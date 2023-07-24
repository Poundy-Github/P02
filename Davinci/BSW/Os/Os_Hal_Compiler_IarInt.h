/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Hal_Compiler
 * \{
 *
 * \file       Os_Hal_Compiler_IarInt.h
 * \brief      Compiler abstraction for compiler IAR
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_COMPILER_IAR_H
# define OS_HAL_COMPILER_IAR_H
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"
# include "Os_Hal_Core_Types.h"
# include "Os_MemoryProtection_Cfg.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief      Declares a function with a compiler specific attribute.
 *  \details    The implementations prototype has to be created with OS_FUNC_ATTRIBUTE_DEFINITION.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
# define OS_FUNC_ATTRIBUTE_DECLARATION(rettype, memclass, attribute, functionName, arguments) \
      attribute FUNC(rettype, memclass)  functionName arguments                                                         /* PRQA S 3410, 3453 */ /* MD_Os_Rule20.7_3410, MD_MSR_FctLikeMacro */

/*! \brief      Provides a function prototype for function definitions with a compiler specific attribute.
 *  \details    The declaration has to be created with OS_FUNC_ATTRIBUTE_DECLARATION.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
# define OS_FUNC_ATTRIBUTE_DEFINITION(rettype, memclass, attribute, functionName, arguments) \
      attribute FUNC(rettype, memclass)  functionName arguments                                                         /* PRQA S 3410, 3453 */ /* MD_Os_Rule20.7_3410, MD_MSR_FctLikeMacro */

/*! \brief    Tells the compiler that the conditional statement is likely to be true.
 *  \details
 *  The compiler, in turn, can then perform block reordering, and other optimization to
 *  improve the performance of conditional branches.
 *
 *  Availability: GCC ('__builtin_expect'), Diab
 *
 *  \param[in]  CONDITION   The condition which is likely to be true
 */
# define OS_LIKELY(CONDITION)       (CONDITION)                                                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief    Tells the compiler that the conditional statement is likely to be false.
 *  \details
 *  The compiler, in turn, can then perform block reordering, and other optimization to
 *  improve the performance of conditional branches.
 *
 *  Availability: GCC ('__builtin_expect'), Diab
 *
 *  \param[in]  CONDITION   The condition which is likely to be false
 */
# define OS_UNLIKELY(CONDITION)     (CONDITION)                                                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief    Force the compiler to inline a function.
 *  \details  This attribute forces the compiler to inline the specified function,
 *        regardless of the optimization strategy of the compiler itself.
 *        On some compilers you may be able to disable even this kind of inlining, using debugging options.
 *
 *        Availability: GCC ('always_inline'), Diab, Tasking
 */
# define OS_ALWAYS_INLINE

/*! \brief  Abstraction for HAL specific compiler attribute to prevent from inlining a function. */
# define OS_HAL_NOINLINE

/*! \brief    This attribute tells the compiler that a function never returns.
 *  \details
 * It can then optimize without regard to what would happen if the function ever did return.
 * This makes slightly better code. More importantly, it helps avoid spurious warnings of uninitialized variables.
 *
 * Availability: GCC ('noreturn'), Diab, Tasking, GreenHills
 */
# define OS_NORETURN


/*! \brief    This attribute forces inlining of all function calls in a function, including nested function calls.
 * \details
 * Whether the function itself is considered for inlining depends on its size and the current inlining parameters.
 *
 * Availability: GCC ('flatten'), Diab, Tasking
 */
# define OS_FLATTEN


/*! \brief    This attribute tells that a function has no side effects and will not access global data.
 *  \details
 * This can help the compiler to optimize code. Such functions do not examine any values except their arguments,
 * and have no effects except the return value. This is just slightly more strict class than the OS_PURE attribute,
 * since function is not allowed to read global memory.
 *
 * Availability: GCC ('const'), Diab ('no_side_effects'), Tasking, Green Hills
 */
# define OS_NOSIDEEFFECTS


/*! \brief    This attribute tells that a function has no side effects, although it may read global data.
 *  \details
 * Such pure functions can be subject to common subexpression elimination and loop optimization.
 *
 * Availability: GCC ('pure'), Diab, Tasking, Green Hills
 */
# define OS_PURE

/*! \brief         Abstraction of executing arbitrary assembler instruction
 *  \param[in]     x       Assembler instruction
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_ASM(x)             __asm(x)

/*! \brief         Abstraction of the assembler align directive
 *  \param[in]     val      Alignment
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_ALIGN(val)

/*! \brief         Defines an externally visible identifier.
 *  \param[in]     name      Name of the identifier
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_LABEL(name)        __asm("PUBLIC _"name);__asm("_"name":")

/*! \brief         Starts a program code (.text) section
 *  \details       --no details--
 *  \param[in]     name      Name of the section
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SECTION(name)      __asm("section "name" :CODE(2)")

/*! \brief         Stores the value of a constant expressions as successive 32-bit data.
 *  \details       --no details--
 *  \param[in]     name
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_WORD(name)         __asm(".word _"name);

/*! \brief         Abstraction of the assembler nop instruction
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_NOP()              __asm("nop")

/*! \brief         Disables acknowledgment of EI level interrupts
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           Supervisor mode
 */
# define Os_Hal_DisableGlobal()    __asm("di")

/*! \brief         Enables acknowledgment of EI level interrupts
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           Supervisor mode
 */
# define Os_Hal_EnableGlobal()     __asm("ei")

/*! \brief         Abstraction of the assembler synci instruction
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SyncInstruction()  __asm("synci")

/*! \brief         Abstraction of the assembler syncp instruction
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SyncPipeline()     __asm("syncp")

/*! \brief         Abstraction of the assembler syncm instruction
 *  \details       --no details--
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SyncMemory()       __asm("syncm")

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* ECO_IGNORE_BLOCK_BEGIN */

/***********************************************************************************************************************
 *  Os_Hal_GetSP()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetSP(void)
 *  \brief        Get the current stack pointer.
 *  \details      --no details--
 *
 *  \return       The current stack pointer.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetSP(void)
{
  uint32 stackpointer;

  __asm("mov r3, %0"
        : "=r"(stackpointer)
        :
        :);

  return stackpointer;
}


/***********************************************************************************************************************
 *  Os_Hal_SetLP()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetLP(uint32 val)
 *  \brief        Set the current stack pointer.
 *  \details      --no details--
 *
 *  \param[in]    The link pointer to set.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static void Os_Hal_SetLP(uint32 val)
{
  __asm("mov %0, r31"
        :
        : "r" (val)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_GetLP()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetLP(void)
 *  \brief        Returns the current link pointer.
 *  \details      --no details--
 *
 *  \return       The current link pointer.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetLP(void)
{
  uint32 linkpointer;

  __asm("mov r31, %0"
        : "=r"(linkpointer)
        :
        :);

  return linkpointer;
}


/***********************************************************************************************************************
 *  Os_Hal_SetPSW()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetPSW(uint32 value)
 *  \brief      Writes a value to the PSW register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the PSW register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetPSW(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 5, 0"
        :
        : "r" (value)
        :);
}



/***********************************************************************************************************************
 *  Os_Hal_SetPMR()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetPMR(uint32 value)
 *  \brief      Writes a value to the PMR register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the PMR register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode and EI level interrupts disabled.
 **********************************************************************************************************************/
static void Os_Hal_SetPMR(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 11, 2"
        :
        : "r"(value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetASID()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetASID(uint32 value)
 *  \brief      Writes a value to the ASID register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the ASID register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetASID(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 7, 2"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetCTBP()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetCTBP(uint32 value)
 *  \brief      Writes a value to the CTBP register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the CTBP register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static void Os_Hal_SetCTBP(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 20, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetSCCFG()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetSCCFG(uint32 value)
 *  \brief      Writes a value to the SCCFG register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the SCCFG register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetSCCFG(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 11, 1"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetSCBP()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetSCBP(uint32 value)
 *  \brief      Writes a value to the SCBP register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the SCBP register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetSCBP(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 12, 1"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetEIPC()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetEIPC(uint32 value)
 *  \brief      Writes a value to the EIPC register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the EIPC register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetEIPC(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 0, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetEIPSW()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetEIPSW(uint32 value)
 *  \brief      Writes a value to the EIPSW register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the EIPSW register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetEIPSW(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 1, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetEIWR()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetEIWR(uint32 value)
 *  \brief      Writes a value to the EIWR register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the EIWR register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetEIWR(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 28, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetFPSR()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetFPSR(uint32 value)
 *  \brief      Writes a value to the FPSR register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the FPSR register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode or enabled CU0 flag in PSW.
 **********************************************************************************************************************/
static void Os_Hal_SetFPSR(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 6, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetFPEPC()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetFPEPC(uint32 value)
 *  \brief      Writes a value to the FPEPC register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the FPEPC register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode or enabled CU0 flag in PSW.
 **********************************************************************************************************************/
static void Os_Hal_SetFPEPC(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 7, 0"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetEBASE()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetEBASE(uint32 value)
 *  \brief      Writes a value to the EBASE register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the EBASE register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetEBASE(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 3, 1"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetINTBP()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetINTBP(uint32 value)
 *  \brief      Writes a value to the INTBP register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the INTB register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetINTBP(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 4, 1"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetINTCFG()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetINTCFG(uint32 value)
 *  \brief      Writes a value to the INTCFG register.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the INTCFG register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetINTCFG(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 13, 2"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPM()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPM(uint32 value)
 *  \brief      Sets the memory protection operation mode register to the passed value.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPU region control register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPM(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 0, 5"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPRC()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPRC(uint32 value)
 *  \brief      Sets the MPU region control register to the passed value.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPU region control register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPRC(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 1, 5"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_GetMPLA0()
 **********************************************************************************************************************/
/*! \fn         uint32 Os_Hal_GetMPLA0(void)
 *  \brief      Returns the protection area minimum address of the specific core MPU region.
 *  \details    --no details--
 *
 *  \return       MPLA0 register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          SUPERVISOR
 **********************************************************************************************************************/
static uint32 Os_Hal_GetMPLA0(void)
{
  uint32 mpla0;

  __asm("stsr 0, %0, 6"
        : "=r" (mpla0)
        :
        :);

  return mpla0;
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA0()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA0(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA0 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA0(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 0, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_GetMPUA0()
 **********************************************************************************************************************/
/*! \fn         uint32 Os_Hal_GetMPUA0(void)
 *  \brief      Returns the protection area minimum address of the specific core MPU region.
 *  \details    --no details--
 *
 *  \return       MPUA0 register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetMPUA0(void)
{
  uint32 mpua0;

  __asm("stsr 1, %0, 6"
        : "=r" (mpua0)
        :
        :);

  return mpua0;
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA0()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA0(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA0 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA0(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 1, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT0()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT0(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT0 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT0(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 2, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA1()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA1(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA1 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA1(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 4, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA1()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA1(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA1 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA1(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 5, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT1()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT1(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT1 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT1(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 6, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA2()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA2(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA2 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA2(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr r11, 8, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA2()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA2(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA2 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA2(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 9, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT2()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT2(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT2 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT2(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 10, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA3()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA3(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA3 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA3(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 12, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA3()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA3(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA3 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA3(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 13, 6"
        :
        : "r" (value)
        :);
}



/***********************************************************************************************************************
 *  Os_Hal_SetMPAT3()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT3(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT3 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT3(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 14, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA4()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA4(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA4 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA4(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 16, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA4()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA4(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA4 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA4(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 17, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT4()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT4(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT4 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT4(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 18, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA5()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA5(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA5 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA5(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 20, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA5()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA5(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA5 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA5(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 21, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT5()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT5(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT5 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT5(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 22, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA6()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA6(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA6 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA6(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 24, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA6()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA6(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA6 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA6(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 25, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT6()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT6(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT6 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT6(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 26, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA7()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA7(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA7 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA7(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 28, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA7()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA7(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA7 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA7(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 29, 6"
        :
        : "r" (value)
        :);
}



/***********************************************************************************************************************
 *  Os_Hal_SetMPAT7()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT7(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT7 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT7(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 30, 6"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA8()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA8(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA0 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA8(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 0, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA8()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA8(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA8 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA8(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 1, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT8()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT8(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT8 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT8(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 2, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA9()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA9(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA9 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA9(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 4, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA9()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA9(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA9 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA9(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 5, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT9()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT9(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT9 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT9(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 6, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA10()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA10(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA10 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA10(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 8, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA10()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA10(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA10 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA10(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 9, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT10()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT10(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT10 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT10(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 10, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA11()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA11(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA11 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA11(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 12, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA11()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA11(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA11 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA11(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 13, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT11()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT11(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT11 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT11(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 14, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA12()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA12(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA12 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA12(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 16, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA12()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA12(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA12 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA12(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 17, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT12()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT12(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT12 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT12(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 18, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA13()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA13(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA13 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA13(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 20, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA13()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA13(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA13 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA13(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 21, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT13()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT13(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT13 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT13(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 22, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA14()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA14(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA14 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA14(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 24, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA14()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA14(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA14 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA14(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 25, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT14()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT14(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT14 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT14(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 26, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPLA15()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPLA15(uint32 value)
 *  \brief      Sets the protection area minimum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPLA15 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPLA15(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 28, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPUA15()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPUA15(uint32 value)
 *  \brief      Sets the protection area maximum address to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPUA15 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPUA15(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 29, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPAT15()
 **********************************************************************************************************************/
/*! \fn         void Os_Hal_SetMPAT15(uint32 value)
 *  \brief      Sets the protection area attributes to the passed address.
 *  \details    --no details--
 *
 *  \param[in]    value     The value to write to the MPAT15 register.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPAT15(uint32 value)
{
  __asm("mov %0, r11\n"
        "ldsr  r11, 30, 7"
        :
        : "r" (value)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_GetCoreID()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetCoreID(void)
 *  \brief        Returns the physical id of the core.
 *  \details      --no details--
 *
 *  \return       The current core id.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetCoreID(void)
{
  uint32 coreId;

  __asm("stsr 0, %0, 2\n"
        "shr 17, %0"
        : "=r" (coreId)
        :
        :);

  return coreId;
}


/***********************************************************************************************************************
 *  Os_Hal_GetIntState()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetIntState(void)
 *  \brief        Returns the interrupt state of the core.
 *  \details      --no details--
 *
 *  \return        0x0   Interrupt acknowledgment is enabled
 *                 0x20  Interrupt acknowledgment is disabled
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetIntState(void)
{
  uint32 intState;

  __asm("stsr 5, %0, 0\n"
        "andi 0x20, %0, %0"
        : "=r" (intState)
        :
        :);

  return intState;
}


/***********************************************************************************************************************
 *  Os_Hal_GetPSW()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetPSW(void)
 *  \brief        Returns the program status word of the core.
 *  \details      --no details--
 *
 *  \return       PSW register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetPSW(void)
{
  uint32 psw;

  __asm("stsr 5, %0, 0"
        : "=r" (psw)
        :
        :);

  return psw;
}


/***********************************************************************************************************************
 *  Os_Hal_GetPMR()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetPMR(void)
 *  \brief        Returns the interrupt priority masking register of the core.
 *  \details      --no details--
 *
 *  \return       PMR register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode and EI level interrupts disabled.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetPMR(void)
{
  uint32 pmr;

  __asm("stsr 11, %0, 2"
        : "=r" (pmr)
        :
        :);

  return pmr;
}


/***********************************************************************************************************************
 *  Os_Hal_GetASID()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetASID(void)
 *  \brief        Returns the address space identifier register of the core.
 *  \details      --no details--
 *
 *  \return       ASID register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetASID(void)
{
  uint32 asid;

  __asm("stsr 7, %0, 2"
        : "=r" (asid)
        :
        :);

  return asid;
}


/***********************************************************************************************************************
 *  Os_Hal_GetSCCFG()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetSCCFG(void)
 *  \brief        Returns the SYSCALL operation settings  of the core.
 *  \details      --no details--
 *
 *  \return       SYSCALL operation settings
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetSCCFG(void)
{
  uint32 sccfg;

  __asm("stsr 11, %0, 1"
        : "=r" (sccfg)
        :
        :);

  return sccfg;
}


/***********************************************************************************************************************
 *  Os_Hal_GetCTBP()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetCTBP(void)
 *  \brief        Returns the SYSCALL base pointer register of the core.
 *  \details      --no details--
 *
 *  \return       SYSCALL base pointer
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetCTBP(void)
{
  uint32 ctbp;

  __asm("stsr 12, %0, 1"
        : "=r" (ctbp)
        :
        :);

  return ctbp;
}


/***********************************************************************************************************************
 *  Os_Hal_GetSCBP()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetSCBP(void)
 *  \brief        Returns the CALLT base pointer register of the core.
 *  \details      --no details--
 *
 *  \return       CALLT base pointer
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_GetSCBP(void)
{
  uint32 scbp;

  __asm("stsr 20, %0, 0"
        : "=r" (scbp)
        :
        :);

  return scbp;
}


/***********************************************************************************************************************
 *  Os_Hal_GetEIPC()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetEIPC(void)
 *  \brief        Gets the EIPC register of the core.
 *  \details      --no details--
 *
 *  \return       EIPC register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetEIPC(void)
{
  uint32 eipc;

  __asm("stsr 0, %0, 0"
        : "=r" (eipc)
        :
        :);

  return eipc;
}


/***********************************************************************************************************************
 *  Os_Hal_GetEIPSW()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetEIPSW(void)
 *  \brief        Gets the EIPSW register of the core.
 *  \details      --no details--
 *
 *  \return       EIPSW register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetEIPSW(void)
{
  uint32 eipsw;

  __asm("stsr 1, %0, 0"
        : "=r" (eipsw)
        :
        :);

  return eipsw;
}


/***********************************************************************************************************************
 *  Os_Hal_GetEIWR()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetEIWR(void)
 *  \brief        Gets the EI level exception working register of the core.
 *  \details      --no details--
 *
 *  \return       EIWR register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetEIWR(void)
{
  uint32 eiwr;

  __asm("stsr 28, %0, 0"
        : "=r" (eiwr)
        :
        :);

  return eiwr;
}


/***********************************************************************************************************************
 *  Os_Hal_GetFPSR()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetFPSR(void)
 *  \brief        Gets the floating-point configuration/status register of core.
 *  \details      --no details--
 *
 *  \return       FPSR register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode or enabled CU0 flag in PSW.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetFPSR(void)
{
  uint32 fpsr;

  __asm("stsr 6, %0, 0"
        : "=r" (fpsr)
        :
        :);

  return fpsr;
}


/***********************************************************************************************************************
 *  Os_Hal_GetFPEPC()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetFPEPC(void)
 *  \brief        Gets the floating-point exception program counter register of core.
 *  \details      --no details--
 *
 *  \return       FPEPC register
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode or enabled CU0 flag in PSW.
 **********************************************************************************************************************/
static uint32 Os_Hal_GetFPEPC(void)
{
  uint32 fpepc;

  __asm("stsr 7, %0, 0"
        : "=r" (fpepc)
        :
        :);

  return fpepc;
}


/***********************************************************************************************************************
 *  Os_Hal_EndOfInterrupt()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_EndOfInterrupt(void)
 *  \brief        Signals the end of an interrupt to the hardware.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
static void Os_Hal_EndOfInterrupt(void)
{
  /* #10 Get the current PSW. */
  __asm("stsr 5, r12, 0 \n"
  /* #20 Disable all EIINT interrupts. */
        "di \n"
  /* #30 Prepare PC. */
        "mov Os_Hal_EndOfIntLabel, r11\n"
        "ldsr r11, 0, 0 \n"
  /* #40 Prepare PSW. */
        "ldsr r12, 1, 0 \n"
  /* #50 Signal end of interrupt. */
        "eiret \n"
        "Os_Hal_EndOfIntLabel:");
}


/***********************************************************************************************************************
 *  Os_Hal_CallFunc()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_CallFunc(uint32* current, uint32* next)
 *  \brief        Enters a function defined by 'next' without performing a stack switch.
 *  \details      --no details--
 *
 *  \param[in]    current   The current context. Parameter must not be NULL.
 *  \param[in]    next      The context to be continued. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
static void Os_Hal_CallFunc(uint32* current, const uint32* next)
{
  /* #10 Store current context. */
  __asm("pushsp r20-r29\n"          /* Save registers r20 ... r29 to stack. */
        "mov FuncCallReturn, r11\n" /* Get label for return. */
        "st.w r11, 0x00[%0]\n"      /* Save PC. */
        "st.w r3, 0x10[%0]\n"       /* Save SP. */
  /* #20 Prepare new context. */
        "ld.w 0x20[%1], %0\n"       /* Get first parameter. */
        "ld.w 0x00[%1], r12\n"      /* Get PC. */
        "ld.w 0x04[%1], r11\n"      /* Get PSW. */
        "ldsr r11, 5, 0\n"
  /* #30 Synchronize instruction fetches. */
        "synci\n"                   /* Sync instructions. */
  /* #40 Execute next context. */
        "jmp [r12]\n"               /* Branch to function. */
        "FuncCallReturn:\n"
  /* #50 Restore permanent registers of current context. */
        "popsp r20-r29"             /* Restore registers r20 ... r29 from stack. */
        :
        : "r" (current), "r" (next)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_CallFuncOnStack()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_CallFuncOnStack(uint32* current, uint32* next)
 *  \brief        Enters a function defined by 'next' with stack switch.
 *  \details      --no details--
 *
 *  \param[in]    current   The current context. Parameter must not be NULL.
 *  \param[in]    next      The context to be continued. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
static void Os_Hal_CallFuncOnStack(uint32* current, const uint32* next)
{
  /* #10 store current context. */
  __asm("pushsp r20-r29 \n"         /* save registers r20 ... r29 to stack */
        "mov FuncCallReturnCallFuncOnStack, r11 \n" /* get label for return */
        "st.w r11, 0x00[%0] \n"     /* save PC */
        "st.w r3, 0x10[%0] \n"      /* save SP */
  /* #20 Switch to the next context stack. */
        "ld.w 0x10[%1], r3 \n"
 #if (OS_CFG_MEMORY_PROTECTION == STD_ON)
  /* #30 Reprogram stack window. */
        "ld.w 0x14[%1], r11 \n"     /* get MPLA0 */
        "ldsr r11, 0, 6 \n"         /* set MPLA0 */
        "ld.w 0x18[%1], r11 \n"     /* get MPUA0 */
        "ldsr r11, 1, 6 \n"         /* set MPUA0 */
        "ld.w 0x1C[%1], r11 \n"     /* get ASID */
        "ldsr r11, 7, 2 \n"         /* set ASID */
  /* #40 Synchronize the pipeline. */
        "syncp \n"
 #endif
  /* #50 Prepare next context. */
        "ld.w 0x20[%1], %0 \n"      /* get first parameter */
        "ld.w 0x00[%1], r12 \n"     /* get PC */
        "ld.w 0x04[%1], r11 \n"     /* get PSW */
        "ldsr r11, 5, 0 \n"         /* set PSW */
  /* #60 Synchronize instruction fetch. */
        "synci \n"                  /* sync instructions */
  /* #70 Start next context. */
        "jmp [r12] \n"              /* branch to function */
        "FuncCallReturnCallFuncOnStack: \n"
  /* #80 Restore permanent register for current context on return to current context. */
        "popsp r20-r29"
        :
        : "r" (current), "r" (next)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_StartNextThread()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_StartNextThread(uint32* current, uint32* next)
 *  \brief        Starts the next thread.
 *  \details      --no details--
 *
 *  \param[in]    current   The current context. Parameter must not be NULL.
 *  \param[in]    next      The context to be continued. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
static void Os_Hal_StartNextThread(uint32* current, const uint32* next)
{
  /* #10 Store current context. */
  __asm("pushsp r20-r29 \n"      /* push r20 ... r29 onto stack */
        "mov Os_Hal_Thread_ReturnLabel, r11 \n"
        "st.w r11, 0x00[%0] \n"  /* save PC */
        "st.w SP, 0x10[%0] \n"   /* save SP */
  /* #20 Prepare next context. */
        "ld.w 0x10[%1], SP \n"
 #if (OS_CFG_MEMORY_PROTECTION == STD_ON)
  /* #30 Reprogram stack window and ASID. */
        "ld.w 0x14[%1], r11 \n"  /* get MPLA0 */
        "ldsr r11, 0, 6 \n"      /* set MPLA0 */
        "ld.w 0x18[%1], r11 \n"  /* get MPUA0 */
        "ldsr r11, 1, 6 \n"      /* set MPUA0 */
        "ld.w 0x1C[%1], r11 \n"  /* get ASID */
        "ldsr r11, 7, 2 \n"      /* set ASID */
  /* #40 Synchronize the pipeline. */
        "syncp \n"
 #endif
        "ld.w 0x00[%1], r12 \n"  /* get entry address */
        "ld.w 0x04[%1], r11 \n"  /* get PSW */
        "ldsr r11, 5, 0 \n"      /* set PSW */
  /* #50 Synchronize instruction fetch. */
        "synci \n"
  /* #60 Execute new context. */
        "jmp [r12] \n"
        "Os_Hal_Thread_ReturnLabel: \n"
  /* #70 Restore permanent register for current context on return to current context. */
        "popsp r20-r29"
        :
        : "r" (current), "r" (next)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_StartNext()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_StartNext(uint32* next)
 *  \brief        Starts the next thread.
 *  \details      --no details--
 *
 *  \param[in]    next      The context to be continued. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
static void Os_Hal_StartNext(const uint32* next)
{
  /* #10 Prepare next context */
  __asm("ld.w 0x00[%0], r12 \n"  /* get entry address */
        "ld.w 0x04[%0], r11 \n"  /* get PSW */
        "ld.w 0x10[%0], r3 \n"   /* set SP */
        "ldsr r11, 5, 0 \n"      /* set PSW */
  /* #20 Synchronize instruction fetch */
        "synci \n"
        "jmp [r12]"              /* branch to entry address */
        :
        : "r" (next)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_CountLeadingZeros()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_CountLeadingZeros(uint32 bitfield)
 *  \brief        Returns the number of leading zeros in bitfield.
 *  \details      --no details--
 *
 *  \param[in]    bitfield  The value to query.
 *
 *  \return       The number of leading zero bits.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
static uint32 Os_Hal_CountLeadingZeros(uint32 bitfield)
{
  uint32 zerosCount;

  __asm("mov %0, r6"
        :
        : "r" (bitfield)
        :);

  /* #10 Prepare default return value. */
  __asm("mov 32, r10 \n"
  /* # 20 Return default return value if passed bitfield is zero. */
        "cmp r0, r10 \n"
        "be Os_Hal_ReturnLabel \n"
  /* #30 Else count leading zeros. */
        "sch1l r6, r10 \n"
       "addi -1, r10, r10 \n"
        "Os_Hal_ReturnLabel: \n"
        :
        :
        :);

  __asm("mov r10, %0"
        : "=r" (zerosCount)
        :
        :);

  return zerosCount;
}


/***********************************************************************************************************************
 *  Os_Hal_GetDisableLevel()
 **********************************************************************************************************************/
/*! \fn           Os_Hal_IntLevelType Os_Hal_GetDisableLevel(Os_Hal_IntLevelType Level)
 *  \brief        Sets the current interrupt level and returns the previous one.
 *  \details      --no details--
 *
 *  param[in]     The level to set. Parameter must be in range [0, OS_HAL_PMR_MASK].
 *
 *  \return       The previous interrupt level
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static Os_Hal_IntLevelType Os_Hal_GetDisableLevel(Os_Hal_IntLevelType Level)
{
  Os_Hal_IntLevelType disableLevel;

  __asm("mov %0, r6"
        :
        : "r" (Level)
        :);

  __asm("stsr 5, r11, 0\n"
        "di\n"
        "stsr 11, r10, 0\n"
        "mov r6, r12\n"
        "ldsr r12, 11, 2\n"
        "ldsr r11, 5, 0"
        :
        :
        :);

  __asm("mov r10, %0"
        : "=r" (disableLevel)
        :
        :);

  return disableLevel;
}


/***********************************************************************************************************************
 *  Os_Hal_SetLevelG3X()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetLevelG3X(Os_Hal_IntLevelType Level)
 *  \brief        Set the current interrupt level.
 *  \details      --no details--
 *
 *  \param[in]    The level to set.  Parameter must be in range [0, OS_HAL_PMR_MASK].
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static void Os_Hal_SetLevelG3X(Os_Hal_IntLevelType Level)
{
  __asm("stsr 5, r11, 0 \n"
        "di \n"
        "ldsr %0, 11, 2 \n"
        "ldsr r11, 5, 0"
        :
        : "r" (Level)
        :);
}


/***********************************************************************************************************************
 *  Os_Hal_GetLevelG3X()
 **********************************************************************************************************************/
/*! \fn           Os_Hal_IntLevelType Os_Hal_GetLevelG3X(void)
 *  \brief        Returns the current interrupt level.
 *  \details      --no details--
 *
 *  \return       The current interrupt level.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static Os_Hal_IntLevelType Os_Hal_GetLevelG3X(void)
{
  Os_Hal_IntLevelType level;

  __asm("stsr 5, r11, 0 \n"         /* r11 = PSW */
        "di \n"                     /* disable interrupts */
        "stsr 11, %0, 2 \n"         /* r10 = PMR */
        "ldsr r11, 5, 0"            /* PSW = r11 */
        : "=r" (level)
        :
        :);

  return level;
}


/***********************************************************************************************************************
 *  Os_Hal_TryGetLock()
 **********************************************************************************************************************/
/*! \fn           Os_Hal_SpinlockResultType Os_Hal_TryGetLock(volatile uint32* addr)
 *  \brief        Tries to get a spinlock
 *  \details      --no details--
 *
 *  \param[in]    addr    The spinlock to get. Parameter must not be NULL.
 *
 *  \return       Returns whether getting the spinlock succeeded.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
static Os_Hal_SpinlockResultType Os_Hal_TryGetLock(volatile uint32* addr)
{
  Os_Hal_SpinlockResultType lockResult;

  __asm("mov %0, r6"
        :
        : "r" (addr)
        :);

  /* #10 Load spinlock result from passed addr and aquire link for passed addr. */
  __asm("ldl.w [r6], r10 \n"
  /* #20 Goto label osLock_NoSuccess of spinlock result is not 0. */
        "cmp   r0, r10 \n"
        "bne   osLock_NoSuccess \n"
  /* #30 Else try to write 1 to passed addr. */
        "mov   1, r10 \n"
        "stc.w r10, [r6] \n"
  /* #40 Goto osLock_Success if write access was successful (link was still valid). */
        "cmp   r0, r10 \n"
        "bne   osLock_Success \n"
  /* #50 Else return 0. */
        "osLock_NoSuccess: \n"
  /* #60 Write access successful. Return r10 (1). */
        "mov   0, r10 \n"
        "osLock_Success:"
        :
        :
        :);

  __asm("mov r10, %0"
        : "=r" (lockResult)
        :
        :);

  return lockResult;
}


/***********************************************************************************************************************
 *  Os_Hal_CoreGetCpuMode()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_CoreGetCpuMode(void)
 *  \brief        Returns the current CPU mode.
 *  \details      --no details--
 *
 *  \return       The current CPU mode. 1 = user mode, 0 = supervisor mode
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
static uint32 Os_Hal_CoreGetCpuMode(void)
{
  uint32 cpuMode;

  __asm("stsr 5, %0, 0\n"
        "shr 30, %0"
        : "=r" (cpuMode)
        :
        :);

  return cpuMode;
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPIDX0()
 **********************************************************************************************************************/
/*! \fn           void Os_Hal_SetMPIDX0(void)
 *  \brief        Sets MPIDX register access MPU region 0 registers.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
static void Os_Hal_SetMPIDX0(void)
{
  /* empty function, only needed for G4X cores */
}


/* ECO_IGNORE_BLOCK_END */

#endif /* OS_HAL_COMPILER_IARINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_IARInt.h
 **********************************************************************************************************************/
