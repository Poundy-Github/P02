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
 *            Module: Dcm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.c
 *   Generation Time: 2022-01-27 14:24:30
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DcmDsdSubServiceSessionLevelRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/SecurityAccess/EOLrequestSeed_Key_Send[1:DcmDsdSubServiceSessionLevelRef](value={empty}) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceSessionLevelRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DcmDsdSubServiceSessionLevelRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/SecurityAccess/EOLrequestSeed_Request[1:DcmDsdSubServiceSessionLevelRef](value={empty}) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceSessionLevelRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DcmDspDidWriteSessionRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DidInfo_VehicleModel/DcmDspDidAccess/DcmDspDidWrite[0:DcmDspDidWriteSessionRef](value={empty}) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDidInfo/DcmDspDidAccess/DcmDspDidWrite/DcmDspDidWriteSessionRef)
 *********************************************************************************************************************/


#define DCM_LCFG_SOURCE
/* ----------------------------------------------
 ~&&&   Includes
---------------------------------------------- */
                                                                                                                                                     /* PRQA S 1533 EOF */ /* MD_Dcm_ObjectOnlyAccessedOnce */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Det.h"
#include "Dcm_Int.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif
/* ----------------------------------------------
 ~&&&   Module internal function declarations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_ModeRuleDefaultModeRule()
***********************************************************************************************************************/
/*! \brief         Evaluates a specific mode rule
 *  \details       Evaluates a specific mode rule consisting of one or multiple mode conditions and/or other mode rules.
 *  \param[in]     nrc    Negative response code
 *  \return        TRUE   The condition is fulfilled
 *  \return        FALSE  The condition is not fulfilled
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDefaultModeRule(Dcm_Ptr2LocalU8Type nrc);
/***********************************************************************************************************************
 *  Dcm_ModeRuleDcmModeRule()
***********************************************************************************************************************/
/*! \brief         Evaluates a specific mode rule
 *  \details       Evaluates a specific mode rule consisting of one or multiple mode conditions and/or other mode rules.
 *  \param[in]     nrc    Negative response code
 *  \return        TRUE   The condition is fulfilled
 *  \return        FALSE  The condition is not fulfilled
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDcmModeRule(Dcm_Ptr2LocalU8Type nrc);
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_Mode_DcmUserConditionMode()
***********************************************************************************************************************/
/*! \brief         Reads the currently active mode of a specific mode declaration group.
 *  \details       -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Rte_ModeType_DcmUserConditionMode, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_Mode_DcmUserConditionMode(void);
#define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Call-back function declarations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_RidMgr_0400_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0400_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_A1A1_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_A1A1_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_A1A2_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_A1A2_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_F035_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F035_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_F036_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F036_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_RidMgr_F037_Start()
***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F037_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status);
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in]     pContext      Pointer to the context
 *  \param[in]     opStatus      The operation status
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        DCM_E_NOT_OK  Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode);
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(Dcm_ContextPtrType pContext, Dcm_DiagDataContextPtrType pDataContext);
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Uninitialized RAM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[4095];
#define DCM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 8-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[2]=
{
    0u
  , 1u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll[2]=
{
   1u
  , 0u
};
/*! Look up table of all supported ALFIDs */
CONST(uint8, DCM_CONST) Dcm_CfgMemMgrAlfidLookUpTable[3]=
{
   2u
  ,0x14u
  ,0x24u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[13]=
{
   12u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x23u
  ,0x27u
  ,0x28u
  ,0x2Eu
  ,0x31u
  ,0x3Eu
  ,0x85u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[5]=
{
   4u
  ,0x01u
  ,0x03u
  ,0x60u
  ,0x6Fu
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x03u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[6]=
{
   5u
  ,0x01u
  ,0x02u
  ,0x04u
  ,0x06u
  ,0x0Au
};
/*! Service 0x27 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[5]=
{
   4u
  ,0x01u
  ,0x02u
  ,0x61u
  ,0x62u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[3]=
{
   2u
  ,0x00u
  ,0x03u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[3]=
{
   2u
  ,0x00u
  ,0x0Fu
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
#define DCM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM 16-Bit
---------------------------------------------- */
#define DCM_START_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[5]=
{
   4u
  ,0xB000u
  ,0xF112u
  ,0xF113u
  ,0xF400u
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[22]=
{
   21u
  ,0x0400u
  ,0x0401u
  ,0x0402u
  ,0x0403u
  ,0xA1A1u
  ,0xA1A2u
  ,0xA1A3u
  ,0xCE01u
  ,0xF020u
  ,0xF021u
  ,0xF022u
  ,0xF023u
  ,0xF030u
  ,0xF031u
  ,0xF033u
  ,0xF035u
  ,0xF036u
  ,0xF037u
  ,0xF038u
  ,0xFD20u
  ,0xFD21u
};
#define DCM_STOP_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   ROM of unspecified size
---------------------------------------------- */
#define DCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,4095u}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[4]=
{
   { TRUE, 0u}
  ,{ FALSE, 0u}
  ,{ TRUE, 1u}
  ,{ FALSE, 1u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[2]=
{
   { 0x00E1u,PduRConf_PduRSrcPdu_PduRSrcPdu_ccf5ed2e, 0u,0u,0x00u, 0u}
  ,{ 0x00E1u,PduRConf_PduRSrcPdu_PduRSrcPdu_c66043fb, 0u,0u,0x00u, 0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1]=
{
   { {        1u,       1u},4095u, 3u,TRUE,0u,DemConf_DemClient_DemClient, 0u}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[1]=
{
   ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[2]=
{
   1u
  ,ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b
};
/*! Precondition mode rules */
CONST(Dcm_ModeRuleFuncType, DCM_CONST) Dcm_CfgModeMgrRules[2]=
{
   Dcm_ModeRuleDefaultModeRule
  ,Dcm_ModeRuleDcmModeRule
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[17]=
{
   {    0u,{ 0x0Fu,0x07u}}
  ,{    0u,{ 0x03u,0x07u}}
  ,{    0u,{ 0x07u,0x07u}}
  ,{    0u,{ 0x09u,0x07u}}
  ,{    1u,{ 0x0Fu,0x07u}}
  ,{    1u,{ 0x07u,0x07u}}
  ,{    0u,{ 0x02u,0x02u}}
  ,{    0u,{ 0x06u,0x07u}}
  ,{    0u,{ 0x02u,0x07u}}
  ,{    0u,{ 0x04u,0x07u}}
  ,{    1u,{ 0x02u,0x07u}}
  ,{    0u,{ 0x0Au,0x07u}}
  ,{    1u,{ 0x0Au,0x07u}}
  ,{    0u,{ 0x04u,0x04u}}
  ,{    0u,{ 0x06u,0x04u}}
  ,{    0u,{ 0x06u,0x02u}}
  ,{    0u,{ 0x06u,0x06u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[4]=
{
   { {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
  ,{ {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_EOLDiagnosticSession,0x60u}
  ,{ {        5u,     500u},RTE_MODE_DcmDiagnosticSessionControl_UFSKeepProgrammingSession,0x6Fu}
};
/*! Security Access state properties */
CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[2]=
{
   { 1000u,   0u,FALSE, 3u,0x01u} /* SecLvl: UnlockedL1 */
  ,{ 2000u,   0u,FALSE, 2u,0x31u} /* SecLvl: Level_EOL_Unlocked */
};
/*! DID ranges look up */
CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[4]=
{
   {    3u,   3u}
  ,{ 0xB000u,0xBFFFu}
  ,{ 0xF113u,0xF1FFu}
  ,{ 0xF400u,0xFFFFu}
};
/*! DID ranges to DID info map */
CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[3]=
{
      0u
  ,   2u
  ,   3u
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[4]=
{
   {    0u,4000u,4000u,   0u,0x23u} /* DID: 0xB000 */
  ,{   20u,  20u,  20u,   2u,0x03u} /* DID: 0xF112 */
  ,{    0u,4000u,4000u,   4u,0x23u} /* DID: 0xF113 */
  ,{    0u, 300u, 300u,   6u,0x23u} /* DID: 0xF400 */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[8]=
{
   {    2u,   0u,0x11u} /* DID: 0xB000 */
  ,{    7u,   2u,0x11u} /* DID: 0xB000 */
  ,{    1u,   4u,0x05u} /* DID: 0xF112 */
  ,{    6u,   6u,0x01u} /* DID: 0xF112 */
  ,{    2u,   7u,0x11u} /* DID: 0xF113 */
  ,{    7u,   9u,0x11u} /* DID: 0xF113 */
  ,{    2u,  11u,0x11u} /* DID: 0xF400 */
  ,{    7u,  13u,0x11u} /* DID: 0xF400 */
};
/*! DID operation classes */
CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[16]=
{
   {  0u}
  ,{  1u}
  ,{  2u}
  ,{  3u}
  ,{  4u}
  ,{  5u}
  ,{  6u}
  ,{  7u}
  ,{  8u}
  ,{  9u}
  ,{ 10u}
  ,{ 11u}
  ,{ 12u}
  ,{ 13u}
  ,{ 14u}
  ,{ 15u}
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[15]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeEol1_ReadDidData)),   0u,4000u,0x0000u} /* DID: 0xB000 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeEol1_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xB000 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeEol1_WriteDidData)),   0u,4000u,0x1000u} /* DID: 0xB000 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeEol1_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xB000 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VehicleModel_VehicleModel_ReadData)),  20u,  20u,0x0002u} /* DID: 0xF112 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VehicleModel_VehicleModel_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF112 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VehicleModel_VehicleModel_WriteData)),  20u,  20u,0x1002u} /* DID: 0xF112 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag1_ReadDidData)),   0u,4000u,0x0000u} /* DID: 0xF113 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag1_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xF113 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag1_WriteDidData)),   0u,4000u,0x1000u} /* DID: 0xF113 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag1_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xF113 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag2_ReadDidData)),   0u, 300u,0x0000u} /* DID: 0xF400 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag2_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xF400 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag2_WriteDidData)),   0u, 300u,0x1000u} /* DID: 0xF400 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DIDRange_DidRangeDiag2_IsDidAvailable)),   0u,   0u,0x5400u} /* DID: 0xF400 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[21]=
{
   {    0u,  13u,0x05u, 0u} /* RID: 0x0400 */
  ,{    2u,  14u,0x05u, 0u} /* RID: 0x0401 */
  ,{    4u,  14u,0x05u, 0u} /* RID: 0x0402 */
  ,{    6u,  13u,0x05u, 0u} /* RID: 0x0403 */
  ,{    8u,   6u,0x01u, 0u} /* RID: 0xA1A1 */
  ,{    9u,   6u,0x01u, 0u} /* RID: 0xA1A2 */
  ,{   10u,   6u,0x01u, 0u} /* RID: 0xA1A3 */
  ,{   11u,   6u,0x05u, 0u} /* RID: 0xCE01 */
  ,{   13u,   6u,0x05u, 0u} /* RID: 0xF020 */
  ,{   15u,   6u,0x05u, 0u} /* RID: 0xF021 */
  ,{   17u,   6u,0x05u, 0u} /* RID: 0xF022 */
  ,{   19u,   6u,0x05u, 0u} /* RID: 0xF023 */
  ,{   21u,  15u,0x05u, 0u} /* RID: 0xF030 */
  ,{   23u,  15u,0x05u, 0u} /* RID: 0xF031 */
  ,{   25u,  15u,0x07u, 0u} /* RID: 0xF033 */
  ,{   28u,  15u,0x05u, 0u} /* RID: 0xF035 */
  ,{   30u,  15u,0x05u, 0u} /* RID: 0xF036 */
  ,{   32u,  15u,0x05u, 0u} /* RID: 0xF037 */
  ,{   34u,  15u,0x05u, 0u} /* RID: 0xF038 */
  ,{   36u,  16u,0x01u, 0u} /* RID: 0xFD20 */
  ,{   37u,   6u,0x05u, 0u} /* RID: 0xFD21 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[39]=
{
   { ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0400_Start)),   4u,   4u,   0u,   0u, 9u} /* RID: 0x0400 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_CheckEthernetIPPINGFunction_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0x0400 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_IVITouchTest_Start)),   0u,   0u,   1u,   1u, 3u} /* RID: 0x0401 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_IVITouchTest_RequestResults)),   0u,   0u,  20u,  20u, 3u} /* RID: 0x0401 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMRegister_Start)),   0u,   0u,   1u,   1u, 3u} /* RID: 0x0402 */                             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMRegister_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0x0402 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AMPCalibration_Start)),   0u,   0u,   1u,   1u, 3u} /* RID: 0x0403 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AMPCalibration_RequestResults)),   0u,   0u,  10u,  10u, 3u} /* RID: 0x0403 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_A1A1_Start)),   2u,   2u,   0u,   0u, 9u} /* RID: 0xA1A1 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_A1A2_Start)),   1u,   1u,   1u,   1u, 9u} /* RID: 0xA1A2 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ResetSwitchStatistics_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xA1A3 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_RequestCertificateStatus_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xCE01 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_RequestCertificateStatus_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xCE01 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureFrontCamerParameters_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF020 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureFrontCamerParameters_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF020 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureRearCamerParameters_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF021 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureRearCamerParameters_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF021 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureLeftCamerParameters_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF022 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureLeftCamerParameters_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF022 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureRightCamerParameters_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF023 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ConfigureRightCamerParameters_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF023 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMEnvironmentCheck_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF030 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMEnvironmentCheck_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF030 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMAutoCalibration_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF031 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMAutoCalibration_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF031 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualCalibration_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF033 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualCalibration_Stop)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF033 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualCalibration_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF033 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F035_Start)),   1u,   1u,   0u,   0u, 9u} /* RID: 0xF035 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualViewSelect_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF035 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F036_Start)),   1u,   1u,   0u,   0u, 9u} /* RID: 0xF036 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualConerSelect_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF036 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F037_Start)),   1u,   1u,   0u,   0u, 9u} /* RID: 0xF037 */                                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualConerMove_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF037 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualCorrectValue_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xF038 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_AVMManualCorrectValue_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xF038 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_SystemRecovery_Start)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xFD20 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ODOReset_Start)),   0u,   0u,   0u,   0u, 0u} /* RID: 0xFD21 */                                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_ODOReset_RequestResults)),   0u,   0u,   1u,   1u, 3u} /* RID: 0xFD21 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Properties of the MIDs */
CONST(Dcm_CfgMemMgrMemIdInfoType, DCM_CONST) Dcm_CfgMemMgrMidInfo[1]=
{
   { Dcm_CfgMemMgrMemMap,   2u}
};
/*! Properties of the memory map of a specific MID */
CONST(Dcm_CfgMemMgrMemMapInfoType, DCM_CONST) Dcm_CfgMemMgrMemMap[2]=
{
   { {    1u},0xFEBC0000UL,0xFEBFFFFFUL}
  ,{ {    1u},0xFEF00000UL,0xFEF0FFFFUL}
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[2]=
{
   Dcm_Service27Init
  ,NULL_PTR /* end marker */
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[13]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 0u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   0u,   0u, 0u, 0u} /* SID: 0x22 */
  ,{ Dcm_Service23Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x23 */
  ,{ Dcm_Service27Processor,0x03u, 1u,   6u,   0u, 0u, 0u} /* SID: 0x27 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   7u,   0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x2E */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x31 */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,   8u,   0u, 0u, 0u} /* SID: 0x85 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[12]=
{
      0u /* SID: 0x10 */
  ,   0u /* SID: 0x11 */
  ,   5u /* SID: 0x14 */
  ,   2u /* SID: 0x19 */
  ,   2u /* SID: 0x22 */
  ,   6u /* SID: 0x23 */
  ,   7u /* SID: 0x27 */
  ,   7u /* SID: 0x28 */
  ,   7u /* SID: 0x2E */
  ,   7u /* SID: 0x31 */
  ,   2u /* SID: 0x3E */
  ,  11u /* SID: 0x85 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[9]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service27PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[1]=
{
   Dcm_ServiceNoCancel
};
/*! OEM notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagOemNotificationInfo[2]=
{
   { Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestGWMNotification_Indication,Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestGWMNotification_Confirmation}
  ,{ NULL_PTR,NULL_PTR}
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[4]=
{
   { { 50u, 500u}} /* Session ID: 0x01 */
  ,{ { 50u, 500u}} /* Session ID: 0x03 */
  ,{ { 50u, 500u}} /* Session ID: 0x60 */
  ,{ { 50u, 500u}} /* Session ID: 0x6F */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[4]=
{
      0u /* Session ID: 0x01 */
  ,   1u /* Session ID: 0x03 */
  ,   2u /* Session ID: 0x60 */
  ,   3u /* Session ID: 0x6F */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[2]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
  ,{ Dcm_Service11_03Processor} /* SF: 0x03 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[2]=
{
      4u /* SF: 0x01 */
  ,   4u /* SF: 0x03 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[5]=
{
   { Dcm_Service19_01Processor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
  ,{ Dcm_Service19_0AProcessor, 1u} /* SF: 0x0A */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[5]=
{
      2u /* SF: 0x01 */
  ,   2u /* SF: 0x02 */
  ,   2u /* SF: 0x04 */
  ,   2u /* SF: 0x06 */
  ,   2u /* SF: 0x0A */
};
/*! Service 0x27 sub-service properties table  */
CONST(Dcm_CfgSvc27SubFuncInfoType, DCM_CONST) Dcm_CfgSvc27SubFuncInfo[4]=
{
   {    1u} /* SF: 0x01 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{    5u} /* SF: 0x02 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{    1u} /* SF: 0x61 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{    9u} /* SF: 0x62 */                                                                                                                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Service 0x27 security level properties table  */
CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[2]=
{
   { ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_UnlockedL1_GetSeed)),Rte_Call_SecurityAccess_UnlockedL1_CompareKey,Rte_Call_SecurityAccess_UnlockedL1_GetSecurityAttemptCounter,Rte_Call_SecurityAccess_UnlockedL1_SetSecurityAttemptCounter,   4u, 0u} /* SecLvl: UnlockedL1 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_Level_EOL_Unlocked_GetSeed)),Rte_Call_SecurityAccess_Level_EOL_Unlocked_CompareKey,Rte_Call_SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter,Rte_Call_SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter,   4u, 0u} /* SecLvl: Level_EOL_Unlocked */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Indirection from service 0x27 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[4]=
{
      8u /* SF: 0x01 */
  ,   8u /* SF: 0x02 */
  ,   9u /* SF: 0x61 */
  ,   9u /* SF: 0x62 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[2]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x03 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[2]=
{
     10u /* SF: 0x00 */
  ,  10u /* SF: 0x03 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[2]=
{
   DCM_SVC_28_NETWORK_ALL
  ,DCM_SVC_28_NETWORK_CURRENT
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
     12u /* SF: 0x01 */
  ,  12u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module internal function implementations
---------------------------------------------- */
#define DCM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_ModeRuleDefaultModeRule()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeRule<XXX>() */
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDefaultModeRule(Dcm_Ptr2LocalU8Type nrc)                                                               /* PRQA S 3673, 2889 */ /* MD_Dcm_APIStd_3673, MD_Dcm_Optimize_2889 */
{
  DCM_IGNORE_UNREF_PARAM(nrc);                                                                                                                       /* PRQA S 3112 */ /* MD_Dcm_3112 */
  return TRUE;
}
/***********************************************************************************************************************
 *  Dcm_ModeRuleDcmModeRule()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeRule<XXX>() */
DCM_LOCAL FUNC(boolean, DCM_CODE) Dcm_ModeRuleDcmModeRule(Dcm_Ptr2LocalU8Type nrc)                                                                   /* PRQA S 2889 */ /* MD_Dcm_Optimize_2889 */
{
  if (Dcm_ModeCondGet_Dcm_Read_Mode_DcmUserConditionMode() != RTE_MODE_DcmUserConditionMode_DCM_USER_CONDITION_OK)
  {
    *nrc = ((uint8)(0x22u));                                                                                                                         /* SBSW_DCM_GEN_PARAM_PTR_WRITE */
    return FALSE;
  }
  return TRUE;
}
/***********************************************************************************************************************
 *  Dcm_ModeCondGet_Dcm_Read_Mode_DcmUserConditionMode()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeCondGet_<XXX>() */
DCM_LOCAL FUNC(Rte_ModeType_DcmUserConditionMode, DCM_CODE) Dcm_ModeCondGet_Dcm_Read_Mode_DcmUserConditionMode(void)
{
  Rte_ModeType_DcmUserConditionMode result;
  Rte_ModeType_DcmUserConditionMode prev;
  Rte_ModeType_DcmUserConditionMode next;
  result = Rte_Mode_Dcm_Read_Mode_Dcm_Read_Mode(&prev, &next);                                                                                       /* SBSW_DCM_GEN_POINTER_FORWARD_STACK */
  return ((Rte_ModeType_DcmUserConditionMode)((RTE_TRANSITION_DcmUserConditionMode == result)?next:result));
}
#define DCM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ----------------------------------------------
 ~&&&   Module call-out implementations
---------------------------------------------- */
#define DCM_START_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Dcm_RidMgr_0400_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0400_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint32 dataInIn_Start;

  dataInIn_Start = ((uint32)(Dcm_UtiMake32Bit(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u), Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 1u), Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 2u), Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 3u)))) /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_CheckEthernetIPPINGFunction_Start(dataInIn_Start
                                                                   , OpStatus
                                                                   , ErrorCode
                                                                   );                                                                                /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_A1A1_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_A1A1_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_PortNumber;
  uint8 dataInIn_TestMode;

  dataInIn_PortNumber = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)))                                                                        /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;
  dataInIn_TestMode = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 1u)));

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_PhyTestMode_Start(dataInIn_PortNumber
                                                   , dataInIn_TestMode
                                                   , OpStatus
                                                   , ErrorCode
                                                   );                                                                                                /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_A1A2_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_A1A2_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_CableDiagnosticsControl;

  dataInIn_CableDiagnosticsControl = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)))                                                           /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_CableDiagnostics_Start(dataInIn_CableDiagnosticsControl
                                                        , OpStatus
                                                        , Dcm_DiagGetResDataRel(pMsgContext, 0u)                                                     /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */ /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                                                        , ErrorCode
                                                        );                                                                                           /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F035_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F035_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_AVMManualViewSelect;

  dataInIn_AVMManualViewSelect = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)))                                                               /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_AVMManualViewSelect_Start(dataInIn_AVMManualViewSelect
                                                           , OpStatus
                                                           , ErrorCode
                                                           );                                                                                        /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F036_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F036_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_AVMManualConerSelect;

  dataInIn_AVMManualConerSelect = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)))                                                              /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_AVMManualConerSelect_Start(dataInIn_AVMManualConerSelect
                                                            , OpStatus
                                                            , ErrorCode
                                                            );                                                                                       /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F037_Start()
***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F037_Start(Dcm_OpStatusType OpStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_RidMgrRidLengthPtrType DataLength, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  uint8 dataInIn_AVMManualConerMove;

  dataInIn_AVMManualConerMove = ((uint8)(Dcm_DiagGetReqDataAsU8Rel(pMsgContext, 0u)))                                                                /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */;

  DCM_IGNORE_UNREF_PARAM(DataLength);                                                                                                                /* PRQA S 3112 */ /* MD_Dcm_3112 */

  return Rte_Call_RoutineServices_AVMManualConerMove_Start(dataInIn_AVMManualConerMove
                                                          , OpStatus
                                                          , ErrorCode
                                                          );                                                                                         /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(Dcm_ContextPtrType pContext, Dcm_ConfirmationStatusType status)                    /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  DCM_IGNORE_UNREF_PARAM(pContext);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(status);                                                                                                                    /* PRQA S 3112 */ /* MD_Dcm_3112 */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(Dcm_ContextPtrType pContext, Dcm_OpStatusType opStatus, Dcm_DiagDataContextPtrType pDataContext, Dcm_NegativeResponseCodePtrType ErrorCode) /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
{
  DCM_IGNORE_UNREF_PARAM(pContext);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(opStatus);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(pDataContext);                                                                                                              /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);                                                                                                                 /* PRQA S 3112 */ /* MD_Dcm_3112 */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(Dcm_ContextPtrType pContext, Dcm_DiagDataContextPtrType pDataContext)                     /* PRQA S 3673 */ /* MD_Dcm_Design_3673 */
{
  DCM_IGNORE_UNREF_PARAM(pContext);                                                                                                                  /* PRQA S 3112 */ /* MD_Dcm_3112 */
  DCM_IGNORE_UNREF_PARAM(pDataContext);                                                                                                              /* PRQA S 3112 */ /* MD_Dcm_3112 */
  /* nothing to do */
}
#define DCM_STOP_SEC_CALLOUT_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"                                                                                                                                  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*lint -restore */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Lcfg.c
 * ******************************************************************************************************************** */

