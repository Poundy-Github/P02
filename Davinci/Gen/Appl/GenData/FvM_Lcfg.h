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
 *              File: FvM_Lcfg.h
 *   Generation Time: 2022-03-02 17:10:52
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
#if !defined (FVM_LCFG_H)
# define FVM_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "FvM_Types.h"
# include "FvM_Cbk.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FvMPCDataSwitches  FvM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define FVM_CLEARACCEPTANCEWINDOW                                     STD_ON
#define FVM_CLEARACCEPTANCEWINDOWWITHOUTRESETCOUNTER                  STD_OFF  /**< Deactivateable: 'FvM_ClearAcceptanceWindowWithoutResetCounter' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_DEMEVENTIDREFERENCE                                       STD_OFF  /**< Deactivateable: 'FvM_DemEventIdReference' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_DEVMODEENABLED                                            STD_ON
#define FVM_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'FvM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FVM_FRESHNESSVALUEARRAY                                       STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFO                                  STD_ON
#define FVM_ENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO               STD_ON
#define FVM_FIRSTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO   STD_OFF  /**< Deactivateable: 'FvM_FreshnessValueLayoutInfo.FirstUsedBitsOfMessageCounter' Reason: 'the value of FvM_FirstUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo is always '0' due to this, the array is deactivated.' */
#define FVM_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSENDIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYMESSAGECOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYMESSAGECOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYMESSAGECOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYMESSAGECOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETCOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETFLAGIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYRESETFLAGUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRIPCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRIPCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRIPCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRIPFLAGIDXOFFRESHNESSVALUELAYOUTINFO  STD_OFF  /**< Deactivateable: 'FvM_FreshnessValueLayoutInfo.FreshnessValueArrayTripFlagIdx' Reason: 'the optional indirection is deactivated because FreshnessValueArrayTripFlagUsedOfFreshnessValueLayoutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FVM_FRESHNESSVALUEARRAYTRIPFLAGUSEDOFFRESHNESSVALUELAYOUTINFO STD_OFF  /**< Deactivateable: 'FvM_FreshnessValueLayoutInfo.FreshnessValueArrayTripFlagUsed' Reason: 'the optional indirection is deactivated because FreshnessValueArrayTripFlagUsedOfFreshnessValueLayoutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define FVM_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEENDIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUELENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUESTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO    STD_ON
#define FVM_MESSAGECOUNTERBITSIZEOFFRESHNESSVALUELAYOUTINFO           STD_ON
#define FVM_MESSAGECOUNTERMAXVALUEOFFRESHNESSVALUELAYOUTINFO          STD_ON
#define FVM_RESETFLAGBITSIZEOFFRESHNESSVALUELAYOUTINFO                STD_ON
#define FVM_RESETFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO            STD_ON
#define FVM_RESETFLAGENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO      STD_ON
#define FVM_RESETFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO          STD_ON
#define FVM_TRIPFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO             STD_ON
#define FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO                    STD_OFF  /**< Deactivateable: 'FvM_FreshnessValueLayoutInfo.TripFlagSize' Reason: 'the value of FvM_TripFlagSizeOfFreshnessValueLayoutInfo is always '0' due to this, the array is deactivated.' */
#define FVM_TRIPFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO           STD_ON
#define FVM_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'FvM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FVM_INITIALIZED                                               STD_ON
#define FVM_LATESTRESETCOUNTER                                        STD_ON
#define FVM_LATESTTRIPCOUNTER                                         STD_ON
#define FVM_LATESTTRIPCOUNTERWITHOUTRESETCOUNTER                      STD_OFF  /**< Deactivateable: 'FvM_LatestTripCounterWithoutResetCounter' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCNT                        STD_OFF  /**< Deactivateable: 'FvM_ReceptionTimeoutForTransmissionCnt' Reason: 'Reception timeout for transmission is not configured' */
#define FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCOUNTER                    STD_OFF  /**< Deactivateable: 'FvM_ReceptionTimeoutForTransmissionCounter' Reason: 'Reception timeout for transmission is not configured' */
#define FVM_RESETCOUNTERBITSIZE                                       STD_ON
#define FVM_RESETCOUNTERCYCLETIME                                     STD_OFF  /**< Deactivateable: 'FvM_ResetCounterCycleTime' Reason: 'Master ResetCounter Cycle Time is not configured' */
#define FVM_RESETCOUNTERCYCLETIMECOUNTER                              STD_OFF  /**< Deactivateable: 'FvM_ResetCounterCycleTimeCounter' Reason: 'Master ResetCounter Cycle Time is not configured' */
#define FVM_RESETCOUNTERFIRSTBITCOUNT                                 STD_OFF  /**< Deactivateable: 'FvM_ResetCounterFirstBitCount' Reason: 'the value of FvM_ResetCounterFirstBitCount is always '0' due to this, the array is deactivated.' */
#define FVM_RESETCOUNTERLASTBITCOUNT                                  STD_OFF  /**< Deactivateable: 'FvM_ResetCounterLastBitCount' Reason: 'the value of FvM_ResetCounterLastBitCount is always '0' due to this, the array is deactivated.' */
#define FVM_RESETCOUNTERMAX                                           STD_ON
#define FVM_RESETCOUNTERMAXNOTIFICATION                               STD_OFF  /**< Deactivateable: 'FvM_ResetCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_RXFRESHNESSVALUEINFO                                      STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOLATESTIDXOFRXFRESHNESSVALUEINFO   STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFRXFRESHNESSVALUEINFO STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFRXFRESHNESSVALUEINFO STD_ON
#define FVM_INVALIDHNDOFRXFRESHNESSVALUEINFO                          STD_OFF  /**< Deactivateable: 'FvM_RxFreshnessValueInfo.InvalidHnd' Reason: 'the value of FvM_InvalidHndOfRxFreshnessValueInfo is always 'false' due to this, the array is deactivated.' */
#define FVM_MESSAGECOUNTERHIGHBITSINCVALUEOFRXFRESHNESSVALUEINFO      STD_ON
#define FVM_MESSAGECOUNTERLOWERBITSMASKOFRXFRESHNESSVALUEINFO         STD_ON
#define FVM_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO                      STD_ON
#define FVM_RXMESSAGECOUNTERMAXNOTIFICATION                           STD_OFF  /**< Deactivateable: 'FvM_RxMessageCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_RXMESSAGECOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION        STD_OFF  /**< Deactivateable: 'FvM_RxMessageCounterWithoutResetCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_RXTRIPCOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION           STD_OFF  /**< Deactivateable: 'FvM_RxTripCounterWithoutResetCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_SIZEOFFRESHNESSVALUEARRAY                                 STD_ON
#define FVM_SIZEOFFRESHNESSVALUELAYOUTINFO                            STD_ON
#define FVM_SIZEOFRXFRESHNESSVALUEINFO                                STD_ON
#define FVM_SIZEOFTXFRESHNESSVALUEINFO                                STD_ON
#define FVM_SIZEOFTXPROCESSINGINFO                                    STD_ON
#define FVM_STARTUPCYCLECNT                                           STD_ON
#define FVM_STARTUPCYCLECOUNTER                                       STD_ON
#define FVM_SYNCMESSAGERECEPTIONTIMEOUTCNT                            STD_OFF  /**< Deactivateable: 'FvM_SyncMessageReceptionTimeoutCnt' Reason: 'SyncMessage reception timeout not configured' */
#define FVM_SYNCMESSAGERECEPTIONTIMEOUTCOUNTER                        STD_OFF  /**< Deactivateable: 'FvM_SyncMessageReceptionTimeoutCounter' Reason: 'SyncMessage reception timeout not configured' */
#define FVM_SYNCSTATE                                                 STD_OFF  /**< Deactivateable: 'FvM_SyncState' Reason: 'SyncState Not Used.' */
#define FVM_TRIPCOUNTERBITSIZE                                        STD_ON
#define FVM_TRIPCOUNTERMAX                                            STD_ON
#define FVM_TRIPCOUNTERMAXNOTIFICATION                                STD_OFF  /**< Deactivateable: 'FvM_TripCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOR                             STD_ON
#define FVM_TRIPCOUNTERREADERRORDETECTEDFLAG                          STD_OFF  /**< Deactivateable: 'FvM_TripCounterReadErrorDetectedFlag' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERMAX                         STD_OFF  /**< Deactivateable: 'FvM_TripCounterWithoutResetCounterMax' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION             STD_OFF  /**< Deactivateable: 'FvM_TripCounterWithoutResetCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERNVMBLOCKDESCRIPTOR          STD_OFF  /**< Deactivateable: 'FvM_TripCounterWithoutResetCounterNvMBlockDescriptor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERBITSIZE                     STD_OFF  /**< Deactivateable: 'FvM_TripCounterWithoutResetcounterBitSize' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_TXFRESHNESSVALUEINFO                                      STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOLATESTIDXOFTXFRESHNESSVALUEINFO   STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFTXFRESHNESSVALUEINFO STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFTXFRESHNESSVALUEINFO STD_ON
#define FVM_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO                      STD_ON
#define FVM_TXPROCESSINGINFOIDXOFTXFRESHNESSVALUEINFO                 STD_ON
#define FVM_TXMESSAGECOUNTERMAXNOTIFICATION                           STD_OFF  /**< Deactivateable: 'FvM_TxMessageCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_TXMESSAGECOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION        STD_OFF  /**< Deactivateable: 'FvM_TxMessageCounterWithoutResetCounterMaxNotification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define FVM_TXPROCESSINGINFO                                          STD_ON
#define FVM_INVALIDHNDOFTXPROCESSINGINFO                              STD_OFF  /**< Deactivateable: 'FvM_TxProcessingInfo.InvalidHnd' Reason: 'the value of FvM_InvalidHndOfTxProcessingInfo is always 'false' due to this, the array is deactivated.' */
#define FVM_PROCESSINGTYPEOFTXPROCESSINGINFO                          STD_ON
#define FVM_TXFRESHNESSVALUEINFOIDXOFTXPROCESSINGINFO                 STD_ON
#define FVM_TXFRESHNESSVALUEINFOUSEDOFTXPROCESSINGINFO                STD_ON
#define FVM_PCCONFIG                                                  STD_ON
#define FVM_CLEARACCEPTANCEWINDOWOFPCCONFIG                           STD_ON
#define FVM_CLEARACCEPTANCEWINDOWWITHOUTRESETCOUNTEROFPCCONFIG        STD_OFF  /**< Deactivateable: 'FvM_PCConfig.ClearAcceptanceWindowWithoutResetCounter' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_DEVMODEENABLEDOFPCCONFIG                                  STD_ON
#define FVM_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'FvM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define FVM_FRESHNESSVALUEARRAYOFPCCONFIG                             STD_ON
#define FVM_FRESHNESSVALUELAYOUTINFOOFPCCONFIG                        STD_ON
#define FVM_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'FvM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define FVM_INITIALIZEDOFPCCONFIG                                     STD_ON
#define FVM_LATESTRESETCOUNTEROFPCCONFIG                              STD_ON
#define FVM_LATESTTRIPCOUNTEROFPCCONFIG                               STD_ON
#define FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCNTOFPCCONFIG              STD_OFF  /**< Deactivateable: 'FvM_PCConfig.ReceptionTimeoutForTransmissionCnt' Reason: 'Reception timeout for transmission is not configured' */
#define FVM_RESETCOUNTERBITSIZEOFPCCONFIG                             STD_ON
#define FVM_RESETCOUNTERCYCLETIMEOFPCCONFIG                           STD_OFF  /**< Deactivateable: 'FvM_PCConfig.ResetCounterCycleTime' Reason: 'Master ResetCounter Cycle Time is not configured' */
#define FVM_RESETCOUNTERFIRSTBITCOUNTOFPCCONFIG                       STD_OFF  /**< Deactivateable: 'FvM_PCConfig.ResetCounterFirstBitCount' Reason: 'the value of FvM_ResetCounterFirstBitCountOfPCConfig is always '0' due to this, the array is deactivated.' */
#define FVM_RESETCOUNTERLASTBITCOUNTOFPCCONFIG                        STD_OFF  /**< Deactivateable: 'FvM_PCConfig.ResetCounterLastBitCount' Reason: 'the value of FvM_ResetCounterLastBitCountOfPCConfig is always '0' due to this, the array is deactivated.' */
#define FVM_RESETCOUNTERMAXOFPCCONFIG                                 STD_ON
#define FVM_RXFRESHNESSVALUEINFOOFPCCONFIG                            STD_ON
#define FVM_SIZEOFFRESHNESSVALUEARRAYOFPCCONFIG                       STD_ON
#define FVM_SIZEOFFRESHNESSVALUELAYOUTINFOOFPCCONFIG                  STD_ON
#define FVM_SIZEOFRXFRESHNESSVALUEINFOOFPCCONFIG                      STD_ON
#define FVM_SIZEOFTXFRESHNESSVALUEINFOOFPCCONFIG                      STD_ON
#define FVM_SIZEOFTXPROCESSINGINFOOFPCCONFIG                          STD_ON
#define FVM_STARTUPCYCLECNTOFPCCONFIG                                 STD_ON
#define FVM_STARTUPCYCLECOUNTEROFPCCONFIG                             STD_ON
#define FVM_SYNCMESSAGERECEPTIONTIMEOUTCNTOFPCCONFIG                  STD_OFF  /**< Deactivateable: 'FvM_PCConfig.SyncMessageReceptionTimeoutCnt' Reason: 'SyncMessage reception timeout not configured' */
#define FVM_TRIPCOUNTERBITSIZEOFPCCONFIG                              STD_ON
#define FVM_TRIPCOUNTERMAXOFPCCONFIG                                  STD_ON
#define FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOROFPCCONFIG                   STD_ON
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERMAXOFPCCONFIG               STD_OFF  /**< Deactivateable: 'FvM_PCConfig.TripCounterWithoutResetCounterMax' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_TRIPCOUNTERWITHOUTRESETCOUNTERBITSIZEOFPCCONFIG           STD_OFF  /**< Deactivateable: 'FvM_PCConfig.TripCounterWithoutResetcounterBitSize' Reason: 'Jaspar without Reset Counter Use Case not active.' */
#define FVM_TXFRESHNESSVALUEINFOOFPCCONFIG                            STD_ON
#define FVM_TXPROCESSINGINFOOFPCCONFIG                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCMinNumericValueDefines  FvM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define FVM_MIN_FRESHNESSVALUEARRAY                                   0u
#define FVM_MIN_LATESTRESETCOUNTER                                    0u
#define FVM_MIN_LATESTTRIPCOUNTER                                     0u
#define FVM_MIN_STARTUPCYCLECOUNTER                                   0u
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCMaxNumericValueDefines  FvM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define FVM_MAX_FRESHNESSVALUEARRAY                                   255u
#define FVM_MAX_LATESTRESETCOUNTER                                    18446744073709551615u
#define FVM_MAX_LATESTTRIPCOUNTER                                     4294967295u
#define FVM_MAX_STARTUPCYCLECOUNTER                                   65535u
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCNoReferenceDefines  FvM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define FVM_NO_FRESHNESSVALUEARRAYMESSAGECOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYMESSAGECOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYRESETCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYRESETCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYRESETFLAGIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEENDIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUESTARTIDXOFFRESHNESSVALUELAYOUTINFO 65535u
#define FVM_NO_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFRXFRESHNESSVALUEINFO 255u
#define FVM_NO_TRIPCOUNTERNVMBLOCKDESCRIPTOR                          255u
#define FVM_NO_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFTXFRESHNESSVALUEINFO 255u
#define FVM_NO_TXFRESHNESSVALUEINFOIDXOFTXPROCESSINGINFO              255u
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCEnumExistsDefines  FvM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO STD_ON
#define FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO STD_ON
#define FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO STD_OFF
#define FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO STD_ON
#define FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO STD_OFF
#define FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO STD_OFF
#define FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXPROCESSINGINFO  STD_ON
#define FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFTXPROCESSINGINFO STD_OFF
#define FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXPROCESSINGINFO STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCEnumDefines  FvM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO     0x00u
#define FVM_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO 0x01u
#define FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO     0x00u
#define FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXPROCESSINGINFO         0x00u
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCIsReducedToDefineDefines  FvM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define FVM_ISDEF_ENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO         STD_ON
#define FVM_ISDEF_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSENDIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSLENGTHOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYMESSAGECOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYMESSAGECOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYMESSAGECOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYMESSAGECOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETCOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETFLAGIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYRESETFLAGUSEDOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRIPCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRIPCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRIPCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEENDIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUELENGTHOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUESTARTIDXOFFRESHNESSVALUELAYOUTINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEUSEDOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_MESSAGECOUNTERBITSIZEOFFRESHNESSVALUELAYOUTINFO     STD_ON
#define FVM_ISDEF_MESSAGECOUNTERMAXVALUEOFFRESHNESSVALUELAYOUTINFO    STD_ON
#define FVM_ISDEF_RESETFLAGBITSIZEOFFRESHNESSVALUELAYOUTINFO          STD_ON
#define FVM_ISDEF_RESETFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO      STD_OFF
#define FVM_ISDEF_RESETFLAGENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO STD_ON
#define FVM_ISDEF_RESETFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO    STD_OFF
#define FVM_ISDEF_TRIPFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO       STD_ON
#define FVM_ISDEF_TRIPFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO     STD_ON
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOLATESTIDXOFRXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFRXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFRXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_MESSAGECOUNTERHIGHBITSINCVALUEOFRXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_MESSAGECOUNTERLOWERBITSMASKOFRXFRESHNESSVALUEINFO   STD_OFF
#define FVM_ISDEF_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO                STD_OFF
#define FVM_ISDEF_TRIPCOUNTERNVMBLOCKDESCRIPTOR                       STD_ON
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOLATESTIDXOFTXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFTXFRESHNESSVALUEINFO STD_OFF
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFTXFRESHNESSVALUEINFO STD_ON
#define FVM_ISDEF_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO                STD_ON
#define FVM_ISDEF_TXPROCESSINGINFOIDXOFTXFRESHNESSVALUEINFO           STD_OFF
#define FVM_ISDEF_PROCESSINGTYPEOFTXPROCESSINGINFO                    STD_ON
#define FVM_ISDEF_TXFRESHNESSVALUEINFOIDXOFTXPROCESSINGINFO           STD_OFF
#define FVM_ISDEF_TXFRESHNESSVALUEINFOUSEDOFTXPROCESSINGINFO          STD_ON
#define FVM_ISDEF_DEVMODEENABLEDOFPCCONFIG                            STD_ON
#define FVM_ISDEF_FRESHNESSVALUEARRAYOFPCCONFIG                       STD_ON
#define FVM_ISDEF_FRESHNESSVALUELAYOUTINFOOFPCCONFIG                  STD_ON
#define FVM_ISDEF_INITIALIZEDOFPCCONFIG                               STD_ON
#define FVM_ISDEF_LATESTRESETCOUNTEROFPCCONFIG                        STD_ON
#define FVM_ISDEF_LATESTTRIPCOUNTEROFPCCONFIG                         STD_ON
#define FVM_ISDEF_RXFRESHNESSVALUEINFOOFPCCONFIG                      STD_ON
#define FVM_ISDEF_STARTUPCYCLECOUNTEROFPCCONFIG                       STD_ON
#define FVM_ISDEF_TRIPCOUNTERNVMBLOCKDESCRIPTOROFPCCONFIG             STD_ON
#define FVM_ISDEF_TXFRESHNESSVALUEINFOOFPCCONFIG                      STD_ON
#define FVM_ISDEF_TXPROCESSINGINFOOFPCCONFIG                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCEqualsAlwaysToDefines  FvM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define FVM_EQ2_ENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO           0u
#define FVM_EQ2_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSENDIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSLENGTHOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYCOMPLETEFRESHNESSSTARTIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYMESSAGECOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYMESSAGECOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYMESSAGECOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYMESSAGECOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO 2u
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETCOUNTERUSEDOFFRESHNESSVALUELAYOUTINFO TRUE
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETFLAGIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYRESETFLAGUSEDOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRIPCOUNTERENDIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRIPCOUNTERLENGTHOFFRESHNESSVALUELAYOUTINFO 3u
#define FVM_EQ2_FRESHNESSVALUEARRAYTRIPCOUNTERSTARTIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEENDIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUELENGTHOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUESTARTIDXOFFRESHNESSVALUELAYOUTINFO 
#define FVM_EQ2_FRESHNESSVALUEARRAYTRUNCATEDFRESHNESSVALUEUSEDOFFRESHNESSVALUELAYOUTINFO TRUE
#define FVM_EQ2_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO 6u
#define FVM_EQ2_MESSAGECOUNTERBITSIZEOFFRESHNESSVALUELAYOUTINFO       22u
#define FVM_EQ2_MESSAGECOUNTERMAXVALUEOFFRESHNESSVALUELAYOUTINFO      4194303u
#define FVM_EQ2_RESETFLAGBITSIZEOFFRESHNESSVALUELAYOUTINFO            2u
#define FVM_EQ2_RESETFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO        
#define FVM_EQ2_RESETFLAGENDPADDINGBITSIZEOFFRESHNESSVALUELAYOUTINFO  0u
#define FVM_EQ2_RESETFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO      
#define FVM_EQ2_TRIPFLAGCOPYBITMASKOFFRESHNESSVALUELAYOUTINFO         0u
#define FVM_EQ2_TRIPFLAGUNUSEDBITMASKOFFRESHNESSVALUELAYOUTINFO       0u
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOLATESTIDXOFRXFRESHNESSVALUEINFO 
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFRXFRESHNESSVALUEINFO 
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFRXFRESHNESSVALUEINFO 
#define FVM_EQ2_MESSAGECOUNTERHIGHBITSINCVALUEOFRXFRESHNESSVALUEINFO  
#define FVM_EQ2_MESSAGECOUNTERLOWERBITSMASKOFRXFRESHNESSVALUEINFO     
#define FVM_EQ2_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO                  
#define FVM_EQ2_TRIPCOUNTERNVMBLOCKDESCRIPTOR                         NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOLATESTIDXOFTXFRESHNESSVALUEINFO 
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFTXFRESHNESSVALUEINFO 
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOPREVIOUSUSEDOFTXFRESHNESSVALUEINFO TRUE
#define FVM_EQ2_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO                  FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO
#define FVM_EQ2_TXPROCESSINGINFOIDXOFTXFRESHNESSVALUEINFO             
#define FVM_EQ2_PROCESSINGTYPEOFTXPROCESSINGINFO                      FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXPROCESSINGINFO
#define FVM_EQ2_TXFRESHNESSVALUEINFOIDXOFTXPROCESSINGINFO             
#define FVM_EQ2_TXFRESHNESSVALUEINFOUSEDOFTXPROCESSINGINFO            TRUE
#define FVM_EQ2_DEVMODEENABLEDOFPCCONFIG                              (&(FvM_DevModeEnabled))
#define FVM_EQ2_FRESHNESSVALUEARRAYOFPCCONFIG                         FvM_FreshnessValueArray
#define FVM_EQ2_FRESHNESSVALUELAYOUTINFOOFPCCONFIG                    FvM_FreshnessValueLayoutInfo
#define FVM_EQ2_INITIALIZEDOFPCCONFIG                                 (&(FvM_Initialized))
#define FVM_EQ2_LATESTRESETCOUNTEROFPCCONFIG                          (&(FvM_LatestResetCounter))
#define FVM_EQ2_LATESTTRIPCOUNTEROFPCCONFIG                           (&(FvM_LatestTripCounter))
#define FVM_EQ2_RXFRESHNESSVALUEINFOOFPCCONFIG                        FvM_RxFreshnessValueInfo
#define FVM_EQ2_STARTUPCYCLECOUNTEROFPCCONFIG                         (&(FvM_StartUpCycleCounter))
#define FVM_EQ2_TRIPCOUNTERNVMBLOCKDESCRIPTOROFPCCONFIG               FvM_TripCounterNvMBlockDescriptor
#define FVM_EQ2_TXFRESHNESSVALUEINFOOFPCCONFIG                        FvM_TxFreshnessValueInfo
#define FVM_EQ2_TXPROCESSINGINFOOFPCCONFIG                            FvM_TxProcessingInfo
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCSymbolicInitializationPointers  FvM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define FvM_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'FvM' */
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCInitializationSymbols  FvM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define FvM_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'FvM */
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCGeneral  FvM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define FVM_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define FVM_FINAL_MAGIC_NUMBER                                        0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of FvM */
#define FVM_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'FvM' is not configured to be postbuild capable. */
#define FVM_INIT_DATA                                                 FVM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define FVM_INIT_DATA_HASH_CODE                                       1227920125  /**< the precompile constant to validate the initialization structure at initialization time of FvM with a hashcode. The seed value is '0xFF1Eu' */
#define FVM_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define FVM_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer FvM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FvMLTDataSwitches  FvM Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define FVM_LTCONFIG                                                  STD_OFF  /**< Deactivateable: 'FvM_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 




/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  FvMPCGetConstantDuplicatedRootDataMacros  FvM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define FvM_GetClearAcceptanceWindowOfPCConfig()                      3u
#define FvM_GetDevModeEnabledOfPCConfig()                             (&(FvM_DevModeEnabled))  /**< the pointer to FvM_DevModeEnabled */
#define FvM_GetFreshnessValueArrayOfPCConfig()                        FvM_FreshnessValueArray  /**< the pointer to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueLayoutInfoOfPCConfig()                   FvM_FreshnessValueLayoutInfo  /**< the pointer to FvM_FreshnessValueLayoutInfo */
#define FvM_GetInitializedOfPCConfig()                                (&(FvM_Initialized))  /**< the pointer to FvM_Initialized */
#define FvM_GetLatestResetCounterOfPCConfig()                         (&(FvM_LatestResetCounter))  /**< the pointer to FvM_LatestResetCounter */
#define FvM_GetLatestTripCounterOfPCConfig()                          (&(FvM_LatestTripCounter))  /**< the pointer to FvM_LatestTripCounter */
#define FvM_GetResetCounterBitSizeOfPCConfig()                        16u
#define FvM_GetResetCounterMaxOfPCConfig()                            65535u
#define FvM_GetRxFreshnessValueInfoOfPCConfig()                       FvM_RxFreshnessValueInfo  /**< the pointer to FvM_RxFreshnessValueInfo */
#define FvM_GetSizeOfFreshnessValueArrayOfPCConfig()                  261u  /**< the number of accomplishable value elements in FvM_FreshnessValueArray */
#define FvM_GetSizeOfFreshnessValueLayoutInfoOfPCConfig()             33u  /**< the number of accomplishable value elements in FvM_FreshnessValueLayoutInfo */
#define FvM_GetSizeOfRxFreshnessValueInfoOfPCConfig()                 14u  /**< the number of accomplishable value elements in FvM_RxFreshnessValueInfo */
#define FvM_GetSizeOfTxFreshnessValueInfoOfPCConfig()                 3u  /**< the number of accomplishable value elements in FvM_TxFreshnessValueInfo */
#define FvM_GetSizeOfTxProcessingInfoOfPCConfig()                     3u  /**< the number of accomplishable value elements in FvM_TxProcessingInfo */
#define FvM_GetStartUpCycleCntOfPCConfig()                            1u
#define FvM_GetStartUpCycleCounterOfPCConfig()                        (&(FvM_StartUpCycleCounter))  /**< the pointer to FvM_StartUpCycleCounter */
#define FvM_GetTripCounterBitSizeOfPCConfig()                         24u
#define FvM_GetTripCounterMaxOfPCConfig()                             16777215u
#define FvM_GetTripCounterNvMBlockDescriptorOfPCConfig()              FvM_TripCounterNvMBlockDescriptor  /**< the pointer to FvM_TripCounterNvMBlockDescriptor */
#define FvM_GetTxFreshnessValueInfoOfPCConfig()                       FvM_TxFreshnessValueInfo  /**< the pointer to FvM_TxFreshnessValueInfo */
#define FvM_GetTxProcessingInfoOfPCConfig()                           FvM_TxProcessingInfo  /**< the pointer to FvM_TxProcessingInfo */
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCGetDataMacros  FvM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define FvM_IsDevModeEnabled()                                        (((*(FvM_GetDevModeEnabledOfPCConfig()))) != FALSE)
#define FvM_GetFreshnessValueArray(Index)                             (FvM_GetFreshnessValueArrayOfPCConfig()[(Index)])
#define FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo)
#define FvM_IsFreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo(Index) ((FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo) != FALSE)
#define FvM_GetFreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo)
#define FvM_GetFreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].FreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo)
#define FvM_GetResetFlagCopyBitMaskOfFreshnessValueLayoutInfo(Index)  (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].ResetFlagCopyBitMaskOfFreshnessValueLayoutInfo)
#define FvM_GetResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo(Index) (FvM_GetFreshnessValueLayoutInfoOfPCConfig()[(Index)].ResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo)
#define FvM_IsInitialized()                                           (((*(FvM_GetInitializedOfPCConfig()))) != FALSE)
#define FvM_GetLatestResetCounter()                                   ((*(FvM_GetLatestResetCounterOfPCConfig())))
#define FvM_GetLatestTripCounter()                                    ((*(FvM_GetLatestTripCounterOfPCConfig())))
#define FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(Index) (FvM_GetRxFreshnessValueInfoOfPCConfig()[(Index)].FreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo)
#define FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(Index) (FvM_GetRxFreshnessValueInfoOfPCConfig()[(Index)].FreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo)
#define FvM_GetMessageCounterHighBitsIncValueOfRxFreshnessValueInfo(Index) (FvM_GetRxFreshnessValueInfoOfPCConfig()[(Index)].MessageCounterHighBitsIncValueOfRxFreshnessValueInfo)
#define FvM_GetMessageCounterLowerBitsMaskOfRxFreshnessValueInfo(Index) (FvM_GetRxFreshnessValueInfoOfPCConfig()[(Index)].MessageCounterLowerBitsMaskOfRxFreshnessValueInfo)
#define FvM_GetProcessingTypeOfRxFreshnessValueInfo(Index)            (FvM_GetRxFreshnessValueInfoOfPCConfig()[(Index)].ProcessingTypeOfRxFreshnessValueInfo)
#define FvM_GetStartUpCycleCounter()                                  ((*(FvM_GetStartUpCycleCounterOfPCConfig())))
#define FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(Index) (FvM_GetTxFreshnessValueInfoOfPCConfig()[(Index)].FreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo)
#define FvM_GetFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo(Index) (FvM_GetTxFreshnessValueInfoOfPCConfig()[(Index)].FreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo)
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCGetDeduplicatedDataMacros  FvM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define FvM_GetClearAcceptanceWindow()                                FvM_GetClearAcceptanceWindowOfPCConfig()
#define FvM_GetEndPaddingBitSizeOfFreshnessValueLayoutInfo(Index)     0u
#define FvM_GetFreshnessValueArrayCompleteFreshnessEndIdxOfFreshnessValueLayoutInfo(Index) FvM_GetFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo(Index)  /**< the end index of the 1:n relation pointing to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(Index) FvM_GetFreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo(Index)  /**< the start index of the 1:n relation pointing to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueArrayMessageCounterLengthOfFreshnessValueLayoutInfo(Index) FvM_GetResetFlagCopyBitMaskOfFreshnessValueLayoutInfo(Index)  /**< the number of relations pointing to FvM_FreshnessValueArray */
#define FvM_IsFreshnessValueArrayMessageCounterUsedOfFreshnessValueLayoutInfo(Index) FvM_IsFreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueArrayResetCounterLengthOfFreshnessValueLayoutInfo(Index) 2u  /**< the number of relations pointing to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfo(Index) FvM_GetFreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo(Index)  /**< the start index of the 0:n relation pointing to FvM_FreshnessValueArray */
#define FvM_IsFreshnessValueArrayResetCounterUsedOfFreshnessValueLayoutInfo(Index) (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to FvM_FreshnessValueArray */
#define FvM_GetFreshnessValueArrayTripCounterLengthOfFreshnessValueLayoutInfo(Index) 3u  /**< the number of relations pointing to FvM_FreshnessValueArray */
#define FvM_IsFreshnessValueArrayTruncatedFreshnessValueUsedOfFreshnessValueLayoutInfo(Index) (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to FvM_FreshnessValueArray */
#define FvM_GetLastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(Index) 6u
#define FvM_GetMessageCounterBitSizeOfFreshnessValueLayoutInfo(Index) 22u
#define FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(Index) 4194303u
#define FvM_GetResetFlagBitSizeOfFreshnessValueLayoutInfo(Index)      2u
#define FvM_GetResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfo(Index) 0u
#define FvM_GetTripFlagCopyBitMaskOfFreshnessValueLayoutInfo(Index)   0u
#define FvM_GetTripFlagUnUsedBitMaskOfFreshnessValueLayoutInfo(Index) 0u
#define FvM_GetResetCounterBitSize()                                  FvM_GetResetCounterBitSizeOfPCConfig()
#define FvM_GetResetCounterMax()                                      FvM_GetResetCounterMaxOfPCConfig()
#define FvM_IsFreshnessValueLayoutInfoPreviousUsedOfRxFreshnessValueInfo(Index) (((boolean)(FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(Index) != FVM_NO_FRESHNESSVALUELAYOUTINFOPREVIOUSIDXOFRXFRESHNESSVALUEINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to FvM_FreshnessValueLayoutInfo */
#define FvM_GetSizeOfFreshnessValueArray()                            FvM_GetSizeOfFreshnessValueArrayOfPCConfig()
#define FvM_GetSizeOfFreshnessValueLayoutInfo()                       FvM_GetSizeOfFreshnessValueLayoutInfoOfPCConfig()
#define FvM_GetSizeOfRxFreshnessValueInfo()                           FvM_GetSizeOfRxFreshnessValueInfoOfPCConfig()
#define FvM_GetSizeOfTxFreshnessValueInfo()                           FvM_GetSizeOfTxFreshnessValueInfoOfPCConfig()
#define FvM_GetSizeOfTxProcessingInfo()                               FvM_GetSizeOfTxProcessingInfoOfPCConfig()
#define FvM_GetStartUpCycleCnt()                                      FvM_GetStartUpCycleCntOfPCConfig()
#define FvM_GetTripCounterBitSize()                                   FvM_GetTripCounterBitSizeOfPCConfig()
#define FvM_GetTripCounterMax()                                       FvM_GetTripCounterMaxOfPCConfig()
#define FvM_GetTripCounterNvMBlockDescriptor(Index)                   NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount
#define FvM_IsFreshnessValueLayoutInfoPreviousUsedOfTxFreshnessValueInfo(Index) (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to FvM_FreshnessValueLayoutInfo */
#define FvM_GetProcessingTypeOfTxFreshnessValueInfo(Index)            FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO
#define FvM_GetTxProcessingInfoIdxOfTxFreshnessValueInfo(Index)       ((FvM_TxProcessingInfoIdxOfTxFreshnessValueInfoType)((Index)))  /**< the index of the 1:1 relation pointing to FvM_TxProcessingInfo */
#define FvM_GetProcessingTypeOfTxProcessingInfo(Index)                FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXPROCESSINGINFO
#define FvM_GetTxFreshnessValueInfoIdxOfTxProcessingInfo(Index)       ((FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType)((Index)))  /**< the index of the 0:1 relation pointing to FvM_TxFreshnessValueInfo */
#define FvM_IsTxFreshnessValueInfoUsedOfTxProcessingInfo(Index)       (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to FvM_TxFreshnessValueInfo */
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCSetDataMacros  FvM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define FvM_SetDevModeEnabled(Value)                                  (*(FvM_GetDevModeEnabledOfPCConfig())) = (Value)
#define FvM_SetFreshnessValueArray(Index, Value)                      FvM_GetFreshnessValueArrayOfPCConfig()[(Index)] = (Value)
#define FvM_SetInitialized(Value)                                     (*(FvM_GetInitializedOfPCConfig())) = (Value)
#define FvM_SetLatestResetCounter(Value)                              (*(FvM_GetLatestResetCounterOfPCConfig())) = (Value)
#define FvM_SetLatestTripCounter(Value)                               (*(FvM_GetLatestTripCounterOfPCConfig())) = (Value)
#define FvM_SetStartUpCycleCounter(Value)                             (*(FvM_GetStartUpCycleCounterOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCGetAddressOfDataMacros  FvM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define FvM_GetAddrFreshnessValueArray(Index)                         (&FvM_GetFreshnessValueArray(Index))
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCHasMacros  FvM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define FvM_HasClearAcceptanceWindow()                                (TRUE != FALSE)
#define FvM_HasDevModeEnabled()                                       (TRUE != FALSE)
#define FvM_HasFreshnessValueArray()                                  (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfo()                             (TRUE != FALSE)
#define FvM_HasEndPaddingBitSizeOfFreshnessValueLayoutInfo()          (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayCompleteFreshnessEndIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayMessageCounterLengthOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayMessageCounterUsedOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetCounterLengthOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetCounterUsedOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTripCounterLengthOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayTruncatedFreshnessValueUsedOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasLastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasMessageCounterBitSizeOfFreshnessValueLayoutInfo()      (TRUE != FALSE)
#define FvM_HasMessageCounterMaxValueOfFreshnessValueLayoutInfo()     (TRUE != FALSE)
#define FvM_HasResetFlagBitSizeOfFreshnessValueLayoutInfo()           (TRUE != FALSE)
#define FvM_HasResetFlagCopyBitMaskOfFreshnessValueLayoutInfo()       (TRUE != FALSE)
#define FvM_HasResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfo() (TRUE != FALSE)
#define FvM_HasResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo()     (TRUE != FALSE)
#define FvM_HasTripFlagCopyBitMaskOfFreshnessValueLayoutInfo()        (TRUE != FALSE)
#define FvM_HasTripFlagUnUsedBitMaskOfFreshnessValueLayoutInfo()      (TRUE != FALSE)
#define FvM_HasInitialized()                                          (TRUE != FALSE)
#define FvM_HasLatestResetCounter()                                   (TRUE != FALSE)
#define FvM_HasLatestTripCounter()                                    (TRUE != FALSE)
#define FvM_HasResetCounterBitSize()                                  (TRUE != FALSE)
#define FvM_HasResetCounterMax()                                      (TRUE != FALSE)
#define FvM_HasRxFreshnessValueInfo()                                 (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoPreviousUsedOfRxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasMessageCounterHighBitsIncValueOfRxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasMessageCounterLowerBitsMaskOfRxFreshnessValueInfo()    (TRUE != FALSE)
#define FvM_HasProcessingTypeOfRxFreshnessValueInfo()                 (TRUE != FALSE)
#define FvM_HasSizeOfFreshnessValueArray()                            (TRUE != FALSE)
#define FvM_HasSizeOfFreshnessValueLayoutInfo()                       (TRUE != FALSE)
#define FvM_HasSizeOfRxFreshnessValueInfo()                           (TRUE != FALSE)
#define FvM_HasSizeOfTxFreshnessValueInfo()                           (TRUE != FALSE)
#define FvM_HasSizeOfTxProcessingInfo()                               (TRUE != FALSE)
#define FvM_HasStartUpCycleCnt()                                      (TRUE != FALSE)
#define FvM_HasStartUpCycleCounter()                                  (TRUE != FALSE)
#define FvM_HasTripCounterBitSize()                                   (TRUE != FALSE)
#define FvM_HasTripCounterMax()                                       (TRUE != FALSE)
#define FvM_HasTripCounterNvMBlockDescriptor()                        (TRUE != FALSE)
#define FvM_HasTxFreshnessValueInfo()                                 (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoPreviousUsedOfTxFreshnessValueInfo() (TRUE != FALSE)
#define FvM_HasProcessingTypeOfTxFreshnessValueInfo()                 (TRUE != FALSE)
#define FvM_HasTxProcessingInfoIdxOfTxFreshnessValueInfo()            (TRUE != FALSE)
#define FvM_HasTxProcessingInfo()                                     (TRUE != FALSE)
#define FvM_HasProcessingTypeOfTxProcessingInfo()                     (TRUE != FALSE)
#define FvM_HasTxFreshnessValueInfoIdxOfTxProcessingInfo()            (TRUE != FALSE)
#define FvM_HasTxFreshnessValueInfoUsedOfTxProcessingInfo()           (TRUE != FALSE)
#define FvM_HasPCConfig()                                             (TRUE != FALSE)
#define FvM_HasClearAcceptanceWindowOfPCConfig()                      (TRUE != FALSE)
#define FvM_HasDevModeEnabledOfPCConfig()                             (TRUE != FALSE)
#define FvM_HasFreshnessValueArrayOfPCConfig()                        (TRUE != FALSE)
#define FvM_HasFreshnessValueLayoutInfoOfPCConfig()                   (TRUE != FALSE)
#define FvM_HasInitializedOfPCConfig()                                (TRUE != FALSE)
#define FvM_HasLatestResetCounterOfPCConfig()                         (TRUE != FALSE)
#define FvM_HasLatestTripCounterOfPCConfig()                          (TRUE != FALSE)
#define FvM_HasResetCounterBitSizeOfPCConfig()                        (TRUE != FALSE)
#define FvM_HasResetCounterMaxOfPCConfig()                            (TRUE != FALSE)
#define FvM_HasRxFreshnessValueInfoOfPCConfig()                       (TRUE != FALSE)
#define FvM_HasSizeOfFreshnessValueArrayOfPCConfig()                  (TRUE != FALSE)
#define FvM_HasSizeOfFreshnessValueLayoutInfoOfPCConfig()             (TRUE != FALSE)
#define FvM_HasSizeOfRxFreshnessValueInfoOfPCConfig()                 (TRUE != FALSE)
#define FvM_HasSizeOfTxFreshnessValueInfoOfPCConfig()                 (TRUE != FALSE)
#define FvM_HasSizeOfTxProcessingInfoOfPCConfig()                     (TRUE != FALSE)
#define FvM_HasStartUpCycleCntOfPCConfig()                            (TRUE != FALSE)
#define FvM_HasStartUpCycleCounterOfPCConfig()                        (TRUE != FALSE)
#define FvM_HasTripCounterBitSizeOfPCConfig()                         (TRUE != FALSE)
#define FvM_HasTripCounterMaxOfPCConfig()                             (TRUE != FALSE)
#define FvM_HasTripCounterNvMBlockDescriptorOfPCConfig()              (TRUE != FALSE)
#define FvM_HasTxFreshnessValueInfoOfPCConfig()                       (TRUE != FALSE)
#define FvM_HasTxProcessingInfoOfPCConfig()                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCIncrementDataMacros  FvM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define FvM_IncFreshnessValueArray(Index)                             FvM_GetFreshnessValueArray(Index)++
#define FvM_IncLatestResetCounter()                                   FvM_GetLatestResetCounter()++
#define FvM_IncLatestTripCounter()                                    FvM_GetLatestTripCounter()++
#define FvM_IncStartUpCycleCounter()                                  FvM_GetStartUpCycleCounter()++
/** 
  \}
*/ 

/** 
  \defgroup  FvMPCDecrementDataMacros  FvM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define FvM_DecFreshnessValueArray(Index)                             FvM_GetFreshnessValueArray(Index)--
#define FvM_DecLatestResetCounter()                                   FvM_GetLatestResetCounter()--
#define FvM_DecLatestTripCounter()                                    FvM_GetLatestTripCounter()--
#define FvM_DecStartUpCycleCounter()                                  FvM_GetStartUpCycleCounter()--
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FvMPCIterableTypes  FvM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate FvM_FreshnessValueArray */
typedef uint16_least FvM_FreshnessValueArrayIterType;

/**   \brief  type used to iterate FvM_FreshnessValueLayoutInfo */
typedef uint8_least FvM_FreshnessValueLayoutInfoIterType;

/**   \brief  type used to iterate FvM_RxFreshnessValueInfo */
typedef uint8_least FvM_RxFreshnessValueInfoIterType;

/**   \brief  type used to iterate FvM_TripCounterNvMBlockDescriptor */
typedef uint8_least FvM_TripCounterNvMBlockDescriptorIterType;

/**   \brief  type used to iterate FvM_TxFreshnessValueInfo */
typedef uint8_least FvM_TxFreshnessValueInfoIterType;

/**   \brief  type used to iterate FvM_TxProcessingInfo */
typedef uint8_least FvM_TxProcessingInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  FvMPCValueTypes  FvM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for FvM_ClearAcceptanceWindow */
typedef uint8 FvM_ClearAcceptanceWindowType;

/**   \brief  value based type definition for FvM_DevModeEnabled */
typedef boolean FvM_DevModeEnabledType;

/**   \brief  value based type definition for FvM_FreshnessValueArray */
typedef uint8 FvM_FreshnessValueArrayType;

/**   \brief  value based type definition for FvM_EndPaddingBitSizeOfFreshnessValueLayoutInfo */
typedef uint8 FvM_EndPaddingBitSizeOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayCompleteFreshnessEndIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayCompleteFreshnessEndIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo */
typedef uint8 FvM_FreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayMessageCounterLengthOfFreshnessValueLayoutInfo */
typedef uint8 FvM_FreshnessValueArrayMessageCounterLengthOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayMessageCounterUsedOfFreshnessValueLayoutInfo */
typedef boolean FvM_FreshnessValueArrayMessageCounterUsedOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetCounterLengthOfFreshnessValueLayoutInfo */
typedef uint8 FvM_FreshnessValueArrayResetCounterLengthOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetCounterUsedOfFreshnessValueLayoutInfo */
typedef boolean FvM_FreshnessValueArrayResetCounterUsedOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo */
typedef boolean FvM_FreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTripCounterLengthOfFreshnessValueLayoutInfo */
typedef uint8 FvM_FreshnessValueArrayTripCounterLengthOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo */
typedef uint8 FvM_FreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo */
typedef uint16 FvM_FreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueArrayTruncatedFreshnessValueUsedOfFreshnessValueLayoutInfo */
typedef boolean FvM_FreshnessValueArrayTruncatedFreshnessValueUsedOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_LastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo */
typedef uint8 FvM_LastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfo */
typedef uint8 FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_MessageCounterMaxValueOfFreshnessValueLayoutInfo */
typedef uint32 FvM_MessageCounterMaxValueOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_ResetFlagBitSizeOfFreshnessValueLayoutInfo */
typedef uint8 FvM_ResetFlagBitSizeOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_ResetFlagCopyBitMaskOfFreshnessValueLayoutInfo */
typedef uint8 FvM_ResetFlagCopyBitMaskOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_ResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfo */
typedef uint8 FvM_ResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_ResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo */
typedef uint8 FvM_ResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_TripFlagCopyBitMaskOfFreshnessValueLayoutInfo */
typedef uint8 FvM_TripFlagCopyBitMaskOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_TripFlagUnUsedBitMaskOfFreshnessValueLayoutInfo */
typedef uint8 FvM_TripFlagUnUsedBitMaskOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_Initialized */
typedef boolean FvM_InitializedType;

/**   \brief  value based type definition for FvM_LatestResetCounter */
typedef uint64 FvM_LatestResetCounterType;

/**   \brief  value based type definition for FvM_LatestTripCounter */
typedef uint32 FvM_LatestTripCounterType;

/**   \brief  value based type definition for FvM_ResetCounterBitSize */
typedef uint8 FvM_ResetCounterBitSizeType;

/**   \brief  value based type definition for FvM_ResetCounterMax */
typedef uint16 FvM_ResetCounterMaxType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo */
typedef uint8 FvM_FreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo */
typedef uint8 FvM_FreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoPreviousUsedOfRxFreshnessValueInfo */
typedef boolean FvM_FreshnessValueLayoutInfoPreviousUsedOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_MessageCounterHighBitsIncValueOfRxFreshnessValueInfo */
typedef uint16 FvM_MessageCounterHighBitsIncValueOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_MessageCounterLowerBitsMaskOfRxFreshnessValueInfo */
typedef uint16 FvM_MessageCounterLowerBitsMaskOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_ProcessingTypeOfRxFreshnessValueInfo */
typedef uint8 FvM_ProcessingTypeOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_SizeOfFreshnessValueArray */
typedef uint16 FvM_SizeOfFreshnessValueArrayType;

/**   \brief  value based type definition for FvM_SizeOfFreshnessValueLayoutInfo */
typedef uint8 FvM_SizeOfFreshnessValueLayoutInfoType;

/**   \brief  value based type definition for FvM_SizeOfRxFreshnessValueInfo */
typedef uint8 FvM_SizeOfRxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_SizeOfTxFreshnessValueInfo */
typedef uint8 FvM_SizeOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_SizeOfTxProcessingInfo */
typedef uint8 FvM_SizeOfTxProcessingInfoType;

/**   \brief  value based type definition for FvM_StartUpCycleCnt */
typedef uint8 FvM_StartUpCycleCntType;

/**   \brief  value based type definition for FvM_StartUpCycleCounter */
typedef uint16 FvM_StartUpCycleCounterType;

/**   \brief  value based type definition for FvM_TripCounterBitSize */
typedef uint8 FvM_TripCounterBitSizeType;

/**   \brief  value based type definition for FvM_TripCounterMax */
typedef uint32 FvM_TripCounterMaxType;

/**   \brief  value based type definition for FvM_TripCounterNvMBlockDescriptor */
typedef uint8 FvM_TripCounterNvMBlockDescriptorType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo */
typedef uint8 FvM_FreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo */
typedef uint8 FvM_FreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_FreshnessValueLayoutInfoPreviousUsedOfTxFreshnessValueInfo */
typedef boolean FvM_FreshnessValueLayoutInfoPreviousUsedOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_ProcessingTypeOfTxFreshnessValueInfo */
typedef uint8 FvM_ProcessingTypeOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_TxProcessingInfoIdxOfTxFreshnessValueInfo */
typedef uint8 FvM_TxProcessingInfoIdxOfTxFreshnessValueInfoType;

/**   \brief  value based type definition for FvM_ProcessingTypeOfTxProcessingInfo */
typedef uint8 FvM_ProcessingTypeOfTxProcessingInfoType;

/**   \brief  value based type definition for FvM_TxFreshnessValueInfoIdxOfTxProcessingInfo */
typedef uint8 FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType;

/**   \brief  value based type definition for FvM_TxFreshnessValueInfoUsedOfTxProcessingInfo */
typedef boolean FvM_TxFreshnessValueInfoUsedOfTxProcessingInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  FvMPCStructTypes  FvM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in FvM_FreshnessValueLayoutInfo */
typedef struct sFvM_FreshnessValueLayoutInfoType
{
  FvM_FreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo;  /**< the end index of the 0:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo;  /**< the start index of the 0:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo;  /**< the end index of the 0:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo;  /**< the index of the 0:1 relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo;  /**< the end index of the 1:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo;  /**< the start index of the 1:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo;  /**< the end index of the 0:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfoType FreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo;  /**< the start index of the 0:n relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfoType FreshnessValueArrayResetFlagUsedOfFreshnessValueLayoutInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfoType FreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo;  /**< the number of relations pointing to FvM_FreshnessValueArray */
  FvM_FreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfoType FreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo;  /**< the number of relations pointing to FvM_FreshnessValueArray */
  FvM_ResetFlagCopyBitMaskOfFreshnessValueLayoutInfoType ResetFlagCopyBitMaskOfFreshnessValueLayoutInfo;
  FvM_ResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfoType ResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo;
} FvM_FreshnessValueLayoutInfoType;

/**   \brief  type used in FvM_RxFreshnessValueInfo */
typedef struct sFvM_RxFreshnessValueInfoType
{
  FvM_MessageCounterHighBitsIncValueOfRxFreshnessValueInfoType MessageCounterHighBitsIncValueOfRxFreshnessValueInfo;
  FvM_MessageCounterLowerBitsMaskOfRxFreshnessValueInfoType MessageCounterLowerBitsMaskOfRxFreshnessValueInfo;
  FvM_FreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfoType FreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo;  /**< the index of the 1:1 relation pointing to FvM_FreshnessValueLayoutInfo */
  FvM_FreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfoType FreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo;  /**< the index of the 0:1 relation pointing to FvM_FreshnessValueLayoutInfo */
  FvM_ProcessingTypeOfRxFreshnessValueInfoType ProcessingTypeOfRxFreshnessValueInfo;
} FvM_RxFreshnessValueInfoType;

/**   \brief  type used in FvM_TxFreshnessValueInfo */
typedef struct sFvM_TxFreshnessValueInfoType
{
  FvM_FreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfoType FreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo;  /**< the index of the 1:1 relation pointing to FvM_FreshnessValueLayoutInfo */
  FvM_FreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfoType FreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo;  /**< the index of the 0:1 relation pointing to FvM_FreshnessValueLayoutInfo */
} FvM_TxFreshnessValueInfoType;

/**   \brief  type used in FvM_TxProcessingInfo */
typedef struct sFvM_TxProcessingInfoType
{
  uint8 FvM_TxProcessingInfoNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} FvM_TxProcessingInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  FvMPCRootPointerTypes  FvM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to FvM_DevModeEnabled */
typedef P2VAR(FvM_DevModeEnabledType, TYPEDEF, FVM_VAR_ZERO_INIT) FvM_DevModeEnabledPtrType;

/**   \brief  type used to point to FvM_FreshnessValueArray */
typedef P2VAR(FvM_FreshnessValueArrayType, TYPEDEF, FVM_VAR_NOINIT) FvM_FreshnessValueArrayPtrType;

/**   \brief  type used to point to FvM_FreshnessValueLayoutInfo */
typedef P2CONST(FvM_FreshnessValueLayoutInfoType, TYPEDEF, FVM_CONST) FvM_FreshnessValueLayoutInfoPtrType;

/**   \brief  type used to point to FvM_Initialized */
typedef P2VAR(FvM_InitializedType, TYPEDEF, FVM_VAR_ZERO_INIT) FvM_InitializedPtrType;

/**   \brief  type used to point to FvM_LatestResetCounter */
typedef P2VAR(FvM_LatestResetCounterType, TYPEDEF, FVM_VAR_NOINIT) FvM_LatestResetCounterPtrType;

/**   \brief  type used to point to FvM_LatestTripCounter */
typedef P2VAR(FvM_LatestTripCounterType, TYPEDEF, FVM_VAR_NOINIT) FvM_LatestTripCounterPtrType;

/**   \brief  type used to point to FvM_RxFreshnessValueInfo */
typedef P2CONST(FvM_RxFreshnessValueInfoType, TYPEDEF, FVM_CONST) FvM_RxFreshnessValueInfoPtrType;

/**   \brief  type used to point to FvM_StartUpCycleCounter */
typedef P2VAR(FvM_StartUpCycleCounterType, TYPEDEF, FVM_VAR_NOINIT) FvM_StartUpCycleCounterPtrType;

/**   \brief  type used to point to FvM_TripCounterNvMBlockDescriptor */
typedef P2CONST(FvM_TripCounterNvMBlockDescriptorType, TYPEDEF, FVM_CONST) FvM_TripCounterNvMBlockDescriptorPtrType;

/**   \brief  type used to point to FvM_TxFreshnessValueInfo */
typedef P2CONST(FvM_TxFreshnessValueInfoType, TYPEDEF, FVM_CONST) FvM_TxFreshnessValueInfoPtrType;

/**   \brief  type used to point to FvM_TxProcessingInfo */
typedef P2CONST(FvM_TxProcessingInfoType, TYPEDEF, FVM_CONST) FvM_TxProcessingInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  FvMPCRootValueTypes  FvM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in FvM_PCConfig */
typedef struct sFvM_PCConfigType
{
  uint8 FvM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} FvM_PCConfigType;

typedef FvM_PCConfigType FvM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  FvM_LatestTripCounterWithoutResetCounterInit
**********************************************************************************************************************/

/**********************************************************************************************************************
  FvM_LatestTripCounterInit
**********************************************************************************************************************/
#define FVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FvM_LatestTripCounterType, FVM_CONST) FvM_LatestTripCounterInit;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define FVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  FvM_FreshnessValueLayoutInfo
**********************************************************************************************************************/
/** 
  \var    FvM_FreshnessValueLayoutInfo
  \details
  Element                                               Description
  FreshnessValueArrayMessageCounterEndIdx               the end index of the 0:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayMessageCounterStartIdx             the start index of the 0:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayResetCounterEndIdx                 the end index of the 0:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayResetFlagIdx                       the index of the 0:1 relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayTripCounterEndIdx                  the end index of the 1:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayTripCounterStartIdx                the start index of the 1:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayTruncatedFreshnessValueEndIdx      the end index of the 0:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayTruncatedFreshnessValueStartIdx    the start index of the 0:n relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayResetFlagUsed                      TRUE, if the 0:1 relation has minimum 1 relation pointing to FvM_FreshnessValueArray
  FreshnessValueArrayCompleteFreshnessLength            the number of relations pointing to FvM_FreshnessValueArray
  FreshnessValueArrayTruncatedFreshnessValueLength      the number of relations pointing to FvM_FreshnessValueArray
  ResetFlagCopyBitMask                              
  ResetFlagUnUsedBitMask                            
*/ 
#define FVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FvM_FreshnessValueLayoutInfoType, FVM_CONST) FvM_FreshnessValueLayoutInfo[33];
#define FVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_RxFreshnessValueInfo
**********************************************************************************************************************/
/** 
  \var    FvM_RxFreshnessValueInfo
  \details
  Element                                Description
  MessageCounterHighBitsIncValue     
  MessageCounterLowerBitsMask        
  FreshnessValueLayoutInfoLatestIdx      the index of the 1:1 relation pointing to FvM_FreshnessValueLayoutInfo
  FreshnessValueLayoutInfoPreviousIdx    the index of the 0:1 relation pointing to FvM_FreshnessValueLayoutInfo
  ProcessingType                     
*/ 
#define FVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FvM_RxFreshnessValueInfoType, FVM_CONST) FvM_RxFreshnessValueInfo[14];
#define FVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_TxFreshnessValueInfo
**********************************************************************************************************************/
/** 
  \var    FvM_TxFreshnessValueInfo
  \details
  Element                                Description
  FreshnessValueLayoutInfoLatestIdx      the index of the 1:1 relation pointing to FvM_FreshnessValueLayoutInfo
  FreshnessValueLayoutInfoPreviousIdx    the index of the 0:1 relation pointing to FvM_FreshnessValueLayoutInfo
*/ 
#define FVM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(FvM_TxFreshnessValueInfoType, FVM_CONST) FvM_TxFreshnessValueInfo[3];
#define FVM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_DevModeEnabled
**********************************************************************************************************************/
#define FVM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_DevModeEnabledType, FVM_VAR_ZERO_INIT) FvM_DevModeEnabled;
#define FVM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_FreshnessValueArray
**********************************************************************************************************************/
#define FVM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_FreshnessValueArrayType, FVM_VAR_NOINIT) FvM_FreshnessValueArray[261];
#define FVM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_Initialized
**********************************************************************************************************************/
/** 
  \var    FvM_Initialized
  \brief  Initialization state of FvM. TRUE, if FvM_Init() has been called, else FALSE.
*/ 
#define FVM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_InitializedType, FVM_VAR_ZERO_INIT) FvM_Initialized;
#define FVM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_LatestResetCounter
**********************************************************************************************************************/
#define FVM_START_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_LatestResetCounterType, FVM_VAR_NOINIT) FvM_LatestResetCounter;
#define FVM_STOP_SEC_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_LatestTripCounter
**********************************************************************************************************************/
#define FVM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_LatestTripCounterType, FVM_VAR_NOINIT) FvM_LatestTripCounter;
#define FVM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FvM_StartUpCycleCounter
**********************************************************************************************************************/
#define FVM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(FvM_StartUpCycleCounterType, FVM_VAR_NOINIT) FvM_StartUpCycleCounter;
#define FVM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* FVM_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: FvM_Lcfg.h
**********************************************************************************************************************/

