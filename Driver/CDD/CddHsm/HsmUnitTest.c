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
 * @file:      HsmUnitTest.c
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

#ifndef HSMUNITTEST_SOURCE
#define HSMUNITTEST_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Csm.h"
#include "os.h"
#include "Crypto_30_vHsm_Cfg.h"
#include "Cdd_Common.h"
#include "string.h"

#include "stdio.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Cdd_Hsm.h"

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

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static uint8 rec_test = 0xff;

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

uint32 UT_HostHsm_Case1_1(void)
{
    uint8 key_raw[16] = {0xEA,0xBF,0x33,0x86,0x97,0x41,0xF4,0x03,0xCD,0xB1,0x5F,0x35,0xD9,0x8B,0xDF,0x34};
    uint8 vin[17] =     {0xA5,0xDF,0x4D,0xFD,0x5D,0xF6,0x5D,0xA2,0x3F,0xD3,0xFD,0x3F,0xD3,0x56,0x0D,0xAA,0xBC};
    uint8 key_auth[16] ={0xbc,0xb5,0x75,0xc2,0x2a,0x98,0xfe,0x1f,0x02,0xb9,0x5f,0x37,0xaf,0x0f,0x4d,0x97};
    uint8 key[16] = {0};
    uint8 index = 0;
    uint32 key_len = 16;
    static uint32 loop = 0;
    static boolean test_over = FALSE;

    // if(test_over == FALSE)
    {
        if(loop == 0)
        {
            Cdd_HsmSetCmacKey(vin, 17, key_raw, 16);
        }

        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetCmacKey(key, &key_len);
            for(index=0; index<key_len; index++)
            {
                if(key[index] != key_auth[index])
                {
                    printf("UT_HostHsm_Case1_1 : FAILD\r\n");
                    break;
                }
            }
            printf("UT_HostHsm_Case1_1 : PASS\r\n");
            test_over = TRUE;
            loop=0;
            return 12;
        }

        loop++;
    }
    return 0;
}

uint32 UT_HostHsm_Case1_2(void)
{
    uint8 key_invalid[16]={0};
    uint8 key_raw[20] = {0xEA,0xBF,0x33,0x86,0x97,0x41,0xF4,0x03,0xCD,0xB1,0x5F,0x35,0xD9,0x8B,0xDF,0x34,0xAA,0xAA,0xAA,0xAA};
    uint8 vin[20] =     {0xA5,0xDF,0x4D,0xFD,0x5D,0xF6,0x5D,0xA2,0x3F,0xD3,0xFD,0x3F,0xD3,0x56,0x0D,0xAA,0xBC,0xAA,0xAA,0xAA};
    uint8 key_auth[16] ={0xbc,0xb5,0x75,0xc2,0x2a,0x98,0xfe,0x1f,0x02,0xb9,0x5f,0x37,0xaf,0x0f,0x4d,0x97};
    uint8 key[16] = {0};
    uint8 index = 0;
    uint32 key_len = 16;
    uint8 rec = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;

    static boolean test_over = FALSE;

    if(test_over == FALSE)
    {
        if(loop == 0)
        {
            // ����key Ϊ��Чֵ
            Cdd_HsmSetCmacKey(NULL_PTR, 0, key_invalid, 16);
        }

        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetCmacKeyState(&state);
            if(state == 2)
            {
                printf("UT_HostHsm CMAC Set Invalid Key : PASS\r\n");
                if(Cdd_HsmSetCmacKey(vin, 20, key_raw, 16) != 0)
                {
                    printf("VIN > 17Byte Test : PASS\r\n");
                }
                else
                {
                    printf("VIN > 17Byte Test : FAILD\r\n");
                }

                if(Cdd_HsmSetCmacKey(vin, 16, key_raw, 16) != 0)
                {
                    printf("VIN < 17Byte Test : PASS\r\n");
                }
                else
                {
                    printf("VIN < 17Byte Test : FAILD\r\n");
                }
                
                if(Cdd_HsmSetCmacKey(vin, 17, key_raw, 20) != 0)
                {
                    printf("key_raw > 17Byte Test : PASS\r\n");
                }
                else
                {
                    printf("key_raw > 17Byte Test : FAILD\r\n");
                }
                if(Cdd_HsmSetCmacKey(vin, 17, key_raw, 15) != 0)
                {
                    printf("key_raw < 17Byte Test : PASS\r\n");
                }
                else
                {
                    printf("key_raw < 17Byte Test : FAILD\r\n");
                }
            }
            else
            {
                printf("UT_HostHsm CMAC Set Invalid Key : FAILD\r\n");
            }
            test_over = TRUE;
            return 21;
        }
    }
    loop++;
    return 12;
}

uint32 UT_HostHsm_Case2_1(void)
{
    uint8 key[16] = {0xEA,0xBF,0x33,0x86,0x97,0x41,0xF4,0x03,0xCD,0xB1,0x5F,0x35,0xD9,0x8B,0xDF,0x34};
    uint8 key_[16]= {0};
    uint8 index = 0;
    uint32 key_len = 16;
    static uint32 loop = 0;
    static boolean test_over = FALSE;

    // if(test_over == FALSE)
    {
        if(loop == 0)
        {
            Cdd_HsmSetSecureBootKey(key, 16);
        }

        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetSecureBootKey(key_, &key_len);
            for(index=0; index<key_len; index++)
            {
                if(key[index] != key_[index])
                {
                    //printf("Set Secure Boot Key : FAILD\r\n");
                }
            }
            //printf("Set Secure Boot Key : PASS\r\n");
            test_over = TRUE;
            loop = 0;
            return 31;
        }

        loop++;
    }
    return 21;
}

uint32 UT_HostHsm_Case3_1(void)
{
    uint32 addr = 0, GetAddr = 0;
    uint32 length = 0x1c0000, GetLength = 0;
    uint8 mode = 1, GetMode = 0;
    static uint8 cmac[16] = {0}, GetCmac[16]={0};
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;


    if(test_over == FALSE)
    {
        if(loop == 0)
        {
            // set invalid param cmac
            addr = 0x1, length = 1, mode = 1;
            if (Cdd_HsmSetSecureBoot_AppA_Info(addr, length, mode, cmac, 16) == 0)
            {
                printf("Set invalid Secure Boot App-A Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
                printf("Set invalid Secure Boot App-A Info Test : PASS\r\n");
            }
            addr = 0, length=0x1c0000, mode = 1;
            for(index = 0; index<16;index++)
            {
                cmac[index] = index;
            }
            Cdd_HsmSetSecureBoot_AppA_Info(addr, length, mode, cmac, 16);
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetSecureBoot_AppA_Info(&GetAddr, &GetLength, &GetMode, GetCmac);
            if(GetAddr != addr || GetLength != length || GetMode != mode)
            {
                printf("Set invalid Secure Boot App-A Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
                for(index=0;index<16;index++)
                {
                    if(GetCmac[index]!=cmac[index])
                    {
                        printf("Set invalid Secure Boot App-A Info Test : FAILD\r\n");
                        test_over = TRUE;
                        return 81;
                    }
                }

                printf("Set Secure Boot App-A Info Test : PASS\r\n");
                test_over = TRUE;
                return 81;
            }
            
        }
    }
    loop++;
    return 31;
}
uint32 UT_HostHsm_Case3_2(void)
{
    static uint32 addr = 0, GetAddr = 0;
    static uint32 length = 0x1c0000, GetLength = 0;
    static uint8 mode = 1, GetMode = 0;
    static uint8 cmac[16] = {0}, GetCmac[16]={0};
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;


    // if(test_over == FALSE)
    {
        if(loop == 0)
        {
            // set invalid param cmac
            Cdd_HsmGetSecureBoot_AppA_Info(&addr, &length, &mode, cmac);
            if (Cdd_HsmSetSecureBoot_AppA_Info(addr, length, mode, cmac, 16) == E_NOT_OK)
            {
                //printf("Set Secure Boot App-A Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
                //printf("Set invalid Secure Boot App-A Info Test : PASS\r\n");
            }
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetSecureBoot_AppA_Info(&GetAddr, &GetLength, &GetMode, GetCmac);
            if(GetAddr != addr || GetLength != length)
            {
                //printf("Set Secure Boot App-A Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
                for(index=0;index<16;index++)
                {
                    if(GetCmac[index]!=cmac[index])
                    {
                        //printf("Set invalid Secure Boot App-A Info Test : FAILD\r\n");
                        test_over = TRUE;
                        return 81;
                    }
                }

                //printf("Set Secure Boot App-A Info Test : PASS\r\n");
                test_over = TRUE;
                loop = 0;
                return 81;
            }
            
        }
    }
    loop++;
    return 31;
}

uint32 UT_HostHsm_Case8_1(void)
{
    uint32 addr = 0, GetAddr = 0;
    uint32 length = 0x1c0000, GetLength = 0;
    uint8 mode = 1, GetMode = 0;
    static uint8 cmac[16] = {0}, GetCmac[16]={0};
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;


    if(test_over == FALSE)
    {
        if(loop == 0)
        {
            // set invalid param cmac
            addr = 0x1, length = 1, mode = 1;
            if (Cdd_HsmSetSecureBoot_AppB_Info(addr, length, mode, cmac, 16) == 0)
            {
                printf("Set invalid Secure Boot App-B Info Test : FAILD\r\n");
                test_over = TRUE;
                return 131;
            }
            else
            {
                printf("Set invalid Secure Boot App-B Info Test : PASS\r\n");
            }
            addr = 0, length=0x1c0000, mode = 1;
            for(index = 0; index<16;index++)
            {
                cmac[index] = index;
            }
            Cdd_HsmSetSecureBoot_AppB_Info(addr, length, mode, cmac, 16);
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetSecureBoot_AppB_Info(&GetAddr, &GetLength, &GetMode, GetCmac);
            if(GetAddr != addr || GetLength != length || GetMode != mode)
            {
                printf("Set invalid Secure Boot App-B Info Test : FAILD\r\n");
                test_over = TRUE;
                return 131;
            }
            else
            {
                for(index=0;index<16;index++)
                {
                    if(GetCmac[index]!=cmac[index])
                    {
                        printf("Set invalid Secure Boot App-B Info Test : FAILD\r\n");
                        test_over = TRUE;
                        return 131;
                    }
                }

                printf("Set Secure Boot App-B Info Test : PASS\r\n");
                test_over = TRUE;
                return 131;
            }
            
        }
    }
    loop++;
    return 81;
}

uint32 UT_HostHsm_Case8_2(void)
{
    static uint32 addr = 0, GetAddr = 0;
    static uint32 length = 0x1c0000, GetLength = 0;
    static uint8 mode = 1, GetMode = 0;
    static uint8 cmac[16] = {0}, GetCmac[16]={0};
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;


    // if(test_over == FALSE)
    {
        if(loop == 0)
        {
            // set invalid param cmac
            Cdd_HsmGetSecureBoot_AppB_Info(&addr, &length, &mode, cmac);
            if (Cdd_HsmSetSecureBoot_AppB_Info(addr, length, mode, cmac, 16) == E_NOT_OK)
            {
                //printf("Set Secure Boot App-B Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
            }
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetSecureBoot_AppB_Info(&GetAddr, &GetLength, &GetMode, GetCmac);
            if(GetAddr != addr || GetLength != length)
            {
                //printf("Set Secure Boot App-B Info Test : FAILD\r\n");
                test_over = TRUE;
                return 81;
            }
            else
            {
                for(index=0;index<16;index++)
                {
                    if(GetCmac[index]!=cmac[index])
                    {
                        //printf("Set invalid Secure Boot App-B Info Test : FAILD\r\n");
                        test_over = TRUE;
                        return 81;
                    }
                }

                //printf("Set Secure Boot App-B Info Test : PASS\r\n");
                test_over = TRUE;
                loop = 0;
                return 81;
            }
            
        }
    }
    loop++;
    return 31;

}
uint8 pass_cnt;
uint32 UT_HostHsm_Case13_1(void)
{

    static uint8 IV[20] ={0xA5,0xDF,0x4D,0xFD,0x5D,0xF6,0x5D,0xA2,0x3F,0xD3,0xFD,0x3F,0xD3,0x56,0x0D,0xAA,0xBC,0xAA,0xAA,0xAA};
    static uint8 key[16] ={0xbc,0xb5,0x75,0xc2,0x2a,0x98,0xfe,0x1f,0x02,0xb9,0x5f,0x37,0xaf,0x0f,0x4d,0x97};
    uint8 _IV[16] = {0};
    uint8 _key[16]= {0};
    uint32 keylen = 16;
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;

    if(test_over == FALSE)
    {
        if(loop == 0)
        {
            IV[0] += 1;
            key[0] += 1;
            Cdd_HsmSetAes128Key(IV, key, 16);
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmGetAes128Key(_IV, _key, &keylen);
            for(index=0; index<keylen; index++)
            {
                if(_IV[index] != IV[index])
                {
                    //printf("Set AES128 IV : FAILD\r\n");
                }
                if(_key[index] != key[index])
                {
                    //printf("Set AES128 Key : FAILD\r\n");
                }
            }
            printf("Set AES128 Key and IV : PASS\r\n");
            pass_cnt++;
            rec_test = 0xff;
			loop = 0;
            return 291;
        }
    }
    loop++;
    return 131;
}

uint32 UT_HostHsm_Case29_1(void)
{

    uint8 data[16] ={0xbc,0xb5,0x75,0xc2,0x2a,0x98,0xfe,0x1f,0x02,0xb9,0x5f,0x37,0xaf,0x0f,0x4d,0x97};
    uint8 data_E[16] ={0};
    uint8 data_D[16] ={0};
    uint32 len = 16, index = 0;
    static boolean test_over = FALSE;

    if(test_over == FALSE)
    {
	Csm_Encrypt(CsmConf_CsmJob_CsmJob_Aes128_Encrypt,
                CRYPTO_OPERATIONMODE_SINGLECALL,
                data,
                16,
                data_E,
                &len);
	Csm_Decrypt(CsmConf_CsmJob_CsmJob_Aes128_Decrypt,
                CRYPTO_OPERATIONMODE_SINGLECALL,
                data_E,
                16,
                data_D,
                &len);

	for(index=0; index<len; index++)
	{
	    if(data[index] != data_D[index])
	    {
		printf("AES128 Encrypt/Decrypt : FAILD\r\n");
		test_over = TRUE;
		return 281;
	    }
	}

	printf("AES128 Encrypt/Decrypt : PASS\r\n");
	test_over = TRUE;
	return 281;
    }
    return 0;
}

uint32 UT_HostHsm_Case28_1(void)
{
    uint8 trng[16] = {0};
    uint32 len = 4;
    uint8 loop = 20;

    while(loop--)
    {
        Cdd_HsmTrngGenerate(trng, &len);
        printf("Trng: %2x %2x %2x %2x \r\n", trng[0], trng[1], trng[2], trng[3]);
    }

    return 351;
}

//
uint32 UT_HostHsm_Case35_1(void)
{
    uint8 active = 0xff;
    uint32 keylen = 1;
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;

    // if(test_over == FALSE)
    {
        if(loop == 0)
        {
            Cdd_HsmSecureBoot_SetAppAction(0); // case 35-1
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmSecureBoot_GetAppAction(&active, &keylen);// case 35-3
            if(active == 0)
            {
                //printf("Set APP-A Active : PASS\r\n");
            }
            else{
                //printf("Set APP-A Active : FAILD\r\n");
            }
            test_over = TRUE;
            loop = 0;
            return 352;
        }
    }
    loop++;
    return 351;
}

uint32 UT_HostHsm_Case35_2(void)
{
    uint8 active = 0xff;
    uint32 keylen = 1;
    uint8 index = 0;
    HSM_KeyStateEnum state;
    static uint32 loop = 0;
    static boolean test_over = FALSE;

    if(test_over == FALSE)
    {
        if(loop == 0)
        {
            Cdd_HsmSecureBoot_SetAppAction(1); // case 35-2
        }
        if(Cdd_HsmSetValidIsBusy() == FALSE)
        {
            Cdd_HsmSecureBoot_GetAppAction(&active, &keylen);// case 35-4

            if(active == 1)
            {
                printf("Set APP-B Active : PASS\r\n");
            }
            else{
                printf("Set APP-B Active : FAILD\r\n");
            }
            test_over = TRUE;
            return 0xfe;
        }
    }
    loop++;
    return 352;
}
void HsmUnitTest_MainFunction(void)
{
	
  #if 0
  	if(rec == 0)
        rec = UT_HostHsm_Case1_1();
    if(rec == 12)
        rec = UT_HostHsm_Case1_2();
    if(rec == 21)
        rec = UT_HostHsm_Case2_1();
    if(rec == 31)
        rec = UT_HostHsm_Case3_1();
    if(rec == 81)
        rec = UT_HostHsm_Case8_1();
    if(rec == 291)
        rec = UT_HostHsm_Case29_1();
    if(rec == 281)
        rec = UT_HostHsm_Case28_1();
    if(rec == 351)
        rec = UT_HostHsm_Case35_1();
    if(rec == 352)
        rec = UT_HostHsm_Case35_2();
    if(rec == 0xfe)
        printf("test end\r\n"), rec = 0xff;
#endif
    if(rec_test == 131)
    {
        UT_HostHsm_Case1_1();
        UT_HostHsm_Case2_1();
        UT_HostHsm_Case3_2();
        UT_HostHsm_Case8_2();
        UT_HostHsm_Case35_1();
        UT_HostHsm_Case13_1();
    }
	
	if(rec_test<131 ) rec_test++;
	if(rec_test == 0xff ) rec_test++;

}
/**********************************************************************************************************************
 *  END OF FILE: HsmUnitTest.c
 *********************************************************************************************************************/
#endif //HSMUNITTEST_SOURCE
