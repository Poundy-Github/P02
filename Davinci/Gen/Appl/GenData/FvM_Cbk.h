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
 *            Module: FvM
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FvM_Cbk.h
 *   Generation Time: 2022-03-02 17:10:51
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueTxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueTxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueTxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_R_PBox1_Sc_oB30_for_SC_CAN_V3_2_28fd970b_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_R_PBox1_Sc_oB30_for_SC_CAN_V3_2_28fd970b_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 * 
 * [Warning] AR-ECUC02027 - Integer value out of range 
 * - [Reduced Severity due to User-Defined Parameter] The parameter /ActiveEcuC/FvM/FreshnessValueProcessing_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) is not in range [0, 16].
 * Erroneous configuration elements:
 * /ActiveEcuC/FvM/FreshnessValueProcessing_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/FvMFreshnessValueUseCase/FvMJasparAttributes[0:FvMMessageCounterBitSize](value=22) (DefRef: /MICROSAR/FvM/FvMFreshnessValueRxProcessing/FvMFreshnessValueUseCase/FvMJasparAttributes/FvMMessageCounterBitSize)
 *********************************************************************************************************************/
#if !defined (FVM_CBK_H)
# define FVM_CBK_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "FvM_Types.h"

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


#endif  /* FVM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: FvM_Cbk.h
**********************************************************************************************************************/

