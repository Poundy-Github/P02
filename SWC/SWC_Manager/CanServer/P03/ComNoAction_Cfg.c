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

#ifndef SWC_IPC_CAN_MATRIX_P03H
#include "SWC_IPC_CANMatrix_P03.h"
#if (0x5ea5b7ef != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
     #error " Noaction version dismatch!!! "
#endif
#endif

#define Can_Server_START_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



static const CNA_SignalConfigType cna_signalConfigs[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 149, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 145, 8, 0, 0, 1, 1}, /* ALCMClrSet_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_NONE, 146, 8, 0, 0, 2, 1}, /* ALCMDynModSet_OLE */
    {/* Index 3 */ 5, CNA_BEHAVIOR_NONE, 147, 8, 0, 0, 3, 1}, /* ALCMLightLvlSet_OLE */
    {/* Index 4 */ 5, CNA_BEHAVIOR_NONE, 150, 8, 0, 0, 4, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 5 */ 5, CNA_BEHAVIOR_NONE, 148, 8, 0, 0, 5, 1}, /* ALCMRhmSwt_OLE */
    {/* Index 6 */ 5, CNA_BEHAVIOR_NONE, 144, 8, 0, 0, 6, 1}, /* ALCMStatSwt_OLE */
    {/* Index 7 */ 5, CNA_BEHAVIOR_NONE, 154, 8, 0, 0, 7, 1}, /* ChairMemPosnEna_Pass */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 155, 8, 0, 1, 8, 1}, /* ChairMemPosnSetSwt_Pass */
    {/* Index 9 */ 5, CNA_BEHAVIOR_UNSEND, 153, 8, 1, 1, 9, 1}, /* ChairRestSetSwt */
    {/* Index 10 */ 5, CNA_BEHAVIOR_NONE, 152, 8, 2, 0, 10, 1}, /* ChildLockCmd */
    {/* Index 11 */ 5, CNA_BEHAVIOR_NONE, 151, 8, 2, 0, 11, 1}, /* Rdm_SingleColorNr */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 126, 7, 2, 1, 12, 1}, /* AUTODefrost_TC */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 127, 7, 3, 1, 13, 1}, /* AUTODefrost_VR */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 138, 7, 4, 1, 14, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 5, 1, 15, 1}, /* AutoViewChgCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 137, 7, 6, 1, 16, 1}, /* CarMdlDispCmd */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 136, 7, 7, 1, 17, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 139, 7, 8, 1, 18, 1}, /* FPAS_AutoModSwt */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 9, 1, 19, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 128, 7, 10, 1, 20, 1}, /* LaneCalActvtCmd */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 140, 7, 11, 1, 21, 1}, /* MEBSwtSet */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 12, 1, 22, 1}, /* MODChgReq */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 135, 7, 13, 1, 23, 1}, /* MdlColrChgCmd */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 14, 1, 24, 1}, /* Radar_DispCmd */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 15, 1, 25, 1}, /* Sgl_View_Sel */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 16, 1, 26, 1}, /* SwToFieldCalRstCmd */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 142, 7, 17, 1, 27, 1}, /* View_SoftswitchCmd */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 141, 7, 18, 1, 28, 1}, /* WshSoftSwt */
    {/* Index 29 */ 5, CNA_BEHAVIOR_SEND, 694, 43, 19, 1, 29, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 30 */ 5, CNA_BEHAVIOR_SEND, 686, 43, 20, 1, 30, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 31 */ 5, CNA_BEHAVIOR_NONE, 692, 43, 21, 0, 31, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 32 */ 5, CNA_BEHAVIOR_NONE, 691, 43, 21, 0, 32, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 33 */ 5, CNA_BEHAVIOR_NONE, 693, 43, 21, 0, 33, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 34 */ 5, CNA_BEHAVIOR_SEND, 689, 43, 21, 1, 34, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 687, 43, 22, 1, 35, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 36 */ 5, CNA_BEHAVIOR_SEND, 690, 43, 23, 1, 36, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 37 */ 5, CNA_BEHAVIOR_SEND, 688, 43, 24, 1, 37, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 38 */ 5, CNA_BEHAVIOR_NONE, 695, 43, 25, 0, 38, 1}, /* HUT_PAVP_PathList_Req */
    {/* Index 39 */ 5, CNA_BEHAVIOR_SEND, 685, 43, 25, 1, 39, 1}, /* SlotNum_VR */
    {/* Index 40 */ 5, CNA_BEHAVIOR_SEND, 684, 43, 26, 1, 40, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 683, 43, 27, 1, 41, 1}, /* UserDefinedParkCmd */
    {/* Index 42 */ 5, CNA_BEHAVIOR_NONE, 697, 44, 28, 0, 42, 64}, /* HUT_ExternalDevice */
    {/* Index 43 */ 5, CNA_BEHAVIOR_UNSEND, 510, 38, 28, 1, 106, 1}, /* ApprLightSwt */
    {/* Index 44 */ 5, CNA_BEHAVIOR_SEND, 507, 38, 29, 1, 107, 1}, /* DrvSeatMassgModSet */
    {/* Index 45 */ 5, CNA_BEHAVIOR_UNSEND, 508, 38, 30, 1, 108, 1}, /* PPMI_P_BSR_SwtSet */
    {/* Index 46 */ 5, CNA_BEHAVIOR_SEND, 506, 38, 31, 1, 109, 1}, /* PassSeatMassgModSet */
    {/* Index 47 */ 5, CNA_BEHAVIOR_UNSEND, 509, 38, 32, 1, 110, 1}, /* RWPC_SwtReq */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 518, 39, 33, 0, 111, 1}, /* AGSSwtReq */
    {/* Index 49 */ 5, CNA_BEHAVIOR_NONE, 516, 39, 33, 0, 112, 1}, /* ARFSwtReq */
    {/* Index 50 */ 5, CNA_BEHAVIOR_NONE, 517, 39, 33, 0, 113, 1}, /* ASFCSwtReq */
    {/* Index 51 */ 5, CNA_BEHAVIOR_SEND, 512, 39, 33, 1, 114, 1}, /* DrvSeatVentnLvlSet_Nine */
    {/* Index 52 */ 5, CNA_BEHAVIOR_SEND, 513, 39, 34, 1, 115, 1}, /* PassSeatVentnLvlSet_Nine */
    {/* Index 53 */ 5, CNA_BEHAVIOR_SEND, 514, 39, 35, 1, 116, 1}, /* RLSeatVentnLvlSet_Nine */
    {/* Index 54 */ 5, CNA_BEHAVIOR_SEND, 515, 39, 36, 1, 117, 1}, /* RRSeatVentnLvlSet_Nine */
    {/* Index 55 */ 5, CNA_BEHAVIOR_NONE, 519, 39, 37, 0, 118, 1}, /* SOCMngmntSwtReq */
    {/* Index 56 */ 5, CNA_BEHAVIOR_NONE, 392, 29, 37, 0, 119, 1}, /* ACDrvTempDecReq_ETC_TC */
    {/* Index 57 */ 5, CNA_BEHAVIOR_NONE, 393, 29, 37, 0, 120, 1}, /* ACDrvTempIncReq_ETC_TC */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 398, 29, 37, 1, 121, 1}, /* ACMaxReq_TC */
    {/* Index 59 */ 5, CNA_BEHAVIOR_SEND, 397, 29, 38, 1, 122, 1}, /* ACMaxReq_VR */
    {/* Index 60 */ 5, CNA_BEHAVIOR_SEND, 400, 29, 39, 1, 123, 1}, /* ACRearAutoModReq_VR */
    {/* Index 61 */ 5, CNA_BEHAVIOR_SEND, 402, 29, 40, 1, 124, 1}, /* ACRearLockReq_TC */
    {/* Index 62 */ 5, CNA_BEHAVIOR_SEND, 396, 29, 41, 1, 125, 1}, /* ACRearPowerReq_VR */
    {/* Index 63 */ 5, CNA_BEHAVIOR_NONE, 394, 29, 42, 0, 126, 1}, /* ACRearTempDecReq_ETC_TC */
    {/* Index 64 */ 5, CNA_BEHAVIOR_NONE, 395, 29, 42, 0, 127, 1}, /* ACRearTempIncReq_ETC_TC */
    {/* Index 65 */ 5, CNA_BEHAVIOR_NONE, 390, 29, 42, 0, 128, 1}, /* ACRearTempReq_ETC_VR */
    {/* Index 66 */ 5, CNA_BEHAVIOR_NONE, 391, 29, 42, 0, 129, 1}, /* ACRearTempSteplsReq_ETC_TC */
    {/* Index 67 */ 5, CNA_BEHAVIOR_NONE, 405, 29, 42, 0, 130, 1}, /* ColorCategory */
    {/* Index 68 */ 5, CNA_BEHAVIOR_NONE, 404, 29, 42, 1, 131, 1}, /* DPF_Request */
    {/* Index 69 */ 5, CNA_BEHAVIOR_NONE, 399, 29, 43, 0, 132, 1}, /* FrntWiprCtrl_VR */
    {/* Index 70 */ 5, CNA_BEHAVIOR_NONE, 401, 29, 43, 0, 133, 1}, /* LockWinSet */
    {/* Index 71 */ 5, CNA_BEHAVIOR_NONE, 406, 29, 43, 0, 134, 1}, /* SingleColorNr */
    {/* Index 72 */ 5, CNA_BEHAVIOR_NONE, 403, 29, 43, 0, 135, 1}, /* SrSpdCtrlSwt */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 408, 30, 43, 0, 136, 1}, /* MultiColorNr1 */
    {/* Index 74 */ 5, CNA_BEHAVIOR_NONE, 409, 30, 43, 0, 137, 1}, /* MultiColorNr2 */
    {/* Index 75 */ 5, CNA_BEHAVIOR_NONE, 410, 30, 43, 0, 138, 1}, /* MultiColorNr3 */
    {/* Index 76 */ 5, CNA_BEHAVIOR_NONE, 411, 30, 43, 0, 139, 1}, /* MultiColorNr4 */
    {/* Index 77 */ 5, CNA_BEHAVIOR_NONE, 412, 30, 43, 0, 140, 1}, /* MultiColorNr5 */
    {/* Index 78 */ 5, CNA_BEHAVIOR_NONE, 413, 30, 43, 0, 141, 1}, /* MultiColorNr6 */
    {/* Index 79 */ 5, CNA_BEHAVIOR_NONE, 414, 30, 43, 0, 142, 1}, /* MultiColorNr7 */
    {/* Index 80 */ 5, CNA_BEHAVIOR_NONE, 415, 30, 43, 0, 143, 1}, /* MultiColorNr8 */
    {/* Index 81 */ 5, CNA_BEHAVIOR_NONE, 439, 32, 43, 0, 144, 1}, /* ACFrntWinHeatCmd_TC */
    {/* Index 82 */ 5, CNA_BEHAVIOR_NONE, 440, 32, 43, 0, 145, 1}, /* ACFrntWinHeatCmd_VR */
    {/* Index 83 */ 5, CNA_BEHAVIOR_NONE, 434, 32, 43, 0, 146, 1}, /* ACHumidifierReq_TC */
    {/* Index 84 */ 5, CNA_BEHAVIOR_NONE, 433, 32, 43, 0, 147, 1}, /* ACHumidifierReq_VR */
    {/* Index 85 */ 5, CNA_BEHAVIOR_NONE, 435, 32, 43, 0, 148, 1}, /* ACOzoneReq_TC */
    {/* Index 86 */ 5, CNA_BEHAVIOR_NONE, 436, 32, 43, 0, 149, 1}, /* ACOzoneReq_VR */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 426, 32, 43, 1, 150, 1}, /* ACRLTempDecReq_TC */
    {/* Index 88 */ 5, CNA_BEHAVIOR_SEND, 427, 32, 44, 1, 151, 1}, /* ACRLTempIncReq_TC */
    {/* Index 89 */ 5, CNA_BEHAVIOR_SEND, 428, 32, 45, 1, 152, 1}, /* ACRLTempReq_VR */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 429, 32, 46, 1, 153, 1}, /* ACRRTempDecReq_TC */
    {/* Index 91 */ 5, CNA_BEHAVIOR_SEND, 430, 32, 47, 1, 154, 1}, /* ACRRTempIncReq_TC */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 431, 32, 48, 1, 155, 1}, /* ACRRTempReq_VR */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 432, 32, 49, 1, 156, 1}, /* ACRRTempSteplsReq_TC */
    {/* Index 94 */ 5, CNA_BEHAVIOR_NONE, 437, 32, 50, 0, 157, 1}, /* ACUltravioletReq_TC */
    {/* Index 95 */ 5, CNA_BEHAVIOR_SEND, 438, 32, 50, 1, 158, 1}, /* ACUltravioletReq_VR */
    {/* Index 96 */ 5, CNA_BEHAVIOR_SEND, 441, 32, 51, 1, 159, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 445, 32, 52, 1, 160, 1}, /* FootALCMFlashFreq */
    {/* Index 98 */ 5, CNA_BEHAVIOR_SEND, 443, 32, 53, 1, 161, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 99 */ 5, CNA_BEHAVIOR_SEND, 446, 32, 54, 1, 162, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 100 */ 5, CNA_BEHAVIOR_SEND, 442, 32, 55, 1, 163, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 101 */ 5, CNA_BEHAVIOR_SEND, 444, 32, 56, 1, 164, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 102 */ 5, CNA_BEHAVIOR_SEND, 447, 32, 57, 1, 165, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 322, 24, 58, 1, 166, 1}, /* BackReq_AVM */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 320, 24, 59, 1, 167, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 105 */ 5, CNA_BEHAVIOR_SEND, 319, 24, 60, 1, 168, 1}, /* HUD_HeightLvlSwt */
    {/* Index 106 */ 5, CNA_BEHAVIOR_SEND, 321, 24, 61, 1, 169, 1}, /* HUD_SwtReq */
    {/* Index 107 */ 5, CNA_BEHAVIOR_UNSEND, 324, 24, 62, 1, 170, 1}, /* PPMIBSRSwtSet */
    {/* Index 108 */ 5, CNA_BEHAVIOR_UNSEND, 323, 24, 63, 1, 171, 1}, /* PPMIHWSwtSet */
    {/* Index 109 */ 5, CNA_BEHAVIOR_NONE, 449, 33, 64, 0, 172, 1}, /* ActvEntryLockSet */
    {/* Index 110 */ 5, CNA_BEHAVIOR_NONE, 450, 33, 64, 0, 173, 1}, /* ActvEntryUnlockSet */
    {/* Index 111 */ 5, CNA_BEHAVIOR_NONE, 451, 33, 64, 0, 174, 1}, /* BTAPAEntryLockSet */
    {/* Index 112 */ 5, CNA_BEHAVIOR_NONE, 452, 33, 64, 0, 175, 1}, /* BTAPALvngUnlockSet */
    {/* Index 113 */ 5, CNA_BEHAVIOR_NONE, 453, 33, 64, 0, 176, 1}, /* ClsWinSpdSet */
    {/* Index 114 */ 5, CNA_BEHAVIOR_SEND, 459, 33, 64, 1, 177, 1}, /* DrvDoorALCMClrSet */
    {/* Index 115 */ 5, CNA_BEHAVIOR_NONE, 462, 33, 65, 0, 178, 1}, /* DrvDoorALCMSwt */
    {/* Index 116 */ 5, CNA_BEHAVIOR_SEND, 454, 33, 65, 1, 179, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 117 */ 5, CNA_BEHAVIOR_SEND, 461, 33, 66, 1, 180, 1}, /* LRDoorALCMClrSet */
    {/* Index 118 */ 5, CNA_BEHAVIOR_NONE, 464, 33, 67, 0, 181, 1}, /* LockPromptFunSet */
    {/* Index 119 */ 5, CNA_BEHAVIOR_NONE, 465, 33, 67, 0, 182, 1}, /* OilBoxSplyReq */
    {/* Index 120 */ 5, CNA_BEHAVIOR_SEND, 460, 33, 67, 1, 183, 1}, /* PassDoorALCMClrSet */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 463, 33, 68, 0, 184, 1}, /* PassDoorALCMSwt */
    {/* Index 122 */ 5, CNA_BEHAVIOR_SEND, 455, 33, 68, 1, 185, 1}, /* PassSeatMassgLvlSet */
    {/* Index 123 */ 5, CNA_BEHAVIOR_SEND, 457, 33, 69, 1, 186, 1}, /* RLSeatMassgLvlSet */
    {/* Index 124 */ 5, CNA_BEHAVIOR_SEND, 458, 33, 70, 1, 187, 1}, /* RRSeatMassgLvlSet */
    {/* Index 125 */ 5, CNA_BEHAVIOR_NONE, 456, 33, 71, 0, 188, 1}, /* SeatKeyMemEna */
    {/* Index 126 */ 5, CNA_BEHAVIOR_NONE, 418, 31, 71, 0, 189, 1}, /* MultiColorNr10 */
    {/* Index 127 */ 5, CNA_BEHAVIOR_NONE, 419, 31, 71, 0, 190, 1}, /* MultiColorNr11 */
    {/* Index 128 */ 5, CNA_BEHAVIOR_NONE, 420, 31, 71, 0, 191, 1}, /* MultiColorNr12 */
    {/* Index 129 */ 5, CNA_BEHAVIOR_NONE, 421, 31, 71, 0, 192, 1}, /* MultiColorNr13 */
    {/* Index 130 */ 5, CNA_BEHAVIOR_NONE, 422, 31, 71, 0, 193, 1}, /* MultiColorNr14 */
    {/* Index 131 */ 5, CNA_BEHAVIOR_NONE, 423, 31, 71, 0, 194, 1}, /* MultiColorNr15 */
    {/* Index 132 */ 5, CNA_BEHAVIOR_NONE, 424, 31, 71, 0, 195, 1}, /* MultiColorNr16 */
    {/* Index 133 */ 5, CNA_BEHAVIOR_NONE, 417, 31, 71, 0, 196, 1}, /* MultiColorNr9 */
    {/* Index 134 */ 5, CNA_BEHAVIOR_SEND, 374, 27, 71, 1, 197, 1}, /* ACFGAChanTyp_TC */
    {/* Index 135 */ 5, CNA_BEHAVIOR_SEND, 373, 27, 72, 1, 198, 1}, /* ACFGAEnaReq_TC */
    {/* Index 136 */ 5, CNA_BEHAVIOR_SEND, 375, 27, 73, 1, 199, 1}, /* ACFGALvlReq_TC */
    {/* Index 137 */ 6, CNA_BEHAVIOR_NONE, 351, 27, 74, 0, 200, 1}, /* ADASDispSwt */
    {/* Index 138 */ 6, CNA_BEHAVIOR_NONE, 354, 27, 74, 0, 201, 1}, /* ADASDispSwt_VR */
    {/* Index 139 */ 6, CNA_BEHAVIOR_NONE, 357, 27, 74, 0, 202, 1}, /* ALCMDynModSet */
    {/* Index 140 */ 6, CNA_BEHAVIOR_UNSEND, 355, 27, 74, 1, 203, 1}, /* ApproachLampSet */
    {/* Index 141 */ 5, CNA_BEHAVIOR_SEND, 372, 27, 75, 1, 204, 1}, /* BackReq_APS */
    {/* Index 142 */ 6, CNA_BEHAVIOR_SEND, 362, 27, 76, 1, 205, 1}, /* ChairMemPosnSetSwt */
    {/* Index 143 */ 5, CNA_BEHAVIOR_SEND, 369, 27, 77, 1, 206, 1}, /* DeletePath1Cmd */
    {/* Index 144 */ 5, CNA_BEHAVIOR_SEND, 367, 27, 78, 1, 207, 1}, /* DeletePath2Cmd */
    {/* Index 145 */ 6, CNA_BEHAVIOR_SEND, 360, 27, 79, 1, 208, 1}, /* DrvWinSwtReq_VR */
    {/* Index 146 */ 6, CNA_BEHAVIOR_UNSEND, 349, 27, 80, 1, 209, 1}, /* FlaoutUnlockSet */
    {/* Index 147 */ 6, CNA_BEHAVIOR_NONE, 352, 27, 81, 0, 210, 1}, /* NaviDispSwt */
    {/* Index 148 */ 6, CNA_BEHAVIOR_NONE, 353, 27, 81, 0, 211, 1}, /* NaviDispSwt_VR */
    {/* Index 149 */ 5, CNA_BEHAVIOR_SEND, 376, 27, 81, 1, 212, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 150 */ 5, CNA_BEHAVIOR_SEND, 371, 27, 82, 1, 213, 1}, /* ParkMdlCmd */
    {/* Index 151 */ 6, CNA_BEHAVIOR_SEND, 361, 27, 83, 1, 214, 1}, /* PassWinSwtReq_VR */
    {/* Index 152 */ 5, CNA_BEHAVIOR_SEND, 363, 27, 84, 1, 215, 1}, /* PathLrngFinshCmd */
    {/* Index 153 */ 5, CNA_BEHAVIOR_SEND, 364, 27, 85, 1, 216, 1}, /* PathLrngStartCmd */
    {/* Index 154 */ 6, CNA_BEHAVIOR_NONE, 350, 27, 86, 0, 217, 1}, /* PrkInDirChoice */
    {/* Index 155 */ 6, CNA_BEHAVIOR_SEND, 358, 27, 86, 1, 218, 1}, /* RLWinSwtReq_VR */
    {/* Index 156 */ 6, CNA_BEHAVIOR_SEND, 359, 27, 87, 1, 219, 1}, /* RRWinSwtReq_VR */
    {/* Index 157 */ 5, CNA_BEHAVIOR_SEND, 365, 27, 88, 1, 220, 1}, /* SelPrkOutDirReq */
    {/* Index 158 */ 5, CNA_BEHAVIOR_SEND, 370, 27, 89, 1, 221, 1}, /* SelPrkgFctnCmd */
    {/* Index 159 */ 5, CNA_BEHAVIOR_SEND, 368, 27, 90, 1, 222, 1}, /* StartPrkgPath1Cmd */
    {/* Index 160 */ 5, CNA_BEHAVIOR_SEND, 366, 27, 91, 1, 223, 1}, /* StartPrkgPath2Cmd */
    {/* Index 161 */ 6, CNA_BEHAVIOR_UNSEND, 356, 27, 92, 1, 224, 1}, /* SuperLockSet */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 193, 12, 93, 0, 225, 1}, /* ABSLmpSet */
    {/* Index 163 */ 5, CNA_BEHAVIOR_SEND, 187, 12, 93, 1, 226, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 164 */ 5, CNA_BEHAVIOR_SEND, 185, 12, 94, 1, 227, 1}, /* ACOperMod_TC */
    {/* Index 165 */ 5, CNA_BEHAVIOR_SEND, 186, 12, 95, 1, 228, 1}, /* ACOperMod_VR */
    {/* Index 166 */ 5, CNA_BEHAVIOR_SEND, 188, 12, 96, 1, 229, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 167 */ 5, CNA_BEHAVIOR_SEND, 191, 12, 97, 1, 230, 1}, /* APSPrkgTypSeln */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 190, 12, 98, 1, 231, 1}, /* APSSwtReq_VR */
    {/* Index 169 */ 5, CNA_BEHAVIOR_NONE, 194, 12, 99, 0, 232, 1}, /* AutoWshWipSet */
    {/* Index 170 */ 5, CNA_BEHAVIOR_NONE, 198, 12, 99, 0, 233, 1}, /* DoorUnlockModSet */
    {/* Index 171 */ 5, CNA_BEHAVIOR_NONE, 203, 12, 99, 0, 234, 1}, /* FrntRearACDispSts */
    {/* Index 172 */ 5, CNA_BEHAVIOR_SEND, 200, 12, 99, 1, 235, 1}, /* PASExitSpdSwt */
    {/* Index 173 */ 5, CNA_BEHAVIOR_NONE, 197, 12, 100, 0, 236, 1}, /* ParkLmpSet */
    {/* Index 174 */ 5, CNA_BEHAVIOR_SEND, 189, 12, 100, 1, 237, 1}, /* SDWSwtSet */
    {/* Index 175 */ 5, CNA_BEHAVIOR_NONE, 195, 12, 101, 0, 238, 1}, /* SeekVehSet */
    {/* Index 176 */ 5, CNA_BEHAVIOR_NONE, 196, 12, 101, 0, 239, 1}, /* SpdAutoLockModSet */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 192, 12, 101, 0, 240, 1}, /* SportModLightSet */
    {/* Index 178 */ 5, CNA_BEHAVIOR_SEND, 199, 12, 101, 1, 241, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 179 */ 5, CNA_BEHAVIOR_SEND, 202, 12, 102, 1, 242, 1}, /* SunRoofSwtReq_VR */
    {/* Index 180 */ 5, CNA_BEHAVIOR_SEND, 201, 12, 103, 1, 243, 1}, /* SunShadeSwtReq_VR */
    {/* Index 181 */ 5, CNA_BEHAVIOR_SEND, 497, 36, 104, 1, 244, 1}, /* ACRLTempSteplsReq_TC */
    {/* Index 182 */ 5, CNA_BEHAVIOR_NONE, 489, 35, 105, 0, 245, 1}, /* ALCMBreSwt */
    {/* Index 183 */ 5, CNA_BEHAVIOR_NONE, 488, 35, 105, 0, 246, 1}, /* ALCMFloSwt */
    {/* Index 184 */ 5, CNA_BEHAVIOR_SEND, 481, 35, 105, 1, 247, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 185 */ 5, CNA_BEHAVIOR_SEND, 480, 35, 106, 1, 248, 1}, /* FootALCMClrSet */
    {/* Index 186 */ 5, CNA_BEHAVIOR_SEND, 487, 35, 107, 1, 249, 1}, /* FootALCMLightLvlSet */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 494, 35, 108, 0, 250, 1}, /* FootALCMSwt */
    {/* Index 188 */ 5, CNA_BEHAVIOR_SEND, 483, 35, 108, 1, 251, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 492, 35, 109, 0, 252, 1}, /* LRDoorALCMSwt */
    {/* Index 190 */ 5, CNA_BEHAVIOR_SEND, 478, 35, 109, 1, 253, 1}, /* LeftPanelALCMClrSet */
    {/* Index 191 */ 5, CNA_BEHAVIOR_SEND, 485, 35, 110, 1, 254, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 192 */ 5, CNA_BEHAVIOR_NONE, 490, 35, 111, 0, 255, 1}, /* LeftPanelALCMSwt */
    {/* Index 193 */ 5, CNA_BEHAVIOR_SEND, 482, 35, 111, 1, 256, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 194 */ 5, CNA_BEHAVIOR_SEND, 477, 35, 112, 1, 257, 1}, /* RRDoorALCMClrSet */
    {/* Index 195 */ 5, CNA_BEHAVIOR_SEND, 484, 35, 113, 1, 258, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 196 */ 5, CNA_BEHAVIOR_NONE, 493, 35, 114, 0, 259, 1}, /* RRDoorALCMSwt */
    {/* Index 197 */ 5, CNA_BEHAVIOR_SEND, 479, 35, 114, 1, 260, 1}, /* RightPanelALCMClrSet */
    {/* Index 198 */ 5, CNA_BEHAVIOR_SEND, 486, 35, 115, 1, 261, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 491, 35, 116, 0, 262, 1}, /* RightPanelALCMSwt */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 495, 35, 116, 0, 263, 1}, /* RoofALCMSwt */
    {/* Index 201 */ 5, CNA_BEHAVIOR_SEND, 501, 37, 116, 1, 264, 1}, /* DrvSeatHeatgLvlSet_Nine */
    {/* Index 202 */ 5, CNA_BEHAVIOR_SEND, 502, 37, 117, 1, 265, 1}, /* PassSeatHeatgLvlSet_Nine */
    {/* Index 203 */ 5, CNA_BEHAVIOR_SEND, 503, 37, 118, 1, 266, 1}, /* RLSeatHeatgLvlSet_Nine */
    {/* Index 204 */ 5, CNA_BEHAVIOR_SEND, 499, 37, 119, 1, 267, 1}, /* RLSeatMassgModSet */
    {/* Index 205 */ 5, CNA_BEHAVIOR_SEND, 504, 37, 120, 1, 268, 1}, /* RRSeatHeatgLvlSet_Nine */
    {/* Index 206 */ 5, CNA_BEHAVIOR_SEND, 500, 37, 121, 1, 269, 1}, /* RRSeatMassgModSet */
    {/* Index 207 */ 5, CNA_BEHAVIOR_NONE, 294, 19, 122, 0, 270, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 122, 0, 271, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 295, 19, 122, 0, 272, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 122, 0, 273, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 297, 19, 122, 0, 274, 1}, /* ADAS_Stub_LastStub */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 284, 19, 122, 0, 275, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 300, 19, 122, 0, 276, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 299, 19, 122, 0, 277, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 122, 0, 278, 2}, /* ADAS_Stub_Offset */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 122, 0, 280, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 122, 0, 281, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 122, 0, 282, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 122, 0, 283, 1}, /* ADAS_Stub_Retr */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 298, 19, 122, 0, 284, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 122, 0, 285, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 296, 19, 122, 0, 286, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 122, 0, 287, 1}, /* ADAS_Stub_Update */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 122, 0, 288, 1}, /* ADAS_Seg_Brdg */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 122, 0, 289, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 276, 18, 122, 0, 290, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 122, 0, 291, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 280, 18, 122, 0, 292, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 278, 18, 122, 0, 293, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 279, 18, 122, 0, 294, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 277, 18, 122, 0, 295, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 274, 18, 122, 0, 296, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 264, 18, 122, 0, 297, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 282, 18, 122, 0, 298, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 281, 18, 122, 0, 299, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 122, 0, 300, 2}, /* ADAS_Seg_Offset */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 275, 18, 122, 0, 302, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 122, 0, 303, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 122, 0, 304, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 240 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 122, 0, 305, 1}, /* ADAS_Seg_Retr */
    {/* Index 241 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 122, 0, 306, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 242 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 122, 0, 307, 1}, /* ADAS_Seg_Update */
    {/* Index 243 */ 5, CNA_BEHAVIOR_NONE, 259, 17, 122, 0, 308, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 244 */ 5, CNA_BEHAVIOR_NONE, 256, 17, 122, 0, 309, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 122, 0, 310, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 260, 17, 122, 0, 311, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 251, 17, 122, 0, 313, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 122, 0, 314, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 249 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 122, 0, 316, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 250 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 122, 0, 317, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 257, 17, 122, 0, 318, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 258, 17, 122, 0, 319, 1}, /* ADAS_ProfShort_Update */
    {/* Index 253 */ 5, CNA_BEHAVIOR_NONE, 261, 17, 122, 0, 320, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 262, 17, 122, 0, 322, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 255 */ 5, CNA_BEHAVIOR_NONE, 246, 16, 122, 0, 324, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 256 */ 5, CNA_BEHAVIOR_NONE, 243, 16, 122, 0, 325, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 241, 16, 122, 0, 326, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 258 */ 5, CNA_BEHAVIOR_NONE, 242, 16, 122, 0, 327, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 259 */ 5, CNA_BEHAVIOR_NONE, 244, 16, 122, 0, 329, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 245, 16, 122, 0, 330, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 247, 16, 122, 0, 331, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 248, 16, 122, 0, 332, 1}, /* ADAS_ProfLong_Update */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 249, 16, 122, 0, 333, 4}, /* ADAS_ProfLong_Value */
    {/* Index 264 */ 5, CNA_BEHAVIOR_SEND, 161, 9, 122, 1, 337, 1}, /* ACAIUReq_VR */
    {/* Index 265 */ 5, CNA_BEHAVIOR_SEND, 158, 9, 123, 1, 338, 1}, /* ACAQSReq_VR */
    {/* Index 266 */ 5, CNA_BEHAVIOR_SEND, 157, 9, 124, 1, 339, 1}, /* ACDualReq_VR */
    {/* Index 267 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 125, 1, 340, 1}, /* ACPassTempReq_VR */
    {/* Index 268 */ 5, CNA_BEHAVIOR_SEND, 159, 9, 126, 1, 341, 1}, /* ACRearDefrstReq_VR */
    {/* Index 269 */ 5, CNA_BEHAVIOR_NONE, 164, 9, 127, 0, 342, 1}, /* ALCMClrSet */
    {/* Index 270 */ 5, CNA_BEHAVIOR_NONE, 163, 9, 127, 0, 343, 1}, /* ALCMDynSwt */
    {/* Index 271 */ 5, CNA_BEHAVIOR_NONE, 165, 9, 127, 0, 344, 1}, /* ALCMRhmSwt */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 162, 9, 127, 0, 345, 1}, /* ALCMStatSwt */
    {/* Index 273 */ 3, CNA_BEHAVIOR_SEND, 168, 9, 127, 1, 346, 1}, /* HUT_BeanIDReq */
    {/* Index 274 */ 5, CNA_BEHAVIOR_NONE, 169, 9, 128, 0, 347, 1}, /* HUT_EgyRecvrySet */
    {/* Index 275 */ 5, CNA_BEHAVIOR_NONE, 166, 9, 128, 0, 348, 1}, /* IPVolSet */
    {/* Index 276 */ 5, CNA_BEHAVIOR_SEND, 167, 9, 128, 1, 349, 1}, /* PASSwtReq_VR */
    {/* Index 277 */ 5, CNA_BEHAVIOR_SEND, 303, 20, 129, 1, 350, 1}, /* ACDrvSetTempReq_ETC_VR */
    {/* Index 278 */ 5, CNA_BEHAVIOR_SEND, 304, 20, 130, 1, 351, 1}, /* ACDrvSetTempSteplsReq_ETC_TC */
    {/* Index 279 */ 5, CNA_BEHAVIOR_NONE, 306, 20, 131, 0, 352, 1}, /* HUT_BattKeepTemp */
    {/* Index 280 */ 5, CNA_BEHAVIOR_SEND, 309, 20, 131, 1, 353, 1}, /* HUT_BattSOCLim */
    {/* Index 281 */ 5, CNA_BEHAVIOR_UNSEND, 305, 20, 132, 1, 354, 1}, /* HUT_ChrgnMode */
    {/* Index 282 */ 5, CNA_BEHAVIOR_NONE, 308, 20, 133, 0, 355, 1}, /* HUT_IntelBattTempMagSet */
    {/* Index 283 */ 5, CNA_BEHAVIOR_NONE, 307, 20, 133, 0, 356, 1}, /* HUT_IntelEngIdlChrgnSet */
    {/* Index 284 */ 5, CNA_BEHAVIOR_SEND, 302, 20, 133, 1, 357, 1}, /* HUT_RemtEngCtrl */
    {/* Index 285 */ 5, CNA_BEHAVIOR_SEND, 223, 14, 134, 1, 358, 1}, /* ACRearAirDistribModReq_VR */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 220, 14, 135, 1, 359, 1}, /* ACRearBlwrSpdReq_VR */
    {/* Index 287 */ 5, CNA_BEHAVIOR_SEND, 221, 14, 136, 1, 360, 1}, /* ACRearBlwrsteplsSpdReq_TC */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 224, 14, 137, 1, 361, 1}, /* ACZoneReq_VR */
    {/* Index 289 */ 5, CNA_BEHAVIOR_NONE, 217, 14, 138, 0, 362, 1}, /* AVMMediaVolLvlReq */
    {/* Index 290 */ 5, CNA_BEHAVIOR_NONE, 215, 14, 138, 0, 363, 1}, /* AVMSwtReq */
    {/* Index 291 */ 5, CNA_BEHAVIOR_SEND, 211, 14, 138, 1, 364, 1}, /* BackgroundLightLvlSet */
    {/* Index 292 */ 5, CNA_BEHAVIOR_NONE, 213, 14, 139, 0, 365, 1}, /* DispModSet */
    {/* Index 293 */ 5, CNA_BEHAVIOR_NONE, 218, 14, 139, 0, 366, 1}, /* FPASChanSwtReq */
    {/* Index 294 */ 5, CNA_BEHAVIOR_NONE, 212, 14, 139, 0, 367, 1}, /* ManCmpSet */
    {/* Index 295 */ 5, CNA_BEHAVIOR_NONE, 216, 14, 139, 0, 368, 1}, /* NaviMediaVolLvlReq */
    {/* Index 296 */ 5, CNA_BEHAVIOR_UNSEND, 225, 14, 139, 1, 369, 1}, /* OPDSwtSts */
    {/* Index 297 */ 5, CNA_BEHAVIOR_UNSEND, 222, 14, 140, 1, 370, 1}, /* PLGReq_VR */
    {/* Index 298 */ 5, CNA_BEHAVIOR_NONE, 219, 14, 141, 0, 371, 1}, /* RPASChanSwtReq */
    {/* Index 299 */ 5, CNA_BEHAVIOR_UNSEND, 214, 14, 141, 1, 372, 1}, /* WPC_SwtReq */
    {/* Index 300 */ 5, CNA_BEHAVIOR_SEND, 68, 3, 142, 1, 373, 1}, /* ACAIUReq_TC */
    {/* Index 301 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 143, 1, 374, 1}, /* ACAQSReq_TC */
    {/* Index 302 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 144, 1, 375, 1}, /* ACAirInletReq_TC */
    {/* Index 303 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 145, 1, 376, 1}, /* ACAutoModReq_TC */
    {/* Index 304 */ 5, CNA_BEHAVIOR_SEND, 70, 3, 146, 1, 377, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 305 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 147, 1, 378, 1}, /* ACCmprReq_TC */
    {/* Index 306 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 148, 1, 379, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 307 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 149, 1, 380, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 308 */ 5, CNA_BEHAVIOR_SEND, 65, 3, 150, 1, 381, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 309 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 151, 1, 382, 1}, /* ACDualReq_TC */
    {/* Index 310 */ 5, CNA_BEHAVIOR_SEND, 57, 3, 152, 1, 383, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 311 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 153, 1, 384, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 312 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 154, 1, 385, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 313 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 155, 1, 386, 1}, /* ACFrntHMIDis_TC */
    {/* Index 314 */ 5, CNA_BEHAVIOR_SEND, 66, 3, 156, 1, 387, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 315 */ 5, CNA_BEHAVIOR_SEND, 67, 3, 157, 1, 388, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 316 */ 5, CNA_BEHAVIOR_SEND, 69, 3, 158, 1, 389, 1}, /* ACOffReq_TC */
    {/* Index 317 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 159, 1, 390, 1}, /* ACRearBlwrSpdDecReq_TC */
    {/* Index 318 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 160, 1, 391, 1}, /* ACRearBlwrSpdIncReq_TC */
    {/* Index 319 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 161, 1, 392, 1}, /* ACRearHMIDis_TC */
    {/* Index 320 */ 5, CNA_BEHAVIOR_SEND, 71, 3, 162, 1, 393, 1}, /* ACZoneReq_TC */
    {/* Index 321 */ 5, CNA_BEHAVIOR_NONE, 48, 3, 163, 0, 394, 1}, /* BattSaveDelayTimeSet */
    {/* Index 322 */ 5, CNA_BEHAVIOR_NONE, 64, 3, 163, 0, 395, 1}, /* ChairMemPosnEna */
    {/* Index 323 */ 5, CNA_BEHAVIOR_NONE, 44, 3, 163, 0, 396, 1}, /* DomeLmpDlyTimSet */
    {/* Index 324 */ 5, CNA_BEHAVIOR_NONE, 60, 3, 163, 0, 397, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 325 */ 5, CNA_BEHAVIOR_NONE, 45, 3, 163, 0, 398, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 326 */ 5, CNA_BEHAVIOR_NONE, 47, 3, 163, 0, 399, 1}, /* RearviewFoldModSet */
    {/* Index 327 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 163, 0, 400, 1}, /* TranPMode_Req */
    {/* Index 328 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 163, 0, 401, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 163, 0, 402, 1}, /* AMP_BeepSourceSet */
    {/* Index 330 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 163, 0, 403, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 331 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 163, 0, 404, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 332 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 163, 0, 405, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 333 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 163, 0, 406, 1}, /* AMP_LRDrvSideSet */
    {/* Index 334 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 163, 0, 407, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 335 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 163, 0, 408, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 336 */ 5, CNA_BEHAVIOR_NONE, 83, 4, 163, 0, 409, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 337 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 163, 0, 410, 1}, /* AMP_MuteSet */
    {/* Index 338 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 163, 0, 411, 1}, /* AMP_NaviSourceSet */
    {/* Index 339 */ 5, CNA_BEHAVIOR_NONE, 87, 4, 163, 0, 412, 1}, /* ANCSwtSet */
    {/* Index 340 */ 5, CNA_BEHAVIOR_NONE, 86, 4, 163, 0, 413, 1}, /* QLISurroundSet */
    {/* Index 341 */ 5, CNA_BEHAVIOR_SEND, 73, 4, 163, 1, 414, 1}, /* RearWinHeatCmd_TC */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 85, 4, 164, 0, 415, 1}, /* T_box_ECallSet */
    {/* Index 343 */ 5, CNA_BEHAVIOR_NONE, 100, 5, 164, 0, 416, 1}, /* AMP_BestListegPosnReq */
    {/* Index 344 */ 5, CNA_BEHAVIOR_NONE, 101, 5, 164, 0, 417, 1}, /* AMP_Clari_FiReq */
    {/* Index 345 */ 5, CNA_BEHAVIOR_UNSEND, 97, 5, 164, 1, 418, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 346 */ 5, CNA_BEHAVIOR_UNSEND, 94, 5, 165, 1, 419, 1}, /* AMP_GetHWInfoReq */
    {/* Index 347 */ 5, CNA_BEHAVIOR_UNSEND, 96, 5, 166, 1, 420, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 348 */ 5, CNA_BEHAVIOR_UNSEND, 93, 5, 167, 1, 421, 1}, /* AMP_GetSWInfoReq */
    {/* Index 349 */ 5, CNA_BEHAVIOR_UNSEND, 95, 5, 168, 1, 422, 1}, /* AMP_GetTempInfoReq */
    {/* Index 350 */ 5, CNA_BEHAVIOR_NONE, 89, 5, 169, 0, 423, 1}, /* AMP_HFMVolSet */
    {/* Index 351 */ 5, CNA_BEHAVIOR_NONE, 92, 5, 169, 0, 424, 1}, /* AMP_MainVolSet */
    {/* Index 352 */ 5, CNA_BEHAVIOR_NONE, 91, 5, 169, 0, 425, 1}, /* AMP_NaviVolSet */
    {/* Index 353 */ 5, CNA_BEHAVIOR_NONE, 90, 5, 169, 0, 426, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 354 */ 5, CNA_BEHAVIOR_NONE, 99, 5, 169, 0, 427, 1}, /* IESS_MdlInfoReq */
    {/* Index 355 */ 5, CNA_BEHAVIOR_NONE, 98, 5, 169, 0, 428, 1}, /* IESS_MdlSwtReq */
    {/* Index 356 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 169, 1, 429, 1}, /* ACAirInletReq_VR */
    {/* Index 357 */ 5, CNA_BEHAVIOR_SEND, 105, 6, 170, 1, 430, 1}, /* ACAutoModReq_VR */
    {/* Index 358 */ 5, CNA_BEHAVIOR_SEND, 108, 6, 171, 1, 431, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 359 */ 5, CNA_BEHAVIOR_SEND, 106, 6, 172, 1, 432, 1}, /* ACCmprReq_VR */
    {/* Index 360 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 173, 1, 433, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 361 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 174, 1, 434, 1}, /* ACDrvTempReq_VR */
    {/* Index 362 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 175, 1, 435, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 363 */ 5, CNA_BEHAVIOR_NONE, 113, 6, 176, 0, 436, 1}, /* ACModReq_HUT */
    {/* Index 364 */ 5, CNA_BEHAVIOR_SEND, 107, 6, 176, 1, 437, 1}, /* ACPowerReq_VR */
    {/* Index 365 */ 5, CNA_BEHAVIOR_SEND, 122, 6, 177, 1, 438, 1}, /* ACRearAirDistribModReq_TC */
    {/* Index 366 */ 5, CNA_BEHAVIOR_SEND, 118, 6, 178, 1, 439, 1}, /* ACRearAutoModReq_TC */
    {/* Index 367 */ 5, CNA_BEHAVIOR_SEND, 121, 6, 179, 1, 440, 1}, /* ACRearOffReq_TC */
    {/* Index 368 */ 5, CNA_BEHAVIOR_NONE, 116, 6, 180, 0, 441, 1}, /* AllTerrainDislSet */
    {/* Index 369 */ 5, CNA_BEHAVIOR_NONE, 119, 6, 180, 0, 442, 1}, /* DrvSeatSupportLvlSet */
    {/* Index 370 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 180, 0, 443, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 371 */ 5, CNA_BEHAVIOR_NONE, 114, 6, 180, 0, 444, 1}, /* ElecSideSteppingSysSet */
    {/* Index 372 */ 5, CNA_BEHAVIOR_NONE, 120, 6, 180, 0, 445, 1}, /* PassSeatSupportLvlSet */
    {/* Index 373 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 180, 0, 446, 1}, /* PassSeatVentnLvlSet */
    {/* Index 374 */ 5, CNA_BEHAVIOR_NONE, 123, 6, 180, 0, 447, 1}, /* RLSeatVentnLvlSet */
    {/* Index 375 */ 5, CNA_BEHAVIOR_NONE, 124, 6, 180, 0, 448, 1}, /* RRSeatVentnLvlSet */
    {/* Index 376 */ 5, CNA_BEHAVIOR_NONE, 117, 6, 180, 0, 449, 1}, /* RemUpgrdSts */
    {/* Index 377 */ 5, CNA_BEHAVIOR_NONE, 115, 6, 180, 0, 450, 1}, /* RoofModSet */
    {/* Index 378 */ 5, CNA_BEHAVIOR_CYCLE, 336, 26, 180, 1, 451, 1}, /* ContnPrkgReq */
    {/* Index 379 */ 5, CNA_BEHAVIOR_CYCLE, 334, 26, 181, 1, 452, 1}, /* PrkgCtrlModReq */
    {/* Index 380 */ 5, CNA_BEHAVIOR_CYCLE, 317, 23, 182, 1, 453, 1}, /* BrkPedFeelSelect */
    {/* Index 381 */ 5, CNA_BEHAVIOR_CYCLE, 570, 40, 183, 1, 454, 1}, /* ChairMemPosnSet */
    {/* Index 382 */ 5, CNA_BEHAVIOR_CYCLE, 545, 40, 184, 1, 455, 1}, /* EPSSteerModSwtReq */
    {/* Index 383 */ 5, CNA_BEHAVIOR_CYCLE, 605, 40, 185, 1, 456, 1}, /* HUT_DrvModReq */
    {/* Index 384 */ 5, CNA_BEHAVIOR_CYCLE, 550, 40, 186, 1, 457, 1}, /* OilLvlDispReq */
    {/* Index 385 */ 5, CNA_BEHAVIOR_CYCLE, 181, 11, 187, 1, 458, 1}, /* DampgDrvModeReq */
    {/* Index 386 */ 5, CNA_BEHAVIOR_CYCLE, 180, 11, 188, 1, 459, 1}, /* DrivingModReq_VR */
    {/* Index 387 */ 5, CNA_BEHAVIOR_CYCLE, 177, 11, 189, 1, 460, 1}, /* ORVMFoldSwt_HUT */
    {/* Index 388 */ 5, CNA_BEHAVIOR_CYCLE, 387, 28, 190, 1, 461, 1}, /* AppModeFB */
};

static CNA_SignalType cna_signalDatas[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = {0u};
static const uint8 cna_noActionBuffer[191] =
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
    3u,
    0u,
    3u,
    10u,
    0u,
    3u,
    15u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[734] =
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
    323,
    325,
    327,
    326,
    321,
    309,
    303,
    302,
    313,
    319,
    301,
    305,
    312,
    310,
    317,
    318,
    324,
    311,
    306,
    307,
    322,
    308,
    314,
    315,
    300,
    316,
    304,
    320,
    65535,
    341,
    335,
    338,
    329,
    332,
    328,
    330,
    333,
    334,
    337,
    336,
    331,
    342,
    340,
    339,
    65535,
    350,
    353,
    352,
    351,
    348,
    346,
    349,
    347,
    345,
    355,
    354,
    343,
    344,
    65535,
    370,
    373,
    357,
    359,
    364,
    358,
    361,
    362,
    360,
    356,
    363,
    371,
    377,
    368,
    376,
    366,
    369,
    372,
    367,
    365,
    374,
    375,
    65535,
    12,
    13,
    20,
    22,
    24,
    19,
    25,
    26,
    15,
    23,
    17,
    16,
    14,
    18,
    21,
    28,
    27,
    65535,
    6,
    1,
    2,
    3,
    5,
    0,
    4,
    11,
    10,
    9,
    7,
    8,
    65535,
    266,
    265,
    268,
    267,
    264,
    272,
    270,
    269,
    271,
    275,
    276,
    273,
    274,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    387,
    65535,
    65535,
    386,
    385,
    65535,
    65535,
    65535,
    164,
    165,
    163,
    166,
    174,
    168,
    167,
    177,
    162,
    169,
    175,
    176,
    173,
    170,
    178,
    172,
    180,
    179,
    171,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    291,
    294,
    292,
    299,
    290,
    295,
    289,
    293,
    298,
    286,
    287,
    297,
    285,
    288,
    296,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    257,
    258,
    256,
    259,
    260,
    255,
    261,
    262,
    263,
    65535,
    247,
    248,
    245,
    249,
    250,
    244,
    251,
    252,
    243,
    246,
    253,
    254,
    65535,
    233,
    236,
    227,
    238,
    241,
    224,
    225,
    240,
    242,
    239,
    232,
    237,
    226,
    231,
    229,
    230,
    228,
    235,
    234,
    65535,
    212,
    215,
    208,
    217,
    221,
    219,
    223,
    218,
    210,
    216,
    207,
    209,
    222,
    211,
    220,
    214,
    213,
    65535,
    284,
    277,
    278,
    281,
    279,
    283,
    282,
    280,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    380,
    65535,
    105,
    104,
    106,
    103,
    108,
    107,
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
    146,
    154,
    137,
    147,
    148,
    138,
    140,
    161,
    139,
    155,
    156,
    145,
    151,
    142,
    152,
    153,
    157,
    160,
    144,
    159,
    143,
    158,
    150,
    141,
    135,
    134,
    136,
    149,
    65535,
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
    65535,
    65,
    66,
    56,
    57,
    63,
    64,
    62,
    59,
    58,
    69,
    60,
    70,
    61,
    72,
    68,
    67,
    71,
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
    133,
    126,
    127,
    128,
    129,
    130,
    131,
    132,
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
    94,
    95,
    81,
    82,
    96,
    100,
    98,
    101,
    97,
    99,
    102,
    65535,
    109,
    110,
    111,
    112,
    113,
    116,
    122,
    125,
    123,
    124,
    114,
    120,
    117,
    115,
    121,
    118,
    119,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    194,
    190,
    197,
    185,
    184,
    193,
    188,
    195,
    191,
    198,
    186,
    183,
    182,
    192,
    199,
    189,
    196,
    187,
    200,
    65535,
    181,
    65535,
    204,
    206,
    201,
    202,
    203,
    205,
    65535,
    46,
    44,
    45,
    47,
    43,
    65535,
    51,
    52,
    53,
    54,
    49,
    50,
    48,
    55,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    382,
    65535,
    65535,
    65535,
    65535,
    384,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    41,
    40,
    39,
    30,
    35,
    37,
    34,
    36,
    32,
    31,
    33,
    29,
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
    65535,
    65535,
    65535,
    65535,
};

static uint8 cna_currentBuffer[462] = {0};

const CNA_ConfigType cna_config =
{
    SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER,
    cna_signalConfigs,
    cna_signalDatas,
    191u,
    cna_noActionBuffer,
    462u,
    cna_currentBuffer,
    734u,
    CNA_IdTable
};

#define Can_Server_STOP_SEC_CONST_UNSPECIFIED
#include "Can_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
