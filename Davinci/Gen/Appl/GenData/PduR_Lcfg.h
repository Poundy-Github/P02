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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.h
 *   Generation Time: 2022-04-12 19:43:18
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (PDUR_LCFG_H)
# define PDUR_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_Cfg.h"
# include "Os.h"
# include "PduR_PBcfg.h"

/* include headers with symbolic name values */
/* \trace SPEC-2020167 */

#include "CanIf.h"
#include "CanNm.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm_Cbk.h"
#include "SecOC.h"
#include "SecOC_Cbk.h"


/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCDataSwitches  PduR Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_APPLICATIONID2DESTAPPLICATIONMANAGERROM                                                STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                  STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTAPPLICATIONMANAGERROMUSEDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                 STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INVALIDHNDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                                    STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERARRAYRAM                                                                     STD_ON
#define PDUR_BMTXBUFFERINDROM                                                                       STD_ON
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                                     STD_ON
#define PDUR_BMTXBUFFERINSTANCERAM                                                                  STD_ON
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                       STD_ON
#define PDUR_BMTXBUFFERINSTANCEROM                                                                  STD_ON
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                                STD_ON
#define PDUR_BMTXBUFFERRAM                                                                          STD_ON
#define PDUR_ALLOCATEDOFBMTXBUFFERRAM                                                               STD_ON
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                              STD_ON
#define PDUR_RXLENGTHOFBMTXBUFFERRAM                                                                STD_ON
#define PDUR_BMTXBUFFERROM                                                                          STD_ON
#define PDUR_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                                STD_ON
#define PDUR_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                                STD_ON
#define PDUR_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                              STD_ON
#define PDUR_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                             STD_ON
#define PDUR_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                           STD_ON
#define PDUR_CONFIGID                                                                               STD_ON
#define PDUR_DEFERREDEVENTCACHEARRAYRAM                                                             STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_RMGDESTROMIDXOFDEFERREDEVENTCACHEARRAYRAM                                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHERAM                                                                  STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMREADIDXOFDEFERREDEVENTCACHERAM                               STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMWRITEIDXOFDEFERREDEVENTCACHERAM                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMENDIDXOFDEFERREDEVENTCACHEROM                                STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMLENGTHOFDEFERREDEVENTCACHEROM                                STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMSTARTIDXOFDEFERREDEVENTCACHEROM                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DESTAPPLICATIONMANAGERROM                                                              STD_ON
#define PDUR_MMROMINDENDIDXOFDESTAPPLICATIONMANAGERROM                                              STD_ON
#define PDUR_MMROMINDSTARTIDXOFDESTAPPLICATIONMANAGERROM                                            STD_ON
#define PDUR_MMROMINDUSEDOFDESTAPPLICATIONMANAGERROM                                                STD_ON
#define PDUR_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                                     STD_ON
#define PDUR_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                   STD_ON
#define PDUR_EXCLUSIVEAREAROM                                                                       STD_ON
#define PDUR_LOCKOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_UNLOCKOFEXCLUSIVEAREAROM                                                               STD_ON
#define PDUR_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_FMFIFOELEMENTRAM                                                                       STD_ON
#define PDUR_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                     STD_ON
#define PDUR_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                         STD_ON
#define PDUR_FMFIFOINSTANCERAM                                                                      STD_ON
#define PDUR_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                            STD_ON
#define PDUR_FMFIFOINSTANCEROM                                                                      STD_ON
#define PDUR_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                        STD_ON
#define PDUR_FMFIFORAM                                                                              STD_ON
#define PDUR_FILLLEVELOFFMFIFORAM                                                                   STD_ON
#define PDUR_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                     STD_ON
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                    STD_ON
#define PDUR_PENDINGCONFIRMATIONSOFFMFIFORAM                                                        STD_ON
#define PDUR_TPTXSMSTATEOFFMFIFORAM                                                                 STD_ON
#define PDUR_FMFIFOROM                                                                              STD_ON
#define PDUR_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                      STD_ON
#define PDUR_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                      STD_ON
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                                    STD_ON
#define PDUR_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                      STD_ON
#define PDUR_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                      STD_ON
#define PDUR_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                                    STD_ON
#define PDUR_LOCKROMIDXOFFMFIFOROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: 'the optional indirection is deactivated because LockRomUsedOfFmFifoRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_LOCKROMUSEDOFFMFIFOROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: 'the optional indirection is deactivated because LockRomUsedOfFmFifoRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_GENERALPROPERTIESROM                                                                   STD_ON
#define PDUR_MASKEDBITSOFGENERALPROPERTIESROM                                                       STD_ON
#define PDUR_SPINLOCKRETRYCOUNTEROFGENERALPROPERTIESROM                                             STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' */
#define PDUR_HASIFROUTINGOFGENERALPROPERTIESROM                                                     STD_ON
#define PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM                                                      STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'the value of PduR_hasIfTxFifoOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM                                        STD_ON
#define PDUR_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZED                                                                            STD_ON
#define PDUR_INTERFACEFIFOQUEUEARRAYRAM                                                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAM                                                           STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ACTUALLENGTHOFINTERFACEFIFOQUEUEELEMENTRAM                                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUERAM                                                                  STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FIFOFULLOFINTERFACEFIFOQUEUERAM                                                        STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMREADIDXOFINTERFACEFIFOQUEUERAM                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMWRITEIDXOFINTERFACEFIFOQUEUERAM                            STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMENDIDXOFINTERFACEFIFOQUEUEROM                                STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMENDIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                            STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_MAXPDULENGTHOFINTERFACEFIFOQUEUEROM                                                    STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIDXOFINTERFACEFIFOQUEUEROM                                                    STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LOCKROM                                                                                STD_ON
#define PDUR_EXCLUSIVEAREAROMIDXOFLOCKROM                                                           STD_ON
#define PDUR_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                          STD_ON
#define PDUR_SPINLOCKRAMIDXOFLOCKROM                                                                STD_OFF  /**< Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_SPINLOCKRAMUSEDOFLOCKROM                                                               STD_OFF  /**< Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAM                                                                      STD_OFF  /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERRAM                                                                           STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMPENDINGREADIDXOFMCQBUFFERRAM                                          STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMPENDINGWRITEIDXOFMCQBUFFERRAM                                         STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMREADIDXOFMCQBUFFERRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMWRITEIDXOFMCQBUFFERRAM                                                STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERROM                                                                           STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMENDIDXOFMCQBUFFERROM                                                  STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMLENGTHOFMCQBUFFERROM                                                  STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMSTARTIDXOFMCQBUFFERROM                                                STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MMROM                                                                                  STD_ON
#define PDUR_CANCELRECEIVESUPPORTEDOFMMROM                                                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.ChangeParameterSupported' Reason: 'the value of PduR_ChangeParameterSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFMMROM                                                    STD_ON
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_LOIFCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOIFOFMMROM                                                                            STD_ON
#define PDUR_LOIFTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_LOTPCANCELRECEIVEFCTPTROFMMROM                                                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpChangeParameterFctPtr' Reason: 'the value of PduR_LoTpChangeParameterFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPOFMMROM                                                                            STD_ON
#define PDUR_LOTPTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_MASKEDBITSOFMMROM                                                                      STD_ON
#define PDUR_RMGDESTROMENDIDXOFMMROM                                                                STD_ON
#define PDUR_RMGDESTROMSTARTIDXOFMMROM                                                              STD_ON
#define PDUR_RMGDESTROMUSEDOFMMROM                                                                  STD_ON
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_UPIFOFMMROM                                                                            STD_ON
#define PDUR_UPIFRXINDICATIONFCTPTROFMMROM                                                          STD_ON
#define PDUR_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                       STD_ON
#define PDUR_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPCOPYRXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPCOPYTXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPOFMMROM                                                                            STD_ON
#define PDUR_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_UPTPTPRXINDICATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_MMROMIND                                                                               STD_ON
#define PDUR_PARTITIONIDENTIFIERS                                                                   STD_ON
#define PDUR_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define PDUR_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define PDUR_PARTITIONLOOKUPTABLERAM                                                                STD_OFF  /**< Deactivateable: 'PduR_PartitionLookupTableRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_OSAPPLICATIONTOPDUROFPARTITIONLOOKUPTABLERAM                                           STD_OFF  /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_QUEUEFCTPTRROM                                                                         STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FLUSHFCTPTROFQUEUEFCTPTRROM                                                            STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_GETFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_GETFILLLEVELFCTPTROFQUEUEFCTPTRROM                                                     STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PUTFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_REMOVEFCTPTROFQUEUEFCTPTRROM                                                           STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMBUFFEREDIFPROPERTIESRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                           STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                         STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMBUFFEREDTPPROPERTIESRAM                                                              STD_ON
#define PDUR_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                         STD_ON
#define PDUR_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                                 STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROM                                                              STD_ON
#define PDUR_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                                STD_ON
#define PDUR_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' */
#define PDUR_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the value of PduR_MetaDataLengthUsedOfRmBufferedTpPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                               STD_ON
#define PDUR_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                                 STD_ON
#define PDUR_RMDESTROM                                                                              STD_ON
#define PDUR_BSWMPDURPRETRANSMITCALLBACKOFRMDESTROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_PARTITIONINDEXOFCSLOFRMDESTROM                                                         STD_ON
#define PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                                   STD_ON
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTROMIDXOFRMDESTROM                                                               STD_ON
#define PDUR_RMSRCROMIDXOFRMDESTROM                                                                 STD_ON
#define PDUR_ROUTINGTYPEOFRMDESTROM                                                                 STD_ON
#define PDUR_RMDESTRPGRAM                                                                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDCNTOFRMDESTRPGRAM                                                               STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTRPGROM                                                                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INITIALENABLEDCNTOFRMDESTRPGROM                                                        STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIDXOFRMDESTRPGROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMUSEDOFRMDESTRPGROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIND                                                                        STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTNTO1INFORAM                                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TRANSMISSIONACTIVEOFRMGDESTNTO1INFORAM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMGDESTROM                                                                             STD_ON
#define PDUR_DESTHNDOFRMGDESTROM                                                                    STD_ON
#define PDUR_DIRECTIONOFRMGDESTROM                                                                  STD_ON
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                       STD_ON
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                      STD_ON
#define PDUR_LOCKROMIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_MASKEDBITSOFRMGDESTROM                                                                 STD_ON
#define PDUR_MAXPDULENGTHOFRMGDESTROM                                                               STD_ON
#define PDUR_MMROMIDXOFRMGDESTROM                                                                   STD_ON
#define PDUR_PARTITIONINDEXOFCSLOFRMGDESTROM                                                        STD_ON
#define PDUR_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                      STD_ON
#define PDUR_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmBufferedIfPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmBufferedIfPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTROMIDXOFRMGDESTROM                                                               STD_ON
#define PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                     STD_ON
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                    STD_ON
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TXIF2UPIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_RMGDESTTPTXSTATERAM                                                                    STD_ON
#define PDUR_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                                   STD_ON
#define PDUR_RMSRCROM                                                                               STD_ON
#define PDUR_LOCKROMIDXOFRMSRCROM                                                                   STD_ON
#define PDUR_MASKEDBITSOFRMSRCROM                                                                   STD_ON
#define PDUR_MMROMIDXOFRMSRCROM                                                                     STD_ON
#define PDUR_PARTITIONINDEXOFCSLOFRMSRCROM                                                          STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                                 STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                                STD_ON
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                                                            STD_ON
#define PDUR_SMSRCROMIDXOFRMSRCROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SRCHNDOFRMSRCROM                                                                       STD_ON
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                     STD_ON
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                      STD_ON
#define PDUR_RMTRANSMITFCTPTR                                                                       STD_ON
#define PDUR_RPGEXTIDROM                                                                            STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INVALIDHNDOFRPGEXTIDROM                                                                STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFRPGEXTIDROM                                                       STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.PartitionIndexOfCsl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGROMIDXOFRPGEXTIDROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGROMUSEDOFRPGEXTIDROM                                                                STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGRAM                                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDOFRPGRAM                                                                        STD_OFF  /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RPGROM                                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_ENABLEDATINITOFRPGROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDENDIDXOFRPGROM                                                          STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                        STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDUSEDOFRPGROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXIF2DEST                                                                              STD_ON
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                                STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXIF2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFRXIF2DEST                                                         STD_ON
#define PDUR_RMSRCROMIDXOFRXIF2DEST                                                                 STD_ON
#define PDUR_RXTP2DEST                                                                              STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                              STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                          STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXTP2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFRXTP2DEST                                                         STD_ON
#define PDUR_RMSRCROMIDXOFRXTP2DEST                                                                 STD_ON
#define PDUR_RXTP2SRC                                                                               STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_INVALIDHNDOFRXTP2SRC                                                                   STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_PARTITIONINDEXOFCSLSTRINGSNVOFRXTP2SRC                                                 STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.PartitionIndexOfCslStringSNV' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_RMDESTROMIDXOFRXTP2SRC                                                                 STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.RmDestRomIdx' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_SINGLEBUFFERARRAYRAM                                                                   STD_OFF  /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERRAM                                                                        STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ACTUALLENGTHOFSINGLEBUFFERRAM                                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_SINGLEBUFFERROM                                                                        STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_RMDESTROMIDXOFSINGLEBUFFERROM                                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMENDIDXOFSINGLEBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMLENGTHOFSINGLEBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMSTARTIDXOFSINGLEBUFFERROM                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMENDIDXOFSINGLEBUFFERROM                                       STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMLENGTHOFSINGLEBUFFERROM                                       STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMSTARTIDXOFSINGLEBUFFERROM                                     STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SIZEOFBMTXBUFFERARRAYRAM                                                               STD_ON
#define PDUR_SIZEOFBMTXBUFFERINDROM                                                                 STD_ON
#define PDUR_SIZEOFBMTXBUFFERINSTANCERAM                                                            STD_ON
#define PDUR_SIZEOFBMTXBUFFERINSTANCEROM                                                            STD_ON
#define PDUR_SIZEOFBMTXBUFFERRAM                                                                    STD_ON
#define PDUR_SIZEOFBMTXBUFFERROM                                                                    STD_ON
#define PDUR_SIZEOFDESTAPPLICATIONMANAGERROM                                                        STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_SIZEOFFMFIFOELEMENTRAM                                                                 STD_ON
#define PDUR_SIZEOFFMFIFOINSTANCERAM                                                                STD_ON
#define PDUR_SIZEOFFMFIFOINSTANCEROM                                                                STD_ON
#define PDUR_SIZEOFFMFIFORAM                                                                        STD_ON
#define PDUR_SIZEOFFMFIFOROM                                                                        STD_ON
#define PDUR_SIZEOFGENERALPROPERTIESROM                                                             STD_ON
#define PDUR_SIZEOFLOCKROM                                                                          STD_ON
#define PDUR_SIZEOFMMROM                                                                            STD_ON
#define PDUR_SIZEOFMMROMIND                                                                         STD_ON
#define PDUR_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define PDUR_SIZEOFRMBUFFEREDTPPROPERTIESRAM                                                        STD_ON
#define PDUR_SIZEOFRMBUFFEREDTPPROPERTIESROM                                                        STD_ON
#define PDUR_SIZEOFRMDESTROM                                                                        STD_ON
#define PDUR_SIZEOFRMGDESTROM                                                                       STD_ON
#define PDUR_SIZEOFRMGDESTTPTXSTATERAM                                                              STD_ON
#define PDUR_SIZEOFRMSRCROM                                                                         STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTR                                                                 STD_ON
#define PDUR_SIZEOFRXIF2DEST                                                                        STD_ON
#define PDUR_SIZEOFRXTP2DEST                                                                        STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROM                                                                STD_ON
#define PDUR_SIZEOFTX2LO                                                                            STD_ON
#define PDUR_SIZEOFTXIF2UP                                                                          STD_ON
#define PDUR_SIZEOFTXTP2SRC                                                                         STD_ON
#define PDUR_SMDATAPLANEROM                                                                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                       STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMUSEDOFSMDATAPLANEROM                                                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                                STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                               STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                            STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAM                                                                               STD_OFF  /**< Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_LEARNEDCONNECTIONIDOFSMFIBRAM                                                          STD_OFF  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTR                                                                    STD_OFF  /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROM                                                                             STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMGDESTROM                                                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMGDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMGDESTROM                                                          STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR                                           STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM                                                   STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                           STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM                                               STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTR                                                                      STD_OFF  /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROM                                                                               STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMSRCROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMSRCROM                                                               STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMSRCROM                                                            STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM                             STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTRIDXOFSMSRCROM                                                         STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SPINLOCKRAM                                                                            STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_COUNTEROFSPINLOCKRAM                                                                   STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_LOCKVARIABLEOFSPINLOCKRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_SRCAPPLICATIONROM                                                                      STD_ON
#define PDUR_DEFERREDEVENTCACHEROMIDXOFSRCAPPLICATIONROM                                            STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEROMUSEDOFSRCAPPLICATIONROM                                           STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_MCQBUFFERROMIDXOFSRCAPPLICATIONROM                                                     STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERROMUSEDOFSRCAPPLICATIONROM                                                    STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_PARTITIONINDEXOFCSLOFSRCAPPLICATIONROM                                                 STD_ON
#define PDUR_TX2LO                                                                                  STD_ON
#define PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO                                                        STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_CANCELTRANSMITUSEDOFTX2LO                                                              STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' */
#define PDUR_INVALIDHNDOFTX2LO                                                                      STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFTX2LO                                                             STD_ON
#define PDUR_RMSRCROMIDXOFTX2LO                                                                     STD_ON
#define PDUR_RMSRCROMUSEDOFTX2LO                                                                    STD_ON
#define PDUR_RMTRANSMITFCTPTRIDXOFTX2LO                                                             STD_ON
#define PDUR_TXIF2UP                                                                                STD_ON
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                                STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXIF2UP                                                                    STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFTXIF2UP                                                           STD_ON
#define PDUR_RMGDESTROMIDXOFTXIF2UP                                                                 STD_ON
#define PDUR_TXCONFIRMATIONUSEDOFTXIF2UP                                                            STD_ON
#define PDUR_TXTP2SRC                                                                               STD_ON
#define PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC                                             STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXTP2SRC                                                                   STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_PARTITIONINDEXOFCSLOFTXTP2SRC                                                          STD_ON
#define PDUR_RMGDESTROMIDXOFTXTP2SRC                                                                STD_ON
#define PDUR_PCCONFIG                                                                               STD_ON
#define PDUR_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define PDUR_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define PDUR_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define PDUR_PCPARTITIONCONFIG                                                                      STD_ON
#define PDUR_BMTXBUFFERARRAYRAMOFPCPARTITIONCONFIG                                                  STD_ON
#define PDUR_BMTXBUFFERINDROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_BMTXBUFFERINSTANCERAMOFPCPARTITIONCONFIG                                               STD_ON
#define PDUR_BMTXBUFFERINSTANCEROMOFPCPARTITIONCONFIG                                               STD_ON
#define PDUR_BMTXBUFFERRAMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_BMTXBUFFERROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_CONFIGIDOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                           STD_ON
#define PDUR_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_FMFIFOELEMENTRAMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_FMFIFOINSTANCERAMOFPCPARTITIONCONFIG                                                   STD_ON
#define PDUR_FMFIFOINSTANCEROMOFPCPARTITIONCONFIG                                                   STD_ON
#define PDUR_FMFIFORAMOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_FMFIFOROMOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_INITIALIZEDOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_LOCKROMOFPCPARTITIONCONFIG                                                             STD_ON
#define PDUR_MMROMINDOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_MMROMOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESRAMOFPCPARTITIONCONFIG                                           STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMOFPCPARTITIONCONFIG                                           STD_ON
#define PDUR_RMDESTROMOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RMGDESTROMOFPCPARTITIONCONFIG                                                          STD_ON
#define PDUR_RMGDESTTPTXSTATERAMOFPCPARTITIONCONFIG                                                 STD_ON
#define PDUR_RMSRCROMOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_RXIF2DESTOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RXTP2DESTOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_SIZEOFBMTXBUFFERARRAYRAMOFPCPARTITIONCONFIG                                            STD_ON
#define PDUR_SIZEOFBMTXBUFFERINDROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFBMTXBUFFERINSTANCERAMOFPCPARTITIONCONFIG                                         STD_ON
#define PDUR_SIZEOFBMTXBUFFERINSTANCEROMOFPCPARTITIONCONFIG                                         STD_ON
#define PDUR_SIZEOFBMTXBUFFERRAMOFPCPARTITIONCONFIG                                                 STD_ON
#define PDUR_SIZEOFBMTXBUFFERROMOFPCPARTITIONCONFIG                                                 STD_ON
#define PDUR_SIZEOFDESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFFMFIFOELEMENTRAMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFFMFIFOINSTANCERAMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_SIZEOFFMFIFOINSTANCEROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_SIZEOFFMFIFORAMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFFMFIFOROMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFGENERALPROPERTIESROMOFPCPARTITIONCONFIG                                          STD_ON
#define PDUR_SIZEOFLOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_SIZEOFMMROMINDOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SIZEOFMMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFRMBUFFEREDTPPROPERTIESRAMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_SIZEOFRMBUFFEREDTPPROPERTIESROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_SIZEOFRMDESTROMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRMGDESTROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_SIZEOFRMGDESTTPTXSTATERAMOFPCPARTITIONCONFIG                                           STD_ON
#define PDUR_SIZEOFRMSRCROMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFRXIF2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_SIZEOFTX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFTXIF2UPOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                                   STD_ON
#define PDUR_TX2LOOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_TXIF2UPOFPCPARTITIONCONFIG                                                             STD_ON
#define PDUR_TXTP2SRCOFPCPARTITIONCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMinNumericValueDefines  PduR Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define PDUR_MIN_BMTXBUFFERARRAYRAM                                                                 0u
#define PDUR_MIN_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                   0u
#define PDUR_MIN_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                          0u
#define PDUR_MIN_RXLENGTHOFBMTXBUFFERRAM                                                            0u
#define PDUR_MIN_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                 0u
#define PDUR_MIN_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                     0u
#define PDUR_MIN_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                        0u
#define PDUR_MIN_FILLLEVELOFFMFIFORAM                                                               0u
#define PDUR_MIN_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                 0u
#define PDUR_MIN_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                0u
#define PDUR_MIN_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                     0u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaxNumericValueDefines  PduR Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define PDUR_MAX_BMTXBUFFERARRAYRAM                                                                 255u
#define PDUR_MAX_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                   4294967295u
#define PDUR_MAX_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                          4294967295u
#define PDUR_MAX_RXLENGTHOFBMTXBUFFERRAM                                                            4294967295u
#define PDUR_MAX_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                 255u
#define PDUR_MAX_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                     255u
#define PDUR_MAX_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                        255u
#define PDUR_MAX_FILLLEVELOFFMFIFORAM                                                               65535u
#define PDUR_MAX_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                 255u
#define PDUR_MAX_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                255u
#define PDUR_MAX_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                     255u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCNoReferenceDefines  PduR No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                    4294967295u
#define PDUR_NO_MMROMINDENDIDXOFDESTAPPLICATIONMANAGERROM                                           255u
#define PDUR_NO_MMROMINDSTARTIDXOFDESTAPPLICATIONMANAGERROM                                         255u
#define PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                  255u
#define PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                         255u
#define PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM                                                        255u
#define PDUR_NO_RMGDESTROMENDIDXOFMMROM                                                             255u
#define PDUR_NO_RMGDESTROMSTARTIDXOFMMROM                                                           255u
#define PDUR_NO_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                      255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFRMDESTROM                                                      255u
#define PDUR_NO_DESTHNDOFRMGDESTROM                                                                 255u
#define PDUR_NO_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                    255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFRMGDESTROM                                                     255u
#define PDUR_NO_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                  255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFRMSRCROM                                                       255u
#define PDUR_NO_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                              255u
#define PDUR_NO_SRCHNDOFRMSRCROM                                                                    255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFRXIF2DEST                                                      255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFRXTP2DEST                                                      255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFSRCAPPLICATIONROM                                              255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFTX2LO                                                          255u
#define PDUR_NO_RMSRCROMIDXOFTX2LO                                                                  255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFTXIF2UP                                                        255u
#define PDUR_NO_PARTITIONINDEXOFCSLOFTXTP2SRC                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumExistsDefines  PduR Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM               STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SIMPLE_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_DIRECT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_TRIGGER_TRANSMIT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_FIFO_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                       STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_ON
#define PDUR_EXISTS_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_ON
#define PDUR_EXISTS_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM                                      STD_OFF
#define PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF
#define PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_ON
#define PDUR_EXISTS_RX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_TX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM                                      STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredReception] and /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredTransmission] are both disabled. */
#define PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumDefines  PduR Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM                                                      0x00u
#define PDUR_RM_TX_RECEPTION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                                          0x01u
#define PDUR_RM_TX_TRANSMISSION_FINISHED_TPTXSMSTATEOFFMFIFORAM                                     0x02u
#define PDUR_RM_TX_RECEPTION_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                             0x03u
#define PDUR_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                    0x04u
#define PDUR_RM_RX_IDLE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                      0x00u
#define PDUR_RM_RX_ACTIVE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                    0x01u
#define PDUR_RM_RX_ABORTED_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                   0x02u
#define PDUR_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                           0x01u
#define PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x02u
#define PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x03u
#define PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x00u
#define PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x01u
#define PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x04u
#define PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x05u
#define PDUR_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                                                     0x06u
#define PDUR_RX_DIRECTIONOFRMGDESTROM                                                               0x00u
#define PDUR_TX_DIRECTIONOFRMGDESTROM                                                               0x01u
#define PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                            0x01u
#define PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                    0x00u
#define PDUR_RM_TXINST_ACTIVE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                  0x01u
#define PDUR_RM_TXINST_WAITING_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                 0x02u
#define PDUR_RM_TXINST_ABORTED_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                 0x03u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaskedBitDefines  PduR Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define PDUR_HASIFROUTINGOFGENERALPROPERTIESROM_MASK                                                0x02u
#define PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM_MASK                                   0x01u
#define PDUR_LOIFOFMMROM_MASK                                                                       0x10u
#define PDUR_LOTPOFMMROM_MASK                                                                       0x08u
#define PDUR_RMGDESTROMUSEDOFMMROM_MASK                                                             0x04u
#define PDUR_UPIFOFMMROM_MASK                                                                       0x02u
#define PDUR_UPTPOFMMROM_MASK                                                                       0x01u
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM_MASK                                                 0x02u
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM_MASK                                               0x01u
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM_MASK                                           0x04u
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM_MASK                                                0x02u
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM_MASK                                                 0x01u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIsReducedToDefineDefines  PduR Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                               STD_OFF
#define PDUR_ISDEF_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                        STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                       STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                     STD_OFF
#define PDUR_ISDEF_MMROMINDENDIDXOFDESTAPPLICATIONMANAGERROM                                        STD_OFF
#define PDUR_ISDEF_MMROMINDSTARTIDXOFDESTAPPLICATIONMANAGERROM                                      STD_OFF
#define PDUR_ISDEF_MMROMINDUSEDOFDESTAPPLICATIONMANAGERROM                                          STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                               STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                             STD_OFF
#define PDUR_ISDEF_LOCKOFEXCLUSIVEAREAROM                                                           STD_OFF
#define PDUR_ISDEF_UNLOCKOFEXCLUSIVEAREAROM                                                         STD_OFF
#define PDUR_ISDEF_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                  STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                              STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                              STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFGENERALPROPERTIESROM                                                 STD_OFF
#define PDUR_ISDEF_HASIFROUTINGOFGENERALPROPERTIESROM                                               STD_OFF
#define PDUR_ISDEF_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM                                  STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMIDXOFLOCKROM                                                     STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                    STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFMMROM                                              STD_OFF
#define PDUR_ISDEF_LOIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOIFTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_LOTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOTPTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFMMROM                                                                STD_OFF
#define PDUR_ISDEF_RMGDESTROMENDIDXOFMMROM                                                          STD_OFF
#define PDUR_ISDEF_RMGDESTROMSTARTIDXOFMMROM                                                        STD_OFF
#define PDUR_ISDEF_RMGDESTROMUSEDOFMMROM                                                            STD_OFF
#define PDUR_ISDEF_UPIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPIFRXINDICATIONFCTPTROFMMROM                                                    STD_OFF
#define PDUR_ISDEF_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                 STD_OFF
#define PDUR_ISDEF_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPCOPYRXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPCOPYTXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_UPTPTPRXINDICATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_MMROMIND                                                                         STD_OFF
#define PDUR_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define PDUR_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define PDUR_ISDEF_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                          STD_OFF
#define PDUR_ISDEF_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                         STD_OFF
#define PDUR_ISDEF_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                           STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFRMDESTROM                                                   STD_OFF
#define PDUR_ISDEF_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                             STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFRMDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_ROUTINGTYPEOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_DESTHNDOFRMGDESTROM                                                              STD_OFF
#define PDUR_ISDEF_DIRECTIONOFRMGDESTROM                                                            STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                 STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_MAXPDULENGTHOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMGDESTROM                                                             STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFRMGDESTROM                                                  STD_OFF
#define PDUR_ISDEF_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                               STD_OFF
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                              STD_OFF
#define PDUR_ISDEF_TXIF2UPIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMSRCROM                                                               STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFRMSRCROM                                                    STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                           STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                          STD_OFF
#define PDUR_ISDEF_RMDESTROMENDIDXOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMLENGTHOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMSTARTIDXOFRMSRCROM                                                      STD_OFF
#define PDUR_ISDEF_SRCHNDOFRMSRCROM                                                                 STD_OFF
#define PDUR_ISDEF_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                               STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTR                                                                 STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFRXIF2DEST                                                   STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXIF2DEST                                                           STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFRXTP2DEST                                                   STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXTP2DEST                                                           STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFSRCAPPLICATIONROM                                           STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFTX2LO                                                       STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFTX2LO                                                               STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFTX2LO                                                              STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTRIDXOFTX2LO                                                       STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFTXIF2UP                                                     STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXIF2UP                                                           STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONUSEDOFTXIF2UP                                                      STD_OFF
#define PDUR_ISDEF_PARTITIONINDEXOFCSLOFTXTP2SRC                                                    STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXTP2SRC                                                          STD_OFF
#define PDUR_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_ON
#define PDUR_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMOFPCPARTITIONCONFIG                                            STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMOFPCPARTITIONCONFIG                                              STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCERAMOFPCPARTITIONCONFIG                                         STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCEROMOFPCPARTITIONCONFIG                                         STD_OFF
#define PDUR_ISDEF_BMTXBUFFERRAMOFPCPARTITIONCONFIG                                                 STD_OFF
#define PDUR_ISDEF_BMTXBUFFERROMOFPCPARTITIONCONFIG                                                 STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_ISDEF_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_FMFIFOELEMENTRAMOFPCPARTITIONCONFIG                                              STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCERAMOFPCPARTITIONCONFIG                                             STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMOFPCPARTITIONCONFIG                                             STD_OFF
#define PDUR_ISDEF_FMFIFORAMOFPCPARTITIONCONFIG                                                     STD_OFF
#define PDUR_ISDEF_FMFIFOROMOFPCPARTITIONCONFIG                                                     STD_OFF
#define PDUR_ISDEF_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                          STD_ON
#define PDUR_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                   STD_OFF
#define PDUR_ISDEF_LOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_ISDEF_MMROMINDOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_ISDEF_MMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESRAMOFPCPARTITIONCONFIG                                     STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMOFPCPARTITIONCONFIG                                     STD_OFF
#define PDUR_ISDEF_RMDESTROMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_RMGDESTROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMOFPCPARTITIONCONFIG                                           STD_OFF
#define PDUR_ISDEF_RMSRCROMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_ISDEF_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_RXIF2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_ISDEF_TX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_TXIF2UPOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_ISDEF_TXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEqualsAlwaysToDefines  PduR Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                                 
#define PDUR_EQ2_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                          
#define PDUR_EQ2_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                         
#define PDUR_EQ2_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                       
#define PDUR_EQ2_MMROMINDENDIDXOFDESTAPPLICATIONMANAGERROM                                          
#define PDUR_EQ2_MMROMINDSTARTIDXOFDESTAPPLICATIONMANAGERROM                                        
#define PDUR_EQ2_MMROMINDUSEDOFDESTAPPLICATIONMANAGERROM                                            
#define PDUR_EQ2_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                                 
#define PDUR_EQ2_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                               
#define PDUR_EQ2_LOCKOFEXCLUSIVEAREAROM                                                             
#define PDUR_EQ2_UNLOCKOFEXCLUSIVEAREAROM                                                           
#define PDUR_EQ2_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                    
#define PDUR_EQ2_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                  
#define PDUR_EQ2_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                  
#define PDUR_EQ2_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                                
#define PDUR_EQ2_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                  
#define PDUR_EQ2_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                  
#define PDUR_EQ2_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                                
#define PDUR_EQ2_MASKEDBITSOFGENERALPROPERTIESROM                                                   
#define PDUR_EQ2_HASIFROUTINGOFGENERALPROPERTIESROM                                                 
#define PDUR_EQ2_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM                                    
#define PDUR_EQ2_EXCLUSIVEAREAROMIDXOFLOCKROM                                                       
#define PDUR_EQ2_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                      
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFMMROM                                                
#define PDUR_EQ2_LOIFOFMMROM                                                                        
#define PDUR_EQ2_LOIFTRANSMITFCTPTROFMMROM                                                          
#define PDUR_EQ2_LOTPOFMMROM                                                                        
#define PDUR_EQ2_LOTPTRANSMITFCTPTROFMMROM                                                          
#define PDUR_EQ2_MASKEDBITSOFMMROM                                                                  
#define PDUR_EQ2_RMGDESTROMENDIDXOFMMROM                                                            
#define PDUR_EQ2_RMGDESTROMSTARTIDXOFMMROM                                                          
#define PDUR_EQ2_RMGDESTROMUSEDOFMMROM                                                              
#define PDUR_EQ2_UPIFOFMMROM                                                                        
#define PDUR_EQ2_UPIFRXINDICATIONFCTPTROFMMROM                                                      
#define PDUR_EQ2_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                   
#define PDUR_EQ2_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                    
#define PDUR_EQ2_UPTPCOPYRXDATAFCTPTROFMMROM                                                        
#define PDUR_EQ2_UPTPCOPYTXDATAFCTPTROFMMROM                                                        
#define PDUR_EQ2_UPTPOFMMROM                                                                        
#define PDUR_EQ2_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                  
#define PDUR_EQ2_UPTPTPRXINDICATIONFCTPTROFMMROM                                                    
#define PDUR_EQ2_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                  
#define PDUR_EQ2_MMROMIND                                                                           
#define PDUR_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define PDUR_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define PDUR_EQ2_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                            
#define PDUR_EQ2_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                           
#define PDUR_EQ2_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                             
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFRMDESTROM                                                     
#define PDUR_EQ2_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                               
#define PDUR_EQ2_RMGDESTROMIDXOFRMDESTROM                                                           
#define PDUR_EQ2_RMSRCROMIDXOFRMDESTROM                                                             
#define PDUR_EQ2_ROUTINGTYPEOFRMDESTROM                                                             
#define PDUR_EQ2_DESTHNDOFRMGDESTROM                                                                
#define PDUR_EQ2_DIRECTIONOFRMGDESTROM                                                              
#define PDUR_EQ2_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                   
#define PDUR_EQ2_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                  
#define PDUR_EQ2_LOCKROMIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_MASKEDBITSOFRMGDESTROM                                                             
#define PDUR_EQ2_MAXPDULENGTHOFRMGDESTROM                                                           
#define PDUR_EQ2_MMROMIDXOFRMGDESTROM                                                               
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFRMGDESTROM                                                    
#define PDUR_EQ2_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                  
#define PDUR_EQ2_RMDESTROMIDXOFRMGDESTROM                                                           
#define PDUR_EQ2_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                 
#define PDUR_EQ2_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                
#define PDUR_EQ2_TXIF2UPIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_LOCKROMIDXOFRMSRCROM                                                               
#define PDUR_EQ2_MASKEDBITSOFRMSRCROM                                                               
#define PDUR_EQ2_MMROMIDXOFRMSRCROM                                                                 
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFRMSRCROM                                                      
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                             
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                            
#define PDUR_EQ2_RMDESTROMENDIDXOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMLENGTHOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMSTARTIDXOFRMSRCROM                                                        
#define PDUR_EQ2_SRCHNDOFRMSRCROM                                                                   
#define PDUR_EQ2_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                 
#define PDUR_EQ2_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                  
#define PDUR_EQ2_RMTRANSMITFCTPTR                                                                   
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFRXIF2DEST                                                     
#define PDUR_EQ2_RMSRCROMIDXOFRXIF2DEST                                                             
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFRXTP2DEST                                                     
#define PDUR_EQ2_RMSRCROMIDXOFRXTP2DEST                                                             
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFSRCAPPLICATIONROM                                             
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFTX2LO                                                         
#define PDUR_EQ2_RMSRCROMIDXOFTX2LO                                                                 
#define PDUR_EQ2_RMSRCROMUSEDOFTX2LO                                                                
#define PDUR_EQ2_RMTRANSMITFCTPTRIDXOFTX2LO                                                         
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFTXIF2UP                                                       
#define PDUR_EQ2_RMGDESTROMIDXOFTXIF2UP                                                             
#define PDUR_EQ2_TXCONFIRMATIONUSEDOFTXIF2UP                                                        
#define PDUR_EQ2_PARTITIONINDEXOFCSLOFTXTP2SRC                                                      
#define PDUR_EQ2_RMGDESTROMIDXOFTXTP2SRC                                                            
#define PDUR_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        PduR_PCPartitionConfig
#define PDUR_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     PduR_PartitionIdentifiers
#define PDUR_EQ2_BMTXBUFFERARRAYRAMOFPCPARTITIONCONFIG                                              
#define PDUR_EQ2_BMTXBUFFERINDROMOFPCPARTITIONCONFIG                                                
#define PDUR_EQ2_BMTXBUFFERINSTANCERAMOFPCPARTITIONCONFIG                                           
#define PDUR_EQ2_BMTXBUFFERINSTANCEROMOFPCPARTITIONCONFIG                                           
#define PDUR_EQ2_BMTXBUFFERRAMOFPCPARTITIONCONFIG                                                   
#define PDUR_EQ2_BMTXBUFFERROMOFPCPARTITIONCONFIG                                                   
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                       PduR_DestApplicationManagerRom
#define PDUR_EQ2_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                                PduR_ExclusiveAreaRom
#define PDUR_EQ2_FMFIFOELEMENTRAMOFPCPARTITIONCONFIG                                                
#define PDUR_EQ2_FMFIFOINSTANCERAMOFPCPARTITIONCONFIG                                               
#define PDUR_EQ2_FMFIFOINSTANCEROMOFPCPARTITIONCONFIG                                               
#define PDUR_EQ2_FMFIFORAMOFPCPARTITIONCONFIG                                                       
#define PDUR_EQ2_FMFIFOROMOFPCPARTITIONCONFIG                                                       
#define PDUR_EQ2_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                            PduR_GeneralPropertiesRom
#define PDUR_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                     
#define PDUR_EQ2_LOCKROMOFPCPARTITIONCONFIG                                                         PduR_LockRom
#define PDUR_EQ2_MMROMINDOFPCPARTITIONCONFIG                                                        PduR_MmRomInd
#define PDUR_EQ2_MMROMOFPCPARTITIONCONFIG                                                           PduR_MmRom
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESRAMOFPCPARTITIONCONFIG                                       
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMOFPCPARTITIONCONFIG                                       
#define PDUR_EQ2_RMDESTROMOFPCPARTITIONCONFIG                                                       PduR_RmDestRom
#define PDUR_EQ2_RMGDESTROMOFPCPARTITIONCONFIG                                                      PduR_RmGDestRom
#define PDUR_EQ2_RMGDESTTPTXSTATERAMOFPCPARTITIONCONFIG                                             
#define PDUR_EQ2_RMSRCROMOFPCPARTITIONCONFIG                                                        PduR_RmSrcRom
#define PDUR_EQ2_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                PduR_RmTransmitFctPtr
#define PDUR_EQ2_RXIF2DESTOFPCPARTITIONCONFIG                                                       PduR_RxIf2Dest
#define PDUR_EQ2_RXTP2DESTOFPCPARTITIONCONFIG                                                       PduR_RxTp2Dest
#define PDUR_EQ2_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                               PduR_SrcApplicationRom
#define PDUR_EQ2_TX2LOOFPCPARTITIONCONFIG                                                           PduR_Tx2Lo
#define PDUR_EQ2_TXIF2UPOFPCPARTITIONCONFIG                                                         PduR_TxIf2Up
#define PDUR_EQ2_TXTP2SRCOFPCPARTITIONCONFIG                                                        PduR_TxTp2Src
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicNonDereferenciateablePointers  PduR Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define PduR_BmTxBufferIndRom                                                                       ((PduR_BmTxBufferIndRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_BmTxBufferInstanceRom                                                                  ((PduR_BmTxBufferInstanceRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_BmTxBufferRom                                                                          ((PduR_BmTxBufferRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_DestApplicationManagerRom                                                              ((PduR_DestApplicationManagerRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_FmFifoInstanceRom                                                                      ((PduR_FmFifoInstanceRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_FmFifoRom                                                                              ((PduR_FmFifoRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_GeneralPropertiesRom                                                                   ((PduR_GeneralPropertiesRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_LockRom                                                                                ((PduR_LockRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_MmRomInd                                                                               ((PduR_MmRomIndPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_RmBufferedTpPropertiesRom                                                              ((PduR_RmBufferedTpPropertiesRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
#define PduR_SrcApplicationRom                                                                      ((PduR_SrcApplicationRomPtrType)(&(PduR_PCPartitionConfig)))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicInitializationPointers  PduR Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define PduR_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'PduR' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCInitializationSymbols  PduR Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define PduR_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'PduR */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGeneral  PduR General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define PDUR_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define PDUR_FINAL_MAGIC_NUMBER                                                                     0x331Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of PduR */
#define PDUR_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'PduR' is not configured to be postbuild capable. */
#define PDUR_INIT_DATA                                                                              PDUR_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define PDUR_INIT_DATA_HASH_CODE                                                                    -863935689  /**< the precompile constant to validate the initialization structure at initialization time of PduR with a hashcode. The seed value is '0x331Eu' */
#define PDUR_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define PDUR_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer PduR shall be used. */
#define partitionIndexOfCSLForCommonSharedMemory                                                    0u  /**< internal partition index of the ComStackLib for the partition CommonSharedMemory */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTDataSwitches  PduR Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_LTCONFIG                                                                               STD_OFF  /**< Deactivateable: 'PduR_LTConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PDUR_LTPARTITIONCONFIGOFLTCONFIG                                                            STD_OFF  /**< Deactivateable: 'PduR_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PDUR_LTPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'PduR_LTPartitionConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/** BroadcastDummy */

#define PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE 6

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  PduRPCGetRootDataMacros  PduR Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define PduR_GetBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)                               PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferArrayRamOfPCPartitionConfig
#define PduR_GetBmTxBufferIndRomOfPCPartitionConfig(partitionIndex)                                 PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferIndRomOfPCPartitionConfig
#define PduR_GetBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)                            PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferInstanceRamOfPCPartitionConfig
#define PduR_GetBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)                            PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferInstanceRomOfPCPartitionConfig
#define PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)                                    PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferRamOfPCPartitionConfig
#define PduR_GetBmTxBufferRomOfPCPartitionConfig(partitionIndex)                                    PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].BmTxBufferRomOfPCPartitionConfig
#define PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex)                                 PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].FmFifoElementRamOfPCPartitionConfig
#define PduR_GetFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)                                PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].FmFifoInstanceRamOfPCPartitionConfig
#define PduR_GetFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)                                PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].FmFifoInstanceRomOfPCPartitionConfig
#define PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)                                        PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].FmFifoRamOfPCPartitionConfig
#define PduR_GetFmFifoRomOfPCPartitionConfig(partitionIndex)                                        PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].FmFifoRomOfPCPartitionConfig
#define PduR_GetInitializedOfPCPartitionConfig(partitionIndex)                                      PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InitializedOfPCPartitionConfig
#define PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)                        PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RmBufferedTpPropertiesRamOfPCPartitionConfig
#define PduR_GetRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)                        PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RmBufferedTpPropertiesRomOfPCPartitionConfig
#define PduR_GetRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)                              PduR_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RmGDestTpTxStateRamOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetConstantDuplicatedRootDataMacros  PduR Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define PduR_GetPCPartitionConfigOfPCConfig()                                                       PduR_PCPartitionConfig  /**< the pointer to PduR_PCPartitionConfig */
#define PduR_GetPartitionIdentifiersOfPCConfig()                                                    PduR_PartitionIdentifiers  /**< the pointer to PduR_PartitionIdentifiers */
#define PduR_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in PduR_PartitionIdentifiers */
#define PduR_GetConfigIdOfPCPartitionConfig(partitionIndex)                                         0u  /**< DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRConfigurationId */
#define PduR_GetDestApplicationManagerRomOfPCPartitionConfig()                                      PduR_DestApplicationManagerRom  /**< the pointer to PduR_DestApplicationManagerRom */
#define PduR_GetExclusiveAreaRomOfPCPartitionConfig()                                               PduR_ExclusiveAreaRom  /**< the pointer to PduR_ExclusiveAreaRom */
#define PduR_GetGeneralPropertiesRomOfPCPartitionConfig()                                           PduR_GeneralPropertiesRom  /**< the pointer to PduR_GeneralPropertiesRom */
#define PduR_GetLockRomOfPCPartitionConfig()                                                        PduR_LockRom  /**< the pointer to PduR_LockRom */
#define PduR_GetMmRomIndOfPCPartitionConfig()                                                       PduR_MmRomInd  /**< the pointer to PduR_MmRomInd */
#define PduR_GetMmRomOfPCPartitionConfig()                                                          PduR_MmRom  /**< the pointer to PduR_MmRom */
#define PduR_GetRmDestRomOfPCPartitionConfig()                                                      PduR_RmDestRom  /**< the pointer to PduR_RmDestRom */
#define PduR_GetRmGDestRomOfPCPartitionConfig()                                                     PduR_RmGDestRom  /**< the pointer to PduR_RmGDestRom */
#define PduR_GetRmSrcRomOfPCPartitionConfig()                                                       PduR_RmSrcRom  /**< the pointer to PduR_RmSrcRom */
#define PduR_GetRmTransmitFctPtrOfPCPartitionConfig()                                               PduR_RmTransmitFctPtr  /**< the pointer to PduR_RmTransmitFctPtr */
#define PduR_GetRxIf2DestOfPCPartitionConfig()                                                      PduR_RxIf2Dest  /**< the pointer to PduR_RxIf2Dest */
#define PduR_GetRxTp2DestOfPCPartitionConfig()                                                      PduR_RxTp2Dest  /**< the pointer to PduR_RxTp2Dest */
#define PduR_GetSizeOfBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)                         4096u  /**< the number of accomplishable value elements in PduR_BmTxBufferArrayRam */
#define PduR_GetSizeOfBmTxBufferIndRomOfPCPartitionConfig(partitionIndex)                           1u  /**< the number of accomplishable value elements in PduR_BmTxBufferIndRom */
#define PduR_GetSizeOfBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)                      1u  /**< the number of accomplishable value elements in PduR_BmTxBufferInstanceRom */
#define PduR_GetSizeOfBmTxBufferRomOfPCPartitionConfig(partitionIndex)                              1u  /**< the number of accomplishable value elements in PduR_BmTxBufferRom */
#define PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                1u  /**< the number of accomplishable value elements in PduR_DestApplicationManagerRom */
#define PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         1u  /**< the number of accomplishable value elements in PduR_ExclusiveAreaRom */
#define PduR_GetSizeOfFmFifoElementRamOfPCPartitionConfig(partitionIndex)                           1u  /**< the number of accomplishable value elements in PduR_FmFifoElementRam */
#define PduR_GetSizeOfFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)                          1u  /**< the number of accomplishable value elements in PduR_FmFifoInstanceRom */
#define PduR_GetSizeOfFmFifoRomOfPCPartitionConfig(partitionIndex)                                  1u  /**< the number of accomplishable value elements in PduR_FmFifoRom */
#define PduR_GetSizeOfGeneralPropertiesRomOfPCPartitionConfig()                                     1u  /**< the number of accomplishable value elements in PduR_GeneralPropertiesRom */
#define PduR_GetSizeOfLockRomOfPCPartitionConfig()                                                  1u  /**< the number of accomplishable value elements in PduR_LockRom */
#define PduR_GetSizeOfMmRomIndOfPCPartitionConfig()                                                 6u  /**< the number of accomplishable value elements in PduR_MmRomInd */
#define PduR_GetSizeOfMmRomOfPCPartitionConfig()                                                    6u  /**< the number of accomplishable value elements in PduR_MmRom */
#define PduR_GetSizeOfRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)                  1u  /**< the number of accomplishable value elements in PduR_RmBufferedTpPropertiesRom */
#define PduR_GetSizeOfRmDestRomOfPCPartitionConfig()                                                218u  /**< the number of accomplishable value elements in PduR_RmDestRom */
#define PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()                                               218u  /**< the number of accomplishable value elements in PduR_RmGDestRom */
#define PduR_GetSizeOfRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in PduR_RmGDestTpTxStateRam */
#define PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()                                                 218u  /**< the number of accomplishable value elements in PduR_RmSrcRom */
#define PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         3u  /**< the number of accomplishable value elements in PduR_RmTransmitFctPtr */
#define PduR_GetSizeOfRxIf2DestOfPCPartitionConfig()                                                155u  /**< the number of accomplishable value elements in PduR_RxIf2Dest */
#define PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()                                                4u  /**< the number of accomplishable value elements in PduR_RxTp2Dest */
#define PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()                                        1u  /**< the number of accomplishable value elements in PduR_SrcApplicationRom */
#define PduR_GetSizeOfTx2LoOfPCPartitionConfig()                                                    59u  /**< the number of accomplishable value elements in PduR_Tx2Lo */
#define PduR_GetSizeOfTxIf2UpOfPCPartitionConfig()                                                  57u  /**< the number of accomplishable value elements in PduR_TxIf2Up */
#define PduR_GetSizeOfTxTp2SrcOfPCPartitionConfig()                                                 2u  /**< the number of accomplishable value elements in PduR_TxTp2Src */
#define PduR_GetSrcApplicationRomOfPCPartitionConfig()                                              PduR_SrcApplicationRom  /**< the pointer to PduR_SrcApplicationRom */
#define PduR_GetTx2LoOfPCPartitionConfig()                                                          PduR_Tx2Lo  /**< the pointer to PduR_Tx2Lo */
#define PduR_GetTxIf2UpOfPCPartitionConfig()                                                        PduR_TxIf2Up  /**< the pointer to PduR_TxIf2Up */
#define PduR_GetTxTp2SrcOfPCPartitionConfig()                                                       PduR_TxTp2Src  /**< the pointer to PduR_TxTp2Src */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDuplicatedRootDataMacros  PduR Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define PduR_GetSizeOfBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)                      PduR_GetSizeOfBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in PduR_BmTxBufferInstanceRam */
#define PduR_GetSizeOfBmTxBufferRamOfPCPartitionConfig(partitionIndex)                              PduR_GetSizeOfBmTxBufferRomOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in PduR_BmTxBufferRam */
#define PduR_GetSizeOfFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)                          PduR_GetSizeOfFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in PduR_FmFifoInstanceRam */
#define PduR_GetSizeOfFmFifoRamOfPCPartitionConfig(partitionIndex)                                  PduR_GetSizeOfFmFifoRomOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in PduR_FmFifoRam */
#define PduR_GetSizeOfRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)                  PduR_GetSizeOfRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in PduR_RmBufferedTpPropertiesRam */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDataMacros  PduR Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define PduR_GetBmTxBufferArrayRam(Index, partitionIndex)                                           (PduR_GetBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)[(Index)])
#define PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)             (PduR_GetBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam)
#define PduR_IsAllocatedOfBmTxBufferRam(Index, partitionIndex)                                      ((PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].AllocatedOfBmTxBufferRam) != FALSE)
#define PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                    (PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferArrayRamWriteIdxOfBmTxBufferRam)
#define PduR_GetRxLengthOfBmTxBufferRam(Index, partitionIndex)                                      (PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].RxLengthOfBmTxBufferRam)
#define PduR_GetLockOfExclusiveAreaRom(Index)                                                       (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].LockOfExclusiveAreaRom)
#define PduR_GetUnlockOfExclusiveAreaRom(Index)                                                     (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].UnlockOfExclusiveAreaRom)
#define PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                           (PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferRomIdxOfFmFifoElementRam)
#define PduR_GetRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                               (PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex)[(Index)].RmDestRomIdxOfFmFifoElementRam)
#define PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                  (PduR_GetFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferInstanceRomIdxOfFmFifoInstanceRam)
#define PduR_GetFillLevelOfFmFifoRam(Index, partitionIndex)                                         (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FillLevelOfFmFifoRam)
#define PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                           (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamReadIdxOfFmFifoRam)
#define PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                          (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamWriteIdxOfFmFifoRam)
#define PduR_GetPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                              (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].PendingConfirmationsOfFmFifoRam)
#define PduR_GetTpTxSmStateOfFmFifoRam(Index, partitionIndex)                                       (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].TpTxSmStateOfFmFifoRam)
#define PduR_IsInitialized(partitionIndex)                                                          (((*(PduR_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define PduR_GetDestApplicationManagerRomIdxOfMmRom(Index)                                          (PduR_GetMmRomOfPCPartitionConfig()[(Index)].DestApplicationManagerRomIdxOfMmRom)
#define PduR_GetLoIfTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoIfTransmitFctPtrOfMmRom)
#define PduR_GetLoTpTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoTpTransmitFctPtrOfMmRom)
#define PduR_GetMaskedBitsOfMmRom(Index)                                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].MaskedBitsOfMmRom)
#define PduR_GetRmGDestRomEndIdxOfMmRom(Index)                                                      (PduR_GetMmRomOfPCPartitionConfig()[(Index)].RmGDestRomEndIdxOfMmRom)
#define PduR_GetRmGDestRomStartIdxOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].RmGDestRomStartIdxOfMmRom)
#define PduR_GetUpIfRxIndicationFctPtrOfMmRom(Index)                                                (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfRxIndicationFctPtrOfMmRom)
#define PduR_GetUpIfTriggerTransmitFctPtrOfMmRom(Index)                                             (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfTriggerTransmitFctPtrOfMmRom)
#define PduR_GetUpIfTxConfirmationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfTxConfirmationFctPtrOfMmRom)
#define PduR_GetUpTpCopyRxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyRxDataFctPtrOfMmRom)
#define PduR_GetUpTpCopyTxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyTxDataFctPtrOfMmRom)
#define PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpStartOfReceptionFctPtrOfMmRom)
#define PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpRxIndicationFctPtrOfMmRom)
#define PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpTxConfirmationFctPtrOfMmRom)
#define PduR_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (PduR_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)               (PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamIdxOfRmBufferedTpPropertiesRam)
#define PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(Index, partitionIndex)                       (PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)[(Index)].TpRxSmStateOfRmBufferedTpPropertiesRam)
#define PduR_GetPartitionIndexOfCslOfRmDestRom(Index)                                               (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfRmDestRom)
#define PduR_GetPduLengthHandlingStrategyOfRmDestRom(Index)                                         (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].PduLengthHandlingStrategyOfRmDestRom)
#define PduR_GetRmGDestRomIdxOfRmDestRom(Index)                                                     (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfRmDestRom)
#define PduR_GetRmSrcRomIdxOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmSrcRomIdxOfRmDestRom)
#define PduR_GetRoutingTypeOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RoutingTypeOfRmDestRom)
#define PduR_GetDestHndOfRmGDestRom(Index)                                                          (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DestHndOfRmGDestRom)
#define PduR_GetDirectionOfRmGDestRom(Index)                                                        (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DirectionOfRmGDestRom)
#define PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(Index)                                             (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].FmFifoInstanceRomIdxOfRmGDestRom)
#define PduR_GetMaskedBitsOfRmGDestRom(Index)                                                       (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MaskedBitsOfRmGDestRom)
#define PduR_GetMaxPduLengthOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MaxPduLengthOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmGDestRom(Index)                                                         (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmGDestRom)
#define PduR_GetPartitionIndexOfCslOfRmGDestRom(Index)                                              (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfRmGDestRom)
#define PduR_GetRmDestRomIdxOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].RmDestRomIdxOfRmGDestRom)
#define PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(Index)                                           (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].RmGDestTpTxStateRamIdxOfRmGDestRom)
#define PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(Index, partitionIndex)                         (PduR_GetRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)[(Index)].TpTxInstSmStateOfRmGDestTpTxStateRam)
#define PduR_GetMaskedBitsOfRmSrcRom(Index)                                                         (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].MaskedBitsOfRmSrcRom)
#define PduR_GetMmRomIdxOfRmSrcRom(Index)                                                           (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmSrcRom)
#define PduR_GetPartitionIndexOfCslOfRmSrcRom(Index)                                                (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfRmSrcRom)
#define PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(Index)                                       (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].RmBufferedTpPropertiesRomIdxOfRmSrcRom)
#define PduR_GetRmDestRomStartIdxOfRmSrcRom(Index)                                                  (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].RmDestRomStartIdxOfRmSrcRom)
#define PduR_GetSrcHndOfRmSrcRom(Index)                                                             (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].SrcHndOfRmSrcRom)
#define PduR_GetRmTransmitFctPtr(Index)                                                             (PduR_GetRmTransmitFctPtrOfPCPartitionConfig()[(Index)])
#define PduR_GetPartitionIndexOfCslOfRxIf2Dest(Index)                                               (PduR_GetRxIf2DestOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfRxIf2Dest)
#define PduR_GetPartitionIndexOfCslOfRxTp2Dest(Index)                                               (PduR_GetRxTp2DestOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfRxTp2Dest)
#define PduR_GetPartitionIndexOfCslOfTx2Lo(Index)                                                   (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfTx2Lo)
#define PduR_GetRmTransmitFctPtrIdxOfTx2Lo(Index)                                                   (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].RmTransmitFctPtrIdxOfTx2Lo)
#define PduR_GetPartitionIndexOfCslOfTxIf2Up(Index)                                                 (PduR_GetTxIf2UpOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfTxIf2Up)
#define PduR_GetRmGDestRomIdxOfTxIf2Up(Index)                                                       (PduR_GetTxIf2UpOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfTxIf2Up)
#define PduR_GetPartitionIndexOfCslOfTxTp2Src(Index)                                                (PduR_GetTxTp2SrcOfPCPartitionConfig()[(Index)].PartitionIndexOfCslOfTxTp2Src)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetBitDataMacros  PduR Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define PduR_IshasTpTxBufferedForwardingOfGeneralPropertiesRom(Index)                               (PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM_MASK == (PduR_GetMaskedBitsOfGeneralPropertiesRom(Index) & PDUR_HASTPTXBUFFEREDFORWARDINGOFGENERALPROPERTIESROM_MASK))
#define PduR_IsUpIfOfMmRom(Index)                                                                   (PDUR_UPIFOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_UPIFOFMMROM_MASK))  /**< Is the module a upper communication interface module. */
#define PduR_IsRmGDestTpTxStateRamUsedOfRmGDestRom(Index)                                           (PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM_MASK == (PduR_GetMaskedBitsOfRmGDestRom(Index) & PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM_MASK))  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmGDestTpTxStateRam */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDeduplicatedDataMacros  PduR Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define PduR_GetBmTxBufferRomIdxOfBmTxBufferIndRom(Index, partitionIndex)                           ((PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_BmTxBufferRom */
#define PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(Index, partitionIndex)                      ((PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_BmTxBufferRom */
#define PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(Index, partitionIndex)                      ((PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRomType)((((PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRomType)(Index)) + 4096u)))  /**< the end index of the 1:n relation pointing to PduR_BmTxBufferArrayRam */
#define PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(Index, partitionIndex)                      ((PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType)((((PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType)(Index)) + 4096u)))  /**< the number of relations pointing to PduR_BmTxBufferArrayRam */
#define PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(Index, partitionIndex)                    ((PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_BmTxBufferArrayRam */
#define PduR_GetBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(Index, partitionIndex)                   ((PduR_BmTxBufferInstanceRomEndIdxOfBmTxBufferRomType)((((PduR_BmTxBufferInstanceRomEndIdxOfBmTxBufferRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_BmTxBufferInstanceRom */
#define PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(Index, partitionIndex)                 ((PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_BmTxBufferInstanceRom */
#define PduR_GetConfigId(partitionIndex)                                                            PduR_GetConfigIdOfPCPartitionConfig(partitionIndex)
#define PduR_GetMmRomIndEndIdxOfDestApplicationManagerRom(Index)                                    ((PduR_MmRomIndEndIdxOfDestApplicationManagerRomType)((((PduR_MmRomIndEndIdxOfDestApplicationManagerRomType)(Index)) + 6u)))  /**< the end index of the 0:n relation pointing to PduR_MmRomInd */
#define PduR_GetMmRomIndStartIdxOfDestApplicationManagerRom(Index)                                  ((PduR_MmRomIndStartIdxOfDestApplicationManagerRomType)((Index)))  /**< the start index of the 0:n relation pointing to PduR_MmRomInd */
#define PduR_IsMmRomIndUsedOfDestApplicationManagerRom(Index)                                       (((boolean)(PduR_GetMmRomIndStartIdxOfDestApplicationManagerRom(Index) != PDUR_NO_MMROMINDSTARTIDXOFDESTAPPLICATIONMANAGERROM)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to PduR_MmRomInd */
#define PduR_GetSrcApplicationRomEndIdxOfDestApplicationManagerRom(Index)                           ((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)((((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_GetSrcApplicationRomStartIdxOfDestApplicationManagerRom(Index)                         ((PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(Index, partitionIndex)                              ((PduR_FmFifoRomIdxOfFmFifoInstanceRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_FmFifoRom */
#define PduR_GetBmTxBufferIndRomEndIdxOfFmFifoRom(Index, partitionIndex)                            ((PduR_BmTxBufferIndRomEndIdxOfFmFifoRomType)((((PduR_BmTxBufferIndRomEndIdxOfFmFifoRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_BmTxBufferIndRom */
#define PduR_GetBmTxBufferIndRomLengthOfFmFifoRom(Index, partitionIndex)                            ((PduR_BmTxBufferIndRomLengthOfFmFifoRomType)((((PduR_BmTxBufferIndRomLengthOfFmFifoRomType)(Index)) + 1u)))  /**< the number of relations pointing to PduR_BmTxBufferIndRom */
#define PduR_GetBmTxBufferIndRomStartIdxOfFmFifoRom(Index, partitionIndex)                          ((PduR_BmTxBufferIndRomStartIdxOfFmFifoRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_BmTxBufferIndRom */
#define PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(Index, partitionIndex)                            ((PduR_FmFifoElementRamEndIdxOfFmFifoRomType)((((PduR_FmFifoElementRamEndIdxOfFmFifoRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_FmFifoElementRam */
#define PduR_GetFmFifoElementRamLengthOfFmFifoRom(Index, partitionIndex)                            ((PduR_FmFifoElementRamLengthOfFmFifoRomType)((((PduR_FmFifoElementRamLengthOfFmFifoRomType)(Index)) + 1u)))  /**< the number of relations pointing to PduR_FmFifoElementRam */
#define PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(Index, partitionIndex)                          ((PduR_FmFifoElementRamStartIdxOfFmFifoRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_FmFifoElementRam */
#define PduR_GetMaskedBitsOfGeneralPropertiesRom(Index)                                             ((PduR_MaskedBitsOfGeneralPropertiesRomType)((((PduR_MaskedBitsOfGeneralPropertiesRomType)(Index)) + 0x03u)))  /**< contains bitcoded the boolean data of PduR_hasIfRoutingOfGeneralPropertiesRom, PduR_hasTpTxBufferedForwardingOfGeneralPropertiesRom */
#define PduR_IshasIfRoutingOfGeneralPropertiesRom(Index)                                            PduR_IshasTpTxBufferedForwardingOfGeneralPropertiesRom(Index)
#define PduR_GetExclusiveAreaRomIdxOfLockRom(Index)                                                 ((PduR_ExclusiveAreaRomIdxOfLockRomType)((Index)))  /**< the index of the 0:1 relation pointing to PduR_ExclusiveAreaRom */
#define PduR_IsExclusiveAreaRomUsedOfLockRom(Index)                                                 (((boolean)(PduR_GetExclusiveAreaRomIdxOfLockRom(Index) != PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_ExclusiveAreaRom */
#define PduR_IsLoIfOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) >= 0x0Du)) != FALSE)  /**< Is the module a lower communication interface module. */
#define PduR_IsLoTpOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x0Cu)) != FALSE)  /**< Is the module a lower transport protocol module. */
#define PduR_IsRmGDestRomUsedOfMmRom(Index)                                                         (((boolean)(PduR_GetRmGDestRomStartIdxOfMmRom(Index) != PDUR_NO_RMGDESTROMSTARTIDXOFMMROM)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to PduR_RmGDestRom */
#define PduR_IsUpTpOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x05u)) != FALSE)  /**< Is the module a upper transport protocol module. */
#define PduR_GetMmRomInd(Index)                                                                     ((PduR_MmRomIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to PduR_MmRom */
#define PduR_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   ((PduR_PCPartitionConfigIdxOfPartitionIdentifiersType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_PCPartitionConfig */
#define PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(Index, partitionIndex)                      ((PduR_FmFifoRomIdxOfRmBufferedTpPropertiesRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_FmFifoRom */
#define PduR_GetQueuedDestCntOfRmBufferedTpPropertiesRom(Index, partitionIndex)                     ((PduR_QueuedDestCntOfRmBufferedTpPropertiesRomType)((((PduR_QueuedDestCntOfRmBufferedTpPropertiesRomType)(Index)) + 1u)))  /**< Number of queued TP destinations. */
#define PduR_GetTpThresholdOfRmBufferedTpPropertiesRom(Index, partitionIndex)                       ((PduR_TpThresholdOfRmBufferedTpPropertiesRomType)((((PduR_TpThresholdOfRmBufferedTpPropertiesRomType)(Index)) + 4095u)))  /**< TP threshold value. */
#define PduR_IsFmFifoInstanceRomUsedOfRmGDestRom(Index)                                             PduR_IsRmGDestTpTxStateRamUsedOfRmGDestRom(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_FmFifoInstanceRom */
#define PduR_GetLockRomIdxOfRmGDestRom(Index)                                                       PduR_GetPartitionIndexOfCslOfRmGDestRom(Index)  /**< the index of the 1:1 relation pointing to PduR_LockRom */
#define PduR_GetPduRDestPduProcessingOfRmGDestRom(Index)                                            ((PduR_PduRDestPduProcessingOfRmGDestRomType)((PduR_GetPartitionIndexOfCslOfRmGDestRom(Index) + 1u)))  /**< Is Processing Type of destination PDU. */
#define PduR_GetTxIf2UpIdxOfRmGDestRom(Index)                                                       PduR_GetPartitionIndexOfCslOfRmGDestRom(Index)  /**< TxIf2Up index. */
#define PduR_GetLockRomIdxOfRmSrcRom(Index)                                                         PduR_GetPartitionIndexOfCslOfRmSrcRom(Index)  /**< the index of the 1:1 relation pointing to PduR_LockRom */
#define PduR_IsRmBufferedTpPropertiesRomUsedOfRmSrcRom(Index)                                       (((boolean)(PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(Index) != PDUR_NO_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmBufferedTpPropertiesRom */
#define PduR_GetRmDestRomEndIdxOfRmSrcRom(Index)                                                    ((PduR_RmDestRomEndIdxOfRmSrcRomType)((PduR_GetRmDestRomStartIdxOfRmSrcRom(Index) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_RmDestRom */
#define PduR_GetRmDestRomLengthOfRmSrcRom(Index)                                                    ((PduR_RmDestRomLengthOfRmSrcRomType)((PduR_GetPartitionIndexOfCslOfRmSrcRom(Index) + 1u)))  /**< the number of relations pointing to PduR_RmDestRom */
#define PduR_IsTriggerTransmitSupportedOfRmSrcRom(Index)                                            (((boolean)(PduR_GetMaskedBitsOfRmSrcRom(Index) == 0x02u)) != FALSE)
#define PduR_IsTxConfirmationSupportedOfRmSrcRom(Index)                                             (((boolean)(PduR_GetMaskedBitsOfRmSrcRom(Index) == 0x01u)) != FALSE)
#define PduR_GetRmSrcRomIdxOfRxIf2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxIf2DestType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetRmSrcRomIdxOfRxTp2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxTp2DestType)((((PduR_RmSrcRomIdxOfRxTp2DestType)(Index)) + 155u)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetSizeOfBmTxBufferArrayRam(partitionIndex)                                            PduR_GetSizeOfBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfBmTxBufferIndRom(partitionIndex)                                              PduR_GetSizeOfBmTxBufferIndRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfBmTxBufferInstanceRam(partitionIndex)                                         PduR_GetSizeOfBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfBmTxBufferInstanceRom(partitionIndex)                                         PduR_GetSizeOfBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfBmTxBufferRam(partitionIndex)                                                 PduR_GetSizeOfBmTxBufferRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfBmTxBufferRom(partitionIndex)                                                 PduR_GetSizeOfBmTxBufferRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfDestApplicationManagerRom()                                                   PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()
#define PduR_GetSizeOfExclusiveAreaRom()                                                            PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()
#define PduR_GetSizeOfFmFifoElementRam(partitionIndex)                                              PduR_GetSizeOfFmFifoElementRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfFmFifoInstanceRam(partitionIndex)                                             PduR_GetSizeOfFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfFmFifoInstanceRom(partitionIndex)                                             PduR_GetSizeOfFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfFmFifoRam(partitionIndex)                                                     PduR_GetSizeOfFmFifoRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfFmFifoRom(partitionIndex)                                                     PduR_GetSizeOfFmFifoRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfGeneralPropertiesRom()                                                        PduR_GetSizeOfGeneralPropertiesRomOfPCPartitionConfig()
#define PduR_GetSizeOfLockRom()                                                                     PduR_GetSizeOfLockRomOfPCPartitionConfig()
#define PduR_GetSizeOfMmRom()                                                                       PduR_GetSizeOfMmRomOfPCPartitionConfig()
#define PduR_GetSizeOfMmRomInd()                                                                    PduR_GetSizeOfMmRomIndOfPCPartitionConfig()
#define PduR_GetSizeOfPartitionIdentifiers()                                                        PduR_GetSizeOfPartitionIdentifiersOfPCConfig()
#define PduR_GetSizeOfRmBufferedTpPropertiesRam(partitionIndex)                                     PduR_GetSizeOfRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfRmBufferedTpPropertiesRom(partitionIndex)                                     PduR_GetSizeOfRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfRmDestRom()                                                                   PduR_GetSizeOfRmDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmGDestRom()                                                                  PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmGDestTpTxStateRam(partitionIndex)                                           PduR_GetSizeOfRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfRmSrcRom()                                                                    PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmTransmitFctPtr()                                                            PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()
#define PduR_GetSizeOfRxIf2Dest()                                                                   PduR_GetSizeOfRxIf2DestOfPCPartitionConfig()
#define PduR_GetSizeOfRxTp2Dest()                                                                   PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()
#define PduR_GetSizeOfSrcApplicationRom()                                                           PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()
#define PduR_GetSizeOfTx2Lo()                                                                       PduR_GetSizeOfTx2LoOfPCPartitionConfig()
#define PduR_GetSizeOfTxIf2Up()                                                                     PduR_GetSizeOfTxIf2UpOfPCPartitionConfig()
#define PduR_GetSizeOfTxTp2Src()                                                                    PduR_GetSizeOfTxTp2SrcOfPCPartitionConfig()
#define PduR_GetPartitionIndexOfCslOfSrcApplicationRom(Index)                                       ((PduR_PartitionIndexOfCslOfSrcApplicationRomType)((Index)))
#define PduR_GetRmSrcRomIdxOfTx2Lo(Index)                                                           ((PduR_RmSrcRomIdxOfTx2LoType)((((PduR_RmSrcRomIdxOfTx2LoType)(Index)) + 159u)))  /**< the index of the 0:1 relation pointing to PduR_RmSrcRom */
#define PduR_IsRmSrcRomUsedOfTx2Lo(Index)                                                           (((boolean)(PduR_GetRmSrcRomIdxOfTx2Lo(Index) != PDUR_NO_RMSRCROMIDXOFTX2LO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmSrcRom */
#define PduR_IsTxConfirmationUsedOfTxIf2Up(Index)                                                   (((boolean)(PduR_GetRmGDestRomIdxOfTxIf2Up(Index) != 53u)) != FALSE)  /**< True, if any of the source PduRDestPdus uses a TxConfirmation. */
#define PduR_GetRmGDestRomIdxOfTxTp2Src(Index)                                                      ((PduR_RmGDestRomIdxOfTxTp2SrcType)((((PduR_RmGDestRomIdxOfTxTp2SrcType)(Index)) + 54u)))  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSetDataMacros  PduR Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define PduR_SetBmTxBufferArrayRam(Index, Value, partitionIndex)                                    PduR_GetBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)      PduR_GetBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam = (Value)
#define PduR_SetAllocatedOfBmTxBufferRam(Index, Value, partitionIndex)                              PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].AllocatedOfBmTxBufferRam = (Value)
#define PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)             PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferArrayRamWriteIdxOfBmTxBufferRam = (Value)
#define PduR_SetRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                               PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex)[(Index)].RxLengthOfBmTxBufferRam = (Value)
#define PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                    PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferRomIdxOfFmFifoElementRam = (Value)
#define PduR_SetRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                        PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex)[(Index)].RmDestRomIdxOfFmFifoElementRam = (Value)
#define PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)           PduR_GetFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)[(Index)].BmTxBufferInstanceRomIdxOfFmFifoInstanceRam = (Value)
#define PduR_SetFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                  PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FillLevelOfFmFifoRam = (Value)
#define PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                    PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamReadIdxOfFmFifoRam = (Value)
#define PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                   PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamWriteIdxOfFmFifoRam = (Value)
#define PduR_SetPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                       PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].PendingConfirmationsOfFmFifoRam = (Value)
#define PduR_SetTpTxSmStateOfFmFifoRam(Index, Value, partitionIndex)                                PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex)[(Index)].TpTxSmStateOfFmFifoRam = (Value)
#define PduR_SetInitialized(Value, partitionIndex)                                                  (*(PduR_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)        PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)[(Index)].FmFifoElementRamIdxOfRmBufferedTpPropertiesRam = (Value)
#define PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)                PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)[(Index)].TpRxSmStateOfRmBufferedTpPropertiesRam = (Value)
#define PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(Index, Value, partitionIndex)                  PduR_GetRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)[(Index)].TpTxInstSmStateOfRmGDestTpTxStateRam = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetAddressOfDataMacros  PduR Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define PduR_GetAddrBmTxBufferArrayRam(Index, partitionIndex)                                       (&PduR_GetBmTxBufferArrayRam(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCHasMacros  PduR Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasBmTxBufferArrayRam(partitionIndex)                                                  (PduR_GetBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferIndRom(partitionIndex)                                                    (PduR_GetBmTxBufferIndRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferRomIdxOfBmTxBufferIndRom(partitionIndex)                                  (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRam(partitionIndex)                                               (PduR_GetBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(partitionIndex)                    (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRom(partitionIndex)                                               (PduR_GetBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferRomIdxOfBmTxBufferInstanceRom(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasBmTxBufferRam(partitionIndex)                                                       (PduR_GetBmTxBufferRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasAllocatedOfBmTxBufferRam(partitionIndex)                                            (TRUE != FALSE)
#define PduR_HasBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(partitionIndex)                           (TRUE != FALSE)
#define PduR_HasRxLengthOfBmTxBufferRam(partitionIndex)                                             (TRUE != FALSE)
#define PduR_HasBmTxBufferRom(partitionIndex)                                                       (PduR_GetBmTxBufferRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferArrayRamEndIdxOfBmTxBufferRom(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasBmTxBufferArrayRamLengthOfBmTxBufferRom(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasBmTxBufferArrayRamStartIdxOfBmTxBufferRom(partitionIndex)                           (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(partitionIndex)                          (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(partitionIndex)                        (TRUE != FALSE)
#define PduR_HasConfigId(partitionIndex)                                                            (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRom()                                                         (TRUE != FALSE)
#define PduR_HasMmRomIndEndIdxOfDestApplicationManagerRom()                                         (TRUE != FALSE)
#define PduR_HasMmRomIndStartIdxOfDestApplicationManagerRom()                                       (TRUE != FALSE)
#define PduR_HasMmRomIndUsedOfDestApplicationManagerRom()                                           (TRUE != FALSE)
#define PduR_HasSrcApplicationRomEndIdxOfDestApplicationManagerRom()                                (TRUE != FALSE)
#define PduR_HasSrcApplicationRomStartIdxOfDestApplicationManagerRom()                              (TRUE != FALSE)
#define PduR_HasExclusiveAreaRom()                                                                  (TRUE != FALSE)
#define PduR_HasLockOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasUnlockOfExclusiveAreaRom()                                                          (TRUE != FALSE)
#define PduR_HasFmFifoElementRam(partitionIndex)                                                    (PduR_GetFmFifoElementRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferRomIdxOfFmFifoElementRam(partitionIndex)                                  (TRUE != FALSE)
#define PduR_HasRmDestRomIdxOfFmFifoElementRam(partitionIndex)                                      (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRam(partitionIndex)                                                   (PduR_GetFmFifoInstanceRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(partitionIndex)                         (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRom(partitionIndex)                                                   (PduR_GetFmFifoInstanceRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasFmFifoRomIdxOfFmFifoInstanceRom(partitionIndex)                                     (TRUE != FALSE)
#define PduR_HasFmFifoRam(partitionIndex)                                                           (PduR_GetFmFifoRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasFillLevelOfFmFifoRam(partitionIndex)                                                (TRUE != FALSE)
#define PduR_HasFmFifoElementRamReadIdxOfFmFifoRam(partitionIndex)                                  (TRUE != FALSE)
#define PduR_HasFmFifoElementRamWriteIdxOfFmFifoRam(partitionIndex)                                 (TRUE != FALSE)
#define PduR_HasPendingConfirmationsOfFmFifoRam(partitionIndex)                                     (TRUE != FALSE)
#define PduR_HasTpTxSmStateOfFmFifoRam(partitionIndex)                                              (TRUE != FALSE)
#define PduR_HasFmFifoRom(partitionIndex)                                                           (PduR_GetFmFifoRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasBmTxBufferIndRomEndIdxOfFmFifoRom(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasBmTxBufferIndRomLengthOfFmFifoRom(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasBmTxBufferIndRomStartIdxOfFmFifoRom(partitionIndex)                                 (TRUE != FALSE)
#define PduR_HasFmFifoElementRamEndIdxOfFmFifoRom(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasFmFifoElementRamLengthOfFmFifoRom(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasFmFifoElementRamStartIdxOfFmFifoRom(partitionIndex)                                 (TRUE != FALSE)
#define PduR_HasGeneralPropertiesRom()                                                              (TRUE != FALSE)
#define PduR_HasMaskedBitsOfGeneralPropertiesRom()                                                  (TRUE != FALSE)
#define PduR_HashasIfRoutingOfGeneralPropertiesRom()                                                (TRUE != FALSE)
#define PduR_HashasTpTxBufferedForwardingOfGeneralPropertiesRom()                                   (TRUE != FALSE)
#define PduR_HasInitialized(partitionIndex)                                                         (PduR_GetInitializedOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasLockRom()                                                                           (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomIdxOfLockRom()                                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomUsedOfLockRom()                                                     (TRUE != FALSE)
#define PduR_HasMmRom()                                                                             (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRomIdxOfMmRom()                                               (TRUE != FALSE)
#define PduR_HasLoIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoIfTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasLoTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoTpTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasMaskedBitsOfMmRom()                                                                 (TRUE != FALSE)
#define PduR_HasRmGDestRomEndIdxOfMmRom()                                                           (TRUE != FALSE)
#define PduR_HasRmGDestRomStartIdxOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasRmGDestRomUsedOfMmRom()                                                             (TRUE != FALSE)
#define PduR_HasUpIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpIfRxIndicationFctPtrOfMmRom()                                                     (TRUE != FALSE)
#define PduR_HasUpIfTriggerTransmitFctPtrOfMmRom()                                                  (TRUE != FALSE)
#define PduR_HasUpIfTxConfirmationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpCopyRxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpCopyTxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpTpStartOfReceptionFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasUpTpTpRxIndicationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpTpTxConfirmationFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasMmRomInd()                                                                          (TRUE != FALSE)
#define PduR_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define PduR_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRam(partitionIndex)                                           (PduR_GetRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(partitionIndex)                      (TRUE != FALSE)
#define PduR_HasTpRxSmStateOfRmBufferedTpPropertiesRam(partitionIndex)                              (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRom(partitionIndex)                                           (PduR_GetRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasFmFifoRomIdxOfRmBufferedTpPropertiesRom(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasQueuedDestCntOfRmBufferedTpPropertiesRom(partitionIndex)                            (TRUE != FALSE)
#define PduR_HasTpThresholdOfRmBufferedTpPropertiesRom(partitionIndex)                              (TRUE != FALSE)
#define PduR_HasRmDestRom()                                                                         (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfRmDestRom()                                                    (TRUE != FALSE)
#define PduR_HasPduLengthHandlingStrategyOfRmDestRom()                                              (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfRmDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRoutingTypeOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmGDestRom()                                                                        (TRUE != FALSE)
#define PduR_HasDestHndOfRmGDestRom()                                                               (TRUE != FALSE)
#define PduR_HasDirectionOfRmGDestRom()                                                             (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRomIdxOfRmGDestRom()                                                  (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRomUsedOfRmGDestRom()                                                 (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasMaskedBitsOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasMaxPduLengthOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmGDestRom()                                                              (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfRmGDestRom()                                                   (TRUE != FALSE)
#define PduR_HasPduRDestPduProcessingOfRmGDestRom()                                                 (TRUE != FALSE)
#define PduR_HasRmDestRomIdxOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmGDestTpTxStateRamIdxOfRmGDestRom()                                                (TRUE != FALSE)
#define PduR_HasRmGDestTpTxStateRamUsedOfRmGDestRom()                                               (TRUE != FALSE)
#define PduR_HasTxIf2UpIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmGDestTpTxStateRam(partitionIndex)                                                 (PduR_GetRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define PduR_HasTpTxInstSmStateOfRmGDestTpTxStateRam(partitionIndex)                                (TRUE != FALSE)
#define PduR_HasRmSrcRom()                                                                          (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMaskedBitsOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmSrcRom()                                                                (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfRmSrcRom()                                                     (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRomIdxOfRmSrcRom()                                            (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRomUsedOfRmSrcRom()                                           (TRUE != FALSE)
#define PduR_HasRmDestRomEndIdxOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomLengthOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomStartIdxOfRmSrcRom()                                                       (TRUE != FALSE)
#define PduR_HasSrcHndOfRmSrcRom()                                                                  (TRUE != FALSE)
#define PduR_HasTriggerTransmitSupportedOfRmSrcRom()                                                (TRUE != FALSE)
#define PduR_HasTxConfirmationSupportedOfRmSrcRom()                                                 (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtr()                                                                  (TRUE != FALSE)
#define PduR_HasRxIf2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfRxIf2Dest()                                                    (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxIf2Dest()                                                            (TRUE != FALSE)
#define PduR_HasRxTp2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfRxTp2Dest()                                                    (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxTp2Dest()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferArrayRam(partitionIndex)                                            (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferIndRom(partitionIndex)                                              (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferInstanceRam(partitionIndex)                                         (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferInstanceRom(partitionIndex)                                         (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferRam(partitionIndex)                                                 (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferRom(partitionIndex)                                                 (TRUE != FALSE)
#define PduR_HasSizeOfDestApplicationManagerRom()                                                   (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoElementRam(partitionIndex)                                              (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoInstanceRam(partitionIndex)                                             (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoInstanceRom(partitionIndex)                                             (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoRam(partitionIndex)                                                     (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoRom(partitionIndex)                                                     (TRUE != FALSE)
#define PduR_HasSizeOfGeneralPropertiesRom()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfLockRom()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfMmRomInd()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfRmBufferedTpPropertiesRam(partitionIndex)                                     (TRUE != FALSE)
#define PduR_HasSizeOfRmBufferedTpPropertiesRom(partitionIndex)                                     (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRom()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRom()                                                                  (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestTpTxStateRam(partitionIndex)                                           (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRom()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtr()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRom()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2Up()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                                                    (TRUE != FALSE)
#define PduR_HasSrcApplicationRom()                                                                 (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfSrcApplicationRom()                                            (TRUE != FALSE)
#define PduR_HasTx2Lo()                                                                             (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfTx2Lo()                                                        (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfTx2Lo()                                                                (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfTx2Lo()                                                               (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrIdxOfTx2Lo()                                                        (TRUE != FALSE)
#define PduR_HasTxIf2Up()                                                                           (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfTxIf2Up()                                                      (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxIf2Up()                                                            (TRUE != FALSE)
#define PduR_HasTxConfirmationUsedOfTxIf2Up()                                                       (TRUE != FALSE)
#define PduR_HasTxTp2Src()                                                                          (TRUE != FALSE)
#define PduR_HasPartitionIndexOfCslOfTxTp2Src()                                                     (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxTp2Src()                                                           (TRUE != FALSE)
#define PduR_HasPCConfig()                                                                          (TRUE != FALSE)
#define PduR_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define PduR_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfig()                                                                 (TRUE != FALSE)
#define PduR_HasBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define PduR_HasBmTxBufferIndRomOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define PduR_HasBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define PduR_HasBmTxBufferRamOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define PduR_HasBmTxBufferRomOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define PduR_HasConfigIdOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRomOfPCPartitionConfig()                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasFmFifoElementRamOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define PduR_HasFmFifoRamOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define PduR_HasFmFifoRomOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define PduR_HasGeneralPropertiesRomOfPCPartitionConfig()                                           (TRUE != FALSE)
#define PduR_HasInitializedOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define PduR_HasLockRomOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define PduR_HasMmRomIndOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define PduR_HasMmRomOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define PduR_HasRmDestRomOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRmGDestRomOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define PduR_HasRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define PduR_HasRmSrcRomOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasRxIf2DestOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferArrayRamOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferIndRomOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferInstanceRamOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferInstanceRomOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferRamOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define PduR_HasSizeOfBmTxBufferRomOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define PduR_HasSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoElementRamOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoInstanceRamOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoInstanceRomOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoRamOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define PduR_HasSizeOfFmFifoRomOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define PduR_HasSizeOfGeneralPropertiesRomOfPCPartitionConfig()                                     (TRUE != FALSE)
#define PduR_HasSizeOfLockRomOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfMmRomIndOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSizeOfMmRomOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmBufferedTpPropertiesRamOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define PduR_HasSizeOfRmBufferedTpPropertiesRomOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRomOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestTpTxStateRamOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRomOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2DestOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRomOfPCPartitionConfig()                                        (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2UpOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSrcApplicationRomOfPCPartitionConfig()                                              (TRUE != FALSE)
#define PduR_HasTx2LoOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasTxIf2UpOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCPartitionConfig()                                                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIncrementDataMacros  PduR Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define PduR_IncBmTxBufferArrayRam(Index, partitionIndex)                                           PduR_GetBmTxBufferArrayRam(((Index)), (partitionIndex))++
#define PduR_IncBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)             PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(((Index)), (partitionIndex))++
#define PduR_IncBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                    PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(((Index)), (partitionIndex))++
#define PduR_IncRxLengthOfBmTxBufferRam(Index, partitionIndex)                                      PduR_GetRxLengthOfBmTxBufferRam(((Index)), (partitionIndex))++
#define PduR_IncBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                           PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(((Index)), (partitionIndex))++
#define PduR_IncRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                               PduR_GetRmDestRomIdxOfFmFifoElementRam(((Index)), (partitionIndex))++
#define PduR_IncBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                  PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(((Index)), (partitionIndex))++
#define PduR_IncFillLevelOfFmFifoRam(Index, partitionIndex)                                         PduR_GetFillLevelOfFmFifoRam(((Index)), (partitionIndex))++
#define PduR_IncFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                           PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(((Index)), (partitionIndex))++
#define PduR_IncFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                          PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(((Index)), (partitionIndex))++
#define PduR_IncPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                              PduR_GetPendingConfirmationsOfFmFifoRam(((Index)), (partitionIndex))++
#define PduR_IncFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)               PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCDecrementDataMacros  PduR Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define PduR_DecBmTxBufferArrayRam(Index, partitionIndex)                                           PduR_GetBmTxBufferArrayRam(((Index)), (partitionIndex))--
#define PduR_DecBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)             PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(((Index)), (partitionIndex))--
#define PduR_DecBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                    PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(((Index)), (partitionIndex))--
#define PduR_DecRxLengthOfBmTxBufferRam(Index, partitionIndex)                                      PduR_GetRxLengthOfBmTxBufferRam(((Index)), (partitionIndex))--
#define PduR_DecBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                           PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(((Index)), (partitionIndex))--
#define PduR_DecRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                               PduR_GetRmDestRomIdxOfFmFifoElementRam(((Index)), (partitionIndex))--
#define PduR_DecBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                  PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(((Index)), (partitionIndex))--
#define PduR_DecFillLevelOfFmFifoRam(Index, partitionIndex)                                         PduR_GetFillLevelOfFmFifoRam(((Index)), (partitionIndex))--
#define PduR_DecFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                           PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(((Index)), (partitionIndex))--
#define PduR_DecFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                          PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(((Index)), (partitionIndex))--
#define PduR_DecPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                              PduR_GetPendingConfirmationsOfFmFifoRam(((Index)), (partitionIndex))--
#define PduR_DecFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)               PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCAddDataMacros  PduR Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define PduR_AddBmTxBufferArrayRam(Index, Value, partitionIndex)                                    PduR_SetBmTxBufferArrayRam(Index, (PduR_GetBmTxBufferArrayRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)      PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)             PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                               PduR_SetRxLengthOfBmTxBufferRam(Index, (PduR_GetRxLengthOfBmTxBufferRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                    PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(Index, (PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                        PduR_SetRmDestRomIdxOfFmFifoElementRam(Index, (PduR_GetRmDestRomIdxOfFmFifoElementRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)           PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, (PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                  PduR_SetFillLevelOfFmFifoRam(Index, (PduR_GetFillLevelOfFmFifoRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                    PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(Index, (PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                   PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(Index, (PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                       PduR_SetPendingConfirmationsOfFmFifoRam(Index, (PduR_GetPendingConfirmationsOfFmFifoRam(((Index)), (partitionIndex)) + Value), partitionIndex)
#define PduR_AddFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)        PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, (PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSubstractDataMacros  PduR Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define PduR_SubBmTxBufferArrayRam(Index, Value, partitionIndex)                                    PduR_SetBmTxBufferArrayRam(Index, (PduR_GetBmTxBufferArrayRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)      PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, (PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)             PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, (PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                               PduR_SetRxLengthOfBmTxBufferRam(Index, (PduR_GetRxLengthOfBmTxBufferRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                    PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(Index, (PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                        PduR_SetRmDestRomIdxOfFmFifoElementRam(Index, (PduR_GetRmDestRomIdxOfFmFifoElementRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)           PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, (PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                  PduR_SetFillLevelOfFmFifoRam(Index, (PduR_GetFillLevelOfFmFifoRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                    PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(Index, (PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                   PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(Index, (PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                       PduR_SetPendingConfirmationsOfFmFifoRam(Index, (PduR_GetPendingConfirmationsOfFmFifoRam(((Index)), (partitionIndex)) - Value), partitionIndex)
#define PduR_SubFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)        PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, (PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(((Index)), (partitionIndex)) - Value), partitionIndex)
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


#define PduR_IsPreInitialized()                     (PduR_PreInitialized != FALSE)
#define PduR_SetPreInitialized(Value)               (PduR_IsPreInitialized()) = (Value)

#define CommonSharedMemory  0u /* Dummy symbolic name value for the shared memory memory section */

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef P2FUNC(void, PDUR_CODE, PduR_LockFunctionType) (void);    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Communication Interface APIs */

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Transport Protocol APIs */
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);    /* PRQA S 1336 */ /* MD_PduR_1336 */


#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif
#if (PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelReceiveFctPtrType) (PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif
#if (PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCIterableTypes  PduR Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate PduR_BmTxBufferArrayRam */
typedef uint32_least PduR_BmTxBufferArrayRamIterType;

/**   \brief  type used to iterate PduR_BmTxBufferIndRom */
typedef uint32_least PduR_BmTxBufferIndRomIterType;

/**   \brief  type used to iterate PduR_BmTxBufferInstanceRom */
typedef uint8_least PduR_BmTxBufferInstanceRomIterType;

/**   \brief  type used to iterate PduR_BmTxBufferRom */
typedef uint8_least PduR_BmTxBufferRomIterType;

/**   \brief  type used to iterate PduR_DestApplicationManagerRom */
typedef uint8_least PduR_DestApplicationManagerRomIterType;

/**   \brief  type used to iterate PduR_ExclusiveAreaRom */
typedef uint8_least PduR_ExclusiveAreaRomIterType;

/**   \brief  type used to iterate PduR_FmFifoElementRam */
typedef uint8_least PduR_FmFifoElementRamIterType;

/**   \brief  type used to iterate PduR_FmFifoInstanceRom */
typedef uint8_least PduR_FmFifoInstanceRomIterType;

/**   \brief  type used to iterate PduR_FmFifoRom */
typedef uint8_least PduR_FmFifoRomIterType;

/**   \brief  type used to iterate PduR_GeneralPropertiesRom */
typedef uint8_least PduR_GeneralPropertiesRomIterType;

/**   \brief  type used to iterate PduR_LockRom */
typedef uint8_least PduR_LockRomIterType;

/**   \brief  type used to iterate PduR_MmRom */
typedef uint8_least PduR_MmRomIterType;

/**   \brief  type used to iterate PduR_MmRomInd */
typedef uint8_least PduR_MmRomIndIterType;

/**   \brief  type used to iterate PduR_PartitionIdentifiers */
typedef uint8_least PduR_PartitionIdentifiersIterType;

/**   \brief  type used to iterate PduR_RmBufferedTpPropertiesRom */
typedef uint8_least PduR_RmBufferedTpPropertiesRomIterType;

/**   \brief  type used to iterate PduR_RmDestRom */
typedef uint8_least PduR_RmDestRomIterType;

/**   \brief  type used to iterate PduR_RmGDestRom */
typedef uint8_least PduR_RmGDestRomIterType;

/**   \brief  type used to iterate PduR_RmGDestTpTxStateRam */
typedef uint8_least PduR_RmGDestTpTxStateRamIterType;

/**   \brief  type used to iterate PduR_RmSrcRom */
typedef uint8_least PduR_RmSrcRomIterType;

/**   \brief  type used to iterate PduR_RmTransmitFctPtr */
typedef uint8_least PduR_RmTransmitFctPtrIterType;

/**   \brief  type used to iterate PduR_RxIf2Dest */
typedef uint8_least PduR_RxIf2DestIterType;

/**   \brief  type used to iterate PduR_RxTp2Dest */
typedef uint8_least PduR_RxTp2DestIterType;

/**   \brief  type used to iterate PduR_SrcApplicationRom */
typedef uint8_least PduR_SrcApplicationRomIterType;

/**   \brief  type used to iterate PduR_Tx2Lo */
typedef uint8_least PduR_Tx2LoIterType;

/**   \brief  type used to iterate PduR_TxIf2Up */
typedef uint8_least PduR_TxIf2UpIterType;

/**   \brief  type used to iterate PduR_TxTp2Src */
typedef uint8_least PduR_TxTp2SrcIterType;

/**   \brief  type used to iterate PduR_PCPartitionConfig */
typedef uint8_least PduR_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIterableTypesWithSizeRelations  PduR Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate PduR_BmTxBufferInstanceRam */
typedef PduR_BmTxBufferInstanceRomIterType PduR_BmTxBufferInstanceRamIterType;

/**   \brief  type used to iterate PduR_BmTxBufferRam */
typedef PduR_BmTxBufferRomIterType PduR_BmTxBufferRamIterType;

/**   \brief  type used to iterate PduR_FmFifoInstanceRam */
typedef PduR_FmFifoInstanceRomIterType PduR_FmFifoInstanceRamIterType;

/**   \brief  type used to iterate PduR_FmFifoRam */
typedef PduR_FmFifoRomIterType PduR_FmFifoRamIterType;

/**   \brief  type used to iterate PduR_RmBufferedTpPropertiesRam */
typedef PduR_RmBufferedTpPropertiesRomIterType PduR_RmBufferedTpPropertiesRamIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCValueTypes  PduR Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for PduR_BmTxBufferArrayRam */
typedef uint8 PduR_BmTxBufferArrayRamType;

/**   \brief  value based type definition for PduR_BmTxBufferRomIdxOfBmTxBufferIndRom */
typedef uint8 PduR_BmTxBufferRomIdxOfBmTxBufferIndRomType;

/**   \brief  value based type definition for PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam */
typedef uint32 PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType;

/**   \brief  value based type definition for PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRom */
typedef uint8 PduR_BmTxBufferRomIdxOfBmTxBufferInstanceRomType;

/**   \brief  value based type definition for PduR_AllocatedOfBmTxBufferRam */
typedef boolean PduR_AllocatedOfBmTxBufferRamType;

/**   \brief  value based type definition for PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRam */
typedef uint32 PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType;

/**   \brief  value based type definition for PduR_RxLengthOfBmTxBufferRam */
typedef PduLengthType PduR_RxLengthOfBmTxBufferRamType;

/**   \brief  value based type definition for PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRom */
typedef uint16 PduR_BmTxBufferArrayRamEndIdxOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_BmTxBufferArrayRamLengthOfBmTxBufferRom */
typedef uint16 PduR_BmTxBufferArrayRamLengthOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRom */
typedef uint16 PduR_BmTxBufferArrayRamStartIdxOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_BmTxBufferInstanceRomEndIdxOfBmTxBufferRom */
typedef uint8 PduR_BmTxBufferInstanceRomEndIdxOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRom */
typedef uint8 PduR_BmTxBufferInstanceRomStartIdxOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_ConfigId */
typedef uint8 PduR_ConfigIdType;

/**   \brief  value based type definition for PduR_MmRomIndEndIdxOfDestApplicationManagerRom */
typedef uint8 PduR_MmRomIndEndIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_MmRomIndStartIdxOfDestApplicationManagerRom */
typedef uint8 PduR_MmRomIndStartIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_MmRomIndUsedOfDestApplicationManagerRom */
typedef boolean PduR_MmRomIndUsedOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRom */
typedef uint8 PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRom */
typedef uint8 PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_BmTxBufferRomIdxOfFmFifoElementRam */
typedef uint8 PduR_BmTxBufferRomIdxOfFmFifoElementRamType;

/**   \brief  value based type definition for PduR_RmDestRomIdxOfFmFifoElementRam */
typedef uint8 PduR_RmDestRomIdxOfFmFifoElementRamType;

/**   \brief  value based type definition for PduR_BmTxBufferInstanceRomIdxOfFmFifoInstanceRam */
typedef uint8 PduR_BmTxBufferInstanceRomIdxOfFmFifoInstanceRamType;

/**   \brief  value based type definition for PduR_FmFifoRomIdxOfFmFifoInstanceRom */
typedef uint8 PduR_FmFifoRomIdxOfFmFifoInstanceRomType;

/**   \brief  value based type definition for PduR_FillLevelOfFmFifoRam */
typedef uint16 PduR_FillLevelOfFmFifoRamType;

/**   \brief  value based type definition for PduR_FmFifoElementRamReadIdxOfFmFifoRam */
typedef uint8 PduR_FmFifoElementRamReadIdxOfFmFifoRamType;

/**   \brief  value based type definition for PduR_FmFifoElementRamWriteIdxOfFmFifoRam */
typedef uint8 PduR_FmFifoElementRamWriteIdxOfFmFifoRamType;

/**   \brief  value based type definition for PduR_TpTxSmStateOfFmFifoRam */
typedef uint8 PduR_TpTxSmStateOfFmFifoRamType;

/**   \brief  value based type definition for PduR_BmTxBufferIndRomEndIdxOfFmFifoRom */
typedef uint8 PduR_BmTxBufferIndRomEndIdxOfFmFifoRomType;

/**   \brief  value based type definition for PduR_BmTxBufferIndRomLengthOfFmFifoRom */
typedef uint8 PduR_BmTxBufferIndRomLengthOfFmFifoRomType;

/**   \brief  value based type definition for PduR_BmTxBufferIndRomStartIdxOfFmFifoRom */
typedef uint8 PduR_BmTxBufferIndRomStartIdxOfFmFifoRomType;

/**   \brief  value based type definition for PduR_FmFifoElementRamEndIdxOfFmFifoRom */
typedef uint8 PduR_FmFifoElementRamEndIdxOfFmFifoRomType;

/**   \brief  value based type definition for PduR_FmFifoElementRamLengthOfFmFifoRom */
typedef uint8 PduR_FmFifoElementRamLengthOfFmFifoRomType;

/**   \brief  value based type definition for PduR_FmFifoElementRamStartIdxOfFmFifoRom */
typedef uint8 PduR_FmFifoElementRamStartIdxOfFmFifoRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfGeneralPropertiesRom */
typedef uint8 PduR_MaskedBitsOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_hasIfRoutingOfGeneralPropertiesRom */
typedef boolean PduR_hasIfRoutingOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_hasTpTxBufferedForwardingOfGeneralPropertiesRom */
typedef boolean PduR_hasTpTxBufferedForwardingOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_Initialized */
typedef boolean PduR_InitializedType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomIdxOfLockRom */
typedef uint8 PduR_ExclusiveAreaRomIdxOfLockRomType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomUsedOfLockRom */
typedef boolean PduR_ExclusiveAreaRomUsedOfLockRomType;

/**   \brief  value based type definition for PduR_DestApplicationManagerRomIdxOfMmRom */
typedef uint8 PduR_DestApplicationManagerRomIdxOfMmRomType;

/**   \brief  value based type definition for PduR_LoIfOfMmRom */
typedef boolean PduR_LoIfOfMmRomType;

/**   \brief  value based type definition for PduR_LoTpOfMmRom */
typedef boolean PduR_LoTpOfMmRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfMmRom */
typedef uint8 PduR_MaskedBitsOfMmRomType;

/**   \brief  value based type definition for PduR_RmGDestRomEndIdxOfMmRom */
typedef uint8 PduR_RmGDestRomEndIdxOfMmRomType;

/**   \brief  value based type definition for PduR_RmGDestRomStartIdxOfMmRom */
typedef uint8 PduR_RmGDestRomStartIdxOfMmRomType;

/**   \brief  value based type definition for PduR_RmGDestRomUsedOfMmRom */
typedef boolean PduR_RmGDestRomUsedOfMmRomType;

/**   \brief  value based type definition for PduR_UpIfOfMmRom */
typedef boolean PduR_UpIfOfMmRomType;

/**   \brief  value based type definition for PduR_UpTpOfMmRom */
typedef boolean PduR_UpTpOfMmRomType;

/**   \brief  value based type definition for PduR_MmRomInd */
typedef uint8 PduR_MmRomIndType;

/**   \brief  value based type definition for PduR_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 PduR_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_PartitionSNVOfPartitionIdentifiers */
typedef uint32 PduR_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_FmFifoElementRamIdxOfRmBufferedTpPropertiesRam */
typedef uint8 PduR_FmFifoElementRamIdxOfRmBufferedTpPropertiesRamType;

/**   \brief  value based type definition for PduR_TpRxSmStateOfRmBufferedTpPropertiesRam */
typedef uint8 PduR_TpRxSmStateOfRmBufferedTpPropertiesRamType;

/**   \brief  value based type definition for PduR_FmFifoRomIdxOfRmBufferedTpPropertiesRom */
typedef uint8 PduR_FmFifoRomIdxOfRmBufferedTpPropertiesRomType;

/**   \brief  value based type definition for PduR_QueuedDestCntOfRmBufferedTpPropertiesRom */
typedef uint8 PduR_QueuedDestCntOfRmBufferedTpPropertiesRomType;

/**   \brief  value based type definition for PduR_TpThresholdOfRmBufferedTpPropertiesRom */
typedef uint16 PduR_TpThresholdOfRmBufferedTpPropertiesRomType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfRmDestRom */
typedef uint8 PduR_PartitionIndexOfCslOfRmDestRomType;

/**   \brief  value based type definition for PduR_PduLengthHandlingStrategyOfRmDestRom */
typedef uint8 PduR_PduLengthHandlingStrategyOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfRmDestRom */
typedef uint8 PduR_RmGDestRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRmDestRom */
typedef uint8 PduR_RmSrcRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RoutingTypeOfRmDestRom */
typedef uint8 PduR_RoutingTypeOfRmDestRomType;

/**   \brief  value based type definition for PduR_DestHndOfRmGDestRom */
typedef uint8 PduR_DestHndOfRmGDestRomType;

/**   \brief  value based type definition for PduR_DirectionOfRmGDestRom */
typedef uint8 PduR_DirectionOfRmGDestRomType;

/**   \brief  value based type definition for PduR_FmFifoInstanceRomIdxOfRmGDestRom */
typedef uint8 PduR_FmFifoInstanceRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_FmFifoInstanceRomUsedOfRmGDestRom */
typedef boolean PduR_FmFifoInstanceRomUsedOfRmGDestRomType;

/**   \brief  value based type definition for PduR_LockRomIdxOfRmGDestRom */
typedef uint8 PduR_LockRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfRmGDestRom */
typedef uint8 PduR_MaskedBitsOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MaxPduLengthOfRmGDestRom */
typedef uint8 PduR_MaxPduLengthOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmGDestRom */
typedef uint8 PduR_MmRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfRmGDestRom */
typedef uint8 PduR_PartitionIndexOfCslOfRmGDestRomType;

/**   \brief  value based type definition for PduR_PduRDestPduProcessingOfRmGDestRom */
typedef uint8 PduR_PduRDestPduProcessingOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmDestRomIdxOfRmGDestRom */
typedef uint8 PduR_RmDestRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmGDestTpTxStateRamIdxOfRmGDestRom */
typedef uint8 PduR_RmGDestTpTxStateRamIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmGDestTpTxStateRamUsedOfRmGDestRom */
typedef boolean PduR_RmGDestTpTxStateRamUsedOfRmGDestRomType;

/**   \brief  value based type definition for PduR_TxIf2UpIdxOfRmGDestRom */
typedef uint8 PduR_TxIf2UpIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_TpTxInstSmStateOfRmGDestTpTxStateRam */
typedef uint8 PduR_TpTxInstSmStateOfRmGDestTpTxStateRamType;

/**   \brief  value based type definition for PduR_LockRomIdxOfRmSrcRom */
typedef uint8 PduR_LockRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfRmSrcRom */
typedef uint8 PduR_MaskedBitsOfRmSrcRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmSrcRom */
typedef uint8 PduR_MmRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfRmSrcRom */
typedef uint8 PduR_PartitionIndexOfCslOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmBufferedTpPropertiesRomIdxOfRmSrcRom */
typedef uint8 PduR_RmBufferedTpPropertiesRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmBufferedTpPropertiesRomUsedOfRmSrcRom */
typedef boolean PduR_RmBufferedTpPropertiesRomUsedOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomEndIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomEndIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomLengthOfRmSrcRom */
typedef uint8 PduR_RmDestRomLengthOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomStartIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomStartIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SrcHndOfRmSrcRom */
typedef uint8 PduR_SrcHndOfRmSrcRomType;

/**   \brief  value based type definition for PduR_TriggerTransmitSupportedOfRmSrcRom */
typedef boolean PduR_TriggerTransmitSupportedOfRmSrcRomType;

/**   \brief  value based type definition for PduR_TxConfirmationSupportedOfRmSrcRom */
typedef boolean PduR_TxConfirmationSupportedOfRmSrcRomType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfRxIf2Dest */
typedef uint8 PduR_PartitionIndexOfCslOfRxIf2DestType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxIf2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxIf2DestType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfRxTp2Dest */
typedef uint8 PduR_PartitionIndexOfCslOfRxTp2DestType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxTp2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferArrayRam */
typedef uint16 PduR_SizeOfBmTxBufferArrayRamType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferIndRom */
typedef uint8 PduR_SizeOfBmTxBufferIndRomType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferInstanceRam */
typedef uint8 PduR_SizeOfBmTxBufferInstanceRamType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferInstanceRom */
typedef uint8 PduR_SizeOfBmTxBufferInstanceRomType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferRam */
typedef uint8 PduR_SizeOfBmTxBufferRamType;

/**   \brief  value based type definition for PduR_SizeOfBmTxBufferRom */
typedef uint8 PduR_SizeOfBmTxBufferRomType;

/**   \brief  value based type definition for PduR_SizeOfDestApplicationManagerRom */
typedef uint8 PduR_SizeOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SizeOfExclusiveAreaRom */
typedef uint8 PduR_SizeOfExclusiveAreaRomType;

/**   \brief  value based type definition for PduR_SizeOfFmFifoElementRam */
typedef uint8 PduR_SizeOfFmFifoElementRamType;

/**   \brief  value based type definition for PduR_SizeOfFmFifoInstanceRam */
typedef uint8 PduR_SizeOfFmFifoInstanceRamType;

/**   \brief  value based type definition for PduR_SizeOfFmFifoInstanceRom */
typedef uint8 PduR_SizeOfFmFifoInstanceRomType;

/**   \brief  value based type definition for PduR_SizeOfFmFifoRam */
typedef uint8 PduR_SizeOfFmFifoRamType;

/**   \brief  value based type definition for PduR_SizeOfFmFifoRom */
typedef uint8 PduR_SizeOfFmFifoRomType;

/**   \brief  value based type definition for PduR_SizeOfGeneralPropertiesRom */
typedef uint8 PduR_SizeOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_SizeOfLockRom */
typedef uint8 PduR_SizeOfLockRomType;

/**   \brief  value based type definition for PduR_SizeOfMmRom */
typedef uint8 PduR_SizeOfMmRomType;

/**   \brief  value based type definition for PduR_SizeOfMmRomInd */
typedef uint8 PduR_SizeOfMmRomIndType;

/**   \brief  value based type definition for PduR_SizeOfPartitionIdentifiers */
typedef uint8 PduR_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_SizeOfRmBufferedTpPropertiesRam */
typedef uint8 PduR_SizeOfRmBufferedTpPropertiesRamType;

/**   \brief  value based type definition for PduR_SizeOfRmBufferedTpPropertiesRom */
typedef uint8 PduR_SizeOfRmBufferedTpPropertiesRomType;

/**   \brief  value based type definition for PduR_SizeOfRmDestRom */
typedef uint8 PduR_SizeOfRmDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmGDestRom */
typedef uint8 PduR_SizeOfRmGDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmGDestTpTxStateRam */
typedef uint8 PduR_SizeOfRmGDestTpTxStateRamType;

/**   \brief  value based type definition for PduR_SizeOfRmSrcRom */
typedef uint8 PduR_SizeOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SizeOfRmTransmitFctPtr */
typedef uint8 PduR_SizeOfRmTransmitFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfRxIf2Dest */
typedef uint8 PduR_SizeOfRxIf2DestType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Dest */
typedef uint8 PduR_SizeOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfSrcApplicationRom */
typedef uint8 PduR_SizeOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_SizeOfTx2Lo */
typedef uint8 PduR_SizeOfTx2LoType;

/**   \brief  value based type definition for PduR_SizeOfTxIf2Up */
typedef uint8 PduR_SizeOfTxIf2UpType;

/**   \brief  value based type definition for PduR_SizeOfTxTp2Src */
typedef uint8 PduR_SizeOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfSrcApplicationRom */
typedef uint8 PduR_PartitionIndexOfCslOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfTx2Lo */
typedef uint8 PduR_PartitionIndexOfCslOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfTx2Lo */
typedef uint8 PduR_RmSrcRomIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomUsedOfTx2Lo */
typedef boolean PduR_RmSrcRomUsedOfTx2LoType;

/**   \brief  value based type definition for PduR_RmTransmitFctPtrIdxOfTx2Lo */
typedef uint8 PduR_RmTransmitFctPtrIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfTxIf2Up */
typedef uint8 PduR_PartitionIndexOfCslOfTxIf2UpType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxIf2Up */
typedef uint8 PduR_RmGDestRomIdxOfTxIf2UpType;

/**   \brief  value based type definition for PduR_TxConfirmationUsedOfTxIf2Up */
typedef boolean PduR_TxConfirmationUsedOfTxIf2UpType;

/**   \brief  value based type definition for PduR_PartitionIndexOfCslOfTxTp2Src */
typedef uint8 PduR_PartitionIndexOfCslOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxTp2Src */
typedef uint8 PduR_RmGDestRomIdxOfTxTp2SrcType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_RmTransmitFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Queue abstraction layer */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_PutFctPtrType)          (PduR_RmGDestRomIterType, PduR_RmDestRomIterType, PduLengthType, SduDataPtrType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_GetFctPtrType)          (PduR_RmGDestRomIterType, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_RemoveFctPtrType)       (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(uint16,         PDUR_APPL_CODE, PduR_QAL_GetFillLevelFctPtrType) (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_FlushFctPtrType)        (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_TxConfirmation_StateHandler_FctPtrType) (PduR_RmGDestRomIterType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_FifoHandling_StateHandler_FctPtrType) (PduR_RmDestRomIterType, PduR_RmGDestRomIdxOfRmDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));  /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef uint8 PduR_MemIdxType;

#if(PDUR_SMDATAPLANEROM == STD_ON)
typedef uint8 PduR_FilterReturnType;
# define PDUR_FILTER_PASS  0u
# define PDUR_FILTER_BLOCK 1u

typedef uint32 PduR_SmSaType;
typedef uint32 PduR_SmTaType;

#define PDUR_SM_UNLEARNED_CONNECTION 0u
typedef P2FUNC(PduR_SmSaType, PDUR_CODE, PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType) (PduR_SmLinearTaToSaCalculationStrategyRomIterType, uint32, PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_CODE, PduR_Sm_SrcFilterFctPtrType) (PduR_SmSrcRomIdxOfRmSrcRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(PduR_FilterReturnType, PDUR_CODE, PduR_Sm_DestFilterFctPtrType) (PduR_SmGDestRomIdxOfRmGDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCStructTypes  PduR Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in PduR_BmTxBufferIndRom */
typedef struct sPduR_BmTxBufferIndRomType
{
  uint8 PduR_BmTxBufferIndRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_BmTxBufferIndRomType;

/**   \brief  type used in PduR_BmTxBufferInstanceRam */
typedef struct sPduR_BmTxBufferInstanceRamType
{
  PduR_BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRamType BmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam;  /**< the index of the 0:1 relation pointing to PduR_BmTxBufferArrayRam */
} PduR_BmTxBufferInstanceRamType;

/**   \brief  type used in PduR_BmTxBufferInstanceRom */
typedef struct sPduR_BmTxBufferInstanceRomType
{
  uint8 PduR_BmTxBufferInstanceRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_BmTxBufferInstanceRomType;

/**   \brief  type used in PduR_BmTxBufferRam */
typedef struct sPduR_BmTxBufferRamType
{
  PduR_BmTxBufferArrayRamWriteIdxOfBmTxBufferRamType BmTxBufferArrayRamWriteIdxOfBmTxBufferRam;  /**< the index of the 1:1 relation pointing to PduR_BmTxBufferArrayRam */
  PduR_RxLengthOfBmTxBufferRamType RxLengthOfBmTxBufferRam;  /**< Rx Pdu Sdu length */
  PduR_AllocatedOfBmTxBufferRamType AllocatedOfBmTxBufferRam;  /**< Is true, if the buffer is allocated by a routing. */
} PduR_BmTxBufferRamType;

/**   \brief  type used in PduR_BmTxBufferRom */
typedef struct sPduR_BmTxBufferRomType
{
  uint8 PduR_BmTxBufferRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_BmTxBufferRomType;

/**   \brief  type used in PduR_DestApplicationManagerRom */
typedef struct sPduR_DestApplicationManagerRomType
{
  uint8 PduR_DestApplicationManagerRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_DestApplicationManagerRomType;

/**   \brief  type used in PduR_ExclusiveAreaRom */
typedef struct sPduR_ExclusiveAreaRomType
{
  PduR_LockFunctionType LockOfExclusiveAreaRom;  /**< Lock function */
  PduR_LockFunctionType UnlockOfExclusiveAreaRom;  /**< Unlock function */
} PduR_ExclusiveAreaRomType;

/**   \brief  type used in PduR_FmFifoElementRam */
typedef struct sPduR_FmFifoElementRamType
{
  PduR_BmTxBufferRomIdxOfFmFifoElementRamType BmTxBufferRomIdxOfFmFifoElementRam;  /**< the index of the 0:1 relation pointing to PduR_BmTxBufferRom */
  PduR_RmDestRomIdxOfFmFifoElementRamType RmDestRomIdxOfFmFifoElementRam;  /**< the index of the 1:1 relation pointing to PduR_RmDestRom */
} PduR_FmFifoElementRamType;

/**   \brief  type used in PduR_FmFifoInstanceRam */
typedef struct sPduR_FmFifoInstanceRamType
{
  PduR_BmTxBufferInstanceRomIdxOfFmFifoInstanceRamType BmTxBufferInstanceRomIdxOfFmFifoInstanceRam;  /**< the index of the 0:1 relation pointing to PduR_BmTxBufferInstanceRom */
} PduR_FmFifoInstanceRamType;

/**   \brief  type used in PduR_FmFifoInstanceRom */
typedef struct sPduR_FmFifoInstanceRomType
{
  uint8 PduR_FmFifoInstanceRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_FmFifoInstanceRomType;

/**   \brief  type used in PduR_FmFifoRam */
typedef struct sPduR_FmFifoRamType
{
  PduR_FillLevelOfFmFifoRamType FillLevelOfFmFifoRam;  /**< Fill level of the FIFO queue */
  PduR_FmFifoElementRamReadIdxOfFmFifoRamType FmFifoElementRamReadIdxOfFmFifoRam;  /**< the index of the 1:1 relation pointing to PduR_FmFifoElementRam */
  PduR_FmFifoElementRamWriteIdxOfFmFifoRamType FmFifoElementRamWriteIdxOfFmFifoRam;  /**< the index of the 1:1 relation pointing to PduR_FmFifoElementRam */
  PduR_TpTxSmStateOfFmFifoRamType TpTxSmStateOfFmFifoRam;  /**< Tp Tx state */
  PduR_RmDestRomLengthOfRmSrcRomType PendingConfirmationsOfFmFifoRam;  /**< Number of pending Tx Confirmations of all possible destinations. */
} PduR_FmFifoRamType;

/**   \brief  type used in PduR_FmFifoRom */
typedef struct sPduR_FmFifoRomType
{
  uint8 PduR_FmFifoRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_FmFifoRomType;

/**   \brief  type used in PduR_GeneralPropertiesRom */
typedef struct sPduR_GeneralPropertiesRomType
{
  uint8 PduR_GeneralPropertiesRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_GeneralPropertiesRomType;

/**   \brief  type used in PduR_LockRom */
typedef struct sPduR_LockRomType
{
  uint8 PduR_LockRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_LockRomType;

/**   \brief  type used in PduR_MmRom */
typedef struct sPduR_MmRomType
{
  PduR_DestApplicationManagerRomIdxOfMmRomType DestApplicationManagerRomIdxOfMmRom;  /**< the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom */
  PduR_MaskedBitsOfMmRomType MaskedBitsOfMmRom;  /**< contains bitcoded the boolean data of PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_RmGDestRomUsedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom */
  PduR_RmGDestRomEndIdxOfMmRomType RmGDestRomEndIdxOfMmRom;  /**< the end index of the 0:n relation pointing to PduR_RmGDestRom */
  PduR_RmGDestRomStartIdxOfMmRomType RmGDestRomStartIdxOfMmRom;  /**< the start index of the 0:n relation pointing to PduR_RmGDestRom */
  PduR_CopyRxDataFctPtrType UpTpCopyRxDataFctPtrOfMmRom;  /**< Transport protocol CopyRxData function pointers */
  PduR_CopyTxDataFctPtrType UpTpCopyTxDataFctPtrOfMmRom;  /**< Transport protocol CopyTxData function pointers */
  PduR_IfRxIndicationType UpIfRxIndicationFctPtrOfMmRom;  /**< Upper layer communication interface Rx indication function pointers. */
  PduR_IfTxConfirmationFctPtrType UpIfTxConfirmationFctPtrOfMmRom;  /**< Upper layer communication interface Tx confimation function pointers */
  PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFctPtrOfMmRom;  /**< Transport protocol StartOfReception function pointers */
  PduR_TpRxIndicationFctPtrType UpTpTpRxIndicationFctPtrOfMmRom;  /**< Transport protocol TpRxIndication function pointers */
  PduR_TpTxConfirmationFctPtrType UpTpTpTxConfirmationFctPtrOfMmRom;  /**< Transport protocol TpTxConfimation function pointers */
  PduR_TransmitFctPtrType LoIfTransmitFctPtrOfMmRom;  /**< Lower layer If transmit function pointers */
  PduR_TransmitFctPtrType LoTpTransmitFctPtrOfMmRom;  /**< Lower layer Tp transmit function pointers */
  PduR_TriggerTransmitFctPtrType UpIfTriggerTransmitFctPtrOfMmRom;  /**< Upper layer trigger transmit function pointers */
} PduR_MmRomType;

/**   \brief  type used in PduR_PartitionIdentifiers */
typedef struct sPduR_PartitionIdentifiersType
{
  PduR_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
} PduR_PartitionIdentifiersType;

/**   \brief  type used in PduR_RmBufferedTpPropertiesRam */
typedef struct sPduR_RmBufferedTpPropertiesRamType
{
  PduR_FmFifoElementRamIdxOfRmBufferedTpPropertiesRamType FmFifoElementRamIdxOfRmBufferedTpPropertiesRam;  /**< the index of the 0:1 relation pointing to PduR_FmFifoElementRam */
  PduR_TpRxSmStateOfRmBufferedTpPropertiesRamType TpRxSmStateOfRmBufferedTpPropertiesRam;  /**< Tp source instance state */
} PduR_RmBufferedTpPropertiesRamType;

/**   \brief  type used in PduR_RmBufferedTpPropertiesRom */
typedef struct sPduR_RmBufferedTpPropertiesRomType
{
  uint8 PduR_RmBufferedTpPropertiesRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_RmBufferedTpPropertiesRomType;

/**   \brief  type used in PduR_RmDestRom */
typedef struct sPduR_RmDestRomType
{
  PduR_PartitionIndexOfCslOfRmDestRomType PartitionIndexOfCslOfRmDestRom;
  PduR_PduLengthHandlingStrategyOfRmDestRomType PduLengthHandlingStrategyOfRmDestRom;  /**< The strategy how larger than configured If Pdus are handled. */
  PduR_RmGDestRomIdxOfRmDestRomType RmGDestRomIdxOfRmDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
  PduR_RmSrcRomIdxOfRmDestRomType RmSrcRomIdxOfRmDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
  PduR_RoutingTypeOfRmDestRomType RoutingTypeOfRmDestRom;  /**< Type of the Routing (API Forwarding, Gateway). */
} PduR_RmDestRomType;

/**   \brief  type used in PduR_RmGDestRom */
typedef struct sPduR_RmGDestRomType
{
  PduR_DestHndOfRmGDestRomType DestHndOfRmGDestRom;  /**< handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call. */
  PduR_DirectionOfRmGDestRomType DirectionOfRmGDestRom;  /**< Direction of this Pdu: Rx or Tx */
  PduR_FmFifoInstanceRomIdxOfRmGDestRomType FmFifoInstanceRomIdxOfRmGDestRom;  /**< the index of the 0:1 relation pointing to PduR_FmFifoInstanceRom */
  PduR_MaskedBitsOfRmGDestRomType MaskedBitsOfRmGDestRom;  /**< contains bitcoded the boolean data of PduR_FmFifoInstanceRomUsedOfRmGDestRom, PduR_RmGDestTpTxStateRamUsedOfRmGDestRom */
  PduR_MaxPduLengthOfRmGDestRomType MaxPduLengthOfRmGDestRom;  /**< Configured PduLength + metadata length. */
  PduR_MmRomIdxOfRmGDestRomType MmRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_PartitionIndexOfCslOfRmGDestRomType PartitionIndexOfCslOfRmGDestRom;
  PduR_RmDestRomIdxOfRmGDestRomType RmDestRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmDestRom */
  PduR_RmGDestTpTxStateRamIdxOfRmGDestRomType RmGDestTpTxStateRamIdxOfRmGDestRom;  /**< the index of the 0:1 relation pointing to PduR_RmGDestTpTxStateRam */
} PduR_RmGDestRomType;

/**   \brief  type used in PduR_RmGDestTpTxStateRam */
typedef struct sPduR_RmGDestTpTxStateRamType
{
  PduR_TpTxInstSmStateOfRmGDestTpTxStateRamType TpTxInstSmStateOfRmGDestTpTxStateRam;  /**< Tp dest instance state */
} PduR_RmGDestTpTxStateRamType;

/**   \brief  type used in PduR_RmSrcRom */
typedef struct sPduR_RmSrcRomType
{
  PduR_MaskedBitsOfRmSrcRomType MaskedBitsOfRmSrcRom;  /**< contains bitcoded the boolean data of PduR_RmBufferedTpPropertiesRomUsedOfRmSrcRom, PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom */
  PduR_MmRomIdxOfRmSrcRomType MmRomIdxOfRmSrcRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_PartitionIndexOfCslOfRmSrcRomType PartitionIndexOfCslOfRmSrcRom;
  PduR_RmBufferedTpPropertiesRomIdxOfRmSrcRomType RmBufferedTpPropertiesRomIdxOfRmSrcRom;  /**< the index of the 0:1 relation pointing to PduR_RmBufferedTpPropertiesRom */
  PduR_RmDestRomStartIdxOfRmSrcRomType RmDestRomStartIdxOfRmSrcRom;  /**< the start index of the 1:n relation pointing to PduR_RmDestRom */
  PduR_SrcHndOfRmSrcRomType SrcHndOfRmSrcRom;  /**< handle to be used as parameter for the TxConfirmation or TriggerTransmit function call. */
} PduR_RmSrcRomType;

/**   \brief  type used in PduR_RxIf2Dest */
typedef struct sPduR_RxIf2DestType
{
  PduR_PartitionIndexOfCslOfRxIf2DestType PartitionIndexOfCslOfRxIf2Dest;
} PduR_RxIf2DestType;

/**   \brief  type used in PduR_RxTp2Dest */
typedef struct sPduR_RxTp2DestType
{
  PduR_PartitionIndexOfCslOfRxTp2DestType PartitionIndexOfCslOfRxTp2Dest;
} PduR_RxTp2DestType;

/**   \brief  type used in PduR_SrcApplicationRom */
typedef struct sPduR_SrcApplicationRomType
{
  uint8 PduR_SrcApplicationRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_SrcApplicationRomType;

/**   \brief  type used in PduR_Tx2Lo */
typedef struct sPduR_Tx2LoType
{
  PduR_PartitionIndexOfCslOfTx2LoType PartitionIndexOfCslOfTx2Lo;
  PduR_RmTransmitFctPtrIdxOfTx2LoType RmTransmitFctPtrIdxOfTx2Lo;  /**< the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr */
} PduR_Tx2LoType;

/**   \brief  type used in PduR_TxIf2Up */
typedef struct sPduR_TxIf2UpType
{
  PduR_PartitionIndexOfCslOfTxIf2UpType PartitionIndexOfCslOfTxIf2Up;
  PduR_RmGDestRomIdxOfTxIf2UpType RmGDestRomIdxOfTxIf2Up;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
} PduR_TxIf2UpType;

/**   \brief  type used in PduR_TxTp2Src */
typedef struct sPduR_TxTp2SrcType
{
  PduR_PartitionIndexOfCslOfTxTp2SrcType PartitionIndexOfCslOfTxTp2Src;
} PduR_TxTp2SrcType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicStructTypes  PduR Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to PduR_BmTxBufferArrayRam in the partition context  */
typedef struct PduR_BmTxBufferArrayRamStructSTag
{
  PduR_BmTxBufferArrayRamType PduRTxBuffer[4096];
} PduR_BmTxBufferArrayRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_BmTxBufferInstanceRam in the partition context  */
typedef struct PduR_BmTxBufferInstanceRamStructSTag
{
  PduR_BmTxBufferInstanceRamType PduRTxBuffer;
} PduR_BmTxBufferInstanceRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_BmTxBufferRam in the partition context  */
typedef struct PduR_BmTxBufferRamStructSTag
{
  PduR_BmTxBufferRamType PduRTxBuffer;
} PduR_BmTxBufferRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_FmFifoElementRam in the partition context  */
typedef struct PduR_FmFifoElementRamStructSTag
{
  PduR_FmFifoElementRamType PduRQueue;
} PduR_FmFifoElementRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_FmFifoInstanceRam in the partition context  */
typedef struct PduR_FmFifoInstanceRamStructSTag
{
  PduR_FmFifoInstanceRamType HUT_Phy_Resp_oB30_for_SC_CAN_V3_2_20_e2aa5bb4_Tx;
} PduR_FmFifoInstanceRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_FmFifoRam in the partition context  */
typedef struct PduR_FmFifoRamStructSTag
{
  PduR_FmFifoRamType PduRQueue;
} PduR_FmFifoRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_RmBufferedTpPropertiesRam in the partition context  */
typedef struct PduR_RmBufferedTpPropertiesRamStructSTag
{
  PduR_RmBufferedTpPropertiesRamType PduRSrcPdu_c66043fb;
} PduR_RmBufferedTpPropertiesRamStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_RmGDestTpTxStateRam in the partition context  */
typedef struct PduR_RmGDestTpTxStateRamStructSTag
{
  PduR_RmGDestTpTxStateRamType HUT_Phy_Resp_oB30_for_SC_CAN_V3_2_20_e2aa5bb4_Tx;
} PduR_RmGDestTpTxStateRamStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCUnionIndexAndSymbolTypes  PduR Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access PduR_BmTxBufferArrayRam in an index and symbol based style. */
typedef union PduR_BmTxBufferArrayRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_BmTxBufferArrayRamType raw[4096];
  PduR_BmTxBufferArrayRamStructSType str;
} PduR_BmTxBufferArrayRamUType;

/**   \brief  type to access PduR_BmTxBufferInstanceRam in an index and symbol based style. */
typedef union PduR_BmTxBufferInstanceRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_BmTxBufferInstanceRamType raw[1];
  PduR_BmTxBufferInstanceRamStructSType str;
} PduR_BmTxBufferInstanceRamUType;

/**   \brief  type to access PduR_BmTxBufferRam in an index and symbol based style. */
typedef union PduR_BmTxBufferRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_BmTxBufferRamType raw[1];
  PduR_BmTxBufferRamStructSType str;
} PduR_BmTxBufferRamUType;

/**   \brief  type to access PduR_FmFifoElementRam in an index and symbol based style. */
typedef union PduR_FmFifoElementRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_FmFifoElementRamType raw[1];
  PduR_FmFifoElementRamStructSType str;
} PduR_FmFifoElementRamUType;

/**   \brief  type to access PduR_FmFifoInstanceRam in an index and symbol based style. */
typedef union PduR_FmFifoInstanceRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_FmFifoInstanceRamType raw[1];
  PduR_FmFifoInstanceRamStructSType str;
} PduR_FmFifoInstanceRamUType;

/**   \brief  type to access PduR_FmFifoRam in an index and symbol based style. */
typedef union PduR_FmFifoRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_FmFifoRamType raw[1];
  PduR_FmFifoRamStructSType str;
} PduR_FmFifoRamUType;

/**   \brief  type to access PduR_RmBufferedTpPropertiesRam in an index and symbol based style. */
typedef union PduR_RmBufferedTpPropertiesRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_RmBufferedTpPropertiesRamType raw[1];
  PduR_RmBufferedTpPropertiesRamStructSType str;
} PduR_RmBufferedTpPropertiesRamUType;

/**   \brief  type to access PduR_RmGDestTpTxStateRam in an index and symbol based style. */
typedef union PduR_RmGDestTpTxStateRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_RmGDestTpTxStateRamType raw[1];
  PduR_RmGDestTpTxStateRamStructSType str;
} PduR_RmGDestTpTxStateRamUType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootPointerTypes  PduR Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to PduR_BmTxBufferArrayRam */
typedef P2VAR(PduR_BmTxBufferArrayRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_BmTxBufferArrayRamPtrType;

/**   \brief  type used to point to PduR_BmTxBufferIndRom */
typedef P2CONST(PduR_BmTxBufferIndRomType, TYPEDEF, PDUR_CONST) PduR_BmTxBufferIndRomPtrType;

/**   \brief  type used to point to PduR_BmTxBufferInstanceRam */
typedef P2VAR(PduR_BmTxBufferInstanceRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_BmTxBufferInstanceRamPtrType;

/**   \brief  type used to point to PduR_BmTxBufferInstanceRom */
typedef P2CONST(PduR_BmTxBufferInstanceRomType, TYPEDEF, PDUR_CONST) PduR_BmTxBufferInstanceRomPtrType;

/**   \brief  type used to point to PduR_BmTxBufferRam */
typedef P2VAR(PduR_BmTxBufferRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_BmTxBufferRamPtrType;

/**   \brief  type used to point to PduR_BmTxBufferRom */
typedef P2CONST(PduR_BmTxBufferRomType, TYPEDEF, PDUR_CONST) PduR_BmTxBufferRomPtrType;

/**   \brief  type used to point to PduR_DestApplicationManagerRom */
typedef P2CONST(PduR_DestApplicationManagerRomType, TYPEDEF, PDUR_CONST) PduR_DestApplicationManagerRomPtrType;

/**   \brief  type used to point to PduR_ExclusiveAreaRom */
typedef P2CONST(PduR_ExclusiveAreaRomType, TYPEDEF, PDUR_CONST) PduR_ExclusiveAreaRomPtrType;

/**   \brief  type used to point to PduR_FmFifoElementRam */
typedef P2VAR(PduR_FmFifoElementRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_FmFifoElementRamPtrType;

/**   \brief  type used to point to PduR_FmFifoInstanceRam */
typedef P2VAR(PduR_FmFifoInstanceRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_FmFifoInstanceRamPtrType;

/**   \brief  type used to point to PduR_FmFifoInstanceRom */
typedef P2CONST(PduR_FmFifoInstanceRomType, TYPEDEF, PDUR_CONST) PduR_FmFifoInstanceRomPtrType;

/**   \brief  type used to point to PduR_FmFifoRam */
typedef P2VAR(PduR_FmFifoRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_FmFifoRamPtrType;

/**   \brief  type used to point to PduR_FmFifoRom */
typedef P2CONST(PduR_FmFifoRomType, TYPEDEF, PDUR_CONST) PduR_FmFifoRomPtrType;

/**   \brief  type used to point to PduR_GeneralPropertiesRom */
typedef P2CONST(PduR_GeneralPropertiesRomType, TYPEDEF, PDUR_CONST) PduR_GeneralPropertiesRomPtrType;

/**   \brief  type used to point to PduR_Initialized */
typedef P2VAR(PduR_InitializedType, TYPEDEF, PDUR_VAR_ZERO_INIT) PduR_InitializedPtrType;

/**   \brief  type used to point to PduR_LockRom */
typedef P2CONST(PduR_LockRomType, TYPEDEF, PDUR_CONST) PduR_LockRomPtrType;

/**   \brief  type used to point to PduR_MmRom */
typedef P2CONST(PduR_MmRomType, TYPEDEF, PDUR_CONST) PduR_MmRomPtrType;

/**   \brief  type used to point to PduR_MmRomInd */
typedef P2CONST(PduR_MmRomIndType, TYPEDEF, PDUR_CONST) PduR_MmRomIndPtrType;

/**   \brief  type used to point to PduR_PartitionIdentifiers */
typedef P2CONST(PduR_PartitionIdentifiersType, TYPEDEF, PDUR_CONST) PduR_PartitionIdentifiersPtrType;

/**   \brief  type used to point to PduR_RmBufferedTpPropertiesRam */
typedef P2VAR(PduR_RmBufferedTpPropertiesRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_RmBufferedTpPropertiesRamPtrType;

/**   \brief  type used to point to PduR_RmBufferedTpPropertiesRom */
typedef P2CONST(PduR_RmBufferedTpPropertiesRomType, TYPEDEF, PDUR_CONST) PduR_RmBufferedTpPropertiesRomPtrType;

/**   \brief  type used to point to PduR_RmDestRom */
typedef P2CONST(PduR_RmDestRomType, TYPEDEF, PDUR_CONST) PduR_RmDestRomPtrType;

/**   \brief  type used to point to PduR_RmGDestRom */
typedef P2CONST(PduR_RmGDestRomType, TYPEDEF, PDUR_CONST) PduR_RmGDestRomPtrType;

/**   \brief  type used to point to PduR_RmGDestTpTxStateRam */
typedef P2VAR(PduR_RmGDestTpTxStateRamType, TYPEDEF, PDUR_VAR_NOINIT) PduR_RmGDestTpTxStateRamPtrType;

/**   \brief  type used to point to PduR_RmSrcRom */
typedef P2CONST(PduR_RmSrcRomType, TYPEDEF, PDUR_CONST) PduR_RmSrcRomPtrType;

/**   \brief  type used to point to PduR_RmTransmitFctPtr */
typedef P2CONST(PduR_RmTransmitFctPtrType, TYPEDEF, PDUR_CONST) PduR_RmTransmitFctPtrPtrType;

/**   \brief  type used to point to PduR_RxIf2Dest */
typedef P2CONST(PduR_RxIf2DestType, TYPEDEF, PDUR_CONST) PduR_RxIf2DestPtrType;

/**   \brief  type used to point to PduR_RxTp2Dest */
typedef P2CONST(PduR_RxTp2DestType, TYPEDEF, PDUR_CONST) PduR_RxTp2DestPtrType;

/**   \brief  type used to point to PduR_SrcApplicationRom */
typedef P2CONST(PduR_SrcApplicationRomType, TYPEDEF, PDUR_CONST) PduR_SrcApplicationRomPtrType;

/**   \brief  type used to point to PduR_Tx2Lo */
typedef P2CONST(PduR_Tx2LoType, TYPEDEF, PDUR_CONST) PduR_Tx2LoPtrType;

/**   \brief  type used to point to PduR_TxIf2Up */
typedef P2CONST(PduR_TxIf2UpType, TYPEDEF, PDUR_CONST) PduR_TxIf2UpPtrType;

/**   \brief  type used to point to PduR_TxTp2Src */
typedef P2CONST(PduR_TxTp2SrcType, TYPEDEF, PDUR_CONST) PduR_TxTp2SrcPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCPartitionRootPointer  PduR Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in PduR_PCPartitionConfig */
typedef struct sPduR_PCPartitionConfigType
{
  PduR_BmTxBufferArrayRamPtrType BmTxBufferArrayRamOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferArrayRam */
  PduR_BmTxBufferIndRomPtrType BmTxBufferIndRomOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferIndRom */
  PduR_BmTxBufferInstanceRamPtrType BmTxBufferInstanceRamOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferInstanceRam */
  PduR_BmTxBufferInstanceRomPtrType BmTxBufferInstanceRomOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferInstanceRom */
  PduR_BmTxBufferRamPtrType BmTxBufferRamOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferRam */
  PduR_BmTxBufferRomPtrType BmTxBufferRomOfPCPartitionConfig;  /**< the pointer to PduR_BmTxBufferRom */
  PduR_FmFifoElementRamPtrType FmFifoElementRamOfPCPartitionConfig;  /**< the pointer to PduR_FmFifoElementRam */
  PduR_FmFifoInstanceRamPtrType FmFifoInstanceRamOfPCPartitionConfig;  /**< the pointer to PduR_FmFifoInstanceRam */
  PduR_FmFifoInstanceRomPtrType FmFifoInstanceRomOfPCPartitionConfig;  /**< the pointer to PduR_FmFifoInstanceRom */
  PduR_FmFifoRamPtrType FmFifoRamOfPCPartitionConfig;  /**< the pointer to PduR_FmFifoRam */
  PduR_FmFifoRomPtrType FmFifoRomOfPCPartitionConfig;  /**< the pointer to PduR_FmFifoRom */
  PduR_InitializedPtrType InitializedOfPCPartitionConfig;  /**< the pointer to PduR_Initialized */
  PduR_RmBufferedTpPropertiesRamPtrType RmBufferedTpPropertiesRamOfPCPartitionConfig;  /**< the pointer to PduR_RmBufferedTpPropertiesRam */
  PduR_RmBufferedTpPropertiesRomPtrType RmBufferedTpPropertiesRomOfPCPartitionConfig;  /**< the pointer to PduR_RmBufferedTpPropertiesRom */
  PduR_RmGDestTpTxStateRamPtrType RmGDestTpTxStateRamOfPCPartitionConfig;  /**< the pointer to PduR_RmGDestTpTxStateRam */
} PduR_PCPartitionConfigType;

/**   \brief  type used to point to PduR_PCPartitionConfig */
typedef P2CONST(PduR_PCPartitionConfigType, TYPEDEF, PDUR_CONST) PduR_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootValueTypes  PduR Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in PduR_PCConfig */
typedef struct sPduR_PCConfigType
{
  uint8 PduR_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_PCConfigType;

typedef PduR_PCConfigType PduR_PBConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                         Description
  DestApplicationManagerRomIdx    the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom
  MaskedBits                      contains bitcoded the boolean data of PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_RmGDestRomUsedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom
  RmGDestRomEndIdx                the end index of the 0:n relation pointing to PduR_RmGDestRom
  RmGDestRomStartIdx              the start index of the 0:n relation pointing to PduR_RmGDestRom
  UpTpCopyRxDataFctPtr            Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr            Transport protocol CopyTxData function pointers
  UpIfRxIndicationFctPtr          Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr        Upper layer communication interface Tx confimation function pointers
  UpTpStartOfReceptionFctPtr      Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr        Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr      Transport protocol TpTxConfimation function pointers
  LoIfTransmitFctPtr              Lower layer If transmit function pointers
  LoTpTransmitFctPtr              Lower layer Tp transmit function pointers
  UpIfTriggerTransmitFctPtr       Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[6];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    PduR_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PartitionIdentifiersType, PDUR_CONST) PduR_PartitionIdentifiers[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRom
  \brief  PduR RoutiongPathManager destPdu Table
  \details
  Element                      Description
  PartitionIndexOfCsl      
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[218];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRom
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element                   Description
  DestHnd                   handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction                 Direction of this Pdu: Rx or Tx
  FmFifoInstanceRomIdx      the index of the 0:1 relation pointing to PduR_FmFifoInstanceRom
  MaskedBits                contains bitcoded the boolean data of PduR_FmFifoInstanceRomUsedOfRmGDestRom, PduR_RmGDestTpTxStateRamUsedOfRmGDestRom
  MaxPduLength              Configured PduLength + metadata length.
  MmRomIdx                  the index of the 1:1 relation pointing to PduR_MmRom
  PartitionIndexOfCsl   
  RmDestRomIdx              the index of the 1:1 relation pointing to PduR_RmDestRom
  RmGDestTpTxStateRamIdx    the index of the 0:1 relation pointing to PduR_RmGDestTpTxStateRam
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[218];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRom
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element                         Description
  MaskedBits                      contains bitcoded the boolean data of PduR_RmBufferedTpPropertiesRomUsedOfRmSrcRom, PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx                        the index of the 1:1 relation pointing to PduR_MmRom
  PartitionIndexOfCsl         
  RmBufferedTpPropertiesRomIdx    the index of the 0:1 relation pointing to PduR_RmBufferedTpPropertiesRom
  RmDestRomStartIdx               the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd                          handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[218];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[3];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxIf2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxIf2Dest
  \brief  This table contains all routing information to perform the Rx handling of an interface routing. Used in the &lt;LLIf&gt;_RxIndication
  \details
  Element                Description
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RxIf2DestType, PDUR_CONST) PduR_RxIf2Dest[155];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element                Description
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all information to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  PartitionIndexOfCsl
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[59];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element                Description
  PartitionIndexOfCsl
  RmGDestRomIdx          the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[57];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_TxTp2Src
  \brief  This table contains all routing information to perform the Tx handling of a transport protocol routing, Used in the &lt;LoTp&gt;_CopyTxData and &lt;LoTp&gt;_TxConfirmation
  \details
  Element                Description
  PartitionIndexOfCsl
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_BmTxBufferArrayRam
**********************************************************************************************************************/
/** 
  \var    PduR_BmTxBufferArrayRam
  \brief  PduR BufferManagere TxBufferArray Table
*/ 
#define PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_BmTxBufferArrayRamUType, PDUR_VAR_NOINIT) PduR_BmTxBufferArrayRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_BmTxBufferInstanceRam
**********************************************************************************************************************/
/** 
  \var    PduR_BmTxBufferInstanceRam
  \brief  PduR BufferManager TxBufferInstance Table
  \details
  Element                      Description
  BmTxBufferArrayRamReadIdx    the index of the 0:1 relation pointing to PduR_BmTxBufferArrayRam
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_BmTxBufferInstanceRamUType, PDUR_VAR_NOINIT) PduR_BmTxBufferInstanceRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_BmTxBufferRam
**********************************************************************************************************************/
/** 
  \var    PduR_BmTxBufferRam
  \brief  PduR BufferManager TxBuffer Table
  \details
  Element                       Description
  BmTxBufferArrayRamWriteIdx    the index of the 1:1 relation pointing to PduR_BmTxBufferArrayRam
  RxLength                      Rx Pdu Sdu length
  Allocated                     Is true, if the buffer is allocated by a routing.
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_BmTxBufferRamUType, PDUR_VAR_NOINIT) PduR_BmTxBufferRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_FmFifoElementRam
**********************************************************************************************************************/
/** 
  \var    PduR_FmFifoElementRam
  \brief  PduR FiFoManager FIFO element table
  \details
  Element             Description
  BmTxBufferRomIdx    the index of the 0:1 relation pointing to PduR_BmTxBufferRom
  RmDestRomIdx        the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_FmFifoElementRamUType, PDUR_VAR_NOINIT) PduR_FmFifoElementRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_FmFifoInstanceRam
**********************************************************************************************************************/
/** 
  \var    PduR_FmFifoInstanceRam
  \brief  Instance of the PduRDestPdus using a single Fifo
  \details
  Element                     Description
  BmTxBufferInstanceRomIdx    the index of the 0:1 relation pointing to PduR_BmTxBufferInstanceRom
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_FmFifoInstanceRamUType, PDUR_VAR_NOINIT) PduR_FmFifoInstanceRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_FmFifoRam
**********************************************************************************************************************/
/** 
  \var    PduR_FmFifoRam
  \brief  PduR FiFoManager Fifo Table
  \details
  Element                     Description
  FillLevel                   Fill level of the FIFO queue
  FmFifoElementRamReadIdx     the index of the 1:1 relation pointing to PduR_FmFifoElementRam
  FmFifoElementRamWriteIdx    the index of the 1:1 relation pointing to PduR_FmFifoElementRam
  TpTxSmState                 Tp Tx state
  PendingConfirmations        Number of pending Tx Confirmations of all possible destinations.
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_FmFifoRamUType, PDUR_VAR_NOINIT) PduR_FmFifoRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmBufferedTpPropertiesRam
**********************************************************************************************************************/
/** 
  \var    PduR_RmBufferedTpPropertiesRam
  \brief  PduR RoutiongManager Properties of buffered Tp routing paths.
  \details
  Element                Description
  FmFifoElementRamIdx    the index of the 0:1 relation pointing to PduR_FmFifoElementRam
  TpRxSmState            Tp source instance state
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_RmBufferedTpPropertiesRamUType, PDUR_VAR_NOINIT) PduR_RmBufferedTpPropertiesRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestTpTxStateRam
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestTpTxStateRam
  \brief  PduR RoutiongPathManager global destPdu Tp Tx State
  \details
  Element            Description
  TpTxInstSmState    Tp dest instance state
*/ 
#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_RmGDestTpTxStateRamUType, PDUR_VAR_NOINIT) PduR_RmGDestTpTxStateRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfig
  \details
  Element                      Description
  BmTxBufferArrayRam           the pointer to PduR_BmTxBufferArrayRam
  BmTxBufferIndRom             the pointer to PduR_BmTxBufferIndRom
  BmTxBufferInstanceRam        the pointer to PduR_BmTxBufferInstanceRam
  BmTxBufferInstanceRom        the pointer to PduR_BmTxBufferInstanceRom
  BmTxBufferRam                the pointer to PduR_BmTxBufferRam
  BmTxBufferRom                the pointer to PduR_BmTxBufferRom
  FmFifoElementRam             the pointer to PduR_FmFifoElementRam
  FmFifoInstanceRam            the pointer to PduR_FmFifoInstanceRam
  FmFifoInstanceRom            the pointer to PduR_FmFifoInstanceRom
  FmFifoRam                    the pointer to PduR_FmFifoRam
  FmFifoRom                    the pointer to PduR_FmFifoRom
  Initialized                  the pointer to PduR_Initialized
  RmBufferedTpPropertiesRam    the pointer to PduR_RmBufferedTpPropertiesRam
  RmBufferedTpPropertiesRom    the pointer to PduR_RmBufferedTpPropertiesRom
  RmGDestTpTxStateRam          the pointer to PduR_RmGDestTpTxStateRam
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfig[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
extern P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, PDUR_VAR_NOINIT) PduR_PreInitialized;

#define PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * LOCAL GEN FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL GEN FUNCTIONS
 *********************************************************************************************************************/

#endif  /* PDUR_LCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.h
 *********************************************************************************************************************/

