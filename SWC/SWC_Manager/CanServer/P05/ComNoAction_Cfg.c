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

#ifndef SWC_IPC_CAN_MATRIX_P05H
#include "SWC_IPC_CANMatrix_P05.h"
#if (0x57a6351f != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
     #error " Noaction version dismatch!!! "
#endif
#endif

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const CNA_SignalConfigType cna_signalConfigs[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 143, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 140, 8, 0, 0, 1, 1}, /* ALCMClrSet_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_NONE, 141, 8, 0, 0, 2, 1}, /* ALCMDynModSet_OLE */
    {/* Index 3 */ 5, CNA_BEHAVIOR_NONE, 142, 8, 0, 0, 3, 1}, /* ALCMLightLvlSet_OLE */
    {/* Index 4 */ 5, CNA_BEHAVIOR_NONE, 144, 8, 0, 0, 4, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 5 */ 5, CNA_BEHAVIOR_NONE, 145, 8, 0, 0, 5, 1}, /* ALCMRhmSwt_OLE */
    {/* Index 6 */ 5, CNA_BEHAVIOR_NONE, 139, 8, 0, 0, 6, 1}, /* ALCMStatSwt_OLE */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 147, 8, 0, 1, 7, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 146, 8, 1, 1, 8, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 9 */ 5, CNA_BEHAVIOR_SEND, 121, 7, 2, 1, 9, 1}, /* AUTODefrost_TC */
    {/* Index 10 */ 5, CNA_BEHAVIOR_SEND, 122, 7, 3, 1, 10, 1}, /* AUTODefrost_VR */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 4, 1, 11, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 5, 1, 12, 1}, /* AutoViewChgCmd */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 6, 1, 13, 1}, /* CarMdlDispCmd */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 7, 1, 14, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 8, 1, 15, 1}, /* FPAS_AutoModSwt */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 126, 7, 9, 1, 16, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 123, 7, 10, 1, 17, 1}, /* LaneCalActvtCmd */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 135, 7, 11, 1, 18, 1}, /* MEBSwtSet */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 124, 7, 12, 1, 19, 1}, /* MODChgReq */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 13, 1, 20, 1}, /* MdlColrChgCmd */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 125, 7, 14, 1, 21, 1}, /* Radar_DispCmd */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 127, 7, 15, 1, 22, 1}, /* Sgl_View_Sel */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 128, 7, 16, 1, 23, 1}, /* SwToFieldCalRstCmd */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 137, 7, 17, 1, 24, 1}, /* View_SoftswitchCmd */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 136, 7, 18, 1, 25, 1}, /* WshSoftSwt */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 654, 42, 19, 1, 26, 1}, /* SlotNum_VR */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 653, 42, 20, 1, 27, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 652, 42, 21, 1, 28, 1}, /* UserDefinedParkCmd */
    {/* Index 29 */ 5, CNA_BEHAVIOR_SEND, 484, 36, 22, 1, 29, 1}, /* DrvSeatMassgModSet */
    {/* Index 30 */ 5, CNA_BEHAVIOR_SEND, 483, 36, 23, 1, 30, 1}, /* PassSeatMassgModSet */
    {/* Index 31 */ 5, CNA_BEHAVIOR_UNSEND, 482, 36, 24, 1, 31, 1}, /* RWPC_SwtReq */
    {/* Index 32 */ 5, CNA_BEHAVIOR_UNSEND, 490, 37, 25, 1, 32, 1}, /* AGSSwtReq */
    {/* Index 33 */ 5, CNA_BEHAVIOR_UNSEND, 488, 37, 26, 1, 33, 1}, /* ARFSwtReq */
    {/* Index 34 */ 5, CNA_BEHAVIOR_UNSEND, 489, 37, 27, 1, 34, 1}, /* ASFCSwtReq */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 486, 37, 28, 1, 35, 1}, /* DrvSeatVentnLvlSet_Nine */
    {/* Index 36 */ 5, CNA_BEHAVIOR_SEND, 487, 37, 29, 1, 36, 1}, /* PassSeatVentnLvlSet_Nine */
    {/* Index 37 */ 5, CNA_BEHAVIOR_UNSEND, 491, 37, 30, 1, 37, 1}, /* SOCMngmntSwtReq */
    {/* Index 38 */ 5, CNA_BEHAVIOR_NONE, 371, 28, 31, 0, 38, 1}, /* ACDrvTempDecReq_ETC_TC */
    {/* Index 39 */ 5, CNA_BEHAVIOR_NONE, 372, 28, 31, 0, 39, 1}, /* ACDrvTempIncReq_ETC_TC */
    {/* Index 40 */ 5, CNA_BEHAVIOR_SEND, 377, 28, 31, 1, 40, 1}, /* ACMaxReq_TC */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 376, 28, 32, 1, 41, 1}, /* ACMaxReq_VR */
    {/* Index 42 */ 5, CNA_BEHAVIOR_SEND, 380, 28, 33, 1, 42, 1}, /* ACRearAutoModReq_VR */
    {/* Index 43 */ 5, CNA_BEHAVIOR_SEND, 375, 28, 34, 1, 43, 1}, /* ACRearPowerReq_VR */
    {/* Index 44 */ 5, CNA_BEHAVIOR_NONE, 373, 28, 35, 0, 44, 1}, /* ACRearTempDecReq_ETC_TC */
    {/* Index 45 */ 5, CNA_BEHAVIOR_NONE, 374, 28, 35, 0, 45, 1}, /* ACRearTempIncReq_ETC_TC */
    {/* Index 46 */ 5, CNA_BEHAVIOR_NONE, 369, 28, 35, 0, 46, 1}, /* ACRearTempReq_ETC_VR */
    {/* Index 47 */ 5, CNA_BEHAVIOR_NONE, 370, 28, 35, 0, 47, 1}, /* ACRearTempSteplsReq_ETC_TC */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 385, 28, 35, 0, 48, 1}, /* ColorCategory */
    {/* Index 49 */ 5, CNA_BEHAVIOR_SEND, 384, 28, 35, 1, 49, 1}, /* DPF_Request */
    {/* Index 50 */ 5, CNA_BEHAVIOR_NONE, 382, 28, 36, 0, 50, 1}, /* FreightLmpAutoSet */
    {/* Index 51 */ 5, CNA_BEHAVIOR_UNSEND, 381, 28, 36, 1, 51, 1}, /* FreightLmptSwt */
    {/* Index 52 */ 5, CNA_BEHAVIOR_NONE, 379, 28, 37, 0, 52, 1}, /* FrntWiprCtrl_VR */
    {/* Index 53 */ 5, CNA_BEHAVIOR_NONE, 383, 28, 37, 0, 53, 1}, /* LockWinSet */
    {/* Index 54 */ 5, CNA_BEHAVIOR_NONE, 378, 28, 37, 0, 54, 1}, /* SrSpdCtrlSwt */
    {/* Index 55 */ 5, CNA_BEHAVIOR_NONE, 387, 29, 37, 0, 55, 1}, /* MultiColorNr1 */
    {/* Index 56 */ 5, CNA_BEHAVIOR_NONE, 388, 29, 37, 0, 56, 1}, /* MultiColorNr2 */
    {/* Index 57 */ 5, CNA_BEHAVIOR_NONE, 389, 29, 37, 0, 57, 1}, /* MultiColorNr3 */
    {/* Index 58 */ 5, CNA_BEHAVIOR_NONE, 390, 29, 37, 0, 58, 1}, /* MultiColorNr4 */
    {/* Index 59 */ 5, CNA_BEHAVIOR_NONE, 391, 29, 37, 0, 59, 1}, /* MultiColorNr5 */
    {/* Index 60 */ 5, CNA_BEHAVIOR_NONE, 392, 29, 37, 0, 60, 1}, /* MultiColorNr6 */
    {/* Index 61 */ 5, CNA_BEHAVIOR_NONE, 393, 29, 37, 0, 61, 1}, /* MultiColorNr7 */
    {/* Index 62 */ 5, CNA_BEHAVIOR_NONE, 394, 29, 37, 0, 62, 1}, /* MultiColorNr8 */
    {/* Index 63 */ 5, CNA_BEHAVIOR_NONE, 419, 31, 37, 0, 63, 1}, /* ACFrntWinHeatCmd_TC */
    {/* Index 64 */ 5, CNA_BEHAVIOR_NONE, 420, 31, 37, 0, 64, 1}, /* ACFrntWinHeatCmd_VR */
    {/* Index 65 */ 5, CNA_BEHAVIOR_NONE, 414, 31, 37, 0, 65, 1}, /* ACHumidifierReq_TC */
    {/* Index 66 */ 5, CNA_BEHAVIOR_NONE, 413, 31, 37, 0, 66, 1}, /* ACHumidifierReq_VR */
    {/* Index 67 */ 5, CNA_BEHAVIOR_NONE, 415, 31, 37, 0, 67, 1}, /* ACOzoneReq_TC */
    {/* Index 68 */ 5, CNA_BEHAVIOR_NONE, 416, 31, 37, 0, 68, 1}, /* ACOzoneReq_VR */
    {/* Index 69 */ 5, CNA_BEHAVIOR_SEND, 405, 31, 37, 1, 69, 1}, /* ACRLTempDecReq_TC */
    {/* Index 70 */ 5, CNA_BEHAVIOR_SEND, 406, 31, 38, 1, 70, 1}, /* ACRLTempIncReq_TC */
    {/* Index 71 */ 5, CNA_BEHAVIOR_SEND, 409, 31, 39, 1, 71, 1}, /* ACRLTempReq_VR */
    {/* Index 72 */ 5, CNA_BEHAVIOR_SEND, 410, 31, 40, 1, 72, 1}, /* ACRLTempSteplsReq_TC */
    {/* Index 73 */ 5, CNA_BEHAVIOR_SEND, 407, 31, 41, 1, 73, 1}, /* ACRRTempDecReq_TC */
    {/* Index 74 */ 5, CNA_BEHAVIOR_SEND, 408, 31, 42, 1, 74, 1}, /* ACRRTempIncReq_TC */
    {/* Index 75 */ 5, CNA_BEHAVIOR_SEND, 411, 31, 43, 1, 75, 1}, /* ACRRTempReq_VR */
    {/* Index 76 */ 5, CNA_BEHAVIOR_SEND, 412, 31, 44, 1, 76, 1}, /* ACRRTempSteplsReq_TC */
    {/* Index 77 */ 5, CNA_BEHAVIOR_SEND, 417, 31, 45, 1, 77, 1}, /* ACUltravioletReq_TC */
    {/* Index 78 */ 5, CNA_BEHAVIOR_SEND, 418, 31, 46, 1, 78, 1}, /* ACUltravioletReq_VR */
    {/* Index 79 */ 5, CNA_BEHAVIOR_SEND, 421, 31, 47, 1, 79, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 80 */ 5, CNA_BEHAVIOR_SEND, 423, 31, 48, 1, 80, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 81 */ 5, CNA_BEHAVIOR_SEND, 425, 31, 49, 1, 81, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 82 */ 5, CNA_BEHAVIOR_SEND, 422, 31, 50, 1, 82, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 83 */ 5, CNA_BEHAVIOR_SEND, 424, 31, 51, 1, 83, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 84 */ 5, CNA_BEHAVIOR_SEND, 426, 31, 52, 1, 84, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 85 */ 5, CNA_BEHAVIOR_SEND, 304, 23, 53, 1, 85, 1}, /* BackReq_AVM */
    {/* Index 86 */ 5, CNA_BEHAVIOR_SEND, 302, 23, 54, 1, 86, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 301, 23, 55, 1, 87, 1}, /* HUD_HeightLvlSwt */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 303, 23, 56, 1, 88, 1}, /* HUD_SwtReq */
    {/* Index 89 */ 5, CNA_BEHAVIOR_NONE, 428, 32, 57, 0, 89, 1}, /* ActvEntryLockSet */
    {/* Index 90 */ 5, CNA_BEHAVIOR_NONE, 429, 32, 57, 0, 90, 1}, /* ActvEntryUnlockSet */
    {/* Index 91 */ 5, CNA_BEHAVIOR_NONE, 431, 32, 57, 0, 91, 1}, /* BTAPAEntryLockSet */
    {/* Index 92 */ 5, CNA_BEHAVIOR_NONE, 432, 32, 57, 0, 92, 1}, /* BTAPALvngUnlockSet */
    {/* Index 93 */ 5, CNA_BEHAVIOR_NONE, 433, 32, 57, 0, 93, 1}, /* ClsWinSpdSet */
    {/* Index 94 */ 5, CNA_BEHAVIOR_SEND, 440, 32, 57, 1, 94, 1}, /* DrvDoorALCMClrSet */
    {/* Index 95 */ 5, CNA_BEHAVIOR_NONE, 443, 32, 58, 0, 95, 1}, /* DrvDoorALCMSwt */
    {/* Index 96 */ 5, CNA_BEHAVIOR_SEND, 436, 32, 58, 1, 96, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 442, 32, 59, 1, 97, 1}, /* LRDoorALCMClrSet */
    {/* Index 98 */ 5, CNA_BEHAVIOR_NONE, 430, 32, 60, 0, 98, 1}, /* LockPromptFunSet */
    {/* Index 99 */ 5, CNA_BEHAVIOR_NONE, 434, 32, 60, 0, 99, 1}, /* OilBoxSplyReq */
    {/* Index 100 */ 5, CNA_BEHAVIOR_SEND, 441, 32, 60, 1, 100, 1}, /* PassDoorALCMClrSet */
    {/* Index 101 */ 5, CNA_BEHAVIOR_NONE, 444, 32, 61, 0, 101, 1}, /* PassDoorALCMSwt */
    {/* Index 102 */ 5, CNA_BEHAVIOR_SEND, 437, 32, 61, 1, 102, 1}, /* PassSeatMassgLvlSet */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 438, 32, 62, 1, 103, 1}, /* RLSeatMassgLvlSet */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 439, 32, 63, 1, 104, 1}, /* RRSeatMassgLvlSet */
    {/* Index 105 */ 5, CNA_BEHAVIOR_NONE, 435, 32, 64, 0, 105, 1}, /* SeatKeyMemEna */
    {/* Index 106 */ 5, CNA_BEHAVIOR_NONE, 397, 30, 64, 0, 106, 1}, /* MultiColorNr10 */
    {/* Index 107 */ 5, CNA_BEHAVIOR_NONE, 398, 30, 64, 0, 107, 1}, /* MultiColorNr11 */
    {/* Index 108 */ 5, CNA_BEHAVIOR_NONE, 399, 30, 64, 0, 108, 1}, /* MultiColorNr12 */
    {/* Index 109 */ 5, CNA_BEHAVIOR_NONE, 400, 30, 64, 0, 109, 1}, /* MultiColorNr13 */
    {/* Index 110 */ 5, CNA_BEHAVIOR_NONE, 401, 30, 64, 0, 110, 1}, /* MultiColorNr14 */
    {/* Index 111 */ 5, CNA_BEHAVIOR_NONE, 402, 30, 64, 0, 111, 1}, /* MultiColorNr15 */
    {/* Index 112 */ 5, CNA_BEHAVIOR_NONE, 403, 30, 64, 0, 112, 1}, /* MultiColorNr16 */
    {/* Index 113 */ 5, CNA_BEHAVIOR_NONE, 396, 30, 64, 0, 113, 1}, /* MultiColorNr9 */
    {/* Index 114 */ 5, CNA_BEHAVIOR_SEND, 354, 26, 64, 1, 114, 1}, /* ACFGAChanTyp_TC */
    {/* Index 115 */ 5, CNA_BEHAVIOR_SEND, 353, 26, 65, 1, 115, 1}, /* ACFGAEnaReq_TC */
    {/* Index 116 */ 5, CNA_BEHAVIOR_SEND, 355, 26, 66, 1, 116, 1}, /* ACFGALvlReq_TC */
    {/* Index 117 */ 6, CNA_BEHAVIOR_NONE, 331, 26, 67, 0, 117, 1}, /* ADASDispSwt */
    {/* Index 118 */ 6, CNA_BEHAVIOR_NONE, 334, 26, 67, 0, 118, 1}, /* ADASDispSwt_VR */
    {/* Index 119 */ 6, CNA_BEHAVIOR_NONE, 337, 26, 67, 0, 119, 1}, /* ALCMDynModSet */
    {/* Index 120 */ 6, CNA_BEHAVIOR_UNSEND, 335, 26, 67, 1, 120, 1}, /* ApproachLampSet */
    {/* Index 121 */ 5, CNA_BEHAVIOR_SEND, 352, 26, 68, 1, 121, 1}, /* BackReq_APS */
    {/* Index 122 */ 6, CNA_BEHAVIOR_SEND, 342, 26, 69, 1, 122, 1}, /* ChairMemPosnSetSwt */
    {/* Index 123 */ 5, CNA_BEHAVIOR_SEND, 349, 26, 70, 1, 123, 1}, /* DeletePath1Cmd */
    {/* Index 124 */ 5, CNA_BEHAVIOR_SEND, 347, 26, 71, 1, 124, 1}, /* DeletePath2Cmd */
    {/* Index 125 */ 6, CNA_BEHAVIOR_SEND, 340, 26, 72, 1, 125, 1}, /* DrvWinSwtReq_VR */
    {/* Index 126 */ 6, CNA_BEHAVIOR_UNSEND, 329, 26, 73, 1, 126, 1}, /* FlaoutUnlockSet */
    {/* Index 127 */ 6, CNA_BEHAVIOR_NONE, 332, 26, 74, 0, 127, 1}, /* NaviDispSwt */
    {/* Index 128 */ 6, CNA_BEHAVIOR_NONE, 333, 26, 74, 0, 128, 1}, /* NaviDispSwt_VR */
    {/* Index 129 */ 5, CNA_BEHAVIOR_SEND, 356, 26, 74, 1, 129, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 130 */ 5, CNA_BEHAVIOR_SEND, 351, 26, 75, 1, 130, 1}, /* ParkMdlCmd */
    {/* Index 131 */ 6, CNA_BEHAVIOR_SEND, 341, 26, 76, 1, 131, 1}, /* PassWinSwtReq_VR */
    {/* Index 132 */ 5, CNA_BEHAVIOR_SEND, 343, 26, 77, 1, 132, 1}, /* PathLrngFinshCmd */
    {/* Index 133 */ 5, CNA_BEHAVIOR_SEND, 344, 26, 78, 1, 133, 1}, /* PathLrngStartCmd */
    {/* Index 134 */ 6, CNA_BEHAVIOR_NONE, 330, 26, 79, 0, 134, 1}, /* PrkInDirChoice */
    {/* Index 135 */ 6, CNA_BEHAVIOR_SEND, 338, 26, 79, 1, 135, 1}, /* RLWinSwtReq_VR */
    {/* Index 136 */ 6, CNA_BEHAVIOR_SEND, 339, 26, 80, 1, 136, 1}, /* RRWinSwtReq_VR */
    {/* Index 137 */ 5, CNA_BEHAVIOR_SEND, 345, 26, 81, 1, 137, 1}, /* SelPrkOutDirReq */
    {/* Index 138 */ 5, CNA_BEHAVIOR_SEND, 350, 26, 82, 1, 138, 1}, /* SelPrkgFctnCmd */
    {/* Index 139 */ 5, CNA_BEHAVIOR_SEND, 348, 26, 83, 1, 139, 1}, /* StartPrkgPath1Cmd */
    {/* Index 140 */ 5, CNA_BEHAVIOR_SEND, 346, 26, 84, 1, 140, 1}, /* StartPrkgPath2Cmd */
    {/* Index 141 */ 6, CNA_BEHAVIOR_UNSEND, 336, 26, 85, 1, 141, 1}, /* SuperLockSet */
    {/* Index 142 */ 5, CNA_BEHAVIOR_NONE, 185, 12, 86, 0, 142, 1}, /* ABSLmpSet */
    {/* Index 143 */ 5, CNA_BEHAVIOR_SEND, 177, 12, 86, 1, 143, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 144 */ 5, CNA_BEHAVIOR_SEND, 175, 12, 87, 1, 144, 1}, /* ACOperMod_TC */
    {/* Index 145 */ 5, CNA_BEHAVIOR_SEND, 176, 12, 88, 1, 145, 1}, /* ACOperMod_VR */
    {/* Index 146 */ 5, CNA_BEHAVIOR_SEND, 178, 12, 89, 1, 146, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 147 */ 5, CNA_BEHAVIOR_SEND, 181, 12, 90, 1, 147, 1}, /* APSPrkgTypSeln */
    {/* Index 148 */ 5, CNA_BEHAVIOR_SEND, 180, 12, 91, 1, 148, 1}, /* APSSwtReq_VR */
    {/* Index 149 */ 5, CNA_BEHAVIOR_NONE, 186, 12, 92, 0, 149, 1}, /* AutoWshWipSet */
    {/* Index 150 */ 5, CNA_BEHAVIOR_NONE, 190, 12, 92, 0, 150, 1}, /* DoorUnlockModSet */
    {/* Index 151 */ 5, CNA_BEHAVIOR_NONE, 193, 12, 92, 0, 151, 1}, /* FrntRearACDispSts */
    {/* Index 152 */ 5, CNA_BEHAVIOR_SEND, 192, 12, 92, 1, 152, 1}, /* PASExitSpdSwt */
    {/* Index 153 */ 5, CNA_BEHAVIOR_NONE, 189, 12, 93, 0, 153, 1}, /* ParkLmpSet */
    {/* Index 154 */ 5, CNA_BEHAVIOR_SEND, 179, 12, 93, 1, 154, 1}, /* SDWSwtSet */
    {/* Index 155 */ 5, CNA_BEHAVIOR_NONE, 187, 12, 94, 0, 155, 1}, /* SeekVehSet */
    {/* Index 156 */ 5, CNA_BEHAVIOR_NONE, 188, 12, 94, 0, 156, 1}, /* SpdAutoLockModSet */
    {/* Index 157 */ 5, CNA_BEHAVIOR_NONE, 184, 12, 94, 0, 157, 1}, /* SportModLightSet */
    {/* Index 158 */ 5, CNA_BEHAVIOR_SEND, 191, 12, 94, 1, 158, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 159 */ 5, CNA_BEHAVIOR_SEND, 183, 12, 95, 1, 159, 1}, /* SunRoofSwtReq_VR */
    {/* Index 160 */ 5, CNA_BEHAVIOR_SEND, 182, 12, 96, 1, 160, 1}, /* SunShadeSwtReq_VR */
    {/* Index 161 */ 5, CNA_BEHAVIOR_UNSEND, 493, 38, 97, 1, 161, 1}, /* WinShortUpShortDownSet */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 459, 34, 98, 0, 162, 1}, /* ALCMBreSwt */
    {/* Index 163 */ 5, CNA_BEHAVIOR_NONE, 457, 34, 98, 0, 163, 1}, /* ALCMFloSwt */
    {/* Index 164 */ 5, CNA_BEHAVIOR_SEND, 461, 34, 98, 1, 164, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 165 */ 5, CNA_BEHAVIOR_NONE, 471, 34, 99, 0, 165, 1}, /* FootALCMSwt */
    {/* Index 166 */ 5, CNA_BEHAVIOR_SEND, 463, 34, 99, 1, 166, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 167 */ 5, CNA_BEHAVIOR_NONE, 469, 34, 100, 0, 167, 1}, /* LRDoorALCMSwt */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 458, 34, 100, 1, 168, 1}, /* LeftPanelALCMClrSet */
    {/* Index 169 */ 5, CNA_BEHAVIOR_SEND, 465, 34, 101, 1, 169, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 170 */ 5, CNA_BEHAVIOR_NONE, 467, 34, 102, 0, 170, 1}, /* LeftPanelALCMSwt */
    {/* Index 171 */ 5, CNA_BEHAVIOR_SEND, 462, 34, 102, 1, 171, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 172 */ 5, CNA_BEHAVIOR_SEND, 456, 34, 103, 1, 172, 1}, /* RRDoorALCMClrSet */
    {/* Index 173 */ 5, CNA_BEHAVIOR_SEND, 464, 34, 104, 1, 173, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 174 */ 5, CNA_BEHAVIOR_NONE, 470, 34, 105, 0, 174, 1}, /* RRDoorALCMSwt */
    {/* Index 175 */ 5, CNA_BEHAVIOR_SEND, 460, 34, 105, 1, 175, 1}, /* RightPanelALCMClrSet */
    {/* Index 176 */ 5, CNA_BEHAVIOR_SEND, 466, 34, 106, 1, 176, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 468, 34, 107, 0, 177, 1}, /* RightPanelALCMSwt */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 472, 34, 107, 0, 178, 1}, /* RoofALCMSwt */
    {/* Index 179 */ 5, CNA_BEHAVIOR_NONE, 480, 35, 107, 0, 179, 1}, /* ChairMemPosnEna_SecRow */
    {/* Index 180 */ 5, CNA_BEHAVIOR_SEND, 476, 35, 107, 1, 180, 1}, /* DrvSeatHeatgLvlSet_Nine */
    {/* Index 181 */ 5, CNA_BEHAVIOR_SEND, 477, 35, 108, 1, 181, 1}, /* PassSeatHeatgLvlSet_Nine */
    {/* Index 182 */ 5, CNA_BEHAVIOR_SEND, 474, 35, 109, 1, 182, 1}, /* RLSeatMassgModSet */
    {/* Index 183 */ 5, CNA_BEHAVIOR_SEND, 475, 35, 110, 1, 183, 1}, /* RRSeatMassgModSet */
    {/* Index 184 */ 5, CNA_BEHAVIOR_UNSEND, 478, 35, 111, 1, 184, 1}, /* RWinSwtReq_TC */
    {/* Index 185 */ 5, CNA_BEHAVIOR_NONE, 479, 35, 112, 0, 185, 1}, /* RWinSwtReq_VR */
    {/* Index 186 */ 5, CNA_BEHAVIOR_NONE, 284, 19, 112, 0, 186, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 276, 19, 112, 0, 187, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 188 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 112, 0, 188, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 282, 19, 112, 0, 189, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 190 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 112, 0, 190, 1}, /* ADAS_Stub_LastStub */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 274, 19, 112, 0, 191, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 192 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 112, 0, 192, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 193 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 112, 0, 193, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 194 */ 5, CNA_BEHAVIOR_NONE, 275, 19, 112, 0, 194, 2}, /* ADAS_Stub_Offset */
    {/* Index 195 */ 5, CNA_BEHAVIOR_NONE, 283, 19, 112, 0, 196, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 196 */ 5, CNA_BEHAVIOR_NONE, 277, 19, 112, 0, 197, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 197 */ 5, CNA_BEHAVIOR_NONE, 281, 19, 112, 0, 198, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 198 */ 5, CNA_BEHAVIOR_NONE, 279, 19, 112, 0, 199, 1}, /* ADAS_Stub_Retr */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 112, 0, 200, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 278, 19, 112, 0, 201, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 201 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 112, 0, 202, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 280, 19, 112, 0, 203, 1}, /* ADAS_Stub_Update */
    {/* Index 203 */ 5, CNA_BEHAVIOR_NONE, 259, 18, 112, 0, 204, 1}, /* ADAS_Seg_Brdg */
    {/* Index 204 */ 5, CNA_BEHAVIOR_NONE, 260, 18, 112, 0, 205, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 205 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 112, 0, 206, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 206 */ 5, CNA_BEHAVIOR_NONE, 256, 18, 112, 0, 207, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 207 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 112, 0, 208, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 112, 0, 209, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 112, 0, 210, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 112, 0, 211, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 264, 18, 112, 0, 212, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 254, 18, 112, 0, 213, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 112, 0, 214, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 112, 0, 215, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 255, 18, 112, 0, 216, 2}, /* ADAS_Seg_Offset */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 112, 0, 218, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 257, 18, 112, 0, 219, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 263, 18, 112, 0, 220, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 261, 18, 112, 0, 221, 1}, /* ADAS_Seg_Retr */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 258, 18, 112, 0, 222, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 262, 18, 112, 0, 223, 1}, /* ADAS_Seg_Update */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 249, 17, 112, 0, 224, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 246, 17, 112, 0, 225, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 243, 17, 112, 0, 226, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 250, 17, 112, 0, 227, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 241, 17, 112, 0, 229, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 242, 17, 112, 0, 230, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 244, 17, 112, 0, 232, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 245, 17, 112, 0, 233, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 247, 17, 112, 0, 234, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 248, 17, 112, 0, 235, 1}, /* ADAS_ProfShort_Update */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 251, 17, 112, 0, 236, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 112, 0, 238, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 236, 16, 112, 0, 240, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 233, 16, 112, 0, 241, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 231, 16, 112, 0, 242, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 232, 16, 112, 0, 243, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 234, 16, 112, 0, 245, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 235, 16, 112, 0, 246, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 240 */ 5, CNA_BEHAVIOR_NONE, 237, 16, 112, 0, 247, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 241 */ 5, CNA_BEHAVIOR_NONE, 238, 16, 112, 0, 248, 1}, /* ADAS_ProfLong_Update */
    {/* Index 242 */ 5, CNA_BEHAVIOR_NONE, 239, 16, 112, 0, 249, 4}, /* ADAS_ProfLong_Value */
    {/* Index 243 */ 5, CNA_BEHAVIOR_SEND, 153, 9, 112, 1, 253, 1}, /* ACAIUReq_VR */
    {/* Index 244 */ 5, CNA_BEHAVIOR_SEND, 150, 9, 113, 1, 254, 1}, /* ACAQSReq_VR */
    {/* Index 245 */ 5, CNA_BEHAVIOR_SEND, 149, 9, 114, 1, 255, 1}, /* ACDualReq_VR */
    {/* Index 246 */ 5, CNA_BEHAVIOR_SEND, 152, 9, 115, 1, 256, 1}, /* ACPassTempReq_VR */
    {/* Index 247 */ 5, CNA_BEHAVIOR_SEND, 151, 9, 116, 1, 257, 1}, /* ACRearDefrstReq_VR */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 157, 9, 117, 0, 258, 1}, /* ALCMClrSet */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 155, 9, 117, 0, 259, 1}, /* ALCMDynSwt */
    {/* Index 250 */ 5, CNA_BEHAVIOR_NONE, 158, 9, 117, 0, 260, 1}, /* ALCMRhmSwt */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 154, 9, 117, 0, 261, 1}, /* ALCMStatSwt */
    {/* Index 252 */ 3, CNA_BEHAVIOR_SEND, 156, 9, 117, 1, 262, 1}, /* HUT_BeanIDReq */
    {/* Index 253 */ 5, CNA_BEHAVIOR_UNSEND, 161, 9, 118, 1, 263, 1}, /* HUT_EgyRecvrySet */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 159, 9, 119, 0, 264, 1}, /* IPVolSet */
    {/* Index 255 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 119, 1, 265, 1}, /* PASSwtReq_VR */
    {/* Index 256 */ 5, CNA_BEHAVIOR_SEND, 293, 20, 120, 1, 266, 1}, /* ACDrvSetTempReq_ETC_VR */
    {/* Index 257 */ 5, CNA_BEHAVIOR_SEND, 294, 20, 121, 1, 267, 1}, /* ACDrvSetTempSteplsReq_ETC_TC */
    {/* Index 258 */ 5, CNA_BEHAVIOR_SEND, 292, 20, 122, 1, 268, 1}, /* HUT_RemtEngCtrl */
    {/* Index 259 */ 5, CNA_BEHAVIOR_SEND, 213, 14, 123, 1, 269, 1}, /* ACRearAirDistribModReq_VR */
    {/* Index 260 */ 5, CNA_BEHAVIOR_SEND, 210, 14, 124, 1, 270, 1}, /* ACRearBlwrSpdReq_VR */
    {/* Index 261 */ 5, CNA_BEHAVIOR_SEND, 211, 14, 125, 1, 271, 1}, /* ACRearBlwrsteplsSpdReq_TC */
    {/* Index 262 */ 5, CNA_BEHAVIOR_SEND, 214, 14, 126, 1, 272, 1}, /* ACZoneReq_VR */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 207, 14, 127, 0, 273, 1}, /* AVMMediaVolLvlReq */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 205, 14, 127, 0, 274, 1}, /* AVMSwtReq */
    {/* Index 265 */ 5, CNA_BEHAVIOR_SEND, 201, 14, 127, 1, 275, 1}, /* BackgroundLightLvlSet */
    {/* Index 266 */ 5, CNA_BEHAVIOR_NONE, 203, 14, 128, 0, 276, 1}, /* DispModSet */
    {/* Index 267 */ 5, CNA_BEHAVIOR_NONE, 208, 14, 128, 0, 277, 1}, /* FPASChanSwtReq */
    {/* Index 268 */ 5, CNA_BEHAVIOR_NONE, 202, 14, 128, 0, 278, 1}, /* ManCmpSet */
    {/* Index 269 */ 5, CNA_BEHAVIOR_NONE, 206, 14, 128, 0, 279, 1}, /* NaviMediaVolLvlReq */
    {/* Index 270 */ 5, CNA_BEHAVIOR_UNSEND, 215, 14, 128, 1, 280, 1}, /* OPDSwtSts */
    {/* Index 271 */ 5, CNA_BEHAVIOR_UNSEND, 212, 14, 129, 1, 281, 1}, /* PLGReq_VR */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 209, 14, 130, 0, 282, 1}, /* RPASChanSwtReq */
    {/* Index 273 */ 5, CNA_BEHAVIOR_UNSEND, 204, 14, 130, 1, 283, 1}, /* WPC_SwtReq */
    {/* Index 274 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 131, 1, 284, 1}, /* ACAIUReq_TC */
    {/* Index 275 */ 5, CNA_BEHAVIOR_SEND, 47, 3, 132, 1, 285, 1}, /* ACAQSReq_TC */
    {/* Index 276 */ 5, CNA_BEHAVIOR_SEND, 44, 3, 133, 1, 286, 1}, /* ACAirInletReq_TC */
    {/* Index 277 */ 5, CNA_BEHAVIOR_SEND, 43, 3, 134, 1, 287, 1}, /* ACAutoModReq_TC */
    {/* Index 278 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 135, 1, 288, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 279 */ 5, CNA_BEHAVIOR_SEND, 48, 3, 136, 1, 289, 1}, /* ACCmprReq_TC */
    {/* Index 280 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 137, 1, 290, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 281 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 138, 1, 291, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 282 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 139, 1, 292, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 283 */ 5, CNA_BEHAVIOR_SEND, 42, 3, 140, 1, 293, 1}, /* ACDualReq_TC */
    {/* Index 284 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 141, 1, 294, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 285 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 142, 1, 295, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 143, 1, 296, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 287 */ 5, CNA_BEHAVIOR_SEND, 45, 3, 144, 1, 297, 1}, /* ACFrntHMIDis_TC */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 145, 1, 298, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 289 */ 5, CNA_BEHAVIOR_SEND, 60, 3, 146, 1, 299, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 290 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 147, 1, 300, 1}, /* ACOffReq_TC */
    {/* Index 291 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 148, 1, 301, 1}, /* ACRearBlwrSpdDecReq_TC */
    {/* Index 292 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 149, 1, 302, 1}, /* ACRearBlwrSpdIncReq_TC */
    {/* Index 293 */ 5, CNA_BEHAVIOR_SEND, 46, 3, 150, 1, 303, 1}, /* ACRearHMIDis_TC */
    {/* Index 294 */ 5, CNA_BEHAVIOR_SEND, 64, 3, 151, 1, 304, 1}, /* ACZoneReq_TC */
    {/* Index 295 */ 5, CNA_BEHAVIOR_NONE, 41, 3, 152, 0, 305, 1}, /* BattSaveDelayTimeSet */
    {/* Index 296 */ 5, CNA_BEHAVIOR_NONE, 57, 3, 152, 0, 306, 1}, /* ChairMemPosnEna */
    {/* Index 297 */ 5, CNA_BEHAVIOR_NONE, 37, 3, 152, 0, 307, 1}, /* DomeLmpDlyTimSet */
    {/* Index 298 */ 5, CNA_BEHAVIOR_NONE, 53, 3, 152, 0, 308, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 299 */ 5, CNA_BEHAVIOR_NONE, 38, 3, 152, 0, 309, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 300 */ 5, CNA_BEHAVIOR_NONE, 40, 3, 152, 0, 310, 1}, /* RearviewFoldModSet */
    {/* Index 301 */ 5, CNA_BEHAVIOR_NONE, 39, 3, 152, 0, 311, 1}, /* TranPMode_Req */
    {/* Index 302 */ 5, CNA_BEHAVIOR_NONE, 71, 4, 152, 0, 312, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 303 */ 5, CNA_BEHAVIOR_NONE, 69, 4, 152, 0, 313, 1}, /* AMP_BeepSourceSet */
    {/* Index 304 */ 5, CNA_BEHAVIOR_NONE, 72, 4, 152, 0, 314, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 305 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 152, 0, 315, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 306 */ 5, CNA_BEHAVIOR_NONE, 70, 4, 152, 0, 316, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 307 */ 5, CNA_BEHAVIOR_NONE, 73, 4, 152, 0, 317, 1}, /* AMP_LRDrvSideSet */
    {/* Index 308 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 152, 0, 318, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 309 */ 5, CNA_BEHAVIOR_NONE, 67, 4, 152, 0, 319, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 310 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 152, 0, 320, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 311 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 152, 0, 321, 1}, /* AMP_MuteSet */
    {/* Index 312 */ 5, CNA_BEHAVIOR_NONE, 68, 4, 152, 0, 322, 1}, /* AMP_NaviSourceSet */
    {/* Index 313 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 152, 0, 323, 1}, /* ANCSwtSet */
    {/* Index 314 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 152, 0, 324, 1}, /* QLISurroundSet */
    {/* Index 315 */ 5, CNA_BEHAVIOR_SEND, 66, 4, 152, 1, 325, 1}, /* RearWinHeatCmd_TC */
    {/* Index 316 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 153, 0, 326, 1}, /* T_box_ECallSet */
    {/* Index 317 */ 5, CNA_BEHAVIOR_NONE, 93, 5, 153, 0, 327, 1}, /* AMP_BestListegPosnReq */
    {/* Index 318 */ 5, CNA_BEHAVIOR_NONE, 94, 5, 153, 0, 328, 1}, /* AMP_Clari_FiReq */
    {/* Index 319 */ 5, CNA_BEHAVIOR_SEND, 90, 5, 153, 1, 329, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 320 */ 5, CNA_BEHAVIOR_SEND, 87, 5, 154, 1, 330, 1}, /* AMP_GetHWInfoReq */
    {/* Index 321 */ 5, CNA_BEHAVIOR_SEND, 89, 5, 155, 1, 331, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 322 */ 5, CNA_BEHAVIOR_SEND, 86, 5, 156, 1, 332, 1}, /* AMP_GetSWInfoReq */
    {/* Index 323 */ 5, CNA_BEHAVIOR_SEND, 88, 5, 157, 1, 333, 1}, /* AMP_GetTempInfoReq */
    {/* Index 324 */ 5, CNA_BEHAVIOR_NONE, 82, 5, 158, 0, 334, 1}, /* AMP_HFMVolSet */
    {/* Index 325 */ 5, CNA_BEHAVIOR_NONE, 85, 5, 158, 0, 335, 1}, /* AMP_MainVolSet */
    {/* Index 326 */ 5, CNA_BEHAVIOR_NONE, 84, 5, 158, 0, 336, 1}, /* AMP_NaviVolSet */
    {/* Index 327 */ 5, CNA_BEHAVIOR_NONE, 83, 5, 158, 0, 337, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 328 */ 5, CNA_BEHAVIOR_NONE, 92, 5, 158, 0, 338, 1}, /* IESS_MdlInfoReq */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 91, 5, 158, 0, 339, 1}, /* IESS_MdlSwtReq */
    {/* Index 330 */ 5, CNA_BEHAVIOR_SEND, 116, 6, 158, 1, 340, 1}, /* ACAirInletReq_VR */
    {/* Index 331 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 159, 1, 341, 1}, /* ACAutoModReq_VR */
    {/* Index 332 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 160, 1, 342, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 333 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 161, 1, 343, 1}, /* ACCmprReq_VR */
    {/* Index 334 */ 5, CNA_BEHAVIOR_SEND, 115, 6, 162, 1, 344, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 335 */ 5, CNA_BEHAVIOR_SEND, 113, 6, 163, 1, 345, 1}, /* ACDrvTempReq_VR */
    {/* Index 336 */ 5, CNA_BEHAVIOR_SEND, 114, 6, 164, 1, 346, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 337 */ 5, CNA_BEHAVIOR_NONE, 118, 6, 165, 0, 347, 1}, /* ACModReq_HUT */
    {/* Index 338 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 165, 1, 348, 1}, /* ACPowerReq_VR */
    {/* Index 339 */ 5, CNA_BEHAVIOR_SEND, 117, 6, 166, 1, 349, 1}, /* ACRearAirDistribModReq_TC */
    {/* Index 340 */ 5, CNA_BEHAVIOR_SEND, 98, 6, 167, 1, 350, 1}, /* ACRearAutoModReq_TC */
    {/* Index 341 */ 5, CNA_BEHAVIOR_SEND, 99, 6, 168, 1, 351, 1}, /* ACRearOffReq_TC */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 108, 6, 169, 0, 352, 1}, /* AllTerrainDislSet */
    {/* Index 343 */ 5, CNA_BEHAVIOR_NONE, 96, 6, 169, 0, 353, 1}, /* DrvSeatSupportLvlSet */
    {/* Index 344 */ 5, CNA_BEHAVIOR_NONE, 100, 6, 169, 0, 354, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 345 */ 5, CNA_BEHAVIOR_NONE, 102, 6, 169, 0, 355, 1}, /* ElecSideSteppingSysSet */
    {/* Index 346 */ 5, CNA_BEHAVIOR_NONE, 97, 6, 169, 0, 356, 1}, /* PassSeatSupportLvlSet */
    {/* Index 347 */ 5, CNA_BEHAVIOR_NONE, 101, 6, 169, 0, 357, 1}, /* PassSeatVentnLvlSet */
    {/* Index 348 */ 5, CNA_BEHAVIOR_NONE, 106, 6, 169, 0, 358, 1}, /* RLSeatHeatgLvlSet */
    {/* Index 349 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 169, 0, 359, 1}, /* RLSeatVentnLvlSet */
    {/* Index 350 */ 5, CNA_BEHAVIOR_NONE, 107, 6, 169, 0, 360, 1}, /* RRSeatHeatgLvlSet */
    {/* Index 351 */ 5, CNA_BEHAVIOR_NONE, 105, 6, 169, 0, 361, 1}, /* RRSeatVentnLvlSet */
    {/* Index 352 */ 5, CNA_BEHAVIOR_SEND, 119, 6, 169, 1, 362, 1}, /* RemUpgrdSts */
    {/* Index 353 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 170, 0, 363, 1}, /* RoofModSet */
    {/* Index 354 */ 5, CNA_BEHAVIOR_CYCLE, 316, 25, 170, 1, 364, 1}, /* ContnPrkgReq */
    {/* Index 355 */ 5, CNA_BEHAVIOR_CYCLE, 314, 25, 171, 1, 365, 1}, /* PrkgCtrlModReq */
    {/* Index 356 */ 5, CNA_BEHAVIOR_CYCLE, 543, 39, 172, 1, 366, 1}, /* ChairMemPosnSet */
    {/* Index 357 */ 5, CNA_BEHAVIOR_CYCLE, 519, 39, 173, 1, 367, 1}, /* EPSSteerModSwtReq */
    {/* Index 358 */ 5, CNA_BEHAVIOR_CYCLE, 579, 39, 174, 1, 368, 1}, /* HUT_HybModReq */
    {/* Index 359 */ 5, CNA_BEHAVIOR_CYCLE, 520, 39, 175, 1, 369, 1}, /* OilLvlDispReq */
    {/* Index 360 */ 5, CNA_BEHAVIOR_CYCLE, 169, 11, 176, 1, 370, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = {0u};
static const uint8 cna_noActionBuffer[177] =
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
    0u,
    0u,
    0u,
    64u,
    4u,
    64u,
    64u,
    4u,
    4u,
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
    0u,
    0u,
    0u,
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
};

static const ComEx_SignalIdType CNA_IdTable[691] =
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
    297,
    299,
    301,
    300,
    295,
    283,
    277,
    276,
    287,
    293,
    275,
    279,
    286,
    284,
    291,
    292,
    298,
    285,
    280,
    281,
    296,
    282,
    288,
    289,
    274,
    290,
    278,
    294,
    65535,
    315,
    309,
    312,
    303,
    306,
    302,
    304,
    307,
    308,
    311,
    310,
    305,
    316,
    314,
    313,
    65535,
    324,
    327,
    326,
    325,
    322,
    320,
    323,
    321,
    319,
    329,
    328,
    317,
    318,
    65535,
    343,
    346,
    340,
    341,
    344,
    347,
    345,
    349,
    353,
    351,
    348,
    350,
    342,
    331,
    333,
    338,
    332,
    335,
    336,
    334,
    330,
    339,
    337,
    352,
    65535,
    9,
    10,
    17,
    19,
    21,
    16,
    22,
    23,
    12,
    20,
    14,
    13,
    11,
    15,
    18,
    25,
    24,
    65535,
    6,
    1,
    2,
    3,
    0,
    4,
    5,
    8,
    7,
    65535,
    245,
    244,
    247,
    246,
    243,
    251,
    249,
    252,
    248,
    250,
    254,
    255,
    253,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    360,
    65535,
    65535,
    65535,
    65535,
    65535,
    144,
    145,
    143,
    146,
    154,
    148,
    147,
    160,
    159,
    157,
    142,
    149,
    155,
    156,
    153,
    150,
    158,
    152,
    151,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    265,
    268,
    266,
    273,
    264,
    269,
    263,
    267,
    272,
    260,
    261,
    271,
    259,
    262,
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
    236,
    237,
    235,
    238,
    239,
    234,
    240,
    241,
    242,
    65535,
    226,
    227,
    224,
    228,
    229,
    223,
    230,
    231,
    222,
    225,
    232,
    233,
    65535,
    212,
    215,
    206,
    217,
    220,
    203,
    204,
    219,
    221,
    218,
    211,
    216,
    205,
    210,
    208,
    209,
    207,
    214,
    213,
    65535,
    191,
    194,
    187,
    196,
    200,
    198,
    202,
    197,
    189,
    195,
    186,
    188,
    201,
    190,
    199,
    193,
    192,
    65535,
    258,
    256,
    257,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    87,
    86,
    88,
    85,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    355,
    65535,
    354,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    126,
    134,
    117,
    127,
    128,
    118,
    120,
    141,
    119,
    135,
    136,
    125,
    131,
    122,
    132,
    133,
    137,
    140,
    124,
    139,
    123,
    138,
    130,
    121,
    115,
    114,
    116,
    129,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    46,
    47,
    38,
    39,
    44,
    45,
    43,
    41,
    40,
    54,
    52,
    42,
    51,
    50,
    53,
    49,
    48,
    65535,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    65535,
    113,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    65535,
    69,
    70,
    73,
    74,
    71,
    72,
    75,
    76,
    66,
    65,
    67,
    68,
    77,
    78,
    63,
    64,
    79,
    82,
    80,
    83,
    81,
    84,
    65535,
    89,
    90,
    98,
    91,
    92,
    93,
    99,
    105,
    96,
    102,
    103,
    104,
    94,
    100,
    97,
    95,
    101,
    65535,
    65535,
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
    163,
    168,
    162,
    175,
    164,
    171,
    166,
    173,
    169,
    176,
    170,
    177,
    167,
    174,
    165,
    178,
    65535,
    182,
    183,
    180,
    181,
    184,
    185,
    179,
    65535,
    31,
    30,
    29,
    65535,
    35,
    36,
    33,
    34,
    32,
    37,
    65535,
    161,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    357,
    359,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    356,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    358,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    28,
    27,
    26,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[371] = {0};

const CNA_ConfigType cna_config =
{
    SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER,
    cna_signalConfigs,
    cna_signalDatas,
    177u,
    cna_noActionBuffer,
    371u,
    cna_currentBuffer,
    691u,
    CNA_IdTable
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
