/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  IoHwAb_MemMap.h
 *        Config:  Turing.dpa
 *   ECU-Project:  ICM
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
 *
 *   Description:  Memory Mapping header file for SW-C <IoHwAb>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * IoHwAb specific defines
 *********************************************************************************************************************/

/* open sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_START_SEC_CODE
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_CODE
# undef SWC_TC_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_NONTRUST_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_START_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_CONST_UNSPECIFIED
# undef SWC_TC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_NONTRUST_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_START_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SWC_TC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_NONTRUST_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_VAR_INIT_UNSPECIFIED
# undef SWC_TC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_NONTRUST_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SWC_TC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_NONTRUST_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* close sections */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_CODE
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_STOP_SEC_CODE
# undef SWC_TC_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_CONST_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_STOP_SEC_CONST_UNSPECIFIED
# undef SWC_TC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SWC_TC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SWC_TC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SWC_TC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif
/* PRQA L:L1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!         << Start of memory mapping implementation >>         DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
 *********************************************************************************************************************/

/* PRQA S 0883 L1 */ /* MD_Rte_0883 */
#ifdef SWC_TC_START_SEC_GLOBALB_VAR_UNSPECIFIED
# undef SWC_TC_START_SEC_GLOBALB_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_GLOBALB_NONTRUST_VAR_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#ifdef SWC_TC_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
# undef SWC_TC_STOP_SEC_GLOBALB_VAR_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!          << End of memory mapping implementation >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0883:  MISRA rule: 19.15
     Reason:     AUTOSAR SWS Memory Mapping requires inclusion of MemMap.h multiple times in a file in order to
                 select appropriate #pragma directives.
     Risk:       MemMap.h is provided by the integrator, hence many risks may occur, caused by wrong implementation of this file.
     Prevention: The integrator strictly has to adhere to the definitions of the AUTOSAR SWS Memory Mapping. Extensions to
                 the file not described in the SWS may not be put into MemMap.h. This has to be verified by code inspection.

*/
