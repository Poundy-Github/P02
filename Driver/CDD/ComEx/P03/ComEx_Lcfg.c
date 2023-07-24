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
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 13u/* AppAccBytePosition */}, /*RollingCounter_ABM1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 14u/* AppAccBytePosition */}, /*ABM1_0x351*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 3u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 22u/* AppAccBytePosition */}, /*VehLgtAccel*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 3u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 24u/* AppAccBytePosition */}, /*VehLatAccel*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 4u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 26u/* AppAccBytePosition */}, /*VehYawRate*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 28u/* AppAccBytePosition */}, /*VehLgtAccelVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 29u/* AppAccBytePosition */}, /*VehLatAccelVld*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 30u/* AppAccBytePosition */}, /*VehDynYawRateVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 31u/* AppAccBytePosition */}, /*ABM2_0x245*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 39u/* AppAccBytePosition */}, /*FLWheelDriveDirection*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 40u/* AppAccBytePosition */}, /*FRWheelDriveDirection*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 41u/* AppAccBytePosition */}, /*FRWheelSpdVld*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 42u/* AppAccBytePosition */}, /*FLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 43u/* AppAccBytePosition */}, /*FLWheelSpd*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 45u/* AppAccBytePosition */}, /*FRWheelSpd*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 47u/* AppAccBytePosition */}, /*WssFLEdgesSum*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 48u/* AppAccBytePosition */}, /*WssFREdgesSum*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 49u/* AppAccBytePosition */}, /*WssFLEdgesSumVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 50u/* AppAccBytePosition */}, /*WssFREdgesSumVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 51u/* AppAccBytePosition */}, /*ABS1_0x231*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 59u/* AppAccBytePosition */}, /*RLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 60u/* AppAccBytePosition */}, /*RLWheelSpd*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 62u/* AppAccBytePosition */}, /*RRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 63u/* AppAccBytePosition */}, /*RRWheelSpd*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 65u/* AppAccBytePosition */}, /*RLWheelDriveDirection*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 66u/* AppAccBytePosition */}, /*RRWheelDriveDirection*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 67u/* AppAccBytePosition */}, /*WssRREdgesSum*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 68u/* AppAccBytePosition */}, /*WssRLEdgesSum*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 69u/* AppAccBytePosition */}, /*WssRLEdgesSumVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 70u/* AppAccBytePosition */}, /*WssRREdgesSumVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 71u/* AppAccBytePosition */}, /*ABS2_0x246*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 79u/* AppAccBytePosition */}, /*InCarTemp*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 80u/* AppAccBytePosition */}, /*ACAQSEnaSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 81u/* AppAccBytePosition */}, /*ACOperMod*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 82u/* AppAccBytePosition */}, /*ACAIUEnaSts*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 83u/* AppAccBytePosition */}, /*ACDrvAirDistriMod*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 84u/* AppAccBytePosition */}, /*ACSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 85u/* AppAccBytePosition */}, /*ACFrntPassTempSteplessSetEnaSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 86u/* AppAccBytePosition */}, /*ACDrvTempSteplessSetEnaSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 87u/* AppAccBytePosition */}, /*ACEEMSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 88u/* AppAccBytePosition */}, /*AC1_0x29D*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 96u/* AppAccBytePosition */}, /*ACFrntDefrstSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 97u/* AppAccBytePosition */}, /*ACHMIDispCmd*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 98u/* AppAccBytePosition */}, /*ACFrntBlwrSpd*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 99u/* AppAccBytePosition */}, /*ACOpenSts*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 100u/* AppAccBytePosition */}, /*ACDualModEnaSts*/
  {6u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 101u/* AppAccBytePosition */}, /*ACDrvTemp_ATC*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 102u/* AppAccBytePosition */}, /*ACAmbTemp*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 103u/* AppAccBytePosition */}, /*ACAirInletSts*/
  {6u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 104u/* AppAccBytePosition */}, /*ACFrntPasstTemp_ATC*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 105u/* AppAccBytePosition */}, /*ACAutoModEnaSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 106u/* AppAccBytePosition */}, /*ACCmprEnaSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 107u/* AppAccBytePosition */}, /*ACRearWinHeatSts*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 108u/* AppAccBytePosition */}, /*ACAutoDefrstModEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 109u/* AppAccBytePosition */}, /*AC2_0x385*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 117u/* AppAccBytePosition */}, /*ACRearAirDistriMod*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 118u/* AppAccBytePosition */}, /*ACReartBlwrSpd*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 119u/* AppAccBytePosition */}, /*RearACAutoModEnaSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 120u/* AppAccBytePosition */}, /*ACRearSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 121u/* AppAccBytePosition */}, /*ACRLTempStepleSetEnaSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 122u/* AppAccBytePosition */}, /*ACRearHMIDispCmd*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 123u/* AppAccBytePosition */}, /*ACRearLockSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 124u/* AppAccBytePosition */}, /*ACRearOpenSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 125u/* AppAccBytePosition */}, /*AC3_0x2FD*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 133u/* AppAccBytePosition */}, /*ACMaxEnaSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 134u/* AppAccBytePosition */}, /*ACZoneModEnaSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 135u/* AppAccBytePosition */}, /*L_FGAChan1TimeoutAlarm*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 136u/* AppAccBytePosition */}, /*L_FGAChan2TimeoutAlarm*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 137u/* AppAccBytePosition */}, /*L_FGAChan3TimeoutAlarm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 138u/* AppAccBytePosition */}, /*AC4_0x2CC*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 146u/* AppAccBytePosition */}, /*L_PM25InAirQltyLvl*/
  {10u/*BitLength*/, 27u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 147u/* AppAccBytePosition */}, /*L_PM25InDens*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 149u/* AppAccBytePosition */}, /*L_FGAEnaSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 150u/* AppAccBytePosition */}, /*L_FGALvlResp*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 151u/* AppAccBytePosition */}, /*L_FGAChanTypSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 152u/* AppAccBytePosition */}, /*AC6_0x2F8*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 160u/* AppAccBytePosition */}, /*FG_Chan1Typ*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 161u/* AppAccBytePosition */}, /*FG_Chan2Typ*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 162u/* AppAccBytePosition */}, /*FG_Chan3Typ*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 163u/* AppAccBytePosition */}, /*L_FGAChan1IllegalitySts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 164u/* AppAccBytePosition */}, /*L_FGAChan2IllegalitySts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 165u/* AppAccBytePosition */}, /*L_FGAChan3IllegalitySts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 166u/* AppAccBytePosition */}, /*AC7_0x2D0*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 174u/* AppAccBytePosition */}, /*RearInCarTemp*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 175u/* AppAccBytePosition */}, /*ACRLTemp_ATC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 176u/* AppAccBytePosition */}, /*AC8_0x27C*/
  {7u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 184u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dy*/
  {9u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 185u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dx*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 187u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Typ*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 188u/* AppAccBytePosition */}, /*ACC_LeTargrt_02_Detn*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 189u/* AppAccBytePosition */}, /*ACC_RiTargrt_02_Detn*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 190u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dy*/
  {9u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 191u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dx*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 193u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Typ*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 194u/* AppAccBytePosition */}, /*ACC_LeTgtObjBarDisp*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 195u/* AppAccBytePosition */}, /*ACC_RiTgtObjBarDisp*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 196u/* AppAccBytePosition */}, /*Checksum_ACC3*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 197u/* AppAccBytePosition */}, /*ICA_HandsOffResp*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 198u/* AppAccBytePosition */}, /*ALC_Resp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 199u/* AppAccBytePosition */}, /*HWA_Resp*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 200u/* AppAccBytePosition */}, /*ISL_Resp*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 201u/* AppAccBytePosition */}, /*HWA_SnvtySet_Resp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 202u/* AppAccBytePosition */}, /*Longctrl_VehHldReq_DVR*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 203u/* AppAccBytePosition */}, /*Longctrl_DrvOFF_Req_DVR*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 204u/* AppAccBytePosition */}, /*Longctrl_ModSts_DVR*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 205u/* AppAccBytePosition */}, /*Longctrl_Decel_Req_DVR*/
  {16u/*BitLength*/, 96u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 206u/* AppAccBytePosition */}, /*Longctrl_EngTrqReq_DVR*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 208u/* AppAccBytePosition */}, /*Longctrl_EngTrqReqActive_DVR*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 209u/* AppAccBytePosition */}, /*Longctrl_DecelToStopReq_DVR*/
  {2u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 210u/* AppAccBytePosition */}, /*Longctrl_ParkShiftReq_DVR*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 211u/* AppAccBytePosition */}, /*Longctrl_Decel_ReqValue_DVR*/
  {2u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 212u/* AppAccBytePosition */}, /*ALC_InterSysInfoDisp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 213u/* AppAccBytePosition */}, /*RollingCounter_ACC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 214u/* AppAccBytePosition */}, /*Checksum_ACC4*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 215u/* AppAccBytePosition */}, /*ACC_ObjDetecte*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 216u/* AppAccBytePosition */}, /*ACC_TakeOverReq*/
  {5u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 217u/* AppAccBytePosition */}, /*ACC_InterSysInfoDisp*/
  {5u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 218u/* AppAccBytePosition */}, /*ACC_ModDisp*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 219u/* AppAccBytePosition */}, /*ACC_FctSts*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 220u/* AppAccBytePosition */}, /*ACC_TgtObjBarDisp*/
  {2u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 221u/* AppAccBytePosition */}, /*Longctrl_HazActv*/
  {3u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 222u/* AppAccBytePosition */}, /*TJA_ACC_SelSts*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 223u/* AppAccBytePosition */}, /*CruCha_ModDisp*/
  {3u/*BitLength*/, 161u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 224u/* AppAccBytePosition */}, /*TJA_ICA_InterSysInfoDisp*/
  {3u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 225u/* AppAccBytePosition */}, /*TJA_ICA_ModDisp*/
  {2u/*BitLength*/, 171u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 226u/* AppAccBytePosition */}, /*ISL_InterSysInfoDisp*/
  {3u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 227u/* AppAccBytePosition */}, /*ACC_TimeGapSet*/
  {8u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 228u/* AppAccBytePosition */}, /*ACC_SpdSetValue*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 229u/* AppAccBytePosition */}, /*CruChar_InterSysInfoDisp*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 230u/* AppAccBytePosition */}, /*RollingCounter_ACC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 231u/* AppAccBytePosition */}, /*Checksum_ACC8*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 232u/* AppAccBytePosition */}, /*HWA_ModDisp*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 233u/* AppAccBytePosition */}, /*HWA_InterSysInfoDisp*/
  {2u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 234u/* AppAccBytePosition */}, /*HWA_LaneChange*/
  {3u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 235u/* AppAccBytePosition */}, /*HWA_LaneChangeReq*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 236u/* AppAccBytePosition */}, /*HWA_Warning*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 237u/* AppAccBytePosition */}, /*RollingCounter_ACC8*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 238u/* AppAccBytePosition */}, /*Checksum_ACC6*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 239u/* AppAccBytePosition */}, /*ACC_PotentialTgtDy*/
  {9u/*BitLength*/, 287u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 240u/* AppAccBytePosition */}, /*ACC_PotentialTgtDx*/
  {2u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 242u/* AppAccBytePosition */}, /*ACC_RlvTgtDetn*/
  {2u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 243u/* AppAccBytePosition */}, /*ACC_EgoStatus*/
  {3u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 244u/* AppAccBytePosition */}, /*ACC_RlvTgtTyp*/
  {8u/*BitLength*/, 288u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 245u/* AppAccBytePosition */}, /*ACC_RlvTgtDy*/
  {9u/*BitLength*/, 311u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 246u/* AppAccBytePosition */}, /*ACC_RlvTgtDx*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 248u/* AppAccBytePosition */}, /*ACC_PotentialTgtDetn*/
  {3u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 249u/* AppAccBytePosition */}, /*ACC_PotentialTgtTyp*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 250u/* AppAccBytePosition */}, /*RollingCounter_ACC6*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 251u/* AppAccBytePosition */}, /*Checksum_ACC7*/
  {3u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 252u/* AppAccBytePosition */}, /*Request_driveoff*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 253u/* AppAccBytePosition */}, /*ACC_LeTgtDy*/
  {9u/*BitLength*/, 351u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 254u/* AppAccBytePosition */}, /*ACC_LeTgtDx*/
  {3u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 256u/* AppAccBytePosition */}, /*ACC_LeTgtTyp*/
  {2u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 257u/* AppAccBytePosition */}, /*ACC_LeTargrtDection*/
  {2u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 258u/* AppAccBytePosition */}, /*ACC_RiTargrtDetn*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 259u/* AppAccBytePosition */}, /*ACC_RiTgtDy*/
  {9u/*BitLength*/, 375u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 260u/* AppAccBytePosition */}, /*ACC_RiTgtDx*/
  {3u/*BitLength*/, 372u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 262u/* AppAccBytePosition */}, /*ACC_RiTgtTyp*/
  {1u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 263u/* AppAccBytePosition */}, /*ACCSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 264u/* AppAccBytePosition */}, /*RollingCounter_ACC7*/
  {1u/*BitLength*/, 399u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 265u/* AppAccBytePosition */}, /*ACC_RlvTgtfusion*/
  {6u/*BitLength*/, 393u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 266u/* AppAccBytePosition */}, /*ACC_RlvTgtHeading*/
  {1u/*BitLength*/, 392u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 267u/* AppAccBytePosition */}, /*ACC_LeTgtfusion*/
  {6u/*BitLength*/, 402u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 268u/* AppAccBytePosition */}, /*ACC_LeTgtHeading*/
  {1u/*BitLength*/, 401u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 269u/* AppAccBytePosition */}, /*ACC_RiTgtfusion*/
  {6u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 270u/* AppAccBytePosition */}, /*ACC_RiTgtHeading*/
  {1u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 271u/* AppAccBytePosition */}, /*ACC_PotentialTgtfusion*/
  {6u/*BitLength*/, 420u/* BitPosition */, 2u/* ByteLength */, 52u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 272u/* AppAccBytePosition */}, /*ACC_PotentialTgtHeading*/
  {6u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 273u/* AppAccBytePosition */}, /*TargetCutinPro*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 274u/* AppAccBytePosition */}, /*TargetCutoutPro*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 275u/* AppAccBytePosition */}, /*Longctrl_WheelTrqReqActive_DVR*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 276u/* AppAccBytePosition */}, /*Longctrl_WheelTrqReq_DVR*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 278u/* AppAccBytePosition */}, /*ACC_FD2_0x2AB*/
  {6u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 334u/* AppAccBytePosition */}, /*JAPedObjExist*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 335u/* AppAccBytePosition */}, /*AEBJAObjID*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 336u/* AppAccBytePosition */}, /*AEBJAObjExist*/
  {8u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 337u/* AppAccBytePosition */}, /*JAPedObjID*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 338u/* AppAccBytePosition */}, /*AEBJAObjVideoCfmd*/
  {12u/*BitLength*/, 100u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 339u/* AppAccBytePosition */}, /*AEBJAObjVx*/
  {12u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 341u/* AppAccBytePosition */}, /*AEBJAObjDx*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 343u/* AppAccBytePosition */}, /*JAPedObjVideoCfmd*/
  {3u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 344u/* AppAccBytePosition */}, /*AEBJAObjState*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 345u/* AppAccBytePosition */}, /*AEBJAObjCntAlive*/
  {11u/*BitLength*/, 153u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 347u/* AppAccBytePosition */}, /*AEBJAObjDy*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 349u/* AppAccBytePosition */}, /*JAPedObjState*/
  {5u/*BitLength*/, 164u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 350u/* AppAccBytePosition */}, /*AEBJAObjObstcl*/
  {10u/*BitLength*/, 170u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 351u/* AppAccBytePosition */}, /*AEBJAObjVy*/
  {10u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 353u/* AppAccBytePosition */}, /*AEBJAObjAx*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 355u/* AppAccBytePosition */}, /*AEBJAObjAy*/
  {5u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 357u/* AppAccBytePosition */}, /*JAPedObjObstcl*/
  {11u/*BitLength*/, 229u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 358u/* AppAccBytePosition */}, /*JAPedObjDy*/
  {12u/*BitLength*/, 233u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 360u/* AppAccBytePosition */}, /*JAPedObjDx*/
  {6u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 362u/* AppAccBytePosition */}, /*FCWAEB_JATTC*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 363u/* AppAccBytePosition */}, /*JAPedObjVx*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 365u/* AppAccBytePosition */}, /*JAPedObjVy*/
  {10u/*BitLength*/, 308u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 367u/* AppAccBytePosition */}, /*JAPedObjAy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 369u/* AppAccBytePosition */}, /*JAPedObjCntAlive*/
  {6u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 371u/* AppAccBytePosition */}, /*FCWAEB_longTTC*/
  {6u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 372u/* AppAccBytePosition */}, /*FCWAEB_crossingTTC*/
  {10u/*BitLength*/, 342u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 373u/* AppAccBytePosition */}, /*JAPedObjAx*/
  {4u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 375u/* AppAccBytePosition */}, /*NOH_Sts*/
  {1u/*BitLength*/, 368u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 376u/* AppAccBytePosition */}, /*NOH_Swt_Resp*/
  {1u/*BitLength*/, 369u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 377u/* AppAccBytePosition */}, /*NOH_Act_Resp*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 378u/* AppAccBytePosition */}, /*NOH_SysInfoDisplay*/
  {12u/*BitLength*/, 356u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 379u/* AppAccBytePosition */}, /*NOH_DistToExit*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 381u/* AppAccBytePosition */}, /*ACC_FD3_0x2B4*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 445u/* AppAccBytePosition */}, /*AEBObjID*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 446u/* AppAccBytePosition */}, /*AEBObjExist*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 447u/* AppAccBytePosition */}, /*AEBObjVideoCfmd*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 448u/* AppAccBytePosition */}, /*AEBObjVx*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 450u/* AppAccBytePosition */}, /*AEBObjDx*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 452u/* AppAccBytePosition */}, /*AEBObjCntAlive*/
  {11u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 454u/* AppAccBytePosition */}, /*AEBObjDy*/
  {3u/*BitLength*/, 69u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 456u/* AppAccBytePosition */}, /*AEBObjState*/
  {5u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 457u/* AppAccBytePosition */}, /*AEBObjObstcl*/
  {10u/*BitLength*/, 86u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 458u/* AppAccBytePosition */}, /*AEBObjVy*/
  {6u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 460u/* AppAccBytePosition */}, /*CyclistObjExist*/
  {10u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 461u/* AppAccBytePosition */}, /*AEBObjAx*/
  {10u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 463u/* AppAccBytePosition */}, /*AEBObjAy*/
  {12u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 465u/* AppAccBytePosition */}, /*CyclistObjDx*/
  {8u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 467u/* AppAccBytePosition */}, /*CyclistObjID*/
  {5u/*BitLength*/, 131u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 468u/* AppAccBytePosition */}, /*CyclistObjObstcl*/
  {11u/*BitLength*/, 136u/* BitPosition */, 2u/* ByteLength */, 17u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 469u/* AppAccBytePosition */}, /*CyclistObjDy*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 471u/* AppAccBytePosition */}, /*CyclistObjVx*/
  {12u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 473u/* AppAccBytePosition */}, /*CyclistObjCntAlive*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 475u/* AppAccBytePosition */}, /*CyclistObjVy*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 477u/* AppAccBytePosition */}, /*CyclistObjState*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 478u/* AppAccBytePosition */}, /*CyclistObjVideoCfmd*/
  {10u/*BitLength*/, 184u/* BitPosition */, 2u/* ByteLength */, 23u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 479u/* AppAccBytePosition */}, /*CyclistObjAx*/
  {10u/*BitLength*/, 206u/* BitPosition */, 2u/* ByteLength */, 25u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 481u/* AppAccBytePosition */}, /*CyclistObjAy*/
  {6u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 483u/* AppAccBytePosition */}, /*PedObjExist*/
  {8u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 484u/* AppAccBytePosition */}, /*PedObjID*/
  {5u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 485u/* AppAccBytePosition */}, /*PedObjObstcl*/
  {11u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 486u/* AppAccBytePosition */}, /*PedObjDy*/
  {12u/*BitLength*/, 244u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 488u/* AppAccBytePosition */}, /*PedObjDx*/
  {12u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 490u/* AppAccBytePosition */}, /*PedObjVx*/
  {10u/*BitLength*/, 270u/* BitPosition */, 2u/* ByteLength */, 33u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 492u/* AppAccBytePosition */}, /*PedObjVy*/
  {1u/*BitLength*/, 269u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 494u/* AppAccBytePosition */}, /*PedObjVideoCfmd*/
  {12u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 495u/* AppAccBytePosition */}, /*ACCTgtObjDx*/
  {10u/*BitLength*/, 294u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 497u/* AppAccBytePosition */}, /*PedObjAy*/
  {12u/*BitLength*/, 298u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 499u/* AppAccBytePosition */}, /*PedObjCntAlive*/
  {10u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 501u/* AppAccBytePosition */}, /*PedObjAx*/
  {8u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 503u/* AppAccBytePosition */}, /*ACCTgtObjID*/
  {5u/*BitLength*/, 323u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 504u/* AppAccBytePosition */}, /*ACCTgtObjObstcl*/
  {11u/*BitLength*/, 328u/* BitPosition */, 2u/* ByteLength */, 41u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 505u/* AppAccBytePosition */}, /*ACCTgtObjDy*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 507u/* AppAccBytePosition */}, /*ACCTgtObjExist*/
  {10u/*BitLength*/, 344u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 508u/* AppAccBytePosition */}, /*ACCTgtObjVy*/
  {12u/*BitLength*/, 364u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 510u/* AppAccBytePosition */}, /*ACCTgtObjVx*/
  {10u/*BitLength*/, 370u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 512u/* AppAccBytePosition */}, /*ACCTgtObjAx*/
  {10u/*BitLength*/, 376u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 514u/* AppAccBytePosition */}, /*ACCTgtObjAy*/
  {3u/*BitLength*/, 389u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 516u/* AppAccBytePosition */}, /*ACCTgtObjState*/
  {1u/*BitLength*/, 388u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 517u/* AppAccBytePosition */}, /*ACCTgtObjVideoCfmd*/
  {12u/*BitLength*/, 392u/* BitPosition */, 2u/* ByteLength */, 49u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 518u/* AppAccBytePosition */}, /*ACCTgtObjCntAlive*/
  {12u/*BitLength*/, 412u/* BitPosition */, 2u/* ByteLength */, 51u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 520u/* AppAccBytePosition */}, /*RadarHorMisalign*/
  {2u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 522u/* AppAccBytePosition */}, /*HandsoffDetd*/
  {2u/*BitLength*/, 408u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 523u/* AppAccBytePosition */}, /*DrvgOnHiWay*/
  {10u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 524u/* AppAccBytePosition */}, /*RoadCrvt*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 526u/* AppAccBytePosition */}, /*SpdLimitDst*/
  {10u/*BitLength*/, 446u/* BitPosition */, 2u/* ByteLength */, 55u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 527u/* AppAccBytePosition */}, /*RoadCrvtFar*/
  {6u/*BitLength*/, 440u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 529u/* AppAccBytePosition */}, /*RampDst*/
  {8u/*BitLength*/, 448u/* BitPosition */, 1u/* ByteLength */, 56u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 530u/* AppAccBytePosition */}, /*SpdLimit*/
  {6u/*BitLength*/, 458u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 531u/* AppAccBytePosition */}, /*CurveDst*/
  {2u/*BitLength*/, 456u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 532u/* AppAccBytePosition */}, /*NavSpdLimUnit*/
  {6u/*BitLength*/, 466u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 533u/* AppAccBytePosition */}, /*TunnelDst*/
  {2u/*BitLength*/, 464u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 534u/* AppAccBytePosition */}, /*DrvgOnRiLane*/
  {6u/*BitLength*/, 474u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 535u/* AppAccBytePosition */}, /*BrdgDst*/
  {1u/*BitLength*/, 473u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 536u/* AppAccBytePosition */}, /*RadarDrvrAttentive*/
  {8u/*BitLength*/, 504u/* BitPosition */, 1u/* ByteLength */, 63u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 537u/* AppAccBytePosition */}, /*ACC_DataRecReq*/
  {2u/*BitLength*/, 483u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 538u/* AppAccBytePosition */}, /*ACC_SOSReq*/
  {3u/*BitLength*/, 480u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 539u/* AppAccBytePosition */}, /*PedObjState*/
  {1u/*BitLength*/, 495u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 540u/* AppAccBytePosition */}, /*MapDataValid*/
  {3u/*BitLength*/, 492u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 541u/* AppAccBytePosition */}, /*DrvrSts*/
  {5u/*BitLength*/, 503u/* BitPosition */, 2u/* ByteLength */, 62u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 542u/* AppAccBytePosition */}, /*AEBObjOverlap*/
  {5u/*BitLength*/, 498u/* BitPosition */, 1u/* ByteLength */, 62u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 543u/* AppAccBytePosition */}, /*AEBObjDrvby*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 544u/* AppAccBytePosition */}, /*ACC_FD4_0x2B8*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 608u/* AppAccBytePosition */}, /*AEB_ABA_Level*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 609u/* AppAccBytePosition */}, /*AEB_ABA_Req*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 610u/* AppAccBytePosition */}, /*EBA_TgtDecel_Req*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 611u/* AppAccBytePosition */}, /*AEB_VehHldReq*/
  {1u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 612u/* AppAccBytePosition */}, /*AEB_TgtDecel_Req*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 613u/* AppAccBytePosition */}, /*AEB_TgtDecel_ReqValue*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 615u/* AppAccBytePosition */}, /*AEB_AWB_Req*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 616u/* AppAccBytePosition */}, /*AEB_AWB_Level*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 617u/* AppAccBytePosition */}, /*AEB_ABP_Req*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 618u/* AppAccBytePosition */}, /*AEB_BrkReqFunc*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 619u/* AppAccBytePosition */}, /*AEB_ObjSty*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 620u/* AppAccBytePosition */}, /*AEB_FD1_0x18B*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 684u/* AppAccBytePosition */}, /*Checksum_AEB2*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 685u/* AppAccBytePosition */}, /*AEB_PedResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 686u/* AppAccBytePosition */}, /*AEB_VehResp*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 687u/* AppAccBytePosition */}, /*FCW_Snvty*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 688u/* AppAccBytePosition */}, /*AEB_JA_Resp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 689u/* AppAccBytePosition */}, /*RollingCounter_AEB2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 690u/* AppAccBytePosition */}, /*Checksum_AEB3*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 691u/* AppAccBytePosition */}, /*AEB_VehTrig*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 692u/* AppAccBytePosition */}, /*AEB_PedTrig*/
  {2u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 693u/* AppAccBytePosition */}, /*FCW_AEB_VehFctSts*/
  {2u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 694u/* AppAccBytePosition */}, /*FCW_AEB_PedFctSts*/
  {2u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 695u/* AppAccBytePosition */}, /*FCW_Warn*/
  {2u/*BitLength*/, 146u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 696u/* AppAccBytePosition */}, /*AEB_JAFuncSts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 697u/* AppAccBytePosition */}, /*AEB_JA_Warn*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 698u/* AppAccBytePosition */}, /*AEB_JABrkTrig*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 699u/* AppAccBytePosition */}, /*RollingCounter_AEB3*/
  {8u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 700u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dy*/
  {9u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 701u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Dx*/
  {2u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 703u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Detn*/
  {3u/*BitLength*/, 218u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 704u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Typ*/
  {1u/*BitLength*/, 217u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 705u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_fusion*/
  {6u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 706u/* AppAccBytePosition */}, /*ACC_PotentialTgt_02_Heading*/
  {8u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 707u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dy*/
  {9u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 708u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Dx*/
  {2u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 710u/* AppAccBytePosition */}, /*ACC_LeTargrt_03_Detn*/
  {3u/*BitLength*/, 253u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 711u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Typ*/
  {1u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 712u/* AppAccBytePosition */}, /*ACC_LeTgt_03_fusion*/
  {6u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 713u/* AppAccBytePosition */}, /*ACC_LeTgt_03_Heading*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 714u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dy*/
  {9u/*BitLength*/, 295u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 715u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Dx*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 717u/* AppAccBytePosition */}, /*ACC_RiTargrt_03_Detn*/
  {3u/*BitLength*/, 292u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 718u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Typ*/
  {1u/*BitLength*/, 291u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 719u/* AppAccBytePosition */}, /*ACC_RiTgt_03_fusion*/
  {6u/*BitLength*/, 298u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 720u/* AppAccBytePosition */}, /*ACC_RiTgt_03_Heading*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 721u/* AppAccBytePosition */}, /*AEB_FD2_0x227*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 777u/* AppAccBytePosition */}, /*CheckSum_HC1*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 778u/* AppAccBytePosition */}, /*ALS_FailSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 779u/* AppAccBytePosition */}, /*RollingCounter_HC1*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 780u/* AppAccBytePosition */}, /*ALS1_0x287*/
  {16u/*BitLength*/, 8u/* BitPosition */, 2u/* ByteLength */, 1u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 796u/* AppAccBytePosition */}, /*AMP_SWVersion*/
  {16u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 798u/* AppAccBytePosition */}, /*AMP_HWVersion*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 800u/* AppAccBytePosition */}, /*AMP_Chan1DTCInfo*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 801u/* AppAccBytePosition */}, /*AMP_Chan2DTCInfo*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 802u/* AppAccBytePosition */}, /*AMP_Chan3DTCInfo*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 803u/* AppAccBytePosition */}, /*AMP_Chan4DTCInfo*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 804u/* AppAccBytePosition */}, /*AMP_Chan5DTCInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 805u/* AppAccBytePosition */}, /*AMP_Chan6DTCInfo*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 806u/* AppAccBytePosition */}, /*AMP_Chan7DTCInfo*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 807u/* AppAccBytePosition */}, /*AMP_Chan8DTCInfo*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 808u/* AppAccBytePosition */}, /*AMP_TempValue*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 809u/* AppAccBytePosition */}, /*AMP_TempSts*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 810u/* AppAccBytePosition */}, /*AMP_VolValue*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 811u/* AppAccBytePosition */}, /*BestListegPosnResp*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 812u/* AppAccBytePosition */}, /*Clari_FiResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 813u/* AppAccBytePosition */}, /*AMP1_0x3E1*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 821u/* AppAccBytePosition */}, /*MediaCallSourceState*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 822u/* AppAccBytePosition */}, /*BeepSourceSts*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 823u/* AppAccBytePosition */}, /*BalanceSetState*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 824u/* AppAccBytePosition */}, /*VSCModeState*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 825u/* AppAccBytePosition */}, /*FadeSetState*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 826u/* AppAccBytePosition */}, /*DriveSideSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 827u/* AppAccBytePosition */}, /*BassSetState*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 828u/* AppAccBytePosition */}, /*MuteState*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 829u/* AppAccBytePosition */}, /*NaviSourceState*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 830u/* AppAccBytePosition */}, /*MidrangeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 831u/* AppAccBytePosition */}, /*T_box_ECallSts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 832u/* AppAccBytePosition */}, /*GetHUTInfoSts*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 833u/* AppAccBytePosition */}, /*TrebleSetState*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 834u/* AppAccBytePosition */}, /*QLISurroundSetSt*/
  {1u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 835u/* AppAccBytePosition */}, /*AVMStResp*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 836u/* AppAccBytePosition */}, /*NaviMediaVolLvlResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 837u/* AppAccBytePosition */}, /*AVMMediaVolLvlResp*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 838u/* AppAccBytePosition */}, /*FPASChStResp*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 839u/* AppAccBytePosition */}, /*RPASChStResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 840u/* AppAccBytePosition */}, /*AMP2_0x3E3*/
  {6u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 848u/* AppAccBytePosition */}, /*HFMVolSetSts*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 849u/* AppAccBytePosition */}, /*VR_TTSVolSetSts*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 850u/* AppAccBytePosition */}, /*NaviVolumeSetState*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 851u/* AppAccBytePosition */}, /*MainVolumeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 852u/* AppAccBytePosition */}, /*AMPPowerSts*/
  {6u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 853u/* AppAccBytePosition */}, /*IPVolSetSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 854u/* AppAccBytePosition */}, /*AMP3_0x3E5*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 862u/* AppAccBytePosition */}, /*Microphone_Cha1DTCInfo*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 863u/* AppAccBytePosition */}, /*Microphone_Cha2DTCInfo*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 864u/* AppAccBytePosition */}, /*Microphone_Cha3DTCInfo*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 865u/* AppAccBytePosition */}, /*Microphone_Cha4DTCInfo*/
  {1u/*BitLength*/, 58u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 866u/* AppAccBytePosition */}, /*ANCSwtStatus*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 867u/* AppAccBytePosition */}, /*AMP4_ANC1_0x2D2*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 875u/* AppAccBytePosition */}, /*IPBackgroundLmpCmd*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 876u/* AppAccBytePosition */}, /*TrunkSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 877u/* AppAccBytePosition */}, /*DrvDoorSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 878u/* AppAccBytePosition */}, /*LRDoorSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 879u/* AppAccBytePosition */}, /*PassengerDoorSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 880u/* AppAccBytePosition */}, /*RRDoorSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 881u/* AppAccBytePosition */}, /*BrkPedalSts_BCM*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 882u/* AppAccBytePosition */}, /*BackgroundLightLvl*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 883u/* AppAccBytePosition */}, /*DrowsyDrvDetWarn*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 884u/* AppAccBytePosition */}, /*RLSFailSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 885u/* AppAccBytePosition */}, /*PosnLightReq*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 886u/* AppAccBytePosition */}, /*WindshldWiprActvSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 887u/* AppAccBytePosition */}, /*BCM1_0x319*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 895u/* AppAccBytePosition */}, /*LasHdLmpSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 896u/* AppAccBytePosition */}, /*AntitheftSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 897u/* AppAccBytePosition */}, /*DrvDoorLockSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 898u/* AppAccBytePosition */}, /*DoorLockSts*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 899u/* AppAccBytePosition */}, /*HiLowBeamSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 900u/* AppAccBytePosition */}, /*BCM3_0x345*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 908u/* AppAccBytePosition */}, /*VolSwtReq*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 909u/* AppAccBytePosition */}, /*VolSwtErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 910u/* AppAccBytePosition */}, /*BCM6_0x28C*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 918u/* AppAccBytePosition */}, /*SecRowLeSeatVentnSts_Nine*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 919u/* AppAccBytePosition */}, /*SecRowRiSeatVentnSts_Nine*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 920u/* AppAccBytePosition */}, /*BCM7_0x28D*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 928u/* AppAccBytePosition */}, /*RemoteModSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 929u/* AppAccBytePosition */}, /*PASWorkCmd*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 930u/* AppAccBytePosition */}, /*KL30BRelaySts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 931u/* AppAccBytePosition */}, /*RViewMirrorSts*/
  {3u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 932u/* AppAccBytePosition */}, /*WiprReq_F_PBOX*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 933u/* AppAccBytePosition */}, /*DrivingModReq*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 934u/* AppAccBytePosition */}, /*DrvAsstSwtReq*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 935u/* AppAccBytePosition */}, /*DrvAsstSwtErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 936u/* AppAccBytePosition */}, /*BCM8_0x29F*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 944u/* AppAccBytePosition */}, /*ExpertModSwtReq*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 945u/* AppAccBytePosition */}, /*CCO_SwtShift_Warn*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 946u/* AppAccBytePosition */}, /*TAB_SwtShift_Warn*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 947u/* AppAccBytePosition */}, /*FourLModeSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 948u/* AppAccBytePosition */}, /*Wade_Sw_Warn*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 949u/* AppAccBytePosition */}, /*WadeSwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 950u/* AppAccBytePosition */}, /*BCM11_0x305*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 958u/* AppAccBytePosition */}, /*SrAntiPinch*/
  {7u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 959u/* AppAccBytePosition */}, /*SsPosn_VR_APP*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 960u/* AppAccBytePosition */}, /*SsAntiPinch*/
  {7u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 961u/* AppAccBytePosition */}, /*SrPosn_VR_APP*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 962u/* AppAccBytePosition */}, /*RLS_IRBrightness*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 963u/* AppAccBytePosition */}, /*RLS_FwBrightness*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 965u/* AppAccBytePosition */}, /*RLS_AmbBrightness*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 967u/* AppAccBytePosition */}, /*BCM12_0x238*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 975u/* AppAccBytePosition */}, /*DrvSeatHeatSts_Nine*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 976u/* AppAccBytePosition */}, /*PassSeatHeatSts_Nine*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 977u/* AppAccBytePosition */}, /*SecRowLeSeatHeatSts_Nine*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 978u/* AppAccBytePosition */}, /*SecRowRiSeatHeatSts_Nine*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 979u/* AppAccBytePosition */}, /*DrvSeatVentnSts_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 980u/* AppAccBytePosition */}, /*PassSeatVentnSts_Nine*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 981u/* AppAccBytePosition */}, /*BCM14_0x2A3*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 989u/* AppAccBytePosition */}, /*AutoLmpSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 990u/* AppAccBytePosition */}, /*BCM17_0x23E*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 998u/* AppAccBytePosition */}, /*WshngLiquidLvlWarn*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 999u/* AppAccBytePosition */}, /*DrivingModReq_HCU*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1000u/* AppAccBytePosition */}, /*BCM19_0x30F*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1008u/* AppAccBytePosition */}, /*BLEConnSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1009u/* AppAccBytePosition */}, /*BLESecuritySts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1010u/* AppAccBytePosition */}, /*BLE1_0x25C*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1018u/* AppAccBytePosition */}, /*BLE_BeanID*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1026u/* AppAccBytePosition */}, /*BLE5_0x1FA*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1034u/* AppAccBytePosition */}, /*BMS_ErrCategory*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1035u/* AppAccBytePosition */}, /*CheckSum_BMS4*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1036u/* AppAccBytePosition */}, /*BMS_PackCurr*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 23u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1038u/* AppAccBytePosition */}, /*BMS_PackVolt*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1039u/* AppAccBytePosition */}, /*BMS_PowerDownCmplt*/
  {2u/*BitLength*/, 63u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1040u/* AppAccBytePosition */}, /*BMS_BattPoweErr*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1041u/* AppAccBytePosition */}, /*RollingCounter_BMS4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1042u/* AppAccBytePosition */}, /*BMS4_0xF1*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1050u/* AppAccBytePosition */}, /*BMS_DisSOC1*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1051u/* AppAccBytePosition */}, /*BMS_BattHeatRunaway*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1052u/* AppAccBytePosition */}, /*BMS8_0x285*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1060u/* AppAccBytePosition */}, /*BMS_IntelEngIdlChrgnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1061u/* AppAccBytePosition */}, /*BMS_BattKeepTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1062u/* AppAccBytePosition */}, /*BMS19_0x352*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1070u/* AppAccBytePosition */}, /*BMS_ChrgDurationTime*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1072u/* AppAccBytePosition */}, /*BMS22_0x3BF*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1080u/* AppAccBytePosition */}, /*BMS_SOCLowWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1081u/* AppAccBytePosition */}, /*BMS30_0x3F1*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1089u/* AppAccBytePosition */}, /*BMS_BattSOCLimResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1090u/* AppAccBytePosition */}, /*BMS35_0x2C4*/
  {10u/*BitLength*/, 40u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1098u/* AppAccBytePosition */}, /*BMS_BattSOC_P0*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1100u/* AppAccBytePosition */}, /*BMS65_0x14F*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1108u/* AppAccBytePosition */}, /*BMS_SocJumpWarn_RM*/
  {1u/*BitLength*/, 6u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1109u/* AppAccBytePosition */}, /*BMS_PackOverChrgWarn_RM*/
  {3u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1110u/* AppAccBytePosition */}, /*BMS_ChrgSts_RM*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 25u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1111u/* AppAccBytePosition */}, /*BMS_IsolationRValue_RM*/
  {15u/*BitLength*/, 33u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1113u/* AppAccBytePosition */}, /*BMS_PackCurr_RM*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1115u/* AppAccBytePosition */}, /*BMS_SocOverWarn_RM*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1116u/* AppAccBytePosition */}, /*BMS_BattOverTempRank_RM*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1117u/* AppAccBytePosition */}, /*BMS_BattOverVoltRank_RM*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1118u/* AppAccBytePosition */}, /*BMS_BattSOCLowRank_RM*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1119u/* AppAccBytePosition */}, /*BMS_VCUIsolateErr_RM*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1120u/* AppAccBytePosition */}, /*BMS_BattUnderVoltRank_RM*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1121u/* AppAccBytePosition */}, /*BMS_CellDeltaVoltRank_RM*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1122u/* AppAccBytePosition */}, /*BMS_CellOverVoltRank_RM*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1123u/* AppAccBytePosition */}, /*BMS_CellUnderVoltRank_RM*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1124u/* AppAccBytePosition */}, /*BMS_DeltaTempRank_RM*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1125u/* AppAccBytePosition */}, /*BMS_PackMismatchWarn_RM*/
  {14u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1126u/* AppAccBytePosition */}, /*BMS_PackVolt_RM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1128u/* AppAccBytePosition */}, /*BMS66_0x3AE*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1136u/* AppAccBytePosition */}, /*BMS_ChrgTimResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1137u/* AppAccBytePosition */}, /*BMS_FD14_0x1E3*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1145u/* AppAccBytePosition */}, /*RoofModFb*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1146u/* AppAccBytePosition */}, /*AllTerrainDislFb*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1147u/* AppAccBytePosition */}, /*ElecSideStepSysFb*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1148u/* AppAccBytePosition */}, /*CP1_0x35E*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1156u/* AppAccBytePosition */}, /*CR_FCTA_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1157u/* AppAccBytePosition */}, /*CR_FCTB_Resp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1158u/* AppAccBytePosition */}, /*CR_BliSts*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1159u/* AppAccBytePosition */}, /*FCTA_Warn*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1160u/* AppAccBytePosition */}, /*FCTBTrig*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1161u/* AppAccBytePosition */}, /*FCTA_B_FuncSts*/
  {6u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1162u/* AppAccBytePosition */}, /*FCTA_B_TTC*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1163u/* AppAccBytePosition */}, /*CR_FD1_0x15E*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1227u/* AppAccBytePosition */}, /*LTurnLmpSwtSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1228u/* AppAccBytePosition */}, /*RTurnLmpSwtSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1229u/* AppAccBytePosition */}, /*AutoLmpSwtSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1230u/* AppAccBytePosition */}, /*HornSwtSts*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1231u/* AppAccBytePosition */}, /*FrntWiprSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1232u/* AppAccBytePosition */}, /*CSA1_0x165*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1240u/* AppAccBytePosition */}, /*SteerWheelAng*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1242u/* AppAccBytePosition */}, /*SteerWheelAngSign*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1243u/* AppAccBytePosition */}, /*SAS_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1244u/* AppAccBytePosition */}, /*CSA2_0xA1*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1252u/* AppAccBytePosition */}, /*MenuReturnSwtSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1253u/* AppAccBytePosition */}, /*SteerWheelHeatdSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1254u/* AppAccBytePosition */}, /*HomeSwtSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1255u/* AppAccBytePosition */}, /*MuteSwtSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1256u/* AppAccBytePosition */}, /*CustomSwtSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1257u/* AppAccBytePosition */}, /*PageUpSwtSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1258u/* AppAccBytePosition */}, /*PageDwnSwtSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1259u/* AppAccBytePosition */}, /*PageLSwtSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1260u/* AppAccBytePosition */}, /*PageRSwtSts*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1261u/* AppAccBytePosition */}, /*SeekUpSwtSts*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1262u/* AppAccBytePosition */}, /*SeekDwnSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1263u/* AppAccBytePosition */}, /*AdjVolUpSwtSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1264u/* AppAccBytePosition */}, /*AdjVolDwnSwtSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1265u/* AppAccBytePosition */}, /*VRSwtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1266u/* AppAccBytePosition */}, /*EnterSwtSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1267u/* AppAccBytePosition */}, /*EnterSwtSts_Mmed*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1268u/* AppAccBytePosition */}, /*CustomSwtSts_Mmed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1269u/* AppAccBytePosition */}, /*CSA3_0x244*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1277u/* AppAccBytePosition */}, /*TgtEngSpdIP*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1279u/* AppAccBytePosition */}, /*TgtEngSpdIPValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1280u/* AppAccBytePosition */}, /*DCT3_0xA6*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1288u/* AppAccBytePosition */}, /*CurrentGearValid*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1289u/* AppAccBytePosition */}, /*CURRENT_GEAR*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 26u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1290u/* AppAccBytePosition */}, /*TGS_LEVER*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1291u/* AppAccBytePosition */}, /*TRANS_Warning_LAMP*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1292u/* AppAccBytePosition */}, /*DCT5_0x221*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1300u/* AppAccBytePosition */}, /*CheckSum_DCT7*/
  {3u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1301u/* AppAccBytePosition */}, /*TrsmStNID*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1302u/* AppAccBytePosition */}, /*DCT_RaceModeSts*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1303u/* AppAccBytePosition */}, /*TRANS_OIL_TEMP*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1304u/* AppAccBytePosition */}, /*DCT_PrsBrk_Warn*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1305u/* AppAccBytePosition */}, /*DCT_ShftNotAlwd_Warn*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1306u/* AppAccBytePosition */}, /*DCT_ShftRecom_M*/
  {3u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1307u/* AppAccBytePosition */}, /*DrvWarnMsg*/
  {4u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1308u/* AppAccBytePosition */}, /*DrvFaiMsg*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1309u/* AppAccBytePosition */}, /*DrvModDisp*/
  {2u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1310u/* AppAccBytePosition */}, /*DrvModDispSts*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1311u/* AppAccBytePosition */}, /*DrvAutoGearDisp*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1312u/* AppAccBytePosition */}, /*DrvGearDispSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1313u/* AppAccBytePosition */}, /*RollingCounter_DCT7*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1314u/* AppAccBytePosition */}, /*DCT_FD4_0x236*/
  {5u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1370u/* AppAccBytePosition */}, /*DrvWinPosnSts_Perc*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1371u/* AppAccBytePosition */}, /*DrvWinLrnSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1372u/* AppAccBytePosition */}, /*DrvWinHotProtSts*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1373u/* AppAccBytePosition */}, /*DrvSideRearWinLrnSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1374u/* AppAccBytePosition */}, /*DrvSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1375u/* AppAccBytePosition */}, /*DDCM1_0x2CA*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1383u/* AppAccBytePosition */}, /*DrvSideRearWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1384u/* AppAccBytePosition */}, /*DDCM3_0x2F7*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1392u/* AppAccBytePosition */}, /*DOCK_ExternalDevice_P*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1456u/* AppAccBytePosition */}, /*DOCK1_0x311*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1520u/* AppAccBytePosition */}, /*DOCK_HUT_ExternalDevice_E*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1584u/* AppAccBytePosition */}, /*DOCK2_0x1DF*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1648u/* AppAccBytePosition */}, /*DrvSeatMassLvlSetSts*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1649u/* AppAccBytePosition */}, /*DrvSeatMassModeSts*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1650u/* AppAccBytePosition */}, /*PassSeatMassgLvlSetSts*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1651u/* AppAccBytePosition */}, /*RLSeatMassgLvlSetSts*/
  {3u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1652u/* AppAccBytePosition */}, /*RRSeatMassgLvlSetSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1653u/* AppAccBytePosition */}, /*PassSeatMassgModeSts*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1654u/* AppAccBytePosition */}, /*RLSeatMassgModSts*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1655u/* AppAccBytePosition */}, /*RRSeatMassgModSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1656u/* AppAccBytePosition */}, /*DSC4_0x2CE*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1664u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1665u/* AppAccBytePosition */}, /*ChairRestSetSwtFB*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1666u/* AppAccBytePosition */}, /*ChairEndSetSwt*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1667u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB_Pass*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1668u/* AppAccBytePosition */}, /*DSM1_0x2C1*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1676u/* AppAccBytePosition */}, /*DWD_WorkSts*/
  {5u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1677u/* AppAccBytePosition */}, /*DWD_TextDisp*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1678u/* AppAccBytePosition */}, /*DWD_Dis*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1679u/* AppAccBytePosition */}, /*DWD_SoundIndcn*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1680u/* AppAccBytePosition */}, /*RSnsrFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1681u/* AppAccBytePosition */}, /*LSnsrFailSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1682u/* AppAccBytePosition */}, /*DWD1_0x2B9*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1690u/* AppAccBytePosition */}, /*EB_TgtRcprtnTrqSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1691u/* AppAccBytePosition */}, /*EBOOSTER_FD1_0x12D*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1755u/* AppAccBytePosition */}, /*EMS_AuthenResult*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1756u/* AppAccBytePosition */}, /*EngSpd*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1758u/* AppAccBytePosition */}, /*EngSpdVldty*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1759u/* AppAccBytePosition */}, /*BrkPedalSts*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1760u/* AppAccBytePosition */}, /*EngSpd_PHEV*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1762u/* AppAccBytePosition */}, /*EngSpdVldty_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1763u/* AppAccBytePosition */}, /*ECM1_0x111*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1771u/* AppAccBytePosition */}, /*FuelConsumption*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1773u/* AppAccBytePosition */}, /*TgtCrsVehSpd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1774u/* AppAccBytePosition */}, /*CruiseCtrlSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1775u/* AppAccBytePosition */}, /*AccelPedalPosn*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1776u/* AppAccBytePosition */}, /*AccelPedalPosnVldty*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1777u/* AppAccBytePosition */}, /*ThrtlPosRatio*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1778u/* AppAccBytePosition */}, /*EngSVSSig*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1779u/* AppAccBytePosition */}, /*MILSts*/
  {2u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1780u/* AppAccBytePosition */}, /*EngState*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1781u/* AppAccBytePosition */}, /*ECM2_0x271*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1789u/* AppAccBytePosition */}, /*BaroPressure*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1790u/* AppAccBytePosition */}, /*EngCoolantTemp*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1791u/* AppAccBytePosition */}, /*GPF_Warning*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1792u/* AppAccBytePosition */}, /*GentrWarnLmpSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1793u/* AppAccBytePosition */}, /*EngClntTempWarn*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1794u/* AppAccBytePosition */}, /*EngClntTempVldty*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1795u/* AppAccBytePosition */}, /*SS_Screen_tip*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1796u/* AppAccBytePosition */}, /*SSSSetSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1797u/* AppAccBytePosition */}, /*SS_Enable_Lamp*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1798u/* AppAccBytePosition */}, /*SS_Fault_Lamp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1799u/* AppAccBytePosition */}, /*MaxEngTrqNorm*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1800u/* AppAccBytePosition */}, /*AGS_Failure*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1801u/* AppAccBytePosition */}, /*ECM3_0x371*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1809u/* AppAccBytePosition */}, /*NetEngTrq*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1811u/* AppAccBytePosition */}, /*DrvEngTrqReq*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1813u/* AppAccBytePosition */}, /*DrvEngTrqReqVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1814u/* AppAccBytePosition */}, /*ECM4_0x82*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1822u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x84*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1823u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x84*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1824u/* AppAccBytePosition */}, /*EngTrqEstimdActGear*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1826u/* AppAccBytePosition */}, /*EngTrqEstimdActGear_Qf*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1827u/* AppAccBytePosition */}, /*ECM7_0x84*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1835u/* AppAccBytePosition */}, /*AccelPedlPosnDiagc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1836u/* AppAccBytePosition */}, /*ECM9_0x102*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1844u/* AppAccBytePosition */}, /*EngSpd_ForIP*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1846u/* AppAccBytePosition */}, /*EWP_Err*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1847u/* AppAccBytePosition */}, /*ECM_OffroadThmSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1848u/* AppAccBytePosition */}, /*ECM11_0x2D3*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1856u/* AppAccBytePosition */}, /*DPF_Warning*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1857u/* AppAccBytePosition */}, /*WIFSensorFailSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1858u/* AppAccBytePosition */}, /*GlowPlugLmpCmd*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1859u/* AppAccBytePosition */}, /*UreaLampCmd*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1860u/* AppAccBytePosition */}, /*Urea_Level*/
  {12u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1861u/* AppAccBytePosition */}, /*UreaRemainDist*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1863u/* AppAccBytePosition */}, /*SCRSysWarnDisplay*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1864u/* AppAccBytePosition */}, /*WIFFullLmpCmd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1865u/* AppAccBytePosition */}, /*DPF_Activation*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1866u/* AppAccBytePosition */}, /*OilBoxSplySts*/
  {5u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1867u/* AppAccBytePosition */}, /*SCRSysWarnDisplay_B2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1868u/* AppAccBytePosition */}, /*ECM16_0x2D4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1876u/* AppAccBytePosition */}, /*ECM_VIN*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1884u/* AppAccBytePosition */}, /*ECM19_0x3B5*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 27u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1892u/* AppAccBytePosition */}, /*ECM_VehDstBackup*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1896u/* AppAccBytePosition */}, /*ECM20_0x3B7*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1904u/* AppAccBytePosition */}, /*EngOilLvlWrn*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1905u/* AppAccBytePosition */}, /*EngOilLowPresWrn*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1906u/* AppAccBytePosition */}, /*EngOilPres*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1907u/* AppAccBytePosition */}, /*EngOilTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1908u/* AppAccBytePosition */}, /*ECM24_0x350*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1916u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvl*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1918u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvlValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1919u/* AppAccBytePosition */}, /*ECM_PT5_0x8E*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1927u/* AppAccBytePosition */}, /*EngOilLvl*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1928u/* AppAccBytePosition */}, /*FTIVFault*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1929u/* AppAccBytePosition */}, /*FuelTankCapWarning*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1930u/* AppAccBytePosition */}, /*PressReliProgs*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1931u/* AppAccBytePosition */}, /*ECM_PT6_0x290*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1939u/* AppAccBytePosition */}, /*EngState_PHEV*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1940u/* AppAccBytePosition */}, /*CruiseCtrlSts_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1941u/* AppAccBytePosition */}, /*ECM_PT7_0x117*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1949u/* AppAccBytePosition */}, /*CurrDamprMode*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1950u/* AppAccBytePosition */}, /*WarnLmpReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1951u/* AppAccBytePosition */}, /*EDC1_0x2D9*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1959u/* AppAccBytePosition */}, /*TranPMode_Sts*/
  {3u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1960u/* AppAccBytePosition */}, /*Stat_PwrSv_Lvl*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1961u/* AppAccBytePosition */}, /*Dyn_PwrSv_Lvl*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1962u/* AppAccBytePosition */}, /*LvPwrSysErr*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1963u/* AppAccBytePosition */}, /*EEM1_0x2A8*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1971u/* AppAccBytePosition */}, /*FrntELDLckSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1972u/* AppAccBytePosition */}, /*RearELDLckSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1973u/* AppAccBytePosition */}, /*ELD1_0x152*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1981u/* AppAccBytePosition */}, /*CheckSum_EPB1*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1982u/* AppAccBytePosition */}, /*EPBErrSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1983u/* AppAccBytePosition */}, /*EPBRedLmpSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1984u/* AppAccBytePosition */}, /*EPBSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1985u/* AppAccBytePosition */}, /*EPBTextDisp*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1986u/* AppAccBytePosition */}, /*PressBrakePedalPointOut*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1987u/* AppAccBytePosition */}, /*RollingCounter_EPB1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1988u/* AppAccBytePosition */}, /*EPB1_0x16B*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1996u/* AppAccBytePosition */}, /*CheckSum_EPS1*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1997u/* AppAccBytePosition */}, /*EPS_FailSts*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1998u/* AppAccBytePosition */}, /*EPS_SteerMod*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1999u/* AppAccBytePosition */}, /*SteerCorrnRmn*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2000u/* AppAccBytePosition */}, /*SteerCorrnResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2001u/* AppAccBytePosition */}, /*RollingCounter_EPS1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2002u/* AppAccBytePosition */}, /*EPS_FD1_0x147*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2066u/* AppAccBytePosition */}, /*RotSteerWheel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2067u/* AppAccBytePosition */}, /*ESCL2_0x303*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2075u/* AppAccBytePosition */}, /*CCO_Warn*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2076u/* AppAccBytePosition */}, /*CCO_Active*/
  {5u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2077u/* AppAccBytePosition */}, /*CCO_TgtVel*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2078u/* AppAccBytePosition */}, /*EspFuncOffSts_mode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2079u/* AppAccBytePosition */}, /*ESP8_0x170*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2087u/* AppAccBytePosition */}, /*ESP_HMI_WarningOn*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2088u/* AppAccBytePosition */}, /*WadeModeWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2089u/* AppAccBytePosition */}, /*ESP11_0xC8*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2097u/* AppAccBytePosition */}, /*CheckSum_ESP2*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2098u/* AppAccBytePosition */}, /*HDCFault*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2099u/* AppAccBytePosition */}, /*HDCCtrl*/
  {2u/*BitLength*/, 98u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2100u/* AppAccBytePosition */}, /*AVHErrSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2101u/* AppAccBytePosition */}, /*AVHSts*/
  {1u/*BitLength*/, 103u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2102u/* AppAccBytePosition */}, /*CDPActv*/
  {5u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2103u/* AppAccBytePosition */}, /*DrivingModDis*/
  {5u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2104u/* AppAccBytePosition */}, /*DrivingModReq_ESP*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2105u/* AppAccBytePosition */}, /*Shift_N_Warn*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2106u/* AppAccBytePosition */}, /*Over_Spd_Warn*/
  {1u/*BitLength*/, 106u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2107u/* AppAccBytePosition */}, /*FourL_Warn*/
  {2u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2108u/* AppAccBytePosition */}, /*TAB_Sts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2109u/* AppAccBytePosition */}, /*RollingCounter_ESP2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2110u/* AppAccBytePosition */}, /*CheckSum_ESP1*/
  {1u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2111u/* AppAccBytePosition */}, /*ESPFuncOffSts*/
  {1u/*BitLength*/, 141u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2112u/* AppAccBytePosition */}, /*ESPActvInfoLmp*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2113u/* AppAccBytePosition */}, /*ESPFailSts*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2114u/* AppAccBytePosition */}, /*IMC_Actv*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2115u/* AppAccBytePosition */}, /*RollingCounter_ESP1*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2116u/* AppAccBytePosition */}, /*CheckSum_ABS3*/
  {1u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2117u/* AppAccBytePosition */}, /*ABSActv*/
  {1u/*BitLength*/, 335u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2118u/* AppAccBytePosition */}, /*ABSFailSts*/
  {1u/*BitLength*/, 334u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2119u/* AppAccBytePosition */}, /*EBDFailSts*/
  {1u/*BitLength*/, 333u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2120u/* AppAccBytePosition */}, /*VehSpdVld*/
  {13u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2121u/* AppAccBytePosition */}, /*VehSpd*/
  {1u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2123u/* AppAccBytePosition */}, /*VehOdoInfoSts*/
  {10u/*BitLength*/, 352u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2124u/* AppAccBytePosition */}, /*VehOdoInfo*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2126u/* AppAccBytePosition */}, /*RollingCounter_ABS3*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 2127u/* AppAccBytePosition */}, /*ESP_FD2_0x137*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2183u/* AppAccBytePosition */}, /*FFogLmpSts_F_Pbox*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2184u/* AppAccBytePosition */}, /*HiBeamSts_F_Pbox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2185u/* AppAccBytePosition */}, /*HoodSts_F_Pbox*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2186u/* AppAccBytePosition */}, /*LasHdLmpSts_F_Pbox*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2187u/* AppAccBytePosition */}, /*LHiBeamFailSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2188u/* AppAccBytePosition */}, /*RHiBeamFailSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2189u/* AppAccBytePosition */}, /*LLowBeamFailSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2190u/* AppAccBytePosition */}, /*LHeadLmpFailSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2191u/* AppAccBytePosition */}, /*RHeadLmpFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2192u/* AppAccBytePosition */}, /*RLowBeamFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2193u/* AppAccBytePosition */}, /*RLasHdLmpDiagSig*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2194u/* AppAccBytePosition */}, /*LLasHdLmpDiagSig*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2195u/* AppAccBytePosition */}, /*LowBeamSts_F_PBOX*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2196u/* AppAccBytePosition */}, /*WhistleSts_F_PBOX*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2197u/* AppAccBytePosition */}, /*F_PBox1_0x19B*/
  {14u/*BitLength*/, 74u/* BitPosition */, 2u/* ByteLength */, 9u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 28u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2205u/* AppAccBytePosition */}, /*U_BATT*/
  {2u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2207u/* AppAccBytePosition */}, /*I_RANGE*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2208u/* AppAccBytePosition */}, /*I_BATT*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2210u/* AppAccBytePosition */}, /*SOC*/
  {8u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2211u/* AppAccBytePosition */}, /*SOH_SUL*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2212u/* AppAccBytePosition */}, /*SOC_STATE*/
  {2u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2213u/* AppAccBytePosition */}, /*SOH_SUL_STATE*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2214u/* AppAccBytePosition */}, /*GW_FD1_0x2BB*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2278u/* AppAccBytePosition */}, /*ResetCount*/
  {88u/*BitLength*/, 40u/* BitPosition */, 11u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 30u/* InitValueIdx */, 11u/* AppAccBtyeLength */, 2280u/* AppAccBytePosition */}, /*CMACMessageInfo*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 27u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2291u/* AppAccBytePosition */}, /*TripCount*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2295u/* AppAccBytePosition */}, /*APS_PrkgMod*/
  {7u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2296u/* AppAccBytePosition */}, /*APS_ProcBar*/
  {1u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2297u/* AppAccBytePosition */}, /*APS_SwtSts*/
  {3u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2298u/* AppAccBytePosition */}, /*APS_SlotDisp*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2299u/* AppAccBytePosition */}, /*APS_SysSoundIndcn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2300u/* AppAccBytePosition */}, /*APS_PrkgTyp*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2301u/* AppAccBytePosition */}, /*APS_TextDisp*/
  {3u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2302u/* AppAccBytePosition */}, /*APS_WorkSts*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2303u/* AppAccBytePosition */}, /*APS_ESP_BrkDistance*/
  {1u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2305u/* AppAccBytePosition */}, /*MEB_AVHReq*/
  {1u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2306u/* AppAccBytePosition */}, /*LParaPrkgOutVald*/
  {1u/*BitLength*/, 282u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2307u/* AppAccBytePosition */}, /*RParaPrkgOutVald*/
  {1u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2308u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald*/
  {1u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2309u/* AppAccBytePosition */}, /*TailVertPrkgOutVald*/
  {3u/*BitLength*/, 277u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2310u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2311u/* AppAccBytePosition */}, /*P2P_PahDelSts*/
  {4u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2312u/* AppAccBytePosition */}, /*P2P_SelfDetErrCode*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2313u/* AppAccBytePosition */}, /*P2P_SelfDetSts*/
  {1u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2314u/* AppAccBytePosition */}, /*P2P_Pah1Avail*/
  {1u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2315u/* AppAccBytePosition */}, /*P2P_Pah2Avail*/
  {1u/*BitLength*/, 293u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2316u/* AppAccBytePosition */}, /*P2P_PrkgDirectSts*/
  {4u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2317u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts*/
  {2u/*BitLength*/, 294u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2318u/* AppAccBytePosition */}, /*APS_MovgDirc*/
  {2u/*BitLength*/, 366u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2319u/* AppAccBytePosition */}, /*ParallelSlotBtn_Ena*/
  {2u/*BitLength*/, 364u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2320u/* AppAccBytePosition */}, /*VerticalSlotBtn_Ena*/
  {2u/*BitLength*/, 362u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2321u/* AppAccBytePosition */}, /*ClockwiseBtn_Ena*/
  {2u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2322u/* AppAccBytePosition */}, /*AnticlockwiseBtn_Ena*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2323u/* AppAccBytePosition */}, /*SlotConfirmBtn_Ena*/
  {2u/*BitLength*/, 330u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2324u/* AppAccBytePosition */}, /*HAVP_StartBtn_Ena*/
  {2u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2325u/* AppAccBytePosition */}, /*HAVP_StopBtn_Ena*/
  {2u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2326u/* AppAccBytePosition */}, /*HAVP_SelfParLotEnding_Ena*/
  {4u/*BitLength*/, 332u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2327u/* AppAccBytePosition */}, /*HAVP_WorkSts*/
  {6u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2328u/* AppAccBytePosition */}, /*PAVP_TextDis*/
  {4u/*BitLength*/, 340u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2329u/* AppAccBytePosition */}, /*PAVP_Status*/
  {6u/*BitLength*/, 354u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2330u/* AppAccBytePosition */}, /*PAVP_TextDis2*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2331u/* AppAccBytePosition */}, /*HAP_FD1_0x15B*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2395u/* AppAccBytePosition */}, /*AutoAVMSwtSet_Sts*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2396u/* AppAccBytePosition */}, /*AVM_CurrSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2397u/* AppAccBytePosition */}, /*GuidOvlSts*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2398u/* AppAccBytePosition */}, /*FrntCamInpFailSts*/
  {1u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2399u/* AppAccBytePosition */}, /*RearCamInpFailSts*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2400u/* AppAccBytePosition */}, /*LeCamInpFailSts*/
  {1u/*BitLength*/, 111u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2401u/* AppAccBytePosition */}, /*RiCamInpFailSts*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2402u/* AppAccBytePosition */}, /*EolNotCmpltd*/
  {1u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2403u/* AppAccBytePosition */}, /*OvlOpFailSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2404u/* AppAccBytePosition */}, /*LaneCalSts*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2405u/* AppAccBytePosition */}, /*RadarDispSts*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2406u/* AppAccBytePosition */}, /*LaneCalFltSts*/
  {1u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2407u/* AppAccBytePosition */}, /*AutoViewChgFuncSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2408u/* AppAccBytePosition */}, /*CarMdlTrsprcySts*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2409u/* AppAccBytePosition */}, /*CarMdlDispSts*/
  {1u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2410u/* AppAccBytePosition */}, /*CurrCalResultSts*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2411u/* AppAccBytePosition */}, /*MdlColrSts*/
  {6u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2412u/* AppAccBytePosition */}, /*SigViewIndcn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2413u/* AppAccBytePosition */}, /*HAP_DispCmd*/
  {9u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2414u/* AppAccBytePosition */}, /*AVM_3DAngSts*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2416u/* AppAccBytePosition */}, /*MOD_WorkSts*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2417u/* AppAccBytePosition */}, /*MOD_AlarmSts*/
  {2u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2418u/* AppAccBytePosition */}, /*DVRWorkSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2419u/* AppAccBytePosition */}, /*HAP_Hmi_Index*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2420u/* AppAccBytePosition */}, /*HAP_FD2_0x274*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2484u/* AppAccBytePosition */}, /*HAVP_ProcRa*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2485u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn*/
  {7u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2486u/* AppAccBytePosition */}, /*P2P_ProcBar*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2487u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1*/
  {4u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2488u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2489u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3*/
  {4u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2490u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2491u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2492u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2493u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2*/
  {4u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2494u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2495u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4*/
  {4u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2496u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2497u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2498u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2499u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2500u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2501u/* AppAccBytePosition */}, /*SDW_SoundIndcn*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2502u/* AppAccBytePosition */}, /*SDWActiveSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2503u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1*/
  {4u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2504u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2*/
  {4u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2505u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1*/
  {4u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2506u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2507u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2508u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2509u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1*/
  {4u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2510u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2511u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2512u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2513u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2514u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2515u/* AppAccBytePosition */}, /*RPAS_WorkSts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2516u/* AppAccBytePosition */}, /*RPAS_SoundIndcn*/
  {2u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2517u/* AppAccBytePosition */}, /*MEBWorkSts*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2518u/* AppAccBytePosition */}, /*MEB_EnableSts*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2519u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2520u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2*/
  {4u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2521u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1*/
  {4u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2522u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2523u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2524u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2*/
  {4u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2525u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1*/
  {4u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2526u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2*/
  {1u/*BitLength*/, 239u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2527u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts*/
  {1u/*BitLength*/, 238u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2528u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 237u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2529u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 236u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2530u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts*/
  {2u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2531u/* AppAccBytePosition */}, /*FPAS_WorkSts*/
  {1u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2532u/* AppAccBytePosition */}, /*FPAS_AutoModSts*/
  {2u/*BitLength*/, 246u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2533u/* AppAccBytePosition */}, /*FPAS_SoundIndcn*/
  {7u/*BitLength*/, 252u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2534u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn*/
  {4u/*BitLength*/, 276u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2535u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2536u/* AppAccBytePosition */}, /*APA_FuncSts*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2537u/* AppAccBytePosition */}, /*P2P_FuncSts*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2538u/* AppAccBytePosition */}, /*RADS_FuncSts*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2539u/* AppAccBytePosition */}, /*FADS_FuncSts*/
  {2u/*BitLength*/, 274u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2540u/* AppAccBytePosition */}, /*HAP_TextIconDispCtrl*/
  {1u/*BitLength*/, 447u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2541u/* AppAccBytePosition */}, /*FrntCamDirtySts*/
  {1u/*BitLength*/, 446u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2542u/* AppAccBytePosition */}, /*RearCamDirtySts*/
  {1u/*BitLength*/, 445u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2543u/* AppAccBytePosition */}, /*LeCamDirtySts*/
  {1u/*BitLength*/, 444u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2544u/* AppAccBytePosition */}, /*RiCamDirtySts*/
  {1u/*BitLength*/, 432u/* BitPosition */, 1u/* ByteLength */, 54u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2545u/* AppAccBytePosition */}, /*DVRCamDirtySts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2546u/* AppAccBytePosition */}, /*HAP_FD3_0x298*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2610u/* AppAccBytePosition */}, /*HAP_RtCam_WorkSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2611u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_ID*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2612u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_type*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2613u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Confidence*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2614u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2616u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2618u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_ID*/
  {3u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2619u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_type*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2620u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Confidence*/
  {12u/*BitLength*/, 92u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2621u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2623u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2625u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_ID*/
  {3u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2626u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_type*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2627u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Confidence*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2628u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2630u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2632u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_ID*/
  {3u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2633u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_type*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2634u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Confidence*/
  {12u/*BitLength*/, 220u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2635u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2637u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_Y*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2639u/* AppAccBytePosition */}, /*USS_FLSide1_Status*/
  {7u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2640u/* AppAccBytePosition */}, /*USS_FLSide1_Dist*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2641u/* AppAccBytePosition */}, /*USS_RLSide2_Status*/
  {7u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2642u/* AppAccBytePosition */}, /*USS_RLSide2_Dist*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2643u/* AppAccBytePosition */}, /*USS_FRSide1_Status*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2644u/* AppAccBytePosition */}, /*USS_FRSide1_Dist*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2645u/* AppAccBytePosition */}, /*USS_RRSide2_Status*/
  {7u/*BitLength*/, 297u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2646u/* AppAccBytePosition */}, /*USS_RRSide2_Dist*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2647u/* AppAccBytePosition */}, /*HAP_FD6_0x289*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2711u/* AppAccBytePosition */}, /*HAVP_LrngDst*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2712u/* AppAccBytePosition */}, /*HAVP_HUT_TextDisp*/
  {5u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2713u/* AppAccBytePosition */}, /*HAVP_ScFail_info*/
  {5u/*BitLength*/, 363u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2714u/* AppAccBytePosition */}, /*PAVP_ScFail_info*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2715u/* AppAccBytePosition */}, /*HAP_FD7_0x29B*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2779u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_Diag*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2780u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_DiagValid*/
  {5u/*BitLength*/, 299u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2781u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x60*/
  {3u/*BitLength*/, 317u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2782u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x60*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2783u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x60*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2784u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2785u/* AppAccBytePosition */}, /*HCU_AccelPedalPosnValid*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2786u/* AppAccBytePosition */}, /*HCU_FD1_0x60*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2850u/* AppAccBytePosition */}, /*HCU_BattLowTemWarn*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2851u/* AppAccBytePosition */}, /*HCU_BattLowHeatSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2852u/* AppAccBytePosition */}, /*HCU_BattLowTempWarn*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2853u/* AppAccBytePosition */}, /*HCU_BattLowTempHeatSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2854u/* AppAccBytePosition */}, /*HCU_HC3_0x268*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2862u/* AppAccBytePosition */}, /*HCU_ACLineDisconnect*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2863u/* AppAccBytePosition */}, /*HCU_ChargSts*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2864u/* AppAccBytePosition */}, /*HCU_IntelBattTempMagSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2865u/* AppAccBytePosition */}, /*HCU_HC6_0x314*/
  {10u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2873u/* AppAccBytePosition */}, /*HCU_RecupPwr*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2875u/* AppAccBytePosition */}, /*HCU_EVContnsDistance*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2876u/* AppAccBytePosition */}, /*HCU_EVContnsDistanceVld*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2877u/* AppAccBytePosition */}, /*HCU_EgyUsed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2879u/* AppAccBytePosition */}, /*HCU_HC7_0x3C2*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2887u/* AppAccBytePosition */}, /*HCU_TotalScore*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2888u/* AppAccBytePosition */}, /*HCU_HC8_0x1E2*/
  {4u/*BitLength*/, 46u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2896u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x9e*/
  {8u/*BitLength*/, 34u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2897u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x9e*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2898u/* AppAccBytePosition */}, /*TgtRcprtnTrqSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2899u/* AppAccBytePosition */}, /*HCU_HC16_0x9E*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2907u/* AppAccBytePosition */}, /*HCU_SOCMngmntSts*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2908u/* AppAccBytePosition */}, /*HCU_ARFSts*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2909u/* AppAccBytePosition */}, /*HCU_ASFCSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2910u/* AppAccBytePosition */}, /*HCU_AGSSts*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2911u/* AppAccBytePosition */}, /*PDCU_AvailabilityOfARF*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2912u/* AppAccBytePosition */}, /*PDCU_lossenPedalPrompt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2913u/* AppAccBytePosition */}, /*PDCU_EvSave_disl*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2914u/* AppAccBytePosition */}, /*HCU_HP5_0x201*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2922u/* AppAccBytePosition */}, /*HCU_HybMod*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2923u/* AppAccBytePosition */}, /*HCU_HybFctnMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2924u/* AppAccBytePosition */}, /*HCU_HP6_0x11A*/
  {9u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2932u/* AppAccBytePosition */}, /*HCU_TrqLimMax_Norm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2934u/* AppAccBytePosition */}, /*HCU_HP8_0xF9*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 33u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2942u/* AppAccBytePosition */}, /*HCU_TotalScore_P0*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2943u/* AppAccBytePosition */}, /*HCU_GearChngPorNTXT*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2944u/* AppAccBytePosition */}, /*HCU_SOCLow_Indcn*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2945u/* AppAccBytePosition */}, /*HCU_RemoveChrgLine_Indcn*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2946u/* AppAccBytePosition */}, /*HCU_Shift_P_Indcn*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2947u/* AppAccBytePosition */}, /*HCU_ConnectChrgLine_Indcn*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2948u/* AppAccBytePosition */}, /*HCU_EgyRecFB*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2949u/* AppAccBytePosition */}, /*HCU_OilTankCoverSts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2950u/* AppAccBytePosition */}, /*HCU_InhbChrgInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2951u/* AppAccBytePosition */}, /*ImdtlyChrgSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2952u/* AppAccBytePosition */}, /*HCU_EnerSavePowerMod*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2953u/* AppAccBytePosition */}, /*HCU_RefuReq*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2954u/* AppAccBytePosition */}, /*HCU_OPDFail*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2955u/* AppAccBytePosition */}, /*OPDParkWarnReq*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2956u/* AppAccBytePosition */}, /*HCU_ACStsReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2957u/* AppAccBytePosition */}, /*HCU_PT4_0x2FA*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2965u/* AppAccBytePosition */}, /*HCUImmoAuthRes*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2966u/* AppAccBytePosition */}, /*HCU_EVLmpSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2967u/* AppAccBytePosition */}, /*HCU_ECODrvHabit_Indcn*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2968u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x14a*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2969u/* AppAccBytePosition */}, /*HCU_AvailPower_TM*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2970u/* AppAccBytePosition */}, /*HCU_DrvMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2971u/* AppAccBytePosition */}, /*HCU_PT5_0x14A*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2979u/* AppAccBytePosition */}, /*HCU_12VSysErr_1*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2980u/* AppAccBytePosition */}, /*HCU_12VSysErr_2*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2981u/* AppAccBytePosition */}, /*HCU_HybSysErr_1*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2982u/* AppAccBytePosition */}, /*HCU_HybSysErr_2*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2983u/* AppAccBytePosition */}, /*HCU_HybSysErr_5*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2984u/* AppAccBytePosition */}, /*HCU_HybSysErr_6*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2985u/* AppAccBytePosition */}, /*HCU_HybSysErr_7*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2986u/* AppAccBytePosition */}, /*HCU_12VSysErrLmpSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2987u/* AppAccBytePosition */}, /*HCU_HybSysErrLmpSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2988u/* AppAccBytePosition */}, /*HCU_PowerRedWarnLmpCmd*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2989u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2990u/* AppAccBytePosition */}, /*HCU_HybSysErr_3*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2991u/* AppAccBytePosition */}, /*HCU_RdyLmpSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2992u/* AppAccBytePosition */}, /*CheckSum_HCU_PT7*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2993u/* AppAccBytePosition */}, /*HCU_HybSysErr_4*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2994u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd_P2*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2995u/* AppAccBytePosition */}, /*HCU_12VSysErr_3*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2996u/* AppAccBytePosition */}, /*HCU_OPDLmpSts*/
  {3u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2997u/* AppAccBytePosition */}, /*HCU_OPDSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2998u/* AppAccBytePosition */}, /*HCU_ModSwtFail*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2999u/* AppAccBytePosition */}, /*RollingCounter_HCU_PT7*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3000u/* AppAccBytePosition */}, /*HCU_PT7_0x248*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3008u/* AppAccBytePosition */}, /*HCU_ChrgSysLmpSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3009u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_1*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3010u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_2*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3011u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_3*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3012u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_4*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3013u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_5*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3014u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_6*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3015u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_7*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3016u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_8*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3017u/* AppAccBytePosition */}, /*HCU_DrvModDisp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3018u/* AppAccBytePosition */}, /*HCU_PT8_0x1C0*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3026u/* AppAccBytePosition */}, /*HUD_SwtSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 34u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3027u/* AppAccBytePosition */}, /*HUD_BrightnessLvl*/
  {5u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3028u/* AppAccBytePosition */}, /*HUD_HeightLvl*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3029u/* AppAccBytePosition */}, /*HUD_UIMod*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3030u/* AppAccBytePosition */}, /*HUD_UIModVld*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3031u/* AppAccBytePosition */}, /*HUD_Manufactor*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3032u/* AppAccBytePosition */}, /*HUD_ReslType*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3033u/* AppAccBytePosition */}, /*HUD1_0x325*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3041u/* AppAccBytePosition */}, /*IFCTrqOvlCmdProtnValue*/
  {11u/*BitLength*/, 45u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3043u/* AppAccBytePosition */}, /*IFCTrqOvlCmdReqValue*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3045u/* AppAccBytePosition */}, /*IFC1_0x109*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3053u/* AppAccBytePosition */}, /*Checksum_IFC3*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3054u/* AppAccBytePosition */}, /*LDWResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3055u/* AppAccBytePosition */}, /*LKAResp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3056u/* AppAccBytePosition */}, /*LCKResp*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3057u/* AppAccBytePosition */}, /*ELKResp*/
  {2u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3058u/* AppAccBytePosition */}, /*LDW_LKA_Snvty*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3059u/* AppAccBytePosition */}, /*IFCHUTInterface*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3060u/* AppAccBytePosition */}, /*LSSWarnFormResp*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3061u/* AppAccBytePosition */}, /*LSSResp*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3062u/* AppAccBytePosition */}, /*AESSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3063u/* AppAccBytePosition */}, /*ESSSts*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3064u/* AppAccBytePosition */}, /*AESErrSts*/
  {1u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3065u/* AppAccBytePosition */}, /*ESSErrSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3066u/* AppAccBytePosition */}, /*RollingCounter_IFC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3067u/* AppAccBytePosition */}, /*Checksum_IFC4*/
  {3u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3068u/* AppAccBytePosition */}, /*IFC_Handsoffwarn*/
  {2u/*BitLength*/, 153u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3069u/* AppAccBytePosition */}, /*IFCCalibrationSts*/
  {1u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3070u/* AppAccBytePosition */}, /*CameraBlockageSts*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3071u/* AppAccBytePosition */}, /*LDW_LKAWarn*/
  {3u/*BitLength*/, 139u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3072u/* AppAccBytePosition */}, /*LSSIntervention*/
  {3u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3073u/* AppAccBytePosition */}, /*LSSFuncSts*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3074u/* AppAccBytePosition */}, /*ELKMainState*/
  {2u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3075u/* AppAccBytePosition */}, /*LaneAvailability*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3076u/* AppAccBytePosition */}, /*TJA_FollowSts*/
  {3u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3077u/* AppAccBytePosition */}, /*LSSErrSts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3078u/* AppAccBytePosition */}, /*AESintervention*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3079u/* AppAccBytePosition */}, /*ESSintervention*/
  {2u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3080u/* AppAccBytePosition */}, /*ELKActSts*/
  {2u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3081u/* AppAccBytePosition */}, /*IntelligentEvaActSts*/
  {2u/*BitLength*/, 162u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3082u/* AppAccBytePosition */}, /*LCKStsIndcr*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3083u/* AppAccBytePosition */}, /*RollingCounter_IFC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3084u/* AppAccBytePosition */}, /*Checksum_IFC5*/
  {12u/*BitLength*/, 212u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3085u/* AppAccBytePosition */}, /*IFC_LaneCurve*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3087u/* AppAccBytePosition */}, /*IFC_LeLaneTyp*/
  {3u/*BitLength*/, 222u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3088u/* AppAccBytePosition */}, /*IFC_RiLaneTyp*/
  {3u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3089u/* AppAccBytePosition */}, /*IFC_NextLeLaneTyp*/
  {3u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3090u/* AppAccBytePosition */}, /*IFC_NextRiLaneTyp*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3091u/* AppAccBytePosition */}, /*IFC_LeLane_dy*/
  {12u/*BitLength*/, 240u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3093u/* AppAccBytePosition */}, /*IFC_RiLane_dy*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3095u/* AppAccBytePosition */}, /*RollingCounter_IFC5*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3096u/* AppAccBytePosition */}, /*Checksum_IFC6*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3097u/* AppAccBytePosition */}, /*IFC_NextLeLane_dy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3099u/* AppAccBytePosition */}, /*IFC_NextRiLane_dy*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3101u/* AppAccBytePosition */}, /*RollingCounter_IFC6*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3102u/* AppAccBytePosition */}, /*AESResp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3103u/* AppAccBytePosition */}, /*ESS_Pedresp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3104u/* AppAccBytePosition */}, /*ESS_Vehresp*/
  {1u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3105u/* AppAccBytePosition */}, /*IntelligentEvaResp*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 3106u/* AppAccBytePosition */}, /*IFC_FD2_0x23D*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3162u/* AppAccBytePosition */}, /*TSRResp*/
  {2u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3163u/* AppAccBytePosition */}, /*TSRSpdLimUnit*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3164u/* AppAccBytePosition */}, /*TSRSpdLim*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3165u/* AppAccBytePosition */}, /*TSRSpdLimCfdc*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3166u/* AppAccBytePosition */}, /*TSRSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3167u/* AppAccBytePosition */}, /*TSRSpdLimSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3168u/* AppAccBytePosition */}, /*TSRTrfcSignValCfdc*/
  {8u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3169u/* AppAccBytePosition */}, /*TSRTrfcSignVal*/
  {1u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3170u/* AppAccBytePosition */}, /*TSRSpdLimWarn*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3171u/* AppAccBytePosition */}, /*TSRWarnResp*/
  {5u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3172u/* AppAccBytePosition */}, /*TSR_Snvty*/
  {2u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3173u/* AppAccBytePosition */}, /*IDC_L2_TurnLightReq*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3174u/* AppAccBytePosition */}, /*HWA_ALC_Trig*/
  {4u/*BitLength*/, 138u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3175u/* AppAccBytePosition */}, /*HWA_WarnInfoDisp*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3176u/* AppAccBytePosition */}, /*HWA_TakOver_Trig*/
  {2u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3177u/* AppAccBytePosition */}, /*HWA_TakOver_Req*/
  {4u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3178u/* AppAccBytePosition */}, /*MRC_InterSysInfoDisp*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3179u/* AppAccBytePosition */}, /*MRC_TakOver_Req*/
  {4u/*BitLength*/, 154u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3180u/* AppAccBytePosition */}, /*NOH_WarnInfoDisp*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3181u/* AppAccBytePosition */}, /*IFC_Line01_Source*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3182u/* AppAccBytePosition */}, /*IFC_Line02_Source*/
  {2u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3183u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Posn*/
  {2u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3184u/* AppAccBytePosition */}, /*Stop_Mark_Detn*/
  {9u/*BitLength*/, 175u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3185u/* AppAccBytePosition */}, /*Stop_Mark_Dx*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3187u/* AppAccBytePosition */}, /*Zebra_Mark_Detn*/
  {2u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3188u/* AppAccBytePosition */}, /*Grid_Mark_Detn*/
  {3u/*BitLength*/, 181u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3189u/* AppAccBytePosition */}, /*HWA_InhibitWarn*/
  {1u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3190u/* AppAccBytePosition */}, /*LaneChngCfmSwt_Resp*/
  {1u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3191u/* AppAccBytePosition */}, /*ALC_SwtReq_Resp*/
  {1u/*BitLength*/, 191u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3192u/* AppAccBytePosition */}, /*AutoSpdSetSwt_Resp*/
  {1u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3193u/* AppAccBytePosition */}, /*VoiceBrdcSwt_Resp*/
  {4u/*BitLength*/, 177u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3194u/* AppAccBytePosition */}, /*UsrManSts_Resp*/
  {9u/*BitLength*/, 215u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3195u/* AppAccBytePosition */}, /*Grid_Mark_Dx*/
  {9u/*BitLength*/, 231u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3197u/* AppAccBytePosition */}, /*Zebra_Mark_Dx*/
  {2u/*BitLength*/, 213u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3199u/* AppAccBytePosition */}, /*TSR_Traffic_Light*/
  {2u/*BitLength*/, 211u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3200u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Through*/
  {2u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3201u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Le*/
  {2u/*BitLength*/, 229u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3202u/* AppAccBytePosition */}, /*TSR_Traffic_Light_Ri*/
  {1u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3203u/* AppAccBytePosition */}, /*RainMode_Swt_Resp*/
  {2u/*BitLength*/, 226u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3204u/* AppAccBytePosition */}, /*LCMode_Swt_Resp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3205u/* AppAccBytePosition */}, /*IFC_FD3_0x2CF*/
  {13u/*BitLength*/, 19u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3269u/* AppAccBytePosition */}, /*IFC_Line01_Dy*/
  {15u/*BitLength*/, 36u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3271u/* AppAccBytePosition */}, /*IFC_Line01_Curv*/
  {20u/*BitLength*/, 48u/* BitPosition */, 3u/* ByteLength */, 6u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3273u/* AppAccBytePosition */}, /*IFC_Line01_CurvChange*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3277u/* AppAccBytePosition */}, /*IFC_Line01_Type*/
  {13u/*BitLength*/, 83u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3278u/* AppAccBytePosition */}, /*IFC_Line02_Dy*/
  {15u/*BitLength*/, 100u/* BitPosition */, 3u/* ByteLength */, 12u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3280u/* AppAccBytePosition */}, /*IFC_Line02_Curv*/
  {20u/*BitLength*/, 112u/* BitPosition */, 3u/* ByteLength */, 14u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3282u/* AppAccBytePosition */}, /*IFC_Line02_CurvChange*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3286u/* AppAccBytePosition */}, /*IFC_Line02_Type*/
  {13u/*BitLength*/, 147u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3287u/* AppAccBytePosition */}, /*IFC_Line03_Dy*/
  {15u/*BitLength*/, 164u/* BitPosition */, 3u/* ByteLength */, 20u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3289u/* AppAccBytePosition */}, /*IFC_Line03_Curv*/
  {20u/*BitLength*/, 176u/* BitPosition */, 3u/* ByteLength */, 22u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3291u/* AppAccBytePosition */}, /*IFC_Line03_CurvChange*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3295u/* AppAccBytePosition */}, /*IFC_Line03_Type*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3296u/* AppAccBytePosition */}, /*IFC_Line04_Dy*/
  {15u/*BitLength*/, 228u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3298u/* AppAccBytePosition */}, /*IFC_Line04_Curv*/
  {20u/*BitLength*/, 240u/* BitPosition */, 3u/* ByteLength */, 30u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3300u/* AppAccBytePosition */}, /*IFC_Line04_CurvChange*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3304u/* AppAccBytePosition */}, /*IFC_Line04_Type*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3305u/* AppAccBytePosition */}, /*IFC_Roadedge01_Dy*/
  {15u/*BitLength*/, 292u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3307u/* AppAccBytePosition */}, /*IFC_Roadedge01_Curv*/
  {20u/*BitLength*/, 304u/* BitPosition */, 3u/* ByteLength */, 38u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3309u/* AppAccBytePosition */}, /*IFC_Roadedge01_CurvChange*/
  {4u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3313u/* AppAccBytePosition */}, /*IFC_Roadedge01_Type*/
  {13u/*BitLength*/, 339u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3314u/* AppAccBytePosition */}, /*IFC_Roadedge02_Dy*/
  {15u/*BitLength*/, 356u/* BitPosition */, 3u/* ByteLength */, 44u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3316u/* AppAccBytePosition */}, /*IFC_Roadedge02_Curv*/
  {20u/*BitLength*/, 368u/* BitPosition */, 3u/* ByteLength */, 46u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 3318u/* AppAccBytePosition */}, /*IFC_Roadedge02_CurvChange*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3322u/* AppAccBytePosition */}, /*IFC_Roadedge02_Type*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3323u/* AppAccBytePosition */}, /*IFC_FD5_0x19F*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3387u/* AppAccBytePosition */}, /*IFC_Line01_DxStart*/
  {15u/*BitLength*/, 34u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3389u/* AppAccBytePosition */}, /*IFC_Line01_DxEnd*/
  {9u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3391u/* AppAccBytePosition */}, /*IFC_Line01_HeadingAngle*/
  {9u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3393u/* AppAccBytePosition */}, /*IFC_Line02_HeadingAngle*/
  {15u/*BitLength*/, 81u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3395u/* AppAccBytePosition */}, /*IFC_Line02_DxStart*/
  {15u/*BitLength*/, 97u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3397u/* AppAccBytePosition */}, /*IFC_Line02_DxEnd*/
  {15u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3399u/* AppAccBytePosition */}, /*IFC_Line03_DxStart*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3401u/* AppAccBytePosition */}, /*IFC_Line03_DxEnd*/
  {9u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3403u/* AppAccBytePosition */}, /*IFC_Line03_HeadingAngle*/
  {15u/*BitLength*/, 169u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3405u/* AppAccBytePosition */}, /*IFC_Line04_DxStart*/
  {9u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3407u/* AppAccBytePosition */}, /*IFC_Line04_HeadingAngle*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3409u/* AppAccBytePosition */}, /*IFC_Line04_DxEnd*/
  {15u/*BitLength*/, 225u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3411u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxStart*/
  {15u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3413u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxEnd*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3415u/* AppAccBytePosition */}, /*IFC_Roadedge01_HeadingAngle*/
  {15u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3417u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxStart*/
  {15u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3419u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxEnd*/
  {9u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3421u/* AppAccBytePosition */}, /*IFC_Roadedge02_HeadingAngle*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3423u/* AppAccBytePosition */}, /*IFC_FD6_0x222*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3487u/* AppAccBytePosition */}, /*IB_Warn*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3488u/* AppAccBytePosition */}, /*BrkPedFeelMod*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3489u/* AppAccBytePosition */}, /*Ibooster_FD2_0x120*/
  {14u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 43u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3553u/* AppAccBytePosition */}, /*P2M_ActTrq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3555u/* AppAccBytePosition */}, /*P2M1_0xAC*/
  {16u/*BitLength*/, 60u/* BitPosition */, 3u/* ByteLength */, 7u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3563u/* AppAccBytePosition */}, /*P2M_ActSpd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3565u/* AppAccBytePosition */}, /*P2M3_0xBE*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3573u/* AppAccBytePosition */}, /*PassWinPosnSts_Perc*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3574u/* AppAccBytePosition */}, /*PassWinLrnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3575u/* AppAccBytePosition */}, /*PassWinHotProtSts*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3576u/* AppAccBytePosition */}, /*PassSideRearWinPosnSts_Perc*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3577u/* AppAccBytePosition */}, /*PassSideRearWinLrnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3578u/* AppAccBytePosition */}, /*PassSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3579u/* AppAccBytePosition */}, /*PDCM1_0x2CD*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3587u/* AppAccBytePosition */}, /*SysPowerMod*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3588u/* AppAccBytePosition */}, /*SysPowerModVld*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3589u/* AppAccBytePosition */}, /*PEPS_PowerRlyOutpSts*/
  {2u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3590u/* AppAccBytePosition */}, /*RemPowerFailureSts*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3591u/* AppAccBytePosition */}, /*RemUpgrdModSysPower*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3592u/* AppAccBytePosition */}, /*PEPS2_0x295*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3600u/* AppAccBytePosition */}, /*WarnPowerNotInOffPosn*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3601u/* AppAccBytePosition */}, /*WarnKeyInCarWhenExit*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3602u/* AppAccBytePosition */}, /*WarnVldKeyNotFound*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3603u/* AppAccBytePosition */}, /*WarnEngStrtNotMeet*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3604u/* AppAccBytePosition */}, /*PowerRlyFault*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3605u/* AppAccBytePosition */}, /*AntLostFlg*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3606u/* AppAccBytePosition */}, /*PEPS4_0x302*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3614u/* AppAccBytePosition */}, /*PPMIErrSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3615u/* AppAccBytePosition */}, /*HW_EnaSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3616u/* AppAccBytePosition */}, /*BSR_EnaSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3617u/* AppAccBytePosition */}, /*BSR_Sts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3618u/* AppAccBytePosition */}, /*HW_Sts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3619u/* AppAccBytePosition */}, /*VDS_Sts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3620u/* AppAccBytePosition */}, /*PP_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3621u/* AppAccBytePosition */}, /*PPMI1_0x35B*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3629u/* AppAccBytePosition */}, /*PPMI_P_ErrSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3630u/* AppAccBytePosition */}, /*PPMI_P_BSR_EnaSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3631u/* AppAccBytePosition */}, /*PPMI_P_BSR_Sts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3632u/* AppAccBytePosition */}, /*PPMI_P_VDS_Sts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3633u/* AppAccBytePosition */}, /*PPMI_P_PP_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3634u/* AppAccBytePosition */}, /*PPMI_P1_0x34F*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3642u/* AppAccBytePosition */}, /*RSDS_IPSoundReq*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3643u/* AppAccBytePosition */}, /*RSDS_ErrSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3644u/* AppAccBytePosition */}, /*RSDS_BrkgTrig*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3645u/* AppAccBytePosition */}, /*RSDS_BliSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3646u/* AppAccBytePosition */}, /*RSDS_TrailerSts*/
  {1u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3647u/* AppAccBytePosition */}, /*RSDS_LCAResp*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3648u/* AppAccBytePosition */}, /*RSDS_DOWResp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3649u/* AppAccBytePosition */}, /*RSDS_RCWResp*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3650u/* AppAccBytePosition */}, /*RSDS_RCTAResp*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3651u/* AppAccBytePosition */}, /*RSDS_RCTABrkResp*/
  {2u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3652u/* AppAccBytePosition */}, /*RSDS_RCW_Trigger*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3653u/* AppAccBytePosition */}, /*RSDS_CTA_Actv*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3654u/* AppAccBytePosition */}, /*BSD_LCA_warningReqRight*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3655u/* AppAccBytePosition */}, /*BSD_LCA_warningReqleft*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3656u/* AppAccBytePosition */}, /*DOW_warningReqRight*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3657u/* AppAccBytePosition */}, /*DOW_warningReqleft*/
  {1u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3658u/* AppAccBytePosition */}, /*RCTA_warningReqRight*/
  {1u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3659u/* AppAccBytePosition */}, /*RCTA_warningReqLeft*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3660u/* AppAccBytePosition */}, /*RSDS_FD1_0x16F*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3724u/* AppAccBytePosition */}, /*RCTA_B_TTC*/
  {6u/*BitLength*/, 20u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3725u/* AppAccBytePosition */}, /*BSD_LCA_Left_TTC*/
  {6u/*BitLength*/, 30u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3726u/* AppAccBytePosition */}, /*BSD_LCA_Right_TTC*/
  {6u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3727u/* AppAccBytePosition */}, /*RCW_TTC*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3728u/* AppAccBytePosition */}, /*RSDS_LeTgt_01*/
  {10u/*BitLength*/, 94u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3729u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dx*/
  {7u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3731u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dy*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3732u/* AppAccBytePosition */}, /*RSDS_LeTgt_02*/
  {10u/*BitLength*/, 99u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3733u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dx*/
  {7u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3735u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dy*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3736u/* AppAccBytePosition */}, /*RSDS_RiTgt_01*/
  {10u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3737u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dx*/
  {7u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3739u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dy*/
  {1u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3740u/* AppAccBytePosition */}, /*RSDS_RiTgt_02*/
  {10u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3741u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dx*/
  {7u/*BitLength*/, 167u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3743u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dy*/
  {1u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3744u/* AppAccBytePosition */}, /*RSDS_MidTgt_01*/
  {10u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3745u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dx*/
  {7u/*BitLength*/, 181u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3747u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dy*/
  {1u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3748u/* AppAccBytePosition */}, /*RSDS_MidTgt_02*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3749u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dx*/
  {7u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3751u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dy*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3752u/* AppAccBytePosition */}, /*RSDS_FD2_0x30A*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3816u/* AppAccBytePosition */}, /*RWPC_SwtSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3817u/* AppAccBytePosition */}, /*RWPC_FaultSts*/
  {2u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3818u/* AppAccBytePosition */}, /*RWPC_ChrgSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3819u/* AppAccBytePosition */}, /*RWPC1_0x35D*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3827u/* AppAccBytePosition */}, /*HiPosnBrkLmpFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3828u/* AppAccBytePosition */}, /*LBrkLmpFailSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3829u/* AppAccBytePosition */}, /*RFogLmpFailSts_R_Pbox*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3830u/* AppAccBytePosition */}, /*RFogLmpSts_R_Pbox*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3831u/* AppAccBytePosition */}, /*ParkLmpSts_R_Pbox*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3832u/* AppAccBytePosition */}, /*RBrkLmpFailSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3833u/* AppAccBytePosition */}, /*PosnLmpOutpSts_R_Pbox*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3834u/* AppAccBytePosition */}, /*RRPosnLmpFailSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3835u/* AppAccBytePosition */}, /*RvsLmpFailSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3836u/* AppAccBytePosition */}, /*LRPosnLmpFailSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3837u/* AppAccBytePosition */}, /*LTurnLmpSts_R_Pbox*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3838u/* AppAccBytePosition */}, /*RTurnLmpSts_R_Pbox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3839u/* AppAccBytePosition */}, /*RWinHeatgIconRlyCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3840u/* AppAccBytePosition */}, /*RWinHeatgFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3841u/* AppAccBytePosition */}, /*LicPlateLmpFailSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3842u/* AppAccBytePosition */}, /*RTurnLmpFailSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3843u/* AppAccBytePosition */}, /*LTurnLmpFailSts*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3844u/* AppAccBytePosition */}, /*LChildLockProtSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3845u/* AppAccBytePosition */}, /*RChildLockProtSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3846u/* AppAccBytePosition */}, /*RBrkLmpOutpSts_R_Pbox*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3847u/* AppAccBytePosition */}, /*HiPosnBrkLmpOutpSts_R_Pbox*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3848u/* AppAccBytePosition */}, /*LBrkLmpOutpSts_R_Pbox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3849u/* AppAccBytePosition */}, /*R_PBox1_0x19C*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3857u/* AppAccBytePosition */}, /*FuncProtnSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3858u/* AppAccBytePosition */}, /*ShiftSysStuInLow*/
  {4u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3859u/* AppAccBytePosition */}, /*SystemOperMod*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3860u/* AppAccBytePosition */}, /*CouplingFaultSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3861u/* AppAccBytePosition */}, /*CouplingThermWarning*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3862u/* AppAccBytePosition */}, /*DiagLmpReq*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3863u/* AppAccBytePosition */}, /*EstimatedTorque*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3865u/* AppAccBytePosition */}, /*ModeShiftTimeout*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3866u/* AppAccBytePosition */}, /*AutoShiftSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3867u/* AppAccBytePosition */}, /*TOD1_0x251*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3875u/* AppAccBytePosition */}, /*FLTirePressIndSts*/
  {3u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3876u/* AppAccBytePosition */}, /*FRTirePressIndSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3877u/* AppAccBytePosition */}, /*TirePressSysFailrIndcn*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3878u/* AppAccBytePosition */}, /*RLTirePressIndSts*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3879u/* AppAccBytePosition */}, /*RRTirePressIndSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3880u/* AppAccBytePosition */}, /*FLTireTempSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3881u/* AppAccBytePosition */}, /*FRTireTempSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3882u/* AppAccBytePosition */}, /*RLTireTempSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3883u/* AppAccBytePosition */}, /*RRTireTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3884u/* AppAccBytePosition */}, /*TPMS1_0x341*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3892u/* AppAccBytePosition */}, /*FLTirePress*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3893u/* AppAccBytePosition */}, /*FLTireTemp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3894u/* AppAccBytePosition */}, /*FRTirePress*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3895u/* AppAccBytePosition */}, /*FRTireTemp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3896u/* AppAccBytePosition */}, /*RLTirePress*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3897u/* AppAccBytePosition */}, /*RLTireTemp*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3898u/* AppAccBytePosition */}, /*RRTirePress*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3899u/* AppAccBytePosition */}, /*RRTireTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3900u/* AppAccBytePosition */}, /*TPMS2_0x395*/
  {3u/*BitLength*/, 5u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3908u/* AppAccBytePosition */}, /*T_BOX_RemtDoorLockCtrl*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3909u/* AppAccBytePosition */}, /*T_BOX_AudioMuteReq*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3910u/* AppAccBytePosition */}, /*T_BOX_PM25AirQLvl*/
  {10u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3911u/* AppAccBytePosition */}, /*T_BOX_PM25Dens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3913u/* AppAccBytePosition */}, /*T_BOX_FD1_0x33*/
  {5u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3921u/* AppAccBytePosition */}, /*T_BOX_SysErrSts*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3922u/* AppAccBytePosition */}, /*T_BOX_SWUpdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3923u/* AppAccBytePosition */}, /*T_BOX_FD3_0x3E9*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3931u/* AppAccBytePosition */}, /*T_BOX_RemtVideoMonrEnaReq_APP*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3932u/* AppAccBytePosition */}, /*T_BOX_FD4_0x1E1*/
  {5u/*BitLength*/, 62u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 126u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3948u/* AppAccBytePosition */}, /*T_BOX_ChrgTim_Day*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 126u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3949u/* AppAccBytePosition */}, /*T_BOX_FD9_0x1FE*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3957u/* AppAccBytePosition */}, /*V2X_FCW*/
  {4u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3958u/* AppAccBytePosition */}, /*V2X_BSW*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3959u/* AppAccBytePosition */}, /*V2X_LCW*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3960u/* AppAccBytePosition */}, /*V2X_EBW*/
  {4u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3961u/* AppAccBytePosition */}, /*V2X_ICW*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3962u/* AppAccBytePosition */}, /*V2X_LTA*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3963u/* AppAccBytePosition */}, /*V2X_IVSW*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3964u/* AppAccBytePosition */}, /*V2X_AVW*/
  {3u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3965u/* AppAccBytePosition */}, /*V2X_EVW*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3966u/* AppAccBytePosition */}, /*V2X_DNPW*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3967u/* AppAccBytePosition */}, /*V2X_HLW*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3968u/* AppAccBytePosition */}, /*V2X_TJW*/
  {6u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3969u/* AppAccBytePosition */}, /*V2X_CLW*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3970u/* AppAccBytePosition */}, /*V2X_RLVW*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3971u/* AppAccBytePosition */}, /*V2X_VRUCW*/
  {6u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3972u/* AppAccBytePosition */}, /*V2X_SLW*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3973u/* AppAccBytePosition */}, /*V2X_GLOSA*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3974u/* AppAccBytePosition */}, /*V2X_SL1_LightTyp*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3975u/* AppAccBytePosition */}, /*V2X_SL1_LightColor*/
  {16u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3976u/* AppAccBytePosition */}, /*V2X_SL1_LightTim*/
  {4u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3978u/* AppAccBytePosition */}, /*V2X_SL2_LightTyp*/
  {4u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3979u/* AppAccBytePosition */}, /*V2X_SL2_LightColor*/
  {16u/*BitLength*/, 144u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3980u/* AppAccBytePosition */}, /*V2X_SL2_LightTim*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3982u/* AppAccBytePosition */}, /*V2X_SL3_LightTyp*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3983u/* AppAccBytePosition */}, /*V2X_SL3_LightColor*/
  {16u/*BitLength*/, 168u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3984u/* AppAccBytePosition */}, /*V2X_SL3_LightTim*/
  {4u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3986u/* AppAccBytePosition */}, /*V2X_SL4_LightTyp*/
  {4u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3987u/* AppAccBytePosition */}, /*V2X_SL4_LightColor*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3988u/* AppAccBytePosition */}, /*V2X_SL5_LightTyp*/
  {16u/*BitLength*/, 208u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3989u/* AppAccBytePosition */}, /*V2X_SL4_LightTim*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3991u/* AppAccBytePosition */}, /*V2X_SL5_LightColor*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3992u/* AppAccBytePosition */}, /*V2X_SL5_LightTim*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3994u/* AppAccBytePosition */}, /*V2X_SL6_LightTyp*/
  {4u/*BitLength*/, 244u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3995u/* AppAccBytePosition */}, /*V2X_SL6_LightColor*/
  {16u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3996u/* AppAccBytePosition */}, /*V2X_SL6_LightTim*/
  {4u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3998u/* AppAccBytePosition */}, /*V2X_SL7_LightTyp*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3999u/* AppAccBytePosition */}, /*V2X_SL7_LightColor*/
  {16u/*BitLength*/, 288u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4000u/* AppAccBytePosition */}, /*V2X_SL7_LightTim*/
  {4u/*BitLength*/, 300u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4002u/* AppAccBytePosition */}, /*V2X_SL8_LightTyp*/
  {4u/*BitLength*/, 296u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4003u/* AppAccBytePosition */}, /*V2X_SL8_LightColor*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 4004u/* AppAccBytePosition */}, /*V2X_SL8_LightTim*/
  {4u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4006u/* AppAccBytePosition */}, /*V2X_SL_of_Veh*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 127u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 4007u/* AppAccBytePosition */}, /*T_Box_FD10_0x2F0*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 128u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4071u/* AppAccBytePosition */}, /*TrailerSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 128u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 4072u/* AppAccBytePosition */}, /*Trailer1_0x273*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 129u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4080u/* AppAccBytePosition */}, /*WPC_ChrgSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 129u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4081u/* AppAccBytePosition */}, /*WPC_SwtSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 129u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4082u/* AppAccBytePosition */}, /*WPC_FaultSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 129u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 4083u/* AppAccBytePosition */}, /*WPC_PhoneReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 129u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 4084u/* AppAccBytePosition */}, /*WPC1_0x2BA*/
};


const ComEx_RxGroupInfoType ComEx_RxGroupInfo[ComEx_RxGroupSize] = 
{
  {0u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*ABM1*/
  {11u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 1u/* E2eIdx */}, /*ACC3_ACC_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 2u/* E2eIdx */}, /*ACC4_ACC_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 3u/* E2eIdx */}, /*ACC8_ACC_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 4u/* E2eIdx */}, /*ACC6_ACC_FD2*/
  {11u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 5u/* E2eIdx */}, /*ACC7_ACC_FD2*/
  {15u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 6u/* E2eIdx */}, /*AEB2_AEB_FD2*/
  {15u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 7u/* E2eIdx */}, /*AEB3_AEB_FD2*/
  {16u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 8u/* E2eIdx */}, /*ALS1*/
  {33u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* E2eIdx */}, /*BMS4*/
  {49u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 10u/* E2eIdx */}, /*DCT_FD4*/
  {75u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 11u/* E2eIdx */}, /*EPB1*/
  {76u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 12u/* E2eIdx */}, /*EPS_FD1*/
  {80u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 13u/* E2eIdx */}, /*ESP2_ESP_FD2*/
  {80u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 14u/* E2eIdx */}, /*ESP1_ESP_FD2*/
  {80u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 15u/* E2eIdx */}, /*ABS3_ESP_FD2*/
  {100u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* E2eIdx */}, /*HCU_PT7*/
  {104u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 17u/* E2eIdx */}, /*IFC3_IFC_FD2*/
  {104u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 18u/* E2eIdx */}, /*IFC4_IFC_FD2*/
  {104u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 19u/* E2eIdx */}, /*IFC5_IFC_FD2*/
  {104u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 20u/* E2eIdx */}, /*IFC6_IFC_FD2*/
};


const ComEx_RxPduInfoType ComEx_RxPduInfo[ComEx_RxPduSize] = 
{
  {0u/* SignalStartIdx */, 15u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABM1*/
  {15u/* SignalStartIdx */, 22u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABM2*/
  {22u/* SignalStartIdx */, 33u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 16u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS1*/
  {33u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 24u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS2*/
  {44u/* SignalStartIdx */, 54u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 32u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC1*/
  {54u/* SignalStartIdx */, 68u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 40u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC2*/
  {68u/* SignalStartIdx */, 77u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 48u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC3*/
  {77u/* SignalStartIdx */, 83u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 56u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC4*/
  {83u/* SignalStartIdx */, 89u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 64u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC6*/
  {89u/* SignalStartIdx */, 96u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC7*/
  {96u/* SignalStartIdx */, 99u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 80u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC8*/
  {99u/* SignalStartIdx */, 186u/* SignalEndIdx */, 1u/* GroupStartIdx */, 6u/* GroupEndIdx */, 88u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ACC_FD2*/
  {186u/* SignalStartIdx */, 219u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD3*/
  {219u/* SignalStartIdx */, 288u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD4*/
  {288u/* SignalStartIdx */, 300u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AEB_FD1*/
  {300u/* SignalStartIdx */, 335u/* SignalEndIdx */, 6u/* GroupStartIdx */, 8u/* GroupEndIdx */, 336u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AEB_FD2*/
  {335u/* SignalStartIdx */, 339u/* SignalEndIdx */, 8u/* GroupStartIdx */, 9u/* GroupEndIdx */, 392u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ALS1*/
  {339u/* SignalStartIdx */, 355u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP1*/
  {355u/* SignalStartIdx */, 375u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AMP2*/
  {375u/* SignalStartIdx */, 382u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP3*/
  {382u/* SignalStartIdx */, 388u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP4_ANC1*/
  {388u/* SignalStartIdx */, 401u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM1*/
  {401u/* SignalStartIdx */, 407u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM3*/
  {407u/* SignalStartIdx */, 410u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM6*/
  {410u/* SignalStartIdx */, 413u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM7*/
  {413u/* SignalStartIdx */, 422u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 472u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM8*/
  {422u/* SignalStartIdx */, 429u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM11*/
  {429u/* SignalStartIdx */, 437u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 488u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM12*/
  {437u/* SignalStartIdx */, 444u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 496u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM14*/
  {444u/* SignalStartIdx */, 446u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 504u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM17*/
  {446u/* SignalStartIdx */, 449u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 512u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM19*/
  {449u/* SignalStartIdx */, 452u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 520u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE1*/
  {452u/* SignalStartIdx */, 454u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 528u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE5*/
  {454u/* SignalStartIdx */, 462u/* SignalEndIdx */, 9u/* GroupStartIdx */, 10u/* GroupEndIdx */, 536u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS4*/
  {462u/* SignalStartIdx */, 465u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 544u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS8*/
  {465u/* SignalStartIdx */, 468u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 552u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS19*/
  {468u/* SignalStartIdx */, 470u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 560u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS22*/
  {470u/* SignalStartIdx */, 472u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 568u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS30*/
  {472u/* SignalStartIdx */, 474u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 576u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS35*/
  {474u/* SignalStartIdx */, 476u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 584u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS65*/
  {476u/* SignalStartIdx */, 494u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS66*/
  {494u/* SignalStartIdx */, 496u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS_FD14*/
  {496u/* SignalStartIdx */, 500u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 608u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CP1*/
  {500u/* SignalStartIdx */, 508u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 616u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CR_FD1*/
  {508u/* SignalStartIdx */, 514u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 680u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA1*/
  {514u/* SignalStartIdx */, 518u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 688u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA2*/
  {518u/* SignalStartIdx */, 536u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA3*/
  {536u/* SignalStartIdx */, 539u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT3*/
  {539u/* SignalStartIdx */, 544u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 712u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT5*/
  {544u/* SignalStartIdx */, 559u/* SignalEndIdx */, 10u/* GroupStartIdx */, 11u/* GroupEndIdx */, 720u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*DCT_FD4*/
  {559u/* SignalStartIdx */, 565u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 776u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM1*/
  {565u/* SignalStartIdx */, 567u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 784u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM3*/
  {567u/* SignalStartIdx */, 569u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 792u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DOCK1*/
  {569u/* SignalStartIdx */, 571u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 856u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DOCK2*/
  {571u/* SignalStartIdx */, 580u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 920u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSC4*/
  {580u/* SignalStartIdx */, 585u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 928u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSM1*/
  {585u/* SignalStartIdx */, 592u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 936u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DWD1*/
  {592u/* SignalStartIdx */, 594u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 944u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EBOOSTER_FD1*/
  {594u/* SignalStartIdx */, 601u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1008u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM1*/
  {601u/* SignalStartIdx */, 611u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1016u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM2*/
  {611u/* SignalStartIdx */, 624u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1024u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM3*/
  {624u/* SignalStartIdx */, 628u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1032u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM4*/
  {628u/* SignalStartIdx */, 633u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1040u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM7*/
  {633u/* SignalStartIdx */, 635u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1048u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM9*/
  {635u/* SignalStartIdx */, 639u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1056u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM11*/
  {639u/* SignalStartIdx */, 651u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1064u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM16*/
  {651u/* SignalStartIdx */, 653u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1072u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM19*/
  {653u/* SignalStartIdx */, 655u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1080u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM20*/
  {655u/* SignalStartIdx */, 660u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1088u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM24*/
  {660u/* SignalStartIdx */, 663u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1096u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT5*/
  {663u/* SignalStartIdx */, 668u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1104u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT6*/
  {668u/* SignalStartIdx */, 671u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1112u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT7*/
  {671u/* SignalStartIdx */, 674u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1120u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EDC1*/
  {674u/* SignalStartIdx */, 679u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1128u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EEM1*/
  {679u/* SignalStartIdx */, 682u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1136u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ELD1*/
  {682u/* SignalStartIdx */, 690u/* SignalEndIdx */, 11u/* GroupStartIdx */, 12u/* GroupEndIdx */, 1144u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPB1*/
  {690u/* SignalStartIdx */, 697u/* SignalEndIdx */, 12u/* GroupStartIdx */, 13u/* GroupEndIdx */, 1152u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPS_FD1*/
  {697u/* SignalStartIdx */, 699u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1216u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESCL2*/
  {699u/* SignalStartIdx */, 704u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1224u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP8*/
  {704u/* SignalStartIdx */, 707u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1232u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP11*/
  {707u/* SignalStartIdx */, 736u/* SignalEndIdx */, 13u/* GroupStartIdx */, 16u/* GroupEndIdx */, 1240u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP_FD2*/
  {736u/* SignalStartIdx */, 751u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1296u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*F_PBox1*/
  {751u/* SignalStartIdx */, 759u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1304u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_FD1*/
  {759u/* SignalStartIdx */, 762u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1368u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 2/* CalloutStartIdx */}, /*GW_Sync_Req*/
  {762u/* SignalStartIdx */, 798u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1384u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD1*/
  {798u/* SignalStartIdx */, 823u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1448u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD2*/
  {823u/* SignalStartIdx */, 886u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1512u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD3*/
  {886u/* SignalStartIdx */, 916u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1576u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD6*/
  {916u/* SignalStartIdx */, 921u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1640u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD7*/
  {921u/* SignalStartIdx */, 929u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1704u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_FD1*/
  {929u/* SignalStartIdx */, 934u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1768u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC3*/
  {934u/* SignalStartIdx */, 938u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1776u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC6*/
  {938u/* SignalStartIdx */, 943u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1784u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC7*/
  {943u/* SignalStartIdx */, 945u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1792u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC8*/
  {945u/* SignalStartIdx */, 949u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1800u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC16*/
  {949u/* SignalStartIdx */, 957u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1808u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP5*/
  {957u/* SignalStartIdx */, 960u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1816u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP6*/
  {960u/* SignalStartIdx */, 962u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1824u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP8*/
  {962u/* SignalStartIdx */, 978u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1832u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT4*/
  {978u/* SignalStartIdx */, 985u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1840u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT5*/
  {985u/* SignalStartIdx */, 1007u/* SignalEndIdx */, 16u/* GroupStartIdx */, 17u/* GroupEndIdx */, 1848u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT7*/
  {1007u/* SignalStartIdx */, 1018u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1856u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT8*/
  {1018u/* SignalStartIdx */, 1026u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1864u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HUD1*/
  {1026u/* SignalStartIdx */, 1029u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1872u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC1*/
  {1029u/* SignalStartIdx */, 1078u/* SignalEndIdx */, 17u/* GroupStartIdx */, 21u/* GroupEndIdx */, 1880u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*IFC_FD2*/
  {1078u/* SignalStartIdx */, 1119u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1936u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD3*/
  {1119u/* SignalStartIdx */, 1144u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2000u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD5*/
  {1144u/* SignalStartIdx */, 1163u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2064u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD6*/
  {1163u/* SignalStartIdx */, 1166u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2128u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Ibooster_FD2*/
  {1166u/* SignalStartIdx */, 1168u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2192u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M1*/
  {1168u/* SignalStartIdx */, 1170u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2200u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M3*/
  {1170u/* SignalStartIdx */, 1177u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2208u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PDCM1*/
  {1177u/* SignalStartIdx */, 1183u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2216u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS2*/
  {1183u/* SignalStartIdx */, 1190u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2224u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS4*/
  {1190u/* SignalStartIdx */, 1198u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2232u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PPMI1*/
  {1198u/* SignalStartIdx */, 1204u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2240u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PPMI_P1*/
  {1204u/* SignalStartIdx */, 1223u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2248u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD1*/
  {1223u/* SignalStartIdx */, 1246u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2312u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD2*/
  {1246u/* SignalStartIdx */, 1250u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2376u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RWPC1*/
  {1250u/* SignalStartIdx */, 1273u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2384u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*R_PBox1*/
  {1273u/* SignalStartIdx */, 1283u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*TOD1*/
  {1283u/* SignalStartIdx */, 1293u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2400u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS1*/
  {1293u/* SignalStartIdx */, 1302u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2408u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS2*/
  {1302u/* SignalStartIdx */, 1307u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2416u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD1*/
  {1307u/* SignalStartIdx */, 1310u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2424u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD3*/
  {1310u/* SignalStartIdx */, 1312u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2432u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD4*/
  {1312u/* SignalStartIdx */, 1314u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD9*/
  {1314u/* SignalStartIdx */, 1357u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2456u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_Box_FD10*/
  {1357u/* SignalStartIdx */, 1359u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2520u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Trailer1*/
  {1359u/* SignalStartIdx */, 1364u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2528u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*WPC1*/
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
  {16u/* byteLength */, 148u/* bytePosition */},
  {1u/* byteLength */, 164u/* bytePosition */},
  {1u/* byteLength */, 165u/* bytePosition */},
  {1u/* byteLength */, 166u/* bytePosition */},
  {1u/* byteLength */, 167u/* bytePosition */},
  {1u/* byteLength */, 168u/* bytePosition */},
  {1u/* byteLength */, 169u/* bytePosition */},
  {2u/* byteLength */, 170u/* bytePosition */},
  {1u/* byteLength */, 172u/* bytePosition */},
  {4u/* byteLength */, 173u/* bytePosition */},
  {2u/* byteLength */, 177u/* bytePosition */},
  {2u/* byteLength */, 179u/* bytePosition */},
  {11u/* byteLength */, 181u/* bytePosition */},
  {1u/* byteLength */, 192u/* bytePosition */},
  {2u/* byteLength */, 193u/* bytePosition */},
  {1u/* byteLength */, 195u/* bytePosition */},
  {1u/* byteLength */, 196u/* bytePosition */},
  {2u/* byteLength */, 197u/* bytePosition */},
  {2u/* byteLength */, 199u/* bytePosition */},
  {2u/* byteLength */, 201u/* bytePosition */},
  {2u/* byteLength */, 203u/* bytePosition */},
  {2u/* byteLength */, 205u/* bytePosition */},
  {2u/* byteLength */, 207u/* bytePosition */},
  {4u/* byteLength */, 209u/* bytePosition */},
  {2u/* byteLength */, 213u/* bytePosition */},
  {2u/* byteLength */, 215u/* bytePosition */},
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
  {E2EPW_ReadInit_ALS1_E2E/* InitFunPtr */, E2EPW_Read_ALS1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_BMS4_E2E/* InitFunPtr */, E2EPW_Read_BMS4_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_DCT_FD4_E2E/* InitFunPtr */, E2EPW_Read_DCT_FD4_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPB1_E2E/* InitFunPtr */, E2EPW_Read_EPB1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPS_FD1_E2E/* InitFunPtr */, E2EPW_Read_EPS_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP2_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ESP2_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP1_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ESP1_ESP_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ABS3_ESP_FD2_E2E/* InitFunPtr */, E2EPW_Read_ABS3_ESP_FD2_E2E/* ReadFunPtr */},
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xau,
  0x2u,
  0x80u,
  0x7fu,
  0xb2u,
  0x6u,
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
  0x4u,
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
};

const uint8 ComEx_RxTimeoutBuffer[ComEx_RxTimeoutBufferSize] = 
{
  0
};

const uint8 ComEx_RxPduCalloutIdx[4] =
{
    0u, 2u, 1u, 2u
};

const ComEx_TxSigInfoType ComEx_TxSigInfo[ComEx_TxSignalSize]= 
{
  {3u/*BitLength*/, 11u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 9u/* BufferStartIdx */, 10u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvl*/
  {7u/*BitLength*/, 20u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 9u/* BufferStartIdx */, 11u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvlQlty*/
  {2u/*BitLength*/, 35u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GenderSts*/
  {7u/*BitLength*/, 41u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 13u/* BufferStartIdx */, 14u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GenderStsQlty*/
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExprsnSts*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 16u/* BufferStartIdx */, 17u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS2*/
  {3u/*BitLength*/, 93u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvl_ACC*/
  {7u/*BitLength*/, 73u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 17u/* BufferStartIdx */, 18u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DistrctnLvlQlty_ACC*/
  {3u/*BitLength*/, 90u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 19u/* BufferStartIdx */, 20u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvl_ACC*/
  {7u/*BitLength*/, 81u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 18u/* BufferStartIdx */, 19u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrowsnsLvlQlty_ACC*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 23u/* BufferStartIdx */, 24u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 24u/* BufferStartIdx */, 25u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS3*/
  {11u/*BitLength*/, 149u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 25u/* BufferStartIdx */, 27u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnX*/
  {11u/*BitLength*/, 154u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 26u/* BufferStartIdx */, 28u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnY*/
  {11u/*BitLength*/, 175u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 27u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosnZ*/
  {7u/*BitLength*/, 168u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 29u/* BufferStartIdx */, 30u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPosQlty*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 31u/* BufferStartIdx */, 32u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS3*/
  {11u/*BitLength*/, 213u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 33u/* BufferStartIdx */, 35u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnX*/
  {11u/*BitLength*/, 218u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 34u/* BufferStartIdx */, 36u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnY*/
  {11u/*BitLength*/, 239u/* BitPosition */, 1u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 35u/* BufferStartIdx */, 38u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GazePosnZ*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 40u/* BufferStartIdx */, 41u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS5*/
  {3u/*BitLength*/, 301u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 45u/* BufferStartIdx */, 46u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMSSts*/
  {1u/*BitLength*/, 288u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadDetn*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 41u/* BufferStartIdx */, 42u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadYawAng*/
  {8u/*BitLength*/, 272u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 42u/* BufferStartIdx */, 43u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadPitchAng*/
  {8u/*BitLength*/, 280u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 43u/* BufferStartIdx */, 44u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRollAng*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 44u/* BufferStartIdx */, 45u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HeadRotAngQlty*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 47u/* BufferStartIdx */, 48u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS5*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 48u/* BufferStartIdx */, 49u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Checksum_DMS6*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenSts*/
  {7u/*BitLength*/, 345u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 51u/* BufferStartIdx */, 52u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LEyeOpenStsQlty*/
  {2u/*BitLength*/, 372u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenSts*/
  {7u/*BitLength*/, 353u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 52u/* BufferStartIdx */, 53u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*REyeOpenStsQlty*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 49u/* BufferStartIdx */, 50u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeYawAng*/
  {8u/*BitLength*/, 336u/* BitPosition */, 1u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 50u/* BufferStartIdx */, 51u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazePitchAng*/
  {7u/*BitLength*/, 361u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 53u/* BufferStartIdx */, 54u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RobustGazeAngQlty*/
  {3u/*BitLength*/, 368u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvBehvSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 55u/* BufferStartIdx */, 56u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_DMS6*/
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
  {2u/*BitLength*/, 19u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatVentnLvlSet*/
  {2u/*BitLength*/, 16u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatVentnLvlSet*/
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
  {1u/*BitLength*/, 15u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 177u/* BufferStartIdx */, 178u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt_OLE*/
  {6u/*BitLength*/, 9u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 177u/* BufferStartIdx */, 178u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet_OLE*/
  {3u/*BitLength*/, 21u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 178u/* BufferStartIdx */, 179u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet_OLE*/
  {4u/*BitLength*/, 0u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMLightLvlSet_OLE*/
  {1u/*BitLength*/, 8u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 177u/* BufferStartIdx */, 178u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt_OLE*/
  {1u/*BitLength*/, 20u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 178u/* BufferStartIdx */, 179u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt_OLE*/
  {1u/*BitLength*/, 19u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 178u/* BufferStartIdx */, 179u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRdmSwt_OLE*/
  {7u/*BitLength*/, 25u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 179u/* BufferStartIdx */, 180u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Rdm_SingleColorNr*/
  {2u/*BitLength*/, 38u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 180u/* BufferStartIdx */, 181u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChildLockCmd*/
  {2u/*BitLength*/, 60u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 183u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairRestSetSwt*/
  {1u/*BitLength*/, 24u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 179u/* BufferStartIdx */, 180u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnEna_Pass*/
  {3u/*BitLength*/, 35u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 180u/* BufferStartIdx */, 181u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt_Pass*/
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
  {2u/*BitLength*/, 42u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BeanIDReq*/
  {2u/*BitLength*/, 4u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 185u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EgyRecvrySet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 9u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT10_0x331*/
  {7u/*BitLength*/, 33u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 196u/* BufferStartIdx */, 197u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*WeatherCdn*/
  {7u/*BitLength*/, 17u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 194u/* BufferStartIdx */, 195u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PitchAng*/
  {1u/*BitLength*/, 31u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 195u/* BufferStartIdx */, 196u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PitchAngSign*/
  {64u/*BitLength*/, 0u/* BitPosition */, 10u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 192u/* BufferStartIdx */, 200u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT12_0x3AF*/
  {2u/*BitLength*/, 14u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AudioMuteSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OrvmPosnEnaSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ORVMFoldSwt_HUT*/
  {4u/*BitLength*/, 28u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ORVMLensAdjmt_HUT*/
  {4u/*BitLength*/, 24u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvSeatAdjmt_HUT*/
  {4u/*BitLength*/, 36u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrivingModReq_VR*/
  {2u/*BitLength*/, 54u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DampgDrvModeReq*/
  {1u/*BitLength*/, 60u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 207u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DWD_WorkCmd*/
  {1u/*BitLength*/, 8u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 201u/* BufferStartIdx */, 202u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*VSGSwtSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 11u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT13_0x31C*/
  {2u/*BitLength*/, 6u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_VR*/
  {6u/*BitLength*/, 18u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 210u/* BufferStartIdx */, 211u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_TC*/
  {6u/*BitLength*/, 26u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 211u/* BufferStartIdx */, 212u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassSetTempSteplsReq_TC*/
  {1u/*BitLength*/, 39u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SDWSwtSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSSwtReq_VR*/
  {2u/*BitLength*/, 33u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSPrkgTypSeln*/
  {2u/*BitLength*/, 0u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SportModLightSet*/
  {1u/*BitLength*/, 14u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ABSLmpSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoWshWipSet*/
  {2u/*BitLength*/, 9u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeekVehSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 211u/* BufferStartIdx */, 212u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SpdAutoLockModSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkLmpSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 209u/* BufferStartIdx */, 210u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DoorUnlockModSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 209u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SteerWheelHeatSwtReq*/
  {2u/*BitLength*/, 52u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASExitSpdSwt*/
  {4u/*BitLength*/, 40u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 213u/* BufferStartIdx */, 214u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunShadeSwtReq_VR*/
  {4u/*BitLength*/, 44u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 213u/* BufferStartIdx */, 214u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SunRoofSwtReq_VR*/
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
  {2u/*BitLength*/, 28u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ChrgnMode*/
  {2u/*BitLength*/, 24u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BattKeepTemp*/
  {2u/*BitLength*/, 48u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 278u/* BufferStartIdx */, 279u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_IntelEngIdlChrgnSet*/
  {2u/*BitLength*/, 56u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 279u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_IntelBattTempMagSet*/
  {3u/*BitLength*/, 61u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 279u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BattSOCLim*/
  {64u/*BitLength*/, 0u/* BitPosition */, 20u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 272u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT25_0x339*/
  {4u/*BitLength*/, 36u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 284u/* BufferStartIdx */, 285u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PassSeatAdjmtSwt_HUT*/
  {3u/*BitLength*/, 53u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SeatFlankAdjmtSwt_HUT*/
  {1u/*BitLength*/, 16u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 282u/* BufferStartIdx */, 283u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AVM_dispsts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT26_0x2B6*/
  {2u/*BitLength*/, 61u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 295u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_HCU*/
  {64u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT27_0x2B2*/
  {2u/*BitLength*/, 50u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BrkPedFeelSelect*/
  {64u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT28_0x2C0*/
  {5u/*BitLength*/, 8u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_HeightLvlSwt*/
  {4u/*BitLength*/, 28u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_BrightnessLvlSwt*/
  {2u/*BitLength*/, 24u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_SwtReq*/
  {1u/*BitLength*/, 13u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 305u/* BufferStartIdx */, 306u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_AVM*/
  {2u/*BitLength*/, 4u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMIHWSwtSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMIBSRSwtSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT30_0x1E9*/
  {64u/*BitLength*/, 56u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_PhoneNextRoad*/
  {64u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT31_0x30C*/
  {8u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 321u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_HUT32*/
  {2u/*BitLength*/, 46u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ScrnOpSts*/
  {11u/*BitLength*/, 29u/* BitPosition */, 26u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*XLvl*/
  {11u/*BitLength*/, 32u/* BitPosition */, 26u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*YLvl*/
  {1u/*BitLength*/, 9u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DetVideoLost*/
  {1u/*BitLength*/, 10u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkgCtrlModReqValid*/
  {2u/*BitLength*/, 12u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkgCtrlModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ContnPrkgReqValid*/
  {2u/*BitLength*/, 14u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ContnPrkgReq*/
  {1u/*BitLength*/, 11u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSwtReq_HUT*/
  {2u/*BitLength*/, 27u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSuspendOrFinishReq_HUT*/
  {3u/*BitLength*/, 61u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightModSel_HUT*/
  {1u/*BitLength*/, 60u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSts_HUT*/
  {1u/*BitLength*/, 45u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightStrtReq_HUT*/
  {1u/*BitLength*/, 44u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightVehStrtReq_HUT_Valid*/
  {1u/*BitLength*/, 55u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightContinueReq_HUT*/
  {1u/*BitLength*/, 54u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*P2P_PrkgDirSwtReq*/
  {1u/*BitLength*/, 51u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RainMode_Swt_Req*/
  {2u/*BitLength*/, 49u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCMode_Swt_Req*/
  {4u/*BitLength*/, 56u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_HUT32*/
  {64u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT32_0x26F*/
  {2u/*BitLength*/, 4u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 329u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FlaoutUnlockSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 329u/* BufferStartIdx */, 330u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkInDirChoice*/
  {2u/*BitLength*/, 60u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt*/
  {2u/*BitLength*/, 56u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt*/
  {2u/*BitLength*/, 58u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt_VR*/
  {2u/*BitLength*/, 62u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt_VR*/
  {2u/*BitLength*/, 6u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 329u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApproachLampSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 329u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SuperLockSet*/
  {3u/*BitLength*/, 50u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLWinSwtReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRWinSwtReq_VR*/
  {3u/*BitLength*/, 13u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 329u/* BufferStartIdx */, 330u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvWinSwtReq_VR*/
  {3u/*BitLength*/, 35u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassWinSwtReq_VR*/
  {3u/*BitLength*/, 8u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 329u/* BufferStartIdx */, 330u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt*/
  {1u/*BitLength*/, 17u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngFinshCmd*/
  {1u/*BitLength*/, 18u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngStartCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkOutDirReq*/
  {1u/*BitLength*/, 25u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath2Cmd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath2Cmd*/
  {1u/*BitLength*/, 27u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath1Cmd*/
  {1u/*BitLength*/, 28u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath1Cmd*/
  {3u/*BitLength*/, 29u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkgFctnCmd*/
  {1u/*BitLength*/, 19u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkMdlCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_APS*/
  {2u/*BitLength*/, 46u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAEnaReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAChanTyp_TC*/
  {3u/*BitLength*/, 40u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGALvlReq_TC*/
  {1u/*BitLength*/, 16u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*P2P_PrkgDirectSwtCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 27u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT33_0x1ED*/
  {1u/*BitLength*/, 16u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeMod*/
  {1u/*BitLength*/, 17u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeIndcn*/
  {5u/*BitLength*/, 11u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 337u/* BufferStartIdx */, 338u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Hour*/
  {6u/*BitLength*/, 18u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Minutes*/
  {6u/*BitLength*/, 26u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Second*/
  {4u/*BitLength*/, 36u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Left*/
  {4u/*BitLength*/, 32u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Right*/
  {4u/*BitLength*/, 44u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Month*/
  {5u/*BitLength*/, 51u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 342u/* BufferStartIdx */, 343u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Day*/
  {4u/*BitLength*/, 40u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AppModeFB*/
  {6u/*BitLength*/, 61u/* BitPosition */, 28u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 342u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_TgtSOCSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT34_0x370*/
  {5u/*BitLength*/, 19u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempReq_ETC_VR*/
  {5u/*BitLength*/, 27u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempSteplsReq_ETC_TC*/
  {2u/*BitLength*/, 38u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 34u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 46u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 349u/* BufferStartIdx */, 350u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearPowerReq_VR*/
  {2u/*BitLength*/, 25u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_VR*/
  {2u/*BitLength*/, 17u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 351u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FrntWiprCtrl_VR*/
  {2u/*BitLength*/, 42u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 349u/* BufferStartIdx */, 350u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAutoModReq_VR*/
  {1u/*BitLength*/, 49u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 350u/* BufferStartIdx */, 351u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockWinSet*/
  {2u/*BitLength*/, 44u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 349u/* BufferStartIdx */, 350u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearLockReq_TC*/
  {1u/*BitLength*/, 16u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SrSpdCtrlSwt*/
  {2u/*BitLength*/, 57u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 351u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DPF_Request*/
  {2u/*BitLength*/, 2u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ColorCategory*/
  {7u/*BitLength*/, 8u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 346u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SingleColorNr*/
  {64u/*BitLength*/, 0u/* BitPosition */, 29u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT35_0x1E5*/
  {7u/*BitLength*/, 1u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 353u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr1*/
  {7u/*BitLength*/, 9u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr2*/
  {7u/*BitLength*/, 17u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 354u/* BufferStartIdx */, 355u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr3*/
  {7u/*BitLength*/, 25u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 355u/* BufferStartIdx */, 356u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr4*/
  {7u/*BitLength*/, 33u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr5*/
  {7u/*BitLength*/, 41u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr6*/
  {7u/*BitLength*/, 49u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr7*/
  {7u/*BitLength*/, 57u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 359u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr8*/
  {64u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT36_0x1E6*/
  {7u/*BitLength*/, 1u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr9*/
  {7u/*BitLength*/, 9u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 361u/* BufferStartIdx */, 362u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr10*/
  {7u/*BitLength*/, 17u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 362u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr11*/
  {7u/*BitLength*/, 25u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr12*/
  {7u/*BitLength*/, 33u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr13*/
  {7u/*BitLength*/, 41u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 365u/* BufferStartIdx */, 366u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr14*/
  {7u/*BitLength*/, 49u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 366u/* BufferStartIdx */, 367u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr15*/
  {7u/*BitLength*/, 57u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 367u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr16*/
  {64u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT37_0x1EC*/
  {2u/*BitLength*/, 6u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempDecReq_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempIncReq_TC*/
  {6u/*BitLength*/, 10u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempReq_VR*/
  {2u/*BitLength*/, 2u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempDecReq_TC*/
  {2u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempIncReq_TC*/
  {6u/*BitLength*/, 18u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempReq_VR*/
  {2u/*BitLength*/, 16u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempSteplsReq_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_VR*/
  {2u/*BitLength*/, 28u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_TC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_TC*/
  {2u/*BitLength*/, 24u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 372u/* BufferStartIdx */, 373u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 372u/* BufferStartIdx */, 373u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_VR*/
  {2u/*BitLength*/, 34u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 372u/* BufferStartIdx */, 373u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 372u/* BufferStartIdx */, 373u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_VR*/
  {3u/*BitLength*/, 45u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 373u/* BufferStartIdx */, 374u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMFlashFreq*/
  {3u/*BitLength*/, 42u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 373u/* BufferStartIdx */, 374u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMFlashFreq*/
  {3u/*BitLength*/, 55u/* BitPosition */, 32u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 373u/* BufferStartIdx */, 375u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 52u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 374u/* BufferStartIdx */, 375u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 49u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 374u/* BufferStartIdx */, 375u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMFlashFreq*/
  {3u/*BitLength*/, 61u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 375u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMFlashFreq*/
  {3u/*BitLength*/, 58u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 375u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMFlashFreq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT38_0x1E7*/
  {1u/*BitLength*/, 7u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryLockSet*/
  {1u/*BitLength*/, 6u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryUnlockSet*/
  {1u/*BitLength*/, 3u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPAEntryLockSet*/
  {1u/*BitLength*/, 2u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPALvngUnlockSet*/
  {2u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ClsWinSpdSet*/
  {3u/*BitLength*/, 21u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgLvlSet*/
  {3u/*BitLength*/, 18u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgLvlSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 377u/* BufferStartIdx */, 378u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeatKeyMemEna*/
  {3u/*BitLength*/, 29u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 379u/* BufferStartIdx */, 380u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgLvlSet*/
  {3u/*BitLength*/, 26u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 379u/* BufferStartIdx */, 380u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgLvlSet*/
  {7u/*BitLength*/, 40u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 381u/* BufferStartIdx */, 382u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMClrSet*/
  {7u/*BitLength*/, 49u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 382u/* BufferStartIdx */, 383u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMClrSet*/
  {7u/*BitLength*/, 57u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 383u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMClrSet*/
  {1u/*BitLength*/, 48u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 382u/* BufferStartIdx */, 383u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMSwt*/
  {1u/*BitLength*/, 56u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 383u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMSwt*/
  {2u/*BitLength*/, 4u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockPromptFunSet*/
  {1u/*BitLength*/, 9u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 377u/* BufferStartIdx */, 378u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OilBoxSplyReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT39_0x1EB*/
  {1u/*BitLength*/, 61u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMMasterSwt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMPartitionSwt*/
  {7u/*BitLength*/, 9u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 385u/* BufferStartIdx */, 386u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq0*/
  {7u/*BitLength*/, 18u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 385u/* BufferStartIdx */, 387u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq1*/
  {7u/*BitLength*/, 27u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 386u/* BufferStartIdx */, 388u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq2*/
  {7u/*BitLength*/, 36u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 387u/* BufferStartIdx */, 389u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq3*/
  {7u/*BitLength*/, 45u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 388u/* BufferStartIdx */, 390u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq4*/
  {7u/*BitLength*/, 54u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 389u/* BufferStartIdx */, 391u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq5*/
  {7u/*BitLength*/, 63u/* BitPosition */, 34u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 390u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq6*/
  {64u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT40_0x224*/
  {7u/*BitLength*/, 1u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMClrSet*/
  {7u/*BitLength*/, 9u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 393u/* BufferStartIdx */, 394u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMClrSet*/
  {7u/*BitLength*/, 17u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMClrSet*/
  {7u/*BitLength*/, 25u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMClrSet*/
  {4u/*BitLength*/, 36u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 32u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 44u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 40u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 52u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 398u/* BufferStartIdx */, 399u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMLightLvlSet*/
  {4u/*BitLength*/, 48u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 398u/* BufferStartIdx */, 399u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMLightLvlSet*/
  {4u/*BitLength*/, 60u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMLightLvlSet*/
  {1u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMFloSwt*/
  {1u/*BitLength*/, 8u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 393u/* BufferStartIdx */, 394u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt*/
  {1u/*BitLength*/, 16u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMSwt*/
  {1u/*BitLength*/, 24u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 395u/* BufferStartIdx */, 396u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMSwt*/
  {1u/*BitLength*/, 59u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMSwt*/
  {1u/*BitLength*/, 58u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMSwt*/
  {1u/*BitLength*/, 57u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMSwt*/
  {1u/*BitLength*/, 56u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 399u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RoofALCMSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT41_0x1FB*/
  {6u/*BitLength*/, 32u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempSteplsReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 400u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT42_0x1F9*/
  {4u/*BitLength*/, 20u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgModSet*/
  {4u/*BitLength*/, 16u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgModSet*/
  {4u/*BitLength*/, 4u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 409u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgLvlSet_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 409u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatHeatgLvlSet_Nine*/
  {4u/*BitLength*/, 12u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 409u/* BufferStartIdx */, 410u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatHeatgLvlSet_Nine*/
  {4u/*BitLength*/, 8u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 409u/* BufferStartIdx */, 410u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatHeatgLvlSet_Nine*/
  {64u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT43_0x1FD*/
  {4u/*BitLength*/, 8u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 417u/* BufferStartIdx */, 418u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgModSet*/
  {4u/*BitLength*/, 12u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 417u/* BufferStartIdx */, 418u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgModSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 418u/* BufferStartIdx */, 419u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PPMI_P_BSR_SwtSet*/
  {2u/*BitLength*/, 16u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 418u/* BufferStartIdx */, 419u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RWPC_SwtReq*/
  {4u/*BitLength*/, 60u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 423u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApprLightSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 416u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT45_0x1DC*/
  {4u/*BitLength*/, 4u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 425u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 425u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet_Nine*/
  {4u/*BitLength*/, 12u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatVentnLvlSet_Nine*/
  {4u/*BitLength*/, 8u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatVentnLvlSet_Nine*/
  {2u/*BitLength*/, 22u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ARFSwtReq*/
  {2u/*BitLength*/, 20u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ASFCSwtReq*/
  {2u/*BitLength*/, 18u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AGSSwtReq*/
  {2u/*BitLength*/, 16u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 427u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SOCMngmntSwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 432u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT46_0x1DD*/
  {1u/*BitLength*/, 64u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 440u/* BufferStartIdx */, 441u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SSSSet_HUT*/
  {2u/*BitLength*/, 76u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 441u/* BufferStartIdx */, 442u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IFC_SnvtySet*/
  {1u/*BitLength*/, 104u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DOWSwtReq*/
  {1u/*BitLength*/, 105u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_PedSwtReq*/
  {4u/*BitLength*/, 72u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 441u/* BufferStartIdx */, 442u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMLightLvlSet*/
  {1u/*BitLength*/, 86u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FlashLmpSwtReq*/
  {1u/*BitLength*/, 85u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCASwtReq*/
  {1u/*BitLength*/, 84u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTASwtReq*/
  {1u/*BitLength*/, 83u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTABrkSwtReq*/
  {1u/*BitLength*/, 82u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCWSwtReq*/
  {2u/*BitLength*/, 80u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCW_SnvtySet*/
  {1u/*BitLength*/, 95u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_VehSwtReq*/
  {1u/*BitLength*/, 93u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LKASwtReq*/
  {1u/*BitLength*/, 92u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCKSwtReq*/
  {1u/*BitLength*/, 91u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ELKSwtReq*/
  {1u/*BitLength*/, 90u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_PedSwtReq*/
  {1u/*BitLength*/, 89u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_VehSwtReq*/
  {1u/*BitLength*/, 88u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LDWSwtReq*/
  {1u/*BitLength*/, 102u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 445u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRSwtReq*/
  {1u/*BitLength*/, 101u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 445u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRWarnSwtReq*/
  {1u/*BitLength*/, 127u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ICA_HandsOffSwtReq*/
  {1u/*BitLength*/, 126u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ISLSwtReq*/
  {5u/*BitLength*/, 121u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSR_SnvtySet*/
  {1u/*BitLength*/, 87u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HFASwtSts*/
  {2u/*BitLength*/, 113u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EPSSteerModSwtReq*/
  {1u/*BitLength*/, 112u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DSTSwtReq*/
  {2u/*BitLength*/, 99u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 445u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSWarnFormSwtReq*/
  {1u/*BitLength*/, 98u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 445u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_ESPFuncOffSwtSts*/
  {4u/*BitLength*/, 108u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrivingModReq_HUT*/
  {1u/*BitLength*/, 115u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OilLvlDispReq*/
  {1u/*BitLength*/, 120u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvgModeMemReq*/
  {1u/*BitLength*/, 107u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntelligentEvaSwtReq*/
  {1u/*BitLength*/, 106u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSSwtReq*/
  {12u/*BitLength*/, 148u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 449u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUTRadioFrq*/
  {4u/*BitLength*/, 156u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 451u/* BufferStartIdx */, 452u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MediaPlaySrc*/
  {2u/*BitLength*/, 168u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_AudioSts*/
  {2u/*BitLength*/, 176u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 454u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_VideoSts*/
  {2u/*BitLength*/, 178u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 454u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*BT_AudioSts*/
  {2u/*BitLength*/, 180u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 454u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IPod_Sts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 454u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AM_Sts*/
  {2u/*BitLength*/, 184u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 455u/* BufferStartIdx */, 456u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FM_Sts*/
  {2u/*BitLength*/, 186u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 455u/* BufferStartIdx */, 456u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*APPLink_Sts*/
  {2u/*BitLength*/, 188u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 455u/* BufferStartIdx */, 456u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*QQMusic_Sts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 455u/* BufferStartIdx */, 456u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*KaolaFM_Sts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OnlineNews_Sts*/
  {1u/*BitLength*/, 147u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OffroadThmSts*/
  {3u/*BitLength*/, 173u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ECM*/
  {3u/*BitLength*/, 170u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TCU*/
  {2u/*BitLength*/, 162u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 453u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TOD*/
  {2u/*BitLength*/, 243u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 462u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSet*/
  {4u/*BitLength*/, 252u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 463u/* BufferStartIdx */, 464u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ChairMemPosnSetResult*/
  {1u/*BitLength*/, 224u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 460u/* BufferStartIdx */, 461u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TABSwtReq_HUT*/
  {10u/*BitLength*/, 246u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavVehToTrafEyeDist*/
  {4u/*BitLength*/, 308u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 470u/* BufferStartIdx */, 471u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavRoadType*/
  {2u/*BitLength*/, 306u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 470u/* BufferStartIdx */, 471u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimType*/
  {6u/*BitLength*/, 266u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimValue*/
  {2u/*BitLength*/, 264u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 465u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimUnit_HUT*/
  {10u/*BitLength*/, 286u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavCtryType*/
  {3u/*BitLength*/, 283u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 467u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimSignSts*/
  {8u/*BitLength*/, 288u/* BitPosition */, 40u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 468u/* BufferStartIdx */, 469u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavTSRTrafSign*/
  {1u/*BitLength*/, 298u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AESSwtReq*/
  {1u/*BitLength*/, 280u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 467u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SwtReq*/
  {2u/*BitLength*/, 302u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SnvtySet*/
  {1u/*BitLength*/, 301u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTASwtReq*/
  {1u/*BitLength*/, 300u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTABrkSwtReq*/
  {1u/*BitLength*/, 299u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_JASwtReq*/
  {1u/*BitLength*/, 297u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_WarnFormSwtReq*/
  {1u/*BitLength*/, 316u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 471u/* BufferStartIdx */, 472u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SteerCorrnReq*/
  {1u/*BitLength*/, 296u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALC_SwtReq*/
  {1u/*BitLength*/, 319u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 471u/* BufferStartIdx */, 472u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModSwtReq_HUT*/
  {2u/*BitLength*/, 317u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 471u/* BufferStartIdx */, 472u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ESP*/
  {3u/*BitLength*/, 325u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 472u/* BufferStartIdx */, 473u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_MsgTye*/
  {13u/*BitLength*/, 328u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 472u/* BufferStartIdx */, 474u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Offset*/
  {2u/*BitLength*/, 342u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 475u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CycCnt*/
  {6u/*BitLength*/, 336u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 474u/* BufferStartIdx */, 475u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Pathldx*/
  {2u/*BitLength*/, 350u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 475u/* BufferStartIdx */, 476u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Idx*/
  {5u/*BitLength*/, 345u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 475u/* BufferStartIdx */, 476u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosProbb*/
  {9u/*BitLength*/, 352u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 475u/* BufferStartIdx */, 477u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Age*/
  {3u/*BitLength*/, 364u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 477u/* BufferStartIdx */, 478u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosConfdc*/
  {3u/*BitLength*/, 361u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 477u/* BufferStartIdx */, 478u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CurLane*/
  {9u/*BitLength*/, 368u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 477u/* BufferStartIdx */, 479u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Spd*/
  {8u/*BitLength*/, 376u/* BitPosition */, 40u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 479u/* BufferStartIdx */, 480u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Rehead*/
  {2u/*BitLength*/, 118u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_HybModReq*/
  {2u/*BitLength*/, 116u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_HybFctnReq*/
  {4u/*BitLength*/, 164u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 453u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_DrvModReq*/
  {448u/*BitLength*/, 0u/* BitPosition */, 40u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 56u/* BusAccBtyeLength */, 432u/* BufferStartIdx */, 488u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD1_0x2C3*/
  {4u/*BitLength*/, 12u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 491u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 492u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 492u/* BufferStartIdx */, 494u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 493u/* BufferStartIdx */, 495u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HTU_OD_Obj1_ID*/
  {3u/*BitLength*/, 85u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 499u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_type*/
  {4u/*BitLength*/, 72u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Confidence*/
  {7u/*BitLength*/, 94u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 500u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_width*/
  {12u/*BitLength*/, 108u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 500u/* BufferStartIdx */, 502u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 112u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 501u/* BufferStartIdx */, 503u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_ID*/
  {3u/*BitLength*/, 149u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 507u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_type*/
  {4u/*BitLength*/, 136u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Confidence*/
  {7u/*BitLength*/, 158u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_width*/
  {12u/*BitLength*/, 172u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 508u/* BufferStartIdx */, 510u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 176u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 509u/* BufferStartIdx */, 511u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_ID*/
  {3u/*BitLength*/, 213u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 515u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_type*/
  {4u/*BitLength*/, 200u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Confidence*/
  {7u/*BitLength*/, 222u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 516u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_width*/
  {12u/*BitLength*/, 236u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 516u/* BufferStartIdx */, 518u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 240u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 517u/* BufferStartIdx */, 519u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 268u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 522u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_ID*/
  {3u/*BitLength*/, 277u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 522u/* BufferStartIdx */, 523u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_type*/
  {4u/*BitLength*/, 264u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 522u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Confidence*/
  {7u/*BitLength*/, 286u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 522u/* BufferStartIdx */, 524u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_width*/
  {12u/*BitLength*/, 300u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 524u/* BufferStartIdx */, 526u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 304u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 525u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_Y*/
  {4u/*BitLength*/, 332u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_ID*/
  {3u/*BitLength*/, 341u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_type*/
  {4u/*BitLength*/, 328u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Confidence*/
  {7u/*BitLength*/, 350u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_width*/
  {12u/*BitLength*/, 364u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 534u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_X*/
  {12u/*BitLength*/, 368u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 533u/* BufferStartIdx */, 535u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_Y*/
  {4u/*BitLength*/, 396u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 537u/* BufferStartIdx */, 538u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_ID*/
  {3u/*BitLength*/, 405u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 538u/* BufferStartIdx */, 539u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_type*/
  {4u/*BitLength*/, 392u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 537u/* BufferStartIdx */, 538u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Confidence*/
  {7u/*BitLength*/, 414u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 538u/* BufferStartIdx */, 540u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_width*/
  {12u/*BitLength*/, 428u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 540u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_X*/
  {12u/*BitLength*/, 432u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 488u/* BufferStartIdx */, 552u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD2_0x203*/
  {4u/*BitLength*/, 12u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 553u/* BufferStartIdx */, 554u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 554u/* BufferStartIdx */, 555u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 553u/* BufferStartIdx */, 554u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 554u/* BufferStartIdx */, 556u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 556u/* BufferStartIdx */, 558u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 557u/* BufferStartIdx */, 559u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_Y*/
  {1u/*BitLength*/, 25u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 555u/* BufferStartIdx */, 556u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AutoSpdSetSwt*/
  {1u/*BitLength*/, 24u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 555u/* BufferStartIdx */, 556u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LaneChngCfmSwt*/
  {1u/*BitLength*/, 63u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 559u/* BufferStartIdx */, 560u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*VoiceBrdcSwt*/
  {4u/*BitLength*/, 26u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 555u/* BufferStartIdx */, 556u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*UsrManSts*/
  {2u/*BitLength*/, 112u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 566u/* BufferStartIdx */, 567u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_WorkSts*/
  {16u/*BitLength*/, 80u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 561u/* BufferStartIdx */, 563u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj_Timestamp*/
  {6u/*BitLength*/, 90u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 563u/* BufferStartIdx */, 564u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD1_distance*/
  {6u/*BitLength*/, 100u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 563u/* BufferStartIdx */, 565u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD2_distance*/
  {6u/*BitLength*/, 110u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 564u/* BufferStartIdx */, 566u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD3_distance*/
  {6u/*BitLength*/, 104u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 565u/* BufferStartIdx */, 566u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD4_distance*/
  {6u/*BitLength*/, 114u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 566u/* BufferStartIdx */, 567u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD5_distance*/
  {6u/*BitLength*/, 138u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 570u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD6_distance*/
  {6u/*BitLength*/, 148u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 571u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD7_distance*/
  {6u/*BitLength*/, 158u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 570u/* BufferStartIdx */, 572u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD8_distance*/
  {6u/*BitLength*/, 152u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 571u/* BufferStartIdx */, 572u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD9_distance*/
  {6u/*BitLength*/, 162u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 572u/* BufferStartIdx */, 573u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD10_distance*/
  {6u/*BitLength*/, 172u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 572u/* BufferStartIdx */, 574u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD11_distance*/
  {6u/*BitLength*/, 182u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 573u/* BufferStartIdx */, 575u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD12_distance*/
  {6u/*BitLength*/, 176u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 574u/* BufferStartIdx */, 575u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD13_distance*/
  {6u/*BitLength*/, 202u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 577u/* BufferStartIdx */, 578u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD14_distance*/
  {6u/*BitLength*/, 212u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 577u/* BufferStartIdx */, 579u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD15_distance*/
  {6u/*BitLength*/, 222u/* BitPosition */, 42u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 578u/* BufferStartIdx */, 580u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD16_distance*/
  {6u/*BitLength*/, 216u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 579u/* BufferStartIdx */, 580u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD17_distance*/
  {6u/*BitLength*/, 226u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 580u/* BufferStartIdx */, 581u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD18_distance*/
  {1u/*BitLength*/, 335u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 593u/* BufferStartIdx */, 594u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Swt_Req*/
  {1u/*BitLength*/, 334u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 593u/* BufferStartIdx */, 594u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NOH_Act_Req*/
  {512u/*BitLength*/, 0u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 552u/* BufferStartIdx */, 616u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD3_0x243*/
  {1u/*BitLength*/, 44u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 621u/* BufferStartIdx */, 622u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefinedParkCmd*/
  {3u/*BitLength*/, 16u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 618u/* BufferStartIdx */, 619u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefPrkMenuSelCmd*/
  {4u/*BitLength*/, 32u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 620u/* BufferStartIdx */, 621u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SlotNum_VR*/
  {1u/*BitLength*/, 8u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 617u/* BufferStartIdx */, 618u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Comfirm_Btn*/
  {1u/*BitLength*/, 9u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 617u/* BufferStartIdx */, 618u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_SelfParLot_Ending*/
  {1u/*BitLength*/, 10u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 617u/* BufferStartIdx */, 618u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Set_Starting*/
  {1u/*BitLength*/, 11u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 617u/* BufferStartIdx */, 618u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Return_Btn*/
  {1u/*BitLength*/, 21u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 618u/* BufferStartIdx */, 619u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Set_Path_Ending*/
  {4u/*BitLength*/, 24u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 619u/* BufferStartIdx */, 620u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Path_Select*/
  {4u/*BitLength*/, 28u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 619u/* BufferStartIdx */, 620u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Path_Delete*/
  {4u/*BitLength*/, 36u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 620u/* BufferStartIdx */, 621u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Path_SetTop*/
  {2u/*BitLength*/, 42u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 621u/* BufferStartIdx */, 622u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_APA_Permit*/
  {1u/*BitLength*/, 45u/* BitPosition */, 43u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 621u/* BufferStartIdx */, 622u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_PAVP_PathList_Req*/
  {512u/*BitLength*/, 0u/* BitPosition */, 43u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 616u/* BufferStartIdx */, 680u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD4_0x1DA*/
  {512u/*BitLength*/, 504u/* BitPosition */, 44u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 680u/* BufferStartIdx */, 744u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_ExternalDevice*/
  {512u/*BitLength*/, 0u/* BitPosition */, 44u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 680u/* BufferStartIdx */, 744u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD5_0x1DB*/
  {8u/*BitLength*/, 0u/* BitPosition */, 45u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 744u/* BufferStartIdx */, 745u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequestMessageId*/
  {56u/*BitLength*/, 56u/* BitPosition */, 45u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 7u/* BusAccBtyeLength */, 745u/* BufferStartIdx */, 752u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequstReseverData*/
  {3u/*BitLength*/, 18u/* BitPosition */, 46u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 762u/* BufferStartIdx */, 763u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_CurrTheme*/
  {9u/*BitLength*/, 23u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 761u/* BufferStartIdx */, 763u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdDisp*/
  {8u/*BitLength*/, 60u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 766u/* BufferStartIdx */, 768u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VelSpdDisp_Mile*/
  {10u/*BitLength*/, 24u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 762u/* BufferStartIdx */, 764u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelMainTankR*/
  {10u/*BitLength*/, 46u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 764u/* BufferStartIdx */, 766u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxTankR*/
  {4u/*BitLength*/, 42u/* BitPosition */, 46u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 765u/* BufferStartIdx */, 766u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_LagueSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 46u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 760u/* BufferStartIdx */, 768u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP1_0x293*/
  {8u/*BitLength*/, 0u/* BitPosition */, 47u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 768u/* BufferStartIdx */, 769u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_IP2*/
  {2u/*BitLength*/, 50u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 774u/* BufferStartIdx */, 775u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_DrvSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 774u/* BufferStartIdx */, 775u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_PassSeatBeltWarnLmpFailSts*/
  {24u/*BitLength*/, 24u/* BitPosition */, 47u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 769u/* BufferStartIdx */, 772u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistance*/
  {1u/*BitLength*/, 46u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 773u/* BufferStartIdx */, 774u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceValid*/
  {8u/*BitLength*/, 32u/* BitPosition */, 47u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 772u/* BufferStartIdx */, 773u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlInfo*/
  {2u/*BitLength*/, 44u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 773u/* BufferStartIdx */, 774u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlLowLmpSts*/
  {2u/*BitLength*/, 42u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 773u/* BufferStartIdx */, 774u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_BattChrgLmpSts*/
  {2u/*BitLength*/, 40u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 773u/* BufferStartIdx */, 774u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EngOilPressLowLmpSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 774u/* BufferStartIdx */, 775u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ABMWarnLmpFailrSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 774u/* BufferStartIdx */, 775u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_Err*/
  {1u/*BitLength*/, 47u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 773u/* BufferStartIdx */, 774u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ACCErr*/
  {1u/*BitLength*/, 53u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 774u/* BufferStartIdx */, 775u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdUnit*/
  {1u/*BitLength*/, 63u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 775u/* BufferStartIdx */, 776u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VINcompr*/
  {4u/*BitLength*/, 56u/* BitPosition */, 47u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 775u/* BufferStartIdx */, 776u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_IP2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 47u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 768u/* BufferStartIdx */, 776u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP2_0x27F*/
  {12u/*BitLength*/, 20u/* BitPosition */, 48u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 777u/* BufferStartIdx */, 779u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_RemainDistance*/
  {1u/*BitLength*/, 19u/* BitPosition */, 48u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 778u/* BufferStartIdx */, 779u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelConsUnit*/
  {1u/*BitLength*/, 18u/* BitPosition */, 48u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 778u/* BufferStartIdx */, 779u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EBDFailSts*/
  {12u/*BitLength*/, 36u/* BitPosition */, 48u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 779u/* BufferStartIdx */, 781u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AvgFuelCons*/
  {14u/*BitLength*/, 54u/* BitPosition */, 48u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 780u/* BufferStartIdx */, 783u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelCons*/
  {128u/*BitLength*/, 0u/* BitPosition */, 48u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 16u/* BusAccBtyeLength */, 776u/* BufferStartIdx */, 792u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP3_0x34A*/
  {12u/*BitLength*/, 44u/* BitPosition */, 49u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 796u/* BufferStartIdx */, 798u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AuxRemainDistance*/
  {64u/*BitLength*/, 0u/* BitPosition */, 49u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 792u/* BufferStartIdx */, 800u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP4_0x34B*/
  {8u/*BitLength*/, 8u/* BitPosition */, 50u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 801u/* BufferStartIdx */, 802u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxLvlInfo*/
  {64u/*BitLength*/, 0u/* BitPosition */, 50u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 800u/* BufferStartIdx */, 808u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP7_0x223*/
};

const ComEx_TxPduInfoType ComEx_TxPduInfo[ComEx_TxPduSize] = 
{
  {65535u/* SignalStartIdx */, 65535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 0/* CalloutStartIdx */, 1u/* CalloutNum */}, /*ComIPdu_userData*/
  {0u/* SignalStartIdx */, 39u/* SignalEndIdx */, 0u/* GroupStartIdx */, 4u/* GroupEndIdx */, 8u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DMS_FD1*/
  {39u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DVR_FD1*/
  {44u/* SignalStartIdx */, 73u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT1*/
  {73u/* SignalStartIdx */, 89u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT2*/
  {89u/* SignalStartIdx */, 103u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 152u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT3*/
  {103u/* SignalStartIdx */, 126u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 160u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT4*/
  {126u/* SignalStartIdx */, 144u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 168u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT6*/
  {144u/* SignalStartIdx */, 157u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT7*/
  {157u/* SignalStartIdx */, 171u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 184u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT10*/
  {171u/* SignalStartIdx */, 175u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT12*/
  {175u/* SignalStartIdx */, 185u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT13*/
  {185u/* SignalStartIdx */, 205u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT15*/
  {205u/* SignalStartIdx */, 211u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 216u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT16*/
  {211u/* SignalStartIdx */, 227u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 224u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT17*/
  {227u/* SignalStartIdx */, 241u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 232u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT19*/
  {241u/* SignalStartIdx */, 251u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT20*/
  {251u/* SignalStartIdx */, 264u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 248u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT21*/
  {264u/* SignalStartIdx */, 284u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT22*/
  {284u/* SignalStartIdx */, 302u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT23*/
  {302u/* SignalStartIdx */, 311u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT25*/
  {311u/* SignalStartIdx */, 315u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 280u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT26*/
  {315u/* SignalStartIdx */, 317u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 288u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT27*/
  {317u/* SignalStartIdx */, 319u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 296u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT28*/
  {319u/* SignalStartIdx */, 326u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 304u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT30*/
  {326u/* SignalStartIdx */, 328u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 312u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT31*/
  {328u/* SignalStartIdx */, 349u/* SignalEndIdx */, 4u/* GroupStartIdx */, 5u/* GroupEndIdx */, 320u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT32*/
  {349u/* SignalStartIdx */, 378u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 328u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT33*/
  {378u/* SignalStartIdx */, 390u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 336u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT34*/
  {390u/* SignalStartIdx */, 408u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 344u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT35*/
  {408u/* SignalStartIdx */, 417u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 352u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT36*/
  {417u/* SignalStartIdx */, 426u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT37*/
  {426u/* SignalStartIdx */, 449u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT38*/
  {449u/* SignalStartIdx */, 467u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT39*/
  {467u/* SignalStartIdx */, 477u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT40*/
  {477u/* SignalStartIdx */, 497u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT41*/
  {497u/* SignalStartIdx */, 499u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT42*/
  {499u/* SignalStartIdx */, 506u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT43*/
  {506u/* SignalStartIdx */, 512u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT45*/
  {512u/* SignalStartIdx */, 521u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT46*/
  {521u/* SignalStartIdx */, 607u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 56u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD1*/
  {607u/* SignalStartIdx */, 650u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 488u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD2*/
  {650u/* SignalStartIdx */, 683u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 552u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD3*/
  {683u/* SignalStartIdx */, 697u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 616u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD4*/
  {697u/* SignalStartIdx */, 699u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 680u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD5*/
  {699u/* SignalStartIdx */, 701u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 744u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_Sync_Req*/
  {701u/* SignalStartIdx */, 708u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 760u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP1*/
  {708u/* SignalStartIdx */, 724u/* SignalEndIdx */, 5u/* GroupStartIdx */, 6u/* GroupEndIdx */, 768u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP2*/
  {724u/* SignalStartIdx */, 730u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 776u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP3*/
  {730u/* SignalStartIdx */, 732u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 792u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP4*/
  {732u/* SignalStartIdx */, 734u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 800u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP7*/
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
  0x5u,
  0x1u,
  0x0u,
  0x11u,
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xcu,
  0x0u,
  0x28u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x8u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x10u,
  0x12u,
  0x2u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x81u,
  0x81u,
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
  0x81u,
  0x81u,
  0x0u,
  0x0u,
  0x0u,
  0xfu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  {26u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* E2eIdx */}, /*HUT32*/
  {47u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* E2eIdx */}, /*IP2*/
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
