/**
 ********************************************************************************************************************
 * @file:      ComNoAction_Cfg.c
 * @author:    ComNoAction Generator
 * @date:      2020-9-26
 * @brief:   
 ********************************************************************************************************************
 * @attention: 
 *    1. date    : 2020-9-26
 *       author  : ComNoAction Generator
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
#ifndef SWC_IPC_CAN_MATRIX_P01H
    #include "SWC_IPC_CANMatrix_P01.h"
    #if (0xbdf5db77 != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
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
    {/* Index 0 */ 5, CNA_BEHAVIOR_SEND, 147, 8, 0, 1, 0, 1}, /* HUT_VMDRInitAlarmDlySet */
    {/* Index 1 */ 5, CNA_BEHAVIOR_SEND, 146, 8, 1, 1, 1, 1}, /* HUT_VMDRTmpMonFctnSet */
    {/* Index 2 */ 5, CNA_BEHAVIOR_UNSEND, 148, 8, 2, 1, 2, 1}, /* OTA_UpgrdModReq */
    {/* Index 3 */ 5, CNA_BEHAVIOR_SEND, 128, 7, 3, 1, 3, 1}, /* AUTODefrost_TC */
    {/* Index 4 */ 5, CNA_BEHAVIOR_SEND, 129, 7, 4, 1, 4, 1}, /* AUTODefrost_VR */
    {/* Index 5 */ 5, CNA_BEHAVIOR_SEND, 140, 7, 5, 1, 5, 1}, /* AutoAVMSwSet_Cmd */
    {/* Index 6 */ 5, CNA_BEHAVIOR_SEND, 136, 7, 6, 1, 6, 1}, /* AutoViewChgCmd */
    {/* Index 7 */ 5, CNA_BEHAVIOR_SEND, 139, 7, 7, 1, 7, 1}, /* CarMdlDispCmd */
    {/* Index 8 */ 5, CNA_BEHAVIOR_SEND, 138, 7, 8, 1, 8, 1}, /* CarMdlTrsprcySwtCmd */
    {/* Index 9 */ 5, CNA_BEHAVIOR_SEND, 141, 7, 9, 1, 9, 1}, /* FPAS_AutoModSwt */
    {/* Index 10 */ 5, CNA_BEHAVIOR_SEND, 133, 7, 10, 1, 10, 1}, /* Guid_Ovl_Display_Cmd */
    {/* Index 11 */ 5, CNA_BEHAVIOR_SEND, 130, 7, 11, 1, 11, 1}, /* LaneCalActvtCmd */
    {/* Index 12 */ 5, CNA_BEHAVIOR_SEND, 142, 7, 12, 1, 12, 1}, /* MEBSwtSet */
    {/* Index 13 */ 5, CNA_BEHAVIOR_SEND, 131, 7, 13, 1, 13, 1}, /* MODChgReq */
    {/* Index 14 */ 5, CNA_BEHAVIOR_SEND, 137, 7, 14, 1, 14, 1}, /* MdlColrChgCmd */
    {/* Index 15 */ 5, CNA_BEHAVIOR_SEND, 132, 7, 15, 1, 15, 1}, /* Radar_DispCmd */
    {/* Index 16 */ 5, CNA_BEHAVIOR_SEND, 134, 7, 16, 1, 16, 1}, /* Sgl_View_Sel */
    {/* Index 17 */ 5, CNA_BEHAVIOR_SEND, 135, 7, 17, 1, 17, 1}, /* SwToFieldCalRstCmd */
    {/* Index 18 */ 5, CNA_BEHAVIOR_SEND, 144, 7, 18, 1, 18, 1}, /* View_SoftswitchCmd */
    {/* Index 19 */ 5, CNA_BEHAVIOR_SEND, 143, 7, 19, 1, 19, 1}, /* WshSoftSwt */
    {/* Index 20 */ 5, CNA_BEHAVIOR_SEND, 607, 38, 20, 1, 20, 1}, /* SlotNum_VR */
    {/* Index 21 */ 5, CNA_BEHAVIOR_NONE, 609, 39, 21, 0, 21, 64}, /* HUT_ExternalDevice */
    {/* Index 22 */ 5, CNA_BEHAVIOR_SEND, 436, 32, 21, 1, 85, 1}, /* DrvSeatMassgModSet */
    {/* Index 23 */ 5, CNA_BEHAVIOR_UNSEND, 437, 32, 22, 1, 86, 1}, /* PPMI_P_BSR_SwtSet */
    {/* Index 24 */ 5, CNA_BEHAVIOR_SEND, 435, 32, 23, 1, 87, 1}, /* PassSeatMassgModSet */
    {/* Index 25 */ 5, CNA_BEHAVIOR_UNSEND, 438, 32, 24, 1, 88, 1}, /* RWPC_SwtReq */
    {/* Index 26 */ 5, CNA_BEHAVIOR_UNSEND, 442, 33, 25, 1, 89, 1}, /* AGSSwtReq */
    {/* Index 27 */ 5, CNA_BEHAVIOR_UNSEND, 440, 33, 26, 1, 90, 1}, /* ARFSwtReq */
    {/* Index 28 */ 5, CNA_BEHAVIOR_UNSEND, 441, 33, 27, 1, 91, 1}, /* ASFCSwtReq */
    {/* Index 29 */ 5, CNA_BEHAVIOR_UNSEND, 443, 33, 28, 1, 92, 1}, /* SOCMngmntSwtReq */
    {/* Index 30 */ 5, CNA_BEHAVIOR_NONE, 388, 27, 29, 0, 93, 1}, /* ACDrvTempDecReq_ETC_TC */
    {/* Index 31 */ 5, CNA_BEHAVIOR_NONE, 389, 27, 29, 0, 94, 1}, /* ACDrvTempIncReq_ETC_TC */
    {/* Index 32 */ 5, CNA_BEHAVIOR_SEND, 394, 27, 29, 1, 95, 1}, /* ACMaxReq_TC */
    {/* Index 33 */ 5, CNA_BEHAVIOR_SEND, 393, 27, 30, 1, 96, 1}, /* ACMaxReq_VR */
    {/* Index 34 */ 5, CNA_BEHAVIOR_SEND, 396, 27, 31, 1, 97, 1}, /* ACRearAutoModReq_VR */
    {/* Index 35 */ 5, CNA_BEHAVIOR_SEND, 398, 27, 32, 1, 98, 1}, /* ACRearLockReq_TC */
    {/* Index 36 */ 5, CNA_BEHAVIOR_SEND, 392, 27, 33, 1, 99, 1}, /* ACRearPowerReq_VR */
    {/* Index 37 */ 5, CNA_BEHAVIOR_NONE, 390, 27, 34, 0, 100, 1}, /* ACRearTempDecReq_ETC_TC */
    {/* Index 38 */ 5, CNA_BEHAVIOR_NONE, 391, 27, 34, 0, 101, 1}, /* ACRearTempIncReq_ETC_TC */
    {/* Index 39 */ 5, CNA_BEHAVIOR_NONE, 386, 27, 34, 0, 102, 1}, /* ACRearTempReq_ETC_VR */
    {/* Index 40 */ 5, CNA_BEHAVIOR_NONE, 387, 27, 34, 0, 103, 1}, /* ACRearTempSteplsReq_ETC_TC */
    {/* Index 41 */ 5, CNA_BEHAVIOR_UNSEND, 399, 27, 34, 1, 104, 1}, /* DPF_Request */
    {/* Index 42 */ 5, CNA_BEHAVIOR_NONE, 395, 27, 35, 0, 105, 1}, /* FrntWiprCtrl_VR */
    {/* Index 43 */ 5, CNA_BEHAVIOR_NONE, 397, 27, 35, 0, 106, 1}, /* LockWinSet */
    {/* Index 44 */ 5, CNA_BEHAVIOR_NONE, 414, 28, 35, 0, 107, 1}, /* ACFrntWinHeatCmd_TC */
    {/* Index 45 */ 5, CNA_BEHAVIOR_NONE, 415, 28, 35, 0, 108, 1}, /* ACFrntWinHeatCmd_VR */
    {/* Index 46 */ 5, CNA_BEHAVIOR_NONE, 409, 28, 35, 0, 109, 1}, /* ACHumidifierReq_TC */
    {/* Index 47 */ 5, CNA_BEHAVIOR_NONE, 408, 28, 35, 0, 110, 1}, /* ACHumidifierReq_VR */
    {/* Index 48 */ 5, CNA_BEHAVIOR_NONE, 410, 28, 35, 0, 111, 1}, /* ACOzoneReq_TC */
    {/* Index 49 */ 5, CNA_BEHAVIOR_NONE, 411, 28, 35, 0, 112, 1}, /* ACOzoneReq_VR */
    {/* Index 50 */ 5, CNA_BEHAVIOR_SEND, 401, 28, 35, 1, 113, 1}, /* ACRLTempDecReq_TC */
    {/* Index 51 */ 5, CNA_BEHAVIOR_SEND, 402, 28, 36, 1, 114, 1}, /* ACRLTempIncReq_TC */
    {/* Index 52 */ 5, CNA_BEHAVIOR_SEND, 403, 28, 37, 1, 115, 1}, /* ACRLTempReq_VR */
    {/* Index 53 */ 5, CNA_BEHAVIOR_SEND, 404, 28, 38, 1, 116, 1}, /* ACRRTempDecReq_TC */
    {/* Index 54 */ 5, CNA_BEHAVIOR_SEND, 405, 28, 39, 1, 117, 1}, /* ACRRTempIncReq_TC */
    {/* Index 55 */ 5, CNA_BEHAVIOR_SEND, 406, 28, 40, 1, 118, 1}, /* ACRRTempReq_VR */
    {/* Index 56 */ 5, CNA_BEHAVIOR_SEND, 407, 28, 41, 1, 119, 1}, /* ACRRTempSteplsReq_TC */
    {/* Index 57 */ 5, CNA_BEHAVIOR_SEND, 412, 28, 42, 1, 120, 1}, /* ACUltravioletReq_TC */
    {/* Index 58 */ 5, CNA_BEHAVIOR_SEND, 413, 28, 43, 1, 121, 1}, /* ACUltravioletReq_VR */
    {/* Index 59 */ 5, CNA_BEHAVIOR_SEND, 311, 22, 44, 1, 122, 1}, /* BackReq_AVM */
    {/* Index 60 */ 5, CNA_BEHAVIOR_NONE, 316, 22, 45, 0, 123, 1}, /* DeleteUserIDFaceData */
    {/* Index 61 */ 5, CNA_BEHAVIOR_NONE, 320, 22, 45, 0, 124, 1}, /* DistrctnDetnSet */
    {/* Index 62 */ 5, CNA_BEHAVIOR_NONE, 321, 22, 45, 0, 125, 1}, /* DrowsnsDetnSet */
    {/* Index 63 */ 5, CNA_BEHAVIOR_NONE, 314, 22, 45, 0, 126, 1}, /* EnrollFaceReq */
    {/* Index 64 */ 5, CNA_BEHAVIOR_NONE, 315, 22, 45, 0, 127, 1}, /* EnrollUserIDResult */
    {/* Index 65 */ 5, CNA_BEHAVIOR_NONE, 317, 22, 45, 0, 128, 1}, /* EraseAllFaceUsersReq */
    {/* Index 66 */ 5, CNA_BEHAVIOR_NONE, 319, 22, 45, 0, 129, 1}, /* FaceIdnSet */
    {/* Index 67 */ 5, CNA_BEHAVIOR_SEND, 309, 22, 45, 1, 130, 1}, /* HUD_BrightnessLvlSwt */
    {/* Index 68 */ 5, CNA_BEHAVIOR_SEND, 308, 22, 46, 1, 131, 1}, /* HUD_HeightLvlSwt */
    {/* Index 69 */ 5, CNA_BEHAVIOR_SEND, 310, 22, 47, 1, 132, 1}, /* HUD_SwtReq */
    {/* Index 70 */ 5, CNA_BEHAVIOR_NONE, 318, 22, 48, 0, 133, 1}, /* IdnResultReq_HUT */
    {/* Index 71 */ 5, CNA_BEHAVIOR_UNSEND, 313, 22, 48, 1, 134, 1}, /* PPMIBSRSwtSet */
    {/* Index 72 */ 5, CNA_BEHAVIOR_UNSEND, 312, 22, 49, 1, 135, 1}, /* PPMIHWSwtSet */
    {/* Index 73 */ 5, CNA_BEHAVIOR_NONE, 417, 29, 50, 0, 136, 1}, /* ActvEntryLockSet */
    {/* Index 74 */ 5, CNA_BEHAVIOR_NONE, 418, 29, 50, 0, 137, 1}, /* ActvEntryUnlockSet */
    {/* Index 75 */ 5, CNA_BEHAVIOR_NONE, 420, 29, 50, 0, 138, 1}, /* BTAPAEntryLockSet */
    {/* Index 76 */ 5, CNA_BEHAVIOR_NONE, 421, 29, 50, 0, 139, 1}, /* BTAPALvngUnlockSet */
    {/* Index 77 */ 5, CNA_BEHAVIOR_NONE, 422, 29, 50, 0, 140, 1}, /* ClsWinSpdSet */
    {/* Index 78 */ 5, CNA_BEHAVIOR_SEND, 423, 29, 50, 1, 141, 1}, /* DrvSeatMassgLvlSet */
    {/* Index 79 */ 5, CNA_BEHAVIOR_NONE, 419, 29, 51, 0, 142, 1}, /* LockPromptFunSet */
    {/* Index 80 */ 5, CNA_BEHAVIOR_NONE, 428, 29, 51, 0, 143, 1}, /* OilBoxSplyReq */
    {/* Index 81 */ 5, CNA_BEHAVIOR_SEND, 424, 29, 51, 1, 144, 1}, /* PassSeatMassgLvlSet */
    {/* Index 82 */ 5, CNA_BEHAVIOR_SEND, 426, 29, 52, 1, 145, 1}, /* RLSeatMassgLvlSet */
    {/* Index 83 */ 5, CNA_BEHAVIOR_SEND, 427, 29, 53, 1, 146, 1}, /* RRSeatMassgLvlSet */
    {/* Index 84 */ 5, CNA_BEHAVIOR_NONE, 425, 29, 54, 0, 147, 1}, /* SeatKeyMemEna */
    {/* Index 85 */ 5, CNA_BEHAVIOR_SEND, 371, 25, 54, 1, 148, 1}, /* ACFGAChanTyp_TC */
    {/* Index 86 */ 5, CNA_BEHAVIOR_SEND, 370, 25, 55, 1, 149, 1}, /* ACFGAEnaReq_TC */
    {/* Index 87 */ 5, CNA_BEHAVIOR_SEND, 372, 25, 56, 1, 150, 1}, /* ACFGALvlReq_TC */
    {/* Index 88 */ 6, CNA_BEHAVIOR_NONE, 348, 25, 57, 0, 151, 1}, /* ADASDispSwt */
    {/* Index 89 */ 6, CNA_BEHAVIOR_NONE, 351, 25, 57, 0, 152, 1}, /* ADASDispSwt_VR */
    {/* Index 90 */ 6, CNA_BEHAVIOR_NONE, 354, 25, 57, 0, 153, 1}, /* ALCMDynModSet */
    {/* Index 91 */ 6, CNA_BEHAVIOR_UNSEND, 352, 25, 57, 1, 154, 1}, /* ApproachLampSet */
    {/* Index 92 */ 5, CNA_BEHAVIOR_SEND, 369, 25, 58, 1, 155, 1}, /* BackReq_APS */
    {/* Index 93 */ 6, CNA_BEHAVIOR_SEND, 359, 25, 59, 1, 156, 1}, /* ChairMemPosnSetSwt */
    {/* Index 94 */ 5, CNA_BEHAVIOR_SEND, 366, 25, 60, 1, 157, 1}, /* DeletePath1Cmd */
    {/* Index 95 */ 5, CNA_BEHAVIOR_SEND, 364, 25, 61, 1, 158, 1}, /* DeletePath2Cmd */
    {/* Index 96 */ 6, CNA_BEHAVIOR_NONE, 373, 25, 62, 0, 159, 1}, /* DrvSeatHeatgRmdTempSet */
    {/* Index 97 */ 6, CNA_BEHAVIOR_SEND, 357, 25, 62, 1, 160, 1}, /* DrvWinSwtReq_VR */
    {/* Index 98 */ 6, CNA_BEHAVIOR_UNSEND, 346, 25, 63, 1, 161, 1}, /* FlaoutUnlockSet */
    {/* Index 99 */ 6, CNA_BEHAVIOR_NONE, 349, 25, 64, 0, 162, 1}, /* NaviDispSwt */
    {/* Index 100 */ 6, CNA_BEHAVIOR_NONE, 350, 25, 64, 0, 163, 1}, /* NaviDispSwt_VR */
    {/* Index 101 */ 5, CNA_BEHAVIOR_SEND, 368, 25, 64, 1, 164, 1}, /* ParkMdlCmd */
    {/* Index 102 */ 6, CNA_BEHAVIOR_SEND, 358, 25, 65, 1, 165, 1}, /* PassWinSwtReq_VR */
    {/* Index 103 */ 5, CNA_BEHAVIOR_SEND, 360, 25, 66, 1, 166, 1}, /* PathLrngFinshCmd */
    {/* Index 104 */ 5, CNA_BEHAVIOR_SEND, 361, 25, 67, 1, 167, 1}, /* PathLrngStartCmd */
    {/* Index 105 */ 6, CNA_BEHAVIOR_NONE, 347, 25, 68, 0, 168, 1}, /* PrkInDirChoice */
    {/* Index 106 */ 6, CNA_BEHAVIOR_SEND, 355, 25, 68, 1, 169, 1}, /* RLWinSwtReq_VR */
    {/* Index 107 */ 6, CNA_BEHAVIOR_SEND, 356, 25, 69, 1, 170, 1}, /* RRWinSwtReq_VR */
    {/* Index 108 */ 5, CNA_BEHAVIOR_SEND, 362, 25, 70, 1, 171, 1}, /* SelPrkOutDirReq */
    {/* Index 109 */ 5, CNA_BEHAVIOR_SEND, 367, 25, 71, 1, 172, 1}, /* SelPrkgFctnCmd */
    {/* Index 110 */ 5, CNA_BEHAVIOR_SEND, 365, 25, 72, 1, 173, 1}, /* StartPrkgPath1Cmd */
    {/* Index 111 */ 5, CNA_BEHAVIOR_SEND, 363, 25, 73, 1, 174, 1}, /* StartPrkgPath2Cmd */
    {/* Index 112 */ 6, CNA_BEHAVIOR_UNSEND, 353, 25, 74, 1, 175, 1}, /* SuperLockSet */
    {/* Index 113 */ 5, CNA_BEHAVIOR_NONE, 188, 12, 75, 0, 176, 1}, /* ABSLmpSet */
    {/* Index 114 */ 5, CNA_BEHAVIOR_SEND, 180, 12, 75, 1, 177, 1}, /* ACDrvSetTempSteplsReq_TC */
    {/* Index 115 */ 5, CNA_BEHAVIOR_SEND, 178, 12, 76, 1, 178, 1}, /* ACOperMod_TC */
    {/* Index 116 */ 5, CNA_BEHAVIOR_SEND, 179, 12, 77, 1, 179, 1}, /* ACOperMod_VR */
    {/* Index 117 */ 5, CNA_BEHAVIOR_SEND, 181, 12, 78, 1, 180, 1}, /* ACPassSetTempSteplsReq_TC */
    {/* Index 118 */ 5, CNA_BEHAVIOR_SEND, 184, 12, 79, 1, 181, 1}, /* APSPrkgTypSeln */
    {/* Index 119 */ 5, CNA_BEHAVIOR_SEND, 183, 12, 80, 1, 182, 1}, /* APSSwtReq_VR */
    {/* Index 120 */ 5, CNA_BEHAVIOR_NONE, 189, 12, 81, 0, 183, 1}, /* AutoWshWipSet */
    {/* Index 121 */ 5, CNA_BEHAVIOR_NONE, 193, 12, 81, 0, 184, 1}, /* DoorUnlockModSet */
    {/* Index 122 */ 5, CNA_BEHAVIOR_NONE, 196, 12, 81, 0, 185, 1}, /* FrntRearACDispSts */
    {/* Index 123 */ 5, CNA_BEHAVIOR_SEND, 195, 12, 81, 1, 186, 1}, /* PASExitSpdSwt */
    {/* Index 124 */ 5, CNA_BEHAVIOR_NONE, 192, 12, 82, 0, 187, 1}, /* ParkLmpSet */
    {/* Index 125 */ 5, CNA_BEHAVIOR_SEND, 182, 12, 82, 1, 188, 1}, /* SDWSwtSet */
    {/* Index 126 */ 5, CNA_BEHAVIOR_NONE, 190, 12, 83, 0, 189, 1}, /* SeekVehSet */
    {/* Index 127 */ 5, CNA_BEHAVIOR_NONE, 191, 12, 83, 0, 190, 1}, /* SpdAutoLockModSet */
    {/* Index 128 */ 5, CNA_BEHAVIOR_NONE, 187, 12, 83, 0, 191, 1}, /* SportModLightSet */
    {/* Index 129 */ 5, CNA_BEHAVIOR_SEND, 194, 12, 83, 1, 192, 1}, /* SteerWheelHeatSwtReq */
    {/* Index 130 */ 5, CNA_BEHAVIOR_SEND, 186, 12, 84, 1, 193, 1}, /* SunRoofSwtReq_VR */
    {/* Index 131 */ 5, CNA_BEHAVIOR_SEND, 185, 12, 85, 1, 194, 1}, /* SunShadeSwtReq_VR */
    {/* Index 132 */ 5, CNA_BEHAVIOR_NONE, 446, 34, 86, 0, 195, 1}, /* CallingFuncSetUp */
    {/* Index 133 */ 5, CNA_BEHAVIOR_NONE, 445, 34, 86, 0, 196, 1}, /* SmokeFuncSetUp */
    {/* Index 134 */ 5, CNA_BEHAVIOR_SEND, 430, 30, 86, 1, 197, 1}, /* ACRLTempSteplsReq_TC */
    {/* Index 135 */ 5, CNA_BEHAVIOR_SEND, 432, 31, 87, 1, 198, 1}, /* RLSeatMassgModSet */
    {/* Index 136 */ 5, CNA_BEHAVIOR_SEND, 433, 31, 88, 1, 199, 1}, /* RRSeatMassgModSet */
    {/* Index 137 */ 5, CNA_BEHAVIOR_NONE, 287, 19, 89, 0, 200, 1}, /* ADAS_Stub_CmplxInsct */
    {/* Index 138 */ 5, CNA_BEHAVIOR_NONE, 279, 19, 89, 0, 201, 1}, /* ADAS_Stub_CycCnt */
    {/* Index 139 */ 5, CNA_BEHAVIOR_NONE, 288, 19, 89, 0, 202, 1}, /* ADAS_Stub_FormOfWay */
    {/* Index 140 */ 5, CNA_BEHAVIOR_NONE, 285, 19, 89, 0, 203, 1}, /* ADAS_Stub_FuncRoadClass */
    {/* Index 141 */ 5, CNA_BEHAVIOR_NONE, 290, 19, 89, 0, 204, 1}, /* ADAS_Stub_LastStub */
    {/* Index 142 */ 5, CNA_BEHAVIOR_NONE, 277, 19, 89, 0, 205, 1}, /* ADAS_Stub_MsgTyp */
    {/* Index 143 */ 5, CNA_BEHAVIOR_NONE, 293, 19, 89, 0, 206, 1}, /* ADAS_Stub_NumOfLaneDrvDir */
    {/* Index 144 */ 5, CNA_BEHAVIOR_NONE, 292, 19, 89, 0, 207, 1}, /* ADAS_Stub_NumOfLaneOppDir */
    {/* Index 145 */ 5, CNA_BEHAVIOR_NONE, 278, 19, 89, 0, 208, 2}, /* ADAS_Stub_Offset */
    {/* Index 146 */ 5, CNA_BEHAVIOR_NONE, 286, 19, 89, 0, 210, 1}, /* ADAS_Stub_PartOfCalcRoute */
    {/* Index 147 */ 5, CNA_BEHAVIOR_NONE, 280, 19, 89, 0, 211, 1}, /* ADAS_Stub_PathIdx */
    {/* Index 148 */ 5, CNA_BEHAVIOR_NONE, 284, 19, 89, 0, 212, 1}, /* ADAS_Stub_RelProbb */
    {/* Index 149 */ 5, CNA_BEHAVIOR_NONE, 282, 19, 89, 0, 213, 1}, /* ADAS_Stub_Retr */
    {/* Index 150 */ 5, CNA_BEHAVIOR_NONE, 291, 19, 89, 0, 214, 1}, /* ADAS_Stub_RtOfWay */
    {/* Index 151 */ 5, CNA_BEHAVIOR_NONE, 281, 19, 89, 0, 215, 1}, /* ADAS_Stub_StubPathIdx */
    {/* Index 152 */ 5, CNA_BEHAVIOR_NONE, 289, 19, 89, 0, 216, 1}, /* ADAS_Stub_TurnAngl */
    {/* Index 153 */ 5, CNA_BEHAVIOR_NONE, 283, 19, 89, 0, 217, 1}, /* ADAS_Stub_Update */
    {/* Index 154 */ 5, CNA_BEHAVIOR_NONE, 262, 18, 89, 0, 218, 1}, /* ADAS_Seg_Brdg */
    {/* Index 155 */ 5, CNA_BEHAVIOR_NONE, 263, 18, 89, 0, 219, 1}, /* ADAS_Seg_BuildUpArea */
    {/* Index 156 */ 5, CNA_BEHAVIOR_NONE, 269, 18, 89, 0, 220, 1}, /* ADAS_Seg_CmplxInsct */
    {/* Index 157 */ 5, CNA_BEHAVIOR_NONE, 259, 18, 89, 0, 221, 1}, /* ADAS_Seg_CycCnt */
    {/* Index 158 */ 5, CNA_BEHAVIOR_NONE, 273, 18, 89, 0, 222, 1}, /* ADAS_Seg_DivideRoad */
    {/* Index 159 */ 5, CNA_BEHAVIOR_NONE, 271, 18, 89, 0, 223, 1}, /* ADAS_Seg_EffSpdLmt */
    {/* Index 160 */ 5, CNA_BEHAVIOR_NONE, 272, 18, 89, 0, 224, 1}, /* ADAS_Seg_EffSpdLmtTyp */
    {/* Index 161 */ 5, CNA_BEHAVIOR_NONE, 270, 18, 89, 0, 225, 1}, /* ADAS_Seg_FormOfWay */
    {/* Index 162 */ 5, CNA_BEHAVIOR_NONE, 267, 18, 89, 0, 226, 1}, /* ADAS_Seg_FuncRoadClass */
    {/* Index 163 */ 5, CNA_BEHAVIOR_NONE, 257, 18, 89, 0, 227, 1}, /* ADAS_Seg_MsgTyp */
    {/* Index 164 */ 5, CNA_BEHAVIOR_NONE, 275, 18, 89, 0, 228, 1}, /* ADAS_Seg_NumOfLaneDrvDir */
    {/* Index 165 */ 5, CNA_BEHAVIOR_NONE, 274, 18, 89, 0, 229, 1}, /* ADAS_Seg_NumOfLaneOppDir */
    {/* Index 166 */ 5, CNA_BEHAVIOR_NONE, 258, 18, 89, 0, 230, 2}, /* ADAS_Seg_Offset */
    {/* Index 167 */ 5, CNA_BEHAVIOR_NONE, 268, 18, 89, 0, 232, 1}, /* ADAS_Seg_PartOfCalcRoute */
    {/* Index 168 */ 5, CNA_BEHAVIOR_NONE, 260, 18, 89, 0, 233, 1}, /* ADAS_Seg_PathIdx */
    {/* Index 169 */ 5, CNA_BEHAVIOR_NONE, 266, 18, 89, 0, 234, 1}, /* ADAS_Seg_RelProbb */
    {/* Index 170 */ 5, CNA_BEHAVIOR_NONE, 264, 18, 89, 0, 235, 1}, /* ADAS_Seg_Retr */
    {/* Index 171 */ 5, CNA_BEHAVIOR_NONE, 261, 18, 89, 0, 236, 1}, /* ADAS_Seg_Tunnel */
    {/* Index 172 */ 5, CNA_BEHAVIOR_NONE, 265, 18, 89, 0, 237, 1}, /* ADAS_Seg_Update */
    {/* Index 173 */ 5, CNA_BEHAVIOR_NONE, 252, 17, 89, 0, 238, 1}, /* ADAS_ProfShort_AccurClass */
    {/* Index 174 */ 5, CNA_BEHAVIOR_NONE, 249, 17, 89, 0, 239, 1}, /* ADAS_ProfShort_CtrlPoint */
    {/* Index 175 */ 5, CNA_BEHAVIOR_NONE, 246, 17, 89, 0, 240, 1}, /* ADAS_ProfShort_CycCnt */
    {/* Index 176 */ 5, CNA_BEHAVIOR_NONE, 253, 17, 89, 0, 241, 2}, /* ADAS_ProfShort_Dist1 */
    {/* Index 177 */ 5, CNA_BEHAVIOR_NONE, 244, 17, 89, 0, 243, 1}, /* ADAS_ProfShort_MsgTyp */
    {/* Index 178 */ 5, CNA_BEHAVIOR_NONE, 245, 17, 89, 0, 244, 2}, /* ADAS_ProfShort_Offset */
    {/* Index 179 */ 5, CNA_BEHAVIOR_NONE, 247, 17, 89, 0, 246, 1}, /* ADAS_ProfShort_PathIdx */
    {/* Index 180 */ 5, CNA_BEHAVIOR_NONE, 248, 17, 89, 0, 247, 1}, /* ADAS_ProfShort_ProfTyp */
    {/* Index 181 */ 5, CNA_BEHAVIOR_NONE, 250, 17, 89, 0, 248, 1}, /* ADAS_ProfShort_Retr */
    {/* Index 182 */ 5, CNA_BEHAVIOR_NONE, 251, 17, 89, 0, 249, 1}, /* ADAS_ProfShort_Update */
    {/* Index 183 */ 5, CNA_BEHAVIOR_NONE, 254, 17, 89, 0, 250, 2}, /* ADAS_ProfShort_Value0 */
    {/* Index 184 */ 5, CNA_BEHAVIOR_NONE, 255, 17, 89, 0, 252, 2}, /* ADAS_ProfShort_Value1 */
    {/* Index 185 */ 5, CNA_BEHAVIOR_NONE, 239, 16, 89, 0, 254, 1}, /* ADAS_ProfLong_CtrlPoint */
    {/* Index 186 */ 5, CNA_BEHAVIOR_NONE, 236, 16, 89, 0, 255, 1}, /* ADAS_ProfLong_CycCnt */
    {/* Index 187 */ 5, CNA_BEHAVIOR_NONE, 234, 16, 89, 0, 256, 1}, /* ADAS_ProfLong_MsgTyp */
    {/* Index 188 */ 5, CNA_BEHAVIOR_NONE, 235, 16, 89, 0, 257, 2}, /* ADAS_ProfLong_Offset */
    {/* Index 189 */ 5, CNA_BEHAVIOR_NONE, 237, 16, 89, 0, 259, 1}, /* ADAS_ProfLong_PathIdx */
    {/* Index 190 */ 5, CNA_BEHAVIOR_NONE, 238, 16, 89, 0, 260, 1}, /* ADAS_ProfLong_ProfTyp */
    {/* Index 191 */ 5, CNA_BEHAVIOR_NONE, 240, 16, 89, 0, 261, 1}, /* ADAS_ProfLong_Retr */
    {/* Index 192 */ 5, CNA_BEHAVIOR_NONE, 241, 16, 89, 0, 262, 1}, /* ADAS_ProfLong_Update */
    {/* Index 193 */ 5, CNA_BEHAVIOR_NONE, 242, 16, 89, 0, 263, 4}, /* ADAS_ProfLong_Value */
    {/* Index 194 */ 5, CNA_BEHAVIOR_SEND, 154, 9, 89, 1, 267, 1}, /* ACAIUReq_VR */
    {/* Index 195 */ 5, CNA_BEHAVIOR_SEND, 151, 9, 90, 1, 268, 1}, /* ACAQSReq_VR */
    {/* Index 196 */ 5, CNA_BEHAVIOR_SEND, 150, 9, 91, 1, 269, 1}, /* ACDualReq_VR */
    {/* Index 197 */ 5, CNA_BEHAVIOR_SEND, 153, 9, 92, 1, 270, 1}, /* ACPassTempReq_VR */
    {/* Index 198 */ 5, CNA_BEHAVIOR_SEND, 152, 9, 93, 1, 271, 1}, /* ACRearDefrstReq_VR */
    {/* Index 199 */ 5, CNA_BEHAVIOR_NONE, 157, 9, 94, 0, 272, 1}, /* ALCMClrSet */
    {/* Index 200 */ 5, CNA_BEHAVIOR_NONE, 156, 9, 94, 0, 273, 1}, /* ALCMDynSwt */
    {/* Index 201 */ 5, CNA_BEHAVIOR_NONE, 158, 9, 94, 0, 274, 1}, /* ALCMRhmSwt */
    {/* Index 202 */ 5, CNA_BEHAVIOR_NONE, 155, 9, 94, 0, 275, 1}, /* ALCMStatSwt */
    {/* Index 203 */ 5, CNA_BEHAVIOR_UNSEND, 161, 9, 94, 1, 276, 1}, /* HUT_EgyRecvrySet */
    {/* Index 204 */ 5, CNA_BEHAVIOR_NONE, 159, 9, 95, 0, 277, 1}, /* IPVolSet */
    {/* Index 205 */ 5, CNA_BEHAVIOR_SEND, 160, 9, 95, 1, 278, 1}, /* PASSwtReq_VR */
    {/* Index 206 */ 5, CNA_BEHAVIOR_SEND, 296, 20, 96, 1, 279, 1}, /* ACDrvSetTempReq_ETC_VR */
    {/* Index 207 */ 5, CNA_BEHAVIOR_SEND, 297, 20, 97, 1, 280, 1}, /* ACDrvSetTempSteplsReq_ETC_TC */
    {/* Index 208 */ 5, CNA_BEHAVIOR_NONE, 298, 20, 98, 0, 281, 1}, /* GazeAreaInteractionSetUp */
    {/* Index 209 */ 5, CNA_BEHAVIOR_UNSEND, 301, 20, 98, 1, 282, 1}, /* HUT_BattKeepTemp */
    {/* Index 210 */ 5, CNA_BEHAVIOR_UNSEND, 300, 20, 99, 1, 283, 1}, /* HUT_ChrgnMode */
    {/* Index 211 */ 5, CNA_BEHAVIOR_NONE, 303, 20, 100, 0, 284, 1}, /* HUT_IntelBattTempMagSet */
    {/* Index 212 */ 5, CNA_BEHAVIOR_NONE, 302, 20, 100, 0, 285, 1}, /* HUT_IntelEngIdlChrgnSet */
    {/* Index 213 */ 5, CNA_BEHAVIOR_SEND, 295, 20, 100, 1, 286, 1}, /* HUT_RemtEngCtrl */
    {/* Index 214 */ 5, CNA_BEHAVIOR_NONE, 299, 20, 101, 0, 287, 1}, /* OccptAttrSetUp */
    {/* Index 215 */ 5, CNA_BEHAVIOR_SEND, 216, 14, 101, 1, 288, 1}, /* ACRearAirDistribModReq_VR */
    {/* Index 216 */ 5, CNA_BEHAVIOR_SEND, 213, 14, 102, 1, 289, 1}, /* ACRearBlwrSpdReq_VR */
    {/* Index 217 */ 5, CNA_BEHAVIOR_SEND, 214, 14, 103, 1, 290, 1}, /* ACRearBlwrsteplsSpdReq_TC */
    {/* Index 218 */ 5, CNA_BEHAVIOR_SEND, 217, 14, 104, 1, 291, 1}, /* ACZoneReq_VR */
    {/* Index 219 */ 5, CNA_BEHAVIOR_NONE, 210, 14, 105, 0, 292, 1}, /* AVMMediaVolLvlReq */
    {/* Index 220 */ 5, CNA_BEHAVIOR_NONE, 208, 14, 105, 0, 293, 1}, /* AVMSwtReq */
    {/* Index 221 */ 5, CNA_BEHAVIOR_SEND, 204, 14, 105, 1, 294, 1}, /* BackgroundLightLvlSet */
    {/* Index 222 */ 5, CNA_BEHAVIOR_NONE, 206, 14, 106, 0, 295, 1}, /* DispModSet */
    {/* Index 223 */ 5, CNA_BEHAVIOR_NONE, 211, 14, 106, 0, 296, 1}, /* FPASChanSwtReq */
    {/* Index 224 */ 5, CNA_BEHAVIOR_NONE, 205, 14, 106, 0, 297, 1}, /* ManCmpSet */
    {/* Index 225 */ 5, CNA_BEHAVIOR_NONE, 209, 14, 106, 0, 298, 1}, /* NaviMediaVolLvlReq */
    {/* Index 226 */ 5, CNA_BEHAVIOR_UNSEND, 218, 14, 106, 1, 299, 1}, /* OPDSwtSts */
    {/* Index 227 */ 5, CNA_BEHAVIOR_UNSEND, 215, 14, 107, 1, 300, 1}, /* PLGReq_VR */
    {/* Index 228 */ 5, CNA_BEHAVIOR_NONE, 212, 14, 108, 0, 301, 1}, /* RPASChanSwtReq */
    {/* Index 229 */ 5, CNA_BEHAVIOR_UNSEND, 207, 14, 108, 1, 302, 1}, /* WPC_SwtReq */
    {/* Index 230 */ 5, CNA_BEHAVIOR_SEND, 68, 3, 109, 1, 303, 1}, /* ACAIUReq_TC */
    {/* Index 231 */ 5, CNA_BEHAVIOR_SEND, 54, 3, 110, 1, 304, 1}, /* ACAQSReq_TC */
    {/* Index 232 */ 5, CNA_BEHAVIOR_SEND, 51, 3, 111, 1, 305, 1}, /* ACAirInletReq_TC */
    {/* Index 233 */ 5, CNA_BEHAVIOR_SEND, 50, 3, 112, 1, 306, 1}, /* ACAutoModReq_TC */
    {/* Index 234 */ 5, CNA_BEHAVIOR_SEND, 70, 3, 113, 1, 307, 1}, /* ACBlwrsteplsSpdReq_TC */
    {/* Index 235 */ 5, CNA_BEHAVIOR_SEND, 55, 3, 114, 1, 308, 1}, /* ACCmprReq_TC */
    {/* Index 236 */ 5, CNA_BEHAVIOR_SEND, 62, 3, 115, 1, 309, 1}, /* ACDrvAirDistribModReq_TC */
    {/* Index 237 */ 5, CNA_BEHAVIOR_SEND, 63, 3, 116, 1, 310, 1}, /* ACDrvTempDecReq_TC */
    {/* Index 238 */ 5, CNA_BEHAVIOR_SEND, 65, 3, 117, 1, 311, 1}, /* ACDrvTempIncReq_TC */
    {/* Index 239 */ 5, CNA_BEHAVIOR_SEND, 49, 3, 118, 1, 312, 1}, /* ACDualReq_TC */
    {/* Index 240 */ 5, CNA_BEHAVIOR_SEND, 57, 3, 119, 1, 313, 1}, /* ACFrntBlwrSpdDecReq_TC */
    {/* Index 241 */ 5, CNA_BEHAVIOR_SEND, 61, 3, 120, 1, 314, 1}, /* ACFrntBlwrSpdIncReq_TC */
    {/* Index 242 */ 5, CNA_BEHAVIOR_SEND, 56, 3, 121, 1, 315, 1}, /* ACFrntDefrstReq_TC */
    {/* Index 243 */ 5, CNA_BEHAVIOR_SEND, 52, 3, 122, 1, 316, 1}, /* ACFrntHMIDis_TC */
    {/* Index 244 */ 5, CNA_BEHAVIOR_SEND, 66, 3, 123, 1, 317, 1}, /* ACFrntPassTempDecReq_TC */
    {/* Index 245 */ 5, CNA_BEHAVIOR_SEND, 67, 3, 124, 1, 318, 1}, /* ACFrntPassTempIncReq_TC */
    {/* Index 246 */ 5, CNA_BEHAVIOR_SEND, 69, 3, 125, 1, 319, 1}, /* ACOffReq_TC */
    {/* Index 247 */ 5, CNA_BEHAVIOR_SEND, 58, 3, 126, 1, 320, 1}, /* ACRearBlwrSpdDecReq_TC */
    {/* Index 248 */ 5, CNA_BEHAVIOR_SEND, 59, 3, 127, 1, 321, 1}, /* ACRearBlwrSpdIncReq_TC */
    {/* Index 249 */ 5, CNA_BEHAVIOR_SEND, 53, 3, 128, 1, 322, 1}, /* ACRearHMIDis_TC */
    {/* Index 250 */ 5, CNA_BEHAVIOR_SEND, 71, 3, 129, 1, 323, 1}, /* ACZoneReq_TC */
    {/* Index 251 */ 5, CNA_BEHAVIOR_NONE, 48, 3, 130, 0, 324, 1}, /* BattSaveDelayTimeSet */
    {/* Index 252 */ 5, CNA_BEHAVIOR_NONE, 64, 3, 130, 0, 325, 1}, /* ChairMemPosnEna */
    {/* Index 253 */ 5, CNA_BEHAVIOR_NONE, 44, 3, 130, 0, 326, 1}, /* DomeLmpDlyTimSet */
    {/* Index 254 */ 5, CNA_BEHAVIOR_NONE, 60, 3, 130, 0, 327, 1}, /* DrvDrowsnsDetnSet */
    {/* Index 255 */ 5, CNA_BEHAVIOR_NONE, 45, 3, 130, 0, 328, 1}, /* FolwMeHomeDlyTimSet */
    {/* Index 256 */ 5, CNA_BEHAVIOR_NONE, 47, 3, 130, 0, 329, 1}, /* RearviewFoldModSet */
    {/* Index 257 */ 5, CNA_BEHAVIOR_NONE, 46, 3, 130, 0, 330, 1}, /* TranPMode_Req */
    {/* Index 258 */ 5, CNA_BEHAVIOR_NONE, 78, 4, 130, 0, 331, 1}, /* AMP_AudioVolVSCModReq */
    {/* Index 259 */ 5, CNA_BEHAVIOR_NONE, 76, 4, 130, 0, 332, 1}, /* AMP_BeepSourceSet */
    {/* Index 260 */ 5, CNA_BEHAVIOR_NONE, 79, 4, 130, 0, 333, 1}, /* AMP_FRAudioFaderSet */
    {/* Index 261 */ 5, CNA_BEHAVIOR_NONE, 84, 4, 130, 0, 334, 1}, /* AMP_HighFrqAudioSet */
    {/* Index 262 */ 5, CNA_BEHAVIOR_NONE, 77, 4, 130, 0, 335, 1}, /* AMP_LRAudioBalanceSet */
    {/* Index 263 */ 5, CNA_BEHAVIOR_NONE, 80, 4, 130, 0, 336, 1}, /* AMP_LRDrvSideSet */
    {/* Index 264 */ 5, CNA_BEHAVIOR_NONE, 81, 4, 130, 0, 337, 1}, /* AMP_LowFrqAudioSet */
    {/* Index 265 */ 5, CNA_BEHAVIOR_NONE, 74, 4, 130, 0, 338, 1}, /* AMP_MediaCallSourceSet */
    {/* Index 266 */ 5, CNA_BEHAVIOR_NONE, 83, 4, 130, 0, 339, 1}, /* AMP_MidFrqAudioSet */
    {/* Index 267 */ 5, CNA_BEHAVIOR_NONE, 82, 4, 130, 0, 340, 1}, /* AMP_MuteSet */
    {/* Index 268 */ 5, CNA_BEHAVIOR_NONE, 75, 4, 130, 0, 341, 1}, /* AMP_NaviSourceSet */
    {/* Index 269 */ 5, CNA_BEHAVIOR_NONE, 87, 4, 130, 0, 342, 1}, /* ANCSwtSet */
    {/* Index 270 */ 5, CNA_BEHAVIOR_NONE, 86, 4, 130, 0, 343, 1}, /* QLISurroundSet */
    {/* Index 271 */ 5, CNA_BEHAVIOR_SEND, 73, 4, 130, 1, 344, 1}, /* RearWinHeatCmd_TC */
    {/* Index 272 */ 5, CNA_BEHAVIOR_NONE, 85, 4, 131, 0, 345, 1}, /* T_box_ECallSet */
    {/* Index 273 */ 5, CNA_BEHAVIOR_NONE, 100, 5, 131, 0, 346, 1}, /* AMP_BestListegPosnReq */
    {/* Index 274 */ 5, CNA_BEHAVIOR_NONE, 101, 5, 131, 0, 347, 1}, /* AMP_Clari_FiReq */
    {/* Index 275 */ 5, CNA_BEHAVIOR_SEND, 97, 5, 131, 1, 348, 1}, /* AMP_GetDTCInfoReq */
    {/* Index 276 */ 5, CNA_BEHAVIOR_SEND, 94, 5, 132, 1, 349, 1}, /* AMP_GetHWInfoReq */
    {/* Index 277 */ 5, CNA_BEHAVIOR_SEND, 96, 5, 133, 1, 350, 1}, /* AMP_GetIntVoltInfoReq */
    {/* Index 278 */ 5, CNA_BEHAVIOR_SEND, 93, 5, 134, 1, 351, 1}, /* AMP_GetSWInfoReq */
    {/* Index 279 */ 5, CNA_BEHAVIOR_SEND, 95, 5, 135, 1, 352, 1}, /* AMP_GetTempInfoReq */
    {/* Index 280 */ 5, CNA_BEHAVIOR_NONE, 89, 5, 136, 0, 353, 1}, /* AMP_HFMVolSet */
    {/* Index 281 */ 5, CNA_BEHAVIOR_NONE, 92, 5, 136, 0, 354, 1}, /* AMP_MainVolSet */
    {/* Index 282 */ 5, CNA_BEHAVIOR_NONE, 91, 5, 136, 0, 355, 1}, /* AMP_NaviVolSet */
    {/* Index 283 */ 5, CNA_BEHAVIOR_NONE, 90, 5, 136, 0, 356, 1}, /* AMP_TTSVolSet_VR */
    {/* Index 284 */ 5, CNA_BEHAVIOR_NONE, 99, 5, 136, 0, 357, 1}, /* IESS_MdlInfoReq */
    {/* Index 285 */ 5, CNA_BEHAVIOR_NONE, 98, 5, 136, 0, 358, 1}, /* IESS_MdlSwtReq */
    {/* Index 286 */ 5, CNA_BEHAVIOR_SEND, 112, 6, 136, 1, 359, 1}, /* ACAirInletReq_VR */
    {/* Index 287 */ 5, CNA_BEHAVIOR_SEND, 105, 6, 137, 1, 360, 1}, /* ACAutoModReq_VR */
    {/* Index 288 */ 5, CNA_BEHAVIOR_SEND, 108, 6, 138, 1, 361, 1}, /* ACBlwrSpdReq_VR */
    {/* Index 289 */ 5, CNA_BEHAVIOR_SEND, 106, 6, 139, 1, 362, 1}, /* ACCmprReq_VR */
    {/* Index 290 */ 5, CNA_BEHAVIOR_SEND, 111, 6, 140, 1, 363, 1}, /* ACDrvAirDistribModReq_VR */
    {/* Index 291 */ 5, CNA_BEHAVIOR_SEND, 109, 6, 141, 1, 364, 1}, /* ACDrvTempReq_VR */
    {/* Index 292 */ 5, CNA_BEHAVIOR_SEND, 110, 6, 142, 1, 365, 1}, /* ACFrntDefrostReq_VR */
    {/* Index 293 */ 5, CNA_BEHAVIOR_NONE, 113, 6, 143, 0, 366, 1}, /* ACModReq_HUT */
    {/* Index 294 */ 5, CNA_BEHAVIOR_SEND, 107, 6, 143, 1, 367, 1}, /* ACPowerReq_VR */
    {/* Index 295 */ 5, CNA_BEHAVIOR_SEND, 122, 6, 144, 1, 368, 1}, /* ACRearAirDistribModReq_TC */
    {/* Index 296 */ 5, CNA_BEHAVIOR_SEND, 118, 6, 145, 1, 369, 1}, /* ACRearAutoModReq_TC */
    {/* Index 297 */ 5, CNA_BEHAVIOR_SEND, 121, 6, 146, 1, 370, 1}, /* ACRearOffReq_TC */
    {/* Index 298 */ 5, CNA_BEHAVIOR_NONE, 116, 6, 147, 0, 371, 1}, /* AllTerrainDislSet */
    {/* Index 299 */ 5, CNA_BEHAVIOR_NONE, 123, 6, 147, 0, 372, 1}, /* DrvSeatHeatgLvlSet */
    {/* Index 300 */ 5, CNA_BEHAVIOR_NONE, 119, 6, 147, 0, 373, 1}, /* DrvSeatSupportLvlSet */
    {/* Index 301 */ 5, CNA_BEHAVIOR_NONE, 103, 6, 147, 0, 374, 1}, /* DrvSeatVentnLvlSet */
    {/* Index 302 */ 5, CNA_BEHAVIOR_NONE, 114, 6, 147, 0, 375, 1}, /* ElecSideSteppingSysSet */
    {/* Index 303 */ 5, CNA_BEHAVIOR_NONE, 124, 6, 147, 0, 376, 1}, /* PassSeatHeatgLvlSet */
    {/* Index 304 */ 5, CNA_BEHAVIOR_NONE, 120, 6, 147, 0, 377, 1}, /* PassSeatSupportLvlSet */
    {/* Index 305 */ 5, CNA_BEHAVIOR_NONE, 104, 6, 147, 0, 378, 1}, /* PassSeatVentnLvlSet */
    {/* Index 306 */ 5, CNA_BEHAVIOR_NONE, 125, 6, 147, 0, 379, 1}, /* RLSeatHeatgLvlSet */
    {/* Index 307 */ 5, CNA_BEHAVIOR_NONE, 126, 6, 147, 0, 380, 1}, /* RRSeatHeatgLvlSet */
    {/* Index 308 */ 5, CNA_BEHAVIOR_UNSEND, 117, 6, 147, 1, 381, 1}, /* RemUpgrdSts */
    {/* Index 309 */ 5, CNA_BEHAVIOR_NONE, 115, 6, 148, 0, 382, 1}, /* RoofModSet */
    {/* Index 310 */ 5, CNA_BEHAVIOR_CYCLE, 333, 24, 148, 1, 383, 1}, /* ContnPrkgReq */
    {/* Index 311 */ 5, CNA_BEHAVIOR_CYCLE, 331, 24, 149, 1, 384, 1}, /* PrkgCtrlModReq */
    {/* Index 312 */ 5, CNA_BEHAVIOR_CYCLE, 497, 35, 150, 1, 385, 1}, /* ChairMemPosnSet */
    {/* Index 313 */ 5, CNA_BEHAVIOR_CYCLE, 473, 35, 151, 1, 386, 1}, /* EPSSteerModSwtReq */
    {/* Index 314 */ 5, CNA_BEHAVIOR_CYCLE, 533, 35, 152, 1, 387, 1}, /* HUT_DrvModReq */
    {/* Index 315 */ 5, CNA_BEHAVIOR_CYCLE, 531, 35, 153, 1, 388, 1}, /* HUT_HybModReq */
    {/* Index 316 */ 5, CNA_BEHAVIOR_CYCLE, 171, 11, 154, 1, 389, 1}, /* DampgDrvModeReq */
    {/* Index 317 */ 5, CNA_BEHAVIOR_CYCLE, 170, 11, 155, 1, 390, 1}, /* DrivingModReq_VR */
    {/* Index 318 */ 5, CNA_BEHAVIOR_CYCLE, 167, 11, 156, 1, 391, 1}, /* ORVMFoldSwt_HUT */
};

static CNA_SignalType cna_signalDatas[SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = {0u};
static const uint8 cna_noActionBuffer[157] =
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
    4u,
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
    0u,
    0u,
    0u,
    0u,
    3u,
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
    3u,
    15u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[643] =
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
    253,
    255,
    257,
    256,
    251,
    239,
    233,
    232,
    243,
    249,
    231,
    235,
    242,
    240,
    247,
    248,
    254,
    241,
    236,
    237,
    252,
    238,
    244,
    245,
    230,
    246,
    234,
    250,
    65535,
    271,
    265,
    268,
    259,
    262,
    258,
    260,
    263,
    264,
    267,
    266,
    261,
    272,
    270,
    269,
    65535,
    280,
    283,
    282,
    281,
    278,
    276,
    279,
    277,
    275,
    285,
    284,
    273,
    274,
    65535,
    301,
    305,
    287,
    289,
    294,
    288,
    291,
    292,
    290,
    286,
    293,
    302,
    309,
    298,
    308,
    296,
    300,
    304,
    297,
    295,
    299,
    303,
    306,
    307,
    65535,
    3,
    4,
    11,
    13,
    15,
    10,
    16,
    17,
    6,
    14,
    8,
    7,
    5,
    9,
    12,
    19,
    18,
    65535,
    1,
    0,
    2,
    65535,
    196,
    195,
    198,
    197,
    194,
    202,
    200,
    199,
    201,
    204,
    205,
    203,
    65535,
    65535,
    65535,
    65535,
    65535,
    318,
    65535,
    65535,
    317,
    316,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    115,
    116,
    114,
    117,
    125,
    119,
    118,
    131,
    130,
    128,
    113,
    120,
    126,
    127,
    124,
    121,
    129,
    123,
    122,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    221,
    224,
    222,
    229,
    220,
    225,
    219,
    223,
    228,
    216,
    217,
    227,
    215,
    218,
    226,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    187,
    188,
    186,
    189,
    190,
    185,
    191,
    192,
    193,
    65535,
    177,
    178,
    175,
    179,
    180,
    174,
    181,
    182,
    173,
    176,
    183,
    184,
    65535,
    163,
    166,
    157,
    168,
    171,
    154,
    155,
    170,
    172,
    169,
    162,
    167,
    156,
    161,
    159,
    160,
    158,
    165,
    164,
    65535,
    142,
    145,
    138,
    147,
    151,
    149,
    153,
    148,
    140,
    146,
    137,
    139,
    152,
    141,
    150,
    144,
    143,
    65535,
    213,
    206,
    207,
    208,
    214,
    210,
    209,
    212,
    211,
    65535,
    65535,
    65535,
    65535,
    68,
    67,
    69,
    59,
    72,
    71,
    63,
    64,
    60,
    65,
    70,
    66,
    61,
    62,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    311,
    65535,
    310,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    98,
    105,
    88,
    99,
    100,
    89,
    91,
    112,
    90,
    106,
    107,
    97,
    102,
    93,
    103,
    104,
    108,
    111,
    95,
    110,
    94,
    109,
    101,
    92,
    86,
    85,
    87,
    96,
    65535,
    65535,
    65535,
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
    40,
    30,
    31,
    37,
    38,
    36,
    33,
    32,
    42,
    34,
    43,
    35,
    41,
    65535,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    47,
    46,
    48,
    49,
    57,
    58,
    44,
    45,
    65535,
    73,
    74,
    79,
    75,
    76,
    77,
    78,
    81,
    84,
    82,
    83,
    80,
    65535,
    134,
    65535,
    135,
    136,
    65535,
    24,
    22,
    23,
    25,
    65535,
    27,
    28,
    26,
    29,
    65535,
    133,
    132,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    313,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    312,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    315,
    65535,
    314,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    20,
    65535,
    21,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[392] = {0};

const CNA_ConfigType cna_config =
{
    SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER,
    cna_signalConfigs,
    cna_signalDatas,
    157u,
    cna_noActionBuffer,
    392u,
    cna_currentBuffer,
    643u,
    CNA_IdTable
};


