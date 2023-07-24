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
#ifndef SWC_IPC_CAN_MATRIX_D03H
    #include "SWC_IPC_CANMatrix_D03.h"
    #if (0x2dabc729 != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
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
static const CNA_SignalConfigType cna_signalConfigs[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 153, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 154, 8, 0, 0, 1, 1}, /* ALCMClrSet_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_NONE, 155, 8, 0, 0, 2, 1}, /* ALCMDynModSet_OLE */
    {/* Index 3 */ 5, CNA_BEHAVIOR_NONE, 156, 8, 0, 0, 3, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 4 */ 5, CNA_BEHAVIOR_NONE, 157, 8, 0, 0, 4, 1}, /* ALCMRhmSwt_OLE */
    {/* Index 5 */ 5, CNA_BEHAVIOR_NONE, 158, 8, 0, 0, 5, 1}, /* ALCMStatSwt_OLE */
    {/* Index 6 */ 5, CNA_BEHAVIOR_NONE, 161, 8, 0, 0, 6, 1}, /* ChairMemPosnEna_Pass */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 163, 8, 0, 1, 7, 1}, /* ChairMemPosnSetSwt_Pass */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 159, 8, 1, 1, 8, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 9 */ 5, CNA_BEHAVIOR_SEND, 160, 8, 2, 1, 9, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 10 */ 5, CNA_BEHAVIOR_UNSEND, 162, 8, 3, 1, 10, 1}, /* OTA_UpgrdModReq */
    {/* Index 11 */ 5, CNA_BEHAVIOR_NONE, 164, 8, 4, 0, 11, 1}, /* SmtCsaSwt */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 136, 7, 4, 1, 12, 1}, /* AUTODefrost_TC */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 137, 7, 5, 1, 13, 1}, /* AUTODefrost_VR */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 135, 7, 6, 1, 14, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 138, 7, 7, 1, 15, 1}, /* AutoViewChgCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 139, 7, 8, 1, 16, 1}, /* CarMdlDispCmd */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 140, 7, 9, 1, 17, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 141, 7, 10, 1, 18, 1}, /* FPAS_AutoModSwt */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 142, 7, 11, 1, 19, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 143, 7, 12, 1, 20, 1}, /* LaneCalActvtCmd */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 145, 7, 13, 1, 21, 1}, /* MEBSwtSet */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 146, 7, 14, 1, 22, 1}, /* MODChgReq */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 144, 7, 15, 1, 23, 1}, /* MdlColrChgCmd */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 147, 7, 16, 1, 24, 1}, /* Radar_DispCmd */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 148, 7, 17, 1, 25, 1}, /* Sgl_View_Sel */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 149, 7, 18, 1, 26, 1}, /* SwToFieldCalRstCmd */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 150, 7, 19, 1, 27, 1}, /* View_SoftswitchCmd */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 151, 7, 20, 1, 28, 1}, /* WshSoftSwt */
    {/* Index 29 */ 5, CNA_BEHAVIOR_NONE, 531, 42, 21, 0, 29, 4}, /* AntiDisIdnResp */
    {/* Index 30 */ 5, CNA_BEHAVIOR_SEND, 719, 48, 21, 1, 33, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 31 */ 5, CNA_BEHAVIOR_UNSEND, 720, 48, 22, 1, 34, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 32 */ 5, CNA_BEHAVIOR_NONE, 732, 48, 23, 0, 35, 1}, /* HUT_HAVP_LearningTypeSele */
    {/* Index 33 */ 5, CNA_BEHAVIOR_NONE, 731, 48, 23, 0, 36, 1}, /* HUT_HAVP_Learning_Set_ParkLot */
    {/* Index 34 */ 5, CNA_BEHAVIOR_NONE, 721, 48, 23, 0, 37, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 35 */ 5, CNA_BEHAVIOR_NONE, 722, 48, 23, 0, 38, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 36 */ 5, CNA_BEHAVIOR_NONE, 723, 48, 23, 0, 39, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 37 */ 5, CNA_BEHAVIOR_SEND, 724, 48, 23, 1, 40, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 38 */ 5, CNA_BEHAVIOR_SEND, 725, 48, 24, 1, 41, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 39 */ 5, CNA_BEHAVIOR_SEND, 726, 48, 25, 1, 42, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 40 */ 5, CNA_BEHAVIOR_SEND, 727, 48, 26, 1, 43, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 41 */ 5, CNA_BEHAVIOR_NONE, 738, 48, 27, 0, 44, 1}, /* LR_ProfLong_CtrlPoint */
    {/* Index 42 */ 5, CNA_BEHAVIOR_NONE, 736, 48, 27, 0, 45, 1}, /* LR_ProfLong_CycCnt */
    {/* Index 43 */ 5, CNA_BEHAVIOR_NONE, 734, 48, 27, 0, 46, 1}, /* LR_ProfLong_MsgTyp */
    {/* Index 44 */ 5, CNA_BEHAVIOR_NONE, 733, 48, 27, 0, 47, 2}, /* LR_ProfLong_Offset */
    {/* Index 45 */ 5, CNA_BEHAVIOR_NONE, 735, 48, 27, 0, 49, 1}, /* LR_ProfLong_PathIdx */
    {/* Index 46 */ 5, CNA_BEHAVIOR_NONE, 739, 48, 27, 0, 50, 1}, /* LR_ProfLong_ProfTyp */
    {/* Index 47 */ 5, CNA_BEHAVIOR_NONE, 741, 48, 27, 0, 51, 1}, /* LR_ProfLong_Retr */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 737, 48, 27, 0, 52, 1}, /* LR_ProfLong_Update */
    {/* Index 49 */ 5, CNA_BEHAVIOR_NONE, 740, 48, 27, 0, 53, 4}, /* LR_ProfLong_Value */
    {/* Index 50 */ 5, CNA_BEHAVIOR_SEND, 728, 48, 27, 1, 57, 1}, /* SlotNum_VR */
    {/* Index 51 */ 5, CNA_BEHAVIOR_SEND, 730, 48, 28, 1, 58, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 52 */ 5, CNA_BEHAVIOR_SEND, 729, 48, 29, 1, 59, 1}, /* UserDefinedParkCmd */
    {/* Index 53 */ 5, CNA_BEHAVIOR_SEND, 514, 39, 30, 1, 60, 1}, /* DrvSeatMassgModSet */
    {/* Index 54 */ 5, CNA_BEHAVIOR_UNSEND, 518, 39, 31, 1, 61, 1}, /* InCarTempMaxSet */
    {/* Index 55 */ 5, CNA_BEHAVIOR_UNSEND, 517, 39, 32, 1, 62, 1}, /* InCarTempMinSet */
    {/* Index 56 */ 5, CNA_BEHAVIOR_SEND, 515, 39, 33, 1, 63, 1}, /* PassSeatMassgModSet */
    {/* Index 57 */ 5, CNA_BEHAVIOR_UNSEND, 516, 39, 34, 1, 64, 1}, /* RWPC_SwtReq */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 519, 39, 35, 1, 65, 1}, /* SmtACSwt */
    {/* Index 59 */ 5, CNA_BEHAVIOR_UNSEND, 523, 40, 36, 1, 66, 1}, /* AGSSwtReq */
    {/* Index 60 */ 5, CNA_BEHAVIOR_UNSEND, 521, 40, 37, 1, 67, 1}, /* ARFSwtReq */
    {/* Index 61 */ 5, CNA_BEHAVIOR_UNSEND, 522, 40, 38, 1, 68, 1}, /* ASFCSwtReq */
    {/* Index 62 */ 5, CNA_BEHAVIOR_UNSEND, 524, 40, 39, 1, 69, 1}, /* SOCMngmntSwtReq */
    {/* Index 63 */ 5, CNA_BEHAVIOR_SEND, 413, 30, 40, 1, 70, 1}, /* ACMaxReq_TC */
    {/* Index 64 */ 5, CNA_BEHAVIOR_SEND, 414, 30, 41, 1, 71, 1}, /* ACMaxReq_VR */
    {/* Index 65 */ 5, CNA_BEHAVIOR_SEND, 415, 30, 42, 1, 72, 1}, /* ACRearAutoModReq_VR */
    {/* Index 66 */ 5, CNA_BEHAVIOR_SEND, 416, 30, 43, 1, 73, 1}, /* ACRearLockReq_TC */
    {/* Index 67 */ 5, CNA_BEHAVIOR_SEND, 417, 30, 44, 1, 74, 1}, /* ACRearPowerReq_VR */
    {/* Index 68 */ 5, CNA_BEHAVIOR_NONE, 418, 30, 45, 0, 75, 1}, /* LockWinSet */
    {/* Index 69 */ 5, CNA_BEHAVIOR_NONE, 420, 31, 45, 0, 76, 1}, /* MultiColorNr1 */
    {/* Index 70 */ 5, CNA_BEHAVIOR_NONE, 421, 31, 45, 0, 77, 1}, /* MultiColorNr2 */
    {/* Index 71 */ 5, CNA_BEHAVIOR_NONE, 422, 31, 45, 0, 78, 1}, /* MultiColorNr3 */
    {/* Index 72 */ 5, CNA_BEHAVIOR_NONE, 423, 31, 45, 0, 79, 1}, /* MultiColorNr4 */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 424, 31, 45, 0, 80, 1}, /* MultiColorNr5 */
    {/* Index 74 */ 5, CNA_BEHAVIOR_NONE, 425, 31, 45, 0, 81, 1}, /* MultiColorNr6 */
    {/* Index 75 */ 5, CNA_BEHAVIOR_NONE, 426, 31, 45, 0, 82, 1}, /* MultiColorNr7 */
    {/* Index 76 */ 5, CNA_BEHAVIOR_NONE, 427, 31, 45, 0, 83, 1}, /* MultiColorNr8 */
    {/* Index 77 */ 5, CNA_BEHAVIOR_SEND, 438, 33, 45, 1, 84, 1}, /* ACRLTempDecReq_TC */
    {/* Index 78 */ 5, CNA_BEHAVIOR_SEND, 439, 33, 46, 1, 85, 1}, /* ACRLTempIncReq_TC */
    {/* Index 79 */ 5, CNA_BEHAVIOR_SEND, 440, 33, 47, 1, 86, 1}, /* ACRLTempReq_VR */
    {/* Index 80 */ 5, CNA_BEHAVIOR_SEND, 441, 33, 48, 1, 87, 1}, /* ACRRTempDecReq_TC */
    {/* Index 81 */ 5, CNA_BEHAVIOR_SEND, 442, 33, 49, 1, 88, 1}, /* ACRRTempIncReq_TC */
    {/* Index 82 */ 5, CNA_BEHAVIOR_SEND, 443, 33, 50, 1, 89, 1}, /* ACRRTempReq_VR */
    {/* Index 83 */ 5, CNA_BEHAVIOR_SEND, 444, 33, 51, 1, 90, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 84 */ 5, CNA_BEHAVIOR_SEND, 445, 33, 52, 1, 91, 1}, /* FootALCMFlashFreq */
    {/* Index 85 */ 5, CNA_BEHAVIOR_SEND, 447, 33, 53, 1, 92, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 86 */ 5, CNA_BEHAVIOR_SEND, 446, 33, 54, 1, 93, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 448, 33, 55, 1, 94, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 450, 33, 56, 1, 95, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 89 */ 5, CNA_BEHAVIOR_SEND, 449, 33, 57, 1, 96, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 351, 26, 58, 1, 97, 1}, /* BackReq_AVM */
    {/* Index 91 */ 5, CNA_BEHAVIOR_SEND, 352, 26, 59, 1, 98, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 353, 26, 60, 1, 99, 1}, /* HUD_HeightLvlSwt */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 354, 26, 61, 1, 100, 1}, /* HUD_SwtReq */
    {/* Index 94 */ 5, CNA_BEHAVIOR_UNSEND, 355, 26, 62, 1, 101, 1}, /* PPMIBSRSwtSet */
    {/* Index 95 */ 5, CNA_BEHAVIOR_UNSEND, 356, 26, 63, 1, 102, 1}, /* PPMIHWSwtSet */
    {/* Index 96 */ 5, CNA_BEHAVIOR_NONE, 452, 34, 64, 0, 103, 1}, /* ActvEntryLockSet */
    {/* Index 97 */ 5, CNA_BEHAVIOR_NONE, 453, 34, 64, 0, 104, 1}, /* ActvEntryUnlockSet */
    {/* Index 98 */ 5, CNA_BEHAVIOR_NONE, 454, 34, 64, 0, 105, 1}, /* BTAPAEntryLockSet */
    {/* Index 99 */ 5, CNA_BEHAVIOR_NONE, 455, 34, 64, 0, 106, 1}, /* BTAPALvngUnlockSet */
    {/* Index 100 */ 5, CNA_BEHAVIOR_NONE, 456, 34, 64, 0, 107, 1}, /* ClsWinSpdSet */
    {/* Index 101 */ 5, CNA_BEHAVIOR_SEND, 457, 34, 64, 1, 108, 1}, /* DrvDoorALCMClrSet */
    {/* Index 102 */ 5, CNA_BEHAVIOR_NONE, 458, 34, 65, 0, 109, 1}, /* DrvDoorALCMSwt */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 459, 34, 65, 1, 110, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 460, 34, 66, 1, 111, 1}, /* LRDoorALCMClrSet */
    {/* Index 105 */ 5, CNA_BEHAVIOR_NONE, 471, 34, 67, 0, 112, 1}, /* LockPromptFunSet */
    {/* Index 106 */ 5, CNA_BEHAVIOR_SEND, 461, 34, 67, 1, 113, 1}, /* PassDoorALCMClrSet */
    {/* Index 107 */ 5, CNA_BEHAVIOR_NONE, 462, 34, 68, 0, 114, 1}, /* PassDoorALCMSwt */
    {/* Index 108 */ 5, CNA_BEHAVIOR_SEND, 463, 34, 68, 1, 115, 1}, /* PassSeatMassgLvlSet */
    {/* Index 109 */ 5, CNA_BEHAVIOR_SEND, 464, 34, 69, 1, 116, 1}, /* RLSeatMassgLvlSet */
    {/* Index 110 */ 5, CNA_BEHAVIOR_UNSEND, 465, 34, 70, 1, 117, 1}, /* RLSeatMemPosnSwt */
    {/* Index 111 */ 5, CNA_BEHAVIOR_NONE, 466, 34, 71, 0, 118, 1}, /* RLSeatSupportLvlSet */
    {/* Index 112 */ 5, CNA_BEHAVIOR_SEND, 467, 34, 71, 1, 119, 1}, /* RRSeatMassgLvlSet */
    {/* Index 113 */ 5, CNA_BEHAVIOR_UNSEND, 468, 34, 72, 1, 120, 1}, /* RRSeatMemPosnSwt */
    {/* Index 114 */ 5, CNA_BEHAVIOR_NONE, 469, 34, 73, 0, 121, 1}, /* RRSeatSupportLvlSet */
    {/* Index 115 */ 5, CNA_BEHAVIOR_NONE, 470, 34, 73, 0, 122, 1}, /* SeatKeyMemEna */
    {/* Index 116 */ 5, CNA_BEHAVIOR_NONE, 429, 32, 73, 0, 123, 1}, /* MultiColorNr10 */
    {/* Index 117 */ 5, CNA_BEHAVIOR_NONE, 430, 32, 73, 0, 124, 1}, /* MultiColorNr11 */
    {/* Index 118 */ 5, CNA_BEHAVIOR_NONE, 431, 32, 73, 0, 125, 1}, /* MultiColorNr12 */
    {/* Index 119 */ 5, CNA_BEHAVIOR_NONE, 432, 32, 73, 0, 126, 1}, /* MultiColorNr13 */
    {/* Index 120 */ 5, CNA_BEHAVIOR_NONE, 433, 32, 73, 0, 127, 1}, /* MultiColorNr14 */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 434, 32, 73, 0, 128, 1}, /* MultiColorNr15 */
    {/* Index 122 */ 5, CNA_BEHAVIOR_NONE, 435, 32, 73, 0, 129, 1}, /* MultiColorNr16 */
    {/* Index 123 */ 5, CNA_BEHAVIOR_NONE, 436, 32, 73, 0, 130, 1}, /* MultiColorNr9 */
    {/* Index 124 */ 5, CNA_BEHAVIOR_SEND, 377, 28, 73, 1, 131, 1}, /* ACFGAChanTyp_TC */
    {/* Index 125 */ 5, CNA_BEHAVIOR_SEND, 378, 28, 74, 1, 132, 1}, /* ACFGAEnaReq_TC */
    {/* Index 126 */ 5, CNA_BEHAVIOR_SEND, 379, 28, 75, 1, 133, 1}, /* ACFGALvlReq_TC */
    {/* Index 127 */ 6, CNA_BEHAVIOR_NONE, 393, 28, 76, 0, 134, 1}, /* ALCMDynModSet */
    {/* Index 128 */ 6, CNA_BEHAVIOR_UNSEND, 395, 28, 76, 1, 135, 1}, /* ApproachLampSet */
    {/* Index 129 */ 6, CNA_BEHAVIOR_NONE, 398, 28, 77, 0, 136, 1}, /* ApproachLampSet0 */
    {/* Index 130 */ 6, CNA_BEHAVIOR_NONE, 399, 28, 77, 0, 137, 1}, /* ApproachLampSet1 */
    {/* Index 131 */ 5, CNA_BEHAVIOR_SEND, 380, 28, 77, 1, 138, 1}, /* BackReq_APS */
    {/* Index 132 */ 6, CNA_BEHAVIOR_SEND, 394, 28, 78, 1, 139, 1}, /* ChairMemPosnSetSwt */
    {/* Index 133 */ 6, CNA_BEHAVIOR_NONE, 396, 28, 79, 0, 140, 1}, /* ChairMemPosnSetSwt0 */
    {/* Index 134 */ 6, CNA_BEHAVIOR_NONE, 397, 28, 79, 0, 141, 1}, /* ChairMemPosnSetSwt1 */
    {/* Index 135 */ 5, CNA_BEHAVIOR_SEND, 381, 28, 79, 1, 142, 1}, /* DeletePath1Cmd */
    {/* Index 136 */ 5, CNA_BEHAVIOR_SEND, 382, 28, 80, 1, 143, 1}, /* DeletePath2Cmd */
    {/* Index 137 */ 6, CNA_BEHAVIOR_UNSEND, 383, 28, 81, 1, 144, 1}, /* FlaoutUnlockSet */
    {/* Index 138 */ 5, CNA_BEHAVIOR_SEND, 384, 28, 82, 1, 145, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 139 */ 5, CNA_BEHAVIOR_SEND, 385, 28, 83, 1, 146, 1}, /* ParkMdlCmd */
    {/* Index 140 */ 5, CNA_BEHAVIOR_SEND, 386, 28, 84, 1, 147, 1}, /* PathLrngFinshCmd */
    {/* Index 141 */ 5, CNA_BEHAVIOR_SEND, 387, 28, 85, 1, 148, 1}, /* PathLrngStartCmd */
    {/* Index 142 */ 6, CNA_BEHAVIOR_NONE, 388, 28, 86, 0, 149, 1}, /* PrkInDirChoice */
    {/* Index 143 */ 5, CNA_BEHAVIOR_SEND, 390, 28, 86, 1, 150, 1}, /* SelPrkOutDirReq */
    {/* Index 144 */ 5, CNA_BEHAVIOR_SEND, 389, 28, 87, 1, 151, 1}, /* SelPrkgFctnCmd */
    {/* Index 145 */ 5, CNA_BEHAVIOR_SEND, 391, 28, 88, 1, 152, 1}, /* StartPrkgPath1Cmd */
    {/* Index 146 */ 5, CNA_BEHAVIOR_SEND, 392, 28, 89, 1, 153, 1}, /* StartPrkgPath2Cmd */
    {/* Index 147 */ 5, CNA_BEHAVIOR_NONE, 201, 13, 90, 0, 154, 1}, /* ABSLmpSet */
    {/* Index 148 */ 5, CNA_BEHAVIOR_SEND, 202, 13, 90, 1, 155, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 149 */ 5, CNA_BEHAVIOR_SEND, 203, 13, 91, 1, 156, 1}, /* ACOperMod_TC */
    {/* Index 150 */ 5, CNA_BEHAVIOR_SEND, 204, 13, 92, 1, 157, 1}, /* ACOperMod_VR */
    {/* Index 151 */ 5, CNA_BEHAVIOR_SEND, 205, 13, 93, 1, 158, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 152 */ 5, CNA_BEHAVIOR_SEND, 206, 13, 94, 1, 159, 1}, /* APSPrkgTypSeln */
    {/* Index 153 */ 5, CNA_BEHAVIOR_SEND, 207, 13, 95, 1, 160, 1}, /* APSSwtReq_VR */
    {/* Index 154 */ 5, CNA_BEHAVIOR_NONE, 208, 13, 96, 0, 161, 1}, /* AutoWshWipSet */
    {/* Index 155 */ 5, CNA_BEHAVIOR_NONE, 209, 13, 96, 0, 162, 1}, /* DoorUnlockModSet */
    {/* Index 156 */ 5, CNA_BEHAVIOR_NONE, 210, 13, 96, 0, 163, 1}, /* FrntRearACDispSts */
    {/* Index 157 */ 5, CNA_BEHAVIOR_SEND, 212, 13, 96, 1, 164, 1}, /* PASExitSpdSwt */
    {/* Index 158 */ 5, CNA_BEHAVIOR_NONE, 211, 13, 97, 0, 165, 1}, /* ParkLmpSet */
    {/* Index 159 */ 5, CNA_BEHAVIOR_SEND, 213, 13, 97, 1, 166, 1}, /* SDWSwtSet */
    {/* Index 160 */ 5, CNA_BEHAVIOR_NONE, 214, 13, 98, 0, 167, 1}, /* SeekVehSet */
    {/* Index 161 */ 5, CNA_BEHAVIOR_NONE, 215, 13, 98, 0, 168, 1}, /* SpdAutoLockModSet */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 216, 13, 98, 0, 169, 1}, /* SportModLightSet */
    {/* Index 163 */ 5, CNA_BEHAVIOR_SEND, 217, 13, 98, 1, 170, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 164 */ 5, CNA_BEHAVIOR_SEND, 218, 13, 99, 1, 171, 1}, /* SunRoofSwtReq_VR */
    {/* Index 165 */ 5, CNA_BEHAVIOR_SEND, 219, 13, 100, 1, 172, 1}, /* SunShadeSwtReq_VR */
    {/* Index 166 */ 5, CNA_BEHAVIOR_NONE, 526, 41, 101, 0, 173, 1}, /* LRearVisCurtCtrlCmd */
    {/* Index 167 */ 5, CNA_BEHAVIOR_SEND, 529, 41, 101, 1, 174, 1}, /* NaturalWindReq */
    {/* Index 168 */ 5, CNA_BEHAVIOR_NONE, 527, 41, 102, 0, 175, 1}, /* RRearVisCurtCtrlCmd */
    {/* Index 169 */ 5, CNA_BEHAVIOR_NONE, 528, 41, 102, 0, 176, 1}, /* RearVisCurtLockSwt */
    {/* Index 170 */ 5, CNA_BEHAVIOR_SEND, 503, 37, 102, 1, 177, 1}, /* ACRLTempSteplsReq_TC */
    {/* Index 171 */ 5, CNA_BEHAVIOR_SEND, 504, 37, 103, 1, 178, 1}, /* ACRRTempSteplsReq_TC */
    {/* Index 172 */ 5, CNA_BEHAVIOR_NONE, 483, 36, 104, 0, 179, 1}, /* ALCMBreSwt */
    {/* Index 173 */ 5, CNA_BEHAVIOR_NONE, 484, 36, 104, 0, 180, 1}, /* ALCMFloSwt */
    {/* Index 174 */ 5, CNA_BEHAVIOR_SEND, 485, 36, 104, 1, 181, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 175 */ 5, CNA_BEHAVIOR_SEND, 486, 36, 105, 1, 182, 1}, /* FootALCMClrSet */
    {/* Index 176 */ 5, CNA_BEHAVIOR_SEND, 487, 36, 106, 1, 183, 1}, /* FootALCMLightLvlSet */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 488, 36, 107, 0, 184, 1}, /* FootALCMSwt */
    {/* Index 178 */ 5, CNA_BEHAVIOR_SEND, 492, 36, 107, 1, 185, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 179 */ 5, CNA_BEHAVIOR_NONE, 493, 36, 108, 0, 186, 1}, /* LRDoorALCMSwt */
    {/* Index 180 */ 5, CNA_BEHAVIOR_SEND, 489, 36, 108, 1, 187, 1}, /* LeftPanelALCMClrSet */
    {/* Index 181 */ 5, CNA_BEHAVIOR_SEND, 490, 36, 109, 1, 188, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 182 */ 5, CNA_BEHAVIOR_NONE, 491, 36, 110, 0, 189, 1}, /* LeftPanelALCMSwt */
    {/* Index 183 */ 5, CNA_BEHAVIOR_SEND, 494, 36, 110, 1, 190, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 184 */ 5, CNA_BEHAVIOR_SEND, 499, 36, 111, 1, 191, 1}, /* RRDoorALCMClrSet */
    {/* Index 185 */ 5, CNA_BEHAVIOR_SEND, 500, 36, 112, 1, 192, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 186 */ 5, CNA_BEHAVIOR_NONE, 501, 36, 113, 0, 193, 1}, /* RRDoorALCMSwt */
    {/* Index 187 */ 5, CNA_BEHAVIOR_SEND, 495, 36, 113, 1, 194, 1}, /* RightPanelALCMClrSet */
    {/* Index 188 */ 5, CNA_BEHAVIOR_SEND, 496, 36, 114, 1, 195, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 497, 36, 115, 0, 196, 1}, /* RightPanelALCMSwt */
    {/* Index 190 */ 5, CNA_BEHAVIOR_NONE, 498, 36, 115, 0, 197, 1}, /* RoofALCMSwt */
    {/* Index 191 */ 5, CNA_BEHAVIOR_SEND, 506, 38, 115, 1, 198, 1}, /* DrvSeatHeatgLvlSet_Nine */
    {/* Index 192 */ 5, CNA_BEHAVIOR_SEND, 507, 38, 116, 1, 199, 1}, /* PassSeatHeatgLvlSet_Nine */
    {/* Index 193 */ 5, CNA_BEHAVIOR_SEND, 508, 38, 117, 1, 200, 1}, /* RLSeatHeatgLvlSet_Nine */
    {/* Index 194 */ 5, CNA_BEHAVIOR_SEND, 509, 38, 118, 1, 201, 1}, /* RLSeatMassgModSet */
    {/* Index 195 */ 5, CNA_BEHAVIOR_SEND, 510, 38, 119, 1, 202, 1}, /* RRSeatHeatgLvlSet_Nine */
    {/* Index 196 */ 5, CNA_BEHAVIOR_SEND, 511, 38, 120, 1, 203, 1}, /* RRSeatMassgModSet */
    {/* Index 197 */ 5, CNA_BEHAVIOR_SEND, 512, 38, 121, 1, 204, 1}, /* SmtSeatSwt */
    {/* Index 198 */ 5, CNA_BEHAVIOR_NONE, 295, 20, 122, 0, 205, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 296, 20, 122, 0, 206, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 297, 20, 122, 0, 207, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 201 */ 5, CNA_BEHAVIOR_NONE, 298, 20, 122, 0, 208, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 299, 20, 122, 0, 209, 1}, /* ADAS_Stub_LastStub */
    {/* Index 203 */ 5, CNA_BEHAVIOR_NONE, 300, 20, 122, 0, 210, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 204 */ 5, CNA_BEHAVIOR_NONE, 301, 20, 122, 0, 211, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 205 */ 5, CNA_BEHAVIOR_NONE, 302, 20, 122, 0, 212, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 206 */ 5, CNA_BEHAVIOR_NONE, 303, 20, 122, 0, 213, 2}, /* ADAS_Stub_Offset */
    {/* Index 207 */ 5, CNA_BEHAVIOR_NONE, 304, 20, 122, 0, 215, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 305, 20, 122, 0, 216, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 306, 20, 122, 0, 217, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 307, 20, 122, 0, 218, 1}, /* ADAS_Stub_Retr */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 308, 20, 122, 0, 219, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 309, 20, 122, 0, 220, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 310, 20, 122, 0, 221, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 311, 20, 122, 0, 222, 1}, /* ADAS_Stub_Update */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 275, 19, 122, 0, 223, 1}, /* ADAS_Seg_Brdg */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 276, 19, 122, 0, 224, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 277, 19, 122, 0, 225, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 278, 19, 122, 0, 226, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 279, 19, 122, 0, 227, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 280, 19, 122, 0, 228, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 281, 19, 122, 0, 229, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 282, 19, 122, 0, 230, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 283, 19, 122, 0, 231, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 284, 19, 122, 0, 232, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 122, 0, 233, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 122, 0, 234, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 122, 0, 235, 2}, /* ADAS_Seg_Offset */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 122, 0, 237, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 122, 0, 238, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 122, 0, 239, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 122, 0, 240, 1}, /* ADAS_Seg_Retr */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 122, 0, 241, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 122, 0, 242, 1}, /* ADAS_Seg_Update */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 262, 18, 122, 0, 243, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 263, 18, 122, 0, 244, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 264, 18, 122, 0, 245, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 122, 0, 246, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 122, 0, 248, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 122, 0, 249, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 240 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 122, 0, 251, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 241 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 122, 0, 252, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 242 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 122, 0, 253, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 243 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 122, 0, 254, 1}, /* ADAS_ProfShort_Update */
    {/* Index 244 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 122, 0, 255, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 122, 0, 257, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 122, 0, 259, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 122, 0, 260, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 122, 0, 261, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 122, 0, 262, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 250 */ 5, CNA_BEHAVIOR_NONE, 256, 17, 122, 0, 264, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 257, 17, 122, 0, 265, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 258, 17, 122, 0, 266, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 253 */ 5, CNA_BEHAVIOR_NONE, 259, 17, 122, 0, 267, 1}, /* ADAS_ProfLong_Update */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 260, 17, 122, 0, 268, 4}, /* ADAS_ProfLong_Value */
    {/* Index 255 */ 5, CNA_BEHAVIOR_SEND, 168, 10, 122, 1, 272, 1}, /* ACAIUReq_VR */
    {/* Index 256 */ 5, CNA_BEHAVIOR_SEND, 169, 10, 123, 1, 273, 1}, /* ACAQSReq_VR */
    {/* Index 257 */ 5, CNA_BEHAVIOR_SEND, 170, 10, 124, 1, 274, 1}, /* ACDualReq_VR */
    {/* Index 258 */ 5, CNA_BEHAVIOR_SEND, 171, 10, 125, 1, 275, 1}, /* ACPassTempReq_VR */
    {/* Index 259 */ 5, CNA_BEHAVIOR_SEND, 172, 10, 126, 1, 276, 1}, /* ACRearDefrstReq_VR */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 176, 10, 127, 0, 277, 1}, /* ALCMClrSet */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 177, 10, 127, 0, 278, 1}, /* ALCMRhmSwt */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 178, 10, 127, 0, 279, 1}, /* ALCMStatSwt */
    {/* Index 263 */ 3, CNA_BEHAVIOR_SEND, 173, 10, 127, 1, 280, 1}, /* HUT_BeanIDReq */
    {/* Index 264 */ 5, CNA_BEHAVIOR_UNSEND, 179, 10, 128, 1, 281, 1}, /* HUT_EgyRecvrySet */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 174, 10, 129, 0, 282, 1}, /* IPVolSet */
    {/* Index 266 */ 5, CNA_BEHAVIOR_SEND, 175, 10, 129, 1, 283, 1}, /* PASSwtReq_VR */
    {/* Index 267 */ 5, CNA_BEHAVIOR_SEND, 313, 21, 130, 1, 284, 1}, /* ACDrvSetTempReq_ETC_VR */
    {/* Index 268 */ 5, CNA_BEHAVIOR_SEND, 314, 21, 131, 1, 285, 1}, /* ACDrvSetTempSteplsReq_ETC_TC */
    {/* Index 269 */ 5, CNA_BEHAVIOR_UNSEND, 319, 21, 132, 1, 286, 1}, /* HUT_BattKeepTemp */
    {/* Index 270 */ 5, CNA_BEHAVIOR_SEND, 318, 21, 133, 1, 287, 1}, /* HUT_BattSOCLim */
    {/* Index 271 */ 5, CNA_BEHAVIOR_UNSEND, 317, 21, 134, 1, 288, 1}, /* HUT_ChrgnMode */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 321, 21, 135, 0, 289, 1}, /* HUT_IntelBattTempMagSet */
    {/* Index 273 */ 5, CNA_BEHAVIOR_NONE, 320, 21, 135, 0, 290, 1}, /* HUT_IntelEngIdlChrgnSet */
    {/* Index 274 */ 5, CNA_BEHAVIOR_SEND, 315, 21, 135, 1, 291, 1}, /* HUT_RemtEngCtrl */
    {/* Index 275 */ 5, CNA_BEHAVIOR_NONE, 316, 21, 136, 0, 292, 1}, /* SuspLiftReq */
    {/* Index 276 */ 5, CNA_BEHAVIOR_SEND, 223, 15, 136, 1, 293, 1}, /* ACRearAirDistribModReq_VR */
    {/* Index 277 */ 5, CNA_BEHAVIOR_SEND, 224, 15, 137, 1, 294, 1}, /* ACRearBlwrSpdReq_VR */
    {/* Index 278 */ 5, CNA_BEHAVIOR_SEND, 225, 15, 138, 1, 295, 1}, /* ACRearBlwrsteplsSpdReq_TC */
    {/* Index 279 */ 5, CNA_BEHAVIOR_SEND, 226, 15, 139, 1, 296, 1}, /* ACZoneReq_VR */
    {/* Index 280 */ 5, CNA_BEHAVIOR_NONE, 227, 15, 140, 0, 297, 1}, /* AVMMediaVolLvlReq */
    {/* Index 281 */ 5, CNA_BEHAVIOR_NONE, 228, 15, 140, 0, 298, 1}, /* AVMSwtReq */
    {/* Index 282 */ 5, CNA_BEHAVIOR_SEND, 229, 15, 140, 1, 299, 1}, /* BackgroundLightLvlSet */
    {/* Index 283 */ 5, CNA_BEHAVIOR_UNSEND, 230, 15, 141, 1, 300, 1}, /* CSTSwt */
    {/* Index 284 */ 5, CNA_BEHAVIOR_NONE, 231, 15, 142, 0, 301, 1}, /* FPASChanSwtReq */
    {/* Index 285 */ 5, CNA_BEHAVIOR_NONE, 232, 15, 142, 0, 302, 1}, /* NaviMediaVolLvlReq */
    {/* Index 286 */ 5, CNA_BEHAVIOR_UNSEND, 236, 15, 142, 1, 303, 1}, /* OPDSwtSts */
    {/* Index 287 */ 5, CNA_BEHAVIOR_UNSEND, 233, 15, 143, 1, 304, 1}, /* PLGReq_VR */
    {/* Index 288 */ 5, CNA_BEHAVIOR_NONE, 234, 15, 144, 0, 305, 1}, /* RPASChanSwtReq */
    {/* Index 289 */ 5, CNA_BEHAVIOR_UNSEND, 235, 15, 144, 1, 306, 1}, /* WPC_SwtReq */
    {/* Index 290 */ 5, CNA_BEHAVIOR_SEND, 45, 3, 145, 1, 307, 1}, /* ACAIUReq_TC */
    {/* Index 291 */ 5, CNA_BEHAVIOR_SEND, 46, 3, 146, 1, 308, 1}, /* ACAQSReq_TC */
    {/* Index 292 */ 5, CNA_BEHAVIOR_SEND, 44, 3, 147, 1, 309, 1}, /* ACAirInletReq_TC */
    {/* Index 293 */ 5, CNA_BEHAVIOR_SEND, 47, 3, 148, 1, 310, 1}, /* ACAutoModReq_TC */
    {/* Index 294 */ 5, CNA_BEHAVIOR_SEND, 48, 3, 149, 1, 311, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 295 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 150, 1, 312, 1}, /* ACCmprReq_TC */
    {/* Index 296 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 151, 1, 313, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 297 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 152, 1, 314, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 298 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 153, 1, 315, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 299 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 154, 1, 316, 1}, /* ACDualReq_TC */
    {/* Index 300 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 155, 1, 317, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 301 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 156, 1, 318, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 302 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 157, 1, 319, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 303 */ 5, CNA_BEHAVIOR_SEND, 57, 3, 158, 1, 320, 1}, /* ACFrntHMIDis_TC */
    {/* Index 304 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 159, 1, 321, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 305 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 160, 1, 322, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 306 */ 5, CNA_BEHAVIOR_SEND, 60, 3, 161, 1, 323, 1}, /* ACOffReq_TC */
    {/* Index 307 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 162, 1, 324, 1}, /* ACRearBlwrSpdDecReq_TC */
    {/* Index 308 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 163, 1, 325, 1}, /* ACRearBlwrSpdIncReq_TC */
    {/* Index 309 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 164, 1, 326, 1}, /* ACRearHMIDis_TC */
    {/* Index 310 */ 5, CNA_BEHAVIOR_SEND, 64, 3, 165, 1, 327, 1}, /* ACZoneReq_TC */
    {/* Index 311 */ 5, CNA_BEHAVIOR_NONE, 65, 3, 166, 0, 328, 1}, /* BattSaveDelayTimeSet */
    {/* Index 312 */ 5, CNA_BEHAVIOR_NONE, 71, 3, 166, 0, 329, 1}, /* ChairMemPosnEna */
    {/* Index 313 */ 5, CNA_BEHAVIOR_NONE, 72, 3, 166, 0, 330, 1}, /* ChairMemPosnEna0 */
    {/* Index 314 */ 5, CNA_BEHAVIOR_NONE, 73, 3, 166, 0, 331, 1}, /* ChairMemPosnEna1 */
    {/* Index 315 */ 5, CNA_BEHAVIOR_NONE, 66, 3, 166, 0, 332, 1}, /* DomeLmpDlyTimSet */
    {/* Index 316 */ 5, CNA_BEHAVIOR_NONE, 67, 3, 166, 0, 333, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 317 */ 5, CNA_BEHAVIOR_NONE, 68, 3, 166, 0, 334, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 318 */ 5, CNA_BEHAVIOR_NONE, 69, 3, 166, 0, 335, 1}, /* RearviewFoldModSet */
    {/* Index 319 */ 5, CNA_BEHAVIOR_NONE, 70, 3, 166, 0, 336, 1}, /* TranPMode_Req */
    {/* Index 320 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 166, 0, 337, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 321 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 166, 0, 338, 1}, /* AMP_BeepSourceSet */
    {/* Index 322 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 166, 0, 339, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 323 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 166, 0, 340, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 324 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 166, 0, 341, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 325 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 166, 0, 342, 1}, /* AMP_LRDrvSideSet */
    {/* Index 326 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 166, 0, 343, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 327 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 166, 0, 344, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 328 */ 5, CNA_BEHAVIOR_NONE, 83, 4, 166, 0, 345, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 166, 0, 346, 1}, /* AMP_MuteSet */
    {/* Index 330 */ 5, CNA_BEHAVIOR_NONE, 85, 4, 166, 0, 347, 1}, /* AMP_NaviSourceSet */
    {/* Index 331 */ 5, CNA_BEHAVIOR_NONE, 86, 4, 166, 0, 348, 1}, /* ANCSwtSet */
    {/* Index 332 */ 5, CNA_BEHAVIOR_NONE, 90, 4, 166, 0, 349, 1}, /* EnhdSiriSet */
    {/* Index 333 */ 5, CNA_BEHAVIOR_SEND, 87, 4, 166, 1, 350, 1}, /* RearWinHeatCmd_TC */
    {/* Index 334 */ 5, CNA_BEHAVIOR_NONE, 88, 4, 167, 0, 351, 1}, /* T_BOX_ECallSet */
    {/* Index 335 */ 5, CNA_BEHAVIOR_NONE, 89, 4, 167, 0, 352, 1}, /* VRTTSSourceSet */
    {/* Index 336 */ 5, CNA_BEHAVIOR_NONE, 92, 5, 167, 0, 353, 1}, /* AMP_BestListegPosnReq */
    {/* Index 337 */ 5, CNA_BEHAVIOR_SEND, 93, 5, 167, 1, 354, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 338 */ 5, CNA_BEHAVIOR_SEND, 94, 5, 168, 1, 355, 1}, /* AMP_GetHWInfoReq */
    {/* Index 339 */ 5, CNA_BEHAVIOR_SEND, 95, 5, 169, 1, 356, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 340 */ 5, CNA_BEHAVIOR_SEND, 96, 5, 170, 1, 357, 1}, /* AMP_GetSWInfoReq */
    {/* Index 341 */ 5, CNA_BEHAVIOR_SEND, 97, 5, 171, 1, 358, 1}, /* AMP_GetTempInfoReq */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 98, 5, 172, 0, 359, 1}, /* AMP_HFMVolSet */
    {/* Index 343 */ 5, CNA_BEHAVIOR_NONE, 99, 5, 172, 0, 360, 1}, /* AMP_MainVolSet */
    {/* Index 344 */ 5, CNA_BEHAVIOR_NONE, 100, 5, 172, 0, 361, 1}, /* AMP_NaviVolSet */
    {/* Index 345 */ 5, CNA_BEHAVIOR_NONE, 101, 5, 172, 0, 362, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 346 */ 5, CNA_BEHAVIOR_NONE, 107, 5, 172, 0, 363, 1}, /* AudioChanModSet */
    {/* Index 347 */ 5, CNA_BEHAVIOR_NONE, 102, 5, 172, 0, 364, 1}, /* HdPrivacyModeSet */
    {/* Index 348 */ 5, CNA_BEHAVIOR_NONE, 106, 5, 172, 0, 365, 1}, /* ICCSwtReq */
    {/* Index 349 */ 5, CNA_BEHAVIOR_NONE, 103, 5, 172, 0, 366, 1}, /* IESS_MdlInfoReq */
    {/* Index 350 */ 5, CNA_BEHAVIOR_NONE, 104, 5, 172, 0, 367, 1}, /* IESS_MdlSwtReq */
    {/* Index 351 */ 5, CNA_BEHAVIOR_NONE, 105, 5, 172, 0, 368, 1}, /* QLIPlusSurroundSet */
    {/* Index 352 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 172, 1, 369, 1}, /* ACAirInletReq_VR */
    {/* Index 353 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 173, 1, 370, 1}, /* ACAutoModReq_VR */
    {/* Index 354 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 174, 1, 371, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 355 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 175, 1, 372, 1}, /* ACCmprReq_VR */
    {/* Index 356 */ 5, CNA_BEHAVIOR_SEND, 113, 6, 176, 1, 373, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 357 */ 5, CNA_BEHAVIOR_SEND, 114, 6, 177, 1, 374, 1}, /* ACDrvTempReq_VR */
    {/* Index 358 */ 5, CNA_BEHAVIOR_SEND, 115, 6, 178, 1, 375, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 359 */ 5, CNA_BEHAVIOR_SEND, 116, 6, 179, 1, 376, 1}, /* ACPowerReq_VR */
    {/* Index 360 */ 5, CNA_BEHAVIOR_SEND, 117, 6, 180, 1, 377, 1}, /* ACRearAirDistribModReq_TC */
    {/* Index 361 */ 5, CNA_BEHAVIOR_SEND, 118, 6, 181, 1, 378, 1}, /* ACRearAutoModReq_TC */
    {/* Index 362 */ 5, CNA_BEHAVIOR_SEND, 119, 6, 182, 1, 379, 1}, /* ACRearOffReq_TC */
    {/* Index 363 */ 5, CNA_BEHAVIOR_NONE, 120, 6, 183, 0, 380, 1}, /* AllTerrainDislSet */
    {/* Index 364 */ 5, CNA_BEHAVIOR_NONE, 121, 6, 183, 0, 381, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 365 */ 5, CNA_BEHAVIOR_NONE, 122, 6, 183, 0, 382, 1}, /* DrvSeatSupportLvlSet */
    {/* Index 366 */ 5, CNA_BEHAVIOR_NONE, 123, 6, 183, 0, 383, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 367 */ 5, CNA_BEHAVIOR_NONE, 124, 6, 183, 0, 384, 1}, /* ElecSideSteppingSysSet */
    {/* Index 368 */ 5, CNA_BEHAVIOR_NONE, 125, 6, 183, 0, 385, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 369 */ 5, CNA_BEHAVIOR_NONE, 126, 6, 183, 0, 386, 1}, /* PassSeatSupportLvlSet */
    {/* Index 370 */ 5, CNA_BEHAVIOR_NONE, 127, 6, 183, 0, 387, 1}, /* PassSeatVentnLvlSet */
    {/* Index 371 */ 5, CNA_BEHAVIOR_NONE, 129, 6, 183, 0, 388, 1}, /* RLSeatHeatgLvlSet */
    {/* Index 372 */ 5, CNA_BEHAVIOR_NONE, 130, 6, 183, 0, 389, 1}, /* RLSeatVentnLvlSet */
    {/* Index 373 */ 5, CNA_BEHAVIOR_NONE, 132, 6, 183, 0, 390, 1}, /* RRSeatHeatgLvlSet */
    {/* Index 374 */ 5, CNA_BEHAVIOR_NONE, 133, 6, 183, 0, 391, 1}, /* RRSeatVentnLvlSet */
    {/* Index 375 */ 5, CNA_BEHAVIOR_UNSEND, 128, 6, 183, 1, 392, 1}, /* RemUpgrdSts */
    {/* Index 376 */ 5, CNA_BEHAVIOR_NONE, 131, 6, 184, 0, 393, 1}, /* RoofModSet */
    {/* Index 377 */ 5, CNA_BEHAVIOR_CYCLE, 359, 27, 184, 1, 394, 1}, /* ContnPrkgReq */
    {/* Index 378 */ 5, CNA_BEHAVIOR_CYCLE, 362, 27, 185, 1, 395, 1}, /* PrkgCtrlModReq */
    {/* Index 379 */ 5, CNA_BEHAVIOR_CYCLE, 573, 45, 186, 1, 396, 1}, /* ChairMemPosnSet */
    {/* Index 380 */ 5, CNA_BEHAVIOR_CYCLE, 578, 45, 187, 1, 397, 1}, /* EPSSteerModSwtReq */
    {/* Index 381 */ 5, CNA_BEHAVIOR_CYCLE, 638, 45, 188, 1, 398, 1}, /* HUT_DrvModReq */
    {/* Index 382 */ 5, CNA_BEHAVIOR_CYCLE, 639, 45, 189, 1, 399, 1}, /* HUT_HybModReq */
    {/* Index 383 */ 5, CNA_BEHAVIOR_CYCLE, 618, 45, 190, 1, 400, 1}, /* OilLvlDispReq */
    {/* Index 384 */ 5, CNA_BEHAVIOR_CYCLE, 186, 12, 191, 1, 401, 1}, /* DampgDrvModeReq */
    {/* Index 385 */ 5, CNA_BEHAVIOR_CYCLE, 187, 12, 192, 1, 402, 1}, /* DrivingModReq_VR */
    {/* Index 386 */ 5, CNA_BEHAVIOR_CYCLE, 191, 12, 193, 1, 403, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = {0u};
static const uint8 cna_noActionBuffer[194] =
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
    61u,
    61u,
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
    64u,
    4u,
    64u,
    64u,
    4u,
    4u,
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
    3u,
    0u,
    0u,
    0u,
    0u,
    6u,
    3u,
    0u,
    0u,
    0u,
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
    3u,
    15u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[773] =
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
    292,
    290,
    291,
    293,
    294,
    295,
    296,
    297,
    298,
    299,
    300,
    301,
    302,
    303,
    304,
    305,
    306,
    307,
    308,
    309,
    310,
    311,
    315,
    316,
    317,
    318,
    319,
    312,
    313,
    314,
    65535,
    320,
    321,
    322,
    323,
    326,
    324,
    325,
    327,
    328,
    329,
    330,
    331,
    333,
    334,
    335,
    332,
    65535,
    336,
    337,
    338,
    339,
    340,
    341,
    342,
    343,
    344,
    345,
    347,
    349,
    350,
    351,
    348,
    346,
    65535,
    352,
    353,
    354,
    355,
    356,
    357,
    358,
    359,
    360,
    361,
    362,
    363,
    364,
    365,
    366,
    367,
    368,
    369,
    370,
    375,
    371,
    372,
    376,
    373,
    374,
    65535,
    14,
    12,
    13,
    15,
    16,
    17,
    18,
    19,
    20,
    23,
    21,
    22,
    24,
    25,
    26,
    27,
    28,
    65535,
    0,
    1,
    2,
    3,
    4,
    5,
    8,
    9,
    6,
    10,
    7,
    11,
    65535,
    65535,
    65535,
    255,
    256,
    257,
    258,
    259,
    263,
    265,
    266,
    260,
    261,
    262,
    264,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    384,
    385,
    65535,
    65535,
    65535,
    386,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    147,
    148,
    149,
    150,
    151,
    152,
    153,
    154,
    155,
    156,
    158,
    157,
    159,
    160,
    161,
    162,
    163,
    164,
    165,
    65535,
    65535,
    65535,
    276,
    277,
    278,
    279,
    280,
    281,
    282,
    283,
    284,
    285,
    287,
    288,
    289,
    286,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    246,
    247,
    248,
    249,
    250,
    251,
    252,
    253,
    254,
    65535,
    234,
    235,
    236,
    237,
    238,
    239,
    240,
    241,
    242,
    243,
    244,
    245,
    65535,
    215,
    216,
    217,
    218,
    219,
    220,
    221,
    222,
    223,
    224,
    225,
    226,
    227,
    228,
    229,
    230,
    231,
    232,
    233,
    65535,
    198,
    199,
    200,
    201,
    202,
    203,
    204,
    205,
    206,
    207,
    208,
    209,
    210,
    211,
    212,
    213,
    214,
    65535,
    267,
    268,
    274,
    275,
    271,
    270,
    269,
    273,
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    90,
    91,
    92,
    93,
    94,
    95,
    65535,
    65535,
    377,
    65535,
    65535,
    378,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    124,
    125,
    126,
    131,
    135,
    136,
    137,
    138,
    139,
    140,
    141,
    142,
    144,
    143,
    145,
    146,
    127,
    132,
    128,
    133,
    134,
    129,
    130,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    63,
    64,
    65,
    66,
    67,
    68,
    65535,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    65535,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
    123,
    65535,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    86,
    85,
    87,
    89,
    88,
    65535,
    96,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    105,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    172,
    173,
    174,
    175,
    176,
    177,
    180,
    181,
    182,
    178,
    179,
    183,
    187,
    188,
    189,
    190,
    184,
    185,
    186,
    65535,
    170,
    171,
    65535,
    191,
    192,
    193,
    194,
    195,
    196,
    197,
    65535,
    53,
    56,
    57,
    55,
    54,
    58,
    65535,
    60,
    61,
    59,
    62,
    65535,
    166,
    168,
    169,
    167,
    65535,
    29,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    379,
    65535,
    65535,
    65535,
    65535,
    380,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    383,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    381,
    382,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    30,
    31,
    34,
    35,
    36,
    37,
    38,
    39,
    40,
    50,
    52,
    51,
    33,
    32,
    44,
    43,
    45,
    42,
    48,
    41,
    46,
    49,
    47,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[404] = {0};

const CNA_ConfigType cna_config =
{
    SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER,
    cna_signalConfigs,
    cna_signalDatas,
    194u,
    cna_noActionBuffer,
    404u,
    cna_currentBuffer,
    773u,
    CNA_IdTable
};


