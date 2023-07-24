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
 *             File:  Rte_AMP_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <AMP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_AMP_TYPE_H
# define RTE_AMP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef DEM_DTC_FORMAT_OBD
#   define DEM_DTC_FORMAT_OBD (0U)
#  endif

#  ifndef DEM_DTC_FORMAT_UDS
#   define DEM_DTC_FORMAT_UDS (1U)
#  endif

#  ifndef DEM_DTC_FORMAT_J1939
#   define DEM_DTC_FORMAT_J1939 (2U)
#  endif

#  ifndef DEM_DEBOUNCE_STATUS_FREEZE
#   define DEM_DEBOUNCE_STATUS_FREEZE (0U)
#  endif

#  ifndef DEM_DEBOUNCE_STATUS_RESET
#   define DEM_DEBOUNCE_STATUS_RESET (1U)
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

#  ifndef DEM_UDS_STATUS_TF
#   define DEM_UDS_STATUS_TF (1U)
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflMask
#   define DEM_UDS_STATUS_TF_BflMask 1U
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflPn
#   define DEM_UDS_STATUS_TF_BflPn 0U
#  endif

#  ifndef DEM_UDS_STATUS_TF_BflLn
#   define DEM_UDS_STATUS_TF_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC
#   define DEM_UDS_STATUS_TFTOC (2U)
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflMask
#   define DEM_UDS_STATUS_TFTOC_BflMask 2U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflPn
#   define DEM_UDS_STATUS_TFTOC_BflPn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFTOC_BflLn
#   define DEM_UDS_STATUS_TFTOC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC
#   define DEM_UDS_STATUS_PDTC (4U)
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflMask
#   define DEM_UDS_STATUS_PDTC_BflMask 4U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflPn
#   define DEM_UDS_STATUS_PDTC_BflPn 2U
#  endif

#  ifndef DEM_UDS_STATUS_PDTC_BflLn
#   define DEM_UDS_STATUS_PDTC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC
#   define DEM_UDS_STATUS_CDTC (8U)
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflMask
#   define DEM_UDS_STATUS_CDTC_BflMask 8U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflPn
#   define DEM_UDS_STATUS_CDTC_BflPn 3U
#  endif

#  ifndef DEM_UDS_STATUS_CDTC_BflLn
#   define DEM_UDS_STATUS_CDTC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC
#   define DEM_UDS_STATUS_TNCSLC (16U)
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflMask
#   define DEM_UDS_STATUS_TNCSLC_BflMask 16U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflPn
#   define DEM_UDS_STATUS_TNCSLC_BflPn 4U
#  endif

#  ifndef DEM_UDS_STATUS_TNCSLC_BflLn
#   define DEM_UDS_STATUS_TNCSLC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC
#   define DEM_UDS_STATUS_TFSLC (32U)
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflMask
#   define DEM_UDS_STATUS_TFSLC_BflMask 32U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflPn
#   define DEM_UDS_STATUS_TFSLC_BflPn 5U
#  endif

#  ifndef DEM_UDS_STATUS_TFSLC_BflLn
#   define DEM_UDS_STATUS_TFSLC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC
#   define DEM_UDS_STATUS_TNCTOC (64U)
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflMask
#   define DEM_UDS_STATUS_TNCTOC_BflMask 64U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflPn
#   define DEM_UDS_STATUS_TNCTOC_BflPn 6U
#  endif

#  ifndef DEM_UDS_STATUS_TNCTOC_BflLn
#   define DEM_UDS_STATUS_TNCTOC_BflLn 1U
#  endif

#  ifndef DEM_UDS_STATUS_WIR
#   define DEM_UDS_STATUS_WIR (128U)
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflMask
#   define DEM_UDS_STATUS_WIR_BflMask 128U
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflPn
#   define DEM_UDS_STATUS_WIR_BflPn 7U
#  endif

#  ifndef DEM_UDS_STATUS_WIR_BflLn
#   define DEM_UDS_STATUS_WIR_BflLn 1U
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_AMP_TYPE_H */
