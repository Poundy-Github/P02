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
 * @file:      GNSS_Alg.c
 * @author:    Nobo
 * @date:      2021-3-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-3-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"
#ifdef PLATFOEM_OF_GNSS_USED

#include <stdio.h>
#include <string.h>

#include "GNSS_RI.h"
#include "GNSS_Com.h"
#include "GNSS_Alg.h"

//===============================================add by GW00221986
#if(STD_ON == GNSS_GW00221986_MANAGER_EN)
//=======================================================================
//============================== Headers ================================
//=======================================================================
#include "RingBuffer.h"

//=======================================================================
//============================== Variables ==============================
//=======================================================================
//Open/Close By Trace Order
boolean gnssInfoTrace = FALSE;

// Private Context 
static GNSS_Alg_Context_t tGNSS_Alg_Context;

//app event input
static tGNSSManagerInput_t sGNSSManagerInput={eGNSS_Cmd_Empty,FALSE,FALSE,eGNSSNMEA_v40,eGNSSNAV_1Hz};

//GNSS manager contex
static tGNSSManager_t sGNSSManager={FALSE,eGNSS_Manager_Idle,eGNSS_Device_Busy,0,NULL_PTR,{0},{0}}; 

//gnss order header
const uint8 GNSS_CMD_PDTINFO[] = "$PDTINFO";//get GNSS info
const uint8 GNSS_CMD_CFGNMEA[] = "$CFGNMEA";//NEMA
const uint8 GNSS_CMD_CFGMSG[] = "$CFGMSG";//single CFG
const uint8 GNSS_CMD_CFGNAV[] = "$CFGNAV";//freqency
const uint8 GNSS_CMD_CFGSAVE[] = "$CFGSAVE";//save
const uint8 GNSS_CMD_CFGCLR[] = "$CFGCLR";//clear
const uint8 GNSS_CMD_RESET[] = "$RESET,0,h0";//reset
const uint8 GNSS_CMD_OK[] = "$OK";//ok

//GNSS MSG split function contex
static tGNSSMsgSplit_t tGnssSplitComtex={NULL_PTR,',','*',0,0,{0}};

//GNSS HW uart buff
uint8 GNSS_CMD_BUFF[GNSS_CMD_BUFF_LEN]="";//send to gnss
uint8 GNSS_RCV_BUFF[GNSS_CMD_BUFF_LEN]="";//receive from gnss ,such as:"$,,,\r\n"


//=======================================================================
//============================== Functions ==============================
//=======================================================================
//split function : by ',' and '*'
void splitFunc(tGNSSMsgSplit_t *Contex);
//alg each char
static void GNSS_Alg_Parser(GNSS_Alg_Context_t * Context,uint8 ch);
//gnss trace printf set
void GNSS_TracePrintfSet(boolean vlu)
{
	gnssInfoTrace = vlu;
}

//when Input Event Deal Completed , Clear Contex Data
void GNSS_InputClear(tGNSSManagerInput_t *pInput)
{
	pInput->eCmdInput = eGNSS_Cmd_Empty;
	pInput->bSet = FALSE;
	pInput->bAns = FALSE;
	pInput->tNMEA = eGNSSNMEA_MAX;
	pInput->tNAV = eGNSSNAV_MAX;
	memset(tGnssSplitComtex.cSplitArry[0][0],0,(GNSS_MSG_ALY_SPLIT_NUM*GNSS_MSG_ALY_SPLIT_CHARS));
	memset(GNSS_RCV_BUFF,0,GNSS_CMD_BUFF_LEN);
}
//===============================================PDTINFO
static boolean  GNSS_CMD_PDTINFO_Send(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//
	memset(GNSS_CMD_BUFF,0,GNSS_CMD_BUFF_LEN);
	strcat(GNSS_CMD_BUFF,GNSS_CMD_PDTINFO);
	//set or read
	if(pInput->bSet == TRUE)//order was set
	{
	}
	else//order was read
	{
	}
	//
	strcat(GNSS_CMD_BUFF,"\r\n");
	gnss_info(GNSS_CMD_BUFF);
	//
	(void)RB_Push(GNSS_TX_RING_BUFFER_ID, GNSS_CMD_BUFF,strlen(GNSS_CMD_BUFF));
	Uart_TriggerTransmit(UART_ID_GPS);
	//
	ret = TRUE;
	return ret;
}
static boolean  GNSS_CMD_PDTINFO_Calibrate(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//uint8 i = 0 ;
	IPC_M2S_GNSSConfigPDTINFO_Data_t tData;
	if(TRUE == pInput->bAns)
	{
		//set or read
		if(pInput->bSet == TRUE)//order was set
		{
			if(NULL_PTR != strstr(GNSS_RCV_BUFF,GNSS_CMD_OK))
			{
				ret = TRUE;
			}
		}
		else//order was read
		{
			tData.PDTINFODataLength = strlen(GNSS_RCV_BUFF);
			memcpy(&tData.PDTINFOData,GNSS_RCV_BUFF,(tData.PDTINFODataLength));
			IPC_M2S_GNSSConfigPDTINFO_Data_Transmit(&tData);
			//
			tGnssSplitComtex.uSplitSybl = ',';
			tGnssSplitComtex.uSplitSyblA = '*';
			tGnssSplitComtex.pSrc = GNSS_RCV_BUFF;
			tGnssSplitComtex.u8CharNum = strlen(GNSS_RCV_BUFF);
			splitFunc(&tGnssSplitComtex);
			//
			if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[0],GNSS_CMD_PDTINFO))
			{
				ret = TRUE;
			}
		}
	}
	//return
	return ret;
}
static const tGNSSCmdFun_t  tGNSS_CMD_PDTINFO_FuncList[] = 
{
	GNSS_CMD_PDTINFO_Send,
	GNSS_CMD_PDTINFO_Calibrate,
};

//===============================================CFGNMEA
static boolean  GNSS_CMD_CFGNMEA_Send(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//
	memset(GNSS_CMD_BUFF,0,GNSS_CMD_BUFF_LEN);
	strcat(GNSS_CMD_BUFF,GNSS_CMD_CFGNMEA);
	//set or read
	if(pInput->bSet == TRUE)//order was set
	{
		switch(pInput->tNMEA)
		{
			case eGNSSNMEA_v30://NEMA 3.0
				strcat(GNSS_CMD_BUFF,",h30");
			break;
			case eGNSSNMEA_v40://NEMA 4.0
				strcat(GNSS_CMD_BUFF,",h51");
			break;
			case eGNSSNMEA_v41://NEMA 4.1
				strcat(GNSS_CMD_BUFF,",h52");
			break;
			default:
			/* nothing to do */
			break;
		}
	}
	else//order was read
	{
		//read
	}
	strcat(GNSS_CMD_BUFF,"\r\n");
	gnss_info(GNSS_CMD_BUFF);
	//
	(void)RB_Push(GNSS_TX_RING_BUFFER_ID, GNSS_CMD_BUFF,strlen(GNSS_CMD_BUFF));
	Uart_TriggerTransmit(UART_ID_GPS);
	//
	ret = TRUE;
	return ret;
}
static boolean  GNSS_CMD_CFGNMEA_Calibrate(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//uint8 i = 0 ;
	IPC_M2S_GNSSNMEAData_t tData;
	IPC_M2S_GNSSConfigNMEA_Data_t tData_N;
	if(TRUE == pInput->bAns)
	{
		//set or read
		if(pInput->bSet == TRUE)//order was set
		{
			if(NULL_PTR != strstr(GNSS_RCV_BUFF,GNSS_CMD_OK))
			{
				ret = TRUE;
			}
		}
		else//order was read
		{
			tGnssSplitComtex.uSplitSybl = ',';
			tGnssSplitComtex.uSplitSyblA = '*';
			tGnssSplitComtex.pSrc = GNSS_RCV_BUFF;
			tGnssSplitComtex.u8CharNum = strlen(GNSS_RCV_BUFF);
			splitFunc(&tGnssSplitComtex);
			//
			if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[1],",h30"))
			{
				tData.NmeaVersion = (uint8)eGNSSNMEA_v30;
				IPC_M2S_GNSSNMEAData_Transmit(&tData);
				tData_N.NmeaVersion = (uint8)eGNSSNMEA_v30;
				IPC_M2S_GNSSConfigNMEA_Data_Transmit(&tData_N);
				ret = TRUE;
			}
			else if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[1],",h51"))
			{
				tData.NmeaVersion = (uint8)eGNSSNMEA_v40;
				IPC_M2S_GNSSNMEAData_Transmit(&tData);
				tData_N.NmeaVersion = (uint8)eGNSSNMEA_v40;
				IPC_M2S_GNSSConfigNMEA_Data_Transmit(&tData_N);
				ret = TRUE;
			}
			else if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[1],",h52"))
			{
				tData.NmeaVersion = (uint8)eGNSSNMEA_v41;
				IPC_M2S_GNSSNMEAData_Transmit(&tData);
				tData_N.NmeaVersion = (uint8)eGNSSNMEA_v41;
				IPC_M2S_GNSSConfigNMEA_Data_Transmit(&tData_N);
				ret = TRUE;
			}
		}
	}
	//return
	return ret;
}
static const tGNSSCmdFun_t  tGNSS_CMD_CFGNMEA_FuncList[] = 
{
	GNSS_CMD_CFGNMEA_Send,
	GNSS_CMD_CFGNMEA_Calibrate,
};
	
//===============================================CFGMSG
static boolean  GNSS_CMD_CFGMSG_Send(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//uint16 i = 0 ;
	//
	memset(GNSS_CMD_BUFF,0,GNSS_CMD_BUFF_LEN);
	strcat(GNSS_CMD_BUFF,GNSS_CMD_CFGMSG);
	//set or read
	if(pInput->bSet == TRUE)//order was set
	{
	}
	else//order was read
	{
	}
	if(0 == pInput->bSet)
	{
	}
	strcat(GNSS_CMD_BUFF,"\r\n");
	gnss_info(GNSS_CMD_BUFF);
	//
	(void)RB_Push(GNSS_TX_RING_BUFFER_ID, GNSS_CMD_BUFF,strlen(GNSS_CMD_BUFF));
	Uart_TriggerTransmit(UART_ID_GPS);
	
	ret = TRUE;
	return ret;
}
static boolean  GNSS_CMD_CFGMSG_Calibrate(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	if(TRUE == pInput->bAns)
	{
		//set or read
		if(pInput->bSet == TRUE)//order was set
		{
			if(NULL_PTR != strstr(GNSS_RCV_BUFF,GNSS_CMD_OK))
			{
				ret = TRUE;
			}
		}
		else//order was read
		{
			//
		}
	}
	return ret;
}
static const tGNSSCmdFun_t  tGNSS_CMD_CFGMSG_FuncList[] = 
{
	GNSS_CMD_CFGMSG_Send,
	GNSS_CMD_CFGMSG_Calibrate,
};
	
//===============================================CFGNAV
static boolean  GNSS_CMD_CFGNAV_Send(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//
	memset(GNSS_CMD_BUFF,0,GNSS_CMD_BUFF_LEN);
	strcat(GNSS_CMD_BUFF,GNSS_CMD_CFGNAV);
	//set or read
	if(pInput->bSet == TRUE)//order was set
	{
		switch(pInput->tNAV)
		{
			case eGNSSNAV_1Hz://1000:1HZ
				strcat(GNSS_CMD_BUFF,",1000,1000,3");
			break;
			case eGNSSNAV_2Hz://500:2HZ
				strcat(GNSS_CMD_BUFF,",1000,500,3");
			break;
			case eGNSSNAV_5Hz://200:5HZ
				strcat(GNSS_CMD_BUFF,",1000,200,3");
			break;
			default:
			/* nothing to do */
			break;
		}
	}
	else//order was read
	{
		//read
	}
	strcat(GNSS_CMD_BUFF,"\r\n");
	gnss_info(GNSS_CMD_BUFF);
	//
	(void)RB_Push(GNSS_TX_RING_BUFFER_ID, GNSS_CMD_BUFF,strlen(GNSS_CMD_BUFF));
	Uart_TriggerTransmit(UART_ID_GPS);

	ret = TRUE;
	return ret;
}
static boolean  GNSS_CMD_CFGNAV_Calibrate(tGNSSManagerInput_t *pInput)
{	
    boolean ret = FALSE;
	//uint8 i = 0 ;
	IPC_M2S_GNSSNAVData_t tData;
	IPC_M2S_GNSSConfigNAV_Data_t tData_N;
	if(TRUE == pInput->bAns)
	{
		//set or read
		if(pInput->bSet == TRUE)//order was set
		{
			if(NULL_PTR != strstr(GNSS_RCV_BUFF,GNSS_CMD_OK))
			{
				ret = TRUE;
			}
		}
		else//order was read
		{
			tGnssSplitComtex.uSplitSybl = ',';
			tGnssSplitComtex.uSplitSyblA = '*';
			tGnssSplitComtex.pSrc = GNSS_RCV_BUFF;
			tGnssSplitComtex.u8CharNum = strlen(GNSS_RCV_BUFF);
			splitFunc(&tGnssSplitComtex);
			//
			if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[2],",1000"))
			{
				tData.NAVData = (uint8)eGNSSNAV_1Hz;
				IPC_M2S_GNSSNAVData_Transmit(&tData);
				tData_N.NAVData = (uint8)eGNSSNAV_1Hz;
				IPC_M2S_GNSSConfigNAV_Data_Transmit(&tData_N);
				ret = TRUE;
			}
			else if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[2],",500"))
			{
				tData.NAVData = (uint8)eGNSSNAV_2Hz;
				IPC_M2S_GNSSNAVData_Transmit(&tData);
				tData_N.NAVData = (uint8)eGNSSNAV_2Hz;
				IPC_M2S_GNSSConfigNAV_Data_Transmit(&tData_N);
				ret = TRUE;
			}
			else if(NULL_PTR != strstr(tGnssSplitComtex.cSplitArry[2],",200"))
			{
				tData.NAVData = (uint8)eGNSSNAV_5Hz;
				IPC_M2S_GNSSNAVData_Transmit(&tData);
				tData_N.NAVData = (uint8)eGNSSNAV_5Hz;
				IPC_M2S_GNSSConfigNAV_Data_Transmit(&tData_N);
				ret = TRUE;
			}
		}
	}
	//return
	return ret;
}
static const tGNSSCmdFun_t  tGNSS_CMD_CFGNAV_FuncList[] = 
{
	GNSS_CMD_CFGNAV_Send,
	GNSS_CMD_CFGNAV_Calibrate,
};
	
//===============================================total list
#define GNSS_CMD_SequenceRegister(state,list)              {state,sizeof(list)/sizeof(list[0]),&list[0]}
#define GNSS_CMD_INPUT_Size                                (sizeof(tGnssGetSetSequence)/sizeof(tGnssGetSetSequence[0]))
static const tGNSSCmdDelSequence_t tGnssGetSetSequence[] =
{   
    GNSS_CMD_SequenceRegister(eGNSS_Cmd_PDTINFO,tGNSS_CMD_PDTINFO_FuncList),
    GNSS_CMD_SequenceRegister(eGNSS_Cmd_CFGNMEA,tGNSS_CMD_CFGNMEA_FuncList),
    GNSS_CMD_SequenceRegister(eGNSS_Cmd_CFGMSG,tGNSS_CMD_CFGMSG_FuncList),
    GNSS_CMD_SequenceRegister(eGNSS_Cmd_CFGNAV,tGNSS_CMD_CFGNAV_FuncList),
}; 

//=================================================application event set or read
void app_GNSS_CMD_PDTINFO_GetTriger(void)
{
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	io->eCmdInput = eGNSS_Cmd_PDTINFO;
	io->bSet = FALSE;
}
boolean app_GNSS_CMD_CFGNMEA_Set(eGNSSNMEA_t nmea)
{
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	if(nmea < eGNSSNMEA_MAX)
	{
		io->eCmdInput = eGNSS_Cmd_CFGNMEA;
		io->bSet = TRUE;
		io->tNMEA = nmea;
	}
	return TRUE;
}
void app_GNSS_CMD_CFGNMEA_GetTriger(void)
{
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	io->eCmdInput = eGNSS_Cmd_CFGNMEA;
	io->bSet = FALSE;
}
boolean app_GNSS_CMD_CFGNAV_Set(eGNSSNAV_t nav)
{
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	if(nav < eGNSSNAV_MAX)
	{
		io->eCmdInput = eGNSS_Cmd_CFGNAV;
		io->bSet = TRUE;
		io->tNAV = nav;
	}
	return TRUE;
}
void app_GNSS_CMD_CFGNAV_GetTriger(void)
{
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	io->eCmdInput = eGNSS_Cmd_CFGNAV;
	io->bSet = FALSE;
}
void app_GNSS_CMD_ERR_FRAME_GetTriger(void)
{
	GNSS_Alg_Context_t *Contex = &tGNSS_Alg_Context;
	IPC_M2S_GNSSFrameLossData_t tData;
	IPC_M2S_GNSSConfigFrameLoss_Data_t tData_N;
	//
	tData.FrameLossNum = Contex->errFrameNum;
	IPC_M2S_GNSSFrameLossData_Transmit(&tData);
	tData_N.FrameLossNum = Contex->errFrameNum;
	IPC_M2S_GNSSConfigFrameLoss_Data_Transmit(&tData_N);
}
void app_GNSS_CMD_ERR_FRAME_SetTriger(uint16 data)
{
	GNSS_Alg_Context_t *Contex = &tGNSS_Alg_Context;
	//
	Contex->errFrameNum = data;
}

//gnss uart device status set:IDLE or BUSY
boolean GNSSManager_DeviceStatusSet(eGNSSDeviceStatus_t sts)
{
    boolean ret = FALSE;
	if(sts < eGNSS_Device_MAX)
	{
		sGNSSManager.eDeviceStatus = sts;
	}
	return ret;
}
//gnss receive form uart:"$,,,\r\n"
boolean GNSSManager_RCV_BUFF_Fresh(uint8 *recvBuff)
{
	tGNSSManager_t *pGNSSManager = &sGNSSManager;
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	boolean pushIn = FALSE;
	if(eGNSS_Manager_Deal == pGNSSManager->eManagerStatus)
	{
		//order was set ,gnss return OK 
		if(io->bSet == TRUE)
		{
			if(NULL_PTR != strstr(recvBuff,GNSS_CMD_OK))
			{
				pushIn = TRUE;
			}
		}
		else//order was read
		{
			switch(io->eCmdInput)
			{
				case eGNSS_Cmd_PDTINFO:
					if(NULL_PTR != strstr(recvBuff,GNSS_CMD_PDTINFO))
					{
						pushIn = TRUE;
					}
				break;
				case eGNSS_Cmd_CFGNMEA:
					if(NULL_PTR != strstr(recvBuff,GNSS_CMD_CFGNMEA))
					{
						pushIn = TRUE;
					}
				break;
				case eGNSS_Cmd_CFGMSG:
					if(NULL_PTR != strstr(recvBuff,GNSS_CMD_CFGMSG))
					{
						pushIn = TRUE;
					}
				break;
				case eGNSS_Cmd_CFGNAV:
					if(NULL_PTR != strstr(recvBuff,GNSS_CMD_CFGNAV))
					{
						pushIn = TRUE;
					}
				break;
				default:
				/* nothing to do */
				break;
			}
		}
		//
		if(TRUE == pushIn)
		{
			//enable Event Calibrate
			io->bAns = TRUE;
			//push in GNSS_RCV_BUFF
			memset(GNSS_RCV_BUFF,0,GNSS_CMD_BUFF_LEN);
			strcat(GNSS_RCV_BUFF,recvBuff);
			//printf
			gnss_info(GNSS_RCV_BUFF);
		}
	}
}
//=================================================get ptr base on input_Cmd
const tGNSSCmdDelSequence_t * GNSSManager_FuncListGet(eGNSSCmd_t input_Cmd)
{
	uint8 i = 0 ;
	const tGNSSCmdDelSequence_t * ptr = NULL_PTR;

	if(input_Cmd < eGNSS_Cmd_MAX)
	{
		//get input event function list
		for(i=0;i<GNSS_CMD_INPUT_Size;i++)
		{
			if(input_Cmd == tGnssGetSetSequence[i].Cmd)
			{
				ptr = &tGnssGetSetSequence[i];
				break;
			}
		}
	}
	
	return ptr;
}

//================================================gnss input deal handing
boolean GNSSManager_InputProcessing(tGNSSManager_t *mng,tGNSSManagerInput_t *Contex)
{
    boolean ret = FALSE,retDeal = FALSE;
	//
	if(NULL_PTR != mng->pDeal)
	{
		if(mng->u8HandingSeq < mng->pDeal->u8SequenceLen)
		{
			retDeal = mng->pDeal->GnssCmdList[mng->u8HandingSeq](Contex);
			if(TRUE == retDeal)
			{	
				mng->u8HandingSeq++;
			}
		}
		if(mng->u8HandingSeq >= mng->pDeal->u8SequenceLen)
		{
			mng->u8HandingSeq= 0 ;
			ret = TRUE;
		}
	}
	return ret;
}

//===========================================================timer management
void GNSSManager_StartTimer(tGNSSManagerTimer_t *timer,uint16 aim_timer_cnt)
{
	timer->bStart = TRUE;
	timer->u16CurTimerCnt = 0;
	timer->u16AimTimerCnt = aim_timer_cnt;
}
boolean GNSSManager_CheckTimer(tGNSSManagerTimer_t *timer)
{
    boolean ret = FALSE;
	if(TRUE == timer->bStart)
	{
		if(timer->u16CurTimerCnt++ >= timer->u16AimTimerCnt)
		{
			ret = TRUE;
		}
	}
	return ret;
}
void GNSSManager_StopTimer(tGNSSManagerTimer_t *timer)
{
	timer->bStart = FALSE;
	timer->u16CurTimerCnt = 0;
	timer->u16AimTimerCnt = 0;
}
//=========================================================gnss PowerOn InitFunction
static boolean GNSS_PowerOn_Init(tGNSSManager_t *pGNSSManager)
{
	static uint16 u16PowerOnCnt = 0 ,u16Status = 0;
	//tGNSSManagerInput_t *io=&sGNSSManagerInput;
	boolean ret = FALSE;
	//
	switch(u16Status)
	{
		case 0://get GNSS Info
			if(u16PowerOnCnt++ > 1000)//when sys power on 1000*5ms = 5s , read GNSS info
			{
				app_GNSS_CMD_PDTINFO_GetTriger();
				u16PowerOnCnt = 0;
				u16Status++;
			}
		break;
		case 1://set GNSS NMEA
			if(u16PowerOnCnt++ > 200)//then 200*5ms = 1s , get GNSS NMEA
			{
				app_GNSS_CMD_CFGNMEA_GetTriger();
				u16PowerOnCnt = 0;
				u16Status++;
			}
		break;
		case 2://set GNSS NAV
			if(u16PowerOnCnt++ > 200)//then 200*5ms = 1s , get GNSS NAV
			{
				app_GNSS_CMD_CFGNAV_GetTriger();
				u16PowerOnCnt = 0;
				u16Status++;
			}
		break;
		default:
			ret = TRUE;
		break;	
	}
	//
	return ret;
}

//=========================================================gnss deal mainfunction
void GNSS_InputDeal_Mainfunction(void)
{
	//uint8 i=0;
	//boolean ret = FALSE;
	//
	tGNSSManager_t *pGNSSManager = &sGNSSManager;
	tGNSSManagerInput_t *io=&sGNSSManagerInput;
	//
	if(FALSE == pGNSSManager->bGnssInitFlag)
	{
		pGNSSManager->bGnssInitFlag = GNSS_PowerOn_Init(pGNSSManager);
	}
	//
	switch(pGNSSManager->eManagerStatus)
	{
	    case eGNSS_Manager_Idle://input
			if(eGNSS_Cmd_Empty != io->eCmdInput)//input event arrive
			{
				pGNSSManager->pDeal = GNSSManager_FuncListGet(io->eCmdInput);//get deal ptr
				//
				if(NULL_PTR == pGNSSManager->pDeal)//not match
				{
					//print err ptr
					gnss_err("[GNSS-E]:Input=%d,NotSpt\r\n",io->eCmdInput);
					//clear io->eCmdInput
					io->eCmdInput = eGNSS_Cmd_Empty;
					//
					pGNSSManager->eManagerStatus = eGNSS_Manager_Idle;
				}
				else
				{
					//start wait idle timer
					GNSSManager_StartTimer(&pGNSSManager->tUartIdleDelayTimer,GNSS_UART_IDLE_DELAY_TIMER_CNT);//20*5=100ms,wait gnss uart Idle
					//
					gnss_info("[GNSS-I]:Input=%d,r_w=%d\r\n",io->eCmdInput,io->bSet);
					gnss_info("[GNSS-I]:Idle->IdleDelay\r\n");
					//
					pGNSSManager->eManagerStatus = eGNSS_Manager_IdleDelay;
				}
			}
		break;
		case eGNSS_Manager_IdleDelay://wait GNSS uart IDLE
			if(eGNSS_Device_Busy == pGNSSManager->eDeviceStatus)//device status is busy ,restart timer
			{
				GNSSManager_StartTimer(&pGNSSManager->tUartIdleDelayTimer,GNSS_UART_IDLE_DELAY_TIMER_CNT);//20*5=100ms
			}
			else
			{
				if(TRUE == GNSSManager_CheckTimer(&pGNSSManager->tUartIdleDelayTimer))//gnss uart idle delayed
				{
					GNSSManager_StopTimer(&pGNSSManager->tUartIdleDelayTimer);//stop it
					GNSSManager_StartTimer(&pGNSSManager->tInputMaxDealTimer,GNSS_INPUT_MAX_DEAL_TIMER_CNT);//400*5=2000ms,set max deal timer
					//
					gnss_info("[GNSS-I]:IdleDelay->Deal\r\n");
					//
					pGNSSManager->eManagerStatus = eGNSS_Manager_Deal;
					pGNSSManager->u8HandingSeq = 0 ;
				}
			}
		break;
	    case eGNSS_Manager_Deal://handing
			if(NULL_PTR != pGNSSManager->pDeal)
			{
				if(TRUE == GNSSManager_InputProcessing(pGNSSManager,io))
				{
					pGNSSManager->eManagerStatus = eGNSS_Manager_Complet;
				}
				else
				{
					if(TRUE == GNSSManager_CheckTimer(&pGNSSManager->tInputMaxDealTimer))
					{
						//print timerout
						gnss_err("[GNSS-E]:DealTimeout\r\n");
						pGNSSManager->eManagerStatus = eGNSS_Manager_Complet;
					}
				}
			}
			else
			{
				//print err ptr not deal
				gnss_err("[GNSS-E]:ptr was Null\r\n");
				pGNSSManager->eManagerStatus = eGNSS_Manager_Complet;
			}
		break;
		case eGNSS_Manager_Complet:	//complet
			//clear io->eCmdInput
			io->eCmdInput = eGNSS_Cmd_Empty;
			//when Input Event Deal Complete , Clear Swap Data
			GNSS_InputClear(io);
			//
			GNSSManager_StopTimer(&pGNSSManager->tInputMaxDealTimer);//stop max deal timer
			//
			gnss_info("[GNSS-I]:EventDealComplet\r\n");
			pGNSSManager->eManagerStatus = eGNSS_Manager_Idle;	
			pGNSSManager->u8HandingSeq = 0 ;
		break;
		default:
		/* nothing to do */
		break;
	}
}

void splitFunc(tGNSSMsgSplit_t *Contex)
{
	uint8 src_i = 0 ,char_j = 0;
	if(Contex->u8CharNum <= GNSS_CMD_BUFF_LEN)
	{
		Contex->u8SplitNum = 0;
		for(src_i=0;src_i<Contex->u8CharNum;src_i++)
		{
			if((Contex->pSrc[src_i] == Contex->uSplitSybl) || (Contex->pSrc[src_i] == Contex->uSplitSyblA))
			{
				Contex->u8SplitNum++;
				if(Contex->u8SplitNum >= GNSS_MSG_ALY_SPLIT_NUM)
				{
					Contex->u8SplitNum = (GNSS_MSG_ALY_SPLIT_NUM-1);
				}
				char_j = 0;
			}
			//
			Contex->cSplitArry[Contex->u8SplitNum][char_j++] = Contex->pSrc[src_i];
			//
			if(char_j >= GNSS_MSG_ALY_SPLIT_CHARS)
			{
				char_j = (GNSS_MSG_ALY_SPLIT_CHARS-1);
			}
		}
	}
}

void GNSS_Logger_Triger(uint8 *u8LogBuff)
{
	if((u8LogBuff[0]=='$')&&(u8LogBuff[1]=='$')&&(u8LogBuff[2]=='o'))
	{
		gnssInfoTrace = TRUE;
	}
	else if((u8LogBuff[0]=='$')&&(u8LogBuff[1]=='$')&&(u8LogBuff[2]=='c'))
	{
		gnssInfoTrace = FALSE;
	}
	else
	{
		memset(GNSS_CMD_BUFF,0,GNSS_CMD_BUFF_LEN);
		strcat(GNSS_CMD_BUFF,u8LogBuff);
		strcat(GNSS_CMD_BUFF,"\r\n");
		(void)RB_Push(GNSS_TX_RING_BUFFER_ID, GNSS_CMD_BUFF,strlen(GNSS_CMD_BUFF));
		Uart_TriggerTransmit(UART_ID_GPS);
	}
}
#endif
//===============================================end by GW00221986

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GNSS_Alg_Init(void)
{
    tGNSS_Alg_Context.SeriaNetData.BufferLength = 0;
    tGNSS_Alg_Context.tParserState = eGNSS_Alg_WaitHead;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GNSS_Alg_Calculate(void)
{
    ///uint8 buffer[GNSS_Alg_CMD_CACHE_LEN];
    uint16 len;
    sint32 i;

    len = GNSS_Com_ReadData(tGNSS_Alg_Context.buffer,GNSS_Alg_CMD_CACHE_LEN);

    for (i=0; i< len; i++)
    {
        GNSS_Alg_Parser(&tGNSS_Alg_Context,tGNSS_Alg_Context.buffer[i]);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void GNSS_Alg_Parser_Clear(GNSS_Alg_Context_t * Context)
{
    //Context->tParserState = eGNSS_Alg_WaitHead;
    Context->SeriaNetData.BufferLength = 0;
    memset(Context->SeriaNetData.Buffer,0,GNSS_Alg_CMD_MSG_DEEPTH);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void GNSS_Alg_Parser_Start(GNSS_Alg_Context_t * Context)
{
    Context->tParserState = eGNSS_Alg_ReadMessage;
    Context->SeriaNetData.BufferLength = 0;
    memset(Context->SeriaNetData.Buffer,0,GNSS_Alg_CMD_MSG_DEEPTH);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void GNSS_Alg_Parser_Execute(GNSS_Alg_Context_t * Context)
{
    //sint32 i;
	
#ifdef PLATFORM_OF_STB_IPC_USED
    (void) IPC_M2S_GNSSSeriaNetData_Transmit(&Context->SeriaNetData);
#endif

#if (STD_ON == GNSS_MSG_TRACE)
	if(TRUE == gnssInfoTrace)
	{
		gnss_info(Context->SeriaNetData.Buffer);
	}
#endif
}

#if (STD_ON == GNSS_DATA_CHECK_EN)
void GNSS_Alg_Check(uint8 ch)
{
	static boolean checkEN = FALSE;
	static uint8 checkXOR = 0 ,checkVlu = 0 , checkNum =2;
	
	GNSS_Alg_Context_t *Contex = &tGNSS_Alg_Context;
	switch(ch)
	{
		case '$'://check start
			checkEN = TRUE;
			checkXOR = 0 ;
		break;
		case '*'://check end
			checkEN = FALSE;
			checkVlu = 0 ;
			checkNum = 2;
		break;
		case '\n'://frame end
			//gnss_err("[GNSS-E]:%d %d\r\n",checkXOR,checkVlu);
			if(checkXOR != checkVlu)
			{
				Contex->errFrameNum ++;
				gnss_err("[GNSS-E]:frame check faild num = %d\r\n",Contex->errFrameNum);
			}
		break;
		default:
			if(TRUE == checkEN)
			{
				checkXOR = checkXOR^ch;
			}
			else if (checkNum > 0)
			{
				checkVlu <<= 4;
				if((ch >= '0') && (ch <= '9'))
				{
					checkVlu  += (ch - '0');
				}
				else if((ch >= 'A') && (ch <= 'F'))
				{
					checkVlu  += (ch - 'A' + 10);
				}
				checkNum--;
			}
		break;
	}
}
#endif

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void GNSS_Alg_Parser(GNSS_Alg_Context_t * Context,uint8 ch)
{
	//uint16 i = 0;

#if (STD_ON == GNSS_DATA_CHECK_EN)
	GNSS_Alg_Check(ch);
#endif
	//check each char at : Status
	switch(Context->tParserState)
	{
		//wait gnss power on info
		case eGNSS_Alg_WaitInfo:
			Context->SeriaNetData.Buffer[Context->SeriaNetData.BufferLength] = ch;
			Context->SeriaNetData.BufferLength++;
			//
			if(ch == '$')//gnss DATA start char
			{
				GNSS_Alg_Parser_Clear(Context);
				GNSSManager_DeviceStatusSet(eGNSS_Device_Busy);
				Context->tParserState = eGNSS_Alg_ReadMessage;
				//
				Context->SeriaNetData.Buffer[Context->SeriaNetData.BufferLength] = ch;
				Context->SeriaNetData.BufferLength++;
			}else if(ch == '\n')//end char
			{
				//printf Power Gnss Info
				gnss_info(Context->SeriaNetData.Buffer);
				//
				GNSS_Alg_Parser_Clear(Context);
				GNSSManager_DeviceStatusSet(eGNSS_Device_Idle);
				Context->tParserState = eGNSS_Alg_WaitInfo;
			}
		break;

		//gnss normal com DATA start
		case eGNSS_Alg_WaitHead:
			if(ch == '$')
			{
				GNSS_Alg_Parser_Clear(Context);
				GNSSManager_DeviceStatusSet(eGNSS_Device_Busy);
				//
				Context->SeriaNetData.Buffer[Context->SeriaNetData.BufferLength] = ch;
				Context->SeriaNetData.BufferLength++;
				Context->tParserState = eGNSS_Alg_ReadMessage;
			}
		break;
		
		case eGNSS_Alg_ReadMessage://recv gnss data
			Context->SeriaNetData.Buffer[Context->SeriaNetData.BufferLength] = ch;
			Context->SeriaNetData.BufferLength++;
			if(ch == '\n')
			{
				//deal GNSS data : 1
				#if(STD_ON == GNSS_MSG_M2S_EN)
					GNSS_Alg_Parser_Execute(Context);
				#endif

				//deal GNSS data : 2
				GNSSManager_RCV_BUFF_Fresh(Context->SeriaNetData.Buffer);
				
				//clear GNSS data
				GNSS_Alg_Parser_Clear(Context);
				GNSSManager_DeviceStatusSet(eGNSS_Device_Idle);
				Context->tParserState = eGNSS_Alg_WaitHead;
			}
		break;
		default:
			GNSS_Alg_Parser_Clear(Context);
			GNSSManager_DeviceStatusSet(eGNSS_Device_Idle);
			Context->tParserState = eGNSS_Alg_WaitHead;
		break;
	}
	//check frame over , error not recv '\r\n'
	if (Context->SeriaNetData.BufferLength >= GNSS_Alg_CMD_MSG_DEEPTH)
	{
		GNSS_Alg_Parser_Clear(Context);
		GNSSManager_DeviceStatusSet(eGNSS_Device_Idle);
		Context->errFrameNum++;
		Context->tParserState = eGNSS_Alg_WaitHead;
	}
}
#endif
