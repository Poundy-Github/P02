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
 *             File:  Rte_ADAS_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <ADAS>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ADAS_TYPE_H
# define RTE_ADAS_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define ACC_LeTargrtDection_adt_LowerLimit (0)
#  define ACC_LeTargrtDection_adt_UpperLimit (3U)

#  ifndef Cx0_Not_dectected_
#   define Cx0_Not_dectected_ (0U)
#  endif

#  ifndef Cx1_Dectected_
#   define Cx1_Dectected_ (1U)
#  endif

#  ifndef Cx2_Reserved_
#   define Cx2_Reserved_ (2U)
#  endif

#  ifndef Cx3_Invalid_
#   define Cx3_Invalid_ (3U)
#  endif

#  define ACC_LeTgtDx_adt_LowerLimit (0)
#  define ACC_LeTgtDx_adt_UpperLimit (301U)

#  ifndef Cx000_Valid_value_
#   define Cx000_Valid_value_ (0U)
#  endif

#  ifndef Cx12D_Reserved_
#   define Cx12D_Reserved_ (301U)
#  endif

#  define ACC_LeTgtDy_adt_LowerLimit (0)
#  define ACC_LeTgtDy_adt_UpperLimit (161U)

#  ifndef Cx00_Valid_value_
#   define Cx00_Valid_value_ (0U)
#  endif

#  ifndef CxA1_Reserved_
#   define CxA1_Reserved_ (161U)
#  endif

#  define ACC_LeTgtTyp_adt_LowerLimit (0)
#  define ACC_LeTgtTyp_adt_UpperLimit (7U)

#  ifndef Cx0_Unkown_
#   define Cx0_Unkown_ (0U)
#  endif

#  ifndef Cx1_Sedan_
#   define Cx1_Sedan_ (1U)
#  endif

#  ifndef Cx2_Truck_
#   define Cx2_Truck_ (2U)
#  endif

#  ifndef Cx3_Motorcycle_
#   define Cx3_Motorcycle_ (3U)
#  endif

#  ifndef Cx4_Pedestrian_
#   define Cx4_Pedestrian_ (4U)
#  endif

#  ifndef Cx5_Bicycle_
#   define Cx5_Bicycle_ (5U)
#  endif

#  ifndef Cx6_Reserved_
#   define Cx6_Reserved_ (6U)
#  endif

#  ifndef Cx7_Invalid_
#   define Cx7_Invalid_ (7U)
#  endif

#  define ACC_RiTargrtDetn_adt_LowerLimit (0)
#  define ACC_RiTargrtDetn_adt_UpperLimit (3U)

#  define ACC_RiTgtDx_adt_LowerLimit (0)
#  define ACC_RiTgtDx_adt_UpperLimit (301U)

#  define ACC_RiTgtDy_adt_LowerLimit (0)
#  define ACC_RiTgtDy_adt_UpperLimit (161U)

#  define ACC_RiTgtTyp_adt_LowerLimit (0)
#  define ACC_RiTgtTyp_adt_UpperLimit (7U)

#  define Checksum_ACC7_adt_LowerLimit (0)
#  define Checksum_ACC7_adt_UpperLimit (255U)

#  define RollingCounter_ACC7_adt_LowerLimit (0)
#  define RollingCounter_ACC7_adt_UpperLimit (15U)

#  ifndef Cx0_Valid_value_
#   define Cx0_Valid_value_ (0U)
#  endif

#  ifndef CxF_Invalid_value_
#   define CxF_Invalid_value_ (15U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ADAS_TYPE_H */
