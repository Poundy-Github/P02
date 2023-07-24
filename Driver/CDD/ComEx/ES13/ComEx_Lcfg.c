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
 * @file:      ComEx_Lcfg.c
 * @author:    Nobo
 * @date:      2021-2-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-2-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Std_Types.h"
#include "ComEx_Cfg.h"
#include "ComEx_Type.h"

extern void CNA_SignalCallBack(uint16 signalId);
const ComEx_RxSigInfoType ComEx_RxSigInfo[ComEx_RxSignalSize] = 
{
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 0u/* AppAccBytePosition */}, /*SecRowLSBR*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1u/* AppAccBytePosition */}, /*AirbFailLmpCmd*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2u/* AppAccBytePosition */}, /*SecRowMidSBR*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3u/* AppAccBytePosition */}, /*DrvSBR*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4u/* AppAccBytePosition */}, /*SecRowRSBR*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 5u/* AppAccBytePosition */}, /*PassSBR*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 6u/* AppAccBytePosition */}, /*PassSBR_Visual*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 7u/* AppAccBytePosition */}, /*DrvSBR_Visual*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 8u/* AppAccBytePosition */}, /*SecRowLSBR_Visual*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 9u/* AppAccBytePosition */}, /*SecRowMidSBR_Visual*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 10u/* AppAccBytePosition */}, /*SecRowRSBR_Visual*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 11u/* AppAccBytePosition */}, /*CrashOutputSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 12u/* AppAccBytePosition */}, /*CheckSum_ABM1*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 13u/* AppAccBytePosition */}, /*RollingCounter_ABM1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 14u/* AppAccBytePosition */}, /*ABM1_0x351*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 3u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 22u/* AppAccBytePosition */}, /*VehYawRate*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 24u/* AppAccBytePosition */}, /*VehDynYawRateVld*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 4u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 25u/* AppAccBytePosition */}, /*VehLgtAccel*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 4u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 27u/* AppAccBytePosition */}, /*VehLatAccel*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 29u/* AppAccBytePosition */}, /*VehLgtAccelVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 30u/* AppAccBytePosition */}, /*VehLatAccelVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 31u/* AppAccBytePosition */}, /*ABM2_0x245*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 39u/* AppAccBytePosition */}, /*FLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 40u/* AppAccBytePosition */}, /*FLWheelSpd*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 42u/* AppAccBytePosition */}, /*FRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 43u/* AppAccBytePosition */}, /*FRWheelSpd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 45u/* AppAccBytePosition */}, /*ABS1_0x231*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 53u/* AppAccBytePosition */}, /*RRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 54u/* AppAccBytePosition */}, /*RRWheelSpd*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 56u/* AppAccBytePosition */}, /*RLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 57u/* AppAccBytePosition */}, /*RLWheelSpd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 59u/* AppAccBytePosition */}, /*ABS2_0x246*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 67u/* AppAccBytePosition */}, /*InCarTemp*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 68u/* AppAccBytePosition */}, /*ACDrvAirDistriMod*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 69u/* AppAccBytePosition */}, /*ACEEMSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 70u/* AppAccBytePosition */}, /*ACSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 71u/* AppAccBytePosition */}, /*ACDrvTempSteplessSetEnaSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 72u/* AppAccBytePosition */}, /*ACOperMod*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 73u/* AppAccBytePosition */}, /*ACCbnClnEnasts*/
  {4u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 74u/* AppAccBytePosition */}, /*ACCbnClnOffCode*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 75u/* AppAccBytePosition */}, /*ACAQSEnaSts*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 76u/* AppAccBytePosition */}, /*ACAIUEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 77u/* AppAccBytePosition */}, /*AC1_0x29D*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 85u/* AppAccBytePosition */}, /*ACFrntDefrstSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 86u/* AppAccBytePosition */}, /*ACRearWinHeatSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 87u/* AppAccBytePosition */}, /*ACHMIDispCmd*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 88u/* AppAccBytePosition */}, /*ACFrntBlwrSpd*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 89u/* AppAccBytePosition */}, /*ACOpenSts*/
  {6u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 90u/* AppAccBytePosition */}, /*ACDrvTemp_ATC*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 91u/* AppAccBytePosition */}, /*ACAmbTemp*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 92u/* AppAccBytePosition */}, /*ACAirInletSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 93u/* AppAccBytePosition */}, /*ACAutoModEnaSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 94u/* AppAccBytePosition */}, /*ACCmprEnaSts*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 95u/* AppAccBytePosition */}, /*ACAutoDefrstModEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 96u/* AppAccBytePosition */}, /*AC2_0x385*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 104u/* AppAccBytePosition */}, /*L_FGAChan1TimeoutAlarm*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 105u/* AppAccBytePosition */}, /*L_FGAChan2TimeoutAlarm*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 106u/* AppAccBytePosition */}, /*L_FGAChan3TimeoutAlarm*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 107u/* AppAccBytePosition */}, /*ACMaxEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 108u/* AppAccBytePosition */}, /*AC4_0x2CC*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 116u/* AppAccBytePosition */}, /*L_EAHEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 117u/* AppAccBytePosition */}, /*AC5_0x306*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 125u/* AppAccBytePosition */}, /*L_FGAEnaSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 126u/* AppAccBytePosition */}, /*L_FGALvlResp*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 127u/* AppAccBytePosition */}, /*L_FGAChanTypSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 128u/* AppAccBytePosition */}, /*AC6_0x2F8*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 136u/* AppAccBytePosition */}, /*FG_Chan1Typ*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 137u/* AppAccBytePosition */}, /*FG_Chan2Typ*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 138u/* AppAccBytePosition */}, /*FG_Chan3Typ*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 139u/* AppAccBytePosition */}, /*L_FGAChan1IllegalitySts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 140u/* AppAccBytePosition */}, /*L_FGAChan2IllegalitySts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 141u/* AppAccBytePosition */}, /*L_FGAChan3IllegalitySts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 142u/* AppAccBytePosition */}, /*AC7_0x2D0*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 150u/* AppAccBytePosition */}, /*ACC_TgtObjBarDisp*/
  {3u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 151u/* AppAccBytePosition */}, /*ACC_TimeGapSet*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 152u/* AppAccBytePosition */}, /*ISL_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 153u/* AppAccBytePosition */}, /*ICA_HandsOffResp*/
  {3u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 154u/* AppAccBytePosition */}, /*Request_driveoff*/
  {1u/*BitLength*/, 319u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 155u/* AppAccBytePosition */}, /*IntelligentCurveAct*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 156u/* AppAccBytePosition */}, /*HWA_SnvtySet_Resp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 157u/* AppAccBytePosition */}, /*HWA_Resp*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 158u/* AppAccBytePosition */}, /*ALC_Resp*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 159u/* AppAccBytePosition */}, /*Checksum_ACC8*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 160u/* AppAccBytePosition */}, /*HWA_warning*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 161u/* AppAccBytePosition */}, /*HWA_ModDisp*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 162u/* AppAccBytePosition */}, /*HWA_InterSysInfoDisp*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 163u/* AppAccBytePosition */}, /*ADAS_DriverInloop_Monitor*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 164u/* AppAccBytePosition */}, /*RollingCounter_ACC8*/
  {3u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 165u/* AppAccBytePosition */}, /*HWA_LaneChangeReq*/
  {2u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 166u/* AppAccBytePosition */}, /*HWA_LaneChange*/
  {2u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 167u/* AppAccBytePosition */}, /*ALC_InterSysInfoDisp*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 168u/* AppAccBytePosition */}, /*ACC_ObjDetecte*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 169u/* AppAccBytePosition */}, /*ACC_TakeOverReq*/
  {5u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 170u/* AppAccBytePosition */}, /*ACC_InterSysInfoDisp*/
  {5u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 171u/* AppAccBytePosition */}, /*ACC_ModDisp*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 172u/* AppAccBytePosition */}, /*ACC_FctSts*/
  {8u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 173u/* AppAccBytePosition */}, /*ACC_SpdSetValue*/
  {3u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 174u/* AppAccBytePosition */}, /*TJA_ACC_SelSts*/
  {3u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 175u/* AppAccBytePosition */}, /*TJA_ICA_ModDisp*/
  {3u/*BitLength*/, 161u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 176u/* AppAccBytePosition */}, /*TJA_ICA_InterSysInfoDisp*/
  {2u/*BitLength*/, 171u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 177u/* AppAccBytePosition */}, /*ISL_InterSysInfoDisp*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 178u/* AppAccBytePosition */}, /*ACC_PotentialTgtDy*/
  {9u/*BitLength*/, 287u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 179u/* AppAccBytePosition */}, /*ACC_PotentialTgtDx*/
  {2u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 181u/* AppAccBytePosition */}, /*ACC_RlvTgtDetn*/
  {2u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 182u/* AppAccBytePosition */}, /*ACC_EgoStatus*/
  {8u/*BitLength*/, 288u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 183u/* AppAccBytePosition */}, /*ACC_RlvTgtDy*/
  {9u/*BitLength*/, 311u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 184u/* AppAccBytePosition */}, /*ACC_RlvTgtDx*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 186u/* AppAccBytePosition */}, /*ACC_PotentialTgtDetn*/
  {3u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 187u/* AppAccBytePosition */}, /*ACC_PotentialTgtTyp*/
  {3u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 188u/* AppAccBytePosition */}, /*ACC_RlvTgtTyp*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 189u/* AppAccBytePosition */}, /*ACC_LeTgtDy*/
  {9u/*BitLength*/, 351u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 190u/* AppAccBytePosition */}, /*ACC_LeTgtDx*/
  {3u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 192u/* AppAccBytePosition */}, /*ACC_LeTgtTyp*/
  {2u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 193u/* AppAccBytePosition */}, /*ACC_LeTargrtDection*/
  {2u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 194u/* AppAccBytePosition */}, /*ACC_RiTargrtDetn*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 195u/* AppAccBytePosition */}, /*ACC_RiTgtDy*/
  {9u/*BitLength*/, 375u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 196u/* AppAccBytePosition */}, /*ACC_RiTgtDx*/
  {3u/*BitLength*/, 372u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 198u/* AppAccBytePosition */}, /*ACC_RiTgtTyp*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 199u/* AppAccBytePosition */}, /*CruCha_ModDisp*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 200u/* AppAccBytePosition */}, /*CruChar_InterSysInfoDisp*/
  {7u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 201u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dy*/
  {9u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 202u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dx*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 204u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Typ*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 205u/* AppAccBytePosition */}, /*ACC_LeTargrt_02_Detn*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 206u/* AppAccBytePosition */}, /*ACC_RiTargrt_02_Detn*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 207u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dy*/
  {9u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 208u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dx*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 210u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Typ*/
  {1u/*BitLength*/, 399u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 211u/* AppAccBytePosition */}, /*ACC_RlvTgtfusion*/
  {6u/*BitLength*/, 393u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 212u/* AppAccBytePosition */}, /*ACC_RlvTgtHeading*/
  {1u/*BitLength*/, 392u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 213u/* AppAccBytePosition */}, /*ACC_LeTgtfusion*/
  {6u/*BitLength*/, 402u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 214u/* AppAccBytePosition */}, /*ACC_LeTgtHeading*/
  {1u/*BitLength*/, 401u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 215u/* AppAccBytePosition */}, /*ACC_RiTgtfusion*/
  {6u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 216u/* AppAccBytePosition */}, /*ACC_RiTgtHeading*/
  {1u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 217u/* AppAccBytePosition */}, /*ACC_PotentialTgtfusion*/
  {6u/*BitLength*/, 420u/* BitPosition */, 2u/* ByteLength */, 52u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 218u/* AppAccBytePosition */}, /*ACC_PotentialTgtHeading*/
  {6u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 219u/* AppAccBytePosition */}, /*TargetCutinPro*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 220u/* AppAccBytePosition */}, /*TargetCutoutPro*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 221u/* AppAccBytePosition */}, /*ACC_LeTgtObjBarDisp*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 222u/* AppAccBytePosition */}, /*ACC_RiTgtObjBarDisp*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 223u/* AppAccBytePosition */}, /*Checksum_ACC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 224u/* AppAccBytePosition */}, /*Checksum_ACC4*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 225u/* AppAccBytePosition */}, /*Checksum_ACC6*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 226u/* AppAccBytePosition */}, /*Checksum_ACC7*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 227u/* AppAccBytePosition */}, /*RollingCounter_ACC3*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 228u/* AppAccBytePosition */}, /*RollingCounter_ACC4*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 229u/* AppAccBytePosition */}, /*RollingCounter_ACC6*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 230u/* AppAccBytePosition */}, /*RollingCounter_ACC7*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 231u/* AppAccBytePosition */}, /*Longctrl_VehHldReq_DVR*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 232u/* AppAccBytePosition */}, /*Longctrl_DrvOFF_Req_DVR*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 233u/* AppAccBytePosition */}, /*Longctrl_ModSts_DVR*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 234u/* AppAccBytePosition */}, /*Longctrl_Decel_Req_DVR*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 235u/* AppAccBytePosition */}, /*Longctrl_DecelToStopReq_DVR*/
  {2u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 236u/* AppAccBytePosition */}, /*Longctrl_ParkShiftReq_DVR*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 237u/* AppAccBytePosition */}, /*Longctrl_Decel_ReqValue_DVR*/
  {2u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 238u/* AppAccBytePosition */}, /*Longctrl_HazActv*/
  {1u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 239u/* AppAccBytePosition */}, /*ACCSts*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 240u/* AppAccBytePosition */}, /*ACC_FD2_0x2AB*/
  {6u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 296u/* AppAccBytePosition */}, /*FCWAEB_JATTC*/
  {6u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 297u/* AppAccBytePosition */}, /*FCWAEB_longTTC*/
  {6u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 298u/* AppAccBytePosition */}, /*FCWAEB_crossingTTC*/
  {4u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 299u/* AppAccBytePosition */}, /*NOH_Sts*/
  {1u/*BitLength*/, 368u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 300u/* AppAccBytePosition */}, /*NOH_Swt_Resp*/
  {1u/*BitLength*/, 369u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 301u/* AppAccBytePosition */}, /*NOH_Act_Resp*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 302u/* AppAccBytePosition */}, /*NOH_SysInfoDisplay*/
  {12u/*BitLength*/, 356u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 303u/* AppAccBytePosition */}, /*NOH_DistToExit*/
  {6u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 305u/* AppAccBytePosition */}, /*JAPedObjExist*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 306u/* AppAccBytePosition */}, /*AEBJAObjID*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 307u/* AppAccBytePosition */}, /*AEBJAObjExist*/
  {8u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 308u/* AppAccBytePosition */}, /*JAPedObjID*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 309u/* AppAccBytePosition */}, /*AEBJAObjVideoCfmd*/
  {12u/*BitLength*/, 100u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 310u/* AppAccBytePosition */}, /*AEBJAObjVx*/
  {12u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 312u/* AppAccBytePosition */}, /*AEBJAObjDx*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 314u/* AppAccBytePosition */}, /*JAPedObjVideoCfmd*/
  {3u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 315u/* AppAccBytePosition */}, /*AEBJAObjState*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 316u/* AppAccBytePosition */}, /*AEBJAObjCntAlive*/
  {11u/*BitLength*/, 153u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 318u/* AppAccBytePosition */}, /*AEBJAObjDy*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 320u/* AppAccBytePosition */}, /*JAPedObjState*/
  {5u/*BitLength*/, 164u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 321u/* AppAccBytePosition */}, /*AEBJAObjObstcl*/
  {10u/*BitLength*/, 170u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 322u/* AppAccBytePosition */}, /*AEBJAObjVy*/
  {10u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 324u/* AppAccBytePosition */}, /*AEBJAObjAx*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 326u/* AppAccBytePosition */}, /*AEBJAObjAy*/
  {5u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 328u/* AppAccBytePosition */}, /*JAPedObjObstcl*/
  {11u/*BitLength*/, 229u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 329u/* AppAccBytePosition */}, /*JAPedObjDy*/
  {12u/*BitLength*/, 233u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 331u/* AppAccBytePosition */}, /*JAPedObjDx*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 333u/* AppAccBytePosition */}, /*JAPedObjVx*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 335u/* AppAccBytePosition */}, /*JAPedObjVy*/
  {10u/*BitLength*/, 308u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 337u/* AppAccBytePosition */}, /*JAPedObjAy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 339u/* AppAccBytePosition */}, /*JAPedObjCntAlive*/
  {10u/*BitLength*/, 342u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 341u/* AppAccBytePosition */}, /*JAPedObjAx*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 343u/* AppAccBytePosition */}, /*ACC_FD3_0x2B4*/
  {8u/*BitLength*/, 504u/* BitPosition */, 1u/* ByteLength */, 63u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 407u/* AppAccBytePosition */}, /*ACC_DataRecReq*/
  {2u/*BitLength*/, 483u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 408u/* AppAccBytePosition */}, /*ACC_SOSReq*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 409u/* AppAccBytePosition */}, /*AEBObjID*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 410u/* AppAccBytePosition */}, /*AEBObjExist*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 411u/* AppAccBytePosition */}, /*AEBObjVideoCfmd*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 412u/* AppAccBytePosition */}, /*AEBObjVx*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 414u/* AppAccBytePosition */}, /*AEBObjDx*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 416u/* AppAccBytePosition */}, /*AEBObjCntAlive*/
  {11u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 418u/* AppAccBytePosition */}, /*AEBObjDy*/
  {3u/*BitLength*/, 69u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 420u/* AppAccBytePosition */}, /*AEBObjState*/
  {5u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 421u/* AppAccBytePosition */}, /*AEBObjObstcl*/
  {10u/*BitLength*/, 86u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 422u/* AppAccBytePosition */}, /*AEBObjVy*/
  {6u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 424u/* AppAccBytePosition */}, /*CyclistObjExist*/
  {10u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 425u/* AppAccBytePosition */}, /*AEBObjAx*/
  {10u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 427u/* AppAccBytePosition */}, /*AEBObjAy*/
  {12u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 429u/* AppAccBytePosition */}, /*CyclistObjDx*/
  {8u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 431u/* AppAccBytePosition */}, /*CyclistObjID*/
  {5u/*BitLength*/, 131u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 432u/* AppAccBytePosition */}, /*CyclistObjObstcl*/
  {11u/*BitLength*/, 136u/* BitPosition */, 2u/* ByteLength */, 17u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 433u/* AppAccBytePosition */}, /*CyclistObjDy*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 435u/* AppAccBytePosition */}, /*CyclistObjVx*/
  {12u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 437u/* AppAccBytePosition */}, /*CyclistObjCntAlive*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 439u/* AppAccBytePosition */}, /*CyclistObjVy*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 441u/* AppAccBytePosition */}, /*CyclistObjState*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 442u/* AppAccBytePosition */}, /*CyclistObjVideoCfmd*/
  {10u/*BitLength*/, 184u/* BitPosition */, 2u/* ByteLength */, 23u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 443u/* AppAccBytePosition */}, /*CyclistObjAx*/
  {10u/*BitLength*/, 206u/* BitPosition */, 2u/* ByteLength */, 25u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 445u/* AppAccBytePosition */}, /*CyclistObjAy*/
  {6u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 447u/* AppAccBytePosition */}, /*PedObjExist*/
  {8u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 448u/* AppAccBytePosition */}, /*PedObjID*/
  {5u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 449u/* AppAccBytePosition */}, /*PedObjObstcl*/
  {11u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 450u/* AppAccBytePosition */}, /*PedObjDy*/
  {12u/*BitLength*/, 244u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 452u/* AppAccBytePosition */}, /*PedObjDx*/
  {12u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 454u/* AppAccBytePosition */}, /*PedObjVx*/
  {10u/*BitLength*/, 270u/* BitPosition */, 2u/* ByteLength */, 33u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 456u/* AppAccBytePosition */}, /*PedObjVy*/
  {1u/*BitLength*/, 269u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 458u/* AppAccBytePosition */}, /*PedObjVideoCfmd*/
  {12u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 459u/* AppAccBytePosition */}, /*ACCTgtObjDx*/
  {10u/*BitLength*/, 294u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 461u/* AppAccBytePosition */}, /*PedObjAy*/
  {12u/*BitLength*/, 298u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 463u/* AppAccBytePosition */}, /*PedObjCntAlive*/
  {10u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 465u/* AppAccBytePosition */}, /*PedObjAx*/
  {8u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 467u/* AppAccBytePosition */}, /*ACCTgtObjID*/
  {5u/*BitLength*/, 323u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 468u/* AppAccBytePosition */}, /*ACCTgtObjObstcl*/
  {11u/*BitLength*/, 328u/* BitPosition */, 2u/* ByteLength */, 41u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 469u/* AppAccBytePosition */}, /*ACCTgtObjDy*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 471u/* AppAccBytePosition */}, /*ACCTgtObjExist*/
  {10u/*BitLength*/, 344u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 472u/* AppAccBytePosition */}, /*ACCTgtObjVy*/
  {12u/*BitLength*/, 364u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 474u/* AppAccBytePosition */}, /*ACCTgtObjVx*/
  {10u/*BitLength*/, 370u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 476u/* AppAccBytePosition */}, /*ACCTgtObjAx*/
  {10u/*BitLength*/, 376u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 478u/* AppAccBytePosition */}, /*ACCTgtObjAy*/
  {3u/*BitLength*/, 389u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 480u/* AppAccBytePosition */}, /*ACCTgtObjState*/
  {1u/*BitLength*/, 388u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 481u/* AppAccBytePosition */}, /*ACCTgtObjVideoCfmd*/
  {12u/*BitLength*/, 392u/* BitPosition */, 2u/* ByteLength */, 49u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 482u/* AppAccBytePosition */}, /*ACCTgtObjCntAlive*/
  {12u/*BitLength*/, 412u/* BitPosition */, 2u/* ByteLength */, 51u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 484u/* AppAccBytePosition */}, /*RadarHorMisalign*/
  {2u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 486u/* AppAccBytePosition */}, /*HandsoffDetd*/
  {2u/*BitLength*/, 408u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 487u/* AppAccBytePosition */}, /*DrvgOnHiWay*/
  {10u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 488u/* AppAccBytePosition */}, /*RoadCrvt*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 490u/* AppAccBytePosition */}, /*SpdLimitDst*/
  {10u/*BitLength*/, 446u/* BitPosition */, 2u/* ByteLength */, 55u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 491u/* AppAccBytePosition */}, /*RoadCrvtFar*/
  {6u/*BitLength*/, 440u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 493u/* AppAccBytePosition */}, /*RampDst*/
  {8u/*BitLength*/, 448u/* BitPosition */, 1u/* ByteLength */, 56u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 494u/* AppAccBytePosition */}, /*SpdLimit*/
  {6u/*BitLength*/, 458u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 495u/* AppAccBytePosition */}, /*CurveDst*/
  {2u/*BitLength*/, 456u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 496u/* AppAccBytePosition */}, /*NavSpdLimUnit*/
  {6u/*BitLength*/, 466u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 497u/* AppAccBytePosition */}, /*TunnelDst*/
  {2u/*BitLength*/, 464u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 498u/* AppAccBytePosition */}, /*DrvgOnRiLane*/
  {6u/*BitLength*/, 474u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 499u/* AppAccBytePosition */}, /*BrdgDst*/
  {1u/*BitLength*/, 473u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 500u/* AppAccBytePosition */}, /*RadarDrvrAttentive*/
  {3u/*BitLength*/, 480u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 501u/* AppAccBytePosition */}, /*PedObjState*/
  {1u/*BitLength*/, 495u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 502u/* AppAccBytePosition */}, /*MapDataValid*/
  {3u/*BitLength*/, 492u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 503u/* AppAccBytePosition */}, /*DrvrSts*/
  {5u/*BitLength*/, 503u/* BitPosition */, 2u/* ByteLength */, 62u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 504u/* AppAccBytePosition */}, /*AEBObjOverlap*/
  {5u/*BitLength*/, 498u/* BitPosition */, 1u/* ByteLength */, 62u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 505u/* AppAccBytePosition */}, /*AEBObjDrvby*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 506u/* AppAccBytePosition */}, /*ACC_FD4_0x2B8*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 570u/* AppAccBytePosition */}, /*AEB_ObjSty*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 571u/* AppAccBytePosition */}, /*AEB_ABA_Level*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 572u/* AppAccBytePosition */}, /*AEB_ABA_Req*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 573u/* AppAccBytePosition */}, /*EBA_TgtDecel_Req*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 574u/* AppAccBytePosition */}, /*AEB_VehHldReq*/
  {1u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 575u/* AppAccBytePosition */}, /*AEB_TgtDecel_Req*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 576u/* AppAccBytePosition */}, /*AEB_TgtDecel_ReqValue*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 578u/* AppAccBytePosition */}, /*AEB_AWB_Req*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 579u/* AppAccBytePosition */}, /*AEB_AWB_Level*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 580u/* AppAccBytePosition */}, /*AEB_ABP_Req*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 581u/* AppAccBytePosition */}, /*AEB_BrkReqFunc*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 582u/* AppAccBytePosition */}, /*AEB_FD1_0x18B*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 646u/* AppAccBytePosition */}, /*FCW_Snvty*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 647u/* AppAccBytePosition */}, /*AEB_PedResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 648u/* AppAccBytePosition */}, /*AEB_VehResp*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 649u/* AppAccBytePosition */}, /*AEB_JA_Resp*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 650u/* AppAccBytePosition */}, /*AEB_VehTrig*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 651u/* AppAccBytePosition */}, /*AEB_PedTrig*/
  {2u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 652u/* AppAccBytePosition */}, /*FCW_AEB_VehFctSts*/
  {2u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 653u/* AppAccBytePosition */}, /*FCW_AEB_PedFctSts*/
  {2u/*BitLength*/, 146u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 654u/* AppAccBytePosition */}, /*AEB_JAFuncSts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 655u/* AppAccBytePosition */}, /*AEB_JA_Warn*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 656u/* AppAccBytePosition */}, /*AEB_JABrkTrig*/
  {2u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 657u/* AppAccBytePosition */}, /*FCW_Warn*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 658u/* AppAccBytePosition */}, /*Checksum_AEB2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 659u/* AppAccBytePosition */}, /*Checksum_AEB3*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 660u/* AppAccBytePosition */}, /*RollingCounter_AEB2*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 661u/* AppAccBytePosition */}, /*RollingCounter_AEB3*/
  {8u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 662u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dy*/
  {9u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 663u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dx*/
  {2u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 665u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Detn*/
  {3u/*BitLength*/, 218u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 666u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Typ*/
  {1u/*BitLength*/, 217u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 667u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_fusion*/
  {6u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 668u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Heading*/
  {8u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 669u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dy*/
  {9u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 670u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dx*/
  {2u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 672u/* AppAccBytePosition */}, /*ACC_LeTargrt_03_Detn*/
  {3u/*BitLength*/, 253u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 673u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Typ*/
  {1u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 674u/* AppAccBytePosition */}, /*ACC_LeTgt_03_fusion*/
  {6u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 675u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Heading*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 676u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dy*/
  {9u/*BitLength*/, 295u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 677u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dx*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 679u/* AppAccBytePosition */}, /*ACC_RiTargrt_03_Detn*/
  {3u/*BitLength*/, 292u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 680u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Typ*/
  {1u/*BitLength*/, 291u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 681u/* AppAccBytePosition */}, /*ACC_RiTgt_03_fusion*/
  {6u/*BitLength*/, 298u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 682u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Heading*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 683u/* AppAccBytePosition */}, /*AEB_FD2_0x227*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 739u/* AppAccBytePosition */}, /*ALCMSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 740u/* AppAccBytePosition */}, /*ALCM1_0x2DB*/
  {16u/*BitLength*/, 8u/* BitPosition */, 2u/* ByteLength */, 1u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 748u/* AppAccBytePosition */}, /*AMP_SWVersion*/
  {16u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 750u/* AppAccBytePosition */}, /*AMP_HWVersion*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 752u/* AppAccBytePosition */}, /*AMP_Chan1DTCInfo*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 753u/* AppAccBytePosition */}, /*AMP_Chan2DTCInfo*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 754u/* AppAccBytePosition */}, /*AMP_Chan3DTCInfo*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 755u/* AppAccBytePosition */}, /*AMP_Chan4DTCInfo*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 756u/* AppAccBytePosition */}, /*AMP_Chan5DTCInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 757u/* AppAccBytePosition */}, /*AMP_Chan6DTCInfo*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 758u/* AppAccBytePosition */}, /*AMP_Chan7DTCInfo*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 759u/* AppAccBytePosition */}, /*AMP_Chan8DTCInfo*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 760u/* AppAccBytePosition */}, /*AMP_TempValue*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 761u/* AppAccBytePosition */}, /*AMP_TempSts*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 762u/* AppAccBytePosition */}, /*AMP_VolValue*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 763u/* AppAccBytePosition */}, /*BestListegPosnResp*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 764u/* AppAccBytePosition */}, /*Clari_FiResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 765u/* AppAccBytePosition */}, /*AMP1_0x3E1*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 773u/* AppAccBytePosition */}, /*MediaCallSourceState*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 774u/* AppAccBytePosition */}, /*BeepSourceSts*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 775u/* AppAccBytePosition */}, /*BalanceSetState*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 776u/* AppAccBytePosition */}, /*VSCModeState*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 777u/* AppAccBytePosition */}, /*FadeSetState*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 778u/* AppAccBytePosition */}, /*DriveSideSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 779u/* AppAccBytePosition */}, /*BassSetState*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 780u/* AppAccBytePosition */}, /*MuteState*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 781u/* AppAccBytePosition */}, /*NaviSourceState*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 782u/* AppAccBytePosition */}, /*MidrangeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 783u/* AppAccBytePosition */}, /*T_BOX_ECallSts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 784u/* AppAccBytePosition */}, /*GetHUTInfoSts*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 785u/* AppAccBytePosition */}, /*TrebleSetState*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 786u/* AppAccBytePosition */}, /*QLISurroundSetSt*/
  {1u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 787u/* AppAccBytePosition */}, /*AVMStResp*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 788u/* AppAccBytePosition */}, /*NaviMediaVolLvlResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 789u/* AppAccBytePosition */}, /*AVMMediaVolLvlResp*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 790u/* AppAccBytePosition */}, /*FPASChStResp*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 791u/* AppAccBytePosition */}, /*RPASChStResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 792u/* AppAccBytePosition */}, /*AMP2_0x3E3*/
  {6u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 800u/* AppAccBytePosition */}, /*HFMVolSetSts*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 801u/* AppAccBytePosition */}, /*VR_TTSVolSetSts*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 802u/* AppAccBytePosition */}, /*NaviVolumeSetState*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 803u/* AppAccBytePosition */}, /*MainVolumeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 804u/* AppAccBytePosition */}, /*AMPPowerSts*/
  {6u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 805u/* AppAccBytePosition */}, /*IPVolSetSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 806u/* AppAccBytePosition */}, /*AMP3_0x3E5*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 814u/* AppAccBytePosition */}, /*Microphone_Cha1DTCInfo*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 815u/* AppAccBytePosition */}, /*Microphone_Cha2DTCInfo*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 816u/* AppAccBytePosition */}, /*Microphone_Cha3DTCInfo*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 817u/* AppAccBytePosition */}, /*Microphone_Cha4DTCInfo*/
  {1u/*BitLength*/, 58u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 818u/* AppAccBytePosition */}, /*ANCSwtStatus*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 819u/* AppAccBytePosition */}, /*AMP4_ANC1_0x2D2*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 827u/* AppAccBytePosition */}, /*IESS_SwitchModel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 828u/* AppAccBytePosition */}, /*AMP5_IESS1_0x3A1*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 836u/* AppAccBytePosition */}, /*HoodSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 837u/* AppAccBytePosition */}, /*LTurnLmpSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 838u/* AppAccBytePosition */}, /*RTurnLmpSts*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 839u/* AppAccBytePosition */}, /*LowBeamSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 840u/* AppAccBytePosition */}, /*HiBeamSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 841u/* AppAccBytePosition */}, /*PosLmpOutputSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 842u/* AppAccBytePosition */}, /*IPBackgroundLmpCmd*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 843u/* AppAccBytePosition */}, /*TrunkSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 844u/* AppAccBytePosition */}, /*DrvDoorSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 845u/* AppAccBytePosition */}, /*LRDoorSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 846u/* AppAccBytePosition */}, /*PassengerDoorSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 847u/* AppAccBytePosition */}, /*RRDoorSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 848u/* AppAccBytePosition */}, /*BrkPedalSts_BCM*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 849u/* AppAccBytePosition */}, /*BrkPedalFailSts*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 850u/* AppAccBytePosition */}, /*BackgroundLightLvl*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 851u/* AppAccBytePosition */}, /*RLSFailSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 852u/* AppAccBytePosition */}, /*PosnLightReq*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 853u/* AppAccBytePosition */}, /*RFogLmpSts*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 854u/* AppAccBytePosition */}, /*RFogLmpFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 855u/* AppAccBytePosition */}, /*BrkLmpFailSts*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 856u/* AppAccBytePosition */}, /*LicenPlateLmpFailSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 857u/* AppAccBytePosition */}, /*FPosnLmpFailSts*/
  {1u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 858u/* AppAccBytePosition */}, /*TrunkPosnLmpFailSts*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 859u/* AppAccBytePosition */}, /*RPosnLmpFailSts*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 860u/* AppAccBytePosition */}, /*HighPosnBrkLmpFailSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 861u/* AppAccBytePosition */}, /*BCM1_0x319*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 869u/* AppAccBytePosition */}, /*AntitheftSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 870u/* AppAccBytePosition */}, /*DrvDoorLockSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 871u/* AppAccBytePosition */}, /*DoorLockSts*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 872u/* AppAccBytePosition */}, /*HiLowBeamSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 873u/* AppAccBytePosition */}, /*HazardLmpSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 874u/* AppAccBytePosition */}, /*BCM3_0x345*/
  {3u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 882u/* AppAccBytePosition */}, /*WiprReq_F_PBOX*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 883u/* AppAccBytePosition */}, /*KL30BRelaySts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 884u/* AppAccBytePosition */}, /*RemoteModSts*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 885u/* AppAccBytePosition */}, /*WhistleSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 886u/* AppAccBytePosition */}, /*PASWorkCmd*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 887u/* AppAccBytePosition */}, /*RViewMirrorSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 888u/* AppAccBytePosition */}, /*BCM8_0x29F*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 896u/* AppAccBytePosition */}, /*RLWinLrnSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 897u/* AppAccBytePosition */}, /*RLWinHotProtSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 898u/* AppAccBytePosition */}, /*RRWinLrnSts*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 899u/* AppAccBytePosition */}, /*RRWinHotProtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 900u/* AppAccBytePosition */}, /*RLWinPosnSts*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 901u/* AppAccBytePosition */}, /*RRWinPosnSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 902u/* AppAccBytePosition */}, /*AVMSwFctResp_VR*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 903u/* AppAccBytePosition */}, /*RRAntiPinchSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 904u/* AppAccBytePosition */}, /*RLAntiPinchSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 905u/* AppAccBytePosition */}, /*PassAntiPinchSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 906u/* AppAccBytePosition */}, /*DrvAntiPinchSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 907u/* AppAccBytePosition */}, /*BCMRemDoorLockFb*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 908u/* AppAccBytePosition */}, /*BCM9_0x2E8*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 916u/* AppAccBytePosition */}, /*LChildLockProtSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 917u/* AppAccBytePosition */}, /*RChildLockProtSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 918u/* AppAccBytePosition */}, /*RFPosnLmpWorkCmd*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 919u/* AppAccBytePosition */}, /*LFPosnLmpWorkCmd*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 920u/* AppAccBytePosition */}, /*HiBeamWorkCmd*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 921u/* AppAccBytePosition */}, /*LowBeamWorkCmd*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 922u/* AppAccBytePosition */}, /*RTurnLmpWorkCmd*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 923u/* AppAccBytePosition */}, /*LTurnLampWorkCmd*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 924u/* AppAccBytePosition */}, /*RDayRunngLmpWorkCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 925u/* AppAccBytePosition */}, /*LDayRunngLmpWorkCmd*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 926u/* AppAccBytePosition */}, /*RFFogLmpWorkCmd*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 927u/* AppAccBytePosition */}, /*LFFogLmpWorkCmd*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 928u/* AppAccBytePosition */}, /*RRPosnLmpWorkCmd*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 929u/* AppAccBytePosition */}, /*LRPosnLmpWorkCmd*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 930u/* AppAccBytePosition */}, /*LicPlateLmpWorkCmd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 931u/* AppAccBytePosition */}, /*ReversLampWorkCmd*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 932u/* AppAccBytePosition */}, /*BrkLmpWorkCmd*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 933u/* AppAccBytePosition */}, /*RFogLmpWorkCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 934u/* AppAccBytePosition */}, /*BCM10_0x2E7*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 942u/* AppAccBytePosition */}, /*SrAntiPinch*/
  {7u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 943u/* AppAccBytePosition */}, /*SsPosn_VR_APP*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 944u/* AppAccBytePosition */}, /*SsAntiPinch*/
  {7u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 945u/* AppAccBytePosition */}, /*SrPosn_VR_APP*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 946u/* AppAccBytePosition */}, /*UVCAntiVirusFdbk*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 947u/* AppAccBytePosition */}, /*OMSWorkCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 948u/* AppAccBytePosition */}, /*BCM12_0x238*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 956u/* AppAccBytePosition */}, /*AutoLmpSwtSts_CEM*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 957u/* AppAccBytePosition */}, /*AutoLmpSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 958u/* AppAccBytePosition */}, /*BCM17_0x23E*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 966u/* AppAccBytePosition */}, /*FastChrgnLidSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 967u/* AppAccBytePosition */}, /*SlowChrgnLidSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 968u/* AppAccBytePosition */}, /*FastChrgnLidAlarm*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 969u/* AppAccBytePosition */}, /*SlowChrgnLidAlarm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 970u/* AppAccBytePosition */}, /*BCM19_0x30F*/
  {4u/*BitLength*/, 336u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 978u/* AppAccBytePosition */}, /*BMS_Sts*/
  {10u/*BitLength*/, 318u/* BitPosition */, 2u/* ByteLength */, 39u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 979u/* AppAccBytePosition */}, /*BMS_SOC*/
  {14u/*BitLength*/, 293u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 981u/* AppAccBytePosition */}, /*BMS_BattCurr*/
  {13u/*BitLength*/, 296u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 983u/* AppAccBytePosition */}, /*BMS_BattVolt*/
  {1u/*BitLength*/, 340u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 985u/* AppAccBytePosition */}, /*BMS_DCChrgNegRlySts*/
  {1u/*BitLength*/, 341u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 986u/* AppAccBytePosition */}, /*BMS_DCChrgPosRlySts*/
  {4u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 987u/* AppAccBytePosition */}, /*BMS_SysFaultLvl*/
  {1u/*BitLength*/, 368u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 988u/* AppAccBytePosition */}, /*BMS_PreRlySts*/
  {1u/*BitLength*/, 369u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 989u/* AppAccBytePosition */}, /*BMS_NegRlySts*/
  {1u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 990u/* AppAccBytePosition */}, /*BMS_PosRlySts*/
  {1u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 991u/* AppAccBytePosition */}, /*BMS_OpenPosRlyReq*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 992u/* AppAccBytePosition */}, /*BMS_FD1_0xF2*/
  {7u/*BitLength*/, 321u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1056u/* AppAccBytePosition */}, /*BMS_SOC_RM*/
  {1u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1057u/* AppAccBytePosition */}, /*BMS_DeltaTempRank_RM*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 21u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1058u/* AppAccBytePosition */}, /*BMS_IsolationRValue_RM*/
  {1u/*BitLength*/, 351u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1060u/* AppAccBytePosition */}, /*BMS_BattOverTempRank_RM*/
  {1u/*BitLength*/, 350u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1061u/* AppAccBytePosition */}, /*BMS_BattOverVoltRank_RM*/
  {1u/*BitLength*/, 349u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1062u/* AppAccBytePosition */}, /*BMS_BattUnderVoltRank_RM*/
  {1u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1063u/* AppAccBytePosition */}, /*BMS_BattSOCLowRank_RM*/
  {1u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1064u/* AppAccBytePosition */}, /*BMS_CellOverVoltRank_RM*/
  {1u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1065u/* AppAccBytePosition */}, /*BMS_CellUnderVoltRank_RM*/
  {1u/*BitLength*/, 345u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1066u/* AppAccBytePosition */}, /*BMS_CellDeltaVoltRank_RM*/
  {1u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1067u/* AppAccBytePosition */}, /*BMS_VCUIsolateErr_RM*/
  {7u/*BitLength*/, 353u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1068u/* AppAccBytePosition */}, /*BMS_NumCell_RM*/
  {6u/*BitLength*/, 362u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1069u/* AppAccBytePosition */}, /*BMS_NumModuleTempSnsr_RM*/
  {15u/*BitLength*/, 377u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1070u/* AppAccBytePosition */}, /*BMS_BattCurr_RM*/
  {1u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1072u/* AppAccBytePosition */}, /*BMS_BattNum_RM*/
  {16u/*BitLength*/, 96u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1073u/* AppAccBytePosition */}, /*BMS_ChrgTime*/
  {1u/*BitLength*/, 311u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1075u/* AppAccBytePosition */}, /*BMS_DCChrgConnect*/
  {2u/*BitLength*/, 309u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1076u/* AppAccBytePosition */}, /*BMS_ChrgSts*/
  {2u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1077u/* AppAccBytePosition */}, /*BMS_BattHeatRunaway*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1078u/* AppAccBytePosition */}, /*BMS_RemtPreHeatSts*/
  {10u/*BitLength*/, 118u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1079u/* AppAccBytePosition */}, /*BMS_SOE*/
  {1u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1081u/* AppAccBytePosition */}, /*BMS_SafetyCnSts*/
  {1u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1082u/* AppAccBytePosition */}, /*BMS_SysErr*/
  {2u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1083u/* AppAccBytePosition */}, /*BMS_BattSOCLowRank*/
  {5u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1084u/* AppAccBytePosition */}, /*BMS_Type*/
  {2u/*BitLength*/, 318u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1085u/* AppAccBytePosition */}, /*BMS_FSOBCSS*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1086u/* AppAccBytePosition */}, /*BMS_V2GSts*/
  {1u/*BitLength*/, 304u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1087u/* AppAccBytePosition */}, /*BMS_GUNSts*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1088u/* AppAccBytePosition */}, /*BMS_WordDisp*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1089u/* AppAccBytePosition */}, /*CheckSum_BMS17*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1090u/* AppAccBytePosition */}, /*RollingCounter_BMS17*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1091u/* AppAccBytePosition */}, /*BMS_FD10_0x2F6*/
  {9u/*BitLength*/, 29u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1155u/* AppAccBytePosition */}, /*BMS_DTCNumber*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1157u/* AppAccBytePosition */}, /*BMS_BattSOCLim*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1158u/* AppAccBytePosition */}, /*BMS_FD11_0x324*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1166u/* AppAccBytePosition */}, /*CR_FCTA_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1167u/* AppAccBytePosition */}, /*CR_FCTB_Resp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1168u/* AppAccBytePosition */}, /*CR_BliSts*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1169u/* AppAccBytePosition */}, /*FCTA_Warn*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1170u/* AppAccBytePosition */}, /*FCTBTrig*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1171u/* AppAccBytePosition */}, /*FCTA_B_FuncSts*/
  {6u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1172u/* AppAccBytePosition */}, /*FCTA_B_TTC*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1173u/* AppAccBytePosition */}, /*CR_FD1_0x15E*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1237u/* AppAccBytePosition */}, /*LTurnLmpSwtSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1238u/* AppAccBytePosition */}, /*RTurnLmpSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1239u/* AppAccBytePosition */}, /*CSA1_0x165*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1247u/* AppAccBytePosition */}, /*SteerWheelAng*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1249u/* AppAccBytePosition */}, /*SteerWheelAngSign*/
  {15u/*BitLength*/, 33u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1250u/* AppAccBytePosition */}, /*SteerWheelSpd*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1252u/* AppAccBytePosition */}, /*SteerWheelSpdSign*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1253u/* AppAccBytePosition */}, /*SAS_Sts*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1254u/* AppAccBytePosition */}, /*HWA_OK_OFFSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1255u/* AppAccBytePosition */}, /*CSA2_0xA1*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1263u/* AppAccBytePosition */}, /*SeekDwnSwtSts*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1264u/* AppAccBytePosition */}, /*SeekUpSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1265u/* AppAccBytePosition */}, /*AdjVolUpSwtSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1266u/* AppAccBytePosition */}, /*AdjVolDwnSwtSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1267u/* AppAccBytePosition */}, /*VRSwtSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1268u/* AppAccBytePosition */}, /*SoundSourceModSwtSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1269u/* AppAccBytePosition */}, /*PhoneSwtSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1270u/* AppAccBytePosition */}, /*PageUpSwtSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1271u/* AppAccBytePosition */}, /*PageDwnSwtSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1272u/* AppAccBytePosition */}, /*MenuReturnSwtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1273u/* AppAccBytePosition */}, /*EnterSwtSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1274u/* AppAccBytePosition */}, /*HomeSwtSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1275u/* AppAccBytePosition */}, /*MuteSwtSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1276u/* AppAccBytePosition */}, /*SteerWheelHeatdSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1277u/* AppAccBytePosition */}, /*PageLSwtSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1278u/* AppAccBytePosition */}, /*PageRSwtSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1279u/* AppAccBytePosition */}, /*EnterSwtSts_Mmed*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1280u/* AppAccBytePosition */}, /*CustomSwtSts_Mmed*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1281u/* AppAccBytePosition */}, /*IpMenuSwtSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1282u/* AppAccBytePosition */}, /*CustomSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1283u/* AppAccBytePosition */}, /*CSA3_0x244*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1291u/* AppAccBytePosition */}, /*DCDC_ActSts_RM*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1292u/* AppAccBytePosition */}, /*DCDC_Tempwarning_RM*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1293u/* AppAccBytePosition */}, /*DCDC_FailStswarning_RM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1294u/* AppAccBytePosition */}, /*DCDC2_0x3BD*/
  {2u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1302u/* AppAccBytePosition */}, /*DCDC_FailSts*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1303u/* AppAccBytePosition */}, /*DCDC_OperMod*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1304u/* AppAccBytePosition */}, /*CheckSum_DCDC1*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1305u/* AppAccBytePosition */}, /*RollingCounter_DCDC1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1306u/* AppAccBytePosition */}, /*DCDC_FD1_0x12A*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1370u/* AppAccBytePosition */}, /*DrvMirrFold_UnfoldSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1371u/* AppAccBytePosition */}, /*PowerCutSwt*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1372u/* AppAccBytePosition */}, /*DrvWinAntiPinchSts*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1373u/* AppAccBytePosition */}, /*DrvSideRearWinLrnSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1374u/* AppAccBytePosition */}, /*DrvSideRearWinHotProtSts*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1375u/* AppAccBytePosition */}, /*DrvWinLrnSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1376u/* AppAccBytePosition */}, /*DrvSideRearAntiPinchSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1377u/* AppAccBytePosition */}, /*DrvWinHotProtSts*/
  {3u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1378u/* AppAccBytePosition */}, /*DrvWinPosnSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1379u/* AppAccBytePosition */}, /*PowerCutSwtLmpSts*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1380u/* AppAccBytePosition */}, /*DrvSideRearWinPosnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1381u/* AppAccBytePosition */}, /*DDCM1_0x2CA*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1389u/* AppAccBytePosition */}, /*DOCK_ExternalDevice_P*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1453u/* AppAccBytePosition */}, /*DOCK1_0x311*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1517u/* AppAccBytePosition */}, /*DOCK_HUT_ExternalDevice_E*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1581u/* AppAccBytePosition */}, /*DOCK2_0x1DF*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1645u/* AppAccBytePosition */}, /*DrvSeatMassLvlSetSts*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1646u/* AppAccBytePosition */}, /*DrvSeatMassModeSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1647u/* AppAccBytePosition */}, /*DrvSeatSupportPosnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1648u/* AppAccBytePosition */}, /*DSC4_0x2CE*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1656u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1657u/* AppAccBytePosition */}, /*DrvMassgSts*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1658u/* AppAccBytePosition */}, /*ChairRestSetSwtFB*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1659u/* AppAccBytePosition */}, /*ChairEndSetSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1660u/* AppAccBytePosition */}, /*DSM1_0x2C1*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1668u/* AppAccBytePosition */}, /*TranPMode_Sts*/
  {3u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1669u/* AppAccBytePosition */}, /*Stat_PwrSv_Lvl*/
  {2u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1670u/* AppAccBytePosition */}, /*DeepSlpCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1671u/* AppAccBytePosition */}, /*Dyn_PwrSv_Lvl*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1672u/* AppAccBytePosition */}, /*LvPwrSysErr*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1673u/* AppAccBytePosition */}, /*EEM1_0x2A8*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1681u/* AppAccBytePosition */}, /*EPB_VirtSwtAvailable*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1682u/* AppAccBytePosition */}, /*EPBSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1683u/* AppAccBytePosition */}, /*PressBrakePedalPointOut*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1684u/* AppAccBytePosition */}, /*EPBRedLmpSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1685u/* AppAccBytePosition */}, /*EPBErrSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1686u/* AppAccBytePosition */}, /*EPBTextDisp*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1687u/* AppAccBytePosition */}, /*CheckSum_EPB1*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1688u/* AppAccBytePosition */}, /*RollingCounter_EPB1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1689u/* AppAccBytePosition */}, /*EPB1_0x16B*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1697u/* AppAccBytePosition */}, /*EPS_FailSts*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1698u/* AppAccBytePosition */}, /*EPS_SteerMod*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1699u/* AppAccBytePosition */}, /*EPS_AssiRat*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1700u/* AppAccBytePosition */}, /*CheckSum_EPS1*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1701u/* AppAccBytePosition */}, /*RollingCounter_EPS1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1702u/* AppAccBytePosition */}, /*EPS_FD1_0x147*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1766u/* AppAccBytePosition */}, /*UnlockRtryPshIndOn*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1767u/* AppAccBytePosition */}, /*RotSteerWheel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1768u/* AppAccBytePosition */}, /*ESCL2_0x303*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1776u/* AppAccBytePosition */}, /*TgtRcprtnTrqSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1777u/* AppAccBytePosition */}, /*ESP10_0xD8*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1785u/* AppAccBytePosition */}, /*ESP_HMI_WarningOn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1786u/* AppAccBytePosition */}, /*ESP11_0xC8*/
  {1u/*BitLength*/, 335u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1794u/* AppAccBytePosition */}, /*ABSFailSts*/
  {1u/*BitLength*/, 334u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1795u/* AppAccBytePosition */}, /*EBDFailSts*/
  {1u/*BitLength*/, 333u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1796u/* AppAccBytePosition */}, /*VehSpdVld*/
  {13u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1797u/* AppAccBytePosition */}, /*VehSpd*/
  {1u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1799u/* AppAccBytePosition */}, /*VehOdoInfoSts*/
  {10u/*BitLength*/, 352u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1800u/* AppAccBytePosition */}, /*VehOdoInfo*/
  {1u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1802u/* AppAccBytePosition */}, /*ESPFuncOffSts*/
  {1u/*BitLength*/, 141u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1803u/* AppAccBytePosition */}, /*ESPActvInfoLmp*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1804u/* AppAccBytePosition */}, /*ESPFailSts*/
  {2u/*BitLength*/, 98u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1805u/* AppAccBytePosition */}, /*AVHErrSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1806u/* AppAccBytePosition */}, /*AVHSts*/
  {1u/*BitLength*/, 103u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1807u/* AppAccBytePosition */}, /*CDPActv*/
  {1u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1808u/* AppAccBytePosition */}, /*ABSActv*/
  {2u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1809u/* AppAccBytePosition */}, /*EBDfailsts_RM*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1810u/* AppAccBytePosition */}, /*HDCFault*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1811u/* AppAccBytePosition */}, /*HDCCtrl*/
  {16u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1812u/* AppAccBytePosition */}, /*ESP_MasterCylBrkPress*/
  {1u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1814u/* AppAccBytePosition */}, /*VDCActv*/
  {1u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1815u/* AppAccBytePosition */}, /*PTCActv*/
  {1u/*BitLength*/, 151u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1816u/* AppAccBytePosition */}, /*BTCActv*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1817u/* AppAccBytePosition */}, /*ESP_MasterCylBrkPressVld*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1818u/* AppAccBytePosition */}, /*CheckSum_ABS3*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1819u/* AppAccBytePosition */}, /*RollingCounter_ABS3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1820u/* AppAccBytePosition */}, /*CheckSum_ESP1*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1821u/* AppAccBytePosition */}, /*RollingCounter_ESP1*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 13u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1822u/* AppAccBytePosition */}, /*ESP_FD2_0x137*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1878u/* AppAccBytePosition */}, /*EVCC_PPLineSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1879u/* AppAccBytePosition */}, /*EVCC1_0x310*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1887u/* AppAccBytePosition */}, /*E_Park_Failcode*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1888u/* AppAccBytePosition */}, /*E_Park_Sts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1889u/* AppAccBytePosition */}, /*E_Park_Inhibit*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1890u/* AppAccBytePosition */}, /*E_Park_FaultLmpSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1891u/* AppAccBytePosition */}, /*CheckSum_E_Park1*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1892u/* AppAccBytePosition */}, /*RollingCounter_E_Park1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1893u/* AppAccBytePosition */}, /*E_Park1_0x24F*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1901u/* AppAccBytePosition */}, /*ScenarioID*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1902u/* AppAccBytePosition */}, /*ScenarioReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1903u/* AppAccBytePosition */}, /*GW1_0x239*/
  {14u/*BitLength*/, 74u/* BitPosition */, 2u/* ByteLength */, 9u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 23u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1911u/* AppAccBytePosition */}, /*U_BATT*/
  {2u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1913u/* AppAccBytePosition */}, /*I_RANGE*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1914u/* AppAccBytePosition */}, /*I_BATT*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1916u/* AppAccBytePosition */}, /*T_BATT*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1917u/* AppAccBytePosition */}, /*IBATT_QUIESCENT*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1918u/* AppAccBytePosition */}, /*Status_Current*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1919u/* AppAccBytePosition */}, /*Status_Voltage*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1920u/* AppAccBytePosition */}, /*Status_Temp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1921u/* AppAccBytePosition */}, /*ERROR_Calib*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1922u/* AppAccBytePosition */}, /*ERROR_IDENT*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1923u/* AppAccBytePosition */}, /*Resp_Error*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1924u/* AppAccBytePosition */}, /*FLAG_INCONSISTENCY*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1925u/* AppAccBytePosition */}, /*SOC*/
  {8u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1926u/* AppAccBytePosition */}, /*SOH_SUL*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1927u/* AppAccBytePosition */}, /*SOC_STATE*/
  {2u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1928u/* AppAccBytePosition */}, /*SOH_SUL_STATE*/
  {8u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1929u/* AppAccBytePosition */}, /*SOFV_StopEnable*/
  {8u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1930u/* AppAccBytePosition */}, /*SOFV_Restart*/
  {8u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1931u/* AppAccBytePosition */}, /*SOH_LAM*/
  {8u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1932u/* AppAccBytePosition */}, /*SOH_COR*/
  {2u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1933u/* AppAccBytePosition */}, /*SOFV_StopEnable_STATE*/
  {2u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1934u/* AppAccBytePosition */}, /*SOFV_Restart_STATE*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1935u/* AppAccBytePosition */}, /*SOH_LAM_STATE*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1936u/* AppAccBytePosition */}, /*SOH_COR_STATE*/
  {16u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1937u/* AppAccBytePosition */}, /*Q_Charge*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1939u/* AppAccBytePosition */}, /*Q_Discharge*/
  {14u/*BitLength*/, 274u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 23u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1941u/* AppAccBytePosition */}, /*U_BATT_STORED*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1943u/* AppAccBytePosition */}, /*I_RANGE_STORED*/
  {16u/*BitLength*/, 288u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1944u/* AppAccBytePosition */}, /*I_BATT_STORED*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1946u/* AppAccBytePosition */}, /*T_BATT_STORED*/
  {8u/*BitLength*/, 296u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1947u/* AppAccBytePosition */}, /*SOC_STORED*/
  {4u/*BitLength*/, 304u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1948u/* AppAccBytePosition */}, /*HISTORICAL_COUNTER*/
  {1u/*BitLength*/, 313u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1949u/* AppAccBytePosition */}, /*Quickmode_State*/
  {1u/*BitLength*/, 314u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1950u/* AppAccBytePosition */}, /*Blind_charge_Quickmode*/
  {1u/*BitLength*/, 315u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1951u/* AppAccBytePosition */}, /*JumpStart_Quickmode*/
  {1u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1952u/* AppAccBytePosition */}, /*SOX_Mode*/
  {1u/*BitLength*/, 317u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1953u/* AppAccBytePosition */}, /*DisChargeCurrWU*/
  {1u/*BitLength*/, 318u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1954u/* AppAccBytePosition */}, /*ChargeCurrWU*/
  {1u/*BitLength*/, 319u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1955u/* AppAccBytePosition */}, /*LowSOCWU*/
  {1u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1956u/* AppAccBytePosition */}, /*HighSOCWU*/
  {1u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1957u/* AppAccBytePosition */}, /*StopEnable*/
  {1u/*BitLength*/, 311u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1958u/* AppAccBytePosition */}, /*StartRequest*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1959u/* AppAccBytePosition */}, /*CheckSum_GWM1*/
  {2u/*BitLength*/, 342u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1960u/* AppAccBytePosition */}, /*OTA_UpgrdModSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1961u/* AppAccBytePosition */}, /*RollingCounter_GWM1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1962u/* AppAccBytePosition */}, /*GW_FD1_0x2BB*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2026u/* AppAccBytePosition */}, /*OTAUpgrdSts*/
  {2u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2027u/* AppAccBytePosition */}, /*OTA_UpgrdModErrCode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2028u/* AppAccBytePosition */}, /*GW_OTA_0x1D9*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2036u/* AppAccBytePosition */}, /*ResetCount*/
  {88u/*BitLength*/, 40u/* BitPosition */, 11u/* ByteLength */, 5u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 25u/* InitValueIdx */, 11u/* AppAccBtyeLength */, 2038u/* AppAccBytePosition */}, /*CMACMessageInfo*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 26u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2049u/* AppAccBytePosition */}, /*TripCount*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2053u/* AppAccBytePosition */}, /*APS_PrkgMod*/
  {7u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2054u/* AppAccBytePosition */}, /*APS_ProcBar*/
  {1u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2055u/* AppAccBytePosition */}, /*APS_SwtSts*/
  {3u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2056u/* AppAccBytePosition */}, /*APS_SlotDisp*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2057u/* AppAccBytePosition */}, /*APS_SysSoundIndcn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2058u/* AppAccBytePosition */}, /*APS_PrkgTyp*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2059u/* AppAccBytePosition */}, /*APS_TextDisp*/
  {3u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2060u/* AppAccBytePosition */}, /*APS_WorkSts*/
  {1u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2061u/* AppAccBytePosition */}, /*LParaPrkgOutVald*/
  {1u/*BitLength*/, 282u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2062u/* AppAccBytePosition */}, /*RParaPrkgOutVald*/
  {1u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2063u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald*/
  {1u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2064u/* AppAccBytePosition */}, /*TailVertPrkgOutVald*/
  {3u/*BitLength*/, 277u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2065u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd*/
  {4u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2066u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts*/
  {2u/*BitLength*/, 294u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2067u/* AppAccBytePosition */}, /*APS_MovgDirc*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2068u/* AppAccBytePosition */}, /*P2P_PahDelSts*/
  {4u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2069u/* AppAccBytePosition */}, /*P2P_SelfDetErrCode*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2070u/* AppAccBytePosition */}, /*P2P_SelfDetSts*/
  {1u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2071u/* AppAccBytePosition */}, /*P2P_Pah1Avail*/
  {1u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2072u/* AppAccBytePosition */}, /*P2P_Pah2Avail*/
  {1u/*BitLength*/, 293u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2073u/* AppAccBytePosition */}, /*P2P_PrkgDirectSts*/
  {2u/*BitLength*/, 330u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2074u/* AppAccBytePosition */}, /*HAVP_StartBtn_Ena*/
  {2u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2075u/* AppAccBytePosition */}, /*HAVP_StopBtn_Ena*/
  {2u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2076u/* AppAccBytePosition */}, /*HAVP_SelfParLotEnding_Ena*/
  {2u/*BitLength*/, 366u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2077u/* AppAccBytePosition */}, /*ParallelSlotBtn_Ena*/
  {2u/*BitLength*/, 364u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2078u/* AppAccBytePosition */}, /*VerticalSlotBtn_Ena*/
  {2u/*BitLength*/, 362u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2079u/* AppAccBytePosition */}, /*ClockwiseBtn_Ena*/
  {2u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2080u/* AppAccBytePosition */}, /*AnticlockwiseBtn_Ena*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2081u/* AppAccBytePosition */}, /*SlotConfirmBtn_Ena*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2082u/* AppAccBytePosition */}, /*APS_ESP_BrkDistance*/
  {2u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2084u/* AppAccBytePosition */}, /*AVP_T_Box_WorkSts*/
  {6u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2085u/* AppAccBytePosition */}, /*PAVP_TextDis*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2086u/* AppAccBytePosition */}, /*HAP_FD1_0x15B*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2150u/* AppAccBytePosition */}, /*AutoAVMSwtSet_Sts*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2151u/* AppAccBytePosition */}, /*AVM_CurrSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2152u/* AppAccBytePosition */}, /*GuidOvlSts*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2153u/* AppAccBytePosition */}, /*FrntCamInpFailSts*/
  {1u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2154u/* AppAccBytePosition */}, /*RearCamInpFailSts*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2155u/* AppAccBytePosition */}, /*LeCamInpFailSts*/
  {1u/*BitLength*/, 111u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2156u/* AppAccBytePosition */}, /*RiCamInpFailSts*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2157u/* AppAccBytePosition */}, /*EolNotCmpltd*/
  {1u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2158u/* AppAccBytePosition */}, /*OvlOpFailSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2159u/* AppAccBytePosition */}, /*LaneCalSts*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2160u/* AppAccBytePosition */}, /*RadarDispSts*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2161u/* AppAccBytePosition */}, /*LaneCalFltSts*/
  {1u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2162u/* AppAccBytePosition */}, /*AutoViewChgFuncSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2163u/* AppAccBytePosition */}, /*CarMdlTrsprcySts*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2164u/* AppAccBytePosition */}, /*CarMdlDispSts*/
  {1u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2165u/* AppAccBytePosition */}, /*CurrCalResultSts*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2166u/* AppAccBytePosition */}, /*MdlColrSts*/
  {6u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2167u/* AppAccBytePosition */}, /*SigViewIndcn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2168u/* AppAccBytePosition */}, /*HAP_DispCmd*/
  {9u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2169u/* AppAccBytePosition */}, /*AVM_3DAngSts*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2171u/* AppAccBytePosition */}, /*MOD_WorkSts*/
  {3u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2172u/* AppAccBytePosition */}, /*HAP_Hmi_Index*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2173u/* AppAccBytePosition */}, /*MOD_AlarmSts*/
  {2u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2174u/* AppAccBytePosition */}, /*DVRWorkSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2175u/* AppAccBytePosition */}, /*HAP_FD2_0x274*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2239u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1*/
  {4u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2240u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2241u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3*/
  {4u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2242u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2243u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2244u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2245u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2*/
  {4u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2246u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2247u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4*/
  {4u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2248u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2249u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2250u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2251u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2252u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2253u/* AppAccBytePosition */}, /*SDW_SoundIndcn*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2254u/* AppAccBytePosition */}, /*SDWActiveSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2255u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1*/
  {4u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2256u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2*/
  {4u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2257u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1*/
  {4u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2258u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2259u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2260u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2261u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1*/
  {4u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2262u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2263u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2264u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2265u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2266u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2267u/* AppAccBytePosition */}, /*RPAS_WorkSts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2268u/* AppAccBytePosition */}, /*RPAS_SoundIndcn*/
  {2u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2269u/* AppAccBytePosition */}, /*MEBWorkSts*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2270u/* AppAccBytePosition */}, /*MEB_EnableSts*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2271u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2272u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2*/
  {4u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2273u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1*/
  {4u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2274u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2275u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2276u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2*/
  {4u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2277u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1*/
  {4u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2278u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2*/
  {1u/*BitLength*/, 239u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2279u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts*/
  {1u/*BitLength*/, 238u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2280u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 237u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2281u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 236u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2282u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts*/
  {2u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2283u/* AppAccBytePosition */}, /*FPAS_WorkSts*/
  {1u/*BitLength*/, 233u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2284u/* AppAccBytePosition */}, /*FPAS_DispCmd*/
  {1u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2285u/* AppAccBytePosition */}, /*FPAS_AutoModSts*/
  {2u/*BitLength*/, 246u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2286u/* AppAccBytePosition */}, /*FPAS_SoundIndcn*/
  {4u/*BitLength*/, 276u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2287u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2288u/* AppAccBytePosition */}, /*APA_FuncSts*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2289u/* AppAccBytePosition */}, /*P2P_FuncSts*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2290u/* AppAccBytePosition */}, /*RADS_FuncSts*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2291u/* AppAccBytePosition */}, /*FADS_FuncSts*/
  {2u/*BitLength*/, 274u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2292u/* AppAccBytePosition */}, /*HAP_TextIconDispCtrl*/
  {7u/*BitLength*/, 252u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2293u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2294u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn*/
  {7u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2295u/* AppAccBytePosition */}, /*P2P_ProcBar*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2296u/* AppAccBytePosition */}, /*HAVP_ProcRa*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2297u/* AppAccBytePosition */}, /*HAP_FD3_0x298*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2361u/* AppAccBytePosition */}, /*USS_FLSide1_Status*/
  {7u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2362u/* AppAccBytePosition */}, /*USS_FLSide1_Dist*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2363u/* AppAccBytePosition */}, /*USS_RLSide2_Status*/
  {7u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2364u/* AppAccBytePosition */}, /*USS_RLSide2_Dist*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2365u/* AppAccBytePosition */}, /*USS_FRSide1_Status*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2366u/* AppAccBytePosition */}, /*USS_FRSide1_Dist*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2367u/* AppAccBytePosition */}, /*USS_RRSide2_Status*/
  {7u/*BitLength*/, 297u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2368u/* AppAccBytePosition */}, /*USS_RRSide2_Dist*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2369u/* AppAccBytePosition */}, /*HAP_RtCam_WorkSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2370u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_ID*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2371u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_type*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2372u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Confidence*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2373u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2375u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2377u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_ID*/
  {3u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2378u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_type*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2379u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Confidence*/
  {12u/*BitLength*/, 92u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2380u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2382u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2384u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_ID*/
  {3u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2385u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_type*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2386u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Confidence*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2387u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2389u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2391u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_ID*/
  {3u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2392u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_type*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2393u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Confidence*/
  {12u/*BitLength*/, 220u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2394u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2396u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2398u/* AppAccBytePosition */}, /*HAP_FD6_0x289*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2462u/* AppAccBytePosition */}, /*HAVP_LrngDst*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2463u/* AppAccBytePosition */}, /*HAVP_HUT_TextDisp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2464u/* AppAccBytePosition */}, /*HAP_FD7_0x29B*/
  {11u/*BitLength*/, 109u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 27u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2528u/* AppAccBytePosition */}, /*IFCTrqOvlCmdReqValue*/
  {14u/*BitLength*/, 82u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 28u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2530u/* AppAccBytePosition */}, /*IFCTrqOvlCmdProtnValue*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2532u/* AppAccBytePosition */}, /*IFC_FD1_0x12B*/
  {2u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2596u/* AppAccBytePosition */}, /*LDW_LKA_Snvty*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2597u/* AppAccBytePosition */}, /*IFCHUTInterface*/
  {1u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2598u/* AppAccBytePosition */}, /*CameraBlockageSts*/
  {3u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2599u/* AppAccBytePosition */}, /*LSSFuncSts*/
  {2u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2600u/* AppAccBytePosition */}, /*LaneAvailability*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2601u/* AppAccBytePosition */}, /*TJA_FollowSts*/
  {3u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2602u/* AppAccBytePosition */}, /*LSSErrSts*/
  {12u/*BitLength*/, 212u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2603u/* AppAccBytePosition */}, /*IFC_LaneCurve*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2605u/* AppAccBytePosition */}, /*LDWResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2606u/* AppAccBytePosition */}, /*LKAResp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2607u/* AppAccBytePosition */}, /*LCKResp*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2608u/* AppAccBytePosition */}, /*ELKResp*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2609u/* AppAccBytePosition */}, /*AESResp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2610u/* AppAccBytePosition */}, /*ESS_PedResp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2611u/* AppAccBytePosition */}, /*ESS_VehResp*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2612u/* AppAccBytePosition */}, /*LSSWarnFormResp*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2613u/* AppAccBytePosition */}, /*LSSResp*/
  {1u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2614u/* AppAccBytePosition */}, /*IntelligentEvaResp*/
  {2u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2615u/* AppAccBytePosition */}, /*ELKActSts*/
  {2u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2616u/* AppAccBytePosition */}, /*IntelligentEvaActSts*/
  {2u/*BitLength*/, 162u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2617u/* AppAccBytePosition */}, /*LCKStsIndcr*/
  {2u/*BitLength*/, 153u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2618u/* AppAccBytePosition */}, /*IFCCalibrationSts*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2619u/* AppAccBytePosition */}, /*LDW_LKAWarn*/
  {3u/*BitLength*/, 139u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2620u/* AppAccBytePosition */}, /*LSSIntervention*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2621u/* AppAccBytePosition */}, /*ELKMainState*/
  {3u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2622u/* AppAccBytePosition */}, /*IFC_Handsoffwarn*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2623u/* AppAccBytePosition */}, /*IFC_LeLaneTyp*/
  {3u/*BitLength*/, 222u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2624u/* AppAccBytePosition */}, /*IFC_RiLaneTyp*/
  {3u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2625u/* AppAccBytePosition */}, /*IFC_NextLeLaneTyp*/
  {3u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2626u/* AppAccBytePosition */}, /*IFC_NextRiLaneTyp*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2627u/* AppAccBytePosition */}, /*IFC_LeLane_dy*/
  {12u/*BitLength*/, 240u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2629u/* AppAccBytePosition */}, /*IFC_RiLane_dy*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2631u/* AppAccBytePosition */}, /*IFC_NextLeLane_dy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2633u/* AppAccBytePosition */}, /*IFC_NextRiLane_dy*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2635u/* AppAccBytePosition */}, /*AESintervention*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2636u/* AppAccBytePosition */}, /*ESSintervention*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2637u/* AppAccBytePosition */}, /*AESSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2638u/* AppAccBytePosition */}, /*ESSSts*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2639u/* AppAccBytePosition */}, /*AESErrSts*/
  {1u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2640u/* AppAccBytePosition */}, /*ESSErrSts*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2641u/* AppAccBytePosition */}, /*Checksum_IFC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2642u/* AppAccBytePosition */}, /*Checksum_IFC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2643u/* AppAccBytePosition */}, /*Checksum_IFC5*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2644u/* AppAccBytePosition */}, /*Checksum_IFC6*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2645u/* AppAccBytePosition */}, /*RollingCounter_IFC3*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2646u/* AppAccBytePosition */}, /*RollingCounter_IFC4*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2647u/* AppAccBytePosition */}, /*RollingCounter_IFC5*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2648u/* AppAccBytePosition */}, /*RollingCounter_IFC6*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 2649u/* AppAccBytePosition */}, /*IFC_FD2_0x23D*/
  {5u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2705u/* AppAccBytePosition */}, /*TSR_Snvty*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2706u/* AppAccBytePosition */}, /*TSRResp*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2707u/* AppAccBytePosition */}, /*TSRWarnResp*/
  {2u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2708u/* AppAccBytePosition */}, /*TSRSpdLimUnit*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2709u/* AppAccBytePosition */}, /*TSRSpdLim*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2710u/* AppAccBytePosition */}, /*TSRSpdLimCfdc*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2711u/* AppAccBytePosition */}, /*TSRSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2712u/* AppAccBytePosition */}, /*TSRSpdLimSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2713u/* AppAccBytePosition */}, /*TSRTrfcSignValCfdc*/
  {8u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2714u/* AppAccBytePosition */}, /*TSRTrfcSignVal*/
  {1u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2715u/* AppAccBytePosition */}, /*TSRSpdLimWarn*/
  {2u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2716u/* AppAccBytePosition */}, /*IDC_L2_TurnLightReq*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2717u/* AppAccBytePosition */}, /*HWA_ALC_Trig*/
  {4u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2718u/* AppAccBytePosition */}, /*MRC_InterSysInfoDisp*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2719u/* AppAccBytePosition */}, /*IFC_Line01_Source*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2720u/* AppAccBytePosition */}, /*IFC_Line02_Source*/
  {2u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2721u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Posn*/
  {2u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2722u/* AppAccBytePosition */}, /*Stop_Mark_Detn*/
  {9u/*BitLength*/, 175u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2723u/* AppAccBytePosition */}, /*Stop_Mark_Dx*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2725u/* AppAccBytePosition */}, /*Zebra_Mark_Detn*/
  {2u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2726u/* AppAccBytePosition */}, /*Grid_Mark_Detn*/
  {3u/*BitLength*/, 181u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2727u/* AppAccBytePosition */}, /*HWA_InhibitWarn*/
  {1u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2728u/* AppAccBytePosition */}, /*LaneChngCfmSwt_Resp*/
  {1u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2729u/* AppAccBytePosition */}, /*ALC_SwtReq_Resp*/
  {1u/*BitLength*/, 191u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2730u/* AppAccBytePosition */}, /*AutoSpdSetSwt_Resp*/
  {1u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2731u/* AppAccBytePosition */}, /*VoiceBrdcSwt_Resp*/
  {4u/*BitLength*/, 177u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2732u/* AppAccBytePosition */}, /*UsrManSts_Resp*/
  {9u/*BitLength*/, 215u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2733u/* AppAccBytePosition */}, /*Grid_Mark_Dx*/
  {9u/*BitLength*/, 231u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2735u/* AppAccBytePosition */}, /*Zebra_Mark_Dx*/
  {2u/*BitLength*/, 213u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2737u/* AppAccBytePosition */}, /*TSR_Traffic_Light*/
  {2u/*BitLength*/, 211u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2738u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Through*/
  {2u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2739u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Le*/
  {2u/*BitLength*/, 229u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2740u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Ri*/
  {4u/*BitLength*/, 138u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2741u/* AppAccBytePosition */}, /*HWA_WarnInfoDisp*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2742u/* AppAccBytePosition */}, /*HWA_TakOver_Trig*/
  {2u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2743u/* AppAccBytePosition */}, /*HWA_TakOver_Req*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2744u/* AppAccBytePosition */}, /*MRC_TakOver_Req*/
  {4u/*BitLength*/, 154u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2745u/* AppAccBytePosition */}, /*NOH_WarnInfoDisp*/
  {1u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2746u/* AppAccBytePosition */}, /*RainMode_Swt_Resp*/
  {2u/*BitLength*/, 226u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2747u/* AppAccBytePosition */}, /*LCMode_Swt_Resp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2748u/* AppAccBytePosition */}, /*IFC_FD3_0x2CF*/
  {13u/*BitLength*/, 19u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2812u/* AppAccBytePosition */}, /*IFC_Line01_Dy*/
  {15u/*BitLength*/, 36u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2814u/* AppAccBytePosition */}, /*IFC_Line01_Curv*/
  {20u/*BitLength*/, 48u/* BitPosition */, 3u/* ByteLength */, 6u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2816u/* AppAccBytePosition */}, /*IFC_Line01_CurvChange*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2820u/* AppAccBytePosition */}, /*IFC_Line01_Type*/
  {13u/*BitLength*/, 83u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2821u/* AppAccBytePosition */}, /*IFC_Line02_Dy*/
  {15u/*BitLength*/, 100u/* BitPosition */, 3u/* ByteLength */, 12u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2823u/* AppAccBytePosition */}, /*IFC_Line02_Curv*/
  {20u/*BitLength*/, 112u/* BitPosition */, 3u/* ByteLength */, 14u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2825u/* AppAccBytePosition */}, /*IFC_Line02_CurvChange*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2829u/* AppAccBytePosition */}, /*IFC_Line02_Type*/
  {13u/*BitLength*/, 147u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2830u/* AppAccBytePosition */}, /*IFC_Line03_Dy*/
  {15u/*BitLength*/, 164u/* BitPosition */, 3u/* ByteLength */, 20u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2832u/* AppAccBytePosition */}, /*IFC_Line03_Curv*/
  {20u/*BitLength*/, 176u/* BitPosition */, 3u/* ByteLength */, 22u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2834u/* AppAccBytePosition */}, /*IFC_Line03_CurvChange*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2838u/* AppAccBytePosition */}, /*IFC_Line03_Type*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2839u/* AppAccBytePosition */}, /*IFC_Line04_Dy*/
  {15u/*BitLength*/, 228u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2841u/* AppAccBytePosition */}, /*IFC_Line04_Curv*/
  {20u/*BitLength*/, 240u/* BitPosition */, 3u/* ByteLength */, 30u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2843u/* AppAccBytePosition */}, /*IFC_Line04_CurvChange*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2847u/* AppAccBytePosition */}, /*IFC_Line04_Type*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2848u/* AppAccBytePosition */}, /*IFC_Roadedge01_Dy*/
  {15u/*BitLength*/, 292u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2850u/* AppAccBytePosition */}, /*IFC_Roadedge01_Curv*/
  {20u/*BitLength*/, 304u/* BitPosition */, 3u/* ByteLength */, 38u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2852u/* AppAccBytePosition */}, /*IFC_Roadedge01_CurvChange*/
  {4u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2856u/* AppAccBytePosition */}, /*IFC_Roadedge01_Type*/
  {13u/*BitLength*/, 339u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2857u/* AppAccBytePosition */}, /*IFC_Roadedge02_Dy*/
  {15u/*BitLength*/, 356u/* BitPosition */, 3u/* ByteLength */, 44u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2859u/* AppAccBytePosition */}, /*IFC_Roadedge02_Curv*/
  {20u/*BitLength*/, 368u/* BitPosition */, 3u/* ByteLength */, 46u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2861u/* AppAccBytePosition */}, /*IFC_Roadedge02_CurvChange*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2865u/* AppAccBytePosition */}, /*IFC_Roadedge02_Type*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2866u/* AppAccBytePosition */}, /*IFC_FD5_0x19F*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2930u/* AppAccBytePosition */}, /*IFC_Line01_DxStart*/
  {15u/*BitLength*/, 34u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2932u/* AppAccBytePosition */}, /*IFC_Line01_DxEnd*/
  {9u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2934u/* AppAccBytePosition */}, /*IFC_Line01_HeadingAngle*/
  {9u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2936u/* AppAccBytePosition */}, /*IFC_Line02_HeadingAngle*/
  {15u/*BitLength*/, 81u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2938u/* AppAccBytePosition */}, /*IFC_Line02_DxStart*/
  {15u/*BitLength*/, 97u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2940u/* AppAccBytePosition */}, /*IFC_Line02_DxEnd*/
  {15u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2942u/* AppAccBytePosition */}, /*IFC_Line03_DxStart*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2944u/* AppAccBytePosition */}, /*IFC_Line03_DxEnd*/
  {9u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2946u/* AppAccBytePosition */}, /*IFC_Line03_HeadingAngle*/
  {15u/*BitLength*/, 169u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2948u/* AppAccBytePosition */}, /*IFC_Line04_DxStart*/
  {9u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2950u/* AppAccBytePosition */}, /*IFC_Line04_HeadingAngle*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2952u/* AppAccBytePosition */}, /*IFC_Line04_DxEnd*/
  {15u/*BitLength*/, 225u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2954u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxStart*/
  {15u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2956u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxEnd*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2958u/* AppAccBytePosition */}, /*IFC_Roadedge01_HeadingAngle*/
  {15u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2960u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxStart*/
  {15u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2962u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxEnd*/
  {9u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2964u/* AppAccBytePosition */}, /*IFC_Roadedge02_HeadingAngle*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2966u/* AppAccBytePosition */}, /*IFC_FD6_0x222*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3030u/* AppAccBytePosition */}, /*IB_Warn*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3031u/* AppAccBytePosition */}, /*Ibooster_FD2_0x120*/
  {16u/*BitLength*/, 168u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3095u/* AppAccBytePosition */}, /*MCU_ActRotSpd*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3097u/* AppAccBytePosition */}, /*MCU_OperMod*/
  {3u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3098u/* AppAccBytePosition */}, /*MCU_FailSts*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3099u/* AppAccBytePosition */}, /*MCU_ParkSts*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3100u/* AppAccBytePosition */}, /*MCU_ActHvCurr*/
  {8u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3102u/* AppAccBytePosition */}, /*MCU_ErrCode*/
  {15u/*BitLength*/, 105u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3103u/* AppAccBytePosition */}, /*MCU_ActHvVolt*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3105u/* AppAccBytePosition */}, /*MCU_PosAvailTrqMax_10s*/
  {14u/*BitLength*/, 229u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3107u/* AppAccBytePosition */}, /*MCU_ActTrq*/
  {7u/*BitLength*/, 238u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3109u/* AppAccBytePosition */}, /*MCU_EffReqTrq*/
  {13u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3110u/* AppAccBytePosition */}, /*MCU_PosAvailTrqMax*/
  {1u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3112u/* AppAccBytePosition */}, /*MCU_SysErrSts*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3113u/* AppAccBytePosition */}, /*MCU_ActPosTrq*/
  {13u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3115u/* AppAccBytePosition */}, /*MCU_NegAvailTrqMax*/
  {13u/*BitLength*/, 316u/* BitPosition */, 3u/* ByteLength */, 39u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3117u/* AppAccBytePosition */}, /*MCU_NegAvailTrqMax_10s*/
  {16u/*BitLength*/, 400u/* BitPosition */, 2u/* ByteLength */, 50u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3119u/* AppAccBytePosition */}, /*MCU_ActPosRotSpd*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3121u/* AppAccBytePosition */}, /*MCU_FD1_0xAE*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3185u/* AppAccBytePosition */}, /*MCU_ActTemp*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3186u/* AppAccBytePosition */}, /*MCU_InvActTemp*/
  {8u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3187u/* AppAccBytePosition */}, /*MCU_ClntoutletActTemp*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3188u/* AppAccBytePosition */}, /*MCU_OffsetAngle*/
  {10u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3190u/* AppAccBytePosition */}, /*MCU_MotorPower*/
  {1u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3192u/* AppAccBytePosition */}, /*MCU_lockrotorsts*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3193u/* AppAccBytePosition */}, /*MCU_ActHvDCCurr_RM*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3195u/* AppAccBytePosition */}, /*MCU_FD2_0x2A4*/
  {2u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3259u/* AppAccBytePosition */}, /*OBC_ConnectSts_EV*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3260u/* AppAccBytePosition */}, /*OBC_ModSts_EV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3261u/* AppAccBytePosition */}, /*OBC11_0x321*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3269u/* AppAccBytePosition */}, /*OBC_V2VSts*/
  {2u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3270u/* AppAccBytePosition */}, /*OBC_V2VInfo*/
  {2u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3271u/* AppAccBytePosition */}, /*OBC_V2LSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3272u/* AppAccBytePosition */}, /*OBC12_0x323*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3280u/* AppAccBytePosition */}, /*OBC_E_lockSts*/
  {2u/*BitLength*/, 63u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3281u/* AppAccBytePosition */}, /*OBC_CCLineConnectSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3282u/* AppAccBytePosition */}, /*OBC_FD2_0x31F*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3290u/* AppAccBytePosition */}, /*PassMirrFold_UnfoldSts*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3291u/* AppAccBytePosition */}, /*PassWinAntiPinchSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3292u/* AppAccBytePosition */}, /*PassSideRearWinAntiPinchSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3293u/* AppAccBytePosition */}, /*PassSideRearWinLrnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3294u/* AppAccBytePosition */}, /*PassSideRearWinHotProtSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3295u/* AppAccBytePosition */}, /*PassWinLrnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3296u/* AppAccBytePosition */}, /*PassWinHotProtSts*/
  {3u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3297u/* AppAccBytePosition */}, /*PassWinPosnSts*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3298u/* AppAccBytePosition */}, /*PassSideRearWinPosnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3299u/* AppAccBytePosition */}, /*PDCM1_0x2CD*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3307u/* AppAccBytePosition */}, /*PKEDoorLockCmd*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3308u/* AppAccBytePosition */}, /*RKEDoorLockCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3309u/* AppAccBytePosition */}, /*PEPS1_0xA5*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3317u/* AppAccBytePosition */}, /*SysPowerMod*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3318u/* AppAccBytePosition */}, /*SysPowerModVld*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3319u/* AppAccBytePosition */}, /*EmgyShutDwnRmd*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3320u/* AppAccBytePosition */}, /*RemUpgrdModSysPower*/
  {2u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3321u/* AppAccBytePosition */}, /*RemPowerFailureSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3322u/* AppAccBytePosition */}, /*PEPS2_0x295*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3330u/* AppAccBytePosition */}, /*PEPS_RlyDrvErr*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3331u/* AppAccBytePosition */}, /*WarnPowerNotInOffPosn*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3332u/* AppAccBytePosition */}, /*WarnKeyInCarWhenExit*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3333u/* AppAccBytePosition */}, /*WarnVldKeyNotFound*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3334u/* AppAccBytePosition */}, /*WarnEngStrtNotMeet*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3335u/* AppAccBytePosition */}, /*PowerRlyFault*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3336u/* AppAccBytePosition */}, /*PEPS4_0x302*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3344u/* AppAccBytePosition */}, /*PLG_Sts*/
  {3u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3345u/* AppAccBytePosition */}, /*PLG_HeightSetSts*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3346u/* AppAccBytePosition */}, /*PLG_SysFlt*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3347u/* AppAccBytePosition */}, /*PLG_InitLearnedSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3348u/* AppAccBytePosition */}, /*PLG_1_0x2FE*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3356u/* AppAccBytePosition */}, /*RSDS_IPSoundReq*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3357u/* AppAccBytePosition */}, /*RSDS_ErrSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3358u/* AppAccBytePosition */}, /*RSDS_BrkgTrig*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3359u/* AppAccBytePosition */}, /*RSDS_BliSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3360u/* AppAccBytePosition */}, /*RSDS_TrailerSts*/
  {1u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3361u/* AppAccBytePosition */}, /*RSDS_LCAResp*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3362u/* AppAccBytePosition */}, /*RSDS_DOWResp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3363u/* AppAccBytePosition */}, /*RSDS_RCWResp*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3364u/* AppAccBytePosition */}, /*RSDS_RCTAResp*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3365u/* AppAccBytePosition */}, /*RSDS_RCTABrkResp*/
  {2u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3366u/* AppAccBytePosition */}, /*RSDS_RCW_Trigger*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3367u/* AppAccBytePosition */}, /*RSDS_CTA_Actv*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3368u/* AppAccBytePosition */}, /*RSDS_LEDLightReqLeft*/
  {2u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3369u/* AppAccBytePosition */}, /*RSDS_LEDLightReqRight*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3370u/* AppAccBytePosition */}, /*BSD_LCA_warningReqRight*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3371u/* AppAccBytePosition */}, /*BSD_LCA_warningReqleft*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3372u/* AppAccBytePosition */}, /*DOW_warningReqRight*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3373u/* AppAccBytePosition */}, /*DOW_warningReqleft*/
  {1u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3374u/* AppAccBytePosition */}, /*RCTA_warningReqRight*/
  {1u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3375u/* AppAccBytePosition */}, /*RCTA_warningReqLeft*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3376u/* AppAccBytePosition */}, /*RSDS_FD1_0x16F*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3440u/* AppAccBytePosition */}, /*RCTA_B_TTC*/
  {6u/*BitLength*/, 20u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3441u/* AppAccBytePosition */}, /*BSD_LCA_Left_TTC*/
  {6u/*BitLength*/, 30u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3442u/* AppAccBytePosition */}, /*BSD_LCA_Right_TTC*/
  {6u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3443u/* AppAccBytePosition */}, /*RCW_TTC*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3444u/* AppAccBytePosition */}, /*RSDS_LeTgt_01*/
  {10u/*BitLength*/, 94u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3445u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dx*/
  {7u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3447u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dy*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3448u/* AppAccBytePosition */}, /*RSDS_LeTgt_02*/
  {10u/*BitLength*/, 99u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3449u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dx*/
  {7u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3451u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dy*/
  {10u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3452u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dx*/
  {7u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3454u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dy*/
  {1u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3455u/* AppAccBytePosition */}, /*RSDS_RiTgt_02*/
  {10u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3456u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dx*/
  {7u/*BitLength*/, 167u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3458u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dy*/
  {1u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3459u/* AppAccBytePosition */}, /*RSDS_MidTgt_01*/
  {10u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3460u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dx*/
  {7u/*BitLength*/, 181u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3462u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dy*/
  {1u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3463u/* AppAccBytePosition */}, /*RSDS_MidTgt_02*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3464u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dx*/
  {7u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3466u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dy*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3467u/* AppAccBytePosition */}, /*RSDS_RiTgt_01*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3468u/* AppAccBytePosition */}, /*RSDS_FD2_0x30A*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3532u/* AppAccBytePosition */}, /*R_PBox1_0x19C*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3540u/* AppAccBytePosition */}, /*DrvSeatHeatSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3541u/* AppAccBytePosition */}, /*PassSeatHeatSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3542u/* AppAccBytePosition */}, /*DrvSeatVentnSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3543u/* AppAccBytePosition */}, /*PassSeatVentnSts*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 39u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3544u/* AppAccBytePosition */}, /*SCM1_0x2D1*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3560u/* AppAccBytePosition */}, /*STBS_SoundReq*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3561u/* AppAccBytePosition */}, /*DispTODReq_SC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3562u/* AppAccBytePosition */}, /*STBS1_0x21F*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3570u/* AppAccBytePosition */}, /*FLTirePressIndSts*/
  {3u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3571u/* AppAccBytePosition */}, /*FRTirePressIndSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3572u/* AppAccBytePosition */}, /*TirePressSysFailrIndcn*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3573u/* AppAccBytePosition */}, /*RLTirePressIndSts*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3574u/* AppAccBytePosition */}, /*RRTirePressIndSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3575u/* AppAccBytePosition */}, /*FLTireTempSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3576u/* AppAccBytePosition */}, /*FRTireTempSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3577u/* AppAccBytePosition */}, /*RLTireTempSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3578u/* AppAccBytePosition */}, /*RRTireTempSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3579u/* AppAccBytePosition */}, /*TPMS_AutoLoctSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3580u/* AppAccBytePosition */}, /*TPMS1_0x341*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3588u/* AppAccBytePosition */}, /*FLTirePress*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3589u/* AppAccBytePosition */}, /*FLTireTemp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3590u/* AppAccBytePosition */}, /*FRTirePress*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3591u/* AppAccBytePosition */}, /*FRTireTemp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3592u/* AppAccBytePosition */}, /*RLTirePress*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3593u/* AppAccBytePosition */}, /*RLTireTemp*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3594u/* AppAccBytePosition */}, /*RRTirePress*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3595u/* AppAccBytePosition */}, /*RRTireTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3596u/* AppAccBytePosition */}, /*TPMS2_0x395*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3604u/* AppAccBytePosition */}, /*T_BOX_RemtWinCtrl*/
  {2u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3605u/* AppAccBytePosition */}, /*T_BOX_RemtTrunkCtrl*/
  {3u/*BitLength*/, 5u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3606u/* AppAccBytePosition */}, /*T_BOX_RemtDoorLockCtrl*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3607u/* AppAccBytePosition */}, /*T_BOX_RemtAutoCtrl*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3608u/* AppAccBytePosition */}, /*T_BOX_RemtSrCtrl*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3609u/* AppAccBytePosition */}, /*T_BOX_RemtCarSearch*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3610u/* AppAccBytePosition */}, /*T_BOX_RemtDrvSeatHeatgLvlSet*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3611u/* AppAccBytePosition */}, /*T_BOX_RemtPassSeatHeatgLvlSet*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3612u/* AppAccBytePosition */}, /*T_BOX_RemtDrvTempSet*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3613u/* AppAccBytePosition */}, /*T_BOX_RemtPassTempSet*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3614u/* AppAccBytePosition */}, /*T_BOX_AudioMuteReq*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3615u/* AppAccBytePosition */}, /*T_BOX_RemtEngCtrl*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3616u/* AppAccBytePosition */}, /*T_BOX_RemtSsCtrl*/
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3617u/* AppAccBytePosition */}, /*T_BOX_RemtDrvSeatVentnLvlSet*/
  {3u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3618u/* AppAccBytePosition */}, /*T_BOX_RemtPassSeatVentnLvlSet*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3619u/* AppAccBytePosition */}, /*T_BOX_RemtAIUReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3620u/* AppAccBytePosition */}, /*T_BOX_FD1_0x33*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3628u/* AppAccBytePosition */}, /*T_BOX_SWUpdSts*/
  {5u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3629u/* AppAccBytePosition */}, /*T_BOX_SysErrSts*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3630u/* AppAccBytePosition */}, /*T_BOX_ChrgCmpltTime_hour*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3631u/* AppAccBytePosition */}, /*T_BOX_ChrgCmpltTime_minute*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3632u/* AppAccBytePosition */}, /*T_BOX_FD3_0x3E9*/
  {3u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3640u/* AppAccBytePosition */}, /*Tbox_BattSOCLim*/
  {3u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3641u/* AppAccBytePosition */}, /*Tbox_AvailInputCur*/
  {2u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3642u/* AppAccBytePosition */}, /*HUT_ChrgnReq*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3643u/* AppAccBytePosition */}, /*T_BOX_RefrInfo*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3644u/* AppAccBytePosition */}, /*T_BOX_wake*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3645u/* AppAccBytePosition */}, /*T_BOX_ChrgRemtCtrlCmd*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3646u/* AppAccBytePosition */}, /*T_BOX_RemtRearDefrostCtrl*/
  {11u/*BitLength*/, 13u/* BitPosition */, 2u/* ByteLength */, 1u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3647u/* AppAccBytePosition */}, /*Tbox_BMSReMtPreHeatT*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3649u/* AppAccBytePosition */}, /*Tbox_BMSReMtPreHeatReq*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3650u/* AppAccBytePosition */}, /*TBOX_RemtVideoMonrEnaReq_APP*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3651u/* AppAccBytePosition */}, /*T_BOX_RemtChrgnUnlockedCmd*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3652u/* AppAccBytePosition */}, /*T_BOX_RemtCockpitClnReq*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3653u/* AppAccBytePosition */}, /*TBOX_DelaySet*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3654u/* AppAccBytePosition */}, /*T_BOX_RemtFrntDefrostCtrl*/
  {2u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3655u/* AppAccBytePosition */}, /*RemUpgrdModeCmd*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3656u/* AppAccBytePosition */}, /*UVCAntiVirusReq*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3657u/* AppAccBytePosition */}, /*T_BOX_RemtSdlMod*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 39u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3658u/* AppAccBytePosition */}, /*T_BOX_FD4_0x1E1*/
  {2u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3674u/* AppAccBytePosition */}, /*Phone_ChrgnMode*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3675u/* AppAccBytePosition */}, /*Phone_ChrgnReq*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3676u/* AppAccBytePosition */}, /*T_BOX_DlyChargReq*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 39u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3677u/* AppAccBytePosition */}, /*T_BOX_FD5_0x2EE*/
  {11u/*BitLength*/, 85u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3693u/* AppAccBytePosition */}, /*Phone_StrtHourMin*/
  {11u/*BitLength*/, 90u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3695u/* AppAccBytePosition */}, /*Phone_EndHourMin*/
  {7u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3697u/* AppAccBytePosition */}, /*Phone_DelayTimMod*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3698u/* AppAccBytePosition */}, /*T_BOX_FD8_0x33E*/
  {2u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3762u/* AppAccBytePosition */}, /*SentinelMode*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3763u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Year_Right*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3764u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Year_Left*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 40u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3765u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Hour*/
  {6u/*BitLength*/, 45u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3766u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Minutes*/
  {6u/*BitLength*/, 55u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 16u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3767u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Second*/
  {4u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3768u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Month*/
  {5u/*BitLength*/, 62u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3769u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Day*/
  {2u/*BitLength*/, 58u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3770u/* AppAccBytePosition */}, /*MiaoCallOpenReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3771u/* AppAccBytePosition */}, /*T_BOX_FD9_0x1FE*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3779u/* AppAccBytePosition */}, /*V2X_FCW*/
  {4u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3780u/* AppAccBytePosition */}, /*V2X_BSW*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3781u/* AppAccBytePosition */}, /*V2X_LCW*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3782u/* AppAccBytePosition */}, /*V2X_EBW*/
  {4u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3783u/* AppAccBytePosition */}, /*V2X_ICW*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3784u/* AppAccBytePosition */}, /*V2X_LTA*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3785u/* AppAccBytePosition */}, /*V2X_IVSW*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3786u/* AppAccBytePosition */}, /*V2X_AVW*/
  {3u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3787u/* AppAccBytePosition */}, /*V2X_EVW*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3788u/* AppAccBytePosition */}, /*V2X_DNPW*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3789u/* AppAccBytePosition */}, /*V2X_HLW*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3790u/* AppAccBytePosition */}, /*V2X_TJW*/
  {6u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3791u/* AppAccBytePosition */}, /*V2X_CLW*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3792u/* AppAccBytePosition */}, /*V2X_RLVW*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3793u/* AppAccBytePosition */}, /*V2X_VRUCW*/
  {6u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3794u/* AppAccBytePosition */}, /*V2X_SLW*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3795u/* AppAccBytePosition */}, /*V2X_GLOSA*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3796u/* AppAccBytePosition */}, /*V2X_SL1_LightTyp*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3797u/* AppAccBytePosition */}, /*V2X_SL1_LightColor*/
  {16u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3798u/* AppAccBytePosition */}, /*V2X_SL1_LightTim*/
  {4u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3800u/* AppAccBytePosition */}, /*V2X_SL2_LightTyp*/
  {4u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3801u/* AppAccBytePosition */}, /*V2X_SL2_LightColor*/
  {16u/*BitLength*/, 144u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3802u/* AppAccBytePosition */}, /*V2X_SL2_LightTim*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3804u/* AppAccBytePosition */}, /*V2X_SL3_LightTyp*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3805u/* AppAccBytePosition */}, /*V2X_SL3_LightColor*/
  {16u/*BitLength*/, 168u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3806u/* AppAccBytePosition */}, /*V2X_SL3_LightTim*/
  {4u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3808u/* AppAccBytePosition */}, /*V2X_SL4_LightTyp*/
  {4u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3809u/* AppAccBytePosition */}, /*V2X_SL4_LightColor*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3810u/* AppAccBytePosition */}, /*V2X_SL5_LightTyp*/
  {16u/*BitLength*/, 208u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3811u/* AppAccBytePosition */}, /*V2X_SL4_LightTim*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3813u/* AppAccBytePosition */}, /*V2X_SL5_LightColor*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3814u/* AppAccBytePosition */}, /*V2X_SL5_LightTim*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3816u/* AppAccBytePosition */}, /*V2X_SL6_LightTyp*/
  {4u/*BitLength*/, 244u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3817u/* AppAccBytePosition */}, /*V2X_SL6_LightColor*/
  {16u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3818u/* AppAccBytePosition */}, /*V2X_SL6_LightTim*/
  {4u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3820u/* AppAccBytePosition */}, /*V2X_SL7_LightTyp*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3821u/* AppAccBytePosition */}, /*V2X_SL7_LightColor*/
  {16u/*BitLength*/, 288u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3822u/* AppAccBytePosition */}, /*V2X_SL7_LightTim*/
  {4u/*BitLength*/, 300u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3824u/* AppAccBytePosition */}, /*V2X_SL8_LightTyp*/
  {4u/*BitLength*/, 296u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3825u/* AppAccBytePosition */}, /*V2X_SL8_LightColor*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3826u/* AppAccBytePosition */}, /*V2X_SL8_LightTim*/
  {4u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3828u/* AppAccBytePosition */}, /*V2X_SL_of_Veh*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3829u/* AppAccBytePosition */}, /*T_BOX_FD10_0x2F0*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3893u/* AppAccBytePosition */}, /*VCU_ACLineCnctSts*/
  {10u/*BitLength*/, 22u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3894u/* AppAccBytePosition */}, /*VCU_InstantEgyCns*/
  {10u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3896u/* AppAccBytePosition */}, /*VCU_AvrgEgyCns*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3898u/* AppAccBytePosition */}, /*CheckSum_VCU5*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3899u/* AppAccBytePosition */}, /*VCU_AuthPassed*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3900u/* AppAccBytePosition */}, /*VCU_ParkFltLmp*/
  {3u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3901u/* AppAccBytePosition */}, /*VCU_FltLvl*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3902u/* AppAccBytePosition */}, /*RollingCounter_VCU5*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3903u/* AppAccBytePosition */}, /*VCU5_0x31B*/
  {11u/*BitLength*/, 221u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3911u/* AppAccBytePosition */}, /*VCU_CrsSpd*/
  {2u/*BitLength*/, 230u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3913u/* AppAccBytePosition */}, /*VCU_CrsCtrlSts*/
  {2u/*BitLength*/, 254u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3914u/* AppAccBytePosition */}, /*VCU_RaceLaunchSts*/
  {2u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3915u/* AppAccBytePosition */}, /*VCU_RaceLaunchAvlSts*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3916u/* AppAccBytePosition */}, /*VCU_BrkPedlSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3917u/* AppAccBytePosition */}, /*VCU_FD1_0xB5*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3981u/* AppAccBytePosition */}, /*VCU_GearSts*/
  {3u/*BitLength*/, 99u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3982u/* AppAccBytePosition */}, /*VCU_OPDSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3983u/* AppAccBytePosition */}, /*VCU_ECOACLimnSts*/
  {3u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3984u/* AppAccBytePosition */}, /*VCU_EgyFlowIndcr*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3985u/* AppAccBytePosition */}, /*EgyRgnLvl*/
  {4u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3986u/* AppAccBytePosition */}, /*VCU_DrvMod*/
  {8u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3987u/* AppAccBytePosition */}, /*VCU_CurrVehSpdLim*/
  {2u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3988u/* AppAccBytePosition */}, /*VCU_CrpSts*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3989u/* AppAccBytePosition */}, /*VCU_GearStsIP*/
  {7u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3990u/* AppAccBytePosition */}, /*VCU_CurrRcprtnInten*/
  {7u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3991u/* AppAccBytePosition */}, /*VCU_CurrAccelPedalSnvty*/
  {5u/*BitLength*/, 89u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3992u/* AppAccBytePosition */}, /*VCU_WordDispInfo*/
  {9u/*BitLength*/, 231u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3993u/* AppAccBytePosition */}, /*VCU_DTCNr3*/
  {1u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3995u/* AppAccBytePosition */}, /*VCU_GearStsVld*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3996u/* AppAccBytePosition */}, /*VCU_FD3_0x219*/
  {1u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4060u/* AppAccBytePosition */}, /*VCU_CoolgCircFlt*/
  {8u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4061u/* AppAccBytePosition */}, /*VCU_BattU*/
  {5u/*BitLength*/, 177u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4062u/* AppAccBytePosition */}, /*VCU_VCUSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4063u/* AppAccBytePosition */}, /*VCU_RdyLEDSts*/
  {3u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4064u/* AppAccBytePosition */}, /*VCU_ChrgnSts*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4065u/* AppAccBytePosition */}, /*VCU_ResrDrvRng*/
  {1u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4067u/* AppAccBytePosition */}, /*VCU_HUTBattKeepTempSet*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4068u/* AppAccBytePosition */}, /*VCU_DTCNr*/
  {9u/*BitLength*/, 286u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4070u/* AppAccBytePosition */}, /*VCU_DTCNr2*/
  {1u/*BitLength*/, 99u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4072u/* AppAccBytePosition */}, /*VCU_PwrLo*/
  {2u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4073u/* AppAccBytePosition */}, /*VCU_SysFltLmp*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4074u/* AppAccBytePosition */}, /*VCU_GModeSts*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4075u/* AppAccBytePosition */}, /*VCU_GModeFail*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4076u/* AppAccBytePosition */}, /*CheckSum_VCU3*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4077u/* AppAccBytePosition */}, /*RollingCounter_VCU3*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 4078u/* AppAccBytePosition */}, /*VCU_FD4_0x2D6*/
  {8u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4142u/* AppAccBytePosition */}, /*VCU_BrkPedlSts_RM*/
  {1u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4143u/* AppAccBytePosition */}, /*VCU_DrvPower_RM*/
  {7u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4144u/* AppAccBytePosition */}, /*VCU_ActAccrPedlRat_RM*/
  {1u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4145u/* AppAccBytePosition */}, /*VCU_BrkPower_RM*/
  {2u/*BitLength*/, 225u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4146u/* AppAccBytePosition */}, /*VCU_RdyLEDSts_RM*/
  {1u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4147u/* AppAccBytePosition */}, /*VCU_HiVoltInterlockSts_RM*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4148u/* AppAccBytePosition */}, /*VCU_GearSts_RM*/
  {7u/*BitLength*/, 265u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4149u/* AppAccBytePosition */}, /*VCU_TotalScore*/
  {7u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4150u/* AppAccBytePosition */}, /*VCU_AccelTimes*/
  {7u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4151u/* AppAccBytePosition */}, /*VCU_DecelTimes*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4152u/* AppAccBytePosition */}, /*VCU_DrvScoDst*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4154u/* AppAccBytePosition */}, /*VCU_MCUActHvCurr_RM*/
  {16u/*BitLength*/, 352u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4156u/* AppAccBytePosition */}, /*VCU_MCUActHvVolt_RM*/
  {4u/*BitLength*/, 106u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4158u/* AppAccBytePosition */}, /*VCU_ECODrvHabit_Indcn*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4159u/* AppAccBytePosition */}, /*VCU_AGSFailrFlg*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 14u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 4160u/* AppAccBytePosition */}, /*VCU_FD5_0x3AD*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4224u/* AppAccBytePosition */}, /*MbrMonrEnaSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4225u/* AppAccBytePosition */}, /*VMDR_TmpMonFctnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4226u/* AppAccBytePosition */}, /*VMDR_InitAlarmDlySetSts*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4227u/* AppAccBytePosition */}, /*VMDR_FctnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 4228u/* AppAccBytePosition */}, /*VMDR1_0x2FB*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4236u/* AppAccBytePosition */}, /*MbrMonrAlarmReq*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4237u/* AppAccBytePosition */}, /*ReleAlarmSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 4238u/* AppAccBytePosition */}, /*VMDR2_0x1E8*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4246u/* AppAccBytePosition */}, /*WPC_ChrgSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4247u/* AppAccBytePosition */}, /*WPC_SwtSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4248u/* AppAccBytePosition */}, /*WPC_FaultSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4249u/* AppAccBytePosition */}, /*WPC_PhoneReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 4250u/* AppAccBytePosition */}, /*WPC1_0x2BA*/
};


const ComEx_RxGroupInfoType ComEx_RxGroupInfo[ComEx_RxGroupSize] = 
{
  {0u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*ABM1*/
  {10u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 1u/* E2eIdx */}, /*ACC3_ACC_FD2*/
  {10u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 2u/* E2eIdx */}, /*ACC4_ACC_FD2*/
  {10u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 3u/* E2eIdx */}, /*ACC8_ACC_FD2*/
  {10u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 4u/* E2eIdx */}, /*ACC6_ACC_FD2*/
  {10u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 5u/* E2eIdx */}, /*ACC7_ACC_FD2*/
  {14u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 6u/* E2eIdx */}, /*AEB2_AEB_FD2*/
  {14u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 7u/* E2eIdx */}, /*AEB3_AEB_FD2*/
  {30u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 8u/* E2eIdx */}, /*BMS_FD10*/
  {37u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* E2eIdx */}, /*DCDC_FD1*/
  {44u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 10u/* E2eIdx */}, /*EPB1*/
  {45u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 11u/* E2eIdx */}, /*EPS_FD1*/
  {49u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 12u/* E2eIdx */}, /*ESP1_ESP_FD2*/
  {49u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 13u/* E2eIdx */}, /*ABS3_ESP_FD2*/
  {51u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 14u/* E2eIdx */}, /*E_Park1*/
  {53u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 15u/* E2eIdx */}, /*GW_FD1*/
  {62u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 16u/* E2eIdx */}, /*IFC3_IFC_FD2*/
  {62u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 17u/* E2eIdx */}, /*IFC4_IFC_FD2*/
  {62u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 18u/* E2eIdx */}, /*IFC5_IFC_FD2*/
  {62u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 19u/* E2eIdx */}, /*IFC6_IFC_FD2*/
  {91u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* E2eIdx */}, /*VCU5*/
  {94u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 21u/* E2eIdx */}, /*VCU_FD4*/
};


const ComEx_RxPduInfoType ComEx_RxPduInfo[ComEx_RxPduSize] = 
{
  {0u/* SignalStartIdx */, 15u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABM1*/
  {15u/* SignalStartIdx */, 22u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABM2*/
  {22u/* SignalStartIdx */, 27u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 16u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS1*/
  {27u/* SignalStartIdx */, 32u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 24u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS2*/
  {32u/* SignalStartIdx */, 43u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 32u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC1*/
  {43u/* SignalStartIdx */, 55u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 40u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC2*/
  {55u/* SignalStartIdx */, 60u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 48u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC4*/
  {60u/* SignalStartIdx */, 62u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 56u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC5*/
  {62u/* SignalStartIdx */, 66u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 64u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC6*/
  {66u/* SignalStartIdx */, 73u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC7*/
  {73u/* SignalStartIdx */, 158u/* SignalEndIdx */, 1u/* GroupStartIdx */, 6u/* GroupEndIdx */, 80u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ACC_FD2*/
  {158u/* SignalStartIdx */, 191u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD3*/
  {191u/* SignalStartIdx */, 260u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD4*/
  {260u/* SignalStartIdx */, 272u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AEB_FD1*/
  {272u/* SignalStartIdx */, 307u/* SignalEndIdx */, 6u/* GroupStartIdx */, 8u/* GroupEndIdx */, 328u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AEB_FD2*/
  {307u/* SignalStartIdx */, 309u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ALCM1*/
  {309u/* SignalStartIdx */, 325u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP1*/
  {325u/* SignalStartIdx */, 345u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AMP2*/
  {345u/* SignalStartIdx */, 352u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP3*/
  {352u/* SignalStartIdx */, 358u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP4_ANC1*/
  {358u/* SignalStartIdx */, 360u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP5_IESS1*/
  {360u/* SignalStartIdx */, 386u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM1*/
  {386u/* SignalStartIdx */, 392u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM3*/
  {392u/* SignalStartIdx */, 399u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM8*/
  {399u/* SignalStartIdx */, 412u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM9*/
  {412u/* SignalStartIdx */, 431u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM10*/
  {431u/* SignalStartIdx */, 438u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 472u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM12*/
  {438u/* SignalStartIdx */, 441u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM17*/
  {441u/* SignalStartIdx */, 446u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 488u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM19*/
  {446u/* SignalStartIdx */, 458u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 496u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS_FD1*/
  {458u/* SignalStartIdx */, 490u/* SignalEndIdx */, 8u/* GroupStartIdx */, 9u/* GroupEndIdx */, 560u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS_FD10*/
  {490u/* SignalStartIdx */, 493u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 624u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS_FD11*/
  {493u/* SignalStartIdx */, 501u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 632u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CR_FD1*/
  {501u/* SignalStartIdx */, 504u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA1*/
  {504u/* SignalStartIdx */, 511u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA2*/
  {511u/* SignalStartIdx */, 532u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 712u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA3*/
  {532u/* SignalStartIdx */, 536u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 720u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCDC2*/
  {536u/* SignalStartIdx */, 541u/* SignalEndIdx */, 9u/* GroupStartIdx */, 10u/* GroupEndIdx */, 728u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCDC_FD1*/
  {541u/* SignalStartIdx */, 553u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 792u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM1*/
  {553u/* SignalStartIdx */, 555u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 800u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DOCK1*/
  {555u/* SignalStartIdx */, 557u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 864u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DOCK2*/
  {557u/* SignalStartIdx */, 561u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 928u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSC4*/
  {561u/* SignalStartIdx */, 566u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 936u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSM1*/
  {566u/* SignalStartIdx */, 572u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 944u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EEM1*/
  {572u/* SignalStartIdx */, 581u/* SignalEndIdx */, 10u/* GroupStartIdx */, 11u/* GroupEndIdx */, 952u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPB1*/
  {581u/* SignalStartIdx */, 587u/* SignalEndIdx */, 11u/* GroupStartIdx */, 12u/* GroupEndIdx */, 960u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPS_FD1*/
  {587u/* SignalStartIdx */, 590u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1024u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESCL2*/
  {590u/* SignalStartIdx */, 592u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1032u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP10*/
  {592u/* SignalStartIdx */, 594u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1040u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP11*/
  {594u/* SignalStartIdx */, 620u/* SignalEndIdx */, 12u/* GroupStartIdx */, 14u/* GroupEndIdx */, 1048u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP_FD2*/
  {620u/* SignalStartIdx */, 622u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1104u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EVCC1*/
  {622u/* SignalStartIdx */, 629u/* SignalEndIdx */, 14u/* GroupStartIdx */, 15u/* GroupEndIdx */, 1112u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*E_Park1*/
  {629u/* SignalStartIdx */, 632u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1120u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW1*/
  {632u/* SignalStartIdx */, 678u/* SignalEndIdx */, 15u/* GroupStartIdx */, 16u/* GroupEndIdx */, 1128u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_FD1*/
  {678u/* SignalStartIdx */, 681u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1192u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_OTA*/
  {681u/* SignalStartIdx */, 684u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1200u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 2/* CalloutStartIdx */}, /*GW_Sync_Req*/
  {684u/* SignalStartIdx */, 717u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1216u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD1*/
  {717u/* SignalStartIdx */, 742u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1280u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD2*/
  {742u/* SignalStartIdx */, 801u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1344u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD3*/
  {801u/* SignalStartIdx */, 831u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1408u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD6*/
  {831u/* SignalStartIdx */, 834u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1472u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD7*/
  {834u/* SignalStartIdx */, 837u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1536u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD1*/
  {837u/* SignalStartIdx */, 886u/* SignalEndIdx */, 16u/* GroupStartIdx */, 20u/* GroupEndIdx */, 1600u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*IFC_FD2*/
  {886u/* SignalStartIdx */, 927u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1656u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD3*/
  {927u/* SignalStartIdx */, 952u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1720u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD5*/
  {952u/* SignalStartIdx */, 971u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1784u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD6*/
  {971u/* SignalStartIdx */, 973u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1848u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Ibooster_FD2*/
  {973u/* SignalStartIdx */, 990u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1912u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*MCU_FD1*/
  {990u/* SignalStartIdx */, 998u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1976u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*MCU_FD2*/
  {998u/* SignalStartIdx */, 1001u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2040u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*OBC11*/
  {1001u/* SignalStartIdx */, 1005u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2048u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*OBC12*/
  {1005u/* SignalStartIdx */, 1008u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2056u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*OBC_FD2*/
  {1008u/* SignalStartIdx */, 1018u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2064u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PDCM1*/
  {1018u/* SignalStartIdx */, 1021u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2072u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS1*/
  {1021u/* SignalStartIdx */, 1027u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2080u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS2*/
  {1027u/* SignalStartIdx */, 1034u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2088u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS4*/
  {1034u/* SignalStartIdx */, 1039u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2096u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PLG_1*/
  {1039u/* SignalStartIdx */, 1060u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2104u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD1*/
  {1060u/* SignalStartIdx */, 1083u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2168u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD2*/
  {1083u/* SignalStartIdx */, 1084u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2232u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*R_PBox1*/
  {1084u/* SignalStartIdx */, 1089u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2240u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*SCM1*/
  {1089u/* SignalStartIdx */, 1092u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2256u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*STBS1*/
  {1092u/* SignalStartIdx */, 1103u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2264u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS1*/
  {1103u/* SignalStartIdx */, 1112u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2272u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS2*/
  {1112u/* SignalStartIdx */, 1129u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2280u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD1*/
  {1129u/* SignalStartIdx */, 1134u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2288u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD3*/
  {1134u/* SignalStartIdx */, 1152u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2296u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD4*/
  {1152u/* SignalStartIdx */, 1156u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2312u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD5*/
  {1156u/* SignalStartIdx */, 1160u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2328u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD8*/
  {1160u/* SignalStartIdx */, 1170u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD9*/
  {1170u/* SignalStartIdx */, 1213u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2400u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD10*/
  {1213u/* SignalStartIdx */, 1222u/* SignalEndIdx */, 20u/* GroupStartIdx */, 21u/* GroupEndIdx */, 2464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VCU5*/
  {1222u/* SignalStartIdx */, 1228u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2472u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VCU_FD1*/
  {1228u/* SignalStartIdx */, 1243u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2536u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VCU_FD3*/
  {1243u/* SignalStartIdx */, 1259u/* SignalEndIdx */, 21u/* GroupStartIdx */, 22u/* GroupEndIdx */, 2600u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VCU_FD4*/
  {1259u/* SignalStartIdx */, 1275u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2664u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VCU_FD5*/
  {1275u/* SignalStartIdx */, 1280u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2728u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VMDR1*/
  {1280u/* SignalStartIdx */, 1283u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2736u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VMDR2*/
  {1283u/* SignalStartIdx */, 1288u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2744u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*WPC1*/
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
  {1u/* byteLength */, 21u/* bytePosition */},
  {1u/* byteLength */, 22u/* bytePosition */},
  {56u/* byteLength */, 23u/* bytePosition */},
  {64u/* byteLength */, 79u/* bytePosition */},
  {2u/* byteLength */, 143u/* bytePosition */},
  {1u/* byteLength */, 145u/* bytePosition */},
  {1u/* byteLength */, 146u/* bytePosition */},
  {1u/* byteLength */, 147u/* bytePosition */},
  {1u/* byteLength */, 148u/* bytePosition */},
  {1u/* byteLength */, 149u/* bytePosition */},
  {2u/* byteLength */, 150u/* bytePosition */},
  {1u/* byteLength */, 152u/* bytePosition */},
  {2u/* byteLength */, 153u/* bytePosition */},
  {2u/* byteLength */, 155u/* bytePosition */},
  {11u/* byteLength */, 157u/* bytePosition */},
  {4u/* byteLength */, 168u/* bytePosition */},
  {2u/* byteLength */, 172u/* bytePosition */},
  {2u/* byteLength */, 174u/* bytePosition */},
  {2u/* byteLength */, 176u/* bytePosition */},
  {2u/* byteLength */, 178u/* bytePosition */},
  {2u/* byteLength */, 180u/* bytePosition */},
  {2u/* byteLength */, 182u/* bytePosition */},
  {4u/* byteLength */, 184u/* bytePosition */},
  {2u/* byteLength */, 188u/* bytePosition */},
  {2u/* byteLength */, 190u/* bytePosition */},
  {2u/* byteLength */, 192u/* bytePosition */},
  {2u/* byteLength */, 194u/* bytePosition */},
  {2u/* byteLength */, 196u/* bytePosition */},
  {16u/* byteLength */, 198u/* bytePosition */},
  {1u/* byteLength */, 214u/* bytePosition */},
  {1u/* byteLength */, 215u/* bytePosition */},
};

const ComEx_RxSigTimeoutInfoType ComEx_RxSigTimeoutInfo[ComEx_RxTimeoutSize] = 
{
  {65535u/* byteLength */, 65535u/* bytePosition */, 1000u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 40u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 200u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 100u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 20u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 400u/* TimeoutMax */},
  {65535u/* byteLength */, 65535u/* bytePosition */, 2000u/* TimeoutMax */},
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
  {E2EPW_ReadInit_BMS_FD10_E2E/* InitFunPtr */, E2EPW_Read_BMS_FD10_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_DCDC_FD1_E2E/* InitFunPtr */, E2EPW_Read_DCDC_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPB1_E2E/* InitFunPtr */, E2EPW_Read_EPB1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPS_FD1_E2E/* InitFunPtr */, E2EPW_Read_EPS_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP1_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ESP1_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ABS3_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ABS3_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_E_Park1_E2E/* InitFunPtr */, E2EPW_Read_E_Park1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_GW_FD1_E2E/* InitFunPtr */, E2EPW_Read_GW_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC3_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC3_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC4_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC4_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC5_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC5_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_IFC6_IFC_FD2_E2E/* InitFunPtr */, E2EPW_Read_IFC6_IFC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_VCU5_E2E/* InitFunPtr */, E2EPW_Read_VCU5_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_VCU_FD4_E2E/* InitFunPtr */, E2EPW_Read_VCU_FD4_E2E/* ReadFunPtr */},
};

const uint8 ComEx_RxInitValueBuffer[ComEx_RxInitValueBufferSize] =
{
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x11u,
  0x22u,
  0x11u,
  0x56u,
  0x0u,
  0x0u,
  0xfeu,
  0x7u,
  0xfu,
  0x21u,
  0x3u,
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
  0x10u,
  0x27u,
  0x5au,
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0x3u,
  0x1u,
  0x1cu,
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
  0x20u,
  0x4eu,
  0xe8u,
  0x3u,
  0x2cu,
  0x1u,
  0xc8u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x1fu,
  0x96u,
};

const uint8 ComEx_RxTimeoutBuffer[ComEx_RxTimeoutBufferSize] = 
{0
};

const uint8 ComEx_RxPduCalloutIdx[4] =
{
    0u, 2u, 1u, 2u
};

const ComEx_TxSigInfoType ComEx_TxSigInfo[ComEx_TxSignalSize]= 
{
  {3u/*BitLength*/, 93u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvl_ACC*/
  {7u/*BitLength*/, 73u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 17u/* BufferStartIdx */, 18u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvlQlty_ACC*/
  {3u/*BitLength*/, 90u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvl_ACC*/
  {7u/*BitLength*/, 81u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 18u/* BufferStartIdx */, 19u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvlQlty_ACC*/
  {11u/*BitLength*/, 149u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 25u/* BufferStartIdx */, 27u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnX*/
  {11u/*BitLength*/, 154u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 26u/* BufferStartIdx */, 28u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnY*/
  {11u/*BitLength*/, 175u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 27u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnZ*/
  {7u/*BitLength*/, 168u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 29u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosQlty*/
  {11u/*BitLength*/, 213u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 33u/* BufferStartIdx */, 35u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnX*/
  {11u/*BitLength*/, 218u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 34u/* BufferStartIdx */, 36u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnY*/
  {11u/*BitLength*/, 239u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 35u/* BufferStartIdx */, 38u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnZ*/
  {3u/*BitLength*/, 301u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 45u/* BufferStartIdx */, 46u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMSSts*/
  {1u/*BitLength*/, 288u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadDetn*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 41u/* BufferStartIdx */, 42u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadYawAng*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 42u/* BufferStartIdx */, 43u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPitchAng*/
  {8u/*BitLength*/, 280u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 43u/* BufferStartIdx */, 44u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRollAng*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRotAngQlty*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenSts*/
  {7u/*BitLength*/, 345u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 51u/* BufferStartIdx */, 52u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenStsQlty*/
  {2u/*BitLength*/, 372u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenSts*/
  {7u/*BitLength*/, 353u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 52u/* BufferStartIdx */, 53u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenStsQlty*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 49u/* BufferStartIdx */, 50u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeYawAng*/
  {8u/*BitLength*/, 336u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 50u/* BufferStartIdx */, 51u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazePitchAng*/
  {7u/*BitLength*/, 361u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 53u/* BufferStartIdx */, 54u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeAngQlty*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 16u/* BufferStartIdx */, 17u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS2*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 23u/* BufferStartIdx */, 24u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 24u/* BufferStartIdx */, 25u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS3*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 31u/* BufferStartIdx */, 32u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS3*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 40u/* BufferStartIdx */, 41u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS5*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 47u/* BufferStartIdx */, 48u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS5*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 48u/* BufferStartIdx */, 49u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS6*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 55u/* BufferStartIdx */, 56u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS6*/
  {2u/*BitLength*/, 96u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 20u/* BufferStartIdx */, 21u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OMSAlarmReq*/
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExprsnSts*/
  {3u/*BitLength*/, 368u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvBehvSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 1u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 8u/* BufferStartIdx */, 72u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMS_FD1_0x24D*/
  {3u/*BitLength*/, 26u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 75u/* BufferStartIdx */, 76u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRRemtCnSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_360VideoCaptureReq*/
  {512u/*BitLength*/, 0u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 72u/* BufferStartIdx */, 136u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_FD1_0x2EC*/
  {3u/*BitLength*/, 5u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DomeLmpDlyTimSet*/
  {3u/*BitLength*/, 1u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FolwMeHomeDlyTimSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*TranPMode_Req*/
  {1u/*BitLength*/, 14u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearviewFoldModSet*/
  {2u/*BitLength*/, 12u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BattSaveDelayTimeSet*/
  {2u/*BitLength*/, 20u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_TC*/
  {2u/*BitLength*/, 18u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_TC*/
  {2u/*BitLength*/, 16u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_TC*/
  {2u/*BitLength*/, 28u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACCmprReq_TC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntDefrstReq_TC*/
  {2u/*BitLength*/, 24u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntBlwrSpdDecReq_TC*/
  {1u/*BitLength*/, 36u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 140u/* BufferStartIdx */, 141u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDrowsnsDetnSet*/
  {2u/*BitLength*/, 46u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntBlwrSpdIncReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvAirDistribModReq_TC*/
  {2u/*BitLength*/, 41u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempDecReq_TC*/
  {1u/*BitLength*/, 40u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 141u/* BufferStartIdx */, 142u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnEna*/
  {2u/*BitLength*/, 54u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempIncReq_TC*/
  {2u/*BitLength*/, 52u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntPassTempDecReq_TC*/
  {2u/*BitLength*/, 50u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntPassTempIncReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOffReq_TC*/
  {4u/*BitLength*/, 56u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrsteplsSpdReq_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_TC*/
  {1u/*BitLength*/, 48u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_TC*/
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
  {1u/*BitLength*/, 50u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 150u/* BufferStartIdx */, 151u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*T_BOX_ECallSet*/
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
  {2u/*BitLength*/, 14u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgLvlSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatHeatgLvlSet*/
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
  {2u/*BitLength*/, 8u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet*/
  {2u/*BitLength*/, 3u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvMassgCmd*/
  {1u/*BitLength*/, 56u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RemUpgrdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 6u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT4_0x36D*/
  {1u/*BitLength*/, 60u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FPAS_AutoModSwt*/
  {1u/*BitLength*/, 61u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MEBSwtSet*/
  {2u/*BitLength*/, 5u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_TC*/
  {2u/*BitLength*/, 3u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_VR*/
  {2u/*BitLength*/, 0u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 169u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VCUBattKeepTemp*/
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
  {1u/*BitLength*/, 56u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WshSoftSwt*/
  {1u/*BitLength*/, 59u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*View_SoftswitchCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 7u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT6_0x4A*/
  {2u/*BitLength*/, 6u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRTmpMonFctnSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRInitAlarmDlySet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 180u/* BufferStartIdx */, 181u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OTA_UpgrdModReq*/
  {2u/*BitLength*/, 38u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 180u/* BufferStartIdx */, 181u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChildLockCmd*/
  {2u/*BitLength*/, 53u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 182u/* BufferStartIdx */, 183u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MiaoCallClsReq*/
  {2u/*BitLength*/, 60u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 183u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairRestSetSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT7_0x44*/
  {2u/*BitLength*/, 40u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearDefrstReq_VR*/
  {2u/*BitLength*/, 4u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 185u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EgyRecvrySet*/
  {4u/*BitLength*/, 12u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ECODrvModReq*/
  {8u/*BitLength*/, 16u/* BitPosition */, 9u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 186u/* BufferStartIdx */, 187u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ECOSpdLim*/
  {2u/*BitLength*/, 0u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 185u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ECOACLimnSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASSwtReq_VR*/
  {1u/*BitLength*/, 25u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ImdChrgSet*/
  {2u/*BitLength*/, 28u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MeditationModReq*/
  {1u/*BitLength*/, 24u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt*/
  {1u/*BitLength*/, 47u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt*/
  {1u/*BitLength*/, 46u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynSwt*/
  {6u/*BitLength*/, 32u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 188u/* BufferStartIdx */, 189u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet*/
  {2u/*BitLength*/, 10u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_VR*/
  {6u/*BitLength*/, 58u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IPVolSet*/
  {2u/*BitLength*/, 8u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_VR*/
  {2u/*BitLength*/, 56u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_VR*/
  {64u/*BitLength*/, 0u/* BitPosition */, 9u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT10_0x331*/
  {2u/*BitLength*/, 14u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 193u/* BufferStartIdx */, 194u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AudioMuteSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 193u/* BufferStartIdx */, 194u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OrvmPosnEnaSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 194u/* BufferStartIdx */, 195u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavIdentifyTurnReq*/
  {4u/*BitLength*/, 24u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 195u/* BufferStartIdx */, 196u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvSeatAdjmt_HUT*/
  {8u/*BitLength*/, 40u/* BitPosition */, 10u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 197u/* BufferStartIdx */, 198u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_VehSpdLimAdj*/
  {2u/*BitLength*/, 22u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 194u/* BufferStartIdx */, 195u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ORVMFoldSwt_HUT*/
  {4u/*BitLength*/, 28u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 195u/* BufferStartIdx */, 196u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ORVMLensAdjmt_HUT*/
  {1u/*BitLength*/, 53u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_AVHSwitchSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EPB_SwtPosn*/
  {2u/*BitLength*/, 48u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AVMAutoSet*/
  {1u/*BitLength*/, 52u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HDCSwitchCtrl*/
  {64u/*BitLength*/, 0u/* BitPosition */, 10u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 192u/* BufferStartIdx */, 200u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT13_0x31C*/
  {2u/*BitLength*/, 6u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_VR*/
  {6u/*BitLength*/, 18u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_TC*/
  {1u/*BitLength*/, 39u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SDWSwtSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSSwtReq_VR*/
  {4u/*BitLength*/, 40u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 205u/* BufferStartIdx */, 206u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunShadeSwtReq_VR*/
  {4u/*BitLength*/, 44u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 205u/* BufferStartIdx */, 206u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunRoofSwtReq_VR*/
  {2u/*BitLength*/, 0u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SportModLightSet*/
  {1u/*BitLength*/, 14u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ABSLmpSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoWshWipSet*/
  {2u/*BitLength*/, 9u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeekVehSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SpdAutoLockModSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkLmpSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DoorUnlockModSet*/
  {1u/*BitLength*/, 32u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACEAHReq_TC*/
  {2u/*BitLength*/, 37u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACEAHReq_VR*/
  {2u/*BitLength*/, 33u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSPrkgTypSeln*/
  {2u/*BitLength*/, 52u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASExitSpdSwt*/
  {2u/*BitLength*/, 50u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*VehStsChngReq*/
  {2u/*BitLength*/, 2u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SteerWheelHeatSwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 11u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT15_0x1EE*/
  {1u/*BitLength*/, 39u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PowerSet*/
  {2u/*BitLength*/, 60u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 215u/* BufferStartIdx */, 216u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SentinelModests*/
  {16u/*BitLength*/, 48u/* BitPosition */, 12u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 213u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ModeAlarm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 12u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 216u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT16_0x348*/
  {2u/*BitLength*/, 52u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 222u/* BufferStartIdx */, 223u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OPDSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WPC_SwtReq*/
  {4u/*BitLength*/, 36u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackgroundLightLvlSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 222u/* BufferStartIdx */, 223u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PLGReq_VR*/
  {1u/*BitLength*/, 19u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AVMSwtReq*/
  {4u/*BitLength*/, 28u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 219u/* BufferStartIdx */, 220u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviMediaVolLvlReq*/
  {4u/*BitLength*/, 24u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 219u/* BufferStartIdx */, 220u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AVMMediaVolLvlReq*/
  {1u/*BitLength*/, 18u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FPASChanSwtReq*/
  {1u/*BitLength*/, 17u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RPASChanSwtReq*/
  {2u/*BitLength*/, 50u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 222u/* BufferStartIdx */, 223u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_V2VStart*/
  {4u/*BitLength*/, 32u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ManCmpSet*/
  {2u/*BitLength*/, 46u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 221u/* BufferStartIdx */, 222u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DispModSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 13u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 224u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT17_0x33B*/
  {3u/*BitLength*/, 5u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 225u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MsgTyp*/
  {3u/*BitLength*/, 2u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 225u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapProvider*/
  {10u/*BitLength*/, 8u/* BitPosition */, 14u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 226u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CountryCode*/
  {2u/*BitLength*/, 22u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CycCnt*/
  {2u/*BitLength*/, 20u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Major*/
  {3u/*BitLength*/, 17u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_MinorSub*/
  {9u/*BitLength*/, 24u/* BitPosition */, 14u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_HwVer*/
  {1u/*BitLength*/, 39u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 228u/* BufferStartIdx */, 229u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_DrvSide*/
  {15u/*BitLength*/, 40u/* BitPosition */, 14u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 228u/* BufferStartIdx */, 230u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_RegionCode*/
  {2u/*BitLength*/, 54u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 230u/* BufferStartIdx */, 231u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerQtr*/
  {6u/*BitLength*/, 48u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 230u/* BufferStartIdx */, 231u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerYear*/
  {1u/*BitLength*/, 60u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 231u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_SpdUnits*/
  {4u/*BitLength*/, 56u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 231u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Minor*/
  {64u/*BitLength*/, 0u/* BitPosition */, 14u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT19_0x415*/
  {3u/*BitLength*/, 5u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 233u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 234u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Update*/
  {32u/*BitLength*/, 56u/* BitPosition */, 15u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 4u/* BusAccBtyeLength */, 236u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Value*/
  {64u/*BitLength*/, 0u/* BitPosition */, 15u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT20_0x2DE*/
  {3u/*BitLength*/, 5u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 241u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 242u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Update*/
  {2u/*BitLength*/, 38u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 244u/* BufferStartIdx */, 245u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_AccurClass*/
  {10u/*BitLength*/, 44u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 244u/* BufferStartIdx */, 246u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Dist1*/
  {10u/*BitLength*/, 50u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 245u/* BufferStartIdx */, 247u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value0*/
  {10u/*BitLength*/, 56u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 246u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 16u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT21_0x2DD*/
  {3u/*BitLength*/, 5u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 249u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 250u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PathIdx*/
  {2u/*BitLength*/, 30u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Tunnel*/
  {2u/*BitLength*/, 28u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Brdg*/
  {2u/*BitLength*/, 26u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_BuildUpArea*/
  {1u/*BitLength*/, 25u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 253u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 253u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FormOfWay*/
  {5u/*BitLength*/, 51u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 254u/* BufferStartIdx */, 255u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmt*/
  {3u/*BitLength*/, 48u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 254u/* BufferStartIdx */, 255u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmtTyp*/
  {2u/*BitLength*/, 61u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_DivideRoad*/
  {2u/*BitLength*/, 59u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 17u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT22_0x2DA*/
  {3u/*BitLength*/, 5u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 257u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 18u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 258u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 258u/* BufferStartIdx */, 259u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 258u/* BufferStartIdx */, 259u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PathIdx*/
  {6u/*BitLength*/, 26u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_StubPathIdx*/
  {1u/*BitLength*/, 25u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 260u/* BufferStartIdx */, 261u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 260u/* BufferStartIdx */, 261u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 262u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FormOfWay*/
  {8u/*BitLength*/, 48u/* BitPosition */, 18u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 262u/* BufferStartIdx */, 263u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_TurnAngl*/
  {1u/*BitLength*/, 63u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_LastStub*/
  {2u/*BitLength*/, 61u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RtOfWay*/
  {2u/*BitLength*/, 59u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 263u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 18u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT23_0x2D8*/
  {3u/*BitLength*/, 58u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_GModeSet*/
  {3u/*BitLength*/, 61u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 271u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BattSOCLim*/
  {2u/*BitLength*/, 26u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 267u/* BufferStartIdx */, 268u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_RemtEngCtrl*/
  {64u/*BitLength*/, 0u/* BitPosition */, 19u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 264u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT25_0x339*/
  {3u/*BitLength*/, 33u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 276u/* BufferStartIdx */, 277u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatSupportPosnSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 20u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 272u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT26_0x2B6*/
  {1u/*BitLength*/, 60u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 287u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Short_Time*/
  {64u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT28_0x2C0*/
  {1u/*BitLength*/, 13u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_AVM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT30_0x1E9*/
  {2u/*BitLength*/, 46u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 301u/* BufferStartIdx */, 302u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ScrnOpSts*/
  {11u/*BitLength*/, 29u/* BitPosition */, 23u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 298u/* BufferStartIdx */, 300u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*XLvl*/
  {11u/*BitLength*/, 32u/* BitPosition */, 23u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 299u/* BufferStartIdx */, 301u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*YLvl*/
  {1u/*BitLength*/, 9u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DetVideoLost*/
  {1u/*BitLength*/, 10u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkgCtrlModReqValid*/
  {2u/*BitLength*/, 12u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkgCtrlModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ContnPrkgReqValid*/
  {2u/*BitLength*/, 14u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ContnPrkgReq*/
  {1u/*BitLength*/, 54u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*P2P_PrkgDirSwtReq*/
  {4u/*BitLength*/, 56u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 303u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_HUT32*/
  {1u/*BitLength*/, 11u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSwtReq_HUT*/
  {2u/*BitLength*/, 27u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 299u/* BufferStartIdx */, 300u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSuspendOrFinishReq_HUT*/
  {3u/*BitLength*/, 61u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 303u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightModSel_HUT*/
  {1u/*BitLength*/, 60u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 303u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSts_HUT*/
  {1u/*BitLength*/, 45u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 301u/* BufferStartIdx */, 302u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightStrtReq_HUT*/
  {1u/*BitLength*/, 44u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 301u/* BufferStartIdx */, 302u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightVehStrtReq_HUT_Valid*/
  {1u/*BitLength*/, 55u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightContinueReq_HUT*/
  {8u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 297u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_HUT32*/
  {1u/*BitLength*/, 51u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RainMode_Swt_Req*/
  {2u/*BitLength*/, 49u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCMode_Swt_Req*/
  {64u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT32_0x26F*/
  {3u/*BitLength*/, 32u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 308u/* BufferStartIdx */, 309u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLWinSwtReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRWinSwtReq_VR*/
  {3u/*BitLength*/, 13u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvWinSwtReq_VR*/
  {3u/*BitLength*/, 35u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 308u/* BufferStartIdx */, 309u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassWinSwtReq_VR*/
  {3u/*BitLength*/, 8u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt*/
  {2u/*BitLength*/, 6u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApproachLampSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FlaoutUnlockSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkInDirChoice*/
  {1u/*BitLength*/, 17u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngFinshCmd*/
  {1u/*BitLength*/, 18u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngStartCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkOutDirReq*/
  {1u/*BitLength*/, 19u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkMdlCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_APS*/
  {1u/*BitLength*/, 25u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath2Cmd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath2Cmd*/
  {1u/*BitLength*/, 27u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath1Cmd*/
  {1u/*BitLength*/, 28u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath1Cmd*/
  {3u/*BitLength*/, 29u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkgFctnCmd*/
  {3u/*BitLength*/, 50u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet*/
  {2u/*BitLength*/, 46u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAEnaReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAChanTyp_TC*/
  {3u/*BitLength*/, 40u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 309u/* BufferStartIdx */, 310u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGALvlReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT33_0x1ED*/
  {1u/*BitLength*/, 16u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeMod*/
  {1u/*BitLength*/, 17u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeIndcn*/
  {5u/*BitLength*/, 11u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Hour*/
  {6u/*BitLength*/, 18u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Minutes*/
  {6u/*BitLength*/, 26u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Second*/
  {4u/*BitLength*/, 36u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 316u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Left*/
  {4u/*BitLength*/, 32u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 316u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Right*/
  {4u/*BitLength*/, 44u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Month*/
  {5u/*BitLength*/, 51u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Day*/
  {4u/*BitLength*/, 40u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AppModeFB*/
  {64u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT34_0x370*/
  {1u/*BitLength*/, 51u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEnterSet*/
  {1u/*BitLength*/, 50u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvLeaveSet*/
  {2u/*BitLength*/, 25u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_VR*/
  {2u/*BitLength*/, 17u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT35_0x1E5*/
  {3u/*BitLength*/, 45u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMFlashFreq*/
  {3u/*BitLength*/, 55u/* BitPosition */, 27u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 42u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMFlashFreq*/
  {3u/*BitLength*/, 52u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 61u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMFlashFreq*/
  {3u/*BitLength*/, 58u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMFlashFreq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 27u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT38_0x1E7*/
  {3u/*BitLength*/, 21u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgLvlSet*/
  {7u/*BitLength*/, 40u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMClrSet*/
  {7u/*BitLength*/, 57u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 343u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMClrSet*/
  {7u/*BitLength*/, 49u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 342u/* BufferStartIdx */, 343u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMClrSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT39_0x1EB*/
  {1u/*BitLength*/, 61u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 351u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMMasterSwt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 351u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMPartitionSwt*/
  {7u/*BitLength*/, 9u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 346u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq0*/
  {7u/*BitLength*/, 18u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq1*/
  {7u/*BitLength*/, 27u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq2*/
  {7u/*BitLength*/, 36u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq3*/
  {7u/*BitLength*/, 45u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 350u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq4*/
  {7u/*BitLength*/, 54u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 349u/* BufferStartIdx */, 351u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq5*/
  {7u/*BitLength*/, 63u/* BitPosition */, 29u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 350u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq6*/
  {64u/*BitLength*/, 0u/* BitPosition */, 29u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT40_0x224*/
  {4u/*BitLength*/, 48u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMLightLvlSet*/
  {7u/*BitLength*/, 1u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 353u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMClrSet*/
  {7u/*BitLength*/, 9u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMClrSet*/
  {7u/*BitLength*/, 17u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 354u/* BufferStartIdx */, 355u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMClrSet*/
  {4u/*BitLength*/, 36u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 44u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 32u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 40u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 52u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMLightLvlSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT41_0x1FB*/
  {2u/*BitLength*/, 6u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ChrgnMod*/
  {7u/*BitLength*/, 25u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_DelayTimMod*/
  {11u/*BitLength*/, 11u/* BitPosition */, 31u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 362u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_StrtHourMin*/
  {11u/*BitLength*/, 16u/* BitPosition */, 31u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 361u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EndHourMin*/
  {2u/*BitLength*/, 38u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_IndDrvgModReq*/
  {2u/*BitLength*/, 46u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 365u/* BufferStartIdx */, 366u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_CreepSwt*/
  {7u/*BitLength*/, 49u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 366u/* BufferStartIdx */, 367u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EneRecoInteAdj*/
  {7u/*BitLength*/, 57u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 367u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_AccelPedalSnvtyAdj*/
  {64u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT42_0x1F9*/
  {1u/*BitLength*/, 12u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PosnLmpSwtSts_HUT*/
  {1u/*BitLength*/, 10u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearFogLmpSwtSts_HUT*/
  {1u/*BitLength*/, 9u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LowBeamSwtSts_HUT*/
  {1u/*BitLength*/, 23u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AutoLmpSwtSts_HUT*/
  {64u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT44_0x127*/
  {4u/*BitLength*/, 12u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 377u/* BufferStartIdx */, 378u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgModSet*/
  {2u/*BitLength*/, 18u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_V2LStart*/
  {3u/*BitLength*/, 4u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PLG_HeightSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT45_0x1DC*/
  {1u/*BitLength*/, 64u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SSSSet_HUT*/
  {2u/*BitLength*/, 76u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 393u/* BufferStartIdx */, 394u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IFC_SnvtySet*/
  {1u/*BitLength*/, 104u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DOWSwtReq*/
  {1u/*BitLength*/, 105u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_PedSwtReq*/
  {1u/*BitLength*/, 86u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FlashLmpSwtReq*/
  {1u/*BitLength*/, 85u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCASwtReq*/
  {1u/*BitLength*/, 84u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTASwtReq*/
  {1u/*BitLength*/, 83u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTABrkSwtReq*/
  {1u/*BitLength*/, 82u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCWSwtReq*/
  {2u/*BitLength*/, 80u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCW_SnvtySet*/
  {1u/*BitLength*/, 95u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_VehSwtReq*/
  {1u/*BitLength*/, 93u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LKASwtReq*/
  {1u/*BitLength*/, 92u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCKSwtReq*/
  {1u/*BitLength*/, 91u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ELKSwtReq*/
  {1u/*BitLength*/, 90u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_PedSwtReq*/
  {1u/*BitLength*/, 89u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_VehSwtReq*/
  {1u/*BitLength*/, 88u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LDWSwtReq*/
  {1u/*BitLength*/, 102u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRSwtReq*/
  {1u/*BitLength*/, 101u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRWarnSwtReq*/
  {1u/*BitLength*/, 127u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ICA_HandsOffSwtReq*/
  {1u/*BitLength*/, 126u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ISLSwtReq*/
  {5u/*BitLength*/, 121u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSR_SnvtySet*/
  {2u/*BitLength*/, 113u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 398u/* BufferStartIdx */, 399u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EPSSteerModSwtReq*/
  {1u/*BitLength*/, 112u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 398u/* BufferStartIdx */, 399u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DSTSwtReq*/
  {1u/*BitLength*/, 98u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_ESPFuncOffSwtSts*/
  {4u/*BitLength*/, 108u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrivingModReq_HUT*/
  {2u/*BitLength*/, 243u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 414u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSet*/
  {4u/*BitLength*/, 252u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 415u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ChairMemPosnSetResult*/
  {1u/*BitLength*/, 224u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 412u/* BufferStartIdx */, 413u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TABSwtReq_HUT*/
  {4u/*BitLength*/, 308u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 422u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavRoadType*/
  {2u/*BitLength*/, 306u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 422u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimType*/
  {6u/*BitLength*/, 266u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 417u/* BufferStartIdx */, 418u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimValue*/
  {2u/*BitLength*/, 264u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 417u/* BufferStartIdx */, 418u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimUnit_HUT*/
  {10u/*BitLength*/, 286u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 418u/* BufferStartIdx */, 420u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavCtryType*/
  {3u/*BitLength*/, 283u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 419u/* BufferStartIdx */, 420u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimSignSts*/
  {8u/*BitLength*/, 288u/* BitPosition */, 34u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 420u/* BufferStartIdx */, 421u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavTSRTrafSign*/
  {1u/*BitLength*/, 299u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_JASwtReq*/
  {3u/*BitLength*/, 325u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 425u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_MsgTye*/
  {13u/*BitLength*/, 328u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Offset*/
  {2u/*BitLength*/, 342u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CycCnt*/
  {6u/*BitLength*/, 336u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Pathldx*/
  {2u/*BitLength*/, 350u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Idx*/
  {5u/*BitLength*/, 345u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosProbb*/
  {9u/*BitLength*/, 352u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 429u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Age*/
  {3u/*BitLength*/, 364u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosConfdc*/
  {3u/*BitLength*/, 361u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CurLane*/
  {9u/*BitLength*/, 368u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 431u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Spd*/
  {8u/*BitLength*/, 376u/* BitPosition */, 34u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 431u/* BufferStartIdx */, 432u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Rehead*/
  {2u/*BitLength*/, 99u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSWarnFormSwtReq*/
  {10u/*BitLength*/, 246u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 413u/* BufferStartIdx */, 415u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavVehToTrafEyeDist*/
  {1u/*BitLength*/, 106u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSSwtReq*/
  {1u/*BitLength*/, 107u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntelligentEvaSwtReq*/
  {1u/*BitLength*/, 298u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AESSwtReq*/
  {1u/*BitLength*/, 301u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTASwtReq*/
  {1u/*BitLength*/, 300u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTABrkSwtReq*/
  {1u/*BitLength*/, 280u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 419u/* BufferStartIdx */, 420u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SwtReq*/
  {2u/*BitLength*/, 302u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SnvtySet*/
  {1u/*BitLength*/, 296u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 422u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALC_SwtReq*/
  {3u/*BitLength*/, 66u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_GModeSts*/
  {12u/*BitLength*/, 148u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUTRadioFrq*/
  {1u/*BitLength*/, 87u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HFASwtSts*/
  {4u/*BitLength*/, 72u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 393u/* BufferStartIdx */, 394u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMLightLvlSet*/
  {448u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 56u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD1_0x2C3*/
  {4u/*BitLength*/, 12u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 441u/* BufferStartIdx */, 442u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 441u/* BufferStartIdx */, 442u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 449u/* BufferStartIdx */, 450u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HTU_OD_Obj1_ID*/
  {3u/*BitLength*/, 85u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_type*/
  {4u/*BitLength*/, 72u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 449u/* BufferStartIdx */, 450u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Confidence*/
  {7u/*BitLength*/, 94u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 452u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_width*/
  {12u/*BitLength*/, 108u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 112u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_ID*/
  {3u/*BitLength*/, 149u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 458u/* BufferStartIdx */, 459u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_type*/
  {4u/*BitLength*/, 136u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Confidence*/
  {7u/*BitLength*/, 158u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 458u/* BufferStartIdx */, 460u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_width*/
  {12u/*BitLength*/, 172u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 460u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 176u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_ID*/
  {3u/*BitLength*/, 213u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 467u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_type*/
  {4u/*BitLength*/, 200u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Confidence*/
  {7u/*BitLength*/, 222u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_width*/
  {12u/*BitLength*/, 236u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 468u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 240u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 471u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 268u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 473u/* BufferStartIdx */, 474u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_ID*/
  {3u/*BitLength*/, 277u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 475u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_type*/
  {4u/*BitLength*/, 264u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 473u/* BufferStartIdx */, 474u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Confidence*/
  {7u/*BitLength*/, 286u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 476u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_width*/
  {12u/*BitLength*/, 300u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 476u/* BufferStartIdx */, 478u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 304u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 477u/* BufferStartIdx */, 479u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_Y*/
  {4u/*BitLength*/, 332u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_ID*/
  {3u/*BitLength*/, 341u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 483u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_type*/
  {4u/*BitLength*/, 328u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Confidence*/
  {7u/*BitLength*/, 350u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 484u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_width*/
  {12u/*BitLength*/, 364u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 484u/* BufferStartIdx */, 486u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_X*/
  {12u/*BitLength*/, 368u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 485u/* BufferStartIdx */, 487u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_Y*/
  {4u/*BitLength*/, 396u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_ID*/
  {3u/*BitLength*/, 405u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 491u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_type*/
  {4u/*BitLength*/, 392u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Confidence*/
  {7u/*BitLength*/, 414u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 492u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_width*/
  {12u/*BitLength*/, 428u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 492u/* BufferStartIdx */, 494u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_X*/
  {12u/*BitLength*/, 432u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 493u/* BufferStartIdx */, 495u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 440u/* BufferStartIdx */, 504u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD2_0x203*/
  {4u/*BitLength*/, 12u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 507u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 508u/* BufferStartIdx */, 510u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 509u/* BufferStartIdx */, 511u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_Y*/
  {2u/*BitLength*/, 112u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 518u/* BufferStartIdx */, 519u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_WorkSts*/
  {16u/*BitLength*/, 80u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 515u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj_Timestamp*/
  {6u/*BitLength*/, 90u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 515u/* BufferStartIdx */, 516u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD1_distance*/
  {6u/*BitLength*/, 100u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 515u/* BufferStartIdx */, 517u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD2_distance*/
  {6u/*BitLength*/, 110u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 516u/* BufferStartIdx */, 518u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD3_distance*/
  {6u/*BitLength*/, 104u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 517u/* BufferStartIdx */, 518u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD4_distance*/
  {6u/*BitLength*/, 114u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 518u/* BufferStartIdx */, 519u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD5_distance*/
  {6u/*BitLength*/, 138u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 522u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD6_distance*/
  {6u/*BitLength*/, 148u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 523u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD7_distance*/
  {6u/*BitLength*/, 158u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 522u/* BufferStartIdx */, 524u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD8_distance*/
  {6u/*BitLength*/, 152u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 523u/* BufferStartIdx */, 524u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD9_distance*/
  {6u/*BitLength*/, 162u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 524u/* BufferStartIdx */, 525u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD10_distance*/
  {6u/*BitLength*/, 172u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 524u/* BufferStartIdx */, 526u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD11_distance*/
  {6u/*BitLength*/, 182u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 525u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD12_distance*/
  {6u/*BitLength*/, 176u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 526u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD13_distance*/
  {6u/*BitLength*/, 202u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD14_distance*/
  {6u/*BitLength*/, 212u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD15_distance*/
  {6u/*BitLength*/, 222u/* BitPosition */, 36u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD16_distance*/
  {6u/*BitLength*/, 216u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 531u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD17_distance*/
  {6u/*BitLength*/, 226u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 533u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD18_distance*/
  {1u/*BitLength*/, 335u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 545u/* BufferStartIdx */, 546u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Swt_Req*/
  {1u/*BitLength*/, 334u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 545u/* BufferStartIdx */, 546u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Act_Req*/
  {1u/*BitLength*/, 25u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 507u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AutoSpdSetSwt*/
  {1u/*BitLength*/, 24u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 507u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LaneChngCfmSwt*/
  {1u/*BitLength*/, 63u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 511u/* BufferStartIdx */, 512u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*VoiceBrdcSwt*/
  {4u/*BitLength*/, 26u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 507u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*UsrManSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 504u/* BufferStartIdx */, 568u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD3_0x243*/
  {1u/*BitLength*/, 11u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 570u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Return_Btn*/
  {2u/*BitLength*/, 42u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 573u/* BufferStartIdx */, 574u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_APA_Permit*/
  {1u/*BitLength*/, 10u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 570u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Set_Starting*/
  {1u/*BitLength*/, 9u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 570u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_SelfParLot_Ending*/
  {1u/*BitLength*/, 21u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 570u/* BufferStartIdx */, 571u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Set_Path_Ending*/
  {4u/*BitLength*/, 32u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 572u/* BufferStartIdx */, 573u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SlotNum_VR*/
  {3u/*BitLength*/, 16u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 570u/* BufferStartIdx */, 571u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefPrkMenuSelCmd*/
  {1u/*BitLength*/, 44u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 573u/* BufferStartIdx */, 574u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefinedParkCmd*/
  {512u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 568u/* BufferStartIdx */, 632u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD4_0x1DA*/
  {512u/*BitLength*/, 504u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 632u/* BufferStartIdx */, 696u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ExternalDevice*/
  {512u/*BitLength*/, 0u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 632u/* BufferStartIdx */, 696u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD5_0x1DB*/
  {8u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 696u/* BufferStartIdx */, 697u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequestMessageId*/
  {56u/*BitLength*/, 56u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 7u/* BusAccBtyeLength */, 697u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequstReseverData*/
  {9u/*BitLength*/, 23u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 713u/* BufferStartIdx */, 715u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdDisp*/
  {8u/*BitLength*/, 60u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 718u/* BufferStartIdx */, 720u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VelSpdDisp_Mile*/
  {64u/*BitLength*/, 0u/* BitPosition */, 40u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 712u/* BufferStartIdx */, 720u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP1_0x293*/
  {24u/*BitLength*/, 24u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 721u/* BufferStartIdx */, 724u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistance*/
  {1u/*BitLength*/, 46u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 725u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceValid*/
  {2u/*BitLength*/, 50u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 727u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_DrvSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 727u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_PassSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 42u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 725u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_BattChrgLmpSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 727u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ABMWarnLmpFailSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 727u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_Err*/
  {1u/*BitLength*/, 47u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 725u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ACCErr*/
  {1u/*BitLength*/, 53u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 726u/* BufferStartIdx */, 727u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdUnit*/
  {64u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 720u/* BufferStartIdx */, 728u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP2_0x27F*/
  {1u/*BitLength*/, 18u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 730u/* BufferStartIdx */, 731u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EBDFailSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 728u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP3_0x34A*/
  {1u/*BitLength*/, 29u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 739u/* BufferStartIdx */, 740u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IP_RstAvrgEgyCns*/
  {64u/*BitLength*/, 0u/* BitPosition */, 43u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 736u/* BufferStartIdx */, 744u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP5_0x338*/
  {16u/*BitLength*/, 43u/* BitPosition */, 44u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 747u/* BufferStartIdx */, 750u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_MntnDistance*/
  {64u/*BitLength*/, 0u/* BitPosition */, 44u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 744u/* BufferStartIdx */, 752u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP6_0x473*/
};

const ComEx_TxPduInfoType ComEx_TxPduInfo[ComEx_TxPduSize] = 
{
  {65535u/* SignalStartIdx */, 65535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 0/* CalloutStartIdx */, 1u/* CalloutNum */}, /*ComIPdu_userData*/
  {0u/* SignalStartIdx */, 36u/* SignalEndIdx */, 0u/* GroupStartIdx */, 4u/* GroupEndIdx */, 8u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DMS_FD1*/
  {36u/* SignalStartIdx */, 40u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DVR_FD1*/
  {40u/* SignalStartIdx */, 64u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT1*/
  {64u/* SignalStartIdx */, 80u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT2*/
  {80u/* SignalStartIdx */, 94u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 152u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT3*/
  {94u/* SignalStartIdx */, 113u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 160u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT4*/
  {113u/* SignalStartIdx */, 132u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 168u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT6*/
  {132u/* SignalStartIdx */, 139u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT7*/
  {139u/* SignalStartIdx */, 156u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 184u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT10*/
  {156u/* SignalStartIdx */, 168u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT13*/
  {168u/* SignalStartIdx */, 189u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT15*/
  {189u/* SignalStartIdx */, 193u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT16*/
  {193u/* SignalStartIdx */, 206u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 216u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT17*/
  {206u/* SignalStartIdx */, 220u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 224u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT19*/
  {220u/* SignalStartIdx */, 230u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 232u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT20*/
  {230u/* SignalStartIdx */, 243u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT21*/
  {243u/* SignalStartIdx */, 263u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 248u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT22*/
  {263u/* SignalStartIdx */, 281u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT23*/
  {281u/* SignalStartIdx */, 285u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT25*/
  {285u/* SignalStartIdx */, 287u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT26*/
  {287u/* SignalStartIdx */, 289u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 280u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT28*/
  {289u/* SignalStartIdx */, 291u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 288u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT30*/
  {291u/* SignalStartIdx */, 312u/* SignalEndIdx */, 4u/* GroupStartIdx */, 5u/* GroupEndIdx */, 296u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT32*/
  {312u/* SignalStartIdx */, 335u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 304u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT33*/
  {335u/* SignalStartIdx */, 346u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 312u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT34*/
  {346u/* SignalStartIdx */, 351u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 320u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT35*/
  {351u/* SignalStartIdx */, 358u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 328u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT38*/
  {358u/* SignalStartIdx */, 363u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 336u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT39*/
  {363u/* SignalStartIdx */, 373u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 344u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT40*/
  {373u/* SignalStartIdx */, 384u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 352u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT41*/
  {384u/* SignalStartIdx */, 393u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT42*/
  {393u/* SignalStartIdx */, 398u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT44*/
  {398u/* SignalStartIdx */, 402u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT45*/
  {402u/* SignalStartIdx */, 465u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 56u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD1*/
  {465u/* SignalStartIdx */, 508u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD2*/
  {508u/* SignalStartIdx */, 541u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 504u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD3*/
  {541u/* SignalStartIdx */, 550u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 568u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD4*/
  {550u/* SignalStartIdx */, 552u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 632u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD5*/
  {552u/* SignalStartIdx */, 554u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_Sync_Req*/
  {554u/* SignalStartIdx */, 557u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 712u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP1*/
  {557u/* SignalStartIdx */, 567u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 720u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP2*/
  {567u/* SignalStartIdx */, 569u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 728u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP3*/
  {569u/* SignalStartIdx */, 571u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 736u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP5*/
  {571u/* SignalStartIdx */, 573u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 744u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP6*/
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
  0x0u,
  0x0u,
  0x0u,
  0x7u,
  0x0u,
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
  0x3cu,
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
  0x96u,
  0x0u,
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
  0x45u,
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
  0x0u,
  0x0u,
  0x0u,
  0xffu,
  0xe7u,
  0xffu,
  0x0u,
  0x0u,
  0x0u,
  0xa0u,
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
  0x40u,
  0x80u,
  0x80u,
  0x0u,
  0xcbu,
  0x97u,
  0x2eu,
  0x5cu,
  0xb9u,
  0x72u,
  0xa0u,
  0x80u,
  0x80u,
  0x80u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xbfu,
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x0u,
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
  0x1u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x15u,
  0x34u,
  0x25u,
  0x27u,
  0xf9u,
  0xau,
  0x44u,
  0x86u,
  0x96u,
  0x7fu,
  0x46u,
  0xb0u,
  0x9au,
  0xffu,
  0x86u,
  0xd5u,
  0x35u,
  0x64u,
  0xdu,
  0xa1u,
  0x99u,
  0xf3u,
  0xa1u,
  0x89u,
  0x1fu,
  0xb6u,
  0xabu,
  0x44u,
  0xa5u,
  0x61u,
  0x78u,
  0x94u,
  0xefu,
  0x53u,
  0xa4u,
  0x14u,
  0xb4u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  {23u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* E2eIdx */}, /*HUT32*/
};

const ComEx_TxE2eInfoType ComEx_TxE2eInfo[ComEx_TxE2eSize] =
{
  {E2EPW_WriteInit_DMS2_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS2_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS2_DMS_FD1*/
  {E2EPW_WriteInit_DMS3_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS3_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS3_DMS_FD1*/
  {E2EPW_WriteInit_DMS5_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS5_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS5_DMS_FD1*/
  {E2EPW_WriteInit_DMS6_DMS_FD1_E2E/* InitFunPtr */, E2EPW_Write_DMS6_DMS_FD1_E2E/* WriteFunPtr */}, /*DMS6_DMS_FD1*/
  {E2EPW_WriteInit_HUT32_E2E/* InitFunPtr */, E2EPW_Write_HUT32_E2E/* WriteFunPtr */}, /*HUT32*/
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
