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
 * @file:      MagicNum.h
 * @author:    Nobo
 * @date:      2020-8-4
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-4
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef MAGICNUM_INCLUDE
#define MAGICNUM_INCLUDE

/**********************************************************************************************************************
* External Function Include
*********************************************************************************************************************/
#include "Crc.h"
/**********************************************************************************************************************
* Internel Function Include
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MAGIC_NUMBER_CLR do{\
    MagicNumber->MagicNum[0] = 0;\
    MagicNumber->MagicNum[1] = 0;\
    MagicNumber->MagicNum[2] = 0x55;\
    MagicNumber->MagicNumBit.crc=\
    Crc_CalculateCRC8((uint8*)MagicNumber,3,0xff, TRUE);\
}while(0)

#define MAGIC_NUMBER_SET(b, v) do{\
    MagicNumber->MagicNumBit.b = v;\
    MagicNumber->MagicNumBit.crc=\
    Crc_CalculateCRC8((uint8*)MagicNumber,3,0xff, TRUE);\
}while(0)

#define MAGIC_NUMBER_GET(b) MagicNumber->MagicNumBit.b

#define MACIC_NUMBER_CHECK \
    (MagicNumber->MagicNumBit.crc==Crc_CalculateCRC8((uint8*)MagicNumber,3,0xff, TRUE))

#define MN_IN_APP   (0)
#define MN_IN_BM    (1)

#define MN_TO_APP   (0)
#define MN_TO_BM    (1)

#define MN_RESET_POWERON    (0)
#define MN_RESET_WAKEUP     (1)
#define MN_RESET_RESET      (2)

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Development Error Detection
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    uint8 in:1;
    uint8 to:1;
    uint8 AppCheck:1;
    uint8 AppCheckState:1;
    uint8 AppChenckResult:1;
    uint8 ref1:1;
    uint8 reset:2;
    uint8 app2bm;
    uint8 fix;
    uint8 crc;
} MagicNum_st;


typedef union
{
    uint8 MagicNum[4];
    MagicNum_st MagicNumBit;
}MagicNum_un;

extern MagicNum_un* const MagicNumber;
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
 *  END OF FILE: MagicNum.h
 *********************************************************************************************************************/
#endif //MAGICNUM_INCLUDE