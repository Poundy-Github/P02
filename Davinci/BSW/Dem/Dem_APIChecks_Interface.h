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
/*! \ingroup    Dem_Shared
 *  \defgroup   Dem_APIChecks APIChecks
 *  \{
 *  \file       Dem_APIChecks_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of all DET checks used in API sub-components.
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Laura Henze                   visera        Vector Informatik GmbH
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Erik Jeglorz                  visejz        Vector Informatik GmbH
 *  Friederike Schulze            visfrs        Vector Informatik GmbH
 *  Erwin Stamm                   visern        Vector Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vector Informatik GmbH 
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_APICHECKS_INTERFACE_H)
#define DEM_APICHECKS_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_APIChecks_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_APIChecks_Public Public Methods
 * \{
 */
 /* ****************************************************************************
 * Dem_APIChecks_SatelliteInState
 *****************************************************************************/
 /*!
 * \brief         Test if the Dem Satellite is in the given state
 *
 * \details       Test if the Dem Satellite is in the given state
 *
 * \param[in]     SatelliteId
 *                Index of the satellite associated with the event
 * \param[in]     InitState
 *                The initialization state
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           Developement error detection enabled
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_SatelliteInState(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(uint8, AUTOMATIC) InitState
);

 /* ****************************************************************************
 * Dem_APIChecks_MasterInState
 *****************************************************************************/
 /*!
 * \brief         Test if the Dem is in the given state
 *
 * \details       Test if the Dem is in the given state if developement
 *                error detection is on.
 *
 * \param[in]     InitState
 *                The initialization state
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_MasterInState(
  CONST(uint8, AUTOMATIC) InitState
);

/* ****************************************************************************
 * Dem_APIChecks_MasterNotInState
 *****************************************************************************/
/*!
 * \brief         Test if the Dem is not in the given state
 *
 * \details       Test if the Dem is not in the given state if developement
 *                error detection is on.
 *
 * \param[in]     InitState
 *                The initialization state
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_MasterNotInState(
  CONST(uint8, AUTOMATIC) InitState
);


/* ****************************************************************************
 * Dem_APIChecks_MasterAtLeastInState
 *****************************************************************************/
/*!
 * \brief         Test if the Dem is at least in the given state
 *
 * \details       Test if the Dem is at least in the given state if developement
 *                error detection is on.
 *
 * \param[in]     InitState
 *                The initialization state
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_MasterAtLeastInState(
  CONST(uint8, AUTOMATIC) InitState
);

/* ****************************************************************************
 * Dem_APIChecks_SatelliteAtLeastInState
 *****************************************************************************/
/*!
 * \brief         Test if the Dem is at least in the given state
 *
 * \details       Test if the Dem is at least in the given state if developement
 *                error detection is on.
 *
 * \param[in]     InitState
 *                The initialization state
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_SatelliteAtLeastInState(
  CONST(Dem_Satellite_IdType, AUTOMATIC)  SatelliteId,
  CONST(uint8, AUTOMATIC) InitState
);

/* ****************************************************************************
 * Dem_APIChecks_SingleSatellite
 *****************************************************************************/
/*!
 * \brief         Check that only one satellite is configured.
 *
 * \details       Check that only one satellite is configured if developement
 *                error detection is on.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_SingleSatellite(
  void
);

/* ****************************************************************************
 * Dem_APIChecks_isBoolean
 *****************************************************************************/
/*!
 * \brief         Check that passed parameter matches definition of type boolean
 *
 * \details       Check that passed parameter matches definition of type boolean
 *                if developement error detection is on.
 * \param[in]     Paramter
 *                An abitrary boolean parameter
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_isBoolean(
  boolean  Parameter
  );
 
/* ****************************************************************************
 * Dem_APIChecks_isBoolean
 *****************************************************************************/
/*!
 * \brief         Check that current partition is master partition
 *
 * \details       Check that current partition is master partition if developement
 *                error detection is on.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_IsMasterPartition(
  void
  );

/* ****************************************************************************
 * Dem_APIChecks_DebounceCounterNvConditions
 *****************************************************************************/
/*!
 * \brief         Test that preconditions for status reports are fulfilled 
 *                if debounce counters are stored non-volatile.
 *
 * \details       Test that preconditions for status reports are fulfilled 
 *                if debounce counters are stored non-volatile anf if developement
 *                error detection is on.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_DebounceCounterNvConditions(
  Dem_EventIdType  EventId
);

 /* ****************************************************************************
 * Dem_APIChecks_ReportedSimilarConditions
 *****************************************************************************/
 /*!
 * \brief         Test if the passed status is valid.
 *
 * \details       Test That the passed status is not a similar condition status or
 *                that a similar condition status is supported by the passed event.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     Monitor result reported for the Event.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_ReportedSimilarConditions(
  Dem_EventIdType  EventId,
  Dem_EventStatusType EventStatus
);

 /* ****************************************************************************
 * Dem_APIChecks_EventId
 *****************************************************************************/
 /*!
 * \brief         Test if the passed event id is in valid range.
 *
 * \details       Test if the passed event id is in valid range if developement
 *                 error detection is on.
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_EventId(
  Dem_EventIdType EventId
);

/* ****************************************************************************
 * Dem_APIChecks_ClientId
 *****************************************************************************/
/*!
 * \brief         Test if the passed client id is in valid range.
 *
 * \details       Test if the passed client id is in valid range if developement
 *                error detection is on.
 *
 * \param[in]     ClientId
 *                Unique handle of the Client.
 *                The EventId must be in range 
 *                [1..Dem_ClientAccess_GlobalClientCount()[.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_ClientId(
  uint8  ClientId
);

/* ****************************************************************************
 * Dem_APIChecks_NullPointer
 *****************************************************************************/
/*!
 * \brief         Test that the passed pointer is not 'null pointer'.
 *
 * \details       Test that the passed pointer is not 'null pointer'if developement
 *                error detection is on.
 *
 * \param[in]     ExternalPtr
 *                An abitrary external pointer.
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_NullPointer(
  CONSTP2CONST(void, AUTOMATIC, DEM_SHARED_DATA)  ExternalPtr
  );

 /* ****************************************************************************
 * Dem_APIChecks_EventApplicationId
 *****************************************************************************/
 /*!
 * \brief         Check whether the event can be processed in the current
 *                execution context
 *
 * \details       Checks whether the given event is configured to be processed
 *                on the current OS application. In single partition
 *                configurations, this is always the case.
 *
 * \param[in]     EventId
 *                Global Event Id
 *
 * \return        TRUE
 *                The event can be processed
 * \return        FALSE
 *                The event belongs to a different OS application
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_EventApplicationId(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId                                                                                     /* PRQA S 3206 */ /* MD_DEM_3206 */
);

 /* ****************************************************************************
 * Dem_APIChecks_ReportedStatus
 *****************************************************************************/
 /*!
 * \brief         Test if the passed status is valid.
 *
 * \details       Test if the passed status is valid if developement
 *                error detection is on.
 *
 * \param[in]     Monitor result reported for the Event.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_ReportedStatus(
  Dem_EventStatusType EventStatus
);



/* ****************************************************************************
 * Dem_APIChecks_IsIUMPRRatioIDValid
 *****************************************************************************/
/*!
 * \brief         Test if the passed ratio index is valid.
 *
 * \details       Test if the passed ratio index is valid. if developement
 *                error detection is on.
 *
 * \param[in]     RatioID
 *                Unique handle of the Ratio, which is equal to the EventId
 *                associated with the Ratio.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_IsIUMPRRatioIDValid(
  Dem_RatioIdType  RatioID
);

/* ****************************************************************************
 * Dem_APIChecks_IsRatioIDOfApiType
 *****************************************************************************/
/*!
 * \brief         Test if the passed ratio is of api type
 *
 * \details       Test if the passed ratio is of api type if developement
 *                error detection is on.
 *
 * \param[in]     RatioID
 *                Unique handle of the Ratio, which is equal to the EventId
 *                associated with the Ratio.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_IsRatioIDOfApiType(
  Dem_RatioIdType  RatioID
);

/* ****************************************************************************
 * Dem_APIChecks_IsRatioDenominatorGroupPhysApi
 *****************************************************************************/
/*!
 * \brief         Test if the passed ratio denominator group is of phys api type.
 *
 * \details       Test if the passed ratio denominator group is of phys api type.
 *                If developement error detection is on.
 *
 * \param[in]     RatioID
 *                Unique handle of the Ratio, which is equal to the EventId
 *                associated with the Ratio.
 *
 * \return        TRUE
 *                No error detected
 * \return        FALSE
 *                Error detected
 *
 * \pre           RatioIndex is valid.
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_APIChecks_IsRatioDenominatorGroupPhysApi(
  Dem_RatioIdType  RatioID
);


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_APICHECKS_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_APIChecks_Interface.h
 *********************************************************************************************************************/
