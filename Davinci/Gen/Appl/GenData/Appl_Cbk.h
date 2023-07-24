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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Appl_Cbk.h
 *   Generation Time: 2022-03-02 17:10:51
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (APPL_CBK_H)
# define APPL_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Configurable notification interface prototypes */
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_DMS_FD1_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_DVR_FD1_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT10_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT12_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT13_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT15_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT16_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT17_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT19_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT1_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT20_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT21_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT22_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT23_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT25_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT26_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT27_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT2_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT30_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT31_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT32_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT33_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT34_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT35_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT36_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT37_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT38_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT39_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT3_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT40_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT41_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT42_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT43_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT45_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT46_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT49_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT4_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT6_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT7_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT_FD1_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT_FD2_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT_FD3_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT_FD4_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_HUT_FD5_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_IP1_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_IP2_Confiratmion(void);
FUNC(void, COM_APPL_CODE) ComEx_TransmitPdu_IP3_Confiratmion(void);


#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

#endif  /* APPL_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Appl_Cbk.h
**********************************************************************************************************************/

