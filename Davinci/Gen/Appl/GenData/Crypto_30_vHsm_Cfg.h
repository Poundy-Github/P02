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
 *            Module: Crypto_30_vHsm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Cfg.h
 *   Generation Time: 2021-07-20 09:29:35
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_VHSM_CFG_H)
#define CRYPTO_30_VHSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CRYPTO_30_VHSM_USE_DUMMY_STATEMENT
#define CRYPTO_30_VHSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_DUMMY_STATEMENT
#define CRYPTO_30_VHSM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_DUMMY_STATEMENT_CONST
#define CRYPTO_30_VHSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_VHSM_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_VHSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_VHSM_PROCESSOR_RH850_1651
#define CRYPTO_30_VHSM_PROCESSOR_RH850_1651
#endif
#ifndef CRYPTO_30_VHSM_COMP_GREENHILLS
#define CRYPTO_30_VHSM_COMP_GREENHILLS
#endif
#ifndef CRYPTO_30_VHSM_GEN_GENERATOR_MSR
#define CRYPTO_30_VHSM_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_VHSM_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_VHSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_VHSM_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_VHSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifdef _MICROSOFT_C_VTT_
#define CRYPTO_30_VHSM_USE_VTT STD_ON
#else
#define CRYPTO_30_VHSM_USE_VTT STD_OFF
#endif
#define CRYPTO_30_VHSM_NOBUFFERING_ENABLED                                                          STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define CRYPTO_30_VHSM_VERSION_INFO_API                                                             STD_OFF 
#define CRYPTO_30_VHSM_KEY_ELEMENT_DELETE_SUPPORT                                                   STD_ON 
#define CRYPTO_30_VHSM_INTERRUPT_MODE                                                               STD_ON 
#define CRYPTO_30_VHSM_IPC_CHANNELS                                                                 2u 
#define CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION                                                         2u 
#define CRYPTO_30_VHSM_REDIRECTION                                                                  STD_OFF 
#define CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION                                                     STD_ON 
#define CRYPTO_30_VHSM_DET_INSTANCE_MASK                                                            0u 
#define CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT                                                       STD_ON 
#define CRYPTO_30_VHSM_HOST2_HSM_ADDRESS                                                            4280221716uL 
#define CRYPTO_30_VHSM_HSM2_HOST_ADDRESS                                                            4280221712uL 
#define CRYPTO_30_VHSM_IPC_INSTANCE_ID                                                              0u 
#define CRYPTO_30_VHSM_IPC_INITIALIZATION                                                           STD_ON 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_ADDRESS                                    4280221784uL 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_MASK                                       1uL 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_VALUE                                      1u 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEARING                                         STD_ON 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SET_ADDRESS                                       4280221764uL 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SET_MASK                                          1uL 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SETTING                                           STD_OFF 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Core                                           0uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hal                                            1uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacGenerate                             2uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacVerify                               3uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyM                                           4uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyManagement                                  5uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv                                          6uL 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv_HighPrio                                 7uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyM_CertificateData_Sync                       0uL 
#define CryptoConf_CryptoKeyElement_vHsmDummyKeyElement                                             0uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmSecureBootInfo_GroupState_Sync                    0uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_She_Sync                             1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_Sync                                 1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKeyElement_Aes128_Sync                    1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She_Sync                                1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_Sync                                    1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SecOC_CMAC_Sync                                 1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Key_Sync                              1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_LazyPersistKey_Sync                        1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Key_Sync                        1uL 
#define CryptoConf_CryptoKeyElement_vHsm_Hal_CMAC_Sync                                              1uL 
#define CryptoConf_CryptoKeyElement_vHsm_Hal_CryptoKey_Random_Sync                                  1uL 
#define CryptoConf_CryptoKeyElement_vHsm_Hal_RomKey_Sync                                            1uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Proof_Sync                                  2uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Section_Active_Sync             2uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128_Sync       3uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_Sync  4uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_IV_Sync                                  5uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKeyElement_Aes128_IV_Sync                 5uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Proof_Sync                               6uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_PrivateString_Sync                       3015uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_AdditionalInput_Sync                     3016uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Reseed_Counter_Sync                      3018uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_Counter_Sync                                3019uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_Version_Sync                                 3020uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_UId_Sync                                    3021uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_Info_Uid_Sync                              3021uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_PerformPersist_Sync                          3022uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_Info_ErrorLog_Sync                         3023uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_0_Address_Sync      3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_1_Address_Sync      3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_2_Address_Sync      3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Address_Sync      3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Address_Sync      3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_BM_0_Address_Sync        3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_FBL_0_Address_Sync       3024uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_0_Length_Sync       3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_1_Length_Sync       3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_2_Length_Sync       3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Length_Sync       3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Length_Sync       3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_BM_0_Length_Sync         3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_FBL_0_Length_Sync        3025uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_0_CMAC_Sync         3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_1_CMAC_Sync         3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_2_CMAC_Sync         3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_CMAC_Sync         3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_CMAC_Sync         3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_BM_0_CMAC_Sync           3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_FBL_0_CMAC_Sync          3026uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_0_Sanction_Sync     3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_1_Sanction_Sync     3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_2_Sanction_Sync     3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Sanction_Sync     3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Sanction_Sync     3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_BM_0_Sanction_Sync       3027uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_FBL_0_Sanction_Sync      3027uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_SecureBootEnd_Sync                           3028uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Action_Sync       3029uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Action_Sync       3029uL 
#define CryptoConf_CryptoKeyElement_vHsm_Hal_FlashOperation_Sync                                    3032uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_PerformRepersist_Sync                        3036uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_SecureBootResult_Sync                        3037uL 
#define CryptoConf_CryptoKeyElement_vHsm_Core_vHsmInfo_StartFirmwareUpdater_Sync                    3038uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_0_Mode_Sync         3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_1_Mode_Sync         3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_2_Mode_Sync         3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Mode_Sync         3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Mode_Sync         3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_BM_0_Mode_Sync           3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_FBL_0_Mode_Sync          3039uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_BootProtection_Sync                         3056uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_DebuggerProtection_Sync                     3057uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKey_GetKeyState_Sync                      3909uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_Info_TestCounterPersisted_Sync             5000uL 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_Info_TestCounterVolatile_Sync              5001uL 
#define CryptoConf_CryptoKey_CryIfKey_Aes128                                                        0uL 
#define CryptoConf_CryptoKey_CryIfKey_Random                                                        1uL 
#define CryptoConf_CryptoKey_CryIfKey_SecOC_CMAC                                                    2uL 
#define CryptoConf_CryptoKey_CryIfKey_vHsm_Aggregated_hsm_hal_cmac                                  3uL 
#define CryptoConf_CryptoKey_CryIfKey_vHsm_Hal_CMAC                                                 4uL 
#define CryptoConf_CryptoKey_KeyM_Cert_Intermediate                                                 5uL 
#define CryptoConf_CryptoKey_SecureBootProtectedKey                                                 6uL 
#define CryptoConf_CryptoKey_She_Info                                                               7uL 
#define CryptoConf_CryptoKey_She_Key1                                                               8uL 
#define CryptoConf_CryptoKey_She_Key2                                                               9uL 
#define CryptoConf_CryptoKey_She_MasterEcuKey                                                       10uL 
#define CryptoConf_CryptoKey_She_SecretKey                                                          11uL 
#define CryptoConf_CryptoKey_SymmetricKey                                                           12uL 
#define CryptoConf_CryptoKey_WriteOnceKey                                                           13uL 
#define CryptoConf_CryptoKey_vHsm_Custom                                                            14uL 
#define CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Decrypt                                            15uL 
#define CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Encrypt                                            16uL 
#define CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Mac                                                17uL 
#define CryptoConf_CryptoKey_vHsm_Hardware                                                          18uL 
#define CryptoConf_CryptoKey_vHsm_Info                                                              19uL 
#define CryptoConf_CryptoKey_vHsm_Info_SecureBoot                                                   20uL 
#define CryptoConf_CryptoKey_vHsm_RomKey0                                                           21uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Group_APPL                                             22uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Group_BM                                               23uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Group_FBL                                              24uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_APPL_0                                         25uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_APPL_1                                         26uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_APPL_2                                         27uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_BM_0                                           28uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_FBL_0                                          29uL 
#define CryptoConf_CryptoKey_vHsm_SecureBoot_Signature                                              30uL 

#ifndef CRYPTO_30_VHSM_DEV_ERROR_DETECT
#define CRYPTO_30_VHSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYPTO_30_VHSM_DEV_ERROR_REPORT
#define CRYPTO_30_VHSM_DEV_ERROR_REPORT STD_ON
#endif
#define CRYPTO_30_VHSM_SERVICE_MAC_VERIFY                                                           STD_ON
#define CRYPTO_30_VHSM_SERVICE_MAC_GENERATE                                                         STD_ON
#define CRYPTO_30_VHSM_SERVICE_SIGNATURE_VERIFY                                                     STD_ON
#define CRYPTO_30_VHSM_SERVICE_SIGNATURE_GENERATE                                                   STD_OFF
#define CRYPTO_30_VHSM_SERVICE_ENCRYPT                                                              STD_ON
#define CRYPTO_30_VHSM_SERVICE_DECRYPT                                                              STD_ON
#define CRYPTO_30_VHSM_SERVICE_AEADENCRYPT                                                          STD_ON
#define CRYPTO_30_VHSM_SERVICE_AEADDECRYPT                                                          STD_OFF
#define CRYPTO_30_VHSM_SERVICE_HASH                                                                 STD_ON
#define CRYPTO_30_VHSM_SERVICE_RANDOM                                                               STD_ON
#define CRYPTO_30_VHSM_SERVICE_KEY_SET_VALID                                                        STD_ON
#define CRYPTO_30_VHSM_SERVICE_RANDOM_SEED                                                          STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_GENERATE                                                         STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_DERIVE                                                           STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_EXCHANGE_CALC_PUBVAL                                             STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_EXCHANGE_CALC_SECRET                                             STD_OFF
#define CRYPTO_30_VHSM_SERVICE_CERIFICATE_PARSE                                                     STD_OFF
#define CRYPTO_30_VHSM_SERVICE_CERTIFICATE_VERIFY                                                   STD_OFF
#define CRYPTO_30_VHSM_IPC_PROTOCOL_INFO_SIZE                                                       12uL
#define CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS                                                         0x00u
#define CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS                                                    0x01u
#define CRYPTO_30_VHSM_READWRITE_AVAILABLE                                                          STD_ON


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCDataSwitches  Crypto_30_vHsm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_VHSM_CHANNELSTATE                                                                 STD_ON
#define CRYPTO_30_VHSM_DETINSTANCEMASKOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_DRIVEROBJECT                                                                 STD_ON
#define CRYPTO_30_VHSM_IDOFDRIVEROBJECT                                                             STD_ON
#define CRYPTO_30_VHSM_QUEUEIDXOFDRIVEROBJECT                                                       STD_ON
#define CRYPTO_30_VHSM_VHSMBUFFERIDXOFDRIVEROBJECT                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferIdx' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_VHSM_VHSMBUFFERUSEDOFDRIVEROBJECT                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferUsed' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_VHSM_DRIVEROBJECTLOCK                                                             STD_ON
#define CRYPTO_30_VHSM_EXPECTEDCOMPATIBILITYVERSION                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_FINALMAGICNUMBER                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_FLAGCLEARADDRESSOFJOBRESPONSEINTERRUPT                                       STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARMASKOFJOBRESPONSEINTERRUPT                                          STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARVALUEOFJOBRESPONSEINTERRUPT                                         STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARINGOFJOBRESPONSEINTERRUPT                                           STD_ON
#define CRYPTO_30_VHSM_FLAGSETADDRESSOFJOBREQUESTINTERRUPT                                          STD_ON
#define CRYPTO_30_VHSM_FLAGSETMASKOFJOBREQUESTINTERRUPT                                             STD_ON
#define CRYPTO_30_VHSM_FLAGSETTINGOFJOBREQUESTINTERRUPT                                             STD_ON
#define CRYPTO_30_VHSM_GENERATORCOMPATIBILITYVERSION                                                STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_HOST2HSMADDRESSOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_HSM2HOSTADDRESSOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_INITDATAHASHCODE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_INTERNALOBJECTIDS                                                            STD_ON
#define CRYPTO_30_VHSM_INTERRUPTMODEOFVHSM                                                          STD_ON
#define CRYPTO_30_VHSM_IPCCHANNELSOFVHSM                                                            STD_ON
#define CRYPTO_30_VHSM_IPCINITIALIZATIONOFVHSM                                                      STD_ON
#define CRYPTO_30_VHSM_IPCINSTANCEIDOFVHSM                                                          STD_ON
#define CRYPTO_30_VHSM_IPCMACJOBOPTIMIZATIONOFVHSM                                                  STD_ON
#define CRYPTO_30_VHSM_IPCPROTOCOLVERSIONOFVHSM                                                     STD_ON
#define CRYPTO_30_VHSM_JOBREQUEST                                                                   STD_ON
#define CRYPTO_30_VHSM_CANCELOFJOBREQUEST                                                           STD_ON
#define CRYPTO_30_VHSM_CRYPTOJOBOFJOBREQUEST                                                        STD_ON
#define CRYPTO_30_VHSM_INTERNALOBJECTIDOFJOBREQUEST                                                 STD_ON
#define CRYPTO_30_VHSM_JOBSTATEOFJOBREQUEST                                                         STD_ON
#define CRYPTO_30_VHSM_KEYMJOBOFJOBREQUEST                                                          STD_ON
#define CRYPTO_30_VHSM_KINDOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_LOCKOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_OUTPUTOFFSETOFJOBREQUEST                                                     STD_ON
#define CRYPTO_30_VHSM_PROCESSINGTYPEOFJOBREQUEST                                                   STD_ON
#define CRYPTO_30_VHSM_RESULTOFJOBREQUEST                                                           STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                            STD_ON
#define CRYPTO_30_VHSM_STATEOFJOBREQUEST                                                            STD_ON
#define CRYPTO_30_VHSM_TRIMMEDOUTPUTBUFFEROFJOBREQUEST                                              STD_ON
#define CRYPTO_30_VHSM_USEDBUFFEROFJOBREQUEST                                                       STD_ON
#define CRYPTO_30_VHSM_KEYDERIVEJOBSUPPORTOFVHSM                                                    STD_ON
#define CRYPTO_30_VHSM_KEYELEMENTDELETESUPPORTOFVHSM                                                STD_ON
#define CRYPTO_30_VHSM_MAINFUNCTIONPERIODOFGENERAL                                                  STD_ON
#define CRYPTO_30_VHSM_MANAGEMENTDRIVEROBJECT                                                       STD_ON
#define CRYPTO_30_VHSM_MEMORYAREA                                                                   STD_ON
#define CRYPTO_30_VHSM_AREASTARTOFMEMORYAREA                                                        STD_ON
#define CRYPTO_30_VHSM_AREASTOPOFMEMORYAREA                                                         STD_ON
#define CRYPTO_30_VHSM_AREATYPEOFMEMORYAREA                                                         STD_ON
#define CRYPTO_30_VHSM_OBJECTINFO                                                                   STD_ON
#define CRYPTO_30_VHSM_BUFFERUSEDOFOBJECTINFO                                                       STD_ON
#define CRYPTO_30_VHSM_MASKEDBITSOFOBJECTINFO                                                       STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                           STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                         STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_VHSM_OUTPUT64PTRDATABUFFER                                                        STD_ON
#define CRYPTO_30_VHSM_OUTPUTLENGTHPTRDATABUFFER                                                    STD_ON
#define CRYPTO_30_VHSM_QUEUE                                                                        STD_ON
#define CRYPTO_30_VHSM_REDIRECTIONOFVHSM                                                            STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                           STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFER                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFCHANNELSTATE                                                           STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECT                                                           STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECTLOCK                                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFINTERNALOBJECTIDS                                                      STD_ON
#define CRYPTO_30_VHSM_SIZEOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFMANAGEMENTDRIVEROBJECT                                                 STD_ON
#define CRYPTO_30_VHSM_SIZEOFMEMORYAREA                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJECTINFO                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUT64PTRDATABUFFER                                                  STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUTLENGTHPTRDATABUFFER                                              STD_ON
#define CRYPTO_30_VHSM_SIZEOFQUEUE                                                                  STD_ON
#define CRYPTO_30_VHSM_SIZEOFSECONDARYOUTPUTLENGTHPTRDATABUFFER                                     STD_ON
#define CRYPTO_30_VHSM_SIZEOFSHAREDDATABUFFER                                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFVERIFYPTRDATABUFFER                                                    STD_ON
#define CRYPTO_30_VHSM_VERIFYPTRDATABUFFER                                                          STD_ON
#define CRYPTO_30_VHSM_VERSIONINFOAPIOFGENERAL                                                      STD_ON
#define CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSM                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_VHSM_VHSMBUFFER                                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_VHSM_INPUTBUFFERSIZEOFVHSMBUFFER                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.InputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_VHSM_OUTPUTBUFFERSIZEOFVHSMBUFFER                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.OutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_VHSM_SECONDARYINPUTBUFFERSIZEOFVHSMBUFFER                                         STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_VHSM_SECONDARYOUTPUTBUFFERSIZEOFVHSMBUFFER                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryOutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_VHSM_TERTIARYINPUTBUFFERSIZEOFVHSMBUFFER                                          STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.TertiaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_VHSM_PCCONFIG                                                                     STD_ON
#define CRYPTO_30_VHSM_CHANNELSTATEOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_VHSM_DETINSTANCEMASKOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_DRIVEROBJECTLOCKOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_DRIVEROBJECTOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_VHSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_FLAGCLEARADDRESSOFJOBRESPONSEINTERRUPTOFPCCONFIG                             STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARMASKOFJOBRESPONSEINTERRUPTOFPCCONFIG                                STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARVALUEOFJOBRESPONSEINTERRUPTOFPCCONFIG                               STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARINGOFJOBRESPONSEINTERRUPTOFPCCONFIG                                 STD_ON
#define CRYPTO_30_VHSM_FLAGSETADDRESSOFJOBREQUESTINTERRUPTOFPCCONFIG                                STD_ON
#define CRYPTO_30_VHSM_FLAGSETMASKOFJOBREQUESTINTERRUPTOFPCCONFIG                                   STD_ON
#define CRYPTO_30_VHSM_FLAGSETTINGOFJOBREQUESTINTERRUPTOFPCCONFIG                                   STD_ON
#define CRYPTO_30_VHSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_HOST2HSMADDRESSOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_HSM2HOSTADDRESSOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_INTERNALOBJECTIDSOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_VHSM_INTERRUPTMODEOFVHSMOFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_IPCCHANNELSOFVHSMOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_VHSM_IPCINITIALIZATIONOFVHSMOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_IPCINSTANCEIDOFVHSMOFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_IPCMACJOBOPTIMIZATIONOFVHSMOFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_IPCPROTOCOLVERSIONOFVHSMOFPCCONFIG                                           STD_ON
#define CRYPTO_30_VHSM_JOBREQUESTOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_KEYDERIVEJOBSUPPORTOFVHSMOFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_KEYELEMENTDELETESUPPORTOFVHSMOFPCCONFIG                                      STD_ON
#define CRYPTO_30_VHSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_MANAGEMENTDRIVEROBJECTOFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_MEMORYAREAOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_OBJECTINFOOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_OUTPUT64PTRDATABUFFEROFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_QUEUEOFPCCONFIG                                                              STD_ON
#define CRYPTO_30_VHSM_REDIRECTIONOFVHSMOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                 STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFEROFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFCHANNELSTATEOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECTLOCKOFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_SIZEOFINTERNALOBJECTIDSOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_SIZEOFJOBREQUESTOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFMANAGEMENTDRIVEROBJECTOFPCCONFIG                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFMEMORYAREAOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJECTINFOOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUT64PTRDATABUFFEROFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                    STD_ON
#define CRYPTO_30_VHSM_SIZEOFQUEUEOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_VHSM_SIZEOFSECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                           STD_ON
#define CRYPTO_30_VHSM_SIZEOFSHAREDDATABUFFEROFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFVERIFYPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_VERIFYPTRDATABUFFEROFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                              STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCMinNumericValueDefines  Crypto_30_vHsm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_VHSM_MIN_CHANNELSTATE                                                             0u
#define CRYPTO_30_VHSM_MIN_DRIVEROBJECTLOCK                                                         0u
#define CRYPTO_30_VHSM_MIN_INTERNALOBJECTIDOFJOBREQUEST                                             0u
#define CRYPTO_30_VHSM_MIN_KINDOFJOBREQUEST                                                         0u
#define CRYPTO_30_VHSM_MIN_OUTPUTOFFSETOFJOBREQUEST                                                 0u
#define CRYPTO_30_VHSM_MIN_PROCESSINGTYPEOFJOBREQUEST                                               0u
#define CRYPTO_30_VHSM_MIN_RESULTOFJOBREQUEST                                                       0u
#define CRYPTO_30_VHSM_MIN_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                        0u
#define CRYPTO_30_VHSM_MIN_STATEOFJOBREQUEST                                                        0u
#define CRYPTO_30_VHSM_MIN_USEDBUFFEROFJOBREQUEST                                                   0u
#define CRYPTO_30_VHSM_MIN_OUTPUT64PTRDATABUFFER                                                    0u
#define CRYPTO_30_VHSM_MIN_OUTPUTLENGTHPTRDATABUFFER                                                0u
#define CRYPTO_30_VHSM_MIN_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                       0u
#define CRYPTO_30_VHSM_MIN_SHAREDDATABUFFER                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCMaxNumericValueDefines  Crypto_30_vHsm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_VHSM_MAX_CHANNELSTATE                                                             255u
#define CRYPTO_30_VHSM_MAX_DRIVEROBJECTLOCK                                                         4294967295u
#define CRYPTO_30_VHSM_MAX_INTERNALOBJECTIDOFJOBREQUEST                                             4294967295u
#define CRYPTO_30_VHSM_MAX_KINDOFJOBREQUEST                                                         255u
#define CRYPTO_30_VHSM_MAX_OUTPUTOFFSETOFJOBREQUEST                                                 4294967295u
#define CRYPTO_30_VHSM_MAX_PROCESSINGTYPEOFJOBREQUEST                                               255u
#define CRYPTO_30_VHSM_MAX_RESULTOFJOBREQUEST                                                       255u
#define CRYPTO_30_VHSM_MAX_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                        4294967295u
#define CRYPTO_30_VHSM_MAX_STATEOFJOBREQUEST                                                        255u
#define CRYPTO_30_VHSM_MAX_USEDBUFFEROFJOBREQUEST                                                   4294967295u
#define CRYPTO_30_VHSM_MAX_OUTPUT64PTRDATABUFFER                                                    18446744073709551615u
#define CRYPTO_30_VHSM_MAX_OUTPUTLENGTHPTRDATABUFFER                                                4294967295u
#define CRYPTO_30_VHSM_MAX_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                       4294967295u
#define CRYPTO_30_VHSM_MAX_SHAREDDATABUFFER                                                         4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCNoReferenceDefines  Crypto_30_vHsm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_VHSM_NO_VHSMBUFFERIDXOFDRIVEROBJECT                                               255u
#define CRYPTO_30_VHSM_NO_INTERNALOBJECTIDS                                                         255u
#define CRYPTO_30_VHSM_NO_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                        65535u
#define CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                      65535u
#define CRYPTO_30_VHSM_NO_EXPECTEDCOMPATIBILITYVERSION                                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCMaskedBitDefines  Crypto_30_vHsm Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CRYPTO_30_VHSM_BUFFERUSEDOFOBJECTINFO_MASK                                                  0x02u
#define CRYPTO_30_VHSM_SHAREDDATABUFFERUSEDOFOBJECTINFO_MASK                                        0x01u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIsReducedToDefineDefines  Crypto_30_vHsm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_VHSM_ISDEF_IDOFDRIVEROBJECT                                                       STD_OFF
#define CRYPTO_30_VHSM_ISDEF_QUEUEIDXOFDRIVEROBJECT                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_VHSMBUFFERIDXOFDRIVEROBJECT                                            STD_OFF
#define CRYPTO_30_VHSM_ISDEF_VHSMBUFFERUSEDOFDRIVEROBJECT                                           STD_OFF
#define CRYPTO_30_VHSM_ISDEF_INTERNALOBJECTIDS                                                      STD_OFF
#define CRYPTO_30_VHSM_ISDEF_MANAGEMENTDRIVEROBJECT                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREASTARTOFMEMORYAREA                                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREASTOPOFMEMORYAREA                                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREATYPEOFMEMORYAREA                                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_BUFFERUSEDOFOBJECTINFO                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_MASKEDBITSOFOBJECTINFO                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_VHSM_ISDEF_INPUTBUFFERSIZEOFVHSMBUFFER                                            STD_OFF
#define CRYPTO_30_VHSM_ISDEF_OUTPUTBUFFERSIZEOFVHSMBUFFER                                           STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SECONDARYINPUTBUFFERSIZEOFVHSMBUFFER                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SECONDARYOUTPUTBUFFERSIZEOFVHSMBUFFER                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_TERTIARYINPUTBUFFERSIZEOFVHSMBUFFER                                    STD_OFF
#define CRYPTO_30_VHSM_ISDEF_CHANNELSTATEOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_ISDEF_DRIVEROBJECTLOCKOFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_ISDEF_DRIVEROBJECTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                             STD_OFF
#define CRYPTO_30_VHSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                STD_OFF
#define CRYPTO_30_VHSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                             STD_OFF
#define CRYPTO_30_VHSM_ISDEF_INTERNALOBJECTIDSOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_ISDEF_JOBREQUESTOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_MANAGEMENTDRIVEROBJECTOFPCCONFIG                                       STD_ON
#define CRYPTO_30_VHSM_ISDEF_MEMORYAREAOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_OBJECTINFOOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_OUTPUT64PTRDATABUFFEROFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_ISDEF_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                    STD_ON
#define CRYPTO_30_VHSM_ISDEF_QUEUEOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_VHSM_ISDEF_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                           STD_ON
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFEROFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_ISDEF_VERIFYPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_ISDEF_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCEqualsAlwaysToDefines  Crypto_30_vHsm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_VHSM_EQ2_IDOFDRIVEROBJECT                                                         
#define CRYPTO_30_VHSM_EQ2_QUEUEIDXOFDRIVEROBJECT                                                   
#define CRYPTO_30_VHSM_EQ2_VHSMBUFFERIDXOFDRIVEROBJECT                                              
#define CRYPTO_30_VHSM_EQ2_VHSMBUFFERUSEDOFDRIVEROBJECT                                             
#define CRYPTO_30_VHSM_EQ2_INTERNALOBJECTIDS                                                        
#define CRYPTO_30_VHSM_EQ2_MANAGEMENTDRIVEROBJECT                                                   
#define CRYPTO_30_VHSM_EQ2_AREASTARTOFMEMORYAREA                                                    
#define CRYPTO_30_VHSM_EQ2_AREASTOPOFMEMORYAREA                                                     
#define CRYPTO_30_VHSM_EQ2_AREATYPEOFMEMORYAREA                                                     
#define CRYPTO_30_VHSM_EQ2_BUFFERUSEDOFOBJECTINFO                                                   
#define CRYPTO_30_VHSM_EQ2_MASKEDBITSOFOBJECTINFO                                                   
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                       
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                     
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERUSEDOFOBJECTINFO                                         
#define CRYPTO_30_VHSM_EQ2_INPUTBUFFERSIZEOFVHSMBUFFER                                              
#define CRYPTO_30_VHSM_EQ2_OUTPUTBUFFERSIZEOFVHSMBUFFER                                             
#define CRYPTO_30_VHSM_EQ2_SECONDARYINPUTBUFFERSIZEOFVHSMBUFFER                                     
#define CRYPTO_30_VHSM_EQ2_SECONDARYOUTPUTBUFFERSIZEOFVHSMBUFFER                                    
#define CRYPTO_30_VHSM_EQ2_TERTIARYINPUTBUFFERSIZEOFVHSMBUFFER                                      
#define CRYPTO_30_VHSM_EQ2_CHANNELSTATEOFPCCONFIG                                                   Crypto_30_vHsm_ChannelState
#define CRYPTO_30_VHSM_EQ2_DRIVEROBJECTLOCKOFPCCONFIG                                               Crypto_30_vHsm_DriverObjectLock
#define CRYPTO_30_VHSM_EQ2_DRIVEROBJECTOFPCCONFIG                                                   Crypto_30_vHsm_DriverObject
#define CRYPTO_30_VHSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                   
#define CRYPTO_30_VHSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                               
#define CRYPTO_30_VHSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                  
#define CRYPTO_30_VHSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                               
#define CRYPTO_30_VHSM_EQ2_INTERNALOBJECTIDSOFPCCONFIG                                              Crypto_30_vHsm_InternalObjectIds
#define CRYPTO_30_VHSM_EQ2_JOBREQUESTOFPCCONFIG                                                     Crypto_30_vHsm_JobRequest
#define CRYPTO_30_VHSM_EQ2_MANAGEMENTDRIVEROBJECTOFPCCONFIG                                         Crypto_30_vHsm_ManagementDriverObject
#define CRYPTO_30_VHSM_EQ2_MEMORYAREAOFPCCONFIG                                                     Crypto_30_vHsm_MemoryArea
#define CRYPTO_30_VHSM_EQ2_OBJECTINFOOFPCCONFIG                                                     Crypto_30_vHsm_ObjectInfo
#define CRYPTO_30_VHSM_EQ2_OUTPUT64PTRDATABUFFEROFPCCONFIG                                          Crypto_30_vHsm_Output64PtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                      Crypto_30_vHsm_OutputLengthPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_QUEUEOFPCCONFIG                                                          Crypto_30_vHsm_Queue.raw
#define CRYPTO_30_VHSM_EQ2_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                             Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFEROFPCCONFIG                                               Crypto_30_vHsm_SharedDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_VERIFYPTRDATABUFFEROFPCCONFIG                                            Crypto_30_vHsm_VerifyPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                          
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSymbolicInitializationPointers  Crypto_30_vHsm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_vHsm_Config_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_vHsm' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCInitializationSymbols  Crypto_30_vHsm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_vHsm_Config                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_vHsm */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGeneral  Crypto_30_vHsm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_VHSM_CHECK_INIT_POINTER                                                           STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_VHSM_FINAL_MAGIC_NUMBER                                                           0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_vHsm */
#define CRYPTO_30_VHSM_INDIVIDUAL_POSTBUILD                                                         STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_vHsm' is not configured to be postbuild capable. */
#define CRYPTO_30_VHSM_INIT_DATA                                                                    CRYPTO_30_VHSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_VHSM_INIT_DATA_HASH_CODE                                                          366851565  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_vHsm with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_VHSM_USE_ECUM_BSW_ERROR_HOOK                                                      STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_VHSM_USE_INIT_POINTER                                                             STD_OFF  /**< STD_ON if the init pointer Crypto_30_vHsm shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPBDataSwitches  Crypto_30_vHsm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_VHSM_PBCONFIG                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_VHSM_LTCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_VHSM_PCCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBIsReducedToDefineDefines  Crypto_30_vHsm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_VHSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                  STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBEqualsAlwaysToDefines  Crypto_30_vHsm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_VHSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                    
#define CRYPTO_30_VHSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                    
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
  \defgroup  Crypto_30_vHsmPCGetRootDataMacros  Crypto_30_vHsm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_vHsm_GetExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetWaitLoopCalloutOfvHsmOfPCConfig()                                           /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetConstantDuplicatedRootDataMacros  Crypto_30_vHsm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetChannelStateOfPCConfig()                                                  Crypto_30_vHsm_ChannelState  /**< the pointer to Crypto_30_vHsm_ChannelState */
#define Crypto_30_vHsm_GetDetInstanceMaskOfvHsmOfPCConfig()                                         0u
#define Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()                                              Crypto_30_vHsm_DriverObjectLock  /**< the pointer to Crypto_30_vHsm_DriverObjectLock */
#define Crypto_30_vHsm_GetDriverObjectOfPCConfig()                                                  Crypto_30_vHsm_DriverObject  /**< the pointer to Crypto_30_vHsm_DriverObject */
#define Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterruptOfPCConfig()                        4280221784u
#define Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterruptOfPCConfig()                           1u
#define Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterruptOfPCConfig()                          1u
#define Crypto_30_vHsm_IsFlagClearingOfJobResponseInterruptOfPCConfig()                             (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterruptOfPCConfig()                           4280221764u
#define Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterruptOfPCConfig()                              1u
#define Crypto_30_vHsm_IsFlagSettingOfJobRequestInterruptOfPCConfig()                               (((FALSE)) != FALSE)
#define Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig()                                         4280221716u
#define Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig()                                         4280221712u
#define Crypto_30_vHsm_GetInternalObjectIdsOfPCConfig()                                             Crypto_30_vHsm_InternalObjectIds  /**< the pointer to Crypto_30_vHsm_InternalObjectIds */
#define Crypto_30_vHsm_IsInterruptModeOfvHsmOfPCConfig()                                            (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetIpcChannelsOfvHsmOfPCConfig()                                             2u
#define Crypto_30_vHsm_IsIpcInitializationOfvHsmOfPCConfig()                                        (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetIpcInstanceIdOfvHsmOfPCConfig()                                           0u
#define Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsmOfPCConfig()                                    (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetIpcProtocolVersionOfvHsmOfPCConfig()                                      2u
#define Crypto_30_vHsm_GetJobRequestOfPCConfig()                                                    Crypto_30_vHsm_JobRequest  /**< the pointer to Crypto_30_vHsm_JobRequest */
#define Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsmOfPCConfig()                                      (((TRUE)) != FALSE)
#define Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsmOfPCConfig()                                  (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                   1u
#define Crypto_30_vHsm_GetManagementDriverObjectOfPCConfig()                                        Crypto_30_vHsm_ManagementDriverObject  /**< the pointer to Crypto_30_vHsm_ManagementDriverObject */
#define Crypto_30_vHsm_GetMemoryAreaOfPCConfig()                                                    Crypto_30_vHsm_MemoryArea  /**< the pointer to Crypto_30_vHsm_MemoryArea */
#define Crypto_30_vHsm_GetObjectInfoOfPCConfig()                                                    Crypto_30_vHsm_ObjectInfo  /**< the pointer to Crypto_30_vHsm_ObjectInfo */
#define Crypto_30_vHsm_GetOutput64PtrDataBufferOfPCConfig()                                         Crypto_30_vHsm_Output64PtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_Output64PtrDataBuffer */
#define Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()                                     Crypto_30_vHsm_OutputLengthPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetQueueOfPCConfig()                                                         Crypto_30_vHsm_Queue.raw  /**< the pointer to Crypto_30_vHsm_Queue */
#define Crypto_30_vHsm_IsRedirectionOfvHsmOfPCConfig()                                              (((FALSE)) != FALSE)
#define Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()                            Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()                                              Crypto_30_vHsm_SharedDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_GetSizeOfChannelStateOfPCConfig()                                            2u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ChannelState */
#define Crypto_30_vHsm_GetSizeOfDriverObjectOfPCConfig()                                            8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_DriverObject */
#define Crypto_30_vHsm_GetSizeOfInternalObjectIdsOfPCConfig()                                       8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_InternalObjectIds */
#define Crypto_30_vHsm_GetSizeOfManagementDriverObjectOfPCConfig()                                  1u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ManagementDriverObject */
#define Crypto_30_vHsm_GetSizeOfMemoryAreaOfPCConfig()                                              3u  /**< the number of accomplishable value elements in Crypto_30_vHsm_MemoryArea */
#define Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()                                              8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ObjectInfo */
#define Crypto_30_vHsm_GetSizeOfOutput64PtrDataBufferOfPCConfig()                                   8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_Output64PtrDataBuffer */
#define Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBufferOfPCConfig()                               8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_OutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSizeOfQueueOfPCConfig()                                                   8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_Queue */
#define Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()                      8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSizeOfSharedDataBufferOfPCConfig()                                        472u  /**< the number of accomplishable value elements in Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_GetSizeOfVerifyPtrDataBufferOfPCConfig()                                     8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_VerifyPtrDataBuffer */
#define Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()                                           Crypto_30_vHsm_VerifyPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_VerifyPtrDataBuffer */
#define Crypto_30_vHsm_IsVersionInfoApiOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDuplicatedRootDataMacros  Crypto_30_vHsm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetSizeOfDriverObjectLockOfPCConfig()                                        Crypto_30_vHsm_GetSizeOfDriverObjectOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_DriverObjectLock */
#define Crypto_30_vHsm_GetSizeOfJobRequestOfPCConfig()                                              Crypto_30_vHsm_GetSizeOfDriverObjectOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_JobRequest */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDataMacros  Crypto_30_vHsm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Crypto_30_vHsm_GetChannelState(Index)                                                       (Crypto_30_vHsm_GetChannelStateOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetIdOfDriverObject(Index)                                                   (Crypto_30_vHsm_GetDriverObjectOfPCConfig()[(Index)].IdOfDriverObject)
#define Crypto_30_vHsm_GetQueueIdxOfDriverObject(Index)                                             (Crypto_30_vHsm_GetDriverObjectOfPCConfig()[(Index)].QueueIdxOfDriverObject)
#define Crypto_30_vHsm_GetvHsmBufferIdxOfDriverObject(Index)                                          /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferIdx' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_vHsm_IsvHsmBufferUsedOfDriverObject(Index)                                          /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferUsed' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_vHsm_GetDriverObjectLock(Index)                                                   (Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetInternalObjectIds(Index)                                                  (Crypto_30_vHsm_GetInternalObjectIdsOfPCConfig()[(Index)])
#define Crypto_30_vHsm_IsCancelOfJobRequest(Index)                                                  ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CancelOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)                                              (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CryptoJobOfJobRequest)
#define Crypto_30_vHsm_GetInternalObjectIdOfJobRequest(Index)                                       (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].InternalObjectIdOfJobRequest)
#define Crypto_30_vHsm_GetJobStateOfJobRequest(Index)                                               (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].JobStateOfJobRequest)
#define Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)                                                (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KeyMJobOfJobRequest)
#define Crypto_30_vHsm_GetKindOfJobRequest(Index)                                                   (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KindOfJobRequest)
#define Crypto_30_vHsm_IsLockOfJobRequest(Index)                                                    ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].LockOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)                                           (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].OutputOffsetOfJobRequest)
#define Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)                                         (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ProcessingTypeOfJobRequest)
#define Crypto_30_vHsm_GetResultOfJobRequest(Index)                                                 (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ResultOfJobRequest)
#define Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)                                  (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].SecondaryOutputOffsetOfJobRequest)
#define Crypto_30_vHsm_GetStateOfJobRequest(Index)                                                  (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].StateOfJobRequest)
#define Crypto_30_vHsm_IsTrimmedOutputBufferOfJobRequest(Index)                                     ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].TrimmedOutputBufferOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)                                             (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].UsedBufferOfJobRequest)
#define Crypto_30_vHsm_GetManagementDriverObject(Index)                                             (Crypto_30_vHsm_GetManagementDriverObjectOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetAreaStartOfMemoryArea(Index)                                              (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaStartOfMemoryArea)
#define Crypto_30_vHsm_GetAreaStopOfMemoryArea(Index)                                               (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaStopOfMemoryArea)
#define Crypto_30_vHsm_GetAreaTypeOfMemoryArea(Index)                                               (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaTypeOfMemoryArea)
#define Crypto_30_vHsm_GetMaskedBitsOfObjectInfo(Index)                                             (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].MaskedBitsOfObjectInfo)
#define Crypto_30_vHsm_GetSharedDataBufferEndIdxOfObjectInfo(Index)                                 (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].SharedDataBufferEndIdxOfObjectInfo)
#define Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(Index)                               (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].SharedDataBufferStartIdxOfObjectInfo)
#define Crypto_30_vHsm_GetOutput64PtrDataBuffer(Index)                                              (Crypto_30_vHsm_GetOutput64PtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)                                          (Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetQueue(Index)                                                              (Crypto_30_vHsm_GetQueueOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)                                 (Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetSharedDataBuffer(Index)                                                   (Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)                                                (Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetInputBufferSizeOfvHsmBuffer(Index)                                          /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.InputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_GetOutputBufferSizeOfvHsmBuffer(Index)                                         /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.OutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_GetSecondaryInputBufferSizeOfvHsmBuffer(Index)                                 /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_GetSecondaryOutputBufferSizeOfvHsmBuffer(Index)                                /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryOutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_GetTertiaryInputBufferSizeOfvHsmBuffer(Index)                                  /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.TertiaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetBitDataMacros  Crypto_30_vHsm Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Crypto_30_vHsm_IsBufferUsedOfObjectInfo(Index)                                              (CRYPTO_30_VHSM_BUFFERUSEDOFOBJECTINFO_MASK == (Crypto_30_vHsm_GetMaskedBitsOfObjectInfo(Index) & CRYPTO_30_VHSM_BUFFERUSEDOFOBJECTINFO_MASK))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDeduplicatedDataMacros  Crypto_30_vHsm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetDetInstanceMaskOfvHsm()                                                   Crypto_30_vHsm_GetDetInstanceMaskOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterrupt()                                  Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterrupt()                                     Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterrupt()                                    Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_IsFlagClearingOfJobResponseInterrupt()                                       Crypto_30_vHsm_IsFlagClearingOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterrupt()                                     Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterrupt()                                        Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_IsFlagSettingOfJobRequestInterrupt()                                         Crypto_30_vHsm_IsFlagSettingOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_GetGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetHost2HsmAddressOfvHsm()                                                   Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetHsm2HostAddressOfvHsm()                                                   Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_IsInterruptModeOfvHsm()                                                      Crypto_30_vHsm_IsInterruptModeOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcChannelsOfvHsm()                                                       Crypto_30_vHsm_GetIpcChannelsOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsIpcInitializationOfvHsm()                                                  Crypto_30_vHsm_IsIpcInitializationOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcInstanceIdOfvHsm()                                                     Crypto_30_vHsm_GetIpcInstanceIdOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsm()                                              Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm()                                                Crypto_30_vHsm_GetIpcProtocolVersionOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsm()                                                Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsm()                                            Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetMainFunctionPeriodOfGeneral()                                             Crypto_30_vHsm_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Crypto_30_vHsm_IsSharedDataBufferUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(Index) != CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_IsRedirectionOfvHsm()                                                        Crypto_30_vHsm_IsRedirectionOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfChannelState()                                                      Crypto_30_vHsm_GetSizeOfChannelStateOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfDriverObject()                                                      Crypto_30_vHsm_GetSizeOfDriverObjectOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfDriverObjectLock()                                                  Crypto_30_vHsm_GetSizeOfDriverObjectLockOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfInternalObjectIds()                                                 Crypto_30_vHsm_GetSizeOfInternalObjectIdsOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfJobRequest()                                                        Crypto_30_vHsm_GetSizeOfJobRequestOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfManagementDriverObject()                                            Crypto_30_vHsm_GetSizeOfManagementDriverObjectOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfMemoryArea()                                                        Crypto_30_vHsm_GetSizeOfMemoryAreaOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfObjectInfo()                                                        Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfOutput64PtrDataBuffer()                                             Crypto_30_vHsm_GetSizeOfOutput64PtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBuffer()                                         Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfQueue()                                                             Crypto_30_vHsm_GetSizeOfQueueOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBuffer()                                Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfSharedDataBuffer()                                                  Crypto_30_vHsm_GetSizeOfSharedDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfVerifyPtrDataBuffer()                                               Crypto_30_vHsm_GetSizeOfVerifyPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_IsVersionInfoApiOfGeneral()                                                  Crypto_30_vHsm_IsVersionInfoApiOfGeneralOfPCConfig()
#define Crypto_30_vHsm_GetWaitLoopCalloutOfvHsm()                                                     /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSetDataMacros  Crypto_30_vHsm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Crypto_30_vHsm_SetChannelState(Index, Value)                                                Crypto_30_vHsm_GetChannelStateOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetDriverObjectLock(Index, Value)                                            Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetCancelOfJobRequest(Index, Value)                                          Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CancelOfJobRequest = (Value)
#define Crypto_30_vHsm_SetCryptoJobOfJobRequest(Index, Value)                                       Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CryptoJobOfJobRequest = (Value)
#define Crypto_30_vHsm_SetInternalObjectIdOfJobRequest(Index, Value)                                Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].InternalObjectIdOfJobRequest = (Value)
#define Crypto_30_vHsm_SetJobStateOfJobRequest(Index, Value)                                        Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].JobStateOfJobRequest = (Value)
#define Crypto_30_vHsm_SetKeyMJobOfJobRequest(Index, Value)                                         Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KeyMJobOfJobRequest = (Value)
#define Crypto_30_vHsm_SetKindOfJobRequest(Index, Value)                                            Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KindOfJobRequest = (Value)
#define Crypto_30_vHsm_SetLockOfJobRequest(Index, Value)                                            Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].LockOfJobRequest = (Value)
#define Crypto_30_vHsm_SetOutputOffsetOfJobRequest(Index, Value)                                    Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].OutputOffsetOfJobRequest = (Value)
#define Crypto_30_vHsm_SetProcessingTypeOfJobRequest(Index, Value)                                  Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ProcessingTypeOfJobRequest = (Value)
#define Crypto_30_vHsm_SetResultOfJobRequest(Index, Value)                                          Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ResultOfJobRequest = (Value)
#define Crypto_30_vHsm_SetSecondaryOutputOffsetOfJobRequest(Index, Value)                           Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].SecondaryOutputOffsetOfJobRequest = (Value)
#define Crypto_30_vHsm_SetStateOfJobRequest(Index, Value)                                           Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].StateOfJobRequest = (Value)
#define Crypto_30_vHsm_SetTrimmedOutputBufferOfJobRequest(Index, Value)                             Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].TrimmedOutputBufferOfJobRequest = (Value)
#define Crypto_30_vHsm_SetUsedBufferOfJobRequest(Index, Value)                                      Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].UsedBufferOfJobRequest = (Value)
#define Crypto_30_vHsm_SetOutput64PtrDataBuffer(Index, Value)                                       Crypto_30_vHsm_GetOutput64PtrDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetOutputLengthPtrDataBuffer(Index, Value)                                   Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetQueue(Index, Value)                                                       Crypto_30_vHsm_GetQueueOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetSecondaryOutputLengthPtrDataBuffer(Index, Value)                          Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetSharedDataBuffer(Index, Value)                                            Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetVerifyPtrDataBuffer(Index, Value)                                         Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetAddressOfDataMacros  Crypto_30_vHsm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Crypto_30_vHsm_GetAddrOutput64PtrDataBuffer(Index)                                          (&Crypto_30_vHsm_GetOutput64PtrDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(Index)                                      (&Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(Index)                             (&Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrSharedDataBuffer(Index)                                               (&Crypto_30_vHsm_GetSharedDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(Index)                                            (&Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCHasMacros  Crypto_30_vHsm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_vHsm_HasChannelState()                                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasDetInstanceMaskOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasDriverObject()                                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasIdOfDriverObject()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasQueueIdxOfDriverObject()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasvHsmBufferIdxOfDriverObject()                                               /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferIdx' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_vHsm_HasvHsmBufferUsedOfDriverObject()                                              /**< Deactivateable: 'Crypto_30_vHsm_DriverObject.vHsmBufferUsed' Reason: 'the optional indirection is deactivated because vHsmBufferUsedOfDriverObject is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_vHsm_HasDriverObjectLock()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasFlagClearAddressOfJobResponseInterrupt()                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearMaskOfJobResponseInterrupt()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearValueOfJobResponseInterrupt()                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearingOfJobResponseInterrupt()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetAddressOfJobRequestInterrupt()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetMaskOfJobRequestInterrupt()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSettingOfJobRequestInterrupt()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasHost2HsmAddressOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasHsm2HostAddressOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasInternalObjectIds()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasInterruptModeOfvHsm()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcChannelsOfvHsm()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInitializationOfvHsm()                                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInstanceIdOfvHsm()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcMacJobOptimizationOfvHsm()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcProtocolVersionOfvHsm()                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobRequest()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasCancelOfJobRequest()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasCryptoJobOfJobRequest()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasInternalObjectIdOfJobRequest()                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobStateOfJobRequest()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyMJobOfJobRequest()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasKindOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasLockOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputOffsetOfJobRequest()                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasProcessingTypeOfJobRequest()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasResultOfJobRequest()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputOffsetOfJobRequest()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasStateOfJobRequest()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasTrimmedOutputBufferOfJobRequest()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasUsedBufferOfJobRequest()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyDeriveJobSupportOfvHsm()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyElementDeleteSupportOfvHsm()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasMainFunctionPeriodOfGeneral()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasManagementDriverObject()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasMemoryArea()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaStartOfMemoryArea()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaStopOfMemoryArea()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaTypeOfMemoryArea()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfo()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasBufferUsedOfObjectInfo()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasMaskedBitsOfObjectInfo()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferEndIdxOfObjectInfo()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferStartIdxOfObjectInfo()                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutput64PtrDataBuffer()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputLengthPtrDataBuffer()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasQueue()                                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasRedirectionOfvHsm()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputLengthPtrDataBuffer()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBuffer()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfChannelState()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObject()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObjectLock()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfInternalObjectIds()                                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfManagementDriverObject()                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfMemoryArea()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjectInfo()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutput64PtrDataBuffer()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutputLengthPtrDataBuffer()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfQueue()                                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSecondaryOutputLengthPtrDataBuffer()                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSharedDataBuffer()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfVerifyPtrDataBuffer()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasVerifyPtrDataBuffer()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasVersionInfoApiOfGeneral()                                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasWaitLoopCalloutOfvHsm()                                                     /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
#define Crypto_30_vHsm_HasvHsmBuffer()                                                                /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_vHsm_HasInputBufferSizeOfvHsmBuffer()                                               /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.InputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_HasOutputBufferSizeOfvHsmBuffer()                                              /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.OutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_HasSecondaryInputBufferSizeOfvHsmBuffer()                                      /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_HasSecondaryOutputBufferSizeOfvHsmBuffer()                                     /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.SecondaryOutputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_HasTertiaryInputBufferSizeOfvHsmBuffer()                                       /**< Deactivateable: 'Crypto_30_vHsm_vHsmBuffer.TertiaryInputBufferSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_vHsm_HasPCConfig()                                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasChannelStateOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasDetInstanceMaskOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasDriverObjectLockOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasDriverObjectOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasFlagClearAddressOfJobResponseInterruptOfPCConfig()                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearMaskOfJobResponseInterruptOfPCConfig()                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearValueOfJobResponseInterruptOfPCConfig()                          (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearingOfJobResponseInterruptOfPCConfig()                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetAddressOfJobRequestInterruptOfPCConfig()                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetMaskOfJobRequestInterruptOfPCConfig()                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSettingOfJobRequestInterruptOfPCConfig()                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasHost2HsmAddressOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasHsm2HostAddressOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasInternalObjectIdsOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasInterruptModeOfvHsmOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcChannelsOfvHsmOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInitializationOfvHsmOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInstanceIdOfvHsmOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcMacJobOptimizationOfvHsmOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcProtocolVersionOfvHsmOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobRequestOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyDeriveJobSupportOfvHsmOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyElementDeleteSupportOfvHsmOfPCConfig()                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasManagementDriverObjectOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasMemoryAreaOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfoOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutput64PtrDataBufferOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputLengthPtrDataBufferOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasQueueOfPCConfig()                                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasRedirectionOfvHsmOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputLengthPtrDataBufferOfPCConfig()                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfChannelStateOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObjectLockOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObjectOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfInternalObjectIdsOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfJobRequestOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfManagementDriverObjectOfPCConfig()                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfMemoryAreaOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjectInfoOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutput64PtrDataBufferOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutputLengthPtrDataBufferOfPCConfig()                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfQueueOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSharedDataBufferOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfVerifyPtrDataBufferOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasVerifyPtrDataBufferOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasVersionInfoApiOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasWaitLoopCalloutOfvHsmOfPCConfig()                                           /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIncrementDataMacros  Crypto_30_vHsm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_IncChannelState(Index)                                                       Crypto_30_vHsm_GetChannelState(Index)++
#define Crypto_30_vHsm_IncDriverObjectLock(Index)                                                   Crypto_30_vHsm_GetDriverObjectLock(Index)++
#define Crypto_30_vHsm_IncCryptoJobOfJobRequest(Index)                                              Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)++
#define Crypto_30_vHsm_IncInternalObjectIdOfJobRequest(Index)                                       Crypto_30_vHsm_GetInternalObjectIdOfJobRequest(Index)++
#define Crypto_30_vHsm_IncJobStateOfJobRequest(Index)                                               Crypto_30_vHsm_GetJobStateOfJobRequest(Index)++
#define Crypto_30_vHsm_IncKeyMJobOfJobRequest(Index)                                                Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)++
#define Crypto_30_vHsm_IncKindOfJobRequest(Index)                                                   Crypto_30_vHsm_GetKindOfJobRequest(Index)++
#define Crypto_30_vHsm_IncOutputOffsetOfJobRequest(Index)                                           Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)++
#define Crypto_30_vHsm_IncProcessingTypeOfJobRequest(Index)                                         Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)++
#define Crypto_30_vHsm_IncResultOfJobRequest(Index)                                                 Crypto_30_vHsm_GetResultOfJobRequest(Index)++
#define Crypto_30_vHsm_IncSecondaryOutputOffsetOfJobRequest(Index)                                  Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)++
#define Crypto_30_vHsm_IncStateOfJobRequest(Index)                                                  Crypto_30_vHsm_GetStateOfJobRequest(Index)++
#define Crypto_30_vHsm_IncUsedBufferOfJobRequest(Index)                                             Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)++
#define Crypto_30_vHsm_IncOutput64PtrDataBuffer(Index)                                              Crypto_30_vHsm_GetOutput64PtrDataBuffer(Index)++
#define Crypto_30_vHsm_IncOutputLengthPtrDataBuffer(Index)                                          Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)++
#define Crypto_30_vHsm_IncQueue(Index)                                                              Crypto_30_vHsm_GetQueue(Index)++
#define Crypto_30_vHsm_IncSecondaryOutputLengthPtrDataBuffer(Index)                                 Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)++
#define Crypto_30_vHsm_IncSharedDataBuffer(Index)                                                   Crypto_30_vHsm_GetSharedDataBuffer(Index)++
#define Crypto_30_vHsm_IncVerifyPtrDataBuffer(Index)                                                Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCDecrementDataMacros  Crypto_30_vHsm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_DecChannelState(Index)                                                       Crypto_30_vHsm_GetChannelState(Index)--
#define Crypto_30_vHsm_DecDriverObjectLock(Index)                                                   Crypto_30_vHsm_GetDriverObjectLock(Index)--
#define Crypto_30_vHsm_DecCryptoJobOfJobRequest(Index)                                              Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)--
#define Crypto_30_vHsm_DecInternalObjectIdOfJobRequest(Index)                                       Crypto_30_vHsm_GetInternalObjectIdOfJobRequest(Index)--
#define Crypto_30_vHsm_DecJobStateOfJobRequest(Index)                                               Crypto_30_vHsm_GetJobStateOfJobRequest(Index)--
#define Crypto_30_vHsm_DecKeyMJobOfJobRequest(Index)                                                Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)--
#define Crypto_30_vHsm_DecKindOfJobRequest(Index)                                                   Crypto_30_vHsm_GetKindOfJobRequest(Index)--
#define Crypto_30_vHsm_DecOutputOffsetOfJobRequest(Index)                                           Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)--
#define Crypto_30_vHsm_DecProcessingTypeOfJobRequest(Index)                                         Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)--
#define Crypto_30_vHsm_DecResultOfJobRequest(Index)                                                 Crypto_30_vHsm_GetResultOfJobRequest(Index)--
#define Crypto_30_vHsm_DecSecondaryOutputOffsetOfJobRequest(Index)                                  Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)--
#define Crypto_30_vHsm_DecStateOfJobRequest(Index)                                                  Crypto_30_vHsm_GetStateOfJobRequest(Index)--
#define Crypto_30_vHsm_DecUsedBufferOfJobRequest(Index)                                             Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)--
#define Crypto_30_vHsm_DecOutput64PtrDataBuffer(Index)                                              Crypto_30_vHsm_GetOutput64PtrDataBuffer(Index)--
#define Crypto_30_vHsm_DecOutputLengthPtrDataBuffer(Index)                                          Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)--
#define Crypto_30_vHsm_DecQueue(Index)                                                              Crypto_30_vHsm_GetQueue(Index)--
#define Crypto_30_vHsm_DecSecondaryOutputLengthPtrDataBuffer(Index)                                 Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)--
#define Crypto_30_vHsm_DecSharedDataBuffer(Index)                                                   Crypto_30_vHsm_GetSharedDataBuffer(Index)--
#define Crypto_30_vHsm_DecVerifyPtrDataBuffer(Index)                                                Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)--
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
  \defgroup  Crypto_30_vHsmPBGetRootDataMacros  Crypto_30_vHsm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_vHsm_GetLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_GetPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBHasMacros  Crypto_30_vHsm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_vHsm_HasPBConfig()                                                                  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_HasLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_HasPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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




/* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
#define Crypto_30_vHsm_TriggerInterrupt()                                                          
#define Crypto_30_vHsm_ClearInterrupt()                                                             (*(volatile uint32 *)CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_ADDRESS) |= (0x00000001uL)
#define Crypto_30_vHsm_IndicateInitializedIpc()                                                     (*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS |= (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_IndicateUninitializedIpc()                                                   (*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS &= ~(1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_IsIpcNotInitialized()                                                        ((*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS & (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID) ) != (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_CheckForHsmReady()                                                           ((*(volatile uint32*)CRYPTO_30_VHSM_HSM2_HOST_ADDRESS & ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE))) != ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE)))
/* PRQA L:Macros_3453 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) Crypto_30_vHsm_CryptoJobPtr;
typedef P2VAR(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) Crypto_30_vHsm_KeyMJobPtr;
typedef Crypto_JobType* Crypto_30_vHsm_QueueElementType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCIterableTypes  Crypto_30_vHsm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_vHsm_ChannelState */
typedef uint8_least Crypto_30_vHsm_ChannelStateIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_DriverObject */
typedef uint8_least Crypto_30_vHsm_DriverObjectIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_InternalObjectIds */
typedef uint8_least Crypto_30_vHsm_InternalObjectIdsIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_ManagementDriverObject */
typedef uint8_least Crypto_30_vHsm_ManagementDriverObjectIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_MemoryArea */
typedef uint8_least Crypto_30_vHsm_MemoryAreaIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_ObjectInfo */
typedef uint8_least Crypto_30_vHsm_ObjectInfoIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_Output64PtrDataBuffer */
typedef uint8_least Crypto_30_vHsm_Output64PtrDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef uint8_least Crypto_30_vHsm_OutputLengthPtrDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_Queue */
typedef uint8_least Crypto_30_vHsm_QueueIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef uint8_least Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_SharedDataBuffer */
typedef uint16_least Crypto_30_vHsm_SharedDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_VerifyPtrDataBuffer */
typedef uint8_least Crypto_30_vHsm_VerifyPtrDataBufferIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIterableTypesWithSizeRelations  Crypto_30_vHsm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_vHsm_DriverObjectLock */
typedef Crypto_30_vHsm_DriverObjectIterType Crypto_30_vHsm_DriverObjectLockIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_JobRequest */
typedef Crypto_30_vHsm_DriverObjectIterType Crypto_30_vHsm_JobRequestIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCValueTypes  Crypto_30_vHsm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_vHsm_ChannelState */
typedef uint8 Crypto_30_vHsm_ChannelStateType;

/**   \brief  value based type definition for Crypto_30_vHsm_DetInstanceMaskOfvHsm */
typedef uint8 Crypto_30_vHsm_DetInstanceMaskOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IdOfDriverObject */
typedef uint8 Crypto_30_vHsm_IdOfDriverObjectType;

/**   \brief  value based type definition for Crypto_30_vHsm_QueueIdxOfDriverObject */
typedef uint8 Crypto_30_vHsm_QueueIdxOfDriverObjectType;

/**   \brief  value based type definition for Crypto_30_vHsm_DriverObjectLock */
typedef uint32 Crypto_30_vHsm_DriverObjectLockType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearAddressOfJobResponseInterrupt */
typedef uint32 Crypto_30_vHsm_FlagClearAddressOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearMaskOfJobResponseInterrupt */
typedef uint8 Crypto_30_vHsm_FlagClearMaskOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearValueOfJobResponseInterrupt */
typedef uint8 Crypto_30_vHsm_FlagClearValueOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearingOfJobResponseInterrupt */
typedef boolean Crypto_30_vHsm_FlagClearingOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSetAddressOfJobRequestInterrupt */
typedef uint32 Crypto_30_vHsm_FlagSetAddressOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSetMaskOfJobRequestInterrupt */
typedef uint8 Crypto_30_vHsm_FlagSetMaskOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSettingOfJobRequestInterrupt */
typedef boolean Crypto_30_vHsm_FlagSettingOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_Host2HsmAddressOfvHsm */
typedef uint32 Crypto_30_vHsm_Host2HsmAddressOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_Hsm2HostAddressOfvHsm */
typedef uint32 Crypto_30_vHsm_Hsm2HostAddressOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_InternalObjectIds */
typedef uint8 Crypto_30_vHsm_InternalObjectIdsType;

/**   \brief  value based type definition for Crypto_30_vHsm_InterruptModeOfvHsm */
typedef boolean Crypto_30_vHsm_InterruptModeOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcChannelsOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcChannelsOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcInitializationOfvHsm */
typedef boolean Crypto_30_vHsm_IpcInitializationOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcInstanceIdOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcInstanceIdOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcMacJobOptimizationOfvHsm */
typedef boolean Crypto_30_vHsm_IpcMacJobOptimizationOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcProtocolVersionOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcProtocolVersionOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_CancelOfJobRequest */
typedef boolean Crypto_30_vHsm_CancelOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_InternalObjectIdOfJobRequest */
typedef uint32 Crypto_30_vHsm_InternalObjectIdOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_KindOfJobRequest */
typedef uint8 Crypto_30_vHsm_KindOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_LockOfJobRequest */
typedef boolean Crypto_30_vHsm_LockOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_OutputOffsetOfJobRequest */
typedef uint32 Crypto_30_vHsm_OutputOffsetOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_ProcessingTypeOfJobRequest */
typedef uint8 Crypto_30_vHsm_ProcessingTypeOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_ResultOfJobRequest */
typedef uint8 Crypto_30_vHsm_ResultOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequest */
typedef uint32 Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_StateOfJobRequest */
typedef uint8 Crypto_30_vHsm_StateOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_TrimmedOutputBufferOfJobRequest */
typedef boolean Crypto_30_vHsm_TrimmedOutputBufferOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_UsedBufferOfJobRequest */
typedef uint32 Crypto_30_vHsm_UsedBufferOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_KeyDeriveJobSupportOfvHsm */
typedef boolean Crypto_30_vHsm_KeyDeriveJobSupportOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_KeyElementDeleteSupportOfvHsm */
typedef boolean Crypto_30_vHsm_KeyElementDeleteSupportOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_MainFunctionPeriodOfGeneral */
typedef uint8 Crypto_30_vHsm_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Crypto_30_vHsm_ManagementDriverObject */
typedef uint32 Crypto_30_vHsm_ManagementDriverObjectType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaStartOfMemoryArea */
typedef uint32 Crypto_30_vHsm_AreaStartOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaStopOfMemoryArea */
typedef uint32 Crypto_30_vHsm_AreaStopOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaTypeOfMemoryArea */
typedef uint8 Crypto_30_vHsm_AreaTypeOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_BufferUsedOfObjectInfo */
typedef boolean Crypto_30_vHsm_BufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_MaskedBitsOfObjectInfo */
typedef uint8 Crypto_30_vHsm_MaskedBitsOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfo */
typedef uint16 Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfo */
typedef uint16 Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfo */
typedef boolean Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_Output64PtrDataBuffer */
typedef uint64 Crypto_30_vHsm_Output64PtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef uint32 Crypto_30_vHsm_OutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_RedirectionOfvHsm */
typedef boolean Crypto_30_vHsm_RedirectionOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef uint32 Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBuffer */
typedef uint32 Crypto_30_vHsm_SharedDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfChannelState */
typedef uint8 Crypto_30_vHsm_SizeOfChannelStateType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfDriverObject */
typedef uint8 Crypto_30_vHsm_SizeOfDriverObjectType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfDriverObjectLock */
typedef uint8 Crypto_30_vHsm_SizeOfDriverObjectLockType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfInternalObjectIds */
typedef uint8 Crypto_30_vHsm_SizeOfInternalObjectIdsType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfJobRequest */
typedef uint8 Crypto_30_vHsm_SizeOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfManagementDriverObject */
typedef uint8 Crypto_30_vHsm_SizeOfManagementDriverObjectType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfMemoryArea */
typedef uint8 Crypto_30_vHsm_SizeOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfObjectInfo */
typedef uint8 Crypto_30_vHsm_SizeOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfOutput64PtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfOutput64PtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfOutputLengthPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfQueue */
typedef uint8 Crypto_30_vHsm_SizeOfQueueType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfSecondaryOutputLengthPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfSecondaryOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfSharedDataBuffer */
typedef uint16 Crypto_30_vHsm_SizeOfSharedDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfVerifyPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfVerifyPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_VersionInfoApiOfGeneral */
typedef boolean Crypto_30_vHsm_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCStructTypes  Crypto_30_vHsm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Crypto_30_vHsm_DriverObject */
typedef struct sCrypto_30_vHsm_DriverObjectType
{
  Crypto_30_vHsm_IdOfDriverObjectType IdOfDriverObject;  /**< Contains values of DefinitionRef: /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject/CryptoDriverObjectId. */
  Crypto_30_vHsm_QueueIdxOfDriverObjectType QueueIdxOfDriverObject;  /**< the index of the 1:1 relation pointing to Crypto_30_vHsm_Queue */
} Crypto_30_vHsm_DriverObjectType;

/**   \brief  type used in Crypto_30_vHsm_JobRequest */
typedef struct sCrypto_30_vHsm_JobRequestType
{
  Crypto_30_vHsm_InternalObjectIdOfJobRequestType InternalObjectIdOfJobRequest;
  Crypto_30_vHsm_OutputOffsetOfJobRequestType OutputOffsetOfJobRequest;
  Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequestType SecondaryOutputOffsetOfJobRequest;
  Crypto_30_vHsm_UsedBufferOfJobRequestType UsedBufferOfJobRequest;
  Crypto_30_vHsm_CancelOfJobRequestType CancelOfJobRequest;
  Crypto_30_vHsm_KindOfJobRequestType KindOfJobRequest;
  Crypto_30_vHsm_LockOfJobRequestType LockOfJobRequest;
  Crypto_30_vHsm_ProcessingTypeOfJobRequestType ProcessingTypeOfJobRequest;
  Crypto_30_vHsm_ResultOfJobRequestType ResultOfJobRequest;
  Crypto_30_vHsm_StateOfJobRequestType StateOfJobRequest;
  Crypto_30_vHsm_TrimmedOutputBufferOfJobRequestType TrimmedOutputBufferOfJobRequest;
  Crypto_30_vHsm_CryptoJobPtr CryptoJobOfJobRequest;
  Crypto_JobStateType JobStateOfJobRequest;
  Crypto_30_vHsm_KeyMJobPtr KeyMJobOfJobRequest;
} Crypto_30_vHsm_JobRequestType;

/**   \brief  type used in Crypto_30_vHsm_MemoryArea */
typedef struct sCrypto_30_vHsm_MemoryAreaType
{
  Crypto_30_vHsm_AreaStartOfMemoryAreaType AreaStartOfMemoryArea;  /**< Start address of area */
  Crypto_30_vHsm_AreaStopOfMemoryAreaType AreaStopOfMemoryArea;  /**< Stop address of area */
  Crypto_30_vHsm_AreaTypeOfMemoryAreaType AreaTypeOfMemoryArea;  /**< Access type of area */
} Crypto_30_vHsm_MemoryAreaType;

/**   \brief  type used in Crypto_30_vHsm_ObjectInfo */
typedef struct sCrypto_30_vHsm_ObjectInfoType
{
  Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfoType SharedDataBufferEndIdxOfObjectInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer */
  Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfoType SharedDataBufferStartIdxOfObjectInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer */
  Crypto_30_vHsm_MaskedBitsOfObjectInfoType MaskedBitsOfObjectInfo;  /**< contains bitcoded the boolean data of Crypto_30_vHsm_BufferUsedOfObjectInfo, Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfo */
} Crypto_30_vHsm_ObjectInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSymbolicStructTypes  Crypto_30_vHsm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_Output64PtrDataBuffer */
typedef struct Crypto_30_vHsm_Output64PtrDataBufferStructSTag
{
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_Hal;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_Hsm_Hal_AesCmacGenerate;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_Hsm_Hal_AesCmacVerify;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_KeyM;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_Output64PtrDataBufferType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_Output64PtrDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef struct Crypto_30_vHsm_OutputLengthPtrDataBufferStructSTag
{
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_Hal;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_Hsm_Hal_AesCmacGenerate;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_Hsm_Hal_AesCmacVerify;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_KeyM;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_OutputLengthPtrDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_Queue */
typedef struct Crypto_30_vHsm_QueueStructSTag
{
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_Hal;
  Crypto_30_vHsm_QueueElementType Crypto_30_Hsm_Hal_AesCmacGenerate;
  Crypto_30_vHsm_QueueElementType Crypto_30_Hsm_Hal_AesCmacVerify;
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_KeyM;
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_QueueElementType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_QueueStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef struct Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSTag
{
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_Hal;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_Hsm_Hal_AesCmacGenerate;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_Hsm_Hal_AesCmacVerify;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_KeyM;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_SharedDataBuffer */
typedef struct Crypto_30_vHsm_SharedDataBufferStructSTag
{
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_Core[35];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_Hal[35];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_Hsm_Hal_AesCmacGenerate[131];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_Hsm_Hal_AesCmacVerify[131];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_KeyM[35];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_KeyManagement[35];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_LibCv[35];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_LibCv_HighPrio[35];
} Crypto_30_vHsm_SharedDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_VerifyPtrDataBuffer */
typedef struct Crypto_30_vHsm_VerifyPtrDataBufferStructSTag
{
  Crypto_VerifyResultType Crypto_30_vHsm_Core;
  Crypto_VerifyResultType Crypto_30_vHsm_Hal;
  Crypto_VerifyResultType Crypto_30_Hsm_Hal_AesCmacGenerate;
  Crypto_VerifyResultType Crypto_30_Hsm_Hal_AesCmacVerify;
  Crypto_VerifyResultType Crypto_30_vHsm_KeyM;
  Crypto_VerifyResultType Crypto_30_vHsm_KeyManagement;
  Crypto_VerifyResultType Crypto_30_vHsm_LibCv;
  Crypto_VerifyResultType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_VerifyPtrDataBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCUnionIndexAndSymbolTypes  Crypto_30_vHsm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Crypto_30_vHsm_Output64PtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_Output64PtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_Output64PtrDataBufferType raw[8];
  Crypto_30_vHsm_Output64PtrDataBufferStructSType str;
} Crypto_30_vHsm_Output64PtrDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_OutputLengthPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_OutputLengthPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_OutputLengthPtrDataBufferType raw[8];
  Crypto_30_vHsm_OutputLengthPtrDataBufferStructSType str;
} Crypto_30_vHsm_OutputLengthPtrDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_Queue in an index and symbol based style. */
typedef union Crypto_30_vHsm_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_QueueElementType raw[8];
  Crypto_30_vHsm_QueueStructSType str;
} Crypto_30_vHsm_QueueUType;

/**   \brief  type to access Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType raw[8];
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSType str;
} Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_SharedDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_SharedDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_SharedDataBufferType raw[472];
  Crypto_30_vHsm_SharedDataBufferStructSType str;
} Crypto_30_vHsm_SharedDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_VerifyPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_VerifyPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_VerifyResultType raw[8];
  Crypto_30_vHsm_VerifyPtrDataBufferStructSType str;
} Crypto_30_vHsm_VerifyPtrDataBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCRootPointerTypes  Crypto_30_vHsm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Crypto_30_vHsm_ChannelState */
typedef P2VAR(Crypto_30_vHsm_ChannelStateType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelStatePtrType;

/**   \brief  type used to point to Crypto_30_vHsm_DriverObject */
typedef P2CONST(Crypto_30_vHsm_DriverObjectType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_DriverObjectPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_DriverObjectLock */
typedef P2VAR(Crypto_30_vHsm_DriverObjectLockType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLockPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_InternalObjectIds */
typedef P2CONST(Crypto_30_vHsm_InternalObjectIdsType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_InternalObjectIdsPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_JobRequest */
typedef P2VAR(volatile Crypto_30_vHsm_JobRequestType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequestPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_ManagementDriverObject */
typedef P2CONST(Crypto_30_vHsm_ManagementDriverObjectType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ManagementDriverObjectPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_MemoryArea */
typedef P2CONST(Crypto_30_vHsm_MemoryAreaType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryAreaPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_ObjectInfo */
typedef P2CONST(Crypto_30_vHsm_ObjectInfoType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfoPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_Output64PtrDataBuffer */
typedef P2VAR(Crypto_30_vHsm_Output64PtrDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Output64PtrDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef P2VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_Queue */
typedef P2VAR(Crypto_30_vHsm_QueueElementType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_QueuePtrType;

/**   \brief  type used to point to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef P2VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_SharedDataBuffer */
typedef P2VAR(Crypto_30_vHsm_SharedDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_VerifyPtrDataBuffer */
typedef P2VAR(Crypto_VerifyResultType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBufferPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCRootValueTypes  Crypto_30_vHsm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_vHsm_PCConfig */
typedef struct sCrypto_30_vHsm_PCConfigType
{
  uint8 Crypto_30_vHsm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_vHsm_PCConfigType;

typedef Crypto_30_vHsm_PCConfigType Crypto_30_vHsm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPBValueTypes  Crypto_30_vHsm Value Types (POST_BUILD)
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
  \defgroup  Crypto_30_vHsmPBRootValueTypes  Crypto_30_vHsm Root Value Types (POST_BUILD)
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
  Crypto_30_vHsm_DriverObject
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_DriverObject
  \brief  Contains parameters of /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject.
  \details
  Element     Description
  Id          Contains values of DefinitionRef: /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject/CryptoDriverObjectId.
  QueueIdx    the index of the 1:1 relation pointing to Crypto_30_vHsm_Queue
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_DriverObjectType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_DriverObject[8];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_InternalObjectIds
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_InternalObjectIdsType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_InternalObjectIds[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ManagementDriverObject
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ManagementDriverObject
  \brief  Contains values of DefinitionRef: /MICROSAR/Crypto_30_vHsm/Crypto/CryptovHsm/CryptoManagementDriverObject.
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_ManagementDriverObjectType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ManagementDriverObject[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_MemoryArea
  \brief  Memory to which vHsm has direct access without the need of a copy.
  \details
  Element      Description
  AreaStart    Start address of area
  AreaStop     Stop address of area
  AreaType     Access type of area
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_MemoryAreaType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryArea[3];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjectInfo
  \details
  Element                     Description
  SharedDataBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  SharedDataBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  MaskedBits                  contains bitcoded the boolean data of Crypto_30_vHsm_BufferUsedOfObjectInfo, Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_ObjectInfoType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfo[8];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ChannelState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ChannelState
  \brief  Tracks which IPC channel is currently used.
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_ChannelStateType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelState[2];
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_DriverObjectLock
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_DriverObjectLockType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLock[8];
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_JobRequest
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_JobRequest
  \details
  Element                  Description
  InternalObjectId     
  OutputOffset         
  SecondaryOutputOffset
  UsedBuffer           
  Cancel               
  Kind                 
  Lock                 
  ProcessingType       
  Result               
  State                
  TrimmedOutputBuffer  
  CryptoJob            
  JobState             
  KeyMJob              
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(Crypto_30_vHsm_JobRequestType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequest[8];
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_Output64PtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_Output64PtrDataBuffer
  \brief  Buffer for the Output64Ptr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_Output64PtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Output64PtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_OutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_OutputLengthPtrDataBuffer
  \brief  Buffer for the outputLengthPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_Queue
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_QueueUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
  \brief  Buffer for the secondaryOutputLengthPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SharedDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SharedDataBuffer
  \brief  Buffer for input and output data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_SharedDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_VerifyPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_VerifyPtrDataBuffer
  \brief  Buffer for the verifyPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_VerifyPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
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





#define CRYPTO_30_VHSM_START_SEC_APPL_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


#define CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */




#endif /* CRYPTO_30_VHSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Cfg.h
 *********************************************************************************************************************/

