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
static const CNA_SignalConfigType cna_signalConfigs[279] =
{
    {5, CNA_BEHAVIOR_NONE, 137, 8, 0, 0, 0, 1},/*ChairRestSetSwt*/
    {5, CNA_BEHAVIOR_NONE, 135, 8, 0, 0, 1, 1},/*ChildLockCmd*/
    {5, CNA_BEHAVIOR_UNSEND, 133, 8, 0, 1, 2, 1},/*HUT_VMDRInitAlarmDlySet*/
    {5, CNA_BEHAVIOR_UNSEND, 132, 8, 1, 1, 3, 1},/*HUT_VMDRTmpMonFctnSet*/
    {5, CNA_BEHAVIOR_NONE, 136, 8, 2, 0, 4, 1},/*MiaoCallClsReq*/
    {5, CNA_BEHAVIOR_NONE, 134, 8, 2, 0, 5, 1},/*OTA_UpgrdModReq*/
    {5, CNA_BEHAVIOR_NONE, 115, 7, 2, 0, 6, 1},/*AUTODefrost_TC*/
    {5, CNA_BEHAVIOR_SEND, 116, 7, 2, 1, 7, 1},/*AUTODefrost_VR*/
    {5, CNA_BEHAVIOR_SEND, 128, 7, 3, 1, 8, 1},/*AutoAVMSwSet_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 124, 7, 4, 1, 9, 1},/*AutoViewChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 127, 7, 5, 1, 10, 1},/*CarMdlDispCmd*/
    {5, CNA_BEHAVIOR_SEND, 126, 7, 6, 1, 11, 1},/*CarMdlTrsprcySwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 113, 7, 7, 1, 12, 1},/*FPAS_AutoModSwt*/
    {5, CNA_BEHAVIOR_SEND, 121, 7, 8, 1, 13, 1},/*Guid_Ovl_Display_Cmd*/
    {5, CNA_BEHAVIOR_NONE, 117, 7, 9, 0, 14, 1},/*HUT_VCUBattKeepTemp*/
    {5, CNA_BEHAVIOR_SEND, 118, 7, 9, 1, 15, 1},/*LaneCalActvtCmd*/
    {5, CNA_BEHAVIOR_SEND, 114, 7, 10, 1, 16, 1},/*MEBSwtSet*/
    {5, CNA_BEHAVIOR_SEND, 119, 7, 11, 1, 17, 1},/*MODChgReq*/
    {5, CNA_BEHAVIOR_SEND, 125, 7, 12, 1, 18, 1},/*MdlColrChgCmd*/
    {5, CNA_BEHAVIOR_UNSEND, 120, 7, 13, 1, 19, 1},/*Radar_DispCmd*/
    {5, CNA_BEHAVIOR_SEND, 122, 7, 14, 1, 20, 1},/*Sgl_View_Sel*/
    {5, CNA_BEHAVIOR_SEND, 123, 7, 15, 1, 21, 1},/*SwToFieldCalRstCmd*/
    {5, CNA_BEHAVIOR_SEND, 130, 7, 16, 1, 22, 1},/*View_SoftswitchCmd*/
    {5, CNA_BEHAVIOR_SEND, 129, 7, 17, 1, 23, 1},/*WshSoftSwt*/
    {5, CNA_BEHAVIOR_SEND, 542, 37, 18, 1, 24, 1},/*HUT_HAVP_APA_Permit*/
    {5, CNA_BEHAVIOR_SEND, 541, 37, 19, 1, 25, 1},/*HUT_HAVP_Return_Btn*/
    {5, CNA_BEHAVIOR_SEND, 544, 37, 20, 1, 26, 1},/*HUT_HAVP_SelfParLot_Ending*/
    {5, CNA_BEHAVIOR_SEND, 545, 37, 21, 1, 27, 1},/*HUT_HAVP_Set_Path_Ending*/
    {5, CNA_BEHAVIOR_NONE, 543, 37, 22, 0, 28, 1},/*HUT_HAVP_Set_Starting*/
    {5, CNA_BEHAVIOR_SEND, 546, 37, 22, 1, 29, 1},/*SlotNum_VR*/
    {5, CNA_BEHAVIOR_SEND, 547, 37, 23, 1, 30, 1},/*UserDefPrkMenuSelCmd*/
    {5, CNA_BEHAVIOR_SEND, 548, 37, 24, 1, 31, 1},/*UserDefinedParkCmd*/
    {5, CNA_BEHAVIOR_NONE, 550, 38, 25, 0, 32, 64},/*HUT_ExternalDevice*/
    {5, CNA_BEHAVIOR_UNSEND, 398, 33, 25, 1, 96, 1},/*DrvSeatMassgModSet*/
    {5, CNA_BEHAVIOR_NONE, 399, 33, 26, 0, 97, 1},/*HUT_V2LStart*/
    {5, CNA_BEHAVIOR_NONE, 400, 33, 26, 0, 98, 1},/*PLG_HeightSet*/
    {5, CNA_BEHAVIOR_NONE, 349, 26, 26, 0, 99, 1},/*ACMaxReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 348, 26, 26, 1, 100, 1},/*ACMaxReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 346, 26, 27, 0, 101, 1},/*ActvEnterSet*/
    {5, CNA_BEHAVIOR_NONE, 347, 26, 27, 0, 102, 1},/*ActvLeaveSet*/
    {5, CNA_BEHAVIOR_SEND, 351, 27, 27, 1, 103, 1},/*DrvDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 352, 27, 28, 1, 104, 1},/*LRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 355, 27, 29, 1, 105, 1},/*LeftPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 353, 27, 30, 1, 106, 1},/*PassDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 354, 27, 31, 1, 107, 1},/*RRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 356, 27, 32, 1, 108, 1},/*RightPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 289, 22, 33, 1, 109, 1},/*BackReq_AVM*/
    {5, CNA_BEHAVIOR_SEND, 359, 28, 34, 1, 110, 1},/*DrvDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_UNSEND, 358, 28, 35, 1, 111, 1},/*DrvSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 360, 28, 36, 1, 112, 1},/*LRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 361, 28, 37, 1, 113, 1},/*PassDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 332, 24, 38, 1, 114, 1},/*ACFGAChanTyp_TC*/
    {5, CNA_BEHAVIOR_SEND, 331, 24, 39, 1, 115, 1},/*ACFGAEnaReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 333, 24, 40, 1, 116, 1},/*ACFGALvlReq_TC*/
    {6, CNA_BEHAVIOR_NONE, 330, 24, 41, 0, 117, 1},/*ALCMDynModSet*/
    {6, CNA_BEHAVIOR_UNSEND, 317, 24, 41, 1, 118, 1},/*ApproachLampSet*/
    {5, CNA_BEHAVIOR_SEND, 324, 24, 42, 1, 119, 1},/*BackReq_APS*/
    {6, CNA_BEHAVIOR_SEND, 316, 24, 43, 1, 120, 1},/*ChairMemPosnSetSwt*/
    {5, CNA_BEHAVIOR_SEND, 328, 24, 44, 1, 121, 1},/*DeletePath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 326, 24, 45, 1, 122, 1},/*DeletePath2Cmd*/
    {6, CNA_BEHAVIOR_SEND, 314, 24, 46, 1, 123, 1},/*DrvWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_UNSEND, 318, 24, 47, 1, 124, 1},/*FlaoutUnlockSet*/
    {5, CNA_BEHAVIOR_SEND, 323, 24, 48, 1, 125, 1},/*ParkMdlCmd*/
    {6, CNA_BEHAVIOR_SEND, 315, 24, 49, 1, 126, 1},/*PassWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 320, 24, 50, 1, 127, 1},/*PathLrngFinshCmd*/
    {5, CNA_BEHAVIOR_SEND, 321, 24, 51, 1, 128, 1},/*PathLrngStartCmd*/
    {6, CNA_BEHAVIOR_NONE, 319, 24, 52, 0, 129, 1},/*PrkInDirChoice*/
    {6, CNA_BEHAVIOR_SEND, 312, 24, 52, 1, 130, 1},/*RLWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_SEND, 313, 24, 53, 1, 131, 1},/*RRWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 322, 24, 54, 1, 132, 1},/*SelPrkOutDirReq*/
    {5, CNA_BEHAVIOR_SEND, 329, 24, 55, 1, 133, 1},/*SelPrkgFctnCmd*/
    {5, CNA_BEHAVIOR_SEND, 327, 24, 56, 1, 134, 1},/*StartPrkgPath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 325, 24, 57, 1, 135, 1},/*StartPrkgPath2Cmd*/
    {5, CNA_BEHAVIOR_NONE, 176, 11, 58, 0, 136, 1},/*ABSLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 170, 11, 58, 1, 137, 1},/*ACDrvSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 182, 11, 59, 0, 138, 1},/*ACEAHReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 183, 11, 59, 1, 139, 1},/*ACEAHReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 168, 11, 60, 0, 140, 1},/*ACOperMod_TC*/
    {5, CNA_BEHAVIOR_SEND, 169, 11, 60, 1, 141, 1},/*ACOperMod_VR*/
    {5, CNA_BEHAVIOR_SEND, 184, 11, 61, 1, 142, 1},/*APSPrkgTypSeln*/
    {5, CNA_BEHAVIOR_SEND, 172, 11, 62, 1, 143, 1},/*APSSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 177, 11, 63, 0, 144, 1},/*AutoWshWipSet*/
    {5, CNA_BEHAVIOR_NONE, 181, 11, 63, 0, 145, 1},/*DoorUnlockModSet*/
    {5, CNA_BEHAVIOR_SEND, 185, 11, 63, 1, 146, 1},/*PASExitSpdSwt*/
    {5, CNA_BEHAVIOR_NONE, 180, 11, 64, 0, 147, 1},/*ParkLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 171, 11, 64, 1, 148, 1},/*SDWSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 178, 11, 65, 0, 149, 1},/*SeekVehSet*/
    {5, CNA_BEHAVIOR_NONE, 179, 11, 65, 0, 150, 1},/*SpdAutoLockModSet*/
    {5, CNA_BEHAVIOR_NONE, 175, 11, 65, 0, 151, 1},/*SportModLightSet*/
    {5, CNA_BEHAVIOR_SEND, 187, 11, 65, 1, 152, 1},/*SteerWheelHeatSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 174, 11, 66, 1, 153, 1},/*SunRoofSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 173, 11, 67, 1, 154, 1},/*SunShadeSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 186, 11, 68, 0, 155, 1},/*VehStsChngReq*/
    {5, CNA_BEHAVIOR_NONE, 391, 31, 68, 0, 156, 1},/*HUT_AccelPedalSnvtyAdj*/
    {5, CNA_BEHAVIOR_NONE, 384, 31, 68, 0, 157, 1},/*HUT_ChrgnMod*/
    {5, CNA_BEHAVIOR_UNSEND, 389, 31, 68, 1, 158, 1},/*HUT_CreepSwt*/
    {5, CNA_BEHAVIOR_NONE, 385, 31, 69, 0, 159, 1},/*HUT_DelayTimMod*/
    {5, CNA_BEHAVIOR_NONE, 387, 31, 69, 0, 160, 2},/*HUT_EndHourMin*/
    {5, CNA_BEHAVIOR_NONE, 390, 31, 69, 0, 162, 1},/*HUT_EneRecoInteAdj*/
    {5, CNA_BEHAVIOR_NONE, 388, 31, 69, 0, 163, 1},/*HUT_IndDrvgModReq*/
    {5, CNA_BEHAVIOR_NONE, 386, 31, 69, 0, 164, 2},/*HUT_StrtHourMin*/
    {5, CNA_BEHAVIOR_NONE, 382, 30, 69, 0, 166, 1},/*ALCMBreSwt*/
    {5, CNA_BEHAVIOR_SEND, 377, 30, 69, 1, 167, 1},/*DrvDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 378, 30, 70, 1, 168, 1},/*LRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 375, 30, 71, 1, 169, 1},/*LeftPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 381, 30, 72, 1, 170, 1},/*LeftPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 379, 30, 73, 1, 171, 1},/*PassDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 374, 30, 74, 1, 172, 1},/*RRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 380, 30, 75, 1, 173, 1},/*RRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 376, 30, 76, 1, 174, 1},/*RightPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 373, 30, 77, 1, 175, 1},/*RightPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 273, 18, 78, 0, 176, 1},/*ADAS_Stub_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 265, 18, 78, 0, 177, 1},/*ADAS_Stub_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 274, 18, 78, 0, 178, 1},/*ADAS_Stub_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 271, 18, 78, 0, 179, 1},/*ADAS_Stub_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 276, 18, 78, 0, 180, 1},/*ADAS_Stub_LastStub*/
    {5, CNA_BEHAVIOR_NONE, 263, 18, 78, 0, 181, 1},/*ADAS_Stub_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 279, 18, 78, 0, 182, 1},/*ADAS_Stub_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 278, 18, 78, 0, 183, 1},/*ADAS_Stub_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 264, 18, 78, 0, 184, 2},/*ADAS_Stub_Offset*/
    {5, CNA_BEHAVIOR_NONE, 272, 18, 78, 0, 186, 1},/*ADAS_Stub_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 266, 18, 78, 0, 187, 1},/*ADAS_Stub_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 270, 18, 78, 0, 188, 1},/*ADAS_Stub_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 268, 18, 78, 0, 189, 1},/*ADAS_Stub_Retr*/
    {5, CNA_BEHAVIOR_NONE, 277, 18, 78, 0, 190, 1},/*ADAS_Stub_RtOfWay*/
    {5, CNA_BEHAVIOR_NONE, 267, 18, 78, 0, 191, 1},/*ADAS_Stub_StubPathIdx*/
    {5, CNA_BEHAVIOR_NONE, 275, 18, 78, 0, 192, 1},/*ADAS_Stub_TurnAngl*/
    {5, CNA_BEHAVIOR_NONE, 269, 18, 78, 0, 193, 1},/*ADAS_Stub_Update*/
    {5, CNA_BEHAVIOR_NONE, 248, 17, 78, 0, 194, 1},/*ADAS_Seg_Brdg*/
    {5, CNA_BEHAVIOR_NONE, 249, 17, 78, 0, 195, 1},/*ADAS_Seg_BuildUpArea*/
    {5, CNA_BEHAVIOR_NONE, 255, 17, 78, 0, 196, 1},/*ADAS_Seg_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 245, 17, 78, 0, 197, 1},/*ADAS_Seg_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 259, 17, 78, 0, 198, 1},/*ADAS_Seg_DivideRoad*/
    {5, CNA_BEHAVIOR_NONE, 257, 17, 78, 0, 199, 1},/*ADAS_Seg_EffSpdLmt*/
    {5, CNA_BEHAVIOR_NONE, 258, 17, 78, 0, 200, 1},/*ADAS_Seg_EffSpdLmtTyp*/
    {5, CNA_BEHAVIOR_NONE, 256, 17, 78, 0, 201, 1},/*ADAS_Seg_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 253, 17, 78, 0, 202, 1},/*ADAS_Seg_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 243, 17, 78, 0, 203, 1},/*ADAS_Seg_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 261, 17, 78, 0, 204, 1},/*ADAS_Seg_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 260, 17, 78, 0, 205, 1},/*ADAS_Seg_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 244, 17, 78, 0, 206, 2},/*ADAS_Seg_Offset*/
    {5, CNA_BEHAVIOR_NONE, 254, 17, 78, 0, 208, 1},/*ADAS_Seg_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 246, 17, 78, 0, 209, 1},/*ADAS_Seg_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 252, 17, 78, 0, 210, 1},/*ADAS_Seg_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 250, 17, 78, 0, 211, 1},/*ADAS_Seg_Retr*/
    {5, CNA_BEHAVIOR_NONE, 247, 17, 78, 0, 212, 1},/*ADAS_Seg_Tunnel*/
    {5, CNA_BEHAVIOR_NONE, 251, 17, 78, 0, 213, 1},/*ADAS_Seg_Update*/
    {5, CNA_BEHAVIOR_NONE, 238, 16, 78, 0, 214, 1},/*ADAS_ProfShort_AccurClass*/
    {5, CNA_BEHAVIOR_NONE, 235, 16, 78, 0, 215, 1},/*ADAS_ProfShort_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 232, 16, 78, 0, 216, 1},/*ADAS_ProfShort_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 239, 16, 78, 0, 217, 2},/*ADAS_ProfShort_Dist1*/
    {5, CNA_BEHAVIOR_NONE, 230, 16, 78, 0, 219, 1},/*ADAS_ProfShort_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 231, 16, 78, 0, 220, 2},/*ADAS_ProfShort_Offset*/
    {5, CNA_BEHAVIOR_NONE, 233, 16, 78, 0, 222, 1},/*ADAS_ProfShort_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 234, 16, 78, 0, 223, 1},/*ADAS_ProfShort_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 236, 16, 78, 0, 224, 1},/*ADAS_ProfShort_Retr*/
    {5, CNA_BEHAVIOR_NONE, 237, 16, 78, 0, 225, 1},/*ADAS_ProfShort_Update*/
    {5, CNA_BEHAVIOR_NONE, 240, 16, 78, 0, 226, 2},/*ADAS_ProfShort_Value0*/
    {5, CNA_BEHAVIOR_NONE, 241, 16, 78, 0, 228, 2},/*ADAS_ProfShort_Value1*/
    {5, CNA_BEHAVIOR_NONE, 225, 15, 78, 0, 230, 1},/*ADAS_ProfLong_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 222, 15, 78, 0, 231, 1},/*ADAS_ProfLong_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 220, 15, 78, 0, 232, 1},/*ADAS_ProfLong_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 221, 15, 78, 0, 233, 2},/*ADAS_ProfLong_Offset*/
    {5, CNA_BEHAVIOR_NONE, 223, 15, 78, 0, 235, 1},/*ADAS_ProfLong_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 224, 15, 78, 0, 236, 1},/*ADAS_ProfLong_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 226, 15, 78, 0, 237, 1},/*ADAS_ProfLong_Retr*/
    {5, CNA_BEHAVIOR_NONE, 227, 15, 78, 0, 238, 1},/*ADAS_ProfLong_Update*/
    {5, CNA_BEHAVIOR_NONE, 228, 15, 78, 0, 239, 4},/*ADAS_ProfLong_Value*/
    {5, CNA_BEHAVIOR_SEND, 154, 9, 78, 1, 243, 1},/*ACAIUReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 153, 9, 79, 1, 244, 1},/*ACAQSReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 151, 9, 80, 1, 245, 1},/*ACDualReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 139, 9, 81, 1, 246, 1},/*ACRearDefrstReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 150, 9, 82, 0, 247, 1},/*ALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 149, 9, 82, 0, 248, 1},/*ALCMDynSwt*/
    {5, CNA_BEHAVIOR_NONE, 147, 9, 82, 0, 249, 1},/*ALCMRhmSwt*/
    {5, CNA_BEHAVIOR_NONE, 148, 9, 82, 0, 250, 1},/*ALCMStatSwt*/
    {5, CNA_BEHAVIOR_NONE, 143, 9, 82, 0, 251, 1},/*HUT_ECOACLimnSet*/
    {5, CNA_BEHAVIOR_NONE, 141, 9, 82, 0, 252, 1},/*HUT_ECODrvModReq*/
    {5, CNA_BEHAVIOR_NONE, 142, 9, 82, 0, 253, 1},/*HUT_ECOSpdLim*/
    {5, CNA_BEHAVIOR_UNSEND, 140, 9, 82, 1, 254, 1},/*HUT_EgyRecvrySet*/
    {5, CNA_BEHAVIOR_NONE, 145, 9, 83, 0, 255, 1},/*HUT_ImdChrgSet*/
    {5, CNA_BEHAVIOR_NONE, 152, 9, 83, 0, 256, 1},/*IPVolSet*/
    {5, CNA_BEHAVIOR_NONE, 146, 9, 83, 0, 257, 1},/*MeditationModReq*/
    {5, CNA_BEHAVIOR_SEND, 144, 9, 83, 1, 258, 1},/*PASSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 569, 43, 84, 0, 259, 1},/*IP_RstAvrgEgyCns*/
    {5, CNA_BEHAVIOR_SEND, 282, 19, 84, 1, 260, 1},/*HUT_BattSOCLim*/
    {5, CNA_BEHAVIOR_UNSEND, 281, 19, 85, 1, 261, 1},/*HUT_GModeSet*/
    {5, CNA_BEHAVIOR_NONE, 283, 19, 86, 0, 262, 1},/*HUT_RemtEngCtrl*/
    {5, CNA_BEHAVIOR_NONE, 199, 13, 86, 0, 263, 1},/*AVMMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_NONE, 197, 13, 86, 0, 264, 1},/*AVMSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 195, 13, 86, 1, 265, 1},/*BackgroundLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 204, 13, 87, 0, 266, 1},/*DispModSet*/
    {5, CNA_BEHAVIOR_NONE, 200, 13, 87, 0, 267, 1},/*FPASChanSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 202, 13, 87, 0, 268, 1},/*HUT_V2VStart*/
    {5, CNA_BEHAVIOR_NONE, 203, 13, 87, 0, 269, 1},/*ManCmpSet*/
    {5, CNA_BEHAVIOR_NONE, 198, 13, 87, 0, 270, 1},/*NaviMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_UNSEND, 193, 13, 87, 1, 271, 1},/*OPDSwtSts*/
    {5, CNA_BEHAVIOR_UNSEND, 196, 13, 88, 1, 272, 1},/*PLGReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 201, 13, 89, 0, 273, 1},/*RPASChanSwtReq*/
    {5, CNA_BEHAVIOR_UNSEND, 194, 13, 89, 1, 274, 1},/*WPC_SwtReq*/
    {5, CNA_BEHAVIOR_NONE, 62, 3, 90, 0, 275, 1},/*ACAIUReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 61, 3, 90, 0, 276, 1},/*ACAQSReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 47, 3, 90, 0, 277, 1},/*ACAirInletReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 46, 3, 90, 0, 278, 1},/*ACAutoModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 60, 3, 90, 1, 279, 1},/*ACBlwrsteplsSpdReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 48, 3, 91, 0, 280, 1},/*ACCmprReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 53, 3, 91, 0, 281, 1},/*ACDrvAirDistribModReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 54, 3, 91, 0, 282, 1},/*ACDrvTempDecReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 56, 3, 91, 0, 283, 1},/*ACDrvTempIncReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 45, 3, 91, 0, 284, 1},/*ACDualReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 50, 3, 91, 0, 285, 1},/*ACFrntBlwrSpdDecReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 52, 3, 91, 0, 286, 1},/*ACFrntBlwrSpdIncReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 49, 3, 91, 0, 287, 1},/*ACFrntDefrstReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 57, 3, 91, 0, 288, 1},/*ACFrntPassTempDecReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 58, 3, 91, 0, 289, 1},/*ACFrntPassTempIncReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 59, 3, 91, 0, 290, 1},/*ACOffReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 44, 3, 91, 0, 291, 1},/*BattSaveDelayTimeSet*/
    {5, CNA_BEHAVIOR_NONE, 55, 3, 91, 0, 292, 1},/*ChairMemPosnEna*/
    {5, CNA_BEHAVIOR_NONE, 40, 3, 91, 0, 293, 1},/*DomeLmpDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 51, 3, 91, 0, 294, 1},/*DrvDrowsnsDetnSet*/
    {5, CNA_BEHAVIOR_NONE, 41, 3, 91, 0, 295, 1},/*FolwMeHomeDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 43, 3, 91, 0, 296, 1},/*RearviewFoldModSet*/
    {5, CNA_BEHAVIOR_NONE, 42, 3, 91, 0, 297, 1},/*TranPMode_Req*/
    {5, CNA_BEHAVIOR_NONE, 69, 4, 91, 0, 298, 1},/*AMP_AudioVolVSCModReq*/
    {5, CNA_BEHAVIOR_NONE, 67, 4, 91, 0, 299, 1},/*AMP_BeepSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 70, 4, 91, 0, 300, 1},/*AMP_FRAudioFaderSet*/
    {5, CNA_BEHAVIOR_NONE, 75, 4, 91, 0, 301, 1},/*AMP_HighFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 68, 4, 91, 0, 302, 1},/*AMP_LRAudioBalanceSet*/
    {5, CNA_BEHAVIOR_NONE, 71, 4, 91, 0, 303, 1},/*AMP_LRDrvSideSet*/
    {5, CNA_BEHAVIOR_NONE, 72, 4, 91, 0, 304, 1},/*AMP_LowFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 65, 4, 91, 0, 305, 1},/*AMP_MediaCallSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 74, 4, 91, 0, 306, 1},/*AMP_MidFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 73, 4, 91, 0, 307, 1},/*AMP_MuteSet*/
    {5, CNA_BEHAVIOR_NONE, 66, 4, 91, 0, 308, 1},/*AMP_NaviSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 78, 4, 91, 0, 309, 1},/*ANCSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 77, 4, 91, 0, 310, 1},/*QLISurroundSet*/
    {5, CNA_BEHAVIOR_SEND, 64, 4, 91, 1, 311, 1},/*RearWinHeatCmd_TC*/
    {5, CNA_BEHAVIOR_NONE, 76, 4, 92, 0, 312, 1},/*T_BOX_ECallSet*/
    {5, CNA_BEHAVIOR_NONE, 91, 5, 92, 0, 313, 1},/*AMP_BestListegPosnReq*/
    {5, CNA_BEHAVIOR_NONE, 92, 5, 92, 0, 314, 1},/*AMP_Clari_FiReq*/
    {5, CNA_BEHAVIOR_NONE, 88, 5, 92, 0, 315, 1},/*AMP_GetDTCInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 85, 5, 92, 0, 316, 1},/*AMP_GetHWInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 87, 5, 92, 0, 317, 1},/*AMP_GetIntVoltInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 84, 5, 92, 0, 318, 1},/*AMP_GetSWInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 86, 5, 92, 0, 319, 1},/*AMP_GetTempInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 80, 5, 92, 0, 320, 1},/*AMP_HFMVolSet*/
    {5, CNA_BEHAVIOR_NONE, 83, 5, 92, 0, 321, 1},/*AMP_MainVolSet*/
    {5, CNA_BEHAVIOR_NONE, 82, 5, 92, 0, 322, 1},/*AMP_NaviVolSet*/
    {5, CNA_BEHAVIOR_NONE, 81, 5, 92, 0, 323, 1},/*AMP_TTSVolSet_VR*/
    {5, CNA_BEHAVIOR_NONE, 90, 5, 92, 0, 324, 1},/*IESS_MdlInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 89, 5, 92, 0, 325, 1},/*IESS_MdlSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 103, 6, 92, 1, 326, 1},/*ACAirInletReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 96, 6, 93, 1, 327, 1},/*ACAutoModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 99, 6, 94, 1, 328, 1},/*ACBlwrSpdReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 97, 6, 95, 1, 329, 1},/*ACCmprReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 102, 6, 96, 1, 330, 1},/*ACDrvAirDistribModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 100, 6, 97, 1, 331, 1},/*ACDrvTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 101, 6, 98, 1, 332, 1},/*ACFrntDefrostReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 104, 6, 99, 0, 333, 1},/*ACModReq_HUT*/
    {5, CNA_BEHAVIOR_SEND, 98, 6, 99, 1, 334, 1},/*ACPowerReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 107, 6, 100, 0, 335, 1},/*AllTerrainDislSet*/
    {5, CNA_BEHAVIOR_NONE, 110, 6, 100, 0, 336, 1},/*DrvMassgCmd*/
    {5, CNA_BEHAVIOR_NONE, 94, 6, 100, 0, 337, 1},/*DrvSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 108, 6, 100, 0, 338, 1},/*DrvSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 105, 6, 100, 0, 339, 1},/*ElecSideSteppingSysSet*/
    {5, CNA_BEHAVIOR_NONE, 95, 6, 100, 0, 340, 1},/*PassSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 109, 6, 100, 0, 341, 1},/*PassSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 111, 6, 100, 0, 342, 1},/*RemUpgrdSts*/
    {5, CNA_BEHAVIOR_NONE, 106, 6, 100, 0, 343, 1},/*RoofModSet*/
    {5, CNA_BEHAVIOR_CYCLE, 394, 32, 100, 1, 344, 1},/*RearFogLmpSwtSts_HUT*/
    {5, CNA_BEHAVIOR_CYCLE, 298, 23, 101, 1, 345, 1},/*ContnPrkgReq*/
    {5, CNA_BEHAVIOR_CYCLE, 296, 23, 102, 1, 346, 1},/*PrkgCtrlModReq*/
    {5, CNA_BEHAVIOR_CYCLE, 285, 20, 103, 1, 347, 1},/*DrvSeatSupportPosnSwt*/
    {5, CNA_BEHAVIOR_CYCLE, 428, 34, 104, 1, 348, 1},/*ChairMemPosnSet*/
    {5, CNA_BEHAVIOR_CYCLE, 424, 34, 105, 1, 349, 1},/*EPSSteerModSwtReq*/
    {5, CNA_BEHAVIOR_CYCLE, 163, 10, 106, 1, 350, 1},/*HUT_AVHSwitchSts*/
    {5, CNA_BEHAVIOR_CYCLE, 164, 10, 107, 1, 351, 1},/*HUT_EPB_SwtPosn*/
    {5, CNA_BEHAVIOR_CYCLE, 166, 10, 108, 1, 352, 1},/*HUT_HDCSwitchCtrl*/
    {5, CNA_BEHAVIOR_CYCLE, 161, 10, 109, 1, 353, 1},/*ORVMFoldSwt_HUT*/
};

static CNA_SignalType cna_signalDatas[279] = {0u};
static const uint8 cna_noActionBuffer[110] =
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
    64u,
    4u,
    64u,
    64u,
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
    64u,
    0u,
    0u,
    64u,
    0u,
    64u,
    0u,
    0u,
    0u,
    0u,
    0u,
    3u,
    0u,
    6u,
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
    3u,
    0u,
    0u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[573] =
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    218,
    220,
    222,
    221,
    216,
    209,
    203,
    202,
    205,
    212,
    210,
    219,
    211,
    206,
    207,
    217,
    208,
    213,
    214,
    215,
    204,
    201,
    200,
    65535,
    236,
    230,
    233,
    224,
    227,
    223,
    225,
    228,
    229,
    232,
    231,
    226,
    237,
    235,
    234,
    65535,
    245,
    248,
    247,
    246,
    243,
    241,
    244,
    242,
    240,
    250,
    249,
    238,
    239,
    65535,
    262,
    265,
    252,
    254,
    259,
    253,
    256,
    257,
    255,
    251,
    258,
    264,
    268,
    260,
    263,
    266,
    261,
    267,
    65535,
    12,
    16,
    6,
    7,
    14,
    15,
    17,
    19,
    13,
    20,
    21,
    9,
    18,
    11,
    10,
    8,
    23,
    22,
    65535,
    3,
    2,
    5,
    1,
    4,
    0,
    65535,
    171,
    179,
    177,
    178,
    176,
    183,
    180,
    182,
    174,
    175,
    173,
    172,
    170,
    181,
    169,
    168,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    278,
    65535,
    275,
    276,
    65535,
    277,
    65535,
    77,
    78,
    74,
    85,
    80,
    91,
    90,
    88,
    73,
    81,
    86,
    87,
    84,
    82,
    75,
    76,
    79,
    83,
    92,
    89,
    65535,
    65535,
    65535,
    65535,
    65535,
    196,
    199,
    190,
    197,
    189,
    195,
    188,
    192,
    198,
    193,
    194,
    191,
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
    186,
    185,
    187,
    65535,
    272,
    65535,
    65535,
    65535,
    46,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    271,
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
    67,
    68,
    60,
    63,
    57,
    55,
    61,
    66,
    64,
    65,
    69,
    62,
    56,
    72,
    59,
    71,
    58,
    70,
    54,
    52,
    51,
    53,
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
    38,
    39,
    37,
    36,
    65535,
    40,
    41,
    43,
    44,
    42,
    45,
    65535,
    48,
    47,
    49,
    50,
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
    110,
    107,
    104,
    109,
    102,
    103,
    106,
    108,
    105,
    101,
    65535,
    94,
    96,
    100,
    97,
    99,
    95,
    98,
    93,
    65535,
    65535,
    269,
    65535,
    65535,
    65535,
    33,
    34,
    35,
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
    274,
    65535,
    65535,
    65535,
    273,
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    25,
    24,
    28,
    26,
    27,
    29,
    30,
    31,
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
    184,
    65535,
    65535,
    65535,
};

static uint8 cna_currentBuffer[354] = {0};

const CNA_ConfigType cna_config =
{
    279u,
    cna_signalConfigs,
    cna_signalDatas,
    110u,
    cna_noActionBuffer,
    354u,
    cna_currentBuffer,
    573u,
    CNA_IdTable
};


