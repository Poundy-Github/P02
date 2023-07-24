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
 * @file:      GNSS_Alg.h
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

#ifndef _GNSS_ALG_H_
#define _GNSS_ALG_H_
#include "Std_Types.h"
#include "GNSS_RI.h"

//=======================================================================
//============================== Definens ===============================
//=======================================================================
#define GNSS_MSG_M2S_EN			(STD_ON)//GNSS Message Send To SOC
#define GNSS_MSG_TRACE			(STD_ON)//GNSS Message Trace(Open/Close) At Vip Log
#define GNSS_GW00221986_MANAGER_EN	(STD_ON)
#define GNSS_DATA_CHECK_EN					(STD_OFF)

#define GNSS_Alg_CMD_MSG_DEEPTH             (IPC_M2S_GNSS_SERIANET_MSGSUB_DATA_FLEX_NUMBER)
#define GNSS_Alg_CMD_CACHE_LEN              (256)

#define GNSS_UART_IDLE_DELAY_TIMER_CNT		(10)//5ms*10
#define GNSS_INPUT_MAX_DEAL_TIMER_CNT		(400)//5ms*400
#define GNSS_CMD_TEST_BLOCK_NUM				(10)//split by ','
#define GNSS_CMD_TEST_BLOCK_LEN				(50)
#define GNSS_CMD_BUFF_LEN					(256)


//==gnss order recv analyse
#define  GNSS_MSG_ALY_SPLIT_NUM				(10)//max split out num
#define  GNSS_MSG_ALY_SPLIT_CHARS			(15)//max split out chars

//==sys timestamp 
extern void TM_Timer1msStartStamp(uint32 * StartStamp);
#define GNSS_GET_OSTick(X)		TM_Timer1msStartStamp(X)

//==GNSS Used Ring Buff
#define GNSS_TX_RING_BUFFER_ID          RB_ID_GPS_UART_TX
#define GNSS_RX_RING_BUFFER_ID          RB_ID_GPS_UART_RX

//==enum of : GNSS Input Event
typedef enum 
{
	eGNSS_Cmd_Empty = 0 ,
    eGNSS_Cmd_PDTINFO = 1,
    eGNSS_Cmd_CFGNMEA = 2,
    eGNSS_Cmd_CFGMSG = 3,
    eGNSS_Cmd_CFGNAV = 4,
    eGNSS_Cmd_MAX
}eGNSSCmd_t;
	
//==enum of : GNSS NMEA Input (From IPC ...)
typedef enum
{
	eGNSSNMEA_v30=0,//NEMA 3.0
	eGNSSNMEA_v40=1,//NEMA 4.0
	eGNSSNMEA_v41=2,//NEMA 4.1
	eGNSSNMEA_MAX
}eGNSSNMEA_t;
	
//==enum of : GNSS NAV Input (From IPC ...)
typedef enum
{
	eGNSSNAV_1Hz=0,//1000:1HZ
	eGNSSNAV_2Hz=1,//500:2HZ
	eGNSSNAV_5Hz=2,//200:5HZ
	eGNSSNAV_MAX
}eGNSSNAV_t;
	
//==struct of : GNSS Event Manager Function
typedef struct
{
	eGNSSCmd_t			eCmdInput;//event input cmd
	boolean				bSet;//set or get
	boolean				bAns;//gnss answer
	eGNSSNMEA_t 		tNMEA;
	eGNSSNAV_t			tNAV;
}tGNSSManagerInput_t;

//==functions of : GNSS Event Deal 
typedef boolean (*tGNSSCmdFun_t)(tGNSSManagerInput_t *);
typedef struct
{
    eGNSSCmd_t   				Cmd;
    uint8                       u8SequenceLen;
    const tGNSSCmdFun_t *  		GnssCmdList;
}tGNSSCmdDelSequence_t;

// Parser State define
typedef enum 
{
    eGNSS_Alg_WaitHead = 0,
    eGNSS_Alg_ReadMessage,
    eGNSS_Alg_WaitInfo,//when gnss power on ,it's Version Info will be sendout
    eGNSS_Alg_RecvEnd,
}GNSS_Alg_ParserState_t;


//==enum of : GNSS Event Manager Function Status
typedef enum 
{
    eGNSS_Manager_Idle = 0,
    eGNSS_Manager_IdleDelay = 1,
    eGNSS_Manager_Deal = 2,
    eGNSS_Manager_Complet = 3,
    eGNSS_Manager_MAX
}eGNSSManager_t;
//==enum of : GNSS Device Uart Status
typedef enum 
{
    eGNSS_Device_Idle = 0,
    eGNSS_Device_Busy = 1,
    eGNSS_Device_MAX
}eGNSSDeviceStatus_t;
//==struct of : GNSS Timer
typedef struct
{
	boolean bStart;
	uint16	u16CurTimerCnt;
	uint16	u16AimTimerCnt;
}tGNSSManagerTimer_t;
//==stuct of : GNSS Event Manager Function
typedef struct
{
	boolean				bGnssInitFlag;
    eGNSSManager_t		eManagerStatus;
	eGNSSDeviceStatus_t eDeviceStatus;
	uint8				u8HandingSeq;//reuse by each event handing
	const tGNSSCmdDelSequence_t *pDeal;
	tGNSSManagerTimer_t	tUartIdleDelayTimer;
	tGNSSManagerTimer_t	tInputMaxDealTimer;
}tGNSSManager_t;

//==struct of : GNSS Split
typedef struct
{
	uint8 	*pSrc;
	uint8	uSplitSybl;//','
	uint8	uSplitSyblA;//'*'
	uint8 	u8CharNum;
	uint8 	u8SplitNum;
	char	cSplitArry[GNSS_MSG_ALY_SPLIT_NUM][GNSS_MSG_ALY_SPLIT_CHARS];
}tGNSSMsgSplit_t;

typedef struct
{
    IPC_M2S_GNSSSeriaNetData_t SeriaNetData;
    GNSS_Alg_ParserState_t tParserState;
	uint8 buffer[GNSS_Alg_CMD_CACHE_LEN];
	uint16 errFrameNum;
}GNSS_Alg_Context_t;

//
void GNSS_Alg_Init(void);
void GNSS_Alg_Calculate(void);
//
void GNSS_InputDeal_Mainfunction(void);
extern void GNSS_Logger_Triger(uint8 *u8LogBuff);
extern boolean app_GNSS_CMD_CFGNMEA_Set(eGNSSNMEA_t nmea);
extern boolean app_GNSS_CMD_CFGNAV_Set(eGNSSNAV_t nav);

extern void app_GNSS_CMD_CFGNMEA_GetTriger(void);
extern void app_GNSS_CMD_CFGNAV_GetTriger(void);
extern void app_GNSS_CMD_ERR_FRAME_GetTriger(void);
extern void GNSS_TracePrintfSet(boolean vlu);
extern void app_GNSS_CMD_ERR_FRAME_SetTriger(uint16 data);
extern void app_GNSS_CMD_PDTINFO_GetTriger(void);
#endif /* ifndef _GNSS_ALG_H_.2021-3-6 10:50:41 GW00188879 */

#endif
