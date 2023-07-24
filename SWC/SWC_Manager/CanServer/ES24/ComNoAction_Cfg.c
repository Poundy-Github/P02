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
#include "Std_Types.h"
#include "ComNoAction.h"
#ifndef SWC_IPC_CAN_MATRIX_ES24H
    #include "SWC_IPC_CANMatrix_ES24.h"
    #if ( 0xb0f43e84 != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
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
static const CNA_SignalConfigType cna_signalConfigs[366] =
{
    {/* Index 0 */ 5, CNA_BEHAVIOR_NONE, 137, 8, 0, 0, 0, 1}, /* ALCMBreSwt_OLE */
    {/* Index 1 */ 5, CNA_BEHAVIOR_NONE, 140, 8, 0, 0, 1, 1}, /* ALCMRdmSwt_OLE */
    {/* Index 2 */ 5, CNA_BEHAVIOR_UNSEND, 142, 8, 0, 1, 2, 1}, /* ChairRestSetSwt */
    {/* Index 3 */ 5, CNA_BEHAVIOR_SEND, 141, 8, 1, 1, 3, 1}, /* ChildLockCmd */
    {/* Index 4 */ 5, CNA_BEHAVIOR_SEND, 139, 8, 2, 1, 4, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 5 */ 5, CNA_BEHAVIOR_SEND, 138, 8, 3, 1, 5, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 6 */ 5, CNA_BEHAVIOR_SEND, 144, 8, 4, 1, 6, 1}, /* MiaoCallClsReq */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 136, 8, 5, 1, 7, 1}, /* MusicLightShowSet */
    {/* Index 8 */ 5, CNA_BEHAVIOR_UNSEND, 145, 8, 6, 1, 8, 1}, /* OTA_UpgrdModReq */
    {/* Index 9 */ 5, CNA_BEHAVIOR_NONE, 143, 8, 7, 0, 9, 1}, /* SpoilerSpdSet */
    {/* Index 10 */ 5, CNA_BEHAVIOR_SEND, 119, 7, 7, 1, 10, 1}, /* AUTODefrost_TC */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 118, 7, 8, 1, 11, 1}, /* AUTODefrost_VR */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 128, 7, 9, 1, 12, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 126, 7, 10, 1, 13, 1}, /* AutoViewChgCmd */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 11, 1, 14, 1}, /* CarMdlDispCmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 124, 7, 12, 1, 15, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 13, 1, 16, 1}, /* FPAS_AutoModSwt */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 120, 7, 14, 1, 17, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 117, 7, 15, 1, 18, 1}, /* HUT_VCUBattKeepTemp */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 123, 7, 16, 1, 19, 1}, /* LaneCalActvtCmd */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 17, 1, 20, 1}, /* MEBSwtSet */
    {/* Index 21 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 18, 1, 21, 1}, /* MODChgReq */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 125, 7, 19, 1, 22, 1}, /* MdlColrChgCmd */
    {/* Index 23 */ 5, CNA_BEHAVIOR_SEND, 122, 7, 20, 1, 23, 1}, /* Radar_DispCmd */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 121, 7, 21, 1, 24, 1}, /* Sgl_View_Sel */
    {/* Index 25 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 22, 1, 25, 1}, /* SwToFieldCalRstCmd */
    {/* Index 26 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 23, 1, 26, 1}, /* View_SoftswitchCmd */
    {/* Index 27 */ 5, CNA_BEHAVIOR_SEND, 127, 7, 24, 1, 27, 1}, /* WshSoftSwt */
    {/* Index 28 */ 5, CNA_BEHAVIOR_SEND, 681, 45, 25, 1, 28, 1}, /* HUT_HAVP_APA_Permit */
    {/* Index 29 */ 5, CNA_BEHAVIOR_UNSEND, 688, 45, 26, 1, 29, 1}, /* HUT_HAVP_Comfirm_Btn */
    {/* Index 30 */ 5, CNA_BEHAVIOR_NONE, 689, 45, 27, 0, 30, 1}, /* HUT_HAVP_Path_Delete */
    {/* Index 31 */ 5, CNA_BEHAVIOR_NONE, 690, 45, 27, 0, 31, 1}, /* HUT_HAVP_Path_Select */
    {/* Index 32 */ 5, CNA_BEHAVIOR_NONE, 691, 45, 27, 0, 32, 1}, /* HUT_HAVP_Path_SetTop */
    {/* Index 33 */ 5, CNA_BEHAVIOR_SEND, 680, 45, 27, 1, 33, 1}, /* HUT_HAVP_Return_Btn */
    {/* Index 34 */ 5, CNA_BEHAVIOR_SEND, 683, 45, 28, 1, 34, 1}, /* HUT_HAVP_SelfParLot_Ending */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 684, 45, 29, 1, 35, 1}, /* HUT_HAVP_Set_Path_Ending */
    {/* Index 36 */ 5, CNA_BEHAVIOR_SEND, 682, 45, 30, 1, 36, 1}, /* HUT_HAVP_Set_Starting */
    {/* Index 37 */ 5, CNA_BEHAVIOR_SEND, 685, 45, 31, 1, 37, 1}, /* SlotNum_VR */
    {/* Index 38 */ 5, CNA_BEHAVIOR_SEND, 686, 45, 32, 1, 38, 1}, /* UserDefPrkMenuSelCmd */
    {/* Index 39 */ 5, CNA_BEHAVIOR_SEND, 687, 45, 33, 1, 39, 1}, /* UserDefinedParkCmd */
    {/* Index 40 */ 5, CNA_BEHAVIOR_UNSEND, 491, 39, 34, 1, 40, 1}, /* ApprLightSwt */
    {/* Index 41 */ 5, CNA_BEHAVIOR_SEND, 495, 39, 35, 1, 41, 1}, /* DrvSeatMassgModSet */
    {/* Index 42 */ 5, CNA_BEHAVIOR_SEND, 497, 39, 36, 1, 42, 1}, /* FastChargelidSwt */
    {/* Index 43 */ 5, CNA_BEHAVIOR_SEND, 496, 39, 37, 1, 43, 1}, /* HUT_V2LStart */
    {/* Index 44 */ 5, CNA_BEHAVIOR_UNSEND, 493, 39, 38, 1, 44, 1}, /* LockWelLightSwt */
    {/* Index 45 */ 5, CNA_BEHAVIOR_SEND, 494, 39, 39, 1, 45, 1}, /* PassSeatMassgModSet */
    {/* Index 46 */ 5, CNA_BEHAVIOR_SEND, 498, 39, 40, 1, 46, 1}, /* SlowChargelidSwt */
    {/* Index 47 */ 5, CNA_BEHAVIOR_UNSEND, 492, 39, 41, 1, 47, 1}, /* UnlockWelLightSwt */
    {/* Index 48 */ 5, CNA_BEHAVIOR_SEND, 401, 29, 42, 1, 48, 1}, /* ACMaxReq_TC */
    {/* Index 49 */ 5, CNA_BEHAVIOR_SEND, 400, 29, 43, 1, 49, 1}, /* ACMaxReq_VR */
    {/* Index 50 */ 5, CNA_BEHAVIOR_SEND, 398, 29, 44, 1, 50, 1}, /* ESCMAdjCmd */
    {/* Index 51 */ 5, CNA_BEHAVIOR_NONE, 399, 29, 45, 0, 51, 1}, /* LockWinSet */
    {/* Index 52 */ 5, CNA_BEHAVIOR_SEND, 397, 29, 45, 1, 52, 1}, /* SpoilerCtrlCmd */
    {/* Index 53 */ 5, CNA_BEHAVIOR_NONE, 396, 29, 46, 0, 53, 1}, /* SpoilerFixModSwt */
    {/* Index 54 */ 5, CNA_BEHAVIOR_NONE, 395, 29, 46, 0, 54, 1}, /* SpoilerWelModSwt */
    {/* Index 55 */ 5, CNA_BEHAVIOR_NONE, 403, 30, 46, 0, 55, 1}, /* MultiColorNr1 */
    {/* Index 56 */ 5, CNA_BEHAVIOR_NONE, 404, 30, 46, 0, 56, 1}, /* MultiColorNr2 */
    {/* Index 57 */ 5, CNA_BEHAVIOR_NONE, 405, 30, 46, 0, 57, 1}, /* MultiColorNr3 */
    {/* Index 58 */ 5, CNA_BEHAVIOR_NONE, 406, 30, 46, 0, 58, 1}, /* MultiColorNr4 */
    {/* Index 59 */ 5, CNA_BEHAVIOR_NONE, 407, 30, 46, 0, 59, 1}, /* MultiColorNr5 */
    {/* Index 60 */ 5, CNA_BEHAVIOR_NONE, 408, 30, 46, 0, 60, 1}, /* MultiColorNr6 */
    {/* Index 61 */ 5, CNA_BEHAVIOR_NONE, 409, 30, 46, 0, 61, 1}, /* MultiColorNr7 */
    {/* Index 62 */ 5, CNA_BEHAVIOR_NONE, 410, 30, 46, 0, 62, 1}, /* MultiColorNr8 */
    {/* Index 63 */ 5, CNA_BEHAVIOR_SEND, 421, 32, 46, 1, 63, 1}, /* ACUltravioletReq_TC */
    {/* Index 64 */ 5, CNA_BEHAVIOR_SEND, 422, 32, 47, 1, 64, 1}, /* ACUltravioletReq_VR */
    {/* Index 65 */ 5, CNA_BEHAVIOR_SEND, 423, 32, 48, 1, 65, 1}, /* DrvDoorALCMFlashFreq */
    {/* Index 66 */ 5, CNA_BEHAVIOR_SEND, 429, 32, 49, 1, 66, 1}, /* FootALCMFlashFreq */
    {/* Index 67 */ 5, CNA_BEHAVIOR_SEND, 424, 32, 50, 1, 67, 1}, /* LRDoorALCMFlashFreq */
    {/* Index 68 */ 5, CNA_BEHAVIOR_SEND, 427, 32, 51, 1, 68, 1}, /* LeftPanelALCMFlashFreq */
    {/* Index 69 */ 5, CNA_BEHAVIOR_SEND, 425, 32, 52, 1, 69, 1}, /* PassDoorALCMFlashFreq */
    {/* Index 70 */ 5, CNA_BEHAVIOR_SEND, 426, 32, 53, 1, 70, 1}, /* RRDoorALCMFlashFreq */
    {/* Index 71 */ 5, CNA_BEHAVIOR_SEND, 428, 32, 54, 1, 71, 1}, /* RightPanelALCMFlashFreq */
    {/* Index 72 */ 5, CNA_BEHAVIOR_NONE, 325, 24, 55, 0, 72, 1}, /* ADASDispSwt */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 328, 24, 55, 0, 73, 1}, /* BTPhoneDispSwt */
    {/* Index 74 */ 5, CNA_BEHAVIOR_SEND, 327, 24, 55, 1, 74, 1}, /* BackReq_AVM */
    {/* Index 75 */ 5, CNA_BEHAVIOR_NONE, 329, 24, 56, 0, 75, 1}, /* EngspdDispSwt */
    {/* Index 76 */ 5, CNA_BEHAVIOR_SEND, 333, 24, 56, 1, 76, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 77 */ 5, CNA_BEHAVIOR_NONE, 330, 24, 57, 0, 77, 1}, /* HUD_DisplayModeCfg */
    {/* Index 78 */ 5, CNA_BEHAVIOR_SEND, 326, 24, 57, 1, 78, 1}, /* HUD_HeightLvlSwt */
    {/* Index 79 */ 5, CNA_BEHAVIOR_NONE, 331, 24, 58, 0, 79, 1}, /* HUD_RotateAngleCfg */
    {/* Index 80 */ 5, CNA_BEHAVIOR_NONE, 334, 24, 58, 0, 80, 1}, /* HUD_RotateDirCfg */
    {/* Index 81 */ 5, CNA_BEHAVIOR_SEND, 332, 24, 58, 1, 81, 1}, /* HUD_SwtReq */
    {/* Index 82 */ 5, CNA_BEHAVIOR_NONE, 324, 24, 59, 0, 82, 1}, /* NaviDispSwt */
    {/* Index 83 */ 5, CNA_BEHAVIOR_UNSEND, 322, 24, 59, 1, 83, 1}, /* PPMIBSRSwtSet */
    {/* Index 84 */ 5, CNA_BEHAVIOR_UNSEND, 323, 24, 60, 1, 84, 1}, /* PPMIHWSwtSet */
    {/* Index 85 */ 5, CNA_BEHAVIOR_NONE, 439, 33, 61, 0, 85, 1}, /* ActvEntryLockSet */
    {/* Index 86 */ 5, CNA_BEHAVIOR_NONE, 440, 33, 61, 0, 86, 1}, /* ActvEntryUnlockSet */
    {/* Index 87 */ 5, CNA_BEHAVIOR_NONE, 431, 33, 61, 0, 87, 1}, /* BTAPAEntryLockSet */
    {/* Index 88 */ 5, CNA_BEHAVIOR_NONE, 432, 33, 61, 0, 88, 1}, /* BTAPALvngUnlockSet */
    {/* Index 89 */ 5, CNA_BEHAVIOR_NONE, 441, 33, 61, 0, 89, 1}, /* ClsWinSpdSet */
    {/* Index 90 */ 5, CNA_BEHAVIOR_SEND, 433, 33, 61, 1, 90, 1}, /* DrvDoorALCMClrSet */
    {/* Index 91 */ 5, CNA_BEHAVIOR_NONE, 436, 33, 62, 0, 91, 1}, /* DrvDoorALCMSwt */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 443, 33, 62, 1, 92, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 93 */ 5, CNA_BEHAVIOR_SEND, 434, 33, 63, 1, 93, 1}, /* LRDoorALCMClrSet */
    {/* Index 94 */ 5, CNA_BEHAVIOR_NONE, 438, 33, 64, 0, 94, 1}, /* LockPromptFunSet */
    {/* Index 95 */ 5, CNA_BEHAVIOR_SEND, 435, 33, 64, 1, 95, 1}, /* PassDoorALCMClrSet */
    {/* Index 96 */ 5, CNA_BEHAVIOR_NONE, 437, 33, 65, 0, 96, 1}, /* PassDoorALCMSwt */
    {/* Index 97 */ 5, CNA_BEHAVIOR_SEND, 442, 33, 65, 1, 97, 1}, /* PassSeatMassgLvlSet */
    {/* Index 98 */ 5, CNA_BEHAVIOR_NONE, 413, 31, 66, 0, 98, 1}, /* MultiColorNr10 */
    {/* Index 99 */ 5, CNA_BEHAVIOR_NONE, 414, 31, 66, 0, 99, 1}, /* MultiColorNr11 */
    {/* Index 100 */ 5, CNA_BEHAVIOR_NONE, 415, 31, 66, 0, 100, 1}, /* MultiColorNr12 */
    {/* Index 101 */ 5, CNA_BEHAVIOR_NONE, 416, 31, 66, 0, 101, 1}, /* MultiColorNr13 */
    {/* Index 102 */ 5, CNA_BEHAVIOR_NONE, 417, 31, 66, 0, 102, 1}, /* MultiColorNr14 */
    {/* Index 103 */ 5, CNA_BEHAVIOR_NONE, 418, 31, 66, 0, 103, 1}, /* MultiColorNr15 */
    {/* Index 104 */ 5, CNA_BEHAVIOR_NONE, 419, 31, 66, 0, 104, 1}, /* MultiColorNr16 */
    {/* Index 105 */ 5, CNA_BEHAVIOR_NONE, 412, 31, 66, 0, 105, 1}, /* MultiColorNr9 */
    {/* Index 106 */ 5, CNA_BEHAVIOR_SEND, 377, 27, 66, 1, 106, 1}, /* ACFGAChanTyp_TC */
    {/* Index 107 */ 5, CNA_BEHAVIOR_SEND, 378, 27, 67, 1, 107, 1}, /* ACFGAEnaReq_TC */
    {/* Index 108 */ 5, CNA_BEHAVIOR_SEND, 376, 27, 68, 1, 108, 1}, /* ACFGALvlReq_TC */
    {/* Index 109 */ 6, CNA_BEHAVIOR_NONE, 379, 27, 69, 0, 109, 1}, /* ALCMDynModSet */
    {/* Index 110 */ 6, CNA_BEHAVIOR_UNSEND, 381, 27, 69, 1, 110, 1}, /* ApproachLampSet */
    {/* Index 111 */ 5, CNA_BEHAVIOR_SEND, 366, 27, 70, 1, 111, 1}, /* BackReq_APS */
    {/* Index 112 */ 6, CNA_BEHAVIOR_SEND, 360, 27, 71, 1, 112, 1}, /* ChairMemPosnSetSwt */
    {/* Index 113 */ 5, CNA_BEHAVIOR_SEND, 371, 27, 72, 1, 113, 1}, /* DeletePath1Cmd */
    {/* Index 114 */ 5, CNA_BEHAVIOR_SEND, 369, 27, 73, 1, 114, 1}, /* DeletePath2Cmd */
    {/* Index 115 */ 6, CNA_BEHAVIOR_SEND, 362, 27, 74, 1, 115, 1}, /* DrvWinSwtReq_VR */
    {/* Index 116 */ 6, CNA_BEHAVIOR_UNSEND, 359, 27, 75, 1, 116, 1}, /* FlaoutUnlockSet */
    {/* Index 117 */ 6, CNA_BEHAVIOR_NONE, 375, 27, 76, 0, 117, 1}, /* HUD_VibrationCorrn */
    {/* Index 118 */ 5, CNA_BEHAVIOR_SEND, 382, 27, 76, 1, 118, 1}, /* P2P_PrkgDirectSwtCmd */
    {/* Index 119 */ 5, CNA_BEHAVIOR_SEND, 365, 27, 77, 1, 119, 1}, /* ParkMdlCmd */
    {/* Index 120 */ 6, CNA_BEHAVIOR_SEND, 374, 27, 78, 1, 120, 1}, /* PassWinSwtReq_VR */
    {/* Index 121 */ 5, CNA_BEHAVIOR_SEND, 363, 27, 79, 1, 121, 1}, /* PathLrngFinshCmd */
    {/* Index 122 */ 5, CNA_BEHAVIOR_SEND, 364, 27, 80, 1, 122, 1}, /* PathLrngStartCmd */
    {/* Index 123 */ 6, CNA_BEHAVIOR_NONE, 361, 27, 81, 0, 123, 1}, /* PrkInDirChoice */
    {/* Index 124 */ 6, CNA_BEHAVIOR_SEND, 373, 27, 81, 1, 124, 1}, /* RLWinSwtReq_VR */
    {/* Index 125 */ 6, CNA_BEHAVIOR_SEND, 380, 27, 82, 1, 125, 1}, /* RRWinSwtReq_VR */
    {/* Index 126 */ 5, CNA_BEHAVIOR_SEND, 367, 27, 83, 1, 126, 1}, /* SelPrkOutDirReq */
    {/* Index 127 */ 5, CNA_BEHAVIOR_SEND, 372, 27, 84, 1, 127, 1}, /* SelPrkgFctnCmd */
    {/* Index 128 */ 5, CNA_BEHAVIOR_SEND, 370, 27, 85, 1, 128, 1}, /* StartPrkgPath1Cmd */
    {/* Index 129 */ 5, CNA_BEHAVIOR_SEND, 368, 27, 86, 1, 129, 1}, /* StartPrkgPath2Cmd */
    {/* Index 130 */ 5, CNA_BEHAVIOR_NONE, 186, 12, 87, 0, 130, 1}, /* ABSLmpSet */
    {/* Index 131 */ 5, CNA_BEHAVIOR_SEND, 188, 12, 87, 1, 131, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 132 */ 5, CNA_BEHAVIOR_SEND, 191, 12, 88, 1, 132, 1}, /* ACEAHReq_TC */
    {/* Index 133 */ 5, CNA_BEHAVIOR_SEND, 193, 12, 89, 1, 133, 1}, /* ACEAHReq_VR */
    {/* Index 134 */ 5, CNA_BEHAVIOR_SEND, 182, 12, 90, 1, 134, 1}, /* ACOperMod_TC */
    {/* Index 135 */ 5, CNA_BEHAVIOR_SEND, 181, 12, 91, 1, 135, 1}, /* ACOperMod_VR */
    {/* Index 136 */ 5, CNA_BEHAVIOR_SEND, 190, 12, 92, 1, 136, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 137 */ 5, CNA_BEHAVIOR_SEND, 192, 12, 93, 1, 137, 1}, /* APSPrkgTypSeln */
    {/* Index 138 */ 5, CNA_BEHAVIOR_SEND, 198, 12, 94, 1, 138, 1}, /* APSSwtReq_VR */
    {/* Index 139 */ 5, CNA_BEHAVIOR_NONE, 185, 12, 95, 0, 139, 1}, /* AutoWshWipSet */
    {/* Index 140 */ 5, CNA_BEHAVIOR_NONE, 187, 12, 95, 0, 140, 1}, /* DoorUnlockModSet */
    {/* Index 141 */ 5, CNA_BEHAVIOR_SEND, 197, 12, 95, 1, 141, 1}, /* PASExitSpdSwt */
    {/* Index 142 */ 5, CNA_BEHAVIOR_NONE, 183, 12, 96, 0, 142, 1}, /* ParkLmpSet */
    {/* Index 143 */ 5, CNA_BEHAVIOR_SEND, 194, 12, 96, 1, 143, 1}, /* SDWSwtSet */
    {/* Index 144 */ 5, CNA_BEHAVIOR_NONE, 184, 12, 97, 0, 144, 1}, /* SeekVehSet */
    {/* Index 145 */ 5, CNA_BEHAVIOR_NONE, 189, 12, 97, 0, 145, 1}, /* SpdAutoLockModSet */
    {/* Index 146 */ 5, CNA_BEHAVIOR_NONE, 179, 12, 97, 0, 146, 1}, /* SportModLightSet */
    {/* Index 147 */ 5, CNA_BEHAVIOR_SEND, 180, 12, 97, 1, 147, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 148 */ 5, CNA_BEHAVIOR_SEND, 196, 12, 98, 1, 148, 1}, /* SunRoofSwtReq_VR */
    {/* Index 149 */ 5, CNA_BEHAVIOR_SEND, 195, 12, 99, 1, 149, 1}, /* SunShadeSwtReq_VR */
    {/* Index 150 */ 5, CNA_BEHAVIOR_NONE, 501, 40, 100, 0, 150, 1}, /* ALCMCPClrSet */
    {/* Index 151 */ 5, CNA_BEHAVIOR_NONE, 502, 40, 100, 0, 151, 1}, /* ALCMCPModeSet */
    {/* Index 152 */ 5, CNA_BEHAVIOR_NONE, 500, 40, 100, 0, 152, 1}, /* ALCMWPCGangSwt */
    {/* Index 153 */ 5, CNA_BEHAVIOR_SEND, 506, 41, 100, 1, 153, 1}, /* LChildLockProtSwt */
    {/* Index 154 */ 5, CNA_BEHAVIOR_SEND, 507, 41, 101, 1, 154, 1}, /* RChildLockProtSwt */
    {/* Index 155 */ 5, CNA_BEHAVIOR_UNSEND, 504, 41, 102, 1, 155, 1}, /* ScenarioSwtID */
    {/* Index 156 */ 5, CNA_BEHAVIOR_UNSEND, 505, 41, 103, 1, 156, 1}, /* ScenarioSwtReq */
    {/* Index 157 */ 5, CNA_BEHAVIOR_UNSEND, 476, 36, 104, 1, 157, 1}, /* HUT_AccelPedalSnvtyAdj */
    {/* Index 158 */ 5, CNA_BEHAVIOR_UNSEND, 477, 36, 105, 1, 158, 1}, /* HUT_CreepSwt */
    {/* Index 159 */ 5, CNA_BEHAVIOR_UNSEND, 475, 36, 106, 1, 159, 1}, /* HUT_EneRecoInteAdj */
    {/* Index 160 */ 5, CNA_BEHAVIOR_NONE, 473, 35, 107, 0, 160, 1}, /* ALCMBreSwt */
    {/* Index 161 */ 5, CNA_BEHAVIOR_NONE, 464, 35, 107, 0, 161, 1}, /* ALCMFloSwt */
    {/* Index 162 */ 5, CNA_BEHAVIOR_SEND, 459, 35, 107, 1, 162, 1}, /* DrvDoorALCMLightLvlSet */
    {/* Index 163 */ 5, CNA_BEHAVIOR_SEND, 471, 35, 108, 1, 163, 1}, /* FootALCMClrSet */
    {/* Index 164 */ 5, CNA_BEHAVIOR_SEND, 472, 35, 109, 1, 164, 1}, /* FootALCMLightLvlSet */
    {/* Index 165 */ 5, CNA_BEHAVIOR_NONE, 469, 35, 110, 0, 165, 1}, /* FootALCMSwt */
    {/* Index 166 */ 5, CNA_BEHAVIOR_SEND, 460, 35, 110, 1, 166, 1}, /* LRDoorALCMLightLvlSet */
    {/* Index 167 */ 5, CNA_BEHAVIOR_NONE, 467, 35, 111, 0, 167, 1}, /* LRDoorALCMSwt */
    {/* Index 168 */ 5, CNA_BEHAVIOR_SEND, 457, 35, 111, 1, 168, 1}, /* LeftPanelALCMClrSet */
    {/* Index 169 */ 5, CNA_BEHAVIOR_SEND, 463, 35, 112, 1, 169, 1}, /* LeftPanelALCMLightLvlSet */
    {/* Index 170 */ 5, CNA_BEHAVIOR_NONE, 465, 35, 113, 0, 170, 1}, /* LeftPanelALCMSwt */
    {/* Index 171 */ 5, CNA_BEHAVIOR_SEND, 461, 35, 113, 1, 171, 1}, /* PassDoorALCMLightLvlSet */
    {/* Index 172 */ 5, CNA_BEHAVIOR_SEND, 456, 35, 114, 1, 172, 1}, /* RRDoorALCMClrSet */
    {/* Index 173 */ 5, CNA_BEHAVIOR_SEND, 462, 35, 115, 1, 173, 1}, /* RRDoorALCMLightLvlSet */
    {/* Index 174 */ 5, CNA_BEHAVIOR_NONE, 468, 35, 116, 0, 174, 1}, /* RRDoorALCMSwt */
    {/* Index 175 */ 5, CNA_BEHAVIOR_SEND, 458, 35, 116, 1, 175, 1}, /* RightPanelALCMClrSet */
    {/* Index 176 */ 5, CNA_BEHAVIOR_SEND, 455, 35, 117, 1, 176, 1}, /* RightPanelALCMLightLvlSet */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 466, 35, 118, 0, 177, 1}, /* RightPanelALCMSwt */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 470, 35, 118, 0, 178, 1}, /* RoofALCMSwt */
    {/* Index 179 */ 5, CNA_BEHAVIOR_NONE, 479, 37, 118, 0, 179, 1}, /* DrvWinSwtReq */
    {/* Index 180 */ 5, CNA_BEHAVIOR_NONE, 481, 37, 118, 0, 180, 1}, /* PassWinSwtReq */
    {/* Index 181 */ 5, CNA_BEHAVIOR_NONE, 480, 37, 118, 0, 181, 1}, /* RLWinSwtReq */
    {/* Index 182 */ 5, CNA_BEHAVIOR_NONE, 482, 37, 118, 0, 182, 1}, /* RRWinSwtReq */
    {/* Index 183 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 118, 0, 183, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 184 */ 5, CNA_BEHAVIOR_NONE, 281, 19, 118, 0, 184, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 185 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 118, 0, 185, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 186 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 118, 0, 186, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 294, 19, 118, 0, 187, 1}, /* ADAS_Stub_LastStub */
    {/* Index 188 */ 5, CNA_BEHAVIOR_NONE, 279, 19, 118, 0, 188, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 118, 0, 189, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 190 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 118, 0, 190, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 278, 19, 118, 0, 191, 2}, /* ADAS_Stub_Offset */
    {/* Index 192 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 118, 0, 193, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 193 */ 5, CNA_BEHAVIOR_NONE, 280, 19, 118, 0, 194, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 194 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 118, 0, 195, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 195 */ 5, CNA_BEHAVIOR_NONE, 283, 19, 118, 0, 196, 1}, /* ADAS_Stub_Retr */
    {/* Index 196 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 118, 0, 197, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 197 */ 5, CNA_BEHAVIOR_NONE, 284, 19, 118, 0, 198, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 198 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 118, 0, 199, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 282, 19, 118, 0, 200, 1}, /* ADAS_Stub_Update */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 118, 0, 201, 1}, /* ADAS_Seg_Brdg */
    {/* Index 201 */ 5, CNA_BEHAVIOR_NONE, 264, 18, 118, 0, 202, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 118, 0, 203, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 203 */ 5, CNA_BEHAVIOR_NONE, 261, 18, 118, 0, 204, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 204 */ 5, CNA_BEHAVIOR_NONE, 276, 18, 118, 0, 205, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 205 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 118, 0, 206, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 206 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 118, 0, 207, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 207 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 118, 0, 208, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 118, 0, 209, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 209 */ 5, CNA_BEHAVIOR_NONE, 259, 18, 118, 0, 210, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 210 */ 5, CNA_BEHAVIOR_NONE, 274, 18, 118, 0, 211, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 275, 18, 118, 0, 212, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 258, 18, 118, 0, 213, 2}, /* ADAS_Seg_Offset */
    {/* Index 213 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 118, 0, 215, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 260, 18, 118, 0, 216, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 215 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 118, 0, 217, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 216 */ 5, CNA_BEHAVIOR_NONE, 263, 18, 118, 0, 218, 1}, /* ADAS_Seg_Retr */
    {/* Index 217 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 118, 0, 219, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 218 */ 5, CNA_BEHAVIOR_NONE, 262, 18, 118, 0, 220, 1}, /* ADAS_Seg_Update */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 118, 0, 221, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 251, 17, 118, 0, 222, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 221 */ 5, CNA_BEHAVIOR_NONE, 248, 17, 118, 0, 223, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 118, 0, 224, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 246, 17, 118, 0, 226, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 245, 17, 118, 0, 227, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 247, 17, 118, 0, 229, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 226 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 118, 0, 230, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 227 */ 5, CNA_BEHAVIOR_NONE, 250, 17, 118, 0, 231, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 249, 17, 118, 0, 232, 1}, /* ADAS_ProfShort_Update */
    {/* Index 229 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 118, 0, 233, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 230 */ 5, CNA_BEHAVIOR_NONE, 256, 17, 118, 0, 235, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 231 */ 5, CNA_BEHAVIOR_NONE, 241, 16, 118, 0, 237, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 232 */ 5, CNA_BEHAVIOR_NONE, 238, 16, 118, 0, 238, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 233 */ 5, CNA_BEHAVIOR_NONE, 236, 16, 118, 0, 239, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 234 */ 5, CNA_BEHAVIOR_NONE, 235, 16, 118, 0, 240, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 235 */ 5, CNA_BEHAVIOR_NONE, 237, 16, 118, 0, 242, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 236 */ 5, CNA_BEHAVIOR_NONE, 242, 16, 118, 0, 243, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 237 */ 5, CNA_BEHAVIOR_NONE, 240, 16, 118, 0, 244, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 238 */ 5, CNA_BEHAVIOR_NONE, 239, 16, 118, 0, 245, 1}, /* ADAS_ProfLong_Update */
    {/* Index 239 */ 5, CNA_BEHAVIOR_NONE, 243, 16, 118, 0, 246, 4}, /* ADAS_ProfLong_Value */
    {/* Index 240 */ 5, CNA_BEHAVIOR_SEND, 162, 9, 118, 1, 250, 1}, /* ACAIUReq_VR */
    {/* Index 241 */ 5, CNA_BEHAVIOR_SEND, 150, 9, 119, 1, 251, 1}, /* ACAQSReq_VR */
    {/* Index 242 */ 5, CNA_BEHAVIOR_SEND, 151, 9, 120, 1, 252, 1}, /* ACDualReq_VR */
    {/* Index 243 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 121, 1, 253, 1}, /* ACPassTempReq_VR */
    {/* Index 244 */ 5, CNA_BEHAVIOR_SEND, 157, 9, 122, 1, 254, 1}, /* ACRearDefrstReq_VR */
    {/* Index 245 */ 5, CNA_BEHAVIOR_NONE, 156, 9, 123, 0, 255, 1}, /* ALCMClrSet */
    {/* Index 246 */ 5, CNA_BEHAVIOR_NONE, 158, 9, 123, 0, 256, 1}, /* ALCMDynSwt */
    {/* Index 247 */ 5, CNA_BEHAVIOR_NONE, 154, 9, 123, 0, 257, 1}, /* ALCMRhmSwt */
    {/* Index 248 */ 5, CNA_BEHAVIOR_NONE, 159, 9, 123, 0, 258, 1}, /* ALCMStatSwt */
    {/* Index 249 */ 3, CNA_BEHAVIOR_SEND, 164, 9, 123, 1, 259, 1}, /* HUT_BeanIDReq */
    {/* Index 250 */ 5, CNA_BEHAVIOR_SEND, 147, 9, 124, 1, 260, 1}, /* HUT_ECOACLimnSet */
    {/* Index 251 */ 5, CNA_BEHAVIOR_SEND, 152, 9, 125, 1, 261, 1}, /* HUT_ECODrvModReq */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 153, 9, 126, 0, 262, 1}, /* HUT_ECOSpdLim */
    {/* Index 253 */ 5, CNA_BEHAVIOR_UNSEND, 149, 9, 126, 1, 263, 1}, /* HUT_EgyRecvrySet */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 155, 9, 127, 0, 264, 1}, /* HUT_ImdChrgSet */
    {/* Index 255 */ 5, CNA_BEHAVIOR_NONE, 163, 9, 127, 0, 265, 1}, /* IPVolSet */
    {/* Index 256 */ 5, CNA_BEHAVIOR_SEND, 161, 9, 127, 1, 266, 1}, /* PASSwtReq_VR */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 148, 9, 128, 0, 267, 1}, /* VSGMuteSwSet */
    {/* Index 258 */ 5, CNA_BEHAVIOR_NONE, 305, 20, 128, 0, 268, 1}, /* ADASDispSwt_VR */
    {/* Index 259 */ 5, CNA_BEHAVIOR_NONE, 298, 20, 128, 0, 269, 1}, /* BTPhoneDispSwt_VR */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 299, 20, 128, 0, 270, 1}, /* EngspdDispSwt_VR */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 304, 20, 128, 0, 271, 1}, /* HUD_BrightnessLvlSwt_VR */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 306, 20, 128, 0, 272, 1}, /* HUD_DisplayModeCfg_VR */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 301, 20, 128, 0, 273, 1}, /* HUD_HeightLvlSwt_VR */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 307, 20, 128, 0, 274, 1}, /* HUD_RotateAngleCfg_VR */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 302, 20, 128, 0, 275, 1}, /* HUD_RotateDirCfg_VR */
    {/* Index 266 */ 5, CNA_BEHAVIOR_NONE, 303, 20, 128, 0, 276, 1}, /* HUD_SwtReq_VR */
    {/* Index 267 */ 5, CNA_BEHAVIOR_SEND, 297, 20, 128, 1, 277, 1}, /* HUT_BattSOCLim */
    {/* Index 268 */ 5, CNA_BEHAVIOR_UNSEND, 296, 20, 129, 1, 278, 1}, /* HUT_GModeSet */
    {/* Index 269 */ 5, CNA_BEHAVIOR_SEND, 308, 20, 130, 1, 279, 1}, /* HUT_RemtEngCtrl */
    {/* Index 270 */ 5, CNA_BEHAVIOR_NONE, 300, 20, 131, 0, 280, 1}, /* NaviDispSwt_VR */
    {/* Index 271 */ 5, CNA_BEHAVIOR_NONE, 212, 14, 131, 0, 281, 1}, /* AVMMediaVolLvlReq */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 210, 14, 131, 0, 282, 1}, /* AVMSwtReq */
    {/* Index 273 */ 5, CNA_BEHAVIOR_SEND, 215, 14, 131, 1, 283, 1}, /* BackgroundLightLvlSet */
    {/* Index 274 */ 5, CNA_BEHAVIOR_NONE, 216, 14, 132, 0, 284, 1}, /* DispModSet */
    {/* Index 275 */ 5, CNA_BEHAVIOR_NONE, 209, 14, 132, 0, 285, 1}, /* FPASChanSwtReq */
    {/* Index 276 */ 5, CNA_BEHAVIOR_SEND, 217, 14, 132, 1, 286, 1}, /* HUT_V2VStart */
    {/* Index 277 */ 5, CNA_BEHAVIOR_NONE, 214, 14, 133, 0, 287, 1}, /* ManCmpSet */
    {/* Index 278 */ 5, CNA_BEHAVIOR_NONE, 213, 14, 133, 0, 288, 1}, /* NaviMediaVolLvlReq */
    {/* Index 279 */ 5, CNA_BEHAVIOR_UNSEND, 218, 14, 133, 1, 289, 1}, /* OPDSwtSts */
    {/* Index 280 */ 5, CNA_BEHAVIOR_UNSEND, 219, 14, 134, 1, 290, 1}, /* PLGReq_VR */
    {/* Index 281 */ 5, CNA_BEHAVIOR_NONE, 208, 14, 135, 0, 291, 1}, /* RPASChanSwtReq */
    {/* Index 282 */ 5, CNA_BEHAVIOR_UNSEND, 211, 14, 135, 1, 292, 1}, /* WPC_SwtReq */
    {/* Index 283 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 136, 1, 293, 1}, /* ACAIUReq_TC */
    {/* Index 284 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 137, 1, 294, 1}, /* ACAQSReq_TC */
    {/* Index 285 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 138, 1, 295, 1}, /* ACAirInletReq_TC */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 139, 1, 296, 1}, /* ACAutoModReq_TC */
    {/* Index 287 */ 5, CNA_BEHAVIOR_SEND, 65, 3, 140, 1, 297, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 141, 1, 298, 1}, /* ACCmprReq_TC */
    {/* Index 289 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 142, 1, 299, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 290 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 143, 1, 300, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 291 */ 5, CNA_BEHAVIOR_SEND, 64, 3, 144, 1, 301, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 292 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 145, 1, 302, 1}, /* ACDualReq_TC */
    {/* Index 293 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 146, 1, 303, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 294 */ 5, CNA_BEHAVIOR_SEND, 60, 3, 147, 1, 304, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 295 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 148, 1, 305, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 296 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 149, 1, 306, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 297 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 150, 1, 307, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 298 */ 5, CNA_BEHAVIOR_SEND, 66, 3, 151, 1, 308, 1}, /* ACOffReq_TC */
    {/* Index 299 */ 5, CNA_BEHAVIOR_NONE, 47, 3, 152, 0, 309, 1}, /* BattSaveDelayTimeSet */
    {/* Index 300 */ 5, CNA_BEHAVIOR_NONE, 57, 3, 152, 0, 310, 1}, /* ChairMemPosnEna */
    {/* Index 301 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 152, 0, 311, 1}, /* DomeLmpDlyTimSet */
    {/* Index 302 */ 5, CNA_BEHAVIOR_NONE, 56, 3, 152, 0, 312, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 303 */ 5, CNA_BEHAVIOR_NONE, 45, 3, 152, 0, 313, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 304 */ 5, CNA_BEHAVIOR_NONE, 48, 3, 152, 0, 314, 1}, /* RearviewFoldModSet */
    {/* Index 305 */ 5, CNA_BEHAVIOR_NONE, 67, 3, 152, 0, 315, 1}, /* TranPMode_Req */
    {/* Index 306 */ 5, CNA_BEHAVIOR_NONE, 72, 4, 152, 0, 316, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 307 */ 5, CNA_BEHAVIOR_NONE, 69, 4, 152, 0, 317, 1}, /* AMP_BeepSourceSet */
    {/* Index 308 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 152, 0, 318, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 309 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 152, 0, 319, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 310 */ 5, CNA_BEHAVIOR_NONE, 73, 4, 152, 0, 320, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 311 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 152, 0, 321, 1}, /* AMP_LRDrvSideSet */
    {/* Index 312 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 152, 0, 322, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 313 */ 5, CNA_BEHAVIOR_NONE, 71, 4, 152, 0, 323, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 314 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 152, 0, 324, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 315 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 152, 0, 325, 1}, /* AMP_MuteSet */
    {/* Index 316 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 152, 0, 326, 1}, /* AMP_NaviSourceSet */
    {/* Index 317 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 152, 0, 327, 1}, /* ANCSwtSet */
    {/* Index 318 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 152, 0, 328, 1}, /* QLISurroundSet */
    {/* Index 319 */ 5, CNA_BEHAVIOR_SEND, 80, 4, 152, 1, 329, 1}, /* RearWinHeatCmd_TC */
    {/* Index 320 */ 5, CNA_BEHAVIOR_NONE, 83, 4, 153, 0, 330, 1}, /* T_BOX_ECallSet */
    {/* Index 321 */ 5, CNA_BEHAVIOR_NONE, 70, 4, 153, 0, 331, 1}, /* ThunStoKTVSourSet */
    {/* Index 322 */ 5, CNA_BEHAVIOR_NONE, 94, 5, 153, 0, 332, 1}, /* AMP_BestListegPosnReq */
    {/* Index 323 */ 5, CNA_BEHAVIOR_NONE, 97, 5, 153, 0, 333, 1}, /* AMP_Clari_FiReq */
    {/* Index 324 */ 5, CNA_BEHAVIOR_SEND, 98, 5, 153, 1, 334, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 325 */ 5, CNA_BEHAVIOR_SEND, 91, 5, 154, 1, 335, 1}, /* AMP_GetHWInfoReq */
    {/* Index 326 */ 5, CNA_BEHAVIOR_SEND, 95, 5, 155, 1, 336, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 327 */ 5, CNA_BEHAVIOR_SEND, 92, 5, 156, 1, 337, 1}, /* AMP_GetSWInfoReq */
    {/* Index 328 */ 5, CNA_BEHAVIOR_SEND, 96, 5, 157, 1, 338, 1}, /* AMP_GetTempInfoReq */
    {/* Index 329 */ 5, CNA_BEHAVIOR_NONE, 87, 5, 158, 0, 339, 1}, /* AMP_HFMVolSet */
    {/* Index 330 */ 5, CNA_BEHAVIOR_NONE, 90, 5, 158, 0, 340, 1}, /* AMP_MainVolSet */
    {/* Index 331 */ 5, CNA_BEHAVIOR_NONE, 89, 5, 158, 0, 341, 1}, /* AMP_NaviVolSet */
    {/* Index 332 */ 5, CNA_BEHAVIOR_NONE, 88, 5, 158, 0, 342, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 333 */ 5, CNA_BEHAVIOR_NONE, 86, 5, 158, 0, 343, 1}, /* IESS_MdlInfoReq */
    {/* Index 334 */ 5, CNA_BEHAVIOR_NONE, 93, 5, 158, 0, 344, 1}, /* IESS_MdlSwtReq */
    {/* Index 335 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 158, 1, 345, 1}, /* ACAirInletReq_VR */
    {/* Index 336 */ 5, CNA_BEHAVIOR_SEND, 106, 6, 159, 1, 346, 1}, /* ACAutoModReq_VR */
    {/* Index 337 */ 5, CNA_BEHAVIOR_SEND, 107, 6, 160, 1, 347, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 338 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 161, 1, 348, 1}, /* ACCmprReq_VR */
    {/* Index 339 */ 5, CNA_BEHAVIOR_SEND, 113, 6, 162, 1, 349, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 340 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 163, 1, 350, 1}, /* ACDrvTempReq_VR */
    {/* Index 341 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 164, 1, 351, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 342 */ 5, CNA_BEHAVIOR_NONE, 114, 6, 165, 0, 352, 1}, /* ACModReq_HUT */
    {/* Index 343 */ 5, CNA_BEHAVIOR_SEND, 108, 6, 165, 1, 353, 1}, /* ACPowerReq_VR */
    {/* Index 344 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 166, 0, 354, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 345 */ 5, CNA_BEHAVIOR_NONE, 102, 6, 166, 0, 355, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 346 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 166, 0, 356, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 347 */ 5, CNA_BEHAVIOR_NONE, 105, 6, 166, 0, 357, 1}, /* PassSeatVentnLvlSet */
    {/* Index 348 */ 5, CNA_BEHAVIOR_NONE, 100, 6, 166, 0, 358, 1}, /* RLSeatHeatgLvlSet */
    {/* Index 349 */ 5, CNA_BEHAVIOR_NONE, 101, 6, 166, 0, 359, 1}, /* RRSeatHeatgLvlSet */
    {/* Index 350 */ 5, CNA_BEHAVIOR_SEND, 115, 6, 166, 1, 360, 1}, /* RemUpgrdSts */
    {/* Index 351 */ 5, CNA_BEHAVIOR_CYCLE, 488, 38, 167, 1, 361, 1}, /* RearFogLmpSwtSts_HUT */
    {/* Index 352 */ 5, CNA_BEHAVIOR_CYCLE, 344, 26, 168, 1, 362, 1}, /* ContnPrkgReq */
    {/* Index 353 */ 5, CNA_BEHAVIOR_CYCLE, 355, 26, 169, 1, 363, 1}, /* PrkStraightModSel_HUT */
    {/* Index 354 */ 5, CNA_BEHAVIOR_CYCLE, 349, 26, 170, 1, 364, 1}, /* PrkStraightStrtReq_HUT */
    {/* Index 355 */ 5, CNA_BEHAVIOR_CYCLE, 342, 26, 171, 1, 365, 1}, /* PrkStraightSwtReq_HUT */
    {/* Index 356 */ 5, CNA_BEHAVIOR_CYCLE, 343, 26, 172, 1, 366, 1}, /* PrkgCtrlModReq */
    {/* Index 357 */ 5, CNA_BEHAVIOR_CYCLE, 566, 42, 173, 1, 367, 1}, /* ChairMemPosnSet */
    {/* Index 358 */ 5, CNA_BEHAVIOR_CYCLE, 545, 42, 174, 1, 368, 1}, /* EPSSteerModSwtReq */
    {/* Index 359 */ 5, CNA_BEHAVIOR_CYCLE, 177, 11, 175, 1, 369, 1}, /* DampgDrvModeReq */
    {/* Index 360 */ 5, CNA_BEHAVIOR_CYCLE, 176, 11, 176, 1, 370, 1}, /* HUT_AVHSwitchSts */
    {/* Index 361 */ 5, CNA_BEHAVIOR_CYCLE, 174, 11, 177, 1, 371, 1}, /* HUT_EPB_SwtPosn */
    {/* Index 362 */ 5, CNA_BEHAVIOR_CYCLE, 175, 11, 178, 1, 372, 1}, /* HUT_HDCSwitchCtrl */
    {/* Index 363 */ 5, CNA_BEHAVIOR_CYCLE, 168, 11, 179, 1, 373, 1}, /* HUT_VehSpdLimAdj */
    {/* Index 364 */ 5, CNA_BEHAVIOR_CYCLE, 171, 11, 180, 1, 374, 1}, /* ORVMFoldSwt_HUT */
    {/* Index 365 */ 5, CNA_BEHAVIOR_CYCLE, 393, 28, 181, 1, 375, 1}, /* AppModeFB */
};

static CNA_SignalType cna_signalDatas[366] = {0u};
static const uint8 cna_noActionBuffer[182] =
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
    0u,
    0u,
    0u,
    3u,
    3u,
    0u,
    0u,
    0u,
    255u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[718] =
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
    303,
    301,
    299,
    304,
    285,
    286,
    292,
    293,
    295,
    288,
    284,
    302,
    300,
    290,
    289,
    294,
    283,
    297,
    296,
    291,
    287,
    298,
    305,
    65535,
    307,
    321,
    313,
    306,
    310,
    311,
    308,
    315,
    312,
    317,
    316,
    319,
    314,
    318,
    320,
    309,
    65535,
    333,
    329,
    332,
    331,
    330,
    325,
    327,
    334,
    322,
    326,
    328,
    323,
    324,
    65535,
    348,
    349,
    345,
    346,
    344,
    347,
    336,
    337,
    343,
    338,
    341,
    340,
    335,
    339,
    342,
    350,
    65535,
    18,
    11,
    10,
    17,
    24,
    23,
    19,
    15,
    22,
    13,
    27,
    12,
    25,
    26,
    16,
    20,
    21,
    14,
    65535,
    7,
    0,
    5,
    4,
    1,
    3,
    2,
    9,
    6,
    8,
    65535,
    250,
    257,
    253,
    241,
    242,
    251,
    252,
    247,
    254,
    245,
    244,
    246,
    248,
    243,
    256,
    240,
    255,
    249,
    65535,
    65535,
    65535,
    363,
    65535,
    65535,
    364,
    65535,
    65535,
    361,
    362,
    360,
    359,
    65535,
    146,
    147,
    135,
    134,
    142,
    144,
    139,
    130,
    140,
    131,
    145,
    136,
    132,
    137,
    133,
    143,
    149,
    148,
    141,
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
    281,
    275,
    272,
    282,
    271,
    278,
    277,
    273,
    274,
    276,
    279,
    280,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    234,
    233,
    235,
    232,
    238,
    237,
    231,
    236,
    239,
    65535,
    224,
    223,
    225,
    221,
    228,
    227,
    220,
    226,
    222,
    219,
    229,
    230,
    65535,
    212,
    209,
    214,
    203,
    218,
    216,
    201,
    200,
    217,
    208,
    215,
    207,
    202,
    213,
    206,
    205,
    210,
    211,
    204,
    65535,
    191,
    188,
    193,
    184,
    199,
    195,
    197,
    186,
    194,
    185,
    183,
    192,
    198,
    189,
    190,
    196,
    187,
    65535,
    268,
    267,
    259,
    260,
    270,
    263,
    265,
    266,
    261,
    258,
    262,
    264,
    269,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    83,
    84,
    82,
    72,
    78,
    74,
    73,
    75,
    77,
    79,
    81,
    76,
    80,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    355,
    356,
    352,
    65535,
    65535,
    65535,
    65535,
    354,
    65535,
    65535,
    65535,
    65535,
    65535,
    353,
    65535,
    65535,
    65535,
    116,
    112,
    123,
    115,
    121,
    122,
    119,
    111,
    126,
    129,
    114,
    128,
    113,
    127,
    124,
    120,
    117,
    108,
    106,
    107,
    109,
    125,
    110,
    118,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    365,
    65535,
    54,
    53,
    52,
    50,
    51,
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
    105,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    65535,
    63,
    64,
    65,
    67,
    69,
    70,
    68,
    71,
    66,
    65535,
    87,
    88,
    90,
    93,
    95,
    91,
    96,
    94,
    85,
    86,
    89,
    97,
    92,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    176,
    172,
    168,
    175,
    162,
    166,
    171,
    173,
    169,
    161,
    170,
    177,
    167,
    174,
    165,
    178,
    163,
    164,
    160,
    65535,
    159,
    157,
    158,
    65535,
    179,
    181,
    180,
    182,
    65535,
    65535,
    65535,
    65535,
    65535,
    351,
    65535,
    65535,
    40,
    47,
    44,
    45,
    41,
    43,
    42,
    46,
    65535,
    152,
    150,
    151,
    65535,
    155,
    156,
    153,
    154,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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
    357,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    33,
    28,
    36,
    34,
    35,
    37,
    38,
    39,
    29,
    30,
    31,
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
};

static uint8 cna_currentBuffer[376] = {0};

const CNA_ConfigType cna_config =
{
    366u,
    cna_signalConfigs,
    cna_signalDatas,
    182u,
    cna_noActionBuffer,
    376u,
    cna_currentBuffer,
    718u,
    CNA_IdTable
};


