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
 *            Module: Csm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.h
 *   Generation Time: 2021-03-03 10:55:52
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (CSM_CFG_H)
#define CSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Types.h"
#include "Crypto_30_vHsm_Custom.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CSM_USE_DUMMY_STATEMENT
#define CSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT
#define CSM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT_CONST
#define CSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CSM_ATOMIC_VARIABLE_ACCESS
#define CSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CSM_PROCESSOR_RH850_1651
#define CSM_PROCESSOR_RH850_1651
#endif
#ifndef CSM_COMP_GREENHILLS
#define CSM_COMP_GREENHILLS
#endif
#ifndef CSM_GEN_GENERATOR_MSR
#define CSM_GEN_GENERATOR_MSR
#endif
#ifndef CSM_CPUTYPE_BITORDER_LSB2MSB
#define CSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CSM_CONFIGURATION_VARIANT_LINKTIME
#define CSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CSM_CONFIGURATION_VARIANT
#define CSM_CONFIGURATION_VARIANT CSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CSM_POSTBUILD_VARIANT_SUPPORT
#define CSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define CSM_CALLBACKS                                                                               STD_ON 
#define CSM_ASYM_PRIVATE_KEY_MAX_LENGTH                                                             32uL 
#define CSM_ASYM_PUBLIC_KEY_MAX_LENGTH                                                              1024uL 
#define CSM_SYM_KEY_MAX_LENGTH                                                                      16uL 
#define CSM_USE_DEPRECATED                                                                          STD_OFF 
#define CSM_VERSION_INFO_API                                                                        STD_OFF 
#define CSM_CALLBACK_START_NOTIFICATION                                                             STD_OFF 
#define CSM_JOBS                                                                                    STD_ON 
#define CSM_KEYS                                                                                    STD_ON 
#define CSM_QUEUES                                                                                  STD_ON 
#define CSM_CALLOUTS                                                                                STD_ON 
#define CSM_IN_OUT_REDIRECTIONS                                                                     STD_OFF 

/* Symbolic Name Define Block */
#define CsmConf_CsmJob_CsmJob_Aes128_Decrypt                                                        0uL 
#define CsmConf_CsmJob_CsmJob_Aes128_Encrypt                                                        1uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT15                                                   2uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_FD1                                                 3uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_IP2                                                 4uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ABM1                                                      5uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_DCT_FD4                                                   6uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP_FD1                                                   7uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ACC_FD2                                                   8uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_AEB_FD2                                                   9uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_AMP2                                                      10uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM1                                                      11uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM3                                                      12uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_DCT7                                                      13uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP1                                                      14uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP2                                                      15uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP_FD2                                                   16uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_GW_SYNC_REQ                                               17uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_IFC_FD2                                                   18uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_R_PBox1                                                   19uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS1                                                     20uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS2                                                     21uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD1                                                 22uL 
#define CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD3                                                 23uL 
#define CsmConf_CsmJob_CsmJob_KeySetValid                                                           24uL 
#define CsmConf_CsmJob_CsmJob_Random                                                                25uL 
#define CsmConf_CsmJob_CsmJob_SecureBoot_Generate                                                   26uL 
#define CsmConf_CsmKey_CsmKey                                                                       0uL 
#define CsmConf_CsmKey_CsmKey_Aes128                                                                1uL 
#define CsmConf_CsmKey_CsmKey_Flash                                                                 2uL 
#define CsmConf_CsmKey_CsmKey_RandomSeed                                                            3uL 
#define CsmConf_CsmKey_CsmKey_SecureBootAPP_A                                                       4uL 
#define CsmConf_CsmKey_CsmKey_SecureBootAPP_B                                                       5uL 
#define CsmConf_CsmKey_CsmKey_SecureBootAppKey                                                      6uL 

#define CSM_ASYNC_PROCESSING                                                                        STD_ON
#ifndef CSM_DEV_ERROR_DETECT
#define CSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CSM_DEV_ERROR_REPORT
#define CSM_DEV_ERROR_REPORT STD_ON
#endif
#define CSM_EXIST_AEADDECRYPT                                                                       STD_OFF
#define CSM_EXIST_AEADENCRYPT                                                                       STD_OFF
#define CSM_EXIST_DECRYPT                                                                           STD_ON
#define CSM_EXIST_ENCRYPT                                                                           STD_ON
#define CSM_EXIST_HASH                                                                              STD_OFF
#define CSM_EXIST_MACGENERATE                                                                       STD_ON
#define CSM_EXIST_MACVERIFY                                                                         STD_ON
#define CSM_EXIST_RANDOMGENERATE                                                                    STD_ON
#define CSM_EXIST_SECURECOUNTER                                                                     STD_OFF
#define CSM_EXIST_SIGNATUREGENERATE                                                                 STD_OFF
#define CSM_EXIST_SIGNATUREVERIFY                                                                   STD_OFF
#define CSM_EXIST_JOBKEYSETVALID                                                                    STD_ON
#define CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL                                                          STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCSECRET                                                          STD_OFF
#define CSM_EXIST_JOBKEYDERIVE                                                                      STD_OFF
#define CSM_EXIST_JOBRANDOMSEED                                                                     STD_OFF
#define CSM_EXIST_JOBKEYGENERATE                                                                    STD_OFF
#define CSM_EXIST_JOBCERTIFICATEPARSE                                                               STD_OFF
#define CSM_EXIST_JOBCERTIFICATEVERIFY                                                              STD_OFF
#define CSM_INVALID_KEYID                                                                           0xFFFFFFFFUL


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCDataSwitches  Csm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERAL                                                        STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERAL                                                         STD_ON
#define CSM_BSWCALLBACKS                                                                            STD_ON
#define CSM_CALLBACKFUNC43OFBSWCALLBACKS                                                            STD_ON
#define CSM_CALLBACKFUNC44OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define CSM_CALLBACKFUNC45OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERAL                                                      STD_ON
#define CSM_CALLOUT                                                                                 STD_ON
#define CSM_POSTJOBCALLOUTFUNCOFCALLOUT                                                             STD_ON
#define CSM_PREJOBCALLOUTFUNCOFCALLOUT                                                              STD_ON
#define CSM_CALLOUTINFO                                                                             STD_ON
#define CSM_CALLOUTIDXOFCALLOUTINFO                                                                 STD_ON
#define CSM_JOBTABLEIDXOFCALLOUTINFO                                                                STD_ON
#define CSM_CALLOUTSTATE                                                                            STD_ON
#define CSM_CALLOUTSTATEOFCALLOUTSTATE                                                              STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSION                                                            STD_OFF  /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_GENERATORCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_INOUTJOBREDIRECTIONTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define CSM_DUMMYOFINOUTJOBREDIRECTIONTABLE                                                         STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.Dummy' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                        STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                           STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                          STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_INOUTREDIRECTION                                                                        STD_OFF  /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_JOB                                                                                     STD_ON
#define CSM_JOBINFO                                                                                 STD_ON
#define CSM_JOBPRIMITIVEINFO                                                                        STD_ON
#define CSM_JOBTABLE                                                                                STD_ON
#define CSM_BSWCALLBACKSIDXOFJOBTABLE                                                               STD_ON
#define CSM_BSWCALLBACKSUSEDOFJOBTABLE                                                              STD_ON
#define CSM_CALLOUTINFOIDXOFJOBTABLE                                                                STD_ON
#define CSM_CALLOUTINFOUSEDOFJOBTABLE                                                               STD_ON
#define CSM_CSMKEYIDIDXOFJOBTABLE                                                                   STD_ON
#define CSM_INOUTREDIRECTIONCONFIGIDXOFJOBTABLE                                                     STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigIdx' Reason: 'Not enabled for any job' */
#define CSM_INOUTREDIRECTIONCONFIGUSEDOFJOBTABLE                                                    STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigUsed' Reason: 'Not enabled for any job' */
#define CSM_INOUTREDIRECTIONIDXOFJOBTABLE                                                           STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_INOUTREDIRECTIONUSEDOFJOBTABLE                                                          STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_JOBINFOIDXOFJOBTABLE                                                                    STD_ON
#define CSM_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                           STD_ON
#define CSM_MASKEDBITSOFJOBTABLE                                                                    STD_ON
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                           STD_ON
#define CSM_PRIORITYOFJOBTABLE                                                                      STD_ON
#define CSM_QUEUEREFIDXOFJOBTABLE                                                                   STD_ON
#define CSM_RTECALLBACKIDXOFJOBTABLE                                                                STD_ON
#define CSM_RTECALLBACKUSEDOFJOBTABLE                                                               STD_ON
#define CSM_KEY                                                                                     STD_ON
#define CSM_CRYIFKEYIDOFKEY                                                                         STD_ON
#define CSM_USEPORTOFKEY                                                                            STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERAL                                                             STD_ON
#define CSM_PRIMITIVEINFO                                                                           STD_ON
#define CSM_QUEUE                                                                                   STD_ON
#define CSM_QUEUEINFO                                                                               STD_ON
#define CSM_CHANNELIDOFQUEUEINFO                                                                    STD_ON
#define CSM_QUEUEENDIDXOFQUEUEINFO                                                                  STD_ON
#define CSM_QUEUELENGTHOFQUEUEINFO                                                                  STD_ON
#define CSM_QUEUESTARTIDXOFQUEUEINFO                                                                STD_ON
#define CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                                  STD_ON
#define CSM_QUEUESTATE                                                                              STD_ON
#define CSM_PAUSEPROCESSINGOFQUEUESTATE                                                             STD_ON
#define CSM_QUEUEIDXOFQUEUESTATE                                                                    STD_ON
#define CSM_RESERVEDINDEXESOFQUEUESTATE                                                             STD_ON
#define CSM_SORTNEEDEDOFQUEUESTATE                                                                  STD_ON
#define CSM_RTECALLBACK                                                                             STD_ON
#define CSM_RTECALLBACKOCCURED                                                                      STD_ON
#define CSM_RTERESULT                                                                               STD_ON
#define CSM_SIZEOFBSWCALLBACKS                                                                      STD_ON
#define CSM_SIZEOFCALLOUT                                                                           STD_ON
#define CSM_SIZEOFCALLOUTINFO                                                                       STD_ON
#define CSM_SIZEOFCALLOUTSTATE                                                                      STD_ON
#define CSM_SIZEOFJOB                                                                               STD_ON
#define CSM_SIZEOFJOBINFO                                                                           STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFO                                                                  STD_ON
#define CSM_SIZEOFJOBTABLE                                                                          STD_ON
#define CSM_SIZEOFKEY                                                                               STD_ON
#define CSM_SIZEOFPRIMITIVEINFO                                                                     STD_ON
#define CSM_SIZEOFQUEUE                                                                             STD_ON
#define CSM_SIZEOFQUEUEINFO                                                                         STD_ON
#define CSM_SIZEOFQUEUESTATE                                                                        STD_ON
#define CSM_SIZEOFRTECALLBACK                                                                       STD_ON
#define CSM_SIZEOFRTERESULT                                                                         STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERAL                                                                STD_ON
#define CSM_USEDEPRECATEDOFGENERAL                                                                  STD_ON
#define CSM_VERSIONINFOAPIOFGENERAL                                                                 STD_ON
#define CSM_PCCONFIG                                                                                STD_ON
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERALOFPCCONFIG                                              STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERALOFPCCONFIG                                               STD_ON
#define CSM_BSWCALLBACKSOFPCCONFIG                                                                  STD_ON
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERALOFPCCONFIG                                            STD_ON
#define CSM_CALLOUTINFOOFPCCONFIG                                                                   STD_ON
#define CSM_CALLOUTOFPCCONFIG                                                                       STD_ON
#define CSM_CALLOUTSTATEOFPCCONFIG                                                                  STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_JOBINFOOFPCCONFIG                                                                       STD_ON
#define CSM_JOBOFPCCONFIG                                                                           STD_ON
#define CSM_JOBPRIMITIVEINFOOFPCCONFIG                                                              STD_ON
#define CSM_JOBTABLEOFPCCONFIG                                                                      STD_ON
#define CSM_KEYOFPCCONFIG                                                                           STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                   STD_ON
#define CSM_PRIMITIVEINFOOFPCCONFIG                                                                 STD_ON
#define CSM_QUEUEINFOOFPCCONFIG                                                                     STD_ON
#define CSM_QUEUEOFPCCONFIG                                                                         STD_ON
#define CSM_QUEUESTATEOFPCCONFIG                                                                    STD_ON
#define CSM_RTECALLBACKOCCUREDOFPCCONFIG                                                            STD_ON
#define CSM_RTECALLBACKOFPCCONFIG                                                                   STD_ON
#define CSM_RTERESULTOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFBSWCALLBACKSOFPCCONFIG                                                            STD_ON
#define CSM_SIZEOFCALLOUTINFOOFPCCONFIG                                                             STD_ON
#define CSM_SIZEOFCALLOUTOFPCCONFIG                                                                 STD_ON
#define CSM_SIZEOFCALLOUTSTATEOFPCCONFIG                                                            STD_ON
#define CSM_SIZEOFJOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_SIZEOFJOBOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_SIZEOFJOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_SIZEOFKEYOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFPRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_SIZEOFQUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_SIZEOFQUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_SIZEOFQUEUESTATEOFPCCONFIG                                                              STD_ON
#define CSM_SIZEOFRTECALLBACKOFPCCONFIG                                                             STD_ON
#define CSM_SIZEOFRTERESULTOFPCCONFIG                                                               STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERALOFPCCONFIG                                                      STD_ON
#define CSM_USEDEPRECATEDOFGENERALOFPCCONFIG                                                        STD_ON
#define CSM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMinNumericValueDefines  Csm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CSM_MIN_CALLOUTSTATEOFCALLOUTSTATE                                                          0u
#define CSM_MIN_QUEUEIDXOFQUEUESTATE                                                                0u
#define CSM_MIN_RESERVEDINDEXESOFQUEUESTATE                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaxNumericValueDefines  Csm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CSM_MAX_CALLOUTSTATEOFCALLOUTSTATE                                                          255u
#define CSM_MAX_QUEUEIDXOFQUEUESTATE                                                                255u
#define CSM_MAX_RESERVEDINDEXESOFQUEUESTATE                                                         255u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCNoReferenceDefines  Csm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CSM_NO_BSWCALLBACKSIDXOFJOBTABLE                                                            255u
#define CSM_NO_CALLOUTINFOIDXOFJOBTABLE                                                             255u
#define CSM_NO_INOUTREDIRECTIONCONFIGIDXOFJOBTABLE                                                  255u
#define CSM_NO_INOUTREDIRECTIONIDXOFJOBTABLE                                                        255u
#define CSM_NO_RTECALLBACKIDXOFJOBTABLE                                                             255u
#define CSM_NO_EXPECTEDCOMPATIBILITYVERSION                                                         65535u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaskedBitDefines  Csm Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CSM_BSWCALLBACKSUSEDOFJOBTABLE_MASK                                                         0x08u
#define CSM_CALLOUTINFOUSEDOFJOBTABLE_MASK                                                          0x04u
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK                                      0x02u
#define CSM_RTECALLBACKUSEDOFJOBTABLE_MASK                                                          0x01u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIsReducedToDefineDefines  Csm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_CALLBACKFUNC43OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC44OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC45OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_POSTJOBCALLOUTFUNCOFCALLOUT                                                       STD_OFF
#define CSM_ISDEF_PREJOBCALLOUTFUNCOFCALLOUT                                                        STD_OFF
#define CSM_ISDEF_CALLOUTIDXOFCALLOUTINFO                                                           STD_OFF
#define CSM_ISDEF_JOBTABLEIDXOFCALLOUTINFO                                                          STD_OFF
#define CSM_ISDEF_DUMMYOFINOUTJOBREDIRECTIONTABLE                                                   STD_OFF
#define CSM_ISDEF_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                       STD_OFF
#define CSM_ISDEF_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                              STD_OFF
#define CSM_ISDEF_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF
#define CSM_ISDEF_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                  STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                              STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                             STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_JOBINFO                                                                           STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFO                                                                  STD_OFF
#define CSM_ISDEF_BSWCALLBACKSIDXOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_BSWCALLBACKSUSEDOFJOBTABLE                                                        STD_OFF
#define CSM_ISDEF_CALLOUTINFOIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_CALLOUTINFOUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CSMKEYIDIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONCONFIGIDXOFJOBTABLE                                               STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONCONFIGUSEDOFJOBTABLE                                              STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONIDXOFJOBTABLE                                                     STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONUSEDOFJOBTABLE                                                    STD_OFF
#define CSM_ISDEF_JOBINFOIDXOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                     STD_OFF
#define CSM_ISDEF_MASKEDBITSOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                     STD_OFF
#define CSM_ISDEF_PRIORITYOFJOBTABLE                                                                STD_OFF
#define CSM_ISDEF_QUEUEREFIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_RTECALLBACKIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_RTECALLBACKUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CRYIFKEYIDOFKEY                                                                   STD_OFF
#define CSM_ISDEF_USEPORTOFKEY                                                                      STD_OFF
#define CSM_ISDEF_PRIMITIVEINFO                                                                     STD_OFF
#define CSM_ISDEF_CHANNELIDOFQUEUEINFO                                                              STD_OFF
#define CSM_ISDEF_QUEUEENDIDXOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_QUEUELENGTHOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_QUEUESTARTIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                            STD_OFF
#define CSM_ISDEF_RTECALLBACK                                                                       STD_OFF
#define CSM_ISDEF_BSWCALLBACKSOFPCCONFIG                                                            STD_ON
#define CSM_ISDEF_CALLOUTINFOOFPCCONFIG                                                             STD_ON
#define CSM_ISDEF_CALLOUTOFPCCONFIG                                                                 STD_ON
#define CSM_ISDEF_CALLOUTSTATEOFPCCONFIG                                                            STD_ON
#define CSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF
#define CSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define CSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_JOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_ISDEF_JOBOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_JOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_ISDEF_JOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_ISDEF_KEYOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_PRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_ISDEF_QUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_ISDEF_QUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_ISDEF_QUEUESTATEOFPCCONFIG                                                              STD_ON
#define CSM_ISDEF_RTECALLBACKOCCUREDOFPCCONFIG                                                      STD_ON
#define CSM_ISDEF_RTECALLBACKOFPCCONFIG                                                             STD_ON
#define CSM_ISDEF_RTERESULTOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCEqualsAlwaysToDefines  Csm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_CALLBACKFUNC43OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC44OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC45OFBSWCALLBACKS                                                        
#define CSM_EQ2_POSTJOBCALLOUTFUNCOFCALLOUT                                                         
#define CSM_EQ2_PREJOBCALLOUTFUNCOFCALLOUT                                                          
#define CSM_EQ2_CALLOUTIDXOFCALLOUTINFO                                                             
#define CSM_EQ2_JOBTABLEIDXOFCALLOUTINFO                                                            
#define CSM_EQ2_DUMMYOFINOUTJOBREDIRECTIONTABLE                                                     
#define CSM_EQ2_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                         
#define CSM_EQ2_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                
#define CSM_EQ2_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                               
#define CSM_EQ2_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                    
#define CSM_EQ2_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                
#define CSM_EQ2_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                       
#define CSM_EQ2_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               
#define CSM_EQ2_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      
#define CSM_EQ2_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                 
#define CSM_EQ2_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_JOBINFO                                                                             
#define CSM_EQ2_JOBPRIMITIVEINFO                                                                    
#define CSM_EQ2_BSWCALLBACKSIDXOFJOBTABLE                                                           
#define CSM_EQ2_BSWCALLBACKSUSEDOFJOBTABLE                                                          
#define CSM_EQ2_CALLOUTINFOIDXOFJOBTABLE                                                            
#define CSM_EQ2_CALLOUTINFOUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CSMKEYIDIDXOFJOBTABLE                                                               
#define CSM_EQ2_INOUTREDIRECTIONCONFIGIDXOFJOBTABLE                                                 
#define CSM_EQ2_INOUTREDIRECTIONCONFIGUSEDOFJOBTABLE                                                
#define CSM_EQ2_INOUTREDIRECTIONIDXOFJOBTABLE                                                       
#define CSM_EQ2_INOUTREDIRECTIONUSEDOFJOBTABLE                                                      
#define CSM_EQ2_JOBINFOIDXOFJOBTABLE                                                                
#define CSM_EQ2_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                       
#define CSM_EQ2_MASKEDBITSOFJOBTABLE                                                                
#define CSM_EQ2_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                       
#define CSM_EQ2_PRIORITYOFJOBTABLE                                                                  
#define CSM_EQ2_QUEUEREFIDXOFJOBTABLE                                                               
#define CSM_EQ2_RTECALLBACKIDXOFJOBTABLE                                                            
#define CSM_EQ2_RTECALLBACKUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CRYIFKEYIDOFKEY                                                                     
#define CSM_EQ2_USEPORTOFKEY                                                                        
#define CSM_EQ2_PRIMITIVEINFO                                                                       
#define CSM_EQ2_CHANNELIDOFQUEUEINFO                                                                
#define CSM_EQ2_QUEUEENDIDXOFQUEUEINFO                                                              
#define CSM_EQ2_QUEUELENGTHOFQUEUEINFO                                                              
#define CSM_EQ2_QUEUESTARTIDXOFQUEUEINFO                                                            
#define CSM_EQ2_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                              
#define CSM_EQ2_RTECALLBACK                                                                         
#define CSM_EQ2_BSWCALLBACKSOFPCCONFIG                                                              Csm_BswCallbacks
#define CSM_EQ2_CALLOUTINFOOFPCCONFIG                                                               Csm_CalloutInfo
#define CSM_EQ2_CALLOUTOFPCCONFIG                                                                   Csm_Callout
#define CSM_EQ2_CALLOUTSTATEOFPCCONFIG                                                              Csm_CalloutState.raw
#define CSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                              
#define CSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                          
#define CSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                             
#define CSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                          
#define CSM_EQ2_JOBINFOOFPCCONFIG                                                                   Csm_JobInfo
#define CSM_EQ2_JOBOFPCCONFIG                                                                       Csm_Job.raw
#define CSM_EQ2_JOBPRIMITIVEINFOOFPCCONFIG                                                          Csm_JobPrimitiveInfo
#define CSM_EQ2_JOBTABLEOFPCCONFIG                                                                  Csm_JobTable
#define CSM_EQ2_KEYOFPCCONFIG                                                                       Csm_Key
#define CSM_EQ2_PRIMITIVEINFOOFPCCONFIG                                                             Csm_PrimitiveInfo
#define CSM_EQ2_QUEUEINFOOFPCCONFIG                                                                 Csm_QueueInfo
#define CSM_EQ2_QUEUEOFPCCONFIG                                                                     Csm_Queue.raw
#define CSM_EQ2_QUEUESTATEOFPCCONFIG                                                                Csm_QueueState
#define CSM_EQ2_RTECALLBACKOCCUREDOFPCCONFIG                                                        (&(Csm_RteCallbackOccured))
#define CSM_EQ2_RTECALLBACKOFPCCONFIG                                                               Csm_RteCallback
#define CSM_EQ2_RTERESULTOFPCCONFIG                                                                 Csm_RteResult.raw
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicInitializationPointers  Csm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Csm_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Csm' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCInitializationSymbols  Csm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Csm_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Csm */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGeneral  Csm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CSM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CSM_FINAL_MAGIC_NUMBER                                                                      0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Csm */
#define CSM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Csm' is not configured to be postbuild capable. */
#define CSM_INIT_DATA                                                                               CSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CSM_INIT_DATA_HASH_CODE                                                                     842809845  /**< the precompile constant to validate the initialization structure at initialization time of Csm with a hashcode. The seed value is '0xFF1Eu' */
#define CSM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CSM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Csm shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBDataSwitches  Csm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_PBCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBIsReducedToDefineDefines  Csm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                             STD_OFF
#define CSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBEqualsAlwaysToDefines  Csm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                               
#define CSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                               
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
  \defgroup  CsmPCGetRootDataMacros  Csm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetConstantDuplicatedRootDataMacros  Csm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         32u
#define Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          1024u
#define Csm_GetBswCallbacksOfPCConfig()                                                             Csm_BswCallbacks  /**< the pointer to Csm_BswCallbacks */
#define Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define Csm_GetCalloutInfoOfPCConfig()                                                              Csm_CalloutInfo  /**< the pointer to Csm_CalloutInfo */
#define Csm_GetCalloutOfPCConfig()                                                                  Csm_Callout  /**< the pointer to Csm_Callout */
#define Csm_GetCalloutStateOfPCConfig()                                                             Csm_CalloutState.raw  /**< the pointer to Csm_CalloutState */
#define Csm_GetJobInfoOfPCConfig()                                                                  Csm_JobInfo  /**< the pointer to Csm_JobInfo */
#define Csm_GetJobOfPCConfig()                                                                      Csm_Job.raw  /**< the pointer to Csm_Job */
#define Csm_GetJobPrimitiveInfoOfPCConfig()                                                         Csm_JobPrimitiveInfo  /**< the pointer to Csm_JobPrimitiveInfo */
#define Csm_GetJobTableOfPCConfig()                                                                 Csm_JobTable  /**< the pointer to Csm_JobTable */
#define Csm_GetKeyOfPCConfig()                                                                      Csm_Key  /**< the pointer to Csm_Key */
#define Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                              1u
#define Csm_GetPrimitiveInfoOfPCConfig()                                                            Csm_PrimitiveInfo  /**< the pointer to Csm_PrimitiveInfo */
#define Csm_GetQueueInfoOfPCConfig()                                                                Csm_QueueInfo  /**< the pointer to Csm_QueueInfo */
#define Csm_GetQueueOfPCConfig()                                                                    Csm_Queue.raw  /**< the pointer to Csm_Queue */
#define Csm_GetQueueStateOfPCConfig()                                                               Csm_QueueState  /**< the pointer to Csm_QueueState */
#define Csm_GetRteCallbackOccuredOfPCConfig()                                                       (&(Csm_RteCallbackOccured))  /**< the pointer to Csm_RteCallbackOccured */
#define Csm_GetRteCallbackOfPCConfig()                                                              Csm_RteCallback  /**< the pointer to Csm_RteCallback */
#define Csm_GetRteResultOfPCConfig()                                                                Csm_RteResult.raw  /**< the pointer to Csm_RteResult */
#define Csm_GetSizeOfBswCallbacksOfPCConfig()                                                       3u  /**< the number of accomplishable value elements in Csm_BswCallbacks */
#define Csm_GetSizeOfCalloutInfoOfPCConfig()                                                        25u  /**< the number of accomplishable value elements in Csm_CalloutInfo */
#define Csm_GetSizeOfCalloutOfPCConfig()                                                            4u  /**< the number of accomplishable value elements in Csm_Callout */
#define Csm_GetSizeOfJobInfoOfPCConfig()                                                            27u  /**< the number of accomplishable value elements in Csm_JobInfo */
#define Csm_GetSizeOfJobOfPCConfig()                                                                27u  /**< the number of accomplishable value elements in Csm_Job */
#define Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()                                                   27u  /**< the number of accomplishable value elements in Csm_JobPrimitiveInfo */
#define Csm_GetSizeOfJobTableOfPCConfig()                                                           27u  /**< the number of accomplishable value elements in Csm_JobTable */
#define Csm_GetSizeOfKeyOfPCConfig()                                                                7u  /**< the number of accomplishable value elements in Csm_Key */
#define Csm_GetSizeOfPrimitiveInfoOfPCConfig()                                                      10u  /**< the number of accomplishable value elements in Csm_PrimitiveInfo */
#define Csm_GetSizeOfQueueInfoOfPCConfig()                                                          5u  /**< the number of accomplishable value elements in Csm_QueueInfo */
#define Csm_GetSizeOfQueueOfPCConfig()                                                              22u  /**< the number of accomplishable value elements in Csm_Queue */
#define Csm_GetSizeOfRteCallbackOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Csm_RteCallback */
#define Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()                                                 16u
#define Csm_IsUseDeprecatedOfGeneralOfPCConfig()                                                    (((FALSE)) != FALSE)
#define Csm_IsVersionInfoApiOfGeneralOfPCConfig()                                                   (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDuplicatedRootDataMacros  Csm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Csm_GetSizeOfCalloutStateOfPCConfig()                                                       Csm_GetSizeOfCalloutInfoOfPCConfig()  /**< the number of accomplishable value elements in Csm_CalloutState */
#define Csm_GetSizeOfQueueStateOfPCConfig()                                                         Csm_GetSizeOfQueueInfoOfPCConfig()  /**< the number of accomplishable value elements in Csm_QueueState */
#define Csm_GetSizeOfRteResultOfPCConfig()                                                          Csm_GetSizeOfRteCallbackOfPCConfig()  /**< the number of accomplishable value elements in Csm_RteResult */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDataMacros  Csm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Csm_GetCallbackFunc43OfBswCallbacks(Index)                                                  (Csm_GetBswCallbacksOfPCConfig()[(Index)].CallbackFunc43OfBswCallbacks)
#define Csm_GetCallbackFunc44OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_GetCallbackFunc45OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define Csm_GetPostJobCalloutFuncOfCallout(Index)                                                   (Csm_GetCalloutOfPCConfig()[(Index)].PostJobCalloutFuncOfCallout)
#define Csm_GetPreJobCalloutFuncOfCallout(Index)                                                    (Csm_GetCalloutOfPCConfig()[(Index)].PreJobCalloutFuncOfCallout)
#define Csm_GetCalloutIdxOfCalloutInfo(Index)                                                       (Csm_GetCalloutInfoOfPCConfig()[(Index)].CalloutIdxOfCalloutInfo)
#define Csm_GetJobTableIdxOfCalloutInfo(Index)                                                      (Csm_GetCalloutInfoOfPCConfig()[(Index)].JobTableIdxOfCalloutInfo)
#define Csm_GetCalloutStateOfCalloutState(Index)                                                    (Csm_GetCalloutStateOfPCConfig()[(Index)].CalloutStateOfCalloutState)
#define Csm_IsDummyOfInOutJobRedirectionTable(Index)                                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.Dummy' Reason: 'Not enabled for any job' */
#define Csm_GetInputKeyElementIdOfInOutJobRedirectionTable(Index)                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetInputKeyIdOfInOutJobRedirectionTable(Index)                                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyElementIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyIdOfInOutJobRedirectionTable(Index)                                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetRedirectionConfigValueOfInOutJobRedirectionTable(Index)                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyIdOfInOutJobRedirectionTable(Index)                                   /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyElementIdOfInOutJobRedirectionTable(Index)                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyIdOfInOutJobRedirectionTable(Index)                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetJob(Index)                                                                           (Csm_GetJobOfPCConfig()[(Index)])
#define Csm_GetJobInfo(Index)                                                                       (Csm_GetJobInfoOfPCConfig()[(Index)])
#define Csm_GetJobPrimitiveInfo(Index)                                                              (Csm_GetJobPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetBswCallbacksIdxOfJobTable(Index)                                                     (Csm_GetJobTableOfPCConfig()[(Index)].BswCallbacksIdxOfJobTable)
#define Csm_GetCalloutInfoIdxOfJobTable(Index)                                                      (Csm_GetJobTableOfPCConfig()[(Index)].CalloutInfoIdxOfJobTable)
#define Csm_GetCsmKeyIdIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].CsmKeyIdIdxOfJobTable)
#define Csm_GetInOutRedirectionConfigIdxOfJobTable(Index)                                             /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigIdx' Reason: 'Not enabled for any job' */
#define Csm_IsInOutRedirectionConfigUsedOfJobTable(Index)                                             /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigUsed' Reason: 'Not enabled for any job' */
#define Csm_GetInOutRedirectionIdxOfJobTable(Index)                                                   /**< Deactivateable: 'Csm_JobTable.InOutRedirectionIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsInOutRedirectionUsedOfJobTable(Index)                                                   /**< Deactivateable: 'Csm_JobTable.InOutRedirectionUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetMaskedBitsOfJobTable(Index)                                                          (Csm_GetJobTableOfPCConfig()[(Index)].MaskedBitsOfJobTable)
#define Csm_GetPriorityOfJobTable(Index)                                                            (Csm_GetJobTableOfPCConfig()[(Index)].PriorityOfJobTable)
#define Csm_GetQueueRefIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].QueueRefIdxOfJobTable)
#define Csm_GetRteCallbackIdxOfJobTable(Index)                                                      (Csm_GetJobTableOfPCConfig()[(Index)].RteCallbackIdxOfJobTable)
#define Csm_GetCryIfKeyIdOfKey(Index)                                                               (Csm_GetKeyOfPCConfig()[(Index)].CryIfKeyIdOfKey)
#define Csm_IsUsePortOfKey(Index)                                                                   ((Csm_GetKeyOfPCConfig()[(Index)].UsePortOfKey) != FALSE)
#define Csm_GetPrimitiveInfo(Index)                                                                 (Csm_GetPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetQueue(Index)                                                                         (Csm_GetQueueOfPCConfig()[(Index)])
#define Csm_GetChannelIdOfQueueInfo(Index)                                                          (Csm_GetQueueInfoOfPCConfig()[(Index)].ChannelIdOfQueueInfo)
#define Csm_GetQueueEndIdxOfQueueInfo(Index)                                                        (Csm_GetQueueInfoOfPCConfig()[(Index)].QueueEndIdxOfQueueInfo)
#define Csm_GetQueueLengthOfQueueInfo(Index)                                                        (Csm_GetQueueInfoOfPCConfig()[(Index)].QueueLengthOfQueueInfo)
#define Csm_GetQueueStartIdxOfQueueInfo(Index)                                                      (Csm_GetQueueInfoOfPCConfig()[(Index)].QueueStartIdxOfQueueInfo)
#define Csm_IsTriggerAsynchJobsInCallbackOfQueueInfo(Index)                                         ((Csm_GetQueueInfoOfPCConfig()[(Index)].TriggerAsynchJobsInCallbackOfQueueInfo) != FALSE)
#define Csm_IsPauseProcessingOfQueueState(Index)                                                    ((Csm_GetQueueStateOfPCConfig()[(Index)].PauseProcessingOfQueueState) != FALSE)
#define Csm_GetQueueIdxOfQueueState(Index)                                                          (Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState)
#define Csm_GetReservedIndexesOfQueueState(Index)                                                   (Csm_GetQueueStateOfPCConfig()[(Index)].ReservedIndexesOfQueueState)
#define Csm_IsSortNeededOfQueueState(Index)                                                         ((Csm_GetQueueStateOfPCConfig()[(Index)].SortNeededOfQueueState) != FALSE)
#define Csm_GetRteCallback(Index)                                                                   (Csm_GetRteCallbackOfPCConfig()[(Index)])
#define Csm_IsRteCallbackOccured()                                                                  (((*(Csm_GetRteCallbackOccuredOfPCConfig()))) != FALSE)
#define Csm_GetRteResult(Index)                                                                     (Csm_GetRteResultOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetBitDataMacros  Csm Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)                                  (CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK == (Csm_GetMaskedBitsOfJobTable(Index) & CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK))  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPrimitiveCallbackUpdateNotification. */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDeduplicatedDataMacros  Csm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneral()                                                   Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_GetAsymPublicKeyMaxLengthOfGeneral()                                                    Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsCallbackStartNotificationOfGeneral()                                                  Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()
#define Csm_GetExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_IsBswCallbacksUsedOfJobTable(Index)                                                     (((boolean)(Csm_GetBswCallbacksIdxOfJobTable(Index) != CSM_NO_BSWCALLBACKSIDXOFJOBTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_BswCallbacks */
#define Csm_IsCalloutInfoUsedOfJobTable(Index)                                                      (((boolean)(Csm_GetCalloutInfoIdxOfJobTable(Index) != CSM_NO_CALLOUTINFOIDXOFJOBTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_CalloutInfo */
#define Csm_GetJobInfoIdxOfJobTable(Index)                                                          ((Csm_JobInfoIdxOfJobTableType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_JobInfo */
#define Csm_GetJobPrimitiveInfoIdxOfJobTable(Index)                                                 ((Csm_JobPrimitiveInfoIdxOfJobTableType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo */
#define Csm_IsRteCallbackUsedOfJobTable(Index)                                                      (((boolean)(Csm_GetRteCallbackIdxOfJobTable(Index) != CSM_NO_RTECALLBACKIDXOFJOBTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_RteCallback */
#define Csm_GetMainFunctionPeriodOfGeneral()                                                        Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Csm_GetSizeOfBswCallbacks()                                                                 Csm_GetSizeOfBswCallbacksOfPCConfig()
#define Csm_GetSizeOfCallout()                                                                      Csm_GetSizeOfCalloutOfPCConfig()
#define Csm_GetSizeOfCalloutInfo()                                                                  Csm_GetSizeOfCalloutInfoOfPCConfig()
#define Csm_GetSizeOfCalloutState()                                                                 Csm_GetSizeOfCalloutStateOfPCConfig()
#define Csm_GetSizeOfJob()                                                                          Csm_GetSizeOfJobOfPCConfig()
#define Csm_GetSizeOfJobInfo()                                                                      Csm_GetSizeOfJobInfoOfPCConfig()
#define Csm_GetSizeOfJobPrimitiveInfo()                                                             Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfJobTable()                                                                     Csm_GetSizeOfJobTableOfPCConfig()
#define Csm_GetSizeOfKey()                                                                          Csm_GetSizeOfKeyOfPCConfig()
#define Csm_GetSizeOfPrimitiveInfo()                                                                Csm_GetSizeOfPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfQueue()                                                                        Csm_GetSizeOfQueueOfPCConfig()
#define Csm_GetSizeOfQueueInfo()                                                                    Csm_GetSizeOfQueueInfoOfPCConfig()
#define Csm_GetSizeOfQueueState()                                                                   Csm_GetSizeOfQueueStateOfPCConfig()
#define Csm_GetSizeOfRteCallback()                                                                  Csm_GetSizeOfRteCallbackOfPCConfig()
#define Csm_GetSizeOfRteResult()                                                                    Csm_GetSizeOfRteResultOfPCConfig()
#define Csm_GetSymKeyMaxLengthOfGeneral()                                                           Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsUseDeprecatedOfGeneral()                                                              Csm_IsUseDeprecatedOfGeneralOfPCConfig()
#define Csm_IsVersionInfoApiOfGeneral()                                                             Csm_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSetDataMacros  Csm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Csm_SetCalloutStateOfCalloutState(Index, Value)                                             Csm_GetCalloutStateOfPCConfig()[(Index)].CalloutStateOfCalloutState = (Value)
#define Csm_SetInOutRedirection(Index, Value)                                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_SetJob(Index, Value)                                                                    Csm_GetJobOfPCConfig()[(Index)] = (Value)
#define Csm_SetQueue(Index, Value)                                                                  Csm_GetQueueOfPCConfig()[(Index)] = (Value)
#define Csm_SetPauseProcessingOfQueueState(Index, Value)                                            Csm_GetQueueStateOfPCConfig()[(Index)].PauseProcessingOfQueueState = (Value)
#define Csm_SetQueueIdxOfQueueState(Index, Value)                                                   Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState = (Value)
#define Csm_SetReservedIndexesOfQueueState(Index, Value)                                            Csm_GetQueueStateOfPCConfig()[(Index)].ReservedIndexesOfQueueState = (Value)
#define Csm_SetSortNeededOfQueueState(Index, Value)                                                 Csm_GetQueueStateOfPCConfig()[(Index)].SortNeededOfQueueState = (Value)
#define Csm_SetRteCallbackOccured(Value)                                                            (*(Csm_GetRteCallbackOccuredOfPCConfig())) = (Value)
#define Csm_SetRteResult(Index, Value)                                                              Csm_GetRteResultOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetAddressOfDataMacros  Csm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Csm_GetAddrJob(Index)                                                                       (&Csm_GetJob(Index))
#define Csm_GetAddrJobInfo(Index)                                                                   (&Csm_GetJobInfo(Index))
#define Csm_GetAddrJobPrimitiveInfo(Index)                                                          (&Csm_GetJobPrimitiveInfo(Index))
#define Csm_GetAddrPrimitiveInfo(Index)                                                             (&Csm_GetPrimitiveInfo(Index))
#define Csm_GetAddrQueue(Index)                                                                     (&Csm_GetQueue(Index))
#define Csm_GetAddrRteResult(Index)                                                                 (&Csm_GetRteResult(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCHasMacros  Csm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneral()                                                   (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneral()                                                    (TRUE != FALSE)
#define Csm_HasBswCallbacks()                                                                       (TRUE != FALSE)
#define Csm_HasCallbackFunc43OfBswCallbacks()                                                       (TRUE != FALSE)
#define Csm_HasCallbackFunc44OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_HasCallbackFunc45OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define Csm_HasCallbackStartNotificationOfGeneral()                                                 (TRUE != FALSE)
#define Csm_HasCallout()                                                                            (TRUE != FALSE)
#define Csm_HasPostJobCalloutFuncOfCallout()                                                        (TRUE != FALSE)
#define Csm_HasPreJobCalloutFuncOfCallout()                                                         (TRUE != FALSE)
#define Csm_HasCalloutInfo()                                                                        (TRUE != FALSE)
#define Csm_HasCalloutIdxOfCalloutInfo()                                                            (TRUE != FALSE)
#define Csm_HasJobTableIdxOfCalloutInfo()                                                           (TRUE != FALSE)
#define Csm_HasCalloutState()                                                                       (TRUE != FALSE)
#define Csm_HasCalloutStateOfCalloutState()                                                         (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasInOutJobRedirectionTable()                                                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define Csm_HasDummyOfInOutJobRedirectionTable()                                                      /**< Deactivateable: 'Csm_InOutJobRedirectionTable.Dummy' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyElementIdOfInOutJobRedirectionTable()                                          /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyIdOfInOutJobRedirectionTable()                                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyElementIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyIdOfInOutJobRedirectionTable()                                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasRedirectionConfigValueOfInOutJobRedirectionTable()                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyElementIdOfInOutJobRedirectionTable()                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyIdOfInOutJobRedirectionTable()                                        /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyElementIdOfInOutJobRedirectionTable()                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyIdOfInOutJobRedirectionTable()                                       /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyElementIdOfInOutJobRedirectionTable()                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasInOutRedirection()                                                                     /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasJob()                                                                                (TRUE != FALSE)
#define Csm_HasJobInfo()                                                                            (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfo()                                                                   (TRUE != FALSE)
#define Csm_HasJobTable()                                                                           (TRUE != FALSE)
#define Csm_HasBswCallbacksIdxOfJobTable()                                                          (TRUE != FALSE)
#define Csm_HasBswCallbacksUsedOfJobTable()                                                         (TRUE != FALSE)
#define Csm_HasCalloutInfoIdxOfJobTable()                                                           (TRUE != FALSE)
#define Csm_HasCalloutInfoUsedOfJobTable()                                                          (TRUE != FALSE)
#define Csm_HasCsmKeyIdIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasInOutRedirectionConfigIdxOfJobTable()                                                  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigIdx' Reason: 'Not enabled for any job' */
#define Csm_HasInOutRedirectionConfigUsedOfJobTable()                                                 /**< Deactivateable: 'Csm_JobTable.InOutRedirectionConfigUsed' Reason: 'Not enabled for any job' */
#define Csm_HasInOutRedirectionIdxOfJobTable()                                                        /**< Deactivateable: 'Csm_JobTable.InOutRedirectionIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasInOutRedirectionUsedOfJobTable()                                                       /**< Deactivateable: 'Csm_JobTable.InOutRedirectionUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasJobInfoIdxOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoIdxOfJobTable()                                                      (TRUE != FALSE)
#define Csm_HasMaskedBitsOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasPrimitiveCallbackUpdateNotificationOfJobTable()                                      (TRUE != FALSE)
#define Csm_HasPriorityOfJobTable()                                                                 (TRUE != FALSE)
#define Csm_HasQueueRefIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasRteCallbackIdxOfJobTable()                                                           (TRUE != FALSE)
#define Csm_HasRteCallbackUsedOfJobTable()                                                          (TRUE != FALSE)
#define Csm_HasKey()                                                                                (TRUE != FALSE)
#define Csm_HasCryIfKeyIdOfKey()                                                                    (TRUE != FALSE)
#define Csm_HasUsePortOfKey()                                                                       (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneral()                                                        (TRUE != FALSE)
#define Csm_HasPrimitiveInfo()                                                                      (TRUE != FALSE)
#define Csm_HasQueue()                                                                              (TRUE != FALSE)
#define Csm_HasQueueInfo()                                                                          (TRUE != FALSE)
#define Csm_HasChannelIdOfQueueInfo()                                                               (TRUE != FALSE)
#define Csm_HasQueueEndIdxOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasQueueLengthOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasQueueStartIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasTriggerAsynchJobsInCallbackOfQueueInfo()                                             (TRUE != FALSE)
#define Csm_HasQueueState()                                                                         (TRUE != FALSE)
#define Csm_HasPauseProcessingOfQueueState()                                                        (TRUE != FALSE)
#define Csm_HasQueueIdxOfQueueState()                                                               (TRUE != FALSE)
#define Csm_HasReservedIndexesOfQueueState()                                                        (TRUE != FALSE)
#define Csm_HasSortNeededOfQueueState()                                                             (TRUE != FALSE)
#define Csm_HasRteCallback()                                                                        (TRUE != FALSE)
#define Csm_HasRteCallbackOccured()                                                                 (TRUE != FALSE)
#define Csm_HasRteResult()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfBswCallbacks()                                                                 (TRUE != FALSE)
#define Csm_HasSizeOfCallout()                                                                      (TRUE != FALSE)
#define Csm_HasSizeOfCalloutInfo()                                                                  (TRUE != FALSE)
#define Csm_HasSizeOfCalloutState()                                                                 (TRUE != FALSE)
#define Csm_HasSizeOfJob()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfJobInfo()                                                                      (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfo()                                                             (TRUE != FALSE)
#define Csm_HasSizeOfJobTable()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfKey()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfo()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfQueue()                                                                        (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfo()                                                                    (TRUE != FALSE)
#define Csm_HasSizeOfQueueState()                                                                   (TRUE != FALSE)
#define Csm_HasSizeOfRteCallback()                                                                  (TRUE != FALSE)
#define Csm_HasSizeOfRteResult()                                                                    (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneral()                                                           (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneral()                                                             (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneral()                                                            (TRUE != FALSE)
#define Csm_HasPCConfig()                                                                           (TRUE != FALSE)
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define Csm_HasBswCallbacksOfPCConfig()                                                             (TRUE != FALSE)
#define Csm_HasCallbackStartNotificationOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Csm_HasCalloutInfoOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasCalloutOfPCConfig()                                                                  (TRUE != FALSE)
#define Csm_HasCalloutStateOfPCConfig()                                                             (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasJobInfoOfPCConfig()                                                                  (TRUE != FALSE)
#define Csm_HasJobOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasJobTableOfPCConfig()                                                                 (TRUE != FALSE)
#define Csm_HasKeyOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define Csm_HasPrimitiveInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasQueueInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasQueueOfPCConfig()                                                                    (TRUE != FALSE)
#define Csm_HasQueueStateOfPCConfig()                                                               (TRUE != FALSE)
#define Csm_HasRteCallbackOccuredOfPCConfig()                                                       (TRUE != FALSE)
#define Csm_HasRteCallbackOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasRteResultOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfBswCallbacksOfPCConfig()                                                       (TRUE != FALSE)
#define Csm_HasSizeOfCalloutInfoOfPCConfig()                                                        (TRUE != FALSE)
#define Csm_HasSizeOfCalloutOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasSizeOfCalloutStateOfPCConfig()                                                       (TRUE != FALSE)
#define Csm_HasSizeOfJobInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasSizeOfJobOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfoOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasSizeOfJobTableOfPCConfig()                                                           (TRUE != FALSE)
#define Csm_HasSizeOfKeyOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Csm_HasSizeOfQueueOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasSizeOfQueueStateOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasSizeOfRteCallbackOfPCConfig()                                                        (TRUE != FALSE)
#define Csm_HasSizeOfRteResultOfPCConfig()                                                          (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneralOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneralOfPCConfig()                                                  (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIncrementDataMacros  Csm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Csm_IncCalloutStateOfCalloutState(Index)                                                    Csm_GetCalloutStateOfCalloutState(Index)++
#define Csm_IncInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_IncJob(Index)                                                                           Csm_GetJob(Index)++
#define Csm_IncQueue(Index)                                                                         Csm_GetQueue(Index)++
#define Csm_IncQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)++
#define Csm_IncReservedIndexesOfQueueState(Index)                                                   Csm_GetReservedIndexesOfQueueState(Index)++
#define Csm_IncRteResult(Index)                                                                     Csm_GetRteResult(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCDecrementDataMacros  Csm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Csm_DecCalloutStateOfCalloutState(Index)                                                    Csm_GetCalloutStateOfCalloutState(Index)--
#define Csm_DecInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_DecJob(Index)                                                                           Csm_GetJob(Index)--
#define Csm_DecQueue(Index)                                                                         Csm_GetQueue(Index)--
#define Csm_DecQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)--
#define Csm_DecReservedIndexesOfQueueState(Index)                                                   Csm_GetReservedIndexesOfQueueState(Index)--
#define Csm_DecRteResult(Index)                                                                     Csm_GetRteResult(Index)--
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBGetRootDataMacros  Csm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_GetPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBHasMacros  Csm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasPBConfig()                                                                             /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2VAR(Crypto_JobType, AUTOMATIC, CSM_VAR_NOINIT) Csm_QueueElementType;
typedef uint8 Csm_JobCalloutStateType;
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc43Type)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc44Type)(const uint32 jobID, Csm_ResultType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc45Type)(P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Crypto_ResultType result);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PreJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PostJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);
typedef P2FUNC (Std_ReturnType, RTE_CODE, Csm_RteCallbackFuncType)(Csm_ResultType result);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCIterableTypes  Csm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Csm_BswCallbacks */
typedef uint8_least Csm_BswCallbacksIterType;

/**   \brief  type used to iterate Csm_Callout */
typedef uint8_least Csm_CalloutIterType;

/**   \brief  type used to iterate Csm_CalloutInfo */
typedef uint8_least Csm_CalloutInfoIterType;

/**   \brief  type used to iterate Csm_Job */
typedef uint8_least Csm_JobIterType;

/**   \brief  type used to iterate Csm_JobInfo */
typedef uint8_least Csm_JobInfoIterType;

/**   \brief  type used to iterate Csm_JobPrimitiveInfo */
typedef uint8_least Csm_JobPrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_JobTable */
typedef uint8_least Csm_JobTableIterType;

/**   \brief  type used to iterate Csm_Key */
typedef uint8_least Csm_KeyIterType;

/**   \brief  type used to iterate Csm_PrimitiveInfo */
typedef uint8_least Csm_PrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_Queue */
typedef uint8_least Csm_QueueIterType;

/**   \brief  type used to iterate Csm_QueueInfo */
typedef uint8_least Csm_QueueInfoIterType;

/**   \brief  type used to iterate Csm_RteCallback */
typedef uint8_least Csm_RteCallbackIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIterableTypesWithSizeRelations  Csm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Csm_CalloutState */
typedef Csm_CalloutInfoIterType Csm_CalloutStateIterType;

/**   \brief  type used to iterate Csm_QueueState */
typedef Csm_QueueInfoIterType Csm_QueueStateIterType;

/**   \brief  type used to iterate Csm_RteResult */
typedef Csm_RteCallbackIterType Csm_RteResultIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCValueTypes  Csm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Csm_AsymPrivateKeyMaxLengthOfGeneral */
typedef uint8 Csm_AsymPrivateKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_AsymPublicKeyMaxLengthOfGeneral */
typedef uint16 Csm_AsymPublicKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_CallbackStartNotificationOfGeneral */
typedef boolean Csm_CallbackStartNotificationOfGeneralType;

/**   \brief  value based type definition for Csm_CalloutIdxOfCalloutInfo */
typedef uint8 Csm_CalloutIdxOfCalloutInfoType;

/**   \brief  value based type definition for Csm_JobTableIdxOfCalloutInfo */
typedef uint8 Csm_JobTableIdxOfCalloutInfoType;

/**   \brief  value based type definition for Csm_CalloutStateOfCalloutState */
typedef uint8 Csm_CalloutStateOfCalloutStateType;

/**   \brief  value based type definition for Csm_BswCallbacksIdxOfJobTable */
typedef uint8 Csm_BswCallbacksIdxOfJobTableType;

/**   \brief  value based type definition for Csm_BswCallbacksUsedOfJobTable */
typedef boolean Csm_BswCallbacksUsedOfJobTableType;

/**   \brief  value based type definition for Csm_CalloutInfoIdxOfJobTable */
typedef uint8 Csm_CalloutInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_CalloutInfoUsedOfJobTable */
typedef boolean Csm_CalloutInfoUsedOfJobTableType;

/**   \brief  value based type definition for Csm_CsmKeyIdIdxOfJobTable */
typedef uint8 Csm_CsmKeyIdIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobInfoIdxOfJobTable */
typedef uint8 Csm_JobInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobPrimitiveInfoIdxOfJobTable */
typedef uint8 Csm_JobPrimitiveInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_MaskedBitsOfJobTable */
typedef uint8 Csm_MaskedBitsOfJobTableType;

/**   \brief  value based type definition for Csm_PrimitiveCallbackUpdateNotificationOfJobTable */
typedef boolean Csm_PrimitiveCallbackUpdateNotificationOfJobTableType;

/**   \brief  value based type definition for Csm_PriorityOfJobTable */
typedef uint8 Csm_PriorityOfJobTableType;

/**   \brief  value based type definition for Csm_QueueRefIdxOfJobTable */
typedef uint8 Csm_QueueRefIdxOfJobTableType;

/**   \brief  value based type definition for Csm_RteCallbackIdxOfJobTable */
typedef uint8 Csm_RteCallbackIdxOfJobTableType;

/**   \brief  value based type definition for Csm_RteCallbackUsedOfJobTable */
typedef boolean Csm_RteCallbackUsedOfJobTableType;

/**   \brief  value based type definition for Csm_CryIfKeyIdOfKey */
typedef uint32 Csm_CryIfKeyIdOfKeyType;

/**   \brief  value based type definition for Csm_UsePortOfKey */
typedef boolean Csm_UsePortOfKeyType;

/**   \brief  value based type definition for Csm_MainFunctionPeriodOfGeneral */
typedef uint8 Csm_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Csm_ChannelIdOfQueueInfo */
typedef uint32 Csm_ChannelIdOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueEndIdxOfQueueInfo */
typedef uint8 Csm_QueueEndIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueLengthOfQueueInfo */
typedef uint8 Csm_QueueLengthOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueStartIdxOfQueueInfo */
typedef uint8 Csm_QueueStartIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_TriggerAsynchJobsInCallbackOfQueueInfo */
typedef boolean Csm_TriggerAsynchJobsInCallbackOfQueueInfoType;

/**   \brief  value based type definition for Csm_PauseProcessingOfQueueState */
typedef boolean Csm_PauseProcessingOfQueueStateType;

/**   \brief  value based type definition for Csm_QueueIdxOfQueueState */
typedef uint8 Csm_QueueIdxOfQueueStateType;

/**   \brief  value based type definition for Csm_ReservedIndexesOfQueueState */
typedef uint8 Csm_ReservedIndexesOfQueueStateType;

/**   \brief  value based type definition for Csm_SortNeededOfQueueState */
typedef boolean Csm_SortNeededOfQueueStateType;

/**   \brief  value based type definition for Csm_RteCallbackOccured */
typedef boolean Csm_RteCallbackOccuredType;

/**   \brief  value based type definition for Csm_SizeOfBswCallbacks */
typedef uint8 Csm_SizeOfBswCallbacksType;

/**   \brief  value based type definition for Csm_SizeOfCallout */
typedef uint8 Csm_SizeOfCalloutType;

/**   \brief  value based type definition for Csm_SizeOfCalloutInfo */
typedef uint8 Csm_SizeOfCalloutInfoType;

/**   \brief  value based type definition for Csm_SizeOfCalloutState */
typedef uint8 Csm_SizeOfCalloutStateType;

/**   \brief  value based type definition for Csm_SizeOfJob */
typedef uint8 Csm_SizeOfJobType;

/**   \brief  value based type definition for Csm_SizeOfJobInfo */
typedef uint8 Csm_SizeOfJobInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobPrimitiveInfo */
typedef uint8 Csm_SizeOfJobPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobTable */
typedef uint8 Csm_SizeOfJobTableType;

/**   \brief  value based type definition for Csm_SizeOfKey */
typedef uint8 Csm_SizeOfKeyType;

/**   \brief  value based type definition for Csm_SizeOfPrimitiveInfo */
typedef uint8 Csm_SizeOfPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueue */
typedef uint8 Csm_SizeOfQueueType;

/**   \brief  value based type definition for Csm_SizeOfQueueInfo */
typedef uint8 Csm_SizeOfQueueInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueueState */
typedef uint8 Csm_SizeOfQueueStateType;

/**   \brief  value based type definition for Csm_SizeOfRteCallback */
typedef uint8 Csm_SizeOfRteCallbackType;

/**   \brief  value based type definition for Csm_SizeOfRteResult */
typedef uint8 Csm_SizeOfRteResultType;

/**   \brief  value based type definition for Csm_SymKeyMaxLengthOfGeneral */
typedef uint8 Csm_SymKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_UseDeprecatedOfGeneral */
typedef boolean Csm_UseDeprecatedOfGeneralType;

/**   \brief  value based type definition for Csm_VersionInfoApiOfGeneral */
typedef boolean Csm_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCStructTypes  Csm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Csm_BswCallbacks */
typedef struct sCsm_BswCallbacksType
{
  Csm_CallbackFunc43Type CallbackFunc43OfBswCallbacks;
} Csm_BswCallbacksType;

/**   \brief  type used in Csm_Callout */
typedef struct sCsm_CalloutType
{
  Csm_PostJobCalloutFunc PostJobCalloutFuncOfCallout;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPostJobCalloutFunc. */
  Csm_PreJobCalloutFunc PreJobCalloutFuncOfCallout;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPreJobCalloutFunc. */
} Csm_CalloutType;

/**   \brief  type used in Csm_CalloutInfo */
typedef struct sCsm_CalloutInfoType
{
  Csm_CalloutIdxOfCalloutInfoType CalloutIdxOfCalloutInfo;  /**< the index of the 1:1 relation pointing to Csm_Callout */
  Csm_JobTableIdxOfCalloutInfoType JobTableIdxOfCalloutInfo;  /**< the index of the 1:1 relation pointing to Csm_JobTable */
} Csm_CalloutInfoType;

/**   \brief  type used in Csm_CalloutState */
typedef struct sCsm_CalloutStateType
{
  Csm_CalloutStateOfCalloutStateType CalloutStateOfCalloutState;
} Csm_CalloutStateType;

/**   \brief  type used in Csm_JobTable */
typedef struct sCsm_JobTableType
{
  Csm_BswCallbacksIdxOfJobTableType BswCallbacksIdxOfJobTable;  /**< the index of the 0:1 relation pointing to Csm_BswCallbacks */
  Csm_CalloutInfoIdxOfJobTableType CalloutInfoIdxOfJobTable;  /**< the index of the 0:1 relation pointing to Csm_CalloutInfo */
  Csm_CsmKeyIdIdxOfJobTableType CsmKeyIdIdxOfJobTable;  /**< the index of the 1:1 relation pointing to one of Csm_Key */
  Csm_MaskedBitsOfJobTableType MaskedBitsOfJobTable;  /**< contains bitcoded the boolean data of Csm_BswCallbacksUsedOfJobTable, Csm_CalloutInfoUsedOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable, Csm_RteCallbackUsedOfJobTable */
  Csm_PriorityOfJobTableType PriorityOfJobTable;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority. */
  Csm_QueueRefIdxOfJobTableType QueueRefIdxOfJobTable;  /**< the index of the 1:1 relation pointing to one of Csm_QueueInfo */
  Csm_RteCallbackIdxOfJobTableType RteCallbackIdxOfJobTable;  /**< the index of the 0:1 relation pointing to Csm_RteCallback */
} Csm_JobTableType;

/**   \brief  type used in Csm_Key */
typedef struct sCsm_KeyType
{
  Csm_CryIfKeyIdOfKeyType CryIfKeyIdOfKey;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef. */
  Csm_UsePortOfKeyType UsePortOfKey;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyUsePort. */
} Csm_KeyType;

/**   \brief  type used in Csm_QueueInfo */
typedef struct sCsm_QueueInfoType
{
  Csm_ChannelIdOfQueueInfoType ChannelIdOfQueueInfo;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef. */
  Csm_TriggerAsynchJobsInCallbackOfQueueInfoType TriggerAsynchJobsInCallbackOfQueueInfo;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmTriggerAsynchJobsInCallback. */
  Csm_QueueEndIdxOfQueueInfoType QueueEndIdxOfQueueInfo;  /**< the end index of the 1:n relation pointing to Csm_Queue */
  Csm_QueueLengthOfQueueInfoType QueueLengthOfQueueInfo;  /**< the number of relations pointing to Csm_Queue */
  Csm_QueueStartIdxOfQueueInfoType QueueStartIdxOfQueueInfo;  /**< the start index of the 1:n relation pointing to Csm_Queue */
} Csm_QueueInfoType;

/**   \brief  type used in Csm_QueueState */
typedef struct sCsm_QueueStateType
{
  Csm_PauseProcessingOfQueueStateType PauseProcessingOfQueueState;
  Csm_QueueIdxOfQueueStateType QueueIdxOfQueueState;  /**< the index of the 1:1 relation pointing to Csm_Queue */
  Csm_ReservedIndexesOfQueueStateType ReservedIndexesOfQueueState;
  Csm_SortNeededOfQueueStateType SortNeededOfQueueState;
} Csm_QueueStateType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicStructTypes  Csm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Csm_CalloutState */
typedef struct Csm_CalloutStateStructSTag
{
  Csm_CalloutStateType CsmJob_CMAC_Verify_GW_SYNC_REQ;
  Csm_CalloutStateType CsmJob_Aes128_Decrypt;
  Csm_CalloutStateType CsmJob_Aes128_Encrypt;
  Csm_CalloutStateType CsmJob_KeySetValid;
  Csm_CalloutStateType CsmJob_CMAC_Generate_HUT15;
  Csm_CalloutStateType CsmJob_CMAC_Generate_HUT_FD1;
  Csm_CalloutStateType CsmJob_CMAC_Generate_HUT_IP2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ABM1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ACC_FD2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_AEB_FD2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_AMP2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_BCM1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_BCM3;
  Csm_CalloutStateType CsmJob_CMAC_Verify_DCT7;
  Csm_CalloutStateType CsmJob_CMAC_Verify_DCT_FD4;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ESP1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ESP2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ESP_FD1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_ESP_FD2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_IFC_FD2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_R_PBox1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_TPMS1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_TPMS2;
  Csm_CalloutStateType CsmJob_CMAC_Verify_T_Box_FD1;
  Csm_CalloutStateType CsmJob_CMAC_Verify_T_Box_FD3;
} Csm_CalloutStateStructSType;

/**   \brief  type to be used as symbolic data element access to Csm_Job */
typedef struct Csm_JobStructSTag
{
  Crypto_JobType CsmJob_Aes128_Decrypt;
  Crypto_JobType CsmJob_Aes128_Encrypt;
  Crypto_JobType CsmJob_CMAC_Generate_HUT15;
  Crypto_JobType CsmJob_CMAC_Generate_HUT_FD1;
  Crypto_JobType CsmJob_CMAC_Generate_HUT_IP2;
  Crypto_JobType CsmJob_CMAC_Verify_ABM1;
  Crypto_JobType CsmJob_CMAC_Verify_DCT_FD4;
  Crypto_JobType CsmJob_CMAC_Verify_ESP_FD1;
  Crypto_JobType CsmJob_CMAC_Verify_ACC_FD2;
  Crypto_JobType CsmJob_CMAC_Verify_AEB_FD2;
  Crypto_JobType CsmJob_CMAC_Verify_AMP2;
  Crypto_JobType CsmJob_CMAC_Verify_BCM1;
  Crypto_JobType CsmJob_CMAC_Verify_BCM3;
  Crypto_JobType CsmJob_CMAC_Verify_DCT7;
  Crypto_JobType CsmJob_CMAC_Verify_ESP1;
  Crypto_JobType CsmJob_CMAC_Verify_ESP2;
  Crypto_JobType CsmJob_CMAC_Verify_ESP_FD2;
  Crypto_JobType CsmJob_CMAC_Verify_GW_SYNC_REQ;
  Crypto_JobType CsmJob_CMAC_Verify_IFC_FD2;
  Crypto_JobType CsmJob_CMAC_Verify_R_PBox1;
  Crypto_JobType CsmJob_CMAC_Verify_TPMS1;
  Crypto_JobType CsmJob_CMAC_Verify_TPMS2;
  Crypto_JobType CsmJob_CMAC_Verify_T_Box_FD1;
  Crypto_JobType CsmJob_CMAC_Verify_T_Box_FD3;
  Crypto_JobType CsmJob_KeySetValid;
  Crypto_JobType CsmJob_Random;
  Crypto_JobType CsmJob_SecureBoot_Generate;
} Csm_JobStructSType;

/**   \brief  type to be used as symbolic data element access to Csm_Queue */
typedef struct Csm_QueueStructSTag
{
  Csm_QueueElementType CsmQueue_SecOC_Verify[16];
  Csm_QueueElementType CsmQueue;
  Csm_QueueElementType CsmQueue_KeySetValid;
  Csm_QueueElementType CsmQueue_SecOC_Generate[3];
  Csm_QueueElementType CsmQueue_AES128;
} Csm_QueueStructSType;

/**   \brief  type to be used as symbolic data element access to Csm_RteResult */
typedef struct Csm_RteResultStructSTag
{
  Std_ReturnType CsmJob_Aes128_Decrypt;
  Std_ReturnType CsmJob_Aes128_Encrypt;
} Csm_RteResultStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCUnionIndexAndSymbolTypes  Csm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Csm_CalloutState in an index and symbol based style. */
typedef union Csm_CalloutStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_CalloutStateType raw[25];
  Csm_CalloutStateStructSType str;
} Csm_CalloutStateUType;

/**   \brief  type to access Csm_Job in an index and symbol based style. */
typedef union Csm_JobUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_JobType raw[27];
  Csm_JobStructSType str;
} Csm_JobUType;

/**   \brief  type to access Csm_Queue in an index and symbol based style. */
typedef union Csm_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_QueueElementType raw[22];
  Csm_QueueStructSType str;
} Csm_QueueUType;

/**   \brief  type to access Csm_RteResult in an index and symbol based style. */
typedef union Csm_RteResultUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Std_ReturnType raw[2];
  Csm_RteResultStructSType str;
} Csm_RteResultUType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootPointerTypes  Csm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Csm_BswCallbacks */
typedef P2CONST(Csm_BswCallbacksType, TYPEDEF, CSM_CONST) Csm_BswCallbacksPtrType;

/**   \brief  type used to point to Csm_Callout */
typedef P2CONST(Csm_CalloutType, TYPEDEF, CSM_CONST) Csm_CalloutPtrType;

/**   \brief  type used to point to Csm_CalloutInfo */
typedef P2CONST(Csm_CalloutInfoType, TYPEDEF, CSM_CONST) Csm_CalloutInfoPtrType;

/**   \brief  type used to point to Csm_CalloutState */
typedef P2VAR(Csm_CalloutStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_CalloutStatePtrType;

/**   \brief  type used to point to Csm_Job */
typedef P2VAR(Crypto_JobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobPtrType;

/**   \brief  type used to point to Csm_JobInfo */
typedef P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) Csm_JobInfoPtrType;

/**   \brief  type used to point to Csm_JobPrimitiveInfo */
typedef P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_JobPrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_JobTable */
typedef P2CONST(Csm_JobTableType, TYPEDEF, CSM_CONST) Csm_JobTablePtrType;

/**   \brief  type used to point to Csm_Key */
typedef P2CONST(Csm_KeyType, TYPEDEF, CSM_CONST) Csm_KeyPtrType;

/**   \brief  type used to point to Csm_PrimitiveInfo */
typedef P2CONST(Crypto_PrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_PrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_Queue */
typedef P2VAR(Csm_QueueElementType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueuePtrType;

/**   \brief  type used to point to Csm_QueueInfo */
typedef P2CONST(Csm_QueueInfoType, TYPEDEF, CSM_CONST) Csm_QueueInfoPtrType;

/**   \brief  type used to point to Csm_QueueState */
typedef P2VAR(Csm_QueueStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueueStatePtrType;

/**   \brief  type used to point to Csm_RteCallback */
typedef P2CONST(Csm_RteCallbackFuncType, TYPEDEF, CSM_CONST) Csm_RteCallbackPtrType;

/**   \brief  type used to point to Csm_RteCallbackOccured */
typedef P2VAR(Csm_RteCallbackOccuredType, TYPEDEF, CSM_VAR_NOINIT) Csm_RteCallbackOccuredPtrType;

/**   \brief  type used to point to Csm_RteResult */
typedef P2VAR(Std_ReturnType, TYPEDEF, CSM_VAR_NOINIT) Csm_RteResultPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootValueTypes  Csm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Csm_PCConfig */
typedef struct sCsm_PCConfigType
{
  uint8 Csm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Csm_PCConfigType;

typedef Csm_PCConfigType Csm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBValueTypes  Csm Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBRootValueTypes  Csm Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
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
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc43
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[3];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Callout
**********************************************************************************************************************/
/** 
  \var    Csm_Callout
  \brief  Contains parameters of /MICROSAR/Csm/CsmCallouts/CsmCallout.
  \details
  Element               Description
  PostJobCalloutFunc    Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPostJobCalloutFunc.
  PreJobCalloutFunc     Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPreJobCalloutFunc.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_CalloutType, CSM_CONST) Csm_Callout[4];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_CalloutInfo
**********************************************************************************************************************/
/** 
  \var    Csm_CalloutInfo
  \brief  Reference Table to Callouts and Jobs
  \details
  Element        Description
  CalloutIdx     the index of the 1:1 relation pointing to Csm_Callout
  JobTableIdx    the index of the 1:1 relation pointing to Csm_JobTable
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_CalloutInfoType, CSM_CONST) Csm_CalloutInfo[25];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[27];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 secureCounterId; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType; const bool callbackUpdateNotification
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[27];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element            Description
  BswCallbacksIdx    the index of the 0:1 relation pointing to Csm_BswCallbacks
  CalloutInfoIdx     the index of the 0:1 relation pointing to Csm_CalloutInfo
  CsmKeyIdIdx        the index of the 1:1 relation pointing to one of Csm_Key
  MaskedBits         contains bitcoded the boolean data of Csm_BswCallbacksUsedOfJobTable, Csm_CalloutInfoUsedOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable, Csm_RteCallbackUsedOfJobTable
  Priority           Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx        the index of the 1:1 relation pointing to one of Csm_QueueInfo
  RteCallbackIdx     the index of the 0:1 relation pointing to Csm_RteCallback
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[27];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
  UsePort       Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyUsePort.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_KeyType, CSM_CONST) Csm_Key[7];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[10];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element                        Description
  ChannelId                      Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  TriggerAsynchJobsInCallback    Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmTriggerAsynchJobsInCallback.
  QueueEndIdx                    the end index of the 1:n relation pointing to Csm_Queue
  QueueLength                    the number of relations pointing to Csm_Queue
  QueueStartIdx                  the start index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteCallback
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_RteCallbackFuncType, CSM_CONST) Csm_RteCallback[2];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_CalloutState
**********************************************************************************************************************/
/** 
  \var    Csm_CalloutState
  \brief  Holds current state of the pre and post job callout processing.
  \details
  Element         Description
  CalloutState
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_CalloutStateUType, CSM_VAR_NOINIT) Csm_CalloutState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_JobUType, CSM_VAR_NOINIT) Csm_Job;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element            Description
  PauseProcessing
  QueueIdx           the index of the 1:1 relation pointing to Csm_Queue
  ReservedIndexes
  SortNeeded     
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[5];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteCallbackOccured
**********************************************************************************************************************/
/** 
  \var    Csm_RteCallbackOccured
  \brief  Variable which stores if a Callback for RTE occurred which needs to be handled in MainFunction.
*/ 
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_RteCallbackOccuredType, CSM_VAR_NOINIT) Csm_RteCallbackOccured;
#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteResult
**********************************************************************************************************************/
/** 
  \var    Csm_RteResult
  \brief  Contains the results of occurred callbacks which need to be delayed to MainFunction.
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_RteResultUType, CSM_VAR_NOINIT) Csm_RteResult;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




/* Callback Notification Prototypes */
extern FUNC(void, CSM_APPL_CODE) CsmJob_CMAC_Generate_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
extern FUNC(void, CSM_APPL_CODE) CsmJob_CMAC_Verify_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
extern FUNC(void, CSM_APPL_CODE) CsmJob_KeySetValid_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);

/* Pre-and Post-Job Callout Prototypes */
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOcSync_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOcSync_Callout_Post(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_Aes128_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_Aes128_Callout_Post(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SetKey_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SetKey_Callout_Post(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOc_CsmCallout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
extern FUNC(Std_ReturnType, CSM_APPL_CODE) CSM_SecOc_CsmCallout_Post(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);




#endif /* CSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.h
 *********************************************************************************************************************/

