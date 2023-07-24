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
#ifndef SWC_IPC_CAN_MATRIX_A07H
    #include "SWC_IPC_CANMatrix_A07.h"
    #if ( 0x85abfe84 != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
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
static const CNA_SignalConfigType cna_signalConfigs[255] =
{
    {5, CNA_BEHAVIOR_NONE, 94, 7, 0, 0, 0, 1}, /*ALCMBreSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 91, 7, 0, 0, 1, 1}, /*ALCMClrSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 92, 7, 0, 0, 2, 1}, /*ALCMDynModSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 95, 7, 0, 0, 3, 1}, /*ALCMRdmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 93, 7, 0, 0, 4, 1}, /*ALCMRhmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 90, 7, 0, 0, 5, 1}, /*ALCMStatSwt_OLE*/
    {5, CNA_BEHAVIOR_UNSEND, 98, 7, 0, 1, 6, 1}, /*CarWashModeReq*/
    {5, CNA_BEHAVIOR_NONE, 100, 7, 1, 0, 7, 1}, /*OTA_UpgrdModReq*/
    {5, CNA_BEHAVIOR_NONE, 96, 7, 1, 0, 8, 1}, /*Rdm_SingleColorNr*/
    {5, CNA_BEHAVIOR_SEND, 97, 7, 1, 1, 9, 1}, /*SmtCsaSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 99, 7, 2, 1, 10, 1}, /*StartModSet*/
    {5, CNA_BEHAVIOR_SEND, 72, 6, 3, 1, 11, 1}, /*AUTODefrost_TC*/
    {5, CNA_BEHAVIOR_SEND, 73, 6, 4, 1, 12, 1}, /*AUTODefrost_VR*/
    {5, CNA_BEHAVIOR_SEND, 86, 6, 5, 1, 13, 1}, /*AutoAVMSwSet_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 82, 6, 6, 1, 14, 1}, /*AutoViewChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 85, 6, 7, 1, 15, 1}, /*CarMdlDispCmd*/
    {5, CNA_BEHAVIOR_SEND, 84, 6, 8, 1, 16, 1}, /*CarMdlTrsprcySwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 74, 6, 9, 1, 17, 1}, /*FPAS_AutoModSwt*/
    {5, CNA_BEHAVIOR_SEND, 79, 6, 10, 1, 18, 1}, /*Guid_Ovl_Display_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 76, 6, 11, 1, 19, 1}, /*LaneCalActvtCmd*/
    {5, CNA_BEHAVIOR_SEND, 75, 6, 12, 1, 20, 1}, /*MEBSwtSet*/
    {5, CNA_BEHAVIOR_SEND, 77, 6, 13, 1, 21, 1}, /*MODChgReq*/
    {5, CNA_BEHAVIOR_SEND, 83, 6, 14, 1, 22, 1}, /*MdlColrChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 78, 6, 15, 1, 23, 1}, /*Radar_DispCmd*/
    {5, CNA_BEHAVIOR_SEND, 80, 6, 16, 1, 24, 1}, /*Sgl_View_Sel*/
    {5, CNA_BEHAVIOR_SEND, 81, 6, 17, 1, 25, 1}, /*SwToFieldCalRstCmd*/
    {5, CNA_BEHAVIOR_SEND, 88, 6, 18, 1, 26, 1}, /*View_SoftswitchCmd*/
    {5, CNA_BEHAVIOR_SEND, 87, 6, 19, 1, 27, 1}, /*WshSoftSwt*/
    {5, CNA_BEHAVIOR_NONE, 446, 36, 20, 0, 28, 1}, /*HUT_HAVP_LearningTypeSele*/
    {5, CNA_BEHAVIOR_NONE, 444, 36, 20, 0, 29, 1}, /*HUT_HAVP_Learning_Set_ParkLot*/
    {5, CNA_BEHAVIOR_SEND, 445, 36, 20, 1, 30, 1}, /*HUT_HAVP_Set_Path_Ending*/
    {5, CNA_BEHAVIOR_SEND, 447, 36, 21, 1, 31, 1}, /*SlotNum_VR*/
    {5, CNA_BEHAVIOR_SEND, 449, 36, 22, 1, 32, 1}, /*UserDefPrkMenuSelCmd*/
    {5, CNA_BEHAVIOR_SEND, 448, 36, 23, 1, 33, 1}, /*UserDefinedParkCmd*/
    {5, CNA_BEHAVIOR_SEND, 363, 33, 24, 1, 34, 1}, /*InCarTempMaxSet*/
    {5, CNA_BEHAVIOR_SEND, 362, 33, 25, 1, 35, 1}, /*InCarTempMinSet*/
    {5, CNA_BEHAVIOR_UNSEND, 361, 33, 26, 1, 36, 1}, /*PLG_HeightSet*/
    {5, CNA_BEHAVIOR_SEND, 364, 33, 27, 1, 37, 1}, /*SmtACSwt*/
    {5, CNA_BEHAVIOR_SEND, 285, 24, 28, 1, 38, 1}, /*ACMaxReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 284, 24, 29, 1, 39, 1}, /*ACMaxReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 287, 24, 30, 0, 40, 1}, /*ColorCategory*/
    {5, CNA_BEHAVIOR_NONE, 286, 24, 30, 0, 41, 1}, /*LockWinSet*/
    {5, CNA_BEHAVIOR_NONE, 289, 25, 30, 0, 42, 1}, /*MultiColorNr1*/
    {5, CNA_BEHAVIOR_NONE, 290, 25, 30, 0, 43, 1}, /*MultiColorNr2*/
    {5, CNA_BEHAVIOR_NONE, 291, 25, 30, 0, 44, 1}, /*MultiColorNr3*/
    {5, CNA_BEHAVIOR_NONE, 292, 25, 30, 0, 45, 1}, /*MultiColorNr4*/
    {5, CNA_BEHAVIOR_NONE, 293, 25, 30, 0, 46, 1}, /*MultiColorNr5*/
    {5, CNA_BEHAVIOR_NONE, 294, 25, 30, 0, 47, 1}, /*MultiColorNr6*/
    {5, CNA_BEHAVIOR_NONE, 295, 25, 30, 0, 48, 1}, /*MultiColorNr7*/
    {5, CNA_BEHAVIOR_NONE, 296, 25, 30, 0, 49, 1}, /*MultiColorNr8*/
    {5, CNA_BEHAVIOR_SEND, 307, 27, 30, 1, 50, 1}, /*DrvDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 311, 27, 31, 1, 51, 1}, /*FootALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 309, 27, 32, 1, 52, 1}, /*LRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 312, 27, 33, 1, 53, 1}, /*LeftPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 308, 27, 34, 1, 54, 1}, /*PassDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 310, 27, 35, 1, 55, 1}, /*RRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 313, 27, 36, 1, 56, 1}, /*RightPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 232, 20, 37, 1, 57, 1}, /*BackReq_AVM*/
    {5, CNA_BEHAVIOR_SEND, 234, 20, 38, 1, 58, 1}, /*HUD_BrightnessLvlSwt*/
    {5, CNA_BEHAVIOR_SEND, 233, 20, 39, 1, 59, 1}, /*HUD_HeightLvlSwt*/
    {5, CNA_BEHAVIOR_SEND, 235, 20, 40, 1, 60, 1}, /*HUD_SwtReq*/
    {5, CNA_BEHAVIOR_NONE, 319, 28, 41, 0, 61, 1}, /*ActvEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 318, 28, 41, 0, 62, 1}, /*ActvEntryUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 320, 28, 41, 0, 63, 1}, /*BTAPAEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 321, 28, 41, 0, 64, 1}, /*BTAPALvngUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 322, 28, 41, 0, 65, 1}, /*ClsWinSpdSet*/
    {5, CNA_BEHAVIOR_SEND, 323, 28, 41, 1, 66, 1}, /*DrvDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_UNSEND, 315, 28, 42, 1, 67, 1}, /*DrvSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_UNSEND, 316, 28, 43, 1, 68, 1}, /*DrvSeatMassgModSet*/
    {5, CNA_BEHAVIOR_SEND, 325, 28, 44, 1, 69, 1}, /*LRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 317, 28, 45, 0, 70, 1}, /*LockPromptFunSet*/
    {5, CNA_BEHAVIOR_SEND, 324, 28, 45, 1, 71, 1}, /*PassDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 299, 26, 46, 0, 72, 1}, /*MultiColorNr10*/
    {5, CNA_BEHAVIOR_NONE, 300, 26, 46, 0, 73, 1}, /*MultiColorNr11*/
    {5, CNA_BEHAVIOR_NONE, 301, 26, 46, 0, 74, 1}, /*MultiColorNr12*/
    {5, CNA_BEHAVIOR_NONE, 302, 26, 46, 0, 75, 1}, /*MultiColorNr13*/
    {5, CNA_BEHAVIOR_NONE, 303, 26, 46, 0, 76, 1}, /*MultiColorNr14*/
    {5, CNA_BEHAVIOR_NONE, 304, 26, 46, 0, 77, 1}, /*MultiColorNr15*/
    {5, CNA_BEHAVIOR_NONE, 305, 26, 46, 0, 78, 1}, /*MultiColorNr16*/
    {5, CNA_BEHAVIOR_NONE, 298, 26, 46, 0, 79, 1}, /*MultiColorNr9*/
    {6, CNA_BEHAVIOR_NONE, 267, 22, 46, 0, 80, 1}, /*ALCMDynModSet*/
    {6, CNA_BEHAVIOR_UNSEND, 260, 22, 46, 1, 81, 1}, /*ApproachLampSet*/
    {5, CNA_BEHAVIOR_SEND, 271, 22, 47, 1, 82, 1}, /*BackReq_APS*/
    {6, CNA_BEHAVIOR_SEND, 259, 22, 48, 1, 83, 1}, /*ChairMemPosnSetSwt*/
    {6, CNA_BEHAVIOR_SEND, 265, 22, 49, 1, 84, 1}, /*DrvWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_UNSEND, 261, 22, 50, 1, 85, 1}, /*FlaoutUnlockSet*/
    {6, CNA_BEHAVIOR_NONE, 258, 22, 51, 0, 86, 1}, /*MbrMonrEnReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 270, 22, 51, 1, 87, 1}, /*ParkMdlCmd*/
    {6, CNA_BEHAVIOR_SEND, 266, 22, 52, 1, 88, 1}, /*PassWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_NONE, 268, 22, 53, 0, 89, 1}, /*PrkInDirChoice*/
    {6, CNA_BEHAVIOR_SEND, 263, 22, 53, 1, 90, 1}, /*RLWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_SEND, 264, 22, 54, 1, 91, 1}, /*RRWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 269, 22, 55, 1, 92, 1}, /*SelPrkOutDirReq*/
    {5, CNA_BEHAVIOR_SEND, 272, 22, 56, 1, 93, 1}, /*SelPrkgFctnCmd*/
    {6, CNA_BEHAVIOR_UNSEND, 262, 22, 57, 1, 94, 1}, /*SuperLockSet*/
    {5, CNA_BEHAVIOR_NONE, 133, 11, 58, 0, 95, 1}, /*ABSLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 127, 11, 58, 1, 96, 1}, /*ACDrvSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 139, 11, 59, 1, 97, 1}, /*ACEAHReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 140, 11, 60, 1, 98, 1}, /*ACEAHReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 124, 11, 61, 1, 99, 1}, /*ACOperMod_TC*/
    {5, CNA_BEHAVIOR_SEND, 125, 11, 62, 1, 100, 1}, /*ACOperMod_VR*/
    {5, CNA_BEHAVIOR_SEND, 128, 11, 63, 1, 101, 1}, /*ACPassSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 143, 11, 64, 1, 102, 1}, /*APSPrkgTypSeln*/
    {5, CNA_BEHAVIOR_SEND, 142, 11, 65, 1, 103, 1}, /*APSSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 134, 11, 66, 0, 104, 1}, /*AutoWshWipSet*/
    {5, CNA_BEHAVIOR_NONE, 138, 11, 66, 0, 105, 1}, /*DoorUnlockModSet*/
    {5, CNA_BEHAVIOR_NONE, 144, 11, 66, 0, 106, 1}, /*HUT_APSPrkgModSeln*/
    {5, CNA_BEHAVIOR_SEND, 129, 11, 66, 1, 107, 1}, /*PASExitSpdSwt*/
    {5, CNA_BEHAVIOR_NONE, 137, 11, 67, 0, 108, 1}, /*ParkLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 141, 11, 67, 1, 109, 1}, /*SDWSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 135, 11, 68, 0, 110, 1}, /*SeekVehSet*/
    {5, CNA_BEHAVIOR_NONE, 136, 11, 68, 0, 111, 1}, /*SpdAutoLockModSet*/
    {5, CNA_BEHAVIOR_NONE, 132, 11, 68, 0, 112, 1}, /*SportModLightSet*/
    {5, CNA_BEHAVIOR_SEND, 126, 11, 68, 1, 113, 1}, /*SteerWheelHeatSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 131, 11, 69, 1, 114, 1}, /*SunRoofSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 130, 11, 70, 1, 115, 1}, /*SunShadeSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 366, 34, 71, 0, 116, 1}, /*APAPrkgTypSeln*/
    {5, CNA_BEHAVIOR_NONE, 349, 30, 71, 0, 117, 1}, /*ALCMBreSwt*/
    {5, CNA_BEHAVIOR_NONE, 348, 30, 71, 0, 118, 1}, /*ALCMFloSwt*/
    {5, CNA_BEHAVIOR_SEND, 341, 30, 71, 1, 119, 1}, /*DrvDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 340, 30, 72, 0, 120, 1}, /*FootALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 347, 30, 72, 0, 121, 1}, /*FootALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 343, 30, 72, 1, 122, 1}, /*LRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 338, 30, 73, 1, 123, 1}, /*LeftPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 345, 30, 74, 1, 124, 1}, /*LeftPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 342, 30, 75, 1, 125, 1}, /*PassDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 337, 30, 76, 1, 126, 1}, /*RRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 344, 30, 77, 1, 127, 1}, /*RRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 339, 30, 78, 1, 128, 1}, /*RightPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 346, 30, 79, 1, 129, 1}, /*RightPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 351, 31, 80, 1, 130, 1}, /*SmtSeatSwt*/
    {5, CNA_BEHAVIOR_NONE, 217, 17, 81, 0, 131, 1}, /*ADAS_Stub_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 209, 17, 81, 0, 132, 1}, /*ADAS_Stub_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 218, 17, 81, 0, 133, 1}, /*ADAS_Stub_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 215, 17, 81, 0, 134, 1}, /*ADAS_Stub_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 220, 17, 81, 0, 135, 1}, /*ADAS_Stub_LastStub*/
    {5, CNA_BEHAVIOR_NONE, 207, 17, 81, 0, 136, 1}, /*ADAS_Stub_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 223, 17, 81, 0, 137, 1}, /*ADAS_Stub_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 222, 17, 81, 0, 138, 1}, /*ADAS_Stub_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 208, 17, 81, 0, 139, 2}, /*ADAS_Stub_Offset*/
    {5, CNA_BEHAVIOR_NONE, 216, 17, 81, 0, 141, 1}, /*ADAS_Stub_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 210, 17, 81, 0, 142, 1}, /*ADAS_Stub_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 214, 17, 81, 0, 143, 1}, /*ADAS_Stub_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 212, 17, 81, 0, 144, 1}, /*ADAS_Stub_Retr*/
    {5, CNA_BEHAVIOR_NONE, 221, 17, 81, 0, 145, 1}, /*ADAS_Stub_RtOfWay*/
    {5, CNA_BEHAVIOR_NONE, 211, 17, 81, 0, 146, 1}, /*ADAS_Stub_StubPathIdx*/
    {5, CNA_BEHAVIOR_NONE, 219, 17, 81, 0, 147, 1}, /*ADAS_Stub_TurnAngl*/
    {5, CNA_BEHAVIOR_NONE, 213, 17, 81, 0, 148, 1}, /*ADAS_Stub_Update*/
    {5, CNA_BEHAVIOR_NONE, 192, 16, 81, 0, 149, 1}, /*ADAS_Seg_Brdg*/
    {5, CNA_BEHAVIOR_NONE, 193, 16, 81, 0, 150, 1}, /*ADAS_Seg_BuildUpArea*/
    {5, CNA_BEHAVIOR_NONE, 199, 16, 81, 0, 151, 1}, /*ADAS_Seg_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 189, 16, 81, 0, 152, 1}, /*ADAS_Seg_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 203, 16, 81, 0, 153, 1}, /*ADAS_Seg_DivideRoad*/
    {5, CNA_BEHAVIOR_NONE, 201, 16, 81, 0, 154, 1}, /*ADAS_Seg_EffSpdLmt*/
    {5, CNA_BEHAVIOR_NONE, 202, 16, 81, 0, 155, 1}, /*ADAS_Seg_EffSpdLmtTyp*/
    {5, CNA_BEHAVIOR_NONE, 200, 16, 81, 0, 156, 1}, /*ADAS_Seg_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 197, 16, 81, 0, 157, 1}, /*ADAS_Seg_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 187, 16, 81, 0, 158, 1}, /*ADAS_Seg_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 205, 16, 81, 0, 159, 1}, /*ADAS_Seg_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 204, 16, 81, 0, 160, 1}, /*ADAS_Seg_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 188, 16, 81, 0, 161, 2}, /*ADAS_Seg_Offset*/
    {5, CNA_BEHAVIOR_NONE, 198, 16, 81, 0, 163, 1}, /*ADAS_Seg_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 190, 16, 81, 0, 164, 1}, /*ADAS_Seg_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 196, 16, 81, 0, 165, 1}, /*ADAS_Seg_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 194, 16, 81, 0, 166, 1}, /*ADAS_Seg_Retr*/
    {5, CNA_BEHAVIOR_NONE, 191, 16, 81, 0, 167, 1}, /*ADAS_Seg_Tunnel*/
    {5, CNA_BEHAVIOR_NONE, 195, 16, 81, 0, 168, 1}, /*ADAS_Seg_Update*/
    {5, CNA_BEHAVIOR_NONE, 182, 15, 81, 0, 169, 1}, /*ADAS_ProfShort_AccurClass*/
    {5, CNA_BEHAVIOR_NONE, 179, 15, 81, 0, 170, 1}, /*ADAS_ProfShort_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 176, 15, 81, 0, 171, 1}, /*ADAS_ProfShort_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 183, 15, 81, 0, 172, 2}, /*ADAS_ProfShort_Dist1*/
    {5, CNA_BEHAVIOR_NONE, 174, 15, 81, 0, 174, 1}, /*ADAS_ProfShort_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 175, 15, 81, 0, 175, 2}, /*ADAS_ProfShort_Offset*/
    {5, CNA_BEHAVIOR_NONE, 177, 15, 81, 0, 177, 1}, /*ADAS_ProfShort_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 178, 15, 81, 0, 178, 1}, /*ADAS_ProfShort_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 180, 15, 81, 0, 179, 1}, /*ADAS_ProfShort_Retr*/
    {5, CNA_BEHAVIOR_NONE, 181, 15, 81, 0, 180, 1}, /*ADAS_ProfShort_Update*/
    {5, CNA_BEHAVIOR_NONE, 184, 15, 81, 0, 181, 2}, /*ADAS_ProfShort_Value0*/
    {5, CNA_BEHAVIOR_NONE, 185, 15, 81, 0, 183, 2}, /*ADAS_ProfShort_Value1*/
    {5, CNA_BEHAVIOR_NONE, 169, 14, 81, 0, 185, 1}, /*ADAS_ProfLong_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 166, 14, 81, 0, 186, 1}, /*ADAS_ProfLong_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 164, 14, 81, 0, 187, 1}, /*ADAS_ProfLong_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 165, 14, 81, 0, 188, 2}, /*ADAS_ProfLong_Offset*/
    {5, CNA_BEHAVIOR_NONE, 167, 14, 81, 0, 190, 1}, /*ADAS_ProfLong_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 168, 14, 81, 0, 191, 1}, /*ADAS_ProfLong_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 170, 14, 81, 0, 192, 1}, /*ADAS_ProfLong_Retr*/
    {5, CNA_BEHAVIOR_NONE, 171, 14, 81, 0, 193, 1}, /*ADAS_ProfLong_Update*/
    {5, CNA_BEHAVIOR_NONE, 172, 14, 81, 0, 194, 4}, /*ADAS_ProfLong_Value*/
    {5, CNA_BEHAVIOR_SEND, 107, 9, 81, 1, 198, 1}, /*ACAIUReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 105, 9, 82, 1, 199, 1}, /*ACAQSReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 104, 9, 83, 1, 200, 1}, /*ACDualReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 106, 9, 84, 1, 201, 1}, /*ACPassTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 113, 9, 85, 1, 202, 1}, /*ACRearDefrstReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 109, 9, 86, 0, 203, 1}, /*ALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 110, 9, 86, 0, 204, 1}, /*ALCMRhmSwt*/
    {5, CNA_BEHAVIOR_NONE, 108, 9, 86, 0, 205, 1}, /*ALCMStatSwt*/
    {3, CNA_BEHAVIOR_SEND, 112, 9, 86, 1, 206, 1}, /*HUT_BeanIDReq*/
    {5, CNA_BEHAVIOR_SEND, 111, 9, 87, 1, 207, 1}, /*PASSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 226, 18, 88, 1, 208, 1}, /*ACDrvSetTempReq_ETC_VR*/
    {5, CNA_BEHAVIOR_SEND, 227, 18, 89, 1, 209, 1}, /*ACDrvSetTempSteplsReq_ETC_TC*/
    {5, CNA_BEHAVIOR_SEND, 225, 18, 90, 1, 210, 1}, /*HUT_RemtEngCtrl*/
    {5, CNA_BEHAVIOR_SEND, 146, 12, 91, 1, 211, 1}, /*BackgroundLightLvlSet*/
    {5, CNA_BEHAVIOR_UNSEND, 147, 12, 92, 1, 212, 1}, /*PLGReq_VR*/
    {5, CNA_BEHAVIOR_UNSEND, 148, 12, 93, 1, 213, 1}, /*WPC_SwtReq*/
    {5, CNA_BEHAVIOR_NONE, 483, 41, 94, 0, 214, 1}, /*T_BOX_RemtLimitStart*/
    {5, CNA_BEHAVIOR_NONE, 484, 41, 94, 0, 215, 1}, /*T_BOX_RemtSteerWheelHeatCtrl*/
    {5, CNA_BEHAVIOR_SEND, 51, 3, 94, 1, 216, 1}, /*ACAIUReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 39, 3, 95, 1, 217, 1}, /*ACAQSReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 38, 3, 96, 1, 218, 1}, /*ACAirInletReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 37, 3, 97, 1, 219, 1}, /*ACAutoModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 53, 3, 98, 1, 220, 1}, /*ACBlwrsteplsSpdReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 40, 3, 99, 1, 221, 1}, /*ACCmprReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 45, 3, 100, 1, 222, 1}, /*ACDrvAirDistribModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 46, 3, 101, 1, 223, 1}, /*ACDrvTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 48, 3, 102, 1, 224, 1}, /*ACDrvTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 36, 3, 103, 1, 225, 1}, /*ACDualReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 42, 3, 104, 1, 226, 1}, /*ACFrntBlwrSpdDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 44, 3, 105, 1, 227, 1}, /*ACFrntBlwrSpdIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 41, 3, 106, 1, 228, 1}, /*ACFrntDefrstReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 49, 3, 107, 1, 229, 1}, /*ACFrntPassTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 50, 3, 108, 1, 230, 1}, /*ACFrntPassTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 52, 3, 109, 1, 231, 1}, /*ACOffReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 35, 3, 110, 0, 232, 1}, /*BattSaveDelayTimeSet*/
    {5, CNA_BEHAVIOR_NONE, 47, 3, 110, 0, 233, 1}, /*ChairMemPosnEna*/
    {5, CNA_BEHAVIOR_NONE, 31, 3, 110, 0, 234, 1}, /*DomeLmpDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 43, 3, 110, 0, 235, 1}, /*DrvDrowsnsDetnSet*/
    {5, CNA_BEHAVIOR_NONE, 32, 3, 110, 0, 236, 1}, /*FolwMeHomeDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 34, 3, 110, 0, 237, 1}, /*RearviewFoldModSet*/
    {5, CNA_BEHAVIOR_NONE, 33, 3, 110, 0, 238, 1}, /*TranPMode_Req*/
    {5, CNA_BEHAVIOR_SEND, 55, 4, 110, 1, 239, 1}, /*RearWinHeatCmd_TC*/
    {5, CNA_BEHAVIOR_SEND, 68, 5, 111, 1, 240, 1}, /*ACAirInletReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 61, 5, 112, 1, 241, 1}, /*ACAutoModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 64, 5, 113, 1, 242, 1}, /*ACBlwrSpdReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 62, 5, 114, 1, 243, 1}, /*ACCmprReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 67, 5, 115, 1, 244, 1}, /*ACDrvAirDistribModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 65, 5, 116, 1, 245, 1}, /*ACDrvTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 66, 5, 117, 1, 246, 1}, /*ACFrntDefrostReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 69, 5, 118, 0, 247, 1}, /*ACModReq_HUT*/
    {5, CNA_BEHAVIOR_SEND, 63, 5, 118, 1, 248, 1}, /*ACPowerReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 57, 5, 119, 0, 249, 1}, /*DrvSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 59, 5, 119, 0, 250, 1}, /*DrvSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 58, 5, 119, 0, 251, 1}, /*PassSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 60, 5, 119, 0, 252, 1}, /*PassSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 70, 5, 119, 0, 253, 1}, /*RemUpgrdSts*/
    {5, CNA_BEHAVIOR_CYCLE, 356, 32, 119, 1, 254, 1}, /*RearFogLmpSwtSts_HUT*/
    {5, CNA_BEHAVIOR_CYCLE, 242, 21, 120, 1, 255, 1}, /*ContnPrkgReq*/
    {5, CNA_BEHAVIOR_CYCLE, 240, 21, 121, 1, 256, 1}, /*PrkgCtrlModReq*/
    {5, CNA_BEHAVIOR_CYCLE, 229, 19, 122, 1, 257, 1}, /*DrvSeatSupportPosnSwt*/
    {5, CNA_BEHAVIOR_CYCLE, 411, 35, 123, 1, 258, 1}, /*ChairMemPosnSet*/
    {5, CNA_BEHAVIOR_CYCLE, 393, 35, 124, 1, 259, 1}, /*EPSSteerModSwtReq*/
    {10, CNA_BEHAVIOR_CYCLE, 442, 35, 125, 1, 260, 1}, /*HUT_TGSSwtReq*/
    {5, CNA_BEHAVIOR_CYCLE, 117, 10, 126, 1, 261, 1}, /*HUT_AVHSwitchSts*/
    {5, CNA_BEHAVIOR_CYCLE, 119, 10, 127, 1, 262, 1}, /*HUT_EPB_SwtPosn*/
    {5, CNA_BEHAVIOR_CYCLE, 118, 10, 128, 1, 263, 1}, /*HUT_HDCSwitchCtrl*/
    {5, CNA_BEHAVIOR_CYCLE, 122, 10, 129, 1, 264, 1}, /*ORVMFoldSwt_HUT*/
};

static CNA_SignalType cna_signalDatas[255] = {0u};
static const uint8 cna_noActionBuffer[130] =
{
    2u,
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
    61u,
    61u,
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
    64u,
    4u,
    0u,
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
    0u,
    0u,
    0u,
    0u,
    10u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
    0u,
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
    2u,
    0u,
    0u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[486] =
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
    224,
    226,
    228,
    227,
    222,
    215,
    209,
    208,
    207,
    211,
    218,
    216,
    225,
    217,
    212,
    213,
    223,
    214,
    219,
    220,
    206,
    221,
    210,
    65535,
    229,
    65535,
    239,
    241,
    240,
    242,
    231,
    233,
    238,
    232,
    235,
    236,
    234,
    230,
    237,
    243,
    65535,
    11,
    12,
    17,
    20,
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
    27,
    26,
    65535,
    5,
    1,
    2,
    4,
    0,
    3,
    8,
    9,
    6,
    10,
    7,
    65535,
    65535,
    65535,
    190,
    189,
    191,
    188,
    195,
    193,
    194,
    197,
    196,
    192,
    65535,
    65535,
    65535,
    251,
    253,
    252,
    65535,
    65535,
    254,
    65535,
    99,
    100,
    113,
    96,
    101,
    107,
    115,
    114,
    112,
    95,
    104,
    110,
    111,
    108,
    105,
    97,
    98,
    109,
    103,
    102,
    106,
    65535,
    201,
    202,
    203,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    181,
    182,
    180,
    183,
    184,
    179,
    185,
    186,
    187,
    65535,
    171,
    172,
    169,
    173,
    174,
    168,
    175,
    176,
    167,
    170,
    177,
    178,
    65535,
    157,
    160,
    151,
    162,
    165,
    148,
    149,
    164,
    166,
    163,
    156,
    161,
    150,
    155,
    153,
    154,
    152,
    159,
    158,
    65535,
    136,
    139,
    132,
    141,
    145,
    143,
    147,
    142,
    134,
    140,
    131,
    133,
    146,
    135,
    144,
    138,
    137,
    65535,
    200,
    198,
    199,
    65535,
    247,
    65535,
    65535,
    57,
    59,
    58,
    60,
    65535,
    65535,
    65535,
    65535,
    246,
    65535,
    245,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    86,
    83,
    81,
    85,
    94,
    90,
    91,
    84,
    88,
    80,
    89,
    92,
    87,
    82,
    93,
    65535,
    65535,
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
    38,
    41,
    40,
    65535,
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    65535,
    79,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    65535,
    50,
    54,
    52,
    55,
    51,
    53,
    56,
    65535,
    67,
    68,
    70,
    62,
    61,
    63,
    64,
    65,
    66,
    71,
    69,
    65535,
    65535,
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
    123,
    128,
    120,
    119,
    125,
    122,
    127,
    124,
    129,
    121,
    118,
    117,
    65535,
    130,
    65535,
    65535,
    65535,
    65535,
    244,
    65535,
    65535,
    65535,
    65535,
    36,
    35,
    34,
    37,
    65535,
    116,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    249,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    248,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    250,
    65535,
    29,
    30,
    28,
    31,
    33,
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
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    204,
    205,
    65535,
};

static uint8 cna_currentBuffer[265] = {0};

const CNA_ConfigType cna_config =
{
    255u,
    cna_signalConfigs,
    cna_signalDatas,
    130u,
    cna_noActionBuffer,
    265u,
    cna_currentBuffer,
    486u,
    CNA_IdTable
};


