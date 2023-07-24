/*============================================================================*/
/* Project      = AUTOSAR Renesas F1x MCAL Components                         */
/* Module       = Mcu_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of MCU  */
/* Driver                                                                     */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        F1x                                           */
/*============================================================================*/

/* Implements: EAAR_PN0034_NR_0045                                            */
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*                                                                             *
* V1.0.0: 07-Sep-2015 : Initial Version                                        *
* V1.0.1: 18-Dec-2015 : MISRA justification has been added for Msg(4:0828).    *
*                         Also start and end for the same Msg has been added.  *
* V2.0.0: 14-Oct-2016 : ARDAABD-473 - AUTOSAR 3.2.2 is not supported anymore   *
*                         - MCU_AR_HIGHER_VERSION is changed to 4.2.2          *
*                         - MCU_AR_LOWER_VERSION is changed to 4.0.3           *
*                         - Removed code related to AUTOSAR 3.2.2              *
*                       ARDAABD-838 - All boolean variables are grouped under  *
*                         one START/STOP memory section.                       *
* V2.0.1: 28-Oct-2016 : ARDAABD-473 - History numbering changed according to   *
*                         projects requirements                                *
* V2.1.0: 01-Nov-2016 : ARDAABD-569 - Variables used as Ram Mirror for         *
*                        Hardware ConsistencyCheck added                       *
* V2.2.0: 11-Nov-2016 : ARDAABD-569 - New element inserted for Ram Mirror of   *
*                        the register(SOSCST)                                  *
* V2.3.0: 18-Nov-2016 : ARDAABD-569 - Mcu_HWConsistencyCheckType type inserted *
* V2.4.0: 29-Nov-2016 : ARDAABD-569 - Add include for Mcu_Ram.h                *
* V2.5.0: 31-Jan-2017 : ARDAABD-989 - Included macro MCU_MEMMAP_FILE instead   *
*                         Memmap.h file                                        *
* V2.6.0: 08-Feb-2017 : ARDAABD-569 - Changed the values of compiler switch    *
*                         MCU_RAM_MIRROR to MCU_MIRROR_ENABLE and              *
*                         MCU_MIRROR_DISABLE                                   *
*                       ARDAABD-569 - Include of Mcu_RegWrite.h added for the  *
*                         MCU_RAM_MIRROR values                                *
* V2.7.0: 16-Jun-2017 : ARDAABD-1949 - Attributes ulPLL0C and ulCKSC_PLL0IS_CTL*
*                         added in Mcu_ClkCntlRegMirror                        *
* V2.8.0: 22-Jun-2017 : ARDAABD-1960 Added RAM mirror support for              *
*                         wake up factor 1                                     *
* V2.9.0: 05-Jul-2017 : ARDAABD-1959 Added RAM mirror support for              *
*                         CLMA3 parameters                                     *
* V2.10.0:29-Aug-2017 : ARDAABD-2150 -Added QAC/MISRA Warnings justification.  *
*                        Corrected QAC/MISRA Warning.                          *
* V2.11.0:19-Sep-2017 : ARDAABD-2346 Rename global variables                   *
* V2.12.0:25-Sep-2017 : ARDAABD-2346 Mcu_WufReg10RamMirror changed to          *
*                        Mcu_GddWufReg10RamMirror                              *
* V2.13.0:01-Oct-2017 : ARDAABD-1359 Mcu_GddFeintRegRamMirror removed          *
*                       ARDAABD-1612 Attribute ulROSCS added in                *
*                        Stag_Mcu_ClkCntlRegMirror structure.                  *
* V2.13.1:20-Jun-2018 : Following changes are done as part of merging          *
*                       activities ARDAABD-3490, Following changes are done:   *
*                       1.As part of #ARDAABD-908:                             *
*                       a. Changed memory section name from                    *
*                          MCU_<START/STOP>_SEC_VAR_NO_INIT_UNSPECIFIED to     *
*                          MCU_<START/STOP>_SEC_VAR_NO_INIT_UNSPECIFIED.       *
*                       b. Mapped variable under MCU_STOP_SEC_VAR_BOOLEAN      *
*                          to MCU_STOP_SEC_VAR_INIT_BOOLEAN.                   *
*                       2.As part of #ARDAABD-1293, Added Mcu_GblPllActCheck.  *
*                       3.As part of #ARDAABD-3850, traceability               *
*                        inconsistencies are corrected and requirement         *
*                        mapping is done.                                     */
/******************************************************************************/
#ifndef MCU_RAM_H
#define MCU_RAM_H

#include "Mcu_PBTypes.h"
#include "Mcu_RegWrite.h"

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR specification version information */

#define MCU_RAM_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_AR_RELEASE_REVISION_VERSION    \
                                               MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_RAM_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_RAM_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION

/*******************************************************************************
**                       MISRA C Rule Violations                              **
*******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* 1.  QAC Warning:                                                           */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Rule          : No MISRA-C:2004 Rule                                       */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for QAC Warning START Msg(2:0832)-1 and               */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
 ** Structures for RAM mirror                                                 **
 ******************************************************************************/
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)

/* Type of Hardware Consistency check */
typedef enum ETag_Mcu_HWConsistencyCheckType
{
  MCU_HW_CONSIST_CHECK_STATIC,
  MCU_HW_CONSIST_CHECK_DYNAMIC
} Mcu_HWConsistencyCheckType;

typedef struct STag_Mcu_LVIRegMirror
{
  unsigned long ulLVICNT;                               /* LVICNT           */
}Mcu_LVIRegMirror;

typedef struct STag_RESFRegMirror
{
  unsigned long ulCYCRBASE;                             /* CYCRBASE         */
}Mcu_RESFRegMirror;

typedef struct STag_Mcu_LPSRegMirror
{
  unsigned long ulSCTLR;                                /* SCTLR            */
  unsigned long ulEVFR;                                 /* EVFR             */
  unsigned long ulDPSELR0;                              /* DPSELR0          */
  unsigned long ulDPSELRM;                              /* DPSELRM          */
  unsigned long ulDPSELRH;                              /* DPSELRH          */
  unsigned long ulDPDSR0;                               /* DPDSR0           */
  unsigned long ulDPDSRM;                               /* DPDSRM           */
  unsigned long ulDPDSRH;                               /* DPDSRH           */
  unsigned short usCNTVAL;                              /* CNTVAL           */
}Mcu_LPSRegMirror;

typedef struct STag_Mcu_ClkMntrReg0Mirror
  {
  unsigned char  ucCTL0;                                /* CTL0             */
  unsigned short ulCMPL;                                /* CMPL             */
  unsigned short ulCMPH;                                /* CMPH             */
}Mcu_ClkMntrReg0Mirror;

typedef struct STag_Mcu_ClkMntrReg1Mirror
{
  unsigned char  ucCTL0;                                /* CTL0             */
  unsigned short ulCMPL;                                /* CMPL             */
  unsigned short ulCMPH;                                /* CMPH             */
}Mcu_ClkMntrReg1Mirror;

typedef struct STag_Mcu_ClkMntrReg2Mirror
{
  unsigned char  ucCTL0;                                /* CTL0             */
  unsigned short ulCMPL;                                /* CMPL             */
  unsigned short ulCMPH;                                /* CMPH             */
}Mcu_ClkMntrReg2Mirror;

typedef struct STag_Mcu_ClkMntrReg3Mirror
{
  unsigned char  ucCTL0;                                /* CTL0             */
  unsigned short ulCMPL;                                /* CMPL             */
  unsigned short ulCMPH;                                /* CMPH             */
}Mcu_ClkMntrReg3Mirror;

typedef struct STag_Mcu_TAUJOsRegMirror
{
  unsigned short usTPS;                                 /* TPS              */
  unsigned char ucBRS;                                  /* BRS              */
}Mcu_TAUJOsRegMirror;

typedef struct STag_TAUJChRegMirror
{
  unsigned long ulCDR;                                  /* CDR              */
  unsigned short usCMOR;                                /* CMOR             */
}Mcu_TAUJChRegMirror;

typedef struct Stag_Mcu_ClkCntlRegMirror
{
  unsigned long ulROSCS;                                /* ROSCS            */
  unsigned long ulROSCSTPM;                             /* ROSCSTPM         */
  unsigned long ulMOSCE;                                /* MOSCE            */
  unsigned long ulMOSCC;                                /* MOSCC            */
  unsigned long ulMOSCST;                               /* MOSCST           */
  unsigned long ulMOSCSTPM;                             /* MOSCSTPM         */
  unsigned long ulSOSCE;                                /* SOSCE            */
  unsigned long ulSOSCST;                               /* SOSCST           */
  unsigned long ulCKSC_AWDTAD_CTL;                      /* CKSC_AWDTAD_CTL  */
  unsigned long ulCKSC_AWDTAD_STPM;                     /* CKSC_AWDTAD_STPM */
  unsigned long ulCKSC_ATAUJS_CTL;                      /* CKSC_ATAUJS_CTL  */
  unsigned long ulCKSC_ATAUJD_CTL;                      /* CKSC_ATAUJD_CTL  */
  unsigned long ulCKSC_ATAUJD_STPM;                     /* CKSC_ATAUJD_STPM */
  unsigned long ulCKSC_ARTCAS_CTL;                      /* CKSC_ARTCAS_CTL  */
  unsigned long ulCKSC_ARTCAD_CTL;                      /* CKSC_ARTCAD_CTL  */
  unsigned long ulCKSC_ARTCAD_STPM;                     /* CKSC_ARTCAD_STPM */
  unsigned long ulCKSC_AADCAS_CTL;                      /* CKSC_AADCAS_CTL  */
  unsigned long ulCKSC_AADCAD_CTL;                      /* CKSC_AADCAD_CTL  */
  unsigned long ulCKSC_AADCAD_STPM;                     /* CKSC_AADCAD_STPM */
  unsigned long ulCKSC_AFOUTS_CTL;                      /* CKSC_AFOUTS_CTL  */
  unsigned long ulCKSC_AFOUTS_STPM;                     /* CKSC_AFOUTS_STPM */
  unsigned long ulFOUTDIV;                              /* FOUTDIV          */
  unsigned long ulPLLE;                                 /* PLLE             */
  unsigned long ulPLLC;                                 /* PLLC             */
  unsigned long ulPLL0C;                                /* PLL0C            */
  unsigned long ulCKSC_CPUCLKS_CTL;                     /* CKSC_CPUCLKS_CTL */
  unsigned long ulCKSC_PPLLCLKS_CTL;                    /* CKSC_PPLLCLKS_CTL*/
  unsigned long ulCKSC_CPUCLKD_CTL;                     /* CKSC_CPUCLKD_CTL */
  unsigned long ulCKSC_IPERI1S_CTL;                     /* CKSC_IPERI1S_CTL */
  unsigned long ulCKSC_IPERI2S_CTL;                     /* CKSC_IPERI2S_CTL */
  unsigned long ulCKSC_ILINS_CTL;                       /* CKSC_ILINS_CTL   */
  unsigned long ulCKSC_IADCAS_CTL;                      /* CKSC_IADCAS_CTL  */
  unsigned long ulCKSC_IADCAD_CTL;                      /* CKSC_IADCAD_CTL  */
  unsigned long ulCKSC_PLL0IS_CTL;                      /* CKSC_PLL0IS_CTL  */
  unsigned long ulCKSC_PLLIS_CTL;                       /* CKSC_PLLIS_CTL   */
  unsigned long ulCKSC_ILIND_CTL;                       /* CKSC_ILIND_CTL   */
  unsigned long ulCKSC_ILIND_STPM;                      /* CKSC_ILIND_STPM  */
  unsigned long ulCKSC_ICANS_CTL;                       /* CKSC_ICANS_CTL   */
  unsigned long ulCKSC_ICANS_STPM;                      /* CKSC_ICANS_STPM  */
  unsigned long ulCKSC_ICANOSCD_CTL;                    /* CKSC_ICANOSCD_CTL*/
  unsigned long ulCKSC_ICANOSCD_STPM;                   /* CKSC_ICANOSCD_STPM*/
  unsigned long ulCKSC_ICSIS_CTL;                       /* CKSC_ICSIS_CTL   */
  unsigned long ulCKSC_IIICS_CTL;                       /* CKSC_IIICS_CTL   */
}Mcu_ClkCntlRegMirror;

typedef struct STag_Mcu_WUFReg0Mirror
{
  unsigned long ulWUFMSK0;                              /* WUFMSK0          */
}Mcu_WUFReg0Mirror;

typedef struct STag_Mcu_WUFReg20Mirror
{
  unsigned long ulWUFMSK0;                              /* WUFMSK0          */
}Mcu_WUFReg20Mirror;

typedef struct STag_Mcu_WUFRegISOMirror
{
  unsigned long ulWUFMSK0;                              /* WUFMSK0          */
}Mcu_WUFRegISOMirror;

#if (MCU_WUF1_ENABLED == STD_ON)
typedef struct STag_Mcu_WUFReg10Mirror
{
  unsigned long ulWUFMSK0;                              /* WUFMSK0          */
}Mcu_WUFReg10Mirror;
#endif
#endif /* (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE) */

/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                             Mcu_GpClockSetting;

/* Global pointer variable for MCU CKSC clock Setting configuration */
extern P2CONST(Mcu_CkscSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                             Mcu_GpCkscSetting;

#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
extern P2CONST(Mcu_SequencerSetting, MCU_VAR, MCU_CONFIG_CONST)
                                                      Mcu_GpSeqSetting;
#endif /* (MCU_LOW_POWER_SEQUENCER == STD_ON) */

/* Ram Mirror variables used for HWCC */
#if (MCU_RAM_MIRROR == MCU_MIRROR_ENABLE)
extern VAR(Mcu_LVIRegMirror, MCU_NOINIT_DATA)Mcu_GddLviRegRamMirror;
extern VAR(Mcu_RESFRegMirror, MCU_NOINIT_DATA)Mcu_GddResfRegRamMirror;
extern VAR(Mcu_LPSRegMirror, MCU_NOINIT_DATA)Mcu_GddLpsRegRamMirror;
extern VAR(Mcu_ClkMntrReg0Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg0RamMirror;
extern VAR(Mcu_ClkMntrReg1Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg1RamMirror;
extern VAR(Mcu_ClkMntrReg2Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg2RamMirror;
extern VAR(Mcu_ClkMntrReg3Mirror, MCU_NOINIT_DATA)Mcu_GddClkMntrReg3RamMirror;
extern VAR(Mcu_TAUJOsRegMirror, MCU_NOINIT_DATA)Mcu_GddTaujOsRegRamMirror;
extern VAR(Mcu_TAUJChRegMirror, MCU_NOINIT_DATA)Mcu_GddTaujChRegRamMirror;
extern VAR(Mcu_ClkCntlRegMirror, MCU_NOINIT_DATA)Mcu_GddClkCntlRegRamMirror;
extern VAR(Mcu_WUFReg0Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg0RamMirror;
extern VAR(Mcu_WUFReg20Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg20RamMirror;
extern VAR(Mcu_WUFRegISOMirror, MCU_NOINIT_DATA)Mcu_GddWufRegIsoRamMirror;
#if (MCU_WUF1_ENABLED == STD_ON)
extern VAR(Mcu_WUFReg10Mirror, MCU_NOINIT_DATA)Mcu_GddWufReg10RamMirror;
#endif
#endif
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus;
/* Global variable to check WakeUp status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblWakeUpPreparation;
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

extern VAR(boolean, MCU_INIT_DATA) Mcu_GblResetFlag;

/* Global variable to store PLL ACT check status */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblPllActCheck;
#if (MCU_LOW_POWER_SEQUENCER == STD_ON)
#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblSeqDriverStatus;
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
#endif /* MCU_LOW_POWER_SEQUENCER == STD_ON */
/* QAC Warning: START Msg(2:0832)-1 */
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include MCU_MEMMAP_FILE
/* END Msg(2:0832)-1 */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
