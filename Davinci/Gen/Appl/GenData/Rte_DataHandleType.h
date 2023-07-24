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
 *             File:  Rte_DataHandleType.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Header file containing Data Handle type declarations for component data structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DATA_HANDLE_TYPE_H
# define RTE_DATA_HANDLE_TYPE_H


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE value;
} Rte_DE_FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  SystemState_RecordType value;
  Std_ReturnType status;
} Rte_DES_SystemState_RecordType;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  sint64 value;
} Rte_DE_sint64;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  TC_MODULE_OUTPUT_DATA_STRUCT_RTE value;
} Rte_DE_TC_MODULE_OUTPUT_DATA_STRUCT_RTE;
/* PRQA L:L1 */

 /* PRQA S 1039 L1 */ /* MD_Rte_1039 */
typedef struct
{
  SystemState_RecordType value;
} Rte_DE_SystemState_RecordType;
/* PRQA L:L1 */

#endif /* RTE_DATA_HANDLE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

*/
