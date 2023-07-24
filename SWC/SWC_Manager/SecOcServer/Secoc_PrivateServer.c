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
 * @file:      Secoc_StaticServer.c
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

#include "Rte_SecOc_Server.h"

#include <string.h>
#include <stdio.h>
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
#include "Dem.h"
#include "Platform_Types.h"
#include "NvM.h"

#include "Secoc_PrivateServer.h"
#include "Com.h"
#include "logger.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
#include "cfg/Secoc_StaticServerB02_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

#elif defined GWM_V35_PROJECT_TYPE_B03
#include "cfg/Secoc_StaticServerB03_Cfg.c"
extern FUNC(void, Can_Server_CODE) CanServer_CanIfRxPDUTimeoutMonitor(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    CanServer_CanIfRxPDUTimeoutMonitor(CanIfRxPduId, CanDlc)

#elif defined GWM_V35_PROJECT_TYPE_P03
#define COMPDUGRPCTRLCOMMON
#define COMPDUGRPCTRLHEV
#include "cfg/Secoc_StaticServerP03_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_P02
#define COMPDUGRPCTRLCOMMON
#define COMPDUGRPCTRLHEV
#include "cfg/Secoc_StaticServerP02_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_P09
#define COMPDUGRPCTRLCOMMON
#define COMPDUGRPCTRLHEV
#include "cfg/Secoc_StaticServerP09_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_P05
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerP05_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_A07
#define COMPDUGRPCTRLCOMMON
#define COMPDUGRPCTRLHEV
#include "cfg/Secoc_StaticServerA07_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_A08
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerA08_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_B16
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerB16_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)
		
extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_ES13
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerES13_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_EC24
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerEC24_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif defined GWM_V35_PROJECT_TYPE_ES24
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerES24_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif(defined GWM_V35_PROJECT_TYPE_D01)
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerD01_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif(defined GWM_V35_PROJECT_TYPE_D02)
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerD02_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif(defined GWM_V35_PROJECT_TYPE_D03)
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerD03_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#elif(defined GWM_V35_PROJECT_TYPE_P01)
#define COMPDUGRPCTRLCOMMON
#include "cfg/Secoc_StaticServerP01_Cfg.c"
extern FUNC(void, Can_Server_CODE) MD_PduCallback(PduIdType CanIfRxPduId, uint8 CanDlc);
#define CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc)    MD_PduCallback(CanIfRxPduId, CanDlc)

extern boolean CanServer_RxPDUTimeoutMonitor(uint16 PduId);

#else
#endif

#ifdef Rte_Read_piDiagMonitorReInitFlag_ChangeCounter
#define SECOC_GET_DTC_ChangeCounter(data)  Rte_Read_piDiagMonitorReInitFlag_ChangeCounter(data)
#else
#define SECOC_GET_DTC_ChangeCounter(data)   0
#endif

static void Secoc_CleanSecocTableDtcState(void);

static SECOC_STATE current_state = SECOC_UNINIT;
static SECOC_STATE last_state = SECOC_UNINIT;
static uint8 Vin_Data_Did[17] = {0};
static uint8 key_data[16] = {0};
uint8 SecOC_Default_Code = 0;
static uint8 secoc_req_sync_cnt = 3;
static uint32 Secoc150msCnt = 1;
static uint32 Secoc30sCnt = 1;
static boolean secoc_150ms_timeout = FALSE;
static boolean secoc_30s_timeout = FALSE;
static boolean secoc_recv_spdu = FALSE;
static boolean secoc_recv_sync = FALSE;
// static boolean secoc_busoff_recover = FALSE;
static boolean secoc_key_checked = FALSE;
// static boolean secoc_pdu_checked = FALSE;
static boolean secoc_running_err_checked = FALSE;
static boolean secoc_sync_nvm_erasure_checked = FALSE;
static uint32 OldChangeCounter = 0;
static uint32 ChangeCounter = 0;
static boolean KeyStorageOk = FALSE;
static uint8  gu8key_auth[16]={0};

#define SECOC_SET_STATE(s)  do{ \
    SECOC_STATE temp = s;\
    last_state = current_state;                            \
    current_state  = temp ;                           \
}while(0)

extern FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus);
#define SECOC_RUNNING_DTC(state)    Dem_SetEventStatus(DemConf_DemEventParameter_SecOC_software_module_running_error_Unexpected_Operation,state)
#define SECOC_SYNC_NVM_ERASURE_DTC(state)    Dem_SetEventStatus(\
    DemConf_DemEventParameter_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure,state)

static inline void Secoc_PrintVinAndKey(uint8* Vin)
{
    const uint8 key_const[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    uint8 i = 0;
    uint32 keylen = 16;
    (void)crypto_warn("Secoc Vin_Data_Did = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\r\n",
    Vin[0],Vin[1],Vin[2],Vin[3],Vin[4],Vin[5],Vin[6],Vin[7],Vin[8],
    Vin[9],Vin[10],Vin[11],Vin[12],Vin[13],Vin[14],Vin[15],Vin[16]);
    (void)Csm_KeyElementGet(0, 1, gu8key_auth, &keylen);
    for(;i<keylen;i++)
    {
        gu8key_auth[i] = gu8key_auth[i]^key_const[i];
    }
    (void)crypto_warn("Secoc data = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\r\n",
    gu8key_auth[0],gu8key_auth[1],gu8key_auth[2],gu8key_auth[3],gu8key_auth[4],gu8key_auth[5],gu8key_auth[6],gu8key_auth[7],gu8key_auth[8],
    gu8key_auth[9],gu8key_auth[10],gu8key_auth[11],gu8key_auth[12],gu8key_auth[13],gu8key_auth[14],gu8key_auth[15]);
}
static Secoc_Server_Pud *Secoc_switchPud(uint16 msgID)
{
    uint8 index = 0;
    for (index = 0; index < SECOC_PDU_CNT; index++)
    {
        if (SecocServerPudTable[index].msgId == msgID)
        {
            return &SecocServerPudTable[index];
        }
    }
    return NULL_PTR;
}

static uint8 Secoc_CanIfRxIndication(uint16 CanId, const uint8 *CanSduPtr, uint8 CanDlc)
{
    uint8 rec = E_NOT_OK;
    uint8 dataIndex = 0;
    Secoc_Server_Pud *secoc_pdu = Secoc_switchPud(CanId);
    PduInfoType PduData;
    PduData.SduDataPtr = (uint8 *) CanSduPtr;
    PduData.SduLength = CanDlc - 8;

    if (secoc_pdu != NULL_PTR)
    {
        /* dev mode ,trans 2 upper layer,deleted ! */
        if (SecOC_IsDevModeEnabled())
        {
            // PduR_SecOCRxIndication(secoc_pdu->pduId, &PduData);
            // rec = E_NOT_OK;
            rec = E_OK;
        }
        else
        {
            if (secoc_pdu->isSycnFrame == FALSE)
            {
                #ifdef GWM_V35_PROJECT_TYPE_P03
                if(secoc_pdu->SecocCfgEn == FALSE)
                {
                    rec = E_NOT_OK;
                }
                else
                #endif
                {
                    for (dataIndex = (uint8)(CanDlc - 8); dataIndex < CanDlc; dataIndex++)
                    {
                        if (CanSduPtr[dataIndex] != SecOC_Default_Code)
                        {
                            rec = E_OK;
                            break;
                        }
                    }
                }
            }
            else
            {
                rec = E_OK;
            }

            if (rec == E_OK)
            {
                //secoc_pdu->currentState = SECOC_VERIFY;
                if (secoc_pdu->rxCnt)
                {
                    secoc_pdu->rxCnt--;
                    // secoc_recv_spdu = TRUE;
                }
            }
            else
            {
                /* defaut code , trans 2 upper layer */
                PduR_SecOCRxIndication(secoc_pdu->pduId, &PduData);
                rec = E_NOT_OK;
            }
        }
    }
    else
    {
        rec = E_OK;
    }

    return rec;
}

static void Secoc_Busoff_Ctrl(void)
{
    if (CanServer_SecOCBusOffEndStatusGet() == TRUE)
    {
        // secoc_busoff_recover = TRUE;
        secoc_recv_sync = FALSE;
        secoc_req_sync_cnt = 3;
        CanServer_SecOCBusOffEndStatusSet(FALSE);
    }
}

static void Secoc_InitTask(void)
{
    uint8 SecOcCurrentComMode = COMM_NO_COMMUNICATION;

    (void)ComM_GetCurrentComMode(0, &SecOcCurrentComMode);
    if (SecOcCurrentComMode == COMM_FULL_COMMUNICATION)
    {
        // printf("init to run one \r\n");
        SECOC_SET_STATE(SECOC_RUN_ONE);
        secoc_req_sync_cnt = 3;
        Secoc150msCnt = 1;
        Secoc30sCnt = 1;
        secoc_150ms_timeout = FALSE;
        secoc_30s_timeout = FALSE;
        secoc_recv_spdu = FALSE;
        secoc_recv_sync = FALSE;
        // secoc_busoff_recover = FALSE;
        Secoc_CleanSecocTableDtcState();
    }
}

static void Secoc_TimerCtrl(void)
{
    uint32 run150MsTime = 0;
    uint32 run30STime = 0;
    uint8 SecOcCurrentComMode = COMM_NO_COMMUNICATION;
    uint8 powerMode = Cx0_OFF;

    (void)ComM_GetCurrentComMode(0, &SecOcCurrentComMode);
    (void)READ_SYS_POWER_MOD(&powerMode);

    (void)ComM_GetCurrentComMode(0, &SecOcCurrentComMode);
    if(SecOcCurrentComMode == COMM_FULL_COMMUNICATION)
    {
        run150MsTime = 50 * (++Secoc150msCnt);
    }
    else
    {
        Secoc150msCnt = 1;
    }

    if (powerMode == Cx2_ON)
    {
        run30STime = 50 * (++Secoc30sCnt);
    }
    else
    {
        Secoc30sCnt = 1;
    }

    if ((run150MsTime >= 150) && (secoc_150ms_timeout == FALSE))
    {
        secoc_150ms_timeout = TRUE;
    }
    if ((run30STime >= 3000) && (secoc_30s_timeout == FALSE))
    {
        secoc_30s_timeout = TRUE;
    }
}

static void Secoc_CleanSecocTableDtcState(void)
{
    uint8 index = 0;
    for (index = 0; index < SECOC_PDU_CNT; index++)
    {
        SecocServerPudTable[index].dtcEvent = SECOC_DTC_INIT;
        SecocServerPudTable[index].rxCnt = SecocServerPudTable[index].rxMaxCount;
        SecocServerPudTable[index].currentState = SECOC_IDLE;
        SecocServerPudTable[index].SecocMsgReportStatus = SECOC_NO_REPORT;
    }
    for(index=0;index<SECOCNODE_DTC_NUM;index++)
    {
        SecOCNodeDtcStatusTable[index].SecocPduNoFailFlag = TRUE;
        SecOCNodeDtcStatusTable[index].SecocReportStatus = SECOC_NO_REPORT;
        SecOCNodeDtcStatusTable[index].SeoocPduDebounceFlag = FALSE;
    }

}

static void Secoc_SetSecocDtc(void)
{
    uint8 index = 0;
	for (index = 0; index < SECOC_PDU_CNT; index++)
	{
	  if(SecocPduIsRxPdu(index))
	  {
		if(SecocPduIsSync(index))/* sync msg dtc */
		{
		   if(GetSecocPduDtcEventState(index) == SECOC_DTC_PASS)
			{
			   if(GetSecocPduDtcReportStatus(index) != SECOC_PASS_REPORT)
				{
				  if(E_OK == SetSecocPduDtcReport(index,DEM_EVENT_STATUS_PASSED))
				   {
				   (void)crypto_warn("SECOC GW-Sync SecOcFailure DTC Event Report PASS! \r\n");
					SetSecocPduDtcReportStatus(index,SECOC_PASS_REPORT) ;
				   }
				}
			}
		   else if(GetSecocPduDtcEventState(index) == SECOC_DTC_FAIL)
			{
			   if(GetSecocPduDtcReportStatus(index) != SECOC_FAIL_REPORT)
				{
				  if(E_OK == SetSecocPduDtcReport(index,DEM_EVENT_STATUS_FAILED))
				   {
				   (void)crypto_warn("SECOC GW-Sync FV-Sync DTC Event Report FALIED, trip = 0x%x  reset = 0x%x\r\n", FvM_GetLatestTripCounter(),FvM_GetLatestResetCounter());
				   SetSecocPduDtcReportStatus(index,SECOC_FAIL_REPORT) ;
				   }
				}
			}
		   else if(GetSecocPduDtcEventState(index) == SECOC_DTC_INIT)
			{
			  /*do nothing*/	
			}
		 }
		else
		 { 
		   if(secoc_30s_timeout)
			{
			/* Report Secoc Pdu DTC Fail , except gw_sync pdu*/
			  if(GetSecocPduDtcEventState(index) == SECOC_DTC_FAIL)
				{
				   SetSecocNodeDtcNoFailFlag(index, FALSE); 		   
				   if(GetSecocPduDtcReportStatus(index) != SECOC_FAIL_REPORT)
					 {						  
						 if(E_OK == SetSecocPduDtcReport(index,DEM_EVENT_STATUS_FAILED))
						   {
							 (void)crypto_warn("SECOC %s DTC Event report FAILED,ID =%2x !\r\n", GetSecocPduNodeNameStr(index),GetSecocPduMsgID(index));
						   }
						 SetSecocNodeDtcReportStatus(index,SECOC_FAIL_REPORT);
						 SetSecocPduDtcReportStatus(index,SECOC_FAIL_REPORT); 
					 }
				}
			  else if(GetSecocPduDtcEventState(index) == SECOC_DTC_DEBOUNCE)
				{
				   SetSecocNodeDebounceStatus(index, TRUE);
				}
			  else
				{
				/* Do nothing*/
				}
			}
		 }
	   }
	 }
	if(secoc_30s_timeout)
	{
	/* Report Secoc Pdu DTC Pass,except gw_sync pdu*/
	   for(index = 0; index < SECOC_PDU_CNT; index++)
		{
		 if((!SecocPduIsSync(index))&&(SecocPduIsRxPdu(index)))
			{
			 if((GetSecocNodeDtcNoFailFlag(index)  == TRUE)
			   &&(GetSecocPduDtcEventState(index)  == SECOC_DTC_PASS)
			   &&(GetSecocNodeDebounceStatus(index)== FALSE))
			   {
				 SetSecocPduDtcReportStatus(index,SECOC_PASS_REPORT); 
				 if(GetSecocNodeDtcReportStatus(index)!= SECOC_PASS_REPORT)
				   {
					 SetSecocNodeDtcReportStatus(index,SECOC_PASS_REPORT) ;
					if(E_OK == SetSecocPduDtcReport(index,DEM_EVENT_STATUS_PASSED))
						{
						 (void)crypto_warn("SECOC %s DTC Event report PASS !\r\n", GetSecocPduNodeNameStr(index));
						}
				   }
			   }
			 else
			   {
				  /*do nothing*/
			   }
				 }
		}
	}
	for(index=0; index < SECOCNODE_DTC_NUM ; index++)
	 {
	  SecOCNodeDtcStatusTable[index].SecocPduNoFailFlag   = TRUE;
	  SecOCNodeDtcStatusTable[index].SeoocPduDebounceFlag = FALSE;
	 }

    if(secoc_30s_timeout)
    {
        if (secoc_key_checked == FALSE)
        {
            if(Rte_Call_Monitor_SecOC_key_storage_SetEventStatus(DEM_EVENT_STATUS_PASSED)==E_OK)
            {
                (void)crypto_warn("Secoc key storage DTC Event clean ok ,ign on \r\n");
                secoc_key_checked = TRUE;
            }
        }

        if (secoc_running_err_checked == FALSE)
        {
            if(SECOC_RUNNING_DTC(DEM_EVENT_STATUS_PASSED)==E_OK)
            {
                (void)crypto_warn("Secoc running DTC Event clean ok \r\n");
                secoc_running_err_checked = TRUE;
            }
        }
        if (secoc_sync_nvm_erasure_checked == FALSE)
        {
            if(SECOC_SYNC_NVM_ERASURE_DTC(DEM_EVENT_STATUS_PASSED)==E_OK)
            {
                (void)crypto_warn("Secoc sync nvm erasure DTC Event clean ok \r\n");
                secoc_sync_nvm_erasure_checked = TRUE; 
            }
        }
    }
}

static void Secoc_DTC_Task(void)
{
    uint8 index = 0;
    uint8 powerMode = Cx0_OFF;
    (void)READ_SYS_POWER_MOD(&powerMode);
	if(SecOC_IsDevModeEnabled())
		{
			/*nothing to do*/
		}
	else
		{
         if(powerMode == Cx2_ON)
            {
             (void)SECOC_GET_DTC_ChangeCounter(&ChangeCounter);
             if(ChangeCounter>OldChangeCounter)
                {
                 OldChangeCounter = ChangeCounter;
                 secoc_30s_timeout = FALSE;
                 secoc_running_err_checked = FALSE;
                 secoc_sync_nvm_erasure_checked = FALSE;
                 secoc_key_checked = FALSE;
                 Secoc_CleanSecocTableDtcState();
                }
			 
              for (index = 0; index < SECOC_PDU_CNT; index++)
              {
                if(GetSecocPduCurrentState(index) == SECOC_PASS)
                 {
                    SetSecocPduDtcEventState(index,SECOC_DTC_PASS);
                 }
                else if(GetSecocPduCurrentState(index) == SECOC_FAIL)
                 {
                   if(GetSecocPduRxCnt(index) == 0u)
                     {
                       SetSecocPduDtcEventState(index,SECOC_DTC_FAIL);
                     }
      			   else
      			     {
                       SetSecocPduDtcEventState(index, SECOC_DTC_DEBOUNCE);
      			     }
                 }
                else if(GetSecocPduCurrentState(index) == SECOC_IDLE)
                 {
                   SetSecocPduDtcEventState(index,SECOC_DTC_INIT) ;/* The pdu was not received and verified,or the pdu was  received and  need verified*/
                 }
                else
                 {
                  /*Nothing to do*/
                 }
              }
              Secoc_SetSecocDtc();
		    }
        }
}

static void Secoc_RunOneTask(void)
{
    uint8 powerMode = Cx0_OFF;
    (void)READ_SYS_POWER_MOD(&powerMode);
    Secoc_TimerCtrl();

    if (powerMode == Cx2_ON)
    {
        (void)crypto_info("Secoc run one to run two \r\n");
        SECOC_SET_STATE(SECOC_RUN_TWO);
    }

    // if ((secoc_150ms_timeout || secoc_recv_spdu || secoc_busoff_recover) && !secoc_recv_sync && secoc_req_sync_cnt)
    // {
    //     secoc_busoff_recover = FALSE;
    //     SECOC_SET_STATE(SECOC_SYNC);
    // }

    if (!secoc_recv_sync )
    {
        if(secoc_recv_spdu || secoc_150ms_timeout || (secoc_req_sync_cnt>0))
        {
            SECOC_SET_STATE(SECOC_SYNC);
        }
    }
}


static void Secoc_RunTwoTask(void)
{
    uint8 powerMode = Cx0_OFF;
    (void)READ_SYS_POWER_MOD(&powerMode);
    Secoc_TimerCtrl();

    if (powerMode == Cx2_ON)
    {
        if (!secoc_recv_sync)
        {
            if((secoc_recv_spdu || secoc_150ms_timeout) && (secoc_req_sync_cnt>0))
            {
                SECOC_SET_STATE(SECOC_SYNC);
            }
        }
        // Secoc_DTC_Task();

    }
    else
    {
        SECOC_SET_STATE(SECOC_RUN_ONE);
    }
}

static void Secoc_DeInitTask(void)
{
    FvM_SetLatestResetCounter(0);
    VStdMemClr(FvM_GetAddrFreshnessValueArray(0), FvM_GetSizeOfFreshnessValueArray());
    SECOC_SET_STATE(SECOC_UNINIT);
}

static void Secoc_SyncTask(void)
{
    Secoc_TimerCtrl();
    if (!secoc_recv_sync && (secoc_req_sync_cnt>0))
    {
        if (E_OK == SEND_SYC_REQ())
        {
            // crypto_info("Secoc Secoc_SyncTask\r\n");
            secoc_req_sync_cnt--;
        }
    }
    else
    {
        secoc_recv_spdu = FALSE;
        SECOC_SET_STATE(last_state);
    }
}

static void Secoc_DevModeCheck(void)
{
    if ((current_state != SECOC_DEV_MODE) && (SecOC_IsDevModeEnabled()))
    {
        (void)crypto_info("Secoc %d 2 dev mode\r\n", current_state);
        SECOC_SET_STATE(SECOC_DEV_MODE);
        secoc_recv_sync = FALSE;
        secoc_req_sync_cnt = 3;
    }
}

static void Secoc_DevModeTask(void)
{
    if (!SecOC_IsDevModeEnabled())
    {
        (void)crypto_info("Secoc dev mode 2 run one \r\n");
        SECOC_SET_STATE(SECOC_RUN_ONE);
    }
}

void Secoc_ServerInit(void)
{
    #ifdef GWM_V35_PROJECT_TYPE_P03
    SecocConfigSupportCheck();
    #endif
    (void)Rte_Read_tiSR_VIN_Element(Vin_Data_Did);
    
    Secoc_PrintVinAndKey(Vin_Data_Did);

    SecOC_Default_Code = Vin_Data_Did[17 - 1] ^ Vin_Data_Did[16 - 1] ^ Vin_Data_Did[15 - 1];
    (void)crypto_warn("Secoc trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
    if (SecOC_IsDevModeEnabled())
    {
        (void)crypto_warn("Secoc init DevMode On,Secoc disabled!\r\n");
        SECOC_SET_STATE(SECOC_DEV_MODE);
    }
    else
    {
        (void)crypto_warn("Secoc init DevMode Off,Secoc enabled!\r\n");
        SECOC_SET_STATE(SECOC_INIT);
    }
}

void Secoc_StaticServerMainFunction(void)
{
    Secoc_DevModeCheck();
    Secoc_Busoff_Ctrl();
    Secoc_DTC_Task();
    switch (current_state)
    {
        case SECOC_UNINIT:
            break;
        case SECOC_INIT:
            Secoc_InitTask();
            break;
        case SECOC_RUN_ONE:
            Secoc_RunOneTask();
            break;
        case SECOC_SYNC:
            Secoc_SyncTask();
            break;
        case SECOC_RUN_TWO:
            Secoc_RunTwoTask();
            break;
        case SECOC_DEV_MODE:
            Secoc_DevModeTask();
            break;
        case SECOC_DEINIT:
            Secoc_DeInitTask();
            break;
        default:
            break;
    }
}

#define DCM_E_OK ((Std_ReturnType)E_OK)         /*!< Successful operation */
#define DCM_E_NOT_OK ((Std_ReturnType)E_NOT_OK) /*!< Failed operation with no specific reason (except when NRC is returned in addition) */
#define DCM_E_PENDING ((Std_ReturnType)10)      /*!< Invoked callout (operation) needs to be called again */
#define DCM_E_FORCE_RCRRP ((Std_ReturnType)12)  /*!< Invoked callout (operation) requests an immediate RCR-RP response transmission and needs to be called again once it is (successfully or not) sent */

#define DCM_INITIAL             (0U)
#define DCM_PENDING             (1U)
#define DCM_CANCEL              (2U)
#define DCM_FORCE_RCRRP_OK      (3U)
#define DCM_FORCE_RCRRP_NOT_OK  (64U)

#define SECOC_WRITE_KEY_IDLE                (0u)
#define SECOC_WRITE_KEY_WAIT_KEY_FINISH     (1u)
#define SECOC_WRITE_KEY_WAIT_TC_START       (2u)
#define SECOC_WRITE_KEY_WAIT_TC_FINISH      (3u)
static uint8 SecOc_WriteKeyStep = SECOC_WRITE_KEY_IDLE;
Std_ReturnType Secoc_KEYM_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
    uint8 ret = DCM_E_PENDING;
    uint8 i = 0;
    // uint8 key_data_default_flag = TRUE;
    // uint8 Key_Status = KEY_OK;
    boolean key_data_is_fail = TRUE;
    NvM_RequestResultType nvmStatus = NVM_REQ_OK;

    switch (OpStatus)
    {
        case DCM_INITIAL:
            SecOc_WriteKeyStep = SECOC_WRITE_KEY_IDLE;
            (void)Rte_Read_tiSR_VIN_Element(Vin_Data_Did);
            (void)memcpy(key_data, Data, KEY_DATA_LENGHT);
            for (i = 0; i < KEY_DATA_LENGHT; i++)
            {
                if (key_data[i] != key_data[0])
                {
                    key_data_is_fail = FALSE;
                    break;
                }
            }
            if (!key_data_is_fail)
            {
                Rte_Call_HsmKeyM_SetCmacKey(Vin_Data_Did, VIN_LENGTH, key_data, KEY_DATA_LENGHT);
                Secoc_PrintVinAndKey(Vin_Data_Did);
                (void)crypto_err("SecOc key key write start trip = 0x%x,reset = 0x%x",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
                SecOc_WriteKeyStep = SECOC_WRITE_KEY_WAIT_KEY_FINISH;
                
                KeyStorageOk = FALSE;
                ret = DCM_E_PENDING;
            }
            else
            {
                *ErrorCode = 0x31;
                ret = RTE_E_INVALID;
            }
            break;
        case DCM_PENDING:
        case DCM_FORCE_RCRRP_OK:
            if(SECOC_WRITE_KEY_WAIT_KEY_FINISH == SecOc_WriteKeyStep)
            {
            if (Cdd_HsmSetValidIsBusy() == FALSE)
            {
                if(KeyStorageOk == FALSE)
                {
                    if(Rte_Call_Monitor_SecOC_key_storage_SetEventStatus(DEM_EVENT_STATUS_FAILED)==E_OK)
                    {
                        (void)crypto_warn("Secoc key storage DTC Event write ok , key write  \r\n");
                    }
                    ret = DCM_E_NOT_OK;
                }
                else
                {
                    if(Rte_Call_Monitor_SecOC_key_storage_SetEventStatus(DEM_EVENT_STATUS_PASSED)==E_OK)
                    {
                        (void)crypto_warn("Secoc key storage DTC Event Clean ok , key write  \r\n");
                        secoc_key_checked = TRUE;
                    }
                        SecOc_WriteKeyStep = SECOC_WRITE_KEY_WAIT_TC_START;
                    }
                }
            }

            if(SECOC_WRITE_KEY_WAIT_TC_START == SecOc_WriteKeyStep)
            {
                (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount, &nvmStatus);
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    FvM_ResetTripAndResetCounter();
                    SecOc_WriteKeyStep = SECOC_WRITE_KEY_WAIT_TC_FINISH;
                    (void)crypto_err("Secoc trip counter write start");
                }
            }
            if(SECOC_WRITE_KEY_WAIT_TC_FINISH == SecOc_WriteKeyStep)
            {
                (void)NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount, &nvmStatus);
                if(NVM_REQ_PENDING != nvmStatus)
                {
                    if(NVM_REQ_OK == nvmStatus)
                    {
                        SecOc_WriteKeyStep = SECOC_WRITE_KEY_IDLE;
                        Secoc_PrintVinAndKey(Vin_Data_Did);
                        (void)crypto_warn("Secoc trip counter write OK trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
                        ret = E_OK;
                    }
            else
            {
                        SecOc_WriteKeyStep = SECOC_WRITE_KEY_IDLE;
                        (void)crypto_err("Secoc trip trip counter write fail");
                        *ErrorCode = 0x72;//DCM_E_GENERALPROGRAMMINGFAILURE
                        ret = E_NOT_OK;
                    }
                }
            }
            break;
        default:
            break;
    }
    return (ret);
}

/*********************** callback function **********************/
void CANNM_State_Change_Callback(uint8 nmNetworkHandle, uint8 PreState, uint8 CurState)
{
    (void)nmNetworkHandle;
    if (CurState == NM_STATE_BUS_SLEEP)
    {
        if (PreState == NM_STATE_PREPARE_BUS_SLEEP)
        {
            SECOC_SET_STATE(SECOC_DEINIT);
        }
    }

    if (PreState == NM_STATE_BUS_SLEEP)
    {
        if (CurState == NM_STATE_REPEAT_MESSAGE)
        {
            SECOC_SET_STATE(SECOC_INIT);
        }
    }

    /* Can not receive data when in NM_STATE_PREPARE_BUS_SLEEP and NM_STATE_BUS_SLEEP */
    if ((CurState == NM_STATE_BUS_SLEEP) || (CurState == NM_STATE_PREPARE_BUS_SLEEP))
    {
        if ((PreState != NM_STATE_BUS_SLEEP) && (PreState != NM_STATE_PREPARE_BUS_SLEEP))
        {
            Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35);
            
            #ifdef COMPDUGRPCTRLCOMMON
                /* Add for first frame is not NM frame */
                Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3);
                #ifdef COMPDUGRPCTRLHEV
                Com_IpduGroupStop(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV);
                #endif
            #endif
        }
    }
        /* Receive data when not in NM_STATE_PREPARE_BUS_SLEEP and NM_STATE_BUS_SLEEP */
    else
    {
        if (PreState == NM_STATE_BUS_SLEEP)
        {
            Com_IpduGroupStart(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35, TRUE);
        }
        else if (PreState == NM_STATE_PREPARE_BUS_SLEEP)
        {
            Com_IpduGroupStart(ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35, FALSE);
        }
        else
        {
            /* No action */
        }
    }
}

FUNC(void, COM_APPL_CODE) SECOC_PDU_Message_ReqSet(boolean flag)
{
    (void)flag;
}

FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOcSync_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR)job, Csm_JobCalloutStateType state)
{
    (void)job;
    (void)state;
    return E_OK;
}

FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOcSync_Callout_Post(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR)job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR)jobReturnValue)
{
    uint8 mac[11]={0};
    uint8 index = 0;
    uint8 cmacLen = (uint8)(job->jobPrimitiveInputOutput.secondaryInputLength/8u);
    boolean isDefaultMac = TRUE;
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr = job->jobPrimitiveInputOutput.verifyPtr;
    (void)jobReturnValue;
	(void)state;
	(void)memcpy(mac, job->jobPrimitiveInputOutput.secondaryInputPtr, cmacLen);
    for (index = 0; index < cmacLen; index++)
    {
        if (mac[index] != SecOC_Default_Code)
        {
            isDefaultMac = FALSE;
            break;
        }
    }

    if(isDefaultMac == TRUE)
    {
        *verifyPtr = 0;
    }
    return E_OK;
}

FUNC(boolean, COM_APPL_CODE) SecOc_GW_Sync_Req_Callout(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA)PduInfoPtr)
{
    boolean ret = TRUE;
	(void)PduId;
	(void)PduInfoPtr;
    return ret;
}

FUNC(void, SECOC_APPL_CODE) SecOc_Verification_Status_Callout_With_Secured_Pdu(SecOC_VerificationStatusType verificationStatus, const PduInfoType *receivedSecuredPDU, uint8 *fullfreshnessValue, uint32 fullfreshnessValueLength)
{
    Secoc_Server_Pud *secoc_pdu = NULL_PTR;
    SecOC_VerificationStatusType *SecOc_Verification_Status;
    uint16 canId = 0;
	(void)receivedSecuredPDU;
	(void)fullfreshnessValue;
    (void)fullfreshnessValueLength;
    SecOc_Verification_Status = &verificationStatus;
    canId = SecOc_Verification_Status->secOCDataId;
    secoc_pdu = Secoc_switchPud(canId);
    if (SecOc_Verification_Status->verificationStatus == E_OK)
    {
        if (secoc_pdu->lastState == SECOC_FAIL)
        {
            (void)crypto_warn("Secoc verify Recover, ID[%2x], error count [%d], SecOc trip = 0x%x,reset = 0x%x", canId, secoc_pdu->rxMaxCount - secoc_pdu->rxCnt-(secoc_pdu->dtcEvent==SECOC_DTC_FAIL?0:1),FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }

        secoc_pdu->lastState = SECOC_PASS;
        secoc_pdu->currentState = SECOC_PASS;
        secoc_pdu->rxCnt = secoc_pdu->rxMaxCount;
        if(secoc_pdu->isSycnFrame)
        {
             secoc_recv_sync = TRUE;
        }
    }
    else
    {
        if (secoc_pdu->lastState == SECOC_PASS)
        {
            (void)crypto_err("Secoc verify Error , ID[%2x], trip = 0x%x,reset = 0x%x", canId,FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }

        secoc_pdu->lastState = SECOC_FAIL;
        secoc_pdu->currentState = SECOC_FAIL;
    }
    if(secoc_pdu->isSycnFrame == FALSE)
    {
        secoc_recv_spdu = TRUE;
        secoc_req_sync_cnt = 3;
    }

    Secoc_DTC_Task();

}

CanFrameCounterType ABS3_counter = {0};
CanFrameCounterType ESP_FD2_counter = {0};
CanFrameCounterType ECM2_counter = {0};

Std_ReturnType CanIf_RxIndicationSubDataChecksumRxVerify(PduIdType CanIfRxPduId, Can_IdType CanId, uint8 CanDlc, const uint8 *CanSduPtr)
{
    uint8 ret = E_OK;
    Std_ReturnType canNmRet = E_OK;
    Nm_StateType nmState = NM_STATE_UNINIT;
    Nm_ModeType nmMode = NM_STATE_UNINIT;


    /* check Rx PDU to decide monitor or not*/
    CAN_SERVER_CANIF_PDU(CanIfRxPduId, CanDlc);

    /* frame count */
    switch (CanId)
    {
        case 0x265:
        {
            ABS3_counter.Counter++;
            ABS3_counter.Data = ((uint16) (((uint16)CanSduPtr[3]) & (uint16)0x0003) << 8) | (uint16) (CanSduPtr[4]);
        }
            break;

        case 0x271:
        {
            ECM2_counter.Counter++;
            ECM2_counter.Data = (uint16) (((uint16)CanSduPtr[1]) << 8) | (uint16) (CanSduPtr[2]);
        }
            break;

        case 0x137:
        {
            ESP_FD2_counter.Counter++;
            ESP_FD2_counter.Data = ((uint16) (((uint16)CanSduPtr[43]) & (uint16)0x0003) << 8) | (uint16) (CanSduPtr[44]);
        }
			break;

        default:
			/* do nothing */
            break;
    }

    /* Network management in PBM and BSM, diag frame is blocked */
    switch (CanId)
    {
        case 0x760:
        case 0x773:
        {
            canNmRet = CanNm_GetState(0, &nmState, &nmMode);
            if (E_OK == canNmRet)
            {
                if (nmState <= NM_STATE_PREPARE_BUS_SLEEP)
                {
                    ret |= E_NOT_OK;
                }
            }
        }
            break;

        default:
            /* secoc switch */
            ret |= Secoc_CanIfRxIndication((uint16) CanId, CanSduPtr, CanDlc);
            break;
    }

    ret |= CanServer_RxPDUTimeoutMonitor(CanIfRxPduId);

    return ret;
}

/**
 * @brief 
 * 
 */
void SecOc_KeyElementSetFail(void)
{ 
    KeyStorageOk = FALSE;
    (void)crypto_warn("Secoc key storage error \r\n");
}
/**
 * @brief 
 * 
 */
void SecOc_KeyElementSetOk(void)
{
    KeyStorageOk = TRUE;
    (void)crypto_warn("Secoc key storage success! \r\n");

}
/**
 * @brief 
 * 
 * @param ServiceId 
 * @param JobResult 
 */
void Secoc_NvmTripCounterWriteNotification(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
    if(ServiceId == NVM_WRITE_BLOCK)
    {
        if(JobResult != NVM_REQ_OK)
        {
            (void)Rte_Call_Monitor_Fvm_TripCount_NVM_SetEventStatus(DEM_EVENT_STATUS_FAILED);
            (void)crypto_warn("Secoc trip cnt write error,DTC event write ! trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }
        else
        {
            (void)Rte_Call_Monitor_Fvm_TripCount_NVM_SetEventStatus(DEM_EVENT_STATUS_PASSED);
            (void)crypto_warn("Secoc trip cnt write ok,DTC event clean ! trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }
    }

    if(ServiceId == NVM_READ_BLOCK)
    {
        if(JobResult != NVM_REQ_OK)
        {
            (void)Rte_Call_Monitor_Fvm_TripCount_NVM_SetEventStatus(DEM_EVENT_STATUS_FAILED);
            (void)crypto_warn("Secoc trip cnt read error,DTC event write ! trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }
        else
        {
            (void)Rte_Call_Monitor_Fvm_TripCount_NVM_SetEventStatus(DEM_EVENT_STATUS_PASSED);
            (void)crypto_warn("Secoc trip cnt read ok,DTC event clean ! trip = 0x%x,reset = 0x%x\r\n",FvM_GetLatestTripCounter() ,FvM_GetLatestResetCounter());
        }
    }
}


/**
 * @brief 
 * 
 * @param pduId 
 * @param MsgCnt 
 */

#include "FvM.h"
uint8 Seco_CmdIf_SetTxMsgCounter(uint16 msgId,uint32 MsgCnt)
{
    uint8 i = 0;
    uint8 ret = E_NOT_OK;
    uint8 freshnessValueLayoutId = 0;

    #ifdef SECOC_CLI_IF
    for(;i < SECOC_TXPDU_NUM; i ++)
    {
        if(SecocPduLookUpTable[i].msgId == msgId)
        {
            freshnessValueLayoutId = SecocPduLookUpTable[i].SecocId;
            freshnessValueLayoutId *= 2;
            break;
        }
    }
    /* msgId valid */
    if(i < SECOC_TXPDU_NUM )
    {

        uint32 MessageCounterValueIntern = MsgCnt;
        FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType bitsToCopy = FvM_GetMessageCounterBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
        FvM_FreshnessValueArrayIterType interVal = FvM_GetFreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
        FvM_LastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType lastBitCount = FvM_GetLastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

        for(; interVal > FvM_GetFreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); interVal--)
        {
            FvM_FreshnessValueArrayIterType destIdx = interVal - 1u;
            if(lastBitCount != 0u)
            {
                uint8 unUsedBits = 8u - lastBitCount;
                uint8 messageCounterValueMask = 255u >> unUsedBits;
                uint8 unUsedBitsMask = 255u >> lastBitCount;

                uint8 copyByte = (uint8) (MessageCounterValueIntern & messageCounterValueMask) << unUsedBits;
                copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));
                FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

                MessageCounterValueIntern = MessageCounterValueIntern >> lastBitCount;
                bitsToCopy = bitsToCopy - lastBitCount;
                lastBitCount = 0u;
            }
            else
            if((bitsToCopy / 8u) > 0u)  /* COV_FVM_MESSAGE_COUNTER_BIT_COUNT */
            {
            uint8 copyByte = (uint8) MessageCounterValueIntern & 255u;        /* PRQA S 2985 */ /* MD_FvM_2985 */
            FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */
            MessageCounterValueIntern = MessageCounterValueIntern >> 8;
            bitsToCopy = bitsToCopy - 8u;
            }
            else        /* COV_FVM_MISRA */
            {
            /* do nothing */
            }
        }
        
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    #else
	(void)msgId;
    (void)MsgCnt;
    ret = E_NOT_OK;
    #endif

    return ret;
}
