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
 * @file:      Secoc_StaticServer.h
 * @author:    Nobo
 * @date:      2021-4-8
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-4-8
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef SECOC_STATICSERVER_INCLUDE
#define SECOC_STATICSERVER_INCLUDE

/**********************************************************************************************************************
* External Function Include
*********************************************************************************************************************/

/**********************************************************************************************************************
* Internel Function Include
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SECOC_VERSION_LEN 3
#define KEY_DATA_LENGHT   16
#define VIN_LENGTH        17

typedef enum{
    SECOC_UNINIT,
    SECOC_INIT,
    SECOC_RUN_ONE,
    SECOC_SYNC,
    SECOC_RUN_TWO,
    SECOC_DEV_MODE,
    SECOC_DEINIT
}SECOC_STATE;

typedef enum{
    SECOC_IDLE,
    SECOC_RECV,
    SECOC_VERIFY,
    SECOC_PASS,
    SECOC_FAIL
}SECOC_MSG_STATE;

typedef enum{
    GW = 0,
    T_BOX,
    HUT,
    IDC_L2_IFC,
    IDC_L3,
    TCU,  
    ESP,  
    AR_HUD
}SECOC_NODE;

typedef enum{
    SECOC_DTC_INIT = 0,
    SECOC_DTC_FAIL,
    SECOC_DTC_DEBOUNCE,
    SECOC_DTC_PASS
}DTCEVENT_STS;

typedef enum{
    SECOC_NO_REPORT = 0,
    SECOC_PASS_REPORT,
    SECOC_FAIL_REPORT
}SeocoReport_STS;

typedef Std_ReturnType (*tReportDtcStatusCbk)(Dem_EventStatusType EventStatus);


typedef struct
{
    const uint16 msgId;
    const uint8 is_rx;
    const SECOC_NODE node;
    const PduIdType pduId;
    SECOC_MSG_STATE lastState;
    SECOC_MSG_STATE currentState;
    const uint8 rxMaxCount;
    uint8 rxCnt;
    DTCEVENT_STS dtcEvent;
    boolean isSycnFrame;
    uint32 fv;
#ifdef GWM_V35_PROJECT_TYPE_P03
    const uint16 VconfigNeed;
    boolean SecocCfgEn;
    // Secoc_MsgBuffer buffer;
#endif
    tReportDtcStatusCbk reportDtcStatusCbk;
    const uint8 *nodeNameStr;
	SeocoReport_STS SecocMsgReportStatus;
}Secoc_Server_Pud;

typedef struct
{
	const SECOC_NODE SecocMsgNode;
	boolean SecocPduNoFailFlag;/*Pdu status is pass or init*/
	boolean SeoocPduDebounceFlag;
	SeocoReport_STS SecocReportStatus;

}sSecOC_DTC_STATE;


/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GetSecocPduTableHanlde(index)               SecocServerPudTable[index]
#define GetSecocPduCurrentState(index)              SecocServerPudTable[index].currentState
#define SetSecocPduCurrentState(index,status)       SecocServerPudTable[index].currentState = status
#define GetSecocPduRxCnt(index)                     SecocServerPudTable[index].rxCnt
#define SetSecocPduRxCnt(index,value)               SecocServerPudTable[index].rxCnt = value
#define GetSecocPduRxMaxCount(index)                SecocServerPudTable[index].rxMaxCount
#define GetSecocPduDtcEventState(index)             SecocServerPudTable[index].dtcEvent
#define SetSecocPduDtcEventState(index,status)      SecocServerPudTable[index].dtcEvent = status
#define SetSecocPduDtcReport(index,value)           SecocServerPudTable[index].reportDtcStatusCbk(value)
#define GetSecocPduDtcReportStatus(index)           SecocServerPudTable[index].SecocMsgReportStatus
#define SetSecocPduDtcReportStatus(index,status)    SecocServerPudTable[index].SecocMsgReportStatus = status
#define SecocPduIsSync(index)                       SecocServerPudTable[index].isSycnFrame != FALSE
#define SecocPduIsRxPdu(index)                      SecocServerPudTable[index].is_rx != FALSE
#define GetSecocPduNodeNameStr(index)               SecocServerPudTable[index].nodeNameStr
#define GetSecocPduMsgID(index)                     SecocServerPudTable[index].msgId

/*SECOC Node DTC STATUS */
#define GetSecocNodeDtcNoFailFlag(index)                SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SecocPduNoFailFlag
#define SetSecocNodeDtcNoFailFlag(index,value)          SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SecocPduNoFailFlag = value
#define GetSecocNodeDtcReportStatus(index)              SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SecocReportStatus
#define SetSecocNodeDtcReportStatus(index,status)       SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SecocReportStatus = status
#define GetSecocNodeDebounceStatus(index)               SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SeoocPduDebounceFlag
#define SetSecocNodeDebounceStatus(index,status)        SecOCNodeDtcStatusTable[GetSecocPduTableHanlde(index).node].SeoocPduDebounceFlag = status


/*********************************************************************************************************************
 * Development Error Detection
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint8 SecOc_Version[3];
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

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
void Secoc_ServerInit(void);
Std_ReturnType Secoc_KEYM_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
void Secoc_StaticServerMainFunction(void);
void Secoc_NvmTripCounterWriteNotification(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);
/**********************************************************************************************************************
 *  END OF FILE: Secoc_StaticServer.h
 *********************************************************************************************************************/
#endif //SECOC_STATICSERVER_INCLUDE
