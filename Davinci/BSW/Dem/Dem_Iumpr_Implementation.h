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
 *  \file       Dem_Iumpr_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    Implementation of the Obd Iumpr subcomponent which manages calculation of the IUMPR ratios.
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

#if !defined (DEM_IUMPR_IMPLEMENTATION_H)
#define DEM_IUMPR_IMPLEMENTATION_H

 /* ********************************************************************************************************************
 *  GLOBAL MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 2880 EOF */ /* MD_DEM_2.1_UNREACHABLE_STATEMENT */
/* PRQA S 2982 EOF */ /* MD_DEM_2982 */
/* PRQA S 2983 EOF */ /* MD_DEM_2983 */
/* PRQA S 2985 EOF */ /* MD_DEM_2985 */
/* PRQA S 2986 EOF */ /* MD_DEM_2986 */
/* PRQA S 2987 EOF */ /* MD_DEM_2987 */
/* PRQA S 2991 EOF */ /* MD_DEM_2991 */
/* PRQA S 2992 EOF */ /* MD_DEM_2992 */
/* PRQA S 2995 EOF */ /* MD_DEM_2995 */
/* PRQA S 2996 EOF */ /* MD_DEM_2996 */
/* PRQA S 3415 EOF */ /* MD_DEM_13.5_cf */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Iumpr_Interface.h"

/* ------------------------------------------------------------------------- */
#include "Dem_Ratio_Implementation.h"
#include "Dem_Denominator_Implementation.h"
#include "Dem_FimFid_Implementation.h"
#include "Dem_Cfg_Definitions.h"
#include "Dem_Mem_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_InitState_Implementation.h"
#include "Dem_Memory_Interface.h"
#include "Dem_DTC_Interface.h"
#include "Dem_ClientAccess_Interface.h"
#include "Dem_Event_Interface.h"
#include "Dem_Nvm_Interface.h"
#include "Dem_Scheduler_Interface.h"

/* ********************************************************************************************************************
 *  FILE SPECIFIC MISRA VIOLATIONS
 *********************************************************************************************************************/
/* PRQA S 3406 DEM_IUMPR_IMPL */ /* MD_DEM_8.6 */

/* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */


/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_IUMPR_IMPLEMENTATION_FILENAME "Dem_Iumpr_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/

#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Filter data for IUMPR readout */
DEM_LOCAL VAR(Dem_IumprFilter_InfoType, DEM_VAR_NOINIT)  Dem_Iumpr_FilterInfo;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE PROPERTIES DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Iumpr_PrivateProperties Private Properties
 * \{
 */
 /* ****************************************************************************
 * Dem_Iumpr_RatioIter_Exists
 *****************************************************************************/
 /*!
 * \brief         Test if the iterator points to a valid element
 *
 * \details       Test if the iterator points to a valid element
 *
 * \param[in]     IterPtr
 *                Pointer to the iterator
 *
 * \return        TRUE
 *                Dem_Iumpr_RatioIter_GetIdx() will return a valid element
 *                on this iterator
 * \return        FALSE
 *                Dem_Iumpr_RatioIter_GetIdx() is undefined on this iterator
 *
 * \pre           IterPtr has been initialized
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_RatioIter_Exists(
  CONSTP2CONST(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
);

/* ****************************************************************************
 * Dem_Iumpr_RatioIter_GetIdx
 *****************************************************************************/
/*!
 * \brief         Get the element pointed to by the iterator
 *
 * \details       Get the element pointed to by the iterator
 *
 * \param[in]     IterPtr
 *                Pointer to the iterator
 *
 * \return        Unique handle of the Ratio
 *
 * \pre           IterPtr has been initialized
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Dem_RatioIdIndexType, DEM_CODE)
Dem_Iumpr_RatioIter_GetIdx(
  CONSTP2CONST(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
);

/* ****************************************************************************
 * Dem_Iumpr_RatioIter_Init
 *****************************************************************************/
/*!
 * \brief         Init the iterator
 *
 * \details       Initializes the iterator to enumerate all configured ratios
 *
 * \param[out]    IterPtr
 *                Pointer to the iterator
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RatioIter_Init(
  CONSTP2VAR(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
);

/* ****************************************************************************
 * Dem_Iumpr_RatioIter_Next
 *****************************************************************************/
/*!
 * \brief         Move the iterator to the next element
 *
 * \details       Move the iterator to the next element
 *
 * \param[in,out] IterPtr
 *                Pointer to the iterator
 *
 * \pre           IterPtr has been initialized
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RatioIter_Next(
  CONSTP2VAR(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
);

/* ****************************************************************************
 * Dem_Iumpr_IsHybridCycleCounterEnabled
 *****************************************************************************/
/*!
 * \brief         Returns true if IUMPR Hybrid Cycle Counter feature set is enabled.
 * \details       -
 *
 * \return        TRUE
 *                Support for IUMPR Hybrid Cycle Counter
 * \return        FALSE
 *                No support for IUMPR Hybrid Cycle Counter
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsHybridCycleCounterEnabled(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_TestHybridCounterIncremented
 *****************************************************************************/
/*!
 * \brief         Test hybrid ignition cycle counter incremented state in 
 *                global hybrid ignition cycle state
 *
 * \details       -
 *
 *
 * \return        TRUE
 *                Hybrid ignition cyclce counter was incremented
 * \return        FALSE
 *                Hybrid ignition cyclce counter was not incremented
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_CycleCounter_TestHybridCounterIncremented(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_SetHybridCounterIncremented
 *****************************************************************************/
/*!
 * \brief         Set hybrid ignition cycle counter incremented state in
 *                global hybrid ignition cycle state
 *
 * \details       -
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_SetHybridCounterIncremented(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_ResetIncrementedHybridCycleCounter
 *****************************************************************************/
/*!
 * \brief         Reset hybrid ignition cycle counter incremented state in 
 *                global hybrid ignition cycle state
 *
 * \details       -
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetIncrementedHybridCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_IncrementHybridCycleCounter
 *****************************************************************************/
/*!
 * \brief         Increment hybrid ignition cycle counter
 *
 * \details       Increment hybrid ignition cycle counter
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_IncrementHybridCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_ResetHybridCycleCounter
 *****************************************************************************/
/*!
 * \brief         Reset hybrid ignition cycle counter
 *
 * \details       Reset hybrid ignition cycle counter

 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetHybridCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_IncrementIgnitionCycleCounter
 *****************************************************************************/
/*!
 * \brief         Increment ignition cycle counter
 *
 * \details       Increment ignition cycle counter
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_IncrementIgnitionCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_ResetIgnitionCycleCounter
 *****************************************************************************/
/*!
 * \brief         Reset ignition cycle counter
 *
 * \details       Reset ignition cycle counter
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetIgnitionCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_GetIgnitionCycleCounter
 *****************************************************************************/
/*!
 * \brief         Get ignition cycle counter
 *
 * \details       Get ignition cycle counter
 *
 * \return        Value of the ignition cycle counter
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetIgnitionCycleCounter(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_GetHybridCycleCounter
 *****************************************************************************/
/*!
 * \brief         Get hybrid ignition cycle counter value
 *
 * \details       Get hybrid ignition cycle counter value
 *
 * \return        Value of the hybrid ignition cycle counter
 *
 * \pre           Feature IUMPR and hybrid ingnition cycle is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetHybridCycleCounter(void);


/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_GetValue
 *****************************************************************************/
/*!
 * \brief         Get the general denominator counter
 *
 * \details       Get the general denominator counter
 *
 * \return        The value of the general denominator counter
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_OBDDenominator_GetValue(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_SetValue
 *****************************************************************************/
/*!
 * \brief         Set the general denominator counter
 *
 * \details       Set the general denominator counter
 *
 * \param[in]     Value
 *                The new counter value
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different RatioIdx
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetValue(
  CONST(uint16, AUTOMATIC) Value
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_SetIncremented
 *****************************************************************************/
/*!
 * \brief         Set general OBD denominator incremented state
 *
 * \details       Set general OBD denominator incremented state
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetIncremented(void);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_ResetIncremented
 *****************************************************************************/
/*!
 * \brief         Reset general OBD denominator incremented state
 *
 * \details       -
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_ResetIncremented(void);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_TestIncremented
 *****************************************************************************/
/*!
 * \brief         Test general OBD denominator incremented state
 *
 * \details       Test general OBD denominator incremented state
 *
 * \return        TRUE
 *                General OBD denominator is currently incremented
 * \return        FALSE
 *                General OBD denominator is currently not incremented
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_OBDDenominator_TestIncremented(void);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_SetInhibited
 *****************************************************************************/
/*!
 * \brief         Set general OBD denominator conditions inhibited state
 *
 * \details       Set general OBD denominator conditions inhibited state
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetInhibited(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_ResetInhibited
 *****************************************************************************/
/*!
 * \brief         Reset general OBD denominator conditions inhibited state
 *
 * \details       -
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_ResetInhibited(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_TestInhibited
 *****************************************************************************/
/*!
 * \brief         Test general OBD denominator conditions inhibited state
 *
 * \details       Test general OBD denominator conditions inhibited state
 *
 * \return        TRUE
 *                General OBD denominator is currently inhibited
 * \return        FALSE
 *                General OBD denominator is currently uninhibited
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_OBDDenominator_TestInhibited(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_TestReached
 *****************************************************************************/
/*!
 * \brief         Test conditions reached state
 *
 * \details       Test conditions reached state
 *
 * \param[in]     ConditionId
 *
 * \return        TRUE
 *                Condition is currently reached
 * \return        FALSE
 *                Condition is currently not-reached
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_ConditionStatus_TestReached(
  Dem_IumprDenomCondIdType ConditionId
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_SetReached
 *****************************************************************************/
/*!
 * \brief         Set general individual denominator conditions reached state
 *
 * \details       Set general individual denominator conditions reached state
 *
 * \param[in]     ConditionId
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_SetReached(
  Dem_IumprDenomCondIdType ConditionId
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_ResetReached
 *****************************************************************************/
/*!
 * \brief         Reset conditions reached state
 *
 * \details       Reset conditions reached state
 *
 * \param[in]     ConditionId
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_ResetReached(
  Dem_IumprDenomCondIdType ConditionId
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_TestInhibited
 *****************************************************************************/
/*!
 * \brief         Test conditions inhibited state
 *
 * \details       Test conditions inhibited state
 *
 * \param[in]     ConditionId
 *
 * \return        TRUE
 *                Denominator condition is currently inhibited
 * \return        FALSE
 *                Denominator condition is currently uninhibited
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_ConditionStatus_TestInhibited(
  Dem_IumprDenomCondIdType ConditionId
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_SetInhibited
 *****************************************************************************/
/*!
 * \brief         Set conditions inhibited state
 *
 * \details       Set conditions inhibited state
 *
 * \param[in]     ConditionId
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_SetInhibited(
  Dem_IumprDenomCondIdType ConditionId
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_ResetInhibited
 *****************************************************************************/
/*!
 * \brief         Reset conditions inhibited state
 *
 * \details       Reset conditions inhibited state
 *
 * \param[in]     ConditionId
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_ResetInhibited(
  Dem_IumprDenomCondIdType ConditionId
);

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

 /* ****************************************************************************
 % Dem_Iumpr_RatioIter_Exists
 *****************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_RatioIter_Exists(
  CONSTP2CONST(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
)
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(IterPtr)                                                                                      /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    return (boolean)(*IterPtr < Dem_Cfg_GetSizeOfRatioIdTable());
#else
    return FALSE;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_RatioIter_GetIdx
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_RatioIdIndexType, DEM_CODE)
Dem_Iumpr_RatioIter_GetIdx(
  CONSTP2CONST(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
)
{
  return (Dem_RatioIdIndexType)*IterPtr;
}

/* ****************************************************************************
 % Dem_Iumpr_RatioIter_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RatioIter_Init(
  CONSTP2VAR(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
)
{
  *IterPtr = 0u;                                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
}

/* ****************************************************************************
 % Dem_Iumpr_RatioIter_Next
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RatioIter_Next(
  CONSTP2VAR(Dem_Cfg_ObdRatioIdIterType, AUTOMATIC, AUTOMATIC)  IterPtr
)
{
  *IterPtr += 1u;                                                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_TestReached
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_ConditionStatus_TestReached(
  Dem_IumprDenomCondIdType ConditionId
)
{
  boolean lReturnValue = FALSE;
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    lReturnValue = ((Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus & DEM_RATIO_GENDEN_CONDITIONS_REACHED) != 0u);
#endif
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_SetReached
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_SetReached(
  Dem_IumprDenomCondIdType ConditionId
)
{
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus | DEM_RATIO_GENDEN_CONDITIONS_REACHED));
#endif
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_ResetReached
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_ResetReached(
  Dem_IumprDenomCondIdType ConditionId
)
{
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus& DEM_RATIO_GENDEN_CONDITIONS_REACHED_MASK));
#endif
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_TestInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_ConditionStatus_TestInhibited(
  Dem_IumprDenomCondIdType ConditionId
)
{
  boolean lReturnValue = FALSE;
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    lReturnValue = ((Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus & DEM_RATIO_GENDEN_CONDITIONS_INHIBITED) != 0u);
#endif
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_SetInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_SetInhibited(
  Dem_IumprDenomCondIdType ConditionId
)
{
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus | DEM_RATIO_GENDEN_CONDITIONS_INHIBITED));
#endif
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_ResetInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_ResetInhibited(
  Dem_IumprDenomCondIdType ConditionId
)
{
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
    Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralIndDenominatorStatus & DEM_RATIO_GENDEN_CONDITIONS_INHIBITED_MASK));
#endif
  }
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_SetValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetValue(
CONST(uint16, AUTOMATIC) Value
)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GeneralDenominator = Value;
#else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(Value)                                                                                        /* PRQA S 3112 */ /* MD_DEM_14.2 */
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_GetValue
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_OBDDenominator_GetValue(
  void
)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return (uint16)(Dem_Cfg_ObdIumprData.GeneralDenominator);
#else
  return (uint16)0;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_SetIncremented
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetIncremented(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus | DEM_RATIO_GENDEN_INCREMENTED));
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_ResetIncremented
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_ResetIncremented(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus & DEM_RATIO_GENDEN_INCREMENTED_MASK));
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_TestIncremented
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_OBDDenominator_TestIncremented(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return ((Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus& DEM_RATIO_GENDEN_INCREMENTED) != 0u);
#else
  return FALSE;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_SetInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_SetInhibited(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus | DEM_RATIO_GENDEN_CONDITIONS_INC_INHIBITED));
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_ResetInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_ResetInhibited(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus = ((uint8)(Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus & DEM_RATIO_GENDEN_CONDITIONS_INC_INHIBITED_MASK));
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_TestInhibited
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_OBDDenominator_TestInhibited(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return ((Dem_Cfg_ObdIumprData.GeneralOBDDenominatorStatus & DEM_RATIO_GENDEN_CONDITIONS_INC_INHIBITED) != 0u);
#else
  return FALSE;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_IsHybridCycleCounterEnabled()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsHybridCycleCounterEnabled(void)
{
  return (boolean)(DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID == STD_ON);
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_ResetHybridCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetHybridCycleCounter(void)                                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID)
  Dem_Cfg_AdminData.IgnitionCycleHybridCounter = 0u;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_TestHybridCounterIncremented
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_CycleCounter_TestHybridCounterIncremented(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return (((Dem_Cfg_ObdIumprData.GlobalHybridStatus)& DEM_IUMPR_IGN_CYC_HYBRID_INCREMENTED) != 0u);
#else
  return FALSE;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_SetHybridCounterIncremented
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_SetHybridCounterIncremented(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GlobalHybridStatus = ((Dem_Cfg_ObdIumprData.GlobalHybridStatus) | DEM_IUMPR_IGN_CYC_HYBRID_INCREMENTED);
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_ResetIncrementedHybridCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetIncrementedHybridCycleCounter(void)                                                                                    /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_ObdIumprData.GlobalHybridStatus = ((Dem_Cfg_ObdIumprData.GlobalHybridStatus)& DEM_IUMPR_IGN_CYC_HYBRID_INCREMENTED_MASK);
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_IncrementHybridCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_IncrementHybridCycleCounter(void)
{
  /* Overflow handling is done with an reset to 0, which is the expected c behaviour  */
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID)
  Dem_Cfg_AdminData.IgnitionCycleHybridCounter = Dem_Cfg_AdminData.IgnitionCycleHybridCounter + 1u;
#endif
  Dem_Iumpr_CycleCounter_SetHybridCounterIncremented();
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_IncrementIgnitionCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_IncrementIgnitionCycleCounter(void)
{
  /* Overflow handling is done with an reset to 0, which is the expected c behaviour  */
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_AdminData.IgnitionCycleCounter = Dem_Cfg_AdminData.IgnitionCycleCounter + 1u;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_ResetIgnitionCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_ResetIgnitionCycleCounter(void)                                                                                                     /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  Dem_Cfg_AdminData.IgnitionCycleCounter = 0u;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_GetHybridCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetHybridCycleCounter(void)                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON) && (DEM_CFG_SUPPORT_CYCLE_IGNITION_HYBRID)
  return Dem_Cfg_AdminData.IgnitionCycleHybridCounter;
#else
  return 0;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_GetIgnitionCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetIgnitionCycleCounter(void)
{
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return Dem_Cfg_AdminData.IgnitionCycleCounter;
#else
  return 0;
#endif
}
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT PUBLIC PROPERTIES DEFINITIONS
 *********************************************************************************************************************/

#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Iumpr_PublicProperties
 * \{
 */

/* ****************************************************************************
 % Dem_Iumpr_IsEnabled()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsEnabled(void)
{
  return (boolean)(DEM_CFG_SUPPORT_IUMPR == STD_ON);
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Iumpr_Private Private Methods
 * \{
 */

/* ****************************************************************************
 * Dem_Iumpr_SetRatioDenCondition
 *****************************************************************************/
/*!
 * \brief         Report denominator condition to all monitor specific denominators.
 *
 * \details       Report denominator condition to all monitor specific denominators.
 *
 * \param[in]     ConditionId
 *                The denominator group for which the conditions are reported.
 * \param[in]     ConditionStatus
 *                The new status of the given ConditionId
 *
 *
 * \pre           RTE is active (if RTE is used)
 * \config        Feature IUMPR is supported
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_SetRatioDenCondition(
CONST(Dem_IumprDenomCondIdType, AUTOMATIC) ConditionId,
CONST(Dem_IumprDenomCondStatusType, AUTOMATIC) ConditionStatus
);

/* ****************************************************************************
 * Dem_Iumpr_SetOBDDenominatorCondition()
 *****************************************************************************/
/*!
 * \brief         Set general OBD condition reached, not-reached, or inhibited.
 *
 * \details       Set general OBD condition status.
 *                If reported reached: Increment general denominator,
 *                if it has not been incremented in the current operation cycle.
 *                If reported inhibited: Set the general denominator increase to
 *                inhibited, for the current operationc cycle.
 *
 *
 * \param[in]     ConditionStatus
 *                The new status of the general OBD condition
 *
 * \return        E_OK
 *                Condition status was accepted
 * \return        E_NOT_OK
 *                Condition status is rejected, since general denominator
 *                increase is inhibited.
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetOBDDenominatorCondition(
Dem_IumprDenomCondStatusType ConditionStatus
);


/* ****************************************************************************
 * Dem_Iumpr_SetRatioDenominatorCondition()
 *****************************************************************************/
/*!
 * \brief         Set denominator conditions reached, not-reached or inhibited.
 *
 * \details       Set denominator conditions reached, not-reached or inhibited.
 *                Only the general denomniator can be inhibited.
 *
 * \param[in]     DenominatorGroup
 *                Unique handle of denominator group
 * \param[in]     ConditionStatus
 *                The new status of the given ConditionId
 *
 * \return        E_OK
 *                Condition status was accepted
 * \return        E_NOT_OK
 *                Condition status is rejected, since general denominator
 *                increase is inhibited.
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetRatioDenominatorCondition(
Dem_IumprDenomCondIdType ConditionId,
Dem_IumprDenomCondStatusType ConditionStatus
);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_InitStatus()
 *****************************************************************************/
/*!
 * \brief        Initialize global hybrid ignition cycle status 
 *
 * \details       -
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_InitStatus(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_InitMemory
 *****************************************************************************/
/*!
 * \brief         Initialize ignition cycle counters
 *
 * \details       Initialize ignition cycle counter and hybrid cycle counter
 *
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_InitMemory(void);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_GetValue()
 *****************************************************************************/
/*!
 * \brief        Retrieve value of cycle counter
 *
 * \details       -
 *
 * \param[in]     CycleCounter
 *                Ignition Cycle Counter or Ignition Hybrid Cycle Counter
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetValue(
  Dem_Iumpr_CycleCounter_CycleCounterType CycleCounter
);

/* ****************************************************************************
 * Dem_Iumpr_CycleCounter_Increment()
 *****************************************************************************/
/*!
 * \brief         Increment value of cycle counter
 *
 * \details       -
 *
 * \param[in]     CycleCounter
 *                Ignition Cycle Counter or Ignition Hybrid Cycle Counter
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_Increment(
  Dem_Iumpr_CycleCounter_CycleCounterType CycleCounter
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_InitStatus()
 *****************************************************************************/
/*!
 * \brief         Initialize global OBD denominator cycle status
 *
 * \details       -
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     TRUE for different ConditionIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_InitStatus(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_InitNv
 *****************************************************************************/
/*!
 * \brief         Initalize general OBD denominator
 *
 * \details       Initalize general OBD denominator
 *
 *
 * \pre           Feature IUMPR is supported
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_InitNv(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_Increment
 *****************************************************************************/
/*!
 * \brief         Increment the general denominator counter
 *
 * \details       Increment the general denominator counter
 *
 * \param[out]    UpdateNvM
 *                TRUE: Counter value has changed
 *                FALSE: Counter value has not changed
 * \return        E_OK
 *                Incrementing is not inhibited
 * \return        E_NOT_OK
 *                Incrementing is inhibited
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_OBDDenominator_Increment(
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC)  UpdateNvM
);

/* ****************************************************************************
 * Dem_Iumpr_OBDDenominator_Inhibit
 *****************************************************************************/
/*!
 * \brief         Set the general OBD denominator to inhibited
 *
 * \details       Set the general OBD denominator to inhibited
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_Inhibit(
  void
);

/* ****************************************************************************
 * Dem_Iumpr_ConditionStatus_InitStatus()
 *****************************************************************************/
/*!
 * \brief         Initialize condition status
 *
 * \details       Initialize condition status
 *
 * \param[in]     ConditionId
 *
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_InitStatus(
  Dem_IumprDenomCondIdType ConditionId
);


/* ****************************************************************************
 * Dem_Iumpr_SetGeneralIndividualConditionStatus()
 *****************************************************************************/
/*!
 * \brief         Set general individual denominator conditions reached, 
 *                not reached or inhibited.
 *
 * \details       -
 *
 * \param[in]     ConditionStatus
 *                The new status for the general individual denominator
 *
 * \pre           -
 *
 * \context       TASK|ISR2
 * \synchronous   FALSE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_SetGeneralIndividualConditionStatus(
  Dem_IumprDenomCondStatusType ConditionStatus
);


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/                                                                                                                               /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Iumpr_SetRatioDenCondition()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE  FUNC(void, DEM_CODE)
Dem_Iumpr_SetRatioDenCondition(
CONST(Dem_IumprDenomCondIdType, AUTOMATIC) ConditionId,
CONST(Dem_IumprDenomCondStatusType, AUTOMATIC) ConditionStatus
  )
{
  /* Conditions for a denominator group have been changed and general denominator conditions are not inhibited */
  Dem_Cfg_ObdRatioIdIterType lRatioIter;
  boolean lUpdateNvM;

  lUpdateNvM = FALSE;
  /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();

  for (Dem_Iumpr_RatioIter_Init(&lRatioIter);                                                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Iumpr_RatioIter_Exists(&lRatioIter) == TRUE;                                                                                   /* PRQA S 2994 */ /* MD_DEM_2994 */ /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_Iumpr_RatioIter_Next(&lRatioIter))                                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_RatioIdIndexType lRatioIndex;
    boolean lUpdateRatio;

    lRatioIndex = Dem_Iumpr_RatioIter_GetIdx(&lRatioIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */

    /* update ratio specific denominator condition flag for all ratios  */
    switch (ConditionStatus)
    {
      case DEM_IUMPR_DEN_STATUS_REACHED:
      {
        lUpdateRatio = Dem_Iumpr_Ratio_Denominator_Reach(lRatioIndex, ConditionId);
        break;
      }
      default:
      {
        lUpdateRatio = Dem_Iumpr_Ratio_Denominator_NotReach(lRatioIndex, ConditionId);
        break;
      }
    }

    if (lUpdateRatio == TRUE)
    {
      Dem_Iumpr_Ratio_QueueUpdate(lRatioIndex, TRUE);
      lUpdateNvM = TRUE;
    }
  }
  Dem_LeaveCritical_DiagMonitor();
  /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

  if (lUpdateNvM == TRUE)
  {
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR), DEM_NVM_BLOCKSTATE_DIRTY);
    Dem_Scheduler_EnableTaskOnce(Dem_Scheduler_Task_IUMPR);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Iumpr_SetOBDDenominatorCondition()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetOBDDenominatorCondition(
Dem_IumprDenomCondStatusType ConditionStatus
)
{
  Std_ReturnType lReturnValue;
  boolean lUpdateNvM;

  lReturnValue = E_OK;
  lUpdateNvM = FALSE;

  switch (ConditionStatus)
  {
  case DEM_IUMPR_DEN_STATUS_REACHED:
    lReturnValue = Dem_Iumpr_OBDDenominator_Increment(&lUpdateNvM);                                                              /* SBSW_DEM_POINTER_FORWARD_STACK */
    break;

  case DEM_IUMPR_DEN_STATUS_INHIBITED:
    Dem_Iumpr_OBDDenominator_Inhibit();
    lUpdateNvM = TRUE;
    break;

  case DEM_IUMPR_DEN_STATUS_NOT_REACHED:
    if (Dem_Iumpr_OBDDenominator_TestInhibited() == TRUE)
    {
      lReturnValue = E_NOT_OK;
    }
    break;

  default:                                                                                                                       /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    /* MISRA Case */
    break;
  }

  if (lUpdateNvM == TRUE)
  {
    /* update NvM */
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR), DEM_NVM_BLOCKSTATE_DIRTY);
  }
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */



/* ****************************************************************************
 % Dem_Iumpr_SetRatioDenominatorCondition()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetRatioDenominatorCondition(
Dem_IumprDenomCondIdType ConditionId,                                                                                            /* PRQA S 1330 */ /* MD_DEM_8.3_rte */
Dem_IumprDenomCondStatusType ConditionStatus
)
{
  Std_ReturnType lReturnValue;

  /* --- Set Denominator Reached --- */
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
    /* --- General Individual Denominator Handling --- */
    Dem_Iumpr_SetGeneralIndividualConditionStatus(ConditionStatus);
  }

  if (
    (ConditionId < DEM_DENOMINATOR_COND_INVALID)
    && (Dem_Iumpr_ConditionStatus_TestInhibited(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR) == FALSE)                                                          /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    )
  {
    /* Set Condition status for each ratio */
    Dem_Iumpr_SetRatioDenCondition(ConditionId, ConditionStatus);
    lReturnValue = E_OK;
  }
  else if ((ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
    && (ConditionStatus == DEM_IUMPR_DEN_STATUS_INHIBITED))
  {
    lReturnValue = E_OK;
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_GetValue()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Iumpr_CycleCounter_GetValue(Dem_Iumpr_CycleCounter_CycleCounterType CycleCounter)                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
  uint16 lCycleCounterValue;
  lCycleCounterValue = 0;
  switch (CycleCounter)
  {
  case Dem_Iumpr_CycleCounter_IgnitionCycleCounter:
    lCycleCounterValue = Dem_Iumpr_CycleCounter_GetIgnitionCycleCounter();
    break;
  case Dem_Iumpr_CycleCounter_IgnitionHybridCycleCounter:
    lCycleCounterValue = Dem_Iumpr_CycleCounter_GetHybridCycleCounter();
    break;
  default:
    /* No valid cycle counter type */
    break;
  }
  return lCycleCounterValue;
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_Increment()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_Increment(Dem_Iumpr_CycleCounter_CycleCounterType CycleCounter)                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{

  switch (CycleCounter)
  {
  case Dem_Iumpr_CycleCounter_IgnitionCycleCounter:
    Dem_Iumpr_CycleCounter_IncrementIgnitionCycleCounter();
    break;
  case Dem_Iumpr_CycleCounter_IgnitionHybridCycleCounter:
    Dem_Iumpr_CycleCounter_IncrementHybridCycleCounter();
    break;
  default:
    /* No valid cycle counter type */
    break;
  }
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_InitStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_InitStatus(void)                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
  Dem_Iumpr_CycleCounter_ResetIncrementedHybridCycleCounter();
}

/* ****************************************************************************
 % Dem_Iumpr_CycleCounter_InitMemory
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_CycleCounter_InitMemory(void)                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_Iumpr_CycleCounter_ResetIgnitionCycleCounter();

    if (Dem_Iumpr_IsHybridCycleCounterEnabled() == TRUE)
    {
      Dem_Iumpr_CycleCounter_ResetHybridCycleCounter();
    }
  }
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_InitStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_InitStatus(void)                                                                                            /* PRQA S 3219 */ /* MD_DEM_14.1_ACCESSOR */
{
  Dem_Iumpr_OBDDenominator_ResetIncremented();
  Dem_Iumpr_OBDDenominator_ResetInhibited();
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_InitNv
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_InitNv(
  void
)
{
  Dem_Iumpr_OBDDenominator_SetValue(0);
  Dem_Iumpr_OBDDenominator_InitStatus();
}

/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_Increment
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_OBDDenominator_Increment(
  CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC)  UpdateNvM
)
{
  Std_ReturnType lReturnValue = E_OK;
  if (Dem_Iumpr_OBDDenominator_TestInhibited() == FALSE)
  {
    if (Dem_Iumpr_OBDDenominator_TestIncremented() == FALSE)
    {
      /* general conditions fulfilled and denominator not yet incremented in this DCY */
      Dem_Iumpr_OBDDenominator_SetIncremented();
      *UpdateNvM = TRUE;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

      /* --> no overrun handling; value shall rollover and increment to zero  [CCR1968.2 (g)(5.2.1)(E)] */
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
      Dem_Iumpr_OBDDenominator_SetValue(Dem_Iumpr_OBDDenominator_GetValue() + 1u);
#endif
    }
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }
  return lReturnValue;
}


/* ****************************************************************************
 % Dem_Iumpr_OBDDenominator_Inhibit
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OBDDenominator_Inhibit(void)
{
  Dem_Iumpr_OBDDenominator_SetInhibited();
  /* set incremented flag to prevent, that general denominator is incremented in this DCY */
  Dem_Iumpr_OBDDenominator_SetIncremented();
}

/* ****************************************************************************
 % Dem_Iumpr_SetGeneralIndividualConditionStatus()
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_SetGeneralIndividualConditionStatus(
  Dem_IumprDenomCondStatusType ConditionStatus
)
{
  boolean lUpdataNvm;

  lUpdataNvm = FALSE;
  if (Dem_Iumpr_ConditionStatus_TestInhibited(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR) == FALSE)
  {
    switch (ConditionStatus)
    {
    case DEM_IUMPR_DEN_STATUS_REACHED:
    {
      Dem_Iumpr_ConditionStatus_SetReached(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
      lUpdataNvm = TRUE;
      break;
    }
    case DEM_IUMPR_DEN_STATUS_NOT_REACHED:
    {
      /* general conditions not fulfilled */
      Dem_Iumpr_ConditionStatus_ResetReached(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
      lUpdataNvm = TRUE;
      break;
    }
    case DEM_IUMPR_DEN_STATUS_INHIBITED:
    {
      Dem_Iumpr_ConditionStatus_SetInhibited(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
      lUpdataNvm = TRUE;
      break;
    }
    default:                                                                                                                     /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    {
      /* MISRA Case */
      break;
    }
    }
  }
  if (lUpdataNvm == TRUE)
  {
    /* update NvM */
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR), DEM_NVM_BLOCKSTATE_DIRTY);
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ConditionStatus_InitStatus
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ConditionStatus_InitStatus(
  Dem_IumprDenomCondIdType ConditionId
)
{
  if (ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR)
  {
    Dem_Iumpr_ConditionStatus_ResetReached(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
    Dem_Iumpr_ConditionStatus_ResetInhibited(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
  }
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Iumpr_Public
 * \{
 */

/* ****************************************************************************
 % Dem_Iumpr_InitNv
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitNv(
 void
)
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_Cfg_ObdRatioIdIterType     lRatioIter;

    /* ----- Implementation ------------------------------------------------ */
    /* initialize general data */

    Dem_Iumpr_OBDDenominator_InitNv();
    Dem_Iumpr_ConditionStatus_InitStatus(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);
    Dem_Iumpr_Ratio_Numerator_ReleaseLock();
    Dem_Iumpr_CycleCounter_InitStatus();

    /* initialize all ratios */
    for (Dem_Iumpr_RatioIter_Init(&lRatioIter);                                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Iumpr_RatioIter_Exists(&lRatioIter) == TRUE;                                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Iumpr_RatioIter_Next(&lRatioIter))                                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      Dem_Iumpr_Ratio_InitNv(Dem_Iumpr_RatioIter_GetIdx(&lRatioIter));                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
    }
  }
}                                                                                                                                      /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Iumpr_GetGeneralIumprData
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_GetGeneralIumprData(
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  GeneralDenominator,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  IgnitionCycles,
  P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  IgnitionCyclesHybrid
)
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    *GeneralDenominator = Dem_Iumpr_OBDDenominator_GetValue();                                                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *IgnitionCycles = Dem_Iumpr_CycleCounter_GetValue(Dem_Iumpr_CycleCounter_IgnitionCycleCounter);                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *IgnitionCyclesHybrid = Dem_Iumpr_CycleCounter_GetValue(Dem_Iumpr_CycleCounter_IgnitionHybridCycleCounter);                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}

/* ****************************************************************************
 % Dem_Iumpr_SetDenominatorCondition
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_SetDenominatorCondition(
Dem_IumprDenomCondIdType ConditionId,                                                                                            /* PRQA S 1330 */ /* MD_DEM_8.3_rte */
Dem_IumprDenomCondStatusType ConditionStatus
)
{
  Std_ReturnType lReturnValue;

  /* ----- Implementation ------------------------------------------------ */
  if (ConditionId == DEM_IUMPR_GENERAL_DENOMINATOR)
  {
    Std_ReturnType lOBDCONDReturnValue;
    Std_ReturnType lDenominatorReturnValue;
    /* --- General OBD Denominator Forwarding --- */
    lOBDCONDReturnValue = Dem_Iumpr_SetOBDDenominatorCondition(ConditionStatus);
    /* --- General Individual Denominator Forwarding --- */
    lDenominatorReturnValue = Dem_Iumpr_SetRatioDenominatorCondition(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR, ConditionStatus);
      

    if ((lOBDCONDReturnValue == E_OK) && (lDenominatorReturnValue == E_OK))
    {
      lReturnValue = E_OK;
    }
    else
    {
      lReturnValue = E_NOT_OK;
    }
  }
  else if (ConditionId == DEM_IUMPR_GENERAL_OBDCOND)
  {
    /* --- General OBD Condition Handling --- */
    lReturnValue = Dem_Iumpr_SetOBDDenominatorCondition(ConditionStatus);
  }
  else if ((ConditionId == DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR) || (ConditionStatus != DEM_IUMPR_DEN_STATUS_INHIBITED))
  {
    /* --- Monitor Specific Denominator and General Individual Denominator Handling --- */
    lReturnValue = Dem_Iumpr_SetRatioDenominatorCondition(ConditionId, ConditionStatus);
  }
  else
  {
    /* ConditionId != GENERAL and ConditionStatus == INHIBITED */
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Iumpr_ResetPendingFids
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ResetPendingFids(void)                                                                                                 /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_Cfg_ObdRatioIdIterType lRatioIter;
    uint8 lLeaveCSCounter;

    lLeaveCSCounter = 0u;
    /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
    Dem_EnterCritical_DiagMonitor();

    for (Dem_Iumpr_RatioIter_Init(&lRatioIter);                                                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Iumpr_RatioIter_Exists(&lRatioIter) == TRUE;                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_Iumpr_RatioIter_Next(&lRatioIter))                                                                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      Dem_Iumpr_Ratio_ResetFidPending(Dem_Iumpr_RatioIter_GetIdx(&lRatioIter));                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */

      ++lLeaveCSCounter;
      if (lLeaveCSCounter >= DEM_IUMPR_RESET_PENDING_RATIO)
      {
        Dem_LeaveCritical_DiagMonitor();
        lLeaveCSCounter = 0u;
        Dem_EnterCritical_DiagMonitor();
      }
    }

    Dem_LeaveCritical_DiagMonitor();
    /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR),
      DEM_NVM_BLOCKSTATE_DIRTYCLEAREDIMMEDIATE);
  }
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* ****************************************************************************
 % Dem_Iumpr_RestartDcy
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_RestartDcy(void)                                                                                                       /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    /* reset general individual denominator and general OBD denominator status bits to the following setting:
    * - general denominator not incremented
    * - general conditions not fulfilled
    * - general conditions not inhibited
    * - general denominator increase not inhibited
    */
    Dem_Iumpr_ConditionStatus_InitStatus(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR);

    Dem_Iumpr_OBDDenominator_InitStatus();

    /* reset hybrid status to the following setting:
    * - hybrid ignition cycle counter not incremented
    */
    Dem_Iumpr_CycleCounter_InitStatus();

    /* reset Numerators status to the following setting:
    * - Numerators Unlocked
    */
    Dem_Iumpr_Ratio_Numerator_ReleaseLock();

    /* update NvRam blocks */
    Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR),
      DEM_NVM_BLOCKSTATE_DIRTY);
    /* admin block has already been set to dirty */
  }
}


/* ****************************************************************************
 % Dem_Iumpr_IsIgnitionHybrid
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE)
Dem_Iumpr_IsIgnitionHybrid(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
CONST(uint8, AUTOMATIC) CycleId                                                                                                              /* PRQA S 3206 */ /* MD_DEM_3206 */
)
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(CycleId)                                                                              /* PRQA S 3112 */ /* MD_DEM_14.2 */
  return (boolean)(Dem_Cfg_GetOpCycleTypeOfCycleIdTable(CycleId) == DEM_CFG_OPCYC_IGNITION_HYBRID);
}


/* ****************************************************************************
 % Dem_Iumpr_MainFunction
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_MainFunction(
void
)
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_Cfg_ObdRatioIdIterType    lRatioIter;
    Dem_RatioIdIndexType          lRatioIndex;

    /* are general conditions available (i.e.: no input faults have been reported in this DCY)? */
    if (Dem_Iumpr_ConditionStatus_TestInhibited(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR) == FALSE)
    {
      boolean lUpdateNvM;
      lUpdateNvM = FALSE;

      /* check each ratio */
      for (Dem_Iumpr_RatioIter_Init(&lRatioIter);                                                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Iumpr_RatioIter_Exists(&lRatioIter) == TRUE;                                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Iumpr_RatioIter_Next(&lRatioIter))                                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        lRatioIndex = Dem_Iumpr_RatioIter_GetIdx(&lRatioIter);                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
        /* process any pending operation on this ratio if needed/allowed */
              if (Dem_Iumpr_Ratio_ProcessUpdate(lRatioIndex))
              {
                lUpdateNvM = TRUE;
              }
      }

      /* --- update NvM --- */
      if (lUpdateNvM == TRUE)
      {
        Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR),
          DEM_NVM_BLOCKSTATE_DIRTY);
      }
    }
  }
  /* else: general conditions not yet reached; nothing to do */
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/* ****************************************************************************
 % Dem_Iumpr_CalculateObdRatio
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Iumpr_CalculateObdRatio(                                                                                                     /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
CONST(Dem_EventIdType, AUTOMATIC) EventId,
CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Numerator,
CONSTP2VAR(uint16, AUTOMATIC, AUTOMATIC) Denominator
)
{
  Dem_RatioIdIndexType  lRatioIndex;
  lRatioIndex = Dem_Event_GetRatioIdx(EventId);

  if ((lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
    && ((Dem_DTC_IsEventCombinationType2Enabled() == TRUE) || (Dem_Cfg_EventIsCombined(EventId) == FALSE))                       /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    )
  {
    Dem_Iumpr_Ratio_GetRatio(lRatioIndex, Numerator, Denominator);                                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
  {
    *Numerator = 0x00;                                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    *Denominator = 0x00;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
}


/* ****************************************************************************
 % Dem_Iumpr_ReportRatioFault
 *****************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ReportRatioFault(
  const Dem_EventIdType EventId,
  const Dem_Iumpr_FaultOriginType FaultOrigin
)
{
  Dem_RatioIdIndexType lRatioIndex;

  lRatioIndex = Dem_Event_GetRatioIdx(EventId);

  /* If Iumpr is disabled, all events have invalid ratio index */
  if ((lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
    && (Dem_Iumpr_GetRatioReportingType(lRatioIndex) == (uint8)FaultOrigin)
    && (Dem_InitState_TestMasterAtLeastInState(DEM_INITSTATE_INITIALIZED) == TRUE)                                           /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
    )
  {
    Dem_Iumpr_Ratio_ReportRatioFault(lRatioIndex);
  }
}

/* ****************************************************************************
 % Dem_Iumpr_SetRatioAvailability
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Iumpr_SetRatioAvailability(                                                                                                  /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
CONST(Dem_EventIdType, AUTOMATIC) EventId,
CONST(Dem_Iumpr_RatioAvailabilityType, AUTOMATIC) availabiltyCommand
)
{
  Dem_RatioIdIndexType  lRatioIndex;
  lRatioIndex = Dem_Event_GetRatioIdx(EventId);

  if (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
  {
    switch (availabiltyCommand)
    {
      case Dem_Iumpr_ReconnectRatio:
        Dem_Iumpr_Ratio_Reconnect(lRatioIndex);
      break;

      case Dem_Iumpr_DisconnectRatio:
        Dem_Iumpr_Ratio_Disconnect(lRatioIndex);
      break;
      default:
        /* MISRA CASE */
      break;
    }
  }
}


/* ****************************************************************************
 % Dem_Iumpr_OpCycleStart
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_OpCycleStart(
CONST(Dem_EventIdType, AUTOMATIC) EventId
)
{
  Dem_RatioIdIndexType lRatioIndex;
  lRatioIndex = Dem_Event_GetRatioIdx(EventId);

  if (lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
  {
    Dem_Iumpr_Ratio_OpCycleStart(lRatioIndex);
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ProcessIgnCycleCounterIncrement
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ProcessIgnCycleCounterIncrement(void)                                                                                          /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_FimFid_PendingStateType lFiMPendingState;

    /* increment ignition cycle counter when DCY is qualified and increment is not inhibited by an input fault */
    lFiMPendingState = Dem_FimFid_QueryPendingState(Dem_FimFid_GetIgnitionCycle());
    if (lFiMPendingState == Dem_FimFid_PendingState_NotPending)
    {
      Dem_Iumpr_CycleCounter_Increment(Dem_Iumpr_CycleCounter_IgnitionCycleCounter);                                                                                                       /* PRQA S 3112 */ /* MD_DEM_14.2_CONFIGURATION_SWITCH */
    }
  }
}

/* ****************************************************************************
 % Dem_Iumpr_ProcessIgnHybridCycleCounterIncrement
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_ProcessIgnHybridCycleCounterIncrement(                                                                                               /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
CONST(Dem_OperationCycleStateType, AUTOMATIC) CycleState
)
{
  /* increment optional ignition cycle counter once per driving cycle */
  if (CycleState == DEM_CYCLE_STATE_START)
  {
    if (Dem_Iumpr_CycleCounter_TestHybridCounterIncremented() == FALSE)
    {
      Dem_FimFid_PendingStateType lFiMPendingState;

      lFiMPendingState = Dem_FimFid_QueryPendingState(Dem_FimFid_GetIgnitionCycle());
      if (lFiMPendingState == Dem_FimFid_PendingState_NotPending)
      {
        Dem_Iumpr_CycleCounter_Increment(Dem_Iumpr_CycleCounter_IgnitionHybridCycleCounter);                                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2_CONFIGURATION_SWITCH */
        Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR),
          DEM_NVM_BLOCKSTATE_DIRTY);
      }
    }
  }
}




/* ****************************************************************************
 % Dem_Iumpr_LockNumerators
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_LockNumerators(
  void
)
{
  Dem_Iumpr_Ratio_Numerator_Lock();

  Dem_Nvm_SetSingleBlockState(Dem_Nvm_GetSingleBlockId(DEM_NVM_BLOCKTYPE_IUMPR),
    DEM_NVM_BLOCKSTATE_DIRTY);
}

/* ****************************************************************************
 % Dem_Iumpr_LockRatioDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_LockRatioDenominator(
  Dem_RatioIdType RatioID
  )
{
  Std_ReturnType lReturnValue;
  Dem_RatioIdIndexType  lRatioIndex;

  /* ----- Implementation ---------------------------------------------- */

  lRatioIndex = Dem_Event_GetRatioIdx(RatioID);
  /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();

  /* set locked state */
  Dem_Iumpr_Ratio_Denominator_Lock(lRatioIndex);

  Dem_LeaveCritical_DiagMonitor();
  /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */

  lReturnValue = E_OK;
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_ReleaseRatioDenominator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_ReleaseRatioDenominator(
Dem_RatioIdType RatioID
)
{
  Std_ReturnType lReturnValue;
  Dem_RatioIdIndexType lRatioIndex;
  boolean lIncrementDenominator;

  lRatioIndex = Dem_Event_GetRatioIdx(RatioID);
  /* >>>> -------------------------------- Enter Critical Section: DiagMonitor */
  Dem_EnterCritical_DiagMonitor();
                                                                                                                                                                                                                                                               
  /* clear locked state */                                                                                                       
  lIncrementDenominator = Dem_Iumpr_Ratio_Denominator_Release(lRatioIndex);
                                                                                                                                 
  Dem_LeaveCritical_DiagMonitor();
  /* <<<< -------------------------------- Leave Critical Section: DiagMonitor */                                                
                                                                                                                                 
  if ((Dem_Iumpr_ConditionStatus_TestReached(DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR) == TRUE)
    && (lIncrementDenominator == FALSE))                                                                  /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
  {                                                                                                                              
    /* conditions for increment seem to be fulfilled; set pending flag and increment on task level */                            
    Dem_Iumpr_Ratio_QueueUpdate(lRatioIndex, TRUE);                                                                               
    Dem_Scheduler_EnableTaskOnce(Dem_Scheduler_Task_IUMPR);                                                                      
  }                                                                                                                              
                                                                                                                                 
  lReturnValue = E_OK;                                                                                                           
                                                                                                                                 
  return lReturnValue;                                                                                                           
}                                                                                                                                  /* PRQA S 6050 */ /* MD_MSR_STCAL */


/* ****************************************************************************
 % Dem_Iumpr_Filter_SetFilter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_SetFilter(
Dem_IumprReadinessGroupType IumprReadinessGroup,
Dem_DTCOriginType DTCOrigin
)
{
  Std_ReturnType lReturnValue;
  uint8 memoryId;

  Dem_Iumpr_FilterInfo.ReadinessGroup = IumprReadinessGroup;
  Dem_Iumpr_FilterInfo.CurrentEvent = DEM_EVENT_INVALID;

  memoryId = Dem_ClientAccess_MemoryIdFromOrigin(DTCOrigin);

  if ((memoryId == DEM_CFG_MEMORYID_PRIMARY) || (memoryId == DEM_CFG_MEMORYID_SECONDARY))
  {
    Dem_Iumpr_FilterInfo.FirstEvent = Dem_Memory_GetFirstEvent(memoryId);
    Dem_Iumpr_FilterInfo.LastEvent = Dem_Memory_GetLastEvent(memoryId);
    lReturnValue = E_OK;
  }
  else
  {
    /* not supported memory location for IUMPR filtering */
    lReturnValue = E_NOT_OK;
  }
  return lReturnValue;
}


/* ****************************************************************************
 % Dem_Iumpr_InitFilter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitFilter(
void
)
{
  if (Dem_Iumpr_IsEnabled() == TRUE)
  {
    Dem_Iumpr_FilterInfo.FirstEvent = DEM_EVENT_INVALID;
  }
}

/* ****************************************************************************
 % Dem_Iumpr_Filter_GetFirstEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Iumpr_Filter_GetFirstEvent(
void
)
{
  return Dem_Iumpr_FilterInfo.FirstEvent;
}

/* ****************************************************************************
 % Dem_Iumpr_Filter_GetCurrentEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Dem_EventIdType, DEM_CODE)
Dem_Iumpr_Filter_GetCurrentEvent(
void
)
{
  return Dem_Iumpr_FilterInfo.CurrentEvent;
}

/* ****************************************************************************
 % Dem_Iumpr_Filter_GetCount
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetCount(
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  NumberOfFilteredRatios                                                                  /* PRQA S 1330 */ /* MD_DEM_8.3_rte */
)
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lReturnValue = E_NOT_OK;

  lEventId = Dem_Iumpr_FilterInfo.FirstEvent;
  if (lEventId != DEM_EVENT_INVALID)
  {
    *NumberOfFilteredRatios = 0u;                                                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    for (lEventId = Dem_Iumpr_FilterInfo.FirstEvent;
      lEventId <= Dem_Iumpr_FilterInfo.LastEvent;
      ++lEventId)
    {
      Dem_RatioIdIndexType  lRatioIndex;
      lRatioIndex = Dem_Event_GetRatioIdx(lEventId);

      /* Skip suppressed or deactivated events. RatioId == EventId */
      if ((lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)                                                                            
        && (Dem_Event_TestSuppressionOnEventRetrieval(lEventId) == FALSE)                                                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        )
      {
        /* either only a specific ratio group is selected or all groups are selected */
        if ((Dem_Iumpr_FilterInfo.ReadinessGroup == Dem_Iumpr_Ratio_GetReadinessGroupType(lRatioIndex))
          || (Dem_Iumpr_FilterInfo.ReadinessGroup == DEM_IUMPR_ALLGROUPS))
        {
          ++(*NumberOfFilteredRatios);                                                                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        }
      }
    }
    lReturnValue = E_OK;
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_Filter_GetNext
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetNext(
P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  UdsDtcNumber,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  ObdDtcNumber,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Denominator,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Numerator
)
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lReturnValue = E_NOT_OK;

  lEventId = Dem_Iumpr_FilterInfo.FirstEvent;
  if (lEventId != DEM_EVENT_INVALID)
  {
    lEventId = Dem_Iumpr_FilterInfo.CurrentEvent;

    if (Dem_Iumpr_FilterInfo.CurrentEvent == DEM_EVENT_INVALID)
    { /* Initial call after set filter, set current event to first event */
      lEventId = Dem_Iumpr_FilterInfo.FirstEvent;
    }
    else
    {
      lEventId += 1u; /* add 1 for the next possible element */
    }


    for (; lEventId <= Dem_Iumpr_FilterInfo.LastEvent; ++lEventId)
    {
      Dem_RatioIdIndexType  lRatioIndex;

      lRatioIndex = Dem_Event_GetRatioIdx(lEventId);

      /* Skip suppressed or deactivated events. RatioId == EventId */
      if ((lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)                                                                            
        && (Dem_Event_TestSuppressionOnEventRetrieval(lEventId) == FALSE))                                                       /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      {
        /* either only a specific ratio group is selected or all groups are selected */
        if ((Dem_Iumpr_FilterInfo.ReadinessGroup == Dem_Iumpr_Ratio_GetReadinessGroupType(lRatioIndex))
          || (Dem_Iumpr_FilterInfo.ReadinessGroup == DEM_IUMPR_ALLGROUPS))
        {
          *UdsDtcNumber = Dem_Cfg_EventUdsDtc(lEventId);                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          *ObdDtcNumber = Dem_Cfg_EventObdDtc(lEventId);                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
          Dem_Iumpr_Ratio_GetRatio(lRatioIndex, Numerator, Denominator);                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

          lReturnValue = E_OK;
          break;
        }
      }
    }

    if (lEventId <= Dem_Iumpr_FilterInfo.LastEvent)
    {
      Dem_Iumpr_FilterInfo.CurrentEvent = lEventId;
    }
  }
  return lReturnValue;
}

/* ****************************************************************************
 % Dem_Iumpr_Filter_GetCurrent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Iumpr_Filter_GetCurrent(
P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA)  UdsDtcNumber,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  ObdDtcNumber,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Denominator,
P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  Numerator
)
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lReturnValue = E_NOT_OK;

  lEventId = Dem_Iumpr_FilterInfo.CurrentEvent;
  if (lEventId != DEM_EVENT_INVALID)
  {
    Dem_RatioIdIndexType  lRatioIndex;

    lRatioIndex = Dem_Event_GetRatioIdx(lEventId);

    /* Exclude suppressed or deactivated events. RatioId == EventId */
    if ((lRatioIndex != DEM_CFG_RATIOINDEX_INVALID)
      && (Dem_Event_TestSuppressionOnEventRetrieval(lEventId) == FALSE)                                                          /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      )
    {
      *UdsDtcNumber = Dem_Cfg_EventUdsDtc(lEventId);                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      *ObdDtcNumber = Dem_Cfg_EventObdDtc(lEventId);                                                                             /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      Dem_Iumpr_Ratio_GetRatio(lRatioIndex, Numerator, Denominator);                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */

      lReturnValue = E_OK;
    }
  }
  return lReturnValue;
}



/* ****************************************************************************
 % Dem_Iumpr_GetRatioReportingType
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Iumpr_GetRatioReportingType(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex
)
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(RatioIndex)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
#if (DEM_CFG_SUPPORT_IUMPR == STD_ON)
  return Dem_Cfg_GetRatioIdTypeOfRatioIdTable(RatioIndex);
#else
    return (uint8)DEM_RATIO_REPORTINGTYPE_INVALID;
#endif
}

/* ****************************************************************************
 % Dem_Iumpr_GetDenGroupOfRatio
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Iumpr_GetDenGroupOfRatio(
CONST(Dem_RatioIdIndexType, AUTOMATIC) RatioIndex                                                                                            /* PRQA S 3206, 3219 */ /* MD_DEM_3206, MD_DEM_14.1_ACCESSOR */
)
{
  return Dem_Iumpr_Ratio_Denominator_GetDenominatorGroup(RatioIndex);
}

/* ****************************************************************************
 % Dem_Iumpr_InitCycleCounter
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Iumpr_InitCycleCounter(                                                                                                      /* PRQA S 3219 */ /* MD_DEM_14.1_CONFIGURATION_SWITCH */
  void
)
{
  Dem_Iumpr_CycleCounter_InitMemory();
}

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  FILE SPECIFIC MISRA VIOLATIONS
 *********************************************************************************************************************/
/* PRQA L:DEM_IUMPR_IMPL */

#endif /* DEM_IUMPR_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Iumpr_Implementation.h
 *********************************************************************************************************************/
