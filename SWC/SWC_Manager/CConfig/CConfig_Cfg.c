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
 * @file:      CConfig_Cfg.c
 * @author:    Nobo
 * @date:      2020-10-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file in this project/library%
 */
#include "CConfig_Cfg.h"



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
#define CCONFIG_START_SEC_CONST_UNSPECIFIED
#include "CConfig_MemMap.h"

const CConfig_KindConfigType cConfig_kindConfigs[CCONFIG_KIND_NUMBER]=
{
    {1u, 0xF0u, 0xFFu, 4u, 2u, 0u, 2u},
    {1u, 0x8u, 0x0u, 3u, 1u, 2u, 3u},
    {1u, 0x4u, 0x0u, 2u, 1u, 3u, 4u},
    {2u, 0xFFu, 0x1u, 0u, 2u, 4u, 6u},
    {4u, 0x80u, 0xFFu, 7u, 2u, 6u, 8u},
    {6u, 0xFFu, 0xFFu, 0u, 2u, 8u, 10u},
    {7u, 0xFFu, 0x0u, 0u, 1u, 10u, 11u},
    {8u, 0xFFu, 0x0u, 0u, 1u, 11u, 12u},
    {9u, 0xFFu, 0x0u, 0u, 1u, 12u, 13u},
    {10u, 0xFFu, 0x0u, 0u, 1u, 13u, 14u},
    {11u, 0xFFu, 0x0u, 0u, 1u, 14u, 15u},
    {12u, 0xFFu, 0x0u, 0u, 1u, 15u, 16u},
    {13u, 0xFFu, 0x0u, 0u, 1u, 16u, 17u},
    {14u, 0xFFu, 0x0u, 0u, 1u, 17u, 18u},
    {15u, 0xFFu, 0x0u, 0u, 1u, 18u, 19u},
    {16u, 0xFFu, 0x0u, 0u, 1u, 19u, 20u},
    {17u, 0xFFu, 0x0u, 0u, 1u, 20u, 21u},
    {18u, 0xFFu, 0x0u, 0u, 1u, 21u, 22u},
    {19u, 0xFFu, 0x0u, 0u, 1u, 22u, 23u},
    {20u, 0xFFu, 0x0u, 0u, 1u, 23u, 24u},
    {22u, 0xF0u, 0xFFu, 4u, 2u, 24u, 26u},
    {24u, 0xFFu, 0xFFu, 0u, 2u, 26u, 28u},
    {26u, 0xF0u, 0xFFu, 4u, 2u, 28u, 30u},
    {27u, 0xFFu, 0xFu, 0u, 2u, 30u, 32u},
    {29u, 0xF0u, 0xFFu, 4u, 2u, 32u, 34u},
    {30u, 0xFFu, 0xFu, 0u, 2u, 34u, 36u},
    {32u, 0xF0u, 0xFFu, 4u, 2u, 36u, 38u},
    {33u, 0xFFu, 0x0u, 0u, 1u, 38u, 39u},
    {35u, 0xFFu, 0xFFu, 0u, 2u, 39u, 41u},
    {37u, 0xFFu, 0xFFu, 0u, 2u, 41u, 43u},
    {39u, 0xFFu, 0xFFu, 0u, 2u, 43u, 45u},
    {40u, 0xFFu, 0x0u, 0u, 1u, 45u, 46u},
    {42u, 0xFFu, 0xFu, 0u, 2u, 46u, 48u},
    {43u, 0xFFu, 0x0u, 0u, 1u, 48u, 49u},
    {45u, 0xFFu, 0xFFu, 0u, 2u, 49u, 51u},
    {47u, 0xF0u, 0xFFu, 4u, 2u, 51u, 53u},
    {48u, 0xFFu, 0xFu, 0u, 2u, 53u, 55u},
    {50u, 0xF0u, 0xFFu, 4u, 2u, 55u, 57u},
    {51u, 0xFFu, 0xFu, 0u, 2u, 57u, 59u},
    {53u, 0xF0u, 0xFFu, 4u, 2u, 59u, 61u},
    {54u, 0xFFu, 0xFu, 0u, 2u, 61u, 63u},
    {56u, 0xF0u, 0xFFu, 4u, 2u, 63u, 65u},
    {58u, 0xFFu, 0xFFu, 0u, 2u, 65u, 67u},
    {60u, 0xFFu, 0xFFu, 0u, 2u, 67u, 69u},
    {62u, 0xFFu, 0xFFu, 0u, 2u, 69u, 71u},
    {66u, 0xFFu, 0xFu, 0u, 2u, 71u, 73u},
    {68u, 0xF0u, 0xFFu, 4u, 2u, 73u, 75u},
    {69u, 0xFFu, 0xFu, 0u, 2u, 75u, 77u},
    {71u, 0xF0u, 0xFFu, 4u, 2u, 77u, 79u},
    {73u, 0xFFu, 0xFFu, 0u, 2u, 79u, 81u},
    {75u, 0xFFu, 0xFFu, 0u, 2u, 81u, 83u},
    {77u, 0xFFu, 0xFFu, 0u, 2u, 83u, 85u},
    {81u, 0xFFu, 0xFu, 0u, 2u, 85u, 87u},
    {83u, 0xF0u, 0xFFu, 4u, 2u, 87u, 89u},
    {84u, 0xFFu, 0xFu, 0u, 2u, 89u, 91u},
    {86u, 0xF0u, 0xFFu, 4u, 2u, 91u, 93u},
    {87u, 0xFFu, 0xFu, 0u, 2u, 93u, 95u},
    {89u, 0xF0u, 0xFFu, 4u, 2u, 95u, 97u},
    {90u, 0xFFu, 0xFu, 0u, 2u, 97u, 99u},
    {92u, 0xF0u, 0xFFu, 4u, 2u, 99u, 101u},
    {96u, 0xFFu, 0xFu, 0u, 2u, 101u, 103u},
    {98u, 0xF0u, 0xFFu, 4u, 2u, 103u, 105u},
    {99u, 0xFFu, 0xFu, 0u, 2u, 105u, 107u},
    {101u, 0xF0u, 0xFFu, 4u, 2u, 107u, 109u},
    {111u, 0xFFu, 0xFu, 0u, 2u, 109u, 111u},
    {113u, 0xF0u, 0xFFu, 4u, 2u, 111u, 113u},
    {114u, 0xFFu, 0xFu, 0u, 2u, 113u, 115u},
    {116u, 0xF0u, 0xFFu, 4u, 2u, 115u, 117u},
    {126u, 0xF0u, 0xFFu, 4u, 2u, 117u, 119u},
    {127u, 0xFFu, 0x0u, 0u, 1u, 119u, 120u},
    {128u, 0xFFu, 0x0u, 0u, 1u, 120u, 121u},
    {129u, 0xF8u, 0x0u, 3u, 1u, 121u, 122u},
    {130u, 0xFFu, 0x0u, 0u, 1u, 122u, 123u},
    {132u, 0xF0u, 0xFFu, 4u, 2u, 123u, 125u},
    {133u, 0xFFu, 0x0u, 0u, 1u, 125u, 126u},
    {134u, 0x80u, 0x0u, 7u, 1u, 126u, 127u},
    {134u, 0x40u, 0x0u, 6u, 1u, 127u, 128u},
    {134u, 0x20u, 0x0u, 5u, 1u, 128u, 129u},
    {134u, 0x10u, 0x0u, 4u, 1u, 129u, 130u},
    {139u, 0xFFu, 0xFFu, 0u, 5u, 130u, 135u},
    {141u, 0xF0u, 0xFFu, 4u, 2u, 135u, 137u},
    {143u, 0xFFu, 0xFFu, 0u, 2u, 137u, 139u},
    {144u, 0xF0u, 0x0u, 4u, 1u, 139u, 140u},
    {144u, 0x8u, 0x0u, 3u, 1u, 140u, 141u},
    {144u, 0x4u, 0x0u, 2u, 1u, 141u, 142u},
    {146u, 0xF0u, 0xFFu, 4u, 2u, 142u, 144u},
    {146u, 0xFu, 0x0u, 0u, 1u, 144u, 145u},
    {148u, 0x80u, 0x0u, 7u, 1u, 145u, 146u},
    {148u, 0x40u, 0x0u, 6u, 1u, 146u, 147u},
    {150u, 0xF0u, 0xFFu, 4u, 2u, 147u, 149u},
    {151u, 0xFFu, 0xFu, 0u, 2u, 149u, 151u},
    {154u, 0xFFu, 0xFu, 0u, 2u, 151u, 153u},
    {156u, 0xF0u, 0xFFu, 4u, 2u, 153u, 155u},
    {157u, 0xFFu, 0x0u, 0u, 1u, 155u, 156u},
    {158u, 0xFFu, 0x0u, 0u, 1u, 156u, 157u},
    {159u, 0xFFu, 0x0u, 0u, 1u, 157u, 158u},
    {160u, 0xFFu, 0x0u, 0u, 1u, 158u, 159u},
    {161u, 0xFFu, 0x0u, 0u, 1u, 159u, 160u},
    {162u, 0xFFu, 0x0u, 0u, 1u, 160u, 161u},
    {166u, 0xF0u, 0xFFu, 4u, 2u, 161u, 163u},
    {166u, 0x8u, 0x0u, 3u, 1u, 163u, 164u},
    {172u, 0x80u, 0x0u, 7u, 1u, 164u, 165u},
    {173u, 0xFFu, 0x0u, 0u, 1u, 165u, 166u},
    {175u, 0x80u, 0x0u, 7u, 1u, 166u, 167u},
    {180u, 0x80u, 0x0u, 7u, 1u, 167u, 168u},
    {182u, 0xF0u, 0xFFu, 4u, 2u, 168u, 170u},
    {182u, 0x1u, 0x0u, 0u, 1u, 170u, 171u},
    {183u, 0xFFu, 0x0u, 0u, 1u, 171u, 172u},
    {185u, 0xF0u, 0xFFu, 4u, 2u, 172u, 174u},
    {185u, 0x1u, 0x0u, 0u, 1u, 174u, 175u},
    {187u, 0xF0u, 0xFFu, 4u, 2u, 175u, 177u},
    {188u, 0xFFu, 0xFu, 0u, 2u, 177u, 179u},
    {189u, 0x80u, 0x0u, 7u, 1u, 179u, 180u},
    {190u, 0xFFu, 0xFu, 0u, 2u, 180u, 182u},
    {191u, 0x80u, 0x0u, 7u, 1u, 182u, 183u},
    {192u, 0xFFu, 0xFu, 0u, 2u, 183u, 185u},
    {193u, 0x80u, 0x0u, 7u, 1u, 185u, 186u},
    {194u, 0xFFu, 0xFu, 0u, 2u, 186u, 188u},
    {196u, 0xF0u, 0xFFu, 4u, 2u, 188u, 190u},
    {196u, 0x1u, 0x0u, 0u, 1u, 190u, 191u},
    {199u, 0xFFu, 0x0u, 0u, 1u, 191u, 192u},
    {201u, 0xF0u, 0xFFu, 4u, 2u, 192u, 194u},
    {202u, 0xFFu, 0x0u, 0u, 1u, 194u, 195u},
    {203u, 0x80u, 0x0u, 7u, 1u, 195u, 196u},
    {203u, 0x40u, 0x0u, 6u, 1u, 196u, 197u},
    {208u, 0xFFu, 0xFFu, 0u, 5u, 197u, 202u},
    {209u, 0x80u, 0x0u, 7u, 1u, 202u, 203u},
    {209u, 0x40u, 0x0u, 6u, 1u, 203u, 204u},
    {209u, 0x20u, 0x0u, 5u, 1u, 204u, 205u},
    {209u, 0x10u, 0x0u, 4u, 1u, 205u, 206u},
    {209u, 0x8u, 0x0u, 3u, 1u, 206u, 207u},
    {209u, 0x4u, 0x0u, 2u, 1u, 207u, 208u},
    {209u, 0x2u, 0x0u, 1u, 1u, 208u, 209u},
    {215u, 0x80u, 0x0u, 7u, 1u, 209u, 210u},
    {215u, 0x40u, 0x0u, 6u, 1u, 210u, 211u},
    {215u, 0x20u, 0x0u, 5u, 1u, 211u, 212u},
    {215u, 0xFu, 0x0u, 0u, 1u, 212u, 213u},
    {216u, 0xFCu, 0x0u, 2u, 1u, 213u, 214u},
    {216u, 0x1u, 0x0u, 0u, 1u, 214u, 215u},
    {217u, 0xFFu, 0x0u, 0u, 1u, 215u, 216u},
    {220u, 0xF0u, 0xFFu, 4u, 3u, 216u, 219u},
    {221u, 0xFCu, 0x0u, 2u, 1u, 219u, 220u},
    {222u, 0xFCu, 0x0u, 2u, 1u, 220u, 221u},
    {223u, 0xFFu, 0x0u, 0u, 1u, 221u, 222u},
    {224u, 0xFFu, 0x0u, 0u, 1u, 222u, 223u},
    {226u, 0xFFu, 0xFFu, 0u, 2u, 223u, 225u},
    {227u, 0xFFu, 0x0u, 0u, 1u, 225u, 226u},
    {228u, 0xFFu, 0x0u, 0u, 1u, 226u, 227u},
    {229u, 0xFFu, 0x0u, 0u, 1u, 227u, 228u},
    {230u, 0xFFu, 0x0u, 0u, 1u, 228u, 229u},
    {231u, 0xFFu, 0x0u, 0u, 1u, 229u, 230u},
    {232u, 0xFFu, 0x0u, 0u, 1u, 230u, 231u},
    {233u, 0xFFu, 0x0u, 0u, 1u, 231u, 232u},
    {236u, 0xF0u, 0xFFu, 4u, 3u, 232u, 235u},
    {238u, 0xFFu, 0xFu, 0u, 3u, 235u, 238u},
    {239u, 0xF0u, 0x0u, 4u, 1u, 238u, 239u},
    {239u, 0xFu, 0x0u, 0u, 1u, 239u, 240u},
    {241u, 0xFFu, 0xFFu, 0u, 2u, 240u, 242u},
    {243u, 0xFFu, 0xFFu, 0u, 2u, 242u, 244u},
    {244u, 0xFFu, 0x0u, 0u, 1u, 244u, 245u},
    {245u, 0xFFu, 0x0u, 0u, 1u, 245u, 246u},
    {248u, 0xF0u, 0xFFu, 4u, 2u, 246u, 248u},
    {249u, 0xFFu, 0xFu, 0u, 2u, 248u, 250u},
    {251u, 0xF0u, 0xFFu, 4u, 2u, 250u, 252u},
    {252u, 0xFFu, 0xFu, 0u, 2u, 252u, 254u},
    {254u, 0xF0u, 0xFFu, 4u, 2u, 254u, 256u},
    {255u, 0xFFu, 0xFu, 0u, 2u, 256u, 258u},
    {256u, 0xFFu, 0x0u, 0u, 1u, 258u, 259u},
    {258u, 0xF0u, 0xFFu, 4u, 2u, 259u, 261u},
    {259u, 0xFFu, 0xFu, 0u, 2u, 261u, 263u},
    {263u, 0xFFu, 0x0u, 0u, 1u, 263u, 264u},
    {265u, 0xF0u, 0xFFu, 4u, 2u, 264u, 266u},
    {266u, 0xFFu, 0xFu, 0u, 2u, 266u, 268u},
    {268u, 0xF0u, 0xFFu, 4u, 2u, 268u, 270u},
    {269u, 0xFFu, 0xFu, 0u, 2u, 270u, 272u},
    {271u, 0xF0u, 0xFFu, 4u, 2u, 272u, 274u},
    {272u, 0xFFu, 0xFu, 0u, 2u, 274u, 276u},
    {274u, 0xF0u, 0xFFu, 4u, 2u, 276u, 278u},
    {275u, 0xFFu, 0xFu, 0u, 2u, 278u, 280u},
    {277u, 0xF0u, 0xFFu, 4u, 2u, 280u, 282u},
    {278u, 0xFFu, 0xFu, 0u, 2u, 282u, 284u},
    {279u, 0xFFu, 0x0u, 0u, 1u, 284u, 285u},
    {280u, 0xFFu, 0x0u, 0u, 1u, 285u, 286u},
    {281u, 0xFFu, 0x0u, 0u, 1u, 286u, 287u},
    {282u, 0xFFu, 0x0u, 0u, 1u, 287u, 288u},
    {283u, 0xFFu, 0x0u, 0u, 1u, 288u, 289u},
    {284u, 0xFFu, 0x0u, 0u, 1u, 289u, 290u},
    {286u, 0xF0u, 0xFFu, 4u, 2u, 290u, 292u},
    {287u, 0xFFu, 0x0u, 0u, 1u, 292u, 293u},
    {288u, 0xFFu, 0x0u, 0u, 1u, 293u, 294u},
    {290u, 0xFFu, 0xFFu, 0u, 2u, 294u, 296u},
    {291u, 0xFFu, 0x0u, 0u, 1u, 296u, 297u},
    {292u, 0xFFu, 0x0u, 0u, 1u, 297u, 298u},
    {293u, 0xFFu, 0x0u, 0u, 1u, 298u, 299u},
};



#define CCONFIG_STOP_SEC_CONST_UNSPECIFIED
#include "CConfig_MemMap.h"

#define CCONFIG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CConfig_MemMap.h"

static uint8 cConfig_kindBuffer[CCONFIG_KIND_BUFFER_SIZE];
static uint8 cConfig_rawData[CCONFIG_RAW_DATA_SIZE];
static uint8 cConfig_rawDataBackup[CCONFIG_RAW_DATA_SIZE];

#define CCONFIG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CConfig_MemMap.h"

#define CCONFIG_START_SEC_CONST_UNSPECIFIED
#include "CConfig_MemMap.h"

CConfig_ConfigType cConfig_config =
{
    CCONFIG_KIND_NUMBER,
    cConfig_kindConfigs,
    CCONFIG_KIND_BUFFER_SIZE,
    cConfig_kindBuffer,
    CCONFIG_RAW_DATA_SIZE,
    cConfig_rawData,
    cConfig_rawDataBackup,
};

#define CCONFIG_STOP_SEC_CONST_UNSPECIFIED
#include "CConfig_MemMap.h"

/*
* @brief   :   Internal parse function to convert raw config data to kind config data
* @param   :   kindId,buffer
* @retval  :   condig value
*/
uint64 CConfig_GetConfig(uint16 kindId, uint8 *buffer)
{
    uint64 result = 0u;

    if((kindId < cConfig_config.kindNumber) || (buffer == NULL_PTR))
    {
        const CConfig_KindConfigType *kindConfig = &cConfig_config.kindConfigs[kindId];
        uint16 pos;
        for(pos = kindConfig->bufferEnd; pos > kindConfig->bufferStart; pos--)
        {
            result = (result << 8);
            result = result | buffer[pos-1];
        }
    }
    return result;
}



