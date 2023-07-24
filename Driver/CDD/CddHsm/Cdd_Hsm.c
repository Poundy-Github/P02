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
 * @file:      Cdd_Hsm.c
 * @author:    Nobo
 * @date:      2020-6-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef CDD_HSM_SOURCE
#define CDD_HSM_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Csm.h"
#include "os.h"
#include "Crypto_30_vHsm_Cfg.h"
#include "Cdd_Common.h"
#include "string.h"

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Cdd_Hsm.h"
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#include "fls.h"
#include "Fls_Ram.h"
#include "stdio.h"

uint8 test_cnt = 0;
uint8 err_flag = 0;

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CMAC_KEY CsmConf_CsmKey_CsmKey
#define CMAC_KEY_ELEMENT CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SecOC_CMAC_Sync
#define CMAC_KEY_STATE CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKey_GetKeyState_Sync

#define AES128_KEY CsmConf_CsmKey_CsmKey_Aes128
#define AES128_KEY_ELEMENT CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKeyElement_Aes128_Sync
#define AES128_KEY_IV_ELEMENT CryptoConf_CryptoKeyElement_Crypto_30_LibCv_CryptoKeyElement_Aes128_IV_Sync

#define FLASH_KEY CsmConf_CsmKey_CsmKey_Flash

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

static uint8 Cdd_HsmSetAes128Key_Cbk(void);
static uint8 Cdd_HsmSetCmacKey_cbk(void);
static uint8 Cdd_HsmSetSecureBoot_AppA_Info_cbk(void);
static uint8 Cdd_HsmSetSecureBoot_AppB_Info_cbk(void);
static uint8 Cdd_HsmSetSecureBootKey_cbk(void);
static uint8 Cdd_HsmSecureBoot_SetAppAction_cbk(void);
extern void SecOc_KeyElementSetFail(void);
extern void SecOc_KeyElementSetOk(void);
/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

boolean SetValidIsBusy = TRUE;
boolean CodeFlashIsAllow = FALSE;
SET_VALID_EM WaitSetValidCbk = SET_VALID_IDLE;
AES128_PARAM_ST AES128_PARAM = {0};
CMAC_PARAM_ST CMAC_PARAM = {0};
SECBOOT_PARAM_ST SECBOOT_A_PARAM = {0};
SECBOOT_PARAM_ST SECBOOT_B_PARAM = {0};
SECBOOT_KEY_PARAM_ST SECBOOT_KEY_PARAM = {0};
SECBOOT_ACTION_APP_PARAM_ST SECBOOT_ACTION_APP_PARAM = {0};

HSM_PCB_ST hsm_pcb[6] = {
    {Cdd_HsmSetAes128Key_Cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,NULL,NULL},
    {Cdd_HsmSetCmacKey_cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,SecOc_KeyElementSetFail,SecOc_KeyElementSetOk},
    {Cdd_HsmSetSecureBoot_AppA_Info_cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,NULL,NULL},
    {Cdd_HsmSetSecureBoot_AppB_Info_cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,NULL,NULL},
    {Cdd_HsmSetSecureBootKey_cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,  NULL},
    {Cdd_HsmSecureBoot_SetAppAction_cbk, FALSE, HSM_PCB_ATTEMPS_MAX_TIME,NULL,NULL}};
/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define IC_INTFICUIF0DF (*((volatile uint16 *)0xffffb2ceUL))

#define ICUM_FENTDUPACK0 (1u)

#define ICUM_CMDREGICUM_PEFLPRG0ACK (*((volatile uint16 *)0xff1f0028UL))
#define ICUM_ICU2PEIE               (*((volatile uint16 *)0xff1f005CUL))
void Os_Isr_INTFICUIF0DFRQPE(void)
{
    ICUM_CMDREGICUM_PEFLPRG0ACK |= (1u << ICUM_FENTDUPACK0);
}

FUNC(void, CSM_APPL_CODE)
CsmJob_KeySetValid_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result)
{
    if (result == E_OK)
    {
        WaitSetValidCbk = SET_VALUE_COMP;
    }
    else
    {
        WaitSetValidCbk = SET_VALUE_SET_ERR;
        // WaitSetValidCbk = SET_VALUE_COMP;
    }
}

FUNC(void, CSM_APPL_CODE)
CsmJob_SecureBoot_Generate_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result)
{
}

void Cdd_HsmEnableIcup2CpuInterrupt(void)
{
    ICUM_ICU2PEIE = 1;
}

boolean Cdd_HsmCodeFlashIsAllow(void)
{
    return CodeFlashIsAllow;
}

boolean Cdd_HsmSetValidIsBusy(void)
{
    uint8 index = 0;
    boolean ret = FALSE;
    for (index = 0; index < (sizeof(hsm_pcb) / sizeof(HSM_PCB_ST)); index++)
    {
        ret |= HSM_GET_ACTIVE(index);
    }
    ret |= SetValidIsBusy;
    return ret;
}

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
uint8 Cdd_HsmDataFlashStart(void)
{
    uint8 op[1];
    uint8 ret = E_OK;
    if (SetValidIsBusy == TRUE)
    {
        /* Restrict data flash operations for vHsm */
        op[0] = CRYPTO_30_VHSM_DATAFLASH_START;
        ret = Csm_KeyElementSet(FLASH_KEY, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, op, 1);
        if (ret == E_OK)
        {
            SetValidIsBusy = FALSE;
        }
    }
    return ret;
}

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
uint8 Cdd_HsmDataFlashStop(void)
{
    uint8 op[1];
    uint8 ret = E_OK;
    if (SetValidIsBusy == FALSE)
    {
        /* Restrict data flash operations for vHsm */
        op[0] = CRYPTO_30_VHSM_DATAFLASH_STOP;
        ret = Csm_KeyElementSet(FLASH_KEY, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, op, 1);
        if (ret == E_OK)
        {
            SetValidIsBusy = TRUE;
        }
    }
    return ret;
}

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
void Cdd_HsmCodeFlashStart(void)
{
    uint8 op[1];
    Std_ReturnType ret = E_OK;
    if((CodeFlashIsAllow==FALSE) && (Fls_GenState == MEMIF_IDLE))
    {
        /* Restrict data flash operations for vHsm */
        op[0] = CRYPTO_30_VHSM_CODEFLASH_START;
        ret = Csm_KeyElementSet(FLASH_KEY, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, op, 1);
        if(ret == E_OK)
        {
            CodeFlashIsAllow = TRUE;
            Fls_GenState = MEMIF_BUSY_INTERNAL;
        }
    }
}

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
void Cdd_HsmCodeFlashStop(void)
{
    uint8 op[1];
    Std_ReturnType ret = E_OK;
    if(CodeFlashIsAllow==TRUE)
    {
        /* Restrict data flash operations for vHsm */
        op[0] = CRYPTO_30_VHSM_CODEFLASH_STOP;
        ret = Csm_KeyElementSet(FLASH_KEY, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, op, 1);
        if(ret == E_OK)
        {
            CodeFlashIsAllow = FALSE;
            if(Fls_GenState == MEMIF_BUSY_INTERNAL)
            {
                Fls_GenState = MEMIF_IDLE;
            }
        }
    }
}

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
uint8 _Cdd_HsmSetCmacKey(const uint8 *vin, uint32 vin_len, const uint8 *key, uint32 key_len)
{
    uint8 key_[33] = {0};
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;
    uint32 keyLen = vin_len + key_len;

    if ((key_len != 16) || (key == NULL_PTR))
    {
        rec = 0x13;
        return rec;
    }

    if (vin == NULL_PTR)
    {
        if (vin_len == 0)
        {
            keyLen = 16;
        }
        else
        {
            /* code */
            rec = 0x13;
            return rec;
        }
    }
    else
    {
        if (vin_len != 17)
        {
            rec = 0x13;
            return rec;
        }
    }

    if (vin_len > 0)
    {
        (void)memcpy(key_, vin, vin_len);
    }
    (void)memcpy(key_ + vin_len, key, key_len);

    retVal = Csm_KeyElementSet(CMAC_KEY, CMAC_KEY_ELEMENT, key_, keyLen);

    if (retVal == E_OK)
    {
        retVal = Csm_JobKeySetValid(CsmConf_CsmJob_CsmJob_KeySetValid, CMAC_KEY);
    }

    if (retVal != E_OK)
    {
        rec = 0x72;
    }
    return rec;
}

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
uint8 Cdd_HsmGetCmacKey(uint8 *key, uint32 *key_len)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementGet(CMAC_KEY, CMAC_KEY_ELEMENT, key, key_len);
    if (retVal != E_OK)
    {
        rec = 0x72;
    }

    return rec;
}

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
uint8 Cdd_HsmGetCmacKeyState(HSM_KeyStateEnum *state)
{
    uint8 rec = 0;
    uint8 state_t = 0;
    uint32 len = 1;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementGet(CMAC_KEY, CMAC_KEY_STATE, &state_t, &len);
    if (retVal != E_OK)
    {
        rec = 0x72;
    }
    else
    {
        *state = (HSM_KeyStateEnum)state_t;
    }

    return rec;
}

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
uint8 _Cdd_HsmSetAes128Key(const uint8 *IV, const uint8 *key, uint32 key_len)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementSet(AES128_KEY, AES128_KEY_ELEMENT, key, key_len);
    retVal |= Csm_KeyElementSet(AES128_KEY, AES128_KEY_IV_ELEMENT, IV, key_len);

    if (retVal == E_OK)
    {
        retVal = Csm_JobKeySetValid(CsmConf_CsmJob_CsmJob_KeySetValid, AES128_KEY);
    }

    if (retVal != E_OK)
    {
        rec = 0x72;
    }

    return rec;
}
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
uint8 Cdd_HsmGetAes128Key(uint8 *IV, uint8 *key, uint32 *key_len)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementGet(AES128_KEY, AES128_KEY_ELEMENT, key, key_len);
    retVal |= Csm_KeyElementGet(AES128_KEY, AES128_KEY_IV_ELEMENT, IV, key_len);
    if (retVal != E_OK)
    {
        rec = 0x72;
    }

    return rec;
}

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
void Cdd_HsmTrngGenerate(uint8 *Trng, uint32 *len)
{
    (void)Csm_RandomGenerate(CsmConf_CsmJob_CsmJob_Random, Trng, len);
}

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
uint8 _Cdd_HsmSetSecureBoot_AppA_Info(
    uint32 addr,
    uint32 length,
    uint8 mode,
    uint8 *cmac,
    uint32 cmacLen)
{
    Std_ReturnType retVal = E_NOT_OK;

    if ((mode != 0) && (mode != 1))
    {
        return 0x33;
    }
    while (cmacLen)
    {
        cmacLen = cmacLen-1;
        if (cmac[cmacLen] != cmac[0])
        {
            break;
        }
        return 0x33;
    }

    retVal = Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS,
        (uint8 *)&addr, 4);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE,
        (uint8 *)&length, 4);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Mode_Sync,
        &mode, 1);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC,
        cmac, 16);

    if (retVal == E_OK)
    {
        // retVal = Csm_KeySetValid(AES128_KEY);
        retVal = Csm_JobKeySetValid(CsmConf_CsmJob_CsmJob_KeySetValid, CsmConf_CsmKey_CsmKey_SecureBootAPP_A);
    }

    return retVal;
}

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
uint8 Cdd_HsmGetSecureBoot_AppA_Info(
    uint8 *addr,
    uint8 *length,
    uint8 *mode,
    uint8 *cmac)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 len = 4;
    retVal = Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS,
        addr, &len);
    len = 4;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE,
        length, &len);
    len = 1;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_A_Mode_Sync,
        mode, &len);
    len = 16;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_A,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC,
        cmac, &len);
    return retVal;
}

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
uint8 _Cdd_HsmSetSecureBoot_AppB_Info(
    uint32 addr,
    uint32 length,
    uint8 mode,
    uint8 *cmac,
    uint32 cmacLen)
{
    Std_ReturnType retVal = E_NOT_OK;

    if ((mode != 0) && (mode != 1))
    {
        return 0x33;
    }
    while (cmacLen)
    {
        cmacLen = cmacLen-1;
        if (cmac[cmacLen] != cmac[0])
        {
            break;
        }
        return 0x33;
    }

    retVal = Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS,
        (uint8 *)&addr, 4);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE,
        (uint8 *)&length, 4);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Mode_Sync,
        &mode, 1);
    retVal |= Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC,
        cmac, 16);

    if (retVal == E_OK)
    {
        // retVal = Csm_KeySetValid(AES128_KEY);
        retVal = Csm_JobKeySetValid(
            CsmConf_CsmJob_CsmJob_KeySetValid,
            CsmConf_CsmKey_CsmKey_SecureBootAPP_B);
    }

    return retVal;
}
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
uint8 Cdd_HsmGetSecureBoot_AppB_Info(
    uint8 *addr,
    uint8 *length,
    uint8 *mode,
    uint8 *cmac)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 len = 4;
    retVal = Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS,
        addr, &len);
    len = 4;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE,
        length, &len);
    len = 1;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBootSegment_APPL_B_Mode_Sync,
        mode, &len);
    len = 16;
    retVal |= Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAPP_B,
        CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC,
        cmac, &len);
    return retVal;
}

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
uint8 _Cdd_HsmSetSecureBootKey(uint8 *key, uint32 keyLen)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAppKey,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Key_Sync,
        key, keyLen);

    if (retVal == E_OK)
    {
        retVal = Csm_JobKeySetValid(
            CsmConf_CsmJob_CsmJob_KeySetValid,
            CsmConf_CsmKey_CsmKey_SecureBootAppKey);
    }

    if (retVal != E_OK)
    {
        rec = 0x72;
    }
    return rec;
}

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
uint8 Cdd_HsmGetSecureBootKey(uint8 *key, uint32 *key_len)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAppKey,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Key_Sync,
        key, key_len);
    if (retVal != E_OK)
    {
        rec = 0x72;
    }

    return rec;
}
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
uint8 _Cdd_HsmSecureBoot_SetAppAction(uint8 Section)
{
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementSet(
        CsmConf_CsmKey_CsmKey_SecureBootAppKey,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Section_Active_Sync,
        &Section, 1);

    if (retVal == E_OK)
    {
        retVal = Csm_JobKeySetValid(CsmConf_CsmJob_CsmJob_KeySetValid, CsmConf_CsmKey_CsmKey_SecureBootAppKey);
    }
    return retVal;
}
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
uint8 Cdd_HsmSecureBoot_GetAppAction(uint8 *active, uint32 *key_len)
{
    uint8 rec = 0;
    Std_ReturnType retVal = E_NOT_OK;

    retVal = Csm_KeyElementGet(
        CsmConf_CsmKey_CsmKey_SecureBootAppKey,
        CryptoConf_CryptoKeyElement_Crypto_30_LibCv_vHsm_SecureBoot_Section_Active_Sync,
        active, key_len);
    if (retVal != E_OK)
    {
        rec = 0x72;
    }

    return rec;
}

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
static uint8 Cdd_HsmSetCmacKey_cbk(void)
{
    return _Cdd_HsmSetCmacKey(CMAC_PARAM.vin, CMAC_PARAM.vin_len, CMAC_PARAM.key, CMAC_PARAM.key_len);
}
uint8 Cdd_HsmSetCmacKey(const uint8 *vin, uint32 vin_len, const uint8 *key, uint32 key_len)
{
    if ((vin_len > sizeof(CMAC_PARAM.vin)) || (key_len > sizeof(CMAC_PARAM.key)))
    {
        return E_NOT_OK;
    }
    (void)memcpy(CMAC_PARAM.vin, vin, vin_len);
    CMAC_PARAM.vin_len = vin_len;
    (void)memcpy(CMAC_PARAM.key, key, key_len);
    CMAC_PARAM.key_len = key_len;
    HSM_SET_ACTIVE(HSM_ACTIVE_CMAC_SETKEY);

    return E_OK;
}
static uint8 Cdd_HsmSetAes128Key_Cbk(void)
{
    return _Cdd_HsmSetAes128Key(AES128_PARAM.IV, AES128_PARAM.key, AES128_PARAM.key_len);
}
uint8 Cdd_HsmSetAes128Key(const uint8 *IV, const uint8 *key, uint32 key_len)
{
    if (key_len > sizeof(AES128_PARAM.key))
    {
        return E_NOT_OK;
    }
    (void)memcpy(AES128_PARAM.IV, IV, key_len);
    (void)memcpy(AES128_PARAM.key, key, key_len);
    AES128_PARAM.key_len = key_len;
    HSM_SET_ACTIVE(HSM_ACTIVE_AES128_SETKEY);
    return E_OK;
}
static uint8 Cdd_HsmSetSecureBoot_AppA_Info_cbk(void)
{
    return _Cdd_HsmSetSecureBoot_AppA_Info(
        SECBOOT_A_PARAM.addr,
        SECBOOT_A_PARAM.length,
        SECBOOT_A_PARAM.mode,
        SECBOOT_A_PARAM.cmac,
        SECBOOT_A_PARAM.cmacLen);
}
uint8 Cdd_HsmSetSecureBoot_AppA_Info(
    uint32 addr,
    uint32 length,
    uint8 mode,
    uint8 *cmac,
    uint32 cmacLen)
{
    if (cmacLen > sizeof(SECBOOT_A_PARAM.cmac))
    {
        return E_NOT_OK;
    }
    SECBOOT_A_PARAM.addr = addr;
    SECBOOT_A_PARAM.length = length;
    SECBOOT_A_PARAM.mode = mode;
    (void)memcpy(SECBOOT_A_PARAM.cmac, cmac, cmacLen);
    SECBOOT_A_PARAM.cmacLen = cmacLen;
    HSM_SET_ACTIVE(HSM_ACTIVE_SECBOOT_A_SETINFO);

    return E_OK;
}
static uint8 Cdd_HsmSetSecureBoot_AppB_Info_cbk(void)
{
    return _Cdd_HsmSetSecureBoot_AppB_Info(
        SECBOOT_B_PARAM.addr,
        SECBOOT_B_PARAM.length,
        SECBOOT_B_PARAM.mode,
        SECBOOT_B_PARAM.cmac,
        SECBOOT_B_PARAM.cmacLen);
}
uint8 Cdd_HsmSetSecureBoot_AppB_Info(
    uint32 addr,
    uint32 length,
    uint8 mode,
    uint8 *cmac,
    uint32 cmacLen)
{
    if (cmacLen > sizeof(SECBOOT_B_PARAM.cmac))
    {
        return E_NOT_OK;
    }
    SECBOOT_B_PARAM.addr = addr;
    SECBOOT_B_PARAM.length = length;
    SECBOOT_B_PARAM.mode = mode;
    (void)memcpy(SECBOOT_B_PARAM.cmac, cmac, cmacLen);
    SECBOOT_B_PARAM.cmacLen = cmacLen;
    HSM_SET_ACTIVE(HSM_ACTIVE_SECBOOT_B_SETINFO);

    return E_OK;
}

static uint8 Cdd_HsmSetSecureBootKey_cbk(void)
{
    return _Cdd_HsmSetSecureBootKey(SECBOOT_KEY_PARAM.key, SECBOOT_KEY_PARAM.key_len);
}
uint8 Cdd_HsmSetSecureBootKey(uint8 *key, uint32 keyLen)
{
    if (keyLen > sizeof(SECBOOT_KEY_PARAM.key))
    {
        return E_NOT_OK;
    }
    (void)memcpy(SECBOOT_KEY_PARAM.key, key, keyLen);
    SECBOOT_KEY_PARAM.key_len = keyLen;
    HSM_SET_ACTIVE(HSM_ACTIVE_SECBOOT_SETKEY);

    return E_OK;
}

static uint8 Cdd_HsmSecureBoot_SetAppAction_cbk(void)
{
    return _Cdd_HsmSecureBoot_SetAppAction(SECBOOT_ACTION_APP_PARAM.Section);
}
uint8 Cdd_HsmSecureBoot_SetAppAction(uint8 Section)
{
    if (Section > 1)
    {
        return E_NOT_OK;
    }
    SECBOOT_ACTION_APP_PARAM.Section = Section;
    HSM_SET_ACTIVE(HSM_ACTIVE_SECBOOT_SETAPP);
    return E_OK;
}
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
SetValid:(WaitSetValidCbk)
        Set Key Return E_OK&
        DataFlashAccessStop E_OK
+------+                        +------+
| IDLE +----------------------->+ WAIT |
++----++                        +--+---+
 |    ^                            |
 |    |                            Wait 5s Timeout /
 |    DataFlashAccessStart E_OK    Set Key Callback Event
 |    |                            |
 |    +-------+----------+         |
 |            | Complete +<--------+
 +----------->+----------+
 Set Key Return E_NOR_OK
 */

void Cdd_HsmMainFunction(void)
{
    uint8 ret = E_OK;
    static uint8 index = 0;
    static uint16 loop = 1000; ///> The task cycle is 5ms and Wait for SET Key 5S
    MemIf_StatusType FlsState = Fls_GetStatus();
    switch (WaitSetValidCbk)
    {
        
    case SET_VALID_IDLE:
        for (index = 0; index < (sizeof(hsm_pcb) / sizeof(HSM_PCB_ST)); index++)
        {
            if (HSM_GET_ACTIVE(index) && (FlsState == MEMIF_IDLE) && (SetValidIsBusy == FALSE) && (hsm_pcb[index].call != NULL_PTR))
            {
                Fls_GenState = MEMIF_BUSY_INTERNAL;
                ret = Cdd_HsmDataFlashStop();
                if (ret != E_OK)
                {
                    (void)printf("Cdd_HsmMainFunction Error 1 !! \r\n");
                    Fls_GenState = MEMIF_IDLE;
                    return;
                }

                ret = hsm_pcb[index].call();
                if (ret == E_OK)
                {
                    WaitSetValidCbk = SET_VALID_WAIT;
                }
                else
                {
                    WaitSetValidCbk = SET_VALUE_SET_ERR;
                }
                break;
            }
        }
        break;
    case SET_VALID_WAIT:
        if (loop > 0)
        {
            loop--;
        }
        else
        {
            WaitSetValidCbk = SET_VALUE_SET_ERR;
            loop = 1000;
            (void)printf("timeout !!\r\n");
        }
        break;
    case SET_VALUE_START_ERR:
        break;
    case SET_VALUE_SET_ERR: ///> An error during set, terminates the set but does not clear the flag
        loop = 1000;
        ret = Cdd_HsmDataFlashStart();
        if (ret == E_OK)
        {
            if(0 < HSM_GET_ATTEMT_CNT(index))
            {
                HSM_DEC_ATTEMT_CNT(index);
            }
            else
            {
                if(HSM_GET_MODULE_FAIL_CBK(index) != NULL)
                {
                        HSM_GET_MODULE_FAIL_CBK(index)();
                } 
                HSM_RESET_ATTEMT_CNT(index);
                HSM_CLR_ACTIVE(index);
            }
            WaitSetValidCbk = SET_VALID_IDLE;
            Fls_GenState = MEMIF_IDLE;
        }
        break;
    case SET_VALUE_COMP:
        loop = 1000;

        ret = Cdd_HsmDataFlashStart();
        if (ret == E_OK)
        {
            if(HSM_GET_MODULE_OK_CBK(index) != NULL)
            {
                HSM_GET_MODULE_OK_CBK(index)();
                HSM_RESET_ATTEMT_CNT(index);
            } 
            HSM_CLR_ACTIVE(index);
            WaitSetValidCbk = SET_VALID_IDLE;
            Fls_GenState = MEMIF_IDLE;
        }
        else
        {
        }
        break;
    default:
        break;
    }
}
/**********************************************************************************************************************
 *  END OF FILE: Cdd_Hsm.c
 *********************************************************************************************************************/
#endif //CDD_HSM_SOURCE
