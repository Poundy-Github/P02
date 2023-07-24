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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define OS_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "EcuM.h"
#include "CPULoadMeasure.h"
#include "cpu.h"

#pragma ghs section bss = ".rram_reset_flag" 
extern uint16 Exception_Reset_Flag;
extern uint32 Exception_FEIC;
extern uint32 Exception_FEPC;
extern uint32 Exception_EIIC;
extern uint32 Exception_EIPC;
extern uint32 Exception_CTPC;
extern uint32 Exception_Memeory_MEI;
extern uint32 Exception_Memeory_MEA;
extern TaskType Exception_Current_Task; /* MISRA C-2012 Rule 10.3 */
extern uint32 Exception_LR;
extern uint8 IPC_Exception_GroupId;
extern uint8 IPC_Exception_MajorId;
extern uint8 IPC_Exception_SubId;
extern uint16 IPC_Exception_Len;

#pragma ghs section bss = default 

extern TaskType Curren_Task_Id;
extern uint8 u8IPC_IF_GroupId;
extern uint8 u8IPC_IF_MajorId;
extern uint8 u8IPC_IF_SubId;
extern uint16 u16IPC_IF_Len;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StartupHook()
 *********************************************************************************************************************/
#if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
# define OS_START_SEC_STARTUPHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_STARTUPHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_STARTUPHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ShutdownHook()
 *********************************************************************************************************************/
#if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
# define OS_START_SEC_SHUTDOWNHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
 *********************************************************************************************************************/
  EcuM_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_SHUTDOWNHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_SHUTDOWNHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ErrorHook()
 *********************************************************************************************************************/
#if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
# define OS_START_SEC_ERRORHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
 *********************************************************************************************************************/
  Os_ErrorInformationType CurrentError;
  /* TaskRefType TaskID; */ /* MISRA C-2012 Rule 2.2 */
  volatile uint8 endless = 1u;
  
  (void)Os_GetDetailedError(&CurrentError);
  
  //(void)GetTaskID(&TaskID);
  
  //while(endless)
  {
    
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_ERRORHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_ERRORHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ProtectionHook()
 *********************************************************************************************************************/
#if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
# define OS_START_SEC_PROTECTIONHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
 *********************************************************************************************************************/
	Os_ExceptionContextType ExceptionContext;
	Exception_Reset_Flag = (uint16)Fatalerror;
	Exception_Current_Task = Curren_Task_Id;
	Exception_CTPC = (uint32)__STSR(CTPC);

	if(E_OS_PROTECTION_MEMORY == Fatalerror)
	{
		Exception_FEIC = (uint32)__STSR(FEIC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Feic*/
		Exception_FEPC = (uint32)__STSR(FEPC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Fepc*/
		/*record MEA & MEI*/
		Exception_Memeory_MEA = (uint32)__STSR(MEA);  
		Exception_Memeory_MEI = (uint32)__STSR(MEI);  
		Os_GetExceptionContext(&ExceptionContext);
		Exception_LR = ExceptionContext.Lr;
	}
	else if(E_OS_PROTECTION_EXCEPTION == Fatalerror)
	{
		Exception_FEIC = (uint32)__STSR(FEIC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Feic*/
		Exception_FEPC = (uint32)__STSR(FEPC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Fepc*/
		Os_GetExceptionContext(&ExceptionContext);
		Exception_LR = ExceptionContext.Lr;
	}	
	else if(E_OS_SYS_PROTECTION_IRQ == Fatalerror)
	{
		Exception_EIIC = (uint32)__STSR(EIIC);
		Exception_EIPC = (uint32)__STSR(EIPC);
	}
	else
	{
		/*do nothing*/
	}
	if((u8IPC_IF_GroupId != 0xFF)||(u8IPC_IF_MajorId != 0xFF)||(u8IPC_IF_SubId != 0xFF)||(u16IPC_IF_Len != 0xFFFF))
	{
		IPC_Exception_GroupId=u8IPC_IF_GroupId;
		IPC_Exception_MajorId=u8IPC_IF_MajorId;
		IPC_Exception_SubId=u8IPC_IF_SubId;
		IPC_Exception_Len=u16IPC_IF_Len;
	}
	return PRO_SHUTDOWN;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PROTECTIONHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PROTECTIONHOOK_SYSTEM */


/**********************************************************************************************************************
 *  PreTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_PRETASKHOOK == STD_ON
# define OS_START_SEC_PRETASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
 *********************************************************************************************************************/
	MISC_OS_PreTask_Execution();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PRETASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PRETASKHOOK */


/**********************************************************************************************************************
 *  PostTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_POSTTASKHOOK == STD_ON
# define OS_START_SEC_POSTTASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
 *********************************************************************************************************************/

	MISC_OS_PostTask_Execution();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_POSTTASKHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_POSTTASKHOOK */


/**********************************************************************************************************************
 *  Os_PanicHook()
 *********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
# define OS_START_SEC_PANICHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PanicHook>
 *********************************************************************************************************************/
	Os_ExceptionContextType ExceptionContext;
	#define MIP		0x90	
	#define MDP 	0x91
	
	Exception_Reset_Flag = PANIC_ERROR;
	Exception_Current_Task = Curren_Task_Id;
	Exception_FEIC = (uint32)__STSR(FEIC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Feic*/
	Exception_FEPC = (uint32)__STSR(FEPC);/*OsCfg_Hal_Context_OsCore0_ExceptionContext.Fepc*/
	Exception_CTPC = (uint32)__STSR(CTPC);

	if((MIP == ((uint8)Exception_FEIC & MIP))||(MDP == ((uint8)Exception_FEIC & MDP)))
	{	
		
		Exception_Reset_Flag = PANIC_MPU_ERROR;		
		/*record MEA & MEI*/	
		Exception_Memeory_MEA = (uint32)__STSR(MEA);  
		Exception_Memeory_MEI = (uint32)__STSR(MEI);  
		Os_GetExceptionContext(&ExceptionContext);
		Exception_LR = ExceptionContext.Lr;
	}
	if((u8IPC_IF_GroupId != 0xFF)||(u8IPC_IF_MajorId != 0xFF)||(u8IPC_IF_SubId != 0xFF)||(u16IPC_IF_Len != 0xFFFF))
	{
		IPC_Exception_GroupId=u8IPC_IF_GroupId;
		IPC_Exception_MajorId=u8IPC_IF_MajorId;
		IPC_Exception_SubId=u8IPC_IF_SubId;
		IPC_Exception_Len=u16IPC_IF_Len;
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PANICHOOK_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PANICHOOK */



/* Unrecognized User Blocks */
#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: Os_Callout_Stubs.c
 *********************************************************************************************************************/
