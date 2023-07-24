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
/*! \ingroup    Dem_Master
 *  \defgroup   Dem_Iumpr Dem_Iumpr
 *  \{
 *  \file       Dem_Iumpr_Interface.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Interface of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
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
 *  Friederike Schulze            visfrs        Vector Informatik GmbH
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

#if !defined (DEM_IUMPR_INTERFACE_H)
#define DEM_IUMPR_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Iumpr_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Iumpr_PublicProperties Public Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Iumpr_IsEnabled
 *****************************************************************************/
/*!
 * \brief         Returns true if IUMPR feature set is enabled.
 * \details       -
 *
 * \return        TRUE
 *                Support for IUMPR
 * \return        FALSE
 *                No support for IUMPR
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsEnabled(
void
);


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Iumpr_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Iumpr_InitNv
 *****************************************************************************/
/*!
 * \brief         Initializes IUMPR specific NvM data.
 *
 * \details       Initializes IUMPR specific NvM data.
 *                Resets all IUMPR relevant variables to zero.
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitNv(
void
);

/* ****************************************************************************
 * Dem_Iumpr_GetGeneralIumprData
 *****************************************************************************/
/*!
 * \brief         Get general Iumpr counter values
 *
 * \details       Get general Iumpr counter values
 *
 * \param[out]    GeneralDenominator
 *                
 * \param[out]    IgnitionCycles
 *
 * \param[out]    IgnitionCyclesHybrid
 *                
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_GetGeneralIumprData(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  GeneralDenominator,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  IgnitionCycles,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  IgnitionCyclesHybrid
);

/* ****************************************************************************
 * Dem_Iumpr_SetDenominatorCondition
 *****************************************************************************/
/*!
 * \brief         Sets the denominator condition status for a given
 *                denominator group.
 *
 * \details       Sets the denominator condition status for a given
 *                denominator group. Decides based on the condition id which
 *                procedure should be executed.
 *
 * \param[in]     ConditionId
 *                The denominator group for which the conditions are reported.
 * \param[in]     ConditionStatus
 *                The new status of the given ConditionId
 *
 * \return        E_OK
 *                The new condition status was accepted
 * \return        E_NOT_OK
 *                The new condition status was not accepted
 *
 * \pre           RTE is active (if RTE is used). Feature IUMPR is supported.
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetDenominatorCondition(
Dem_IumprDenomCondIdType ConditionId,
Dem_IumprDenomCondStatusType ConditionStatus
);


/* ****************************************************************************
 * Dem_Iumpr_ResetPendingFids
 *****************************************************************************/
/*!
 * \brief         Reset pending FID status of all ratios
 *
 * \details       Reset pending FID status of all ratios
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ResetPendingFids(
void
);


/* ****************************************************************************
 * Dem_Iumpr_RestartDcy
 *****************************************************************************/
/*!
 * \brief         Resets global IUMPR status information.
 *
 * \details       Resets global IUMPR status information.
 *                Resets general OBD denominator status.
 *                Resets general individual denominator status.
 *                Resets the hybrid ignition cycles status
 *                Resets the numerator locked status
 *                Does not reset event specific ratio status information.
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RestartDcy(
void
);



/* ****************************************************************************
 * Dem_Iumpr_ReportRatioFault
 *****************************************************************************/
/*!
 * \brief         Report Ratio fault to the master.
 *
 * \details       Report Ratio fault to the master.
 *
 * \param[in]     EventId
 *                Unique handle of an event
 * \param[in]     FaultOrigin
 *                Information whether the fault was reported by API or by an 
 *                event report
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ReportRatioFault(
const Dem_EventIdType  EventId,
const Dem_Iumpr_FaultOriginType FaultOrigin
);

/* ****************************************************************************
 * Dem_Iumpr_SetRatioAvailability
 *****************************************************************************/
/*!
 * \brief         Disconnect or reconnect an event from ratio processing.
 *
 * \details       Disconnect or reconnect an event from ratio processing.
 *
 * \param[in]     EventId
 *                Unique handle of an event
 *                Dem_Iumpr_RatioAvailability
 *                Command to either disconnect or reconnect a ratio of the provided
 *                event
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Iumpr_SetRatioAvailability(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONST(Dem_Iumpr_RatioAvailabilityType, AUTOMATIC) availabiltyCommand
);


/* ****************************************************************************
 * Dem_Iumpr_OpCycleStart
 *****************************************************************************/
/*!
 * \brief         Handle event specific changes during dcy start.
 *
 * \details       Handle event specific changes during dcy start.
 *                Resets event's ratio status.
 *                Resets event's pending flag.
 *
 * \param[in]     EventId
 *                Unique handle of an event
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different EventId
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OpCycleStart(
  CONST(Dem_EventIdType, AUTOMATIC) EventId
);


/* ****************************************************************************
 * Dem_Iumpr_ProcessIgnCycleCounterIncrement
 *****************************************************************************/
/*!
 * \brief         Increment ignition cycle counter
 *
 * \details       Increments ignition cycle counter if conditions are fulfilled
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ProcessIgnCycleCounterIncrement(
  void
);


/* ****************************************************************************
 * Dem_Iumpr_ProcessIgnHybridCycleCounterIncrement
 *****************************************************************************/
/*!
 * \brief         Processes hybrid ignition counter
 *
 * \details       Processes hybrid ignition counter
 *
 * \param[in]     CycleState
 *                DEM_CYCLE_STATE_START: Start a stopped cycle, or restart an
 *                                       active cycle.
 *                DEM_CYCLE_STATE_END:   Stop an active cycle.
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ProcessIgnHybridCycleCounterIncrement(
  CONST(Dem_OperationCycleStateType, AUTOMATIC) CycleState
);


/* ****************************************************************************
 * Dem_Iumpr_IsIgnitionHybrid
 *****************************************************************************/
/*!
 * \brief         Test if the cycle is configured to be the hybrid ignition cycle
 *
 * \details       Test if the cycle is configured to be the hybrid ignition cycle
 *
 * \param[in]     CycleId
 *                Unique Id of the cycle
 *
 * \return        TRUE
 *                The cycle is the hybrid ignition cycle
 * \return        FALSE
 *                The cycle is not the hybrid ignition cycle
 *
 * \pre           Feature IUMPR and hybrid ingnition cycle is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsIgnitionHybrid(
  CONST(uint8, AUTOMATIC) CycleId
);


/* ****************************************************************************
 * Dem_Iumpr_MainFunction
 *****************************************************************************/
/*!
 * \brief         Performs scheduled IUMPR calculations
 *
 * \details       This function checks if the numerator and denominator must be
 *                incremented for any ratio, and performs all necessary
 *                increments.
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_MainFunction(
  void
);



/* ****************************************************************************
 * Dem_Iumpr_CalculateObdRatio
 *****************************************************************************/
/*!
 * \brief         Function retrieves the IUMPR numerator and denominator of the
 *                ratio associated with the event.
 *
 * \details       Function retrieves the IUMPR numerator and denominator of the
 *                ratio associated with the event.
 *
 * \param[in]     EventId
 *                Unique event handle
 * \param[out]    Numerator
 *                Pointer to receive the IUMPR numerator
 * \param[out]    Denominator
 *                Pointer to receive the IUMPR denominator
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Iumpr_CalculateObdRatio(
  CONST(Dem_EventIdType, AUTOMATIC) EventId,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Numerator,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Denominator
);


/* ****************************************************************************
 * Dem_Iumpr_LockNumerators
 *****************************************************************************/
/*!
 * \brief         Locks numerators globally.
 *
 * \details       Locks numerators globally.
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_LockNumerators(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_LockRatioDenominator
 *****************************************************************************/
/*!
 * \brief         Passthrough to Dem_Iumpr_Ratio_LockDenominator().
 *
 * \details       Passthrough to Dem_Iumpr_Ratio_LockDenominator().
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        E_OK
 *                Ratio has been locked
 * \return        E_NOT_OK
 *                Event of the ratio is unavailable
 *
 * \pre           Feature IUMPR is supported. RatioId is valid.
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_LockRatioDenominator(
  Dem_RatioIdType RatioID
);



/* ****************************************************************************
 * Dem_Iumpr_ReleaseRatioDenominator
 *****************************************************************************/
/*!
 * \brief         Passthrough to Dem_Iumpr_Ratio_ReleaseDenominator().
 *
 * \details       Passthrough to Dem_Iumpr_Ratio_ReleaseDenominator().
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        E_OK
 *                Ratio has been released
 * \return        E_NOT_OK
 *                Event of the ratio is unavailable
 *
 *
 * \pre           Feature IUMPR is supported. RatioId is valid.
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_ReleaseRatioDenominator(
  Dem_RatioIdType RatioID
);



/* ****************************************************************************
 * Dem_Iumpr_Filter_SetFilter
 *****************************************************************************/
/*!
 * \brief         Initializes readiness group iterator
 *
 * \details       Initializes readiness group iterator for the Iumpr filter
 *                functionality.
 *
 * \param[in]     IumprReadinessGroup
 *                Unique handle of a readiness group
 * \param[in]     DTCOrigin
 *                The event memory of the requested readiness group.
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_SetFilter(
  Dem_IumprReadinessGroupType IumprReadinessGroup,
  Dem_DTCOriginType  DTCOrigin
  );



/* ****************************************************************************
 * Dem_Iumpr_InitFilter
 *****************************************************************************/
/*!
 * \brief         Initializes Iumpr static variables.
 *
 * \details       Initializes Iumpr static variables.
 *
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitFilter(
  void
);


/* ****************************************************************************
 * Dem_Iumpr_Filter_GetFirstEvent
 *****************************************************************************/
/*!
 * \brief         Get the first event of Iumpr filter.
 *
 * \details       Get the first event of Iumpr filter.
 *
 *
 * \return        Unique identifier of the first event in the Iumpr filter.
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Iumpr_Filter_GetFirstEvent(
  void
);


/* ****************************************************************************
 * Dem_Iumpr_Filter_GetCurrentEvent
 *****************************************************************************/
/*!
 * \brief         Get the current event of Iumpr filter.
 *
 * \details       Get the current event of Iumpr filter, which the Iumpr filter
 *                iterator points to.
 *
 * \return        Unique identifier of the currently Iumpr filter selected event.
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Iumpr_Filter_GetCurrentEvent(
  void
);


/* ****************************************************************************
 * Dem_Iumpr_Filter_GetCount
 *****************************************************************************/
/*!
 * \brief         Get the number of currently filtered ratios.
 *
 * \details       Get the number of currently filtered ratios.
 *
 * \param[out]    NumberOfFilteredRatios
 *                Number of ratios which are currently filtered by the Iumpr filter.
 *
 * \return        E_OK
 *                The Iumpr filter is initialized. The number of ratios
 *                has been written.
 * \return        E_NOT_OK
 *                The Iumpr filter is uninitialized. The number of ratios
 *                has NOT been written.
 *
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetCount(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredRatios                                                                  /* PRQA S 1330 */ /* MD_DEM_8.3_rte */
);


/* ****************************************************************************
 * Dem_Iumpr_Filter_GetNext
 *****************************************************************************/
/*!
 * \brief         Get the next Iumpr filtered ratio and its data.
 *
 * \details       Iterates to the next ratio within the Iumpr filter and returns
 *                its information.
 *
 * \param[out]    UdsDtcNumber
 *                UDS Dtc number of the ratio
 * \param[out]    ObdDtcNumber
 *                OBD Dtc number of the ratio
 * \param[out]    Denominator
 *                Denominator value of the ratio
 * \param[out]    Numerator
 *                Numerator value of the ratio
 *
 * \return        E_OK
 *                A new ratio has been found and its values are returned
 * \return        E_NOT_OK
 *                No new ratio filtered by the Iumpr filter
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetNext(
  P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  UdsDtcNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  ObdDtcNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Denominator,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Numerator
);


/* ****************************************************************************
 * Dem_Iumpr_Filter_GetCurrent
 *****************************************************************************/
/*!
 * \brief         Get the currently Iumpr filtered ratio and its data.
 *
 * \details       Iterates to the currently Iumpr filtered ratio and returns
 *                its information.
 *
 * \param[out]    UdsDtcNumber
 *                UDS Dtc number of the ratio
 * \param[out]    ObdDtcNumber
 *                OBD Dtc number of the ratio
 * \param[out]    Denominator
 *                Denominator value of the ratio
 * \param[out]    Numerator
 *                Numerator value of the ratio
 *
 * \return        E_OK
 *                Currently selected ratio has been found and its values are returned
 * \return        E_NOT_OK
 *                Currently no ratio is selected by the Iumpr filter
 *
 *
 * \pre           Feature IUMPR is supported
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetCurrent(
  P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  UdsDtcNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  ObdDtcNumber,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Denominator,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Numerator
);


/* ****************************************************************************
 * Dem_Iumpr_GetRatioReportingType
 *****************************************************************************/
/*!
 * \brief         Get the reporting type of the ratio
 *
 * \details       Get the reporting type (symmetrical, asymmetrical) of the
 *                ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        The reporting type \ref Dem_Cfg_RatioReportingType
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Iumpr_GetRatioReportingType(
  CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);


/* ****************************************************************************
 * Dem_Iumpr_GetDenGroupOfRatio
 *****************************************************************************/
/*!
 * \brief         Get the denominator group of the ratio
 *
 * \details       Get the denominator group of the ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        The Denominator group \ref Dem_Cfg_DenominatorGroupType
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Iumpr_GetDenGroupOfRatio(
  CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);

/* ****************************************************************************
 * Dem_Iumpr_InitCycleCounter
 *****************************************************************************/
/*!
 * \brief         Initialize ignition cycle counter values
 *
 * \details       -
 *
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitCycleCounter(
  void
);


/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_IUMPR_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Iumpr_Interface.h
 *********************************************************************************************************************/
