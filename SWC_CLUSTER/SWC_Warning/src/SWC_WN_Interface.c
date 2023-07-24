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

/**********************************************************************************************************
*File Name   : WN_Interface.c                                                                             *
*                                                                                                         *
*Description : Warning module application interface source file.                                          *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "IPC_ClusterApp.h"
#include "Rte_Common_Normal.h"
#include "SWC_IPC_Application.h"
#include "SWC_Chime_Adapt.h"
#include "VConfig.h"
#include "CConfig_Cfg.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_WN_Config.h"
#include "SWC_WN_Core.h"
#include "SWC_WN_Interface.h"
#include "SWC_WN_Adapt.h"
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Warning Attribute Table                                                                               *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/

#define SWC_WN_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_WN_MemMap.h"

static WN_CFG_tstWarningAttribute WN__cstWarningAttribute[WN_enWARNING_TOTAL_NUMBER] = WN_CFG_WARNING_CONTROL_ATTRIBUTE;

#define SWC_WN_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Warning Main Object Structure Variable                                                                *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
#define SWC_WN_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"

static WN_CFG_tstMAIN_OBJECT WN__stMainObject ;

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Logic Process Attribute Table Const                                                                   *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/

static IPC_M2S_ClusterAppAPPWN_Module_t ToSBUS_WN_status32 = {0};

//static IPC_M2S_ClusterAppAPPWN_Module_t ToSBUS_WN_status32_pre;

#define SWC_WN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"

#define SWC_WN_START_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"

static const WN_CFG_tstLogicProcessAttribute WN__cstLogicProcessAttribute[] = {
                                    WN_CFG_LOGIC_PROCESS_ATTRIBUTE
                                    {WN_DO_NOTHING,(WN_CFG_enLogicProcessMode)WN_NULL}};

#define SWC_WN_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"


/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Warning Common Static Function                                                                        *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"

static boolean WN__boCheckPowerMode(void);

static void WN__vPowerModeErrorProcess(void);

static boolean WN__boCheckExternalControl(void);

static boolean WN__boCheckResponseDelayStatus(void);

static boolean WN__boTimeTaskLogicProcess(void);

static boolean WN__boWarningControlProcess(void);

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)

static void WN__vCANOutputUpdateMessage(void);

static boolean WN__boCANOutputTaskOperation(void);

#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)

static void WN__vSBUSUpdateMessage(void);

static boolean WN__boSBUSTaskOperation(void);


#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)

static void WN__vSetAllWarningToDefault(void);

static void WN__vSystemErrorObjectOperationProcess(void);

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Warning Custom Static Function                                                                        *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/

//None


/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Warning Process Map                                                                                   *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/

/*************************************************************************************************************************************************************************************************************/
/*ProcessName               Process                                SucceedEnable      FaildEnable           AfterSucceed    AfterFaild                   ContinueWhen
                                                                   Status             Status                Operation       Operation                    Faild       */
#define SWC_WN_START_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"

static const WN_tstPROCESS WN_stTimeTask_ProcessTable[] = {
/*Power Mode */           { WN__boCheckPowerMode ,                 WN_KEEP_PREVIOUS , WN_POWER_MODE_ERROR , WN_DO_NOTHING , WN__vPowerModeErrorProcess , WN_CFG_OFF          },
/*External Control */     { WN__boCheckExternalControl ,           WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
/*Response Delay */       { WN__boCheckResponseDelayStatus ,       WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
/*Logic Process*/         { WN__boTimeTaskLogicProcess ,           WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
/*Warning Control*/       { WN__boWarningControlProcess ,          WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
/*CAN Output Operation*/  { WN__boCANOutputTaskOperation ,         WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
#endif
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
/*SBUS Operation*/        { WN__boSBUSTaskOperation ,              WN_KEEP_PREVIOUS , WN_KEEP_PREVIOUS ,    WN_DO_NOTHING , WN_DO_NOTHING ,              WN_CFG_ON           },
#endif
                          { (void *)0,(WN_CFG_enSYSTEM_STATUS)0,(WN_CFG_enSYSTEM_STATUS)0,(void *)0,(void *)0,WN_CFG_OFF},\
                          };

#define SWC_WN_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_WN_MemMap.h"

/*************************************************************************************************************************************************************************************************************/

/**********************************************************************************************************
*Function   : WN_API_vKSTimeTask                                                                          *
*                                                                                                         *
*Description: The functions is called by DI-kernel at slow rate task list at cycle 40ms.                  *
*             which is the main handling task of Warning module at different working mode                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"

void WN_API_vKSTimeTask(void)
{
#if (WN_CFG_WARNING_FUNCTION == TRUE)
	WN_GetAllConfiguration();
    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        WN_CORE_vProcessControl((void *)WN_stTimeTask_ProcessTable,&WN__stMainObject);
    }
    else
    {
        WN__vSystemErrorObjectOperationProcess();
    }

	WN__vTimeTaskLoopRollingCount(&WN__stMainObject);
#endif //(WN_CFG_Warning_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSRoundRobin_Task                                                                   *
*                                                                                                         *
*Description: The function is called by DI-kernel at round-robin task list. if it used,can fill  it with  *
*             code.                                                                                       *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSRoundRobinTask(void)
{
#if(WN_CFG_WARNING_FUNCTION == TRUE)

#endif //(WN_CFG_Warning_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSColdInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at cold init task list,which do global variables        *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSColdInit(void)
{
    VconfigKind_Allbuffers VehCfg;
    CconfigKind_400Bytes LocalCfg;
    uint16 Tpms_delay = 0;                         //uint: 0.1s
    //Byte30 Bit7-bit4
    //uint8 configElecPosition = 0;
    //Byte4 Bit5-bit2
    uint8 configRegional = 0xFF;
    if (E_OK == Rte_Read_Vconfig_GetKindBuffers_AllKinds(VehCfg))
    {
        if (VehCfg[VCONFIG_KIND_INIT_FLAG] != 0)
        {
            configRegional = VehCfg[VCONFIG_KIND_REGIONAL];
            if (configRegional == 3)
            {
                WN__cstWarningAttribute[WN_enFirRowLSeatBelt].u16IgnOnResponseDelayTime = 0;
                WN__cstWarningAttribute[WN_enFirRowRSeatBelt].u16IgnOnResponseDelayTime = 0;
                WN__cstWarningAttribute[WN_enSecRowLSeatBelt].u16IgnOnResponseDelayTime = 0;
                WN__cstWarningAttribute[WN_enSecRowMSeatBelt].u16IgnOnResponseDelayTime = 0;
                WN__cstWarningAttribute[WN_enSecRowRSeatBelt].u16IgnOnResponseDelayTime = 0;
            }
            if (E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(LocalCfg))
            {
                Tpms_delay = (uint16)CConfig_GetConfig(CCONFIG_KIND_Tpms_delay, LocalCfg);
                Tpms_delay = (uint16)(Tpms_delay * 100u); //uint: ms
                WN__cstWarningAttribute[WN_enFLTirePressWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enFRTirePressWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enRLTirePressWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enRRTirePressWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enFLTireTempWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enFRTireTempWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enRLTireTempWarning].u16IgnOnResponseDelayTime = Tpms_delay;
                WN__cstWarningAttribute[WN_enRRTireTempWarning].u16IgnOnResponseDelayTime = Tpms_delay;
            }
        }
    }
    //Avoid Warning
    WN_CORE_vSetSystemErrorStatus(WN_SYSTEM_DEFAULT,&WN__stMainObject);

    WN_CORE_vClearSystemErrorStatus(WN_SYSTEM_DEFAULT,&WN__stMainObject);

    (void)WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_DEFAULT,&WN__stMainObject);

#if (WN_CFG_WARNING_FUNCTION == TRUE)
#if(WN_CFG_DEBUG == TRUE)
printf("\
------------------------------------------------------------\r\n\
--Warning Module Debug Mode Enable-------------------------\r\n\
------------------------------------------------------------\r\n");

    WN_CORE_vCheckModuleConfigration();

    WN_CORE_vDebugModeOperation(&WN__stMainObject);

#endif

    WN_CORE_vCalculateDelayTimerMaxCount(&WN__cstWarningAttribute[0],&WN__stMainObject);

    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        /*Set Flag*/
        WN_CORE_vFlagControl(WN_COLD_INIT,&WN__stMainObject);

#if (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

        WN_CFG_INIT_TIMER();

#endif //(WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

        /*Set Timer default value*/
        WN__stMainObject.stTimer.u16IgnitionOnResponseDelayTick = WN__stMainObject.stCount.u16IgnitionOnResponseDelayMaxTickCount;
        WN__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = WN__stMainObject.stCount.u16ExitAbnormalResponseDelayMaxTickCount;

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
        /*Send CAN message*/
        WN__vCANOutputUpdateMessage();
#endif

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
        /*Send SBUS message*/
        WN__vSBUSUpdateMessage();
#endif

    }
    else //System faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSWarmInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at warm init task list,which do global variables        *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSWarmInit(void)
{
#if (WN_CFG_WARNING_FUNCTION == TRUE)

#if(WN_CFG_DEBUG == TRUE)

    WN_CORE_vDebugModeOperation(&WN__stMainObject);

#endif

    WN_CORE_vCalculateDelayTimerMaxCount(&WN__cstWarningAttribute[0],&WN__stMainObject);

    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        /*Set Flag*/
        WN_CORE_vFlagControl(WN_WARM_INIT,&WN__stMainObject);

#if (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

        WN_CFG_INIT_TIMER();

#endif //(WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

        /*Set Timer default value*/
        WN__stMainObject.stTimer.u16IgnitionOnResponseDelayTick = WN__stMainObject.stCount.u16IgnitionOnResponseDelayMaxTickCount;
        WN__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = WN__stMainObject.stCount.u16ExitAbnormalResponseDelayMaxTickCount;

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
        /*Send CAN message*/
        WN__vCANOutputUpdateMessage();
#endif

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
        /*Send SBUS message*/
        WN__vSBUSUpdateMessage();
#endif

    }
    else //System faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSWakeUp                                                                            *
*                                                                                                         *
*Description: The function is called by DI-kernel at wake up task list,which do global variables          *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-12-20                                                                                  *
**********************************************************************************************************/
void WN_API_vKSWakeUp(void)
{
#if(WN_CFG_WARNING_FUNCTION == TRUE)
    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        /*Set Flag*/
        WN_CORE_vFlagControl(WN_WAKE_UP,&WN__stMainObject);

    }
    else //System faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSSleep                                                                             *
*                                                                                                         *
*Description: The function is called by DI-kernel at sleep task list,which do global variables            *
*             initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-12-20                                                                                  *
**********************************************************************************************************/
void WN_API_vKSSleep(void)
{
#if(WN_CFG_WARNING_FUNCTION == TRUE)
    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        /*Set Flag*/
        WN_CORE_vFlagControl(WN_SLEEP,&WN__stMainObject);

    }
    else //System faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSEnterAbnormalOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSEnterAbnormalOperation(void)
{
#if(WN_CFG_WARNING_FUNCTION == TRUE)
    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        //Function flag control
        WN_CORE_vFlagControl(WN_ENTER_ABNORMAL,&WN__stMainObject);

    }
    else //System Faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vKSExitAbnormalOperation                                                             *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when MCU exits the        *
*             abnormal mode                                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vKSExitAbnormalOperation(void)
{
#if(WN_CFG_WARNING_FUNCTION == TRUE)
    if(FALSE == WN_CORE_boCheckSystemErrorStatus(WN_SYSTEM_FAILD,&WN__stMainObject))
    {
        //Function flag control
        WN_CORE_vFlagControl(WN_EXIT_ABNORMAL,&WN__stMainObject);
        /*Clear time tick*/
        WN__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = 0;
    }
    else //System Faild,do nothing
    {

    }
#endif //(WN_CFG_WARNING_FUNCTION == TRUE)
}
/**********************************************************************************************************
*Function   : WN_API_vSingleWarningControl                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vSingleWarningControl(void* vptrWarningLogicOperation,uint8 u8WarningID)
{
    /*Check EOL or diagnostic work enable state*/
    if(u8WarningID < (uint8)WN_enWARNING_TOTAL_NUMBER)
    {
        WN_CORE_vSingleLogicProcess(vptrWarningLogicOperation,&WN__cstLogicProcessAttribute[0],&WN__stMainObject);

        WN_CORE_vSingleWarningControl(&WN__stMainObject.stWarningControlStatus[u8WarningID],&WN__cstWarningAttribute[u8WarningID],&WN__stMainObject);
    }
    else
    {
        /*Do nothing because request warning ID out of bound */
    }
}
/**********************************************************************************************************
*Function   : WN_API_vSetWarningStatus                                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
void WN_API_vSetWarningStatus(WN_CFG_enWarningID warningID, uint8 warningStatus)
{
    if(warningID < WN_enWARNING_TOTAL_NUMBER)
    {
       WN_CFG_vSetWarningStatus(warningID, warningStatus, &WN__stMainObject);
    }
    else
    {
        /*Do nothing because request warning ID or set logic status index out of bound */
    }
}
/**********************************************************************************************************
*Function   : WN_API_u8GetWarningStatus                                                                   *
*                                                                                                         *
*Description: The function is used to get current warning status                                          *
*                                                                                                         *
*Parameter  : Warning ID                                                                                  *
*                                                                                                         *
*Return     : Warning status type                                                                         *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
uint8 WN_API_u8GetWarningStatus(WN_CFG_enWarningID warningID)
{
    uint8 warningStatus;

    if(warningID < (WN_enWARNING_TOTAL_NUMBER))
    {
        warningStatus = WN__stMainObject.stWarningControlStatus[warningID].unStatus.stStatus.ResultLogicType;
    }
    else
    {
        /*Return default value because request warning ID out of bound */
        warningStatus = (uint8)WN_enDISPLAY_OFF;
    }

    if(WN_CFG_POWER_STATE_IS_ABNORMAL_VOLTAGE)
    {
        /*Return default value because request warning ID out of bound */
        warningStatus = (uint8)WN_enDISPLAY_OFF;
    }
    else
    {
        ;
    }

    return warningStatus;
}
/**********************************************************************************************************
*Function   : WN__boCheckPowerMode                                                                        *
*                                                                                                         *
*Description: The function is used to check power mode which status can warning work .                    *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : Process return status . If power mode get faild , retuen FALSE .                            *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static boolean WN__boCheckPowerMode(void)
{
    boolean boReturn = FALSE;
    uint32 u32WNPowerModeStatus = 0;
    SystemState_RecordType SystemState_RecordType_Tmp = {0};
    (void)memcpy(&SystemState_RecordType_Tmp,Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
    if((VOLTAGE_OUT_NORMAL == SystemState_RecordType_Tmp.s_PowerVoltage.state) ||
       (VOLTAGE_OUT_LOWALARM == SystemState_RecordType_Tmp.s_PowerVoltage.state)||
       (VOLTAGE_OUT_HIGHALARM == SystemState_RecordType_Tmp.s_PowerVoltage.state))
    {
        if (SYSTEMSTATE_Cluster_ON == SystemState_RecordType_Tmp.ClusterState)
        {
            u32WNPowerModeStatus |= (uint32)WN_enRUN;
        }
        else if(SYSTEMSTATE_Cluster_STANDBY == SystemState_RecordType_Tmp.ClusterState)
        {
            u32WNPowerModeStatus |= (uint32)WN_enOFF;
        }
        else if((SYSTEMSTATE_Cluster_SHUTDOWN == SystemState_RecordType_Tmp.ClusterState) ||
                (SYSTEMSTATE_Cluster_OFF == SystemState_RecordType_Tmp.ClusterState))
        {
            u32WNPowerModeStatus |= (uint32)WN_enSLEEP;
        }
        else{}
    }
    else
    {
        u32WNPowerModeStatus |= (uint32)WN_enABNORMAL_VOLTAGE;
    }
    if(((uint32)WN_enNULL_POWER_MODE == u32WNPowerModeStatus) ||
       ((uint32)WN_enABNORMAL_VOLTAGE == u32WNPowerModeStatus))
    {
        /*Already get at least one status,so set return to TRUE*/
        boReturn = FALSE;
    }
    else
    {
        boReturn = TRUE;
    }
    /*Save current power mode status*/
    WN__stMainObject.unPowerModeStatus.u32PowerModeStatus = u32WNPowerModeStatus;

    return boReturn;
}
/**********************************************************************************************************
*Function   : WN__vPowerModeErrorProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static void WN__vPowerModeErrorProcess(void)
{
    (void)memset(&ToSBUS_WN_status32, 0, sizeof(ToSBUS_WN_status32));
    //send warning status to output
    (void)Rte_Write_ppSR_SWCNormal_WarningStsOutput_Element((const WN_WarningStsOutput *)&ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t);
    //send ToSBUS_WN_status32 to SOC
    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_WARNING,(uint8 *)&ToSBUS_WN_status32,(uint16)sizeof(IPC_M2S_ClusterAppAPPWN_Module_t),FALSE);
}
/**********************************************************************************************************
*Function   : WN__boCheckExternalControl                                                                  *
*                                                                                                         *
*Description: The function is used to check external control which status can warning work .             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : Process return status . If power mode get faild , retuen FALSE .                            *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static boolean WN__boCheckExternalControl(void)
{
    //uint16 u8Index;
#if 0
    if(WN_CFG_DIAGNOSIS_MODE_ENABLE||WN_CFG_EOL_MODE_ENABLE)
    {
        for (u8Index = 0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
        {
            WN_CORE_vWarningExternalControlEnable((WN_CFG_enWarningID)u8Index,&WN__stMainObject);
        }
    }
    else
    {
        for (u8Index = 0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
        {
            WN_CORE_vWarningExternalControlDisable((WN_CFG_enWarningID)u8Index,&WN__stMainObject);
        }
    }
#endif
    return TRUE;
}
/**********************************************************************************************************
*Function   : WN__boCheckResponseDelayStatus                                                              *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static boolean WN__boCheckResponseDelayStatus(void)
{
    /*Job define in core file*/
    //Byte4 Bit5-bit2
    uint8 configRegional = 0;

    configRegional = (uint8)WN_GetSingleConfig(WN_enCfg_Regional);

    WN_CORE_vCheckResponseDelayStatus(&WN__cstWarningAttribute[0], &WN__stMainObject);
    if (configRegional == 3)
    {
        if (((uint8)WN_enDISPLAY_ON == WN_API_u8GetWarningStatus(WN_enFirRowLSeatBelt)) ||
            ((uint8)WN_enDISPLAY_ON == WN_API_u8GetWarningStatus(WN_enFirRowRSeatBelt)) ||
            ((uint8)WN_enDISPLAY_ON == WN_API_u8GetWarningStatus(WN_enSecRowLSeatBelt)) ||
            ((uint8)WN_enDISPLAY_ON == WN_API_u8GetWarningStatus(WN_enSecRowMSeatBelt)) ||
            ((uint8)WN_enDISPLAY_ON == WN_API_u8GetWarningStatus(WN_enSecRowRSeatBelt)))
        {
            WN__stMainObject.stWarningControlStatus[WN_enLFDoorOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            WN__stMainObject.stWarningControlStatus[WN_enRFDoorOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            WN__stMainObject.stWarningControlStatus[WN_enLRDoorOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            WN__stMainObject.stWarningControlStatus[WN_enRRDoorOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            WN__stMainObject.stWarningControlStatus[WN_enTrunkOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
            WN__stMainObject.stWarningControlStatus[WN_enHoodOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
			WN__stMainObject.stWarningControlStatus[WN_enOneTrunkBoardOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
			WN__stMainObject.stWarningControlStatus[WN_enSplitTrunkBoardOpen].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
		}
        else
        {
        }
    }

    return TRUE;
}
/**********************************************************************************************************
*Function   : WN__boTimeTaskLogicProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static boolean WN__boTimeTaskLogicProcess(void)
{
    WN_CORE_vWarningTableLogicProcess(WN_enTIME_TASK,&WN__cstLogicProcessAttribute[0],&WN__stMainObject);

    return TRUE;
}
/**********************************************************************************************************
*Function   : WN__boWarningLightControlProcess                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-04-12                                                                                  *
**********************************************************************************************************/
static boolean WN__boWarningControlProcess(void)
{
    uint16 u8Index = 0;

    for(u8Index=0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
    {
        WN_CORE_vSingleWarningControl(&WN__stMainObject.stWarningControlStatus[u8Index],&WN__cstWarningAttribute[u8Index],&WN__stMainObject);
    }

    return TRUE;
}
/**********************************************************************************************************
*Function   : WN__vCANOutputUpdateMessage                                                                 *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-01-16                                                                                  *
**********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
static void WN__vCANOutputUpdateMessage(void)
{
    WN__stMainObject.u32CANMessage = 0;


    /*WN_CFG_SEND_WARNING_STATUS_CAN_MSG(WN__stMainObject.u32CANMessage);*/
}
#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
/**********************************************************************************************************
*Function   : WN__boCANOutputTaskOperation                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : BOOL                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-01-16                                                                                  *
**********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
static boolean WN__boCANOutputTaskOperation(void)
{
    /*Check update flag*/
    if(WN__stMainObject.unFunctionFlag.stFuncFlag.CANUpdateFlag)
    {
        WN__vCANOutputUpdateMessage();

        WN__stMainObject.unFunctionFlag.stFuncFlag.CANUpdateFlag = 0;
    }
    else
    {

    }

    return TRUE;
}
#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
/**********************************************************************************************************
*Function   : WN__vSBUSUpdateMessage                                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-01-16                                                                                  *
**********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
static void WN__vSBUSUpdateMessage(void)
{
    //Special alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvAwayCar = WN_API_u8GetWarningStatus(WN_enDrvAwayCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvAwayCarStop = WN_API_u8GetWarningStatus(WN_enDrvAwayCarStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCESSTrig = WN_API_u8GetWarningStatus(WN_enIFCESSTrig);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCAESTrig = WN_API_u8GetWarningStatus(WN_enIFCAESTrig);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBTrigP = WN_API_u8GetWarningStatus(WN_enAEBTrigP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBTrigV = WN_API_u8GetWarningStatus(WN_enAEBTrigV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IASTrigV = WN_API_u8GetWarningStatus(WN_enIASTrigV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FCTABrakeActive = WN_API_u8GetWarningStatus(WN_enFCTABrakeActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RSDSRLBStart = WN_API_u8GetWarningStatus(WN_enRSDSRLBStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCTakeOverBrake = WN_API_u8GetWarningStatus(WN_enACCTakeOverBrake);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBFCWWarning = WN_API_u8GetWarningStatus(WN_enAEBFCWWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FCTABrakePlease = WN_API_u8GetWarningStatus(WN_enFCTABrakePlease);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCHoldWheel_1Hz = WN_API_u8GetWarningStatus(WN_enIFCHoldWheel_1Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCHoldWheel_2Hz = WN_API_u8GetWarningStatus(WN_enIFCHoldWheel_2Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCHoldWheel_3Hz = WN_API_u8GetWarningStatus(WN_enIFCHoldWheel_3Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCHoldWheel_4Hz = WN_API_u8GetWarningStatus(WN_enIFCHoldWheel_4Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBSafeDistance = WN_API_u8GetWarningStatus(WN_enAEBSafeDistance);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeOver = WN_API_u8GetWarningStatus(WN_enACCHWATakeOver);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeOver_2Hz = WN_API_u8GetWarningStatus(WN_enACCHWATakeOver_2Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeOver_4Hz = WN_API_u8GetWarningStatus(WN_enACCHWATakeOver_4Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCTakeOver = WN_API_u8GetWarningStatus(WN_enIFCTakeOver);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeAtte = WN_API_u8GetWarningStatus(WN_enACCHWATakeAtte);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeAtte_2Hz = WN_API_u8GetWarningStatus(WN_enACCHWATakeAtte_2Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWATakeAtte_4Hz = WN_API_u8GetWarningStatus(WN_enACCHWATakeAtte_4Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GearPSelect = WN_API_u8GetWarningStatus(WN_enGearPSelect);

    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LFDoorOpen = WN_API_u8GetWarningStatus(WN_enLFDoorOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RFDoorOpen = WN_API_u8GetWarningStatus(WN_enRFDoorOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LRDoorOpen = WN_API_u8GetWarningStatus(WN_enLRDoorOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RRDoorOpen = WN_API_u8GetWarningStatus(WN_enRRDoorOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TrunkOpen = WN_API_u8GetWarningStatus(WN_enTrunkOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HoodOpen = WN_API_u8GetWarningStatus(WN_enHoodOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OneTrunkBoardOpen = WN_API_u8GetWarningStatus(WN_enOneTrunkBoardOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SplitTrunkBoardOpen = WN_API_u8GetWarningStatus(WN_enSplitTrunkBoardOpen);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FirRowLSeatBelt = WN_API_u8GetWarningStatus(WN_enFirRowLSeatBelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FirRowRSeatBelt = WN_API_u8GetWarningStatus(WN_enFirRowRSeatBelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SecRowLSeatBelt = WN_API_u8GetWarningStatus(WN_enSecRowLSeatBelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SecRowMSeatBelt = WN_API_u8GetWarningStatus(WN_enSecRowMSeatBelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SecRowRSeatBelt = WN_API_u8GetWarningStatus(WN_enSecRowRSeatBelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BrakeSysFault = WN_API_u8GetWarningStatus(WN_enBrakeSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynSysFault = WN_API_u8GetWarningStatus(WN_enDynSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed0 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed0);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed1 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed1);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed2 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed2);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed3 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed3);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed4 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed4);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed5 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed5);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed6 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed6);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed7 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed7);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CCOTargetSpeed8 = WN_API_u8GetWarningStatus(WN_enCCOTargetSpeed8);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed0 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed0);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed1 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed1);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed2 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed2);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed3 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed3);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed4 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed4);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed5 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed5);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed6 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed6);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed7 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed7);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowTargetSpeed8 = WN_API_u8GetWarningStatus(WN_enSlowTargetSpeed8);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCESSFault = WN_API_u8GetWarningStatus(WN_enIFCESSFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FLTirePressWarning = WN_API_u8GetWarningStatus(WN_enFLTirePressWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FRTirePressWarning = WN_API_u8GetWarningStatus(WN_enFRTirePressWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RLTirePressWarning = WN_API_u8GetWarningStatus(WN_enRLTirePressWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RRTirePressWarning = WN_API_u8GetWarningStatus(WN_enRRTirePressWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FLTireTempWarning = WN_API_u8GetWarningStatus(WN_enFLTireTempWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FRTireTempWarning = WN_API_u8GetWarningStatus(WN_enFRTireTempWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RLTireTempWarning = WN_API_u8GetWarningStatus(WN_enRLTireTempWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RRTireTempWarning = WN_API_u8GetWarningStatus(WN_enRRTireTempWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4WDSystemFault = WN_API_u8GetWarningStatus(WN_en4WDSystemFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4WDSystemHeat = WN_API_u8GetWarningStatus(WN_en4WDSystemHeat);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HybSysFault_Stop = WN_API_u8GetWarningStatus(WN_enHybSysFault_Stop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HybSysUnavailable = WN_API_u8GetWarningStatus(WN_enHybSysUnavailable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_Charging = WN_API_u8GetWarningStatus(WN_enCharging);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeWait = WN_API_u8GetWarningStatus(WN_enChargeWait);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeComplete = WN_API_u8GetWarningStatus(WN_enChargeComplete);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeStop = WN_API_u8GetWarningStatus(WN_enChargeStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattSysFault_Stop = WN_API_u8GetWarningStatus(WN_enDynBattSysFault_Stop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattSysFault_Repair = WN_API_u8GetWarningStatus(WN_enDynBattSysFault_Repair);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCAESFault = WN_API_u8GetWarningStatus(WN_enIFCAESFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransWarnStopCar = WN_API_u8GetWarningStatus(WN_enTransWarnStopCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerSysFault = WN_API_u8GetWarningStatus(WN_enPowerSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransFault = WN_API_u8GetWarningStatus(WN_enTransFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransPutInPFailed = WN_API_u8GetWarningStatus(WN_enTransPutInPFailed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LowOilPressure = WN_API_u8GetWarningStatus(WN_enLowOilPressure);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EngWaterTempHigh = WN_API_u8GetWarningStatus(WN_enEngWaterTempHigh);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransWarning = WN_API_u8GetWarningStatus(WN_enTransWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvSysFault_Repair = WN_API_u8GetWarningStatus(WN_enDrvSysFault_Repair);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HybSysFault_Repair = WN_API_u8GetWarningStatus(WN_enHybSysFault_Repair);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StartingSysFault = WN_API_u8GetWarningStatus(WN_enStartingSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HybSysLimited = WN_API_u8GetWarningStatus(WN_enHybSysLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RecoverySysFault = WN_API_u8GetWarningStatus(WN_enRecoverySysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargerFault = WN_API_u8GetWarningStatus(WN_enChargerFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeSysFault = WN_API_u8GetWarningStatus(WN_enChargeSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargerTempHigh = WN_API_u8GetWarningStatus(WN_enChargerTempHigh);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattTempHigh = WN_API_u8GetWarningStatus(WN_enDynBattTempHigh);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargerPWReduced = WN_API_u8GetWarningStatus(WN_enChargerPWReduced);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FCTAUnavai = WN_API_u8GetWarningStatus(WN_enFCTAUnavai);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LockFailureN = WN_API_u8GetWarningStatus(WN_enLockFailureN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoticeGearN = WN_API_u8GetWarningStatus(WN_enNoticeGearN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PositionLampOn = WN_API_u8GetWarningStatus(WN_enPositionLampOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RSDSTrailer = WN_API_u8GetWarningStatus(WN_enRSDSTrailer);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBPSAUnavai = WN_API_u8GetWarningStatus(WN_enAEBFCWTrailer);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWACrossTunnel = WN_API_u8GetWarningStatus(WN_enACCHWACrossTunnel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWABranchRoad = WN_API_u8GetWarningStatus(WN_enACCHWABranchRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeDevConnectErr = WN_API_u8GetWarningStatus(WN_enChargeDevConnectErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattTempLow = WN_API_u8GetWarningStatus(WN_enDynBattTempLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargePortWarning = WN_API_u8GetWarningStatus(WN_enChargePortWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCSCalibrating = WN_API_u8GetWarningStatus(WN_enIFCSCalibrating);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransAuthenFailed = WN_API_u8GetWarningStatus(WN_enTransAuthenFailed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransLimited = WN_API_u8GetWarningStatus(WN_enTransLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransReleasePFailed = WN_API_u8GetWarningStatus(WN_enTransReleasePFailed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ElecSteerUnlockFail = WN_API_u8GetWarningStatus(WN_enElecSteerUnlockFail);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EngPumpFault = WN_API_u8GetWarningStatus(WN_enEngPumpFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AGSFault = WN_API_u8GetWarningStatus(WN_enAGSFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeDevDisconnect = WN_API_u8GetWarningStatus(WN_enChargeDevDisconnect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeDevConnect = WN_API_u8GetWarningStatus(WN_enChargeDevConnect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattLow = WN_API_u8GetWarningStatus(WN_enDynBattLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GearChngP = WN_API_u8GetWarningStatus(WN_enGearChngP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GearPNeedStop = WN_API_u8GetWarningStatus(WN_enGearPNeedStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HighBeamSysFault = WN_API_u8GetWarningStatus(WN_enHighBeamSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GearPNotSuitable = WN_API_u8GetWarningStatus(WN_enGearPNotSuitable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LimpModeGearD = WN_API_u8GetWarningStatus(WN_enLimpModeGearD);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LimpModeGearP = WN_API_u8GetWarningStatus(WN_enLimpModeGearP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ReadyNoRefuel = WN_API_u8GetWarningStatus(WN_enReadyNoRefuel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelPrepare = WN_API_u8GetWarningStatus(WN_enFuelPrepare);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RaceLaunchActive = WN_API_u8GetWarningStatus(WN_enRaceLaunchActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RaceModeActive = WN_API_u8GetWarningStatus(WN_enRaceModeActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RaceLaunchTimeout = WN_API_u8GetWarningStatus(WN_enRaceLaunchTimeout);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargingNoRefuel = WN_API_u8GetWarningStatus(WN_enChargingNoRefuel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelTankSysFault = WN_API_u8GetWarningStatus(WN_enFuelTankSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelTankCapOn = WN_API_u8GetWarningStatus(WN_enFuelTankCapOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GPFRegenerating = WN_API_u8GetWarningStatus(WN_enGPFRegenerating);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GPFRegenerate = WN_API_u8GetWarningStatus(WN_enGPFRegenerate);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearAxleSysFault = WN_API_u8GetWarningStatus(WN_enRearAxleSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontAxleSysFault = WN_API_u8GetWarningStatus(WN_enFrontAxleSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DoNotStepAcAndBr = WN_API_u8GetWarningStatus(WN_enDoNotStepAcAndBr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ElecShifterFault = WN_API_u8GetWarningStatus(WN_enElecShifterFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowTranMode = WN_API_u8GetWarningStatus(WN_enStatBattLowTranMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowComfortOff = WN_API_u8GetWarningStatus(WN_enStatBattLowComfortOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_12VFaultStop = WN_API_u8GetWarningStatus(WN_en12VFaultStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_12VFaultRepair = WN_API_u8GetWarningStatus(WN_en12VFaultRepair);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowSavingMode = WN_API_u8GetWarningStatus(WN_enStatBattLowSavingMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowStartUp = WN_API_u8GetWarningStatus(WN_enStatBattLowStartUp);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ModeSwitchFailed = WN_API_u8GetWarningStatus(WN_enModeSwitchFailed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RefuelingNoCharge = WN_API_u8GetWarningStatus(WN_enRefuelingNoCharge);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftGearBrakeAndKey = WN_API_u8GetWarningStatus(WN_enShiftGearBrakeAndKey);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftGearStepBrake = WN_API_u8GetWarningStatus(WN_enShiftGearStepBrake);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftGearPressKey = WN_API_u8GetWarningStatus(WN_enShiftGearPressKey);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftNotAllowed = WN_API_u8GetWarningStatus(WN_enShiftNotAllowed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftPStop = WN_API_u8GetWarningStatus(WN_enShiftPStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DMSTakeRest_1 = WN_API_u8GetWarningStatus(WN_enDMSTakeRest_1);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DMSTakeRest_2 = WN_API_u8GetWarningStatus(WN_enDMSTakeRest_2);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DMSTakeRest_3 = WN_API_u8GetWarningStatus(WN_enDMSTakeRest_3);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DMSTakeAttention = WN_API_u8GetWarningStatus(WN_enDMSTakeAttention);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PPMIFault = WN_API_u8GetWarningStatus(WN_enPPMIFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SidePPMIErr = WN_API_u8GetWarningStatus(WN_enSidePPMIErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BSGSysFault = WN_API_u8GetWarningStatus(WN_enBSGSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsStartSelfClean = WN_API_u8GetWarningStatus(WN_enPlsStartSelfClean);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsStartCarSlowly = WN_API_u8GetWarningStatus(WN_enPlsStartCarSlowly);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DPFCleaning = WN_API_u8GetWarningStatus(WN_enDPFCleaning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SelfCleanComplete = WN_API_u8GetWarningStatus(WN_enSelfCleanComplete);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GearChngPN = WN_API_u8GetWarningStatus(WN_enGearChngPN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RainDoorOpen = WN_API_u8GetWarningStatus(WN_enRainDoorOpen);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HeatingPlugIn = WN_API_u8GetWarningStatus(WN_enHeatingPlugIn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaLow = WN_API_u8GetWarningStatus(WN_enUreaLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaVeryLow = WN_API_u8GetWarningStatus(WN_enUreaVeryLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaTankEmpty = WN_API_u8GetWarningStatus(WN_enUreaTankEmpty);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaUnqualifyPlsCheck = WN_API_u8GetWarningStatus(WN_enUreaUnqualifyPlsCheck);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaUnqualifyOver50km = WN_API_u8GetWarningStatus(WN_enUreaUnqualifyOver50km);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaFillStopPlsReFill = WN_API_u8GetWarningStatus(WN_enUreaFillStopPlsReFill);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaFillStopOver50km = WN_API_u8GetWarningStatus(WN_enUreaFillStopOver50km);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaSysDisableEng = WN_API_u8GetWarningStatus(WN_enUreaSysDisableEng);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaSysErrPlsCheck = WN_API_u8GetWarningStatus(WN_enUreaSysErrPlsCheck);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaSysErrOver50km = WN_API_u8GetWarningStatus(WN_enUreaSysErrOver50km);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaSysErrRestartErr = WN_API_u8GetWarningStatus(WN_enUreaSysErrRestartErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_ENS_EV = WN_API_u8GetWarningStatus(WN_enDM_ENS_EV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontTireAlignFinish = WN_API_u8GetWarningStatus(WN_enFrontTireAlignFinish);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontTireTurnRight = WN_API_u8GetWarningStatus(WN_enFrontTireTurnRight);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontTireTurnLeft = WN_API_u8GetWarningStatus(WN_enFrontTireTurnLeft);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RayAntiVirusWarn = WN_API_u8GetWarningStatus(WN_enRayAntiVirusWarn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvConcentrate = WN_API_u8GetWarningStatus(WN_enDrvConcentrate);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvDrowsy = WN_API_u8GetWarningStatus(WN_enDrvDrowsy);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CantDriveBatt = WN_API_u8GetWarningStatus(WN_enCantDriveBatt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DischargingV2L = WN_API_u8GetWarningStatus(WN_enDischargingV2L);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DischargingV2V = WN_API_u8GetWarningStatus(WN_enDischargingV2V);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EngVinMismatch = WN_API_u8GetWarningStatus(WN_enEngVinMismatch);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORExperMode = WN_API_u8GetWarningStatus(WN_enORExperMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeHeating = WN_API_u8GetWarningStatus(WN_enChargeHeating);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCExitPlsControl = WN_API_u8GetWarningStatus(WN_enIFCExitPlsControl);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCTakePhone = WN_API_u8GetWarningStatus(WN_enWPCTakePhone);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ARHUDFault = WN_API_u8GetWarningStatus(WN_enARHUDFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ARHUDOverheat = WN_API_u8GetWarningStatus(WN_enARHUDOverheat);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SRaceLaunchActive = WN_API_u8GetWarningStatus(WN_enSRaceLaunchActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattLowSRaceLaunUnAvail = WN_API_u8GetWarningStatus(WN_enBattLowSRaceLaunUnAvail);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TransHeatSLaunchUnAvail = WN_API_u8GetWarningStatus(WN_enTransHeatSLaunchUnAvail);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SRaceLaunchOverLimit = WN_API_u8GetWarningStatus(WN_enSRaceLaunchOverLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattTempLowCantStart = WN_API_u8GetWarningStatus(WN_enBattTempLowCantStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattTempLowPowerDown = WN_API_u8GetWarningStatus(WN_enBattTempLowPowerDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattTempHighPowerDown = WN_API_u8GetWarningStatus(WN_enBattTempHighPowerDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsPrsBrktoWait = WN_API_u8GetWarningStatus(WN_enPlsPrsBrktoWait);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SelfLearnNotComplete = WN_API_u8GetWarningStatus(WN_enSelfLearnNotComplete);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LearnSuccessPlsRelBrk = WN_API_u8GetWarningStatus(WN_enLearnSuccessPlsRelBrk);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerLowEVUnvil = WN_API_u8GetWarningStatus(WN_enPowerLowEVUnvil);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsCtrlWheel = WN_API_u8GetWarningStatus(WN_enPlsCtrlWheel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearAxSysErr4WDUnvil = WN_API_u8GetWarningStatus(WN_enRearAxSysErr4WDUnvil);

    //Secondary alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PEPSPowerFault = WN_API_u8GetWarningStatus(WN_enPEPSPowerFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedLevel_1 = WN_API_u8GetWarningStatus(WN_enOverSpeedLevel_1);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedLevel_2 = WN_API_u8GetWarningStatus(WN_enOverSpeedLevel_2);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedSetting = WN_API_u8GetWarningStatus(WN_enOverSpeedSetting);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LicPlateLampFault = WN_API_u8GetWarningStatus(WN_enLicPlateLampFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RvsLampFault = WN_API_u8GetWarningStatus(WN_enRvsLampFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearPosnLampFault = WN_API_u8GetWarningStatus(WN_enRearPosnLampFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LasHdLightFault = WN_API_u8GetWarningStatus(WN_enLasHdLightFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCSDectectLimited = WN_API_u8GetWarningStatus(WN_enIFCSDectectLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCSensorDetectLimited = WN_API_u8GetWarningStatus(WN_enACCSensorDetectLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FCTSDectectLimit = WN_API_u8GetWarningStatus(WN_enFCTSDectectLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCLKAFunLimited = WN_API_u8GetWarningStatus(WN_enIFCLKAFunLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CommunicationFault = WN_API_u8GetWarningStatus(WN_enCommunicationFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCHWAFuncFault = WN_API_u8GetWarningStatus(WN_enACCHWAFuncFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RSDSRCWWarning = WN_API_u8GetWarningStatus(WN_enRSDSRCWWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BeepSysFault = WN_API_u8GetWarningStatus(WN_enBeepSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BrakeLampFault = WN_API_u8GetWarningStatus(WN_enBrakeLampFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearFogLampFault = WN_API_u8GetWarningStatus(WN_enRearFogLampFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RainLightFault = WN_API_u8GetWarningStatus(WN_enRainLightFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AFSSystemFault = WN_API_u8GetWarningStatus(WN_enAFSSystemFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCUnavailable = WN_API_u8GetWarningStatus(WN_enACCUnavailable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCCruiseFunFault = WN_API_u8GetWarningStatus(WN_enACCCruiseFunFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AEBESPOff = WN_API_u8GetWarningStatus(WN_enAEBESPOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TrafficSignFault = WN_API_u8GetWarningStatus(WN_enTrafficSignFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowPwrReduce = WN_API_u8GetWarningStatus(WN_enStatBattLowPwrReduce);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ALSSysFault = WN_API_u8GetWarningStatus(WN_enALSSysFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORCruiseLimited = WN_API_u8GetWarningStatus(WN_enORCruiseLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnAssistLimited = WN_API_u8GetWarningStatus(WN_enTurnAssistLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HDCLimited = WN_API_u8GetWarningStatus(WN_enHDCLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoholdLimited = WN_API_u8GetWarningStatus(WN_enAutoholdLimited);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCChargeZone = WN_API_u8GetWarningStatus(WN_enWPCChargeZone);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLFault = WN_API_u8GetWarningStatus(WN_enPHLFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLCameraFault = WN_API_u8GetWarningStatus(WN_enPHLCameraFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeSlow = WN_API_u8GetWarningStatus(WN_en4LModeSlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4WDSystemDemotion = WN_API_u8GetWarningStatus(WN_en4WDSystemDemotion);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4HModeSlow = WN_API_u8GetWarningStatus(WN_en4HModeSlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_VSGFault = WN_API_u8GetWarningStatus(WN_enVSGFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattCutOff = WN_API_u8GetWarningStatus(WN_enDynBattCutOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ElecMachiFault = WN_API_u8GetWarningStatus(WN_enElecMachiFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DCDCFault = WN_API_u8GetWarningStatus(WN_enDCDCFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EParkFault = WN_API_u8GetWarningStatus(WN_enEParkFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RemoveChargeGun = WN_API_u8GetWarningStatus(WN_enRemoveChargeGun);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RemoveDischrgGun = WN_API_u8GetWarningStatus(WN_enRemoveDischrgGun);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShifterFault = WN_API_u8GetWarningStatus(WN_enShifterFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftNotAllowEV = WN_API_u8GetWarningStatus(WN_enShiftNotAllowEV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftPFault = WN_API_u8GetWarningStatus(WN_enShiftPFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ShiftPStopEV = WN_API_u8GetWarningStatus(WN_enShiftPStopEV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargingShift = WN_API_u8GetWarningStatus(WN_enChargingShift);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakeOutP = WN_API_u8GetWarningStatus(WN_enStepBrakeOutP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakeOutN = WN_API_u8GetWarningStatus(WN_enStepBrakeOutN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LVBattFault = WN_API_u8GetWarningStatus(WN_enLVBattFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HVBattSport = WN_API_u8GetWarningStatus(WN_enHVBattSport);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HVBattAir = WN_API_u8GetWarningStatus(WN_enHVBattAir);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ECOValue = WN_API_u8GetWarningStatus(WN_enECOValue);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PedalLimit = WN_API_u8GetWarningStatus(WN_enPedalLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UnidentifyBatt = WN_API_u8GetWarningStatus(WN_enUnidentifyBatt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HeatManagerFault = WN_API_u8GetWarningStatus(WN_enHeatManagerFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FarBeamFault = WN_API_u8GetWarningStatus(WN_enFarBeamFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattFault = WN_API_u8GetWarningStatus(WN_enDynBattFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TboxErr = WN_API_u8GetWarningStatus(WN_enTboxErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DynBattLowEV = WN_API_u8GetWarningStatus(WN_enDynBattLowEV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionLimit = WN_API_u8GetWarningStatus(WN_enSuspensionLimit);

    //Tips
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerOnGearDrive = WN_API_u8GetWarningStatus(WN_enPowerOnGearDrive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelStart = WN_API_u8GetWarningStatus(WN_enFuelStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_KeyInCarOrNot = WN_API_u8GetWarningStatus(WN_enKeyInCarOrNot);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCISLCruiseSpeed = WN_API_u8GetWarningStatus(WN_enACCISLCruiseSpeed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakeStartGearPN = WN_API_u8GetWarningStatus(WN_enStepBrakeStartGearPN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepClutchStartGearNull = WN_API_u8GetWarningStatus(WN_enStepClutchStartGearNull);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakeStartGearNull = WN_API_u8GetWarningStatus(WN_enStepBrakeStartGearNull);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCISLSlowDoWN = WN_API_u8GetWarningStatus(WN_enACCISLSlowDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TargetCruiseSpeed = WN_API_u8GetWarningStatus(WN_enTargetCruiseSpeed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LasHdLightOn = WN_API_u8GetWarningStatus(WN_enLasHdLightOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LasHdLightOff = WN_API_u8GetWarningStatus(WN_enLasHdLightOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ParkLampOn = WN_API_u8GetWarningStatus(WN_enParkLampOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrowsyDrvWarning = WN_API_u8GetWarningStatus(WN_enDrowsyDrvWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrowsyDrvWarning_1Hz = WN_API_u8GetWarningStatus(WN_enDrowsyDrvWarning_1Hz);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TakeTheKeyTip = WN_API_u8GetWarningStatus(WN_enTakeTheKeyTip);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelLowWarn = WN_API_u8GetWarningStatus(WN_enFuelLowWarn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AFSDrivingMode = WN_API_u8GetWarningStatus(WN_enAFSDrivingMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ALSDrivingSide = WN_API_u8GetWarningStatus(WN_enALSDrivingSide);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MaintainPlease = WN_API_u8GetWarningStatus(WN_enMaintainPlease);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MaintainNext = WN_API_u8GetWarningStatus(WN_enMaintainNext);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ReleaseElecParkCCO = WN_API_u8GetWarningStatus(WN_enReleaseElecParkCCO);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PleaseSlowDoWN = WN_API_u8GetWarningStatus(WN_enPleaseSlowDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeStop = WN_API_u8GetWarningStatus(WN_en4LModeStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PleaseGearN = WN_API_u8GetWarningStatus(WN_enPleaseGearN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeEx = WN_API_u8GetWarningStatus(WN_en4LModeEx);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeSelect = WN_API_u8GetWarningStatus(WN_en4LModeSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4HModeSelect = WN_API_u8GetWarningStatus(WN_en4HModeSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeEn = WN_API_u8GetWarningStatus(WN_en4LModeEn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORCruiseActive = WN_API_u8GetWarningStatus(WN_enORCruiseActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Standard = WN_API_u8GetWarningStatus(WN_enDM_B30_Standard);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Sport = WN_API_u8GetWarningStatus(WN_enDM_B30_Sport);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Snow = WN_API_u8GetWarningStatus(WN_enDM_B30_Snow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Muddy = WN_API_u8GetWarningStatus(WN_enDM_B30_Muddy);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Sand = WN_API_u8GetWarningStatus(WN_enDM_B30_Sand);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_4L = WN_API_u8GetWarningStatus(WN_enDM_B30_4L);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_ECO = WN_API_u8GetWarningStatus(WN_enDM_B30_ECO);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_IMC = WN_API_u8GetWarningStatus(WN_enDM_B30_IMC);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_SportPlus = WN_API_u8GetWarningStatus(WN_enDM_B30_SportPlus);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_OffRoad = WN_API_u8GetWarningStatus(WN_enDM_B30_OffRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Expert = WN_API_u8GetWarningStatus(WN_enDM_B30_Expert);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Rock = WN_API_u8GetWarningStatus(WN_enDM_B30_Rock);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Pothole = WN_API_u8GetWarningStatus(WN_enDM_B30_Pothole);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_MuddySand = WN_API_u8GetWarningStatus(WN_enDM_B30_MuddySand);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Mountain = WN_API_u8GetWarningStatus(WN_enDM_B30_Mountain);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_StandardSelect = WN_API_u8GetWarningStatus(WN_enDM_StandardSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportSelect = WN_API_u8GetWarningStatus(WN_enDM_SportSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportPlusSelect = WN_API_u8GetWarningStatus(WN_enDM_SportPlusSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SnowSelect = WN_API_u8GetWarningStatus(WN_enDM_SnowSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddySelect = WN_API_u8GetWarningStatus(WN_enDM_MuddySelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SandSelect = WN_API_u8GetWarningStatus(WN_enDM_SandSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EcoSelect = WN_API_u8GetWarningStatus(WN_enDM_EcoSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RockSelect = WN_API_u8GetWarningStatus(WN_enDM_RockSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PotholeSelect = WN_API_u8GetWarningStatus(WN_enDM_PotholeSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddySandSelect = WN_API_u8GetWarningStatus(WN_enDM_MuddySandSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MountainSelect = WN_API_u8GetWarningStatus(WN_enDM_MountainSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_ExpertSelect = WN_API_u8GetWarningStatus(WN_enDM_ExpertSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_OffRoadSelect = WN_API_u8GetWarningStatus(WN_enDM_OffRoadSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4LSelect = WN_API_u8GetWarningStatus(WN_enDM_4LSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_IMCSelect = WN_API_u8GetWarningStatus(WN_enDM_IMCSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_StandardDPR = WN_API_u8GetWarningStatus(WN_enDM_StandardDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportDPR = WN_API_u8GetWarningStatus(WN_enDM_SportDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EcoDPR = WN_API_u8GetWarningStatus(WN_enDM_EcoDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SnowDPR = WN_API_u8GetWarningStatus(WN_enDM_SnowDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddyDPR = WN_API_u8GetWarningStatus(WN_enDM_MuddyDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SandDPR = WN_API_u8GetWarningStatus(WN_enDM_SandDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PotholeDPR = WN_API_u8GetWarningStatus(WN_enDM_PotholeDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MountainDPR = WN_API_u8GetWarningStatus(WN_enDM_MountainDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RockDPR = WN_API_u8GetWarningStatus(WN_enDM_RockDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_OffRoadDPR = WN_API_u8GetWarningStatus(WN_enDM_OffRoadDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportPlusDPR = WN_API_u8GetWarningStatus(WN_enDM_SportPlusDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_ExpertDPR = WN_API_u8GetWarningStatus(WN_enDM_ExpertDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddySandDPR = WN_API_u8GetWarningStatus(WN_enDM_MuddySandDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_IMCDPR = WN_API_u8GetWarningStatus(WN_enDM_IMCDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4LDPR = WN_API_u8GetWarningStatus(WN_enDM_4LDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LEnGearN = WN_API_u8GetWarningStatus(WN_en4LEnGearN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LEnGearDRP = WN_API_u8GetWarningStatus(WN_en4LEnGearDRP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LExGearN = WN_API_u8GetWarningStatus(WN_en4LExGearN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LExGearDRP = WN_API_u8GetWarningStatus(WN_en4LExGearDRP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LEnClutchStep = WN_API_u8GetWarningStatus(WN_en4LEnClutchStep);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LEnClutchRele = WN_API_u8GetWarningStatus(WN_en4LEnClutchRele);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LExClutchStep = WN_API_u8GetWarningStatus(WN_en4LExClutchStep);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LExClutchRele = WN_API_u8GetWarningStatus(WN_en4LExClutchRele);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_StandardSecond = WN_API_u8GetWarningStatus(WN_enDM_StandardSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportSecond = WN_API_u8GetWarningStatus(WN_enDM_SportSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SportPlusSecond = WN_API_u8GetWarningStatus(WN_enDM_SportPlusSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SnowSecond = WN_API_u8GetWarningStatus(WN_enDM_SnowSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddySecond = WN_API_u8GetWarningStatus(WN_enDM_MuddySecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_SandSecond = WN_API_u8GetWarningStatus(WN_enDM_SandSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_ECOSecond = WN_API_u8GetWarningStatus(WN_enDM_ECOSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4LSecond = WN_API_u8GetWarningStatus(WN_enDM_4LSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PotholeSecond = WN_API_u8GetWarningStatus(WN_enDM_PotholeSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MountainSecond = WN_API_u8GetWarningStatus(WN_enDM_MountainSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RockSecond = WN_API_u8GetWarningStatus(WN_enDM_RockSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_OffRoadSecond = WN_API_u8GetWarningStatus(WN_enDM_OffRoadSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_ExpertSecond = WN_API_u8GetWarningStatus(WN_enDM_ExpertSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_IMCSecond = WN_API_u8GetWarningStatus(WN_enDM_IMCSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MuddySandSecond = WN_API_u8GetWarningStatus(WN_enDM_MuddySandSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_StandardStart = WN_API_u8GetWarningStatus(WN_enDM_EV_StandardStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_SportStart = WN_API_u8GetWarningStatus(WN_enDM_EV_SportStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_EcoStart = WN_API_u8GetWarningStatus(WN_enDM_EV_EcoStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_SnowStart = WN_API_u8GetWarningStatus(WN_enDM_EV_SnowStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_AutoStart = WN_API_u8GetWarningStatus(WN_enDM_EV_AutoStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StopBrakeGearN = WN_API_u8GetWarningStatus(WN_enStopBrakeGearN);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerNotInOff = WN_API_u8GetWarningStatus(WN_enPowerNotInOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoStartStop = WN_API_u8GetWarningStatus(WN_enAutoStartStop);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeDevRemoved = WN_API_u8GetWarningStatus(WN_enChargeDevRemoved);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_DBL_EV_Err = WN_API_u8GetWarningStatus(WN_enDM_DBL_EV_Err);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_AWD = WN_API_u8GetWarningStatus(WN_enDM_HSL_AWD);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_EV = WN_API_u8GetWarningStatus(WN_enDM_HSL_EV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_SAVE = WN_API_u8GetWarningStatus(WN_enDM_HSL_SAVE);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_SPORT = WN_API_u8GetWarningStatus(WN_enDM_HSL_SPORT);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_SAND = WN_API_u8GetWarningStatus(WN_enDM_HSL_SAND);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_MUDDY = WN_API_u8GetWarningStatus(WN_enDM_HSL_MUDDY);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_SNOW = WN_API_u8GetWarningStatus(WN_enDM_HSL_SNOW);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_AutoStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_AutoStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_EvStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_EvStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_SaveStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_SaveStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_SportStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_SportStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_AWDStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_AWDStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_SnowStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_SnowStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_MuddyStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_MuddyStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_SandStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_SandStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_EcoStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_EcoStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_SportPlusStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_SportPlusStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MS_SPORT = WN_API_u8GetWarningStatus(WN_enDM_MS_SPORT);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_MS_SPORT_Only = WN_API_u8GetWarningStatus(WN_enDM_MS_SPORT_Only);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSR_EV = WN_API_u8GetWarningStatus(WN_enDM_HSR_EV);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RLUnavaiESPAVH = WN_API_u8GetWarningStatus(WN_enRLUnavaiESPAVH);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RLUnavaiHYB = WN_API_u8GetWarningStatus(WN_enRLUnavaiHYB);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_SPORT_P = WN_API_u8GetWarningStatus(WN_enDM_HSL_SPORT_P);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_HSL_ECO = WN_API_u8GetWarningStatus(WN_enDM_HSL_ECO);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnAssistOn = WN_API_u8GetWarningStatus(WN_enTurnAssistOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnAssistWork = WN_API_u8GetWarningStatus(WN_enTurnAssistWork);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnAssistClose = WN_API_u8GetWarningStatus(WN_enTurnAssistClose);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORCruiseClose = WN_API_u8GetWarningStatus(WN_enORCruiseClose);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORCruiseWait = WN_API_u8GetWarningStatus(WN_enORCruiseWait);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORCruiseOn = WN_API_u8GetWarningStatus(WN_enORCruiseOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FastenSeatbelt = WN_API_u8GetWarningStatus(WN_enFastenSeatbelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GradientHighWarning = WN_API_u8GetWarningStatus(WN_enGradientHighWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ParkSysWarning = WN_API_u8GetWarningStatus(WN_enParkSysWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ClampForceWarning = WN_API_u8GetWarningStatus(WN_enClampForceWarning);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakePedal = WN_API_u8GetWarningStatus(WN_enStepBrakePedal);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SettingVehilce = WN_API_u8GetWarningStatus(WN_enSettingVehilce);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OutTempLow = WN_API_u8GetWarningStatus(WN_enOutTempLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AFSOff = WN_API_u8GetWarningStatus(WN_enAFSOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AFSOn = WN_API_u8GetWarningStatus(WN_enAFSOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SwitchMudSand = WN_API_u8GetWarningStatus(WN_enSwitchMudSand);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RaceModeExit = WN_API_u8GetWarningStatus(WN_enRaceModeExit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RaceModeFault = WN_API_u8GetWarningStatus(WN_enRaceModeFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLWideFunOff = WN_API_u8GetWarningStatus(WN_enPHLWideFunOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLWideOn = WN_API_u8GetWarningStatus(WN_enPHLWideOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLWideOff = WN_API_u8GetWarningStatus(WN_enPHLWideOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLFunOff = WN_API_u8GetWarningStatus(WN_enPHLFunOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PHLFunOn = WN_API_u8GetWarningStatus(WN_enPHLFunOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_QuitCompactMode = WN_API_u8GetWarningStatus(WN_enQuitCompactMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WashModeActive = WN_API_u8GetWarningStatus(WN_enWashModeActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WashModeSpeed = WN_API_u8GetWarningStatus(WN_enWashModeSpeed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WashModeBatt = WN_API_u8GetWarningStatus(WN_enWashModeBatt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeDisGunConnect = WN_API_u8GetWarningStatus(WN_enChargeDisGunConnect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargeGunConnect = WN_API_u8GetWarningStatus(WN_enChargeGunConnect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ReleaseElecPark = WN_API_u8GetWarningStatus(WN_enReleaseElecPark);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ReleaseRearELD = WN_API_u8GetWarningStatus(WN_enReleaseRearELD);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RLUnavaiESP = WN_API_u8GetWarningStatus(WN_enRLUnavaiESP);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HeatingComplete = WN_API_u8GetWarningStatus(WN_enHeatingComplete);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FaceCancelled = WN_API_u8GetWarningStatus(WN_enFaceCancelled);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FaceNoMatch = WN_API_u8GetWarningStatus(WN_enFaceNoMatch);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FaceSuccess = WN_API_u8GetWarningStatus(WN_enFaceSuccess);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PedalDynBatt = WN_API_u8GetWarningStatus(WN_enPedalDynBatt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PedalDynSnow = WN_API_u8GetWarningStatus(WN_enPedalDynSnow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FarBeamOn = WN_API_u8GetWarningStatus(WN_enFarBeamOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FarBeamOff = WN_API_u8GetWarningStatus(WN_enFarBeamOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TmsTrailer = WN_API_u8GetWarningStatus(WN_enTmsTrailerOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TsmTrailerOff = WN_API_u8GetWarningStatus(WN_enTmsTrailerOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4WDGearDelayPlsSlow = WN_API_u8GetWarningStatus(WN_en4WDGearDelayPlsSlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ARHUDLightLimit = WN_API_u8GetWarningStatus(WN_enARHUDLightLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattLowLaunchUnavil = WN_API_u8GetWarningStatus(WN_enBattLowLaunchUnavil);

    //Update for Warning table v0.60
    //Special alarm

    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ERCSysErr = WN_API_u8GetWarningStatus(WN_enERCSysErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_IFCLKAFuncOn = WN_API_u8GetWarningStatus(WN_enIFCLKAFuncOn);

    //Secondary alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnAssistFuncLimit = WN_API_u8GetWarningStatus(WN_enTurnAssistFuncLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ERCSysLimit = WN_API_u8GetWarningStatus(WN_enERCSysLimit);

    //Tips
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MainTankLow = WN_API_u8GetWarningStatus(WN_enMainTankLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MainTankLowPlsSwitch = WN_API_u8GetWarningStatus(WN_enMainTankLowPlsSwitch);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AuxTankLow = WN_API_u8GetWarningStatus(WN_enAuxTankLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AuxTankLowPlsSwitch = WN_API_u8GetWarningStatus(WN_enAuxTankLowPlsSwitch);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Turbo = WN_API_u8GetWarningStatus(WN_enDM_B30_Turbo);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Race = WN_API_u8GetWarningStatus(WN_enDM_B30_Race);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_GrassGravel = WN_API_u8GetWarningStatus(WN_enDM_B30_GrassGravel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Uneven = WN_API_u8GetWarningStatus(WN_enDM_B30_Uneven);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Wade4H = WN_API_u8GetWarningStatus(WN_enDM_B30_Wade4H);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Wade4L = WN_API_u8GetWarningStatus(WN_enDM_B30_Wade4L);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_2H = WN_API_u8GetWarningStatus(WN_enDM_B30_2H);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_4H = WN_API_u8GetWarningStatus(WN_enDM_B30_4H);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_TurboSelect = WN_API_u8GetWarningStatus(WN_enDM_TurboSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RaceSelect = WN_API_u8GetWarningStatus(WN_enDM_RaceSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_GrassGravelSelect = WN_API_u8GetWarningStatus(WN_enDM_GrassGravelSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_UnevenSelect = WN_API_u8GetWarningStatus(WN_enDM_UnevenSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4HSelect = WN_API_u8GetWarningStatus(WN_enDM_Wade4HSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4LSelect = WN_API_u8GetWarningStatus(WN_enDM_Wade4LSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_2HSelect = WN_API_u8GetWarningStatus(WN_enDM_2HSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4HSelect = WN_API_u8GetWarningStatus(WN_enDM_4HSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_TurboDPR = WN_API_u8GetWarningStatus(WN_enDM_TurboDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RaceDPR = WN_API_u8GetWarningStatus(WN_enDM_RaceDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_GrassGravelDPR = WN_API_u8GetWarningStatus(WN_enDM_GrassGravelDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_UnevenDPR = WN_API_u8GetWarningStatus(WN_enDM_UnevenDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4HDPR = WN_API_u8GetWarningStatus(WN_enDM_Wade4HDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4LDPR = WN_API_u8GetWarningStatus(WN_enDM_Wade4LDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_2HDPR = WN_API_u8GetWarningStatus(WN_enDM_2HDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4HDPR = WN_API_u8GetWarningStatus(WN_enDM_4HDPR);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_TurboSecond = WN_API_u8GetWarningStatus(WN_enDM_TurboSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_RaceSecond = WN_API_u8GetWarningStatus(WN_enDM_RaceSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_GrassGravelSecond = WN_API_u8GetWarningStatus(WN_enDM_GrassGravelSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_UnevenSecond = WN_API_u8GetWarningStatus(WN_enDM_UnevenSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4HSecond = WN_API_u8GetWarningStatus(WN_enDM_Wade4HSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_Wade4LSecond = WN_API_u8GetWarningStatus(WN_enDM_Wade4LSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_2HSecond = WN_API_u8GetWarningStatus(WN_enDM_2HSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_4HSecond = WN_API_u8GetWarningStatus(WN_enDM_4HSecond);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_P2HEVStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_P2HEVStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_P2EVStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_P2EVStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_PHEV_P2SaveStart = WN_API_u8GetWarningStatus(WN_enDM_PHEV_P2SaveStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoNaviStart = WN_API_u8GetWarningStatus(WN_enAutoNaviStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoNaviExitPlsTake = WN_API_u8GetWarningStatus(WN_enAutoNaviExitPlsTake);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoNaviEnd = WN_API_u8GetWarningStatus(WN_enAutoNaviEnd);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedERCSysOn = WN_API_u8GetWarningStatus(WN_enOverSpeedERCSysOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ERCSysDisable = WN_API_u8GetWarningStatus(WN_enERCSysDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OffroadThmSts = WN_API_u8GetWarningStatus(WN_enOffroadThmSts);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AntennaLostErr = WN_API_u8GetWarningStatus(WN_enAntennaLostErr);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoLmpStsOn = WN_API_u8GetWarningStatus(WN_enAutoLmpStsOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoLmpStsOff = WN_API_u8GetWarningStatus(WN_enAutoLmpStsOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsExitWadeMode = WN_API_u8GetWarningStatus(WN_enPlsExitWadeMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WadeModePlsSlow = WN_API_u8GetWarningStatus(WN_enWadeModePlsSlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WadeModePlsCare = WN_API_u8GetWarningStatus(WN_enWadeModePlsCare);

    //Update for Warning table v0.62
    //Special alarm
    
    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CarPowerShutDown = WN_API_u8GetWarningStatus(WN_enCarPowerShutDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LifeDetectFault = WN_API_u8GetWarningStatus(WN_enLifeDetectFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ClutchOverheat = WN_API_u8GetWarningStatus(WN_enClutchOverheat);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_QuickStartOvertime = WN_API_u8GetWarningStatus(WN_enQuickStartOvertime);

    //Secondary alarm

    //Tips
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LifeDetectClose = WN_API_u8GetWarningStatus(WN_enLifeDetectClose);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StopGearNSeatbelt = WN_API_u8GetWarningStatus(WN_enStopGearNSeatbelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StopGearPNSeatbelt = WN_API_u8GetWarningStatus(WN_enStopGearPNSeatbelt);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SwitchSnowSand = WN_API_u8GetWarningStatus(WN_enSwitchSnowSand);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_Individual = WN_API_u8GetWarningStatus(WN_enIndividual);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerSysLimitLaunchFail = WN_API_u8GetWarningStatus(WN_enPowerSysLimitLaunchFail);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ForwardChargeMode = WN_API_u8GetWarningStatus(WN_enForwardChargeMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4WDEVSaveDisable = WN_API_u8GetWarningStatus(WN_en4WDEVSaveDisable);

    //Popup
    
    //Update for Warning table v0.64
    //Special alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XCarDistance = WN_API_u8GetWarningStatus(WN_enV2XCarDistance);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XPeopleRight = WN_API_u8GetWarningStatus(WN_enV2XPeopleRight);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XPeopleMid = WN_API_u8GetWarningStatus(WN_enV2XPeopleMid);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XPeopleLeft = WN_API_u8GetWarningStatus(WN_enV2XPeopleLeft);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFaceCar = WN_API_u8GetWarningStatus(WN_enV2XFaceCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XSideCarTwoSide = WN_API_u8GetWarningStatus(WN_enV2XSideCarTwoSide);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XSideCarRight = WN_API_u8GetWarningStatus(WN_enV2XSideCarRight);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XSideCarLeft = WN_API_u8GetWarningStatus(WN_enV2XSideCarLeft);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontCarAEB = WN_API_u8GetWarningStatus(WN_enV2XFrontCarAEB);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontCarUnContron = WN_API_u8GetWarningStatus(WN_enV2XFrontCarUnContron);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XBackCarUnContron = WN_API_u8GetWarningStatus(WN_enV2XBackCarUnContron);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XAroundCarUnContron = WN_API_u8GetWarningStatus(WN_enV2XAroundCarUnContron);
    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HookFaultPlsCheck = WN_API_u8GetWarningStatus(WN_enHookFaultPlsCheck);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionFuncLimit = WN_API_u8GetWarningStatus(WN_enSuspensionFuncLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionFuncFault = WN_API_u8GetWarningStatus(WN_enSuspensionFuncFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CatalystSuHigh = WN_API_u8GetWarningStatus(WN_enCatalystSuHigh);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuClearing = WN_API_u8GetWarningStatus(WN_enSuClearing);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OilLeverLow = WN_API_u8GetWarningStatus(WN_enOilLeverLow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OilLeverHigh = WN_API_u8GetWarningStatus(WN_enOilLeverHigh);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OilLeverFault = WN_API_u8GetWarningStatus(WN_enOilLeverFault);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeftLine = WN_API_u8GetWarningStatus(WN_enV2XLeftLine);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XRightLine = WN_API_u8GetWarningStatus(WN_enV2XRightLine);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XReverseLine = WN_API_u8GetWarningStatus(WN_enV2XReverseLine);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontRoad = WN_API_u8GetWarningStatus(WN_enV2XFrontRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontCarAttention = WN_API_u8GetWarningStatus(WN_enV2XFrontCarAttention);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeaveCar = WN_API_u8GetWarningStatus(WN_enV2XLeaveCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeaveFireCar = WN_API_u8GetWarningStatus(WN_enV2XLeaveFireCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeaveAmbulance = WN_API_u8GetWarningStatus(WN_enV2XLeaveAmbulance);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeavePolice = WN_API_u8GetWarningStatus(WN_enV2XLeavePolice);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XLeaveEngCar = WN_API_u8GetWarningStatus(WN_enV2XLeaveEngCar);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XBackCarLeft = WN_API_u8GetWarningStatus(WN_enV2XBackCarLeft);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XBackCarRight = WN_API_u8GetWarningStatus(WN_enV2XBackCarRight);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XBackCarTwoSide = WN_API_u8GetWarningStatus(WN_enV2XBackCarTwoSide);
    //Secondary alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SavePlusPowerLimit = WN_API_u8GetWarningStatus(WN_enSavePlusPowerLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedSavePlusFail = WN_API_u8GetWarningStatus(WN_enOverSpeedSavePlusFail);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WormFuncActive = WN_API_u8GetWarningStatus(WN_enWormFuncActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WormFuncOff = WN_API_u8GetWarningStatus(WN_enWormFuncOff);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattLowStartEng = WN_API_u8GetWarningStatus(WN_enBattLowStartEng);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionCoolDown = WN_API_u8GetWarningStatus(WN_enSuspensionCoolDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HeightModeDisable = WN_API_u8GetWarningStatus(WN_enHeightModeDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsCloseDoorRise = WN_API_u8GetWarningStatus(WN_enPlsCloseDoorRise);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RiseModeSusLimit = WN_API_u8GetWarningStatus(WN_enRiseModeSusLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionTimeLimit = WN_API_u8GetWarningStatus(WN_enSuspensionTimeLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedHeightDisable = WN_API_u8GetWarningStatus(WN_enOverSpeedHeightDisable);
    //Tips
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverDefaultPower = WN_API_u8GetWarningStatus(WN_enOverDefaultPower);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HookLock = WN_API_u8GetWarningStatus(WN_enHookLock);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HookUnlock = WN_API_u8GetWarningStatus(WN_enHookUnlock);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HookPowerOn = WN_API_u8GetWarningStatus(WN_enHookPowerOn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SwitchParkSts = WN_API_u8GetWarningStatus(WN_enSwitchParkSts);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsCloseHook = WN_API_u8GetWarningStatus(WN_enPlsCloseHook);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsCheckHookSts = WN_API_u8GetWarningStatus(WN_enPlsCheckHookSts);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NormalHeightSelect = WN_API_u8GetWarningStatus(WN_enNormalHeightSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuitHeightSelect = WN_API_u8GetWarningStatus(WN_enSuitHeightSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORHeight1Select = WN_API_u8GetWarningStatus(WN_enORHeight1Select);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ORHeight2Select = WN_API_u8GetWarningStatus(WN_enORHeight2Select);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionExtend = WN_API_u8GetWarningStatus(WN_enSuspensionExtend);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionLockHeight = WN_API_u8GetWarningStatus(WN_enSuspensionLockHeight);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BackShaftHeightSelect = WN_API_u8GetWarningStatus(WN_enBackShaftHeightSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuitHeightModeSelect = WN_API_u8GetWarningStatus(WN_enSuitHeightModeSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionTrailer = WN_API_u8GetWarningStatus(WN_enSuspensionTrailer);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionLimitRise = WN_API_u8GetWarningStatus(WN_enSuspensionLimitRise);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_KickBackShaft = WN_API_u8GetWarningStatus(WN_enKickBackShaft);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionLimitTrans = WN_API_u8GetWarningStatus(WN_enSuspensionLimitTrans);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuspensionRise = WN_API_u8GetWarningStatus(WN_enSuspensionRise);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CarHighPlsSlow = WN_API_u8GetWarningStatus(WN_enCarHighPlsSlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SuClearDown = WN_API_u8GetWarningStatus(WN_enSuClearDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SysFailACCDisable = WN_API_u8GetWarningStatus(WN_enSysFailACCDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCPowerDisable = WN_API_u8GetWarningStatus(WN_enACCPowerDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HWAACCPowerDisable = WN_API_u8GetWarningStatus(WN_enHWAACCPowerDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ESPACCPowerDisable = WN_API_u8GetWarningStatus(WN_enESPACCPowerDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCPowerExit = WN_API_u8GetWarningStatus(WN_enACCPowerExit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattPowerLowEVDisable = WN_API_u8GetWarningStatus(WN_enBattPowerLowEVDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BattTempLowEVDisable = WN_API_u8GetWarningStatus(WN_enBattTempLowEVDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4LModeEVSaveDisable = WN_API_u8GetWarningStatus(WN_en4LModeEVSaveDisable);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CalibreHeatTabLimit = WN_API_u8GetWarningStatus(WN_enCalibreHeatTabLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SavePlusModeStart = WN_API_u8GetWarningStatus(WN_enSavePlusModeStart);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XRoadBlockLever1 = WN_API_u8GetWarningStatus(WN_enV2XRoadBlockLever1);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XRoadBlockLever2 = WN_API_u8GetWarningStatus(WN_enV2XRoadBlockLever2);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XRoadBlockLever3 = WN_API_u8GetWarningStatus(WN_enV2XRoadBlockLever3);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XRoadBlock = WN_API_u8GetWarningStatus(WN_enV2XRoadBlock);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StepBrakeStartGearBlank = WN_API_u8GetWarningStatus(WN_enStepBrakeStartGearBlank);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StopGearBlankSeatbelt = WN_API_u8GetWarningStatus(WN_enStopGearBlankSeatbelt);

	//Update for Warning table v0.66
	//Special alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsTakeOver = WN_API_u8GetWarningStatus(WN_enPlsTakeOver);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsTakeOver_2Hz = WN_API_u8GetWarningStatus(WN_enPlsTakeOver_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsTakeOver_4Hz = WN_API_u8GetWarningStatus(WN_enPlsTakeOver_4Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CarAutoBrakePlsTake = WN_API_u8GetWarningStatus(WN_enCarAutoBrakePlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CarParkingPlsTake = WN_API_u8GetWarningStatus(WN_enCarParkingPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CarUrgeBrakePlsTake = WN_API_u8GetWarningStatus(WN_enCarUrgeBrakePlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveRampFailPlsTake = WN_API_u8GetWarningStatus(WN_enMoveRampFailPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveMainFailPlsTake = WN_API_u8GetWarningStatus(WN_enMoveMainFailPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveMainFailPlsTake_2Hz = WN_API_u8GetWarningStatus(WN_enMoveMainFailPlsTake_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveMainFailPlsTake_4Hz = WN_API_u8GetWarningStatus(WN_enMoveMainFailPlsTake_4Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnFailPlsTake = WN_API_u8GetWarningStatus(WN_enTurnFailPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnFailPlsTake_2Hz = WN_API_u8GetWarningStatus(WN_enTurnFailPlsTake_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnFailPlsTake_4Hz = WN_API_u8GetWarningStatus(WN_enTurnFailPlsTake_4Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TollGateFailPlsTake = WN_API_u8GetWarningStatus(WN_enTollGateFailPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TollGateFailPlsTake_2Hz = WN_API_u8GetWarningStatus(WN_enTollGateFailPlsTake_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TollGateFailPlsTake_4Hz = WN_API_u8GetWarningStatus(WN_enTollGateFailPlsTake_4Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RoundaboutFailPlsTake = WN_API_u8GetWarningStatus(WN_enRoundaboutFailPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RoundaboutFailPlsTake_2Hz = WN_API_u8GetWarningStatus(WN_enRoundaboutFailPlsTake_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RoundaboutFailPlsTake_4Hz = WN_API_u8GetWarningStatus(WN_enRoundaboutFailPlsTake_4Hz);
	//Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontCarAttentionLeft = WN_API_u8GetWarningStatus(WN_enV2XFrontCarAttentionLeft);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontCarAttentionRight = WN_API_u8GetWarningStatus(WN_enV2XFrontCarAttentionRight);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UrgeTurnPlsHoldWheel = WN_API_u8GetWarningStatus(WN_enUrgeTurnPlsHoldWheel);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FastChrgFault = WN_API_u8GetWarningStatus(WN_enFastChrgFault);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHFailPlsFix = WN_API_u8GetWarningStatus(WN_enNOHFailPlsFix);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHFailPlsGearP = WN_API_u8GetWarningStatus(WN_enNOHFailPlsGearP);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveRampFailPlsHand = WN_API_u8GetWarningStatus(WN_enMoveRampFailPlsHand);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveMainFailPlsHand = WN_API_u8GetWarningStatus(WN_enMoveMainFailPlsHand);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnFailPlsHand = WN_API_u8GetWarningStatus(WN_enTurnFailPlsHand);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TollGateFailPlsHand = WN_API_u8GetWarningStatus(WN_enTollGateFailPlsHand);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RoundaboutFailPlsHand = WN_API_u8GetWarningStatus(WN_enRoundaboutFailPlsHand);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RePlanLanes = WN_API_u8GetWarningStatus(WN_enRePlanLanes);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsHandChangeLanes = WN_API_u8GetWarningStatus(WN_enPlsHandChangeLanes);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveRampFailHandWheel = WN_API_u8GetWarningStatus(WN_enMoveRampFailHandWheel);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveRampFailHandWheel_2Hz = WN_API_u8GetWarningStatus(WN_enMoveRampFailHandWheel_2Hz);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MoveMainFailHandWheel = WN_API_u8GetWarningStatus(WN_enMoveMainFailHandWheel);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnFailPlsHandWheel = WN_API_u8GetWarningStatus(WN_enTurnFailPlsHandWheel);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TollGateFailPlsHandWheel = WN_API_u8GetWarningStatus(WN_enTollGateFailPlsHandWheel);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RoundaboutFailPlsHandWheel = WN_API_u8GetWarningStatus(WN_enRoundaboutFailPlsHandWheel);
	//Secondary alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TJAICADisable = WN_API_u8GetWarningStatus(WN_enTJAICADisable);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LowSpeedLaneAssistDisable = WN_API_u8GetWarningStatus(WN_enLowSpeedLaneAssistDisable);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedLaneAssistDisable = WN_API_u8GetWarningStatus(WN_enOverSpeedLaneAssistDisable);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TJAICAFaultPlsFixCamera = WN_API_u8GetWarningStatus(WN_enTJAICAFaultPlsFixCamera);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TJAICAFaultPlsFix = WN_API_u8GetWarningStatus(WN_enTJAICAFaultPlsFix);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCChargeZoneFront = WN_API_u8GetWarningStatus(WN_enWPCChargeZoneFront);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCChargeZoneRear = WN_API_u8GetWarningStatus(WN_enWPCChargeZoneRear);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCChargeZoneRR = WN_API_u8GetWarningStatus(WN_enWPCChargeZoneRR);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WPCChargeZoneRL = WN_API_u8GetWarningStatus(WN_enWPCChargeZoneRL);
	//Tips
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AutoNaviExit = WN_API_u8GetWarningStatus(WN_enAutoNaviExit);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AcceleratorPowen = WN_API_u8GetWarningStatus(WN_enAcceleratorPowen);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnSafeSlow = WN_API_u8GetWarningStatus(WN_enTurnSafeSlow);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHExit = WN_API_u8GetWarningStatus(WN_enNOHExit);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHExitPlsTake = WN_API_u8GetWarningStatus(WN_enNOHExitPlsTake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHFinishExit = WN_API_u8GetWarningStatus(WN_enNOHFinishExit);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OverSpeedNOHExit = WN_API_u8GetWarningStatus(WN_enOverSpeedNOHExit);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DriveIntoHighSpeed = WN_API_u8GetWarningStatus(WN_enDriveIntoHighSpeed);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DriveIntoRamp = WN_API_u8GetWarningStatus(WN_enDriveIntoRamp);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHSetAccSpeed = WN_API_u8GetWarningStatus(WN_enNOHSetAccSpeed);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LockNGearDisable = WN_API_u8GetWarningStatus(WN_enLockNGearDisable);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsPressBrakeTest = WN_API_u8GetWarningStatus(WN_enPlsPressBrakeTest);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_4Aor4HModeSelect = WN_API_u8GetWarningStatus(WN_en4Aor4HModeSelect);

	//Update for Warning table v0.66
	//Special alarm
	//Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_BrakeSwitchFault = WN_API_u8GetWarningStatus(WN_enBrakeSwitchFault);
	//Secondary alarm
	//Tips
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SafeBackStart = WN_API_u8GetWarningStatus(WN_enSafeBackStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SafeBackStopCar = WN_API_u8GetWarningStatus(WN_enSafeBackStopCar);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SwitchGearReleaseBrake = WN_API_u8GetWarningStatus(WN_enSwitchGearReleaseBrake);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_MuddyStart = WN_API_u8GetWarningStatus(WN_enDM_EV_MuddyStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_SandStart = WN_API_u8GetWarningStatus(WN_enDM_EV_SandStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_EV_SportPlusStart = WN_API_u8GetWarningStatus(WN_enDM_EV_SportPlusStart);


    //Update for Warning table v0.71
    //Special alarm

    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_QuickChargeFlapOpenPicture = WN_API_u8GetWarningStatus(WN_enQuickChargeFlapOpenPicture);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowFillingFlapOpenPicture = WN_API_u8GetWarningStatus(WN_enSlowFillingFlapOpenPicture);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowFillingFlapNotClosed = WN_API_u8GetWarningStatus(WN_enSlowFillingFlapNotClosed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_QuickChargeFlapNotClosed = WN_API_u8GetWarningStatus(WN_enQuickChargeFlapNotClosed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionWaterRoad = WN_API_u8GetWarningStatus(WN_enAttentionWaterRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionLowlyingRoad = WN_API_u8GetWarningStatus(WN_enAttentionLowlyingRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionWetRoad = WN_API_u8GetWarningStatus(WN_enAttentionWetRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionSharpTurn = WN_API_u8GetWarningStatus(WN_enAttentionSharpTurn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteRoadFailure = WN_API_u8GetWarningStatus(WN_enNoteRoadFailure);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteUnevenRoad = WN_API_u8GetWarningStatus(WN_enNoteUnevenRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionDangerousRoad = WN_API_u8GetWarningStatus(WN_enAttentionDangerousRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AwareDebrisFlow = WN_API_u8GetWarningStatus(WN_enAwareDebrisFlow);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteBridge = WN_API_u8GetWarningStatus(WN_enNoteBridge);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AttentionTunnel = WN_API_u8GetWarningStatus(WN_enAttentionTunnel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AwareFire = WN_API_u8GetWarningStatus(WN_enAwareFire);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteFallingRock = WN_API_u8GetWarningStatus(WN_enNoteFallingRock);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteIcyRoad = WN_API_u8GetWarningStatus(WN_enNoteIcyRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteCrosswindRoad = WN_API_u8GetWarningStatus(WN_enNoteCrosswindRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EmbankmentRoad = WN_API_u8GetWarningStatus(WN_enEmbankmentRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteContinuousSharpTurn = WN_API_u8GetWarningStatus(WN_enNoteContinuousSharpTurn);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteRoadNarrows = WN_API_u8GetWarningStatus(WN_enNoteRoadNarrows);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoteIncomingTraffic = WN_API_u8GetWarningStatus(WN_enNoteIncomingTraffic);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NotedamgeRoadFacities = WN_API_u8GetWarningStatus(WN_enNotedamgeRoadFacities);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AwareScatteredObject = WN_API_u8GetWarningStatus(WN_enAwareScatteredObject);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHIsResumed = WN_API_u8GetWarningStatus(WN_enNOHIsResumed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_MargeWatchOutFOrCarsComing = WN_API_u8GetWarningStatus(WN_enMargeWatchOutFOrCarsComing);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SlowingDownForDischarge = WN_API_u8GetWarningStatus(WN_enSlowingDownForDischarge);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOExitedTakeSteeringWheel = WN_API_u8GetWarningStatus(WN_enNOExitedTakeSteeringWheel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LaneLineNotClearDriveCarefully = WN_API_u8GetWarningStatus(WN_enLaneLineNotClearDriveCarefully);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FourWheelDriveSystem = WN_API_u8GetWarningStatus(WN_enFourWheelDriveSystem);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CatcherSeriouslyBlocked = WN_API_u8GetWarningStatus(WN_enCatcherSeriouslyBlocked);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargingStatusDisplay = WN_API_u8GetWarningStatus(WN_enChargingStatusDisplay);
    
    //Secondary alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ExcessiveSpeedFourWheelDrive = WN_API_u8GetWarningStatus(WN_enExcessiveSpeedFourWheelDrive);
   
    //info
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NavigationSlowDownActive = WN_API_u8GetWarningStatus(WN_enNavigationSlowDownActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PlsPayAttentionToSlowDown = WN_API_u8GetWarningStatus(WN_enPlsPayAttentionToSlowDown);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward60kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward60kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward70kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward70kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SPeedLimitForward80kmPerHour = WN_API_u8GetWarningStatus(WN_enSPeedLimitForward80kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward90kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward90kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward100kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward100kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward110kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward110kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SpeedLimitForward120kmPerHour = WN_API_u8GetWarningStatus(WN_enSpeedLimitForward120kmPerHour);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CurrentlyExceedNavigationLimit = WN_API_u8GetWarningStatus(WN_enCurrentlyExceedNavigationLimit);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TurnGearDownConfirmSpeedAdjustment = WN_API_u8GetWarningStatus(WN_enTurnGearDownConfirmSpeedAdjustment);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PressCruiseConfirmAdjustment = WN_API_u8GetWarningStatus(WN_enPressCruiseConfirmAdjustment);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ComingOutMainRoad = WN_API_u8GetWarningStatus(WN_enComingOutMainRoad);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GoddessModeActivated = WN_API_u8GetWarningStatus(WN_enGoddessModeActivated);


	//Update for Warning table v0.71 official version R15
    //Special alarm

    //Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_WshngLiquidNotEnough = WN_API_u8GetWarningStatus(WN_enWshngLiquidNotEnough);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaInsCantStartAfter = WN_API_u8GetWarningStatus(WN_enUreaInsCantStartAfter);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaInsSeriouslyCantStartAfter = WN_API_u8GetWarningStatus(WN_enUreaInsSeriouslyCantStartAfter);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaEmptyCantStartNext = WN_API_u8GetWarningStatus(WN_enUreaEmptyCantStartNext);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaEmptyCantStart = WN_API_u8GetWarningStatus(WN_enUreaEmptyCantStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaUnqualifyCantStartAfter = WN_API_u8GetWarningStatus(WN_enUreaUnqualifyCantStartAfter);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaUnqualifyCantStartNext = WN_API_u8GetWarningStatus(WN_enUreaUnqualifyCantStartNext);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaUnqualifyCantStart = WN_API_u8GetWarningStatus(WN_enUreaUnqualifyCantStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaFillStopCantStartAfter = WN_API_u8GetWarningStatus(WN_enUreaFillStopCantStartAfter);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaFillStopCantStartNext = WN_API_u8GetWarningStatus(WN_enUreaFillStopCantStartNext);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaFillStopCantStart = WN_API_u8GetWarningStatus(WN_enUreaFillStopCantStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ConsumDeviatCantStartAfter = WN_API_u8GetWarningStatus(WN_enConsumDeviatCantStartAfter);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ConsumDeviatCantStartNext = WN_API_u8GetWarningStatus(WN_enConsumDeviatCantStartNext);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ConsumDeviatCantStart = WN_API_u8GetWarningStatus(WN_enConsumDeviatCantStart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_HoodClosedRestart = WN_API_u8GetWarningStatus(WN_enHoodClosedRestart);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_OilTankClosedRestart = WN_API_u8GetWarningStatus(WN_enOilTankClosedRestart);

	//Secondary alarm

	//info
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FaceFail = WN_API_u8GetWarningStatus(WN_enFaceFail);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FaceInforNotEntered = WN_API_u8GetWarningStatus(WN_enFaceInforNotEntered);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CSTActive = WN_API_u8GetWarningStatus(WN_enCSTActive);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CSTClosed = WN_API_u8GetWarningStatus(WN_enCSTClosed);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EVModeBattPowerLow = WN_API_u8GetWarningStatus(WN_enEVModeBattPowerLow);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ConnectedDischarging = WN_API_u8GetWarningStatus(WN_enConnectedDischarging);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ConnectedNoDischarge = WN_API_u8GetWarningStatus(WN_enConnectedNoDischarge);
	
	//Update for Warning table v0.72 official version R16
	
    //Special alarm
    
    //Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontTireAutoBack = WN_API_u8GetWarningStatus(WN_enFrontTireAutoBack);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SteeringAutomaFuncsExits = WN_API_u8GetWarningStatus(WN_enSteeringAutomaFuncsExits);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_EmergencyCallLimited = WN_API_u8GetWarningStatus(WN_enEmergencyCallLimited);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerLowStartEngine = WN_API_u8GetWarningStatus(WN_enPowerLowStartEngine);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FailedActivateDischarge = WN_API_u8GetWarningStatus(WN_enFailedActivateDischarge);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerSystemLimited = WN_API_u8GetWarningStatus(WN_enPowerSystemLimited);

	 //Secondary alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearWheelSteeringFailure = WN_API_u8GetWarningStatus(WN_enRearWheelSteeringFailure);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_RearWheelSteeringLimited = WN_API_u8GetWarningStatus(WN_enRearWheelSteeringLimited);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ETCSystemFault = WN_API_u8GetWarningStatus(WN_enETCSystemFault);

	 //info
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DischargeDeviceRemoved = WN_API_u8GetWarningStatus(WN_enDischargeDeviceRemoved);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ETCNormal = WN_API_u8GetWarningStatus(WN_enETCNormal);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ETCAbnormal = WN_API_u8GetWarningStatus(WN_enETCAbnormal);
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ExpresswayNormal = WN_API_u8GetWarningStatus(WN_enExpresswayNormal);

    //Warning Data
    if(ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TargetCruiseSpeed == WN_enDISPLAY_OFF)
    {
        ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TgtCrsSpdData = 0;
    }
    else
    {
        ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TgtCrsSpdData = WN_CFG_vGetCruiseSpeed();
    }
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_TgtCrsSpdVld = WN_CFG_vGetCruiseSpeedVld();
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DrvModeCase = WN_CFG_vGetDrvModeCase();
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NOHDistData = WN_CFG_vGetNOH_DistToExit();
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_V2XFrontRoadData = WN_CFG_vGetV2XFrontRoadData();//R11
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AccSpdSetValue = WN_CFG_vGetACC_SpdSetValue();//R11
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_UreaRemainDistData = WN_CFG_vGetUreaRemainDistData();//R15
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PressReliProgsData = WN_CFG_vGetWN_PressReliProgsData();
	

	//Update for Warning table v0.73 official version R17

    //Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DisconnectChargingDischarging = WN_API_u8GetWarningStatus(WN_enDisconnectChargingDischarging);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerOffAfterThreeMinute = WN_API_u8GetWarningStatus(WN_enPowerOffAfterThreeMinute);

    //Secondary alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargerFailure = WN_API_u8GetWarningStatus(WN_enChargerFailure);

    //Tips
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CurrentTerrainCannotUnlocked = WN_API_u8GetWarningStatus(WN_enCurrentTerrainCannotUnlocked);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerBattWarmup = WN_API_u8GetWarningStatus(WN_enPowerBattWarmup);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCCCActive = WN_API_u8GetWarningStatus(WN_enACCCCActive);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ACCCCCancel = WN_API_u8GetWarningStatus(WN_enACCCCCancel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PleaseReadUserManual = WN_API_u8GetWarningStatus(WN_enPleaseReadUserManual);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoviceModel = WN_API_u8GetWarningStatus(WN_enNoviceModel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoviceModelSelect = WN_API_u8GetWarningStatus(WN_enNoviceModelSelect);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_NoviceModelSwitch = WN_API_u8GetWarningStatus(WN_enNoviceModelSwitch);

    //Update for Warning table v0.74 official version R18
    //Special alarm

    //Important alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CrabModeFailure = WN_API_u8GetWarningStatus(WN_enCrabModeFailure);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FrontTireAlignFinishGEEP40 = WN_API_u8GetWarningStatus(WN_enFrontTireAlignFinishGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FactoryPatternGEEP40 = WN_API_u8GetWarningStatus(WN_enFactoryPatternGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_GalleryMode = WN_API_u8GetWarningStatus(WN_enGalleryMode);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowTranModeGEEP40 = WN_API_u8GetWarningStatus(WN_enStatBattLowTranModeGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowComfortOffGEEP40 = WN_API_u8GetWarningStatus(WN_enStatBattLowComfortOffGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowSavingModeGEEP40 = WN_API_u8GetWarningStatus(WN_enStatBattLowSavingModeGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_PowerOffAfterThreeMinuteGEEP40 = WN_API_u8GetWarningStatus(WN_enPowerOffAfterThreeMinuteGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ChargingCoverOpen = WN_API_u8GetWarningStatus(WN_enChargingCoverOpen);

    //Secondary alarm
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_StatBattLowPwrReduceGEEP40 = WN_API_u8GetWarningStatus(WN_enStatBattLowPwrReduceGEEP40);

    //info
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_InboundFailedContinueCruise = WN_API_u8GetWarningStatus(WN_enInboundFailedContinueCruise);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_ApproachingRamp = WN_API_u8GetWarningStatus(WN_enApproachingRamp);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CrabModeExitedGEEP40 = WN_API_u8GetWarningStatus(WN_enCrabModeExitedGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_CrabModeEnabledGEEP40 = WN_API_u8GetWarningStatus(WN_enCrabModeEnabledGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t. WN_CrabModeStandbyGEEP40 = WN_API_u8GetWarningStatus(WN_enCrabModeStandbyGEEP40);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LowBatteryStartVehicle = WN_API_u8GetWarningStatus(WN_enLowBatteryStartVehicle);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_LowBatteryPlugGunCharge = WN_API_u8GetWarningStatus(WN_enLowBatteryPlugGunCharge);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_AuxiliaryOpenSingPedalUnable = WN_API_u8GetWarningStatus(WN_enAuxiliaryOpenSingPedalUnable);

    //Update for Warning table v0.75 official version R19
    //Special alarm  
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SmartCruiseouteEmergencyBrake = WN_API_u8GetWarningStatus(WN_enSmartCruiseouteEmergencyBrake);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SteerFailDrivelowSpeed = WN_API_u8GetWarningStatus(WN_enSteerFailDrivelowSpeed);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SteerFailDriveCarefully = WN_API_u8GetWarningStatus(WN_enSteerFailDriveCarefully);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SteeringAutoNotTouchWheel = WN_API_u8GetWarningStatus(WN_enSteeringAutoNotTouchWheel);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_SteeringWheelAutoaLigned = WN_API_u8GetWarningStatus(WN_ensteeringWheelAutoaLigned);
    ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_DM_B30_Novice = WN_API_u8GetWarningStatus(WN_enDM_B30_Novice);

	//Update for D01-2683 
    //Important alarm
	ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t.WN_FuelPrepare_Sound = WN_API_u8GetWarningStatus(WN_enFuelPrepare_Sound);

    //send warning status to output
    (void)Rte_Write_ppSR_SWCNormal_WarningStsOutput_Element((const WN_WarningStsOutput *)&ToSBUS_WN_status32.u_WN_Moduleu32Warning_status_t.s_u32Warning_status_t);
    //send ToSBUS_WN_status32 to SOC
    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_WARNING,(uint8 *)&ToSBUS_WN_status32,(uint16)sizeof(IPC_M2S_ClusterAppAPPWN_Module_t),FALSE);
    // if (memcmp(&ToSBUS_WN_status32, &ToSBUS_WN_status32_pre, sizeof(ToSBUS_WN_status32)) != 0)
    // {
    //     IPC_M2S_ClusterAppAPPWN_Module_Transmit(&ToSBUS_WN_status32);
    //     memcpy(&ToSBUS_WN_status32_pre, &ToSBUS_WN_status32, sizeof(ToSBUS_WN_status32));
    // }

}
#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
uint32 WN_CFG_vGetPowerModeSts(void)
{
    return WN__stMainObject.unPowerModeStatus.u32PowerModeStatus;
}
/**********************************************************************************************************
*Function   : WN__boSBUSTimeTaskOperation                                                                 *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : BOOL                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2018-01-16                                                                                  *
**********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean WN__boSBUSTaskOperation(void)
{

   WN__vSBUSUpdateMessage();

    return TRUE;
}
#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*Function   : WN__vSetAllWarningToDefault                                                                 *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-11-15                                                                                  *
**********************************************************************************************************/
static void WN__vSetAllWarningToDefault(void)
{
    uint16 u8Index;

    for(u8Index=0; u8Index < WN_enWARNING_TOTAL_NUMBER; u8Index++)
    {
        WN__stMainObject.stWarningControlStatus[u8Index].unStatus.stStatus.LogicType = WN_DEFAULT_STATUS;
        WN__stMainObject.stWarningControlStatus[u8Index].unStatus.stStatus.ResultLogicType = WN_DEFAULT_STATUS;
        WN__stMainObject.stWarningControlStatus[u8Index].unStatus.stStatus.LastLogicType = WN_DEFAULT_STATUS;
        WN__stMainObject.stWarningControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
        WN__stMainObject.stWarningControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 0;
    }
}
/**********************************************************************************************************
*Function   : WN__vSystemErrorObjectOperationProcess                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2017-11-15                                                                                  *
**********************************************************************************************************/
static void WN__vSystemErrorObjectOperationProcess(void)
{
    WN__vSetAllWarningToDefault();

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
    /*Send CAN message*/
    WN__vCANOutputUpdateMessage();
#endif

#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
    /*Send SBUS message*/
    WN__vSBUSUpdateMessage();
#endif

}

void WN_API_Set_PrePowerMode_Status(void)
{
    (void)WN__boWarningControlProcess();
    WN__vSBUSUpdateMessage();
}
#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/**********************************************************************************************************
*  End Of File                                                                                            *
**********************************************************************************************************/
