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
 *             File:  Rte_Tacho_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Tacho>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_TACHO_TYPE_H
# define RTE_TACHO_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Invalid_
#   define Cx0_Invalid_ (0U)
#  endif

#  ifndef Cx1_Valid_
#   define Cx1_Valid_ (1U)
#  endif

#  ifndef Cx2_Initial_value_
#   define Cx2_Initial_value_ (2U)
#  endif

#  ifndef Cx3_Reserved_
#   define Cx3_Reserved_ (3U)
#  endif

#  ifndef Cx1_valid_
#   define Cx1_valid_ (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_TACHO_TYPE_H */
