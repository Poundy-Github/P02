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
 * @file:      Secoc_StaticServerB02Cfg.c
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

#define SECOC_PDU_CNT   15
#define VIN_LENGTH      17
#define KEY_DATA_LENGHT 16
#define AuthBuildAttemp 3

Secoc_Server_Pud SecocServerPudTable[SECOC_PDU_CNT] = {
/*GW_SYNC  */{0x461, 1, GW,    PduRConf_PduRDestPdu_GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx,   SECOC_IDLE, SECOC_IDLE, 9, 9, FALSE, TRUE, 0},
/*IFC_FD2  */{0x23D, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*ACC_FD2  */{0X2AB, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*AEB_FD2  */{0X227, 1, IDC_L2_IFC,    PduRConf_PduRDestPdu_AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*BCM1     */{0X319, 1, GW,    PduRConf_PduRDestPdu_BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*BCM3     */{0X345, 1, GW,    PduRConf_PduRDestPdu_BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*AMP2     */{0X3E3, 1, GW,    PduRConf_PduRDestPdu_AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*R_PBox1  */{0X19C, 1, GW,    PduRConf_PduRDestPdu_R_PBox1_oB30_for_SC_CAN_V3_2_c51a56ba_Rx,   SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*ABM1     */{0X351, 1, GW,    PduRConf_PduRDestPdu_ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx,      SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*TPMS1    */{0x341, 1, GW,    PduRConf_PduRDestPdu_TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*TPMS2    */{0x395, 1, GW,    PduRConf_PduRDestPdu_TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*DCT_FD4  */{0x236, 1, TCU,    PduRConf_PduRDestPdu_DCT_FD4_oB30_for_SC_CAN_V3_2_c3f55f0e_Rx,     SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*T_Box_FD1*/{0X033, 1, T_BOX, PduRConf_PduRDestPdu_T_Box_FD1_oB30_for_SC_CAN_V3_2_8c612b61_Rx, SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*T_Box_FD3*/{0X3E9, 1, T_BOX, PduRConf_PduRDestPdu_T_Box_FD3_oB30_for_SC_CAN_V3_2_a231e2e1_Rx, SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0},
/*HUT_FD1  */{0X2C3, 0, HUT,   PduRConf_PduRDestPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx,   SECOC_IDLE, SECOC_IDLE, 5, 5, FALSE, FALSE, 0}
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
