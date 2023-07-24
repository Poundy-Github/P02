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
/*! \addtogroup Dem_Iumpr_Ratio
 *  \{
 *  \file       Dem_Ratio_Types.h
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

#if !defined (DEM_RATIO_TYPES_H)
#define DEM_RATIO_TYPES_H

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"
#include "Dem_Denominator_Types.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*!
 * \defgroup  DEM_IUMPRGeneralDenominatorState  Macros encoding General Denominator states
 * Macros encoding General Denominator states
 * \{
 */
# define DEM_RATIO_GENDEN_INCREMENTED                    ((uint8)(0x01U))  /*!< General denominator incremented this DCY */
# define DEM_RATIO_GENDEN_INCREMENTED_MASK               ((uint8)(0xfeU))  /*!< Mask to reset 'General denominator incremented' */
# define DEM_RATIO_GENDEN_CONDITIONS_REACHED             ((uint8)(0x02U))  /*!< General denominator conditions reached */
# define DEM_RATIO_GENDEN_CONDITIONS_REACHED_MASK        ((uint8)(0xfdU))  /*!< Mask to reset 'General denominator conditions reached' */
# define DEM_RATIO_GENDEN_CONDITIONS_INHIBITED           ((uint8)(0x04U))  /*!< General denominator is failed/blocked this DCY */
# define DEM_RATIO_GENDEN_CONDITIONS_INHIBITED_MASK      ((uint8)(0xfbU))  /*!< Mask to reset 'General denominator failed/blocked this DCY' */
# define DEM_RATIO_GENDEN_CONDITIONS_INC_INHIBITED       ((uint8)(0x08U))  /*!< General denominator increment is inhibtited for this DCY */
# define DEM_RATIO_GENDEN_CONDITIONS_INC_INHIBITED_MASK  ((uint8)(0xf7U))  /*!< Mask to reset 'General denominator increment is inhibtited this DCY' */
/*!
 * \}
 */

/*!
 * \defgroup  DEM_IUMPRGlobalNumeratorsState  Macros encoding Iumpr numerator states
 * Macros encoding Iumpr numerator locked states
 * \{
 */
# define DEM_RATIO_NUMERATORS_LOCKED                     ((uint8)(0x01U))  /*!< Ratio numerators locked globally */
# define DEM_RATIO_NUMERATORS_LOCKED_MASK                ((uint8)(0xfeU))  /*!< Reset mask for Ratio numerators locked globally */
/*!
 * \}
 */

/*! Maximum counter value for numerator / denominator */
# define DEM_RATIO_MAX_VALUE                             ((uint16)0xffffU)

/*!
 * \defgroup  DEM_IUMPRNumeratorStatus  Macros encoding ratio specific numerator states
 * Macros encoding ratio specific numerator states
 * \{
 */
# define DEM_RATIO_NUM_INCREMENTED                       ((uint8)(0x10U))  /*!< Numerator incremented this DCY */
# define DEM_RATIO_NUM_INCREMENTED_MASK                  ((uint8)(0xefU))  /*!< Reset mask for numerator incremented this DCY */
# define DEM_RATIO_NUM_FAULTDETECT                       ((uint8)(0x20U))  /*!< Fault detection completed this DCY */
# define DEM_RATIO_NUM_FAULTDETECT_MASK                  ((uint8)(0xdfU))  /*!< Reset mask for fault detection completed this DCY */
# define DEM_RATIO_DISCONNECTED                          ((uint8)(0x40U))  /*!< Ratio disconnected (suppressed) */
# define DEM_RATIO_DISCONNECTED_MASK                     ((uint8)(0xbfU))  /*!< Reset mask for ratio disconnected (suppressed) */
/*!
 * \}
 */

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



#endif /* DEM_RATIO_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Ratio_Types.h
 *********************************************************************************************************************/
