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
/*! \addtogroup Dem_Esm
 *  \{
 *  \file       Dem_Esm_Implementation.h
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

#if !defined (DEM_ESM_IMPLEMENTATION_H)
#define DEM_ESM_IMPLEMENTATION_H

/* ********************************************************************************************************************
 *  GLOBAL MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 2880 EOF */ /* MD_DEM_2.1_UNREACHABLE_STATEMENT */
/* PRQA S 2982 EOF */ /* MD_DEM_2982 */
/* PRQA S 2983 EOF */ /* MD_DEM_2983 */
/* PRQA S 2985 EOF */ /* MD_DEM_2985 */
/* PRQA S 2986 EOF */ /* MD_DEM_2986 */
/* PRQA S 2987 EOF */ /* MD_DEM_2987 */
/* PRQA S 2991 EOF */ /* MD_DEM_2991 */
/* PRQA S 2992 EOF */ /* MD_DEM_2992 */
/* PRQA S 2995 EOF */ /* MD_DEM_2995 */
/* PRQA S 2996 EOF */ /* MD_DEM_2996 */
/* PRQA S 3415 EOF */ /* MD_DEM_13.5_cf */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Esm_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_Queue_Interface.h"
#include "Dem_Indicator_Implementation.h"
#include "Dem_Nvm_Interface.h"
#include "Dem_DtrIF_Interface.h"
#include "Dem_Scheduler_Implementation.h"
#include "Dem_Statistics_Implementation.h"
#include "Dem_Memory_Interface.h"
#include "Dem_Iumpr_Interface.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_OperationCycle_Interface.h"
#include "Dem_Event_Interface.h"
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_ESM_IMPLEMENTATION_FILENAME "Dem_Esm_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Esm_Public
 * \{
 */
#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Util_SeverityWwhObdDtcClass
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_SeverityWwhObdDtcClass(
  CONST(Dem_DTCSeverityType, AUTOMATIC)  Severity
  )
{
  uint8 lReturnValue;

  switch (Severity & 0x1fU) /* ignore the UDS severity bits */
  {
  case DEM_SEVERITY_WWHOBD_CLASS_A:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_A;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_B1:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_B1;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_B2:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_B2;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_C:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_C;
    break;
  case DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS:
    lReturnValue = DEM_ESM_WWHOBD_DTCCLASS_NO;
    break;
  default:
    Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_INCONSISTENT_STATE);
    lReturnValue = 0x00U;
    break;
  }
  return lReturnValue;
}
#endif



#if (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON)
/* ****************************************************************************
 % Dem_Util_J1939OccurrenceCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Util_J1939OccurrenceCounter(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  uint8 lReturnValue;

  if (Dem_DTC_TestStoredStatus(EventId) == TRUE)
  {
    /* Stored DTC, so occurrence counter is available in primary memory */
    Dem_MemoryEntry_OccurrenceCounterType lOccurrenceCounter;
    lOccurrenceCounter = Dem_MemoryEntry_GetOccurrenceCounter(Dem_MemoryEntry_GetId(Dem_Memory_FindMemoryIndex_StoredEvent(EventId)));

    /* Latch the counter value at 126 */
    if (lOccurrenceCounter > 0x7eU)
    {
      lOccurrenceCounter = 0x7eU;
    }
    lReturnValue = (uint8)lOccurrenceCounter;
  }
  else
  {
    lReturnValue = 0x7fU;
  }

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_J1939_READ_DTC == STD_ON) || (DEM_CFG_SUPPORT_J1939_DM31 == STD_ON) */

#if ( (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_MMONLY_CALCULATION == STD_ON) )
/* ****************************************************************************
 % Dem_Util_SetReadinessGroupSupported
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupSupported(                                                                                             /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
  CONST(boolean, AUTOMATIC)  Supported,
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  PidSupportedMask
)
{
  uint8 lReadinessGroup = ReadinessGroup;
  uint32 lPidSupportedMask;

  switch (lReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lPidSupportedMask = DEM_READINESS_SUPPORT_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CMPRCMPT;
    break;
  case DEM_CFG_READINESS_CAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EGSENS_MASK;
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    lPidSupportedMask = DEM_READINESS_SUPPORT_PMFLT_MASK;
    break;
  case DEM_CFG_READINESS_EGR:
    lPidSupportedMask = DEM_READINESS_SUPPORT_EGR_MASK;
    break;
  default:
    lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;
    lReadinessGroup = DEM_CFG_READINESS_NONE;
    break;
  }

  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if (Supported == TRUE)
    {
      *PidSupportedMask |= lPidSupportedMask;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *PidSupportedMask &= (uint32) (~lPidSupportedMask);                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if ((DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON) || (DEM_FEATURE_NEED_PID41_MMONLY_CALCULATION == STD_ON) )
/* ****************************************************************************
 % Dem_Util_SetReadinessGroupCompleted
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupCompleted(
  CONST(boolean, AUTOMATIC) Completed,
  CONST(uint8, AUTOMATIC)  ReadinessGroup,
  CONSTP2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) PidSupportedMask
)
{
  uint8 lReadinessGroup;
  uint32 lPidSupportedMask;

  lReadinessGroup = ReadinessGroup;
  lPidSupportedMask = DEM_READINESS_SUPPORT_NONE_MASK;

  switch (lReadinessGroup)
  {
  case DEM_CFG_READINESS_MISF:
    lPidSupportedMask = DEM_READINESS_COMPLETE_MISF_MASK;
    break;
  case DEM_CFG_READINESS_FLSYS:
  case DEM_CFG_READINESS_FLSYS_NONCONT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_FLSYS_MASK;
    break;
  case DEM_CFG_READINESS_CMPRCMPT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_CMPRCMPT;
    break;
  case DEM_CFG_READINESS_CAT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_CAT_MASK;
    break;
  case DEM_CFG_READINESS_HCCAT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_HCCAT_MASK;
    break;
  case DEM_CFG_READINESS_HTCAT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_HTCAT_MASK;
    break;
  case DEM_CFG_READINESS_NOXCAT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_NOXCAT_MASK;
    break;
  case DEM_CFG_READINESS_EVAP:
    lPidSupportedMask = DEM_READINESS_COMPLETE_EVAP_MASK;
    break;
  case DEM_CFG_READINESS_SECAIR:
    lPidSupportedMask = DEM_READINESS_COMPLETE_SECAIR_MASK;
    break;
  case DEM_CFG_READINESS_BOOSTPR:
    lPidSupportedMask = DEM_READINESS_COMPLETE_BOOSTPR_MASK;
    break;
  case DEM_CFG_READINESS_O2SENS:
    lPidSupportedMask = DEM_READINESS_COMPLETE_O2SENS_MASK;
    break;
  case DEM_CFG_READINESS_EGSENS:
    lPidSupportedMask = DEM_READINESS_COMPLETE_EGSENS_MASK;
    break;
  case DEM_CFG_READINESS_O2SENSHT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_O2SENSHT_MASK;
    break;
  case DEM_CFG_READINESS_PMFLT:
    lPidSupportedMask = DEM_READINESS_COMPLETE_PMFLT_MASK;
    break;
  case DEM_CFG_READINESS_EGR:
    lPidSupportedMask = DEM_READINESS_COMPLETE_EGR_MASK;
    break;
  default:
    lReadinessGroup = DEM_CFG_READINESS_NONE;
    break;
  }

  if (lReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if (Completed == TRUE)
    {
      *PidSupportedMask &= (uint32) (~lPidSupportedMask);                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *PidSupportedMask |= lPidSupportedMask;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
}                                                                                                                                /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if (DEM_FEATURE_NEED_PID41_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Util_SetReadinessGroupDisabled
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Util_SetReadinessGroupDisabled(
  CONST(uint8, AUTOMATIC)  ReadinessGroup
  )
{
  uint16 lPid41DisabledeMask;
  uint8 lReadinessGroup;

  lPid41DisabledeMask = Dem_Mem_GetPid41DisabledMask();

  if (ReadinessGroup == DEM_CFG_READINESS_FLSYS)
  {
    lReadinessGroup = DEM_CFG_READINESS_FLSYS_NONCONT;
  }
  else
  {
    lReadinessGroup = ReadinessGroup;
  }

  lPid41DisabledeMask |= ((uint16)1 << lReadinessGroup);

  Dem_Mem_SetPid41DisabledMask(lPid41DisabledeMask);
}
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Esm_AddAgingTime
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Esm_AddAgingTime(
  CONST(uint32, AUTOMATIC)  CurrentTime,
  CONST(uint16, AUTOMATIC)  DeltaValue
  )
{
  uint32 lTargetTime;

  lTargetTime = (uint32)(CurrentTime + DeltaValue);

  return lTargetTime;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Esm_EventCreateTimeSeriesEntry
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_EventCreateTimeSeriesEntry(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_EventIdType lMemoryRepresentativeEventId;
  Dem_Cfg_MemoryIndexType lMemoryIndex;

  /* check if there is already a time series entry for this DTC */
  lMemoryRepresentativeEventId = Dem_Cfg_GetMemoryRepresentative(EventId);
  lMemoryIndex = Dem_Mem_TimeSeriesFindIndex(lMemoryRepresentativeEventId);

  if (lMemoryIndex == DEM_MEM_INVALID_MEMORY_INDEX)
  {
    /* get time series entry for this event if possible */
    lMemoryIndex = Dem_Mem_TimeSeriesAllocateIndex(EventId);

    if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
    {
# if (DEM_FEATURE_NEED_TIME_SERIES_PAST == STD_ON)
      Dem_Data_StoreTimeSeriesPastSamples(EventId, lMemoryIndex);
# endif

# if (DEM_FEATURE_NEED_TIME_SERIES_FUTURE == STD_OFF)
      if (Dem_Cfg_EventSupportImmediateNv(EventId) == TRUE)
      {
        Dem_Nvm_SetTimeSeriesMemoryBlockState(lMemoryIndex, DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
      }
      else
# endif
      {
        Dem_Nvm_SetTimeSeriesMemoryBlockState(lMemoryIndex, DEM_NVM_BLOCKSTATE_DIRTY);
      }

# if (DEM_FEATURE_NEED_TIME_SERIES_FUTURE == STD_ON)
      {

#  if (DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_NORMAL == STD_ON)
        /* determine missing future samples */
        Dem_Mem_SetMissingTimeSeriesNormalRate((uint8)(lMemoryIndex - Dem_Memory_GetFirstMemoryIndex(DEM_CFG_MEMORYID_TIMESERIES)), Dem_Cfg_TimeSeriesFutureSamplesNormal());
#  endif
#  if (DEM_CFG_SUPPORT_TIME_SERIES_FUTURE_FAST == STD_ON)
        if (Dem_Cfg_EventSupportTimeSeriesFast(EventId) == TRUE)
        {
          Dem_Mem_SetMissingTimeSeriesFastRate((uint8)(lMemoryIndex - Dem_Memory_GetFirstMemoryIndex(DEM_CFG_MEMORYID_TIMESERIES)), Dem_Cfg_TimeSeriesFutureSamplesFast());
        }
#  endif
      }
# endif
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Esm_ProcessQualifiedActiveEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Esm_ProcessQualifiedActiveEvent(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC)  AddPermanentEntry
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(AddPermanentEntry)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */

  if ( (Dem_Event_TestMilSupport(EventId) == TRUE)
    && (Dem_EventInternalStatus_Test_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId)) == TRUE)                            /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    && (Dem_UDSStatus_Test_TF(Dem_Event_GetUDSStatus(EventId)) == TRUE) )                                                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
  {
    uint8 lWwhObdDtcClass;
    lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));

# if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
    if ((AddPermanentEntry == TRUE) && (Dem_DTC_TestEventStoresPermanentDTC(EventId) == TRUE))                                      /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    { /* Always try to store a permanent DTC */
      if ((lWwhObdDtcClass == DEM_ESM_WWHOBD_DTCCLASS_A)
        || (Dem_Mem_GetB1Counter() > DEM_DATA_B1COUNTER_200H))
      {
        Dem_Data_PermanentEntryAdd(EventId);
      }
    }
# endif

    Dem_Indicator_SetQualifiedActiveEventCount(lWwhObdDtcClass, Dem_Indicator_GetQualifiedActiveEventCount(lWwhObdDtcClass) + 1u);

    /* if continuous MI counter is not active yet and activation mode 4 becomes active , set to Run state */
    if ( (Dem_Mem_GetContinuousMiHealingCounter() != DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID)
      && (Dem_Indicator_GlobalIndicatorActivationMode() == DEM_INDICATOR_CONTINUOUS) )                                           /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
      /* if continuous MI counter was healed and is currently aging, reset continuous MI counter */
      if (Dem_Mem_GetContinuousMiAgingCounter() < DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_AGED)
      {
        Dem_Mem_SetContinuousMiCounter(0);
      }
      Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID);
      Dem_Mem_SetContinuousMiAgingCounter(DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_INVALID);
      Dem_Mem_SetContinuousMiAgingTimer(DEM_DATA_CONTINUOUS_MI_AGING_TIMER_INVALID);
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Esm_DecrementQualifiedActiveEventCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_DecrementQualifiedActiveEventCount(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(boolean, AUTOMATIC) StartB1Healing
  )
{
  if ( (Dem_Event_TestMilSupport(EventId) == TRUE)
    && (Dem_EventInternalStatus_Test_QualifyStatus_CDTC(Dem_Event_GetQualifyStatus(EventId)) == TRUE) )                          /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
  {
    uint16 lEventCountB1Old;
    uint8 lWwhObdDtcClass;

    lEventCountB1Old = Dem_Indicator_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_B1);
    lWwhObdDtcClass = Dem_Util_SeverityWwhObdDtcClass(Dem_Cfg_EventSeverity(EventId));
    Dem_Indicator_SetQualifiedActiveEventCount(lWwhObdDtcClass, Dem_Indicator_GetQualifiedActiveEventCount(lWwhObdDtcClass) - 1u);

    if ( (lEventCountB1Old != 0u)
      && (Dem_Indicator_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_B1) == 0u) )                                         /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
      if (Dem_Mem_GetB1Counter() >= DEM_DATA_B1COUNTER_200H)
      { /* set B1Counter to 190h (11400min) if no B1 event is confirmed and failed and B1 counter is greater than 200h (12000min)
        also clear the healing counter */
        Dem_Mem_SetB1Counter(DEM_DATA_B1COUNTER_190H);
      }

      if (StartB1Healing == TRUE)
      {
        Dem_Mem_SetB1HealingCounter(0);
      }
      else
      {
        Dem_Mem_SetB1HealingCounter(DEM_DATA_B1_HEALING_COUNTER_THRESHOLD);
      }
    }

    /* prepare continuous MI Healing if activation mode 4 is not active */
    if ( (Dem_Mem_GetContinuousMiHealingCounter() == DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID)
      && (Dem_Indicator_GlobalIndicatorActivationMode() != DEM_INDICATOR_CONTINUOUS) )                                           /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
      Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_LOCKED);
    }
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_RESTART_DCY_ON_CLEAR_DTC == STD_ON)
/* ****************************************************************************
 % Dem_Esm_PreOnClear_AllDtc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PreOnClear_AllDtc(
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
  if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
  {
    Dem_OperationCycle_CycleUpdate(Dem_Cfg_GlobalObdDrivingCycleId(), DEM_OPERATIONCYCLE_CYCLE_RESTARTED);
  }
}
#endif

/* ****************************************************************************
 % Dem_Esm_PostOnClear_AllDtc
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_AllDtc(
  CONST(uint8, AUTOMATIC)  MemoryId
  )
{
#if (DEM_FEATURE_NEED_OVFLIND == STD_ON)
  Dem_Memory_ResetOverflow(MemoryId);
#endif

  if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
  {
    Dem_Statistics_SetFirstFailedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetFirstConfirmedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetMostRecentFailedEvent(DEM_EVENT_INVALID);
    Dem_Statistics_SetMostRecentConfirmedEvent(DEM_EVENT_INVALID);
    Dem_DtrIF_ResetDtrsOfEvent(DEM_EVENT_INVALID);
  }
}

/* ****************************************************************************
 % Dem_Esm_PostOnClear_Always
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Esm_PostOnClear_Always(
  CONST(uint8, AUTOMATIC)  MemoryId                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */

#if (DEM_FEATURE_NEED_OBD == STD_ON)
  if (MemoryId == DEM_CFG_MEMORYID_PRIMARY)
  {
# if (DEM_FEATURE_NEED_GLOBAL_MIL_STATE == STD_ON)
    if (Dem_Indicator_TestMilReportedActive() == FALSE)
    {
#  if (DEM_CFG_SUPPORT_PID21 == STD_ON)
/* >>>> -------------------------------- Enter Critical Section: NonAtomic32bit */
      Dem_EnterCritical_NonAtomic32bit();
      /* Clear Odometer for MIL on */
      Dem_Mem_SetOdometerMilOn(0);
      Dem_LeaveCritical_NonAtomic32bit();
/* <<<< -------------------------------- Leave Critical Section: NonAtomic32bit */
#  endif
#  if (DEM_CFG_SUPPORT_PID4D == STD_ON)
      Dem_Mem_SetEngineTimeMilOn(0);
#  endif
    }
# endif
  Dem_Iumpr_ResetPendingFids();
# if (DEM_CFG_SUPPORT_PID30 == STD_ON)
    /* Clear WarmUpCycle since last clear counter */
    Dem_Mem_SetWarmUpCountSinceClear(0x00U);
# endif
# if (DEM_CFG_SUPPORT_PID31 == STD_ON)
/* >>>> -------------------------------- Enter Critical Section: NonAtomic32bit */
    Dem_EnterCritical_NonAtomic32bit();

    /* Set current Odometer value to invalid */
    Dem_Mem_SetOdometerAtClear(DEM_MEM_SET_ODOMETER_INVALID(0u));
    Dem_LeaveCritical_NonAtomic32bit();
/* <<<< -------------------------------- Leave Critical Section: NonAtomic32bit */
# endif
# if (DEM_CFG_SUPPORT_PID4E == STD_ON)
    Dem_Mem_SetEngineTimeSinceClear(0x0000U);
# endif
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* >>>> -------------------------------- Enter Critical Section: StateManager */
    Dem_EnterCritical_StateManager();
    Dem_OperationCycle_SetObdCycleStates(DEM_OPERATIONCYCLE_RESET_PFC_CYCLE(Dem_OperationCycle_GetObdCycleStates()));
    Dem_LeaveCritical_StateManager();
/* <<<< -------------------------------- Leave Critical Section: StateManager */

# endif
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
    Dem_Mem_SetContinuousMiAgingCounter(DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_AGED);
    Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_HEALED);
    Dem_Mem_SetContinuousMiAgingTimer(DEM_DATA_CONTINUOUS_MI_AGING_TIMER_AGED);
    Dem_Mem_SetContinuousMiCounter(0);
# endif
# if (DEM_FEATURE_NEED_PID01_CALCULATION  == STD_ON)
    /* all readiness groups are set to not complete -> reserved bits are set to 0 */
    if ((Dem_Cfg_GlobalPid01SupportedMask() & DEM_READINESS_SUPPORT_COMPRESSION) != 0u)
    {
      Dem_Mem_SetPid01CompletedMask(DEM_READINESS_INITIALIZE_PID01COMPLETED_COMPRESSION);
    }
    else
    {
      Dem_Mem_SetPid01CompletedMask(DEM_READINESS_INITIALIZE_PID01COMPLETED_SPARK);
    }

/* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();

    /* set flag for all readiness group supported by engine type to recalculate monitor state -> not supported groups will be set to N/A = completed*/
    if ((Dem_Cfg_GlobalPid01SupportedMask() & DEM_READINESS_SUPPORT_COMPRESSION) != 0u)
    {
      Dem_Queue_SetPid01UpdateFlag(DEM_READINESS_INITIALIZE_UPDATE_COMPRESSION);
    }
    else
    {
      Dem_Queue_SetPid01UpdateFlag(DEM_READINESS_INITIALIZE_UPDATE_SPARK);
    }

    Dem_LeaveCritical_DiagMonitor();
/* <<<< -------------------------------- Leave Critical Section: DiagMonitor */
# endif
  }
#endif /* DEM_FEATURE_NEED_OBD == STD_ON */


  /* copy debounce values from debounce array to nvram mirror */
  Dem_Mem_CopyDataDebounceNv(DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);

  Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_ADMIN),
                              DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);

#if (DEM_FEATURE_NEED_AGING_DATA == STD_ON)
  Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_AGINGDATA),
                              DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
#endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Esm_SetPid01ReadinessState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Esm_SetPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  )
{
  uint16 lReturnValue;
  lReturnValue = State;
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    lReturnValue |= (uint16)1u << (uint16)ReadinessGroup;
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Esm_ResetPid01ReadinessState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Esm_ResetPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  )
{
  uint16 lReturnValue;
  lReturnValue = State;
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    lReturnValue &= ~((uint16)1U << (uint16)ReadinessGroup);
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_PID01_CALCULATION == STD_ON)
/* ****************************************************************************
 % Dem_Esm_TestPid01ReadinessState
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Esm_TestPid01ReadinessState(
  CONST(uint16, AUTOMATIC) State,
  CONST(uint8, AUTOMATIC) ReadinessGroup
  )
{
  boolean lReturnValue;
  lReturnValue = FALSE;
  if (ReadinessGroup != DEM_CFG_READINESS_NONE)
  {
    if ((State & ((uint16)1u << (uint16)(ReadinessGroup))) != 0u)
    {
      lReturnValue = TRUE;
    }
  }
  return lReturnValue;
}
#endif
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_ESM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Esm_Implementation.h
 *********************************************************************************************************************/
