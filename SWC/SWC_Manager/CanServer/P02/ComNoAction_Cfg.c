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
#ifndef SWC_IPC_CAN_MATRIX_P02H
#include "SWC_IPC_CANMatrix_P02.h"
#if (0xcc43e727 != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
      #error " Noaction version dismatch!!! "
#endif
#endif

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static const CNA_SignalConfigType cna_signalConfigs[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 152, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 148, 8, 0, 0, 1, 1}, /* ALCMClrSet_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_NONE, 149, 8, 0, 0, 2, 1}, /* ALCMDynModSet_OLE */
    {/* Index 3 */ 5, CNA_BEHAVIOR_NONE, 150, 8, 0, 0, 3, 1}, /* ALCMLightLvlSet_OLE */
    {/* Index 4 */ 5, CNA_BEHAVIOR_NONE, 153, 8, 0, 0, 4, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 5 */ 5, CNA_BEHAVIOR_NONE, 151, 8, 0, 0, 5, 1}, /* ALCMRhmSwt_OLE */
    {/* Index 6 */ 5, CNA_BEHAVIOR_NONE, 147, 8, 0, 0, 6, 1}, /* ALCMStatSwt_OLE */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 156, 8, 0, 1, 7, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 155, 8, 1, 1, 8, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 9 */ 5, CNA_BEHAVIOR_UNSEND, 157, 8, 2, 1, 9, 1}, /* OTA_UpgrdModReq */
    {/* Index 10 */ 5, CNA_BEHAVIOR_NONE, 154, 8, 3, 0, 10, 1}, /* Rdm_SingleColorNr */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 3, 1, 11, 1}, /* AUTODefrost_TC */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 4, 1, 12, 1}, /* AUTODefrost_VR */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 141, 7, 5, 1, 13, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 137, 7, 6, 1, 14, 1}, /* AutoViewChgCmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 140, 7, 7, 1, 15, 1}, /* CarMdlDispCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 139, 7, 8, 1, 16, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 142, 7, 9, 1, 17, 1}, /* FPAS_AutoModSwt */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 10, 1, 18, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 11, 1, 19, 1}, /* LaneCalActvtCmd */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 143, 7, 12, 1, 20, 1}, /* MEBSwtSet */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 13, 1, 21, 1}, /* MODChgReq */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 138, 7, 14, 1, 22, 1}, /* MdlColrChgCmd */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 15, 1, 23, 1}, /* Radar_DispCmd */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 135, 7, 16, 1, 24, 1}, /* Sgl_View_Sel */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 136, 7, 17, 1, 25, 1}, /* SwToFieldCalRstCmd */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 145, 7, 18, 1, 26, 1}, /* View_SoftswitchCmd */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 144, 7, 19, 1, 27, 1}, /* WshSoftSwt */
    {/* Index 28 */ 5, CNA_BEHAVIOR_NONE, 523, 39, 20, 0, 28, 4}, /* AntiDisIdnResp */
    {/* Index 29 */ 5, CNA_BEHAVIOR_SEND, 692, 43, 20, 1, 32, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 30 */ 5, CNA_BEHAVIOR_UNSEND, 696, 43, 21, 1, 33, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 31 */ 5, CNA_BEHAVIOR_NONE, 698, 43, 22, 0, 34, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 32 */ 5, CNA_BEHAVIOR_NONE, 697, 43, 22, 0, 35, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 33 */ 5, CNA_BEHAVIOR_NONE, 699, 43, 22, 0, 36, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 34 */ 5, CNA_BEHAVIOR_SEND, 695, 43, 22, 1, 37, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 694, 43, 23, 1, 38, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 36 */ 5, CNA_BEHAVIOR_SEND, 691, 43, 24, 1, 39, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 37 */ 5, CNA_BEHAVIOR_SEND, 690, 43, 25, 1, 40, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 38 */ 5, CNA_BEHAVIOR_NONE, 700, 43, 26, 0, 41, 1}, /* HUT_PAVP_PathList_Req */
    {/* Index 39 */ 5, CNA_BEHAVIOR_SEND, 688, 43, 26, 1, 42, 1}, /* SlotNum_VR */
    {/* Index 40 */ 5, CNA_BEHAVIOR_SEND, 693, 43, 27, 1, 43, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 689, 43, 28, 1, 44, 1}, /* UserDefinedParkCmd */
    {/* Index 42 */ 5, CNA_BEHAVIOR_NONE, 702, 44, 29, 0, 45, 64}, /* HUT_ExternalDevice */
    {/* Index 43 */ 5, CNA_BEHAVIOR_SEND, 510, 37, 29, 1, 109, 1}, /* DrvSeatMassgModSet */
    {/* Index 44 */ 5, CNA_BEHAVIOR_UNSEND, 511, 37, 30, 1, 110, 1}, /* PPMI_P_BSR_SwtSet */
    {/* Index 45 */ 5, CNA_BEHAVIOR_SEND, 509, 37, 31, 1, 111, 1}, /* PassSeatMassgModSet */
    {/* Index 46 */ 5, CNA_BEHAVIOR_UNSEND, 512, 37, 32, 1, 112, 1}, /* RWPC_SwtReq */
    {/* Index 47 */ 5, CNA_BEHAVIOR_UNSEND, 520, 38, 33, 1, 113, 1}, /* AGSSwtReq */
    {/* Index 48 */ 5, CNA_BEHAVIOR_UNSEND, 518, 38, 34, 1, 114, 1}, /* ARFSwtReq */
    {/* Index 49 */ 5, CNA_BEHAVIOR_UNSEND, 519, 38, 35, 1, 115, 1}, /* ASFCSwtReq */
    {/* Index 50 */ 5, CNA_BEHAVIOR_SEND, 514, 38, 36, 1, 116, 1}, /* DrvSeatVentnLvlSet_Nine */
    {/* Index 51 */ 5, CNA_BEHAVIOR_SEND, 515, 38, 37, 1, 117, 1}, /* PassSeatVentnLvlSet_Nine */
    {/* Index 52 */ 5, CNA_BEHAVIOR_SEND, 516, 38, 38, 1, 118, 1}, /* RLSeatVentnLvlSet_Nine */
    {/* Index 53 */ 5, CNA_BEHAVIOR_SEND, 517, 38, 39, 1, 119, 1}, /* RRSeatVentnLvlSet_Nine */
    {/* Index 54 */ 5, CNA_BEHAVIOR_UNSEND, 521, 38, 40, 1, 120, 1}, /* SOCMngmntSwtReq */
    {/* Index 55 */ 5, CNA_BEHAVIOR_NONE, 394, 28, 41, 0, 121, 1}, /* ACDrvTempDecReq_ETC_TC */
    {/* Index 56 */ 5, CNA_BEHAVIOR_NONE, 395, 28, 41, 0, 122, 1}, /* ACDrvTempIncReq_ETC_TC */
    {/* Index 57 */ 5, CNA_BEHAVIOR_SEND, 400, 28, 41, 1, 123, 1}, /* ACMaxReq_TC */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 399, 28, 42, 1, 124, 1}, /* ACMaxReq_VR */
    {/* Index 59 */ 5, CNA_BEHAVIOR_SEND, 402, 28, 43, 1, 125, 1}, /* ACRearAutoModReq_VR */
    {/* Index 60 */ 5, CNA_BEHAVIOR_SEND, 404, 28, 44, 1, 126, 1}, /* ACRearLockReq_TC */
    {/* Index 61 */ 5, CNA_BEHAVIOR_SEND, 398, 28, 45, 1, 127, 1}, /* ACRearPowerReq_VR */
    {/* Index 62 */ 5, CNA_BEHAVIOR_NONE, 396, 28, 46, 0, 128, 1}, /* ACRearTempDecReq_ETC_TC */
    {/* Index 63 */ 5, CNA_BEHAVIOR_NONE, 397, 28, 46, 0, 129, 1}, /* ACRearTempIncReq_ETC_TC */
    {/* Index 64 */ 5, CNA_BEHAVIOR_NONE, 392, 28, 46, 0, 130, 1}, /* ACRearTempReq_ETC_VR */
    {/* Index 65 */ 5, CNA_BEHAVIOR_NONE, 393, 28, 46, 0, 131, 1}, /* ACRearTempSteplsReq_ETC_TC */
    {/* Index 66 */ 5, CNA_BEHAVIOR_NONE, 407, 28, 46, 0, 132, 1}, /* ColorCategory */
    {/* Index 67 */ 5, CNA_BEHAVIOR_NONE, 406, 28, 46, 1, 133, 1}, /* DPF_Request */
    {/* Index 68 */ 5, CNA_BEHAVIOR_NONE, 401, 28, 47, 0, 134, 1}, /* FrntWiprCtrl_VR */
    {/* Index 69 */ 5, CNA_BEHAVIOR_NONE, 403, 28, 47, 0, 135, 1}, /* LockWinSet */
    {/* Index 70 */ 5, CNA_BEHAVIOR_NONE, 409, 28, 47, 0, 136, 1}, /* NozHeatSwt */
    {/* Index 71 */ 5, CNA_BEHAVIOR_NONE, 408, 28, 47, 0, 137, 1}, /* SingleColorNr */
    {/* Index 72 */ 5, CNA_BEHAVIOR_NONE, 405, 28, 47, 0, 138, 1}, /* SrSpdCtrlSwt */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 411, 29, 47, 0, 139, 1}, /* MultiColorNr1 */
    {/* Index 74 */ 5, CNA_BEHAVIOR_NONE, 412, 29, 47, 0, 140, 1}, /* MultiColorNr2 */
    {/* Index 75 */ 5, CNA_BEHAVIOR_NONE, 413, 29, 47, 0, 141, 1}, /* MultiColorNr3 */
    {/* Index 76 */ 5, CNA_BEHAVIOR_NONE, 414, 29, 47, 0, 142, 1}, /* MultiColorNr4 */
    {/* Index 77 */ 5, CNA_BEHAVIOR_NONE, 415, 29, 47, 0, 143, 1}, /* MultiColorNr5 */
    {/* Index 78 */ 5, CNA_BEHAVIOR_NONE, 416, 29, 47, 0, 144, 1}, /* MultiColorNr6 */
    {/* Index 79 */ 5, CNA_BEHAVIOR_NONE, 417, 29, 47, 0, 145, 1}, /* MultiColorNr7 */
    {/* Index 80 */ 5, CNA_BEHAVIOR_NONE, 418, 29, 47, 0, 146, 1}, /* MultiColorNr8 */
    {/* Index 81 */ 5, CNA_BEHAVIOR_NONE, 442, 31, 47, 0, 147, 1}, /* ACFrntWinHeatCmd_TC */
    {/* Index 82 */ 5, CNA_BEHAVIOR_NONE, 443, 31, 47, 0, 148, 1}, /* ACFrntWinHeatCmd_VR */
    {/* Index 83 */ 5, CNA_BEHAVIOR_NONE, 437, 31, 47, 0, 149, 1}, /* ACHumidifierReq_TC */
    {/* Index 84 */ 5, CNA_BEHAVIOR_NONE, 436, 31, 47, 0, 150, 1}, /* ACHumidifierReq_VR */
    {/* Index 85 */ 5, CNA_BEHAVIOR_NONE, 438, 31, 47, 0, 151, 1}, /* ACOzoneReq_TC */
    {/* Index 86 */ 5, CNA_BEHAVIOR_NONE, 439, 31, 47, 0, 152, 1}, /* ACOzoneReq_VR */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 429, 31, 47, 1, 153, 1}, /* ACRLTempDecReq_TC */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 430, 31, 48, 1, 154, 1}, /* ACRLTempIncReq_TC */
    {/* Index 89 */ 5, CNA_BEHAVIOR_SEND, 431, 31, 49, 1, 155, 1}, /* ACRLTempReq_VR */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 432, 31, 50, 1, 156, 1}, /* ACRRTempDecReq_TC */
    {/* Index 91 */ 5, CNA_BEHAVIOR_SEND, 433, 31, 51, 1, 157, 1}, /* ACRRTempIncReq_TC */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 434, 31, 52, 1, 158, 1}, /* ACRRTempReq_VR */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 435, 31, 53, 1, 159, 1}, /* ACRRTempSteplsReq_TC */
    {/* Index 94 */ 5, CNA_BEHAVIOR_NONE, 451, 31, 54, 0, 160, 1}, /* ACRearLockReq_VR */
    {/* Index 95 */ 5, CNA_BEHAVIOR_SEND, 440, 31, 54, 1, 161, 1}, /* ACUltravioletReq_TC */
    {/* Index 96 */ 5, CNA_BEHAVIOR_SEND, 441, 31, 55, 1, 162, 1}, /* ACUltravioletReq_VR */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 444, 31, 56, 1, 163, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 98 */ 5, CNA_BEHAVIOR_SEND, 448, 31, 57, 1, 164, 1}, /* FootALCMFlashFreq */
    {/* Index 99 */ 5, CNA_BEHAVIOR_SEND, 446, 31, 58, 1, 165, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 100 */ 5, CNA_BEHAVIOR_SEND, 449, 31, 59, 1, 166, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 101 */ 5, CNA_BEHAVIOR_SEND, 445, 31, 60, 1, 167, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 102 */ 5, CNA_BEHAVIOR_SEND, 447, 31, 61, 1, 168, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 450, 31, 62, 1, 169, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 322, 23, 63, 1, 170, 1}, /* BackReq_AVM */
    {/* Index 105 */ 5, CNA_BEHAVIOR_SEND, 320, 23, 64, 1, 171, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 106 */ 5, CNA_BEHAVIOR_SEND, 319, 23, 65, 1, 172, 1}, /* HUD_HeightLvlSwt */
    {/* Index 107 */ 5, CNA_BEHAVIOR_SEND, 321, 23, 66, 1, 173, 1}, /* HUD_SwtReq */
    {/* Index 108 */ 5, CNA_BEHAVIOR_UNSEND, 324, 23, 67, 1, 174, 1}, /* PPMIBSRSwtSet */
    {/* Index 109 */ 5, CNA_BEHAVIOR_UNSEND, 326, 23, 68, 1, 175, 1}, /* PPMIBSR_SwtSet */
    {/* Index 110 */ 5, CNA_BEHAVIOR_UNSEND, 323, 23, 69, 1, 176, 1}, /* PPMIHWSwtSet */
    {/* Index 111 */ 5, CNA_BEHAVIOR_UNSEND, 325, 23, 70, 1, 177, 1}, /* PPMIHW_SwtSet */
    {/* Index 112 */ 5, CNA_BEHAVIOR_NONE, 453, 32, 71, 0, 178, 1}, /* ActvEntryLockSet */
    {/* Index 113 */ 5, CNA_BEHAVIOR_NONE, 454, 32, 71, 0, 179, 1}, /* ActvEntryUnlockSet */
    {/* Index 114 */ 5, CNA_BEHAVIOR_NONE, 456, 32, 71, 0, 180, 1}, /* BTAPAEntryLockSet */
    {/* Index 115 */ 5, CNA_BEHAVIOR_NONE, 457, 32, 71, 0, 181, 1}, /* BTAPALvngUnlockSet */
    {/* Index 116 */ 5, CNA_BEHAVIOR_NONE, 458, 32, 71, 0, 182, 1}, /* ClsWinSpdSet */
    {/* Index 117 */ 5, CNA_BEHAVIOR_SEND, 464, 32, 71, 1, 183, 1}, /* DrvDoorALCMClrSet */
    {/* Index 118 */ 5, CNA_BEHAVIOR_NONE, 467, 32, 72, 0, 184, 1}, /* DrvDoorALCMSwt */
    {/* Index 119 */ 5, CNA_BEHAVIOR_SEND, 459, 32, 72, 1, 185, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 120 */ 5, CNA_BEHAVIOR_SEND, 466, 32, 73, 1, 186, 1}, /* LRDoorALCMClrSet */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 455, 32, 74, 0, 187, 1}, /* LockPromptFunSet */
    {/* Index 122 */ 5, CNA_BEHAVIOR_SEND, 465, 32, 74, 1, 188, 1}, /* PassDoorALCMClrSet */
    {/* Index 123 */ 5, CNA_BEHAVIOR_NONE, 468, 32, 75, 0, 189, 1}, /* PassDoorALCMSwt */
    {/* Index 124 */ 5, CNA_BEHAVIOR_SEND, 460, 32, 75, 1, 190, 1}, /* PassSeatMassgLvlSet */
    {/* Index 125 */ 5, CNA_BEHAVIOR_SEND, 462, 32, 76, 1, 191, 1}, /* RLSeatMassgLvlSet */
    {/* Index 126 */ 5, CNA_BEHAVIOR_SEND, 463, 32, 77, 1, 192, 1}, /* RRSeatMassgLvlSet */
    {/* Index 127 */ 5, CNA_BEHAVIOR_NONE, 461, 32, 78, 0, 193, 1}, /* SeatKeyMemEna */
    {/* Index 128 */ 5, CNA_BEHAVIOR_NONE, 421, 30, 78, 0, 194, 1}, /* MultiColorNr10 */
    {/* Index 129 */ 5, CNA_BEHAVIOR_NONE, 422, 30, 78, 0, 195, 1}, /* MultiColorNr11 */
    {/* Index 130 */ 5, CNA_BEHAVIOR_NONE, 423, 30, 78, 0, 196, 1}, /* MultiColorNr12 */
    {/* Index 131 */ 5, CNA_BEHAVIOR_NONE, 424, 30, 78, 0, 197, 1}, /* MultiColorNr13 */
    {/* Index 132 */ 5, CNA_BEHAVIOR_NONE, 425, 30, 78, 0, 198, 1}, /* MultiColorNr14 */
    {/* Index 133 */ 5, CNA_BEHAVIOR_NONE, 426, 30, 78, 0, 199, 1}, /* MultiColorNr15 */
    {/* Index 134 */ 5, CNA_BEHAVIOR_NONE, 427, 30, 78, 0, 200, 1}, /* MultiColorNr16 */
    {/* Index 135 */ 5, CNA_BEHAVIOR_NONE, 420, 30, 78, 0, 201, 1}, /* MultiColorNr9 */
    {/* Index 136 */ 5, CNA_BEHAVIOR_SEND, 377, 26, 78, 1, 202, 1}, /* ACFGAChanTyp_TC */
    {/* Index 137 */ 5, CNA_BEHAVIOR_SEND, 376, 26, 79, 1, 203, 1}, /* ACFGAEnaReq_TC */
    {/* Index 138 */ 5, CNA_BEHAVIOR_SEND, 378, 26, 80, 1, 204, 1}, /* ACFGALvlReq_TC */
    {/* Index 139 */ 6, CNA_BEHAVIOR_NONE, 354, 26, 81, 0, 205, 1}, /* ADASDispSwt */
    {/* Index 140 */ 6, CNA_BEHAVIOR_NONE, 357, 26, 81, 0, 206, 1}, /* ADASDispSwt_VR */
    {/* Index 141 */ 6, CNA_BEHAVIOR_NONE, 360, 26, 81, 0, 207, 1}, /* ALCMDynModSet */
    {/* Index 142 */ 6, CNA_BEHAVIOR_UNSEND, 358, 26, 81, 1, 208, 1}, /* ApproachLampSet */
    {/* Index 143 */ 5, CNA_BEHAVIOR_SEND, 375, 26, 82, 1, 209, 1}, /* BackReq_APS */
    {/* Index 144 */ 6, CNA_BEHAVIOR_SEND, 365, 26, 83, 1, 210, 1}, /* ChairMemPosnSetSwt */
    {/* Index 145 */ 5, CNA_BEHAVIOR_SEND, 372, 26, 84, 1, 211, 1}, /* DeletePath1Cmd */
    {/* Index 146 */ 5, CNA_BEHAVIOR_SEND, 370, 26, 85, 1, 212, 1}, /* DeletePath2Cmd */
    {/* Index 147 */ 6, CNA_BEHAVIOR_SEND, 363, 26, 86, 1, 213, 1}, /* DrvWinSwtReq_VR */
    {/* Index 148 */ 6, CNA_BEHAVIOR_UNSEND, 352, 26, 87, 1, 214, 1}, /* FlaoutUnlockSet */
    {/* Index 149 */ 6, CNA_BEHAVIOR_NONE, 355, 26, 88, 0, 215, 1}, /* NaviDispSwt */
    {/* Index 150 */ 6, CNA_BEHAVIOR_NONE, 356, 26, 88, 0, 216, 1}, /* NaviDispSwt_VR */
    {/* Index 151 */ 5, CNA_BEHAVIOR_SEND, 379, 26, 88, 1, 217, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 152 */ 5, CNA_BEHAVIOR_SEND, 374, 26, 89, 1, 218, 1}, /* ParkMdlCmd */
    {/* Index 153 */ 6, CNA_BEHAVIOR_SEND, 364, 26, 90, 1, 219, 1}, /* PassWinSwtReq_VR */
    {/* Index 154 */ 5, CNA_BEHAVIOR_SEND, 366, 26, 91, 1, 220, 1}, /* PathLrngFinshCmd */
    {/* Index 155 */ 5, CNA_BEHAVIOR_SEND, 367, 26, 92, 1, 221, 1}, /* PathLrngStartCmd */
    {/* Index 156 */ 6, CNA_BEHAVIOR_NONE, 353, 26, 93, 0, 222, 1}, /* PrkInDirChoice */
    {/* Index 157 */ 6, CNA_BEHAVIOR_SEND, 361, 26, 93, 1, 223, 1}, /* RLWinSwtReq_VR */
    {/* Index 158 */ 6, CNA_BEHAVIOR_SEND, 362, 26, 94, 1, 224, 1}, /* RRWinSwtReq_VR */
    {/* Index 159 */ 5, CNA_BEHAVIOR_SEND, 368, 26, 95, 1, 225, 1}, /* SelPrkOutDirReq */
    {/* Index 160 */ 5, CNA_BEHAVIOR_SEND, 373, 26, 96, 1, 226, 1}, /* SelPrkgFctnCmd */
    {/* Index 161 */ 5, CNA_BEHAVIOR_SEND, 371, 26, 97, 1, 227, 1}, /* StartPrkgPath1Cmd */
    {/* Index 162 */ 5, CNA_BEHAVIOR_SEND, 369, 26, 98, 1, 228, 1}, /* StartPrkgPath2Cmd */
    {/* Index 163 */ 6, CNA_BEHAVIOR_UNSEND, 359, 26, 99, 1, 229, 1}, /* SuperLockSet */
    {/* Index 164 */ 5, CNA_BEHAVIOR_NONE, 198, 12, 100, 0, 230, 1}, /* ABSLmpSet */
    {/* Index 165 */ 5, CNA_BEHAVIOR_SEND, 192, 12, 100, 1, 231, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 166 */ 5, CNA_BEHAVIOR_SEND, 190, 12, 101, 1, 232, 1}, /* ACOperMod_TC */
    {/* Index 167 */ 5, CNA_BEHAVIOR_SEND, 191, 12, 102, 1, 233, 1}, /* ACOperMod_VR */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 193, 12, 103, 1, 234, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 169 */ 5, CNA_BEHAVIOR_SEND, 196, 12, 104, 1, 235, 1}, /* APSPrkgTypSeln */
    {/* Index 170 */ 5, CNA_BEHAVIOR_SEND, 195, 12, 105, 1, 236, 1}, /* APSSwtReq_VR */
    {/* Index 171 */ 5, CNA_BEHAVIOR_NONE, 199, 12, 106, 0, 237, 1}, /* AutoWshWipSet */
    {/* Index 172 */ 5, CNA_BEHAVIOR_NONE, 203, 12, 106, 0, 238, 1}, /* DoorUnlockModSet */
    {/* Index 173 */ 5, CNA_BEHAVIOR_NONE, 189, 12, 106, 0, 239, 1}, /* FrntRearACDispSts */
    {/* Index 174 */ 5, CNA_BEHAVIOR_SEND, 205, 12, 106, 1, 240, 1}, /* PASExitSpdSwt */
    {/* Index 175 */ 5, CNA_BEHAVIOR_NONE, 202, 12, 107, 0, 241, 1}, /* ParkLmpSet */
    {/* Index 176 */ 5, CNA_BEHAVIOR_SEND, 194, 12, 107, 1, 242, 1}, /* SDWSwtSet */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 200, 12, 108, 0, 243, 1}, /* SeekVehSet */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 201, 12, 108, 0, 244, 1}, /* SpdAutoLockModSet */
    {/* Index 179 */ 5, CNA_BEHAVIOR_NONE, 197, 12, 108, 0, 245, 1}, /* SportModLightSet */
    {/* Index 180 */ 5, CNA_BEHAVIOR_SEND, 204, 12, 108, 1, 246, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 181 */ 5, CNA_BEHAVIOR_SEND, 188, 12, 109, 1, 247, 1}, /* SunRoofSwtReq_VR */
    {/* Index 182 */ 5, CNA_BEHAVIOR_SEND, 187, 12, 110, 1, 248, 1}, /* SunShadeSwtReq_VR */
    {/* Index 183 */ 5, CNA_BEHAVIOR_SEND, 500, 35, 111, 1, 249, 1}, /* ACRLTempSteplsReq_TC */
    {/* Index 184 */ 5, CNA_BEHAVIOR_NONE, 492, 34, 112, 0, 250, 1}, /* ALCMBreSwt */
    {/* Index 185 */ 5, CNA_BEHAVIOR_NONE, 491, 34, 112, 0, 251, 1}, /* ALCMFloSwt */
    {/* Index 186 */ 5, CNA_BEHAVIOR_SEND, 484, 34, 112, 1, 252, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 187 */ 5, CNA_BEHAVIOR_SEND, 483, 34, 113, 1, 253, 1}, /* FootALCMClrSet */
    {/* Index 188 */ 5, CNA_BEHAVIOR_SEND, 490, 34, 114, 1, 254, 1}, /* FootALCMLightLvlSet */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 496, 34, 115, 0, 255, 1}, /* FootALCMSwt */
    {/* Index 190 */ 5, CNA_BEHAVIOR_SEND, 486, 34, 115, 1, 256, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 494, 34, 116, 0, 257, 1}, /* LRDoorALCMSwt */
    {/* Index 192 */ 5, CNA_BEHAVIOR_SEND, 481, 34, 116, 1, 258, 1}, /* LeftPanelALCMClrSet */
    {/* Index 193 */ 5, CNA_BEHAVIOR_SEND, 488, 34, 117, 1, 259, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 194 */ 5, CNA_BEHAVIOR_NONE, 498, 34, 118, 0, 260, 1}, /* LeftPanelALCMSwt */
    {/* Index 195 */ 5, CNA_BEHAVIOR_SEND, 485, 34, 118, 1, 261, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 196 */ 5, CNA_BEHAVIOR_SEND, 480, 34, 119, 1, 262, 1}, /* RRDoorALCMClrSet */
    {/* Index 197 */ 5, CNA_BEHAVIOR_SEND, 487, 34, 120, 1, 263, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 198 */ 5, CNA_BEHAVIOR_NONE, 495, 34, 121, 0, 264, 1}, /* RRDoorALCMSwt */
    {/* Index 199 */ 5, CNA_BEHAVIOR_SEND, 482, 34, 121, 1, 265, 1}, /* RightPanelALCMClrSet */
    {/* Index 200 */ 5, CNA_BEHAVIOR_SEND, 489, 34, 122, 1, 266, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 201 */ 5, CNA_BEHAVIOR_NONE, 493, 34, 123, 0, 267, 1}, /* RightPanelALCMSwt */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 497, 34, 123, 0, 268, 1}, /* RoofALCMSwt */
    {/* Index 203 */ 5, CNA_BEHAVIOR_SEND, 504, 36, 123, 1, 269, 1}, /* DrvSeatHeatgLvlSet_Nine */
    {/* Index 204 */ 5, CNA_BEHAVIOR_SEND, 505, 36, 124, 1, 270, 1}, /* PassSeatHeatgLvlSet_Nine */
    {/* Index 205 */ 5, CNA_BEHAVIOR_SEND, 506, 36, 125, 1, 271, 1}, /* RLSeatHeatgLvlSet_Nine */
    {/* Index 206 */ 5, CNA_BEHAVIOR_SEND, 502, 36, 126, 1, 272, 1}, /* RLSeatMassgModSet */
    {/* Index 207 */ 5, CNA_BEHAVIOR_SEND, 507, 36, 127, 1, 273, 1}, /* RRSeatHeatgLvlSet_Nine */
    {/* Index 208 */ 5, CNA_BEHAVIOR_SEND, 503, 36, 128, 1, 274, 1}, /* RRSeatMassgModSet */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 296, 19, 129, 0, 275, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 129, 0, 276, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 297, 19, 129, 0, 277, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 294, 19, 129, 0, 278, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 299, 19, 129, 0, 279, 1}, /* ADAS_Stub_LastStub */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 129, 0, 280, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 302, 19, 129, 0, 281, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 301, 19, 129, 0, 282, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 129, 0, 283, 2}, /* ADAS_Stub_Offset */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 295, 19, 129, 0, 285, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 129, 0, 286, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 129, 0, 287, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 129, 0, 288, 1}, /* ADAS_Stub_Retr */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 300, 19, 129, 0, 289, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 129, 0, 290, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 298, 19, 129, 0, 291, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 129, 0, 292, 1}, /* ADAS_Stub_Update */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 129, 0, 293, 1}, /* ADAS_Seg_Brdg */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 129, 0, 294, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 278, 18, 129, 0, 295, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 129, 0, 296, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 282, 18, 129, 0, 297, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 280, 18, 129, 0, 298, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 281, 18, 129, 0, 299, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 279, 18, 129, 0, 300, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 276, 18, 129, 0, 301, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 129, 0, 302, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 284, 18, 129, 0, 303, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 283, 18, 129, 0, 304, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 129, 0, 305, 2}, /* ADAS_Seg_Offset */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 277, 18, 129, 0, 307, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 240 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 129, 0, 308, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 241 */ 5, CNA_BEHAVIOR_NONE, 275, 18, 129, 0, 309, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 242 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 129, 0, 310, 1}, /* ADAS_Seg_Retr */
    {/* Index 243 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 129, 0, 311, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 244 */ 5, CNA_BEHAVIOR_NONE, 274, 18, 129, 0, 312, 1}, /* ADAS_Seg_Update */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 261, 17, 129, 0, 313, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 258, 17, 129, 0, 314, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 129, 0, 315, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 262, 17, 129, 0, 316, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 129, 0, 318, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 250 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 129, 0, 319, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 256, 17, 129, 0, 321, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 257, 17, 129, 0, 322, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 253 */ 5, CNA_BEHAVIOR_NONE, 259, 17, 129, 0, 323, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 260, 17, 129, 0, 324, 1}, /* ADAS_ProfShort_Update */
    {/* Index 255 */ 5, CNA_BEHAVIOR_NONE, 263, 17, 129, 0, 325, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 256 */ 5, CNA_BEHAVIOR_NONE, 264, 17, 129, 0, 327, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 248, 16, 129, 0, 329, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 258 */ 5, CNA_BEHAVIOR_NONE, 245, 16, 129, 0, 330, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 259 */ 5, CNA_BEHAVIOR_NONE, 243, 16, 129, 0, 331, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 244, 16, 129, 0, 332, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 246, 16, 129, 0, 334, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 247, 16, 129, 0, 335, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 249, 16, 129, 0, 336, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 250, 16, 129, 0, 337, 1}, /* ADAS_ProfLong_Update */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 251, 16, 129, 0, 338, 4}, /* ADAS_ProfLong_Value */
    {/* Index 266 */ 5, CNA_BEHAVIOR_SEND, 163, 9, 129, 1, 342, 1}, /* ACAIUReq_VR */
    {/* Index 267 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 130, 1, 343, 1}, /* ACAQSReq_VR */
    {/* Index 268 */ 5, CNA_BEHAVIOR_SEND, 159, 9, 131, 1, 344, 1}, /* ACDualReq_VR */
    {/* Index 269 */ 5, CNA_BEHAVIOR_SEND, 162, 9, 132, 1, 345, 1}, /* ACPassTempReq_VR */
    {/* Index 270 */ 5, CNA_BEHAVIOR_SEND, 161, 9, 133, 1, 346, 1}, /* ACRearDefrstReq_VR */
    {/* Index 271 */ 5, CNA_BEHAVIOR_NONE, 166, 9, 134, 0, 347, 1}, /* ALCMClrSet */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 165, 9, 134, 0, 348, 1}, /* ALCMDynSwt */
    {/* Index 273 */ 5, CNA_BEHAVIOR_NONE, 167, 9, 134, 0, 349, 1}, /* ALCMRhmSwt */
    {/* Index 274 */ 5, CNA_BEHAVIOR_NONE, 164, 9, 134, 0, 350, 1}, /* ALCMStatSwt */
    {/* Index 275 */ 3, CNA_BEHAVIOR_SEND, 170, 9, 134, 1, 351, 1}, /* HUT_BeanIDReq */
    {/* Index 276 */ 5, CNA_BEHAVIOR_UNSEND, 171, 9, 135, 1, 352, 1}, /* HUT_EgyRecvrySet */
    {/* Index 277 */ 5, CNA_BEHAVIOR_NONE, 168, 9, 136, 0, 353, 1}, /* IPVolSet */
    {/* Index 278 */ 5, CNA_BEHAVIOR_SEND, 169, 9, 136, 1, 354, 1}, /* PASSwtReq_VR */
    {/* Index 279 */ 5, CNA_BEHAVIOR_SEND, 305, 20, 137, 1, 355, 1}, /* ACDrvSetTempReq_ETC_VR */
    {/* Index 280 */ 5, CNA_BEHAVIOR_SEND, 306, 20, 138, 1, 356, 1}, /* ACDrvSetTempSteplsReq_ETC_TC */
    {/* Index 281 */ 5, CNA_BEHAVIOR_UNSEND, 308, 20, 139, 1, 357, 1}, /* HUT_BattKeepTemp */
    {/* Index 282 */ 5, CNA_BEHAVIOR_SEND, 311, 20, 140, 1, 358, 1}, /* HUT_BattSOCLim */
    {/* Index 283 */ 5, CNA_BEHAVIOR_UNSEND, 307, 20, 141, 1, 359, 1}, /* HUT_ChrgnMode */
    {/* Index 284 */ 5, CNA_BEHAVIOR_NONE, 310, 20, 142, 0, 360, 1}, /* HUT_IntelBattTempMagSet */
    {/* Index 285 */ 5, CNA_BEHAVIOR_NONE, 309, 20, 142, 0, 361, 1}, /* HUT_IntelEngIdlChrgnSet */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 304, 20, 142, 1, 362, 1}, /* HUT_RemtEngCtrl */
    {/* Index 287 */ 5, CNA_BEHAVIOR_SEND, 225, 14, 143, 1, 363, 1}, /* ACRearAirDistribModReq_VR */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 222, 14, 144, 1, 364, 1}, /* ACRearBlwrSpdReq_VR */
    {/* Index 289 */ 5, CNA_BEHAVIOR_SEND, 223, 14, 145, 1, 365, 1}, /* ACRearBlwrsteplsSpdReq_TC */
    {/* Index 290 */ 5, CNA_BEHAVIOR_SEND, 226, 14, 146, 1, 366, 1}, /* ACZoneReq_VR */
    {/* Index 291 */ 5, CNA_BEHAVIOR_NONE, 219, 14, 147, 0, 367, 1}, /* AVMMediaVolLvlReq */
    {/* Index 292 */ 5, CNA_BEHAVIOR_NONE, 217, 14, 147, 0, 368, 1}, /* AVMSwtReq */
    {/* Index 293 */ 5, CNA_BEHAVIOR_SEND, 213, 14, 147, 1, 369, 1}, /* BackgroundLightLvlSet */
    {/* Index 294 */ 5, CNA_BEHAVIOR_NONE, 215, 14, 148, 0, 370, 1}, /* DispModSet */
    {/* Index 295 */ 5, CNA_BEHAVIOR_NONE, 220, 14, 148, 0, 371, 1}, /* FPASChanSwtReq */
    {/* Index 296 */ 5, CNA_BEHAVIOR_NONE, 214, 14, 148, 0, 372, 1}, /* ManCmpSet */
    {/* Index 297 */ 5, CNA_BEHAVIOR_NONE, 218, 14, 148, 0, 373, 1}, /* NaviMediaVolLvlReq */
    {/* Index 298 */ 5, CNA_BEHAVIOR_UNSEND, 227, 14, 148, 1, 374, 1}, /* OPDSwtSts */
    {/* Index 299 */ 5, CNA_BEHAVIOR_UNSEND, 224, 14, 149, 1, 375, 1}, /* PLGReq_VR */
    {/* Index 300 */ 5, CNA_BEHAVIOR_NONE, 221, 14, 150, 0, 376, 1}, /* RPASChanSwtReq */
    {/* Index 301 */ 5, CNA_BEHAVIOR_UNSEND, 216, 14, 150, 1, 377, 1}, /* WPC_SwtReq */
    {/* Index 302 */ 5, CNA_BEHAVIOR_SEND, 68, 3, 151, 1, 378, 1}, /* ACAIUReq_TC */
    {/* Index 303 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 152, 1, 379, 1}, /* ACAQSReq_TC */
    {/* Index 304 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 153, 1, 380, 1}, /* ACAirInletReq_TC */
    {/* Index 305 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 154, 1, 381, 1}, /* ACAutoModReq_TC */
    {/* Index 306 */ 5, CNA_BEHAVIOR_SEND, 70, 3, 155, 1, 382, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 307 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 156, 1, 383, 1}, /* ACCmprReq_TC */
    {/* Index 308 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 157, 1, 384, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 309 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 158, 1, 385, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 310 */ 5, CNA_BEHAVIOR_SEND, 65, 3, 159, 1, 386, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 311 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 160, 1, 387, 1}, /* ACDualReq_TC */
    {/* Index 312 */ 5, CNA_BEHAVIOR_SEND, 57, 3, 161, 1, 388, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 313 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 162, 1, 389, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 314 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 163, 1, 390, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 315 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 164, 1, 391, 1}, /* ACFrntHMIDis_TC */
    {/* Index 316 */ 5, CNA_BEHAVIOR_SEND, 66, 3, 165, 1, 392, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 317 */ 5, CNA_BEHAVIOR_SEND, 67, 3, 166, 1, 393, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 318 */ 5, CNA_BEHAVIOR_SEND, 69, 3, 167, 1, 394, 1}, /* ACOffReq_TC */
    {/* Index 319 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 168, 1, 395, 1}, /* ACRearBlwrSpdDecReq_TC */
    {/* Index 320 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 169, 1, 396, 1}, /* ACRearBlwrSpdIncReq_TC */
    {/* Index 321 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 170, 1, 397, 1}, /* ACRearHMIDis_TC */
    {/* Index 322 */ 5, CNA_BEHAVIOR_SEND, 71, 3, 171, 1, 398, 1}, /* ACZoneReq_TC */
    {/* Index 323 */ 5, CNA_BEHAVIOR_NONE, 48, 3, 172, 0, 399, 1}, /* BattSaveDelayTimeSet */
    {/* Index 324 */ 5, CNA_BEHAVIOR_NONE, 64, 3, 172, 0, 400, 1}, /* ChairMemPosnEna */
    {/* Index 325 */ 5, CNA_BEHAVIOR_NONE, 44, 3, 172, 0, 401, 1}, /* DomeLmpDlyTimSet */
    {/* Index 326 */ 5, CNA_BEHAVIOR_NONE, 60, 3, 172, 0, 402, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 327 */ 5, CNA_BEHAVIOR_NONE, 45, 3, 172, 0, 403, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 328 */ 5, CNA_BEHAVIOR_NONE, 47, 3, 172, 0, 404, 1}, /* RearviewFoldModSet */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 172, 0, 405, 1}, /* TranPMode_Req */
    {/* Index 330 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 172, 0, 406, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 331 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 172, 0, 407, 1}, /* AMP_BeepSourceSet */
    {/* Index 332 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 172, 0, 408, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 333 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 172, 0, 409, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 334 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 172, 0, 410, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 335 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 172, 0, 411, 1}, /* AMP_LRDrvSideSet */
    {/* Index 336 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 172, 0, 412, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 337 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 172, 0, 413, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 338 */ 5, CNA_BEHAVIOR_NONE, 83, 4, 172, 0, 414, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 339 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 172, 0, 415, 1}, /* AMP_MuteSet */
    {/* Index 340 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 172, 0, 416, 1}, /* AMP_NaviSourceSet */
    {/* Index 341 */ 5, CNA_BEHAVIOR_NONE, 87, 4, 172, 0, 417, 1}, /* ANCSwtSet */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 88, 4, 172, 0, 418, 1}, /* FrntWinHeatSwt */
    {/* Index 343 */ 5, CNA_BEHAVIOR_NONE, 86, 4, 172, 0, 419, 1}, /* QLISurroundSet */
    {/* Index 344 */ 5, CNA_BEHAVIOR_SEND, 73, 4, 172, 1, 420, 1}, /* RearWinHeatCmd_TC */
    {/* Index 345 */ 5, CNA_BEHAVIOR_NONE, 85, 4, 173, 0, 421, 1}, /* T_box_ECallSet */
    {/* Index 346 */ 5, CNA_BEHAVIOR_NONE, 101, 5, 173, 0, 422, 1}, /* AMP_BestListegPosnReq */
    {/* Index 347 */ 5, CNA_BEHAVIOR_NONE, 102, 5, 173, 0, 423, 1}, /* AMP_Clari_FiReq */
    {/* Index 348 */ 5, CNA_BEHAVIOR_SEND, 98, 5, 173, 1, 424, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 349 */ 5, CNA_BEHAVIOR_SEND, 95, 5, 174, 1, 425, 1}, /* AMP_GetHWInfoReq */
    {/* Index 350 */ 5, CNA_BEHAVIOR_SEND, 97, 5, 175, 1, 426, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 351 */ 5, CNA_BEHAVIOR_SEND, 94, 5, 176, 1, 427, 1}, /* AMP_GetSWInfoReq */
    {/* Index 352 */ 5, CNA_BEHAVIOR_SEND, 96, 5, 177, 1, 428, 1}, /* AMP_GetTempInfoReq */
    {/* Index 353 */ 5, CNA_BEHAVIOR_NONE, 90, 5, 178, 0, 429, 1}, /* AMP_HFMVolSet */
    {/* Index 354 */ 5, CNA_BEHAVIOR_NONE, 93, 5, 178, 0, 430, 1}, /* AMP_MainVolSet */
    {/* Index 355 */ 5, CNA_BEHAVIOR_NONE, 92, 5, 178, 0, 431, 1}, /* AMP_NaviVolSet */
    {/* Index 356 */ 5, CNA_BEHAVIOR_NONE, 91, 5, 178, 0, 432, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 357 */ 5, CNA_BEHAVIOR_NONE, 100, 5, 178, 0, 433, 1}, /* IESS_MdlInfoReq */
    {/* Index 358 */ 5, CNA_BEHAVIOR_NONE, 99, 5, 178, 0, 434, 1}, /* IESS_MdlSwtReq */
    {/* Index 359 */ 5, CNA_BEHAVIOR_SEND, 113, 6, 178, 1, 435, 1}, /* ACAirInletReq_VR */
    {/* Index 360 */ 5, CNA_BEHAVIOR_SEND, 106, 6, 179, 1, 436, 1}, /* ACAutoModReq_VR */
    {/* Index 361 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 180, 1, 437, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 362 */ 5, CNA_BEHAVIOR_SEND, 107, 6, 181, 1, 438, 1}, /* ACCmprReq_VR */
    {/* Index 363 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 182, 1, 439, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 364 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 183, 1, 440, 1}, /* ACDrvTempReq_VR */
    {/* Index 365 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 184, 1, 441, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 366 */ 5, CNA_BEHAVIOR_NONE, 114, 6, 185, 0, 442, 1}, /* ACModReq_HUT */
    {/* Index 367 */ 5, CNA_BEHAVIOR_SEND, 108, 6, 185, 1, 443, 1}, /* ACPowerReq_VR */
    {/* Index 368 */ 5, CNA_BEHAVIOR_SEND, 123, 6, 186, 1, 444, 1}, /* ACRearAirDistribModReq_TC */
    {/* Index 369 */ 5, CNA_BEHAVIOR_SEND, 119, 6, 187, 1, 445, 1}, /* ACRearAutoModReq_TC */
    {/* Index 370 */ 5, CNA_BEHAVIOR_SEND, 122, 6, 188, 1, 446, 1}, /* ACRearOffReq_TC */
    {/* Index 371 */ 5, CNA_BEHAVIOR_NONE, 117, 6, 189, 0, 447, 1}, /* AllTerrainDislSet */
    {/* Index 372 */ 5, CNA_BEHAVIOR_NONE, 126, 6, 189, 0, 448, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 373 */ 5, CNA_BEHAVIOR_NONE, 120, 6, 189, 0, 449, 1}, /* DrvSeatSupportLvlSet */
    {/* Index 374 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 189, 0, 450, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 375 */ 5, CNA_BEHAVIOR_NONE, 115, 6, 189, 0, 451, 1}, /* ElecSideSteppingSysSet */
    {/* Index 376 */ 5, CNA_BEHAVIOR_NONE, 127, 6, 189, 0, 452, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 377 */ 5, CNA_BEHAVIOR_NONE, 121, 6, 189, 0, 453, 1}, /* PassSeatSupportLvlSet */
    {/* Index 378 */ 5, CNA_BEHAVIOR_NONE, 105, 6, 189, 0, 454, 1}, /* PassSeatVentnLvlSet */
    {/* Index 379 */ 5, CNA_BEHAVIOR_NONE, 124, 6, 189, 0, 455, 1}, /* RLSeatVentnLvlSet */
    {/* Index 380 */ 5, CNA_BEHAVIOR_NONE, 125, 6, 189, 0, 456, 1}, /* RRSeatVentnLvlSet */
    {/* Index 381 */ 5, CNA_BEHAVIOR_SEND, 118, 6, 189, 1, 457, 1}, /* RemUpgrdSts */
    {/* Index 382 */ 5, CNA_BEHAVIOR_NONE, 116, 6, 190, 0, 458, 1}, /* RoofModSet */
    {/* Index 383 */ 5, CNA_BEHAVIOR_CYCLE, 338, 25, 190, 1, 459, 1}, /* ContnPrkgReq */
    {/* Index 384 */ 5, CNA_BEHAVIOR_CYCLE, 336, 25, 191, 1, 460, 1}, /* PrkgCtrlModReq */
    {/* Index 385 */ 5, CNA_BEHAVIOR_CYCLE, 574, 40, 192, 1, 461, 1}, /* ChairMemPosnSet */
    {/* Index 386 */ 5, CNA_BEHAVIOR_CYCLE, 549, 40, 193, 1, 462, 1}, /* EPSSteerModSwtReq */
    {/* Index 387 */ 5, CNA_BEHAVIOR_CYCLE, 610, 40, 194, 1, 463, 1}, /* HUT_DrvModReq */
    {/* Index 388 */ 5, CNA_BEHAVIOR_CYCLE, 608, 40, 195, 1, 464, 1}, /* HUT_HybModReq */
    {/* Index 389 */ 5, CNA_BEHAVIOR_CYCLE, 554, 40, 196, 1, 465, 1}, /* OilLvlDispReq */
    {/* Index 390 */ 5, CNA_BEHAVIOR_CYCLE, 184, 11, 197, 1, 466, 1}, /* DampgDrvModeReq */
    {/* Index 391 */ 5, CNA_BEHAVIOR_CYCLE, 182, 11, 198, 1, 467, 1}, /* DrivingModReq_VR */
    {/* Index 392 */ 5, CNA_BEHAVIOR_CYCLE, 179, 11, 199, 1, 468, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = {0u};
static const uint8 cna_noActionBuffer[200] =
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
    0u,
    0u,
    0u,
    0u,
    0u,
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

static const ComEx_SignalIdType CNA_IdTable[735] =
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
    325,
    327,
    329,
    328,
    323,
    311,
    305,
    304,
    315,
    321,
    303,
    307,
    314,
    312,
    319,
    320,
    326,
    313,
    308,
    309,
    324,
    310,
    316,
    317,
    302,
    318,
    306,
    322,
    65535,
    344,
    337,
    340,
    331,
    334,
    330,
    332,
    335,
    336,
    339,
    338,
    333,
    345,
    343,
    341,
    342,
    65535,
    353,
    356,
    355,
    354,
    351,
    349,
    352,
    350,
    348,
    358,
    357,
    346,
    347,
    65535,
    374,
    378,
    360,
    362,
    367,
    361,
    364,
    365,
    363,
    359,
    366,
    375,
    382,
    371,
    381,
    369,
    373,
    377,
    370,
    368,
    379,
    380,
    372,
    376,
    65535,
    11,
    12,
    19,
    21,
    23,
    18,
    24,
    25,
    14,
    22,
    16,
    15,
    13,
    17,
    20,
    27,
    26,
    65535,
    6,
    1,
    2,
    3,
    5,
    0,
    4,
    10,
    8,
    7,
    9,
    65535,
    268,
    267,
    270,
    269,
    266,
    274,
    272,
    271,
    273,
    277,
    278,
    275,
    276,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    392,
    65535,
    65535,
    391,
    65535,
    390,
    65535,
    65535,
    182,
    181,
    173,
    166,
    167,
    165,
    168,
    176,
    170,
    169,
    179,
    164,
    171,
    177,
    178,
    175,
    172,
    180,
    174,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    293,
    296,
    294,
    301,
    292,
    297,
    291,
    295,
    300,
    288,
    289,
    299,
    287,
    290,
    298,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    259,
    260,
    258,
    261,
    262,
    257,
    263,
    264,
    265,
    65535,
    249,
    250,
    247,
    251,
    252,
    246,
    253,
    254,
    245,
    248,
    255,
    256,
    65535,
    235,
    238,
    229,
    240,
    243,
    226,
    227,
    242,
    244,
    241,
    234,
    239,
    228,
    233,
    231,
    232,
    230,
    237,
    236,
    65535,
    214,
    217,
    210,
    219,
    223,
    221,
    225,
    220,
    212,
    218,
    209,
    211,
    224,
    213,
    222,
    216,
    215,
    65535,
    286,
    279,
    280,
    283,
    281,
    285,
    284,
    282,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    106,
    105,
    107,
    104,
    110,
    108,
    111,
    109,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    384,
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
    148,
    156,
    139,
    149,
    150,
    140,
    142,
    163,
    141,
    157,
    158,
    147,
    153,
    144,
    154,
    155,
    159,
    162,
    146,
    161,
    145,
    160,
    152,
    143,
    137,
    136,
    138,
    151,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    64,
    65,
    55,
    56,
    62,
    63,
    61,
    58,
    57,
    68,
    59,
    69,
    60,
    72,
    67,
    66,
    71,
    70,
    65535,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    65535,
    135,
    128,
    129,
    130,
    131,
    132,
    133,
    134,
    65535,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    84,
    83,
    85,
    86,
    95,
    96,
    81,
    82,
    97,
    101,
    99,
    102,
    98,
    100,
    103,
    94,
    65535,
    112,
    113,
    121,
    114,
    115,
    116,
    119,
    124,
    127,
    125,
    126,
    117,
    122,
    120,
    118,
    123,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    196,
    192,
    199,
    187,
    186,
    195,
    190,
    197,
    193,
    200,
    188,
    185,
    184,
    201,
    191,
    198,
    189,
    202,
    194,
    65535,
    183,
    65535,
    206,
    208,
    203,
    204,
    205,
    207,
    65535,
    45,
    43,
    44,
    46,
    65535,
    50,
    51,
    52,
    53,
    48,
    49,
    47,
    54,
    65535,
    28,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    386,
    65535,
    65535,
    65535,
    65535,
    389,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    385,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    388,
    65535,
    387,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    39,
    41,
    37,
    36,
    29,
    40,
    35,
    34,
    30,
    32,
    31,
    33,
    38,
    65535,
    42,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[469] = {0};

const CNA_ConfigType cna_config =
{
    SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER,
    cna_signalConfigs,
    cna_signalDatas,
    200u,
    cna_noActionBuffer,
    469u,
    cna_currentBuffer,
    735u,
    CNA_IdTable
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
