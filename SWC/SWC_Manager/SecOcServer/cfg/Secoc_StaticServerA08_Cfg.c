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
 * @file:      Secoc_StaticServerA08Cfg.c
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

#ifndef SECOC_STATICSERVERA08_CFG_SOURCE
#define SECOC_STATICSERVERA08_CFG_SOURCE

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

#include "Platform_Types.h"
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

#define SECOC_PDU_CNT   19
#define VIN_LENGTH      17
#define KEY_DATA_LENGHT 16
#define AuthBuildAttemp 3

Secoc_Server_Pud SecocServerPudTable[SECOC_PDU_CNT] = {
/*ABM1   */  {0x351, 1, GW,    PduRConf_PduRDestPdu_ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*ACC_FD1   */  {0x143, 1, GW,    PduRConf_PduRDestPdu_ACC_FD1_oB30_for_SC_CAN_V3_2_fd8f81f9_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*ACC_FD2   */  {0x2ab, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*AEB_FD2   */  {0x227, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*BCM1   */  {0x319, 1, GW,    PduRConf_PduRDestPdu_BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*BCM3   */  {0x345, 1, GW,    PduRConf_PduRDestPdu_BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*DCT7   */  {0x235, 1, GW,    PduRConf_PduRDestPdu_DCT7_oB30_for_SC_CAN_V3_2_e75e06c2_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*ESP1   */  {0x149, 1, GW,    PduRConf_PduRDestPdu_ESP1_oB30_for_SC_CAN_V3_2_4f1312e2_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*GW_Sync_Req   */  {0x461, 1, GW,    PduRConf_PduRDestPdu_GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx,  SECOC_IDLE, SECOC_IDLE,9, 9, FALSE, TRUE, 0},
/*IFC_FD1   */  {0x12b, 1, GW,    PduRConf_PduRDestPdu_IFC_FD1_oB30_for_SC_CAN_V3_2_ffed1915_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*IFC_FD2   */  {0x23d, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*R_PBOX1   */  {0x19c, 1, GW,    PduRConf_PduRDestPdu_R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*TPMS1   */  {0x341, 1, GW,    PduRConf_PduRDestPdu_TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*TPMS2   */  {0x395, 1, GW,    PduRConf_PduRDestPdu_TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*T_BOX_FD1   */  {0x33, 1, T_BOX,    PduRConf_PduRDestPdu_T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*T_BOX_FD3   */  {0x3e9, 1, T_BOX,    PduRConf_PduRDestPdu_T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*HUT15   */  {0x1ee, 0, HUT,    PduRConf_PduRDestPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*HUT_FD1   */  {0x2c3, 0, HUT,    PduRConf_PduRDestPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
/*IP2   */  {0x27f, 0, HUT,    PduRConf_PduRDestPdu_IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx,  SECOC_IDLE, SECOC_IDLE,5, 5, FALSE, FALSE, 0},
};

uint8 SecOc_Version[3] = {1,0,1};
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length);
INLINE Std_ReturnType READ_SYS_POWER_MOD(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, data, 1);}

extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
INLINE Std_ReturnType SEND_SYC_REQ(void) {
    uint8 data = 0x11;
    return ComEx_SendSignal(COMEX_SIGNAL_TX_SYNCREQUESTMESSAGEID, &data, 1);
}

/* define the macro SECOC_CLI_IF if command line interface is enabled , else not */
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
 *  END OF FILE: Secoc_StaticServerA08_Cfg.c
 *********************************************************************************************************************/
#endif //SECOC_STATICSERVERA08_CFG_SOURCE
