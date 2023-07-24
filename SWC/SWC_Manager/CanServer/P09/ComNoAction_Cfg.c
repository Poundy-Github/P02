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
static const CNA_SignalConfigType cna_signalConfigs[143] =
{
    {/* Index 0 */5, CNA_BEHAVIOR_NONE, 64, 7, 0, 0, 0, 1}, /*OTA_UpgrdModReq*/
    {/* Index 1 */5, CNA_BEHAVIOR_NONE, 245, 27, 0, 0, 1, 64}, /*HUT_ExternalDevice*/
    {/* Index 2 */5, CNA_BEHAVIOR_SEND, 198, 25, 0, 1, 65, 1}, /*DrvSeatMassgModSet*/
    {/* Index 3 */5, CNA_BEHAVIOR_SEND, 197, 25, 1, 1, 66, 1}, /*PassSeatMassgModSet*/
    {/* Index 4 */5, CNA_BEHAVIOR_NONE, 188, 23, 2, 0, 67, 1}, /*LockWinSet*/
    {/* Index 5 */5, CNA_BEHAVIOR_NONE, 190, 24, 2, 0, 68, 1}, /*BTAPAEntryLockSet*/
    {/* Index 6 */5, CNA_BEHAVIOR_NONE, 191, 24, 2, 0, 69, 1}, /*BTAPALvngUnlockSet*/
    {/* Index 7 */5, CNA_BEHAVIOR_NONE, 192, 24, 2, 0, 70, 1}, /*ClsWinSpdSet*/
    {/* Index 8 */5, CNA_BEHAVIOR_SEND, 193, 24, 2, 1, 71, 1}, /*DrvSeatMassgLvlSet*/
    {/* Index 9 */5, CNA_BEHAVIOR_NONE, 195, 24, 3, 0, 72, 1}, /*OilBoxSplyReq*/
    {/* Index 10 */5, CNA_BEHAVIOR_SEND, 194, 24, 3, 1, 73, 1}, /*PassSeatMassgLvlSet*/
    {/* Index 11 */6, CNA_BEHAVIOR_UNSEND, 176, 21, 4, 1, 74, 1}, /*ApproachLampSet*/
    {/* Index 12 */6, CNA_BEHAVIOR_SEND, 177, 21, 5, 1, 75, 1}, /*ChairMemPosnSetSwt*/
    {/* Index 13 */6, CNA_BEHAVIOR_UNSEND, 175, 21, 6, 1, 76, 1}, /*FlaoutUnlockSet*/
    {/* Index 14 */5, CNA_BEHAVIOR_NONE, 77, 11, 7, 0, 77, 1}, /*ABSLmpSet*/
    {/* Index 15 */5, CNA_BEHAVIOR_NONE, 78, 11, 7, 0, 78, 1}, /*AutoWshWipSet*/
    {/* Index 16 */5, CNA_BEHAVIOR_NONE, 81, 11, 7, 0, 79, 1}, /*DoorUnlockModSet*/
    {/* Index 17 */5, CNA_BEHAVIOR_NONE, 79, 11, 7, 0, 80, 1}, /*SeekVehSet*/
    {/* Index 18 */5, CNA_BEHAVIOR_NONE, 80, 11, 7, 0, 81, 1}, /*SpdAutoLockModSet*/
    {/* Index 19 */5, CNA_BEHAVIOR_SEND, 82, 11, 7, 1, 82, 1}, /*SteerWheelHeatSwtReq*/
    {/* Index 20 */5, CNA_BEHAVIOR_SEND, 76, 11, 8, 1, 83, 1}, /*SunRoofSwtReq_VR*/
    {/* Index 21 */5, CNA_BEHAVIOR_NONE, 159, 18, 9, 0, 84, 1}, /*ADAS_Stub_CmplxInsct*/
    {/* Index 22 */5, CNA_BEHAVIOR_NONE, 151, 18, 9, 0, 85, 1}, /*ADAS_Stub_CycCnt*/
    {/* Index 23 */5, CNA_BEHAVIOR_NONE, 160, 18, 9, 0, 86, 1}, /*ADAS_Stub_FormOfWay*/
    {/* Index 24 */5, CNA_BEHAVIOR_NONE, 157, 18, 9, 0, 87, 1}, /*ADAS_Stub_FuncRoadClass*/
    {/* Index 25 */5, CNA_BEHAVIOR_NONE, 162, 18, 9, 0, 88, 1}, /*ADAS_Stub_LastStub*/
    {/* Index 26 */5, CNA_BEHAVIOR_NONE, 149, 18, 9, 0, 89, 1}, /*ADAS_Stub_MsgTyp*/
    {/* Index 27 */5, CNA_BEHAVIOR_NONE, 165, 18, 9, 0, 90, 1}, /*ADAS_Stub_NumOfLaneDrvDir*/
    {/* Index 28 */5, CNA_BEHAVIOR_NONE, 164, 18, 9, 0, 91, 1}, /*ADAS_Stub_NumOfLaneOppDir*/
    {/* Index 29 */5, CNA_BEHAVIOR_NONE, 150, 18, 9, 0, 92, 2}, /*ADAS_Stub_Offset*/
    {/* Index 30 */5, CNA_BEHAVIOR_NONE, 158, 18, 9, 0, 94, 1}, /*ADAS_Stub_PartOfCalcRoute*/
    {/* Index 31 */5, CNA_BEHAVIOR_NONE, 152, 18, 9, 0, 95, 1}, /*ADAS_Stub_PathIdx*/
    {/* Index 32 */5, CNA_BEHAVIOR_NONE, 156, 18, 9, 0, 96, 1}, /*ADAS_Stub_RelProbb*/
    {/* Index 33 */5, CNA_BEHAVIOR_NONE, 154, 18, 9, 0, 97, 1}, /*ADAS_Stub_Retr*/
    {/* Index 34 */5, CNA_BEHAVIOR_NONE, 163, 18, 9, 0, 98, 1}, /*ADAS_Stub_RtOfWay*/
    {/* Index 35 */5, CNA_BEHAVIOR_NONE, 153, 18, 9, 0, 99, 1}, /*ADAS_Stub_StubPathIdx*/
    {/* Index 36 */5, CNA_BEHAVIOR_NONE, 161, 18, 9, 0, 100, 1}, /*ADAS_Stub_TurnAngl*/
    {/* Index 37 */5, CNA_BEHAVIOR_NONE, 155, 18, 9, 0, 101, 1}, /*ADAS_Stub_Update*/
    {/* Index 38 */5, CNA_BEHAVIOR_NONE, 134, 17, 9, 0, 102, 1}, /*ADAS_Seg_Brdg*/
    {/* Index 39 */5, CNA_BEHAVIOR_NONE, 135, 17, 9, 0, 103, 1}, /*ADAS_Seg_BuildUpArea*/
    {/* Index 40 */5, CNA_BEHAVIOR_NONE, 141, 17, 9, 0, 104, 1}, /*ADAS_Seg_CmplxInsct*/
    {/* Index 41 */5, CNA_BEHAVIOR_NONE, 131, 17, 9, 0, 105, 1}, /*ADAS_Seg_CycCnt*/
    {/* Index 42 */5, CNA_BEHAVIOR_NONE, 145, 17, 9, 0, 106, 1}, /*ADAS_Seg_DivideRoad*/
    {/* Index 43 */5, CNA_BEHAVIOR_NONE, 143, 17, 9, 0, 107, 1}, /*ADAS_Seg_EffSpdLmt*/
    {/* Index 44 */5, CNA_BEHAVIOR_NONE, 144, 17, 9, 0, 108, 1}, /*ADAS_Seg_EffSpdLmtTyp*/
    {/* Index 45 */5, CNA_BEHAVIOR_NONE, 142, 17, 9, 0, 109, 1}, /*ADAS_Seg_FormOfWay*/
    {/* Index 46 */5, CNA_BEHAVIOR_NONE, 139, 17, 9, 0, 110, 1}, /*ADAS_Seg_FuncRoadClass*/
    {/* Index 47 */5, CNA_BEHAVIOR_NONE, 129, 17, 9, 0, 111, 1}, /*ADAS_Seg_MsgTyp*/
    {/* Index 48 */5, CNA_BEHAVIOR_NONE, 147, 17, 9, 0, 112, 1}, /*ADAS_Seg_NumOfLaneDrvDir*/
    {/* Index 49 */5, CNA_BEHAVIOR_NONE, 146, 17, 9, 0, 113, 1}, /*ADAS_Seg_NumOfLaneOppDir*/
    {/* Index 50 */5, CNA_BEHAVIOR_NONE, 130, 17, 9, 0, 114, 2}, /*ADAS_Seg_Offset*/
    {/* Index 51 */5, CNA_BEHAVIOR_NONE, 140, 17, 9, 0, 116, 1}, /*ADAS_Seg_PartOfCalcRoute*/
    {/* Index 52 */5, CNA_BEHAVIOR_NONE, 132, 17, 9, 0, 117, 1}, /*ADAS_Seg_PathIdx*/
    {/* Index 53 */5, CNA_BEHAVIOR_NONE, 138, 17, 9, 0, 118, 1}, /*ADAS_Seg_RelProbb*/
    {/* Index 54 */5, CNA_BEHAVIOR_NONE, 136, 17, 9, 0, 119, 1}, /*ADAS_Seg_Retr*/
    {/* Index 55 */5, CNA_BEHAVIOR_NONE, 133, 17, 9, 0, 120, 1}, /*ADAS_Seg_Tunnel*/
    {/* Index 56 */5, CNA_BEHAVIOR_NONE, 137, 17, 9, 0, 121, 1}, /*ADAS_Seg_Update*/
    {/* Index 57 */5, CNA_BEHAVIOR_NONE, 124, 16, 9, 0, 122, 1}, /*ADAS_ProfShort_AccurClass*/
    {/* Index 58 */5, CNA_BEHAVIOR_NONE, 121, 16, 9, 0, 123, 1}, /*ADAS_ProfShort_CtrlPoint*/
    {/* Index 59 */5, CNA_BEHAVIOR_NONE, 118, 16, 9, 0, 124, 1}, /*ADAS_ProfShort_CycCnt*/
    {/* Index 60 */5, CNA_BEHAVIOR_NONE, 125, 16, 9, 0, 125, 2}, /*ADAS_ProfShort_Dist1*/
    {/* Index 61 */5, CNA_BEHAVIOR_NONE, 116, 16, 9, 0, 127, 1}, /*ADAS_ProfShort_MsgTyp*/
    {/* Index 62 */5, CNA_BEHAVIOR_NONE, 117, 16, 9, 0, 128, 2}, /*ADAS_ProfShort_Offset*/
    {/* Index 63 */5, CNA_BEHAVIOR_NONE, 119, 16, 9, 0, 130, 1}, /*ADAS_ProfShort_PathIdx*/
    {/* Index 64 */5, CNA_BEHAVIOR_NONE, 120, 16, 9, 0, 131, 1}, /*ADAS_ProfShort_ProfTyp*/
    {/* Index 65 */5, CNA_BEHAVIOR_NONE, 122, 16, 9, 0, 132, 1}, /*ADAS_ProfShort_Retr*/
    {/* Index 66 */5, CNA_BEHAVIOR_NONE, 123, 16, 9, 0, 133, 1}, /*ADAS_ProfShort_Update*/
    {/* Index 67 */5, CNA_BEHAVIOR_NONE, 126, 16, 9, 0, 134, 2}, /*ADAS_ProfShort_Value0*/
    {/* Index 68 */5, CNA_BEHAVIOR_NONE, 127, 16, 9, 0, 136, 2}, /*ADAS_ProfShort_Value1*/
    {/* Index 69 */5, CNA_BEHAVIOR_NONE, 111, 15, 9, 0, 138, 1}, /*ADAS_ProfLong_CtrlPoint*/
    {/* Index 70 */5, CNA_BEHAVIOR_NONE, 108, 15, 9, 0, 139, 1}, /*ADAS_ProfLong_CycCnt*/
    {/* Index 71 */5, CNA_BEHAVIOR_NONE, 106, 15, 9, 0, 140, 1}, /*ADAS_ProfLong_MsgTyp*/
    {/* Index 72 */5, CNA_BEHAVIOR_NONE, 107, 15, 9, 0, 141, 2}, /*ADAS_ProfLong_Offset*/
    {/* Index 73 */5, CNA_BEHAVIOR_NONE, 109, 15, 9, 0, 143, 1}, /*ADAS_ProfLong_PathIdx*/
    {/* Index 74 */5, CNA_BEHAVIOR_NONE, 110, 15, 9, 0, 144, 1}, /*ADAS_ProfLong_ProfTyp*/
    {/* Index 75 */5, CNA_BEHAVIOR_NONE, 112, 15, 9, 0, 145, 1}, /*ADAS_ProfLong_Retr*/
    {/* Index 76 */5, CNA_BEHAVIOR_NONE, 113, 15, 9, 0, 146, 1}, /*ADAS_ProfLong_Update*/
    {/* Index 77 */5, CNA_BEHAVIOR_NONE, 114, 15, 9, 0, 147, 4}, /*ADAS_ProfLong_Value*/
    {/* Index 78 */5, CNA_BEHAVIOR_UNSEND, 67, 8, 9, 1, 151, 1}, /*HUT_EgyRecvrySet*/
    {/* Index 79 */5, CNA_BEHAVIOR_NONE, 66, 8, 10, 0, 152, 1}, /*IPVolSet*/
    {/* Index 80 */5, CNA_BEHAVIOR_SEND, 170, 19, 10, 1, 153, 1}, /*HUT_BattSOCLim*/
    {/* Index 81 */5, CNA_BEHAVIOR_UNSEND, 167, 19, 11, 1, 154, 1}, /*HUT_ChrgnMode*/
    {/* Index 82 */5, CNA_BEHAVIOR_NONE, 169, 19, 12, 0, 155, 1}, /*HUT_IntelBattTempMagSet*/
    {/* Index 83 */5, CNA_BEHAVIOR_NONE, 168, 19, 12, 0, 156, 1}, /*HUT_IntelEngIdlChrgnSet*/
    {/* Index 84 */5, CNA_BEHAVIOR_NONE, 87, 13, 12, 0, 157, 1}, /*AVMSwtReq*/
    {/* Index 85 */5, CNA_BEHAVIOR_NONE, 89, 13, 12, 0, 158, 1}, /*FPASChanSwtReq*/
    {/* Index 86 */5, CNA_BEHAVIOR_NONE, 88, 13, 12, 0, 159, 1}, /*NaviMediaVolLvlReq*/
    {/* Index 87 */5, CNA_BEHAVIOR_NONE, 90, 13, 12, 0, 160, 1}, /*RPASChanSwtReq*/
    {/* Index 88 */5, CNA_BEHAVIOR_UNSEND, 86, 13, 12, 1, 161, 1}, /*WPC_SwtReq*/
    {/* Index 89 */5, CNA_BEHAVIOR_NONE, 12, 3, 13, 0, 162, 1}, /*BattSaveDelayTimeSet*/
    {/* Index 90 */5, CNA_BEHAVIOR_NONE, 13, 3, 13, 0, 163, 1}, /*ChairMemPosnEna*/
    {/* Index 91 */5, CNA_BEHAVIOR_NONE, 10, 3, 13, 0, 164, 1}, /*FolwMeHomeDlyTimSet*/
    {/* Index 92 */5, CNA_BEHAVIOR_NONE, 11, 3, 13, 0, 165, 1}, /*TranPMode_Req*/
    {/* Index 93 */5, CNA_BEHAVIOR_NONE, 18, 4, 13, 0, 166, 1}, /*AMP_AudioVolVSCModReq*/
    {/* Index 94 */5, CNA_BEHAVIOR_NONE, 16, 4, 13, 0, 167, 1}, /*AMP_BeepSourceSet*/
    {/* Index 95 */5, CNA_BEHAVIOR_NONE, 19, 4, 13, 0, 168, 1}, /*AMP_FRAudioFaderSet*/
    {/* Index 96 */5, CNA_BEHAVIOR_NONE, 24, 4, 13, 0, 169, 1}, /*AMP_HighFrqAudioSet*/
    {/* Index 97 */5, CNA_BEHAVIOR_NONE, 17, 4, 13, 0, 170, 1}, /*AMP_LRAudioBalanceSet*/
    {/* Index 98 */5, CNA_BEHAVIOR_NONE, 20, 4, 13, 0, 171, 1}, /*AMP_LRDrvSideSet*/
    {/* Index 99 */5, CNA_BEHAVIOR_NONE, 21, 4, 13, 0, 172, 1}, /*AMP_LowFrqAudioSet*/
    {/* Index 100 */5, CNA_BEHAVIOR_NONE, 23, 4, 13, 0, 173, 1}, /*AMP_MidFrqAudioSet*/
    {/* Index 101 */5, CNA_BEHAVIOR_NONE, 22, 4, 13, 0, 174, 1}, /*AMP_MuteSet*/
    {/* Index 102 */5, CNA_BEHAVIOR_NONE, 15, 4, 13, 0, 175, 1}, /*AMP_NaviSourceSet*/
    {/* Index 103 */5, CNA_BEHAVIOR_NONE, 27, 4, 13, 0, 176, 1}, /*ANCSwtSet*/
    {/* Index 104 */5, CNA_BEHAVIOR_NONE, 26, 4, 13, 0, 177, 1}, /*QLISurroundSet*/
    {/* Index 105 */5, CNA_BEHAVIOR_NONE, 25, 4, 13, 0, 178, 1}, /*T_box_ECallSet*/
    {/* Index 106 */5, CNA_BEHAVIOR_NONE, 28, 4, 13, 0, 179, 1}, /*VRTTSSourceSet*/
    {/* Index 107 */5, CNA_BEHAVIOR_NONE, 41, 5, 13, 0, 180, 1}, /*AMP_BestListegPosnReq*/
    {/* Index 108 */5, CNA_BEHAVIOR_NONE, 42, 5, 13, 0, 181, 1}, /*AMP_Clari_FiReq*/
    {/* Index 109 */5, CNA_BEHAVIOR_SEND, 38, 5, 13, 1, 182, 1}, /*AMP_GetDTCInfoReq*/
    {/* Index 110 */5, CNA_BEHAVIOR_SEND, 35, 5, 14, 1, 183, 1}, /*AMP_GetHWInfoReq*/
    {/* Index 111 */5, CNA_BEHAVIOR_SEND, 37, 5, 15, 1, 184, 1}, /*AMP_GetIntVoltInfoReq*/
    {/* Index 112 */5, CNA_BEHAVIOR_SEND, 34, 5, 16, 1, 185, 1}, /*AMP_GetSWInfoReq*/
    {/* Index 113 */5, CNA_BEHAVIOR_SEND, 36, 5, 17, 1, 186, 1}, /*AMP_GetTempInfoReq*/
    {/* Index 114 */5, CNA_BEHAVIOR_NONE, 30, 5, 18, 0, 187, 1}, /*AMP_HFMVolSet*/
    {/* Index 115 */5, CNA_BEHAVIOR_NONE, 33, 5, 18, 0, 188, 1}, /*AMP_MainVolSet*/
    {/* Index 116 */5, CNA_BEHAVIOR_NONE, 32, 5, 18, 0, 189, 1}, /*AMP_NaviVolSet*/
    {/* Index 117 */5, CNA_BEHAVIOR_NONE, 31, 5, 18, 0, 190, 1}, /*AMP_TTSVolSet_VR*/
    {/* Index 118 */5, CNA_BEHAVIOR_NONE, 51, 5, 18, 0, 191, 1}, /*AudioChanModSet*/
    {/* Index 119 */5, CNA_BEHAVIOR_NONE, 47, 5, 18, 0, 192, 1}, /*HdPrivacyModeSet*/
    {/* Index 120 */5, CNA_BEHAVIOR_NONE, 43, 5, 18, 0, 193, 1}, /*HeadSpkVoiceSet*/
    {/* Index 121 */5, CNA_BEHAVIOR_NONE, 52, 5, 18, 0, 194, 1}, /*ICCSwtReq*/
    {/* Index 122 */5, CNA_BEHAVIOR_NONE, 40, 5, 18, 0, 195, 1}, /*IESS_MdlInfoReq*/
    {/* Index 123 */5, CNA_BEHAVIOR_NONE, 39, 5, 18, 0, 196, 1}, /*IESS_MdlSwtReq*/
    {/* Index 124 */5, CNA_BEHAVIOR_NONE, 44, 5, 18, 0, 197, 1}, /*LShkAudioSet*/
    {/* Index 125 */5, CNA_BEHAVIOR_NONE, 49, 5, 18, 0, 198, 1}, /*PreBassSet*/
    {/* Index 126 */5, CNA_BEHAVIOR_NONE, 46, 5, 18, 0, 199, 1}, /*QLIPlusSurroundSet*/
    {/* Index 127 */5, CNA_BEHAVIOR_NONE, 45, 5, 18, 0, 200, 1}, /*RShkAudioSet*/
    {/* Index 128 */5, CNA_BEHAVIOR_NONE, 50, 5, 18, 0, 201, 1}, /*SmtVolActvt*/
    {/* Index 129 */5, CNA_BEHAVIOR_NONE, 48, 5, 18, 0, 202, 1}, /*SurrVoiceSet*/
    {/* Index 130 */5, CNA_BEHAVIOR_NONE, 54, 6, 18, 0, 203, 1}, /*ACModReq_HUT*/
    {/* Index 131 */5, CNA_BEHAVIOR_NONE, 57, 6, 18, 0, 204, 1}, /*AllTerrainDislSet*/
    {/* Index 132 */5, CNA_BEHAVIOR_NONE, 58, 6, 18, 0, 205, 1}, /*DrvSeatHeatgLvlSet*/
    {/* Index 133 */5, CNA_BEHAVIOR_NONE, 55, 6, 18, 0, 206, 1}, /*ElecSideSteppingSysSet*/
    {/* Index 134 */5, CNA_BEHAVIOR_NONE, 59, 6, 18, 0, 207, 1}, /*PassSeatHeatgLvlSet*/
    {/* Index 135 */5, CNA_BEHAVIOR_NONE, 60, 6, 18, 0, 208, 1}, /*RLSeatHeatgLvlSet*/
    {/* Index 136 */5, CNA_BEHAVIOR_NONE, 61, 6, 18, 0, 209, 1}, /*RRSeatHeatgLvlSet*/
    {/* Index 137 */5, CNA_BEHAVIOR_NONE, 62, 6, 18, 0, 210, 1}, /*RemUpgrdSts*/
    {/* Index 138 */5, CNA_BEHAVIOR_NONE, 56, 6, 18, 0, 211, 1}, /*RoofModSet*/
    {/* Index 139 */5, CNA_BEHAVIOR_CYCLE, 173, 20, 18, 1, 212, 1}, /*DrvSeatSupportPosnSwt*/
    {/* Index 140 */5, CNA_BEHAVIOR_CYCLE, 225, 26, 19, 1, 213, 1}, /*ChairMemPosnSet*/
    {/* Index 141 */5, CNA_BEHAVIOR_CYCLE, 216, 26, 20, 1, 214, 1}, /*EPSSteerModSwtReq*/
    {/* Index 142 */5, CNA_BEHAVIOR_CYCLE, 243, 26, 21, 1, 215, 1}, /*HUT_DrvModReq*/
};

static CNA_SignalType cna_signalDatas[143] = {0u};
static const uint8 cna_noActionBuffer[22] =
{
    0u,
    0u,
    4u,
    4u,
    0u,
    0u,
    0u,
    0u,
    0u,
    3u,
    6u,
    3u,
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
};

static const ComEx_SignalIdType CNA_IdTable[269] =
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
    91,
    92,
    89,
    90,
    65535,
    102,
    94,
    97,
    93,
    95,
    98,
    99,
    101,
    100,
    96,
    105,
    104,
    103,
    106,
    65535,
    114,
    117,
    116,
    115,
    112,
    110,
    113,
    111,
    109,
    123,
    122,
    107,
    108,
    120,
    124,
    127,
    126,
    119,
    129,
    125,
    128,
    118,
    121,
    65535,
    130,
    133,
    138,
    131,
    132,
    134,
    135,
    136,
    137,
    65535,
    0,
    65535,
    79,
    78,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    20,
    14,
    15,
    17,
    18,
    16,
    19,
    65535,
    65535,
    65535,
    88,
    84,
    86,
    85,
    87,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    71,
    72,
    70,
    73,
    74,
    69,
    75,
    76,
    77,
    65535,
    61,
    62,
    59,
    63,
    64,
    58,
    65,
    66,
    57,
    60,
    67,
    68,
    65535,
    47,
    50,
    41,
    52,
    55,
    38,
    39,
    54,
    56,
    53,
    46,
    51,
    40,
    45,
    43,
    44,
    42,
    49,
    48,
    65535,
    26,
    29,
    22,
    31,
    35,
    33,
    37,
    32,
    24,
    30,
    21,
    23,
    36,
    25,
    34,
    28,
    27,
    65535,
    81,
    83,
    82,
    80,
    65535,
    65535,
    139,
    65535,
    13,
    11,
    12,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    4,
    65535,
    5,
    6,
    7,
    8,
    10,
    9,
    65535,
    3,
    2,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    141,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    140,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    142,
    65535,
    1,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[216] = {0};

const CNA_ConfigType cna_config =
{
    143u,
    cna_signalConfigs,
    cna_signalDatas,
    22u,
    cna_noActionBuffer,
    216u,
    cna_currentBuffer,
    269u,
    CNA_IdTable
};


