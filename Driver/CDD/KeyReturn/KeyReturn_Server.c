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
 * @file:      KeyReturn_Server.c
 * @author:    Nobo
 * @date:      2021-4-13
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-4-13
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Rte_KeyReturn.h"
#include "KeyReturn_Server.h"
#include "string.h"

typedef void (*key_callout)(void);

typedef enum
{
    KEY_FREE = 0,
    KEY_PRESS,
    KEY_EVENT
} KEY_STATE;

typedef struct
{
    KEY_TYPE type;

    Std_ReturnType (*sig)(uint8 *data);
} KeyTypeSig_St;

typedef struct
{
    KeyAttribute_st attribute;
    KEY_STATE state;
    KEY_STATE last_state;
    uint32 runtime;
    uint8 pressCount;
} KeyState_st;

#define KeyListSize     30
#define TASK_CYCLE       10  //ms


static KeyState_st KeyList[KeyListSize] = {0};
static boolean keyIsDisable = FALSE;
static boolean keyIsInit = FALSE;

#define KEY_TEST
#ifdef KEY_TEST
#include "KeyReturnTest.c"
#endif

#ifdef GWM_V35_PROJECT_TYPE_B03
#define KR_AdjVolDwnSwtSts      Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts
#define KR_AdjVolUpSwtSts       Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts
#define KR_CustomSwtSt          Rte_Read_CustomSwtSts_CustomSwtSts
#define KR_CustomSwtSts         Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed
#define KR_EnterSwtSts          Rte_Read_EnterSwtSts_EnterSwtSts
#define KR_EnterSwtSts_Mmed     Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed
#define KR_HomeSwtSts           Rte_Read_HomeSwtSts_HomeSwtSts
#define KR_MenuReturnSwtSts     Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts
#define KR_MuteSwtSts           Rte_Read_MuteSwtSts_MuteSwtSts
#define KR_PageDwnSwtSts        Rte_Read_PageDwnSwtSts_PageDwnSwtSts
#define KR_PageLSwtSts          Rte_Read_PageLSwtSts_PageLSwtSts
#define KR_PageRSwtSts          Rte_Read_PageRSwtSts_PageRSwtSts
#define KR_PageUpSwtSts         Rte_Read_PageUpSwtSts_PageUpSwtSts
#define KR_SeekDwnSwtSts        Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts
#define KR_SeekUpSwtSts         Rte_Read_SeekUpSwtSts_SeekUpSwtSts
#define KR_VRSwtSt              Rte_Read_VRSwtSts_VRSwtSts
#else
#include "ComEx.h"
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length);
INLINE Std_ReturnType KR_AdjVolDwnSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ADJVOLDWNSWTSTS, data, 1);}
INLINE Std_ReturnType KR_AdjVolUpSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ADJVOLUPSWTSTS, data, 1);}
#if (!defined GWM_V35_PROJECT_TYPE_ES13)
INLINE Std_ReturnType KR_CustomSwtSt(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CUSTOMSWTSTS, data, 1);}
#endif
INLINE Std_ReturnType KR_CustomSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CUSTOMSWTSTS_MMED, data, 1);}
INLINE Std_ReturnType KR_EnterSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENTERSWTSTS, data, 1);}
INLINE Std_ReturnType KR_EnterSwtSts_Mmed(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENTERSWTSTS_MMED, data, 1);}
#if (!defined GWM_V35_PROJECT_TYPE_P09)
INLINE Std_ReturnType KR_HomeSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOMESWTSTS, data, 1);}
INLINE Std_ReturnType KR_MenuReturnSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MENURETURNSWTSTS, data, 1);}
#endif
INLINE Std_ReturnType KR_MuteSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MUTESWTSTS, data, 1);}
#if (!defined GWM_V35_PROJECT_TYPE_P09)
INLINE Std_ReturnType KR_PageDwnSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PAGEDWNSWTSTS, data, 1);}
#endif
INLINE Std_ReturnType KR_PageLSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PAGELSWTSTS, data, 1);}
INLINE Std_ReturnType KR_PageRSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PAGERSWTSTS, data, 1);}
INLINE Std_ReturnType KR_PageUpSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PAGEUPSWTSTS, data, 1);}
INLINE Std_ReturnType KR_SeekDwnSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SEEKDWNSWTSTS, data, 1);}
INLINE Std_ReturnType KR_SeekUpSwtSts(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SEEKUPSWTSTS, data, 1);}
INLINE Std_ReturnType KR_VRSwtSt(uint8* data) {return ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VRSWTSTS, data, 1);}
#endif

const KeyTypeSig_St keyTypeSigMap[] = {
#ifdef KEY_TEST
        {KEY_TEST_0, kr_test0_sig},
        {KEY_TEST_1, kr_test1_sig},
        {KEY_TEST_2, kr_test2_sig},
        {KEY_TEST_3, kr_test3_sig},
        {KEY_TEST_4, kr_test4_sig},
#endif
        {AdjVolDwn, KR_AdjVolDwnSwtSts},
        {AdjVolUp, KR_AdjVolUpSwtSts},
    #if (!defined GWM_V35_PROJECT_TYPE_ES13)
        {Custom, KR_CustomSwtSt},
    #endif
        {CustomMmed, KR_CustomSwtSts},
        {Enter, KR_EnterSwtSts},
        {EnterMmed, KR_EnterSwtSts_Mmed},
#if (!defined GWM_V35_PROJECT_TYPE_P09)
        {Home, KR_HomeSwtSts},
        {MenuReturn, KR_MenuReturnSwtSts},
#endif
        {Mute, KR_MuteSwtSts},
#if (!defined GWM_V35_PROJECT_TYPE_P09)
        {PageDwn, KR_PageDwnSwtSts},
#endif
		{PageL, KR_PageLSwtSts},
        {PageR, KR_PageRSwtSts},
        {PageUp, KR_PageUpSwtSts},
        {SeekDwn, KR_SeekDwnSwtSts},
        {SeekUp, KR_SeekUpSwtSts},
        {VR, KR_VRSwtSt}
};
const uint8 KeySigMapSize = sizeof(keyTypeSigMap) / sizeof(KeyTypeSig_St);

static void kr_updataKeyState(KeyState_st *keyState)
{
    uint16 sigIndex = 0;
    uint16 mapIndex = 0;
    uint8 data = 0;
    uint8 isPress = 0xff;

    for (mapIndex = 0; mapIndex < KeySigMapSize; mapIndex++)
    {
        boolean keyTypeInList = FALSE;
        for (sigIndex = 0; keyState->attribute.KeyList[sigIndex]; sigIndex++)
        {
            if (keyState->attribute.KeyList[sigIndex] == keyTypeSigMap[mapIndex].type)
            {
                keyTypeSigMap[mapIndex].sig(&data);
                isPress &= data;
                data = 0;
                keyTypeInList = TRUE;
                break;
            }
        }
        if ((keyTypeInList == FALSE) && (keyState->attribute.OnlyKey))
        {
            keyTypeSigMap[mapIndex].sig(&data);
            if (data)
            {
                data = 0;
                isPress = 0;
                break;
            }
        }
    }
    if (isPress)
    {
        if (keyState->state == KEY_FREE)
        {
            keyState->pressCount++;
            keyState->state = KEY_PRESS;
        }
    }
    else
    {
        if (keyState->state == KEY_EVENT)
        {
            if (keyState->attribute.FreeCallout)
            {
                key_callout FreeCallout = (key_callout) keyState->attribute.FreeCallout;
                FreeCallout();
            }
        }
        if (1 == keyState->attribute.PressCnt)
        {
            keyState->runtime = 0;
            keyState->pressCount = 0;
        }
        keyState->state = KEY_FREE;
    }
}

static void kr_event(KeyState_st *keyState)
{
    if (keyState->state == KEY_PRESS)
    {
        if (keyState->attribute.PressCnt == 1)
        {
            keyState->runtime++;
            if (keyState->runtime >= (keyState->attribute.PressTime/TASK_CYCLE))
            {
                keyState->runtime = 0;
                keyState->pressCount = 0;
                keyState->state = KEY_EVENT;
                if (keyState->attribute.EventCallout)
                {
                    key_callout EventCallout = (key_callout) keyState->attribute.EventCallout;
                    EventCallout();
                }
            }
        }
        else
        {
            keyState->runtime++;
            if (keyState->runtime < (keyState->attribute.PressTime/TASK_CYCLE))
            {
                if ((keyState->pressCount) == keyState->attribute.PressCnt)
                {
                    keyState->runtime = 0;
                    keyState->pressCount = 0;
                    keyState->state = KEY_EVENT;
                    if (keyState->attribute.EventCallout)
                    {
                        key_callout EventCallout = (key_callout) keyState->attribute.EventCallout;
                        EventCallout();
                    }
                }
            }
            else
            {
                keyState->runtime = 0;
                keyState->pressCount = 0;
                keyState->state = KEY_FREE;
            }
        }

    }
    else
    {
    }
}

void KR_Init(void)
{
    keyIsInit = TRUE;
}

/*
 *   Std_ReturnType Rte_Read_AdjVolDwnSwtSts_AdjVolDwnSwtSts(AdjVolDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_AdjVolUpSwtSts_AdjVolUpSwtSts(AdjVolUpSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_CustomSwtSts(CustomSwtSts *data)
 *   Std_ReturnType Rte_Read_CustomSwtSts_Mmed_CustomSwtSts_Mmed(CustomSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_EnterSwtSts(EnterSwtSts *data)
 *   Std_ReturnType Rte_Read_EnterSwtSts_Mmed_EnterSwtSts_Mmed(EnterSwtSts_Mmed *data)
 *   Std_ReturnType Rte_Read_HomeSwtSts_HomeSwtSts(HomeSwtSts *data)
 *   Std_ReturnType Rte_Read_MenuReturnSwtSts_MenuReturnSwtSts(MenuReturnSwtSts *data)
 *   Std_ReturnType Rte_Read_MuteSwtSts_MuteSwtSts(MuteSwtSts *data)
 *   Std_ReturnType Rte_Read_PageDwnSwtSts_PageDwnSwtSts(PageDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_PageLSwtSts_PageLSwtSts(PageLSwtSts *data)
 *   Std_ReturnType Rte_Read_PageRSwtSts_PageRSwtSts(PageRSwtSts *data)
 *   Std_ReturnType Rte_Read_PageUpSwtSts_PageUpSwtSts(PageUpSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekDwnSwtSts_SeekDwnSwtSts(SeekDwnSwtSts *data)
 *   Std_ReturnType Rte_Read_SeekUpSwtSts_SeekUpSwtSts(SeekUpSwtSts *data)
 *   Std_ReturnType Rte_Read_VRSwtSts_VRSwtSts(VRSwtSts *data)
 */
void KR_MainFunction(void)
{
    uint16 listIndex = 0;
    uint16 attributeIndex = 0;

#ifdef KEY_TEST
    kr_test_mainfunction();
#endif

    if (keyIsDisable || (keyIsInit == FALSE))
    {
    } else
    {
        for (listIndex = 0; listIndex < KeyListSize; listIndex++)
        {
            for (attributeIndex = 0; (attributeIndex < sizeof(KeyAttribute_st)); attributeIndex++)
            {
                if (((uint8 *) (&KeyList[listIndex].attribute))[attributeIndex] != 0)
                {
                    kr_updataKeyState(&KeyList[listIndex]);
                    break;
                }
            }
            if (KeyList[listIndex].state == KEY_PRESS)
            {
                kr_event(&KeyList[listIndex]);
            }
        }
    }
}

KeyReturn_CODE KR_State(uint8 KeyId, boolean *isPress)
{
    if (KeyId >= KeyListSize)
    {
        return E_NOT_OK;
    }
    return E_OK;
}

KeyReturn_CODE KR_disable(void)
{
    keyIsDisable = TRUE;
    return E_OK;
}

KeyReturn_CODE KR_enable(void)
{
    keyIsDisable = FALSE;
    return E_OK;
}

KeyReturn_CODE KR_register(const KeyAttribute_st *attribute, uint8 *KeyId)
{
    uint16 listIndex = 0;
    uint16 attributeIndex = 0;
    uint8 id = 0xff;
    for (listIndex = 0; listIndex < KeyListSize; listIndex++)
    {
        id = listIndex;
        for (attributeIndex = 0; (attributeIndex < sizeof(KeyAttribute_st)); attributeIndex++)
        {
            if (((uint8 *) (&KeyList[listIndex].attribute))[attributeIndex] != 0)
            {
                id = 0xff;
                break;
            }
        }
        if (id != 0xff)
        {
            memcpy(&KeyList[listIndex], (const void *) attribute, sizeof(KeyAttribute_st));
            KeyList[listIndex].state = KEY_FREE;
            KeyList[listIndex].pressCount = 0;
            KeyList[listIndex].runtime = 0;
            *KeyId = listIndex;
            return E_OK;
        }

    }
    return E_NOT_OK;
}

KeyReturn_CODE KR_remove(uint8 KeyId)
{
    if (KeyId >= KeyListSize)
    {
        return E_NOT_OK;
    }
    memset((void *) (&KeyList[KeyId]), 0, sizeof(KeyAttribute_st));
    KeyList[KeyId].state = KEY_FREE;
    return E_OK;
}
