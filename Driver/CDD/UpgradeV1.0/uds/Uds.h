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
 * @file:      uds.h
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

#ifndef UDS_INCLUDE
#define UDS_INCLUDE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "BehaviorTree.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define UDS_MSG_MAX_SIZE 0x1000
/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    UDS_E_00_POSITIVERESPONSE = 0x00,
    UDS_E_10_GENERALREJECT = 0x10,
    UDS_E_11_SERVICENOTSUPPORTED = 0x11,
    UDS_E_12_SUBFUNCTIONNOTSUPPORTED = 0x12,
    UDS_E_13_INCORRECTMESSAGELENGTHORINVALIDFORMAT = 0x13,
    UDS_E_14_RESPONSETOOLONG = 0x14,
    UDS_E_22_CONDITIONSNOTCORRECT = 0x22,
    UDS_E_24_REQUESTSEQUENCEERROR = 0x24,
    UDS_E_26_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION = 0x26,
    UDS_E_31_REQUESTOUTOFRANGE = 0x31,
    UDS_E_33_SECURITYACCESSDENIED = 0x33,
    UDS_E_35_INVALIDKEY = 0x35,
    UDS_E_36_EXCEEDNUMBEROFATTEMPTS = 0x36,
    UDS_E_37_REQUIREDTIMEDELAYNOTEXPIRED = 0x37,
    UDS_E_70_UPLOADDOWNLOADNOTACCEPTED = 0x70,
    UDS_E_71_TRANSFERDATASUSPENDED = 0x71,
    UDS_E_72_GENERALPROGRAMMINGFAILURE = 0x72,
    UDS_E_73_WRONGBLOCKSEQUENCECOUNTER = 0x73,
    UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING = 0x78,
    UDS_E_7E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION = 0x7E,
    UDS_E_7F_SERVICENOTSUPPORTEDINACTIVESESSION = 0x7F,
} Uds_Err;

typedef enum
{
    SessionDefault = 1,
    SessionProgramming = 2,
    SessionExtendedDiagnostic = 4
} Uds_Session;

typedef struct
{
    uint8 sid;
    uint8 type;
    uint32 len;
    uint8 busy;
    uint8 data[UDS_MSG_MAX_SIZE];
    uint8 nrc;
} UDS_PDU;

typedef struct{
    uint8 sid;
    uint8 subid;
    uint8 err_cnt;
    uint8 list[32];
}UDS_ERR_LIST;

struct UDS_SUBFUNC{
    uint8 subid;
    uint8 session;
    uint8 rxlen;
    uint8 txlen;
    EStatus (*subfunc)(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
};

struct UDS_SERVICE
{
    uint8 sid;
    uint8 session;
    uint32 len;
    EStatus (*service)(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_subfunc);
    uint8 sub_cnt;
    struct UDS_SUBFUNC sub[10];
} ;

typedef struct{
    uint8 sid;
    uint8 subid;
    const struct UDS_SERVICE* service;
    const struct UDS_SUBFUNC* subfunc;
    uint8 txLen;
    uint8 txData[0x40];
    Uds_Session session;
    Uds_Err err;
}UDS_PCB;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  function name(,
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
extern EStatus uds_tick_PerformService(void);

extern void Uds_MainFunction(void);
extern void Uds_PushUdsData(uint8 *data, uint32 length);
extern void Uds_SendUdsData(void);

extern void Uds_FclErrCbk(uint8 err);

/**********************************************************************************************************************
 *  END OF FILE: Uds.h
 *********************************************************************************************************************/
#endif //UDS_INCLUDE
