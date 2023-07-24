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
 *  \file       Dem_Mem_Implementation.h
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

#if !defined (DEM_MEM_IMPLEMENTATION_H)                                                                                          /* PRQA S 0883 */ /* MD_DEM_19.15 */
#define DEM_MEM_IMPLEMENTATION_H

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
#include "Dem_Mem_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_MemState_Implementation.h"
#include "Dem_Indicator_Implementation.h"
#include "Dem_Cfg_Definitions.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_MemObdFreezeFrame_Implementation.h"
                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Data_Interface.h"
#include "Dem_Event_Interface.h"
#include "Dem_DTC_Interface.h"
#include "Dem_DTCInternalStatus_Interface.h"
#include "Dem_DataStorageIF_Interface.h"
#include "Dem_Memory_Interface.h"
#include "Dem_Error_Interface.h"
#include "Dem_Esm_Interface.h"
#include "Dem_MemAccess_Interface.h"
#include "Dem_Nvm_Interface.h"
#include "Dem_MemPermanent_Interface.h"


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_MEM_IMPLEMENTATION_FILENAME "Dem_Mem_Implementation.h"

#if (DEM_CFG_SUPPORT_IUMPR == STD_OFF)
# define DEM_CFG_MEMORY_IUMPR_INDEX DEM_CFG_MEMORYINDEX_MAX
#endif

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/*! Freeze frame index visible in mode 0x02 */
DEM_LOCAL VAR(uint8, DEM_VAR_NOINIT)          Dem_Mem_FreezeFrameIndexMode02;

#endif

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DEFINITIONS
 *********************************************************************************************************************/
/* ********************************************************************************************************************
 *  SUBCOMPONENT PUBLIC PROPERTIES DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Mem_PublicProperties
 * \{
 */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Mem_Private
 * \{
 */
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Mem_Public
 * \{
 */
#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameObdIIGetDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_Mem_FreezeFrameObdIIGetDataPtr(
  CONST(uint8, AUTOMATIC) Index
  )
{
  Dem_SharedDataPtrType lReturnValue;

# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalObdIIFFCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = &(Dem_Cfg_FreezeFrameData[0].FreezeFrameData[0]);
  }
  else
# endif
  {
    lReturnValue = &(Dem_Cfg_FreezeFrameData[Index].FreezeFrameData[0]);
  }
  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_Mem_DebounceGetStoredValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(sint16, DEM_CODE)
Dem_Mem_DebounceGetStoredValue(
  CONST(uint16, AUTOMATIC)  Index
  )
{
#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
  return Dem_Cfg_DebounceData[Index];
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(Index)                                                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return 0;
#endif
}

/* ****************************************************************************
 % Dem_Mem_DebounceSetStoredValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_DebounceSetStoredValue(
  CONST(uint16, AUTOMATIC)  Index,
  CONST(sint16, AUTOMATIC)  DebounceValue
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalDebounceStorageEventCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
#if (DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON)
    Dem_Cfg_DebounceData[Index] = DebounceValue;                                                                                                       /* SBSW_DEM_ARRAY_WRITE_DEBOUNCEDATA */
#else
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(Index)                                                                                                               /* PRQA S 3112 */ /* MD_DEM_14.2 */
    DEM_IGNORE_UNUSED_CONST_ARGUMENT(DebounceValue)                                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
  }
}

#if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_EventGetAvailableMask
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_EventGetAvailableMask(
  CONST(uint16, AUTOMATIC)  Index                                                                                                /* PRQA S 3206 */ /* MD_DEM_3206 */
  )
{
  return Dem_Cfg_EventAvailableData[Index];
}
#endif

#if (DEM_FEATURE_NEED_EVENTAVAILABLE_NV == STD_ON)
/* ****************************************************************************
 % Dem_Mem_EventSetAvailableMask
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_EventSetAvailableMask(
  CONST(uint16, AUTOMATIC)  Index,
  CONST(uint8, AUTOMATIC)  Mask
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalEventAvailableDataSize())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                     /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Cfg_EventAvailableData[Index] = Mask;                                                                                    /* SBSW_DEM_ARRAY_WRITE_EVENTAVAILABLEDATA */
  }
}
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameGetEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Mem_FreezeFrameGetEvent(
  CONST(uint8, AUTOMATIC)  Index
  )
{
  return Dem_Cfg_FreezeFrameData[Index].EventId;
}
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameSetEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_FreezeFrameSetEvent(
  CONST(uint8, AUTOMATIC)  Index,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalObdIIFFCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Cfg_FreezeFrameData[Index].EventId = EventId;                                                                            /* SBSW_DEM_ARRAY_WRITE_FREEZEFRAMEDATA */
  }
}
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameGetTimestamp
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint32, DEM_CODE)
Dem_Mem_FreezeFrameGetTimestamp(
  CONST(uint8, AUTOMATIC)  Index
  )
{
  return Dem_Cfg_FreezeFrameData[Index].Timestamp;
}
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameSetTimestamp
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_FreezeFrameSetTimestamp(
  CONST(uint8, AUTOMATIC)  Index,
  CONST(uint32, AUTOMATIC)  Timestamp
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalObdIIFFCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Cfg_FreezeFrameData[Index].Timestamp = Timestamp;                                                                        /* SBSW_DEM_ARRAY_WRITE_FREEZEFRAMEDATA */
  }
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 % Dem_Mem_PermanentGetEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Mem_PermanentGetEvent(
  CONST(uint8, AUTOMATIC)  Index
  )
{
  return Dem_Cfg_PermanentData.PermanentDataEntry[Index].EventId;
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 % Dem_Mem_PermanentSetEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_PermanentSetEvent(
  CONST(uint8, AUTOMATIC)  Index,
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalPermanentMaxCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Cfg_PermanentData.PermanentDataEntry[Index].EventId = EventId;                                                           /* SBSW_DEM_ARRAY_WRITE_PERMANENTDATA_PERMANENTDATAENTRY */
  }
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 % Dem_Mem_PermanentGetStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_PermanentGetStatus(
  CONST(uint8, AUTOMATIC)  Index
  )
{
  return Dem_Cfg_PermanentData.PermanentDataEntry[Index].Status;
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 % Dem_Mem_PermanentSetStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_PermanentSetStatus(
  CONST(uint8, AUTOMATIC)  Index,
  CONST(uint8, AUTOMATIC)  Status
  )
{
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (Index >= Dem_Cfg_GlobalPermanentMaxCount())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    Dem_Cfg_PermanentData.PermanentDataEntry[Index].Status = Status;                                                             /* SBSW_DEM_ARRAY_WRITE_PERMANENTDATA_PERMANENTDATAENTRY */
  }
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 % Dem_Mem_PermanentGetInitPattern
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Mem_PermanentGetInitPattern(
  void
  )
{
  return Dem_Cfg_PermanentData.InitPattern;
}
#endif

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
/* ****************************************************************************
 * Dem_Mem_PermanentSetInitPattern
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_PermanentSetInitPattern(
  CONST(uint16, AUTOMATIC)  InitPattern
  )
{
  Dem_Cfg_PermanentData.InitPattern = InitPattern;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_RingBufferNormalRatePtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DataPtrType, DEM_CODE)
Dem_Mem_RingBufferNormalRatePtr(
  CONST(uint8, AUTOMATIC)  BufferIndex
  )
{
  Dem_DataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BufferIndex >= Dem_Cfg_TimeSeriesBufferCountNormal())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = Dem_Cfg_RingBufferNormalRate.Buffer[0];
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_RingBufferNormalRate.Buffer[BufferIndex];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_RingBufferFastRatePtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_DataPtrType, DEM_CODE)
Dem_Mem_RingBufferFastRatePtr(
  CONST(uint8, AUTOMATIC)  BufferIndex
  )
{
  Dem_DataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BufferIndex >= Dem_Cfg_TimeSeriesBufferCountFast())
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = Dem_Cfg_RingBufferFastRate.Buffer[0];
  }
  else
# endif
  {
    lReturnValue = Dem_Cfg_RingBufferFastRate.Buffer[BufferIndex];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetNormalDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetNormalDataPtr(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_SharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal()))
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_ConstSharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal()))
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_NormalRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetFastDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_SharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetFastDataPtr(
  CONST(Dem_Mem_TimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_SharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast()))
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif

#if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
/* ****************************************************************************
 % Dem_Mem_TimeSeriesEntryGetFastConstDataPtr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_ConstSharedDataPtrType, DEM_CODE)
Dem_Mem_TimeSeriesEntryGetFastConstDataPtr(
  CONST(Dem_Mem_ConstTimeSeriesEntryPtrType, AUTOMATIC)  MemoryEntry,
  CONST(uint8, AUTOMATIC)  SeriesIndex
  )
{
  Dem_ConstSharedDataPtrType lReturnValue;
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (SeriesIndex >= (Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast()))
  {
    Dem_Error_RunTimeCheckFailed(DEM_MEM_IMPLEMENTATION_FILENAME, __LINE__);                                                                            /* SBSW_DEM_POINTER_RUNTIME_CHECK */
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[0][0];
  }
  else
# endif
  {
    lReturnValue = &MemoryEntry->SnapshotData_FastRate[SeriesIndex][0];
  }
  return lReturnValue;
}
#endif



#if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Mem_StoreWwhObdFreezeFrame
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_StoreWwhObdFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)  MemoryIndex
  )
{
  uint8 lReturnValue;
  Dem_Cfg_MemoryEntryHandleType lMemoryEntryId;

  lMemoryEntryId = Dem_MemoryEntry_GetId(MemoryIndex);
  Dem_MemState_MemoryUpdateStart(MemoryIndex);

  # if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
  if (Dem_DataStorageIF_PrestorageApplyWwhObdFF(Dem_MemoryEntry_GetWwhObdFreezeFrameDataPtr(lMemoryEntryId),                     /* SBSW_DEM_POINTER_WWHOBDFREEZEFRAME_BUFFER */
                                      Dem_Cfg_GlobalWwhobdFreezeFrameDataSize()) == FALSE)
  # endif
  {
    Dem_DataStorageIF_CollectWwhObdFreezeFrame(EventId,
                                      Dem_MemoryEntry_GetWwhObdFreezeFrameDataPtr(lMemoryEntryId),                               /* SBSW_DEM_POINTER_WWHOBDFREEZEFRAME_BUFFER */
                                      Dem_Cfg_GlobalWwhobdFreezeFrameDataSize());
  }
  Dem_MemState_MemoryUpdateFinish(MemoryIndex);
  lReturnValue = DEM_DATA_USERDATA_CHANGED;

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_UpdateOBDIIFreezeFrame
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
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Mem_UpdateOBDIIFreezeFrame(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC) FreezeFrameSlot,
  CONST(uint8, AUTOMATIC) RequiredUpdates
  )
{
  Dem_EventIdType lMemoryRepresentativeEventId;
  Dem_Cfg_MemoryIndexType lMemoryIndex;

  lMemoryRepresentativeEventId = DEM_EVENT_INVALID;
  lMemoryIndex = Dem_Cfg_MemoryFreezeFrameIndex();

  if ((RequiredUpdates & DEM_DATA_FF_UPDATE_REQUIRED) != 0u)
  {
    Dem_MemState_MemoryUpdateStart(lMemoryIndex);

    if (FreezeFrameSlot != Dem_Cfg_GlobalObdIIFFCount())
    {
      lMemoryRepresentativeEventId = Dem_Cfg_GetMemoryRepresentative(EventId);
      if ((RequiredUpdates & DEM_DATA_FF_UPDATE_DATA) != 0u)
      {
        if (Dem_Mem_FreezeFrameGetEvent(FreezeFrameSlot) != lMemoryRepresentativeEventId)
        {
          /* initial storage of OBD FF, no update*/
          Dem_MemObdFreezeFrame_FreezeFrameResetVisible(FreezeFrameSlot);
          Dem_Mem_FreezeFrameSetEvent(FreezeFrameSlot, lMemoryRepresentativeEventId);
        }
        Dem_Mem_FreezeFrameSetTimestamp(FreezeFrameSlot, Dem_MemState_GetCurrentTimestamp());
        Dem_MemState_SetCurrentTimestamp(Dem_MemState_GetCurrentTimestamp() + 1u);
# if (DEM_CFG_SUPPORT_PRESTORED_FF == STD_ON)
        if (Dem_DataStorageIF_PrestorageApplyObdIIFF(Dem_Mem_FreezeFrameObdIIGetDataPtr(FreezeFrameSlot),                          /* SBSW_DEM_POINTER_OBD_FREEZEFRAME_BUFFER */
          Dem_Cfg_GlobalObdFreezeFrameMaxSize()) == FALSE)
# endif
        {
          Dem_DataStorageIF_CollectObdIIFreezeFrame(EventId,
            Dem_Mem_FreezeFrameObdIIGetDataPtr(FreezeFrameSlot),                                                                   /* SBSW_DEM_POINTER_OBD_FREEZEFRAME_BUFFER */
            Dem_Cfg_GlobalObdFreezeFrameMaxSize());
        }
      }
      else
      {
        /* No data update, check if time stamp update is needed by visibility
           change at confirmation */
        if ((RequiredUpdates & DEM_DATA_FF_UPDATE_TIMESTAMP) != 0u)
        {
          Dem_Mem_FreezeFrameSetTimestamp(FreezeFrameSlot, Dem_MemState_GetCurrentTimestamp());
          Dem_MemState_SetCurrentTimestamp(Dem_MemState_GetCurrentTimestamp() + 1u);
        }
      }
      if ((RequiredUpdates & DEM_DATA_FF_UPDATE_VISIBILITY) != 0u)
      {
        Dem_MemObdFreezeFrame_FreezeFrameSetVisible(FreezeFrameSlot);
      }

    }
# if (DEM_CFG_SUPPORT_CONFIRMED_STORAGE_FREEZE_FRAME == STD_ON) && (DEM_CFG_SUPPORT_CONFIRMED_VISIBLE_FREEZE_FRAME == STD_ON)
    else
    {
      if ((RequiredUpdates & DEM_DATA_FF_UPDATE_VISIBILITY) != 0u)
      {
        lMemoryRepresentativeEventId = Dem_MemObdFreezeFrame_SetOldestHighPrioFreezeFrameVisible();
      }
    }
# endif

    Dem_MemState_MemoryUpdateFinish(lMemoryIndex);

    Dem_Mem_FreezeFrameIndexMode02 = Dem_MemObdFreezeFrame_SelectHighestPriorFreezeFrame();
  }

  if (RequiredUpdates != 0u)
  {
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_OBDFREEZEFRAME),
                                DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
  }

  return lMemoryRepresentativeEventId;
}                                                                                                                                /* PRQA S 6050, 6010 */ /* MD_MSR_STCAL, MD_MSR_STPTH */
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FindOBDIIFreezeFrameSlot
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_FindOBDIIFreezeFrameSlot(
  CONSTP2VAR(Dem_DTC_ContextType, AUTOMATIC, AUTOMATIC) DTCContext,
  CONST(boolean, AUTOMATIC) DisplacePendingFreezeFrame
  )
{
  Dem_EventIdType lMemoryRepresentativeEventId;
  uint8 lSelectedIndex;
  uint8 lFreezeFrameIndex;

  lMemoryRepresentativeEventId = Dem_Cfg_GetMemoryRepresentative(DTCContext->EventId);

  lFreezeFrameIndex = Dem_Cfg_GlobalObdIIFFCount();
  lSelectedIndex    = Dem_Cfg_GlobalObdIIFFCount();

  /* Find the stored freeze frame for the event (using the master event in
      case of event combination) */
  while (lFreezeFrameIndex != 0U)
  {
    Dem_EventIdType lEventId;

    lFreezeFrameIndex--;
    lEventId = Dem_Mem_FreezeFrameGetEvent(lFreezeFrameIndex);

    if (lEventId == lMemoryRepresentativeEventId)
    {
      lSelectedIndex = (uint8)lFreezeFrameIndex;
      break;
    }
    if (lEventId == DEM_EVENT_INVALID)
    {
      lSelectedIndex = (uint8)lFreezeFrameIndex;
    }
  }

  /* If configured and no empty slot or stored freeze frame for the event was found,
     search for displaceable freeze frame */
  if ( lSelectedIndex == Dem_Cfg_GlobalObdIIFFCount())
  {
    lSelectedIndex = Dem_MemObdFreezeFrame_SelectFFDisplaceIndex(lMemoryRepresentativeEventId,                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                                 DisplacePendingFreezeFrame,
                                                                 &(DTCContext->QualifyDTC));
  }

  return lSelectedIndex;
}                                                                                                                                /* PRQA S 6050, 6010 */ /* MD_MSR_STCAL, MD_MSR_STPTH */
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON)
/* ****************************************************************************
 % Dem_Mem_Init_RestoreMemoryObd
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
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_Init_RestoreMemoryObd(
  void
  )
{

#if (DEM_CFG_SUPPORT_PERMANENT == STD_ON) || (DEM_CFG_SUPPORT_OBDII == STD_ON)
  Dem_EventIdType lEventId;
# endif

# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
  /* If the primary entry of a freeze frame event is lost, also remove the
  freeze frame. The most probably scenario to get this state is to clear
  DTCs and NvM restores the previous freeze frame due to CRC errors */
  uint8 lFreezeFrameIndex;

  lFreezeFrameIndex = Dem_Cfg_GlobalObdIIFFCount();
  while (lFreezeFrameIndex != 0U)
  {
    lFreezeFrameIndex--;
    lEventId = Dem_Mem_FreezeFrameGetEvent(lFreezeFrameIndex);
    if (lEventId != DEM_EVENT_INVALID)
    {
      if ( (Dem_MemObdFreezeFrame_IsFreezeFrameStorageValid(lEventId) == FALSE)
        || (Dem_Cfg_GetMemoryRepresentative(lEventId) != lEventId)                                                               /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        || (Dem_Memory_GetLastEvent(DEM_CFG_MEMORYID_PRIMARY) < lEventId)                                                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        || (Dem_Memory_GetFirstEvent(DEM_CFG_MEMORYID_PRIMARY) > lEventId) )                                                     /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      {
        /* invalidate the freeze frame */
        Dem_MemObdFreezeFrame_FreezeFrameFreeEntry(lFreezeFrameIndex);
        Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_OBDFREEZEFRAME),
                                    DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
      }
    }
  }

  /* set the freeze frame index for active slot in Mode02 */
  Dem_Mem_FreezeFrameIndexMode02 = Dem_MemObdFreezeFrame_SelectHighestPriorFreezeFrame();
# endif

# if (DEM_CFG_SUPPORT_PERMANENT == STD_ON)
  /* If the event supports the MIL indicator has stored an permanent DTC in
  active state but the MIL is currently not trigger, the permanent entry
  is set into the same state as after Mode 0x04 */
  {
    uint8 lPermanentIndex;
    Dem_MemState_MemoryInfoPtrType lMemoryInfo;

    lMemoryInfo = Dem_MemState_MemoryInfoInit(DEM_CFG_MEMORYID_PERMANENT);
    Dem_MemState_MemorySetCurrentSize(lMemoryInfo, 0);                                                                             /* SBSW_DEM_CALL_MEMORYINFO_POINTER */
    lPermanentIndex = lMemoryInfo->MaxSize;
    while (lPermanentIndex != 0u)
    {
      --lPermanentIndex;

      lEventId = Dem_Mem_PermanentGetEvent(lPermanentIndex);

      if (lEventId != DEM_EVENT_INVALID)
      {
        Dem_MemState_MemorySetCurrentSize(lMemoryInfo, Dem_MemState_MemoryGetCurrentSize(lMemoryInfo) + 1u);                      /* SBSW_DEM_CALL_MEMORYINFO_POINTER */ /* SBSW_DEM_CALL_MEMORYINFO_POINTER */


        if ((Dem_Cfg_GetMasterEvent(lEventId) != lEventId)
          || (lMemoryInfo->FirstEvent > lEventId)
          || (lMemoryInfo->LastEvent < lEventId))
        {
          /*The configuration has changed somehow - remove entry */
          Dem_Data_PermanentEntryRemove(lPermanentIndex);
        }
        else
        {
          /* If an OBD event has a permanent DTC, but does not fulfill storage percondtion, and is not currently
              in PASSIVE state -> clear it */
          if (DEM_ESM_GET_PERMANENT_STATE(Dem_Mem_PermanentGetStatus(lPermanentIndex)) == DEM_ESM_PERMANENT_ACTIVE)
          {
            if ( (Dem_DTC_TestEventStoresPermanentDTC(lEventId) == TRUE)
              && (Dem_DTC_TestStatusForPermanentStorage(lEventId) == FALSE))                                                     /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
            {
              Dem_Data_PermanentEntryClear(lEventId, FALSE);
            }
          }
        }
      }
    }
    /* Assume worst case */
    Dem_MemPermanent_ConfirmedChronologySetOverflown();

    Dem_MemPermanent_ConfirmedChronologyRestore();
  }
# endif


# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
  /* recovery */
  if ((Dem_Mem_GetContinuousMiHealingCounter() == DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_LOCKED)
    && (Dem_Indicator_GlobalIndicatorActivationMode() == DEM_INDICATOR_CONTINUOUS))                                              /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
  { /* If continuous MI counter is not processed, reset states so it will be processed later */
    Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID);
    Dem_Mem_SetContinuousMiAgingCounter(DEM_DATA_CONTINUOUS_MI_AGING_COUNTER_INVALID);
    Dem_Mem_SetContinuousMiAgingTimer(DEM_DATA_CONTINUOUS_MI_AGING_TIMER_INVALID);
  }

  if (Dem_Indicator_GetQualifiedActiveEventCount(DEM_ESM_WWHOBD_DTCCLASS_B1) == 0u)
  {
    /* set B1Counter to 190h (11400min) if no B1 event is confirmed and failed and B1 counter is greater than 200h (12000min)
    also clear the healing counter */
    if (Dem_Mem_GetB1Counter() >= DEM_DATA_B1COUNTER_200H)
    {
      Dem_Mem_SetB1Counter(DEM_DATA_B1COUNTER_190H);
    }

    Dem_Mem_SetB1HealingCounter(0);

    /* prepare continuous MI Healing if activation mode 4 is not active */
    if ((Dem_Mem_GetContinuousMiHealingCounter() == DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_INVALID)
      && (Dem_Indicator_GlobalIndicatorActivationMode() != DEM_INDICATOR_CONTINUOUS))                                            /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    {
      Dem_Mem_SetContinuousMiHealingCounter(DEM_DATA_CONTINUOUS_MI_HEALING_COUNTER_LOCKED);
    }
  }
# endif
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif


/* ****************************************************************************
 % Dem_Mem_IsDebounceNvEnabled
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Mem_IsDebounceNvEnabled(
  void
  )
{
  return (boolean)(DEM_CFG_SUPPORT_DEBOUNCE_NV == STD_ON);
}

/* ****************************************************************************
 % Dem_Mem_CopyDataDebounceNv
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_CopyDataDebounceNv(
  CONST(uint8, AUTOMATIC)  NvBlockStatus
  )
{
  if (Dem_Mem_IsDebounceNvEnabled() == TRUE)
  {
    Dem_EventIdType lEventId;
    uint16 lDebounceNvIndex;

    lDebounceNvIndex = Dem_Cfg_GlobalDebounceStorageEventCount(); /* is 0 if feature is disabled */
    lEventId = Dem_Cfg_GlobalEventCount();

    Dem_Internal_AssertReturnVoid(lEventId >= lDebounceNvIndex, DEM_E_PARAM_CONFIG)

      while (lDebounceNvIndex != 0U)
      {
        Dem_Internal_AssertReturnVoid(lEventId != DEM_EVENT_INVALID, DEM_E_INCONSISTENT_STATE)

        --lEventId;

        if (Dem_Event_TestDebounceCounterStoredInNv(lEventId) == TRUE)
        {
          --lDebounceNvIndex;
          Dem_Mem_DebounceSetStoredValue(lDebounceNvIndex, (sint16) Dem_Satellite_GetDebounceValue(Dem_Cfg_EventSatelliteId(lEventId), Dem_Cfg_EventSatelliteEventId(lEventId)));
        }
      }
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_DEBOUNCE),
                                NvBlockStatus);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FreezeFrameFindIndex
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_FreezeFrameFindIndex(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  Dem_EventIdType lMemoryRepresentativeEvent;
  uint8 lFreezeFrameIndex;
  uint8 lSelectedIndex;

  lMemoryRepresentativeEvent = Dem_Cfg_GetMemoryRepresentative(EventId);
  lFreezeFrameIndex = Dem_Cfg_GlobalObdIIFFCount();
  lSelectedIndex    = Dem_Cfg_GlobalObdIIFFCount();

  while (lFreezeFrameIndex != 0U)
  {
    lFreezeFrameIndex--;

    if (Dem_Mem_FreezeFrameGetEvent(lFreezeFrameIndex) == lMemoryRepresentativeEvent)
    { /* Requested event has a FreezeFrame stored */
      lSelectedIndex = lFreezeFrameIndex;
      break;
    }
  }

  return lSelectedIndex;
}
#endif

#if (( (DEM_FEATURE_NEED_OEM_EXTENSIONS_VCC == STD_ON) || \
       (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON)) && \
       (DEM_CFG_SUPPORT_OBDII == STD_ON))
/* ****************************************************************************
 % Dem_Mem_FreezeFrameDisplaced
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_FreezeFrameDisplaced(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId
  )
{
  if (Dem_Cfg_EventObdRelated(EventId) == TRUE)
  {
    uint8 lSelectedIndex;

    lSelectedIndex = Dem_Mem_FreezeFrameFindIndex(EventId);
    if (lSelectedIndex != Dem_Cfg_GlobalObdIIFFCount())
    {
      Dem_MemObdFreezeFrame_FreezeFrameFreeEntry(lSelectedIndex);
      Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_OBDFREEZEFRAME),
                                  DEM_NVM_BLOCKSTATE_DIRTYIMMEDIATE);
    }
  }
}
#endif



#if ((DEM_FEATURE_NEED_TIME_SERIES == STD_ON) && (DEM_CFG_SUPPORT_DISPLACEMENT == STD_ON))
/* ****************************************************************************
 % Dem_Mem_TimeSeriesDisplace_GetNextCandidate
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Mem_TimeSeriesDisplace_GetNextCandidate(
  CONSTP2VAR(Dem_MemAccess_DisplacementInfoType, AUTOMATIC, AUTOMATIC) CandidateInfo,
  CONST(Dem_MemState_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(uint8, AUTOMATIC)  ChronoIndexIterator
  )
{
  Dem_Mem_TimeSeriesEntryPtrType lTimeSeriesEntry;

  CandidateInfo->MemoryIndex = Dem_MemState_MemoryGetChronology(MemoryInfo, ChronoIndexIterator);                                /* SBSW_DEM_POINTER_WRITE_ARGUMENT */ /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

  lTimeSeriesEntry = Dem_Mem_TimeSeriesGetEntry(CandidateInfo->MemoryIndex);
  CandidateInfo->EventId = Dem_Mem_EntryGetEventId(lTimeSeriesEntry);                                                            /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
# if (DEM_CFG_AGING_RETAIN_MEMORY_ENTRY == STD_ON) || (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)
  {
    CandidateInfo->MemoryIndexAging = Dem_Memory_FindIndex(CandidateInfo->EventId);                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
# endif
  CandidateInfo->UdsStatus = Dem_DTC_ApplyCombinedStatus(Dem_DTC_GetDTCStatus(CandidateInfo->EventId));                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
# if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_DISPLACEMENT_FALLBACK_OLDEST == STD_ON)
  CandidateInfo->OldestDisplaceableIndex = DEM_MEM_INVALID_MEMORY_INDEX;                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
# endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_PENDING_DISPLACE_FREEZE_FRAME == STD_ON)
/* ****************************************************************************
 % Dem_Mem_FindDisplaceablePendingFreezeFrame
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
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Mem_FindDisplaceablePendingFreezeFrame(
  CONST(boolean, AUTOMATIC)  ReplaceMisfireOrFuelSys
  )
{
  uint8 lSelectedIndex;
  Dem_EventIdType lEventId;

  lEventId = Dem_Mem_FreezeFrameGetEvent(0);

  if ((Dem_UDSStatus_Test_CDTC(Dem_DTC_RetrieveStatus(lEventId)) == FALSE)
    && ((ReplaceMisfireOrFuelSys == TRUE)
    || ( (ReplaceMisfireOrFuelSys == FALSE)
      && (Dem_Event_TestHighPriorReadinessGroup(lEventId) == FALSE))                                                             /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    ))
  {
    lSelectedIndex = 0u;
  }
  else
  {
    lSelectedIndex = Dem_Cfg_GlobalObdIIFFCount();
  }

# if (DEM_CFG_GLOBAL_FREEZEFRAME_SIZE > 1u)                                                                                       /* COV_DEM_UNSUPPORTED_FEATURE_COMBINATION XF */
  /* Function is designed for a single freeze frame slot only. */
  Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
#endif

  return lSelectedIndex;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif


#if (DEM_CFG_SUPPORT_OBDII == STD_ON)
/* ****************************************************************************
% Dem_MemObdFreezeFrame_IsFreezeFrameVisibleInMode02
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Mem_IsFreezeFrameVisibleInMode02(                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
void
)
{
  return (Dem_Mem_FreezeFrameIndexMode02 != Dem_Cfg_GlobalObdIIFFCount());
}
#endif

#if (DEM_CFG_USE_NVM == STD_ON)
/* ****************************************************************************
 % Dem_Mem_MemoryIndexofIumpr
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_Cfg_MemoryIndexType, DEM_CODE)
Dem_Mem_MemoryIndexofIumpr(
void
)
{
  return DEM_CFG_MEMORY_IUMPR_INDEX;
}
#endif

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_MEM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Mem_Implementation.h
 *********************************************************************************************************************/
