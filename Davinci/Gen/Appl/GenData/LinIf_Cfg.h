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
 *              File: LinIf_Cfg.h
 *   Generation Time: 2020-07-09 11:40:52
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined(LINIF_CFG_H)
#define LINIF_CFG_H

/* If_Asr4IfLin CFG5 Generatorversion 8.01.00 */

/**********************************************************************************************************************
 *  Justifications
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Includes
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Com.h"



/**********************************************************************************************************************
 *  Node type defines
 *********************************************************************************************************************/
#define LINIF_NODETYPE_MASTER_SUPPORTED                               STD_ON
#define LINIF_NODETYPE_SLAVE_SUPPORTED                                STD_OFF
#define LINIF_NODETYPE_MASTER_ONLY                                    STD_ON
#define LINIF_NODETYPE_SLAVE_ONLY                                     STD_OFF

/**********************************************************************************************************************
 *  Configuration defines
 *********************************************************************************************************************/
#define LINIF_VERSION_INFO_API                                        STD_OFF
#define LINIF_TP_SUPPORTED                                            STD_OFF
#define LINIF_TRCV_HANDLING                                           STD_ON
#define LINIF_CANCEL_TRANSMIT_SUPPORTED                               STD_OFF
#define LINIF_LIN_CHANNEL_WAKEUP_SUPPORT                              STD_ON
#define LINIF_LINTRCV_WAKEUP_SUPPORT                                  STD_OFF
#define LINIF_MULTIPLE_DRIVER_SUPPORT                                 STD_OFF
#define LINIF_SPORADIC_FRM_SUPPORTED                                  STD_OFF
#define LINIF_EVT_FRM_SUPPORTED                                       STD_OFF
#define LINIF_RUNTIME_MEASUREMENT_SUPPORT                             STD_OFF
#define LINIF_SCHEDULE_END_NOTIFICATION                               STD_OFF
#define LINIF_J2602_FRAME_TOLERANCE_SUPPORT                           STD_OFF
#define LINIF_SCHEDULE_INFO_API                                       STD_OFF
#define LINIF_BUSMIRRORING                                            STD_OFF
#define LINIF_RESPERRSIG_CHANGED_CALLOUT                              STD_OFF

#define LinIf_NumberOfChannels                                        0x01u 
#define LinIf_NumberOfSlaveChannels                                   0x00u 
#define LinIf_NumberOfMasterChannels                                  0x01u 


/**********************************************************************************************************************
 *  General Defines
 *********************************************************************************************************************/
#ifndef LINIF_USE_DUMMY_STATEMENT
#define LINIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINIF_DUMMY_STATEMENT
#define LINIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINIF_DUMMY_STATEMENT_CONST
#define LINIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define LINIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef LINIF_ATOMIC_VARIABLE_ACCESS
#define LINIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef LINIF_PROCESSOR_RH850_1651
#define LINIF_PROCESSOR_RH850_1651
#endif
#ifndef LINIF_COMP_GREENHILLS
#define LINIF_COMP_GREENHILLS
#endif
#ifndef LINIF_GEN_GENERATOR_MSR
#define LINIF_GEN_GENERATOR_MSR
#endif
#ifndef LINIF_CPUTYPE_BITORDER_LSB2MSB
#define LINIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef LINIF_CONFIGURATION_VARIANT_PRECOMPILE
#define LINIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LINIF_CONFIGURATION_VARIANT_LINKTIME
#define LINIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LINIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LINIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef LINIF_CONFIGURATION_VARIANT
#define LINIF_CONFIGURATION_VARIANT LINIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef LINIF_POSTBUILD_VARIANT_SUPPORT
#define LINIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define LINIF_DEV_ERROR_DETECT                                        STD_ON
#define LINIF_DEV_ERROR_REPORT                                        STD_ON

/**********************************************************************************************************************
 *  Global timebase
 *********************************************************************************************************************/
#define LinIf_GlobalTimeBaseMS                                        1u

/**********************************************************************************************************************
 *  Slave node configuration services
 *********************************************************************************************************************/
#define LINIF_NC_GENERAL_SUPPORTED                                    STD_OFF
#define LINIF_NC_ASSIGN_NAD_SUPPORTED                                 STD_OFF
#define LINIF_NC_ASSIGN_FRAME_ID_RANGE_SUPPORTED                      STD_OFF
#define LINIF_NC_SAVE_CONFIGURATION_SUPPORTED                         STD_OFF
#define LINIF_NC_READ_BY_IDENTIFIER_0_SUPPORTED                       STD_OFF
#define LINIF_NC_READ_BY_IDENTIFIER_2_SUPPORTED                       STD_OFF
#define LINIF_NC_READ_BY_IDENTIFIER_3_SUPPORTED                       STD_OFF
#define LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED                      STD_OFF
#define LINIF_NC_PRODUCT_ID_CONFIGURABLE_SUPPORTED                    STD_OFF

#define LINIF_NC_ASSIGN_FRAME_ID_RANGE_ON_ALL_CHANNELS_SUPPORTED      STD_OFF
#define LINIF_NC_SAVE_CONFIGURATION_ON_ALL_CHANNELS_SUPPORTED         STD_OFF
#define LINIF_NC_LIN20_ASSIGN_FRAME_ID_ON_ALL_CHANNELS_SUPPORTED      STD_OFF

/**********************************************************************************************************************
 *  Precompile optimizations
 *********************************************************************************************************************/
#define LINIF_PDUR_ONLY_UL_OPTIMIZATION                               STD_ON
#define LINIF_LINSM_ONLY_UL_OPTIMIZATION                              STD_ON
/* FBL usecase */
#define LINIF_DIAGNOSTIC_FRAMES_ONLY                                  STD_OFF
/* LIN master driver dummy functions */
#define LINIF_LINDRIVER_MASTER_DUMMY_FUNCTIONS                        STD_OFF

/* Single LIN driver instance */
#define LinIf_Lin_SendFrame_FctCall(a,b)                              Lin_SendFrame((a), (b)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_GoToSleep_FctCall(a)                                Lin_GoToSleep((a)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_GoToSleepInternal_FctCall(a)                        Lin_GoToSleepInternal((a)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_Wakeup_FctCall(a)                                   Lin_Wakeup((a)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_WakeupInternal_FctCall(a)                           Lin_WakeupInternal((a)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_CheckWakeup_FctCall(a)                              Lin_CheckWakeup((a)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define LinIf_Lin_GetStatus_FctCall(a,b)                              Lin_GetStatus((a), (b)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Master / Slave only configuration optimizations */
#if ( LINIF_NODETYPE_SLAVE_ONLY == STD_ON ) || ( LINIF_NODETYPE_MASTER_ONLY == STD_ON )
# define LinIf_GetNodeChannelConfigIdxOfLinIfChannel(c)               (c) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define LinIf_GetNodeChannelDataIdxOfLinIfChannel(c)                 (c) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
# define LinIf_GetNodeChannelConfigIdxOfLinIfChannel(c)               LinIf_GetNodeChannelConfigIdxOfChannelConfig((c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define LinIf_GetNodeChannelDataIdxOfLinIfChannel(c)                 LinIf_GetNodeChannelDataIdxOfChannelConfig((c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif


/**********************************************************************************************************************
 *  Symbolic Name Values For LinIf Channels
 *********************************************************************************************************************/



/**
 * \defgroup LinIfHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define LinIfConf_LinIfChannel_CHNL_45618847                          0u
/**\} */

/**********************************************************************************************************************
 *  Symbolic Name Values For Tx Frames
 *********************************************************************************************************************/



/**
 * \defgroup LinIfHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define LinIfConf_LinIfTxPdu_LinIfTxPdu_1ae3d2ad                      1u
#define LinIfConf_LinIfTxPdu_LinIfTxPdu_99a12905                      0u
/**\} */

/**********************************************************************************************************************
 *  Symbolic Name Values For Schedule Tables
 *********************************************************************************************************************/



/**
 * \defgroup LinIfHandleIdsCHNL_45618847 Handle IDs of handle space CHNL_45618847.
 * \brief 
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define LinIfConf_LinIfScheduleTable_Diagnose_09c374bf                1u
#define LinIfConf_LinIfScheduleTable_NULLSchedule                     0u
#define LinIfConf_LinIfScheduleTable_Normal_48a571ca                  2u
/**\} */

/**********************************************************************************************************************
 *  Enumeration defines
 *********************************************************************************************************************/
/* Channel node types */
#define LinIf_ChannelNodeType_Master                                  0x00u 
#define LinIf_ChannelNodeType_Slave                                   0x01u 


/* LIN protocol version defines */
#define LinIf_LinProtocolVersion_13                                   0x13u 
#define LinIf_LinProtocolVersion_20                                   0x20u 
#define LinIf_LinProtocolVersion_21                                   0x21u 
#define LinIf_LinProtocolVersion_22                                   0x22u 
#define LinIf_LinProtocolVersion_ISO17987_2015                        0x30u 




/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinIfPCDataSwitches  LinIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINIF_CHANNELCONFIG                                                                         STD_ON
#define LINIF_CHANNELFUNCCALLCYCLEOFCHANNELCONFIG                                                   STD_ON
#define LINIF_FRAMELENGTHDELAYLISTENDIDXOFCHANNELCONFIG                                             STD_ON
#define LINIF_FRAMELENGTHDELAYLISTSTARTIDXOFCHANNELCONFIG                                           STD_ON
#define LINIF_FRAMELENGTHDELAYLISTUSEDOFCHANNELCONFIG                                               STD_ON
#define LINIF_FRAMELISTENDIDXOFCHANNELCONFIG                                                        STD_ON
#define LINIF_FRAMELISTSTARTIDXOFCHANNELCONFIG                                                      STD_ON
#define LINIF_LOADBALANCINGOFFSETOFCHANNELCONFIG                                                    STD_ON
#define LINIF_NODECHANNELCONFIGIDXOFCHANNELCONFIG                                                   STD_ON
#define LINIF_NODECHANNELDATAIDXOFCHANNELCONFIG                                                     STD_ON
#define LINIF_NODETYPEOFCHANNELCONFIG                                                               STD_ON
#define LINIF_STARTUPSTATEOFCHANNELCONFIG                                                           STD_ON
#define LINIF_TIMEBASEOFCHANNELCONFIG                                                               STD_ON
#define LINIF_WAKEUPDELAYEXTERNALOFCHANNELCONFIG                                                    STD_ON
#define LINIF_WAKEUPDELAYINTERNALOFCHANNELCONFIG                                                    STD_ON
#define LINIF_CHANNELDATA                                                                           STD_ON
#define LINIF_CHANNELINDTABLE                                                                       STD_ON
#define LINIF_LINCHANNELINDEXOFCHANNELINDTABLE                                                      STD_ON
#define LINIF_SYSTEMCHANNELINDEXOFCHANNELINDTABLE                                                   STD_ON
#define LINIF_CHANNELTODRVWAKEUPINFO                                                                STD_ON
#define LINIF_LINWAKEUPSOURCEOFCHANNELTODRVWAKEUPINFO                                               STD_ON
#define LINIF_CONFIGUREDPIDTABLE                                                                    STD_OFF  /**< Deactivateable: 'LinIf_ConfiguredPIDTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_ENTRY                                                                                 STD_ON
#define LINIF_DELAYINTIMEBASETICKSOFENTRY                                                           STD_ON
#define LINIF_FRAMELISTIDXOFENTRY                                                                   STD_ON
#define LINIF_EVTFRAMEINFO                                                                          STD_OFF  /**< Deactivateable: 'LinIf_EvtFrameInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_COLLRESOLVSCHEDHANDLEOFEVTFRAMEINFO                                                   STD_OFF  /**< Deactivateable: 'LinIf_EvtFrameInfo.CollResolvSchedHandle' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_EVTUNCONDITIONALFRAMEINFOENDIDXOFEVTFRAMEINFO                                         STD_OFF  /**< Deactivateable: 'LinIf_EvtFrameInfo.EvtUnconditionalFrameInfoEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_EVTUNCONDITIONALFRAMEINFOSTARTIDXOFEVTFRAMEINFO                                       STD_OFF  /**< Deactivateable: 'LinIf_EvtFrameInfo.EvtUnconditionalFrameInfoStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_EVTUNCONDITIONALFRAMEINFO                                                             STD_OFF  /**< Deactivateable: 'LinIf_EvtUnconditionalFrameInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_FRAMELISTIDXOFEVTUNCONDITIONALFRAMEINFO                                               STD_OFF  /**< Deactivateable: 'LinIf_EvtUnconditionalFrameInfo.FrameListIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_PIDOFEVTUNCONDITIONALFRAMEINFO                                                        STD_OFF  /**< Deactivateable: 'LinIf_EvtUnconditionalFrameInfo.Pid' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'LinIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LINIF_FIXEDFRAMESDULIST                                                                     STD_OFF  /**< Deactivateable: 'LinIf_FixedFrameSduList' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_SDUBYTEOFFIXEDFRAMESDULIST                                                            STD_OFF  /**< Deactivateable: 'LinIf_FixedFrameSduList.SduByte' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_FRAMELENGTHDELAYLIST                                                                  STD_ON
#define LINIF_FRAMELENGTHDELAYOFFRAMELENGTHDELAYLIST                                                STD_ON
#define LINIF_FRAMELIST                                                                             STD_ON
#define LINIF_CHECKSUMTYPEOFFRAMELIST                                                               STD_ON
#define LINIF_DIRECTIONOFFRAMELIST                                                                  STD_ON
#define LINIF_FIXEDFRAMESDULISTIDXOFFRAMELIST                                                       STD_OFF  /**< Deactivateable: 'LinIf_FrameList.FixedFrameSduListIdx' Reason: 'the optional indirection is deactivated because FixedFrameSduListUsedOfFrameList is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define LINIF_FIXEDFRAMESDULISTUSEDOFFRAMELIST                                                      STD_OFF  /**< Deactivateable: 'LinIf_FrameList.FixedFrameSduListUsed' Reason: 'the optional indirection is deactivated because FixedFrameSduListUsedOfFrameList is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define LINIF_FRAMETYPEOFFRAMELIST                                                                  STD_ON
#define LINIF_LENGTHOFFRAMELIST                                                                     STD_ON
#define LINIF_PDUIDOFFRAMELIST                                                                      STD_ON
#define LINIF_PIDOFFRAMELIST                                                                        STD_ON
#define LINIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'LinIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LINIF_LINIFTOLINTRCVCHANNEL                                                                 STD_ON
#define LINIF_TRCVCHANNELOFLINIFTOLINTRCVCHANNEL                                                    STD_ON
#define LINIF_LINIFTOLINTRCVNR                                                                      STD_ON
#define LINIF_TRCVNROFLINIFTOLINTRCVNR                                                              STD_ON
#define LINIF_LINTRCV_CHECKWAKEUPFCT                                                                STD_ON
#define LINIF_LINTRCV_GETBUSWUREASONFCT                                                             STD_ON
#define LINIF_LINTRCV_GETOPMODEFCT                                                                  STD_ON
#define LINIF_LINTRCV_SETOPMODEFCT                                                                  STD_ON
#define LINIF_LINTRCV_SETWAKEUPMODEFCT                                                              STD_ON
#define LINIF_MASTERCHANNELCONFIG                                                                   STD_ON
#define LINIF_NUMBEROFSCHEDULESOFMASTERCHANNELCONFIG                                                STD_ON
#define LINIF_SCHEDULECHANGEBEFORESLOTENDOFMASTERCHANNELCONFIG                                      STD_ON
#define LINIF_SCHEDULETABLELISTINDENDIDXOFMASTERCHANNELCONFIG                                       STD_ON
#define LINIF_SCHEDULETABLELISTINDSTARTIDXOFMASTERCHANNELCONFIG                                     STD_ON
#define LINIF_SCHEDULETABLELISTINDUSEDOFMASTERCHANNELCONFIG                                         STD_ON
#define LINIF_MASTERCHANNELDATA                                                                     STD_ON
#define LINIF_SCHEDULETABLELIST                                                                     STD_ON
#define LINIF_ENTRYENDIDXOFSCHEDULETABLELIST                                                        STD_ON
#define LINIF_ENTRYSTARTIDXOFSCHEDULETABLELIST                                                      STD_ON
#define LINIF_ENTRYUSEDOFSCHEDULETABLELIST                                                          STD_ON
#define LINIF_INVALIDHNDOFSCHEDULETABLELIST                                                         STD_OFF  /**< Deactivateable: 'LinIf_ScheduleTableList.InvalidHnd' Reason: 'the value of LinIf_InvalidHndOfScheduleTableList is always 'false' due to this, the array is deactivated.' */
#define LINIF_NUMBEROFSCHEDULEENTRIESOFSCHEDULETABLELIST                                            STD_ON
#define LINIF_RESUMEPOSITIONOFSCHEDULETABLELIST                                                     STD_ON
#define LINIF_RUNMODEOFSCHEDULETABLELIST                                                            STD_ON
#define LINIF_SCHEDULETABLELISTIND                                                                  STD_ON
#define LINIF_SIZEOFCHANNELCONFIG                                                                   STD_ON
#define LINIF_SIZEOFCHANNELDATA                                                                     STD_ON
#define LINIF_SIZEOFMASTERCHANNELDATA                                                               STD_ON
#define LINIF_SIZEOFSYSTEMTOLINIFCHANNEL                                                            STD_ON
#define LINIF_SLAVECHANNELCONFIG                                                                    STD_ON
#define LINIF_BUSIDLETIMEOUTOFSLAVECHANNELCONFIG                                                    STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.BusIdleTimeout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_CONFIGUREDNADOFSLAVECHANNELCONFIG                                                     STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is RUNTIME_CHECKING and feature deactivation conditions are not available. */
#define LINIF_CONFIGUREDPIDTABLEENDIDXOFSLAVECHANNELCONFIG                                          STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.ConfiguredPIDTableEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_CONFIGUREDPIDTABLELENGTHOFSLAVECHANNELCONFIG                                          STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.ConfiguredPIDTableLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_CONFIGUREDPIDTABLESTARTIDXOFSLAVECHANNELCONFIG                                        STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.ConfiguredPIDTableStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_FRAMELISTRESPERRTXFRAMEIDXOFSLAVECHANNELCONFIG                                        STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.FrameListRespErrTxFrameIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_FRAMELISTRESPERRTXFRAMEUSEDOFSLAVECHANNELCONFIG                                       STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.FrameListRespErrTxFrameUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_PROTOCOLVERSIONOFSLAVECHANNELCONFIG                                                   STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.ProtocolVersion' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_RESPERRSIGNALEXISTSOFSLAVECHANNELCONFIG                                               STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.RespErrSignalExists' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_RESPERRSIGNALHANDLEOFSLAVECHANNELCONFIG                                               STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelConfig.RespErrSignalHandle' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SLAVECHANNELDATA                                                                      STD_OFF  /**< Deactivateable: 'LinIf_SlaveChannelData' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORUNCFRAMEBYHANDLELIST                                                              STD_OFF  /**< Deactivateable: 'LinIf_SporUncFrameByHandleList' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_SPORUNCONDITIONALFRAMEIDXOFSPORUNCFRAMEBYHANDLELIST                                   STD_OFF  /**< Deactivateable: 'LinIf_SporUncFrameByHandleList.SporUnconditionalFrameIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORUNCFRAMEBYPRIORITYLIST                                                            STD_OFF  /**< Deactivateable: 'LinIf_SporUncFrameByPriorityList' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_SPORUNCONDITIONALFRAMEIDXOFSPORUNCFRAMEBYPRIORITYLIST                                 STD_OFF  /**< Deactivateable: 'LinIf_SporUncFrameByPriorityList.SporUnconditionalFrameIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORUNCONDITIONALFRAME                                                                STD_OFF  /**< Deactivateable: 'LinIf_SporUnconditionalFrame' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_BITMSKOFSPORUNCONDITIONALFRAME                                                        STD_OFF  /**< Deactivateable: 'LinIf_SporUnconditionalFrame.BitMsk' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_BYTEMSKOFSPORUNCONDITIONALFRAME                                                       STD_OFF  /**< Deactivateable: 'LinIf_SporUnconditionalFrame.ByteMsk' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_FRAMELISTIDXOFSPORUNCONDITIONALFRAME                                                  STD_OFF  /**< Deactivateable: 'LinIf_SporUnconditionalFrame.FrameListIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORADICFRAMEINFO                                                                     STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_SPORUNCFRAMEBYPRIORITYLISTENDIDXOFSPORADICFRAMEINFO                                   STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameInfo.SporUncFrameByPriorityListEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORUNCFRAMEBYPRIORITYLISTSTARTIDXOFSPORADICFRAMEINFO                                 STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameInfo.SporUncFrameByPriorityListStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_UNCFRAMECOUNTOFSPORADICFRAMEINFO                                                      STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameInfo.UncFrameCount' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SPORADICFRAMELOOKUPTABLE                                                              STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameLookupTable' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define LINIF_BITMSKOFSPORADICFRAMELOOKUPTABLE                                                      STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameLookupTable.BitMsk' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_BYTEMSKOFSPORADICFRAMELOOKUPTABLE                                                     STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameLookupTable.ByteMsk' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_TXPDUIDOFSPORADICFRAMELOOKUPTABLE                                                     STD_OFF  /**< Deactivateable: 'LinIf_SporadicFrameLookupTable.TxPduId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define LINIF_SYSTEMTOLINIFCHANNEL                                                                  STD_ON
#define LINIF_LINIFCHANNELINDEXOFSYSTEMTOLINIFCHANNEL                                               STD_ON
#define LINIF_UNCTXFRMTOTALNUMBER                                                                   STD_ON
#define LINIF_PCCONFIG                                                                              STD_ON
#define LINIF_CHANNELCONFIGOFPCCONFIG                                                               STD_ON
#define LINIF_CHANNELDATAOFPCCONFIG                                                                 STD_ON
#define LINIF_CHANNELINDTABLEOFPCCONFIG                                                             STD_ON
#define LINIF_CHANNELTODRVWAKEUPINFOOFPCCONFIG                                                      STD_ON
#define LINIF_ENTRYOFPCCONFIG                                                                       STD_ON
#define LINIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'LinIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define LINIF_FRAMELENGTHDELAYLISTOFPCCONFIG                                                        STD_ON
#define LINIF_FRAMELISTOFPCCONFIG                                                                   STD_ON
#define LINIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'LinIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define LINIF_LINIFTOLINTRCVCHANNELOFPCCONFIG                                                       STD_ON
#define LINIF_LINIFTOLINTRCVNROFPCCONFIG                                                            STD_ON
#define LINIF_LINTRCV_CHECKWAKEUPFCTOFPCCONFIG                                                      STD_ON
#define LINIF_LINTRCV_GETBUSWUREASONFCTOFPCCONFIG                                                   STD_ON
#define LINIF_LINTRCV_GETOPMODEFCTOFPCCONFIG                                                        STD_ON
#define LINIF_LINTRCV_SETOPMODEFCTOFPCCONFIG                                                        STD_ON
#define LINIF_LINTRCV_SETWAKEUPMODEFCTOFPCCONFIG                                                    STD_ON
#define LINIF_MASTERCHANNELCONFIGOFPCCONFIG                                                         STD_ON
#define LINIF_MASTERCHANNELDATAOFPCCONFIG                                                           STD_ON
#define LINIF_SCHEDULETABLELISTINDOFPCCONFIG                                                        STD_ON
#define LINIF_SCHEDULETABLELISTOFPCCONFIG                                                           STD_ON
#define LINIF_SIZEOFCHANNELCONFIGOFPCCONFIG                                                         STD_ON
#define LINIF_SIZEOFCHANNELDATAOFPCCONFIG                                                           STD_ON
#define LINIF_SIZEOFMASTERCHANNELDATAOFPCCONFIG                                                     STD_ON
#define LINIF_SIZEOFSYSTEMTOLINIFCHANNELOFPCCONFIG                                                  STD_ON
#define LINIF_SLAVECHANNELCONFIGOFPCCONFIG                                                          STD_ON
#define LINIF_SYSTEMTOLINIFCHANNELOFPCCONFIG                                                        STD_ON
#define LINIF_UNCTXFRMTOTALNUMBEROFPCCONFIG                                                         STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCNoReferenceDefines  LinIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define LINIF_NO_FRAMELENGTHDELAYLISTENDIDXOFCHANNELCONFIG                                          255u
#define LINIF_NO_FRAMELENGTHDELAYLISTSTARTIDXOFCHANNELCONFIG                                        255u
#define LINIF_NO_SCHEDULETABLELISTINDENDIDXOFMASTERCHANNELCONFIG                                    255u
#define LINIF_NO_SCHEDULETABLELISTINDSTARTIDXOFMASTERCHANNELCONFIG                                  255u
#define LINIF_NO_ENTRYENDIDXOFSCHEDULETABLELIST                                                     255u
#define LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST                                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCIsReducedToDefineDefines  LinIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define LINIF_ISDEF_CHANNELFUNCCALLCYCLEOFCHANNELCONFIG                                             STD_OFF
#define LINIF_ISDEF_FRAMELENGTHDELAYLISTENDIDXOFCHANNELCONFIG                                       STD_OFF
#define LINIF_ISDEF_FRAMELENGTHDELAYLISTSTARTIDXOFCHANNELCONFIG                                     STD_OFF
#define LINIF_ISDEF_FRAMELENGTHDELAYLISTUSEDOFCHANNELCONFIG                                         STD_OFF
#define LINIF_ISDEF_FRAMELISTENDIDXOFCHANNELCONFIG                                                  STD_OFF
#define LINIF_ISDEF_FRAMELISTSTARTIDXOFCHANNELCONFIG                                                STD_OFF
#define LINIF_ISDEF_LOADBALANCINGOFFSETOFCHANNELCONFIG                                              STD_OFF
#define LINIF_ISDEF_NODECHANNELCONFIGIDXOFCHANNELCONFIG                                             STD_OFF
#define LINIF_ISDEF_NODECHANNELDATAIDXOFCHANNELCONFIG                                               STD_OFF
#define LINIF_ISDEF_NODETYPEOFCHANNELCONFIG                                                         STD_OFF
#define LINIF_ISDEF_STARTUPSTATEOFCHANNELCONFIG                                                     STD_OFF
#define LINIF_ISDEF_TIMEBASEOFCHANNELCONFIG                                                         STD_OFF
#define LINIF_ISDEF_WAKEUPDELAYEXTERNALOFCHANNELCONFIG                                              STD_OFF
#define LINIF_ISDEF_WAKEUPDELAYINTERNALOFCHANNELCONFIG                                              STD_OFF
#define LINIF_ISDEF_LINCHANNELINDEXOFCHANNELINDTABLE                                                STD_OFF
#define LINIF_ISDEF_SYSTEMCHANNELINDEXOFCHANNELINDTABLE                                             STD_OFF
#define LINIF_ISDEF_LINWAKEUPSOURCEOFCHANNELTODRVWAKEUPINFO                                         STD_OFF
#define LINIF_ISDEF_DELAYINTIMEBASETICKSOFENTRY                                                     STD_OFF
#define LINIF_ISDEF_FRAMELISTIDXOFENTRY                                                             STD_OFF
#define LINIF_ISDEF_FRAMELENGTHDELAYOFFRAMELENGTHDELAYLIST                                          STD_OFF
#define LINIF_ISDEF_CHECKSUMTYPEOFFRAMELIST                                                         STD_OFF
#define LINIF_ISDEF_DIRECTIONOFFRAMELIST                                                            STD_OFF
#define LINIF_ISDEF_FRAMETYPEOFFRAMELIST                                                            STD_OFF
#define LINIF_ISDEF_LENGTHOFFRAMELIST                                                               STD_OFF
#define LINIF_ISDEF_PDUIDOFFRAMELIST                                                                STD_OFF
#define LINIF_ISDEF_PIDOFFRAMELIST                                                                  STD_OFF
#define LINIF_ISDEF_TRCVCHANNELOFLINIFTOLINTRCVCHANNEL                                              STD_OFF
#define LINIF_ISDEF_TRCVNROFLINIFTOLINTRCVNR                                                        STD_OFF
#define LINIF_ISDEF_LINTRCV_CHECKWAKEUPFCT                                                          STD_OFF
#define LINIF_ISDEF_LINTRCV_GETBUSWUREASONFCT                                                       STD_OFF
#define LINIF_ISDEF_LINTRCV_GETOPMODEFCT                                                            STD_OFF
#define LINIF_ISDEF_LINTRCV_SETOPMODEFCT                                                            STD_OFF
#define LINIF_ISDEF_LINTRCV_SETWAKEUPMODEFCT                                                        STD_OFF
#define LINIF_ISDEF_NUMBEROFSCHEDULESOFMASTERCHANNELCONFIG                                          STD_OFF
#define LINIF_ISDEF_SCHEDULECHANGEBEFORESLOTENDOFMASTERCHANNELCONFIG                                STD_OFF
#define LINIF_ISDEF_SCHEDULETABLELISTINDENDIDXOFMASTERCHANNELCONFIG                                 STD_OFF
#define LINIF_ISDEF_SCHEDULETABLELISTINDSTARTIDXOFMASTERCHANNELCONFIG                               STD_OFF
#define LINIF_ISDEF_SCHEDULETABLELISTINDUSEDOFMASTERCHANNELCONFIG                                   STD_OFF
#define LINIF_ISDEF_ENTRYENDIDXOFSCHEDULETABLELIST                                                  STD_OFF
#define LINIF_ISDEF_ENTRYSTARTIDXOFSCHEDULETABLELIST                                                STD_OFF
#define LINIF_ISDEF_ENTRYUSEDOFSCHEDULETABLELIST                                                    STD_OFF
#define LINIF_ISDEF_NUMBEROFSCHEDULEENTRIESOFSCHEDULETABLELIST                                      STD_OFF
#define LINIF_ISDEF_RESUMEPOSITIONOFSCHEDULETABLELIST                                               STD_OFF
#define LINIF_ISDEF_RUNMODEOFSCHEDULETABLELIST                                                      STD_OFF
#define LINIF_ISDEF_SCHEDULETABLELISTIND                                                            STD_OFF
#define LINIF_ISDEF_CONFIGUREDNADOFSLAVECHANNELCONFIG                                               STD_OFF
#define LINIF_ISDEF_LINIFCHANNELINDEXOFSYSTEMTOLINIFCHANNEL                                         STD_OFF
#define LINIF_ISDEF_CHANNELCONFIGOFPCCONFIG                                                         STD_ON
#define LINIF_ISDEF_CHANNELDATAOFPCCONFIG                                                           STD_ON
#define LINIF_ISDEF_CHANNELINDTABLEOFPCCONFIG                                                       STD_ON
#define LINIF_ISDEF_CHANNELTODRVWAKEUPINFOOFPCCONFIG                                                STD_ON
#define LINIF_ISDEF_ENTRYOFPCCONFIG                                                                 STD_ON
#define LINIF_ISDEF_FRAMELENGTHDELAYLISTOFPCCONFIG                                                  STD_ON
#define LINIF_ISDEF_FRAMELISTOFPCCONFIG                                                             STD_ON
#define LINIF_ISDEF_LINIFTOLINTRCVCHANNELOFPCCONFIG                                                 STD_ON
#define LINIF_ISDEF_LINIFTOLINTRCVNROFPCCONFIG                                                      STD_ON
#define LINIF_ISDEF_LINTRCV_CHECKWAKEUPFCTOFPCCONFIG                                                STD_ON
#define LINIF_ISDEF_LINTRCV_GETBUSWUREASONFCTOFPCCONFIG                                             STD_ON
#define LINIF_ISDEF_LINTRCV_GETOPMODEFCTOFPCCONFIG                                                  STD_ON
#define LINIF_ISDEF_LINTRCV_SETOPMODEFCTOFPCCONFIG                                                  STD_ON
#define LINIF_ISDEF_LINTRCV_SETWAKEUPMODEFCTOFPCCONFIG                                              STD_ON
#define LINIF_ISDEF_MASTERCHANNELCONFIGOFPCCONFIG                                                   STD_ON
#define LINIF_ISDEF_MASTERCHANNELDATAOFPCCONFIG                                                     STD_ON
#define LINIF_ISDEF_SCHEDULETABLELISTINDOFPCCONFIG                                                  STD_ON
#define LINIF_ISDEF_SCHEDULETABLELISTOFPCCONFIG                                                     STD_ON
#define LINIF_ISDEF_SLAVECHANNELCONFIGOFPCCONFIG                                                    STD_ON
#define LINIF_ISDEF_SYSTEMTOLINIFCHANNELOFPCCONFIG                                                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCEqualsAlwaysToDefines  LinIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define LINIF_EQ2_CHANNELFUNCCALLCYCLEOFCHANNELCONFIG                                               
#define LINIF_EQ2_FRAMELENGTHDELAYLISTENDIDXOFCHANNELCONFIG                                         
#define LINIF_EQ2_FRAMELENGTHDELAYLISTSTARTIDXOFCHANNELCONFIG                                       
#define LINIF_EQ2_FRAMELENGTHDELAYLISTUSEDOFCHANNELCONFIG                                           
#define LINIF_EQ2_FRAMELISTENDIDXOFCHANNELCONFIG                                                    
#define LINIF_EQ2_FRAMELISTSTARTIDXOFCHANNELCONFIG                                                  
#define LINIF_EQ2_LOADBALANCINGOFFSETOFCHANNELCONFIG                                                
#define LINIF_EQ2_NODECHANNELCONFIGIDXOFCHANNELCONFIG                                               
#define LINIF_EQ2_NODECHANNELDATAIDXOFCHANNELCONFIG                                                 
#define LINIF_EQ2_NODETYPEOFCHANNELCONFIG                                                           
#define LINIF_EQ2_STARTUPSTATEOFCHANNELCONFIG                                                       
#define LINIF_EQ2_TIMEBASEOFCHANNELCONFIG                                                           
#define LINIF_EQ2_WAKEUPDELAYEXTERNALOFCHANNELCONFIG                                                
#define LINIF_EQ2_WAKEUPDELAYINTERNALOFCHANNELCONFIG                                                
#define LINIF_EQ2_LINCHANNELINDEXOFCHANNELINDTABLE                                                  
#define LINIF_EQ2_SYSTEMCHANNELINDEXOFCHANNELINDTABLE                                               
#define LINIF_EQ2_LINWAKEUPSOURCEOFCHANNELTODRVWAKEUPINFO                                           
#define LINIF_EQ2_DELAYINTIMEBASETICKSOFENTRY                                                       
#define LINIF_EQ2_FRAMELISTIDXOFENTRY                                                               
#define LINIF_EQ2_FRAMELENGTHDELAYOFFRAMELENGTHDELAYLIST                                            
#define LINIF_EQ2_CHECKSUMTYPEOFFRAMELIST                                                           
#define LINIF_EQ2_DIRECTIONOFFRAMELIST                                                              
#define LINIF_EQ2_FRAMETYPEOFFRAMELIST                                                              
#define LINIF_EQ2_LENGTHOFFRAMELIST                                                                 
#define LINIF_EQ2_PDUIDOFFRAMELIST                                                                  
#define LINIF_EQ2_PIDOFFRAMELIST                                                                    
#define LINIF_EQ2_TRCVCHANNELOFLINIFTOLINTRCVCHANNEL                                                
#define LINIF_EQ2_TRCVNROFLINIFTOLINTRCVNR                                                          
#define LINIF_EQ2_LINTRCV_CHECKWAKEUPFCT                                                            
#define LINIF_EQ2_LINTRCV_GETBUSWUREASONFCT                                                         
#define LINIF_EQ2_LINTRCV_GETOPMODEFCT                                                              
#define LINIF_EQ2_LINTRCV_SETOPMODEFCT                                                              
#define LINIF_EQ2_LINTRCV_SETWAKEUPMODEFCT                                                          
#define LINIF_EQ2_NUMBEROFSCHEDULESOFMASTERCHANNELCONFIG                                            
#define LINIF_EQ2_SCHEDULECHANGEBEFORESLOTENDOFMASTERCHANNELCONFIG                                  
#define LINIF_EQ2_SCHEDULETABLELISTINDENDIDXOFMASTERCHANNELCONFIG                                   
#define LINIF_EQ2_SCHEDULETABLELISTINDSTARTIDXOFMASTERCHANNELCONFIG                                 
#define LINIF_EQ2_SCHEDULETABLELISTINDUSEDOFMASTERCHANNELCONFIG                                     
#define LINIF_EQ2_ENTRYENDIDXOFSCHEDULETABLELIST                                                    
#define LINIF_EQ2_ENTRYSTARTIDXOFSCHEDULETABLELIST                                                  
#define LINIF_EQ2_ENTRYUSEDOFSCHEDULETABLELIST                                                      
#define LINIF_EQ2_NUMBEROFSCHEDULEENTRIESOFSCHEDULETABLELIST                                        
#define LINIF_EQ2_RESUMEPOSITIONOFSCHEDULETABLELIST                                                 
#define LINIF_EQ2_RUNMODEOFSCHEDULETABLELIST                                                        
#define LINIF_EQ2_SCHEDULETABLELISTIND                                                              
#define LINIF_EQ2_CONFIGUREDNADOFSLAVECHANNELCONFIG                                                 
#define LINIF_EQ2_LINIFCHANNELINDEXOFSYSTEMTOLINIFCHANNEL                                           
#define LINIF_EQ2_CHANNELCONFIGOFPCCONFIG                                                           LinIf_ChannelConfig
#define LINIF_EQ2_CHANNELDATAOFPCCONFIG                                                             LinIf_ChannelData.raw
#define LINIF_EQ2_CHANNELINDTABLEOFPCCONFIG                                                         LinIf_ChannelIndTable
#define LINIF_EQ2_CHANNELTODRVWAKEUPINFOOFPCCONFIG                                                  LinIf_ChannelToDrvWakeupInfo
#define LINIF_EQ2_ENTRYOFPCCONFIG                                                                   LinIf_Entry
#define LINIF_EQ2_FRAMELENGTHDELAYLISTOFPCCONFIG                                                    LinIf_FrameLengthDelayList
#define LINIF_EQ2_FRAMELISTOFPCCONFIG                                                               LinIf_FrameList
#define LINIF_EQ2_LINIFTOLINTRCVCHANNELOFPCCONFIG                                                   LinIf_LinIfToLinTrcvChannel
#define LINIF_EQ2_LINIFTOLINTRCVNROFPCCONFIG                                                        LinIf_LinIfToLinTrcvNr
#define LINIF_EQ2_LINTRCV_CHECKWAKEUPFCTOFPCCONFIG                                                  LinIf_LinTrcv_CheckWakeupFct
#define LINIF_EQ2_LINTRCV_GETBUSWUREASONFCTOFPCCONFIG                                               LinIf_LinTrcv_GetBusWuReasonFct
#define LINIF_EQ2_LINTRCV_GETOPMODEFCTOFPCCONFIG                                                    LinIf_LinTrcv_GetOpModeFct
#define LINIF_EQ2_LINTRCV_SETOPMODEFCTOFPCCONFIG                                                    LinIf_LinTrcv_SetOpModeFct
#define LINIF_EQ2_LINTRCV_SETWAKEUPMODEFCTOFPCCONFIG                                                LinIf_LinTrcv_SetWakeupModeFct
#define LINIF_EQ2_MASTERCHANNELCONFIGOFPCCONFIG                                                     LinIf_MasterChannelConfig
#define LINIF_EQ2_MASTERCHANNELDATAOFPCCONFIG                                                       LinIf_MasterChannelData.raw
#define LINIF_EQ2_SCHEDULETABLELISTINDOFPCCONFIG                                                    LinIf_ScheduleTableListInd
#define LINIF_EQ2_SCHEDULETABLELISTOFPCCONFIG                                                       LinIf_ScheduleTableList
#define LINIF_EQ2_SLAVECHANNELCONFIGOFPCCONFIG                                                      NULL_PTR
#define LINIF_EQ2_SYSTEMTOLINIFCHANNELOFPCCONFIG                                                    LinIf_SystemToLinIfChannel
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCSymbolicInitializationPointers  LinIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define LinIf_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'LinIf' */
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCInitializationSymbols  LinIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define LinIf_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'LinIf */
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCGeneral  LinIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define LINIF_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define LINIF_FINAL_MAGIC_NUMBER                                                                    0x3E1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of LinIf */
#define LINIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'LinIf' is not configured to be postbuild capable. */
#define LINIF_INIT_DATA                                                                             LINIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define LINIF_INIT_DATA_HASH_CODE                                                                   -84159238  /**< the precompile constant to validate the initialization structure at initialization time of LinIf with a hashcode. The seed value is '0x3E1Eu' */
#define LINIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define LINIF_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer LinIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinIfLTDataSwitches  LinIf Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINIF_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'LinIf_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LinIfPBDataSwitches  LinIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LINIF_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'LinIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LINIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'LinIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define LINIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'LinIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  Includes
 *********************************************************************************************************************/
#include "LinIf_Types.h"

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
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
  \defgroup  LinIfPCGetConstantDuplicatedRootDataMacros  LinIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define LinIf_GetChannelConfigOfPCConfig()                                                          LinIf_ChannelConfig  /**< the pointer to LinIf_ChannelConfig */
#define LinIf_GetChannelDataOfPCConfig()                                                            LinIf_ChannelData.raw  /**< the pointer to LinIf_ChannelData */
#define LinIf_GetChannelIndTableOfPCConfig()                                                        LinIf_ChannelIndTable  /**< the pointer to LinIf_ChannelIndTable */
#define LinIf_GetChannelToDrvWakeupInfoOfPCConfig()                                                 LinIf_ChannelToDrvWakeupInfo  /**< the pointer to LinIf_ChannelToDrvWakeupInfo */
#define LinIf_GetEntryOfPCConfig()                                                                  LinIf_Entry  /**< the pointer to LinIf_Entry */
#define LinIf_GetFrameLengthDelayListOfPCConfig()                                                   LinIf_FrameLengthDelayList  /**< the pointer to LinIf_FrameLengthDelayList */
#define LinIf_GetFrameListOfPCConfig()                                                              LinIf_FrameList  /**< the pointer to LinIf_FrameList */
#define LinIf_GetLinIfToLinTrcvChannelOfPCConfig()                                                  LinIf_LinIfToLinTrcvChannel  /**< the pointer to LinIf_LinIfToLinTrcvChannel */
#define LinIf_GetLinIfToLinTrcvNrOfPCConfig()                                                       LinIf_LinIfToLinTrcvNr  /**< the pointer to LinIf_LinIfToLinTrcvNr */
#define LinIf_GetLinTrcv_CheckWakeupFctOfPCConfig()                                                 LinIf_LinTrcv_CheckWakeupFct  /**< the pointer to LinIf_LinTrcv_CheckWakeupFct */
#define LinIf_GetLinTrcv_GetBusWuReasonFctOfPCConfig()                                              LinIf_LinTrcv_GetBusWuReasonFct  /**< the pointer to LinIf_LinTrcv_GetBusWuReasonFct */
#define LinIf_GetLinTrcv_GetOpModeFctOfPCConfig()                                                   LinIf_LinTrcv_GetOpModeFct  /**< the pointer to LinIf_LinTrcv_GetOpModeFct */
#define LinIf_GetLinTrcv_SetOpModeFctOfPCConfig()                                                   LinIf_LinTrcv_SetOpModeFct  /**< the pointer to LinIf_LinTrcv_SetOpModeFct */
#define LinIf_GetLinTrcv_SetWakeupModeFctOfPCConfig()                                               LinIf_LinTrcv_SetWakeupModeFct  /**< the pointer to LinIf_LinTrcv_SetWakeupModeFct */
#define LinIf_GetMasterChannelConfigOfPCConfig()                                                    LinIf_MasterChannelConfig  /**< the pointer to LinIf_MasterChannelConfig */
#define LinIf_GetMasterChannelDataOfPCConfig()                                                      LinIf_MasterChannelData.raw  /**< the pointer to LinIf_MasterChannelData */
#define LinIf_GetScheduleTableListIndOfPCConfig()                                                   LinIf_ScheduleTableListInd  /**< the pointer to LinIf_ScheduleTableListInd */
#define LinIf_GetScheduleTableListOfPCConfig()                                                      LinIf_ScheduleTableList  /**< the pointer to LinIf_ScheduleTableList */
#define LinIf_GetSizeOfChannelConfigOfPCConfig()                                                    1u  /**< the number of accomplishable value elements in LinIf_ChannelConfig */
#define LinIf_GetSizeOfChannelDataOfPCConfig()                                                      1u  /**< the number of accomplishable value elements in LinIf_ChannelData */
#define LinIf_GetSizeOfMasterChannelDataOfPCConfig()                                                1u  /**< the number of accomplishable value elements in LinIf_MasterChannelData */
#define LinIf_GetSizeOfSystemToLinIfChannelOfPCConfig()                                             2u  /**< the number of accomplishable value elements in LinIf_SystemToLinIfChannel */
#define LinIf_GetSlaveChannelConfigOfPCConfig()                                                     NULL_PTR  /**< the pointer to LinIf_SlaveChannelConfig */
#define LinIf_GetSystemToLinIfChannelOfPCConfig()                                                   LinIf_SystemToLinIfChannel  /**< the pointer to LinIf_SystemToLinIfChannel */
#define LinIf_GetUncTxFrmTotalNumberOfPCConfig()                                                    2u  /**< Number of unconditional Tx frames */
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCGetDataMacros  LinIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define LinIf_GetChannelFuncCallCycleOfChannelConfig(Index)                                         (LinIf_GetChannelConfigOfPCConfig()[(Index)].ChannelFuncCallCycleOfChannelConfig)
#define LinIf_GetFrameLengthDelayListEndIdxOfChannelConfig(Index)                                   (LinIf_GetChannelConfigOfPCConfig()[(Index)].FrameLengthDelayListEndIdxOfChannelConfig)
#define LinIf_GetFrameLengthDelayListStartIdxOfChannelConfig(Index)                                 (LinIf_GetChannelConfigOfPCConfig()[(Index)].FrameLengthDelayListStartIdxOfChannelConfig)
#define LinIf_GetFrameListEndIdxOfChannelConfig(Index)                                              (LinIf_GetChannelConfigOfPCConfig()[(Index)].FrameListEndIdxOfChannelConfig)
#define LinIf_GetFrameListStartIdxOfChannelConfig(Index)                                            (LinIf_GetChannelConfigOfPCConfig()[(Index)].FrameListStartIdxOfChannelConfig)
#define LinIf_GetLoadBalancingOffsetOfChannelConfig(Index)                                          (LinIf_GetChannelConfigOfPCConfig()[(Index)].LoadBalancingOffsetOfChannelConfig)
#define LinIf_GetNodeChannelConfigIdxOfChannelConfig(Index)                                         (LinIf_GetChannelConfigOfPCConfig()[(Index)].NodeChannelConfigIdxOfChannelConfig)
#define LinIf_GetNodeChannelDataIdxOfChannelConfig(Index)                                           (LinIf_GetChannelConfigOfPCConfig()[(Index)].NodeChannelDataIdxOfChannelConfig)
#define LinIf_GetNodeTypeOfChannelConfig(Index)                                                     (LinIf_GetChannelConfigOfPCConfig()[(Index)].NodeTypeOfChannelConfig)
#define LinIf_GetStartupStateOfChannelConfig(Index)                                                 (LinIf_GetChannelConfigOfPCConfig()[(Index)].StartupStateOfChannelConfig)
#define LinIf_GetTimeBaseOfChannelConfig(Index)                                                     (LinIf_GetChannelConfigOfPCConfig()[(Index)].TimeBaseOfChannelConfig)
#define LinIf_GetWakeupDelayExternalOfChannelConfig(Index)                                          (LinIf_GetChannelConfigOfPCConfig()[(Index)].WakeupDelayExternalOfChannelConfig)
#define LinIf_GetWakeupDelayInternalOfChannelConfig(Index)                                          (LinIf_GetChannelConfigOfPCConfig()[(Index)].WakeupDelayInternalOfChannelConfig)
#define LinIf_GetChannelData(Index)                                                                 (LinIf_GetChannelDataOfPCConfig()[(Index)])
#define LinIf_GetLinChannelIndexOfChannelIndTable(Index)                                            (LinIf_GetChannelIndTableOfPCConfig()[(Index)].LinChannelIndexOfChannelIndTable)
#define LinIf_GetSystemChannelIndexOfChannelIndTable(Index)                                         (LinIf_GetChannelIndTableOfPCConfig()[(Index)].SystemChannelIndexOfChannelIndTable)
#define LinIf_GetLinWakeupSourceOfChannelToDrvWakeupInfo(Index)                                     (LinIf_GetChannelToDrvWakeupInfoOfPCConfig()[(Index)].LinWakeupSourceOfChannelToDrvWakeupInfo)
#define LinIf_GetDelayInTimebaseTicksOfEntry(Index)                                                 (LinIf_GetEntryOfPCConfig()[(Index)].DelayInTimebaseTicksOfEntry)
#define LinIf_GetFrameListIdxOfEntry(Index)                                                         (LinIf_GetEntryOfPCConfig()[(Index)].FrameListIdxOfEntry)
#define LinIf_GetFrameLengthDelayOfFrameLengthDelayList(Index)                                      (LinIf_GetFrameLengthDelayListOfPCConfig()[(Index)].FrameLengthDelayOfFrameLengthDelayList)
#define LinIf_GetChecksumTypeOfFrameList(Index)                                                     (LinIf_GetFrameListOfPCConfig()[(Index)].ChecksumTypeOfFrameList)
#define LinIf_GetDirectionOfFrameList(Index)                                                        (LinIf_GetFrameListOfPCConfig()[(Index)].DirectionOfFrameList)
#define LinIf_GetFrameTypeOfFrameList(Index)                                                        (LinIf_GetFrameListOfPCConfig()[(Index)].FrameTypeOfFrameList)
#define LinIf_GetLengthOfFrameList(Index)                                                           (LinIf_GetFrameListOfPCConfig()[(Index)].LengthOfFrameList)
#define LinIf_GetPduIdOfFrameList(Index)                                                            (LinIf_GetFrameListOfPCConfig()[(Index)].PduIdOfFrameList)
#define LinIf_GetPidOfFrameList(Index)                                                              (LinIf_GetFrameListOfPCConfig()[(Index)].PidOfFrameList)
#define LinIf_GetTrcvChannelOfLinIfToLinTrcvChannel(Index)                                          (LinIf_GetLinIfToLinTrcvChannelOfPCConfig()[(Index)].TrcvChannelOfLinIfToLinTrcvChannel)
#define LinIf_GetTrcvNrOfLinIfToLinTrcvNr(Index)                                                    (LinIf_GetLinIfToLinTrcvNrOfPCConfig()[(Index)].TrcvNrOfLinIfToLinTrcvNr)
#define LinIf_GetLinTrcv_CheckWakeupFct(Index)                                                      (LinIf_GetLinTrcv_CheckWakeupFctOfPCConfig()[(Index)])
#define LinIf_GetLinTrcv_GetBusWuReasonFct(Index)                                                   (LinIf_GetLinTrcv_GetBusWuReasonFctOfPCConfig()[(Index)])
#define LinIf_GetLinTrcv_GetOpModeFct(Index)                                                        (LinIf_GetLinTrcv_GetOpModeFctOfPCConfig()[(Index)])
#define LinIf_GetLinTrcv_SetOpModeFct(Index)                                                        (LinIf_GetLinTrcv_SetOpModeFctOfPCConfig()[(Index)])
#define LinIf_GetLinTrcv_SetWakeupModeFct(Index)                                                    (LinIf_GetLinTrcv_SetWakeupModeFctOfPCConfig()[(Index)])
#define LinIf_GetNumberOfSchedulesOfMasterChannelConfig(Index)                                      ((LinIf_SchHandleType)LinIf_GetMasterChannelConfigOfPCConfig()[(Index)].NumberOfSchedulesOfMasterChannelConfig)
#define LinIf_IsScheduleChangeBeforeSlotEndOfMasterChannelConfig(Index)                             ((LinIf_GetMasterChannelConfigOfPCConfig()[(Index)].ScheduleChangeBeforeSlotEndOfMasterChannelConfig) != FALSE)
#define LinIf_GetScheduleTableListIndEndIdxOfMasterChannelConfig(Index)                             (LinIf_GetMasterChannelConfigOfPCConfig()[(Index)].ScheduleTableListIndEndIdxOfMasterChannelConfig)
#define LinIf_GetScheduleTableListIndStartIdxOfMasterChannelConfig(Index)                           (LinIf_GetMasterChannelConfigOfPCConfig()[(Index)].ScheduleTableListIndStartIdxOfMasterChannelConfig)
#define LinIf_GetMasterChannelData(Index)                                                           (LinIf_GetMasterChannelDataOfPCConfig()[(Index)])
#define LinIf_GetEntryEndIdxOfScheduleTableList(Index)                                              (LinIf_GetScheduleTableListOfPCConfig()[(Index)].EntryEndIdxOfScheduleTableList)
#define LinIf_GetEntryStartIdxOfScheduleTableList(Index)                                            (LinIf_GetScheduleTableListOfPCConfig()[(Index)].EntryStartIdxOfScheduleTableList)
#define LinIf_GetNumberOfScheduleEntriesOfScheduleTableList(Index)                                  (LinIf_GetScheduleTableListOfPCConfig()[(Index)].NumberOfScheduleEntriesOfScheduleTableList)
#define LinIf_GetResumePositionOfScheduleTableList(Index)                                           (LinIf_GetScheduleTableListOfPCConfig()[(Index)].ResumePositionOfScheduleTableList)
#define LinIf_GetRunModeOfScheduleTableList(Index)                                                  (LinIf_GetScheduleTableListOfPCConfig()[(Index)].RunModeOfScheduleTableList)
#define LinIf_GetScheduleTableListInd(Index)                                                        (LinIf_GetScheduleTableListIndOfPCConfig()[(Index)])
#define LinIf_GetConfiguredNADOfSlaveChannelConfig(Index)                                           (LinIf_GetSlaveChannelConfigOfPCConfig()[(Index)].ConfiguredNADOfSlaveChannelConfig)
#define LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Index)                                     (LinIf_GetSystemToLinIfChannelOfPCConfig()[(Index)].LinIfChannelIndexOfSystemToLinIfChannel)
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCGetDeduplicatedDataMacros  LinIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define LinIf_IsFrameLengthDelayListUsedOfChannelConfig(Index)                                      (((boolean)(LinIf_GetFrameLengthDelayListStartIdxOfChannelConfig(Index) != LINIF_NO_FRAMELENGTHDELAYLISTSTARTIDXOFCHANNELCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to LinIf_FrameLengthDelayList */
#define LinIf_IsScheduleTableListIndUsedOfMasterChannelConfig(Index)                                (((boolean)(LinIf_GetScheduleTableListIndStartIdxOfMasterChannelConfig(Index) != LINIF_NO_SCHEDULETABLELISTINDSTARTIDXOFMASTERCHANNELCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to LinIf_ScheduleTableListInd */
#define LinIf_IsEntryUsedOfScheduleTableList(Index)                                                 (((boolean)(LinIf_GetEntryStartIdxOfScheduleTableList(Index) != LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to LinIf_Entry */
#define LinIf_GetSizeOfChannelConfig()                                                              LinIf_GetSizeOfChannelConfigOfPCConfig()
#define LinIf_GetSizeOfChannelData()                                                                LinIf_GetSizeOfChannelDataOfPCConfig()
#define LinIf_GetSizeOfMasterChannelData()                                                          LinIf_GetSizeOfMasterChannelDataOfPCConfig()
#define LinIf_GetSizeOfSystemToLinIfChannel()                                                       LinIf_GetSizeOfSystemToLinIfChannelOfPCConfig()
#define LinIf_GetUncTxFrmTotalNumber()                                                              LinIf_GetUncTxFrmTotalNumberOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCSetDataMacros  LinIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define LinIf_SetChannelData(Index, Value)                                                          LinIf_GetChannelDataOfPCConfig()[(Index)] = (Value)
#define LinIf_SetMasterChannelData(Index, Value)                                                    LinIf_GetMasterChannelDataOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCGetAddressOfDataMacros  LinIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define LinIf_GetAddrChannelData(Index)                                                             (&LinIf_GetChannelData(Index))
#define LinIf_GetAddrMasterChannelData(Index)                                                       (&LinIf_GetMasterChannelData(Index))
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCHasMacros  LinIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define LinIf_HasChannelConfig()                                                                    (TRUE != FALSE)
#define LinIf_HasChannelFuncCallCycleOfChannelConfig()                                              (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayListEndIdxOfChannelConfig()                                        (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayListStartIdxOfChannelConfig()                                      (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayListUsedOfChannelConfig()                                          (TRUE != FALSE)
#define LinIf_HasFrameListEndIdxOfChannelConfig()                                                   (TRUE != FALSE)
#define LinIf_HasFrameListStartIdxOfChannelConfig()                                                 (TRUE != FALSE)
#define LinIf_HasLoadBalancingOffsetOfChannelConfig()                                               (TRUE != FALSE)
#define LinIf_HasNodeChannelConfigIdxOfChannelConfig()                                              (TRUE != FALSE)
#define LinIf_HasNodeChannelDataIdxOfChannelConfig()                                                (TRUE != FALSE)
#define LinIf_HasNodeTypeOfChannelConfig()                                                          (TRUE != FALSE)
#define LinIf_HasStartupStateOfChannelConfig()                                                      (TRUE != FALSE)
#define LinIf_HasTimeBaseOfChannelConfig()                                                          (TRUE != FALSE)
#define LinIf_HasWakeupDelayExternalOfChannelConfig()                                               (TRUE != FALSE)
#define LinIf_HasWakeupDelayInternalOfChannelConfig()                                               (TRUE != FALSE)
#define LinIf_HasChannelData()                                                                      (TRUE != FALSE)
#define LinIf_HasChannelIndTable()                                                                  (TRUE != FALSE)
#define LinIf_HasLinChannelIndexOfChannelIndTable()                                                 (TRUE != FALSE)
#define LinIf_HasSystemChannelIndexOfChannelIndTable()                                              (TRUE != FALSE)
#define LinIf_HasChannelToDrvWakeupInfo()                                                           (TRUE != FALSE)
#define LinIf_HasLinWakeupSourceOfChannelToDrvWakeupInfo()                                          (TRUE != FALSE)
#define LinIf_HasEntry()                                                                            (TRUE != FALSE)
#define LinIf_HasDelayInTimebaseTicksOfEntry()                                                      (TRUE != FALSE)
#define LinIf_HasFrameListIdxOfEntry()                                                              (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayList()                                                             (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayOfFrameLengthDelayList()                                           (TRUE != FALSE)
#define LinIf_HasFrameList()                                                                        (TRUE != FALSE)
#define LinIf_HasChecksumTypeOfFrameList()                                                          (TRUE != FALSE)
#define LinIf_HasDirectionOfFrameList()                                                             (TRUE != FALSE)
#define LinIf_HasFrameTypeOfFrameList()                                                             (TRUE != FALSE)
#define LinIf_HasLengthOfFrameList()                                                                (TRUE != FALSE)
#define LinIf_HasPduIdOfFrameList()                                                                 (TRUE != FALSE)
#define LinIf_HasPidOfFrameList()                                                                   (TRUE != FALSE)
#define LinIf_HasLinIfToLinTrcvChannel()                                                            (TRUE != FALSE)
#define LinIf_HasTrcvChannelOfLinIfToLinTrcvChannel()                                               (TRUE != FALSE)
#define LinIf_HasLinIfToLinTrcvNr()                                                                 (TRUE != FALSE)
#define LinIf_HasTrcvNrOfLinIfToLinTrcvNr()                                                         (TRUE != FALSE)
#define LinIf_HasLinTrcv_CheckWakeupFct()                                                           (TRUE != FALSE)
#define LinIf_HasLinTrcv_GetBusWuReasonFct()                                                        (TRUE != FALSE)
#define LinIf_HasLinTrcv_GetOpModeFct()                                                             (TRUE != FALSE)
#define LinIf_HasLinTrcv_SetOpModeFct()                                                             (TRUE != FALSE)
#define LinIf_HasLinTrcv_SetWakeupModeFct()                                                         (TRUE != FALSE)
#define LinIf_HasMasterChannelConfig()                                                              (TRUE != FALSE)
#define LinIf_HasNumberOfSchedulesOfMasterChannelConfig()                                           (TRUE != FALSE)
#define LinIf_HasScheduleChangeBeforeSlotEndOfMasterChannelConfig()                                 (TRUE != FALSE)
#define LinIf_HasScheduleTableListIndEndIdxOfMasterChannelConfig()                                  (TRUE != FALSE)
#define LinIf_HasScheduleTableListIndStartIdxOfMasterChannelConfig()                                (TRUE != FALSE)
#define LinIf_HasScheduleTableListIndUsedOfMasterChannelConfig()                                    (TRUE != FALSE)
#define LinIf_HasMasterChannelData()                                                                (TRUE != FALSE)
#define LinIf_HasScheduleTableList()                                                                (TRUE != FALSE)
#define LinIf_HasEntryEndIdxOfScheduleTableList()                                                   (TRUE != FALSE)
#define LinIf_HasEntryStartIdxOfScheduleTableList()                                                 (TRUE != FALSE)
#define LinIf_HasEntryUsedOfScheduleTableList()                                                     (TRUE != FALSE)
#define LinIf_HasNumberOfScheduleEntriesOfScheduleTableList()                                       (TRUE != FALSE)
#define LinIf_HasResumePositionOfScheduleTableList()                                                (TRUE != FALSE)
#define LinIf_HasRunModeOfScheduleTableList()                                                       (TRUE != FALSE)
#define LinIf_HasScheduleTableListInd()                                                             (TRUE != FALSE)
#define LinIf_HasSizeOfChannelConfig()                                                              (TRUE != FALSE)
#define LinIf_HasSizeOfChannelData()                                                                (TRUE != FALSE)
#define LinIf_HasSizeOfMasterChannelData()                                                          (TRUE != FALSE)
#define LinIf_HasSizeOfSystemToLinIfChannel()                                                       (TRUE != FALSE)
#define LinIf_HasSlaveChannelConfig()                                                               (TRUE != FALSE)
#define LinIf_HasConfiguredNADOfSlaveChannelConfig()                                                (TRUE != FALSE)
#define LinIf_HasSystemToLinIfChannel()                                                             (TRUE != FALSE)
#define LinIf_HasLinIfChannelIndexOfSystemToLinIfChannel()                                          (TRUE != FALSE)
#define LinIf_HasUncTxFrmTotalNumber()                                                              (TRUE != FALSE)
#define LinIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define LinIf_HasChannelConfigOfPCConfig()                                                          (TRUE != FALSE)
#define LinIf_HasChannelDataOfPCConfig()                                                            (TRUE != FALSE)
#define LinIf_HasChannelIndTableOfPCConfig()                                                        (TRUE != FALSE)
#define LinIf_HasChannelToDrvWakeupInfoOfPCConfig()                                                 (TRUE != FALSE)
#define LinIf_HasEntryOfPCConfig()                                                                  (TRUE != FALSE)
#define LinIf_HasFrameLengthDelayListOfPCConfig()                                                   (TRUE != FALSE)
#define LinIf_HasFrameListOfPCConfig()                                                              (TRUE != FALSE)
#define LinIf_HasLinIfToLinTrcvChannelOfPCConfig()                                                  (TRUE != FALSE)
#define LinIf_HasLinIfToLinTrcvNrOfPCConfig()                                                       (TRUE != FALSE)
#define LinIf_HasLinTrcv_CheckWakeupFctOfPCConfig()                                                 (TRUE != FALSE)
#define LinIf_HasLinTrcv_GetBusWuReasonFctOfPCConfig()                                              (TRUE != FALSE)
#define LinIf_HasLinTrcv_GetOpModeFctOfPCConfig()                                                   (TRUE != FALSE)
#define LinIf_HasLinTrcv_SetOpModeFctOfPCConfig()                                                   (TRUE != FALSE)
#define LinIf_HasLinTrcv_SetWakeupModeFctOfPCConfig()                                               (TRUE != FALSE)
#define LinIf_HasMasterChannelConfigOfPCConfig()                                                    (TRUE != FALSE)
#define LinIf_HasMasterChannelDataOfPCConfig()                                                      (TRUE != FALSE)
#define LinIf_HasScheduleTableListIndOfPCConfig()                                                   (TRUE != FALSE)
#define LinIf_HasScheduleTableListOfPCConfig()                                                      (TRUE != FALSE)
#define LinIf_HasSizeOfChannelConfigOfPCConfig()                                                    (TRUE != FALSE)
#define LinIf_HasSizeOfChannelDataOfPCConfig()                                                      (TRUE != FALSE)
#define LinIf_HasSizeOfMasterChannelDataOfPCConfig()                                                (TRUE != FALSE)
#define LinIf_HasSizeOfSystemToLinIfChannelOfPCConfig()                                             (TRUE != FALSE)
#define LinIf_HasSlaveChannelConfigOfPCConfig()                                                     (TRUE != FALSE)
#define LinIf_HasSystemToLinIfChannelOfPCConfig()                                                   (TRUE != FALSE)
#define LinIf_HasUncTxFrmTotalNumberOfPCConfig()                                                    (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCIncrementDataMacros  LinIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define LinIf_IncChannelData(Index)                                                                 LinIf_GetChannelData(Index)++
#define LinIf_IncMasterChannelData(Index)                                                           LinIf_GetMasterChannelData(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCDecrementDataMacros  LinIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define LinIf_DecChannelData(Index)                                                                 LinIf_GetChannelData(Index)--
#define LinIf_DecMasterChannelData(Index)                                                           LinIf_GetMasterChannelData(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCAddDataMacros  LinIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define LinIf_AddChannelData(Index, Value)                                                          LinIf_SetChannelData(Index, (LinIf_GetChannelData(Index) + Value))
#define LinIf_AddMasterChannelData(Index, Value)                                                    LinIf_SetMasterChannelData(Index, (LinIf_GetMasterChannelData(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCSubstractDataMacros  LinIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define LinIf_SubChannelData(Index, Value)                                                          LinIf_SetChannelData(Index, (LinIf_GetChannelData(Index) - Value))
#define LinIf_SubMasterChannelData(Index, Value)                                                    LinIf_SetMasterChannelData(Index, (LinIf_GetMasterChannelData(Index) - Value))
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
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LinIfPCIterableTypes  LinIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate LinIf_ChannelConfig */
typedef uint8_least LinIf_ChannelConfigIterType;

/**   \brief  type used to iterate LinIf_ChannelData */
typedef uint8_least LinIf_ChannelDataIterType;

/**   \brief  type used to iterate LinIf_ChannelIndTable */
typedef uint8_least LinIf_ChannelIndTableIterType;

/**   \brief  type used to iterate LinIf_ChannelToDrvWakeupInfo */
typedef uint8_least LinIf_ChannelToDrvWakeupInfoIterType;

/**   \brief  type used to iterate LinIf_Entry */
typedef uint8_least LinIf_EntryIterType;

/**   \brief  type used to iterate LinIf_FrameLengthDelayList */
typedef uint8_least LinIf_FrameLengthDelayListIterType;

/**   \brief  type used to iterate LinIf_FrameList */
typedef uint8_least LinIf_FrameListIterType;

/**   \brief  type used to iterate LinIf_LinIfToLinTrcvChannel */
typedef uint8_least LinIf_LinIfToLinTrcvChannelIterType;

/**   \brief  type used to iterate LinIf_LinIfToLinTrcvNr */
typedef uint8_least LinIf_LinIfToLinTrcvNrIterType;

/**   \brief  type used to iterate LinIf_LinTrcv_CheckWakeupFct */
typedef uint8_least LinIf_LinTrcv_CheckWakeupFctIterType;

/**   \brief  type used to iterate LinIf_LinTrcv_GetBusWuReasonFct */
typedef uint8_least LinIf_LinTrcv_GetBusWuReasonFctIterType;

/**   \brief  type used to iterate LinIf_LinTrcv_GetOpModeFct */
typedef uint8_least LinIf_LinTrcv_GetOpModeFctIterType;

/**   \brief  type used to iterate LinIf_LinTrcv_SetOpModeFct */
typedef uint8_least LinIf_LinTrcv_SetOpModeFctIterType;

/**   \brief  type used to iterate LinIf_LinTrcv_SetWakeupModeFct */
typedef uint8_least LinIf_LinTrcv_SetWakeupModeFctIterType;

/**   \brief  type used to iterate LinIf_MasterChannelConfig */
typedef uint8_least LinIf_MasterChannelConfigIterType;

/**   \brief  type used to iterate LinIf_MasterChannelData */
typedef uint8_least LinIf_MasterChannelDataIterType;

/**   \brief  type used to iterate LinIf_ScheduleTableList */
typedef uint8_least LinIf_ScheduleTableListIterType;

/**   \brief  type used to iterate LinIf_ScheduleTableListInd */
typedef uint8_least LinIf_ScheduleTableListIndIterType;

/**   \brief  type used to iterate LinIf_SlaveChannelConfig */
typedef uint8_least LinIf_SlaveChannelConfigIterType;

/**   \brief  type used to iterate LinIf_SystemToLinIfChannel */
typedef uint8_least LinIf_SystemToLinIfChannelIterType;

/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCValueTypes  LinIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for LinIf_ChannelFuncCallCycleOfChannelConfig */
typedef uint8 LinIf_ChannelFuncCallCycleOfChannelConfigType;

/**   \brief  value based type definition for LinIf_FrameLengthDelayListEndIdxOfChannelConfig */
typedef uint8 LinIf_FrameLengthDelayListEndIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_FrameLengthDelayListStartIdxOfChannelConfig */
typedef uint8 LinIf_FrameLengthDelayListStartIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_FrameLengthDelayListUsedOfChannelConfig */
typedef boolean LinIf_FrameLengthDelayListUsedOfChannelConfigType;

/**   \brief  value based type definition for LinIf_FrameListEndIdxOfChannelConfig */
typedef uint8 LinIf_FrameListEndIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_FrameListStartIdxOfChannelConfig */
typedef uint8 LinIf_FrameListStartIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_LoadBalancingOffsetOfChannelConfig */
typedef uint8 LinIf_LoadBalancingOffsetOfChannelConfigType;

/**   \brief  value based type definition for LinIf_NodeChannelConfigIdxOfChannelConfig */
typedef uint8 LinIf_NodeChannelConfigIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_NodeChannelDataIdxOfChannelConfig */
typedef uint8 LinIf_NodeChannelDataIdxOfChannelConfigType;

/**   \brief  value based type definition for LinIf_NodeTypeOfChannelConfig */
typedef uint8 LinIf_NodeTypeOfChannelConfigType;

/**   \brief  value based type definition for LinIf_StartupStateOfChannelConfig */
typedef uint8 LinIf_StartupStateOfChannelConfigType;

/**   \brief  value based type definition for LinIf_TimeBaseOfChannelConfig */
typedef uint8 LinIf_TimeBaseOfChannelConfigType;

/**   \brief  value based type definition for LinIf_WakeupDelayExternalOfChannelConfig */
typedef uint8 LinIf_WakeupDelayExternalOfChannelConfigType;

/**   \brief  value based type definition for LinIf_WakeupDelayInternalOfChannelConfig */
typedef uint8 LinIf_WakeupDelayInternalOfChannelConfigType;

/**   \brief  value based type definition for LinIf_LinChannelIndexOfChannelIndTable */
typedef uint8 LinIf_LinChannelIndexOfChannelIndTableType;

/**   \brief  value based type definition for LinIf_SystemChannelIndexOfChannelIndTable */
typedef uint8 LinIf_SystemChannelIndexOfChannelIndTableType;

/**   \brief  value based type definition for LinIf_LinWakeupSourceOfChannelToDrvWakeupInfo */
typedef uint8 LinIf_LinWakeupSourceOfChannelToDrvWakeupInfoType;

/**   \brief  value based type definition for LinIf_DelayInTimebaseTicksOfEntry */
typedef uint8 LinIf_DelayInTimebaseTicksOfEntryType;

/**   \brief  value based type definition for LinIf_FrameListIdxOfEntry */
typedef uint8 LinIf_FrameListIdxOfEntryType;

/**   \brief  value based type definition for LinIf_FrameLengthDelayOfFrameLengthDelayList */
typedef uint8 LinIf_FrameLengthDelayOfFrameLengthDelayListType;

/**   \brief  value based type definition for LinIf_FrameTypeOfFrameList */
typedef uint8 LinIf_FrameTypeOfFrameListType;

/**   \brief  value based type definition for LinIf_LengthOfFrameList */
typedef uint8 LinIf_LengthOfFrameListType;

/**   \brief  value based type definition for LinIf_PduIdOfFrameList */
typedef PduIdType LinIf_PduIdOfFrameListType;

/**   \brief  value based type definition for LinIf_PidOfFrameList */
typedef uint8 LinIf_PidOfFrameListType;

/**   \brief  value based type definition for LinIf_TrcvChannelOfLinIfToLinTrcvChannel */
typedef uint8 LinIf_TrcvChannelOfLinIfToLinTrcvChannelType;

/**   \brief  value based type definition for LinIf_TrcvNrOfLinIfToLinTrcvNr */
typedef uint8 LinIf_TrcvNrOfLinIfToLinTrcvNrType;

/**   \brief  value based type definition for LinIf_NumberOfSchedulesOfMasterChannelConfig */
typedef uint8 LinIf_NumberOfSchedulesOfMasterChannelConfigType;

/**   \brief  value based type definition for LinIf_ScheduleChangeBeforeSlotEndOfMasterChannelConfig */
typedef boolean LinIf_ScheduleChangeBeforeSlotEndOfMasterChannelConfigType;

/**   \brief  value based type definition for LinIf_ScheduleTableListIndEndIdxOfMasterChannelConfig */
typedef uint8 LinIf_ScheduleTableListIndEndIdxOfMasterChannelConfigType;

/**   \brief  value based type definition for LinIf_ScheduleTableListIndStartIdxOfMasterChannelConfig */
typedef uint8 LinIf_ScheduleTableListIndStartIdxOfMasterChannelConfigType;

/**   \brief  value based type definition for LinIf_ScheduleTableListIndUsedOfMasterChannelConfig */
typedef boolean LinIf_ScheduleTableListIndUsedOfMasterChannelConfigType;

/**   \brief  value based type definition for LinIf_EntryEndIdxOfScheduleTableList */
typedef uint8 LinIf_EntryEndIdxOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_EntryStartIdxOfScheduleTableList */
typedef uint8 LinIf_EntryStartIdxOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_EntryUsedOfScheduleTableList */
typedef boolean LinIf_EntryUsedOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_NumberOfScheduleEntriesOfScheduleTableList */
typedef uint8 LinIf_NumberOfScheduleEntriesOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_ResumePositionOfScheduleTableList */
typedef uint8 LinIf_ResumePositionOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_RunModeOfScheduleTableList */
typedef uint8 LinIf_RunModeOfScheduleTableListType;

/**   \brief  value based type definition for LinIf_ScheduleTableListInd */
typedef uint8 LinIf_ScheduleTableListIndType;

/**   \brief  value based type definition for LinIf_SizeOfChannelConfig */
typedef uint8 LinIf_SizeOfChannelConfigType;

/**   \brief  value based type definition for LinIf_SizeOfChannelData */
typedef uint8 LinIf_SizeOfChannelDataType;

/**   \brief  value based type definition for LinIf_SizeOfMasterChannelData */
typedef uint8 LinIf_SizeOfMasterChannelDataType;

/**   \brief  value based type definition for LinIf_SizeOfSystemToLinIfChannel */
typedef uint8 LinIf_SizeOfSystemToLinIfChannelType;

/**   \brief  value based type definition for LinIf_ConfiguredNADOfSlaveChannelConfig */
typedef uint8 LinIf_ConfiguredNADOfSlaveChannelConfigType;

/**   \brief  value based type definition for LinIf_LinIfChannelIndexOfSystemToLinIfChannel */
typedef uint8 LinIf_LinIfChannelIndexOfSystemToLinIfChannelType;

/**   \brief  value based type definition for LinIf_UncTxFrmTotalNumber */
typedef uint8 LinIf_UncTxFrmTotalNumberType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LinIfPCStructTypes  LinIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in LinIf_ChannelConfig */
typedef struct sLinIf_ChannelConfigType
{
  LinIf_ChannelFuncCallCycleOfChannelConfigType ChannelFuncCallCycleOfChannelConfig;  /**< Channel function call cycle */
  LinIf_FrameLengthDelayListEndIdxOfChannelConfigType FrameLengthDelayListEndIdxOfChannelConfig;  /**< the end index of the 0:n relation pointing to LinIf_FrameLengthDelayList */
  LinIf_FrameLengthDelayListStartIdxOfChannelConfigType FrameLengthDelayListStartIdxOfChannelConfig;  /**< the start index of the 0:n relation pointing to LinIf_FrameLengthDelayList */
  LinIf_FrameListEndIdxOfChannelConfigType FrameListEndIdxOfChannelConfig;  /**< the end index of the 1:n relation pointing to LinIf_FrameList */
  LinIf_FrameListStartIdxOfChannelConfigType FrameListStartIdxOfChannelConfig;  /**< the start index of the 1:n relation pointing to LinIf_FrameList */
  LinIf_LoadBalancingOffsetOfChannelConfigType LoadBalancingOffsetOfChannelConfig;  /**< Load balancing offset in ticks */
  LinIf_NodeChannelConfigIdxOfChannelConfigType NodeChannelConfigIdxOfChannelConfig;  /**< the index of the 1:1 relation pointing to one of LinIf_MasterChannelConfig,LinIf_SlaveChannelConfig */
  LinIf_NodeChannelDataIdxOfChannelConfigType NodeChannelDataIdxOfChannelConfig;  /**< the index of the 1:1 relation pointing to one of LinIf_MasterChannelData,LinIf_SlaveChannelData */
  LinIf_NodeTypeOfChannelConfigType NodeTypeOfChannelConfig;  /**< LIN channel node type */
  LinIf_StartupStateOfChannelConfigType StartupStateOfChannelConfig;  /**< Startup state of channel: 0 : sleep 1 : operational state */
  LinIf_TimeBaseOfChannelConfigType TimeBaseOfChannelConfig;  /**< Channel time base */
  LinIf_WakeupDelayExternalOfChannelConfigType WakeupDelayExternalOfChannelConfig;  /**< External wakeup delay in ticks */
  LinIf_WakeupDelayInternalOfChannelConfigType WakeupDelayInternalOfChannelConfig;  /**< Internal wakeup delay in ticks */
} LinIf_ChannelConfigType;

/**   \brief  type used in LinIf_ChannelIndTable */
typedef struct sLinIf_ChannelIndTableType
{
  LinIf_LinChannelIndexOfChannelIndTableType LinChannelIndexOfChannelIndTable;  /**< LIN Driver channel index */
  LinIf_SystemChannelIndexOfChannelIndTableType SystemChannelIndexOfChannelIndTable;  /**< ComM (System) channel index */
} LinIf_ChannelIndTableType;

/**   \brief  type used in LinIf_ChannelToDrvWakeupInfo */
typedef struct sLinIf_ChannelToDrvWakeupInfoType
{
  LinIf_LinWakeupSourceOfChannelToDrvWakeupInfoType LinWakeupSourceOfChannelToDrvWakeupInfo;  /**< Defines the ID of the wakeup source. Zero means invalid source and that external wakeup is not supported. */
} LinIf_ChannelToDrvWakeupInfoType;

/**   \brief  type used in LinIf_Entry */
typedef struct sLinIf_EntryType
{
  LinIf_DelayInTimebaseTicksOfEntryType DelayInTimebaseTicksOfEntry;
  LinIf_FrameListIdxOfEntryType FrameListIdxOfEntry;  /**< the index of the 1:1 relation pointing to LinIf_FrameList */
} LinIf_EntryType;

/**   \brief  type used in LinIf_FrameLengthDelayList */
typedef struct sLinIf_FrameLengthDelayListType
{
  LinIf_FrameLengthDelayOfFrameLengthDelayListType FrameLengthDelayOfFrameLengthDelayList;
} LinIf_FrameLengthDelayListType;

/**   \brief  type used in LinIf_FrameList */
typedef struct sLinIf_FrameListType
{
  LinIf_PduIdOfFrameListType PduIdOfFrameList;  /**< Upper layer PduId */
  LinIf_FrameTypeOfFrameListType FrameTypeOfFrameList;  /**< UNCONDITIONAL : 0 MRF : 1 SRF : 2 EVENT_TRIGGERED : 4 SPORADIC : 5 ASSIGN : 6 UNASSIGN : 7 ASSIGN_NAD : 8 FREE : 9 CONDITIONAL : 10 ASSIGN_FRAME_ID_RANGE : 11 SAVE_CONFIGURATION : 12 */
  LinIf_LengthOfFrameListType LengthOfFrameList;  /**< Frame length in bytes */
  LinIf_PidOfFrameListType PidOfFrameList;  /**< Protected Identifier */
  Lin_FrameCsModelType ChecksumTypeOfFrameList;  /**< CLASSIC ENHANCED */
  Lin_FrameResponseType DirectionOfFrameList;  /**< TX RX S2S */
} LinIf_FrameListType;

/**   \brief  type used in LinIf_LinIfToLinTrcvChannel */
typedef struct sLinIf_LinIfToLinTrcvChannelType
{
  LinIf_TrcvChannelOfLinIfToLinTrcvChannelType TrcvChannelOfLinIfToLinTrcvChannel;
} LinIf_LinIfToLinTrcvChannelType;

/**   \brief  type used in LinIf_LinIfToLinTrcvNr */
typedef struct sLinIf_LinIfToLinTrcvNrType
{
  LinIf_TrcvNrOfLinIfToLinTrcvNrType TrcvNrOfLinIfToLinTrcvNr;
} LinIf_LinIfToLinTrcvNrType;

/**   \brief  type used in LinIf_MasterChannelConfig */
typedef struct sLinIf_MasterChannelConfigType
{
  LinIf_ScheduleChangeBeforeSlotEndOfMasterChannelConfigType ScheduleChangeBeforeSlotEndOfMasterChannelConfig;  /**< Point of schedule table change. True = after maximum frame time, False = at end of schedule slot. */
  LinIf_NumberOfSchedulesOfMasterChannelConfigType NumberOfSchedulesOfMasterChannelConfig;  /**< Number of schedule tables */
  LinIf_ScheduleTableListIndEndIdxOfMasterChannelConfigType ScheduleTableListIndEndIdxOfMasterChannelConfig;  /**< the end index of the 0:n relation pointing to LinIf_ScheduleTableListInd */
  LinIf_ScheduleTableListIndStartIdxOfMasterChannelConfigType ScheduleTableListIndStartIdxOfMasterChannelConfig;  /**< the start index of the 0:n relation pointing to LinIf_ScheduleTableListInd */
} LinIf_MasterChannelConfigType;

/**   \brief  type used in LinIf_ScheduleTableList */
typedef struct sLinIf_ScheduleTableListType
{
  LinIf_EntryEndIdxOfScheduleTableListType EntryEndIdxOfScheduleTableList;  /**< the end index of the 0:n relation pointing to LinIf_Entry */
  LinIf_EntryStartIdxOfScheduleTableListType EntryStartIdxOfScheduleTableList;  /**< the start index of the 0:n relation pointing to LinIf_Entry */
  LinIf_NumberOfScheduleEntriesOfScheduleTableListType NumberOfScheduleEntriesOfScheduleTableList;  /**< number of entries */
  LinIf_ResumePositionOfScheduleTableListType ResumePositionOfScheduleTableList;  /**< CONTINUE_AT_IT_POINT : 0 START_FROM_BEGINNING : 1 */
  LinIf_RunModeOfScheduleTableListType RunModeOfScheduleTableList;  /**< RUN_CONTINUOUS : 0 RUN_ONCE : 1 */
} LinIf_ScheduleTableListType;

/**   \brief  type used in LinIf_SlaveChannelConfig */
typedef struct sLinIf_SlaveChannelConfigType
{
  LinIf_ConfiguredNADOfSlaveChannelConfigType ConfiguredNADOfSlaveChannelConfig;  /**< Configured NAD */
} LinIf_SlaveChannelConfigType;

/**   \brief  type used in LinIf_SystemToLinIfChannel */
typedef struct sLinIf_SystemToLinIfChannelType
{
  LinIf_LinIfChannelIndexOfSystemToLinIfChannelType LinIfChannelIndexOfSystemToLinIfChannel;
} LinIf_SystemToLinIfChannelType;

/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCSymbolicStructTypes  LinIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to LinIf_ChannelData */
typedef struct LinIf_ChannelDataStructSTag
{
  LinIf_ChannelDataType CHNL_45618847;
} LinIf_ChannelDataStructSType;

/**   \brief  type to be used as symbolic data element access to LinIf_MasterChannelData */
typedef struct LinIf_MasterChannelDataStructSTag
{
  LinIf_MasterChannelDataType CHNL_45618847;
} LinIf_MasterChannelDataStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCUnionIndexAndSymbolTypes  LinIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access LinIf_ChannelData in an index and symbol based style. */
typedef union LinIf_ChannelDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  LinIf_ChannelDataType raw[1];
  LinIf_ChannelDataStructSType str;
} LinIf_ChannelDataUType;

/**   \brief  type to access LinIf_MasterChannelData in an index and symbol based style. */
typedef union LinIf_MasterChannelDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  LinIf_MasterChannelDataType raw[1];
  LinIf_MasterChannelDataStructSType str;
} LinIf_MasterChannelDataUType;

/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCRootPointerTypes  LinIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to LinIf_ChannelConfig */
typedef P2CONST(LinIf_ChannelConfigType, TYPEDEF, LINIF_CONST) LinIf_ChannelConfigPtrType;

/**   \brief  type used to point to LinIf_ChannelData */
typedef P2VAR(LinIf_ChannelDataType, TYPEDEF, LINIF_VAR_NOINIT) LinIf_ChannelDataPtrType;

/**   \brief  type used to point to LinIf_ChannelIndTable */
typedef P2CONST(LinIf_ChannelIndTableType, TYPEDEF, LINIF_CONST) LinIf_ChannelIndTablePtrType;

/**   \brief  type used to point to LinIf_ChannelToDrvWakeupInfo */
typedef P2CONST(LinIf_ChannelToDrvWakeupInfoType, TYPEDEF, LINIF_CONST) LinIf_ChannelToDrvWakeupInfoPtrType;

/**   \brief  type used to point to LinIf_Entry */
typedef P2CONST(LinIf_EntryType, TYPEDEF, LINIF_CONST) LinIf_EntryPtrType;

/**   \brief  type used to point to LinIf_FrameLengthDelayList */
typedef P2CONST(LinIf_FrameLengthDelayListType, TYPEDEF, LINIF_CONST) LinIf_FrameLengthDelayListPtrType;

/**   \brief  type used to point to LinIf_FrameList */
typedef P2CONST(LinIf_FrameListType, TYPEDEF, LINIF_CONST) LinIf_FrameListPtrType;

/**   \brief  type used to point to LinIf_LinIfToLinTrcvChannel */
typedef P2CONST(LinIf_LinIfToLinTrcvChannelType, TYPEDEF, LINIF_CONST) LinIf_LinIfToLinTrcvChannelPtrType;

/**   \brief  type used to point to LinIf_LinIfToLinTrcvNr */
typedef P2CONST(LinIf_LinIfToLinTrcvNrType, TYPEDEF, LINIF_CONST) LinIf_LinIfToLinTrcvNrPtrType;

/**   \brief  type used to point to LinIf_LinTrcv_CheckWakeupFct */
typedef P2CONST(LinIf_LinTrcv_CheckWakeupFctType, TYPEDEF, LINIF_CONST) LinIf_LinTrcv_CheckWakeupFctPtrType;

/**   \brief  type used to point to LinIf_LinTrcv_GetBusWuReasonFct */
typedef P2CONST(LinIf_LinTrcv_GetBusWuReasonFctType, TYPEDEF, LINIF_CONST) LinIf_LinTrcv_GetBusWuReasonFctPtrType;

/**   \brief  type used to point to LinIf_LinTrcv_GetOpModeFct */
typedef P2CONST(LinIf_LinTrcv_GetOpModeFctType, TYPEDEF, LINIF_CONST) LinIf_LinTrcv_GetOpModeFctPtrType;

/**   \brief  type used to point to LinIf_LinTrcv_SetOpModeFct */
typedef P2CONST(LinIf_LinTrcv_SetOpModeFctType, TYPEDEF, LINIF_CONST) LinIf_LinTrcv_SetOpModeFctPtrType;

/**   \brief  type used to point to LinIf_LinTrcv_SetWakeupModeFct */
typedef P2CONST(LinIf_LinTrcv_SetWakeupModeFctType, TYPEDEF, LINIF_CONST) LinIf_LinTrcv_SetWakeupModeFctPtrType;

/**   \brief  type used to point to LinIf_MasterChannelConfig */
typedef P2CONST(LinIf_MasterChannelConfigType, TYPEDEF, LINIF_CONST) LinIf_MasterChannelConfigPtrType;

/**   \brief  type used to point to LinIf_MasterChannelData */
typedef P2VAR(LinIf_MasterChannelDataType, TYPEDEF, LINIF_VAR_NOINIT) LinIf_MasterChannelDataPtrType;

/**   \brief  type used to point to LinIf_ScheduleTableList */
typedef P2CONST(LinIf_ScheduleTableListType, TYPEDEF, LINIF_CONST) LinIf_ScheduleTableListPtrType;

/**   \brief  type used to point to LinIf_ScheduleTableListInd */
typedef P2CONST(LinIf_ScheduleTableListIndType, TYPEDEF, LINIF_CONST) LinIf_ScheduleTableListIndPtrType;

/**   \brief  type used to point to LinIf_SlaveChannelConfig */
typedef P2CONST(LinIf_SlaveChannelConfigType, TYPEDEF, LINIF_CONST) LinIf_SlaveChannelConfigPtrType;

/**   \brief  type used to point to LinIf_SystemToLinIfChannel */
typedef P2CONST(LinIf_SystemToLinIfChannelType, TYPEDEF, LINIF_CONST) LinIf_SystemToLinIfChannelPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  LinIfPCRootValueTypes  LinIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in LinIf_PCConfig */
typedef struct sLinIf_PCConfigType
{
  uint8 LinIf_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} LinIf_PCConfigType;

typedef LinIf_PCConfigType LinIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
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
extern CONST(LinIf_ChannelConfigType, LINIF_CONST) LinIf_ChannelConfig[1];
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
extern CONST(LinIf_ChannelIndTableType, LINIF_CONST) LinIf_ChannelIndTable[1];
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
extern CONST(LinIf_ChannelToDrvWakeupInfoType, LINIF_CONST) LinIf_ChannelToDrvWakeupInfo[1];
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
extern CONST(LinIf_EntryType, LINIF_CONST) LinIf_Entry[6];
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
extern CONST(LinIf_FrameLengthDelayListType, LINIF_CONST) LinIf_FrameLengthDelayList[8];
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
extern CONST(LinIf_FrameListType, LINIF_CONST) LinIf_FrameList[6];
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
extern CONST(LinIf_LinIfToLinTrcvChannelType, LINIF_CONST) LinIf_LinIfToLinTrcvChannel[1];
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
extern CONST(LinIf_LinIfToLinTrcvNrType, LINIF_CONST) LinIf_LinIfToLinTrcvNr[1];
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
extern CONST(LinIf_LinTrcv_CheckWakeupFctType, LINIF_CONST) LinIf_LinTrcv_CheckWakeupFct[1];
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
extern CONST(LinIf_LinTrcv_GetBusWuReasonFctType, LINIF_CONST) LinIf_LinTrcv_GetBusWuReasonFct[1];
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
extern CONST(LinIf_LinTrcv_GetOpModeFctType, LINIF_CONST) LinIf_LinTrcv_GetOpModeFct[1];
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
extern CONST(LinIf_LinTrcv_SetOpModeFctType, LINIF_CONST) LinIf_LinTrcv_SetOpModeFct[1];
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
extern CONST(LinIf_LinTrcv_SetWakeupModeFctType, LINIF_CONST) LinIf_LinTrcv_SetWakeupModeFct[1];
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
extern CONST(LinIf_MasterChannelConfigType, LINIF_CONST) LinIf_MasterChannelConfig[1];
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
extern CONST(LinIf_ScheduleTableListType, LINIF_CONST) LinIf_ScheduleTableList[3];
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
extern CONST(LinIf_ScheduleTableListIndType, LINIF_CONST) LinIf_ScheduleTableListInd[3];
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
extern CONST(LinIf_SystemToLinIfChannelType, LINIF_CONST) LinIf_SystemToLinIfChannel[2];
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
extern VAR(LinIf_ChannelDataUType, LINIF_VAR_NOINIT) LinIf_ChannelData;  /* PRQA S 0759 */  /* MD_CSL_Union */  /* Data structure per LinIf channel */
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
extern VAR(LinIf_MasterChannelDataUType, LINIF_VAR_NOINIT) LinIf_MasterChannelData;  /* PRQA S 0759 */  /* MD_CSL_Union */  /* Data structure per LinIf Master channel */
#define LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/







#endif


