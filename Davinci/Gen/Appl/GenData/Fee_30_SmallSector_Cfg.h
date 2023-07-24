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
 *            Module: Fee
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fee_30_SmallSector_Cfg.h
 *   Generation Time: 2022-01-25 14:49:35
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

/**** Protection against multiple inclusion **************************************************************************/
#ifndef FEE_30_SMALLSECTOR_CFG_H_PUBLIC
# define FEE_30_SMALLSECTOR_CFG_H_PUBLIC
 
/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
 
#ifndef FEE_USE_DUMMY_STATEMENT
#define FEE_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT
#define FEE_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_DUMMY_STATEMENT_CONST
#define FEE_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FEE_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FEE_ATOMIC_VARIABLE_ACCESS
#define FEE_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FEE_PROCESSOR_RH850_1651
#define FEE_PROCESSOR_RH850_1651
#endif
#ifndef FEE_COMP_GREENHILLS
#define FEE_COMP_GREENHILLS
#endif
#ifndef FEE_GEN_GENERATOR_MSR
#define FEE_GEN_GENERATOR_MSR
#endif
#ifndef FEE_CPUTYPE_BITORDER_LSB2MSB
#define FEE_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FEE_CONFIGURATION_VARIANT_PRECOMPILE
#define FEE_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FEE_CONFIGURATION_VARIANT_LINKTIME
#define FEE_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FEE_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FEE_CONFIGURATION_VARIANT
#define FEE_CONFIGURATION_VARIANT FEE_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef FEE_POSTBUILD_VARIANT_SUPPORT
#define FEE_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
#define FEE_30_SMALLSECTOR_CFG_MAJOR_VERSION    (2u) 
#define FEE_30_SMALLSECTOR_CFG_MINOR_VERSION    (0u) 

/**** Pre-compile switches for FEE development error checks ***********************************************************/

#define FEE_30_SMALLSECTOR_DEV_ERROR_DETECT	(STD_ON)
#define FEE_30_SMALLSECTOR_DEV_ERROR_REPORT	(STD_ON)
#include "Det.h"

/***** Optional API functions **************************************************************************************/

#define FEE_30_SMALLSECTOR_VERSION_INFO_API STD_OFF

/**** Symbolic block names **************************************************************************/
  
#define FeeConf_FeeBlockConfiguration_FeeDemAdminDataBlock                                           16u 
#define FeeConf_FeeBlockConfiguration_FeeDemStatusDataBlock                                          32u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock0                                        48u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock1                                        64u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock2                                        80u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock3                                        96u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock4                                        112u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock5                                        128u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock6                                        144u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock7                                        160u 
#define FeeConf_FeeBlockConfiguration_FeeStartApplication_NvMBlock1                                  176u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_Block_ODO_1                                     192u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_Block_ODO_2                                     208u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_Block_ODO_3                                     224u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_Block_ODO_4                                     240u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_Block_ODO_5                                     256u 
#define FeeConf_FeeBlockConfiguration_FeeODO_NvBlockNeed_Block_MaintainOdo                           272u 
#define FeeConf_FeeBlockConfiguration_FeeODO_NvBlockNeed_Block_Trip                                  288u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_FactoryMode                       304u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_VIN                               320u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_VehicleMode                       336u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData  352u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xF18C                                      368u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xF193                                      384u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xF195                                      400u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFD00                                      416u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFD19                                      432u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE20                                      448u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE21                                      464u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE22                                      480u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE23                                      496u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE24                                      512u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xFE25                                      528u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock10                                       544u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock11                                       560u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock12                                       576u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock13                                       592u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock14                                       608u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock15                                       624u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock16                                       640u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock17                                       656u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock18                                       672u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock19                                       688u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock8                                        704u 
#define FeeConf_FeeBlockConfiguration_FeeDemPrimaryDataBlock9                                        720u 
#define FeeConf_FeeBlockConfiguration_FeeEOL_NvBlockNeed_0xF187                                      736u 
#define FeeConf_FeeBlockConfiguration_FeeCommon_GateWayNvBlockNeed_Block_IPC_Config_Data             752u 
#define FeeConf_FeeBlockConfiguration_FeeCommon_GateWayNvBlockNeed_Block_IPC_CAN_Data                768u 
#define FeeConf_FeeBlockConfiguration_FeeMiscNvBlockNeed_ResetInfomation                             784u 
#define FeeConf_FeeBlockConfiguration_FeeDCM_ServerNvBlockNeedSecAttemptCount                        800u 
#define FeeConf_FeeBlockConfiguration_FeeDCM_ServerNvBlockNeed_EOLUnlockCnt                          816u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_ClusterInternalConfiguration      832u 
#define FeeConf_FeeBlockConfiguration_FeeAMP_NvBlockNeed_LC_Calibration                              848u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_E2ESwitch                         864u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_SecOcSwitch                       880u 
#define FeeConf_FeeBlockConfiguration_FeeNvBlockNeed_UpgradeResetFlag                                896u 
#define FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_Fvm_TripCount                            912u 
#define FeeConf_FeeBlockConfiguration_FeeCommon_NormalNvBlockNeed_Menu                               928u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_VehicleSoftwareVersion            944u 
#define FeeConf_FeeBlockConfiguration_FeeAMP_NvBlockNeed_LC_Calibration2                             960u 
#define FeeConf_FeeBlockConfiguration_FeeSOCManagerNvBlockNeed_HealthSwitch                          976u 
#define FeeConf_FeeBlockConfiguration_FeeDidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset 992u 
#define FeeConf_FeeBlockConfiguration_FeeCan_ServerNvBlockNeed_AbnormalWakeupSleepRecords            1008u 
#define FeeConf_FeeBlockConfiguration_FeeCan_ServerNvBlockNeed_ActiveWUCounter                       1024u 


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef uint32 Fee_30_SmallSector_AddressType;

/**********************************************************************************************************************
 *  MODULE RELEVANT CONFIGURATION
 *********************************************************************************************************************/
 
#ifdef FEE_30_SMALLSECTOR_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Fls.h" 

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define FEE_30_SMALLSECTOR_LAYER_ONE_INDEX             (0x00U)
#define FEE_30_SMALLSECTOR_LAYER_TWO_INDEX             (0x01U)
#define FEE_30_SMALLSECTOR_LAYER_THREE_INDEX           (0x02U)

/****  FLS Configuration *********************************************************************************************/

#define FEE_30_SMALLSECTOR_NUMBER_OF_FLS_DEVICES       (1u)

/****  FEE Configuration *********************************************************************************************/

#define FEE_30_SMALLSECTOR_FLS_POLLING_MODE            (STD_ON)
#define FEE_30_SMALLSECTOR_CORRECT_SINGLE_BIT_FLIPS    (STD_OFF)
#define FEE_30_SMALLSECTOR_MANAGEMENT_SIZE             (1u)
#define FEE_30_SMALLSECTOR_MAX_BLOCKS_PER_PARTITION    (28u)
#define FEE_30_SMALLSECTOR_NUMBER_OF_PARTITIONS        (4u)
#define FEE_30_SMALLSECTOR_NUMBER_OF_BLOCKS            (64u)
#define FEE_30_SMALLSECTOR_MAX_WRITE_ALIGNMENT         (4u)
#define FEE_30_SMALLSECTOR_MAX_READ_SIZE               (9u)

#define FEE_30_SMALLSECTOR_STATIC_PATTERN              (0xAAu)

/****  NVM Configuration *********************************************************************************************/

#define FEE_30_SMALLSECTOR_NVM_POLLING_MODE            (STD_ON)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Function pointer prototypes for FLS API services */
typedef P2VAR(uint8, AUTOMATIC, FEE_30_SMALLSECTOR_APPL_DATA) Fee_30_SmallSector_DataPtr;
typedef P2CONST(uint8, AUTOMATIC, FEE_30_SMALLSECTOR_APPL_DATA) Fee_30_SmallSector_ConstDataPtr;

typedef P2FUNC(Std_ReturnType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_ReadPtrType)(Fls_AddressType FlsAddress, Fee_30_SmallSector_DataPtr TargetAddressPtr, Fls_LengthType Length);
typedef P2FUNC(Std_ReturnType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_WritePtrType)(Fls_AddressType FlsAddress, Fee_30_SmallSector_ConstDataPtr SourceAddressPtr, Fls_LengthType Length);
typedef P2FUNC(Std_ReturnType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_ComparePtrType)(Fls_AddressType FlsAddress, Fee_30_SmallSector_ConstDataPtr DataBufferPtr, Fls_LengthType Length);
typedef P2FUNC(Std_ReturnType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_ErasePtrType)(Fls_AddressType FlsAddress, Fls_LengthType Length);
typedef P2FUNC(Std_ReturnType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_BlankCheckPtrType)(Fls_AddressType FlsAddress, Fls_LengthType Length);
typedef P2FUNC(MemIf_StatusType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_GetStatusPtrType)(void);
typedef P2FUNC(MemIf_JobResultType, FEE_30_SMALLSECTOR_PRIVATE_CODE, Fee_30_SmallSector_GetJobResultPtrType)(void);

typedef struct
{
	Fee_30_SmallSector_ReadPtrType Read;
	Fee_30_SmallSector_WritePtrType Write;
	Fee_30_SmallSector_ComparePtrType Compare;
	Fee_30_SmallSector_ErasePtrType Erase;
	Fee_30_SmallSector_BlankCheckPtrType BlankCheck;
	Fee_30_SmallSector_GetStatusPtrType GetStatus;
	Fee_30_SmallSector_GetJobResultPtrType GetJobResult;
} Fee_30_SmallSector_FlsApiType;

typedef P2CONST(Fee_30_SmallSector_FlsApiType, AUTOMATIC, FEE_30_SMALLSECTOR_APPL_DATA) Fee_30_SmallSector_FlsApiPtrType;
  
typedef struct
{
    Fee_30_SmallSector_AddressType PartitionStartAddress;
    uint16 PartitionAddressAlignment;
    uint16 PartitionWriteAlignment;
    uint16 PartitionReadAlignment;
    uint16 FlsDeviceIndex;
    Fee_30_SmallSector_FlsApiPtrType FlsApiPtr;
    uint8 FlsEraseValue;
    boolean BlankCheckApiEnabled;
    uint16 BlockNumberList[FEE_30_SMALLSECTOR_MAX_BLOCKS_PER_PARTITION];
} Fee_30_SmallSector_PartitionConfigType;

typedef struct
{
    Fee_30_SmallSector_AddressType BlockStartAddress;
    uint16 DataLength;
    uint8 NumberOfInstances;
    uint8 NumberOfDatasets;
    boolean IsImmediateData;
    boolean HasVerificationEnabled;
} Fee_30_SmallSector_BlockConfigType;


/* Function pointer prototypes NvM callback routines */

typedef P2FUNC(void, FEE_30_SMALLSECTOR_NVM_CODE, Fee_30_SmallSector_CbkJobEndNotificationType)(void);
typedef P2FUNC(void, FEE_30_SMALLSECTOR_NVM_CODE, Fee_30_SmallSector_CbkJobErrorNotificationType)(void);

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

extern CONST(uint8, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_DatasetSelectionBits;

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */


#define FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */  /* MD_MSR_MemMap */
  
extern CONST(Fee_30_SmallSector_PartitionConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_PartitionConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_PARTITIONS];
extern CONST(Fee_30_SmallSector_BlockConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_BlockConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_BLOCKS];
extern CONST(Fee_30_SmallSector_FlsApiType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_FlsApi0; 


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* Function pointers to the callback routines of the NvM. */
extern CONST(Fee_30_SmallSector_CbkJobEndNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobEndNotification;
extern CONST(Fee_30_SmallSector_CbkJobErrorNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobErrorNotification;

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */  /* MD_MSR_MemMap */


#endif /* FEE_30_SMALLSECTOR_IMPLEMENTATION_SOURCE */

#endif /* FEE_30_SMALLSECTOR_CFG_H_PUBLIC */

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_SmallSector_Cfg.h
 *********************************************************************************************************************/

