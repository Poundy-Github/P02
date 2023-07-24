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
 *             File:  Rte_Power_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Power>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_POWER_TYPE_H
# define RTE_POWER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Disarmed
#   define Cx0_Disarmed (0U)
#  endif

#  ifndef Cx1_Armed
#   define Cx1_Armed (1U)
#  endif

#  ifndef Cx2_Prearmed
#   define Cx2_Prearmed (2U)
#  endif

#  ifndef Cx3_Alarmed
#   define Cx3_Alarmed (3U)
#  endif

#  ifndef Vol_Disable
#   define Vol_Disable (0U)
#  endif

#  ifndef Vol_Enable
#   define Vol_Enable (1U)
#  endif

#  ifndef BswMReqSleep
#   define BswMReqSleep (1U)
#  endif

#  ifndef BswMReqShutdown
#   define BswMReqShutdown (3U)
#  endif

#  ifndef BswMReqShutdownEmergency
#   define BswMReqShutdownEmergency (4U)
#  endif

#  ifndef BswMReqNone
#   define BswMReqNone (0U)
#  endif

#  ifndef BswMReqSleepEmergency
#   define BswMReqSleepEmergency (5U)
#  endif

#  ifndef Cx0_Current_gear_N_or_P_
#   define Cx0_Current_gear_N_or_P_ (0U)
#  endif

#  ifndef Cx1_Current_gear_1_
#   define Cx1_Current_gear_1_ (1U)
#  endif

#  ifndef Cx2_Current_gear_2_
#   define Cx2_Current_gear_2_ (2U)
#  endif

#  ifndef Cx3_Current_gear_3_
#   define Cx3_Current_gear_3_ (3U)
#  endif

#  ifndef Cx4_Current_gear_4_
#   define Cx4_Current_gear_4_ (4U)
#  endif

#  ifndef Cx5_Current_gear_5_
#   define Cx5_Current_gear_5_ (5U)
#  endif

#  ifndef Cx6_Current_gear_6_
#   define Cx6_Current_gear_6_ (6U)
#  endif

#  ifndef Cx7_Current_gear_7_
#   define Cx7_Current_gear_7_ (7U)
#  endif

#  ifndef Cx8_Current_gear_R_
#   define Cx8_Current_gear_R_ (8U)
#  endif

#  ifndef Cx9_Reserved
#   define Cx9_Reserved (9U)
#  endif

#  ifndef CxF_Reserved
#   define CxF_Reserved (15U)
#  endif

#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#   define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
#  endif

#  ifndef Cx0_Lock
#   define Cx0_Lock (0U)
#  endif

#  ifndef Cx1_Unlock
#   define Cx1_Unlock (1U)
#  endif

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_ON
#   define Cx1_ON (1U)
#  endif

#  ifndef Cx0_No_error
#   define Cx0_No_error (0U)
#  endif

#  ifndef Cx1_error
#   define Cx1_error (1U)
#  endif

#  ifndef Cx2_Reservrd
#   define Cx2_Reservrd (2U)
#  endif

#  ifndef Cx3_Reservrd
#   define Cx3_Reservrd (3U)
#  endif

#  ifndef Cx0_Normal_mode
#   define Cx0_Normal_mode (0U)
#  endif

#  ifndef Cx1_Remote_mode
#   define Cx1_Remote_mode (1U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_OFF
#   define SYSTEMSTATE_Cluster_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_STANDBY
#   define SYSTEMSTATE_Cluster_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_ON
#   define SYSTEMSTATE_Cluster_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_STARTUP
#   define SYSTEMSTATE_Cluster_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_SHUTDOWN
#   define SYSTEMSTATE_Cluster_SHUTDOWN (4U)
#  endif

#  ifndef SYSTEMSTATE_IVI_OFF
#   define SYSTEMSTATE_IVI_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_IVI_STANDBY
#   define SYSTEMSTATE_IVI_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON
#   define SYSTEMSTATE_IVI_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_IVI_SHUTDOWN
#   define SYSTEMSTATE_IVI_SHUTDOWN (3U)
#  endif

#  ifndef SYSTEMSTATE_IVI_REMOTE
#   define SYSTEMSTATE_IVI_REMOTE (4U)
#  endif

#  ifndef SYSTEMSTATE_IVI_DEMO
#   define SYSTEMSTATE_IVI_DEMO (5U)
#  endif

#  ifndef SYSTEMSTATE_IVI_AWAKEHOLD
#   define SYSTEMSTATE_IVI_AWAKEHOLD (6U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_NORMAL
#   define SYSTEMSTATE_IVI_ON_NORMAL (7U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_ERROR
#   define SYSTEMSTATE_IVI_ON_POWER_ERROR (8U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_SAVE_1
#   define SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (9U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_SAVE_2
#   define SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (10U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_LOCAL
#   define SYSTEMSTATE_IVI_ON_LOCAL (11U)
#  endif

#  ifndef SYSTEMSTATE_HUD_OFF
#   define SYSTEMSTATE_HUD_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_HUD_STANDBY
#   define SYSTEMSTATE_HUD_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_HUD_ON
#   define SYSTEMSTATE_HUD_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_HUD_STARTUP
#   define SYSTEMSTATE_HUD_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_HUD_SHUTDOWN
#   define SYSTEMSTATE_HUD_SHUTDOWN (4U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_OFF
#   define SYSTEMSTATE_CONSOLE_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_STANDBY
#   define SYSTEMSTATE_CONSOLE_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_ON
#   define SYSTEMSTATE_CONSOLE_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_STARTUP
#   define SYSTEMSTATE_CONSOLE_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_SHUTDOWN
#   define SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
#  endif

#  ifndef KL15OFF
#   define KL15OFF (0U)
#  endif

#  ifndef KL15ON
#   define KL15ON (1U)
#  endif

#  ifndef VOLTAGE_OUT_LOWSLEEP
#   define VOLTAGE_OUT_LOWSLEEP (0U)
#  endif

#  ifndef VOLTAGE_OUT_NORMAL
#   define VOLTAGE_OUT_NORMAL (1U)
#  endif

#  ifndef VOLTAGE_OUT_HIGHALARM
#   define VOLTAGE_OUT_HIGHALARM (2U)
#  endif

#  ifndef VOLTAGE_OUT_HIGHSLEEP
#   define VOLTAGE_OUT_HIGHSLEEP (3U)
#  endif

#  ifndef VOLTAGE_OUT_LOWALARM
#   define VOLTAGE_OUT_LOWALARM (4U)
#  endif

#  ifndef VOLTAGE_OUT_NUM
#   define VOLTAGE_OUT_NUM (5U)
#  endif

#  ifndef SYSTEMSTATE_SP_OFF
#   define SYSTEMSTATE_SP_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_SP_SHUTDOWN
#   define SYSTEMSTATE_SP_SHUTDOWN (1U)
#  endif

#  ifndef SYSTEMSTATE_SP_STANDBY
#   define SYSTEMSTATE_SP_STANDBY (2U)
#  endif

#  ifndef SYSTEMSTATE_SP_SOCOFF
#   define SYSTEMSTATE_SP_SOCOFF (3U)
#  endif

#  ifndef TEMP_LOW_SLEEP
#   define TEMP_LOW_SLEEP (0U)
#  endif

#  ifndef TEMP_NORMAL
#   define TEMP_NORMAL (1U)
#  endif

#  ifndef TEMP_HIGH_PROTECT
#   define TEMP_HIGH_PROTECT (2U)
#  endif

#  ifndef TEMP_HIGH_SLEEP
#   define TEMP_HIGH_SLEEP (3U)
#  endif

#  ifndef TEMP_STATE_NUM
#   define TEMP_STATE_NUM (4U)
#  endif

#  ifndef TEMP_STATE_INIT
#   define TEMP_STATE_INIT (255U)
#  endif

#  ifndef Cx0_Normal
#   define Cx0_Normal (0U)
#  endif

#  ifndef Cx1_Level_1
#   define Cx1_Level_1 (1U)
#  endif

#  ifndef Cx2_Level_2
#   define Cx2_Level_2 (2U)
#  endif

#  ifndef Cx3_Reserved
#   define Cx3_Reserved (3U)
#  endif

#  ifndef Cx7_Reserved
#   define Cx7_Reserved (7U)
#  endif

#  ifndef Cx1_ACC_reserved_
#   define Cx1_ACC_reserved_ (1U)
#  endif

#  ifndef Cx2_ON
#   define Cx2_ON (2U)
#  endif

#  ifndef Cx3_Crank
#   define Cx3_Crank (3U)
#  endif

#  ifndef Cx0_Invalid
#   define Cx0_Invalid (0U)
#  endif

#  ifndef Cx1_Valid
#   define Cx1_Valid (1U)
#  endif

#  ifndef Cx0_Normal_Mode
#   define Cx0_Normal_Mode (0U)
#  endif

#  ifndef Cx1_Transport_Mode
#   define Cx1_Transport_Mode (1U)
#  endif

#  ifndef McuRstRsnConfClm0
#   define McuRstRsnConfClm0 (4U)
#  endif

#  ifndef McuRstRsnConfClm1
#   define McuRstRsnConfClm1 (5U)
#  endif

#  ifndef McuRstRsnConfClm2
#   define McuRstRsnConfClm2 (6U)
#  endif

#  ifndef McuRstRsnConfClm3
#   define McuRstRsnConfClm3 (15U)
#  endif

#  ifndef McuRstRsnConfCvm
#   define McuRstRsnConfCvm (8U)
#  endif

#  ifndef McuRstRsnConfIso
#   define McuRstRsnConfIso (11U)
#  endif

#  ifndef McuRstRsnConfLvi
#   define McuRstRsnConfLvi (7U)
#  endif

#  ifndef McuRstRsnConfMultipleResets
#   define McuRstRsnConfMultipleResets (17U)
#  endif

#  ifndef McuRstRsnConfPOR
#   define McuRstRsnConfPOR (10U)
#  endif

#  ifndef McuRstRsnConfResf11
#   define McuRstRsnConfResf11 (12U)
#  endif

#  ifndef McuRstRsnConfResf12
#   define McuRstRsnConfResf12 (13U)
#  endif

#  ifndef McuRstRsnConfResf13
#   define McuRstRsnConfResf13 (14U)
#  endif

#  ifndef McuRstRsnConfSwRst
#   define McuRstRsnConfSwRst (1U)
#  endif

#  ifndef McuRstRsnConfTer
#   define McuRstRsnConfTer (9U)
#  endif

#  ifndef McuRstRsnConfUndef
#   define McuRstRsnConfUndef (16U)
#  endif

#  ifndef McuRstRsnConfUnknown
#   define McuRstRsnConfUnknown (18U)
#  endif

#  ifndef McuRstRsnConfWdta0
#   define McuRstRsnConfWdta0 (2U)
#  endif

#  ifndef McuRstRsnConfWdta1
#   define McuRstRsnConfWdta1 (3U)
#  endif

#  ifndef init
#   define init (0U)
#  endif

#  ifndef value0
#   define value0 (0U)
#  endif

#  ifndef bit1
#   define bit1 (1U)
#  endif

#  ifndef bit2
#   define bit2 (2U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_DcmEcuReset
#  define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
# endif

# define RTE_MODE_Power_DcmEcuReset_NONE (0U)
# ifndef RTE_MODE_DcmEcuReset_NONE
#  define RTE_MODE_DcmEcuReset_NONE (0U)
# endif
# define RTE_MODE_Power_DcmEcuReset_HARD (1U)
# ifndef RTE_MODE_DcmEcuReset_HARD
#  define RTE_MODE_DcmEcuReset_HARD (1U)
# endif
# define RTE_MODE_Power_DcmEcuReset_KEYONOFF (2U)
# ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#  define RTE_MODE_DcmEcuReset_KEYONOFF (2U)
# endif
# define RTE_MODE_Power_DcmEcuReset_SOFT (3U)
# ifndef RTE_MODE_DcmEcuReset_SOFT
#  define RTE_MODE_DcmEcuReset_SOFT (3U)
# endif
# define RTE_MODE_Power_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# endif
# define RTE_MODE_Power_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# endif
# define RTE_MODE_Power_DcmEcuReset_EXECUTE (6U)
# ifndef RTE_MODE_DcmEcuReset_EXECUTE
#  define RTE_MODE_DcmEcuReset_EXECUTE (6U)
# endif
# define RTE_TRANSITION_Power_DcmEcuReset (7U)
# ifndef RTE_TRANSITION_DcmEcuReset
#  define RTE_TRANSITION_DcmEcuReset (7U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_POWER_TYPE_H */
