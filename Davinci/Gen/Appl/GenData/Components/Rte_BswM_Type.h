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
 *             File:  Rte_BswM_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <BswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BSWM_TYPE_H
# define RTE_BSWM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef BLOCK_STATE
#   define BLOCK_STATE (1U)
#  endif

#  ifndef UNBLOCK_STATE
#   define UNBLOCK_STATE (0U)
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

#  ifndef FUEL
#   define FUEL (0U)
#  endif

#  ifndef EV
#   define EV (1U)
#  endif

#  ifndef STARTUP
#   define STARTUP (0U)
#  endif

#  ifndef RUN
#   define RUN (1U)
#  endif

#  ifndef POSTRUN
#   define POSTRUN (2U)
#  endif

#  ifndef WAKEUP
#   define WAKEUP (3U)
#  endif

#  ifndef SHUTDOWN
#   define SHUTDOWN (4U)
#  endif

#  ifndef NVMPROCESS
#   define NVMPROCESS (5U)
#  endif

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
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
# ifndef RTE_MODETYPE_BswMRteModeBusStateReq
#  define RTE_MODETYPE_BswMRteModeBusStateReq
typedef BswM_BswMRteModeBusStateReq Rte_ModeType_BswMRteModeBusStateReq;
# endif
# ifndef RTE_MODETYPE_BswMRteModeVolEnable
#  define RTE_MODETYPE_BswMRteModeVolEnable
typedef BswM_BswMRteModeVolEnable Rte_ModeType_BswMRteModeVolEnable;
# endif
# ifndef RTE_MODETYPE_BswMRteShutdownReqMode
#  define RTE_MODETYPE_BswMRteShutdownReqMode
typedef BswM_BswMRteShutdownReqMode Rte_ModeType_BswMRteShutdownReqMode;
# endif
# ifndef RTE_MODETYPE_BswMRteVehicleTypeOptionChoose
#  define RTE_MODETYPE_BswMRteVehicleTypeOptionChoose
typedef BswM_BswMRteVehicleTypeOptionChoose Rte_ModeType_BswMRteVehicleTypeOptionChoose;
# endif
# ifndef RTE_MODETYPE_ESH_Mode
#  define RTE_MODETYPE_ESH_Mode
typedef BswM_ESH_Mode Rte_ModeType_ESH_Mode;
# endif
# ifndef RTE_MODETYPE_ESH_RunRequest
#  define RTE_MODETYPE_ESH_RunRequest
typedef BswM_ESH_RunRequest Rte_ModeType_ESH_RunRequest;
# endif

# define RTE_MODE_BswM_BswMRteModeBusStateReq_UNBLOCK_STATE (0U)
# ifndef RTE_MODE_BswMRteModeBusStateReq_UNBLOCK_STATE
#  define RTE_MODE_BswMRteModeBusStateReq_UNBLOCK_STATE (0U)
# endif
# define RTE_MODE_BswM_BswMRteModeBusStateReq_BLOCK_STATE (1U)
# ifndef RTE_MODE_BswMRteModeBusStateReq_BLOCK_STATE
#  define RTE_MODE_BswMRteModeBusStateReq_BLOCK_STATE (1U)
# endif
# define RTE_TRANSITION_BswM_BswMRteModeBusStateReq (2U)
# ifndef RTE_TRANSITION_BswMRteModeBusStateReq
#  define RTE_TRANSITION_BswMRteModeBusStateReq (2U)
# endif

# define RTE_MODE_BswM_BswMRteModeVolEnable_Vol_Disable (0U)
# ifndef RTE_MODE_BswMRteModeVolEnable_Vol_Disable
#  define RTE_MODE_BswMRteModeVolEnable_Vol_Disable (0U)
# endif
# define RTE_MODE_BswM_BswMRteModeVolEnable_Vol_Enable (1U)
# ifndef RTE_MODE_BswMRteModeVolEnable_Vol_Enable
#  define RTE_MODE_BswMRteModeVolEnable_Vol_Enable (1U)
# endif
# define RTE_TRANSITION_BswM_BswMRteModeVolEnable (2U)
# ifndef RTE_TRANSITION_BswMRteModeVolEnable
#  define RTE_TRANSITION_BswMRteModeVolEnable (2U)
# endif

# define RTE_MODE_BswM_BswMRteShutdownReqMode_BswMReqNone (0U)
# ifndef RTE_MODE_BswMRteShutdownReqMode_BswMReqNone
#  define RTE_MODE_BswMRteShutdownReqMode_BswMReqNone (0U)
# endif
# define RTE_MODE_BswM_BswMRteShutdownReqMode_BswMReqSleep (1U)
# ifndef RTE_MODE_BswMRteShutdownReqMode_BswMReqSleep
#  define RTE_MODE_BswMRteShutdownReqMode_BswMReqSleep (1U)
# endif
# define RTE_MODE_BswM_BswMRteShutdownReqMode_BswMReqShutdown (3U)
# ifndef RTE_MODE_BswMRteShutdownReqMode_BswMReqShutdown
#  define RTE_MODE_BswMRteShutdownReqMode_BswMReqShutdown (3U)
# endif
# define RTE_MODE_BswM_BswMRteShutdownReqMode_BswMReqShutdownEmergency (4U)
# ifndef RTE_MODE_BswMRteShutdownReqMode_BswMReqShutdownEmergency
#  define RTE_MODE_BswMRteShutdownReqMode_BswMReqShutdownEmergency (4U)
# endif
# define RTE_MODE_BswM_BswMRteShutdownReqMode_BswMReqSleepEmergency (5U)
# ifndef RTE_MODE_BswMRteShutdownReqMode_BswMReqSleepEmergency
#  define RTE_MODE_BswMRteShutdownReqMode_BswMReqSleepEmergency (5U)
# endif
# define RTE_TRANSITION_BswM_BswMRteShutdownReqMode (5U)
# ifndef RTE_TRANSITION_BswMRteShutdownReqMode
#  define RTE_TRANSITION_BswMRteShutdownReqMode (5U)
# endif

# define RTE_MODE_BswM_BswMRteVehicleTypeOptionChoose_FUEL (0U)
# ifndef RTE_MODE_BswMRteVehicleTypeOptionChoose_FUEL
#  define RTE_MODE_BswMRteVehicleTypeOptionChoose_FUEL (0U)
# endif
# define RTE_MODE_BswM_BswMRteVehicleTypeOptionChoose_EV (1U)
# ifndef RTE_MODE_BswMRteVehicleTypeOptionChoose_EV
#  define RTE_MODE_BswMRteVehicleTypeOptionChoose_EV (1U)
# endif
# define RTE_TRANSITION_BswM_BswMRteVehicleTypeOptionChoose (2U)
# ifndef RTE_TRANSITION_BswMRteVehicleTypeOptionChoose
#  define RTE_TRANSITION_BswMRteVehicleTypeOptionChoose (2U)
# endif

# define RTE_MODE_BswM_ESH_Mode_STARTUP (0U)
# ifndef RTE_MODE_ESH_Mode_STARTUP
#  define RTE_MODE_ESH_Mode_STARTUP (0U)
# endif
# define RTE_MODE_BswM_ESH_Mode_RUN (1U)
# ifndef RTE_MODE_ESH_Mode_RUN
#  define RTE_MODE_ESH_Mode_RUN (1U)
# endif
# define RTE_MODE_BswM_ESH_Mode_POSTRUN (2U)
# ifndef RTE_MODE_ESH_Mode_POSTRUN
#  define RTE_MODE_ESH_Mode_POSTRUN (2U)
# endif
# define RTE_MODE_BswM_ESH_Mode_WAKEUP (3U)
# ifndef RTE_MODE_ESH_Mode_WAKEUP
#  define RTE_MODE_ESH_Mode_WAKEUP (3U)
# endif
# define RTE_MODE_BswM_ESH_Mode_SHUTDOWN (4U)
# ifndef RTE_MODE_ESH_Mode_SHUTDOWN
#  define RTE_MODE_ESH_Mode_SHUTDOWN (4U)
# endif
# define RTE_MODE_BswM_ESH_Mode_NVMPROCESS (5U)
# ifndef RTE_MODE_ESH_Mode_NVMPROCESS
#  define RTE_MODE_ESH_Mode_NVMPROCESS (5U)
# endif
# define RTE_TRANSITION_BswM_ESH_Mode (6U)
# ifndef RTE_TRANSITION_ESH_Mode
#  define RTE_TRANSITION_ESH_Mode (6U)
# endif

# define RTE_MODE_BswM_ESH_RunRequest_RELEASED (0U)
# ifndef RTE_MODE_ESH_RunRequest_RELEASED
#  define RTE_MODE_ESH_RunRequest_RELEASED (0U)
# endif
# define RTE_MODE_BswM_ESH_RunRequest_REQUESTED (1U)
# ifndef RTE_MODE_ESH_RunRequest_REQUESTED
#  define RTE_MODE_ESH_RunRequest_REQUESTED (1U)
# endif
# define RTE_TRANSITION_BswM_ESH_RunRequest (2U)
# ifndef RTE_TRANSITION_ESH_RunRequest
#  define RTE_TRANSITION_ESH_RunRequest (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BSWM_TYPE_H */
