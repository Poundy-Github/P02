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
 *            Module: NvM
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.h
 *   Generation Time: 2022-01-25 14:49:35
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

	
/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
/* public section - to be used by NvM itself and its users */
#if (!defined NVM_CFG_H_PUBLIC)
#define NVM_CFG_H_PUBLIC

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CFG_MAJOR_VERSION    (6u)
#define NVM_CFG_MINOR_VERSION    (2u)
#define NVM_CFG_PATCH_VERSION    (1u)

/**********************************************************************************************************************
 * NVM API TYPE INCLUDES
 *********************************************************************************************************************/
#include "NvM_Types.h"

/**********************************************************************************************************************
 * API CFG TYPE DEFINITIONS
 *********************************************************************************************************************/
/* Type for an the additional published parameter Compiled Configuration ID (see CompiledConfigurationId in NvM.h). */
/* Compiled Config Id Type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_Union */
    uint16 Word_u16;
    uint8  Bytes_au8[2u];
} NvM_CompiledConfigIdType;

/**********************************************************************************************************************
 * CFG COMMON PARAMETER
 *********************************************************************************************************************/
/* --------------------  DEVELOPMENT / PRODUCTION MODE -------------------- */
/* switch between Debug- or Production-Mode */
#define NVM_DEV_ERROR_DETECT                  (STD_ON)

/* Preprocessor switch that is used in NvM_ReadAll() */
#define NVM_DYNAMIC_CONFIGURATION             (STD_OFF)

#define NVM_API_CONFIG_CLASS_1                (1u)
#define NVM_API_CONFIG_CLASS_2                (3u)
#define NVM_API_CONFIG_CLASS_3                (7u)

#define NVM_API_CONFIG_CLASS                  (NVM_API_CONFIG_CLASS_3)

#define NVM_JOB_PRIORISATION                  STD_OFF

/* define compiled Block ID */
#define NVM_COMPILED_CONFIG_ID                (1u)

/* switch for enablinig fast mode during multi block requests */
#define NVM_DRV_MODE_SWITCH                   (STD_ON)

/* switch for enablinig polling mode and disabling notifications */
#define NVM_POLLING_MODE                      (STD_ON)

/* switch for enabling the internal buffer for Crc handling */
#define NVM_CRC_INT_BUFFER                    (STD_ON)

/* number of defined NV blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS         (65u)

/* internal buffer size */
#define NVM_INTERNAL_BUFFER_LENGTH            406uL

/* version info api switch */
#define NVM_VERSION_INFO_API                  (STD_OFF)

/* switch to enable the ram block status api */
#define NVM_SET_RAM_BLOCK_STATUS_API          (STD_ON)

/* switch that gives the user (EcuM) the possibility to time-out WriteAll cancellation */
#define NVM_KILL_WRITEALL_API                 (STD_ON)

/* enabled or disable the whole repair redundant blocks feature */
#define NVM_REPAIR_REDUNDANT_BLOCKS_API       (STD_OFF)

/* NVM does not need this macro. It is intended for underlying modules,
 * relying on its existence
 */
#define NVM_DATASET_SELECTION_BITS            (4u)

/* block offset for DCM blocks */
#define NVM_DCM_BLOCK_OFFSET                  0x8000u

/* returns corresponding DCM BlockId of an original NVRAM Block */
#define NvM_GetDcmBlockId(MyApplBlockId)      ((MyApplBlockId) | NVM_DCM_BLOCK_OFFSET) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* BlockId's:
 * Note: The numbers of the following list must meet the configured blocks in the NvM_BlockDescriptorTable_at
 *
 * Alignment of the handles of all blocks
 * Id 0 is reserved for multiblock calls
 * Id 1 is reserved for config ID
 */
#define NvMConf___MultiBlockRequest (0u) 
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock (1u) 
#define NvMConf_NvMBlockDescriptor_DemAdminDataBlock (2u) 
#define NvMConf_NvMBlockDescriptor_DemStatusDataBlock (3u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 (4u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 (5u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 (6u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 (7u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 (8u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 (9u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 (10u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 (11u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 (12u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_1 (13u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 (14u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_2 (15u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock10 (16u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_3 (17u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock11 (18u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_4 (19u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock12 (20u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_ODO_5 (21u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock13 (22u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_MaintainOdo (23u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock14 (24u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Block_Trip (25u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock15 (26u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock16 (27u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock17 (28u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_FactoryMode (29u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock19 (30u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData (31u) 
#define NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock18 (32u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VIN (33u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VehicleMode (34u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF18C (35u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF193 (36u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF195 (37u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFD00 (38u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFD19 (39u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE20 (40u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE21 (41u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE22 (42u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE23 (43u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE24 (44u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xFE25 (45u) 
#define NvMConf_NvMBlockDescriptor_EOL_NvBlockNeed_0xF187 (46u) 
#define NvMConf_NvMBlockDescriptor_Common_GateWayNvBlockNeed_Block_IPC_Config_Data (47u) 
#define NvMConf_NvMBlockDescriptor_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data (48u) 
#define NvMConf_NvMBlockDescriptor_MiscNvBlockNeed_ResetInfomation (49u) 
#define NvMConf_NvMBlockDescriptor_DCM_ServerNvBlockNeedSecAttemptCount (50u) 
#define NvMConf_NvMBlockDescriptor_DCM_ServerNvBlockNeed_EOLUnlockCnt (51u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ClusterInternalConfiguration (52u) 
#define NvMConf_NvMBlockDescriptor_AMP_NvBlockNeed_LC_Calibration (53u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_E2ESwitch (54u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_SecOcSwitch (55u) 
#define NvMConf_NvMBlockDescriptor_NvBlockNeed_UpgradeResetFlag (56u) 
#define NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Fvm_TripCount (57u) 
#define NvMConf_NvMBlockDescriptor_Common_NormalNvBlockNeed_Menu (58u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VehicleSoftwareVersion (59u) 
#define NvMConf_NvMBlockDescriptor_AMP_NvBlockNeed_LC_Calibration2 (60u) 
#define NvMConf_NvMBlockDescriptor_SOCManagerNvBlockNeed_HealthSwitch (61u) 
#define NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset (62u) 
#define NvMConf_NvMBlockDescriptor_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords (63u) 
#define NvMConf_NvMBlockDescriptor_Can_ServerNvBlockNeed_ActiveWUCounter (64u) 


/* CONST_DESCRIPTOR_TABLE contains all block relevant data, including the compiled config ID
 */
#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Additional published parameter because e.g. in case of validate all RAM
 * Blocks it is nice to know the number of Blocks. But take care: this number
 * of Blocks includes Block 0 and Block 1, which are the MultiBlock and the
 * Configuration Block - user Blocks start wiht index 2!
 */
extern CONST(uint16, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t;

/* Additional published parameter because in case of a clear EEPROM, it is
 * necessary, to write the Configuration Block containing this Compiled
 * Configuration ID to EEPROM
 */
/* Compiled Configuration ID as defined in NvM_Cfg.c */
extern CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t; /* PRQA S 0759 */ /* MD_MSR_Union */

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* Component define block (available, if EcuC module is active, otherwise only NVM_DUMMY_STATEMENTs are defined*/
#ifndef NVM_USE_DUMMY_STATEMENT
#define NVM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT
#define NVM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_DUMMY_STATEMENT_CONST
#define NVM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NVM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NVM_ATOMIC_VARIABLE_ACCESS
#define NVM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NVM_PROCESSOR_RH850_1651
#define NVM_PROCESSOR_RH850_1651
#endif
#ifndef NVM_COMP_GREENHILLS
#define NVM_COMP_GREENHILLS
#endif
#ifndef NVM_GEN_GENERATOR_MSR
#define NVM_GEN_GENERATOR_MSR
#endif
#ifndef NVM_CPUTYPE_BITORDER_LSB2MSB
#define NVM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NVM_CONFIGURATION_VARIANT_PRECOMPILE
#define NVM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NVM_CONFIGURATION_VARIANT_LINKTIME
#define NVM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NVM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NVM_CONFIGURATION_VARIANT
#define NVM_CONFIGURATION_VARIANT NVM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NVM_POSTBUILD_VARIANT_SUPPORT
#define NVM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* ---- end public configuration section ---------------------------------- */
#endif /* NVM_CFG_H_PUBLIC */

/* PRQA L:MemMap */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.h
 *********************************************************************************************************************/

