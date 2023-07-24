/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *  This software is copyright protected and proprietary to Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  Noch Automotive Technology(Shanghai) Co. , Ltd. grants to you only those rights as set out in the license 
 *  conditions.All other rights remain with Noch Automotive Technology(Shanghai) Co. , Ltd.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *                 File:  ComEx_Lcfg.c
 *            Generator:  ComEx Code Generator V1.0
 *     Description file:  ComEx_Lcfg.c.tem
 *          Description:  ComEx source file
 *               Author:  ComEx Code Generator V1.0
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "ComEx_Cfg.h"
#include "ComEx_Type.h"

extern void CNA_SignalCallBack(uint16 signalId);
const ComEx_RxSigInfoType ComEx_RxSigInfo[ComEx_RxSignalSize] = 
{
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 0u/* AppAccBytePosition */}, /*CheckSum_ABM1*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1u/* AppAccBytePosition */}, /*SecRowLSBR*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2u/* AppAccBytePosition */}, /*AirbFailLmpCmd*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3u/* AppAccBytePosition */}, /*SecRowMidSBR*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4u/* AppAccBytePosition */}, /*DrvSBR*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 5u/* AppAccBytePosition */}, /*SecRowRSBR*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 6u/* AppAccBytePosition */}, /*PassSBR*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 7u/* AppAccBytePosition */}, /*PassSBR_Visual*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 8u/* AppAccBytePosition */}, /*DrvSBR_Visual*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 9u/* AppAccBytePosition */}, /*SecRowLSBR_Visual*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 10u/* AppAccBytePosition */}, /*SecRowMidSBR_Visual*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 11u/* AppAccBytePosition */}, /*SecRowRSBR_Visual*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 12u/* AppAccBytePosition */}, /*CrashOutputSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 13u/* AppAccBytePosition */}, /*RSCAOFFSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 14u/* AppAccBytePosition */}, /*RollingCounter_ABM1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 15u/* AppAccBytePosition */}, /*ABM1_0x351*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 3u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 23u/* AppAccBytePosition */}, /*VehLgtAccel*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 3u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 25u/* AppAccBytePosition */}, /*VehLatAccel*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 4u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 27u/* AppAccBytePosition */}, /*VehYawRate*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 29u/* AppAccBytePosition */}, /*VehLgtAccelVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 30u/* AppAccBytePosition */}, /*VehLatAccelVld*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 31u/* AppAccBytePosition */}, /*VehDynYawRateVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 32u/* AppAccBytePosition */}, /*ABM2_0x245*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 40u/* AppAccBytePosition */}, /*FLWheelDriveDirection*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 41u/* AppAccBytePosition */}, /*FRWheelDriveDirection*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 42u/* AppAccBytePosition */}, /*ABS1_0x231*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 50u/* AppAccBytePosition */}, /*RLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 51u/* AppAccBytePosition */}, /*RLWheelSpd*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 53u/* AppAccBytePosition */}, /*RRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 54u/* AppAccBytePosition */}, /*RRWheelSpd*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 56u/* AppAccBytePosition */}, /*RLWheelDriveDirection*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 57u/* AppAccBytePosition */}, /*RRWheelDriveDirection*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 58u/* AppAccBytePosition */}, /*ABS2_0x246*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 66u/* AppAccBytePosition */}, /*InCarTemp*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 67u/* AppAccBytePosition */}, /*ACAQSEnaSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 68u/* AppAccBytePosition */}, /*ACOperMod*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 69u/* AppAccBytePosition */}, /*ACAIUEnaSts*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 70u/* AppAccBytePosition */}, /*ACDrvAirDistriMod*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 71u/* AppAccBytePosition */}, /*ACSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 72u/* AppAccBytePosition */}, /*ACFrntPassTempSteplessSetEnaSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 73u/* AppAccBytePosition */}, /*ACDrvTempSteplessSetEnaSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 74u/* AppAccBytePosition */}, /*ACEEMSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 75u/* AppAccBytePosition */}, /*ACDrvTemp_ETC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 76u/* AppAccBytePosition */}, /*AC1_0x29D*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 84u/* AppAccBytePosition */}, /*ACFrntDefrstSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 85u/* AppAccBytePosition */}, /*ACHMIDispCmd*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 86u/* AppAccBytePosition */}, /*ACFrntBlwrSpd*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 87u/* AppAccBytePosition */}, /*ACOpenSts*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 88u/* AppAccBytePosition */}, /*ACDualModEnaSts*/
  {6u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 89u/* AppAccBytePosition */}, /*ACDrvTemp_ATC*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 90u/* AppAccBytePosition */}, /*ACAmbTemp*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 91u/* AppAccBytePosition */}, /*ACAirInletSts*/
  {6u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 92u/* AppAccBytePosition */}, /*ACFrntPasstTemp_ATC*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 93u/* AppAccBytePosition */}, /*ACAutoModEnaSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 94u/* AppAccBytePosition */}, /*ACCmprEnaSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 95u/* AppAccBytePosition */}, /*ACRearWinHeatSts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 96u/* AppAccBytePosition */}, /*AC_FrntWinHeatEnaSts*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 97u/* AppAccBytePosition */}, /*AC_FrntWinHeatDislSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 98u/* AppAccBytePosition */}, /*AC2_0x385*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 106u/* AppAccBytePosition */}, /*L_PM25InAirQltyLvl*/
  {10u/*BitLength*/, 27u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 107u/* AppAccBytePosition */}, /*L_PM25InDens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 109u/* AppAccBytePosition */}, /*AC6_0x2F8*/
  {7u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 117u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dy*/
  {9u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 118u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dx*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 120u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Typ*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 121u/* AppAccBytePosition */}, /*ACC_LeTargrt_02_Detn*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 122u/* AppAccBytePosition */}, /*ACC_RiTargrt_02_Detn*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 123u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dy*/
  {9u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 124u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dx*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 126u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Typ*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 127u/* AppAccBytePosition */}, /*ACC_LeTgtObjBarDisp*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 128u/* AppAccBytePosition */}, /*ACC_RiTgtObjBarDisp*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 129u/* AppAccBytePosition */}, /*Checksum_ACC3*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 130u/* AppAccBytePosition */}, /*ICA_HandsOffResp*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 131u/* AppAccBytePosition */}, /*ALC_Resp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 132u/* AppAccBytePosition */}, /*HWA_Resp*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 133u/* AppAccBytePosition */}, /*ISL_Resp*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 134u/* AppAccBytePosition */}, /*HWA_SnvtySet_Resp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 135u/* AppAccBytePosition */}, /*Longctrl_VehHldReq_DVR*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 136u/* AppAccBytePosition */}, /*Longctrl_DrvOFF_Req_DVR*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 137u/* AppAccBytePosition */}, /*Longctrl_ModSts_DVR*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 138u/* AppAccBytePosition */}, /*Longctrl_Decel_Req_DVR*/
  {16u/*BitLength*/, 96u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 139u/* AppAccBytePosition */}, /*Longctrl_EngTrqReq_DVR*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 141u/* AppAccBytePosition */}, /*Longctrl_EngTrqReqActive_DVR*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 142u/* AppAccBytePosition */}, /*Longctrl_DecelToStopReq_DVR*/
  {2u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 143u/* AppAccBytePosition */}, /*Longctrl_ParkShiftReq_DVR*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 144u/* AppAccBytePosition */}, /*Longctrl_Decel_ReqValue_DVR*/
  {2u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 145u/* AppAccBytePosition */}, /*ALC_InterSysInfoDisp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 146u/* AppAccBytePosition */}, /*RollingCounter_ACC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 147u/* AppAccBytePosition */}, /*Checksum_ACC4*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 148u/* AppAccBytePosition */}, /*ACC_ObjDetecte*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 149u/* AppAccBytePosition */}, /*ACC_TakeOverReq*/
  {5u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 150u/* AppAccBytePosition */}, /*ACC_InterSysInfoDisp*/
  {5u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 151u/* AppAccBytePosition */}, /*ACC_ModDisp*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 152u/* AppAccBytePosition */}, /*ACC_FctSts*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 153u/* AppAccBytePosition */}, /*ACC_TgtObjBarDisp*/
  {2u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 154u/* AppAccBytePosition */}, /*Longctrl_HazActv*/
  {3u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 155u/* AppAccBytePosition */}, /*TJA_ACC_SelSts*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 156u/* AppAccBytePosition */}, /*CruCha_ModDisp*/
  {3u/*BitLength*/, 161u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 157u/* AppAccBytePosition */}, /*TJA_ICA_InterSysInfoDisp*/
  {3u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 158u/* AppAccBytePosition */}, /*TJA_ICA_ModDisp*/
  {2u/*BitLength*/, 171u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 159u/* AppAccBytePosition */}, /*ISL_InterSysInfoDisp*/
  {3u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 160u/* AppAccBytePosition */}, /*ACC_TimeGapSet*/
  {8u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 161u/* AppAccBytePosition */}, /*ACC_SpdSetValue*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 162u/* AppAccBytePosition */}, /*CruChar_InterSysInfoDisp*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 163u/* AppAccBytePosition */}, /*RollingCounter_ACC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 164u/* AppAccBytePosition */}, /*Checksum_ACC8*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 165u/* AppAccBytePosition */}, /*HWA_ModDisp*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 166u/* AppAccBytePosition */}, /*HWA_InterSysInfoDisp*/
  {2u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 167u/* AppAccBytePosition */}, /*HWA_LaneChange*/
  {3u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 168u/* AppAccBytePosition */}, /*HWA_LaneChangeReq*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 169u/* AppAccBytePosition */}, /*HWA_Warning*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 170u/* AppAccBytePosition */}, /*RollingCounter_ACC8*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 171u/* AppAccBytePosition */}, /*Checksum_ACC6*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 172u/* AppAccBytePosition */}, /*ACC_PotentialTgtDy*/
  {9u/*BitLength*/, 287u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 173u/* AppAccBytePosition */}, /*ACC_PotentialTgtDx*/
  {2u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 175u/* AppAccBytePosition */}, /*ACC_RlvTgtDetn*/
  {2u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 176u/* AppAccBytePosition */}, /*ACC_EgoStatus*/
  {3u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 177u/* AppAccBytePosition */}, /*ACC_RlvTgtTyp*/
  {8u/*BitLength*/, 288u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 178u/* AppAccBytePosition */}, /*ACC_RlvTgtDy*/
  {9u/*BitLength*/, 311u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 179u/* AppAccBytePosition */}, /*ACC_RlvTgtDx*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 181u/* AppAccBytePosition */}, /*ACC_PotentialTgtDetn*/
  {3u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 182u/* AppAccBytePosition */}, /*ACC_PotentialTgtTyp*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 183u/* AppAccBytePosition */}, /*RollingCounter_ACC6*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 184u/* AppAccBytePosition */}, /*Checksum_ACC7*/
  {3u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 185u/* AppAccBytePosition */}, /*Request_driveoff*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 186u/* AppAccBytePosition */}, /*ACC_LeTgtDy*/
  {9u/*BitLength*/, 351u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 187u/* AppAccBytePosition */}, /*ACC_LeTgtDx*/
  {3u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 189u/* AppAccBytePosition */}, /*ACC_LeTgtTyp*/
  {2u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 190u/* AppAccBytePosition */}, /*ACC_LeTargrtDection*/
  {2u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 191u/* AppAccBytePosition */}, /*ACC_RiTargrtDetn*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 192u/* AppAccBytePosition */}, /*ACC_RiTgtDy*/
  {9u/*BitLength*/, 375u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 193u/* AppAccBytePosition */}, /*ACC_RiTgtDx*/
  {3u/*BitLength*/, 372u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 195u/* AppAccBytePosition */}, /*ACC_RiTgtTyp*/
  {1u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 196u/* AppAccBytePosition */}, /*ACCSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 197u/* AppAccBytePosition */}, /*RollingCounter_ACC7*/
  {1u/*BitLength*/, 399u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 198u/* AppAccBytePosition */}, /*ACC_RlvTgtfusion*/
  {6u/*BitLength*/, 393u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 199u/* AppAccBytePosition */}, /*ACC_RlvTgtHeading*/
  {1u/*BitLength*/, 392u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 200u/* AppAccBytePosition */}, /*ACC_LeTgtfusion*/
  {6u/*BitLength*/, 402u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 201u/* AppAccBytePosition */}, /*ACC_LeTgtHeading*/
  {1u/*BitLength*/, 401u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 202u/* AppAccBytePosition */}, /*ACC_RiTgtfusion*/
  {6u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 203u/* AppAccBytePosition */}, /*ACC_RiTgtHeading*/
  {1u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 204u/* AppAccBytePosition */}, /*ACC_PotentialTgtfusion*/
  {6u/*BitLength*/, 420u/* BitPosition */, 2u/* ByteLength */, 52u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 205u/* AppAccBytePosition */}, /*ACC_PotentialTgtHeading*/
  {6u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 206u/* AppAccBytePosition */}, /*TargetCutinPro*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 207u/* AppAccBytePosition */}, /*TargetCutoutPro*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 208u/* AppAccBytePosition */}, /*ACC_FD2_0x2AB*/
  {6u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 264u/* AppAccBytePosition */}, /*JAPedObjExist*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 265u/* AppAccBytePosition */}, /*AEBJAObjID*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 266u/* AppAccBytePosition */}, /*AEBJAObjExist*/
  {8u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 267u/* AppAccBytePosition */}, /*JAPedObjID*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 268u/* AppAccBytePosition */}, /*AEBJAObjVideoCfmd*/
  {12u/*BitLength*/, 100u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 269u/* AppAccBytePosition */}, /*AEBJAObjVx*/
  {12u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 271u/* AppAccBytePosition */}, /*AEBJAObjDx*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 273u/* AppAccBytePosition */}, /*JAPedObjVideoCfmd*/
  {3u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 274u/* AppAccBytePosition */}, /*AEBJAObjState*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 275u/* AppAccBytePosition */}, /*AEBJAObjCntAlive*/
  {11u/*BitLength*/, 153u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 277u/* AppAccBytePosition */}, /*AEBJAObjDy*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 279u/* AppAccBytePosition */}, /*JAPedObjState*/
  {5u/*BitLength*/, 164u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 280u/* AppAccBytePosition */}, /*AEBJAObjObstcl*/
  {10u/*BitLength*/, 170u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 281u/* AppAccBytePosition */}, /*AEBJAObjVy*/
  {10u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 283u/* AppAccBytePosition */}, /*AEBJAObjAx*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 285u/* AppAccBytePosition */}, /*AEBJAObjAy*/
  {5u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 287u/* AppAccBytePosition */}, /*JAPedObjObstcl*/
  {11u/*BitLength*/, 229u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 288u/* AppAccBytePosition */}, /*JAPedObjDy*/
  {12u/*BitLength*/, 233u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 290u/* AppAccBytePosition */}, /*JAPedObjDx*/
  {6u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 292u/* AppAccBytePosition */}, /*FCWAEB_JATTC*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 293u/* AppAccBytePosition */}, /*JAPedObjVx*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 295u/* AppAccBytePosition */}, /*JAPedObjVy*/
  {10u/*BitLength*/, 308u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 297u/* AppAccBytePosition */}, /*JAPedObjAy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 299u/* AppAccBytePosition */}, /*JAPedObjCntAlive*/
  {6u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 301u/* AppAccBytePosition */}, /*FCWAEB_longTTC*/
  {6u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 302u/* AppAccBytePosition */}, /*FCWAEB_crossingTTC*/
  {10u/*BitLength*/, 342u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 303u/* AppAccBytePosition */}, /*JAPedObjAx*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 305u/* AppAccBytePosition */}, /*ACC_FD3_0x2B4*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 369u/* AppAccBytePosition */}, /*AEBObjID*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 370u/* AppAccBytePosition */}, /*AEBObjExist*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 371u/* AppAccBytePosition */}, /*AEBObjVideoCfmd*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 372u/* AppAccBytePosition */}, /*AEBObjVx*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 374u/* AppAccBytePosition */}, /*AEBObjDx*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 376u/* AppAccBytePosition */}, /*AEBObjCntAlive*/
  {11u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 378u/* AppAccBytePosition */}, /*AEBObjDy*/
  {3u/*BitLength*/, 69u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 380u/* AppAccBytePosition */}, /*AEBObjState*/
  {5u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 381u/* AppAccBytePosition */}, /*AEBObjObstcl*/
  {10u/*BitLength*/, 86u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 382u/* AppAccBytePosition */}, /*AEBObjVy*/
  {6u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 384u/* AppAccBytePosition */}, /*CyclistObjExist*/
  {10u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 385u/* AppAccBytePosition */}, /*AEBObjAx*/
  {10u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 387u/* AppAccBytePosition */}, /*AEBObjAy*/
  {12u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 389u/* AppAccBytePosition */}, /*CyclistObjDx*/
  {8u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 391u/* AppAccBytePosition */}, /*CyclistObjID*/
  {5u/*BitLength*/, 131u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 392u/* AppAccBytePosition */}, /*CyclistObjObstcl*/
  {11u/*BitLength*/, 136u/* BitPosition */, 2u/* ByteLength */, 17u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 393u/* AppAccBytePosition */}, /*CyclistObjDy*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 395u/* AppAccBytePosition */}, /*CyclistObjVx*/
  {12u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 397u/* AppAccBytePosition */}, /*CyclistObjCntAlive*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 399u/* AppAccBytePosition */}, /*CyclistObjVy*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 401u/* AppAccBytePosition */}, /*CyclistObjState*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 402u/* AppAccBytePosition */}, /*CyclistObjVideoCfmd*/
  {10u/*BitLength*/, 184u/* BitPosition */, 2u/* ByteLength */, 23u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 403u/* AppAccBytePosition */}, /*CyclistObjAx*/
  {10u/*BitLength*/, 206u/* BitPosition */, 2u/* ByteLength */, 25u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 405u/* AppAccBytePosition */}, /*CyclistObjAy*/
  {6u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 407u/* AppAccBytePosition */}, /*PedObjExist*/
  {8u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 408u/* AppAccBytePosition */}, /*PedObjID*/
  {5u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 409u/* AppAccBytePosition */}, /*PedObjObstcl*/
  {11u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 410u/* AppAccBytePosition */}, /*PedObjDy*/
  {12u/*BitLength*/, 244u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 412u/* AppAccBytePosition */}, /*PedObjDx*/
  {12u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 414u/* AppAccBytePosition */}, /*PedObjVx*/
  {10u/*BitLength*/, 270u/* BitPosition */, 2u/* ByteLength */, 33u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 416u/* AppAccBytePosition */}, /*PedObjVy*/
  {1u/*BitLength*/, 269u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 418u/* AppAccBytePosition */}, /*PedObjVideoCfmd*/
  {12u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 419u/* AppAccBytePosition */}, /*ACCTgtObjDx*/
  {10u/*BitLength*/, 294u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 421u/* AppAccBytePosition */}, /*PedObjAy*/
  {12u/*BitLength*/, 298u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 423u/* AppAccBytePosition */}, /*PedObjCntAlive*/
  {10u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 425u/* AppAccBytePosition */}, /*PedObjAx*/
  {8u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 427u/* AppAccBytePosition */}, /*ACCTgtObjID*/
  {5u/*BitLength*/, 323u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 428u/* AppAccBytePosition */}, /*ACCTgtObjObstcl*/
  {11u/*BitLength*/, 328u/* BitPosition */, 2u/* ByteLength */, 41u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 429u/* AppAccBytePosition */}, /*ACCTgtObjDy*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 431u/* AppAccBytePosition */}, /*ACCTgtObjExist*/
  {10u/*BitLength*/, 344u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 432u/* AppAccBytePosition */}, /*ACCTgtObjVy*/
  {12u/*BitLength*/, 364u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 434u/* AppAccBytePosition */}, /*ACCTgtObjVx*/
  {10u/*BitLength*/, 370u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 436u/* AppAccBytePosition */}, /*ACCTgtObjAx*/
  {10u/*BitLength*/, 376u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 438u/* AppAccBytePosition */}, /*ACCTgtObjAy*/
  {3u/*BitLength*/, 389u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 440u/* AppAccBytePosition */}, /*ACCTgtObjState*/
  {1u/*BitLength*/, 388u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 441u/* AppAccBytePosition */}, /*ACCTgtObjVideoCfmd*/
  {12u/*BitLength*/, 392u/* BitPosition */, 2u/* ByteLength */, 49u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 442u/* AppAccBytePosition */}, /*ACCTgtObjCntAlive*/
  {12u/*BitLength*/, 412u/* BitPosition */, 2u/* ByteLength */, 51u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 444u/* AppAccBytePosition */}, /*RadarHorMisalign*/
  {2u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 446u/* AppAccBytePosition */}, /*HandsoffDetd*/
  {2u/*BitLength*/, 408u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 447u/* AppAccBytePosition */}, /*DrvgOnHiWay*/
  {10u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 448u/* AppAccBytePosition */}, /*RoadCrvt*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 450u/* AppAccBytePosition */}, /*SpdLimitDst*/
  {10u/*BitLength*/, 446u/* BitPosition */, 2u/* ByteLength */, 55u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 451u/* AppAccBytePosition */}, /*RoadCrvtFar*/
  {6u/*BitLength*/, 440u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 453u/* AppAccBytePosition */}, /*RampDst*/
  {8u/*BitLength*/, 448u/* BitPosition */, 1u/* ByteLength */, 56u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 454u/* AppAccBytePosition */}, /*SpdLimit*/
  {6u/*BitLength*/, 458u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 455u/* AppAccBytePosition */}, /*CurveDst*/
  {2u/*BitLength*/, 456u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 456u/* AppAccBytePosition */}, /*NavSpdLimUnit*/
  {6u/*BitLength*/, 466u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 457u/* AppAccBytePosition */}, /*TunnelDst*/
  {2u/*BitLength*/, 464u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 458u/* AppAccBytePosition */}, /*DrvgOnRiLane*/
  {6u/*BitLength*/, 474u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 459u/* AppAccBytePosition */}, /*BrdgDst*/
  {1u/*BitLength*/, 473u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 460u/* AppAccBytePosition */}, /*RadarDrvrAttentive*/
  {8u/*BitLength*/, 504u/* BitPosition */, 1u/* ByteLength */, 63u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 461u/* AppAccBytePosition */}, /*ACC_DataRecReq*/
  {2u/*BitLength*/, 483u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 462u/* AppAccBytePosition */}, /*ACC_SOSReq*/
  {3u/*BitLength*/, 480u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 463u/* AppAccBytePosition */}, /*PedObjState*/
  {1u/*BitLength*/, 495u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 464u/* AppAccBytePosition */}, /*MapDataValid*/
  {3u/*BitLength*/, 492u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 465u/* AppAccBytePosition */}, /*DrvrSts*/
  {5u/*BitLength*/, 503u/* BitPosition */, 2u/* ByteLength */, 62u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 466u/* AppAccBytePosition */}, /*AEBObjOverlap*/
  {5u/*BitLength*/, 498u/* BitPosition */, 1u/* ByteLength */, 62u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 467u/* AppAccBytePosition */}, /*AEBObjDrvby*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 468u/* AppAccBytePosition */}, /*ACC_FD4_0x2B8*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 532u/* AppAccBytePosition */}, /*AEB_ABA_Level*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 533u/* AppAccBytePosition */}, /*AEB_ABA_Req*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 534u/* AppAccBytePosition */}, /*EBA_TgtDecel_Req*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 535u/* AppAccBytePosition */}, /*AEB_VehHldReq*/
  {1u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 536u/* AppAccBytePosition */}, /*AEB_TgtDecel_Req*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 537u/* AppAccBytePosition */}, /*AEB_TgtDecel_ReqValue*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 539u/* AppAccBytePosition */}, /*AEB_AWB_Req*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 540u/* AppAccBytePosition */}, /*AEB_AWB_Level*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 541u/* AppAccBytePosition */}, /*AEB_ABP_Req*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 542u/* AppAccBytePosition */}, /*AEB_BrkReqFunc*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 543u/* AppAccBytePosition */}, /*AEB_ObjSty*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 544u/* AppAccBytePosition */}, /*AEB_FD1_0x18B*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 608u/* AppAccBytePosition */}, /*Checksum_AEB2*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 609u/* AppAccBytePosition */}, /*AEB_PedResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 610u/* AppAccBytePosition */}, /*AEB_VehResp*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 611u/* AppAccBytePosition */}, /*FCW_Snvty*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 612u/* AppAccBytePosition */}, /*AEB_JA_Resp*/
  {1u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 613u/* AppAccBytePosition */}, /*IntellgntcurveResp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 614u/* AppAccBytePosition */}, /*RollingCounter_AEB2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 615u/* AppAccBytePosition */}, /*Checksum_AEB3*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 616u/* AppAccBytePosition */}, /*AEB_VehTrig*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 617u/* AppAccBytePosition */}, /*AEB_PedTrig*/
  {2u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 618u/* AppAccBytePosition */}, /*FCW_AEB_VehFctSts*/
  {2u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 619u/* AppAccBytePosition */}, /*FCW_AEB_PedFctSts*/
  {2u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 620u/* AppAccBytePosition */}, /*FCW_Warn*/
  {2u/*BitLength*/, 146u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 621u/* AppAccBytePosition */}, /*AEB_JAFuncSts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 622u/* AppAccBytePosition */}, /*AEB_JA_Warn*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 623u/* AppAccBytePosition */}, /*AEB_JABrkTrig*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 624u/* AppAccBytePosition */}, /*RollingCounter_AEB3*/
  {8u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 625u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dy*/
  {9u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 626u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dx*/
  {2u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 628u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Detn*/
  {3u/*BitLength*/, 218u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 629u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Typ*/
  {6u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 630u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Heading*/
  {8u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 631u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dy*/
  {9u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 632u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dx*/
  {2u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 634u/* AppAccBytePosition */}, /*ACC_LeTargrt_03_Detn*/
  {3u/*BitLength*/, 253u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 635u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Typ*/
  {6u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 636u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Heading*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 637u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dy*/
  {9u/*BitLength*/, 295u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 638u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dx*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 640u/* AppAccBytePosition */}, /*ACC_RiTargrt_03_Detn*/
  {3u/*BitLength*/, 292u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 641u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Typ*/
  {6u/*BitLength*/, 298u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 642u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Heading*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 643u/* AppAccBytePosition */}, /*AEB_FD2_0x227*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 699u/* AppAccBytePosition */}, /*ALCMSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 700u/* AppAccBytePosition */}, /*ALCM1_0x2DB*/
  {16u/*BitLength*/, 8u/* BitPosition */, 2u/* ByteLength */, 1u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 708u/* AppAccBytePosition */}, /*AMP_SWVersion*/
  {16u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 710u/* AppAccBytePosition */}, /*AMP_HWVersion*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 712u/* AppAccBytePosition */}, /*AMP_Chan1DTCInfo*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 713u/* AppAccBytePosition */}, /*AMP_Chan2DTCInfo*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 714u/* AppAccBytePosition */}, /*AMP_Chan3DTCInfo*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 715u/* AppAccBytePosition */}, /*AMP_Chan4DTCInfo*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 716u/* AppAccBytePosition */}, /*AMP_Chan5DTCInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 717u/* AppAccBytePosition */}, /*AMP_Chan6DTCInfo*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 718u/* AppAccBytePosition */}, /*AMP_Chan7DTCInfo*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 719u/* AppAccBytePosition */}, /*AMP_Chan8DTCInfo*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 720u/* AppAccBytePosition */}, /*AMP_TempValue*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 721u/* AppAccBytePosition */}, /*AMP_TempSts*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 722u/* AppAccBytePosition */}, /*AMP_VolValue*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 723u/* AppAccBytePosition */}, /*BestListegPosnResp*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 724u/* AppAccBytePosition */}, /*Clari_FiResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 725u/* AppAccBytePosition */}, /*AMP1_0x3E1*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 733u/* AppAccBytePosition */}, /*MediaCallSourceState*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 734u/* AppAccBytePosition */}, /*BeepSourceSts*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 735u/* AppAccBytePosition */}, /*BalanceSetState*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 736u/* AppAccBytePosition */}, /*VSCModeState*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 737u/* AppAccBytePosition */}, /*FadeSetState*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 738u/* AppAccBytePosition */}, /*DriveSideSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 739u/* AppAccBytePosition */}, /*BassSetState*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 740u/* AppAccBytePosition */}, /*MuteState*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 741u/* AppAccBytePosition */}, /*NaviSourceState*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 742u/* AppAccBytePosition */}, /*MidrangeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 743u/* AppAccBytePosition */}, /*T_box_ECallSts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 744u/* AppAccBytePosition */}, /*GetHUTInfoSts*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 745u/* AppAccBytePosition */}, /*TrebleSetState*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 746u/* AppAccBytePosition */}, /*QLISurroundSetSt*/
  {1u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 747u/* AppAccBytePosition */}, /*AVMStResp*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 748u/* AppAccBytePosition */}, /*NaviMediaVolLvlResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 749u/* AppAccBytePosition */}, /*AVMMediaVolLvlResp*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 750u/* AppAccBytePosition */}, /*FPASChStResp*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 751u/* AppAccBytePosition */}, /*RPASChStResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 752u/* AppAccBytePosition */}, /*AMP2_0x3E3*/
  {6u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 760u/* AppAccBytePosition */}, /*HFMVolSetSts*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 761u/* AppAccBytePosition */}, /*VR_TTSVolSetSts*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 762u/* AppAccBytePosition */}, /*NaviVolumeSetState*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 763u/* AppAccBytePosition */}, /*MainVolumeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 764u/* AppAccBytePosition */}, /*AMPPowerSts*/
  {6u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 765u/* AppAccBytePosition */}, /*IPVolSetSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 766u/* AppAccBytePosition */}, /*AMP3_0x3E5*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 774u/* AppAccBytePosition */}, /*Microphone_Cha1DTCInfo*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 775u/* AppAccBytePosition */}, /*Microphone_Cha2DTCInfo*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 776u/* AppAccBytePosition */}, /*Microphone_Cha3DTCInfo*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 777u/* AppAccBytePosition */}, /*Microphone_Cha4DTCInfo*/
  {1u/*BitLength*/, 58u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 778u/* AppAccBytePosition */}, /*ANCSwtStatus*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 779u/* AppAccBytePosition */}, /*AMP4_ANC1_0x2D2*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 787u/* AppAccBytePosition */}, /*IESS_SwitchModel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 788u/* AppAccBytePosition */}, /*AMP5_IESS1_0x3A1*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 796u/* AppAccBytePosition */}, /*IPBackgroundLmpCmd*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 797u/* AppAccBytePosition */}, /*TrunkSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 798u/* AppAccBytePosition */}, /*DrvDoorSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 799u/* AppAccBytePosition */}, /*LRDoorSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 800u/* AppAccBytePosition */}, /*PassengerDoorSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 801u/* AppAccBytePosition */}, /*RRDoorSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 802u/* AppAccBytePosition */}, /*BrkPedalSts_BCM*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 803u/* AppAccBytePosition */}, /*BackgroundLightLvl*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 804u/* AppAccBytePosition */}, /*DrowsyDrvDetWarn*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 805u/* AppAccBytePosition */}, /*RLSFailSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 806u/* AppAccBytePosition */}, /*PosnLightReq*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 807u/* AppAccBytePosition */}, /*WindshldWiprActvSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 808u/* AppAccBytePosition */}, /*BCM1_0x319*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 816u/* AppAccBytePosition */}, /*LasHdLmpSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 817u/* AppAccBytePosition */}, /*AntitheftSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 818u/* AppAccBytePosition */}, /*DrvDoorLockSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 819u/* AppAccBytePosition */}, /*DoorLockSts*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 820u/* AppAccBytePosition */}, /*HiLowBeamSts*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 821u/* AppAccBytePosition */}, /*BCMTextDisp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 822u/* AppAccBytePosition */}, /*BCM3_0x345*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 830u/* AppAccBytePosition */}, /*RemoteModSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 831u/* AppAccBytePosition */}, /*KL30BRelaySts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 832u/* AppAccBytePosition */}, /*RViewMirrorSts*/
  {3u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 833u/* AppAccBytePosition */}, /*WiprReq_F_PBox*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 834u/* AppAccBytePosition */}, /*DrivingModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 835u/* AppAccBytePosition */}, /*PASWorkCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 836u/* AppAccBytePosition */}, /*BCM8_0x29F*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 844u/* AppAccBytePosition */}, /*ExpertModSwtReq*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 845u/* AppAccBytePosition */}, /*CCO_SwtShift_Warn*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 846u/* AppAccBytePosition */}, /*TAB_SwtShift_Warn*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 847u/* AppAccBytePosition */}, /*FourLModeSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 848u/* AppAccBytePosition */}, /*FourDrvModSwtReq*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 849u/* AppAccBytePosition */}, /*DrivingModshift_Warn*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 850u/* AppAccBytePosition */}, /*CSM_LDrvSeatHeatgLvl*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 851u/* AppAccBytePosition */}, /*CSM_LDrvSeatVentnLvl*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 852u/* AppAccBytePosition */}, /*CSM_RPassSeatHeatgLvl*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 853u/* AppAccBytePosition */}, /*CSM_RPassSeatVentnLvl*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 854u/* AppAccBytePosition */}, /*BCM11_0x305*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 862u/* AppAccBytePosition */}, /*SrAntiPinch*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 863u/* AppAccBytePosition */}, /*SsAntiPinch*/
  {7u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 864u/* AppAccBytePosition */}, /*SrPosn_VR_APP*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 865u/* AppAccBytePosition */}, /*RLS_IRBrightness*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 866u/* AppAccBytePosition */}, /*RLS_FwBrightness*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 868u/* AppAccBytePosition */}, /*RLS_AmbBrightness*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 870u/* AppAccBytePosition */}, /*BCM12_0x238*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 878u/* AppAccBytePosition */}, /*BLE_BeanID*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 886u/* AppAccBytePosition */}, /*BLE5_0x1FA*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 894u/* AppAccBytePosition */}, /*BMS_ErrCategory*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 895u/* AppAccBytePosition */}, /*CheckSum_BMS4*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 896u/* AppAccBytePosition */}, /*BMS_PackCurr*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 898u/* AppAccBytePosition */}, /*BMS_PackVolt*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 899u/* AppAccBytePosition */}, /*BMS_PowerDownCmplt*/
  {2u/*BitLength*/, 63u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 900u/* AppAccBytePosition */}, /*BMS_BattPoweErr*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 901u/* AppAccBytePosition */}, /*RollingCounter_BMS4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 902u/* AppAccBytePosition */}, /*BMS4_0xF1*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 910u/* AppAccBytePosition */}, /*BMS_BattHeatRunaway*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 911u/* AppAccBytePosition */}, /*BMS_DisSOC1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 912u/* AppAccBytePosition */}, /*BMS8_0x285*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 920u/* AppAccBytePosition */}, /*BMS_IntelEngIdlChrgnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 921u/* AppAccBytePosition */}, /*BMS_BattKeepTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 922u/* AppAccBytePosition */}, /*BMS19_0x352*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 930u/* AppAccBytePosition */}, /*BMS_ChrgDurationTime*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 932u/* AppAccBytePosition */}, /*BMS22_0x3BF*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 940u/* AppAccBytePosition */}, /*BMS_SOCLowWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 941u/* AppAccBytePosition */}, /*BMS30_0x3F1*/
  {10u/*BitLength*/, 40u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 949u/* AppAccBytePosition */}, /*BMS_BattSOC_P0*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 951u/* AppAccBytePosition */}, /*BMS65_0x14F*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 959u/* AppAccBytePosition */}, /*BMS_SocJumpWarn_RM*/
  {1u/*BitLength*/, 6u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 960u/* AppAccBytePosition */}, /*BMS_PackOverChrgWarn_RM*/
  {3u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 961u/* AppAccBytePosition */}, /*BMS_ChrgSts_RM*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 23u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 962u/* AppAccBytePosition */}, /*BMS_IsolationRValue_RM*/
  {15u/*BitLength*/, 33u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 964u/* AppAccBytePosition */}, /*BMS_PackCurr_RM*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 966u/* AppAccBytePosition */}, /*BMS_SocOverWarn_RM*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 967u/* AppAccBytePosition */}, /*BMS_BattOverTempRank_RM*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 968u/* AppAccBytePosition */}, /*BMS_BattOverVoltRank_RM*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 969u/* AppAccBytePosition */}, /*BMS_BattSOCLowRank_RM*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 970u/* AppAccBytePosition */}, /*BMS_VCUIsolateErr_RM*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 971u/* AppAccBytePosition */}, /*BMS_BattUnderVoltRank_RM*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 972u/* AppAccBytePosition */}, /*BMS_CellDeltaVoltRank_RM*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 973u/* AppAccBytePosition */}, /*BMS_CellOverVoltRank_RM*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 974u/* AppAccBytePosition */}, /*BMS_CellUnderVoltRank_RM*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 975u/* AppAccBytePosition */}, /*BMS_DeltaTempRank_RM*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 976u/* AppAccBytePosition */}, /*BMS_PackMismatchWarn_RM*/
  {14u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 977u/* AppAccBytePosition */}, /*BMS_PackVolt_RM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 979u/* AppAccBytePosition */}, /*BMS66_0x3AE*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 987u/* AppAccBytePosition */}, /*RoofModFb*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 988u/* AppAccBytePosition */}, /*AllTerrainDislFb*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 989u/* AppAccBytePosition */}, /*ElecSideStepSysFb*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 990u/* AppAccBytePosition */}, /*CP1_0x35E*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 998u/* AppAccBytePosition */}, /*CR_FCTA_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 999u/* AppAccBytePosition */}, /*CR_FCTB_Resp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1000u/* AppAccBytePosition */}, /*CR_BliSts*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1001u/* AppAccBytePosition */}, /*FCTA_Warn*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1002u/* AppAccBytePosition */}, /*FCTBTrig*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1003u/* AppAccBytePosition */}, /*FCTA_B_FuncSts*/
  {6u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1004u/* AppAccBytePosition */}, /*FCTA_B_TTC*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1005u/* AppAccBytePosition */}, /*CR_FD1_0x15E*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1069u/* AppAccBytePosition */}, /*LTurnLmpSwtSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1070u/* AppAccBytePosition */}, /*RTurnLmpSwtSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1071u/* AppAccBytePosition */}, /*AutoLmpSwtSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1072u/* AppAccBytePosition */}, /*HornSwtSts*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1073u/* AppAccBytePosition */}, /*FrntWiprSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1074u/* AppAccBytePosition */}, /*CSA1_0x165*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1082u/* AppAccBytePosition */}, /*SteerWheelAng*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1084u/* AppAccBytePosition */}, /*SteerWheelAngSign*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1085u/* AppAccBytePosition */}, /*SAS_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1086u/* AppAccBytePosition */}, /*CSA2_0xA1*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1094u/* AppAccBytePosition */}, /*MenuReturnSwtSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1095u/* AppAccBytePosition */}, /*SteerWheelHeatdSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1096u/* AppAccBytePosition */}, /*HomeSwtSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1097u/* AppAccBytePosition */}, /*MuteSwtSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1098u/* AppAccBytePosition */}, /*CustomSwtSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1099u/* AppAccBytePosition */}, /*PageUpSwtSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1100u/* AppAccBytePosition */}, /*PageDwnSwtSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1101u/* AppAccBytePosition */}, /*PageLSwtSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1102u/* AppAccBytePosition */}, /*PageRSwtSts*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1103u/* AppAccBytePosition */}, /*SeekUpSwtSts*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1104u/* AppAccBytePosition */}, /*SeekDwnSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1105u/* AppAccBytePosition */}, /*AdjVolUpSwtSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1106u/* AppAccBytePosition */}, /*AdjVolDwnSwtSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1107u/* AppAccBytePosition */}, /*VRSwtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1108u/* AppAccBytePosition */}, /*EnterSwtSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1109u/* AppAccBytePosition */}, /*EnterSwtSts_Mmed*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1110u/* AppAccBytePosition */}, /*CustomSwtSts_Mmed*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1111u/* AppAccBytePosition */}, /*PhoneSwtSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1112u/* AppAccBytePosition */}, /*SoundSourceModSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1113u/* AppAccBytePosition */}, /*CSA3_0x244*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1121u/* AppAccBytePosition */}, /*TgtEngSpdIP*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1123u/* AppAccBytePosition */}, /*TgtEngSpdIPValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1124u/* AppAccBytePosition */}, /*DCT3_0xA6*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1132u/* AppAccBytePosition */}, /*CurrentGearValid*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1133u/* AppAccBytePosition */}, /*CURRENT_GEAR*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 24u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1134u/* AppAccBytePosition */}, /*TGS_LEVER*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1135u/* AppAccBytePosition */}, /*TRANS_Warning_LAMP*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1136u/* AppAccBytePosition */}, /*DCT5_0x221*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1144u/* AppAccBytePosition */}, /*CheckSum_DCT7*/
  {3u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1145u/* AppAccBytePosition */}, /*TrsmStNID*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1146u/* AppAccBytePosition */}, /*DCT_RaceModeSts*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1147u/* AppAccBytePosition */}, /*TRANS_OIL_TEMP*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1148u/* AppAccBytePosition */}, /*DCT_PrsBrk_Warn*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1149u/* AppAccBytePosition */}, /*DCT_ShftNotAlwd_Warn*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1150u/* AppAccBytePosition */}, /*DCT_ShftRecom_M*/
  {3u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1151u/* AppAccBytePosition */}, /*DrvWarnMsg*/
  {4u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1152u/* AppAccBytePosition */}, /*DrvFaiMsg*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1153u/* AppAccBytePosition */}, /*DrvModDisp*/
  {2u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1154u/* AppAccBytePosition */}, /*DrvModDispSts*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1155u/* AppAccBytePosition */}, /*DrvAutoGearDisp*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1156u/* AppAccBytePosition */}, /*DrvGearDispSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1157u/* AppAccBytePosition */}, /*RollingCounter_DCT7*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1158u/* AppAccBytePosition */}, /*DCT_FD4_0x236*/
  {5u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1222u/* AppAccBytePosition */}, /*DrvWinPosnSts_Perc*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1223u/* AppAccBytePosition */}, /*DrvWinLrnSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1224u/* AppAccBytePosition */}, /*DrvWinHotProtSts*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1225u/* AppAccBytePosition */}, /*DrvSideRearWinLrnSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1226u/* AppAccBytePosition */}, /*DrvSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1227u/* AppAccBytePosition */}, /*DDCM1_0x2CA*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1235u/* AppAccBytePosition */}, /*DrvSideRearWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1236u/* AppAccBytePosition */}, /*DDCM3_0x2F7*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1244u/* AppAccBytePosition */}, /*DrvExprsnResult*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1245u/* AppAccBytePosition */}, /*FRSFaceIDSts*/
  {3u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1246u/* AppAccBytePosition */}, /*DrvAgeResult*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1247u/* AppAccBytePosition */}, /*DrvSmokeResult*/
  {3u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1248u/* AppAccBytePosition */}, /*DrvCallingResult*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1249u/* AppAccBytePosition */}, /*FaceIdnSetSts*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1250u/* AppAccBytePosition */}, /*DistrctnDetnSetSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1251u/* AppAccBytePosition */}, /*DrowsnsDetnSetSts*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1252u/* AppAccBytePosition */}, /*OccptAttrSetUpSts*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1253u/* AppAccBytePosition */}, /*GazeAreaInteractionSetUpSts*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1254u/* AppAccBytePosition */}, /*SmokeFuncSetUpSts*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1255u/* AppAccBytePosition */}, /*CallingFuncSetUpSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1256u/* AppAccBytePosition */}, /*DMS_FD2_0x2AC*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1320u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1321u/* AppAccBytePosition */}, /*DSM1_0x2C1*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1329u/* AppAccBytePosition */}, /*EB_TgtRcprtnTrqSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1330u/* AppAccBytePosition */}, /*EBOOSTER_FD1_0x12D*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1394u/* AppAccBytePosition */}, /*EMS_AuthenResult*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1395u/* AppAccBytePosition */}, /*EngSpd*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1397u/* AppAccBytePosition */}, /*EngSpdVldty*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1398u/* AppAccBytePosition */}, /*EngSpd_PHEV*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1400u/* AppAccBytePosition */}, /*EngSpdVldty_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1401u/* AppAccBytePosition */}, /*ECM1_0x111*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1409u/* AppAccBytePosition */}, /*FuelConsumption*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1411u/* AppAccBytePosition */}, /*TgtCrsVehSpd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1412u/* AppAccBytePosition */}, /*CruiseCtrlSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1413u/* AppAccBytePosition */}, /*AccelPedalPosn*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1414u/* AppAccBytePosition */}, /*AccelPedalPosnVldty*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1415u/* AppAccBytePosition */}, /*ThrtlPosRatio*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1416u/* AppAccBytePosition */}, /*EngSVSSig*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1417u/* AppAccBytePosition */}, /*MILSts*/
  {2u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1418u/* AppAccBytePosition */}, /*EngState*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1419u/* AppAccBytePosition */}, /*ECM2_0x271*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1427u/* AppAccBytePosition */}, /*BaroPressure*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1428u/* AppAccBytePosition */}, /*EngCoolantTemp*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1429u/* AppAccBytePosition */}, /*GPF_Warning*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1430u/* AppAccBytePosition */}, /*GentrWarnLmpSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1431u/* AppAccBytePosition */}, /*EngClntTempWarn*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1432u/* AppAccBytePosition */}, /*EngClntTempVldty*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1433u/* AppAccBytePosition */}, /*SS_Screen_tip*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1434u/* AppAccBytePosition */}, /*SSSSetSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1435u/* AppAccBytePosition */}, /*SS_Enable_Lamp*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1436u/* AppAccBytePosition */}, /*SS_Fault_Lamp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1437u/* AppAccBytePosition */}, /*MaxEngTrqNorm*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1438u/* AppAccBytePosition */}, /*AGS_Failure*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1439u/* AppAccBytePosition */}, /*ECM3_0x371*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1447u/* AppAccBytePosition */}, /*NetEngTrq*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1449u/* AppAccBytePosition */}, /*DrvEngTrqReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1451u/* AppAccBytePosition */}, /*ECM4_0x82*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1459u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x84*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1460u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x84*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1461u/* AppAccBytePosition */}, /*ECM7_0x84*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1469u/* AppAccBytePosition */}, /*AccelPedlPosnDiagc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1470u/* AppAccBytePosition */}, /*ECM9_0x102*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1478u/* AppAccBytePosition */}, /*EngSpd_ForIP*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1480u/* AppAccBytePosition */}, /*EWP_Err*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1481u/* AppAccBytePosition */}, /*ECM_OffroadThmSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1482u/* AppAccBytePosition */}, /*ECM11_0x2D3*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1490u/* AppAccBytePosition */}, /*DPF_Warning*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1491u/* AppAccBytePosition */}, /*WIFSensorFailSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1492u/* AppAccBytePosition */}, /*GlowPlugLmpCmd*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1493u/* AppAccBytePosition */}, /*UreaLampCmd*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1494u/* AppAccBytePosition */}, /*Urea_Level*/
  {12u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1495u/* AppAccBytePosition */}, /*UreaRemainDist*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1497u/* AppAccBytePosition */}, /*SCRSysWarnDisplay*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1498u/* AppAccBytePosition */}, /*WIFFullLmpCmd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1499u/* AppAccBytePosition */}, /*DPF_Activation*/
  {5u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1500u/* AppAccBytePosition */}, /*SCRSysWarnDisplay_B2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1501u/* AppAccBytePosition */}, /*ECM16_0x2D4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1509u/* AppAccBytePosition */}, /*ECM_VIN*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1517u/* AppAccBytePosition */}, /*ECM19_0x3B5*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 25u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1525u/* AppAccBytePosition */}, /*ECM_VehDstBackup*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1529u/* AppAccBytePosition */}, /*ECM20_0x3B7*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1537u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvl*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1539u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvlValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1540u/* AppAccBytePosition */}, /*ECM_PT5_0x8E*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1548u/* AppAccBytePosition */}, /*FTIVFault*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1549u/* AppAccBytePosition */}, /*FuelTankCapWarning*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1550u/* AppAccBytePosition */}, /*PressReliProgs*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1551u/* AppAccBytePosition */}, /*ECM_PT6_0x290*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1559u/* AppAccBytePosition */}, /*EngState_PHEV*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1560u/* AppAccBytePosition */}, /*CruiseCtrlSts_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1561u/* AppAccBytePosition */}, /*ECM_PT7_0x117*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1569u/* AppAccBytePosition */}, /*TranPMode_Sts*/
  {3u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1570u/* AppAccBytePosition */}, /*Stat_PwrSv_Lvl*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1571u/* AppAccBytePosition */}, /*Dyn_PwrSv_Lvl*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1572u/* AppAccBytePosition */}, /*LvPwrSysErr*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1573u/* AppAccBytePosition */}, /*EEM1_0x2A8*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1581u/* AppAccBytePosition */}, /*FrntELDLckSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1582u/* AppAccBytePosition */}, /*RearELDLckSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1583u/* AppAccBytePosition */}, /*ELD1_0x152*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1591u/* AppAccBytePosition */}, /*CheckSum_EPB1*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1592u/* AppAccBytePosition */}, /*EPBErrSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1593u/* AppAccBytePosition */}, /*EPBRedLmpSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1594u/* AppAccBytePosition */}, /*EPBSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1595u/* AppAccBytePosition */}, /*EPBTextDisp*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1596u/* AppAccBytePosition */}, /*PressBrakePedalPointOut*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1597u/* AppAccBytePosition */}, /*RollingCounter_EPB1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1598u/* AppAccBytePosition */}, /*EPB1_0x16B*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1606u/* AppAccBytePosition */}, /*CheckSum_EPS1*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1607u/* AppAccBytePosition */}, /*EPS_FailSts*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1608u/* AppAccBytePosition */}, /*EPS_SteerMod*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1609u/* AppAccBytePosition */}, /*SteerCorrnRmn*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1610u/* AppAccBytePosition */}, /*SteerCorrnResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1611u/* AppAccBytePosition */}, /*RollingCounter_EPS1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1612u/* AppAccBytePosition */}, /*EPS_FD1_0x147*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1676u/* AppAccBytePosition */}, /*RotSteerWheel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1677u/* AppAccBytePosition */}, /*ESCL2_0x303*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1685u/* AppAccBytePosition */}, /*CCO_Warn*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1686u/* AppAccBytePosition */}, /*CCO_Active*/
  {5u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1687u/* AppAccBytePosition */}, /*CCO_TgtVel*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1688u/* AppAccBytePosition */}, /*EspFuncOffSts_mode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1689u/* AppAccBytePosition */}, /*ESP8_0x170*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1697u/* AppAccBytePosition */}, /*ESP_HMI_WarningOn*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1698u/* AppAccBytePosition */}, /*WadeModeWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1699u/* AppAccBytePosition */}, /*ESP11_0xC8*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1707u/* AppAccBytePosition */}, /*CheckSum_ESP2*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1708u/* AppAccBytePosition */}, /*HDCFault*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1709u/* AppAccBytePosition */}, /*HDCCtrl*/
  {2u/*BitLength*/, 98u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1710u/* AppAccBytePosition */}, /*AVHErrSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1711u/* AppAccBytePosition */}, /*AVHSts*/
  {1u/*BitLength*/, 103u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1712u/* AppAccBytePosition */}, /*CDPActv*/
  {5u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1713u/* AppAccBytePosition */}, /*DrivingModDis*/
  {5u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1714u/* AppAccBytePosition */}, /*DrivingModReq_ESP*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1715u/* AppAccBytePosition */}, /*Shift_N_Warn*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1716u/* AppAccBytePosition */}, /*Over_Spd_Warn*/
  {1u/*BitLength*/, 106u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1717u/* AppAccBytePosition */}, /*FourL_Warn*/
  {2u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1718u/* AppAccBytePosition */}, /*TAB_Sts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1719u/* AppAccBytePosition */}, /*RollingCounter_ESP2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1720u/* AppAccBytePosition */}, /*CheckSum_ESP1*/
  {1u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1721u/* AppAccBytePosition */}, /*ESPFuncOffSts*/
  {1u/*BitLength*/, 141u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1722u/* AppAccBytePosition */}, /*ESPActvInfoLmp*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1723u/* AppAccBytePosition */}, /*ESPFailSts*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1724u/* AppAccBytePosition */}, /*IMC_Actv*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1725u/* AppAccBytePosition */}, /*RollingCounter_ESP1*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1726u/* AppAccBytePosition */}, /*CheckSum_ABS3*/
  {1u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1727u/* AppAccBytePosition */}, /*ABSActv*/
  {1u/*BitLength*/, 335u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1728u/* AppAccBytePosition */}, /*ABSFailSts*/
  {1u/*BitLength*/, 334u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1729u/* AppAccBytePosition */}, /*EBDFailSts*/
  {1u/*BitLength*/, 333u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1730u/* AppAccBytePosition */}, /*VehSpdVld*/
  {13u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1731u/* AppAccBytePosition */}, /*VehSpd*/
  {1u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1733u/* AppAccBytePosition */}, /*VehOdoInfoSts*/
  {10u/*BitLength*/, 352u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1734u/* AppAccBytePosition */}, /*VehOdoInfo*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1736u/* AppAccBytePosition */}, /*RollingCounter_ABS3*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1737u/* AppAccBytePosition */}, /*ESP_FD2_0x137*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1793u/* AppAccBytePosition */}, /*FFogLmpSts_F_PBox*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1794u/* AppAccBytePosition */}, /*HiBeamSts_F_PBox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1795u/* AppAccBytePosition */}, /*HoodSts_F_PBox*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1796u/* AppAccBytePosition */}, /*LasHdLmpSts_F_PBox*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1797u/* AppAccBytePosition */}, /*LHiBeamFailSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1798u/* AppAccBytePosition */}, /*RHiBeamFailSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1799u/* AppAccBytePosition */}, /*LLowBeamFailSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1800u/* AppAccBytePosition */}, /*LHeadLmpFailSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1801u/* AppAccBytePosition */}, /*RHeadLmpFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1802u/* AppAccBytePosition */}, /*RLowBeamFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1803u/* AppAccBytePosition */}, /*RLasHdLmpDiagSig*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1804u/* AppAccBytePosition */}, /*LLasHdLmpDiagSig*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1805u/* AppAccBytePosition */}, /*LowBeamSts_F_PBox*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1806u/* AppAccBytePosition */}, /*WhistleSts_F_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1807u/* AppAccBytePosition */}, /*F_PBOX1_0x19B*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1815u/* AppAccBytePosition */}, /*QuietVoiceReq*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1816u/* AppAccBytePosition */}, /*E_CALLSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1817u/* AppAccBytePosition */}, /*GLO_NASS1_0x56*/
  {14u/*BitLength*/, 74u/* BitPosition */, 2u/* ByteLength */, 9u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 26u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1825u/* AppAccBytePosition */}, /*U_BATT*/
  {2u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1827u/* AppAccBytePosition */}, /*I_RANGE*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 27u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1828u/* AppAccBytePosition */}, /*I_BATT*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1830u/* AppAccBytePosition */}, /*SOC*/
  {8u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1831u/* AppAccBytePosition */}, /*SOH_SUL*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1832u/* AppAccBytePosition */}, /*SOC_STATE*/
  {2u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1833u/* AppAccBytePosition */}, /*SOH_SUL_STATE*/
  {2u/*BitLength*/, 342u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1834u/* AppAccBytePosition */}, /*OTA_UpgrdModSts*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1835u/* AppAccBytePosition */}, /*CheckSum_GWM1*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1836u/* AppAccBytePosition */}, /*RollingCounter_GWM1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1837u/* AppAccBytePosition */}, /*GW_FD1_0x2BB*/
  {2u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1901u/* AppAccBytePosition */}, /*OTA_UpgrdModErrCode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1902u/* AppAccBytePosition */}, /*GW_OTA_0x1D9*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1910u/* AppAccBytePosition */}, /*ResetCount*/
  {88u/*BitLength*/, 40u/* BitPosition */, 11u/* ByteLength */, 5u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 28u/* InitValueIdx */, 11u/* AppAccBtyeLength */, 1912u/* AppAccBytePosition */}, /*CMACMessageInfo*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 25u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1923u/* AppAccBytePosition */}, /*TripCount*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1927u/* AppAccBytePosition */}, /*APS_PrkgMod*/
  {7u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1928u/* AppAccBytePosition */}, /*APS_ProcBar*/
  {1u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1929u/* AppAccBytePosition */}, /*APS_SwtSts*/
  {3u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1930u/* AppAccBytePosition */}, /*APS_SlotDisp*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1931u/* AppAccBytePosition */}, /*APS_SysSoundIndcn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1932u/* AppAccBytePosition */}, /*APS_PrkgTyp*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1933u/* AppAccBytePosition */}, /*APS_TextDisp*/
  {3u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1934u/* AppAccBytePosition */}, /*APS_WorkSts*/
  {1u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1935u/* AppAccBytePosition */}, /*MEB_AVHReq*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1936u/* AppAccBytePosition */}, /*APS_ESP_BrkDistance*/
  {1u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1938u/* AppAccBytePosition */}, /*LParaPrkgOutVald*/
  {1u/*BitLength*/, 282u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1939u/* AppAccBytePosition */}, /*RParaPrkgOutVald*/
  {1u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1940u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald*/
  {1u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1941u/* AppAccBytePosition */}, /*TailVertPrkgOutVald*/
  {3u/*BitLength*/, 277u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1942u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1943u/* AppAccBytePosition */}, /*P2P_PahDelSts*/
  {4u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1944u/* AppAccBytePosition */}, /*P2P_SelfDetErrCode*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1945u/* AppAccBytePosition */}, /*P2P_SelfDetSts*/
  {1u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1946u/* AppAccBytePosition */}, /*P2P_Pah1Avail*/
  {1u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1947u/* AppAccBytePosition */}, /*P2P_Pah2Avail*/
  {4u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1948u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts*/
  {2u/*BitLength*/, 294u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1949u/* AppAccBytePosition */}, /*APS_MovgDirc*/
  {1u/*BitLength*/, 293u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1950u/* AppAccBytePosition */}, /*P2P_PrkgDirectSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1951u/* AppAccBytePosition */}, /*HAP_FD1_0x15B*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2015u/* AppAccBytePosition */}, /*AutoAVMSwtSet_Sts*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2016u/* AppAccBytePosition */}, /*AVM_CurrSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2017u/* AppAccBytePosition */}, /*GuidOvlSts*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2018u/* AppAccBytePosition */}, /*FrntCamInpFailSts*/
  {1u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2019u/* AppAccBytePosition */}, /*RearCamInpFailSts*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2020u/* AppAccBytePosition */}, /*LeCamInpFailSts*/
  {1u/*BitLength*/, 111u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2021u/* AppAccBytePosition */}, /*RiCamInpFailSts*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2022u/* AppAccBytePosition */}, /*EolNotCmpltd*/
  {1u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2023u/* AppAccBytePosition */}, /*OvlOpFailSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2024u/* AppAccBytePosition */}, /*LaneCalSts*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2025u/* AppAccBytePosition */}, /*RadarDispSts*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2026u/* AppAccBytePosition */}, /*LaneCalFltSts*/
  {1u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2027u/* AppAccBytePosition */}, /*AutoViewChgFuncSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2028u/* AppAccBytePosition */}, /*CarMdlTrsprcySts*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2029u/* AppAccBytePosition */}, /*CarMdlDispSts*/
  {1u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2030u/* AppAccBytePosition */}, /*CurrCalResultSts*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2031u/* AppAccBytePosition */}, /*MdlColrSts*/
  {6u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2032u/* AppAccBytePosition */}, /*SigViewIndcn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2033u/* AppAccBytePosition */}, /*HAP_DispCmd*/
  {9u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2034u/* AppAccBytePosition */}, /*AVM_3DAngSts*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2036u/* AppAccBytePosition */}, /*MOD_WorkSts*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2037u/* AppAccBytePosition */}, /*MOD_AlarmSts*/
  {2u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2038u/* AppAccBytePosition */}, /*DVRWorkSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2039u/* AppAccBytePosition */}, /*HAP_Hmi_Index*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2040u/* AppAccBytePosition */}, /*HAP_FD2_0x274*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2104u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2105u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1*/
  {4u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2106u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2107u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3*/
  {4u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2108u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2109u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2110u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2111u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2*/
  {4u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2112u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2113u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4*/
  {4u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2114u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2115u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2116u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2117u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2118u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2119u/* AppAccBytePosition */}, /*SDW_SoundIndcn*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2120u/* AppAccBytePosition */}, /*SDWActiveSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2121u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1*/
  {4u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2122u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2*/
  {4u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2123u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1*/
  {4u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2124u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2125u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2126u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2127u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1*/
  {4u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2128u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2129u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2130u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2131u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2132u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2133u/* AppAccBytePosition */}, /*RPAS_WorkSts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2134u/* AppAccBytePosition */}, /*RPAS_SoundIndcn*/
  {2u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2135u/* AppAccBytePosition */}, /*MEBWorkSts*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2136u/* AppAccBytePosition */}, /*MEB_EnableSts*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2137u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2138u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2*/
  {4u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2139u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1*/
  {4u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2140u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2141u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2142u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2*/
  {4u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2143u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1*/
  {4u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2144u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2*/
  {1u/*BitLength*/, 239u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2145u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts*/
  {1u/*BitLength*/, 238u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2146u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 237u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2147u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 236u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2148u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts*/
  {2u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2149u/* AppAccBytePosition */}, /*FPAS_WorkSts*/
  {1u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2150u/* AppAccBytePosition */}, /*FPAS_AutoModSts*/
  {2u/*BitLength*/, 246u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2151u/* AppAccBytePosition */}, /*FPAS_SoundIndcn*/
  {7u/*BitLength*/, 252u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2152u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn*/
  {4u/*BitLength*/, 276u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2153u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2154u/* AppAccBytePosition */}, /*APA_FuncSts*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2155u/* AppAccBytePosition */}, /*P2P_FuncSts*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2156u/* AppAccBytePosition */}, /*RADS_FuncSts*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2157u/* AppAccBytePosition */}, /*FADS_FuncSts*/
  {2u/*BitLength*/, 274u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2158u/* AppAccBytePosition */}, /*HAP_TextIconDispCtrl*/
  {1u/*BitLength*/, 447u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2159u/* AppAccBytePosition */}, /*FrntCamDirtySts*/
  {1u/*BitLength*/, 445u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2160u/* AppAccBytePosition */}, /*LeCamDirtySts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2161u/* AppAccBytePosition */}, /*HAP_FD3_0x298*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2225u/* AppAccBytePosition */}, /*HAP_RtCam_WorkSts*/
  {12u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2226u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_Y*/
  {12u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2228u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_Y*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2230u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_Y*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2232u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2234u/* AppAccBytePosition */}, /*HAP_FD6_0x289*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2298u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_Diag*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2299u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_DiagValid*/
  {5u/*BitLength*/, 299u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2300u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x60*/
  {3u/*BitLength*/, 317u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2301u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x60*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2302u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x60*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2303u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2304u/* AppAccBytePosition */}, /*HCU_AccelPedalPosnValid*/
  {4u/*BitLength*/, 364u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2305u/* AppAccBytePosition */}, /*HCU_CruiseCtrlSts*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2306u/* AppAccBytePosition */}, /*HCU_TgtCrsVehSpd*/
  {1u/*BitLength*/, 363u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2307u/* AppAccBytePosition */}, /*HCU_TgtCrsVehSpdvalid*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2308u/* AppAccBytePosition */}, /*HCU_FD1_0x60*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2372u/* AppAccBytePosition */}, /*HCU_BattLowTemWarn*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2373u/* AppAccBytePosition */}, /*HCU_BattLowHeatSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2374u/* AppAccBytePosition */}, /*HCU_BattLowTempWarn*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2375u/* AppAccBytePosition */}, /*HCU_BattLowTempHeatSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2376u/* AppAccBytePosition */}, /*HCU_HC3_0x268*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2384u/* AppAccBytePosition */}, /*HCU_ACLineDisconnect*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2385u/* AppAccBytePosition */}, /*HCU_ChargSts*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2386u/* AppAccBytePosition */}, /*HCU_IntelBattTempMagSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2387u/* AppAccBytePosition */}, /*HCU_HC6_0x314*/
  {10u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2395u/* AppAccBytePosition */}, /*HCU_RecupPwr*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2397u/* AppAccBytePosition */}, /*HCU_EVContnsDistance*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2398u/* AppAccBytePosition */}, /*HCU_EVContnsDistanceVld*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2399u/* AppAccBytePosition */}, /*HCU_EgyUsed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2401u/* AppAccBytePosition */}, /*HCU_HC7_0x3C2*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2409u/* AppAccBytePosition */}, /*HCU_TotalScore*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2410u/* AppAccBytePosition */}, /*HCU_HC8_0x1E2*/
  {4u/*BitLength*/, 46u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2418u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x9e*/
  {8u/*BitLength*/, 34u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 29u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2419u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x9e*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2420u/* AppAccBytePosition */}, /*TgtRcprtnTrqSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2421u/* AppAccBytePosition */}, /*HCU_HC16_0x9E*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2429u/* AppAccBytePosition */}, /*HCU_SOCMngmntSts*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2430u/* AppAccBytePosition */}, /*HCU_ARFSts*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2431u/* AppAccBytePosition */}, /*HCU_ASFCSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2432u/* AppAccBytePosition */}, /*HCU_AGSSts*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2433u/* AppAccBytePosition */}, /*PDCU_AvailabilityOfARF*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2434u/* AppAccBytePosition */}, /*PDCU_lossenPedalPrompt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2435u/* AppAccBytePosition */}, /*PDCU_EvSave_disl*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2436u/* AppAccBytePosition */}, /*HCU_V2LReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2437u/* AppAccBytePosition */}, /*HCU_HP5_0x201*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2445u/* AppAccBytePosition */}, /*HCU_HybMod*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2446u/* AppAccBytePosition */}, /*HCU_HybFctnMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2447u/* AppAccBytePosition */}, /*HCU_HP6_0x11A*/
  {9u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2455u/* AppAccBytePosition */}, /*HCU_TrqLimMax_Norm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2457u/* AppAccBytePosition */}, /*HCU_HP8_0xF9*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2465u/* AppAccBytePosition */}, /*HCU_TotalScore_P0*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2466u/* AppAccBytePosition */}, /*HCU_GearChngPorNTXT*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2467u/* AppAccBytePosition */}, /*HCU_SOCLow_Indcn*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2468u/* AppAccBytePosition */}, /*HCU_RemoveChrgLine_Indcn*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2469u/* AppAccBytePosition */}, /*HCU_Shift_P_Indcn*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2470u/* AppAccBytePosition */}, /*HCU_ConnectChrgLine_Indcn*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2471u/* AppAccBytePosition */}, /*HCU_EgyRecFB*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2472u/* AppAccBytePosition */}, /*HCU_OilTankCoverSts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2473u/* AppAccBytePosition */}, /*HCU_InhbChrgInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2474u/* AppAccBytePosition */}, /*ImdtlyChrgSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2475u/* AppAccBytePosition */}, /*HCU_EnerSavePowerMod*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2476u/* AppAccBytePosition */}, /*HCU_RefuReq*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2477u/* AppAccBytePosition */}, /*HCU_OPDFail*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2478u/* AppAccBytePosition */}, /*OPDParkWarnReq*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2479u/* AppAccBytePosition */}, /*HCU_ACStsReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2480u/* AppAccBytePosition */}, /*HCU_PT4_0x2FA*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2488u/* AppAccBytePosition */}, /*HCUImmoAuthRes*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2489u/* AppAccBytePosition */}, /*HCU_EVLmpSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 29u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2490u/* AppAccBytePosition */}, /*HCU_ECODrvHabit_Indcn*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 29u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2491u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x14a*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2492u/* AppAccBytePosition */}, /*HCU_AvailPower_TM*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2493u/* AppAccBytePosition */}, /*HCU_DrvMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2494u/* AppAccBytePosition */}, /*HCU_PT5_0x14A*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2502u/* AppAccBytePosition */}, /*HCU_12VSysErr_1*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2503u/* AppAccBytePosition */}, /*HCU_12VSysErr_2*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2504u/* AppAccBytePosition */}, /*HCU_HybSysErr_1*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2505u/* AppAccBytePosition */}, /*HCU_HybSysErr_2*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2506u/* AppAccBytePosition */}, /*HCU_HybSysErr_5*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2507u/* AppAccBytePosition */}, /*HCU_HybSysErr_6*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2508u/* AppAccBytePosition */}, /*HCU_HybSysErr_7*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2509u/* AppAccBytePosition */}, /*HCU_12VSysErrLmpSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2510u/* AppAccBytePosition */}, /*HCU_HybSysErrLmpSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2511u/* AppAccBytePosition */}, /*HCU_PowerRedWarnLmpCmd*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2512u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2513u/* AppAccBytePosition */}, /*HCU_HybSysErr_3*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2514u/* AppAccBytePosition */}, /*HCU_RdyLmpSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2515u/* AppAccBytePosition */}, /*CheckSum_HCU_PT7*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2516u/* AppAccBytePosition */}, /*HCU_HybSysErr_4*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2517u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd_P2*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2518u/* AppAccBytePosition */}, /*HCU_12VSysErr_3*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2519u/* AppAccBytePosition */}, /*HCU_OPDLmpSts*/
  {3u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2520u/* AppAccBytePosition */}, /*HCU_OPDSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2521u/* AppAccBytePosition */}, /*HCU_ModSwtFail*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2522u/* AppAccBytePosition */}, /*RollingCounter_HCU_PT7*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2523u/* AppAccBytePosition */}, /*HCU_PT7_0x248*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2531u/* AppAccBytePosition */}, /*HCU_ChrgSysLmpSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2532u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_1*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2533u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_2*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2534u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_3*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2535u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_4*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2536u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_5*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2537u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_6*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2538u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_7*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2539u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_8*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2540u/* AppAccBytePosition */}, /*HCU_DrvModDisp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2541u/* AppAccBytePosition */}, /*HCU_PT8_0x1C0*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2549u/* AppAccBytePosition */}, /*IB_Warn*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2550u/* AppAccBytePosition */}, /*IBooster_FD2_0x120*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2614u/* AppAccBytePosition */}, /*IFCTrqOvlCmdProtnValue*/
  {11u/*BitLength*/, 45u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 33u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2616u/* AppAccBytePosition */}, /*IFCTrqOvlCmdReqValue*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2618u/* AppAccBytePosition */}, /*IFC1_0x109*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2626u/* AppAccBytePosition */}, /*Checksum_IFC3*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2627u/* AppAccBytePosition */}, /*LDWResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2628u/* AppAccBytePosition */}, /*LKAResp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2629u/* AppAccBytePosition */}, /*LCKResp*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2630u/* AppAccBytePosition */}, /*ELKResp*/
  {2u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2631u/* AppAccBytePosition */}, /*LDW_LKA_Snvty*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2632u/* AppAccBytePosition */}, /*IFCHUTInterface*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2633u/* AppAccBytePosition */}, /*LSSWarnFormResp*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2634u/* AppAccBytePosition */}, /*LSSResp*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2635u/* AppAccBytePosition */}, /*AESSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2636u/* AppAccBytePosition */}, /*ESSSts*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2637u/* AppAccBytePosition */}, /*AESErrSts*/
  {1u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2638u/* AppAccBytePosition */}, /*ESSErrSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2639u/* AppAccBytePosition */}, /*RollingCounter_IFC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2640u/* AppAccBytePosition */}, /*Checksum_IFC4*/
  {3u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2641u/* AppAccBytePosition */}, /*IFC_Handsoffwarn*/
  {2u/*BitLength*/, 153u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2642u/* AppAccBytePosition */}, /*IFCCalibrationSts*/
  {1u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2643u/* AppAccBytePosition */}, /*CameraBlockageSts*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2644u/* AppAccBytePosition */}, /*LDW_LKAWarn*/
  {3u/*BitLength*/, 139u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2645u/* AppAccBytePosition */}, /*LSSIntervention*/
  {3u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2646u/* AppAccBytePosition */}, /*LSSFuncSts*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2647u/* AppAccBytePosition */}, /*ELKMainState*/
  {2u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2648u/* AppAccBytePosition */}, /*LaneAvailability*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2649u/* AppAccBytePosition */}, /*TJA_FollowSts*/
  {3u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2650u/* AppAccBytePosition */}, /*LSSErrSts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2651u/* AppAccBytePosition */}, /*AESintervention*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2652u/* AppAccBytePosition */}, /*ESSintervention*/
  {2u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2653u/* AppAccBytePosition */}, /*ELKActSts*/
  {2u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2654u/* AppAccBytePosition */}, /*IntelligentEvaActSts*/
  {2u/*BitLength*/, 162u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2655u/* AppAccBytePosition */}, /*LCKStsIndcr*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2656u/* AppAccBytePosition */}, /*RollingCounter_IFC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2657u/* AppAccBytePosition */}, /*Checksum_IFC5*/
  {12u/*BitLength*/, 212u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2658u/* AppAccBytePosition */}, /*IFC_LaneCurve*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2660u/* AppAccBytePosition */}, /*IFC_LeLaneTyp*/
  {3u/*BitLength*/, 222u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2661u/* AppAccBytePosition */}, /*IFC_RiLaneTyp*/
  {3u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2662u/* AppAccBytePosition */}, /*IFC_NextLeLaneTyp*/
  {3u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2663u/* AppAccBytePosition */}, /*IFC_NextRiLaneTyp*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2664u/* AppAccBytePosition */}, /*IFC_LeLane_dy*/
  {12u/*BitLength*/, 240u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2666u/* AppAccBytePosition */}, /*IFC_RiLane_dy*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2668u/* AppAccBytePosition */}, /*RollingCounter_IFC5*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2669u/* AppAccBytePosition */}, /*Checksum_IFC6*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2670u/* AppAccBytePosition */}, /*IFC_NextLeLane_dy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2672u/* AppAccBytePosition */}, /*IFC_NextRiLane_dy*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2674u/* AppAccBytePosition */}, /*RollingCounter_IFC6*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2675u/* AppAccBytePosition */}, /*AESResp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2676u/* AppAccBytePosition */}, /*ESS_Pedresp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2677u/* AppAccBytePosition */}, /*ESS_Vehresp*/
  {1u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2678u/* AppAccBytePosition */}, /*IntelligentEvaResp*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 2679u/* AppAccBytePosition */}, /*IFC_FD2_0x23D*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2735u/* AppAccBytePosition */}, /*TSRResp*/
  {2u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2736u/* AppAccBytePosition */}, /*TSRSpdLimUnit*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2737u/* AppAccBytePosition */}, /*TSRSpdLim*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2738u/* AppAccBytePosition */}, /*TSRSpdLimCfdc*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2739u/* AppAccBytePosition */}, /*TSRSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2740u/* AppAccBytePosition */}, /*TSRSpdLimSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2741u/* AppAccBytePosition */}, /*TSRTrfcSignValCfdc*/
  {8u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2742u/* AppAccBytePosition */}, /*TSRTrfcSignVal*/
  {1u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2743u/* AppAccBytePosition */}, /*TSRSpdLimWarn*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2744u/* AppAccBytePosition */}, /*TSRWarnResp*/
  {5u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2745u/* AppAccBytePosition */}, /*TSR_Snvty*/
  {2u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2746u/* AppAccBytePosition */}, /*IDC_L2_TurnLightReq*/
  {2u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2747u/* AppAccBytePosition */}, /*HWA_TakOver_Req*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2748u/* AppAccBytePosition */}, /*HWA_TakOver_Trig*/
  {4u/*BitLength*/, 138u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2749u/* AppAccBytePosition */}, /*HWA_WarnInfoDisp*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2750u/* AppAccBytePosition */}, /*IFC_Line01_Source*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2751u/* AppAccBytePosition */}, /*IFC_Line02_Source*/
  {3u/*BitLength*/, 181u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2752u/* AppAccBytePosition */}, /*HWA_InhibitWarn*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2753u/* AppAccBytePosition */}, /*HWA_ALC_Trig*/
  {4u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2754u/* AppAccBytePosition */}, /*MRC_InterSysInfoDisp*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2755u/* AppAccBytePosition */}, /*MRC_TakOver_Req*/
  {4u/*BitLength*/, 154u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2756u/* AppAccBytePosition */}, /*NOH_WarnInfoDisp*/
  {1u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2757u/* AppAccBytePosition */}, /*ALC_SwtReq_Resp*/
  {1u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2758u/* AppAccBytePosition */}, /*RainMode_Swt_Resp*/
  {2u/*BitLength*/, 226u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2759u/* AppAccBytePosition */}, /*LCMode_Swt_Resp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2760u/* AppAccBytePosition */}, /*IFC_FD3_0x2CF*/
  {13u/*BitLength*/, 19u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2824u/* AppAccBytePosition */}, /*IFC_Line01_Dy*/
  {15u/*BitLength*/, 36u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2826u/* AppAccBytePosition */}, /*IFC_Line01_Curv*/
  {20u/*BitLength*/, 48u/* BitPosition */, 3u/* ByteLength */, 6u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2828u/* AppAccBytePosition */}, /*IFC_Line01_CurvChange*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2832u/* AppAccBytePosition */}, /*IFC_Line01_Type*/
  {13u/*BitLength*/, 83u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2833u/* AppAccBytePosition */}, /*IFC_Line02_Dy*/
  {15u/*BitLength*/, 100u/* BitPosition */, 3u/* ByteLength */, 12u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2835u/* AppAccBytePosition */}, /*IFC_Line02_Curv*/
  {20u/*BitLength*/, 112u/* BitPosition */, 3u/* ByteLength */, 14u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2837u/* AppAccBytePosition */}, /*IFC_Line02_CurvChange*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2841u/* AppAccBytePosition */}, /*IFC_Line02_Type*/
  {13u/*BitLength*/, 147u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2842u/* AppAccBytePosition */}, /*IFC_Line03_Dy*/
  {15u/*BitLength*/, 164u/* BitPosition */, 3u/* ByteLength */, 20u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2844u/* AppAccBytePosition */}, /*IFC_Line03_Curv*/
  {20u/*BitLength*/, 176u/* BitPosition */, 3u/* ByteLength */, 22u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2846u/* AppAccBytePosition */}, /*IFC_Line03_CurvChange*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2850u/* AppAccBytePosition */}, /*IFC_Line03_Type*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2851u/* AppAccBytePosition */}, /*IFC_Line04_Dy*/
  {15u/*BitLength*/, 228u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2853u/* AppAccBytePosition */}, /*IFC_Line04_Curv*/
  {20u/*BitLength*/, 240u/* BitPosition */, 3u/* ByteLength */, 30u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2855u/* AppAccBytePosition */}, /*IFC_Line04_CurvChange*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2859u/* AppAccBytePosition */}, /*IFC_Line04_Type*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2860u/* AppAccBytePosition */}, /*IFC_Roadedge01_Dy*/
  {15u/*BitLength*/, 292u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2862u/* AppAccBytePosition */}, /*IFC_Roadedge01_Curv*/
  {20u/*BitLength*/, 304u/* BitPosition */, 3u/* ByteLength */, 38u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2864u/* AppAccBytePosition */}, /*IFC_Roadedge01_CurvChange*/
  {4u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2868u/* AppAccBytePosition */}, /*IFC_Roadedge01_Type*/
  {13u/*BitLength*/, 339u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2869u/* AppAccBytePosition */}, /*IFC_Roadedge02_Dy*/
  {15u/*BitLength*/, 356u/* BitPosition */, 3u/* ByteLength */, 44u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2871u/* AppAccBytePosition */}, /*IFC_Roadedge02_Curv*/
  {20u/*BitLength*/, 368u/* BitPosition */, 3u/* ByteLength */, 46u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2873u/* AppAccBytePosition */}, /*IFC_Roadedge02_CurvChange*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2877u/* AppAccBytePosition */}, /*IFC_Roadedge02_Type*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2878u/* AppAccBytePosition */}, /*IFC_FD5_0x19F*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2942u/* AppAccBytePosition */}, /*IFC_Line01_DxStart*/
  {15u/*BitLength*/, 34u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2944u/* AppAccBytePosition */}, /*IFC_Line01_DxEnd*/
  {9u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2946u/* AppAccBytePosition */}, /*IFC_Line01_HeadingAngle*/
  {9u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2948u/* AppAccBytePosition */}, /*IFC_Line02_HeadingAngle*/
  {15u/*BitLength*/, 81u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2950u/* AppAccBytePosition */}, /*IFC_Line02_DxStart*/
  {15u/*BitLength*/, 97u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2952u/* AppAccBytePosition */}, /*IFC_Line02_DxEnd*/
  {15u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2954u/* AppAccBytePosition */}, /*IFC_Line03_DxStart*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2956u/* AppAccBytePosition */}, /*IFC_Line03_DxEnd*/
  {9u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2958u/* AppAccBytePosition */}, /*IFC_Line03_HeadingAngle*/
  {15u/*BitLength*/, 169u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2960u/* AppAccBytePosition */}, /*IFC_Line04_DxStart*/
  {9u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2962u/* AppAccBytePosition */}, /*IFC_Line04_HeadingAngle*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2964u/* AppAccBytePosition */}, /*IFC_Line04_DxEnd*/
  {15u/*BitLength*/, 225u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2966u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxStart*/
  {15u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2968u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxEnd*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2970u/* AppAccBytePosition */}, /*IFC_Roadedge01_HeadingAngle*/
  {15u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2972u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxStart*/
  {15u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2974u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxEnd*/
  {9u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2976u/* AppAccBytePosition */}, /*IFC_Roadedge02_HeadingAngle*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2978u/* AppAccBytePosition */}, /*IFC_FD6_0x222*/
  {14u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3042u/* AppAccBytePosition */}, /*P2M_ActTrq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3044u/* AppAccBytePosition */}, /*P2M1_0xAC*/
  {16u/*BitLength*/, 60u/* BitPosition */, 3u/* ByteLength */, 7u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3052u/* AppAccBytePosition */}, /*P2M_ActSpd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3054u/* AppAccBytePosition */}, /*P2M3_0xBE*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3062u/* AppAccBytePosition */}, /*PassWinPosnSts_Perc*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3063u/* AppAccBytePosition */}, /*PassWinLrnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3064u/* AppAccBytePosition */}, /*PassWinHotProtSts*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3065u/* AppAccBytePosition */}, /*PassSideRearWinPosnSts_Perc*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3066u/* AppAccBytePosition */}, /*PassSideRearWinLrnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3067u/* AppAccBytePosition */}, /*PassSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3068u/* AppAccBytePosition */}, /*PDCM1_0x2CD*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3076u/* AppAccBytePosition */}, /*SysPowerMod*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3077u/* AppAccBytePosition */}, /*SysPowerModVld*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3078u/* AppAccBytePosition */}, /*PEPS_PowerRlyOutpSts*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3079u/* AppAccBytePosition */}, /*RemUpgrdModSysPower*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3080u/* AppAccBytePosition */}, /*PEPS2_0x295*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3088u/* AppAccBytePosition */}, /*WarnPowerNotInOffPosn*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3089u/* AppAccBytePosition */}, /*WarnKeyInCarWhenExit*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3090u/* AppAccBytePosition */}, /*WarnVldKeyNotFound*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3091u/* AppAccBytePosition */}, /*WarnEngStrtNotMeet*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3092u/* AppAccBytePosition */}, /*PowerRlyFault*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3093u/* AppAccBytePosition */}, /*PEPS4_0x302*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3101u/* AppAccBytePosition */}, /*RSDS_IPSoundReq*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3102u/* AppAccBytePosition */}, /*RSDS_ErrSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3103u/* AppAccBytePosition */}, /*RSDS_BrkgTrig*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3104u/* AppAccBytePosition */}, /*RSDS_BliSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3105u/* AppAccBytePosition */}, /*RSDS_TrailerSts*/
  {1u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3106u/* AppAccBytePosition */}, /*RSDS_LCAResp*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3107u/* AppAccBytePosition */}, /*RSDS_DOWResp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3108u/* AppAccBytePosition */}, /*RSDS_RCWResp*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3109u/* AppAccBytePosition */}, /*RSDS_RCTAResp*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3110u/* AppAccBytePosition */}, /*RSDS_RCTABrkResp*/
  {2u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3111u/* AppAccBytePosition */}, /*RSDS_RCW_Trigger*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3112u/* AppAccBytePosition */}, /*RSDS_CTA_Actv*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3113u/* AppAccBytePosition */}, /*BSD_LCA_warningReqRight*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3114u/* AppAccBytePosition */}, /*BSD_LCA_warningReqleft*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3115u/* AppAccBytePosition */}, /*DOW_warningReqRight*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3116u/* AppAccBytePosition */}, /*DOW_warningReqleft*/
  {1u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3117u/* AppAccBytePosition */}, /*RCTA_warningReqRight*/
  {1u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3118u/* AppAccBytePosition */}, /*RCTA_warningReqLeft*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3119u/* AppAccBytePosition */}, /*RSDS_FD1_0x16F*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3183u/* AppAccBytePosition */}, /*RCTA_B_TTC*/
  {6u/*BitLength*/, 20u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3184u/* AppAccBytePosition */}, /*BSD_LCA_Left_TTC*/
  {6u/*BitLength*/, 30u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3185u/* AppAccBytePosition */}, /*BSD_LCA_Right_TTC*/
  {6u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3186u/* AppAccBytePosition */}, /*RCW_TTC*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3187u/* AppAccBytePosition */}, /*RSDS_LeTgt_01*/
  {10u/*BitLength*/, 94u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3188u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dx*/
  {7u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3190u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dy*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3191u/* AppAccBytePosition */}, /*RSDS_LeTgt_02*/
  {10u/*BitLength*/, 99u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3192u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dx*/
  {7u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3194u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dy*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3195u/* AppAccBytePosition */}, /*RSDS_RiTgt_01*/
  {10u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3196u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dx*/
  {7u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3198u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dy*/
  {1u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3199u/* AppAccBytePosition */}, /*RSDS_RiTgt_02*/
  {10u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3200u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dx*/
  {7u/*BitLength*/, 167u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3202u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dy*/
  {1u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3203u/* AppAccBytePosition */}, /*RSDS_MidTgt_01*/
  {10u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3204u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dx*/
  {7u/*BitLength*/, 181u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3206u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dy*/
  {1u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3207u/* AppAccBytePosition */}, /*RSDS_MidTgt_02*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3208u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dx*/
  {7u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3210u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dy*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3211u/* AppAccBytePosition */}, /*RSDS_FD2_0x30A*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3275u/* AppAccBytePosition */}, /*HiPosnBrkLmpFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3276u/* AppAccBytePosition */}, /*LBrkLmpFailSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3277u/* AppAccBytePosition */}, /*RFogLmpFailSts_R_PBox*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3278u/* AppAccBytePosition */}, /*RFogLmpSts_R_PBox*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3279u/* AppAccBytePosition */}, /*ParkLmpSts_R_PBox*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3280u/* AppAccBytePosition */}, /*RBrkLmpFailSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3281u/* AppAccBytePosition */}, /*PosnLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3282u/* AppAccBytePosition */}, /*RRPosnLmpFailSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3283u/* AppAccBytePosition */}, /*RvsLmpFailSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3284u/* AppAccBytePosition */}, /*LRPosnLmpFailSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3285u/* AppAccBytePosition */}, /*LTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3286u/* AppAccBytePosition */}, /*RTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3287u/* AppAccBytePosition */}, /*RWinHeatgIconRlyCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3288u/* AppAccBytePosition */}, /*RWinHeatgFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3289u/* AppAccBytePosition */}, /*LicPlateLmpFailSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3290u/* AppAccBytePosition */}, /*RTurnLmpFailSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3291u/* AppAccBytePosition */}, /*LTurnLmpFailSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3292u/* AppAccBytePosition */}, /*RBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3293u/* AppAccBytePosition */}, /*HiPosnBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3294u/* AppAccBytePosition */}, /*LBrkLmpOutpSts_R_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3295u/* AppAccBytePosition */}, /*R_PBOX1_0x19C*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3303u/* AppAccBytePosition */}, /*DrvSeatHeatSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3304u/* AppAccBytePosition */}, /*PassSeatHeatSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3305u/* AppAccBytePosition */}, /*DrvSeatVentnSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3306u/* AppAccBytePosition */}, /*PassSeatVentnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3307u/* AppAccBytePosition */}, /*SCM1_0x2D1*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3315u/* AppAccBytePosition */}, /*STBS_SoundReq*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3316u/* AppAccBytePosition */}, /*VolUpReq_SC*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3317u/* AppAccBytePosition */}, /*VolDwnReq_SC*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3318u/* AppAccBytePosition */}, /*DispTODReq_SC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3319u/* AppAccBytePosition */}, /*MuteReq_SC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3320u/* AppAccBytePosition */}, /*STBS1_0x21F*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3328u/* AppAccBytePosition */}, /*FuncProtnSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3329u/* AppAccBytePosition */}, /*ShiftSysStuInLow*/
  {4u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3330u/* AppAccBytePosition */}, /*SystemOperMod*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3331u/* AppAccBytePosition */}, /*CouplingFaultSts*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3332u/* AppAccBytePosition */}, /*EstimatedTorque*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3334u/* AppAccBytePosition */}, /*CouplingThermWarning*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3335u/* AppAccBytePosition */}, /*DiagLmpReq*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3336u/* AppAccBytePosition */}, /*SystemOperModDisp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3337u/* AppAccBytePosition */}, /*TOD1_0x251*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3345u/* AppAccBytePosition */}, /*FLTirePressIndSts*/
  {3u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3346u/* AppAccBytePosition */}, /*FRTirePressIndSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3347u/* AppAccBytePosition */}, /*TirePressSysFailrIndcn*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3348u/* AppAccBytePosition */}, /*RLTirePressIndSts*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3349u/* AppAccBytePosition */}, /*RRTirePressIndSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3350u/* AppAccBytePosition */}, /*FLTireTempSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3351u/* AppAccBytePosition */}, /*FRTireTempSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3352u/* AppAccBytePosition */}, /*RLTireTempSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3353u/* AppAccBytePosition */}, /*RRTireTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3354u/* AppAccBytePosition */}, /*TPMS1_0x341*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3362u/* AppAccBytePosition */}, /*FLTirePress*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3363u/* AppAccBytePosition */}, /*FLTireTemp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3364u/* AppAccBytePosition */}, /*FRTirePress*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3365u/* AppAccBytePosition */}, /*FRTireTemp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3366u/* AppAccBytePosition */}, /*RLTirePress*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3367u/* AppAccBytePosition */}, /*RLTireTemp*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3368u/* AppAccBytePosition */}, /*RRTirePress*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3369u/* AppAccBytePosition */}, /*RRTireTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3370u/* AppAccBytePosition */}, /*TPMS2_0x395*/
  {3u/*BitLength*/, 5u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3378u/* AppAccBytePosition */}, /*T_BOX_RemtDoorLockCtrl*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3379u/* AppAccBytePosition */}, /*T_BOX_AudioMuteReq*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3380u/* AppAccBytePosition */}, /*T_BOX_PM25AirQLvl*/
  {10u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 33u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3381u/* AppAccBytePosition */}, /*T_BOX_PM25Dens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3383u/* AppAccBytePosition */}, /*T_BOX_FD1_0x33*/
  {5u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3391u/* AppAccBytePosition */}, /*T_BOX_SysErrSts*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3392u/* AppAccBytePosition */}, /*T_BOX_SWUpdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3393u/* AppAccBytePosition */}, /*T_BOX_FD3_0x3E9*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3401u/* AppAccBytePosition */}, /*T_BOX_RemtVideoMonrEnaReq_APP*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 41u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3402u/* AppAccBytePosition */}, /*T_BOX_FD4_0x1E1*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3418u/* AppAccBytePosition */}, /*V2X_FCW*/
  {4u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3419u/* AppAccBytePosition */}, /*V2X_BSW*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3420u/* AppAccBytePosition */}, /*V2X_LCW*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3421u/* AppAccBytePosition */}, /*V2X_EBW*/
  {4u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3422u/* AppAccBytePosition */}, /*V2X_ICW*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3423u/* AppAccBytePosition */}, /*V2X_LTA*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3424u/* AppAccBytePosition */}, /*V2X_IVSW*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3425u/* AppAccBytePosition */}, /*V2X_AVW*/
  {3u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3426u/* AppAccBytePosition */}, /*V2X_EVW*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3427u/* AppAccBytePosition */}, /*V2X_DNPW*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3428u/* AppAccBytePosition */}, /*V2X_HLW*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3429u/* AppAccBytePosition */}, /*V2X_TJW*/
  {6u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3430u/* AppAccBytePosition */}, /*V2X_CLW*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3431u/* AppAccBytePosition */}, /*V2X_RLVW*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3432u/* AppAccBytePosition */}, /*V2X_VRUCW*/
  {6u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3433u/* AppAccBytePosition */}, /*V2X_SLW*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3434u/* AppAccBytePosition */}, /*V2X_GLOSA*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3435u/* AppAccBytePosition */}, /*V2X_SL1_LightTyp*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3436u/* AppAccBytePosition */}, /*V2X_SL1_LightColor*/
  {16u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3437u/* AppAccBytePosition */}, /*V2X_SL1_LightTim*/
  {4u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3439u/* AppAccBytePosition */}, /*V2X_SL2_LightTyp*/
  {4u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3440u/* AppAccBytePosition */}, /*V2X_SL2_LightColor*/
  {16u/*BitLength*/, 144u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3441u/* AppAccBytePosition */}, /*V2X_SL2_LightTim*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3443u/* AppAccBytePosition */}, /*V2X_SL3_LightTyp*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3444u/* AppAccBytePosition */}, /*V2X_SL3_LightColor*/
  {16u/*BitLength*/, 168u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3445u/* AppAccBytePosition */}, /*V2X_SL3_LightTim*/
  {4u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3447u/* AppAccBytePosition */}, /*V2X_SL4_LightTyp*/
  {4u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3448u/* AppAccBytePosition */}, /*V2X_SL4_LightColor*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3449u/* AppAccBytePosition */}, /*V2X_SL5_LightTyp*/
  {16u/*BitLength*/, 208u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3450u/* AppAccBytePosition */}, /*V2X_SL4_LightTim*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3452u/* AppAccBytePosition */}, /*V2X_SL5_LightColor*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3453u/* AppAccBytePosition */}, /*V2X_SL5_LightTim*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3455u/* AppAccBytePosition */}, /*V2X_SL6_LightTyp*/
  {4u/*BitLength*/, 244u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3456u/* AppAccBytePosition */}, /*V2X_SL6_LightColor*/
  {16u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3457u/* AppAccBytePosition */}, /*V2X_SL6_LightTim*/
  {4u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3459u/* AppAccBytePosition */}, /*V2X_SL7_LightTyp*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3460u/* AppAccBytePosition */}, /*V2X_SL7_LightColor*/
  {16u/*BitLength*/, 288u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3461u/* AppAccBytePosition */}, /*V2X_SL7_LightTim*/
  {4u/*BitLength*/, 300u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3463u/* AppAccBytePosition */}, /*V2X_SL8_LightTyp*/
  {4u/*BitLength*/, 296u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3464u/* AppAccBytePosition */}, /*V2X_SL8_LightColor*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3465u/* AppAccBytePosition */}, /*V2X_SL8_LightTim*/
  {4u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3467u/* AppAccBytePosition */}, /*V2X_SL_of_Veh*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3468u/* AppAccBytePosition */}, /*T_BOX_FD10_0x2F0*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3532u/* AppAccBytePosition */}, /*TrailerSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3533u/* AppAccBytePosition */}, /*Trailer1_0x273*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3541u/* AppAccBytePosition */}, /*VMDR_TmpMonFctnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3542u/* AppAccBytePosition */}, /*VMDR_InitAlarmDlySetSts*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3543u/* AppAccBytePosition */}, /*VMDR_FctnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3544u/* AppAccBytePosition */}, /*VMDR1_0x2FB*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3552u/* AppAccBytePosition */}, /*WPC_ChrgSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3553u/* AppAccBytePosition */}, /*WPC_SwtSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3554u/* AppAccBytePosition */}, /*WPC_FaultSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3555u/* AppAccBytePosition */}, /*WPC_PhoneReminder*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3556u/* AppAccBytePosition */}, /*WPC_ChrgSts_Pass*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3557u/* AppAccBytePosition */}, /*WPC1_0x2BA*/
};


const ComEx_RxGroupInfoType ComEx_RxGroupInfo[ComEx_RxGroupSize] = 
{
  {0u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*ABM1*/
  {7u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 1u/* E2eIdx */}, /*ACC3_ACC_FD2*/
  {7u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 2u/* E2eIdx */}, /*ACC4_ACC_FD2*/
  {7u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 3u/* E2eIdx */}, /*ACC8_ACC_FD2*/
  {7u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 4u/* E2eIdx */}, /*ACC6_ACC_FD2*/
  {7u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 5u/* E2eIdx */}, /*ACC7_ACC_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 6u/* E2eIdx */}, /*AEB2_AEB_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 7u/* E2eIdx */}, /*AEB3_AEB_FD2*/
  {24u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 8u/* E2eIdx */}, /*BMS4*/
  {38u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 9u/* E2eIdx */}, /*DCT_FD4*/
  {59u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 10u/* E2eIdx */}, /*EPB1*/
  {60u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 11u/* E2eIdx */}, /*EPS_FD1*/
  {64u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 12u/* E2eIdx */}, /*ESP2_ESP_FD2*/
  {64u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 13u/* E2eIdx */}, /*ESP1_ESP_FD2*/
  {64u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 14u/* E2eIdx */}, /*ABS3_ESP_FD2*/
  {67u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 15u/* E2eIdx */}, /*GW_FD1*/
  {85u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* E2eIdx */}, /*HCU_PT7*/
  {89u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 17u/* E2eIdx */}, /*IFC3_IFC_FD2*/
  {89u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 18u/* E2eIdx */}, /*IFC4_IFC_FD2*/
  {89u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 19u/* E2eIdx */}, /*IFC5_IFC_FD2*/
  {89u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 20u/* E2eIdx */}, /*IFC6_IFC_FD2*/
};


const ComEx_RxPduInfoType ComEx_RxPduInfo[ComEx_RxPduSize] = 
{
  {0u/* SignalStartIdx */, 16u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABM1*/
  {16u/* SignalStartIdx */, 23u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABM2*/
  {23u/* SignalStartIdx */, 26u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 16u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS1*/
  {26u/* SignalStartIdx */, 33u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 24u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS2*/
  {33u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 32u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC1*/
  {44u/* SignalStartIdx */, 59u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 40u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC2*/
  {59u/* SignalStartIdx */, 62u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 48u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC6*/
  {62u/* SignalStartIdx */, 147u/* SignalEndIdx */, 1u/* GroupStartIdx */, 6u/* GroupEndIdx */, 56u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ACC_FD2*/
  {147u/* SignalStartIdx */, 175u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 112u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD3*/
  {175u/* SignalStartIdx */, 244u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD4*/
  {244u/* SignalStartIdx */, 256u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AEB_FD1*/
  {256u/* SignalStartIdx */, 289u/* SignalEndIdx */, 6u/* GroupStartIdx */, 8u/* GroupEndIdx */, 304u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AEB_FD2*/
  {289u/* SignalStartIdx */, 291u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ALCM1*/
  {291u/* SignalStartIdx */, 307u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP1*/
  {307u/* SignalStartIdx */, 327u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AMP2*/
  {327u/* SignalStartIdx */, 334u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP3*/
  {334u/* SignalStartIdx */, 340u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP4_ANC1*/
  {340u/* SignalStartIdx */, 342u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP5_IESS1*/
  {342u/* SignalStartIdx */, 355u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM1*/
  {355u/* SignalStartIdx */, 362u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM3*/
  {362u/* SignalStartIdx */, 369u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM8*/
  {369u/* SignalStartIdx */, 380u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM11*/
  {380u/* SignalStartIdx */, 387u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM12*/
  {387u/* SignalStartIdx */, 389u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE5*/
  {389u/* SignalStartIdx */, 397u/* SignalEndIdx */, 8u/* GroupStartIdx */, 9u/* GroupEndIdx */, 456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS4*/
  {397u/* SignalStartIdx */, 400u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS8*/
  {400u/* SignalStartIdx */, 403u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 472u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS19*/
  {403u/* SignalStartIdx */, 405u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS22*/
  {405u/* SignalStartIdx */, 407u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 488u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS30*/
  {407u/* SignalStartIdx */, 409u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 496u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS65*/
  {409u/* SignalStartIdx */, 427u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 504u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS66*/
  {427u/* SignalStartIdx */, 431u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 512u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CP1*/
  {431u/* SignalStartIdx */, 439u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 520u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CR_FD1*/
  {439u/* SignalStartIdx */, 445u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 584u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA1*/
  {445u/* SignalStartIdx */, 449u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA2*/
  {449u/* SignalStartIdx */, 469u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA3*/
  {469u/* SignalStartIdx */, 472u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 608u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT3*/
  {472u/* SignalStartIdx */, 477u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 616u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT5*/
  {477u/* SignalStartIdx */, 492u/* SignalEndIdx */, 9u/* GroupStartIdx */, 10u/* GroupEndIdx */, 624u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT_FD4*/
  {492u/* SignalStartIdx */, 498u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 688u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM1*/
  {498u/* SignalStartIdx */, 500u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM3*/
  {500u/* SignalStartIdx */, 513u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DMS_FD2*/
  {513u/* SignalStartIdx */, 515u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 768u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSM1*/
  {515u/* SignalStartIdx */, 517u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 776u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EBOOSTER_FD1*/
  {517u/* SignalStartIdx */, 523u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 840u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM1*/
  {523u/* SignalStartIdx */, 533u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 848u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM2*/
  {533u/* SignalStartIdx */, 546u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 856u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM3*/
  {546u/* SignalStartIdx */, 549u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 864u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM4*/
  {549u/* SignalStartIdx */, 552u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 872u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM7*/
  {552u/* SignalStartIdx */, 554u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 880u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM9*/
  {554u/* SignalStartIdx */, 558u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 888u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM11*/
  {558u/* SignalStartIdx */, 569u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 896u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM16*/
  {569u/* SignalStartIdx */, 571u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 904u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM19*/
  {571u/* SignalStartIdx */, 573u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 912u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM20*/
  {573u/* SignalStartIdx */, 576u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 920u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT5*/
  {576u/* SignalStartIdx */, 580u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 928u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT6*/
  {580u/* SignalStartIdx */, 583u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 936u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT7*/
  {583u/* SignalStartIdx */, 588u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 944u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EEM1*/
  {588u/* SignalStartIdx */, 591u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 952u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ELD1*/
  {591u/* SignalStartIdx */, 599u/* SignalEndIdx */, 10u/* GroupStartIdx */, 11u/* GroupEndIdx */, 960u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPB1*/
  {599u/* SignalStartIdx */, 606u/* SignalEndIdx */, 11u/* GroupStartIdx */, 12u/* GroupEndIdx */, 968u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPS_FD1*/
  {606u/* SignalStartIdx */, 608u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1032u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESCL2*/
  {608u/* SignalStartIdx */, 613u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1040u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP8*/
  {613u/* SignalStartIdx */, 616u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1048u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP11*/
  {616u/* SignalStartIdx */, 645u/* SignalEndIdx */, 12u/* GroupStartIdx */, 15u/* GroupEndIdx */, 1056u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP_FD2*/
  {645u/* SignalStartIdx */, 660u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1112u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*F_PBOX1*/
  {660u/* SignalStartIdx */, 663u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1120u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GLO_NASS1*/
  {663u/* SignalStartIdx */, 674u/* SignalEndIdx */, 15u/* GroupStartIdx */, 16u/* GroupEndIdx */, 1128u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_FD1*/
  {674u/* SignalStartIdx */, 676u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1192u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_OTA*/
  {676u/* SignalStartIdx */, 679u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1200u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 2/* CalloutStartIdx */}, /*GW_Sync_Req*/
  {679u/* SignalStartIdx */, 703u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1216u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD1*/
  {703u/* SignalStartIdx */, 728u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1280u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD2*/
  {728u/* SignalStartIdx */, 786u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1344u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD3*/
  {786u/* SignalStartIdx */, 792u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1408u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD6*/
  {792u/* SignalStartIdx */, 803u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1472u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_FD1*/
  {803u/* SignalStartIdx */, 808u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1536u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC3*/
  {808u/* SignalStartIdx */, 812u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1544u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC6*/
  {812u/* SignalStartIdx */, 817u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1552u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC7*/
  {817u/* SignalStartIdx */, 819u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1560u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC8*/
  {819u/* SignalStartIdx */, 823u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1568u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC16*/
  {823u/* SignalStartIdx */, 832u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1576u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP5*/
  {832u/* SignalStartIdx */, 835u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1584u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP6*/
  {835u/* SignalStartIdx */, 837u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP8*/
  {837u/* SignalStartIdx */, 853u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT4*/
  {853u/* SignalStartIdx */, 860u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1608u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT5*/
  {860u/* SignalStartIdx */, 882u/* SignalEndIdx */, 16u/* GroupStartIdx */, 17u/* GroupEndIdx */, 1616u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT7*/
  {882u/* SignalStartIdx */, 893u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1624u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT8*/
  {893u/* SignalStartIdx */, 895u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1632u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IBooster_FD2*/
  {895u/* SignalStartIdx */, 898u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC1*/
  {898u/* SignalStartIdx */, 947u/* SignalEndIdx */, 17u/* GroupStartIdx */, 21u/* GroupEndIdx */, 1704u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*IFC_FD2*/
  {947u/* SignalStartIdx */, 973u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1760u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD3*/
  {973u/* SignalStartIdx */, 998u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1824u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD5*/
  {998u/* SignalStartIdx */, 1017u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1888u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD6*/
  {1017u/* SignalStartIdx */, 1019u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1952u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M1*/
  {1019u/* SignalStartIdx */, 1021u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1960u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M3*/
  {1021u/* SignalStartIdx */, 1028u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1968u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PDCM1*/
  {1028u/* SignalStartIdx */, 1033u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1976u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS2*/
  {1033u/* SignalStartIdx */, 1039u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1984u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS4*/
  {1039u/* SignalStartIdx */, 1058u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1992u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD1*/
  {1058u/* SignalStartIdx */, 1081u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2056u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD2*/
  {1081u/* SignalStartIdx */, 1102u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2120u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*R_PBOX1*/
  {1102u/* SignalStartIdx */, 1107u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2128u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*SCM1*/
  {1107u/* SignalStartIdx */, 1113u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2136u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*STBS1*/
  {1113u/* SignalStartIdx */, 1122u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2144u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*TOD1*/
  {1122u/* SignalStartIdx */, 1132u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2152u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS1*/
  {1132u/* SignalStartIdx */, 1141u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2160u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS2*/
  {1141u/* SignalStartIdx */, 1146u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2168u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD1*/
  {1146u/* SignalStartIdx */, 1149u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2176u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD3*/
  {1149u/* SignalStartIdx */, 1151u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2184u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD4*/
  {1151u/* SignalStartIdx */, 1194u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2200u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD10*/
  {1194u/* SignalStartIdx */, 1196u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2264u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Trailer1*/
  {1196u/* SignalStartIdx */, 1200u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2272u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VMDR1*/
  {1200u/* SignalStartIdx */, 1206u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2280u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*WPC1*/
};


const ComEx_RxSigInitValueInfoType ComEx_RxSigInitValueInfo[ComEx_RxInitValueSize] = 
{
  {1u/* byteLength */, 0u/* bytePosition */},
  {1u/* byteLength */, 1u/* bytePosition */},
  {8u/* byteLength */, 2u/* bytePosition */},
  {2u/* byteLength */, 10u/* bytePosition */},
  {2u/* byteLength */, 12u/* bytePosition */},
  {2u/* byteLength */, 14u/* bytePosition */},
  {1u/* byteLength */, 16u/* bytePosition */},
  {1u/* byteLength */, 17u/* bytePosition */},
  {1u/* byteLength */, 18u/* bytePosition */},
  {1u/* byteLength */, 19u/* bytePosition */},
  {1u/* byteLength */, 20u/* bytePosition */},
  {2u/* byteLength */, 21u/* bytePosition */},
  {1u/* byteLength */, 23u/* bytePosition */},
  {1u/* byteLength */, 24u/* bytePosition */},
  {56u/* byteLength */, 25u/* bytePosition */},
  {64u/* byteLength */, 81u/* bytePosition */},
  {2u/* byteLength */, 145u/* bytePosition */},
  {1u/* byteLength */, 147u/* bytePosition */},
  {1u/* byteLength */, 148u/* bytePosition */},
  {1u/* byteLength */, 149u/* bytePosition */},
  {1u/* byteLength */, 150u/* bytePosition */},
  {1u/* byteLength */, 151u/* bytePosition */},
  {1u/* byteLength */, 152u/* bytePosition */},
  {2u/* byteLength */, 153u/* bytePosition */},
  {1u/* byteLength */, 155u/* bytePosition */},
  {4u/* byteLength */, 156u/* bytePosition */},
  {2u/* byteLength */, 160u/* bytePosition */},
  {2u/* byteLength */, 162u/* bytePosition */},
  {11u/* byteLength */, 164u/* bytePosition */},
  {1u/* byteLength */, 175u/* bytePosition */},
  {2u/* byteLength */, 176u/* bytePosition */},
  {1u/* byteLength */, 178u/* bytePosition */},
  {2u/* byteLength */, 179u/* bytePosition */},
  {2u/* byteLength */, 181u/* bytePosition */},
  {2u/* byteLength */, 183u/* bytePosition */},
  {2u/* byteLength */, 185u/* bytePosition */},
  {2u/* byteLength */, 187u/* bytePosition */},
  {2u/* byteLength */, 189u/* bytePosition */},
  {4u/* byteLength */, 191u/* bytePosition */},
  {2u/* byteLength */, 195u/* bytePosition */},
  {2u/* byteLength */, 197u/* bytePosition */},
  {16u/* byteLength */, 199u/* bytePosition */},
};

const ComEx_RxSigTimeoutInfoType ComEx_RxSigTimeoutInfo[ComEx_RxTimeoutSize] = 
{
  {65535u/* byteLength */, 65535u/* bytePosition */, 1000u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 40u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 200u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 100u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 20u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 2000u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 400u/* TimeoutMax */},
};

const ComEx_RxE2eInfoType ComEx_RxE2eInfo[ComEx_RxE2eSize] = 
{
  {E2EPW_ReadInit_ABM1_E2E/* InitFunPtr */, E2EPW_Read_ABM1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC3_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC3_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC4_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC4_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC8_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC8_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC6_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC6_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC7_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC7_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_AEB2_AEB_FD2_E2E/* InitFunPtr */, E2EPW_Read_AEB2_AEB_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_AEB3_AEB_FD2_E2E/* InitFunPtr */, E2EPW_Read_AEB3_AEB_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_BMS4_E2E/* InitFunPtr */, E2EPW_Read_BMS4_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_DCT_FD4_E2E/* InitFunPtr */, E2EPW_Read_DCT_FD4_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPB1_E2E/* InitFunPtr */, E2EPW_Read_EPB1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPS_FD1_E2E/* InitFunPtr */, E2EPW_Read_EPS_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP2_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ESP2_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP1_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ESP1_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ABS3_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ABS3_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_GW_FD1_E2E/* InitFunPtr */, E2EPW_Read_GW_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_HCU_PT7_E2E/* InitFunPtr */, E2EPW_Read_HCU_PT7_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC3_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC3_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC4_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC4_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC5_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC5_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC6_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC6_IFC_FD2_E2E/* ReadFunPtr */},
};

const uint8 ComEx_RxInitValueBuffer[ComEx_RxInitValueBufferSize] =
{
  0x0u,
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x11u,
  0x56u,
  0x11u,
  0x22u,
  0x0u,
  0x0u,
  0xfeu,
  0x7u,
  0xfu,
  0x21u,
  0x3u,
  0xffu,
  0x7fu,
  0xffu,
  0x1eu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0x1u,
  0x3fu,
  0xau,
  0x2u,
  0x80u,
  0x7fu,
  0xb2u,
  0x10u,
  0x27u,
  0xeu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0x3fu,
  0xffu,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x64u,
  0x13u,
  0x1u,
  0x5u,
  0x1u,
  0x1cu,
  0xffu,
  0x3u,
  0xffu,
  0x7u,
  0xc0u,
  0x9u,
  0x9u,
  0xbu,
  0x9u,
  0x3du,
  0x0u,
  0x53u,
  0x7u,
  0x0u,
  0xc9u,
  0x0u,
  0xfeu,
  0x3fu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
};

const uint8 ComEx_RxTimeoutBuffer[ComEx_RxTimeoutBufferSize] = 
{
  0x0u
};

const uint8 ComEx_RxPduCalloutIdx[4] =
{
    0u, 2u, 1u, 2u
};

const ComEx_TxSigInfoType ComEx_TxSigInfo[ComEx_TxSignalSize]= 
{
  {11u/*BitLength*/, 149u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 25u/* BufferStartIdx */, 27u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnX*/
  {11u/*BitLength*/, 154u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 26u/* BufferStartIdx */, 28u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnY*/
  {11u/*BitLength*/, 175u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 27u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnZ*/
  {7u/*BitLength*/, 168u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 29u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosQlty*/
  {11u/*BitLength*/, 213u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 33u/* BufferStartIdx */, 35u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnX*/
  {11u/*BitLength*/, 218u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 34u/* BufferStartIdx */, 36u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnY*/
  {11u/*BitLength*/, 239u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 35u/* BufferStartIdx */, 38u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnZ*/
  {1u/*BitLength*/, 288u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadDetn*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 41u/* BufferStartIdx */, 42u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadYawAng*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 42u/* BufferStartIdx */, 43u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPitchAng*/
  {8u/*BitLength*/, 280u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 43u/* BufferStartIdx */, 44u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRollAng*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRotAngQlty*/
  {3u/*BitLength*/, 90u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvl_ACC*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 16u/* BufferStartIdx */, 17u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS2*/
  {7u/*BitLength*/, 73u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 17u/* BufferStartIdx */, 18u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvlQlty_ACC*/
  {7u/*BitLength*/, 81u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 18u/* BufferStartIdx */, 19u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvlQlty_ACC*/
  {3u/*BitLength*/, 93u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvl_ACC*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 23u/* BufferStartIdx */, 24u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 24u/* BufferStartIdx */, 25u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS3*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 31u/* BufferStartIdx */, 32u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS3*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 40u/* BufferStartIdx */, 41u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS5*/
  {3u/*BitLength*/, 301u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 45u/* BufferStartIdx */, 46u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMSSts*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 47u/* BufferStartIdx */, 48u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS5*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 48u/* BufferStartIdx */, 49u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS6*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 49u/* BufferStartIdx */, 50u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeYawAng*/
  {8u/*BitLength*/, 336u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 50u/* BufferStartIdx */, 51u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazePitchAng*/
  {7u/*BitLength*/, 345u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 51u/* BufferStartIdx */, 52u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenStsQlty*/
  {7u/*BitLength*/, 353u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 52u/* BufferStartIdx */, 53u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenStsQlty*/
  {7u/*BitLength*/, 361u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 53u/* BufferStartIdx */, 54u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeAngQlty*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenSts*/
  {2u/*BitLength*/, 372u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenSts*/
  {3u/*BitLength*/, 368u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvBehvSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 55u/* BufferStartIdx */, 56u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS6*/
  {3u/*BitLength*/, 11u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 9u/* BufferStartIdx */, 10u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvl*/
  {7u/*BitLength*/, 20u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 9u/* BufferStartIdx */, 11u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvlQlty*/
  {2u/*BitLength*/, 35u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GenderSts*/
  {7u/*BitLength*/, 41u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 13u/* BufferStartIdx */, 14u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GenderStsQlty*/
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExprsnSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 1u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 8u/* BufferStartIdx */, 72u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMS_FD1_0x24D*/
  {1u/*BitLength*/, 9u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_360VideoCaptureReq*/
  {3u/*BitLength*/, 26u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 75u/* BufferStartIdx */, 76u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRRemtCnSts*/
  {48u/*BitLength*/, 104u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 6u/* BusAccBtyeLength */, 80u/* BufferStartIdx */, 86u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSN*/
  {4u/*BitLength*/, 12u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 72u/* BufferStartIdx */, 136u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_FD1_0x2EC*/
  {3u/*BitLength*/, 5u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DomeLmpDlyTimSet*/
  {3u/*BitLength*/, 1u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FolwMeHomeDlyTimSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*TranPMode_Req*/
  {1u/*BitLength*/, 14u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearviewFoldModSet*/
  {2u/*BitLength*/, 12u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BattSaveDelayTimeSet*/
  {2u/*BitLength*/, 20u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_TC*/
  {2u/*BitLength*/, 18u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_TC*/
  {2u/*BitLength*/, 16u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_TC*/
  {1u/*BitLength*/, 33u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 140u/* BufferStartIdx */, 141u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntHMIDis_TC*/
  {1u/*BitLength*/, 32u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 140u/* BufferStartIdx */, 141u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearHMIDis_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_TC*/
  {2u/*BitLength*/, 28u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACCmprReq_TC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntDefrstReq_TC*/
  {2u/*BitLength*/, 24u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntBlwrSpdDecReq_TC*/
  {1u/*BitLength*/, 23u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearBlwrSpdDecReq_TC*/
  {1u/*BitLength*/, 22u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearBlwrSpdIncReq_TC*/
  {1u/*BitLength*/, 36u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 140u/* BufferStartIdx */, 141u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDrowsnsDetnSet*/
  {2u/*BitLength*/, 46u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntBlwrSpdIncReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvAirDistribModReq_TC*/
  {2u/*BitLength*/, 41u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempDecReq_TC*/
  {1u/*BitLength*/, 40u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnEna*/
  {2u/*BitLength*/, 54u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempIncReq_TC*/
  {2u/*BitLength*/, 52u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntPassTempDecReq_TC*/
  {2u/*BitLength*/, 50u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntPassTempIncReq_TC*/
  {1u/*BitLength*/, 48u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOffReq_TC*/
  {4u/*BitLength*/, 56u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrsteplsSpdReq_TC*/
  {1u/*BitLength*/, 4u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACZoneReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 3u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT1_0x367*/
  {2u/*BitLength*/, 40u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 149u/* BufferStartIdx */, 150u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearWinHeatCmd_TC*/
  {4u/*BitLength*/, 4u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 144u/* BufferStartIdx */, 145u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_MediaCallSourceSet*/
  {3u/*BitLength*/, 37u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 148u/* BufferStartIdx */, 149u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_NaviSourceSet*/
  {3u/*BitLength*/, 0u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 144u/* BufferStartIdx */, 145u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_BeepSourceSet*/
  {5u/*BitLength*/, 11u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 145u/* BufferStartIdx */, 146u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_LRAudioBalanceSet*/
  {2u/*BitLength*/, 8u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 145u/* BufferStartIdx */, 146u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_AudioVolVSCModReq*/
  {5u/*BitLength*/, 19u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 146u/* BufferStartIdx */, 147u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_FRAudioFaderSet*/
  {1u/*BitLength*/, 17u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 146u/* BufferStartIdx */, 147u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_LRDrvSideSet*/
  {5u/*BitLength*/, 27u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 147u/* BufferStartIdx */, 148u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_LowFrqAudioSet*/
  {1u/*BitLength*/, 25u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 147u/* BufferStartIdx */, 148u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_MuteSet*/
  {5u/*BitLength*/, 43u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 149u/* BufferStartIdx */, 150u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_MidFrqAudioSet*/
  {5u/*BitLength*/, 51u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 150u/* BufferStartIdx */, 151u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_HighFrqAudioSet*/
  {1u/*BitLength*/, 50u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 150u/* BufferStartIdx */, 151u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*T_box_ECallSet*/
  {1u/*BitLength*/, 49u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 150u/* BufferStartIdx */, 151u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*QLISurroundSet*/
  {1u/*BitLength*/, 36u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 148u/* BufferStartIdx */, 149u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ANCSwtSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 4u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 144u/* BufferStartIdx */, 152u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT2_0x369*/
  {6u/*BitLength*/, 2u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 152u/* BufferStartIdx */, 153u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_HFMVolSet*/
  {6u/*BitLength*/, 10u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 153u/* BufferStartIdx */, 154u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_TTSVolSet_VR*/
  {6u/*BitLength*/, 18u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 154u/* BufferStartIdx */, 155u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_NaviVolSet*/
  {6u/*BitLength*/, 26u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 155u/* BufferStartIdx */, 156u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_MainVolSet*/
  {1u/*BitLength*/, 33u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_GetSWInfoReq*/
  {1u/*BitLength*/, 32u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_GetHWInfoReq*/
  {1u/*BitLength*/, 41u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 157u/* BufferStartIdx */, 158u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_GetTempInfoReq*/
  {1u/*BitLength*/, 40u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 157u/* BufferStartIdx */, 158u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_GetIntVoltInfoReq*/
  {1u/*BitLength*/, 49u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 158u/* BufferStartIdx */, 159u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_GetDTCInfoReq*/
  {2u/*BitLength*/, 34u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IESS_MdlSwtReq*/
  {1u/*BitLength*/, 1u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 152u/* BufferStartIdx */, 153u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IESS_MdlInfoReq*/
  {3u/*BitLength*/, 37u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_BestListegPosnReq*/
  {1u/*BitLength*/, 43u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 157u/* BufferStartIdx */, 158u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AMP_Clari_FiReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 5u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 152u/* BufferStartIdx */, 160u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT3_0x36B*/
  {2u/*BitLength*/, 8u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACCmprReq_VR*/
  {2u/*BitLength*/, 36u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPowerReq_VR*/
  {4u/*BitLength*/, 32u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrSpdReq_VR*/
  {6u/*BitLength*/, 42u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempReq_VR*/
  {2u/*BitLength*/, 40u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntDefrostReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvAirDistribModReq_VR*/
  {2u/*BitLength*/, 51u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_VR*/
  {2u/*BitLength*/, 62u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACModReq_HUT*/
  {1u/*BitLength*/, 21u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ElecSideSteppingSysSet*/
  {1u/*BitLength*/, 18u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RoofModSet*/
  {1u/*BitLength*/, 29u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AllTerrainDislSet*/
  {1u/*BitLength*/, 56u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RemUpgrdSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAutoModReq_TC*/
  {3u/*BitLength*/, 5u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatSupportLvlSet*/
  {3u/*BitLength*/, 0u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatSupportLvlSet*/
  {1u/*BitLength*/, 10u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearOffReq_TC*/
  {3u/*BitLength*/, 48u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAirDistribModReq_TC*/
  {2u/*BitLength*/, 14u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgLvlSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatHeatgLvlSet*/
  {2u/*BitLength*/, 30u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatHeatgLvlSet*/
  {2u/*BitLength*/, 27u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatHeatgLvlSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 6u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT4_0x36D*/
  {2u/*BitLength*/, 5u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_TC*/
  {2u/*BitLength*/, 3u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_VR*/
  {1u/*BitLength*/, 42u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 173u/* BufferStartIdx */, 174u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LaneCalActvtCmd*/
  {1u/*BitLength*/, 62u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MODChgReq*/
  {1u/*BitLength*/, 40u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 173u/* BufferStartIdx */, 174u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Radar_DispCmd*/
  {1u/*BitLength*/, 7u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Guid_Ovl_Display_Cmd*/
  {4u/*BitLength*/, 33u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 172u/* BufferStartIdx */, 173u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Sgl_View_Sel*/
  {1u/*BitLength*/, 58u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SwToFieldCalRstCmd*/
  {1u/*BitLength*/, 55u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 174u/* BufferStartIdx */, 175u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoViewChgCmd*/
  {1u/*BitLength*/, 53u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 174u/* BufferStartIdx */, 175u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MdlColrChgCmd*/
  {1u/*BitLength*/, 49u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 174u/* BufferStartIdx */, 175u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CarMdlTrsprcySwtCmd*/
  {1u/*BitLength*/, 63u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CarMdlDispCmd*/
  {1u/*BitLength*/, 57u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoAVMSwSet_Cmd*/
  {1u/*BitLength*/, 60u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FPAS_AutoModSwt*/
  {1u/*BitLength*/, 61u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MEBSwtSet*/
  {1u/*BitLength*/, 56u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WshSoftSwt*/
  {1u/*BitLength*/, 59u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*View_SoftswitchCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 7u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT6_0x4A*/
  {2u/*BitLength*/, 6u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRTmpMonFctnSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRInitAlarmDlySet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 180u/* BufferStartIdx */, 181u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OTA_UpgrdModReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT7_0x44*/
  {2u/*BitLength*/, 10u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_VR*/
  {2u/*BitLength*/, 8u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_VR*/
  {2u/*BitLength*/, 40u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearDefrstReq_VR*/
  {6u/*BitLength*/, 48u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassTempReq_VR*/
  {2u/*BitLength*/, 56u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_VR*/
  {1u/*BitLength*/, 47u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt*/
  {1u/*BitLength*/, 46u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynSwt*/
  {6u/*BitLength*/, 32u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 188u/* BufferStartIdx */, 189u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet*/
  {1u/*BitLength*/, 24u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt*/
  {6u/*BitLength*/, 58u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IPVolSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASSwtReq_VR*/
  {2u/*BitLength*/, 4u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 185u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EgyRecvrySet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 9u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT10_0x331*/
  {7u/*BitLength*/, 33u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 196u/* BufferStartIdx */, 197u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*WeatherCdn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 10u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 192u/* BufferStartIdx */, 200u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT12_0x3AF*/
  {2u/*BitLength*/, 14u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AudioMuteSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OrvmPosnEnaSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ORVMFoldSwt_HUT*/
  {4u/*BitLength*/, 28u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ORVMLensAdjmt_HUT*/
  {4u/*BitLength*/, 24u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvSeatAdjmt_HUT*/
  {4u/*BitLength*/, 36u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrivingModReq_VR*/
  {2u/*BitLength*/, 54u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DampgDrvModeReq*/
  {1u/*BitLength*/, 19u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FrntELDLckSwtReq_HUT*/
  {1u/*BitLength*/, 18u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FrntELDLckSwtErrSts_HUT*/
  {1u/*BitLength*/, 17u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RearELDLckSwtReq_HUT*/
  {1u/*BitLength*/, 16u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RearELDLckSwtErrSts_HUT*/
  {1u/*BitLength*/, 8u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*VSGSwtSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 11u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT13_0x31C*/
  {2u/*BitLength*/, 6u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_VR*/
  {6u/*BitLength*/, 18u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 210u/* BufferStartIdx */, 211u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_TC*/
  {6u/*BitLength*/, 26u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 211u/* BufferStartIdx */, 212u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassSetTempSteplsReq_TC*/
  {1u/*BitLength*/, 39u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SDWSwtSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSSwtReq_VR*/
  {2u/*BitLength*/, 33u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSPrkgTypSeln*/
  {4u/*BitLength*/, 40u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 213u/* BufferStartIdx */, 214u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunShadeSwtReq_VR*/
  {4u/*BitLength*/, 44u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 213u/* BufferStartIdx */, 214u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunRoofSwtReq_VR*/
  {2u/*BitLength*/, 0u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SportModLightSet*/
  {1u/*BitLength*/, 14u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ABSLmpSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoWshWipSet*/
  {2u/*BitLength*/, 9u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeekVehSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 211u/* BufferStartIdx */, 212u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SpdAutoLockModSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkLmpSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DoorUnlockModSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SteerWheelHeatSwtReq*/
  {2u/*BitLength*/, 52u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASExitSpdSwt*/
  {2u/*BitLength*/, 48u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FrntRearACDispSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 12u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 216u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT15_0x1EE*/
  {1u/*BitLength*/, 39u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PowerSet*/
  {1u/*BitLength*/, 38u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_CallSts_Dialing*/
  {1u/*BitLength*/, 37u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_CallSts_IncomingCall*/
  {1u/*BitLength*/, 36u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_CallSts_ongoing*/
  {24u/*BitLength*/, 24u/* BitPosition */, 13u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 217u/* BufferStartIdx */, 220u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_CallTime*/
  {64u/*BitLength*/, 0u/* BitPosition */, 13u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 224u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT16_0x348*/
  {4u/*BitLength*/, 36u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 228u/* BufferStartIdx */, 229u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackgroundLightLvlSet*/
  {4u/*BitLength*/, 32u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 228u/* BufferStartIdx */, 229u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ManCmpSet*/
  {2u/*BitLength*/, 46u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 229u/* BufferStartIdx */, 230u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DispModSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WPC_SwtReq*/
  {1u/*BitLength*/, 19u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AVMSwtReq*/
  {4u/*BitLength*/, 28u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviMediaVolLvlReq*/
  {4u/*BitLength*/, 24u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AVMMediaVolLvlReq*/
  {1u/*BitLength*/, 18u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FPASChanSwtReq*/
  {1u/*BitLength*/, 17u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RPASChanSwtReq*/
  {4u/*BitLength*/, 0u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 225u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearBlwrSpdReq_VR*/
  {4u/*BitLength*/, 4u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 225u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearBlwrsteplsSpdReq_TC*/
  {2u/*BitLength*/, 54u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 230u/* BufferStartIdx */, 231u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PLGReq_VR*/
  {3u/*BitLength*/, 40u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 229u/* BufferStartIdx */, 230u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAirDistribModReq_VR*/
  {2u/*BitLength*/, 8u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 225u/* BufferStartIdx */, 226u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACZoneReq_VR*/
  {2u/*BitLength*/, 52u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 230u/* BufferStartIdx */, 231u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OPDSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 14u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT17_0x33B*/
  {3u/*BitLength*/, 5u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 233u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MsgTyp*/
  {3u/*BitLength*/, 2u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 233u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapProvider*/
  {10u/*BitLength*/, 8u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 234u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CountryCode*/
  {2u/*BitLength*/, 22u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CycCnt*/
  {2u/*BitLength*/, 20u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Major*/
  {3u/*BitLength*/, 17u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_MinorSub*/
  {9u/*BitLength*/, 24u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_HwVer*/
  {1u/*BitLength*/, 39u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 236u/* BufferStartIdx */, 237u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_DrvSide*/
  {15u/*BitLength*/, 40u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 236u/* BufferStartIdx */, 238u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_RegionCode*/
  {2u/*BitLength*/, 54u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 238u/* BufferStartIdx */, 239u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerQtr*/
  {6u/*BitLength*/, 48u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 238u/* BufferStartIdx */, 239u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerYear*/
  {1u/*BitLength*/, 60u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 239u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_SpdUnits*/
  {4u/*BitLength*/, 56u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 239u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Minor*/
  {64u/*BitLength*/, 0u/* BitPosition */, 15u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT19_0x415*/
  {3u/*BitLength*/, 5u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 241u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 242u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Update*/
  {32u/*BitLength*/, 56u/* BitPosition */, 16u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 4u/* BusAccBtyeLength */, 244u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Value*/
  {64u/*BitLength*/, 0u/* BitPosition */, 16u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT20_0x2DE*/
  {3u/*BitLength*/, 5u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 249u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 250u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Update*/
  {2u/*BitLength*/, 38u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 253u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_AccurClass*/
  {10u/*BitLength*/, 44u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Dist1*/
  {10u/*BitLength*/, 50u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 255u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value0*/
  {10u/*BitLength*/, 56u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 254u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 17u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT21_0x2DD*/
  {3u/*BitLength*/, 5u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 257u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 18u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 258u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 258u/* BufferStartIdx */, 259u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 258u/* BufferStartIdx */, 259u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PathIdx*/
  {2u/*BitLength*/, 30u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Tunnel*/
  {2u/*BitLength*/, 28u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Brdg*/
  {2u/*BitLength*/, 26u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_BuildUpArea*/
  {1u/*BitLength*/, 25u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 260u/* BufferStartIdx */, 261u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 260u/* BufferStartIdx */, 261u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FormOfWay*/
  {5u/*BitLength*/, 51u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 262u/* BufferStartIdx */, 263u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmt*/
  {3u/*BitLength*/, 48u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 262u/* BufferStartIdx */, 263u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmtTyp*/
  {2u/*BitLength*/, 61u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_DivideRoad*/
  {2u/*BitLength*/, 59u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 18u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT22_0x2DA*/
  {3u/*BitLength*/, 5u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 264u/* BufferStartIdx */, 265u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 19u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 264u/* BufferStartIdx */, 266u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 266u/* BufferStartIdx */, 267u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 266u/* BufferStartIdx */, 267u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PathIdx*/
  {6u/*BitLength*/, 26u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 267u/* BufferStartIdx */, 268u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_StubPathIdx*/
  {1u/*BitLength*/, 25u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 267u/* BufferStartIdx */, 268u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 267u/* BufferStartIdx */, 268u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 268u/* BufferStartIdx */, 269u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 268u/* BufferStartIdx */, 269u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 269u/* BufferStartIdx */, 270u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 269u/* BufferStartIdx */, 270u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 269u/* BufferStartIdx */, 270u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FormOfWay*/
  {8u/*BitLength*/, 48u/* BitPosition */, 19u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 270u/* BufferStartIdx */, 271u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_TurnAngl*/
  {1u/*BitLength*/, 63u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_LastStub*/
  {2u/*BitLength*/, 61u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RtOfWay*/
  {2u/*BitLength*/, 59u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 19u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 264u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT23_0x2D8*/
  {2u/*BitLength*/, 26u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_RemtEngCtrl*/
  {5u/*BitLength*/, 55u/* BitPosition */, 20u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 277u/* BufferStartIdx */, 279u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempReq_ETC_VR*/
  {5u/*BitLength*/, 50u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 278u/* BufferStartIdx */, 279u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_ETC_TC*/
  {2u/*BitLength*/, 44u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 277u/* BufferStartIdx */, 278u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*GazeAreaInteractionSetUp*/
  {2u/*BitLength*/, 38u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 276u/* BufferStartIdx */, 277u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OccptAttrSetUp*/
  {2u/*BitLength*/, 28u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ChrgnMode*/
  {2u/*BitLength*/, 24u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BattKeepTemp*/
  {2u/*BitLength*/, 48u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 278u/* BufferStartIdx */, 279u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_IntelEngIdlChrgnSet*/
  {2u/*BitLength*/, 56u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 279u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_IntelBattTempMagSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 20u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 272u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT25_0x339*/
  {4u/*BitLength*/, 36u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 284u/* BufferStartIdx */, 285u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PassSeatAdjmtSwt_HUT*/
  {3u/*BitLength*/, 53u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SeatFlankAdjmtSwt_HUT*/
  {64u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT26_0x2B6*/
  {5u/*BitLength*/, 8u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_HeightLvlSwt*/
  {4u/*BitLength*/, 28u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 291u/* BufferStartIdx */, 292u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_BrightnessLvlSwt*/
  {2u/*BitLength*/, 24u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 291u/* BufferStartIdx */, 292u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_SwtReq*/
  {1u/*BitLength*/, 13u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_AVM*/
  {2u/*BitLength*/, 4u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMIHWSwtSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMIBSRSwtSet*/
  {2u/*BitLength*/, 52u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 294u/* BufferStartIdx */, 295u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EnrollFaceReq*/
  {4u/*BitLength*/, 48u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 294u/* BufferStartIdx */, 295u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EnrollUserIDResult*/
  {4u/*BitLength*/, 60u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 295u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeleteUserIDFaceData*/
  {2u/*BitLength*/, 42u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 293u/* BufferStartIdx */, 294u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EraseAllFaceUsersReq*/
  {2u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IdnResultReq_HUT*/
  {2u/*BitLength*/, 46u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 293u/* BufferStartIdx */, 294u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FaceIdnSet*/
  {2u/*BitLength*/, 34u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 292u/* BufferStartIdx */, 293u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DistrctnDetnSet*/
  {2u/*BitLength*/, 32u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 292u/* BufferStartIdx */, 293u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrowsnsDetnSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT30_0x1E9*/
  {64u/*BitLength*/, 56u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_PhoneNextRoad*/
  {64u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT31_0x30C*/
  {8u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_HUT32*/
  {2u/*BitLength*/, 46u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ScrnOpSts*/
  {11u/*BitLength*/, 29u/* BitPosition */, 24u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*XLvl*/
  {11u/*BitLength*/, 32u/* BitPosition */, 24u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 309u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*YLvl*/
  {1u/*BitLength*/, 9u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DetVideoLost*/
  {1u/*BitLength*/, 10u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkgCtrlModReqValid*/
  {2u/*BitLength*/, 12u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkgCtrlModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ContnPrkgReqValid*/
  {2u/*BitLength*/, 14u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ContnPrkgReq*/
  {1u/*BitLength*/, 11u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSwtReq_HUT*/
  {2u/*BitLength*/, 27u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSuspendOrFinishReq_HUT*/
  {3u/*BitLength*/, 61u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 311u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightModSel_HUT*/
  {1u/*BitLength*/, 60u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 311u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSts_HUT*/
  {1u/*BitLength*/, 45u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightStrtReq_HUT*/
  {1u/*BitLength*/, 44u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightVehStrtReq_HUT_Valid*/
  {1u/*BitLength*/, 55u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightContinueReq_HUT*/
  {1u/*BitLength*/, 54u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*P2P_PrkgDirSwtReq*/
  {1u/*BitLength*/, 51u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RainMode_Swt_Req*/
  {2u/*BitLength*/, 49u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCMode_Swt_Req*/
  {4u/*BitLength*/, 56u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 311u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_HUT32*/
  {64u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT32_0x26F*/
  {2u/*BitLength*/, 4u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 313u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FlaoutUnlockSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkInDirChoice*/
  {2u/*BitLength*/, 60u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt*/
  {2u/*BitLength*/, 56u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt*/
  {2u/*BitLength*/, 58u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt_VR*/
  {2u/*BitLength*/, 62u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt_VR*/
  {2u/*BitLength*/, 6u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 313u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApproachLampSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 313u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SuperLockSet*/
  {3u/*BitLength*/, 50u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 316u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLWinSwtReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRWinSwtReq_VR*/
  {3u/*BitLength*/, 13u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvWinSwtReq_VR*/
  {3u/*BitLength*/, 35u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 316u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassWinSwtReq_VR*/
  {3u/*BitLength*/, 8u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt*/
  {1u/*BitLength*/, 17u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngFinshCmd*/
  {1u/*BitLength*/, 18u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngStartCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkOutDirReq*/
  {1u/*BitLength*/, 25u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath2Cmd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath2Cmd*/
  {1u/*BitLength*/, 27u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath1Cmd*/
  {1u/*BitLength*/, 28u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath1Cmd*/
  {3u/*BitLength*/, 29u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkgFctnCmd*/
  {1u/*BitLength*/, 19u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkMdlCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_APS*/
  {2u/*BitLength*/, 46u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAEnaReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAChanTyp_TC*/
  {3u/*BitLength*/, 40u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGALvlReq_TC*/
  {2u/*BitLength*/, 48u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgRmdTempSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT33_0x1ED*/
  {1u/*BitLength*/, 16u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeMod*/
  {1u/*BitLength*/, 17u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeIndcn*/
  {5u/*BitLength*/, 11u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Hour*/
  {6u/*BitLength*/, 18u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Minutes*/
  {6u/*BitLength*/, 26u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Second*/
  {4u/*BitLength*/, 36u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 324u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Left*/
  {4u/*BitLength*/, 32u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 324u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Right*/
  {4u/*BitLength*/, 44u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Month*/
  {5u/*BitLength*/, 51u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Day*/
  {6u/*BitLength*/, 61u/* BitPosition */, 26u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_TgtSOCSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT34_0x370*/
  {5u/*BitLength*/, 19u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempReq_ETC_VR*/
  {5u/*BitLength*/, 27u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempSteplsReq_ETC_TC*/
  {2u/*BitLength*/, 38u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 34u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 46u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearPowerReq_VR*/
  {2u/*BitLength*/, 25u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_VR*/
  {2u/*BitLength*/, 17u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FrntWiprCtrl_VR*/
  {2u/*BitLength*/, 42u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAutoModReq_VR*/
  {1u/*BitLength*/, 49u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockWinSet*/
  {2u/*BitLength*/, 44u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearLockReq_TC*/
  {2u/*BitLength*/, 57u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DPF_Request*/
  {64u/*BitLength*/, 0u/* BitPosition */, 27u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT35_0x1E5*/
  {2u/*BitLength*/, 6u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempDecReq_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempIncReq_TC*/
  {6u/*BitLength*/, 10u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 337u/* BufferStartIdx */, 338u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempReq_VR*/
  {2u/*BitLength*/, 2u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempDecReq_TC*/
  {2u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempIncReq_TC*/
  {6u/*BitLength*/, 18u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempReq_VR*/
  {2u/*BitLength*/, 16u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempSteplsReq_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_VR*/
  {2u/*BitLength*/, 28u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_TC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_TC*/
  {2u/*BitLength*/, 24u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_VR*/
  {2u/*BitLength*/, 34u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_VR*/
  {64u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT38_0x1E7*/
  {1u/*BitLength*/, 7u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryLockSet*/
  {1u/*BitLength*/, 6u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryUnlockSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockPromptFunSet*/
  {1u/*BitLength*/, 3u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPAEntryLockSet*/
  {1u/*BitLength*/, 2u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPALvngUnlockSet*/
  {2u/*BitLength*/, 0u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ClsWinSpdSet*/
  {3u/*BitLength*/, 21u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgLvlSet*/
  {3u/*BitLength*/, 18u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgLvlSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 346u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeatKeyMemEna*/
  {3u/*BitLength*/, 29u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgLvlSet*/
  {3u/*BitLength*/, 26u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgLvlSet*/
  {1u/*BitLength*/, 9u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 346u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OilBoxSplyReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 29u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT39_0x1EB*/
  {6u/*BitLength*/, 32u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempSteplsReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT42_0x1F9*/
  {4u/*BitLength*/, 20u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 362u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgModSet*/
  {4u/*BitLength*/, 16u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 362u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgModSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT43_0x1FD*/
  {4u/*BitLength*/, 8u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgModSet*/
  {4u/*BitLength*/, 12u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgModSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMI_P_BSR_SwtSet*/
  {2u/*BitLength*/, 16u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RWPC_SwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT45_0x1DC*/
  {2u/*BitLength*/, 22u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ARFSwtReq*/
  {2u/*BitLength*/, 20u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ASFCSwtReq*/
  {2u/*BitLength*/, 18u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AGSSwtReq*/
  {2u/*BitLength*/, 16u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SOCMngmntSwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT46_0x1DD*/
  {2u/*BitLength*/, 54u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 390u/* BufferStartIdx */, 391u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SmokeFuncSetUp*/
  {2u/*BitLength*/, 52u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 390u/* BufferStartIdx */, 391u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CallingFuncSetUp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT48_0x1F4*/
  {1u/*BitLength*/, 9u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 393u/* BufferStartIdx */, 394u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntellgntcurveReq*/
  {1u/*BitLength*/, 64u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 400u/* BufferStartIdx */, 401u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SSSSet_HUT*/
  {2u/*BitLength*/, 76u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 402u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IFC_SnvtySet*/
  {1u/*BitLength*/, 104u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DOWSwtReq*/
  {1u/*BitLength*/, 105u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_PedSwtReq*/
  {4u/*BitLength*/, 72u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 402u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMLightLvlSet*/
  {1u/*BitLength*/, 86u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FlashLmpSwtReq*/
  {1u/*BitLength*/, 85u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCASwtReq*/
  {1u/*BitLength*/, 84u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTASwtReq*/
  {1u/*BitLength*/, 83u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTABrkSwtReq*/
  {1u/*BitLength*/, 82u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCWSwtReq*/
  {2u/*BitLength*/, 80u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCW_SnvtySet*/
  {1u/*BitLength*/, 95u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_VehSwtReq*/
  {1u/*BitLength*/, 93u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LKASwtReq*/
  {1u/*BitLength*/, 92u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCKSwtReq*/
  {1u/*BitLength*/, 91u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ELKSwtReq*/
  {1u/*BitLength*/, 90u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_PedSwtReq*/
  {1u/*BitLength*/, 89u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_VehSwtReq*/
  {1u/*BitLength*/, 88u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 403u/* BufferStartIdx */, 404u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LDWSwtReq*/
  {1u/*BitLength*/, 102u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRSwtReq*/
  {1u/*BitLength*/, 101u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRWarnSwtReq*/
  {1u/*BitLength*/, 127u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 407u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ICA_HandsOffSwtReq*/
  {1u/*BitLength*/, 126u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 407u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ISLSwtReq*/
  {5u/*BitLength*/, 121u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 407u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSR_SnvtySet*/
  {1u/*BitLength*/, 87u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HFASwtSts*/
  {2u/*BitLength*/, 113u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EPSSteerModSwtReq*/
  {1u/*BitLength*/, 112u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DSTSwtReq*/
  {2u/*BitLength*/, 99u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSWarnFormSwtReq*/
  {1u/*BitLength*/, 98u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_ESPFuncOffSwtSts*/
  {4u/*BitLength*/, 108u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrivingModReq_HUT*/
  {1u/*BitLength*/, 120u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 407u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvgModeMemReq*/
  {1u/*BitLength*/, 107u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntelligentEvaSwtReq*/
  {1u/*BitLength*/, 106u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSSwtReq*/
  {12u/*BitLength*/, 148u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 409u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUTRadioFrq*/
  {4u/*BitLength*/, 156u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 411u/* BufferStartIdx */, 412u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MediaPlaySrc*/
  {2u/*BitLength*/, 168u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 413u/* BufferStartIdx */, 414u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_AudioSts*/
  {2u/*BitLength*/, 176u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 414u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_VideoSts*/
  {2u/*BitLength*/, 178u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 414u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*BT_AudioSts*/
  {2u/*BitLength*/, 180u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 414u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IPod_Sts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 414u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AM_Sts*/
  {2u/*BitLength*/, 184u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 415u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FM_Sts*/
  {2u/*BitLength*/, 186u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 415u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*APPLink_Sts*/
  {2u/*BitLength*/, 188u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 415u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*QQMusic_Sts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 415u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*KaolaFM_Sts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OnlineNews_Sts*/
  {3u/*BitLength*/, 173u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 413u/* BufferStartIdx */, 414u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ECM*/
  {3u/*BitLength*/, 170u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 413u/* BufferStartIdx */, 414u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TCU*/
  {2u/*BitLength*/, 162u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 412u/* BufferStartIdx */, 413u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TOD*/
  {1u/*BitLength*/, 147u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OffroadThmSts*/
  {2u/*BitLength*/, 243u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 422u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSet*/
  {4u/*BitLength*/, 252u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 423u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ChairMemPosnSetResult*/
  {1u/*BitLength*/, 224u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 420u/* BufferStartIdx */, 421u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TABSwtReq_HUT*/
  {10u/*BitLength*/, 246u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavVehToTrafEyeDist*/
  {4u/*BitLength*/, 308u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 430u/* BufferStartIdx */, 431u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavRoadType*/
  {2u/*BitLength*/, 306u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 430u/* BufferStartIdx */, 431u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimType*/
  {6u/*BitLength*/, 266u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimValue*/
  {2u/*BitLength*/, 264u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimUnit_HUT*/
  {10u/*BitLength*/, 286u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavCtryType*/
  {3u/*BitLength*/, 283u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimSignSts*/
  {8u/*BitLength*/, 288u/* BitPosition */, 35u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 428u/* BufferStartIdx */, 429u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavTSRTrafSign*/
  {1u/*BitLength*/, 298u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AESSwtReq*/
  {1u/*BitLength*/, 280u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SwtReq*/
  {2u/*BitLength*/, 302u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SnvtySet*/
  {1u/*BitLength*/, 301u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTASwtReq*/
  {1u/*BitLength*/, 300u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTABrkSwtReq*/
  {1u/*BitLength*/, 299u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_JASwtReq*/
  {1u/*BitLength*/, 297u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_WarnFormSwtReq*/
  {1u/*BitLength*/, 316u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 431u/* BufferStartIdx */, 432u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SteerCorrnReq*/
  {1u/*BitLength*/, 296u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALC_SwtReq*/
  {1u/*BitLength*/, 319u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 431u/* BufferStartIdx */, 432u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModSwtReq_HUT*/
  {2u/*BitLength*/, 317u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 431u/* BufferStartIdx */, 432u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ESP*/
  {3u/*BitLength*/, 325u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 432u/* BufferStartIdx */, 433u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_MsgTye*/
  {13u/*BitLength*/, 328u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 432u/* BufferStartIdx */, 434u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Offset*/
  {2u/*BitLength*/, 342u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CycCnt*/
  {6u/*BitLength*/, 336u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Pathldx*/
  {2u/*BitLength*/, 350u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Idx*/
  {5u/*BitLength*/, 345u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosProbb*/
  {9u/*BitLength*/, 352u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 437u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Age*/
  {3u/*BitLength*/, 364u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosConfdc*/
  {3u/*BitLength*/, 361u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CurLane*/
  {9u/*BitLength*/, 368u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Spd*/
  {8u/*BitLength*/, 376u/* BitPosition */, 35u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 439u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Rehead*/
  {1u/*BitLength*/, 70u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 400u/* BufferStartIdx */, 401u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*EngStrtDischrgn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HybModReq*/
  {2u/*BitLength*/, 116u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_HybFctnReq*/
  {4u/*BitLength*/, 164u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 412u/* BufferStartIdx */, 413u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_DrvModReq*/
  {448u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 56u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD1_0x2C3*/
  {4u/*BitLength*/, 12u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 449u/* BufferStartIdx */, 450u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 449u/* BufferStartIdx */, 450u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 452u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HTU_OD_Obj1_ID*/
  {3u/*BitLength*/, 85u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 458u/* BufferStartIdx */, 459u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_type*/
  {4u/*BitLength*/, 72u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Confidence*/
  {7u/*BitLength*/, 94u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 458u/* BufferStartIdx */, 460u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_width*/
  {12u/*BitLength*/, 108u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 460u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 112u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_ID*/
  {3u/*BitLength*/, 149u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 467u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_type*/
  {4u/*BitLength*/, 136u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Confidence*/
  {7u/*BitLength*/, 158u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_width*/
  {12u/*BitLength*/, 172u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 468u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 176u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 471u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 473u/* BufferStartIdx */, 474u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_ID*/
  {3u/*BitLength*/, 213u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 475u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_type*/
  {4u/*BitLength*/, 200u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 473u/* BufferStartIdx */, 474u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Confidence*/
  {7u/*BitLength*/, 222u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 476u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_width*/
  {12u/*BitLength*/, 236u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 476u/* BufferStartIdx */, 478u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 240u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 477u/* BufferStartIdx */, 479u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 268u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_ID*/
  {3u/*BitLength*/, 277u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 483u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_type*/
  {4u/*BitLength*/, 264u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Confidence*/
  {7u/*BitLength*/, 286u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 484u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_width*/
  {12u/*BitLength*/, 300u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 484u/* BufferStartIdx */, 486u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 304u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 485u/* BufferStartIdx */, 487u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_Y*/
  {4u/*BitLength*/, 332u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_ID*/
  {3u/*BitLength*/, 341u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 491u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_type*/
  {4u/*BitLength*/, 328u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Confidence*/
  {7u/*BitLength*/, 350u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 492u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_width*/
  {12u/*BitLength*/, 364u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 492u/* BufferStartIdx */, 494u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_X*/
  {12u/*BitLength*/, 368u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 493u/* BufferStartIdx */, 495u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_Y*/
  {4u/*BitLength*/, 396u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_ID*/
  {3u/*BitLength*/, 405u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 499u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_type*/
  {4u/*BitLength*/, 392u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Confidence*/
  {7u/*BitLength*/, 414u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 500u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_width*/
  {12u/*BitLength*/, 428u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 500u/* BufferStartIdx */, 502u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_X*/
  {12u/*BitLength*/, 432u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 501u/* BufferStartIdx */, 503u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 448u/* BufferStartIdx */, 512u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD2_0x203*/
  {4u/*BitLength*/, 12u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 515u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 516u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 516u/* BufferStartIdx */, 518u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 517u/* BufferStartIdx */, 519u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_Y*/
  {2u/*BitLength*/, 112u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 526u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_WorkSts*/
  {16u/*BitLength*/, 80u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 523u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj_Timestamp*/
  {6u/*BitLength*/, 90u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 523u/* BufferStartIdx */, 524u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD1_distance*/
  {6u/*BitLength*/, 100u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 523u/* BufferStartIdx */, 525u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD2_distance*/
  {6u/*BitLength*/, 110u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 524u/* BufferStartIdx */, 526u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD3_distance*/
  {6u/*BitLength*/, 104u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 525u/* BufferStartIdx */, 526u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD4_distance*/
  {6u/*BitLength*/, 114u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 526u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD5_distance*/
  {6u/*BitLength*/, 138u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD6_distance*/
  {6u/*BitLength*/, 148u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD7_distance*/
  {6u/*BitLength*/, 158u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD8_distance*/
  {6u/*BitLength*/, 152u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 531u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD9_distance*/
  {6u/*BitLength*/, 162u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 533u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD10_distance*/
  {6u/*BitLength*/, 172u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 534u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD11_distance*/
  {6u/*BitLength*/, 182u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 533u/* BufferStartIdx */, 535u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD12_distance*/
  {6u/*BitLength*/, 176u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 534u/* BufferStartIdx */, 535u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD13_distance*/
  {6u/*BitLength*/, 202u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 537u/* BufferStartIdx */, 538u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD14_distance*/
  {6u/*BitLength*/, 212u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 537u/* BufferStartIdx */, 539u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD15_distance*/
  {6u/*BitLength*/, 222u/* BitPosition */, 37u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 538u/* BufferStartIdx */, 540u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD16_distance*/
  {6u/*BitLength*/, 216u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 539u/* BufferStartIdx */, 540u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD17_distance*/
  {6u/*BitLength*/, 226u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 540u/* BufferStartIdx */, 541u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD18_distance*/
  {1u/*BitLength*/, 335u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 553u/* BufferStartIdx */, 554u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Swt_Req*/
  {1u/*BitLength*/, 334u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 553u/* BufferStartIdx */, 554u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Act_Req*/
  {512u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 512u/* BufferStartIdx */, 576u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD3_0x243*/
  {4u/*BitLength*/, 32u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 580u/* BufferStartIdx */, 581u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SlotNum_VR*/
  {512u/*BitLength*/, 0u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 576u/* BufferStartIdx */, 640u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD4_0x1DA*/
  {512u/*BitLength*/, 504u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 640u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ExternalDevice*/
  {512u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 640u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD5_0x1DB*/
  {8u/*BitLength*/, 0u/* BitPosition */, 40u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 704u/* BufferStartIdx */, 705u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequestMessageId*/
  {56u/*BitLength*/, 56u/* BitPosition */, 40u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 7u/* BusAccBtyeLength */, 705u/* BufferStartIdx */, 712u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequstReseverData*/
  {3u/*BitLength*/, 18u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 722u/* BufferStartIdx */, 723u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_CurrTheme*/
  {9u/*BitLength*/, 23u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 721u/* BufferStartIdx */, 723u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdDisp*/
  {8u/*BitLength*/, 60u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 728u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VelSpdDisp_Mile*/
  {10u/*BitLength*/, 24u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 722u/* BufferStartIdx */, 724u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelMainTankR*/
  {10u/*BitLength*/, 46u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 724u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxTankR*/
  {4u/*BitLength*/, 42u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 725u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_LagueSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 720u/* BufferStartIdx */, 728u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP1_0x293*/
  {8u/*BitLength*/, 0u/* BitPosition */, 42u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 728u/* BufferStartIdx */, 729u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_IP2*/
  {2u/*BitLength*/, 50u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 734u/* BufferStartIdx */, 735u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_DrvSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 734u/* BufferStartIdx */, 735u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_PassSeatBeltWarnLmpFailSts*/
  {24u/*BitLength*/, 24u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 729u/* BufferStartIdx */, 732u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistance*/
  {1u/*BitLength*/, 46u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 733u/* BufferStartIdx */, 734u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceValid*/
  {8u/*BitLength*/, 32u/* BitPosition */, 42u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 732u/* BufferStartIdx */, 733u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlInfo*/
  {2u/*BitLength*/, 44u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 733u/* BufferStartIdx */, 734u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlLowLmpSts*/
  {2u/*BitLength*/, 42u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 733u/* BufferStartIdx */, 734u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_BattChrgLmpSts*/
  {2u/*BitLength*/, 40u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 733u/* BufferStartIdx */, 734u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EngOilPressLowLmpSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 734u/* BufferStartIdx */, 735u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ABMWarnLmpFailrSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 734u/* BufferStartIdx */, 735u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_Err*/
  {1u/*BitLength*/, 47u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 733u/* BufferStartIdx */, 734u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ACCErr*/
  {1u/*BitLength*/, 53u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 734u/* BufferStartIdx */, 735u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdUnit*/
  {1u/*BitLength*/, 63u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 735u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VINcompr*/
  {1u/*BitLength*/, 62u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 735u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_RSCAOFFLmpSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 735u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_IP2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 728u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP2_0x27F*/
  {12u/*BitLength*/, 20u/* BitPosition */, 43u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 737u/* BufferStartIdx */, 739u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_RemainDistance*/
  {1u/*BitLength*/, 19u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 738u/* BufferStartIdx */, 739u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelConsUnit*/
  {1u/*BitLength*/, 18u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 738u/* BufferStartIdx */, 739u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EBDFailSts*/
  {12u/*BitLength*/, 36u/* BitPosition */, 43u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 739u/* BufferStartIdx */, 741u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AvgFuelCons*/
  {14u/*BitLength*/, 54u/* BitPosition */, 43u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 740u/* BufferStartIdx */, 743u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelCons*/
  {128u/*BitLength*/, 0u/* BitPosition */, 43u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 16u/* BusAccBtyeLength */, 736u/* BufferStartIdx */, 752u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP3_0x34A*/
};

const ComEx_TxPduInfoType ComEx_TxPduInfo[ComEx_TxPduSize] = 
{
  {65535u/* SignalStartIdx */, 65535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 0/* CalloutStartIdx */, 1u/* CalloutNum */}, /*ComIPdu_userData*/
  {0u/* SignalStartIdx */, 39u/* SignalEndIdx */, 0u/* GroupStartIdx */, 4u/* GroupEndIdx */, 8u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DMS_FD1*/
  {39u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DVR_FD1*/
  {44u/* SignalStartIdx */, 73u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT1*/
  {73u/* SignalStartIdx */, 89u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT2*/
  {89u/* SignalStartIdx */, 103u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 152u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT3*/
  {103u/* SignalStartIdx */, 128u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 160u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT4*/
  {128u/* SignalStartIdx */, 146u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 168u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT6*/
  {146u/* SignalStartIdx */, 150u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT7*/
  {150u/* SignalStartIdx */, 163u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 184u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT10*/
  {163u/* SignalStartIdx */, 165u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT12*/
  {165u/* SignalStartIdx */, 178u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT13*/
  {178u/* SignalStartIdx */, 198u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT15*/
  {198u/* SignalStartIdx */, 204u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 216u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT16*/
  {204u/* SignalStartIdx */, 220u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 224u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT17*/
  {220u/* SignalStartIdx */, 234u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 232u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT19*/
  {234u/* SignalStartIdx */, 244u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT20*/
  {244u/* SignalStartIdx */, 257u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 248u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT21*/
  {257u/* SignalStartIdx */, 277u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT22*/
  {277u/* SignalStartIdx */, 295u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT23*/
  {295u/* SignalStartIdx */, 305u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT25*/
  {305u/* SignalStartIdx */, 308u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 280u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT26*/
  {308u/* SignalStartIdx */, 323u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 288u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT30*/
  {323u/* SignalStartIdx */, 325u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 296u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT31*/
  {325u/* SignalStartIdx */, 346u/* SignalEndIdx */, 4u/* GroupStartIdx */, 5u/* GroupEndIdx */, 304u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT32*/
  {346u/* SignalStartIdx */, 375u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 312u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT33*/
  {375u/* SignalStartIdx */, 386u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 320u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT34*/
  {386u/* SignalStartIdx */, 401u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 328u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT35*/
  {401u/* SignalStartIdx */, 417u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 336u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT38*/
  {417u/* SignalStartIdx */, 430u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 344u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT39*/
  {430u/* SignalStartIdx */, 432u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 352u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT42*/
  {432u/* SignalStartIdx */, 435u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT43*/
  {435u/* SignalStartIdx */, 440u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT45*/
  {440u/* SignalStartIdx */, 445u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT46*/
  {445u/* SignalStartIdx */, 448u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT48*/
  {448u/* SignalStartIdx */, 535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 56u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD1*/
  {535u/* SignalStartIdx */, 578u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD2*/
  {578u/* SignalStartIdx */, 607u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 512u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD3*/
  {607u/* SignalStartIdx */, 609u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 576u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD4*/
  {609u/* SignalStartIdx */, 611u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 640u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD5*/
  {611u/* SignalStartIdx */, 613u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_Sync_Req*/
  {613u/* SignalStartIdx */, 620u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 720u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP1*/
  {620u/* SignalStartIdx */, 637u/* SignalEndIdx */, 5u/* GroupStartIdx */, 6u/* GroupEndIdx */, 728u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP2*/
  {637u/* SignalStartIdx */, 643u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 736u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP3*/
};

const uint8 ComEx_TxInitValueBuffer[ComEx_TxInitValueBufferSize] =
{
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x3fu,
  0xf0u,
  0x0u,
  0x1fu,
  0xfeu,
  0x0u,
  0x0u,
  0x0u,
  0xfeu,
  0xfeu,
  0xfcu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xffu,
  0xffu,
  0xffu,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xffu,
  0xffu,
  0xffu,
  0x80u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xffu,
  0xffu,
  0xfeu,
  0xe0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xffu,
  0xc8u,
  0xc8u,
  0xfeu,
  0xa7u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x22u,
  0x50u,
  0x0u,
  0x0u,
  0x10u,
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x52u,
  0x50u,
  0x52u,
  0x10u,
  0x50u,
  0x52u,
  0x0u,
  0x28u,
  0x28u,
  0x28u,
  0x28u,
  0x0u,
  0x8u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x20u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x40u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x3cu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x1u,
  0x0u,
  0x0u,
  0xf0u,
  0x0u,
  0x40u,
  0x0u,
  0x5u,
  0x51u,
  0x0u,
  0x2u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x80u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x40u,
  0x33u,
  0xa5u,
  0x0u,
  0x10u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x80u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xc0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x40u,
  0x10u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x28u,
  0x0u,
  0x0u,
  0x0u,
  0x5u,
  0x44u,
  0x2fu,
  0xf0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xe7u,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0xa8u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xf8u,
  0xfcu,
  0xfcu,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x81u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x50u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x41u,
  0x5u,
  0xc0u,
  0x80u,
  0x0u,
  0x2u,
  0x0u,
  0x1eu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x1u,
  0x27u,
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x10u,
  0x1fu,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0x1u,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x10u,
  0xau,
  0x2u,
  0xbcu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xffu,
  0xffu,
  0xc0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
};

const ComEx_TxGroupInfoType ComEx_TxGroupInfo[ComEx_TxGroupSize] = 
{
  {1u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 0u/* E2eIdx */}, /*DMS2_DMS_FD1*/
  {1u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 1u/* E2eIdx */}, /*DMS3_DMS_FD1*/
  {1u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 2u/* E2eIdx */}, /*DMS5_DMS_FD1*/
  {1u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 3u/* E2eIdx */}, /*DMS6_DMS_FD1*/
  {24u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* E2eIdx */}, /*HUT32*/
  {42u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* E2eIdx */}, /*IP2*/
};

const ComEx_TxE2eInfoType ComEx_TxE2eInfo[ComEx_TxE2eSize] =
{
  {E2EPW_WriteInit_DMS2_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS2_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS2_DMS_FD1*/
  {E2EPW_WriteInit_DMS3_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS3_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS3_DMS_FD1*/
  {E2EPW_WriteInit_DMS5_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS5_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS5_DMS_FD1*/
  {E2EPW_WriteInit_DMS6_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS6_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS6_DMS_FD1*/
  {E2EPW_WriteInit_HUT32_E2E/* InitFunPtr */, E2EPW_Write_HUT32_E2E/* WriteFunPtr */}, /*HUT32*/
  {E2EPW_WriteInit_IP2_E2E/* InitFunPtr */, E2EPW_Write_IP2_E2E/* WriteFunPtr */}, /*IP2*/
};

const uint8 ComEx_TxPduCalloutIdx[2] =
{
    3u, 4u
};

const PduCalloutFunPtrType ComEx_PduCalloutFunPtrTable[5u] = 
{
	{SECOC_PDU_Message_Received_Callout},
	{SecOc_GW_Sync_Req_Callout},
	{ComEx_ReceivePduSignalProcessing},
	{ComIPdu_userData_Callback_tx},
	{ComEx_TransmitPduSignalProcessing},
};
