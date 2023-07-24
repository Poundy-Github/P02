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

/***********************************************************************************************************
**
**  Name:               Swc_Chime_Adapt.h
**
**  Description:        The main switching logic of the chime module
**
**  Organization:       
**
**********************************************************************************************************/
#ifndef SWC_CHIME_ADAPT_H
#define SWC_CHIME_ADAPT_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Ipc_ClusterApp.h"
#include "Rte_type.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Project dfine                                                                                           *
**********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B03
	#define CHIME_PROJECT_TYPE_B03		1
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_B02
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		1
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
    #include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		1
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_B06
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		1
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		1
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_A07
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		1
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D01
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		1
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D02
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		1
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_D03
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		1
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P02
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		1
	#define CHIME_PROJECT_TYPE_P01		0
#elif defined GWM_V35_PROJECT_TYPE_P01  
	#define CHIME_PROJECT_TYPE_B03		0
	#define CHIME_PROJECT_TYPE_B02 		0
	#define CHIME_PROJECT_TYPE_P05		0
	#define CHIME_PROJECT_TYPE_B06 		0
	#define CHIME_PROJECT_TYPE_P03		0
	#define CHIME_PROJECT_TYPE_A07		0
	#define CHIME_PROJECT_TYPE_D01		0
	#define CHIME_PROJECT_TYPE_D02		0
	#define CHIME_PROJECT_TYPE_D03		0
	#define CHIME_PROJECT_TYPE_P02		0
	#define CHIME_PROJECT_TYPE_P01		1

#else
	#error "No Project defined"
#endif

/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
#define SWC_CHIME_PRINTF_LEVEL3
//#define SWC_CHIME_PRINTF_LEVEL2
//#define SWC_CHIME_PRINTF_LEVEL3

#ifdef SWC_CHIME_PRINTF_LEVEL1

#define SWC_CHIME_INFO_LOG						vipChime_info

#define SWC_CHIME_WARN_LOG(...)

#define SWC_CHIME_ERROR_LOG						vipChime_err

#elif defined SWC_CHIME_PRINTF_LEVEL2

#define SWC_CHIME_INFO_LOG(...)

#define SWC_CHIME_WARN_LOG						vipChime_warn

#define SWC_CHIME_ERROR_LOG						vipChime_err

#elif defined SWC_CHIME_PRINTF_LEVEL3

#define SWC_CHIME_INFO_LOG						vipChime_info

#define SWC_CHIME_WARN_LOG						vipChime_warn

#define SWC_CHIME_ERROR_LOG						vipChime_err

#else
#define SWC_CHIME_INFO_LOG(...)

#define SWC_CHIME_WARN_LOG(...)

#define SWC_CHIME_ERROR_LOG(...)
#endif

typedef enum
{
	ChimeOstmTimer1 = 0,
	ChimeOstmTimer2,
	ChimeOstmTimer3,
	ChimeOstmTimer4,
	ChimeOstmTimer5,
	ChimeOstmTimerAll,
}e_ChimeOstmTimer_t;

typedef enum
{
	ChimeLconfigChimedelaytime = 0,
	ChimeLconfigDoortoRed_speedthreshold,
	ChimeLconfigADASsoundfieldEnable,
	ChimeLconfigAllFieldEnable,
	ChimeLconfigFIXDISPLAY_1_GEAR_ENABLE,
	ChimeLconfigFIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE,
	ChimeLconfigDISPLAY_6_GEAR_ENABLE,
	ChimeLconfigDISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE,
	ChimeVconfigCENTER_SPEAKKER,
	ChimeVconfigCANFD_USE_FLAG,
	ChimeLconfigAll,
}e_ChimeLocationConfig_t;

typedef IPC_S2M_ClusterAppClusterSocBackChime_t s_IPCChimeCallback_t;
typedef IPC_S2M_ClusterAppClusterSocWrnId_t s_IPCWrnCallback_t;
typedef IPC_S2M_ClusterAppClusterSocTTStatus_t s_IPCTTCallback_t;
typedef IPC_S2M_ClusterAppClusterSocAdasStatus_t s_IPCAdasCallback_t;
typedef Std_ReturnType ChimeMessageType;


#define IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER				8U
#define IPC_CHIME_WRN_MESSAGE_LIST_NUMBER				8U
#define IPC_CHIME_TT_MESSAGE_LIST_NUMBER				8U
#define IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER				8U

#define RTE_E_INVALID_SIGNAL_DIFPROJET					15U


typedef WN_WarningStsOutput s_SWCWrnModule_t;

typedef struct
{
	s_IPCChimeCallback_t data[IPC_CHIME_AUDIO_MESSAGE_LIST_NUMBER];
	uint16 listNumber;
}s_ChimeChimeCallback_t;

typedef struct
{
	s_IPCWrnCallback_t data[IPC_CHIME_WRN_MESSAGE_LIST_NUMBER];
	uint16 listNumber;
}s_ChimeWrnCallback_t;

typedef struct
{
	s_IPCTTCallback_t data[IPC_CHIME_TT_MESSAGE_LIST_NUMBER];
	uint16 listNumber;
}s_ChimeTTCallback_t;

typedef struct
{
	s_IPCAdasCallback_t data[IPC_CHIME_ADAS_MESSAGE_LIST_NUMBER];
	uint16 listNumber;
}s_ChimeAadsCallback_t;

typedef struct
{
	uint8 					SoundId_u8;		//enum:e_SoundTypeList_t
	uint8 					Volume_u8;		//start new sound volume  0 --%0  50--%50  100--%100
	uint8 					Operation_u8;	//0:NULL 1:start 2:immediately start 3 :stop 4 :immediately stop 5:read 6:set current sound volume
	uint8 					Toggle_u8;		//Clear sbus byte
	uint32 					RepeatTime_u32; //Sound repetitions, [0:continue other:play time]
	uint32 					Soundtrack; //Sound repetitions, [0:continue other:play time]
}e_ChimeIPCCommand_t;

typedef struct
{
	uint32			 		TimerTick_u32;
	uint8					Status_u8;
}s_ChimeOstmData_t;   

typedef struct
{
	uint8 Chimedelaytime_u8;
	uint8 DoortoRed_speedthreshold_u8;
	uint8 ADASsoundfieldEnable_u8;
	uint8 AllFieldEnable_u8;
	uint8 FIXDISPLAY_1_GEAR_ENABLE_u8;
	uint8 FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE_u8;
	uint8 DISPLAY_6_GEAR_ENABLE_u8;
	uint8 DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE_u8;
	uint8 Center_Speaker;
	uint8 CAN_MESSAGE_USE_FD;
}s_ChimeConfigData_t;   

typedef enum 
{
    ShowPeriod_First = 0,
    ShowPeriod_Diff,
    ShowPeriod_Cycle,
    ShowPeriod_Sheild,
    ShowPeriod_AutoShield,
    ShowPeriod_Showed,
    ShowPeriod_None
}Enum_ShowPeriod_t;

#define CHIME_OSTM_TIMER_CLEAR 					(0u)
#define CHIME_OSTM_TIMER_OVER					(2u)
#define CHIME_OSTM_TIMER_RUNING					(4u)
#define CHIME_OSTM_TIMER_PENNDING				(8u)
#define CHIME_OSTM_TIMER_START_ERROR			(16u)
#define CHIME_OSTM_TIMER_MAX_COUNTER			(0xffffffffu)

#define CHIME_NVM_BLOCK_ALL						(255u)
//#define CHIME_RUNABLE_TIME_TEST

#ifdef CHIME_RUNABLE_TIME_TEST

typedef struct 
{
	uint32 ChimeRunableTimerTest_MAX;
	uint32 ChimeRunableTimerTest_MIN;
	uint32 ChimeRunableTimerTest_AVG;
	uint32 ChimeRunableTimerTest_Index;
	uint64 ChimeRunableTimerTest_Alltime;
	uint32 ChimeRunableTimerTest_MAXRunTime;
	uint32 ChimeRunableTimerTest_AVGRunTime;
	uint32 ChimeRunableTimerTest_IndexRunTime;
	uint32 ChimeRunableTimerTest_OverTimeTick;
	uint64 ChimeRunableTimerTest_AlltimeRunTime;
}s_ChimeRunableTimerTest_t;


#define CHIME_RUNABLE_TIME_TEST_START RTE_RUNNABLE_TM_TimerStartStamp
#define CHIME_RUNABLE_TIME_TEST_PASS RTE_RUNNABLE_TM_TimerElapsed

#endif
/**********************************************************************************************************
*Function   : Na                                                                                          *
*                                                                                                         *
*Description: RTE Message adapt                                                                           *
*                                                                                                         *
*Parameter  :                                                                                             *
*                                                                                                         *
*Return     :                                                                                             *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-01-30                                                                                  *
**********************************************************************************************************/
ChimeMessageType Chime_GetMessage_PASWorkCmd(uint8 *data);
ChimeMessageType Chime_GetMessage_RPAS_SoundIndcn(uint8 *data);
ChimeMessageType Chime_GetMessage_RPAS_WorkSts(uint8 *data);
ChimeMessageType Chime_GetMessage_RPAS_SoundIndcn_FD(uint8 *data);
ChimeMessageType Chime_GetMessage_RPAS_WorkSts_FD(uint8 *data);
ChimeMessageType Chime_GetMessage_FPAS_SoundIndcn(uint8 *data);
ChimeMessageType Chime_GetMessage_FPAS_WorkSts(uint8 *data);
ChimeMessageType Chime_GetMessage_FPAS_SoundIndcn_FD(uint8 *data);
ChimeMessageType Chime_GetMessage_FPAS_WorkSts_FD(uint8 *data);
ChimeMessageType Chime_GetMessage_SDWActiveSts(uint8 *data);
ChimeMessageType Chime_GetMessage_APS_FRSideSnsrFailSts(uint8 *data);
ChimeMessageType Chime_GetMessage_APS_FLSideSnsrFailSts(uint8 *data);
ChimeMessageType Chime_GetMessage_APS_RLSideSnsrFailSts(uint8 *data);
ChimeMessageType Chime_GetMessage_APS_RRSideSnsrFailSts(uint8 *data);
ChimeMessageType Chime_GetMessage_SDW_SoundIndcn(uint8 *data);
ChimeMessageType Chime_GetMessage_APS_SysSoundIndcn(uint8 *data);
ChimeMessageType Chime_GetMessage_RSDS_IPSoundReq(uint8 *data);
ChimeMessageType Chime_GetMessage_BSD_LCA_warningReqRight(uint8 *data);
ChimeMessageType Chime_GetMessage_BSD_LCA_warningReqleft(uint8 *data);
ChimeMessageType Chime_GetMessage_RCTA_warningReqRight(uint8 *data);
ChimeMessageType Chime_GetMessage_RCTA_warningReqLeft(uint8 *data);
ChimeMessageType Chime_GetMessage_DOW_warningReqRight(uint8 *data);
ChimeMessageType Chime_GetMessage_DOW_warningReqleft(uint8 *data);
ChimeMessageType Chime_GetMessage_DrvDoorSts(uint8 *data);
ChimeMessageType Chime_GetMessage_PassengerDoorSts(uint8 *data);
ChimeMessageType Chime_GetMessage_LRDoorSts(uint8 *data);
ChimeMessageType Chime_GetMessage_RRDoorSts(uint8 *data);
ChimeMessageType Chime_GetMessage_LSSIntervention(uint8 *data);
ChimeMessageType Chime_GetMessage_CDPActv_0x137(uint8 *data);
ChimeMessageType Chime_GetMessage_CDPActv_0x145(uint8 *data);
ChimeMessageType Chime_GetMessage_LTurnLmpSts_R_Pbox(uint8 *data);
ChimeMessageType Chime_GetMessage_RTurnLmpSts_R_Pbox(uint8 *data);
ChimeMessageType Chime_GetMessage_TSRSts(uint8 *data);
ChimeMessageType Chime_GetMessage_TSRSpdLimSts(uint8 *data);
ChimeMessageType Chime_GetMessage_TSRSpdLim(uint8 *data);
ChimeMessageType Chime_GetMessage_TSRSpdLimWarn(uint8 *data);
ChimeMessageType Chime_GetMessage_FrntELDLckSts(uint8 *data);
ChimeMessageType Chime_GetMessage_RearELDLckSts(uint8 *data);
ChimeMessageType Chime_GetMessage_TGS_LEVER(uint8 *data);
ChimeMessageType Chime_GetMessage_HCU_RdyLmpSts(uint8 *data);
ChimeMessageType Chime_GetMessage_DrvModDisp_0x201(uint8 *data);
ChimeMessageType Chime_GetMessage_HWA_ModDisp(uint8 *data);
ChimeMessageType Chime_GetMessage_OBC_ConnectSts(uint8 *data);
ChimeMessageType Chime_GetMessage_HCU_ChargSts(uint8 *data);
ChimeMessageType Chime_GetMessage_LCKStsIndcr(uint8 *data);
ChimeMessageType Chime_GetMessage_IntelligentEvaActSts(uint8 *data);
ChimeMessageType Chime_GetMessage_LDW_LKAWarn(uint8 *data);
ChimeMessageType Chime_GetMessage_DWD_SoundIndcn(uint8 *data);
ChimeMessageType Chime_GetMessage_TOD1_SystemOperMod(uint8 *data);
ChimeMessageType Chime_GetInterface_SpeedoInfo_Element(uint16 *data);
ChimeMessageType Chime_GetInterface_WarningStsDoor(uint16 *data,uint16 bit);
ChimeMessageType Chime_GetInterface_SelfCheck_Element(uint8 *data);
ChimeMessageType Chime_GetInterface_TC_NE_ChargStsOutput_Element(uint8 *data);//R15 add



/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*Function   : Chime_RteAdaptInit                                                                          *
*                                                                                                         *
*Description: Chime adapt init function,always for init paramenter                                        *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptInit(void);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint16 Chime_RteAdaptGetPower(void);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint16 Chime_RteAdaptGetVoltage(void);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_RteAdaptGetVconfig(uint8 id_u8);

/**********************************************************************************************************
*Function   : Chime_RteAdaptGetAllConfig                                                                  *
*                                                                                                         *
*Description: Chime get location configuration function                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptGetAllConfig(void);

/**********************************************************************************************************
*Function   : Chime_RteAdaptGetLconfig                                                                    *
*                                                                                                         *
*Description: Chime get location configuration function                                                   *
*                                                                                                         *
*Parameter  : id_u8 : configuration id                                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint32 Chime_RteAdaptGetLconfig(uint8 id_u8);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptOstmStart(uint8 index);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint32 Chime_RteAdaptOstmCheck(uint8 index);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptOstmStop(uint8 index);

/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerPass                                                                     *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_RteAdaptTimerPass(s_ChimeOstmData_t *timer,uint32 pass);
/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerSet                                                                      *
*                                                                                                         *
*Description: app timer start function                                                                    *
*                                                                                                         *
*Parameter  : timer : timer ptr ,overTime : over timer                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerSet(s_ChimeOstmData_t *timer,uint32 overTime);
/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerClr                                                                      *
*                                                                                                         *
*Description: app timer clear  function                                                                   *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerClr(s_ChimeOstmData_t *timer);
/**********************************************************************************************************
*Function   : Chime_RteAdaptTimerClr                                                                      *
*                                                                                                         *
*Description: app timer clear  function                                                                   *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_RteAdaptTimerPending(s_ChimeOstmData_t *timer);

/**********************************************************************************************************
*Function   : NW_SIL_TX_Chime_DATA                                                                        *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void NW_SIL_TX_Chime_DATA(e_ChimeIPCCommand_t data);

/**********************************************************************************************************
*Function   : Chime_RteChimeSocReady                                                                      *
*                                                                                                         *
*Description: Chime soc ready flag，After this chime will request chime                                    *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_RteChimeSocReady(void);

/**********************************************************************************************************
*Function   : Chime_Api_HMIPowerCallback                                                                  *
*                                                                                                         *
*Description: HMIPower callback get data                                                                  *
*                                                                                                         *
*Parameter  : data : Power Status                                                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-03-27                                                                                  *
**********************************************************************************************************/
void Chime_Api_HMIPowerCallback(uint8 *data);

/**********************************************************************************************************
*Function   : Chime_Api_ChimeCallback                                                                     *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_ChimeCallback(uint8 *data);
/**********************************************************************************************************
*Function   : Chime_Api_WrCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_WrCallback(uint8 *data);
/**********************************************************************************************************
*Function   : Chime_Api_TTCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_TTCallback(uint8 *data);

/**********************************************************************************************************
*Function   : ChimeCopyCallbackData                                                                       *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void ChimeCopyCallbackData(void);
/**********************************************************************************************************
*Function   : Chime_Api_TTCallback                                                                        *
*                                                                                                         *
*Description: Chime callback get data                                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_CallbackTask(void);

/**********************************************************************************************************
*Function   : Chime_Api_Callback_Set                                                                      *
*                                                                                                         *
*Description: Chime callback api,call by IPC callback                                                     *
*                                                                                                         *
*Parameter  : data_u8  ：Receive data first address                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_Callback_Set(s_IPCChimeCallback_t data_s);

/**********************************************************************************************************
*Function   : ChimeWarningCheck                                                                           *
*                                                                                                         *
*Description: Chime Warning with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void ChimeWarningCheck(s_IPCWrnCallback_t back);

/**********************************************************************************************************
*Function   : ChimeWarningCheck                                                                           *
*                                                                                                         *
*Description: Chime Warning with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void ChimeTelltaleCheck(s_IPCTTCallback_t led);

/**********************************************************************************************************
*Function   : ChimeAdasCheck                                                                              *
*                                                                                                         *
*Description: Chime Adas    with  sound request                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2021-1-5                                                                                    *
**********************************************************************************************************/
void ChimeAdasCheck(s_IPCAdasCallback_t adas);

#ifdef CHIME_RUNABLE_TIME_TEST

void Chime_RteAdaptRunableOstmStart(uint8 index);
void Chime_RteAdaptRunableOstmCheck(uint8 index);

#endif

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/08/10     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

