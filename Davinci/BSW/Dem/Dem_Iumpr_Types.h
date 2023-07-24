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
/*! \addtogroup Dem_Iumpr
 *  \{
 *  \file       Dem_Iumpr_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Types of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
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

#if !defined (DEM_IUMPR_TYPES_H)
#define DEM_IUMPR_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/
/*!
 * \defgroup  Dem_Iumpr_DenominatorStatus  Macros encoding ratio specific denominator states
 * Macros encoding ratio specific denominator states
 * \{
 */
# define DEM_RATIO_INDIGENDEN_CONDITIONS_REACHED       ((uint8)(0x80U))  /*!< General Denominator is fulfilled since incrementing 500 Miles denominator */
# define DEM_RATIO_INDIGENDEN_CONDITIONS_REACHED_MASK  ((uint8)(0x7fU))  /*!< Reset mask for General Denominator is fulfilled since incrementing 500 Miles denominator */
/*!
 * \}
 */

/*!
 * \defgroup  Dem_Iumpr_Invalid Macros encoding specific invalid values
 * Macros encoding invalid condition and readiness group
 * \{
 */
# define DEM_DENOMINATOR_COND_INVALID                ((Dem_IumprDenomCondIdType)(0x07U))  /*!< First out of range value of Dem_IumprDenomCondIdType */
# define DEM_IUMPR_READINESS_GROUP_INVALID        ((Dem_IumprReadinessGroupType)(0x11U))  /*!< First out of range value of Dem_IumprReadinessGroupType */
/*!
 * \}
 */


/*!
 * \defgroup  DEM_IUMPRHybridIgnitionCounterState  Macros encoding hybrid ignition cycle counter states
 * Macros encoding hybrid ignition counter states
 * \{
 */
# define DEM_IUMPR_IGN_CYC_HYBRID_INCREMENTED            ((uint8)(0x01U))  /*!< Hybrid ignition cycle counter incremented this DCY */
# define DEM_IUMPR_IGN_CYC_HYBRID_INCREMENTED_MASK       ((uint8)(0xfeU))  /*!< Reset mask hybrid ignition cycle counter incremented this DCY */
/*!
 * \}
 */




/*! Number of ratios which are processed at most before critical section 'DiagMonitor' is left for a short time. */
# define DEM_IUMPR_RESET_PENDING_RATIO                   ((uint8)50u)

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Filter data for IUMPR requests */
struct Dem_IumprFilter_InfoType_s
{
  Dem_EventIdType      FirstEvent;     /*!< First event matching the request */
  Dem_EventIdType      CurrentEvent;   /*!< Current event id */
  Dem_EventIdType      LastEvent;      /*!< Last event matching the request */
  uint8                ReadinessGroup; /*!< Filtered readiness group */
};

/*! Filtering strategy for DTC filtering */
typedef enum Dem_Iumpr_RatioAvailability
{
  Dem_Iumpr_ReconnectRatio = 0, /*!< Command to connect ratio */
  Dem_Iumpr_DisconnectRatio   /*!< Command to disconnect ratio */
} Dem_Iumpr_RatioAvailabilityType;

/*! Filter data type for IUMPR requests */
typedef struct Dem_IumprFilter_InfoType_s Dem_IumprFilter_InfoType;

/*! Ignition cycle type */
typedef enum Dem_Iumpr_CycleCounter_CycleCounterType
{
  Dem_Iumpr_CycleCounter_IgnitionCycleCounter = 0,    /*!< Ignition cycle counter */
  Dem_Iumpr_CycleCounter_IgnitionHybridCycleCounter   /*!< Ignition Hybrid cycle counter */
} Dem_Iumpr_CycleCounter_CycleCounterType;

/*! Origin of fault reporting */
typedef enum Dem_Iumpr_FaultOriginType
{
  Dem_Iumpr_FaultOrigin_API = DEM_RATIO_API,                        /*!< Fault was reported by API */
  Dem_Iumpr_FaultOrigin_EventReport = DEM_RATIO_OBSERVER,           /*!< Fault was reported by SetEventStatus*/
  Dem_Iumpr_FaultOrigin_Invalid = DEM_RATIO_REPORTINGTYPE_INVALID   /*!< Invalid Reporting Type */
} Dem_Iumpr_FaultOriginType;

#endif /* DEM_IUMPR_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Iumpr_Types.h
 *********************************************************************************************************************/
