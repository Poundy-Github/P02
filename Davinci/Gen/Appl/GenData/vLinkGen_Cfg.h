/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vLinkGen
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Cfg.h
 *   Generation Time: 2020-12-12 14:39:36
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#ifndef VLINKGEN_CFG_H
# define VLINKGEN_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define VLINKGEN_CFG_MAJOR_VERSION                   2u
/*! Configuration minor version identification. */
# define VLINKGEN_CFG_MINOR_VERSION                   0u

/* Number of entries for different initialization tables */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS      1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS        1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS 2uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        9uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1uL 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1uL 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             10uL 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1uL 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1uL 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1uL 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#endif /* VLINKGEN_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Cfg.h
 *********************************************************************************************************************/
