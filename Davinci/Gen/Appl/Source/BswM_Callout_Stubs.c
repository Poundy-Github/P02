/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2020-11-10 17:14:31
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"



/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 #include "fls.h"
 #include "mcu.h"
 #include "Rte_BswM_Type.h" 
 #include "ext_power.h" 
 #include "Icu.h" 
 #include "IoHwAb.h" 
 #include "IIC.h" 
 #include "AMP.h" 
 #include "Vconfig.h" 
 #include "RTC.h" 
 #include "AMP_ShutDown.h"
 #include "RingBuffer.h"
 #include "logger.h"
 #include "CPULoadMeasure.h"
 #include "RTC.h"
 
#include "nvm.h"
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"
FUNC(void, EOL_CODE) EOL_PreInit(void);
void DidDataProcess_PreInit(void);
void NVM_Mirror_Checksum_Update(void);
boolean NVM_Mirror_Check_Valid(void);
const uint8 nvm_read_sleep_table[36]=
  {
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_FactoryMode,
	NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock19,
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData,
	NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock18,
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VIN,
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VehicleMode, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF18C,
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF193,
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF195, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFD00, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFD19, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE20, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE21,
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE22, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE23, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE24, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE25, 
	NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF187,
	NvMConf_NvMBlockDescriptor_Common_GateWayNvBlockNeed_Block_IPC_Config_Data, 
	NvMConf_NvMBlockDescriptor_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data,
	NvMConf_NvMBlockDescriptor_MiscNvBlockNeed_ResetInfomation, 
	NvMConf_NvMBlockDescriptor_DCM_ServerNvBlockNeedSecAttemptCount, 
	NvMConf_NvMBlockDescriptor_DCM_ServerNvBlockNeed_EOLUnlockCnt, 
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ClusterInternalConfiguration, 
	NvMConf_NvMBlockDescriptor_AMP_NvBlockNeed_LC_Calibration, 
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_E2ESwitch, 
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_SecOcSwitch,
	NvMConf_NvMBlockDescriptor_NvBlockNeed_UpgradeResetFlag,
	NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount,
	NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Menu,
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VehicleSoftwareVersion,
	NvMConf_NvMBlockDescriptor_AMP_NvBlockNeed_LC_Calibration2,
	NvMConf_NvMBlockDescriptor_SOCManagerNvBlockNeed_HealthSwitch,
	NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset,
	NvMConf_NvMBlockDescriptor_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords,
	NvMConf_NvMBlockDescriptor_Can_ServerNvBlockNeed_ActiveWUCounter
  };
const uint8 nvm_read_wakeup_table[8]=
  {
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_1,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_2,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_3,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_4,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_5,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_MaintainOdo,
	  NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_Trip,
	  NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount
  };

#define NVM_READ_STEP_STOP			(0U)
#define NVM_READ_STEP_START			(1U)
#define NVM_READ_STEP_CONTINUE		(2U)


uint8 NVM_Read_Index=0xff;
uint8 NVM_Read_Step = 0xff;
extern uint32 Ecum_RstReason;

#pragma ghs section bss = ".rram_reset_flag" 
uint16 Exception_Reset_Flag;
uint32 Exception_FEIC;
uint32 Exception_FEPC;
uint32 Exception_EIIC;
uint32 Exception_EIPC;
uint32 Exception_CTPC;
uint32 Exception_Memeory_MEI;
uint32 Exception_Memeory_MEA;
TaskType Exception_Current_Task;
uint32 Exception_LR;
uint8 IPC_Exception_GroupId;
uint8 IPC_Exception_MajorId;
uint8 IPC_Exception_SubId;
uint16 IPC_Exception_Len;
uint32 soc_cold_reset_type;
uint32 cold_reset_req;/*if last sw internal reset req a cold init*/
uint32 init_process_finish;/*if appl init is precessed */
#pragma ghs section bss = default 



#define NVM_READALL_SPEEDUP
FUNC(void, IOHWAB_APPL_CODE) IoHwAb_Adc_MainFunction(void);

#ifdef TIME_MEASURE_TEST
uint32 time_tsart,time_elapsed;
FUNC(void, TM_CODE) TM_TimerElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed); 
FUNC(void, TM_CODE) TM_TimerStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp); 
#endif
extern void MenuSetMdl_MenuSet_cold_init(void);
void PowerPre_Init(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_vMemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BSWMCDDInitCallout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSWMCDDInitCallout>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	uint8 IO_Repeat = 0;

	IoHwAb_Init();
	//AMP_Init();
	EOL_PreInit();
	DidDataProcess_PreInit();
	VConfig_Init();
	RTC_PreInit();
	while((IO_Repeat++) < 5U)
	{
		IoHwAb_Adc_MainFunction();	
	}

	MenuSetMdl_MenuSet_cold_init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BSWMCDDInitCallout */


FUNC(void, BSWM_CODE) BSWMCancelReadNVM(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSWMCancelReadNVM>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	NVM_Read_Index = 0;
	NVM_Read_Step = NVM_READ_STEP_STOP;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BSWMCancelReadNVM */


FUNC(void, BSWM_CODE) BSWM_CheckNVMReadStatus(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSWM_CheckNVMReadStatus>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	if(NVM_READ_STEP_STOP == NVM_Read_Step)
	{
	  BswM_RequestMode(BSWM_GENERIC_ESH_NvMReadIndication, BSWM_GENERICVALUE_ESH_NvMReadIndication_NVM_READ_OK);
	}
	else
	{
	  BswM_RequestMode(BSWM_GENERIC_ESH_NvMReadIndication, BSWM_GENERICVALUE_ESH_NvMReadIndication_NVM_READ_PENDING);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BSWM_CheckNVMReadStatus */


FUNC(void, BSWM_CODE) BSWM_Enter_NVMRead(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSWM_Enter_NVMRead>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	BswM_RequestMode(BSWM_GENERIC_ESH_NvMReadIndication, BSWM_GENERICVALUE_ESH_NvMReadIndication_NVM_READ_PENDING);
	NVM_Read_Index = 0;
	NVM_Read_Step = NVM_READ_STEP_START;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BSWM_Enter_NVMRead */


FUNC(void, BSWM_CODE) BSWM_Process_NVMRead(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BSWM_Process_NVMRead>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	NvM_RequestResultType NvBlockReadStatus;

	switch(NVM_Read_Step)
	{
		case NVM_READ_STEP_START:
#ifdef TIME_MEASURE_TEST
			TM_TimerStartStamp(&time_tsart);
#endif
			(void)NvM_GetErrorStatus(nvm_read_sleep_table[NVM_Read_Index], &NvBlockReadStatus);
			if(NvBlockReadStatus != NVM_REQ_PENDING)
			{
				(void)NvM_ReadBlock(nvm_read_sleep_table[NVM_Read_Index],NvM_BlockDescriptorTable_at[nvm_read_sleep_table[NVM_Read_Index]].RamBlockDataAddr_t);
				NVM_Read_Step = NVM_READ_STEP_CONTINUE;
			}
				
			break;
			
		case NVM_READ_STEP_CONTINUE:
			(void)NvM_GetErrorStatus(nvm_read_sleep_table[NVM_Read_Index], &NvBlockReadStatus);	
			if(NvBlockReadStatus != NVM_REQ_PENDING)
			{
				NVM_Read_Index++;
				if(NVM_Read_Index<sizeof(nvm_read_sleep_table))
				{
					
					(void)NvM_ReadBlock(nvm_read_sleep_table[NVM_Read_Index],NvM_BlockDescriptorTable_at[nvm_read_sleep_table[NVM_Read_Index]].RamBlockDataAddr_t);
				}
				else
				{
					(void)CancelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable); 
					NVM_Read_Step = NVM_READ_STEP_STOP;
					
					NVM_Mirror_Checksum_Update();
					
#ifdef TIME_MEASURE_TEST
					TM_TimerElapsed(&time_tsart,&time_elapsed);
#endif

				}
			}
			break;

		default:
			NvBlockReadStatus = NVM_REQ_NOT_OK; /* MISRA C-2012 Rule 16.4 */
			break;
			
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BSWM_Process_NVMRead */


FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	(void)Os_InitialEnableInterruptSources(FALSE);
  Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN0_RXD);
  Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN0_RXD); 
  Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN1_RXD);
  Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN1_RXD);
	Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
	Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN3_RXD);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_AL_SetProgrammableInterrupts */


FUNC(void, BSWM_CODE) BswM_Action_PostSleep(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_Action_PostSleep>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /*perform reset if sleep fail*/
  
  Mcu_PerformReset();
} /* End of BswM_Action_PostSleep */


FUNC(void, BSWM_CODE) BswM_DataFlashStart(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_DataFlashStart>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    
   Cdd_HsmEnableIcup2CpuInterrupt();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  Cdd_HsmDataFlashStart();
} /* End of BswM_DataFlashStart */


FUNC(void, BSWM_CODE) BswM_DataFlashStop(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_DataFlashStop>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  Cdd_HsmDataFlashStop();
} /* End of BswM_DataFlashStop */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPostRun>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPostRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPrepShutdown>           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPrepShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterRun>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	
	init_process_finish = INIT_PROCESS_FINISHED;/*init task of appl swc is processed before BswM_ESH_OnEnterRun callout*/
	(void)Rte_Write_BswM_Provide_BswMRteModeRequestPort_WakeupReason_WakeupSource(EcuM_GetValidatedWakeupEvents());


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterShutdown>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
uint8 temp_PowerModeShutdownReq;

uint8 temp_PowerModeEmergencySleepReq;

#define FCLA0CTL3_INTPL_ADDRESS		*((volatile unsigned long *)0xffC3403CUL)/*INTP3-CAN3RX*/
#define FCLA0CTL5_INTPU_ADDRESS		*((volatile unsigned long *)0xffC340B4UL)/*INTP21-LVI*/


Rtc_SleepDateTimeRecord();
EXT_Power_BasicPowerDown();
(void)RB_Save(RB_ID_LOGGER_IPC);

(void)Rte_Read_Request_PowerModeShutdownReq_requestedMode(&temp_PowerModeShutdownReq);

(void)Rte_Read_BswM_Request_PowerModeShutdownReq_EmergencySleep_requestedMode(&temp_PowerModeEmergencySleepReq);


  if(BswMReqSleepEmergency == temp_PowerModeEmergencySleepReq)
  {
	  AMP_Emergency_Shutdown();
	  Mcu_WakeUpFactor_Preparation(McuConf_McuModeSettingConf_McuModeSettingConf_lvi);
	  Icu_DisableNotification(IcuConf_IcuChannel_VIP_LVI_IDL);
	  Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_LVI_IDL);
	  FCLA0CTL5_INTPU_ADDRESS = 0x05;
	  NVM_Mirror_Checksum_Update();
  }
  else
  {		
	  Mcu_WakeUpFactor_Preparation(McuConf_McuModeSettingConf_McuModeSettingConf_normal);	  
//	  Icu_DisableNotification(IcuConf_IcuChannel_VIP_CAN3_RXD);
//	  Icu_DisableEdgeDetection(IcuConf_IcuChannel_VIP_CAN3_RXD);
//	  FCLA0CTL3_INTPL_ADDRESS = 0x04;
  }



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWaitForNvm>             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  (void)SetRelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable, (TickType)(0 + 1), (TickType)1);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWaitForNvm */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWakeup>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	if(NVM_READ_STEP_STOP != NVM_Read_Step)
	{
		(void)CancelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable); 
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  
  
  
} /* End of BswM_ESH_OnEnterWakeup */


FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifdef NVM_READALL_SPEEDUP

	if((((EcuM_GetPendingWakeupEvents()&ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b)== ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b)
		||((EcuM_GetValidatedWakeupEvents()&ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b)== ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b) ) 
		  && NVM_Mirror_Check_Valid())
	{
	   uint8 nvm_index;
	   for(nvm_index = 0;nvm_index<sizeof(nvm_read_wakeup_table);nvm_index++)
	   {
		  (void)NvM_ReadBlock(nvm_read_wakeup_table[nvm_index],NvM_BlockDescriptorTable_at[nvm_read_wakeup_table[nvm_index]].RamBlockDataAddr_t);
		  {
			  NvM_RequestResultType NvSingleBlockStatus = NVM_REQ_NOT_OK;
			  do
			  {
			  NvM_MainFunction();
		
			  Fee_30_SmallSector_MainFunction();
		
			  Fls_MainFunction();
		
			  NvM_GetErrorStatus(nvm_read_wakeup_table[nvm_index], &NvSingleBlockStatus);
		  
			  }
			  while (NvSingleBlockStatus == NVM_REQ_PENDING);
		  }
	   }
	}
	else
#endif
	{
		NvM_ReadAll();
		{
			  NvM_RequestResultType Int_NvMultiBlockStatus = NVM_REQ_NOT_OK;
			  do
			  {
			  NvM_MainFunction();
		
			  Fee_30_SmallSector_MainFunction();
		
			  Fls_MainFunction();
		
			  NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &Int_NvMultiBlockStatus);
		  
			  }
			  while (Int_NvMultiBlockStatus == NVM_REQ_PENDING);
		}
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  ComM_StateType CN_B30_for_SC_CAN_V3_2_c0d6c67b = COMM_NO_COM_NO_PENDING_REQUEST;
  
  (void)ComM_GetState(ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b, &CN_B30_for_SC_CAN_V3_2_c0d6c67b); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  
  if(CN_B30_for_SC_CAN_V3_2_c0d6c67b != COMM_NO_COM_NO_PENDING_REQUEST)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST);
  }
  
} /* End of ESH_ComM_CheckPendingRequests */


FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_Dem_PostRunRequested>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  boolean isRequested = FALSE;
  (void)Dem_PostRunRequested(&isRequested); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  if (isRequested == TRUE)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE);
  }
  
} /* End of ESH_Dem_PostRunRequested */


FUNC(void, BSWM_CODE) ReadWakeUpPattern(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ReadWakeUpPattern>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	#define INTP21_WUF1_5						(1U<<5) 	// VIP_LVI_IDL
    #define INTP3_WUF0_9                        (1U<<9)     // VIP_CAN
	#define STBC_WUF0							*((volatile unsigned long *)0xfff80400UL)
	#define STBC_WUF1							*((volatile unsigned long *)0xFFF80410UL)

	uint32 loc_WakeUpFactor0;
	uint32 loc_WakeUpFactor1;
	boolean WarmReset;
	Mcu_ResetType reset_reason;

	if(0 != Exception_Reset_Flag)
	{
		 power_err("Last protection reset happen in task  %d",Exception_Current_Task);
		 
		 power_err("CTPC is HEX: %x",Exception_CTPC);
		 
		if((uint16)E_OS_PROTECTION_MEMORY == Exception_Reset_Flag)
		{			
			power_err("Reset for MPU violation !!!!!");
			
			power_err("FEPC is HEX: %x",Exception_FEPC);
			
			power_err("MPU error address is HEX: %x",Exception_Memeory_MEA);
			
			power_err("MPU error info is HEX: %x",Exception_Memeory_MEI);
			power_err("Exception Lr is HEX: %x",Exception_LR);
		}
		else if(PANIC_MPU_ERROR == Exception_Reset_Flag)
		{			
			power_err("Reset for Panic error (MPU violation) !!!!!");
			
			power_err("FEPC is HEX: %x",Exception_FEPC);
			
			power_err("MPU error address is HEX: %x",Exception_Memeory_MEA);
			
			power_err("MPU error info is HEX: %x",Exception_Memeory_MEI);
			power_err("Exception Lr is HEX: %x",Exception_LR);
		}
		else if((uint16)E_OS_PROTECTION_EXCEPTION == Exception_Reset_Flag)
		{
			
			power_err("Reset for unhandled exception HEX:%x",Exception_FEIC);

			power_err("FEPC is HEX: %x",Exception_FEPC);
			power_err("Exception Lr is HEX: %x",Exception_LR);
		}				
		else if((uint16)E_OS_SYS_PROTECTION_IRQ == Exception_Reset_Flag)
		{
			
			power_err("Reset for unhandled Isr HEX:%x",Exception_EIIC);

			power_err("EIPC is HEX: %x",Exception_EIPC);
		}		
		else if(PANIC_ERROR == Exception_Reset_Flag)
		{
			
			power_err("Reset for panic error");

		}
		else
		{
			power_err("Protection error : %d ", Exception_Reset_Flag);
		}	

		if( (IPC_Exception_GroupId != 0xff)||\
			(IPC_Exception_MajorId != 0xff)||\
			(IPC_Exception_SubId != 0xff)||\
			(IPC_Exception_Len != 0xffff))
		{
			power_err("Exception happens in IPC callback , Gid:%d , Mid:%d , Sid:%d, Len:%d ",IPC_Exception_GroupId,IPC_Exception_MajorId,IPC_Exception_SubId,IPC_Exception_Len);
		}
	}
	
	/*log exception error info here*/
	Exception_Reset_Flag=0;
	Exception_FEIC=0;
	Exception_FEPC=0;
	Exception_EIIC=0;
	Exception_EIPC=0;
	Exception_CTPC=0;
	Exception_Memeory_MEI=0;
	Exception_Memeory_MEA=0;
	Exception_LR=0;
	IPC_Exception_GroupId=0xff;
	IPC_Exception_MajorId=0xff;
	IPC_Exception_SubId=0xff;
	IPC_Exception_Len=0xffff;

	
	loc_WakeUpFactor0 = STBC_WUF0;
	loc_WakeUpFactor1 = STBC_WUF1;

	if((loc_WakeUpFactor1 & INTP21_WUF1_5)==INTP21_WUF1_5 )
	{
		EcuM_SetWakeupEvent(ECUM_WKSOURCE_LVI); 
	}
	else if((loc_WakeUpFactor0 & INTP3_WUF0_9)==INTP3_WUF0_9)
    {
		EcuM_SetWakeupEvent(ECUM_WKSOURCE_CN_B30_for_SC_CAN_V3_2_c0d6c67b); 
    }
	else
	{

	}
	power_err("Wakeup flag WuF0 is : %x",loc_WakeUpFactor0);
	
	power_err("Wakeup flag WuF1 is : %x",loc_WakeUpFactor1);

	if (0 == Ecum_RstReason)
	{
	  reset_reason = MCU_RESET_UNDEFINED;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_PURES))
	{
	  reset_reason = MCU_POWER_ON_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_WDR0))
	{
	  reset_reason = MCU_WATCHDOG0_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_WDR1))
	{
	  reset_reason = MCU_WATCHDOG1_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_CLM0))
	{
	  reset_reason = MCU_CLM0_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_CLM1))
	{
	  reset_reason = MCU_CLM1_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_CLM2))
	{
	  reset_reason = MCU_CLM2_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_CVM))
	{
	  reset_reason = MCU_CVM_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_LVI))
	{
	  reset_reason = MCU_LVI_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_SWR))
	{
	  reset_reason = MCU_SW_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_ISO))
	{
	  reset_reason = MCU_ISO_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_CLM3))
	{
	  reset_reason = MCU_CLM3_RESET;
	}
	else if (MCU_LONG_WORD_ZERO != (Ecum_RstReason & MCU_TER))
	{
	  reset_reason = MCU_TERMINAL_RESET;
	}
	else
	{
	  reset_reason = MCU_RESET_UNKNOWN;
	}
	power_err("RESF is HEX: %x ", Ecum_RstReason);

	Rte_Write_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource((reset_type)reset_reason);

	/**************************
	cold reset：
	  1.power on reset
	  2.diag 11 01
	  3.SOC req mcu reset
	  4.mcu reset for abnormal(wdg,clm,cvm ...)
	  5.back from minisys
	  6.other situations not in cold/warm list
	warm reset:
	  1.CAN wakeup
	  2.diag 11 03
	  3.LVI wakeup(no cold reset happens ever since last normal sleep)
	  4.reset for recover from low/high sleep
	**************************/
	if((MCU_POWER_ON_RESET == reset_reason)||(DIAG_REQ_COLD_RESET == cold_reset_req)||(SOC_REQ_COLD_RESET == cold_reset_req)||\
	(UPGRADE_COLD_RESET == cold_reset_req)||(SYS_ERR_COLD_RESET == cold_reset_req))
	{
		if(DIAG_REQ_COLD_RESET == cold_reset_req)
		{			
			power_err("Diag 11 01 Reset");
		}
		else if(SOC_REQ_COLD_RESET == cold_reset_req)
		{
			power_err("SOC req Reset");

			if(SOC_RESET_USB_UPDATE == soc_cold_reset_type)
			{
				power_err("SOC req Reset for USB update");
			}
			else if(SOC_RESET_FOTA_CHECK_MIN == soc_cold_reset_type)			
			{
				power_err("SOC req Reset for FOTA mini system check");
			}		
			else if(SOC_RESET_SYSTEM_REC == soc_cold_reset_type)			
			{
				power_err("SOC req Reset for system recovery");
			}
			else if(SOC_RESET_SOC_MINI == soc_cold_reset_type)			
			{
				power_err("SOC req Reset for SOC mini system");
			}
			else
			{
				/*do nothing*/
			}
		}	
		else if(SYS_ERR_COLD_RESET == cold_reset_req)
		{
			if(SOC_RESET_HANDSHAKE == soc_cold_reset_type)
			{
				power_err("Reset Mcu for handshake timeout 5");
			}
			else if(SOC_RESET_HEALTH == soc_cold_reset_type)			
			{
				power_err("Reset Mcu for health timeout 5");
			}		
			else
			{
				/*do nothing*/
			}
		}
		else if(UPGRADE_COLD_RESET == cold_reset_req)
		{
			power_err("SOC req upgrade cold Reset");
		}
		else
		{
			/*do nothig*/
		}
		/*clear cold reset flag*/
		init_process_finish = INIT_PROCESS_NOT_FINISHED;		
		/*cold reset*/
		WarmReset = FALSE;	
		
	}
	else if(((EcuM_GetValidatedWakeupEvents()&ECUM_WKSOURCE_INTERNAL_RESET)== ECUM_WKSOURCE_INTERNAL_RESET) ||
		((EcuM_GetValidatedWakeupEvents()&ECUM_WKSOURCE_COMMON_WAKEUP)== ECUM_WKSOURCE_COMMON_WAKEUP))
	{
		if(DIAG_REQ_WARM_RESET == cold_reset_req)
		{
			power_err("Diag 11 03 Reset!!!!!");
		}
		else if(UPGRADE_WARM_RESET == cold_reset_req)
		{
			power_err("SOC req upgrade warm Reset!!!!!");
		}
		else if(HARDKEY_WARM_RESET == cold_reset_req)
		{
			power_err("Press HardKey warm Reset!!!!!");
		}
		else 
		{
		}
		if(INIT_PROCESS_FINISHED == init_process_finish)
		{
			/*warm reset*/
			WarmReset = TRUE;  
		}
		else
		{
			init_process_finish = INIT_PROCESS_NOT_FINISHED;		
			/*cold reset*/
			WarmReset = FALSE;	
		}

	}
	else
	{
		init_process_finish = INIT_PROCESS_NOT_FINISHED;		
		/*cold reset*/
		WarmReset = FALSE;	

	}
	cold_reset_req = COLD_RESET_CLEARED;
	soc_cold_reset_type = COLD_RESET_CLEARED;


	if(FALSE == WarmReset)
	{
		RTC_ColdResetCallout();
		/* Log_ColdResetCallout(); */ /* MISRA C-2012 Rule 2.2 */
	}
	
	Rte_Write_Provide_BswMRteModeRequestPort_ResetType_Element(WarmReset);
	PowerPre_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of ReadWakeUpPattern */




#define BSWM_STOP_SEC_CODE
#include "BswM_vMemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


