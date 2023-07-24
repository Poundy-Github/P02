/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_NvM.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <NvM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_NVM_H
# define RTE_NVM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_NvM_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_ActiveWUCounter_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Menu_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterInternalConfiguration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_E2ESwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_FactoryMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_SecOcSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleSoftwareVersion_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF187_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF18C_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF193_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF195_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD00_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD19_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE20_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE21_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE22_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE23_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE24_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE25_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_SOCManagerNvBlockNeed_HealthSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration2_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration2_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_ActiveWUCounter_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_ActiveWUCounter_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_MaintainOdo_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_MaintainOdo_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_1_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_1_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_2_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_2_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_3_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_3_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_4_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_4_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_5_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_5_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_Trip_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_Trip_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Menu_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Menu_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterInternalConfiguration_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterInternalConfiguration_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_E2ESwitch_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_E2ESwitch_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_FactoryMode_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_FactoryMode_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_SecOcSwitch_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_SecOcSwitch_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VIN_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VIN_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleMode_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleMode_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleSoftwareVersion_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleSoftwareVersion_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF187_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF187_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF18C_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF18C_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF193_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF193_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF195_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF195_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD00_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD00_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD19_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD19_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE20_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE20_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE21_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE21_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE22_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE22_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE23_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE23_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE24_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE24_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE25_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE25_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished
#  define Rte_Call_NvM_RpNotifyJobEnd_SOCManagerNvBlockNeed_HealthSwitch_JobFinished Rte_Call_NvM_NvM_RpNotifyJobEnd_SOCManagerNvBlockNeed_HealthSwitch_JobFinished


# endif /* !defined(RTE_CORE) */


# define NvM_START_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EraseBlock NvM_EraseNvBlock
#  define RTE_RUNNABLE_GetErrorStatus NvM_GetErrorStatus
#  define RTE_RUNNABLE_InvalidateNvBlock NvM_InvalidateNvBlock
#  define RTE_RUNNABLE_NvM_MainFunction NvM_MainFunction
#  define RTE_RUNNABLE_ReadBlock NvM_ReadBlock
#  define RTE_RUNNABLE_RestoreBlockDefaults NvM_RestoreBlockDefaults
#  define RTE_RUNNABLE_SetBlockProtection NvM_SetBlockProtection
#  define RTE_RUNNABLE_SetRamBlockStatus NvM_SetRamBlockStatus
#  define RTE_RUNNABLE_WriteBlock NvM_WriteBlock
# endif

FUNC(Std_ReturnType, NvM_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, NvM_CODE) NvM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, NvM_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetBlockProtection(NvM_BlockIdType parg0, boolean ProtectionEnabled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, NvM_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define NvM_STOP_SEC_CODE
# include "NvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMAdministration_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_NVM_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
