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
 * @file:      EccTst.c
 * @author:    Nobo
 * @date:      2020-11-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-11-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  EccTst.c
 *           Config:  E:/Project/V3_5_VIP/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  EccTst
 *  Generation Time:  2020-11-25 10:22:51
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <EccTst>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EccTst.h"
//#include "RamTst.h"
#include "FlsTst.h"
#include "logger.h"
#include "SysSafety.h"

#define Rte_Enter_ExclusiveArea_SysSafety() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define Rte_Exit_ExclusiveArea_SysSafety() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


#define SysSafety_START_SEC_CONST_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*Walking-1, All-1, All-0, 2-bit error*/
static const uint32 RamTst_DataTable[42] = 
{
    0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U, 0x00000000U,
    0x00000000U, 0x00000000U, 0x80000000U, 0x40000000U, 0x20000000U, 
    0x10000000U, 0x08000000U, 0x04000000U, 0x02000000U, 0x01000000U,     
    0x00800000U, 0x00400000U, 0x00200000U, 0x00100000U, 0x00080000U,     
    0x00040000U, 0x00020000U, 0x00010000U, 0x00008000U, 0x00004000U,     
    0x00002000U, 0x00001000U, 0x00000800U, 0x00000400U, 0x00000200U,     
    0x00000100U, 0x00000080U, 0x00000040U, 0x00000020U, 0x00000010U,     
    0x00000008U, 0x00000004U, 0x00000002U, 0x00000001U, 0xFFFFFFFFU,
    0x00000000U, 0x00000003U,
};

#define SysSafety_STOP_SEC_CONST_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#pragma ghs section bss=".LocalRamECCTest"
uint32 RamTst_LocalData[42];
#pragma ghs section bss=default

#pragma ghs section bss=".GlobalRamAECCTest"
uint32 RamTst_GlobalAData[42];
#pragma ghs section bss=default

#pragma ghs section bss=".GlobalRamBECCTest"
uint32 RamTst_GlobalBData[42];
#pragma ghs section bss=default


#define SysSafety_START_SEC_VAR_INIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static uint8 EccTst_DelayCount;
static uint32 EccTst_FeintFactor;

EccTst_ERROR_t EccTst_ErrorInfo[ECCTST_ERROR_NUM];

#define SysSafety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

//#define ECCTST_ERROR_TRIGGER
#define ECCTST_ERROR_CLEAR    


#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static Std_ReturnType RamTst_LocalTestEcc(void);

#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: EccTst_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EccTst_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

void EccTst_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EccTst_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define SysSafety_START_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EccTst_SelfTest(void)
{
    FlsTst_Init( FlsTstConfigSet );
    
    EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].selftest = FlsTst_TestEcc();

    EccTst_ErrorInfo[ECCTST_LOCALRAM].selftest = RamTst_LocalTestEcc();

}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EccTst_MonitorHandle(uint8 type)
{
    uint32 errcnt;
    uint32 erraddr;

    if(type < ECCTST_ERROR_NUM) 
    {
        if(EccTst_ErrorInfo[type].selftest == E_OK)
        {
            if(EccTst_ErrorInfo[type].sedtrig == TRUE)
            {
                Rte_Enter_ExclusiveArea_SysSafety();
                EccTst_ErrorInfo[type].sedtrig = FALSE;
                errcnt = EccTst_ErrorInfo[type].sedcnt;
                erraddr = EccTst_ErrorInfo[type].sedaddr;
                Rte_Exit_ExclusiveArea_SysSafety();
                
                /*Single Ecc Error Detected */
                #ifdef SYSSAFETY_DEBUG_ENABLE
                sys_info("FUSA ECC Single Test Failed, count: %d, address:%08X", errcnt, erraddr);
                #endif  
            }

            if(EccTst_ErrorInfo[type].dedtrig == TRUE)
            {
                Rte_Enter_ExclusiveArea_SysSafety();
                EccTst_ErrorInfo[type].dedtrig = FALSE;
                errcnt = EccTst_ErrorInfo[type].dedcnt;
                erraddr = EccTst_ErrorInfo[type].dedaddr;
                Rte_Exit_ExclusiveArea_SysSafety();

                /*Double Ecc Error Detected*/ 
                #ifdef SYSSAFETY_DEBUG_ENABLE
                sys_info("FUSA ECC Double Test Failed, count: %d, address:%08X", errcnt, erraddr);
                #endif 
            }
        }
        else
        {
            /*SelfTest Error*/
            #ifdef SYSSAFETY_DEBUG_ENABLE
            sys_info("FUSA ECC Selftest Failed");
            #endif 
        }        
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType RamTst_LocalTestEcc(void)
{
    /* Declare the variable to store the return value */
    Std_ReturnType LenReturnValue;
    uint8 LucPatternNumber;
    uint8 LucExpectedError;
    volatile uint32 *LulEccTestAddress;
    uint32 LulEccSaveAddress;
    uint32 LulCompareData;
    uint32 LulDataWord;
    uint32 LucLoopCount;
    uint8 LucEccDelayCount;
    uint32 regError;
    uint32 regAddress;
    
    /* Set the default  return values */
    LenReturnValue = E_OK;
    LulEccSaveAddress = ECCTST_ZERO;

    RAMECCTST_ENTER_CRITICAL_SECTION();
    
    for(LucLoopCount = 0U; LucLoopCount < RAMTST_ECC_END_PATTERN; LucLoopCount++)
    {
        /*Inject Test Ram Data*/
        RamTst_LocalData[LucLoopCount] = RamTst_DataTable[LucLoopCount];
    }

    /*Enable Ecc Test Mode, Inject Test EccData*/
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRTSTCTL_PE1, RAMTST_ECC_LOCAL_ENTRY_TEST_MODE);
    while(RAMTST_LOCAL_LRTSTCTL_PE1 != RAMTST_ECC_LOCAL_TEST_MODE){};
    
    RamTst_LocalData[0] = 0x43;
    RamTst_LocalData[1] = 0x23;
    RamTst_LocalData[2] = 0x13;
    RamTst_LocalData[3] = 0x0B;
    RamTst_LocalData[4] = 0x07;
    RamTst_LocalData[5] = 0x01;
    RamTst_LocalData[6] = 0x02;
    RamTst_LocalData[7] = 0x03;
    RamTst_LocalData[8] = 0x03;
    RamTst_LocalData[9] = 0x03;
    RamTst_LocalData[10] = 0x03;
    RamTst_LocalData[11] = 0x03;
    RamTst_LocalData[12] = 0x03;
    RamTst_LocalData[13] = 0x03;
    RamTst_LocalData[14] = 0x03;
    RamTst_LocalData[15] = 0x03;
    RamTst_LocalData[16] = 0x03;
    RamTst_LocalData[17] = 0x03;
    RamTst_LocalData[18] = 0x03;
    RamTst_LocalData[19] = 0x03;
    RamTst_LocalData[20] = 0x03;
    RamTst_LocalData[21] = 0x03;
    RamTst_LocalData[22] = 0x03;
    RamTst_LocalData[23] = 0x03;
    RamTst_LocalData[24] = 0x03;
    RamTst_LocalData[25] = 0x03;
    RamTst_LocalData[26] = 0x03;
    RamTst_LocalData[27] = 0x03;
    RamTst_LocalData[28] = 0x03;
    RamTst_LocalData[29] = 0x03;
    RamTst_LocalData[30] = 0x03;
    RamTst_LocalData[31] = 0x03;
    RamTst_LocalData[32] = 0x03;
    RamTst_LocalData[33] = 0x03;
    RamTst_LocalData[34] = 0x03;
    RamTst_LocalData[35] = 0x03;
    RamTst_LocalData[36] = 0x03;
    RamTst_LocalData[37] = 0x03;
    RamTst_LocalData[38] = 0x03;
    RamTst_LocalData[39] = 0x03;
    RamTst_LocalData[40] = 0x03;
    RamTst_LocalData[41] = 0x03;
    
    /*Diable Ecc Test Mode*/
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRTSTCTL_PE1, RAMTST_ECC_EXIT_TEST_MODE);
    while(RAMTST_LOCAL_LRTSTCTL_PE1 != RAMTST_ECC_NORMAL_MODE){};

    /* Disable ECC notification */
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRERRINT_PE1, RAMTST_ECC_DISABLE_NOTIFICATION);

    /* Enable Ecc error detection and SEC */
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRECCCTL_PE1, RAMTST_ECC_SEC_ACTIVATE);

    /* Clear Ecc status register*/
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRSTCLR_PE1, ECCTST_ONE);
    
    LucPatternNumber = ECCTST_ONE;
    /* QAC Warning: START Msg(2:3892)-7 */
    LulCompareData = ECCTST_ZERO;
    /* END Msg(2:3892)-7 */
    
    /* MISRA Violation: START Msg(4:0303)-1 */
    LulEccTestAddress = &RamTst_LocalData[0];
    /* END Msg(4:0303)-1 */
    do
    {
        /* Small delay for ECC error and address status update */
        for (LucEccDelayCount = ECCTST_ZERO;
                 LucEccDelayCount < RAMTST_ECC_TEST_DELAY; LucEccDelayCount++)
        {
          /* No operation */
          ASM_NOP();
        }
    
        /* read the data from ECC self test area */
        LulDataWord = *(LulEccTestAddress);
        
        if (LulDataWord == (uint32)LulCompareData)
        {
          if (LucPatternNumber < RAMTST_WALK1_END)
          {
            LucExpectedError = ECCTST_ONE;

            LulEccSaveAddress = (uint32)LulEccTestAddress - RAMTST_LOCAL_ECC_ERROR_ADDRESS_OFFSET;
          }
          else if(LucPatternNumber == RAMTST_ECC_END_PATTERN)
          {
            LucExpectedError = ECCTST_TWO;

            LulEccSaveAddress = (uint32)LulEccTestAddress - RAMTST_LOCAL_ECC_ERROR_ADDRESS_OFFSET;
          }
          else
          {
            /* Set the expected error value and the address value */
            LucExpectedError = ECCTST_ZERO;
            LulEccSaveAddress = ECCTST_ZERO;
          }

          regError = RAMTST_LOCAL_LR1STERSTR_PE1;
          regAddress = RAMTST_LOCAL_LR1STEADR0_PE1;
          /* Check ECC error flags */
          if ((regError != LucExpectedError) || (regAddress != LulEccSaveAddress))
          {
            /* update Test status flag as failed  */
            LenReturnValue = E_NOT_OK;
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* update Test status flag as failed  */
          LenReturnValue = E_NOT_OK;
        }

        /* Increase the read address */
        LulEccTestAddress++;
        
        /* Increase the pattern number */
        LucPatternNumber++;
        
        /* Check Pattern number reached end of walk1 test */
        if (RAMTST_WALK1_END == LucPatternNumber)
        {
            /* Set compare value as 0xFFFFFFFF */
            LulCompareData = RAMTST_ALL1_VALUE;
        }
        else if (RAMTST_ALL1_END == LucPatternNumber)
        {
            /* Set compare value as 0x00000000 */
            LulCompareData = RAMTST_LONG_WORD_ZERO;
        }
        else if (RAMTST_ECC_END_PATTERN == LucPatternNumber)
        {
            /* Set compare value as 0x00000003 */
            LulCompareData = RAMTST_2BIT_ERROR_VALUE;
        }
        else
        {
            /* No action required */
        }
        
        /* Clear the ECC error */
        RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRSTCLR_PE1, ECCTST_ONE);
    } while (LucPatternNumber <= RAMTST_ECC_END_PATTERN);

#ifdef ECCTST_ERROR_CLEAR
    /*Clear All Test Patrten*/
    for(LucLoopCount = 0U; LucLoopCount < RAMTST_ECC_END_PATTERN; LucLoopCount++)
    {
        RamTst_LocalData[LucLoopCount] = RamTst_DataTable[LucLoopCount];
    }
#endif    
    
    /* Clear Ecc status register*/
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRSTCLR_PE1, ECCTST_ONE);

    /* Enable Ecc error detection and SEC */
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRECCCTL_PE1, RAMTST_ECC_SEC_ACTIVATE);
    
    /* Enable ECC notification */
    RAMTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRERRINT_PE1, RAMTST_ECC_ENABLE_NOTIFICATION);
    
    RAMECCTST_EXIT_CRITICAL_SECTION();

    return(LenReturnValue);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EccTst_FETINT_Notification(void)
{
    uint32 reg;
//    asm("PUSHSP       R6-R29     ");

    EccTst_FeintFactor = ECCTST_FEINTF;

    /*Code Flash Ecc Error*/
    if(EccTst_FeintFactor & ECCTST_FEINT_CODEFLASH_MASK)
    {
        /*VCI*/
        reg = FLSTST_CF1STERSTR_VCI;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].dedcnt++;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].dedaddr = FLSTST_CF1STEADR0_VCI;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].sedcnt++;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_VCI].sedaddr = FLSTST_CF1STEADR0_VCI;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(FLSTST_CFSTCLR_VCI, ECCTST_ONE);

        /*PE1*/
        reg = FLSTST_CF1STERSTR_PE1;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].dedcnt++;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].dedaddr = FLSTST_CF1STEADR0_PE1;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].sedcnt++;
            EccTst_ErrorInfo[ECCTST_CODEFLASH_PE1].sedaddr = FLSTST_CF1STEADR0_PE1;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(FLSTST_CFSTCLR_PE1, ECCTST_ONE);
    }
    
    /*Data Flash Ecc Error*/
    if(EccTst_FeintFactor & ECCTST_FEINT_DATAFLASH_MASK)
    {
        reg = FLSTST_DFERSTR;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_DATAFLASH].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_DATAFLASH].dedcnt++;
            EccTst_ErrorInfo[ECCTST_DATAFLASH].dedaddr = FLSTST_DFEADR+FLSTST_DATA_FLASH_ECC_ERROR_ADDRESS_OFFSET;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_DATAFLASH].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_DATAFLASH].sedcnt++;
            EccTst_ErrorInfo[ECCTST_DATAFLASH].sedaddr = FLSTST_DFEADR+FLSTST_DATA_FLASH_ECC_ERROR_ADDRESS_OFFSET;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(FLSTST_DFERSTC, ECCTST_ONE);
    }

    /*Ram Flash Ecc Error*/
    if(EccTst_FeintFactor & ECCTST_FEINT_RAMFLASH_MASK)
    {
        /*Local Ram*/
        reg = RAMTST_LOCAL_LR1STERSTR_PE1;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_LOCALRAM].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_LOCALRAM].dedcnt++;
            EccTst_ErrorInfo[ECCTST_LOCALRAM].dedaddr = RAMTST_LOCAL_LR1STEADR0_PE1+RAMTST_LOCAL_ECC_ERROR_ADDRESS_OFFSET;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_LOCALRAM].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_LOCALRAM].sedcnt++;
            EccTst_ErrorInfo[ECCTST_LOCALRAM].sedaddr = RAMTST_LOCAL_LR1STEADR0_PE1+RAMTST_LOCAL_ECC_ERROR_ADDRESS_OFFSET;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(RAMTST_LOCAL_LRSTCLR_PE1, ECCTST_ONE);

        /*GlobalA Ram*/
        reg = RAMTST_GLOBAL_GR1STERSTR_BKA;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].dedcnt++;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].dedaddr = RAMTST_GLOBAL_GR1STEADR_BKA;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].sedcnt++;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_A].sedaddr = RAMTST_GLOBAL_GR1STEADR_BKA;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(RAMTST_GLOBAL_GRSTCLR_BKA, ECCTST_ONE);

        /*GlobalB Ram*/
        reg = RAMTST_GLOBAL_GR1STERSTR_BKB;
        if((reg == ECCTST_ERROR_OVERFLOW) || (reg == ECCTST_ERROR_DED))
        {
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].dedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].dedcnt++;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].dedaddr = RAMTST_GLOBAL_GR1STEADR_BKB;
        }
        else if(reg == ECCTST_ERROR_SED)
        {
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].sedtrig = TRUE;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].sedcnt++;
            EccTst_ErrorInfo[ECCTST_GLOBALRAM_B].sedaddr = RAMTST_GLOBAL_GR1STEADR_BKB;
        }
        else
        {
            /*No Error*/
        }
        ECCTST_WRITE_REG_ONLY(RAMTST_GLOBAL_GRSTCLR_BKB, ECCTST_ONE);
    }
    
    /*Clear FEINT Factor*/
    ECCTST_WRITE_REG_ONLY(ECCTST_FEINTFC, ECCTST_FEINT_CLEAR);

    /* Small delay for ECC error and address status update */
    for (EccTst_DelayCount = ECCTST_ZERO; EccTst_DelayCount < ECCTST_DELAY; EccTst_DelayCount++)
    {
      ASM_NOP();
    }

    /*Return ISR*/
//    asm("POPSP       R6-R29     ");
//    asm("JR       _SWG3KH_FETINT");
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EccTst_SYSERR_Notification(void)
{
//    asm("PUSHSP       R6-R29     ");

    /*Clear System Error Factor*/
    *((uint32 volatile *)(0xFFFEE982)) = 0x00000000;

//    asm("POPSP       R6-R29     ");
//    asm("JR       _SWG3KH_SYSERR");
}


#define SysSafety_STOP_SEC_CODE
#include "SysSafety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
