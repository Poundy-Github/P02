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
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 40u/* AppAccBytePosition */}, /*FLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 41u/* AppAccBytePosition */}, /*FLWheelSpd*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 43u/* AppAccBytePosition */}, /*FRWheelDriveDirection*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 44u/* AppAccBytePosition */}, /*FRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 45u/* AppAccBytePosition */}, /*FRWheelSpd*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 47u/* AppAccBytePosition */}, /*WssFLEdgesSum*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 48u/* AppAccBytePosition */}, /*WssFREdgesSum*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 49u/* AppAccBytePosition */}, /*WssFLEdgesSumVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 50u/* AppAccBytePosition */}, /*WssFREdgesSumVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 2u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 51u/* AppAccBytePosition */}, /*ABS1_0x231*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 59u/* AppAccBytePosition */}, /*RLWheelDriveDirection*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 60u/* AppAccBytePosition */}, /*RLWheelSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 61u/* AppAccBytePosition */}, /*RLWheelSpd*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 63u/* AppAccBytePosition */}, /*RRWheelDriveDirection*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 64u/* AppAccBytePosition */}, /*RRWheelSpdVld*/
  {13u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 65u/* AppAccBytePosition */}, /*RRWheelSpd*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 67u/* AppAccBytePosition */}, /*WssRLEdgesSum*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 68u/* AppAccBytePosition */}, /*WssRREdgesSum*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 69u/* AppAccBytePosition */}, /*WssRLEdgesSumVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 70u/* AppAccBytePosition */}, /*WssRREdgesSumVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 71u/* AppAccBytePosition */}, /*ABS2_0x246*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 79u/* AppAccBytePosition */}, /*CheckSum_ABS3*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 80u/* AppAccBytePosition */}, /*ABSFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 81u/* AppAccBytePosition */}, /*EBDFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 82u/* AppAccBytePosition */}, /*VehSpdVld*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 83u/* AppAccBytePosition */}, /*VehSpd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 85u/* AppAccBytePosition */}, /*VehOdoInfoSts*/
  {10u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 86u/* AppAccBytePosition */}, /*VehOdoInfo*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 88u/* AppAccBytePosition */}, /*ABSActv*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 89u/* AppAccBytePosition */}, /*RollingCounter_ABS3*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 6u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 90u/* AppAccBytePosition */}, /*ABS3_0x265*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 106u/* AppAccBytePosition */}, /*InCarTemp*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 107u/* AppAccBytePosition */}, /*ACAQSEnaSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 108u/* AppAccBytePosition */}, /*ACOperMod*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 109u/* AppAccBytePosition */}, /*ACAIUEnaSts*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 110u/* AppAccBytePosition */}, /*ACDrvAirDistriMod*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 111u/* AppAccBytePosition */}, /*ACSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 112u/* AppAccBytePosition */}, /*ACFrntPassTempSteplessSetEnaSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 113u/* AppAccBytePosition */}, /*ACDrvTempSteplessSetEnaSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 114u/* AppAccBytePosition */}, /*ACEEMSts*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 115u/* AppAccBytePosition */}, /*ACCbnClnEnasts*/
  {4u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 116u/* AppAccBytePosition */}, /*ACCbnClnOffCode*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 117u/* AppAccBytePosition */}, /*ACDrvTemp_ETC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 118u/* AppAccBytePosition */}, /*AC1_0x29D*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 126u/* AppAccBytePosition */}, /*ACFrntDefrstSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 127u/* AppAccBytePosition */}, /*ACHMIDispCmd*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 128u/* AppAccBytePosition */}, /*ACFrntBlwrSpd*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 129u/* AppAccBytePosition */}, /*ACOpenSts*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 130u/* AppAccBytePosition */}, /*ACDualModEnaSts*/
  {6u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 131u/* AppAccBytePosition */}, /*ACDrvTemp_ATC*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 132u/* AppAccBytePosition */}, /*ACAmbTemp*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 133u/* AppAccBytePosition */}, /*ACAirInletSts*/
  {6u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 134u/* AppAccBytePosition */}, /*ACFrntPasstTemp_ATC*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 135u/* AppAccBytePosition */}, /*ACAutoModEnaSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 136u/* AppAccBytePosition */}, /*ACCmprEnaSts*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 137u/* AppAccBytePosition */}, /*ACAutoDefrstModEnaSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 138u/* AppAccBytePosition */}, /*ACRearWinHeatSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 139u/* AppAccBytePosition */}, /*AC2_0x385*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 147u/* AppAccBytePosition */}, /*ACMaxEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 148u/* AppAccBytePosition */}, /*AC4_0x2CC*/
  {9u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 156u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dx*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 158u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Typ*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 159u/* AppAccBytePosition */}, /*ACC_LeTargrt_02_Detn*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 160u/* AppAccBytePosition */}, /*ACC_RiTargrt_02_Detn*/
  {9u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 161u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dx*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 163u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Typ*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 164u/* AppAccBytePosition */}, /*ACC_LeTgtObjBarDisp*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 165u/* AppAccBytePosition */}, /*ACC_RiTgtObjBarDisp*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 166u/* AppAccBytePosition */}, /*Checksum_ACC3*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 167u/* AppAccBytePosition */}, /*ISL_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 168u/* AppAccBytePosition */}, /*ICA_HandsOffResp*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 169u/* AppAccBytePosition */}, /*HWA_SnvtySet_Resp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 170u/* AppAccBytePosition */}, /*HWA_Resp*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 171u/* AppAccBytePosition */}, /*ALC_Resp*/
  {2u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 172u/* AppAccBytePosition */}, /*ALC_InterSysInfoDisp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 173u/* AppAccBytePosition */}, /*RollingCounter_ACC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 174u/* AppAccBytePosition */}, /*Checksum_ACC4*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 175u/* AppAccBytePosition */}, /*ACC_ObjDetecte*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 176u/* AppAccBytePosition */}, /*ACC_TakeOverReq*/
  {5u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 177u/* AppAccBytePosition */}, /*ACC_InterSysInfoDisp*/
  {5u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 178u/* AppAccBytePosition */}, /*ACC_ModDisp*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 179u/* AppAccBytePosition */}, /*ACC_FctSts*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 180u/* AppAccBytePosition */}, /*ACC_TgtObjBarDisp*/
  {3u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 181u/* AppAccBytePosition */}, /*ACC_TimeGapSet*/
  {8u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 182u/* AppAccBytePosition */}, /*ACC_SpdSetValue*/
  {3u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 183u/* AppAccBytePosition */}, /*TJA_ACC_SelSts*/
  {2u/*BitLength*/, 171u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 184u/* AppAccBytePosition */}, /*ISL_InterSysInfoDisp*/
  {3u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 185u/* AppAccBytePosition */}, /*TJA_ICA_ModDisp*/
  {3u/*BitLength*/, 161u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 186u/* AppAccBytePosition */}, /*TJA_ICA_InterSysInfoDisp*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 187u/* AppAccBytePosition */}, /*CruCha_ModDisp*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 188u/* AppAccBytePosition */}, /*CruChar_InterSysInfoDisp*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 189u/* AppAccBytePosition */}, /*RollingCounter_ACC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 190u/* AppAccBytePosition */}, /*Checksum_ACC8*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 191u/* AppAccBytePosition */}, /*HWA_warning*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 192u/* AppAccBytePosition */}, /*HWA_ModDisp*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 193u/* AppAccBytePosition */}, /*HWA_InterSysInfoDisp*/
  {3u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 194u/* AppAccBytePosition */}, /*HWA_LaneChangeReq*/
  {2u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 195u/* AppAccBytePosition */}, /*HWA_LaneChange*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 196u/* AppAccBytePosition */}, /*RollingCounter_ACC8*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 197u/* AppAccBytePosition */}, /*Checksum_ACC6*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 198u/* AppAccBytePosition */}, /*ACC_PotentialTgtDy*/
  {9u/*BitLength*/, 287u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 199u/* AppAccBytePosition */}, /*ACC_PotentialTgtDx*/
  {2u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 201u/* AppAccBytePosition */}, /*ACC_RlvTgtDetn*/
  {2u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 202u/* AppAccBytePosition */}, /*ACC_EgoStatus*/
  {8u/*BitLength*/, 288u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 203u/* AppAccBytePosition */}, /*ACC_RlvTgtDy*/
  {9u/*BitLength*/, 311u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 204u/* AppAccBytePosition */}, /*ACC_RlvTgtDx*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 206u/* AppAccBytePosition */}, /*ACC_PotentialTgtDetn*/
  {3u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 207u/* AppAccBytePosition */}, /*ACC_PotentialTgtTyp*/
  {3u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 208u/* AppAccBytePosition */}, /*ACC_RlvTgtTyp*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 209u/* AppAccBytePosition */}, /*RollingCounter_ACC6*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 210u/* AppAccBytePosition */}, /*Checksum_ACC7*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 211u/* AppAccBytePosition */}, /*ACC_LeTgtDy*/
  {9u/*BitLength*/, 351u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 212u/* AppAccBytePosition */}, /*ACC_LeTgtDx*/
  {3u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 214u/* AppAccBytePosition */}, /*ACC_LeTgtTyp*/
  {2u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 215u/* AppAccBytePosition */}, /*ACC_LeTargrtDection*/
  {2u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 216u/* AppAccBytePosition */}, /*ACC_RiTargrtDetn*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 217u/* AppAccBytePosition */}, /*ACC_RiTgtDy*/
  {9u/*BitLength*/, 375u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 218u/* AppAccBytePosition */}, /*ACC_RiTgtDx*/
  {3u/*BitLength*/, 372u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 220u/* AppAccBytePosition */}, /*ACC_RiTgtTyp*/
  {3u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 221u/* AppAccBytePosition */}, /*Request_driveoff*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 222u/* AppAccBytePosition */}, /*RollingCounter_ACC7*/
  {1u/*BitLength*/, 399u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 223u/* AppAccBytePosition */}, /*ACC_RlvTgtfusion*/
  {6u/*BitLength*/, 393u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 224u/* AppAccBytePosition */}, /*ACC_RlvTgtHeading*/
  {1u/*BitLength*/, 392u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 225u/* AppAccBytePosition */}, /*ACC_LeTgtfusion*/
  {6u/*BitLength*/, 402u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 226u/* AppAccBytePosition */}, /*ACC_LeTgtHeading*/
  {1u/*BitLength*/, 401u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 227u/* AppAccBytePosition */}, /*ACC_RiTgtfusion*/
  {6u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 228u/* AppAccBytePosition */}, /*ACC_RiTgtHeading*/
  {1u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 229u/* AppAccBytePosition */}, /*ACC_PotentialTgtfusion*/
  {6u/*BitLength*/, 420u/* BitPosition */, 2u/* ByteLength */, 52u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 230u/* AppAccBytePosition */}, /*ACC_PotentialTgtHeading*/
  {6u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 231u/* AppAccBytePosition */}, /*TargetCutinPro*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 232u/* AppAccBytePosition */}, /*TargetCutoutPro*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 233u/* AppAccBytePosition */}, /*Longctrl_VehHldReq_DVR*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 234u/* AppAccBytePosition */}, /*Longctrl_DrvOFF_Req_DVR*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 235u/* AppAccBytePosition */}, /*Longctrl_ModSts_DVR*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 236u/* AppAccBytePosition */}, /*Longctrl_Decel_Req_DVR*/
  {16u/*BitLength*/, 96u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 237u/* AppAccBytePosition */}, /*Longctrl_EngTrqReq_DVR*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 239u/* AppAccBytePosition */}, /*Longctrl_EngTrqReqActive_DVR*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 240u/* AppAccBytePosition */}, /*Longctrl_DecelToStopReq_DVR*/
  {2u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 241u/* AppAccBytePosition */}, /*Longctrl_ParkShiftReq_DVR*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 242u/* AppAccBytePosition */}, /*Longctrl_Decel_ReqValue_DVR*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 243u/* AppAccBytePosition */}, /*ADAS_DriverInloop_Monitor*/
  {7u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 244u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dy*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 245u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dy*/
  {1u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 246u/* AppAccBytePosition */}, /*ACCSts*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 247u/* AppAccBytePosition */}, /*ACC_FD2_0x2AB*/
  {6u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 303u/* AppAccBytePosition */}, /*FCWAEB_JATTC*/
  {6u/*BitLength*/, 336u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 304u/* AppAccBytePosition */}, /*AEB_LePedHeading*/
  {6u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 305u/* AppAccBytePosition */}, /*AEB_RiPedHeading*/
  {6u/*BitLength*/, 356u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 306u/* AppAccBytePosition */}, /*AEB_LeCyclistHeading*/
  {6u/*BitLength*/, 366u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 307u/* AppAccBytePosition */}, /*AEB_RiCyclistHeading*/
  {6u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 308u/* AppAccBytePosition */}, /*FCWAEB_longTTC*/
  {6u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 309u/* AppAccBytePosition */}, /*FCWAEB_crossingTTC*/
  {6u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 310u/* AppAccBytePosition */}, /*JAPedObjExist*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 311u/* AppAccBytePosition */}, /*AEBJAObjID*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 312u/* AppAccBytePosition */}, /*AEBJAObjExist*/
  {8u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 313u/* AppAccBytePosition */}, /*JAPedObjID*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 314u/* AppAccBytePosition */}, /*AEBJAObjVideoCfmd*/
  {12u/*BitLength*/, 100u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 315u/* AppAccBytePosition */}, /*AEBJAObjVx*/
  {12u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 317u/* AppAccBytePosition */}, /*AEBJAObjDx*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 319u/* AppAccBytePosition */}, /*JAPedObjVideoCfmd*/
  {3u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 320u/* AppAccBytePosition */}, /*AEBJAObjState*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 321u/* AppAccBytePosition */}, /*AEBJAObjCntAlive*/
  {11u/*BitLength*/, 153u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 323u/* AppAccBytePosition */}, /*AEBJAObjDy*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 325u/* AppAccBytePosition */}, /*JAPedObjState*/
  {5u/*BitLength*/, 164u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 326u/* AppAccBytePosition */}, /*AEBJAObjObstcl*/
  {10u/*BitLength*/, 170u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 327u/* AppAccBytePosition */}, /*AEBJAObjVy*/
  {10u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 329u/* AppAccBytePosition */}, /*AEBJAObjAx*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 331u/* AppAccBytePosition */}, /*AEBJAObjAy*/
  {5u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 333u/* AppAccBytePosition */}, /*JAPedObjObstcl*/
  {11u/*BitLength*/, 229u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 334u/* AppAccBytePosition */}, /*JAPedObjDy*/
  {12u/*BitLength*/, 233u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 336u/* AppAccBytePosition */}, /*JAPedObjDx*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 338u/* AppAccBytePosition */}, /*JAPedObjVx*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 340u/* AppAccBytePosition */}, /*JAPedObjVy*/
  {10u/*BitLength*/, 308u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 342u/* AppAccBytePosition */}, /*JAPedObjAy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 344u/* AppAccBytePosition */}, /*JAPedObjCntAlive*/
  {10u/*BitLength*/, 342u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 346u/* AppAccBytePosition */}, /*JAPedObjAx*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 348u/* AppAccBytePosition */}, /*ACC_FD3_0x2B4*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 412u/* AppAccBytePosition */}, /*AEBObjID*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 413u/* AppAccBytePosition */}, /*AEBObjExist*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 414u/* AppAccBytePosition */}, /*AEBObjVideoCfmd*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 415u/* AppAccBytePosition */}, /*AEBObjVx*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 417u/* AppAccBytePosition */}, /*AEBObjDx*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 419u/* AppAccBytePosition */}, /*AEBObjCntAlive*/
  {11u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 421u/* AppAccBytePosition */}, /*AEBObjDy*/
  {3u/*BitLength*/, 69u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 423u/* AppAccBytePosition */}, /*AEBObjState*/
  {5u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 424u/* AppAccBytePosition */}, /*AEBObjObstcl*/
  {10u/*BitLength*/, 86u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 425u/* AppAccBytePosition */}, /*AEBObjVy*/
  {6u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 427u/* AppAccBytePosition */}, /*CyclistObjExist*/
  {10u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 428u/* AppAccBytePosition */}, /*AEBObjAx*/
  {10u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 430u/* AppAccBytePosition */}, /*AEBObjAy*/
  {12u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 432u/* AppAccBytePosition */}, /*CyclistObjDx*/
  {8u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 434u/* AppAccBytePosition */}, /*CyclistObjID*/
  {5u/*BitLength*/, 131u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 435u/* AppAccBytePosition */}, /*CyclistObjObstcl*/
  {11u/*BitLength*/, 136u/* BitPosition */, 2u/* ByteLength */, 17u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 436u/* AppAccBytePosition */}, /*CyclistObjDy*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 438u/* AppAccBytePosition */}, /*CyclistObjVx*/
  {12u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 440u/* AppAccBytePosition */}, /*CyclistObjCntAlive*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 442u/* AppAccBytePosition */}, /*CyclistObjVy*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 444u/* AppAccBytePosition */}, /*CyclistObjState*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 445u/* AppAccBytePosition */}, /*CyclistObjVideoCfmd*/
  {10u/*BitLength*/, 184u/* BitPosition */, 2u/* ByteLength */, 23u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 446u/* AppAccBytePosition */}, /*CyclistObjAx*/
  {10u/*BitLength*/, 206u/* BitPosition */, 2u/* ByteLength */, 25u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 448u/* AppAccBytePosition */}, /*CyclistObjAy*/
  {6u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 450u/* AppAccBytePosition */}, /*PedObjExist*/
  {8u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 451u/* AppAccBytePosition */}, /*PedObjID*/
  {5u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 452u/* AppAccBytePosition */}, /*PedObjObstcl*/
  {11u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 453u/* AppAccBytePosition */}, /*PedObjDy*/
  {12u/*BitLength*/, 244u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 455u/* AppAccBytePosition */}, /*PedObjDx*/
  {12u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 457u/* AppAccBytePosition */}, /*PedObjVx*/
  {10u/*BitLength*/, 270u/* BitPosition */, 2u/* ByteLength */, 33u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 459u/* AppAccBytePosition */}, /*PedObjVy*/
  {1u/*BitLength*/, 269u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 461u/* AppAccBytePosition */}, /*PedObjVideoCfmd*/
  {12u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 462u/* AppAccBytePosition */}, /*ACCTgtObjDx*/
  {10u/*BitLength*/, 294u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 464u/* AppAccBytePosition */}, /*PedObjAy*/
  {12u/*BitLength*/, 298u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 466u/* AppAccBytePosition */}, /*PedObjCntAlive*/
  {10u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 468u/* AppAccBytePosition */}, /*PedObjAx*/
  {8u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 470u/* AppAccBytePosition */}, /*ACCTgtObjID*/
  {5u/*BitLength*/, 323u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 471u/* AppAccBytePosition */}, /*ACCTgtObjObstcl*/
  {11u/*BitLength*/, 328u/* BitPosition */, 2u/* ByteLength */, 41u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 472u/* AppAccBytePosition */}, /*ACCTgtObjDy*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 474u/* AppAccBytePosition */}, /*ACCTgtObjExist*/
  {10u/*BitLength*/, 344u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 475u/* AppAccBytePosition */}, /*ACCTgtObjVy*/
  {12u/*BitLength*/, 364u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 477u/* AppAccBytePosition */}, /*ACCTgtObjVx*/
  {10u/*BitLength*/, 370u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 479u/* AppAccBytePosition */}, /*ACCTgtObjAx*/
  {10u/*BitLength*/, 376u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 481u/* AppAccBytePosition */}, /*ACCTgtObjAy*/
  {3u/*BitLength*/, 389u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 483u/* AppAccBytePosition */}, /*ACCTgtObjState*/
  {1u/*BitLength*/, 388u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 484u/* AppAccBytePosition */}, /*ACCTgtObjVideoCfmd*/
  {12u/*BitLength*/, 392u/* BitPosition */, 2u/* ByteLength */, 49u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 485u/* AppAccBytePosition */}, /*ACCTgtObjCntAlive*/
  {12u/*BitLength*/, 412u/* BitPosition */, 2u/* ByteLength */, 51u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 487u/* AppAccBytePosition */}, /*RadarHorMisalign*/
  {2u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 489u/* AppAccBytePosition */}, /*HandsoffDetd*/
  {2u/*BitLength*/, 408u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 490u/* AppAccBytePosition */}, /*DrvgOnHiWay*/
  {10u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 491u/* AppAccBytePosition */}, /*RoadCrvt*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 493u/* AppAccBytePosition */}, /*SpdLimitDst*/
  {10u/*BitLength*/, 446u/* BitPosition */, 2u/* ByteLength */, 55u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 494u/* AppAccBytePosition */}, /*RoadCrvtFar*/
  {6u/*BitLength*/, 440u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 496u/* AppAccBytePosition */}, /*RampDst*/
  {8u/*BitLength*/, 448u/* BitPosition */, 1u/* ByteLength */, 56u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 497u/* AppAccBytePosition */}, /*SpdLimit*/
  {6u/*BitLength*/, 458u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 498u/* AppAccBytePosition */}, /*CurveDst*/
  {2u/*BitLength*/, 456u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 499u/* AppAccBytePosition */}, /*NavSpdLimUnit*/
  {6u/*BitLength*/, 466u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 500u/* AppAccBytePosition */}, /*TunnelDst*/
  {2u/*BitLength*/, 464u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 501u/* AppAccBytePosition */}, /*DrvgOnRiLane*/
  {6u/*BitLength*/, 474u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 502u/* AppAccBytePosition */}, /*BrdgDst*/
  {1u/*BitLength*/, 473u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 503u/* AppAccBytePosition */}, /*RadarDrvrAttentive*/
  {2u/*BitLength*/, 483u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 504u/* AppAccBytePosition */}, /*ACC_SOSReq*/
  {3u/*BitLength*/, 480u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 505u/* AppAccBytePosition */}, /*PedObjState*/
  {1u/*BitLength*/, 495u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 506u/* AppAccBytePosition */}, /*MapDataValid*/
  {3u/*BitLength*/, 492u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 507u/* AppAccBytePosition */}, /*DrvrSts*/
  {5u/*BitLength*/, 503u/* BitPosition */, 2u/* ByteLength */, 62u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 508u/* AppAccBytePosition */}, /*AEBObjOverlap*/
  {5u/*BitLength*/, 498u/* BitPosition */, 1u/* ByteLength */, 62u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 509u/* AppAccBytePosition */}, /*AEBObjDrvby*/
  {8u/*BitLength*/, 504u/* BitPosition */, 1u/* ByteLength */, 63u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 510u/* AppAccBytePosition */}, /*ACC_DataRecReq*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 511u/* AppAccBytePosition */}, /*ACC_FD4_0x2B8*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 575u/* AppAccBytePosition */}, /*AEB_ObjSty*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 576u/* AppAccBytePosition */}, /*AEB_BrkReqFunc*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 577u/* AppAccBytePosition */}, /*AEB_FD1_0x18B*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 641u/* AppAccBytePosition */}, /*Checksum_AEB2*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 642u/* AppAccBytePosition */}, /*AEB_PedResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 643u/* AppAccBytePosition */}, /*AEB_VehResp*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 644u/* AppAccBytePosition */}, /*FCW_Snvty*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 645u/* AppAccBytePosition */}, /*AEB_JA_Resp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 646u/* AppAccBytePosition */}, /*RollingCounter_AEB2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 647u/* AppAccBytePosition */}, /*Checksum_AEB3*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 648u/* AppAccBytePosition */}, /*AEB_VehTrig*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 649u/* AppAccBytePosition */}, /*AEB_PedTrig*/
  {2u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 650u/* AppAccBytePosition */}, /*FCW_AEB_VehFctSts*/
  {2u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 651u/* AppAccBytePosition */}, /*FCW_AEB_PedFctSts*/
  {2u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 652u/* AppAccBytePosition */}, /*FCW_Warn*/
  {2u/*BitLength*/, 146u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 653u/* AppAccBytePosition */}, /*AEB_JAFuncSts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 654u/* AppAccBytePosition */}, /*AEB_JA_Warn*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 655u/* AppAccBytePosition */}, /*AEB_JABrkTrig*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 656u/* AppAccBytePosition */}, /*RollingCounter_AEB3*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 657u/* AppAccBytePosition */}, /*AEB_FD2_0x227*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 713u/* AppAccBytePosition */}, /*ALCMSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 714u/* AppAccBytePosition */}, /*ALCM1_0x2DB*/
  {7u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 722u/* AppAccBytePosition */}, /*APS_ProcBar_0x167*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 723u/* AppAccBytePosition */}, /*APS_SysSoundIndcn_0x167*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 724u/* AppAccBytePosition */}, /*APS_PrkgTyp_0x167*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 725u/* AppAccBytePosition */}, /*APA_SlotDisp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 726u/* AppAccBytePosition */}, /*APS_TextDisp_0x167*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 727u/* AppAccBytePosition */}, /*APS1_0x167*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 735u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1_0x26c*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 736u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2_0x26c*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 737u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3_0x26c*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 738u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4_0x26c*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 739u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5_0x26c*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 740u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1_0x26c*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 741u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2_0x26c*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 742u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3_0x26c*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 743u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4_0x26c*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 744u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5_0x26c*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 745u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts_0x26c*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 746u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts_0x26c*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 747u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts_0x26c*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 748u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts_0x26c*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 749u/* AppAccBytePosition */}, /*SDW_SoundIndcn_0x26c*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 750u/* AppAccBytePosition */}, /*SDWActiveSts_0x26c*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 751u/* AppAccBytePosition */}, /*APS3_0x26C*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 759u/* AppAccBytePosition */}, /*APS_WorkSts_0x13d*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 760u/* AppAccBytePosition */}, /*APS4_0x13D*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 768u/* AppAccBytePosition */}, /*IPBackgroundLmpCmd*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 769u/* AppAccBytePosition */}, /*TrunkSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 770u/* AppAccBytePosition */}, /*DrvDoorSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 771u/* AppAccBytePosition */}, /*LRDoorSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 772u/* AppAccBytePosition */}, /*PassengerDoorSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 773u/* AppAccBytePosition */}, /*RRDoorSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 774u/* AppAccBytePosition */}, /*BrkPedalSts_BCM*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 775u/* AppAccBytePosition */}, /*BackgroundLightLvl*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 776u/* AppAccBytePosition */}, /*DrowsyDrvDetWarn*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 777u/* AppAccBytePosition */}, /*RLSFailSts*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 778u/* AppAccBytePosition */}, /*ReversGearSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 779u/* AppAccBytePosition */}, /*PosnLightReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 780u/* AppAccBytePosition */}, /*BCM1_0x319*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 788u/* AppAccBytePosition */}, /*LasHdLmpSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 789u/* AppAccBytePosition */}, /*AntitheftSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 790u/* AppAccBytePosition */}, /*DrvDoorLockSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 791u/* AppAccBytePosition */}, /*DoorLockSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 792u/* AppAccBytePosition */}, /*RLDoorLockSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 793u/* AppAccBytePosition */}, /*PassDoorLockSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 794u/* AppAccBytePosition */}, /*RRDoorLockSts*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 795u/* AppAccBytePosition */}, /*HiLowBeamSts*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 796u/* AppAccBytePosition */}, /*SeatSwSts*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 797u/* AppAccBytePosition */}, /*SeatSwErrorSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 798u/* AppAccBytePosition */}, /*HazardLmpSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 799u/* AppAccBytePosition */}, /*BCM3_0x345*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 807u/* AppAccBytePosition */}, /*VolSwtReq*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 808u/* AppAccBytePosition */}, /*VolSwtErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 809u/* AppAccBytePosition */}, /*BCM6_0x28C*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 817u/* AppAccBytePosition */}, /*RemoteModSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 818u/* AppAccBytePosition */}, /*PASWorkCmd*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 819u/* AppAccBytePosition */}, /*WhistleSts*/
  {3u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 820u/* AppAccBytePosition */}, /*WiprReq_F_PBox*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 821u/* AppAccBytePosition */}, /*KL30BRelaySts*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 822u/* AppAccBytePosition */}, /*DrivingModReq*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 823u/* AppAccBytePosition */}, /*RViewMirrorSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 824u/* AppAccBytePosition */}, /*BCM8_0x29F*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 832u/* AppAccBytePosition */}, /*ClsWinRmd*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 833u/* AppAccBytePosition */}, /*FourLModeSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 834u/* AppAccBytePosition */}, /*ExpertModSwtReq*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 835u/* AppAccBytePosition */}, /*CCOSwtReq*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 836u/* AppAccBytePosition */}, /*CCO_SwtShift_Warn*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 837u/* AppAccBytePosition */}, /*TAB_SwtShift_Warn*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 838u/* AppAccBytePosition */}, /*ActvEnterTimeOut*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 839u/* AppAccBytePosition */}, /*BCM11_0x305*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 847u/* AppAccBytePosition */}, /*SrAntiPinch*/
  {7u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 848u/* AppAccBytePosition */}, /*SsPosn_VR_APP*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 849u/* AppAccBytePosition */}, /*SsAntiPinch*/
  {7u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 850u/* AppAccBytePosition */}, /*SrPosn_VR_APP*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 851u/* AppAccBytePosition */}, /*RLS_IRBrightness*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 852u/* AppAccBytePosition */}, /*RLS_FwBrightness*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 854u/* AppAccBytePosition */}, /*RLS_AmbBrightness*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 856u/* AppAccBytePosition */}, /*BCM12_0x238*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 864u/* AppAccBytePosition */}, /*AutoLmpSwtSts_CEM*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 865u/* AppAccBytePosition */}, /*AutoLmpSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 866u/* AppAccBytePosition */}, /*BCM17_0x23E*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 874u/* AppAccBytePosition */}, /*BLESecuritySts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 875u/* AppAccBytePosition */}, /*BLEConnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 876u/* AppAccBytePosition */}, /*BLE1_0x25C*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 884u/* AppAccBytePosition */}, /*BLE_BeanID*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 892u/* AppAccBytePosition */}, /*BLE5_0x1FA*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 900u/* AppAccBytePosition */}, /*CR_FCTA_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 901u/* AppAccBytePosition */}, /*CR_FCTB_Resp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 902u/* AppAccBytePosition */}, /*CR_BliSts*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 903u/* AppAccBytePosition */}, /*FCTA_Warn*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 904u/* AppAccBytePosition */}, /*FCTBTrig*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 905u/* AppAccBytePosition */}, /*FCTA_B_FuncSts*/
  {6u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 906u/* AppAccBytePosition */}, /*FCTA_B_TTC*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 907u/* AppAccBytePosition */}, /*CR_FD1_0x15E*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 971u/* AppAccBytePosition */}, /*LTurnLmpSwtSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 972u/* AppAccBytePosition */}, /*RTurnLmpSwtSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 973u/* AppAccBytePosition */}, /*HornSwtSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 974u/* AppAccBytePosition */}, /*HiBeamSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 975u/* AppAccBytePosition */}, /*CSA1_0x165*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 983u/* AppAccBytePosition */}, /*SteerWheelAng*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 985u/* AppAccBytePosition */}, /*SteerWheelAngSign*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 986u/* AppAccBytePosition */}, /*SAS_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 987u/* AppAccBytePosition */}, /*CSA2_0xA1*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 995u/* AppAccBytePosition */}, /*MenuReturnSwtSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 996u/* AppAccBytePosition */}, /*HomeSwtSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 997u/* AppAccBytePosition */}, /*MuteSwtSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 998u/* AppAccBytePosition */}, /*CustomSwtSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 999u/* AppAccBytePosition */}, /*SteerWheelHeatdSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1000u/* AppAccBytePosition */}, /*PageUpSwtSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1001u/* AppAccBytePosition */}, /*PageDwnSwtSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1002u/* AppAccBytePosition */}, /*PageLSwtSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1003u/* AppAccBytePosition */}, /*PageRSwtSts*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1004u/* AppAccBytePosition */}, /*SeekUpSwtSts*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1005u/* AppAccBytePosition */}, /*SeekDwnSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1006u/* AppAccBytePosition */}, /*AdjVolUpSwtSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1007u/* AppAccBytePosition */}, /*AdjVolDwnSwtSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1008u/* AppAccBytePosition */}, /*VRSwtSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1009u/* AppAccBytePosition */}, /*PhoneSwtSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1010u/* AppAccBytePosition */}, /*SoundSourceModSwtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1011u/* AppAccBytePosition */}, /*EnterSwtSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1012u/* AppAccBytePosition */}, /*EnterSwtSts_Mmed*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1013u/* AppAccBytePosition */}, /*CustomSwtSts_Mmed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1014u/* AppAccBytePosition */}, /*CSA3_0x244*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1022u/* AppAccBytePosition */}, /*TgtEngSpdIP*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1024u/* AppAccBytePosition */}, /*TgtEngSpdIPValid*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1025u/* AppAccBytePosition */}, /*TrsmTqIdle*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1027u/* AppAccBytePosition */}, /*DCT3_0xA6*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1035u/* AppAccBytePosition */}, /*CurrentGearValid*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1036u/* AppAccBytePosition */}, /*CURRENT_GEAR*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1037u/* AppAccBytePosition */}, /*TGS_LEVER*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1038u/* AppAccBytePosition */}, /*SHIFT_IN_PROGRESS*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1039u/* AppAccBytePosition */}, /*ShiftInPrgValid*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1040u/* AppAccBytePosition */}, /*TRANS_Warning_LAMP*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1041u/* AppAccBytePosition */}, /*TARGET_GEAR*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1042u/* AppAccBytePosition */}, /*DCT5_0x221*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1050u/* AppAccBytePosition */}, /*CheckSum_DCT7*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1051u/* AppAccBytePosition */}, /*DCT_RaceModeSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1052u/* AppAccBytePosition */}, /*DCT_PrsBrk_Warn*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1053u/* AppAccBytePosition */}, /*DCT_ShftNotAlwd_Warn*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1054u/* AppAccBytePosition */}, /*DCT_ShftRecom_M*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1055u/* AppAccBytePosition */}, /*DrvWarnMsg*/
  {4u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1056u/* AppAccBytePosition */}, /*DrvFaiMsg*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1057u/* AppAccBytePosition */}, /*DrvModDisp*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1058u/* AppAccBytePosition */}, /*DrvModDispSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1059u/* AppAccBytePosition */}, /*DrvAutoGearDisp*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1060u/* AppAccBytePosition */}, /*DrvGearDispSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1061u/* AppAccBytePosition */}, /*RollingCounter_DCT7*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1062u/* AppAccBytePosition */}, /*TRANS_OIL_TEMP*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1063u/* AppAccBytePosition */}, /*DCT_TGSSwtRsp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1064u/* AppAccBytePosition */}, /*DCT7_0x235*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1072u/* AppAccBytePosition */}, /*DrvWinAntiPinchSts*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1073u/* AppAccBytePosition */}, /*DrvWinLrnSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1074u/* AppAccBytePosition */}, /*DrvWinHotProtSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1075u/* AppAccBytePosition */}, /*DrvSideRearAntiPinchSts*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1076u/* AppAccBytePosition */}, /*DrvSideRearWinLrnSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1077u/* AppAccBytePosition */}, /*DrvSideRearWinHotProtSts*/
  {5u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1078u/* AppAccBytePosition */}, /*DrvWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1079u/* AppAccBytePosition */}, /*DDCM1_0x2CA*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1087u/* AppAccBytePosition */}, /*DrvSideRearWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1088u/* AppAccBytePosition */}, /*DDCM3_0x2F7*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1096u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1097u/* AppAccBytePosition */}, /*DSM1_0x2C1*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1105u/* AppAccBytePosition */}, /*EMS_AuthenResult*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1106u/* AppAccBytePosition */}, /*EngSpd*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1108u/* AppAccBytePosition */}, /*EngSpdVldty*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1109u/* AppAccBytePosition */}, /*BrkPedalSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1110u/* AppAccBytePosition */}, /*ECM1_0x111*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1118u/* AppAccBytePosition */}, /*FuelConsumption*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1120u/* AppAccBytePosition */}, /*TgtCrsVehSpd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1121u/* AppAccBytePosition */}, /*CruiseCtrlSts*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1122u/* AppAccBytePosition */}, /*AccelPedalPosnVldty*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1123u/* AppAccBytePosition */}, /*EngSVSSig*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1124u/* AppAccBytePosition */}, /*MILSts*/
  {2u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1125u/* AppAccBytePosition */}, /*EngState*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1126u/* AppAccBytePosition */}, /*AccelPedalPosn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1127u/* AppAccBytePosition */}, /*ECM2_0x271*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1135u/* AppAccBytePosition */}, /*EngCoolantTemp*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1136u/* AppAccBytePosition */}, /*GPF_Warning*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1137u/* AppAccBytePosition */}, /*GentrWarnLmpSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1138u/* AppAccBytePosition */}, /*EngClntTempWarn*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1139u/* AppAccBytePosition */}, /*EngClntTempVldty*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1140u/* AppAccBytePosition */}, /*SS_Screen_tip*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1141u/* AppAccBytePosition */}, /*SSSSetSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1142u/* AppAccBytePosition */}, /*SS_Enable_Lamp*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1143u/* AppAccBytePosition */}, /*SS_Fault_Lamp*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1144u/* AppAccBytePosition */}, /*BaroPressure*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1145u/* AppAccBytePosition */}, /*ECM3_0x371*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1153u/* AppAccBytePosition */}, /*NetEngTrq*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1155u/* AppAccBytePosition */}, /*DrvEngTrqReq*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1157u/* AppAccBytePosition */}, /*DrvEngTrqReqVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1158u/* AppAccBytePosition */}, /*ECM4_0x82*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1166u/* AppAccBytePosition */}, /*EngTrqEstimdActGear*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1168u/* AppAccBytePosition */}, /*EngTrqEstimdActGear_Qf*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1169u/* AppAccBytePosition */}, /*ECM7_0x84*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 14u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1177u/* AppAccBytePosition */}, /*TrqLoss*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1179u/* AppAccBytePosition */}, /*ECM8_0x86*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1187u/* AppAccBytePosition */}, /*AccelPedlPosnDiagc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1188u/* AppAccBytePosition */}, /*ECM9_0x102*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1196u/* AppAccBytePosition */}, /*EngSpd_ForIP*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1198u/* AppAccBytePosition */}, /*ECM11_0x2D3*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1206u/* AppAccBytePosition */}, /*ECM_VIN*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1214u/* AppAccBytePosition */}, /*ECM19_0x3B5*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 23u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1222u/* AppAccBytePosition */}, /*ECM_VehDstBackup*/
  {11u/*BitLength*/, 53u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1226u/* AppAccBytePosition */}, /*EngRoStrt_Failure*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1228u/* AppAccBytePosition */}, /*ECM20_0x3B7*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1236u/* AppAccBytePosition */}, /*TranPMode_Sts*/
  {3u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1237u/* AppAccBytePosition */}, /*Stat_PwrSv_Lvl*/
  {2u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1238u/* AppAccBytePosition */}, /*DeepSlpCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1239u/* AppAccBytePosition */}, /*Dyn_PwrSv_Lvl*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1240u/* AppAccBytePosition */}, /*LvPwrSysErr*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1241u/* AppAccBytePosition */}, /*LimitStartSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1242u/* AppAccBytePosition */}, /*EEM1_0x2A8*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1250u/* AppAccBytePosition */}, /*CheckSum_EPB1*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1251u/* AppAccBytePosition */}, /*PressBrakePedalPointOut*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1252u/* AppAccBytePosition */}, /*EPBErrSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1253u/* AppAccBytePosition */}, /*EPBSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1254u/* AppAccBytePosition */}, /*EPBTextDisp*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1255u/* AppAccBytePosition */}, /*EPBRedLmpSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1256u/* AppAccBytePosition */}, /*RollingCounter_EPB1*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1257u/* AppAccBytePosition */}, /*EPB_SwtPosn*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1258u/* AppAccBytePosition */}, /*EPB_VirtSwtAvailable*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1259u/* AppAccBytePosition */}, /*EPB1_0x16B*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1267u/* AppAccBytePosition */}, /*EPS_FailSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1268u/* AppAccBytePosition */}, /*CheckSum_EPS1*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1269u/* AppAccBytePosition */}, /*EPS_SteerMod*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1270u/* AppAccBytePosition */}, /*RollingCounter_EPS1*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1271u/* AppAccBytePosition */}, /*EPS_AssiRat*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1272u/* AppAccBytePosition */}, /*EPS1_0x168*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1280u/* AppAccBytePosition */}, /*CheckSum_ESP1*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1281u/* AppAccBytePosition */}, /*ESPFuncOffSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1282u/* AppAccBytePosition */}, /*ESPActvInfoLmp*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1283u/* AppAccBytePosition */}, /*ESPFailSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1284u/* AppAccBytePosition */}, /*RollingCounter_ESP1*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1285u/* AppAccBytePosition */}, /*VDCActv*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1286u/* AppAccBytePosition */}, /*PTCActv*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1287u/* AppAccBytePosition */}, /*BTCActv*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1288u/* AppAccBytePosition */}, /*ESP1_0x149*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1296u/* AppAccBytePosition */}, /*CheckSum_ESP2*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1297u/* AppAccBytePosition */}, /*HDCFault*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1298u/* AppAccBytePosition */}, /*HDCCtrl*/
  {2u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1299u/* AppAccBytePosition */}, /*AVHErrSts*/
  {2u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1300u/* AppAccBytePosition */}, /*AVHSts*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1301u/* AppAccBytePosition */}, /*CDPActv*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1302u/* AppAccBytePosition */}, /*DrivingModDis*/
  {5u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1303u/* AppAccBytePosition */}, /*DrivingModReq_ESP*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1304u/* AppAccBytePosition */}, /*RollingCounter_ESP2*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1305u/* AppAccBytePosition */}, /*AEBIBActv*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1306u/* AppAccBytePosition */}, /*AEBBAActv*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1307u/* AppAccBytePosition */}, /*AEBAvailable*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 6u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 1308u/* AppAccBytePosition */}, /*ESP2_0x145*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1324u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1_0x26d*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1325u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2_0x26d*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1326u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1_0x26d*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1327u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2_0x26d*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1328u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1_0x26d*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1329u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2_0x26d*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1330u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1_0x26d*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1331u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2_0x26d*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1332u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts_0x26d*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1333u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts_0x26d*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1334u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts_0x26d*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1335u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts_0x26d*/
  {2u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1336u/* AppAccBytePosition */}, /*FPAS_WorkSts_0x26d*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1337u/* AppAccBytePosition */}, /*FPAS_AutoModSts_0x26d*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1338u/* AppAccBytePosition */}, /*FPAS_SoundIndcn_0x26d*/
  {7u/*BitLength*/, 60u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1339u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn_0x26d*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1340u/* AppAccBytePosition */}, /*FPAS_DispCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1341u/* AppAccBytePosition */}, /*FPAS1_0x26D*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1349u/* AppAccBytePosition */}, /*HiBeamSts_F_PBox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1350u/* AppAccBytePosition */}, /*HoodSts_F_PBox*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1351u/* AppAccBytePosition */}, /*FFogLmpSts_F_PBox*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1352u/* AppAccBytePosition */}, /*LasHdLmpSts_F_PBox*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1353u/* AppAccBytePosition */}, /*LHiBeamFailSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1354u/* AppAccBytePosition */}, /*RHiBeamFailSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1355u/* AppAccBytePosition */}, /*LLowBeamFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1356u/* AppAccBytePosition */}, /*RLowBeamFailSts*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1357u/* AppAccBytePosition */}, /*LLasHdLmpDiagSig*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1358u/* AppAccBytePosition */}, /*RLasHdLmpDiagSig*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1359u/* AppAccBytePosition */}, /*LHeadLmpFailSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1360u/* AppAccBytePosition */}, /*RHeadLmpFailSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1361u/* AppAccBytePosition */}, /*LFPosnLmpFailSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1362u/* AppAccBytePosition */}, /*RFPosnLmpFailSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1363u/* AppAccBytePosition */}, /*FFogLmpFailSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1364u/* AppAccBytePosition */}, /*WhistleSts_F_PBox*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1365u/* AppAccBytePosition */}, /*DayRunngLmpFailSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1366u/* AppAccBytePosition */}, /*LowBeamSts_F_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1367u/* AppAccBytePosition */}, /*F_PBOX1_0x19B*/
  {14u/*BitLength*/, 74u/* BitPosition */, 2u/* ByteLength */, 9u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1375u/* AppAccBytePosition */}, /*U_BATT*/
  {2u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1377u/* AppAccBytePosition */}, /*I_RANGE*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 25u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1378u/* AppAccBytePosition */}, /*I_BATT*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1380u/* AppAccBytePosition */}, /*SOC*/
  {8u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1381u/* AppAccBytePosition */}, /*SOH_SUL*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1382u/* AppAccBytePosition */}, /*SOC_STATE*/
  {2u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1383u/* AppAccBytePosition */}, /*SOH_SUL_STATE*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1384u/* AppAccBytePosition */}, /*CheckSum_GWM1*/
  {2u/*BitLength*/, 342u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1385u/* AppAccBytePosition */}, /*OTA_UpgrdModSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1386u/* AppAccBytePosition */}, /*RollingCounter_GWM1*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1387u/* AppAccBytePosition */}, /*GW_FD1_0x2BB*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1451u/* AppAccBytePosition */}, /*OTAUpgrdSts*/
  {2u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1452u/* AppAccBytePosition */}, /*OTA_UpgrdModErrCode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1453u/* AppAccBytePosition */}, /*GW_OTA_0x1D9*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1461u/* AppAccBytePosition */}, /*ResetCount*/
  {88u/*BitLength*/, 40u/* BitPosition */, 11u/* ByteLength */, 5u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 26u/* InitValueIdx */, 11u/* AppAccBtyeLength */, 1463u/* AppAccBytePosition */}, /*CMACMessageInfo*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 23u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1474u/* AppAccBytePosition */}, /*TripCount*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1478u/* AppAccBytePosition */}, /*LParaPrkgOutVald_0x144*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1479u/* AppAccBytePosition */}, /*RParaPrkgOutVald_0x144*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1480u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald_0x144*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1481u/* AppAccBytePosition */}, /*TailVertPrkgOutVald_0x144*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1482u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd_0x144*/
  {4u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1483u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts_0x144*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1484u/* AppAccBytePosition */}, /*HAP1_0x144*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1492u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd_0x19e*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1493u/* AppAccBytePosition */}, /*APA_FuncSts_0x19e*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1494u/* AppAccBytePosition */}, /*HAP2_0x19E*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1502u/* AppAccBytePosition */}, /*APS_PrkgMod*/
  {7u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1503u/* AppAccBytePosition */}, /*APS_ProcBar_0x15b*/
  {1u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1504u/* AppAccBytePosition */}, /*APS_SwtSts*/
  {3u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1505u/* AppAccBytePosition */}, /*APS_SlotDisp*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1506u/* AppAccBytePosition */}, /*APS_SysSoundIndcn_0x15b*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1507u/* AppAccBytePosition */}, /*APS_PrkgTyp_0x15b*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1508u/* AppAccBytePosition */}, /*APS_TextDisp_0x15b*/
  {3u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1509u/* AppAccBytePosition */}, /*APS_WorkSts_0x15b*/
  {1u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1510u/* AppAccBytePosition */}, /*LParaPrkgOutVald_0x15b*/
  {1u/*BitLength*/, 282u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1511u/* AppAccBytePosition */}, /*RParaPrkgOutVald_0x15b*/
  {1u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1512u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald_0x15b*/
  {1u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1513u/* AppAccBytePosition */}, /*TailVertPrkgOutVald_0x15b*/
  {3u/*BitLength*/, 277u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1514u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd_0x15b*/
  {4u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1515u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts_0x15b*/
  {2u/*BitLength*/, 294u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1516u/* AppAccBytePosition */}, /*APS_MovgDirc*/
  {2u/*BitLength*/, 366u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1517u/* AppAccBytePosition */}, /*ParallelSlotBtn_Ena*/
  {2u/*BitLength*/, 364u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1518u/* AppAccBytePosition */}, /*VerticalSlotBtn_Ena*/
  {2u/*BitLength*/, 362u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1519u/* AppAccBytePosition */}, /*ClockwiseBtn_Ena*/
  {2u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1520u/* AppAccBytePosition */}, /*AnticlockwiseBtn_Ena*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1521u/* AppAccBytePosition */}, /*SlotConfirmBtn_Ena*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1522u/* AppAccBytePosition */}, /*HAP_FD1_0x15B*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1586u/* AppAccBytePosition */}, /*AutoAVMSwtSet_Sts*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1587u/* AppAccBytePosition */}, /*AVM_CurrSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1588u/* AppAccBytePosition */}, /*GuidOvlSts*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1589u/* AppAccBytePosition */}, /*FrntCamInpFailSts*/
  {1u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1590u/* AppAccBytePosition */}, /*RearCamInpFailSts*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1591u/* AppAccBytePosition */}, /*LeCamInpFailSts*/
  {1u/*BitLength*/, 111u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1592u/* AppAccBytePosition */}, /*RiCamInpFailSts*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1593u/* AppAccBytePosition */}, /*EolNotCmpltd*/
  {1u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1594u/* AppAccBytePosition */}, /*OvlOpFailSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1595u/* AppAccBytePosition */}, /*LaneCalSts*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1596u/* AppAccBytePosition */}, /*RadarDispSts*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1597u/* AppAccBytePosition */}, /*LaneCalFltSts*/
  {1u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1598u/* AppAccBytePosition */}, /*AutoViewChgFuncSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1599u/* AppAccBytePosition */}, /*CarMdlTrsprcySts*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1600u/* AppAccBytePosition */}, /*CarMdlDispSts*/
  {1u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1601u/* AppAccBytePosition */}, /*CurrCalResultSts*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1602u/* AppAccBytePosition */}, /*MdlColrSts*/
  {6u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1603u/* AppAccBytePosition */}, /*SigViewIndcn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1604u/* AppAccBytePosition */}, /*HAP_DispCmd*/
  {9u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1605u/* AppAccBytePosition */}, /*AVM_3DAngSts*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1607u/* AppAccBytePosition */}, /*MOD_WorkSts*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1608u/* AppAccBytePosition */}, /*MOD_AlarmSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1609u/* AppAccBytePosition */}, /*HAP_Hmi_Index*/
  {2u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1610u/* AppAccBytePosition */}, /*DVRWorkSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1611u/* AppAccBytePosition */}, /*HAP_FD2_0x274*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1675u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn_0x298*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1676u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1_0x298*/
  {4u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1677u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2_0x298*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1678u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3_0x298*/
  {4u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1679u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4_0x298*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1680u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5_0x298*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1681u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1_0x298*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1682u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2_0x298*/
  {4u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1683u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3_0x298*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1684u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4_0x298*/
  {4u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1685u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5_0x298*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1686u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts_0x298*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1687u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts_0x298*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1688u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts_0x298*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1689u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts_0x298*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1690u/* AppAccBytePosition */}, /*SDW_SoundIndcn_0x298*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1691u/* AppAccBytePosition */}, /*SDWActiveSts_0x298*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1692u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1_0x298*/
  {4u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1693u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2_0x298*/
  {4u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1694u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1_0x298*/
  {4u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1695u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2_0x298*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1696u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1_0x298*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1697u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2_0x298*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1698u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1_0x298*/
  {4u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1699u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2_0x298*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1700u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts_0x298*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1701u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts_0x298*/
  {1u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1702u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts_0x298*/
  {1u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1703u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts_0x298*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1704u/* AppAccBytePosition */}, /*RPAS_WorkSts_0x298*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1705u/* AppAccBytePosition */}, /*RPAS_SoundIndcn_0x298*/
  {2u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1706u/* AppAccBytePosition */}, /*MEBWorkSts_0x298*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1707u/* AppAccBytePosition */}, /*MEB_EnableSts_0x298*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1708u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1_0x298*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1709u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2_0x298*/
  {4u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1710u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1_0x298*/
  {4u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1711u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2_0x298*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1712u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1_0x298*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1713u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2_0x298*/
  {4u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1714u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1_0x298*/
  {4u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1715u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2_0x298*/
  {1u/*BitLength*/, 239u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1716u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts_0x298*/
  {1u/*BitLength*/, 238u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1717u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts_0x298*/
  {1u/*BitLength*/, 237u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1718u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts_0x298*/
  {1u/*BitLength*/, 236u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1719u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts_0x298*/
  {2u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1720u/* AppAccBytePosition */}, /*FPAS_WorkSts_0x298*/
  {1u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1721u/* AppAccBytePosition */}, /*FPAS_AutoModSts_0x298*/
  {2u/*BitLength*/, 246u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1722u/* AppAccBytePosition */}, /*FPAS_SoundIndcn_0x298*/
  {7u/*BitLength*/, 252u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1723u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn_0x298*/
  {4u/*BitLength*/, 276u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1724u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd_0x298*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1725u/* AppAccBytePosition */}, /*APA_FuncSts_0x298*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1726u/* AppAccBytePosition */}, /*RADS_FuncSts*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1727u/* AppAccBytePosition */}, /*FADS_FuncSts*/
  {2u/*BitLength*/, 274u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1728u/* AppAccBytePosition */}, /*HAP_TextIconDispCtrl*/
  {1u/*BitLength*/, 447u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1729u/* AppAccBytePosition */}, /*FrntCamDirtySts*/
  {1u/*BitLength*/, 446u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1730u/* AppAccBytePosition */}, /*RearCamDirtySts*/
  {1u/*BitLength*/, 445u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1731u/* AppAccBytePosition */}, /*LeCamDirtySts*/
  {1u/*BitLength*/, 444u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1732u/* AppAccBytePosition */}, /*RiCamDirtySts*/
  {1u/*BitLength*/, 432u/* BitPosition */, 1u/* ByteLength */, 54u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1733u/* AppAccBytePosition */}, /*DVRCamDirtySts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1734u/* AppAccBytePosition */}, /*HAP_FD3_0x298*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1798u/* AppAccBytePosition */}, /*HAP_RtCam_WorkSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1799u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_ID*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1800u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_type*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1801u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Confidence*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1802u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1804u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1806u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_ID*/
  {3u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1807u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_type*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1808u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Confidence*/
  {12u/*BitLength*/, 92u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1809u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1811u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1813u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_ID*/
  {3u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1814u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_type*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1815u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Confidence*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1816u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1818u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1820u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_ID*/
  {3u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1821u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_type*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1822u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Confidence*/
  {12u/*BitLength*/, 220u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1823u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1825u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_Y*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1827u/* AppAccBytePosition */}, /*USS_FLSide1_Status*/
  {7u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1828u/* AppAccBytePosition */}, /*USS_FLSide1_Dist*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1829u/* AppAccBytePosition */}, /*USS_RLSide2_Status*/
  {7u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1830u/* AppAccBytePosition */}, /*USS_RLSide2_Dist*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1831u/* AppAccBytePosition */}, /*USS_FRSide1_Status*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1832u/* AppAccBytePosition */}, /*USS_FRSide1_Dist*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1833u/* AppAccBytePosition */}, /*USS_RRSide2_Status*/
  {7u/*BitLength*/, 297u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1834u/* AppAccBytePosition */}, /*USS_RRSide2_Dist*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1835u/* AppAccBytePosition */}, /*HAP_FD6_0x289*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1899u/* AppAccBytePosition */}, /*HAVP_HUT_TextDisp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1900u/* AppAccBytePosition */}, /*HAP_FD7_0x29B*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1964u/* AppAccBytePosition */}, /*HUD_SwtSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 27u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1965u/* AppAccBytePosition */}, /*HUD_BrightnessLvl*/
  {5u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 28u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1966u/* AppAccBytePosition */}, /*HUD_HeightLvl*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1967u/* AppAccBytePosition */}, /*HUD_UIMod*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1968u/* AppAccBytePosition */}, /*HUD_UIModVld*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1969u/* AppAccBytePosition */}, /*HUD_Manufactor*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1970u/* AppAccBytePosition */}, /*HUD_ReslType*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1971u/* AppAccBytePosition */}, /*HUD1_0x325*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1979u/* AppAccBytePosition */}, /*Checksum_IFC3*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1980u/* AppAccBytePosition */}, /*LDWResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1981u/* AppAccBytePosition */}, /*LKAResp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1982u/* AppAccBytePosition */}, /*LCKResp*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1983u/* AppAccBytePosition */}, /*AESResp*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1984u/* AppAccBytePosition */}, /*ELKResp*/
  {2u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1985u/* AppAccBytePosition */}, /*LDW_LKA_Snvty*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1986u/* AppAccBytePosition */}, /*IFCHUTInterface*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1987u/* AppAccBytePosition */}, /*LSSWarnFormResp*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1988u/* AppAccBytePosition */}, /*LSSResp*/
  {1u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1989u/* AppAccBytePosition */}, /*IntelligentEvaResp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1990u/* AppAccBytePosition */}, /*ESS_Pedresp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1991u/* AppAccBytePosition */}, /*ESS_Vehresp*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1992u/* AppAccBytePosition */}, /*AESSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1993u/* AppAccBytePosition */}, /*ESSSts*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1994u/* AppAccBytePosition */}, /*AESErrSts*/
  {1u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1995u/* AppAccBytePosition */}, /*ESSErrSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1996u/* AppAccBytePosition */}, /*RollingCounter_IFC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1997u/* AppAccBytePosition */}, /*Checksum_IFC4*/
  {2u/*BitLength*/, 153u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1998u/* AppAccBytePosition */}, /*IFCCalibrationSts*/
  {1u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1999u/* AppAccBytePosition */}, /*CameraBlockageSts*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2000u/* AppAccBytePosition */}, /*LDW_LKAWarn*/
  {3u/*BitLength*/, 139u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2001u/* AppAccBytePosition */}, /*LSSIntervention*/
  {3u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2002u/* AppAccBytePosition */}, /*LSSFuncSts*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2003u/* AppAccBytePosition */}, /*ELKMainState*/
  {2u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2004u/* AppAccBytePosition */}, /*LaneAvailability*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2005u/* AppAccBytePosition */}, /*TJA_FollowSts*/
  {3u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2006u/* AppAccBytePosition */}, /*LSSErrSts*/
  {3u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2007u/* AppAccBytePosition */}, /*IFC_Handsoffwarn*/
  {2u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2008u/* AppAccBytePosition */}, /*ELKActSts*/
  {2u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2009u/* AppAccBytePosition */}, /*IntelligentEvaActSts*/
  {2u/*BitLength*/, 162u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2010u/* AppAccBytePosition */}, /*LCKStsIndcr*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2011u/* AppAccBytePosition */}, /*AESintervention*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2012u/* AppAccBytePosition */}, /*ESSintervention*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2013u/* AppAccBytePosition */}, /*RollingCounter_IFC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2014u/* AppAccBytePosition */}, /*Checksum_IFC5*/
  {12u/*BitLength*/, 212u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2015u/* AppAccBytePosition */}, /*IFC_LaneCurve*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2017u/* AppAccBytePosition */}, /*IFC_LeLaneTyp*/
  {3u/*BitLength*/, 222u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2018u/* AppAccBytePosition */}, /*IFC_RiLaneTyp*/
  {3u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2019u/* AppAccBytePosition */}, /*IFC_NextLeLaneTyp*/
  {3u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2020u/* AppAccBytePosition */}, /*IFC_NextRiLaneTyp*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2021u/* AppAccBytePosition */}, /*IFC_LeLane_dy*/
  {12u/*BitLength*/, 240u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2023u/* AppAccBytePosition */}, /*IFC_RiLane_dy*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2025u/* AppAccBytePosition */}, /*RollingCounter_IFC5*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2026u/* AppAccBytePosition */}, /*Checksum_IFC6*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2027u/* AppAccBytePosition */}, /*IFC_NextLeLane_dy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 30u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2029u/* AppAccBytePosition */}, /*IFC_NextRiLane_dy*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2031u/* AppAccBytePosition */}, /*RollingCounter_IFC6*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 2032u/* AppAccBytePosition */}, /*IFC_FD2_0x23D*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2088u/* AppAccBytePosition */}, /*TSRResp*/
  {2u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2089u/* AppAccBytePosition */}, /*TSRSpdLimUnit*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2090u/* AppAccBytePosition */}, /*TSRSpdLim*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2091u/* AppAccBytePosition */}, /*TSRSpdLimCfdc*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2092u/* AppAccBytePosition */}, /*TSRSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2093u/* AppAccBytePosition */}, /*TSRSpdLimSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2094u/* AppAccBytePosition */}, /*TSRTrfcSignValCfdc*/
  {8u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2095u/* AppAccBytePosition */}, /*TSRTrfcSignVal*/
  {1u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2096u/* AppAccBytePosition */}, /*TSRSpdLimWarn*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2097u/* AppAccBytePosition */}, /*TSRWarnResp*/
  {5u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2098u/* AppAccBytePosition */}, /*TSR_Snvty*/
  {2u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2099u/* AppAccBytePosition */}, /*IDC_L2_TurnLightReq*/
  {2u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2100u/* AppAccBytePosition */}, /*HWA_TakOver_Req*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2101u/* AppAccBytePosition */}, /*HWA_TakOver_Trig*/
  {4u/*BitLength*/, 138u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2102u/* AppAccBytePosition */}, /*HWA_WarnInfoDisp*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2103u/* AppAccBytePosition */}, /*IFC_Line01_Source*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2104u/* AppAccBytePosition */}, /*IFC_Line02_Source*/
  {3u/*BitLength*/, 181u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2105u/* AppAccBytePosition */}, /*HWA_InhibitWarn*/
  {1u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2106u/* AppAccBytePosition */}, /*RainMode_Swt_Resp*/
  {2u/*BitLength*/, 226u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2107u/* AppAccBytePosition */}, /*LCMode_Swt_Resp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2108u/* AppAccBytePosition */}, /*IFC_FD3_0x2CF*/
  {13u/*BitLength*/, 19u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2172u/* AppAccBytePosition */}, /*IFC_Line01_Dy*/
  {15u/*BitLength*/, 36u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2174u/* AppAccBytePosition */}, /*IFC_Line01_Curv*/
  {20u/*BitLength*/, 48u/* BitPosition */, 3u/* ByteLength */, 6u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2176u/* AppAccBytePosition */}, /*IFC_Line01_CurvChange*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2180u/* AppAccBytePosition */}, /*IFC_Line01_Type*/
  {13u/*BitLength*/, 83u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2181u/* AppAccBytePosition */}, /*IFC_Line02_Dy*/
  {15u/*BitLength*/, 100u/* BitPosition */, 3u/* ByteLength */, 12u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2183u/* AppAccBytePosition */}, /*IFC_Line02_Curv*/
  {20u/*BitLength*/, 112u/* BitPosition */, 3u/* ByteLength */, 14u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2185u/* AppAccBytePosition */}, /*IFC_Line02_CurvChange*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2189u/* AppAccBytePosition */}, /*IFC_Line02_Type*/
  {13u/*BitLength*/, 147u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2190u/* AppAccBytePosition */}, /*IFC_Line03_Dy*/
  {15u/*BitLength*/, 164u/* BitPosition */, 3u/* ByteLength */, 20u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2192u/* AppAccBytePosition */}, /*IFC_Line03_Curv*/
  {20u/*BitLength*/, 176u/* BitPosition */, 3u/* ByteLength */, 22u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2194u/* AppAccBytePosition */}, /*IFC_Line03_CurvChange*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2198u/* AppAccBytePosition */}, /*IFC_Line03_Type*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2199u/* AppAccBytePosition */}, /*IFC_Line04_Dy*/
  {15u/*BitLength*/, 228u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2201u/* AppAccBytePosition */}, /*IFC_Line04_Curv*/
  {20u/*BitLength*/, 240u/* BitPosition */, 3u/* ByteLength */, 30u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2203u/* AppAccBytePosition */}, /*IFC_Line04_CurvChange*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2207u/* AppAccBytePosition */}, /*IFC_Line04_Type*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2208u/* AppAccBytePosition */}, /*IFC_Roadedge01_Dy*/
  {15u/*BitLength*/, 292u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2210u/* AppAccBytePosition */}, /*IFC_Roadedge01_Curv*/
  {20u/*BitLength*/, 304u/* BitPosition */, 3u/* ByteLength */, 38u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2212u/* AppAccBytePosition */}, /*IFC_Roadedge01_CurvChange*/
  {4u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2216u/* AppAccBytePosition */}, /*IFC_Roadedge01_Type*/
  {13u/*BitLength*/, 339u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 31u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2217u/* AppAccBytePosition */}, /*IFC_Roadedge02_Dy*/
  {15u/*BitLength*/, 356u/* BitPosition */, 3u/* ByteLength */, 44u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2219u/* AppAccBytePosition */}, /*IFC_Roadedge02_Curv*/
  {20u/*BitLength*/, 368u/* BitPosition */, 3u/* ByteLength */, 46u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 33u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2221u/* AppAccBytePosition */}, /*IFC_Roadedge02_CurvChange*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2225u/* AppAccBytePosition */}, /*IFC_Roadedge02_Type*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2226u/* AppAccBytePosition */}, /*IFC_FD5_0x19F*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2290u/* AppAccBytePosition */}, /*IFC_Line01_DxStart*/
  {15u/*BitLength*/, 34u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2292u/* AppAccBytePosition */}, /*IFC_Line01_DxEnd*/
  {9u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2294u/* AppAccBytePosition */}, /*IFC_Line01_HeadingAngle*/
  {9u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2296u/* AppAccBytePosition */}, /*IFC_Line02_HeadingAngle*/
  {15u/*BitLength*/, 81u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2298u/* AppAccBytePosition */}, /*IFC_Line02_DxStart*/
  {15u/*BitLength*/, 97u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2300u/* AppAccBytePosition */}, /*IFC_Line02_DxEnd*/
  {15u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2302u/* AppAccBytePosition */}, /*IFC_Line03_DxStart*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2304u/* AppAccBytePosition */}, /*IFC_Line03_DxEnd*/
  {9u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2306u/* AppAccBytePosition */}, /*IFC_Line03_HeadingAngle*/
  {15u/*BitLength*/, 169u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2308u/* AppAccBytePosition */}, /*IFC_Line04_DxStart*/
  {9u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2310u/* AppAccBytePosition */}, /*IFC_Line04_HeadingAngle*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2312u/* AppAccBytePosition */}, /*IFC_Line04_DxEnd*/
  {15u/*BitLength*/, 225u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2314u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxStart*/
  {15u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2316u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxEnd*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2318u/* AppAccBytePosition */}, /*IFC_Roadedge01_HeadingAngle*/
  {15u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2320u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxStart*/
  {15u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2322u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxEnd*/
  {9u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 34u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2324u/* AppAccBytePosition */}, /*IFC_Roadedge02_HeadingAngle*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2326u/* AppAccBytePosition */}, /*IFC_FD6_0x222*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2390u/* AppAccBytePosition */}, /*PassWinAntiPinchSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2391u/* AppAccBytePosition */}, /*PassWinLrnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2392u/* AppAccBytePosition */}, /*PassWinHotProtSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2393u/* AppAccBytePosition */}, /*PassSideRearWinAntiPinchSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2394u/* AppAccBytePosition */}, /*PassSideRearWinLrnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2395u/* AppAccBytePosition */}, /*PassSideRearWinHotProtSts*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2396u/* AppAccBytePosition */}, /*PassWinPosnSts_Perc*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2397u/* AppAccBytePosition */}, /*PassSideRearWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2398u/* AppAccBytePosition */}, /*PDCM1_0x2CD*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2406u/* AppAccBytePosition */}, /*StartModSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2407u/* AppAccBytePosition */}, /*SysPowerMod*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2408u/* AppAccBytePosition */}, /*SysPowerModVld*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2409u/* AppAccBytePosition */}, /*PEPS_PowerRlyOutpSts*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2410u/* AppAccBytePosition */}, /*RemUpgrdModSysPower*/
  {2u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2411u/* AppAccBytePosition */}, /*RemPowerFailureSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2412u/* AppAccBytePosition */}, /*PEPS2_0x295*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2420u/* AppAccBytePosition */}, /*WarnPowerNotInOffPosn*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2421u/* AppAccBytePosition */}, /*WarnKeyInCarWhenExit*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2422u/* AppAccBytePosition */}, /*WarnVldKeyNotFound*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2423u/* AppAccBytePosition */}, /*WarnEngStrtNotMeet*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2424u/* AppAccBytePosition */}, /*PowerRlyFault*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2425u/* AppAccBytePosition */}, /*AntLostFlg*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2426u/* AppAccBytePosition */}, /*PEPS4_0x302*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2434u/* AppAccBytePosition */}, /*PLG_Sts*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2435u/* AppAccBytePosition */}, /*PLG_SysFlt*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2436u/* AppAccBytePosition */}, /*PLG_InitLearnedSts*/
  {3u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2437u/* AppAccBytePosition */}, /*PLG_HeightSetSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2438u/* AppAccBytePosition */}, /*PLG_1_0x2FE*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2446u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts_0x26e*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2447u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts_0x26e*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2448u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts_0x26e*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2449u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts_0x26e*/
  {2u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2450u/* AppAccBytePosition */}, /*RPAS_WorkSts_0x26e*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2451u/* AppAccBytePosition */}, /*RPAS_SoundIndcn_0x26e*/
  {2u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2452u/* AppAccBytePosition */}, /*MEBWorkSts_0x26e*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2453u/* AppAccBytePosition */}, /*MEB_EnableSts_0x26e*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2454u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1_0x26e*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2455u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2_0x26e*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2456u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1_0x26e*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2457u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2_0x26e*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2458u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1_0x26e*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2459u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2_0x26e*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2460u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1_0x26e*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2461u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2_0x26e*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2462u/* AppAccBytePosition */}, /*RPAS1_0x26E*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2470u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn_0x2ed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2471u/* AppAccBytePosition */}, /*RPAS2_0x2ED*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2479u/* AppAccBytePosition */}, /*RSDS_IPSoundReq*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2480u/* AppAccBytePosition */}, /*BSD_LCA_warningReqRight*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2481u/* AppAccBytePosition */}, /*BSD_LCA_warningReqleft*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2482u/* AppAccBytePosition */}, /*DOW_warningReqRight*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2483u/* AppAccBytePosition */}, /*DOW_warningReqleft*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2484u/* AppAccBytePosition */}, /*RSDS_ErrSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2485u/* AppAccBytePosition */}, /*RSDS_BrkgTrig*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2486u/* AppAccBytePosition */}, /*RSDS_BliSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2487u/* AppAccBytePosition */}, /*RSDS_TrailerSts*/
  {1u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2488u/* AppAccBytePosition */}, /*RSDS_LCAResp*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2489u/* AppAccBytePosition */}, /*RSDS_DOWResp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2490u/* AppAccBytePosition */}, /*RSDS_RCWResp*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2491u/* AppAccBytePosition */}, /*RSDS_RCTAResp*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2492u/* AppAccBytePosition */}, /*RSDS_RCTABrkResp*/
  {2u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2493u/* AppAccBytePosition */}, /*RSDS_RCW_Trigger*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2494u/* AppAccBytePosition */}, /*RSDS_CTA_Actv*/
  {1u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2495u/* AppAccBytePosition */}, /*RCTA_warningReqRight*/
  {1u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2496u/* AppAccBytePosition */}, /*RCTA_warningReqLeft*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2497u/* AppAccBytePosition */}, /*RSDS_FD1_0x16F*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2561u/* AppAccBytePosition */}, /*RCTA_B_TTC*/
  {6u/*BitLength*/, 20u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2562u/* AppAccBytePosition */}, /*BSD_LCA_Left_TTC*/
  {6u/*BitLength*/, 30u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2563u/* AppAccBytePosition */}, /*BSD_LCA_Right_TTC*/
  {6u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2564u/* AppAccBytePosition */}, /*RCW_TTC*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2565u/* AppAccBytePosition */}, /*RSDS_LeTgt_01*/
  {10u/*BitLength*/, 94u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2566u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dx*/
  {7u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2568u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dy*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2569u/* AppAccBytePosition */}, /*RSDS_LeTgt_02*/
  {10u/*BitLength*/, 99u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2570u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dx*/
  {7u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2572u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dy*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2573u/* AppAccBytePosition */}, /*RSDS_RiTgt_01*/
  {10u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2574u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dx*/
  {7u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2576u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dy*/
  {1u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2577u/* AppAccBytePosition */}, /*RSDS_RiTgt_02*/
  {10u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2578u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dx*/
  {7u/*BitLength*/, 167u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2580u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dy*/
  {1u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2581u/* AppAccBytePosition */}, /*RSDS_MidTgt_01*/
  {10u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2582u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dx*/
  {7u/*BitLength*/, 181u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2584u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dy*/
  {1u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2585u/* AppAccBytePosition */}, /*RSDS_MidTgt_02*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2586u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dx*/
  {7u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2588u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dy*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2589u/* AppAccBytePosition */}, /*RSDS_FD2_0x30A*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2653u/* AppAccBytePosition */}, /*HiPosnBrkLmpFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2654u/* AppAccBytePosition */}, /*LicPlateLmpFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2655u/* AppAccBytePosition */}, /*LBrkLmpFailSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2656u/* AppAccBytePosition */}, /*RFogLmpFailSts_R_PBox*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2657u/* AppAccBytePosition */}, /*RFogLmpSts_R_PBox*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2658u/* AppAccBytePosition */}, /*ParkLmpSts_R_PBox*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2659u/* AppAccBytePosition */}, /*RBrkLmpFailSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2660u/* AppAccBytePosition */}, /*PosnLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2661u/* AppAccBytePosition */}, /*RRPosnLmpFailSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2662u/* AppAccBytePosition */}, /*RvsLmpFailSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2663u/* AppAccBytePosition */}, /*LRPosnLmpFailSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2664u/* AppAccBytePosition */}, /*RTurnLmpFailSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2665u/* AppAccBytePosition */}, /*LTurnLmpFailSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2666u/* AppAccBytePosition */}, /*LTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2667u/* AppAccBytePosition */}, /*RTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2668u/* AppAccBytePosition */}, /*LBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2669u/* AppAccBytePosition */}, /*RBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2670u/* AppAccBytePosition */}, /*HiPosnBrkLmpOutpSts_R_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2671u/* AppAccBytePosition */}, /*R_PBOX1_0x19C*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2679u/* AppAccBytePosition */}, /*DrvSeatHeatSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2680u/* AppAccBytePosition */}, /*PassSeatHeatSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2681u/* AppAccBytePosition */}, /*DrvSeatVentnSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2682u/* AppAccBytePosition */}, /*PassSeatVentnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2683u/* AppAccBytePosition */}, /*SCM1_0x2D1*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2691u/* AppAccBytePosition */}, /*STBS_SoundReq*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2692u/* AppAccBytePosition */}, /*VolUpReq_SC*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2693u/* AppAccBytePosition */}, /*VolDwnReq_SC*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2694u/* AppAccBytePosition */}, /*DispTODReq_SC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2695u/* AppAccBytePosition */}, /*STBS1_0x21F*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2703u/* AppAccBytePosition */}, /*FLTirePressIndSts*/
  {3u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2704u/* AppAccBytePosition */}, /*FRTirePressIndSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2705u/* AppAccBytePosition */}, /*TirePressSysFailrIndcn*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2706u/* AppAccBytePosition */}, /*RLTirePressIndSts*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2707u/* AppAccBytePosition */}, /*RRTirePressIndSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2708u/* AppAccBytePosition */}, /*FLTireTempSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2709u/* AppAccBytePosition */}, /*FRTireTempSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2710u/* AppAccBytePosition */}, /*RLTireTempSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2711u/* AppAccBytePosition */}, /*RRTireTempSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2712u/* AppAccBytePosition */}, /*TPMS_AutoLoctSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2713u/* AppAccBytePosition */}, /*TPMS1_0x341*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2721u/* AppAccBytePosition */}, /*FLTirePress*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2722u/* AppAccBytePosition */}, /*FLTireTemp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2723u/* AppAccBytePosition */}, /*FRTirePress*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2724u/* AppAccBytePosition */}, /*FRTireTemp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2725u/* AppAccBytePosition */}, /*RLTirePress*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2726u/* AppAccBytePosition */}, /*RLTireTemp*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2727u/* AppAccBytePosition */}, /*RRTirePress*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2728u/* AppAccBytePosition */}, /*RRTireTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2729u/* AppAccBytePosition */}, /*TPMS2_0x395*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2737u/* AppAccBytePosition */}, /*T_BOX_RemtWinCtrl*/
  {2u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2738u/* AppAccBytePosition */}, /*T_BOX_RemtTrunkCtrl*/
  {3u/*BitLength*/, 5u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2739u/* AppAccBytePosition */}, /*T_BOX_RemtDoorLockCtrl*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2740u/* AppAccBytePosition */}, /*T_BOX_AudioMuteReq*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2741u/* AppAccBytePosition */}, /*T_BOX_RemtDrvTempSet*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2742u/* AppAccBytePosition */}, /*T_BOX_RemtAutoCtrl*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2743u/* AppAccBytePosition */}, /*T_BOX_RemtPassTempSet*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2744u/* AppAccBytePosition */}, /*T_BOX_RemtSsCtrl*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2745u/* AppAccBytePosition */}, /*T_BOX_RemtSrCtrl*/
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2746u/* AppAccBytePosition */}, /*T_BOX_RemtDrvSeatVentnLvlSet*/
  {3u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2747u/* AppAccBytePosition */}, /*T_BOX_RemtPassSeatVentnLvlSet*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2748u/* AppAccBytePosition */}, /*T_BOX_RemtAIUReq*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2749u/* AppAccBytePosition */}, /*T_BOX_PM25AirQLvl*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2750u/* AppAccBytePosition */}, /*T_BOX_RemtCarSearch*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2751u/* AppAccBytePosition */}, /*T_BOX_RemtEngCtrl*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2752u/* AppAccBytePosition */}, /*T_BOX_RemtDrvSeatHeatgLvlSet*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2753u/* AppAccBytePosition */}, /*T_BOX_RemtPassSeatHeatgLvlSet*/
  {10u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2754u/* AppAccBytePosition */}, /*T_BOX_PM25Dens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2756u/* AppAccBytePosition */}, /*T_BOX_FD1_0x33*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2764u/* AppAccBytePosition */}, /*T_BOX_SWUpdSts*/
  {5u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2765u/* AppAccBytePosition */}, /*T_BOX_SysErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2766u/* AppAccBytePosition */}, /*T_BOX_FD3_0x3E9*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2774u/* AppAccBytePosition */}, /*T_BOX_RemtFrntDefrostCtrl*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2775u/* AppAccBytePosition */}, /*T_BOX_RemtRearDefrostCtrl*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2776u/* AppAccBytePosition */}, /*T_BOX_RemtVideoMonrEnaReq_APP*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2777u/* AppAccBytePosition */}, /*T_BOX_RemtCockpitClnReq*/
  {2u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2778u/* AppAccBytePosition */}, /*RemUpgrdModeCmd*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 6u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 2779u/* AppAccBytePosition */}, /*T_BOX_FD4_0x1E1*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2795u/* AppAccBytePosition */}, /*V2X_FCW*/
  {4u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2796u/* AppAccBytePosition */}, /*V2X_BSW*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2797u/* AppAccBytePosition */}, /*V2X_LCW*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2798u/* AppAccBytePosition */}, /*V2X_EBW*/
  {4u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2799u/* AppAccBytePosition */}, /*V2X_ICW*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2800u/* AppAccBytePosition */}, /*V2X_LTA*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2801u/* AppAccBytePosition */}, /*V2X_IVSW*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2802u/* AppAccBytePosition */}, /*V2X_AVW*/
  {3u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2803u/* AppAccBytePosition */}, /*V2X_EVW*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2804u/* AppAccBytePosition */}, /*V2X_DNPW*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2805u/* AppAccBytePosition */}, /*V2X_HLW*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2806u/* AppAccBytePosition */}, /*V2X_TJW*/
  {6u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2807u/* AppAccBytePosition */}, /*V2X_CLW*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2808u/* AppAccBytePosition */}, /*V2X_RLVW*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2809u/* AppAccBytePosition */}, /*V2X_VRUCW*/
  {6u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2810u/* AppAccBytePosition */}, /*V2X_SLW*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2811u/* AppAccBytePosition */}, /*V2X_GLOSA*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2812u/* AppAccBytePosition */}, /*V2X_SL1_LightTyp*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2813u/* AppAccBytePosition */}, /*V2X_SL1_LightColor*/
  {16u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2814u/* AppAccBytePosition */}, /*V2X_SL1_LightTim*/
  {4u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2816u/* AppAccBytePosition */}, /*V2X_SL2_LightTyp*/
  {4u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2817u/* AppAccBytePosition */}, /*V2X_SL2_LightColor*/
  {16u/*BitLength*/, 144u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2818u/* AppAccBytePosition */}, /*V2X_SL2_LightTim*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2820u/* AppAccBytePosition */}, /*V2X_SL3_LightTyp*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2821u/* AppAccBytePosition */}, /*V2X_SL3_LightColor*/
  {16u/*BitLength*/, 168u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2822u/* AppAccBytePosition */}, /*V2X_SL3_LightTim*/
  {4u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2824u/* AppAccBytePosition */}, /*V2X_SL4_LightTyp*/
  {4u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2825u/* AppAccBytePosition */}, /*V2X_SL4_LightColor*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2826u/* AppAccBytePosition */}, /*V2X_SL5_LightTyp*/
  {16u/*BitLength*/, 208u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2827u/* AppAccBytePosition */}, /*V2X_SL4_LightTim*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2829u/* AppAccBytePosition */}, /*V2X_SL5_LightColor*/
  {16u/*BitLength*/, 232u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2830u/* AppAccBytePosition */}, /*V2X_SL5_LightTim*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2832u/* AppAccBytePosition */}, /*V2X_SL6_LightTyp*/
  {4u/*BitLength*/, 244u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2833u/* AppAccBytePosition */}, /*V2X_SL6_LightColor*/
  {16u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2834u/* AppAccBytePosition */}, /*V2X_SL6_LightTim*/
  {4u/*BitLength*/, 240u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2836u/* AppAccBytePosition */}, /*V2X_SL7_LightTyp*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2837u/* AppAccBytePosition */}, /*V2X_SL7_LightColor*/
  {16u/*BitLength*/, 288u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2838u/* AppAccBytePosition */}, /*V2X_SL7_LightTim*/
  {4u/*BitLength*/, 300u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2840u/* AppAccBytePosition */}, /*V2X_SL8_LightTyp*/
  {4u/*BitLength*/, 296u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2841u/* AppAccBytePosition */}, /*V2X_SL8_LightColor*/
  {16u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2842u/* AppAccBytePosition */}, /*V2X_SL8_LightTim*/
  {4u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2844u/* AppAccBytePosition */}, /*V2X_SL_of_Veh*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2845u/* AppAccBytePosition */}, /*T_BOX_FD10_0x2F0*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2909u/* AppAccBytePosition */}, /*WPC_ChrgSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2910u/* AppAccBytePosition */}, /*WPC_SwtSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2911u/* AppAccBytePosition */}, /*WPC_FaultSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2912u/* AppAccBytePosition */}, /*WPC_PhoneReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2913u/* AppAccBytePosition */}, /*WPC1_0x2BA*/
};


const ComEx_RxGroupInfoType ComEx_RxGroupInfo[ComEx_RxGroupSize] = 
{
  {0u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*ABM1*/
  {4u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* E2eIdx */}, /*ABS3*/
  {8u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 2u/* E2eIdx */}, /*ACC3_ACC_FD2*/
  {8u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 3u/* E2eIdx */}, /*ACC4_ACC_FD2*/
  {8u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 4u/* E2eIdx */}, /*ACC8_ACC_FD2*/
  {8u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 5u/* E2eIdx */}, /*ACC6_ACC_FD2*/
  {8u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 6u/* E2eIdx */}, /*ACC7_ACC_FD2*/
  {12u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 7u/* E2eIdx */}, /*AEB2_AEB_FD2*/
  {12u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 8u/* E2eIdx */}, /*AEB3_AEB_FD2*/
  {32u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* E2eIdx */}, /*DCT7*/
  {47u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 10u/* E2eIdx */}, /*EPB1*/
  {48u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 11u/* E2eIdx */}, /*EPS1*/
  {49u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 12u/* E2eIdx */}, /*ESP1*/
  {50u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 13u/* E2eIdx */}, /*ESP2*/
  {53u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 14u/* E2eIdx */}, /*GW_FD1*/
  {64u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 15u/* E2eIdx */}, /*IFC3_IFC_FD2*/
  {64u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 16u/* E2eIdx */}, /*IFC4_IFC_FD2*/
  {64u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 17u/* E2eIdx */}, /*IFC5_IFC_FD2*/
  {64u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 18u/* E2eIdx */}, /*IFC6_IFC_FD2*/
};


const ComEx_RxPduInfoType ComEx_RxPduInfo[ComEx_RxPduSize] = 
{
  {0u/* SignalStartIdx */, 15u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABM1*/
  {15u/* SignalStartIdx */, 22u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABM2*/
  {22u/* SignalStartIdx */, 33u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 16u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS1*/
  {33u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 24u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS2*/
  {44u/* SignalStartIdx */, 54u/* SignalEndIdx */, 1u/* GroupStartIdx */, 2u/* GroupEndIdx */, 32u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS3*/
  {54u/* SignalStartIdx */, 67u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 48u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC1*/
  {67u/* SignalStartIdx */, 81u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 56u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC2*/
  {81u/* SignalStartIdx */, 83u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 64u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC4*/
  {83u/* SignalStartIdx */, 168u/* SignalEndIdx */, 2u/* GroupStartIdx */, 7u/* GroupEndIdx */, 72u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ACC_FD2*/
  {168u/* SignalStartIdx */, 200u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 128u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD3*/
  {200u/* SignalStartIdx */, 269u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD4*/
  {269u/* SignalStartIdx */, 272u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AEB_FD1*/
  {272u/* SignalStartIdx */, 289u/* SignalEndIdx */, 7u/* GroupStartIdx */, 9u/* GroupEndIdx */, 320u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AEB_FD2*/
  {289u/* SignalStartIdx */, 291u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ALCM1*/
  {291u/* SignalStartIdx */, 297u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*APS1*/
  {297u/* SignalStartIdx */, 314u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*APS3*/
  {314u/* SignalStartIdx */, 316u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*APS4*/
  {316u/* SignalStartIdx */, 329u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM1*/
  {329u/* SignalStartIdx */, 341u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM3*/
  {341u/* SignalStartIdx */, 344u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM6*/
  {344u/* SignalStartIdx */, 352u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM8*/
  {352u/* SignalStartIdx */, 360u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM11*/
  {360u/* SignalStartIdx */, 368u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM12*/
  {368u/* SignalStartIdx */, 371u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM17*/
  {371u/* SignalStartIdx */, 374u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE1*/
  {374u/* SignalStartIdx */, 376u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 472u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE5*/
  {376u/* SignalStartIdx */, 384u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CR_FD1*/
  {384u/* SignalStartIdx */, 389u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 544u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA1*/
  {389u/* SignalStartIdx */, 393u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 552u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA2*/
  {393u/* SignalStartIdx */, 413u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 560u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA3*/
  {413u/* SignalStartIdx */, 417u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 568u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT3*/
  {417u/* SignalStartIdx */, 425u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 576u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT5*/
  {425u/* SignalStartIdx */, 440u/* SignalEndIdx */, 9u/* GroupStartIdx */, 10u/* GroupEndIdx */, 584u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*DCT7*/
  {440u/* SignalStartIdx */, 448u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM1*/
  {448u/* SignalStartIdx */, 450u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM3*/
  {450u/* SignalStartIdx */, 452u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 608u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSM1*/
  {452u/* SignalStartIdx */, 457u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 616u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM1*/
  {457u/* SignalStartIdx */, 466u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 624u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM2*/
  {466u/* SignalStartIdx */, 477u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 632u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM3*/
  {477u/* SignalStartIdx */, 481u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 640u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM4*/
  {481u/* SignalStartIdx */, 484u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 648u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM7*/
  {484u/* SignalStartIdx */, 486u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 656u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM8*/
  {486u/* SignalStartIdx */, 488u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 664u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM9*/
  {488u/* SignalStartIdx */, 490u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 672u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM11*/
  {490u/* SignalStartIdx */, 492u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 680u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM19*/
  {492u/* SignalStartIdx */, 495u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 688u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM20*/
  {495u/* SignalStartIdx */, 502u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EEM1*/
  {502u/* SignalStartIdx */, 512u/* SignalEndIdx */, 10u/* GroupStartIdx */, 11u/* GroupEndIdx */, 704u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPB1*/
  {512u/* SignalStartIdx */, 518u/* SignalEndIdx */, 11u/* GroupStartIdx */, 12u/* GroupEndIdx */, 712u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPS1*/
  {518u/* SignalStartIdx */, 527u/* SignalEndIdx */, 12u/* GroupStartIdx */, 13u/* GroupEndIdx */, 720u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP1*/
  {527u/* SignalStartIdx */, 540u/* SignalEndIdx */, 13u/* GroupStartIdx */, 14u/* GroupEndIdx */, 728u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP2*/
  {540u/* SignalStartIdx */, 558u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 744u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*FPAS1*/
  {558u/* SignalStartIdx */, 577u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 752u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*F_PBOX1*/
  {577u/* SignalStartIdx */, 588u/* SignalEndIdx */, 14u/* GroupStartIdx */, 15u/* GroupEndIdx */, 760u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_FD1*/
  {588u/* SignalStartIdx */, 591u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 824u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_OTA*/
  {591u/* SignalStartIdx */, 594u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 832u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 2/* CalloutStartIdx */}, /*GW_Sync_Req*/
  {594u/* SignalStartIdx */, 601u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 848u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP1*/
  {601u/* SignalStartIdx */, 604u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 856u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP2*/
  {604u/* SignalStartIdx */, 625u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 864u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD1*/
  {625u/* SignalStartIdx */, 650u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 928u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD2*/
  {650u/* SignalStartIdx */, 710u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 992u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD3*/
  {710u/* SignalStartIdx */, 740u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1056u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD6*/
  {740u/* SignalStartIdx */, 742u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1120u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD7*/
  {742u/* SignalStartIdx */, 750u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1184u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HUD1*/
  {750u/* SignalStartIdx */, 799u/* SignalEndIdx */, 15u/* GroupStartIdx */, 19u/* GroupEndIdx */, 1192u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*IFC_FD2*/
  {799u/* SignalStartIdx */, 820u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1248u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD3*/
  {820u/* SignalStartIdx */, 845u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1312u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD5*/
  {845u/* SignalStartIdx */, 864u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1376u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD6*/
  {864u/* SignalStartIdx */, 873u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1440u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PDCM1*/
  {873u/* SignalStartIdx */, 880u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS2*/
  {880u/* SignalStartIdx */, 887u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS4*/
  {887u/* SignalStartIdx */, 892u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1464u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PLG_1*/
  {892u/* SignalStartIdx */, 909u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1472u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RPAS1*/
  {909u/* SignalStartIdx */, 911u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1480u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RPAS2*/
  {911u/* SignalStartIdx */, 930u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1488u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD1*/
  {930u/* SignalStartIdx */, 953u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1552u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD2*/
  {953u/* SignalStartIdx */, 972u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1616u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*R_PBOX1*/
  {972u/* SignalStartIdx */, 977u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1624u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*SCM1*/
  {977u/* SignalStartIdx */, 982u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1632u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*STBS1*/
  {982u/* SignalStartIdx */, 993u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1640u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS1*/
  {993u/* SignalStartIdx */, 1002u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1648u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS2*/
  {1002u/* SignalStartIdx */, 1021u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1656u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD1*/
  {1021u/* SignalStartIdx */, 1024u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1664u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD3*/
  {1024u/* SignalStartIdx */, 1030u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1672u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD4*/
  {1030u/* SignalStartIdx */, 1073u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1688u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD10*/
  {1073u/* SignalStartIdx */, 1078u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1752u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*WPC1*/
};


const ComEx_RxSigInitValueInfoType ComEx_RxSigInitValueInfo[ComEx_RxInitValueSize] = 
{
  {1u/* byteLength */, 0u/* bytePosition */},
  {1u/* byteLength */, 1u/* bytePosition */},
  {8u/* byteLength */, 2u/* bytePosition */},
  {2u/* byteLength */, 10u/* bytePosition */},
  {2u/* byteLength */, 12u/* bytePosition */},
  {2u/* byteLength */, 14u/* bytePosition */},
  {16u/* byteLength */, 16u/* bytePosition */},
  {1u/* byteLength */, 32u/* bytePosition */},
  {1u/* byteLength */, 33u/* bytePosition */},
  {1u/* byteLength */, 34u/* bytePosition */},
  {1u/* byteLength */, 35u/* bytePosition */},
  {1u/* byteLength */, 36u/* bytePosition */},
  {1u/* byteLength */, 37u/* bytePosition */},
  {1u/* byteLength */, 38u/* bytePosition */},
  {2u/* byteLength */, 39u/* bytePosition */},
  {56u/* byteLength */, 41u/* bytePosition */},
  {64u/* byteLength */, 97u/* bytePosition */},
  {2u/* byteLength */, 161u/* bytePosition */},
  {1u/* byteLength */, 163u/* bytePosition */},
  {1u/* byteLength */, 164u/* bytePosition */},
  {1u/* byteLength */, 165u/* bytePosition */},
  {1u/* byteLength */, 166u/* bytePosition */},
  {1u/* byteLength */, 167u/* bytePosition */},
  {4u/* byteLength */, 168u/* bytePosition */},
  {2u/* byteLength */, 172u/* bytePosition */},
  {2u/* byteLength */, 174u/* bytePosition */},
  {11u/* byteLength */, 176u/* bytePosition */},
  {1u/* byteLength */, 187u/* bytePosition */},
  {1u/* byteLength */, 188u/* bytePosition */},
  {2u/* byteLength */, 189u/* bytePosition */},
  {2u/* byteLength */, 191u/* bytePosition */},
  {2u/* byteLength */, 193u/* bytePosition */},
  {2u/* byteLength */, 195u/* bytePosition */},
  {4u/* byteLength */, 197u/* bytePosition */},
  {2u/* byteLength */, 201u/* bytePosition */},
  {2u/* byteLength */, 203u/* bytePosition */},
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
  {E2EPW_ReadInit_ABS3_E2E/* InitFunPtr */, E2EPW_Read_ABS3_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC3_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC3_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC4_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC4_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC8_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC8_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC6_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC6_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ACC7_ACC_FD2_E2E/* InitFunPtr */, E2EPW_Read_ACC7_ACC_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_AEB2_AEB_FD2_E2E/* InitFunPtr */, E2EPW_Read_AEB2_AEB_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_AEB3_AEB_FD2_E2E/* InitFunPtr */, E2EPW_Read_AEB3_AEB_FD2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_DCT7_E2E/* InitFunPtr */, E2EPW_Read_DCT7_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPB1_E2E/* InitFunPtr */, E2EPW_Read_EPB1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPS1_E2E/* InitFunPtr */, E2EPW_Read_EPS1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP1_E2E/* InitFunPtr */, E2EPW_Read_ESP1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP2_E2E/* InitFunPtr */, E2EPW_Read_ESP2_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_GW_FD1_E2E/* InitFunPtr */, E2EPW_Read_GW_FD1_E2E/* ReadFunPtr */},
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xfeu,
  0x7u,
  0xfu,
  0x21u,
  0x3u,
  0xffu,
  0x1eu,
  0xffu,
  0x7fu,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x7fu,
  0x80u,
  0xeu,
  0x2u,
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
  0x4u,
  0xau,
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
  0xffu,
  0x3u,
};

const uint8 ComEx_RxTimeoutBuffer[ComEx_RxTimeoutBufferSize] = 
{
    0u
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
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExprsnSts*/
  {3u/*BitLength*/, 368u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvBehvSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 1u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 8u/* BufferStartIdx */, 72u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMS_FD1_0x24D*/
  {48u/*BitLength*/, 104u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 6u/* BusAccBtyeLength */, 80u/* BufferStartIdx */, 86u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSN*/
  {4u/*BitLength*/, 12u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSts*/
  {3u/*BitLength*/, 26u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 75u/* BufferStartIdx */, 76u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRRemtCnSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 72u/* BufferStartIdx */, 136u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_FD1_0x2EC*/
  {3u/*BitLength*/, 5u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DomeLmpDlyTimSet*/
  {3u/*BitLength*/, 1u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 137u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FolwMeHomeDlyTimSet*/
  {1u/*BitLength*/, 15u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*TranPMode_Req*/
  {1u/*BitLength*/, 14u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearviewFoldModSet*/
  {2u/*BitLength*/, 12u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 137u/* BufferStartIdx */, 138u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BattSaveDelayTimeSet*/
  {2u/*BitLength*/, 20u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_TC*/
  {2u/*BitLength*/, 18u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_TC*/
  {2u/*BitLength*/, 16u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 138u/* BufferStartIdx */, 139u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 139u/* BufferStartIdx */, 140u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_TC*/
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
  {1u/*BitLength*/, 48u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 142u/* BufferStartIdx */, 143u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOffReq_TC*/
  {4u/*BitLength*/, 56u/* BitPosition */, 3u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 143u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrsteplsSpdReq_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 3u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 136u/* BufferStartIdx */, 144u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT1_0x367*/
  {2u/*BitLength*/, 40u/* BitPosition */, 4u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 149u/* BufferStartIdx */, 150u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearWinHeatCmd_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 4u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 144u/* BufferStartIdx */, 152u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT2_0x369*/
  {2u/*BitLength*/, 14u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 153u/* BufferStartIdx */, 154u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgLvlSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 153u/* BufferStartIdx */, 154u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatHeatgLvlSet*/
  {2u/*BitLength*/, 8u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 153u/* BufferStartIdx */, 154u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 154u/* BufferStartIdx */, 155u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 155u/* BufferStartIdx */, 156u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACCmprReq_VR*/
  {2u/*BitLength*/, 36u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPowerReq_VR*/
  {4u/*BitLength*/, 32u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 156u/* BufferStartIdx */, 157u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrSpdReq_VR*/
  {6u/*BitLength*/, 42u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 157u/* BufferStartIdx */, 158u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempReq_VR*/
  {2u/*BitLength*/, 40u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 157u/* BufferStartIdx */, 158u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntDefrostReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 158u/* BufferStartIdx */, 159u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvAirDistribModReq_VR*/
  {2u/*BitLength*/, 51u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 158u/* BufferStartIdx */, 159u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_VR*/
  {2u/*BitLength*/, 62u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 159u/* BufferStartIdx */, 160u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACModReq_HUT*/
  {1u/*BitLength*/, 56u/* BitPosition */, 5u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 159u/* BufferStartIdx */, 160u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RemUpgrdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 5u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 152u/* BufferStartIdx */, 160u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT4_0x36D*/
  {2u/*BitLength*/, 5u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_TC*/
  {2u/*BitLength*/, 3u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AUTODefrost_VR*/
  {1u/*BitLength*/, 60u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FPAS_AutoModSwt*/
  {1u/*BitLength*/, 61u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MEBSwtSet*/
  {1u/*BitLength*/, 42u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LaneCalActvtCmd*/
  {1u/*BitLength*/, 62u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MODChgReq*/
  {1u/*BitLength*/, 40u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Radar_DispCmd*/
  {1u/*BitLength*/, 7u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Guid_Ovl_Display_Cmd*/
  {4u/*BitLength*/, 33u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Sgl_View_Sel*/
  {1u/*BitLength*/, 58u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SwToFieldCalRstCmd*/
  {1u/*BitLength*/, 55u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoViewChgCmd*/
  {1u/*BitLength*/, 53u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MdlColrChgCmd*/
  {1u/*BitLength*/, 49u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CarMdlTrsprcySwtCmd*/
  {1u/*BitLength*/, 63u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CarMdlDispCmd*/
  {1u/*BitLength*/, 57u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AutoAVMSwSet_Cmd*/
  {1u/*BitLength*/, 56u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WshSoftSwt*/
  {1u/*BitLength*/, 59u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*View_SoftswitchCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 6u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT6_0x4A*/
  {1u/*BitLength*/, 15u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 169u/* BufferStartIdx */, 170u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt_OLE*/
  {6u/*BitLength*/, 9u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 169u/* BufferStartIdx */, 170u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet_OLE*/
  {3u/*BitLength*/, 21u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 170u/* BufferStartIdx */, 171u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet_OLE*/
  {1u/*BitLength*/, 8u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 169u/* BufferStartIdx */, 170u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt_OLE*/
  {1u/*BitLength*/, 20u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 170u/* BufferStartIdx */, 171u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt_OLE*/
  {1u/*BitLength*/, 19u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 170u/* BufferStartIdx */, 171u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRdmSwt_OLE*/
  {7u/*BitLength*/, 25u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 171u/* BufferStartIdx */, 172u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*Rdm_SingleColorNr*/
  {2u/*BitLength*/, 51u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 174u/* BufferStartIdx */, 175u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SmtCsaSwt*/
  {2u/*BitLength*/, 49u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 174u/* BufferStartIdx */, 175u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*CarWashModeReq*/
  {2u/*BitLength*/, 62u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 175u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartModSet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 7u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 172u/* BufferStartIdx */, 173u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OTA_UpgrdModReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 7u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 168u/* BufferStartIdx */, 176u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT7_0x44*/
  {1u/*BitLength*/, 56u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 183u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvgModeMemReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT8_0x2C6*/
  {2u/*BitLength*/, 10u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_VR*/
  {2u/*BitLength*/, 8u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_VR*/
  {6u/*BitLength*/, 48u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassTempReq_VR*/
  {2u/*BitLength*/, 56u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_VR*/
  {1u/*BitLength*/, 47u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt*/
  {6u/*BitLength*/, 32u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 188u/* BufferStartIdx */, 189u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet*/
  {1u/*BitLength*/, 24u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt*/
  {2u/*BitLength*/, 54u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASSwtReq_VR*/
  {2u/*BitLength*/, 42u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BeanIDReq*/
  {2u/*BitLength*/, 40u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearDefrstReq_VR*/
  {64u/*BitLength*/, 0u/* BitPosition */, 9u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 184u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT10_0x331*/
  {2u/*BitLength*/, 14u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 193u/* BufferStartIdx */, 194u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AudioMuteSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 193u/* BufferStartIdx */, 194u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OrvmPosnEnaSts*/
  {1u/*BitLength*/, 53u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_AVHSwitchSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HDCSwitchCtrl*/
  {2u/*BitLength*/, 50u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 198u/* BufferStartIdx */, 199u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_EPB_SwtPosn*/
  {4u/*BitLength*/, 28u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 195u/* BufferStartIdx */, 196u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ORVMLensAdjmt_HUT*/
  {4u/*BitLength*/, 24u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 195u/* BufferStartIdx */, 196u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvSeatAdjmt_HUT*/
  {2u/*BitLength*/, 22u/* BitPosition */, 10u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 194u/* BufferStartIdx */, 195u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ORVMFoldSwt_HUT*/
  {64u/*BitLength*/, 0u/* BitPosition */, 10u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 192u/* BufferStartIdx */, 200u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT13_0x31C*/
  {2u/*BitLength*/, 6u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOperMod_VR*/
  {2u/*BitLength*/, 2u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 201u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SteerWheelHeatSwtReq*/
  {6u/*BitLength*/, 18u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 202u/* BufferStartIdx */, 203u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_TC*/
  {6u/*BitLength*/, 26u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 203u/* BufferStartIdx */, 204u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassSetTempSteplsReq_TC*/
  {2u/*BitLength*/, 52u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASExitSpdSwt*/
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
  {1u/*BitLength*/, 39u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SDWSwtSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSSwtReq_VR*/
  {2u/*BitLength*/, 33u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APSPrkgTypSeln*/
  {2u/*BitLength*/, 35u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 204u/* BufferStartIdx */, 205u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_APSPrkgModSeln*/
  {64u/*BitLength*/, 0u/* BitPosition */, 11u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 200u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT15_0x1EE*/
  {4u/*BitLength*/, 36u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 212u/* BufferStartIdx */, 213u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackgroundLightLvlSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 214u/* BufferStartIdx */, 215u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PLGReq_VR*/
  {2u/*BitLength*/, 22u/* BitPosition */, 12u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 210u/* BufferStartIdx */, 211u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WPC_SwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 12u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 208u/* BufferStartIdx */, 216u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT17_0x33B*/
  {3u/*BitLength*/, 5u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 217u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MsgTyp*/
  {3u/*BitLength*/, 2u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 217u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapProvider*/
  {10u/*BitLength*/, 8u/* BitPosition */, 13u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 218u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CountryCode*/
  {2u/*BitLength*/, 22u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_CycCnt*/
  {2u/*BitLength*/, 20u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Major*/
  {3u/*BitLength*/, 17u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 219u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_MinorSub*/
  {9u/*BitLength*/, 24u/* BitPosition */, 13u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 218u/* BufferStartIdx */, 220u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_HwVer*/
  {1u/*BitLength*/, 39u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 221u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_DrvSide*/
  {15u/*BitLength*/, 40u/* BitPosition */, 13u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 220u/* BufferStartIdx */, 222u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_RegionCode*/
  {2u/*BitLength*/, 54u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 222u/* BufferStartIdx */, 223u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerQtr*/
  {6u/*BitLength*/, 48u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 222u/* BufferStartIdx */, 223u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_MapVerYear*/
  {1u/*BitLength*/, 60u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 223u/* BufferStartIdx */, 224u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_SpdUnits*/
  {4u/*BitLength*/, 56u/* BitPosition */, 13u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 223u/* BufferStartIdx */, 224u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Meta_ProtVer_Minor*/
  {64u/*BitLength*/, 0u/* BitPosition */, 13u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 216u/* BufferStartIdx */, 224u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT19_0x415*/
  {3u/*BitLength*/, 5u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 225u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 14u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 226u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 226u/* BufferStartIdx */, 227u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 14u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 227u/* BufferStartIdx */, 228u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Update*/
  {32u/*BitLength*/, 56u/* BitPosition */, 14u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 4u/* BusAccBtyeLength */, 228u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfLong_Value*/
  {64u/*BitLength*/, 0u/* BitPosition */, 14u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 224u/* BufferStartIdx */, 232u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT20_0x2DE*/
  {3u/*BitLength*/, 5u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 233u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 234u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 234u/* BufferStartIdx */, 235u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_PathIdx*/
  {5u/*BitLength*/, 27u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_ProfTyp*/
  {1u/*BitLength*/, 26u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_CtrlPoint*/
  {1u/*BitLength*/, 25u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 235u/* BufferStartIdx */, 236u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Update*/
  {2u/*BitLength*/, 38u/* BitPosition */, 15u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 236u/* BufferStartIdx */, 237u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_AccurClass*/
  {10u/*BitLength*/, 44u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 236u/* BufferStartIdx */, 238u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Dist1*/
  {10u/*BitLength*/, 50u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 237u/* BufferStartIdx */, 239u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value0*/
  {10u/*BitLength*/, 56u/* BitPosition */, 15u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 238u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_ProfShort_Value1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 15u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 232u/* BufferStartIdx */, 240u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT21_0x2DD*/
  {3u/*BitLength*/, 5u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 241u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 16u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 242u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 242u/* BufferStartIdx */, 243u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PathIdx*/
  {2u/*BitLength*/, 30u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Tunnel*/
  {2u/*BitLength*/, 28u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Brdg*/
  {2u/*BitLength*/, 26u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_BuildUpArea*/
  {1u/*BitLength*/, 25u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 243u/* BufferStartIdx */, 244u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 244u/* BufferStartIdx */, 245u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 244u/* BufferStartIdx */, 245u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 245u/* BufferStartIdx */, 246u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 245u/* BufferStartIdx */, 246u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 245u/* BufferStartIdx */, 246u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_FormOfWay*/
  {5u/*BitLength*/, 51u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 246u/* BufferStartIdx */, 247u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmt*/
  {3u/*BitLength*/, 48u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 246u/* BufferStartIdx */, 247u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_EffSpdLmtTyp*/
  {2u/*BitLength*/, 61u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 247u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_DivideRoad*/
  {2u/*BitLength*/, 59u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 247u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 16u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 247u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Seg_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 16u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 240u/* BufferStartIdx */, 248u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT22_0x2DA*/
  {3u/*BitLength*/, 5u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 249u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_MsgTyp*/
  {13u/*BitLength*/, 8u/* BitPosition */, 17u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 250u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Offset*/
  {2u/*BitLength*/, 22u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CycCnt*/
  {6u/*BitLength*/, 16u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 250u/* BufferStartIdx */, 251u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PathIdx*/
  {6u/*BitLength*/, 26u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_StubPathIdx*/
  {1u/*BitLength*/, 25u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Retr*/
  {1u/*BitLength*/, 24u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 251u/* BufferStartIdx */, 252u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_Update*/
  {5u/*BitLength*/, 35u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 253u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RelProbb*/
  {3u/*BitLength*/, 32u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 252u/* BufferStartIdx */, 253u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FuncRoadClass*/
  {2u/*BitLength*/, 46u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_PartOfCalcRoute*/
  {2u/*BitLength*/, 44u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_CmplxInsct*/
  {4u/*BitLength*/, 40u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 253u/* BufferStartIdx */, 254u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_FormOfWay*/
  {8u/*BitLength*/, 48u/* BitPosition */, 17u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 254u/* BufferStartIdx */, 255u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_TurnAngl*/
  {1u/*BitLength*/, 63u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_LastStub*/
  {2u/*BitLength*/, 61u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_RtOfWay*/
  {2u/*BitLength*/, 59u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneOppDir*/
  {3u/*BitLength*/, 56u/* BitPosition */, 17u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 255u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADAS_Stub_NumOfLaneDrvDir*/
  {64u/*BitLength*/, 0u/* BitPosition */, 17u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 248u/* BufferStartIdx */, 256u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT23_0x2D8*/
  {2u/*BitLength*/, 26u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 259u/* BufferStartIdx */, 260u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_RemtEngCtrl*/
  {5u/*BitLength*/, 55u/* BitPosition */, 18u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 261u/* BufferStartIdx */, 263u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempReq_ETC_VR*/
  {5u/*BitLength*/, 50u/* BitPosition */, 18u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 262u/* BufferStartIdx */, 263u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvSetTempSteplsReq_ETC_TC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 18u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 256u/* BufferStartIdx */, 264u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT25_0x339*/
  {3u/*BitLength*/, 33u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 268u/* BufferStartIdx */, 269u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatSupportPosnSwt*/
  {2u/*BitLength*/, 40u/* BitPosition */, 19u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 269u/* BufferStartIdx */, 270u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FrntOccptSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 19u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 264u/* BufferStartIdx */, 272u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT26_0x2B6*/
  {1u/*BitLength*/, 13u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 273u/* BufferStartIdx */, 274u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_AVM*/
  {5u/*BitLength*/, 8u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 273u/* BufferStartIdx */, 274u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_HeightLvlSwt*/
  {4u/*BitLength*/, 28u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_BrightnessLvlSwt*/
  {2u/*BitLength*/, 24u/* BitPosition */, 20u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 275u/* BufferStartIdx */, 276u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_SwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 20u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 272u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT30_0x1E9*/
  {4u/*BitLength*/, 40u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 285u/* BufferStartIdx */, 286u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*VolLampDispSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 281u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_HUT32*/
  {1u/*BitLength*/, 10u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkgCtrlModReqValid*/
  {2u/*BitLength*/, 12u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkgCtrlModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ContnPrkgReqValid*/
  {2u/*BitLength*/, 14u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ContnPrkgReq*/
  {1u/*BitLength*/, 55u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightContinueReq_HUT*/
  {4u/*BitLength*/, 56u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 287u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_HUT32*/
  {2u/*BitLength*/, 46u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 285u/* BufferStartIdx */, 286u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ScrnOpSts*/
  {11u/*BitLength*/, 29u/* BitPosition */, 21u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 282u/* BufferStartIdx */, 284u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*XLvl*/
  {11u/*BitLength*/, 32u/* BitPosition */, 21u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 283u/* BufferStartIdx */, 285u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*YLvl*/
  {1u/*BitLength*/, 9u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DetVideoLost*/
  {1u/*BitLength*/, 11u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 281u/* BufferStartIdx */, 282u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSwtReq_HUT*/
  {2u/*BitLength*/, 27u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 283u/* BufferStartIdx */, 284u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSuspendOrFinishReq_HUT*/
  {3u/*BitLength*/, 61u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 287u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightModSel_HUT*/
  {1u/*BitLength*/, 60u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 287u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSts_HUT*/
  {1u/*BitLength*/, 45u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 285u/* BufferStartIdx */, 286u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightStrtReq_HUT*/
  {1u/*BitLength*/, 44u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 285u/* BufferStartIdx */, 286u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightVehStrtReq_HUT_Valid*/
  {1u/*BitLength*/, 51u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RainMode_Swt_Req*/
  {2u/*BitLength*/, 49u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCMode_Swt_Req*/
  {64u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT32_0x26F*/
  {2u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MbrMonrEnReq_TC*/
  {3u/*BitLength*/, 8u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt*/
  {2u/*BitLength*/, 6u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApproachLampSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FlaoutUnlockSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 289u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SuperLockSet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 292u/* BufferStartIdx */, 293u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLWinSwtReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 294u/* BufferStartIdx */, 295u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRWinSwtReq_VR*/
  {3u/*BitLength*/, 13u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvWinSwtReq_VR*/
  {3u/*BitLength*/, 35u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 292u/* BufferStartIdx */, 293u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassWinSwtReq_VR*/
  {3u/*BitLength*/, 50u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 294u/* BufferStartIdx */, 295u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 289u/* BufferStartIdx */, 290u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkInDirChoice*/
  {3u/*BitLength*/, 21u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 290u/* BufferStartIdx */, 291u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkOutDirReq*/
  {1u/*BitLength*/, 19u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 290u/* BufferStartIdx */, 291u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkMdlCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 290u/* BufferStartIdx */, 291u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_APS*/
  {3u/*BitLength*/, 29u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 291u/* BufferStartIdx */, 292u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkgFctnCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT33_0x1ED*/
  {1u/*BitLength*/, 16u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 298u/* BufferStartIdx */, 299u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeMod*/
  {1u/*BitLength*/, 17u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 298u/* BufferStartIdx */, 299u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeIndcn*/
  {5u/*BitLength*/, 11u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Hour*/
  {6u/*BitLength*/, 18u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 298u/* BufferStartIdx */, 299u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Minutes*/
  {6u/*BitLength*/, 26u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 299u/* BufferStartIdx */, 300u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Second*/
  {4u/*BitLength*/, 36u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 300u/* BufferStartIdx */, 301u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Left*/
  {4u/*BitLength*/, 32u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 300u/* BufferStartIdx */, 301u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Right*/
  {4u/*BitLength*/, 44u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 301u/* BufferStartIdx */, 302u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Month*/
  {5u/*BitLength*/, 51u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 302u/* BufferStartIdx */, 303u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Day*/
  {64u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT34_0x370*/
  {2u/*BitLength*/, 25u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 307u/* BufferStartIdx */, 308u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_VR*/
  {2u/*BitLength*/, 17u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 306u/* BufferStartIdx */, 307u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_TC*/
  {1u/*BitLength*/, 49u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 310u/* BufferStartIdx */, 311u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockWinSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 24u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 305u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ColorCategory*/
  {64u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT35_0x1E5*/
  {7u/*BitLength*/, 1u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 313u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr1*/
  {7u/*BitLength*/, 9u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr2*/
  {7u/*BitLength*/, 17u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 315u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr3*/
  {7u/*BitLength*/, 25u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr4*/
  {7u/*BitLength*/, 33u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 316u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr5*/
  {7u/*BitLength*/, 41u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr6*/
  {7u/*BitLength*/, 49u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr7*/
  {7u/*BitLength*/, 57u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr8*/
  {64u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT36_0x1E6*/
  {7u/*BitLength*/, 1u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 321u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr9*/
  {7u/*BitLength*/, 9u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr10*/
  {7u/*BitLength*/, 17u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr11*/
  {7u/*BitLength*/, 25u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr12*/
  {7u/*BitLength*/, 33u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 324u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr13*/
  {7u/*BitLength*/, 41u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr14*/
  {7u/*BitLength*/, 49u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr15*/
  {7u/*BitLength*/, 57u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr16*/
  {64u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT37_0x1EC*/
  {3u/*BitLength*/, 45u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMFlashFreq*/
  {3u/*BitLength*/, 42u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMFlashFreq*/
  {3u/*BitLength*/, 55u/* BitPosition */, 27u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 52u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 49u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMFlashFreq*/
  {3u/*BitLength*/, 61u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMFlashFreq*/
  {3u/*BitLength*/, 58u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 335u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMFlashFreq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 27u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT38_0x1E7*/
  {3u/*BitLength*/, 21u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgLvlSet*/
  {3u/*BitLength*/, 47u/* BitPosition */, 28u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgModSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockPromptFunSet*/
  {1u/*BitLength*/, 6u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryUnlockSet*/
  {1u/*BitLength*/, 7u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryLockSet*/
  {1u/*BitLength*/, 3u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPAEntryLockSet*/
  {1u/*BitLength*/, 2u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPALvngUnlockSet*/
  {2u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ClsWinSpdSet*/
  {7u/*BitLength*/, 40u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMClrSet*/
  {7u/*BitLength*/, 49u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 342u/* BufferStartIdx */, 343u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMClrSet*/
  {7u/*BitLength*/, 57u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 343u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMClrSet*/
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
  {7u/*BitLength*/, 1u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 353u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMClrSet*/
  {7u/*BitLength*/, 9u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMClrSet*/
  {7u/*BitLength*/, 17u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 354u/* BufferStartIdx */, 355u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMClrSet*/
  {7u/*BitLength*/, 25u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 355u/* BufferStartIdx */, 356u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMClrSet*/
  {4u/*BitLength*/, 36u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 32u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 44u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 40u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 52u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMLightLvlSet*/
  {4u/*BitLength*/, 48u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMLightLvlSet*/
  {4u/*BitLength*/, 60u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 359u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMLightLvlSet*/
  {1u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 353u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMFloSwt*/
  {1u/*BitLength*/, 8u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT41_0x1FB*/
  {2u/*BitLength*/, 56u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 367u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SmtSeatSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT43_0x1FD*/
  {3u/*BitLength*/, 13u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RLSSensitivityReq_HUT*/
  {1u/*BitLength*/, 12u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PosnLmpSwtSts_HUT*/
  {1u/*BitLength*/, 11u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FrntFogLmpSwtSts_HUT*/
  {1u/*BitLength*/, 10u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RearFogLmpSwtSts_HUT*/
  {1u/*BitLength*/, 9u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LowBeamSwtSts_HUT*/
  {1u/*BitLength*/, 8u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AutoHiLowBeamSwtSts_HUT*/
  {1u/*BitLength*/, 23u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AutoLmpSwtSts_HUT*/
  {64u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT44_0x127*/
  {3u/*BitLength*/, 4u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 377u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PLG_HeightSet*/
  {6u/*BitLength*/, 26u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 379u/* BufferStartIdx */, 380u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*InCarTempMinSet*/
  {6u/*BitLength*/, 34u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 380u/* BufferStartIdx */, 381u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*InCarTempMaxSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 379u/* BufferStartIdx */, 380u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SmtACSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT45_0x1DC*/
  {3u/*BitLength*/, 41u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 389u/* BufferStartIdx */, 390u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*APAPrkgTypSeln*/
  {64u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT48_0x1F4*/
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
  {2u/*BitLength*/, 78u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 402u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*BrkPedalFeelReq*/
  {1u/*BitLength*/, 87u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HFASwtSts*/
  {2u/*BitLength*/, 113u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EPSSteerModSwtReq*/
  {1u/*BitLength*/, 112u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 406u/* BufferStartIdx */, 407u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DSTSwtReq*/
  {1u/*BitLength*/, 98u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_ESPFuncOffSwtSts*/
  {4u/*BitLength*/, 108u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrivingModReq_HUT*/
  {1u/*BitLength*/, 106u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSSwtReq*/
  {2u/*BitLength*/, 99u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSWarnFormSwtReq*/
  {1u/*BitLength*/, 107u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 405u/* BufferStartIdx */, 406u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntelligentEvaSwtReq*/
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
  {2u/*BitLength*/, 243u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 422u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSet*/
  {1u/*BitLength*/, 242u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 422u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CCOSwtReq_HUT*/
  {4u/*BitLength*/, 252u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 423u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ChairMemPosnSetResult*/
  {1u/*BitLength*/, 224u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 420u/* BufferStartIdx */, 421u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TABSwtReq_HUT*/
  {10u/*BitLength*/, 246u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 421u/* BufferStartIdx */, 423u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavVehToTrafEyeDist*/
  {4u/*BitLength*/, 308u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 430u/* BufferStartIdx */, 431u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavRoadType*/
  {2u/*BitLength*/, 306u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 430u/* BufferStartIdx */, 431u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimType*/
  {6u/*BitLength*/, 266u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimValue*/
  {2u/*BitLength*/, 264u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 425u/* BufferStartIdx */, 426u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimUnit_HUT*/
  {10u/*BitLength*/, 286u/* BitPosition */, 35u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 426u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavCtryType*/
  {1u/*BitLength*/, 280u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SwtReq*/
  {2u/*BitLength*/, 302u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SnvtySet*/
  {1u/*BitLength*/, 296u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALC_SwtReq*/
  {3u/*BitLength*/, 283u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 427u/* BufferStartIdx */, 428u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimSignSts*/
  {8u/*BitLength*/, 288u/* BitPosition */, 35u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 428u/* BufferStartIdx */, 429u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavTSRTrafSign*/
  {1u/*BitLength*/, 301u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTASwtReq*/
  {1u/*BitLength*/, 300u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTABrkSwtReq*/
  {1u/*BitLength*/, 299u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_JASwtReq*/
  {1u/*BitLength*/, 298u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 429u/* BufferStartIdx */, 430u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AESSwtReq*/
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
  {1u/*BitLength*/, 96u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 404u/* BufferStartIdx */, 405u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_APSPrkgModDftSet*/
  {2u/*BitLength*/, 128u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 409u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_TGSSwtReq*/
  {448u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 56u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD1_0x2C3*/
  {2u/*BitLength*/, 22u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Learning_Set_ParkLot*/
  {1u/*BitLength*/, 21u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_Set_Path_Ending*/
  {2u/*BitLength*/, 19u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HAVP_LearningTypeSele*/
  {4u/*BitLength*/, 32u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 453u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SlotNum_VR*/
  {1u/*BitLength*/, 44u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 454u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefinedParkCmd*/
  {3u/*BitLength*/, 16u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 450u/* BufferStartIdx */, 451u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefPrkMenuSelCmd*/
  {512u/*BitLength*/, 0u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 448u/* BufferStartIdx */, 512u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD4_0x1DA*/
  {8u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 512u/* BufferStartIdx */, 513u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequestMessageId*/
  {56u/*BitLength*/, 56u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 7u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 520u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequstReseverData*/
  {3u/*BitLength*/, 18u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_CurrTheme*/
  {9u/*BitLength*/, 23u/* BitPosition */, 38u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdDisp*/
  {10u/*BitLength*/, 24u/* BitPosition */, 38u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelMainTankR*/
  {10u/*BitLength*/, 46u/* BitPosition */, 38u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 534u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxTankR*/
  {8u/*BitLength*/, 60u/* BitPosition */, 38u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 534u/* BufferStartIdx */, 536u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VelSpdDisp_Mile*/
  {4u/*BitLength*/, 42u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 533u/* BufferStartIdx */, 534u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_LagueSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 528u/* BufferStartIdx */, 536u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP1_0x293*/
  {8u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 536u/* BufferStartIdx */, 537u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_IP2*/
  {2u/*BitLength*/, 50u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 542u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_DrvSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 542u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_PassSeatBeltWarnLmpFailSts*/
  {24u/*BitLength*/, 24u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 537u/* BufferStartIdx */, 540u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistance*/
  {8u/*BitLength*/, 32u/* BitPosition */, 39u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 540u/* BufferStartIdx */, 541u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlInfo*/
  {2u/*BitLength*/, 44u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlLowLmpSts*/
  {2u/*BitLength*/, 42u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_BattChrgLmpSts*/
  {2u/*BitLength*/, 40u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EngOilPressLowLmpSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 542u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ABMWarnLmpFailrSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 542u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_Err*/
  {1u/*BitLength*/, 47u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ACCErr*/
  {1u/*BitLength*/, 46u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 541u/* BufferStartIdx */, 542u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceValid*/
  {1u/*BitLength*/, 53u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 542u/* BufferStartIdx */, 543u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdUnit*/
  {1u/*BitLength*/, 63u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 543u/* BufferStartIdx */, 544u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VINcompr*/
  {4u/*BitLength*/, 56u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 543u/* BufferStartIdx */, 544u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_IP2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 536u/* BufferStartIdx */, 544u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP2_0x27F*/
  {12u/*BitLength*/, 20u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 545u/* BufferStartIdx */, 547u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_RemainDistance*/
  {1u/*BitLength*/, 19u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 546u/* BufferStartIdx */, 547u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelConsUnit*/
  {1u/*BitLength*/, 18u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 546u/* BufferStartIdx */, 547u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EBDFailSts*/
  {12u/*BitLength*/, 36u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 547u/* BufferStartIdx */, 549u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AvgFuelCons*/
  {14u/*BitLength*/, 54u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 548u/* BufferStartIdx */, 551u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelCons*/
  {1u/*BitLength*/, 16u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 546u/* BufferStartIdx */, 547u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceUnit*/
  {128u/*BitLength*/, 0u/* BitPosition */, 40u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 16u/* BusAccBtyeLength */, 544u/* BufferStartIdx */, 560u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP3_0x34A*/
  {2u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 560u/* BufferStartIdx */, 561u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*T_BOX_RemtLimitStart*/
  {2u/*BitLength*/, 14u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 561u/* BufferStartIdx */, 562u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*T_BOX_RemtSteerWheelHeatCtrl*/
  {128u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 16u/* BusAccBtyeLength */, 560u/* BufferStartIdx */, 576u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*T_BOX_FD6_0x33D*/
};

const ComEx_TxPduInfoType ComEx_TxPduInfo[ComEx_TxPduSize] = 
{
  {65535u/* SignalStartIdx */, 65535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 0/* CalloutStartIdx */, 1u/* CalloutNum */}, /*ComIPdu_userData*/
  {0u/* SignalStartIdx */, 27u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DMS_FD1*/
  {27u/* SignalStartIdx */, 31u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DVR_FD1*/
  {31u/* SignalStartIdx */, 55u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT1*/
  {55u/* SignalStartIdx */, 57u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT2*/
  {57u/* SignalStartIdx */, 72u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 152u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT4*/
  {72u/* SignalStartIdx */, 90u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 160u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT6*/
  {90u/* SignalStartIdx */, 102u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 168u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT7*/
  {102u/* SignalStartIdx */, 104u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT8*/
  {104u/* SignalStartIdx */, 115u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 184u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT10*/
  {115u/* SignalStartIdx */, 124u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT13*/
  {124u/* SignalStartIdx */, 146u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT15*/
  {146u/* SignalStartIdx */, 150u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT17*/
  {150u/* SignalStartIdx */, 164u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 216u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT19*/
  {164u/* SignalStartIdx */, 174u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 224u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT20*/
  {174u/* SignalStartIdx */, 187u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 232u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT21*/
  {187u/* SignalStartIdx */, 207u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT22*/
  {207u/* SignalStartIdx */, 225u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 248u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT23*/
  {225u/* SignalStartIdx */, 229u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT25*/
  {229u/* SignalStartIdx */, 232u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT26*/
  {232u/* SignalStartIdx */, 237u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT30*/
  {237u/* SignalStartIdx */, 258u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 280u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT32*/
  {258u/* SignalStartIdx */, 274u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 288u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT33*/
  {274u/* SignalStartIdx */, 284u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 296u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT34*/
  {284u/* SignalStartIdx */, 289u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 304u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT35*/
  {289u/* SignalStartIdx */, 298u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 312u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT36*/
  {298u/* SignalStartIdx */, 307u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 320u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT37*/
  {307u/* SignalStartIdx */, 315u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 328u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT38*/
  {315u/* SignalStartIdx */, 327u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 336u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT39*/
  {327u/* SignalStartIdx */, 337u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 344u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT40*/
  {337u/* SignalStartIdx */, 351u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 352u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT41*/
  {351u/* SignalStartIdx */, 353u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT43*/
  {353u/* SignalStartIdx */, 361u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT44*/
  {361u/* SignalStartIdx */, 366u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT45*/
  {366u/* SignalStartIdx */, 368u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT48*/
  {368u/* SignalStartIdx */, 444u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 56u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD1*/
  {444u/* SignalStartIdx */, 451u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD4*/
  {451u/* SignalStartIdx */, 453u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 512u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_Sync_Req*/
  {453u/* SignalStartIdx */, 460u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 528u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP1*/
  {460u/* SignalStartIdx */, 476u/* SignalEndIdx */, 1u/* GroupStartIdx */, 2u/* GroupEndIdx */, 536u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP2*/
  {476u/* SignalStartIdx */, 483u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 544u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP3*/
  {483u/* SignalStartIdx */, 486u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 560u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*T_BOX_FD6*/
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  0x40u,
  0x0u,
  0xA0u,
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
  0x0u,
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
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0xf4u,
  0xf4u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
  0x0u,
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
  {21u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*HUT32*/
  {39u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* E2eIdx */}, /*IP2*/
};

const ComEx_TxE2eInfoType ComEx_TxE2eInfo[ComEx_TxE2eSize] =
{
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
