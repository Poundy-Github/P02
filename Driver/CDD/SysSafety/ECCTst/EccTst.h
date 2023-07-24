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
 * @file:      EccTst.h
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

#ifndef _ECCTST_H_
#define _ECCTST_H_

#include "Std_Types.h"

#define RAMECCTST_ENTER_CRITICAL_SECTION()        
#define RAMECCTST_EXIT_CRITICAL_SECTION()         


#define RAMTST_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
do \
{ \
  (pWriteRegAddr) = (uiRegWriteValue); \
} \
while(0)


#define ECCTST_WRITE_REG_ONLY(pWriteRegAddr, uiRegWriteValue)  \
do \
{ \
  (pWriteRegAddr) = (uiRegWriteValue); \
} \
while(0)


/* Macro to avoid direct numbers */
#define RAMTST_LONG_WORD_ZERO              (uint32)0x00000000UL
/* Macro to avoid direct numbers */
#define RAMTST_SHORT_WORD_ZERO             (uint16)0x0000
/* Macro for default values for DCRA unit */


#define RAMTST_ECC_TEST_DELAY              (uint8)0x1F
#define RAMTST_ALL1_VALUE                  (uint32)0xFFFFFFFFUL
#define RAMTST_2BIT_ERROR_VALUE            (uint32)0x00000003UL
#define RAMTST_ECC_SEC_ACTIVATE            (uint16)0x4000
#define RAMTST_ECC_SEC_INACTIVATE          (uint16)0x4003
#define RAMTST_ECC_DISABLE_NOTIFICATION    (uint8)0x00
#define RAMTST_ECC_ENABLE_NOTIFICATION     (uint8)0x03
#define RAMTST_ECC_LOCAL_ENTRY_TEST_MODE   (uint16)0x4003
#define RAMTST_ECC_LOCAL_TEST_MODE         (uint16)0x0003
#define RAMTST_ECC_GLOBAL_ENTRY_TEST_MODE  (uint16)0x4001
#define RAMTST_ECC_GLOBAL_TEST_MODE        (uint16)0x0001
#define RAMTST_ECC_EXIT_TEST_MODE          (uint16)0x4000
#define RAMTST_ECC_NORMAL_MODE             (uint16)0x0000
#define RAMTST_WALK1_END                   (uint8)0x28
#define RAMTST_ALL1_END                    (uint8)0x29
#define RAMTST_ECC_END_PATTERN             (uint8)0x2A

#define ECCTST_DELAY              (uint8)0x1F
#define ECCTST_ZERO               (uint8)0x00
#define ECCTST_ONE                (uint8)0x01
#define ECCTST_TWO                (uint8)0x02

#define ECCTST_ERROR_NUM      6U

#define ECCTST_CODEFLASH_PE1    0U
#define ECCTST_CODEFLASH_VCI    1U
#define ECCTST_DATAFLASH        2U
#define ECCTST_LOCALRAM         3U
#define ECCTST_GLOBALRAM_A      4U
#define ECCTST_GLOBALRAM_B      5U

#define ECCTST_NO_ERROR         0U
#define ECCTST_ERROR_SED        1U
#define ECCTST_ERROR_DED        2U
#define ECCTST_ERROR_OVERFLOW   3U

#define ECCTST_FEINT_CLEAR                  (uint32)0xFFFFFFFFUL


#define ECCTST_FEINT_CODEFLASH_MASK     (uint32)0x00001000uL
#define ECCTST_FEINT_DATAFLASH_MASK     (uint32)0x00000010uL
#define ECCTST_FEINT_RAMFLASH_MASK      (uint32)0x00002000uL


/*Local Ram ECC Registers*/
/* Local ECC self test address */
#define RAMTST_LOCAL_ECC_SELF_TEST_ADDRESS      ((volatile uint32 *)0xfebe7e74uL)

/* Global ECC self test address */
#define RAMTST_GLOBAL_ECC_SELF_TEST_ADDRESS     ((volatile uint32 *)0x01032000uL)

/*Data Flash Ecc Error Address Offset*/
#define FLSTST_DATA_FLASH_ECC_ERROR_ADDRESS_OFFSET      (0xFE200000)

/*Locla Ecc Error Address Offset*/
#define RAMTST_LOCAL_ECC_ERROR_ADDRESS_OFFSET           (0xFEB80000)

/*GlobaA Ecc Error Address Offset*/
#define RAMTST_GLOBALA_ECC_ERROR_ADDRESS_OFFSET         (0xFEE00000)

/*GlobaB Ecc Error Address Offset*/
#define RAMTST_GLOBALB_ECC_ERROR_ADDRESS_OFFSET         (0xFEF00000)


/* Local RAM test control register (PE1) */
#define RAMTST_LOCAL_LRTSTCTL_PE1               (*((volatile uint32 *)(0xffc65004uL)))

/* Local RAM test data read buffer 0 (PE1) */
#define RAMTST_LOCAL_LRTDATBF0_PE1              (*((volatile uint32 *)(0xffc65008uL)))

/* Local RAM ECC control register (PE1) */
#define RAMTST_LOCAL_LRECCCTL_PE1               (*((volatile uint32 *)(0xffc65400uL)))

/* Local RAM error information control register (PE1) */
#define RAMTST_LOCAL_LRERRINT_PE1               (*((volatile uint32 *)(0xffc65404uL)))

/* Local RAM status clear register (PE1) */
#define RAMTST_LOCAL_LRSTCLR_PE1                (*((volatile uint32 *)(0xffc65408uL)))

/* Local RAM error count overflow status register (PE1) */
#define RAMTST_LOCAL_LROVFSTR_PE1               (*((volatile uint32 *)(0xffc6540CuL)))

/* Local RAM 1st error status register (PE1) */
#define RAMTST_LOCAL_LR1STERSTR_PE1             (*((volatile uint32 *)(0xffc65410uL)))

/* Local RAM 1st error address register 0 (PE1) */
#define RAMTST_LOCAL_LR1STEADR0_PE1             (*((volatile uint32 *)(0xffc65450uL)))

/*Global BankA Ram ECC Registers*/
/* Global RAM ECC control register (Bank A) */
#define RAMTST_GLOBAL_GRECCCTL_BKA              (*((volatile uint32 *)(0xffc64000uL)))

/* Global RAM error information control register (Bank A) */
#define RAMTST_GLOBAL_GRERRINT_BKA              (*((volatile uint32 *)(0xffc64004uL)))

/* Global RAM status clear register (Bank A) */
#define RAMTST_GLOBAL_GRSTCLR_BKA               (*((volatile uint32 *)(0xffc64010uL)))

/* Global RAM error count overflow status register (Bank A)  */
#define RAMTST_GLOBAL_GROVFSTR_BKA              (*((volatile uint32 *)(0xffc64014uL)))

/* Global RAM 1st error status register (Bank A) */
#define RAMTST_GLOBAL_GR1STERSTR_BKA            (*((volatile uint32 *)(0xffc64018uL)))

/* Global RAM 1st error address register (Bank A) */
#define RAMTST_GLOBAL_GR1STEADR_BKA             (*((volatile uint32 *)(0xffc6401CuL)))

/* Global RAM test control register (Bank A) */
#define RAMTST_GLOBAL_GRTSTCTL_BKA              (*((volatile uint32 *)(0xffc64020uL)))

/* Global RAM ECC decoder input data buffer 1 (Bank A) */
#define RAMTST_GLOBAL_GRDECINBF1_BKA            (*((volatile uint32 *)(0xffc64024uL)))

/*Global BankB Ram ECC Registers*/
/* Global RAM ECC control register (Bank B */
#define RAMTST_GLOBAL_GRECCCTL_BKB              (*((volatile uint32 *)(0xffc64200uL)))

/* Global RAM error information control register (Bank B) */
#define RAMTST_GLOBAL_GRERRINT_BKB              (*((volatile uint32 *)(0xffc64204uL)))

/* Global RAM status clear register (Bank B) */
#define RAMTST_GLOBAL_GRSTCLR_BKB               (*((volatile uint32 *)(0xffc64210uL)))

/* Global RAM error count overflow status register (Bank B)  */
#define RAMTST_GLOBAL_GROVFSTR_BKB              (*((volatile uint32 *)(0xffc64214uL)))

/* Global RAM 1st error status register (Bank B) */
#define RAMTST_GLOBAL_GR1STERSTR_BKB            (*((volatile uint32 *)(0xffc64218uL)))

/* Global RAM 1st error address register (Bank B) */
#define RAMTST_GLOBAL_GR1STEADR_BKB             (*((volatile uint32 *)(0xffc6421CuL)))

/* Global RAM test control register (Bank B) */
#define RAMTST_GLOBAL_GRTSTCTL_BKB              (*((volatile uint32 *)(0xffc64220uL)))

/* Global RAM ECC decoder input data buffer 1 (Bank B) */
#define RAMTST_GLOBAL_GRDECINBF1_BKB            (*((volatile uint32 *)(0xffc64224uL)))


/*Systerm Error Control Register*/
#define SYSTEM_SEGCONT                          (*((volatile uint16 *)(0xfffee980uL)))

/*Code flash status clear register (VCI)*/
#define FLSTST_CFSTCLR_VCI                      (*((volatile uint32 *)(0xffc62208uL)))

/*Code flash 1st error status register (VCI)*/
#define FLSTST_CF1STERSTR_VCI                   (*((volatile uint32 *)(0xffc62210uL)))

/*Code flash 1st error address register (VCI)*/
#define FLSTST_CF1STEADR0_VCI                   (*((volatile uint32 *)(0xffc62250uL)))

/*Code flash status clear register (PE1)*/
#define FLSTST_CFSTCLR_PE1                      (*((volatile uint32 *)(0xffc62408uL)))

/*Code flash 1st error status register (PE1)*/
#define FLSTST_CF1STERSTR_PE1                   (*((volatile uint32 *)(0xffc62410uL)))

/*Code flash 1st error address register (PE1)*/
#define FLSTST_CF1STEADR0_PE1                   (*((volatile uint32 *)(0xffc62450uL)))


/*Data flash error status clear register*/
#define FLSTST_DFERSTC                          (*((volatile uint8 *)(0xffc62a08uL)))

/*Data flash error status register*/
#define FLSTST_DFERSTR                          (*((volatile uint8 *)(0xffc62a04uL)))

/*Data flash 1st error address register*/
#define FLSTST_DFEADR                           (*((volatile uint32 *)(0xffc62a18uL)))


/*FEINT factor register*/
#define ECCTST_FEINTF                           (*((volatile uint32 *)(0xffc00100uL)))

/*FEINT factor mask register*/
#define ECCTST_FEINTFMSK                        (*((volatile uint32 *)(0xffc00104uL)))

/*FEINT factor clear register*/
#define ECCTST_FEINTFC                          (*((volatile uint32 *)(0xffc00108uL)))

typedef struct 
{
    Std_ReturnType selftest;
    uint8 sedtrig;    
    boolean dedtrig;
    uint32 sedcnt;    
    uint32 dedcnt;
    uint32 sedaddr;
    uint32 dedaddr;    
}EccTst_ERROR_t;

extern uint32 RamTst_LocalData[];
extern uint32 RamTst_GlobalAData[];
extern uint32 RamTst_GlobalBData[];
extern EccTst_ERROR_t EccTst_ErrorInfo[];

void SuspendAllInterrupts(void);
void ResumeAllInterrupts(void);

void EccTst_Init(void);
void EccTst_SelfTest(void);
void  EccTst_MonitorHandle(uint8 type);
void EccTst_FETINT_Notification(void);
void EccTst_SYSERR_Notification(void);

#endif /* ifndef _ECCTST_H_.2020-11-25 10:24:37 GW00191223 */

