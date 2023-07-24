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
 * @file:      Misc_Board.h
 * @author:    Nobo
 * @date:      2020-10-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _MISC_BOARD_H_
#define _MISC_BOARD_H_

//careful:1.hardware and software describle not equal
//careful:2.B0/B1 was develop version , it's allow to modified the section min/max value
//careful:3.C0/C1 was release and outused version , it's don't allow to modified the section min/max value
#define eMiscBoard_Version_Non          (0u)
#define eMiscBoard_Version_A1           (1u)
#define eMiscBoard_Version_B0           (2u)
#define eMiscBoard_Version_B1           (3u)
#define eMiscBoard_Version_C0           (4u)//hardware named C1
#define eMiscBoard_Version_C1           (5u)//hardware named SOP
#define eMiscBoard_Version_C2           (6u)//fast charge
#define eMiscBoard_Version_C3           (7u)//low charge
#define eMiscBoard_Version_C4           (8u)//fast charge
#define eMiscBoard_Version_C5           (9u)//low charge

#define MiscBoard_Version_Def           eMiscBoard_Version_C5
#define MiscBoard_WaitingCycle          (20u)           // 100 ms


void Misc_Board_Init(void);
void Misc_Board_Task(void);
Std_ReturnType Misc_Board_GetHwVersion(uint8 * ver);

#endif /* ifndef _MISC_BOARD_H_.2020-10-19 19:35:19 GW00188879 */
