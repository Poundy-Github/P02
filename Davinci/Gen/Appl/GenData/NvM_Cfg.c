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
 *              File: NvM_Cfg.c
 *   Generation Time: 2022-01-25 15:14:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

	
/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */
    
/**********************************************************************************************************************
 *  MODULE SWITCH
 *********************************************************************************************************************/
/* this switch enables the header file(s) to hide some parts. */
#define NVM_CFG_SOURCE

/* multiple inclusion protection */
#define NVM_H_

/* Required for RTE ROM block definitions */
#define RTE_MICROSAR_PIM_EXPORT

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* This tag will only be replaced, if one or more callbacks via Service Ports had been configured */
#include "Rte_NvM.h"

/**********************************************************************************************************************
 *  MODULE HEADER INCLUDES
 *********************************************************************************************************************/
/* only includes the public part of config */
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"

#include "BswM_NvM.h"

/**********************************************************************************************************************
 *  VERSION CHECKS
 *********************************************************************************************************************/
#if ((NVM_CFG_MAJOR_VERSION != (6u)) \
        || (NVM_CFG_MINOR_VERSION != (2u)))
# error "Version numbers of NvM_Cfg.c and NvM_Cfg.h are inconsistent!"
#endif

/* include list of the callback definitions */
#include "Dem_Cbk.h" 
#include "Fvm.h" 


/* include configured file declaring or defining resource (un)locking service(s) */
#include "SchM_NvM.h"

/**********************************************************************************************************************
 *  PUBLIC CONSTANTS
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_16
#include "MemMap.h"

/* maximum number of bytes to be processed in one crc calculation step */
CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16 = 64u;

/* constant holding Crc queue size value */
CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16 = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

#define NVM_STOP_SEC_CONST_16
#include "MemMap.h"

/* 8Bit Data section containing the CRC buffers, as well as the internal buffer */
#define NVM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

static VAR(uint8, NVM_PRIVATE_DATA) NvMConfigBlock_RamBlock_au8[4u];

#if ((NVM_CRC_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
static VAR(uint8, NVM_PRIVATE_DATA) DemAdminDataBlock_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemStatusDataBlock_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock0_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock1_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock2_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock3_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock4_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock5_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock6_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock7_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock8_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_ODO_1_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock9_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_ODO_2_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock10_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_ODO_3_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock11_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_ODO_4_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock12_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_ODO_5_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock13_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_MaintainOdo_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock14_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Block_Trip_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock15_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock16_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock17_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_FactoryMode_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock19_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock18_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_VIN_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_VehicleMode_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xF18C_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xF193_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xF195_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFD00_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFD19_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE20_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE21_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE22_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE23_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE24_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xFE25_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) EOL_NvBlockNeed_0xF187_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_GateWayNvBlockNeed_Block_IPC_Config_Data_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) MiscNvBlockNeed_ResetInfomation_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DCM_ServerNvBlockNeedSecAttemptCount_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DCM_ServerNvBlockNeed_EOLUnlockCnt_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_ClusterInternalConfiguration_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) AMP_NvBlockNeed_LC_Calibration_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_E2ESwitch_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_SecOcSwitch_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvBlockNeed_UpgradeResetFlag_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) NvMBlockDescriptor_Fvm_TripCount_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Common_NormalNvBlockNeed_Menu_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_VehicleSoftwareVersion_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) AMP_NvBlockNeed_LC_Calibration2_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) SOCManagerNvBlockNeed_HealthSwitch_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_Crc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) Can_ServerNvBlockNeed_ActiveWUCounter_Crc[2uL]; 


/* create the internal buffer of size NVM_INTERNAL_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[NVM_INTERNAL_BUFFER_LENGTH]; /* PRQA S 1533 */ /* MD_NvM_Cfg_8.9_InternalBuffer */
#endif

 /*  CRC buffers for CRCCompareMechanism  */ 
static VAR(uint8, NVM_PRIVATE_DATA) DemAdminDataBlock_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemStatusDataBlock_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock0_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock1_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock2_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock3_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock4_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock5_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock6_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock7_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock8_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock9_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock10_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock11_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock12_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock13_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock14_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock15_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock16_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock17_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock19_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DemPrimaryDataBlock18_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) MiscNvBlockNeed_ResetInfomation_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_ClusterInternalConfiguration_CompCrc[2uL]; 
static VAR(uint8, NVM_PRIVATE_DATA) DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_CompCrc[2uL]; 



#define NVM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t = {(uint16)NVM_COMPILED_CONFIG_ID}; /* PRQA S 0759 */ /* MD_MSR_Union */
 
 
/* block descriptor table that holds the static configuration parameters of the RAM, ROM and NVBlocks.
* This table has to be adjusted according to the configuration of the NVManager.
*/

CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS] =
    {
      { /*  MultiBlockRequest  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0001u /*  NV block Base number (defined by FEE/EA)  */ , 
        0U /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        0U /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvMNvBlockNum  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        0u /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_USE_CRC_OFF /*  NvMBlockCrcType  */ , 
        0u /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  NvMConfigBlock  */ 
        (NvM_RamAddressType)NvMConfigBlock_RamBlock_au8 /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_OFF
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemAdminDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_AdminData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitAdminData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemAdminDataBlock_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemAdminDataBlock_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0010u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_AdminData) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemStatusDataBlock  */ 
        (NvM_RamAddressType)&Dem_Cfg_StatusData /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Dem_NvM_InitStatusData /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemStatusDataBlock_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemStatusDataBlock_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0020u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_StatusData) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock0  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_0 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock0_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock0_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0030u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_0) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock1  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_1 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock1_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock1_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0040u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_1) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock2  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_2 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock2_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock2_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0050u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_2) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock3  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_3 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock3_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock3_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0060u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_3) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock4  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_4 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock4_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock4_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0070u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_4) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock5  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_5 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock5_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock5_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0080u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_5) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock6  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_6 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock6_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock6_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0090u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_6) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock7  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_7 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock7_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock7_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_7) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock8  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_8 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock8_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock8_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_8) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_ODO_1  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_1_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_1_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_1_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_ODO_1_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock9  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_9 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock9_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock9_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_9) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_ODO_2  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_2_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_2_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_2_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_ODO_2_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock10  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_10 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock10_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock10_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0220u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_10) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_10) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_ODO_3  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_3_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_3_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_3_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_ODO_3_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock11  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_11 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock11_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock11_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0230u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_11) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_11) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_ODO_4  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_4_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_4_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_4_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_ODO_4_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x00F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock12  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_12 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock12_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock12_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0240u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_12) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_12) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_ODO_5  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_5_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_ODO_5_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_ODO_5_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_ODO_5_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0100u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock13  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_13 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock13_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock13_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0250u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_13) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_13) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_MaintainOdo  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_MaintainOdo_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_MaintainOdo_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_MaintainOdo_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0110u /*  NV block Base number (defined by FEE/EA)  */ , 
        80u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        80u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock14  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_14 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock14_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock14_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0260u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_14) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_14) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Block_Trip  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Block_Trip_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_Block_Trip_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Block_Trip_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Block_Trip_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0120u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock15  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_15 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock15_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock15_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0270u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_15) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_15) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock16  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_16 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock16_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock16_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0280u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_16) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_16) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock17  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_17 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock17_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock17_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0290u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_17) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_17) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_FactoryMode  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_FactoryMode_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_FactoryMode_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_FactoryMode_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0130u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock19  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_18 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock19_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock19_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_18) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_18) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0160u /*  NV block Base number (defined by FEE/EA)  */ , 
        200u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        200u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DemPrimaryDataBlock18  */ 
        (NvM_RamAddressType)&Dem_Cfg_PrimaryEntry_19 /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Dem_Cfg_MemoryEntryInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Dem_NvM_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DemPrimaryDataBlock18_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DemPrimaryDataBlock18_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_19) /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        (uint16)sizeof(Dem_Cfg_PrimaryEntry_19) /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_VIN  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_VIN_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_VIN_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VIN_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_VIN_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0140u /*  NV block Base number (defined by FEE/EA)  */ , 
        17u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        17u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_VehicleMode  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_VehicleMode_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_VehicleMode_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleMode_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_VehicleMode_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0150u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xF18C  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xF18C_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF18C_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xF18C_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0170u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xF193  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xF193_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xF193_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF193_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xF193_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0180u /*  NV block Base number (defined by FEE/EA)  */ , 
        15u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        15u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xF195  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xF195_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xF195_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF195_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xF195_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0190u /*  NV block Base number (defined by FEE/EA)  */ , 
        17u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        17u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFD00  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFD00_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFD00_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD00_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFD00_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        4u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        4u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFD19  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFD19_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFD19_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFD19_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFD19_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE20  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE20_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE20_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE20_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE20_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE21  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE21_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE21_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE21_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE21_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE22  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE22_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE22_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE22_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE22_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE23  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE23_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE23_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE23_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE23_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x01F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE24  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE24_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE24_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE24_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE24_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0200u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xFE25  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xFE25_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xFE25_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xFE25_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xFE25_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0210u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  EOL_NvBlockNeed_0xF187  */ 
        (NvM_RamAddressType)&Rte_EOL_NvBlockNeed_0xF187_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_EOL_NvBlockNeed_0xF187_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_EOL_NvBlockNeed_0xF187_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        EOL_NvBlockNeed_0xF187_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        13u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        13u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_GateWayNvBlockNeed_Block_IPC_Config_Data  */ 
        (NvM_RamAddressType)&Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_GateWay_NvBlockNeed_Block_IPC_Config_Data_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_Config_Data_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_GateWayNvBlockNeed_Block_IPC_Config_Data_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x02F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        60u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        60u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_GateWayNvBlockNeed_Block_IPC_CAN_Data  */ 
        (NvM_RamAddressType)&Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_GateWay_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_GateWayNvBlockNeed_Block_IPC_CAN_Data_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0300u /*  NV block Base number (defined by FEE/EA)  */ , 
        120u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        120u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  MiscNvBlockNeed_ResetInfomation  */ 
        (NvM_RamAddressType)&Rte_Misc_NvBlockNeed_ResetInfomation_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Misc_NvBlockNeed_ResetInfomation_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        MiscNvBlockNeed_ResetInfomation_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        MiscNvBlockNeed_ResetInfomation_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0310u /*  NV block Base number (defined by FEE/EA)  */ , 
        63u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        63u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DCM_ServerNvBlockNeedSecAttemptCount  */ 
        (NvM_RamAddressType)&Rte_DCM_Server_NvBlockNeedSecAttemptCount_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DCM_Server_NvBlockNeedSecAttemptCount_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DCM_ServerNvBlockNeedSecAttemptCount_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0320u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DCM_ServerNvBlockNeed_EOLUnlockCnt  */ 
        (NvM_RamAddressType)&Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DCM_ServerNvBlockNeed_EOLUnlockCnt_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0330u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_ClusterInternalConfiguration  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterInternalConfiguration_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_ClusterInternalConfiguration_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DidDataProcessNvBlockNeed_ClusterInternalConfiguration_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0340u /*  NV block Base number (defined by FEE/EA)  */ , 
        300u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        300u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  AMP_NvBlockNeed_LC_Calibration  */ 
        (NvM_RamAddressType)&Rte_AMP_NvBlockNeed_LC_Calibration_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_AMP_NvBlockNeed_LC_Calibration_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        AMP_NvBlockNeed_LC_Calibration_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0350u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_E2ESwitch  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_E2ESwitch_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_E2ESwitch_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_E2ESwitch_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_E2ESwitch_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0360u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_SecOcSwitch  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_SecOcSwitch_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_SecOcSwitch_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0370u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  NvBlockNeed_UpgradeResetFlag  */ 
        (NvM_RamAddressType)&Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvBlockNeed_UpgradeResetFlag_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0380u /*  NV block Base number (defined by FEE/EA)  */ , 
        4u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        4u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  NvMBlockDescriptor_Fvm_TripCount  */ 
        (NvM_RamAddressType)&FvM_LatestTripCounter /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&FvM_LatestTripCounterInit /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_NvMBlockDescriptor_Fvm_TripCount_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NvMBlockDescriptor_Fvm_TripCount_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0390u /*  NV block Base number (defined by FEE/EA)  */ , 
        4u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        4u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Common_NormalNvBlockNeed_Menu  */ 
        (NvM_RamAddressType)&Rte_Common_Normal_NvBlockNeed_Menu_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Common_Normal_NvBlockNeed_MENU_Data_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Common_NormalNvBlockNeed_Menu_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Common_NormalNvBlockNeed_Menu_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03A0u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_VehicleSoftwareVersion  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_VehicleSoftwareVersion_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_VehicleSoftwareVersion_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03B0u /*  NV block Base number (defined by FEE/EA)  */ , 
        30u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        30u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  AMP_NvBlockNeed_LC_Calibration2  */ 
        (NvM_RamAddressType)&Rte_AMP_NvBlockNeed_LC_Calibration2_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_AMP_NvBlockNeed_LC_Calibration2_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_AMP_NvBlockNeed_LC_Calibration2_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        AMP_NvBlockNeed_LC_Calibration2_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        20u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        20u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_OFF
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  SOCManagerNvBlockNeed_HealthSwitch  */ 
        (NvM_RamAddressType)&Rte_SOCManager_NvBlockNeed_HealthSwitch_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_SOCManager_NvBlockNeed_HealthSwitch_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_SOCManagerNvBlockNeed_HealthSwitch_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        SOCManagerNvBlockNeed_HealthSwitch_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset  */ 
        (NvM_RamAddressType)&Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        DidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset_CompCrc /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        8u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        8u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords  */ 
        (NvM_RamAddressType)&Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Can_Server_NvBlockNeed_AbnormalWakeupSleepRecords_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Can_ServerNvBlockNeed_AbnormalWakeupSleepRecords_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x03F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        80u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        80u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }, 
      { /*  Can_ServerNvBlockNeed_ActiveWUCounter  */ 
        (NvM_RamAddressType)&Rte_Can_Server_NvBlockNeed_ActiveWUCounter_MirrorBlock /*  NvMRamBlockDataAddress  */ , 
        (NvM_RomAddressType)&Rte_Can_Server_NvBlockNeed_ActiveWUCounter_DefaultValue /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Rte_Call_NvM_RpNotifyJobEnd_Can_ServerNvBlockNeed_ActiveWUCounter_JobFinished /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Can_ServerNvBlockNeed_ActiveWUCounter_Crc /*  RamBlockCRC data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        0x0400u /*  NV block Base number (defined by FEE/EA)  */ , 
        1u /*  NvMNvBlockLength  */ , 
        0u /*  CsmJobArrayIndex  */ , 
        1u /*  NvMNvBlockNVRAMDataLength  */ , 
        2u /*  NvMNvBlockNum  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee_30_SmallSector /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockCrcType  */ , 
        (
           NVM_CALC_RAM_BLOCK_CRC_OFF
         | NVM_BLOCK_WRITE_PROT_OFF
         | NVM_BLOCK_WRITE_BLOCK_ONCE_OFF
         | NVM_RESISTANT_TO_CHANGED_SW_ON
         | NVM_SELECT_BLOCK_FOR_READALL_ON
         | NVM_SELECT_BLOCK_FOR_WRITEALL_OFF
         | NVM_INVOKE_CALLBACKS_FOR_READALL_ON
         | NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF
         | NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON
        ) /*  Flags  */ , 
        STD_OFF /*  NvMBswMBlockStatusInformation  */ 
      }
    };

/* Permanent RAM and ROM block length checks - compile time (only available for blocks with enabled length check */

/* PRQA S 3494, 3213, 1755 BlockLengthChecks */ /* MD_NvM_Cfg_14.3, MD_NvM_Cfg_2.4 */

/* How does it work:
 * data length = sizeof(ramBlock - CrcLength 
 *     - CRC internal buffer enabled: CRC length == 0, RAM blocks store only data, CRC is handles internally
 *     - CRC internal buffer disabled: CRC length is the number of CRC bytes, for blocks without CRC the length == 0
 *     - for ROM blocks the CRC does not matter
 * Data length has to be > or < or == to configured NvM block length, depending on configuration (see above). 
 * In case the lengths do not match a bitfield with length -1 will be created and shall cause a compiler error.
 * The compiler error shall mark the line with invalid bitfield (bitfield length == -1) - the line includes all required information:
 *     - Block_ + NvM block name
 *     - length error description
 *     - RAM block name, CRC length and configured NvM block length
 */

typedef unsigned int NvM_LengthCheck;
 
/* Block Length Check and Automatic Block Length enabled: error if sizeof RAM block is greater than the configured block length */
#define SizeOfRamBlockGreaterThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) > (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof RAM block does not match the configured block length */
#define SizeOfRamBlockDoesNotMatchConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled and Strict Length Check disabled: error if the sizeof RAM block is less than the configured block length */
#define SizeOfRamBlockLessThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* RAM block length checks */
struct PermanentRamBlockLengthChecks {
  NvM_LengthCheck Block_DemAdminDataBlock : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_AdminData, 0u, 30u);
  NvM_LengthCheck Block_DemStatusDataBlock : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_StatusData, 0u, 404u);
  NvM_LengthCheck Block_DemPrimaryDataBlock0 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_0, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock1 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_1, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock2 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_2, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock3 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_3, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock4 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_4, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock5 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_5, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock6 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_6, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock7 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_7, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock8 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_8, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock9 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_9, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock10 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_10, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock11 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_11, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock12 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_12, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock13 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_13, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock14 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_14, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock15 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_15, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock16 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_16, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock17 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_17, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock19 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_18, 0u, 30u);
  NvM_LengthCheck Block_DemPrimaryDataBlock18 : SizeOfRamBlockGreaterThanConfiguredLength(Dem_Cfg_PrimaryEntry_19, 0u, 30u);
};

/* Block Length Check and Automatic Block Length enabled: error if sizeof ROM block is less than sizeof RAM block */
#define SizeOfRomBlockLessThanSizeOfRamBlock(romBlock, ramBlock) ((sizeof(romBlock) < sizeof(ramBlock)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof ROM block does not match the configured block length */
#define SizeOfRomBlockDoesNotMatchConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled, Strict Length disabled: error if the sizeof ROM block is less than the configured block length */
#define SizeOfRomBlockLessThanConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* ROM block length checks */
struct PermRomBlockLengthCheck {
  NvM_LengthCheck Block_DemPrimaryDataBlock0 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_0);
  NvM_LengthCheck Block_DemPrimaryDataBlock1 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_1);
  NvM_LengthCheck Block_DemPrimaryDataBlock2 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_2);
  NvM_LengthCheck Block_DemPrimaryDataBlock3 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_3);
  NvM_LengthCheck Block_DemPrimaryDataBlock4 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_4);
  NvM_LengthCheck Block_DemPrimaryDataBlock5 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_5);
  NvM_LengthCheck Block_DemPrimaryDataBlock6 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_6);
  NvM_LengthCheck Block_DemPrimaryDataBlock7 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_7);
  NvM_LengthCheck Block_DemPrimaryDataBlock8 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_8);
  NvM_LengthCheck Block_DemPrimaryDataBlock9 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_9);
  NvM_LengthCheck Block_DemPrimaryDataBlock10 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_10);
  NvM_LengthCheck Block_DemPrimaryDataBlock11 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_11);
  NvM_LengthCheck Block_DemPrimaryDataBlock12 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_12);
  NvM_LengthCheck Block_DemPrimaryDataBlock13 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_13);
  NvM_LengthCheck Block_DemPrimaryDataBlock14 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_14);
  NvM_LengthCheck Block_DemPrimaryDataBlock15 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_15);
  NvM_LengthCheck Block_DemPrimaryDataBlock16 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_16);
  NvM_LengthCheck Block_DemPrimaryDataBlock17 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_17);
  NvM_LengthCheck Block_DemPrimaryDataBlock19 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_18);
  NvM_LengthCheck Block_DemPrimaryDataBlock18 : SizeOfRomBlockLessThanSizeOfRamBlock(Dem_Cfg_MemoryEntryInit, Dem_Cfg_PrimaryEntry_19);
};

/* PRQA L:BlockLengthChecks */

/* Permanent RAM and ROM block length checks - END */

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* Job Queue used for normal and high prio jobs */
VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

/* array of RAM Block Management areas, defined to be usable in block descriptor table */
VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_BlockMngmtArea_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS];

/* management area for DCM blocks */
VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_DcmBlockMngmt_t;

#define NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
*  NvM_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 enter SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void)
{
  /* do what ever was defined to do for locking the resources */
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
*  NvM_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 exit SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void)
{
  /* do what ever was defined to do for unlocking the resources */
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiBlockMode(serv, res) BswM_NvM_CurrentJobMode((serv),(res)) /*  if NvMBswMMultiBlockJobStatusInformation is TRUE  */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiCbk(serv, res)   /*  if Multi Block Callback is configured  */

/**********************************************************************************************************************
*  NvM_MultiBlockCbk
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 invoke the BSWM notification if any is configured
 *  - #20 in case the given job result isn't set to pending, invoke the multi block job end notification
 * \endinternal
 */
/* PRQA S 3206 1 */ /* MD_NvM_Cfg_2.7 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockCbk(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  /* The complete function body is designed to be optimized away by the compiler, if it is not needed    *
   * If the used macro is empty, the compiler may decide to remove code because it would contain         *
   * empty execution blocks (it does not matter whether conditions were TRUE or FALSE                    */
  NvM_invokeMultiBlockMode(ServiceId, JobResult);

  if(JobResult != NVM_REQ_PENDING)
  {
    NvM_invokeMultiCbk(ServiceId, JobResult);
  }   
}

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA L:MemMap */

/* Justification for module specific MISRA deviations:

MD_NvM_Cfg_2.4
Reason: NvM provides compile time block length checks via structures with bitfields with positive or negative length -
        the negative length lead to compiler errors. It is possible to use == or even >= check, if only one is used,
        the other one will never be used. The macros are always available. The created structures will never be used by NvM.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_2.7:
Reason: The function NvM_MultiBlockCbk gets all needed parameters to invoke the BSWM and multi block job end callback.
        If both are disabled, the function is empty and does nothing - the passed parameters remain unused.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.9_InternalBuffer:
Reason: NvM uses an internal buffer for explicit synchronization, in internal CRC buffer use case and for repair redundant blocks.
        Depending on configuration all, one or even none of the uses is enabled - therefore sometimes the internal buffer is
        used only once.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.11:
Reason: Array of unknown size is used in order to reduce dependencies.
Risk: In case the array size shall be determined it would be incorrect.
Prevention: No prevention.

MD_NvM_Cfg_14.3:
Reason: NvM provides compile time block length checks via bitfields with positive or negative length - the negative length
        lead to compiler errors. With valid configuration (all block length are configured correctly), all checks are false.
Risk: No risk.
Prevention: No prevention. If needed the compile time checks can be disabled via configuration.

 */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.c
 *********************************************************************************************************************/


