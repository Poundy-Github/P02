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
/*! \ingroup    Dem_Memory
 *  \defgroup   Dem_MemoryRestoration Memory Restoration
 *  \{
 *  \file       Dem_MemoryRestoration_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Interface of the Memory Restoration subcomponent which restores the status of a memory entry, 
 *              fixes memory entry allocation errors etc.
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

#if !defined (DEM_MEMORYRESTORATION_INTERFACE_H)
#define DEM_MEMORYRESTORATION_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                        /* Dem module header */
/* ------------------------------------------------------------------------- */
#include "Dem_MemoryRestoration_Types.h"

/* ------------------------------------------------------------------------- */

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/


/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_MemoryRestoration_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_MemoryRestoration_FixCorruptMemoryEntry
 *****************************************************************************/
/*!
 * \brief         Check for corrupt memory entry.
 *
 * \details       Test if a memory entry is corrupt. If so, fix it and report
 *                DET.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory.
 * \param[in]     MemoryIndex
 *                Memory index of the current memory entry.
 *
 * \return        TRUE
 *                Entry was corrupt - caller shall continue with next entry.
 * \return        FALSE
 *                Entry is correct.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_MemoryRestoration_FixCorruptMemoryEntry(
  CONST(Dem_MemState_MemoryInfoPtrType, AUTOMATIC)  MemoryInfo,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)    MemoryIndex
  );

/* ****************************************************************************
 * Dem_MemoryRestoration_FixDoubleAllocation
 *****************************************************************************/
/*!
 * \brief         Check for duplicate memory entry.
 *
 * \details       Test if memory entry is allocated to an event that already
 *                has a memory entry. If so, remove the duplicate.
 *
 * \param[in]     MemoryInfo
 *                Pointer to the memory descriptor for the event memory.
 * \param[in]     MemoryIndex
 *                Memory index of the current memory entry.
 *
 * \return        TRUE
 *                This memory entry was the duplicate - the caller shall
 *                continue with next entry, this one was removed.
 * \return        FALSE
 *                This entry is correct.
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_MemoryRestoration_FixDoubleAllocation(
  CONST(Dem_MemState_MemoryInfoPtrType, AUTOMATIC)     MemoryInfo,
  CONST(Dem_Cfg_MemoryIndexType, AUTOMATIC)       MemoryIndex
  );

/* ****************************************************************************
 * Dem_MemoryRestoration_RestoreEventStatus
 *****************************************************************************/
/*!
 * \brief         Restores the event status of an event
 *
 * \details       Restores the event status and internal status based on the 
 *                configured storage trigger.
 *
 * \param[in]     MemoryEntryId
 *                Memory Entry Id of the current memory entry.
 * \param[in]     EventId
 *                EventId stored at the memory index.
 *
 * \return        - 
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_MemoryRestoration_RestoreEventStatus(
  CONST(Dem_Cfg_MemoryEntryHandleType, AUTOMATIC)    MemoryEntryId,
  CONST(Dem_EventIdType, AUTOMATIC)               EventId
  );

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_MEMORYRESTORATION_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_MemoryRestoration_Interface.h
 *********************************************************************************************************************/
