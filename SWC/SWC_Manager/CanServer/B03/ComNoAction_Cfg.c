/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      ComNoAction_Cfg.c
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Std_Types.h"
#include "ComNoAction.h"

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern FUNC(Std_ReturnType, Can_Server_CODE) CNA_SignalSet(uint16 signalId, P2VAR(uint32, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) value);

static const CNA_SignalConfigType cna_signalConfigs[238] =
{
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AUTODefrost_TC_oHUT6_oB30_for_SC_CAN_V3_2_10a25c04_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 0, 0, 0, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_AUTODefrost_VR_oHUT6_oB30_for_SC_CAN_V3_2_cc47c281_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 0, 1, 1, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_AutoAVMSwSet_Cmd_oHUT6_oB30_for_SC_CAN_V3_2_aa62e966_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 1, 1, 2, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_AutoViewChgCmd_oHUT6_oB30_for_SC_CAN_V3_2_3bf103cb_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 2, 1, 3, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_CarMdlDispCmd_oHUT6_oB30_for_SC_CAN_V3_2_7e3ab603_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 3, 1, 4, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_CarMdlTrsprcySwtCmd_oHUT6_oB30_for_SC_CAN_V3_2_2db2d455_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 4, 1, 5, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_FPAS_AutoModSwt_oHUT6_oB30_for_SC_CAN_V3_2_53012f15_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 5, 1, 6, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_Guid_Ovl_Display_Cmd_oHUT6_oB30_for_SC_CAN_V3_2_9e1ad881_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 6, 1, 7, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_LaneCalActvtCmd_oHUT6_oB30_for_SC_CAN_V3_2_b261ae1a_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 7, 1, 8, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_MEBSwtSet_oHUT6_oB30_for_SC_CAN_V3_2_53853242_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 8, 1, 9, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_MODChgReq_oHUT6_oB30_for_SC_CAN_V3_2_5fc749ba_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 9, 1, 10, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_MdlColrChgCmd_oHUT6_oB30_for_SC_CAN_V3_2_36604d95_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 10, 1, 11, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_Radar_DispCmd_oHUT6_oB30_for_SC_CAN_V3_2_0e2af1c6_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 11, 1, 12, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_Sgl_View_Sel_oHUT6_oB30_for_SC_CAN_V3_2_00df326a_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 12, 1, 13, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_SwToFieldCalRstCmd_oHUT6_oB30_for_SC_CAN_V3_2_62085c8c_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 13, 1, 14, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_View_SoftswitchCmd_oHUT6_oB30_for_SC_CAN_V3_2_7883440c_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 14, 1, 15, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_WshSoftSwt_oHUT6_oB30_for_SC_CAN_V3_2_2a23ac90_Tx, ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx, 15, 1, 16, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_BackReq_AVM_oHUT30_oB30_for_SC_CAN_V3_2_c8020bf6_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 16, 1, 17, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_CancelVoiceIdn_oHUT30_oB30_for_SC_CAN_V3_2_b1d43d5f_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 18, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DeleteUserIDFaceData_oHUT30_oB30_for_SC_CAN_V3_2_6904ce75_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 19, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DeleteUserIDVoiceData_oHUT30_oB30_for_SC_CAN_V3_2_43b46199_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 20, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DistrctnDetnSet_oHUT30_oB30_for_SC_CAN_V3_2_9454ba53_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 21, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DrowsnsDetnSet_oHUT30_oB30_for_SC_CAN_V3_2_7245b280_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 22, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_EnrollFaceReq_oHUT30_oB30_for_SC_CAN_V3_2_ed567aa2_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 23, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_EnrollUserIDResult_oHUT30_oB30_for_SC_CAN_V3_2_e2141df6_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 24, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_EraseAllFaceUsersReq_oHUT30_oB30_for_SC_CAN_V3_2_8f7b7e0d_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 25, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_EraseAllVoiceUsersReq_oHUT30_oB30_for_SC_CAN_V3_2_6fd2f3d2_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 26, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ExprsnSetUp_oHUT30_oB30_for_SC_CAN_V3_2_205af662_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 27, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_FaceIdnSet_oHUT30_oB30_for_SC_CAN_V3_2_9bf7ccdd_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 0, 28, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_HUD_BrightnessLvlSwt_oHUT30_oB30_for_SC_CAN_V3_2_2d5452ca_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 17, 1, 29, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_HUD_HeightLvlSwt_oHUT30_oB30_for_SC_CAN_V3_2_eacdafaa_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 18, 1, 30, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_HUD_SwtReq_oHUT30_oB30_for_SC_CAN_V3_2_891fa271_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 19, 1, 31, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_IdnResultReq_HUT_oHUT30_oB30_for_SC_CAN_V3_2_a17068c8_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 20, 0, 32, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_VoiceIdnSet_oHUT30_oB30_for_SC_CAN_V3_2_ec93cd03_Tx, ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx, 20, 0, 33, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DrvBehvTestSetUp_oHUT39_oB30_for_SC_CAN_V3_2_9288743b_Tx, ComConf_ComIPdu_HUT39_oB30_for_SC_CAN_V3_2_dc19868c_Tx, 20, 0, 34, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_DrvSeatMassgLvlSet_oHUT39_oB30_for_SC_CAN_V3_2_6ba19748_Tx, ComConf_ComIPdu_HUT39_oB30_for_SC_CAN_V3_2_dc19868c_Tx, 20, 1, 35, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_DrvSeatMassgModSet_oHUT39_oB30_for_SC_CAN_V3_2_2febe0b2_Tx, ComConf_ComIPdu_HUT39_oB30_for_SC_CAN_V3_2_dc19868c_Tx, 21, 1, 36, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_GazeAreaIntracSetUp_oHUT39_oB30_for_SC_CAN_V3_2_f0ca0793_Tx, ComConf_ComIPdu_HUT39_oB30_for_SC_CAN_V3_2_dc19868c_Tx, 22, 0, 37, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_ApproachLampSet_oHUT33_oB30_for_SC_CAN_V3_2_96286dcd_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 22, 1, 38, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_BackReq_APS_oHUT33_oB30_for_SC_CAN_V3_2_c14d74b8_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 23, 1, 39, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_ChairMemPosnSetSwt_oHUT33_oB30_for_SC_CAN_V3_2_7a3bbfcf_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 24, 1, 40, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_DeletePath1Cmd_oHUT33_oB30_for_SC_CAN_V3_2_59f0a8d3_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 25, 1, 41, 1},
    {6, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DeletePath2Cmd_oHUT33_oB30_for_SC_CAN_V3_2_90efa06c_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 26, 0, 42, 1},
    {6, CNA_BEHAVIOR_SEND, ComConf_ComSignal_DrvWinSwtReq_VR_oHUT33_oB30_for_SC_CAN_V3_2_3368a5e3_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 26, 1, 43, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_FlaoutUnlockSet_oHUT33_oB30_for_SC_CAN_V3_2_71fc343d_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 27, 1, 44, 1},
    {6, CNA_BEHAVIOR_NONE, ComConf_ComSignal_MbrMonrEnReq_TC_oHUT33_oB30_for_SC_CAN_V3_2_4280a917_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 28, 0, 45, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_ParkMdlCmd_oHUT33_oB30_for_SC_CAN_V3_2_0442a858_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 28, 1, 46, 1},
    {6, CNA_BEHAVIOR_SEND, ComConf_ComSignal_PassWinSwtReq_VR_oHUT33_oB30_for_SC_CAN_V3_2_aa7a1077_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 29, 1, 47, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_PathLrngFinshCmd_oHUT33_oB30_for_SC_CAN_V3_2_38f3a81d_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 30, 1, 48, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_PathLrngStartCmd_oHUT33_oB30_for_SC_CAN_V3_2_0ff00f70_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 31, 1, 49, 1},
    {6, CNA_BEHAVIOR_NONE, ComConf_ComSignal_PrkInDirChoice_oHUT33_oB30_for_SC_CAN_V3_2_da644327_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 32, 0, 50, 1},
    {6, CNA_BEHAVIOR_SEND, ComConf_ComSignal_RLWinSwtReq_VR_oHUT33_oB30_for_SC_CAN_V3_2_530003f0_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 32, 1, 51, 1},
    {6, CNA_BEHAVIOR_SEND, ComConf_ComSignal_RRWinSwtReq_VR_oHUT33_oB30_for_SC_CAN_V3_2_396bcee1_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 33, 1, 52, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_SelPrkOutDirReq_oHUT33_oB30_for_SC_CAN_V3_2_b9cf5012_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 34, 1, 53, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_SelPrkgFctnCmd_oHUT33_oB30_for_SC_CAN_V3_2_2ce4a858_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 35, 1, 54, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_StartPrkgPath1Cmd_oHUT33_oB30_for_SC_CAN_V3_2_a9052ab9_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 36, 1, 55, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_StartPrkgPath2Cmd_oHUT33_oB30_for_SC_CAN_V3_2_601a2206_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 37, 1, 56, 1},
    {6, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_SuperLockSet_oHUT33_oB30_for_SC_CAN_V3_2_20162f69_Tx, ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx, 38, 1, 57, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ABSLmpSet_oHUT15_oB30_for_SC_CAN_V3_2_0c59b153_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 39, 0, 58, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACDrvSetTempSteplsReq_TC_oHUT15_oB30_for_SC_CAN_V3_2_c666692e_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 39, 1, 59, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACEAHReq_TC_oHUT15_oB30_for_SC_CAN_V3_2_1fa9b056_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 40, 0, 60, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACEAHReq_VR_oHUT15_oB30_for_SC_CAN_V3_2_82a72267_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 40, 0, 61, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACOperMod_TC_oHUT15_oB30_for_SC_CAN_V3_2_08e3b9bc_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 40, 0, 62, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACOperMod_VR_oHUT15_oB30_for_SC_CAN_V3_2_95ed2b8d_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 40, 1, 63, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACPassSetTempSteplsReq_TC_oHUT15_oB30_for_SC_CAN_V3_2_2bdb7c37_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 41, 1, 64, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_APSPrkgTypSeln_oHUT15_oB30_for_SC_CAN_V3_2_1c75d944_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 42, 1, 65, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_APSSwtReq_VR_oHUT15_oB30_for_SC_CAN_V3_2_d7efad08_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 43, 1, 66, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AutoWshWipSet_oHUT15_oB30_for_SC_CAN_V3_2_e27e87b2_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 44, 0, 67, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DoorUnlockModSet_oHUT15_oB30_for_SC_CAN_V3_2_0e9052dc_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 44, 0, 68, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_PASExitSpdSwt_oHUT15_oB30_for_SC_CAN_V3_2_e0648c92_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 44, 1, 69, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ParkLmpSet_oHUT15_oB30_for_SC_CAN_V3_2_3ab73fae_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 45, 0, 70, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_SDWSwtSet_oHUT15_oB30_for_SC_CAN_V3_2_79b5f9b8_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 45, 1, 71, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_SeekVehSet_oHUT15_oB30_for_SC_CAN_V3_2_a584c719_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 46, 0, 72, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_SpdAutoLockModSet_oHUT15_oB30_for_SC_CAN_V3_2_79ec61b9_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 46, 0, 73, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_SportModLightSet_oHUT15_oB30_for_SC_CAN_V3_2_1544ce4c_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 46, 0, 74, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_SteerWheelHeatSwtReq_oHUT15_oB30_for_SC_CAN_V3_2_16ccc744_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 46, 0, 75, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_SunRoofSwtReq_VR_oHUT15_oB30_for_SC_CAN_V3_2_5e5b1063_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 46, 1, 76, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_SunShadeSwtReq_VR_oHUT15_oB30_for_SC_CAN_V3_2_c4779eb9_Tx, ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, 47, 1, 77, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_CmplxInsct_oHUT23_oB30_for_SC_CAN_V3_2_c6f33501_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 78, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_CycCnt_oHUT23_oB30_for_SC_CAN_V3_2_4edfbd8d_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 79, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_FormOfWay_oHUT23_oB30_for_SC_CAN_V3_2_d1eb4946_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 80, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_FuncRoadClass_oHUT23_oB30_for_SC_CAN_V3_2_15183800_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 81, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_LastStub_oHUT23_oB30_for_SC_CAN_V3_2_4d5d413d_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 82, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_MsgTyp_oHUT23_oB30_for_SC_CAN_V3_2_4e528e11_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 83, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_NumOfLaneDrvDir_oHUT23_oB30_for_SC_CAN_V3_2_5b9ba80f_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 84, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_NumOfLaneOppDir_oHUT23_oB30_for_SC_CAN_V3_2_edd4e27d_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 85, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_Offset_oHUT23_oB30_for_SC_CAN_V3_2_0333b3fe_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 86, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_PartOfCalcRoute_oHUT23_oB30_for_SC_CAN_V3_2_06667b24_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 88, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_PathIdx_oHUT23_oB30_for_SC_CAN_V3_2_ea0ebeeb_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 89, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_RelProbb_oHUT23_oB30_for_SC_CAN_V3_2_8f5eea81_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 90, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_Retr_oHUT23_oB30_for_SC_CAN_V3_2_7d7a3f3e_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 91, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_RtOfWay_oHUT23_oB30_for_SC_CAN_V3_2_000e8535_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 92, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_StubPathIdx_oHUT23_oB30_for_SC_CAN_V3_2_fe9594f1_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 93, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_TurnAngl_oHUT23_oB30_for_SC_CAN_V3_2_7117e1f2_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 94, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Stub_Update_oHUT23_oB30_for_SC_CAN_V3_2_9d313cd4_Tx, ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx, 48, 0, 95, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_Brdg_oHUT22_oB30_for_SC_CAN_V3_2_a20659d9_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 96, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_BuildUpArea_oHUT22_oB30_for_SC_CAN_V3_2_5a7d902e_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 97, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_CmplxInsct_oHUT22_oB30_for_SC_CAN_V3_2_6062cc50_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 98, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_CycCnt_oHUT22_oB30_for_SC_CAN_V3_2_d7c382f4_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 99, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_DivideRoad_oHUT22_oB30_for_SC_CAN_V3_2_e81b7b63_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 100, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_EffSpdLmt_oHUT22_oB30_for_SC_CAN_V3_2_fa2af430_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 101, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_EffSpdLmtTyp_oHUT22_oB30_for_SC_CAN_V3_2_86060afc_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 102, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_FormOfWay_oHUT22_oB30_for_SC_CAN_V3_2_74b798bd_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 103, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_FuncRoadClass_oHUT22_oB30_for_SC_CAN_V3_2_88b371c9_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 104, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_MsgTyp_oHUT22_oB30_for_SC_CAN_V3_2_d74eb168_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 105, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_NumOfLaneDrvDir_oHUT22_oB30_for_SC_CAN_V3_2_d8aea170_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 106, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_NumOfLaneOppDir_oHUT22_oB30_for_SC_CAN_V3_2_6ee1eb02_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 107, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_Offset_oHUT22_oB30_for_SC_CAN_V3_2_9a2f8c87_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 108, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_PartOfCalcRoute_oHUT22_oB30_for_SC_CAN_V3_2_8553725b_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 110, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_PathIdx_oHUT22_oB30_for_SC_CAN_V3_2_4f15e558_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 111, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_RelProbb_oHUT22_oB30_for_SC_CAN_V3_2_51c89df8_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 112, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_Retr_oHUT22_oB30_for_SC_CAN_V3_2_bbdb2ae5_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 113, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_Tunnel_oHUT22_oB30_for_SC_CAN_V3_2_c899a7d6_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 114, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_Seg_Update_oHUT22_oB30_for_SC_CAN_V3_2_042d03ad_Tx, ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx, 48, 0, 115, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_AccurClass_oHUT21_oB30_for_SC_CAN_V3_2_96493a01_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 116, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_CtrlPoint_oHUT21_oB30_for_SC_CAN_V3_2_071d37ef_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 117, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_CycCnt_oHUT21_oB30_for_SC_CAN_V3_2_a6116f96_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 118, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Dist1_oHUT21_oB30_for_SC_CAN_V3_2_eba6e253_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 119, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_MsgTyp_oHUT21_oB30_for_SC_CAN_V3_2_a69c5c0a_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 121, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Offset_oHUT21_oB30_for_SC_CAN_V3_2_ebfd61e5_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 122, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_PathIdx_oHUT21_oB30_for_SC_CAN_V3_2_a345a3bc_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 124, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_ProfTyp_oHUT21_oB30_for_SC_CAN_V3_2_288b51d4_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 125, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Retr_oHUT21_oB30_for_SC_CAN_V3_2_438d5772_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 126, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Update_oHUT21_oB30_for_SC_CAN_V3_2_75ffeecf_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 127, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Value0_oHUT21_oB30_for_SC_CAN_V3_2_492943f9_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 128, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfShort_Value1_oHUT21_oB30_for_SC_CAN_V3_2_2a2e9add_Tx, ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx, 48, 0, 130, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_CtrlPoint_oHUT20_oB30_for_SC_CAN_V3_2_230b6a8f_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 132, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_CycCnt_oHUT20_oB30_for_SC_CAN_V3_2_d80b120d_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 133, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_MsgTyp_oHUT20_oB30_for_SC_CAN_V3_2_d8862191_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 134, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_Offset_oHUT20_oB30_for_SC_CAN_V3_2_95e71c7e_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 135, 2},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_PathIdx_oHUT20_oB30_for_SC_CAN_V3_2_48bd7d19_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 137, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_ProfTyp_oHUT20_oB30_for_SC_CAN_V3_2_c3738f71_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 138, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_Retr_oHUT20_oB30_for_SC_CAN_V3_2_e1d95cdb_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 139, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_Update_oHUT20_oB30_for_SC_CAN_V3_2_0be59354_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 140, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ADAS_ProfLong_Value_oHUT20_oB30_for_SC_CAN_V3_2_b5ee56a4_Tx, ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx, 48, 0, 141, 4},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACAIUReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_15669312_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 48, 1, 145, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACAQSReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_48503a13_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 49, 1, 146, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACDualReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_02255030_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 50, 1, 147, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACPassTempReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_08bb8ec4_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 51, 1, 148, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACRearDefrstReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_82bdbc16_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 52, 1, 149, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ALCMClrSet_oHUT10_oB30_for_SC_CAN_V3_2_8f43b005_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 150, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ALCMDynSwt_oHUT10_oB30_for_SC_CAN_V3_2_c3d56d8f_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 151, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ALCMRhmSwt_oHUT10_oB30_for_SC_CAN_V3_2_1b480966_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 152, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ALCMStatSwt_oHUT10_oB30_for_SC_CAN_V3_2_872ba59f_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 153, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_EgyRecvrySet_oHUT10_oB30_for_SC_CAN_V3_2_76fcde01_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 154, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_IPVolSet_oHUT10_oB30_for_SC_CAN_V3_2_fefc0c2d_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 0, 155, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_PASSwtReq_VR_oHUT10_oB30_for_SC_CAN_V3_2_bafa6fce_Tx, ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx, 53, 1, 156, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_CarWashMode_Req_oHUT25_oB30_for_SC_CAN_V3_2_b2081a77_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 54, 0, 157, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_BattKeepTemp_oHUT25_oB30_for_SC_CAN_V3_2_6cd4bd9f_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 54, 0, 158, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_HUT_BattSOCLim_oHUT25_oB30_for_SC_CAN_V3_2_5f8cae5f_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 54, 1, 159, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_ChrgnMode_oHUT25_oB30_for_SC_CAN_V3_2_ef491313_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 55, 0, 160, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_IntelBattTempMagSet_oHUT25_oB30_for_SC_CAN_V3_2_f8851bed_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 55, 0, 161, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_IntelEngIdlChrgnSet_oHUT25_oB30_for_SC_CAN_V3_2_7bca5376_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 55, 0, 162, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_HUT_RemtEngCtrl_oHUT25_oB30_for_SC_CAN_V3_2_c75958ff_Tx, ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx, 55, 0, 163, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AVMMediaVolLvlReq_oHUT17_oB30_for_SC_CAN_V3_2_fa4ca6eb_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 55, 0, 164, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AVMSwtReq_oHUT17_oB30_for_SC_CAN_V3_2_04e51676_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 55, 0, 165, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_BackgroundLightLvlSet_oHUT17_oB30_for_SC_CAN_V3_2_21f2f04f_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 55, 1, 166, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DispModSet_oHUT17_oB30_for_SC_CAN_V3_2_98eb5ea7_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 56, 0, 167, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_FPASChanSwtReq_oHUT17_oB30_for_SC_CAN_V3_2_e4b64997_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 56, 0, 168, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ManCmpSet_oHUT17_oB30_for_SC_CAN_V3_2_b04c2bd4_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 56, 0, 169, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_NaviMediaVolLvlReq_oHUT17_oB30_for_SC_CAN_V3_2_b128b86d_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 56, 0, 170, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_OPDSwtSts_oHUT17_oB30_for_SC_CAN_V3_2_24fe016a_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 56, 1, 171, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_PLGReq_VR_oHUT17_oB30_for_SC_CAN_V3_2_fc96dedf_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 57, 0, 172, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_RPASChanSwtReq_oHUT17_oB30_for_SC_CAN_V3_2_1ef53982_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 57, 0, 173, 1},
    {5, CNA_BEHAVIOR_UNSEND, ComConf_ComSignal_WPC_SwtReq_oHUT17_oB30_for_SC_CAN_V3_2_a7c8d9c6_Tx, ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx, 57, 1, 174, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_T_BOX_RemtLimitStart_oT_Box_FD6_oB30_for_SC_CAN_V3_2_2541adf9_Tx, ComConf_ComIPdu_T_Box_FD6_oB30_for_SC_CAN_V3_2_e9b81521_Tx, 58, 0, 175, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACAIUReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_b6e76dfd_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 58, 0, 176, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACAQSReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_e8556e07_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 58, 0, 177, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACAirInletReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_35be0947_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 58, 0, 178, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACAutoModReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_11ce40f6_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 58, 0, 179, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACBlwrsteplsSpdReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_3f7d23ff_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 58, 1, 180, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACCmprReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_66f595ab_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 181, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACDrvAirDistribModReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_11c4aebd_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 182, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACDrvTempDecReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_76b6bbc2_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 183, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACDrvTempIncReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_eaa019f2_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 184, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACDualReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_429a0c63_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 185, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACFrntBlwrSpdDecReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_aff5f84f_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 186, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACFrntBlwrSpdIncReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_33e35a7f_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 187, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACFrntDefrstReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_9dbab9b3_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 188, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACFrntPassTempDecReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_fa8b2748_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 189, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACFrntPassTempIncReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_669d8578_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 190, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACOffReq_TC_oHUT1_oB30_for_SC_CAN_V3_2_5a23b6b8_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 191, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_BattSaveDelayTimeSet_oHUT1_oB30_for_SC_CAN_V3_2_03e6cd1e_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 192, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ChairMemPosnEna_oHUT1_oB30_for_SC_CAN_V3_2_b60943e5_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 193, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DomeLmpDlyTimSet_oHUT1_oB30_for_SC_CAN_V3_2_f742962b_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 194, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DrvDrowsnsDetnSet_oHUT1_oB30_for_SC_CAN_V3_2_0f54a3f5_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 195, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_FolwMeHomeDlyTimSet_oHUT1_oB30_for_SC_CAN_V3_2_2fd5fa84_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 196, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_RearviewFoldModSet_oHUT1_oB30_for_SC_CAN_V3_2_c454d18c_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 197, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_TranPMode_Req_oHUT1_oB30_for_SC_CAN_V3_2_a9f4bf69_Tx, ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx, 59, 0, 198, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_AudioVolVSCModReq_oHUT2_oB30_for_SC_CAN_V3_2_8ce877e4_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 199, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_BeepSourceSet_oHUT2_oB30_for_SC_CAN_V3_2_9f83223b_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 200, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_FRAudioFaderSet_oHUT2_oB30_for_SC_CAN_V3_2_ba379647_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 201, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_HighFrqAudioSet_oHUT2_oB30_for_SC_CAN_V3_2_4671056c_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 202, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_LRAudioBalanceSet_oHUT2_oB30_for_SC_CAN_V3_2_a2f2bdee_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 203, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_LRDrvSideSet_oHUT2_oB30_for_SC_CAN_V3_2_b1e37988_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 204, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_LowFrqAudioSet_oHUT2_oB30_for_SC_CAN_V3_2_176070e9_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 205, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_MediaCallSourceSet_oHUT2_oB30_for_SC_CAN_V3_2_e52856c5_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 206, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_MidFrqAudioSet_oHUT2_oB30_for_SC_CAN_V3_2_4a2332b5_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 207, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_MuteSet_oHUT2_oB30_for_SC_CAN_V3_2_c859e023_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 208, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_NaviSourceSet_oHUT2_oB30_for_SC_CAN_V3_2_1214dd28_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 209, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ANCSwtSet_oHUT2_oB30_for_SC_CAN_V3_2_22c086d1_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 210, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_FrntWinHeatSwt_oHUT2_oB30_for_SC_CAN_V3_2_8b741751_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 211, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_QLISurroundSet_oHUT2_oB30_for_SC_CAN_V3_2_4010df4b_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 0, 212, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_RearWinHeatCmd_TC_oHUT2_oB30_for_SC_CAN_V3_2_16026460_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 59, 1, 213, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_T_box_ECallSet_oHUT2_oB30_for_SC_CAN_V3_2_6a76f20c_Tx, ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx, 60, 0, 214, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_BestListegPosnReq_oHUT3_oB30_for_SC_CAN_V3_2_e80cdf2b_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 215, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_Clari_FiReq_oHUT3_oB30_for_SC_CAN_V3_2_27cccfe8_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 216, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_GetDTCInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_3a2e316c_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 217, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_GetHWInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_8ae2ca22_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 218, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_GetIntVoltInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_4d9999be_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 219, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_GetSWInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_7fe362ae_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 220, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_GetTempInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_15a76665_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 221, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_HFMVolSet_oHUT3_oB30_for_SC_CAN_V3_2_c90daffb_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 222, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_MainVolSet_oHUT3_oB30_for_SC_CAN_V3_2_4a00cd55_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 223, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_NaviVolSet_oHUT3_oB30_for_SC_CAN_V3_2_6918cd42_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 224, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AMP_TTSVolSet_VR_oHUT3_oB30_for_SC_CAN_V3_2_ea75ad29_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 225, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_IESS_MdlInfoReq_oHUT3_oB30_for_SC_CAN_V3_2_f8eeef49_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 226, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_IESS_MdlSwtReq_oHUT3_oB30_for_SC_CAN_V3_2_be9c7b7a_Tx, ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx, 60, 0, 227, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACAirInletReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_a2d26002_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 60, 1, 228, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACAutoModReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_86a229b3_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 61, 1, 229, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACBlwrSpdReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_0bfc7670_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 62, 1, 230, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACCmprReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_f199fcee_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 63, 1, 231, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACDrvAirDistribModReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_86a8c7f8_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 64, 1, 232, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACDrvTempReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_b1eb4114_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 65, 1, 233, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACFrntDefrostReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_32e1b3aa_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 66, 1, 234, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ACModReq_HUT_oHUT4_oB30_for_SC_CAN_V3_2_8adaf80e_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 67, 0, 235, 1},
    {5, CNA_BEHAVIOR_SEND, ComConf_ComSignal_ACPowerReq_VR_oHUT4_oB30_for_SC_CAN_V3_2_624bb5d6_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 67, 1, 236, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_AllTerrainDislSet_oHUT4_oB30_for_SC_CAN_V3_2_c087cc89_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 237, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DrvSeatHeatgLvlSet_oHUT4_oB30_for_SC_CAN_V3_2_68785647_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 238, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_DrvSeatVentnLvlSet_oHUT4_oB30_for_SC_CAN_V3_2_068a13f2_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 239, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_ElecSideSteppingSysSet_oHUT4_oB30_for_SC_CAN_V3_2_f38699b8_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 240, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_PassSeatHeatgLvlSet_oHUT4_oB30_for_SC_CAN_V3_2_c65ec748_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 241, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_PassSeatVentnLvlSet_oHUT4_oB30_for_SC_CAN_V3_2_a8ac82fd_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 242, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_RemUpgrdSts_oHUT4_oB30_for_SC_CAN_V3_2_c46482c2_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 243, 1},
    {5, CNA_BEHAVIOR_NONE, ComConf_ComSignal_RoofModSet_oHUT4_oB30_for_SC_CAN_V3_2_210c5e85_Tx, ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx, 68, 0, 244, 1},
    {5, CNA_BEHAVIOR_CYCLE, ComConf_ComSignal_DrvSeatSupportPosnSwt_oHUT26_oB30_for_SC_CAN_V3_2_eb85f6bd_Tx, ComConf_ComIPdu_HUT26_oB30_for_SC_CAN_V3_2_9bf07418_Tx, 68, 1, 245, 1},
    {5, CNA_BEHAVIOR_CYCLE, ComConf_ComSignal_ChairMemPosnSet_oHUT_FD1_oB30_for_SC_CAN_V3_2_384d70bd_Tx, ComConf_ComIPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, 69, 1, 246, 1},
    {5, CNA_BEHAVIOR_CYCLE, ComConf_ComSignal_EPSSteerModSwtReq_oHUT_FD1_oB30_for_SC_CAN_V3_2_9076038b_Tx, ComConf_ComIPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, 70, 1, 247, 1},
};

static CNA_SignalType cna_signalDatas[238] = {0u};
static const uint8 cna_noActionBuffer[71] =
{
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    6u,
    10u,
    3u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    3u,
};

static uint8 cna_currentBuffer[248] = {0};

const CNA_ConfigType cna_config =
{
    238u,
    cna_signalConfigs,
    cna_signalDatas,
    71u,
    cna_noActionBuffer,
    248u,
    cna_currentBuffer
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, COM_APPL_CODE)AUTODefrost_TC_Handle(void);
FUNC(void, COM_APPL_CODE)AUTODefrost_VR_Handle(void);
FUNC(void, COM_APPL_CODE)AutoAVMSwSet_Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)AutoViewChgCmd_Handle(void);
FUNC(void, COM_APPL_CODE)CarMdlDispCmd_Handle(void);
FUNC(void, COM_APPL_CODE)CarMdlTrsprcySwtCmd_Handle(void);
FUNC(void, COM_APPL_CODE)FPAS_AutoModSwt_Handle(void);
FUNC(void, COM_APPL_CODE)Guid_Ovl_Display_Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)LaneCalActvtCmd_Handle(void);
FUNC(void, COM_APPL_CODE)MEBSwtSet_Handle(void);
FUNC(void, COM_APPL_CODE)MODChgReq_Handle(void);
FUNC(void, COM_APPL_CODE)MdlColrChgCmd_Handle(void);
FUNC(void, COM_APPL_CODE)Radar_DispCmd_Handle(void);
FUNC(void, COM_APPL_CODE)Sgl_View_Sel_Handle(void);
FUNC(void, COM_APPL_CODE)SwToFieldCalRstCmd_Handle(void);
FUNC(void, COM_APPL_CODE)View_SoftswitchCmd_Handle(void);
FUNC(void, COM_APPL_CODE)WshSoftSwt_Handle(void);
FUNC(void, COM_APPL_CODE)BackReq_AVM_Handle(void);
FUNC(void, COM_APPL_CODE)CancelVoiceIdn_Handle(void);
FUNC(void, COM_APPL_CODE)DeleteUserIDFaceData_Handle(void);
FUNC(void, COM_APPL_CODE)DeleteUserIDVoiceData_Handle(void);
FUNC(void, COM_APPL_CODE)DistrctnDetnSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrowsnsDetnSet_Handle(void);
FUNC(void, COM_APPL_CODE)EnrollFaceReq_Handle(void);
FUNC(void, COM_APPL_CODE)EnrollUserIDResult_Handle(void);
FUNC(void, COM_APPL_CODE)EraseAllFaceUsersReq_Handle(void);
FUNC(void, COM_APPL_CODE)EraseAllVoiceUsersReq_Handle(void);
FUNC(void, COM_APPL_CODE)ExprsnSetUp_Handle(void);
FUNC(void, COM_APPL_CODE)FaceIdnSet_Handle(void);
FUNC(void, COM_APPL_CODE)HUD_BrightnessLvlSwt_Handle(void);
FUNC(void, COM_APPL_CODE)HUD_HeightLvlSwt_Handle(void);
FUNC(void, COM_APPL_CODE)HUD_SwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)IdnResultReq_HUT_Handle(void);
FUNC(void, COM_APPL_CODE)VoiceIdnSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvBehvTestSetUp_Handle(void);
FUNC(void, COM_APPL_CODE)DrvSeatMassgLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvSeatMassgModSet_Handle(void);
FUNC(void, COM_APPL_CODE)GazeAreaIntracSetUp_Handle(void);
FUNC(void, COM_APPL_CODE)ApproachLampSet_Handle(void);
FUNC(void, COM_APPL_CODE)BackReq_APS_Handle(void);
FUNC(void, COM_APPL_CODE)ChairMemPosnSetSwt_Handle(void);
FUNC(void, COM_APPL_CODE)DeletePath1Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)DeletePath2Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)DrvWinSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)FlaoutUnlockSet_Handle(void);
FUNC(void, COM_APPL_CODE)MbrMonrEnReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ParkMdlCmd_Handle(void);
FUNC(void, COM_APPL_CODE)PassWinSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)PathLrngFinshCmd_Handle(void);
FUNC(void, COM_APPL_CODE)PathLrngStartCmd_Handle(void);
FUNC(void, COM_APPL_CODE)PrkInDirChoice_Handle(void);
FUNC(void, COM_APPL_CODE)RLWinSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)RRWinSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)SelPrkOutDirReq_Handle(void);
FUNC(void, COM_APPL_CODE)SelPrkgFctnCmd_Handle(void);
FUNC(void, COM_APPL_CODE)StartPrkgPath1Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)StartPrkgPath2Cmd_Handle(void);
FUNC(void, COM_APPL_CODE)SuperLockSet_Handle(void);
FUNC(void, COM_APPL_CODE)ABSLmpSet_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvSetTempSteplsReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACEAHReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACEAHReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACOperMod_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACOperMod_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACPassSetTempSteplsReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)APSPrkgTypSeln_Handle(void);
FUNC(void, COM_APPL_CODE)APSSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)AutoWshWipSet_Handle(void);
FUNC(void, COM_APPL_CODE)DoorUnlockModSet_Handle(void);
FUNC(void, COM_APPL_CODE)PASExitSpdSwt_Handle(void);
FUNC(void, COM_APPL_CODE)ParkLmpSet_Handle(void);
FUNC(void, COM_APPL_CODE)SDWSwtSet_Handle(void);
FUNC(void, COM_APPL_CODE)SeekVehSet_Handle(void);
FUNC(void, COM_APPL_CODE)SpdAutoLockModSet_Handle(void);
FUNC(void, COM_APPL_CODE)SportModLightSet_Handle(void);
FUNC(void, COM_APPL_CODE)SteerWheelHeatSwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)SunRoofSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)SunShadeSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_CmplxInsct_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_CycCnt_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_FormOfWay_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_FuncRoadClass_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_LastStub_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_MsgTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_NumOfLaneDrvDir_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_NumOfLaneOppDir_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_Offset_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_PartOfCalcRoute_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_PathIdx_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_RelProbb_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_Retr_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_RtOfWay_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_StubPathIdx_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_TurnAngl_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Stub_Update_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_Brdg_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_BuildUpArea_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_CmplxInsct_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_CycCnt_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_DivideRoad_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_EffSpdLmt_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_EffSpdLmtTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_FormOfWay_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_FuncRoadClass_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_MsgTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_NumOfLaneDrvDir_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_NumOfLaneOppDir_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_Offset_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_PartOfCalcRoute_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_PathIdx_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_RelProbb_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_Retr_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_Tunnel_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_Seg_Update_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_AccurClass_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_CtrlPoint_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_CycCnt_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Dist1_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_MsgTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Offset_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_PathIdx_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_ProfTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Retr_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Update_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Value0_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Value1_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_CtrlPoint_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_CycCnt_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_MsgTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Offset_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_PathIdx_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_ProfTyp_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Retr_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Update_Handle(void);
FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Value_Handle(void);
FUNC(void, COM_APPL_CODE)ACAIUReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACAQSReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACDualReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACPassTempReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACRearDefrstReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ALCMClrSet_Handle(void);
FUNC(void, COM_APPL_CODE)ALCMDynSwt_Handle(void);
FUNC(void, COM_APPL_CODE)ALCMRhmSwt_Handle(void);
FUNC(void, COM_APPL_CODE)ALCMStatSwt_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_EgyRecvrySet_Handle(void);
FUNC(void, COM_APPL_CODE)IPVolSet_Handle(void);
FUNC(void, COM_APPL_CODE)PASSwtReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)CarWashMode_Req_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_BattKeepTemp_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_BattSOCLim_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_ChrgnMode_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_IntelBattTempMagSet_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_IntelEngIdlChrgnSet_Handle(void);
FUNC(void, COM_APPL_CODE)HUT_RemtEngCtrl_Handle(void);
FUNC(void, COM_APPL_CODE)AVMMediaVolLvlReq_Handle(void);
FUNC(void, COM_APPL_CODE)AVMSwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)BackgroundLightLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)DispModSet_Handle(void);
FUNC(void, COM_APPL_CODE)FPASChanSwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)ManCmpSet_Handle(void);
FUNC(void, COM_APPL_CODE)NaviMediaVolLvlReq_Handle(void);
FUNC(void, COM_APPL_CODE)OPDSwtSts_Handle(void);
FUNC(void, COM_APPL_CODE)PLGReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)RPASChanSwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)WPC_SwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)T_BOX_RemtLimitStart_Handle(void);
FUNC(void, COM_APPL_CODE)ACAIUReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACAQSReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACAirInletReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACAutoModReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACBlwrsteplsSpdReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACCmprReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvAirDistribModReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvTempDecReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvTempIncReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACDualReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntBlwrSpdDecReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntBlwrSpdIncReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntDefrstReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntPassTempDecReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntPassTempIncReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)ACOffReq_TC_Handle(void);
FUNC(void, COM_APPL_CODE)BattSaveDelayTimeSet_Handle(void);
FUNC(void, COM_APPL_CODE)ChairMemPosnEna_Handle(void);
FUNC(void, COM_APPL_CODE)DomeLmpDlyTimSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvDrowsnsDetnSet_Handle(void);
FUNC(void, COM_APPL_CODE)FolwMeHomeDlyTimSet_Handle(void);
FUNC(void, COM_APPL_CODE)RearviewFoldModSet_Handle(void);
FUNC(void, COM_APPL_CODE)TranPMode_Req_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_AudioVolVSCModReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_BeepSourceSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_FRAudioFaderSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_HighFrqAudioSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_LRAudioBalanceSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_LRDrvSideSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_LowFrqAudioSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_MediaCallSourceSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_MidFrqAudioSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_MuteSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_NaviSourceSet_Handle(void);
FUNC(void, COM_APPL_CODE)ANCSwtSet_Handle(void);
FUNC(void, COM_APPL_CODE)FrntWinHeatSwt_Handle(void);
FUNC(void, COM_APPL_CODE)QLISurroundSet_Handle(void);
FUNC(void, COM_APPL_CODE)RearWinHeatCmd_TC_Handle(void);
FUNC(void, COM_APPL_CODE)T_box_ECallSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_BestListegPosnReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_Clari_FiReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_GetDTCInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_GetHWInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_GetIntVoltInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_GetSWInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_GetTempInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_HFMVolSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_MainVolSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_NaviVolSet_Handle(void);
FUNC(void, COM_APPL_CODE)AMP_TTSVolSet_VR_Handle(void);
FUNC(void, COM_APPL_CODE)IESS_MdlInfoReq_Handle(void);
FUNC(void, COM_APPL_CODE)IESS_MdlSwtReq_Handle(void);
FUNC(void, COM_APPL_CODE)ACAirInletReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACAutoModReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACBlwrSpdReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACCmprReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvAirDistribModReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACDrvTempReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACFrntDefrostReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)ACModReq_HUT_Handle(void);
FUNC(void, COM_APPL_CODE)ACPowerReq_VR_Handle(void);
FUNC(void, COM_APPL_CODE)AllTerrainDislSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvSeatHeatgLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvSeatVentnLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)ElecSideSteppingSysSet_Handle(void);
FUNC(void, COM_APPL_CODE)PassSeatHeatgLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)PassSeatVentnLvlSet_Handle(void);
FUNC(void, COM_APPL_CODE)RemUpgrdSts_Handle(void);
FUNC(void, COM_APPL_CODE)RoofModSet_Handle(void);
FUNC(void, COM_APPL_CODE)DrvSeatSupportPosnSwt_Handle(void);
FUNC(void, COM_APPL_CODE)ChairMemPosnSet_Handle(void);
FUNC(void, COM_APPL_CODE)EPSSteerModSwtReq_Handle(void);

#define Can_Server_STOP_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define Can_Server_START_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, COM_APPL_CODE)AUTODefrost_TC_Handle(void)
{
    CNA_SignalCallback(0u);
}

FUNC(void, COM_APPL_CODE)AUTODefrost_VR_Handle(void)
{
    CNA_SignalCallback(1u);
}

FUNC(void, COM_APPL_CODE)AutoAVMSwSet_Cmd_Handle(void)
{
    CNA_SignalCallback(2u);
}

FUNC(void, COM_APPL_CODE)AutoViewChgCmd_Handle(void)
{
    CNA_SignalCallback(3u);
}

FUNC(void, COM_APPL_CODE)CarMdlDispCmd_Handle(void)
{
    CNA_SignalCallback(4u);
}

FUNC(void, COM_APPL_CODE)CarMdlTrsprcySwtCmd_Handle(void)
{
    CNA_SignalCallback(5u);
}

FUNC(void, COM_APPL_CODE)FPAS_AutoModSwt_Handle(void)
{
    CNA_SignalCallback(6u);
}

FUNC(void, COM_APPL_CODE)Guid_Ovl_Display_Cmd_Handle(void)
{
    CNA_SignalCallback(7u);
}

FUNC(void, COM_APPL_CODE)LaneCalActvtCmd_Handle(void)
{
    CNA_SignalCallback(8u);
}

FUNC(void, COM_APPL_CODE)MEBSwtSet_Handle(void)
{
    CNA_SignalCallback(9u);
}

FUNC(void, COM_APPL_CODE)MODChgReq_Handle(void)
{
    CNA_SignalCallback(10u);
}

FUNC(void, COM_APPL_CODE)MdlColrChgCmd_Handle(void)
{
    CNA_SignalCallback(11u);
}

FUNC(void, COM_APPL_CODE)Radar_DispCmd_Handle(void)
{
    CNA_SignalCallback(12u);
}

FUNC(void, COM_APPL_CODE)Sgl_View_Sel_Handle(void)
{
    CNA_SignalCallback(13u);
}

FUNC(void, COM_APPL_CODE)SwToFieldCalRstCmd_Handle(void)
{
    CNA_SignalCallback(14u);
}

FUNC(void, COM_APPL_CODE)View_SoftswitchCmd_Handle(void)
{
    CNA_SignalCallback(15u);
}

FUNC(void, COM_APPL_CODE)WshSoftSwt_Handle(void)
{
    CNA_SignalCallback(16u);
}

FUNC(void, COM_APPL_CODE)BackReq_AVM_Handle(void)
{
    CNA_SignalCallback(17u);
}

FUNC(void, COM_APPL_CODE)CancelVoiceIdn_Handle(void)
{
    CNA_SignalCallback(18u);
}

FUNC(void, COM_APPL_CODE)DeleteUserIDFaceData_Handle(void)
{
    CNA_SignalCallback(19u);
}

FUNC(void, COM_APPL_CODE)DeleteUserIDVoiceData_Handle(void)
{
    CNA_SignalCallback(20u);
}

FUNC(void, COM_APPL_CODE)DistrctnDetnSet_Handle(void)
{
    CNA_SignalCallback(21u);
}

FUNC(void, COM_APPL_CODE)DrowsnsDetnSet_Handle(void)
{
    CNA_SignalCallback(22u);
}

FUNC(void, COM_APPL_CODE)EnrollFaceReq_Handle(void)
{
    CNA_SignalCallback(23u);
}

FUNC(void, COM_APPL_CODE)EnrollUserIDResult_Handle(void)
{
    CNA_SignalCallback(24u);
}

FUNC(void, COM_APPL_CODE)EraseAllFaceUsersReq_Handle(void)
{
    CNA_SignalCallback(25u);
}

FUNC(void, COM_APPL_CODE)EraseAllVoiceUsersReq_Handle(void)
{
    CNA_SignalCallback(26u);
}

FUNC(void, COM_APPL_CODE)ExprsnSetUp_Handle(void)
{
    CNA_SignalCallback(27u);
}

FUNC(void, COM_APPL_CODE)FaceIdnSet_Handle(void)
{
    CNA_SignalCallback(28u);
}

FUNC(void, COM_APPL_CODE)HUD_BrightnessLvlSwt_Handle(void)
{
    CNA_SignalCallback(29u);
}

FUNC(void, COM_APPL_CODE)HUD_HeightLvlSwt_Handle(void)
{
    CNA_SignalCallback(30u);
}

FUNC(void, COM_APPL_CODE)HUD_SwtReq_Handle(void)
{
    CNA_SignalCallback(31u);
}

FUNC(void, COM_APPL_CODE)IdnResultReq_HUT_Handle(void)
{
    CNA_SignalCallback(32u);
}

FUNC(void, COM_APPL_CODE)VoiceIdnSet_Handle(void)
{
    CNA_SignalCallback(33u);
}

FUNC(void, COM_APPL_CODE)DrvBehvTestSetUp_Handle(void)
{
    CNA_SignalCallback(34u);
}

FUNC(void, COM_APPL_CODE)DrvSeatMassgLvlSet_Handle(void)
{
    CNA_SignalCallback(35u);
}

FUNC(void, COM_APPL_CODE)DrvSeatMassgModSet_Handle(void)
{
    CNA_SignalCallback(36u);
}

FUNC(void, COM_APPL_CODE)GazeAreaIntracSetUp_Handle(void)
{
    CNA_SignalCallback(37u);
}

FUNC(void, COM_APPL_CODE)ApproachLampSet_Handle(void)
{
    CNA_SignalCallback(38u);
}

FUNC(void, COM_APPL_CODE)BackReq_APS_Handle(void)
{
    CNA_SignalCallback(39u);
}

FUNC(void, COM_APPL_CODE)ChairMemPosnSetSwt_Handle(void)
{
    CNA_SignalCallback(40u);
}

FUNC(void, COM_APPL_CODE)DeletePath1Cmd_Handle(void)
{
    CNA_SignalCallback(41u);
}

FUNC(void, COM_APPL_CODE)DeletePath2Cmd_Handle(void)
{
    CNA_SignalCallback(42u);
}

FUNC(void, COM_APPL_CODE)DrvWinSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(43u);
}

FUNC(void, COM_APPL_CODE)FlaoutUnlockSet_Handle(void)
{
    CNA_SignalCallback(44u);
}

FUNC(void, COM_APPL_CODE)MbrMonrEnReq_TC_Handle(void)
{
    CNA_SignalCallback(45u);
}

FUNC(void, COM_APPL_CODE)ParkMdlCmd_Handle(void)
{
    CNA_SignalCallback(46u);
}

FUNC(void, COM_APPL_CODE)PassWinSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(47u);
}

FUNC(void, COM_APPL_CODE)PathLrngFinshCmd_Handle(void)
{
    CNA_SignalCallback(48u);
}

FUNC(void, COM_APPL_CODE)PathLrngStartCmd_Handle(void)
{
    CNA_SignalCallback(49u);
}

FUNC(void, COM_APPL_CODE)PrkInDirChoice_Handle(void)
{
    CNA_SignalCallback(50u);
}

FUNC(void, COM_APPL_CODE)RLWinSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(51u);
}

FUNC(void, COM_APPL_CODE)RRWinSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(52u);
}

FUNC(void, COM_APPL_CODE)SelPrkOutDirReq_Handle(void)
{
    CNA_SignalCallback(53u);
}

FUNC(void, COM_APPL_CODE)SelPrkgFctnCmd_Handle(void)
{
    CNA_SignalCallback(54u);
}

FUNC(void, COM_APPL_CODE)StartPrkgPath1Cmd_Handle(void)
{
    CNA_SignalCallback(55u);
}

FUNC(void, COM_APPL_CODE)StartPrkgPath2Cmd_Handle(void)
{
    CNA_SignalCallback(56u);
}

FUNC(void, COM_APPL_CODE)SuperLockSet_Handle(void)
{
    CNA_SignalCallback(57u);
}

FUNC(void, COM_APPL_CODE)ABSLmpSet_Handle(void)
{
    CNA_SignalCallback(58u);
}

FUNC(void, COM_APPL_CODE)ACDrvSetTempSteplsReq_TC_Handle(void)
{
    CNA_SignalCallback(59u);
}

FUNC(void, COM_APPL_CODE)ACEAHReq_TC_Handle(void)
{
    CNA_SignalCallback(60u);
}

FUNC(void, COM_APPL_CODE)ACEAHReq_VR_Handle(void)
{
    CNA_SignalCallback(61u);
}

FUNC(void, COM_APPL_CODE)ACOperMod_TC_Handle(void)
{
    CNA_SignalCallback(62u);
}

FUNC(void, COM_APPL_CODE)ACOperMod_VR_Handle(void)
{
    CNA_SignalCallback(63u);
}

FUNC(void, COM_APPL_CODE)ACPassSetTempSteplsReq_TC_Handle(void)
{
    CNA_SignalCallback(64u);
}

FUNC(void, COM_APPL_CODE)APSPrkgTypSeln_Handle(void)
{
    CNA_SignalCallback(65u);
}

FUNC(void, COM_APPL_CODE)APSSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(66u);
}

FUNC(void, COM_APPL_CODE)AutoWshWipSet_Handle(void)
{
    CNA_SignalCallback(67u);
}

FUNC(void, COM_APPL_CODE)DoorUnlockModSet_Handle(void)
{
    CNA_SignalCallback(68u);
}

FUNC(void, COM_APPL_CODE)PASExitSpdSwt_Handle(void)
{
    CNA_SignalCallback(69u);
}

FUNC(void, COM_APPL_CODE)ParkLmpSet_Handle(void)
{
    CNA_SignalCallback(70u);
}

FUNC(void, COM_APPL_CODE)SDWSwtSet_Handle(void)
{
    CNA_SignalCallback(71u);
}

FUNC(void, COM_APPL_CODE)SeekVehSet_Handle(void)
{
    CNA_SignalCallback(72u);
}

FUNC(void, COM_APPL_CODE)SpdAutoLockModSet_Handle(void)
{
    CNA_SignalCallback(73u);
}

FUNC(void, COM_APPL_CODE)SportModLightSet_Handle(void)
{
    CNA_SignalCallback(74u);
}

FUNC(void, COM_APPL_CODE)SteerWheelHeatSwtReq_Handle(void)
{
    CNA_SignalCallback(75u);
}

FUNC(void, COM_APPL_CODE)SunRoofSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(76u);
}

FUNC(void, COM_APPL_CODE)SunShadeSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(77u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_CmplxInsct_Handle(void)
{
    CNA_SignalCallback(78u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_CycCnt_Handle(void)
{
    CNA_SignalCallback(79u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_FormOfWay_Handle(void)
{
    CNA_SignalCallback(80u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_FuncRoadClass_Handle(void)
{
    CNA_SignalCallback(81u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_LastStub_Handle(void)
{
    CNA_SignalCallback(82u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_MsgTyp_Handle(void)
{
    CNA_SignalCallback(83u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_NumOfLaneDrvDir_Handle(void)
{
    CNA_SignalCallback(84u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_NumOfLaneOppDir_Handle(void)
{
    CNA_SignalCallback(85u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_Offset_Handle(void)
{
    CNA_SignalCallback(86u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_PartOfCalcRoute_Handle(void)
{
    CNA_SignalCallback(87u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_PathIdx_Handle(void)
{
    CNA_SignalCallback(88u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_RelProbb_Handle(void)
{
    CNA_SignalCallback(89u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_Retr_Handle(void)
{
    CNA_SignalCallback(90u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_RtOfWay_Handle(void)
{
    CNA_SignalCallback(91u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_StubPathIdx_Handle(void)
{
    CNA_SignalCallback(92u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_TurnAngl_Handle(void)
{
    CNA_SignalCallback(93u);
}

FUNC(void, COM_APPL_CODE)ADAS_Stub_Update_Handle(void)
{
    CNA_SignalCallback(94u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_Brdg_Handle(void)
{
    CNA_SignalCallback(95u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_BuildUpArea_Handle(void)
{
    CNA_SignalCallback(96u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_CmplxInsct_Handle(void)
{
    CNA_SignalCallback(97u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_CycCnt_Handle(void)
{
    CNA_SignalCallback(98u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_DivideRoad_Handle(void)
{
    CNA_SignalCallback(99u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_EffSpdLmt_Handle(void)
{
    CNA_SignalCallback(100u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_EffSpdLmtTyp_Handle(void)
{
    CNA_SignalCallback(101u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_FormOfWay_Handle(void)
{
    CNA_SignalCallback(102u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_FuncRoadClass_Handle(void)
{
    CNA_SignalCallback(103u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_MsgTyp_Handle(void)
{
    CNA_SignalCallback(104u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_NumOfLaneDrvDir_Handle(void)
{
    CNA_SignalCallback(105u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_NumOfLaneOppDir_Handle(void)
{
    CNA_SignalCallback(106u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_Offset_Handle(void)
{
    CNA_SignalCallback(107u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_PartOfCalcRoute_Handle(void)
{
    CNA_SignalCallback(108u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_PathIdx_Handle(void)
{
    CNA_SignalCallback(109u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_RelProbb_Handle(void)
{
    CNA_SignalCallback(110u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_Retr_Handle(void)
{
    CNA_SignalCallback(111u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_Tunnel_Handle(void)
{
    CNA_SignalCallback(112u);
}

FUNC(void, COM_APPL_CODE)ADAS_Seg_Update_Handle(void)
{
    CNA_SignalCallback(113u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_AccurClass_Handle(void)
{
    CNA_SignalCallback(114u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_CtrlPoint_Handle(void)
{
    CNA_SignalCallback(115u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_CycCnt_Handle(void)
{
    CNA_SignalCallback(116u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Dist1_Handle(void)
{
    CNA_SignalCallback(117u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_MsgTyp_Handle(void)
{
    CNA_SignalCallback(118u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Offset_Handle(void)
{
    CNA_SignalCallback(119u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_PathIdx_Handle(void)
{
    CNA_SignalCallback(120u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_ProfTyp_Handle(void)
{
    CNA_SignalCallback(121u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Retr_Handle(void)
{
    CNA_SignalCallback(122u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Update_Handle(void)
{
    CNA_SignalCallback(123u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Value0_Handle(void)
{
    CNA_SignalCallback(124u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfShort_Value1_Handle(void)
{
    CNA_SignalCallback(125u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_CtrlPoint_Handle(void)
{
    CNA_SignalCallback(126u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_CycCnt_Handle(void)
{
    CNA_SignalCallback(127u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_MsgTyp_Handle(void)
{
    CNA_SignalCallback(128u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Offset_Handle(void)
{
    CNA_SignalCallback(129u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_PathIdx_Handle(void)
{
    CNA_SignalCallback(130u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_ProfTyp_Handle(void)
{
    CNA_SignalCallback(131u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Retr_Handle(void)
{
    CNA_SignalCallback(132u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Update_Handle(void)
{
    CNA_SignalCallback(133u);
}

FUNC(void, COM_APPL_CODE)ADAS_ProfLong_Value_Handle(void)
{
    CNA_SignalCallback(134u);
}

FUNC(void, COM_APPL_CODE)ACAIUReq_VR_Handle(void)
{
    CNA_SignalCallback(135u);
}

FUNC(void, COM_APPL_CODE)ACAQSReq_VR_Handle(void)
{
    CNA_SignalCallback(136u);
}

FUNC(void, COM_APPL_CODE)ACDualReq_VR_Handle(void)
{
    CNA_SignalCallback(137u);
}

FUNC(void, COM_APPL_CODE)ACPassTempReq_VR_Handle(void)
{
    CNA_SignalCallback(138u);
}

FUNC(void, COM_APPL_CODE)ACRearDefrstReq_VR_Handle(void)
{
    CNA_SignalCallback(139u);
}

FUNC(void, COM_APPL_CODE)ALCMClrSet_Handle(void)
{
    CNA_SignalCallback(140u);
}

FUNC(void, COM_APPL_CODE)ALCMDynSwt_Handle(void)
{
    CNA_SignalCallback(141u);
}

FUNC(void, COM_APPL_CODE)ALCMRhmSwt_Handle(void)
{
    CNA_SignalCallback(142u);
}

FUNC(void, COM_APPL_CODE)ALCMStatSwt_Handle(void)
{
    CNA_SignalCallback(143u);
}

FUNC(void, COM_APPL_CODE)HUT_EgyRecvrySet_Handle(void)
{
    CNA_SignalCallback(144u);
}

FUNC(void, COM_APPL_CODE)IPVolSet_Handle(void)
{
    CNA_SignalCallback(145u);
}

FUNC(void, COM_APPL_CODE)PASSwtReq_VR_Handle(void)
{
    CNA_SignalCallback(146u);
}

FUNC(void, COM_APPL_CODE)CarWashMode_Req_Handle(void)
{
    CNA_SignalCallback(147u);
}

FUNC(void, COM_APPL_CODE)HUT_BattKeepTemp_Handle(void)
{
    CNA_SignalCallback(148u);
}

FUNC(void, COM_APPL_CODE)HUT_BattSOCLim_Handle(void)
{
    CNA_SignalCallback(149u);
}

FUNC(void, COM_APPL_CODE)HUT_ChrgnMode_Handle(void)
{
    CNA_SignalCallback(150u);
}

FUNC(void, COM_APPL_CODE)HUT_IntelBattTempMagSet_Handle(void)
{
    CNA_SignalCallback(151u);
}

FUNC(void, COM_APPL_CODE)HUT_IntelEngIdlChrgnSet_Handle(void)
{
    CNA_SignalCallback(152u);
}

FUNC(void, COM_APPL_CODE)HUT_RemtEngCtrl_Handle(void)
{
    CNA_SignalCallback(153u);
}

FUNC(void, COM_APPL_CODE)AVMMediaVolLvlReq_Handle(void)
{
    CNA_SignalCallback(154u);
}

FUNC(void, COM_APPL_CODE)AVMSwtReq_Handle(void)
{
    CNA_SignalCallback(155u);
}

FUNC(void, COM_APPL_CODE)BackgroundLightLvlSet_Handle(void)
{
    CNA_SignalCallback(156u);
}

FUNC(void, COM_APPL_CODE)DispModSet_Handle(void)
{
    CNA_SignalCallback(157u);
}

FUNC(void, COM_APPL_CODE)FPASChanSwtReq_Handle(void)
{
    CNA_SignalCallback(158u);
}

FUNC(void, COM_APPL_CODE)ManCmpSet_Handle(void)
{
    CNA_SignalCallback(159u);
}

FUNC(void, COM_APPL_CODE)NaviMediaVolLvlReq_Handle(void)
{
    CNA_SignalCallback(160u);
}

FUNC(void, COM_APPL_CODE)OPDSwtSts_Handle(void)
{
    CNA_SignalCallback(161u);
}

FUNC(void, COM_APPL_CODE)PLGReq_VR_Handle(void)
{
    CNA_SignalCallback(162u);
}

FUNC(void, COM_APPL_CODE)RPASChanSwtReq_Handle(void)
{
    CNA_SignalCallback(163u);
}

FUNC(void, COM_APPL_CODE)WPC_SwtReq_Handle(void)
{
    CNA_SignalCallback(164u);
}

FUNC(void, COM_APPL_CODE)T_BOX_RemtLimitStart_Handle(void)
{
    CNA_SignalCallback(165u);
}

FUNC(void, COM_APPL_CODE)ACAIUReq_TC_Handle(void)
{
    CNA_SignalCallback(166u);
}

FUNC(void, COM_APPL_CODE)ACAQSReq_TC_Handle(void)
{
    CNA_SignalCallback(167u);
}

FUNC(void, COM_APPL_CODE)ACAirInletReq_TC_Handle(void)
{
    CNA_SignalCallback(168u);
}

FUNC(void, COM_APPL_CODE)ACAutoModReq_TC_Handle(void)
{
    CNA_SignalCallback(169u);
}

FUNC(void, COM_APPL_CODE)ACBlwrsteplsSpdReq_TC_Handle(void)
{
    CNA_SignalCallback(170u);
}

FUNC(void, COM_APPL_CODE)ACCmprReq_TC_Handle(void)
{
    CNA_SignalCallback(171u);
}

FUNC(void, COM_APPL_CODE)ACDrvAirDistribModReq_TC_Handle(void)
{
    CNA_SignalCallback(172u);
}

FUNC(void, COM_APPL_CODE)ACDrvTempDecReq_TC_Handle(void)
{
    CNA_SignalCallback(173u);
}

FUNC(void, COM_APPL_CODE)ACDrvTempIncReq_TC_Handle(void)
{
    CNA_SignalCallback(174u);
}

FUNC(void, COM_APPL_CODE)ACDualReq_TC_Handle(void)
{
    CNA_SignalCallback(175u);
}

FUNC(void, COM_APPL_CODE)ACFrntBlwrSpdDecReq_TC_Handle(void)
{
    CNA_SignalCallback(176u);
}

FUNC(void, COM_APPL_CODE)ACFrntBlwrSpdIncReq_TC_Handle(void)
{
    CNA_SignalCallback(177u);
}

FUNC(void, COM_APPL_CODE)ACFrntDefrstReq_TC_Handle(void)
{
    CNA_SignalCallback(178u);
}

FUNC(void, COM_APPL_CODE)ACFrntPassTempDecReq_TC_Handle(void)
{
    CNA_SignalCallback(179u);
}

FUNC(void, COM_APPL_CODE)ACFrntPassTempIncReq_TC_Handle(void)
{
    CNA_SignalCallback(180u);
}

FUNC(void, COM_APPL_CODE)ACOffReq_TC_Handle(void)
{
    CNA_SignalCallback(181u);
}

FUNC(void, COM_APPL_CODE)BattSaveDelayTimeSet_Handle(void)
{
    CNA_SignalCallback(182u);
}

FUNC(void, COM_APPL_CODE)ChairMemPosnEna_Handle(void)
{
    CNA_SignalCallback(183u);
}

FUNC(void, COM_APPL_CODE)DomeLmpDlyTimSet_Handle(void)
{
    CNA_SignalCallback(184u);
}

FUNC(void, COM_APPL_CODE)DrvDrowsnsDetnSet_Handle(void)
{
    CNA_SignalCallback(185u);
}

FUNC(void, COM_APPL_CODE)FolwMeHomeDlyTimSet_Handle(void)
{
    CNA_SignalCallback(186u);
}

FUNC(void, COM_APPL_CODE)RearviewFoldModSet_Handle(void)
{
    CNA_SignalCallback(187u);
}

FUNC(void, COM_APPL_CODE)TranPMode_Req_Handle(void)
{
    CNA_SignalCallback(188u);
}

FUNC(void, COM_APPL_CODE)AMP_AudioVolVSCModReq_Handle(void)
{
    CNA_SignalCallback(189u);
}

FUNC(void, COM_APPL_CODE)AMP_BeepSourceSet_Handle(void)
{
    CNA_SignalCallback(190u);
}

FUNC(void, COM_APPL_CODE)AMP_FRAudioFaderSet_Handle(void)
{
    CNA_SignalCallback(191u);
}

FUNC(void, COM_APPL_CODE)AMP_HighFrqAudioSet_Handle(void)
{
    CNA_SignalCallback(192u);
}

FUNC(void, COM_APPL_CODE)AMP_LRAudioBalanceSet_Handle(void)
{
    CNA_SignalCallback(193u);
}

FUNC(void, COM_APPL_CODE)AMP_LRDrvSideSet_Handle(void)
{
    CNA_SignalCallback(194u);
}

FUNC(void, COM_APPL_CODE)AMP_LowFrqAudioSet_Handle(void)
{
    CNA_SignalCallback(195u);
}

FUNC(void, COM_APPL_CODE)AMP_MediaCallSourceSet_Handle(void)
{
    CNA_SignalCallback(196u);
}

FUNC(void, COM_APPL_CODE)AMP_MidFrqAudioSet_Handle(void)
{
    CNA_SignalCallback(197u);
}

FUNC(void, COM_APPL_CODE)AMP_MuteSet_Handle(void)
{
    CNA_SignalCallback(198u);
}

FUNC(void, COM_APPL_CODE)AMP_NaviSourceSet_Handle(void)
{
    CNA_SignalCallback(199u);
}

FUNC(void, COM_APPL_CODE)ANCSwtSet_Handle(void)
{
    CNA_SignalCallback(200u);
}

FUNC(void, COM_APPL_CODE)FrntWinHeatSwt_Handle(void)
{
    CNA_SignalCallback(201u);
}

FUNC(void, COM_APPL_CODE)QLISurroundSet_Handle(void)
{
    CNA_SignalCallback(202u);
}

FUNC(void, COM_APPL_CODE)RearWinHeatCmd_TC_Handle(void)
{
    CNA_SignalCallback(203u);
}

FUNC(void, COM_APPL_CODE)T_box_ECallSet_Handle(void)
{
    CNA_SignalCallback(204u);
}

FUNC(void, COM_APPL_CODE)AMP_BestListegPosnReq_Handle(void)
{
    CNA_SignalCallback(205u);
}

FUNC(void, COM_APPL_CODE)AMP_Clari_FiReq_Handle(void)
{
    CNA_SignalCallback(206u);
}

FUNC(void, COM_APPL_CODE)AMP_GetDTCInfoReq_Handle(void)
{
    CNA_SignalCallback(207u);
}

FUNC(void, COM_APPL_CODE)AMP_GetHWInfoReq_Handle(void)
{
    CNA_SignalCallback(208u);
}

FUNC(void, COM_APPL_CODE)AMP_GetIntVoltInfoReq_Handle(void)
{
    CNA_SignalCallback(209u);
}

FUNC(void, COM_APPL_CODE)AMP_GetSWInfoReq_Handle(void)
{
    CNA_SignalCallback(210u);
}

FUNC(void, COM_APPL_CODE)AMP_GetTempInfoReq_Handle(void)
{
    CNA_SignalCallback(211u);
}

FUNC(void, COM_APPL_CODE)AMP_HFMVolSet_Handle(void)
{
    CNA_SignalCallback(212u);
}

FUNC(void, COM_APPL_CODE)AMP_MainVolSet_Handle(void)
{
    CNA_SignalCallback(213u);
}

FUNC(void, COM_APPL_CODE)AMP_NaviVolSet_Handle(void)
{
    CNA_SignalCallback(214u);
}

FUNC(void, COM_APPL_CODE)AMP_TTSVolSet_VR_Handle(void)
{
    CNA_SignalCallback(215u);
}

FUNC(void, COM_APPL_CODE)IESS_MdlInfoReq_Handle(void)
{
    CNA_SignalCallback(216u);
}

FUNC(void, COM_APPL_CODE)IESS_MdlSwtReq_Handle(void)
{
    CNA_SignalCallback(217u);
}

FUNC(void, COM_APPL_CODE)ACAirInletReq_VR_Handle(void)
{
    CNA_SignalCallback(218u);
}

FUNC(void, COM_APPL_CODE)ACAutoModReq_VR_Handle(void)
{
    CNA_SignalCallback(219u);
}

FUNC(void, COM_APPL_CODE)ACBlwrSpdReq_VR_Handle(void)
{
    CNA_SignalCallback(220u);
}

FUNC(void, COM_APPL_CODE)ACCmprReq_VR_Handle(void)
{
    CNA_SignalCallback(221u);
}

FUNC(void, COM_APPL_CODE)ACDrvAirDistribModReq_VR_Handle(void)
{
    CNA_SignalCallback(222u);
}

FUNC(void, COM_APPL_CODE)ACDrvTempReq_VR_Handle(void)
{
    CNA_SignalCallback(223u);
}

FUNC(void, COM_APPL_CODE)ACFrntDefrostReq_VR_Handle(void)
{
    CNA_SignalCallback(224u);
}

FUNC(void, COM_APPL_CODE)ACModReq_HUT_Handle(void)
{
    CNA_SignalCallback(225u);
}

FUNC(void, COM_APPL_CODE)ACPowerReq_VR_Handle(void)
{
    CNA_SignalCallback(226u);
}

FUNC(void, COM_APPL_CODE)AllTerrainDislSet_Handle(void)
{
    CNA_SignalCallback(227u);
}

FUNC(void, COM_APPL_CODE)DrvSeatHeatgLvlSet_Handle(void)
{
    CNA_SignalCallback(228u);
}

FUNC(void, COM_APPL_CODE)DrvSeatVentnLvlSet_Handle(void)
{
    CNA_SignalCallback(229u);
}

FUNC(void, COM_APPL_CODE)ElecSideSteppingSysSet_Handle(void)
{
    CNA_SignalCallback(230u);
}

FUNC(void, COM_APPL_CODE)PassSeatHeatgLvlSet_Handle(void)
{
    CNA_SignalCallback(231u);
}

FUNC(void, COM_APPL_CODE)PassSeatVentnLvlSet_Handle(void)
{
    CNA_SignalCallback(232u);
}

FUNC(void, COM_APPL_CODE)RemUpgrdSts_Handle(void)
{
    CNA_SignalCallback(233u);
}

FUNC(void, COM_APPL_CODE)RoofModSet_Handle(void)
{
    CNA_SignalCallback(234u);
}

FUNC(void, COM_APPL_CODE)DrvSeatSupportPosnSwt_Handle(void)
{
    CNA_SignalCallback(235u);
}

FUNC(void, COM_APPL_CODE)ChairMemPosnSet_Handle(void)
{
    CNA_SignalCallback(236u);
}

FUNC(void, COM_APPL_CODE)EPSSteerModSwtReq_Handle(void)
{
    CNA_SignalCallback(237u);
}

#define Can_Server_STOP_SEC_CODE
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
