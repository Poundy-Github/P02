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
 *              File: Os_Ioc_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_IOC_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"
#include "vstdlib.h"

/* Os module declarations */
#include "Os_Ioc_Cfg.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Ioc_Types.h"
#include "Os_Ioc.h"
#include "Ioc.h"

/* Os kernel module dependencies */
#include "Os_Fifo08.h"
#include "Os_Fifo16.h"
#include "Os_Fifo32.h"
#include "Os_Hook.h"
#include "Os_Spinlock_Lcfg.h"
#include "OsInt.h"

/* Os hal dependencies */

/* User file includes */
# include "Rte.h"
# include "usrostyp.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Copies the given target data to the source address, based on the native data type.
 *  \details      -
 *  \param[in]    Source  The source address to read from. Parameter must not be NULL.
 *  \param[out]   Target  The target address to write to. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
);

/**********************************************************************************************************************
 *  Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Initializes the data buffer with configured initial values.
 *  \details      -
 *  \param[in]    Data  The pointer to the data buffer. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
);

/**********************************************************************************************************************
 *  Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Copies the given target data to the source address, based on the native data type.
 *  \details      -
 *  \param[in]    Source  The source address to read from. Parameter must not be NULL.
 *  \param[out]   Target  The target address to write to. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
);

/**********************************************************************************************************************
 *  Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*! \brief        Initializes the data buffer with configured initial values.
 *  \details      -
 *  \param[in]    Data  The pointer to the data buffer. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          -
 *********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
);

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC receive data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element */
OS_LOCAL VAR(Os_IocReadType, OS_VAR_NOINIT) OsCfg_IocRecv_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0_Dyn;

/*! IOC communication single data buffer: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element */
OS_LOCAL VAR(uint8, OS_APPL_DATA) OsCfg_Ioc_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_OsApplication_Trust_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC receive data: Rte_Power_Rc_Cluster_Shutdown_Status_Element */
OS_LOCAL VAR(Os_IocReadType, OS_VAR_NOINIT) OsCfg_IocRecv_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Dyn;

#define OS_STOP_SEC_OsApplication_Trust_OsCore0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_Power_Rc_Cluster_Shutdown_Status_Element_0 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0_Dyn;

/*! IOC communication single data buffer: Rte_Power_Rc_Cluster_Shutdown_Status_Element */
OS_LOCAL VAR(uint8, OS_APPL_DATA) OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic IOC send data: Rte_Power_Rc_Cluster_Shutdown_Status_Element_1 */
OS_LOCAL VAR(Os_IocWriteType, OS_VAR_NOINIT) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! IOC receive configuration data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element */
CONST(Os_IocReadConfigType, OS_CONST) OsCfg_IocRecv_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element =
{
  /* .Ioc      = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCREAD_2_IOC(OsCfg_IocRecv_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Dyn),
      /* .SubClass              = */ IocRead,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_NonTrust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data     = */ &OsCfg_Ioc_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,   /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */
  /* .CopyCbk  = */ Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_NonTrust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_COMMON_NORMAL_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element,
  /* .InitCbk   = */ Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_Trust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_COMMON_NORMAL_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element,
  /* .InitCbk   = */ Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/*! IOC receive configuration data: Rte_Power_Rc_Cluster_Shutdown_Status_Element */
CONST(Os_IocReadConfigType, OS_CONST) OsCfg_IocRecv_Rte_Power_Rc_Cluster_Shutdown_Status_Element =
{
  /* .Ioc      = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCREAD_2_IOC(OsCfg_IocRecv_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Dyn),
      /* .SubClass              = */ IocRead,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_Trust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data     = */ &OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,   /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */
  /* .CopyCbk  = */ Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_Power_Rc_Cluster_Shutdown_Status_Element_0 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_NonTrust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_POWER_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element,
  /* .InitCbk   = */ Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC send configuration data: Rte_Power_Rc_Cluster_Shutdown_Status_Element_1 */
CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1 =
{
  /* .Ioc       = */
  {
      /* .Spinlock              = */ NULL_PTR,
      /* .LockMode              = */ OS_IOCLOCKMODE_NONE,
      /* .Dyn                   = */ OS_IOC_CASTDYN_IOCWRITE_2_IOC(OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1_Dyn),
      /* .SubClass              = */ IocWrite,
      /* .AccessingApplications = */ OS_APPID2MASK(OsApplication_Trust_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    },
  /* .Data      = */ (P2VAR(void, AUTOMATIC, OS_APPL_DATA)) &OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn,  /* PRQA S 0314 */ /* MD_Os_Dir1.1_0314 */
  /* .Callback  = */
  {
      /* .CallbackRefs  = */ NULL_PTR,
      /* .CallbackCount = */ OS_CFG_NUM_IOC_RTE_POWER_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS
    },
  /* .CopyCbk   = */ Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element,
  /* .InitCbk   = */ Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IocRead_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general receive function.
 * \endinternal
 */
Std_ReturnType IocRead_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  uint8 *Arg0
)
{
  Std_ReturnType status;
  uint8 localVar;

  /* #10 Redirect call to the general receive function. */
  status = Os_TrapIocRead(TRUE, &OsCfg_IocRecv_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element, (P2VAR(uint8, AUTOMATIC, OS_APPL_DATA)) &localVar);  /* PRQA S 0310, 0315 */ /* MD_Os_Rule11.3_0310, MD_Os_Dir1.1_0315 */ 
  (*Arg0) = localVar;

  return status;
}



/**********************************************************************************************************************
 *  IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general send function.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0
(
  uint8 Arg0
)
{
  /* #10 Redirect call to the general send function. */
  return Os_TrapIocWrite(TRUE, &OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0, (P2CONST(void, AUTOMATIC, OS_APPL_DATA)) &Arg0);  /* PRQA S 0314, 1340 */ /* MD_Os_Dir1.1_0314, MD_Os_Rule17.8_1340 */
}


/**********************************************************************************************************************
 *  IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Write user data directly to the communication buffer.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1
(
  uint8 Arg0
)
{
  /* #10 Write user data directly to the communication buffer. */
  OsCfg_Ioc_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn = Arg0;

  return IOC_E_OK;
}


/**********************************************************************************************************************
 *  Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Convert given pointers into native type and copy data from source to target.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
)
{
  /* #10 Convert given pointers into native type and copy data from source to target. */
  *((P2VAR(uint8, AUTOMATIC, OS_APPL_DATA)) Target) =   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
  *((P2CONST(uint8, AUTOMATIC, OS_APPL_DATA)) Source);  /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
}


/**********************************************************************************************************************
 *  Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Initialize data.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
)
{
  /* #10 Initialize data. */
  (*((uint8*)Data)) = Rte_IocInitValue_Common_Normal_Rc_Cluster_Shutdown_Status_Element;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
}


/**********************************************************************************************************************
 *  IocRead_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Read from the communication buffer. Put result into out parameter.
 * \endinternal
 */
Std_ReturnType IocRead_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  uint8 *Arg0
)
{
  /* #10 Read from the communication buffer. Put result into out parameter. */
  (*Arg0) = OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn;

  return IOC_E_OK;
}


/**********************************************************************************************************************
 *  IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Redirect call to the general send function.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0
(
  uint8 Arg0
)
{
  /* #10 Redirect call to the general send function. */
  return Os_TrapIocWrite(TRUE, &OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0, (P2CONST(void, AUTOMATIC, OS_APPL_DATA)) &Arg0);  /* PRQA S 0314, 1340 */ /* MD_Os_Dir1.1_0314, MD_Os_Rule17.8_1340 */
}


/**********************************************************************************************************************
 *  IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Write user data directly to the communication buffer.
 * \endinternal
 */
Std_ReturnType IocWrite_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1
(
  uint8 Arg0
)
{
  /* #10 Write user data directly to the communication buffer. */
  OsCfg_Ioc_Rte_Power_Rc_Cluster_Shutdown_Status_Element_Buffer_Dyn = Arg0;

  return IOC_E_OK;
}


/**********************************************************************************************************************
 *  Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Convert given pointers into native type and copy data from source to target.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocCopy_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  P2CONST(void, AUTOMATIC, OS_APPL_DATA) Source,
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Target
)
{
  /* #10 Convert given pointers into native type and copy data from source to target. */
  *((P2VAR(uint8, AUTOMATIC, OS_APPL_DATA)) Target) =   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
  *((P2CONST(uint8, AUTOMATIC, OS_APPL_DATA)) Source);  /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
}


/**********************************************************************************************************************
 *  Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element()
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Initialize data.
 * \endinternal
 */
OS_LOCAL FUNC(void, OS_CODE) Os_IocInit_Rte_Power_Rc_Cluster_Shutdown_Status_Element
(
  P2VAR(void, AUTOMATIC, OS_APPL_DATA) Data
)
{
  /* #10 Initialize data. */
  (*((uint8*)Data)) = Rte_IocInitValue_Power_Rc_Cluster_Shutdown_Status_Element;   /* PRQA S 0316 */ /* MD_Os_Rule11.5_0316_Param */
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Lcfg.c
 *********************************************************************************************************************/
