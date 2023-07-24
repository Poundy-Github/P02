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
/*! \ingroup    Dem_Iumpr
 *  \defgroup   Dem_Iumpr_Ratio Dem_Iumpr_Ratio
 *  \{
 *  \file       Dem_Ratio_Interface.h
 *  \brief      IUMPR Ratio subcomponent.
 *  \details    Provides functionality to manipulate IUMPR ratios for the Dem_Iumpr subcomponent.
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

#if !defined (DEM_RATIO_INTERFACE_H)
#define DEM_RATIO_INTERFACE_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Ratio_Types.h"
#include "Dem_FimFid_Types.h"
#include "Dem_Event_Types.h"
#include "Dem_Lcfg.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT OBJECT FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Iumpr_Ratio_PublicProperties Public Properties
 * \{
 */

/* ****************************************************************************
 * Dem_Iumpr_Ratio_Numerator_Lock
 *****************************************************************************/
/*!
 * \brief         Set numerators locked state in global iumpr state
 *
 * \details       Set numerators locked state in global iumpr state
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_Numerator_Lock(void);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_Numerator_ReleaseLock
 *****************************************************************************/
/*!
 * \brief         Reset numerators locked state in global iumpr state
 *
 * \details       Reset numerators locked state in global iumpr state
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_Numerator_ReleaseLock(void);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_ResetFidPending
 *****************************************************************************/
/*!
 * \brief         Set the ratio as not blocked by a FiD
 *
 * \details       Set the ratio as not blocked by a FiD
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_ResetFidPending(CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_Disconnect
 *****************************************************************************/
/*!
 * \brief         Set ratio disconnected state of a ratio
 *
 * \details       Set ratio disconnected state of a ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_Disconnect(CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex);


/* ****************************************************************************
 * Dem_Iumpr_Ratio_Reconnect
 *****************************************************************************/
/*!
 * \brief         Reset ratio disconnected state of a ratio
 *
 * \details       Reset ratio disconnected state of a ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_Reconnect(CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex);

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
 * \defgroup Dem_Iumpr_Ratio_Public Public Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Iumpr_Ratio_GetReadinessGroupType
 *****************************************************************************/
/*!
 * \brief         Get the readiness group type of the ratio
 *
 * \details       Get the readiness group type (e.g. Cat1, Cat2, BoostPr, ...)
 *                of the ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        The readiness group type of the ratio
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_IumprReadinessGroupType, DEM_CODE)
Dem_Iumpr_Ratio_GetReadinessGroupType(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_QueueUpdate
 *****************************************************************************/
/*!
 * \brief         Set the update state of the ratio
 *
 * \details       Set the update state of the ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 * \param[in]     Value
 *                New update state
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_QueueUpdate(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex,
CONST(boolean, AUTOMATIC) Value
);


/* ****************************************************************************
 * Dem_Iumpr_Ratio_GetRatioStatusUtil
 *****************************************************************************/
/*!
 * \brief         Get the status of the ratio
 *
 * \details       Get the status of the ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 *
 * \return        The status of the ratio
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Iumpr_Ratio_GetRatioStatusUtil(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_SetRatioStatusUtil
 *****************************************************************************/
/*!
 * \brief         Set the status of the ratio
 *
 * \details       Set the status of the ratio
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 * \param[in]     Value
 *                New status of the ratio
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_SetRatioStatusUtil(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex,
CONST(uint8, AUTOMATIC) Value
);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_OpCycleStart
 *****************************************************************************/
/*!
 * \brief         Perform all actions relevant on OBD DCY restart
 *
 * \details       -
 *
 * \param[in]     RatioIndex
 *                Unique handle of the ratio
 *
 * \pre           -
 *
 * \context       TASK
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_OpCycleStart(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);


/* ****************************************************************************
 * Dem_Iumpr_Ratio_ProcessUpdate
 *****************************************************************************/
/*!
 * \brief         Performs scheduled IUMPR calculations for a pending ratio.
 *
 * \details       Performs scheduled IUMPR calculations for a pending ratio.
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \return        TRUE
 *                Ratio status has changed, and needs a NvM update
 * \return        FALSE
 *                Ratio status hasn't changed, and needs no NvM update
 *
 * \pre           -
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_Ratio_ProcessUpdate(
Dem_RatioIdIndexType RatioIndex
);


/* ****************************************************************************
 * Dem_Iumpr_Ratio_InitNv
 *****************************************************************************/
/*!
 * \brief         Initalize ratio specific information that is persisted to NvM
 *
 * \details       Used when the IUMPR Nv-Block needs to be re-initialized.
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different RatioIndex
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_InitNv(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_ReportRatioFault
 *****************************************************************************/
/*!
 * \brief         Queue ratio processing for an event
 *
 * \details       This function will set up IUMPR processing of the event's
 *                ratio, if the numerator has not been incremented yet.
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_ReportRatioFault(
  CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
);

/* ****************************************************************************
 * Dem_Iumpr_Ratio_GetRatio
 *****************************************************************************/
/*!
 * \brief         Get numerator and denominator
 *
 * \details       Get numerator and denominator
 *
 * \param[in]     RatioIndex
 *                Unique handle of the Ratio
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_Ratio_GetRatio(
  CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Numerator,
  CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Denominator
);

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_RATIO_INTERFACE_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Ratio_Interface.h
 *********************************************************************************************************************/
