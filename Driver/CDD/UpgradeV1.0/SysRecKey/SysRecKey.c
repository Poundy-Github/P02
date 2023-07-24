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
 * @file:      SysRecKey.c
 * @author:    Nobo
 * @date:      2020-12-7
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-7
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef SYSRECKEY_SOURCE
#define SYSRECKEY_SOURCE

#ifdef GWM_V35_PROJECT_TYPE_B02
    #define B02_USECOMEXIF
#elif defined GWM_V35_PROJECT_TYPE_P05
    #define P05_USECOMEXIF
#elif defined GWM_V35_PROJECT_TYPE_P03
	#define P03_USECOMEXIF
#endif

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Platform_Types.h"
#include "Rte_Upgrade.h"
#include "logger.h"

#if (defined B02_USECOMEXIF) || (defined P05_USECOMEXIF) || (defined P03_USECOMEXIF)
    #include "ComEx_Cfg.h"
#endif

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define UPGRADE_TASK_CYC        (10)
#define UPGRADE_TO_MINSYS(T)   (T/UPGRADE_TASK_CYC)
#define UPGRADE_TO_MINSYS_15S   (UPGRADE_TO_MINSYS(15*1000))
/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**
 * @brief 
 * \struct 
 * 
 */
typedef struct
{
    boolean KeyPress;
    boolean ToMinSys;
    uint32 timeCount;
} SysRecKey_st;

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
static void Sys_Event_toMinSysKey(void);
static void Sys_Free_toMinSysKey(void);
/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
SysRecKey_st SysRecKeyPcb = {0};
 /* KeyAttribute_st: Record with elements
 *   KeyList of type KeyTypeArray
 *   KeyCnt of type uint8
 *   PressTime of type uint32
 *   PressCnt of type uint8
 *   OnlyKey of type boolean
 *   EventCallout of type uint32
 *   FreeCallout of type uint32
 */
#ifndef GWM_V35_PROJECT_TYPE_A07
KeyAttribute_st toMinSysKey = {
        {AdjVolUp, PageUp},
        2,
        15000,
        1,
        TRUE,
        (uint32)Sys_Event_toMinSysKey,
        (uint32)Sys_Free_toMinSysKey
};
#endif
uint32 toMinSysKeyId = 0xff;
/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/

static void Sys_Event_toMinSysKey(void)
{
    // upgrade_info("To enter the minimum system combination key is [pressed] !! \r\n");
    // Rte_Write_ppSR_Upgrade_System_Recovery_System_Recovery(TRUE);
    // upgrade_info("The key combination continues to press 15s waiting to enter the minimum system !! \r\n");
}

static void Sys_Free_toMinSysKey(void)
{
    (void)upgrade_info("Enter the minimum system key combination to be [released] !! \r\n");
}
/**
 * @brief Initializes the SysRecKeyPcb to an unpressed state
 * 
 */
void SysRecKey_Init(void)
{
//     SysRecKeyPcb.KeyPress = FALSE; //!  TRUE: Press ,FALSE: unPress
//     SysRecKeyPcb.ToMinSys = FALSE; //!  Set to TRUE when sure to enter the small system, other states do not transition, waiting to enter the minimum system
//     SysRecKeyPcb.timeCount = UPGRADE_TO_MINSYS_15S; //!  A task cycle of 10ms
//     Rte_Write_ppSR_Upgrade_System_Recovery_System_Recovery(FALSE);
// #ifndef GWM_V35_PROJECT_TYPE_A07
//     Rte_Call_KeyReturn_Server_register(&toMinSysKey, &toMinSysKeyId);
// #endif
}

/**********************************************************************************************************************
 *  END OF FILE: SysRecKey.c
 *********************************************************************************************************************/
#endif //SYSRECKEY_SOURCE
