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
 *             File:  Rte_Gear_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Gear>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_GEAR_TYPE_H
# define RTE_GEAR_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_P_
#   define Cx0_P_ (0U)
#  endif

#  ifndef Cx1_R_
#   define Cx1_R_ (1U)
#  endif

#  ifndef Cx2_N_
#   define Cx2_N_ (2U)
#  endif

#  ifndef Cx3_D_
#   define Cx3_D_ (3U)
#  endif

#  ifndef Cx4_M_
#   define Cx4_M_ (4U)
#  endif

#  ifndef Cx5_Reserved_
#   define Cx5_Reserved_ (5U)
#  endif

#  ifndef Cx0_Blank_No_Display_
#   define Cx0_Blank_No_Display_ (0U)
#  endif

#  ifndef Cx1_On_
#   define Cx1_On_ (1U)
#  endif

#  ifndef Cx2_Flashing_
#   define Cx2_Flashing_ (2U)
#  endif

#  ifndef Cx3_Reserved_treat_as_Blank_No_Display_
#   define Cx3_Reserved_treat_as_Blank_No_Display_ (3U)
#  endif

#  ifndef Cx0_Gear_shiftdown_display_off_
#   define Cx0_Gear_shiftdown_display_off_ (0U)
#  endif

#  ifndef Cx1_Gear_shiftdown_display_on_
#   define Cx1_Gear_shiftdown_display_on_ (1U)
#  endif

#  ifndef Cx0_Gear_shiftup_display_off_
#   define Cx0_Gear_shiftup_display_off_ (0U)
#  endif

#  ifndef Cx1_Gear_shiftup_display_on_
#   define Cx1_Gear_shiftup_display_on_ (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_GEAR_TYPE_H */
