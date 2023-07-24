#define FEE_30_SMALLSECTOR_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fee_30_SmallSector.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (FEE_30_SMALLSECTOR_CFG_MAJOR_VERSION != (2u)) \
     || (FEE_30_SMALLSECTOR_CFG_MINOR_VERSION != (0u)))
# error "Version numbers of Fee_30_SmallSector_Cfg.c and Fee_30_SmallSector_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#define FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
#include "MemMap.h"    /* PRQA S 5087 */  /* MD_MSR_MemMap */

CONST(uint8, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_DatasetSelectionBits = (4u);

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
#include "MemMap.h"   /* PRQA S 5087 */  /* MD_MSR_MemMap */

#define FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/* PRQA S 686 PARTITIONLIST */ /* MD_FEE_30_SMALLSECTOR_ArraySize */
CONST(Fee_30_SmallSector_PartitionConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_PartitionConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_PARTITIONS] = 
{
   /*  FEEPARTITIONCONFIGURATION  */ {
     /*  Partition Start Address  */ 0x00000000uL, 
     /*  Partition Address Alignment  */ 0x0040u, 
     /*  Partition Write Alignment  */ 0x0004u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  FLS Device Index  */ 0x0000u, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFu, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
       /*  FeeStartApplication_NvMBlock1  */ 0x00B0u, 
       /*  FeeNvBlockNeed_Block_ODO_1  */ 0x00C0u, 
       /*  FeeNvBlockNeed_Block_ODO_2  */ 0x00D0u, 
       /*  FeeNvBlockNeed_Block_ODO_3  */ 0x00E0u, 
       /*  FeeNvBlockNeed_Block_ODO_4  */ 0x00F0u, 
       /*  FeeNvBlockNeed_Block_ODO_5  */ 0x0100u, 
       /*  FeeODO_NvBlockNeed_Block_MaintainOdo  */ 0x0110u, 
       /*  FeeODO_NvBlockNeed_Block_Trip  */ 0x0120u, 
       /*  FeeCommon_GateWayNvBlockNeed_Block_IPC_Config_Data  */ 0x02F0u, 
       /*  FeeCommon_GateWayNvBlockNeed_Block_IPC_CAN_Data  */ 0x0300u, 
       /*  FeeMiscNvBlockNeed_ResetInfomation  */ 0x0310u, 
       /*  FeeBlockConfiguration_Fvm_TripCount  */ 0x0390u, 
       /*  FeeCommon_NormalNvBlockNeed_Menu  */ 0x03A0u
    }
  }, 
   /*  FEEPARTITIONCONFIGURATION_BOOT  */ {
     /*  Partition Start Address  */ 0x00007F80uL, 
     /*  Partition Address Alignment  */ 0x0040u, 
     /*  Partition Write Alignment  */ 0x0004u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  FLS Device Index  */ 0x0000u, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFu, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
       /*  FeeNvBlockNeed_UpgradeResetFlag  */ 0x0380u
    }
  }, 
   /*  FEEPARTITIONCONFIGURATION_DIAG  */ {
     /*  Partition Start Address  */ 0x00004000uL, 
     /*  Partition Address Alignment  */ 0x0040u, 
     /*  Partition Write Alignment  */ 0x0004u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  FLS Device Index  */ 0x0000u, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFu, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
       /*  FeeDidDataProcessNvBlockNeed_VIN  */ 0x0140u, 
       /*  FeeDidDataProcessNvBlockNeed_FactoryMode  */ 0x0130u, 
       /*  FeeDidDataProcessNvBlockNeed_VehicleMode  */ 0x0150u, 
       /*  FeeDidDataProcessNvBlockNeed_ECUlevelNetworkConfigurationData  */ 0x0160u, 
       /*  FeeEOL_NvBlockNeed_0xF18C  */ 0x0170u, 
       /*  FeeEOL_NvBlockNeed_0xF193  */ 0x0180u, 
       /*  FeeEOL_NvBlockNeed_0xF195  */ 0x0190u, 
       /*  FeeEOL_NvBlockNeed_0xFD00  */ 0x01A0u, 
       /*  FeeEOL_NvBlockNeed_0xFD19  */ 0x01B0u, 
       /*  FeeEOL_NvBlockNeed_0xFE20  */ 0x01C0u, 
       /*  FeeEOL_NvBlockNeed_0xFE21  */ 0x01D0u, 
       /*  FeeEOL_NvBlockNeed_0xF187  */ 0x02E0u, 
       /*  FeeEOL_NvBlockNeed_0xFE22  */ 0x01E0u, 
       /*  FeeEOL_NvBlockNeed_0xFE23  */ 0x01F0u, 
       /*  FeeDidDataProcessNvBlockNeed_SecOcSwitch  */ 0x0370u, 
       /*  FeeDCM_ServerNvBlockNeedSecAttemptCount  */ 0x0320u, 
       /*  FeeDidDataProcessNvBlockNeed_E2ESwitch  */ 0x0360u, 
       /*  FeeEOL_NvBlockNeed_0xFE24  */ 0x0200u, 
       /*  FeeDCM_ServerNvBlockNeed_EOLUnlockCnt  */ 0x0330u, 
       /*  FeeEOL_NvBlockNeed_0xFE25  */ 0x0210u, 
       /*  FeeDidDataProcessNvBlockNeed_ClusterInternalConfiguration  */ 0x0340u, 
       /*  FeeAMP_NvBlockNeed_LC_Calibration  */ 0x0350u, 
       /*  FeeDidDataProcessNvBlockNeed_VehicleSoftwareVersion  */ 0x03B0u, 
       /*  FeeAMP_NvBlockNeed_LC_Calibration2  */ 0x03C0u, 
       /*  FeeSOCManagerNvBlockNeed_HealthSwitch  */ 0x03D0u, 
       /*  FeeDidDataProcessNvBlockNeed_ClusterDisplayHMIAdjustmentOffset  */ 0x03E0u, 
       /*  FeeCan_ServerNvBlockNeed_AbnormalWakeupSleepRecords  */ 0x03F0u, 
       /*  FeeCan_ServerNvBlockNeed_ActiveWUCounter  */ 0x0400u
    }
  }, 
   /*  FEEPARTITIONCONFIGURATION_DEM  */ {
     /*  Partition Start Address  */ 0x00002000uL, 
     /*  Partition Address Alignment  */ 0x0040u, 
     /*  Partition Write Alignment  */ 0x0004u, 
     /*  Partition Read Alignment  */ 0x0001u, 
     /*  FLS Device Index  */ 0x0000u, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFu, 
     /*  FLS Blank Check API Enabled  */ TRUE, 
    {
       /*  FeeDemAdminDataBlock  */ 0x0010u, 
       /*  FeeDemStatusDataBlock  */ 0x0020u, 
       /*  FeeDemPrimaryDataBlock8  */ 0x02C0u, 
       /*  FeeDemPrimaryDataBlock0  */ 0x0030u, 
       /*  FeeDemPrimaryDataBlock1  */ 0x0040u, 
       /*  FeeDemPrimaryDataBlock9  */ 0x02D0u, 
       /*  FeeDemPrimaryDataBlock2  */ 0x0050u, 
       /*  FeeDemPrimaryDataBlock3  */ 0x0060u, 
       /*  FeeDemPrimaryDataBlock10  */ 0x0220u, 
       /*  FeeDemPrimaryDataBlock4  */ 0x0070u, 
       /*  FeeDemPrimaryDataBlock5  */ 0x0080u, 
       /*  FeeDemPrimaryDataBlock11  */ 0x0230u, 
       /*  FeeDemPrimaryDataBlock6  */ 0x0090u, 
       /*  FeeDemPrimaryDataBlock7  */ 0x00A0u, 
       /*  FeeDemPrimaryDataBlock12  */ 0x0240u, 
       /*  FeeDemPrimaryDataBlock13  */ 0x0250u, 
       /*  FeeDemPrimaryDataBlock14  */ 0x0260u, 
       /*  FeeDemPrimaryDataBlock15  */ 0x0270u, 
       /*  FeeDemPrimaryDataBlock16  */ 0x0280u, 
       /*  FeeDemPrimaryDataBlock19  */ 0x02B0u, 
       /*  FeeDemPrimaryDataBlock18  */ 0x02A0u, 
       /*  FeeDemPrimaryDataBlock17  */ 0x0290u
    }
  }
};
/* PRQA L: PARTITIONLIST */

/* BlockConfigList is sorted by BlockNumbers in ascending order */
CONST(Fee_30_SmallSector_BlockConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_BlockConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_BLOCKS] =
{
  {
     /*  Block Start Address  */ 0x00000000uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000080uL, 
     /*  Data Length  */ 0x0196u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000480uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000500uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000600uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000680uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000780uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000800uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000900uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000980uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000000uL, 
     /*  Data Length  */ 0x0004u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000080uL, 
     /*  Data Length  */ 0x0012u, 
     /*  Number Of Instances  */ 0x03u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000180uL, 
     /*  Data Length  */ 0x0012u, 
     /*  Number Of Instances  */ 0x03u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000280uL, 
     /*  Data Length  */ 0x0012u, 
     /*  Number Of Instances  */ 0x03u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000380uL, 
     /*  Data Length  */ 0x0012u, 
     /*  Number Of Instances  */ 0x03u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000480uL, 
     /*  Data Length  */ 0x0012u, 
     /*  Number Of Instances  */ 0x03u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000580uL, 
     /*  Data Length  */ 0x0052u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000680uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000080uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000000uL, 
     /*  Data Length  */ 0x0013u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000100uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000180uL, 
     /*  Data Length  */ 0x00CAu, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000380uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000400uL, 
     /*  Data Length  */ 0x0011u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000480uL, 
     /*  Data Length  */ 0x0013u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000500uL, 
     /*  Data Length  */ 0x0006u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000580uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000600uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000680uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000780uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000800uL, 
     /*  Data Length  */ 0x0004u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A00uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B00uL, 
     /*  Data Length  */ 0x0004u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000700uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000880uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A00uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A80uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B00uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B80uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000C00uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000D80uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000D00uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000C80uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000400uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000580uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000700uL, 
     /*  Data Length  */ 0x000Fu, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000700uL, 
     /*  Data Length  */ 0x003Eu, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000800uL, 
     /*  Data Length  */ 0x007Au, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000980uL, 
     /*  Data Length  */ 0x0041u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000900uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A80uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B80uL, 
     /*  Data Length  */ 0x012Eu, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000E00uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000980uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000880uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000000uL, 
     /*  Data Length  */ 0x0006u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000A80uL, 
     /*  Data Length  */ 0x0006u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000B00uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000E80uL, 
     /*  Data Length  */ 0x0020u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000F00uL, 
     /*  Data Length  */ 0x0016u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000F80uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001000uL, 
     /*  Data Length  */ 0x000Au, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001080uL, 
     /*  Data Length  */ 0x0052u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00001180uL, 
     /*  Data Length  */ 0x0003u, 
     /*  Number Of Instances  */ 0x01u, 
     /*  Number Of Datasets  */ 0x02u, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }
};
/* FLS API pointer table */
CONST(Fee_30_SmallSector_FlsApiType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_FlsApi0 = 
{
   /*  Read Service  */ Fls_Read, 
   /*  Write Service  */ Fls_Write, 
   /*  Compare Service  */ Fls_Compare, 
   /*  Erase Service  */ Fls_Erase, 
   /*  Blank Check Service  */ Fls_BlankCheck, 
   /*  Get Status Service  */ Fls_GetStatus, 
   /*  Get Job Result Service  */ Fls_GetJobResult
};
 

/**** NvM Callback Assignments ****/
CONST(Fee_30_SmallSector_CbkJobEndNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobEndNotification = /* PRQA S 1533 */  /* MD_FEE_30_SMALLSECTOR_ExternalDefinition */
    NULL_PTR;
CONST(Fee_30_SmallSector_CbkJobErrorNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobErrorNotification = /* PRQA S 1533 */  /* MD_FEE_30_SMALLSECTOR_ExternalDefinition */
    NULL_PTR;

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */  /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:
 MD_FEE_30_SMALLSECTOR_ArraySize: rule 9.3
      Reason:     Array size of Fee_30_SmallSector_PartitionConfigType.BlockNumberList depends on maximum number of blocks in one partition.             
      Risk:       No risk. Partitions with fewer blocks and thus BlockNumberLists with fewer initializers are implicitly 
                  initialized to zero.
      Prevention: Program flow has been verified by component tests and review.
      
 MD_FEE_30_SMALLSECTOR_ExternalDefinition: rule 8.9
      Reason:     The function pointer is only used inside one translation unit of the static files. The assignment of 
                  this function pointer needs to be done seperately inside the generated file as the related Nvm callback function is configurable.
      Risk:       No risk. 
      Prevention: Program flow has been verified by component tests and review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_SmallSector_Cfg.c
 *********************************************************************************************************************/

