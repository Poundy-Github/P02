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
 *             File:  IoHwAb.c
 *           Config:  E:/V3P5_VIP/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  IoHwAb
 *  Generation Time:  2020-08-11 13:31:34
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <IoHwAb>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_IoHwAb.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "IoHwAb.h"
#include "IoHwAb_common.h"
#include "IoHwAb_Adc.h"
#include "IoHwAb_Dio.h"
#include "IoHwAb_Pwm.h"
#include "IoHwAb_HsLsDrv.h"
#include "IoHwAb_Filter.h"


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
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_GetPin
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetPin> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_GetPin(uint8 Id, boolean *Pin)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_GetPin_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetPin(uint8 Id, P2VAR(boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Pin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_GetPin (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if (Id < IoHwAb_DIn_PinInCfg_Count)
	  {
		  if(TRUE == CIoHwAb_DIn_PinInCfg[Id].IsPeriod)
		  {
			  if(E_OK == CIoHwAb_DIn_PinInCfg[Id].pRAM->Status)
			  {
				  Ret = E_OK;
			  }
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  *Pin = (boolean)CIoHwAb_DIn_PinInCfg[Id].pRAM->AppValue;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
			  *Pin = (boolean)Dio_ReadChannel((Dio_ChannelType)CIoHwAb_DIn_PinInCfg[Id].HwId);
			  Ret = E_OK;
		  }
	  }

	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_GetVoltage
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVoltage> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_GetVoltage(uint8 Id, uint32 *Voltage)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_GetVoltage_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) Voltage) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_GetVoltage (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if(Id < IoHwAb_AIn_Cfg_Count)
	  {
		  if(TRUE == CIoHwAb_AIn_VoltageInCfg[Id].IsPeriod)
		  {
			  if(E_OK == CIoHwAb_AIn_VoltageInCfg[Id].pRAM->Status)
			  {
				  Ret = E_OK;
			  }
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  *Voltage = CIoHwAb_AIn_VoltageInCfg[Id].pRAM->AppValue;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
		  	  Rte_Enter_ExclusiveArea_IoHwAb();
			  *Voltage = CIoHwAb_Input_Convert(CIoHwAb_AIn_VoltageInCfg[Id], CIoHwAb_AIn_VoltageInCfg[Id].pRAM->HwValue);
			  Rte_Exit_ExclusiveArea_IoHwAb();
			  Ret = E_OK;
		  }

	  }
	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_IoHwAb(void)
 *   void Rte_Exit_ExclusiveArea_IoHwAb(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, IoHwAb_CODE) IoHwAb_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_MainFunction
 *********************************************************************************************************************/
	IoHwAb_Adc_MainFunction();
	IoHwAb_Dio_MainFunction();
	IoHwAb_Pwm_MainFunction();
	/*no LS/HS driver in V3.5*/
	/*IoHwAb_HsLsDrv_MainFunction();*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_SetDuty
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetDuty> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_SetDuty(uint8 Id, uint16 Duty)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetDuty_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetDuty(uint8 Id, uint16 Duty) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetDuty (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if(Id < IoHwAb_Pwm_DutyOutCfg_Count)
	  {
		  if(TRUE == CIoHwAb_DOut_PinOutCfg[Id].IsPeriod)
		  {
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  CIoHwAb_Pwm_DutyOutCfg[Id].pRAM->AppValue = Duty;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
			  Duty = (uint16)(((uint64)Duty*0x8000)/1000);
			  Pwm_SetDutyCycle((Pwm_ChannelType)(CIoHwAb_Pwm_DutyOutCfg[Id].HwId + 1U), Duty);
		  }
		  Ret = E_OK;

	  }
	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_SetHsLsOutput
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHsLsOutput> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_SetHsLsOutput(uint8 Id, uint16 Output)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetHsLsOutput_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetHsLsOutput(uint8 Id, uint16 Output) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetHsLsOutput (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if(Id < IoHwAb_HsLs_Cfg_Count)
	  {
		  if(TRUE == CIoHwAb_HSLS_Cfg[Id].BasicCfg.IsPeriod)
		  {
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  CIoHwAb_HSLS_Cfg[Id].BasicCfg.pRAM->AppValue = Output;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
			  Output = (uint16)CIoHwAb_Output_Convert(CIoHwAb_HSLS_Cfg[Id].BasicCfg, Output);

			  switch(CIoHwAb_HSLS_Cfg[Id].DirectHwType)
			  {
				  case cIoHwAb_HsLs_Spi:

					  HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[Id].BasicCfg.Type, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwIdEx, Output);

					  break;
				  case cIoHwAb_HsLs_Direct_Pwm:

					  Pwm_SetDutyCycle((Pwm_ChannelType)CIoHwAb_HSLS_Cfg[Id].DirectHwId, (uint16)Output);
					  HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[Id].BasicCfg.Type, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwIdEx, Output);

					  break;
				  case cIoHwAb_HsLs_Direct_Dio:

					  Dio_WriteChannel((Dio_ChannelType)CIoHwAb_HSLS_Cfg[Id].DirectHwId, (Dio_LevelType)Output);
					  HsLs_Chip_SetOutput(CIoHwAb_HSLS_Cfg[Id].BasicCfg.Type, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwId, CIoHwAb_HSLS_Cfg[Id].BasicCfg.HwIdEx, Output);

					  break;
				  default:
				      /* nothing to do */
					  break;

			  }
		  }
		  Ret = E_OK;

	  }
	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_SetPeriodAndDuty
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPeriodAndDuty> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_SetPeriodAndDuty(uint8 Id, uint16 Period, uint16 Duty)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetPeriodAndDuty_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetPeriodAndDuty(uint8 Id, uint16 Period, uint16 Duty) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetPeriodAndDuty (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if(Id < IoHwAb_Pwm_PeriodOutCfg_Count)
	  {
		  if(TRUE == CIoHwAb_Pwm_PeriodOutCfg[Id].IsPeriod)
		  {
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  CIoHwAb_Pwm_PeriodOutCfg[Id].pRAM->AppValue = Period;
			  CIoHwAb_Pwm_DutyOutCfg[Id].pRAM->AppValue = Duty;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
			  Period = (uint16)CIoHwAb_Output_Convert(CIoHwAb_Pwm_PeriodOutCfg[Id], Period);
			  Duty = (uint16)(((uint64)Duty*0x8000)/1000);
			  Pwm_SetPeriodAndDuty((Pwm_ChannelType)CIoHwAb_Pwm_PeriodOutCfg[Id].HwId, (Pwm_PeriodType)Period,(uint16)Duty);
		  }
		  Ret = E_OK;

	  }
	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_SetPin
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPin> of PortPrototype <IoHwAb_Interface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IoHwAb_SetPin(uint8 Id, boolean Digital)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetPin_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SetPin(uint8 Id, boolean Digital) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_SetPin (returns application error)
 *********************************************************************************************************************/

	  Std_ReturnType Ret = E_NOT_OK;

	  if (Id < IoHwAb_DOut_PinOutCfg_Count)
	  {
		  if(TRUE == CIoHwAb_DOut_PinOutCfg[Id].IsPeriod)
		  {
			  Rte_Enter_ExclusiveArea_IoHwAb();
			  CIoHwAb_DOut_PinOutCfg[Id].pRAM->AppValue = Digital;
			  Rte_Exit_ExclusiveArea_IoHwAb();
		  }
		  else
		  {
			  Dio_WriteChannel((Dio_ChannelType)CIoHwAb_DOut_PinOutCfg[Id].HwId, (Dio_LevelType)Digital);
		  }
		  Ret = E_OK;
	  }

	  return Ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, IoHwAb_CODE) IoHwAb_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

	IoHwAb_FiltersWrapper_Init();
	IoHwAb_Adc_Init();
	IoHwAb_Dio_Init();
	IoHwAb_Pwm_Init();
	IoHwAb_HsLsDrv_Init();

}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:IoHwAb_Init_doc)  *************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:IoHwAb_Init)  ************************************/

	IoHwAb_FiltersWrapper_Init();
	IoHwAb_Adc_Init();
	IoHwAb_Dio_Init();
	IoHwAb_Pwm_Init();
	IoHwAb_HsLsDrv_Init();

/***  End of saved code  ************************************************************************************/
#endif

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
