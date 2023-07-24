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
 *             File:  SocDtcProcess.c
 *           Config:  D:/work/code/ES13/VIP_es13/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  SocDtcProcess
 *  Generation Time:  2021-11-02 11:02:02
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <SocDtcProcess>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComEx_SignalGroupIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * ComEx_SignalIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_DTCFormatType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_DTCOriginType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_DebouncingStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * Dem_MonitorStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_OperationCycleStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EngSpd
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * TMCU_ActSpd_RM
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *********************************************************************************************************************/

#include "Rte_SocDtcProcess.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 #include "IPC_Diagnose.h"
 #include "Dem_Lcfg.h"
 #include "ComEx_Cfg.h"
 #include "DcmEx_Type.h"
 #include "Dem.h"
 #include "VConfig_Cfg.h"
 #include "logger.h"

 #define UDS_STATUS_MASK        (0x01)
 #define DTC_BUFFER_SIZE        (400u)
 
 #define CLEAR_DTC_PENDING       (1u)
 #define CLEAR_DTC_ERROR         (2u)
 #define HIGH_VOLTAGE_THRSH      ((float64)16.0f) // 16V
 #define LOW_9_VOLTAGE_THRSH     ((float64)9.0f)  // 9V
 #define LOW_10_VOLTAGE_THRSH    ((float64)10.0f) // 10V
 #define LOW_12_VOLTAGE_THRSH    ((float64)12.0f) // 12V
 #define LOW_12_5_VOLTAGE_THRSH  ((float64)12.5f) // 12.5V

 #define ODO_MAX_SNAPSHOT_VALUE  (0x63FFFF9CUL)


 struct SocDtcEventHandlerCfg{
    uint32 dtc;
    Std_ReturnType (* setEventFct)(uint8 EventStatus);
 };
 typedef struct SocDtcEventHandlerCfg SocDtcEventHandlerCfg_t;

extern DcmEx_Type dcmEx_data;
extern DcmEx_CfgType dcmEx_cfg;

 static uint8 writeTimeCnt = 51 ;
 static boolean eventRequestFlag = FALSE;
 static boolean iviReportDtcEventFlag = FALSE;
 static uint16 ipDisplayErrStatus = 0;
 static IPC_S2M_DiagnoseQNXReportEventRequest_t reportDtcData;
 static IPC_S2M_DiagnoseIVIReportEventRequest_t iviReportDtcData;
 static IPC_M2S_DiagnoseQNXDtcReinitRequest_t   QNXDtcReinitRsq;
 static IPC_M2S_DiagnoseIVIDtcReinitRequest_t   iviDtcReinitRsq;
 static SG_ABS3  sgAbs3Ptr;
 static EngSpd sgEngSpd;
 static EngSpdVldty sgEngSpdVldty;
 static SystemState_RecordType systemPowerStatus;
 static s_OdoRteGetParament_t OdoData;
 static TMCU_ActSpd_RM mcuActSpd;
 static uint16 KL15StsOnCounter = 0;
 static uint8 reqMonitorReInitCounter = 0;
 static uint32 KL15ChangeCounter = 0;
 static uint32 KL15ChangeCounterOld = 0;
 static uint8  SocVConfigDataBuf[400]= {0};
 static uint8 dtcBuffer[DTC_BUFFER_SIZE] = {0};
 
 static Std_ReturnType SocDiagnosticMonitorSetEventStatus(uint32 Dtc,Dem_EventStatusType EventStatus);
 static void IpDisplayErrorReport(uint32 Dtc,Dem_EventStatusType EventStatus);
 static void IviDiagnoticMonitorSetEventSts(void);
 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ABSActv_0x265: Boolean
 * ABSFailSts_0x265: Boolean
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * Dem_EventIdType: Integer in interval [1...65535]
 * EBDActv_0x265: Boolean
 * EBDFailSts_0x265: Boolean
 * EngSpd: Integer in interval [0...65535]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * TMCU_ActSpd_RM: Integer in interval [0...65535]
 * VehOdoInfoSts_0x265: Boolean
 * VehSpdVld_0x265: Boolean
 * VehSpd_0x265_2: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * dummy_ABS3_0: Integer in interval [0...255]
 * dummy_ABS3_1: Integer in interval [0...255]
 * dummy_ABS3_2: Integer in interval [0...255]
 * dummy_ABS3_3: Integer in interval [0...255]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint64: Integer in interval [-9223372036854775808...9223372036854775807] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CheckSum_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_DTC_FORMAT_OBD (0U)
 *   DEM_DTC_FORMAT_UDS (1U)
 *   DEM_DTC_FORMAT_J1939 (2U)
 * Dem_DTCOriginType: Enumeration of integer in interval [0...65535] with enumerators
 *   DEM_DTC_ORIGIN_PRIMARY_MEMORY (1U)
 *   DEM_DTC_ORIGIN_MIRROR_MEMORY (2U)
 *   DEM_DTC_ORIGIN_PERMANENT_MEMORY (3U)
 *   DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY (4U)
 *   DEM_DTC_ORIGIN_SECONDARY_MEMORY (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_10 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_11 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_12 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_13 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_14 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_15 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_16 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_17 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_18 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_19 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_1F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_20 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_21 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_22 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_23 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_24 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_25 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_26 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_27 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_28 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_29 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_2F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_30 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_31 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_32 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_33 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_34 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_35 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_36 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_37 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_38 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_39 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_3F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_40 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_41 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_42 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_43 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_44 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_45 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_46 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_47 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_48 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_49 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_4F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_50 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_51 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_52 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_53 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_54 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_55 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_56 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_57 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_58 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_59 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_5F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_60 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_61 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_62 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_63 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_64 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_65 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_66 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_67 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_68 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_69 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_6F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_70 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_71 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_72 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_73 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_74 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_75 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_76 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_77 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_78 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_79 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_7F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_80 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_81 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_82 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_83 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_84 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_85 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_86 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_87 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_88 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_89 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_8F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_90 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_91 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_92 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_93 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_94 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_95 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_96 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_97 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_98 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_99 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9A (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9B (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9C (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9D (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9E (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_9F (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_A9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_AF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_B9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_BF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_C9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_CF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_D9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_DF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_E9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_ED (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_EF (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F0 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F1 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F2 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F3 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F4 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F5 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F6 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F7 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F8 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_F9 (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FA (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FB (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FC (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FD (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FE (5U)
 *   DEM_DTC_ORIGIN_USERDEFINED_MEMORY_FF (5U)
 * Dem_DebouncingStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_TEMPORARILY_DEFECTIVE (1U)
 *   DEM_TEMPORARILY_DEFECTIVE_BflMask 1U (0b00000001)
 *   DEM_TEMPORARILY_DEFECTIVE_BflPn 0
 *   DEM_TEMPORARILY_DEFECTIVE_BflLn 1
 *   DEM_FINALLY_DEFECTIVE (2U)
 *   DEM_FINALLY_DEFECTIVE_BflMask 2U (0b00000010)
 *   DEM_FINALLY_DEFECTIVE_BflPn 1
 *   DEM_FINALLY_DEFECTIVE_BflLn 1
 *   DEM_TEMPORARILY_HEALED (4U)
 *   DEM_TEMPORARILY_HEALED_BflMask 4U (0b00000100)
 *   DEM_TEMPORARILY_HEALED_BflPn 2
 *   DEM_TEMPORARILY_HEALED_BflLn 1
 *   DEM_TEST_COMPLETE (8U)
 *   DEM_TEST_COMPLETE_BflMask 8U (0b00001000)
 *   DEM_TEST_COMPLETE_BflPn 3
 *   DEM_TEST_COMPLETE_BflLn 1
 *   DEM_DTR_UPDATE (16U)
 *   DEM_DTR_UPDATE_BflMask 16U (0b00010000)
 *   DEM_DTR_UPDATE_BflPn 4
 *   DEM_DTR_UPDATE_BflLn 1
 * Dem_MonitorStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_MONITOR_STATUS_TF (1U)
 *   DEM_MONITOR_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_MONITOR_STATUS_TF_BflPn 0
 *   DEM_MONITOR_STATUS_TF_BflLn 1
 *   DEM_MONITOR_STATUS_TNCTOC (2U)
 *   DEM_MONITOR_STATUS_TNCTOC_BflMask 2U (0b00000010)
 *   DEM_MONITOR_STATUS_TNCTOC_BflPn 1
 *   DEM_MONITOR_STATUS_TNCTOC_BflLn 1
 * Dem_OperationCycleStateType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_CYCLE_STATE_START (0U)
 *   DEM_CYCLE_STATE_END (1U)
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_UDS_STATUS_TF (1U)
 *   DEM_UDS_STATUS_TF_BflMask 1U (0b00000001)
 *   DEM_UDS_STATUS_TF_BflPn 0
 *   DEM_UDS_STATUS_TF_BflLn 1
 *   DEM_UDS_STATUS_TFTOC (2U)
 *   DEM_UDS_STATUS_TFTOC_BflMask 2U (0b00000010)
 *   DEM_UDS_STATUS_TFTOC_BflPn 1
 *   DEM_UDS_STATUS_TFTOC_BflLn 1
 *   DEM_UDS_STATUS_PDTC (4U)
 *   DEM_UDS_STATUS_PDTC_BflMask 4U (0b00000100)
 *   DEM_UDS_STATUS_PDTC_BflPn 2
 *   DEM_UDS_STATUS_PDTC_BflLn 1
 *   DEM_UDS_STATUS_CDTC (8U)
 *   DEM_UDS_STATUS_CDTC_BflMask 8U (0b00001000)
 *   DEM_UDS_STATUS_CDTC_BflPn 3
 *   DEM_UDS_STATUS_CDTC_BflLn 1
 *   DEM_UDS_STATUS_TNCSLC (16U)
 *   DEM_UDS_STATUS_TNCSLC_BflMask 16U (0b00010000)
 *   DEM_UDS_STATUS_TNCSLC_BflPn 4
 *   DEM_UDS_STATUS_TNCSLC_BflLn 1
 *   DEM_UDS_STATUS_TFSLC (32U)
 *   DEM_UDS_STATUS_TFSLC_BflMask 32U (0b00100000)
 *   DEM_UDS_STATUS_TFSLC_BflPn 5
 *   DEM_UDS_STATUS_TFSLC_BflLn 1
 *   DEM_UDS_STATUS_TNCTOC (64U)
 *   DEM_UDS_STATUS_TNCTOC_BflMask 64U (0b01000000)
 *   DEM_UDS_STATUS_TNCTOC_BflPn 6
 *   DEM_UDS_STATUS_TNCTOC_BflLn 1
 *   DEM_UDS_STATUS_WIR (128U)
 *   DEM_UDS_STATUS_WIR_BflMask 128U (0b10000000)
 *   DEM_UDS_STATUS_WIR_BflPn 7
 *   DEM_UDS_STATUS_WIR_BflLn 1
 * RollingCounter_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * Rte_DT_SystemState_RecordType_0: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_Cluster_OFF (0U)
 *   SYSTEMSTATE_Cluster_STANDBY (1U)
 *   SYSTEMSTATE_Cluster_ON (2U)
 *   SYSTEMSTATE_Cluster_STARTUP (3U)
 *   SYSTEMSTATE_Cluster_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_1: Enumeration of integer in interval [0.0...255] with enumerators
 *   SYSTEMSTATE_IVI_OFF (0U)
 *   SYSTEMSTATE_IVI_STANDBY (1U)
 *   SYSTEMSTATE_IVI_ON (2U)
 *   SYSTEMSTATE_IVI_SHUTDOWN (3U)
 *   SYSTEMSTATE_IVI_REMOTE (4U)
 *   SYSTEMSTATE_IVI_DEMO (5U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (10U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (8U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (9U)
 * Rte_DT_SystemState_RecordType_2: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_HUD_OFF (0U)
 *   SYSTEMSTATE_HUD_STANDBY (1U)
 *   SYSTEMSTATE_HUD_ON (2U)
 *   SYSTEMSTATE_HUD_STARTUP (3U)
 *   SYSTEMSTATE_HUD_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_3: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_CONSOLE_OFF (0U)
 *   SYSTEMSTATE_CONSOLE_STANDBY (1U)
 *   SYSTEMSTATE_CONSOLE_ON (2U)
 *   SYSTEMSTATE_CONSOLE_STARTUP (3U)
 *   SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_4: Enumeration of integer in interval [0...255] with enumerators
 *   KL15OFF (0U)
 *   KL15ON (1U)
 * Rte_DT_SystemState_RecordType_5_0: Enumeration of integer in interval [0...255] with enumerators
 *   VOLTAGE_OUT_LOWSLEEP (0U)
 *   VOLTAGE_OUT_NORMAL (1U)
 *   VOLTAGE_OUT_HIGHALARM (2U)
 *   VOLTAGE_OUT_HIGHSLEEP (3U)
 *   VOLTAGE_OUT_LOWALARM (4U)
 *   VOLTAGE_OUT_NUM (5U)
 * Rte_DT_SystemState_RecordType_6: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_SP_OFF (0U)
 *   SYSTEMSTATE_SP_SHUTDOWN (1U)
 *   SYSTEMSTATE_SP_STANDBY (2U)
 *   SYSTEMSTATE_SP_SOCOFF (3U)
 * Rte_DT_SystemState_RecordType_7_0: Enumeration of integer in interval [0...255] with enumerators
 *   TEMP_LOW_SLEEP (0U)
 *   TEMP_NORMAL (1U)
 *   TEMP_HIGH_PROTECT (2U)
 *   TEMP_HIGH_SLEEP (3U)
 *   TEMP_STATE_NUM (4U)
 *   TEMP_STATE_INIT (255U)
 * VehOdoInfo_0x265: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 *
 * Array Types:
 * ============
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * DataArrayType_uint8_1: Array with 1 element(s) of type uint8
 * DataArrayType_uint8_2: Array with 2 element(s) of type uint8
 * DataArrayType_uint8_3: Array with 3 element(s) of type uint8
 * DataArrayType_uint8_4: Array with 4 element(s) of type uint8
 * Dem_MaxDataValueType: Array with 4 element(s) of type uint8
 * Rte_DT_s_OdoRteGetParament_t_2: Array with 3 element(s) of type uint32
 * Rte_DT_s_OdoRteGetParament_t_3: Array with 3 element(s) of type uint32
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * DateTimeType_t: Record with elements
 *   u16Year of type uint16
 *   u8Month of type uint8
 *   u8Day of type uint8
 *   u8Hour of type uint8
 *   u8Minutes of type uint8
 *   u8Seconds of type uint8
 *   u8TimeMode of type uint8
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SG_ABS3: Record with elements
 *   ABSActv_0x265 of type ABSActv_0x265
 *   ABSFailSts_0x265 of type ABSFailSts_0x265
 *   CheckSum_ABS3_0x265 of type CheckSum_ABS3_0x265
 *   dummy_ABS3_0 of type dummy_ABS3_0
 *   dummy_ABS3_1 of type dummy_ABS3_1
 *   dummy_ABS3_2 of type dummy_ABS3_2
 *   dummy_ABS3_3 of type dummy_ABS3_3
 *   EBDActv_0x265 of type EBDActv_0x265
 *   EBDFailSts_0x265 of type EBDFailSts_0x265
 *   RollingCounter_ABS3_0x265 of type RollingCounter_ABS3_0x265
 *   VehOdoInfo_0x265 of type VehOdoInfo_0x265
 *   VehOdoInfoSts_0x265 of type VehOdoInfoSts_0x265
 *   VehSpd_0x265 of type VehSpd_0x265_2
 *   VehSpdVld_0x265 of type VehSpdVld_0x265
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 * s_OdoRteGetParament_t: Record with elements
 *   OdoKmValue_u32 of type uint32
 *   OdoMileValue_u32 of type uint32
 *   TripKmValue_u32 of type Rte_DT_s_OdoRteGetParament_t_2
 *   TripMileValue_u32 of type Rte_DT_s_OdoRteGetParament_t_3
 *   FsrvKmValue_s32 of type sint32
 *   FsrvMileValue_s32 of type sint32
 *   OdoTripIsaInvalid of type uint8
 *   OdoInputlValid of type uint8
 *   NvmBlockWriteFlag of type uint32
 *   ClearData_u32 of type uint32
 *   FsrvStatus of type uint8
 *   RunCounter_u8 of type uint8
 *   VinCheckFlag_u8 of type uint8
 *   ClearFlag_u8 of type uint8
 * s_SpeedoInfo_t: Record with elements
 *   OverSpdWrnFlg of type uint8
 *   VehRunSts of type uint8
 *   IndicateSpeed of type uint16
 *   RealSpeed of type uint16
 *   IndicateSpeedMile of type uint16
 *   RealSpeedMile of type uint16
 *   RealSpeedBak of type uint16
 *   Msg_missingSts of type uint8
 *   VehSpdVld of type uint8
 * s_TachoInfo_t: Record with elements
 *   EngRunSts of type uint8
 *   EngSpd of type uint16
 *   TimeOutFlag of type uint8
 *   EngSpdBak of type uint16
 *   Msg_missingSts of type uint8
 *
 *********************************************************************************************************************/


#define SocDtcProcess_START_SEC_CODE
#include "SocDtcProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd001_Vehicle_Speed_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd001_Vehicle_Speed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd001_Vehicle_Speed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd001_Vehicle_Speed_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd001_Vehicle_Speed_ReadData (returns application error)
 *********************************************************************************************************************/

    if(TRUE == sgAbs3Ptr.VehSpdVld_0x265)
    {
        Data[0] = (uint8)(sgAbs3Ptr.VehSpd_0x265 >> 8);
        Data[1] = (uint8)sgAbs3Ptr.VehSpd_0x265;
    }
    else
    {
         Data[0] = 0;
         Data[1] = 0;
    }
    
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd002_EngineSpeed_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd002_EngineSpeed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd002_EngineSpeed_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd002_EngineSpeed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd002_EngineSpeed_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd002_EngineSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd002_EngineSpeed_ReadData (returns application error)
 *********************************************************************************************************************/

    if(TRUE == sgEngSpdVldty)
    {
       Data[0] = (uint8)(sgEngSpd >> 8);
       Data[1] = (uint8)sgEngSpd;
    }
    else
    {
       Data[0] = 0;
       Data[1] = 0;
    }
    
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd003_OperatingVoltage_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd003_OperatingVoltage>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd003_OperatingVoltage_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_1
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd003_OperatingVoltage_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd003_OperatingVoltage_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd003_OperatingVoltage_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd003_OperatingVoltage_ReadData (returns application error)
 *********************************************************************************************************************/
    float64 PowerVoltageValue = 0.0f;
    if(systemPowerStatus.s_PowerVoltage.value > 25.5f)
    {
       systemPowerStatus.s_PowerVoltage.value = 25.5f;
    }
    PowerVoltageValue = systemPowerStatus.s_PowerVoltage.value * 10.0f;
    *Data = (uint8)(PowerVoltageValue);
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd004_Odometer_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd004_Odometer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd004_Odometer_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_3
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd004_Odometer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd004_Odometer_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd004_Odometer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd004_Odometer_ReadData (returns application error)
 *********************************************************************************************************************/
    if(OdoData.OdoKmValue_u32 > ODO_MAX_SNAPSHOT_VALUE)
    {
      OdoData.OdoKmValue_u32 = ODO_MAX_SNAPSHOT_VALUE;
    }
    Data[0] = (uint8)((OdoData.OdoKmValue_u32/100u) >> 16);
    Data[1] = (uint8)((OdoData.OdoKmValue_u32/100u) >> 8);
    Data[2] = (uint8)(OdoData.OdoKmValue_u32/100u);
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd005_DTC_Occurrence_Timer>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_rpSR_RTCTimer_UtcTime(sint64 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_4
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd005_DTC_Occurrence_Timer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData (returns application error)
 *********************************************************************************************************************/
    sint64 tUtcTime;
    uint32 u32TmpDate = 0;
    DateTimeType_t currentDate;
    Rte_Read_rpSR_RTCTimer_UtcTime(&tUtcTime);
    Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar(tUtcTime, &currentDate);
    
    currentDate.u8Month += 1;
    
    u32TmpDate = ((currentDate.u16Year%100u)/10u) & 0x0Fu;
    u32TmpDate <<= 4;
    u32TmpDate |= (currentDate.u16Year%10u) & 0x0Fu;
    u32TmpDate <<= 4;
    u32TmpDate |= (currentDate.u8Month & 0x0Fu);
    u32TmpDate <<= 5;
    u32TmpDate |= (currentDate.u8Day & 0x1Fu);
    u32TmpDate <<= 5;
    u32TmpDate |= (currentDate.u8Hour & 0x1Fu);
    u32TmpDate <<= 6;
    u32TmpDate |= (currentDate.u8Minutes & 0x3Fu);
    u32TmpDate <<= 4;

    Data[0] = (uint8)(u32TmpDate >> 24);
    Data[1] = (uint8)(u32TmpDate >> 16);
    Data[2] = (uint8)(u32TmpDate >> 8);
    Data[3] = (uint8)(u32TmpDate);
    
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd006_ActualRotationSpeed>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd006_ActualRotationSpeed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData (returns application error)
 *********************************************************************************************************************/
    if(SocVConfigDataBuf[VCONFIG_KIND_FUEL] == 0x5)
    {
        Data[0] = (uint8)(mcuActSpd >> 8);
        Data[1] = (uint8)mcuActSpd;
    }
    else
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;
    }

    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_0xd007_ActualRotationSpeed02>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_0xd007_ActualRotationSpeed02_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData (returns application error)
 *********************************************************************************************************************/
    Data[0] = 0xFF;
    Data[1] = 0xFF;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClearDtcNotificationFinish_ClearDtcNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearDtcNotification> of PortPrototype <ClearDtcNotificationFinish>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ClearDTC_Service0x14_StatusFlag(uint8 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ClearDtcNotificationFinish_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ClearDtcNotification_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClearDtcNotificationFinish_ClearDtcNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) ClearDtcNotificationFinish_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClearDtcNotificationFinish_ClearDtcNotification (returns application error)
 *********************************************************************************************************************/
  (void)CancelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable); 

  Rte_Write_ClearDTC_Service0x14_StatusFlag(reqMonitorReInitCounter);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ClearDtcNotificationStart_ClearDtcNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClearDtcNotification> of PortPrototype <ClearDtcNotificationStart>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pPSR_DiagMonitorReInitFlag_ChangeCounter(uint32 data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType ClearDtcNotificationStart_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ClearDtcNotification_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ClearDtcNotificationStart_ClearDtcNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SocDtcProcess_CODE) ClearDtcNotificationStart_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ClearDtcNotificationStart_ClearDtcNotification (returns application error)
 *********************************************************************************************************************/
  (void)SetRelAlarm(Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable, 0 + (TickType)1,2);
  reqMonitorReInitCounter++;
  Rte_Write_pPSR_DiagMonitorReInitFlag_ChangeCounter(reqMonitorReInitCounter);
  QNXDtcReinitRsq.ServiceId = 0X14;
  QNXDtcReinitRsq.Type = 0;
  iviDtcReinitRsq.ServiceId = 0X14;
  iviDtcReinitRsq.Type = 0;
  writeTimeCnt = 0;
  IPC_M2S_DiagnoseQNXDtcReinitRequest_Transmit(&QNXDtcReinitRsq);
  IPC_M2S_DiagnoseIVIDtcReinitRequest_Transmit(&iviDtcReinitRsq);
  
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPCIviReportDtcStatus_IpcIviReportDtcSts
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IpcIviReportDtcSts> of PortPrototype <IPCIviReportDtcStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPCIviReportDtcStatus_IpcIviReportDtcSts(uint8 *data, uint8 length)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPCIviReportDtcStatus_IpcIviReportDtcSts_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) IPCIviReportDtcStatus_IpcIviReportDtcSts(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data, uint8 length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPCIviReportDtcStatus_IpcIviReportDtcSts
 *********************************************************************************************************************/
    if(iviReportDtcEventFlag != TRUE)
    {
        IPC_S2M_DiagnoseIVIReportEventRequest_Receive(data,&iviReportDtcData,(uint32_t)length);
        iviReportDtcEventFlag = TRUE;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPCSocReportDtcStatus_IpcSocReportDtcStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IpcSocReportDtcStatus> of PortPrototype <IPCSocReportDtcStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPCSocReportDtcStatus_IpcSocReportDtcStatus(uint8 *Data, uint8 Length)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPCSocReportDtcStatus_IpcSocReportDtcStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) IPCSocReportDtcStatus_IpcSocReportDtcStatus(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data, uint8 Length) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPCSocReportDtcStatus_IpcSocReportDtcStatus
 *********************************************************************************************************************/
    if(eventRequestFlag != TRUE)
    {
        IPC_S2M_DiagnoseQNXReportEventRequest_Receive(Data, &reportDtcData, Length);
        eventRequestFlag = TRUE;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PpCS_AppClearDTCInfo_AppClearDTCInfo
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <AppClearDTCInfo> of PortPrototype <PpCS_AppClearDTCInfo>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ClearDTC_ClearDTC(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ClearDTC_DEM_CLEAR_BUSY, RTE_E_ClearDTC_DEM_CLEAR_FAILED, RTE_E_ClearDTC_DEM_CLEAR_MEMORY_ERROR, RTE_E_ClearDTC_DEM_PENDING, RTE_E_ClearDTC_DEM_WRONG_DTC, RTE_E_ClearDTC_DEM_WRONG_DTCORIGIN, RTE_E_ClearDTC_E_NOT_OK
 *   Std_ReturnType Rte_Call_ClearDTC_SelectDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ClearDTC_E_NOT_OK, RTE_E_ClearDTC_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, uint8 *Result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PpCS_AppClearDTCInfo_AppClearDTCInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) PpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PpCS_AppClearDTCInfo_AppClearDTCInfo
 *********************************************************************************************************************/
    uint8 fctRet;
    if(FALSE == OpStatus)
    {
        Rte_Call_ClearDTC_SelectDTC(0xffffff,DEM_DTC_FORMAT_UDS,DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    }
    
    fctRet = Rte_Call_ClearDTC_ClearDTC();
    if(RTE_E_ClearDTC_DEM_PENDING == fctRet)
    {
        *Result = CLEAR_DTC_PENDING;
    }
    else if(RTE_E_ClearDTC_E_OK == fctRet)
    {
        *Result = E_OK;
    }
    else
    {
        *Result = CLEAR_DTC_ERROR;
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PpCS_AppReadDtcInfomation_AppReadDtcInformation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <AppReadDtcInformation> of PortPrototype <PpCS_AppReadDtcInfomation>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, uint32 *DTCOfEvent)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetDebouncingOfEvent(Dem_EventIdType EventId, Dem_DebouncingStateType *DebouncingState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventEnableCondition(Dem_EventIdType EventId, boolean *ConditionFullfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL, RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventFailed(Dem_EventIdType EventId, boolean *EventFailed)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, uint8 *DestBuffer, uint16 *BufSize)
 *     Argument DestBuffer: uint8* is of type Dem_MaxDataValueType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL, RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventStatus(Dem_EventIdType EventId, Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventTested(Dem_EventIdType EventId, boolean *EventTested)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus(Dem_EventIdType EventId, Dem_UdsStatusByteType *UDSStatusByte)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetFaultDetectionCounter(Dem_EventIdType EventId, sint8 *FaultDetectionCounter)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE, RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *   Std_ReturnType Rte_Call_GeneralDiagnosticInfo_GetMonitorStatus(Dem_EventIdType EventId, Dem_MonitorStatusType *MonitorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GeneralDiagnosticInfo_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SocDtcPorcessExclusiveArea(void)
 *   void Rte_Exit_SocDtcPorcessExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PpCS_AppReadDtcInfomation_AppReadDtcInformation(uint8 *DtcInfo)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PpCS_AppReadDtcInfomation_AppReadDtcInformation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) PpCS_AppReadDtcInfomation_AppReadDtcInformation(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) DtcInfo) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PpCS_AppReadDtcInfomation_AppReadDtcInformation
 *********************************************************************************************************************/
    uint16 i;
    uint16 SizeOfEventTable;
    uint16 dtcIndx;
    uint8 fctRet;
    uint8 UdsStatus;

    uint8 *ptrIn = DtcInfo;
    uint32 tDtc;
    Dem_OperationCycleStateType powerCycleSts = 0;
    
    Rte_Call_OperationCycle_Power_up_down_GetOperationCycleState(&powerCycleSts);
    if(DEM_CYCLE_STATE_START == powerCycleSts)
    {
        //TM_TimerStartStamp(&timeStart);
        SizeOfEventTable = Dem_Cfg_GetSizeOfEventTable();
        dtcIndx = 0;
        for(i = 1;i < SizeOfEventTable;i++)
        {
            fctRet = Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus(i,&UdsStatus);
            if(E_OK == fctRet)
            {
                if((UdsStatus & (uint8)UDS_STATUS_MASK) != 0)
                {
                    
                  fctRet = Rte_Call_GeneralDiagnosticInfo_GetDTCOfEvent(i,DEM_DTC_FORMAT_UDS,&tDtc);

                  if((E_OK == fctRet)&&(tDtc > 0)&&(dtcIndx < (DTC_BUFFER_SIZE-3u)))
                  {
                      dtcBuffer[dtcIndx] = (uint8)(tDtc >>24);
                      dtcIndx++;
                      dtcBuffer[dtcIndx] = (uint8)(tDtc >>16);
                      dtcIndx++;
                      dtcBuffer[dtcIndx] = (uint8)(tDtc >>8);
                      dtcIndx++;
                      dtcBuffer[dtcIndx] = (uint8)(tDtc);
                      dtcIndx++;
                      
                  }
                  
                }
            }
        }
        Rte_Enter_SocDtcPorcessExclusiveArea();
        memcpy(ptrIn,(uint8 *)dtcBuffer,DTC_BUFFER_SIZE);
        memset(dtcBuffer,0,DTC_BUFFER_SIZE);
        Rte_Exit_SocDtcPorcessExclusiveArea();
        //TM_TimerElapsed(&timeStart,&timeResult);
    } 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SocDtcProcess_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SocDtcProcess_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) SocDtcProcess_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SocDtcProcess_Init
 *********************************************************************************************************************/
    KL15StsOnCounter = 0;
    reqMonitorReInitCounter = 0;
    Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, &sgAbs3Ptr.VehSpdVld_0x265, sizeof(sgAbs3Ptr.VehSpdVld_0x265));
    Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, &sgAbs3Ptr.VehSpd_0x265, sizeof(sgAbs3Ptr.VehSpd_0x265));
    // Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &sgEngSpdVldty, sizeof(sgEngSpdVldty));
    // Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, &sgEngSpd, sizeof(sgEngSpd));
    Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MCU_ACTROTSPD, &mcuActSpd, sizeof(mcuActSpd));
    Rte_Read_rpSR_OdoParament_Element(&OdoData);
    Rte_Read_rpSR_Power_Out_SystemStateOut(&systemPowerStatus);
    Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(SocVConfigDataBuf);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SocDtcProcess_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_VconfigKind_157Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_157Bytes
 *   Std_ReturnType Rte_Read_rpSR_EngSpd_EngSpd(EngSpd *data)
 *   Std_ReturnType Rte_Read_rpSR_OdoParament_Element(s_OdoRteGetParament_t *data)
 *   Std_ReturnType Rte_Read_rpSR_Power_Out_SystemStateOut(SystemState_RecordType *data)
 *   Std_ReturnType Rte_Read_rpSR_RTCTimer_SleepDateTime(sint64 *data)
 *   Std_ReturnType Rte_Read_rpSR_RTCTimer_UtcTime(sint64 *data)
 *   Std_ReturnType Rte_Read_rpSR_SG_ABS3_SG_ABS3(SG_ABS3 *data)
 *   Std_ReturnType Rte_Read_rpSR_SocDtcProcess_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SocDtcProcess_TachoInfo_Element(s_TachoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM(TMCU_ActSpd_RM *data)
 *   boolean Rte_IsUpdated_rpSR_SG_ABS3_SG_ABS3(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_pPSR_DiagMonitorReInitFlag_ChangeCounter(uint32 data)
 *   Std_ReturnType Rte_Write_ppSR_DtcInfoForIPErrorStatus_Element(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_cpCS_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EnableCondition_BatteryVoltage_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_EnableCondition_BatteryVoltage_10V_16V_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_EnableCondition_BatteryVoltage_12V_16V_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_EnableCondition_BatteryVoltage_12_5V_16V_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_EnableCondition_IgnOn_SetEnableCondition(boolean ConditionFulfilled)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EnableCondition_E_NOT_OK
 *   Std_ReturnType Rte_Call_OperationCycle_Ign_on_off_GetOperationCycleState(Dem_OperationCycleStateType *CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *   Std_ReturnType Rte_Call_OperationCycle_Ign_on_off_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *   Std_ReturnType Rte_Call_OperationCycle_Power_up_down_GetOperationCycleState(Dem_OperationCycleStateType *CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *   Std_ReturnType Rte_Call_OperationCycle_Power_up_down_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_E_NOT_OK, RTE_E_OperationCycle_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SocDtcProcess_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SocDtcProcess_CODE) SocDtcProcess_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SocDtcProcess_MainFunction
 *********************************************************************************************************************/
    uint32 dtcCode;
    Dem_EventStatusType EventSts;
    Std_ReturnType retValue;
    Std_ReturnType fctRet;
    Dem_OperationCycleStateType ignCycleSts = 0;
    Dem_OperationCycleStateType powerUpdownCycleSts = 0;
    IPC_M2S_DiagnoseQNXReportEventResponse_t qnxReportEventResponse;
	uint8   KL15RetValue = 0xFF;
    uint8   KL15Data  = 0x00;

    Rte_Read_rpSR_Power_Out_SystemStateOut(&systemPowerStatus);
    
    if((uint8)TRUE == systemPowerStatus.KL15State)
    {
        if(KL15StsOnCounter < 10u)
        {
            KL15StsOnCounter++;
            if(5u == KL15StsOnCounter)
            {
                Rte_Call_OperationCycle_Ign_on_off_SetOperationCycleState(DEM_CYCLE_STATE_END);
                KL15ChangeCounter += 1;
            }
        }
        else
        {
            Rte_Call_OperationCycle_Ign_on_off_GetOperationCycleState(&ignCycleSts);
            if(DEM_CYCLE_STATE_START != ignCycleSts)
            {
                Rte_Call_OperationCycle_Ign_on_off_SetOperationCycleState(DEM_CYCLE_STATE_START);
            }
            else
            {
                if(KL15ChangeCounterOld != KL15ChangeCounter)
                {
                    KL15ChangeCounterOld = KL15ChangeCounter;
                    reqMonitorReInitCounter++;
                    QNXDtcReinitRsq.ServiceId = 0X14;
                    QNXDtcReinitRsq.Type = 0;
                    iviDtcReinitRsq.ServiceId = 0X14;
                    iviDtcReinitRsq.Type = 0;
                    writeTimeCnt = 0;
                    Rte_Write_pPSR_DiagMonitorReInitFlag_ChangeCounter(reqMonitorReInitCounter);
                    IPC_M2S_DiagnoseQNXDtcReinitRequest_Transmit(&QNXDtcReinitRsq);
                    IPC_M2S_DiagnoseIVIDtcReinitRequest_Transmit(&iviDtcReinitRsq);
                }
            }
        }
    }
    else
    {
        KL15StsOnCounter = 0;
    }

    Rte_Call_OperationCycle_Power_up_down_GetOperationCycleState(&powerUpdownCycleSts);
    if((uint8)SYSTEMSTATE_SP_STANDBY == systemPowerStatus.SP_State)
    {
        if(DEM_CYCLE_STATE_START != powerUpdownCycleSts)
        {
            Rte_Call_OperationCycle_Power_up_down_SetOperationCycleState(DEM_CYCLE_STATE_START);
        }

    }

    if((uint8)SYSTEMSTATE_SP_SHUTDOWN == systemPowerStatus.SP_State)
    {
        if(DEM_CYCLE_STATE_START == powerUpdownCycleSts)
        {
            Rte_Call_OperationCycle_Power_up_down_SetOperationCycleState(DEM_CYCLE_STATE_END);
        }
    }

         
    KL15RetValue = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, &KL15Data, sizeof(KL15Data));

    if((KL15RetValue == RTE_E_OK) && (KL15Data == 2U))
    {
        Rte_Call_EnableCondition_IgnOn_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCondition_IgnOn_SetEnableCondition(FALSE);
    }
    
    if((systemPowerStatus.s_PowerVoltage.value > LOW_9_VOLTAGE_THRSH)&&(systemPowerStatus.s_PowerVoltage.value < HIGH_VOLTAGE_THRSH))
    {
        Rte_Call_EnableCondition_BatteryVoltage_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCondition_BatteryVoltage_SetEnableCondition(FALSE);
    }

    if((systemPowerStatus.s_PowerVoltage.value > LOW_10_VOLTAGE_THRSH)&&(systemPowerStatus.s_PowerVoltage.value < HIGH_VOLTAGE_THRSH))
    {
        Rte_Call_EnableCondition_BatteryVoltage_10V_16V_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCondition_BatteryVoltage_10V_16V_SetEnableCondition(FALSE);
    }

    if((systemPowerStatus.s_PowerVoltage.value > LOW_12_VOLTAGE_THRSH)&&(systemPowerStatus.s_PowerVoltage.value < HIGH_VOLTAGE_THRSH))
    {
        Rte_Call_EnableCondition_BatteryVoltage_12V_16V_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCondition_BatteryVoltage_12V_16V_SetEnableCondition(FALSE);
    }

    if((systemPowerStatus.s_PowerVoltage.value > LOW_12_5_VOLTAGE_THRSH)&&(systemPowerStatus.s_PowerVoltage.value < HIGH_VOLTAGE_THRSH))
    {
        Rte_Call_EnableCondition_BatteryVoltage_12_5V_16V_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCondition_BatteryVoltage_12_5V_16V_SetEnableCondition(FALSE);
    }

    Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, &sgAbs3Ptr.VehSpdVld_0x265, sizeof(sgAbs3Ptr.VehSpdVld_0x265));
    Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPD, &sgAbs3Ptr.VehSpd_0x265, sizeof(sgAbs3Ptr.VehSpd_0x265));

    // fctRet = Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, &sgEngSpdVldty, sizeof(sgEngSpdVldty));
    // Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, &sgEngSpd, sizeof(sgEngSpd));
    // if((E_OK != fctRet) && (COMEX_UPDATE_RECEIVED != fctRet))
    // {
    //      sgEngSpdVldty =0;
    //      sgEngSpd = 0;
    // }


    Rte_Read_rpSR_OdoParament_Element(&OdoData);
    /* Rte_Read_rpSR_TMCU_ActSpd_RM_TMCU_ActSpd_RM(&mcuActSpd); */
    if(SocVConfigDataBuf[VCONFIG_KIND_FUEL] == 0x5)
    {
        Rte_Call_rpCS_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MCU_ACTROTSPD, &mcuActSpd, sizeof(mcuActSpd));
    }

 	writeTimeCnt++;
    if(writeTimeCnt>50)
    {
       writeTimeCnt =51;
    }
    if((eventRequestFlag == TRUE)&&(writeTimeCnt > 50))
    {
        dtcCode = reportDtcData.DtcCode[0];
        dtcCode <<= 8;
        dtcCode +=reportDtcData.DtcCode[1];
        dtcCode <<= 8;
        dtcCode +=reportDtcData.DtcCode[2];
        
        EventSts = reportDtcData.Result;
        if((DEM_EVENT_STATUS_PASSED == EventSts)||( DEM_EVENT_STATUS_FAILED == EventSts))
        {
             IpDisplayErrorReport(dtcCode,EventSts);
             retValue = SocDiagnosticMonitorSetEventStatus(dtcCode, EventSts);
             if(E_OK == retValue)
             {
                qnxReportEventResponse.ServiceId = 0x70;
             }
             else
             {
                 qnxReportEventResponse.ServiceId = 0x7F;
             }
             memcpy(qnxReportEventResponse.DtcCode,reportDtcData.DtcCode,3);
             IPC_M2S_DiagnoseQNXReportEventResponse_Transmit(&qnxReportEventResponse);
        }
        eventRequestFlag = FALSE;

    }

    if(TRUE == iviReportDtcEventFlag)
    {
        IviDiagnoticMonitorSetEventSts();
        iviReportDtcEventFlag = FALSE;
    }
    
    if((ipDisplayErrStatus & (uint16)0xFC00)== 0)
    {
        Rte_Write_ppSR_DtcInfoForIPErrorStatus_Element(0);
    }
    else
    {
        Rte_Write_ppSR_DtcInfoForIPErrorStatus_Element(1);
    }

    //SocDiagnosticMonitorSetEventStatus(0x9A0613, DEM_EVENT_STATUS_FAILED);

    //PpCS_AppReadDtcInfomation_AppReadDtcInformation(buf);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SocDtcProcess_STOP_SEC_CODE
#include "SocDtcProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static  void IpDisplayErrorReport(uint32 Dtc,Dem_EventStatusType EventStatus)
{
    uint32 localDtc = Dtc;
    uint16 bitMask;
    boolean tmp = FALSE;
    switch(localDtc)
    {
        case 0x908D87:
            bitMask = 0x8000;
            tmp = TRUE;
            break;
        case 0xA10017:
            bitMask = 0x4000;
            tmp = TRUE;
            break;
        case 0xA10116:
            bitMask = 0x2000;
            tmp = TRUE;
            break;
        case 0xA10049:
            bitMask = 0x1000;
            tmp = TRUE;
            break;   
        case 0xA10149:
            bitMask = 0x0800;
            tmp = TRUE;
            break;
        case 0xA10249:
            bitMask = 0x0400;
            tmp = TRUE;
            break;
        default:
            tmp = FALSE;
            break;
    }
    if(TRUE == tmp)
    {
        if(DEM_EVENT_STATUS_PASSED == EventStatus)
        {
            ipDisplayErrStatus &= ~(bitMask);
        }
        else
        {
            ipDisplayErrStatus |= (bitMask); 
        } 
    }

}




static Std_ReturnType SocDiagnosticMonitorSetEventStatus(uint32 Dtc, Dem_EventStatusType EventStatus)
{
    uint16 i;
    Std_ReturnType lRetValue = E_NOT_OK;
    for(i = 0; i < dcmEx_cfg.dtcNumber; i++)
    {
        if(dcmEx_cfg.dtcCfgs[i].dtc == Dtc)
        {
            lRetValue = Dem_SetEventStatus(dcmEx_cfg.dtcCfgs[i].dtcId, EventStatus);
            break;
        }
    }
    return (lRetValue);
}


static void IviDiagnoticMonitorSetEventSts(void)
{
    uint8 eventSts;
    uint32 dtcCode;
    IPC_M2S_DiagnoseIVIReportEventResponse_t iviDtcReportRsp;
    dtcCode = iviReportDtcData.DtcCode[0];
    dtcCode <<= 8;
    dtcCode += iviReportDtcData.DtcCode[1];
    dtcCode <<= 8;
    dtcCode += iviReportDtcData.DtcCode[2];
    
    eventSts = iviReportDtcData.Result;
    if((DEM_EVENT_STATUS_PASSED == eventSts)||( DEM_EVENT_STATUS_FAILED == eventSts))
    {
        if(0xE00487 == dtcCode)
        {
            if(E_OK != Dem_SetEventStatus(DemConf_DemEventParameter_Lost_TCP_communication_Missing_Message, eventSts))
            {
                Dem_SetEventStatus(DemConf_DemEventParameter_Lost_TCP_communication_Missing_Message, eventSts);
                memcpy(iviDtcReportRsp.DtcCode,iviReportDtcData.DtcCode,3);
                iviDtcReportRsp.ServiceId = 0x70;
                IPC_M2S_DiagnoseIVIReportEventResponse_Transmit(&iviDtcReportRsp);
            }
            else
            {
                memcpy(iviDtcReportRsp.DtcCode,iviReportDtcData.DtcCode,3);
                iviDtcReportRsp.ServiceId = 0x70;
                IPC_M2S_DiagnoseIVIReportEventResponse_Transmit(&iviDtcReportRsp);
            }
        }
    }
}


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
