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
#ifndef SWC_IPC_CAN_MATRIX_A08H
    #include "SWC_IPC_CANMatrix_A08.h"
    #if ( 0x80034c7d != SWC_IPC_EVENT_TXSIGNAL_HASHCODE)
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
static const CNA_SignalConfigType cna_signalConfigs[334] =
{
    {5, CNA_BEHAVIOR_NONE, 139, 8, 0, 0, 0, 1}, /*ALCMBreSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 136, 8, 0, 0, 1, 1}, /*ALCMClrSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 137, 8, 0, 0, 2, 1}, /*ALCMDynModSet_OLE*/
    {5, CNA_BEHAVIOR_NONE, 140, 8, 0, 0, 3, 1}, /*ALCMRdmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 138, 8, 0, 0, 4, 1}, /*ALCMRhmSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 135, 8, 0, 0, 5, 1}, /*ALCMStatSwt_OLE*/
    {5, CNA_BEHAVIOR_NONE, 143, 8, 0, 0, 6, 1}, /*CarWashModeReq*/
    {5, CNA_BEHAVIOR_NONE, 132, 8, 0, 0, 7, 1}, /*DrvSeatPosnToWelGuest*/
    {5, CNA_BEHAVIOR_NONE, 133, 8, 0, 0, 8, 1}, /*IntvLightSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 131, 8, 0, 1, 9, 1}, /*LowBeamHightAdjReq*/
    {5, CNA_BEHAVIOR_NONE, 134, 8, 1, 0, 10, 1}, /*OTA_UpgrdModReq*/
    {5, CNA_BEHAVIOR_NONE, 141, 8, 1, 0, 11, 1}, /*Rdm_SingleColorNr*/
    {5, CNA_BEHAVIOR_SEND, 142, 8, 1, 1, 12, 1}, /*SmtCsaSwt*/
    {5, CNA_BEHAVIOR_NONE, 144, 8, 2, 0, 13, 1}, /*StartModSet*/
    {5, CNA_BEHAVIOR_SEND, 114, 7, 2, 1, 14, 1}, /*AUTODefrost_TC*/
    {5, CNA_BEHAVIOR_SEND, 115, 7, 3, 1, 15, 1}, /*AUTODefrost_VR*/
    {5, CNA_BEHAVIOR_SEND, 113, 7, 4, 1, 16, 1}, /*AutoAVMSwSet_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 116, 7, 5, 1, 17, 1}, /*AutoViewChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 117, 7, 6, 1, 18, 1}, /*CarMdlDispCmd*/
    {5, CNA_BEHAVIOR_SEND, 118, 7, 7, 1, 19, 1}, /*CarMdlTrsprcySwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 119, 7, 8, 1, 20, 1}, /*FPAS_AutoModSwt*/
    {5, CNA_BEHAVIOR_SEND, 120, 7, 9, 1, 21, 1}, /*Guid_Ovl_Display_Cmd*/
    {5, CNA_BEHAVIOR_SEND, 121, 7, 10, 1, 22, 1}, /*LaneCalActvtCmd*/
    {5, CNA_BEHAVIOR_SEND, 123, 7, 11, 1, 23, 1}, /*MEBSwtSet*/
    {5, CNA_BEHAVIOR_SEND, 124, 7, 12, 1, 24, 1}, /*MODChgReq*/
    {5, CNA_BEHAVIOR_SEND, 122, 7, 13, 1, 25, 1}, /*MdlColrChgCmd*/
    {5, CNA_BEHAVIOR_SEND, 125, 7, 14, 1, 26, 1}, /*Radar_DispCmd*/
    {5, CNA_BEHAVIOR_SEND, 126, 7, 15, 1, 27, 1}, /*Sgl_View_Sel*/
    {5, CNA_BEHAVIOR_SEND, 127, 7, 16, 1, 28, 1}, /*SwToFieldCalRstCmd*/
    {5, CNA_BEHAVIOR_SEND, 128, 7, 17, 1, 29, 1}, /*View_SoftswitchCmd*/
    {5, CNA_BEHAVIOR_SEND, 129, 7, 18, 1, 30, 1}, /*WshSoftSwt*/
    {5, CNA_BEHAVIOR_SEND, 600, 39, 19, 1, 31, 1}, /*HUT_HAVP_APA_Permit*/
    {5, CNA_BEHAVIOR_UNSEND, 601, 39, 20, 1, 32, 1}, /*HUT_HAVP_Comfirm_Btn*/
    {5, CNA_BEHAVIOR_NONE, 603, 39, 21, 0, 33, 1}, /*HUT_HAVP_LearningTypeSele*/
    {5, CNA_BEHAVIOR_NONE, 602, 39, 21, 0, 34, 1}, /*HUT_HAVP_Learning_Set_ParkLot*/
    {5, CNA_BEHAVIOR_NONE, 604, 39, 21, 0, 35, 1}, /*HUT_HAVP_Path_Delete*/
    {5, CNA_BEHAVIOR_NONE, 605, 39, 21, 0, 36, 1}, /*HUT_HAVP_Path_Select*/
    {5, CNA_BEHAVIOR_NONE, 606, 39, 21, 0, 37, 1}, /*HUT_HAVP_Path_SetTop*/
    {5, CNA_BEHAVIOR_SEND, 607, 39, 21, 1, 38, 1}, /*HUT_HAVP_Return_Btn*/
    {5, CNA_BEHAVIOR_SEND, 608, 39, 22, 1, 39, 1}, /*HUT_HAVP_SelfParLot_Ending*/
    {5, CNA_BEHAVIOR_SEND, 609, 39, 23, 1, 40, 1}, /*HUT_HAVP_Set_Path_Ending*/
    {5, CNA_BEHAVIOR_SEND, 610, 39, 24, 1, 41, 1}, /*HUT_HAVP_Set_Starting*/
    {5, CNA_BEHAVIOR_NONE, 611, 39, 25, 0, 42, 1}, /*HUT_PAVP_Confirm*/
    {5, CNA_BEHAVIOR_NONE, 612, 39, 25, 0, 43, 1}, /*HUT_PAVP_DropOff_Area_req*/
    {5, CNA_BEHAVIOR_NONE, 613, 39, 25, 0, 44, 1}, /*HUT_PAVP_PathList_Req*/
    {5, CNA_BEHAVIOR_SEND, 614, 39, 25, 1, 45, 1}, /*SlotNum_VR*/
    {5, CNA_BEHAVIOR_SEND, 616, 39, 26, 1, 46, 1}, /*UserDefPrkMenuSelCmd*/
    {5, CNA_BEHAVIOR_SEND, 615, 39, 27, 1, 47, 1}, /*UserDefinedParkCmd*/
    {5, CNA_BEHAVIOR_UNSEND, 442, 35, 28, 1, 48, 1}, /*ApprLightSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 438, 35, 29, 1, 49, 1}, /*DrvSeatMassgModSet_0x1dc*/
    {5, CNA_BEHAVIOR_NONE, 447, 35, 30, 0, 50, 1}, /*HUT_V2LStart*/
    {5, CNA_BEHAVIOR_NONE, 445, 35, 30, 0, 51, 1}, /*InCarTempMaxSet*/
    {5, CNA_BEHAVIOR_NONE, 444, 35, 30, 0, 52, 1}, /*InCarTempMinSet*/
    {5, CNA_BEHAVIOR_UNSEND, 441, 35, 30, 1, 53, 1}, /*LockWelLightSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 443, 35, 31, 1, 54, 1}, /*PLG_HeightSet*/
    {5, CNA_BEHAVIOR_UNSEND, 439, 35, 32, 1, 55, 1}, /*PassSeatMassgModSet*/
    {5, CNA_BEHAVIOR_NONE, 446, 35, 33, 0, 56, 1}, /*SmtACSwt*/
    {5, CNA_BEHAVIOR_UNSEND, 440, 35, 33, 1, 57, 1}, /*UnlockWelLightSwt*/
    {5, CNA_BEHAVIOR_SEND, 360, 26, 34, 1, 58, 1}, /*ACMaxReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 361, 26, 35, 1, 59, 1}, /*ACMaxReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 363, 26, 36, 0, 60, 1}, /*ColorCategory*/
    {5, CNA_BEHAVIOR_NONE, 362, 26, 36, 0, 61, 1}, /*LockWinSet*/
    {5, CNA_BEHAVIOR_NONE, 365, 27, 36, 0, 62, 1}, /*MultiColorNr1*/
    {5, CNA_BEHAVIOR_NONE, 366, 27, 36, 0, 63, 1}, /*MultiColorNr2*/
    {5, CNA_BEHAVIOR_NONE, 367, 27, 36, 0, 64, 1}, /*MultiColorNr3*/
    {5, CNA_BEHAVIOR_NONE, 368, 27, 36, 0, 65, 1}, /*MultiColorNr4*/
    {5, CNA_BEHAVIOR_NONE, 369, 27, 36, 0, 66, 1}, /*MultiColorNr5*/
    {5, CNA_BEHAVIOR_NONE, 370, 27, 36, 0, 67, 1}, /*MultiColorNr6*/
    {5, CNA_BEHAVIOR_NONE, 371, 27, 36, 0, 68, 1}, /*MultiColorNr7*/
    {5, CNA_BEHAVIOR_NONE, 372, 27, 36, 0, 69, 1}, /*MultiColorNr8*/
    {5, CNA_BEHAVIOR_SEND, 383, 29, 36, 1, 70, 1}, /*DrvDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 387, 29, 37, 1, 71, 1}, /*FootALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 385, 29, 38, 1, 72, 1}, /*LRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 388, 29, 39, 1, 73, 1}, /*LeftPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 384, 29, 40, 1, 74, 1}, /*PassDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 386, 29, 41, 1, 75, 1}, /*RRDoorALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 389, 29, 42, 1, 76, 1}, /*RightPanelALCMFlashFreq*/
    {5, CNA_BEHAVIOR_SEND, 297, 22, 43, 1, 77, 1}, /*BackReq_AVM*/
    {5, CNA_BEHAVIOR_SEND, 298, 22, 44, 1, 78, 1}, /*HUD_BrightnessLvlSwt*/
    {5, CNA_BEHAVIOR_SEND, 299, 22, 45, 1, 79, 1}, /*HUD_HeightLvlSwt*/
    {5, CNA_BEHAVIOR_SEND, 300, 22, 46, 1, 80, 1}, /*HUD_SwtReq*/
    {5, CNA_BEHAVIOR_NONE, 393, 30, 47, 0, 81, 1}, /*ActvEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 394, 30, 47, 0, 82, 1}, /*ActvEntryUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 395, 30, 47, 0, 83, 1}, /*BTAPAEntryLockSet*/
    {5, CNA_BEHAVIOR_NONE, 396, 30, 47, 0, 84, 1}, /*BTAPALvngUnlockSet*/
    {5, CNA_BEHAVIOR_NONE, 397, 30, 47, 0, 85, 1}, /*ClsWinSpdSet*/
    {5, CNA_BEHAVIOR_SEND, 398, 30, 47, 1, 86, 1}, /*DrvDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_UNSEND, 391, 30, 48, 1, 87, 1}, /*DrvSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 402, 30, 49, 0, 88, 1}, /*DrvSeatMassgModSet_0x1eb*/
    {5, CNA_BEHAVIOR_SEND, 400, 30, 49, 1, 89, 1}, /*LRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 401, 30, 50, 0, 90, 1}, /*LockPromptFunSet*/
    {5, CNA_BEHAVIOR_SEND, 399, 30, 50, 1, 91, 1}, /*PassDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_UNSEND, 392, 30, 51, 1, 92, 1}, /*PassSeatMassgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 375, 28, 52, 0, 93, 1}, /*MultiColorNr10*/
    {5, CNA_BEHAVIOR_NONE, 376, 28, 52, 0, 94, 1}, /*MultiColorNr11*/
    {5, CNA_BEHAVIOR_NONE, 377, 28, 52, 0, 95, 1}, /*MultiColorNr12*/
    {5, CNA_BEHAVIOR_NONE, 378, 28, 52, 0, 96, 1}, /*MultiColorNr13*/
    {5, CNA_BEHAVIOR_NONE, 379, 28, 52, 0, 97, 1}, /*MultiColorNr14*/
    {5, CNA_BEHAVIOR_NONE, 380, 28, 52, 0, 98, 1}, /*MultiColorNr15*/
    {5, CNA_BEHAVIOR_NONE, 381, 28, 52, 0, 99, 1}, /*MultiColorNr16*/
    {5, CNA_BEHAVIOR_NONE, 374, 28, 52, 0, 100, 1}, /*MultiColorNr9*/
    {5, CNA_BEHAVIOR_SEND, 323, 24, 52, 1, 101, 1}, /*ACFGAChanTyp_TC*/
    {5, CNA_BEHAVIOR_SEND, 324, 24, 53, 1, 102, 1}, /*ACFGAEnaReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 325, 24, 54, 1, 103, 1}, /*ACFGALvlReq_TC*/
    {6, CNA_BEHAVIOR_NONE, 326, 24, 55, 0, 104, 1}, /*ALCMDynModSet*/
    {6, CNA_BEHAVIOR_UNSEND, 327, 24, 55, 1, 105, 1}, /*ApproachLampSet*/
    {5, CNA_BEHAVIOR_SEND, 328, 24, 56, 1, 106, 1}, /*BackReq_APS*/
    {6, CNA_BEHAVIOR_SEND, 329, 24, 57, 1, 107, 1}, /*ChairMemPosnSetSwt*/
    {5, CNA_BEHAVIOR_SEND, 330, 24, 58, 1, 108, 1}, /*DeletePath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 331, 24, 59, 1, 109, 1}, /*DeletePath2Cmd*/
    {6, CNA_BEHAVIOR_SEND, 332, 24, 60, 1, 110, 1}, /*DrvWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_UNSEND, 333, 24, 61, 1, 111, 1}, /*FlaoutUnlockSet*/
    {6, CNA_BEHAVIOR_NONE, 334, 24, 62, 0, 112, 1}, /*MbrMonrEnReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 335, 24, 62, 1, 113, 1}, /*P2P_PrkgDirectSwtCmd*/
    {5, CNA_BEHAVIOR_SEND, 336, 24, 63, 1, 114, 1}, /*ParkMdlCmd*/
    {6, CNA_BEHAVIOR_SEND, 337, 24, 64, 1, 115, 1}, /*PassWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 338, 24, 65, 1, 116, 1}, /*PathLrngFinshCmd*/
    {5, CNA_BEHAVIOR_SEND, 339, 24, 66, 1, 117, 1}, /*PathLrngStartCmd*/
    {6, CNA_BEHAVIOR_NONE, 340, 24, 67, 0, 118, 1}, /*PrkInDirChoice*/
    {6, CNA_BEHAVIOR_SEND, 341, 24, 67, 1, 119, 1}, /*RLWinSwtReq_VR*/
    {6, CNA_BEHAVIOR_SEND, 342, 24, 68, 1, 120, 1}, /*RRWinSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 344, 24, 69, 1, 121, 1}, /*SelPrkOutDirReq*/
    {5, CNA_BEHAVIOR_SEND, 343, 24, 70, 1, 122, 1}, /*SelPrkgFctnCmd*/
    {5, CNA_BEHAVIOR_SEND, 345, 24, 71, 1, 123, 1}, /*StartPrkgPath1Cmd*/
    {5, CNA_BEHAVIOR_SEND, 346, 24, 72, 1, 124, 1}, /*StartPrkgPath2Cmd*/
    {6, CNA_BEHAVIOR_UNSEND, 347, 24, 73, 1, 125, 1}, /*SuperLockSet*/
    {5, CNA_BEHAVIOR_NONE, 169, 11, 74, 0, 126, 1}, /*ABSLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 170, 11, 74, 1, 127, 1}, /*ACDrvSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 171, 11, 75, 1, 128, 1}, /*ACEAHReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 172, 11, 76, 1, 129, 1}, /*ACEAHReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 173, 11, 77, 1, 130, 1}, /*ACOperMod_TC*/
    {5, CNA_BEHAVIOR_SEND, 174, 11, 78, 1, 131, 1}, /*ACOperMod_VR*/
    {5, CNA_BEHAVIOR_SEND, 175, 11, 79, 1, 132, 1}, /*ACPassSetTempSteplsReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 176, 11, 80, 1, 133, 1}, /*APSPrkgTypSeln*/
    {5, CNA_BEHAVIOR_SEND, 177, 11, 81, 1, 134, 1}, /*APSSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 178, 11, 82, 0, 135, 1}, /*AutoWshWipSet*/
    {5, CNA_BEHAVIOR_NONE, 179, 11, 82, 0, 136, 1}, /*DoorUnlockModSet*/
    {5, CNA_BEHAVIOR_SEND, 181, 11, 82, 1, 137, 1}, /*PASExitSpdSwt*/
    {5, CNA_BEHAVIOR_NONE, 180, 11, 83, 0, 138, 1}, /*ParkLmpSet*/
    {5, CNA_BEHAVIOR_SEND, 182, 11, 83, 1, 139, 1}, /*SDWSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 183, 11, 84, 0, 140, 1}, /*SeekVehSet*/
    {5, CNA_BEHAVIOR_NONE, 184, 11, 84, 0, 141, 1}, /*SpdAutoLockModSet*/
    {5, CNA_BEHAVIOR_NONE, 185, 11, 84, 0, 142, 1}, /*SportModLightSet*/
    {5, CNA_BEHAVIOR_SEND, 186, 11, 84, 1, 143, 1}, /*SteerWheelHeatSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 187, 11, 85, 1, 144, 1}, /*SunRoofSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 188, 11, 86, 1, 145, 1}, /*SunShadeSwtReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 425, 32, 87, 0, 146, 1}, /*ALCMBreSwt*/
    {5, CNA_BEHAVIOR_NONE, 426, 32, 87, 0, 147, 1}, /*ALCMFloSwt*/
    {5, CNA_BEHAVIOR_SEND, 418, 32, 87, 1, 148, 1}, /*DrvDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 417, 32, 88, 0, 149, 1}, /*FootALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 424, 32, 88, 0, 150, 1}, /*FootALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 420, 32, 88, 1, 151, 1}, /*LRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 415, 32, 89, 1, 152, 1}, /*LeftPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 422, 32, 90, 1, 153, 1}, /*LeftPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 419, 32, 91, 1, 154, 1}, /*PassDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 414, 32, 92, 1, 155, 1}, /*RRDoorALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 421, 32, 93, 1, 156, 1}, /*RRDoorALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_SEND, 416, 32, 94, 1, 157, 1}, /*RightPanelALCMClrSet*/
    {5, CNA_BEHAVIOR_SEND, 423, 32, 95, 1, 158, 1}, /*RightPanelALCMLightLvlSet*/
    {5, CNA_BEHAVIOR_CYCLE, 428, 33, 96, 1, 159, 1}, /*SmtSeatSwt*/
    {5, CNA_BEHAVIOR_NONE, 260, 18, 97, 0, 160, 1}, /*ADAS_Stub_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 261, 18, 97, 0, 161, 1}, /*ADAS_Stub_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 262, 18, 97, 0, 162, 1}, /*ADAS_Stub_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 263, 18, 97, 0, 163, 1}, /*ADAS_Stub_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 264, 18, 97, 0, 164, 1}, /*ADAS_Stub_LastStub*/
    {5, CNA_BEHAVIOR_NONE, 265, 18, 97, 0, 165, 1}, /*ADAS_Stub_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 266, 18, 97, 0, 166, 1}, /*ADAS_Stub_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 267, 18, 97, 0, 167, 1}, /*ADAS_Stub_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 268, 18, 97, 0, 168, 2}, /*ADAS_Stub_Offset*/
    {5, CNA_BEHAVIOR_NONE, 269, 18, 97, 0, 170, 1}, /*ADAS_Stub_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 270, 18, 97, 0, 171, 1}, /*ADAS_Stub_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 271, 18, 97, 0, 172, 1}, /*ADAS_Stub_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 272, 18, 97, 0, 173, 1}, /*ADAS_Stub_Retr*/
    {5, CNA_BEHAVIOR_NONE, 273, 18, 97, 0, 174, 1}, /*ADAS_Stub_RtOfWay*/
    {5, CNA_BEHAVIOR_NONE, 274, 18, 97, 0, 175, 1}, /*ADAS_Stub_StubPathIdx*/
    {5, CNA_BEHAVIOR_NONE, 275, 18, 97, 0, 176, 1}, /*ADAS_Stub_TurnAngl*/
    {5, CNA_BEHAVIOR_NONE, 276, 18, 97, 0, 177, 1}, /*ADAS_Stub_Update*/
    {5, CNA_BEHAVIOR_NONE, 240, 17, 97, 0, 178, 1}, /*ADAS_Seg_Brdg*/
    {5, CNA_BEHAVIOR_NONE, 241, 17, 97, 0, 179, 1}, /*ADAS_Seg_BuildUpArea*/
    {5, CNA_BEHAVIOR_NONE, 242, 17, 97, 0, 180, 1}, /*ADAS_Seg_CmplxInsct*/
    {5, CNA_BEHAVIOR_NONE, 243, 17, 97, 0, 181, 1}, /*ADAS_Seg_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 244, 17, 97, 0, 182, 1}, /*ADAS_Seg_DivideRoad*/
    {5, CNA_BEHAVIOR_NONE, 245, 17, 97, 0, 183, 1}, /*ADAS_Seg_EffSpdLmt*/
    {5, CNA_BEHAVIOR_NONE, 246, 17, 97, 0, 184, 1}, /*ADAS_Seg_EffSpdLmtTyp*/
    {5, CNA_BEHAVIOR_NONE, 247, 17, 97, 0, 185, 1}, /*ADAS_Seg_FormOfWay*/
    {5, CNA_BEHAVIOR_NONE, 248, 17, 97, 0, 186, 1}, /*ADAS_Seg_FuncRoadClass*/
    {5, CNA_BEHAVIOR_NONE, 249, 17, 97, 0, 187, 1}, /*ADAS_Seg_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 250, 17, 97, 0, 188, 1}, /*ADAS_Seg_NumOfLaneDrvDir*/
    {5, CNA_BEHAVIOR_NONE, 251, 17, 97, 0, 189, 1}, /*ADAS_Seg_NumOfLaneOppDir*/
    {5, CNA_BEHAVIOR_NONE, 252, 17, 97, 0, 190, 2}, /*ADAS_Seg_Offset*/
    {5, CNA_BEHAVIOR_NONE, 253, 17, 97, 0, 192, 1}, /*ADAS_Seg_PartOfCalcRoute*/
    {5, CNA_BEHAVIOR_NONE, 254, 17, 97, 0, 193, 1}, /*ADAS_Seg_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 255, 17, 97, 0, 194, 1}, /*ADAS_Seg_RelProbb*/
    {5, CNA_BEHAVIOR_NONE, 256, 17, 97, 0, 195, 1}, /*ADAS_Seg_Retr*/
    {5, CNA_BEHAVIOR_NONE, 257, 17, 97, 0, 196, 1}, /*ADAS_Seg_Tunnel*/
    {5, CNA_BEHAVIOR_NONE, 258, 17, 97, 0, 197, 1}, /*ADAS_Seg_Update*/
    {5, CNA_BEHAVIOR_NONE, 227, 16, 97, 0, 198, 1}, /*ADAS_ProfShort_AccurClass*/
    {5, CNA_BEHAVIOR_NONE, 228, 16, 97, 0, 199, 1}, /*ADAS_ProfShort_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 229, 16, 97, 0, 200, 1}, /*ADAS_ProfShort_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 230, 16, 97, 0, 201, 2}, /*ADAS_ProfShort_Dist1*/
    {5, CNA_BEHAVIOR_NONE, 231, 16, 97, 0, 203, 1}, /*ADAS_ProfShort_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 232, 16, 97, 0, 204, 2}, /*ADAS_ProfShort_Offset*/
    {5, CNA_BEHAVIOR_NONE, 233, 16, 97, 0, 206, 1}, /*ADAS_ProfShort_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 234, 16, 97, 0, 207, 1}, /*ADAS_ProfShort_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 235, 16, 97, 0, 208, 1}, /*ADAS_ProfShort_Retr*/
    {5, CNA_BEHAVIOR_NONE, 236, 16, 97, 0, 209, 1}, /*ADAS_ProfShort_Update*/
    {5, CNA_BEHAVIOR_NONE, 237, 16, 97, 0, 210, 2}, /*ADAS_ProfShort_Value0*/
    {5, CNA_BEHAVIOR_NONE, 238, 16, 97, 0, 212, 2}, /*ADAS_ProfShort_Value1*/
    {5, CNA_BEHAVIOR_NONE, 217, 15, 97, 0, 214, 1}, /*ADAS_ProfLong_CtrlPoint*/
    {5, CNA_BEHAVIOR_NONE, 218, 15, 97, 0, 215, 1}, /*ADAS_ProfLong_CycCnt*/
    {5, CNA_BEHAVIOR_NONE, 219, 15, 97, 0, 216, 1}, /*ADAS_ProfLong_MsgTyp*/
    {5, CNA_BEHAVIOR_NONE, 220, 15, 97, 0, 217, 2}, /*ADAS_ProfLong_Offset*/
    {5, CNA_BEHAVIOR_NONE, 221, 15, 97, 0, 219, 1}, /*ADAS_ProfLong_PathIdx*/
    {5, CNA_BEHAVIOR_NONE, 222, 15, 97, 0, 220, 1}, /*ADAS_ProfLong_ProfTyp*/
    {5, CNA_BEHAVIOR_NONE, 223, 15, 97, 0, 221, 1}, /*ADAS_ProfLong_Retr*/
    {5, CNA_BEHAVIOR_NONE, 224, 15, 97, 0, 222, 1}, /*ADAS_ProfLong_Update*/
    {5, CNA_BEHAVIOR_NONE, 225, 15, 97, 0, 223, 4}, /*ADAS_ProfLong_Value*/
    {5, CNA_BEHAVIOR_SEND, 146, 9, 97, 1, 227, 1}, /*ACAIUReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 147, 9, 98, 1, 228, 1}, /*ACAQSReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 148, 9, 99, 1, 229, 1}, /*ACDualReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 149, 9, 100, 1, 230, 1}, /*ACPassTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 150, 9, 101, 1, 231, 1}, /*ACRearDefrstReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 151, 9, 102, 0, 232, 1}, /*ALCMClrSet*/
    {5, CNA_BEHAVIOR_NONE, 152, 9, 102, 0, 233, 1}, /*ALCMDynSwt*/
    {5, CNA_BEHAVIOR_NONE, 153, 9, 102, 0, 234, 1}, /*ALCMRhmSwt*/
    {5, CNA_BEHAVIOR_NONE, 154, 9, 102, 0, 235, 1}, /*ALCMStatSwt*/
    {3, CNA_BEHAVIOR_SEND, 155, 9, 102, 1, 236, 1}, /*HUT_BeanIDReq*/
    {5, CNA_BEHAVIOR_UNSEND, 158, 9, 103, 1, 237, 1}, /*HUT_EgyRecvrySet*/
    {5, CNA_BEHAVIOR_NONE, 157, 9, 104, 0, 238, 1}, /*IPVolSet*/
    {5, CNA_BEHAVIOR_SEND, 156, 9, 104, 1, 239, 1}, /*PASSwtReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 278, 19, 105, 1, 240, 1}, /*ACDrvSetTempReq_ETC_VR*/
    {5, CNA_BEHAVIOR_SEND, 279, 19, 106, 1, 241, 1}, /*ACDrvSetTempSteplsReq_ETC_TC*/
    {5, CNA_BEHAVIOR_NONE, 281, 19, 107, 0, 242, 1}, /*CarWashMode_Req*/
    {5, CNA_BEHAVIOR_NONE, 283, 19, 107, 0, 243, 1}, /*HUT_BattKeepTemp*/
    {5, CNA_BEHAVIOR_SEND, 285, 19, 107, 1, 244, 1}, /*HUT_BattSOCLim*/
    {5, CNA_BEHAVIOR_UNSEND, 282, 19, 108, 1, 245, 1}, /*HUT_ChrgnMode*/
    {5, CNA_BEHAVIOR_NONE, 286, 19, 109, 0, 246, 1}, /*HUT_IntelBattTempMagSet*/
    {5, CNA_BEHAVIOR_NONE, 284, 19, 109, 0, 247, 1}, /*HUT_IntelEngIdlChrgnSet*/
    {5, CNA_BEHAVIOR_SEND, 280, 19, 109, 1, 248, 1}, /*HUT_RemtEngCtrl*/
    {5, CNA_BEHAVIOR_NONE, 197, 13, 110, 0, 249, 1}, /*AVMMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_NONE, 195, 13, 110, 0, 250, 1}, /*AVMSwtReq*/
    {5, CNA_BEHAVIOR_SEND, 192, 13, 110, 1, 251, 1}, /*BackgroundLightLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 198, 13, 111, 0, 252, 1}, /*FPASChanSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 201, 13, 111, 0, 253, 1}, /*HUT_V2VStart*/
    {5, CNA_BEHAVIOR_NONE, 196, 13, 111, 0, 254, 1}, /*NaviMediaVolLvlReq*/
    {5, CNA_BEHAVIOR_UNSEND, 200, 13, 111, 1, 255, 1}, /*OPDSwtSts*/
    {5, CNA_BEHAVIOR_UNSEND, 193, 13, 112, 1, 256, 1}, /*PLGReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 199, 13, 113, 0, 257, 1}, /*RPASChanSwtReq*/
    {5, CNA_BEHAVIOR_UNSEND, 194, 13, 113, 1, 258, 1}, /*WPC_SwtReq*/
    {5, CNA_BEHAVIOR_SEND, 36, 3, 114, 1, 259, 1}, /*ACAIUReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 37, 3, 115, 1, 260, 1}, /*ACAQSReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 35, 3, 116, 1, 261, 1}, /*ACAirInletReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 38, 3, 117, 1, 262, 1}, /*ACAutoModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 39, 3, 118, 1, 263, 1}, /*ACBlwrsteplsSpdReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 40, 3, 119, 1, 264, 1}, /*ACCmprReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 41, 3, 120, 1, 265, 1}, /*ACDrvAirDistribModReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 42, 3, 121, 1, 266, 1}, /*ACDrvTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 43, 3, 122, 1, 267, 1}, /*ACDrvTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 44, 3, 123, 1, 268, 1}, /*ACDualReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 45, 3, 124, 1, 269, 1}, /*ACFrntBlwrSpdDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 46, 3, 125, 1, 270, 1}, /*ACFrntBlwrSpdIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 47, 3, 126, 1, 271, 1}, /*ACFrntDefrstReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 48, 3, 127, 1, 272, 1}, /*ACFrntPassTempDecReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 49, 3, 128, 1, 273, 1}, /*ACFrntPassTempIncReq_TC*/
    {5, CNA_BEHAVIOR_SEND, 50, 3, 129, 1, 274, 1}, /*ACOffReq_TC*/
    {5, CNA_BEHAVIOR_NONE, 51, 3, 130, 0, 275, 1}, /*BattSaveDelayTimeSet*/
    {5, CNA_BEHAVIOR_NONE, 52, 3, 130, 0, 276, 1}, /*ChairMemPosnEna*/
    {5, CNA_BEHAVIOR_NONE, 53, 3, 130, 0, 277, 1}, /*DomeLmpDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 54, 3, 130, 0, 278, 1}, /*DrvDrowsnsDetnSet*/
    {5, CNA_BEHAVIOR_NONE, 55, 3, 130, 0, 279, 1}, /*FolwMeHomeDlyTimSet*/
    {5, CNA_BEHAVIOR_NONE, 56, 3, 130, 0, 280, 1}, /*RearviewFoldModSet*/
    {5, CNA_BEHAVIOR_NONE, 57, 3, 130, 0, 281, 1}, /*TranPMode_Req*/
    {5, CNA_BEHAVIOR_NONE, 66, 4, 130, 0, 282, 1}, /*AMP_AudioVolVSCModReq*/
    {5, CNA_BEHAVIOR_NONE, 64, 4, 130, 0, 283, 1}, /*AMP_BeepSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 67, 4, 130, 0, 284, 1}, /*AMP_FRAudioFaderSet*/
    {5, CNA_BEHAVIOR_NONE, 71, 4, 130, 0, 285, 1}, /*AMP_HighFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 65, 4, 130, 0, 286, 1}, /*AMP_LRAudioBalanceSet*/
    {5, CNA_BEHAVIOR_NONE, 68, 4, 130, 0, 287, 1}, /*AMP_LRDrvSideSet*/
    {5, CNA_BEHAVIOR_NONE, 69, 4, 130, 0, 288, 1}, /*AMP_LowFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 62, 4, 130, 0, 289, 1}, /*AMP_MediaCallSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 70, 4, 130, 0, 290, 1}, /*AMP_MidFrqAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 61, 4, 130, 0, 291, 1}, /*AMP_MuteSet*/
    {5, CNA_BEHAVIOR_NONE, 63, 4, 130, 0, 292, 1}, /*AMP_NaviSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 73, 4, 130, 0, 293, 1}, /*ANCSwtSet*/
    {5, CNA_BEHAVIOR_NONE, 60, 4, 130, 0, 294, 1}, /*FrntWinHeatSwt*/
    {5, CNA_BEHAVIOR_SEND, 59, 4, 130, 1, 295, 1}, /*RearWinHeatCmd_TC*/
    {5, CNA_BEHAVIOR_NONE, 72, 4, 131, 0, 296, 1}, /*T_box_ECallSet*/
    {5, CNA_BEHAVIOR_NONE, 74, 4, 131, 0, 297, 1}, /*VRTTSSourceSet*/
    {5, CNA_BEHAVIOR_NONE, 87, 5, 131, 0, 298, 1}, /*AMP_BestListegPosnReq*/
    {5, CNA_BEHAVIOR_SEND, 84, 5, 131, 1, 299, 1}, /*AMP_GetDTCInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 81, 5, 132, 1, 300, 1}, /*AMP_GetHWInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 83, 5, 133, 1, 301, 1}, /*AMP_GetIntVoltInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 80, 5, 134, 1, 302, 1}, /*AMP_GetSWInfoReq*/
    {5, CNA_BEHAVIOR_SEND, 82, 5, 135, 1, 303, 1}, /*AMP_GetTempInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 77, 5, 136, 0, 304, 1}, /*AMP_HFMVolSet*/
    {5, CNA_BEHAVIOR_NONE, 76, 5, 136, 0, 305, 1}, /*AMP_MainVolSet*/
    {5, CNA_BEHAVIOR_NONE, 79, 5, 136, 0, 306, 1}, /*AMP_NaviVolSet*/
    {5, CNA_BEHAVIOR_NONE, 78, 5, 136, 0, 307, 1}, /*AMP_TTSVolSet_VR*/
    {5, CNA_BEHAVIOR_NONE, 96, 5, 136, 0, 308, 1}, /*HdPrivacyModeSet*/
    {5, CNA_BEHAVIOR_NONE, 88, 5, 136, 0, 309, 1}, /*HeadSpkVoiceSet*/
    {5, CNA_BEHAVIOR_NONE, 86, 5, 136, 0, 310, 1}, /*IESS_MdlInfoReq*/
    {5, CNA_BEHAVIOR_NONE, 85, 5, 136, 0, 311, 1}, /*IESS_MdlSwtReq*/
    {5, CNA_BEHAVIOR_NONE, 89, 5, 136, 0, 312, 1}, /*LShkActvt*/
    {5, CNA_BEHAVIOR_NONE, 91, 5, 136, 0, 313, 1}, /*LShkAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 94, 5, 136, 0, 314, 1}, /*PreBassSet*/
    {5, CNA_BEHAVIOR_NONE, 90, 5, 136, 0, 315, 1}, /*RShkActvt*/
    {5, CNA_BEHAVIOR_NONE, 92, 5, 136, 0, 316, 1}, /*RShkAudioSet*/
    {5, CNA_BEHAVIOR_NONE, 95, 5, 136, 0, 317, 1}, /*SmtVolActvt*/
    {5, CNA_BEHAVIOR_NONE, 93, 5, 136, 0, 318, 1}, /*SurrVoiceSet*/
    {5, CNA_BEHAVIOR_SEND, 98, 6, 136, 1, 319, 1}, /*ACAirInletReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 99, 6, 137, 1, 320, 1}, /*ACAutoModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 100, 6, 138, 1, 321, 1}, /*ACBlwrSpdReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 101, 6, 139, 1, 322, 1}, /*ACCmprReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 102, 6, 140, 1, 323, 1}, /*ACDrvAirDistribModReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 103, 6, 141, 1, 324, 1}, /*ACDrvTempReq_VR*/
    {5, CNA_BEHAVIOR_SEND, 104, 6, 142, 1, 325, 1}, /*ACFrntDefrostReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 105, 6, 143, 0, 326, 1}, /*ACModReq_HUT*/
    {5, CNA_BEHAVIOR_SEND, 106, 6, 143, 1, 327, 1}, /*ACPowerReq_VR*/
    {5, CNA_BEHAVIOR_NONE, 107, 6, 144, 0, 328, 1}, /*DrvSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 108, 6, 144, 0, 329, 1}, /*DrvSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 109, 6, 144, 0, 330, 1}, /*PassSeatHeatgLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 110, 6, 144, 0, 331, 1}, /*PassSeatVentnLvlSet*/
    {5, CNA_BEHAVIOR_NONE, 111, 6, 144, 0, 332, 1}, /*RemUpgrdSts*/
    {5, CNA_BEHAVIOR_CYCLE, 435, 34, 144, 1, 333, 1}, /*RearFogLmpSwtSts_HUT*/
    {5, CNA_BEHAVIOR_CYCLE, 303, 23, 145, 1, 334, 1}, /*ContnPrkgReq*/
    {5, CNA_BEHAVIOR_CYCLE, 306, 23, 146, 1, 335, 1}, /*PrkgCtrlModReq*/
    {5, CNA_BEHAVIOR_CYCLE, 288, 20, 147, 1, 336, 1}, /*DrvSeatSupportPosnSwt*/
    {5, CNA_BEHAVIOR_CYCLE, 471, 36, 148, 1, 337, 1}, /*ChairMemPosnSet*/
    {5, CNA_BEHAVIOR_CYCLE, 477, 36, 149, 1, 338, 1}, /*EPSSteerModSwtReq*/
    {5, CNA_BEHAVIOR_CYCLE, 525, 36, 150, 1, 339, 1}, /*HUT_DrvModReq*/
    {5, CNA_BEHAVIOR_CYCLE, 161, 10, 151, 1, 340, 1}, /*HUT_AVHSwitchSts*/
    {5, CNA_BEHAVIOR_CYCLE, 162, 10, 152, 1, 341, 1}, /*HUT_EPB_SwtPosn*/
    {5, CNA_BEHAVIOR_CYCLE, 163, 10, 153, 1, 342, 1}, /*HUT_HDCSwitchCtrl*/
    {5, CNA_BEHAVIOR_CYCLE, 165, 10, 154, 1, 343, 1}, /*ORVMFoldSwt_HUT*/
};

static CNA_SignalType cna_signalDatas[334] = {0u};
static const uint8 cna_noActionBuffer[155] =
{
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
    3u,
    0u,
    0u,
    0u,
    6u,
    3u,
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
    3u,
    10u,
    0u,
    0u,
    0u,
    0u,
};

static const ComEx_SignalIdType CNA_IdTable[650] =
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
    251,
    249,
    250,
    252,
    253,
    254,
    255,
    256,
    257,
    258,
    259,
    260,
    261,
    262,
    263,
    264,
    265,
    266,
    267,
    268,
    269,
    270,
    271,
    65535,
    285,
    284,
    281,
    279,
    282,
    273,
    276,
    272,
    274,
    277,
    278,
    280,
    275,
    286,
    283,
    287,
    65535,
    295,
    294,
    297,
    296,
    292,
    290,
    293,
    291,
    289,
    301,
    300,
    288,
    299,
    302,
    305,
    303,
    306,
    308,
    304,
    307,
    298,
    65535,
    309,
    310,
    311,
    312,
    313,
    314,
    315,
    316,
    317,
    318,
    319,
    320,
    321,
    322,
    65535,
    16,
    14,
    15,
    17,
    18,
    19,
    20,
    21,
    22,
    25,
    23,
    24,
    26,
    27,
    28,
    29,
    30,
    65535,
    9,
    7,
    8,
    10,
    5,
    1,
    2,
    4,
    0,
    3,
    11,
    12,
    6,
    13,
    65535,
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
    229,
    228,
    227,
    65535,
    65535,
    330,
    331,
    332,
    65535,
    333,
    65535,
    65535,
    65535,
    126,
    127,
    128,
    129,
    130,
    131,
    132,
    133,
    134,
    135,
    136,
    138,
    137,
    139,
    140,
    141,
    142,
    143,
    144,
    145,
    65535,
    65535,
    65535,
    241,
    246,
    248,
    240,
    244,
    239,
    242,
    247,
    245,
    243,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    208,
    209,
    210,
    211,
    212,
    213,
    214,
    215,
    216,
    65535,
    196,
    197,
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
    65535,
    177,
    178,
    179,
    180,
    181,
    182,
    183,
    184,
    185,
    186,
    187,
    188,
    189,
    190,
    191,
    192,
    193,
    194,
    195,
    65535,
    160,
    161,
    162,
    163,
    164,
    165,
    166,
    167,
    168,
    169,
    170,
    171,
    172,
    173,
    174,
    175,
    176,
    65535,
    230,
    231,
    238,
    232,
    235,
    233,
    237,
    234,
    236,
    65535,
    326,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    77,
    78,
    79,
    80,
    65535,
    65535,
    324,
    65535,
    65535,
    325,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    101,
    102,
    103,
    104,
    105,
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
    116,
    117,
    118,
    119,
    120,
    122,
    121,
    123,
    124,
    125,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    58,
    59,
    61,
    60,
    65535,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    65535,
    100,
    93,
    94,
    95,
    96,
    97,
    98,
    99,
    65535,
    70,
    74,
    72,
    75,
    71,
    73,
    76,
    65535,
    87,
    92,
    81,
    82,
    83,
    84,
    85,
    86,
    91,
    89,
    90,
    88,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    155,
    152,
    157,
    149,
    148,
    154,
    151,
    156,
    153,
    158,
    150,
    146,
    147,
    65535,
    159,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    323,
    65535,
    65535,
    49,
    55,
    57,
    53,
    48,
    54,
    52,
    51,
    56,
    50,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    327,
    65535,
    65535,
    65535,
    65535,
    65535,
    328,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    329,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    31,
    32,
    34,
    33,
    35,
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    47,
    46,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
    65535,
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

static uint8 cna_currentBuffer[344] = {0};

const CNA_ConfigType cna_config =
{
    334u,
    cna_signalConfigs,
    cna_signalDatas,
    155u,
    cna_noActionBuffer,
    344u,
    cna_currentBuffer,
    650u,
    CNA_IdTable
};


