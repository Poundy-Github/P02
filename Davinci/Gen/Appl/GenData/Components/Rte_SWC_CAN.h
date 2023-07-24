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
 *             File:  Rte_SWC_CAN.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <SWC_CAN>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_CAN_H
# define RTE_SWC_CAN_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_CAN_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ABS3_0x265_ABS3_0x265(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ABS3_0x265_ABS3_0x265(P2VAR(ABS3_0x265, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_BMS19_0x352_BMS19_0x352(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_BMS19_0x352_BMS19_0x352(P2VAR(BMS19_0x352, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_DCT3_0xa6_DCT3_0xa6(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_DCT3_0xa6_DCT3_0xa6(P2VAR(DCT3_0xa6, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3(P2VAR(ECM11_0x2d3, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM1_0x111_ECM1_0x111(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM1_0x111_ECM1_0x111(P2VAR(ECM1_0x111, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM3_0x371_ECM3_0x371(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ECM3_0x371_ECM3_0x371(P2VAR(ECM3_0x371, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ESP2_0x145_ESP2_0x145(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ESP2_0x145_ESP2_0x145(P2VAR(ESP2_0x145, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137(P2VAR(ESP_FD2_0x137, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330(P2VAR(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330(P2VAR(HCU_PT5_0x330, AUTOMATIC, RTE_SWC_CAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT15_0x1ee_HUT15_0x1ee(P2CONST(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT15_0x1ee_HUT15_0x1ee(P2CONST(HUT15_0x1ee, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT30_0x1e9_HUT30_0x1e9(P2CONST(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT30_0x1e9_HUT30_0x1e9(P2CONST(HUT30_0x1e9, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT_FD1_0x2c3_HUT_FD1_0x2c3(P2CONST(uint8, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_CAN_HUT_FD1_0x2c3_HUT_FD1_0x2c3(P2CONST(HUT_FD1_0x2c3, AUTOMATIC, RTE_SWC_CAN_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ABS3_0x265_ABS3_0x265 Rte_Read_SWC_CAN_ABS3_0x265_ABS3_0x265
#  define Rte_Read_BMS19_0x352_BMS19_0x352 Rte_Read_SWC_CAN_BMS19_0x352_BMS19_0x352
#  define Rte_Read_DCT3_0xa6_DCT3_0xa6 Rte_Read_SWC_CAN_DCT3_0xa6_DCT3_0xa6
#  define Rte_Read_ECM11_0x2d3_ECM11_0x2d3 Rte_Read_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3
#  define Rte_Read_ECM1_0x111_ECM1_0x111 Rte_Read_SWC_CAN_ECM1_0x111_ECM1_0x111
#  define Rte_Read_ECM3_0x371_ECM3_0x371 Rte_Read_SWC_CAN_ECM3_0x371_ECM3_0x371
#  define Rte_Read_ESP2_0x145_ESP2_0x145 Rte_Read_SWC_CAN_ESP2_0x145_ESP2_0x145
#  define Rte_Read_ESP_FD2_0x137_ESP_FD2_0x137 Rte_Read_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137
#  define Rte_Read_HCU_PT5_0x330_HCU_PT5_0x330 Rte_Read_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_ABS3_0x265_ABS3_0x265 Rte_IsUpdated_SWC_CAN_ABS3_0x265_ABS3_0x265
#  define Rte_IsUpdated_SWC_CAN_ABS3_0x265_ABS3_0x265() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ABS3_0x265_ABS3_0x265 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ABS3_0x265_ABS3_0x265_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_BMS19_0x352_BMS19_0x352 Rte_IsUpdated_SWC_CAN_BMS19_0x352_BMS19_0x352
#  define Rte_IsUpdated_SWC_CAN_BMS19_0x352_BMS19_0x352() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_BMS19_0x352_BMS19_0x352 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_BMS19_0x352_BMS19_0x352_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_DCT3_0xa6_DCT3_0xa6 Rte_IsUpdated_SWC_CAN_DCT3_0xa6_DCT3_0xa6
#  define Rte_IsUpdated_SWC_CAN_DCT3_0xa6_DCT3_0xa6() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_DCT3_0xa6_DCT3_0xa6 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_DCT3_0xa6_DCT3_0xa6_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM11_0x2d3_ECM11_0x2d3 Rte_IsUpdated_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3
#  define Rte_IsUpdated_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM11_0x2d3_ECM11_0x2d3_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM1_0x111_ECM1_0x111 Rte_IsUpdated_SWC_CAN_ECM1_0x111_ECM1_0x111
#  define Rte_IsUpdated_SWC_CAN_ECM1_0x111_ECM1_0x111() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM1_0x111_ECM1_0x111 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM1_0x111_ECM1_0x111_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ECM3_0x371_ECM3_0x371 Rte_IsUpdated_SWC_CAN_ECM3_0x371_ECM3_0x371
#  define Rte_IsUpdated_SWC_CAN_ECM3_0x371_ECM3_0x371() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM3_0x371_ECM3_0x371 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ECM3_0x371_ECM3_0x371_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP2_0x145_ESP2_0x145 Rte_IsUpdated_SWC_CAN_ESP2_0x145_ESP2_0x145
#  define Rte_IsUpdated_SWC_CAN_ESP2_0x145_ESP2_0x145() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ESP2_0x145_ESP2_0x145 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ESP2_0x145_ESP2_0x145_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_ESP_FD2_0x137_ESP_FD2_0x137 Rte_IsUpdated_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137
#  define Rte_IsUpdated_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_ESP_FD2_0x137_ESP_FD2_0x137_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IsUpdated_HCU_PT5_0x330_HCU_PT5_0x330 Rte_IsUpdated_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330
#  define Rte_IsUpdated_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330() (Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330 != Rte_SystemApplication_OsCore0_RxUpdateFlags.Rte_RxUpdate_SWC_CAN_HCU_PT5_0x330_HCU_PT5_0x330_Sender) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_HUT15_0x1ee_HUT15_0x1ee Rte_Write_SWC_CAN_HUT15_0x1ee_HUT15_0x1ee
#  define Rte_Write_HUT30_0x1e9_HUT30_0x1e9 Rte_Write_SWC_CAN_HUT30_0x1e9_HUT30_0x1e9
#  define Rte_Write_HUT_FD1_0x2c3_HUT_FD1_0x2c3 Rte_Write_SWC_CAN_HUT_FD1_0x2c3_HUT_FD1_0x2c3


# endif /* !defined(RTE_CORE) */


# define SWC_CAN_START_SEC_CODE
# include "SWC_CAN_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SWC_CAN_Init SWC_CAN_Init
#  define RTE_RUNNABLE_SWC_CAN_MainFunction SWC_CAN_MainFunction
# endif

FUNC(void, SWC_CAN_CODE) SWC_CAN_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_CAN_CODE) SWC_CAN_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_CAN_STOP_SEC_CODE
# include "SWC_CAN_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_CAN_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
