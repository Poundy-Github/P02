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
#include "Std_Types.h"
#include "ComNoAction.h"
#ifndef SWC_IPC_CAN_MATRIX_EC24H
    #include "SWC_IPC_CANMatrix_EC24.h"
    #if ( 0x8b88adef != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
        #error " Noaction version dismatch!!! "
    #endif
#endif


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
static const CNA_SignalConfigType cna_signalConfigs[380] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 140, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 137, 8, 0, 0, 1, 1}, /* ALCMClrSet_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_NONE, 138, 8, 0, 0, 2, 1}, /* ALCMDynModSet_OLE */
    {/* Index 3 */ 5, CNA_BEHAVIOR_NONE, 144, 8, 0, 0, 3, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 4 */ 5, CNA_BEHAVIOR_NONE, 139, 8, 0, 0, 4, 1}, /* ALCMRhmSwt_OLE */
    {/* Index 5 */ 5, CNA_BEHAVIOR_NONE, 136, 8, 0, 0, 5, 1}, /* ALCMStatSwt_OLE */
    {/* Index 6 */ 5, CNA_BEHAVIOR_UNSEND, 141, 8, 0, 1, 6, 1}, /* CarWashModeReq */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 149, 8, 1, 1, 7, 1}, /* ChairRestSetSwt */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 145, 8, 2, 1, 8, 1}, /* ChildLockCmd */
    {/* Index 9 */ 5, CNA_BEHAVIOR_SEND, 143, 8, 3, 1, 9, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 10 */ 5, CNA_BEHAVIOR_SEND, 142, 8, 4, 1, 10, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 148, 8, 5, 1, 11, 1}, /* MiaoCallClsReq */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 146, 8, 6, 1, 12, 1}, /* MusicLightShowSet */
    {/* Index 13 */ 5, CNA_BEHAVIOR_UNSEND, 151, 8, 7, 1, 13, 1}, /* OTA_UpgrdModReq */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 152, 8, 8, 1, 14, 1}, /* SmtCsaSwt */
    {/* Index 15 */ 5, CNA_BEHAVIOR_NONE, 147, 8, 9, 0, 15, 1}, /* SpoilerSpdSet */
    {/* Index 16 */ 5, CNA_BEHAVIOR_NONE, 150, 8, 9, 0, 16, 1}, /* UltrAntitheftSwt */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 117, 7, 9, 1, 17, 1}, /* AUTODefrost_TC */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 118, 7, 10, 1, 18, 1}, /* AUTODefrost_VR */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 11, 1, 19, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 126, 7, 12, 1, 20, 1}, /* AutoViewChgCmd */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 13, 1, 21, 1}, /* CarMdlDispCmd */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 128, 7, 14, 1, 22, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 15, 1, 23, 1}, /* FPAS_AutoModSwt */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 123, 7, 16, 1, 24, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 119, 7, 17, 1, 25, 1}, /* HUT_VCUBattKeepTemp */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 120, 7, 18, 1, 26, 1}, /* LaneCalActvtCmd */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 19, 1, 27, 1}, /* MEBSwtSet */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 121, 7, 20, 1, 28, 1}, /* MODChgReq */
    {/* Index 29 */ 5, CNA_BEHAVIOR_SEND, 127, 7, 21, 1, 29, 1}, /* MdlColrChgCmd */
    {/* Index 30 */ 5, CNA_BEHAVIOR_SEND, 122, 7, 22, 1, 30, 1}, /* Radar_DispCmd */
    {/* Index 31 */ 5, CNA_BEHAVIOR_SEND, 124, 7, 23, 1, 31, 1}, /* Sgl_View_Sel */
    {/* Index 32 */ 5, CNA_BEHAVIOR_SEND, 125, 7, 24, 1, 32, 1}, /* SwToFieldCalRstCmd */
    {/* Index 33 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 25, 1, 33, 1}, /* View_SoftswitchCmd */
    {/* Index 34 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 26, 1, 34, 1}, /* WshSoftSwt */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 705, 47, 27, 1, 35, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 36 */ 5, CNA_BEHAVIOR_UNSEND, 712, 47, 28, 1, 36, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 37 */ 5, CNA_BEHAVIOR_NONE, 713, 47, 29, 0, 37, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 38 */ 5, CNA_BEHAVIOR_NONE, 714, 47, 29, 0, 38, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 39 */ 5, CNA_BEHAVIOR_NONE, 715, 47, 29, 0, 39, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 40 */ 5, CNA_BEHAVIOR_SEND, 704, 47, 29, 1, 40, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 707, 47, 30, 1, 41, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 42 */ 5, CNA_BEHAVIOR_SEND, 708, 47, 31, 1, 42, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 43 */ 5, CNA_BEHAVIOR_SEND, 706, 47, 32, 1, 43, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 44 */ 5, CNA_BEHAVIOR_SEND, 709, 47, 33, 1, 44, 1}, /* SlotNum_VR */
    {/* Index 45 */ 5, CNA_BEHAVIOR_SEND, 710, 47, 34, 1, 45, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 46 */ 5, CNA_BEHAVIOR_SEND, 711, 47, 35, 1, 46, 1}, /* UserDefinedParkCmd */
    {/* Index 47 */ 5, CNA_BEHAVIOR_SEND, 509, 40, 36, 1, 47, 1}, /* ApprLightSwt */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 510, 40, 37, 0, 48, 1}, /* DoorCtrlLightSwt */
    {/* Index 49 */ 5, CNA_BEHAVIOR_SEND, 502, 40, 37, 1, 49, 1}, /* DrvSeatMassgModSet */
    {/* Index 50 */ 5, CNA_BEHAVIOR_SEND, 503, 40, 38, 1, 50, 1}, /* HUT_V2LStart */
    {/* Index 51 */ 5, CNA_BEHAVIOR_UNSEND, 506, 40, 39, 1, 51, 1}, /* InCarTempMaxSet */
    {/* Index 52 */ 5, CNA_BEHAVIOR_UNSEND, 505, 40, 40, 1, 52, 1}, /* InCarTempMinSet */
    {/* Index 53 */ 5, CNA_BEHAVIOR_SEND, 508, 40, 41, 1, 53, 1}, /* LockWelLightSwt */
    {/* Index 54 */ 5, CNA_BEHAVIOR_SEND, 504, 40, 42, 1, 54, 1}, /* PassSeatMassgModSet */
    {/* Index 55 */ 5, CNA_BEHAVIOR_SEND, 512, 40, 43, 1, 55, 1}, /* RepairModReq */
    {/* Index 56 */ 5, CNA_BEHAVIOR_SEND, 511, 40, 44, 1, 56, 1}, /* SmtACSwt */
    {/* Index 57 */ 5, CNA_BEHAVIOR_SEND, 507, 40, 45, 1, 57, 1}, /* UnlockWelLightSwt */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 521, 41, 46, 1, 58, 1}, /* CLOutletHozlPosnCmd */
    {/* Index 59 */ 5, CNA_BEHAVIOR_SEND, 515, 41, 47, 1, 59, 1}, /* CLOutletSet */
    {/* Index 60 */ 5, CNA_BEHAVIOR_SEND, 520, 41, 48, 1, 60, 1}, /* CLOutletVertPosnCmd */
    {/* Index 61 */ 5, CNA_BEHAVIOR_SEND, 523, 41, 49, 1, 61, 1}, /* CROutletHozlPosnCmd */
    {/* Index 62 */ 5, CNA_BEHAVIOR_SEND, 516, 41, 50, 1, 62, 1}, /* CROutletSet */
    {/* Index 63 */ 5, CNA_BEHAVIOR_SEND, 522, 41, 51, 1, 63, 1}, /* CROutletVertPosnCmd */
    {/* Index 64 */ 5, CNA_BEHAVIOR_SEND, 519, 41, 52, 1, 64, 1}, /* LOutletHozlPosnCmd */
    {/* Index 65 */ 5, CNA_BEHAVIOR_SEND, 514, 41, 53, 1, 65, 1}, /* LOutletSet */
    {/* Index 66 */ 5, CNA_BEHAVIOR_SEND, 518, 41, 54, 1, 66, 1}, /* LOutletVertPosnCmd */
    {/* Index 67 */ 5, CNA_BEHAVIOR_SEND, 525, 41, 55, 1, 67, 1}, /* ROutletHozlPosnCmd */
    {/* Index 68 */ 5, CNA_BEHAVIOR_SEND, 517, 41, 56, 1, 68, 1}, /* ROutletSet */
    {/* Index 69 */ 5, CNA_BEHAVIOR_SEND, 524, 41, 57, 1, 69, 1}, /* ROutletVertPosnCmd */
    {/* Index 70 */ 5, CNA_BEHAVIOR_SEND, 409, 30, 58, 1, 70, 1}, /* ACMaxReq_TC */
    {/* Index 71 */ 5, CNA_BEHAVIOR_SEND, 408, 30, 59, 1, 71, 1}, /* ACMaxReq_VR */
    {/* Index 72 */ 5, CNA_BEHAVIOR_SEND, 406, 30, 60, 1, 72, 1}, /* ESCMAdjCmd */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 402, 30, 61, 0, 73, 1}, /* LockWinSet */
    {/* Index 74 */ 5, CNA_BEHAVIOR_NONE, 407, 30, 61, 0, 74, 1}, /* NozHeatSwt */
    {/* Index 75 */ 5, CNA_BEHAVIOR_SEND, 405, 30, 61, 1, 75, 1}, /* SpoilerCtrlCmd */
    {/* Index 76 */ 5, CNA_BEHAVIOR_NONE, 404, 30, 62, 0, 76, 1}, /* SpoilerFixModSwt */
    {/* Index 77 */ 5, CNA_BEHAVIOR_NONE, 403, 30, 62, 0, 77, 1}, /* SpoilerWelModSwt */
    {/* Index 78 */ 5, CNA_BEHAVIOR_NONE, 411, 31, 62, 0, 78, 1}, /* MultiColorNr1 */
    {/* Index 79 */ 5, CNA_BEHAVIOR_NONE, 412, 31, 62, 0, 79, 1}, /* MultiColorNr2 */
    {/* Index 80 */ 5, CNA_BEHAVIOR_NONE, 413, 31, 62, 0, 80, 1}, /* MultiColorNr3 */
    {/* Index 81 */ 5, CNA_BEHAVIOR_NONE, 414, 31, 62, 0, 81, 1}, /* MultiColorNr4 */
    {/* Index 82 */ 5, CNA_BEHAVIOR_NONE, 415, 31, 62, 0, 82, 1}, /* MultiColorNr5 */
    {/* Index 83 */ 5, CNA_BEHAVIOR_NONE, 416, 31, 62, 0, 83, 1}, /* MultiColorNr6 */
    {/* Index 84 */ 5, CNA_BEHAVIOR_NONE, 417, 31, 62, 0, 84, 1}, /* MultiColorNr7 */
    {/* Index 85 */ 5, CNA_BEHAVIOR_NONE, 418, 31, 62, 0, 85, 1}, /* MultiColorNr8 */
    {/* Index 86 */ 5, CNA_BEHAVIOR_SEND, 429, 33, 62, 1, 86, 1}, /* ACUltravioletReq_TC */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 430, 33, 63, 1, 87, 1}, /* ACUltravioletReq_VR */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 431, 33, 64, 1, 88, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 89 */ 5, CNA_BEHAVIOR_SEND, 437, 33, 65, 1, 89, 1}, /* FootALCMFlashFreq */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 432, 33, 66, 1, 90, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 91 */ 5, CNA_BEHAVIOR_SEND, 435, 33, 67, 1, 91, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 433, 33, 68, 1, 92, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 434, 33, 69, 1, 93, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 94 */ 5, CNA_BEHAVIOR_SEND, 436, 33, 70, 1, 94, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 95 */ 5, CNA_BEHAVIOR_NONE, 330, 25, 71, 0, 95, 1}, /* ADASDispSwt */
    {/* Index 96 */ 5, CNA_BEHAVIOR_NONE, 333, 25, 71, 0, 96, 1}, /* BTPhoneDispSwt */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 340, 25, 71, 1, 97, 1}, /* BackReq_AVM */
    {/* Index 98 */ 5, CNA_BEHAVIOR_NONE, 332, 25, 72, 0, 98, 1}, /* EngspdDispSwt */
    {/* Index 99 */ 5, CNA_BEHAVIOR_SEND, 338, 25, 72, 1, 99, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 100 */ 5, CNA_BEHAVIOR_NONE, 336, 25, 73, 0, 100, 1}, /* HUD_DisplayModeCfg */
    {/* Index 101 */ 5, CNA_BEHAVIOR_SEND, 337, 25, 73, 1, 101, 1}, /* HUD_HeightLvlSwt */
    {/* Index 102 */ 5, CNA_BEHAVIOR_NONE, 335, 25, 74, 0, 102, 1}, /* HUD_RotateAngleCfg */
    {/* Index 103 */ 5, CNA_BEHAVIOR_NONE, 334, 25, 74, 0, 103, 1}, /* HUD_RotateDirCfg */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 339, 25, 74, 1, 104, 1}, /* HUD_SwtReq */
    {/* Index 105 */ 5, CNA_BEHAVIOR_NONE, 331, 25, 75, 0, 105, 1}, /* NaviDispSwt */
    {/* Index 106 */ 5, CNA_BEHAVIOR_NONE, 445, 34, 75, 0, 106, 1}, /* ActvEntryLockSet */
    {/* Index 107 */ 5, CNA_BEHAVIOR_NONE, 444, 34, 75, 0, 107, 1}, /* ActvEntryUnlockSet */
    {/* Index 108 */ 5, CNA_BEHAVIOR_NONE, 441, 34, 75, 0, 108, 1}, /* BTAPAEntryLockSet */
    {/* Index 109 */ 5, CNA_BEHAVIOR_NONE, 442, 34, 75, 0, 109, 1}, /* BTAPALvngUnlockSet */
    {/* Index 110 */ 5, CNA_BEHAVIOR_NONE, 443, 34, 75, 0, 110, 1}, /* ClsWinSpdSet */
    {/* Index 111 */ 5, CNA_BEHAVIOR_SEND, 447, 34, 75, 1, 111, 1}, /* DrvDoorALCMClrSet */
    {/* Index 112 */ 5, CNA_BEHAVIOR_NONE, 450, 34, 76, 0, 112, 1}, /* DrvDoorALCMSwt */
    {/* Index 113 */ 5, CNA_BEHAVIOR_SEND, 439, 34, 76, 1, 113, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 114 */ 5, CNA_BEHAVIOR_SEND, 448, 34, 77, 1, 114, 1}, /* LRDoorALCMClrSet */
    {/* Index 115 */ 5, CNA_BEHAVIOR_NONE, 440, 34, 78, 0, 115, 1}, /* LockPromptFunSet */
    {/* Index 116 */ 5, CNA_BEHAVIOR_SEND, 449, 34, 78, 1, 116, 1}, /* PassDoorALCMClrSet */
    {/* Index 117 */ 5, CNA_BEHAVIOR_NONE, 451, 34, 79, 0, 117, 1}, /* PassDoorALCMSwt */
    {/* Index 118 */ 5, CNA_BEHAVIOR_SEND, 446, 34, 79, 1, 118, 1}, /* PassSeatMassgLvlSet */
    {/* Index 119 */ 5, CNA_BEHAVIOR_NONE, 421, 32, 80, 0, 119, 1}, /* MultiColorNr10 */
    {/* Index 120 */ 5, CNA_BEHAVIOR_NONE, 422, 32, 80, 0, 120, 1}, /* MultiColorNr11 */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 423, 32, 80, 0, 121, 1}, /* MultiColorNr12 */
    {/* Index 122 */ 5, CNA_BEHAVIOR_NONE, 424, 32, 80, 0, 122, 1}, /* MultiColorNr13 */
    {/* Index 123 */ 5, CNA_BEHAVIOR_NONE, 425, 32, 80, 0, 123, 1}, /* MultiColorNr14 */
    {/* Index 124 */ 5, CNA_BEHAVIOR_NONE, 426, 32, 80, 0, 124, 1}, /* MultiColorNr15 */
    {/* Index 125 */ 5, CNA_BEHAVIOR_NONE, 427, 32, 80, 0, 125, 1}, /* MultiColorNr16 */
    {/* Index 126 */ 5, CNA_BEHAVIOR_NONE, 420, 32, 80, 0, 126, 1}, /* MultiColorNr9 */
    {/* Index 127 */ 5, CNA_BEHAVIOR_SEND, 384, 28, 80, 1, 127, 1}, /* ACFGAChanTyp_TC */
    {/* Index 128 */ 5, CNA_BEHAVIOR_SEND, 383, 28, 81, 1, 128, 1}, /* ACFGAEnaReq_TC */
    {/* Index 129 */ 5, CNA_BEHAVIOR_SEND, 385, 28, 82, 1, 129, 1}, /* ACFGALvlReq_TC */
    {/* Index 130 */ 6, CNA_BEHAVIOR_NONE, 370, 28, 83, 0, 130, 1}, /* ALCMDynModSet */
    {/* Index 131 */ 6, CNA_BEHAVIOR_UNSEND, 387, 28, 83, 1, 131, 1}, /* ApproachLampSet */
    {/* Index 132 */ 5, CNA_BEHAVIOR_SEND, 382, 28, 84, 1, 132, 1}, /* BackReq_APS */
    {/* Index 133 */ 6, CNA_BEHAVIOR_SEND, 372, 28, 85, 1, 133, 1}, /* ChairMemPosnSetSwt */
    {/* Index 134 */ 5, CNA_BEHAVIOR_SEND, 379, 28, 86, 1, 134, 1}, /* DeletePath1Cmd */
    {/* Index 135 */ 5, CNA_BEHAVIOR_SEND, 377, 28, 87, 1, 135, 1}, /* DeletePath2Cmd */
    {/* Index 136 */ 6, CNA_BEHAVIOR_SEND, 368, 28, 88, 1, 136, 1}, /* DrvWinSwtReq_VR */
    {/* Index 137 */ 6, CNA_BEHAVIOR_UNSEND, 386, 28, 89, 1, 137, 1}, /* FlaoutUnlockSet */
    {/* Index 138 */ 5, CNA_BEHAVIOR_SEND, 388, 28, 90, 1, 138, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 139 */ 5, CNA_BEHAVIOR_SEND, 381, 28, 91, 1, 139, 1}, /* ParkMdlCmd */
    {/* Index 140 */ 6, CNA_BEHAVIOR_SEND, 369, 28, 92, 1, 140, 1}, /* PassWinSwtReq_VR */
    {/* Index 141 */ 5, CNA_BEHAVIOR_SEND, 373, 28, 93, 1, 141, 1}, /* PathLrngFinshCmd */
    {/* Index 142 */ 5, CNA_BEHAVIOR_SEND, 374, 28, 94, 1, 142, 1}, /* PathLrngStartCmd */
    {/* Index 143 */ 6, CNA_BEHAVIOR_NONE, 371, 28, 95, 0, 143, 1}, /* PrkInDirChoice */
    {/* Index 144 */ 6, CNA_BEHAVIOR_SEND, 366, 28, 95, 1, 144, 1}, /* RLWinSwtReq_VR */
    {/* Index 145 */ 6, CNA_BEHAVIOR_SEND, 367, 28, 96, 1, 145, 1}, /* RRWinSwtReq_VR */
    {/* Index 146 */ 5, CNA_BEHAVIOR_SEND, 375, 28, 97, 1, 146, 1}, /* SelPrkOutDirReq */
    {/* Index 147 */ 5, CNA_BEHAVIOR_SEND, 380, 28, 98, 1, 147, 1}, /* SelPrkgFctnCmd */
    {/* Index 148 */ 5, CNA_BEHAVIOR_SEND, 378, 28, 99, 1, 148, 1}, /* StartPrkgPath1Cmd */
    {/* Index 149 */ 5, CNA_BEHAVIOR_SEND, 376, 28, 100, 1, 149, 1}, /* StartPrkgPath2Cmd */
    {/* Index 150 */ 5, CNA_BEHAVIOR_NONE, 205, 12, 101, 0, 150, 1}, /* ABSLmpSet */
    {/* Index 151 */ 5, CNA_BEHAVIOR_SEND, 188, 12, 101, 1, 151, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 152 */ 5, CNA_BEHAVIOR_SEND, 201, 12, 102, 1, 152, 1}, /* ACEAHReq_TC */
    {/* Index 153 */ 5, CNA_BEHAVIOR_SEND, 202, 12, 103, 1, 153, 1}, /* ACEAHReq_VR */
    {/* Index 154 */ 5, CNA_BEHAVIOR_SEND, 186, 12, 104, 1, 154, 1}, /* ACOperMod_TC */
    {/* Index 155 */ 5, CNA_BEHAVIOR_SEND, 187, 12, 105, 1, 155, 1}, /* ACOperMod_VR */
    {/* Index 156 */ 5, CNA_BEHAVIOR_SEND, 189, 12, 106, 1, 156, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 157 */ 5, CNA_BEHAVIOR_SEND, 192, 12, 107, 1, 157, 1}, /* APSPrkgTypSeln */
    {/* Index 158 */ 5, CNA_BEHAVIOR_SEND, 191, 12, 108, 1, 158, 1}, /* APSSwtReq_VR */
    {/* Index 159 */ 5, CNA_BEHAVIOR_NONE, 196, 12, 109, 0, 159, 1}, /* AutoWshWipSet */
    {/* Index 160 */ 5, CNA_BEHAVIOR_NONE, 200, 12, 109, 0, 160, 1}, /* DoorUnlockModSet */
    {/* Index 161 */ 5, CNA_BEHAVIOR_SEND, 204, 12, 109, 1, 161, 1}, /* PASExitSpdSwt */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 199, 12, 110, 0, 162, 1}, /* ParkLmpSet */
    {/* Index 163 */ 5, CNA_BEHAVIOR_SEND, 190, 12, 110, 1, 163, 1}, /* SDWSwtSet */
    {/* Index 164 */ 5, CNA_BEHAVIOR_NONE, 197, 12, 111, 0, 164, 1}, /* SeekVehSet */
    {/* Index 165 */ 5, CNA_BEHAVIOR_NONE, 198, 12, 111, 0, 165, 1}, /* SpdAutoLockModSet */
    {/* Index 166 */ 5, CNA_BEHAVIOR_NONE, 195, 12, 111, 0, 166, 1}, /* SportModLightSet */
    {/* Index 167 */ 5, CNA_BEHAVIOR_SEND, 203, 12, 111, 1, 167, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 194, 12, 112, 1, 168, 1}, /* SunRoofSwtReq_VR */
    {/* Index 169 */ 5, CNA_BEHAVIOR_SEND, 193, 12, 113, 1, 169, 1}, /* SunShadeSwtReq_VR */
    {/* Index 170 */ 5, CNA_BEHAVIOR_SEND, 527, 42, 114, 1, 170, 1}, /* LSideOutletModSet */
    {/* Index 171 */ 5, CNA_BEHAVIOR_SEND, 528, 42, 115, 1, 171, 1}, /* RSideOutletModSet */
    {/* Index 172 */ 5, CNA_BEHAVIOR_UNSEND, 530, 43, 116, 1, 172, 1}, /* ScenarioSwtID */
    {/* Index 173 */ 5, CNA_BEHAVIOR_UNSEND, 531, 43, 117, 1, 173, 1}, /* ScenarioSwtReq */
    {/* Index 174 */ 5, CNA_BEHAVIOR_UNSEND, 484, 37, 118, 1, 174, 1}, /* HUT_AccelPedalSnvtyAdj */
    {/* Index 175 */ 5, CNA_BEHAVIOR_UNSEND, 485, 37, 119, 1, 175, 1}, /* HUT_CreepSwt */
    {/* Index 176 */ 5, CNA_BEHAVIOR_UNSEND, 483, 37, 120, 1, 176, 1}, /* HUT_EneRecoInteAdj */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 463, 36, 121, 0, 177, 1}, /* ALCMBreSwt */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 473, 36, 121, 0, 178, 1}, /* ALCMFloSwt */
    {/* Index 179 */ 5, CNA_BEHAVIOR_SEND, 468, 36, 121, 1, 179, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 180 */ 5, CNA_BEHAVIOR_SEND, 480, 36, 122, 1, 180, 1}, /* FootALCMClrSet */
    {/* Index 181 */ 5, CNA_BEHAVIOR_SEND, 481, 36, 123, 1, 181, 1}, /* FootALCMLightLvlSet */
    {/* Index 182 */ 5, CNA_BEHAVIOR_NONE, 478, 36, 124, 0, 182, 1}, /* FootALCMSwt */
    {/* Index 183 */ 5, CNA_BEHAVIOR_SEND, 469, 36, 124, 1, 183, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 184 */ 5, CNA_BEHAVIOR_NONE, 476, 36, 125, 0, 184, 1}, /* LRDoorALCMSwt */
    {/* Index 185 */ 5, CNA_BEHAVIOR_SEND, 466, 36, 125, 1, 185, 1}, /* LeftPanelALCMClrSet */
    {/* Index 186 */ 5, CNA_BEHAVIOR_SEND, 472, 36, 126, 1, 186, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 474, 36, 127, 0, 187, 1}, /* LeftPanelALCMSwt */
    {/* Index 188 */ 5, CNA_BEHAVIOR_SEND, 470, 36, 127, 1, 188, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 189 */ 5, CNA_BEHAVIOR_SEND, 465, 36, 128, 1, 189, 1}, /* RRDoorALCMClrSet */
    {/* Index 190 */ 5, CNA_BEHAVIOR_SEND, 471, 36, 129, 1, 190, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 477, 36, 130, 0, 191, 1}, /* RRDoorALCMSwt */
    {/* Index 192 */ 5, CNA_BEHAVIOR_SEND, 467, 36, 130, 1, 192, 1}, /* RightPanelALCMClrSet */
    {/* Index 193 */ 5, CNA_BEHAVIOR_SEND, 464, 36, 131, 1, 193, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 194 */ 5, CNA_BEHAVIOR_NONE, 475, 36, 132, 0, 194, 1}, /* RightPanelALCMSwt */
    {/* Index 195 */ 5, CNA_BEHAVIOR_NONE, 479, 36, 132, 0, 195, 1}, /* RoofALCMSwt */
    {/* Index 196 */ 5, CNA_BEHAVIOR_NONE, 487, 38, 132, 0, 196, 1}, /* DrvWinSwtReq */
    {/* Index 197 */ 5, CNA_BEHAVIOR_NONE, 491, 38, 132, 0, 197, 1}, /* InCarTempSet */
    {/* Index 198 */ 5, CNA_BEHAVIOR_NONE, 489, 38, 132, 0, 198, 1}, /* PassWinSwtReq */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 488, 38, 132, 0, 199, 1}, /* RLWinSwtReq */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 490, 38, 132, 0, 200, 1}, /* RRWinSwtReq */
    {/* Index 201 */ 5, CNA_BEHAVIOR_SEND, 492, 38, 132, 1, 201, 1}, /* SmtSeatSwt */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 295, 19, 133, 0, 202, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 203 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 133, 0, 203, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 204 */ 5, CNA_BEHAVIOR_NONE, 296, 19, 133, 0, 204, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 205 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 133, 0, 205, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 206 */ 5, CNA_BEHAVIOR_NONE, 298, 19, 133, 0, 206, 1}, /* ADAS_Stub_LastStub */
    {/* Index 207 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 133, 0, 207, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 301, 19, 133, 0, 208, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 300, 19, 133, 0, 209, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 133, 0, 210, 2}, /* ADAS_Stub_Offset */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 294, 19, 133, 0, 212, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 133, 0, 213, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 133, 0, 214, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 133, 0, 215, 1}, /* ADAS_Stub_Retr */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 299, 19, 133, 0, 216, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 133, 0, 217, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 297, 19, 133, 0, 218, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 133, 0, 219, 1}, /* ADAS_Stub_Update */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 133, 0, 220, 1}, /* ADAS_Seg_Brdg */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 133, 0, 221, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 277, 18, 133, 0, 222, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 133, 0, 223, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 281, 18, 133, 0, 224, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 279, 18, 133, 0, 225, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 280, 18, 133, 0, 226, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 278, 18, 133, 0, 227, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 275, 18, 133, 0, 228, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 133, 0, 229, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 283, 18, 133, 0, 230, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 282, 18, 133, 0, 231, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 133, 0, 232, 2}, /* ADAS_Seg_Offset */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 276, 18, 133, 0, 234, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 133, 0, 235, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 274, 18, 133, 0, 236, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 133, 0, 237, 1}, /* ADAS_Seg_Retr */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 133, 0, 238, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 133, 0, 239, 1}, /* ADAS_Seg_Update */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 260, 17, 133, 0, 240, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 257, 17, 133, 0, 241, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 240 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 133, 0, 242, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 241 */ 5, CNA_BEHAVIOR_NONE, 261, 17, 133, 0, 243, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 242 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 133, 0, 245, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 243 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 133, 0, 246, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 244 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 133, 0, 248, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 256, 17, 133, 0, 249, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 258, 17, 133, 0, 250, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 259, 17, 133, 0, 251, 1}, /* ADAS_ProfShort_Update */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 262, 17, 133, 0, 252, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 263, 17, 133, 0, 254, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 250 */ 5, CNA_BEHAVIOR_NONE, 247, 16, 133, 0, 256, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 244, 16, 133, 0, 257, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 242, 16, 133, 0, 258, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 253 */ 5, CNA_BEHAVIOR_NONE, 243, 16, 133, 0, 259, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 245, 16, 133, 0, 261, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 255 */ 5, CNA_BEHAVIOR_NONE, 246, 16, 133, 0, 262, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 256 */ 5, CNA_BEHAVIOR_NONE, 248, 16, 133, 0, 263, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 249, 16, 133, 0, 264, 1}, /* ADAS_ProfLong_Update */
    {/* Index 258 */ 5, CNA_BEHAVIOR_NONE, 250, 16, 133, 0, 265, 4}, /* ADAS_ProfLong_Value */
    {/* Index 259 */ 5, CNA_BEHAVIOR_SEND, 158, 9, 133, 1, 269, 1}, /* ACAIUReq_VR */
    {/* Index 260 */ 5, CNA_BEHAVIOR_SEND, 155, 9, 134, 1, 270, 1}, /* ACAQSReq_VR */
    {/* Index 261 */ 5, CNA_BEHAVIOR_SEND, 154, 9, 135, 1, 271, 1}, /* ACDualReq_VR */
    {/* Index 262 */ 5, CNA_BEHAVIOR_SEND, 157, 9, 136, 1, 272, 1}, /* ACPassTempReq_VR */
    {/* Index 263 */ 5, CNA_BEHAVIOR_SEND, 156, 9, 137, 1, 273, 1}, /* ACRearDefrstReq_VR */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 169, 9, 138, 0, 274, 1}, /* ALCMClrSet */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 168, 9, 138, 0, 275, 1}, /* ALCMDynSwt */
    {/* Index 266 */ 5, CNA_BEHAVIOR_NONE, 166, 9, 138, 0, 276, 1}, /* ALCMRhmSwt */
    {/* Index 267 */ 5, CNA_BEHAVIOR_NONE, 167, 9, 138, 0, 277, 1}, /* ALCMStatSwt */
    {/* Index 268 */ 3, CNA_BEHAVIOR_SEND, 171, 9, 138, 1, 278, 1}, /* HUT_BeanIDReq */
    {/* Index 269 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 139, 1, 279, 1}, /* HUT_ECOACLimnSet */
    {/* Index 270 */ 5, CNA_BEHAVIOR_SEND, 162, 9, 140, 1, 280, 1}, /* HUT_ECODrvModReq */
    {/* Index 271 */ 5, CNA_BEHAVIOR_NONE, 163, 9, 141, 0, 281, 1}, /* HUT_ECOSpdLim */
    {/* Index 272 */ 5, CNA_BEHAVIOR_UNSEND, 161, 9, 141, 1, 282, 1}, /* HUT_EgyRecvrySet */
    {/* Index 273 */ 5, CNA_BEHAVIOR_NONE, 165, 9, 142, 0, 283, 1}, /* HUT_ImdChrgSet */
    {/* Index 274 */ 5, CNA_BEHAVIOR_NONE, 159, 9, 142, 0, 284, 1}, /* IPVolSet */
    {/* Index 275 */ 5, CNA_BEHAVIOR_SEND, 170, 9, 142, 1, 285, 1}, /* PASSwtReq_VR */
    {/* Index 276 */ 5, CNA_BEHAVIOR_NONE, 164, 9, 143, 0, 286, 1}, /* VSGMuteSwSet */
    {/* Index 277 */ 5, CNA_BEHAVIOR_NONE, 306, 20, 143, 0, 287, 1}, /* ADASDispSwt_VR */
    {/* Index 278 */ 5, CNA_BEHAVIOR_NONE, 309, 20, 143, 0, 288, 1}, /* BTPhoneDispSwt_VR */
    {/* Index 279 */ 5, CNA_BEHAVIOR_NONE, 308, 20, 143, 0, 289, 1}, /* EngspdDispSwt_VR */
    {/* Index 280 */ 5, CNA_BEHAVIOR_NONE, 304, 20, 143, 0, 290, 1}, /* HUD_BrightnessLvlSwt_VR */
    {/* Index 281 */ 5, CNA_BEHAVIOR_NONE, 312, 20, 143, 0, 291, 1}, /* HUD_DisplayModeCfg_VR */
    {/* Index 282 */ 5, CNA_BEHAVIOR_NONE, 303, 20, 143, 0, 292, 1}, /* HUD_HeightLvlSwt_VR */
    {/* Index 283 */ 5, CNA_BEHAVIOR_NONE, 311, 20, 143, 0, 293, 1}, /* HUD_RotateAngleCfg_VR */
    {/* Index 284 */ 5, CNA_BEHAVIOR_NONE, 310, 20, 143, 0, 294, 1}, /* HUD_RotateDirCfg_VR */
    {/* Index 285 */ 5, CNA_BEHAVIOR_NONE, 305, 20, 143, 0, 295, 1}, /* HUD_SwtReq_VR */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 314, 20, 143, 1, 296, 1}, /* HUT_BattSOCLim */
    {/* Index 287 */ 5, CNA_BEHAVIOR_UNSEND, 315, 20, 144, 1, 297, 1}, /* HUT_GModeSet */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 313, 20, 145, 1, 298, 1}, /* HUT_RemtEngCtrl */
    {/* Index 289 */ 5, CNA_BEHAVIOR_NONE, 307, 20, 146, 0, 299, 1}, /* NaviDispSwt_VR */
    {/* Index 290 */ 5, CNA_BEHAVIOR_NONE, 223, 14, 146, 0, 300, 1}, /* AVMMediaVolLvlReq */
    {/* Index 291 */ 5, CNA_BEHAVIOR_NONE, 222, 14, 146, 0, 301, 1}, /* AVMSwtReq */
    {/* Index 292 */ 5, CNA_BEHAVIOR_SEND, 215, 14, 146, 1, 302, 1}, /* BackgroundLightLvlSet */
    {/* Index 293 */ 5, CNA_BEHAVIOR_NONE, 219, 14, 147, 0, 303, 1}, /* DispModSet */
    {/* Index 294 */ 5, CNA_BEHAVIOR_NONE, 221, 14, 147, 0, 304, 1}, /* FPASChanSwtReq */
    {/* Index 295 */ 5, CNA_BEHAVIOR_SEND, 217, 14, 147, 1, 305, 1}, /* HUT_V2VStart */
    {/* Index 296 */ 5, CNA_BEHAVIOR_NONE, 218, 14, 148, 0, 306, 1}, /* ManCmpSet */
    {/* Index 297 */ 5, CNA_BEHAVIOR_NONE, 224, 14, 148, 0, 307, 1}, /* NaviMediaVolLvlReq */
    {/* Index 298 */ 5, CNA_BEHAVIOR_UNSEND, 216, 14, 148, 1, 308, 1}, /* OPDSwtSts */
    {/* Index 299 */ 5, CNA_BEHAVIOR_UNSEND, 225, 14, 149, 1, 309, 1}, /* PLGReq_VR */
    {/* Index 300 */ 5, CNA_BEHAVIOR_NONE, 220, 14, 150, 0, 310, 1}, /* RPASChanSwtReq */
    {/* Index 301 */ 5, CNA_BEHAVIOR_UNSEND, 226, 14, 150, 1, 311, 1}, /* WPC_SwtReq */
    {/* Index 302 */ 5, CNA_BEHAVIOR_SEND, 64, 3, 151, 1, 312, 1}, /* ACAIUReq_TC */
    {/* Index 303 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 152, 1, 313, 1}, /* ACAQSReq_TC */
    {/* Index 304 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 153, 1, 314, 1}, /* ACAirInletReq_TC */
    {/* Index 305 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 154, 1, 315, 1}, /* ACAutoModReq_TC */
    {/* Index 306 */ 5, CNA_BEHAVIOR_SEND, 66, 3, 155, 1, 316, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 307 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 156, 1, 317, 1}, /* ACCmprReq_TC */
    {/* Index 308 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 157, 1, 318, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 309 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 158, 1, 319, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 310 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 159, 1, 320, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 311 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 160, 1, 321, 1}, /* ACDualReq_TC */
    {/* Index 312 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 161, 1, 322, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 313 */ 5, CNA_BEHAVIOR_SEND, 57, 3, 162, 1, 323, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 314 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 163, 1, 324, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 315 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 164, 1, 325, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 316 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 165, 1, 326, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 317 */ 5, CNA_BEHAVIOR_SEND, 65, 3, 166, 1, 327, 1}, /* ACOffReq_TC */
    {/* Index 318 */ 5, CNA_BEHAVIOR_NONE, 48, 3, 167, 0, 328, 1}, /* BattSaveDelayTimeSet */
    {/* Index 319 */ 5, CNA_BEHAVIOR_NONE, 60, 3, 167, 0, 329, 1}, /* ChairMemPosnEna */
    {/* Index 320 */ 5, CNA_BEHAVIOR_NONE, 45, 3, 167, 0, 330, 1}, /* DomeLmpDlyTimSet */
    {/* Index 321 */ 5, CNA_BEHAVIOR_NONE, 56, 3, 167, 0, 331, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 322 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 167, 0, 332, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 323 */ 5, CNA_BEHAVIOR_NONE, 47, 3, 167, 0, 333, 1}, /* RearviewFoldModSet */
    {/* Index 324 */ 5, CNA_BEHAVIOR_NONE, 67, 3, 167, 0, 334, 1}, /* TranPMode_Req */
    {/* Index 325 */ 5, CNA_BEHAVIOR_NONE, 73, 4, 167, 0, 335, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 326 */ 5, CNA_BEHAVIOR_NONE, 71, 4, 167, 0, 336, 1}, /* AMP_BeepSourceSet */
    {/* Index 327 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 167, 0, 337, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 328 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 167, 0, 338, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 72, 4, 167, 0, 339, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 330 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 167, 0, 340, 1}, /* AMP_LRDrvSideSet */
    {/* Index 331 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 167, 0, 341, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 332 */ 5, CNA_BEHAVIOR_NONE, 69, 4, 167, 0, 342, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 333 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 167, 0, 343, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 334 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 167, 0, 344, 1}, /* AMP_MuteSet */
    {/* Index 335 */ 5, CNA_BEHAVIOR_NONE, 70, 4, 167, 0, 345, 1}, /* AMP_NaviSourceSet */
    {/* Index 336 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 167, 0, 346, 1}, /* ANCSwtSet */
    {/* Index 337 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 167, 0, 347, 1}, /* FrntWinHeatSwt */
    {/* Index 338 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 167, 0, 348, 1}, /* QLISurroundSet */
    {/* Index 339 */ 5, CNA_BEHAVIOR_SEND, 83, 4, 167, 1, 349, 1}, /* RearWinHeatCmd_TC */
    {/* Index 340 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 168, 0, 350, 1}, /* T_BOX_ECallSet */
    {/* Index 341 */ 5, CNA_BEHAVIOR_NONE, 95, 5, 168, 0, 351, 1}, /* AMP_BestListegPosnReq */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 96, 5, 168, 0, 352, 1}, /* AMP_Clari_FiReq */
    {/* Index 343 */ 5, CNA_BEHAVIOR_SEND, 94, 5, 168, 1, 353, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 344 */ 5, CNA_BEHAVIOR_SEND, 91, 5, 169, 1, 354, 1}, /* AMP_GetHWInfoReq */
    {/* Index 345 */ 5, CNA_BEHAVIOR_SEND, 93, 5, 170, 1, 355, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 346 */ 5, CNA_BEHAVIOR_SEND, 90, 5, 171, 1, 356, 1}, /* AMP_GetSWInfoReq */
    {/* Index 347 */ 5, CNA_BEHAVIOR_SEND, 92, 5, 172, 1, 357, 1}, /* AMP_GetTempInfoReq */
    {/* Index 348 */ 5, CNA_BEHAVIOR_NONE, 86, 5, 173, 0, 358, 1}, /* AMP_HFMVolSet */
    {/* Index 349 */ 5, CNA_BEHAVIOR_NONE, 89, 5, 173, 0, 359, 1}, /* AMP_MainVolSet */
    {/* Index 350 */ 5, CNA_BEHAVIOR_NONE, 88, 5, 173, 0, 360, 1}, /* AMP_NaviVolSet */
    {/* Index 351 */ 5, CNA_BEHAVIOR_NONE, 87, 5, 173, 0, 361, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 352 */ 5, CNA_BEHAVIOR_NONE, 97, 5, 173, 0, 362, 1}, /* IESS_MdlInfoReq */
    {/* Index 353 */ 5, CNA_BEHAVIOR_NONE, 98, 5, 173, 0, 363, 1}, /* IESS_MdlSwtReq */
    {/* Index 354 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 173, 1, 364, 1}, /* ACAirInletReq_VR */
    {/* Index 355 */ 5, CNA_BEHAVIOR_SEND, 104, 6, 174, 1, 365, 1}, /* ACAutoModReq_VR */
    {/* Index 356 */ 5, CNA_BEHAVIOR_SEND, 107, 6, 175, 1, 366, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 357 */ 5, CNA_BEHAVIOR_SEND, 105, 6, 176, 1, 367, 1}, /* ACCmprReq_VR */
    {/* Index 358 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 177, 1, 368, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 359 */ 5, CNA_BEHAVIOR_SEND, 108, 6, 178, 1, 369, 1}, /* ACDrvTempReq_VR */
    {/* Index 360 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 179, 1, 370, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 361 */ 5, CNA_BEHAVIOR_NONE, 112, 6, 180, 0, 371, 1}, /* ACModReq_HUT */
    {/* Index 362 */ 5, CNA_BEHAVIOR_SEND, 106, 6, 180, 1, 372, 1}, /* ACPowerReq_VR */
    {/* Index 363 */ 5, CNA_BEHAVIOR_NONE, 100, 6, 181, 0, 373, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 364 */ 5, CNA_BEHAVIOR_NONE, 102, 6, 181, 0, 374, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 365 */ 5, CNA_BEHAVIOR_NONE, 101, 6, 181, 0, 375, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 366 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 181, 0, 376, 1}, /* PassSeatVentnLvlSet */
    {/* Index 367 */ 5, CNA_BEHAVIOR_NONE, 113, 6, 181, 0, 377, 1}, /* RLSeatHeatgLvlSet */
    {/* Index 368 */ 5, CNA_BEHAVIOR_NONE, 114, 6, 181, 0, 378, 1}, /* RRSeatHeatgLvlSet */
    {/* Index 369 */ 5, CNA_BEHAVIOR_SEND, 115, 6, 181, 1, 379, 1}, /* RemUpgrdSts */
    {/* Index 370 */ 5, CNA_BEHAVIOR_CYCLE, 495, 39, 182, 1, 380, 1}, /* RearFogLmpSwtSts_HUT */
    {/* Index 371 */ 5, CNA_BEHAVIOR_CYCLE, 359, 27, 183, 1, 381, 1}, /* ContnPrkgReq */
    {/* Index 372 */ 5, CNA_BEHAVIOR_CYCLE, 357, 27, 184, 1, 382, 1}, /* PrkgCtrlModReq */
    {/* Index 373 */ 5, CNA_BEHAVIOR_CYCLE, 568, 44, 185, 1, 383, 1}, /* ChairMemPosnSet */
    {/* Index 374 */ 5, CNA_BEHAVIOR_CYCLE, 621, 44, 186, 1, 384, 1}, /* EPSSteerModSwtReq */
    {/* Index 375 */ 5, CNA_BEHAVIOR_CYCLE, 182, 11, 187, 1, 385, 1}, /* HUT_AVHSwitchSts */
    {/* Index 376 */ 5, CNA_BEHAVIOR_CYCLE, 181, 11, 188, 1, 386, 1}, /* HUT_EPB_SwtPosn */
    {/* Index 377 */ 5, CNA_BEHAVIOR_CYCLE, 183, 11, 189, 1, 387, 1}, /* HUT_HDCSwitchCtrl */
    {/* Index 378 */ 5, CNA_BEHAVIOR_CYCLE, 180, 11, 190, 1, 388, 1}, /* HUT_VehSpdLimAdj */
    {/* Index 379 */ 5, CNA_BEHAVIOR_CYCLE, 178, 11, 191, 1, 389, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[380] = {0u};
static const uint8 cna_noActionBuffer[192] =
{
    2u,
    0u,
    0u,
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
    61u,
    61u,
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
    0u,
    3u,
    0u,
    0u,
    0u,
    255u,
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
    379,
    65535,
    378,
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

static uint8 cna_currentBuffer[390] = {0};

const CNA_ConfigType cna_config =
{
    380u,
    cna_signalConfigs,
    cna_signalDatas,
    192u,
    cna_noActionBuffer,
    390u,
    cna_currentBuffer,
    742u,
    CNA_IdTable
};


