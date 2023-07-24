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
 * @file:      Misc_Board.c
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

#include <string.h>
#include "Rte_Misc.h"
#include "Dio.h"

#include "Port.h"


#include "IoHwAb.h"
#include "IoHwAb_Cfg_RI.h"
#include "Misc_Board.h"
#include "logger.h"
#include "Ext_Power.h"

typedef struct Misc_BoardSelfData_t
{
    uint32  u32VIP_Version_MON1;
    uint32  u32VIP_Version_MON2;
    uint8   u8DelayCycle;
    uint8   VIP_HW_Version;
    boolean bVersionIsReady;
}Misc_BoardSelfData_t;


typedef struct Misc_BoardMONCfg_t
{
    uint32 u32Max;
    uint32 u32Min;
}Misc_BoardMONCfg_t;

typedef struct Misc_BoardVersionCfg_t
{
    Misc_BoardMONCfg_t tMON1;
    Misc_BoardMONCfg_t tMON2;
    uint8 Verson;
    const char  *VersonStr;
}Misc_BoardVersionCfg_t;

#define BoardVersionCfgSize           ((sizeof(BoardVersionCfg))/sizeof(BoardVersionCfg[0]))  

#define Misc_START_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern Std_ReturnType IoHwAb_GetPin(uint8 Id, boolean * Pin);
static void Misc_Board_CheckTunerDebug2(void);
static Misc_BoardSelfData_t BoardSelfData = {0};

static const Misc_BoardVersionCfg_t BoardVersionCfg[] = 
{
	//careful:1.hardware and software describle not equal
	//careful:2.B0/B1 was develop version , it's allow to modified the section min/max value
	//careful:3.C0/C1 was release and outused version , it's don't allow to modified the section min/max value
    {0x40,  0,    0xA65, 0x600, eMiscBoard_Version_A1,"A1"},
    {0x100, 0x50, 0x9B, 0x50,  eMiscBoard_Version_B0,"B0"},//HW discrible Was B0 ;R2052=[ 75k] but [68k or 56k or 47k or 43k or 33k] was at this section
    {0x100, 0x50, 0x220, 0x150, eMiscBoard_Version_B1,"B1"},//HW discrible Was B1 ;R2052=[ 18k] but [15k ] was at this section
    {0x100, 0x50, 0x3EB, 0x240, eMiscBoard_Version_C0,"C0"},//HW discrible Was C1 ;R2052=[ 10k] but [7.5k] was at this section
    {0x100, 0x50, 0x5DC, 0x410, eMiscBoard_Version_C1,"C1"},//HW discrible Was SOP;R2052=[4.7k] but [5.6k or 4.7k or 4.3k] was at this section
    {0x100, 0x50, 0x72E, 0x5DD, eMiscBoard_Version_C2,"C2"},//HW discrible Was C2 ;R2052=[3.3k] USB2.0 Charge use MPQ4228 , reruest by hardware at 20211019
    {0x100, 0x50, 0x861, 0x72F, eMiscBoard_Version_C3,"C3"},//HW discrible Was C3 ;R2052=[2.2k] USB2.0 Charge use MPQ5073 not support fast charge , reruest by hardware at 20211019
    {0x100, 0x50, 0x942, 0x862, eMiscBoard_Version_C4,"C4"},//HW discrible Was C4 ;R2052=[1.8k] MainBoard+UpBoard was fast charge , reruest by hardware at 20211201
    {0x100, 0x50, 0xC8,  0x9C,  eMiscBoard_Version_C5,"C5"},//HW discrible Was C5 ;R2052=[ 47k] MainBoard+UpBoard was low charge , reruest by hardware at 20212101
};

#define Misc_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Misc_START_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void Misc_Board_CheckHwVersion(void);
static void Misc_Board_Alg(void);

void Misc_Board_Init(void)
{
    memset(&BoardSelfData,0,sizeof(BoardSelfData));
}

void Misc_Board_Task(void)
{
    if (BoardSelfData.bVersionIsReady == FALSE)
    {
        // Delay for a period of time, waiting for the level to stabilize.
        
        if (BoardSelfData.u8DelayCycle < MiscBoard_WaitingCycle)
        {
            BoardSelfData.u8DelayCycle++;
        }
        else
        {
            Std_ReturnType ret = 0;
            
            ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON1_IAN,&BoardSelfData.u32VIP_Version_MON1);
            ret |= IoHwAb_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON2_IAN,&BoardSelfData.u32VIP_Version_MON2);

            if (E_OK == ret)
            {
                Misc_Board_CheckHwVersion();
                Misc_Board_Alg();
                BoardSelfData.bVersionIsReady = TRUE;
            }
        }
    }

    Misc_Board_CheckTunerDebug2();
}

static void Misc_Board_CheckTunerDebug2(void)
{
    boolean Value = FALSE;
    Std_ReturnType ret = E_NOT_OK;

    ret = IoHwAb_GetPin(RI_IoHwAb_DIn_PinInCfg_Tuner_VIP_debug2,&Value);

    if (ret == E_OK)
    {
        Dio_WriteChannel(DioConf_DioChannel_VIP_SWITCH_SPI_EN,(Dio_LevelType)Value);
    }
}

static void Misc_Board_CheckHwVersion(void)
{
    uint8 i;

    for (i=0u; i<BoardVersionCfgSize; i++)
    {
        if ( (BoardSelfData.u32VIP_Version_MON1 <= BoardVersionCfg[i].tMON1.u32Max)&&
             (BoardSelfData.u32VIP_Version_MON1 >= BoardVersionCfg[i].tMON1.u32Min)&&
             (BoardSelfData.u32VIP_Version_MON2 <= BoardVersionCfg[i].tMON2.u32Max)&&
             (BoardSelfData.u32VIP_Version_MON2 >= BoardVersionCfg[i].tMON2.u32Min)
           )
           {
               break;
           }
    }
	misc_warn("HWVersionADCWas : M1=0x%x, M2=0x%x\r\n",BoardSelfData.u32VIP_Version_MON1,BoardSelfData.u32VIP_Version_MON2);
    if (BoardVersionCfgSize == i)
    {
        BoardSelfData.VIP_HW_Version = MiscBoard_Version_Def;
        misc_warn("HW Version is invalid !!! MON1:%x; MON2:%x",BoardSelfData.u32VIP_Version_MON1,BoardSelfData.u32VIP_Version_MON2);
        misc_warn("The hardware version number USES the default value.");
    }
    else
    {
        BoardSelfData.VIP_HW_Version = BoardVersionCfg[i].Verson;
        misc_warn("Hardware Version %s",BoardVersionCfg[i].VersonStr);
    }
    
}

static void Misc_Board_Alg(void)
{
    if (BoardSelfData.VIP_HW_Version == eMiscBoard_Version_A1)
    {
        // Disabled WD
        Dio_WriteChannel(DioConf_DioChannel_VIP_WD_enable,STD_HIGH);
    }
}

Std_ReturnType Misc_Board_GetHwVersion(uint8 * ver)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR == ver)
    {
        ret = E_NOT_OK;
    }
    else if ( FALSE == BoardSelfData.bVersionIsReady)
    {
        *ver = eMiscBoard_Version_Non;
        ret = E_NOT_OK;
    }
    else
    {
        *ver = BoardSelfData.VIP_HW_Version;
        ret = E_OK;
    }
    
    return ret;
}



#define Misc_STOP_SEC_CODE
#include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */







