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
 * @file:      DcmEx_DtcCfg.c
 * @author:    Nobo
 * @date:      2020-5-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Rte_Vconfig.h"
#include "AMPVCfg.h"
#include "DcmEx.h"
#include "Vconfig.h"
#include "SecOC.h"
#include "IPC_EOL.h"
#include "EOL_Diag.h"
#include <string.h>

extern VConfig_Type vConfig;

boolean Dtc_AmpAvaiableCheck(uint32 dtc)
{
    boolean result = FALSE;
    uint16 ampChnSts = 0;

    ampChnSts = AMP_ChCfgSts();
    switch(dtc)
    {
        case 0x9A0101:
        case 0x9A0111:
        case 0x9A0112:
        case 0x9A0113:
        case 0x9A011E:
        case 0x9A0125:
        {
            if((ampChnSts & AMP_FL_CHN_ENABLE_MASK) == AMP_FL_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0201:
        case 0x9A0211:
        case 0x9A0212:
        case 0x9A0213:
        case 0x9A021E:
        case 0x9A0225:
        {
            if((ampChnSts & AMP_FR_CHN_ENABLE_MASK) == AMP_FR_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0301:
        case 0x9A0311:
        case 0x9A0312:
        case 0x9A0313:
        case 0x9A031E:
        case 0x9A0325:
        {
            if((ampChnSts & AMP_RL_CHN_ENABLE_MASK) == AMP_RL_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0401:
        case 0x9A0411:
        case 0x9A0412:
        case 0x9A0413:
        case 0x9A041E:
        case 0x9A0425:
        {
            if((ampChnSts & AMP_RR_CHN_ENABLE_MASK) == AMP_RR_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0501:
        case 0x9A0511:
        case 0x9A0512:
        case 0x9A0513:
        case 0x9A051E:
        case 0x9A0525:
        {
            if((ampChnSts & AMP_CENTER_CHN_ENABLE_MASK) == AMP_CENTER_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0601:
        case 0x9A0611:
        case 0x9A0612:
        case 0x9A0613:
        case 0x9A061E:
        case 0x9A0625:
        {
            if(((ampChnSts & AMP_WOOFER1_CHN_ENABLE_MASK) == AMP_WOOFER1_CHN_ENABLE_MASK)||
                ((ampChnSts & AMP_WOOFER2_CHN_ENABLE_MASK) == AMP_WOOFER2_CHN_ENABLE_MASK))
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x9A0701:
        case 0x9A0711:
        case 0x9A0712:
        case 0x9A0713:
        case 0x9A071E:
        case 0x9A0725:
        {
            if((ampChnSts & AMP_AVAS_CHN_ENABLE_MASK) == AMP_AVAS_CHN_ENABLE_MASK)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;

        case 0x95F811:
        case 0x95F812:
        case 0x95F813:
        {
            if((ampChnSts  == (uint16)AMP_CHANNEL_NONE) || (ampChnSts == (uint16)AMP_AVAS_CHN_ENABLE_MASK))
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        break;


        default:
        break;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x95F811(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AMPLIFIER].configGet == 0x2)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x95F812(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AMPLIFIER].configGet == 0x2)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x95F813(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AMPLIFIER].configGet == 0x2)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA13011(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x927312(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA13111(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x4)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x927412(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL_TANK_SYSTEM].configGet == 0x4)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908B87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
        || 
        (
            (
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1G) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_YY) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_XDL) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1R) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1IND) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_THA) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01G) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03) ||
                (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03_1G)
            )
        && 
            (
                (vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet == 0x1)
            )
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908A87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x5)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908687(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908587(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x908487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30017(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30116(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30008(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30149(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30249(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30349(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30549(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30649(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30093(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (
                vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1
            )
            ||
            (
                (
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1G) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_YY) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_XDL) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1R) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1IND) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_THA) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01G) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03_1G)
                )
                &&
                (
                    0x01 == vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet
                )
            )
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA30157(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (
                vConfig.config->kindDatas[VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN].configGet == 0x1
            )
            ||
            (
                (
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1G) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_YY) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_XDL) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1R) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_1IND) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_P03_THA) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D01G) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03) ||
                   (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_D03_1G)
                )
                &&
                (
                    0x01 == vConfig.config->kindDatas[VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST].configGet
                )
            )
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xA50157(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910011(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910012(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910013(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910087(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_REVERSE_VIDEO].configGet != 0x0)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910111(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910112(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910113(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910287(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC10087(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x6) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ENGINE_CONTROL_UNIT].configGet == 0x7)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC12287(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_SERVICE_BRAKE].configGet == 0x2)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x0) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC10187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x7) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x26) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x29) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x0F) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x10)
            )
            && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x0)
            )
           )
          || 
           (
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x7) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x26) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x29) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x0F) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x10)
            )
            && 
            (
            (vConfig.config->kindDatas[VCONFIG_KIND_PT_CAN_BUS_TYPE].configGet == 0x1)
            )
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x13)
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x27) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x28)
           )
          || 
           (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSMISSION].configGet == 0x8)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC24187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC24287(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD10B87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRT_SEAT_BELT].configGet == 0x8)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD02687(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x5)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC14087(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_STARTING_SYSTEM].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC16487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AIR_CONDITIONER].configGet == 0x4)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC13187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (vConfig.config->kindDatas[VCONFIG_KIND_STEERING_SYSTEM ].configGet == 0x1)
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC12887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_PARKING_BRAKE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC20887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x6)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC19987(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DOOR_MODULE_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC20087(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DOOR_MODULE_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC24687(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_DRIVER_SEAT].configGet == 0x6)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRT_SEAT__HEATING_LEVEL_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC24387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_AUTO_PARKING_SYSTEM].configGet == 0x6)
        )
        || 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_SENSOR].configGet != 0x0)
        )
        || 
        (
            (
                (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_SENSOR].configGet == 0x0)
            )
            && 
            (
                (vConfig.config->kindDatas[VCONFIG_KIND_REAR_PAS_SENSOR].configGet != 0x0)
            )
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC2B387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC19887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE].configGet == 0xa)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC12787(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_TPMS].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC29387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0xa)
        )
        || 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC11187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_ELECTROMOTOR_POSITION].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC1BB87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FUEL].configGet == 0xa)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD10887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_SMART_JUNCTION_BOX].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD10987(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_SMART_JUNCTION_BOX].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD00487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC10487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet != 0x1)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC14387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet != 0x1)
        )
        && 
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD00987(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_SIDE_STEP].configGet == 0x6)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC23087(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_RR_DOOR_OPENING].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_RR_DOOR_OPENING].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC15C87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HIGHWAY_ASSIST].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC11587(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL].configGet == 0x4)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD01587(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_PROJECT_CODE].configGet == VCONFIG_PROJECT_B06)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC14187(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x4) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x5) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRAILING_HOOK].configGet == 0x6)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD02987(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_WIRELESS_POWER_CHARGER].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_WIRELESS_POWER_CHARGER].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC11487(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x3) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_TRANSFER_CASE].configGet == 0x5)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC15887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x2) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_HEAD_UP_DISPLAY].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC23387(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_LANE_CHANGE_ASSIST].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC2B587(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK].configGet == 0x1) ||
            (vConfig.config->kindDatas[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xC25E87(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910511(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910512(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910513(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DMS_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910611(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910612(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910613(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_DVR].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910711(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910712(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910713(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMS_TYPE].configGet == 0x1)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x9A0811(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x9A0812(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x9A0813(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x9A0819(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_GNSS_MODULE_TYPE].configGet == 0x2)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910811(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910812(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910813(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }

    return result;
}

boolean Dtc_AvaialbleCheck0x910887(uint32 dtc)
{
    boolean result = FALSE;

    if
    (
        (
            (vConfig.config->kindDatas[VCONFIG_KIND_OMNIVIEW_SYSTEM_VEHICLE_CONFIGURATION_INFORMATION].configGet == 0x0)
            &&(vConfig.config->kindDatas[VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM].configGet == 0x1)
        )
    )
    {
    	result = TRUE;
    }
    else
    {
    	result = FALSE; 
    }

    return result;
}

boolean Dtc_AvaialbleCheck0xD12387(uint32 dtc)
{
    boolean result = FALSE;
    if
    (
        (vConfig.config->kindDatas[VCONFIG_KIND_WATER_DEPTH_DETECTION].configGet == 0x1)
   
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE; 
    }
    return result;
}

boolean Dtc_AvaialbleCheckMIC1(uint32 dtc)
{
    boolean result = FALSE;
    if
    (
        (
        (vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x2)
         &&(vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet != 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE; 
    }
    return result;
}
boolean Dtc_AvaialbleCheckA2BDigitalMIC(uint32 dtc)
{
    boolean result = FALSE;
    if
    (
        (
        (vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet == 0x2)
         ||(vConfig.config->kindDatas[VCONFIG_KIND_VOICE_RECOGNITION].configGet == 0x3)
        )
    )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE; 
    }
    return result;
}
