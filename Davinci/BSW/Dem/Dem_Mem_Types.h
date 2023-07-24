/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*! \addtogroup Dem_Mem
 *  \{
 *  \file       Dem_Mem_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Erik Jeglorz                  visejz        Vector Informatik GmbH
 *  Friederike Hitzler            visfrs        Vector Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vector Informatik GmbH
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  Erwin Stamm                   visern        Vector Informatik GmbH
 *  Laura Henze                   visera        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_MEM_TYPES_H)
#define DEM_MEM_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

#include "Dem_MemAccess_Types.h"
#include "Dem_MemState_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*! Aging counter threshold for PID aging */
#define DEM_MEM_PID_AGING_COUNTER_THRESHOLD      0x28U


/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* Entry->State currently used bits: 0x89 */
/*! Set not qualified status bits  */
#define DEM_MEM_SET_NON_QUALIFIED_STATUS_BITS(Reg)            ((uint8)((Reg) | 0x77U))                                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Applies qualified status to memory entry status byte */
#define DEM_MEM_APPLY_QUALIFIED_STATUS(State, QualifyStatus)  ((uint8)(((State) & 0x77U) | ((QualifyStatus) & 0x88U)))           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Test aging only state of memory entry status byte */
#define DEM_MEM_TEST_AGING_ONLY(State)           ((uint8)((State) & 0x01U) == 0x01U)                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set aging only state of memory entry status byte */
#define DEM_MEM_SET_AGING_ONLY(State)            ((uint8)((State) | 0x01U))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Reset aging only state of memory entry status byte */
#define DEM_MEM_RESET_AGING_ONLY(State)          ((uint8)((State) & 0xfeU))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/*! Get the PID41 disabled mask state */
# define Dem_Mem_GetPid41DisabledMask()          (Dem_Cfg_AdminData.Pid41DisabledMask)                                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the PID41 disabled mask state */
# define Dem_Mem_SetPid41DisabledMask(Value)     (Dem_Cfg_AdminData.Pid41DisabledMask = (Value))                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/*! Get the PID01 completed mask state */
# define Dem_Mem_GetPid01CompletedMask()         (Dem_Cfg_StatusData.Pid01CompletedMask)                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the PID01 completed mask state */
# define Dem_Mem_SetPid01CompletedMask(Value)    (Dem_Cfg_StatusData.Pid01CompletedMask = (Value))                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/* Event Memory */
/*! Get EventId of a memory entry */
#define Dem_Mem_EntryGetEventId(Entry)           ((Entry)->EventId)                                                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set EventId of a memory entry */
#define Dem_Mem_EntrySetEventId(Entry, Id)       (Entry)->EventId = (Id)                                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get TimeStamp of a memory entry */
#define Dem_Mem_EntryGetTimestamp(Entry)         ((Entry)->Timestamp)                                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set TimeStamp of a memory entry */
#define Dem_Mem_EntrySetTimestamp(Entry, Time)   (Entry)->Timestamp = (Time)                                                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get unused past normal samples of a time series entry */
# define Dem_Mem_GetUnusedPastSamplesNormal(Entry)       ((Entry)->UnusedPastSamples_NormalRate)                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set unused past normal samples of a time series entry */
# define Dem_Mem_SetUnusedPastSamplesNormal(Entry, Nr)   (Entry)->UnusedPastSamples_NormalRate = (Nr)                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get unused past fast samples of a time series entry */
# define Dem_Mem_GetUnusedPastSamplesFast(Entry)         ((Entry)->UnusedPastSamples_FastRate)                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set unused past fast samples of a time series entry */
# define Dem_Mem_SetUnusedPastSamplesFast(Entry, Nr)     (Entry)->UnusedPastSamples_FastRate = (Nr)                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get unused future normal samples of a time series entry */
# define Dem_Mem_GetUnusedFutureSamplesNormal(Entry)     ((Entry)->UnusedFutureSamples_NormalRate)                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set unused future normal samples of a time series entry */
# define Dem_Mem_SetUnusedFutureSamplesNormal(Entry, Nr) (Entry)->UnusedFutureSamples_NormalRate = (Nr)                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get unused future fast samples of a time series entry */
# define Dem_Mem_GetUnusedFutureSamplesFast(Entry)       ((Entry)->UnusedFutureSamples_FastRate)                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set unused future fast samples of a time series entry */
# define Dem_Mem_SetUnusedFutureSamplesFast(Entry, Nr)   (Entry)->UnusedFutureSamples_FastRate = (Nr)                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get the memory index of a time series block */
# define Dem_Mem_TimeSeriesGetIndex(MemoryInfo, EntryIndex)  (Dem_MemState_MemoryGetFirstIndex(MemoryInfo) + (EntryIndex)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the first valid time series memory index */
# define Dem_Mem_TimeSeriesIndexAll_Begin()      (Dem_Cfg_MemoryTimeSeriesIndex())                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Get the first invalid time series memory index */
# define Dem_Mem_TimeSeriesIndexAll_End()        (Dem_Mem_TimeSeriesIndexAll_Begin() + Dem_Cfg_GlobalTimeSeriesMaxCount())       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Test if a memory index is used for a time series memory block  */
# define Dem_Mem_IsTimeSeriesEntryIndex(Index)   (((Index) >= Dem_Mem_TimeSeriesIndexAll_Begin()) && ((Index) < Dem_Mem_TimeSeriesIndexAll_End())) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
#  if (DEM_CFG_SUPPORT_PERMANENTDTC_ACTIVATION_DISTANCE == STD_ON)
/*! Get the permanent DTC storage activation state */
#  define Dem_Mem_GetPermanentActivationState()         ((boolean)(Dem_Cfg_AdminData.PermanentActivationState))                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the permanent DTC storage activation state */
#  define Dem_Mem_SetPermanentActivationState(Value)    (Dem_Cfg_AdminData.PermanentActivationState = (Value))                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Get the permanent DTC storage activation distance */
#  define Dem_Mem_GetPermanentActivationDistance()      (Dem_Cfg_AdminData.PermanentActivationDistance)                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the permanent DTC storage activation distance */
#  define Dem_Mem_SetPermanentActivationDistance(Value) (Dem_Cfg_AdminData.PermanentActivationDistance = (Value))                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# endif
/*! Initialization pattern for permanent DTC memory */
# define DEM_MEM_PERMANENT_INIT_PATTERN          (0x4cb9U)
#endif

#if (DEM_CFG_SUPPORT_PID21 == STD_ON)
/*! Get the odometer with MIL on */
# define Dem_Mem_GetOdometerMilOn()              (Dem_Cfg_AdminData.OdometerMilOn)                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the odometer with MIL on */
# define Dem_Mem_SetOdometerMilOn(Value)         (Dem_Cfg_AdminData.OdometerMilOn = (Value))                                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_CFG_SUPPORT_PID30 == STD_ON)
/*! Get the warmup count since clear */
# define Dem_Mem_GetWarmUpCountSinceClear()      (Dem_Cfg_AdminData.WarmUpCountAtClear)                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the warmup count since clear */
# define Dem_Mem_SetWarmUpCountSinceClear(Value)  (Dem_Cfg_AdminData.WarmUpCountAtClear = (Value))                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_CFG_SUPPORT_PID31 == STD_ON)
/*! Get the odometer at clear */
# define Dem_Mem_GetOdometerAtClear()            (Dem_Cfg_AdminData.OdometerAtClear)                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the odometer at clear */
# define Dem_Mem_SetOdometerAtClear(Value)       (Dem_Cfg_AdminData.OdometerAtClear = (Value))                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_CFG_SUPPORT_PID4D == STD_ON)
/*! Get the engine time with MIL on */
# define Dem_Mem_GetEngineTimeMilOn()            (Dem_Cfg_AdminData.EngineRunTimeMilOn)                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the engine time with MIL on */
# define Dem_Mem_SetEngineTimeMilOn(Value)       (Dem_Cfg_AdminData.EngineRunTimeMilOn = (Value))                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_CFG_SUPPORT_PID4E == STD_ON)
/*! Get the engine time since clear */
# define Dem_Mem_GetEngineTimeSinceClear()       (Dem_Cfg_AdminData.EngineRunTimeSinceDtcClear)                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the engine time since clear */
# define Dem_Mem_SetEngineTimeSinceClear(Value)  (Dem_Cfg_AdminData.EngineRunTimeSinceDtcClear = (Value))                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)
/*! Get the PID aging counter */
# define Dem_Mem_GetPidAgingCounter()            (Dem_Cfg_AdminData.PidAgingCounter)                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the PID aging counter */
# define Dem_Mem_SetPidAgingCounter(Value)       (Dem_Cfg_AdminData.PidAgingCounter = (Value))                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/*! Test if an OBD odometer value is invalid */
#define DEM_MEM_TEST_ODOMETER_ISINVALID(Odometer)  ((Dem_GetHiHiByte(Odometer) & 0x80U) != 0u)                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set OBD odometer value invalid */
#define DEM_MEM_SET_ODOMETER_INVALID(Odometer)     ((uint32)((Odometer) | 0x80000000UL))                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Reset OBD odometer value invalid */
#define DEM_MEM_RESET_ODOMETER_INVALID(Odometer)   ((uint32)((Odometer) & 0x7fffffffUL))                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Test if an OBD engine runtime value is invalid */
#define DEM_MEM_TEST_ENGRUNTIME_ISINVALID(EngRunTime)  ((Dem_GetHiHiByte(EngRunTime) & 0x80U) != 0u)                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set OBD engine runtime value invalid */
#define DEM_MEM_SET_ENGRUNTIME_INVALID(EngRunTime)     ((uint32)((EngRunTime) | 0x80000000UL))                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Reset OBD engine runtime value invalid */
#define DEM_MEM_RESET_ENGRUNTIME_INVALID(EngRunTime)   ((uint32)((EngRunTime) & 0x7fffffffUL))                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/*! Get the global B1 counter */
# define Dem_Mem_GetB1Counter()                  (Dem_Cfg_AdminData.B1Counter)                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the global B1 counter */
# define Dem_Mem_SetB1Counter(Value)             (Dem_Cfg_AdminData.B1Counter = (Value))                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the global B1 healing counter */
# define Dem_Mem_GetB1HealingCounter()           (Dem_Cfg_AdminData.B1HealingCounter)                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the global B1 healing counter */
# define Dem_Mem_SetB1HealingCounter(Value)      (Dem_Cfg_AdminData.B1HealingCounter = (Value))                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the continuous MI counter */
# define Dem_Mem_GetContinuousMiCounter()        (Dem_Cfg_AdminData.ContinuousMiCounter)                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the continuous MI counter */
# define Dem_Mem_SetContinuousMiCounter(Value)   (Dem_Cfg_AdminData.ContinuousMiCounter = (Value))                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the continuous MI aging timer */
# define Dem_Mem_GetContinuousMiAgingTimer()     (Dem_Cfg_AdminData.ContinuousMiAgingTimer)                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the continuous MI aging timer */
# define Dem_Mem_SetContinuousMiAgingTimer(Value)  (Dem_Cfg_AdminData.ContinuousMiAgingTimer = (Value))                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the continuous MI healing counter */
# define Dem_Mem_GetContinuousMiHealingCounter()  (Dem_Cfg_AdminData.ContinuousMiHealingCounter)                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the continuous MI healing counter */
# define Dem_Mem_SetContinuousMiHealingCounter(Value)  (Dem_Cfg_AdminData.ContinuousMiHealingCounter = (Value))                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the continuous MI aging counter */
# define Dem_Mem_GetContinuousMiAgingCounter()   (Dem_Cfg_AdminData.ContinuousMiAgingCounter)                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the continuous MI aging counter */
# define Dem_Mem_SetContinuousMiAgingCounter(Value)  (Dem_Cfg_AdminData.ContinuousMiAgingCounter = (Value))                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get the cumulative OBD engine runtime */
# define Dem_Mem_GetCumulativeEngRuntime()       (Dem_Cfg_AdminData.CumulativeEngineRunTime)                                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set the cumulative OBD engine runtime */
# define Dem_Mem_SetCumulativeEngRuntime(Value)  (Dem_Cfg_AdminData.CumulativeEngineRunTime = (Value))                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_FEATURE_NEED_MIL_GROUPS)
/*! Initialize a MIL group trip counter */
# define Dem_Mem_InitMilGroupTripCount(MilGroupIdx)            (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, 0x00U))                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Get a MIL group trip counter */
# define Dem_Mem_GetMilGroupTripCount(MilGroupIdx)             (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x7Fu)            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Increment a MIL group trip counter */
# define Dem_Mem_IncrementMilGroupTripCount(MilGroupIdx)       (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (uint8)(Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) + 1u)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set a MIL group trip counter to 0 */
# define Dem_Mem_ResetMilGroupTripCount(MilGroupIdx)           (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x80U)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get MIL group incremented this DCY */
# define Dem_Mem_GetMilGroupIncremented(MilGroupIdx)           (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x80U)            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set MIL group incremented this DCY */
# define Dem_Mem_SetMilGroupIncremented(MilGroupIdx)           (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) | 0x80U)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Reset MIL group incremented this DCY */
# define Dem_Mem_ResetMilGroupIncremented(MilGroupIdx)         (Dem_EventInternalStatus_SetMilGroupTripCount(MilGroupIdx, (Dem_EventInternalStatus_GetMilGroupTripCountRaw(MilGroupIdx) & 0x7fU)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Increment pending DTC count */
# define Dem_Mem_IncrementMilGroupPendingCount(MilGroupIdx)    (Dem_EventInternalStatus_SetMilGroupPendingCount(MilGroupIdx, (uint16)(Dem_EventInternalStatus_GetMilGroupPendingCount(MilGroupIdx) + 1u)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Decrement pending DTC count */
# define Dem_Mem_DecrementMilGroupPendingCount(MilGroupIdx)    (Dem_EventInternalStatus_SetMilGroupPendingCount(MilGroupIdx, (uint16)(Dem_EventInternalStatus_GetMilGroupPendingCount(MilGroupIdx) - 1u)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Get ring buffer index for normal rate samples */
# define Dem_Mem_GetCurrentRingBufferIndexNormal()             (Dem_Cfg_RingBufferNormalRate.CurrentIndex)                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set ring buffer index for normal rate samples */
# define Dem_Mem_SetCurrentRingBufferIndexNormal(Value)        (Dem_Cfg_RingBufferNormalRate.CurrentIndex = (Value))             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get normal rate sample count */
# define Dem_Mem_GetSampleCountNormal()                        (Dem_Cfg_RingBufferNormalRate.SampleCount)                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set normal rate sample count */
# define Dem_Mem_SetSampleCountNormal(Value)                   (Dem_Cfg_RingBufferNormalRate.SampleCount = (Value))              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/*! Get ring buffer index for fast rate samples */
#  define Dem_Mem_GetCurrentRingBufferIndexFast()              (Dem_Cfg_RingBufferFastRate.CurrentIndex)                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set ring buffer index for fast rate samples */
#  define Dem_Mem_SetCurrentRingBufferIndexFast(Value)         (Dem_Cfg_RingBufferFastRate.CurrentIndex = (Value))               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Get fast rate sample count */
#  define Dem_Mem_GetSampleCountFast()                         (Dem_Cfg_RingBufferFastRate.SampleCount)                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Set fast rate sample count */
#  define Dem_Mem_SetSampleCountFast(Value)                    (Dem_Cfg_RingBufferFastRate.SampleCount = (Value))                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# endif
#endif


/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/*! Pointer to a time-series memory entry */
typedef P2VAR(Dem_Cfg_TimeSeriesEntryType, TYPEDEF, DEM_NVM_DATA)    Dem_Mem_TimeSeriesEntryPtrType;
/*! Non-writeable Pointer to a time-series memory entry */
typedef P2CONST(Dem_Cfg_TimeSeriesEntryType, TYPEDEF, DEM_NVM_DATA)  Dem_Mem_ConstTimeSeriesEntryPtrType;
#endif

#endif /* DEM_MEM_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Mem_Types.h
 *********************************************************************************************************************/
