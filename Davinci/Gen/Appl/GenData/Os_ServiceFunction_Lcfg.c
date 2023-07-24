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
 *              File: Os_ServiceFunction_Lcfg.c
 *   Generation Time: 2022-04-12 19:43:18
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_SERVICEFUNCTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_ServiceFunction_Cfg.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_ServiceFunction.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common_Types.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os.h"

/* Os externals dependencies */
#include "Platform_Types.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* User file includes */
#include "usrostyp.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Data type for packing user variables for: Csm_Decrypt */
typedef struct
{
  uint32 Arg1; /* IN - jobId */
  Crypto_OperationModeType Arg2; /* IN - mode */
  uint8* Arg3; /* IN - dataPtr */
  uint32 Arg4; /* IN - datalength */
  uint8* Arg5; /* OUT - resultPtr */
  uint32* Arg6; /* IN_OUT - resultLengthPtr */
  Std_ReturnType Returnvalue;
} Os_Csm_DecryptPackageType;

/*! Data type for packing user variables for: Csm_Encrypt */
typedef struct
{
  uint32 Arg1; /* IN - jobId */
  Crypto_OperationModeType Arg2; /* IN - mode */
  uint8* Arg3; /* IN - dataPtr */
  uint32 Arg4; /* IN - datalength */
  uint8* Arg5; /* OUT - resultPtr */
  uint32* Arg6; /* IN_OUT - resultLengthPtr */
  Std_ReturnType Returnvalue;
} Os_Csm_EncryptPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation */
typedef struct
{
  const EventSignalInfo_Type* Arg1; /* IN - event_signal_info */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation */
typedef struct
{
  uint16 Arg1; /* IN - signalId */
  uint32* Arg2; /* IN_OUT - value */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation */
typedef struct
{
  uint8* Arg1; /* IN_OUT - p_msg */
  uint16 Arg2; /* IN - len */
  uint8 Arg3; /* IN - priority */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
typedef struct
{
  uint16 Arg1; /* IN - kindId */
  uint8* Arg2; /* OUT - kindConfig */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo */
typedef struct
{
  uint8 Arg1; /* IN - OpStatus */
  uint8* Arg2; /* OUT - Result */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfoPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation */
typedef struct
{
  uint16 Arg1; /* IN - signalId */
  uint8* Arg2; /* IN_OUT - value */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation */
typedef struct
{
  uint16 Arg1; /* IN - signalId */
  EventSignalType* Arg2; /* IN_OUT - value */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus */
typedef struct
{
  ComEx_SignalGroupIdType Arg1; /* IN - GroupId */
  uint32* Arg2; /* OUT - E2eStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal */
typedef struct
{
  ComEx_SignalIdType Arg1; /* IN - SignalId */
  ComEx_ConstSignalDataType Arg2; /* IN - SignalDataPtr */
  uint8 Arg3; /* IN - Length */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignalPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation */
typedef struct
{
  uint8 Arg1; /* IN - Length */
  uint8* Arg2; /* IN_OUT - Data */
  uint8* Arg3; /* OUT - Status */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation */
typedef struct
{
  uint8 Arg1; /* IN - Length */
  uint8* Arg2; /* IN_OUT - Data */
  uint8* Arg3; /* OUT - Status */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation */
typedef struct
{
  uint8 Arg1; /* IN - Length */
  uint8* Arg2; /* IN_OUT - Data */
  uint8* Arg3; /* OUT - Status */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation */
typedef struct
{
  uint8 Arg1; /* IN - Length */
  uint8* Arg2; /* IN_OUT - Data */
  uint8* Arg3; /* OUT - Status */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_OperationPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar */
typedef struct
{
  sint64 Arg1; /* IN - utc */
  DateTimeType_t* Arg2; /* OUT - date */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendarPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter */
typedef struct
{
  CanFrameCounterType* Arg1; /* OUT - counter */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_CounterPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter */
typedef struct
{
  CanFrameCounterType* Arg1; /* OUT - counter */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_CounterPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter */
typedef struct
{
  CanFrameCounterType* Arg1; /* OUT - counter */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_CounterPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus */
typedef struct
{
  Dem_EventStatusType Arg1; /* IN - EventStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus */
typedef struct
{
  Dem_EventStatusType Arg1; /* IN - EventStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus */
typedef struct
{
  Dem_EventStatusType Arg1; /* IN - EventStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus */
typedef struct
{
  Dem_EventStatusType Arg1; /* IN - EventStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key */
typedef struct
{
  A_17Bytes* Arg1; /* OUT - IV */
  A_16Bytes* Arg2; /* OUT - KEY */
  uint32* Arg3; /* IN_OUT - key_len */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128KeyPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key */
typedef struct
{
  const A_16Bytes* Arg1; /* IN - IV */
  const A_16Bytes* Arg2; /* IN - KEY */
  uint32 Arg3; /* IN - key_len */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128KeyPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate */
typedef struct
{
  A_16Bytes* Arg1; /* OUT - Trng */
  uint32* Arg2; /* IN_OUT - len */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGeneratePackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis */
typedef struct
{
  uint64* Arg1; /* OUT - arg */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillisPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar */
typedef struct
{
  sint64 Arg1; /* IN - utc */
  DateTimeType_t* Arg2; /* OUT - date */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendarPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin */
typedef struct
{
  uint8 Arg1; /* IN - Id */
  boolean* Arg2; /* OUT - Pin */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPinPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage */
typedef struct
{
  uint8 Arg1; /* IN - Id */
  uint32* Arg2; /* OUT - Voltage */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltagePackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock */
typedef struct
{
  dtRef_const_VOID Arg1; /* IN - SrcPtr */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlockPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue */
typedef struct
{
  TimeInMicrosecondsType* Arg1; /* OUT - Value */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValuePackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue */
typedef struct
{
  TimeInMicrosecondsType* Arg1; /* IN_OUT - Value */
  TimeInMicrosecondsType* Arg2; /* OUT - ElapsedValue */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValuePackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
typedef struct
{
  uint16 Arg1; /* IN - kindId */
  uint8* Arg2; /* OUT - kindConfig */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick */
typedef struct
{
  TimeInMicrosecondsType* Arg1; /* OUT - updateTick */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTickPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus */
typedef struct
{
  ComEx_SignalGroupIdType Arg1; /* IN - GroupId */
  uint32* Arg2; /* OUT - E2eStatus */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatusPackageType;

/*! Data type for packing user variables for: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal */
typedef struct
{
  ComEx_SignalIdType Arg1; /* IN - SignalId */
  ComEx_ConstSignalDataType Arg2; /* IN - SignalDataPtr */
  uint8 Arg3; /* IN - Length */
  Std_ReturnType Returnvalue;
} Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignalPackageType;

/*! Data type for packing user variables for: Rte_TrustedCom_SendSignal */
typedef struct
{
  Com_SignalIdType Arg1; /* IN - SignalId */
  const void* Arg2; /* IN - SignalDataPtr */
  uint8 Returnvalue;
} Os_Rte_TrustedCom_SendSignalPackageType;


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Csm_Decrypt
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Csm_Decrypt
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Csm_Encrypt
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Csm_Encrypt
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCom_SendSignal
 *********************************************************************************************************************/
/*! \brief        Unpacking part of call stub for service functions.
 *  \details      Since the service of CallTrustedFunction() is very generic, it is needed to define a stub-interface
 *                which does the packing and unpacking of the arguments. This function performs the unpacking.
 *                It's signature matches the AUTOSAR trusted function interface.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCom_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Trusted function configuration data: Csm_Decrypt */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Csm_Decrypt =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Csm_Decrypt,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Csm_Encrypt */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Csm_Encrypt =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Csm_Encrypt,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal,
  /* .Context  = */ NULL_PTR
};

/*! Trusted function configuration data: Rte_TrustedCom_SendSignal */
CONST(Os_ServiceTfConfigType, OS_CONST) OsCfg_Service_Rte_TrustedCom_SendSignal =
{
  /* .Base     = */
  {
    /* .OwnerApplication = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .MpAccessRights   = */ &OsCfg_Mp_OsApplication_Trust_OsCore0,
    /* .ServiceType      = */ OS_SERVICE_TRUSTEDFUNCTION
  },
  /* .Callback = */ TRUSTED_Os_ServiceCallee_Rte_TrustedCom_SendSignal,
  /* .Context  = */ NULL_PTR
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for trusted functions. */
CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1] =                                /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule1.1_4521 */
{
  &OsCfg_Service_Csm_Decrypt,
  &OsCfg_Service_Csm_Encrypt,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation,
  &OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus,
  &OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal,
  &OsCfg_Service_Rte_TrustedCom_SendSignal,
  NULL_PTR
};

/*! Object reference table for non-trusted functions. */
CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule1.1_4521 */
{
  NULL_PTR
};

/*! Object reference table for fast trusted functions. */
CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule1.1_4521 */
{
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Csm_Decrypt
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Csm_Decrypt
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Csm_DecryptPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Csm_DecryptPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Csm_Decrypt
  (
    package->Arg1,
    package->Arg2,
    package->Arg3,
    package->Arg4,
    package->Arg5,
    package->Arg6
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Csm_Encrypt
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Csm_Encrypt
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Csm_EncryptPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Csm_EncryptPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Csm_Encrypt
  (
    package->Arg1,
    package->Arg2,
    package->Arg3,
    package->Arg4,
    package->Arg5,
    package->Arg6
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfoPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfoPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_OperationPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendarPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendarPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_CounterPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128KeyPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128KeyPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128KeyPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128KeyPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGeneratePackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGeneratePackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillisPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillisPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendarPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendarPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPinPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPinPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltagePackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltagePackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlockPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValuePackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValuePackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValuePackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValuePackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTickPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTickPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
  (
    package->Arg1
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatusPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatusPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
  (
    package->Arg1,
    package->Arg2,
    package->Arg3
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}

/**********************************************************************************************************************
 *  TRUSTED_Os_ServiceCallee_Rte_TrustedCom_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call service function.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) TRUSTED_Os_ServiceCallee_Rte_TrustedCom_SendSignal
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams                     /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  P2VAR(Os_Rte_TrustedCom_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT) package;
  package = (P2VAR(Os_Rte_TrustedCom_SendSignalPackageType, AUTOMATIC, OS_VAR_NOINIT)) FunctionParams;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */

  /* #10 Call service function. */
  package->Returnvalue = Rte_TrustedCom_SendSignal
  (
    package->Arg1,
    package->Arg2
  );

  OS_IGNORE_UNREF_PARAM(FunctionIndex);                                              /* PRQA S 3112 */ /* MD_Os_3112 */
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Os_Call_Csm_Decrypt
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Csm_Decrypt
(
  uint32 Arg1,
  Crypto_OperationModeType Arg2,
  uint8* Arg3,
  uint32 Arg4,
  uint8* Arg5,
  uint32* Arg6
)
{
  Os_Csm_DecryptPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;
  package.Arg4 = Arg4;
  package.Arg5 = Arg5;
  package.Arg6 = Arg6;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Csm_Decrypt, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Csm_Encrypt
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Csm_Encrypt
(
  uint32 Arg1,
  Crypto_OperationModeType Arg2,
  uint8* Arg3,
  uint32 Arg4,
  uint8* Arg5,
  uint32* Arg6
)
{
  Os_Csm_EncryptPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;
  package.Arg4 = Arg4;
  package.Arg5 = Arg5;
  package.Arg6 = Arg6;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Csm_Encrypt, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation
(
  const EventSignalInfo_Type* Arg1
)
{
  Os_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_OperationPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation
(
  uint16 Arg1,
  uint32* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation
(
  uint8* Arg1,
  uint16 Arg2,
  uint8 Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  uint16 Arg1,
  uint8* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo
(
  uint8 Arg1,
  uint8* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfoPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation
(
  uint16 Arg1,
  uint8* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation
(
  uint16 Arg1,
  EventSignalType* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus
(
  ComEx_SignalGroupIdType Arg1,
  uint32* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatusPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal
(
  ComEx_SignalIdType Arg1,
  ComEx_ConstSignalDataType Arg2,
  uint8 Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignalPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation
(
  uint8 Arg1,
  uint8* Arg2,
  uint8* Arg3
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_OperationPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar
(
  sint64 Arg1,
  DateTimeType_t* Arg2
)
{
  Os_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendarPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter
(
  CanFrameCounterType* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_CounterPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter
(
  CanFrameCounterType* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_CounterPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter
(
  CanFrameCounterType* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_CounterPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
(
  Dem_EventStatusType Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatusPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
(
  Dem_EventStatusType Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatusPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
(
  Dem_EventStatusType Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatusPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
(
  Dem_EventStatusType Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatusPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key
(
  A_17Bytes* Arg1,
  A_16Bytes* Arg2,
  uint32* Arg3
)
{
  Os_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128KeyPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key
(
  const A_16Bytes* Arg1,
  const A_16Bytes* Arg2,
  uint32 Arg3
)
{
  Os_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128KeyPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate
(
  A_16Bytes* Arg1,
  uint32* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGeneratePackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis
(
  uint64* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillisPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar
(
  sint64 Arg1,
  DateTimeType_t* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendarPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin
(
  uint8 Arg1,
  boolean* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPinPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage
(
  uint8 Arg1,
  uint32* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltagePackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock
(
  dtRef_const_VOID Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlockPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue
(
  TimeInMicrosecondsType* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValuePackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue
(
  TimeInMicrosecondsType* Arg1,
  TimeInMicrosecondsType* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValuePackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
(
  uint16 Arg1,
  uint8* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfigPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
(
  TimeInMicrosecondsType* Arg1
)
{
  Os_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTickPackageType package;
  package.Arg1 = Arg1;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus
(
  ComEx_SignalGroupIdType Arg1,
  uint32* Arg2
)
{
  Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatusPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(Std_ReturnType, OS_CODE) Os_Call_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal
(
  ComEx_SignalIdType Arg1,
  ComEx_ConstSignalDataType Arg2,
  uint8 Arg3
)
{
  Os_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignalPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;
  package.Arg3 = Arg3;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

/**********************************************************************************************************************
 *  Os_Call_Rte_TrustedCom_SendSignal
 *********************************************************************************************************************/
 /*!
 * \internal
 * - #10 Call trusted function.
 * \endinternal
 */
FUNC(uint8, OS_CODE) Os_Call_Rte_TrustedCom_SendSignal
(
  Com_SignalIdType Arg1,
  const void* Arg2
)
{
  Os_Rte_TrustedCom_SendSignalPackageType package;
  package.Arg1 = Arg1;
  package.Arg2 = Arg2;

  /* #10 Call trusted function. */
  (void)CallTrustedFunction(Os_ServiceCallee_Rte_TrustedCom_SendSignal, (TrustedFunctionParameterRefType)&package);  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */

  return package.Returnvalue;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.c
 *********************************************************************************************************************/
