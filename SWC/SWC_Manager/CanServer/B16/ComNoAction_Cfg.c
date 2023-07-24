/**
 ********************************************************************************************************************
 * @file:      ComNoAction_Cfg.c
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 ********************************************************************************************************************
 *  @copyright
 *  COPYRIGHT
 *  -----------------------------------------------------------------------------------------------------------------
 * 
 *  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
 *  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
 * 
 ********************************************************************************************************************
 */

/*
 *  %header file in this project/library%
 */
#include "ComNoAction.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */


/*
 *  %forward declaration%
 */


/*
 *  %global definition%
 */
static const CNA_SignalConfigType cna_signalConfigs[277] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 125, 8, 0, 0, 0, 1}, /* DrvSeatPosnToWelGuest */
    {/* Index 1 */ 5, CNA_BEHAVIOR_SEND, 107, 7, 0, 1, 1, 1}, /* AUTODefrost_TC */
    {/* Index 2 */ 5, CNA_BEHAVIOR_SEND, 108, 7, 1, 1, 2, 1}, /* AUTODefrost_VR */
    {/* Index 3 */ 5, CNA_BEHAVIOR_SEND, 119, 7, 2, 1, 3, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 4 */ 5, CNA_BEHAVIOR_SEND, 115, 7, 3, 1, 4, 1}, /* AutoViewChgCmd */
    {/* Index 5 */ 5, CNA_BEHAVIOR_SEND, 118, 7, 4, 1, 5, 1}, /* CarMdlDispCmd */
    {/* Index 6 */ 5, CNA_BEHAVIOR_SEND, 117, 7, 5, 1, 6, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 120, 7, 6, 1, 7, 1}, /* FPAS_AutoModSwt */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 112, 7, 7, 1, 8, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 9 */ 5, CNA_BEHAVIOR_SEND, 109, 7, 8, 1, 9, 1}, /* LaneCalActvtCmd */
    {/* Index 10 */ 5, CNA_BEHAVIOR_SEND, 121, 7, 9, 1, 10, 1}, /* MEBSwtSet */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 110, 7, 10, 1, 11, 1}, /* MODChgReq */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 116, 7, 11, 1, 12, 1}, /* MdlColrChgCmd */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 111, 7, 12, 1, 13, 1}, /* Radar_DispCmd */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 113, 7, 13, 1, 14, 1}, /* Sgl_View_Sel */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 114, 7, 14, 1, 15, 1}, /* SwToFieldCalRstCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 123, 7, 15, 1, 16, 1}, /* View_SoftswitchCmd */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 122, 7, 16, 1, 17, 1}, /* WshSoftSwt */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 545, 34, 17, 1, 18, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 19 */ 5, CNA_BEHAVIOR_UNSEND, 536, 34, 18, 1, 19, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 20 */ 5, CNA_BEHAVIOR_NONE, 539, 34, 19, 0, 20, 1}, /* HUT_HAVP_LearningTypeSele */
    {/* Index 21 */ 5, CNA_BEHAVIOR_NONE, 537, 34, 19, 0, 21, 1}, /* HUT_HAVP_Learning_Set_ParkLot */
    {/* Index 22 */ 5, CNA_BEHAVIOR_NONE, 540, 34, 19, 0, 22, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 23 */ 5, CNA_BEHAVIOR_NONE, 541, 34, 19, 0, 23, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 24 */ 5, CNA_BEHAVIOR_NONE, 542, 34, 19, 0, 24, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 533, 34, 19, 1, 25, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 535, 34, 20, 1, 26, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 538, 34, 21, 1, 27, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 534, 34, 22, 1, 28, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 29 */ 5, CNA_BEHAVIOR_SEND, 543, 34, 23, 1, 29, 1}, /* SlotNum_VR */
    {/* Index 30 */ 5, CNA_BEHAVIOR_SEND, 546, 34, 24, 1, 30, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 31 */ 5, CNA_BEHAVIOR_SEND, 544, 34, 25, 1, 31, 1}, /* UserDefinedParkCmd */
    {/* Index 32 */ 5, CNA_BEHAVIOR_NONE, 548, 35, 26, 0, 32, 64}, /* HUT_ExternalDevice */
    {/* Index 33 */ 5, CNA_BEHAVIOR_UNSEND, 373, 29, 26, 1, 96, 1}, /* ApprLightSwt */
    {/* Index 34 */ 5, CNA_BEHAVIOR_UNSEND, 374, 29, 27, 1, 97, 1}, /* DrvSeatMassgModSet */
    {/* Index 35 */ 5, CNA_BEHAVIOR_NONE, 376, 29, 28, 0, 98, 1}, /* ElecSaveFuncMemSet */
    {/* Index 36 */ 5, CNA_BEHAVIOR_UNSEND, 372, 29, 28, 1, 99, 1}, /* LightShowSwt */
    {/* Index 37 */ 5, CNA_BEHAVIOR_UNSEND, 371, 29, 29, 1, 100, 1}, /* LockWelLightSwt */
    {/* Index 38 */ 5, CNA_BEHAVIOR_UNSEND, 375, 29, 30, 1, 101, 1}, /* PLG_HeightSet */
    {/* Index 39 */ 5, CNA_BEHAVIOR_UNSEND, 370, 29, 31, 1, 102, 1}, /* UnlockWelLightSwt */
    {/* Index 40 */ 5, CNA_BEHAVIOR_UNSEND, 369, 29, 32, 1, 103, 1}, /* WelLightMainSwt */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 341, 25, 33, 1, 104, 1}, /* ACMaxReq_TC */
    {/* Index 42 */ 5, CNA_BEHAVIOR_SEND, 340, 25, 34, 1, 105, 1}, /* ACMaxReq_VR */
    {/* Index 43 */ 5, CNA_BEHAVIOR_NONE, 339, 25, 35, 0, 106, 1}, /* LockWinSet */
    {/* Index 44 */ 5, CNA_BEHAVIOR_SEND, 267, 21, 35, 1, 107, 1}, /* BackReq_AVM */
    {/* Index 45 */ 5, CNA_BEHAVIOR_NONE, 278, 21, 36, 0, 108, 1}, /* CancelVoiceIdn */
    {/* Index 46 */ 5, CNA_BEHAVIOR_NONE, 281, 21, 36, 0, 109, 1}, /* DeleteUserIDFaceData */
    {/* Index 47 */ 5, CNA_BEHAVIOR_NONE, 282, 21, 36, 0, 110, 1}, /* DeleteUserIDVoiceData */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 272, 21, 36, 0, 111, 1}, /* DistrctnDetnSet */
    {/* Index 49 */ 5, CNA_BEHAVIOR_NONE, 273, 21, 36, 0, 112, 1}, /* DrowsnsDetnSet */
    {/* Index 50 */ 5, CNA_BEHAVIOR_NONE, 279, 21, 36, 0, 113, 1}, /* EnrollFaceReq */
    {/* Index 51 */ 5, CNA_BEHAVIOR_NONE, 280, 21, 36, 0, 114, 1}, /* EnrollUserIDResult */
    {/* Index 52 */ 5, CNA_BEHAVIOR_NONE, 276, 21, 36, 0, 115, 1}, /* EraseAllFaceUsersReq */
    {/* Index 53 */ 5, CNA_BEHAVIOR_NONE, 277, 21, 36, 0, 116, 1}, /* EraseAllVoiceUsersReq */
    {/* Index 54 */ 5, CNA_BEHAVIOR_NONE, 271, 21, 36, 0, 117, 1}, /* ExprsnSetUp */
    {/* Index 55 */ 5, CNA_BEHAVIOR_NONE, 274, 21, 36, 0, 118, 1}, /* FaceIdnSet */
    {/* Index 56 */ 5, CNA_BEHAVIOR_SEND, 269, 21, 36, 1, 119, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 57 */ 5, CNA_BEHAVIOR_SEND, 268, 21, 37, 1, 120, 1}, /* HUD_HeightLvlSwt */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 270, 21, 38, 1, 121, 1}, /* HUD_SwtReq */
    {/* Index 59 */ 5, CNA_BEHAVIOR_NONE, 275, 21, 39, 0, 122, 1}, /* VoiceIdnSet */
    {/* Index 60 */ 5, CNA_BEHAVIOR_NONE, 348, 26, 39, 0, 123, 1}, /* ActvEntryLockSet */
    {/* Index 61 */ 5, CNA_BEHAVIOR_NONE, 347, 26, 39, 0, 124, 1}, /* ActvEntryUnlockSet */
    {/* Index 62 */ 5, CNA_BEHAVIOR_NONE, 344, 26, 39, 0, 125, 1}, /* BTAPAEntryLockSet */
    {/* Index 63 */ 5, CNA_BEHAVIOR_NONE, 345, 26, 39, 0, 126, 1}, /* BTAPALvngUnlockSet */
    {/* Index 64 */ 5, CNA_BEHAVIOR_NONE, 346, 26, 39, 0, 127, 1}, /* ClsWinSpdSet */
    {/* Index 65 */ 5, CNA_BEHAVIOR_UNSEND, 349, 26, 39, 1, 128, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 66 */ 5, CNA_BEHAVIOR_NONE, 343, 26, 40, 0, 129, 1}, /* LockPromptFunSet */
    {/* Index 67 */ 5, CNA_BEHAVIOR_SEND, 325, 23, 40, 1, 130, 1}, /* ACFGAChanTyp_TC */
    {/* Index 68 */ 5, CNA_BEHAVIOR_SEND, 324, 23, 41, 1, 131, 1}, /* ACFGAEnaReq_TC */
    {/* Index 69 */ 5, CNA_BEHAVIOR_SEND, 326, 23, 42, 1, 132, 1}, /* ACFGALvlReq_TC */
    {/* Index 70 */ 6, CNA_BEHAVIOR_NONE, 323, 23, 43, 0, 133, 1}, /* ALCMDynModSet */
    {/* Index 71 */ 6, CNA_BEHAVIOR_UNSEND, 305, 23, 43, 1, 134, 1}, /* ApproachLampSet */
    {/* Index 72 */ 5, CNA_BEHAVIOR_SEND, 313, 23, 44, 1, 135, 1}, /* BackReq_APS */
    {/* Index 73 */ 6, CNA_BEHAVIOR_SEND, 304, 23, 45, 1, 136, 1}, /* ChairMemPosnSetSwt */
    {/* Index 74 */ 5, CNA_BEHAVIOR_SEND, 317, 23, 46, 1, 137, 1}, /* DeletePath1Cmd */
    {/* Index 75 */ 5, CNA_BEHAVIOR_SEND, 315, 23, 47, 1, 138, 1}, /* DeletePath2Cmd */
    {/* Index 76 */ 6, CNA_BEHAVIOR_SEND, 321, 23, 48, 1, 139, 1}, /* DrvWinSwtReq_VR */
    {/* Index 77 */ 6, CNA_BEHAVIOR_UNSEND, 306, 23, 49, 1, 140, 1}, /* FlaoutUnlockSet */
    {/* Index 78 */ 6, CNA_BEHAVIOR_NONE, 303, 23, 50, 0, 141, 1}, /* MbrMonrEnReq_TC */
    {/* Index 79 */ 5, CNA_BEHAVIOR_SEND, 308, 23, 50, 1, 142, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 80 */ 5, CNA_BEHAVIOR_SEND, 312, 23, 51, 1, 143, 1}, /* ParkMdlCmd */
    {/* Index 81 */ 6, CNA_BEHAVIOR_SEND, 322, 23, 52, 1, 144, 1}, /* PassWinSwtReq_VR */
    {/* Index 82 */ 5, CNA_BEHAVIOR_SEND, 309, 23, 53, 1, 145, 1}, /* PathLrngFinshCmd */
    {/* Index 83 */ 5, CNA_BEHAVIOR_SEND, 310, 23, 54, 1, 146, 1}, /* PathLrngStartCmd */
    {/* Index 84 */ 6, CNA_BEHAVIOR_NONE, 307, 23, 55, 0, 147, 1}, /* PrkInDirChoice */
    {/* Index 85 */ 6, CNA_BEHAVIOR_SEND, 319, 23, 55, 1, 148, 1}, /* RLWinSwtReq_VR */
    {/* Index 86 */ 6, CNA_BEHAVIOR_SEND, 320, 23, 56, 1, 149, 1}, /* RRWinSwtReq_VR */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 311, 23, 57, 1, 150, 1}, /* SelPrkOutDirReq */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 318, 23, 58, 1, 151, 1}, /* SelPrkgFctnCmd */
    {/* Index 89 */ 5, CNA_BEHAVIOR_SEND, 316, 23, 59, 1, 152, 1}, /* StartPrkgPath1Cmd */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 314, 23, 60, 1, 153, 1}, /* StartPrkgPath2Cmd */
    {/* Index 91 */ 5, CNA_BEHAVIOR_NONE, 160, 11, 61, 0, 154, 1}, /* ABSLmpSet */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 152, 11, 61, 1, 155, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 165, 11, 62, 1, 156, 1}, /* ACEAHReq_TC */
    {/* Index 94 */ 5, CNA_BEHAVIOR_SEND, 166, 11, 63, 1, 157, 1}, /* ACEAHReq_VR */
    {/* Index 95 */ 5, CNA_BEHAVIOR_SEND, 149, 11, 64, 1, 158, 1}, /* ACOperMod_TC */
    {/* Index 96 */ 5, CNA_BEHAVIOR_SEND, 150, 11, 65, 1, 159, 1}, /* ACOperMod_VR */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 153, 11, 66, 1, 160, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 98 */ 5, CNA_BEHAVIOR_SEND, 157, 11, 67, 1, 161, 1}, /* APSPrkgTypSeln */
    {/* Index 99 */ 5, CNA_BEHAVIOR_SEND, 155, 11, 68, 1, 162, 1}, /* APSSwtReq_VR */
    {/* Index 100 */ 5, CNA_BEHAVIOR_NONE, 161, 11, 69, 0, 163, 1}, /* AutoWshWipSet */
    {/* Index 101 */ 5, CNA_BEHAVIOR_NONE, 164, 11, 69, 0, 164, 1}, /* DoorUnlockModSet */
    {/* Index 102 */ 5, CNA_BEHAVIOR_SEND, 156, 11, 69, 1, 165, 1}, /* PASExitSpdSwt */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 154, 11, 70, 1, 166, 1}, /* SDWSwtSet */
    {/* Index 104 */ 5, CNA_BEHAVIOR_NONE, 162, 11, 71, 0, 167, 1}, /* SeekVehSet */
    {/* Index 105 */ 5, CNA_BEHAVIOR_NONE, 163, 11, 71, 0, 168, 1}, /* SpdAutoLockModSet */
    {/* Index 106 */ 5, CNA_BEHAVIOR_SEND, 151, 11, 71, 1, 169, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 107 */ 5, CNA_BEHAVIOR_SEND, 159, 11, 72, 1, 170, 1}, /* SunRoofSwtReq_VR */
    {/* Index 108 */ 5, CNA_BEHAVIOR_SEND, 158, 11, 73, 1, 171, 1}, /* SunShadeSwtReq_VR */
    {/* Index 109 */ 5, CNA_BEHAVIOR_NONE, 378, 30, 74, 0, 172, 4}, /* AntiDisIdnResp */
    {/* Index 110 */ 5, CNA_BEHAVIOR_NONE, 379, 30, 74, 0, 176, 1}, /* DrvModMemSet */
    {/* Index 111 */ 5, CNA_BEHAVIOR_NONE, 249, 18, 74, 0, 177, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 112 */ 5, CNA_BEHAVIOR_NONE, 241, 18, 74, 0, 178, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 113 */ 5, CNA_BEHAVIOR_NONE, 250, 18, 74, 0, 179, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 114 */ 5, CNA_BEHAVIOR_NONE, 247, 18, 74, 0, 180, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 115 */ 5, CNA_BEHAVIOR_NONE, 252, 18, 74, 0, 181, 1}, /* ADAS_Stub_LastStub */
    {/* Index 116 */ 5, CNA_BEHAVIOR_NONE, 239, 18, 74, 0, 182, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 117 */ 5, CNA_BEHAVIOR_NONE, 255, 18, 74, 0, 183, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 118 */ 5, CNA_BEHAVIOR_NONE, 254, 18, 74, 0, 184, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 119 */ 5, CNA_BEHAVIOR_NONE, 240, 18, 74, 0, 185, 2}, /* ADAS_Stub_Offset */
    {/* Index 120 */ 5, CNA_BEHAVIOR_NONE, 248, 18, 74, 0, 187, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 242, 18, 74, 0, 188, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 122 */ 5, CNA_BEHAVIOR_NONE, 246, 18, 74, 0, 189, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 123 */ 5, CNA_BEHAVIOR_NONE, 244, 18, 74, 0, 190, 1}, /* ADAS_Stub_Retr */
    {/* Index 124 */ 5, CNA_BEHAVIOR_NONE, 253, 18, 74, 0, 191, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 125 */ 5, CNA_BEHAVIOR_NONE, 243, 18, 74, 0, 192, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 126 */ 5, CNA_BEHAVIOR_NONE, 251, 18, 74, 0, 193, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 127 */ 5, CNA_BEHAVIOR_NONE, 245, 18, 74, 0, 194, 1}, /* ADAS_Stub_Update */
    {/* Index 128 */ 5, CNA_BEHAVIOR_NONE, 224, 17, 74, 0, 195, 1}, /* ADAS_Seg_Brdg */
    {/* Index 129 */ 5, CNA_BEHAVIOR_NONE, 225, 17, 74, 0, 196, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 130 */ 5, CNA_BEHAVIOR_NONE, 231, 17, 74, 0, 197, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 131 */ 5, CNA_BEHAVIOR_NONE, 221, 17, 74, 0, 198, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 132 */ 5, CNA_BEHAVIOR_NONE, 235, 17, 74, 0, 199, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 133 */ 5, CNA_BEHAVIOR_NONE, 233, 17, 74, 0, 200, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 134 */ 5, CNA_BEHAVIOR_NONE, 234, 17, 74, 0, 201, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 135 */ 5, CNA_BEHAVIOR_NONE, 232, 17, 74, 0, 202, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 136 */ 5, CNA_BEHAVIOR_NONE, 229, 17, 74, 0, 203, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 137 */ 5, CNA_BEHAVIOR_NONE, 219, 17, 74, 0, 204, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 138 */ 5, CNA_BEHAVIOR_NONE, 237, 17, 74, 0, 205, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 139 */ 5, CNA_BEHAVIOR_NONE, 236, 17, 74, 0, 206, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 140 */ 5, CNA_BEHAVIOR_NONE, 220, 17, 74, 0, 207, 2}, /* ADAS_Seg_Offset */
    {/* Index 141 */ 5, CNA_BEHAVIOR_NONE, 230, 17, 74, 0, 209, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 142 */ 5, CNA_BEHAVIOR_NONE, 222, 17, 74, 0, 210, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 143 */ 5, CNA_BEHAVIOR_NONE, 228, 17, 74, 0, 211, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 144 */ 5, CNA_BEHAVIOR_NONE, 226, 17, 74, 0, 212, 1}, /* ADAS_Seg_Retr */
    {/* Index 145 */ 5, CNA_BEHAVIOR_NONE, 223, 17, 74, 0, 213, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 146 */ 5, CNA_BEHAVIOR_NONE, 227, 17, 74, 0, 214, 1}, /* ADAS_Seg_Update */
    {/* Index 147 */ 5, CNA_BEHAVIOR_NONE, 214, 16, 74, 0, 215, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 148 */ 5, CNA_BEHAVIOR_NONE, 211, 16, 74, 0, 216, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 149 */ 5, CNA_BEHAVIOR_NONE, 208, 16, 74, 0, 217, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 150 */ 5, CNA_BEHAVIOR_NONE, 215, 16, 74, 0, 218, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 151 */ 5, CNA_BEHAVIOR_NONE, 206, 16, 74, 0, 220, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 152 */ 5, CNA_BEHAVIOR_NONE, 207, 16, 74, 0, 221, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 153 */ 5, CNA_BEHAVIOR_NONE, 209, 16, 74, 0, 223, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 154 */ 5, CNA_BEHAVIOR_NONE, 210, 16, 74, 0, 224, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 155 */ 5, CNA_BEHAVIOR_NONE, 212, 16, 74, 0, 225, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 156 */ 5, CNA_BEHAVIOR_NONE, 213, 16, 74, 0, 226, 1}, /* ADAS_ProfShort_Update */
    {/* Index 157 */ 5, CNA_BEHAVIOR_NONE, 216, 16, 74, 0, 227, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 158 */ 5, CNA_BEHAVIOR_NONE, 217, 16, 74, 0, 229, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 159 */ 5, CNA_BEHAVIOR_NONE, 201, 15, 74, 0, 231, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 160 */ 5, CNA_BEHAVIOR_NONE, 198, 15, 74, 0, 232, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 161 */ 5, CNA_BEHAVIOR_NONE, 196, 15, 74, 0, 233, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 197, 15, 74, 0, 234, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 163 */ 5, CNA_BEHAVIOR_NONE, 199, 15, 74, 0, 236, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 164 */ 5, CNA_BEHAVIOR_NONE, 200, 15, 74, 0, 237, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 165 */ 5, CNA_BEHAVIOR_NONE, 202, 15, 74, 0, 238, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 166 */ 5, CNA_BEHAVIOR_NONE, 203, 15, 74, 0, 239, 1}, /* ADAS_ProfLong_Update */
    {/* Index 167 */ 5, CNA_BEHAVIOR_NONE, 204, 15, 74, 0, 240, 4}, /* ADAS_ProfLong_Value */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 132, 9, 74, 1, 244, 1}, /* ACAIUReq_VR */
    {/* Index 169 */ 5, CNA_BEHAVIOR_SEND, 129, 9, 75, 1, 245, 1}, /* ACAQSReq_VR */
    {/* Index 170 */ 5, CNA_BEHAVIOR_SEND, 128, 9, 76, 1, 246, 1}, /* ACDualReq_VR */
    {/* Index 171 */ 5, CNA_BEHAVIOR_SEND, 131, 9, 77, 1, 247, 1}, /* ACPassTempReq_VR */
    {/* Index 172 */ 5, CNA_BEHAVIOR_SEND, 130, 9, 78, 1, 248, 1}, /* ACRearDefrstReq_VR */
    {/* Index 173 */ 5, CNA_BEHAVIOR_NONE, 136, 9, 79, 0, 249, 1}, /* ALCMClrSet */
    {/* Index 174 */ 5, CNA_BEHAVIOR_NONE, 135, 9, 79, 0, 250, 1}, /* ALCMDynSwt */
    {/* Index 175 */ 5, CNA_BEHAVIOR_NONE, 137, 9, 79, 0, 251, 1}, /* ALCMRhmSwt */
    {/* Index 176 */ 5, CNA_BEHAVIOR_NONE, 134, 9, 79, 0, 252, 1}, /* ALCMStatSwt */
    {/* Index 177 */ 5, CNA_BEHAVIOR_UNSEND, 127, 9, 79, 1, 253, 1}, /* HUT_EgyRecvrySet */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 133, 9, 80, 0, 254, 1}, /* IPVolSet */
    {/* Index 179 */ 5, CNA_BEHAVIOR_SEND, 138, 9, 80, 1, 255, 1}, /* PASSwtReq_VR */
    {/* Index 180 */ 5, CNA_BEHAVIOR_NONE, 257, 19, 81, 0, 256, 1}, /* CarWashMode_Req */
    {/* Index 181 */ 5, CNA_BEHAVIOR_NONE, 260, 19, 81, 0, 257, 1}, /* HUT_BattKeepTemp */
    {/* Index 182 */ 5, CNA_BEHAVIOR_SEND, 262, 19, 81, 1, 258, 1}, /* HUT_BattSOCLim */
    {/* Index 183 */ 5, CNA_BEHAVIOR_UNSEND, 258, 19, 82, 1, 259, 1}, /* HUT_ChrgnMode */
    {/* Index 184 */ 5, CNA_BEHAVIOR_NONE, 263, 19, 83, 0, 260, 1}, /* HUT_IntelBattTempMagSet */
    {/* Index 185 */ 5, CNA_BEHAVIOR_NONE, 261, 19, 83, 0, 261, 1}, /* HUT_IntelEngIdlChrgnSet */
    {/* Index 186 */ 5, CNA_BEHAVIOR_SEND, 259, 19, 83, 1, 262, 1}, /* HUT_RemtEngCtrl */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 172, 13, 84, 0, 263, 1}, /* AVMMediaVolLvlReq */
    {/* Index 188 */ 5, CNA_BEHAVIOR_NONE, 170, 13, 84, 0, 264, 1}, /* AVMSwtReq */
    {/* Index 189 */ 5, CNA_BEHAVIOR_SEND, 175, 13, 84, 1, 265, 1}, /* BackgroundLightLvlSet */
    {/* Index 190 */ 5, CNA_BEHAVIOR_NONE, 177, 13, 85, 0, 266, 1}, /* DispModSet */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 173, 13, 85, 0, 267, 1}, /* FPASChanSwtReq */
    {/* Index 192 */ 5, CNA_BEHAVIOR_NONE, 176, 13, 85, 0, 268, 1}, /* ManCmpSet */
    {/* Index 193 */ 5, CNA_BEHAVIOR_NONE, 171, 13, 85, 0, 269, 1}, /* NaviMediaVolLvlReq */
    {/* Index 194 */ 5, CNA_BEHAVIOR_UNSEND, 178, 13, 85, 1, 270, 1}, /* OPDSwtSts */
    {/* Index 195 */ 5, CNA_BEHAVIOR_UNSEND, 179, 13, 86, 1, 271, 1}, /* PLGReq_VR */
    {/* Index 196 */ 5, CNA_BEHAVIOR_NONE, 174, 13, 87, 0, 272, 1}, /* RPASChanSwtReq */
    {/* Index 197 */ 5, CNA_BEHAVIOR_UNSEND, 180, 13, 87, 1, 273, 1}, /* WPC_SwtReq */
    {/* Index 198 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 88, 1, 274, 1}, /* ACAIUReq_TC */
    {/* Index 199 */ 5, CNA_BEHAVIOR_SEND, 42, 3, 89, 1, 275, 1}, /* ACAQSReq_TC */
    {/* Index 200 */ 5, CNA_BEHAVIOR_SEND, 41, 3, 90, 1, 276, 1}, /* ACAirInletReq_TC */
    {/* Index 201 */ 5, CNA_BEHAVIOR_SEND, 40, 3, 91, 1, 277, 1}, /* ACAutoModReq_TC */
    {/* Index 202 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 92, 1, 278, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 203 */ 5, CNA_BEHAVIOR_SEND, 43, 3, 93, 1, 279, 1}, /* ACCmprReq_TC */
    {/* Index 204 */ 5, CNA_BEHAVIOR_SEND, 48, 3, 94, 1, 280, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 205 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 95, 1, 281, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 206 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 96, 1, 282, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 207 */ 5, CNA_BEHAVIOR_SEND, 39, 3, 97, 1, 283, 1}, /* ACDualReq_TC */
    {/* Index 208 */ 5, CNA_BEHAVIOR_SEND, 45, 3, 98, 1, 284, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 209 */ 5, CNA_BEHAVIOR_SEND, 47, 3, 99, 1, 285, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 210 */ 5, CNA_BEHAVIOR_SEND, 44, 3, 100, 1, 286, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 211 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 101, 1, 287, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 212 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 102, 1, 288, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 213 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 103, 1, 289, 1}, /* ACOffReq_TC */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 38, 3, 104, 0, 290, 1}, /* BattSaveDelayTimeSet */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 50, 3, 104, 0, 291, 1}, /* ChairMemPosnEna */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 34, 3, 104, 0, 292, 1}, /* DomeLmpDlyTimSet */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 104, 0, 293, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 35, 3, 104, 0, 294, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 37, 3, 104, 0, 295, 1}, /* RearviewFoldModSet */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 36, 3, 104, 0, 296, 1}, /* TranPMode_Req */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 62, 4, 104, 0, 297, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 60, 4, 104, 0, 298, 1}, /* AMP_BeepSourceSet */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 63, 4, 104, 0, 299, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 68, 4, 104, 0, 300, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 61, 4, 104, 0, 301, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 64, 4, 104, 0, 302, 1}, /* AMP_LRDrvSideSet */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 65, 4, 104, 0, 303, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 58, 4, 104, 0, 304, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 67, 4, 104, 0, 305, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 66, 4, 104, 0, 306, 1}, /* AMP_MuteSet */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 59, 4, 104, 0, 307, 1}, /* AMP_NaviSourceSet */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 71, 4, 104, 0, 308, 1}, /* ANCSwtSet */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 73, 4, 104, 0, 309, 1}, /* FrntWinHeatSwt */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 70, 4, 104, 0, 310, 1}, /* QLISurroundSet */
    {/* Index 235 */ 5, CNA_BEHAVIOR_SEND, 72, 4, 104, 1, 311, 1}, /* RearWinHeatCmd_TC */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 69, 4, 105, 0, 312, 1}, /* T_box_ECallSet */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 86, 5, 105, 0, 313, 1}, /* AMP_BestListegPosnReq */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 87, 5, 105, 0, 314, 1}, /* AMP_Clari_FiReq */
    {/* Index 239 */ 5, CNA_BEHAVIOR_SEND, 83, 5, 105, 1, 315, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 240 */ 5, CNA_BEHAVIOR_SEND, 80, 5, 106, 1, 316, 1}, /* AMP_GetHWInfoReq */
    {/* Index 241 */ 5, CNA_BEHAVIOR_SEND, 82, 5, 107, 1, 317, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 242 */ 5, CNA_BEHAVIOR_SEND, 79, 5, 108, 1, 318, 1}, /* AMP_GetSWInfoReq */
    {/* Index 243 */ 5, CNA_BEHAVIOR_SEND, 81, 5, 109, 1, 319, 1}, /* AMP_GetTempInfoReq */
    {/* Index 244 */ 5, CNA_BEHAVIOR_NONE, 75, 5, 110, 0, 320, 1}, /* AMP_HFMVolSet */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 78, 5, 110, 0, 321, 1}, /* AMP_MainVolSet */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 77, 5, 110, 0, 322, 1}, /* AMP_NaviVolSet */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 76, 5, 110, 0, 323, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 85, 5, 110, 0, 324, 1}, /* IESS_MdlInfoReq */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 84, 5, 110, 0, 325, 1}, /* IESS_MdlSwtReq */
    {/* Index 250 */ 5, CNA_BEHAVIOR_SEND, 100, 6, 110, 1, 326, 1}, /* ACAirInletReq_VR */
    {/* Index 251 */ 5, CNA_BEHAVIOR_SEND, 93, 6, 111, 1, 327, 1}, /* ACAutoModReq_VR */
    {/* Index 252 */ 5, CNA_BEHAVIOR_SEND, 96, 6, 112, 1, 328, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 253 */ 5, CNA_BEHAVIOR_SEND, 94, 6, 113, 1, 329, 1}, /* ACCmprReq_VR */
    {/* Index 254 */ 5, CNA_BEHAVIOR_SEND, 99, 6, 114, 1, 330, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 255 */ 5, CNA_BEHAVIOR_SEND, 97, 6, 115, 1, 331, 1}, /* ACDrvTempReq_VR */
    {/* Index 256 */ 5, CNA_BEHAVIOR_SEND, 98, 6, 116, 1, 332, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 101, 6, 117, 0, 333, 1}, /* ACModReq_HUT */
    {/* Index 258 */ 5, CNA_BEHAVIOR_SEND, 95, 6, 117, 1, 334, 1}, /* ACPowerReq_VR */
    {/* Index 259 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 118, 0, 335, 1}, /* AllTerrainDislSet */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 89, 6, 118, 0, 336, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 91, 6, 118, 0, 337, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 102, 6, 118, 0, 338, 1}, /* ElecSideSteppingSysSet */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 90, 6, 118, 0, 339, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 92, 6, 118, 0, 340, 1}, /* PassSeatVentnLvlSet */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 105, 6, 118, 0, 341, 1}, /* RemUpgrdSts */
    {/* Index 266 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 118, 0, 342, 1}, /* RoofModSet */
    {/* Index 267 */ 5, CNA_BEHAVIOR_CYCLE, 363, 28, 118, 1, 343, 1}, /* RearFogLmpSwtSts_HUT */
    {/* Index 268 */ 5, CNA_BEHAVIOR_CYCLE, 292, 22, 119, 1, 344, 1}, /* ContnPrkgReq */
    {/* Index 269 */ 5, CNA_BEHAVIOR_CYCLE, 290, 22, 120, 1, 345, 1}, /* PrkgCtrlModReq */
    {/* Index 270 */ 5, CNA_BEHAVIOR_CYCLE, 428, 31, 121, 1, 346, 1}, /* ChairMemPosnSet */
    {/* Index 271 */ 5, CNA_BEHAVIOR_CYCLE, 406, 31, 122, 1, 347, 1}, /* EPSSteerModSwtReq */
    {/* Index 272 */ 5, CNA_BEHAVIOR_CYCLE, 417, 31, 123, 1, 348, 1}, /* HUT_DrvModReq */
    {/* Index 273 */ 5, CNA_BEHAVIOR_CYCLE, 143, 10, 124, 1, 349, 1}, /* HUT_AVHSwitchSts */
    {/* Index 274 */ 5, CNA_BEHAVIOR_CYCLE, 145, 10, 125, 1, 350, 1}, /* HUT_EPB_SwtPosn */
    {/* Index 275 */ 5, CNA_BEHAVIOR_CYCLE, 144, 10, 126, 1, 351, 1}, /* HUT_HDCSwitchCtrl */
    {/* Index 276 */ 5, CNA_BEHAVIOR_CYCLE, 146, 10, 127, 1, 352, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[277] = {0u};
static const uint8 cna_noActionBuffer[128] =
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
    4u,
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
    3u,
    0u,
    6u,
    3u,
    0u,
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
    3u,
    10u,
    0u,
    0u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[581] =
{
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    216,
    218,
    220,
    219,
    214,
    207,
    201,
    200,
    199,
    203,
    210,
    208,
    217,
    209,
    204,
    205,
    215,
    206,
    211,
    212,
    198,
    213,
    202,
    65535,
    228,
    231,
    222,
    225,
    221,
    223,
    226,
    227,
    230,
    229,
    224,
    236,
    234,
    232,
    235,
    233,
    65535,
    244,
    247,
    246,
    245,
    242,
    240,
    243,
    241,
    239,
    249,
    248,
    237,
    238,
    65535,
    260,
    263,
    261,
    264,
    251,
    253,
    258,
    252,
    255,
    256,
    254,
    250,
    257,
    262,
    266,
    259,
    265,
    65535,
    1,
    2,
    9,
    11,
    13,
    8,
    14,
    15,
    4,
    12,
    6,
    5,
    3,
    7,
    10,
    17,
    16,
    65535,
    0,
    65535,
    177,
    170,
    169,
    172,
    171,
    168,
    178,
    176,
    174,
    173,
    175,
    179,
    65535,
    65535,
    65535,
    65535,
    273,
    275,
    274,
    276,
    65535,
    65535,
    95,
    96,
    106,
    92,
    97,
    103,
    99,
    102,
    98,
    108,
    107,
    91,
    100,
    104,
    105,
    101,
    93,
    94,
    65535,
    65535,
    65535,
    188,
    193,
    187,
    191,
    196,
    189,
    192,
    190,
    194,
    195,
    197,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    161,
    162,
    160,
    163,
    164,
    159,
    165,
    166,
    167,
    65535,
    151,
    152,
    149,
    153,
    154,
    148,
    155,
    156,
    147,
    150,
    157,
    158,
    65535,
    137,
    140,
    131,
    142,
    145,
    128,
    129,
    144,
    146,
    143,
    136,
    141,
    130,
    135,
    133,
    134,
    132,
    139,
    138,
    65535,
    116,
    119,
    112,
    121,
    125,
    123,
    127,
    122,
    114,
    120,
    111,
    113,
    126,
    115,
    124,
    118,
    117,
    65535,
    180,
    183,
    186,
    181,
    185,
    182,
    184,
    65535,
    65535,
    65535,
    44,
    57,
    56,
    58,
    54,
    48,
    49,
    55,
    59,
    52,
    53,
    45,
    50,
    51,
    46,
    47,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    269,
    65535,
    268,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    78,
    73,
    71,
    77,
    84,
    79,
    82,
    83,
    87,
    80,
    72,
    90,
    75,
    89,
    74,
    88,
    85,
    86,
    76,
    81,
    70,
    68,
    67,
    69,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    43,
    42,
    41,
    65535,
    66,
    62,
    63,
    64,
    61,
    60,
    65,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    267,
    65535,
    65535,
    65535,
    65535,
    65535,
    40,
    39,
    37,
    36,
    33,
    34,
    38,
    35,
    65535,
    109,
    110,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    271,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    272,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    270,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    25,
    28,
    26,
    19,
    21,
    27,
    20,
    22,
    23,
    24,
    29,
    31,
    18,
    30,
    65535,
    32,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
};

static uint8 cna_currentBuffer[353] = {0};

const CNA_ConfigType cna_config =
{
    277u,
    cna_signalConfigs,
    cna_signalDatas,
    128u,
    cna_noActionBuffer,
    353u,
    cna_currentBuffer,
    581u,
    CNA_IdTable
};


