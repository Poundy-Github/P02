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
 *            Module: LinTrcv
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LinTrcv_30_Tle7259_Cfg.h
 *   Generation Time: 2020-08-18 15:19:13
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/



/* PRQA S 0779, 0883 EOF */ /* MD_MSR_Rule5.2, MD_LINTRCV_0883 */

#if !defined(LINTRCV_30_TLE7259_CFG_H)
#define LINTRCV_30_TLE7259_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */
#include "EcuM_Cbk.h"
#include "Dio.h"

/* -----------------------------------------------------------------------------
    &&&~ Version defines
 ----------------------------------------------------------------------------- */
#define DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_MAJOR_VERSION 0x07u
#define DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_MINOR_VERSION 0x00u
#define DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_PATCH_VERSION 0x00u

/* -----------------------------------------------------------------------------
    &&&~ Defines
 ----------------------------------------------------------------------------- */
#define LINTRCV_30_TLE7259_GET_VERSION_INFO         STD_OFF
#define LINTRCV_30_TLE7259_DEV_ERROR_DETECT         STD_ON
#define LINTRCV_30_TLE7259_DEV_ERROR_REPORT         STD_ON

#define LINTRCV_30_TLE7259_CRC_CHECK                STD_OFF
#define LINTRCV_30_TLE7259_NROFCHANNELS             2
#define LINTRCV_30_TLE7259_INSTANCE_ID              0

#define LINTRCV_30_TLE7259_WAKEUPSUPPORT            STD_OFF

#define LINTRCV_30_TLE7259_WAIT_COUNT_USED          STD_OFF
#define LINTRCV_30_TLE7259_WAIT_COUNT               0

/**********************************************************************************************************************
 *  General Defines
 *********************************************************************************************************************/

#ifndef LINTRCV_30_TLE7259_USE_DUMMY_STATEMENT
#define LINTRCV_30_TLE7259_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINTRCV_30_TLE7259_DUMMY_STATEMENT
#define LINTRCV_30_TLE7259_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINTRCV_30_TLE7259_DUMMY_STATEMENT_CONST
#define LINTRCV_30_TLE7259_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINTRCV_30_TLE7259_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define LINTRCV_30_TLE7259_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef LINTRCV_30_TLE7259_ATOMIC_VARIABLE_ACCESS
#define LINTRCV_30_TLE7259_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef LINTRCV_30_TLE7259_PROCESSOR_RH850_1651
#define LINTRCV_30_TLE7259_PROCESSOR_RH850_1651
#endif
#ifndef LINTRCV_30_TLE7259_COMP_GREENHILLS
#define LINTRCV_30_TLE7259_COMP_GREENHILLS
#endif
#ifndef LINTRCV_30_TLE7259_GEN_GENERATOR_MSR
#define LINTRCV_30_TLE7259_GEN_GENERATOR_MSR
#endif
#ifndef LINTRCV_30_TLE7259_CPUTYPE_BITORDER_LSB2MSB
#define LINTRCV_30_TLE7259_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_PRECOMPILE
#define LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_LINKTIME
#define LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef LINTRCV_30_TLE7259_CONFIGURATION_VARIANT
#define LINTRCV_30_TLE7259_CONFIGURATION_VARIANT LINTRCV_30_TLE7259_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef LINTRCV_30_TLE7259_POSTBUILD_VARIANT_SUPPORT
#define LINTRCV_30_TLE7259_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/* -----------------------------------------------------------------------------
    &&&~ Structs
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinTrcv_30_Tle7259PCDataSwitches  LinTrcv_30_Tle7259 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINTRCV_30_TLE7259_CHANNEL                                                                  STD_ON
#define LINTRCV_30_TLE7259_CHANNELUSEDOFCHANNEL                                                     STD_ON
#define LINTRCV_30_TLE7259_ECUMWAKEUPSOURCEIDOFCHANNEL                                              STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Channel.EcuMWakeupSourceId' Reason: 'the value of LinTrcv_30_Tle7259_EcuMWakeupSourceIdOfChannel is always 'LINTRCV_30_TLE7259_NO_ECUMWAKEUPSOURCEIDOFCHANNEL' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_ICUCHANNELIDOFCHANNEL                                                    STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Channel.IcuChannelId' Reason: 'the value of LinTrcv_30_Tle7259_IcuChannelIdOfChannel is always 'LINTRCV_30_TLE7259_NO_ICUCHANNELIDOFCHANNEL' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_ICUCHANNELIDUSEDOFCHANNEL                                                STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Channel.IcuChannelIdUsed' Reason: 'the value of LinTrcv_30_Tle7259_IcuChannelIdUsedOfChannel is always 'false' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_INITSTATEOFCHANNEL                                                       STD_ON
#define LINTRCV_30_TLE7259_WAKEUPBYBUSUSEDOFCHANNEL                                                 STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Channel.WakeupByBusUsed' Reason: 'the value of LinTrcv_30_Tle7259_WakeupByBusUsedOfChannel is always 'false' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_WAKEUPBYPINUSEDOFCHANNEL                                                 STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Channel.WakeupByPinUsed' Reason: 'the value of LinTrcv_30_Tle7259_WakeupByPinUsedOfChannel is always 'false' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_DIOCHANNEL                                                               STD_ON
#define LINTRCV_30_TLE7259_DIOPINENOFDIOCHANNEL                                                     STD_ON
#define LINTRCV_30_TLE7259_DIOPINRXOFDIOCHANNEL                                                     STD_ON
#define LINTRCV_30_TLE7259_DIOPINTXOFDIOCHANNEL                                                     STD_ON
#define LINTRCV_30_TLE7259_FINALMAGICNUMBER                                                         STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LINTRCV_30_TLE7259_INITDATAHASHCODE                                                         STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LINTRCV_30_TLE7259_TLE7259CHANNEL                                                           STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Tle7259Channel' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINTRCV_30_TLE7259_SLEEPINITWORKAROUNDOFTLE7259CHANNEL                                      STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_Tle7259Channel.SleepInitWorkaround' Reason: 'the value of LinTrcv_30_Tle7259_SleepInitWorkaroundOfTle7259Channel is always 'false' due to this, the array is deactivated.' */
#define LINTRCV_30_TLE7259_WAKEUPSOURCEMAPPING                                                      STD_ON
#define LINTRCV_30_TLE7259_WAKEUPBYBUSRXOFWAKEUPSOURCEMAPPING                                       STD_ON
#define LINTRCV_30_TLE7259_WAKEUPBYBUSTXOFWAKEUPSOURCEMAPPING                                       STD_ON
#define LINTRCV_30_TLE7259_WAKEUPBYPINRXOFWAKEUPSOURCEMAPPING                                       STD_ON
#define LINTRCV_30_TLE7259_WAKEUPBYPINTXOFWAKEUPSOURCEMAPPING                                       STD_ON
#define LINTRCV_30_TLE7259_PCCONFIG                                                                 STD_ON
#define LINTRCV_30_TLE7259_CHANNELOFPCCONFIG                                                        STD_ON
#define LINTRCV_30_TLE7259_DIOCHANNELOFPCCONFIG                                                     STD_ON
#define LINTRCV_30_TLE7259_FINALMAGICNUMBEROFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LINTRCV_30_TLE7259_INITDATAHASHCODEOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LINTRCV_30_TLE7259_WAKEUPSOURCEMAPPINGOFPCCONFIG                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCIsReducedToDefineDefines  LinTrcv_30_Tle7259 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define LINTRCV_30_TLE7259_ISDEF_CHANNELUSEDOFCHANNEL                                               STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_INITSTATEOFCHANNEL                                                 STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_DIOPINENOFDIOCHANNEL                                               STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_DIOPINRXOFDIOCHANNEL                                               STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_DIOPINTXOFDIOCHANNEL                                               STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_WAKEUPBYBUSRXOFWAKEUPSOURCEMAPPING                                 STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_WAKEUPBYBUSTXOFWAKEUPSOURCEMAPPING                                 STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_WAKEUPBYPINRXOFWAKEUPSOURCEMAPPING                                 STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_WAKEUPBYPINTXOFWAKEUPSOURCEMAPPING                                 STD_OFF
#define LINTRCV_30_TLE7259_ISDEF_CHANNELOFPCCONFIG                                                  STD_ON
#define LINTRCV_30_TLE7259_ISDEF_DIOCHANNELOFPCCONFIG                                               STD_ON
#define LINTRCV_30_TLE7259_ISDEF_WAKEUPSOURCEMAPPINGOFPCCONFIG                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCEqualsAlwaysToDefines  LinTrcv_30_Tle7259 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define LINTRCV_30_TLE7259_EQ2_CHANNELUSEDOFCHANNEL                                                 
#define LINTRCV_30_TLE7259_EQ2_INITSTATEOFCHANNEL                                                   
#define LINTRCV_30_TLE7259_EQ2_DIOPINENOFDIOCHANNEL                                                 
#define LINTRCV_30_TLE7259_EQ2_DIOPINRXOFDIOCHANNEL                                                 
#define LINTRCV_30_TLE7259_EQ2_DIOPINTXOFDIOCHANNEL                                                 
#define LINTRCV_30_TLE7259_EQ2_WAKEUPBYBUSRXOFWAKEUPSOURCEMAPPING                                   
#define LINTRCV_30_TLE7259_EQ2_WAKEUPBYBUSTXOFWAKEUPSOURCEMAPPING                                   
#define LINTRCV_30_TLE7259_EQ2_WAKEUPBYPINRXOFWAKEUPSOURCEMAPPING                                   
#define LINTRCV_30_TLE7259_EQ2_WAKEUPBYPINTXOFWAKEUPSOURCEMAPPING                                   
#define LINTRCV_30_TLE7259_EQ2_CHANNELOFPCCONFIG                                                    LinTrcv_30_Tle7259_Channel
#define LINTRCV_30_TLE7259_EQ2_DIOCHANNELOFPCCONFIG                                                 LinTrcv_30_Tle7259_DioChannel
#define LINTRCV_30_TLE7259_EQ2_WAKEUPSOURCEMAPPINGOFPCCONFIG                                        LinTrcv_30_Tle7259_WakeUpSourceMapping
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCSymbolicInitializationPointers  LinTrcv_30_Tle7259 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define LinTrcv_30_Tle7259_Config_Ptr                                                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'LinTrcv_30_Tle7259' */
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCInitializationSymbols  LinTrcv_30_Tle7259 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define LinTrcv_30_Tle7259_Config                                                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'LinTrcv_30_Tle7259 */
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCGeneral  LinTrcv_30_Tle7259 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define LINTRCV_30_TLE7259_CHECK_INIT_POINTER                                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define LINTRCV_30_TLE7259_FINAL_MAGIC_NUMBER                                                       0x401Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of LinTrcv_30_Tle7259 */
#define LINTRCV_30_TLE7259_INDIVIDUAL_POSTBUILD                                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'LinTrcv_30_Tle7259' is not configured to be postbuild capable. */
#define LINTRCV_30_TLE7259_INIT_DATA                                                                LINTRCV_30_TLE7259_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define LINTRCV_30_TLE7259_INIT_DATA_HASH_CODE                                                      1396430800  /**< the precompile constant to validate the initialization structure at initialization time of LinTrcv_30_Tle7259 with a hashcode. The seed value is '0x401Eu' */
#define LINTRCV_30_TLE7259_USE_ECUM_BSW_ERROR_HOOK                                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define LINTRCV_30_TLE7259_USE_INIT_POINTER                                                         STD_OFF  /**< STD_ON if the init pointer LinTrcv_30_Tle7259 shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinTrcv_30_Tle7259LTDataSwitches  LinTrcv_30_Tle7259 Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINTRCV_30_TLE7259_LTCONFIG                                                                 STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinTrcv_30_Tle7259PBDataSwitches  LinTrcv_30_Tle7259 Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINTRCV_30_TLE7259_PBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LINTRCV_30_TLE7259_LTCONFIGIDXOFPBCONFIG                                                    STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LINTRCV_30_TLE7259_PCCONFIGIDXOFPBCONFIG                                                    STD_OFF  /**< Deactivateable: 'LinTrcv_30_Tle7259_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
  \defgroup  LinTrcv_30_Tle7259PCGetConstantDuplicatedRootDataMacros  LinTrcv_30_Tle7259 Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define LinTrcv_30_Tle7259_GetChannelOfPCConfig()                                                   LinTrcv_30_Tle7259_Channel  /**< the pointer to LinTrcv_30_Tle7259_Channel */
#define LinTrcv_30_Tle7259_GetDioChannelOfPCConfig()                                                LinTrcv_30_Tle7259_DioChannel  /**< the pointer to LinTrcv_30_Tle7259_DioChannel */
#define LinTrcv_30_Tle7259_GetWakeUpSourceMappingOfPCConfig()                                       LinTrcv_30_Tle7259_WakeUpSourceMapping  /**< the pointer to LinTrcv_30_Tle7259_WakeUpSourceMapping */
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCGetDataMacros  LinTrcv_30_Tle7259 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define LinTrcv_30_Tle7259_IsChannelUsedOfChannel(Index)                                            ((LinTrcv_30_Tle7259_GetChannelOfPCConfig()[(Index)].ChannelUsedOfChannel) != FALSE)
#define LinTrcv_30_Tle7259_GetInitStateOfChannel(Index)                                             (LinTrcv_30_Tle7259_GetChannelOfPCConfig()[(Index)].InitStateOfChannel)
#define LinTrcv_30_Tle7259_GetDioPinEnOfDioChannel(Index)                                           (LinTrcv_30_Tle7259_GetDioChannelOfPCConfig()[(Index)].DioPinEnOfDioChannel)
#define LinTrcv_30_Tle7259_GetDioPinRxOfDioChannel(Index)                                           (LinTrcv_30_Tle7259_GetDioChannelOfPCConfig()[(Index)].DioPinRxOfDioChannel)
#define LinTrcv_30_Tle7259_GetDioPinTxOfDioChannel(Index)                                           (LinTrcv_30_Tle7259_GetDioChannelOfPCConfig()[(Index)].DioPinTxOfDioChannel)
#define LinTrcv_30_Tle7259_GetWakeupByBusRxOfWakeUpSourceMapping(Index)                             (LinTrcv_30_Tle7259_GetWakeUpSourceMappingOfPCConfig()[(Index)].WakeupByBusRxOfWakeUpSourceMapping)
#define LinTrcv_30_Tle7259_GetWakeupByBusTxOfWakeUpSourceMapping(Index)                             (LinTrcv_30_Tle7259_GetWakeUpSourceMappingOfPCConfig()[(Index)].WakeupByBusTxOfWakeUpSourceMapping)
#define LinTrcv_30_Tle7259_GetWakeupByPinRxOfWakeUpSourceMapping(Index)                             (LinTrcv_30_Tle7259_GetWakeUpSourceMappingOfPCConfig()[(Index)].WakeupByPinRxOfWakeUpSourceMapping)
#define LinTrcv_30_Tle7259_GetWakeupByPinTxOfWakeUpSourceMapping(Index)                             (LinTrcv_30_Tle7259_GetWakeUpSourceMappingOfPCConfig()[(Index)].WakeupByPinTxOfWakeUpSourceMapping)
/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCHasMacros  LinTrcv_30_Tle7259 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define LinTrcv_30_Tle7259_HasChannel()                                                             (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasChannelUsedOfChannel()                                                (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasInitStateOfChannel()                                                  (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasDioChannel()                                                          (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasDioPinEnOfDioChannel()                                                (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasDioPinRxOfDioChannel()                                                (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasDioPinTxOfDioChannel()                                                (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeUpSourceMapping()                                                 (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeupByBusRxOfWakeUpSourceMapping()                                  (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeupByBusTxOfWakeUpSourceMapping()                                  (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeupByPinRxOfWakeUpSourceMapping()                                  (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeupByPinTxOfWakeUpSourceMapping()                                  (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasPCConfig()                                                            (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasChannelOfPCConfig()                                                   (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasDioChannelOfPCConfig()                                                (TRUE != FALSE)
#define LinTrcv_30_Tle7259_HasWakeUpSourceMappingOfPCConfig()                                       (TRUE != FALSE)
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
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
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
  \defgroup  LinTrcv_30_Tle7259PCIterableTypes  LinTrcv_30_Tle7259 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate LinTrcv_30_Tle7259_Channel */
typedef uint8_least LinTrcv_30_Tle7259_ChannelIterType;

/**   \brief  type used to iterate LinTrcv_30_Tle7259_DioChannel */
typedef uint8_least LinTrcv_30_Tle7259_DioChannelIterType;

/**   \brief  type used to iterate LinTrcv_30_Tle7259_WakeUpSourceMapping */
typedef uint8_least LinTrcv_30_Tle7259_WakeUpSourceMappingIterType;

/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCValueTypes  LinTrcv_30_Tle7259 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for LinTrcv_30_Tle7259_ChannelUsedOfChannel */
typedef boolean LinTrcv_30_Tle7259_ChannelUsedOfChannelType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LinTrcv_30_Tle7259PCStructTypes  LinTrcv_30_Tle7259 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in LinTrcv_30_Tle7259_Channel */
typedef struct sLinTrcv_30_Tle7259_ChannelType
{
  LinTrcv_30_Tle7259_ChannelUsedOfChannelType ChannelUsedOfChannel;
  LinTrcv_TrcvModeType InitStateOfChannel;
} LinTrcv_30_Tle7259_ChannelType;

/**   \brief  type used in LinTrcv_30_Tle7259_DioChannel */
typedef struct sLinTrcv_30_Tle7259_DioChannelType
{
  Dio_ChannelType DioPinEnOfDioChannel;
  Dio_ChannelType DioPinRxOfDioChannel;
  Dio_ChannelType DioPinTxOfDioChannel;
} LinTrcv_30_Tle7259_DioChannelType;

/**   \brief  type used in LinTrcv_30_Tle7259_WakeUpSourceMapping */
typedef struct sLinTrcv_30_Tle7259_WakeUpSourceMappingType
{
  Dio_LevelType WakeupByBusRxOfWakeUpSourceMapping;  /**< Level of Rx pin when Bus wakeup is signalized */
  Dio_LevelType WakeupByBusTxOfWakeUpSourceMapping;  /**< Level of Tx pin when Bus wakeup is signalized */
  Dio_LevelType WakeupByPinRxOfWakeUpSourceMapping;  /**< Level of Rx pin when Pin wakeup is signalized */
  Dio_LevelType WakeupByPinTxOfWakeUpSourceMapping;  /**< Level of Tx pin when Pin wakeup is signalized */
} LinTrcv_30_Tle7259_WakeUpSourceMappingType;

/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCRootPointerTypes  LinTrcv_30_Tle7259 Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to LinTrcv_30_Tle7259_Channel */
typedef P2CONST(LinTrcv_30_Tle7259_ChannelType, TYPEDEF, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_ChannelPtrType;

/**   \brief  type used to point to LinTrcv_30_Tle7259_DioChannel */
typedef P2CONST(LinTrcv_30_Tle7259_DioChannelType, TYPEDEF, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_DioChannelPtrType;

/**   \brief  type used to point to LinTrcv_30_Tle7259_WakeUpSourceMapping */
typedef P2CONST(LinTrcv_30_Tle7259_WakeUpSourceMappingType, TYPEDEF, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_WakeUpSourceMappingPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  LinTrcv_30_Tle7259PCRootValueTypes  LinTrcv_30_Tle7259 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in LinTrcv_30_Tle7259_PCConfig */
typedef struct sLinTrcv_30_Tle7259_PCConfigType
{
  uint8 LinTrcv_30_Tle7259_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} LinTrcv_30_Tle7259_PCConfigType;

typedef LinTrcv_30_Tle7259_PCConfigType LinTrcv_30_Tle7259_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  LinTrcv_30_Tle7259_Channel
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_Channel
  \details
  Element        Description
  ChannelUsed
  InitState  
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LinTrcv_30_Tle7259_ChannelType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_Channel[2];
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinTrcv_30_Tle7259_DioChannel
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_DioChannel
  \details
  Element     Description
  DioPinEn
  DioPinRx
  DioPinTx
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LinTrcv_30_Tle7259_DioChannelType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_DioChannel[2];
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinTrcv_30_Tle7259_WakeUpSourceMapping
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_WakeUpSourceMapping
  \brief  Struct to provide the required Pin state
  \details
  Element          Description
  WakeupByBusRx    Level of Rx pin when Bus wakeup is signalized
  WakeupByBusTx    Level of Tx pin when Bus wakeup is signalized
  WakeupByPinRx    Level of Rx pin when Pin wakeup is signalized
  WakeupByPinTx    Level of Tx pin when Pin wakeup is signalized
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LinTrcv_30_Tle7259_WakeUpSourceMappingType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_WakeUpSourceMapping[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

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
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


typedef struct sLinTrcv_30_Tle7259_ChannelDataTypeTag
{
  VAR(LinTrcv_TrcvWakeupReasonType , AUTOMATIC)   LinTrcv_30_Tle7259_WakeupReason;
  VAR(LinTrcv_TrcvWakeupModeType , AUTOMATIC)     LinTrcv_30_Tle7259_WakeupMode;
  VAR(LinTrcv_TrcvModeType , AUTOMATIC)           LinTrcv_30_Tle7259_State;
}LinTrcv_30_Tle7259_ChannelDataType;

#define LINTRCV_30_TLE7259_START_SEC_CONST_8BIT

#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_NrOfChannels;
extern CONST(uint8, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_InstanceId;
extern CONST(uint32, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_WaitCount;

#define LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT

#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(LinTrcv_30_Tle7259_ChannelDataType, LINTRCV_30_TLE7259_VAR_NOINIT) LinTrcv_30_Tle7259_ChannelData[LINTRCV_30_TLE7259_NROFCHANNELS];
#define LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* LINTRCV_30_TLE7259_CFG_H */

