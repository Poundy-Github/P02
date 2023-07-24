/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  TM.c
 *           Config:  D:/VIP_8_13/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  TM
 *  Generation Time:  2020-08-14 15:54:20
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <TM>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_TM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "gpt.h"
#include "dr7f701651.dvf.h"
#include "TM_Cfg.h"
#include "os.h"

extern uint32 u32Tick1ms;

void TM_Init(void);
FUNC(void, TM_CODE) TM_Timer1msStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp);
FUNC(void, TM_CODE) TM_Timer1msElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed);
FUNC(Std_ReturnType, TM_CODE) TM_TimerOperation(uint8 TMId, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed,uint32 TimeoutValue, uint8 Op, uint8* Status);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


#define TM_START_SEC_CODE
#include "TM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_MainFunction_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TM_CODE) TM_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_MainFunction
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TM_TimerElapsed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TM_TimerElapsed> of PortPrototype <TM_Operation>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TM_TimerElapsed(uint32 *StartStamp, uint32 *TimeElapsed)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_TimerElapsed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TM_CODE) TM_TimerElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_TimerElapsed
 *********************************************************************************************************************/
	uint32 temp_time;
	uint32 result;


	temp_time = TAUJ0CNT0;

	if(temp_time <= *StartStamp)
	{
		result = *StartStamp - temp_time;/*count down timer*/
	}
	else																								  
	{
	  result = 0xffffffff - temp_time + *StartStamp  + 1;
	}

	result = result/2;/*unit : 0.1 us */
	
	(*TimeElapsed) = result;                                              

	(*StartStamp) = temp_time;                                                                                


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TM_TimerStartStamp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TM_TimerStartStamp> of PortPrototype <TM_Operation>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TM_TimerStartStamp(uint32 *StartStamp)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_TimerStartStamp_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, TM_CODE) TM_TimerStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TM_TimerStartStamp
 *********************************************************************************************************************/

	(*StartStamp) = TAUJ0CNT0;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define TM_STOP_SEC_CODE
#include "TM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
void TM_Init(void)
{
	
	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_tick,(uint32)-1);
}


FUNC(void, TM_CODE) TM_Timer1msStartStamp(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp) 
{

	(*StartStamp) = u32Tick1ms;

}

FUNC(void, TM_CODE) TM_Timer1msElapsed(P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) StartStamp, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed)
{
	uint32 temp_time;
	uint32 result;


	temp_time = u32Tick1ms;

	if(temp_time >= *StartStamp)
	{
		result = temp_time - *StartStamp ;/*count up timer*/
	}
	else																								  
	{
	  	result = 0xffffffff - *StartStamp  +  temp_time + 1;
	}
	
	(*TimeElapsed) = result;                                              

	(*StartStamp) = temp_time;                                                                                


}

FUNC(Std_ReturnType, TM_CODE) TM_TimerOperation(uint8 TMId, P2VAR(uint32, AUTOMATIC, RTE_TM_APPL_VAR) TimeElapsed,uint32 TimeoutValue, uint8 Op, uint8* Status) 
{
	Std_ReturnType ret = E_OK;
	uint32 temp_tm_start;
	
	if(TMId >= MAX_TM_ID)
	{
		ret = E_NOT_OK;
		return ret;
	}
	
	
	switch(Op)
	{

		case TM_OP_START:

			SuspendAllInterrupts();
			if(TM_Str_cfg[TMId].TM_Info->TM_Status != TM_RUNNING)
			{
				if(TM_Str_cfg[TMId].TM_Type == TM_TYPE_0P1US)
				{
					TM_Str_cfg[TMId].TM_Info->TM_Status = TM_RUNNING;					
					TM_Str_cfg[TMId].TM_Info->TM_CompareValue = TimeoutValue;
					TM_TimerStartStamp(&TM_Str_cfg[TMId].TM_Info->TM_Start);
					ResumeAllInterrupts();
				}
				else if(TM_Str_cfg[TMId].TM_Type == TM_TYPE_1MS)
				{
					TM_Str_cfg[TMId].TM_Info->TM_Status = TM_RUNNING;					
					TM_Str_cfg[TMId].TM_Info->TM_CompareValue = TimeoutValue;
					TM_Timer1msStartStamp(&TM_Str_cfg[TMId].TM_Info->TM_Start);
					ResumeAllInterrupts();
				}
				else
				{
					ResumeAllInterrupts();
					ret = E_NOT_OK;
					return ret;
				}
			}
			else
			{			
				ResumeAllInterrupts();
				ret = E_NOT_OK;
				return ret;
			}
			break;
			
		case TM_OP_CLEAR:
		
			SuspendAllInterrupts();
			TM_Str_cfg[TMId].TM_Info->TM_Status = TM_STOP;			
			TM_Str_cfg[TMId].TM_Info->TM_Start = 0uL;
			TM_Str_cfg[TMId].TM_Info->TM_Elapsed = 0uL;		
			TM_Str_cfg[TMId].TM_Info->TM_CompareValue = 0uL;		
			ResumeAllInterrupts();
			break;
			
		case TM_OP_CHECK:
		
			
			SuspendAllInterrupts();
			if((TM_Str_cfg[TMId].TM_Info->TM_Status == TM_RUNNING)||(TM_Str_cfg[TMId].TM_Info->TM_Status == TM_EXPIRED))
			{
				if(TM_Str_cfg[TMId].TM_Type == TM_TYPE_0P1US)
				{
					temp_tm_start = TM_Str_cfg[TMId].TM_Info->TM_Start;
					TM_TimerElapsed(&temp_tm_start,&TM_Str_cfg[TMId].TM_Info->TM_Elapsed);
				}
				else if(TM_Str_cfg[TMId].TM_Type == TM_TYPE_1MS)
				{
					temp_tm_start = TM_Str_cfg[TMId].TM_Info->TM_Start;
					TM_Timer1msElapsed(&temp_tm_start,&TM_Str_cfg[TMId].TM_Info->TM_Elapsed);
				}
				else
				{
					ResumeAllInterrupts();
					ret = E_NOT_OK;
					return ret;
				}

				if(TM_Str_cfg[TMId].TM_Info->TM_Status == TM_RUNNING)
				{
					if(TM_Str_cfg[TMId].TM_Info->TM_Elapsed >= TM_Str_cfg[TMId].TM_Info->TM_CompareValue)
					{
						TM_Str_cfg[TMId].TM_Info->TM_Status = TM_EXPIRED;
					}
				}	
			}
			else
			{					
				TM_Str_cfg[TMId].TM_Info->TM_Status = TM_STOP;
			}
			ResumeAllInterrupts();
			
			break;

		default:

			ret = E_NOT_OK;

			break;
			
			/*do nothing*/
			
	}
	
	*Status = TM_Str_cfg[TMId].TM_Info->TM_Status;
	*TimeElapsed = TM_Str_cfg[TMId].TM_Info->TM_Elapsed;
	

	
	return ret;

}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
