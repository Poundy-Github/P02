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
 * @file:      Secoc_StaticServerP03Cfg.c
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

#ifndef SECOC_STATICSERVERB03_CFG_SOURCE
#define SECOC_STATICSERVERB03_CFG_SOURCE

#define SECOC_VEHICLE_TYPE_MASK                   (0xF0)
#define SECOC_VEHICLE_TYPE_FUEL                   (0u)
#define SECOC_VEHICLE_TYPE_DIESEL                 (1u)
#define SECOC_VEHICLE_TYPE_GASOLINE               (2u)
#define SECOC_VEHICLE_TYPE_GASOLINE_CNG           (3u)
#define SECOC_VEHICLE_TYPE_HEV                    (4u)
#define SECOC_VEHICLE_TYPE_PHEV                   (5u)
#define SECOC_VEHICLE_TYPE_EV                     (6u)
#define SECOC_VEHICLE_TYPE_EV_CNG                 (7u)
#define SECOC_VEHICLE_TYPE_CNG                    (8u)
#define SECOC_VEHICLE_TYPE_FCEV                   (9u)
#define SECOC_VEHICLE_TYPE_FCEV_HEV               (10u)
#define SECOC_VEHICLE_TYPE_FCEV_PHEV              (11u)


#define SECOC_VIHICLE_BIT_ALL_MASK      (0xFFFF)

#define SECOC_VIHICLE_BIT_DIESEL        (0x1u)
#define SECOC_VIHICLE_BIT_GASOLINE      (0x2u)
#define SECOC_VIHICLE_BIT_GASOLINE_CNG  (0x4u)
#define SECOC_VIHICLE_BIT_HEV           (0x8u)
#define SECOC_VIHICLE_BIT_PHEV          (0x10u)
#define SECOC_VIHICLE_BIT_EV            (0x20u)
#define SECOC_VIHICLE_BIT_EV_CNG        (0x40u)
#define SECOC_VIHICLE_BIT_CNG           (0x80u)
#define SECOC_VIHICLE_BIT_FCEV          (0x100u)
#define SECOC_VIHICLE_BIT_FCEV_HEV      (0x2000u)
#define SECOC_VIHICLE_BIT_FCEV_PHEV		(0x4000u)

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Rte_SecOc_Server.h"

#include <string.h>
#include "SecOc_Server.h"
#include "Cdd_Hsm.h"
#include "Fvm.h"
#include "FvM_Lcfg.h"
#include "vstdlib.h"
#include "CanIf_Cfg.h"
#include "PduR_SecOC.h"
#include "PduR_Cfg.h"
#include "CanNm.h"
#include "SecOc_Lcfg.h"
#include "ComEx.h"
#include "Cdd_Common.h"
#include "Platform_Types.h"
#include "VConfig_Cfg.h"
#include "Rte_SecOc_Server.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "../Secoc_PrivateServer.h"
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
#define Cx0_OFF 0
#define Cx2_ON 2

#define SECOC_PDU_CNT     ARRAY_SIZE(SecocServerPudTable)
#define SECOCNODE_DTC_NUM ARRAY_SIZE(SecOCNodeDtcStatusTable)
#define VIN_LENGTH      17
#define KEY_DATA_LENGHT 16
#define AuthBuildAttemp 3

#define SECOC_ALL_CONFIG_BIT    (SECOC_VIHICLE_BIT_ALL_MASK)
#define SECOC_PHEV_CONFIG_BIT   (SECOC_VIHICLE_BIT_HEV|SECOC_VIHICLE_BIT_PHEV)
#define SECOC_FUEL_CONFIG_BIT   (SECOC_VIHICLE_BIT_ALL_MASK & (~SECOC_PHEV_CONFIG_BIT))

boolean SECOC_GWFailure_Report(Dem_EventStatusType EventStatus)
{
	return Rte_Call_Monitor_SecOC_GWSecOcFailure_SetEventStatus(EventStatus);
}

boolean SECOC_IDC_L2_IFC_Failure_Report(Dem_EventStatusType EventStatus)
{
    boolean ret = E_NOT_OK;
	if(( E_OK ==  Rte_Call_Monitor_SecOC_SecOcFailure_IFC_SetEventStatus(EventStatus)) 
	 && (E_OK == Rte_Call_Monitor_SecOC_SecOcFailure_IDC_L2_SetEventStatus(EventStatus)))
		{
			ret = E_OK;
		}
	return  ret;
}

boolean SECOC_TBox_Failure_Report(Dem_EventStatusType EventStatus)
{
	return  Rte_Call_Monitor_SecOC_TBoxSecOcFailure_SetEventStatus(EventStatus);
}

boolean SECOC_FVSync_Failure_Report(Dem_EventStatusType EventStatus)
{
	return  Rte_Call_Monitor_SecOC_FV_synchronization_SetEventStatus(EventStatus);
}

boolean SECOC_IDC_L3_Failure_Report(Dem_EventStatusType EventStatus)
{
	return  Rte_Call_Monitor_SecOC_SecOcFailure_IDC_L3_SetEventStatus(EventStatus);
}

boolean SECOC_ESP_Failure_Report(Dem_EventStatusType EventStatus)
{
	return  Rte_Call_Monitor_SecOC_SecOcFailure_ESP_SetEventStatus(EventStatus);
}

boolean SECOC_TCU_Failure_Report(Dem_EventStatusType EventStatus)
{
	return  Rte_Call_Monitor_SecOC_SecOcFailure_TCU_SetEventStatus(EventStatus);
}


Secoc_Server_Pud SecocServerPudTable[] = {
/*			 msgID	RX	NODE		  ComIpduId												   lastState  currentstate rxCount rxCnt  DTCeventState  isSync fv     VconfigNeed   SecocCfgEn                   reportCallout				   nodenamestr	pduReportStatus*/
/*ESP_FD2  */{0x137, 1, ESP,    PduRConf_PduRDestPdu_ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5,        SECOC_DTC_INIT, FALSE, 0	,SECOC_FUEL_CONFIG_BIT,TRUE, SECOC_ESP_Failure_Report,       "ESP",        SECOC_NO_REPORT},
/*R_PBox1  */{0X19C, 1, GW,    PduRConf_PduRDestPdu_R_PBox1_oB30_for_SC_CAN_V3_2_c51a56ba_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*AEB_FD2  */{0X227, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_IDC_L2_IFC_Failure_Report,"IDC_L2_IFC", SECOC_NO_REPORT},
/*DCT_FD4  */{0x236, 1, TCU,    PduRConf_PduRDestPdu_DCT_FD4_oB30_for_SC_CAN_V3_2_c3f55f0e_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5,      SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_TCU_Failure_Report,       "TCU",        SECOC_NO_REPORT},
/*IFC_FD2  */{0x23D, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_IDC_L2_IFC_Failure_Report,"IDC_L2_IFC", SECOC_NO_REPORT},
/*ACC_FD2  */{0X2AB, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_IDC_L2_IFC_Failure_Report,"IDC_L2_IFC", SECOC_NO_REPORT},
/*BCM1     */{0X319, 1, GW,    PduRConf_PduRDestPdu_BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*TPMS1    */{0x341, 1, GW,    PduRConf_PduRDestPdu_TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*BCM3     */{0X345, 1, GW,    PduRConf_PduRDestPdu_BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*ABM1     */{0X351, 1, GW,    PduRConf_PduRDestPdu_ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*TPMS2    */{0x395, 1, GW,    PduRConf_PduRDestPdu_TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*AMP2     */{0X3E3, 1, GW,    PduRConf_PduRDestPdu_AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_GWFailure_Report,         "GW",         SECOC_NO_REPORT},
/*GW_SYNC  */{0x461, 1, GW,    PduRConf_PduRDestPdu_GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx,   SECOC_IDLE, SECOC_IDLE, 9, 9,     SECOC_DTC_INIT, TRUE,  0,   SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_FVSync_Failure_Report,  "GW-SYNC",      SECOC_NO_REPORT},
/*T_Box_FD1*/{0X033, 1, T_BOX, PduRConf_PduRDestPdu_T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE,  SECOC_TBox_Failure_Report,      "T_BOX",      SECOC_NO_REPORT},
/*T_Box_FD3*/{0X3E9, 1, T_BOX, PduRConf_PduRDestPdu_T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, SECOC_IDLE, SECOC_IDLE, 5, 5,         SECOC_DTC_INIT, FALSE, 0	,SECOC_ALL_CONFIG_BIT,TRUE, SECOC_TBox_Failure_Report,      "T_BOX",       SECOC_NO_REPORT}
};

sSecOC_DTC_STATE SecOCNodeDtcStatusTable[] ={
/*   NodeName   NoFail   Debounce    DtcReportStatus*/
    {GW,        TRUE,    FALSE,       SECOC_NO_REPORT},
    {T_BOX,     TRUE,    FALSE,       SECOC_NO_REPORT},
    {HUT,       TRUE,    FALSE,       SECOC_NO_REPORT},
    {IDC_L2_IFC,TRUE,    FALSE,       SECOC_NO_REPORT},
    {IDC_L3,    TRUE,    FALSE,       SECOC_NO_REPORT},
    {TCU,       TRUE,    FALSE,       SECOC_NO_REPORT},
    {ESP,       TRUE,    FALSE,       SECOC_NO_REPORT},
    {AR_HUD,    TRUE,    FALSE,       SECOC_NO_REPORT},

};
uint8 SecOc_Version[3] = {1,0,1};
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length);
INLINE Std_ReturnType READ_SYS_POWER_MOD(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, data, 1);}

extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
INLINE Std_ReturnType SEND_SYC_REQ(void) {
    uint8 data = 0x11;
    return ComEx_SendSignal(COMEX_SIGNAL_TX_SYNCREQUESTMESSAGEID, &data, 1);
}
static inline void SecocConfigSupportCheck(void)
{
    uint8 index = 0;
    uint8 VConfigInfo[400] = {0x00};
    uint8 VehicleTypevconfig = 0;
    Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(VConfigInfo);
    VehicleTypevconfig = VConfigInfo[VCONFIG_KIND_FUEL];
    for(;index < SECOC_PDU_CNT;index++)
    {
        if((SecocServerPudTable[index].VconfigNeed & (1<<VehicleTypevconfig)) > 0)
        {
            SecocServerPudTable[index].SecocCfgEn = TRUE;
        }
        else
        {
            SecocServerPudTable[index].SecocCfgEn = FALSE;
        }
    }
}


// /* define the macro SECOC_CLI_IF if command line interface is enabled , else not */
// #define SECOC_CLI_IF

#ifdef SECOC_CLI_IF

typedef struct 
{
    uint16 msgId;
    uint8 SecocId;

}SecocPduTable_t;

#define SECOC_TXPDU_NUM (3U)
SecocPduTable_t SecocPduLookUpTable[SECOC_TXPDU_NUM] = 
{
    {0x27f,2},/* ip2 639 */
    {0x2c3,1},/* hut_fd1 707 */
    {0x1ee,0} /* hut15 494 */
};

#endif

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


/**********************************************************************************************************************
 *  END OF FILE: Secoc_StaticServerB03_Cfg.c
 *********************************************************************************************************************/
#endif //SECOC_STATICSERVERB03_CFG_SOURCE
