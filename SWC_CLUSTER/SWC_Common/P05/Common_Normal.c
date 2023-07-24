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
 *             File:  Common_Normal.c
 *           Config:  D:/code/VIP-P05/VIP_P05/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Common_Normal
 *  Generation Time:  2022-02-26 15:14:44
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Common_Normal>
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
 * ACAmbTemp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * APS_FLSideSnsrFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * APS_FRSideSnsrFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * APS_RLSideSnsrFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * APS_RRSideSnsrFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * APS_SysSoundIndcn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * APS_WorkSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * AccelPedalPosnVldty
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * AccelPedlPosnDiagc
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * AutoLmpSwtSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * BrkPedalSts_BCM
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CCO_Active
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CCO_TgtVel
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CCO_Warn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CR_BliSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
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
 * CouplingThermWarning
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * CruiseCtrlSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Csm_DecryptDataType_CsmPrimitives_AES128_Decrypt
 *   Used as Buffer for service.
 *
 * Csm_DecryptResultType_CsmPrimitives_AES128_Decrypt
 *   Used as Buffer for service.
 *
 * Csm_EncryptDataType_CsmPrimitives_AES128_Encrypt
 *   Used as Buffer for service.
 *
 * Csm_EncryptResultType_CsmPrimitives_AES128_Encrypt
 *   Used as Buffer for service.
 *
 * Csm_ResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DiagLmpReq
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * DrowsyDrvDetWarn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * DrvDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Dyn_PwrSv_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ECM_VehDstBackup
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * EMS_AuthenResult
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * ESP_HMI_WarningOn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EWP_Err
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EngClntTempWarn
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EngSVSSig
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * EngSpdVldty
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EngSpd_ForIP
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * EspFuncOffSts_mode
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FCTA_B_FuncSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FCTA_Warn
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FCTBTrig
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * FLTirePress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FLTirePressIndSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FLTireTemp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FLTireTempSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FRTirePress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FRTirePressIndSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FRTireTemp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FRTireTempSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * FuelConsumption
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * GPF_Warning
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * GentrWarnLmpSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * HiLowBeamSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IB_Warn
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * KL30BRelaySts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LRDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * LvPwrSysErr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MILSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * PASWorkCmd
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * PassengerDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * PowerRlyFault
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RLSFailSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RLTirePress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RLTirePressIndSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RLTireTemp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RLTireTempSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RRDoorSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RRTirePress
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RRTirePressIndSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RRTireTemp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RRTireTempSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RSDS_BliSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RSDS_BrkgTrig
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RSDS_CTA_Actv
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RSDS_ErrSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RSDS_IPSoundReq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RSDS_LCAResp
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RSDS_RCW_Trigger
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RSDS_TrailerSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RearELDLckSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RemoteModSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RotSteerWheel
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SDWActiveSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SDW_SoundIndcn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SS_Enable_Lamp
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * SS_Fault_Lamp
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Stat_PwrSv_Lvl
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SysPowerMod
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TGS_LEVER
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TSRSpdLim
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TSRSpdLimCfdc
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TSRSpdLimSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TSRSpdLimWarn
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TSRSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TSRTrfcSignVal
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TgtEngSpdIP
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * TgtEngSpdIPValid
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TirePressSysFailrIndcn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TrailerSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TranPMode_Sts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * TrunkSts
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WPC_FaultSts
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * WPC_PhoneReminder
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WarnEngStrtNotMeet
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WarnKeyInCarWhenExit
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WarnPowerNotInOffPosn
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * WarnVldKeyNotFound
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 *
 * Operation Prototypes:
 * =====================
 * CancelJob of Port Interface CsmDecrypt_CsmPrimitives_AES128_Decrypt
 *   Cancels the Job.
 *
 * Decrypt of Port Interface CsmDecrypt_CsmPrimitives_AES128_Decrypt
 *   This interface shall be used to start the Decrypt service of the CSM module.
 *
 * CancelJob of Port Interface CsmEncrypt_CsmPrimitives_AES128_Encrypt
 *   Cancels the Job.
 *
 * Encrypt of Port Interface CsmEncrypt_CsmPrimitives_AES128_Encrypt
 *   This interface shall be used to start the Encrypt service of the CSM module.
 *
 * GetCounterValue of Port Interface Os_Service
 *   This service reads the current count value of a counter (returning either the hardware timer ticks if counter is driven by hardware or the software ticks when user drives counter).
 *
 * GetElapsedValue of Port Interface Os_Service
 *   This service gets the number of ticks between the current tick value and a previously read tick value.
 *
 *
 * Runnable Entities:
 * ==================
 * Common_Normal_100msMainFunction
 *   OffSet:9ms
 *
 * Common_Normal_100msMainFunction_
 *   OffSet:19ms
 *
 * Common_Normal_10msMainFunction
 *   OffSet:2ms
 *
 * Common_Normal_10msMainFunction_
 *   OffSet:8ms
 *
 * Common_Normal_20msMainFunction
 *   OffSet:4ms
 *
 * Common_Normal_20msMainFunction_
 *   OffSet:14ms
 *
 * Common_Normal_20msMainFunction_A
 *   OffSet:7ms
 *
 * Common_Normal_20msMainFunction_B
 *   OffSet:17ms
 *
 * Common_Normal_5msMainFunction
 *   OffSet:0ms
 *
 *********************************************************************************************************************/

#include "Rte_Common_Normal.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_Odo_Interface.h"
#include "SWC_Fuel_Api_Process.h"
#include "SWC_Fuel_Api_Rte_Adapt.h"
#include "SWC_TT_Interface.h"
#include "SWC_WN_Interface.h"
#include "SWC_SM_Interface.h"
#include "SWC_TC_Process.h"
#include "SWC_TM_Interface.h"
#include "SWC_Chime_App.h"
#include "SWC_Chime_Process.h"
#include "SWC_TC_Rte_Adapt.h"
#include "SWC_TPMS.h"
#include "SWC_DM_Interface.h"
#include "SWC_ODO_Adapt.h"
#include "SWC_MenuSet.h"
#include "SWC_CL_Interface.h"
#include "SWC_Config.h"
#include "SWC_TC_NE_Process.h"
#include "SWC_Odo_Interface.h"

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
 * ABSActv_0x137: Boolean
 * ABSActv_0x265: Boolean
 * ABSFailSts_0x137: Boolean
 * ABSFailSts_0x265: Boolean
 * ACAmbTemp: Integer in interval [0...255]
 * ACC_LeTgtDx_2: Integer in interval [0...65535]
 * ACC_LeTgtDy_2: Integer in interval [0...255]
 * ACC_ObjDetecte_4: Boolean
 * ACC_RiTgtDx_2: Integer in interval [0...65535]
 * ACC_RiTgtDy_2: Integer in interval [0...255]
 * ACC_TakeOverReq_4: Boolean
 * AEB_JA_Resp_3: Boolean
 * AEB_PedResp_3: Boolean
 * AEB_PedTrig_2: Boolean
 * AEB_VehResp_3: Boolean
 * AEB_VehTrig_2: Boolean
 * AESErrSts_1: Boolean
 * AESResp_1: Boolean
 * ALC_Resp: Boolean
 * AccelPedlPosnDiagc: Integer in interval [0...255]
 * AirbFailLmpCmd_4: Boolean
 * CDPActv_0x137: Boolean
 * CDPActv_0x145: Boolean
 * CameraBlockageSts_3: Boolean
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * DrvSBR_4: Boolean
 * EBDFailSts_0x137: Boolean
 * EBDFailSts_0x265: Boolean
 * ECM_VehDstBackup: Integer in interval [0...16777215]
 * ELKResp_1: Boolean
 * ESPActvInfoLmp_0x137: Boolean
 * ESPFailSts_0x137: Boolean
 * ESPFuncOffSts_0x137: Boolean
 * ESSErrSts_1: Boolean
 * ESS_Pedresp_1: Boolean
 * ESS_Vehresp_1: Boolean
 * EngCoolantTemp: Integer in interval [0...255]
 * EngSpd_ForIP: Integer in interval [0...65535]
 * FFogLmpSts_F_PBOX: Boolean
 * FLTirePress: Integer in interval [0...255]
 * FLTireTemp: Integer in interval [0...255]
 * FRTirePress: Integer in interval [0...255]
 * FRTireTemp: Integer in interval [0...255]
 * FourL_Warn_0x137: Boolean
 * FourL_Warn_0x145: Boolean
 * FuelConsumption: Integer in interval [0...65535]
 * GazePosnX: Integer in interval [0...2047]
 * GazePosnY: Integer in interval [0...2047]
 * GazePosnZ: Integer in interval [0...2047]
 * HWA_Resp: Boolean
 * HeadDetn: Boolean
 * HeadPitchAng: Integer in interval [0...255]
 * HeadPosnX: Integer in interval [0...2047]
 * HeadPosnY: Integer in interval [0...2047]
 * HeadPosnZ: Integer in interval [0...2047]
 * HeadRollAng: Integer in interval [0...255]
 * HeadYawAng: Integer in interval [0...255]
 * HiBeamSts_F_PBOX: Boolean
 * HiPosnBrkLmpFailSts: Boolean
 * HoodSts_F_PBOX: Boolean
 * ICA_HandsOffResp: Boolean
 * IFCHUTInterface_1: Boolean
 * IFC_LaneCurve_2: Integer in interval [0...65535]
 * IFC_LeLane_dy_2: Integer in interval [0...65535]
 * IFC_NextLeLane_dy: Integer in interval [0...65535]
 * IFC_NextRiLane_dy: Integer in interval [0...65535]
 * IFC_RiLane_dy_2: Integer in interval [0...65535]
 * ISL_Resp: Boolean
 * IntelligentEvaResp_1: Boolean
 * LBrkLmpFailSts: Boolean
 * LCKResp_1: Boolean
 * LDWResp_1: Boolean
 * LHeadLmpFailSts: Boolean
 * LHiBeamFailSts: Boolean
 * LKAResp_1: Boolean
 * LLasHdLmpDiagSig: Boolean
 * LLowBeamFailSts: Boolean
 * LRPosnLmpFailSts: Boolean
 * LSSResp_1: Boolean
 * LTurnLmpSts_R_PBOX: Boolean
 * LasHdLmpSts_F_PBOX: Boolean
 * LicPlateLmpFailSts: Boolean
 * Longctrl_DecelToStopReq_DVR: Boolean
 * Longctrl_Decel_ReqValue_DVR_2: Integer in interval [0...255]
 * Longctrl_Decel_Req_DVR: Boolean
 * Longctrl_DrvOFF_Req_DVR: Boolean
 * Longctrl_EngTrqReqActive_DVR: Boolean
 * Longctrl_EngTrqReq_DVR_2: Integer in interval [0...65535]
 * Longctrl_VehHldReq_DVR: Boolean
 * Over_Spd_Warn_0x137: Boolean
 * Over_Spd_Warn_0x145: Boolean
 * ParkLmpSts_R_PBOX: Boolean
 * PassSBR_4: Boolean
 * PosnLmpOutpSts_R_PBOX: Boolean
 * PressBrakePedalPointOut: Boolean
 * RBrkLmpFailSts: Boolean
 * RCTA_warningReqLeft: Boolean
 * RCTA_warningReqRight: Boolean
 * RFogLmpFailSts_R_PBOX: Boolean
 * RFogLmpSts_R_PBOX: Boolean
 * RHeadLmpFailSts: Boolean
 * RHiBeamFailSts: Boolean
 * RLTirePress: Integer in interval [0...255]
 * RLTireTemp: Integer in interval [0...255]
 * RLasHdLmpDiagSig: Boolean
 * RLowBeamFailSts: Boolean
 * RRPosnLmpFailSts: Boolean
 * RRTirePress: Integer in interval [0...255]
 * RRTireTemp: Integer in interval [0...255]
 * RTurnLmpSts_R_PBOX: Boolean
 * RWinHeatgFailSts: Boolean
 * RWinHeatgIconRlyCmd: Boolean
 * RobustGazePitchAng: Integer in interval [0...255]
 * RobustGazeYawAng: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_0: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_1: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_2: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_3: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_4: Integer in interval [0...255]
 * Rte_DT_AVASDTCRet_5: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_0: Integer in interval [0...65535]
 * Rte_DT_MenuSetData_t_1: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_10: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_11: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_12: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_17: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_2: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_3: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_4: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_5: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_6: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_7: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_8: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_9: Integer in interval [0...255]
 * Rte_DT_NVMBlockMaintain_Type_0: Integer in interval [0...255]
 * Rte_DT_NVMBlockTCConfig_Type_0: Integer in interval [0...255]
 * Rte_DT_NVMBlockTC_Type_0: Integer in interval [0...255]
 * Rte_DT_NVMBlockTrip_0: Integer in interval [0...255]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * RvsLmpFailSts: Boolean
 * SecRowLSBR_4: Boolean
 * SecRowMidSBR_4: Boolean
 * SecRowRSBR_4: Boolean
 * Shift_N_Warn_0x137: Boolean
 * Shift_N_Warn_0x145: Boolean
 * SteerCorrnResp_0x147: Boolean
 * SteerCorrnResp_0x168: Boolean
 * TCU_Warn_P_faulty: Boolean
 * TCU_Warn_drive_faulty: Boolean
 * TCU_Warn_driver_leaves_car: Boolean
 * TCU_Warn_gearbox_N: Boolean
 * TCU_Warn_gearbox_faulty: Boolean
 * TCU_Warn_high_temp: Boolean
 * TCU_Warn_limphome_D: Boolean
 * TCU_Warn_limphome_P: Boolean
 * TCU_Warn_prohibit_P: Boolean
 * TCU_Warn_release_button: Boolean
 * TCU_Warn_shifter_faulty: Boolean
 * TCU_Warn_step_P: Boolean
 * TCU_Warn_vehicle_P: Boolean
 * TCU_gear_flashing: Boolean
 * TRANS_OIL_TEMP_0x236: Integer in interval [0...255]
 * TRANS_OIL_TEMP_0xc6: Integer in interval [0...255]
 * TRANS_Warning_LAMP: Boolean
 * TSM_Trailer_0x137: Boolean
 * TgtEngSpdIP: Integer in interval [0...4095]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * Urea_Level: Integer in interval [0...21]
 * VehOdoInfoSts_0x137: Boolean
 * VehOdoInfoSts_0x265: Boolean
 * VehSpdVld_0x137: Boolean
 * VehSpdVld_0x265: Boolean
 * VehSpd_0x137_2: Integer in interval [0...65535]
 * VehSpd_0x265: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * dummy_ABM1_0: Boolean
 * dummy_ABM1_1: Boolean
 * dummy_ABM1_2: Integer in interval [0...255]
 * dummy_ABM1_3: Integer in interval [0...255]
 * dummy_ABM1_4: Integer in interval [0...255]
 * dummy_ABM1_5: Integer in interval [0...255]
 * dummy_ABS3_0: Integer in interval [0...255]
 * dummy_ABS3_1: Integer in interval [0...255]
 * dummy_ABS3_2: Integer in interval [0...255]
 * dummy_ABS3_3: Integer in interval [0...255]
 * dummy_ACC_FD2_16: Boolean
 * dummy_ACC_FD2_17: Boolean
 * dummy_ACC_FD2_18: Integer in interval [0...255]
 * dummy_ACC_FD2_24: Integer in interval [0...255]
 * dummy_ACC_FD2_25: Boolean
 * dummy_ACC_FD2_33: Boolean
 * dummy_ACC_FD2_34: Boolean
 * dummy_ACC_FD2_35: Integer in interval [0...255]
 * dummy_ACC_FD2_36: Integer in interval [0...255]
 * dummy_ACC_FD2_44: Integer in interval [0...255]
 * dummy_ACC_FD2_45: Integer in interval [0...255]
 * dummy_ACC_FD2_46: Integer in interval [0...255]
 * dummy_ACC_FD2_47: Integer in interval [0...255]
 * dummy_ACC_FD2_48: Integer in interval [0...255]
 * dummy_ACC_FD2_49: Integer in interval [0...255]
 * dummy_ACC_FD2_50: Integer in interval [0...255]
 * dummy_AEB_FD2_22: Integer in interval [0...255]
 * dummy_AEB_FD2_23: Integer in interval [0...255]
 * dummy_AEB_FD2_24: Integer in interval [0...255]
 * dummy_AEB_FD2_25: Integer in interval [0...255]
 * dummy_AEB_FD2_26: Integer in interval [0...255]
 * dummy_AEB_FD2_27: Integer in interval [0...255]
 * dummy_AEB_FD2_28: Integer in interval [0...255]
 * dummy_AEB_FD2_29: Integer in interval [0...255]
 * dummy_AEB_FD2_30: Boolean
 * dummy_AEB_FD2_31: Integer in interval [0...255]
 * dummy_AEB_FD2_32: Integer in interval [0...255]
 * dummy_AEB_FD2_33: Integer in interval [0...255]
 * dummy_AEB_FD2_34: Integer in interval [0...255]
 * dummy_AEB_FD2_35: Integer in interval [0...255]
 * dummy_DCT_FD4_10: Boolean
 * dummy_DCT_FD4_11: Integer in interval [0...255]
 * dummy_DCT_FD4_8: Integer in interval [0...255]
 * dummy_DCT_FD4_9: Integer in interval [0...255]
 * dummy_EPB1_0: Integer in interval [0...255]
 * dummy_EPB1_1: Integer in interval [0...255]
 * dummy_EPB1_2: Boolean
 * dummy_EPB1_3: Integer in interval [0...255]
 * dummy_EPB1_4: Integer in interval [0...255]
 * dummy_EPB1_5: Integer in interval [0...255]
 * dummy_EPB1_6: Integer in interval [0...255]
 * dummy_EPB1_7: Integer in interval [0...255]
 * dummy_EPS1_10: Integer in interval [0...255]
 * dummy_EPS1_11: Integer in interval [0...255]
 * dummy_EPS1_12: Integer in interval [0...255]
 * dummy_EPS1_13: Integer in interval [0...255]
 * dummy_EPS1_14: Integer in interval [0...255]
 * dummy_EPS1_15: Boolean
 * dummy_EPS1_8: Integer in interval [0...255]
 * dummy_EPS1_9: Integer in interval [0...255]
 * dummy_EPS_FD1_24: Integer in interval [0...255]
 * dummy_EPS_FD1_25: Integer in interval [0...255]
 * dummy_EPS_FD1_26: Integer in interval [0...255]
 * dummy_EPS_FD1_27: Integer in interval [0...255]
 * dummy_EPS_FD1_28: Integer in interval [0...255]
 * dummy_EPS_FD1_29: Integer in interval [0...255]
 * dummy_EPS_FD1_30: Integer in interval [0...255]
 * dummy_EPS_FD1_31: Boolean
 * dummy_ESP2_10: Integer in interval [0...255]
 * dummy_ESP2_11: Boolean
 * dummy_ESP2_12: Boolean
 * dummy_ESP2_13: Integer in interval [0...255]
 * dummy_ESP2_14: Integer in interval [0...255]
 * dummy_ESP2_8: Integer in interval [0...255]
 * dummy_ESP2_9: Integer in interval [0...255]
 * dummy_ESP_FD2_34: Integer in interval [0...255]
 * dummy_ESP_FD2_35: Integer in interval [0...255]
 * dummy_ESP_FD2_36: Integer in interval [0...255]
 * dummy_ESP_FD2_41: Integer in interval [0...255]
 * dummy_ESP_FD2_42: Integer in interval [0...255]
 * dummy_ESP_FD2_43: Integer in interval [0...255]
 * dummy_ESP_FD2_44: Integer in interval [0...255]
 * dummy_ESP_FD2_45: Integer in interval [0...255]
 * dummy_ESP_FD2_46: Integer in interval [0...255]
 * dummy_ESP_FD2_47: Boolean
 * dummy_ESP_FD2_48: Integer in interval [0...255]
 * dummy_ESP_FD2_49: Integer in interval [0...255]
 * dummy_ESP_FD2_57: Integer in interval [0...255]
 * dummy_ESP_FD2_58: Integer in interval [0...255]
 * dummy_ESP_FD2_59: Integer in interval [0...255]
 * dummy_ESP_FD2_60: Boolean
 * dummy_ESP_FD2_61: Boolean
 * dummy_ESP_FD2_62: Integer in interval [0...255]
 * dummy_ESP_FD2_63: Integer in interval [0...255]
 * dummy_IFC_FD2_10: Integer in interval [0...255]
 * dummy_IFC_FD2_11: Integer in interval [0...255]
 * dummy_IFC_FD2_12: Integer in interval [0...255]
 * dummy_IFC_FD2_16: Integer in interval [0...255]
 * dummy_IFC_FD2_17: Integer in interval [0...255]
 * dummy_IFC_FD2_18: Integer in interval [0...255]
 * dummy_IFC_FD2_19: Integer in interval [0...255]
 * dummy_IFC_FD2_20: Integer in interval [0...255]
 * dummy_IFC_FD2_8: Integer in interval [0...255]
 * dummy_IFC_FD2_9: Integer in interval [0...255]
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint64: Integer in interval [-9223372036854775808...9223372036854775807] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ACC_FctSts_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Fuction_Not_Available (0U)
 *   Cx1_Fuction_Available (1U)
 *   Cx2_Performance_degradation (2U)
 *   Cx3_Reserved (3U)
 * ACC_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_display (0U)
 *   Cx01_Unable_to_activate_ACC_due_to_speed_not_achive (1U)
 *   Cx02_ACC_active_control_is_cancelled (2U)
 *   Cx03_Resvered (3U)
 *   Cx04_ACC_and_PEBS_temporary_unavailable (4U)
 *   Cx05_Unable_to_activate_ACC_due_to_other_limitation_except_speed_not_achive_ (5U)
 *   Cx06_ACC_and_PEBS_error (6U)
 *   Cx07_ACC_temporary_unavailable (7U)
 *   Cx08_Resvered (8U)
 *   Cx09_Blindness (9U)
 *   Cx0A_Resvered (10U)
 *   Cx1F_Resvered (31U)
 * ACC_LeTargrtDection: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_LeTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_ModDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_OFF_Mode (0U)
 *   Cx01_Passive_Mode (1U)
 *   Cx02_StandBy_Mode (2U)
 *   Cx03_Active_Control_Mode (3U)
 *   Cx04_Brake_Only_Mode (4U)
 *   Cx05_Override (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_ACC_and_PEBS_Failure_mode (7U)
 *   Cx08_ACC_Failure_mode (8U)
 *   Cx09_Reserved (9U)
 *   Cx1F_Reserved (31U)
 * ACC_RiTargrtDetn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_RiTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_SpdSetValue_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFE_Valid_value (254U)
 *   CxFF_No_display (255U)
 * ACC_TgtObjBarDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Distance_1_one_bar (1U)
 *   Cx2_Distance_2_two_bars (2U)
 *   Cx3_Distance_3_three_bars (3U)
 *   Cx4_Distance_4_four_bars (4U)
 *   Cx5_Resvered (5U)
 *   Cx7_Resvered (7U)
 * ACC_TimeGapSet_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_TimeGap_1_1s (1U)
 *   Cx2_TimeGap_2_1_4s (2U)
 *   Cx3_TimeGap_3_1_8s (3U)
 *   Cx4_TimeGap_4_2_1s (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * AEB_JABrkTrig_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_tirggered (0U)
 *   Cx1_AEB_JA_Function_Triggered_for_vehicle (1U)
 *   Cx2_AEB_JA_Function_Triggered_for_pedestrian (2U)
 *   Cx3_reverse (3U)
 * AEB_JAFuncSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_JA_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_JA_Performance_degradation (3U)
 * AEB_JA_Warn_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_for_vehicle (1U)
 *   Cx2_Warning_for_pedestrian (2U)
 *   Cx3_reverse (3U)
 * AESSts_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * AESintervention: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_intervention (0U)
 *   Cx1_Left_intervention (1U)
 *   Cx2_Right_intervention (2U)
 *   Cx3_Reserved (3U)
 * ALC_InterSysInfoDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Automatic_lane_change_function_failure (1U)
 *   Cx2_Reserve (2U)
 *   Cx3_Reserve (3U)
 * APS_FLSideSnsrFailSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_no_failure (0U)
 *   Cx1_failure (1U)
 * APS_FRSideSnsrFailSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_no_failure (0U)
 *   Cx1_failure (1U)
 * APS_RLSideSnsrFailSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_no_failure (0U)
 *   Cx1_failure (1U)
 * APS_RRSideSnsrFailSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_no_failure (0U)
 *   Cx1_failure (1U)
 * APS_SysSoundIndcn: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Tone_0_No_Warning (0U)
 *   Cx1_Tone_1_APS_failed_tone (1U)
 *   Cx2_Tone_2_APS_successful_tone (2U)
 *   Cx3_Tone_3_APS_warning_tone (3U)
 *   Cx4_Tone_4_APS_request_tone (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * APS_WorkSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Searching (2U)
 *   Cx3_Guidance (3U)
 *   Cx4_Failed (4U)
 *   Cx5_Wait_for_Engine_restart (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * AVHErrSts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_AVH_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * AVHErrSts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_AVH_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * AVHSts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Standby (1U)
 *   Cx2_active (2U)
 *   Cx3_Reserved (3U)
 * AVHSts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Standby (1U)
 *   Cx2_active (2U)
 *   Cx3_Reserved (3U)
 * AccelPedalPosnVldty: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 *   Cx2_Init_value (2U)
 *   Cx3_Reserved (3U)
 * AutoLmpSwtSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Non_Auto (0U)
 *   Cx1_Auto (1U)
 * BSD_LCA_warningReqRight: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_level_1 (1U)
 *   Cx2_Warning_level_2 (2U)
 *   Cx3_Reserved (3U)
 * BSD_LCA_warningReqleft: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_level_1 (1U)
 *   Cx2_Warning_level_2 (2U)
 *   Cx3_Reserved (3U)
 * BrkPedalSts_BCM: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * CCO_Active: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_Active (0U)
 *   Cx1_Active (1U)
 *   Cx2_Stand_by (2U)
 *   Cx3_Failed (3U)
 * CCO_TgtVel: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_Valid_values (0U)
 *   Cx1F_Valid_values (31U)
 * CCO_Warn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Warn (0U)
 *   Cx1_Please_Release_EPB (1U)
 *   Cx2_Please_slow_down (2U)
 *   Cx3_Reserved (3U)
 * CR_BliSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Blindness (0U)
 *   Cx1_Blindness (1U)
 * CheckSum_ABM1_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPB1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPS1_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPS1_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP1_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP2_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP2_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Checksum_ACC3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC4_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC8_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_AEB2_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_AEB3_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_IFC3_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_IFC4_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_IFC5_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_IFC6: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * CouplingThermWarning: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_coupling_thermal_failsafe (0U)
 *   Cx1_coupling_thermal_failsafe (1U)
 * CrashOutputSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_crash (0U)
 *   Cx01_Reserved (1U)
 *   Cx02_Front_First_level (2U)
 *   Cx03_rear_crash_Reserved_ (3U)
 *   Cx04_Reserved (4U)
 *   Cx07_Reserved (7U)
 *   Cx08_Right_hand_side (8U)
 *   Cx09_Reserved (9U)
 *   Cx0F_Reserved (15U)
 *   Cx10_Left_hand_side (16U)
 *   Cx11_Rollover_Reserved_ (17U)
 *   Cx12_Static_Roll_Reserved_ (18U)
 *   Cx13_Reserved (19U)
 *   CxFF_Reserved (255U)
 * CruCha_ModDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Idle_mode (1U)
 *   Cx2_Ready_mode (2U)
 *   Cx3_Active (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Warning_Level_1 (5U)
 *   Cx6_Warning_Level_2 (6U)
 *   Cx7_Warning_Level_3 (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Failure (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * CruChar_InterSysInfoDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_CruiseChauffer_due_to_other_limitation (1U)
 *   Cx2_CruiseChauffer_active_control_is_cancelled (2U)
 *   Cx3_CruiseChauffer_temporarily_unavailable (3U)
 *   Cx4_Take_over_request (4U)
 *   Cx5_Current_IGN_Cycle_Function_Inhibit (5U)
 *   Cx6_Please_Keep_Attention (6U)
 *   Cx7_To_cross_the_tunnel_please_take_over_in_time (7U)
 *   Cx8_Have_a_branch_road_ahead_Please_take_over_in_time (8U)
 *   Cx9_Hands_off_warning (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * CruiseCtrlSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 *   Cx2_Standby (2U)
 *   Cx3_Error (3U)
 * Csm_ResultType: Enumeration of integer in interval [0...8] with enumerators
 *   E_NOT_OK (1U)
 *   E_SMALL_BUFFER (2U)
 *   E_ENTROPY_EXHAUSTION (3U)
 *   E_KEY_READ_FAIL (4U)
 *   E_KEY_NOT_AVAILABLE (5U)
 *   E_KEY_NOT_VALID (6U)
 *   E_JOB_CANCELED (7U)
 *   E_KEY_EMPTY (8U)
 * DCT_PrsBrk_Warn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Press_brake_and_Unlock_button_to_shift (1U)
 *   Cx2_Press_Unlock_button_to_shift (2U)
 *   Cx3_Press_brake_to_shift (3U)
 * DCT_RaceModeSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 *   Cx2_Turn_Off (2U)
 *   Cx3_Forbidden (3U)
 *   Cx4_Reserved_treat_as_0x0_inactive_ (4U)
 *   Cx7_Reserved_treat_as_0x0_inactive_ (7U)
 * DCT_ShftNotAlwd_Warn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
 *   Cx2_Engage_P_not_allowed_due_to_high_vehicle_speed (2U)
 *   Cx3_Transmission_is_in_N_park_lock_is_not_locked (3U)
 * DCT_ShftRecom_M: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Recommendation (0U)
 *   Cx1_Up_Shift (1U)
 *   Cx2_Down_Shift (2U)
 *   Cx3_Reserved (3U)
 * DMSSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Blindness (0U)
 *   Cx1_Error (1U)
 *   Cx2_Active (2U)
 *   Cx3_Not_active (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * DOW_warningReqRight: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_level_1 (1U)
 *   Cx2_Warning_level_2 (2U)
 *   Cx3_Reserved (3U)
 * DOW_warningReqleft: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_level_1 (1U)
 *   Cx2_Warning_level_2 (2U)
 *   Cx3_Reserved (3U)
 * DPF_Warning: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_self_cleaning (0U)
 *   Cx1_Please_place_self_cleaning (1U)
 *   Cx2_Please_start_the_car_and_keep_idle (2U)
 *   Cx3_In_the_clean (3U)
 *   Cx4_Clean_finishi_thank_you_for_waiting (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Invalid (6U)
 *   Cx7_Invalid (7U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 *   DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
 *   DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
 *   DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
 *   DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
 * DiagLmpReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Lamp_is_not_being_requested (0U)
 *   Cx1_Lamp_is_being_requested (1U)
 * DisplayGear: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Current_gear_N (0U)
 *   Cx1_Current_gear_1 (1U)
 *   Cx2_Current_gear_2 (2U)
 *   Cx3_Current_gear_3 (3U)
 *   Cx4_Current_gear_4 (4U)
 *   Cx5_Current_gear_5 (5U)
 *   Cx6_Current_gear_6 (6U)
 *   Cx7_Current_gear_7 (7U)
 *   Cx8_Current_gear_8 (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Current_gear_R (11U)
 *   CxC_Reserved (12U)
 *   CxD_Current_gear_P (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid_Value (15U)
 * DistrctnLvlQlty_ACC: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * DistrctnLvl_ACC: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_distraction (0U)
 *   Cx1_Low_level_distraction (1U)
 *   Cx2_Middle_level_distraction (2U)
 *   Cx3_Hi_level_distraction (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * DrivingModDis_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Standard (0U)
 *   Cx01_Sport (1U)
 *   Cx02_Snow (2U)
 *   Cx03_Mud (3U)
 *   Cx04_Sand (4U)
 *   Cx05_4L (5U)
 *   Cx06_Economic (6U)
 *   Cx07_Mode_Unkown (7U)
 *   Cx08_AUTO (8U)
 *   Cx09_Sport_ (9U)
 *   Cx0A_Off_road (10U)
 *   Cx0B_Stand_2H (11U)
 *   Cx0C_Expert (12U)
 *   Cx0D_Stand_4H (13U)
 *   Cx0E_Failed (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Snow_4H (16U)
 *   Cx11_Normal_4L (17U)
 *   Cx12_Rock_4L (18U)
 *   Cx13_Pothle_4L (19U)
 *   Cx14_MudSand_4L (20U)
 *   Cx15_Mountain_4L (21U)
 *   Cx16_reserved (22U)
 *   Cx1F_reserved (31U)
 * DrivingModDis_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Standard (0U)
 *   Cx01_Sport (1U)
 *   Cx02_Snow (2U)
 *   Cx03_Mud (3U)
 *   Cx04_Sand (4U)
 *   Cx05_4L (5U)
 *   Cx06_Economic (6U)
 *   Cx07_Mode_Unkown (7U)
 *   Cx08_AUTO (8U)
 *   Cx09_Sport_ (9U)
 *   Cx0A_Off_road (10U)
 *   Cx0B_Stand_2H (11U)
 *   Cx0C_Expert (12U)
 *   Cx0D_Stand_4H (13U)
 *   Cx0E_Failed (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Snow_4H (16U)
 *   Cx11_Normal_4L (17U)
 *   Cx12_Rock_4L (18U)
 *   Cx13_Pothle_4L (19U)
 *   Cx14_MudSand_4L (20U)
 *   Cx15_Mountain_4L (21U)
 *   Cx16_reserved (22U)
 *   Cx1F_reserved (31U)
 * DrivingModReq_ESP_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_Terrain_Control (0U)
 *   Cx01_Standard (1U)
 *   Cx02_Sport (2U)
 *   Cx03_Snow_Nex (3U)
 *   Cx04_Expert (4U)
 *   Cx05_Deep_Mud (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_Soft_sand (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_4L (9U)
 *   Cx0A_Economic (10U)
 *   Cx0B_Reserved (11U)
 *   Cx0C_Snow_TOD (12U)
 *   Cx0D_Off_road (13U)
 *   Cx0E_Sport_ (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Standard_2H (16U)
 *   Cx11_Reserved (17U)
 *   Cx12_Standard_4H (18U)
 *   Cx13_Snow_4H (19U)
 *   Cx14_Normal_4L (20U)
 *   Cx15_Rock_4L (21U)
 *   Cx16_Pothole_4L (22U)
 *   Cx17_MudSand_4L (23U)
 *   Cx18_Mountain_4L (24U)
 *   Cx19_Reserved (25U)
 *   Cx1F_Reserved (31U)
 * DrivingModReq_ESP_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_Terrain_Control (0U)
 *   Cx01_Standard (1U)
 *   Cx02_Sport (2U)
 *   Cx03_Snow_Nex (3U)
 *   Cx04_Expert (4U)
 *   Cx05_Deep_Mud (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_Soft_sand (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_4L (9U)
 *   Cx0A_Economic (10U)
 *   Cx0B_Reserved (11U)
 *   Cx0C_Snow_TOD (12U)
 *   Cx0D_Off_road (13U)
 *   Cx0E_Sport_ (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Stand_2H (16U)
 *   Cx11_Reserved (17U)
 *   Cx12_Stand_4H (18U)
 *   Cx13_Snow_4H (19U)
 *   Cx14_Normal_4L (20U)
 *   Cx15_Rock_4L (21U)
 *   Cx16_Pothole_4L (22U)
 *   Cx17_MudSand_4L (23U)
 *   Cx18_Mountain_4L (24U)
 *   Cx19_Reserved (25U)
 *   Cx1F_Reserved (31U)
 * DrowsnsLvl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Drowsiness (0U)
 *   Cx1_Low_level_Drowsiness (1U)
 *   Cx2_Middle_level_Drowsiness (2U)
 *   Cx3_High_level_Drowsiness (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * DrowsnsLvlQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * DrowsnsLvlQlty_ACC: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * DrowsnsLvl_ACC: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Drowsiness (0U)
 *   Cx1_Low_level_Drowsiness (1U)
 *   Cx2_Middle_level_Drowsiness (2U)
 *   Cx3_Hi_level_Drowsiness (3U)
 *   Cx4_Reserved (4U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * DrowsyDrvDetWarn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_1 (1U)
 *   Cx2_Warning_2 (2U)
 *   Cx3_Not_available (3U)
 * DrvAutoGearDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Neutral (0U)
 *   Cx1_1st_Gear (1U)
 *   Cx2_2nd_Gear (2U)
 *   Cx3_3rd_Gear (3U)
 *   Cx4_4th_Gear (4U)
 *   Cx5_5th_Gear (5U)
 *   Cx6_6th_Gear (6U)
 *   Cx7_7th_Gear (7U)
 *   Cx8_8th_Gear (8U)
 *   Cx9_9th_Gear (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * DrvDoorSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * DrvFaiMsg: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Message (0U)
 *   Cx1_Transmission_Malfunction (1U)
 *   Cx2_Transmission_P_engagement_fault (2U)
 *   Cx3_Transmission_P_disengagement_fault (3U)
 *   Cx4_Authentication_failure (4U)
 *   Cx5_Reserved (5U)
 *   CxE_Reserved (14U)
 *   CxF_transmission_limit_function (15U)
 * DrvGearDispSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Blank_No_display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_display_ (3U)
 * DrvModDispSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_BlankNo_Display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_Display_ (3U)
 * DrvModDisp_0x236: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_P (0U)
 *   Cx1_R (1U)
 *   Cx2_N (2U)
 *   Cx3_D (3U)
 *   Cx4_M (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * DrvModDisp_0xc6: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_P (0U)
 *   Cx1_R (1U)
 *   Cx2_N (2U)
 *   Cx3_D (3U)
 *   Cx4_M (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * DrvSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * DrvWarnMsg: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Text (0U)
 *   Cx1_PressBrake (1U)
 *   Cx2_TransToo_Hot (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * Dyn_PwrSv_Lvl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Level_1 (1U)
 *   Cx2_Level_2 (2U)
 *   Cx3_Level_3 (3U)
 *   Cx4_Level_4 (4U)
 *   Cx5_Level_5 (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * ELKActSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Left_Active (1U)
 *   Cx2_Right_active (2U)
 *   Cx3_Reserved (3U)
 * ELKMainState_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_ELK_OFF_ (0U)
 *   Cx1_ELK_Standby_ (1U)
 *   Cx2_ELK_Enable_ (2U)
 *   Cx3_ELK_Road_edge_Active_ (3U)
 *   Cx4_ELK_Oncoming_Active_oncoming_ (4U)
 *   Cx5_ELK_Overtaking_Active_overtaking_ (5U)
 *   Cx6_ELK_Failure (6U)
 *   Cx7_Reserved (7U)
 * EMS_AuthenResult: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Nothing (0U)
 *   Cx1_Authentication_failure (1U)
 *   Cx2_Authentication_success (2U)
 *   Cx3_Reserved (3U)
 * EPBErrSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Undefined (0U)
 *   Cx1_No_Error (1U)
 *   Cx2_Error (2U)
 *   Cx3_Diagnosis (3U)
 * EPBRedLmpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Lamp_flash (2U)
 *   Cx3_Reserved (3U)
 * EPBSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Closed (1U)
 *   Cx2_In_progress (2U)
 *   Cx3_unknown (3U)
 * EPBTextDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Gradient_too_high (1U)
 *   Cx2_Park_brake_force_not_enough (2U)
 *   Cx3_Park_brake_system_overheated (3U)
 *   Cx4_Remind_driver_to_apply_safety_belt (4U)
 *   Cx5_Park_brake_maintenance_mode (5U)
 *   Cx6_Roller_bench_mode (6U)
 *   Cx7_Please_Release_EPB (7U)
 *   Cx8_Please_Release_Rear_ELD (8U)
 *   Cx9_Reserved (9U)
 *   CxF_Reserved (15U)
 * EPS_FailSts_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_fault (0U)
 *   Cx1_Permanent_Error_Detected (1U)
 *   Cx2_Intermittent_Error_Detected (2U)
 *   Cx3_Reserved (3U)
 * EPS_FailSts_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_fault (0U)
 *   Cx1_Permanent_Error_Detected (1U)
 *   Cx2_Intermittent_Error_Detected (2U)
 *   Cx3_Reserved (3U)
 * EPS_SteerMod_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Comfort_Mode (0U)
 *   Cx1_sport_mode (1U)
 *   Cx2_Handiness_Mode (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * EPS_SteerMod_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Comfort_Mode (0U)
 *   Cx1_sport_mode (1U)
 *   Cx2_Handiness_Mode (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * ESP_HMI_WarningOn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning_lamp (0U)
 *   Cx1_Yellow_Lamp (1U)
 *   Cx2_Red_Lamp (2U)
 *   Cx3_reserved (3U)
 * ESSSts_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * ESSintervention: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_intervention (0U)
 *   Cx1_Left_intervention (1U)
 *   Cx2_Right_intervention (2U)
 *   Cx3_Reserved (3U)
 * EWP_Err: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_error (0U)
 *   Cx1_Error (1U)
 * EnergyInfoDataType: Enumeration of integer in interval [0...255] with enumerators
 *   TC_ENERGY_RESP (0U)
 *   TC_ENERGY_PER_1KM (1U)
 *   TC_ENERGY_DTE (2U)
 * EngClntTempVldty: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 *   Cx2_Init_value (2U)
 * EngClntTempWarn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No (0U)
 *   Cx1_Yes (1U)
 * EngSVSSig: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_SVS_off (0U)
 *   Cx1_SVS_on (1U)
 * EngSpdVldty: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_Valid (1U)
 *   Cx2_Initial_value (2U)
 *   Cx3_Reserved (3U)
 * EspFuncOffSts_mode: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_AvailableOn (0U)
 *   Cx1_Cross_country_expert_mode (1U)
 * FCTA_B_FuncSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCTA_B_temporarily_unavailable (2U)
 *   Cx3_FCTA_B_Performance_degradation (3U)
 * FCTA_Warn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning (1U)
 * FCTBTrig: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_tirggered (0U)
 *   Cx1_tirggered (1U)
 * FCW_AEB_PedFctSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_P_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_P_Performance_degradation (3U)
 * FCW_AEB_VehFctSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_V_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_V_Performance_degradation (3U)
 * FCW_Snvty_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High_sensitivity (1U)
 *   Cx2_Low_sensitivity (2U)
 *   Cx3_Reserved (3U)
 * FCW_Warn_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Latent_warning (1U)
 *   Cx2_warning_Level_1 (2U)
 *   Cx3_warning_Level_2 (3U)
 * FLTirePressIndSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Low (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_High (3U)
 *   Cx4_Not_available (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * FLTireTempSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High (1U)
 *   Cx2_Not_available (2U)
 *   Cx3_Reserved (3U)
 * FPAS_SoundIndcn_0x26D: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Tone_zero_No_warning (0U)
 *   Cx1_Tone_one_Long_beep (1U)
 *   Cx2_Tone_two_1_5_Hz (2U)
 *   Cx3_Tone_three_3Hz (3U)
 * FPAS_WorkSts_0x26D: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Enable (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failed (3U)
 * FRTirePressIndSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Low (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_High (3U)
 *   Cx4_Not_available (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * FRTireTempSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High (1U)
 *   Cx2_Not_available (2U)
 *   Cx3_Reserved (3U)
 * FrntELDLckSts: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_UnLocked (0U)
 *   Cx1_Locked (1U)
 *   Cx2_Over_Speed_Warning (2U)
 *   Cx3_Reserved (3U)
 *   Cx4_Lock_Request_Deny (4U)
 *   Cx5_Reserved (5U)
 *   CxD_Reserved (13U)
 *   CxE_Fault (14U)
 *   CxF_Invalid (15U)
 * GPF_Warning: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_GPF_is_regenerating (1U)
 *   Cx2_GPF_need_to_regenerate (2U)
 *   Cx3_Reserved (3U)
 * GenderSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Male (0U)
 *   Cx1_Female (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * GenderStsQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * GentrWarnLmpSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * GlowPlugLmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Not_available (3U)
 * HDCCtrl_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_On_active_braking (1U)
 *   Cx2_On_not_active_braking (2U)
 *   Cx3_Reserved (3U)
 * HDCCtrl_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_On_active_braking (1U)
 *   Cx2_On_not_active_braking (2U)
 *   Cx3_Reserved (3U)
 * HDCFault_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_HDC_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * HDCFault_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_HDC_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * HSM_KeyStateEnum: Enumeration of integer in interval [0...255] with enumerators
 *   KEY_OK (0U)
 *   KEY_IS_INIT (1U)
 *   KEY_IS_INVALID (2U)
 * HWA_InterSysInfoDisp_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_HWA_due_to_other_limitation (1U)
 *   Cx2_HWA_active_control_is_cancelled (2U)
 *   Cx3_Turn_off_the_turn_light (3U)
 *   Cx4_Active_confirm (4U)
 *   Cx5_Overtime_for_lane_change (5U)
 *   Cx6_lane_change_is_cancelled (6U)
 *   Cx7_HWA_temporary_unavailable (7U)
 *   Cx8_Speed_is_too_low_to_support_lane_change (8U)
 *   Cx9_HWA_need_to_restart_the_engine (9U)
 *   CxA_Take_over_request (10U)
 *   CxB_Please_Keep_Attention (11U)
 *   CxC_To_cross_the_tunnel_please_take_over_in_time (12U)
 *   CxD_Have_a_branch_road_ahead_Please_take_over_in_time (13U)
 *   CxE_Reserve (14U)
 *   CxF_Reserve (15U)
 * HWA_LaneChangeReq_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_left_satisfied (1U)
 *   Cx2_right_satisfied (2U)
 *   Cx3_left_not_satisfied (3U)
 *   Cx4_right_not_satisfied (4U)
 *   Cx5_reserved (5U)
 *   Cx7_reserved (7U)
 * HWA_LaneChange_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_left (1U)
 *   Cx2_right (2U)
 *   Cx3_reserved (3U)
 * HWA_ModDisp_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_Safstop (1U)
 *   Cx2_Passive (2U)
 *   Cx3_Ready (3U)
 *   Cx4_Active (4U)
 *   Cx5_Override (5U)
 *   Cx6_Slow_retreat (6U)
 *   Cx7_Standstill (7U)
 *   Cx8_Reserved (8U)
 *   CxE_Reserved (14U)
 *   CxF_Fault (15U)
 * HWA_SnvtySet_Resp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High_sensitivity (1U)
 *   Cx2_Low_sensitivity (2U)
 *   Cx3_Reserved (3U)
 * HWA_Warning: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning_Level_1 (1U)
 *   Cx2_Warning_Level_2 (2U)
 *   Cx3_Warning_Level_3 (3U)
 * HeadPosQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * HeadRotAngQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * HiLowBeamSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_ON (1U)
 *   Cx2_error (2U)
 *   Cx3_Reserved (3U)
 * IB_Warn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Warning_lamp_off (0U)
 *   Cx1_Warning_lamp_on (1U)
 * IFCCalibrationSts_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Calibration_Success (0U)
 *   Cx1_Calibration_In_Process (1U)
 *   Cx2_Calibration_Failed (2U)
 *   Cx3_Reserved (3U)
 * IFC_Handsoffwarn_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Level1_warning (1U)
 *   Cx2_Level2_warning (2U)
 *   Cx3_Level3_warning (3U)
 *   Cx4_Level4_warning (4U)
 *   Cx5_Level5_warning (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * IFC_LeLaneTyp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Solid_lane (1U)
 *   Cx2_Dashed_lane (2U)
 *   Cx3_Rode_edge (3U)
 *   Cx4_Reserved (4U)
 *   Cx7_Reserved (7U)
 * IFC_NextLeLaneTyp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Solid_lane (1U)
 *   Cx2_Dashed_lane (2U)
 *   Cx3_Rode_edge (3U)
 *   Cx4_Reserved (4U)
 *   Cx7_Reserved (7U)
 * IFC_NextRiLaneTyp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Solid_lane (1U)
 *   Cx2_Dashed_lane (2U)
 *   Cx3_Rode_edge (3U)
 *   Cx4_Reserved (4U)
 *   Cx7_Reserved (7U)
 * IFC_RiLaneTyp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Solid_lane (1U)
 *   Cx2_Dashed_lane (2U)
 *   Cx3_Rode_edge (3U)
 *   Cx4_Reserved (4U)
 *   Cx7_Reserved (7U)
 * ISL_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Speed_Limit_Confirm_Request (1U)
 *   Cx2_Speed_Limit_Take_Over_Request (2U)
 *   Cx3_Resvered (3U)
 * IntelligentEvaActSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Left_Eva (1U)
 *   Cx2_Right_Eva (2U)
 *   Cx3_Reserved (3U)
 * KL30BRelaySts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * LCKStsIndcr: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_indicator (0U)
 *   Cx1_Active_indicator (1U)
 *   Cx2_Passive_indicator (2U)
 *   Cx3_Reserved (3U)
 * LDW_LKAWarn_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_LDW_LKA_warning (0U)
 *   Cx1_LDW_LKA_left_warning (1U)
 *   Cx2_LDW_LKA_right_warning (2U)
 *   Cx3_Reserved (3U)
 * LDW_LKA_Snvty_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High_sensitivity (1U)
 *   Cx2_Low_sensitivity (2U)
 *   Cx3_Reserved (3U)
 * LEyeOpenSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No (0U)
 *   Cx1_Yes (1U)
 *   Cx2_Loss_left_eye (2U)
 *   Cx3_Invalid (3U)
 * LEyeOpenStsQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * LRDoorSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * LSSErrSts_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_error (0U)
 *   Cx1_LDW_error (1U)
 *   Cx2_LKA_error (2U)
 *   Cx3_LCK_error (3U)
 *   Cx4_ELK_error (4U)
 *   Cx5_ESS_error (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * LSSFuncSts_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_LDW_on (1U)
 *   Cx2_LKA_on (2U)
 *   Cx3_LCK_ON (3U)
 *   Cx4_Reserved (4U)
 *   Cx7_Reserved (7U)
 * LSSIntervention_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning_and_Intervention (0U)
 *   Cx1_Left_warning (1U)
 *   Cx2_Right_warning (2U)
 *   Cx3_Left_Intervention (3U)
 *   Cx4_Right_Intervention (4U)
 *   Cx5_Both_Intervention (5U)
 *   Cx6_Left_warn_only_reminder (6U)
 *   Cx7_Right_warn_only_reminder (7U)
 * LSSWarnFormResp_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Voice (0U)
 *   Cx1_Haptic (1U)
 *   Cx2_Voice_Haptic (2U)
 *   Cx3_Reserved (3U)
 * LTurnLmpFailSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Short_circuit (1U)
 *   Cx2_Open_circuit (2U)
 *   Cx3_Reserved (3U)
 * LaneAvailability_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_Avaliable (0U)
 *   Cx1_Left_Lane_Marker_Available (1U)
 *   Cx2_Right_Lane_Marker_Available (2U)
 *   Cx3_Both_Lane_Markers_Available (3U)
 * Longctrl_HazActv: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_AEB_active (1U)
 *   Cx2_Safestop_active (2U)
 *   Cx3_Reserved (3U)
 * Longctrl_ModSts_DVR: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Passive_mode_Reject_ (1U)
 *   Cx2_Passive_mode_Stand_by_ (2U)
 *   Cx3_Active_Control_mode (3U)
 *   Cx4_Brake_only_mode (4U)
 *   Cx5_Override (5U)
 *   Cx6_Standstill (6U)
 *   Cx7_Failure_mode_Longctrl (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Shut_off (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * Longctrl_ParkShiftReq_DVR: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_request (0U)
 *   Cx1_Request_park_Shift (1U)
 *   Cx2_Invalid (2U)
 *   Cx3_Reserved (3U)
 * LvPwrSysErr: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_error (0U)
 *   Cx1_error (1U)
 *   Cx2_Reservrd (2U)
 *   Cx3_Reservrd (3U)
 * MILSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * PASWorkCmd: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 * PassSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * PassengerDoorSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * PowerRlyFault: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_ACCIGN1IGN2_Relay_failure_ACC_Reserved_ (1U)
 * REyeOpenSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No (0U)
 *   Cx1_Yes (1U)
 *   Cx2_Loss_right_eye (2U)
 *   Cx3_Invalid (3U)
 * REyeOpenStsQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * RLSFailSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 * RLTirePressIndSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Low (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_High (3U)
 *   Cx4_Not_available (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * RLTireTempSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High (1U)
 *   Cx2_Not_available (2U)
 *   Cx3_Reserved (3U)
 * RPAS_SoundIndcn_0x26E: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Tone_0_No_warning (0U)
 *   Cx1_Tone_1_Long_beep (1U)
 *   Cx2_Tone_2_1_5_Hz (2U)
 *   Cx3_Tone_3_3Hz (3U)
 * RPAS_WorkSts_0x26E: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Enable (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failed (3U)
 * RRDoorSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * RRTirePressIndSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Low (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_High (3U)
 *   Cx4_Not_available (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * RRTireTempSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High (1U)
 *   Cx2_Not_available (2U)
 *   Cx3_Reserved (3U)
 * RSDS_BliSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Blindness (0U)
 *   Cx1_Blindness (1U)
 * RSDS_BrkgTrig: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_tirggered (0U)
 *   Cx1_Triggered (1U)
 * RSDS_CTA_Actv: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_Active (1U)
 * RSDS_ErrSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Error (0U)
 *   Cx1_Error (1U)
 * RSDS_IPSoundReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_level_1_2Hz_ (1U)
 *   Cx2_Warning_level_2_4Hz_ (2U)
 *   Cx3_Warning_level_3_ (3U)
 * RSDS_LCAResp: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 * RSDS_RCW_Trigger: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_RCW_level_1 (1U)
 *   Cx2_RCW_level_2 (2U)
 *   Cx3_Reserved (3U)
 * RSDS_TrailerSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Trailer (1U)
 * RTurnLmpFailSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Short_circuit (1U)
 *   Cx2_Open_circuit (2U)
 *   Cx3_Reserved (3U)
 * RearELDLckSts: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_UnLocked (0U)
 *   Cx1_Locked (1U)
 *   Cx2_Over_Speed_Warning (2U)
 *   Cx3_Driving_Mode_Select_Error (3U)
 *   Cx4_Lock_Request_Deny (4U)
 *   Cx5_Reserved (5U)
 *   CxD_Reserved (13U)
 *   CxE_Fault (14U)
 *   CxF_Invalid (15U)
 * RemoteModSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_mode (0U)
 *   Cx1_Remote_mode (1U)
 * Request_driveoff: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_no_request (0U)
 *   Cx1_The_front_car_has_started (1U)
 *   Cx2_The_front_car_has_started_Please_pay_attention_to_the_road_environment_ahead (2U)
 *   Cx3_The_front_car_has_started_please_keep_your_attention (3U)
 *   Cx4_The_front_car_has_started_please_take_over_the_car (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * RobustGazeAngQlty: Enumeration of integer in interval [0...127] with enumerators
 *   Cx00_Valid_value (0U)
 *   Cx64_Valid_value (100U)
 *   Cx65_Reserved (101U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Invalid (127U)
 * RollingCounter_ABM1_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ABS3_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC4_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC8_5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_AEB2_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_AEB3_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPB1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPS1_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPS1_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP1_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP2_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP2_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IFC3_1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IFC4_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IFC5_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IFC6: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RotSteerWheel: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Warning (1U)
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
 *   SYSTEMSTATE_IVI_AWAKEHOLD (6U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (11U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (8U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (9U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (10U)
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
 * SCRSysWarnDisplay: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_No_warn_ (0U)
 *   Cx1_Urea_level_low_ (1U)
 *   Cx2_Urea_level_tool_low_ (2U)
 *   Cx3_Empty_tank_next_start_prohibit_ (3U)
 *   Cx4_Incorrect_urea_ (4U)
 *   Cx5_Incorrect_urea_over_limit_dist_50km (5U)
 *   Cx6_Urea_fill_intercept_please_refill_ (6U)
 *   Cx7_Urea_fill_intercept_over_limit_dist_50km (7U)
 *   Cx8_Engine_start_prohibit_ (8U)
 *   Cx9_SCR_system_fault_please_check_ (9U)
 *   CxA_SCR_system_fault_over_limit_Dist_50km (10U)
 *   CxB_Driving_dist_over_limition_with_fault_next_start_prohibit_ (11U)
 *   CxC_Reserved (12U)
 *   CxF_Reserved (15U)
 * SDWActiveSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_Active (1U)
 * SDW_SoundIndcn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Tone_0_No_warning (0U)
 *   Cx1_Tone_1_Long_beep (1U)
 *   Cx2_Tone_2_1_5_Hz (2U)
 *   Cx3_Tone_3_3Hz (3U)
 * SS_Enable_Lamp: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 * SS_Fault_Lamp: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 * SecRowLSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * SecRowMidSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * SecRowRSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * ShiftRecommend_M: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Recommendation (0U)
 *   Cx1_Up_Shift (1U)
 *   Cx2_Down_Shift (2U)
 *   Cx3_Reserved (3U)
 * Stat_PwrSv_Lvl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Level_1 (1U)
 *   Cx2_Level_2 (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * SteerCorrnRmn_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Tip (0U)
 *   Cx1_Tip_return_finish (1U)
 *   Cx2_Tip_return_R (2U)
 *   Cx3_Tip_return_L (3U)
 * SteerCorrnRmn_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Tip (0U)
 *   Cx1_Tip_return_finish (1U)
 *   Cx2_Tip_return_R (2U)
 *   Cx3_Tip_return_L (3U)
 * SysPowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ACC_reserved_ (1U)
 *   Cx2_ON (2U)
 *   Cx3_Crank (3U)
 * TAB_Sts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Function_OFF (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failure (3U)
 * TAB_Sts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Function_OFF (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failure (3U)
 * TCU_Shift_not_allowed_Warn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
 *   Cx2_Reversed (2U)
 *   Cx3_Reversed (3U)
 * TGS_LEVER: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Select_lever_in_position_P_ (0U)
 *   Cx1_Reserved (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Select_lever_in_position_D_ (5U)
 *   Cx6_Select_lever_in_position_N_ (6U)
 *   Cx7_Select_lever_in_position_R_ (7U)
 *   Cx8_Select_lever_in_position_M_ (8U)
 *   Cx9_Reserved (9U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * TJA_ACC_SelSts_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_off (0U)
 *   Cx1_ACC_selected (1U)
 *   Cx2_TJAICA_selected (2U)
 *   Cx3_Off_selected (3U)
 *   Cx4_ACC_on (4U)
 *   Cx5_TJAICA_on (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * TJA_FollowSts_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Follow (0U)
 *   Cx1_Follow_Vehicle (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * TJA_ICA_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_TJAICA_due_to_other_limitation (1U)
 *   Cx2_TJAICA_active_control_is_cancelled (2U)
 *   Cx3_TJAICA_temporarily_unavailable (3U)
 *   Cx4_Current_IGN_Cycle_Function_Inhibit (4U)
 *   Cx5_Resvered (5U)
 *   Cx7_Resvered (7U)
 * TJA_ICA_ModDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Passive_mode (1U)
 *   Cx2_Active_mode (2U)
 *   Cx3_Ready_mode (3U)
 *   Cx4_Failure (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * TSRSpdLim: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_No_Display (0U)
 *   Cx01_SPL_5 (1U)
 *   Cx02_SPL_10 (2U)
 *   Cx03_SPL_15 (3U)
 *   Cx04_SPL_20 (4U)
 *   Cx05_SPL_25 (5U)
 *   Cx06_SPL_30 (6U)
 *   Cx07_SPL_35 (7U)
 *   Cx08_SPL_40 (8U)
 *   Cx09_SPL_45 (9U)
 *   Cx0A_SPL_50 (10U)
 *   Cx0B_SPL_55 (11U)
 *   Cx0C_SPL_60 (12U)
 *   Cx0D_SPL_65 (13U)
 *   Cx0E_SPL_70 (14U)
 *   Cx0F_SPL_75 (15U)
 *   Cx10_SPL_80 (16U)
 *   Cx11_SPL_85 (17U)
 *   Cx12_SPL_90 (18U)
 *   Cx13_SPL_95 (19U)
 *   Cx14_SPL_100 (20U)
 *   Cx15_SPL_105 (21U)
 *   Cx16_SPL_110 (22U)
 *   Cx17_SPL_115 (23U)
 *   Cx18_SPL_120 (24U)
 *   Cx19_SPL_125 (25U)
 *   Cx1A_SPL_130 (26U)
 *   Cx1B_SPL_135 (27U)
 *   Cx1C_SPL_140 (28U)
 *   Cx1D_SPL_145 (29U)
 *   Cx1E_SPL_150 (30U)
 *   Cx1F_Reserved (31U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Invalid (63U)
 * TSRSpdLimCfdc: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Null (0U)
 *   Cx1_Implicit (1U)
 *   Cx2_Explicit (2U)
 *   Cx3_Reserved (3U)
 * TSRSpdLimSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Speed_Limit (0U)
 *   Cx1_Speed_Limit (1U)
 *   Cx2_Speed_Limit_Cancel (2U)
 *   Cx3_Reserved (3U)
 * TSRSpdLimWarn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning (1U)
 * TSRSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fusion_mode (1U)
 *   Cx2_Vision_mode (2U)
 *   Cx3_Navigation_only_mode (3U)
 *   Cx4_Failed (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * TSRTrfcSignVal: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_None (0U)
 *   Cx01_Snow (1U)
 *   Cx02_Fog (2U)
 *   Cx03_ThunderStorm (3U)
 *   Cx04_Rain (4U)
 *   Cx05_FWay (5U)
 *   Cx06_EFWay (6U)
 *   Cx07_Straight (7U)
 *   Cx08_FrontageLeft (8U)
 *   Cx09_TurnLeftRight (9U)
 *   Cx0A_FrontageRight (10U)
 *   Cx0B_Right (11U)
 *   Cx0C_TurnRight (12U)
 *   Cx0D_Left (13U)
 *   Cx0E_TurnLeft (14U)
 *   Cx0F_RelieveNoOvertake (15U)
 *   Cx10_NoOvertake (16U)
 *   Cx11_StopGiveWay (17U)
 *   Cx12_GiveWay (18U)
 *   Cx13_NoPass (19U)
 *   Cx14_NoEntry (20U)
 *   Cx15_NoCar (21U)
 *   Cx16_NoTruck (22U)
 *   Cx17_NoBus (23U)
 *   Cx18_NoTurnaround (24U)
 *   Cx19_NoStraightLeftTurn (25U)
 *   Cx1A_NoStraightRightTurn (26U)
 *   Cx1B_NoLeftRightTurn (27U)
 *   Cx1C_NoLeftTurn (28U)
 *   Cx1D_NoRightTurn (29U)
 *   Cx1E_NoStraight (30U)
 *   Cx1F_WarnKids (31U)
 *   Cx20_WarnPed (32U)
 *   Cx21_WarnBike (33U)
 *   Cx22_WarnWorks (34U)
 *   Cx23_WarnWildanimal (35U)
 *   Cx24_WarnCattle (36U)
 *   Cx25_ACCidentProneSection (37U)
 *   Cx26_Town (38U)
 *   Cx27_Slow (39U)
 *   Cx28_SharpTurnR (40U)
 *   Cx29_SharpTurnL (41U)
 *   Cx2A_ReverseCurveL (42U)
 *   Cx2B_ReverseCurveR (43U)
 *   Cx2C_ContinuousBend (44U)
 *   Cx2D_Crossroads (45U)
 *   Cx2E_ConfluenceR (46U)
 *   Cx2F_ConfluenceL (47U)
 *   Cx30_RainWetness (48U)
 *   Cx31_SnowIcy (49U)
 *   Cx32_Time (50U)
 *   Cx33_Distance_For (51U)
 *   Cx34_Distance_In (52U)
 *   Cx35_Straight (53U)
 *   Cx36_FrontageLeft (54U)
 *   Cx37_TurnLeftRight (55U)
 *   Cx38_FrontageRight (56U)
 *   Cx39_Right (57U)
 *   Cx3A_Turn_Right (58U)
 *   Cx3B_Left (59U)
 *   Cx3C_Turn_Left (60U)
 *   Cx3D_Highway_Start (61U)
 *   Cx3E_Highway_End (62U)
 *   Cx3F_Mortorway_Start (63U)
 *   Cx40_Mortorway_End (64U)
 *   Cx41_City_Entry (65U)
 *   Cx42_City_Exit (66U)
 *   Cx43_Residential_zones_Entry (67U)
 *   Cx44_Residential_zones_Exit (68U)
 *   Cx45_Trailer (69U)
 *   Cx46_Reserved (70U)
 *   CxFE_Reserved (254U)
 *   CxFF_Invalid (255U)
 * T_BOX_SWUpdSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Idle (0U)
 *   Cx1_NAD_start_update (1U)
 *   Cx2_NAD_update_inprogress (2U)
 *   Cx3_NAD_update_done (3U)
 *   Cx4_NAD_update_failed (4U)
 *   Cx5_MCU_start_update (5U)
 *   Cx6_MCU_update_done (6U)
 *   Cx7_Reserved (7U)
 * T_BOX_SysErrSts: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_No_error (0U)
 *   Cx01_Error (1U)
 *   Cx02_Standby_Battery_Error (2U)
 *   Cx03_Reserved (3U)
 *   Cx1F_Reserved (31U)
 * TgtEngSpdIPValid: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Invalid (0U)
 *   Cx1_valid (1U)
 * TirePressSysFailrIndcn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * TrailerSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Trailer_off (0U)
 *   Cx1_Trailer_on (1U)
 * TranPMode_Sts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_Mode (0U)
 *   Cx1_Transport_Mode (1U)
 * TrsmStNID_0x236: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Break_down_powerflow (1U)
 *   Cx2_CSN_or_NUN_active (2U)
 *   Cx3_Geneate_power_flow (3U)
 *   Cx4_Reserve (4U)
 *   Cx7_Reserve (7U)
 * TrsmStNID_0xc6: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Break_down_powerflow (1U)
 *   Cx2_CSN_or_NUN_active (2U)
 *   Cx3_Geneate_power_flow (3U)
 *   Cx4_Reserve (4U)
 *   Cx7_Reserve (7U)
 * TrunkSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * UreaLampCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 *   Cx2_Flsah (2U)
 *   Cx3_Reserved (3U)
 * UreaRemainDist: Enumeration of integer in interval [0...4095] with enumerators
 *   Cx000_Valid_value (0U)
 *   CxFFF_Valid_value (4095U)
 * VehOdoInfo_0x137: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 * VehOdoInfo_0x265: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 * WIFFullLmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Not_available (3U)
 * WIFSensorFailSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Not_available (3U)
 * WPC_FaultSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Fault (0U)
 *   Cx1_Foreign_Object_Detection_FOD (1U)
 *   Cx2_Over_Voltage_Protection_OVP (2U)
 *   Cx3_Low_Voltage_Protection_LVP (3U)
 *   Cx4_Over_Temperature_Protection_OTP (4U)
 *   Cx5_System_Fault (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * WPC_PhoneReminder: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_need_to_remind (0U)
 *   Cx1_Remind_forgotten_phone (1U)
 * WarnEngStrtNotMeet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning (1U)
 * WarnKeyInCarWhenExit: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning (1U)
 * WarnPowerNotInOffPosn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning (1U)
 * WarnVldKeyNotFound: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning (1U)
 *
 * Array Types:
 * ============
 * A_16Bytes: Array with 16 element(s) of type uint8
 * A_17Bytes: Array with 17 element(s) of type uint8
 * A_ODO_data_u8_16: Array with 16 element(s) of type uint8
 * CconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * Csm_DecryptDataType_CsmPrimitives_AES128_Decrypt: Array with 16 element(s) of type uint8
 * Csm_DecryptResultType_CsmPrimitives_AES128_Decrypt: Array with 16 element(s) of type uint8
 * Csm_EncryptDataType_CsmPrimitives_AES128_Encrypt: Array with 16 element(s) of type uint8
 * Csm_EncryptResultType_CsmPrimitives_AES128_Encrypt: Array with 16 element(s) of type uint8
 * Diag_9Bytes: Array with 9 element(s) of type uint8
 * ECM_VIN: Array with 8 element(s) of type uint8
 * EOL_6Bytes: Array with 6 element(s) of type Rte_DT_EOL_6Bytes_0
 * IdtHsmKeyArray: Array with 16 element(s) of type uint8
 * IdtHsmVinArray: Array with 16 element(s) of type uint8
 * NVMBlockMaintain_Type: Array with 80 element(s) of type Rte_DT_NVMBlockMaintain_Type_0
 * NVMBlockTCConfig_Type: Array with 60 element(s) of type Rte_DT_NVMBlockTCConfig_Type_0
 * NVMBlockTC_Type: Array with 60 element(s) of type Rte_DT_NVMBlockTC_Type_0
 * NVMBlockTrip: Array with 20 element(s) of type Rte_DT_NVMBlockTrip_0
 * NVMMenuData_A20: Array with 20 element(s) of type uint8
 * Rte_DT_DM_tstDrvModStatusRecord_1: Array with 15 element(s) of type uint8
 * Rte_DT_EOL_6Bytes_0: Array with 1 element(s) of type uint8
 * Rte_DT_WN_WarningStsOutput_0: Array with 150 element(s) of type uint8
 * Rte_DT_s_OdoRteGetParament_t_2: Array with 3 element(s) of type uint32
 * Rte_DT_s_OdoRteGetParament_t_3: Array with 3 element(s) of type uint32
 * VconfigKind_Allbuffers: Array with 600 element(s) of type uint8
 *
 * Record Types:
 * =============
 * AVASDTCRet: Record with elements
 *   Open of type Rte_DT_AVASDTCRet_0
 *   ShortAcross of type Rte_DT_AVASDTCRet_1
 *   ShorttoGND of type Rte_DT_AVASDTCRet_2
 *   Clip of type Rte_DT_AVASDTCRet_3
 *   OutofRange of type Rte_DT_AVASDTCRet_4
 *   ShorttoBAT of type Rte_DT_AVASDTCRet_5
 * CanFrameCounterType: Record with elements
 *   Counter of type uint16
 *   Data of type uint16
 * DM_tstDrvModStatusRecord: Record with elements
 *   TelltaleStatus of type uint8
 *   WarningStatus of type Rte_DT_DM_tstDrvModStatusRecord_1
 *   WarningPreStatus of type uint8
 *   WarningNextStatus of type uint8
 * DateTimeType_t: Record with elements
 *   u16Year of type uint16
 *   u8Month of type uint8
 *   u8Day of type uint8
 *   u8Hour of type uint8
 *   u8Minutes of type uint8
 *   u8Seconds of type uint8
 *   u8TimeMode of type uint8
 * EnergyInfoIdDataType: Record with elements
 *   ModuleId of type uint32
 *   ClientId of type uint32
 * FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE: Record with elements
 *   Fuel_Fast_Fill_Status of type uint8
 *   Fuel_Fast_Fill_Status_Aux of type uint8
 *   Fuel_Init_Complete_Status of type uint8
 *   Fuel_Init_Complete_Status_Aux of type uint8
 *   Fuel_Level_Display_Percent of type uint16
 *   Fuel_Level_Display_Percent_Aux of type uint16
 *   Fuel_Level_Display_Segment of type uint8
 *   Fuel_Warning_Status_Aux of type uint8
 *   Fuel_Warning_Status of type uint8
 *   Fuel_Sensor_Error_Status_Aux of type uint8
 *   Fuel_Sensor_Error_Status of type uint8
 *   Fuel_Level_Display_Value of type uint32
 *   Fuel_Level_Display_Value_Aux of type uint32
 *   Fuel_Level_Calculate_Value of type uint16
 *   Fuel_Level_Calculate_Value_Aux of type uint16
 *   Fuel_Sensor_Raw_Value_A of type uint16
 *   Fuel_Sensor_Raw_Value_B of type uint16
 *   Fuel_Sensor_Switch of type uint8
 * MenuSetData_t: Record with elements
 *   NaviLimitSpeed of type Rte_DT_MenuSetData_t_0
 *   OverSpeedEnable of type Rte_DT_MenuSetData_t_1
 *   Language of type Rte_DT_MenuSetData_t_2
 *   ClusterTheme of type Rte_DT_MenuSetData_t_3
 *   OdometerUnit of type Rte_DT_MenuSetData_t_4
 *   TemperatureUnit of type Rte_DT_MenuSetData_t_5
 *   TirePressureUnit of type Rte_DT_MenuSetData_t_6
 *   TripComputerId of type Rte_DT_MenuSetData_t_7
 *   InteractiveCarId of type Rte_DT_MenuSetData_t_8
 *   DrivingModeMemorySwitch of type Rte_DT_MenuSetData_t_9
 *   TimeUnit of type Rte_DT_MenuSetData_t_10
 *   HighwayAssistSwitch of type Rte_DT_MenuSetData_t_11
 *   LaneChangeAssistSwitch of type Rte_DT_MenuSetData_t_12
 *   Cluster_Sunrise_Sunset_Mode of type uint8
 *   Cluster_Auto_Mode of type uint8
 *   DrvgModeMemReq of type uint8
 *   DrvingModReq_HUT of type uint8
 *   DataSyncFlag of type Rte_DT_MenuSetData_t_17
 *   AtmosphereLampLinkageSwt_Sts of type uint8
 *   SimSoundWaveLinkageSwt_Sts of type uint8
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SG_ABM1: Record with elements
 *   AirbFailLmpCmd of type AirbFailLmpCmd_4
 *   CheckSum_ABM1 of type CheckSum_ABM1_4
 *   DrvSBR of type DrvSBR_4
 *   DrvSBR_Visual of type DrvSBR_Visual_4
 *   PassSBR of type PassSBR_4
 *   PassSBR_Visual of type PassSBR_Visual_4
 *   RollingCounter_ABM1 of type RollingCounter_ABM1_4
 *   SecRowLSBR of type SecRowLSBR_4
 *   SecRowLSBR_Visual of type SecRowLSBR_Visual_4
 *   SecRowMidSBR of type SecRowMidSBR_4
 *   SecRowMidSBR_Visual of type SecRowMidSBR_Visual_4
 *   SecRowRSBR of type SecRowRSBR_4
 *   SecRowRSBR_Visual of type SecRowRSBR_Visual_4
 *   CrashOutputSts of type CrashOutputSts
 *   dummy_ABM1_0 of type dummy_ABM1_0
 *   dummy_ABM1_1 of type dummy_ABM1_1
 *   dummy_ABM1_2 of type dummy_ABM1_2
 *   dummy_ABM1_3 of type dummy_ABM1_3
 *   dummy_ABM1_4 of type dummy_ABM1_4
 *   dummy_ABM1_5 of type dummy_ABM1_5
 * SG_ABS3: Record with elements
 *   ABSActv_0x265 of type ABSActv_0x265
 *   ABSFailSts_0x265 of type ABSFailSts_0x265
 *   CheckSum_ABS3_0x265 of type CheckSum_ABS3_0x265
 *   dummy_ABS3_0 of type dummy_ABS3_0
 *   dummy_ABS3_1 of type dummy_ABS3_1
 *   dummy_ABS3_2 of type dummy_ABS3_2
 *   dummy_ABS3_3 of type dummy_ABS3_3
 *   EBDFailSts_0x265 of type EBDFailSts_0x265
 *   RollingCounter_ABS3_0x265 of type RollingCounter_ABS3_0x265
 *   VehOdoInfo_0x265 of type VehOdoInfo_0x265
 *   VehOdoInfoSts_0x265 of type VehOdoInfoSts_0x265
 *   VehSpd_0x265 of type VehSpd_0x265
 *   VehSpdVld_0x265 of type VehSpdVld_0x265
 * SG_ABS3_ESP_FD2: Record with elements
 *   ABSActv_0x137 of type ABSActv_0x137
 *   ABSFailSts_0x137 of type ABSFailSts_0x137
 *   CheckSum_ABS3_0x137 of type CheckSum_ABS3_0x137
 *   dummy_ESP_FD2_39 of type dummy_ESP_FD2_41
 *   dummy_ESP_FD2_40 of type dummy_ESP_FD2_42
 *   EBDFailSts_0x137 of type EBDFailSts_0x137
 *   RollingCounter_ABS3_0x137 of type RollingCounter_ABS3_0x137
 *   VehOdoInfo_0x137 of type VehOdoInfo_0x137
 *   VehOdoInfoSts_0x137 of type VehOdoInfoSts_0x137
 *   VehSpd_0x137 of type VehSpd_0x137_2
 *   VehSpdVld_0x137 of type VehSpdVld_0x137
 *   dummy_ESP_FD2_41 of type dummy_ESP_FD2_43
 *   dummy_ESP_FD2_42 of type dummy_ESP_FD2_44
 * SG_ACC3_ACC_FD2: Record with elements
 *   ALC_InterSysInfoDisp of type ALC_InterSysInfoDisp
 *   ALC_Resp of type ALC_Resp
 *   Checksum_ACC3 of type Checksum_ACC3
 *   HWA_Resp of type HWA_Resp
 *   HWA_SnvtySet_Resp of type HWA_SnvtySet_Resp
 *   ICA_HandsOffResp of type ICA_HandsOffResp
 *   ISL_Resp of type ISL_Resp
 *   Longctrl_Decel_Req_DVR of type Longctrl_Decel_Req_DVR
 *   Longctrl_Decel_ReqValue_DVR of type Longctrl_Decel_ReqValue_DVR_2
 *   Longctrl_DecelToStopReq_DVR of type Longctrl_DecelToStopReq_DVR
 *   Longctrl_DrvOFF_Req_DVR of type Longctrl_DrvOFF_Req_DVR
 *   Longctrl_EngTrqReq_DVR of type Longctrl_EngTrqReq_DVR_2
 *   Longctrl_EngTrqReqActive_DVR of type Longctrl_EngTrqReqActive_DVR
 *   Longctrl_ModSts_DVR of type Longctrl_ModSts_DVR
 *   Longctrl_ParkShiftReq_DVR of type Longctrl_ParkShiftReq_DVR
 *   Longctrl_VehHldReq_DVR of type Longctrl_VehHldReq_DVR
 *   RollingCounter_ACC3 of type RollingCounter_ACC3
 *   dummy_ACC_FD2_4 of type dummy_ACC_FD2_33
 *   dummy_ACC_FD2_5 of type dummy_ACC_FD2_34
 *   dummy_ACC_FD2_6 of type dummy_ACC_FD2_35
 *   dummy_ACC_FD2_7 of type dummy_ACC_FD2_36
 * SG_ACC4_ACC_FD2: Record with elements
 *   ACC_FctSts of type ACC_FctSts_4
 *   ACC_InterSysInfoDisp of type ACC_InterSysInfoDisp_4
 *   ACC_ModDisp of type ACC_ModDisp_4
 *   ACC_ObjDetecte of type ACC_ObjDetecte_4
 *   ACC_SpdSetValue of type ACC_SpdSetValue_4
 *   ACC_TakeOverReq of type ACC_TakeOverReq_4
 *   ACC_TgtObjBarDisp of type ACC_TgtObjBarDisp_4
 *   ACC_TimeGapSet of type ACC_TimeGapSet_4
 *   Checksum_ACC4 of type Checksum_ACC4_4
 *   ISL_InterSysInfoDisp of type ISL_InterSysInfoDisp_4
 *   RollingCounter_ACC4 of type RollingCounter_ACC4_4
 *   TJA_ACC_SelSts of type TJA_ACC_SelSts_4
 *   TJA_ICA_InterSysInfoDisp of type TJA_ICA_InterSysInfoDisp_4
 *   TJA_ICA_ModDisp of type TJA_ICA_ModDisp_4
 *   CruCha_ModDisp of type CruCha_ModDisp
 *   CruChar_InterSysInfoDisp of type CruChar_InterSysInfoDisp
 *   Longctrl_HazActv of type Longctrl_HazActv
 *   dummy_ACC_FD2_8 of type dummy_ACC_FD2_16
 *   dummy_ACC_FD2_9 of type dummy_ACC_FD2_17
 *   dummy_ACC_FD2_10 of type dummy_ACC_FD2_18
 * SG_ACC7_ACC_FD2: Record with elements
 *   ACC_LeTargrtDection of type ACC_LeTargrtDection
 *   ACC_LeTgtDx of type ACC_LeTgtDx_2
 *   ACC_LeTgtDy of type ACC_LeTgtDy_2
 *   ACC_LeTgtTyp of type ACC_LeTgtTyp
 *   ACC_RiTargrtDetn of type ACC_RiTargrtDetn
 *   ACC_RiTgtDx of type ACC_RiTgtDx_2
 *   ACC_RiTgtDy of type ACC_RiTgtDy_2
 *   ACC_RiTgtTyp of type ACC_RiTgtTyp
 *   Checksum_ACC7 of type Checksum_ACC7
 *   Request_driveoff of type Request_driveoff
 *   RollingCounter_ACC7 of type RollingCounter_ACC7
 *   dummy_ACC_FD2_21 of type dummy_ACC_FD2_24
 *   dummy_ACC_FD2_22 of type dummy_ACC_FD2_25
 * SG_ACC8_ACC_FD2: Record with elements
 *   Checksum_ACC8 of type Checksum_ACC8_5
 *   HWA_InterSysInfoDisp of type HWA_InterSysInfoDisp_5
 *   HWA_LaneChange of type HWA_LaneChange_5
 *   HWA_LaneChangeReq of type HWA_LaneChangeReq_5
 *   HWA_ModDisp of type HWA_ModDisp_5
 *   RollingCounter_ACC8 of type RollingCounter_ACC8_5
 *   dummy_ACC_FD2_11 of type dummy_ACC_FD2_44
 *   dummy_ACC_FD2_12 of type dummy_ACC_FD2_45
 *   dummy_ACC_FD2_13 of type dummy_ACC_FD2_46
 *   dummy_ACC_FD2_14 of type dummy_ACC_FD2_47
 *   dummy_ACC_FD2_15 of type dummy_ACC_FD2_48
 *   dummy_ACC_FD2_16 of type dummy_ACC_FD2_49
 *   dummy_ACC_FD2_17 of type dummy_ACC_FD2_50
 *   HWA_Warning of type HWA_Warning
 * SG_AEB2_AEB_FD2: Record with elements
 *   AEB_JA_Resp of type AEB_JA_Resp_3
 *   AEB_PedResp of type AEB_PedResp_3
 *   AEB_VehResp of type AEB_VehResp_3
 *   Checksum_AEB2 of type Checksum_AEB2_3
 *   FCW_Snvty of type FCW_Snvty_3
 *   RollingCounter_AEB2 of type RollingCounter_AEB2_3
 *   dummy_AEB_FD2_8 of type dummy_AEB_FD2_22
 *   dummy_AEB_FD2_9 of type dummy_AEB_FD2_23
 *   dummy_AEB_FD2_10 of type dummy_AEB_FD2_24
 *   dummy_AEB_FD2_11 of type dummy_AEB_FD2_25
 *   dummy_AEB_FD2_12 of type dummy_AEB_FD2_26
 *   dummy_AEB_FD2_13 of type dummy_AEB_FD2_27
 *   dummy_AEB_FD2_14 of type dummy_AEB_FD2_28
 * SG_AEB3_AEB_FD2: Record with elements
 *   AEB_JA_Warn of type AEB_JA_Warn_2
 *   AEB_JABrkTrig of type AEB_JABrkTrig_2
 *   AEB_JAFuncSts of type AEB_JAFuncSts_2
 *   AEB_PedTrig of type AEB_PedTrig_2
 *   AEB_VehTrig of type AEB_VehTrig_2
 *   Checksum_AEB3 of type Checksum_AEB3_2
 *   FCW_AEB_PedFctSts of type FCW_AEB_PedFctSts_2
 *   FCW_AEB_VehFctSts of type FCW_AEB_VehFctSts_2
 *   FCW_Warn of type FCW_Warn_2
 *   RollingCounter_AEB3 of type RollingCounter_AEB3_2
 *   dummy_AEB_FD2_15 of type dummy_AEB_FD2_29
 *   dummy_AEB_FD2_16 of type dummy_AEB_FD2_30
 *   dummy_AEB_FD2_17 of type dummy_AEB_FD2_31
 *   dummy_AEB_FD2_18 of type dummy_AEB_FD2_32
 *   dummy_AEB_FD2_19 of type dummy_AEB_FD2_33
 *   dummy_AEB_FD2_20 of type dummy_AEB_FD2_34
 *   dummy_AEB_FD2_21 of type dummy_AEB_FD2_35
 * SG_DCT_FD4: Record with elements
 *   CheckSum_DCT7 of type CheckSum_DCT7
 *   DCT_PrsBrk_Warn of type DCT_PrsBrk_Warn
 *   DCT_RaceModeSts of type DCT_RaceModeSts
 *   DCT_ShftNotAlwd_Warn of type DCT_ShftNotAlwd_Warn
 *   DCT_ShftRecom_M of type DCT_ShftRecom_M
 *   DrvAutoGearDisp of type DrvAutoGearDisp
 *   DrvFaiMsg of type DrvFaiMsg
 *   DrvGearDispSts of type DrvGearDispSts
 *   DrvModDisp_0x236 of type DrvModDisp_0x236
 *   DrvModDispSts of type DrvModDispSts
 *   DrvWarnMsg of type DrvWarnMsg
 *   dummy_DCT_FD4_8 of type dummy_DCT_FD4_8
 *   dummy_DCT_FD4_9 of type dummy_DCT_FD4_9
 *   dummy_DCT_FD4_10 of type dummy_DCT_FD4_10
 *   dummy_DCT_FD4_11 of type dummy_DCT_FD4_11
 *   RollingCounter_DCT7 of type RollingCounter_DCT7
 *   TRANS_OIL_TEMP_0x236 of type TRANS_OIL_TEMP_0x236
 *   TrsmStNID_0x236 of type TrsmStNID_0x236
 * SG_EPB1: Record with elements
 *   CheckSum_EPB1 of type CheckSum_EPB1
 *   EPBErrSts of type EPBErrSts
 *   EPBRedLmpSts of type EPBRedLmpSts
 *   EPBSts of type EPBSts
 *   EPBTextDisp of type EPBTextDisp
 *   PressBrakePedalPointOut of type PressBrakePedalPointOut
 *   RollingCounter_EPB1 of type RollingCounter_EPB1
 *   dummy_EPB1_0 of type dummy_EPB1_0
 *   dummy_EPB1_1 of type dummy_EPB1_1
 *   dummy_EPB1_2 of type dummy_EPB1_2
 *   dummy_EPB1_3 of type dummy_EPB1_3
 *   dummy_EPB1_4 of type dummy_EPB1_4
 *   dummy_EPB1_5 of type dummy_EPB1_5
 *   dummy_EPB1_6 of type dummy_EPB1_6
 *   dummy_EPB1_7 of type dummy_EPB1_7
 * SG_EPS1: Record with elements
 *   CheckSum_EPS1_0x168 of type CheckSum_EPS1_0x168
 *   dummy_EPS1_0 of type dummy_EPS1_8
 *   dummy_EPS1_1 of type dummy_EPS1_9
 *   dummy_EPS1_2 of type dummy_EPS1_10
 *   dummy_EPS1_3 of type dummy_EPS1_11
 *   dummy_EPS1_4 of type dummy_EPS1_12
 *   dummy_EPS1_5 of type dummy_EPS1_13
 *   dummy_EPS1_6 of type dummy_EPS1_14
 *   dummy_EPS1_7 of type dummy_EPS1_15
 *   EPS_FailSts_0x168 of type EPS_FailSts_0x168
 *   EPS_SteerMod_0x168 of type EPS_SteerMod_0x168
 *   RollingCounter_EPS1_0x168 of type RollingCounter_EPS1_0x168
 *   SteerCorrnResp_0x168 of type SteerCorrnResp_0x168
 *   SteerCorrnRmn_0x168 of type SteerCorrnRmn_0x168
 * SG_EPS1_FD1: Record with elements
 *   CheckSum_EPS1_0x147 of type CheckSum_EPS1_0x147
 *   dummy_EPS_FD1_0 of type dummy_EPS_FD1_24
 *   dummy_EPS_FD1_1 of type dummy_EPS_FD1_25
 *   dummy_EPS_FD1_2 of type dummy_EPS_FD1_26
 *   dummy_EPS_FD1_3 of type dummy_EPS_FD1_27
 *   dummy_EPS_FD1_4 of type dummy_EPS_FD1_28
 *   dummy_EPS_FD1_5 of type dummy_EPS_FD1_29
 *   dummy_EPS_FD1_6 of type dummy_EPS_FD1_30
 *   dummy_EPS_FD1_7 of type dummy_EPS_FD1_31
 *   EPS_FailSts_0x147 of type EPS_FailSts_0x147
 *   EPS_SteerMod_0x147 of type EPS_SteerMod_0x147
 *   RollingCounter_EPS1_0x147 of type RollingCounter_EPS1_0x147
 *   SteerCorrnResp_0x147 of type SteerCorrnResp_0x147
 *   SteerCorrnRmn_0x147 of type SteerCorrnRmn_0x147
 * SG_ESP1_ESP_FD2: Record with elements
 *   CheckSum_ESP1_0x137 of type CheckSum_ESP1_0x137
 *   dummy_ESP_FD2_16 of type dummy_ESP_FD2_34
 *   dummy_ESP_FD2_17 of type dummy_ESP_FD2_35
 *   dummy_ESP_FD2_18 of type dummy_ESP_FD2_36
 *   dummy_ESP_FD2_19 of type dummy_ESP_FD2_45
 *   dummy_ESP_FD2_20 of type dummy_ESP_FD2_46
 *   ESPActvInfoLmp_0x137 of type ESPActvInfoLmp_0x137
 *   ESPFailSts_0x137 of type ESPFailSts_0x137
 *   ESPFuncOffSts_0x137 of type ESPFuncOffSts_0x137
 *   RollingCounter_ESP1_0x137 of type RollingCounter_ESP1_0x137
 *   dummy_ESP_FD2_15 of type dummy_ESP_FD2_47
 *   dummy_ESP_FD2_21 of type dummy_ESP_FD2_48
 *   dummy_ESP_FD2_22 of type dummy_ESP_FD2_49
 *   TSM_Trailer_0x137 of type TSM_Trailer_0x137
 * SG_ESP2: Record with elements
 *   AVHErrSts_0x145 of type AVHErrSts_0x145
 *   AVHSts_0x145 of type AVHSts_0x145
 *   CDPActv_0x145 of type CDPActv_0x145
 *   CheckSum_ESP2_0x145 of type CheckSum_ESP2_0x145
 *   dummy_ESP2_0 of type dummy_ESP2_8
 *   dummy_ESP2_1 of type dummy_ESP2_9
 *   dummy_ESP2_2 of type dummy_ESP2_10
 *   dummy_ESP2_3 of type dummy_ESP2_11
 *   dummy_ESP2_4 of type dummy_ESP2_12
 *   dummy_ESP2_5 of type dummy_ESP2_13
 *   dummy_ESP2_6 of type dummy_ESP2_14
 *   HDCCtrl_0x145 of type HDCCtrl_0x145
 *   HDCFault_0x145 of type HDCFault_0x145
 *   RollingCounter_ESP2_0x145 of type RollingCounter_ESP2_0x145
 *   DrivingModDis_0x145 of type DrivingModDis_0x145
 *   DrivingModReq_ESP_0x145 of type DrivingModReq_ESP_0x145
 *   FourL_Warn_0x145 of type FourL_Warn_0x145
 *   Over_Spd_Warn_0x145 of type Over_Spd_Warn_0x145
 *   Shift_N_Warn_0x145 of type Shift_N_Warn_0x145
 *   TAB_Sts_0x145 of type TAB_Sts_0x145
 * SG_ESP2_ESP_FD2: Record with elements
 *   AVHErrSts_0x137 of type AVHErrSts_0x137
 *   AVHSts_0x137 of type AVHSts_0x137
 *   CDPActv_0x137 of type CDPActv_0x137
 *   CheckSum_ESP2_0x137 of type CheckSum_ESP2_0x137
 *   dummy_ESP_FD2_8 of type dummy_ESP_FD2_57
 *   dummy_ESP_FD2_9 of type dummy_ESP_FD2_58
 *   dummy_ESP_FD2_10 of type dummy_ESP_FD2_59
 *   dummy_ESP_FD2_11 of type dummy_ESP_FD2_60
 *   dummy_ESP_FD2_12 of type dummy_ESP_FD2_61
 *   dummy_ESP_FD2_13 of type dummy_ESP_FD2_62
 *   dummy_ESP_FD2_14 of type dummy_ESP_FD2_63
 *   HDCCtrl_0x137 of type HDCCtrl_0x137
 *   HDCFault_0x137 of type HDCFault_0x137
 *   RollingCounter_ESP2_0x137 of type RollingCounter_ESP2_0x137
 *   DrivingModDis_0x137 of type DrivingModDis_0x137
 *   DrivingModReq_ESP_0x137 of type DrivingModReq_ESP_0x137
 *   FourL_Warn_0x137 of type FourL_Warn_0x137
 *   Over_Spd_Warn_0x137 of type Over_Spd_Warn_0x137
 *   Shift_N_Warn_0x137 of type Shift_N_Warn_0x137
 *   TAB_Sts_0x137 of type TAB_Sts_0x137
 * SG_IFC3_IFC_FD2: Record with elements
 *   AESErrSts of type AESErrSts_1
 *   AESResp of type AESResp_1
 *   AESSts of type AESSts_1
 *   Checksum_IFC3 of type Checksum_IFC3_1
 *   ELKResp of type ELKResp_1
 *   ESS_Pedresp of type ESS_Pedresp_1
 *   ESS_Vehresp of type ESS_Vehresp_1
 *   ESSErrSts of type ESSErrSts_1
 *   ESSSts of type ESSSts_1
 *   IFCHUTInterface of type IFCHUTInterface_1
 *   IntelligentEvaResp of type IntelligentEvaResp_1
 *   LCKResp of type LCKResp_1
 *   LDW_LKA_Snvty of type LDW_LKA_Snvty_1
 *   LDWResp of type LDWResp_1
 *   LKAResp of type LKAResp_1
 *   LSSResp of type LSSResp_1
 *   LSSWarnFormResp of type LSSWarnFormResp_1
 *   RollingCounter_IFC3 of type RollingCounter_IFC3_1
 *   dummy_IFC_FD2_8 of type dummy_IFC_FD2_8
 *   dummy_IFC_FD2_9 of type dummy_IFC_FD2_9
 *   dummy_IFC_FD2_10 of type dummy_IFC_FD2_10
 *   dummy_IFC_FD2_11 of type dummy_IFC_FD2_11
 *   dummy_IFC_FD2_12 of type dummy_IFC_FD2_12
 * SG_IFC4_IFC_FD2: Record with elements
 *   CameraBlockageSts of type CameraBlockageSts_3
 *   Checksum_IFC4 of type Checksum_IFC4_3
 *   ELKMainState of type ELKMainState_3
 *   IFC_Handsoffwarn of type IFC_Handsoffwarn_3
 *   IFCCalibrationSts of type IFCCalibrationSts_3
 *   LaneAvailability of type LaneAvailability_3
 *   LDW_LKAWarn of type LDW_LKAWarn_3
 *   LSSErrSts of type LSSErrSts_3
 *   LSSFuncSts of type LSSFuncSts_3
 *   LSSIntervention of type LSSIntervention_3
 *   RollingCounter_IFC4 of type RollingCounter_IFC4_3
 *   TJA_FollowSts of type TJA_FollowSts_3
 *   AESintervention of type AESintervention
 *   ESSintervention of type ESSintervention
 *   dummy_IFC_FD2_13 of type dummy_IFC_FD2_17
 *   dummy_IFC_FD2_14 of type dummy_IFC_FD2_18
 *   dummy_IFC_FD2_15 of type dummy_IFC_FD2_19
 *   ELKActSts of type ELKActSts
 *   IntelligentEvaActSts of type IntelligentEvaActSts
 *   LCKStsIndcr of type LCKStsIndcr
 * SG_IFC5_IFC_FD2: Record with elements
 *   Checksum_IFC5 of type Checksum_IFC5_2
 *   IFC_LaneCurve of type IFC_LaneCurve_2
 *   IFC_LeLane_dy of type IFC_LeLane_dy_2
 *   IFC_LeLaneTyp of type IFC_LeLaneTyp_2
 *   IFC_NextLeLaneTyp of type IFC_NextLeLaneTyp_2
 *   IFC_NextRiLaneTyp of type IFC_NextRiLaneTyp_2
 *   IFC_RiLane_dy of type IFC_RiLane_dy_2
 *   IFC_RiLaneTyp of type IFC_RiLaneTyp_2
 *   RollingCounter_IFC5 of type RollingCounter_IFC5_2
 *   dummy_IFC_FD2_16 of type dummy_IFC_FD2_16
 * SG_IFC6_IFC_FD2: Record with elements
 *   Checksum_IFC6 of type Checksum_IFC6
 *   dummy_IFC_FD2_17 of type dummy_IFC_FD2_17
 *   dummy_IFC_FD2_18 of type dummy_IFC_FD2_18
 *   dummy_IFC_FD2_19 of type dummy_IFC_FD2_19
 *   dummy_IFC_FD2_20 of type dummy_IFC_FD2_20
 *   IFC_NextLeLane_dy of type IFC_NextLeLane_dy
 *   IFC_NextRiLane_dy of type IFC_NextRiLane_dy
 *   RollingCounter_IFC6 of type RollingCounter_IFC6
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 * TC_MODULE_OUTPUT_DATA_STRUCT_RTE: Record with elements
 *   u16AFE_1st_Display_Output_Data of type uint16
 *   u16AFE_2st_Display_Output_Data of type uint16
 *   u32AFE_1st_Fuel_Trip_Value of type uint32
 *   u32AFE_1st_Fuel_Consumption_Value of type uint32
 *   u32AFE_2st_Fuel_Trip_Value of type uint32
 *   u32AFE_2st_Fuel_Consumption_Value of type uint32
 *   u16IFE_Calculate_Output_Data of type uint16
 *   u16IFE_Display_Output_Data of type uint16
 *   u32IFE_Fuel_Trip_Value of type uint32
 *   u32IFE_Fuel_Consumption_Value of type uint32
 *   u32IFE_Fuel_Consumption_Can_Signal of type uint32
 *   u16AVS_1st_Display_Output_Data of type uint16
 *   u16AVS_2st_Display_Output_Data of type uint16
 *   u32AVS_1st_Driving_Time_Value of type uint32
 *   u32AVS_2st_Driving_Time_Value of type uint32
 *   u32AVS_1st_Fuel_Trip_Value of type uint32
 *   u32AVS_2st_Fuel_Trip_Value of type uint32
 *   u8DrivingTime_1st_Display_Hour of type uint8
 *   u8DrivingTime_2st_Display_Hour of type uint8
 *   u8DrivingTime_1st_Display_Minute of type uint8
 *   u8DrivingTime_2st_Display_Minute of type uint8
 *   u16DTE_Fuel_Tank_Volume of type uint16
 *   u16DTE_Fuel_Tank_Volume_Aux of type uint16
 *   u8DTE_Fuel_Stage_Consumption of type uint16
 *   u8DTE_Fuel_Stage_Consumption_Aux of type uint16
 *   u16DTE_Display_Output_Data of type uint16
 *   u16DTE_Display_Output_Data_Aux of type uint16
 *   u16DTE_Calculate_Output_Data of type uint16
 *   u16SFC_Output_Data of type uint16
 *   u8IFC_Poc_Update of type uint8
 *   u16IFC_Poc_Calculate_Value of type uint16
 *   u16SFC_For_Fuel_Output_Data of type uint16
 *   u16IFC_Poc_For_Fuel_Calculate_Rate of type uint16
 *   u16IFC_Poc_For_Fuel_Calculate_Rate_Aux of type uint16
 * WN_WarningStsOutput: Record with elements
 *   WarningStatus of type Rte_DT_WN_WarningStsOutput_0
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Rte_DT_NVMBlockMaintain_Type_0 *Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock(void)
 *     Returnvalue: Rte_DT_NVMBlockMaintain_Type_0* is of type NVMBlockMaintain_Type
 *   uint8 *Rte_Pim_NvBlockNeed_Block_ODO_1_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_Pim_NvBlockNeed_Block_ODO_2_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_Pim_NvBlockNeed_Block_ODO_3_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_Pim_NvBlockNeed_Block_ODO_4_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_Pim_NvBlockNeed_Block_ODO_5_MirrorBlock(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   Rte_DT_NVMBlockTrip_0 *Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock(void)
 *     Returnvalue: Rte_DT_NVMBlockTrip_0* is of type NVMBlockTrip
 *   uint8 *Rte_Pim_NvBlockNeed_MENU_Data_MirrorBlock(void)
 *     Returnvalue: uint8* is of type NVMMenuData_A20
 *   uint8 *Rte_Pim_NvBlockNeed_Menu_MirrorBlock(void)
 *     Returnvalue: uint8* is of type NVMMenuData_A20
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Rte_DT_NVMBlockMaintain_Type_0 *Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue(void)
 *     Returnvalue: Rte_DT_NVMBlockMaintain_Type_0* is of type NVMBlockMaintain_Type
 *   uint8 *Rte_CData_NvBlockNeed_Block_ODO_1_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_CData_NvBlockNeed_Block_ODO_2_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_CData_NvBlockNeed_Block_ODO_3_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_CData_NvBlockNeed_Block_ODO_4_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   uint8 *Rte_CData_NvBlockNeed_Block_ODO_5_DefaultValue(void)
 *     Returnvalue: uint8* is of type A_ODO_data_u8_16
 *   Rte_DT_NVMBlockTCConfig_Type_0 *Rte_CData_NvBlockNeed_Block_TC_Config_Data_DefaultValue(void)
 *     Returnvalue: Rte_DT_NVMBlockTCConfig_Type_0* is of type NVMBlockTCConfig_Type
 *   Rte_DT_NVMBlockTC_Type_0 *Rte_CData_NvBlockNeed_Block_TC_Data_DefaultValue(void)
 *     Returnvalue: Rte_DT_NVMBlockTC_Type_0* is of type NVMBlockTC_Type
 *   Rte_DT_NVMBlockTrip_0 *Rte_CData_NvBlockNeed_Block_Trip_DefaultValue(void)
 *     Returnvalue: Rte_DT_NVMBlockTrip_0* is of type NVMBlockTrip
 *   uint8 *Rte_CData_NvBlockNeed_MENU_Data_DefaultValue(void)
 *     Returnvalue: uint8* is of type NVMMenuData_A20
 *
 *********************************************************************************************************************/


#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_100msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rc_Fuel_Status_Fuel_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_Odo_RunCounter_RunCounter(uint8 *data)
 *   boolean Rte_IsUpdated_Rc_Fuel_Status_Fuel_Status(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   SystemState_RecordType *Rte_IRead_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Sd_Fuel_Status_Fuel_Status(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(const FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_IP_AuxRemainDistance_IP_AuxRemainDistance(uint16 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_IP_FuelAuxLvlInfo_IP_FuelAuxLvlInfo(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_OdoParament_Element(const s_OdoRteGetParament_t *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(const TC_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_Normal_100msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_100msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_100msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_100msMainFunction
 *********************************************************************************************************************/
	Fuel_Api_Main_Task();
	TC_Api_Process_fuel_update_Task();
	TC_Api_Update_Calc_Task();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_100msMainFunction_
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_tiSR_VIN_Element(uint8 *data)
 *     Argument data: uint8* is of type A_17Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_100msMainFunction__doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_100msMainFunction_(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_100msMainFunction_
 *********************************************************************************************************************/
	TPMSMdl_TPMS_app_tsk();
    MenuSetMdl_MenuSet_app_tsk();
	SWC_Config_Entrance_Task();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_10msMainFunction
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
 *   Std_ReturnType Rte_Read_ACAmbTemp_ACAmbTemp(ACAmbTemp *data)
 *   Std_ReturnType Rte_Read_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts(APS_FLSideSnsrFailSts *data)
 *   Std_ReturnType Rte_Read_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts(APS_FRSideSnsrFailSts *data)
 *   Std_ReturnType Rte_Read_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts(APS_RLSideSnsrFailSts *data)
 *   Std_ReturnType Rte_Read_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts(APS_RRSideSnsrFailSts *data)
 *   Std_ReturnType Rte_Read_APS_SysSoundIndcn_APS_SysSoundIndcn(APS_SysSoundIndcn *data)
 *   Std_ReturnType Rte_Read_APS_WorkSts_APS_WorkSts(APS_WorkSts *data)
 *   Std_ReturnType Rte_Read_AccelPedalPosnVldty_AccelPedalPosnVldty(AccelPedalPosnVldty *data)
 *   Std_ReturnType Rte_Read_AccelPedlPosnDiagc_AccelPedlPosnDiagc(AccelPedlPosnDiagc *data)
 *   Std_ReturnType Rte_Read_AutoLmpSwtSts_AutoLmpSwtSts(AutoLmpSwtSts *data)
 *   Std_ReturnType Rte_Read_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight(BSD_LCA_warningReqRight *data)
 *   Std_ReturnType Rte_Read_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft(BSD_LCA_warningReqleft *data)
 *   Std_ReturnType Rte_Read_BrkPedalSts_BCM_BrkPedalSts_BCM(BrkPedalSts_BCM *data)
 *   Std_ReturnType Rte_Read_CCO_Active_CCO_Active(CCO_Active *data)
 *   Std_ReturnType Rte_Read_CCO_TgtVel_CCO_TgtVel(CCO_TgtVel *data)
 *   Std_ReturnType Rte_Read_CCO_Warn_CCO_Warn(CCO_Warn *data)
 *   Std_ReturnType Rte_Read_CR_BliSts_CR_BliSts(CR_BliSts *data)
 *   Std_ReturnType Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type CconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_CouplingThermWarning_CouplingThermWarning(CouplingThermWarning *data)
 *   Std_ReturnType Rte_Read_CruiseCtrlSts_CruiseCtrlSts(CruiseCtrlSts *data)
 *   Std_ReturnType Rte_Read_DCT3_TgtEngSpdIP_TgtEngSpdIP(TgtEngSpdIP *data)
 *   Std_ReturnType Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(TgtEngSpdIPValid *data)
 *   Std_ReturnType Rte_Read_DCT9_DisplayGear(DisplayGear *data)
 *   Std_ReturnType Rte_Read_DCT9_DrvModDisp_0xc6(DrvModDisp_0xc6 *data)
 *   Std_ReturnType Rte_Read_DCT9_ShiftRecommend_M(ShiftRecommend_M *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Shift_not_allowed_Warn(TCU_Shift_not_allowed_Warn *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_P_faulty(TCU_Warn_P_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_drive_faulty(TCU_Warn_drive_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_driver_leaves_car(TCU_Warn_driver_leaves_car *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_gearbox_N(TCU_Warn_gearbox_N *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_gearbox_faulty(TCU_Warn_gearbox_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_high_temp(TCU_Warn_high_temp *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_limphome_D(TCU_Warn_limphome_D *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_limphome_P(TCU_Warn_limphome_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_prohibit_P(TCU_Warn_prohibit_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_release_button(TCU_Warn_release_button *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_shifter_faulty(TCU_Warn_shifter_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_step_P(TCU_Warn_step_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_vehicle_P(TCU_Warn_vehicle_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_gear_flashing(TCU_gear_flashing *data)
 *   Std_ReturnType Rte_Read_DCT9_TRANS_OIL_TEMP_0xc6(TRANS_OIL_TEMP_0xc6 *data)
 *   Std_ReturnType Rte_Read_DCT9_TrsmStNID_0xc6(TrsmStNID_0xc6 *data)
 *   Std_ReturnType Rte_Read_DOW_warningReqRight_DOW_warningReqRight(DOW_warningReqRight *data)
 *   Std_ReturnType Rte_Read_DOW_warningReqleft_DOW_warningReqleft(DOW_warningReqleft *data)
 *   Std_ReturnType Rte_Read_DiagLmpReq_DiagLmpReq(DiagLmpReq *data)
 *   Std_ReturnType Rte_Read_DrowsyDrvDetWarn_DrowsyDrvDetWarn(DrowsyDrvDetWarn *data)
 *   Std_ReturnType Rte_Read_DrvDoorSts_DrvDoorSts(DrvDoorSts *data)
 *   Std_ReturnType Rte_Read_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl(Dyn_PwrSv_Lvl *data)
 *   Std_ReturnType Rte_Read_ECM11_EngSpd_ForIP_EngSpd_ForIP(EngSpd_ForIP *data)
 *   Std_ReturnType Rte_Read_ECM16_DPF_Warning(DPF_Warning *data)
 *   Std_ReturnType Rte_Read_ECM16_GlowPlugLmpCmd(GlowPlugLmpCmd *data)
 *   Std_ReturnType Rte_Read_ECM16_SCRSysWarnDisplay(SCRSysWarnDisplay *data)
 *   Std_ReturnType Rte_Read_ECM16_UreaLampCmd(UreaLampCmd *data)
 *   Std_ReturnType Rte_Read_ECM16_UreaRemainDist(UreaRemainDist *data)
 *   Std_ReturnType Rte_Read_ECM16_Urea_Level(Urea_Level *data)
 *   Std_ReturnType Rte_Read_ECM16_WIFFullLmpCmd(WIFFullLmpCmd *data)
 *   Std_ReturnType Rte_Read_ECM16_WIFSensorFailSts(WIFSensorFailSts *data)
 *   Std_ReturnType Rte_Read_ECM1_EngSpdVldty_EngSpdVldty(EngSpdVldty *data)
 *   Std_ReturnType Rte_Read_ECM_VIN_ECM19_0x3B5(uint8 *data)
 *     Argument data: uint8* is of type ECM_VIN
 *   Std_ReturnType Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup(ECM_VehDstBackup *data)
 *   Std_ReturnType Rte_Read_EMS_AuthenResult_EMS_AuthenResult(EMS_AuthenResult *data)
 *   Std_ReturnType Rte_Read_ESP_HMI_WarningOn_ESP_HMI_WarningOn(ESP_HMI_WarningOn *data)
 *   Std_ReturnType Rte_Read_EWP_Err_EWP_Err(EWP_Err *data)
 *   Std_ReturnType Rte_Read_EngClntTempVldty_EngClntTempVldty(EngClntTempVldty *data)
 *   Std_ReturnType Rte_Read_EngClntTempWarn_EngClntTempWarn(EngClntTempWarn *data)
 *   Std_ReturnType Rte_Read_EngCoolantTemp_EngCoolantTemp(EngCoolantTemp *data)
 *   Std_ReturnType Rte_Read_EngSVSSig_EngSVSSig(EngSVSSig *data)
 *   Std_ReturnType Rte_Read_EngSpdVldty_EngSpdVldty(EngSpdVldty *data)
 *   Std_ReturnType Rte_Read_EngSpd_ForIP_EngSpd_ForIP(EngSpd_ForIP *data)
 *   Std_ReturnType Rte_Read_EspFuncOffSts_mode_EspFuncOffSts_mode(EspFuncOffSts_mode *data)
 *   Std_ReturnType Rte_Read_FCTA_B_FuncSts_FCTA_B_FuncSts(FCTA_B_FuncSts *data)
 *   Std_ReturnType Rte_Read_FCTA_Warn_FCTA_Warn(FCTA_Warn *data)
 *   Std_ReturnType Rte_Read_FCTBTrig_FCTBTrig(FCTBTrig *data)
 *   Std_ReturnType Rte_Read_FLTirePress_FLTirePress(FLTirePress *data)
 *   Std_ReturnType Rte_Read_FLTirePressIndSts_FLTirePressIndSts(FLTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_FLTireTemp_FLTireTemp(FLTireTemp *data)
 *   Std_ReturnType Rte_Read_FLTireTempSts_FLTireTempSts(FLTireTempSts *data)
 *   Std_ReturnType Rte_Read_FPAS_SoundIndcn_FPAS_SoundIndcn(FPAS_SoundIndcn_0x26D *data)
 *   Std_ReturnType Rte_Read_FPAS_WorkSts_FPAS_WorkSts(FPAS_WorkSts_0x26D *data)
 *   Std_ReturnType Rte_Read_FRTirePress_FRTirePress(FRTirePress *data)
 *   Std_ReturnType Rte_Read_FRTirePressIndSts_FRTirePressIndSts(FRTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_FRTireTemp_FRTireTemp(FRTireTemp *data)
 *   Std_ReturnType Rte_Read_FRTireTempSts_FRTireTempSts(FRTireTempSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_FFogLmpSts_F_PBOX(FFogLmpSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_HiBeamSts_F_PBOX(HiBeamSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_HoodSts_F_PBOX(HoodSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LHeadLmpFailSts(LHeadLmpFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LHiBeamFailSts(LHiBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LLasHdLmpDiagSig(LLasHdLmpDiagSig *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LLowBeamFailSts(LLowBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LasHdLmpSts_F_PBOX(LasHdLmpSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RHeadLmpFailSts(RHeadLmpFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RHiBeamFailSts(RHiBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RLasHdLmpDiagSig(RLasHdLmpDiagSig *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RLowBeamFailSts(RLowBeamFailSts *data)
 *   Std_ReturnType Rte_Read_FrntELDLckSts_FrntELDLckSts(FrntELDLckSts *data)
 *   Std_ReturnType Rte_Read_FuelConsumption_FuelConsumption(FuelConsumption *data)
 *   Std_ReturnType Rte_Read_GPF_Warning_GPF_Warning(GPF_Warning *data)
 *   Std_ReturnType Rte_Read_GentrWarnLmpSts_GentrWarnLmpSts(GentrWarnLmpSts *data)
 *   Std_ReturnType Rte_Read_HiLowBeamSts_HiLowBeamSts(HiLowBeamSts *data)
 *   Std_ReturnType Rte_Read_IB_Warn_IB_Warn(IB_Warn *data)
 *   Std_ReturnType Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30BRelaySts *data)
 *   Std_ReturnType Rte_Read_LRDoorSts_LRDoorSts(LRDoorSts *data)
 *   Std_ReturnType Rte_Read_LvPwrSysErr_LvPwrSysErr(LvPwrSysErr *data)
 *   Std_ReturnType Rte_Read_MILSts_MILSts(MILSts *data)
 *   Std_ReturnType Rte_Read_PASWorkCmd_PASWorkCmd(PASWorkCmd *data)
 *   Std_ReturnType Rte_Read_PassengerDoorSts_PassengerDoorSts(PassengerDoorSts *data)
 *   Std_ReturnType Rte_Read_PowerRlyFault_PowerRlyFault(PowerRlyFault *data)
 *   Std_ReturnType Rte_Read_RCTA_warningReqLeft_RCTA_warningReqLeft(RCTA_warningReqLeft *data)
 *   Std_ReturnType Rte_Read_RCTA_warningReqRight_RCTA_warningReqRight(RCTA_warningReqRight *data)
 *   Std_ReturnType Rte_Read_RLSFailSts_RLSFailSts(RLSFailSts *data)
 *   Std_ReturnType Rte_Read_RLTirePress_RLTirePress(RLTirePress *data)
 *   Std_ReturnType Rte_Read_RLTirePressIndSts_RLTirePressIndSts(RLTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_RLTireTemp_RLTireTemp(RLTireTemp *data)
 *   Std_ReturnType Rte_Read_RLTireTempSts_RLTireTempSts(RLTireTempSts *data)
 *   Std_ReturnType Rte_Read_RPAS_SoundIndcn_RPAS_SoundIndcn(RPAS_SoundIndcn_0x26E *data)
 *   Std_ReturnType Rte_Read_RPAS_WorkSts_RPAS_WorkSts(RPAS_WorkSts_0x26E *data)
 *   Std_ReturnType Rte_Read_RRDoorSts_RRDoorSts(RRDoorSts *data)
 *   Std_ReturnType Rte_Read_RRTirePress_RRTirePress(RRTirePress *data)
 *   Std_ReturnType Rte_Read_RRTirePressIndSts_RRTirePressIndSts(RRTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_RRTireTemp_RRTireTemp(RRTireTemp *data)
 *   Std_ReturnType Rte_Read_RRTireTempSts_RRTireTempSts(RRTireTempSts *data)
 *   Std_ReturnType Rte_Read_RSDS_BliSts_RSDS_BliSts(RSDS_BliSts *data)
 *   Std_ReturnType Rte_Read_RSDS_BrkgTrig_RSDS_BrkgTrig(RSDS_BrkgTrig *data)
 *   Std_ReturnType Rte_Read_RSDS_CTA_Actv_RSDS_CTA_Actv(RSDS_CTA_Actv *data)
 *   Std_ReturnType Rte_Read_RSDS_ErrSts_RSDS_ErrSts(RSDS_ErrSts *data)
 *   Std_ReturnType Rte_Read_RSDS_IPSoundReq_RSDS_IPSoundReq(RSDS_IPSoundReq *data)
 *   Std_ReturnType Rte_Read_RSDS_LCAResp_RSDS_LCAResp(RSDS_LCAResp *data)
 *   Std_ReturnType Rte_Read_RSDS_RCW_Trigger_RSDS_RCW_Trigger(RSDS_RCW_Trigger *data)
 *   Std_ReturnType Rte_Read_RSDS_TrailerSts_RSDS_TrailerSts(RSDS_TrailerSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_HiPosnBrkLmpFailSts(HiPosnBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LBrkLmpFailSts(LBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LRPosnLmpFailSts(LRPosnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LTurnLmpFailSts(LTurnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LTurnLmpSts_R_PBOX(LTurnLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LicPlateLmpFailSts(LicPlateLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_ParkLmpSts_R_PBOX(ParkLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_PosnLmpOutpSts_R_PBOX(PosnLmpOutpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RBrkLmpFailSts(RBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RFogLmpFailSts_R_PBOX(RFogLmpFailSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RFogLmpSts_R_PBOX(RFogLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RRPosnLmpFailSts(RRPosnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RTurnLmpFailSts(RTurnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RTurnLmpSts_R_PBOX(RTurnLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RWinHeatgFailSts(RWinHeatgFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RWinHeatgIconRlyCmd(RWinHeatgIconRlyCmd *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RvsLmpFailSts(RvsLmpFailSts *data)
 *   Std_ReturnType Rte_Read_Rc_Cluster_Shutdown_Status_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_Fuel_Status_Fuel_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_Odo_RunCounter_RunCounter(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_IndicateSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_OverSpdWrnFlg(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_RealSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_VehRunSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_TachoInfo_EngRunSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_TachoInfo_EngSpd(uint16 *data)
 *   Std_ReturnType Rte_Read_RearELDLckSts_RearELDLckSts(RearELDLckSts *data)
 *   Std_ReturnType Rte_Read_RemoteModSts_RemoteModSts(RemoteModSts *data)
 *   Std_ReturnType Rte_Read_RotSteerWheel_RotSteerWheel(RotSteerWheel *data)
 *   Std_ReturnType Rte_Read_SDWActiveSts_SDWActiveSts(SDWActiveSts *data)
 *   Std_ReturnType Rte_Read_SDW_SoundIndcn_SDW_SoundIndcn(SDW_SoundIndcn *data)
 *   Std_ReturnType Rte_Read_SG_ABM1_SG_ABM1(SG_ABM1 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_SG_ABS3(SG_ABS3 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(SG_ABS3_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(SG_ACC3_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(SG_ACC4_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(SG_ACC7_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(SG_ACC8_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(SG_AEB2_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(SG_AEB3_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_DCT_FD4_SG_DCT_FD4(SG_DCT_FD4 *data)
 *   Std_ReturnType Rte_Read_SG_EPB1_SG_EPB1(SG_EPB1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_SG_EPS1(SG_EPS1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(SG_EPS1_FD1 *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(SG_ESP1_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_SG_ESP2(SG_ESP2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(SG_ESP2_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(SG_IFC3_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(SG_IFC4_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2(SG_IFC5_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(SG_IFC6_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_SS_Enable_Lamp_SS_Enable_Lamp(SS_Enable_Lamp *data)
 *   Std_ReturnType Rte_Read_SS_Fault_Lamp_SS_Fault_Lamp(SS_Fault_Lamp *data)
 *   Std_ReturnType Rte_Read_SS_Screen_tip_SS_Screen_tip(uint8 *data)
 *   Std_ReturnType Rte_Read_SocReadyFlag_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(Stat_PwrSv_Lvl *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_TGS_LEVER_TGS_LEVER(TGS_LEVER *data)
 *   Std_ReturnType Rte_Read_TRANS_Warning_LAMP_TRANS_Warning_LAMP(TRANS_Warning_LAMP *data)
 *   Std_ReturnType Rte_Read_TSRSpdLim_TSRSpdLim(TSRSpdLim *data)
 *   Std_ReturnType Rte_Read_TSRSpdLimCfdc_TSRSpdLimCfdc(TSRSpdLimCfdc *data)
 *   Std_ReturnType Rte_Read_TSRSpdLimSts_TSRSpdLimSts(TSRSpdLimSts *data)
 *   Std_ReturnType Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn(TSRSpdLimWarn *data)
 *   Std_ReturnType Rte_Read_TSRSts_TSRSts(TSRSts *data)
 *   Std_ReturnType Rte_Read_TSRTrfcSignVal_TSRTrfcSignVal(TSRTrfcSignVal *data)
 *   Std_ReturnType Rte_Read_T_BOX_FD3_T_BOX_SWUpdSts(T_BOX_SWUpdSts *data)
 *   Std_ReturnType Rte_Read_T_BOX_FD3_T_BOX_SysErrSts(T_BOX_SysErrSts *data)
 *   Std_ReturnType Rte_Read_TgtCrsVehSpd_TgtCrsVehSpd(uint8 *data)
 *   Std_ReturnType Rte_Read_TirePressSysFailrIndcn_TirePressSysFailrIndcn(TirePressSysFailrIndcn *data)
 *   Std_ReturnType Rte_Read_TrailerSts_TrailerSts(TrailerSts *data)
 *   Std_ReturnType Rte_Read_TranPMode_Sts_TranPMode_Sts(TranPMode_Sts *data)
 *   Std_ReturnType Rte_Read_TrunkSts_TrunkSts(TrunkSts *data)
 *   Std_ReturnType Rte_Read_Vconfig_GetKindBuffers_AllKinds(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_Allbuffers
 *   Std_ReturnType Rte_Read_WPC_FaultSts_WPC_FaultSts(WPC_FaultSts *data)
 *   Std_ReturnType Rte_Read_WPC_PhoneReminder_WPC_PhoneReminder(WPC_PhoneReminder *data)
 *   Std_ReturnType Rte_Read_WarnEngStrtNotMeet_WarnEngStrtNotMeet(WarnEngStrtNotMeet *data)
 *   Std_ReturnType Rte_Read_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit(WarnKeyInCarWhenExit *data)
 *   Std_ReturnType Rte_Read_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn(WarnPowerNotInOffPosn *data)
 *   Std_ReturnType Rte_Read_WarnVldKeyNotFound_WarnVldKeyNotFound(WarnVldKeyNotFound *data)
 *   Std_ReturnType Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(boolean *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_ChimeID_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter(uint32 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_DrvModStatusRecord_Element(DM_tstDrvModStatusRecord *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_EnergyInfoId_Data(EnergyInfoIdDataType *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_MenuSetData_Element(MenuSetData_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(uint16 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_OdoParament_Element(s_OdoRteGetParament_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_S2M_Information_SpeedValue(uint16 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_S2M_Information_TachoValue(uint16 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(TC_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_TachoInfo_Element(s_TachoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_WarningStsOutput_Element(WN_WarningStsOutput *data)
 *   Std_ReturnType Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_SleepDateTime(sint64 *data)
 *   Std_ReturnType Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(sint64 *data)
 *   Std_ReturnType Rte_Read_tiSR_SWC_TT_SelfCheck_Element(uint8 *data)
 *   boolean Rte_IsUpdated_APS_FLSideSnsrFailSts_APS_FLSideSnsrFailSts(void)
 *   boolean Rte_IsUpdated_APS_FRSideSnsrFailSts_APS_FRSideSnsrFailSts(void)
 *   boolean Rte_IsUpdated_APS_RLSideSnsrFailSts_APS_RLSideSnsrFailSts(void)
 *   boolean Rte_IsUpdated_APS_RRSideSnsrFailSts_APS_RRSideSnsrFailSts(void)
 *   boolean Rte_IsUpdated_APS_SysSoundIndcn_APS_SysSoundIndcn(void)
 *   boolean Rte_IsUpdated_APS_WorkSts_APS_WorkSts(void)
 *   boolean Rte_IsUpdated_BSD_LCA_warningReqRight_BSD_LCA_warningReqRight(void)
 *   boolean Rte_IsUpdated_BSD_LCA_warningReqleft_BSD_LCA_warningReqleft(void)
 *   boolean Rte_IsUpdated_CCO_Active_CCO_Active(void)
 *   boolean Rte_IsUpdated_CR_BliSts_CR_BliSts(void)
 *   boolean Rte_IsUpdated_CruiseCtrlSts_CruiseCtrlSts(void)
 *   boolean Rte_IsUpdated_DCT3_TgtEngSpdIP_TgtEngSpdIP(void)
 *   boolean Rte_IsUpdated_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(void)
 *   boolean Rte_IsUpdated_DCT9_DisplayGear(void)
 *   boolean Rte_IsUpdated_DCT9_DrvModDisp_0xc6(void)
 *   boolean Rte_IsUpdated_DCT9_ShiftRecommend_M(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Shift_not_allowed_Warn(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_P_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_drive_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_driver_leaves_car(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_gearbox_N(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_gearbox_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_high_temp(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_limphome_D(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_limphome_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_prohibit_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_release_button(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_shifter_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_step_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_vehicle_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_gear_flashing(void)
 *   boolean Rte_IsUpdated_DCT9_TRANS_OIL_TEMP_0xc6(void)
 *   boolean Rte_IsUpdated_DCT9_TrsmStNID_0xc6(void)
 *   boolean Rte_IsUpdated_DOW_warningReqRight_DOW_warningReqRight(void)
 *   boolean Rte_IsUpdated_DOW_warningReqleft_DOW_warningReqleft(void)
 *   boolean Rte_IsUpdated_ECM16_DPF_Warning(void)
 *   boolean Rte_IsUpdated_ECM16_GlowPlugLmpCmd(void)
 *   boolean Rte_IsUpdated_ECM16_SCRSysWarnDisplay(void)
 *   boolean Rte_IsUpdated_ECM16_UreaLampCmd(void)
 *   boolean Rte_IsUpdated_ECM16_UreaRemainDist(void)
 *   boolean Rte_IsUpdated_ECM16_Urea_Level(void)
 *   boolean Rte_IsUpdated_ECM16_WIFFullLmpCmd(void)
 *   boolean Rte_IsUpdated_ECM16_WIFSensorFailSts(void)
 *   boolean Rte_IsUpdated_ECM_VIN_ECM19_0x3B5(void)
 *   boolean Rte_IsUpdated_ECM_VehDstBackup_ECM_VehDstBackup(void)
 *   boolean Rte_IsUpdated_ESP_HMI_WarningOn_ESP_HMI_WarningOn(void)
 *   boolean Rte_IsUpdated_EngClntTempVldty_EngClntTempVldty(void)
 *   boolean Rte_IsUpdated_EngClntTempWarn_EngClntTempWarn(void)
 *   boolean Rte_IsUpdated_EngCoolantTemp_EngCoolantTemp(void)
 *   boolean Rte_IsUpdated_EngSVSSig_EngSVSSig(void)
 *   boolean Rte_IsUpdated_FCTA_B_FuncSts_FCTA_B_FuncSts(void)
 *   boolean Rte_IsUpdated_FCTA_Warn_FCTA_Warn(void)
 *   boolean Rte_IsUpdated_FCTBTrig_FCTBTrig(void)
 *   boolean Rte_IsUpdated_FLTirePress_FLTirePress(void)
 *   boolean Rte_IsUpdated_FLTirePressIndSts_FLTirePressIndSts(void)
 *   boolean Rte_IsUpdated_FLTireTemp_FLTireTemp(void)
 *   boolean Rte_IsUpdated_FLTireTempSts_FLTireTempSts(void)
 *   boolean Rte_IsUpdated_FPAS_SoundIndcn_FPAS_SoundIndcn(void)
 *   boolean Rte_IsUpdated_FPAS_WorkSts_FPAS_WorkSts(void)
 *   boolean Rte_IsUpdated_FRTirePress_FRTirePress(void)
 *   boolean Rte_IsUpdated_FRTirePressIndSts_FRTirePressIndSts(void)
 *   boolean Rte_IsUpdated_FRTireTemp_FRTireTemp(void)
 *   boolean Rte_IsUpdated_FRTireTempSts_FRTireTempSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_FFogLmpSts_F_PBOX(void)
 *   boolean Rte_IsUpdated_F_PBOX1_HiBeamSts_F_PBOX(void)
 *   boolean Rte_IsUpdated_F_PBOX1_HoodSts_F_PBOX(void)
 *   boolean Rte_IsUpdated_F_PBOX1_LHeadLmpFailSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_LHiBeamFailSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_LLasHdLmpDiagSig(void)
 *   boolean Rte_IsUpdated_F_PBOX1_LLowBeamFailSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_LasHdLmpSts_F_PBOX(void)
 *   boolean Rte_IsUpdated_F_PBOX1_RHeadLmpFailSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_RHiBeamFailSts(void)
 *   boolean Rte_IsUpdated_F_PBOX1_RLasHdLmpDiagSig(void)
 *   boolean Rte_IsUpdated_F_PBOX1_RLowBeamFailSts(void)
 *   boolean Rte_IsUpdated_FrntELDLckSts_FrntELDLckSts(void)
 *   boolean Rte_IsUpdated_FuelConsumption_FuelConsumption(void)
 *   boolean Rte_IsUpdated_GentrWarnLmpSts_GentrWarnLmpSts(void)
 *   boolean Rte_IsUpdated_HiLowBeamSts_HiLowBeamSts(void)
 *   boolean Rte_IsUpdated_IB_Warn_IB_Warn(void)
 *   boolean Rte_IsUpdated_KL30BRelaySts_KL30BRelaySts(void)
 *   boolean Rte_IsUpdated_MILSts_MILSts(void)
 *   boolean Rte_IsUpdated_PASWorkCmd_PASWorkCmd(void)
 *   boolean Rte_IsUpdated_RCTA_warningReqLeft_RCTA_warningReqLeft(void)
 *   boolean Rte_IsUpdated_RCTA_warningReqRight_RCTA_warningReqRight(void)
 *   boolean Rte_IsUpdated_RLTirePress_RLTirePress(void)
 *   boolean Rte_IsUpdated_RLTirePressIndSts_RLTirePressIndSts(void)
 *   boolean Rte_IsUpdated_RLTireTemp_RLTireTemp(void)
 *   boolean Rte_IsUpdated_RLTireTempSts_RLTireTempSts(void)
 *   boolean Rte_IsUpdated_RPAS_SoundIndcn_RPAS_SoundIndcn(void)
 *   boolean Rte_IsUpdated_RPAS_WorkSts_RPAS_WorkSts(void)
 *   boolean Rte_IsUpdated_RRTirePress_RRTirePress(void)
 *   boolean Rte_IsUpdated_RRTirePressIndSts_RRTirePressIndSts(void)
 *   boolean Rte_IsUpdated_RRTireTemp_RRTireTemp(void)
 *   boolean Rte_IsUpdated_RRTireTempSts_RRTireTempSts(void)
 *   boolean Rte_IsUpdated_RSDS_CTA_Actv_RSDS_CTA_Actv(void)
 *   boolean Rte_IsUpdated_RSDS_ErrSts_RSDS_ErrSts(void)
 *   boolean Rte_IsUpdated_RSDS_IPSoundReq_RSDS_IPSoundReq(void)
 *   boolean Rte_IsUpdated_R_PBOX1_HiPosnBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LRPosnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LTurnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LTurnLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LicPlateLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_ParkLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_PosnLmpOutpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RFogLmpFailSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RFogLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RRPosnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RTurnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RTurnLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RWinHeatgFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RWinHeatgIconRlyCmd(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RvsLmpFailSts(void)
 *   boolean Rte_IsUpdated_Rc_Fuel_Status_Fuel_Status(void)
 *   boolean Rte_IsUpdated_RemoteModSts_RemoteModSts(void)
 *   boolean Rte_IsUpdated_SDWActiveSts_SDWActiveSts(void)
 *   boolean Rte_IsUpdated_SDW_SoundIndcn_SDW_SoundIndcn(void)
 *   boolean Rte_IsUpdated_SG_ABM1_SG_ABM1(void)
 *   boolean Rte_IsUpdated_SG_ABS3_SG_ABS3(void)
 *   boolean Rte_IsUpdated_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_DCT_FD4_SG_DCT_FD4(void)
 *   boolean Rte_IsUpdated_SG_EPB1_SG_EPB1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_SG_EPS1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_FD1_SG_EPS1_FD1(void)
 *   boolean Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_SG_ESP2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC5_IFC_FD2_SG_IFC5_IFC_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(void)
 *   boolean Rte_IsUpdated_SS_Enable_Lamp_SS_Enable_Lamp(void)
 *   boolean Rte_IsUpdated_SS_Fault_Lamp_SS_Fault_Lamp(void)
 *   boolean Rte_IsUpdated_TGS_LEVER_TGS_LEVER(void)
 *   boolean Rte_IsUpdated_TRANS_Warning_LAMP_TRANS_Warning_LAMP(void)
 *   boolean Rte_IsUpdated_TSRSpdLim_TSRSpdLim(void)
 *   boolean Rte_IsUpdated_TSRSpdLimCfdc_TSRSpdLimCfdc(void)
 *   boolean Rte_IsUpdated_TSRSpdLimSts_TSRSpdLimSts(void)
 *   boolean Rte_IsUpdated_TSRSpdLimWarn_TSRSpdLimWarn(void)
 *   boolean Rte_IsUpdated_TSRSts_TSRSts(void)
 *   boolean Rte_IsUpdated_TSRTrfcSignVal_TSRTrfcSignVal(void)
 *   boolean Rte_IsUpdated_T_BOX_FD3_T_BOX_SWUpdSts(void)
 *   boolean Rte_IsUpdated_T_BOX_FD3_T_BOX_SysErrSts(void)
 *   boolean Rte_IsUpdated_TirePressSysFailrIndcn_TirePressSysFailrIndcn(void)
 *   boolean Rte_IsUpdated_TrailerSts_TrailerSts(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   SystemState_RecordType *Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_DMS_FD1_DMSSts(DMSSts data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DistrctnLvlQlty_ACC(DistrctnLvlQlty_ACC data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DistrctnLvl_ACC(DistrctnLvl_ACC data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DrowsnsLvl(DrowsnsLvl data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DrowsnsLvlQlty(DrowsnsLvlQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DrowsnsLvlQlty_ACC(DrowsnsLvlQlty_ACC data)
 *   Std_ReturnType Rte_Write_DMS_FD1_DrowsnsLvl_ACC(DrowsnsLvl_ACC data)
 *   Std_ReturnType Rte_Write_DMS_FD1_GazePosnX(GazePosnX data)
 *   Std_ReturnType Rte_Write_DMS_FD1_GazePosnY(GazePosnY data)
 *   Std_ReturnType Rte_Write_DMS_FD1_GazePosnZ(GazePosnZ data)
 *   Std_ReturnType Rte_Write_DMS_FD1_GenderSts(GenderSts data)
 *   Std_ReturnType Rte_Write_DMS_FD1_GenderStsQlty(GenderStsQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadDetn(HeadDetn data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadPitchAng(HeadPitchAng data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadPosQlty(HeadPosQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadPosnX(HeadPosnX data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadPosnY(HeadPosnY data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadPosnZ(HeadPosnZ data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadRollAng(HeadRollAng data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadRotAngQlty(HeadRotAngQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_HeadYawAng(HeadYawAng data)
 *   Std_ReturnType Rte_Write_DMS_FD1_LEyeOpenSts(LEyeOpenSts data)
 *   Std_ReturnType Rte_Write_DMS_FD1_LEyeOpenStsQlty(LEyeOpenStsQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_REyeOpenSts(REyeOpenSts data)
 *   Std_ReturnType Rte_Write_DMS_FD1_REyeOpenStsQlty(REyeOpenStsQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_RobustGazeAngQlty(RobustGazeAngQlty data)
 *   Std_ReturnType Rte_Write_DMS_FD1_RobustGazePitchAng(RobustGazePitchAng data)
 *   Std_ReturnType Rte_Write_DMS_FD1_RobustGazeYawAng(RobustGazeYawAng data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_CheckSum_IP2(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_ABMWarnLmpFailrSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_ACCErr(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_BattChrgLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_CurrTheme(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_EngOilPressLowLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_Err(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_LagueSet(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VINcompr(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdDisp(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VehSpdUnit(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistance(uint32 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VehTotDistanceValid(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_IP_VelSpdDisp_Mile(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_RollingCounter_IP2(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutputViaGateway_dummy_HUT_IP2_0(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_Cluster_Shutdown_Status_Element(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_SpeedoInfo_IndicateSpeed(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_SpeedoInfo_OverSpdWrnFlg(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_SpeedoInfo_RealSpeed(uint16 data)
 *   Std_ReturnType Rte_Write_Sd_SpeedoInfo_VehRunSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_TachoInfo_EngRunSts(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_TachoInfo_EngSpd(uint16 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_ChimeID_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_DrvModStatusRecord_Element(const DM_tstDrvModStatusRecord *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_MenuSetData_Element(const MenuSetData_t *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedEnable_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_MenuSet_OverSpeedLimit_Element(uint16 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_WarningStsOutput_Element(const WN_WarningStsOutput *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_HsmKeyM_GetAes128Key(uint8 *IV, uint8 *KEY, uint32 *key_len)
 *     Argument IV: uint8* is of type A_17Bytes
 *     Argument KEY: uint8* is of type A_16Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_HsmKeyM_GetCmacKey(uint8 *key, uint32 *key_len)
 *     Argument key: uint8* is of type IdtHsmKeyArray
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_HsmKeyM_GetCmacKeyState(HSM_KeyStateEnum *state)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_HsmKeyM_SetAes128Key(const uint8 *IV, const uint8 *KEY, uint32 key_len)
 *     Argument IV: uint8* is of type A_16Bytes
 *     Argument KEY: uint8* is of type A_16Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_HsmKeyM_SetCmacKey(const uint8 *vin, uint32 vin_len, const uint8 *key, uint32 key_len)
 *     Argument vin: uint8* is of type IdtHsmVinArray
 *     Argument key: uint8* is of type IdtHsmKeyArray
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Hsm_Port_TrngGenerate(uint8 *Trng, uint32 *len)
 *     Argument Trng: uint8* is of type A_16Bytes
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IPC_Send_IPC_Send(uint8 Id_u8, uint8 *data_s, uint16 len_u16, boolean Imm_bool)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IPC_Send_Std_ReturnType
 *   Std_ReturnType Rte_Call_IRTC_Service_GetUTCTimeInMillis(uint64 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_IRTC_Service_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *   Std_ReturnType Rte_Call_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetUpdateTick_Std_ReturnType
 *   Std_ReturnType Rte_Call_ppCS_SWCNormal_ChimeCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ppCS_SWCNormal_TTCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_ppCS_SWCNormal_WrnCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModTTStatus_Operation(uint8 *status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_DM_API_vGetDrvModTTStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModWarningStatus_Operation(uint8 enWarningID, uint8 *status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_DM_API_vGetDrvModWarningStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_Reset_TC_Module_Data_WriteData(uint8 tc_reset_index)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_Reset_TC_Module_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiSR_SensorAorB_Status_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CancelJob(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_JOB_CANCELED, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_E_NOT_OK
 *   Std_ReturnType Rte_Call_CsmDecrypt_CsmPrimitives_AES128_Decrypt_Decrypt(const uint8 *dataBuffer, uint32 dataLength, uint8 *resultBuffer, uint32 *resultLength)
 *     Argument dataBuffer: uint8* is of type Csm_DecryptDataType_CsmPrimitives_AES128_Decrypt
 *     Argument resultBuffer: uint8* is of type Csm_DecryptResultType_CsmPrimitives_AES128_Decrypt
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_BUSY, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_EMPTY, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_NOT_VALID, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_CSM_E_SMALL_BUFFER, RTE_E_CsmDecrypt_CsmPrimitives_AES128_Decrypt_E_NOT_OK
 *   Std_ReturnType Rte_Call_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CancelJob(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_JOB_CANCELED, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_E_NOT_OK
 *   Std_ReturnType Rte_Call_CsmEncrypt_CsmPrimitives_AES128_Encrypt_Encrypt(const uint8 *dataBuffer, uint32 dataLength, uint8 *resultBuffer, uint32 *resultLength)
 *     Argument dataBuffer: uint8* is of type Csm_EncryptDataType_CsmPrimitives_AES128_Encrypt
 *     Argument resultBuffer: uint8* is of type Csm_EncryptResultType_CsmPrimitives_AES128_Encrypt
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_BUSY, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_EMPTY, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_NOT_VALID, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_CSM_E_SMALL_BUFFER, RTE_E_CsmEncrypt_CsmPrimitives_AES128_Encrypt_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Normal(void)
 *   void Rte_Exit_ExclusiveArea_Normal(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_10msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_10msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_10msMainFunction
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_10msMainFunction_
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_10msMainFunction__doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_10msMainFunction_(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_10msMainFunction_
 *********************************************************************************************************************/
	SWC_ChimeMainProcess();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_20msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ACAmbTemp_ACAmbTemp(ACAmbTemp *data)
 *   Std_ReturnType Rte_Read_AccelPedalPosnVldty_AccelPedalPosnVldty(AccelPedalPosnVldty *data)
 *   Std_ReturnType Rte_Read_AccelPedlPosnDiagc_AccelPedlPosnDiagc(AccelPedlPosnDiagc *data)
 *   Std_ReturnType Rte_Read_AutoLmpSwtSts_AutoLmpSwtSts(AutoLmpSwtSts *data)
 *   Std_ReturnType Rte_Read_BrkPedalSts_BCM_BrkPedalSts_BCM(BrkPedalSts_BCM *data)
 *   Std_ReturnType Rte_Read_CCO_Active_CCO_Active(CCO_Active *data)
 *   Std_ReturnType Rte_Read_CCO_TgtVel_CCO_TgtVel(CCO_TgtVel *data)
 *   Std_ReturnType Rte_Read_CCO_Warn_CCO_Warn(CCO_Warn *data)
 *   Std_ReturnType Rte_Read_CouplingThermWarning_CouplingThermWarning(CouplingThermWarning *data)
 *   Std_ReturnType Rte_Read_CruiseCtrlSts_CruiseCtrlSts(CruiseCtrlSts *data)
 *   Std_ReturnType Rte_Read_DCT3_TgtEngSpdIP_TgtEngSpdIP(TgtEngSpdIP *data)
 *   Std_ReturnType Rte_Read_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(TgtEngSpdIPValid *data)
 *   Std_ReturnType Rte_Read_DiagLmpReq_DiagLmpReq(DiagLmpReq *data)
 *   Std_ReturnType Rte_Read_DrowsyDrvDetWarn_DrowsyDrvDetWarn(DrowsyDrvDetWarn *data)
 *   Std_ReturnType Rte_Read_DrvDoorSts_DrvDoorSts(DrvDoorSts *data)
 *   Std_ReturnType Rte_Read_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl(Dyn_PwrSv_Lvl *data)
 *   Std_ReturnType Rte_Read_ECM11_EngSpd_ForIP_EngSpd_ForIP(EngSpd_ForIP *data)
 *   Std_ReturnType Rte_Read_ECM1_EngSpdVldty_EngSpdVldty(EngSpdVldty *data)
 *   Std_ReturnType Rte_Read_ECM_VIN_ECM19_0x3B5(uint8 *data)
 *     Argument data: uint8* is of type ECM_VIN
 *   Std_ReturnType Rte_Read_ECM_VehDstBackup_ECM_VehDstBackup(ECM_VehDstBackup *data)
 *   Std_ReturnType Rte_Read_EMS_AuthenResult_EMS_AuthenResult(EMS_AuthenResult *data)
 *   Std_ReturnType Rte_Read_ESP_HMI_WarningOn_ESP_HMI_WarningOn(ESP_HMI_WarningOn *data)
 *   Std_ReturnType Rte_Read_EWP_Err_EWP_Err(EWP_Err *data)
 *   Std_ReturnType Rte_Read_EngClntTempWarn_EngClntTempWarn(EngClntTempWarn *data)
 *   Std_ReturnType Rte_Read_EngSVSSig_EngSVSSig(EngSVSSig *data)
 *   Std_ReturnType Rte_Read_EngSpdVldty_EngSpdVldty(EngSpdVldty *data)
 *   Std_ReturnType Rte_Read_EngSpd_ForIP_EngSpd_ForIP(EngSpd_ForIP *data)
 *   Std_ReturnType Rte_Read_EspFuncOffSts_mode_EspFuncOffSts_mode(EspFuncOffSts_mode *data)
 *   Std_ReturnType Rte_Read_FLTirePressIndSts_FLTirePressIndSts(FLTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_FLTireTempSts_FLTireTempSts(FLTireTempSts *data)
 *   Std_ReturnType Rte_Read_FRTirePressIndSts_FRTirePressIndSts(FRTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_FRTireTempSts_FRTireTempSts(FRTireTempSts *data)
 *   Std_ReturnType Rte_Read_GPF_Warning_GPF_Warning(GPF_Warning *data)
 *   Std_ReturnType Rte_Read_HiLowBeamSts_HiLowBeamSts(HiLowBeamSts *data)
 *   Std_ReturnType Rte_Read_IB_Warn_IB_Warn(IB_Warn *data)
 *   Std_ReturnType Rte_Read_KL30BRelaySts_KL30BRelaySts(KL30BRelaySts *data)
 *   Std_ReturnType Rte_Read_LRDoorSts_LRDoorSts(LRDoorSts *data)
 *   Std_ReturnType Rte_Read_LvPwrSysErr_LvPwrSysErr(LvPwrSysErr *data)
 *   Std_ReturnType Rte_Read_MILSts_MILSts(MILSts *data)
 *   Std_ReturnType Rte_Read_PassengerDoorSts_PassengerDoorSts(PassengerDoorSts *data)
 *   Std_ReturnType Rte_Read_PowerRlyFault_PowerRlyFault(PowerRlyFault *data)
 *   Std_ReturnType Rte_Read_RLSFailSts_RLSFailSts(RLSFailSts *data)
 *   Std_ReturnType Rte_Read_RLTirePressIndSts_RLTirePressIndSts(RLTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_RLTireTempSts_RLTireTempSts(RLTireTempSts *data)
 *   Std_ReturnType Rte_Read_RRDoorSts_RRDoorSts(RRDoorSts *data)
 *   Std_ReturnType Rte_Read_RRTirePressIndSts_RRTirePressIndSts(RRTirePressIndSts *data)
 *   Std_ReturnType Rte_Read_RRTireTempSts_RRTireTempSts(RRTireTempSts *data)
 *   Std_ReturnType Rte_Read_RSDS_BliSts_RSDS_BliSts(RSDS_BliSts *data)
 *   Std_ReturnType Rte_Read_RSDS_BrkgTrig_RSDS_BrkgTrig(RSDS_BrkgTrig *data)
 *   Std_ReturnType Rte_Read_RSDS_CTA_Actv_RSDS_CTA_Actv(RSDS_CTA_Actv *data)
 *   Std_ReturnType Rte_Read_RSDS_ErrSts_RSDS_ErrSts(RSDS_ErrSts *data)
 *   Std_ReturnType Rte_Read_RSDS_LCAResp_RSDS_LCAResp(RSDS_LCAResp *data)
 *   Std_ReturnType Rte_Read_RSDS_RCW_Trigger_RSDS_RCW_Trigger(RSDS_RCW_Trigger *data)
 *   Std_ReturnType Rte_Read_RSDS_TrailerSts_RSDS_TrailerSts(RSDS_TrailerSts *data)
 *   Std_ReturnType Rte_Read_Rc_Cluster_Shutdown_Status_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_Fuel_Status_Fuel_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_Odo_RunCounter_RunCounter(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_IndicateSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_OverSpdWrnFlg(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_RealSpeed(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_SpeedoInfo_VehRunSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_TachoInfo_EngRunSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_TachoInfo_EngSpd(uint16 *data)
 *   Std_ReturnType Rte_Read_RearELDLckSts_RearELDLckSts(RearELDLckSts *data)
 *   Std_ReturnType Rte_Read_RemoteModSts_RemoteModSts(RemoteModSts *data)
 *   Std_ReturnType Rte_Read_RotSteerWheel_RotSteerWheel(RotSteerWheel *data)
 *   Std_ReturnType Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(SG_ACC4_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(SG_IFC4_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_SS_Enable_Lamp_SS_Enable_Lamp(SS_Enable_Lamp *data)
 *   Std_ReturnType Rte_Read_SS_Fault_Lamp_SS_Fault_Lamp(SS_Fault_Lamp *data)
 *   Std_ReturnType Rte_Read_SS_Screen_tip_SS_Screen_tip(uint8 *data)
 *   Std_ReturnType Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(Stat_PwrSv_Lvl *data)
 *   Std_ReturnType Rte_Read_SysPowerMod_SysPowerMod(SysPowerMod *data)
 *   Std_ReturnType Rte_Read_TSRSpdLim_TSRSpdLim(TSRSpdLim *data)
 *   Std_ReturnType Rte_Read_TSRSpdLimSts_TSRSpdLimSts(TSRSpdLimSts *data)
 *   Std_ReturnType Rte_Read_TSRSpdLimWarn_TSRSpdLimWarn(TSRSpdLimWarn *data)
 *   Std_ReturnType Rte_Read_TSRSts_TSRSts(TSRSts *data)
 *   Std_ReturnType Rte_Read_TSRTrfcSignVal_TSRTrfcSignVal(TSRTrfcSignVal *data)
 *   Std_ReturnType Rte_Read_TgtCrsVehSpd_TgtCrsVehSpd(uint8 *data)
 *   Std_ReturnType Rte_Read_TirePressSysFailrIndcn_TirePressSysFailrIndcn(TirePressSysFailrIndcn *data)
 *   Std_ReturnType Rte_Read_TrailerSts_TrailerSts(TrailerSts *data)
 *   Std_ReturnType Rte_Read_TranPMode_Sts_TranPMode_Sts(TranPMode_Sts *data)
 *   Std_ReturnType Rte_Read_TrunkSts_TrunkSts(TrunkSts *data)
 *   Std_ReturnType Rte_Read_WPC_FaultSts_WPC_FaultSts(WPC_FaultSts *data)
 *   Std_ReturnType Rte_Read_WPC_PhoneReminder_WPC_PhoneReminder(WPC_PhoneReminder *data)
 *   Std_ReturnType Rte_Read_WarnEngStrtNotMeet_WarnEngStrtNotMeet(WarnEngStrtNotMeet *data)
 *   Std_ReturnType Rte_Read_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit(WarnKeyInCarWhenExit *data)
 *   Std_ReturnType Rte_Read_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn(WarnPowerNotInOffPosn *data)
 *   Std_ReturnType Rte_Read_WarnVldKeyNotFound_WarnVldKeyNotFound(WarnVldKeyNotFound *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_OdoParament_Element(s_OdoRteGetParament_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(TC_MODULE_OUTPUT_DATA_STRUCT_RTE *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCNormal_TachoInfo_Element(s_TachoInfo_t *data)
 *   boolean Rte_IsUpdated_CCO_Active_CCO_Active(void)
 *   boolean Rte_IsUpdated_CruiseCtrlSts_CruiseCtrlSts(void)
 *   boolean Rte_IsUpdated_DCT3_TgtEngSpdIP_TgtEngSpdIP(void)
 *   boolean Rte_IsUpdated_DCT3_TgtEngSpdIPValid_TgtEngSpdIPValid(void)
 *   boolean Rte_IsUpdated_ECM_VIN_ECM19_0x3B5(void)
 *   boolean Rte_IsUpdated_ECM_VehDstBackup_ECM_VehDstBackup(void)
 *   boolean Rte_IsUpdated_ESP_HMI_WarningOn_ESP_HMI_WarningOn(void)
 *   boolean Rte_IsUpdated_EngClntTempWarn_EngClntTempWarn(void)
 *   boolean Rte_IsUpdated_EngSVSSig_EngSVSSig(void)
 *   boolean Rte_IsUpdated_FLTirePressIndSts_FLTirePressIndSts(void)
 *   boolean Rte_IsUpdated_FLTireTempSts_FLTireTempSts(void)
 *   boolean Rte_IsUpdated_FRTirePressIndSts_FRTirePressIndSts(void)
 *   boolean Rte_IsUpdated_FRTireTempSts_FRTireTempSts(void)
 *   boolean Rte_IsUpdated_HiLowBeamSts_HiLowBeamSts(void)
 *   boolean Rte_IsUpdated_IB_Warn_IB_Warn(void)
 *   boolean Rte_IsUpdated_KL30BRelaySts_KL30BRelaySts(void)
 *   boolean Rte_IsUpdated_MILSts_MILSts(void)
 *   boolean Rte_IsUpdated_RLTirePressIndSts_RLTirePressIndSts(void)
 *   boolean Rte_IsUpdated_RLTireTempSts_RLTireTempSts(void)
 *   boolean Rte_IsUpdated_RRTirePressIndSts_RRTirePressIndSts(void)
 *   boolean Rte_IsUpdated_RRTireTempSts_RRTireTempSts(void)
 *   boolean Rte_IsUpdated_RSDS_CTA_Actv_RSDS_CTA_Actv(void)
 *   boolean Rte_IsUpdated_RSDS_ErrSts_RSDS_ErrSts(void)
 *   boolean Rte_IsUpdated_Rc_Fuel_Status_Fuel_Status(void)
 *   boolean Rte_IsUpdated_RemoteModSts_RemoteModSts(void)
 *   boolean Rte_IsUpdated_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(void)
 *   boolean Rte_IsUpdated_SS_Enable_Lamp_SS_Enable_Lamp(void)
 *   boolean Rte_IsUpdated_SS_Fault_Lamp_SS_Fault_Lamp(void)
 *   boolean Rte_IsUpdated_TSRSpdLim_TSRSpdLim(void)
 *   boolean Rte_IsUpdated_TSRSpdLimSts_TSRSpdLimSts(void)
 *   boolean Rte_IsUpdated_TSRSpdLimWarn_TSRSpdLimWarn(void)
 *   boolean Rte_IsUpdated_TSRSts_TSRSts(void)
 *   boolean Rte_IsUpdated_TSRTrfcSignVal_TSRTrfcSignVal(void)
 *   boolean Rte_IsUpdated_TirePressSysFailrIndcn_TirePressSysFailrIndcn(void)
 *   boolean Rte_IsUpdated_TrailerSts_TrailerSts(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   SystemState_RecordType *Rte_IRead_Common_Normal_20msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Sd_Odo_RunCounter_RunCounter(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_SpeedoInfo_Element(const s_SpeedoInfo_t *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCNormal_TachoInfo_Element(const s_TachoInfo_t *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IPC_Send_IPC_Send(uint8 Id_u8, uint8 *data_s, uint16 len_u16, boolean Imm_bool)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IPC_Send_Std_ReturnType
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *   Std_ReturnType Rte_Call_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetUpdateTick_Std_ReturnType
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModTTStatus_Operation(uint8 *status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_DM_API_vGetDrvModTTStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_DM_API_vGetDrvModWarningStatus_Operation(uint8 enWarningID, uint8 *status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_DM_API_vGetDrvModWarningStatus_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCNormal_Reset_TC_Module_Data_WriteData(uint8 tc_reset_index)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_tiCS_Reset_TC_Module_Data_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_Normal_20msMainFunction_tiSR_Power_Out_SystemStateOut(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction
 *********************************************************************************************************************/
  TT_API_vKSTimeTask();  

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_20msMainFunction_
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CanFrameCounter_Can_ABS3_Counter(CanFrameCounterType *counter)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CanFrameCounter_Can_ECM2_Counter(CanFrameCounterType *counter)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(CanFrameCounterType *counter)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_TC_Data_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction__doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_
 *********************************************************************************************************************/
	Odo_Api_IrqTimeTask();
	Odo_Api_TimeTask();
	//Fuel_Api_Init();
	TC_Api_Accum_Collect_Task();
	TC_Api_Process_Task();	
	TC_NE_Process_Task();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_20msMainFunction_A
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AVASDTCResults_AVASDTC(AVASDTCRet *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_A_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_A(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_A
 *********************************************************************************************************************/
	WN_API_vKSTimeTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_20msMainFunction_B
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_B_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_20msMainFunction_B(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_20msMainFunction_B
 *********************************************************************************************************************/
	SM_API_vKSTimeTask();
	TM_API_vKSTimeTask();
	DM_API_vDrvModeAppTimeTask();
	CL_API_vKSTimeTask();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_5msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Normal(void)
 *   void Rte_Exit_ExclusiveArea_Normal(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_5msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_5msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_5msMainFunction
 *********************************************************************************************************************/
	Chime_Api_CallbackTask();
	Chime_SlowRateTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Init
 *********************************************************************************************************************/
  Fuel_Api_ColdInit();
  TT_API_vKSColdInit();
  WN_API_vKSColdInit();
  SM_API_vKSColdInit();
  Odo_Api_ColdInit();
  TM_API_vKSColdInit();
  TC_Api_KSColdInit();
  Chime_KSColdInit();
  TPMSMdl_TPMS_cold_init();
  DM_API_vKSColdInit();
  //MenuSetMdl_MenuSet_cold_init();
  CL_API_vKSColdInit();
  TC_NE_Process_Init();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_List_Deinit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Deinit> of PortPrototype <Common_Normal_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Normal_List_Deinit(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_List_Deinit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_List_Deinit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_List_Deinit
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_List_Int
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Int> of PortPrototype <Common_Normal_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Normal_List_Int(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_List_Int_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_List_Int(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_List_Int
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_Nomal2Standby_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Nomal2StandbyCallback> of PortPrototype <rpCS_Common_Nomal_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Normal_Nomal2Standby_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Nomal2Standby_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_Nomal2Standby_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Nomal2Standby_Callbcak
 *********************************************************************************************************************/
  TT_API_Set_PreOffPowerMode_Status();
  WN_API_Set_PrePowerMode_Status();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Normal_Standby2Nomal_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Standby2NomalCallback> of PortPrototype <rpCS_Common_Nomal_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Normal_Standby2Nomal_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Standby2Nomal_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Common_Normal_Standby2Nomal_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Normal_Standby2Nomal_Callbcak
 *********************************************************************************************************************/
  TT_API_Set_PreOnPowerMode_Status();
  WN_API_Set_PrePowerMode_Status();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CsmJob_Aes128_Decrypt_Cbk_Callback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification
 *********************************************************************************************************************/
	if(e_OdoHsmStatus_Start == Odo_HSMDecryptFlag_Get())
	{
		if(0 == result)
		{
			Odo_HSMDecryptFlag_Clear(e_OdoHsmStatus_Success);
		}
		else
		{
			Odo_HSMDecryptFlag_Clear(e_OdoHsmStatus_Error);
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CsmJob_Aes128_Encrypt_Cbk_Callback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification
 *********************************************************************************************************************/
	if(e_OdoHsmStatus_Start == Odo_HSMEncryptFlag_Get())
	{
		if(0 == result)
		{
			Odo_HSMEncryptFlag_Clear(e_OdoHsmStatus_Success);
		}
		else
		{
			Odo_HSMEncryptFlag_Clear(e_OdoHsmStatus_Error);
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DM_API_vGetDrvModTTStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_DM_API_vGetDrvModTTStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DM_API_vGetDrvModTTStatus(uint8 *status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_tiCS_DM_API_vGetDrvModTTStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DM_API_vGetDrvModTTStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_Normal_CODE) DM_API_vGetDrvModTTStatus(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DM_API_vGetDrvModTTStatus (returns application error)
 *********************************************************************************************************************/
	(void)status;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DM_API_vGetDrvModWarningStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_DM_API_vGetDrvModWarningStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DM_API_vGetDrvModWarningStatus(uint8 enWarningID, uint8 *status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_tiCS_DM_API_vGetDrvModWarningStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DM_API_vGetDrvModWarningStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_Normal_CODE) DM_API_vGetDrvModWarningStatus(uint8 enWarningID, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DM_API_vGetDrvModWarningStatus (returns application error)
 *********************************************************************************************************************/
	(void)enWarningID;
	(void)status;
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EOL_GetReadHardInputForCluster> of PortPrototype <EOL_ReadDID0xFDD8>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(uint8 *arg)
 *     Argument arg: uint8* is of type EOL_6Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster
 *********************************************************************************************************************/
	SWC_API_RTE_EOL_HardInput_For_Cluster(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Fuel_Api_ParamentGetCsPort_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_Fuel_Api_ParamentGetCsPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Fuel_Api_ParamentGetCsPort_Operation(uint8 *arg)
 *     Argument arg: uint8* is of type Diag_9Bytes
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Fuel_Api_ParamentGetCsPort_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Fuel_Api_ParamentGetCsPort_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Fuel_Api_ParamentGetCsPort_Operation
 *********************************************************************************************************************/
	Fuel_SWC_API_RTE_Diag_Read_Fuel_Data(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished
 *********************************************************************************************************************/
	if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Matain_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Matain_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Matain_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_Matain_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("MaintainOdo write error with callback");
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Matain_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_Matain_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished
 *********************************************************************************************************************/
	if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO1_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO1_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO1_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO1_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO1_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			
			(void)SWC_ODO_ERROR_LOG("1 Block write error");
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO1_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO1_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished
 *********************************************************************************************************************/
if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO2_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO2_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO2_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO2_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO2_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("2 Block write error");
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO2_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO2_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished
 *********************************************************************************************************************/
if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO3_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO3_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO3_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO3_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO3_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("3 Block write error");
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO3_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO3_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished
 *********************************************************************************************************************/
	if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO4_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO4_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO4_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO4_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO4_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("4 Block write error");
			if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO4_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO4_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished
 *********************************************************************************************************************/
	if(NVM_WRITE_BLOCK == ServiceId)
		{
			if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO5_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
			{
				if(NVM_REQ_OK == JobResult)
				{
					Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO5_NVM_BLOCK).Process(TRUE);
				}
				else
				{
					Odo_GetBlockWriteCallback((uint8)e_OdoBlock_ODO5_NVM_BLOCK).Process(FALSE);
				}
			}
			if(NVM_REQ_OK == JobResult)
			{
				if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO5_NVM_BLOCK))
				{
					Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO5_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
				}
			}
			else
			{
				(void)SWC_ODO_ERROR_LOG("5 Block write error");
				if(((uint8)e_OdoWriteSts_Request) == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_ODO5_NVM_BLOCK))
				{
					Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_ODO5_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
				}
			}
		}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Config_Data_JobFinished
 *********************************************************************************************************************/
	(void)ServiceId;
	(void)JobResult;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_TC_Data_JobFinished
 *********************************************************************************************************************/
	(void)ServiceId;
	(void)JobResult;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_Trip>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished
 *********************************************************************************************************************/
	if(NVM_WRITE_BLOCK == ServiceId)
	{
		if(Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Trip_NVM_BLOCK).Process != ODO_ADAPT_NULL_PTRFUN)
		{
			if(NVM_REQ_OK == JobResult)
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Trip_NVM_BLOCK).Process(TRUE);
			}
			else
			{
				Odo_GetBlockWriteCallback((uint8)e_OdoBlock_Trip_NVM_BLOCK).Process(FALSE);
			}
		}
		if(NVM_REQ_OK == JobResult)
		{
			if((uint8)e_OdoWriteSts_Request == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Trip_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_Trip_NVM_BLOCK),((uint8)e_OdoWriteSts_Success));
			}
		}
		else
		{
			(void)SWC_ODO_ERROR_LOG("Trip Block write error");
			if((uint8)e_OdoWriteSts_Request == Odo_Api_ResetOdoFlag_Get((uint8)e_OdoBlock_Trip_NVM_BLOCK))
			{
				Odo_Api_ResetOdoFlag_Set(((uint8)e_OdoBlock_Trip_NVM_BLOCK),((uint8)e_OdoWriteSts_Fail));
			}
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Menu>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Menu_JobFinished
 *********************************************************************************************************************/
	(void)ServiceId;
	(void)JobResult;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Odo_Api_ParamentGetCsPortGetData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_Odo_Api_ParamentGetCsPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Odo_Api_ParamentGetCsPortGetData(uint8 Id, uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Odo_Api_ParamentGetCsPortGetData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) Odo_Api_ParamentGetCsPortGetData(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Odo_Api_ParamentGetCsPortGetData
 *********************************************************************************************************************/
	Odo_Api_ParamentGetCsPort(Id,Data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RTE_Odo_Api_ParamentSetFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_OdoSetParament>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RTE_Odo_Api_ParamentSetFunction(uint8 SetId, uint32 *data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_tiCS_OdoSetParament_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_Odo_Api_ParamentSetFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_Normal_CODE) RTE_Odo_Api_ParamentSetFunction(uint8 SetId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_Odo_Api_ParamentSetFunction (returns application error)
 *********************************************************************************************************************/
	Std_ReturnType result;
	result = Odo_Api_ParamentSetFunction(SetId,data);

	return result;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RTE_TC_API_Set_TC_Module_Reset_Data
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <ppCS_SWCNormal_Reset_TC_Module_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RTE_TC_API_Set_TC_Module_Reset_Data(uint8 tc_reset_index)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_tiCS_Reset_TC_Module_Data_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TC_API_Set_TC_Module_Reset_Data_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_Normal_CODE) RTE_TC_API_Set_TC_Module_Reset_Data(uint8 tc_reset_index) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TC_API_Set_TC_Module_Reset_Data (returns application error)
 *********************************************************************************************************************/
  TC_RTE_API_Set_TC_Module_Reset_Data(tc_reset_index);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SWCNormal_SensorAorB_Status_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <svCS_SWCNormal_SensorAorB_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SWCNormal_SensorAorB_Status_Operation(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_tiSR_SensorAorB_Status_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SWCNormal_SensorAorB_Status_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_Normal_CODE) SWCNormal_SensorAorB_Status_Operation(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SWCNormal_SensorAorB_Status_Operation (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType result=0;
  result = ((Fuel_Api_Get_SensorAorB_Status_Change()==TRUE)?1u:0u);

  return result;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TC_Api_ParamentGetCsPort_1_Operation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_TC_Api_ParamentGetCsPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TC_Api_ParamentGetCsPort_1_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_Api_ParamentGetCsPort_1_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) TC_Api_ParamentGetCsPort_1_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_Api_ParamentGetCsPort_1_Operation
 *********************************************************************************************************************/
	TC_API_RTE_Diag_Read_TC_Data(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TC_EnergyInfo
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_TC_EnergyInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TC_EnergyInfo(EnergyInfoDataType Id, uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_EnergyInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) TC_EnergyInfo(EnergyInfoDataType Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_EnergyInfo
 *********************************************************************************************************************/
    TC_Api_Emergy_Get_IVI_Alive_Respone(Id,Data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TC_EnergyInfoResp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_TC_EnergyInfoResp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TC_EnergyInfoResp(EnergyInfoDataType Id, boolean Resp)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_EnergyInfoResp_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) TC_EnergyInfoResp(EnergyInfoDataType Id, boolean Resp) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TC_EnergyInfoResp
 *********************************************************************************************************************/
	(void)Id;
	(void)Resp;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_SWCNormal_Fuel_DualTank_EnduranceMileage_CallBack
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_TC_Api_ParamentGetCsPort>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ppCS_SWCNormal_Fuel_DualTank_EnduranceMileage_CallBack(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_Fuel_DualTank_EnduranceMileage_CallBack_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) ppCS_SWCNormal_Fuel_DualTank_EnduranceMileage_CallBack(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_Fuel_DualTank_EnduranceMileage_CallBack
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_SWCNormal_OdoTimeSync_CallBack
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallBack> of PortPrototype <ppCS_SWCNormal_OdoTimeSync>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ppCS_SWCNormal_OdoTimeSync_CallBack(sint64 pre_time, sint64 now_time)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_OdoTimeSync_CallBack_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) ppCS_SWCNormal_OdoTimeSync_CallBack(sint64 pre_time, sint64 now_time) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_OdoTimeSync_CallBack
 *********************************************************************************************************************/

	ODO_callback(pre_time,now_time);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_SWCNormal_ReceiveMenuTheme_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <ppCS_SWCNormal_ReceiveMenuTheme>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ppCS_SWCNormal_ReceiveMenuTheme_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_ReceiveMenuTheme_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) ppCS_SWCNormal_ReceiveMenuTheme_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_ReceiveMenuTheme_Callback
 *********************************************************************************************************************/
	(void)data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_TtToChime
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <ppCS_SWCNormal_TtToChime>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ppCS_TtToChime(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_TtToChime_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) ppCS_TtToChime(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_TtToChime
 *********************************************************************************************************************/
	Chime_Api_TTFlashCallback(data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_GetTankResistanceValue_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_GetTankResistanceValue>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_GetTankResistanceValue_Operation(uint8 *TankResistanceValue)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_GetTankResistanceValue_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_GetTankResistanceValue_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) TankResistanceValue) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_GetTankResistanceValue_Operation
 *********************************************************************************************************************/
	(void)TankResistanceValue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ChimeCallback_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <svCS_SWCNormal_ChimeCallback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ChimeCallback_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ChimeCallback_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ChimeCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ChimeCallback_Operation
 *********************************************************************************************************************/
	Chime_Api_ChimeCallback(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_HMIResetTC_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_HMIResetTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_HMIResetTC_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_HMIResetTC_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_HMIResetTC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_HMIResetTC_Callback
 *********************************************************************************************************************/
	Odo_HMIResetTcCallback(data);	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveAdasStatus_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveAdasStatus>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveAdasStatus_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveAdasStatus_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveAdasStatus_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveAdasStatus_Callback
 *********************************************************************************************************************/
	(void)data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveHMIPowerMode_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveHMIPowerMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveHMIPowerMode_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveHMIPowerMode_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveHMIPowerMode_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveHMIPowerMode_Callback
 *********************************************************************************************************************/
	Chime_Api_HMIPowerCallback(data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveMenuSetting_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveMenuSetting>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveMenuSetting_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveMenuSetting_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveMenuSetting_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveMenuSetting_Callback
 *********************************************************************************************************************/

	IPC_API_ReceiveMenuSettingCallback(data);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveOffroadInfo_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveOffroadInfo>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveOffroadInfo_Callback(uint8 *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveOffroadInfo_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveOffroadInfo_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveOffroadInfo_Callback
 *********************************************************************************************************************/

    IPC_API_ReceiveMenuOffroadInfoCallback(data);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveSafetyGearCRCCallback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveSafetyGearCRC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveSafetyGearCRCCallback(uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveSafetyGearCRCCallback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveSafetyGearCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveSafetyGearCRCCallback
 *********************************************************************************************************************/
	(void)Data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_ReceiveSafetyTTCRCCallback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCNormal_ReceiveSafetyTTCRC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_ReceiveSafetyTTCRCCallback(uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveSafetyTTCRCCallback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_ReceiveSafetyTTCRCCallback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_ReceiveSafetyTTCRCCallback
 *********************************************************************************************************************/
	(void)Data;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_TTCallback_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <svCS_SWCNormal_TTCallback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_TTCallback_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_TTCallback_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_TTCallback_Operation
 *********************************************************************************************************************/
	Chime_Api_TTCallback(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCNormal_WrnCallback_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <svCS_SWCNormal_WrnCallback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCNormal_WrnCallback_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_WrnCallback_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Normal_CODE) svCS_SWCNormal_WrnCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCNormal_WrnCallback_Operation
 *********************************************************************************************************************/
	Chime_Api_WrCallback(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:Odo_Api_TimeTask)  *******************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Odo_Api_IrqTimeTask)  ****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Odo_Api_IrqTimeTask_doc)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Odo_Api_TimeTask_doc)  ********************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Odo_Api_PkgRrobinTask)  **************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Odo_Api_PkgRrobinTask_doc)  ***************************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:ODO_MainFunction)  *******************************/
	static uint8 Odo_Runable_test = 0;
	if(!Odo_Runable_test)
	{
		Odo_Runable_test = 1;
		Odo_Api_ColdInit();
	}
	else
	{
		Odo_Api_IrqTimeTask();
		Odo_Api_TimeTask();
	}
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Tacho_MainFunction_doc)  ******************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:TC_MainFunction)  ********************************/
Fuel_Api_Main_Task();


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:TC_MainFunction_doc)  *********************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Tacho_MainFunction)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Common_Normal_MainFunction_doc)  **********************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Speedo_MainFunction_doc)  *****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Common_Normal_MainFunction)  *********************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Speedo_MainFunction)  ****************************/
  TT_API_vKSTimeTask();

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:ODO_MainFunction_doc)  ********************************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:Common_Normal_50msMainFunction)  *****************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Common_Normal_50msMainFunction_doc)  ******************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:Common_Normal_50msMainFunction_)  ****************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Common_Normal_50msMainFunction__doc)  *****************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:Odo_Api_ParamentGetCsPort)  **********************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Odo_Api_ParamentGetCsPort_doc)  ***********************/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:svCS_SWCNormal_SensorAorB_Status_Operation)  *****/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:svCS_SWCNormal_SensorAorB_Status_Operation_doc)  ******/


/***  End of saved code  ************************************************************************************/
#endif

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
