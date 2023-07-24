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
static const CNA_SignalConfigType cna_signalConfigs[379] =
{
    {5, CNA_BEHAVIOR_NONE, 140, 8, 0, 0, 0, 1},/*ALCMBreSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 137, 8, 0, 0, 1, 1},/*ALCMClrSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 138, 8, 0, 0, 2, 1},/*ALCMDynModSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 144, 8, 0, 0, 3, 1},/*ALCMRdmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 139, 8, 0, 0, 4, 1},/*ALCMRhmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 136, 8, 0, 0, 5, 1},/*ALCMStatSwt_OLE*/
    {5, CNA_BEHAVIOR_UNSEND, 141, 8, 0, 1, 6, 1},/*CarWashModeReq*/
    {5, CNA_BEHAVIOR_UNSEND, 149, 8, 1, 1, 7, 1},/*ChairRestSetSwt*/
    {5, CNA_BEHAVIOR_SEND, 145, 8, 2, 1, 8, 1},/*ChildLockCmd*/
    {5, CNA_BEHAVIOR_SEND, 143, 8, 3, 1, 9, 1},/*HUT_VMDRInitAlarmDlySet*/
    {5, CNA_BEHAVIOR_SEND, 142, 8, 4, 1, 10, 1},/*HUT_VMDRTmpMonFctnSet*/
    {5, CNA_BEHAVIOR_NONE, 148, 8, 5, 0, 11, 1},/*MiaoCallClsReq*/
    {5, CNA_BEHAVIOR_UNSEND, 146, 8, 5, 1, 12, 1},/*MusicLightShowSet*/
    {5, CNA_BEHAVIOR_NONE, 151, 8, 6, 0, 13, 1},/*OTA_UpgrdModReq*/
    {5, CNA_BEHAVIOR_SEND, 152, 8, 6, 1, 14, 1},/*SmtCsaSwt*/
    {5, CNA_BEHAVIOR_NONE, 147, 8, 7, 0, 15, 1},/*SpoilerSpdSet*/
    {5, CNA_BEHAVIOR_NONE, 150, 8, 7, 0, 16, 1},/*UltrAntitheftSwt*/
    {5, CNA_BEHAVIOR_SEND, 117, 7, 7, 1, 17, 1},/*AUTODefrost_TC*/
    {5, CNA_BEHAVIOR_SEND, 118, 7, 8, 1, 18, 1},/*AUTODefrost_VR*/
    {5, CNA_BEHAVIOR_SEND, 130, 7, 9, 1, 19, 1},/*AutoAVMSwSet_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 126, 7, 10, 1, 20, 1},/*AutoViewChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 129, 7, 11, 1, 21, 1},/*CarMdlDispCmd*/
    {5, CNA_BEHAVIOR_SEND, 128, 7, 12, 1, 22, 1},/*CarMdlTrsprcySwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 131, 7, 13, 1, 23, 1},/*FPAS_AutoModSwt*/
    {5, CNA_BEHAVIOR_SEND, 123, 7, 14, 1, 24, 1},/*Guid_Ovl_Display_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 119, 7, 15, 1, 25, 1},/*HUT_VCUBattKeepTemp*/
    {5, CNA_BEHAVIOR_SEND, 120, 7, 16, 1, 26, 1},/*LaneCalActvtCmd*/
    {5, CNA_BEHAVIOR_SEND, 132, 7, 17, 1, 27, 1},/*MEBSwtSet*/
    {5, CNA_BEHAVIOR_SEND, 121, 7, 18, 1, 28, 1},/*MODChgReq*/
    {5, CNA_BEHAVIOR_SEND, 127, 7, 19, 1, 29, 1},/*MdlColrChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 122, 7, 20, 1, 30, 1},/*Radar_DispCmd*/
    {5, CNA_BEHAVIOR_SEND, 124, 7, 21, 1, 31, 1},/*Sgl_View_Sel*/
    {5, CNA_BEHAVIOR_SEND, 125, 7, 22, 1, 32, 1},/*SwToFieldCalRstCmd*/
    {5, CNA_BEHAVIOR_SEND, 134, 7, 23, 1, 33, 1},/*View_SoftswitchCmd*/
    {5, CNA_BEHAVIOR_SEND, 133, 7, 24, 1, 34, 1},/*WshSoftSwt*/
    {5, CNA_BEHAVIOR_SEND, 705, 47, 25, 1, 35, 1},/*HUT_HAVP_APA_Permit*/
    {5, CNA_BEHAVIOR_UNSEND, 712, 47, 26, 1, 36, 1},/*HUT_HAVP_Comfirm_Btn*/
    {5, CNA_BEHAVIOR_NONE, 713, 47, 27, 0, 37, 1},/*HUT_HAVP_Path_Delete*/
    {5, CNA_BEHAVIOR_NONE, 714, 47, 27, 0, 38, 1},/*HUT_HAVP_Path_Select*/
    {5, CNA_BEHAVIOR_NONE, 715, 47, 27, 0, 39, 1},/*HUT_HAVP_Path_SetTop*/
    {5, CNA_BEHAVIOR_SEND, 704, 47, 27, 1, 40, 1},/*HUT_HAVP_Return_Btn*/
    {5, CNA_BEHAVIOR_SEND, 707, 47, 28, 1, 41, 1},/*HUT_HAVP_SelfParLot_Ending*/
    {5, CNA_BEHAVIOR_SEND, 708, 47, 29, 1, 42, 1},/*HUT_HAVP_Set_Path_Ending*/
    {5, CNA_BEHAVIOR_SEND, 706, 47, 30, 1, 43, 1},/*HUT_HAVP_Set_Starting*/
    {5, CNA_BEHAVIOR_SEND, 709, 47, 31, 1, 44, 1},/*SlotNum_VR*/
    {5, CNA_BEHAVIOR_SEND, 710, 47, 32, 1, 45, 1},/*UserDefPrkMenuSelCmd*/
    {5, CNA_BEHAVIOR_SEND, 711, 47, 33, 1, 46, 1},/*UserDefinedParkCmd*/
    {5, CNA_BEHAVIOR_UNSEND, 509, 40, 34, 1, 47, 1},/*ApprLightSwt*/
    {5, CNA_BEHAVIOR_NONE, 510, 40, 35, 0, 48, 1},/*DoorCtrlLightSwt*/
    {5, CNA_BEHAVIOR_SEND, 502, 40, 35, 1, 49, 1},/*DrvSeatMassgModSet*/
    {5, CNA_BEHAVIOR_SEND, 503, 40, 36, 1, 50, 1},/*HUT_V2LStart*/
    {5, CNA_BEHAVIOR_NONE, 506, 40, 37, 0, 51, 1},/*InCarTempMaxSet*/
    {5, CNA_BEHAVIOR_NONE, 505, 40, 37, 0, 52, 1},/*InCarTempMinSet*/
    {5, CNA_BEHAVIOR_UNSEND, 508, 40, 37, 1, 53, 1},/*LockWelLightSwt*/
    {5, CNA_BEHAVIOR_SEND, 504, 40, 38, 1, 54, 1},/*PassSeatMassgModSet*/
    {5, CNA_BEHAVIOR_NONE, 512, 40, 39, 0, 55, 1},/*RepairModReq*/
    {5, CNA_BEHAVIOR_NONE, 511, 40, 39, 0, 56, 1},/*SmtACSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 507, 40, 39, 1, 57, 1},/*UnlockWelLightSwt*/
    {5, CNA_BEHAVIOR_SEND, 521, 41, 40, 1, 58, 1},/*CLOutletHozlPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 515, 41, 41, 1, 59, 1},/*CLOutletSet*/
    {5, CNA_BEHAVIOR_SEND, 520, 41, 42, 1, 60, 1},/*CLOutletVertPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 523, 41, 43, 1, 61, 1},/*CROutletHozlPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 516, 41, 44, 1, 62, 1},/*CROutletSet*/
    {5, CNA_BEHAVIOR_SEND, 522, 41, 45, 1, 63, 1},/*CROutletVertPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 519, 41, 46, 1, 64, 1},/*LOutletHozlPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 514, 41, 47, 1, 65, 1},/*LOutletSet*/
    {5, CNA_BEHAVIOR_SEND, 518, 41, 48, 1, 66, 1},/*LOutletVertPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 525, 41, 49, 1, 67, 1},/*ROutletHozlPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 517, 41, 50, 1, 68, 1},/*ROutletSet*/
    {5, CNA_BEHAVIOR_SEND, 524, 41, 51, 1, 69, 1},/*ROutletVertPosnCmd*/
    {5, CNA_BEHAVIOR_SEND, 409, 30, 52, 1, 70, 1},/*ACMaxReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 408, 30, 53, 1, 71, 1},/*ACMaxReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 406, 30, 54, 1, 72, 1},/*ESCMAdjCmd*/
    {5, CNA_BEHAVIOR_NONE, 402, 30, 55, 0, 73, 1},/*LockWinSet*/
    {5, CNA_BEHAVIOR_NONE, 407, 30, 55, 0, 74, 1},/*NozHeatSwt*/
    {5, CNA_BEHAVIOR_SEND, 405, 30, 55, 1, 75, 1},/*SpoilerCtrlCmd*/
    {5, CNA_BEHAVIOR_NONE, 404, 30, 56, 0, 76, 1},/*SpoilerFixModSwt*/
    {5, CNA_BEHAVIOR_NONE, 403, 30, 56, 0, 77, 1},/*SpoilerWelModSwt*/
    {5, CNA_BEHAVIOR_NONE, 411, 31, 56, 0, 78, 1},/*MultiColorNr1*/
    {5, CNA_BEHAVIOR_NONE, 412, 31, 56, 0, 79, 1},/*MultiColorNr2*/
    {5, CNA_BEHAVIOR_NONE, 413, 31, 56, 0, 80, 1},/*MultiColorNr3*/
    {5, CNA_BEHAVIOR_NONE, 414, 31, 56, 0, 81, 1},/*MultiColorNr4*/
    {5, CNA_BEHAVIOR_NONE, 415, 31, 56, 0, 82, 1},/*MultiColorNr5*/
    {5, CNA_BEHAVIOR_NONE, 416, 31, 56, 0, 83, 1},/*MultiColorNr6*/
    {5, CNA_BEHAVIOR_NONE, 417, 31, 56, 0, 84, 1},/*MultiColorNr7*/
    {5, CNA_BEHAVIOR_NONE, 418, 31, 56, 0, 85, 1},/*MultiColorNr8*/
    {5, CNA_BEHAVIOR_NONE, 429, 33, 56, 0, 86, 1},/*ACUltravioletReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 430, 33, 56, 1, 87, 1},/*ACUltravioletReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 431, 33, 57, 1, 88, 1},/*DrvDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 437, 33, 58, 1, 89, 1},/*FootALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 432, 33, 59, 1, 90, 1},/*LRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 435, 33, 60, 1, 91, 1},/*LeftPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 433, 33, 61, 1, 92, 1},/*PassDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 434, 33, 62, 1, 93, 1},/*RRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 436, 33, 63, 1, 94, 1},/*RightPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_NONE, 330, 25, 64, 0, 95, 1},/*ADASDispSwt*/
    {5, CNA_BEHAVIOR_NONE, 333, 25, 64, 0, 96, 1},/*BTPhoneDispSwt*/
    {5, CNA_BEHAVIOR_SEND, 340, 25, 64, 1, 97, 1},/*BackReq_AVM*/
    {5, CNA_BEHAVIOR_NONE, 332, 25, 65, 0, 98, 1},/*EngspdDispSwt*/
    {5, CNA_BEHAVIOR_SEND, 338, 25, 65, 1, 99, 1},/*HUD_BrightnessLvlSwt*/
    {5, CNA_BEHAVIOR_NONE, 336, 25, 66, 0, 100, 1},/*HUD_DisplayModeCfg*/
    {5, CNA_BEHAVIOR_SEND, 337, 25, 66, 1, 101, 1},/*HUD_HeightLvlSwt*/
    {5, CNA_BEHAVIOR_NONE, 335, 25, 67, 0, 102, 1},/*HUD_RotateAngleCfg*/
    {5, CNA_BEHAVIOR_NONE, 334, 25, 67, 0, 103, 1},/*HUD_RotateDirCfg*/
    {5, CNA_BEHAVIOR_SEND, 339, 25, 67, 1, 104, 1},/*HUD_SwtReq*/
    {5, CNA_BEHAVIOR_NONE, 331, 25, 68, 0, 105, 1},/*NaviDispSwt*/
    {5, CNA_BEHAVIOR_NONE, 445, 34, 68, 0, 106, 1},/*ActvEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 444, 34, 68, 0, 107, 1},/*ActvEntryUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 441, 34, 68, 0, 108, 1},/*BTAPAEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 442, 34, 68, 0, 109, 1},/*BTAPALvngUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 443, 34, 68, 0, 110, 1},/*ClsWinSpdSet*/
    {5, CNA_BEHAVIOR_SEND, 447, 34, 68, 1, 111, 1},/*DrvDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 450, 34, 69, 0, 112, 1},/*DrvDoorALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 439, 34, 69, 1, 113, 1},/*DrvSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 448, 34, 70, 1, 114, 1},/*LRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 440, 34, 71, 0, 115, 1},/*LockPromptFunSet*/
    {5, CNA_BEHAVIOR_SEND, 449, 34, 71, 1, 116, 1},/*PassDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 451, 34, 72, 0, 117, 1},/*PassDoorALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 446, 34, 72, 1, 118, 1},/*PassSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 421, 32, 73, 0, 119, 1},/*MultiColorNr10*/
    {5, CNA_BEHAVIOR_NONE, 422, 32, 73, 0, 120, 1},/*MultiColorNr11*/
    {5, CNA_BEHAVIOR_NONE, 423, 32, 73, 0, 121, 1},/*MultiColorNr12*/
    {5, CNA_BEHAVIOR_NONE, 424, 32, 73, 0, 122, 1},/*MultiColorNr13*/
    {5, CNA_BEHAVIOR_NONE, 425, 32, 73, 0, 123, 1},/*MultiColorNr14*/
    {5, CNA_BEHAVIOR_NONE, 426, 32, 73, 0, 124, 1},/*MultiColorNr15*/
    {5, CNA_BEHAVIOR_NONE, 427, 32, 73, 0, 125, 1},/*MultiColorNr16*/
    {5, CNA_BEHAVIOR_NONE, 420, 32, 73, 0, 126, 1},/*MultiColorNr9*/
    {5, CNA_BEHAVIOR_SEND, 384, 28, 73, 1, 127, 1},/*ACFGAChanTyp_TC*/
    {5, CNA_BEHAVIOR_SEND, 383, 28, 74, 1, 128, 1},/*ACFGAEnaReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 385, 28, 75, 1, 129, 1},/*ACFGALvlReq_TC*/
    {6, CNA_BEHAVIOR_NONE, 370, 28, 76, 0, 130, 1},/*ALCMDynModSet*/
    {6, CNA_BEHAVIOR_UNSEND, 387, 28, 76, 1, 131, 1},/*ApproachLampSet*/
    {5, CNA_BEHAVIOR_SEND, 382, 28, 77, 1, 132, 1},/*BackReq_APS*/
    {6, CNA_BEHAVIOR_SEND, 372, 28, 78, 1, 133, 1},/*ChairMemPosnSetSwt*/
    {5, CNA_BEHAVIOR_SEND, 379, 28, 79, 1, 134, 1},/*DeletePath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 377, 28, 80, 1, 135, 1},/*DeletePath2Cmd*/
    {6, CNA_BEHAVIOR_SEND, 368, 28, 81, 1, 136, 1},/*DrvWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_UNSEND, 386, 28, 82, 1, 137, 1},/*FlaoutUnlockSet*/
    {5, CNA_BEHAVIOR_SEND, 388, 28, 83, 1, 138, 1},/*P2P_PrkgDirectSwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 381, 28, 84, 1, 139, 1},/*ParkMdlCmd*/
    {6, CNA_BEHAVIOR_SEND, 369, 28, 85, 1, 140, 1},/*PassWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 373, 28, 86, 1, 141, 1},/*PathLrngFinshCmd*/
    {5, CNA_BEHAVIOR_SEND, 374, 28, 87, 1, 142, 1},/*PathLrngStartCmd*/
    {6, CNA_BEHAVIOR_NONE, 371, 28, 88, 0, 143, 1},/*PrkInDirChoice*/
    {6, CNA_BEHAVIOR_SEND, 366, 28, 88, 1, 144, 1},/*RLWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_SEND, 367, 28, 89, 1, 145, 1},/*RRWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 375, 28, 90, 1, 146, 1},/*SelPrkOutDirReq*/
    {5, CNA_BEHAVIOR_SEND, 380, 28, 91, 1, 147, 1},/*SelPrkgFctnCmd*/
    {5, CNA_BEHAVIOR_SEND, 378, 28, 92, 1, 148, 1},/*StartPrkgPath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 376, 28, 93, 1, 149, 1},/*StartPrkgPath2Cmd*/
    {5, CNA_BEHAVIOR_NONE, 205, 12, 94, 0, 150, 1},/*ABSLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 188, 12, 94, 1, 151, 1},/*ACDrvSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 201, 12, 95, 1, 152, 1},/*ACEAHReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 202, 12, 96, 1, 153, 1},/*ACEAHReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 186, 12, 97, 1, 154, 1},/*ACOperMod_TC*/
    {5, CNA_BEHAVIOR_SEND, 187, 12, 98, 1, 155, 1},/*ACOperMod_VR*/
    {5, CNA_BEHAVIOR_SEND, 189, 12, 99, 1, 156, 1},/*ACPassSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 192, 12, 100, 1, 157, 1},/*APSPrkgTypSeln*/
    {5, CNA_BEHAVIOR_SEND, 191, 12, 101, 1, 158, 1},/*APSSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 196, 12, 102, 0, 159, 1},/*AutoWshWipSet*/
    {5, CNA_BEHAVIOR_NONE, 200, 12, 102, 0, 160, 1},/*DoorUnlockModSet*/
    {5, CNA_BEHAVIOR_SEND, 204, 12, 102, 1, 161, 1},/*PASExitSpdSwt*/
    {5, CNA_BEHAVIOR_NONE, 199, 12, 103, 0, 162, 1},/*ParkLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 190, 12, 103, 1, 163, 1},/*SDWSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 197, 12, 104, 0, 164, 1},/*SeekVehSet*/
    {5, CNA_BEHAVIOR_NONE, 198, 12, 104, 0, 165, 1},/*SpdAutoLockModSet*/
    {5, CNA_BEHAVIOR_NONE, 195, 12, 104, 0, 166, 1},/*SportModLightSet*/
    {5, CNA_BEHAVIOR_SEND, 203, 12, 104, 1, 167, 1},/*SteerWheelHeatSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 194, 12, 105, 1, 168, 1},/*SunRoofSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 193, 12, 106, 1, 169, 1},/*SunShadeSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 527, 42, 107, 1, 170, 1},/*LSideOutletModSet*/
    {5, CNA_BEHAVIOR_SEND, 528, 42, 108, 1, 171, 1},/*RSideOutletModSet*/
    {5, CNA_BEHAVIOR_UNSEND, 530, 43, 109, 1, 172, 1},/*ScenarioSwtID*/
    {5, CNA_BEHAVIOR_UNSEND, 531, 43, 110, 1, 173, 1},/*ScenarioSwtReq*/
    {5, CNA_BEHAVIOR_UNSEND, 484, 37, 111, 1, 174, 1},/*HUT_AccelPedalSnvtyAdj*/
    {5, CNA_BEHAVIOR_UNSEND, 485, 37, 112, 1, 175, 1},/*HUT_CreepSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 483, 37, 113, 1, 176, 1},/*HUT_EneRecoInteAdj*/
    {5, CNA_BEHAVIOR_NONE, 463, 36, 114, 0, 177, 1},/*ALCMBreSwt*/
    {5, CNA_BEHAVIOR_NONE, 473, 36, 114, 0, 178, 1},/*ALCMFloSwt*/
    {5, CNA_BEHAVIOR_SEND, 468, 36, 114, 1, 179, 1},/*DrvDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 480, 36, 115, 1, 180, 1},/*FootALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 481, 36, 116, 1, 181, 1},/*FootALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 478, 36, 117, 0, 182, 1},/*FootALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 469, 36, 117, 1, 183, 1},/*LRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 476, 36, 118, 0, 184, 1},/*LRDoorALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 466, 36, 118, 1, 185, 1},/*LeftPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 472, 36, 119, 1, 186, 1},/*LeftPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 474, 36, 120, 0, 187, 1},/*LeftPanelALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 470, 36, 120, 1, 188, 1},/*PassDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 465, 36, 121, 1, 189, 1},/*RRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 471, 36, 122, 1, 190, 1},/*RRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 477, 36, 123, 0, 191, 1},/*RRDoorALCMSwt*/
    {5, CNA_BEHAVIOR_SEND, 467, 36, 123, 1, 192, 1},/*RightPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 464, 36, 124, 1, 193, 1},/*RightPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 475, 36, 125, 0, 194, 1},/*RightPanelALCMSwt*/
    {5, CNA_BEHAVIOR_NONE, 479, 36, 125, 0, 195, 1},/*RoofALCMSwt*/
    {5, CNA_BEHAVIOR_NONE, 487, 38, 125, 0, 196, 1},/*DrvWinSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 491, 38, 125, 0, 197, 1},/*InCarTempSet*/
    {5, CNA_BEHAVIOR_NONE, 489, 38, 125, 0, 198, 1},/*PassWinSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 488, 38, 125, 0, 199, 1},/*RLWinSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 490, 38, 125, 0, 200, 1},/*RRWinSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 492, 38, 125, 1, 201, 1},/*SmtSeatSwt*/
    {5, CNA_BEHAVIOR_NONE, 295, 19, 126, 0, 202, 1},/*ADAS_Stub_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 287, 19, 126, 0, 203, 1},/*ADAS_Stub_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 296, 19, 126, 0, 204, 1},/*ADAS_Stub_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 293, 19, 126, 0, 205, 1},/*ADAS_Stub_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 298, 19, 126, 0, 206, 1},/*ADAS_Stub_LastStub*/
    {5, CNA_BEHAVIOR_NONE, 285, 19, 126, 0, 207, 1},/*ADAS_Stub_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 301, 19, 126, 0, 208, 1},/*ADAS_Stub_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 300, 19, 126, 0, 209, 1},/*ADAS_Stub_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 286, 19, 126, 0, 210, 2},/*ADAS_Stub_Offset*/
    {5, CNA_BEHAVIOR_NONE, 294, 19, 126, 0, 212, 1},/*ADAS_Stub_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 288, 19, 126, 0, 213, 1},/*ADAS_Stub_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 292, 19, 126, 0, 214, 1},/*ADAS_Stub_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 290, 19, 126, 0, 215, 1},/*ADAS_Stub_Retr*/
    {5, CNA_BEHAVIOR_NONE, 299, 19, 126, 0, 216, 1},/*ADAS_Stub_RtOfWay*/
    {5, CNA_BEHAVIOR_NONE, 289, 19, 126, 0, 217, 1},/*ADAS_Stub_StubPathIdx*/
    {5, CNA_BEHAVIOR_NONE, 297, 19, 126, 0, 218, 1},/*ADAS_Stub_TurnAngl*/
    {5, CNA_BEHAVIOR_NONE, 291, 19, 126, 0, 219, 1},/*ADAS_Stub_Update*/
    {5, CNA_BEHAVIOR_NONE, 270, 18, 126, 0, 220, 1},/*ADAS_Seg_Brdg*/
    {5, CNA_BEHAVIOR_NONE, 271, 18, 126, 0, 221, 1},/*ADAS_Seg_BuildUpArea*/
    {5, CNA_BEHAVIOR_NONE, 277, 18, 126, 0, 222, 1},/*ADAS_Seg_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 267, 18, 126, 0, 223, 1},/*ADAS_Seg_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 281, 18, 126, 0, 224, 1},/*ADAS_Seg_DivideRoad*/
    {5, CNA_BEHAVIOR_NONE, 279, 18, 126, 0, 225, 1},/*ADAS_Seg_EffSpdLmt*/
    {5, CNA_BEHAVIOR_NONE, 280, 18, 126, 0, 226, 1},/*ADAS_Seg_EffSpdLmtTyp*/
    {5, CNA_BEHAVIOR_NONE, 278, 18, 126, 0, 227, 1},/*ADAS_Seg_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 275, 18, 126, 0, 228, 1},/*ADAS_Seg_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 265, 18, 126, 0, 229, 1},/*ADAS_Seg_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 283, 18, 126, 0, 230, 1},/*ADAS_Seg_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 282, 18, 126, 0, 231, 1},/*ADAS_Seg_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 266, 18, 126, 0, 232, 2},/*ADAS_Seg_Offset*/
    {5, CNA_BEHAVIOR_NONE, 276, 18, 126, 0, 234, 1},/*ADAS_Seg_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 268, 18, 126, 0, 235, 1},/*ADAS_Seg_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 274, 18, 126, 0, 236, 1},/*ADAS_Seg_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 272, 18, 126, 0, 237, 1},/*ADAS_Seg_Retr*/
    {5, CNA_BEHAVIOR_NONE, 269, 18, 126, 0, 238, 1},/*ADAS_Seg_Tunnel*/
    {5, CNA_BEHAVIOR_NONE, 273, 18, 126, 0, 239, 1},/*ADAS_Seg_Update*/
    {5, CNA_BEHAVIOR_NONE, 260, 17, 126, 0, 240, 1},/*ADAS_ProfShort_AccurClass*/
    {5, CNA_BEHAVIOR_NONE, 257, 17, 126, 0, 241, 1},/*ADAS_ProfShort_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 254, 17, 126, 0, 242, 1},/*ADAS_ProfShort_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 261, 17, 126, 0, 243, 2},/*ADAS_ProfShort_Dist1*/
    {5, CNA_BEHAVIOR_NONE, 252, 17, 126, 0, 245, 1},/*ADAS_ProfShort_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 253, 17, 126, 0, 246, 2},/*ADAS_ProfShort_Offset*/
    {5, CNA_BEHAVIOR_NONE, 255, 17, 126, 0, 248, 1},/*ADAS_ProfShort_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 256, 17, 126, 0, 249, 1},/*ADAS_ProfShort_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 258, 17, 126, 0, 250, 1},/*ADAS_ProfShort_Retr*/
    {5, CNA_BEHAVIOR_NONE, 259, 17, 126, 0, 251, 1},/*ADAS_ProfShort_Update*/
    {5, CNA_BEHAVIOR_NONE, 262, 17, 126, 0, 252, 2},/*ADAS_ProfShort_Value0*/
    {5, CNA_BEHAVIOR_NONE, 263, 17, 126, 0, 254, 2},/*ADAS_ProfShort_Value1*/
    {5, CNA_BEHAVIOR_NONE, 247, 16, 126, 0, 256, 1},/*ADAS_ProfLong_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 244, 16, 126, 0, 257, 1},/*ADAS_ProfLong_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 242, 16, 126, 0, 258, 1},/*ADAS_ProfLong_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 243, 16, 126, 0, 259, 2},/*ADAS_ProfLong_Offset*/
    {5, CNA_BEHAVIOR_NONE, 245, 16, 126, 0, 261, 1},/*ADAS_ProfLong_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 246, 16, 126, 0, 262, 1},/*ADAS_ProfLong_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 248, 16, 126, 0, 263, 1},/*ADAS_ProfLong_Retr*/
    {5, CNA_BEHAVIOR_NONE, 249, 16, 126, 0, 264, 1},/*ADAS_ProfLong_Update*/
    {5, CNA_BEHAVIOR_NONE, 250, 16, 126, 0, 265, 4},/*ADAS_ProfLong_Value*/
    {5, CNA_BEHAVIOR_SEND, 158, 9, 126, 1, 269, 1},/*ACAIUReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 155, 9, 127, 1, 270, 1},/*ACAQSReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 154, 9, 128, 1, 271, 1},/*ACDualReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 157, 9, 129, 1, 272, 1},/*ACPassTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 156, 9, 130, 1, 273, 1},/*ACRearDefrstReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 169, 9, 131, 0, 274, 1},/*ALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 168, 9, 131, 0, 275, 1},/*ALCMDynSwt*/
    {5, CNA_BEHAVIOR_NONE, 166, 9, 131, 0, 276, 1},/*ALCMRhmSwt*/
    {5, CNA_BEHAVIOR_NONE, 167, 9, 131, 0, 277, 1},/*ALCMStatSwt*/
    {3, CNA_BEHAVIOR_SEND, 171, 9, 131, 1, 278, 1},/*HUT_BeanIDReq*/
    {5, CNA_BEHAVIOR_SEND, 160, 9, 132, 1, 279, 1},/*HUT_ECOACLimnSet*/
    {5, CNA_BEHAVIOR_SEND, 162, 9, 133, 1, 280, 1},/*HUT_ECODrvModReq*/
    {5, CNA_BEHAVIOR_NONE, 163, 9, 134, 0, 281, 1},/*HUT_ECOSpdLim*/
    {5, CNA_BEHAVIOR_UNSEND, 161, 9, 134, 1, 282, 1},/*HUT_EgyRecvrySet*/
    {5, CNA_BEHAVIOR_NONE, 165, 9, 135, 0, 283, 1},/*HUT_ImdChrgSet*/
    {5, CNA_BEHAVIOR_NONE, 159, 9, 135, 0, 284, 1},/*IPVolSet*/
    {5, CNA_BEHAVIOR_SEND, 170, 9, 135, 1, 285, 1},/*PASSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 164, 9, 136, 0, 286, 1},/*VSGMuteSwSet*/
    {5, CNA_BEHAVIOR_NONE, 306, 20, 136, 0, 287, 1},/*ADASDispSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 309, 20, 136, 0, 288, 1},/*BTPhoneDispSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 308, 20, 136, 0, 289, 1},/*EngspdDispSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 304, 20, 136, 0, 290, 1},/*HUD_BrightnessLvlSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 312, 20, 136, 0, 291, 1},/*HUD_DisplayModeCfg_VR*/
    {5, CNA_BEHAVIOR_NONE, 303, 20, 136, 0, 292, 1},/*HUD_HeightLvlSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 311, 20, 136, 0, 293, 1},/*HUD_RotateAngleCfg_VR*/
    {5, CNA_BEHAVIOR_NONE, 310, 20, 136, 0, 294, 1},/*HUD_RotateDirCfg_VR*/
    {5, CNA_BEHAVIOR_NONE, 305, 20, 136, 0, 295, 1},/*HUD_SwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 314, 20, 136, 1, 296, 1},/*HUT_BattSOCLim*/
    {5, CNA_BEHAVIOR_UNSEND, 315, 20, 137, 1, 297, 1},/*HUT_GModeSet*/
    {5, CNA_BEHAVIOR_SEND, 313, 20, 138, 1, 298, 1},/*HUT_RemtEngCtrl*/
    {5, CNA_BEHAVIOR_NONE, 307, 20, 139, 0, 299, 1},/*NaviDispSwt_VR*/
    {5, CNA_BEHAVIOR_NONE, 223, 14, 139, 0, 300, 1},/*AVMMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_NONE, 222, 14, 139, 0, 301, 1},/*AVMSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 215, 14, 139, 1, 302, 1},/*BackgroundLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 219, 14, 140, 0, 303, 1},/*DispModSet*/
    {5, CNA_BEHAVIOR_NONE, 221, 14, 140, 0, 304, 1},/*FPASChanSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 217, 14, 140, 1, 305, 1},/*HUT_V2VStart*/
    {5, CNA_BEHAVIOR_NONE, 218, 14, 141, 0, 306, 1},/*ManCmpSet*/
    {5, CNA_BEHAVIOR_NONE, 224, 14, 141, 0, 307, 1},/*NaviMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_UNSEND, 216, 14, 141, 1, 308, 1},/*OPDSwtSts*/
    {5, CNA_BEHAVIOR_UNSEND, 225, 14, 142, 1, 309, 1},/*PLGReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 220, 14, 143, 0, 310, 1},/*RPASChanSwtReq*/
    {5, CNA_BEHAVIOR_UNSEND, 226, 14, 143, 1, 311, 1},/*WPC_SwtReq*/
    {5, CNA_BEHAVIOR_SEND, 64, 3, 144, 1, 312, 1},/*ACAIUReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 52, 3, 145, 1, 313, 1},/*ACAQSReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 51, 3, 146, 1, 314, 1},/*ACAirInletReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 50, 3, 147, 1, 315, 1},/*ACAutoModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 66, 3, 148, 1, 316, 1},/*ACBlwrsteplsSpdReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 53, 3, 149, 1, 317, 1},/*ACCmprReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 58, 3, 150, 1, 318, 1},/*ACDrvAirDistribModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 59, 3, 151, 1, 319, 1},/*ACDrvTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 61, 3, 152, 1, 320, 1},/*ACDrvTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 49, 3, 153, 1, 321, 1},/*ACDualReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 55, 3, 154, 1, 322, 1},/*ACFrntBlwrSpdDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 57, 3, 155, 1, 323, 1},/*ACFrntBlwrSpdIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 54, 3, 156, 1, 324, 1},/*ACFrntDefrstReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 62, 3, 157, 1, 325, 1},/*ACFrntPassTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 63, 3, 158, 1, 326, 1},/*ACFrntPassTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 65, 3, 159, 1, 327, 1},/*ACOffReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 48, 3, 160, 0, 328, 1},/*BattSaveDelayTimeSet*/
    {5, CNA_BEHAVIOR_NONE, 60, 3, 160, 0, 329, 1},/*ChairMemPosnEna*/
    {5, CNA_BEHAVIOR_NONE, 45, 3, 160, 0, 330, 1},/*DomeLmpDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 56, 3, 160, 0, 331, 1},/*DrvDrowsnsDetnSet*/
    {5, CNA_BEHAVIOR_NONE, 46, 3, 160, 0, 332, 1},/*FolwMeHomeDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 47, 3, 160, 0, 333, 1},/*RearviewFoldModSet*/
    {5, CNA_BEHAVIOR_NONE, 67, 3, 160, 0, 334, 1},/*TranPMode_Req*/
    {5, CNA_BEHAVIOR_NONE, 73, 4, 160, 0, 335, 1},/*AMP_AudioVolVSCModReq*/
    {5, CNA_BEHAVIOR_NONE, 71, 4, 160, 0, 336, 1},/*AMP_BeepSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 74, 4, 160, 0, 337, 1},/*AMP_FRAudioFaderSet*/
    {5, CNA_BEHAVIOR_NONE, 79, 4, 160, 0, 338, 1},/*AMP_HighFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 72, 4, 160, 0, 339, 1},/*AMP_LRAudioBalanceSet*/
    {5, CNA_BEHAVIOR_NONE, 75, 4, 160, 0, 340, 1},/*AMP_LRDrvSideSet*/
    {5, CNA_BEHAVIOR_NONE, 76, 4, 160, 0, 341, 1},/*AMP_LowFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 69, 4, 160, 0, 342, 1},/*AMP_MediaCallSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 78, 4, 160, 0, 343, 1},/*AMP_MidFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 77, 4, 160, 0, 344, 1},/*AMP_MuteSet*/
    {5, CNA_BEHAVIOR_NONE, 70, 4, 160, 0, 345, 1},/*AMP_NaviSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 82, 4, 160, 0, 346, 1},/*ANCSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 84, 4, 160, 0, 347, 1},/*FrntWinHeatSwt*/
    {5, CNA_BEHAVIOR_NONE, 81, 4, 160, 0, 348, 1},/*QLISurroundSet*/
    {5, CNA_BEHAVIOR_SEND, 83, 4, 160, 1, 349, 1},/*RearWinHeatCmd_TC*/
    {5, CNA_BEHAVIOR_NONE, 80, 4, 161, 0, 350, 1},/*T_BOX_ECallSet*/
    {5, CNA_BEHAVIOR_NONE, 95, 5, 161, 0, 351, 1},/*AMP_BestListegPosnReq*/
    {5, CNA_BEHAVIOR_NONE, 96, 5, 161, 0, 352, 1},/*AMP_Clari_FiReq*/
    {5, CNA_BEHAVIOR_SEND, 94, 5, 161, 1, 353, 1},/*AMP_GetDTCInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 91, 5, 162, 1, 354, 1},/*AMP_GetHWInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 93, 5, 163, 1, 355, 1},/*AMP_GetIntVoltInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 90, 5, 164, 1, 356, 1},/*AMP_GetSWInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 92, 5, 165, 1, 357, 1},/*AMP_GetTempInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 86, 5, 166, 0, 358, 1},/*AMP_HFMVolSet*/
    {5, CNA_BEHAVIOR_NONE, 89, 5, 166, 0, 359, 1},/*AMP_MainVolSet*/
    {5, CNA_BEHAVIOR_NONE, 88, 5, 166, 0, 360, 1},/*AMP_NaviVolSet*/
    {5, CNA_BEHAVIOR_NONE, 87, 5, 166, 0, 361, 1},/*AMP_TTSVolSet_VR*/
    {5, CNA_BEHAVIOR_NONE, 97, 5, 166, 0, 362, 1},/*IESS_MdlInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 98, 5, 166, 0, 363, 1},/*IESS_MdlSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 111, 6, 166, 1, 364, 1},/*ACAirInletReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 104, 6, 167, 1, 365, 1},/*ACAutoModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 107, 6, 168, 1, 366, 1},/*ACBlwrSpdReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 105, 6, 169, 1, 367, 1},/*ACCmprReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 110, 6, 170, 1, 368, 1},/*ACDrvAirDistribModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 108, 6, 171, 1, 369, 1},/*ACDrvTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 109, 6, 172, 1, 370, 1},/*ACFrntDefrostReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 112, 6, 173, 0, 371, 1},/*ACModReq_HUT*/
    {5, CNA_BEHAVIOR_SEND, 106, 6, 173, 1, 372, 1},/*ACPowerReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 100, 6, 174, 0, 373, 1},/*DrvSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 102, 6, 174, 0, 374, 1},/*DrvSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 101, 6, 174, 0, 375, 1},/*PassSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 103, 6, 174, 0, 376, 1},/*PassSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 113, 6, 174, 0, 377, 1},/*RLSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 114, 6, 174, 0, 378, 1},/*RRSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 115, 6, 174, 0, 379, 1},/*RemUpgrdSts*/
    {5, CNA_BEHAVIOR_CYCLE, 495, 39, 174, 1, 380, 1},/*RearFogLmpSwtSts_HUT*/
    {5, CNA_BEHAVIOR_CYCLE, 359, 27, 175, 1, 381, 1},/*ContnPrkgReq*/
    {5, CNA_BEHAVIOR_CYCLE, 357, 27, 176, 1, 382, 1},/*PrkgCtrlModReq*/
    {5, CNA_BEHAVIOR_CYCLE, 568, 44, 177, 1, 383, 1},/*ChairMemPosnSet*/
    {5, CNA_BEHAVIOR_CYCLE, 621, 44, 178, 1, 384, 1},/*EPSSteerModSwtReq*/
    {5, CNA_BEHAVIOR_CYCLE, 182, 11, 179, 1, 385, 1},/*HUT_AVHSwitchSts*/
    {5, CNA_BEHAVIOR_CYCLE, 181, 11, 180, 1, 386, 1},/*HUT_EPB_SwtPosn*/
    {5, CNA_BEHAVIOR_CYCLE, 183, 11, 181, 1, 387, 1},/*HUT_HDCSwitchCtrl*/
    {5, CNA_BEHAVIOR_CYCLE, 178, 11, 182, 1, 388, 1},/*ORVMFoldSwt_HUT*/
};

static CNA_SignalType cna_signalDatas[379] = {0u};
static const uint8 cna_noActionBuffer[183] =
{
    2u,
    0u,
    0u,
    0u,
    0u,
    0u,
    2u,
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
    127u,
    0u,
    127u,
    0u,
    64u,
    0u,
    0u,
    64u,
    0u,
    0u,
    64u,
    0u,
    64u,
    0u,
    2u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    2u,
    4u,
    3u,
    0u,
    6u,
    0u,
    0u,
    10u,
    0u,
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
    0u,
    0u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[742] =
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
    65535,
    65535,
    65535,
    65535,
    65535,
    320,
    322,
    323,
    318,
    311,
    305,
    304,
    303,
    307,
    314,
    312,
    321,
    313,
    308,
    309,
    319,
    310,
    315,
    316,
    302,
    317,
    306,
    324,
    65535,
    332,
    335,
    326,
    329,
    325,
    327,
    330,
    331,
    334,
    333,
    328,
    340,
    338,
    336,
    339,
    337,
    65535,
    348,
    351,
    350,
    349,
    346,
    344,
    347,
    345,
    343,
    341,
    342,
    352,
    353,
    65535,
    363,
    365,
    364,
    366,
    355,
    357,
    362,
    356,
    359,
    360,
    358,
    354,
    361,
    367,
    368,
    369,
    65535,
    17,
    18,
    25,
    26,
    28,
    30,
    24,
    31,
    32,
    20,
    29,
    22,
    21,
    19,
    23,
    27,
    34,
    33,
    65535,
    5,
    1,
    2,
    4,
    0,
    6,
    10,
    9,
    3,
    8,
    12,
    15,
    11,
    7,
    16,
    13,
    14,
    65535,
    261,
    260,
    263,
    262,
    259,
    274,
    269,
    272,
    270,
    271,
    276,
    273,
    266,
    267,
    265,
    264,
    275,
    268,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    378,
    65535,
    65535,
    376,
    375,
    377,
    65535,
    65535,
    154,
    155,
    151,
    156,
    163,
    158,
    157,
    169,
    168,
    166,
    159,
    164,
    165,
    162,
    160,
    152,
    153,
    167,
    161,
    150,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    292,
    298,
    295,
    296,
    293,
    300,
    294,
    291,
    290,
    297,
    299,
    301,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    252,
    253,
    251,
    254,
    255,
    250,
    256,
    257,
    258,
    65535,
    242,
    243,
    240,
    244,
    245,
    239,
    246,
    247,
    238,
    241,
    248,
    249,
    65535,
    228,
    231,
    222,
    233,
    236,
    219,
    220,
    235,
    237,
    234,
    227,
    232,
    221,
    226,
    224,
    225,
    223,
    230,
    229,
    65535,
    207,
    210,
    203,
    212,
    216,
    214,
    218,
    213,
    205,
    211,
    202,
    204,
    217,
    206,
    215,
    209,
    208,
    65535,
    282,
    280,
    285,
    277,
    289,
    279,
    278,
    284,
    283,
    281,
    288,
    286,
    287,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    95,
    105,
    98,
    96,
    103,
    102,
    100,
    101,
    99,
    104,
    97,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    372,
    65535,
    371,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    144,
    145,
    136,
    140,
    130,
    143,
    133,
    141,
    142,
    146,
    149,
    135,
    148,
    134,
    147,
    139,
    132,
    128,
    127,
    129,
    137,
    131,
    138,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    73,
    77,
    76,
    75,
    72,
    74,
    71,
    70,
    65535,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    65535,
    126,
    119,
    120,
    121,
    122,
    123,
    124,
    125,
    65535,
    86,
    87,
    88,
    90,
    92,
    93,
    91,
    94,
    89,
    65535,
    113,
    115,
    108,
    109,
    110,
    107,
    106,
    118,
    111,
    114,
    116,
    112,
    117,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    177,
    193,
    189,
    185,
    192,
    179,
    183,
    188,
    190,
    186,
    178,
    187,
    194,
    184,
    191,
    182,
    195,
    180,
    181,
    65535,
    176,
    174,
    175,
    65535,
    196,
    199,
    198,
    200,
    197,
    201,
    65535,
    65535,
    370,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    49,
    50,
    54,
    52,
    51,
    57,
    53,
    47,
    48,
    56,
    55,
    65535,
    65,
    59,
    62,
    68,
    66,
    64,
    60,
    58,
    63,
    61,
    69,
    67,
    65535,
    170,
    171,
    65535,
    172,
    173,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    373,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    374,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    40,
    35,
    43,
    41,
    42,
    44,
    45,
    46,
    36,
    37,
    38,
    39,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[389] = {0};

const CNA_ConfigType cna_config =
{
    379u,
    cna_signalConfigs,
    cna_signalDatas,
    183u,
    cna_noActionBuffer,
    389u,
    cna_currentBuffer,
    742u,
    CNA_IdTable
};


