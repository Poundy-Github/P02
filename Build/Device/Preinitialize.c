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
 * @file:      Preinitialize.c
 * @author:    Nobo
 * @date:      2020-8-3
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-3
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "dr7f701651.dvf.h"

extern unsigned int __ghs_rramstart;
extern unsigned int __ghs_rramend;

/* reserved
extern unsigned int __ghs_ramstart;
extern unsigned int __ghs_ramend;

extern unsigned int __ghs_gramastart;
extern unsigned int __ghs_gramaend;
*/

extern unsigned int __ghs_grambstart;
extern unsigned int __ghs_grambend;

/************************************************************************************************************
Macro definitions
************************************************************************************************************/
#define protected_write(preg,pstatus,reg,value)             \
do                                                          \
{                                                           \
    (preg) = 0xa5u;                                         \
    (reg) = (value);                                        \
    (reg) = ~(value);                                       \
    (reg) = (value);                                        \
} while ((pstatus) == 1u)

#define CLKCTLMOSCS_MOSCCLKACT          (0x04u)
#define CLKCTLMOSCC_24MHZ               (0x04)
#define CLKCTLMOSCST_SOSCCLKST          (0x00003E80)
#define CLKCTLPLL0S_PLL0CLKACT          (0x04u)

#define R_RESF_PowerUp        (((uint32)1u) << 9)

void Preinitialize_CLKC_PLLInit(void)
{
      /* Prepare 24MHz MainOsc */
    if((CLKCTLMOSCS&CLKCTLMOSCS_MOSCCLKACT) != CLKCTLMOSCS_MOSCCLKACT)       /* Check if MainOsc needs to be started */
    {
        CLKCTLMOSCC=CLKCTLMOSCC_24MHZ;                                       /* Set MainOSC gain for 24MHz */
        CLKCTLMOSCST=CLKCTLMOSCST_SOSCCLKST;                                 /* Set MainOSC stabilization time to 2ms */
        protected_write(WPROTRPROTCMD0,WPROTRPROTS0,CLKCTLMOSCE,0x01u);      /* Trigger Enable (protected write) */
        while ((CLKCTLMOSCS&CLKCTLMOSCS_MOSCCLKACT) != CLKCTLMOSCS_MOSCCLKACT);  /* Wait for active MainOSC */
    }

    if((CLKCTLPLL0S&CLKCTLPLL0S_PLL0CLKACT) != CLKCTLPLL0S_PLL0CLKACT)       /* Check if PLL needs to be started */
    {
        /* Prepare PLL0 */
        CLKCTLPLL0C = 0x63404827;				                            /* 24 MHz MainOSC -> 480MHz VCOUT (reference:0x6340483B;) */
                                                                            /* 5% @ 100kHz SSCG */
                                                                            
        protected_write(WPROTRPROTCMD0,WPROTRPROTS0,CLKCTLPLL0ST,0x1B80u);   /* Set stabilization time to recommended value */
        protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLPLL0E,0x01u);     /* Enable PLL */
        while((CLKCTLPLL0S&CLKCTLPLL0S_PLL0CLKACT) != CLKCTLPLL0S_PLL0CLKACT){}    /* Wait for active PLL */
    }

    /* CPLLOUT = VCOOUT � 1/2 = 240 MHz */
    protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKD_CTL,0x29u);
    while(CLKCTLCKSC_CPUCLKD_ACT!=0x29);  

    /* CPLLOUT -> CPU Clock */ 
    protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKS_CTL,0x00u);
    while(CLKCTLCKSC_CPUCLKS_ACT!=0x00u);


}

/*****************************************************************************
** Function:    R_SYSTEM_ClearRetentionRAM
** Description: Clears Retention RAM area (GHS version)
** Parameter:   None
** Return:      None
******************************************************************************/
void R_SYSTEM_ClearGlobalBRAM(void)
{  
	uint32* loc_ptr;

/* reserved
//	loc_ptr = (uint32*)&__ghs_ramstart;
//	while(((uint32*)&__ghs_ramend ) > loc_ptr)
//	{
//		*loc_ptr=0x00000000;
//		loc_ptr++;
//	}
	
//   	loc_ptr = (uint32*)&__ghs_gramastart;
//	while(((uint32*)&__ghs_gramaend ) > loc_ptr)
//	{
//		*loc_ptr=0x00000000;
//		loc_ptr++;
//	}
*/
	loc_ptr = (uint32*)&__ghs_grambstart;
	while(((uint32*)&__ghs_grambend ) > loc_ptr)
	{
		*loc_ptr=0x00000000;
		loc_ptr++;
	}
}

/*****************************************************************************
** Function:    R_SYSTEM_GetResetCause
** Description: Returns reset cause
** Parameter:   None
** Return:      Contens of reset cause register (RESF)
******************************************************************************/
uint32 R_SYSTEM_GetResetCause(void)
{
    return (uint32)RESCTLRESF;
}

/*****************************************************************************
** Function:    R_SYSTEM_ClearRetentionRAM
** Description: Clears Retention RAM area (GHS version)
** Parameter:   None
** Return:      None
******************************************************************************/
void R_SYSTEM_ClearRetentionRAM(void)
{  
	uint32* loc_ptr;
  
	loc_ptr = (uint32*)&__ghs_rramstart;
	while(((uint32*)&__ghs_rramend ) > loc_ptr)
	{
		*loc_ptr=0x00000000;
		loc_ptr++;
	}
}

/*****************************************************************************
** Function:    __low_level_init
** Description: called during start-up (GHS version)
** Parameter:   None
** Return:      None
******************************************************************************/
void __lowinit(void)
{
	/* check if power-up reset has occured */
	if(R_SYSTEM_GetResetCause()&R_RESF_PowerUp)
	{
	 	/* clear noinit area of retention RAM */
	 	R_SYSTEM_ClearRetentionRAM();
	}
}


