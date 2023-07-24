/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Spi_CSIX_LLDriver.c                                         */
/* Version      = V1.0.0                                                      */
/* Date         = 12-Nov-2019                                                 */
/*============================================================================*/
/*                               COPYRIGHT                                    */
/*============================================================================*/
/* Copyright(c) 2019 Renesas Electronics Corporation. All rights reserved.    */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Low level driver function definitions of the SPI        */
/* Driver                                                                     */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  12-Mar-2019  : Initial Version
 *          24-Oct-2019  : The following changes are made:
 *                         1. As per ARDAACH-81 and ARDAACH-98, use
 *                         Spi_CSIXMaskHWUnitInterrupts to mask and clear
 *                         all related interrupts in Spi_CSIXForceStop.
 *                         2. As per ARDAACH-94, use Spi_CSIXTurnOffUnit to
 *                         clear CTL0 in Spi_CSIXInit and Spi_CSIXDeInit;
 *                         add clear PWR after writing CSIHnTXE and CSIHnRXE in
 *                         in Spi_CSIXLoopBackSelfTest(); change the condition
 *                         for macro dummy read in Spi_CSIXTurnOffUnit().
 *                         3. As per ARDAACH-86, move setting STCR0 after
 *                         Spi_CSIHInitRegs.
 *                         4. As per ARDAACH-87, add default setting for
 *                         CSIHnCFGx and CSIGnCFG0 in Spi_CSIXInit when
 *                         persistent configuration is disabled.
 *                         5. As per ARDAACH-87, move setting of CSIGnCFG0 in
 *                         Spi_CSIXInitializeForJob to set it once for a CSIGn
 *                         in Spi_CSIXInit.
 *                         6. As per ARDAACH-97, the sequence of Tx reg writting
 *                         and "usRemainedTxCount" decliment is reversed in
 *                         Spi_CSIXStartChannelDirectAccessMode to remove
 *                         un-neccesary critical sections.
 *                         7. As per ARDAACH-88, use new macro to clear TCC
 *                         in Spi_CSIXDMACompleteISR.
 *                         8. As per ARDAACH-98, remove the function,
 *                         Spi_CSIXMaskMultipleHWUnitInterrupts.
 *                         9. As per ARDAACH-96, change PSR mask to verify
 *                         target pin only in Spi_HWControlCS.
 *                         10. As per ARDAACH-89, add wrapper macros for
 *                         internal vars in Spi_CheckAndStoreErrorInfo and
 *                         Spi_CSIXRegsConsistencyCheck.
 *                         11. As per ARDAACH-85, set MCTL0 in Spi_CSIHInitRegs
 *                         after self-test is performed.
 *                         12. As per ARDAACH-95, add verify-write for MCTL2 in
 *                         Spi_CSIHInitRegs and Spi_CSIXReceiveISR().
 *                         13. As per ARDAACH-84, correc macro to perfom dummy
 *                         read in Spi_CSIXTurnOffUnit().
 *          12-Nov-2019  : The following changes are made:
 *                         1. As per static test result, remove un-used
 *                         parameter-in of Spi_ProcessSequence;
 *                         remove un-neccesary casting in
 *                         Spi_CSIXStartChannelFifoMode and
 *                         Spi_CSIXReceiveChannelFifoMode.
 *                         2. As per review of ARDAACH-87, add default setting
 *                         for CSIXnCLT2 in Spi_CSIXInit and move setting of
 *                         CSIHnBRSx in Spi_CSIHInitRegs when persistent
 *                         configuration is disabled.
 *                         3. As per ARDAACH-149, move status bits clear from
 *                         Spi_CSIXInitializeForJob to Spi_CSIXProcessJob and
 *                         after all registers setting in  Spi_CSIXInit.
 *                         4. As per ARDAACH-144, CSIX interrupts disable
 *                         is enclosed in (SPI_LOOPBACK_SELFTEST == SPI_ZERO).
 *                         5. As per ARDAACH-140, add ECC code (7 bits) walk-1
 *                         test in Spi_EccWalkOneTest.
 *                         6. As per ARDAACH-154, clear pending interrupts added
 *                         in Spi_CSIXLoopbackSelfTest.
 *                         7. As per ARDAACH-155, correct used write verify
 *                         macros used in Spi_CSIXTurnOnUnit, Spi_CSIXProcessJob
 *                         and Spi_CSIXReceiveISR.
 *                         8. As per ARDAACH-156, add parity error verification
 *                         in Spi_CSIXLoopbackSelfTest.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dem.h"
#include "rh850_Types.h"
#include "Spi.h"
#include "Spi_Ram.h"
#include "Spi_Scheduler.h"
#include "Spi_CSIX_LLDriver.h"
#include "Spi_Irq.h"
#include "Spi_RegWrite.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define SPI_CSIX_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION \
                               SPI_AR_RELEASE_MAJOR_VERSION_VALUE
#define SPI_CSIX_LLDRIVER_C_AR_RELEASE_MINOR_VERSION \
                               SPI_AR_RELEASE_MINOR_VERSION_VALUE
#define SPI_CSIX_LLDRIVER_C_AR_RELEASE_REVISION_VERSION \
                               SPI_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define SPI_CSIX_LLDRIVER_C_SW_MAJOR_VERSION    SPI_SW_MAJOR_VERSION_VALUE
#define SPI_CSIX_LLDRIVER_C_SW_MINOR_VERSION    SPI_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (SPI_CSIX_LLDRIVER_AR_RELEASE_MAJOR_VERSION != \
                               SPI_CSIX_LLDRIVER_C_AR_RELEASE_MAJOR_VERSION)
#error "Spi_CSIX_LLDriver.c : Mismatch in Release Major Version"
#endif

#if (SPI_CSIX_LLDRIVER_AR_RELEASE_MINOR_VERSION != \
                               SPI_CSIX_LLDRIVER_C_AR_RELEASE_MINOR_VERSION)
#error "Spi_CSIX_LLDriver.c : Mismatch in Release Minor Version"
#endif

#if (SPI_CSIX_LLDRIVER_AR_RELEASE_REVISION_VERSION != \
                               SPI_CSIX_LLDRIVER_C_AR_RELEASE_REVISION_VERSION)
#error "Spi_CSIX_LLDriver.c : Mismatch in Release Revision Version"
#endif

#if (SPI_CSIX_LLDRIVER_SW_MAJOR_VERSION != SPI_CSIX_LLDRIVER_C_SW_MAJOR_VERSION)
#error "Spi_CSIX_LLDriver.c : Mismatch in Software Major Version"
#endif

#if (SPI_CSIX_LLDRIVER_SW_MINOR_VERSION != SPI_CSIX_LLDRIVER_C_SW_MINOR_VERSION)
#error "Spi_CSIX_LLDriver.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : This is necessary to support multiple configuration.       */
/*                 The actuall array can't be decided statically.             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-1 and                           */
/*                 END Msg(4:0491)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : To reduce RAM consumption of a variable which contains     */
/*                 index value.                                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-2 and                           */
/*                 END Msg(4:0488)-2 tags in the code.                        */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0310) Casting to different object pointer type.         */
/*                                                                            */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : 1. This is necessary to support AUTOSAR SWS.               */
/*                 Pointer must be converted according to actual data size.   */
/*                 2. EIC register allows both 16 bit and 8 bit accesses.     */
/*                 8 bit access is necessary to modify only EIMK bit.         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0310)-3 and                           */
/*                 END Msg(4:0310)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION::                                                */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done for pointer array storing data address.*/
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-4 and                           */
/*                 END Msg(4:0303)-4 tags in the code.                        */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:1055) [C99] The keyword 'inline' has been used.         */
/*                 result is always that of the left-hand operand.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : It is used to achieve better throughput instead of         */
/*                 invoking a function call.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1055)-5 and                           */
/*                 END Msg(4:1055)-5 tags in the code.                        */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Macro defines an unrecognised code-fragment.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Macro definition as multi-line operation hence multi-line  */
/*                 macro is used                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-6 and                           */
/*                 END Msg(4:3412)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Justification : Function used for write-verify will impact a lot to time   */
/*                 execution. Using macros is better in point of performance. */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/*                 const value, or macro is better in point of performance.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-7 and                           */
/*                 END Msg(4:3453)-7 tags in the code.                        */
/******************************************************************************/

/******************************************************************************/
/**                      QAC Warning                                         **/
/******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0314) Cast from a pointer to object type to a pointer   */
/*                 to void.                                                   */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0314           */
/* Justification : Is is necessary to accept variable types by DMA driver.    */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:0314)-1 and                           */
/*                 END Msg(2:0314)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (3:3305) Pointer cast to stricter alignment.               */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3305           */
/* Justification : This is necessary to comply AUTOSAR specification.         */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(3:3305)-2 and                           */
/*                 END Msg(3:3305)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3441) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3441           */
/* Justification : According to the coding guide, all global variables must   */
/*                 be declared with volatile keyword. Since these are normal  */
/*                 memory objects, there is no side effect.                   */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3441)-3 and                           */
/*                 END Msg(2:3441)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:0832) Function call argument is an expression with      */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 0832           */
/* Justification : The name of an include file has been specified using a     */
/*                 macro. This is not recommended in some coding standards.   */
/* Verification  : This is quite legitimate in C. It is necessary for macro   */
/*                 substitution and it is not having any impact.              */
/* Reference     : Look for START Msg(2:0832)-4 and                           */
/*                 END Msg(2:0832)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:2016) This 'switch' statement 'default' clause is empty */
/* Rule          : No MISRA-C:2004 Rules applicable to message 2016           */
/* Justification : This default is necessary to comply the coding guide but   */
/*                 it is guaranteed that it is never executed by the design.  */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:2016)-5 and                           */
/*                 END Msg(2:2016)-5 tags in the code.                        */
/******************************************************************************/

/* 6. QAC Warning:                                                            */
/* Message       : (2:3206) The parameter is not used in this function.       */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3206           */
/* Justification : This is done as per implementation requirement             */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3206)-6 and                           */
/*                 END Msg(2:3206)-6 tags in the code.                        */
/******************************************************************************/

/* 7. QAC Warning:                                                            */
/* Message       : (2:3204) The variable '%s' is only set once and so it      */
/*                  could be declared with the 'const' qualifier.             */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3204           */
/* Justification : The variable '%s' is only set once to make source clearly  */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3204)-7 and                           */
/*                 END Msg(2:3204)-7 tags in the code.                        */
/******************************************************************************/

/* 8. QAC Warning:                                                            */
/* Message       : (2:3227) The variable '%s' is only set once and so it      */
/*                  could be declared with the 'const' qualifier.             */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3227           */
/* Justification : The variable '%s' is only set once to make source clearly  */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3227)-8 and                           */
/*                 END Msg(2:3227)-8 tags in the code.                        */
/******************************************************************************/

/* 9. QAC Warning:                                                            */
/* Message       : (2:2743) This 'do - while' loop controlling expression is  */
/*                 a constant expression and its value is 'false'. The loop   */
/*                 will only be executed once.                                */
/* Rule          : No MISRA-C:2004 Rules applicable to message 2743           */
/* Justification : This 'do - while' loop is used to those command run only   */
/*                 one time.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2743)-9 and                           */
/*                 END Msg(2:2743)-9 tags in the code.                        */
/******************************************************************************/

/* 10. QAC Warning:                                                           */
/* Message       : (2:3416) Logical operation performed on expression with    */
/*                 possible side effects.                                     */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3416           */
/* Justification : According to the coding guide, all global variables must   */
/*                 be declared with volatile keyword. Since these are normal  */
/*                 memory objects, there is no side effect.                   */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(2:3416)-10 and                          */
/*                 END Msg(2:3416)-10 tags in the code.                       */
/******************************************************************************/

/* 11. QAC Warning:                                                           */
/* Message       : (3:3352) This 'switch' statement contains only two         */
/*                 execution paths.                                           */
/* Rule          : No MISRA-C:2004 Rules applicable to message 3352           */
/* Justification : When using different configurations, "case" branches       */
/*                 (through Compiler switch) may no longer be present.        */
/* Verification  : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/* Reference     : Look for START Msg(3:3352)-11 and                          */
/*                 END Msg(3:3352)-11 tags in the code.                       */
/******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#define SPI_START_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */
/*******************************************************************************
**                      Inline Function Definitions                           **
*******************************************************************************/

#if (SPI_CSIX_WRITE_VERIFY != SPI_WV_DISABLE)
/*******************************************************************************
** Function Name         : Spi_CSIXVerifyWriteInitRTReg32
**
** Description           : This function is to do the comparison check for CSIX
**                         32-bit registers accessed in both Spi_Init/Spi_DeInit
**                         and the other run-time APIs.
**
** Input Parameters      : LpWriteRegAddr, LulRegWriteValue, LulMaskValue,
**                         LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : SPI_VERIFY_WRITE_REG
*******************************************************************************/
/* MISRA Violation: START Msg(4:1055)-5 */
/* QAC Warning: START Msg(2:3206)-6 */
static INLINE FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXVerifyWriteInitRTReg32(
  volatile CONSTP2CONST(uint32, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint32, AUTOMATIC) LulRegWriteValue,
  CONST(uint32, AUTOMATIC) LulMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* END Msg(4:1055)-5 */
  /* References: SPI_DDD_ACT_099 */
{
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  if ((SPI_INIT_SID == LucApiId) || (SPI_DEINIT_SID == LucApiId))
#endif
  {
    SPI_VERIFY_WRITE_REG(
      LpWriteRegAddr, LulRegWriteValue,
      LulMaskValue, LucApiId)
  }
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  else
  {
    /* Do nothing */
  }
#endif /* SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY) */
}

/*******************************************************************************
** Function Name         : Spi_CSIXVerifyWriteInitRTReg16
**
** Description           : This function is to do the comparison check for CSIX
**                         16-bit registers accessed in both Spi_Init/Spi_DeInit
**                         and the other run-time APIs.
**
** Input Parameters      : LpWriteRegAddr, LusRegWriteValue, LusMaskValue,
**                         LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : SPI_VERIFY_WRITE_REG
*******************************************************************************/
/* MISRA Violation: START Msg(4:1055)-5 */
/* QAC Warning: START Msg(2:3206)-6 */
static INLINE FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXVerifyWriteInitRTReg16(
  volatile CONSTP2CONST( uint16, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint16, AUTOMATIC) LusRegWriteValue,
  CONST(uint16, AUTOMATIC) LusMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* END Msg(4:1055)-5 */
  /* References: SPI_DDD_ACT_100 */
{
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  if ((SPI_INIT_SID == LucApiId) || (SPI_DEINIT_SID == LucApiId))
#endif
  {
    SPI_VERIFY_WRITE_REG(
      LpWriteRegAddr, LusRegWriteValue,
      LusMaskValue, LucApiId)
  }
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  else
  {
    /* Do nothing */
  }
#endif /* SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY) */
}

/*******************************************************************************
** Function Name         : Spi_CSIXVerifyWriteInitRTReg8
**
** Description           : This function is to do the comparison check for CSIX
**                         8-bit registers accessed in both Spi_Init/Spi_DeInit
**                         and the other run-time APIs.
**
** Input Parameters      : LpWriteRegAddr, LucRegWriteValue, LucMaskValue,
**                         LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : SPI_VERIFY_WRITE_REG
*******************************************************************************/
/* MISRA Violation: START Msg(4:1055)-5 */
/* QAC Warning: START Msg(2:3206)-6 */
static INLINE FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXVerifyWriteInitRTReg8(
  volatile CONSTP2CONST(uint8, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint8, AUTOMATIC) LucRegWriteValue,
  CONST(uint8, AUTOMATIC) LucMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* END Msg(4:1055)-5 */
  /* References: SPI_DDD_ACT_101 */
{
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  if ((SPI_INIT_SID == LucApiId) || (SPI_DEINIT_SID == LucApiId))
#endif
  {
    SPI_VERIFY_WRITE_REG(
      LpWriteRegAddr, LucRegWriteValue,
      LucMaskValue, LucApiId)
  }
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
  else
  {
    /* Do nothing */
  }
#endif /* SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY) */
}

#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_RUNTIME)
/*******************************************************************************
** Function Name         : Spi_CSIXVerifyWriteReg32
**
** Description           : This function is to do the comparison check for CSIX
**                         32-bit registers accessed in either Spi_Init/
**                         Spi_DeInit or the other run-time APIs only.
**
** Input Parameters      : LpWriteRegAddr, LulRegWriteValue, LulMaskValue,
**                         LucApiId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Pre-conditions        : None
**
** Functions invoked     : SPI_VERIFY_WRITE_REG
*******************************************************************************/
/* MISRA Violation: START Msg(4:1055)-5 */
/* QAC Warning: START Msg(2:3206)-6 */
static INLINE FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXVerifyWriteReg32(
  volatile CONSTP2CONST(uint32, AUTOMATIC, REGSPACE) LpWriteRegAddr,
  CONST(uint32, AUTOMATIC) LulRegWriteValue,
  CONST(uint32, AUTOMATIC) LulMaskValue,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* END Msg(4:1055)-5 */
  /* References: SPI_DDD_ACT_102 */
{
  SPI_VERIFY_WRITE_REG(
    LpWriteRegAddr, LulRegWriteValue,
    LulMaskValue, LucApiId)
}
#endif /* End of #if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_RUNTIME) */
#endif /* End of #if (SPI_CSIX_WRITE_VERIFY != SPI_WV_DISABLE) */

/* Code snippet to perform write-verify and verify registers after writing */
#if (SPI_CSIX_WRITE_VERIFY != SPI_WV_DISABLE)

  /* Macro for write-verify and mirror register accessed in an internal
     function which is invoked in both init/de-init and run-time API */
  /* MISRA Violation: START Msg(4:3412)-6 */
  #define SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(\
    pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  Spi_CSIXVerifyWriteInitRTReg##RegSize(\
    pWriteRegAddr, RegWriteValue, MaskValue, ApiId);\
  SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
  /* END Msg(4:3412)-6 */

  /* Macro for checking writing register accessed in an internal function
     which is invoked in both init/de-init and run-time API */
  /* MISRA Violation: START Msg(4:3412)-6 */
  #define SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  Spi_CSIXVerifyWriteInitRTReg##RegSize(\
    pWriteRegAddr, RegWriteValue, MaskValue, ApiId);
  /* END Msg(4:3412)-6 */

  #if (SPI_CSIX_WRITE_VERIFY == SPI_WV_INIT_ONLY)
    /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked only run-time API */
    /* MISRA Violation: START Msg(4:3453)-7 */
    #define SPI_CSIX_WRITE_VERIFY_AND_MIRROR_RUNTIME(\
      pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
    SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
    SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
    /* END Msg(4:3453)-7 */

    /* Macro for checking writing register accessed in an internal function
     which is invoked only run-time API */
    /* MISRA Violation: START Msg(4:3412)-6 */
    #define SPI_CSIX_VERIFY_WRITE_RUNTIME(\
      pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
    {\
    }
    /* END Msg(4:3412)-6 */
  #else
    /* Macro for write-verify and mirror register accessed in an internal
    function which is invoked only run-time API */
    /* MISRA Violation: START Msg(4:3412)-6 */
    #define SPI_CSIX_WRITE_VERIFY_AND_MIRROR_RUNTIME(\
      pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
      SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
      Spi_CSIXVerifyWriteReg##RegSize(\
        pWriteRegAddr, RegWriteValue, MaskValue, ApiId);\
      SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
    /* END Msg(4:3412)-6 */

    /* Macro for checking writing register accessed in an internal function
    which is invoked only run-time API */
    /* MISRA Violation: START Msg(4:3412)-6 */
    #define SPI_CSIX_VERIFY_WRITE_RUNTIME(\
      pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
      Spi_CSIXVerifyWriteReg##RegSize(\
      pWriteRegAddr, RegWriteValue, MaskValue, ApiId);
    /* END Msg(4:3412)-6 */

  #endif
#else
  /* Macro for write-verify and mirror register accessed in an internal function
     which is invoked in both init/de-init and run-time API */
  /* MISRA Violation: START Msg(4:3453)-7 */
  #define SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(\
    pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
  /* END Msg(4:3453)-7 */

  /* Macro for checking writing register accessed in an internal function
     which is invoked in both init/de-init and run-time API */
  /* MISRA Violation: START Msg(4:3412)-6 */
  #define SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  {\
  }
  /* END Msg(4:3412)-6 */

  /* Macro for write-verify and mirror register accessed in an internal
  function which is invoked only run-time API */
  /* MISRA Violation: START Msg(4:3453)-7 */
  #define SPI_CSIX_WRITE_VERIFY_AND_MIRROR_RUNTIME(\
    pWriteRegAddr, RegWriteValue, pMirrorAddr, MaskValue, RegSize, ApiId) \
  SPI_WRITE_REG_ONLY(pWriteRegAddr, RegWriteValue)\
  SPI_CSIX_WRITE_RAM_MIRROR(pMirrorAddr, RegWriteValue)
  /* END Msg(4:3453)-7 */

  /* Macro for checking writing register accessed in an internal function
  which is invoked only run-time API */
  /* MISRA Violation: START Msg(4:3412)-6 */
  #define SPI_CSIX_VERIFY_WRITE_RUNTIME(\
    pWriteRegAddr, RegWriteValue, MaskValue, RegSize, ApiId) \
  {\
  }
  /* END Msg(4:3412)-6 */

#endif


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* Prototypes for functions used in this file only */
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInitializeForJob(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblCFGxOnly,
  CONST(uint8, AUTOMATIC) LucApiId);

#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInitializeForCh(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelDirectAccessMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelDirectAccessMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

#if (SPI_DIRECT_ACCESS_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXWriteTX0Register(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(uint32, AUTOMATIC) LulData);
#endif

#if (SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
static FUNC(uint16, SPI_PRIVATE_CODE) Spi_CSIXReadRX0Register(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

static FUNC(void, SPI_PRIVATE_CODE) Spi_LoadTxData(
  volatile CONSTP2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpData,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpFirstWord,
  volatile CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpSecondWord);

static FUNC(void, SPI_PRIVATE_CODE) Spi_StoreRxData(
  volatile CONSTP2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpData,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint16, AUTOMATIC) LusFirstWord,
  CONST(uint16, AUTOMATIC) LusSecondWord);

#if (SPI_FIFO_MODE == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#if (SPI_DMA_CONFIGURED == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMAStartChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif
#endif

#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON))
static FUNC(void, SPI_FAST_CODE) Spi_HWBufferLoadTxData(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpTxPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) LusNoOfBuffers,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON))
static FUNC(void, SPI_FAST_CODE) Spi_HWBufferStoreRxData(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpRxPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) LusNoOfBuffers,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelHwBuffer(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

#if (SPI_TX_ONLY_MODE == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelTxOnlyMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex);
#endif

#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
static FUNC(void, SPI_FAST_CODE) Spi_HWControlCS(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblActivateCS,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitInterrupts(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblTxMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF);

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitRxInterrupt(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF);

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitTxInterrupt(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF);
#endif

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndStoreErrorInfo(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex,
  CONST(uint16, AUTOMATIC) LusErrorValue);

static FUNC(void, SPI_PRIVATE_CODE) Spi_StoreErrorInfo(
  CONSTP2CONST(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST) LpErrorDetails);
#endif

#if (SPI_CSIX_RAM_MIRROR == STD_ON) && (SPI_CSIH_CONFIGURED == STD_ON)
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIHRegsConsistencyCheck(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig);
#endif

#if (SPI_DMA_CONFIGURED == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMASetUp(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2CONST(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONSTP2CONST(uint32, AUTOMATIC, SPI_APPL_CONST) LpDefaultData,
  CONST(uint16, AUTOMATIC) LusRxCount,
  CONST(uint16, AUTOMATIC) LusTxCount);
#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllZeroTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr);

static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllOneTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr);

static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccWalkOneTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr);

static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccTwoBitTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr);
#endif
#endif

#if (SPI_CSIH_CONFIGURED == STD_ON)
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIHInitRegs(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(Spi_MemoryModeType, AUTOMATIC) LenMemoryMode,
  CONST(uint8, AUTOMATIC) LucApiId);
#endif

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXProcessEndJob(
  CONSTP2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo,
  volatile CONSTP2CONST(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId);

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTurnOnUnit(
  CONST(uint8, AUTOMATIC) LucHWUnitIndex,
  CONST(uint8, AUTOMATIC) LucApiId);

static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTurnOffUnit(
  CONST(uint8, AUTOMATIC) LucHWUnitIndex,
  CONST(uint8, AUTOMATIC) LucApiId);

/*******************************************************************************
** Function Name      : Spi_CSIXInit
**
** Service ID         : Not Applicable
**
** Description        : This function initializes all configured CSIX units.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs,
**                      Spi_GpFirstJob
**
** Function invoked   : Spi_CSIXTurnOffUnit, Spi_CSIXInitializeForJob,
**                      Spi_CSIXDisableAllInterrupts, Spi_CSIHInitRegs
**
** Registers Used     : CSIXnCTL0, CSIXnCTL1, CSIXnSTCR0, CSIGnBCTL0,
**                        CSIXnSTR0
**
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInit(CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_019 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulInitialized;
  VAR(uint8, AUTOMATIC) LucCTL0RegValue;
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) && \
  (SPI_CSIH_CONFIGURED == STD_ON)
  VAR(uint32, AUTOMATIC) LulCSCount;
  VAR(uint32, AUTOMATIC) LulCSIndex;
#endif

  /* Initialize already initialized flags */
  LulInitialized = SPI_ZERO;
  /* Scan all jobs and initialize the associated HWUnits */
  for (LulJobIndex = SPI_ZERO;
    LulJobIndex < Spi_GpConfigPtr->usNoOfJobs; LulJobIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
    /* END Msg(4:0491)-1 */
    LulHWUnitIndex = LpJobConfig->ucHWUnitIndex;
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */
    LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

    /* Avoid initializing same HW twice */
    if ((uint32)SPI_ZERO ==
      (LulInitialized & ((uint32)SPI_ONE << LulHWUnitIndex)))
    {
      /* Set default value to registers */
      /* Step 1. Clear PWR, do dummy read */
      Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

      /* Step 2. Set TXE, RXE, MBS and PWR at same time */
      LucCTL0RegValue = (uint8)(SPI_CSIX_PWR | LpHWInfo->ucCTL0DefaultValue);
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0, LucCTL0RegValue,
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].ucCTL0,
        CTLREG_8_BIT_MASK, 8, LucApiId)
      /* References: SPI_DDD_ACT_019_REG002 */

      /* Step 3. Clear PWR */
      Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

#if (SPI_CSIH_CONFIGURED == STD_ON)
      if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
      {
        /* Initialize CSIH specific registers */
        Spi_CSIHInitRegs(LpJobConfig, LulHWPhyIndex,
          LpHWInfo->enMemoryMode, LucApiId);
      }
      else
      {
        /* Nothing to do */
      }
#endif  /* (SPI_CSIH_CONFIGURED == STD_ON) */

#if (SPI_CSIG_CONFIGURED == STD_ON)
      if (SPI_MACRO_CSIG == LpHWInfo->enMacroType)
      {
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
        /* Re-set default value for CFG0 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0,
          SPI_CSIX_CFG_DEFAULT,
          &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ulCFG0,
          CTLREG_32_BIT_MASK, 32, LucApiId)
        /* References: SPI_DDD_ACT_019_REG007 */
#endif
        /* Set default value for BCTL0 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ucBCTL0,
          SPI_CSIG_BCTL0_DEFAULT,
          &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ucBCTL0,
          CTLREG_8_BIT_MASK, 8, LucApiId)
        /* References: SPI_DDD_ACT_019_REG005 */
      }
      else
      {
        /* Nothing to do */
      }
#endif /* (SPI_CSIG_CONFIGURED == STD_ON) */

#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
      /*
       * If hardware settings never changed during operation,
       * initialize entire the CSIH unit here.
       */
      Spi_CSIXInitializeForJob(LpJobConfig, SPI_FALSE, LucApiId);
#else
      /* Otherwise, initialize CTL1 with the first Job without setting CSRI */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ulCTL1,
        LpJobConfig->ulCSIXCTL1 & (uint32)(~SPI_CSIH_CSRI),
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].ulCTL1,
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* References: SPI_DDD_ACT_019_REG006 */
      /* Reset CLT2 to default, setting of CLT2 will be done when starting
         transmission for each job when persistent config is disabled. */
       SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
         &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
         SPI_CSIX_CTL2_DEFAULT,
         &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
         CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_019_REG009 */
#endif
      /* Clear all status error bits and implement for caution of MCTL0:
       * After a change of the memory mode, the respective buffer pointers
       * must be cleared by setting the CSIHnSTCR0.CSIHnPCT bit to 1. */
      SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
        LpHWInfo->usSTCR0MaskValue)
      /* Check for Write verification */
      SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0, (uint32)SPI_ZERO,
        (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)
      /* References: SPI_DDD_ACT_019_REG004 */
      /* Set flag corresponding to HW unit index to avoid
         initializing same HW twice */
      LulInitialized = LulInitialized | ((uint32)SPI_ONE << LulHWUnitIndex);
    }
    else
    {
    /*
     * To initialize CFGx for each Job,
     * invoke this for each Job even HWUnit is already initialized.
     */
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON)
      /* Initialize CFGx for each Job */
      Spi_CSIXInitializeForJob(LpJobConfig, SPI_TRUE, LucApiId);
#else
#if (SPI_CSIH_CONFIGURED == STD_ON)
    /* Reset CFGx registers for each Job,
     * when persistent configured is disabled, setting CFGx according to
     * job configured will be done inside Spi_Aysntransmit()
     */
    for (LulCSCount = SPI_ZERO; LulCSCount < LpJobConfig->ucNoOfCS;
      LulCSCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      LulCSIndex = LpJobConfig->pCSArray[LulCSCount];
      /* END Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaCFG[LulCSIndex],
        SPI_CSIX_CFG_DEFAULT,
        &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaCFG[LulCSIndex],
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* END Msg(2:3441)-3 */
      /* References: SPI_DDD_ACT_019_REG008 */
    }
#endif /* End of (SPI_CSIH_CONFIGURED == STD_ON) */
#endif /* End of (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_ON) */
    }
  }

#if (SPI_LOOPBACK_SELFTEST == SPI_ZERO)
  /* Disable all interrupts unconditionally.
   * If Loopback self-test were enabled, CSIX interrupts
   * already had been disabled before.
   */
  Spi_CSIXDisableAllInterrupts();
#endif
}

/*******************************************************************************
** Function Name      : Spi_CSIXDeInit
**
** Service ID         : Not Applicable
**
** Description        : This function de-initializes all configured CSIX units.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpConfig, Spi_GpFirstHWUnit, Spi_GpFirstJob,
**                      Spi_GaaCSIXRegs
**
** Function invoked   : Spi_CSIXDisableAllInterrupts, Spi_HWControlCS,
**                      Spi_CSIXTurnOffUnit, Spi_CSIHInitRegs
**
** Registers Used     : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIHnCFGx, CSIGnCFG0,
**                      CSIHnMCTL1, CSIHnMCTL2, CSIXnSTCR0, CSIXnBRSy, CSIXnSTR0
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDeInit(CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_020 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulJobIndex;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulInitialized;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint8, AUTOMATIC) LucCTL0RegValue;
#if (SPI_CSIH_CONFIGURED == STD_ON)
  VAR(uint32, AUTOMATIC) LulCSCount;
  VAR(uint32, AUTOMATIC) LulCSIndex;
#endif

  LulInitialized = SPI_ZERO;
  /* Scan all jobs and initialize the associated HWUnits */
  for (LulJobIndex = SPI_ZERO;
    LulJobIndex < Spi_GpConfigPtr->usNoOfJobs; LulJobIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
    /* END Msg(4:0491)-1 */
    LulHWUnitIndex = LpJobConfig->ucHWUnitIndex;
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */
    LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
    /* Avoid initializing same HW twice */
    if ((uint32)SPI_ZERO ==
      (LulInitialized & ((uint32)SPI_ONE << LulHWUnitIndex)))
    {
      /* Restore CSIXnCTL0 as the rest default value */
      /* Set default value to registers */
      /* Step 1. Clear PWR, do dummy read */
      Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

      /* Step 2. Clear TXE, RXE, MBS at the same time as setting PWR */
      LucCTL0RegValue = SPI_CSIX_PWR | SPI_CSIX_CTL0_DEFAULT;
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0, LucCTL0RegValue,
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].ucCTL0,
        CTLREG_8_BIT_MASK, 8, LucApiId)
      /* References: SPI_DDD_ACT_020_REG002 */

      /* Step 3. Clear PWR */
      Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

      /* Restore all used registers as the rest default value */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ulCTL1,
        SPI_CSIX_CTL1_DEFAULT,
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].ulCTL1,
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* References: SPI_DDD_ACT_020_REG004 */

      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
        SPI_CSIX_CTL2_DEFAULT,
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
        CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_020_REG005 */

#if (SPI_CSIH_CONFIGURED == STD_ON)
      if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
      {
        /* Reset CSIH specific registers */
        Spi_CSIHInitRegs(LpJobConfig, LulHWPhyIndex,
          LpHWInfo->enMemoryMode, LucApiId);
      }
      else
      {
         /* Nothing to do */
      }
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

      /* Clear all status bits */
      SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
        LpHWInfo->usSTCR0MaskValue)
      /* References: SPI_DDD_ACT_020_REG006 */
      /* Check for Write verification */
      SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0,
        (uint32)SPI_ZERO, (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)

#if (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MACRO_CSIG == LpHWInfo->enMacroType)
    {
      /* Re-set default value for CFG0 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0,
        SPI_CSIX_CFG_DEFAULT,
        &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ulCFG0,
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* References: SPI_DDD_ACT_020_REG007 */
      /* Re-set default value for BCTL0 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ucBCTL0,
        SPI_CSIG_BCTL0_DEFAULT,
        &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ucBCTL0,
        CTLREG_8_BIT_MASK, 8, LucApiId)
      /* References: SPI_DDD_ACT_020_REG008 */
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_CSIG_CONFIGURED == STD_ON) */

      /* Set intialized unit flag */
      LulInitialized = LulInitialized | ((uint32)SPI_ONE << LulHWUnitIndex);
    }
    else
    {
      /* Nothing to do */
    }

#if (SPI_CSIH_CONFIGURED == STD_ON)
    if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
    {
      /* Initialize CFGx registers to reset the clock polarity */
      for (LulCSCount = SPI_ZERO; LulCSCount < LpJobConfig->ucNoOfCS;
        LulCSCount++)
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        LulCSIndex = LpJobConfig->pCSArray[LulCSCount];
        /* END Msg(4:0491)-1 */
        /* QAC Warning: START Msg(2:3441)-3 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaCFG[LulCSIndex],
          SPI_CSIX_CFG_DEFAULT,
          &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaCFG[LulCSIndex],
          CTLREG_32_BIT_MASK, 32, LucApiId)
        /* END Msg(2:3441)-3 */
        /* References: SPI_DDD_ACT_020_REG009 */
      }
    }
    else
    {
      /* Nothing to do */
    }
#endif

#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
    if (SPI_GPIO_CS == LpJobConfig->enCSType)
    {
      /* Deactivate the chip select */
      Spi_HWControlCS(LpJobConfig, SPI_FALSE, LucApiId);
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON) */
  }

  /* Disable all HW unit interrupts */
  Spi_CSIXDisableAllInterrupts();
}

/*******************************************************************************
** Function Name      : Spi_CSIXInitializeForJob
**
** Service ID         : Not Applicable
**
** Description        : Setup a CSIX unit according to Job and the first channel
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig - Pointer to the Job configuration.
**                      LblCFGxOnly - If true, only CFGx registers are
**                        configured.
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function Invoked   : None
**
** Registers Used     : CSIXnBRS, CSIXnCTL1, CSIXnCTL2, CSIXnSTCR0, CSIXnCFG0,
**                      CSIHnCFGx, CSIHnMCTL0
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInitializeForJob(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblCFGxOnly,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_021 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulCFGValue;
#if (SPI_CSIH_CONFIGURED == STD_ON)
  VAR(uint32, AUTOMATIC) LulBRSIndex;
  VAR(uint32, AUTOMATIC) LulCSCount;
#endif
#if (SPI_FIFO_MODE == STD_ON)
  VAR(uint16, AUTOMATIC) LusMCTL0RegValue;
#endif

#if (SPI_CSIX_RAM_MIRROR == STD_ON)
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  /* HW unit index in HW info structure */
  LulHWUnitIndex = (uint32)LpJobConfig->ucHWUnitIndex;
#endif

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  /* Physical index */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  /* Get CFGx value from Job(includes baudrate and CS settings) and
  * the first Channel(includes data length and direction) */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel[LpJobConfig->pChannelList[SPI_ZERO]];
  /* END Msg(4:0491)-1 */
  LulCFGValue = LpJobConfig->ulCSIXCFG | LpChConfig->ulCSIXCFG;

#if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Setup CFGx registers */
  if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
  {
    for (LulCSCount = SPI_ZERO; LulCSCount < LpJobConfig->ucNoOfCS;
      LulCSCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(&Spi_GaaCSIXRegs[
        LulHWPhyIndex].pCSIHRegs->aaCFG[LpJobConfig->pCSArray[LulCSCount]],
        LulCFGValue, &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaCFG[
        LpJobConfig->pCSArray[LulCSCount]], CTLREG_32_BIT_MASK, 32, LucApiId)
      /* END Msg(2:3441)-3 */
      /* END Msg(4:0491)-1 */
      /* References: SPI_DDD_ACT_021_REG001 */
      /* The first CFGx is dominant, and the others are recessive(ignored) */
      LulCFGValue = LulCFGValue | SPI_CSIH_RCB;
    }
  }
  else
  {
    /* Do nothing */
  }
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

  if (SPI_FALSE == LblCFGxOnly)
  {
    /* Setup CTL1, CTL2 and BRS registers according to Job settings */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ulCTL1,
      LpJobConfig->ulCSIXCTL1 & (uint32)(~SPI_CSIH_CSRI),
      &Spi_GaaCTLRegMirror[LulHWUnitIndex].ulCTL1,
      CTLREG_32_BIT_MASK, 32, LucApiId)

    /* References: SPI_DDD_ACT_021_REG003 */
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
#endif
    {
#if (SPI_CSIH_CONFIGURED == STD_ON)
      LulBRSIndex = SPI_CSIH_BRSS_GET(LpJobConfig->ulCSIXCFG);
#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
      /* QAC Warning: START Msg(2:3416)-10 */
      if (SPI_CLOCK_MODE_LOW_POWER == Spi_GenClockModeStatus)
      /* END Msg(2:3416)-10 */
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaBRS[LulBRSIndex].usBRS,
          LpJobConfig->usCSIXBRSLowPower,
          &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaBRS[LulBRSIndex],
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* END Msg(2:3441)-3 */
        /* References: SPI_DDD_ACT_021_REG002 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
          LpJobConfig->usCSIXCTL2LowPower,
          &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* References: SPI_DDD_ACT_021_REG004 */
      }
      else
#endif /* (SPI_SET_CLOCK_MODE_ENABLED == STD_ON) */
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaBRS[LulBRSIndex].usBRS,
          LpJobConfig->usCSIXBRS, &Spi_GaaCSIHRegMirror[
          LulHWUnitIndex].aaBRS[LulBRSIndex],
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* END Msg(2:3441)-3 */
        /* References: SPI_DDD_ACT_021_REG009 */
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
          LpJobConfig->usCSIXCTL2,
          &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* References: SPI_DDD_ACT_021_REG010 */
      }
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
    }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    else
#endif
    {
#if (SPI_CSIG_CONFIGURED == STD_ON)
#if (SPI_SET_CLOCK_MODE_ENABLED == STD_ON)
      /* QAC Warning: START Msg(2:3416)-10 */
      if (SPI_CLOCK_MODE_LOW_POWER == Spi_GenClockModeStatus)
      /* END Msg(2:3416)-10 */
      {
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
          (uint16)(LpJobConfig->usCSIXCTL2LowPower |\
          LpJobConfig->usCSIXBRSLowPower),
          &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* References: SPI_DDD_ACT_021_REG007 */
      }
      else
#endif /* (SPI_SET_CLOCK_MODE_ENABLED == STD_ON) */
      {
        SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
          &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
          (uint16)(LpJobConfig->usCSIXCTL2 | LpJobConfig->usCSIXBRS),
          &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
          CTLREG_16_BIT_MASK, 16, LucApiId)
        /* References: SPI_DDD_ACT_021_REG008 */
      }
      /* Initialize CSIGn.CFG0 register */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0, LulCFGValue,
        &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ulCFG0,
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* References: SPI_DDD_ACT_021_REG011 */
#endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
    }

#if (SPI_FIFO_MODE == STD_ON)
    /* If HW unit configured as slave, initialize FiFo time-out bits */
    if ((SPI_CSIX_PRS_SLAVE == LpJobConfig->usCSIXCTL2) &&
      (SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode))
    {
      /* Initialize FiFo time out in case FIFO slave */
      LusMCTL0RegValue = Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0 |
        (LpJobConfig->usCSIHMCTL0 & (uint16)(~SPI_CSIH_TO_MASK));
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0, LusMCTL0RegValue,
        &Spi_GaaCSIHRegMirror[LulHWUnitIndex].usMCTL0,
        CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_021_REG006 */
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_FIFO_MODE == STD_ON) */
  }
  else
  {
    /* Nothing to do */
  }
}

#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
/*******************************************************************************
** Function Name      : Spi_CSIXInitializeForCh
**
** Service ID         : Not Applicable
**
** Description        : Setup a CSIH unit according to Channel configuration.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters   : LpJobConfig    - Pointer to the Job configuration
**                      LpChConfig     - Pointer to the Channel configuration
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function Invoked   : None
**
** Registers Used     : CSIHnCFGx, CSIGnCFG0
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXInitializeForCh(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_022 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulRegValue;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;

  /* Make CFGx value from Job(includes baudrate and CS settings) and
   * the first Channel(includes data length and direction) */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  /* Get physical index from job */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  /* Value to write CSIXCFG */
  LulRegValue = LpJobConfig->ulCSIXCFG | LpChConfig->ulCSIXCFG;

  /* Since only the first CFGx is marked as dominant,
   * it is enough to modify the first CFGx */
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
#endif
  {
#if (SPI_CSIH_CONFIGURED == STD_ON)
    /* MISRA Violation: START Msg(4:0491)-1 */
    /* QAC Warning: START Msg(2:3441)-3 */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaCFG[
      LpJobConfig->pCSArray[SPI_ZERO]], LulRegValue,
      &Spi_GaaCSIHRegMirror[(uint32)LpJobConfig->ucHWUnitIndex].aaCFG[
      LpJobConfig->pCSArray[SPI_ZERO]], CTLREG_32_BIT_MASK, 32, LucApiId)
    /* END Msg(2:3441)-3 */
    /* END Msg(4:0491)-1 */
    /* References: SPI_DDD_ACT_022_REG001 */
#endif
  }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  else
#endif
  {
#if (SPI_CSIG_CONFIGURED == STD_ON)
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0, LulRegValue,
      &Spi_GaaCSIGRegMirror[(uint32)LpJobConfig->ucHWUnitIndex].ulCFG0,
      CTLREG_32_BIT_MASK, 32, LucApiId)
    /* References: SPI_DDD_ACT_022_REG002 */
#endif
  }
}
#endif /* (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) */

/*******************************************************************************
** Function Name      : Spi_CSIXProcessJob
**
** Service ID         : Not Applicable
**
** Description        : This function perform scheduling under Job layer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LblFirst    - This is the first call for the Job.
**                      LpJobConfig - Pointer to the Job configuration.
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel, Spi_GpFirstHWUnit, Spi_GaaHWStatus
**
** Function Invoked   : Spi_CSIXInitializeForJob, Spi_CSIXInitializeForCh,
**                      Spi_CSIXStartChannelDirectAccessMode,
**                      Spi_CSIXStartChannelFifoMode, Spi_HWControlCS,
**                      Spi_CSIXStartChannelHwBuffer, Spi_CSIXTurnOffUnit
**                      Spi_CSIXTurnOnUnit, Spi_CSIXDMASetUp,
**                      Spi_CSIXDMAStartChannelFifoMode
**
** Registers Used     : None
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXProcessJob(
  CONST(boolean, AUTOMATIC) LblFirst,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_023 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
  (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF))
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(uint32, AUTOMATIC) LulChIndex;
#endif
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LpHWStat = &Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex];
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

  /*
   * If this is the start of Job, initialize entire CSIH.
   * Otherwise, initialize channel relevant registers only.
   */
  if (SPI_TRUE == LblFirst)
  {
    /* Initialize status and HW according to Job config */
    LpHWStat->ucTxChannelCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_023_GBL001 */
    LpHWStat->ucRxChannelCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_023_GBL002 */
#if (SPI_FIFO_MODE == STD_ON)
    /* Initialize HW buffer status for job */
    LpHWStat->blIsTxBufferFull = SPI_FALSE;
    /* References: SPI_DDD_ACT_023_GBL003 */
    LpHWStat->blIsRxBufferFull = SPI_FALSE;
    /* References: SPI_DDD_ACT_023_GBL004 */
#endif
#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
  (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF))
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[SPI_ZERO];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */
#endif
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
    /* Power OFF */
    Spi_CSIXTurnOffUnit(LpJobConfig->ucHWUnitIndex, LucApiId);
    /* Initialize CSIXn */
    Spi_CSIXInitializeForJob(LpJobConfig, SPI_FALSE, LucApiId);
#endif
    /* Clear all error bits and buffer pointers before new transmission */
    SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
      LpHWInfo->usSTCR0MaskValue)
    /* References: SPI_DDD_ACT_023_REG001 */
    /* Check for Write verification */
    SPI_CSIX_VERIFY_WRITE_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0,
     (uint32)SPI_ZERO, (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)
    /* Power ON */
    Spi_CSIXTurnOnUnit(LpJobConfig->ucHWUnitIndex, LucApiId);
  } /* if (SPI_TRUE == LblFirst) */
  else
  {
#if ((SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) || \
  (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF))
    /* Initialize HW according to Channel config */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */
#endif
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
    /* Check if channels in job are not configured as same,
       then configure HW again according next channel properties */
    if (SPI_FALSE == LpJobConfig->blChannelPropertySame)
    {
      /* Power OFF */
      Spi_CSIXTurnOffUnit(LpJobConfig->ucHWUnitIndex, LucApiId);
      /* Initialize CFGx according to Channel config */
      Spi_CSIXInitializeForCh(LpJobConfig, LpChConfig, LucApiId);
      /* Power ON */
      Spi_CSIXTurnOnUnit(LpJobConfig->ucHWUnitIndex, LucApiId);
    }
    else
    {
      /* Nothing to do */
    }
#endif
  } /* else (SPI_TRUE == LblFirst) */

#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
  if (SPI_GPIO_CS == LpJobConfig->enCSType)
  {
    /* Activate the chip select */
    Spi_HWControlCS(LpJobConfig, SPI_TRUE, LucApiId);
  }
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON) */

  switch (LpHWInfo->enMemoryMode)
  {
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  case SPI_MEMMODE_DIRECT_ACCESS:
    /* Start transmission in direct access mode */
    Spi_CSIXStartChannelDirectAccessMode(
      LpJobConfig, LpChConfig, LpHWStat, LulHWPhyIndex);
  break;
#endif
#if (SPI_FIFO_MODE == STD_ON)
  case SPI_MEMMODE_FIFO:
#if (SPI_DMA_CONFIGURED == STD_ON)
    if (SPI_INVALID_DMAUNIT == LpJobConfig->ucRxDmaIndex)
#endif
    {
      /* Start transmission in FIFO mode */
      Spi_CSIXStartChannelFifoMode(
        LpJobConfig, LpHWStat, LulHWPhyIndex);
    }
#if (SPI_DMA_CONFIGURED == STD_ON)
    else
    {
      /* Start transmission in FIFO mode with DMA */
      Spi_CSIXDMAStartChannelFifoMode(
        LpJobConfig, LpHWStat, LulHWPhyIndex);
    }
#endif
  break;
#endif
#if (SPI_DUAL_BUFFER_MODE == STD_ON)
  case SPI_MEMMODE_DUAL_BUFFER:
    /* Start transmission in dual buffer mode */
    Spi_CSIXStartChannelHwBuffer(
      LpJobConfig, LpChConfig, LulHWPhyIndex);
  break;
#endif
#if (SPI_TX_ONLY_MODE == STD_ON)
  case SPI_MEMMODE_TX_ONLY:
    /* Initialize RAM Rx pointer and the number of Rx data */
    LpHWStat->pRxPtr = LpChConfig->pRxBuffer;
    /* References: SPI_DDD_ACT_023_GBL005 */
    LpHWStat->usRemainedRxCount = LpJobConfig->usNoOfHwBuffers;
    /* References: SPI_DDD_ACT_023_GBL006 */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    /* Set EDL flag if DataWidth is longer than 16 */
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      LpHWStat->blRxEDLOngoing = SPI_TRUE;
      /* References: SPI_DDD_ACT_023_GBL007 */
    }
    else
    {
      LpHWStat->blRxEDLOngoing = SPI_FALSE;
      /* References: SPI_DDD_ACT_023_GBL008 */
    }
#endif
#if (SPI_DMA_CONFIGURED == STD_ON)
    /* Setup Rx DMA for reception */
    Spi_CSIXDMASetUp(
      LpJobConfig, LpHWStat, NULL_PTR,
      LpJobConfig->usNoOfHwBuffers, SPI_ZERO);
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
    /* Start transmission in Tx only mode */
    Spi_CSIXStartChannelHwBuffer(
      LpJobConfig, LpChConfig, LulHWPhyIndex);
  break;
#endif
  /* QAC Warning: START Msg(2:2016)-5 */
  default:
    /* Nothing to do */
  /* END Msg(2:2016)-5 */
  break;
  /* QAC Warning: START Msg(3:3352)-11 */
  }
  /* END Msg(3:3352)-11 */
}

#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXStartChannelDirectAccessMode
**
** Service ID         : Not Applicable
**
** Description        : This function writes data to Tx Buffer and
**                      starts transmission on DirectAccessMode on CSIX.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpChConfig    - Pointer to the Channel configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GenAsyncMode, Spi_GulDmaRxData
**
** Function Invoked   : Spi_LoadTxData, Spi_DMAStart, Spi_CSIXWriteTX0Register,
**                      Spi_CSIXMaskHWUnitInterrupts, Spi_CSIXDMASetUp
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelDirectAccessMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_024 */
{
  VAR(uint32, AUTOMATIC) LulTxData;

  /* Prepare channel buffers in Direct access mode */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
  if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
  {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
    /* Initialize rx/tx pointers to point to IB */
    LpHWStat->pTxPtr = LpChConfig->pTxBuffer;
    /* References: SPI_DDD_ACT_024_GBL001 */
    LpHWStat->pRxPtr = LpChConfig->pRxBuffer;
    /* References: SPI_DDD_ACT_024_GBL002 */
    LpHWStat->usRemainedTxCount = LpChConfig->usNoOfBuffers;
    /* References: SPI_DDD_ACT_024_GBL003 */
    LpHWStat->usRemainedRxCount = LpChConfig->usNoOfBuffers;
    /* References: SPI_DDD_ACT_024_GBL004 */
#endif
  }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
  else
#endif
  {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
    /* Initialize rx/tx pointers to point to EB */
    LpHWStat->pTxPtr = LpChConfig->pEBData->pSrcPtr;
    /* References: SPI_DDD_ACT_024_GBL005 */
    LpHWStat->pRxPtr = LpChConfig->pEBData->pDestPtr;
    /* References: SPI_DDD_ACT_024_GBL006 */
    LpHWStat->usRemainedTxCount = LpChConfig->pEBData->usEBLength;
    /* References: SPI_DDD_ACT_024_GBL007 */
    LpHWStat->usRemainedRxCount = LpChConfig->pEBData->usEBLength;
    /* References: SPI_DDD_ACT_024_GBL008 */
#endif
  }

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* QAC Warning: START Msg(2:3416)-10 */
  if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
  /* END Msg(2:3416)-10 */
#endif
  {
    /* If the channel has only one data, transmit ISR is not necessary */
    if ((SPI_ONE == LpHWStat->usRemainedTxCount) &&
      ((SPI_FALSE == LpJobConfig->blChannelPropertySame) ||
       (SPI_ONE == LpJobConfig->ucNoOfChannels))
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      /* If DataWidth > 16, not disable Tx interrupt to transmit 2nd word */
      && (LpChConfig->ucDataWidth <= SPI_CSIX_WORD)
#endif
    )
    {
      /* Enable Rx interrupt and DMA only */
      Spi_CSIXMaskHWUnitInterrupts(
        LpJobConfig, SPI_FALSE, SPI_TRUE, SPI_TRUE);
    }
    else
    {
      /* Enable all interrupts */
      Spi_CSIXMaskHWUnitInterrupts(
        LpJobConfig, SPI_FALSE, SPI_FALSE, SPI_TRUE);
    }
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if (SPI_CSIH_CONFIGURED == STD_ON)
  /* Set CS field of TX0W register */
  LulTxData = SPI_CSIH_CS(LpJobConfig->ucCSIHCSInfo);
#else
  /* Initialize local variable as zero */
  LulTxData = SPI_ZERO;
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

  /* Prepare TX0W register value(s) */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* QAC Warning: START Msg(2:3441)-3 */
  Spi_LoadTxData(LpHWStat->pTxPtr, LpChConfig,
    &LulTxData, &LpHWStat->ulTxEDLSecondWord);
  /* END Msg(2:3441)-3 */
#else
  /* QAC Warning: START Msg(2:3441)-3 */
  Spi_LoadTxData(LpHWStat->pTxPtr, LpChConfig,
    &LulTxData, NULL_PTR);
  /* END Msg(2:3441)-3 */
#endif
  /* Increment tx pointer according to data width */
  if (NULL_PTR != LpHWStat->pTxPtr)
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    LpHWStat->pTxPtr = LpHWStat->pTxPtr + LpChConfig->ucByteSize;
    /* END Msg(4:0488)-2 */
    /* References: SPI_DDD_ACT_024_GBL009 */
  }
  else
  {
    /* Nothing to do */
  }

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Set EDL flag if DataWidth is longer than 16 */
  if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
  {
    LpHWStat->blTxEDLOngoing = SPI_TRUE;
    /* References: SPI_DDD_ACT_024_GBL010 */
    LpHWStat->blRxEDLOngoing = SPI_TRUE;
    /* References: SPI_DDD_ACT_024_GBL011 */

    /* DMA is not supported for EDL */
  }
  else
#endif
  {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    LpHWStat->blTxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_024_GBL012 */
    LpHWStat->blRxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_024_GBL013 */
#endif

#if (SPI_DMA_CONFIGURED == STD_ON)
    /* QAC Warning: START Msg(2:3441)-3 */
    Spi_CSIXDMASetUp(
      LpJobConfig, LpHWStat, &LpChConfig->ulDefaultData,
      LpHWStat->usRemainedRxCount,
      (uint16)(LpHWStat->usRemainedTxCount - SPI_ONE));
    /* END Msg(2:3441)-3 */
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
  }

  /* Decrease Tx buffer counter */
  LpHWStat->usRemainedTxCount--;
  /* References: SPI_DDD_ACT_024_GBL014 */

  /* Start transmission */
  Spi_CSIXWriteTX0Register(LulHWPhyIndex, LulTxData);
}
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXTransmitSyncJob
**
** Service ID         : Not Applicable
**
** Description        : This function transmits a Job synchronously.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig - Pointer to the Job configuration.
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variables   : Spi_GaaHWStatus, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs,
**                      Spi_GpConfigPtr, Spi_GaaJobStatus, Spi_GaaSeqStatus
**
** Function Invoked   : Dem_ReportErrorStatus, Spi_CSIXProcessJob,
**                      Spi_CSIXReceiveISR, Spi_CSIXTransmitISR
**
** Registers Used     : EIC(CSIXnTIR), EIC(CSIX,TIC)
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXTransmitSyncJob(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_025 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulWaitCount;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  LucReturnValue = E_OK;

  /* Get the base address of the HW Unit */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LpHWStat = &Spi_GaaHWStatus[LpJobConfig->ucHWUnitIndex];
  /* Get HW physical index */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

  /* Just in case, clear EIRF flags before starting transmission */
  RH850_SV_CLEAR_ICR_SYNCP(16,
    Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC, (uint16)(~SPI_EIC_EIRF_MASK));
  /* References: SPI_DDD_ACT_025_REG001 */
  RH850_SV_CLEAR_ICR_SYNCP(16,
    Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR, (uint16)(~SPI_EIC_EIRF_MASK));
  /* References: SPI_DDD_ACT_025_REG002 */

  /* Setup HW for Job and send the first data */
  Spi_CSIXProcessJob(SPI_TRUE, LpJobConfig, LucApiId);

  /* Loop until Job end or any error occurs */
  LulWaitCount = SPI_ZERO;
  do
  {
    if (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR) & SPI_EIC_EIRF_MASK))
    {
      /* To emulate the default interrupt priority (CSIXnTIC > CSIXnTIR),
         check CSIXnTIC again */
      if (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
        Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC) & SPI_EIC_EIRF_MASK))
      {
        /* Clear interrupt request flag */
        RH850_SV_CLEAR_ICR_SYNCP(16,
          Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC, (uint16)(~SPI_EIC_EIRF_MASK));
        /* References: SPI_DDD_ACT_025_REG003 */
        /* If tx interruption flag is activated, call TxISR */
        Spi_CSIXTransmitISR((uint32)LpJobConfig->ucHWUnitIndex);
      }
      else
      {
        /* Nothing to do */
      }
      /* Clear interrupt request flag */
      RH850_SV_CLEAR_ICR_SYNCP(16,
        Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR, (uint16)(~SPI_EIC_EIRF_MASK));
      /* References: SPI_DDD_ACT_025_REG004 */
      /* If rx interruption flag is activated, call RxISR */
      Spi_CSIXReceiveISR((uint32)LpJobConfig->ucHWUnitIndex);
      /* Reset timeout count */
      LulWaitCount = SPI_ZERO;
    }
    else
    {
      /* Increment timeout count */
      LulWaitCount++;
    }

    if (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC) & SPI_EIC_EIRF_MASK))
    {
      /* Clear interrupt request flag */
      RH850_SV_CLEAR_ICR_SYNCP(16,
        Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC, (uint16)(~SPI_EIC_EIRF_MASK));
      /* References: SPI_DDD_ACT_025_REG005 */
      /* If tx interruption flag is activated, call TxISR */
      Spi_CSIXTransmitISR((uint32)LpJobConfig->ucHWUnitIndex);
      /* Reset timeout count */
      LulWaitCount = SPI_ZERO;
    }
    else
    {
      /* Increment timeout count */
      LulWaitCount++;
    }

    /* Check timeout */
    if (Spi_GpConfigPtr->ulTimeoutCount <= LulWaitCount)
    /* References: SPI_DDD_ACT_025_ERR001 */
    {
#if defined(SPI_E_DATA_TX_TIMEOUT_FAILURE)
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
        DEM_EVENT_STATUS_FAILED);
#endif
      Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult = SPI_JOB_FAILED;
      /* References: SPI_DDD_ACT_025_GBL001 */
      /* At least one Job failed, set sequence failed flag */
      Spi_GaaSeqStatus[LpHWStat->ucOngoingSeqIndex].blFailed = SPI_TRUE;
      /* References: SPI_DDD_ACT_025_GBL002 */
    }
    else
    {
      /* Nothing to do */
    }
  }while ((SPI_FALSE == Spi_GaaSeqStatus[LpHWStat->ucOngoingSeqIndex].blFailed)
    && (LpHWStat->ucRxChannelCount < LpJobConfig->ucNoOfChannels));

  /* If any HW error has been occurred, return E_NOT_OK */
  if (SPI_TRUE == Spi_GaaSeqStatus[LpHWStat->ucOngoingSeqIndex].blFailed)
  {
    LucReturnValue = E_NOT_OK;
  }
  else
  {
    /* Nothing to do */
  }

  return(LucReturnValue);
}
#endif /* (DIRECT_ACCESS_MODE == STD_ON) */
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

/*******************************************************************************
** Function Name      : Spi_LoadTxData
**
** Service ID         : Not Applicable
**
** Description        : This function loads data from the buffer and
**                      encode it to send with TX0W register.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpData       - Pointer to the buffer to load data.
**                      LpChConfig   - Pointer to the Channel configuration.
**
** InOut Parameters   : None
**
** Output Parameters  : LpFirstWord  - Pointer to store the first word of TX0W
**                      LpSecondWord - Pointer to store the second word of TX0W
**                                     This parameter is not used when
**                                     EDL feature is disabled.
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : None
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_LoadTxData(
  volatile CONSTP2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpData,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpFirstWord,
  volatile CONSTP2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpSecondWord)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_026 */
{
  VAR(uint32, AUTOMATIC) LulData;

  /* Load data from memory according to the access size */
  if (NULL_PTR == LpData)
  {
    LulData = LpChConfig->ulDefaultData;
  }
  else
  {
    switch (LpChConfig->ucByteSize)
    {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* QAC Warning: START Msg(3:3305)-2 */
    case sizeof(uint32):
      LulData = *(const volatile uint32*)LpData;
    /* END Msg(3:3305)-2 */
    /* END Msg(4:0310)-3 */
      break;
#endif
    /* MISRA Violation: START Msg(4:0310)-3 */
    /* QAC Warning: START Msg(3:3305)-2 */
    case sizeof(uint16):
      LulData = *(const volatile uint16*)LpData;
    /* END Msg(3:3305)-2 */
    /* END Msg(4:0310)-3 */
      break;
    default:
      LulData = *LpData;
      break;
    /* QAC Warning: START Msg(3:3352)-11 */
    }
    /* END Msg(3:3352)-11 */
  }

  /* Dereference of NULL pointer */
  if (NULL_PTR != LpFirstWord)
  {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if ((LpChConfig->ucDataWidth > SPI_CSIX_WORD) &&
      (NULL_PTR != LpSecondWord))
    {
      /* Copy CS setting to SecondWord from FirstWord */
      *LpSecondWord = *LpFirstWord;
      /* Set EDL of FirstWord */
      *LpFirstWord =(*LpFirstWord) | SPI_CSIX_EDL;
      /* Separate 32bit data to two 16bit data */
      if ((uint32)SPI_ZERO != (LpChConfig->ulCSIXCFG & SPI_CSIX_DIRL))
      {
        /*
         * e.g. DataWidth=20, LSB first
         *   [******** ****cccc BBBBbbbb AAAAaaaa]
         *   => 1stTxData: [XXXXXXXX XXXXXXXX BBBBbbbb AAAAaaaa]
         *      2ndTxData: [XXXXXXXX XXXXXXXX ******** ****cccc]
         *   X: Control bits of TX0W
         *   *: Don't care
         */
        *LpFirstWord = *LpFirstWord |
          ((LulData << SPI_CSIX_WORD) >> SPI_CSIX_WORD);
        *LpSecondWord = *LpSecondWord | (LulData >> SPI_CSIX_WORD);
      }
      else
      {
        /*
         * e.g. DataWidth=20, MSB first
         *   [******** ****cccc BBBBbbbb AAAAaaaa]
         *   => 1stTxData: [XXXXXXXX XXXXXXXX ccccBBBB bbbbAAAA]
         *      2ndTxData: [XXXXXXXX XXXXXXXX ******** ****aaaa]
         *   X: Control bits of TX0W
         *   *: Don't care
         */
        *LpFirstWord = *LpFirstWord |
          ((LulData << (SPI_UINT32_BITS - LpChConfig->ucDataWidth))
          >> SPI_CSIX_WORD);
        *LpSecondWord = *LpSecondWord |
          ((LulData << SPI_CSIX_WORD) >> SPI_CSIX_WORD);
      }
    }
    else
#endif
    {
      /* Merge upper 16bit of FirstWord and lower 16bit of LulData */
      *LpFirstWord = *LpFirstWord | LulData;
    }
  }
  else
  {
    /* Nothing to do */
  }
}

/*******************************************************************************
** Function Name      : Spi_StoreRxData
**
** Service ID         : Not Applicable
**
** Description        : This function merges two word from RX0H register and
**                      stores it to the buffer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpChConfig    - Pointer to the Channel configuration.
**                      LusFirstWord  - The first word from RX0H register.
**                      LusSecondWord - The second word from RX0H register.
**                                      This parameter is not used when
**                                      EDL feature is disabled.
**
** InOut Parameters   : None
**
** Output Parameters  : LpData        - Pointer to the buffer to store data.
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : None
**
** Registers Used     : None
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_StoreRxData(
  volatile CONSTP2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpData,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint16, AUTOMATIC) LusFirstWord,
  CONST(uint16, AUTOMATIC) LusSecondWord)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_027 */
{
  VAR(uint32, AUTOMATIC) LulData;
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Combine 32bit data from two 16bit data */
  if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
  {
    if ((uint32)SPI_ZERO != (LpChConfig->ulCSIXCFG & SPI_CSIX_DIRL))
    {
      /* e.g. DataWidth=20, LSB first
       *   1stRxData: [BBBBbbbb AAAAaaaa]
       *   2ndRxData: [00000000 0000cccc]
       *   => [00000000 0000cccc BBBBbbbbb AAAAaaaa]
       */
      LulData =
        (uint32)LusFirstWord | ((uint32)LusSecondWord << SPI_CSIX_WORD);
    }
    else
    {
      /* e.g. DataWidth=20, MSB first
       *   1stRxData: [ccccBBBB bbbbAAAA]
       *   2ndRxData: [00000000 0000aaaa]
       *   => [00000000 0000cccc BBBBbbbb AAAAaaaa]
       */
      /* Fill unnecessary bits of 1st and 2nd Data with 0, and merge them */
      LulData =
        ((uint32)LusFirstWord << (LpChConfig->ucDataWidth - SPI_CSIX_WORD)) |
        (uint32)LusSecondWord;
    }
  }
  else
#endif /* (SPI_EXTENDED_DATA_LENGTH == STD_ON) */
  {
    LulData = (uint32)LusSecondWord;
  }
  /* Store data to memory according to the access size */
  switch (LpChConfig->ucByteSize)
  {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* MISRA Violation: START Msg(4:0310)-3 */
  /* QAC Warning: START Msg(3:3305)-2 */
  case sizeof(uint32):
    *(volatile uint32*)LpData = LulData;
  /* END Msg(3:3305)-2 */
  /* END Msg(4:0310)-3 */
    break;
#endif
  /* MISRA Violation: START Msg(4:0310)-3 */
  /* QAC Warning: START Msg(3:3305)-2 */
  case sizeof(uint16):
    *(volatile uint16*)LpData = (uint16)LulData;
  /* END Msg(3:3305)-2 */
  /* END Msg(4:0310)-3 */
    break;
  default:
    *LpData = (uint8)LulData;
    break;
  /* QAC Warning: START Msg(3:3352)-11 */
  }
  /* END Msg(3:3352)-11 */
}

#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXTransmitISR
**
** Service ID         : Not Applicable
**
** Description        : This is the interrupt service routine for transmission
**                      This ISR is invoked when the following case:
**                      DIRECT_ACCESS_MODE    : every transmission complete
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LulHWUnitIndex - Index of HWUnit configuration.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstjob, Spi_GpFirstChannel, Spi_GpFirstHWUnit,
**                      Spi_GaaHWStatus, Spi_GenAsyncMode
**
** Function Invoked   : Spi_LoadTxData, Spi_CSIXWriteTX0Register,
**                      Spi_CSIXMaskHWUnitTxInterrupt
**
** Registers Used     : None
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTransmitISR(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex)
/* References: SPI_DDD_ACT_028 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulFirstWord;

  /* Get pointers and index relevant to HW */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  LpHWStat = &Spi_GaaHWStatus[LulHWUnitIndex];

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  if (SPI_TRUE == LpHWStat->blTxEDLOngoing)
  {
    /* If this is the second half of 32bit data, send prepared data */
    LpHWStat->blTxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_028_GBL001 */
    /* QAC Warning: START Msg(2:3441)-3 */
    Spi_CSIXWriteTX0Register(LulHWPhyIndex, LpHWStat->ulTxEDLSecondWord);
    /* END Msg(2:3441)-3 */
  }
  else
#endif
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LpHWStat->usOngoingJobIndex];
    /* END Msg(4:0491)-1 */

    /* Check whether a Channel is finished */
    if (SPI_ZERO == LpHWStat->usRemainedTxCount)
    {
      /* When a Channel is finished, increment Channel count */
      LpHWStat->ucTxChannelCount++;
      /* References: SPI_DDD_ACT_028_GBL002 */

      /*
       * There are remained Channels and all Channel properties are same,
       * setup buffer for the next channel and continue the operation.
       * Otherwise this operation will be done by RxISR.
       */
      if ((LpHWStat->ucTxChannelCount < LpJobConfig->ucNoOfChannels)
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
        && (SPI_TRUE == LpJobConfig->blChannelPropertySame)
#endif
        )
      {
        /* MISRA Violation: START Msg(4:0491)-1 */
        LpChConfig = &Spi_GpFirstChannel
          [LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount]];
        /* END Msg(4:0491)-1 */

#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
        if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
        {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
          LpHWStat->pTxPtr = LpChConfig->pTxBuffer;
          /* References: SPI_DDD_ACT_028_GBL003 */
          LpHWStat->usRemainedTxCount = LpChConfig->usNoOfBuffers;
          /* References: SPI_DDD_ACT_028_GBL004 */
#endif
        }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
        else
#endif
        {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
(SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
          LpHWStat->pTxPtr = LpChConfig->pEBData->pSrcPtr;
          /* References: SPI_DDD_ACT_028_GBL005 */
          LpHWStat->usRemainedTxCount = LpChConfig->pEBData->usEBLength;
          /* References: SPI_DDD_ACT_028_GBL006 */
#endif
        }
      }
      else
      {
        /* Nothing to do */
      }
    } /* if (LpHWStat->usRemainedTxCount == SPI_ZERO) */
    else
    {
      /* Nothing to do */
    }

    /* If there is the next data, send it */
    if (LpHWStat->usRemainedTxCount > SPI_ZERO)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      LpChConfig = &Spi_GpFirstChannel
        [LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount]];
      /* END Msg(4:0491)-1 */

#if (SPI_CSIH_CONFIGURED == STD_ON)
      /* Set CS field of TX0W register */
      LulFirstWord = SPI_CSIH_CS(LpJobConfig->ucCSIHCSInfo);
#else
      /* Initialize local variable as zero */
      LulFirstWord = SPI_ZERO;
#endif

      /* Prepare Tx data from memory */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      /* QAC Warning: START Msg(2:3441)-3 */
      Spi_LoadTxData(LpHWStat->pTxPtr,
        LpChConfig, &LulFirstWord, &LpHWStat->ulTxEDLSecondWord);
      /* END Msg(2:3441)-3 */
#else
      /* QAC Warning: START Msg(2:3441)-3 */
      Spi_LoadTxData(LpHWStat->pTxPtr, LpChConfig, &LulFirstWord, NULL_PTR);
      /* END Msg(2:3441)-3 */
#endif
      /* Increment the data pointer */
      if (NULL_PTR != LpHWStat->pTxPtr)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpHWStat->pTxPtr = LpHWStat->pTxPtr + LpChConfig->ucByteSize;
        /* END Msg(4:0488)-2 */
        /* References: SPI_DDD_ACT_028_GBL007 */
      }
      else
      {
        /* Nothing to do */
      }
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
      {
        LpHWStat->blTxEDLOngoing = SPI_TRUE;
        /* References: SPI_DDD_ACT_028_GBL008 */
      }
      else
      {
        /* Nothing to do */
      }
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
      /* QAC Warning: START Msg(2:3416)-10 */
      if ((SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
        && (SPI_FALSE == LpHWInfo->blSynchronous))
      /* END Msg(2:3416)-10 */
#endif
      {
        /* If the channel has only one data, transmit ISR is not necessary */
        if ((SPI_ONE == LpHWStat->usRemainedTxCount) &&
          ((SPI_FALSE == LpJobConfig->blChannelPropertySame) ||
          (LpHWStat->ucTxChannelCount ==
          (LpJobConfig->ucNoOfChannels - SPI_ONE)))
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
          && (SPI_FALSE == LpHWStat->blTxEDLOngoing)
#endif
        )
        {
          /* Disable TX interrupt */
          Spi_CSIXMaskHWUnitTxInterrupt(
            LulHWPhyIndex, SPI_TRUE, SPI_FALSE);
        }
        else
        {
          /* Nothing to do */
        }
      }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
      else
      {
        /* Nothing to do */
      }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

      /* Send data by writing to TX register */
      Spi_CSIXWriteTX0Register(LulHWPhyIndex, LulFirstWord);
      LpHWStat->usRemainedTxCount--;
      /* References: SPI_DDD_ACT_028_GBL009 */
    } /* if (LpHWStat->usRemainedTxCount > SPI_ZERO) */
    else
    {
      /* Nothing to do */
    }
  } /* else (SPI_TRUE == LpHWStat->blTxEDLOngoing) */
}
#endif /* End of (SPI_DIRECT_ACCESS_MODE == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_CSIXReceiveISR
**
** Service ID         : Not Applicable
**
** Description        : This is the interrupt service routine for CSIX
**                      This is invoked when the following cases:
**                      DIRECT_ACCESS_MODE : every reception complete.
**                      FIFO_MODE: every data in HW buffer complete.
**                      DUAL_BUFFER_MODE : every data in a job complete.
**                      TX_ONLY_MODE : every data in a job complete.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters   : LulHWUnitIndex - Index of HWUnit configuration
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstJob, Spi_GpFirstHWUnit, Spi_GpFirstSeq
**                      Spi_GaaHWStatus, Spi_GaaCSIXRegs, Spi_GaaJobStatus,
**                      Spi_GaaSeqStatus
**
** Function Invoked   : Spi_CSIXProcessEndJob,
**                      Spi_CSIXReceiveChannelDirectAccessMode,
**                      Spi_CSIXReceiveChannelFifoMode,
**                      Spi_CSIXReceiveChannelTxOnlyMode,
**                        Dem_ReportErrorStatus
**
** Registers Used     : CSIXnSTR0
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveISR(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex)
/* References: SPI_DDD_ACT_029 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  /* If Internal Diagnosis Error Buffer size is Greater than Zero */
  #if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
  VAR(uint16, AUTOMATIC) LusErrorStatus;
  #endif
  /* QAC Warning: START Msg(2:3204)-7 */
  volatile VAR(uint8, AUTOMATIC) LucApiId;
  /* END Msg(2:3204)-7 */

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  LpHWStat = &Spi_GaaHWStatus[LulHWUnitIndex];

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LpHWStat->usOngoingJobIndex];
  /* END Msg(4:0491)-1 */

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_0)
  LucApiId = SPI_SYNCTRANSMIT_SID;
#elif (SPI_LEVEL_DELIVERED == SPI_LEVEL_1)
  LucApiId = SPI_ASYNCTRANSMIT_SID;
#else
  /* MISRA Violation: START Msg(4:0491)-1 */
  if (SPI_TRUE == Spi_GpFirstSeq[LpHWStat->ucOngoingSeqIndex].blSynchronous)
  /* END Msg(4:0491)-1 */
  {
    LucApiId = SPI_SYNCTRANSMIT_SID;
  }
  else
  {
    LucApiId = SPI_ASYNCTRANSMIT_SID;
  }
#endif

  switch (LpHWInfo->enMemoryMode)
  {
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
  case SPI_MEMMODE_DIRECT_ACCESS:
    /* Process to receive data in Direct access mode */
    Spi_CSIXReceiveChannelDirectAccessMode(
      LpJobConfig, LpHWStat, LulHWPhyIndex);
  break;
#endif
#if (SPI_FIFO_MODE == STD_ON)
  case SPI_MEMMODE_FIFO:
    /* Process to receive data in fifo mode */
    Spi_CSIXReceiveChannelFifoMode(
      LpJobConfig, LpHWStat, LulHWPhyIndex);
  break;
#endif
#if (SPI_DUAL_BUFFER_MODE == STD_ON)
  case SPI_MEMMODE_DUAL_BUFFER:
    /* Set number of channels received of this job */
    LpHWStat->ucRxChannelCount = LpJobConfig->ucNoOfChannels;
    /* References: SPI_DDD_ACT_029_GBL001 */
  break;
#endif
#if (SPI_TX_ONLY_MODE == STD_ON)
  case SPI_MEMMODE_TX_ONLY:
    /* Process to receive data in Tx only mode */
    Spi_CSIXReceiveChannelTxOnlyMode(
      LpJobConfig, LpHWStat, LulHWPhyIndex);
  break;
#endif
  /* QAC Warning: START Msg(2:2016)-5 */
  default:
      /* Nothing to do */
  /* END Msg(2:2016)-5 */
  break;
  /* QAC Warning: START Msg(3:3352)-11 */
  }
  /* END Msg(3:3352)-11 */

  /* Check whether a Channel is finished */
  /* Check whether any error has been occurred during a Channel */
  if ((uint32)SPI_ZERO != (Spi_GaaCSIXRegs[
    LpHWInfo->ucPhysicalIndex].pCSIXSTRegs->ulSTR0 &
    ((uint32)LpHWInfo->usSTCR0MaskValue & (uint32)SPI_CSIX_ERR_MASK)))
  /* References: SPI_DDD_ACT_029_ERR001 */
  {
#if defined(SPI_E_HARDWARE_ERROR)
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
    /* Get error value from status register */
    LusErrorStatus = (uint16)Spi_GaaCSIXRegs[
      LpHWInfo->ucPhysicalIndex].pCSIXSTRegs->ulSTR0;
    /* Check and store error information to RAM buffer */
    Spi_CheckAndStoreErrorInfo(LulHWUnitIndex, LusErrorStatus);
#endif
    /* Clear all status bits */
    SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
        LpHWInfo->usSTCR0MaskValue)
    /* References: SPI_DDD_ACT_029_REG001 */
    /* Check for Write verification */
    /* QAC Warning: START Msg(2:3441)-3 */
    SPI_CSIX_VERIFY_WRITE_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0, (uint32)SPI_ZERO,
      (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)
    /* END Msg(2:3441)-3 */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
    if ((SPI_MEMMODE_DUAL_BUFFER == LpHWInfo->enMemoryMode) ||
      (SPI_MEMMODE_TX_ONLY == LpHWInfo->enMemoryMode))
    {
      /* Clear memory control bits in dual buffer mode */
      SPI_WRITE_REG_ONLY(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL2,
        SPI_CSIH_MCTL2_DEFAULT)
      /* References: SPI_DDD_ACT_029_REG002 */
      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_VERIFY_WRITE_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL2,
        SPI_CSIH_MCTL2_DEFAULT, CTLREG_32_BIT_MASK, 32, LucApiId)
      /* END Msg(2:3441)-3 */
    }
    else
    {
      /* Nothing to do */
    }
#endif
    /* Update Job result as FAILED */
    Spi_GaaJobStatus[Spi_GaaHWStatus[
      LulHWUnitIndex].usOngoingJobIndex].enResult = SPI_JOB_FAILED;
    /* References: SPI_DDD_ACT_029_GBL002 */
    /* A least one Job failed, set sequence failed flag */
    Spi_GaaSeqStatus[Spi_GaaHWStatus[
      LulHWUnitIndex].ucOngoingSeqIndex].blFailed = SPI_TRUE;
    /* References: SPI_DDD_ACT_029_GBL003 */
  }
  else
  {
    /* Nothing to do */
  }

  /* Check whether a job is finished and process next job or sequence */
  /* QAC Warning: START Msg(2:3441)-3 */
  Spi_CSIXProcessEndJob(
    LpHWInfo, LpHWStat, LpJobConfig, LucApiId);
  /* END Msg(2:3441)-3 */
}

/*******************************************************************************
** Function Name      : Spi_CSIXProcessEndJob
**
** Service ID         : Not Applicable
**
** Description        : This is to check whether a job is finished and then
**                      process next job or sequence.
**
** Sync/Async         : Asynchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters   : LpHWInfo    - Pointer to the HW configuration.
**                      LpHWStat    - Pointer to the HW status structure.
**                      LpJobConfig - Pointer to the job configuration.
**                      LucApiId    - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstJob,, Spi_GaaJobStatus, Spi_GenAsyncMode
**
** Function Invoked   : Spi_CSIXProcessJob, Spi_ProcessSequence,
**                      Spi_CSIXTurnOffUnit, Spi_HWControlCS,
**                      Spi_CSIXMaskHWUnitInterrupts
**
** Registers Used     : CSIXnCTL1
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXProcessEndJob(
  CONSTP2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo,
  volatile CONSTP2CONST(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_092 */
{
  /* Check whether a job is finished */
  if ((LpHWStat->ucRxChannelCount == LpJobConfig->ucNoOfChannels) ||
    (SPI_JOB_FAILED == Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult))
  {
    /* All Channels in a Job are completed */
#if (SPI_CSIH_CONFIGURED == STD_ON)
    /* Check CS configured with HW unit */
    if ((SPI_PERIPHERAL_ENGINE_CS != LpJobConfig->enCSType) ||
      (SPI_CSIH_CSRI == (LpJobConfig->ulCSIXCTL1 & SPI_CSIH_CSRI)))
#endif
    {
      /* Power OFF HW unit associated the job to save power consumption. */
      /* If HW unit is CSIH, It also de-activates CSIH CS signal assigned to
         this job. */
      Spi_CSIXTurnOffUnit(LpJobConfig->ucHWUnitIndex, LucApiId);
    }
#if (SPI_CSIH_CONFIGURED == STD_ON)
    else
    {
      /* Nothing to do */
    }
#endif

#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
    /* Check if job is configured with CS as GPIO */
    if (SPI_GPIO_CS == LpJobConfig->enCSType)
    {
      /* Deactivate the chip select via selected GPIO port pin */
      Spi_HWControlCS(LpJobConfig, SPI_FALSE, LucApiId);
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON) */

    /* Set Job result as OK if no hardware error */
    if (SPI_JOB_FAILED !=
      Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult)
    {
      Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult = SPI_JOB_OK;
      /* References: SPI_DDD_ACT_092_GBL001 */
    }
    else
    {
      /* Nothing to do */
    }

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
    if (SPI_TRUE == LpHWInfo->blSynchronous)
    {
      /* When SyncTransmit, scheduling is done by Spi_SyncTransmit */
    }
    else
#endif
    {
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
      /* QAC Warning: START Msg(2:3416)-10 */
      if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
      /* END Msg(2:3416)-10 */
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
      {
        /* Mask all interrupts after job completed */
        Spi_CSIXMaskHWUnitInterrupts(
          LpJobConfig, SPI_TRUE, SPI_TRUE, SPI_FALSE);
      }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
      else
      {
        /* Nothing to do */
      }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */
      /* Invoke the upper layer scheduler */
      Spi_ProcessSequence((uint32)LpJobConfig->ucHWUnitIndex);
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */
    } /* if (LpHWStat->ucRxChannelCount == LpJobConfig->ucNoOfChannels) */
  }
  else
  {
#if (((SPI_DIRECT_ACCESS_MODE == STD_ON) &&\
       (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)) ||\
         (SPI_FIFO_MODE == STD_ON))
    if (((SPI_ZERO == LpHWStat->usRemainedRxCount) &&
         (SPI_FALSE == LpJobConfig->blChannelPropertySame) &&
         (SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode)) ||
         (SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode)
       )
    {
      /* Start the next channel in direct access mode/fifo mode */
      /* QAC Warning: START Msg(2:3441)-3 */
      /* MISRA Violation: START Msg(4:0491)-1 */
      Spi_CSIXProcessJob(SPI_FALSE,
        &Spi_GpFirstJob[LpHWStat->usOngoingJobIndex], LucApiId);
      /* END Msg(4:0491)-1 */
      /* END Msg(2:3441)-3 */
    }
    else
    {
      /* Nothing to do */
    }
#endif
  }
}

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
   (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#if (SPI_DMA_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXDMACompleteISR
**
** Service ID         : Not Applicable
**
** Description        : This function is invoked when DMA transfer is completed.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters   : LulDMAUnitIndex - Index of DMA unit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstJob, Spi_GpFirstDMAUnit, Spi_GaaHWStatus,
**                      Spi_GpFirstHWUnit, Spi_GaaCSIXRegs, Spi_GaaJobStatus,
**                      Spi_GaaSeqStatus
**
** Function Invoked   : Spi_CSIXProcessJob, Spi_ProcessSequence,
**                        Dem_ReportErrorStatus,
**
** Registers Used     : CSIXnSTR0
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMACompleteISR(
  CONST(uint32, AUTOMATIC) LulDMAUnitIndex)
/* References: SPI_DDD_ACT_030 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
#if (SPI_FIFO_MODE == STD_ON)
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(uint32, AUTOMATIC) LulChIndex;
#endif
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  /* If Internal Diagnosis Error Buffer size is Greater than Zero */
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
  VAR(uint16, AUTOMATIC) LusErrorStatus;
#endif

  /* MISRA Violation: START Msg(4:0491)-1 */
  LulHWUnitIndex = Spi_GpFirstDMAUnit[LulDMAUnitIndex].ucSPIHWUnit;
  /* END Msg(4:0491)-1 */
  LpHWStat = &Spi_GaaHWStatus[LulHWUnitIndex];
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LpHWStat->usOngoingJobIndex];
  /* END Msg(4:0491)-1 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

  /* Clear DMA completion flag */
  /* MISRA Violation: START Msg(4:0491)-1 */
  SPI_DMA_WRITE_VERIFY_CLEAR_TCC(LulDMAUnitIndex)
  /* END Msg(4:0491)-1 */
  /* References: SPI_DDD_ACT_030_REG002 */

  /* Check whether any error has been occurred during a Channel */
  if ((uint32)SPI_ZERO != (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0 &
     ((uint32)LpHWInfo->usSTCR0MaskValue & (uint32)SPI_CSIX_ERR_MASK)))
  /* References: SPI_DDD_ACT_030_ERR001 */
  {
#if defined(SPI_E_HARDWARE_ERROR)
    Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
    /* Get error value from status register */
    LusErrorStatus = (uint16)Spi_GaaCSIXRegs[
      LpHWInfo->ucPhysicalIndex].pCSIXSTRegs->ulSTR0;
    /* Check and store error information to RAM buffer */
    Spi_CheckAndStoreErrorInfo(LulHWUnitIndex, LusErrorStatus);
#endif
    /* Clear all status bits */
    SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
        LpHWInfo->usSTCR0MaskValue)
    /* References: SPI_DDD_ACT_030_REG001 */
    /* Check for writing register */
    SPI_CSIX_VERIFY_WRITE_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0, (uint32)SPI_ZERO,
      ((uint32)LpHWInfo->usSTCR0MaskValue), 32, SPI_ASYNCTRANSMIT_SID)
    /* Update Job result as FAILED */
    Spi_GaaJobStatus[Spi_GaaHWStatus[
      LulHWUnitIndex].usOngoingJobIndex].enResult = SPI_JOB_FAILED;
    /* References: SPI_DDD_ACT_030_GBL001 */
    /* A least one Job failed, set sequence failed flag */
    Spi_GaaSeqStatus[Spi_GaaHWStatus[
      LulHWUnitIndex].ucOngoingSeqIndex].blFailed = SPI_TRUE;
    /* References: SPI_DDD_ACT_030_GBL002 */
  }
  else
  {
    /* Nothing to do */
  }

  /* Check whether direct access mode is used */
  if ((SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode)
#if (SPI_FIFO_MODE == STD_ON)
    || ((SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode) &&
    (SPI_FALSE == LpHWStat->blIsTxBufferFull))
#endif
  )
  {
    /* Set remaining buffers to be transmitted for on-going channel */
    LpHWStat->usRemainedTxCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_030_GBL003 */
    /* Set remaining buffers to be received for on-going channel */
    LpHWStat->usRemainedRxCount = SPI_ZERO;
    /* References: SPI_DDD_ACT_030_GBL004 */
    /* Increase channel count for next channel transmission */
    LpHWStat->ucTxChannelCount++;
    /* References: SPI_DDD_ACT_030_GBL005 */
    LpHWStat->ucRxChannelCount++;
    /* References: SPI_DDD_ACT_030_GBL006 */
  }
#if (SPI_FIFO_MODE == STD_ON)
  else if ((SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode) &&
    (SPI_TRUE == LpHWStat->blIsTxBufferFull))
  {
    /* Set remaining buffers to be transmitted for the on-going channel */
    LpHWStat->usRemainedTxCount =
      LpHWStat->usRemainedTxCount - (uint16)SPI_CSIH_HW_BUFFER_SIZE;
    /* References: SPI_DDD_ACT_030_GBL007 */
    /* Set remaining buffers to be received for the on-going channel */
    LpHWStat->usRemainedRxCount =
      LpHWStat->usRemainedRxCount - (uint16)SPI_CSIH_HW_BUFFER_SIZE;
    /* References: SPI_DDD_ACT_030_GBL008 */

    /* Get channel index according to on-going job and channel count */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */

    /* Increment tx pointer of the on-going channel according to data width */
    if (NULL_PTR != LpHWStat->pTxPtr)
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpHWStat->pTxPtr = LpHWStat->pTxPtr +
       (LpChConfig->ucByteSize *
       ((uint8)((uint8)SPI_CSIH_HW_BUFFER_SIZE - (uint8)SPI_ONE)));
      /* END Msg(4:0488)-2 */
      /* References: SPI_DDD_ACT_030_GBL009 */
    }
    else
    {
      /* Nothing to do */
    }
    /* Increment rx pointer of the on-going channel according to data width */
    if (NULL_PTR != LpHWStat->pRxPtr)
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpHWStat->pRxPtr =
        LpHWStat->pRxPtr + (LpChConfig->ucByteSize * SPI_CSIH_HW_BUFFER_SIZE);
      /* END Msg(4:0488)-2 */
      /* References: SPI_DDD_ACT_030_GBL010 */
    }
    else
    {
      /* Nothing to do */
    }
  }
#endif
#if (SPI_TX_ONLY_MODE == STD_ON)
  else if (SPI_MEMMODE_TX_ONLY == LpHWInfo->enMemoryMode)
  {
    /* Set Rx count for next job */
    LpHWStat->ucRxChannelCount = LpJobConfig->ucNoOfChannels;
    /* References: SPI_DDD_ACT_030_GBL011 */
  }
#endif
  else
  {
    /* Nothing to do */
  }

  /* Check if all channels of job already transmitted */
  if (LpHWStat->ucRxChannelCount == LpJobConfig->ucNoOfChannels)
  {
    /* Update Job status */
    if (SPI_JOB_FAILED !=
      Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult)
    {
      Spi_GaaJobStatus[LpHWStat->usOngoingJobIndex].enResult = SPI_JOB_OK;
      /* References: SPI_DDD_ACT_030_GBL012 */
    }
    else
    {
      /* Nothing to do */
    }
    /* When a job is completed, call Sequence scheduler */
    Spi_ProcessSequence(LulHWUnitIndex);
  }
  else
  {
    /* Otherwise, process the next Channel */
    Spi_CSIXProcessJob(SPI_FALSE, LpJobConfig, SPI_ASYNCTRANSMIT_SID);
  }
}
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
#endif /* #if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
   (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if (SPI_DMA_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXDMASetUp
**
** Service ID         : Not Applicable
**
** Description        : This function is to setup DMA channels for Tx buffer and
**                      Rx buffer.
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig    - Pointer to the Job configuration.
**                      LpDefaultData  - Pointer to the Channel default data.
**                      LpHWStat       - Pointer to the HW status structure.
**                      LusRxCount     - The number of Rx data needs to be
**                                       received by Rx DMA channel.
**                      LusTxCount     - The number of Tx data needs to be
**                                       transmitted by Tx DMA channel.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : None
**
** Function Invoked   : Spi_DMAStart
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMASetUp(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2CONST(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONSTP2CONST(uint32, AUTOMATIC, SPI_APPL_CONST) LpDefaultData,
  CONST(uint16, AUTOMATIC) LusRxCount,
  CONST(uint16, AUTOMATIC) LusTxCount)
/* References: SPI_DDD_ACT_077 */
{
  volatile P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LpDummyVar;

  /* Dummy data for each HW unit configured with DMA */
  LpDummyVar = &Spi_GaaDmaRxData[LpJobConfig->ucHWUnitIndex];

  /* Setup DMA for Rx side */
  if (SPI_INVALID_DMAUNIT != LpJobConfig->ucRxDmaIndex)
  {
    if (NULL_PTR != LpHWStat->pRxPtr)
    {
      /* If rx buffer isn't NULL, set pointer to rx buffer to DMA */
      /* QAC Warning: START Msg(2:3441)-3 */
      /* QAC Warning: START Msg(2:0314)-1 */
      Spi_DMAStart((uint32)LpJobConfig->ucRxDmaIndex,
        (volatile const void*)LpHWStat->pRxPtr,
        (uint32)LusRxCount,
        SPI_DMA_TCE | SPI_DMA_SACM_FIXED | SPI_DMA_DACM_UP | SPI_DMA_16BIT);
      /* END Msg(2:0314)-1 */
      /* END Msg(2:3441)-3 */
    }
    else
    {
      /* If rx buffer is NULL, set pointer to the dummy variable to DMA */
      /* QAC Warning: START Msg(2:0314)-1 */
      Spi_DMAStart((uint32)LpJobConfig->ucRxDmaIndex,
        (volatile const void*)LpDummyVar,
        (uint32)LusRxCount,
        SPI_DMA_TCE | SPI_DMA_SACM_FIXED | SPI_DMA_DACM_FIXED | SPI_DMA_16BIT);
      /* END Msg(2:0314)-1 */
    }
  }
  else
  {
    /* Nothing to do */
  }

  /* Setup DMA for Tx side */
  if ((SPI_INVALID_DMAUNIT != LpJobConfig->ucTxDmaIndex) &&
    (SPI_ZERO < LusTxCount))
  {
    if (NULL_PTR != LpHWStat->pTxPtr)
    {
      /* If tx buffer isn't NULL, set pointer to tx buffer to DMA */
      /* QAC Warning: START Msg(2:3441)-3 */
      /* QAC Warning: START Msg(2:0314)-1 */
      Spi_DMAStart((uint32)LpJobConfig->ucTxDmaIndex,
        (volatile const void*)LpHWStat->pTxPtr,
        (uint32)LusTxCount,
        SPI_DMA_DACM_FIXED | SPI_DMA_SACM_UP | SPI_DMA_16BIT);
      /* END Msg(2:0314)-1 */
      /* END Msg(2:3441)-3 */
    }
    else
    {
      /* If tx buffer is NULL, set pointer to the default data to DMA */
      /* QAC Warning: START Msg(2:0314)-1 */
      Spi_DMAStart((uint32)LpJobConfig->ucTxDmaIndex,
        (volatile const void*)LpDefaultData,
        (uint32)LusTxCount,
        SPI_DMA_DACM_FIXED | SPI_DMA_SACM_FIXED | SPI_DMA_16BIT);
      /* END Msg(2:0314)-1 */
    }
  }
  else
  {
    /* Nothing to do */
  }
}
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */

/*******************************************************************************
** Function Name          : Spi_CSIXDisableAllInterrupts
**
** Service ID             : NA
**
** Description            : This service disables interrupts for all CSIX units.
**
** Sync/Async             : Synchronous
**
** Re-entrancy            : Non-Reentrant
**
** Input Parameters       : None
**
** InOut Parameters       : None
**
** Output Parameters      : None
**
** Return parameter       : None
**
** Preconditions          : Global variables must be initialized
**
** Global Variable        : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function invoked       : None
**
** Registers Used         : EIC(CSIXnTIR), EIC(CSIXnTIC)
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDisableAllInterrupts(void)
/* References: SPI_DDD_ACT_032 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;

  for (LulHWUnitIndex = SPI_ZERO;
    LulHWUnitIndex < Spi_GpConfigPtr->ucNoOfHWUnits; LulHWUnitIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */

    /* Disable all interrupts unconditionally */
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_SET_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIR,
      (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_032_REG001 */
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_SET_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIC,
      (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_032_REG002 */
  }
}

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
/*******************************************************************************
** Function Name      : Spi_CSIXMainFunction_Handling
**
** Service ID         : Not Applicable
**
** Description        : This function performs the polling operation.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**                      Spi_GulCancelingHWUnits, Spi_GpFirstDMAUnit
**
** Function Invoked   : Spi_CSIXReceiveISR, Spi_CSIXTransmitISR,
**                      Spi_CSIXDMACompleteISR
**
** Registers Used     : EIC(CSIXnTIR), EIC(CSIXnTIC)
*******************************************************************************/
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMainFunction_Handling(void)
/* References: SPI_DDD_ACT_033 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
#if (SPI_DMA_CONFIGURED == STD_ON)
  P2CONST(Spi_DmaConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpDmaConfig;
  VAR(uint32, AUTOMATIC) LulDmaIndex;
  VAR(uint32, AUTOMATIC) LulTxAssignedToDma;
  VAR(uint32, AUTOMATIC) LulRxAssignedToDma;
#endif
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;

  /*
     Spi_GulCancelingHWUnits is modified by Spi_FoceCancel,
     but no critical section is required here for this variable.
     Because:
     - Spi_ForceCancel modify it in the interrupt disabled section.
     - Spi_ForceCancel can't be invoked in any higher priority task than
       Spi_MainFunction_Handling, so Spi_GulCancelHWUnits is never changed
       while this function is executing.
  */

  /* Scan DMA completions */
#if (SPI_DMA_CONFIGURED == STD_ON)
  LulTxAssignedToDma = SPI_ZERO;
  LulRxAssignedToDma = SPI_ZERO;
  for (LulDmaIndex = SPI_ZERO;
    LulDmaIndex < Spi_GpConfigPtr->ucNoOfDMAChannels; LulDmaIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpDmaConfig = &Spi_GpFirstDMAUnit[LulDmaIndex];
    /* END Msg(4:0491)-1 */

    if (SPI_TRUE == LpDmaConfig->blRxSide)
    {
      /* Invoke DMA ISR if the IRQ is asserted */
      if (
#if (SPI_FORCE_CANCEL_API == STD_ON)
        ((uint32)SPI_ZERO ==
          (Spi_GulCancelingHWUnits
          & ((uint32)SPI_ONE << LpDmaConfig->ucSPIHWUnit))) &&
#endif
        /* MISRA Violation: START Msg(4:0491)-1 */
        ((uint32)SPI_ZERO != SPI_DMA_CHECK_INTERRUPT_FLAG(LulDmaIndex)))
        /* END Msg(4:0491)-1 */
      {
        Spi_CSIXDMACompleteISR(LulDmaIndex);
      }
      else
      {
        /* Nothing to do */
      }
      /* If the rx side is using DMA, polling of CSIXnTIR is not necessary */
      LulRxAssignedToDma |= ((uint32)SPI_ONE << LpDmaConfig->ucSPIHWUnit);
    }
    else
    {
      /* If the tx side is using DMA, polling of CSIXnTIC is not necessary */
      LulTxAssignedToDma |= ((uint32)SPI_ONE << LpDmaConfig->ucSPIHWUnit);
    }
  }
#endif

  /* Scan CSIXnTIC and CSIXnTIR */
  for (LulHWUnitIndex = SPI_ZERO;
    LulHWUnitIndex < Spi_GpConfigPtr->ucNoOfHWUnits; LulHWUnitIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */

    if ((SPI_FALSE == LpHWInfo->blSynchronous)
#if (SPI_FORCE_CANCEL_API == STD_ON)
      && ((uint32)SPI_ZERO == (Spi_GulCancelingHWUnits
        & ((uint32)SPI_ONE << LulHWUnitIndex)))
#endif
      )
    {
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
      /* Tx interruption */
      if (
#if (SPI_DMA_CONFIGURED == STD_ON)
        ((uint32)SPI_ZERO == (LulTxAssignedToDma
        & ((uint32)SPI_ONE << LulHWUnitIndex))) &&
#endif
        (SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode) &&
        (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
          Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIC)
          & SPI_EIC_EIRF_MASK)))
      {
        /* Clear Tx interrupt request flag before starting next transmission */
        RH850_SV_CLEAR_ICR_SYNCP(16,
          Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIC,
          (uint16)(~SPI_EIC_EIRF_MASK));
        /* References: SPI_DDD_ACT_033_REG001 */
        Spi_CSIXTransmitISR(LulHWUnitIndex);
      }
      else
      {
        /* Nothing to do */
      }
#endif
      /* Rx interruption */
      if (
#if (SPI_DMA_CONFIGURED == STD_ON)
        ((uint32)SPI_ZERO == (LulRxAssignedToDma
        & ((uint32)SPI_ONE << LulHWUnitIndex))) &&
#endif
        (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
          Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIR)
          & SPI_EIC_EIRF_MASK)))
      {
#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
        /* To emulate the default interrupt priority (CSIXnTIC > CSIXnTIR),
           check CSIXnTIC again */
        if (
#if (SPI_DMA_CONFIGURED == STD_ON)
          ((uint32)SPI_ZERO == (LulTxAssignedToDma
          & ((uint32)SPI_ONE << LulHWUnitIndex))) &&
#endif
          (SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode) &&
          (SPI_ZERO != (RH850_SV_MODE_REG_READ_ONLY(16,
            Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIC)
            & SPI_EIC_EIRF_MASK)))
        {
          /* Clear Tx interrupt flag before starting next transmission */
          RH850_SV_CLEAR_ICR_SYNCP(16,
            Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIC,
            (uint16)(~SPI_EIC_EIRF_MASK));
          /* References: SPI_DDD_ACT_033_REG002 */
          Spi_CSIXTransmitISR(LulHWUnitIndex);
        }
        else
        {
          /* Nothing to do */
        }
#endif /* (DIRECT_ACCESS_MODE == STD_ON) */
        /* Clear Rx interrupt request flag */
        RH850_SV_CLEAR_ICR_SYNCP(16,
          Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pICTIR,
          (uint16)(~SPI_EIC_EIRF_MASK));
        /* References: SPI_DDD_ACT_033_REG003 */
        Spi_CSIXReceiveISR(LulHWUnitIndex);
      }
      else
      {
        /* Nothing to do */
      }
    }
    else
    {
      /* Nothing to do */
    }
  }
}
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

#if (((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) && \
  (SPI_FORCE_CANCEL_API == STD_ON))
/*******************************************************************************
** Function Name      : Spi_CSIXForceStop
**
** Service ID         : Not Applicable
**
** Description        : This function stops a CSIX unit unconditionally.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HWUnit.
**                      Non-Reentrant for same HWUnit.
**
** Input Parameters   : LulHWUnitIndex - Index of HW to be stopped.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : The interrupts of target HWUnit are disabled.
**
** Global Variable    : Spi_GpFirstHWUnit, Spi_GaaCSIXRegs, Spi_GpFirstJob,
**                      Spi_GaaHWStatus
**
** Function Invoked   : Spi_DMAStop, Spi_CSIXTurnOffUnit,
**                      Spi_CSIXMaskHWUnitInterrupts
**
** Registers Used     : EICn/ICxxx
*******************************************************************************/
FUNC(void, SPI_FAST_CODE) Spi_CSIXForceStop(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex)
/* References: SPI_DDD_ACT_034 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;

  /* Get pointer to job configuration */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig =
    &Spi_GpFirstJob[Spi_GaaHWStatus[LulHWUnitIndex].usOngoingJobIndex];
  /* END Msg(4:0491)-1 */

  /* Mask all interrupts of HW unit */
  Spi_CSIXMaskHWUnitInterrupts(
    LpJobConfig, SPI_TRUE, SPI_TRUE, SPI_TRUE);

  /* Stop SPI unit by CTL0.PWR = 0 do dummy read */
  Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, SPI_FORCECANCEL_SID);

#if (SPI_DMA_CONFIGURED == STD_ON)
  /* Stop DMA */
  if (SPI_INVALID_DMAUNIT != LpJobConfig->ucRxDmaIndex)
  {
    /* Stop Rx DMA */
    Spi_DMAStop((uint32)LpJobConfig->ucRxDmaIndex);
  }
  else
  {
    /* Nothing to do */
  }
  if (SPI_INVALID_DMAUNIT != LpJobConfig->ucTxDmaIndex)
  {
    /* Stop Tx DMA */
    Spi_DMAStop((uint32)LpJobConfig->ucTxDmaIndex);
  }
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */
}
#endif /* (((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) && \
  (SPI_FORCE_CANCEL_API == STD_ON)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/*******************************************************************************
** Function Name      : Spi_CSIXMaskHWUnitInterrupts
**
** Service ID         : NA
**
** Description        : This function manipulates interrupt masks of a HWUnit,
**                      including DMA interrupts if available.
**                      This function modifies EIMK bit only,
**                      EIRF bit is not affected.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HWUnit
**                      Non-Reentrant for same HWUnit
**
** Input Parameters   : LpJobConfig - Pointer to the Job configuration.
**                      LblMask - Flag to mask DMA and Rx interrupt.
**                                TRUE: set mask FALSE: reset mask
**                      LblTxMask - Flag to mask DMA and Tx interrupt.
**                                  TRUE: set mask FALSE: reset mask
**                      LblClearEIRF  - TRUE: clear interrupt request
**                                    - FAlSE: do not clear interrupt request
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Global variables must be initialized.
**
** Global Variable    : Spi_GpFirstHWUnit
**
** Function invoked   : Spi_DMAMaskHWUnitInterrupts,
**                      Spi_CSIXMaskHWUnitRxInterrupt,
**                      Spi_CSIXMaskHWUnitTxInterrupt,
**                      SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitInterrupts(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblTxMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF)
/* References: SPI_DDD_ACT_035 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */

#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  if (SPI_FALSE == LpHWInfo->blSynchronous)
#endif
  {
    /* INTERRUPT_PROTECTION is required to avoid ISR occur
       while EIMK is being set */
    SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_035_CRT001 */
    /* Write the lower byte of EIC registers to avoid modifing EIRF bit */
#if (SPI_DMA_CONFIGURED == STD_ON)
    if (SPI_INVALID_DMAUNIT != LpJobConfig->ucRxDmaIndex)
    {
      /* Mask DMA interrupt */
      Spi_DMAMaskHWUnitInterrupts(
        (uint32)LpJobConfig->ucRxDmaIndex, LblMask, LblClearEIRF);
    }
    else
#endif
    {
      /* Mask Rx interrupt */
      Spi_CSIXMaskHWUnitRxInterrupt(
        (uint32)LpHWInfo->ucPhysicalIndex, LblMask, LblClearEIRF);
      if (SPI_MEMMODE_DIRECT_ACCESS == LpHWInfo->enMemoryMode)
      {
        /* Mask Tx interrupt */
        Spi_CSIXMaskHWUnitTxInterrupt(
          (uint32)LpHWInfo->ucPhysicalIndex, LblTxMask, LblClearEIRF);
      }
      else
      {
        /* Nothing to do */
      }
    }
    SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_035_CRT002 */
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  else
  {
    /* Nothing to do */
  }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if (SPI_FIFO_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXStartChannelFifoMode
**
** Service ID         : Not Applicable
**
** Description        : This function writes data to HW Buffer and
**                      starts transmission on Fifo mode on CSIH.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GaaCSIXRegs, Spi_GpFirstChannel, Spi_GenAsyncMode
**
** Function Invoked   : Spi_HWBufferLoadTxData, Spi_CSIXMaskHWUnitRxInterrupt
**
** Registers Used     : CSIHnMCTL1
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
 /* References: SPI_DDD_ACT_036 */
{
  volatile P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpTxDataPtr;
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Spi_NumberOfDataType, AUTOMATIC) LusNoOfChBuffers;
  VAR(Spi_NumberOfDataType, AUTOMATIC) LusNoOfTxBuffers;
  VAR(Spi_NumberOfDataType, AUTOMATIC)
    LaaNoOfTxBuffers[SPI_CSIH_HW_BUFFER_SIZE];
  VAR(uint32, AUTOMATIC) LaaTxPtr[SPI_CSIH_HW_BUFFER_SIZE];
  VAR(uint16, AUTOMATIC) LusNoOfTxChannels;
  VAR(uint16, AUTOMATIC) LusMaxNoOfFiFoBuffers;
  VAR(uint32, AUTOMATIC) LulChIndex;
  VAR(uint16, AUTOMATIC) LusChCount;
  VAR(uint32, AUTOMATIC) LulMCTL1RegValue;

  /* Initialize channel count as zero */
  LusChCount = SPI_ZERO;
  /* Initialize Tx buffers loaded into HW */
  LusNoOfTxBuffers = SPI_ZERO;
  /* Initialize HW buffers size */
  LusMaxNoOfFiFoBuffers = SPI_CSIH_HW_BUFFER_SIZE;
  /* Initialize the number of channels transmitted */
  LusNoOfTxChannels = LpHWStat->ucTxChannelCount;

  /* Interrupt protection is not necessary in loop */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* QAC Warning: START Msg(2:3416)-10 */
  if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
  /* END Msg(2:3416)-10 */
#endif
  {
    /* Clear Rx pending interrupt and un-mask Rx interrupt */
    Spi_CSIXMaskHWUnitRxInterrupt(
      LulHWPhyIndex, SPI_FALSE, SPI_TRUE);
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

  /* Loop to find channels in jobs and number of data to be transmitted */
  do
  {
    /* Get channel index according to on-going job and channel count */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */

    /* Calculate Max Number Of FIFO Buffers */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      LusMaxNoOfFiFoBuffers = (uint16)(LusMaxNoOfFiFoBuffers >> SPI_ONE);
    }
    else
#endif
    {
      LusMaxNoOfFiFoBuffers = LusMaxNoOfFiFoBuffers;
    }

    /* Check whether HW buffer is full */
    if (SPI_FALSE == LpHWStat->blIsTxBufferFull)
    {
    /* Prepare channel buffers */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
      if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
      {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
        /* Initialize rx/tx pointers to point to IB */
        LpHWStat->pTxPtr = LpChConfig->pTxBuffer;
        /* References: SPI_DDD_ACT_036_GBL001 */
        LpHWStat->usRemainedTxCount = LpChConfig->usNoOfBuffers;
        /* References: SPI_DDD_ACT_036_GBL002 */
#endif
      }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
      else
#endif
      {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
        /* Initialize rx/tx pointers to point to EB */
        LpHWStat->pTxPtr = LpChConfig->pEBData->pSrcPtr;
            /* References: SPI_DDD_ACT_036_GBL003 */
        LpHWStat->usRemainedTxCount = LpChConfig->pEBData->usEBLength;
            /* References: SPI_DDD_ACT_036_GBL004 */
#endif
      }
    }
    else
    {
      /* Nothing to do */
    }

    /* Load the number of buffers of channel or remaining buffers in channel */
    LusNoOfChBuffers = LpHWStat->usRemainedTxCount;
    /* Store buffer pointer to transmit */
    /* MISRA Violation: START Msg(4:0303)-4 */
    LaaTxPtr[(uint32)LusChCount] = (uint32)LpHWStat->pTxPtr;
    /* END Msg(4:0303)-4 */

    /* Check whether the number of data to transmit is less than HW buffer */
    if (LusMaxNoOfFiFoBuffers >= LusNoOfChBuffers)
    {
      /* HW buffer is not full */
      LpHWStat->blIsTxBufferFull = SPI_FALSE;
      /* References: SPI_DDD_ACT_036_GBL005 */
      /* Set remaining number of buffer to transmit of this channel */
      LpHWStat->usRemainedTxCount = SPI_ZERO;
      /* References: SPI_DDD_ACT_036_GBL006 */
      /* Increment the channel list to point to next channel */
      LpHWStat->ucTxChannelCount++;
      /* References: SPI_DDD_ACT_036_GBL007 */
      /* Increase the number of channels transmitted */
      LusNoOfTxChannels++;
      /* Save max number of fifo buffers can be used to load next channel */
      LusMaxNoOfFiFoBuffers =
        (uint16)(LusMaxNoOfFiFoBuffers - LusNoOfChBuffers);
    }
    else
    {
      /* Set a flag to indicate PAUSE of transferring this channel */
      LpHWStat->blIsTxBufferFull = SPI_TRUE;
      /* References: SPI_DDD_ACT_036_GBL008 */
      /* Go to next data in channel buffer */
      if (NULL_PTR != LpHWStat->pTxPtr)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpHWStat->pTxPtr = LpHWStat->pTxPtr +
          (LusMaxNoOfFiFoBuffers * LpChConfig->ucByteSize);
        /* END Msg(4:0488)-2 */
          /* References: SPI_DDD_ACT_036_GBL009 */
      }
      else
      {
        /* Nothing to do */
      }
      /* Set remaining number of buffer to transmit */
      LpHWStat->usRemainedTxCount =
        (uint16)(LusNoOfChBuffers - LusMaxNoOfFiFoBuffers);
      /* References: SPI_DDD_ACT_036_GBL010 */
      /* Set number of buffer to be transmitted as maximum buffer size */
      LusNoOfChBuffers = LusMaxNoOfFiFoBuffers;
      /* To break loop when number of channel > size of buffer */
      LusNoOfTxChannels = LpJobConfig->ucNoOfChannels;
    }

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      /* Calculate number of available HW buffers with 16-bit word */
      LusMaxNoOfFiFoBuffers = (uint16)(LusMaxNoOfFiFoBuffers << SPI_ONE);
      /* Accumulate number of buffer to be transmitted in 16-bit word */
      LusNoOfTxBuffers =
        LusNoOfTxBuffers + (uint16)(LusNoOfChBuffers << SPI_ONE);
    }
    else
#endif
    {
      /* Accumulate number of buffer to be transmitted in 16-bit word */
      LusNoOfTxBuffers = LusNoOfTxBuffers + LusNoOfChBuffers;
    }

    /* Store the numbers of buffer transmitted for each channel */
    LaaNoOfTxBuffers[(uint32)LusChCount] = LusNoOfChBuffers;
    /* Increase channel count */
    LusChCount++;

    /* Break loop if there is no channel to transmit
       or number of buffer of channel is equal to HW buffer size */
  }while ((LpJobConfig->ucNoOfChannels > LusNoOfTxChannels) &&
    (SPI_ZERO != LusMaxNoOfFiFoBuffers));

  /* Set condition for receive interrupt */
  LulMCTL1RegValue =
     (uint32)((uint32)SPI_CSIH_HW_BUFFER_SIZE - (uint32)LusNoOfTxBuffers);
  SPI_CSIX_WRITE_VERIFY_AND_MIRROR_RUNTIME(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL1, LulMCTL1RegValue,
    &Spi_GaaCSIHRegMirror[LpJobConfig->ucHWUnitIndex].ulMCTL1,
    CTLREG_32_BIT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
  /* References: SPI_DDD_ACT_036_REG001 */

  /* Store number of channels to be transmitted */
  LusNoOfTxChannels = LusChCount;
  /* Initialize channel count as zero */
  LusChCount = SPI_ZERO;

  /* Loop to write data to HW buffer until it is full */
  do
  {
    /* Get channel index according to on-going job and channel count */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[LusChCount];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0303)-4 */
    LpTxDataPtr =
      (volatile P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA))
      (LaaTxPtr[(uint32)LusChCount]);
    /* END Msg(4:0303)-4 */
    /* Write all data of channel to HW buffer */
    Spi_HWBufferLoadTxData(LpChConfig,
      LpTxDataPtr, LaaNoOfTxBuffers[(uint32)LusChCount], LulHWPhyIndex);

    /* Increase channel count */
    LusChCount++;
    /* Break loop if there is no channel to transmit */
  }while (LusChCount < LusNoOfTxChannels);
}

#if (SPI_DMA_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXDMAStartChannelFifoMode
**
** Service ID         : Not Applicable
**
** Description        : This function writes data to HW Buffer and
**                      starts transmission on Fifo mode on CSIH.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GaaCSIXRegs, Spi_GpFirstChannel, Spi_GenAsyncMode
**
** Function Invoked   : Spi_CSIXDMASetUp, Spi_DMAMaskHWUnitInterrupts
**                      SPI_DMA_SW_REQ
**
** Registers Used     : CSIHnMCTL1, DCSTSn
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXDMAStartChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
 /* References: SPI_DDD_ACT_078 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Spi_NumberOfDataType, AUTOMATIC) LusNoOfChBuffers;
  VAR(uint32, AUTOMATIC) LulChIndex;
  VAR(uint32, AUTOMATIC) LulTxData;
  VAR(uint32, AUTOMATIC) LulMCTL1RegValue;

  /* Interrupt protection is not necessary in loop */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* QAC Warning: START Msg(2:3416)-10 */
  if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
  /* END Msg(2:3416)-10 */
#endif
  {
    /* Clear DMA pending interrupt and un-mask DMA interrupt */
    Spi_DMAMaskHWUnitInterrupts(
      (uint32)LpJobConfig->ucRxDmaIndex, SPI_FALSE, SPI_TRUE);
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

  /* Get channel index according to on-going job and channel count */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LulChIndex = LpJobConfig->pChannelList[LpHWStat->ucTxChannelCount];
  /* END Msg(4:0491)-1 */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel[LulChIndex];
  /* END Msg(4:0491)-1 */

  /* Check whether HW buffer is full */
  if (SPI_FALSE == LpHWStat->blIsTxBufferFull)
  {
    /* Prepare channel buffers in FIFO mode */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
    if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
    {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
      /* Initialize rx/tx pointers to point to IB */
      LpHWStat->pTxPtr = LpChConfig->pTxBuffer;
      /* References: SPI_DDD_ACT_078_GBL001 */
      LpHWStat->pRxPtr = LpChConfig->pRxBuffer;
      /* References: SPI_DDD_ACT_078_GBL002 */
      LpHWStat->usRemainedTxCount = LpChConfig->usNoOfBuffers;
      /* References: SPI_DDD_ACT_078_GBL003 */
      LpHWStat->usRemainedRxCount = LpChConfig->usNoOfBuffers;
      /* References: SPI_DDD_ACT_078_GBL004 */
#endif
    }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
    else
#endif
    {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
      /* Initialize rx/tx pointers to point to EB */
      LpHWStat->pTxPtr = LpChConfig->pEBData->pSrcPtr;
      /* References: SPI_DDD_ACT_078_GBL005 */
      LpHWStat->pRxPtr = LpChConfig->pEBData->pDestPtr;
      /* References: SPI_DDD_ACT_078_GBL006 */
      LpHWStat->usRemainedTxCount = LpChConfig->pEBData->usEBLength;
      /* References: SPI_DDD_ACT_078_GBL007 */
      LpHWStat->usRemainedRxCount = LpChConfig->pEBData->usEBLength;
      /* References: SPI_DDD_ACT_078_GBL008 */
#endif
    }
  }
  else
  {
    /* Nothing to do */
  }

  /* Check whether the number of data transmitted is less than HW buffer */
  if (SPI_CSIH_HW_BUFFER_SIZE >= LpHWStat->usRemainedTxCount)
  {
    /* HW buffer is not full */
    LpHWStat->blIsTxBufferFull = SPI_FALSE;
    /* References: SPI_DDD_ACT_078_GBL009 */
    /* Set the number of buffers to transmitted/received as Ch buffer size */
    LusNoOfChBuffers = LpHWStat->usRemainedTxCount;
  }
  else
  {
    /* Set a flag to indicate PAUSE of transferring this channel */
    LpHWStat->blIsTxBufferFull = SPI_TRUE;
    /* References: SPI_DDD_ACT_078_GBL010 */
    /* Set the number of buffers to transmitted/received as max buffer size */
    LusNoOfChBuffers = SPI_CSIH_HW_BUFFER_SIZE;
  }

  /* Prepare first data including CS setting */
  LulTxData = SPI_CSIH_CS(LpJobConfig->ucCSIHCSInfo);
  /* QAC Warning: START Msg(2:3441)-3 */
  Spi_LoadTxData(LpHWStat->pTxPtr, LpChConfig, &LulTxData, NULL_PTR);
  /* END Msg(2:3441)-3 */
  /* Increment tx pointer according to data width */
  if (NULL_PTR != LpHWStat->pTxPtr)
  {
    /* MISRA Violation: START Msg(4:0488)-2 */
    LpHWStat->pTxPtr = LpHWStat->pTxPtr + LpChConfig->ucByteSize;
    /* END Msg(4:0488)-2 */
    /* References: SPI_DDD_ACT_078_GBL011 */
  }
  else
  {
    /* Nothing to do */
  }

  /* Set condition for receive interrupt as HW trigger request for Rx DMA */
  LulMCTL1RegValue =
    (uint32)((uint32)SPI_CSIH_HW_BUFFER_SIZE - (uint32)LusNoOfChBuffers);
  SPI_CSIX_WRITE_VERIFY_AND_MIRROR_RUNTIME(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL1, LulMCTL1RegValue,
    &Spi_GaaCSIHRegMirror[LpJobConfig->ucHWUnitIndex].ulMCTL1,
    CTLREG_32_BIT_MASK, 32, SPI_ASYNCTRANSMIT_SID)
  /* References: SPI_DDD_ACT_078_REG001 */

  /* Write first data into CSIHTX0W register */
  SPI_WRITE_REG_ONLY(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulTX0W, LulTxData)
  /* References: SPI_DDD_ACT_078_REG002 */

  /* Setup for DMA block transfer */
  Spi_CSIXDMASetUp(LpJobConfig, LpHWStat, &LpChConfig->ulDefaultData,
    LusNoOfChBuffers, (uint16)(LusNoOfChBuffers - SPI_ONE));

  /* Write remaining Tx data by DMA block transfer if any */
  if (SPI_ONE < LpHWStat->usRemainedTxCount)
  {
    /* SW DMA transfer request for Tx side to start transmission */
    /* MISRA Violation: START Msg(4:0491)-1 */
    SPI_DMA_SW_REQ(LpJobConfig->ucTxDmaIndex);
    /* END Msg(4:0491)-1 */
    /* References: SPI_DDD_ACT_078_REG003 */
  }
  else
  {
    /* Nothing to do */
  }
}
#endif /* (SPI_DMA_CONFIGURED == STD_ON) */

/*******************************************************************************
** Function Name      : Spi_CSIXReceiveChannelFifoMode
**
** Service ID         : Not Applicable
**
** Description        : This function receive data to Rx Buffer from HW buffer
**                      in FIFO mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel
**
** Function Invoked   : Spi_HWBufferStoreRxData
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelFifoMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_037 */
{
  volatile P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpRxDataPtr;
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  VAR(Spi_NumberOfDataType, AUTOMATIC) LusNoOfBuffers;
  VAR(uint16, AUTOMATIC) LusNoOfRxChannels;
  VAR(uint16, AUTOMATIC) LusMaxNoOfFiFoBuffers;
  VAR(uint32, AUTOMATIC) LulChIndex;

  /* Initialize the number of channel */
  LusNoOfRxChannels = LpHWStat->ucRxChannelCount;
  /* Initialize maximum size of 16-bit HW buffer */
  LusMaxNoOfFiFoBuffers = SPI_CSIH_HW_BUFFER_SIZE;

  /* Loop to write data to HW buffer until it is full */
  do
  {
    /* Get channel index accoding to on-going job anc channel count */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LulChIndex = LpJobConfig->pChannelList[LpHWStat->ucRxChannelCount];
    /* END Msg(4:0491)-1 */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpChConfig = &Spi_GpFirstChannel[LulChIndex];
    /* END Msg(4:0491)-1 */

    /* Calculate Max Number Of FIFO Buffers */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      LusMaxNoOfFiFoBuffers = (uint16)(LusMaxNoOfFiFoBuffers >> SPI_ONE);
    }
    else
#endif
    {
      LusMaxNoOfFiFoBuffers = LusMaxNoOfFiFoBuffers;
    }

    /* Check whether HW buffer is full */
    if (SPI_FALSE == LpHWStat->blIsRxBufferFull)
    {
    /* Prepare channel buffers */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
      if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
      {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
        /* Initialize rx/Rx pointers to point to IB */
        LpHWStat->pRxPtr = LpChConfig->pRxBuffer;
        /* References: SPI_DDD_ACT_037_GBL001 */
        LpHWStat->usRemainedRxCount = LpChConfig->usNoOfBuffers;
        /* References: SPI_DDD_ACT_037_GBL002 */
#endif
      }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
      else
#endif
      {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
     (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
        /* Initialize rx/Rx pointers to point to EB */
        LpHWStat->pRxPtr = LpChConfig->pEBData->pDestPtr;
        /* References: SPI_DDD_ACT_037_GBL003 */
        LpHWStat->usRemainedRxCount = LpChConfig->pEBData->usEBLength;
        /* References: SPI_DDD_ACT_037_GBL004 */
#endif
      }
    }
    else
    {
      /* Do nothing */
    }

    /* Load the data from RAM */
    LpRxDataPtr = LpHWStat->pRxPtr;
    LusNoOfBuffers = LpHWStat->usRemainedRxCount;

    /* Check whether the number of data to receive is less than HW buffer */
    if (LusMaxNoOfFiFoBuffers >= LusNoOfBuffers)
    {
      /* HW buffer is not full */
      LpHWStat->blIsRxBufferFull = SPI_FALSE;
      /* References: SPI_DDD_ACT_037_GBL005 */
      /* Set remaining number of buffers to receive of this channel */
      LpHWStat->usRemainedRxCount = SPI_ZERO;
      /* References: SPI_DDD_ACT_037_GBL006 */
      /* Increment the channel list to point to next channel */
      LpHWStat->ucRxChannelCount++;
      /* References: SPI_DDD_ACT_037_GBL007 */
      /* Increment the number of channels */
      LusNoOfRxChannels++;
      /* Save max number of fifo buffers can be used to load next channel */
      LusMaxNoOfFiFoBuffers = (uint16)(LusMaxNoOfFiFoBuffers - LusNoOfBuffers);
      /* Calculate number of available HW buffers with 16-bit word */
    }
    else
    {
      /* Set a flag to indicate PAUSE of receiving this channel */
      LpHWStat->blIsRxBufferFull = SPI_TRUE;
      /* References: SPI_DDD_ACT_037_GBL008 */
      /* Go to next Rx data pointer in channel buffer */
      if (NULL_PTR != LpHWStat->pRxPtr)
      {
        /* MISRA Violation: START Msg(4:0488)-2 */
        LpHWStat->pRxPtr = LpHWStat->pRxPtr +
          (LusMaxNoOfFiFoBuffers * LpChConfig->ucByteSize);
        /* END Msg(4:0488)-2 */
          /* References: SPI_DDD_ACT_037_GBL009 */
      }
      else
      {
        /* Nothing to do */
      }
      /* Set remaining number of buffer to receive */
      LpHWStat->usRemainedRxCount =
        (uint16)(LusNoOfBuffers - LusMaxNoOfFiFoBuffers);
      /* References: SPI_DDD_ACT_037_GBL010 */
      /* Set number of buffer to be received as maximum buffer size */
      LusNoOfBuffers = LusMaxNoOfFiFoBuffers;
      /* To break loop when number of channel > size of buffer */
      LusNoOfRxChannels = LpJobConfig->ucNoOfChannels;
    }

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
      {
        LusMaxNoOfFiFoBuffers = (uint16)(LusMaxNoOfFiFoBuffers << SPI_ONE);
      }
      else
      {
        /* Nothing to do */
      }
#endif

    /* Read all data of channel from HW buffer */
    Spi_HWBufferStoreRxData(
      LpChConfig, LpRxDataPtr, LusNoOfBuffers, LulHWPhyIndex);

    /* Break loop if there is no channel to transmit
       or number of buffer of channel is equal to HW buffer size */
  }while ((LpJobConfig->ucNoOfChannels > LusNoOfRxChannels) &&
         (SPI_ZERO != LusMaxNoOfFiFoBuffers));
}
#endif /* (SPI_FIFO_MODE == STD_ON) */

#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON))
/*******************************************************************************
** Function Name      : Spi_HWBufferLoadTxData
**
** Service ID         : Not Applicable
**
** Description        : This function loads data to the CSIH hardware buffer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpJobConfig    - Pointer to the Job configuration.
**                      LpChConfig     - Pointer to the Channel configuration.
**                      LpTxPtr        - Pointer to the transmission Channel
**                                       buffer.
**                      LusNoOfBuffers - Numbers of buffer to write into HW
**                                       buffer.
**                      LulHWPhyIndex  - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Spi_GaaCSIXRegs
**
** Function Invoked   : Spi_LoadTxData
**
** Registers Used     : CSIHnTX0W
*******************************************************************************/
static FUNC(void, SPI_FAST_CODE) Spi_HWBufferLoadTxData(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpTxPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) LusNoOfBuffers,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_038 */
{
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulTxData;
  VAR(uint16, AUTOMATIC) LusNoOfTxBuffers;

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  /* Second half of 32bit data that will be written in the next transmission */
  volatile VAR(uint32, AUTOMATIC) ulTxSecondWord;
  ulTxSecondWord = SPI_ZERO;
#endif
  LusNoOfTxBuffers = LusNoOfBuffers;

  /* Get the pointer to the post-build structure of job linked to the channel */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LpChConfig->ulFirstJobIndex];
  /* END Msg(4:0491)-1 */

  /* Loop to load all data of channel into HW buffer*/
  do
  {
    /* Set CS field of TX0W register */
    LulTxData = SPI_CSIH_CS(LpJobConfig->ucCSIHCSInfo);

    /* Prepare TX0W register value(s) */
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    /* Send second data if DataWidth is longer than 16 */
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      Spi_LoadTxData(LpTxPtr, LpChConfig,
        &LulTxData, &ulTxSecondWord);
      /* Load first data into HW buffer */
      SPI_WRITE_REG_ONLY(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulTX0W, LulTxData)
      /* References: SPI_DDD_ACT_038_REG001 */

      /* The second half of 32bit data, load second data into HW buffer */
      SPI_WRITE_REG_ONLY(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulTX0W, ulTxSecondWord)
      /* References: SPI_DDD_ACT_038_REG002 */
    }
    else
#endif
    {
      Spi_LoadTxData(LpTxPtr, LpChConfig,
          &LulTxData, NULL_PTR);
      /* Start transmission for first data */
      SPI_WRITE_REG_ONLY(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulTX0W, LulTxData)
      /* References: SPI_DDD_ACT_038_REG003 */
    }
    /* Increment tx pointer according to data width */
    if (NULL_PTR != LpTxPtr)
    {
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpTxPtr = LpTxPtr + LpChConfig->ucByteSize;
      /* END Msg(4:0488)-2 */
    }
    else
    {
      /* Nothing to do */
    }
    /* Decrement the counter for number of buffers */
    LusNoOfTxBuffers--;
  }while (SPI_ZERO < LusNoOfTxBuffers);
}
#endif /* ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON))*/

#if ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON))
/*******************************************************************************
** Function Name      : Spi_HWBufferStoreRxData
**
** Service ID         : Not Applicable
**
** Description        : This function loads data from CSIH hardware buffer to
**                      Channel destination buffer pointer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpChConfig     - Pointer to the Channel configuration.
**                      LpRxPtr        - Pointer to the receiving Channel buffer
**                      LusNoOfBuffers - Numbers of buffer needs to be read.
**                      LulHWPhyIndex  - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Spi_GaaCSIXRegs
**
** Function Invoked   : Spi_StoreRxData
**
** Registers Used     : CSIHnRX0W
*******************************************************************************/
static FUNC(void, SPI_FAST_CODE) Spi_HWBufferStoreRxData(
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  volatile P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpRxPtr,
  CONST(Spi_NumberOfDataType, AUTOMATIC) LusNoOfBuffers,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_039 */
{
  /* First half of 32bit data */
  /* QAC Warning: START Msg(2:3204)-7 */
  volatile VAR(uint16, AUTOMATIC) LusRxEDLFirstWord;
  /* END Msg(2:3204)-7 */
  /* Second half of 32bit data */
  volatile VAR(uint16, AUTOMATIC) LusSecondWord;
  VAR(uint16, AUTOMATIC) LusNoOfRxBuffers;

  /* Initialize local variables */
  LusRxEDLFirstWord = SPI_ZERO;
  LusSecondWord = SPI_ZERO;
  LusNoOfRxBuffers = LusNoOfBuffers;

  /* Loop to load all data of channel into Rx buffer pointer */
  do
  {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    /* Set EDL flag if DataWidth is longer than 16 */
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      /* If this is the first half of 32bit data, save the received data */
      LusRxEDLFirstWord = (uint16)(Spi_GaaCSIXRegs[
        LulHWPhyIndex].pCSIHRegs->ulRX0W);
      /* Receive and store data to memory */
      LusSecondWord = (uint16)(Spi_GaaCSIXRegs[
        LulHWPhyIndex].pCSIHRegs->ulRX0W);
    }
    else
#endif
    {
      /* Receive and store data to memory */
      LusSecondWord = (uint16)(Spi_GaaCSIXRegs[
        LulHWPhyIndex].pCSIHRegs->ulRX0W);
    }

    if (NULL_PTR != LpRxPtr)
    {
      /* QAC Warning: START Msg(2:3441)-3 */
      Spi_StoreRxData(LpRxPtr,
        LpChConfig, LusRxEDLFirstWord, LusSecondWord);
      /* END Msg(2:3441)-3 */
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpRxPtr = LpRxPtr + LpChConfig->ucByteSize;
      /* END Msg(4:0488)-2 */
    }
    else
    {
      /* Nothing to do */
    }
    /* Decrement the counter for number of buffers */
    LusNoOfRxBuffers--;
  }while (SPI_ZERO < LusNoOfRxBuffers);
}
#endif /* ((SPI_FIFO_MODE == STD_ON) || (SPI_DUAL_BUFFER_MODE == STD_ON)) */

#if (SPI_DIRECT_ACCESS_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXReceiveChannelDirectAccessMode
**
** Service ID         : Not Applicable
**
** Description        : This function receive data to Rx Buffer from Rx register
**                      in Direct access mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel
**
** Function Invoked   : Spi_StoreRxData, Spi_CSIXReadRX0Register
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelDirectAccessMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_040 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  /* Local to store date read from Rx register */
  VAR(uint16, AUTOMATIC) LusSecondWord;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel
    [LpJobConfig->pChannelList[LpHWStat->ucRxChannelCount]];
  /* END Msg(4:0491)-1 */

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  if (SPI_TRUE == LpHWStat->blRxEDLOngoing)
  {
    /* If this is the first half of 32bit data, save the received data */
    LpHWStat->blRxEDLOngoing = SPI_FALSE;
      /* References: SPI_DDD_ACT_040_GBL001 */
    LpHWStat->usRxEDLFirstWord = Spi_CSIXReadRX0Register(LulHWPhyIndex);
      /* References: SPI_DDD_ACT_040_GBL002 */
  }
  else
#endif
  {
    /* Receive and store data to memory */
    LusSecondWord = Spi_CSIXReadRX0Register(LulHWPhyIndex);
    if (NULL_PTR != LpHWStat->pRxPtr)
    {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        Spi_StoreRxData(LpHWStat->pRxPtr,
          LpChConfig, LpHWStat->usRxEDLFirstWord, LusSecondWord);
        /* END Msg(2:3441)-3 */
      }
      else
#endif
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        Spi_StoreRxData(LpHWStat->pRxPtr, LpChConfig, SPI_ZERO, LusSecondWord);
        /* END Msg(2:3441)-3 */
      }
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpHWStat->pRxPtr = LpHWStat->pRxPtr + LpChConfig->ucByteSize;
      /* END Msg(4:0488)-2 */
      /* References: SPI_DDD_ACT_040_GBL004 */
    }
    else
    {
      /* Nothing to do */
    }

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
      LpHWStat->blRxEDLOngoing = SPI_TRUE;
      /* References: SPI_DDD_ACT_040_GBL003 */
    }
    else
    {
      /* Nothing to do */
    }
#endif

    LpHWStat->usRemainedRxCount--;
    /* References: SPI_DDD_ACT_040_GBL005 */
    /* Check whether a Channel is finished */
    if (SPI_ZERO == LpHWStat->usRemainedRxCount)
    {
      /* Increase channel count for next channel */
      LpHWStat->ucRxChannelCount++;
      /* References: SPI_DDD_ACT_040_GBL006 */
      /* Check whether a Job is finished */
      if (LpHWStat->ucRxChannelCount < LpJobConfig->ucNoOfChannels)
      {
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
        if (SPI_FALSE == LpJobConfig->blChannelPropertySame)
        {
          /*
           * If ChannelProperty is not same, TxChannelCount is not updated
           * because TxISR never occur on the last data.
           * Hence update it here.
           */
          LpHWStat->ucTxChannelCount = LpHWStat->ucRxChannelCount;
          /* References: SPI_DDD_ACT_040_GBL007 */
        }
        else
#endif
        {
          /*
           * When a channel is completed and all channel properties are same,
           * setup buffer for the next channel and continue the operation.
           * Otherwise, call job scheduler.
           */
          /* MISRA Violation: START Msg(4:0491)-1 */
          LpChConfig = &Spi_GpFirstChannel
            [LpJobConfig->pChannelList[LpHWStat->ucRxChannelCount]];
          /* END Msg(4:0491)-1 */
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
          if (SPI_BUFFER_TYPE_IB == LpChConfig->enChannelBufferType)
#endif
          {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
            LpHWStat->pRxPtr = LpChConfig->pRxBuffer;
            /* References: SPI_DDD_ACT_040_GBL008 */
            LpHWStat->usRemainedRxCount = LpChConfig->usNoOfBuffers;
            /* References: SPI_DDD_ACT_040_GBL009 */
#endif
          }
#if (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB)
          else
#endif
          {
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == SPI_EB) || \
  (SPI_CHANNEL_BUFFERS_ALLOWED == SPI_IBEB))
            LpHWStat->pRxPtr = LpChConfig->pEBData->pDestPtr;
            /* References: SPI_DDD_ACT_040_GBL010 */
            LpHWStat->usRemainedRxCount = LpChConfig->pEBData->usEBLength;
            /* References: SPI_DDD_ACT_040_GBL011 */
#endif
          }
        } /* else (SPI_FALSE == LpJobConfig->blChannelPropertySame) */
      }/* else (LpHWStat->ucRxChannelCount == LpJobConfig->ucNoOfChannels) */
      else
      {
        /* Nothing to do */
      }
    } /* if (SPI_ZERO == LpHWStat->usRemainedRxCount) */
    else
    {
      /* Nothing to do */
    }
  } /* else (SPI_TRUE == LpHWStat->blRxEDLOngoing) */
}

#endif /* (SPI_DIRECT_ACCESS_MODE == STD_ON) */

#if (SPI_TX_ONLY_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXReceiveChannelTxOnlyMode
**
** Service ID         : Not Applicable
**
** Description        : This function receives data to RAM Buffer from Rx
**                      register in Tx-Only mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW.
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel
**
** Function Invoked   : Spi_StoreRxData, Spi_CSIXReadRX0Register
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReceiveChannelTxOnlyMode(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  volatile CONSTP2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_090 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  /* Local to store date read from Rx register */
  VAR(uint16, AUTOMATIC) LusSecondWord;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel
    [LpJobConfig->pChannelList[LpHWStat->ucRxChannelCount]];
  /* END Msg(4:0491)-1 */

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
  if (SPI_TRUE == LpHWStat->blRxEDLOngoing)
  {
    /* If this is the first half of 32bit data, save the received data */
    LpHWStat->blRxEDLOngoing = SPI_FALSE;
    /* References: SPI_DDD_ACT_090_GBL001 */
    LpHWStat->usRxEDLFirstWord = Spi_CSIXReadRX0Register(LulHWPhyIndex);
    /* References: SPI_DDD_ACT_090_GBL002 */
    /* Reduce the number of Rx count for each reception*/
    LpHWStat->usRemainedRxCount--;
    /* References: SPI_DDD_ACT_090_GBL007 */
  }
  else
#endif
  {
    /* Receive and store data to memory */
    LusSecondWord = Spi_CSIXReadRX0Register(LulHWPhyIndex);
    if (NULL_PTR != LpHWStat->pRxPtr)
    {
#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
      if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        Spi_StoreRxData(LpHWStat->pRxPtr,
          LpChConfig, LpHWStat->usRxEDLFirstWord, LusSecondWord);
        /* END Msg(2:3441)-3 */
      }
      else
#endif
      {
        /* QAC Warning: START Msg(2:3441)-3 */
        Spi_StoreRxData(LpHWStat->pRxPtr, LpChConfig, SPI_ZERO, LusSecondWord);
        /* END Msg(2:3441)-3 */
      }
      /* MISRA Violation: START Msg(4:0488)-2 */
      LpHWStat->pRxPtr = LpHWStat->pRxPtr + LpChConfig->ucByteSize;
      /* END Msg(4:0488)-2 */
      /* References: SPI_DDD_ACT_090_GBL004 */
    }
    else
    {
      /* Nothing to do */
    }

#if (SPI_EXTENDED_DATA_LENGTH == STD_ON)
    if (LpChConfig->ucDataWidth > SPI_CSIX_WORD)
    {
       LpHWStat->blRxEDLOngoing = SPI_TRUE;
       /* References: SPI_DDD_ACT_090_GBL003 */
    }
    else
    {
      /* Nothing to do */
    }
#endif

    /* Reduce the number of Rx count for each reception*/
    LpHWStat->usRemainedRxCount--;
    /* References: SPI_DDD_ACT_090_GBL005 */

    /* Check whether data of all channels in a job is finished */
    if (SPI_ZERO == LpHWStat->usRemainedRxCount)
    {
      /* Set Rx count for next job */
      LpHWStat->ucRxChannelCount = LpJobConfig->ucNoOfChannels;
      /* References: SPI_DDD_ACT_090_GBL006 */
    }
    else
    {
      /* Nothing to do */
    }
  }
}
#endif /* End of (SPI_TX_ONLY_MODE == STD_ON) */

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
/*******************************************************************************
** Function Name      : Spi_CSIXWriteHWIB
**
** Service ID         : Not Applicable
**
** Description        : This service writes the data into HW Buffer.
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LucChannel - Channel ID.
**                      LpDataBufferPtr - Pointer to source data buffer.
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel, Spi_GaaCSIXRegs, Spi_GpFirstJob,
**                      Spi_GpFirstHWUnit
**
** Function Invoked   : Spi_HWBufferLoadTxData
**
** Registers Used     : CSIHnMRWP0
*******************************************************************************/
/* QAC Warning: START Msg(2:3227)-8 */
/* QAC Warning: START Msg(2:3206)-6 */
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXWriteHWIB(
  CONST(Spi_ChannelType, AUTOMATIC) LucChannel,
  P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDataBufferPtr,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* END Msg(2:3227)-8 */
/* References: SPI_DDD_ACT_041 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulMRWP0RegValue;

  /* Get the pointer to the post-build structure of the channel */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel[LucChannel];
  /* END Msg(4:0491)-1 */

  /* Get the pointer to the post-build structure of job linked to the channel */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LpChConfig->ulFirstJobIndex];
  /* END Msg(4:0491)-1 */

  /* Index of CSIHn*/
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */

  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

  /* Load channel buffer index to CSIHMRWP0 to select start address of HW
     buffer to write data */
  LulMRWP0RegValue =
    (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMRWP0 & SPI_CSIH_TRWA_MASK) |
      LpChConfig->ulHWBufferIndex;
  SPI_WRITE_REG_ONLY(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMRWP0, LulMRWP0RegValue)
  /* References: SPI_DDD_ACT_041_REG001 */
  /* Check for Write verification */
  SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMRWP0,LulMRWP0RegValue,
    CTLREG_32_BIT_MASK, 32, LucApiId)

  /* Write all data of channel to HW buffer */
  Spi_HWBufferLoadTxData(LpChConfig, LpDataBufferPtr,
    LpChConfig->usNoOfBuffers, LulHWPhyIndex);
}
#endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON)) */

#if (SPI_DUAL_BUFFER_MODE == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXReadHWIB
**
** Service ID         : Not Applicable
**
** Description        : This service reads the data from HW Buffer.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LucChannel - Channel ID.
**                      LpDataBufferPtr - Pointer to destination data buffer.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GpFirstChannel, Spi_GaaCSIXRegs, Spi_GpFirstJob,
**                      Spi_GpFirstHWUnit
**
** Function Invoked   : Spi_HWBufferStoreRxData
**                      Spi_CSIXTurnOffUnit, Spi_CSIXTurnOnUnit
**
** Registers Used     : CSIHnMRWP0
*******************************************************************************/
/* QAC Warning: START Msg(2:3227)-8 */
FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXReadHWIB(
  CONST(Spi_ChannelType, AUTOMATIC) LucChannel,
  P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LpDataBufferPtr
)
/* END Msg(2:3227)-8 */
/* References: SPI_DDD_ACT_042 */
{
  P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulMRWP0RegValue;

  /* Get the pointer to the post-build structure of the channel */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpChConfig = &Spi_GpFirstChannel[LucChannel];
  /* END Msg(4:0491)-1 */

  /* Get the pointer to the post-build structure of job linked to the channel */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpJobConfig = &Spi_GpFirstJob[LpChConfig->ulFirstJobIndex];
  /* END Msg(4:0491)-1 */

  /* Index of CSIHn*/
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */

  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

  /* Set PWR to provide operate clock to start reading data */
  Spi_CSIXTurnOnUnit(LpJobConfig->ucHWUnitIndex, SPI_READIB_SID);

  /* Load channel buffer index to CSIHMRWP0 to select start address of HW
     buffer to read data */
  LulMRWP0RegValue =
    (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMRWP0 & SPI_CSIH_RRA_MASK) |
      SPI_CSIH_SET_RRA(LpChConfig->ulHWBufferIndex);
  SPI_WRITE_REG_ONLY(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMRWP0, LulMRWP0RegValue)
  /* References: SPI_DDD_ACT_042_REG001 */

  /* Read all data corresponding to channel from HW buffer */
  Spi_HWBufferStoreRxData(LpChConfig, LpDataBufferPtr,
    LpChConfig->usNoOfBuffers, LulHWPhyIndex);

  /* Clear PWR to stop operate clock after reading data */
  Spi_CSIXTurnOffUnit(LpJobConfig->ucHWUnitIndex, SPI_READIB_SID);
}
#endif /* End of (SPI_DUAL_BUFFER_MODE == STD_ON) */

#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
/*******************************************************************************
** Function Name      : Spi_CSIXStartChannelHwBuffer
**
** Service ID         : Not Applicable
**
** Description        : This function is to trigger transmission on CSIH
**                      configured as Dual buffer or Tx only mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HW, Non-Reentrant for same HW
**
** Input Parameters   : LpJobConfig   - Pointer to the Job configuration.
**                      LpHWStat      - Pointer to the HW status structure.
**                      LulHWPhyIndex - Physical index of the HWUnit.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GaaCSIXRegs, Spi_GenAsyncMode
**
** Function Invoked   : Spi_CSIXMaskHWUnitInterrupts
**
** Registers Used     : CSIHnMCTL2
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXStartChannelHwBuffer(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONSTP2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpChConfig,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
 /* References: SPI_DDD_ACT_043 */
{
  VAR(uint32, AUTOMATIC) LulMCTL2RegValue;
  /* Interrupt protection is not necessary in loop */
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  /* QAC Warning: START Msg(2:3416)-10 */
  if (SPI_INTERRUPT_MODE == Spi_GenAsyncMode)
  /* END Msg(2:3416)-10 */
#endif
  {
    /* Enable Rx interrupt and Rx DMA only if Rx DMA is configured */
    Spi_CSIXMaskHWUnitInterrupts(
      LpJobConfig, SPI_FALSE, SPI_TRUE, SPI_TRUE);
  }
#if (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)
  else
  {
    /* Nothing to do */
  }
#endif /* (SPI_LEVEL_DELIVERED == SPI_LEVEL_2) */

  /* Set SOP-bits, ND-bits and BTST bit to start transmission
     in dual buffer mode */
  LulMCTL2RegValue = SPI_CSIH_SET_SOP(LpChConfig->ulHWBufferIndex) |
    SPI_CSIH_SET_ND(LpJobConfig->usNoOfHwBuffers) | SPI_CSIH_SET_BTST;
  SPI_WRITE_REG_ONLY(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL2, LulMCTL2RegValue)
  /* References: SPI_DDD_ACT_043_REG001 */
}
#endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON)) */

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
/*******************************************************************************
** Function Name      : Spi_CSIXMaskHWUnitRxInterrupt
**
** Service ID         : NA
**
** Description        : This function manipulates interrupt masks of a HWUnit.
**                      This function modifies EIMK bit only,
**                      EIRF bit is not affected.
**                      This function doesn't perform disabling interruption,
**                      dummyread & SYNP. These should be done in a caller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HWUnit
**                      Non-Reentrant for same HWUnit
**
** Input Parameters   : LulHWPhyIndex - Physical index of the HWUnit.
**                      LblMask       - TRUE: set mask, FALSE: reset mask
**                      LblClearEIRF  - TRUE: clear interrupt request
**                                    - FAlSE: do not clear interrupt request
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Global variables must be initialized.
**
** Global Variable    : Spi_GaaCSIXRegs
**
** Function invoked   : None
**
** Registers Used     : EICn/ICxxx
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitRxInterrupt(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF)
/* References: SPI_DDD_ACT_093 */
{
  /* Write the lower byte of EIC registers to avoid modifying EIRF bit */
  if (SPI_TRUE == LblMask)
  {
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_SET_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR,
      (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_093_REG001 */
  }
  else
  {
    /* Check if request to clear pending interrupt */
    if (SPI_TRUE == LblClearEIRF)
    {
      /* Clear interrupt request flag */
      RH850_SV_CLEAR_ICR_SYNCP(16,
        Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR,
        (uint16)(~SPI_EIC_EIRF_MASK));
      /* References:SPI_DDD_ACT_093_REG002 */
    }
    else
    {
      /* Nothing to do */
    }
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_CLEAR_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR,
      (uint8)(~SPI_EIC_EIMK_MASK));
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_093_REG003 */
  }
}

/*******************************************************************************
** Function Name      : Spi_CSIXMaskHWUnitTxInterrupt
**
** Service ID         : NA
**
** Description        : This function manipulates interrupt masks of a HWUnit.
**                      This function modifies EIMK bit only,
**                      EIRF bit is not affected.
**                      This function doesn't perform disabling interruption,
**                      dummyread & SYNP. These should be done in a caller.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant for different HWUnit
**                      Non-Reentrant for same HWUnit
**
** Input Parameters   : LulDmaIndex  - Index of HW
**                      LblMask      - TRUE: set mask, FALSE: reset mask
**                      LblClearEIRF - TRUE: clear interrupt request
**                                   - FAlSE: do not clear interrupt request
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Global variables must be initialized.
**
** Global Variable    : Spi_GaaCSIXRegs
**
** Function invoked   : None
**
** Registers Used     : EICn/ICxxx
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXMaskHWUnitTxInterrupt(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(boolean, AUTOMATIC) LblMask,
  CONST(boolean, AUTOMATIC) LblClearEIRF)
/* References: SPI_DDD_ACT_105 */
{
  /* Get pointer to interrupt control registers */
  if (SPI_TRUE == LblMask)
  {
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_SET_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC,
      (uint8)SPI_EIC_EIMK_MASK);
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_105_REG001 */
  }
  else
  {
    /* Check if request to clear pending interrupt */
    if (SPI_TRUE == LblClearEIRF)
    {
      /* Clear interrupt request flag */
      RH850_SV_CLEAR_ICR_SYNCP(16,
        Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC,
        (uint16)(~SPI_EIC_EIRF_MASK));
      /* References: SPI_DDD_ACT_105_REG002 */
    }
    else
    {
      /* Nothing to do */
    }
    /* MISRA Violation: START Msg(4:0310)-3 */
    RH850_SV_CLEAR_ICR_SYNCP(8,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC,
      (uint8)(~SPI_EIC_EIMK_MASK));
    /* END Msg(4:0310)-3 */
    /* References: SPI_DDD_ACT_105_REG003 */
  }
}
#endif /* ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || \
  (SPI_LEVEL_DELIVERED == SPI_LEVEL_2)) */

#if (SPI_DIRECT_ACCESS_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
/*******************************************************************************
** Function Name       : Spi_CSIXWriteTX0Register
**
** Service ID          : Not Applicable
**
** Description         : This function writes data to TX0 register.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LulHWPhyIndex - HW unit phyical index.
**                       LulData - Data to write to TX0W register.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized.
**
** Global Variable     : Spi_GaaCSIXRegs
**
** Function Invoked    : None
**
** Registers Used      : CSIXnTX0W
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXWriteTX0Register(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(uint32, AUTOMATIC) LulData)
/* References: SPI_DDD_ACT_095 */
{
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check physical index corresponding to CSIH */
  if (NULL_PTR != Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs)
#endif
  {
#if (SPI_CSIH_CONFIGURED == STD_ON)
    SPI_WRITE_REG_ONLY(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulTX0W, LulData)
    /* References: SPI_DDD_ACT_095_REG001 */
#endif
  }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  else
#endif
  {
#if (SPI_CSIG_CONFIGURED == STD_ON)
    SPI_WRITE_REG_ONLY(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulTX0W, LulData)
    /* References: SPI_DDD_ACT_095_REG002 */
#endif
  }
}
#endif /* (SPI_DIRECT_ACCESS_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) */

#if (SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
/*******************************************************************************
** Function Name       : Spi_CSIXReadRX0Register
**
** Service ID          : Not Applicable
**
** Description         : This function reads data from RX0 register.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LulHWPhyIndex - HW unit phyical index.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : LusData - data read from RX0 register
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GaaCSIXRegs
**
** Function Invoked    : None
**
** Registers Used      : CSIXnRX0H
*******************************************************************************/
static FUNC(uint16, SPI_PRIVATE_CODE) Spi_CSIXReadRX0Register(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex)
/* References: SPI_DDD_ACT_094 */
{
  VAR(uint16, AUTOMATIC) LusData;
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  /* Check physical index corresponding to CSIH */
  if (NULL_PTR != Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs)
#endif
  {
#if (SPI_CSIH_CONFIGURED == STD_ON)
    LusData = Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usRX0H;
#endif
  }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
  else
#endif
  {
#if (SPI_CSIG_CONFIGURED == STD_ON)
    LusData = Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->usRX0H;
#endif
  }
  return LusData;
}
#endif /* (SPI_DIRECT_ACCESS_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME) */

#if (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_HWControlCS
**
** Service ID         : Not Applicable
**
** Description        : This service performs activation of the Chip Select pin.
**
** Sync/Async         : Synchronous.
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpJobConfig - Pointer to Job configuration.
**                      LblActivateCS - Chip select activation is required.
**                      LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : None
**
** Function Invoked   : None
**
** Registers Used     : PSRn
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_FAST_CODE) Spi_HWControlCS(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(boolean, AUTOMATIC) LblActivateCS,
  CONST(uint8, AUTOMATIC) LucApiId
)
/* END Msg(2:3206)-6 */
{
  /* References: SPI_DDD_ACT_096 */
  volatile VAR(uint32, AUTOMATIC) LulLoopCount;

  /* Set or reset port pin depending on chip select polarity and cs act flag */
  if (((SPI_CS_HIGH == LpJobConfig->blCsPolarity) &&
    (SPI_TRUE == LblActivateCS)) ||
    ((SPI_CS_LOW == LpJobConfig->blCsPolarity) &&
    (SPI_FALSE == LblActivateCS)))
  {
    /* Set port pin to high level  */
    SPI_WRITE_REG_ONLY(LpJobConfig->pPSRReg, LpJobConfig->ulPortPinMask)
    /* References: SPI_DDD_ACT_096_REG001 */
    /* Check after write for target pin */
    SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(LpJobConfig->pPSRReg,
      (uint32)(LpJobConfig->ulPortPinMask & SPI_PORT_PIN_VALUE_MASK),
      LpJobConfig->ulPortPinMask, 32,
      LucApiId)
  }
  else /* If Chip select polarity is configured as active Low */
  {
    /* Reset port pin to low level */
    SPI_WRITE_REG_ONLY(LpJobConfig->pPSRReg,
      (LpJobConfig->ulPortPinMask & SPI_PORT_PIN_MASK))
    /* References: SPI_DDD_ACT_096_REG002 */
    /* Check after write for target pin */
    SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(LpJobConfig->pPSRReg,
      (uint32)SPI_ZERO,
      LpJobConfig->ulPortPinMask, 32, LucApiId)
  }

  /* Check whether CS activation is required */
  if (SPI_TRUE == LblActivateCS)
  {
    /* Timing between chip select activated and clock start when writing data */
    LulLoopCount = LpJobConfig->ulClk2CsCount;
    /* QAC Warning: START Msg(2:3416)-10 */
    while ((uint32)SPI_ZERO < LulLoopCount)
    /* END Msg(2:3416)-10 */
    {
      LulLoopCount--;
    }
  }
  else
  {
    /* Nothing to do */
  }
}
#endif /* (SPI_CS_VIA_GPIO_CONFIGURED == STD_ON) */

#if (SPI_MAX_ERROR_BUFFER_SIZE > 0)
/*******************************************************************************
** Function Name      : Spi_CheckAndStoreErrorInfo
**
** Service ID         : Not Applicable
**
** Description        : Function to store Hardware Error Details.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LulHWUnitIndex - Index of HWUnit configuration.
**                      LusErrorValue - Error status value
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GpFirstHWUnit, Spi_GaaHWStatus
**
** Function Invoked   : Spi_StoreErrorInfo
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CheckAndStoreErrorInfo(
  CONST(uint32, AUTOMATIC) LulHWUnitIndex,
  CONST(uint16, AUTOMATIC) LusErrorValue)
/* References: SPI_DDD_ACT_064 */
{
  volatile P2VAR(Spi_HWStatusType, AUTOMATIC, SPI_APPL_DATA) LpHWStat;
  VAR(Spi_CommErrorType, AUTOMATIC) LstErrorType;

#if (SPI_FIFO_MODE == STD_ON)
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  /* Get pointers and index relevant to HW */
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
  /* END Msg(4:0491)-1 */
#endif

  LpHWStat = &Spi_GaaHWStatus[LulHWUnitIndex];

  /* Copy the Hardware unit Index */
  LstErrorType.ucHwUnit = (uint8)LulHWUnitIndex;
  /* Copy the Sequence Index */
  LstErrorType.ucSeqID = LpHWStat->ucOngoingSeqIndex;
  /* Copy the Job Index */
  LstErrorType.usJobID = LpHWStat->usOngoingJobIndex;

  /* Check for Over run Error */
  if (SPI_CSIX_OVEC == (uint16)(LusErrorValue & SPI_CSIX_OVEC))
  {
    /* Set Error type */
    LstErrorType.enErrorType = SPI_OVERRUN_ERROR;
    /* Store error information into buffer */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }

  /* Check for Parity Error */
  if (SPI_CSIX_PEC == (uint16)(LusErrorValue & SPI_CSIX_PEC))
  {
     /* Set Error type */
    LstErrorType.enErrorType = SPI_PARITY_ERROR;
    /* Store error information into buffer */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }

  /* Check for Data Consistency Error */
  if (SPI_CSIX_DCEC == (uint16)(LusErrorValue & SPI_CSIX_DCEC))
  {
    LstErrorType.enErrorType = SPI_DATA_CONSISTENCY_ERROR;
    /* Store error information into buffer */
    Spi_StoreErrorInfo(&LstErrorType);
  }
  else
  {
    /* No action required */
  }

#if (SPI_FIFO_MODE == STD_ON)
  if (SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode)
  {
    /* Check for Overflow Error */
    if (SPI_CSIH_OFEC == (uint16)(LusErrorValue & SPI_CSIH_OFEC))
    {
      LstErrorType.enErrorType = SPI_OVERFLOW_ERROR;
      /* Store error information into buffer */
      Spi_StoreErrorInfo(&LstErrorType);
    }
    else
    {
      /* No action required */
    }

    /* Check for slave fifo time out error */
    if (SPI_CSIH_TMOEC == (uint16)(LusErrorValue & SPI_CSIH_TMOEC))
    {
      LstErrorType.enErrorType = SPI_SLAVE_TIME_OUT_ERROR;
      /* Store error information into buffer */
      Spi_StoreErrorInfo(&LstErrorType);
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
#endif /* (SPI_FIFO_MODE == STD_ON) */
}

/*******************************************************************************
** Function Name      : Spi_StoreErrorInfo
**
** Service ID         : Not Applicable
**
** Description        : Function to store Hardware Error Details.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LpErrorDetails - Error Details.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variable    : Spi_GstErrorBuffer
**
** Function Invoked   : SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : None
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_StoreErrorInfo(
  CONSTP2CONST(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST) LpErrorDetails)
/* References: SPI_DDD_ACT_065 */
{
  volatile P2VAR(Spi_CommErrorType, AUTOMATIC, SPI_APPL_CONST)LpCommErrorInfo;

  /* Critical secion to protect re-entrancy between
     1. Spi_SyncTransmit - Spi_SyncTransmit
     2. Spi_SyncTransmit - Spi_MainFunction_Handling (or ISR) */
  SPI_ENTER_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_065_CRT001 */
  /* Getting the global pointer to local variable */
  LpCommErrorInfo =
    &Spi_GstErrorBuffer.aaErrorInfo[(uint32)Spi_GstErrorBuffer.ucNextIndex];
  /* Copy the Error details into the Error Buffer */
  /* Copy the Hardware unit Index */
  LpCommErrorInfo->ucHwUnit = LpErrorDetails->ucHwUnit;
  /* Copy the Sequence Index */
  LpCommErrorInfo->ucSeqID = LpErrorDetails->ucSeqID;
  /* Copy the Job Index */
  LpCommErrorInfo->usJobID = LpErrorDetails->usJobID;
  /* Copy the Error */
  LpCommErrorInfo->enErrorType = LpErrorDetails->enErrorType;
  /* Index pointing to the next location */
  Spi_GstErrorBuffer.ucNextIndex++;
  /* Spi_GucBufferIndex updating to zero, since it is a cyclic buffer */
  if ((uint8)SPI_MAX_ERROR_BUFFER_SIZE <= Spi_GstErrorBuffer.ucNextIndex)
  {
    Spi_GstErrorBuffer.ucNextIndex = SPI_ZERO;
   /* References: SPI_DDD_ACT_065_GBL001 */
  }
  else
  {
    /* No action required */
  }
  /* Exit critical section */
  SPI_EXIT_CRITICAL_SECTION(SPI_RAM_DATA_PROTECTION);
  /* References: SPI_DDD_ACT_065_CRT002 */
}
#endif /* (SPI_MAX_ERROR_BUFFER_SIZE > 0) */

#if (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)
/*******************************************************************************
** Function Name      : Spi_CSIXLoopBackSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform data transmission self test
**                      using loop back mode.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LucApiId - Service ID of API invoking this function.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK/E_NOT_OK)
**
** Preconditions      : Global variables must have been initialized
**                      All interruption must be disabled
**
** Global Variable    : Spi_GpConfigPtr, Spi_FirstHWUnit
**
** Function Invoked   : Spi_CSIXTurnOffUnit, Dem_ReportErrorStatus
**                      Spi_CSIXReadRX0Register
**
** Registers Used     : CSIXnCTL0, CSIXnCTL1, CSIXnCTL2, CSIXnCFG0, CSIXnSTCR0,
**                      CSIXnBRSx
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXLoopBackSelfTest(
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_068 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  volatile VAR(uint32, AUTOMATIC) LulTimeout;
  VAR(uint16, AUTOMATIC) LusData;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

  /* Initialize the Return variable */
  LucReturnValue = E_OK;

  /* Check for maximum HW Unit configured */
  for (LulHWUnitIndex = SPI_ZERO;
    LulHWUnitIndex < Spi_GpConfigPtr->ucNoOfHWUnits; LulHWUnitIndex++)
  {
    /* Get the pointer to the structure of HW Unit information */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */
    LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

    /* Step 1. Clear PWR, do dummy read to do the other registers setting */
    Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

    /* Step 2. Set TXE, RXE, MBS (direct access mode) */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0,
      ((uint8)(SPI_CSIX_TXE | SPI_CSIX_RXE | SPI_CSIX_MBS)),
       &Spi_GaaCTLRegMirror[LulHWUnitIndex].ucCTL0,
       CTLREG_8_BIT_MASK, 8, LucApiId)
    /* References: SPI_DDD_ACT_068_REG001 */

    /* Step 3. Clear PWR */
    Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);

    /* Set loopback mode */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ulCTL1, SPI_CSIX_LBM,
      &Spi_GaaCTLRegMirror[LulHWUnitIndex].ulCTL1,
      CTLREG_32_BIT_MASK, 32, LucApiId)
    /* References: SPI_DDD_ACT_068_REG002 */

    /* Set baudrate */
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
#endif
    {
#if (SPI_CSIH_CONFIGURED == STD_ON)
      /* Set baudrate */
      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaBRS[0].usBRS,
         SPI_CSIX_LOOPBACK_BRS,
         &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaBRS[0],
         CTLREG_16_BIT_MASK, 16, LucApiId)
      /* END Msg(2:3441)-3 */
      /* References: SPI_DDD_ACT_068_REG003 */

      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
        SPI_CSIX_PRS_DIV_2,
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
        CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_068_REG004 */

      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaCFG[0],
        SPI_CSIX_LOOPBACK_CFG,
        &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaCFG[0],
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* END Msg(2:3441)-3 */
      /* References: SPI_DDD_ACT_068_REG005 */

#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
    }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    else
#endif
    {
#if (SPI_CSIG_CONFIGURED == STD_ON)
      /* Set baudrate */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2,
        (SPI_CSIX_PRS_DIV_2 | SPI_CSIX_LOOPBACK_BRS),
        &Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2,
        CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_068_REG006 */

      /* Set data length */
      SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0,
        SPI_CSIX_LOOPBACK_CFG,
        &Spi_GaaCSIGRegMirror[LulHWUnitIndex].ulCFG0,
        CTLREG_32_BIT_MASK, 32, LucApiId)
      /* References: SPI_DDD_ACT_068_REG007 */

#endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
    }

    /* Clear all status error bits */
    SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
      LpHWInfo->usSTCR0MaskValue)
    /* References: SPI_DDD_ACT_068_REG008 */
    /* Check for Write verification */
    SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0, (uint32)SPI_ZERO,
      (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)

    /* Power ON */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0,
      ((uint8)(SPI_CSIX_PWR | SPI_CSIX_TXE | SPI_CSIX_RXE | SPI_CSIX_MBS)),
      &Spi_GaaCTLRegMirror[LulHWUnitIndex].ucCTL0,
      CTLREG_8_BIT_MASK, 8, LucApiId)
    /* References: SPI_DDD_ACT_068_REG009 */

    /* Clear EIRF flags before starting transmission */
    RH850_SV_CLEAR_ICR_SYNCP(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC, (uint16)(~SPI_EIC_EIRF_MASK));
    /* References: SPI_DDD_ACT_068_REG010 */
    RH850_SV_CLEAR_ICR_SYNCP(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR, (uint16)(~SPI_EIC_EIRF_MASK));
    /* References: SPI_DDD_ACT_068_REG012 */

    /* Send dummy data */
    Spi_CSIXWriteTX0Register(LulHWPhyIndex, SPI_CSIX_LOOPBACK_DATA);

    /* Wait in the loop until the communication is stopped */
    LulTimeout = SPI_ZERO;
    /* QAC Warning: START Msg(2:3416)-10 */
    while ((LulTimeout < Spi_GpConfigPtr->ulTimeoutCount) &&
      (SPI_ZERO == (RH850_SV_MODE_REG_READ_ONLY(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR) & SPI_EIC_EIRF_MASK))
    )
    /* END Msg(2:3416)-10 */
    {
      LulTimeout++;
    }

    /* QAC Warning: START Msg(2:3416)-10 */
    if (LulTimeout >= Spi_GpConfigPtr->ulTimeoutCount)
    /* END Msg(2:3416)-10 */
    {
#if defined(SPI_E_DATA_TX_TIMEOUT_FAILURE)
      Dem_ReportErrorStatus(SPI_E_DATA_TX_TIMEOUT_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* References: SPI_DDD_ACT_068_ERR001 */
#endif
      LucReturnValue = E_NOT_OK;
    }
    else
    {

    }

    /* Try to read data from RX0*/
    LusData = Spi_CSIXReadRX0Register(LulHWPhyIndex);
    /* If the loopback data is not consistent, return error */
    if (LusData != SPI_CSIX_LOOPBACK_DATA)
    {
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Nothing to do */
    }

    if ((uint32)SPI_ZERO != (Spi_GaaCSIXRegs[
      LpHWInfo->ucPhysicalIndex].pCSIXSTRegs->ulSTR0 & (uint32)SPI_CSIX_PE))
    {
#if defined(SPI_E_HARDWARE_ERROR)
      Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
      /* References: SPI_DDD_ACT_068_ERR002 */
#endif
      /* Clear PE bit */
      SPI_WRITE_REG_ONLY(&Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->usSTCR0,
        SPI_CSIX_PEC)
      /* References: SPI_DDD_ACT_068_REG014 */
      /* Check for Write verification */
      /* QAC Warning: START Msg(2:3441)-3 */
      SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
        &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXSTRegs->ulSTR0, (uint32)SPI_ZERO,
        (uint32)LpHWInfo->usSTCR0MaskValue, 32, LucApiId)
      /* END Msg(2:3441)-3 */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Nothing to do */
    }

    /* Report LOOPBACK DEM error */
    if (E_OK != LucReturnValue)
    {
      Dem_ReportErrorStatus(SPI_E_LOOPBACK_SELFTEST_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* References: SPI_DDD_ACT_068_ERR003 */
    }
    else
    {
      /* Nothing to do */
    }

    /* Clear EIRF flags */
    RH850_SV_CLEAR_ICR_SYNCP(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIC, (uint16)(~SPI_EIC_EIRF_MASK));
    /* References: SPI_DDD_ACT_068_REG011 */
    RH850_SV_CLEAR_ICR_SYNCP(16,
      Spi_GaaCSIXRegs[LulHWPhyIndex].pICTIR, (uint16)(~SPI_EIC_EIRF_MASK));
    /* References: SPI_DDD_ACT_068_REG013 */
  }

  return(LucReturnValue);
}
#endif /* ((SPI_LOOPBACK_SELFTEST == SPI_LB_INIT) ||\
  (SPI_LOOPBACK_SELFTEST == SPI_LB_INIT_RUNTIME)) */

#if (SPI_CSIH_CONFIGURED == STD_ON)
#if (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME)
/*******************************************************************************
** Function Name      : Spi_CSIHEccSelfTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc self test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : Spi_GpConfigPtr, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function Invoked   : Spi_EccAllZeroTest, Spi_EccAllOneTest,
**                      Spi_EccWalkOneTest, Spi_EccTwoBitTest
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTMC, ECCCSIHnTED, ECCCSIHnTRC,
**                      ECCCSIHnERDB
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIHEccSelfTest(void)
/* References: SPI_DDD_ACT_067 */
{
  volatile P2VAR(Spi_CSIHECCRegType, AUTOMATIC, SPI_CONFIG_DATA) LpEccBaseAddr;
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint16, AUTOMATIC) LusEccTmcRegValue;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulTestPattern;

  /* Initialize the local variables */
  LucReturnValue = E_OK;
  LulTestPattern = SPI_ZERO;

  for (LulHWUnitIndex = SPI_ZERO;
    ((LulHWUnitIndex < Spi_GpConfigPtr->ucNoOfHWUnits) &&
    (LucReturnValue == E_OK)); LulHWUnitIndex++)
  {
    /* Get the pointer to the structure of HW Unit information */
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    if (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
#endif
    {
#if (SPI_CSIH_CONFIGURED == STD_ON)
      LpEccBaseAddr = Spi_GaaCSIXRegs[LpHWInfo->ucPhysicalIndex].pCSIHECCRegs;
      /* Set ECREIS, ECDCS, ECTRRS, ECTMCE AND ETMA[1:0] bits of TMC register */
      LusEccTmcRegValue = LpEccBaseAddr->usEccTmc | ECC_TMC_SET_BITS;
      SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccTmc, LusEccTmcRegValue)
      /* References: SPI_DDD_ACT_067_REG001 */

      /* Disable 1-Bit/2-Bit Error Detection Interrupt during perform ECC
         self-test to prevent ISR occur when error detected */
      SPI_WRITE_REG_ONLY(
        &LpEccBaseAddr->usEccCtl, ECC_CTL_CLEAR_EC1EDIC_EC2EDIC)
      /* References: SPI_DDD_ACT_067_REG002 */
      do
      {
        switch (LulTestPattern)
        {
        case SPI_ZERO :
          LucReturnValue = Spi_EccAllZeroTest(LpEccBaseAddr);
        break;
        case SPI_ONE :
          LucReturnValue = Spi_EccAllOneTest(LpEccBaseAddr);
        break;
        case SPI_TWO:
          LucReturnValue = Spi_EccWalkOneTest(LpEccBaseAddr);
        break;
        case SPI_THREE:
          LucReturnValue = Spi_EccTwoBitTest(LpEccBaseAddr);
        break;
        default:
          LucReturnValue = E_NOT_OK;
        break;
        }
        LulTestPattern++;
      }
      while(((uint32)SPI_THREE >= LulTestPattern) && \
        (E_NOT_OK != LucReturnValue));

      /* Enable 1-Bit/2-Bit Error Detection Interrupt after perform ECC
         self-test */
      SPI_WRITE_REG_ONLY(
        &LpEccBaseAddr->usEccCtl, ECC_CTL_SET_EC1EDIC_EC2EDIC)
      /* References: SPI_DDD_ACT_067_REG003 */

      /* Set ECTMCE = 0 in TMC register */
      SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccTmc, ECC_TMC_SET_TEST_DISABLE)
      /* References: SPI_DDD_ACT_067_REG004 */
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
    }
#if (SPI_CSIH_CONFIGURED == STD_ON) && (SPI_CSIG_CONFIGURED == STD_ON)
    else
    {
      /* Do nothing */
    }
#endif

    /* Reset the test pattern to continue ECC self test for next Hw unit */
    LulTestPattern = SPI_ZERO;
  }

  return LucReturnValue;
}

/*******************************************************************************
** Function Name      : Spi_EccAllZeroTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc all zero error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpEccBaseAddr - Base address of ECCCSIH registers
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC, ECCCSIHnERDB
*******************************************************************************/
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllZeroTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr
)
/* References: SPI_DDD_ACT_069 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint16, AUTOMATIC) LusEccCtlRegValue;

  /* Initialize the return variable */
  LucReturnValue = E_OK;

  /* Initialize RAM */
  SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
  /* References: SPI_DDD_ACT_069_REG001 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO ==((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LusEccCtlRegValue = LpEccBaseAddr->usEccCtl | ECC_CTL_ECER1F_ECER2F_CLEAR;
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
    /* References: SPI_DDD_ACT_069_REG002 */
  }
  else
  {
    /* Report to DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
      DEM_EVENT_STATUS_FAILED);
    /* References: SPI_DDD_ACT_069_ER001 */
    /* Set Return value */
    LucReturnValue = E_NOT_OK;
  }

  if (E_OK == LucReturnValue)
  {
    /* Write All zero test pattern to RAM */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TRC_ALL_ZERO_PATTERN)
    /* References: SPI_DDD_ACT_069_REG003 */
    /* Write to ECC bits */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb, ECC_TRC_ERDB_INITIALIZE)
    /* References: SPI_DDD_ACT_069_REG004 */
    /* Dummy Read value from RAM */
    RH850_IOREG_READ_ONLY(32, &LpEccBaseAddr->ulEccTed)

    /* Check any error flag is set */
    if (SPI_ZERO != (LpEccBaseAddr->usEccCtl & ECC_CTL_ERR_FLAG))
    {
      /* Clear error flag should be handled by upper layer */
      /* Report to DEM */
      Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* References: SPI_DDD_ACT_069_ER002 */
      /* Set Return value */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Do nothing */
    }
  }
  else
  {
    /* Do nothing */
  }

  return LucReturnValue;
}

/*******************************************************************************
** Function Name      : Spi_EccAllOneTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc all one error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpEccBaseAddr - Base address of ECCCSIH registers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC, ECCCSIHnERDB.
*******************************************************************************/
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccAllOneTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr
)
/* References: SPI_DDD_ACT_070 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint16, AUTOMATIC) LusEccCtlRegValue;

  /* Initialize the return variable */
  LucReturnValue = E_OK;

  /* Initialize RAM */
  SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
  /* References: SPI_DDD_ACT_070_REG001 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO == ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LusEccCtlRegValue = LpEccBaseAddr->usEccCtl | ECC_CTL_ECER1F_ECER2F_CLEAR;
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
    /* References: SPI_DDD_ACT_070_REG002 */
  }
  else
  {
    /* Report to DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Set Return value */
    LucReturnValue = E_NOT_OK;
  }

  if (E_OK == LucReturnValue)
  {
    /* Write All ONE test pattern to RAM */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TRC_ALL_ONE_PATTERN)
    /* References: SPI_DDD_ACT_070_REG003 */
    /* Write to ECC bits */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb, ECC_TRC_ERDB_INITIALIZE)
    /* References: SPI_DDD_ACT_070_REG004 */
    /* Dummy Read value from RAM */
    RH850_IOREG_READ_ONLY(32, &LpEccBaseAddr->ulEccTed)

    /* Check any error flag is set */
    if (SPI_ZERO != ((LpEccBaseAddr->usEccCtl & ECC_CTL_ERR_FLAG)))
    {
      /* Clear error flag should be handled by upper layer */
      /* Report DEM */
      Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* Set Return value */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* No Action required */
    }
  }
  else
  {
    /* Do nothing */
  }

  return LucReturnValue;
}

/*******************************************************************************
** Function Name      : Spi_EccWalkOneTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc walk one bit error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpEccBaseAddr - Base address of ECCCSIH registers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC, ECCCSIHnERDB.
*******************************************************************************/
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccWalkOneTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr
)
/* References: SPI_DDD_ACT_071 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint16, AUTOMATIC) LusEccCtlRegValue;
  VAR(uint32, AUTOMATIC) LulPattentCount;
  VAR(uint32, AUTOMATIC) LulDataWordCount;

  /* Initialize the local variables */
  LucReturnValue = E_OK;
  LulPattentCount = SPI_ZERO;
  LulDataWordCount = SPI_ZERO;

  do
  {
    /* Initialize RAM */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
    /* References: SPI_DDD_ACT_071_REG001 */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb, ECC_TRC_ERDB_INITIALIZE)
    /* References: SPI_DDD_ACT_071_REG010 */
    /* Check ECEMF of CTL register is SET */
    if ((uint32)SPI_ZERO ==
      ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
    {
      /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
      LusEccCtlRegValue = LpEccBaseAddr->usEccCtl | ECC_CTL_ECER1F_ECER2F_CLEAR;
      SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
      /* References: SPI_DDD_ACT_071_REG002 */
    }
    else
    {
      /* Report to DEM */
      Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* Set Return value */
      LucReturnValue = E_NOT_OK;
    }

    if (E_OK == LucReturnValue)
    {
      if (ECC_CODE_TOTAL_PATTERNS <= LulPattentCount)
      {
        /* A single data bit is set to 1 and "walked" through the entire
           the data word (32 bits) and the other bits are set to "0" */
        SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed,
          (uint32)((uint32)SPI_ONE << LulDataWordCount))
        /* References: SPI_DDD_ACT_071_REG003 */
        SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb,
          ECC_TRC_ERDB_INITIALIZE)
        /* References: SPI_DDD_ACT_071_REG004 */
        /* Increase count to test next pattern */
        LulDataWordCount++;
      }
      else
      {
        /* A single data bit is set to 1 and "walked" through the ECC code
           (7 bits) and the other bits are set to "0" */
        SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed,
          ECC_TED_RAM_INITIALIZE)
        /* References: SPI_DDD_ACT_071_REG007 */
        SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb,
          (uint8)((uint8)SPI_ONE << (uint8)LulPattentCount))
        /* References: SPI_DDD_ACT_071_REG008 */
      }
      /* Dummy Read of the value from RAM */
      RH850_IOREG_READ_ONLY(32, &LpEccBaseAddr->ulEccTed)

      if ((uint32)SPI_ZERO ==
        ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_1BIT_ERR_FLAG))
      /* Check any error flag is set - Expected 1 bit error */
      {
        /* Report DEM */
        Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        /* Set Return value */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* To clear the error flag, a normal pattern needs to be set to
        ECEDB bit of ECC Encode/Decode Input/Output Replacement Test Register
        and ECC Redundant Bit Input/Output Replacement Register*/
        SPI_WRITE_REG_ONLY(
          &LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
        /* References: SPI_DDD_ACT_071_REG005 */
        SPI_WRITE_REG_ONLY(
          &LpEccBaseAddr->stEccTrc.ucErdb, ECC_TRC_ERDB_INITIALIZE)
        /* References: SPI_DDD_ACT_071_REG009 */
        /* Check ECEMF of CTL register is SET */
        if ((uint32)SPI_ZERO ==
          ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
        {
          /* Clear the one bit error flag by setting ECER1C bit of
             CTL Register */
          LusEccCtlRegValue = LpEccBaseAddr->usEccCtl| ECC_CTL_1BIT_ERRCLR_FLAG;
          SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
          /* References: SPI_DDD_ACT_071_REG006 */
        }
        else
        {
          /* Report to DEM */
          Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
            DEM_EVENT_STATUS_FAILED);
          /* Set Return value */
          LucReturnValue = E_NOT_OK;
        }
      }
      /* Increase pattern count */
      LulPattentCount++;
    }
    else
    {
      /* Do nothing */
    }
  }while ((ECC_TEST_TOTAL_PATTERNS > LulPattentCount) && \
    (E_NOT_OK != LucReturnValue));

  return LucReturnValue;
}

/*******************************************************************************
** Function Name      : Spi_EccTwoBitTest
**
** Service ID         : Not Applicable
**
** Description        : This function is to perform Ecc two bit error test.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpEccBaseAddr - Base address of ECCCSIH registers
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : None
**
** Function Invoked   : Dem_ReportErrorStatus
**
** Registers Used     : ECCCSIHnCTL, ECCCSIHnTED, ECCCSIHnTRC, ECCCSIHnERDB.
*******************************************************************************/
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_EccTwoBitTest(
  volatile CONSTP2VAR(Spi_CSIHECCRegType, AUTOMATIC, REGSPACE)
  LpEccBaseAddr
)
/* References: SPI_DDD_ACT_072 */
{
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  VAR(uint16, AUTOMATIC) LusEccCtlRegValue;

  /* Initialize the local variables */
  LucReturnValue = E_OK;

  /* Initialize RAM */
  SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
  /* References: SPI_DDD_ACT_072_REG001 */
  /* Check ECEMF of CTL register is SET */
  if ((uint32)SPI_ZERO == ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
  {
    /* Clearing 1-bit and 2-bit error flags in case if ECEMF is 0 */
    LusEccCtlRegValue = LpEccBaseAddr->usEccCtl | ECC_CTL_ECER1F_ECER2F_CLEAR;
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
    /* References: SPI_DDD_ACT_072_REG002 */
  }
  else
  {
    /* Report to DEM */
    Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE, DEM_EVENT_STATUS_FAILED);
    /* Set Return value */
    LucReturnValue = E_NOT_OK;
  }

  if (E_OK == LucReturnValue)
  {
    /* Write two bit test pattern to RAM */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TRC_TWO_BIT_PATTERN)
    /* References: SPI_DDD_ACT_072_REG003 */
    SPI_WRITE_REG_ONLY(&LpEccBaseAddr->stEccTrc.ucErdb, ECC_TRC_ERDB_INITIALIZE)
    /* References: SPI_DDD_ACT_072_REG004 */
    /* Dummy Read value from RAM */
    RH850_IOREG_READ_ONLY(32, &LpEccBaseAddr->ulEccTed)

    /* Check any error flag is set - Expected 2 bit error */
    if ((uint32)SPI_ZERO ==
      ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_2BIT_ERR_FLAG))
    {
      /* Report DEM */
      Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
        DEM_EVENT_STATUS_FAILED);
      /* Set Return value */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Initialize RAM */
      SPI_WRITE_REG_ONLY(&LpEccBaseAddr->ulEccTed, ECC_TED_RAM_INITIALIZE)
      /* References: SPI_DDD_ACT_072_REG005 */
      /* Check ECEMF of CTL register is SET */
      if ((uint32)SPI_ZERO ==
        ((uint32)LpEccBaseAddr->usEccCtl & ECC_CTL_ECEMF_SET))
      {
        /* Clear the one bit error flag by setting ECER2C bit of CTL Register */
        LusEccCtlRegValue = LpEccBaseAddr->usEccCtl | ECC_CTL_2BIT_ERRCLR_FLAG;
        SPI_WRITE_REG_ONLY(&LpEccBaseAddr->usEccCtl, LusEccCtlRegValue)
        /* References: SPI_DDD_ACT_072_REG006 */
      }
      else
      {
        /* Report to DEM */
        Dem_ReportErrorStatus(SPI_E_ECC_SELFTEST_FAILURE,
          DEM_EVENT_STATUS_FAILED);
        /* Set Return value */
        LucReturnValue = E_NOT_OK;
      }
    }
  }
  else
  {
    /* Do nothing */
  }

  return LucReturnValue;
}

#endif /* (SPI_ECC_SELFTEST == SPI_ECC_INIT) ||\
  (SPI_ECC_SELFTEST == SPI_ECC_INIT_RUNTIME) */
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */

#if (SPI_CSIX_RAM_MIRROR == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIXRegsConsistencyCheck
**
** Service ID         : Not Applicable
**
** Description        : This API is for comparing dynamically setting CSIX
**                      control registers values with its corresponding to
**                      RAM mirror variable.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LenHWConsistencyMode - HW consistency mode type
**                                             (SPI_DYNAMIC/SPI_STATIC)
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : Spi_GpFirstJob, Spi_GpFirstHWUnit, Spi_GaaCSIXRegs,
**                      Spi_GaaCTLRegMirror, Spi_GaaCSIGRegMirror,
**                      Spi_GaaCSIHRegMirror
**
** Functions invoked  : Spi_CSIHRegsConsistencyCheck
**                      SPI_ENTER_CRITICAL_SECTION, SPI_EXIT_CRITICAL_SECTION
**
** Registers Used     : CSIHnCTL0, CSIHnCTL1, CSIHnCTL2, CSIHnMCTL0, CSIHnCFGx,
**                      CSIGnCFG0, CSIGnBCTL0
**
*******************************************************************************/
FUNC(Std_ReturnType, SPI_PRIVATE_CODE) Spi_CSIXRegsConsistencyCheck(
  CONST(Spi_HWConsistencyModeType, AUTOMATIC) LenHWConsistencyMode)
/* References: SPI_DDD_ACT_075 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(uint32, AUTOMATIC) LulJobIndex;

  /* Local Variable for Status Return */
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;
  LucReturnValue = E_OK;

  /* Scan all jobs and initialize the associated HWUnits */
  for (LulJobIndex = SPI_ZERO; (E_OK == LucReturnValue) &&
    (LulJobIndex < Spi_GpConfigPtr->usNoOfJobs); LulJobIndex++)
  {
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpJobConfig = &Spi_GpFirstJob[LulJobIndex];
    /* END Msg(4:0491)-1 */
    LulHWUnitIndex = LpJobConfig->ucHWUnitIndex;
    /* MISRA Violation: START Msg(4:0491)-1 */
    LpHWInfo = &Spi_GpFirstHWUnit[LulHWUnitIndex];
    /* END Msg(4:0491)-1 */
    LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;

    /* Check control register 0 value. It always is updated dynamically.
       CTL0.PWR is set before transmission and cleared after transmision
       is completed. Hence disabling interrupts is neccesary to prevent
       pre-emption which could modify this register. */
    SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_075_CRT001 */
    if ((SPI_DYNAMIC == LenHWConsistencyMode) &&
      (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0 !=
      Spi_GaaCTLRegMirror[LulHWUnitIndex].ucCTL0))
    {
      /* Update return status to E_NOT_OK */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Nothing to do */
    }
    SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
    /* References: SPI_DDD_ACT_075_CRT002 */
    if ((E_OK == LucReturnValue)
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
      && (SPI_DYNAMIC == LenHWConsistencyMode)
#else
      && (SPI_STATIC == LenHWConsistencyMode)
#endif
    )
    {
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
      SPI_ENTER_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
      /* References: SPI_DDD_ACT_075_CRT003 */
#endif
      if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ulCTL1 !=
        Spi_GaaCTLRegMirror[LulHWUnitIndex].ulCTL1)
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->usCTL2 !=
        Spi_GaaCTLRegMirror[LulHWUnitIndex].usCTL2)
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Nothing to do */
      }

      if (E_OK == LucReturnValue)
      {
#if (SPI_CSIG_CONFIGURED == STD_ON)
        if ((SPI_MACRO_CSIG == LpHWInfo->enMacroType) &&
          (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ulCFG0 !=
           Spi_GaaCSIGRegMirror[LulHWUnitIndex].ulCFG0))
        {
          /* Update return status to E_NOT_OK */
          LucReturnValue = E_NOT_OK;
        }
        else
        {
          /* Nothing to do */
        }
#endif
#if (SPI_CSIH_CONFIGURED == STD_ON)
        if (
#if (SPI_CSIG_CONFIGURED == STD_ON)
          (E_OK == LucReturnValue) &&
#endif
          (SPI_MACRO_CSIH == LpHWInfo->enMacroType)
        )
        {
          /* Update return status as CSIH Registers result check */
          LucReturnValue =
            Spi_CSIHRegsConsistencyCheck(LulHWPhyIndex, LpJobConfig);
        }
        else
        {
          /* Nothing to do */
        }
#endif
      }
      else
      {
        /* Nothing to do */
      }
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
      SPI_EXIT_CRITICAL_SECTION(SPI_INTERRUPT_CONTROL_PROTECTION);
      /* References: SPI_DDD_ACT_075_CRT004 */
#endif
    }
    else
    {
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
#if (SPI_FIFO_MODE == STD_ON)
      /* Only MCTL0 is static update when HW is not slave FIFO mode */
      if ((SPI_MACRO_CSIH == LpHWInfo->enMacroType) &&
        ((SPI_CSIX_PRS_SLAVE != LpJobConfig->usCSIXCTL2) ||
        (SPI_MEMMODE_FIFO != LpHWInfo->enMemoryMode)) &&
        (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0 !=
        Spi_GaaCSIHRegMirror[LulHWUnitIndex].usMCTL0)
      )
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Nothing to do */
      }
#endif /* (SPI_FIFO_MODE == STD_ON) */
#endif /* (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF) */
    }

#if (SPI_CSIG_CONFIGURED == STD_ON)
    if ((SPI_STATIC == LenHWConsistencyMode) &&
      (SPI_MACRO_CSIG == LpHWInfo->enMacroType) &&
      (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIGRegs->ucBCTL0 !=
       Spi_GaaCSIGRegMirror[LulHWUnitIndex].ucBCTL0))
    {
      /* Update return status to E_NOT_OK */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (SPI_CSIG_CONFIGURED == STD_ON) */
  }

  return LucReturnValue;
}

#if (SPI_CSIH_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIHRegsConsistencyCheck
**
** Service ID         : Not Applicable
**
** Description        : This API is for comparing dynamically setting of secific
**                      CSIH control registers values with its corresponding RAM
**                      mirror variable.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Reentrant
**
** Input Parameters   : LulHWPhyIndex - Physical index of the HWUnit.
**                      LpJobConfig   - Pointer to the Job configuration.
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType(E_OK/E_NOT_OK)
**
** Preconditions      : Global variables must have been initialized
**
** Global Variable    : Spi_GaaCSIXRegs, Spi_GaaCSIHRegMirror
**
** Functions invoked  : None
**
** Registers Used     : CSIHnCFG0, CSIHnMCTL0, CSIHnMCTL1, CSIHBRSx
**
*******************************************************************************/
static FUNC(Std_ReturnType, SPI_PRIVATE_CODE)Spi_CSIHRegsConsistencyCheck(
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig)
/* References: SPI_DDD_ACT_076 */
{
#if (SPI_FIFO_MODE == STD_ON)
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
#endif
#endif
  VAR(uint32, AUTOMATIC) LulBRSIndex;
  VAR(uint32, AUTOMATIC) LulCSCount;
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  VAR(Std_ReturnType, AUTOMATIC) LucReturnValue;

#if (SPI_FIFO_MODE == STD_ON)
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[LpJobConfig->ucHWUnitIndex];
  /* END Msg(4:0491)-1 */
#endif
#endif

  /* Initialize return value */
  LucReturnValue = E_OK;
  /* Get BRS register */
  LulBRSIndex = SPI_CSIH_BRSS_GET(LpJobConfig->ulCSIXCFG);
  /* Unit index in HW info structure */
  LulHWUnitIndex = LpJobConfig->ucHWUnitIndex;

  /* Check mirror data */
  if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaBRS[LulBRSIndex].usBRS !=
    Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaBRS[LulBRSIndex])
  {
    /* Update return status to E_NOT_OK */
    LucReturnValue = E_NOT_OK;
  }
  else
  {
    for (LulCSCount = SPI_ZERO; ((E_OK == LucReturnValue) &&
      (LulCSCount < LpJobConfig->ucNoOfCS)); LulCSCount++)
    {
      /* MISRA Violation: START Msg(4:0491)-1 */
      if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaCFG[
        LpJobConfig->pCSArray[LulCSCount]] !=
        Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaCFG[
        LpJobConfig->pCSArray[LulCSCount]])
      /* END Msg(4:0491)-1 */
      {
        /* Update return status to E_NOT_OK */
        LucReturnValue = E_NOT_OK;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }

#if (SPI_FIFO_MODE == STD_ON)
  if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL1 !=
    Spi_GaaCSIHRegMirror[LulHWUnitIndex].ulMCTL1)
  {
    /* Update return status to E_NOT_OK */
    LucReturnValue = E_NOT_OK;
  }
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* If HW unit configured as slave, check MCTL0 */
  else if ((SPI_CSIX_PRS_SLAVE == LpJobConfig->usCSIXCTL2) &&
    (SPI_MEMMODE_FIFO == LpHWInfo->enMemoryMode))
#else
  else
#endif
  {
    if (Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0 !=
      Spi_GaaCSIHRegMirror[LulHWUnitIndex].usMCTL0)
    {
      /* Update return status to E_NOT_OK */
      LucReturnValue = E_NOT_OK;
    }
    else
    {
      /* Nothing to do */
    }
  }
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  else
  {
    /* Nothing to do */
  }
#endif
#endif /* (SPI_FIFO_MODE == STD_ON) */

  /* Return result of consistency check of CSIH registers */
  return LucReturnValue;
}
#endif /* (SPI_CSIH_CONFIGURED == STD_ON) */
#endif /* (SPI_CSIX_RAM_MIRROR == STD_ON) */

/*******************************************************************************
** Function Name       : Spi_CSIXTurnOnUnit
**
** Service ID          : Not Applicable
**
** Description         : This function start the clock of the HWUnit.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LucHWUnitIndex - Index of the HWUnit
**                       LucApiId - Service ID of API invoking this function.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function Invoked    : None
**
** Registers Used      : CSIXnCTL0
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTurnOnUnit(
  CONST(uint8, AUTOMATIC) LucHWUnitIndex,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_073 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint8, AUTOMATIC) LucCTL0RegValue;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[(uint32)LucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  /* Start CSIX clock operation */
  LucCTL0RegValue =
    (uint8)(Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0 |
    (uint8)(SPI_CSIX_PWR));

  SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0, LucCTL0RegValue,
    &Spi_GaaCTLRegMirror[(uint32)LucHWUnitIndex].ucCTL0,
    CTLREG_8_BIT_MASK, 8, LucApiId)
  /* References: SPI_DDD_ACT_073_REG001 */
}

/*******************************************************************************
** Function Name       : Spi_CSIXTurnOffUnit
**
** Service ID          : Not Applicable
**
** Description         : This function stop the clock of the HWUnit.
**
** Sync/Async          : Synchronous
**
** Re-entrancy         : Reentrant
**
** Input Parameters    : LucHWUnitIndex - Index of the HWUnit
**                       LucApiId - Service ID of API invoking this function.
**
** InOut Parameters    : None
**
** Output Parameters   : None
**
** Return parameter    : None
**
** Preconditions       : Spi Driver must be initialized
**
** Global Variable     : Spi_GpFirstHWUnit, Spi_GaaCSIXRegs
**
** Function Invoked    : None
**
** Registers Used      : CSIXnCTL0
*******************************************************************************/
/* QAC Warning: START Msg(2:3206)-6 */
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIXTurnOffUnit(
  CONST(uint8, AUTOMATIC) LucHWUnitIndex,
  CONST(uint8, AUTOMATIC) LucApiId)
/* END Msg(2:3206)-6 */
/* References: SPI_DDD_ACT_060 */
{
  P2CONST(Spi_HWUnitInfoType, AUTOMATIC, SPI_CONFIG_DATA) LpHWInfo;
  VAR(uint32, AUTOMATIC) LulHWPhyIndex;
  VAR(uint8, AUTOMATIC) LucCTL0RegValue;

  /* MISRA Violation: START Msg(4:0491)-1 */
  LpHWInfo = &Spi_GpFirstHWUnit[(uint32)LucHWUnitIndex];
  /* END Msg(4:0491)-1 */
  LulHWPhyIndex = (uint32)LpHWInfo->ucPhysicalIndex;
  /* Stop CSIX clock operation */
  LucCTL0RegValue =
     (uint8)(Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0 &
     (uint8)(~SPI_CSIX_PWR));
  SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
    &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0, LucCTL0RegValue,
    &Spi_GaaCTLRegMirror[(uint32)LucHWUnitIndex].ucCTL0,
    CTLREG_8_BIT_MASK, 8, LucApiId)
  /* References: SPI_DDD_ACT_060_REG001 */
#if (SPI_CSIX_WRITE_VERIFY == SPI_WV_DISABLE)
  /* Dummy read if write-verify is disabled */
  RH850_IOREG_READ_ONLY(8,
     &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIXCTLRegs->ucCTL0)
#endif
}

#if (SPI_CSIH_CONFIGURED == STD_ON)
/*******************************************************************************
** Function Name      : Spi_CSIHInitRegs
**
** Service ID         : Not Applicable
**
** Description        : This function initializes specific registers of CSIH
**                      unit.
**
** Sync/Async         : Synchronous
**
** Re-entrancy        : Non-Reentrant
**
** Input Parameters   : LpJobConfig - Pointer to the Job configuration
**                      LulHWPhyIndex - Physical index of the HWUnit
**                      LenMemoryMode - memory mode associated with HW unit
**                        corresponding to hw physical index.
**                      LucApiId - Service ID of API invoking this function
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : Spi_Init must have been invoked.
**
** Global Variable    : Spi_GaaCSIXRegs, Spi_GaaCSIHRegMirror
**
** Function invoked   : Spi_CSIXTurnOnUnit, Spi_CSIXTurnOffUnit
**
** Registers Used     : CSIHnMCTL0, CSIHnMCTL1, CSIHnMCTL2, CSIHnBRSm
**
*******************************************************************************/
static FUNC(void, SPI_PRIVATE_CODE) Spi_CSIHInitRegs(
  CONSTP2CONST(Spi_JobConfigType, AUTOMATIC, SPI_CONFIG_DATA) LpJobConfig,
  CONST(uint32, AUTOMATIC) LulHWPhyIndex,
  CONST(Spi_MemoryModeType, AUTOMATIC) LenMemoryMode,
  CONST(uint8, AUTOMATIC) LucApiId)
/* References: SPI_DDD_ACT_091 */
{
#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  VAR(uint32, AUTOMATIC) LulBRSIndex;
#endif
  VAR(uint16, AUTOMATIC) LusMCTL0RegValue;

#if ((SPI_CSIX_RAM_MIRROR == STD_ON) || \
    (SPI_DUAL_BUFFER_MODE == STD_ON ) || (SPI_TX_ONLY_MODE == STD_ON))
  VAR(uint32, AUTOMATIC) LulHWUnitIndex;
  LulHWUnitIndex = LpJobConfig->ucHWUnitIndex;
#endif

#if (SPI_PERSISTENT_HW_CONFIGURATION_ENABLED == STD_OFF)
  /* Reset BRS registers */
  for (LulBRSIndex = SPI_ZERO; LulBRSIndex < SPI_CSIH_BRS_NUM; LulBRSIndex++)
  {
    /* QAC Warning: START Msg(2:3441)-3 */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->aaBRS[LulBRSIndex].usBRS,
      SPI_CSIH_BRS_DEFAULT,
      &Spi_GaaCSIHRegMirror[LulHWUnitIndex].aaBRS[LulBRSIndex],
      CTLREG_16_BIT_MASK, 16, LucApiId)
    /* END Msg(2:3441)-3 */
    /* References: SPI_DDD_ACT_091_REG002 */
  }
#endif

  /* Setting of MCTL0 register */
  if ((SPI_INIT_SID == LucApiId) || (SPI_SELFTEST_SID == LucApiId))
  {
    /* Clear FIFO time-out bits and set memory mode */
    LusMCTL0RegValue = Spi_GaaCSIXRegs[
      LulHWPhyIndex].pCSIHRegs->usMCTL0 & SPI_CSIH_TO_MASK;
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_FIFO_MODE == STD_ON) ||\
  (SPI_TX_ONLY_MODE == STD_ON))
    if (SPI_MEMMODE_DIRECT_ACCESS != LenMemoryMode)
    {
      /* Set memory mode bits */
      LusMCTL0RegValue = LusMCTL0RegValue |
        (LpJobConfig->usCSIHMCTL0 & SPI_CSIH_MMS_MASK);
    }
    else
    {
       /* Nothing to do */
    }
#endif
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0, LusMCTL0RegValue,
      &Spi_GaaCSIHRegMirror[LulHWUnitIndex].usMCTL0,
      CTLREG_16_BIT_MASK, 16, LucApiId)
      /* References: SPI_DDD_ACT_091_REG003 */
  }
  else
  {
    /* Reset MCTL0 register */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->usMCTL0,
      SPI_CSIH_MCTL0_DEFAULT,
      &Spi_GaaCSIHRegMirror[LulHWUnitIndex].usMCTL0,
      CTLREG_16_BIT_MASK, 16, LucApiId)
    /* References: SPI_DDD_ACT_091_REG004 */
  }

  /* Reset MCTL1 register */
#if (SPI_FIFO_MODE == STD_ON)
  if (SPI_MEMMODE_FIFO == LenMemoryMode)
  {
    /* Clear memory control bits in FIFO mode */
    SPI_CSIX_WRITE_VERIFY_AND_MIRROR_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL1,
      SPI_CSIH_MCTL1_DEFAULT,
      &Spi_GaaCSIHRegMirror[LulHWUnitIndex].ulMCTL1,
      CTLREG_32_BIT_MASK, 32, LucApiId)
    /* References: SPI_DDD_ACT_091_REG005 */
  }
  else
  {
    /* Nothing to do */
  }
#endif

  /* Reset MCTL2 register */
#if ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE == STD_ON))
  if ((SPI_MEMMODE_DUAL_BUFFER == LenMemoryMode) ||
    (SPI_MEMMODE_TX_ONLY == LenMemoryMode))
  {
    /* Set PWR since writing to CSIHnMCTL2 is prohibited when PWR = 0 */
    Spi_CSIXTurnOnUnit((uint8)LulHWUnitIndex, LucApiId);

    /* Reset MCTL2 register as default */
    SPI_WRITE_REG_ONLY(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL2,
      SPI_CSIH_MCTL2_DEFAULT)
    /* References: SPI_DDD_ACT_091_REG007 */
    SPI_CSIX_VERIFY_WRITE_INIT_RUNTIME(
      &Spi_GaaCSIXRegs[LulHWPhyIndex].pCSIHRegs->ulMCTL2,
      SPI_CSIH_MCTL2_DEFAULT, CTLREG_32_BIT_MASK, 32, LucApiId)

    /* Clear CTL0 for writing other registers */
    Spi_CSIXTurnOffUnit((uint8)LulHWUnitIndex, LucApiId);
  }
  else
  {
    /* Nothing to do */
  }
#endif /* End of ((SPI_DUAL_BUFFER_MODE == STD_ON) || (SPI_TX_ONLY_MODE)) */
}
#endif /* End of (SPI_CSIH_CONFIGURED == STD_ON) */

#define SPI_STOP_SEC_PRIVATE_CODE
/* QAC Warning: START Msg(2:0832)-4 */
#include SPI_MEMMAP_FILE
/* END Msg(2:0832)-4 */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
