/* Kernbauer Version: 1.16 Konfiguration: DrvTransCan Erzeugungsgangnummer: 1 */


/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 |  FILE DESCRIPTION
 |  -------------------------------------------------------------------------------------------------------------------
 |         File:  CanTrcv_30_Tja1145.h
 |      Project:  MICROSAR
 |       Module:  CAN Transceiver driver
 |    Generator:  DaVinci Configurator
 |  Description:  Header of the MICROSAR CAN Transceiver Driver.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Senol Cendere                 Ces           Vector Informatik GmbH
 *  Matthias Fleischmann          Fn            Vector Informatik GmbH
 *  Mihai Olariu                  Ou            Vector Informatik GmbH
 *  Timo Vanoni                   Tvi           Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  Jan Hammer                    Jan           Vector Informatik GmbH
 *  Carsten Gauglitz              Gaz           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2011-07-26  Tvi     -             First Implementation
 *  1.01.00   2012-03-05  Tvi     ESCAN00057891 AR3-1698: Add MISRA justifications in source code for automatic generation of MISRA reports
 *                                ESCAN00057890 AR3-1738: Add support for asynchronous transceiver driver
 *  2.00.00   2012-05-23  Tvi     ESCAN00058534 Compile error caused by usage of wrong memory class
 *                                ESCAN00060767 SetOpMode returns E_NOT_OK and reports a DET after initialization 
 *  2.00.01   2012-12-05  Tvi     -             (no changes here, just merge with new HL)
 *  2.00.02   2013-02-28  Tvi     ESCAN00064688 Incorrect register address for "Wake pin status" used in CanTrcv_30_Tja1145_GetTrcvSystemData
 *  2.01.00   2013-04-10  Tvi     ESCAN00066526 Use block transfer for improved performance
 *                        Tvi     ESCAN00066527 Add support for automatic reinitialization
 *                        Tvi     ESCAN00066528 [ASR3 only] Clear wakeup flags during transition to STANDBY if PN is disabled.
 *                        Tvi     ESCAN00066529 Clear Wake Pin wakeups in ClearTrcvWufFlag
 *  2.02.00   2013-12-04  Tvi     -             (no changes here, just merge with new HL)
 *  2.03.00   2014-04-22  Tvi     ESCAN00072393 Allow configuration of Bit CFDC 
 *  3.00.00   2014-11-05  Seu     ESCAN00079389 AR4-698: Post-Build Selectable (Identity Manager)
 *  3.01.00   2015-07-28  Seu     ESCAN00083361 Unexpectedly wake-up reason "WU_BY_SYSERR" is reported / set
 *  3.02.00   2015-10-07  Seu     ESCAN00081058 FEAT-427: SafeBSW Step I
 *            2015-12-01  Seu     ESCAN00086914 Add support for "CanTrcvHwPnSupport" = false
 *            2015-12-01  Seu     ESCAN00086226 ECU does NOT: go to standby/sleep / wake-up / answer at all
 *  3.02.01   2015-01-20  Seu     ESCAN00087596 Compiler warning: ctc E553 "no break or comment before case label"
 *  3.03.00   2016-01-20  Seu     ESCAN00087581 SafeBSW - Silent Analysis
 *            2016-03-09  Seu     ESCAN00088822 Add Postbuild Loadable Support for Tja1145-CanTrcvDrv
 *  3.04.00   2016-04-05  Seu     ESCAN00089226 FEAT-1688: SafeBSW Step 4
 *  3.04.01   2016-06-22  Seu     ESCAN00090613 Compiler error: Syntax Error caused by undefined compiler class: CANTRCV_30_TJA1145_VAR
 *  3.05.00   2016-08-01  Seu     ESCAN00091504 Improve code coverage
 *            2016-11-01  Seu     ESCAN00092619 Driver does not work as expected
 *            2016-11-23  Seu     ESCAN00092984 Add support for asynchronous SPI without polling support
 *            2016-12-15  Seu     ESCAN00093320 Compiler error: error #20: identifier "CanTrcv_30_Tja1145_RdStatusTask" is undefined
 *            2017-01-23  Seu     ESCAN00093677 ECU does not go to sleep / CanTrcv does not answer with indication function in case of shut down sequence
 *  3.06.00   2017-01-31  Seu     ESCAN00093786 Improve doxygen comments
 *            2017-02-06  Seu     ESCAN00094661 Improve CDD
 *            2017-04-05  Seu     ESCAN00092283 Error frame is caused in case of start-up of ECU
 *  3.06.01   2017-08-29  Jan     ESCAN00096444 Support ATA6570
 *  3.07.00   2018-08-23  Jan     STORYC-6321   MISRA-C:2012 Compliance
 *  3.08.00   2019-04-29  Gaz     STORYC-8228   Deactivate Wakeup Source in case Wakeup by Bus is deactivated
 * *******************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Matthias Fleischmann          Fn            Vector Informatik GmbH
 *  Mihai Olariu                  Ou            Vector Informatik GmbH
 *  Timo Vanoni                   Tvi           Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  Jan Hammer                    Jan           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2008-02-25  Fn      -             Intitial revision of the core implementation
 *  01.00.01  2008-04-17  Fn      -             Update of the include file names
 *  01.01.00  2008-06-26  Ou      ESCAN00027616 Various compile errors, problems with Organi
 *  01.02.00  2008-09-12  Ou      ESCAN00029980 Compiler failure due to wrong definition of SW version
 *  01.03.00  2008-10-07  Ou      ESCAN00028298 Several warnings due to unreferenced local variables
 *                        Ou      ESCAN00029572 DrvTrans__coreCanxAsr raise DET error if CanTrcv_SetOpMode is called with invalid TrcvWakeupMode
 *                        Ou      ESCAN00030536 Compile error at extended version check
 *  01.04.00  2008-12-11  Ou      ESCAN00031771 Adjust wakeup by bus handling for platforms which cannot be woken up with a CAN frame
 *  01.05.00  2009-02-19  Tvi     ESCAN00033258 GetBusWuReason may return an invalid value
 *  01.06.00  2009-02-26  Tvi     ESCAN00033383 Don't throw DET error in case the same mode is requested again
 *                        Tvi     ESCAN00033398 Compiler warnings when using different transceiver types within the same stack
 *                        Tvi     ESCAN00033413 Possible out of bounds access in SetOpMode if DET is enabled
 *  02.00.00  2009-06-29  Fn      ESCAN00035913 CAN Transceiver channel does not wake up
 *  02.00.01  2009-10-15  Tvi     ESCAN00038495 Compile error: unknown type definitions in dio.h
 *  02.01.00  2009-11-04  Tvi     ESCAN00036841 OP_MODE_SLEEP should be independent of GENERAL_WAKE_UP_SUPPORT
 *                        Tvi     ESCAN00038945 Use different DioPins tokens for GetOpMode and CHECK_WA
 *                        Tvi     ESCAN00038946 Rename filenames to match BSW00347
 *                        Tvi     ESCAN00038947 CanTrcv087 has to be implemented the correct way
 *                        Tvi     ESCAN00039039 Add support for timers
 *                        Tvi     ESCAN00039041 Allow transition to OP_MODE_NORMAL even if it is the current OpMode
 *                        Tvi     ESCAN00039043 Implement an initialization via OP_MODE_NORMAL
 *                        Tvi     ESCAN00039194 Disable IcuNotification when entering Normal mode in Init and SetOpMode
 *  02.02.00  2010-05-04  Tvi     ESCAN00040088 Compiler Warning: unused parameter 'TrcvWakeupMode'
 *  02.20.00  2010-07-01  Tvi     ESCAN00046512 Add support for partial network transceivers
 *            2010-11-29  Tvi     ESCAN00046781 Support Multiple Identity Configuration
 *                                ESCAN00045601 "Channel Used" parameter not well implemented
 *                                ESCAN00046813 Adapt AUTOSAR version check
 *                                ESCAN00047668 Critical areas should be Trcv specific
 *  02.20.01  2011-02-08  Tvi     ESCAN00048498 Wrong DEM Events used
 *  02.20.02  2011-03-11  Tvi     ESCAN00049830 Remove ASR Version check for SPI / DIO
 *                        Tvi     ESCAN00049831 [PN only] Store wakeup event and report them if Trcv is in Standby mode
 *  03.00.00  2011-05-05  Tvi     ESCAN00051930 Add support for ASR3.2.1
 *                                ESCAN00051564 Remove the AUTOSAR Release Version Check
 *  03.01.00  2011-11-22  Tvi     ESCAN00054349 AR3-1738: Add support for asynchronous transceiver driver
 *                                ESCAN00053272 AR3-1698: Add MISRA justifications in source code for automatic generation of MISRA reports
 *                                ESCAN00053265 AR3-2069: Remove non-SchM code for critical section handling
 *  03.01.01  2012-02-12  Tvi     ESCAN00057892 [PN only] CanTrcv does not wakeup when Synchronous SPI is being used
 *                        Tvi     ESCAN00056788 Compiler error/warning: DRVTRANS__CORECANXASR_RELEASE_VERSION' redefined
 *  04.00.00  2012-05-21  Tvi     ESCAN00058641 AR4-95: Provide CanTrcv according ASR 4, Asynchronous Transceiver Mode Changes
 *                                ESCAN00059656 Add support for SetPNActivationState according to ASR4
 *                                ESCAN00060455 AR3-2406: Asynchronous transceiver handling according to AUTOASR 3.2.2
 *  04.00.01  2012-09-27  Tvi     ESCAN00061779 [CFG5/ASR4 only]: Compiler error about unkown struct member instanceID
 *  04.01.00  2012-10-08  Tvi     ESCAN00062121 Report DEM if PN is not available
 *                        Tvi     ESCAN00066283 AR4-352: Support partial networking 
 *  04.02.00  2013-11-20  Tvi     ESCAN00071370 AR4-569: [CanTrcv]  Incompatible  argument  in call to EcuM_SetWakeupEvent() 
 *  04.03.00  2014-01-10  Tvi     ESCAN00073861 AR4-345: Implement PF4_PostBuildSelectable
 *  05.00.00  2014-09-24  Seu     ESCAN00076622 AR4-698: Post-Build Selectable (Identity Manager)
 *  05.00.01  2014-11-13  Seu     -             MISRA deviation comment for rule 6080 added (APIs: *_ClearTrcvWufFlag() and *_CheckWakeFlag())
 *  05.01.00  2015-05-04  Seu     ESCAN00077814 Support for CAN Transceiver on System-Basis Chips (SBCs)
 *            2015-07-23  Seu     ESCAN00084154 Only since R13: Compiler error: C2059: syntax error : '{'
 *            2015-07-23  Seu     ESCAN00083583 Adapt in order to fix ESCAN00083361 / ESCAN00083362
 *            2015-07-23  Seu     ESCAN00083395 Compiler warning: parameter is never used
 *  05.01.01  2015-09-24  Seu     ESCAN00085451 Support usage of Partial Networking for SBCs.
 *  05.01.02  2015-10-06  Seu     ESCAN00085678 Initialize requestState in case of INTERFACE_SBC and PN is used
 *  05.02.00  2015-02-04  Seu     ESCAN00080310 FEAT-427: SafeBSW Step I
 *            2015-10-05  Seu     ESCAN00081795 FEAT-1275: SafeBSW Step 2
 *            2015-10-05  Seu     ESCAN00085154 FEAT-1527: SafeBSW Step 3
 *  05.03.00  2016-01-16  Seu     ESCAN00087580 SafeBSW - Silent Analysis
 *            2016-03-09  Seu     ESCAN00088810 Add Postbuild Loadable Support for CanTrcvDrv
 *  05.04.00  2016-04-05  Seu     ESCAN00087813 FEAT-1688: SafeBSW Step 4
 *            2016-05-19  Seu     ESCAN00090097 Compiler error: Syntax Error caused by undefined compiler class
 *  05.04.01  2016-08-02  Seu     ESCAN00091270 MISRA deviation: MISRA-C:2004 Rule 8.8
 *            2016-08-17  Seu     ESCAN00091505 Improve code coverage and doxygen comments
 *            2016-10-17  Seu     ESCAN00091616 Compiler error: identifier index not declared
 *  05.05.00  2016-11-23  Seu     ESCAN00092817 Add support for asynchronous SPI without polling support
 *            2016-11-29  Seu     ESCAN00093075 [Only: Tja1145 / E52013] In case of startup of ECU SysErr-wakeup is reported instead of PowerOn-wakeup
 *            2016-12-06  Seu     ESCAN00093177 Omit interrupted transition: STANDBY -> NORMAL (pending) -> SLEEP  [only async SPI]
 *  05.06.00  2017-04-05  Seu     ESCAN00094603 Add support for requirements: CanTrcv_00230, CanTrcv_00190, CanTrcv_00191
 *            2017-04-05  Seu     ESCAN00094658 Improve doxygen comments
 *  05.06.01  2017-05-30  Seu     ESCAN00095350 Add: SafeBSW support for DIO-CanTrcv, flexibility for SPI-CanTrcv
 *  05.07.00  2018-08-21  Jan     STORYC-4868   MISRA-C:2012 Compliance
 *  05.08.00  2019-05-03  Jan     ESCAN00102288 Spi_DataType to Spi_DataBufferType: Incompatible data type.
 *            2019-05-03  Jan     STORYC-8282   Add emulated Sleep mode
 *            2019-05-13  Jan     STORYC-8389   Improve PTH of API: CanTrcv_SetOpMode()
 * *******************************************************************************************************************/
#if !defined (CANTRCV_30_TJA1145_API_H)
# define CANTRCV_30_TJA1145_API_H

/* PRQA S 0850 EOF */ /* MD_MSR_MacroArgumentEmpty */
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

# define V_CANTRCV_30_TJA1145_HEADER

/* ********************************************************************************************************************
 * INCLUDES
 * *******************************************************************************************************************/
# include "CanTrcv_30_Tja1145_Cfg.h" /* SREQ00010148,SREQ00007523 */

# include "SchM_CanTrcv_30_Tja1145.h"

/* ********************************************************************************************************************
 * Module version
 * *******************************************************************************************************************/

# define CANTRCV_30_TJA1145_AR_RELEASE_MAJOR_VERSION      4u
# define CANTRCV_30_TJA1145_AR_RELEASE_MINOR_VERSION      0u
# define CANTRCV_30_TJA1145_AR_RELEASE_REVISION_VERSION   3u
# define CANTRCV_30_TJA1145_AUTOSARVERSION_4X             0x403u

/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans_Tja1145CanspiAsr CQComponent : Implementation */
# define DRVTRANS_TJA1145CANSPIASR_VERSION                 0x0308u
# define DRVTRANS_TJA1145CANSPIASR_RELEASE_VERSION         0x00u

#if defined(CANTRCV_30_TJA1145_INCLUDE_INTERNAL) /* COV_CANTRCV_HL_TJA1145_VARCOV_AVOID_COREVER_REDEF */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans__coreCanxAsr CQComponent : Implementation */
# define DRVTRANS__CORECANXASR_VERSION                         0x0508u
# define DRVTRANS__CORECANXASR_RELEASE_VERSION                 0x00u
#endif

#  define CANTRCV_30_TJA1145_SW_MAJOR_VERSION      ((uint8)((DRVTRANS_TJA1145CANSPIASR_VERSION & 0xFF00u) >> 8))
#  define CANTRCV_30_TJA1145_SW_MINOR_VERSION               (DRVTRANS_TJA1145CANSPIASR_VERSION & 0x00FFu)
#  define CANTRCV_30_TJA1145_SW_PATCH_VERSION                DRVTRANS_TJA1145CANSPIASR_RELEASE_VERSION



#define CANTRCV_30_TJA1145_SUPPORTS_MODE_STANDBY

#define CANTRCV_30_TJA1145_SUPPORTS_MODE_SLEEP

#define CANTRCV_30_TJA1145_SUPPORTS_MODE_EMULATED_SLEEP



#define CANTRCV_30_TJA1145_SUPPORTS_PARTIAL_NETWORKING

#define CANTRCV_30_TJA1145_GETTRCVSYSTEMDATA_RAW


/* ********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 * *******************************************************************************************************************/ 
# define CANTRCV_30_TJA1145_VENDOR_ID                      30u
# define CANTRCV_30_TJA1145_MODULE_ID                      70u

/* ! API IDs for Error Reporting */
# define CANTRCV_30_TJA1145_INIT_ID                        0x00u
# define CANTRCV_30_TJA1145_SETOPMODE_ID                   0x01u
# define CANTRCV_30_TJA1145_GETOPMODE_ID                   0x02u
# define CANTRCV_30_TJA1145_GETBUSWUREASON_ID              0x03u
# define CANTRCV_30_TJA1145_GETVERSIONINFO_ID              0x04u
# define CANTRCV_30_TJA1145_SETWAKEUPMODE_ID               0x05u
# define CANTRCV_30_TJA1145_MAINFUNCTION_ID                0x06u
# define CANTRCV_30_TJA1145_CHECKWAKEUP_ID                 0x07u 
# define CANTRCV_30_TJA1145_MAINFUNCTIONDIAGNOSTICS        0x08u
# define CANTRCV_30_TJA1145_GETTRCVSYSTEMDATA_ID           0x09u
# define CANTRCV_30_TJA1145_CLEARTRCVWUFFLAG_ID            0x0Au
# define CANTRCV_30_TJA1145_READTRCVTIMEOUTFLAG_ID         0x0Bu
# define CANTRCV_30_TJA1145_CLEARTRCVTIMEOUTFLAG_ID        0x0Cu
# define CANTRCV_30_TJA1145_READTRCVSILENCEFLAG_ID         0x0Du
# define CANTRCV_30_TJA1145_CHECKWAKEFLAG_ID               0x0Eu
# define CANTRCV_30_TJA1145_SETPNACTIVATIONSTATE_ID        0x0Fu
# define CANTRCV_30_TJA1145_SPIINDICATION_ID               0x10u


# define CANTRCV_30_TJA1145_OP_MODE_NORMAL                 CANTRCV_TRCVMODE_NORMAL
# define CANTRCV_30_TJA1145_OP_MODE_STANDBY                CANTRCV_TRCVMODE_STANDBY 
# define CANTRCV_30_TJA1145_OP_MODE_SLEEP                  CANTRCV_TRCVMODE_SLEEP

# define CANTRCV_30_TJA1145_WU_ENABLE                      CANTRCV_WUMODE_ENABLE
# define CANTRCV_30_TJA1145_WU_DISABLE                     CANTRCV_WUMODE_DISABLE
# define CANTRCV_30_TJA1145_WU_CLEAR                       CANTRCV_WUMODE_CLEAR

# define CANTRCV_30_TJA1145_WU_ERROR                       CANTRCV_WU_ERROR
# define CANTRCV_30_TJA1145_WU_NOT_SUPPORTED               CANTRCV_WU_NOT_SUPPORTED
# define CANTRCV_30_TJA1145_WU_BY_BUS                      CANTRCV_WU_BY_BUS
# define CANTRCV_30_TJA1145_WU_INTERNALLY                  CANTRCV_WU_INTERNALLY
# define CANTRCV_30_TJA1145_WU_RESET                       CANTRCV_WU_RESET
# define CANTRCV_30_TJA1145_WU_POWER_ON                    CANTRCV_WU_POWER_ON
# define CANTRCV_30_TJA1145_WU_BY_PIN                      CANTRCV_WU_BY_PIN
# define CANTRCV_30_TJA1145_WU_BY_SYSERR                   CANTRCV_WU_BY_SYSERR

# define CANTRCV_30_TJA1145_E_NO_ERROR                     0x00u
# define CANTRCV_30_TJA1145_E_INVALID_CAN_NETWORK          0x01u
/* ! SREQ00010156: Keep the invalid CAN Network switch for compatibility reason. */
# define CANTRCV_30_TJA1145_E_INVALID_TRANSCEIVER          CANTRCV_30_TJA1145_E_INVALID_CAN_NETWORK
# define CANTRCV_30_TJA1145_E_PARAM_POINTER                0x02u
# define CANTRCV_30_TJA1145_E_UNINIT                       0x11u
# define CANTRCV_30_TJA1145_E_TRCV_NOT_STANDBY             0x21u
# define CANTRCV_30_TJA1145_E_TRCV_NOT_NORMAL              0x22u
# define CANTRCV_30_TJA1145_E_PARAM_TRCV_WAKEUP_MODE       0x23u
# define CANTRCV_30_TJA1145_E_PARAM_TRCV_OP_MODE           0x24u
# define CANTRCV_30_TJA1145_E_BAUDRATE_NOT_SUPPORTED       0x25u
# define CANTRCV_30_TJA1145_E_CLR_TRCV_WUF_NOT_CALLED      0x30u
# define CANTRCV_30_TJA1145_E_NO_TRCV_CONTROL              0x40u /* SREQ00010156: Actual ID is unspecified in SWS! */


# define CANTRCV_30_TJA1145_WAKEUP_NOT_SUPPORTED          0u
# define CANTRCV_30_TJA1145_WAKEUP_BY_POLLING             1u
# define CANTRCV_30_TJA1145_WAKEUP_BY_ISR                 2u
/* ! Compatibility defines... */
# define CANTRCV_30_TJA1145_WAKEUP_NONE                   CANTRCV_30_TJA1145_WAKEUP_NOT_SUPPORTED
# define CANTRCV_30_TJA1145_WAKEUP_POLLING                CANTRCV_30_TJA1145_WAKEUP_BY_POLLING
# define CANTRCV_30_TJA1145_WAKEUP_ISR                    CANTRCV_30_TJA1145_WAKEUP_BY_ISR

# define CanTrcv_30_Tja1145_TrcvModeType                  CanTrcv_TrcvModeType
# define CanTrcv_30_Tja1145_TrcvWakeupModeType            CanTrcv_TrcvWakeupModeType
# define CanTrcv_30_Tja1145_TrcvWakeupReasonType          CanTrcv_TrcvWakeupReasonType


/* ! Timer configuration */

# define CANTRCV_30_TJA1145_USE_TIMERS                    STD_OFF

/* ! Predefined timer indexes (0x01 - 0x0f)                                   */
# define kCanTrcv_30_Tja1145_LoopInit                          0x01





/* ********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 * *******************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 * *******************************************************************************************************************/
/* SREQ00007522 */
/* ! Defines the state of any requested FLAG-action: *SET or *CLEARED. */
typedef enum
{
  CANTRCV_30_TJA1145_FLAG_SET,
  CANTRCV_30_TJA1145_FLAG_CLEARED
}
CanTrcv_30_Tja1145_TrcvFlagStateType;

/* ! Defines the state of PN (= Partial Networking): *ENABLED or *DISABLED. */
typedef enum
{
  CANTRCV_30_TJA1145_PN_ENABLED,
  CANTRCV_30_TJA1145_PN_DISABLED
} CanTrcv_30_Tja1145_PNActivationType;


typedef struct CanTrcv_30_Tja1145_StatusFlagType_Tag
{
  uint8 Ts;   /*!< Transceiver status register */
  uint8 Ecs;  /*!< Event capture status register */
  uint8 Ses;  /*!< System event capture status register */
  uint8 Tes;  /*!< Transceiver event capture status register */
  uint8 Wes;  /*!< Wake pin event capture status register */
} CanTrcv_30_Tja1145_StatusFlagsType;

#if (CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF) 
typedef struct CanTrcv_30_Tja1145_TaskStateType_Tag
{
  uint8 TaskId;
  uint8 TaskState;
} CanTrcv_30_Tja1145_TaskStateType;


typedef struct CanTrcv_30_Tja1145_FifoInfoType_Tag
{
  uint8 IdxWrite;
  uint8 IdxRead;
  uint8 NumFree;
} CanTrcv_30_Tja1145_FifoInfoType;
#endif

/* ! The following type includes CAN transceiver channel specific settings. */
typedef volatile struct
{
  /* ---- Common attributes ---- */

  /* ! Last detected wakeup reason */
  CanTrcv_30_Tja1145_TrcvWakeupReasonType wakeUpReason;

  /* ! Specifies whether or not to report wakeups */
  CanTrcv_30_Tja1145_TrcvWakeupModeType wakeUpReport;

  /* ! Holds the last read statusFlags.. only valid if statusFlagsRdy == TRUE */
  CanTrcv_30_Tja1145_StatusFlagsType statusFlags;

  /* ! Holds the current request state */
  uint32 requestState;

  /* ! Holds the current operation mode */
  CanTrcv_30_Tja1145_TrcvModeType curOpMode;

# if (CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF) 
  /* ! Holds the next request that is triggered automatically
   * after the worker was cancelled
   */
  uint32 nextRequestState;

#  if (CANTRCV_30_TJA1145_WAKEUP_BY_BUS_USED == STD_ON)
  /* ! Indicates whether a wakeup was detected during a mode transition */
  boolean wakeUpInTransitionDetected;
#  endif

  /* ! Indicates that statusFlags are ready.. This must be evaluated with locked
   * interrupts before reading statusFlags
   */
  boolean statusFlagsRdy;

  /* ! Indicates that new statusFlags are available for the MainFunction.
   * will be reset as soon as read
   */
  boolean statusFlagsNew;
# endif

#if (CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON) 
  /* ! Indicates if pn is currently available in HW */
  boolean pnAvailable;

  /* ! Indicates if pn is enabled in software */
  boolean isPnEnabled;
#endif

  /* ! Specifies whether the transceiver is initialized, this member is not needed in case of DIO because IsUsed == IsInit */
  uint8 isInit;

  /* ! HW specific attributes */
  uint8 CanControlWrite;   /*!< Content of the Can Control Register -> Write access */
  uint8 CanControlRead;    /*!< Content of the Can Control Register -> Read access  */
  uint8 ModeControlWrite;  /*!< Content of the Mode Control Register -> Write access */
  uint8 ModeControlRead;   /*!< Content of the Mode Control Register -> Read access */
  
  #if (CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF) 
  /* Substate of the OpMode Worker */
  uint8 WorkerSubState;
  #endif
  
  /* Stores the last requested spi command */
  uint8 CanTrcvSpiReqType;
  

} CanTrcv_30_Tja1145_Prob_Type;

/* ********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 * *******************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 * *******************************************************************************************************************/
/* for callback function prototypes see CanTrcv_Cbk.h */
# define CANTRCV_30_TJA1145_START_SEC_CODE
# include "MemMap.h"


/************************************************************************************************************
 | NAME:  CanTrcv_30_Tja1145_Init()
 ***********************************************************************************************************/
/*! \brief         Initializes the CAN transceiver module.
 *  \details       Initializes all active channels of the CAN transceiver driver which are configured in the configuration tool.
 *                 This function has the service id 0x00.
 *  \param[in]     ConfigPtr - Pointer to the CanTrcv_30_Tja1145_Config structure.
 *                 If multiple configurations are available, the active configuration can be selected by using the related CanTrcv_30_Tja1145_Config_<IdentityName> structure.
 *  \pre           The function CanTrcv_30_Tja1145_InitMemory must be called before the function CanTrcv_30_Tja1145_Init can be called.
 *                 This function must be called before any other service functionality of the transceiver driver
 *                 The SPI/DIO driver must be initialized
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
***********************************************************************************************************/
FUNC(void, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_Init( P2CONST(CanTrcv_30_Tja1145_ConfigType, AUTOMATIC, CANTRCV_30_TJA1145_CONST) ConfigPtr );


/***********************************************************************************************************************
 | NAME:  CanTrcv_30_Tja1145_InitMemory
 **********************************************************************************************************************/
/*! \brief         Initializes the memory of the CAN transceiver module.
 *  \details       -
 *  \param[in]     -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
 **********************************************************************************************************************/
FUNC(void, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_InitMemory(void);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_SetOpMode
 **********************************************************************************************************************/
/*! \brief       Changes the transceiver operating mode to the requested mode.
 *  \details     This function has the service id 0x01.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[in]   OpMode: Operating mode which shall be set.
 *  \return      E_OK: Change of transceiver operating mode was successful.
 *  \return      E_NOT_OK: Change of transceiver operating mode failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_SetOpMode(uint8 CanTrcvIndex, CanTrcv_TrcvModeType OpMode);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_GetOpMode
 **********************************************************************************************************************/
/*! \brief       Returns the current transceiver operating mode.
 *  \details     DIO transceiver: The mode is determined from status of PINs of the transceiver hardware.
 *               SPI transceiver: The mode is read from state variable. No access to transceiver hardware is performed.
 *               This function has the service id 0x02.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  OpMode: Pointer to buffer where the current operating mode is stored.
 *  \return      E_OK: Determination of current transceiver operating mode was successful.
 *  \return      E_NOT_OK: Determination of transceiver operating mode failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_GetOpMode(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) OpMode);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_GetBusWuReason
 **********************************************************************************************************************/
/*! \brief       Returns the bus wake-up reason.
 *  \details     The wake-up reason is read from state variable. No access to transceiver hardware is performed.
 *               This function has the service id 0x03.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  Reason: Pointer to buffer where the bus wake-up reason is stored.
 *  \return      E_OK: Determination of wake-up reason was successfull.
 *  \return      E_NOT_OK: Determination of wake-up reason failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_GetBusWuReason(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) Reason);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_SetWakeupMode
 **********************************************************************************************************************/
/*! \brief       Changes the wake-up mode to the requested mode.
 *  \details     For more information about possible wake-up modes please see the description of type <CanTrcv_TrcvWakeupModeType>.
 *               This function has the service id 0x05.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[in]   TrcvWakeupMode: Requested wake-up mode for the transceiver channel (CanTrcvIndex).
 *  \return      E_OK: Change of wake-up mode was successful.
 *  \return      E_NOT_OK: Change of wake-up mode has failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_SetWakeupMode(uint8 CanTrcvIndex, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_CheckWakeup
 **********************************************************************************************************************/
/*! \brief       Checks if a wake-up event was detected.
 *  \details     This function has the service id 0x07.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \return      E_OK: Wake-up was detected / the request to check for wake-up was accepted (only asynchronous SPI-interface).
 *  \return      E_NOT_OK: No wake-up was detected / the request to check for wake-up was rejected (only asynchronous SPI-interface).
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_CheckWakeup(uint8 CanTrcvIndex);


#if (CANTRCV_30_TJA1145_GET_VERSION_INFO == STD_ON)
/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version info of the CAN transceiver module.
 *  \details     The versions are stored into the structure referenced by parameter: VersionInfo.
 *               This function has the service id 0x04.
 *  \param[out]  VersionInfo: Pointer to structure for storing of version info.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_GET_VERSION_INFO == STD_ON
 **********************************************************************************************************************/
FUNC(void, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) VersionInfo);
#endif /* (CANTRCV_30_TJA1145_GET_VERSION_INFO == STD_ON) */

/* SREQ00007670 */
#if (CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON) 
/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_GetTrcvSystemData
 **********************************************************************************************************************/
/*! \brief       Reads the transceiver configuration / status data and returns it via the parameter TrcvSysData.
 *  \details     This function has the service id 0x09.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  TrcvSysData: Configuration / status data of the transceiver.
 *  \return      E_OK: Status was read successfully.
                 E_NOT_OK: Status data is not available or DET/DEM occurred.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_GetTrcvSystemData(uint8 CanTrcvIndex, P2VAR(uint32, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) TrcvSysData );
#endif /* (CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON) */

#if (CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON) /* SREQ00007670 */
/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_ClearTrcvWufFlag
 **********************************************************************************************************************/
/*! \brief       Requests to clear the WUF flag of a transceiver channel (CanTrcvIndex).
 *  \details     This function has the service id 0x0A.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \return      E_OK: Request to clear the WUF was accepted.
                 E_NOT_OK: Request to clear the WUF was rejected.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_ClearTrcvWufFlag(uint8 CanTrcvIndex);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_ReadTrcvTimeoutFlag
 **********************************************************************************************************************/
/*! \brief       Reads the status of the timeout flag from the transceiver hardware.
 *  \details     This function has the service id 0x0B.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  FlagState: State of the timeout flag.
 *  \return      E_OK: Status was read successfully.
                 E_NOT_OK: Status could not be read or DET occurred.
 *  \pre         -
 *  \context     ANY
  * \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_ReadTrcvTimeoutFlag(uint8 CanTrcvIndex, P2VAR(CanTrcv_30_Tja1145_TrcvFlagStateType, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) FlagState);


/***********************************************************************************************************************
 | NAME:  CanTrcv_30_Tja1145_ClearTrcvTimeoutFlag
 **********************************************************************************************************************/
/*! \brief       Clears the status of the timeout flag in the transceiver hardware.
 *  \details     This function has the service id 0x0C.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \return      E_OK: Timeout flag cleared successfully.
                 E_NOT_OK: Timeout flag could not be cleared or DET occurred.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_ClearTrcvTimeoutFlag(uint8 CanTrcvIndex);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_ReadTrcvSilenceFlag
 **********************************************************************************************************************/
/*! \brief       Reads the status of the silence flag from the transceiver hardware.
 *  \details     This function has the service id 0x0D.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  FlagState: State of the silence flag.
 *  \return      E_OK: Status was read successfully.
                 E_NOT_OK: Status could not be read or DET occurred.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_ReadTrcvSilenceFlag(uint8 CanTrcvIndex, P2VAR(CanTrcv_30_Tja1145_TrcvFlagStateType, AUTOMATIC, CANTRCV_30_TJA1145_APPL_VAR) FlagState);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_CheckWakeFlag
 **********************************************************************************************************************/
/*! \brief       Requests to check the status of the wake-up flag from the transceiver hardware.
 *  \details     This function has the service id 0x0E.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \return      E_OK: Request was accepted.
                 E_NOT_OK: Request was not accepted or DET occurred.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_CheckWakeFlag(uint8 CanTrcvIndex);


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_SetPNActivationState
 **********************************************************************************************************************/
/*! \brief       Enables / disables selective wake-up for all transceiver channels.
 *  \details     This function has the service id 0x0F.
 *  \param[in]   ActivationState: State of PN-mode to be applied for all transceiver channels.
 *               <ENABLE>: Selective wake-up for all channels where PN is configured shall be enabled.
 *               <DISABLE>: Disable the selective wake-up functionality on all transceiver channels.
 *  \return      E_OK: PN-mode was changed successfully.
 *               E_NOT_OK: PN-mode change was not accepted or DET occurred.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_SetPNActivationState(CanTrcv_30_Tja1145_PNActivationType ActivationState);
#endif /* (CANTRCV_30_TJA1145_HW_PN_SUPPORT == STD_ON) */


/***********************************************************************************************************************
| NAME:  CanTrcv_30_Tja1145_MainFunction
 **********************************************************************************************************************/
/*! \brief       Service to scan all buses for wake up events and perform these event.
 *  \details     This function has the service id 0x06.
 *  \param[in]   -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
/* FUNC(void, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_MainFunction(void); */ /* ESCAN00091270 */


#if (CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
/***********************************************************************************************************************
 *  CanTrcv_30_Tja1145_SpiIndication
 **********************************************************************************************************************/
/*! \brief       This API is an internal SPI-end-notification function which indicates a successful process of a SPI-sequence.
 *  \details     This API is required to be internal one in case of synchronous SPI-interface is used.
 *               This API is required to be external one in case of asynchronous SPI-interface is used and must be called
 *               within the SpiEndNotification of the SPI-driver.
 *  \param[in]   CanTrcvIndex: CAN transceiver channel
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different <CanTrcvIndex>.
 *  \synchronous TRUE
 *  \config      (CANTRCV_30_TJA1145_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 **********************************************************************************************************************/
FUNC(void, CANTRCV_30_TJA1145_CODE) CanTrcv_30_Tja1145_SpiIndication(uint8 CanTrcvIndex);
#endif

# define CANTRCV_30_TJA1145_STOP_SEC_CODE
# include "MemMap.h"


/*! 
* \exclusivearea CANTRCV_TJA1145_EXCLUSIVE_AREA_0
* Ensures consistent handling of CanTrcv-hardware via the SPI-interface.
* \protects Atomic / consistent usage of SPI-interface.
* \usedin CanTrcv_30_Tja1145_Init(), CanTrcv_30_Tja1145_SetOpMode(), CanTrcv_30_Tja1145_GetOpMode(), CanTrcv_30_Tja1145_CheckWakeup(), CanTrcv_30_Tja1145_CbWakeupByBusIndication
*         CanTrcv_30_Tja1145_TrcvModeIndication(), CanTrcv_30_Tja1145_GetTrcvSystemData(), CanTrcv_30_Tja1145_ClearTrcvWufFlag(), CanTrcv_30_Tja1145_ClearTrcvWufFlagIndication()
*         CanTrcv_30_Tja1145_ReadTrcvTimeoutFlag(), CanTrcv_30_Tja1145_ClearTrcvTimeoutFlag(),  CanTrcv_30_Tja1145_ReadTrcvSilenceFlag(), CanTrcv_30_Tja1145_CheckWakeFlag() 
*         CanTrcv_30_Tja1145_CheckWakeFlagIndication(), CanTrcv_30_Tja1145_GetStatusFlagsIndication(), CanTrcv_30_Tja1145_StartTask(), CanTrcv_30_Tja1145_ReSchedule() 
*         CanTrcv_30_Tja1145_Schedule() and CanTrcv_30_Tja1145_MainFunction().
* \exclude call of: CanTrcv-driver APIs: CanTrcv_30_Tja1145_Init(), CanTrcv_30_Tja1145_SetOpMode(), CanTrcv_30_Tja1145_GetOpMode(), CanTrcv_30_Tja1145_CheckWakeup(), CanTrcv_30_Tja1145_MainFunction(), 
*                   CanTrcv_30_Tja1145_GetTrcvSystemData(), CanTrcv_30_Tja1145_ClearTrcvWufFlag(), CanTrcv_30_Tja1145_ReadTrcvTimeoutFlag(), CanTrcv_30_Tja1145_ClearTrcvTimeoutFlag(),
*                   CanTrcv_30_Tja1145_ReadTrcvSilenceFlag(), CanTrcv_30_Tja1145_CheckWakeFlag(), CanTrcv_30_Tja1145_MainFunction() and CanTrcv_30_Tja1145_SpiIndication().
* \length LONG Call to SPI module, update of internal states.
* \endexclusivearea
*/


#endif /* CANTRCV_30_TJA1145_API_H */

/* ********************************************************************************************************************
 *  END OF FILE
 * *******************************************************************************************************************/