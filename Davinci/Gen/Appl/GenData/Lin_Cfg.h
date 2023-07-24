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
 *            Module: Lin
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Lin_Cfg.h
 *   Generation Time: 2020-08-18 12:27:26
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


/* MICROSAR Lin Rh850 Generator */
/* 15.00.00 */

/* Baudrate information */
/*
Channel Shortname: Channel Clock/hz, Channel baudrate, Calculated channel baudrate 
 
Default - CN_LIN00_fd825f00: 40000000hz, 19200Baud --> 19200Baud 
Default - CN_LIN00_fd825f00_001: 40000000hz, 19200Baud --> 19200Baud 

*/

#if !defined(LIN_CFG_H)
#define LIN_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Includes
----------------------------------------------------------------------------- */
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"


/* -----------------------------------------------------------------------------
    &&&~ Symbolic name values
 ----------------------------------------------------------------------------- */



/**
 * \defgroup LinHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define LinConf_LinChannel_CN_LIN00_fd825f00                          0u
#define LinConf_LinChannel_CN_LIN00_fd825f00_001                      1u
/**\} */

/* -----------------------------------------------------------------------------
    &&&~ General Define Block
----------------------------------------------------------------------------- */
#ifndef LIN_USE_DUMMY_STATEMENT
#define LIN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LIN_DUMMY_STATEMENT
#define LIN_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LIN_DUMMY_STATEMENT_CONST
#define LIN_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LIN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define LIN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef LIN_ATOMIC_VARIABLE_ACCESS
#define LIN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef LIN_PROCESSOR_RH850_1651
#define LIN_PROCESSOR_RH850_1651
#endif
#ifndef LIN_COMP_GREENHILLS
#define LIN_COMP_GREENHILLS
#endif
#ifndef LIN_GEN_GENERATOR_MSR
#define LIN_GEN_GENERATOR_MSR
#endif
#ifndef LIN_CPUTYPE_BITORDER_LSB2MSB
#define LIN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef LIN_CONFIGURATION_VARIANT_PRECOMPILE
#define LIN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LIN_CONFIGURATION_VARIANT_LINKTIME
#define LIN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LIN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LIN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef LIN_CONFIGURATION_VARIANT
#define LIN_CONFIGURATION_VARIANT LIN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef LIN_POSTBUILD_VARIANT_SUPPORT
#define LIN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* -----------------------------------------------------------------------------
    &&&~ LIN Define Block
----------------------------------------------------------------------------- */
#define LIN_VERSION_INFO_API                          STD_OFF
#define LIN_DEV_ERROR_DETECT                          STD_ON
#define LIN_DEV_ERROR_REPORT                          STD_ON
#define LIN_RUNTIME_MEASUREMENT_SUPPORT               STD_OFF
#define LIN_E_TIMEOUT_TYPE_DET                        STD_ON
#define LIN_LEAST_ONE_CHANNEL_WAKEUP_SUPPORT_ENABLED  STD_OFF /*!< Least one channel has wake up support enabled */
#define LIN_LEAST_ONE_CHANNEL_WAKEUP_SUPPORT_DISABLED STD_ON /*!< Least one channel has wake up support disabled */

#define LIN_E_TIMEOUT        16u /*!< Timeout caused by hardware error */ 
#define LIN_TIMEOUT_DURATION 100u

#define LIN_GROUP_F1KM_CTRL 



/* Hardware specific defines */
/* None */



/* -----------------------------------------------------------------------------
    &&&~ Interrupts
----------------------------------------------------------------------------- */
/* no interrupt declaration at Category 2 */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinPCDataSwitches  Lin Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LIN_CHANNELCONFIG                                                                           STD_ON
#define LIN_CHANNELBASEADDRESSOFCHANNELCONFIG                                                       STD_ON
#define LIN_CHANNELIDOFCHANNELCONFIG                                                                STD_ON
#define LIN_ECUMWAKEUPSOURCEOFCHANNELCONFIG                                                         STD_ON
#define LIN_GLOBALBASEADDRESSOFCHANNELCONFIG                                                        STD_ON
#define LIN_LBFCOFCHANNELCONFIG                                                                     STD_ON
#define LIN_LBRP0OFCHANNELCONFIG                                                                    STD_ON
#define LIN_LBRP1OFCHANNELCONFIG                                                                    STD_ON
#define LIN_LEDEOFCHANNELCONFIG                                                                     STD_ON
#define LIN_LIEOFCHANNELCONFIG                                                                      STD_ON
#define LIN_LMDOFCHANNELCONFIG                                                                      STD_ON
#define LIN_LWBROFCHANNELCONFIG                                                                     STD_ON
#define LIN_NODETYPEOFCHANNELCONFIG                                                                 STD_ON
#define LIN_CHANNELDATA                                                                             STD_ON
#define LIN_DATABUFFEROFCHANNELDATA                                                                 STD_ON
#define LIN_INTERNALSTATEOFCHANNELDATA                                                              STD_ON
#define LIN_CHANNELHW                                                                               STD_ON
#define LIN_CHANNELCONFIGIDXOFCHANNELHW                                                             STD_ON
#define LIN_INVALIDHNDOFCHANNELHW                                                                   STD_OFF  /**< Deactivateable: 'Lin_ChannelHw.InvalidHnd' Reason: 'the value of Lin_InvalidHndOfChannelHw is always 'false' due to this, the array is deactivated.' */
#define LIN_CHANNELID                                                                               STD_ON
#define LIN_CHANNELCONFIGIDXOFCHANNELID                                                             STD_ON
#define LIN_INVALIDHNDOFCHANNELID                                                                   STD_OFF  /**< Deactivateable: 'Lin_ChannelId.InvalidHnd' Reason: 'the value of Lin_InvalidHndOfChannelId is always 'false' due to this, the array is deactivated.' */
#define LIN_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Lin_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LIN_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Lin_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LIN_MAXHWCHANNELS                                                                           STD_ON
#define LIN_MAXVARIANTCHANNELS                                                                      STD_ON
#define LIN_SIZEOFCHANNELCONFIG                                                                     STD_ON
#define LIN_SIZEOFCHANNELDATA                                                                       STD_ON
#define LIN_SIZEOFCHANNELHW                                                                         STD_ON
#define LIN_SIZEOFCHANNELID                                                                         STD_ON
#define LIN_PCCONFIG                                                                                STD_ON
#define LIN_CHANNELCONFIGOFPCCONFIG                                                                 STD_ON
#define LIN_CHANNELDATAOFPCCONFIG                                                                   STD_ON
#define LIN_CHANNELHWOFPCCONFIG                                                                     STD_ON
#define LIN_CHANNELIDOFPCCONFIG                                                                     STD_ON
#define LIN_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Lin_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LIN_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Lin_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LIN_MAXHWCHANNELSOFPCCONFIG                                                                 STD_ON
#define LIN_MAXVARIANTCHANNELSOFPCCONFIG                                                            STD_ON
#define LIN_SIZEOFCHANNELCONFIGOFPCCONFIG                                                           STD_ON
#define LIN_SIZEOFCHANNELDATAOFPCCONFIG                                                             STD_ON
#define LIN_SIZEOFCHANNELHWOFPCCONFIG                                                               STD_ON
#define LIN_SIZEOFCHANNELIDOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinPCEnumExistsDefines  Lin Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG                                                   STD_ON
#define LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  LinPCEnumDefines  Lin Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define LIN_MASTER_NODETYPEOFCHANNELCONFIG                                                          0x00u
#define LIN_ONTX_OK_INTERNALSTATEOFCHANNELDATA                                                      0x00u
#define LIN_ONTX_BUSY_INTERNALSTATEOFCHANNELDATA                                                    0x01u
#define LIN_ONTX_HEADER_ERROR_INTERNALSTATEOFCHANNELDATA                                            0x02u
#define LIN_ONTX_ERROR_INTERNALSTATEOFCHANNELDATA                                                   0x03u
#define LIN_ONRX_OK_INTERNALSTATEOFCHANNELDATA                                                      0x04u
#define LIN_ONRX_BUSY_INTERNALSTATEOFCHANNELDATA                                                    0x05u
#define LIN_ONRX_ERROR_INTERNALSTATEOFCHANNELDATA                                                   0x06u
#define LIN_ONRX_NO_RESPONSE_INTERNALSTATEOFCHANNELDATA                                             0x07u
#define LIN_ONWAKE_INTERNALSTATEOFCHANNELDATA                                                       0x09u
#define LIN_ONSLEEP_INTERNALSTATEOFCHANNELDATA                                                      0x0Au
#define LIN_NOT_OK_INTERNALSTATEOFCHANNELDATA                                                       0x0Bu
#define LIN_ONSLEEP_PENDING_INTERNALSTATEOFCHANNELDATA                                              0x19u
#define LIN_ONWAKEUP_PENDING_INTERNALSTATEOFCHANNELDATA                                             0x29u
#define LIN_ONS2S_BUSY_INTERNALSTATEOFCHANNELDATA                                                   0x11u
#define LIN_ONWAKEUP_EXTERNAL_INTERNALSTATEOFCHANNELDATA                                            0x3Au
/** 
  \}
*/ 

/** 
  \defgroup  LinPCIsReducedToDefineDefines  Lin Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define LIN_ISDEF_CHANNELBASEADDRESSOFCHANNELCONFIG                                                 STD_OFF
#define LIN_ISDEF_CHANNELIDOFCHANNELCONFIG                                                          STD_OFF
#define LIN_ISDEF_ECUMWAKEUPSOURCEOFCHANNELCONFIG                                                   STD_ON
#define LIN_ISDEF_GLOBALBASEADDRESSOFCHANNELCONFIG                                                  STD_OFF
#define LIN_ISDEF_LBFCOFCHANNELCONFIG                                                               STD_ON
#define LIN_ISDEF_LBRP0OFCHANNELCONFIG                                                              STD_ON
#define LIN_ISDEF_LBRP1OFCHANNELCONFIG                                                              STD_ON
#define LIN_ISDEF_LEDEOFCHANNELCONFIG                                                               STD_ON
#define LIN_ISDEF_LIEOFCHANNELCONFIG                                                                STD_ON
#define LIN_ISDEF_LMDOFCHANNELCONFIG                                                                STD_ON
#define LIN_ISDEF_LWBROFCHANNELCONFIG                                                               STD_ON
#define LIN_ISDEF_NODETYPEOFCHANNELCONFIG                                                           STD_ON
#define LIN_ISDEF_CHANNELCONFIGIDXOFCHANNELHW                                                       STD_OFF
#define LIN_ISDEF_CHANNELCONFIGIDXOFCHANNELID                                                       STD_OFF
#define LIN_ISDEF_CHANNELCONFIGOFPCCONFIG                                                           STD_ON
#define LIN_ISDEF_CHANNELDATAOFPCCONFIG                                                             STD_ON
#define LIN_ISDEF_CHANNELHWOFPCCONFIG                                                               STD_ON
#define LIN_ISDEF_CHANNELIDOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinPCEqualsAlwaysToDefines  Lin Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define LIN_EQ2_CHANNELBASEADDRESSOFCHANNELCONFIG                                                   
#define LIN_EQ2_CHANNELIDOFCHANNELCONFIG                                                            
#define LIN_EQ2_ECUMWAKEUPSOURCEOFCHANNELCONFIG                                                     0x00000000u
#define LIN_EQ2_GLOBALBASEADDRESSOFCHANNELCONFIG                                                    
#define LIN_EQ2_LBFCOFCHANNELCONFIG                                                                 0x11u
#define LIN_EQ2_LBRP0OFCHANNELCONFIG                                                                0x81u
#define LIN_EQ2_LBRP1OFCHANNELCONFIG                                                                0x00u
#define LIN_EQ2_LEDEOFCHANNELCONFIG                                                                 0x0Fu
#define LIN_EQ2_LIEOFCHANNELCONFIG                                                                  0x00u
#define LIN_EQ2_LMDOFCHANNELCONFIG                                                                  0x00u
#define LIN_EQ2_LWBROFCHANNELCONFIG                                                                 0x00u
#define LIN_EQ2_NODETYPEOFCHANNELCONFIG                                                             LIN_MASTER_NODETYPEOFCHANNELCONFIG
#define LIN_EQ2_CHANNELCONFIGIDXOFCHANNELHW                                                         
#define LIN_EQ2_CHANNELCONFIGIDXOFCHANNELID                                                         
#define LIN_EQ2_CHANNELCONFIGOFPCCONFIG                                                             Lin_ChannelConfig
#define LIN_EQ2_CHANNELDATAOFPCCONFIG                                                               Lin_ChannelData.raw
#define LIN_EQ2_CHANNELHWOFPCCONFIG                                                                 Lin_ChannelHw
#define LIN_EQ2_CHANNELIDOFPCCONFIG                                                                 Lin_ChannelId
/** 
  \}
*/ 

/** 
  \defgroup  LinPCSymbolicInitializationPointers  Lin Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Lin_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Lin' */
/** 
  \}
*/ 

/** 
  \defgroup  LinPCInitializationSymbols  Lin Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Lin_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Lin */
/** 
  \}
*/ 

/** 
  \defgroup  LinPCGeneral  Lin General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define LIN_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define LIN_FINAL_MAGIC_NUMBER                                                                      0x521Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Lin */
#define LIN_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Lin' is not configured to be postbuild capable. */
#define LIN_INIT_DATA                                                                               LIN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define LIN_INIT_DATA_HASH_CODE                                                                     1764184991  /**< the precompile constant to validate the initialization structure at initialization time of Lin with a hashcode. The seed value is '0x521Eu' */
#define LIN_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define LIN_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Lin shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinLTDataSwitches  Lin Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LIN_LTCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Lin_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinPBDataSwitches  Lin Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LIN_PBCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Lin_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LIN_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Lin_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LIN_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Lin_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
  \defgroup  LinPCGetConstantDuplicatedRootDataMacros  Lin Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Lin_GetChannelConfigOfPCConfig()                                                            Lin_ChannelConfig  /**< the pointer to Lin_ChannelConfig */
#define Lin_GetChannelDataOfPCConfig()                                                              Lin_ChannelData.raw  /**< the pointer to Lin_ChannelData */
#define Lin_GetChannelHwOfPCConfig()                                                                Lin_ChannelHw  /**< the pointer to Lin_ChannelHw */
#define Lin_GetChannelIdOfPCConfig()                                                                Lin_ChannelId  /**< the pointer to Lin_ChannelId */
#define Lin_GetMaxHwChannelsOfPCConfig()                                                            12u
#define Lin_GetMaxVariantChannelsOfPCConfig()                                                       2u
#define Lin_GetSizeOfChannelConfigOfPCConfig()                                                      2u  /**< the number of accomplishable value elements in Lin_ChannelConfig */
#define Lin_GetSizeOfChannelHwOfPCConfig()                                                          2u  /**< the number of accomplishable value elements in Lin_ChannelHw */
#define Lin_GetSizeOfChannelIdOfPCConfig()                                                          2u  /**< the number of accomplishable value elements in Lin_ChannelId */
/** 
  \}
*/ 

/** 
  \defgroup  LinPCGetDuplicatedRootDataMacros  Lin Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Lin_GetSizeOfChannelDataOfPCConfig()                                                        Lin_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in Lin_ChannelData */
/** 
  \}
*/ 

/** 
  \defgroup  LinPCGetDataMacros  Lin Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Lin_GetChannelBaseAddressOfChannelConfig(Index)                                             (Lin_GetChannelConfigOfPCConfig()[(Index)].ChannelBaseAddressOfChannelConfig)
#define Lin_GetGlobalBaseAddressOfChannelConfig(Index)                                              (Lin_GetChannelConfigOfPCConfig()[(Index)].GlobalBaseAddressOfChannelConfig)
#define Lin_GetDataBufferOfChannelData(Index)                                                       (Lin_GetChannelDataOfPCConfig()[(Index)].DataBufferOfChannelData)
#define Lin_GetInternalStateOfChannelData(Index)                                                    (Lin_GetChannelDataOfPCConfig()[(Index)].InternalStateOfChannelData)
/** 
  \}
*/ 

/** 
  \defgroup  LinPCGetDeduplicatedDataMacros  Lin Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Lin_GetChannelIdOfChannelConfig(Index)                                                      ((Lin_ChannelIdOfChannelConfigType)((Index)))  /**< ChannelID for Slave indication functions */
#define Lin_GetEcuMWakeupSourceOfChannelConfig(Index)                                               0x00000000u  /**< EcuM Wakeup Source, 0 if wakeup support disabled */
#define Lin_GetLBFCOfChannelConfig(Index)                                                           0x11u  /**< LIN Break Field Configuration Register */
#define Lin_GetLBRP0OfChannelConfig(Index)                                                          0x81u  /**< LIN Baud Rate Prescaler 0 Register */
#define Lin_GetLBRP1OfChannelConfig(Index)                                                          0x00u  /**< LIN Baud Rate Prescaler 1 Register */
#define Lin_GetLEDEOfChannelConfig(Index)                                                           0x0Fu  /**< LIN Error Detection Enable Register */
#define Lin_GetLIEOfChannelConfig(Index)                                                            0x00u  /**< LIN Interrupt Enable Register */
#define Lin_GetLMDOfChannelConfig(Index)                                                            0x00u  /**< LIN Mode Register */
#define Lin_GetLWBROfChannelConfig(Index)                                                           0x00u  /**< LIN Wake-up Baud Rate Select Register */
#define Lin_GetNodeTypeOfChannelConfig(Index)                                                       LIN_MASTER_NODETYPEOFCHANNELCONFIG  /**< ENUM to indicate the Lin Node Type */
#define Lin_GetChannelConfigIdxOfChannelHw(Index)                                                   ((Lin_ChannelConfigIdxOfChannelHwType)((Index)))  /**< the index of the 1:1 relation pointing to Lin_ChannelConfig */
#define Lin_GetChannelConfigIdxOfChannelId(Index)                                                   ((Lin_ChannelConfigIdxOfChannelIdType)((Index)))  /**< the index of the 1:1 relation pointing to Lin_ChannelConfig */
#define Lin_GetMaxHwChannels()                                                                      Lin_GetMaxHwChannelsOfPCConfig()
#define Lin_GetMaxVariantChannels()                                                                 Lin_GetMaxVariantChannelsOfPCConfig()
#define Lin_GetSizeOfChannelConfig()                                                                Lin_GetSizeOfChannelConfigOfPCConfig()
#define Lin_GetSizeOfChannelData()                                                                  Lin_GetSizeOfChannelDataOfPCConfig()
#define Lin_GetSizeOfChannelHw()                                                                    Lin_GetSizeOfChannelHwOfPCConfig()
#define Lin_GetSizeOfChannelId()                                                                    Lin_GetSizeOfChannelIdOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  LinPCSetDataMacros  Lin Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Lin_SetDataBufferOfChannelData(Index, Value)                                                Lin_GetChannelDataOfPCConfig()[(Index)].DataBufferOfChannelData = (Value)
#define Lin_SetInternalStateOfChannelData(Index, Value)                                             Lin_GetChannelDataOfPCConfig()[(Index)].InternalStateOfChannelData = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  LinPCHasMacros  Lin Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Lin_HasChannelConfig()                                                                      (TRUE != FALSE)
#define Lin_HasChannelBaseAddressOfChannelConfig()                                                  (TRUE != FALSE)
#define Lin_HasChannelIdOfChannelConfig()                                                           (TRUE != FALSE)
#define Lin_HasEcuMWakeupSourceOfChannelConfig()                                                    (TRUE != FALSE)
#define Lin_HasGlobalBaseAddressOfChannelConfig()                                                   (TRUE != FALSE)
#define Lin_HasLBFCOfChannelConfig()                                                                (TRUE != FALSE)
#define Lin_HasLBRP0OfChannelConfig()                                                               (TRUE != FALSE)
#define Lin_HasLBRP1OfChannelConfig()                                                               (TRUE != FALSE)
#define Lin_HasLEDEOfChannelConfig()                                                                (TRUE != FALSE)
#define Lin_HasLIEOfChannelConfig()                                                                 (TRUE != FALSE)
#define Lin_HasLMDOfChannelConfig()                                                                 (TRUE != FALSE)
#define Lin_HasLWBROfChannelConfig()                                                                (TRUE != FALSE)
#define Lin_HasNodeTypeOfChannelConfig()                                                            (TRUE != FALSE)
#define Lin_HasChannelData()                                                                        (TRUE != FALSE)
#define Lin_HasDataBufferOfChannelData()                                                            (TRUE != FALSE)
#define Lin_HasInternalStateOfChannelData()                                                         (TRUE != FALSE)
#define Lin_HasChannelHw()                                                                          (TRUE != FALSE)
#define Lin_HasChannelConfigIdxOfChannelHw()                                                        (TRUE != FALSE)
#define Lin_HasChannelId()                                                                          (TRUE != FALSE)
#define Lin_HasChannelConfigIdxOfChannelId()                                                        (TRUE != FALSE)
#define Lin_HasMaxHwChannels()                                                                      (TRUE != FALSE)
#define Lin_HasMaxVariantChannels()                                                                 (TRUE != FALSE)
#define Lin_HasSizeOfChannelConfig()                                                                (TRUE != FALSE)
#define Lin_HasSizeOfChannelData()                                                                  (TRUE != FALSE)
#define Lin_HasSizeOfChannelHw()                                                                    (TRUE != FALSE)
#define Lin_HasSizeOfChannelId()                                                                    (TRUE != FALSE)
#define Lin_HasPCConfig()                                                                           (TRUE != FALSE)
#define Lin_HasChannelConfigOfPCConfig()                                                            (TRUE != FALSE)
#define Lin_HasChannelDataOfPCConfig()                                                              (TRUE != FALSE)
#define Lin_HasChannelHwOfPCConfig()                                                                (TRUE != FALSE)
#define Lin_HasChannelIdOfPCConfig()                                                                (TRUE != FALSE)
#define Lin_HasMaxHwChannelsOfPCConfig()                                                            (TRUE != FALSE)
#define Lin_HasMaxVariantChannelsOfPCConfig()                                                       (TRUE != FALSE)
#define Lin_HasSizeOfChannelConfigOfPCConfig()                                                      (TRUE != FALSE)
#define Lin_HasSizeOfChannelDataOfPCConfig()                                                        (TRUE != FALSE)
#define Lin_HasSizeOfChannelHwOfPCConfig()                                                          (TRUE != FALSE)
#define Lin_HasSizeOfChannelIdOfPCConfig()                                                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  LinPCIncrementDataMacros  Lin Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Lin_IncDataBufferOfChannelData(Index)                                                       Lin_GetDataBufferOfChannelData(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  LinPCDecrementDataMacros  Lin Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Lin_DecDataBufferOfChannelData(Index)                                                       Lin_GetDataBufferOfChannelData(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  LinPCAddDataMacros  Lin Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Lin_AddDataBufferOfChannelData(Index, Value)                                                Lin_SetDataBufferOfChannelData(Index, (Lin_GetDataBufferOfChannelData(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  LinPCSubstractDataMacros  Lin Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Lin_SubDataBufferOfChannelData(Index, Value)                                                Lin_SetDataBufferOfChannelData(Index, (Lin_GetDataBufferOfChannelData(Index) - Value))
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
/*! Create pointer type to channel hardware register base address. */
typedef volatile struct Lin_RegisterStructTag Lin_RegisterStruct;
typedef Lin_RegisterStruct* Lin_RegisterStructPtr;

/*! Create pointer type to global hardware register base address. */
typedef volatile struct Lin_GlobalRegisterStructTag Lin_GlobalRegisterStruct;
typedef Lin_GlobalRegisterStruct* Lin_GlobalRegisterStructPtr;

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LinPCIterableTypes  Lin Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Lin_ChannelConfig */
typedef uint8_least Lin_ChannelConfigIterType;

/**   \brief  type used to iterate Lin_ChannelHw */
typedef uint8_least Lin_ChannelHwIterType;

/**   \brief  type used to iterate Lin_ChannelId */
typedef uint8_least Lin_ChannelIdIterType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCIterableTypesWithSizeRelations  Lin Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Lin_ChannelData */
typedef Lin_ChannelConfigIterType Lin_ChannelDataIterType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCValueTypes  Lin Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Lin_ChannelIdOfChannelConfig */
typedef uint8 Lin_ChannelIdOfChannelConfigType;

/**   \brief  value based type definition for Lin_EcuMWakeupSourceOfChannelConfig */
typedef uint32 Lin_EcuMWakeupSourceOfChannelConfigType;

/**   \brief  value based type definition for Lin_LBFCOfChannelConfig */
typedef uint8 Lin_LBFCOfChannelConfigType;

/**   \brief  value based type definition for Lin_LBRP0OfChannelConfig */
typedef uint8 Lin_LBRP0OfChannelConfigType;

/**   \brief  value based type definition for Lin_LBRP1OfChannelConfig */
typedef uint8 Lin_LBRP1OfChannelConfigType;

/**   \brief  value based type definition for Lin_LEDEOfChannelConfig */
typedef uint8 Lin_LEDEOfChannelConfigType;

/**   \brief  value based type definition for Lin_LIEOfChannelConfig */
typedef uint8 Lin_LIEOfChannelConfigType;

/**   \brief  value based type definition for Lin_LMDOfChannelConfig */
typedef uint8 Lin_LMDOfChannelConfigType;

/**   \brief  value based type definition for Lin_LWBROfChannelConfig */
typedef uint8 Lin_LWBROfChannelConfigType;

/**   \brief  value based type definition for Lin_NodeTypeOfChannelConfig */
typedef uint8 Lin_NodeTypeOfChannelConfigType;

/**   \brief  value based type definition for Lin_InternalStateOfChannelData */
typedef uint8 Lin_InternalStateOfChannelDataType;

/**   \brief  value based type definition for Lin_ChannelConfigIdxOfChannelHw */
typedef uint8 Lin_ChannelConfigIdxOfChannelHwType;

/**   \brief  value based type definition for Lin_ChannelConfigIdxOfChannelId */
typedef uint8 Lin_ChannelConfigIdxOfChannelIdType;

/**   \brief  value based type definition for Lin_MaxHwChannels */
typedef uint8 Lin_MaxHwChannelsType;

/**   \brief  value based type definition for Lin_MaxVariantChannels */
typedef uint8 Lin_MaxVariantChannelsType;

/**   \brief  value based type definition for Lin_SizeOfChannelConfig */
typedef uint8 Lin_SizeOfChannelConfigType;

/**   \brief  value based type definition for Lin_SizeOfChannelData */
typedef uint8 Lin_SizeOfChannelDataType;

/**   \brief  value based type definition for Lin_SizeOfChannelHw */
typedef uint8 Lin_SizeOfChannelHwType;

/**   \brief  value based type definition for Lin_SizeOfChannelId */
typedef uint8 Lin_SizeOfChannelIdType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LinPCStructTypes  Lin Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Lin_ChannelConfig */
typedef struct sLin_ChannelConfigType
{
  Lin_GlobalRegisterStructPtr GlobalBaseAddressOfChannelConfig;  /**< RLIN global register address. */
  Lin_RegisterStructPtr ChannelBaseAddressOfChannelConfig;  /**< RLIN channel register address. */
} Lin_ChannelConfigType;

/**   \brief  type used in Lin_ChannelData */
typedef struct sLin_ChannelDataType
{
  Lin_InternalStateOfChannelDataType InternalStateOfChannelData;  /**< Internal software state. */
  Lin_DataBufferType DataBufferOfChannelData;  /**< Data Buffer. */
} Lin_ChannelDataType;

/**   \brief  type used in Lin_ChannelHw */
typedef struct sLin_ChannelHwType
{
  uint8 Lin_ChannelHwNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Lin_ChannelHwType;

/**   \brief  type used in Lin_ChannelId */
typedef struct sLin_ChannelIdType
{
  uint8 Lin_ChannelIdNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Lin_ChannelIdType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCSymbolicStructTypes  Lin Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Lin_ChannelData */
typedef struct Lin_ChannelDataStructSTag
{
  Lin_ChannelDataType CN_LIN00_fd825f00;
  Lin_ChannelDataType CN_LIN00_fd825f00_001;
} Lin_ChannelDataStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCUnionIndexAndSymbolTypes  Lin Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Lin_ChannelData in an index and symbol based style. */
typedef union Lin_ChannelDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Lin_ChannelDataType raw[2];
  Lin_ChannelDataStructSType str;
} Lin_ChannelDataUType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCRootPointerTypes  Lin Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Lin_ChannelConfig */
typedef P2CONST(Lin_ChannelConfigType, TYPEDEF, LIN_CONST) Lin_ChannelConfigPtrType;

/**   \brief  type used to point to Lin_ChannelData */
typedef P2VAR(Lin_ChannelDataType, TYPEDEF, LIN_VAR_NOINIT) Lin_ChannelDataPtrType;

/**   \brief  type used to point to Lin_ChannelHw */
typedef P2CONST(Lin_ChannelHwType, TYPEDEF, LIN_CONST) Lin_ChannelHwPtrType;

/**   \brief  type used to point to Lin_ChannelId */
typedef P2CONST(Lin_ChannelIdType, TYPEDEF, LIN_CONST) Lin_ChannelIdPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  LinPCRootValueTypes  Lin Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Lin_PCConfig */
typedef struct sLin_PCConfigType
{
  uint8 Lin_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Lin_PCConfigType;

typedef Lin_PCConfigType Lin_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
  Lin_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    Lin_ConfigDataPtr
  \brief  Global config data pointer.
*/ 
#if (LIN_USE_INIT_POINTER == STD_ON)

# define LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern P2CONST(Lin_ConfigType, LIN_VAR_NOINIT, LIN_PBCFG) Lin_ConfigDataPtr;

# define LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Lin_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    Lin_ChannelConfig
  \brief  List of all Lin channel config
  \details
  Element               Description
  GlobalBaseAddress     RLIN global register address.
  ChannelBaseAddress    RLIN channel register address.
*/ 
#define LIN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Lin_ChannelConfigType, LIN_CONST) Lin_ChannelConfig[2];
#define LIN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Lin_ChannelData
**********************************************************************************************************************/
/** 
  \var    Lin_ChannelData
  \brief  RAM data for channels.
  \details
  Element          Description
  InternalState    Internal software state.
  DataBuffer       Data Buffer.
*/ 
#define LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Lin_ChannelDataUType, LIN_VAR_NOINIT) Lin_ChannelData;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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





#endif /* LIN_CFG_H */

