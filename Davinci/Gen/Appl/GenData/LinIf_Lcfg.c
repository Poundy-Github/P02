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
 *            Module: LinIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LinIf_Lcfg.c
 *   Generation Time: 2020-07-09 11:40:52
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#define LINIF_LCFG_SOURCE

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Includes
 *********************************************************************************************************************/

#include "LinIf.h"
#include "PduR_LinIf.h"
#include "LinSM_Cbk.h"
#include "LinIf_LinTrcv.h"


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  LinIf_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelConfig
  \details
  Element                         Description
  ChannelFuncCallCycle            Channel function call cycle
  FrameLengthDelayListEndIdx      the end index of the 0:n relation pointing to LinIf_FrameLengthDelayList
  FrameLengthDelayListStartIdx    the start index of the 0:n relation pointing to LinIf_FrameLengthDelayList
  FrameListEndIdx                 the end index of the 1:n relation pointing to LinIf_FrameList
  FrameListStartIdx               the start index of the 1:n relation pointing to LinIf_FrameList
  LoadBalancingOffset             Load balancing offset in ticks
  NodeChannelConfigIdx            the index of the 1:1 relation pointing to one of LinIf_MasterChannelConfig,LinIf_SlaveChannelConfig
  NodeChannelDataIdx              the index of the 1:1 relation pointing to one of LinIf_MasterChannelData,LinIf_SlaveChannelData
  NodeType                        LIN channel node type
  StartupState                    Startup state of channel: 0 : sleep 1 : operational state
  TimeBase                        Channel time base
  WakeupDelayExternal             External wakeup delay in ticks
  WakeupDelayInternal             Internal wakeup delay in ticks
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_ChannelConfigType, LINIF_CONST) LinIf_ChannelConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelFuncCallCycle  FrameLengthDelayListEndIdx  FrameLengthDelayListStartIdx  FrameListEndIdx  FrameListStartIdx  LoadBalancingOffset  NodeChannelConfigIdx  NodeChannelDataIdx  NodeType                      StartupState  TimeBase  WakeupDelayExternal  WakeupDelayInternal */
  { /*     0 */                   1u,                         8u,                           0u,              6u,                0u,                  1u,                   0u,                 0u, LinIf_ChannelNodeType_Master,           0u,       1u,                100u,                100u }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelIndTable
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelIndTable
  \details
  Element               Description
  LinChannelIndex       LIN Driver channel index
  SystemChannelIndex    ComM (System) channel index
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_ChannelIndTableType, LINIF_CONST) LinIf_ChannelIndTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LinChannelIndex                               SystemChannelIndex                             */
  { /*     0 */ 0 /* LinConf_LinChannel_CN_LIN00_fd825f00 */, 1 /* ComMConf_ComMChannel_CN_LIN00_fd825f00 */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelToDrvWakeupInfo
**********************************************************************************************************************/
/** 
  \var    LinIf_ChannelToDrvWakeupInfo
  \details
  Element            Description
  LinWakeupSource    Defines the ID of the wakeup source. Zero means invalid source and that external wakeup is not supported.
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_ChannelToDrvWakeupInfoType, LINIF_CONST) LinIf_ChannelToDrvWakeupInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LinWakeupSource */
  { /*     0 */           0x40u }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_Entry
**********************************************************************************************************************/
/** 
  \var    LinIf_Entry
  \details
  Element                 Description
  DelayInTimebaseTicks
  FrameListIdx            the index of the 1:1 relation pointing to LinIf_FrameList
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_EntryType, LINIF_CONST) LinIf_Entry[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DelayInTimebaseTicks  FrameListIdx        Comment                                          Referable Keys */
  { /*     0 */                  80u,           4u },  /* [FT_MasterReq_355bc768_Tx]           */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Diagnose_09c374bf] */
  { /*     1 */                  80u,           5u },  /* [FT_SlaveResp_9d5cbedc_Rx]           */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Diagnose_09c374bf] */
  { /*     2 */                   5u,           1u },  /* [FT_Frame_LinTr_HUT_fb8922e7_Tx]     */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Normal_48a571ca] */
  { /*     3 */                   5u,           2u },  /* [FT_Frame_LinTr_RearECU_482c51df_Rx] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Normal_48a571ca] */
  { /*     4 */                  10u,           0u },  /* [FT_Frame_LinTr_HUT2_244040f4_Tx]    */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Normal_48a571ca] */
  { /*     5 */                  10u,           3u }   /* [FT_Frame_LinTr_Slave3_95c9a842_Rx]  */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/Normal_48a571ca] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_FrameLengthDelayList
**********************************************************************************************************************/
/** 
  \var    LinIf_FrameLengthDelayList
  \details
  Element             Description
  FrameLengthDelay
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_FrameLengthDelayListType, LINIF_CONST) LinIf_FrameLengthDelayList[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FrameLengthDelay        Comment                      Referable Keys */
  { /*     0 */               4u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     1 */               5u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     2 */               6u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     3 */               7u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     4 */               7u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     5 */               8u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     6 */               9u },  /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     7 */              10u }   /* [Bitrate: 19200] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_FrameList
**********************************************************************************************************************/
/** 
  \var    LinIf_FrameList
  \details
  Element         Description
  PduId           Upper layer PduId
  FrameType       UNCONDITIONAL : 0 MRF : 1 SRF : 2 EVENT_TRIGGERED : 4 SPORADIC : 5 ASSIGN : 6 UNASSIGN : 7 ASSIGN_NAD : 8 FREE : 9 CONDITIONAL : 10 ASSIGN_FRAME_ID_RANGE : 11 SAVE_CONFIGURATION : 12
  Length          Frame length in bytes
  Pid             Protected Identifier
  ChecksumType    CLASSIC ENHANCED
  Direction       TX RX S2S
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_FrameListType, LINIF_CONST) LinIf_FrameList[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduId                                                     FrameType  Length  Pid    ChecksumType     Direction                   Referable Keys */
  { /*     0 */ PduRConf_PduRDestPdu_Frame_LinTr_HUT2_oLIN00_aac66511_Tx,        0u,     3u, 0xD3u, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_Frame_LinTr_HUT2_244040f4_Tx] */
  { /*     1 */ PduRConf_PduRDestPdu_Frame_LinTr_HUT_oLIN00_a123072b_Tx ,        0u,     1u, 0x11u, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_TX },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_Frame_LinTr_HUT_fb8922e7_Tx] */
  { /*     2 */ PduRConf_PduRSrcPdu_PduRSrcPdu_87852900                 ,        0u,     1u, 0x92u, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_Frame_LinTr_RearECU_482c51df_Rx] */
  { /*     3 */ PduRConf_PduRSrcPdu_PduRSrcPdu_8cf2ea35                 ,        0u,     3u, 0x55u, LIN_ENHANCED_CS, LIN_FRAMERESPONSE_RX },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_Frame_LinTr_Slave3_95c9a842_Rx] */
  { /*     4 */ 0                                                       ,        1u,     8u, 0x3Cu, LIN_CLASSIC_CS , LIN_FRAMERESPONSE_TX },  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_MasterReq_355bc768_Tx] */
  { /*     5 */ 0                                                       ,        2u,     8u, 0x7Du, LIN_CLASSIC_CS , LIN_FRAMERESPONSE_RX }   /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847, /ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847/FT_SlaveResp_9d5cbedc_Rx] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinIfToLinTrcvChannel
**********************************************************************************************************************/
/** 
  \var    LinIf_LinIfToLinTrcvChannel
  \details
  Element        Description
  TrcvChannel
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinIfToLinTrcvChannelType, LINIF_CONST) LinIf_LinIfToLinTrcvChannel[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TrcvChannel                                                                               */
  { /*     0 */ 0 /* LinIfConf_LinIfChannel_CHNL_45618847 -> LinTrcvConf_LinTrcvChannel_LinTrcvChannel */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinIfToLinTrcvNr
**********************************************************************************************************************/
/** 
  \var    LinIf_LinIfToLinTrcvNr
  \details
  Element    Description
  TrcvNr 
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinIfToLinTrcvNrType, LINIF_CONST) LinIf_LinIfToLinTrcvNr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TrcvNr                                                             */
  { /*     0 */ 0 /* LinIfConf_LinIfChannel_CHNL_45618847 -> LinTrcv_30_Tle7259 */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinTrcv_CheckWakeupFct
**********************************************************************************************************************/
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinTrcv_CheckWakeupFctType, LINIF_CONST) LinIf_LinTrcv_CheckWakeupFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinTrcv_CheckWakeupFct          */
  /*     0 */ LinTrcv_30_Tle7259_CheckWakeup 
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinTrcv_GetBusWuReasonFct
**********************************************************************************************************************/
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinTrcv_GetBusWuReasonFctType, LINIF_CONST) LinIf_LinTrcv_GetBusWuReasonFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinTrcv_GetBusWuReasonFct          */
  /*     0 */ LinTrcv_30_Tle7259_GetBusWuReason 
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinTrcv_GetOpModeFct
**********************************************************************************************************************/
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinTrcv_GetOpModeFctType, LINIF_CONST) LinIf_LinTrcv_GetOpModeFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinTrcv_GetOpModeFct          */
  /*     0 */ LinTrcv_30_Tle7259_GetOpMode 
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinTrcv_SetOpModeFct
**********************************************************************************************************************/
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinTrcv_SetOpModeFctType, LINIF_CONST) LinIf_LinTrcv_SetOpModeFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinTrcv_SetOpModeFct          */
  /*     0 */ LinTrcv_30_Tle7259_SetOpMode 
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_LinTrcv_SetWakeupModeFct
**********************************************************************************************************************/
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_LinTrcv_SetWakeupModeFctType, LINIF_CONST) LinIf_LinTrcv_SetWakeupModeFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LinTrcv_SetWakeupModeFct          */
  /*     0 */ LinTrcv_30_Tle7259_SetWakeupMode 
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_MasterChannelConfig
**********************************************************************************************************************/
/** 
  \var    LinIf_MasterChannelConfig
  \details
  Element                         Description
  ScheduleChangeBeforeSlotEnd     Point of schedule table change. True = after maximum frame time, False = at end of schedule slot.
  NumberOfSchedules               Number of schedule tables
  ScheduleTableListIndEndIdx      the end index of the 0:n relation pointing to LinIf_ScheduleTableListInd
  ScheduleTableListIndStartIdx    the start index of the 0:n relation pointing to LinIf_ScheduleTableListInd
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_MasterChannelConfigType, LINIF_CONST) LinIf_MasterChannelConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ScheduleChangeBeforeSlotEnd  NumberOfSchedules  ScheduleTableListIndEndIdx  ScheduleTableListIndStartIdx        Referable Keys */
  { /*     0 */                       FALSE,                2u,                         3u,                           0u }   /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ScheduleTableList
**********************************************************************************************************************/
/** 
  \var    LinIf_ScheduleTableList
  \details
  Element                    Description
  EntryEndIdx                the end index of the 0:n relation pointing to LinIf_Entry
  EntryStartIdx              the start index of the 0:n relation pointing to LinIf_Entry
  NumberOfScheduleEntries    number of entries
  ResumePosition             CONTINUE_AT_IT_POINT : 0 START_FROM_BEGINNING : 1
  RunMode                    RUN_CONTINUOUS : 0 RUN_ONCE : 1
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_ScheduleTableListType, LINIF_CONST) LinIf_ScheduleTableList[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EntryEndIdx                              EntryStartIdx                              NumberOfScheduleEntries  ResumePosition  RunMode        Comment                         Referable Keys */
  { /*     0 */ LINIF_NO_ENTRYENDIDXOFSCHEDULETABLELIST, LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST,                   0x00u,          0x00u,   0x00u },  /* [NULLSchedule]      */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     1 */                                      2u,                                        0u,                   0x02u,          0x01u,   0x00u },  /* [Diagnose_09c374bf] */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  { /*     2 */                                      6u,                                        2u,                   0x04u,          0x01u,   0x00u }   /* [Normal_48a571ca]   */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ScheduleTableListInd
**********************************************************************************************************************/
/** 
  \var    LinIf_ScheduleTableListInd
  \brief  the indexes of the 1:1 sorted relation pointing to LinIf_ScheduleTableList
*/ 
#define LINIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_ScheduleTableListIndType, LINIF_CONST) LinIf_ScheduleTableListInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ScheduleTableListInd      Referable Keys */
  /*     0 */                    0u,  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  /*     1 */                    1u,  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
  /*     2 */                    2u   /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */
};
#define LINIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_SystemToLinIfChannel
**********************************************************************************************************************/
/** 
  \var    LinIf_SystemToLinIfChannel
  \details
  Element              Description
  LinIfChannelIndex
*/ 
#define LINIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinIf_SystemToLinIfChannelType, LINIF_CONST) LinIf_SystemToLinIfChannel[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LinIfChannelIndex                                                                       */
  { /*     0 */                                                       255U /* 0xFF -> No Lin channel */ },
  { /*     1 */ 0U /* ComMConf_ComMChannel_CN_LIN00_fd825f00 -> LinIfConf_LinIfChannel_CHNL_45618847 */ }
};
#define LINIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_ChannelData
**********************************************************************************************************************/
#define LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(LinIf_ChannelDataUType, LINIF_VAR_NOINIT) LinIf_ChannelData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */  /* Data structure per LinIf channel */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */

#define LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinIf_MasterChannelData
**********************************************************************************************************************/
#define LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(LinIf_MasterChannelDataUType, LINIF_VAR_NOINIT) LinIf_MasterChannelData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */  /* Data structure per LinIf Master channel */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/LinIf/LinIfGlobalConfig/CHNL_45618847] */

#define LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/






