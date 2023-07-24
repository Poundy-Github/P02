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
 * @file:      CLM.c
 * @author:    Nobo
 * @date:      2020-12-20
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-20
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file%
 */
#include "dr7f701651.dvf.h"
#include "Std_Types.h"
#include "Cdd_Common.h"
#include "logger.h"
#include "CLM.h"

/*
 *  %typedef/macro defintion%
 */
#define CLM_SELF_TEST_NUMBER    (4U)
#define CYCLE_PER_US            (240U)

/*
 *  %forward declaration%
 */
static void CLM_Delayus(uint32 us);
static Std_ReturnType CLM_SelfTest0(boolean isHigh);
static Std_ReturnType CLM_SelfTest1(boolean isHigh);
static Std_ReturnType CLM_SelfTest2(boolean isHigh);
static void CLM_ResetError(void);


/*
 *  %global definition%
 */
static Std_ReturnType clm_status[CLM_SELF_TEST_NUMBER] = {E_OK, E_OK, E_OK, E_OK};

/*
 *  %function definition%
 */

/*
* @brief   :   init state machine
* @param   :   sm[IN]: runtime data of state machine
* @param   :   config[IN]: config of state machine
* @retval  :   SM_E_NO_ERROR: initialize success
* @retval  :   SM_E_PARAM_POINTER: zero pointer error
* @retval  :   SM_E_UNINIT: already initialized
*/
static void CLM_Delayus(uint32 us)
{
    uint32 i;
    uint32 j;

    for(i = 0; i < us; i++)
    {
        for(j = 0; j < CYCLE_PER_US; j++)
        {
            ASM_NOP();
        }
    }
}

void CLM_SelfTest(void)
{
    Std_ReturnType ret;

    ret = CLM_SelfTest0(FALSE);
    if(E_NOT_OK == ret)
    {
        clm_status[0] = E_NOT_OK;
    }
    else
    {
        ret = CLM_SelfTest0(TRUE);
        if(E_NOT_OK == ret)
        {
            clm_status[0] = E_NOT_OK;
        }
    }
    
    ret = CLM_SelfTest1(FALSE);
    if(E_NOT_OK == ret)
    {
        clm_status[1] = E_NOT_OK;
    }
    else
    {
        ret = CLM_SelfTest1(TRUE);
        if(E_NOT_OK == ret)
        {
            clm_status[1] = E_NOT_OK;
        }
    }

    ret = CLM_SelfTest2(FALSE);
    if(E_NOT_OK == ret)
    {
        clm_status[2] = E_NOT_OK;
    }
    else
    {
        ret = CLM_SelfTest2(TRUE);
        if(E_NOT_OK == ret)
        {
            clm_status[2] = E_NOT_OK;
        }
    }
}

static Std_ReturnType CLM_SelfTest0(boolean isHigh)
{
    Std_ReturnType ret = E_OK;
    uint32 data;

    if(FALSE == isHigh)
    {
        CLMA0CMPH = 0x4U;                               /* Setting of the maximum CLMA0 threshold(Set CLMA0CMPH to 0004H) */
        CLMA0CMPL = 0x1U;                               /* Setting of the minimum CLMA0 threshold(Set CLMA0CMPL to 0001H) */
    }
    else
    {
        CLMA0CMPH = 0xFFFU;                             /* Setting of the maximum CLMA0 threshold(Set CLMA0CMPH to 0FFFH) */
        CLMA0CMPL = 0xFFCU;                             /* Setting of the minimum CLMA0 threshold(Set CLMA0CMPL to 0FFCH) */
    }

    /* Enable CLMA0 self-test mode(Set CLMATEST.CLMA0TESEN to 1) */
    /* Mask CLMA0 reset signal(Set CLMATEST.ERRMSK to 1) */
    data = CLMATEST;
    BIT_SET_SELF(data, 2);
    BIT_SET_SELF(data, 3);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);
                                                
    if(BIT_GET(CLMATESTS, 0) == 0x0)            /* CLMA0 errors not detected(CLMATESTS.CLMA0ERRS = 0)? */
    {
        data = CLMA0CTL0;                       /* Yes Enable CLMA0(Set CLMA0CTL0.CLMA0CLME to 1) */
        BIT_SET_SELF(data, 0);
        protected_write(CLMA0PCMD, CLMA0PS, CLMA0CTL0, (uint8)data);
        CLM_Delayus(145U);                      /* Wait 145us */

        if(BIT_GET(CLMATESTS, 0) == 0x1)        /* CLMA0 errors detected(CLMATESTS.CLMA0ERRS = 1)? */
        {
            CLM_ResetError();                   /* Execute CLMA0 test reset(Set CLMATEST.RESCLM to 1 -> 0) */

            if(BIT_GET(CLMATESTS, 0) != 0x0)    /* CLMA0 errors not detected(CLMATESTS.CLMA0ERRS = 0)? */
            {
                ret = E_NOT_OK;
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    if(E_NOT_OK == ret)
    {
        /* Execute CLMA test reset(Set CLMATEST.RESCLM to 1 -> 0) */
        CLM_ResetError();
    }

    /* Set threshold to default */
    CLMA0CMPH = 0x0U;
    CLMA0CMPL = 0xFFFU;

    /* Clear mask of CLMA reset signal(Set CLMATEST.ERRMSK to 0) */
    /* Disable CLMA0 self-test mode(Set CLMATEST.CLMA0TESEN to 0) */
    data = CLMATEST;
    BIT_CLR_SELF(data, 2);
    BIT_CLR_SELF(data, 3);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);

    return ret;
}

static Std_ReturnType CLM_SelfTest1(boolean isHigh)
{
    Std_ReturnType ret = E_OK;
    uint32 data;

    if(FALSE == isHigh)
    {
        CLMA1CMPH = 0x4U;                               /* Setting of the maximum CLMA1 threshold(Set CLMA1CMPH to 0004H) */
        CLMA1CMPL = 0x1U;                               /* Setting of the minimum CLMA1 threshold(Set CLMA1CMPL to 0001H) */
    }
    else
    {
        CLMA1CMPH = 0xFFFU;                             /* Setting of the maximum CLMA1 threshold(Set CLMA1CMPH to 0FFFH) */
        CLMA1CMPL = 0xFFCU;                             /* Setting of the minimum CLMA1 threshold(Set CLMA1CMPL to 0FFCH) */
    }

    /* Enable CLMA1 self-test mode(Set CLMATEST.CLMA1TESEN to 1) */
    /* Mask CLMA1 reset signal(Set CLMATEST.ERRMSK to 1) */
    data = CLMATEST;
    BIT_SET_SELF(data, 2);
    BIT_SET_SELF(data, 4);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);
                                                
    if(BIT_GET(CLMATESTS, 1) == 0x0)            /* CLMA1 errors not detected(CLMATESTS.CLMA1ERRS = 0)? */
    {
        data = CLMA1CTL0;                       /* Yes Enable CLMA1(Set CLMA1CTL0.CLMA1CLME to 1) */
        BIT_SET_SELF(data, 0);
        protected_write(CLMA1PCMD, CLMA1PS, CLMA1CTL0, (uint8)data);
        CLM_Delayus(145U);                      /* Wait 145us */

        if(BIT_GET(CLMATESTS, 1) == 0x1)        /* CLMA1 errors detected(CLMATESTS.CLMA1ERRS = 1)? */
        {         
            CLM_ResetError();                   /* Execute CLMA1 test reset(Set CLMATEST.RESCLM to 1 -> 0) */
            if(BIT_GET(CLMATESTS, 1) != 0x0)    /* CLMA1 errors not detected(CLMATESTS.CLMA1ERRS = 0)? */
            {
                ret = E_NOT_OK;
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    if(E_NOT_OK == ret)
    {
        /* Execute CLMA test reset(Set CLMATEST.RESCLM to 1 -> 0) */
        CLM_ResetError();
    }

    /*Clear mask of CLMA reset signal(Set CLMATEST.ERRMSK to 0) */
    /* Disable CLMA1 self-test mode(Set CLMATEST.CLMA1TESEN to 0) */
    data = CLMATEST;
    BIT_CLR_SELF(data, 2);
    BIT_CLR_SELF(data, 4);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);

    /* Set threshold to default */
    CLMA1CMPH = 0x0U;
    CLMA1CMPL = 0xFFFU;

    return ret;
}

static Std_ReturnType CLM_SelfTest2(boolean isHigh)
{
    Std_ReturnType ret = E_OK;
    uint32 data;

    if(FALSE == isHigh)
    {
        CLMA2CMPH = 0x4U;                               /* Setting of the maximum CLMA2 threshold(Set CLMA2CMPH to 0004H) */
        CLMA2CMPL = 0x1U;                               /* Setting of the minimum CLMA2 threshold(Set CLMA2CMPL to 0001H) */
    }
    else
    {
        CLMA2CMPH = 0xFFFU;                             /* Setting of the maximum CLMA2 threshold(Set CLMA2CMPH to 0FFFH) */
        CLMA2CMPL = 0xFFCU;                             /* Setting of the minimum CLMA2 threshold(Set CLMA2CMPL to 0FFCH) */
    }

    /* Enable CLMA2 self-test mode(Set CLMATEST.CLMA2TESEN to 1) */
    /* Mask CLMA2 reset signal(Set CLMATEST.ERRMSK to 1) */
    data = CLMATEST;
    BIT_SET_SELF(data, 2);
    BIT_SET_SELF(data, 5);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);
                                                
    if(BIT_GET(CLMATESTS, 2) == 0x0)            /* CLMA2 errors not detected(CLMATESTS.CLMA2ERRS = 0)? */
    {       
        data = CLMA2CTL0;                       /* Yes Enable CLMA2(Set CLMA2CTL0.CLMA2CLME to 1) */
        BIT_SET_SELF(data, 0);
        protected_write(CLMA2PCMD, CLMA2PS, CLMA2CTL0, (uint8)data);
        CLM_Delayus(5U);                        /* Wait 5us */

        if(BIT_GET(CLMATESTS, 2) == 0x1)        /* CLMA2 errors detected(CLMATESTS.CLMA2ERRS = 1)? */
        {
            CLM_ResetError();                   /* Execute CLMA2 test reset(Set CLMATEST.RESCLM to 1 -> 0) */
            if(BIT_GET(CLMATESTS, 2) != 0x0)    /* CLMA2 errors not detected(CLMATESTS.CLMA2ERRS = 0)? */
            {
                ret = E_NOT_OK;
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    if(E_NOT_OK == ret)
    {
        /* Execute CLMA test reset(Set CLMATEST.RESCLM to 1 -> 0) */
        CLM_ResetError();
    }

    /* Set threshold to default */
    CLMA2CMPH = 0x0U;
    CLMA2CMPL = 0xFFFU;

    /*Clear mask of CLMA reset signal(Set CLMATEST.ERRMSK to 0) */
    /* Disable CLMA2 self-test mode(Set CLMATEST.CLMA2TESEN to 0) */
    data = CLMATEST;
    BIT_CLR_SELF(data, 2);
    BIT_CLR_SELF(data, 5);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);

    return ret;
}

static void CLM_ResetError(void)
{
    uint32 data;

    data = CLMATEST;
    BIT_SET_SELF(data, 0);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);
    data = CLMATEST;
    BIT_CLR_SELF(data, 0);
    protected_write(CLMAPROTCMDCLMA, CLMAPROTSCLMA, CLMATEST, data);
}

void CLM_ErrorHandle(void)
{
    uint8 index;

    for(index = 0U; index < CLM_SELF_TEST_NUMBER; index++)
    {
        if(clm_status[index] != E_OK)
        {
            (void)sys_err("CLM%d self test error.", index);
            clm_status[index] = E_OK;
        }
    }
}
