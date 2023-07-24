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
 * @file:      Cdd_Hsm.h
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

#ifndef CDD_HSM_INCLUDE
#define CDD_HSM_INCLUDE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HSM_ACTIVE_AES128_SETKEY  (0u)
#define HSM_ACTIVE_CMAC_SETKEY  (1u)
#define HSM_ACTIVE_SECBOOT_A_SETINFO  (2u)
#define HSM_ACTIVE_SECBOOT_B_SETINFO  (3u)
#define HSM_ACTIVE_SECBOOT_SETKEY  (4u)
#define HSM_ACTIVE_SECBOOT_SETAPP  (5u)

#define HSM_PCB_ATTEMPS_MAX_TIME    (10U)
#define HSM_SET_ACTIVE(modle)  do{\
    hsm_pcb[modle].active=TRUE;\
}while(0);

#define HSM_CLR_ACTIVE(modle)  do{\
    hsm_pcb[modle].active=FALSE;\
}while(0);

#define HSM_GET_MODULE_OK_CBK(modle)    (hsm_pcb[modle].ok_cbk)
#define HSM_GET_MODULE_FAIL_CBK(modle)  (hsm_pcb[modle].fail_cbk)
#define HSM_GET_ATTEMT_CNT(modle)       (hsm_pcb[modle].count)
#define HSM_DEC_ATTEMT_CNT(modle)       (HSM_GET_ATTEMT_CNT(modle)--)
#define HSM_RESET_ATTEMT_CNT(modle)     (hsm_pcb[modle].count = HSM_PCB_ATTEMPS_MAX_TIME)
#define HSM_GET_ACTIVE(modle) (hsm_pcb[modle].active)
/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
typedef uint8 (*hsm_call)(void);
typedef void (*hsm_result_cbk)(void);

typedef enum
{
    SET_VALID_IDLE,
    SET_VALID_WAIT,
    SET_VALUE_COMP,
    SET_VALUE_SET_ERR,
    SET_VALUE_START_ERR,
    SET_VALUE_STOP_ERR
} SET_VALID_EM;

typedef struct{
    uint8 IV[0x20];
    uint8 key[0x20];
    uint32 key_len;
}AES128_PARAM_ST;
typedef struct{
    uint8 vin[0x20];
    uint32 vin_len;
    uint8 key[0x20];
    uint32 key_len;
}CMAC_PARAM_ST;
typedef struct{
    uint32 addr; 
    uint32 length;
    uint8 mode; 
    uint8 cmac[0x20]; 
    uint32 cmacLen;
}SECBOOT_PARAM_ST;
typedef struct{
    uint8 key[0x20];
    uint32 key_len;
}SECBOOT_KEY_PARAM_ST;
typedef struct{
    uint8 Section;
}SECBOOT_ACTION_APP_PARAM_ST;
/**
 * @brief 
 * 
 */
typedef struct{
    hsm_call call;
    boolean active;
    uint8 count;
    hsm_result_cbk fail_cbk;
    hsm_result_cbk ok_cbk;
}HSM_PCB_ST;
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
uint8 Cdd_HsmDataFlashStart(void);
uint8 Cdd_HsmDataFlashStop(void);
void Cdd_HsmCodeFlashStart(void);
void Cdd_HsmCodeFlashStop(void);
void Cdd_HsmEnableIcup2CpuInterrupt(void);
uint8 Cdd_HsmSetCmacKey(const uint8* vin, uint32 vin_len, const uint8* key, uint32 key_len);
uint8 Cdd_HsmGetCmacKey(uint8* key, uint32* key_len);
uint8 Cdd_HsmGetCmacKeyState(HSM_KeyStateEnum* state);
uint8 Cdd_HsmSetSecureBoot_AppA_Info(uint32 addr, uint32 length, uint8 mode, uint8* cmac, uint32 cmacLen);
uint8 Cdd_HsmSetSecureBoot_AppB_Info(uint32 addr, uint32 length, uint8 mode, uint8* cmac, uint32 cmacLen);
uint8 Cdd_HsmGetSecureBoot_AppA_Info(uint8* addr, uint8* length, uint8* mode, uint8* cmac);
uint8 Cdd_HsmGetSecureBoot_AppB_Info(uint8* addr, uint8* length, uint8* mode, uint8* cmac);
uint8 Cdd_HsmSetSecureBootKey(uint8* key, uint32 keyLen);
uint8 Cdd_HsmGetSecureBootKey(uint8*key, uint32 *key_len);
uint8 Cdd_HsmGetAes128Key(uint8 *IV, uint8 *key, uint32 *key_len);
uint8 Cdd_HsmSetAes128Key(const uint8 *IV, const uint8 *key, uint32 key_len);
void Cdd_HsmTrngGenerate(uint8* Trng, uint32 *len);
uint8 Cdd_HsmSecureBoot_SetAppAction(uint8 Section);
uint8 Cdd_HsmSecureBoot_GetAppAction(uint8* active, uint32 *key_len);
boolean Cdd_HsmSetValidIsBusy(void);
boolean Cdd_HsmCodeFlashIsAllow(void);
void Cdd_HsmMainFunction(void);
/**********************************************************************************************************************
 *  END OF FILE: Cdd_Hsm.h
 *********************************************************************************************************************/
#endif //CDD_HSM_INCLUDE
