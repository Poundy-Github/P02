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
 *              File: Com_Cfg.h
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
# include "Com_PBcfg.h"
# include "Com_Cbk.h"
# include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_RH850_1651
#define COM_PROCESSOR_RH850_1651
#endif
#ifndef COM_COMP_GREENHILLS
#define COM_COMP_GREENHILLS
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCDataSwitches  Com Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ACTIVATABLERXCOMIPDUS                                                                   STD_OFF  /**< Deactivateable: 'Com_ActivatableRxComIPdus' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                                                     STD_OFF  /**< Deactivateable: 'Com_ActivatableRxComIPdus.RxPduInfoIdx' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_ACTIVATABLETXCOMIPDUS                                                                   STD_OFF  /**< Deactivateable: 'Com_ActivatableTxComIPdus' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                                                     STD_OFF  /**< Deactivateable: 'Com_ActivatableTxComIPdus.TxPduInfoIdx' Reason: 'Deactivated as OptimizedIPduGroupControl is set to false.' */
#define COM_ALWAYSACTIVERXCOMIPDUS                                                                  STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_RXPDUINFOIDXOFALWAYSACTIVERXCOMIPDUS                                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ALWAYSACTIVETXCOMIPDUS                                                                  STD_ON
#define COM_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                    STD_ON
#define COM_CBKRXTOUTFUNCPTR                                                                        STD_ON
#define COM_CBKRXTOUTFUNCPTRIND                                                                     STD_ON
#define COM_CBKTXACKDEFFUNCPTR                                                                      STD_ON
#define COM_CBKTXACKDEFFUNCPTRIND                                                                   STD_ON
#define COM_CBKTXACKIMFUNCPTR                                                                       STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTRIND                                                                    STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTR                                                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTRIND                                                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRIND                                                                     STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONFIGID                                                                                STD_ON
#define COM_CONSTVALUEARRAYBASED                                                                    STD_ON
#define COM_CONSTVALUEFLOAT32                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT64                                                                       STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT16                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT32                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT8                                                                         STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESS                                                             STD_OFF  /**< Deactivateable: 'Com_ConstValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT16                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT32                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT64                                                                        STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8                                                                         STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CURRENTTXMODE                                                                           STD_ON
#define COM_CYCLETIMECNT                                                                            STD_ON
#define COM_CYCLICSENDREQUEST                                                                       STD_ON
#define COM_DEFERREDGWMAPPINGEVENT                                                                  STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingEvent' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFDEFERREDGWMAPPINGINFO                                                     STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DELAYTIMECNT                                                                            STD_ON
#define COM_DIRECTTRIGGER                                                                           STD_OFF  /**< Deactivateable: 'Com_DirectTrigger' Reason: 'the parameter is only needed if ComEnableMDTForCyclicTransmission is equals FALSE.' */
#define COM_FILTERINFO_FLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT32                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT32                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_FLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT64                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT64                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_SINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT16                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT16                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT16                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT32                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT32                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT32                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT64                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT64                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT64                                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8                                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8                                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8_N                                                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8_N                                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8_N                                                           STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8_N                                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTER                                              STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLD                                            STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTER                                                         STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockCounter' Reason: 'Signal Gateway is not configured.' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLD                                                       STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured.' */
#define COM_GWDESCRIPTIONACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITOFFSETOFGWDESCRIPTIONACCESSINFO                                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_BITSIZEOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitSize' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWSOURCESTARTBITINDEXOFGWDESCRIPTIONACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.GwSourceStartBitIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBIDXOFGWDESCRIPTIONACCESSINFO                                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_RXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKIDXOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKUSEDOFGWDESCRIPTIONACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCEDESCRIPTIONMASKIDXOFGWDESCRIPTIONACCESSINFO                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_SOURCESTARTBYTEPOSITIONOFGWDESCRIPTIONACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceStartBytePosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFGWDESCRIPTIONACCESSINFO                                               STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBIDXOFGWDESCRIPTIONACCESSINFO                                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXBUFFERUBUSEDOFGWDESCRIPTIONACCESSINFO                                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXPDUINFOIDXOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TYPEOFGWDESCRIPTIONACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_VALIDDLCOFGWDESCRIPTIONACCESSINFO                                                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.ValidDlc' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWEVENT                                                                                 STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWEVENTCACHE                                                                            STD_OFF  /**< Deactivateable: 'Com_GwEventCache' Reason: 'No Deferred Description Routings exist' */
#define COM_GWEVENTCACHEINDEX                                                                       STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWGRPSIGMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                                                        STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWGRPSIGMAPPING                                                                STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                                                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                                                         STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                                                            STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWROUTINGTIMEOUTCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_GwRoutingTimeoutCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWSIGGRPMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                                                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                                                STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPIDOFGWSIGGRPMAPPING                                                             STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                                                            STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                                                           STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWSIGMAPPING                                                                   STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWTIMEOUTINFO                                                                           STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_GWROUTINGTIMEOUTFACTOROFGWTIMEOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.GwRoutingTimeoutFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFGWTIMEOUTINFO                                                             STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWTXPDUDESCRIPTIONINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOENDIDXOFGWTXPDUDESCRIPTIONINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWDESCRIPTIONACCESSINFOSTARTIDXOFGWTXPDUDESCRIPTIONINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTION                                                           STD_OFF  /**< Deactivateable: 'Com_HandleRxDeferredGwDescription' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERRED                                                                     STD_ON
#define COM_HANDLETXPDUDEFERRED                                                                     STD_ON
#define COM_IPDUGROUPINFO                                                                           STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                    STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                                  STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                      STD_ON
#define COM_INVALIDHNDOFIPDUGROUPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfIPduGroupInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                       STD_ON
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                     STD_ON
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                         STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                                                             STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                         STD_ON
#define COM_IPDUGROUPSTATE                                                                          STD_ON
#define COM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZED                                                                             STD_ON
#define COM_PDUGRPCNT                                                                               STD_ON
#define COM_PDUGRPVECTOR                                                                            STD_OFF  /**< Deactivateable: 'Com_PduGrpVector' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_REPCNT                                                                                  STD_OFF  /**< Deactivateable: 'Com_RepCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_REPCYCLECNT                                                                             STD_OFF  /**< Deactivateable: 'Com_RepCycleCnt' Reason: 'This array is deactivated, because no transmission mode with repetitions is configured.' */
#define COM_RXACCESSINFO                                                                            STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                                                  STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                                                 STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                                               STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.BufferIdx' Reason: 'the optional indirection is deactivated because BufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_BUFFERUSEDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.BufferUsed' Reason: 'the optional indirection is deactivated because BufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_BUSACCOFRXACCESSINFO                                                                    STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                                                STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                                              STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                       STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO                                       STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                                     STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO                                         STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFRXACCESSINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEENDIDXOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUELENGTHOFRXACCESSINFO                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUESTARTIDXOFRXACCESSINFO                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXACCESSINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWINFOIDXOFRXACCESSINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InitValueIdx' Reason: 'the optional indirection is deactivated because InitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INITVALUEUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InitValueUsed' Reason: 'the optional indirection is deactivated because InitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEIDXOFRXACCESSINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXACCESSINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ISGROUPSIGNALOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.IsGroupSignal' Reason: 'the value of Com_IsGroupSignalOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ROUTINGBUFFERIDXOFRXACCESSINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferIdx' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFERUSEDOFRXACCESSINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueIdx' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXACCESSINFO                                                              STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                         STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                         STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                       STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                           STD_ON
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERLENGTHOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferLength' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERUSEDOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERENDIDXOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERLENGTHOFRXACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERSTARTIDXOFRXACCESSINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERUSEDOFRXACCESSINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXACCESSINFO                                                             STD_ON
#define COM_RXTOUTINFOUSEDOFRXACCESSINFO                                                            STD_ON
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferIdx' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferUsed' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.SignExtRequired' Reason: 'the value of Com_SignExtRequiredOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                    STD_ON
#define COM_TMPBUFFERIDXOFRXACCESSINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferIdx' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPBUFFERUSEDOFRXACCESSINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERENDIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferEndIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERLENGTHOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferLength' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERSTARTIDXOFRXACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferStartIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERUSEDOFRXACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOGRPSIGIND                                                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOIND                                                                         STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                                                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTR                                                                            STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                      STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLD                                                    STD_ON
#define COM_RXDEFPDUBUFFER                                                                          STD_ON
#define COM_RXDEFERREDEVENTCACHE                                                                    STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHE                                                                   STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                      STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLD                                                    STD_ON
#define COM_RXDLMONDIVISOR                                                                          STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDLMONDIVISORCOUNTER                                                                   STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                                                     STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: 'No dynamic length group signals are present' */
#define COM_RXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_RXNEXTEVENTCACHEENTY                                                                    STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEnty' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUCALLOUTFUNCPTR                                                                     STD_ON
#define COM_RXPDUDMSTATE                                                                            STD_ON
#define COM_RXPDUGRPACTIVE                                                                          STD_ON
#define COM_RXPDUINFO                                                                               STD_ON
#define COM_DEFERREDGWMAPPINGINFOIDXOFRXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFOUSEDOFRXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWINFOENDIDXOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWTXPDUDESCRIPTIONINFOENDIDXOFRXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOSTARTIDXOFRXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GWTXPDUDESCRIPTIONINFOUSEDOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONIDXOFRXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONUSEDOFRXPDUINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                       STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                      STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFRXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFRXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.MetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_PDUGRPVECTORENDIDXOFRXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORSTARTIDXOFRXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORUSEDOFRXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.PduGrpVectorUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                      STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                                                          STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                         STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                       STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                           STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                       STD_ON
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                                                      STD_ON
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                                              STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                                                            STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                                                STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                                                STD_ON
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                          STD_ON
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                        STD_ON
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                                                            STD_ON
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                                               STD_ON
#define COM_RXTPINFOIDXOFRXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGNALPROCESSINGOFRXPDUINFO                                                             STD_ON
#define COM_TYPEOFRXPDUINFO                                                                         STD_ON
#define COM_RXPDUINFOIND                                                                            STD_ON
#define COM_RXSIGARRAYACCESSSIGGRPBUFFER                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigArrayAccessSigGrpBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERARRAYBASED                                                                   STD_ON
#define COM_RXSIGBUFFERFLOAT32                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT64                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT16                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT32                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT64                                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERZEROBIT                                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigBufferZeroBit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUESIGGRPARRAYACCESSENDIDXOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSLENGTHOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSSTARTIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSUSEDOFRXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8ENDIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8LENGTHOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8STARTIDXOFRXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8USEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVALIDHNDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERENDIDXOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERLENGTHOFRXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERSTARTIDXOFRXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERUSEDOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8ENDIDXOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8LENGTHOFRXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8STARTIDXOFRXSIGGRPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8USEDOFRXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                                                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SHDBUFFERREQUIREDOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ShdBufferRequired' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.StartBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBIDXOFRXSIGGRPINFO                                                                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ValidDlc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGINFO                                                                               STD_ON
#define COM_GWINFOIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                                              STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                           STD_ON
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                          STD_ON
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGINFO                                                       STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                                                STD_ON
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                                               STD_ON
#define COM_SIGNALPROCESSINGOFRXSIGINFO                                                             STD_ON
#define COM_UBIDXOFRXSIGINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                                                     STD_ON
#define COM_RXTOUTCNT                                                                               STD_ON
#define COM_RXTOUTINFO                                                                              STD_ON
#define COM_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                                   STD_ON
#define COM_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                                 STD_ON
#define COM_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                                     STD_ON
#define COM_FACTOROFRXTOUTINFO                                                                      STD_ON
#define COM_FIRSTFACTOROFRXTOUTINFO                                                                 STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO                                            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceGrpSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO                                             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndEndIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO                                           STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndStartIdx' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                                               STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndUsed' Reason: 'the optional indirection is deactivated because RxAccessInfoReplaceSigIndUsedOfRxTOutInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                                                STD_ON
#define COM_RXTOUTINFOIND                                                                           STD_ON
#define COM_RXTPBUFFER                                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFRXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                                                         STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAENDIDXOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATALENGTHOFRXTPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATASTARTIDXOFRXTPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERMETADATAUSEDOFRXTPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferMetaDataUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKENDIDXOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKLENGTHOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKSTARTIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKUSEDOFSIGGRPARRAYFILTERINFO                                    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXENDIDXOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXLENGTHOFSIGGRPARRAYFILTERINFO                                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXSTARTIDXOFSIGGRPARRAYFILTERINFO                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXUSEDOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_FILTERALGOOFSIGGRPARRAYFILTERINFO                                                       STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_OFFSETINSIGNALGROUPOFSIGGRPARRAYFILTERINFO                                              STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.OffsetInSignalGroup' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpEventFlag' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUS                                                            STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTR                                                                  STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRIND                                                               STD_ON
#define COM_SIZEOFCBKTXACKDEFFUNCPTR                                                                STD_ON
#define COM_SIZEOFCBKTXACKDEFFUNCPTRIND                                                             STD_ON
#define COM_SIZEOFCONSTVALUEARRAYBASED                                                              STD_ON
#define COM_SIZEOFCURRENTTXMODE                                                                     STD_ON
#define COM_SIZEOFCYCLETIMECNT                                                                      STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                                                 STD_ON
#define COM_SIZEOFDELAYTIMECNT                                                                      STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                                               STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERRED                                                               STD_ON
#define COM_SIZEOFIPDUGROUPINFO                                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOIND                                                       STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_ON
#define COM_SIZEOFIPDUGROUPSTATE                                                                    STD_ON
#define COM_SIZEOFRXACCESSINFO                                                                      STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                                                   STD_ON
#define COM_SIZEOFRXCBKFUNCPTR                                                                      STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                                                    STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHE                                                             STD_ON
#define COM_SIZEOFRXPDUCALLOUTFUNCPTR                                                               STD_ON
#define COM_SIZEOFRXPDUDMSTATE                                                                      STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFRXPDUINFO                                                                         STD_ON
#define COM_SIZEOFRXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFRXSIGBUFFERARRAYBASED                                                             STD_ON
#define COM_SIZEOFRXSIGINFO                                                                         STD_ON
#define COM_SIZEOFRXTOUTCNT                                                                         STD_ON
#define COM_SIZEOFRXTOUTINFO                                                                        STD_ON
#define COM_SIZEOFRXTOUTINFOIND                                                                     STD_ON
#define COM_SIZEOFTMPRXBUFFER                                                                       STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                                                   STD_ON
#define COM_SIZEOFTXBUFFER                                                                          STD_ON
#define COM_SIZEOFTXCYCLICPDU                                                                       STD_ON
#define COM_SIZEOFTXMODEFALSE                                                                       STD_ON
#define COM_SIZEOFTXMODEINFO                                                                        STD_ON
#define COM_SIZEOFTXMODETRUE                                                                        STD_ON
#define COM_SIZEOFTXPDUCALLOUTFUNCPTR                                                               STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                                                    STD_ON
#define COM_SIZEOFTXPDUINFO                                                                         STD_ON
#define COM_SIZEOFTXPDUINFOIND                                                                      STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                                                    STD_ON
#define COM_SIZEOFTXPDUTTCALLOUTFUNCPTR                                                             STD_ON
#define COM_SIZEOFTXSDULENGTH                                                                       STD_ON
#define COM_SIZEOFTXSIGINFO                                                                         STD_ON
#define COM_SOURCEDESCRIPTIONMASK                                                                   STD_OFF  /**< Deactivateable: 'Com_SourceDescriptionMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_TMPRXBUFFER                                                                             STD_ON
#define COM_TMPRXSHDBUFFERARRAYBASED                                                                STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT32                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT64                                                                   STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT16                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT32                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT64                                                                    STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT8                                                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TRANSMITREQUEST                                                                         STD_ON
#define COM_TXBUFFER                                                                                STD_ON
#define COM_TXCYCLECOUNTERDIVISOR                                                                   STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLECOUNTERDIVISORCOUNTER                                                            STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPDU                                                                             STD_ON
#define COM_TXPDUINFOIDXOFTXCYCLICPDU                                                               STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                        STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLD                                                      STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTER                                                      STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockCounter' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLD                                                    STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOR                                                                          STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDLMONDIVISORCOUNTER                                                                   STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDYNSIGNALLENGTH                                                                       STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                                                       STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASED                                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT32                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT64                                                                STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESIGGRPARRAYACCESS                                                      STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT16                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT8                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEARRAYBASED                                                              STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT32                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT64                                                                 STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT16                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT32                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT64                                                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT8                                                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERSTATE                                                                           STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXIPDUGROUPISRLOCKCOUNTER                                                               STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLD                                                             STD_ON
#define COM_TXMODEFALSE                                                                             STD_ON
#define COM_DIRECTOFTXMODEFALSE                                                                     STD_ON
#define COM_PERIODICOFTXMODEFALSE                                                                   STD_ON
#define COM_REPCNTOFTXMODEFALSE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the value of Com_RepCntOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODEFALSE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                                                 STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeFalse is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODEFALSE                                                                 STD_ON
#define COM_TXMODEINFO                                                                              STD_ON
#define COM_INITMODEOFTXMODEINFO                                                                    STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxModeInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINIMUMDELAYOFTXMODEINFO                                                                STD_ON
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                                              STD_ON
#define COM_TXMODETRUEIDXOFTXMODEINFO                                                               STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODETRUE                                                                              STD_ON
#define COM_DIRECTOFTXMODETRUE                                                                      STD_ON
#define COM_PERIODICOFTXMODETRUE                                                                    STD_ON
#define COM_REPCNTOFTXMODETRUE                                                                      STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODETRUE                                                                   STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODETRUE                                                                  STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                                                  STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                                                     STD_ON
#define COM_TXPDUGRPACTIVE                                                                          STD_ON
#define COM_TXPDUINFO                                                                               STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: '/ActiveEcuC/PduR/Com[0:PduRCancelTransmit] is configured to 'false'' */
#define COM_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                                  STD_ON
#define COM_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                                STD_ON
#define COM_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                                                    STD_ON
#define COM_CBKTXACKIMFUNCPTRINDENDIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDSTARTIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDUSEDOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDENDIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDSTARTIDXOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDUSEDOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKENDIDXOFTXPDUINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKSTARTIDXOFTXPDUINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKUSEDOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                                                   STD_ON
#define COM_GWTIMEOUTINFOIDXOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOUSEDOFTXPDUINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoUsed' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                            STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                          STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                              STD_ON
#define COM_INVALIDHNDOFTXPDUINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFTXPDUINFO                                                               STD_ON
#define COM_PDUGRPVECTORENDIDXOFTXPDUINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORSTARTIDXOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUGRPVECTORUSEDOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.PduGrpVectorUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'true'' */
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                                                        STD_ON
#define COM_TXBUFFERENDIDXOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXPDUINFO                                                               STD_ON
#define COM_TXBUFFERMETADATAENDIDXOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATALENGTHOFTXPDUINFO                                                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATASTARTIDXOFTXPDUINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATAUSEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXPDUINFO                                                             STD_ON
#define COM_TXBUFFERUSEDOFTXPDUINFO                                                                 STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                       STD_ON
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                      STD_ON
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                         STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                       STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                                                           STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                                     STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                    STD_ON
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because TxSigGrpInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUINFOIND                                                                            STD_ON
#define COM_TXPDUINITVALUE                                                                          STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                                                   STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTER                                                              STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLD                                                            STD_ON
#define COM_TXSDULENGTH                                                                             STD_ON
#define COM_TXSIGGRPINFO                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_PDUOFFSETOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.PduOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOENDIDXOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOSTARTIDXOFTXSIGGRPINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOUSEDOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERENDIDXOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERLENGTHOFTXSIGGRPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDULength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferSigGrpInTxIPDUStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERSTARTIDXOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGGRPINFO                                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXBUFFERUSEDOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEENDIDXOFTXSIGGRPINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXSIGGRPINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGGRPINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXSIGGRPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFTXSIGGRPINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPINFOIND                                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPMASK                                                                            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGGRPONCHANGEMASK                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                                               STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                                                     STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                                                    STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                                                  STD_ON
#define COM_BUSACCOFTXSIGINFO                                                                       STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                                                   STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                                                 STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXSIGINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXSIGINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXSIGINFO                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFTXSIGINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ONCHANGEIDXOFTXSIGINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEUSEDOFTXSIGINFO                                                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                       STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                                                    STD_ON
#define COM_TXBUFFERENDIDXOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGINFO                                                               STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGINFO                                                             STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGINFO                                                                 STD_ON
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                                                         STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXSIGINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGINFO                                                                 STD_ON
#define COM_TXSIGGRPINFOIDXOFTXSIGINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxSigGrpInfoIdx' Reason: 'the optional indirection is deactivated because TxSigGrpInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOUSEDOFTXSIGINFO                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxSigGrpInfoUsed' Reason: 'the optional indirection is deactivated because TxSigGrpInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKIDXOFTXSIGINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                                                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEIND                                                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTCNT                                                                               STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFO                                                                              STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKTXTOUTFUNCPTRINDENDIDXOFTXTOUTINFO                                                   STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDSTARTIDXOFTXTOUTINFO                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDUSEDOFTXTOUTINFO                                                     STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                                                      STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MODEOFTXTOUTINFO                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTMPTPPDULENGTH                                                                        STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                                                     STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                                                    STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFTXTPINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFTXTPINFO                                                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXTPINFO                                                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERUSEDOFTXTPINFO                                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGIDXOFTXTPINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGUSEDOFTXTPINFO                                                           STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                                                           STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                                                 STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_WAITINGFORCONFIRMATION                                                                  STD_OFF  /**< Deactivateable: 'Com_WaitingForConfirmation' Reason: 'This array is deactivated, because no Tx error notification functions are configured.' */
#define COM_PCCONFIG                                                                                STD_ON
#define COM_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                        STD_ON
#define COM_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                           STD_ON
#define COM_CBKRXTOUTFUNCPTROFPCCONFIG                                                              STD_ON
#define COM_CBKTXACKDEFFUNCPTRINDOFPCCONFIG                                                         STD_ON
#define COM_CBKTXACKDEFFUNCPTROFPCCONFIG                                                            STD_ON
#define COM_CONFIGIDOFPCCONFIG                                                                      STD_ON
#define COM_CONSTVALUEARRAYBASEDOFPCCONFIG                                                          STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                                                 STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                                                  STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                                                             STD_ON
#define COM_DELAYTIMECNTOFPCCONFIG                                                                  STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayDescriptionProcessingISRLockThreshold' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway is not configured.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                                                           STD_ON
#define COM_HANDLETXPDUDEFERREDOFPCCONFIG                                                           STD_ON
#define COM_IPDUGROUPINFOOFPCCONFIG                                                                 STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                                   STD_ON
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                               STD_ON
#define COM_IPDUGROUPSTATEOFPCCONFIG                                                                STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                                                   STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                                                     STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                                               STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                                                  STD_ON
#define COM_RXCBKFUNCPTROFPCCONFIG                                                                  STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                            STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_ON
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                                                STD_ON
#define COM_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                         STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                            STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_ON
#define COM_RXDLMONDIVISOROFPCCONFIG                                                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_RXPDUCALLOUTFUNCPTROFPCCONFIG                                                           STD_ON
#define COM_RXPDUDMSTATEOFPCCONFIG                                                                  STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_RXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_RXSIGBUFFERARRAYBASEDOFPCCONFIG                                                         STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                                                     STD_ON
#define COM_RXTOUTCNTOFPCCONFIG                                                                     STD_ON
#define COM_RXTOUTINFOINDOFPCCONFIG                                                                 STD_ON
#define COM_RXTOUTINFOOFPCCONFIG                                                                    STD_ON
#define COM_SIZEOFALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTRINDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFCBKRXTOUTFUNCPTROFPCCONFIG                                                        STD_ON
#define COM_SIZEOFCBKTXACKDEFFUNCPTRINDOFPCCONFIG                                                   STD_ON
#define COM_SIZEOFCBKTXACKDEFFUNCPTROFPCCONFIG                                                      STD_ON
#define COM_SIZEOFCONSTVALUEARRAYBASEDOFPCCONFIG                                                    STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_SIZEOFDELAYTIMECNTOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFHANDLETXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_SIZEOFIPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_SIZEOFIPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXCBKFUNCPTROFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXDEFERREDFCTPTRCACHEOFPCCONFIG                                                   STD_ON
#define COM_SIZEOFRXPDUCALLOUTFUNCPTROFPCCONFIG                                                     STD_ON
#define COM_SIZEOFRXPDUDMSTATEOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFRXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXSIGBUFFERARRAYBASEDOFPCCONFIG                                                   STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXTOUTCNTOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFRXTOUTINFOINDOFPCCONFIG                                                           STD_ON
#define COM_SIZEOFRXTOUTINFOOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTMPRXBUFFEROFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_SIZEOFTXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_SIZEOFTXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_SIZEOFTXPDUCALLOUTFUNCPTROFPCCONFIG                                                     STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_SIZEOFTXPDUTTCALLOUTFUNCPTROFPCCONFIG                                                   STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_TMPRXBUFFEROFPCCONFIG                                                                   STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                                               STD_ON
#define COM_TXBUFFEROFPCCONFIG                                                                      STD_ON
#define COM_TXCYCLECOUNTERDIVISOROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPDUOFPCCONFIG                                                                   STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                            STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOROFPCCONFIG                                                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                     STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                                                   STD_ON
#define COM_TXMODEFALSEOFPCCONFIG                                                                   STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                                                    STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                                                    STD_ON
#define COM_TXPDUCALLOUTFUNCPTROFPCCONFIG                                                           STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                                                STD_ON
#define COM_TXPDUINFOINDOFPCCONFIG                                                                  STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                                                     STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                                                STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTROFPCCONFIG                                                         STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                    STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                                                  STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                                                   STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMinNumericValueDefines  Com Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COM_MIN_CYCLETIMECNT                                                                        0u
#define COM_MIN_DELAYTIMECNT                                                                        0u
#define COM_MIN_HANDLERXPDUDEFERRED                                                                 0u
#define COM_MIN_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                  0u
#define COM_MIN_RXDEFPDUBUFFER                                                                      0u
#define COM_MIN_RXDEFERREDFCTPTRCACHE                                                               0u
#define COM_MIN_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                  0u
#define COM_MIN_RXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_RXSIGBUFFERARRAYBASED                                                               0u
#define COM_MIN_RXTOUTCNT                                                                           0u
#define COM_MIN_TMPRXBUFFER                                                                         0u
#define COM_MIN_TXBUFFER                                                                            0u
#define COM_MIN_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                    0u
#define COM_MIN_TXIPDUGROUPISRLOCKCOUNTER                                                           0u
#define COM_MIN_TXPROCESSINGISRLOCKCOUNTER                                                          0u
#define COM_MIN_TXSDULENGTH                                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMaxNumericValueDefines  Com Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COM_MAX_CYCLETIMECNT                                                                        65535u
#define COM_MAX_DELAYTIMECNT                                                                        255u
#define COM_MAX_HANDLERXPDUDEFERRED                                                                 4294967295u
#define COM_MAX_RXDEADLINEMONITORINGISRLOCKCOUNTER                                                  65535u
#define COM_MAX_RXDEFPDUBUFFER                                                                      255u
#define COM_MAX_RXDEFERREDFCTPTRCACHE                                                               4294967295u
#define COM_MAX_RXDEFERREDPROCESSINGISRLOCKCOUNTER                                                  65535u
#define COM_MAX_RXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_RXSIGBUFFERARRAYBASED                                                               255u
#define COM_MAX_RXTOUTCNT                                                                           65535u
#define COM_MAX_TMPRXBUFFER                                                                         255u
#define COM_MAX_TXBUFFER                                                                            255u
#define COM_MAX_TXCYCLICPROCESSINGISRLOCKCOUNTER                                                    65535u
#define COM_MAX_TXIPDUGROUPISRLOCKCOUNTER                                                           65535u
#define COM_MAX_TXPROCESSINGISRLOCKCOUNTER                                                          65535u
#define COM_MAX_TXSDULENGTH                                                                         4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCNoReferenceDefines  Com No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                 255u
#define COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                               255u
#define COM_NO_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                    255u
#define COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                  255u
#define COM_NO_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                    65535u
#define COM_NO_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                                  65535u
#define COM_NO_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                      65535u
#define COM_NO_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                    65535u
#define COM_NO_RXTOUTINFOIDXOFRXACCESSINFO                                                          255u
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                    255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                       255u
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                     255u
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                   255u
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                      65535u
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                    65535u
#define COM_NO_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                    255u
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                                                           255u
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                                                         255u
#define COM_NO_RXTOUTINFOIDXOFRXPDUINFO                                                             255u
#define COM_NO_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                       255u
#define COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                     255u
#define COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                        255u
#define COM_NO_RXTOUTINFOIDXOFRXSIGINFO                                                             255u
#define COM_NO_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                                255u
#define COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                              255u
#define COM_NO_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                               255u
#define COM_NO_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                             255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                         255u
#define COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                       255u
#define COM_NO_TXBUFFERENDIDXOFTXPDUINFO                                                            65535u
#define COM_NO_TXBUFFERSTARTIDXOFTXPDUINFO                                                          65535u
#define COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                    255u
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                      65535u
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                    65535u
#define COM_NO_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                                  255u
#define COM_NO_TXBUFFERENDIDXOFTXSIGINFO                                                            65535u
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGINFO                                                          65535u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumExistsDefines  Com Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT32                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT32                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT32                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT64                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT64                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT64                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT16                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT16                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT16                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT16                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT16                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT16                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT32                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT32                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT32                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT32                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT32                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT32                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT64                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT64                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT64                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT64                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT64                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT64                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8                                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8                                      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8                                       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8                                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8_N                                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8_N                                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8_N                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8_N                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8_N                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8_N                                    STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8_N                                     STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8_N                                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DIRECT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_RIGHTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LEFTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO                                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_BIG_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_LITTLE_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_DEFERRED_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] is configured to 'false'' */
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                                                     STD_OFF
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                                                     STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                                                   STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                                                 STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFRXACCESSINFO                                                   STD_ON
#define COM_EXISTS_FLOAT32_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                                                        STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                                                        STD_OFF
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                                                       STD_OFF
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                                                    STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                                                   STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                                                STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFRXACCESSINFO                                                 STD_ON
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO                                            STD_OFF
#define COM_EXISTS_NORMAL_TYPEOFRXPDUINFO                                                           STD_ON
#define COM_EXISTS_TP_TYPEOFRXPDUINFO                                                               STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                             STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO                                            STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFSIGGRPARRAYFILTERINFO                                         STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEVER_FILTERALGOOFSIGGRPARRAYFILTERINFO                                          STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFSIGGRPARRAYFILTERINFO                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO                            STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                 STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFSIGGRPARRAYFILTERINFO                                  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NONE_FILTERALGOOFSIGGRPARRAYFILTERINFO                                           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                                           STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO                                         STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TransferProperty' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                                                        STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                                                        STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                                                      STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                                                    STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_FLOAT64_APPLTYPEOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                                                           STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                                                           STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                                                          STD_OFF
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                                                       STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                                                      STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                                                   STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXSIGINFO                                                    STD_ON
#define COM_EXISTS_NORMAL_MODEOFTXTOUTINFO                                                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_MODEOFTXTOUTINFO                                                            STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumDefines  Com Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_INACTIVE_IPDUGROUPSTATE                                                                 0x00u
#define COM_ACTIVE_DMINACTIVE_IPDUGROUPSTATE                                                        0x01u
#define COM_ACTIVE_DMACTIVE_IPDUGROUPSTATE                                                          0x02u
#define COM_UINT8_N_APPLTYPEOFRXACCESSINFO                                                          0x08u
#define COM_ZEROBIT_APPLTYPEOFRXACCESSINFO                                                          0x0Au
#define COM_NBIT_BUSACCOFRXACCESSINFO                                                               0x00u
#define COM_ARRAY_BASED_BUSACCOFRXACCESSINFO                                                        0x06u
#define COM_INACTIVE_RXPDUDMSTATE                                                                   0x00u
#define COM_ACTIVE_RXPDUDMSTATE                                                                     0x01u
#define COM_PURE_DM_STATE_MASK_RXPDUDMSTATE                                                         0x01u
#define COM_OCCURRED_RXPDUDMSTATE                                                                   0x03u
#define COM_OCCURRED_FLAG_RXPDUDMSTATE                                                              0x02u
#define COM_CLEAR_OCCURRED_FLAG_RXPDUDMSTATE                                                        0xFDu
#define COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                                                    0x00u
#define COM_NORMAL_TYPEOFRXPDUINFO                                                                  0x00u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                                                    0x00u
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                                               0x00u
#define COM_UINT8_N_APPLTYPEOFTXSIGINFO                                                             0x08u
#define COM_NBIT_BUSACCOFTXSIGINFO                                                                  0x00u
#define COM_BYTE_BUSACCOFTXSIGINFO                                                                  0x01u
#define COM_ARRAY_BASED_BUSACCOFTXSIGINFO                                                           0x06u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIsReducedToDefineDefines  Com Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                              STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTR                                                                  STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRIND                                                               STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTR                                                                STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRIND                                                             STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASED                                                              STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                              STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                            STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                STD_OFF
#define COM_ISDEF_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                               STD_OFF
#define COM_ISDEF_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                   STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOIND                                                       STD_OFF
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                   STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                                                            STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                                                           STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                                                         STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                                              STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                                                          STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                 STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO                                 STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                               STD_OFF
#define COM_ISDEF_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO                                   STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXACCESSINFO                                                        STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                   STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                   STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                 STD_OFF
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                     STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXACCESSINFO                                                       STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXACCESSINFO                                                      STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                              STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                                                   STD_OFF
#define COM_ISDEF_RXCBKFUNCPTR                                                                      STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTR                                                               STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                        STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                                                    STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                     STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                 STD_OFF
#define COM_ISDEF_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                                                STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                                                        STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                                                      STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXPDUINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                    STD_OFF
#define COM_ISDEF_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                  STD_OFF
#define COM_ISDEF_RXTOUTINFOINDUSEDOFRXPDUINFO                                                      STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXPDUINFO                                                         STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TYPEOFRXPDUINFO                                                                   STD_OFF
#define COM_ISDEF_RXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                                                        STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                     STD_OFF
#define COM_ISDEF_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                    STD_OFF
#define COM_ISDEF_RXTOUTINFOIDXOFRXSIGINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOUSEDOFRXSIGINFO                                                         STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                                                       STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                                               STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                             STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                           STD_OFF
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                               STD_OFF
#define COM_ISDEF_FACTOROFRXTOUTINFO                                                                STD_OFF
#define COM_ISDEF_FIRSTFACTOROFRXTOUTINFO                                                           STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXTOUTINFO                                                          STD_OFF
#define COM_ISDEF_RXTOUTINFOIND                                                                     STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXCYCLICPDU                                                         STD_OFF
#define COM_ISDEF_DIRECTOFTXMODEFALSE                                                               STD_OFF
#define COM_ISDEF_PERIODICOFTXMODEFALSE                                                             STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODEFALSE                                                           STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                                              STD_OFF
#define COM_ISDEF_MINIMUMDELAYOFTXMODEINFO                                                          STD_OFF
#define COM_ISDEF_TXMODEFALSEIDXOFTXMODEINFO                                                        STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                                                         STD_OFF
#define COM_ISDEF_DIRECTOFTXMODETRUE                                                                STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                                              STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                                                            STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTR                                                               STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                            STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                          STD_OFF
#define COM_ISDEF_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                                              STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                                                             STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                      STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                    STD_OFF
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                        STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                                                  STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXPDUINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXPDUINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXPDUINFO                                                           STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                 STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                                                     STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                               STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                                              STD_OFF
#define COM_ISDEF_TXPDUINFOIND                                                                      STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                                                    STD_OFF
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTR                                                             STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                                               STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                                              STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                                                            STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                                                 STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                                                             STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                 STD_OFF
#define COM_ISDEF_TRIGGEREDOFTXSIGINFO                                                              STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGINFO                                                         STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGINFO                                                       STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGINFO                                                           STD_OFF
#define COM_ISDEF_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                  STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_CBKRXTOUTFUNCPTROFPCCONFIG                                                        STD_ON
#define COM_ISDEF_CBKTXACKDEFFUNCPTRINDOFPCCONFIG                                                   STD_ON
#define COM_ISDEF_CBKTXACKDEFFUNCPTROFPCCONFIG                                                      STD_ON
#define COM_ISDEF_CONSTVALUEARRAYBASEDOFPCCONFIG                                                    STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                                                       STD_ON
#define COM_ISDEF_DELAYTIMECNTOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_HANDLETXPDUDEFERREDOFPCCONFIG                                                     STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                             STD_ON
#define COM_ISDEF_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                         STD_ON
#define COM_ISDEF_IPDUGROUPSTATEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXCBKFUNCPTROFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                      STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                   STD_ON
#define COM_ISDEF_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                      STD_ON
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_RXPDUCALLOUTFUNCPTROFPCCONFIG                                                     STD_ON
#define COM_ISDEF_RXPDUDMSTATEOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_RXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXSIGBUFFERARRAYBASEDOFPCCONFIG                                                   STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXTOUTCNTOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_RXTOUTINFOINDOFPCCONFIG                                                           STD_ON
#define COM_ISDEF_RXTOUTINFOOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TMPRXBUFFEROFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                                                         STD_ON
#define COM_ISDEF_TXBUFFEROFPCCONFIG                                                                STD_ON
#define COM_ISDEF_TXCYCLICPDUOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                        STD_ON
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                               STD_ON
#define COM_ISDEF_TXMODEFALSEOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                                              STD_ON
#define COM_ISDEF_TXPDUCALLOUTFUNCPTROFPCCONFIG                                                     STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPDUINFOINDOFPCCONFIG                                                            STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                                               STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                                                          STD_ON
#define COM_ISDEF_TXPDUTTCALLOUTFUNCPTROFPCCONFIG                                                   STD_ON
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                              STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                                                             STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEqualsAlwaysToDefines  Com Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                                                
#define COM_EQ2_CBKRXTOUTFUNCPTR                                                                    
#define COM_EQ2_CBKRXTOUTFUNCPTRIND                                                                 
#define COM_EQ2_CBKTXACKDEFFUNCPTR                                                                  
#define COM_EQ2_CBKTXACKDEFFUNCPTRIND                                                               
#define COM_EQ2_CONSTVALUEARRAYBASED                                                                
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO                                
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO                              
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO                                  
#define COM_EQ2_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_RXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                                                   
#define COM_EQ2_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                                                 
#define COM_EQ2_TXPDUINFOINDUSEDOFIPDUGROUPINFO                                                     
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOIND                                                         
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSIND                                                     
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                                              
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                                                             
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                                                           
#define COM_EQ2_BUSACCOFRXACCESSINFO                                                                
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                                                            
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                                                          
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO                                   
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO                                   
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO                                 
#define COM_EQ2_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO                                     
#define COM_EQ2_RXPDUINFOIDXOFRXACCESSINFO                                                          
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO                                     
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO                                     
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO                                   
#define COM_EQ2_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO                                       
#define COM_EQ2_RXTOUTINFOIDXOFRXACCESSINFO                                                         
#define COM_EQ2_RXTOUTINFOUSEDOFRXACCESSINFO                                                        
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                                                
#define COM_EQ2_RXACCESSINFOIND                                                                     
#define COM_EQ2_RXCBKFUNCPTR                                                                        
#define COM_EQ2_RXPDUCALLOUTFUNCPTR                                                                 
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                                                   
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                                                  
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                                          
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                                                  
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                                                      
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                                                     
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                                                   
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                                                       
#define COM_EQ2_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                                                   
#define COM_EQ2_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                                                  
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                                                          
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                                                        
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                                                            
#define COM_EQ2_RXTOUTINFOIDXOFRXPDUINFO                                                            
#define COM_EQ2_RXTOUTINFOINDENDIDXOFRXPDUINFO                                                      
#define COM_EQ2_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                                                    
#define COM_EQ2_RXTOUTINFOINDUSEDOFRXPDUINFO                                                        
#define COM_EQ2_RXTOUTINFOUSEDOFRXPDUINFO                                                           
#define COM_EQ2_SIGNALPROCESSINGOFRXPDUINFO                                                         
#define COM_EQ2_TYPEOFRXPDUINFO                                                                     
#define COM_EQ2_RXPDUINFOIND                                                                        
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                                                          
#define COM_EQ2_RXCBKFUNCPTRACKIDXOFRXSIGINFO                                                       
#define COM_EQ2_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                                                      
#define COM_EQ2_RXTOUTINFOIDXOFRXSIGINFO                                                            
#define COM_EQ2_RXTOUTINFOUSEDOFRXSIGINFO                                                           
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                                                         
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                                                 
#define COM_EQ2_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                                               
#define COM_EQ2_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                                             
#define COM_EQ2_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                                                 
#define COM_EQ2_FACTOROFRXTOUTINFO                                                                  
#define COM_EQ2_FIRSTFACTOROFRXTOUTINFO                                                             
#define COM_EQ2_RXPDUINFOIDXOFRXTOUTINFO                                                            
#define COM_EQ2_RXTOUTINFOIND                                                                       
#define COM_EQ2_TXPDUINFOIDXOFTXCYCLICPDU                                                           
#define COM_EQ2_DIRECTOFTXMODEFALSE                                                                 
#define COM_EQ2_PERIODICOFTXMODEFALSE                                                               
#define COM_EQ2_TIMEPERIODOFTXMODEFALSE                                                             
#define COM_EQ2_INITMODEOFTXMODEINFO                                                                
#define COM_EQ2_MINIMUMDELAYOFTXMODEINFO                                                            
#define COM_EQ2_TXMODEFALSEIDXOFTXMODEINFO                                                          
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                                                           
#define COM_EQ2_DIRECTOFTXMODETRUE                                                                  
#define COM_EQ2_PERIODICOFTXMODETRUE                                                                
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                                              
#define COM_EQ2_TXPDUCALLOUTFUNCPTR                                                                 
#define COM_EQ2_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                                              
#define COM_EQ2_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                                            
#define COM_EQ2_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                                                
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                                               
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO                                        
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO                                      
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                                          
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                                                           
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                                                    
#define COM_EQ2_TXBUFFERENDIDXOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXPDUINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXPDUINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXPDUINFO                                                             
#define COM_EQ2_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                                                   
#define COM_EQ2_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                  
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                                                     
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                                                   
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                                                       
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                                                 
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                                                
#define COM_EQ2_TXPDUINFOIND                                                                        
#define COM_EQ2_TXPDUINITVALUE                                                                      
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTR                                                               
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                                                 
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                                                
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                                              
#define COM_EQ2_BUSACCOFTXSIGINFO                                                                   
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                                               
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                                                             
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFTXSIGINFO                                                   
#define COM_EQ2_TRIGGEREDOFTXSIGINFO                                                                
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGINFO                                                           
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGINFO                                                         
#define COM_EQ2_TXBUFFERUSEDOFTXSIGINFO                                                             
#define COM_EQ2_TXPDUINFOIDXOFTXSIGINFO                                                             
#define COM_EQ2_ALWAYSACTIVETXCOMIPDUSOFPCCONFIG                                                    Com_AlwaysActiveTxComIPdus
#define COM_EQ2_CBKRXTOUTFUNCPTRINDOFPCCONFIG                                                       Com_CbkRxTOutFuncPtrInd
#define COM_EQ2_CBKRXTOUTFUNCPTROFPCCONFIG                                                          Com_CbkRxTOutFuncPtr
#define COM_EQ2_CBKTXACKDEFFUNCPTRINDOFPCCONFIG                                                     Com_CbkTxAckDefFuncPtrInd
#define COM_EQ2_CBKTXACKDEFFUNCPTROFPCCONFIG                                                        Com_CbkTxAckDefFuncPtr
#define COM_EQ2_CONSTVALUEARRAYBASEDOFPCCONFIG                                                      Com_ConstValueArrayBased
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                                                             Com_CurrentTxMode
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                                              Com_CycleTimeCnt
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                                                         Com_CyclicSendRequest
#define COM_EQ2_DELAYTIMECNTOFPCCONFIG                                                              Com_DelayTimeCnt
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                                                       Com_HandleRxPduDeferred.raw
#define COM_EQ2_HANDLETXPDUDEFERREDOFPCCONFIG                                                       Com_HandleTxPduDeferred
#define COM_EQ2_IPDUGROUPINFOOFPCCONFIG                                                             Com_IPduGroupInfo
#define COM_EQ2_IPDUGROUPINFOOFRXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfRxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOOFTXPDUINFOINDOFPCCONFIG                                               Com_IPduGroupInfoOfTxPduInfoInd
#define COM_EQ2_IPDUGROUPINFOTOSUBIPDUGROUPSINDOFPCCONFIG                                           Com_IPduGroupInfoToSubIPduGroupsInd
#define COM_EQ2_IPDUGROUPSTATEOFPCCONFIG                                                            Com_IPduGroupState
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                                               (&(Com_Initialized))
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                                                           Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                                              Com_RxAccessInfo
#define COM_EQ2_RXCBKFUNCPTROFPCCONFIG                                                              Com_RxCbkFuncPtr
#define COM_EQ2_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG                                        (&(Com_RxDeadlineMonitoringISRLockCounter))
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                                                            Com_RxDefPduBuffer.raw
#define COM_EQ2_RXDEFERREDFCTPTRCACHEOFPCCONFIG                                                     Com_RxDeferredFctPtrCache
#define COM_EQ2_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                        (&(Com_RxDeferredProcessingISRLockCounter))
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 (&(Com_RxIPduGroupISRLockCounter))
#define COM_EQ2_RXPDUCALLOUTFUNCPTROFPCCONFIG                                                       Com_RxPduCalloutFuncPtr
#define COM_EQ2_RXPDUDMSTATEOFPCCONFIG                                                              Com_RxPduDmState
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                                                            Com_RxPduGrpActive
#define COM_EQ2_RXPDUINFOINDOFPCCONFIG                                                              Com_RxPduInfoInd
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                                                 Com_RxPduInfo
#define COM_EQ2_RXSIGBUFFERARRAYBASEDOFPCCONFIG                                                     Com_RxSigBufferArrayBased
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                                                 Com_RxSigInfo
#define COM_EQ2_RXTOUTCNTOFPCCONFIG                                                                 Com_RxTOutCnt
#define COM_EQ2_RXTOUTINFOINDOFPCCONFIG                                                             Com_RxTOutInfoInd
#define COM_EQ2_RXTOUTINFOOFPCCONFIG                                                                Com_RxTOutInfo
#define COM_EQ2_TMPRXBUFFEROFPCCONFIG                                                               Com_TmpRxBuffer
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                                                           Com_TransmitRequest
#define COM_EQ2_TXBUFFEROFPCCONFIG                                                                  Com_TxBuffer
#define COM_EQ2_TXCYCLICPDUOFPCCONFIG                                                               Com_TxCyclicPdu
#define COM_EQ2_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                          (&(Com_TxCyclicProcessingISRLockCounter))
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                                                 (&(Com_TxIPduGroupISRLockCounter))
#define COM_EQ2_TXMODEFALSEOFPCCONFIG                                                               Com_TxModeFalse
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                                                Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                                                Com_TxModeTrue
#define COM_EQ2_TXPDUCALLOUTFUNCPTROFPCCONFIG                                                       Com_TxPduCalloutFuncPtr
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                                                            Com_TxPduGrpActive
#define COM_EQ2_TXPDUINFOINDOFPCCONFIG                                                              Com_TxPduInfoInd
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                                                 Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                                                            Com_TxPduInitValue
#define COM_EQ2_TXPDUTTCALLOUTFUNCPTROFPCCONFIG                                                     Com_TxPduTTCalloutFuncPtr
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                                                (&(Com_TxProcessingISRLockCounter))
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                                               Com_TxSduLength
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                                                 Com_TxSigInfo
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicInitializationPointers  Com Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCInitializationSymbols  Com Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGeneral  Com General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                                                      0x321Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                                               COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                                                     -917688657  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321Eu' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 



/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */
#define COM_IPDUCALLOUT_USEPDUINFOPTR        STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComAdvancedIPduCallouts] */

/* Optimization */
#define COM_RECEIVE_SIGNAL_MACRO_API         STD_OFF

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSignalGateway] || /ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] */
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */
#define COM_GENERATED_DESCRIPTION_ROUTING    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] */

#define COM_LMGT_MAXIPDUGROUPVECTORBYTECNT   1U
#define COM_SUPPORTED_IPDU_GROUPS            8uL  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U

/**
  \brief  Constants to compare floating-point values according to ISO C-99 standard.
  \details  -
    \{
*/
#define COM_FLT_EPSILON                      1E-5
#define COM_DBL_EPSILON                      1E-9
/**
  \}
*/




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_ABM1_0x351_oABM1_oB30_for_SC_CAN_V3_2_1a88f258_Rx 0u
#define ComConf_ComSignal_ABM2_0x245_oABM2_oB30_for_SC_CAN_V3_2_17c6621a_Rx 1u
#define ComConf_ComSignal_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx 2u
#define ComConf_ComSignal_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx 3u
#define ComConf_ComSignal_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx 4u
#define ComConf_ComSignal_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx 5u
#define ComConf_ComSignal_AC3_0x2FD_oAC3_oB30_for_SC_CAN_V3_2_2814c5ad_Rx 6u
#define ComConf_ComSignal_AC4_0x2CC_oAC4_oB30_for_SC_CAN_V3_2_18a746db_Rx 7u
#define ComConf_ComSignal_AC6_0x2F8_oAC6_oB30_for_SC_CAN_V3_2_6d580a77_Rx 8u
#define ComConf_ComSignal_AC7_0x2D0_oAC7_oB30_for_SC_CAN_V3_2_8d6bd2f4_Rx 9u
#define ComConf_ComSignal_AC8_0x27C_oAC8_oB30_for_SC_CAN_V3_2_0c22f08a_Rx 10u
#define ComConf_ComSignal_AC14_0x299_oAC14_oB30_for_SC_CAN_V3_2_4b535511_Rx 11u
#define ComConf_ComSignal_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx 12u
#define ComConf_ComSignal_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx 13u
#define ComConf_ComSignal_ACC_FD4_0x2B8_oACC_FD4_oB30_for_SC_CAN_V3_2_b08c3adf_Rx 14u
#define ComConf_ComSignal_AEB_FD1_0x18B_oAEB_FD1_oB30_for_SC_CAN_V3_2_88d04ffa_Rx 15u
#define ComConf_ComSignal_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx 16u
#define ComConf_ComSignal_ALS1_0x287_oALS1_oB30_for_SC_CAN_V3_2_c7d86158_Rx 17u
#define ComConf_ComSignal_AMP1_0x3E1_oAMP1_oB30_for_SC_CAN_V3_2_ab4beb46_Rx 18u
#define ComConf_ComSignal_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx 19u
#define ComConf_ComSignal_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx 20u
#define ComConf_ComSignal_AMP4_ANC1_0x2D2_oAMP4_ANC1_oB30_for_SC_CAN_V3_2_2dfdb3ea_Rx 21u
#define ComConf_ComSignal_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx 22u
#define ComConf_ComSignal_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx 23u
#define ComConf_ComSignal_BCM7_0x28D_oBCM7_oB30_for_SC_CAN_V3_2_2985d7eb_Rx 24u
#define ComConf_ComSignal_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx 25u
#define ComConf_ComSignal_BCM11_0x305_oBCM11_oB30_for_SC_CAN_V3_2_ac8c1462_Rx 26u
#define ComConf_ComSignal_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx 27u
#define ComConf_ComSignal_BCM14_0x2A3_oBCM14_oB30_for_SC_CAN_V3_2_8a12cec7_Rx 28u
#define ComConf_ComSignal_BCM18_0x34D_oBCM18_oB30_for_SC_CAN_V3_2_b3211af2_Rx 29u
#define ComConf_ComSignal_BCM19_0x30F_oBCM19_oB30_for_SC_CAN_V3_2_5c1b5792_Rx 30u
#define ComConf_ComSignal_BLE1_0x25C_oBLE1_oB30_for_SC_CAN_V3_2_1b3c9d76_Rx 31u
#define ComConf_ComSignal_BLE5_0x1FA_oBLE5_oB30_for_SC_CAN_V3_2_11cf5179_Rx 32u
#define ComConf_ComSignal_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx 33u
#define ComConf_ComSignal_BMS8_0x285_oBMS8_oB30_for_SC_CAN_V3_2_cae03fe4_Rx 34u
#define ComConf_ComSignal_BMS19_0x352_oBMS19_oB30_for_SC_CAN_V3_2_9c6d6e6b_Rx 35u
#define ComConf_ComSignal_BMS22_0x3BF_oBMS22_oB30_for_SC_CAN_V3_2_02e5eecb_Rx 36u
#define ComConf_ComSignal_BMS30_0x3F1_oBMS30_oB30_for_SC_CAN_V3_2_43871adf_Rx 37u
#define ComConf_ComSignal_BMS35_0x2C4_oBMS35_oB30_for_SC_CAN_V3_2_b8679579_Rx 38u
#define ComConf_ComSignal_BMS65_0x14F_oBMS65_oB30_for_SC_CAN_V3_2_41016de9_Rx 39u
#define ComConf_ComSignal_BMS66_0x3AE_oBMS66_oB30_for_SC_CAN_V3_2_0f7b9919_Rx 40u
#define ComConf_ComSignal_BMS_FD14_0x1E3_oBMS_FD14_oB30_for_SC_CAN_V3_2_60b89745_Rx 41u
#define ComConf_ComSignal_CP1_0x35E_oCP1_oB30_for_SC_CAN_V3_2_86ba6def_Rx 42u
#define ComConf_ComSignal_CR_FD1_0x15E_oCR_FD1_oB30_for_SC_CAN_V3_2_779ff2cc_Rx 43u
#define ComConf_ComSignal_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx 44u
#define ComConf_ComSignal_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx 45u
#define ComConf_ComSignal_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx 46u
#define ComConf_ComSignal_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx 47u
#define ComConf_ComSignal_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx 48u
#define ComConf_ComSignal_DCT_FD4_0x236_oDCT_FD4_oB30_for_SC_CAN_V3_2_186dc059_Rx 49u
#define ComConf_ComSignal_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx 50u
#define ComConf_ComSignal_DDCM3_0x2F7_oDDCM3_oB30_for_SC_CAN_V3_2_1a16b5b8_Rx 51u
#define ComConf_ComSignal_DOCK1_0x311_oDOCK1_oB30_for_SC_CAN_V3_2_143f2c45_Rx 52u
#define ComConf_ComSignal_DOCK2_0x1DF_oDOCK2_oB30_for_SC_CAN_V3_2_2bb215fd_Rx 53u
#define ComConf_ComSignal_DSC4_0x2CE_oDSC4_oB30_for_SC_CAN_V3_2_fb519096_Rx 54u
#define ComConf_ComSignal_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx 55u
#define ComConf_ComSignal_DWD1_0x2B9_oDWD1_oB30_for_SC_CAN_V3_2_0a15b1ed_Rx 56u
#define ComConf_ComSignal_EBOOSTER_FD1_0x12D_oEBOOSTER_FD1_oB30_for_SC_CAN_V3_2_276bef9e_Rx 57u
#define ComConf_ComSignal_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx 58u
#define ComConf_ComSignal_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx 59u
#define ComConf_ComSignal_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx 60u
#define ComConf_ComSignal_ECM4_0x82_oECM4_oB30_for_SC_CAN_V3_2_ad48075d_Rx 61u
#define ComConf_ComSignal_ECM7_0x84_oECM7_oB30_for_SC_CAN_V3_2_ca9b1546_Rx 62u
#define ComConf_ComSignal_ECM9_0x102_oECM9_oB30_for_SC_CAN_V3_2_93658c9d_Rx 63u
#define ComConf_ComSignal_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx 64u
#define ComConf_ComSignal_ECM16_0x2D4_oECM16_oB30_for_SC_CAN_V3_2_3587073b_Rx 65u
#define ComConf_ComSignal_ECM19_0x3B5_oECM19_oB30_for_SC_CAN_V3_2_c4b3a800_Rx 66u
#define ComConf_ComSignal_ECM20_0x3B7_oECM20_oB30_for_SC_CAN_V3_2_bb09ac86_Rx 67u
#define ComConf_ComSignal_ECM24_0x350_oECM24_oB30_for_SC_CAN_V3_2_a1837eee_Rx 68u
#define ComConf_ComSignal_ECM_PT5_0x8E_oECM_PT5_oB30_for_SC_CAN_V3_2_9b098e80_Rx 69u
#define ComConf_ComSignal_ECM_PT6_0x290_oECM_PT6_oB30_for_SC_CAN_V3_2_e4144dec_Rx 70u
#define ComConf_ComSignal_ECM_PT7_0x117_oECM_PT7_oB30_for_SC_CAN_V3_2_e3782145_Rx 71u
#define ComConf_ComSignal_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx 72u
#define ComConf_ComSignal_ELD1_0x152_oELD1_oB30_for_SC_CAN_V3_2_b0381828_Rx 73u
#define ComConf_ComSignal_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx 74u
#define ComConf_ComSignal_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx 75u
#define ComConf_ComSignal_ESCL2_0x303_oESCL2_oB30_for_SC_CAN_V3_2_09a4f237_Rx 76u
#define ComConf_ComSignal_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx 77u
#define ComConf_ComSignal_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx 78u
#define ComConf_ComSignal_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx 79u
#define ComConf_ComSignal_ETC2_0x1F1_oETC2_oB30_for_SC_CAN_V3_2_2cfee004_Rx 80u
#define ComConf_ComSignal_ETC3_0x344_oETC3_oB30_for_SC_CAN_V3_2_8061075a_Rx 81u
#define ComConf_ComSignal_ETC4_0x1F2_oETC4_oB30_for_SC_CAN_V3_2_87dc5b17_Rx 82u
#define ComConf_ComSignal_F_PBOX1_0x19B_oF_PBOX1_oB30_for_SC_CAN_V3_2_d80ac1f1_Rx 83u
#define ComConf_ComSignal_GLO_NASS1_0x56_oGLO_NASS1_oB30_for_SC_CAN_V3_2_db007902_Rx 84u
#define ComConf_ComSignal_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx 85u
#define ComConf_ComSignal_GW_OTA_0x1D9_oGW_OTA_oB30_for_SC_CAN_V3_2_30df0d5c_Rx 86u
#define ComConf_ComSignal_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx 87u
#define ComConf_ComSignal_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx 88u
#define ComConf_ComSignal_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx 89u
#define ComConf_ComSignal_HAP_FD6_0x289_oHAP_FD6_oB30_for_SC_CAN_V3_2_78575c1f_Rx 90u
#define ComConf_ComSignal_HAP_FD7_0x29B_oHAP_FD7_oB30_for_SC_CAN_V3_2_9ca8fc22_Rx 91u
#define ComConf_ComSignal_HCM_L1_0x308_oHCM_L1_oB30_for_SC_CAN_V3_2_b65b4e09_Rx 92u
#define ComConf_ComSignal_HCM_L2_0x304_oHCM_L2_oB30_for_SC_CAN_V3_2_22360a96_Rx 93u
#define ComConf_ComSignal_HCM_R1_0x30D_oHCM_R1_oB30_for_SC_CAN_V3_2_10025674_Rx 94u
#define ComConf_ComSignal_HCM_R2_0x330_oHCM_R2_oB30_for_SC_CAN_V3_2_26c487d6_Rx 95u
#define ComConf_ComSignal_HCU_FD1_0x60_oHCU_FD1_oB30_for_SC_CAN_V3_2_3ebe3c03_Rx 96u
#define ComConf_ComSignal_HCU_HC3_0x268_oHCU_HC3_oB30_for_SC_CAN_V3_2_69b49564_Rx 97u
#define ComConf_ComSignal_HCU_HC6_0x314_oHCU_HC6_oB30_for_SC_CAN_V3_2_0e5944ae_Rx 98u
#define ComConf_ComSignal_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx 99u
#define ComConf_ComSignal_HCU_HC8_0x1E2_oHCU_HC8_oB30_for_SC_CAN_V3_2_c53eaa25_Rx 100u
#define ComConf_ComSignal_HCU_HC16_0x9E_oHCU_HC16_oB30_for_SC_CAN_V3_2_40590207_Rx 101u
#define ComConf_ComSignal_HCU_HP5_0x201_oHCU_HP5_oB30_for_SC_CAN_V3_2_10dd4439_Rx 102u
#define ComConf_ComSignal_HCU_HP6_0x11A_oHCU_HP6_oB30_for_SC_CAN_V3_2_3fe3cb15_Rx 103u
#define ComConf_ComSignal_HCU_HP8_0xF9_oHCU_HP8_oB30_for_SC_CAN_V3_2_1d9304d5_Rx 104u
#define ComConf_ComSignal_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx 105u
#define ComConf_ComSignal_HCU_PT5_0x14A_oHCU_PT5_oB30_for_SC_CAN_V3_2_004da173_Rx 106u
#define ComConf_ComSignal_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx 107u
#define ComConf_ComSignal_HCU_PT8_0x1C0_oHCU_PT8_oB30_for_SC_CAN_V3_2_c294c705_Rx 108u
#define ComConf_ComSignal_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx 109u
#define ComConf_ComSignal_IFC1_0x109_oIFC1_oB30_for_SC_CAN_V3_2_1195757e_Rx 110u
#define ComConf_ComSignal_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx 111u
#define ComConf_ComSignal_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx 112u
#define ComConf_ComSignal_IFC_FD5_0x19F_oIFC_FD5_oB30_for_SC_CAN_V3_2_ac61e9de_Rx 113u
#define ComConf_ComSignal_IFC_FD6_0x222_oIFC_FD6_oB30_for_SC_CAN_V3_2_6311fcf7_Rx 114u
#define ComConf_ComSignal_Ibooster_FD2_0x120_oIbooster_FD2_oB30_for_SC_CAN_V3_2_a4812faa_Rx 115u
#define ComConf_ComSignal_OBC1_0x316_oOBC1_oB30_for_SC_CAN_V3_2_8dbaa55f_Rx 116u
#define ComConf_ComSignal_OBC2_0x317_oOBC2_oB30_for_SC_CAN_V3_2_d8f10658_Rx 117u
#define ComConf_ComSignal_P2M1_0xAC_oP2M1_oB30_for_SC_CAN_V3_2_369d99f8_Rx 118u
#define ComConf_ComSignal_P2M3_0xBE_oP2M3_oB30_for_SC_CAN_V3_2_d59c14bc_Rx 119u
#define ComConf_ComSignal_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx 120u
#define ComConf_ComSignal_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx 121u
#define ComConf_ComSignal_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx 122u
#define ComConf_ComSignal_RFCM_L1_0x332_oRFCM_L1_oB30_for_SC_CAN_V3_2_91cc902c_Rx 123u
#define ComConf_ComSignal_RFCM_R1_0x333_oRFCM_R1_oB30_for_SC_CAN_V3_2_ea29c6d8_Rx 124u
#define ComConf_ComSignal_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx 125u
#define ComConf_ComSignal_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx 126u
#define ComConf_ComSignal_R_PBOX1_0x19C_oR_PBOX1_oB30_for_SC_CAN_V3_2_a642ab1f_Rx 127u
#define ComConf_ComSignal_SCM1_0x2D1_oSCM1_oB30_for_SC_CAN_V3_2_07ffa3ae_Rx 128u
#define ComConf_ComSignal_TOD1_0x251_oTOD1_oB30_for_SC_CAN_V3_2_d5e91403_Rx 129u
#define ComConf_ComSignal_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx 130u
#define ComConf_ComSignal_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx 131u
#define ComConf_ComSignal_T_BOX_FD1_0x33_oT_BOX_FD1_oB30_for_SC_CAN_V3_2_f218711f_Rx 132u
#define ComConf_ComSignal_T_BOX_FD3_0x3E9_oT_BOX_FD3_oB30_for_SC_CAN_V3_2_4f9ede14_Rx 133u
#define ComConf_ComSignal_T_BOX_FD4_0x1E1_oT_BOX_FD4_oB30_for_SC_CAN_V3_2_30217c42_Rx 134u
#define ComConf_ComSignal_T_BOX_FD9_0x1FE_oT_BOX_FD9_oB30_for_SC_CAN_V3_2_a242690e_Rx 135u
#define ComConf_ComSignal_T_BOX_FD10_0x2F0_oT_BOX_FD10_oB30_for_SC_CAN_V3_2_8b5da6a2_Rx 136u
#define ComConf_ComSignal_Trailer1_0x273_oTrailer1_oB30_for_SC_CAN_V3_2_e6f8aad9_Rx 137u
#define ComConf_ComSignal_VMDR1_0x2FB_oVMDR1_oB30_for_SC_CAN_V3_2_7f271e6c_Rx 138u
#define ComConf_ComSignal_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx 139u
#define ComConf_ComSignal_null_oGW_Sync_Req_oB30_for_SC_CAN_V3_2_dbe97aeb_Rx 140u
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_ComSignal_Cluster_Debug_Msg_0x7AB_Tx        0u
#define ComConf_ComSignal_ComSignal_Cluster_Debug_Msg_0x7AC_Tx        1u
#define ComConf_ComSignal_ComSignal_Cluster_Debug_Msg_0x7AD_Tx        2u
#define ComConf_ComSignal_ComSignal_Cluster_Debug_Msg_0x7AE_Tx        3u
#define ComConf_ComSignal_ComSignal_Cluster_Debug_Msg_0x7AF_Tx        4u
#define ComConf_ComSignal_ComSignal_userData_byte2_tx                 5u
#define ComConf_ComSignal_ComSignal_userdata_Byte3_tx                 6u
#define ComConf_ComSignal_DMS_FD1_0x24D_oDMS_FD1_oB30_for_SC_CAN_V3_2_d4f63723_Tx 7u
#define ComConf_ComSignal_DVR_FD1_0x2EC_oDVR_FD1_oB30_for_SC_CAN_V3_2_5deb10a1_Tx 8u
#define ComConf_ComSignal_HUT1_0x367_oHUT1_oB30_for_SC_CAN_V3_2_4cf1fae5_Tx 9u
#define ComConf_ComSignal_HUT2_0x369_oHUT2_oB30_for_SC_CAN_V3_2_101c4259_Tx 10u
#define ComConf_ComSignal_HUT3_0x36B_oHUT3_oB30_for_SC_CAN_V3_2_6c58ad50_Tx 11u
#define ComConf_ComSignal_HUT4_0x36D_oHUT4_oB30_for_SC_CAN_V3_2_f3b22adc_Tx 12u
#define ComConf_ComSignal_HUT6_0x4A_oHUT6_oB30_for_SC_CAN_V3_2_d227f5be_Tx 13u
#define ComConf_ComSignal_HUT7_0x44_oHUT7_oB30_for_SC_CAN_V3_2_b4003dd4_Tx 14u
#define ComConf_ComSignal_HUT10_0x331_oHUT10_oB30_for_SC_CAN_V3_2_acd87eba_Tx 15u
#define ComConf_ComSignal_HUT12_0x3AF_oHUT12_oB30_for_SC_CAN_V3_2_e30e4c90_Tx 16u
#define ComConf_ComSignal_HUT13_0x31C_oHUT13_oB30_for_SC_CAN_V3_2_86243622_Tx 17u
#define ComConf_ComSignal_HUT15_0x1EE_oHUT15_oB30_for_SC_CAN_V3_2_ccda2985_Tx 18u
#define ComConf_ComSignal_HUT16_0x348_oHUT16_oB30_for_SC_CAN_V3_2_6a07ebf7_Tx 19u
#define ComConf_ComSignal_HUT17_0x33B_oHUT17_oB30_for_SC_CAN_V3_2_49d9e9b4_Tx 20u
#define ComConf_ComSignal_HUT19_0x415_oHUT19_oB30_for_SC_CAN_V3_2_0070b441_Tx 21u
#define ComConf_ComSignal_HUT20_0x2DE_oHUT20_oB30_for_SC_CAN_V3_2_fd1a0297_Tx 22u
#define ComConf_ComSignal_HUT21_0x2DD_oHUT21_oB30_for_SC_CAN_V3_2_46aba8bb_Tx 23u
#define ComConf_ComSignal_HUT22_0x2DA_oHUT22_oB30_for_SC_CAN_V3_2_c0698017_Tx 24u
#define ComConf_ComSignal_HUT23_0x2D8_oHUT23_oB30_for_SC_CAN_V3_2_f39d4000_Tx 25u
#define ComConf_ComSignal_HUT25_0x339_oHUT25_oB30_for_SC_CAN_V3_2_1c8c4a71_Tx 26u
#define ComConf_ComSignal_HUT26_0x2B6_oHUT26_oB30_for_SC_CAN_V3_2_49efaca1_Tx 27u
#define ComConf_ComSignal_HUT27_0x2B2_oHUT27_oB30_for_SC_CAN_V3_2_c637bd78_Tx 28u
#define ComConf_ComSignal_HUT30_0x1E9_oHUT30_oB30_for_SC_CAN_V3_2_037aee47_Tx 29u
#define ComConf_ComSignal_HUT31_0x30C_oHUT31_oB30_for_SC_CAN_V3_2_cc5f49f9_Tx 30u
#define ComConf_ComSignal_HUT32_0x26F_oHUT32_oB30_for_SC_CAN_V3_2_cd38c3b4_Tx 31u
#define ComConf_ComSignal_HUT33_0x1ED_oHUT33_oB30_for_SC_CAN_V3_2_0dfdacd0_Tx 32u
#define ComConf_ComSignal_HUT34_0x370_oHUT34_oB30_for_SC_CAN_V3_2_f661979e_Tx 33u
#define ComConf_ComSignal_HUT35_0x1E5_oHUT35_oB30_for_SC_CAN_V3_2_f645fa9e_Tx 34u
#define ComConf_ComSignal_HUT36_0x1E6_oHUT36_oB30_for_SC_CAN_V3_2_e1e602ab_Tx 35u
#define ComConf_ComSignal_HUT37_0x1EC_oHUT37_oB30_for_SC_CAN_V3_2_2ba065cf_Tx 36u
#define ComConf_ComSignal_HUT38_0x1E7_oHUT38_oB30_for_SC_CAN_V3_2_4fc17c79_Tx 37u
#define ComConf_ComSignal_HUT39_0x1EB_oHUT39_oB30_for_SC_CAN_V3_2_85871b1d_Tx 38u
#define ComConf_ComSignal_HUT40_0x224_oHUT40_oB30_for_SC_CAN_V3_2_9c3909d3_Tx 39u
#define ComConf_ComSignal_HUT41_0x1FB_oHUT41_oB30_for_SC_CAN_V3_2_982902c7_Tx 40u
#define ComConf_ComSignal_HUT42_0x1F9_oHUT42_oB30_for_SC_CAN_V3_2_07cf90c9_Tx 41u
#define ComConf_ComSignal_HUT43_0x1FD_oHUT43_oB30_for_SC_CAN_V3_2_6355320f_Tx 42u
#define ComConf_ComSignal_HUT45_0x1DC_oHUT45_oB30_for_SC_CAN_V3_2_57d4dd51_Tx 43u
#define ComConf_ComSignal_HUT46_0x1DD_oHUT46_oB30_for_SC_CAN_V3_2_171947b5_Tx 44u
#define ComConf_ComSignal_HUT49_0x1D1_oHUT49_oB30_for_SC_CAN_V3_2_107f8727_Tx 45u
#define ComConf_ComSignal_HUT_FD1_0x2C3_oHUT_FD1_oB30_for_SC_CAN_V3_2_c297c003_Tx 46u
#define ComConf_ComSignal_HUT_FD2_0x203_oHUT_FD2_oB30_for_SC_CAN_V3_2_3a1f5203_Tx 47u
#define ComConf_ComSignal_HUT_FD3_0x243_oHUT_FD3_oB30_for_SC_CAN_V3_2_dc4d3bf6_Tx 48u
#define ComConf_ComSignal_HUT_FD4_0x1DA_oHUT_FD4_oB30_for_SC_CAN_V3_2_7f1aadf2_Tx 49u
#define ComConf_ComSignal_HUT_FD5_0x1DB_oHUT_FD5_oB30_for_SC_CAN_V3_2_fbeae75e_Tx 50u
#define ComConf_ComSignal_IP1_0x293_oIP1_oB30_for_SC_CAN_V3_2_979cdb1f_Tx 51u
#define ComConf_ComSignal_IP2_0x27F_oIP2_oB30_for_SC_CAN_V3_2_b2130702_Tx 52u
#define ComConf_ComSignal_IP3_0x34A_oIP3_oB30_for_SC_CAN_V3_2_20c56bb4_Tx 53u
#define ComConf_ComSignal_SyncRequestMessageId_oHUT_Sync_Req_oB30_for_SC_CAN_V3_2_d94984d1_Tx 54u
#define ComConf_ComSignal_SyncRequstReseverData_oHUT_Sync_Req_oB30_for_SC_CAN_V3_2_92a62205_Tx 55u
/**\} */







/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_ComIPduGroup                             0u
#define ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Rx_4400ad35     2u
#define ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_125a0ab3     3u
#define ComConf_ComIPduGroup_HUT_oB30_for_SC_CAN_V3_2_Tx_HEV          1u
#define ComConf_ComIPduGroup_HUT_oCAN_Rx_f5814658                     4u
#define ComConf_ComIPduGroup_HUT_oCAN_Tx_a3dbe1de                     5u
#define ComConf_ComIPduGroup_HUT_oLIN00_Rx_27d7c1e5                   6u
#define ComConf_ComIPduGroup_HUT_oLIN00_Tx_718d6663                   7u
/**\} */

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
  \defgroup  ComPCGetConstantDuplicatedRootDataMacros  Com Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Com_GetAlwaysActiveTxComIPdusOfPCConfig()                                                   Com_AlwaysActiveTxComIPdus  /**< the pointer to Com_AlwaysActiveTxComIPdus */
#define Com_GetCbkRxTOutFuncPtrIndOfPCConfig()                                                      Com_CbkRxTOutFuncPtrInd  /**< the pointer to Com_CbkRxTOutFuncPtrInd */
#define Com_GetCbkRxTOutFuncPtrOfPCConfig()                                                         Com_CbkRxTOutFuncPtr  /**< the pointer to Com_CbkRxTOutFuncPtr */
#define Com_GetCbkTxAckDefFuncPtrIndOfPCConfig()                                                    Com_CbkTxAckDefFuncPtrInd  /**< the pointer to Com_CbkTxAckDefFuncPtrInd */
#define Com_GetCbkTxAckDefFuncPtrOfPCConfig()                                                       Com_CbkTxAckDefFuncPtr  /**< the pointer to Com_CbkTxAckDefFuncPtr */
#define Com_GetConfigIdOfPCConfig()                                                                 0u  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueArrayBasedOfPCConfig()                                                     Com_ConstValueArrayBased  /**< the pointer to Com_ConstValueArrayBased */
#define Com_GetCurrentTxModeOfPCConfig()                                                            Com_CurrentTxMode  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                                                             Com_CycleTimeCnt  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                                                        Com_CyclicSendRequest  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetDelayTimeCntOfPCConfig()                                                             Com_DelayTimeCnt  /**< the pointer to Com_DelayTimeCnt */
#define Com_GetHandleRxPduDeferredOfPCConfig()                                                      Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetHandleTxPduDeferredOfPCConfig()                                                      Com_HandleTxPduDeferred  /**< the pointer to Com_HandleTxPduDeferred */
#define Com_GetIPduGroupInfoOfPCConfig()                                                            Com_IPduGroupInfo  /**< the pointer to Com_IPduGroupInfo */
#define Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfRxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              Com_IPduGroupInfoOfTxPduInfoInd  /**< the pointer to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          Com_IPduGroupInfoToSubIPduGroupsInd  /**< the pointer to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetIPduGroupStateOfPCConfig()                                                           Com_IPduGroupState  /**< the pointer to Com_IPduGroupState */
#define Com_GetInitializedOfPCConfig()                                                              (&(Com_Initialized))  /**< the pointer to Com_Initialized */
#define Com_GetPduGrpCntOfPCConfig()                                                                0u
#define Com_GetRxAccessInfoIndOfPCConfig()                                                          Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                                                             Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxCbkFuncPtrOfPCConfig()                                                             Com_RxCbkFuncPtr  /**< the pointer to Com_RxCbkFuncPtr */
#define Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig()                                       (&(Com_RxDeadlineMonitoringISRLockCounter))  /**< the pointer to Com_RxDeadlineMonitoringISRLockCounter */
#define Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()                                     1u
#define Com_GetRxDefPduBufferOfPCConfig()                                                           Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxDeferredFctPtrCacheOfPCConfig()                                                    Com_RxDeferredFctPtrCache  /**< the pointer to Com_RxDeferredFctPtrCache */
#define Com_GetRxDeferredProcessingISRLockCounterOfPCConfig()                                       (&(Com_RxDeferredProcessingISRLockCounter))  /**< the pointer to Com_RxDeferredProcessingISRLockCounter */
#define Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()                                     1u
#define Com_GetRxIPduGroupISRLockCounterOfPCConfig()                                                (&(Com_RxIPduGroupISRLockCounter))  /**< the pointer to Com_RxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetRxPduCalloutFuncPtrOfPCConfig()                                                      Com_RxPduCalloutFuncPtr  /**< the pointer to Com_RxPduCalloutFuncPtr */
#define Com_GetRxPduDmStateOfPCConfig()                                                             Com_RxPduDmState  /**< the pointer to Com_RxPduDmState */
#define Com_GetRxPduGrpActiveOfPCConfig()                                                           Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduInfoIndOfPCConfig()                                                             Com_RxPduInfoInd  /**< the pointer to Com_RxPduInfoInd */
#define Com_GetRxPduInfoOfPCConfig()                                                                Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxSigBufferArrayBasedOfPCConfig()                                                    Com_RxSigBufferArrayBased  /**< the pointer to Com_RxSigBufferArrayBased */
#define Com_GetRxSigInfoOfPCConfig()                                                                Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetRxTOutCntOfPCConfig()                                                                Com_RxTOutCnt  /**< the pointer to Com_RxTOutCnt */
#define Com_GetRxTOutInfoIndOfPCConfig()                                                            Com_RxTOutInfoInd  /**< the pointer to Com_RxTOutInfoInd */
#define Com_GetRxTOutInfoOfPCConfig()                                                               Com_RxTOutInfo  /**< the pointer to Com_RxTOutInfo */
#define Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Com_AlwaysActiveTxComIPdus */
#define Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                                                47u  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtrInd */
#define Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()                                                   47u  /**< the number of accomplishable value elements in Com_CbkRxTOutFuncPtr */
#define Com_GetSizeOfCbkTxAckDefFuncPtrIndOfPCConfig()                                              47u  /**< the number of accomplishable value elements in Com_CbkTxAckDefFuncPtrInd */
#define Com_GetSizeOfCbkTxAckDefFuncPtrOfPCConfig()                                                 47u  /**< the number of accomplishable value elements in Com_CbkTxAckDefFuncPtr */
#define Com_GetSizeOfConstValueArrayBasedOfPCConfig()                                               671u  /**< the number of accomplishable value elements in Com_ConstValueArrayBased */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                                                141u  /**< the number of accomplishable value elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfIPduGroupInfoOfPCConfig()                                                      8u  /**< the number of accomplishable value elements in Com_IPduGroupInfo */
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        142u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfRxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        103u  /**< the number of accomplishable value elements in Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    8u  /**< the number of accomplishable value elements in Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                                                    141u  /**< the number of accomplishable value elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                                                       141u  /**< the number of accomplishable value elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxCbkFuncPtrOfPCConfig()                                                       49u  /**< the number of accomplishable value elements in Com_RxCbkFuncPtr */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                                                     2616u  /**< the number of accomplishable value elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()                                              1u  /**< the number of accomplishable value elements in Com_RxDeferredFctPtrCache */
#define Com_GetSizeOfRxPduCalloutFuncPtrOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Com_RxPduCalloutFuncPtr */
#define Com_GetSizeOfRxPduInfoIndOfPCConfig()                                                       142u  /**< the number of accomplishable value elements in Com_RxPduInfoInd */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                                                          141u  /**< the number of accomplishable value elements in Com_RxPduInfo */
#define Com_GetSizeOfRxSigBufferArrayBasedOfPCConfig()                                              2616u  /**< the number of accomplishable value elements in Com_RxSigBufferArrayBased */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                                                          141u  /**< the number of accomplishable value elements in Com_RxSigInfo */
#define Com_GetSizeOfRxTOutInfoIndOfPCConfig()                                                      47u  /**< the number of accomplishable value elements in Com_RxTOutInfoInd */
#define Com_GetSizeOfRxTOutInfoOfPCConfig()                                                         47u  /**< the number of accomplishable value elements in Com_RxTOutInfo */
#define Com_GetSizeOfTmpRxBufferOfPCConfig()                                                        64u  /**< the number of accomplishable value elements in Com_TmpRxBuffer */
#define Com_GetSizeOfTxBufferOfPCConfig()                                                           1110u  /**< the number of accomplishable value elements in Com_TxBuffer */
#define Com_GetSizeOfTxCyclicPduOfPCConfig()                                                        47u  /**< the number of accomplishable value elements in Com_TxCyclicPdu */
#define Com_GetSizeOfTxModeFalseOfPCConfig()                                                        8u  /**< the number of accomplishable value elements in Com_TxModeFalse */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                                                         54u  /**< the number of accomplishable value elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                                                         8u  /**< the number of accomplishable value elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduCalloutFuncPtrOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Com_TxPduCalloutFuncPtr */
#define Com_GetSizeOfTxPduInfoIndOfPCConfig()                                                       103u  /**< the number of accomplishable value elements in Com_TxPduInfoInd */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                                                          54u  /**< the number of accomplishable value elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                                                     1110u  /**< the number of accomplishable value elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxPduTTCalloutFuncPtrOfPCConfig()                                              1u  /**< the number of accomplishable value elements in Com_TxPduTTCalloutFuncPtr */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                                                          56u  /**< the number of accomplishable value elements in Com_TxSigInfo */
#define Com_GetTmpRxBufferOfPCConfig()                                                              Com_TmpRxBuffer  /**< the pointer to Com_TmpRxBuffer */
#define Com_GetTransmitRequestOfPCConfig()                                                          Com_TransmitRequest  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxBufferOfPCConfig()                                                                 Com_TxBuffer  /**< the pointer to Com_TxBuffer */
#define Com_GetTxCyclicPduOfPCConfig()                                                              Com_TxCyclicPdu  /**< the pointer to Com_TxCyclicPdu */
#define Com_GetTxCyclicProcessingISRLockCounterOfPCConfig()                                         (&(Com_TxCyclicProcessingISRLockCounter))  /**< the pointer to Com_TxCyclicProcessingISRLockCounter */
#define Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()                                       1u
#define Com_GetTxIPduGroupISRLockCounterOfPCConfig()                                                (&(Com_TxIPduGroupISRLockCounter))  /**< the pointer to Com_TxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockThresholdOfPCConfig()                                              1u
#define Com_GetTxModeFalseOfPCConfig()                                                              Com_TxModeFalse  /**< the pointer to Com_TxModeFalse */
#define Com_GetTxModeInfoOfPCConfig()                                                               Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                                               Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduCalloutFuncPtrOfPCConfig()                                                      Com_TxPduCalloutFuncPtr  /**< the pointer to Com_TxPduCalloutFuncPtr */
#define Com_GetTxPduGrpActiveOfPCConfig()                                                           Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduInfoIndOfPCConfig()                                                             Com_TxPduInfoInd  /**< the pointer to Com_TxPduInfoInd */
#define Com_GetTxPduInfoOfPCConfig()                                                                Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                                                           Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxPduTTCalloutFuncPtrOfPCConfig()                                                    Com_TxPduTTCalloutFuncPtr  /**< the pointer to Com_TxPduTTCalloutFuncPtr */
#define Com_GetTxProcessingISRLockCounterOfPCConfig()                                               (&(Com_TxProcessingISRLockCounter))  /**< the pointer to Com_TxProcessingISRLockCounter */
#define Com_GetTxProcessingISRLockThresholdOfPCConfig()                                             1u
#define Com_GetTxSduLengthOfPCConfig()                                                              Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxSigInfoOfPCConfig()                                                                Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDuplicatedRootDataMacros  Com Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                                                      Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                                                       Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                                                  Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CyclicSendRequest */
#define Com_GetSizeOfDelayTimeCntOfPCConfig()                                                       Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_DelayTimeCnt */
#define Com_GetSizeOfHandleTxPduDeferredOfPCConfig()                                                Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_HandleTxPduDeferred */
#define Com_GetSizeOfIPduGroupStateOfPCConfig()                                                     Com_GetSizeOfIPduGroupInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_IPduGroupState */
#define Com_GetSizeOfRxPduDmStateOfPCConfig()                                                       Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduDmState */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduGrpActive */
#define Com_GetSizeOfRxTOutCntOfPCConfig()                                                          Com_GetSizeOfRxTOutInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxTOutCnt */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                                                    Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TransmitRequest */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                                                     Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                                                        Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxSduLength */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDataMacros  Com Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetCbkRxTOutFuncPtr(Index)                                                              (Com_GetCbkRxTOutFuncPtrOfPCConfig()[(Index)])
#define Com_GetCbkTxAckDefFuncPtr(Index)                                                            (Com_GetCbkTxAckDefFuncPtrOfPCConfig()[(Index)])
#define Com_GetConstValueArrayBased(Index)                                                          (Com_GetConstValueArrayBasedOfPCConfig()[(Index)])
#define Com_IsCurrentTxMode(Index)                                                                  ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                                                  (Com_GetCycleTimeCntOfPCConfig()[(Index)])
#define Com_IsCyclicSendRequest(Index)                                                              ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetDelayTimeCnt(Index)                                                                  (Com_GetDelayTimeCntOfPCConfig()[(Index)])
#define Com_GetHandleRxPduDeferred(Index)                                                           (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)])
#define Com_IsHandleTxPduDeferred(Index)                                                            ((Com_GetHandleTxPduDeferredOfPCConfig()[(Index)]) != FALSE)
#define Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Index)                                             (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndEndIdxOfIPduGroupInfo)
#define Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index)                                           (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndStartIdxOfIPduGroupInfo)
#define Com_GetIPduGroupInfoOfRxPduInfoInd(Index)                                                   (Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetIPduGroupInfoOfTxPduInfoInd(Index)                                                   (Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetIPduGroupState(Index)                                                                (Com_GetIPduGroupStateOfPCConfig()[(Index)])
#define Com_IsInitialized()                                                                         (((*(Com_GetInitializedOfPCConfig()))) != FALSE)
#define Com_GetApplTypeOfRxAccessInfo(Index)                                                        (Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo)
#define Com_GetBitLengthOfRxAccessInfo(Index)                                                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitLengthOfRxAccessInfo)
#define Com_GetBusAccOfRxAccessInfo(Index)                                                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].BusAccOfRxAccessInfo)
#define Com_GetBytePositionOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].BytePositionOfRxAccessInfo)
#define Com_GetConstValueArrayBasedInitValueEndIdxOfRxAccessInfo(Index)                             (Com_GetRxAccessInfoOfPCConfig()[(Index)].ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo)
#define Com_GetConstValueArrayBasedInitValueStartIdxOfRxAccessInfo(Index)                           (Com_GetRxAccessInfoOfPCConfig()[(Index)].ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo)
#define Com_GetRxPduInfoIdxOfRxAccessInfo(Index)                                                    (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxAccessInfo)
#define Com_GetRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo(Index)                               (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo)
#define Com_GetRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo(Index)                             (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo)
#define Com_IsRxSigBufferArrayBasedBufferUsedOfRxAccessInfo(Index)                                  ((Com_GetRxAccessInfoOfPCConfig()[(Index)].RxSigBufferArrayBasedBufferUsedOfRxAccessInfo) != FALSE)
#define Com_GetRxTOutInfoIdxOfRxAccessInfo(Index)                                                   (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxAccessInfo)
#define Com_GetRxAccessInfoInd(Index)                                                               (Com_GetRxAccessInfoIndOfPCConfig()[(Index)])
#define Com_GetRxCbkFuncPtr(Index)                                                                  (Com_GetRxCbkFuncPtrOfPCConfig()[(Index)])
#define Com_GetRxDeadlineMonitoringISRLockCounter()                                                 ((*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())))
#define Com_GetRxDefPduBuffer(Index)                                                                (Com_GetRxDefPduBufferOfPCConfig()[(Index)])
#define Com_GetRxDeferredFctPtrCache(Index)                                                         (Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)])
#define Com_GetRxDeferredProcessingISRLockCounter()                                                 ((*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())))
#define Com_GetRxIPduGroupISRLockCounter()                                                          ((*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())))
#define Com_GetRxPduCalloutFuncPtr(Index)                                                           (Com_GetRxPduCalloutFuncPtrOfPCConfig()[(Index)])
#define Com_GetRxPduDmState(Index)                                                                  (Com_GetRxPduDmStateOfPCConfig()[(Index)])
#define Com_IsRxPduGrpActive(Index)                                                                 ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Index)                                  (Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo)
#define Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index)                                (Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo)
#define Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)                                     ((Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo) != FALSE)
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                                               (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferEndIdxOfRxPduInfo)
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)                                             (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIdxOfRxPduInfo(Index)                                                      (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Index)                                                (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndEndIdxOfRxPduInfo)
#define Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index)                                              (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndStartIdxOfRxPduInfo)
#define Com_IsRxTOutInfoUsedOfRxPduInfo(Index)                                                      ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoUsedOfRxPduInfo) != FALSE)
#define Com_GetSignalProcessingOfRxPduInfo(Index)                                                   (Com_GetRxPduInfoOfPCConfig()[(Index)].SignalProcessingOfRxPduInfo)
#define Com_GetRxPduInfoInd(Index)                                                                  (Com_GetRxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetRxSigBufferArrayBased(Index)                                                         (Com_GetRxSigBufferArrayBasedOfPCConfig()[(Index)])
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                                                    (Com_GetRxSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxSigInfo)
#define Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index)                                                 (Com_GetRxSigInfoOfPCConfig()[(Index)].RxCbkFuncPtrAckIdxOfRxSigInfo)
#define Com_GetRxTOutInfoIdxOfRxSigInfo(Index)                                                      (Com_GetRxSigInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigInfo)
#define Com_GetSignalProcessingOfRxSigInfo(Index)                                                   (Com_GetRxSigInfoOfPCConfig()[(Index)].SignalProcessingOfRxSigInfo)
#define Com_GetValidDlcOfRxSigInfo(Index)                                                           (Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo)
#define Com_GetRxTOutCnt(Index)                                                                     (Com_GetRxTOutCntOfPCConfig()[(Index)])
#define Com_GetFactorOfRxTOutInfo(Index)                                                            (Com_GetRxTOutInfoOfPCConfig()[(Index)].FactorOfRxTOutInfo)
#define Com_GetFirstFactorOfRxTOutInfo(Index)                                                       (Com_GetRxTOutInfoOfPCConfig()[(Index)].FirstFactorOfRxTOutInfo)
#define Com_GetRxPduInfoIdxOfRxTOutInfo(Index)                                                      (Com_GetRxTOutInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxTOutInfo)
#define Com_GetTmpRxBuffer(Index)                                                                   (Com_GetTmpRxBufferOfPCConfig()[(Index)])
#define Com_IsTransmitRequest(Index)                                                                ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxBuffer(Index)                                                                      (Com_GetTxBufferOfPCConfig()[(Index)])
#define Com_GetTxPduInfoIdxOfTxCyclicPdu(Index)                                                     (Com_GetTxCyclicPduOfPCConfig()[(Index)].TxPduInfoIdxOfTxCyclicPdu)
#define Com_GetTxCyclicProcessingISRLockCounter()                                                   ((*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxIPduGroupISRLockCounter()                                                          ((*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())))
#define Com_IsDirectOfTxModeFalse(Index)                                                            ((Com_GetTxModeFalseOfPCConfig()[(Index)].DirectOfTxModeFalse) != FALSE)
#define Com_GetTimePeriodOfTxModeFalse(Index)                                                       (Com_GetTxModeFalseOfPCConfig()[(Index)].TimePeriodOfTxModeFalse)
#define Com_IsInitModeOfTxModeInfo(Index)                                                           ((Com_GetTxModeInfoOfPCConfig()[(Index)].InitModeOfTxModeInfo) != FALSE)
#define Com_GetMinimumDelayOfTxModeInfo(Index)                                                      (Com_GetTxModeInfoOfPCConfig()[(Index)].MinimumDelayOfTxModeInfo)
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                                                     (Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueIdxOfTxModeInfo)
#define Com_IsDirectOfTxModeTrue(Index)                                                             ((Com_GetTxModeTrueOfPCConfig()[(Index)].DirectOfTxModeTrue) != FALSE)
#define Com_GetTimePeriodOfTxModeTrue(Index)                                                        (Com_GetTxModeTrueOfPCConfig()[(Index)].TimePeriodOfTxModeTrue)
#define Com_GetTxPduCalloutFuncPtr(Index)                                                           (Com_GetTxPduCalloutFuncPtrOfPCConfig()[(Index)])
#define Com_IsTxPduGrpActive(Index)                                                                 ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCbkTxAckDefFuncPtrIndEndIdxOfTxPduInfo(Index)                                        (Com_GetTxPduInfoOfPCConfig()[(Index)].CbkTxAckDefFuncPtrIndEndIdxOfTxPduInfo)
#define Com_GetCbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo(Index)                                      (Com_GetTxPduInfoOfPCConfig()[(Index)].CbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo)
#define Com_GetExternalIdOfTxPduInfo(Index)                                                         (Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Index)                                  (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo)
#define Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index)                                (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo)
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                                                     (Com_GetTxPduInfoOfPCConfig()[(Index)].MetaDataLengthOfTxPduInfo)
#define Com_GetTxBufferLengthOfTxPduInfo(Index)                                                     (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferLengthOfTxPduInfo)
#define Com_GetTxPduCalloutFuncPtrIdxOfTxPduInfo(Index)                                             (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduCalloutFuncPtrIdxOfTxPduInfo)
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                                               (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo)
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)                                             (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo)
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                                                  ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueUsedOfTxPduInfo) != FALSE)
#define Com_GetTxPduTTCalloutFuncPtrIdxOfTxPduInfo(Index)                                           (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduTTCalloutFuncPtrIdxOfTxPduInfo)
#define Com_IsTxPduTTCalloutFuncPtrUsedOfTxPduInfo(Index)                                           ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduTTCalloutFuncPtrUsedOfTxPduInfo) != FALSE)
#define Com_GetTxPduInfoInd(Index)                                                                  (Com_GetTxPduInfoIndOfPCConfig()[(Index)])
#define Com_GetTxPduInitValue(Index)                                                                (Com_GetTxPduInitValueOfPCConfig()[(Index)])
#define Com_GetTxPduTTCalloutFuncPtr(Index)                                                         (Com_GetTxPduTTCalloutFuncPtrOfPCConfig()[(Index)])
#define Com_GetTxProcessingISRLockCounter()                                                         ((*(Com_GetTxProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxSduLength(Index)                                                                   (Com_GetTxSduLengthOfPCConfig()[(Index)])
#define Com_GetApplTypeOfTxSigInfo(Index)                                                           (Com_GetTxSigInfoOfPCConfig()[(Index)].ApplTypeOfTxSigInfo)
#define Com_GetBitLengthOfTxSigInfo(Index)                                                          (Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo)
#define Com_GetBitPositionOfTxSigInfo(Index)                                                        (Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo)
#define Com_GetBusAccOfTxSigInfo(Index)                                                             (Com_GetTxSigInfoOfPCConfig()[(Index)].BusAccOfTxSigInfo)
#define Com_GetByteLengthOfTxSigInfo(Index)                                                         (Com_GetTxSigInfoOfPCConfig()[(Index)].ByteLengthOfTxSigInfo)
#define Com_GetStartByteInPduPositionOfTxSigInfo(Index)                                             (Com_GetTxSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxSigInfo)
#define Com_GetTxBufferEndIdxOfTxSigInfo(Index)                                                     (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxSigInfo)
#define Com_GetTxBufferStartIdxOfTxSigInfo(Index)                                                   (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigInfo)
#define Com_GetTxPduInfoIdxOfTxSigInfo(Index)                                                       (Com_GetTxSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigInfo)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDeduplicatedDataMacros  Com Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetTxPduInfoIdxOfAlwaysActiveTxComIPdus(Index)                                          ((Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetCbkRxTOutFuncPtrInd(Index)                                                           ((Com_CbkRxTOutFuncPtrIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_CbkRxTOutFuncPtr */
#define Com_GetCbkTxAckDefFuncPtrInd(Index)                                                         ((Com_CbkTxAckDefFuncPtrIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_CbkTxAckDefFuncPtr */
#define Com_GetConfigId()                                                                           Com_GetConfigIdOfPCConfig()
#define Com_GetIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo(Index)                          ((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)((((Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index)                        ((Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo(Index)                             (((boolean)(Com_GetIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo(Index) != COM_NO_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoToSubIPduGroupsInd */
#define Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Index)                                                (((boolean)(Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxPduInfoInd */
#define Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Index)                                                (((boolean)(Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInfoInd */
#define Com_GetIPduGroupInfoToSubIPduGroupsInd(Index)                                               ((Com_IPduGroupInfoToSubIPduGroupsIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo */
#define Com_GetPduGrpCnt()                                                                          Com_GetPduGrpCntOfPCConfig()
#define Com_GetBitPositionOfRxAccessInfo(Index)                                                     Com_GetBytePositionOfRxAccessInfo(Index)  /**< Little endian bit position of the signal or group signal within the I-PDU. */
#define Com_GetByteLengthOfRxAccessInfo(Index)                                                      Com_GetConstValueArrayBasedInitValueLengthOfRxAccessInfo(Index)  /**< Byte length of the signal or group signal. */
#define Com_GetConstValueArrayBasedInitValueLengthOfRxAccessInfo(Index)                             ((Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfoType)((Com_GetConstValueArrayBasedInitValueEndIdxOfRxAccessInfo(Index) - Com_GetConstValueArrayBasedInitValueStartIdxOfRxAccessInfo(Index))))  /**< the number of relations pointing to Com_ConstValueArrayBased */
#define Com_IsConstValueArrayBasedInitValueUsedOfRxAccessInfo(Index)                                Com_IsRxSigBufferArrayBasedBufferUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_ConstValueArrayBased */
#define Com_GetRxSigBufferArrayBasedBufferLengthOfRxAccessInfo(Index)                               ((Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfoType)((Com_GetRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo(Index) - Com_GetRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo(Index))))  /**< the number of relations pointing to Com_RxSigBufferArrayBased */
#define Com_IsRxTOutInfoUsedOfRxAccessInfo(Index)                                                   (((boolean)(Com_GetRxTOutInfoIdxOfRxAccessInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXACCESSINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_GetStartByteInPduPositionOfRxAccessInfo(Index)                                          Com_GetBytePositionOfRxAccessInfo(Index)  /**< Start Byte position of the signal or group signal within the I-PDU. */
#define Com_GetRxDeadlineMonitoringISRLockThreshold()                                               Com_GetRxDeadlineMonitoringISRLockThresholdOfPCConfig()
#define Com_GetRxDeferredProcessingISRLockThreshold()                                               Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()
#define Com_GetRxIPduGroupISRLockThreshold()                                                        Com_GetRxIPduGroupISRLockThresholdOfPCConfig()
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)                                             ((Com_HandleRxPduDeferredIdxOfRxPduInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)                                             Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                                              ((Com_RxAccessInfoIndEndIdxOfRxPduInfoType)((((Com_RxAccessInfoIndEndIdxOfRxPduInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)                                            ((Com_RxAccessInfoIndStartIdxOfRxPduInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                                                 Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                                               ((Com_RxDefPduBufferLengthOfRxPduInfoType)((Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index) - Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index))))  /**< the number of relations pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                                                  (((boolean)(Com_GetRxDefPduBufferLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_GetRxPduCalloutFuncPtrIdxOfRxPduInfo(Index)                                             Com_GetSignalProcessingOfRxPduInfo(Index)  /**< the index of the 0:1 relation pointing to Com_RxPduCalloutFuncPtr */
#define Com_IsRxPduCalloutFuncPtrUsedOfRxPduInfo(Index)                                             Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxPduCalloutFuncPtr */
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                                                    ((Com_RxSigInfoEndIdxOfRxPduInfoType)((((Com_RxSigInfoEndIdxOfRxPduInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                                                  ((Com_RxSigInfoStartIdxOfRxPduInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                                                       Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
#define Com_IsRxTOutInfoIndUsedOfRxPduInfo(Index)                                                   Com_IsRxTOutInfoUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxTOutInfoInd */
#define Com_GetTypeOfRxPduInfo(Index)                                                               Com_GetSignalProcessingOfRxPduInfo(Index)  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
#define Com_IsRxCbkFuncPtrAckUsedOfRxSigInfo(Index)                                                 (((boolean)(Com_GetRxCbkFuncPtrAckIdxOfRxSigInfo(Index) != COM_NO_RXCBKFUNCPTRACKIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxCbkFuncPtr */
#define Com_IsRxTOutInfoUsedOfRxSigInfo(Index)                                                      (((boolean)(Com_GetRxTOutInfoIdxOfRxSigInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
#define Com_GetCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo(Index)                                         ((Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType)((((Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType)(Index)) + 1u)))  /**< the end index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
#define Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index)                                       ((Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType)((Index)))  /**< the start index of the 0:n relation pointing to Com_CbkRxTOutFuncPtrInd */
#define Com_IsCbkRxTOutFuncPtrIndUsedOfRxTOutInfo(Index)                                            (((boolean)(Com_GetCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo(Index) != COM_NO_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_CbkRxTOutFuncPtrInd */
#define Com_GetRxTOutInfoInd(Index)                                                                 ((Com_RxTOutInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_RxTOutInfo */
#define Com_GetSizeOfAlwaysActiveTxComIPdus()                                                       Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtr()                                                             Com_GetSizeOfCbkRxTOutFuncPtrOfPCConfig()
#define Com_GetSizeOfCbkRxTOutFuncPtrInd()                                                          Com_GetSizeOfCbkRxTOutFuncPtrIndOfPCConfig()
#define Com_GetSizeOfCbkTxAckDefFuncPtr()                                                           Com_GetSizeOfCbkTxAckDefFuncPtrOfPCConfig()
#define Com_GetSizeOfCbkTxAckDefFuncPtrInd()                                                        Com_GetSizeOfCbkTxAckDefFuncPtrIndOfPCConfig()
#define Com_GetSizeOfConstValueArrayBased()                                                         Com_GetSizeOfConstValueArrayBasedOfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                                                Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                                                 Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                                                            Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfDelayTimeCnt()                                                                 Com_GetSizeOfDelayTimeCntOfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                                                          Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfHandleTxPduDeferred()                                                          Com_GetSizeOfHandleTxPduDeferredOfPCConfig()
#define Com_GetSizeOfIPduGroupInfo()                                                                Com_GetSizeOfIPduGroupInfoOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              Com_GetSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()
#define Com_GetSizeOfIPduGroupState()                                                               Com_GetSizeOfIPduGroupStateOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                                                 Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                                              Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxCbkFuncPtr()                                                                 Com_GetSizeOfRxCbkFuncPtrOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                                               Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxDeferredFctPtrCache()                                                        Com_GetSizeOfRxDeferredFctPtrCacheOfPCConfig()
#define Com_GetSizeOfRxPduCalloutFuncPtr()                                                          Com_GetSizeOfRxPduCalloutFuncPtrOfPCConfig()
#define Com_GetSizeOfRxPduDmState()                                                                 Com_GetSizeOfRxPduDmStateOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                                               Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                                                    Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfoInd()                                                                 Com_GetSizeOfRxPduInfoIndOfPCConfig()
#define Com_GetSizeOfRxSigBufferArrayBased()                                                        Com_GetSizeOfRxSigBufferArrayBasedOfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                                                    Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfRxTOutCnt()                                                                    Com_GetSizeOfRxTOutCntOfPCConfig()
#define Com_GetSizeOfRxTOutInfo()                                                                   Com_GetSizeOfRxTOutInfoOfPCConfig()
#define Com_GetSizeOfRxTOutInfoInd()                                                                Com_GetSizeOfRxTOutInfoIndOfPCConfig()
#define Com_GetSizeOfTmpRxBuffer()                                                                  Com_GetSizeOfTmpRxBufferOfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                                              Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxBuffer()                                                                     Com_GetSizeOfTxBufferOfPCConfig()
#define Com_GetSizeOfTxCyclicPdu()                                                                  Com_GetSizeOfTxCyclicPduOfPCConfig()
#define Com_GetSizeOfTxModeFalse()                                                                  Com_GetSizeOfTxModeFalseOfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                                                   Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                                                   Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduCalloutFuncPtr()                                                          Com_GetSizeOfTxPduCalloutFuncPtrOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                                               Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                                                    Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfoInd()                                                                 Com_GetSizeOfTxPduInfoIndOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                                               Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxPduTTCalloutFuncPtr()                                                        Com_GetSizeOfTxPduTTCalloutFuncPtrOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                                                  Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                                                    Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_GetTxCyclicProcessingISRLockThreshold()                                                 Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()
#define Com_GetTxIPduGroupISRLockThreshold()                                                        Com_GetTxIPduGroupISRLockThresholdOfPCConfig()
#define Com_IsPeriodicOfTxModeFalse(Index)                                                          (((boolean)(Com_GetTimePeriodOfTxModeFalse(Index) != 0u)) != FALSE)  /**< TRUE if transmission mode contains a cyclic part. */
#define Com_GetTxModeFalseIdxOfTxModeInfo(Index)                                                    Com_GetTxModeTrueIdxOfTxModeInfo(Index)  /**< the index of the 1:1 relation pointing to Com_TxModeFalse */
#define Com_IsPeriodicOfTxModeTrue(Index)                                                           (((boolean)(Com_GetTimePeriodOfTxModeTrue(Index) != 0u)) != FALSE)  /**< TRUE if transmission mode contains a cyclic part. */
#define Com_IsCbkTxAckDefFuncPtrIndUsedOfTxPduInfo(Index)                                           (((boolean)(Com_GetCbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo(Index) != COM_NO_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_CbkTxAckDefFuncPtrInd */
#define Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Index)                                     (((!(Com_IsTxPduTTCalloutFuncPtrUsedOfTxPduInfo(Index)))) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                                              Com_GetTxBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxBufferEndIdxOfTxPduInfo(Index)                                                     Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferStartIdxOfTxPduInfo(Index)                                                   Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxPduInfo(Index)                                                        Com_IsTxPduInitValueUsedOfTxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_IsTxPduCalloutFuncPtrUsedOfTxPduInfo(Index)                                             (((boolean)(Com_GetTxPduCalloutFuncPtrIdxOfTxPduInfo(Index) != COM_NO_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxPduCalloutFuncPtr */
#define Com_GetTxProcessingISRLockThreshold()                                                       Com_GetTxProcessingISRLockThresholdOfPCConfig()
#define Com_GetBytePositionOfTxSigInfo(Index)                                                       Com_GetStartByteInPduPositionOfTxSigInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_IsTriggeredOfTxSigInfo(Index)                                                           (((boolean)(Com_GetTxPduInfoIdxOfTxSigInfo(Index) == 45u)) != FALSE)  /**< TRUE if signal or group signal has any 'TRIGGERED_*' transfer property. */
#define Com_GetTxBufferLengthOfTxSigInfo(Index)                                                     ((Com_TxBufferLengthOfTxSigInfoType)((Com_GetTxBufferEndIdxOfTxSigInfo(Index) - Com_GetTxBufferStartIdxOfTxSigInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigInfo(Index)                                                        (((boolean)(Com_GetTxBufferLengthOfTxSigInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSetDataMacros  Com Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                                                          Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                                                           Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                                                      Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetDelayTimeCnt(Index, Value)                                                           Com_GetDelayTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleRxPduDeferred(Index, Value)                                                    Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetHandleTxPduDeferred(Index, Value)                                                    Com_GetHandleTxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetIPduGroupState(Index, Value)                                                         Com_GetIPduGroupStateOfPCConfig()[(Index)] = (Value)
#define Com_SetInitialized(Value)                                                                   (*(Com_GetInitializedOfPCConfig())) = (Value)
#define Com_SetRxDeadlineMonitoringISRLockCounter(Value)                                            (*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                                                         Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredFctPtrCache(Index, Value)                                                  Com_GetRxDeferredFctPtrCacheOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredProcessingISRLockCounter(Value)                                            (*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxIPduGroupISRLockCounter(Value)                                                     (*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxPduDmState(Index, Value)                                                           Com_GetRxPduDmStateOfPCConfig()[(Index)] = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                                                         Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferArrayBased(Index, Value)                                                  Com_GetRxSigBufferArrayBasedOfPCConfig()[(Index)] = (Value)
#define Com_SetRxTOutCnt(Index, Value)                                                              Com_GetRxTOutCntOfPCConfig()[(Index)] = (Value)
#define Com_SetTmpRxBuffer(Index, Value)                                                            Com_GetTmpRxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                                                        Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxBuffer(Index, Value)                                                               Com_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxCyclicProcessingISRLockCounter(Value)                                              (*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxIPduGroupISRLockCounter(Value)                                                     (*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                                                         Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxProcessingISRLockCounter(Value)                                                    (*(Com_GetTxProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxSduLength(Index, Value)                                                            Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetAddressOfDataMacros  Com Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueArrayBased(Index)                                                      (&Com_GetConstValueArrayBased(Index))
#define Com_GetAddrRxDefPduBuffer(Index)                                                            (&Com_GetRxDefPduBuffer(Index))
#define Com_GetAddrRxDeferredFctPtrCache(Index)                                                     (&Com_GetRxDeferredFctPtrCache(Index))
#define Com_GetAddrRxSigBufferArrayBased(Index)                                                     (&Com_GetRxSigBufferArrayBased(Index))
#define Com_GetAddrTmpRxBuffer(Index)                                                               (&Com_GetTmpRxBuffer(Index))
#define Com_GetAddrTxBuffer(Index)                                                                  (&Com_GetTxBuffer(Index))
#define Com_GetAddrTxPduInitValue(Index)                                                            (&Com_GetTxPduInitValue(Index))
/** 
  \}
*/ 

/** 
  \defgroup  ComPCHasMacros  Com Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasAlwaysActiveTxComIPdus()                                                             (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfAlwaysActiveTxComIPdus()                                               (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtr()                                                                   (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrInd()                                                                (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtr()                                                                 (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrInd()                                                              (TRUE != FALSE)
#define Com_HasConfigId()                                                                           (TRUE != FALSE)
#define Com_HasConstValueArrayBased()                                                               (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                                                      (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                                                       (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                                                  (TRUE != FALSE)
#define Com_HasDelayTimeCnt()                                                                       (TRUE != FALSE)
#define Com_HasHandleRxPduDeferred()                                                                (TRUE != FALSE)
#define Com_HasHandleTxPduDeferred()                                                                (TRUE != FALSE)
#define Com_HasIPduGroupInfo()                                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo()                               (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo()                             (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo()                                 (TRUE != FALSE)
#define Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasRxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo()                                                (TRUE != FALSE)
#define Com_HasTxPduInfoIndUsedOfIPduGroupInfo()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoInd()                                                        (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsInd()                                                    (TRUE != FALSE)
#define Com_HasIPduGroupState()                                                                     (TRUE != FALSE)
#define Com_HasInitialized()                                                                        (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                                                       (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                                                             (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                                                            (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                                                          (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                                               (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                                                           (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueEndIdxOfRxAccessInfo()                                  (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueLengthOfRxAccessInfo()                                  (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueStartIdxOfRxAccessInfo()                                (TRUE != FALSE)
#define Com_HasConstValueArrayBasedInitValueUsedOfRxAccessInfo()                                    (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxAccessInfo()                                                         (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferLengthOfRxAccessInfo()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo()                                  (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedBufferUsedOfRxAccessInfo()                                      (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxAccessInfo()                                                        (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxAccessInfo()                                                       (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfRxAccessInfo()                                               (TRUE != FALSE)
#define Com_HasRxAccessInfoInd()                                                                    (TRUE != FALSE)
#define Com_HasRxCbkFuncPtr()                                                                       (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounter()                                                 (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThreshold()                                               (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                                                     (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCache()                                                              (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounter()                                                 (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThreshold()                                               (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtr()                                                                (TRUE != FALSE)
#define Com_HasRxPduDmState()                                                                       (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasRxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo()                                         (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                                                     (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtrIdxOfRxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtrUsedOfRxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                                                         (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                                                       (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxPduInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoIndEndIdxOfRxPduInfo()                                                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIndStartIdxOfRxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasRxTOutInfoIndUsedOfRxPduInfo()                                                       (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTypeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasRxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBased()                                                              (TRUE != FALSE)
#define Com_HasRxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                                                         (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckIdxOfRxSigInfo()                                                      (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrAckUsedOfRxSigInfo()                                                     (TRUE != FALSE)
#define Com_HasRxTOutInfoIdxOfRxSigInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoUsedOfRxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasRxTOutCnt()                                                                          (TRUE != FALSE)
#define Com_HasRxTOutInfo()                                                                         (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo()                                              (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo()                                            (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndUsedOfRxTOutInfo()                                                (TRUE != FALSE)
#define Com_HasFactorOfRxTOutInfo()                                                                 (TRUE != FALSE)
#define Com_HasFirstFactorOfRxTOutInfo()                                                            (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxTOutInfo()                                                           (TRUE != FALSE)
#define Com_HasRxTOutInfoInd()                                                                      (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdus()                                                       (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtr()                                                             (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrInd()                                                          (TRUE != FALSE)
#define Com_HasSizeOfCbkTxAckDefFuncPtr()                                                           (TRUE != FALSE)
#define Com_HasSizeOfCbkTxAckDefFuncPtrInd()                                                        (TRUE != FALSE)
#define Com_HasSizeOfConstValueArrayBased()                                                         (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                                                (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                                                            (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCnt()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                                                          (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferred()                                                          (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfo()                                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoInd()                                                  (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsInd()                                              (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupState()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                                              (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtr()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCache()                                                        (TRUE != FALSE)
#define Com_HasSizeOfRxPduCalloutFuncPtr()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmState()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferArrayBased()                                                        (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCnt()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfo()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoInd()                                                                (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBuffer()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                                              (TRUE != FALSE)
#define Com_HasSizeOfTxBuffer()                                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPdu()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalse()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduCalloutFuncPtr()                                                          (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoInd()                                                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                                               (TRUE != FALSE)
#define Com_HasSizeOfTxPduTTCalloutFuncPtr()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                                                  (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                                                    (TRUE != FALSE)
#define Com_HasTmpRxBuffer()                                                                        (TRUE != FALSE)
#define Com_HasTransmitRequest()                                                                    (TRUE != FALSE)
#define Com_HasTxBuffer()                                                                           (TRUE != FALSE)
#define Com_HasTxCyclicPdu()                                                                        (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxCyclicPdu()                                                          (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounter()                                                   (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThreshold()                                                 (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounter()                                                          (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThreshold()                                                        (TRUE != FALSE)
#define Com_HasTxModeFalse()                                                                        (TRUE != FALSE)
#define Com_HasDirectOfTxModeFalse()                                                                (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeFalse()                                                              (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeFalse()                                                            (TRUE != FALSE)
#define Com_HasTxModeInfo()                                                                         (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                                               (TRUE != FALSE)
#define Com_HasMinimumDelayOfTxModeInfo()                                                           (TRUE != FALSE)
#define Com_HasTxModeFalseIdxOfTxModeInfo()                                                         (TRUE != FALSE)
#define Com_HasTxModeTrueIdxOfTxModeInfo()                                                          (TRUE != FALSE)
#define Com_HasTxModeTrue()                                                                         (TRUE != FALSE)
#define Com_HasDirectOfTxModeTrue()                                                                 (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeTrue()                                                               (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeTrue()                                                             (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtr()                                                                (TRUE != FALSE)
#define Com_HasTxPduGrpActive()                                                                     (TRUE != FALSE)
#define Com_HasTxPduInfo()                                                                          (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrIndEndIdxOfTxPduInfo()                                             (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo()                                           (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrIndUsedOfTxPduInfo()                                               (TRUE != FALSE)
#define Com_HasExternalIdOfTxPduInfo()                                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo()                                       (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo()                                     (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo()                                         (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                                                   (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxPduInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxPduInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxPduInfo()                                                            (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtrIdxOfTxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtrUsedOfTxPduInfo()                                                 (TRUE != FALSE)
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                                                    (TRUE != FALSE)
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                                                      (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtrIdxOfTxPduInfo()                                                (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtrUsedOfTxPduInfo()                                               (TRUE != FALSE)
#define Com_HasTxPduInfoInd()                                                                       (TRUE != FALSE)
#define Com_HasTxPduInitValue()                                                                     (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtr()                                                              (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounter()                                                         (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThreshold()                                                       (TRUE != FALSE)
#define Com_HasTxSduLength()                                                                        (TRUE != FALSE)
#define Com_HasTxSigInfo()                                                                          (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                                                (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                                               (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                                                             (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                                                  (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                                              (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfTxSigInfo()                                                  (TRUE != FALSE)
#define Com_HasTriggeredOfTxSigInfo()                                                               (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigInfo()                                                          (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigInfo()                                                        (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigInfo()                                                            (TRUE != FALSE)
#define Com_HasPCConfig()                                                                           (TRUE != FALSE)
#define Com_HasAlwaysActiveTxComIPdusOfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrIndOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasCbkRxTOutFuncPtrOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrIndOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasCbkTxAckDefFuncPtrOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasConstValueArrayBasedOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasDelayTimeCntOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasHandleTxPduDeferredOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                          (TRUE != FALSE)
#define Com_HasIPduGroupStateOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasInitializedOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxCbkFuncPtrOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounterOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockThresholdOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxDeferredFctPtrCacheOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounterOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThresholdOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasRxPduCalloutFuncPtrOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasRxPduDmStateOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasRxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxSigBufferArrayBasedOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxTOutCntOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasRxTOutInfoIndOfPCConfig()                                                            (TRUE != FALSE)
#define Com_HasRxTOutInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasSizeOfAlwaysActiveTxComIPdusOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrIndOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfCbkRxTOutFuncPtrOfPCConfig()                                                   (TRUE != FALSE)
#define Com_HasSizeOfCbkTxAckDefFuncPtrIndOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasSizeOfCbkTxAckDefFuncPtrOfPCConfig()                                                 (TRUE != FALSE)
#define Com_HasSizeOfConstValueArrayBasedOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                                                  (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCntOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfHandleTxPduDeferredOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig()                                        (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupInfoToSubIPduGroupsIndOfPCConfig()                                    (TRUE != FALSE)
#define Com_HasSizeOfIPduGroupStateOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxCbkFuncPtrOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxDeferredFctPtrCacheOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasSizeOfRxPduCalloutFuncPtrOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfRxPduDmStateOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferArrayBasedOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxTOutCntOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoIndOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasSizeOfRxTOutInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTmpRxBufferOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasSizeOfTxBufferOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasSizeOfTxCyclicPduOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalseOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                                                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduCalloutFuncPtrOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoIndOfPCConfig()                                                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduTTCalloutFuncPtrOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                                                        (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTmpRxBufferOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                                                          (TRUE != FALSE)
#define Com_HasTxBufferOfPCConfig()                                                                 (TRUE != FALSE)
#define Com_HasTxCyclicPduOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounterOfPCConfig()                                         (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThresholdOfPCConfig()                                       (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterOfPCConfig()                                                (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThresholdOfPCConfig()                                              (TRUE != FALSE)
#define Com_HasTxModeFalseOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                                               (TRUE != FALSE)
#define Com_HasTxPduCalloutFuncPtrOfPCConfig()                                                      (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxPduInfoIndOfPCConfig()                                                             (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                                                           (TRUE != FALSE)
#define Com_HasTxPduTTCalloutFuncPtrOfPCConfig()                                                    (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterOfPCConfig()                                               (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThresholdOfPCConfig()                                             (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                                              (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIncrementDataMacros  Com Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)++
#define Com_IncDelayTimeCnt(Index)                                                                  Com_GetDelayTimeCnt(Index)++
#define Com_IncHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRxDeadlineMonitoringISRLockCounter()                                                 Com_GetRxDeadlineMonitoringISRLockCounter()++
#define Com_IncRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxDeferredFctPtrCache(Index)                                                         Com_GetRxDeferredFctPtrCache(Index)++
#define Com_IncRxDeferredProcessingISRLockCounter()                                                 Com_GetRxDeferredProcessingISRLockCounter()++
#define Com_IncRxIPduGroupISRLockCounter()                                                          Com_GetRxIPduGroupISRLockCounter()++
#define Com_IncRxSigBufferArrayBased(Index)                                                         Com_GetRxSigBufferArrayBased(Index)++
#define Com_IncRxTOutCnt(Index)                                                                     Com_GetRxTOutCnt(Index)++
#define Com_IncTmpRxBuffer(Index)                                                                   Com_GetTmpRxBuffer(Index)++
#define Com_IncTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)++
#define Com_IncTxCyclicProcessingISRLockCounter()                                                   Com_GetTxCyclicProcessingISRLockCounter()++
#define Com_IncTxIPduGroupISRLockCounter()                                                          Com_GetTxIPduGroupISRLockCounter()++
#define Com_IncTxProcessingISRLockCounter()                                                         Com_GetTxProcessingISRLockCounter()++
#define Com_IncTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComPCDecrementDataMacros  Com Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                                                  Com_GetCycleTimeCnt(Index)--
#define Com_DecDelayTimeCnt(Index)                                                                  Com_GetDelayTimeCnt(Index)--
#define Com_DecHandleRxPduDeferred(Index)                                                           Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRxDeadlineMonitoringISRLockCounter()                                                 Com_GetRxDeadlineMonitoringISRLockCounter()--
#define Com_DecRxDefPduBuffer(Index)                                                                Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxDeferredFctPtrCache(Index)                                                         Com_GetRxDeferredFctPtrCache(Index)--
#define Com_DecRxDeferredProcessingISRLockCounter()                                                 Com_GetRxDeferredProcessingISRLockCounter()--
#define Com_DecRxIPduGroupISRLockCounter()                                                          Com_GetRxIPduGroupISRLockCounter()--
#define Com_DecRxSigBufferArrayBased(Index)                                                         Com_GetRxSigBufferArrayBased(Index)--
#define Com_DecRxTOutCnt(Index)                                                                     Com_GetRxTOutCnt(Index)--
#define Com_DecTmpRxBuffer(Index)                                                                   Com_GetTmpRxBuffer(Index)--
#define Com_DecTxBuffer(Index)                                                                      Com_GetTxBuffer(Index)--
#define Com_DecTxCyclicProcessingISRLockCounter()                                                   Com_GetTxCyclicProcessingISRLockCounter()--
#define Com_DecTxIPduGroupISRLockCounter()                                                          Com_GetTxIPduGroupISRLockCounter()--
#define Com_DecTxProcessingISRLockCounter()                                                         Com_GetTxProcessingISRLockCounter()--
#define Com_DecTxSduLength(Index)                                                                   Com_GetTxSduLength(Index)--
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


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCIterableTypes  Com Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Com_AlwaysActiveTxComIPdus */
typedef uint8_least Com_AlwaysActiveTxComIPdusIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtr */
typedef uint8_least Com_CbkRxTOutFuncPtrIterType;

/**   \brief  type used to iterate Com_CbkRxTOutFuncPtrInd */
typedef uint8_least Com_CbkRxTOutFuncPtrIndIterType;

/**   \brief  type used to iterate Com_CbkTxAckDefFuncPtr */
typedef uint8_least Com_CbkTxAckDefFuncPtrIterType;

/**   \brief  type used to iterate Com_CbkTxAckDefFuncPtrInd */
typedef uint8_least Com_CbkTxAckDefFuncPtrIndIterType;

/**   \brief  type used to iterate Com_ConstValueArrayBased */
typedef uint16_least Com_ConstValueArrayBasedIterType;

/**   \brief  type used to iterate Com_HandleRxPduDeferred */
typedef uint8_least Com_HandleRxPduDeferredIterType;

/**   \brief  type used to iterate Com_IPduGroupInfo */
typedef uint8_least Com_IPduGroupInfoIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfRxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8_least Com_IPduGroupInfoOfTxPduInfoIndIterType;

/**   \brief  type used to iterate Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8_least Com_IPduGroupInfoToSubIPduGroupsIndIterType;

/**   \brief  type used to iterate Com_RxAccessInfo */
typedef uint8_least Com_RxAccessInfoIterType;

/**   \brief  type used to iterate Com_RxAccessInfoInd */
typedef uint8_least Com_RxAccessInfoIndIterType;

/**   \brief  type used to iterate Com_RxCbkFuncPtr */
typedef uint8_least Com_RxCbkFuncPtrIterType;

/**   \brief  type used to iterate Com_RxDefPduBuffer */
typedef uint16_least Com_RxDefPduBufferIterType;

/**   \brief  type used to iterate Com_RxDeferredFctPtrCache */
typedef uint8_least Com_RxDeferredFctPtrCacheIterType;

/**   \brief  type used to iterate Com_RxPduCalloutFuncPtr */
typedef uint8_least Com_RxPduCalloutFuncPtrIterType;

/**   \brief  type used to iterate Com_RxPduInfo */
typedef uint8_least Com_RxPduInfoIterType;

/**   \brief  type used to iterate Com_RxPduInfoInd */
typedef uint8_least Com_RxPduInfoIndIterType;

/**   \brief  type used to iterate Com_RxSigBufferArrayBased */
typedef uint16_least Com_RxSigBufferArrayBasedIterType;

/**   \brief  type used to iterate Com_RxSigInfo */
typedef uint8_least Com_RxSigInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfo */
typedef uint8_least Com_RxTOutInfoIterType;

/**   \brief  type used to iterate Com_RxTOutInfoInd */
typedef uint8_least Com_RxTOutInfoIndIterType;

/**   \brief  type used to iterate Com_TmpRxBuffer */
typedef uint8_least Com_TmpRxBufferIterType;

/**   \brief  type used to iterate Com_TxBuffer */
typedef uint16_least Com_TxBufferIterType;

/**   \brief  type used to iterate Com_TxCyclicPdu */
typedef uint8_least Com_TxCyclicPduIterType;

/**   \brief  type used to iterate Com_TxModeFalse */
typedef uint8_least Com_TxModeFalseIterType;

/**   \brief  type used to iterate Com_TxModeInfo */
typedef uint8_least Com_TxModeInfoIterType;

/**   \brief  type used to iterate Com_TxModeTrue */
typedef uint8_least Com_TxModeTrueIterType;

/**   \brief  type used to iterate Com_TxPduCalloutFuncPtr */
typedef uint8_least Com_TxPduCalloutFuncPtrIterType;

/**   \brief  type used to iterate Com_TxPduInfo */
typedef uint8_least Com_TxPduInfoIterType;

/**   \brief  type used to iterate Com_TxPduInfoInd */
typedef uint8_least Com_TxPduInfoIndIterType;

/**   \brief  type used to iterate Com_TxPduInitValue */
typedef uint16_least Com_TxPduInitValueIterType;

/**   \brief  type used to iterate Com_TxPduTTCalloutFuncPtr */
typedef uint8_least Com_TxPduTTCalloutFuncPtrIterType;

/**   \brief  type used to iterate Com_TxSigInfo */
typedef uint8_least Com_TxSigInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCIterableTypesWithSizeRelations  Com Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Com_CurrentTxMode */
typedef Com_TxPduInfoIterType Com_CurrentTxModeIterType;

/**   \brief  type used to iterate Com_CycleTimeCnt */
typedef Com_TxPduInfoIterType Com_CycleTimeCntIterType;

/**   \brief  type used to iterate Com_CyclicSendRequest */
typedef Com_TxPduInfoIterType Com_CyclicSendRequestIterType;

/**   \brief  type used to iterate Com_DelayTimeCnt */
typedef Com_TxPduInfoIterType Com_DelayTimeCntIterType;

/**   \brief  type used to iterate Com_HandleTxPduDeferred */
typedef Com_TxPduInfoIterType Com_HandleTxPduDeferredIterType;

/**   \brief  type used to iterate Com_IPduGroupState */
typedef Com_IPduGroupInfoIterType Com_IPduGroupStateIterType;

/**   \brief  type used to iterate Com_RxPduDmState */
typedef Com_RxTOutInfoIterType Com_RxPduDmStateIterType;

/**   \brief  type used to iterate Com_RxPduGrpActive */
typedef Com_RxPduInfoIterType Com_RxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_RxTOutCnt */
typedef Com_RxTOutInfoIterType Com_RxTOutCntIterType;

/**   \brief  type used to iterate Com_TransmitRequest */
typedef Com_TxPduInfoIterType Com_TransmitRequestIterType;

/**   \brief  type used to iterate Com_TxPduGrpActive */
typedef Com_TxPduInfoIterType Com_TxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TxSduLength */
typedef Com_TxPduInfoIterType Com_TxSduLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCValueTypes  Com Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Com_TxPduInfoIdxOfAlwaysActiveTxComIPdus */
typedef uint8 Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrInd */
typedef uint8 Com_CbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_CbkTxAckDefFuncPtrInd */
typedef uint8 Com_CbkTxAckDefFuncPtrIndType;

/**   \brief  value based type definition for Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  value based type definition for Com_ConstValueArrayBased */
typedef uint8 Com_ConstValueArrayBasedType;

/**   \brief  value based type definition for Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  value based type definition for Com_CycleTimeCnt */
typedef uint16 Com_CycleTimeCntType;

/**   \brief  value based type definition for Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  value based type definition for Com_DelayTimeCnt */
typedef uint8 Com_DelayTimeCntType;

/**   \brief  value based type definition for Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  value based type definition for Com_HandleTxPduDeferred */
typedef boolean Com_HandleTxPduDeferredType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfo */
typedef boolean Com_IPduGroupInfoToSubIPduGroupsIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_RxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_RxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndEndIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndEndIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndStartIdxOfIPduGroupInfo */
typedef uint8 Com_TxPduInfoIndStartIdxOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIndUsedOfIPduGroupInfo */
typedef boolean Com_TxPduInfoIndUsedOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_IPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_IPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_IPduGroupState */
typedef uint8 Com_IPduGroupStateType;

/**   \brief  value based type definition for Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  value based type definition for Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  value based type definition for Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitLengthOfRxAccessInfo */
typedef uint16 Com_BitLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo */
typedef uint16 Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfo */
typedef uint8 Com_ConstValueArrayBasedInitValueLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo */
typedef uint16 Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ConstValueArrayBasedInitValueUsedOfRxAccessInfo */
typedef boolean Com_ConstValueArrayBasedInitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxPduInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo */
typedef uint16 Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfo */
typedef uint8 Com_RxSigBufferArrayBasedBufferLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo */
typedef uint16 Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfo */
typedef boolean Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxAccessInfo */
typedef boolean Com_RxTOutInfoUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfRxAccessInfo */
typedef uint8 Com_StartByteInPduPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoInd */
typedef uint8 Com_RxAccessInfoIndType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_RxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockThreshold */
typedef uint8 Com_RxDeadlineMonitoringISRLockThresholdType;

/**   \brief  value based type definition for Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  value based type definition for Com_RxDeferredFctPtrCache */
typedef uint32 Com_RxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockCounter */
typedef uint16 Com_RxDeferredProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockThreshold */
typedef uint8 Com_RxDeferredProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounter */
typedef uint16 Com_RxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockThreshold */
typedef uint8 Com_RxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_RxPduDmState */
typedef uint8 Com_RxPduDmStateType;

/**   \brief  value based type definition for Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo */
typedef boolean Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint16 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint16 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxPduCalloutFuncPtrIdxOfRxPduInfo */
typedef uint8 Com_RxPduCalloutFuncPtrIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxPduCalloutFuncPtrUsedOfRxPduInfo */
typedef boolean Com_RxPduCalloutFuncPtrUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint8 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndEndIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndStartIdxOfRxPduInfo */
typedef uint8 Com_RxTOutInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxPduInfo */
typedef boolean Com_RxTOutInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxPduInfo */
typedef uint8 Com_SignalProcessingOfRxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfRxPduInfo */
typedef uint8 Com_TypeOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxPduInfoInd */
typedef uint8 Com_RxPduInfoIndType;

/**   \brief  value based type definition for Com_RxSigBufferArrayBased */
typedef uint8 Com_RxSigBufferArrayBasedType;

/**   \brief  value based type definition for Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint8 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckIdxOfRxSigInfo */
typedef uint8 Com_RxCbkFuncPtrAckIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxCbkFuncPtrAckUsedOfRxSigInfo */
typedef boolean Com_RxCbkFuncPtrAckUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoIdxOfRxSigInfo */
typedef uint8 Com_RxTOutInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoUsedOfRxSigInfo */
typedef boolean Com_RxTOutInfoUsedOfRxSigInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  value based type definition for Com_RxTOutCnt */
typedef uint16 Com_RxTOutCntType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndEndIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfo */
typedef uint8 Com_CbkRxTOutFuncPtrIndStartIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfo */
typedef boolean Com_CbkRxTOutFuncPtrIndUsedOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FactorOfRxTOutInfo */
typedef uint16 Com_FactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_FirstFactorOfRxTOutInfo */
typedef uint8 Com_FirstFactorOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxTOutInfo */
typedef uint8 Com_RxPduInfoIdxOfRxTOutInfoType;

/**   \brief  value based type definition for Com_RxTOutInfoInd */
typedef uint8 Com_RxTOutInfoIndType;

/**   \brief  value based type definition for Com_SizeOfAlwaysActiveTxComIPdus */
typedef uint8 Com_SizeOfAlwaysActiveTxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtr */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfCbkRxTOutFuncPtrInd */
typedef uint8 Com_SizeOfCbkRxTOutFuncPtrIndType;

/**   \brief  value based type definition for Com_SizeOfCbkTxAckDefFuncPtr */
typedef uint8 Com_SizeOfCbkTxAckDefFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfCbkTxAckDefFuncPtrInd */
typedef uint8 Com_SizeOfCbkTxAckDefFuncPtrIndType;

/**   \brief  value based type definition for Com_SizeOfConstValueArrayBased */
typedef uint16 Com_SizeOfConstValueArrayBasedType;

/**   \brief  value based type definition for Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  value based type definition for Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  value based type definition for Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  value based type definition for Com_SizeOfDelayTimeCnt */
typedef uint8 Com_SizeOfDelayTimeCntType;

/**   \brief  value based type definition for Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfHandleTxPduDeferred */
typedef uint8 Com_SizeOfHandleTxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfo */
typedef uint8 Com_SizeOfIPduGroupInfoType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfRxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoOfTxPduInfoInd */
typedef uint8 Com_SizeOfIPduGroupInfoOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupInfoToSubIPduGroupsInd */
typedef uint8 Com_SizeOfIPduGroupInfoToSubIPduGroupsIndType;

/**   \brief  value based type definition for Com_SizeOfIPduGroupState */
typedef uint8 Com_SizeOfIPduGroupStateType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfo */
typedef uint8 Com_SizeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoInd */
typedef uint8 Com_SizeOfRxAccessInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxCbkFuncPtr */
typedef uint8 Com_SizeOfRxCbkFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfRxDefPduBuffer */
typedef uint16 Com_SizeOfRxDefPduBufferType;

/**   \brief  value based type definition for Com_SizeOfRxDeferredFctPtrCache */
typedef uint8 Com_SizeOfRxDeferredFctPtrCacheType;

/**   \brief  value based type definition for Com_SizeOfRxPduCalloutFuncPtr */
typedef uint8 Com_SizeOfRxPduCalloutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfRxPduDmState */
typedef uint8 Com_SizeOfRxPduDmStateType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfoInd */
typedef uint8 Com_SizeOfRxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferArrayBased */
typedef uint16 Com_SizeOfRxSigBufferArrayBasedType;

/**   \brief  value based type definition for Com_SizeOfRxSigInfo */
typedef uint8 Com_SizeOfRxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutCnt */
typedef uint8 Com_SizeOfRxTOutCntType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfo */
typedef uint8 Com_SizeOfRxTOutInfoType;

/**   \brief  value based type definition for Com_SizeOfRxTOutInfoInd */
typedef uint8 Com_SizeOfRxTOutInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTmpRxBuffer */
typedef uint8 Com_SizeOfTmpRxBufferType;

/**   \brief  value based type definition for Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  value based type definition for Com_SizeOfTxBuffer */
typedef uint16 Com_SizeOfTxBufferType;

/**   \brief  value based type definition for Com_SizeOfTxCyclicPdu */
typedef uint8 Com_SizeOfTxCyclicPduType;

/**   \brief  value based type definition for Com_SizeOfTxModeFalse */
typedef uint8 Com_SizeOfTxModeFalseType;

/**   \brief  value based type definition for Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  value based type definition for Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  value based type definition for Com_SizeOfTxPduCalloutFuncPtr */
typedef uint8 Com_SizeOfTxPduCalloutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfoInd */
typedef uint8 Com_SizeOfTxPduInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTxPduInitValue */
typedef uint16 Com_SizeOfTxPduInitValueType;

/**   \brief  value based type definition for Com_SizeOfTxPduTTCalloutFuncPtr */
typedef uint8 Com_SizeOfTxPduTTCalloutFuncPtrType;

/**   \brief  value based type definition for Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/**   \brief  value based type definition for Com_TmpRxBuffer */
typedef uint8 Com_TmpRxBufferType;

/**   \brief  value based type definition for Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  value based type definition for Com_TxBuffer */
typedef uint8 Com_TxBufferType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxCyclicPdu */
typedef uint8 Com_TxPduInfoIdxOfTxCyclicPduType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockCounter */
typedef uint16 Com_TxCyclicProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockThreshold */
typedef uint8 Com_TxCyclicProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounter */
typedef uint16 Com_TxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockThreshold */
typedef uint8 Com_TxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_DirectOfTxModeFalse */
typedef boolean Com_DirectOfTxModeFalseType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeFalse */
typedef boolean Com_PeriodicOfTxModeFalseType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeFalse */
typedef uint16 Com_TimePeriodOfTxModeFalseType;

/**   \brief  value based type definition for Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  value based type definition for Com_MinimumDelayOfTxModeInfo */
typedef uint8 Com_MinimumDelayOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeFalseIdxOfTxModeInfo */
typedef uint8 Com_TxModeFalseIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_DirectOfTxModeTrue */
typedef boolean Com_DirectOfTxModeTrueType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeTrue */
typedef uint16 Com_TimePeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  value based type definition for Com_CbkTxAckDefFuncPtrIndEndIdxOfTxPduInfo */
typedef uint8 Com_CbkTxAckDefFuncPtrIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_CbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo */
typedef uint8 Com_CbkTxAckDefFuncPtrIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_CbkTxAckDefFuncPtrIndUsedOfTxPduInfo */
typedef boolean Com_CbkTxAckDefFuncPtrIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo */
typedef boolean Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxPduInfo */
typedef uint16 Com_TxBufferEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxPduInfo */
typedef uint8 Com_TxBufferLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxPduInfo */
typedef uint16 Com_TxBufferStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxPduInfo */
typedef boolean Com_TxBufferUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduCalloutFuncPtrIdxOfTxPduInfo */
typedef uint8 Com_TxPduCalloutFuncPtrIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduCalloutFuncPtrUsedOfTxPduInfo */
typedef boolean Com_TxPduCalloutFuncPtrUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint16 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint16 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduTTCalloutFuncPtrIdxOfTxPduInfo */
typedef uint8 Com_TxPduTTCalloutFuncPtrIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduTTCalloutFuncPtrUsedOfTxPduInfo */
typedef boolean Com_TxPduTTCalloutFuncPtrUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInfoInd */
typedef uint8 Com_TxPduInfoIndType;

/**   \brief  value based type definition for Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounter */
typedef uint16 Com_TxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxProcessingISRLockThreshold */
typedef uint8 Com_TxProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  value based type definition for Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitLengthOfTxSigInfo */
typedef uint16 Com_BitLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitPositionOfTxSigInfo */
typedef uint8 Com_BitPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfTxSigInfo */
typedef uint8 Com_StartByteInPduPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_TriggeredOfTxSigInfo */
typedef boolean Com_TriggeredOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigInfo */
typedef uint16 Com_TxBufferEndIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigInfo */
typedef uint8 Com_TxBufferLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigInfo */
typedef uint16 Com_TxBufferStartIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigInfo */
typedef boolean Com_TxBufferUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCStructTypes  Com Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Com_AlwaysActiveTxComIPdus */
typedef struct sCom_AlwaysActiveTxComIPdusType
{
  uint8 Com_AlwaysActiveTxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_AlwaysActiveTxComIPdusType;

/**   \brief  type used in Com_IPduGroupInfo */
typedef struct sCom_IPduGroupInfoType
{
  Com_RxPduInfoIndEndIdxOfIPduGroupInfoType RxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_RxPduInfoIndStartIdxOfIPduGroupInfoType RxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_RxPduInfoInd */
  Com_TxPduInfoIndEndIdxOfIPduGroupInfoType TxPduInfoIndEndIdxOfIPduGroupInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInfoInd */
  Com_TxPduInfoIndStartIdxOfIPduGroupInfoType TxPduInfoIndStartIdxOfIPduGroupInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInfoInd */
} Com_IPduGroupInfoType;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_BitLengthOfRxAccessInfoType BitLengthOfRxAccessInfo;  /**< Bit length of the signal or group signal. */
  Com_ConstValueArrayBasedInitValueEndIdxOfRxAccessInfoType ConstValueArrayBasedInitValueEndIdxOfRxAccessInfo;  /**< the end index of the 0:n relation pointing to Com_ConstValueArrayBased */
  Com_ConstValueArrayBasedInitValueStartIdxOfRxAccessInfoType ConstValueArrayBasedInitValueStartIdxOfRxAccessInfo;  /**< the start index of the 0:n relation pointing to Com_ConstValueArrayBased */
  Com_RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfoType RxSigBufferArrayBasedBufferEndIdxOfRxAccessInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased */
  Com_RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfoType RxSigBufferArrayBasedBufferStartIdxOfRxAccessInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased */
  Com_RxSigBufferArrayBasedBufferUsedOfRxAccessInfoType RxSigBufferArrayBasedBufferUsedOfRxAccessInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased */
  Com_ApplTypeOfRxAccessInfoType ApplTypeOfRxAccessInfo;  /**< Application data type. */
  Com_BusAccOfRxAccessInfoType BusAccOfRxAccessInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_BytePositionOfRxAccessInfoType BytePositionOfRxAccessInfo;  /**< Little endian byte position of the signal or group signal within the I-PDU. */
  Com_RxPduInfoIdxOfRxAccessInfoType RxPduInfoIdxOfRxAccessInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
  Com_RxTOutInfoIdxOfRxAccessInfoType RxTOutInfoIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_RxDefPduBufferEndIdxOfRxPduInfoType RxDefPduBufferEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxDefPduBufferStartIdxOfRxPduInfoType RxDefPduBufferStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
  Com_RxTOutInfoUsedOfRxPduInfoType RxTOutInfoUsedOfRxPduInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo */
  Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
  Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd */
  Com_RxTOutInfoIdxOfRxPduInfoType RxTOutInfoIdxOfRxPduInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_RxTOutInfoIndEndIdxOfRxPduInfoType RxTOutInfoIndEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_RxTOutInfoIndStartIdxOfRxPduInfoType RxTOutInfoIndStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxTOutInfoInd */
  Com_SignalProcessingOfRxPduInfoType SignalProcessingOfRxPduInfo;  /**< Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion. */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_RxAccessInfoIdxOfRxSigInfoType RxAccessInfoIdxOfRxSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_RxCbkFuncPtrAckIdxOfRxSigInfoType RxCbkFuncPtrAckIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxCbkFuncPtr */
  Com_RxTOutInfoIdxOfRxSigInfoType RxTOutInfoIdxOfRxSigInfo;  /**< the index of the 0:1 relation pointing to Com_RxTOutInfo */
  Com_SignalProcessingOfRxSigInfoType SignalProcessingOfRxSigInfo;
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigInfoType;

/**   \brief  type used in Com_RxTOutInfo */
typedef struct sCom_RxTOutInfoType
{
  Com_FactorOfRxTOutInfoType FactorOfRxTOutInfo;  /**< Deadline monitoring timeout factor. */
  Com_FirstFactorOfRxTOutInfoType FirstFactorOfRxTOutInfo;  /**< Timeout factor for first deadline monitoring. */
  Com_RxPduInfoIdxOfRxTOutInfoType RxPduInfoIdxOfRxTOutInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
} Com_RxTOutInfoType;

/**   \brief  type used in Com_TxCyclicPdu */
typedef struct sCom_TxCyclicPduType
{
  Com_TxPduInfoIdxOfTxCyclicPduType TxPduInfoIdxOfTxCyclicPdu;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
} Com_TxCyclicPduType;

/**   \brief  type used in Com_TxModeFalse */
typedef struct sCom_TxModeFalseType
{
  Com_TimePeriodOfTxModeFalseType TimePeriodOfTxModeFalse;  /**< Cycle time factor. */
  Com_DirectOfTxModeFalseType DirectOfTxModeFalse;  /**< TRUE if transmission mode contains a direct part. */
} Com_TxModeFalseType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_InitModeOfTxModeInfoType InitModeOfTxModeInfo;  /**< Initial transmission mode selector of the Tx I-PDU. */
  Com_MinimumDelayOfTxModeInfoType MinimumDelayOfTxModeInfo;  /**< Minimum delay factor of the Tx I-PDU. */
  Com_TxModeTrueIdxOfTxModeInfoType TxModeTrueIdxOfTxModeInfo;  /**< the index of the 1:1 relation pointing to Com_TxModeTrue */
} Com_TxModeInfoType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_TimePeriodOfTxModeTrueType TimePeriodOfTxModeTrue;  /**< Cycle time factor. */
  Com_DirectOfTxModeTrueType DirectOfTxModeTrue;  /**< TRUE if transmission mode contains a direct part. */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueUsedOfTxPduInfoType TxPduInitValueUsedOfTxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
  Com_TxPduTTCalloutFuncPtrUsedOfTxPduInfoType TxPduTTCalloutFuncPtrUsedOfTxPduInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxPduTTCalloutFuncPtr */
  Com_CbkTxAckDefFuncPtrIndEndIdxOfTxPduInfoType CbkTxAckDefFuncPtrIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_CbkTxAckDefFuncPtrInd */
  Com_CbkTxAckDefFuncPtrIndStartIdxOfTxPduInfoType CbkTxAckDefFuncPtrIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_CbkTxAckDefFuncPtrInd */
  Com_ExternalIdOfTxPduInfoType ExternalIdOfTxPduInfo;  /**< External ID used to call PduR_ComTransmit(). */
  Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd */
  Com_MetaDataLengthOfTxPduInfoType MetaDataLengthOfTxPduInfo;  /**< Length of MetaData. */
  Com_TxBufferLengthOfTxPduInfoType TxBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxPduCalloutFuncPtrIdxOfTxPduInfoType TxPduCalloutFuncPtrIdxOfTxPduInfo;  /**< the index of the 0:1 relation pointing to Com_TxPduCalloutFuncPtr */
  Com_TxPduTTCalloutFuncPtrIdxOfTxPduInfoType TxPduTTCalloutFuncPtrIdxOfTxPduInfo;  /**< the index of the 0:1 relation pointing to Com_TxPduTTCalloutFuncPtr */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. */
  Com_TxBufferEndIdxOfTxSigInfoType TxBufferEndIdxOfTxSigInfo;  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigInfoType TxBufferStartIdxOfTxSigInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_ApplTypeOfTxSigInfoType ApplTypeOfTxSigInfo;  /**< Application data type. */
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BusAccOfTxSigInfoType BusAccOfTxSigInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfTxSigInfoType ByteLengthOfTxSigInfo;  /**< Byte length of the signal or group signal. */
  Com_StartByteInPduPositionOfTxSigInfoType StartByteInPduPositionOfTxSigInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TxPduInfoIdxOfTxSigInfoType TxPduInfoIdxOfTxSigInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
} Com_TxSigInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicStructTypes  Com Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct Com_HandleRxPduDeferredStructSTag
{
  Com_HandleRxPduDeferredType ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx;
  Com_HandleRxPduDeferredType ABM2_oB30_for_SC_CAN_V3_2_e97c616e_Rx;
  Com_HandleRxPduDeferredType ABS1_oB30_for_SC_CAN_V3_2_3c057b3e_Rx;
  Com_HandleRxPduDeferredType ABS2_oB30_for_SC_CAN_V3_2_057dd67e_Rx;
  Com_HandleRxPduDeferredType AC1_oB30_for_SC_CAN_V3_2_b80b56cf_Rx;
  Com_HandleRxPduDeferredType AC2_oB30_for_SC_CAN_V3_2_8173fb8f_Rx;
  Com_HandleRxPduDeferredType AC3_oB30_for_SC_CAN_V3_2_965b9f4f_Rx;
  Com_HandleRxPduDeferredType AC4_oB30_for_SC_CAN_V3_2_f382a10f_Rx;
  Com_HandleRxPduDeferredType AC6_oB30_for_SC_CAN_V3_2_ddd2688f_Rx;
  Com_HandleRxPduDeferredType AC7_oB30_for_SC_CAN_V3_2_cafa0c4f_Rx;
  Com_HandleRxPduDeferredType AC8_oB30_for_SC_CAN_V3_2_1660140f_Rx;
  Com_HandleRxPduDeferredType AC14_oB30_for_SC_CAN_V3_2_1c102f98_Rx;
  Com_HandleRxPduDeferredType ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx;
  Com_HandleRxPduDeferredType ACC_FD3_oB30_for_SC_CAN_V3_2_d3df4879_Rx;
  Com_HandleRxPduDeferredType ACC_FD4_oB30_for_SC_CAN_V3_2_b6067639_Rx;
  Com_HandleRxPduDeferredType AEB_FD1_oB30_for_SC_CAN_V3_2_a6cb7aa9_Rx;
  Com_HandleRxPduDeferredType AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx;
  Com_HandleRxPduDeferredType ALS1_oB30_for_SC_CAN_V3_2_5e3515d0_Rx;
  Com_HandleRxPduDeferredType AMP1_oB30_for_SC_CAN_V3_2_a9f549ca_Rx;
  Com_HandleRxPduDeferredType AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx;
  Com_HandleRxPduDeferredType AMP3_oB30_for_SC_CAN_V3_2_87a5804a_Rx;
  Com_HandleRxPduDeferredType AMP4_ANC1_oB30_for_SC_CAN_V3_2_0839201d_Rx;
  Com_HandleRxPduDeferredType BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx;
  Com_HandleRxPduDeferredType BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx;
  Com_HandleRxPduDeferredType BCM7_oB30_for_SC_CAN_V3_2_163d45da_Rx;
  Com_HandleRxPduDeferredType BCM8_oB30_for_SC_CAN_V3_2_caa75d9a_Rx;
  Com_HandleRxPduDeferredType BCM11_oB30_for_SC_CAN_V3_2_d72078da_Rx;
  Com_HandleRxPduDeferredType BCM12_oB30_for_SC_CAN_V3_2_ee58d59a_Rx;
  Com_HandleRxPduDeferredType BCM14_oB30_for_SC_CAN_V3_2_9ca98f1a_Rx;
  Com_HandleRxPduDeferredType BCM18_oB30_for_SC_CAN_V3_2_794b3a1a_Rx;
  Com_HandleRxPduDeferredType BCM19_oB30_for_SC_CAN_V3_2_6e635eda_Rx;
  Com_HandleRxPduDeferredType BLE1_oB30_for_SC_CAN_V3_2_876057b5_Rx;
  Com_HandleRxPduDeferredType BLE5_oB30_for_SC_CAN_V3_2_dbc1c4b5_Rx;
  Com_HandleRxPduDeferredType BMS4_oB30_for_SC_CAN_V3_2_a1743164_Rx;
  Com_HandleRxPduDeferredType BMS8_oB30_for_SC_CAN_V3_2_44968464_Rx;
  Com_HandleRxPduDeferredType BMS19_oB30_for_SC_CAN_V3_2_34e8b018_Rx;
  Com_HandleRxPduDeferredType BMS22_oB30_for_SC_CAN_V3_2_c2360265_Rx;
  Com_HandleRxPduDeferredType BMS30_oB30_for_SC_CAN_V3_2_77152131_Rx;
  Com_HandleRxPduDeferredType BMS35_oB30_for_SC_CAN_V3_2_3c9cd6f1_Rx;
  Com_HandleRxPduDeferredType BMS65_oB30_for_SC_CAN_V3_2_a7b39db6_Rx;
  Com_HandleRxPduDeferredType BMS66_oB30_for_SC_CAN_V3_2_9ecb30f6_Rx;
  Com_HandleRxPduDeferredType BMS_FD14_oB30_for_SC_CAN_V3_2_20801849_Rx;
  Com_HandleRxPduDeferredType CP1_oB30_for_SC_CAN_V3_2_16a725b1_Rx;
  Com_HandleRxPduDeferredType CR_FD1_oB30_for_SC_CAN_V3_2_da926426_Rx;
  Com_HandleRxPduDeferredType CSA1_oB30_for_SC_CAN_V3_2_bec912dc_Rx;
  Com_HandleRxPduDeferredType CSA2_oB30_for_SC_CAN_V3_2_87b1bf9c_Rx;
  Com_HandleRxPduDeferredType CSA3_oB30_for_SC_CAN_V3_2_9099db5c_Rx;
  Com_HandleRxPduDeferredType DCT3_oB30_for_SC_CAN_V3_2_bbff95c2_Rx;
  Com_HandleRxPduDeferredType DCT5_oB30_for_SC_CAN_V3_2_c90ecf42_Rx;
  Com_HandleRxPduDeferredType DCT_FD4_oB30_for_SC_CAN_V3_2_c3f55f0e_Rx;
  Com_HandleRxPduDeferredType DDCM1_oB30_for_SC_CAN_V3_2_4226467c_Rx;
  Com_HandleRxPduDeferredType DDCM3_oB30_for_SC_CAN_V3_2_6c768ffc_Rx;
  Com_HandleRxPduDeferredType DOCK1_oB30_for_SC_CAN_V3_2_b60a11e2_Rx;
  Com_HandleRxPduDeferredType DOCK2_oB30_for_SC_CAN_V3_2_8f72bca2_Rx;
  Com_HandleRxPduDeferredType DSC4_oB30_for_SC_CAN_V3_2_d686ca5d_Rx;
  Com_HandleRxPduDeferredType DSM1_oB30_for_SC_CAN_V3_2_707c0cc1_Rx;
  Com_HandleRxPduDeferredType DWD1_oB30_for_SC_CAN_V3_2_82b03b6c_Rx;
  Com_HandleRxPduDeferredType EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_683305cd_Rx;
  Com_HandleRxPduDeferredType ECM1_oB30_for_SC_CAN_V3_2_aa9ce3f2_Rx;
  Com_HandleRxPduDeferredType ECM2_oB30_for_SC_CAN_V3_2_93e44eb2_Rx;
  Com_HandleRxPduDeferredType ECM3_oB30_for_SC_CAN_V3_2_84cc2a72_Rx;
  Com_HandleRxPduDeferredType ECM4_oB30_for_SC_CAN_V3_2_e1151432_Rx;
  Com_HandleRxPduDeferredType ECM7_oB30_for_SC_CAN_V3_2_d86db972_Rx;
  Com_HandleRxPduDeferredType ECM9_oB30_for_SC_CAN_V3_2_13dfc5f2_Rx;
  Com_HandleRxPduDeferredType ECM11_oB30_for_SC_CAN_V3_2_0fe303fc_Rx;
  Com_HandleRxPduDeferredType ECM16_oB30_for_SC_CAN_V3_2_6a3a3dbc_Rx;
  Com_HandleRxPduDeferredType ECM19_oB30_for_SC_CAN_V3_2_b6a025fc_Rx;
  Com_HandleRxPduDeferredType ECM20_oB30_for_SC_CAN_V3_2_6e2e5e01_Rx;
  Com_HandleRxPduDeferredType ECM24_oB30_for_SC_CAN_V3_2_328fcd01_Rx;
  Com_HandleRxPduDeferredType ECM_PT5_oB30_for_SC_CAN_V3_2_032abda1_Rx;
  Com_HandleRxPduDeferredType ECM_PT6_oB30_for_SC_CAN_V3_2_3a5210e1_Rx;
  Com_HandleRxPduDeferredType ECM_PT7_oB30_for_SC_CAN_V3_2_2d7a7421_Rx;
  Com_HandleRxPduDeferredType EEM1_oB30_for_SC_CAN_V3_2_1aa1b1a2_Rx;
  Com_HandleRxPduDeferredType ELD1_oB30_for_SC_CAN_V3_2_d24341c9_Rx;
  Com_HandleRxPduDeferredType EPB1_oB30_for_SC_CAN_V3_2_fbe9ee6f_Rx;
  Com_HandleRxPduDeferredType EPS_FD1_oB30_for_SC_CAN_V3_2_bceaa863_Rx;
  Com_HandleRxPduDeferredType ESCL2_oB30_for_SC_CAN_V3_2_91777cb9_Rx;
  Com_HandleRxPduDeferredType ESP8_oB30_for_SC_CAN_V3_2_e1785022_Rx;
  Com_HandleRxPduDeferredType ESP11_oB30_for_SC_CAN_V3_2_12b19c69_Rx;
  Com_HandleRxPduDeferredType ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx;
  Com_HandleRxPduDeferredType ETC2_oB30_for_SC_CAN_V3_2_30e437a4_Rx;
  Com_HandleRxPduDeferredType ETC3_oB30_for_SC_CAN_V3_2_27cc5364_Rx;
  Com_HandleRxPduDeferredType ETC4_oB30_for_SC_CAN_V3_2_42156d24_Rx;
  Com_HandleRxPduDeferredType F_PBOX1_oB30_for_SC_CAN_V3_2_24a181fc_Rx;
  Com_HandleRxPduDeferredType GLO_NASS1_oB30_for_SC_CAN_V3_2_96a1bccc_Rx;
  Com_HandleRxPduDeferredType GW_FD1_oB30_for_SC_CAN_V3_2_765a3f2a_Rx;
  Com_HandleRxPduDeferredType GW_OTA_oB30_for_SC_CAN_V3_2_cf261bba_Rx;
  Com_HandleRxPduDeferredType GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx;
  Com_HandleRxPduDeferredType HAP_FD1_oB30_for_SC_CAN_V3_2_7488140e_Rx;
  Com_HandleRxPduDeferredType HAP_FD2_oB30_for_SC_CAN_V3_2_4df0b94e_Rx;
  Com_HandleRxPduDeferredType HAP_FD3_oB30_for_SC_CAN_V3_2_5ad8dd8e_Rx;
  Com_HandleRxPduDeferredType HAP_FD6_oB30_for_SC_CAN_V3_2_11512a4e_Rx;
  Com_HandleRxPduDeferredType HAP_FD7_oB30_for_SC_CAN_V3_2_06794e8e_Rx;
  Com_HandleRxPduDeferredType HCM_L1_oB30_for_SC_CAN_V3_2_02400631_Rx;
  Com_HandleRxPduDeferredType HCM_L2_oB30_for_SC_CAN_V3_2_3b38ab71_Rx;
  Com_HandleRxPduDeferredType HCM_R1_oB30_for_SC_CAN_V3_2_ee41b121_Rx;
  Com_HandleRxPduDeferredType HCM_R2_oB30_for_SC_CAN_V3_2_d7391c61_Rx;
  Com_HandleRxPduDeferredType HCU_FD1_oB30_for_SC_CAN_V3_2_641912c5_Rx;
  Com_HandleRxPduDeferredType HCU_HC3_oB30_for_SC_CAN_V3_2_5ec02d05_Rx;
  Com_HandleRxPduDeferredType HCU_HC6_oB30_for_SC_CAN_V3_2_1549dac5_Rx;
  Com_HandleRxPduDeferredType HCU_HC7_oB30_for_SC_CAN_V3_2_0261be05_Rx;
  Com_HandleRxPduDeferredType HCU_HC8_oB30_for_SC_CAN_V3_2_defba645_Rx;
  Com_HandleRxPduDeferredType HCU_HC16_oB30_for_SC_CAN_V3_2_a481d524_Rx;
  Com_HandleRxPduDeferredType HCU_HP5_oB30_for_SC_CAN_V3_2_5ba6c8f4_Rx;
  Com_HandleRxPduDeferredType HCU_HP6_oB30_for_SC_CAN_V3_2_62de65b4_Rx;
  Com_HandleRxPduDeferredType HCU_HP8_oB30_for_SC_CAN_V3_2_a96c1934_Rx;
  Com_HandleRxPduDeferredType HCU_PT4_oB30_for_SC_CAN_V3_2_e1b44e24_Rx;
  Com_HandleRxPduDeferredType HCU_PT5_oB30_for_SC_CAN_V3_2_f69c2ae4_Rx;
  Com_HandleRxPduDeferredType HCU_PT7_oB30_for_SC_CAN_V3_2_d8cce364_Rx;
  Com_HandleRxPduDeferredType HCU_PT8_oB30_for_SC_CAN_V3_2_0456fb24_Rx;
  Com_HandleRxPduDeferredType HUD1_oB30_for_SC_CAN_V3_2_8c3d2e2f_Rx;
  Com_HandleRxPduDeferredType IFC1_oB30_for_SC_CAN_V3_2_787af09a_Rx;
  Com_HandleRxPduDeferredType IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx;
  Com_HandleRxPduDeferredType IFC_FD3_oB30_for_SC_CAN_V3_2_d1bdd095_Rx;
  Com_HandleRxPduDeferredType IFC_FD5_oB30_for_SC_CAN_V3_2_a34c8a15_Rx;
  Com_HandleRxPduDeferredType IFC_FD6_oB30_for_SC_CAN_V3_2_9a342755_Rx;
  Com_HandleRxPduDeferredType Ibooster_FD2_oB30_for_SC_CAN_V3_2_e9e18adf_Rx;
  Com_HandleRxPduDeferredType OBC1_oB30_for_SC_CAN_V3_2_7aa70263_Rx;
  Com_HandleRxPduDeferredType OBC2_oB30_for_SC_CAN_V3_2_43dfaf23_Rx;
  Com_HandleRxPduDeferredType P2M1_oB30_for_SC_CAN_V3_2_8af900bc_Rx;
  Com_HandleRxPduDeferredType P2M3_oB30_for_SC_CAN_V3_2_a4a9c93c_Rx;
  Com_HandleRxPduDeferredType PDCM1_oB30_for_SC_CAN_V3_2_c2e08bda_Rx;
  Com_HandleRxPduDeferredType PEPS2_oB30_for_SC_CAN_V3_2_9567d791_Rx;
  Com_HandleRxPduDeferredType PEPS4_oB30_for_SC_CAN_V3_2_e7968d11_Rx;
  Com_HandleRxPduDeferredType RFCM_L1_oB30_for_SC_CAN_V3_2_0f4843bb_Rx;
  Com_HandleRxPduDeferredType RFCM_R1_oB30_for_SC_CAN_V3_2_e349f4ab_Rx;
  Com_HandleRxPduDeferredType RSDS_FD1_oB30_for_SC_CAN_V3_2_984f3330_Rx;
  Com_HandleRxPduDeferredType RSDS_FD2_oB30_for_SC_CAN_V3_2_a1379e70_Rx;
  Com_HandleRxPduDeferredType R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx;
  Com_HandleRxPduDeferredType SCM1_oB30_for_SC_CAN_V3_2_9950a83a_Rx;
  Com_HandleRxPduDeferredType TOD1_oB30_for_SC_CAN_V3_2_77c15f81_Rx;
  Com_HandleRxPduDeferredType TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx;
  Com_HandleRxPduDeferredType TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx;
  Com_HandleRxPduDeferredType T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx;
  Com_HandleRxPduDeferredType T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx;
  Com_HandleRxPduDeferredType T_BOX_FD4_oB30_for_SC_CAN_V3_2_f4d43aba_Rx;
  Com_HandleRxPduDeferredType T_BOX_FD9_oB30_for_SC_CAN_V3_2_061eeb7a_Rx;
  Com_HandleRxPduDeferredType T_BOX_FD10_oB30_for_SC_CAN_V3_2_fbbdad00_Rx;
  Com_HandleRxPduDeferredType Trailer1_oB30_for_SC_CAN_V3_2_7da566bd_Rx;
  Com_HandleRxPduDeferredType VMDR1_oB30_for_SC_CAN_V3_2_32d43f61_Rx;
  Com_HandleRxPduDeferredType WPC1_oB30_for_SC_CAN_V3_2_a8eb0588_Rx;
} Com_HandleRxPduDeferredStructSType;  /* PRQA S 0639 */  /* MD_MSR_Dir1.1 */

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct Com_RxDefPduBufferStructSTag
{
  Com_RxDefPduBufferType ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx[8];
  Com_RxDefPduBufferType ABM2_oB30_for_SC_CAN_V3_2_e97c616e_Rx[8];
  Com_RxDefPduBufferType ABS1_oB30_for_SC_CAN_V3_2_3c057b3e_Rx[8];
  Com_RxDefPduBufferType ABS2_oB30_for_SC_CAN_V3_2_057dd67e_Rx[8];
  Com_RxDefPduBufferType AC1_oB30_for_SC_CAN_V3_2_b80b56cf_Rx[8];
  Com_RxDefPduBufferType AC2_oB30_for_SC_CAN_V3_2_8173fb8f_Rx[8];
  Com_RxDefPduBufferType AC3_oB30_for_SC_CAN_V3_2_965b9f4f_Rx[8];
  Com_RxDefPduBufferType AC4_oB30_for_SC_CAN_V3_2_f382a10f_Rx[8];
  Com_RxDefPduBufferType AC6_oB30_for_SC_CAN_V3_2_ddd2688f_Rx[8];
  Com_RxDefPduBufferType AC7_oB30_for_SC_CAN_V3_2_cafa0c4f_Rx[8];
  Com_RxDefPduBufferType AC8_oB30_for_SC_CAN_V3_2_1660140f_Rx[8];
  Com_RxDefPduBufferType AC14_oB30_for_SC_CAN_V3_2_1c102f98_Rx[8];
  Com_RxDefPduBufferType ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx[56];
  Com_RxDefPduBufferType ACC_FD3_oB30_for_SC_CAN_V3_2_d3df4879_Rx[64];
  Com_RxDefPduBufferType ACC_FD4_oB30_for_SC_CAN_V3_2_b6067639_Rx[64];
  Com_RxDefPduBufferType AEB_FD1_oB30_for_SC_CAN_V3_2_a6cb7aa9_Rx[64];
  Com_RxDefPduBufferType AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx[56];
  Com_RxDefPduBufferType ALS1_oB30_for_SC_CAN_V3_2_5e3515d0_Rx[16];
  Com_RxDefPduBufferType AMP1_oB30_for_SC_CAN_V3_2_a9f549ca_Rx[8];
  Com_RxDefPduBufferType AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx[8];
  Com_RxDefPduBufferType AMP3_oB30_for_SC_CAN_V3_2_87a5804a_Rx[8];
  Com_RxDefPduBufferType AMP4_ANC1_oB30_for_SC_CAN_V3_2_0839201d_Rx[8];
  Com_RxDefPduBufferType BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx[8];
  Com_RxDefPduBufferType BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx[8];
  Com_RxDefPduBufferType BCM7_oB30_for_SC_CAN_V3_2_163d45da_Rx[8];
  Com_RxDefPduBufferType BCM8_oB30_for_SC_CAN_V3_2_caa75d9a_Rx[8];
  Com_RxDefPduBufferType BCM11_oB30_for_SC_CAN_V3_2_d72078da_Rx[8];
  Com_RxDefPduBufferType BCM12_oB30_for_SC_CAN_V3_2_ee58d59a_Rx[8];
  Com_RxDefPduBufferType BCM14_oB30_for_SC_CAN_V3_2_9ca98f1a_Rx[8];
  Com_RxDefPduBufferType BCM18_oB30_for_SC_CAN_V3_2_794b3a1a_Rx[8];
  Com_RxDefPduBufferType BCM19_oB30_for_SC_CAN_V3_2_6e635eda_Rx[8];
  Com_RxDefPduBufferType BLE1_oB30_for_SC_CAN_V3_2_876057b5_Rx[8];
  Com_RxDefPduBufferType BLE5_oB30_for_SC_CAN_V3_2_dbc1c4b5_Rx[8];
  Com_RxDefPduBufferType BMS4_oB30_for_SC_CAN_V3_2_a1743164_Rx[8];
  Com_RxDefPduBufferType BMS8_oB30_for_SC_CAN_V3_2_44968464_Rx[8];
  Com_RxDefPduBufferType BMS19_oB30_for_SC_CAN_V3_2_34e8b018_Rx[8];
  Com_RxDefPduBufferType BMS22_oB30_for_SC_CAN_V3_2_c2360265_Rx[8];
  Com_RxDefPduBufferType BMS30_oB30_for_SC_CAN_V3_2_77152131_Rx[8];
  Com_RxDefPduBufferType BMS35_oB30_for_SC_CAN_V3_2_3c9cd6f1_Rx[8];
  Com_RxDefPduBufferType BMS65_oB30_for_SC_CAN_V3_2_a7b39db6_Rx[8];
  Com_RxDefPduBufferType BMS66_oB30_for_SC_CAN_V3_2_9ecb30f6_Rx[8];
  Com_RxDefPduBufferType BMS_FD14_oB30_for_SC_CAN_V3_2_20801849_Rx[8];
  Com_RxDefPduBufferType CP1_oB30_for_SC_CAN_V3_2_16a725b1_Rx[8];
  Com_RxDefPduBufferType CR_FD1_oB30_for_SC_CAN_V3_2_da926426_Rx[64];
  Com_RxDefPduBufferType CSA1_oB30_for_SC_CAN_V3_2_bec912dc_Rx[8];
  Com_RxDefPduBufferType CSA2_oB30_for_SC_CAN_V3_2_87b1bf9c_Rx[8];
  Com_RxDefPduBufferType CSA3_oB30_for_SC_CAN_V3_2_9099db5c_Rx[8];
  Com_RxDefPduBufferType DCT3_oB30_for_SC_CAN_V3_2_bbff95c2_Rx[8];
  Com_RxDefPduBufferType DCT5_oB30_for_SC_CAN_V3_2_c90ecf42_Rx[8];
  Com_RxDefPduBufferType DCT_FD4_oB30_for_SC_CAN_V3_2_c3f55f0e_Rx[64];
  Com_RxDefPduBufferType DDCM1_oB30_for_SC_CAN_V3_2_4226467c_Rx[8];
  Com_RxDefPduBufferType DDCM3_oB30_for_SC_CAN_V3_2_6c768ffc_Rx[8];
  Com_RxDefPduBufferType DOCK1_oB30_for_SC_CAN_V3_2_b60a11e2_Rx[64];
  Com_RxDefPduBufferType DOCK2_oB30_for_SC_CAN_V3_2_8f72bca2_Rx[64];
  Com_RxDefPduBufferType DSC4_oB30_for_SC_CAN_V3_2_d686ca5d_Rx[8];
  Com_RxDefPduBufferType DSM1_oB30_for_SC_CAN_V3_2_707c0cc1_Rx[8];
  Com_RxDefPduBufferType DWD1_oB30_for_SC_CAN_V3_2_82b03b6c_Rx[8];
  Com_RxDefPduBufferType EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_683305cd_Rx[64];
  Com_RxDefPduBufferType ECM1_oB30_for_SC_CAN_V3_2_aa9ce3f2_Rx[8];
  Com_RxDefPduBufferType ECM2_oB30_for_SC_CAN_V3_2_93e44eb2_Rx[8];
  Com_RxDefPduBufferType ECM3_oB30_for_SC_CAN_V3_2_84cc2a72_Rx[8];
  Com_RxDefPduBufferType ECM4_oB30_for_SC_CAN_V3_2_e1151432_Rx[8];
  Com_RxDefPduBufferType ECM7_oB30_for_SC_CAN_V3_2_d86db972_Rx[8];
  Com_RxDefPduBufferType ECM9_oB30_for_SC_CAN_V3_2_13dfc5f2_Rx[8];
  Com_RxDefPduBufferType ECM11_oB30_for_SC_CAN_V3_2_0fe303fc_Rx[8];
  Com_RxDefPduBufferType ECM16_oB30_for_SC_CAN_V3_2_6a3a3dbc_Rx[8];
  Com_RxDefPduBufferType ECM19_oB30_for_SC_CAN_V3_2_b6a025fc_Rx[8];
  Com_RxDefPduBufferType ECM20_oB30_for_SC_CAN_V3_2_6e2e5e01_Rx[8];
  Com_RxDefPduBufferType ECM24_oB30_for_SC_CAN_V3_2_328fcd01_Rx[8];
  Com_RxDefPduBufferType ECM_PT5_oB30_for_SC_CAN_V3_2_032abda1_Rx[8];
  Com_RxDefPduBufferType ECM_PT6_oB30_for_SC_CAN_V3_2_3a5210e1_Rx[8];
  Com_RxDefPduBufferType ECM_PT7_oB30_for_SC_CAN_V3_2_2d7a7421_Rx[8];
  Com_RxDefPduBufferType EEM1_oB30_for_SC_CAN_V3_2_1aa1b1a2_Rx[8];
  Com_RxDefPduBufferType ELD1_oB30_for_SC_CAN_V3_2_d24341c9_Rx[8];
  Com_RxDefPduBufferType EPB1_oB30_for_SC_CAN_V3_2_fbe9ee6f_Rx[8];
  Com_RxDefPduBufferType EPS_FD1_oB30_for_SC_CAN_V3_2_bceaa863_Rx[64];
  Com_RxDefPduBufferType ESCL2_oB30_for_SC_CAN_V3_2_91777cb9_Rx[8];
  Com_RxDefPduBufferType ESP8_oB30_for_SC_CAN_V3_2_e1785022_Rx[8];
  Com_RxDefPduBufferType ESP11_oB30_for_SC_CAN_V3_2_12b19c69_Rx[8];
  Com_RxDefPduBufferType ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx[56];
  Com_RxDefPduBufferType ETC2_oB30_for_SC_CAN_V3_2_30e437a4_Rx[8];
  Com_RxDefPduBufferType ETC3_oB30_for_SC_CAN_V3_2_27cc5364_Rx[8];
  Com_RxDefPduBufferType ETC4_oB30_for_SC_CAN_V3_2_42156d24_Rx[8];
  Com_RxDefPduBufferType F_PBOX1_oB30_for_SC_CAN_V3_2_24a181fc_Rx[8];
  Com_RxDefPduBufferType GLO_NASS1_oB30_for_SC_CAN_V3_2_96a1bccc_Rx[8];
  Com_RxDefPduBufferType GW_FD1_oB30_for_SC_CAN_V3_2_765a3f2a_Rx[64];
  Com_RxDefPduBufferType GW_OTA_oB30_for_SC_CAN_V3_2_cf261bba_Rx[8];
  Com_RxDefPduBufferType HAP_FD1_oB30_for_SC_CAN_V3_2_7488140e_Rx[64];
  Com_RxDefPduBufferType HAP_FD2_oB30_for_SC_CAN_V3_2_4df0b94e_Rx[64];
  Com_RxDefPduBufferType HAP_FD3_oB30_for_SC_CAN_V3_2_5ad8dd8e_Rx[64];
  Com_RxDefPduBufferType HAP_FD6_oB30_for_SC_CAN_V3_2_11512a4e_Rx[64];
  Com_RxDefPduBufferType HAP_FD7_oB30_for_SC_CAN_V3_2_06794e8e_Rx[64];
  Com_RxDefPduBufferType HCM_L1_oB30_for_SC_CAN_V3_2_02400631_Rx[8];
  Com_RxDefPduBufferType HCM_L2_oB30_for_SC_CAN_V3_2_3b38ab71_Rx[8];
  Com_RxDefPduBufferType HCM_R1_oB30_for_SC_CAN_V3_2_ee41b121_Rx[8];
  Com_RxDefPduBufferType HCM_R2_oB30_for_SC_CAN_V3_2_d7391c61_Rx[8];
  Com_RxDefPduBufferType HCU_FD1_oB30_for_SC_CAN_V3_2_641912c5_Rx[64];
  Com_RxDefPduBufferType HCU_HC3_oB30_for_SC_CAN_V3_2_5ec02d05_Rx[8];
  Com_RxDefPduBufferType HCU_HC6_oB30_for_SC_CAN_V3_2_1549dac5_Rx[8];
  Com_RxDefPduBufferType HCU_HC7_oB30_for_SC_CAN_V3_2_0261be05_Rx[8];
  Com_RxDefPduBufferType HCU_HC8_oB30_for_SC_CAN_V3_2_defba645_Rx[8];
  Com_RxDefPduBufferType HCU_HC16_oB30_for_SC_CAN_V3_2_a481d524_Rx[8];
  Com_RxDefPduBufferType HCU_HP5_oB30_for_SC_CAN_V3_2_5ba6c8f4_Rx[8];
  Com_RxDefPduBufferType HCU_HP6_oB30_for_SC_CAN_V3_2_62de65b4_Rx[8];
  Com_RxDefPduBufferType HCU_HP8_oB30_for_SC_CAN_V3_2_a96c1934_Rx[8];
  Com_RxDefPduBufferType HCU_PT4_oB30_for_SC_CAN_V3_2_e1b44e24_Rx[8];
  Com_RxDefPduBufferType HCU_PT5_oB30_for_SC_CAN_V3_2_f69c2ae4_Rx[8];
  Com_RxDefPduBufferType HCU_PT7_oB30_for_SC_CAN_V3_2_d8cce364_Rx[8];
  Com_RxDefPduBufferType HCU_PT8_oB30_for_SC_CAN_V3_2_0456fb24_Rx[8];
  Com_RxDefPduBufferType HUD1_oB30_for_SC_CAN_V3_2_8c3d2e2f_Rx[8];
  Com_RxDefPduBufferType IFC1_oB30_for_SC_CAN_V3_2_787af09a_Rx[8];
  Com_RxDefPduBufferType IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx[56];
  Com_RxDefPduBufferType IFC_FD3_oB30_for_SC_CAN_V3_2_d1bdd095_Rx[64];
  Com_RxDefPduBufferType IFC_FD5_oB30_for_SC_CAN_V3_2_a34c8a15_Rx[64];
  Com_RxDefPduBufferType IFC_FD6_oB30_for_SC_CAN_V3_2_9a342755_Rx[64];
  Com_RxDefPduBufferType Ibooster_FD2_oB30_for_SC_CAN_V3_2_e9e18adf_Rx[64];
  Com_RxDefPduBufferType OBC1_oB30_for_SC_CAN_V3_2_7aa70263_Rx[8];
  Com_RxDefPduBufferType OBC2_oB30_for_SC_CAN_V3_2_43dfaf23_Rx[8];
  Com_RxDefPduBufferType P2M1_oB30_for_SC_CAN_V3_2_8af900bc_Rx[8];
  Com_RxDefPduBufferType P2M3_oB30_for_SC_CAN_V3_2_a4a9c93c_Rx[8];
  Com_RxDefPduBufferType PDCM1_oB30_for_SC_CAN_V3_2_c2e08bda_Rx[8];
  Com_RxDefPduBufferType PEPS2_oB30_for_SC_CAN_V3_2_9567d791_Rx[8];
  Com_RxDefPduBufferType PEPS4_oB30_for_SC_CAN_V3_2_e7968d11_Rx[8];
  Com_RxDefPduBufferType RFCM_L1_oB30_for_SC_CAN_V3_2_0f4843bb_Rx[8];
  Com_RxDefPduBufferType RFCM_R1_oB30_for_SC_CAN_V3_2_e349f4ab_Rx[8];
  Com_RxDefPduBufferType RSDS_FD1_oB30_for_SC_CAN_V3_2_984f3330_Rx[64];
  Com_RxDefPduBufferType RSDS_FD2_oB30_for_SC_CAN_V3_2_a1379e70_Rx[64];
  Com_RxDefPduBufferType R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx[8];
  Com_RxDefPduBufferType SCM1_oB30_for_SC_CAN_V3_2_9950a83a_Rx[8];
  Com_RxDefPduBufferType TOD1_oB30_for_SC_CAN_V3_2_77c15f81_Rx[8];
  Com_RxDefPduBufferType TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx[8];
  Com_RxDefPduBufferType TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx[8];
  Com_RxDefPduBufferType T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx[8];
  Com_RxDefPduBufferType T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx[8];
  Com_RxDefPduBufferType T_BOX_FD4_oB30_for_SC_CAN_V3_2_f4d43aba_Rx[16];
  Com_RxDefPduBufferType T_BOX_FD9_oB30_for_SC_CAN_V3_2_061eeb7a_Rx[8];
  Com_RxDefPduBufferType T_BOX_FD10_oB30_for_SC_CAN_V3_2_fbbdad00_Rx[64];
  Com_RxDefPduBufferType Trailer1_oB30_for_SC_CAN_V3_2_7da566bd_Rx[8];
  Com_RxDefPduBufferType VMDR1_oB30_for_SC_CAN_V3_2_32d43f61_Rx[8];
  Com_RxDefPduBufferType WPC1_oB30_for_SC_CAN_V3_2_a8eb0588_Rx[8];
} Com_RxDefPduBufferStructSType;  /* PRQA S 0639 */  /* MD_MSR_Dir1.1 */

/** 
  \}
*/ 

/** 
  \defgroup  ComPCUnionIndexAndSymbolTypes  Com Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Com_HandleRxPduDeferred in an index and symbol based style. */
typedef union Com_HandleRxPduDeferredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_HandleRxPduDeferredType raw[141];
  Com_HandleRxPduDeferredStructSType str;
} Com_HandleRxPduDeferredUType;

/**   \brief  type to access Com_RxDefPduBuffer in an index and symbol based style. */
typedef union Com_RxDefPduBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxDefPduBufferType raw[2616];
  Com_RxDefPduBufferStructSType str;
} Com_RxDefPduBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootPointerTypes  Com Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Com_AlwaysActiveTxComIPdus */
typedef P2CONST(Com_AlwaysActiveTxComIPdusType, TYPEDEF, COM_CONST) Com_AlwaysActiveTxComIPdusPtrType;

/**   \brief  type used to point to Com_CbkRxTOutFuncPtr */
typedef P2CONST(ComCbkRxTOutType, TYPEDEF, COM_CONST) Com_CbkRxTOutFuncPtrPtrType;

/**   \brief  type used to point to Com_CbkRxTOutFuncPtrInd */
typedef P2CONST(Com_CbkRxTOutFuncPtrIndType, TYPEDEF, COM_CONST) Com_CbkRxTOutFuncPtrIndPtrType;

/**   \brief  type used to point to Com_CbkTxAckDefFuncPtr */
typedef P2CONST(ComCbkTxAckDefType, TYPEDEF, COM_CONST) Com_CbkTxAckDefFuncPtrPtrType;

/**   \brief  type used to point to Com_CbkTxAckDefFuncPtrInd */
typedef P2CONST(Com_CbkTxAckDefFuncPtrIndType, TYPEDEF, COM_CONST) Com_CbkTxAckDefFuncPtrIndPtrType;

/**   \brief  type used to point to Com_ConstValueArrayBased */
typedef P2CONST(Com_ConstValueArrayBasedType, TYPEDEF, COM_CONST) Com_ConstValueArrayBasedPtrType;

/**   \brief  type used to point to Com_CurrentTxMode */
typedef P2VAR(Com_CurrentTxModeType, TYPEDEF, COM_VAR_NOINIT) Com_CurrentTxModePtrType;

/**   \brief  type used to point to Com_CycleTimeCnt */
typedef P2VAR(Com_CycleTimeCntType, TYPEDEF, COM_VAR_NOINIT) Com_CycleTimeCntPtrType;

/**   \brief  type used to point to Com_CyclicSendRequest */
typedef P2VAR(Com_CyclicSendRequestType, TYPEDEF, COM_VAR_NOINIT) Com_CyclicSendRequestPtrType;

/**   \brief  type used to point to Com_DelayTimeCnt */
typedef P2VAR(Com_DelayTimeCntType, TYPEDEF, COM_VAR_NOINIT) Com_DelayTimeCntPtrType;

/**   \brief  type used to point to Com_HandleRxPduDeferred */
typedef P2VAR(Com_HandleRxPduDeferredType, TYPEDEF, COM_VAR_NOINIT) Com_HandleRxPduDeferredPtrType;

/**   \brief  type used to point to Com_HandleTxPduDeferred */
typedef P2VAR(Com_HandleTxPduDeferredType, TYPEDEF, COM_VAR_NOINIT) Com_HandleTxPduDeferredPtrType;

/**   \brief  type used to point to Com_IPduGroupInfo */
typedef P2CONST(Com_IPduGroupInfoType, TYPEDEF, COM_CONST) Com_IPduGroupInfoPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfRxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfRxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfRxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoOfTxPduInfoInd */
typedef P2CONST(Com_IPduGroupInfoOfTxPduInfoIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoOfTxPduInfoIndPtrType;

/**   \brief  type used to point to Com_IPduGroupInfoToSubIPduGroupsInd */
typedef P2CONST(Com_IPduGroupInfoToSubIPduGroupsIndType, TYPEDEF, COM_CONST) Com_IPduGroupInfoToSubIPduGroupsIndPtrType;

/**   \brief  type used to point to Com_IPduGroupState */
typedef P2VAR(Com_IPduGroupStateType, TYPEDEF, COM_VAR_NOINIT) Com_IPduGroupStatePtrType;

/**   \brief  type used to point to Com_Initialized */
typedef P2VAR(Com_InitializedType, TYPEDEF, COM_VAR_ZERO_INIT) Com_InitializedPtrType;

/**   \brief  type used to point to Com_RxAccessInfo */
typedef P2CONST(Com_RxAccessInfoType, TYPEDEF, COM_CONST) Com_RxAccessInfoPtrType;

/**   \brief  type used to point to Com_RxAccessInfoInd */
typedef P2CONST(Com_RxAccessInfoIndType, TYPEDEF, COM_CONST) Com_RxAccessInfoIndPtrType;

/**   \brief  type used to point to Com_RxCbkFuncPtr */
typedef P2CONST(ComRxCbkType, TYPEDEF, COM_CONST) Com_RxCbkFuncPtrPtrType;

/**   \brief  type used to point to Com_RxDeadlineMonitoringISRLockCounter */
typedef P2VAR(Com_RxDeadlineMonitoringISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxDefPduBuffer */
typedef P2VAR(Com_RxDefPduBufferType, TYPEDEF, COM_VAR_NOINIT) Com_RxDefPduBufferPtrType;

/**   \brief  type used to point to Com_RxDeferredFctPtrCache */
typedef P2VAR(Com_RxDeferredFctPtrCacheType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeferredFctPtrCachePtrType;

/**   \brief  type used to point to Com_RxDeferredProcessingISRLockCounter */
typedef P2VAR(Com_RxDeferredProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxIPduGroupISRLockCounter */
typedef P2VAR(Com_RxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxPduCalloutFuncPtr */
typedef P2CONST(ComRxPduCalloutType, TYPEDEF, COM_CONST) Com_RxPduCalloutFuncPtrPtrType;

/**   \brief  type used to point to Com_RxPduDmState */
typedef P2VAR(Com_RxPduDmStateType, TYPEDEF, COM_VAR_NOINIT) Com_RxPduDmStatePtrType;

/**   \brief  type used to point to Com_RxPduGrpActive */
typedef P2VAR(Com_RxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_RxPduGrpActivePtrType;

/**   \brief  type used to point to Com_RxPduInfo */
typedef P2CONST(Com_RxPduInfoType, TYPEDEF, COM_CONST) Com_RxPduInfoPtrType;

/**   \brief  type used to point to Com_RxPduInfoInd */
typedef P2CONST(Com_RxPduInfoIndType, TYPEDEF, COM_CONST) Com_RxPduInfoIndPtrType;

/**   \brief  type used to point to Com_RxSigBufferArrayBased */
typedef P2VAR(Com_RxSigBufferArrayBasedType, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferArrayBasedPtrType;

/**   \brief  type used to point to Com_RxSigInfo */
typedef P2CONST(Com_RxSigInfoType, TYPEDEF, COM_CONST) Com_RxSigInfoPtrType;

/**   \brief  type used to point to Com_RxTOutCnt */
typedef P2VAR(Com_RxTOutCntType, TYPEDEF, COM_VAR_NOINIT) Com_RxTOutCntPtrType;

/**   \brief  type used to point to Com_RxTOutInfo */
typedef P2CONST(Com_RxTOutInfoType, TYPEDEF, COM_CONST) Com_RxTOutInfoPtrType;

/**   \brief  type used to point to Com_RxTOutInfoInd */
typedef P2CONST(Com_RxTOutInfoIndType, TYPEDEF, COM_CONST) Com_RxTOutInfoIndPtrType;

/**   \brief  type used to point to Com_TmpRxBuffer */
typedef P2VAR(Com_TmpRxBufferType, TYPEDEF, COM_VAR_NOINIT) Com_TmpRxBufferPtrType;

/**   \brief  type used to point to Com_TransmitRequest */
typedef P2VAR(Com_TransmitRequestType, TYPEDEF, COM_VAR_NOINIT) Com_TransmitRequestPtrType;

/**   \brief  type used to point to Com_TxBuffer */
typedef P2VAR(Com_TxBufferType, TYPEDEF, COM_VAR_NOINIT) Com_TxBufferPtrType;

/**   \brief  type used to point to Com_TxCyclicPdu */
typedef P2CONST(Com_TxCyclicPduType, TYPEDEF, COM_CONST) Com_TxCyclicPduPtrType;

/**   \brief  type used to point to Com_TxCyclicProcessingISRLockCounter */
typedef P2VAR(Com_TxCyclicProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxIPduGroupISRLockCounter */
typedef P2VAR(Com_TxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxModeFalse */
typedef P2CONST(Com_TxModeFalseType, TYPEDEF, COM_CONST) Com_TxModeFalsePtrType;

/**   \brief  type used to point to Com_TxModeInfo */
typedef P2CONST(Com_TxModeInfoType, TYPEDEF, COM_CONST) Com_TxModeInfoPtrType;

/**   \brief  type used to point to Com_TxModeTrue */
typedef P2CONST(Com_TxModeTrueType, TYPEDEF, COM_CONST) Com_TxModeTruePtrType;

/**   \brief  type used to point to Com_TxPduCalloutFuncPtr */
typedef P2CONST(ComTxPduCalloutType, TYPEDEF, COM_CONST) Com_TxPduCalloutFuncPtrPtrType;

/**   \brief  type used to point to Com_TxPduGrpActive */
typedef P2VAR(Com_TxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_TxPduGrpActivePtrType;

/**   \brief  type used to point to Com_TxPduInfo */
typedef P2CONST(Com_TxPduInfoType, TYPEDEF, COM_CONST) Com_TxPduInfoPtrType;

/**   \brief  type used to point to Com_TxPduInfoInd */
typedef P2CONST(Com_TxPduInfoIndType, TYPEDEF, COM_CONST) Com_TxPduInfoIndPtrType;

/**   \brief  type used to point to Com_TxPduInitValue */
typedef P2CONST(Com_TxPduInitValueType, TYPEDEF, COM_CONST) Com_TxPduInitValuePtrType;

/**   \brief  type used to point to Com_TxPduTTCalloutFuncPtr */
typedef P2CONST(ComTxPduCalloutType, TYPEDEF, COM_CONST) Com_TxPduTTCalloutFuncPtrPtrType;

/**   \brief  type used to point to Com_TxProcessingISRLockCounter */
typedef P2VAR(Com_TxProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxSduLength */
typedef P2VAR(Com_TxSduLengthType, TYPEDEF, COM_VAR_NOINIT) Com_TxSduLengthPtrType;

/**   \brief  type used to point to Com_TxSigInfo */
typedef P2CONST(Com_TxSigInfoType, TYPEDEF, COM_CONST) Com_TxSigInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootValueTypes  Com Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 Com_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_CbkRxTOutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkRxTOutFuncPtr
  \brief  Function pointer table containing configured Rx timeout notifications for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComCbkRxTOutType, COM_CONST) Com_CbkRxTOutFuncPtr[47];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CbkTxAckDefFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_CbkTxAckDefFuncPtr
  \brief  Function pointer table for deferred Tx confirmation notification functions.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComCbkTxAckDefType, COM_CONST) Com_CbkTxAckDefFuncPtr[47];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueArrayBased
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueArrayBasedType, COM_CONST) Com_ConstValueArrayBased[671];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfo
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfo
  \brief  Contains all I-Pdu Group relevant information
  \details
  Element                 Description
  RxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_RxPduInfoInd
  RxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_RxPduInfoInd
  TxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxPduInfoInd
  TxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxPduInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_IPduGroupInfoType, COM_CONST) Com_IPduGroupInfo[8];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfRxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfRxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfRxPduInfoInd[142];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupInfoOfTxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_IPduGroupInfoOfTxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_IPduGroupInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CONST) Com_IPduGroupInfoOfTxPduInfoInd[103];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                                  Description
  BitLength                                Bit length of the signal or group signal.
  ConstValueArrayBasedInitValueEndIdx      the end index of the 0:n relation pointing to Com_ConstValueArrayBased
  ConstValueArrayBasedInitValueStartIdx    the start index of the 0:n relation pointing to Com_ConstValueArrayBased
  RxSigBufferArrayBasedBufferEndIdx        the end index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedBufferStartIdx      the start index of the 0:n relation pointing to Com_RxSigBufferArrayBased
  RxSigBufferArrayBasedBufferUsed          TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigBufferArrayBased
  ApplType                                 Application data type.
  BusAcc                                   BUS access algorithm for signal or group signal packing / un-packing.
  BytePosition                             Little endian byte position of the signal or group signal within the I-PDU.
  RxPduInfoIdx                             the index of the 1:1 relation pointing to Com_RxPduInfo
  RxTOutInfoIdx                            the index of the 0:1 relation pointing to Com_RxTOutInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[141];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[141];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxCbkFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxCbkFuncPtr
  \brief  Function pointer table containing configured notification and invalid notifications function pointer for signals and signal groups.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComRxCbkType, COM_CONST) Com_RxCbkFuncPtr[49];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_RxPduCalloutFuncPtr
  \brief  Rx I-PDU callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComRxPduCalloutType, COM_CONST) Com_RxPduCalloutFuncPtr[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                                Description
  RxDefPduBufferEndIdx                   the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx                 the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  IPduGroupInfoOfRxPduInfoIndUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  RxTOutInfoUsed                         TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxTOutInfo
  IPduGroupInfoOfRxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  IPduGroupInfoOfRxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfRxPduInfoInd
  RxTOutInfoIdx                          the index of the 0:1 relation pointing to Com_RxTOutInfo
  RxTOutInfoIndEndIdx                    the end index of the 0:n relation pointing to Com_RxTOutInfoInd
  RxTOutInfoIndStartIdx                  the start index of the 0:n relation pointing to Com_RxTOutInfoInd
  SignalProcessing                       Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[141];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxPduInfoIndType, COM_CONST) Com_RxPduInfoInd[142];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element               Description
  RxAccessInfoIdx       the index of the 1:1 relation pointing to Com_RxAccessInfo
  RxCbkFuncPtrAckIdx    the index of the 0:1 relation pointing to Com_RxCbkFuncPtr
  RxTOutInfoIdx         the index of the 0:1 relation pointing to Com_RxTOutInfo
  SignalProcessing  
  ValidDlc              Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[141];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutInfo
  \brief  Contains all relevant information for signal based and I-PDu based Rx deadline monitoring.
  \details
  Element         Description
  Factor          Deadline monitoring timeout factor.
  FirstFactor     Timeout factor for first deadline monitoring.
  RxPduInfoIdx    the index of the 1:1 relation pointing to Com_RxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxTOutInfoType, COM_CONST) Com_RxTOutInfo[47];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicPdu
**********************************************************************************************************************/
/** 
  \var    Com_TxCyclicPdu
  \details
  Element         Description
  TxPduInfoIdx    the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxCyclicPduType, COM_CONST) Com_TxCyclicPdu[47];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
  Direct        TRUE if transmission mode contains a direct part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[8];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element          Description
  InitMode         Initial transmission mode selector of the Tx I-PDU.
  MinimumDelay     Minimum delay factor of the Tx I-PDU.
  TxModeTrueIdx    the index of the 1:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[54];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
  Direct        TRUE if transmission mode contains a direct part.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[8];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_TxPduCalloutFuncPtr
  \brief  Tx I-PDU callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComTxPduCalloutType, COM_CONST) Com_TxPduCalloutFuncPtr[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                                Description
  TxPduInitValueEndIdx                   the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx                 the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueUsed                     TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  TxPduTTCalloutFuncPtrUsed              TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxPduTTCalloutFuncPtr
  CbkTxAckDefFuncPtrIndEndIdx            the end index of the 0:n relation pointing to Com_CbkTxAckDefFuncPtrInd
  CbkTxAckDefFuncPtrIndStartIdx          the start index of the 0:n relation pointing to Com_CbkTxAckDefFuncPtrInd
  ExternalId                             External ID used to call PduR_ComTransmit().
  IPduGroupInfoOfTxPduInfoIndEndIdx      the end index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  IPduGroupInfoOfTxPduInfoIndStartIdx    the start index of the 0:n relation pointing to Com_IPduGroupInfoOfTxPduInfoInd
  MetaDataLength                         Length of MetaData.
  TxBufferLength                         the number of relations pointing to Com_TxBuffer
  TxPduCalloutFuncPtrIdx                 the index of the 0:1 relation pointing to Com_TxPduCalloutFuncPtr
  TxPduTTCalloutFuncPtrIdx               the index of the 0:1 relation pointing to Com_TxPduTTCalloutFuncPtr
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[54];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInfoIndType, COM_CONST) Com_TxPduInfoInd[103];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[1110];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduTTCalloutFuncPtr
**********************************************************************************************************************/
/** 
  \var    Com_TxPduTTCalloutFuncPtr
  \brief  Tx I-PDU trigger transmit callout function pointer table.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComTxPduCalloutType, COM_CONST) Com_TxPduTTCalloutFuncPtr[1];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitLength                 Bit length of the signal or group signal.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  ApplType                  Application data type.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[56];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[54];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleTxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleTxPduDeferred
  \brief  Flag array used for deferred Tx confirmation handling.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_HandleTxPduDeferredType, COM_VAR_NOINIT) Com_HandleTxPduDeferred[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_IPduGroupState
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_IPduGroupStateType, COM_VAR_NOINIT) Com_IPduGroupState[8];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredFctPtrCache
**********************************************************************************************************************/
/** 
  \var    Com_RxDeferredFctPtrCache
  \brief  Cache for deferred Rx (invalid) notification.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeferredFctPtrCacheType, COM_VAR_NOINIT) Com_RxDeferredFctPtrCache[1];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduDmState
**********************************************************************************************************************/
/** 
  \var    Com_RxPduDmState
  \brief  Rx I-PDU based deadline monitoring state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxPduDmStateType, COM_VAR_NOINIT) Com_RxPduDmState[47];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[141];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferArrayBased
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferArrayBased
  \brief  Rx Signal and Group Signal Buffer. (UINT8_N, UINT8_DYN)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferArrayBasedType, COM_VAR_NOINIT) Com_RxSigBufferArrayBased[2616];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxTOutCnt
**********************************************************************************************************************/
/** 
  \var    Com_RxTOutCnt
  \brief  This array holds timeout counters for all Rx timeout objects.
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxTOutCntType, COM_VAR_NOINIT) Com_RxTOutCnt[47];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TmpRxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TmpRxBuffer
  \brief  Temporary buffer for Rx UINT8_N and UINT8_DYN signals.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TmpRxBufferType, COM_VAR_NOINIT) Com_TmpRxBuffer[64];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[1110];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[54];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[54];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  RECEIVE MACRO API
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* User Config File Start */

/* User Config File End */


#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

