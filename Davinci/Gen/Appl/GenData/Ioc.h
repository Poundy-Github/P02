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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ioc.h
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef IOC_H
# define IOC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"
# include "vstdlib.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/* User file includes */
# include "Rte.h"
# include "usrostyp.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! IOC function return types */
# define IOC_E_OK                                (RTE_E_OK          )
# define IOC_E_NOK                               ((Std_ReturnType) 1)
# define IOC_E_NO_DATA                           (RTE_E_NO_DATA     )
# define IOC_E_LOST_DATA                         (RTE_E_LOST_DATA   )
# define IOC_E_LIMIT                             (RTE_E_LIMIT       )
# define IOC_E_CHANNEL                           (IOC_E_NOK         )


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IocRead_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Reads the data from the IOC.
 *  \details      -
 *  \param[out]   Arg0  Data read from the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocRead().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          Channel is initialized.
 *********************************************************************************************************************/
Std_ReturnType IocRead_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  uint8 *Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocWrite().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0
(
  uint8 Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      IOC_E_OK is always returned.
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1
(
  uint8 Arg0
);

/**********************************************************************************************************************
 *  IocRead_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Reads the data from the IOC.
 *  \details      -
 *  \param[out]   Arg0  Data read from the IOC. Parameter must not be NULL.
 *  \returns      IOC_E_OK is always returned.
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          Channel is initialized.
 *********************************************************************************************************************/
Std_ReturnType IocRead_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  uint8 *Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      For further information see Os_IocWrite().
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0
(
  uint8 Arg0
);

/**********************************************************************************************************************
 *  IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1()
 *********************************************************************************************************************/
/*! \brief        Writes the given data to the IOC.
 *  \details      -
 *  \param[in]    Arg0  The data to write to the IOC. Parameter must not be NULL.
 *  \returns      IOC_E_OK is always returned.
 *  \context      TASK|ISR2
 *  \reentrant    TRUE if concurrent access is prevented by configuration.
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
Std_ReturnType IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1
(
  uint8 Arg0
);


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* IOC_H */

/**********************************************************************************************************************
 *  END OF FILE: Ioc.h
 *********************************************************************************************************************/
