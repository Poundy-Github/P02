/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* File name    = rh850_Types.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012 - 2019 Renesas Electronics Corporation                   */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for platform dependent types                                     */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  03-Sep-2012  : Initial Version
 * V1.0.1:  05-Dec-2013  : As per Mantis #17424 note 0110082,Macro definition
 *                         added for supervisor mode(SV) write enabled
 *                         Registers IMR & ICxxx access.
 * V1.0.2:  06-Jan-2014  : As per Mantis #17424,Macro definition
 *                         added for supervisor mode(SV) write enabled
 *                         Registers IMR & ICxxx direct write.
 * V1.0.3:  22-Apr-2014  : As per Mantis #17424:0134318,replaced the Macros
 *                         corresponds to write operation of supervisor
 *                         mode(SV) write enabled registers IMR & ICxxx.
 * V1.0.4:  22-Jun-2014  : As per Mantis #22157, Macro definitions corresponding
 *                         to supervisor mode(SV) write enabled registers IMR &
 *                         ICxxx direct write are modified to avoid compilation
 *                         issues due to concatenation operator "##".
 *
 * V1.0.5:     26-Sep-2017: #ARDAABD-2261
 *                          1. Added RH850_SET_IOREG_SYNCP
 *                          2. Added RH850_CLEAR_IOREG_SYNCP
 *                          3. Added RH850_SV_SET_ICR_SYNCP
 *                          4. Added RH850_SV_CLEAR_ICR_SYNCP
 *                          5. Added RH850_SV_WRITE_ICR_SYNCP
 *                          6. Added RH850_SV_SET_IMR_SYNCP
 *                          7. Added RH850_SV_CLEAR_IMR_SYNCP
 *                          8. Added RH850_SV_WRITE_IMR_SYNCP
 *
 * V1.0.6:  09-Aug-2018 : As part of ARDAABD-3707
 *                        Following changes are made:
 *                        1.Add RH850_DUMMY_READ_SYNCP to fix the fault
 *                         synchronization at the timing when control shifts from MCAL
 *                         to application.
 *
 * V1.0.7: 09-Aug-2018 : Following changes are made:
 *                       As part of ARDAABD-2420, Following changes are made:
 *                       1.Replace the processing in the original code with the
 *                         macro value SetIORegSyncpDummyRead().
 *
 * V1.0.8:  18-Oct-2018 : As part of ARDAABD-3707
 *                        Remove the RH850_DUMMY_READ_SYNCP Marco
 *
 * V1.0.9:  23-Aug-2019 : Following changes are made:
 *                       1.As part of ARDAABD-4014,
 *                       Added macro RH850_DUMMY_READ_SYNCP().
 *
 * V1.0.10: 30-Oct-2019 : As part of commonized project,
 *                        1. Add RH850_IOREG_READ_ONLY
 *                        2. Add RH850_SV_MODE_REG_READ_ONLY
 *                        3. Add RH850_SV_MODE_REG_WRITE_ONLY
 */
/******************************************************************************/

#ifndef RH850_TYPES_H
#define RH850_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*
 * File version information
 */
#define V850_TYPES_SW_MAJOR_VERSION  1
#define V850_TYPES_SW_MINOR_VERSION  0
#define V850_TYPES_SW_PATCH_VERSION  10

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef unsigned int        uinteger;       /*           0 .. 65535           */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*******************************************************************************
**                      Macro                                                 **
*******************************************************************************/

/*  Macro definition for supervisor mode(SV) write enabled Registers
 *  IMR & ICxxx .
 */
/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_OR
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         writing which involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_ICR_OR(SIZE, ADDR, VAL)                                  \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))|(VAL)))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_AND
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         writing which involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_ICR_AND(SIZE, ADDR, VAL)                                 \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))&(VAL)))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_ICR_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register ICxxx register
**                         direct writing operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_ICR_WRITE_ONLY(SIZE, ADDR, VAL)                          \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            (VAL))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_OR
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         writing which involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address.
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_IMR_OR(SIZE, ADDR, VAL)                                  \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))|(VAL)))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_AND
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         writing which involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_IMR_AND(SIZE, ADDR, VAL)                                 \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))&(VAL)))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_IMR_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write enabled Register IMR register
**                         direct writing operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_IMR_WRITE_ONLY(SIZE, ADDR, VAL)                          \
                            (*((volatile uint##SIZE*)(ADDR)) = (VAL))          \


/*******************************************************************************
** Macro Name            : RH850_SET_IOREG_SYNCP
**
** Description           : This Macro performs setting of IOREG with SYNCP.
**                         Dummy read of register is executed prior to write.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SET_IOREG_SYNCP(SIZE, ADDR, VAL)                                 \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))|(VAL)));        \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_CLEAR_IOREG_SYNCP
**
** Description           : This Macro performs clearing of IOREG with SYNCP.
**                         Dummy read of register is executed prior to write.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_CLEAR_IOREG_SYNCP(SIZE, ADDR, VAL)                               \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))&(VAL)));        \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_IOREG_READ_ONLY
**
** Description           : This Macro performs IOREG read only and syncp.
**
** Input Parameters      : SIZE, ADDR
**                         SIZE : Register Access Size.
**                         ADDR : Register address
*******************************************************************************/
#define RH850_IOREG_READ_ONLY(SIZE, ADDR)                                 \
                            (*((volatile uint##SIZE*)(ADDR)));


/*******************************************************************************
** Macro Name            : RH850_SV_SET_ICR_SYNCP
**
** Description           : This Macro performs supervisor mode setting of
**                         ICR with SYNCP.
**                         Writing operation involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_SET_ICR_SYNCP(SIZE, ADDR, VAL)                                \
                            RH850_SV_MODE_ICR_OR(SIZE, ADDR, VAL);             \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_SV_CLEAR_ICR_SYNCP
**
** Description           : This Macro performs supervisor mode clearing of
**                         ICR with SYNCP.
**                         Writing operation involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_CLEAR_ICR_SYNCP(SIZE, ADDR, VAL)                              \
                            RH850_SV_MODE_ICR_AND(SIZE, ADDR, VAL);            \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_SV_WRITE_ICR_SYNCP
**
** Description           : This Macro performs supervisor mode writing of ICR
**                         with direct write to the register.
**                         SYNCP is executed after the write.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_WRITE_ICR_SYNCP(SIZE, ADDR, VAL)                              \
                            RH850_SV_MODE_ICR_WRITE_ONLY(SIZE, ADDR, VAL);     \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_SV_SET_IMR_SYNCP
**
** Description           : This Macro performs supervisor mode setting of
**                         IMR with SYNCP.
**                         Writing operation involves an OR operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_SET_IMR_SYNCP(SIZE, ADDR, VAL)                                \
                            RH850_SV_MODE_IMR_OR(SIZE, ADDR, VAL);             \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_SV_CLEAR_IMR_SYNCP
**
** Description           : This Macro performs supervisor mode setting of
**                         IMR with SYNCP.
**                         Writing operation involves an AND operation.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_CLEAR_IMR_SYNCP(SIZE, ADDR, VAL)                              \
                            RH850_SV_MODE_IMR_AND(SIZE, ADDR, VAL);            \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name            : RH850_SV_WRITE_IMR_SYNCP
**
** Description           : This Macro performs supervisor mode writing of IMR
**                         with direct write to the register.
**                         SYNCP is executed after the write.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_WRITE_IMR_SYNCP(SIZE, ADDR, VAL)                              \
                            RH850_SV_MODE_IMR_WRITE_ONLY(SIZE, ADDR, VAL);     \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")


/*******************************************************************************
** Macro Name             : RH850_DUMMY_READ_SYNCP
**
** Description            : This Macro performs Synchronous processing
**                          with dummy read and SYNCP.
**
** Input Parameters       : SIZE, ADDR
**                          SIZE : Register Access Size.
**                          ADDR : Register address.
*******************************************************************************/
#define RH850_DUMMY_READ_SYNCP(SIZE, ADDR)                                     \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")

/*******************************************************************************
** Macro Name             : SetIORegSyncpDummyRead
**
** Description            : This Macro performs Synchronous processing
**                          with dummy read and SYNCP.
**
** Input Parameters       : SIZE, ADDR, VAL
**                          SIZE : Register Access Size.
**                          ADDR : Register address.
**                          VAL  : Value to be written to the register.
*******************************************************************************/

#define SetIORegSyncpDummyRead(SIZE, ADDR, VAL)                                \
                            (*((volatile uint##SIZE*)(ADDR)) =                 \
                            ((*((volatile uint##SIZE*)(ADDR)))|(VAL)));        \
                            (*((volatile uint##SIZE*)(ADDR)));                 \
                            __asm("syncp")

/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_READ_ONLY
**
** Description           : This Macro performs a dummy reading a register
**
** Input Parameters      : SIZE, ADDR
**                         SIZE : Register Access Size.
**                         ADDR : Register address
*******************************************************************************/
#define RH850_SV_MODE_REG_READ_ONLY(SIZE, ADDR) \
                                    (*((volatile uint##SIZE*)(ADDR)))


/*******************************************************************************
** Macro Name            : RH850_SV_MODE_REG_WRITE_ONLY
**
** Description           : This Macro performs supervisor mode(SV)
**                         write register.
**
** Input Parameters      : SIZE, ADDR, VAL
**                         SIZE : Register Access Size.
**                         ADDR : Register address
**                         VAL  : Value to be written to the register.
*******************************************************************************/
#define RH850_SV_MODE_REG_WRITE_ONLY(SIZE, ADDR, VAL) \
                                 (*((volatile uint##SIZE*)(ADDR)) = \
                                 (VAL))


#endif /* RH850_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
