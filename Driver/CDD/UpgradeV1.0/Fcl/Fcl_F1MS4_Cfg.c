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
 * @file:      Fcl_F1MS4_Cfg.c
 * @author:    Nobo
 * @date:      2020-12-12
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-12
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef FCL_F1MS4_CFG_SOURCE
#define FCL_F1MS4_CFG_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Fcl_Api.h"
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/
const Fcl_Block const_blocks[] = {
    {0, 0x0, 0x1FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {1, 0x2000, 0x3FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {2, 0x4000, 0x5FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {3, 0x6000, 0x7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {4, 0x8000, 0x9FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {5, 0xA000, 0xBFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {6, 0xC000, 0xDFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {7, 0xE000, 0xFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {8, 0x10000, 0x17FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {9, 0x18000, 0x1FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {10, 0x20000, 0x27FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {11, 0x28000, 0x2FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {12, 0x30000, 0x37FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {13, 0x38000, 0x3FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {14, 0x40000, 0x47FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {15, 0x48000, 0x4FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {16, 0x50000, 0x57FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {17, 0x58000, 0x5FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {18, 0x60000, 0x67FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {19, 0x68000, 0x6FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {20, 0x70000, 0x77FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {21, 0x78000, 0x7FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {22, 0x80000, 0x87FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {23, 0x88000, 0x8FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {24, 0x90000, 0x97FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {25, 0x98000, 0x9FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {26, 0xA0000, 0xA7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {27, 0xA8000, 0xAFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {28, 0xB0000, 0xB7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {29, 0xB8000, 0xBFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {30, 0xC0000, 0xC7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {31, 0xC8000, 0xCFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {32, 0xD0000, 0xD7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {33, 0xD8000, 0xDFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {34, 0xE0000, 0xE7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {35, 0xE8000, 0xEFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {36, 0xF0000, 0xF7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {37, 0xF8000, 0xFFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {38, 0x100000, 0x107FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {39, 0x108000, 0x10FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {40, 0x110000, 0x117FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {41, 0x118000, 0x11FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {42, 0x120000, 0x127FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {43, 0x128000, 0x12FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {44, 0x130000, 0x137FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {45, 0x138000, 0x13FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {46, 0x140000, 0x147FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {47, 0x148000, 0x14FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {48, 0x150000, 0x157FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {49, 0x158000, 0x15FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {50, 0x160000, 0x167FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {51, 0x168000, 0x16FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {52, 0x170000, 0x177FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {53, 0x178000, 0x17FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {54, 0x180000, 0x187FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {55, 0x188000, 0x18FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {56, 0x190000, 0x197FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {57, 0x198000, 0x19FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {58, 0x1A0000, 0x1A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {59, 0x1A8000, 0x1AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {60, 0x1B0000, 0x1B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {61, 0x1B8000, 0x1BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {62, 0x1C0000, 0x1C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {63, 0x1C8000, 0x1CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {64, 0x1D0000, 0x1D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {65, 0x1D8000, 0x1DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {66, 0x1E0000, 0x1E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {67, 0x1E8000, 0x1EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {68, 0x1F0000, 0x1F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {69, 0x1F8000, 0x1FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {70, 0x200000, 0x207FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {71, 0x208000, 0x20FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {72, 0x210000, 0x217FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {73, 0x218000, 0x21FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {74, 0x220000, 0x227FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {75, 0x228000, 0x22FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {76, 0x230000, 0x237FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {77, 0x238000, 0x23FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {78, 0x240000, 0x247FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {79, 0x248000, 0x24FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {80, 0x250000, 0x257FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {81, 0x258000, 0x25FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {82, 0x260000, 0x267FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {83, 0x268000, 0x26FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {84, 0x270000, 0x277FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {85, 0x278000, 0x27FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {86, 0x280000, 0x287FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {87, 0x288000, 0x28FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {88, 0x290000, 0x297FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {89, 0x298000, 0x29FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {90, 0x2A0000, 0x2A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {91, 0x2A8000, 0x2AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {92, 0x2B0000, 0x2B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {93, 0x2B8000, 0x2BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {94, 0x2C0000, 0x2C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {95, 0x2C8000, 0x2CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {96, 0x2D0000, 0x2D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {97, 0x2D8000, 0x2DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {98, 0x2E0000, 0x2E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {99, 0x2E8000, 0x2EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {100, 0x2F0000, 0x2F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {101, 0x2F8000, 0x2FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {102, 0x300000, 0x307FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {103, 0x308000, 0x30FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {104, 0x310000, 0x317FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {105, 0x318000, 0x31FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {106, 0x320000, 0x327FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {107, 0x328000, 0x32FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {108, 0x330000, 0x337FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {109, 0x338000, 0x33FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {110, 0x340000, 0x347FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {111, 0x348000, 0x34FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {112, 0x350000, 0x357FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {113, 0x358000, 0x35FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {114, 0x360000, 0x367FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {115, 0x368000, 0x36FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {116, 0x370000, 0x377FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {117, 0x378000, 0x37FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {118, 0x380000, 0x387FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {119, 0x388000, 0x38FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {120, 0x390000, 0x397FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {121, 0x398000, 0x39FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {122, 0x3A0000, 0x3A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {123, 0x3A8000, 0x3AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {124, 0x3B0000, 0x3B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {125, 0x3B8000, 0x3BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {126, 0x3C0000, 0x3C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {127, 0x3C8000, 0x3CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {128, 0x3D0000, 0x3D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {129, 0x3D8000, 0x3DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {130, 0x3E0000, 0x3E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {131, 0x3E8000, 0x3EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {132, 0x3F0000, 0x3F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {133, 0x3F8000, 0x3FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
};
Fcl_Block blocks[] = {
    {0, 0x0, 0x1FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {1, 0x2000, 0x3FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {2, 0x4000, 0x5FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {3, 0x6000, 0x7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {4, 0x8000, 0x9FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {5, 0xA000, 0xBFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {6, 0xC000, 0xDFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {7, 0xE000, 0xFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {8, 0x10000, 0x17FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {9, 0x18000, 0x1FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {10, 0x20000, 0x27FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {11, 0x28000, 0x2FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {12, 0x30000, 0x37FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {13, 0x38000, 0x3FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {14, 0x40000, 0x47FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {15, 0x48000, 0x4FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {16, 0x50000, 0x57FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {17, 0x58000, 0x5FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {18, 0x60000, 0x67FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {19, 0x68000, 0x6FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {20, 0x70000, 0x77FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {21, 0x78000, 0x7FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {22, 0x80000, 0x87FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {23, 0x88000, 0x8FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {24, 0x90000, 0x97FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {25, 0x98000, 0x9FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {26, 0xA0000, 0xA7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {27, 0xA8000, 0xAFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {28, 0xB0000, 0xB7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {29, 0xB8000, 0xBFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {30, 0xC0000, 0xC7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {31, 0xC8000, 0xCFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {32, 0xD0000, 0xD7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {33, 0xD8000, 0xDFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {34, 0xE0000, 0xE7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {35, 0xE8000, 0xEFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {36, 0xF0000, 0xF7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {37, 0xF8000, 0xFFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {38, 0x100000, 0x107FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {39, 0x108000, 0x10FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {40, 0x110000, 0x117FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {41, 0x118000, 0x11FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {42, 0x120000, 0x127FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {43, 0x128000, 0x12FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {44, 0x130000, 0x137FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {45, 0x138000, 0x13FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {46, 0x140000, 0x147FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {47, 0x148000, 0x14FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {48, 0x150000, 0x157FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {49, 0x158000, 0x15FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {50, 0x160000, 0x167FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {51, 0x168000, 0x16FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {52, 0x170000, 0x177FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {53, 0x178000, 0x17FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {54, 0x180000, 0x187FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {55, 0x188000, 0x18FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {56, 0x190000, 0x197FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {57, 0x198000, 0x19FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {58, 0x1A0000, 0x1A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {59, 0x1A8000, 0x1AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {60, 0x1B0000, 0x1B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {61, 0x1B8000, 0x1BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {62, 0x1C0000, 0x1C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {63, 0x1C8000, 0x1CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {64, 0x1D0000, 0x1D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {65, 0x1D8000, 0x1DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {66, 0x1E0000, 0x1E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {67, 0x1E8000, 0x1EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {68, 0x1F0000, 0x1F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {69, 0x1F8000, 0x1FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {70, 0x200000, 0x207FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {71, 0x208000, 0x20FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {72, 0x210000, 0x217FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {73, 0x218000, 0x21FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {74, 0x220000, 0x227FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {75, 0x228000, 0x22FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {76, 0x230000, 0x237FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {77, 0x238000, 0x23FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {78, 0x240000, 0x247FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {79, 0x248000, 0x24FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {80, 0x250000, 0x257FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {81, 0x258000, 0x25FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {82, 0x260000, 0x267FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {83, 0x268000, 0x26FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {84, 0x270000, 0x277FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {85, 0x278000, 0x27FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {86, 0x280000, 0x287FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {87, 0x288000, 0x28FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {88, 0x290000, 0x297FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {89, 0x298000, 0x29FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {90, 0x2A0000, 0x2A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {91, 0x2A8000, 0x2AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {92, 0x2B0000, 0x2B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {93, 0x2B8000, 0x2BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {94, 0x2C0000, 0x2C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {95, 0x2C8000, 0x2CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {96, 0x2D0000, 0x2D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {97, 0x2D8000, 0x2DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {98, 0x2E0000, 0x2E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {99, 0x2E8000, 0x2EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {100, 0x2F0000, 0x2F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {101, 0x2F8000, 0x2FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {102, 0x300000, 0x307FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {103, 0x308000, 0x30FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {104, 0x310000, 0x317FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {105, 0x318000, 0x31FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {106, 0x320000, 0x327FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {107, 0x328000, 0x32FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {108, 0x330000, 0x337FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {109, 0x338000, 0x33FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {110, 0x340000, 0x347FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {111, 0x348000, 0x34FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {112, 0x350000, 0x357FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {113, 0x358000, 0x35FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {114, 0x360000, 0x367FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {115, 0x368000, 0x36FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {116, 0x370000, 0x377FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {117, 0x378000, 0x37FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {118, 0x380000, 0x387FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {119, 0x388000, 0x38FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {120, 0x390000, 0x397FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {121, 0x398000, 0x39FFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {122, 0x3A0000, 0x3A7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {123, 0x3A8000, 0x3AFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {124, 0x3B0000, 0x3B7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {125, 0x3B8000, 0x3BFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {126, 0x3C0000, 0x3C7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {127, 0x3C8000, 0x3CFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {128, 0x3D0000, 0x3D7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {129, 0x3D8000, 0x3DFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {130, 0x3E0000, 0x3E7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {131, 0x3E8000, 0x3EFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {132, 0x3F0000, 0x3F7FFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
    {133, 0x3F8000, 0x3FFFFF, 10, FCL_OP_IDLE, 10,FCL_OP_IDLE},
};
/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */

/**********************************************************************************************************************
 *  END OF FILE: Fcl_F1MS4_Cfg.c
 *********************************************************************************************************************/
#endif //FCL_F1MS4_CFG_SOURCE
