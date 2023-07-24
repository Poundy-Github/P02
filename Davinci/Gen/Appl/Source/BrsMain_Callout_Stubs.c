
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsMain_Callout_Stubs.c
      Project:  Vector Basic Runtime System
       Module:  BrsMain

  \brief Description:  UseCase specific implementation templates for several hooks out of BrsMain.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2020-04-29  visbwa  Initial creation for vBaseEnv 2.0.0
            2020-06-03  visbwa  Several new hooks for updated BrsMainStartup.c and vLinkGen 2.0
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsMain.h"

#include "BrsHw.h"

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/

/**********************************************************************************************************************
  DEFINITION + MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             previous to the memory initialization, stage zero.
 */
/*****************************************************************************/
void BrsMain_MemoryInit_StageZero_Hook(uint32 coreId)
{
  /* nothing to be done up to now */
}

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             previous to the memory initialization, stage one.
 */
/*****************************************************************************/
void BrsMain_MemoryInit_StageOne_Hook(uint32 coreId)
{
  /* nothing to be done up to now */
}

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             previous to the memory initialization, stage hard reset.
 */
/*****************************************************************************/
void BrsMain_MemoryInit_StageHardReset_Hook(uint32 coreId)
{
  /* nothing to be done up to now */
}

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             previous to the memory initialization, stage two.
 */
/*****************************************************************************/
void BrsMain_MemoryInit_StageTwo_Hook(uint32 coreId)
{
  /* nothing to be done up to now */
}

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             previous to the memory initialization, stage three.
 */
/*****************************************************************************/
void BrsMain_MemoryInit_StageThree_Hook(uint32 coreId)
{
  /* nothing to be done up to now */
}

/*****************************************************************************/
/**
 * @brief      This API is an optional callout
 * @pre        -
 * @param[in]  coreID must declare the ID of the actual running core
 * @param[out] -
 * @return     -
 * @context    Function is called from Brs_PreMainStartup() during StartUp,
 *             after the memory initialization was done.
 */
/*****************************************************************************/
void BrsMain_PreMainHook(uint32 coreId)
{
  /* nothing to be done up to now */
}
