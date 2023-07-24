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
 * @file:      SOCManager_RI.h
 * @author:    Nobo
 * @date:      2020-7-2
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-2
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SOC_MANAGE_RI_H_
#define _SOC_MANAGE_RI_H_

#include "VariantCfg.h"

#define SOC_MANAGE_TASK_PERIOD          (100u)

#include "SOCManager_IPC_Service.h"
#include "SOCManager_Type.h"
#include "Ext_Power.h"
#include "Ipc_If.h"
#ifdef PLATFORM_OF_STB_IPC_USED
#include "Ipc_STB_If.h"
#endif
#include "IPC_POWER.h"




#  ifndef SYSTEMSTATE_SP_OFF
#   define SYSTEMSTATE_SP_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_SP_STANDBY
#   define SYSTEMSTATE_SP_STANDBY (2U)
#  endif

#  ifndef SYSTEMSTATE_SP_SOCOFF
#   define SYSTEMSTATE_SP_SOCOFF (3U)
#  endif


// debug
#define socmanager_Verbose(...)     Logger_String(LOGGER_MODULE_SOCM, LOGGER_LEVEL_VERBOSE, __VA_ARGS__)
#define socmanager_debug(...)       Logger_String(LOGGER_MODULE_SOCM, LOGGER_LEVEL_DEBUG, __VA_ARGS__)
#define socmanager_info(...)        Logger_String(LOGGER_MODULE_SOCM, LOGGER_LEVEL_INFO, __VA_ARGS__)
#define socmanager_warn(...)        Logger_String(LOGGER_MODULE_SOCM, LOGGER_LEVEL_WARN, __VA_ARGS__)
#define socmanager_err(...)         Logger_String(LOGGER_MODULE_SOCM, LOGGER_LEVEL_ERR, __VA_ARGS__)

#define RI_SystemState_QnxCloseResponseFunc             SystemState_QnxCloseResponseFunc
extern void SystemState_QnxCloseResponseFunc(uint8 *param, uint16 param_len);

#define RI_SystemState_IVINOForceResponseFunc           SystemState_IVINOForceResponseFunc
extern void SystemState_IVINOForceResponseFunc(uint8 * param, uint16 param_len);

#define RI_SystemState_FOTAStsFunc           SystemState_FOTASts
extern void SystemState_FOTASts(uint8 * param, uint16 param_len);

#define RI_SystemState_GetFunc           SystemState_GetSMSts
extern void SystemState_GetSMSts(uint8 * param, uint16 param_len);

#define RI_SystemState_APP_INFOSM           SystemState_APP_INFOSM
extern void SystemState_APP_INFOSM(uint8 * param, uint16 param_len);


#define RI_DataSendFormHandshake                        IPC_DataSendFormHandshake

#ifdef PLATFORM_OF_STB_IPC_USED
#define RI_STB_DataSendFormHandshake                    IPC_M2S_DedicatedSocManagerHandshakeResponse_Transmit
#endif

#define RI_SetIPCStateType                              IPC_SetIPCStateType

#ifdef PLATFORM_OF_STB_IPC_USED
#define RI_STB_SetIPCStateType                          IPC_STB_SetIPC_STBStateType
#endif

#define RI_GetHwVersion                                 Misc_Board_GetHwVersion
extern Std_ReturnType Misc_Board_GetHwVersion(uint8 * ver);

#define RI_ReqSocPowerState                             EXT_Power_ReqSocPowerState

#define RI_ReqSocReset                                  EXT_Power_ReqSocReset

#define RI_ReadKeepDownloadRID                          Rte_Read_EOL_KeepDownload_keepDownloadRID

#define RI_ReadPmicState                                EXT_Power_ReadPmicState

#define RI_ReadSystemState(x)                           (*(x) = SystemState_SP_State,((Std_ReturnType)RTE_E_OK))
extern uint8 SystemState_SP_State;

#define RI_WriteSOCManagerState                         Rte_Write_ppSR_SocManager_SystemState

#define RI_AMP_Emergency_Shutdown                       AMP_Emergency_Shutdown
extern void AMP_Emergency_Shutdown(void);

#define RI_AMP_Init                                     AMP_Init
extern void AMP_Init(void);

#define RI_Request_PowerModeShutdownReq_requestedMode   Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode
Std_ReturnType Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(uint8 data); /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */


#define RI_WriteSocFactoryResetReady                    Rte_Write_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady

#define RI_POWERSocManagerVersion_Transmit              IPC_M2S_POWERSocManagerVersion_Transmit

#define RI_POWERSocManagerHeath_Receive                 IPC_S2M_POWERSocManagerHeath_Receive

#define RI_POWERSocManagerReset_Receive                 IPC_S2M_POWERSocManagerReset_Receive

#define RI_QnxInfoMCUSystem_Receive                     IPC_S2M_POWERSocManagerQnxInfoMCUSystem_Receive

#define RI_POWERSocManagerHealthSet_Receive             IPC_S2M_POWERSocManagerHealthset_Receive

#define RI_IPC_DeInit                                   IPC_DeInit

#define RI_IPC_Init                                     IPC_If_Init

#ifdef PLATFORM_OF_STB_IPC_USED
#define RI_IPC_STB_DeInit                               IPC_STB_DeInit

#define RI_IPC_STB_Init                                 IPC_STB_If_Init
#endif

#define RI_Read_Upgrade_flag                            Rte_Read_SOCManager_Rc_Upgrade_flag_Element

// #define RI_Read_Requset2MiniSystem                      Rte_Read_rpSR_System_Recovery_System_Recovery


// V35-14714 Output the reason why the SoC is started
#define RI_Write_Logger_IPC_ReadyStatus(x)              (Logger_IPC_SetReadyStatus(x),((Std_ReturnType)RTE_E_OK))
extern void Logger_IPC_SetReadyStatus(boolean status);

#define RI_Read_Logger_IPC_ReadyStatus(x)                ((*x) = Logger_IPC_ReadReadyStatus(),((Std_ReturnType)RTE_E_OK))

extern boolean Logger_IPC_ReadReadyStatus(void);

#define RI_Read_HeathFromSoc(x)                			 ((*x) = SOCManager_HeathMsg_Get(),((Std_ReturnType)RTE_E_OK))

extern uint8 SOCManager_HeathMsg_Get(void);


#ifdef GWM_V35_PROJECT_TYPE_B03
#define RI_ReadAdjVolDwnSwtSts                          Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts
#define RI_ReadAdjVolUpSwtSts                           Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts
#define RI_ReadCustomSwtSts                             Rte_Read_CustomSwtSts_CustomSwtSts
#define RI_ReadCustomSwtSts_Mmed                        Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed
#define RI_ReadEnterSwtSts                              Rte_Read_EnterSwtSts_EnterSwtSts
#define RI_ReadEnterSwtSts_Mmed                         Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed
#define RI_ReadHomeSwtSts                               Rte_Read_HomeSwtSts_HomeSwtSts
#define RI_ReadMenuReturnSwtSts                         Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts
#define RI_ReadMuteSwtSts                               Rte_Read_MuteSwtSts_MuteSwtSts
#define RI_ReadPageDwnSwtSts                            Rte_Read_PageDwnSwtSts_PageDwnSwtSts
#define RI_ReadPageLSwtSts                              Rte_Read_PageLSwtSts_PageLSwtSts
#define RI_ReadPageRSwtSts                              Rte_Read_PageRSwtSts_PageRSwtSts
#define RI_ReadPageUpSwtSts                             Rte_Read_PageUpSwtSts_PageUpSwtSts
#define RI_ReadSeekDwnSwtSts                            Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts
#define RI_ReadSeekUpSwtSts                             Rte_Read_SeekUpSwtSts_SeekUpSwtSts
#define RI_ReadVRSwtSts                                 Rte_Read_VRSwtSts_VRSwtSts
#else
#define RI_ReceiveSignal                                Rte_Call_ComEx_ReceiveSignal

#endif
                
#define RI_ReadDrvGearDisp                              Rte_Read_rpSR_SOCManager_DrvGearDisp_Element 
#define RI_ReadGearMsgMiss                              Rte_Read_rpSR_SOCManager_GearMsgMiss_Element 
#define RI_ReadSpeedoInfo                               Rte_Read_rpSR_SOCManager_SpeedoInfo_Element
#define RI_ReadTachoInfo                                Rte_Read_rpSR_SOCManager_TachoInfo_Element



#endif /* ifndef _SOC_MANAGE_RI_H_.2020-7-2 15:17:21 GW00188879 */
