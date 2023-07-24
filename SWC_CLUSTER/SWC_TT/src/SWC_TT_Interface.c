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
*File Name   : TT_Interface.c                                                                             *
*                                                                                                         *
*Description : Telltale module interface function source file.                                            *
*                                                                                                         *
*Author      : Chao Feng                                                                                  *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
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
#include <string.h>
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"
#include "VConfig.h"
#include "IPC_ClusterApp.h"
#include "SWC_IPC_Config.h"
#include "SWC_Chime_Adapt.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TT_Interface.h"
#include "SWC_TT_Core.h"
#include "SWC_TT_MemMap.h"
#include "SWC_TT_Adapt.h"
#include "SWC_TT_Safety_Adaptor.h"


#define FTT_GET_Report_DID(TelltaleID) \
		(TT__stMainObject.stTelltaleControlStatus[TelltaleID].unStatus.stStatus.Vehselfchecksts)


/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Main Object Structure Variable															      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static IPC_M2S_ClusterAppAPPTT_Module_t ToSBUS_TT_status32;

//static IPC_M2S_ClusterAppAPPTT_Module_t ToSBUS_TT_status32_Pre;
//Telltale_Sts32 ToSBUS_TT_status32_backup;
static IPC_M2S_ClusterAppAPPVConfig_t ToSBUS_TT_VConfig;

static TT_tstMainObject TT__stMainObject ;
static uint8 u8PrePowerMode;
#define SWC_TT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Logic Process Attribute Table Const															          *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"
static const TT_tstLogicProcessAttribute TT__cstLogicProcessAttribute[] = TT_CFG_LOGIC_PROCESS_ATTRIBUTE;


/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Attribute Table Const															              *
*																								          *
*																								          *
**********************************************************************************************************/

static const TT_tstTelltaleAttribute TT__cstTelltaleAttribute[TT_enTELLTALE_TOTAL_NUMBER] = TT_CFG_TELLTALE_CONTROL_ATTRIBUTE;

/**********************************************************************************************************
*																								          *
*																								          *
*	Flash Attribute Table Const          															      *
*																								          *
*																								          *
**********************************************************************************************************/

static const TT_tstFlashAttribute TT__cstFlashAttribute[TT_enSTATUS_TOTAL_NUMBER - TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER] = TT_CFG_FLASH_ATTRIBUTE;

static const TT_CFG_enTelltaleID FTT__SelfcheckReport[FTT_CFG_SelfcheckReport_COUNT + 1] = FTT_CFG_SelfcheckReport_LIST;
static const TT_CFG_enTelltaleID FTT__SelfcheckReport2[FTT_CFG_SelfcheckReport_COUNT2 + 1] = FTT_CFG_SelfcheckReport_LIST2;

#define SWC_TT_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"


#define SWC_TT_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static uint8 u8SelfcheckReportsts = 1;
static boolean FTT_boSelfcheckReportsts = FALSE;
static boolean TT_boSelfcheckReportsts = FALSE;

#define SWC_TT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Common Static Function																          *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

static boolean TT__boCheckPowerMode(void);

static void TT__vPowerModeErrorProcess(void);

static boolean TT__boCheckExternalControl(void);

static boolean TT__boCheckResponseDelayStatus(void);

static boolean TT__boResponseDelayStatusTickPlus(void);

static boolean TT__boCalculateFlashReferenceStatus(void);

static boolean TT__boFlashReferenceTickPlus(void);

static boolean TT__boTimeTaskLogicProcess(void);

static boolean TT__boTelltaleLightControlProcess(void);

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)

static void TT__vCANOutputUpdateMessage(void);

static boolean TT__boCANOutputTaskOperation(void);

#endif //((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)

static void TT__vSBUSUpdateMessage(void);

static boolean TT__boSBUSTaskOperation(void);

#endif //((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)

static void TT__vForceAllTelltaleClose(void);

static void TT__vSystemErrorObjectOperationProcess(void);

static void TT_vSwitchAllTelltale_Function(TT_CFG_enStatusType boTelltaleStatus);
static void FTT_SBUSUpdateVConfig(void);
//extern boolean STT_boSendSelfcheckReportsts(void);

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Custom Static Function																          *
*																								          *
*																								          *
**********************************************************************************************************/

//None

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Process Map																			      *
*																								          *
*																								          *
**********************************************************************************************************/
#define SWC_TT_START_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"

/*************************************************************************************************************************************************************************************************************/
/*ProcessName               Process                                SucceedEnable      FaildEnable           AfterSucceed    AfterFaild                   ContinueWhen
                                                                   Status             Status                Operation       Operation                    Faild       */
static const TT_tstPROCESS TT_stTimeTask_ProcessTable[] = {
/*Power Mode */           { TT__boCheckPowerMode , 	               TT_KEEP_PREVIOUS , TT_POWER_MODE_ERROR ,	TT_DO_NOTHING ,	TT__vPowerModeErrorProcess , TT_CFG_OFF			},
/*External Control */ 	  { TT__boCheckExternalControl ,           TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON			},
/*Response Delay */       { TT__boCheckResponseDelayStatus ,       TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON 			},
/*Flash Status */         { TT__boCalculateFlashReferenceStatus ,  TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON 			},
/*Response Delay */ 	  { TT__boResponseDelayStatusTickPlus ,    TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,	TT_DO_NOTHING , TT_DO_NOTHING , 			 TT_CFG_ON			},
/*Flash Status */		  { TT__boFlashReferenceTickPlus ,         TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,	TT_DO_NOTHING , TT_DO_NOTHING , 			 TT_CFG_ON			},
/*Logic Process*/         { TT__boTimeTaskLogicProcess ,           TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON 			},
/*Light Control*/         { TT__boTelltaleLightControlProcess ,    TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON 			},
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
/*CAN Output Operation*/  { TT__boCANOutputTaskOperation ,         TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,	TT_DO_NOTHING , TT_DO_NOTHING , 			 TT_CFG_ON			},
#endif
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
/*SBUS Operation*/        { TT__boSBUSTaskOperation ,              TT_KEEP_PREVIOUS , TT_KEEP_PREVIOUS ,    TT_DO_NOTHING , TT_DO_NOTHING ,              TT_CFG_ON 			},
#endif
                          { (void *)0,(TT_enSystemStatus)0,(TT_enSystemStatus)0,(void *)0,(void *)0,TT_CFG_OFF},\
                          };
/*************************************************************************************************************************************************************************************************************/
#define SWC_TT_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_TT_MemMap.h"
/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Interface Function For DI Kennel System												      *
*																								          *
*																								          *
**********************************************************************************************************/

#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*Function   : TT_API_vKSTimeTask                                                                          *
*                                                                                                         *
*Description: The functions is called by DI-kernel at time task list at cycle 20ms.                       *
*			  which is the main handling task of Telltale module .                                        *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSTimeTask(void)
{
#if (TT_CFG_TELLTALE_FUNCTION == TRUE)
    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        TT_CORE_vProcessControl(TT_stTimeTask_ProcessTable,&TT__stMainObject);
    }
    else
    {
        TT__vSystemErrorObjectOperationProcess();
    }

	TT__vTimeTaskLoopRollingCount(&TT__stMainObject);
#endif
}
/**********************************************************************************************************
*Function   : TT_API_vKSColdInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at cold init task list,which do global variables        *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSColdInit(void)
{
    //Avoid Warning
    (void)memset(&TT__stMainObject,0,sizeof(TT_tstMainObject));
    TT_CORE_vSetSystemStatus(TT_SYSTEM_DEFAULT,&TT__stMainObject);

    TT_CORE_vClearSystemStatus(TT_SYSTEM_DEFAULT,&TT__stMainObject);

    (void)TT_CORE_boCheckSystemStatus(TT_SYSTEM_DEFAULT,&TT__stMainObject);
    TT__stMainObject.unPowerModeStatus.u32PowerModeStatus = 1;
#if (TT_CFG_TELLTALE_FUNCTION == TRUE)
#if(TT_CFG_DEBUG == TRUE)
printf("\
------------------------------------------------------------\r\n\
--Telltale Module Debug Mode Enable-------------------------\r\n\
------------------------------------------------------------\r\n");

    TT_CORE_vCheckModuleConfigration();

	TT_CORE_vDebugModeOperation(&TT__stMainObject);

#endif

	TT_CORE_vSetFlashStatusOffset(&TT__cstFlashAttribute[0],&TT__stMainObject);

    TT_CORE_vCalculateDelayTimerMaxCount(&TT__cstTelltaleAttribute[0],&TT__stMainObject);

    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Set Flag*/
        TT_CORE_vFlagControl(TT_COLD_INIT,&TT__stMainObject);

        /*Set Timer default value*/
        TT__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = TT__stMainObject.stCount.u16ExitAbnormalResponseDelayMaxTickCount;
        TT_CORE_vStopAllTelltaleSelfCheck(&TT__stMainObject);

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
        /*Send CAN message*/
        TT__vCANOutputUpdateMessage();
#endif

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
        /*Send SBUS message*/
        TT__vSBUSUpdateMessage();
#endif

    }
    else //System faild,do nothing
    {

    }

#endif
}
/**********************************************************************************************************
*Function   : TT_API_vKSWarmInit                                                                          *
*                                                                                                         *
*Description: The function is called by DI-kernel at warm init task list,which do global variables        *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSWarmInit(void)
{
#if (TT_CFG_TELLTALE_FUNCTION == TRUE)
#if(TT_CFG_DEBUG == TRUE)

	TT_CORE_vDebugModeOperation(&TT__stMainObject);

#endif

	TT_CORE_vSetFlashStatusOffset(&TT__cstFlashAttribute[0],&TT__stMainObject);

    TT_CORE_vCalculateDelayTimerMaxCount(&TT__cstTelltaleAttribute[0],&TT__stMainObject);



    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Set Flag*/
        TT_CORE_vFlagControl(TT_WARM_INIT,&TT__stMainObject);

        /*Set Timer default value*/
        TT__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = TT__stMainObject.stCount.u16ExitAbnormalResponseDelayMaxTickCount;
        TT_CORE_vStopAllTelltaleSelfCheck(&TT__stMainObject);

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
        /*Send CAN message*/
        TT__vCANOutputUpdateMessage();
#endif

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
        /*Send SBUS message*/
        TT__vSBUSUpdateMessage();
#endif

    }
    else //System faild,do nothing
    {

    }

#endif
}
/**********************************************************************************************************
*Function   : TT_API_vKSWakeUp                                                                            *
*                                                                                                         *
*Description: The function is called by DI-kernel at wake up task list,which do global variables          *
*			  initialization and flags clearing .                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
void TT_API_vKSWakeUp(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == TRUE)
    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Set Flag*/
        TT_CORE_vFlagControl(TT_WAKE_UP,&TT__stMainObject);

    }
    else //System faild,do nothing
    {

    }
#endif
}
#endif
/**********************************************************************************************************
*Function   : TT_API_vKSSleep                                                                             *
*                                                                                                         *
*Description: The function is called by DI-kernel at sleep task list,which do global variables            *
*			  initialization and flags clearing                                                           *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
void TT_API_vKSSleep(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == TRUE)
    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Set Flag*/
        TT_CORE_vFlagControl(TT_SLEEP,&TT__stMainObject);

    }
    else //System faild,do nothing
    {

    }
#endif
}
#endif
/**********************************************************************************************************
*Function   : TT_API_vKSEnterAbnormalOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSEnterAbnormalOperation(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == TRUE)
    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Function flag control*/
        TT_CORE_vFlagControl(TT_ENTER_ABNORMAL,&TT__stMainObject);

    }
    else
    {
		/*System Faild,do nothing*/
    }
#endif
}

/**********************************************************************************************************
*Function   : TT_API_vKSEnterPowerStatusOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_Set_PreOffPowerMode_Status(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == FALSE)

    uint8 u8Index = 0;
    for(u8Index=0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
        TT__vCheckPowerModeCondition(&TT__stMainObject.stTelltaleControlStatus[u8Index],&TT__cstTelltaleAttribute[u8Index]/*,&TT__stMainObject*/);
    }

#endif

#if(TT_CFG_TELLTALE_FUNCTION == TRUE)
    uint8 u8Index = 0;
    for(u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
        TT__vCheckPowerModeCondition(&TT__stMainObject.stTelltaleControlStatus[u8Index],&TT__cstTelltaleAttribute[u8Index]/*,&TT__stMainObject*/);
    }
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPS_Yellow_Error_Data = 0;
    TT__vSBUSUpdateMessage();
    u8PrePowerMode = 1;
#endif
}

/**********************************************************************************************************
*Function   : TT_API_vKSEnterPowerStatusOperation                                                            *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when trans into abnormal  *
*             state from normal/limited mode                                                              *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_Set_PreOnPowerMode_Status(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == FALSE)

    uint8 u8Index = 0;
    for(u8Index=0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
        TT__vCheckPowerModeCondition(&TT__stMainObject.stTelltaleControlStatus[u8Index],&TT__cstTelltaleAttribute[u8Index]/*,&TT__stMainObject*/);
    }

#endif

#if(TT_CFG_TELLTALE_FUNCTION == TRUE)

    //u8PrePowerMode = SYSTEMSTATE_Cluster_ON;

#endif
}
/**********************************************************************************************************
*Function   : TT_API_vKSExitAbnormalOperation                                                             *
*                                                                                                         *
*Description: The function is called by Power management module to do operation when MCU exits the        *
*             abnormal mode                                                                               *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vKSExitAbnormalOperation(void)
{
#if(TT_CFG_TELLTALE_FUNCTION == TRUE)
    if(FALSE == TT_CORE_boCheckSystemStatus(TT_SYSTEM_FAILD,&TT__stMainObject))
    {
        /*Function flag control*/
        TT_CORE_vFlagControl(TT_EXIT_ABNORMAL,&TT__stMainObject);
        /*Clear time tick*/
        TT__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = 0;
    }
    else
    {
		/*System Faild,do nothing*/
    }
#endif
}
/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Application Interface Function 														      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TT_API_vSingleTelltaleControl                                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (void) *vptrTelltaleLogicOperation                                                          *
*             (UINT8) u8TelltaleID                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vSingleTelltaleControl(void *vptrTelltaleLogicOperation,TT_CFG_enTelltaleID enTelltaleID)
{
	if(enTelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
    {

		TT_CORE_vSingleLogicProcess(vptrTelltaleLogicOperation,&TT__cstLogicProcessAttribute[0],&TT__stMainObject);

		TT_CORE_vSingleTelltaleLightControl(&TT__stMainObject.stTelltaleControlStatus[enTelltaleID],&TT__cstTelltaleAttribute[enTelltaleID],&TT__stMainObject);


	}
    else
    {
        /*Do nothing because request telltale ID out of bound */
    }
}
/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleStatus                                                                  *
*                                                                                                         *
*Description: The function is used to get current telltale flash status .                                 *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if 0
TT_CFG_enStatusType TT_API_u8GetTelltaleStatus(TT_CFG_enTelltaleID u8TelltaleID)
{
	TT_CFG_enStatusType u8Return;

	if(u8TelltaleID < TT_enTELLTALE_TOTAL_NUMBER)
	{
		if(TT__stMainObject.stTelltaleControlStatus[u8TelltaleID].unStatus.stStatus.ExternalControlStatus)
		{
			u8Return = TT_CORE_u8GetTelltaleExternalLogicStatus(u8TelltaleID,&TT__stMainObject);
		}
		else
		{
			u8Return = TT_CORE_u8GetTelltaleResultLogicStatus(u8TelltaleID,&TT__stMainObject);
		}

	}
	else
	{
		/*Return default value because request telltale ID out of bound */
		u8Return = TT_enTURN_OFF;
	}

#if ((TT_CFG_OUTPUT_MODE == TT_CFG_OUTPUT_ON_SBUS)||(TT_CFG_OUTPUT_MODE == TT_CFG_OUTPUT_USE_GPIO))
		if( u8Return >= TT_enSELF_CHECK )
		{
			u8Return--;
		}
#endif

    return(u8Return);
}
#endif
/**********************************************************************************************************
*Function   : TT_API_enGetTelltaleCurrentStatus                                                           *
*                                                                                                         *
*Description: The function is used to get current telltale flash status .                                 *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: Flash status type                                                                           *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_CFG_enStatusType TT_API_enGetTelltaleCurrentStatus(TT_CFG_enTelltaleID enTelltaleID)
{
    TT_CFG_enStatusType enReturn;

    if(TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExternalControlStatus)
	{
		enReturn = TT_CORE_u8GetTelltaleExternalLogicStatus(enTelltaleID,&TT__stMainObject);
	}
	else
	{
		enReturn = TT_CORE_u8GetTelltaleResultLogicStatus(enTelltaleID,&TT__stMainObject);
	}

    return(enReturn);
}
/**********************************************************************************************************
*Function   : TT_API_enGetLampStatus                                                                      *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_API_enGetLampStatus(TT_CFG_enTelltaleID enTelltaleID)
{
    return (TT_CORE_enGetLampStatus(enTelltaleID,&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_boGetLampOnOffStatus                                                                 *
*                                                                                                         *
*Description: The function is used to get current lamp status of telltale                                 *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetLampOnOffStatus(TT_CFG_enTelltaleID enTelltaleID)
{
    return (TT_CORE_boGetLampOnOffStatus(enTelltaleID,&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleLightCountStatus                                                        *
*                                                                                                         *
*Description: The function is used to get current telltale light count status .                           *
*			                                                                                              *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetTelltaleFlashFinishStatus(TT_CFG_enTelltaleID enTelltaleID)
{
	return(TT_CORE_boGetTelltaleFlashFinishStatus(enTelltaleID,&TT__cstTelltaleAttribute[0],&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_vSetTelltaleExternalControlStatus                                                    *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (TT_CFG_enTelltaleID) u8TelltaleID                                                          *
*             (TT_CFG_enStatusType) u8LogicStatus                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vSetTelltaleExternalControlStatus(uint8 enTelltaleID,TT_CFG_enStatusType enLogicStatus)
{
	TT_CORE_vTelltaleExternalControlEnable(enTelltaleID,&TT__stMainObject);

	TT_CORE_vSetTelltaleExternalControlStatus(enTelltaleID,enLogicStatus,&TT__stMainObject);
}
/**********************************************************************************************************
*Function   : TT_API_vReleaseTelltaleExternalControl                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TT_API_vReleaseTelltaleExternalControl(TT_CFG_enTelltaleID enTelltaleID)
{
    TT_CORE_vTelltaleExternalControlDisable(enTelltaleID,&TT__stMainObject);
}
/**********************************************************************************************************
*Function   : TT_API_u8GetTelltaleExternalControlStatus                                                   *
*                                                                                                         *
*Description: The function is used to get current telltale external control status .                      *
*			                                                                                              *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_u8GetTelltaleExternalControlStatus(TT_CFG_enTelltaleID enTelltaleID)
{
    return(TT_CORE_boGetTelltaleExternalControlStatus(enTelltaleID,&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_enGetFlashTypeStatus                                                                 *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: TT_enLampStatus                                                                             *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
TT_enLampStatus TT_API_enGetFlashTypeStatus(TT_CFG_enStatusType enStatusTypeID)
{
    return (TT_CORE_enGetFlashTypeStatus(enStatusTypeID,&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_boGetFlashTypeOnOffStatus                                                            *
*                                                                                                         *
*Description: The function is used to get current lamp status of flash type                               *
*			                                                                                              *
*Parameter	: (TT_CFG_enStatusType) u8TelltaleID	                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetFlashTypeOnOffStatus(TT_CFG_enStatusType enStatusTypeID)
{
    return (TT_CORE_boGetFlashTypeOnOffStatus(enStatusTypeID,&TT__stMainObject));
}
/**********************************************************************************************************
*Function   : TT_API_boGetSingleTelltaleResponseDelayStatus                                               *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetSingleTelltaleResponseDelayStatus(TT_CFG_enStatusType enTelltaleID)
{
    boolean boReturn;

    if(enTelltaleID >= TT_enTELLTALE_TOTAL_NUMBER)
    {
        /*Return default value because request telltale ID out bound */
        boReturn = FALSE;
    }
    else if(TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.SelfCheckStatus)
    {
        boReturn = TRUE;
    }
    else if(TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.IgnitionOnResponseDelayStatus)
    {
        boReturn = TRUE;
    }
    else if(TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.ExitAbnormalDelayStatus)
    {
        boReturn = TRUE;
    }
    else
    {
        boReturn = FALSE;
    }
    return(boReturn);
}
/**********************************************************************************************************
*Function   : TT_API_boGetSingleTelltaleSelfCheckStatus                                                   *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
boolean TT_API_boGetSingleTelltaleSelfCheckStatus(TT_CFG_enTelltaleID enTelltaleID)
{
	boolean boReturn;

	if(enTelltaleID >= TT_enTELLTALE_TOTAL_NUMBER)
	{
		/*Return default value because request telltale ID out bound */
		boReturn = FALSE;
	}
	else if((1 == TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.SelfCheckStatus) && (1 == TT__stMainObject.stTelltaleControlStatus[enTelltaleID].unStatus.stStatus.DidConfigEnable))
	{
		boReturn = TRUE;
	}
	else
	{
		boReturn = FALSE;
	}
	return(boReturn);
}
#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*																								          *
*																								          *
*	Telltale Private Function 																		      *
*																								          *
*																								          *
**********************************************************************************************************/

/**********************************************************************************************************
*Function   : TT__boCheckPowerMode                                                                        *
*                                                                                                         *
*Description: The function is used to check power mode which status can telltale work .                   *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: Process return status . If power mode get faild , retuen FALSE .                            *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/

#define SWC_TT_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"

static boolean IGN_OFF_Flag = FALSE;
static uint8 sync_flag = FALSE;
static uint8 last_sync = FALSE;
static uint8 selfcheckbreaktime = FALSE;
static uint8 onlyonce = FALSE;
static boolean PowerHadIgnOff = TRUE;

#define SWC_TT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TT_MemMap.h"


#define SWC_TT_START_SEC_CODE
#include "SWC_TT_MemMap.h"

static boolean TT__boCheckPowerMode(void)
{
    boolean boReturn = FALSE;
    uint32 u32PowerModeStatus = 0;
	uint8 PowerVoltageSts = 0;
	SystemState_RecordType Power_State = {0};
    uint32 u32LastPowerModeStatus = TT__stMainObject.unPowerModeStatus.u32PowerModeStatus;

	(void)memcpy(&Power_State,Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(),sizeof(SystemState_RecordType));
	u32PowerModeStatus = Power_State.ClusterState;
	PowerVoltageSts = Power_State.s_PowerVoltage.state;
    u8PrePowerMode = 0;
    /*Check power High voltage */

   if((PowerVoltageSts == VOLTAGE_OUT_NORMAL) || (PowerVoltageSts == VOLTAGE_OUT_LOWALARM) ||\
   	(PowerVoltageSts == VOLTAGE_OUT_HIGHALARM))
    {
        if(u32PowerModeStatus == SYSTEMSTATE_Cluster_STANDBY)
	    {
	        u32PowerModeStatus |= (uint32)TT_enOFF;
			PowerHadIgnOff = TRUE;
			TT_boSelfcheckReportsts = FALSE;
	    }
	    else if((u32PowerModeStatus == SYSTEMSTATE_Cluster_OFF) || (u32PowerModeStatus == SYSTEMSTATE_Cluster_SHUTDOWN))
	    {
	        u32PowerModeStatus |= (uint32)TT_enSLEEP;
			TT_boSelfcheckReportsts = FALSE;
	    }
		else if(u32PowerModeStatus == SYSTEMSTATE_Cluster_ON)
	    {
	        u32PowerModeStatus |= (uint32)TT_enRUN;
	    }
	    else
	    {
	        /*Do nothing but avoid QAC*/
	    }
    }
	else
	{
		 u32PowerModeStatus = (uint32)TT_enABNORMAL;
		 PowerHadIgnOff = FALSE;
		 TT_boSelfcheckReportsts = FALSE;
	}

    if(((uint32)TT_enNULL_POWER_MODE != u32PowerModeStatus) && ((uint32)TT_enABNORMAL != u32PowerModeStatus))
    {
        /*Already get at least one status,so set return to TRUE*/
        boReturn = TRUE;
    }
    else
    {
        boReturn = FALSE;
    }

	if(((uint32)TT_enRUN == (u32PowerModeStatus&(uint32)TT_enRUN))&&(FALSE != PowerHadIgnOff))
    {
        IGN_OFF_Flag = (boolean)1;
		onlyonce = 1;
		selfcheckbreaktime = 0;
		PowerHadIgnOff = FALSE;
    }
    else
    {

    }

	if(((uint32)TT_enRUN == (u32PowerModeStatus&(uint32)TT_enRUN))&&(0 == (u32LastPowerModeStatus&(uint32)TT_enRUN)))
	{
		TT__stMainObject.unFunctionFlag.stFuncFlag.AnyPowerModeToRunFlag = 1;
	}
	else
    {
        TT__stMainObject.unFunctionFlag.stFuncFlag.AnyPowerModeToRunFlag = 0;
    }

    /*When ignition on, then clear time tick*/
    //modify by fchao in 20200512 //if(((IGN_OFF_Flag == 1)&&(NJTC_GetAnimationState() != 1 )))
    if(IGN_OFF_Flag == 1)
    {
		IGN_OFF_Flag = (boolean)0;
        TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus(&TT__stMainObject);
        TT_CORE_vRestartAllTelltaleSelfCheck(&TT__stMainObject);

    }
    else
    {

    }
	if(onlyonce == 1)
	{
		selfcheckbreaktime++ ;
		if(selfcheckbreaktime < (2000/5))
		{
			sync_flag = 1 ;
		}
		else
		{
			onlyonce = 0;
		}
	}

	if(sync_flag == 1)
	{
		//modify by fchao in 20200512 //if((0 ==  NJTC_GetAnimationState() && last_sync ==1 ))
		if(last_sync ==1)
		{
			sync_flag = 0;
			//TT_CORE_vRestartAllTelltaleIgnOnResponseDelayStatus(&TT__stMainObject);
			TT_CORE_vRestartAllTelltaleSelfCheck(&TT__stMainObject);
		}
	}


    /*When exit abnormal status, then clear time tick*/
    if((((uint32)TT_enRUN == (u32PowerModeStatus&(uint32)TT_enRUN))||((uint32)TT_enOFF == (u32PowerModeStatus&(uint32)TT_enOFF))) \
		&&((uint32)TT_enABNORMAL == (u32LastPowerModeStatus&(uint32)TT_enABNORMAL)))
    {
        TT__stMainObject.stTimer.u16ExitAbnormalResponseDelayDelayTick = 0;
    }
    else
    {

    }

    /*When ignition off, not need to prove out*/
    if(u32PowerModeStatus&(uint32)TT_enOFF)
    {
        TT_CORE_vStopAllTelltaleSelfCheck(&TT__stMainObject);
    }
    else
    {

    }

    /*Save current power mode status*/
    TT__stMainObject.unPowerModeStatus.u32PowerModeStatus = u32PowerModeStatus;

    //modify by fchao in 20200512 //last_sync = NJTC_GetAnimationState();
    return boReturn;
}
/**********************************************************************************************************
*Function   : TT__vPowerModeErrorProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vPowerModeErrorProcess(void)
{
	(void)memset(&ToSBUS_TT_status32, 0, sizeof(ToSBUS_TT_status32));
    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TELLTALE,(uint8*)&ToSBUS_TT_status32,(uint16)sizeof(IPC_M2S_ClusterAppAPPTT_Module_t),FALSE);
}

/**********************************************************************************************************
*Function   : TT__boCheckExternalControl                                                                  *
*                                                                                                         *
*Description: The function is used to check external control which status can telltale work .             *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: Process return status . If power mode get faild , retuen FALSE .                            *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boCheckExternalControl(void)
{
	//uint8 u8Index;
	if(TT_CFG_DIAGNOSIS_MODE_ENABLE)
	{

	}
	else if(TT_CFG_EOL_MODE_ENABLE)
	{
	}
	/* modify by fchao in 20200512
	else if(FALSE == (Dimming_vGetDimmingStatus()&0x02))
	{
		TT_API_vSwitchAllTelltaleOFF_Function();
	}
	*/
	else
	{
		//for (u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
        //{
		//	TT_CORE_vTelltaleExternalControlDisable((TT_CFG_enTelltaleID)u8Index,&TT__stMainObject);
		//}

	}

	return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boCheckResponseDelayStatus                                                              *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boCheckResponseDelayStatus(void)
{
    /*Job define in core file*/
    TT_CORE_vCheckResponseDelayStatus(&TT__cstTelltaleAttribute[0],&TT__stMainObject);

	return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boResponseDelayStatusTickPlus                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boResponseDelayStatusTickPlus(void)
{
    /*Job define in core file*/
	TT_CORE_vResponseDelayStatusTickPlus(&TT__cstTelltaleAttribute[0],&TT__stMainObject);

    return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boCalculateFlashReferenceStatus                                                         *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boCalculateFlashReferenceStatus(void)
{
    /*Job define in core file*/
    //TT_CORE_vCalculateFlashReferenceStatus(&TT__cstFlashAttribute[0],&TT__stMainObject);

    return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boFlashReferenceTickPlus                                                                *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boFlashReferenceTickPlus(void)
{
    /*Job define in core file*/
    //TT_CORE_vFlashReferenceTickPlus(&TT__cstFlashAttribute[0],&TT__stMainObject);

    return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boTimeTaskLogicProcess                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boTimeTaskLogicProcess(void)
{
	TT_CORE_vTelltaleTableLogicProcess(TT_enTIME_TASK,&TT__cstLogicProcessAttribute[0],&TT__stMainObject);

    return TRUE;
}
/**********************************************************************************************************
*Function   : TT__boTelltaleLightControlProcess                                                           *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static boolean TT__boTelltaleLightControlProcess(void)
{
    uint8 u8Index = 0;
    for(u8Index=0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
		TT_CORE_vSingleTelltaleLightControl(&TT__stMainObject.stTelltaleControlStatus[u8Index],&TT__cstTelltaleAttribute[u8Index],&TT__stMainObject);
	}

	return TRUE;
}
/**********************************************************************************************************
*Function   : TT__vCANOutputUpdateMessage                                                                 *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void                                                                                        *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
static void TT__vCANOutputUpdateMessage(void)
{
	 TT__stMainObject.u32CANMessage = 0;
}
#endif
/**********************************************************************************************************
*Function   : TT__boCANOutputTaskOperation                                                                *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
static boolean TT__boCANOutputTaskOperation(void)
{
    /*Check update flag*/
    if(TT__stMainObject.unFunctionFlag.stFuncFlag.CANUpdateFlag)
    {
        TT__vCANOutputUpdateMessage();

        TT__stMainObject.unFunctionFlag.stFuncFlag.CANUpdateFlag = 0;
    }
    else
    {

    }

    return TRUE;
}
#endif
/**********************************************************************************************************
*Function   : TT__vSBUSUpdateMessage                                                                      *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)

static uint8 TT__vGetTelltaleSBUStatus(TT_CFG_enTelltaleID enTelltaleID)
{
	uint8 enLogicStatus = (uint8)TT_API_enGetTelltaleCurrentStatus(enTelltaleID);

	if((uint8)TT_enSELF_CHECK == enLogicStatus)
	{
		//enLogicStatus = TT_enTURN_ON;
	}
	else if(TT_enDEFAULT_LOGIC_STATUS_TYPE_NUMBER > enLogicStatus)
	{
		enLogicStatus = enLogicStatus;
	}
	else
	{
		enLogicStatus -= 1;
	}
	return enLogicStatus;
}

static void TT__vSBUSUpdateMessage(void)
{
    TT_TSR_Info tsr_send_value = {0};
    TT_V2X_Info v2x_send_value = {0};

    (void)Rte_Enter_ExclusiveArea_Normal();
    ETC_get_TSR_tt_inf(&tsr_send_value);
    Get_V2X_TT_Info(&v2x_send_value);
	FTT_API_GetSelfcheckReportStatus(); //A07独有自检播报功能
	FTT_SBUSUpdateVConfig();
    /* u32Telltales_status byte0*/
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineSysFault_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EngineSysFault) ? 1u : 0u;
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineSysFault_Data = TT__vGetTelltaleSBUStatus(enFTT_EngineSysFault);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineFix_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EngineFix) ? 1u : 0u;
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineFix_Data = TT__vGetTelltaleSBUStatus(enFTT_EngineFix);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CruiseControl_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CruiseControl) ? 1u : 0u;
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CruiseControl_Data = TT__vGetTelltaleSBUStatus(enFTT_CruiseControl);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineHighTemp_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EngineHighTemp) ? 1u : 0u;
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EngineHighTemp_Data = TT__vGetTelltaleSBUStatus(enFTT_EngineHighTemp);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SS_Enable_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_SS_Enable) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SS_Enable_Data = TT__vGetTelltaleSBUStatus(enFTT_SS_Enable);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SS_Fault_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_SS_Fault) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SS_Fault_Data = TT__vGetTelltaleSBUStatus(enFTT_SS_Fault);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BatteryCharge_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_BatteryCharge) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BatteryCharge_Data = TT__vGetTelltaleSBUStatus(enFTT_BatteryCharge);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LowFuelPress_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LowFuelPress) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LowFuelPress_Data = TT__vGetTelltaleSBUStatus(enFTT_LowFuelPress);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AutoPark_Enable_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_AutoPark_Enable) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AutoPark_Enable_Data = TT__vGetTelltaleSBUStatus(enFTT_AutoPark_Enable);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AutoPark_Fault_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_AutoPark_Fault) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AutoPark_Fault_Data = TT__vGetTelltaleSBUStatus(enFTT_AutoPark_Fault);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSD_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSD) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSD_Data = TT__vGetTelltaleSBUStatus(enFTT_HSD);
    if (TT_DOMAIN_CH == FTT_vDomain_Logic_Process())
    {
    	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_US_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_US_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_US_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_US_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_CH_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EPB_Enable_CH) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_CH_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_DPB_Enable_CH) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_CH_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Ibooster_Yellow_CH) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_CH_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Ibooster_Red_CH) ? 1u : 0u;

    }
    else
    {
    	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_CH_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_CH_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_CH_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_CH_Data_selfcheck = 0;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_US_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EPB_Enable_US) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_US_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_DPB_Enable_US) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_US_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Ibooster_Yellow_US) ? 1u : 0u;
        ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_US_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Ibooster_Red_US) ? 1u : 0u;
    }
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_CH_Data = TT__vGetTelltaleSBUStatus(enFTT_EPB_Enable_CH);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EPB_Enable_US_Data = TT__vGetTelltaleSBUStatus(enFTT_EPB_Enable_US);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_CH_Data = TT__vGetTelltaleSBUStatus(enFTT_DPB_Enable_CH);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DPB_Enable_US_Data = TT__vGetTelltaleSBUStatus(enFTT_DPB_Enable_US);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_CH_Data = TT__vGetTelltaleSBUStatus(enFTT_Ibooster_Yellow_CH);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_CH_Data = TT__vGetTelltaleSBUStatus(enFTT_Ibooster_Red_CH);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Yellow_US_Data = TT__vGetTelltaleSBUStatus(enFTT_Ibooster_Yellow_US);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ibooster_Red_US_Data = TT__vGetTelltaleSBUStatus(enFTT_Ibooster_Red_US);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_120KMH_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_120KMH) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_120KMH_Data = TT__vGetTelltaleSBUStatus(enFTT_120KMH);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Front_Fog_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Front_Fog) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Front_Fog_Data = TT__vGetTelltaleSBUStatus(enFTT_Front_Fog);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Rear_Fog_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Rear_Fog) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Rear_Fog_Data = TT__vGetTelltaleSBUStatus(enFTT_Rear_Fog);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.High_Beam_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_High_Beam) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.High_Beam_Data = TT__vGetTelltaleSBUStatus(enFTT_High_Beam);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Turn_Left_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Turn_Left) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Turn_Left_Data = TT__vGetTelltaleSBUStatus(enFTT_Turn_Left);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Turn_Right_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Turn_Right) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Turn_Right_Data = TT__vGetTelltaleSBUStatus(enFTT_Turn_Right);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Position_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Position) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Position_Data = TT__vGetTelltaleSBUStatus(enFTT_Position);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LightSwitch_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LightSwitch) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LightSwitch_Data = TT__vGetTelltaleSBUStatus(enFTT_LightSwitch);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Trailer_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Trailer) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Trailer_Data = TT__vGetTelltaleSBUStatus(enFTT_Trailer);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DoorOpen_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_DoorOpen) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.DoorOpen_Data = TT__vGetTelltaleSBUStatus(enFTT_DoorOpen);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TPMS_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_TPMS) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TPMS_Data = TT__vGetTelltaleSBUStatus(enFTT_TPMS);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Seat_Belt_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Seat_Belt) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Seat_Belt_Data = TT__vGetTelltaleSBUStatus(enFTT_Seat_Belt);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Trans_OverHeat_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Trans_OverHeat) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Trans_OverHeat_Data = TT__vGetTelltaleSBUStatus(enFTT_Trans_OverHeat);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Auto_Yellow_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Auto_Yellow) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Auto_Yellow_Data = TT__vGetTelltaleSBUStatus(enFTT_Auto_Yellow);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Auto_Green_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Auto_Green) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Auto_Green_Data = TT__vGetTelltaleSBUStatus(enFTT_Auto_Green);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LowFuel_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LowFuel) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LowFuel_Data = TT__vGetTelltaleSBUStatus(enFTT_LowFuel);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LDW_Enable_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LDW_Enable) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LDW_Enable_Data = TT__vGetTelltaleSBUStatus(enFTT_LDW_Enable);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LDW_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LDW_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LDW_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_LDW_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LKA_Enable_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LKA_Enable) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LKA_Enable_Data = TT__vGetTelltaleSBUStatus(enFTT_LKA_Enable);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LKA_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LKA_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LKA_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_LKA_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LCK_Enable_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LCK_Enable) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LCK_Enable_Data = TT__vGetTelltaleSBUStatus(enFTT_LCK_Enable);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LCK_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_LCK_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.LCK_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_LCK_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ready_Light_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Ready_Light) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Ready_Light_Data = TT__vGetTelltaleSBUStatus(enFTT_Ready_Light);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EV_Indicator_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_EV_Indicator) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.EV_Indicator_Data = TT__vGetTelltaleSBUStatus(enFTT_EV_Indicator);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_Green_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Charging_Green) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_Green_Data = TT__vGetTelltaleSBUStatus(enFTT_Charging_Green);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_Red_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Charging_Red) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_Red_Data = TT__vGetTelltaleSBUStatus(enFTT_Charging_Red);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_E_Yellow_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Charging_E_Yellow) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_E_Yellow_Data = TT__vGetTelltaleSBUStatus(enFTT_Charging_E_Yellow);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_E_Red_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Charging_E_Red) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Charging_E_Red_Data = TT__vGetTelltaleSBUStatus(enFTT_Charging_E_Red);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Secondary_Warning_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Secondary_Warning) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Secondary_Warning_Data = TT__vGetTelltaleSBUStatus(enFTT_Secondary_Warning);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Major_Warning_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Major_Warning) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Major_Warning_Data = TT__vGetTelltaleSBUStatus(enFTT_Major_Warning);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Parking_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Parking) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Parking_Data = TT__vGetTelltaleSBUStatus(enFTT_Parking);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Power_Reduction_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Power_Reduction) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Power_Reduction_Data = TT__vGetTelltaleSBUStatus(enFTT_Power_Reduction);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RBS_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_RBS) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RBS_Data = TT__vGetTelltaleSBUStatus(enFTT_RBS);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Engine_Warmup_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Engine_Warmup) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Engine_Warmup_Data = TT__vGetTelltaleSBUStatus(enFTT_Engine_Warmup);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BrakePad_Worn_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_BrakePad_Worn) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BrakePad_Worn_Data = TT__vGetTelltaleSBUStatus(enFTT_BrakePad_Worn);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Active_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CCO_Active) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Active_Data = TT__vGetTelltaleSBUStatus(enFTT_CCO_Active);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Standby_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CCO_Standby) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Standby_Data = TT__vGetTelltaleSBUStatus(enFTT_CCO_Standby);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Inactive_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CCO_Inactive) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CCO_Inactive_Data = TT__vGetTelltaleSBUStatus(enFTT_CCO_Inactive);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.FEDL_Active_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_FEDL_Active) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.FEDL_Active_Data = TT__vGetTelltaleSBUStatus(enFTT_FEDL_Active);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.FEDL_Inactive_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_FEDL_Inactive) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.FEDL_Inactive_Data = TT__vGetTelltaleSBUStatus(enFTT_FEDL_Inactive);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.REDL_Active_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_REDL_Active) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.REDL_Active_Data = TT__vGetTelltaleSBUStatus(enFTT_REDL_Active);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.REDL_Inactive_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_REDL_Inactive) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.REDL_Inactive_Data = TT__vGetTelltaleSBUStatus(enFTT_REDL_Inactive);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Standby_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAP_Standby) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Standby_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAP_Standby);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Active_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAP_Active) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Active_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAP_Active);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAP_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAP_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAP_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Switch_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAS_Switch) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Switch_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAS_Switch);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Active_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAS_Active) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Active_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAS_Active);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Standby_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAS_Standby) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Standby_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAS_Standby);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_HSAS_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.HSAS_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_HSAS_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AUX_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_AUX) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AUX_Data = TT__vGetTelltaleSBUStatus(enFTT_AUX);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RSW_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_RSW) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RSW_Data = TT__vGetTelltaleSBUStatus(enFTT_RSW);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SAS_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_SAS_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SAS_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_SAS_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SAS_Limit_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_SAS_Limit) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SAS_Limit_Data = TT__vGetTelltaleSBUStatus(enFTT_SAS_Limit);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Open_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Steer_Assit_Open) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Open_Data = TT__vGetTelltaleSBUStatus(enFTT_Steer_Assit_Open);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Work_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Steer_Assit_Work) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Work_Data = TT__vGetTelltaleSBUStatus(enFTT_Steer_Assit_Work);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Error_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Steer_Assit_Error) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Steer_Assit_Error_Data = TT__vGetTelltaleSBUStatus(enFTT_Steer_Assit_Error);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Sound_Reminder_Red_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Sound_Reminder_Red) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Sound_Reminder_Red_Data = TT__vGetTelltaleSBUStatus(enFTT_Sound_Reminder_Red);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Sound_Reminder_Yellow_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Sound_Reminder_Yellow) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Sound_Reminder_Yellow_Data = TT__vGetTelltaleSBUStatus(enFTT_Sound_Reminder_Yellow);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BatteryPack_Charge_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_BatteryPack_Charge) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.BatteryPack_Charge_Data = TT__vGetTelltaleSBUStatus(enFTT_BatteryPack_Charge);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Battery_Off_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Battery_Off) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Battery_Off_Data = TT__vGetTelltaleSBUStatus(enFTT_Battery_Off);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Low_Battery_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Low_Battery) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Low_Battery_Data = TT__vGetTelltaleSBUStatus(enFTT_Low_Battery);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RSCA_Off_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_RSCA_Off) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.RSCA_Off_Data = TT__vGetTelltaleSBUStatus(enFTT_RSCA_Off);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_2H_Indicator_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_2H_Indicator) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_2H_Indicator_Data = TT__vGetTelltaleSBUStatus(enFTT_2H_Indicator);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_4H_Indicator_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_4H_Indicator) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_4H_Indicator_Data = TT__vGetTelltaleSBUStatus(enFTT_4H_Indicator);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_4L_Indicator_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_4L_Indicator) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TT_4L_Indicator_Data = TT__vGetTelltaleSBUStatus(enFTT_4L_Indicator);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Single_Pedal_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Single_Pedal) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Single_Pedal_Data = TT__vGetTelltaleSBUStatus(enFTT_Single_Pedal);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Speed_Limit_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_TSR_Speed_Limit) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Speed_Limit_Data = TT__vGetTelltaleSBUStatus(enFTT_TSR_Speed_Limit);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Speed_Limit_Data_Value = tsr_send_value.u8TSR_Speed_Limit_Value;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Road_Sign_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_TSR_Traffic_Sign) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Road_Sign_Data = TT__vGetTelltaleSBUStatus(enFTT_TSR_Traffic_Sign);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TSR_Road_Sign_Data_Value = tsr_send_value.u8TSR_Road_Sign;
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.OilWaterSeparation_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_OilWaterSeparation) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.OilWaterSeparation_Data = TT__vGetTelltaleSBUStatus(enFTT_OilWaterSeparation);
	ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Adblue_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_Adblue) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.Adblue_Data = TT__vGetTelltaleSBUStatus(enFTT_Adblue);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SelfCheckReportStatus = TT_boSelfcheckReportsts ? 1u : 0u;

    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.GLOSA_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLOSA);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.GLOSA_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLOSA) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.GLOSA_Data_Value = v2x_send_value.u8V2X_GuideSpeed;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SpeedLimitWrn_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_SpeedLimit);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SpeedLimitWrn_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_SpeedLimit) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.SpeedLimitWrn_Data_Value = v2x_send_value.u8V2X_SpeedLimit;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficSign_Data  = TT__vGetTelltaleSBUStatus(enFTT_V2X_TrafficSign);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficSign_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_TrafficSign) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficSign_Data_value = v2x_send_value.u8V2X_TrafficSign;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLight_Position_Value = v2x_send_value.u8V2X_VehPosition;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight1) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight1);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight1) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight1);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight1) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight1);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL1_Time = v2x_send_value.u8V2X_LightTime[0];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight2) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight2);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight2) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight2);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight2) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight2);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL2_Time = v2x_send_value.u8V2X_LightTime[1];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight3) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight3);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight3) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight3);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight3) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight3);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL3_Time = v2x_send_value.u8V2X_LightTime[2];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight4) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight4);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight4) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight4);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight4) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight4);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL4_Time = v2x_send_value.u8V2X_LightTime[3];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight5) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight5);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight5) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight5);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight5) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight5);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL5_Time = v2x_send_value.u8V2X_LightTime[4];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight6) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight6);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight6) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight6);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight6) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight6);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL6_Time = v2x_send_value.u8V2X_LightTime[5];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_R_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_RLight7) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_R_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_RLight7);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_Y_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_YLight7) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_Y_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_YLight7);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_G_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_V2X_GLight7) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_G_Data = TT__vGetTelltaleSBUStatus(enFTT_V2X_GLight7);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.TrafficLights_SL7_Time  = v2x_send_value.u8V2X_LightTime[6];
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AirSus_Red_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_AirSus_Red) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AirSus_Red_Data = TT__vGetTelltaleSBUStatus(enFTT_AirSus_Red);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AirSus_Yellow_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_AirSus_Yellow) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.AirSus_Yellow_Data = TT__vGetTelltaleSBUStatus(enFTT_AirSus_Yellow);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CentDiffLock_Green_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CDLL_Green) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CentDiffLock_Green_Data = TT__vGetTelltaleSBUStatus(enFTT_CDLL_Green);
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CentDiffLock_Yellow_Data_selfcheck = TT_API_boGetSingleTelltaleSelfCheckStatus(enFTT_CDLL_Yellow) ? 1u : 0u;
    ToSBUS_TT_status32.u_TT_Moduleu32Telltales_status_t.s_u32Telltales_status_t.CentDiffLock_Yellow_Data = TT__vGetTelltaleSBUStatus(enFTT_CDLL_Yellow);

    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_TELLTALE,(uint8*)&ToSBUS_TT_status32,(uint16)sizeof(IPC_M2S_ClusterAppAPPTT_Module_t),FALSE);
    (void)Rte_Exit_ExclusiveArea_Normal();
    //if (memcmp(&ToSBUS_TT_status32,&ToSBUS_TT_status32_Pre,sizeof(ToSBUS_TT_status32)) != 0)
    // {
    //     IPC_M2S_ClusterAppAPPTT_Module_Transmit(&ToSBUS_TT_status32);
    //     memcpy(&ToSBUS_TT_status32_Pre,&ToSBUS_TT_status32,sizeof(ToSBUS_TT_status32));
    // }


}
#endif
/**********************************************************************************************************
*Function   : TT__boSBUSTimeTaskOperation                                                                 *
*                                                                                                         *
*Description: TBD		                                                                                  *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
static boolean TT__boSBUSTaskOperation(void)
{
    /*Check update flag*/

    if(0 == u8PrePowerMode)//TT__stMainObject.unFunctionFlag.stFuncFlag.SBUSUpdateFlag)
    {
        TT__vSBUSUpdateMessage();

        //TT__stMainObject.unFunctionFlag.stFuncFlag.SBUSUpdateFlag = 0;
    }
    else
    {

    }

//        TT__vSBUSUpdateMessage();

	return TRUE;
}
#endif
/*******************************************************************************
*	Function name		: void FTT_vSwitchAllTelltale_Function(void)
*
*	Parameters		: None.
*
*	Return Type 		: None.
*
*	Global Variables	: None.
*
*	External interface	: None.
*
*-----------------------------------------------------------------------------
*	Invocation		: Invoked by the Scheduler Wakeup list
*
*	Description 		:
*
********************************************************************************/
static void TT_vSwitchAllTelltale_Function(TT_CFG_enStatusType boTelltaleStatus)
{
    uint8 u8Index;
    for(u8Index = 0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
    {
		TT_API_vSetTelltaleExternalControlStatus(u8Index,boTelltaleStatus);
    }
}

/**********************************************************************************************************
*Function   : TT_API_vSwitchAllTelltaleON_Function                                                        *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/

void TT_API_vSwitchAllTelltaleON_Function (void)
{
	TT_vSwitchAllTelltale_Function(TT_enTURN_ON);

}
/**********************************************************************************************************
*Function   : TT_API_vSwitchAllTelltaleOFF_Function                                                       *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: (UINT8) u8TelltaleID	                                                                      *
*                                                                                                         *
*Return 	: BOOL                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/

void TT_API_vSwitchAllTelltaleOFF_Function (void)
{
	TT_vSwitchAllTelltale_Function(TT_enTURN_OFF);
}

/**********************************************************************************************************
*Function   : TT__vForceAllTelltaleClose                                                                  *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vForceAllTelltaleClose(void)
{
	const uint8 u8Factor = TT_CFG_TIME_TASK_CYCLE;
	uint8 u8Index;

	for(u8Index=0; u8Index < TT_enTELLTALE_TOTAL_NUMBER; u8Index++)
	{
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.LogicType = TT_enTURN_OFF;
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.ResultLogicType = TT_enTURN_OFF;
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.ExternalLogicType = TT_enTURN_OFF;
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.LastLogicType = TT_enTURN_OFF;

		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.IgnitionOnResponseDelayStatus = 0;
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.ExitAbnormalDelayStatus = 0;
		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.SelfCheckStatus = 0;

		TT__stMainObject.stTelltaleControlStatus[u8Index].unStatus.stStatus.LightType = TT_enLAMP_OFF;
		TT__stMainObject.stTelltaleControlStatus[u8Index].u8CurrentLightCount = 0;

		TT__stMainObject.stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount \
			= TT__cstTelltaleAttribute[u8Index].u16SelfCheckTime / u8Factor;

		TT__stMainObject.stTelltaleControlStatus[u8Index].u16SelfCheckTimeTick \
			= TT__stMainObject.stTelltaleControlStatus[u8Index].u16SelfCheckFinishTickCount;

		TT__stMainObject.stTelltaleControlStatus[u8Index].u16IgnOnDelayTimeTick \
			= TT__cstTelltaleAttribute[u8Index].u16IgnOnResponseDelayTime / u8Factor;

		TT_CORE_vSetTelltaleLightStatus(/*FALSE,*/&TT__cstTelltaleAttribute[u8Index],&TT__stMainObject);
	}
}
/**********************************************************************************************************
*Function   : TT__vSystemErrorObjectOperationProcess                                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: void		                                                                                  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
static void TT__vSystemErrorObjectOperationProcess(void)
{
    TT__vForceAllTelltaleClose();

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_CAN) != FALSE)
    /*Send CAN message*/
    TT__vCANOutputUpdateMessage();
#endif

#if ((TT_CFG_OUTPUT_MODE & TT_CFG_OUTPUT_ON_SBUS) != FALSE)
    /*Send SBUS message*/
    TT__vSBUSUpdateMessage();
#endif

}

boolean FTT_API_boGetSelfcheckReportStatus(void)
{
	boolean boReturn = FALSE;
	uint8 u8Selfchecksts = 1;

	if (0 == (FTT_Adapt_GetSelfChecksts(&u8Selfchecksts)))
	{
		u8SelfcheckReportsts = u8Selfchecksts;
	}

	// self check tt
	if(u8SelfcheckReportsts == 0)   // self check exit
	{
		if((0 != FTT_GET_Report_DID(enFTT_EngineSysFault)) \
		|| (0 != FTT_GET_Report_DID(enFTT_Trans_OverHeat)))
		{
			boReturn = TRUE;
		}

		if(FTT_boGetSelfcheckReportStatus())
		{
			boReturn = TRUE;
		}
	}
	else
	{
		if(0 != FTT_GET_Report_DID(enFTT_LowFuelPress))
		{
			boReturn = TRUE;
		}
	}

	// no self check tt 
	if(FTT_boGetSelfcheckReportStatus2())
	{
		boReturn = TRUE;
	}

	return(boReturn);
}

boolean FTT_boGetSelfcheckReportStatus(void)
{
	uint8 index = 0;
	boolean boReturn = FALSE;

	for(index = 0; index <= FTT_CFG_SelfcheckReport_COUNT; index ++)
	{
		if(TT__vGetTelltaleSBUStatus(FTT__SelfcheckReport[index]))
		{
			boReturn = TRUE;
			break;
		}
		else
		{
			boReturn = FALSE;
		}
	}

	return (boReturn);
}

boolean FTT_boGetSelfcheckReportStatus2(void)
{
	uint8 index = 0;
	boolean boReturn = FALSE;

	for(index = 0; index <= FTT_CFG_SelfcheckReport_COUNT2; index ++)
	{
		if(TT__vGetTelltaleSBUStatus(FTT__SelfcheckReport2[index]))
		{
			boReturn = TRUE;
			break;
		}
		else
		{
			boReturn = FALSE;
		}
	}

	return (boReturn);
}

void FTT_API_GetSelfcheckReportStatus(void)
{
	boolean boGetSelfcheckReportsts = FALSE;

	boGetSelfcheckReportsts = STT_boSendSelfcheckReportsts();
	FTT_boSelfcheckReportsts = FTT_API_boGetSelfcheckReportStatus();

	if(boGetSelfcheckReportsts || FTT_boSelfcheckReportsts)
	{
		TT_boSelfcheckReportsts = TRUE;
	}
	else
	{
		TT_boSelfcheckReportsts = FALSE;
	}

}
 static void FTT_SBUSUpdateVConfig(void)
{
	uint8 u8Config_FUEL = 0;
	uint8 u8Config_REGIONAL = 0;
	uint8 u8Config_SERVICE = 0;
	uint8 u8Config_PARKING = 0;
	uint8 u8Config_STEERING = 0;
	uint8 u8Config_FCW = 0;
	uint8 u8Config_AEB = 0;
	uint8 u8Config_ELEC = 0;
	uint8 u8Config_E_PARK = 0;

	u8Config_FUEL = FTT_Adapt_GetVconfig(VCONFIG_KIND_FUEL);	//燃油
	u8Config_REGIONAL = FTT_Adapt_GetVconfig(VCONFIG_KIND_REGIONAL);	//区域
	u8Config_SERVICE = FTT_Adapt_GetVconfig(VCONFIG_KIND_SERVICE_BRAKE);	//辅助制动
	u8Config_PARKING = FTT_Adapt_GetVconfig(VCONFIG_KIND_PARKING_BRAKE);
	u8Config_STEERING = FTT_Adapt_GetVconfig(VCONFIG_KIND_STEERING_SYSTEM);//转向助力
	u8Config_FCW = FTT_Adapt_GetVconfig(VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING);	//前方碰撞预警+制动
	u8Config_AEB = FTT_Adapt_GetVconfig(VCONFIG_KIND_AEB_JUNCTION_ASSIST);	//AEB交叉路口辅助
	u8Config_ELEC = FTT_Adapt_GetVconfig(VCONFIG_KIND_ELECTROMOTOR_POSITION);	//电机位置
	u8Config_E_PARK = FTT_Adapt_GetVconfig(VCONFIG_KIND_E_PARK);	//电子p挡

	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Fuel = u8Config_FUEL;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Regional = u8Config_REGIONAL;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Service_Brake = u8Config_SERVICE;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Parking_Brake = u8Config_PARKING;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Steering_System = u8Config_STEERING;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Fcw_Aeb = u8Config_FCW;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Aeb_Assist = u8Config_AEB;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.Elec_Position = u8Config_ELEC;
	ToSBUS_TT_VConfig.u_VConfigu8VConfig_data_t.s_u8VConfig_data_t.E_Park = u8Config_E_PARK;

    (void)Rte_Call_IPC_Send_IPC_Send((uint8)M2S_APP_VCONFIG,(uint8*)&ToSBUS_TT_VConfig,(uint16)sizeof(IPC_M2S_ClusterAppAPPVConfig_t),FALSE);
}

#define SWC_TT_STOP_SEC_CODE
#include "SWC_TT_MemMap.h"

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
