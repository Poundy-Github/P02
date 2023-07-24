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
 *             File:  Rte_KeyReturn_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <KeyReturn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_KEYRETURN_TYPE_H
# define RTE_KEYRETURN_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Released
#   define Cx0_Released (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef Cx2_error
#   define Cx2_error (2U)
#  endif

#  ifndef Cx3_invalidation
#   define Cx3_invalidation (3U)
#  endif

#  ifndef UnKey
#   define UnKey (0U)
#  endif

#  ifndef AdjVolDwn
#   define AdjVolDwn (1U)
#  endif

#  ifndef AdjVolUp
#   define AdjVolUp (2U)
#  endif

#  ifndef Custom
#   define Custom (3U)
#  endif

#  ifndef CustomMmed
#   define CustomMmed (4U)
#  endif

#  ifndef Enter
#   define Enter (5U)
#  endif

#  ifndef EnterMmed
#   define EnterMmed (6U)
#  endif

#  ifndef Home
#   define Home (7U)
#  endif

#  ifndef MenuReturn
#   define MenuReturn (8U)
#  endif

#  ifndef Mute
#   define Mute (9U)
#  endif

#  ifndef PageDwn
#   define PageDwn (10U)
#  endif

#  ifndef PageL
#   define PageL (11U)
#  endif

#  ifndef PageR
#   define PageR (12U)
#  endif

#  ifndef PageUp
#   define PageUp (13U)
#  endif

#  ifndef SeekDwn
#   define SeekDwn (14U)
#  endif

#  ifndef SeekUp
#   define SeekUp (15U)
#  endif

#  ifndef VR
#   define VR (16U)
#  endif

#  ifndef Cx2_Error
#   define Cx2_Error (2U)
#  endif

#  ifndef Cx3_invalid
#   define Cx3_invalid (3U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_KEYRETURN_TYPE_H */
