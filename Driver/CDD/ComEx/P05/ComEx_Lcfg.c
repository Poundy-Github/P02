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
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 67u/* AppAccBytePosition */}, /*WssRREdgesSum*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 68u/* AppAccBytePosition */}, /*WssRLEdgesSum*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 69u/* AppAccBytePosition */}, /*WssRLEdgesSumVld*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 70u/* AppAccBytePosition */}, /*WssRREdgesSumVld*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 3u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 71u/* AppAccBytePosition */}, /*ABS2_0x246*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 79u/* AppAccBytePosition */}, /*CheckSum_ABS3_0x265*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 80u/* AppAccBytePosition */}, /*ABSActv_0x265*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 81u/* AppAccBytePosition */}, /*ABSFailSts_0x265*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 82u/* AppAccBytePosition */}, /*EBDFailSts_0x265*/
  {10u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 83u/* AppAccBytePosition */}, /*VehOdoInfo_0x265*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 85u/* AppAccBytePosition */}, /*VehOdoInfoSts_0x265*/
  {13u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 86u/* AppAccBytePosition */}, /*VehSpd_0x265*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 88u/* AppAccBytePosition */}, /*VehSpdVld_0x265*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 89u/* AppAccBytePosition */}, /*RollingCounter_ABS3_0x265*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 4u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 90u/* AppAccBytePosition */}, /*ABS3_0x265*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 98u/* AppAccBytePosition */}, /*InCarTemp*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 99u/* AppAccBytePosition */}, /*ACAQSEnaSts*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 100u/* AppAccBytePosition */}, /*ACOperMod*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 101u/* AppAccBytePosition */}, /*ACAIUEnaSts*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 102u/* AppAccBytePosition */}, /*ACDrvAirDistriMod*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 103u/* AppAccBytePosition */}, /*ACSteplessSpdSetEnaSts*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 104u/* AppAccBytePosition */}, /*ACFrntPassTempSteplessSetEnaSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 105u/* AppAccBytePosition */}, /*ACDrvTempSteplessSetEnaSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 106u/* AppAccBytePosition */}, /*ACEEMSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 107u/* AppAccBytePosition */}, /*ACDrvTemp_ETC*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 5u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 108u/* AppAccBytePosition */}, /*AC1_0x29D*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 116u/* AppAccBytePosition */}, /*ACRearWinHeatSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 117u/* AppAccBytePosition */}, /*ACHMIDispCmd*/
  {4u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 118u/* AppAccBytePosition */}, /*ACFrntBlwrSpd*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 119u/* AppAccBytePosition */}, /*ACOpenSts*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 120u/* AppAccBytePosition */}, /*ACDualModEnaSts*/
  {6u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 121u/* AppAccBytePosition */}, /*ACDrvTemp_ATC*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 122u/* AppAccBytePosition */}, /*ACAmbTemp*/
  {2u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 123u/* AppAccBytePosition */}, /*ACAirInletSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 124u/* AppAccBytePosition */}, /*ACFrntDefrstSts*/
  {6u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 9u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 125u/* AppAccBytePosition */}, /*ACFrntPasstTemp_ATC*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 126u/* AppAccBytePosition */}, /*ACAutoModEnaSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 127u/* AppAccBytePosition */}, /*ACCmprEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 6u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 128u/* AppAccBytePosition */}, /*AC2_0x385*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 136u/* AppAccBytePosition */}, /*ACMaxEnaSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 137u/* AppAccBytePosition */}, /*ACZoneModEnaSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 7u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 138u/* AppAccBytePosition */}, /*AC4_0x2CC*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 146u/* AppAccBytePosition */}, /*L_PM25InAirQltyLvl*/
  {10u/*BitLength*/, 27u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 147u/* AppAccBytePosition */}, /*L_PM25InDens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 8u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 149u/* AppAccBytePosition */}, /*AC6_0x2F8*/
  {7u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 157u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dy*/
  {9u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 158u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Dx*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 160u/* AppAccBytePosition */}, /*ACC_LeTgt_02_Typ*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 161u/* AppAccBytePosition */}, /*ACC_LeTargrt_02_Detn*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 162u/* AppAccBytePosition */}, /*ACC_RiTargrt_02_Detn*/
  {7u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 163u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dy*/
  {9u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 164u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Dx*/
  {3u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 166u/* AppAccBytePosition */}, /*ACC_RiTgt_02_Typ*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 167u/* AppAccBytePosition */}, /*ACC_LeTgtObjBarDisp*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 168u/* AppAccBytePosition */}, /*ACC_RiTgtObjBarDisp*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 169u/* AppAccBytePosition */}, /*Checksum_ACC3*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 170u/* AppAccBytePosition */}, /*ICA_HandsOffResp*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 171u/* AppAccBytePosition */}, /*ALC_Resp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 172u/* AppAccBytePosition */}, /*HWA_Resp*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 173u/* AppAccBytePosition */}, /*ISL_Resp*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 174u/* AppAccBytePosition */}, /*HWA_SnvtySet_Resp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 175u/* AppAccBytePosition */}, /*Longctrl_VehHldReq_DVR*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 176u/* AppAccBytePosition */}, /*Longctrl_DrvOFF_Req_DVR*/
  {4u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 177u/* AppAccBytePosition */}, /*Longctrl_ModSts_DVR*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 178u/* AppAccBytePosition */}, /*Longctrl_Decel_Req_DVR*/
  {16u/*BitLength*/, 96u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 179u/* AppAccBytePosition */}, /*Longctrl_EngTrqReq_DVR*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 181u/* AppAccBytePosition */}, /*Longctrl_EngTrqReqActive_DVR*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 182u/* AppAccBytePosition */}, /*Longctrl_DecelToStopReq_DVR*/
  {2u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 183u/* AppAccBytePosition */}, /*Longctrl_ParkShiftReq_DVR*/
  {8u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 184u/* AppAccBytePosition */}, /*Longctrl_Decel_ReqValue_DVR*/
  {2u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 185u/* AppAccBytePosition */}, /*ALC_InterSysInfoDisp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 186u/* AppAccBytePosition */}, /*RollingCounter_ACC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 187u/* AppAccBytePosition */}, /*Checksum_ACC4*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 188u/* AppAccBytePosition */}, /*ACC_ObjDetecte*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 189u/* AppAccBytePosition */}, /*ACC_TakeOverReq*/
  {5u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 190u/* AppAccBytePosition */}, /*ACC_InterSysInfoDisp*/
  {5u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 191u/* AppAccBytePosition */}, /*ACC_ModDisp*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 192u/* AppAccBytePosition */}, /*ACC_FctSts*/
  {3u/*BitLength*/, 157u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 193u/* AppAccBytePosition */}, /*ACC_TgtObjBarDisp*/
  {2u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 194u/* AppAccBytePosition */}, /*Longctrl_HazActv*/
  {3u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 195u/* AppAccBytePosition */}, /*TJA_ACC_SelSts*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 196u/* AppAccBytePosition */}, /*CruCha_ModDisp*/
  {3u/*BitLength*/, 161u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 197u/* AppAccBytePosition */}, /*TJA_ICA_InterSysInfoDisp*/
  {3u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 198u/* AppAccBytePosition */}, /*TJA_ICA_ModDisp*/
  {2u/*BitLength*/, 171u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 199u/* AppAccBytePosition */}, /*ISL_InterSysInfoDisp*/
  {3u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 200u/* AppAccBytePosition */}, /*ACC_TimeGapSet*/
  {8u/*BitLength*/, 176u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 201u/* AppAccBytePosition */}, /*ACC_SpdSetValue*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 202u/* AppAccBytePosition */}, /*CruChar_InterSysInfoDisp*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 203u/* AppAccBytePosition */}, /*RollingCounter_ACC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 204u/* AppAccBytePosition */}, /*Checksum_ACC8*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 205u/* AppAccBytePosition */}, /*HWA_ModDisp*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 206u/* AppAccBytePosition */}, /*HWA_InterSysInfoDisp*/
  {2u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 207u/* AppAccBytePosition */}, /*HWA_LaneChange*/
  {3u/*BitLength*/, 221u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 208u/* AppAccBytePosition */}, /*HWA_LaneChangeReq*/
  {2u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 209u/* AppAccBytePosition */}, /*HWA_Warning*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 210u/* AppAccBytePosition */}, /*RollingCounter_ACC8*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 211u/* AppAccBytePosition */}, /*Checksum_ACC6*/
  {8u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 212u/* AppAccBytePosition */}, /*ACC_PotentialTgtDy*/
  {9u/*BitLength*/, 287u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 213u/* AppAccBytePosition */}, /*ACC_PotentialTgtDx*/
  {2u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 215u/* AppAccBytePosition */}, /*ACC_RlvTgtDetn*/
  {2u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 216u/* AppAccBytePosition */}, /*ACC_EgoStatus*/
  {3u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 217u/* AppAccBytePosition */}, /*ACC_RlvTgtTyp*/
  {8u/*BitLength*/, 288u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 218u/* AppAccBytePosition */}, /*ACC_RlvTgtDy*/
  {9u/*BitLength*/, 311u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 219u/* AppAccBytePosition */}, /*ACC_RlvTgtDx*/
  {2u/*BitLength*/, 308u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 221u/* AppAccBytePosition */}, /*ACC_PotentialTgtDetn*/
  {3u/*BitLength*/, 305u/* BitPosition */, 1u/* ByteLength */, 38u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 222u/* AppAccBytePosition */}, /*ACC_PotentialTgtTyp*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 223u/* AppAccBytePosition */}, /*RollingCounter_ACC6*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 224u/* AppAccBytePosition */}, /*Checksum_ACC7*/
  {3u/*BitLength*/, 381u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 225u/* AppAccBytePosition */}, /*Request_driveoff*/
  {8u/*BitLength*/, 328u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 226u/* AppAccBytePosition */}, /*ACC_LeTgtDy*/
  {9u/*BitLength*/, 351u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 227u/* AppAccBytePosition */}, /*ACC_LeTgtDx*/
  {3u/*BitLength*/, 348u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 229u/* AppAccBytePosition */}, /*ACC_LeTgtTyp*/
  {2u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 230u/* AppAccBytePosition */}, /*ACC_LeTargrtDection*/
  {2u/*BitLength*/, 344u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 231u/* AppAccBytePosition */}, /*ACC_RiTargrtDetn*/
  {8u/*BitLength*/, 352u/* BitPosition */, 1u/* ByteLength */, 44u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 232u/* AppAccBytePosition */}, /*ACC_RiTgtDy*/
  {9u/*BitLength*/, 375u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 233u/* AppAccBytePosition */}, /*ACC_RiTgtDx*/
  {3u/*BitLength*/, 372u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 235u/* AppAccBytePosition */}, /*ACC_RiTgtTyp*/
  {1u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 236u/* AppAccBytePosition */}, /*ACCSts*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 237u/* AppAccBytePosition */}, /*RollingCounter_ACC7*/
  {1u/*BitLength*/, 399u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 238u/* AppAccBytePosition */}, /*ACC_RlvTgtfusion*/
  {6u/*BitLength*/, 393u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 239u/* AppAccBytePosition */}, /*ACC_RlvTgtHeading*/
  {1u/*BitLength*/, 392u/* BitPosition */, 1u/* ByteLength */, 49u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 240u/* AppAccBytePosition */}, /*ACC_LeTgtfusion*/
  {6u/*BitLength*/, 402u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 241u/* AppAccBytePosition */}, /*ACC_LeTgtHeading*/
  {1u/*BitLength*/, 401u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 242u/* AppAccBytePosition */}, /*ACC_RiTgtfusion*/
  {6u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 243u/* AppAccBytePosition */}, /*ACC_RiTgtHeading*/
  {1u/*BitLength*/, 400u/* BitPosition */, 1u/* ByteLength */, 50u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 244u/* AppAccBytePosition */}, /*ACC_PotentialTgtfusion*/
  {6u/*BitLength*/, 420u/* BitPosition */, 2u/* ByteLength */, 52u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 13u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 245u/* AppAccBytePosition */}, /*ACC_PotentialTgtHeading*/
  {6u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 246u/* AppAccBytePosition */}, /*TargetCutinPro*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 247u/* AppAccBytePosition */}, /*TargetCutoutPro*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 9u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 248u/* AppAccBytePosition */}, /*ACC_FD2_0x2AB*/
  {6u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 304u/* AppAccBytePosition */}, /*JAPedObjExist*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 305u/* AppAccBytePosition */}, /*AEBJAObjID*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 306u/* AppAccBytePosition */}, /*AEBJAObjExist*/
  {8u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 307u/* AppAccBytePosition */}, /*JAPedObjID*/
  {1u/*BitLength*/, 81u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 308u/* AppAccBytePosition */}, /*AEBJAObjVideoCfmd*/
  {12u/*BitLength*/, 100u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 309u/* AppAccBytePosition */}, /*AEBJAObjVx*/
  {12u/*BitLength*/, 104u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 311u/* AppAccBytePosition */}, /*AEBJAObjDx*/
  {1u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 313u/* AppAccBytePosition */}, /*JAPedObjVideoCfmd*/
  {3u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 314u/* AppAccBytePosition */}, /*AEBJAObjState*/
  {12u/*BitLength*/, 148u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 315u/* AppAccBytePosition */}, /*AEBJAObjCntAlive*/
  {11u/*BitLength*/, 153u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 317u/* AppAccBytePosition */}, /*AEBJAObjDy*/
  {3u/*BitLength*/, 189u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 319u/* AppAccBytePosition */}, /*JAPedObjState*/
  {5u/*BitLength*/, 164u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 320u/* AppAccBytePosition */}, /*AEBJAObjObstcl*/
  {10u/*BitLength*/, 170u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 321u/* AppAccBytePosition */}, /*AEBJAObjVy*/
  {10u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 323u/* AppAccBytePosition */}, /*AEBJAObjAx*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 325u/* AppAccBytePosition */}, /*AEBJAObjAy*/
  {5u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 327u/* AppAccBytePosition */}, /*JAPedObjObstcl*/
  {11u/*BitLength*/, 229u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 328u/* AppAccBytePosition */}, /*JAPedObjDy*/
  {12u/*BitLength*/, 233u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 330u/* AppAccBytePosition */}, /*JAPedObjDx*/
  {6u/*BitLength*/, 242u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 332u/* AppAccBytePosition */}, /*FCWAEB_JATTC*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 333u/* AppAccBytePosition */}, /*JAPedObjVx*/
  {10u/*BitLength*/, 302u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 335u/* AppAccBytePosition */}, /*JAPedObjVy*/
  {10u/*BitLength*/, 308u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 337u/* AppAccBytePosition */}, /*JAPedObjAy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 339u/* AppAccBytePosition */}, /*JAPedObjCntAlive*/
  {6u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 341u/* AppAccBytePosition */}, /*FCWAEB_longTTC*/
  {6u/*BitLength*/, 370u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 342u/* AppAccBytePosition */}, /*FCWAEB_crossingTTC*/
  {10u/*BitLength*/, 342u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 343u/* AppAccBytePosition */}, /*JAPedObjAx*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 10u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 345u/* AppAccBytePosition */}, /*ACC_FD3_0x2B4*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 409u/* AppAccBytePosition */}, /*AEBObjID*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 410u/* AppAccBytePosition */}, /*AEBObjExist*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 411u/* AppAccBytePosition */}, /*AEBObjVideoCfmd*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 412u/* AppAccBytePosition */}, /*AEBObjVx*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 414u/* AppAccBytePosition */}, /*AEBObjDx*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 416u/* AppAccBytePosition */}, /*AEBObjCntAlive*/
  {11u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 418u/* AppAccBytePosition */}, /*AEBObjDy*/
  {3u/*BitLength*/, 69u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 420u/* AppAccBytePosition */}, /*AEBObjState*/
  {5u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 421u/* AppAccBytePosition */}, /*AEBObjObstcl*/
  {10u/*BitLength*/, 86u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 422u/* AppAccBytePosition */}, /*AEBObjVy*/
  {6u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 424u/* AppAccBytePosition */}, /*CyclistObjExist*/
  {10u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 425u/* AppAccBytePosition */}, /*AEBObjAx*/
  {10u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 427u/* AppAccBytePosition */}, /*AEBObjAy*/
  {12u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 429u/* AppAccBytePosition */}, /*CyclistObjDx*/
  {8u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 431u/* AppAccBytePosition */}, /*CyclistObjID*/
  {5u/*BitLength*/, 131u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 432u/* AppAccBytePosition */}, /*CyclistObjObstcl*/
  {11u/*BitLength*/, 136u/* BitPosition */, 2u/* ByteLength */, 17u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 433u/* AppAccBytePosition */}, /*CyclistObjDy*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 435u/* AppAccBytePosition */}, /*CyclistObjVx*/
  {12u/*BitLength*/, 160u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 437u/* AppAccBytePosition */}, /*CyclistObjCntAlive*/
  {10u/*BitLength*/, 182u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 439u/* AppAccBytePosition */}, /*CyclistObjVy*/
  {3u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 441u/* AppAccBytePosition */}, /*CyclistObjState*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 442u/* AppAccBytePosition */}, /*CyclistObjVideoCfmd*/
  {10u/*BitLength*/, 184u/* BitPosition */, 2u/* ByteLength */, 23u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 443u/* AppAccBytePosition */}, /*CyclistObjAx*/
  {10u/*BitLength*/, 206u/* BitPosition */, 2u/* ByteLength */, 25u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 445u/* AppAccBytePosition */}, /*CyclistObjAy*/
  {6u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 447u/* AppAccBytePosition */}, /*PedObjExist*/
  {8u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 448u/* AppAccBytePosition */}, /*PedObjID*/
  {5u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 449u/* AppAccBytePosition */}, /*PedObjObstcl*/
  {11u/*BitLength*/, 224u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 450u/* AppAccBytePosition */}, /*PedObjDy*/
  {12u/*BitLength*/, 244u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 452u/* AppAccBytePosition */}, /*PedObjDx*/
  {12u/*BitLength*/, 248u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 454u/* AppAccBytePosition */}, /*PedObjVx*/
  {10u/*BitLength*/, 270u/* BitPosition */, 2u/* ByteLength */, 33u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 456u/* AppAccBytePosition */}, /*PedObjVy*/
  {1u/*BitLength*/, 269u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 458u/* AppAccBytePosition */}, /*PedObjVideoCfmd*/
  {12u/*BitLength*/, 272u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 459u/* AppAccBytePosition */}, /*ACCTgtObjDx*/
  {10u/*BitLength*/, 294u/* BitPosition */, 2u/* ByteLength */, 36u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 461u/* AppAccBytePosition */}, /*PedObjAy*/
  {12u/*BitLength*/, 298u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 463u/* AppAccBytePosition */}, /*PedObjCntAlive*/
  {10u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 465u/* AppAccBytePosition */}, /*PedObjAx*/
  {8u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 467u/* AppAccBytePosition */}, /*ACCTgtObjID*/
  {5u/*BitLength*/, 323u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 468u/* AppAccBytePosition */}, /*ACCTgtObjObstcl*/
  {11u/*BitLength*/, 328u/* BitPosition */, 2u/* ByteLength */, 41u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 469u/* AppAccBytePosition */}, /*ACCTgtObjDy*/
  {6u/*BitLength*/, 338u/* BitPosition */, 1u/* ByteLength */, 42u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 471u/* AppAccBytePosition */}, /*ACCTgtObjExist*/
  {10u/*BitLength*/, 344u/* BitPosition */, 2u/* ByteLength */, 43u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 472u/* AppAccBytePosition */}, /*ACCTgtObjVy*/
  {12u/*BitLength*/, 364u/* BitPosition */, 2u/* ByteLength */, 45u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 474u/* AppAccBytePosition */}, /*ACCTgtObjVx*/
  {10u/*BitLength*/, 370u/* BitPosition */, 2u/* ByteLength */, 46u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 476u/* AppAccBytePosition */}, /*ACCTgtObjAx*/
  {10u/*BitLength*/, 376u/* BitPosition */, 2u/* ByteLength */, 47u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 478u/* AppAccBytePosition */}, /*ACCTgtObjAy*/
  {3u/*BitLength*/, 389u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 480u/* AppAccBytePosition */}, /*ACCTgtObjState*/
  {1u/*BitLength*/, 388u/* BitPosition */, 1u/* ByteLength */, 48u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 481u/* AppAccBytePosition */}, /*ACCTgtObjVideoCfmd*/
  {12u/*BitLength*/, 392u/* BitPosition */, 2u/* ByteLength */, 49u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 482u/* AppAccBytePosition */}, /*ACCTgtObjCntAlive*/
  {12u/*BitLength*/, 412u/* BitPosition */, 2u/* ByteLength */, 51u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 484u/* AppAccBytePosition */}, /*RadarHorMisalign*/
  {2u/*BitLength*/, 410u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 486u/* AppAccBytePosition */}, /*HandsoffDetd*/
  {2u/*BitLength*/, 408u/* BitPosition */, 1u/* ByteLength */, 51u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 487u/* AppAccBytePosition */}, /*DrvgOnHiWay*/
  {10u/*BitLength*/, 430u/* BitPosition */, 2u/* ByteLength */, 53u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 488u/* AppAccBytePosition */}, /*RoadCrvt*/
  {6u/*BitLength*/, 424u/* BitPosition */, 1u/* ByteLength */, 53u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 490u/* AppAccBytePosition */}, /*SpdLimitDst*/
  {10u/*BitLength*/, 446u/* BitPosition */, 2u/* ByteLength */, 55u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 16u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 491u/* AppAccBytePosition */}, /*RoadCrvtFar*/
  {6u/*BitLength*/, 440u/* BitPosition */, 1u/* ByteLength */, 55u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 493u/* AppAccBytePosition */}, /*RampDst*/
  {8u/*BitLength*/, 448u/* BitPosition */, 1u/* ByteLength */, 56u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 6u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 494u/* AppAccBytePosition */}, /*SpdLimit*/
  {6u/*BitLength*/, 458u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 495u/* AppAccBytePosition */}, /*CurveDst*/
  {2u/*BitLength*/, 456u/* BitPosition */, 1u/* ByteLength */, 57u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 496u/* AppAccBytePosition */}, /*NavSpdLimUnit*/
  {6u/*BitLength*/, 466u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 497u/* AppAccBytePosition */}, /*TunnelDst*/
  {2u/*BitLength*/, 464u/* BitPosition */, 1u/* ByteLength */, 58u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 498u/* AppAccBytePosition */}, /*DrvgOnRiLane*/
  {6u/*BitLength*/, 474u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 17u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 499u/* AppAccBytePosition */}, /*BrdgDst*/
  {1u/*BitLength*/, 473u/* BitPosition */, 1u/* ByteLength */, 59u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 500u/* AppAccBytePosition */}, /*RadarDrvrAttentive*/
  {8u/*BitLength*/, 504u/* BitPosition */, 1u/* ByteLength */, 63u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 501u/* AppAccBytePosition */}, /*ACC_DataRecReq*/
  {2u/*BitLength*/, 483u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 502u/* AppAccBytePosition */}, /*ACC_SOSReq*/
  {3u/*BitLength*/, 480u/* BitPosition */, 1u/* ByteLength */, 60u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 503u/* AppAccBytePosition */}, /*PedObjState*/
  {1u/*BitLength*/, 495u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 504u/* AppAccBytePosition */}, /*MapDataValid*/
  {3u/*BitLength*/, 492u/* BitPosition */, 1u/* ByteLength */, 61u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 505u/* AppAccBytePosition */}, /*DrvrSts*/
  {5u/*BitLength*/, 503u/* BitPosition */, 2u/* ByteLength */, 62u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 506u/* AppAccBytePosition */}, /*AEBObjOverlap*/
  {5u/*BitLength*/, 498u/* BitPosition */, 1u/* ByteLength */, 62u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 507u/* AppAccBytePosition */}, /*AEBObjDrvby*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 11u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 508u/* AppAccBytePosition */}, /*ACC_FD4_0x2B8*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 572u/* AppAccBytePosition */}, /*AEB_ABA_Level*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 573u/* AppAccBytePosition */}, /*AEB_ABA_Req*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 574u/* AppAccBytePosition */}, /*EBA_TgtDecel_Req*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 575u/* AppAccBytePosition */}, /*AEB_VehHldReq*/
  {1u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 576u/* AppAccBytePosition */}, /*AEB_TgtDecel_Req*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 577u/* AppAccBytePosition */}, /*AEB_TgtDecel_ReqValue*/
  {1u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 579u/* AppAccBytePosition */}, /*AEB_AWB_Req*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 580u/* AppAccBytePosition */}, /*AEB_AWB_Level*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 581u/* AppAccBytePosition */}, /*AEB_ABP_Req*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 582u/* AppAccBytePosition */}, /*AEB_BrkReqFunc*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 583u/* AppAccBytePosition */}, /*AEB_ObjSty*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 12u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 584u/* AppAccBytePosition */}, /*AEB_FD1_0x18B*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 648u/* AppAccBytePosition */}, /*Checksum_AEB2*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 649u/* AppAccBytePosition */}, /*AEB_PedResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 650u/* AppAccBytePosition */}, /*AEB_VehResp*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 651u/* AppAccBytePosition */}, /*FCW_Snvty*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 652u/* AppAccBytePosition */}, /*AEB_JA_Resp*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 653u/* AppAccBytePosition */}, /*RollingCounter_AEB2*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 654u/* AppAccBytePosition */}, /*Checksum_AEB3*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 655u/* AppAccBytePosition */}, /*AEB_VehTrig*/
  {1u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 656u/* AppAccBytePosition */}, /*AEB_PedTrig*/
  {2u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 657u/* AppAccBytePosition */}, /*FCW_AEB_VehFctSts*/
  {2u/*BitLength*/, 150u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 658u/* AppAccBytePosition */}, /*FCW_AEB_PedFctSts*/
  {2u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 659u/* AppAccBytePosition */}, /*FCW_Warn*/
  {2u/*BitLength*/, 146u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 660u/* AppAccBytePosition */}, /*AEB_JAFuncSts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 661u/* AppAccBytePosition */}, /*AEB_JA_Warn*/
  {2u/*BitLength*/, 158u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 662u/* AppAccBytePosition */}, /*AEB_JABrkTrig*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 663u/* AppAccBytePosition */}, /*RollingCounter_AEB3*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 13u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 664u/* AppAccBytePosition */}, /*AEB_FD2_0x227*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 720u/* AppAccBytePosition */}, /*CheckSum_HC1*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 721u/* AppAccBytePosition */}, /*ALS_FailSts*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 722u/* AppAccBytePosition */}, /*RollingCounter_HC1*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 14u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 18u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 723u/* AppAccBytePosition */}, /*ALS1_0x287*/
  {16u/*BitLength*/, 8u/* BitPosition */, 2u/* ByteLength */, 1u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 739u/* AppAccBytePosition */}, /*AMP_SWVersion*/
  {16u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 741u/* AppAccBytePosition */}, /*AMP_HWVersion*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 743u/* AppAccBytePosition */}, /*AMP_Chan1DTCInfo*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 744u/* AppAccBytePosition */}, /*AMP_Chan2DTCInfo*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 745u/* AppAccBytePosition */}, /*AMP_Chan3DTCInfo*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 746u/* AppAccBytePosition */}, /*AMP_Chan4DTCInfo*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 747u/* AppAccBytePosition */}, /*AMP_Chan5DTCInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 748u/* AppAccBytePosition */}, /*AMP_Chan6DTCInfo*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 749u/* AppAccBytePosition */}, /*AMP_Chan7DTCInfo*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 750u/* AppAccBytePosition */}, /*AMP_Chan8DTCInfo*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 751u/* AppAccBytePosition */}, /*AMP_TempValue*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 752u/* AppAccBytePosition */}, /*AMP_TempSts*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 753u/* AppAccBytePosition */}, /*AMP_VolValue*/
  {3u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 754u/* AppAccBytePosition */}, /*BestListegPosnResp*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 755u/* AppAccBytePosition */}, /*Clari_FiResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 15u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 756u/* AppAccBytePosition */}, /*AMP1_0x3E1*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 764u/* AppAccBytePosition */}, /*MediaCallSourceState*/
  {3u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 765u/* AppAccBytePosition */}, /*BeepSourceSts*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 766u/* AppAccBytePosition */}, /*BalanceSetState*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 767u/* AppAccBytePosition */}, /*VSCModeState*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 768u/* AppAccBytePosition */}, /*FadeSetState*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 769u/* AppAccBytePosition */}, /*DriveSideSts*/
  {5u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 770u/* AppAccBytePosition */}, /*BassSetState*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 771u/* AppAccBytePosition */}, /*MuteState*/
  {3u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 772u/* AppAccBytePosition */}, /*NaviSourceState*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 773u/* AppAccBytePosition */}, /*MidrangeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 774u/* AppAccBytePosition */}, /*T_box_ECallSts*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 775u/* AppAccBytePosition */}, /*GetHUTInfoSts*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 776u/* AppAccBytePosition */}, /*TrebleSetState*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 777u/* AppAccBytePosition */}, /*QLISurroundSetSt*/
  {1u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 778u/* AppAccBytePosition */}, /*AVMStResp*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 779u/* AppAccBytePosition */}, /*NaviMediaVolLvlResp*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 780u/* AppAccBytePosition */}, /*AVMMediaVolLvlResp*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 781u/* AppAccBytePosition */}, /*FPASChStResp*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 782u/* AppAccBytePosition */}, /*RPASChStResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 783u/* AppAccBytePosition */}, /*AMP2_0x3E3*/
  {6u/*BitLength*/, 2u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 791u/* AppAccBytePosition */}, /*HFMVolSetSts*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 792u/* AppAccBytePosition */}, /*VR_TTSVolSetSts*/
  {6u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 793u/* AppAccBytePosition */}, /*NaviVolumeSetState*/
  {6u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 794u/* AppAccBytePosition */}, /*MainVolumeSetState*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 795u/* AppAccBytePosition */}, /*AMPPowerSts*/
  {6u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 796u/* AppAccBytePosition */}, /*IPVolSetSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 17u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 797u/* AppAccBytePosition */}, /*AMP3_0x3E5*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 805u/* AppAccBytePosition */}, /*Microphone_Cha1DTCInfo*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 806u/* AppAccBytePosition */}, /*Microphone_Cha2DTCInfo*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 807u/* AppAccBytePosition */}, /*Microphone_Cha3DTCInfo*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 808u/* AppAccBytePosition */}, /*Microphone_Cha4DTCInfo*/
  {1u/*BitLength*/, 58u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 809u/* AppAccBytePosition */}, /*ANCSwtStatus*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 18u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 810u/* AppAccBytePosition */}, /*AMP4_ANC1_0x2D2*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 818u/* AppAccBytePosition */}, /*IPBackgroundLmpCmd*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 819u/* AppAccBytePosition */}, /*TrunkSts*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 820u/* AppAccBytePosition */}, /*DrvDoorSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 821u/* AppAccBytePosition */}, /*LRDoorSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 822u/* AppAccBytePosition */}, /*PassengerDoorSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 823u/* AppAccBytePosition */}, /*RRDoorSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 824u/* AppAccBytePosition */}, /*BrkPedalSts_BCM*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 21u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 825u/* AppAccBytePosition */}, /*BackgroundLightLvl*/
  {2u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 826u/* AppAccBytePosition */}, /*DrowsyDrvDetWarn*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 827u/* AppAccBytePosition */}, /*RLSFailSts*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 828u/* AppAccBytePosition */}, /*PosnLightReq*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 829u/* AppAccBytePosition */}, /*WindshldWiprActvSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 19u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 830u/* AppAccBytePosition */}, /*BCM1_0x319*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 838u/* AppAccBytePosition */}, /*LasHdLmpSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 839u/* AppAccBytePosition */}, /*AntitheftSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 840u/* AppAccBytePosition */}, /*DrvDoorLockSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 841u/* AppAccBytePosition */}, /*DoorLockSts*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 842u/* AppAccBytePosition */}, /*HiLowBeamSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 843u/* AppAccBytePosition */}, /*FreightLmpSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 844u/* AppAccBytePosition */}, /*BCM3_0x345*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 852u/* AppAccBytePosition */}, /*VolSwtReq*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 853u/* AppAccBytePosition */}, /*VolSwtErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 21u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 854u/* AppAccBytePosition */}, /*BCM6_0x28C*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 862u/* AppAccBytePosition */}, /*SecRowLeSeatVentSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 863u/* AppAccBytePosition */}, /*SecRowRiSeatVentSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 864u/* AppAccBytePosition */}, /*SecRowLeSeatHeatSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 865u/* AppAccBytePosition */}, /*SecRowRiSeatHeatSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 22u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 866u/* AppAccBytePosition */}, /*BCM7_0x28D*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 874u/* AppAccBytePosition */}, /*RemoteModSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 875u/* AppAccBytePosition */}, /*PASWorkCmd*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 876u/* AppAccBytePosition */}, /*KL30BRelaySts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 877u/* AppAccBytePosition */}, /*RViewMirrorSts*/
  {3u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 878u/* AppAccBytePosition */}, /*WiprReq_F_PBox*/
  {4u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 879u/* AppAccBytePosition */}, /*DrivingModReq*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 880u/* AppAccBytePosition */}, /*DrvAsstSwtReq*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 881u/* AppAccBytePosition */}, /*DrvAsstSwtErrSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 23u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 882u/* AppAccBytePosition */}, /*BCM8_0x29F*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 890u/* AppAccBytePosition */}, /*PassBliSpotVisSwt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 891u/* AppAccBytePosition */}, /*PassBliSpotVisSwtErrSts*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 24u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 18u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 892u/* AppAccBytePosition */}, /*BCM10_0x2E7*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 908u/* AppAccBytePosition */}, /*TAB_SwtShift_Warn*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 909u/* AppAccBytePosition */}, /*FourLModeSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 910u/* AppAccBytePosition */}, /*ExpertModSwtReq*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 911u/* AppAccBytePosition */}, /*SW_Warn*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 912u/* AppAccBytePosition */}, /*CCO_SwtShift_Warn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 25u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 913u/* AppAccBytePosition */}, /*BCM11_0x305*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 921u/* AppAccBytePosition */}, /*SrAntiPinch*/
  {7u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 922u/* AppAccBytePosition */}, /*SsPosn_VR_APP*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 923u/* AppAccBytePosition */}, /*SsAntiPinch*/
  {7u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 924u/* AppAccBytePosition */}, /*SrPosn_VR_APP*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 925u/* AppAccBytePosition */}, /*RLS_IRBrightness*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 926u/* AppAccBytePosition */}, /*RLS_FwBrightness*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 928u/* AppAccBytePosition */}, /*RLS_AmbBrightness*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 26u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 930u/* AppAccBytePosition */}, /*BCM12_0x238*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 938u/* AppAccBytePosition */}, /*RAntiPinchSts*/
  {6u/*BitLength*/, 60u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 939u/* AppAccBytePosition */}, /*RWinPosnSts_Perc*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 940u/* AppAccBytePosition */}, /*RainshedSts_R*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 941u/* AppAccBytePosition */}, /*TrunkSts_Y*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 942u/* AppAccBytePosition */}, /*RainshedSts_FL*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 943u/* AppAccBytePosition */}, /*RainshedSts_FR*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 27u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 944u/* AppAccBytePosition */}, /*BCM13_0x2A7*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 952u/* AppAccBytePosition */}, /*DrvSeatHeatSts_Nine*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 953u/* AppAccBytePosition */}, /*PassSeatHeatSts_Nine*/
  {4u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 954u/* AppAccBytePosition */}, /*DrvSeatVentnSts_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 955u/* AppAccBytePosition */}, /*PassSeatVentnSts_Nine*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 28u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 956u/* AppAccBytePosition */}, /*BCM14_0x2A3*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 964u/* AppAccBytePosition */}, /*BLEConnSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 965u/* AppAccBytePosition */}, /*BLESecuritySts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 29u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 966u/* AppAccBytePosition */}, /*BLE1_0x25C*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 974u/* AppAccBytePosition */}, /*BLE_BeanID*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 30u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 982u/* AppAccBytePosition */}, /*BLE5_0x1FA*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 990u/* AppAccBytePosition */}, /*BMS_PowerDownCmplt*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 991u/* AppAccBytePosition */}, /*BMS_ErrCategory*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 992u/* AppAccBytePosition */}, /*BMS_PackCurr*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 23u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 994u/* AppAccBytePosition */}, /*BMS_PackVolt*/
  {2u/*BitLength*/, 63u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 995u/* AppAccBytePosition */}, /*BMS_BattPoweErr*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 996u/* AppAccBytePosition */}, /*CheckSum_BMS4*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 997u/* AppAccBytePosition */}, /*RollingCounter_BMS4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 31u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 998u/* AppAccBytePosition */}, /*BMS4_0xF1*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1006u/* AppAccBytePosition */}, /*BMS_BattHeatRunaway*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1007u/* AppAccBytePosition */}, /*BMS_DisSOC1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 32u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1008u/* AppAccBytePosition */}, /*BMS8_0x285*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1016u/* AppAccBytePosition */}, /*BMS_IntelEngIdlChrgnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1017u/* AppAccBytePosition */}, /*BMS_BattKeepTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 33u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1018u/* AppAccBytePosition */}, /*BMS19_0x352*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1026u/* AppAccBytePosition */}, /*BMS_ChrgDurationTime*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 34u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1028u/* AppAccBytePosition */}, /*BMS22_0x3BF*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1036u/* AppAccBytePosition */}, /*BMS_SOCLowWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 35u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1037u/* AppAccBytePosition */}, /*BMS30_0x3F1*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 24u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1045u/* AppAccBytePosition */}, /*BMS_BattSOCLimResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 36u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1046u/* AppAccBytePosition */}, /*BMS35_0x2C4*/
  {10u/*BitLength*/, 40u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1054u/* AppAccBytePosition */}, /*BMS_BattSOC_P0*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 37u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1056u/* AppAccBytePosition */}, /*BMS65_0x14F*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1064u/* AppAccBytePosition */}, /*BMS_SocJumpWarn_RM*/
  {1u/*BitLength*/, 6u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1065u/* AppAccBytePosition */}, /*BMS_PackOverChrgWarn_RM*/
  {3u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1066u/* AppAccBytePosition */}, /*BMS_ChrgSts_RM*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 25u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1067u/* AppAccBytePosition */}, /*BMS_IsolationRValue_RM*/
  {15u/*BitLength*/, 33u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1069u/* AppAccBytePosition */}, /*BMS_PackCurr_RM*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1071u/* AppAccBytePosition */}, /*BMS_SocOverWarn_RM*/
  {1u/*BitLength*/, 47u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1072u/* AppAccBytePosition */}, /*BMS_BattOverTempRank_RM*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1073u/* AppAccBytePosition */}, /*BMS_BattOverVoltRank_RM*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1074u/* AppAccBytePosition */}, /*BMS_BattSOCLowRank_RM*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1075u/* AppAccBytePosition */}, /*BMS_VCUIsolateErr_RM*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1076u/* AppAccBytePosition */}, /*BMS_BattUnderVoltRank_RM*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1077u/* AppAccBytePosition */}, /*BMS_CellDeltaVoltRank_RM*/
  {1u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1078u/* AppAccBytePosition */}, /*BMS_CellOverVoltRank_RM*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1079u/* AppAccBytePosition */}, /*BMS_CellUnderVoltRank_RM*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1080u/* AppAccBytePosition */}, /*BMS_DeltaTempRank_RM*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1081u/* AppAccBytePosition */}, /*BMS_PackMismatchWarn_RM*/
  {14u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1082u/* AppAccBytePosition */}, /*BMS_PackVolt_RM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 38u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1084u/* AppAccBytePosition */}, /*BMS66_0x3AE*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1092u/* AppAccBytePosition */}, /*BMS_ChrgTimResp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 39u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1093u/* AppAccBytePosition */}, /*BMS_FD14_0x1E3*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1101u/* AppAccBytePosition */}, /*RoofModFb*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1102u/* AppAccBytePosition */}, /*AllTerrainDislFb*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1103u/* AppAccBytePosition */}, /*ElecSideStepSysFb*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 40u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1104u/* AppAccBytePosition */}, /*CP1_0x35E*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1112u/* AppAccBytePosition */}, /*CR_FCTA_Resp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1113u/* AppAccBytePosition */}, /*CR_FCTB_Resp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1114u/* AppAccBytePosition */}, /*CR_BliSts*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1115u/* AppAccBytePosition */}, /*FCTA_Warn*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1116u/* AppAccBytePosition */}, /*FCTBTrig*/
  {2u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1117u/* AppAccBytePosition */}, /*FCTA_B_FuncSts*/
  {6u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1118u/* AppAccBytePosition */}, /*FCTA_B_TTC*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 41u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1119u/* AppAccBytePosition */}, /*CR_FD1_0x15E*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1183u/* AppAccBytePosition */}, /*LTurnLmpSwtSts*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1184u/* AppAccBytePosition */}, /*RTurnLmpSwtSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1185u/* AppAccBytePosition */}, /*AutoLmpSwtSts*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1186u/* AppAccBytePosition */}, /*HornSwtSts*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1187u/* AppAccBytePosition */}, /*FrntWiprSwtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 42u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1188u/* AppAccBytePosition */}, /*CSA1_0x165*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1196u/* AppAccBytePosition */}, /*SteerWheelAng*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1198u/* AppAccBytePosition */}, /*SteerWheelAngSign*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1199u/* AppAccBytePosition */}, /*SAS_Sts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 43u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1200u/* AppAccBytePosition */}, /*CSA2_0xA1*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1208u/* AppAccBytePosition */}, /*MenuReturnSwtSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1209u/* AppAccBytePosition */}, /*SteerWheelHeatdSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1210u/* AppAccBytePosition */}, /*HomeSwtSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1211u/* AppAccBytePosition */}, /*MuteSwtSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1212u/* AppAccBytePosition */}, /*CustomSwtSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1213u/* AppAccBytePosition */}, /*PageUpSwtSts*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1214u/* AppAccBytePosition */}, /*PageDwnSwtSts*/
  {2u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1215u/* AppAccBytePosition */}, /*PageLSwtSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1216u/* AppAccBytePosition */}, /*PageRSwtSts*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1217u/* AppAccBytePosition */}, /*SeekUpSwtSts*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1218u/* AppAccBytePosition */}, /*SeekDwnSwtSts*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1219u/* AppAccBytePosition */}, /*AdjVolUpSwtSts*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1220u/* AppAccBytePosition */}, /*AdjVolDwnSwtSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1221u/* AppAccBytePosition */}, /*VRSwtSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1222u/* AppAccBytePosition */}, /*EnterSwtSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1223u/* AppAccBytePosition */}, /*EnterSwtSts_Mmed*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1224u/* AppAccBytePosition */}, /*CustomSwtSts_Mmed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 44u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1225u/* AppAccBytePosition */}, /*CSA3_0x244*/
  {12u/*BitLength*/, 52u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1233u/* AppAccBytePosition */}, /*TgtEngSpdIP*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1235u/* AppAccBytePosition */}, /*TgtEngSpdIPValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 45u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1236u/* AppAccBytePosition */}, /*DCT3_0xA6*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1244u/* AppAccBytePosition */}, /*CurrentGearValid*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1245u/* AppAccBytePosition */}, /*CURRENT_GEAR*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 26u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1246u/* AppAccBytePosition */}, /*TGS_LEVER*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1247u/* AppAccBytePosition */}, /*TRANS_Warning_LAMP*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 46u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1248u/* AppAccBytePosition */}, /*DCT5_0x221*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1256u/* AppAccBytePosition */}, /*DisplayGear*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1257u/* AppAccBytePosition */}, /*DrvModDisp_0xc6*/
  {2u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1258u/* AppAccBytePosition */}, /*ShiftRecommend_M*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1259u/* AppAccBytePosition */}, /*TCU_gear_flashing*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1260u/* AppAccBytePosition */}, /*TCU_Shift_not_allowed_Warn*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1261u/* AppAccBytePosition */}, /*TCU_Warn_drive_faulty*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1262u/* AppAccBytePosition */}, /*TCU_Warn_driver_leaves_car*/
  {1u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1263u/* AppAccBytePosition */}, /*TCU_Warn_gearbox_faulty*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1264u/* AppAccBytePosition */}, /*TCU_Warn_gearbox_N*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1265u/* AppAccBytePosition */}, /*TCU_Warn_high_temp*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1266u/* AppAccBytePosition */}, /*TCU_Warn_limphome_D*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1267u/* AppAccBytePosition */}, /*TCU_Warn_limphome_P*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1268u/* AppAccBytePosition */}, /*TCU_Warn_P_faulty*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1269u/* AppAccBytePosition */}, /*TCU_Warn_prohibit_P*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1270u/* AppAccBytePosition */}, /*TCU_Warn_release_button*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1271u/* AppAccBytePosition */}, /*TCU_Warn_shifter_faulty*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1272u/* AppAccBytePosition */}, /*TCU_Warn_step_P*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1273u/* AppAccBytePosition */}, /*TCU_Warn_vehicle_P*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1274u/* AppAccBytePosition */}, /*TRANS_OIL_TEMP_0xc6*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1275u/* AppAccBytePosition */}, /*TrsmStNID_0xc6*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 47u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1276u/* AppAccBytePosition */}, /*DCT9_0xC6*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1284u/* AppAccBytePosition */}, /*CheckSum_DCT7*/
  {3u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1285u/* AppAccBytePosition */}, /*TrsmStNID_0x236*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1286u/* AppAccBytePosition */}, /*DCT_RaceModeSts*/
  {8u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1287u/* AppAccBytePosition */}, /*TRANS_OIL_TEMP_0x236*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1288u/* AppAccBytePosition */}, /*DCT_PrsBrk_Warn*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1289u/* AppAccBytePosition */}, /*DCT_ShftNotAlwd_Warn*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1290u/* AppAccBytePosition */}, /*DCT_ShftRecom_M*/
  {3u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1291u/* AppAccBytePosition */}, /*DrvWarnMsg*/
  {4u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1292u/* AppAccBytePosition */}, /*DrvFaiMsg*/
  {3u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1293u/* AppAccBytePosition */}, /*DrvModDisp_0x236*/
  {2u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1294u/* AppAccBytePosition */}, /*DrvModDispSts*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1295u/* AppAccBytePosition */}, /*DrvAutoGearDisp*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1296u/* AppAccBytePosition */}, /*DrvGearDispSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1297u/* AppAccBytePosition */}, /*RollingCounter_DCT7*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 48u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1298u/* AppAccBytePosition */}, /*DCT_FD4_0x236*/
  {5u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1354u/* AppAccBytePosition */}, /*DrvWinPosnSts_Perc*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1355u/* AppAccBytePosition */}, /*DrvWinAntiPinchSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1356u/* AppAccBytePosition */}, /*DrvSideRearAntiPinchSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1357u/* AppAccBytePosition */}, /*DrvWinHotProtSts*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1358u/* AppAccBytePosition */}, /*DrvWinLrnSts*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1359u/* AppAccBytePosition */}, /*DrvSideRearWinLrnSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1360u/* AppAccBytePosition */}, /*DrvSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 49u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1361u/* AppAccBytePosition */}, /*DDCM1_0x2CA*/
  {5u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1369u/* AppAccBytePosition */}, /*DrvSideRearWinPosnSts_Perc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 50u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1370u/* AppAccBytePosition */}, /*DDCM3_0x2F7*/
  {3u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1378u/* AppAccBytePosition */}, /*DrvSeatMassLvlSetSts*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1379u/* AppAccBytePosition */}, /*DrvSeatMassModeSts*/
  {3u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1380u/* AppAccBytePosition */}, /*PassSeatMassgLvlSetSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1381u/* AppAccBytePosition */}, /*PassSeatMassgModeSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 51u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1382u/* AppAccBytePosition */}, /*DSC4_0x2CE*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1390u/* AppAccBytePosition */}, /*ChairMemPosnSetSwtFB*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 52u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1391u/* AppAccBytePosition */}, /*DSM1_0x2C1*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1399u/* AppAccBytePosition */}, /*DWD_WorkSts*/
  {5u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1400u/* AppAccBytePosition */}, /*DWD_TextDisp*/
  {4u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1401u/* AppAccBytePosition */}, /*DWD_Dis*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1402u/* AppAccBytePosition */}, /*DWD_SoundIndcn*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1403u/* AppAccBytePosition */}, /*RSnsrFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1404u/* AppAccBytePosition */}, /*LSnsrFailSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 53u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1405u/* AppAccBytePosition */}, /*DWD1_0x2B9*/
  {2u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1413u/* AppAccBytePosition */}, /*EB_TgtRcprtnTrqSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 54u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1414u/* AppAccBytePosition */}, /*EBOOSTER_FD1_0x12D*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1478u/* AppAccBytePosition */}, /*EMS_AuthenResult*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1479u/* AppAccBytePosition */}, /*EngSpd*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1481u/* AppAccBytePosition */}, /*EngSpdVldty*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1482u/* AppAccBytePosition */}, /*EngSpd_PHEV*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1484u/* AppAccBytePosition */}, /*EngSpdVldty_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 55u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1485u/* AppAccBytePosition */}, /*ECM1_0x111*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1493u/* AppAccBytePosition */}, /*FuelConsumption*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1495u/* AppAccBytePosition */}, /*TgtCrsVehSpd*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1496u/* AppAccBytePosition */}, /*CruiseCtrlSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1497u/* AppAccBytePosition */}, /*AccelPedalPosn*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1498u/* AppAccBytePosition */}, /*AccelPedalPosnVldty*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1499u/* AppAccBytePosition */}, /*ThrtlPosRatio*/
  {1u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1500u/* AppAccBytePosition */}, /*EngSVSSig*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1501u/* AppAccBytePosition */}, /*MILSts*/
  {2u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1502u/* AppAccBytePosition */}, /*EngState*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 56u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1503u/* AppAccBytePosition */}, /*ECM2_0x271*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1511u/* AppAccBytePosition */}, /*BaroPressure*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1512u/* AppAccBytePosition */}, /*EngCoolantTemp*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1513u/* AppAccBytePosition */}, /*GPF_Warning*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1514u/* AppAccBytePosition */}, /*GentrWarnLmpSts*/
  {1u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1515u/* AppAccBytePosition */}, /*EngClntTempWarn*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1516u/* AppAccBytePosition */}, /*EngClntTempVldty*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1517u/* AppAccBytePosition */}, /*SS_Screen_tip*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1518u/* AppAccBytePosition */}, /*SSSSetSts*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1519u/* AppAccBytePosition */}, /*SS_Enable_Lamp*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1520u/* AppAccBytePosition */}, /*SS_Fault_Lamp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1521u/* AppAccBytePosition */}, /*MaxEngTrqNorm*/
  {1u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1522u/* AppAccBytePosition */}, /*AGS_Failure*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 57u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1523u/* AppAccBytePosition */}, /*ECM3_0x371*/
  {16u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1531u/* AppAccBytePosition */}, /*NetEngTrq*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 11u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1533u/* AppAccBytePosition */}, /*DrvEngTrqReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 58u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1535u/* AppAccBytePosition */}, /*ECM4_0x82*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1543u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x84*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1544u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x84*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 59u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1545u/* AppAccBytePosition */}, /*ECM7_0x84*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1553u/* AppAccBytePosition */}, /*AccelPedlPosnDiagc*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 60u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1554u/* AppAccBytePosition */}, /*ECM9_0x102*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1562u/* AppAccBytePosition */}, /*ECM_ClutovrheatdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 61u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1563u/* AppAccBytePosition */}, /*ECM10_0x139*/
  {16u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1571u/* AppAccBytePosition */}, /*EngSpd_ForIP*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1573u/* AppAccBytePosition */}, /*ECM_OffroadThmSts*/
  {1u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1574u/* AppAccBytePosition */}, /*EWP_Err*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 62u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1575u/* AppAccBytePosition */}, /*ECM11_0x2D3*/
  {3u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1583u/* AppAccBytePosition */}, /*DPF_Warning*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1584u/* AppAccBytePosition */}, /*WIFSensorFailSts*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1585u/* AppAccBytePosition */}, /*GlowPlugLmpCmd*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1586u/* AppAccBytePosition */}, /*UreaLampCmd*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1587u/* AppAccBytePosition */}, /*Urea_Level*/
  {12u/*BitLength*/, 16u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1588u/* AppAccBytePosition */}, /*UreaRemainDist*/
  {4u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1590u/* AppAccBytePosition */}, /*SCRSysWarnDisplay*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1591u/* AppAccBytePosition */}, /*WIFFullLmpCmd*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1592u/* AppAccBytePosition */}, /*OilBoxSplySts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1593u/* AppAccBytePosition */}, /*DPF_Activation*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1594u/* AppAccBytePosition */}, /*LNT_Warning*/
  {5u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1595u/* AppAccBytePosition */}, /*SCRSysWarnDisplay_B2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 63u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1596u/* AppAccBytePosition */}, /*ECM16_0x2D4*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1604u/* AppAccBytePosition */}, /*ECM_VIN*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 64u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1612u/* AppAccBytePosition */}, /*ECM19_0x3B5*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 27u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 1620u/* AppAccBytePosition */}, /*ECM_VehDstBackup*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 65u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1624u/* AppAccBytePosition */}, /*ECM20_0x3B7*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1632u/* AppAccBytePosition */}, /*EngOilLvlWrn*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1633u/* AppAccBytePosition */}, /*EngOilLowPresWrn*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1634u/* AppAccBytePosition */}, /*EngOilPres*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1635u/* AppAccBytePosition */}, /*EngOilTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 66u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1636u/* AppAccBytePosition */}, /*ECM24_0x350*/
  {12u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1644u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvl*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1646u/* AppAccBytePosition */}, /*EngTrqCrankshaftLvlValid*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 67u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1647u/* AppAccBytePosition */}, /*ECM_PT5_0x8E*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1655u/* AppAccBytePosition */}, /*EngOilLvl*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1656u/* AppAccBytePosition */}, /*FTIVFault*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1657u/* AppAccBytePosition */}, /*FuelTankCapWarning*/
  {7u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1658u/* AppAccBytePosition */}, /*PressReliProgs*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 68u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1659u/* AppAccBytePosition */}, /*ECM_PT6_0x290*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1667u/* AppAccBytePosition */}, /*EngState_PHEV*/
  {4u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1668u/* AppAccBytePosition */}, /*CruiseCtrlSts_PHEV*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 69u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1669u/* AppAccBytePosition */}, /*ECM_PT7_0x117*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1677u/* AppAccBytePosition */}, /*TranPMode_Sts*/
  {3u/*BitLength*/, 4u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1678u/* AppAccBytePosition */}, /*Stat_PwrSv_Lvl*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1679u/* AppAccBytePosition */}, /*Dyn_PwrSv_Lvl*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1680u/* AppAccBytePosition */}, /*LvPwrSysErr*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1681u/* AppAccBytePosition */}, /*LimitStartSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 70u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1682u/* AppAccBytePosition */}, /*EEM1_0x2A8*/
  {4u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1690u/* AppAccBytePosition */}, /*FrntELDLckSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1691u/* AppAccBytePosition */}, /*RearELDLckSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 71u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1692u/* AppAccBytePosition */}, /*ELD1_0x152*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1700u/* AppAccBytePosition */}, /*CheckSum_EPB1*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1701u/* AppAccBytePosition */}, /*EPBErrSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1702u/* AppAccBytePosition */}, /*EPBRedLmpSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1703u/* AppAccBytePosition */}, /*EPBSts*/
  {4u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1704u/* AppAccBytePosition */}, /*EPBTextDisp*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1705u/* AppAccBytePosition */}, /*PressBrakePedalPointOut*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1706u/* AppAccBytePosition */}, /*RollingCounter_EPB1*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 72u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1707u/* AppAccBytePosition */}, /*EPB1_0x16B*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1715u/* AppAccBytePosition */}, /*CheckSum_EPS1_0x168*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1716u/* AppAccBytePosition */}, /*EPS_FailSts_0x168*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1717u/* AppAccBytePosition */}, /*EPS_SteerMod_0x168*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1718u/* AppAccBytePosition */}, /*SteerCorrnRmn_0x168*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1719u/* AppAccBytePosition */}, /*SteerCorrnResp_0x168*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1720u/* AppAccBytePosition */}, /*RollingCounter_EPS1_0x168*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 73u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1721u/* AppAccBytePosition */}, /*EPS1_0x168*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1729u/* AppAccBytePosition */}, /*CheckSum_EPS1_0x147*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1730u/* AppAccBytePosition */}, /*EPS_FailSts_0x147*/
  {3u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1731u/* AppAccBytePosition */}, /*EPS_SteerMod_0x147*/
  {2u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1732u/* AppAccBytePosition */}, /*SteerCorrnRmn_0x147*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1733u/* AppAccBytePosition */}, /*SteerCorrnResp_0x147*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1734u/* AppAccBytePosition */}, /*RollingCounter_EPS1_0x147*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 74u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1735u/* AppAccBytePosition */}, /*EPS_FD1_0x147*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1791u/* AppAccBytePosition */}, /*RotSteerWheel*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 75u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1792u/* AppAccBytePosition */}, /*ESCL2_0x303*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1800u/* AppAccBytePosition */}, /*CheckSum_ESP1_0x149*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1801u/* AppAccBytePosition */}, /*ESPActvInfoLmp_0x149*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1802u/* AppAccBytePosition */}, /*ESPFailSts_0x149*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1803u/* AppAccBytePosition */}, /*ESPFuncOffSts_0x149*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1804u/* AppAccBytePosition */}, /*TSM_Trailer_0x149*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1805u/* AppAccBytePosition */}, /*RollingCounter_ESP1_0x149*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 76u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1806u/* AppAccBytePosition */}, /*ESP1_0x149*/
  {1u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1814u/* AppAccBytePosition */}, /*Shift_N_Warn_0x145*/
  {1u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1815u/* AppAccBytePosition */}, /*FourL_Warn_0x145*/
  {2u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1816u/* AppAccBytePosition */}, /*AVHErrSts_0x145*/
  {2u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1817u/* AppAccBytePosition */}, /*AVHSts_0x145*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1818u/* AppAccBytePosition */}, /*CDPActv_0x145*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1819u/* AppAccBytePosition */}, /*CheckSum_ESP2_0x145*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1820u/* AppAccBytePosition */}, /*DrivingModDis_0x145*/
  {5u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1821u/* AppAccBytePosition */}, /*DrivingModReq_ESP_0x145*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1822u/* AppAccBytePosition */}, /*HDCCtrl_0x145*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1823u/* AppAccBytePosition */}, /*HDCFault_0x145*/
  {1u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1824u/* AppAccBytePosition */}, /*Over_Spd_Warn_0x145*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1825u/* AppAccBytePosition */}, /*RollingCounter_ESP2_0x145*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1826u/* AppAccBytePosition */}, /*TAB_Sts_0x145*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 77u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1827u/* AppAccBytePosition */}, /*ESP2_0x145*/
  {2u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1835u/* AppAccBytePosition */}, /*CCO_Warn*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1836u/* AppAccBytePosition */}, /*CCO_Active*/
  {5u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1837u/* AppAccBytePosition */}, /*CCO_TgtVel*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1838u/* AppAccBytePosition */}, /*EspFuncOffSts_mode*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 78u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1839u/* AppAccBytePosition */}, /*ESP8_0x170*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1847u/* AppAccBytePosition */}, /*ESP_HMI_WarningOn*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1848u/* AppAccBytePosition */}, /*WadeModeWarn*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 79u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1849u/* AppAccBytePosition */}, /*ESP11_0xC8*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1857u/* AppAccBytePosition */}, /*CheckSum_ESP2_0x137*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1858u/* AppAccBytePosition */}, /*HDCFault_0x137*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1859u/* AppAccBytePosition */}, /*HDCCtrl_0x137*/
  {2u/*BitLength*/, 98u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1860u/* AppAccBytePosition */}, /*AVHErrSts_0x137*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1861u/* AppAccBytePosition */}, /*AVHSts_0x137*/
  {1u/*BitLength*/, 103u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1862u/* AppAccBytePosition */}, /*CDPActv_0x137*/
  {5u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1863u/* AppAccBytePosition */}, /*DrivingModDis_0x137*/
  {5u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1864u/* AppAccBytePosition */}, /*DrivingModReq_ESP_0x137*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1865u/* AppAccBytePosition */}, /*Shift_N_Warn_0x137*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1866u/* AppAccBytePosition */}, /*Over_Spd_Warn_0x137*/
  {1u/*BitLength*/, 106u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1867u/* AppAccBytePosition */}, /*FourL_Warn_0x137*/
  {2u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1868u/* AppAccBytePosition */}, /*TAB_Sts_0x137*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1869u/* AppAccBytePosition */}, /*RollingCounter_ESP2_0x137*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1870u/* AppAccBytePosition */}, /*CheckSum_ESP1_0x137*/
  {1u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1871u/* AppAccBytePosition */}, /*ESPFuncOffSts_0x137*/
  {1u/*BitLength*/, 141u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1872u/* AppAccBytePosition */}, /*ESPActvInfoLmp_0x137*/
  {1u/*BitLength*/, 143u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1873u/* AppAccBytePosition */}, /*ESPFailSts_0x137*/
  {1u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1874u/* AppAccBytePosition */}, /*TSM_Trailer_0x137*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1875u/* AppAccBytePosition */}, /*IMC_Actv*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1876u/* AppAccBytePosition */}, /*RollingCounter_ESP1_0x137*/
  {8u/*BitLength*/, 320u/* BitPosition */, 1u/* ByteLength */, 40u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1877u/* AppAccBytePosition */}, /*CheckSum_ABS3_0x137*/
  {1u/*BitLength*/, 347u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1878u/* AppAccBytePosition */}, /*ABSActv_0x137*/
  {1u/*BitLength*/, 335u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1879u/* AppAccBytePosition */}, /*ABSFailSts_0x137*/
  {1u/*BitLength*/, 334u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1880u/* AppAccBytePosition */}, /*EBDFailSts_0x137*/
  {1u/*BitLength*/, 333u/* BitPosition */, 1u/* ByteLength */, 41u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1881u/* AppAccBytePosition */}, /*VehSpdVld_0x137*/
  {13u/*BitLength*/, 336u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1882u/* AppAccBytePosition */}, /*VehSpd_0x137*/
  {1u/*BitLength*/, 346u/* BitPosition */, 1u/* ByteLength */, 43u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1884u/* AppAccBytePosition */}, /*VehOdoInfoSts_0x137*/
  {10u/*BitLength*/, 352u/* BitPosition */, 2u/* ByteLength */, 44u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1885u/* AppAccBytePosition */}, /*VehOdoInfo_0x137*/
  {4u/*BitLength*/, 376u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1887u/* AppAccBytePosition */}, /*RollingCounter_ABS3_0x137*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 80u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 1888u/* AppAccBytePosition */}, /*ESP_FD2_0x137*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1944u/* AppAccBytePosition */}, /*FFogLmpSts_F_PBox*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1945u/* AppAccBytePosition */}, /*HiBeamSts_F_PBox*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1946u/* AppAccBytePosition */}, /*HoodSts_F_PBox*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1947u/* AppAccBytePosition */}, /*LasHdLmpSts_F_PBox*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1948u/* AppAccBytePosition */}, /*LHiBeamFailSts*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1949u/* AppAccBytePosition */}, /*RHiBeamFailSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1950u/* AppAccBytePosition */}, /*LLowBeamFailSts*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1951u/* AppAccBytePosition */}, /*LHeadLmpFailSts*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1952u/* AppAccBytePosition */}, /*RHeadLmpFailSts*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1953u/* AppAccBytePosition */}, /*RLowBeamFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1954u/* AppAccBytePosition */}, /*RLasHdLmpDiagSig*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1955u/* AppAccBytePosition */}, /*LLasHdLmpDiagSig*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1956u/* AppAccBytePosition */}, /*LowBeamSts_F_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 81u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 1957u/* AppAccBytePosition */}, /*F_PBOX1_0x19B*/
  {14u/*BitLength*/, 74u/* BitPosition */, 2u/* ByteLength */, 9u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 28u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1965u/* AppAccBytePosition */}, /*U_BATT*/
  {2u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1967u/* AppAccBytePosition */}, /*I_RANGE*/
  {16u/*BitLength*/, 88u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 29u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 1968u/* AppAccBytePosition */}, /*I_BATT*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1970u/* AppAccBytePosition */}, /*SOC*/
  {8u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1971u/* AppAccBytePosition */}, /*SOH_SUL*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1972u/* AppAccBytePosition */}, /*SOC_STATE*/
  {2u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 10u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 1973u/* AppAccBytePosition */}, /*SOH_SUL_STATE*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 82u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 1974u/* AppAccBytePosition */}, /*GW_FD1_0x2BB*/
  {16u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2038u/* AppAccBytePosition */}, /*ResetCount*/
  {88u/*BitLength*/, 40u/* BitPosition */, 11u/* ByteLength */, 5u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 30u/* InitValueIdx */, 11u/* AppAccBtyeLength */, 2040u/* AppAccBytePosition */}, /*CMACMessageInfo*/
  {24u/*BitLength*/, 16u/* BitPosition */, 3u/* ByteLength */, 2u/* BytePosition */, 83u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 27u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2051u/* AppAccBytePosition */}, /*TripCount*/
  {2u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2055u/* AppAccBytePosition */}, /*APS_PrkgMod*/
  {7u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2056u/* AppAccBytePosition */}, /*APS_ProcBar*/
  {1u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2057u/* AppAccBytePosition */}, /*APS_SwtSts*/
  {3u/*BitLength*/, 74u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2058u/* AppAccBytePosition */}, /*APS_SlotDisp*/
  {3u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2059u/* AppAccBytePosition */}, /*APS_SysSoundIndcn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2060u/* AppAccBytePosition */}, /*APS_PrkgTyp*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2061u/* AppAccBytePosition */}, /*APS_TextDisp*/
  {3u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2062u/* AppAccBytePosition */}, /*APS_WorkSts*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2063u/* AppAccBytePosition */}, /*APS_ESP_BrkDistance*/
  {1u/*BitLength*/, 168u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2065u/* AppAccBytePosition */}, /*MEB_AVHReq*/
  {1u/*BitLength*/, 283u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2066u/* AppAccBytePosition */}, /*LParaPrkgOutVald*/
  {1u/*BitLength*/, 282u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2067u/* AppAccBytePosition */}, /*RParaPrkgOutVald*/
  {1u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2068u/* AppAccBytePosition */}, /*HeadVertPrkgOutVald*/
  {1u/*BitLength*/, 280u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2069u/* AppAccBytePosition */}, /*TailVertPrkgOutVald*/
  {3u/*BitLength*/, 277u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2070u/* AppAccBytePosition */}, /*HAP_SwtDispCtrlCmd*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2071u/* AppAccBytePosition */}, /*P2P_PahDelSts*/
  {4u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2072u/* AppAccBytePosition */}, /*P2P_SelfDetErrCode*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2073u/* AppAccBytePosition */}, /*P2P_SelfDetSts*/
  {1u/*BitLength*/, 272u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2074u/* AppAccBytePosition */}, /*P2P_Pah1Avail*/
  {1u/*BitLength*/, 285u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2075u/* AppAccBytePosition */}, /*P2P_Pah2Avail*/
  {1u/*BitLength*/, 293u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2076u/* AppAccBytePosition */}, /*P2P_PrkgDirectSts*/
  {4u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2077u/* AppAccBytePosition */}, /*HAP_PrkgModCurrSts*/
  {2u/*BitLength*/, 294u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2078u/* AppAccBytePosition */}, /*APS_MovgDirc*/
  {2u/*BitLength*/, 366u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2079u/* AppAccBytePosition */}, /*ParallelSlotBtn_Ena*/
  {2u/*BitLength*/, 364u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2080u/* AppAccBytePosition */}, /*VerticalSlotBtn_Ena*/
  {2u/*BitLength*/, 362u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2081u/* AppAccBytePosition */}, /*ClockwiseBtn_Ena*/
  {2u/*BitLength*/, 360u/* BitPosition */, 1u/* ByteLength */, 45u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2082u/* AppAccBytePosition */}, /*AnticlockwiseBtn_Ena*/
  {2u/*BitLength*/, 374u/* BitPosition */, 1u/* ByteLength */, 46u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2083u/* AppAccBytePosition */}, /*SlotConfirmBtn_Ena*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 84u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2084u/* AppAccBytePosition */}, /*HAP_FD1_0x15B*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2148u/* AppAccBytePosition */}, /*AutoAVMSwtSet_Sts*/
  {2u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2149u/* AppAccBytePosition */}, /*AVM_CurrSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2150u/* AppAccBytePosition */}, /*GuidOvlSts*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2151u/* AppAccBytePosition */}, /*FrntCamInpFailSts*/
  {1u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2152u/* AppAccBytePosition */}, /*RearCamInpFailSts*/
  {1u/*BitLength*/, 110u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2153u/* AppAccBytePosition */}, /*LeCamInpFailSts*/
  {1u/*BitLength*/, 111u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2154u/* AppAccBytePosition */}, /*RiCamInpFailSts*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2155u/* AppAccBytePosition */}, /*EolNotCmpltd*/
  {1u/*BitLength*/, 105u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2156u/* AppAccBytePosition */}, /*OvlOpFailSts*/
  {2u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2157u/* AppAccBytePosition */}, /*LaneCalSts*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2158u/* AppAccBytePosition */}, /*RadarDispSts*/
  {3u/*BitLength*/, 97u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2159u/* AppAccBytePosition */}, /*LaneCalFltSts*/
  {1u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2160u/* AppAccBytePosition */}, /*AutoViewChgFuncSts*/
  {2u/*BitLength*/, 102u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2161u/* AppAccBytePosition */}, /*CarMdlTrsprcySts*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2162u/* AppAccBytePosition */}, /*CarMdlDispSts*/
  {1u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2163u/* AppAccBytePosition */}, /*CurrCalResultSts*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2164u/* AppAccBytePosition */}, /*MdlColrSts*/
  {6u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2165u/* AppAccBytePosition */}, /*SigViewIndcn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2166u/* AppAccBytePosition */}, /*HAP_DispCmd*/
  {9u/*BitLength*/, 112u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2167u/* AppAccBytePosition */}, /*AVM_3DAngSts*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2169u/* AppAccBytePosition */}, /*MOD_WorkSts*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2170u/* AppAccBytePosition */}, /*MOD_AlarmSts*/
  {2u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2171u/* AppAccBytePosition */}, /*DVRWorkSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2172u/* AppAccBytePosition */}, /*HAP_Hmi_Index*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 85u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2173u/* AppAccBytePosition */}, /*HAP_FD2_0x274*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 12u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2237u/* AppAccBytePosition */}, /*RPAS_NearBrrdstn*/
  {7u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2238u/* AppAccBytePosition */}, /*P2P_ProcBar*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2239u/* AppAccBytePosition */}, /*APS_ObjRiSideAr1*/
  {4u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2240u/* AppAccBytePosition */}, /*APS_ObjRiSideAr2*/
  {4u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2241u/* AppAccBytePosition */}, /*APS_ObjRiSideAr3*/
  {4u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2242u/* AppAccBytePosition */}, /*APS_ObjRiSideAr4*/
  {4u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2243u/* AppAccBytePosition */}, /*APS_ObjRiSideAr5*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2244u/* AppAccBytePosition */}, /*APS_ObjLeSideAr1*/
  {4u/*BitLength*/, 100u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2245u/* AppAccBytePosition */}, /*APS_ObjLeSideAr2*/
  {4u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2246u/* AppAccBytePosition */}, /*APS_ObjLeSideAr3*/
  {4u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2247u/* AppAccBytePosition */}, /*APS_ObjLeSideAr4*/
  {4u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2248u/* AppAccBytePosition */}, /*APS_ObjLeSideAr5*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2249u/* AppAccBytePosition */}, /*APS_FRSideSnsrFailSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2250u/* AppAccBytePosition */}, /*APS_FLSideSnsrFailSts*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2251u/* AppAccBytePosition */}, /*APS_RRSideSnsrFailSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2252u/* AppAccBytePosition */}, /*APS_RLSideSnsrFailSts*/
  {2u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2253u/* AppAccBytePosition */}, /*SDW_SoundIndcn*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2254u/* AppAccBytePosition */}, /*SDWActiveSts*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2255u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr1*/
  {4u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2256u/* AppAccBytePosition */}, /*RPAS_ObjRRCornrAr2*/
  {4u/*BitLength*/, 148u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2257u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr1*/
  {4u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2258u/* AppAccBytePosition */}, /*RPAS_ObjRRMidlAr2*/
  {4u/*BitLength*/, 156u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2259u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr1*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2260u/* AppAccBytePosition */}, /*RPAS_ObjRLMidlAr2*/
  {4u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2261u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr1*/
  {4u/*BitLength*/, 160u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2262u/* AppAccBytePosition */}, /*RPAS_ObjRLCornrAr2*/
  {1u/*BitLength*/, 175u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2263u/* AppAccBytePosition */}, /*RPAS_RLCornrSnsrFailSts*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2264u/* AppAccBytePosition */}, /*RPAS_RLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 173u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2265u/* AppAccBytePosition */}, /*RPAS_RRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 172u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2266u/* AppAccBytePosition */}, /*RPAS_RRCornrSnsrFailSts*/
  {2u/*BitLength*/, 170u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2267u/* AppAccBytePosition */}, /*RPAS_WorkSts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2268u/* AppAccBytePosition */}, /*RPAS_SoundIndcn*/
  {2u/*BitLength*/, 179u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2269u/* AppAccBytePosition */}, /*MEBWorkSts*/
  {1u/*BitLength*/, 178u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2270u/* AppAccBytePosition */}, /*MEB_EnableSts*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2271u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr1*/
  {4u/*BitLength*/, 200u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2272u/* AppAccBytePosition */}, /*FPAS_ObjFLCornrAr2*/
  {4u/*BitLength*/, 212u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2273u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr1*/
  {4u/*BitLength*/, 208u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2274u/* AppAccBytePosition */}, /*FPAS_ObjFLMidlAr2*/
  {4u/*BitLength*/, 220u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2275u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr1*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2276u/* AppAccBytePosition */}, /*FPAS_ObjFRMidlAr2*/
  {4u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2277u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr1*/
  {4u/*BitLength*/, 224u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2278u/* AppAccBytePosition */}, /*FPAS_ObjFRCornrAr2*/
  {1u/*BitLength*/, 239u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2279u/* AppAccBytePosition */}, /*FPAS_FLCornrSnsrFailSts*/
  {1u/*BitLength*/, 238u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2280u/* AppAccBytePosition */}, /*FPAS_FLMiddlSnsrFailSts*/
  {1u/*BitLength*/, 237u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2281u/* AppAccBytePosition */}, /*FPAS_FRMiddlSnsrFailSts*/
  {1u/*BitLength*/, 236u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2282u/* AppAccBytePosition */}, /*FPAS_FRCornrSnsrFailSts*/
  {2u/*BitLength*/, 234u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2283u/* AppAccBytePosition */}, /*FPAS_WorkSts*/
  {1u/*BitLength*/, 232u/* BitPosition */, 1u/* ByteLength */, 29u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2284u/* AppAccBytePosition */}, /*FPAS_AutoModSts*/
  {2u/*BitLength*/, 246u/* BitPosition */, 1u/* ByteLength */, 30u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2285u/* AppAccBytePosition */}, /*FPAS_SoundIndcn*/
  {7u/*BitLength*/, 252u/* BitPosition */, 2u/* ByteLength */, 31u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 22u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2286u/* AppAccBytePosition */}, /*FPAS_NearBrrdstn*/
  {4u/*BitLength*/, 276u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2287u/* AppAccBytePosition */}, /*APA_MenuDispCtrlCmd*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2288u/* AppAccBytePosition */}, /*APA_FuncSts*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2289u/* AppAccBytePosition */}, /*P2P_FuncSts*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2290u/* AppAccBytePosition */}, /*RADS_FuncSts*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2291u/* AppAccBytePosition */}, /*FADS_FuncSts*/
  {2u/*BitLength*/, 274u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2292u/* AppAccBytePosition */}, /*HAP_TextIconDispCtrl*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 86u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2293u/* AppAccBytePosition */}, /*HAP_FD3_0x298*/
  {2u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2357u/* AppAccBytePosition */}, /*HAP_RtCam_WorkSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2358u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_ID*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2359u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_type*/
  {4u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2360u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Confidence*/
  {12u/*BitLength*/, 28u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2361u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 44u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2363u/* AppAccBytePosition */}, /*HAP_RtSide_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2365u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_ID*/
  {3u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2366u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_type*/
  {4u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2367u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Confidence*/
  {12u/*BitLength*/, 92u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2368u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2370u/* AppAccBytePosition */}, /*HAP_RtSide_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2372u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_ID*/
  {3u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2373u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_type*/
  {4u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2374u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Confidence*/
  {12u/*BitLength*/, 156u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2375u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2377u/* AppAccBytePosition */}, /*HAP_RtSide_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2379u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_ID*/
  {3u/*BitLength*/, 201u/* BitPosition */, 1u/* ByteLength */, 25u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2380u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_type*/
  {4u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2381u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Confidence*/
  {12u/*BitLength*/, 220u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2382u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2384u/* AppAccBytePosition */}, /*HAP_RtSide_Obj4_Ground_Pos_Y*/
  {2u/*BitLength*/, 270u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2386u/* AppAccBytePosition */}, /*USS_FLSide1_Status*/
  {7u/*BitLength*/, 273u/* BitPosition */, 1u/* ByteLength */, 34u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2387u/* AppAccBytePosition */}, /*USS_FLSide1_Dist*/
  {2u/*BitLength*/, 268u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2388u/* AppAccBytePosition */}, /*USS_RLSide2_Status*/
  {7u/*BitLength*/, 281u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2389u/* AppAccBytePosition */}, /*USS_RLSide2_Dist*/
  {2u/*BitLength*/, 266u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2390u/* AppAccBytePosition */}, /*USS_FRSide1_Status*/
  {7u/*BitLength*/, 289u/* BitPosition */, 1u/* ByteLength */, 36u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2391u/* AppAccBytePosition */}, /*USS_FRSide1_Dist*/
  {2u/*BitLength*/, 264u/* BitPosition */, 1u/* ByteLength */, 33u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2392u/* AppAccBytePosition */}, /*USS_RRSide2_Status*/
  {7u/*BitLength*/, 297u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2393u/* AppAccBytePosition */}, /*USS_RRSide2_Dist*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 87u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2394u/* AppAccBytePosition */}, /*HAP_FD6_0x289*/
  {8u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2458u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_Diag*/
  {1u/*BitLength*/, 85u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2459u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn_DiagValid*/
  {5u/*BitLength*/, 299u/* BitPosition */, 1u/* ByteLength */, 37u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2460u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x60*/
  {3u/*BitLength*/, 317u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2461u/* AppAccBytePosition */}, /*HCU_RaceLaunchSts_0x60*/
  {2u/*BitLength*/, 286u/* BitPosition */, 1u/* ByteLength */, 35u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2462u/* AppAccBytePosition */}, /*HCU_RaceLaunchAvail_0x60*/
  {8u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2463u/* AppAccBytePosition */}, /*HCU_AccelPedalPosn*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2464u/* AppAccBytePosition */}, /*HCU_AccelPedalPosnValid*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 88u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2465u/* AppAccBytePosition */}, /*HCU_FD1_0x60*/
  {2u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2529u/* AppAccBytePosition */}, /*HCU_BattLowTemWarn*/
  {2u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2530u/* AppAccBytePosition */}, /*HCU_BattLowHeatSts*/
  {2u/*BitLength*/, 50u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2531u/* AppAccBytePosition */}, /*HCU_BattLowTempWarn*/
  {2u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2532u/* AppAccBytePosition */}, /*HCU_BattLowTempHeatSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 89u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2533u/* AppAccBytePosition */}, /*HCU_HC3_0x268*/
  {2u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2541u/* AppAccBytePosition */}, /*HCU_ACLineDisconnect*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2542u/* AppAccBytePosition */}, /*HCU_ChargSts*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2543u/* AppAccBytePosition */}, /*HCU_IntelBattTempMagSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 90u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2544u/* AppAccBytePosition */}, /*HCU_HC6_0x314*/
  {10u/*BitLength*/, 32u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2552u/* AppAccBytePosition */}, /*HCU_RecupPwr*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2554u/* AppAccBytePosition */}, /*HCU_EVContnsDistance*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2555u/* AppAccBytePosition */}, /*HCU_EVContnsDistanceVld*/
  {10u/*BitLength*/, 54u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2556u/* AppAccBytePosition */}, /*HCU_EgyUsed*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 91u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 5u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2558u/* AppAccBytePosition */}, /*HCU_HC7_0x3C2*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2566u/* AppAccBytePosition */}, /*HCU_TotalScore*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 92u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2567u/* AppAccBytePosition */}, /*HCU_HC8_0x1E2*/
  {8u/*BitLength*/, 34u/* BitPosition */, 2u/* ByteLength */, 4u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2575u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x9e*/
  {4u/*BitLength*/, 46u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2576u/* AppAccBytePosition */}, /*HCU_PowertrainSts_0x9e*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2577u/* AppAccBytePosition */}, /*TgtRcprtnTrqSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 93u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2578u/* AppAccBytePosition */}, /*HCU_HC16_0x9E*/
  {1u/*BitLength*/, 55u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2586u/* AppAccBytePosition */}, /*HCU_SOCMngmntSts*/
  {1u/*BitLength*/, 54u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2587u/* AppAccBytePosition */}, /*HCU_ARFSts*/
  {1u/*BitLength*/, 53u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2588u/* AppAccBytePosition */}, /*HCU_ASFCSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2589u/* AppAccBytePosition */}, /*HCU_AGSSts*/
  {4u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2590u/* AppAccBytePosition */}, /*PDCU_AvailabilityOfARF*/
  {1u/*BitLength*/, 63u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2591u/* AppAccBytePosition */}, /*PDCU_lossenPedalPrompt*/
  {1u/*BitLength*/, 62u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2592u/* AppAccBytePosition */}, /*PDCU_EvSave_disl*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2593u/* AppAccBytePosition */}, /*HCU_V2LReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 94u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2594u/* AppAccBytePosition */}, /*HCU_HP5_0x201*/
  {2u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2602u/* AppAccBytePosition */}, /*HCU_HybMod*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2603u/* AppAccBytePosition */}, /*HCU_HybFctnMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 95u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2604u/* AppAccBytePosition */}, /*HCU_HP6_0x11A*/
  {9u/*BitLength*/, 24u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 32u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2612u/* AppAccBytePosition */}, /*HCU_TrqLimMax_Norm*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 96u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2614u/* AppAccBytePosition */}, /*HCU_HP8_0xF9*/
  {1u/*BitLength*/, 33u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2622u/* AppAccBytePosition */}, /*HCU_GearChngPorNTXT*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 33u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2623u/* AppAccBytePosition */}, /*HCU_TotalScore_P0*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2624u/* AppAccBytePosition */}, /*HCU_SOCLow_Indcn*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2625u/* AppAccBytePosition */}, /*HCU_RemoveChrgLine_Indcn*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2626u/* AppAccBytePosition */}, /*HCU_Shift_P_Indcn*/
  {1u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2627u/* AppAccBytePosition */}, /*HCU_ConnectChrgLine_Indcn*/
  {2u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2628u/* AppAccBytePosition */}, /*HCU_EgyRecFB*/
  {1u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2629u/* AppAccBytePosition */}, /*HCU_OilTankCoverSts*/
  {1u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2630u/* AppAccBytePosition */}, /*HCU_InhbChrgInfo*/
  {1u/*BitLength*/, 34u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2631u/* AppAccBytePosition */}, /*ImdtlyChrgSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2632u/* AppAccBytePosition */}, /*HCU_EnerSavePowerMod*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2633u/* AppAccBytePosition */}, /*HCU_RefuReq*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2634u/* AppAccBytePosition */}, /*HCU_OPDFail*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2635u/* AppAccBytePosition */}, /*OPDParkWarnReq*/
  {2u/*BitLength*/, 49u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 20u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2636u/* AppAccBytePosition */}, /*HCU_ACStsReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 97u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2637u/* AppAccBytePosition */}, /*HCU_PT4_0x2FA*/
  {2u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2645u/* AppAccBytePosition */}, /*HCUImmoAuthRes*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2646u/* AppAccBytePosition */}, /*HCU_EVLmpSts*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2647u/* AppAccBytePosition */}, /*HCU_ECODrvHabit_Indcn*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 31u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2648u/* AppAccBytePosition */}, /*HCU_TotDrvReqPower_0x14a*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2649u/* AppAccBytePosition */}, /*HCU_AvailPower_TM*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2650u/* AppAccBytePosition */}, /*HCU_DrvMod*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 98u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2651u/* AppAccBytePosition */}, /*HCU_PT5_0x14A*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2659u/* AppAccBytePosition */}, /*HCU_12VSysErr_1*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2660u/* AppAccBytePosition */}, /*HCU_12VSysErr_2*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2661u/* AppAccBytePosition */}, /*HCU_HybSysErr_1*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2662u/* AppAccBytePosition */}, /*HCU_HybSysErr_2*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2663u/* AppAccBytePosition */}, /*HCU_HybSysErr_3*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2664u/* AppAccBytePosition */}, /*HCU_HybSysErr_5*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2665u/* AppAccBytePosition */}, /*HCU_HybSysErr_6*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2666u/* AppAccBytePosition */}, /*HCU_HybSysErr_7*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2667u/* AppAccBytePosition */}, /*HCU_HybSysErrLmpSts*/
  {5u/*BitLength*/, 51u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2668u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2669u/* AppAccBytePosition */}, /*HCU_12VSysErrLmpSts*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2670u/* AppAccBytePosition */}, /*HCU_PowerRedWarnLmpCmd*/
  {1u/*BitLength*/, 37u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2671u/* AppAccBytePosition */}, /*HCU_RdyLmpSts*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2672u/* AppAccBytePosition */}, /*CheckSum_HCU_PT7*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2673u/* AppAccBytePosition */}, /*HCU_HybSysErr_4*/
  {5u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2674u/* AppAccBytePosition */}, /*HCU_EnrgFlowInd_P2*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2675u/* AppAccBytePosition */}, /*HCU_12VSysErr_3*/
  {1u/*BitLength*/, 36u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2676u/* AppAccBytePosition */}, /*HCU_OPDLmpSts*/
  {3u/*BitLength*/, 41u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2677u/* AppAccBytePosition */}, /*HCU_OPDSts*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2678u/* AppAccBytePosition */}, /*HCU_ModSwtFail*/
  {4u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2679u/* AppAccBytePosition */}, /*RollingCounter_HCU_PT7*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 99u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2680u/* AppAccBytePosition */}, /*HCU_PT7_0x248*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2688u/* AppAccBytePosition */}, /*HCU_ChrgSysLmpSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2689u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_1*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2690u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_2*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2691u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_3*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2692u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_4*/
  {1u/*BitLength*/, 27u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2693u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_5*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2694u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_6*/
  {1u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2695u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_7*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2696u/* AppAccBytePosition */}, /*HCU_ChrgSysErr_8*/
  {4u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2697u/* AppAccBytePosition */}, /*HCU_DrvModDisp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 100u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2698u/* AppAccBytePosition */}, /*HCU_PT8_0x1C0*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2706u/* AppAccBytePosition */}, /*HUD_SwtSts*/
  {4u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 34u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2707u/* AppAccBytePosition */}, /*HUD_BrightnessLvl*/
  {5u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 19u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2708u/* AppAccBytePosition */}, /*HUD_HeightLvl*/
  {1u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2709u/* AppAccBytePosition */}, /*HUD_UIMod*/
  {1u/*BitLength*/, 61u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2710u/* AppAccBytePosition */}, /*HUD_UIModVld*/
  {3u/*BitLength*/, 45u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2711u/* AppAccBytePosition */}, /*HUD_Manufactor*/
  {3u/*BitLength*/, 42u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2712u/* AppAccBytePosition */}, /*HUD_ReslType*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 101u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2713u/* AppAccBytePosition */}, /*HUD1_0x325*/
  {14u/*BitLength*/, 18u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 35u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2721u/* AppAccBytePosition */}, /*IFCTrqOvlCmdProtnValue*/
  {11u/*BitLength*/, 45u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2723u/* AppAccBytePosition */}, /*IFCTrqOvlCmdReqValue*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 102u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 2725u/* AppAccBytePosition */}, /*IFC1_0x109*/
  {8u/*BitLength*/, 64u/* BitPosition */, 1u/* ByteLength */, 8u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2733u/* AppAccBytePosition */}, /*Checksum_IFC3*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2734u/* AppAccBytePosition */}, /*LDWResp*/
  {1u/*BitLength*/, 78u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2735u/* AppAccBytePosition */}, /*LKAResp*/
  {1u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2736u/* AppAccBytePosition */}, /*LCKResp*/
  {1u/*BitLength*/, 76u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2737u/* AppAccBytePosition */}, /*ELKResp*/
  {2u/*BitLength*/, 73u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2738u/* AppAccBytePosition */}, /*LDW_LKA_Snvty*/
  {1u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2739u/* AppAccBytePosition */}, /*IFCHUTInterface*/
  {2u/*BitLength*/, 84u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2740u/* AppAccBytePosition */}, /*LSSWarnFormResp*/
  {1u/*BitLength*/, 83u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2741u/* AppAccBytePosition */}, /*LSSResp*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2742u/* AppAccBytePosition */}, /*AESSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2743u/* AppAccBytePosition */}, /*ESSSts*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2744u/* AppAccBytePosition */}, /*AESErrSts*/
  {1u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2745u/* AppAccBytePosition */}, /*ESSErrSts*/
  {4u/*BitLength*/, 120u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2746u/* AppAccBytePosition */}, /*RollingCounter_IFC3*/
  {8u/*BitLength*/, 128u/* BitPosition */, 1u/* ByteLength */, 16u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2747u/* AppAccBytePosition */}, /*Checksum_IFC4*/
  {3u/*BitLength*/, 155u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2748u/* AppAccBytePosition */}, /*IFC_Handsoffwarn*/
  {2u/*BitLength*/, 153u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2749u/* AppAccBytePosition */}, /*IFCCalibrationSts*/
  {1u/*BitLength*/, 152u/* BitPosition */, 1u/* ByteLength */, 19u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2750u/* AppAccBytePosition */}, /*CameraBlockageSts*/
  {2u/*BitLength*/, 142u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2751u/* AppAccBytePosition */}, /*LDW_LKAWarn*/
  {3u/*BitLength*/, 139u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2752u/* AppAccBytePosition */}, /*LSSIntervention*/
  {3u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2753u/* AppAccBytePosition */}, /*LSSFuncSts*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2754u/* AppAccBytePosition */}, /*ELKMainState*/
  {2u/*BitLength*/, 147u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2755u/* AppAccBytePosition */}, /*LaneAvailability*/
  {2u/*BitLength*/, 145u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2756u/* AppAccBytePosition */}, /*TJA_FollowSts*/
  {3u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2757u/* AppAccBytePosition */}, /*LSSErrSts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2758u/* AppAccBytePosition */}, /*AESintervention*/
  {2u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2759u/* AppAccBytePosition */}, /*ESSintervention*/
  {2u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2760u/* AppAccBytePosition */}, /*ELKActSts*/
  {2u/*BitLength*/, 164u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2761u/* AppAccBytePosition */}, /*IntelligentEvaActSts*/
  {2u/*BitLength*/, 162u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2762u/* AppAccBytePosition */}, /*LCKStsIndcr*/
  {4u/*BitLength*/, 184u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2763u/* AppAccBytePosition */}, /*RollingCounter_IFC4*/
  {8u/*BitLength*/, 192u/* BitPosition */, 1u/* ByteLength */, 24u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2764u/* AppAccBytePosition */}, /*Checksum_IFC5*/
  {12u/*BitLength*/, 212u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 37u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2765u/* AppAccBytePosition */}, /*IFC_LaneCurve*/
  {3u/*BitLength*/, 209u/* BitPosition */, 1u/* ByteLength */, 26u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2767u/* AppAccBytePosition */}, /*IFC_LeLaneTyp*/
  {3u/*BitLength*/, 222u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2768u/* AppAccBytePosition */}, /*IFC_RiLaneTyp*/
  {3u/*BitLength*/, 219u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2769u/* AppAccBytePosition */}, /*IFC_NextLeLaneTyp*/
  {3u/*BitLength*/, 216u/* BitPosition */, 1u/* ByteLength */, 27u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2770u/* AppAccBytePosition */}, /*IFC_NextRiLaneTyp*/
  {12u/*BitLength*/, 236u/* BitPosition */, 2u/* ByteLength */, 29u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2771u/* AppAccBytePosition */}, /*IFC_LeLane_dy*/
  {12u/*BitLength*/, 240u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2773u/* AppAccBytePosition */}, /*IFC_RiLane_dy*/
  {4u/*BitLength*/, 248u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2775u/* AppAccBytePosition */}, /*RollingCounter_IFC5*/
  {8u/*BitLength*/, 256u/* BitPosition */, 1u/* ByteLength */, 32u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2776u/* AppAccBytePosition */}, /*Checksum_IFC6*/
  {12u/*BitLength*/, 276u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2777u/* AppAccBytePosition */}, /*IFC_NextLeLane_dy*/
  {12u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 38u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2779u/* AppAccBytePosition */}, /*IFC_NextRiLane_dy*/
  {4u/*BitLength*/, 312u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2781u/* AppAccBytePosition */}, /*RollingCounter_IFC6*/
  {1u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2782u/* AppAccBytePosition */}, /*AESResp*/
  {1u/*BitLength*/, 87u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2783u/* AppAccBytePosition */}, /*ESS_Pedresp*/
  {1u/*BitLength*/, 86u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2784u/* AppAccBytePosition */}, /*ESS_Vehresp*/
  {1u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2785u/* AppAccBytePosition */}, /*IntelligentEvaResp*/
  {448u/*BitLength*/, 0u/* BitPosition */, 56u/* ByteLength */, 0u/* BytePosition */, 103u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 14u/* InitValueIdx */, 56u/* AppAccBtyeLength */, 2786u/* AppAccBytePosition */}, /*IFC_FD2_0x23D*/
  {2u/*BitLength*/, 109u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2842u/* AppAccBytePosition */}, /*IDC_L2_TurnLightReq*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2843u/* AppAccBytePosition */}, /*TSRResp*/
  {2u/*BitLength*/, 77u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 1u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2844u/* AppAccBytePosition */}, /*TSRSpdLimUnit*/
  {6u/*BitLength*/, 82u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2845u/* AppAccBytePosition */}, /*TSRSpdLim*/
  {2u/*BitLength*/, 75u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2846u/* AppAccBytePosition */}, /*TSRSpdLimCfdc*/
  {3u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2847u/* AppAccBytePosition */}, /*TSRSts*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2848u/* AppAccBytePosition */}, /*TSRSpdLimSts*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2849u/* AppAccBytePosition */}, /*TSRTrfcSignValCfdc*/
  {8u/*BitLength*/, 102u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2850u/* AppAccBytePosition */}, /*TSRTrfcSignVal*/
  {1u/*BitLength*/, 101u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2851u/* AppAccBytePosition */}, /*TSRSpdLimWarn*/
  {1u/*BitLength*/, 108u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2852u/* AppAccBytePosition */}, /*TSRWarnResp*/
  {5u/*BitLength*/, 96u/* BitPosition */, 1u/* ByteLength */, 12u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 8u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2853u/* AppAccBytePosition */}, /*TSR_Snvty*/
  {2u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2854u/* AppAccBytePosition */}, /*HWA_TakOver_Req*/
  {3u/*BitLength*/, 149u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2855u/* AppAccBytePosition */}, /*HWA_TakOver_Trig*/
  {4u/*BitLength*/, 138u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2856u/* AppAccBytePosition */}, /*HWA_WarnInfoDisp*/
  {1u/*BitLength*/, 144u/* BitPosition */, 1u/* ByteLength */, 18u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2857u/* AppAccBytePosition */}, /*IFC_Line01_Source*/
  {1u/*BitLength*/, 174u/* BitPosition */, 1u/* ByteLength */, 21u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2858u/* AppAccBytePosition */}, /*IFC_Line02_Source*/
  {3u/*BitLength*/, 181u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2859u/* AppAccBytePosition */}, /*HWA_InhibitWarn*/
  {1u/*BitLength*/, 228u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2860u/* AppAccBytePosition */}, /*RainMode_Swt_Resp*/
  {2u/*BitLength*/, 226u/* BitPosition */, 1u/* ByteLength */, 28u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2861u/* AppAccBytePosition */}, /*LCMode_Swt_Resp*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 104u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2862u/* AppAccBytePosition */}, /*IFC_FD3_0x2CF*/
  {13u/*BitLength*/, 19u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2926u/* AppAccBytePosition */}, /*IFC_Line01_Dy*/
  {15u/*BitLength*/, 36u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2928u/* AppAccBytePosition */}, /*IFC_Line01_Curv*/
  {20u/*BitLength*/, 48u/* BitPosition */, 3u/* ByteLength */, 6u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2930u/* AppAccBytePosition */}, /*IFC_Line01_CurvChange*/
  {4u/*BitLength*/, 60u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2934u/* AppAccBytePosition */}, /*IFC_Line01_Type*/
  {13u/*BitLength*/, 83u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2935u/* AppAccBytePosition */}, /*IFC_Line02_Dy*/
  {15u/*BitLength*/, 100u/* BitPosition */, 3u/* ByteLength */, 12u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2937u/* AppAccBytePosition */}, /*IFC_Line02_Curv*/
  {20u/*BitLength*/, 112u/* BitPosition */, 3u/* ByteLength */, 14u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2939u/* AppAccBytePosition */}, /*IFC_Line02_CurvChange*/
  {4u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2943u/* AppAccBytePosition */}, /*IFC_Line02_Type*/
  {13u/*BitLength*/, 147u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2944u/* AppAccBytePosition */}, /*IFC_Line03_Dy*/
  {15u/*BitLength*/, 164u/* BitPosition */, 3u/* ByteLength */, 20u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2946u/* AppAccBytePosition */}, /*IFC_Line03_Curv*/
  {20u/*BitLength*/, 176u/* BitPosition */, 3u/* ByteLength */, 22u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2948u/* AppAccBytePosition */}, /*IFC_Line03_CurvChange*/
  {4u/*BitLength*/, 188u/* BitPosition */, 1u/* ByteLength */, 23u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2952u/* AppAccBytePosition */}, /*IFC_Line03_Type*/
  {13u/*BitLength*/, 211u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2953u/* AppAccBytePosition */}, /*IFC_Line04_Dy*/
  {15u/*BitLength*/, 228u/* BitPosition */, 3u/* ByteLength */, 28u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2955u/* AppAccBytePosition */}, /*IFC_Line04_Curv*/
  {20u/*BitLength*/, 240u/* BitPosition */, 3u/* ByteLength */, 30u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2957u/* AppAccBytePosition */}, /*IFC_Line04_CurvChange*/
  {4u/*BitLength*/, 252u/* BitPosition */, 1u/* ByteLength */, 31u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2961u/* AppAccBytePosition */}, /*IFC_Line04_Type*/
  {13u/*BitLength*/, 275u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2962u/* AppAccBytePosition */}, /*IFC_Roadedge01_Dy*/
  {15u/*BitLength*/, 292u/* BitPosition */, 3u/* ByteLength */, 36u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2964u/* AppAccBytePosition */}, /*IFC_Roadedge01_Curv*/
  {20u/*BitLength*/, 304u/* BitPosition */, 3u/* ByteLength */, 38u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2966u/* AppAccBytePosition */}, /*IFC_Roadedge01_CurvChange*/
  {4u/*BitLength*/, 316u/* BitPosition */, 1u/* ByteLength */, 39u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2970u/* AppAccBytePosition */}, /*IFC_Roadedge01_Type*/
  {13u/*BitLength*/, 339u/* BitPosition */, 2u/* ByteLength */, 42u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 39u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2971u/* AppAccBytePosition */}, /*IFC_Roadedge02_Dy*/
  {15u/*BitLength*/, 356u/* BitPosition */, 3u/* ByteLength */, 44u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 40u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 2973u/* AppAccBytePosition */}, /*IFC_Roadedge02_Curv*/
  {20u/*BitLength*/, 368u/* BitPosition */, 3u/* ByteLength */, 46u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT32_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 41u/* InitValueIdx */, 4u/* AppAccBtyeLength */, 2975u/* AppAccBytePosition */}, /*IFC_Roadedge02_CurvChange*/
  {4u/*BitLength*/, 380u/* BitPosition */, 1u/* ByteLength */, 47u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 2979u/* AppAccBytePosition */}, /*IFC_Roadedge02_Type*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 105u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 2980u/* AppAccBytePosition */}, /*IFC_FD5_0x19F*/
  {15u/*BitLength*/, 17u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3044u/* AppAccBytePosition */}, /*IFC_Line01_DxStart*/
  {15u/*BitLength*/, 34u/* BitPosition */, 3u/* ByteLength */, 4u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3046u/* AppAccBytePosition */}, /*IFC_Line01_DxEnd*/
  {9u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3048u/* AppAccBytePosition */}, /*IFC_Line01_HeadingAngle*/
  {9u/*BitLength*/, 48u/* BitPosition */, 2u/* ByteLength */, 6u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3050u/* AppAccBytePosition */}, /*IFC_Line02_HeadingAngle*/
  {15u/*BitLength*/, 81u/* BitPosition */, 2u/* ByteLength */, 10u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3052u/* AppAccBytePosition */}, /*IFC_Line02_DxStart*/
  {15u/*BitLength*/, 97u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3054u/* AppAccBytePosition */}, /*IFC_Line02_DxEnd*/
  {15u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3056u/* AppAccBytePosition */}, /*IFC_Line03_DxStart*/
  {15u/*BitLength*/, 145u/* BitPosition */, 2u/* ByteLength */, 18u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3058u/* AppAccBytePosition */}, /*IFC_Line03_DxEnd*/
  {9u/*BitLength*/, 152u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3060u/* AppAccBytePosition */}, /*IFC_Line03_HeadingAngle*/
  {15u/*BitLength*/, 169u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3062u/* AppAccBytePosition */}, /*IFC_Line04_DxStart*/
  {9u/*BitLength*/, 176u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3064u/* AppAccBytePosition */}, /*IFC_Line04_HeadingAngle*/
  {15u/*BitLength*/, 209u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3066u/* AppAccBytePosition */}, /*IFC_Line04_DxEnd*/
  {15u/*BitLength*/, 225u/* BitPosition */, 2u/* ByteLength */, 28u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3068u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxStart*/
  {15u/*BitLength*/, 241u/* BitPosition */, 2u/* ByteLength */, 30u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3070u/* AppAccBytePosition */}, /*IFC_Roadedge01_DxEnd*/
  {9u/*BitLength*/, 279u/* BitPosition */, 2u/* ByteLength */, 34u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3072u/* AppAccBytePosition */}, /*IFC_Roadedge01_HeadingAngle*/
  {15u/*BitLength*/, 280u/* BitPosition */, 2u/* ByteLength */, 35u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3074u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxStart*/
  {15u/*BitLength*/, 297u/* BitPosition */, 2u/* ByteLength */, 37u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3076u/* AppAccBytePosition */}, /*IFC_Roadedge02_DxEnd*/
  {9u/*BitLength*/, 304u/* BitPosition */, 2u/* ByteLength */, 38u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 42u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3078u/* AppAccBytePosition */}, /*IFC_Roadedge02_HeadingAngle*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 106u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3080u/* AppAccBytePosition */}, /*IFC_FD6_0x222*/
  {1u/*BitLength*/, 46u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3144u/* AppAccBytePosition */}, /*IB_Warn*/
  {2u/*BitLength*/, 44u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3145u/* AppAccBytePosition */}, /*BrkPedFeelMod*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 107u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3146u/* AppAccBytePosition */}, /*Ibooster_FD2_0x120*/
  {14u/*BitLength*/, 41u/* BitPosition */, 2u/* ByteLength */, 5u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 43u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3210u/* AppAccBytePosition */}, /*P2M_ActTrq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 108u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3212u/* AppAccBytePosition */}, /*P2M1_0xAC*/
  {16u/*BitLength*/, 60u/* BitPosition */, 3u/* ByteLength */, 7u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3220u/* AppAccBytePosition */}, /*P2M_ActSpd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 109u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 4u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3222u/* AppAccBytePosition */}, /*P2M3_0xBE*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3230u/* AppAccBytePosition */}, /*PassWinAntiPinchSts*/
  {5u/*BitLength*/, 35u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3231u/* AppAccBytePosition */}, /*PassWinPosnSts_Perc*/
  {1u/*BitLength*/, 17u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3232u/* AppAccBytePosition */}, /*PassSideRearWinAntiPinchSts*/
  {5u/*BitLength*/, 43u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3233u/* AppAccBytePosition */}, /*PassSideRearWinPosnSts_Perc*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3234u/* AppAccBytePosition */}, /*PassWinLrnSts*/
  {1u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3235u/* AppAccBytePosition */}, /*PassWinHotProtSts*/
  {1u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3236u/* AppAccBytePosition */}, /*PassSideRearWinLrnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3237u/* AppAccBytePosition */}, /*PassSideRearWinHotProtSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 110u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3238u/* AppAccBytePosition */}, /*PDCM1_0x2CD*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3246u/* AppAccBytePosition */}, /*SysPowerMod*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3247u/* AppAccBytePosition */}, /*SysPowerModVld*/
  {3u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3248u/* AppAccBytePosition */}, /*PEPS_PowerRlyOutpSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 111u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3249u/* AppAccBytePosition */}, /*PEPS2_0x295*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3257u/* AppAccBytePosition */}, /*WarnPowerNotInOffPosn*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3258u/* AppAccBytePosition */}, /*WarnKeyInCarWhenExit*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3259u/* AppAccBytePosition */}, /*WarnVldKeyNotFound*/
  {1u/*BitLength*/, 23u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3260u/* AppAccBytePosition */}, /*WarnEngStrtNotMeet*/
  {1u/*BitLength*/, 22u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3261u/* AppAccBytePosition */}, /*PowerRlyFault*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3262u/* AppAccBytePosition */}, /*AntLostFlg*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 112u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3263u/* AppAccBytePosition */}, /*PEPS4_0x302*/
  {2u/*BitLength*/, 80u/* BitPosition */, 1u/* ByteLength */, 10u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3271u/* AppAccBytePosition */}, /*RSDS_IPSoundReq*/
  {1u/*BitLength*/, 119u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3272u/* AppAccBytePosition */}, /*RSDS_ErrSts*/
  {1u/*BitLength*/, 118u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3273u/* AppAccBytePosition */}, /*RSDS_BrkgTrig*/
  {1u/*BitLength*/, 117u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3274u/* AppAccBytePosition */}, /*RSDS_BliSts*/
  {1u/*BitLength*/, 116u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3275u/* AppAccBytePosition */}, /*RSDS_TrailerSts*/
  {1u/*BitLength*/, 115u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3276u/* AppAccBytePosition */}, /*RSDS_LCAResp*/
  {1u/*BitLength*/, 114u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3277u/* AppAccBytePosition */}, /*RSDS_DOWResp*/
  {1u/*BitLength*/, 113u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3278u/* AppAccBytePosition */}, /*RSDS_RCWResp*/
  {1u/*BitLength*/, 112u/* BitPosition */, 1u/* ByteLength */, 14u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3279u/* AppAccBytePosition */}, /*RSDS_RCTAResp*/
  {1u/*BitLength*/, 127u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3280u/* AppAccBytePosition */}, /*RSDS_RCTABrkResp*/
  {2u/*BitLength*/, 104u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3281u/* AppAccBytePosition */}, /*RSDS_RCW_Trigger*/
  {1u/*BitLength*/, 126u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3282u/* AppAccBytePosition */}, /*RSDS_CTA_Actv*/
  {2u/*BitLength*/, 94u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3283u/* AppAccBytePosition */}, /*BSD_LCA_warningReqRight*/
  {2u/*BitLength*/, 92u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3284u/* AppAccBytePosition */}, /*BSD_LCA_warningReqleft*/
  {2u/*BitLength*/, 90u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3285u/* AppAccBytePosition */}, /*DOW_warningReqRight*/
  {2u/*BitLength*/, 88u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3286u/* AppAccBytePosition */}, /*DOW_warningReqleft*/
  {1u/*BitLength*/, 125u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3287u/* AppAccBytePosition */}, /*RCTA_warningReqRight*/
  {1u/*BitLength*/, 124u/* BitPosition */, 1u/* ByteLength */, 15u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3288u/* AppAccBytePosition */}, /*RCTA_warningReqLeft*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 113u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3289u/* AppAccBytePosition */}, /*RSDS_FD1_0x16F*/
  {6u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3353u/* AppAccBytePosition */}, /*RCTA_B_TTC*/
  {6u/*BitLength*/, 20u/* BitPosition */, 2u/* ByteLength */, 2u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3354u/* AppAccBytePosition */}, /*BSD_LCA_Left_TTC*/
  {6u/*BitLength*/, 30u/* BitPosition */, 2u/* ByteLength */, 3u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3355u/* AppAccBytePosition */}, /*BSD_LCA_Right_TTC*/
  {6u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3356u/* AppAccBytePosition */}, /*RCW_TTC*/
  {1u/*BitLength*/, 79u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3357u/* AppAccBytePosition */}, /*RSDS_LeTgt_01*/
  {10u/*BitLength*/, 94u/* BitPosition */, 2u/* ByteLength */, 11u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3358u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dx*/
  {7u/*BitLength*/, 72u/* BitPosition */, 1u/* ByteLength */, 9u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3360u/* AppAccBytePosition */}, /*RSDS_LeTgt_01_dy*/
  {1u/*BitLength*/, 93u/* BitPosition */, 1u/* ByteLength */, 11u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3361u/* AppAccBytePosition */}, /*RSDS_LeTgt_02*/
  {10u/*BitLength*/, 99u/* BitPosition */, 2u/* ByteLength */, 12u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3362u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dx*/
  {7u/*BitLength*/, 108u/* BitPosition */, 2u/* ByteLength */, 13u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3364u/* AppAccBytePosition */}, /*RSDS_LeTgt_02_dy*/
  {1u/*BitLength*/, 107u/* BitPosition */, 1u/* ByteLength */, 13u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3365u/* AppAccBytePosition */}, /*RSDS_RiTgt_01*/
  {10u/*BitLength*/, 113u/* BitPosition */, 2u/* ByteLength */, 14u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3366u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dx*/
  {7u/*BitLength*/, 137u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3368u/* AppAccBytePosition */}, /*RSDS_RiTgt_01_dy*/
  {1u/*BitLength*/, 136u/* BitPosition */, 1u/* ByteLength */, 17u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3369u/* AppAccBytePosition */}, /*RSDS_RiTgt_02*/
  {10u/*BitLength*/, 158u/* BitPosition */, 2u/* ByteLength */, 19u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3370u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dx*/
  {7u/*BitLength*/, 167u/* BitPosition */, 2u/* ByteLength */, 20u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3372u/* AppAccBytePosition */}, /*RSDS_RiTgt_02_dy*/
  {1u/*BitLength*/, 166u/* BitPosition */, 1u/* ByteLength */, 20u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3373u/* AppAccBytePosition */}, /*RSDS_MidTgt_01*/
  {10u/*BitLength*/, 172u/* BitPosition */, 2u/* ByteLength */, 21u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3374u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dx*/
  {7u/*BitLength*/, 181u/* BitPosition */, 2u/* ByteLength */, 22u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3376u/* AppAccBytePosition */}, /*RSDS_MidTgt_01_dy*/
  {1u/*BitLength*/, 180u/* BitPosition */, 1u/* ByteLength */, 22u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3377u/* AppAccBytePosition */}, /*RSDS_MidTgt_02*/
  {10u/*BitLength*/, 214u/* BitPosition */, 2u/* ByteLength */, 26u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 5u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3378u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dx*/
  {7u/*BitLength*/, 223u/* BitPosition */, 2u/* ByteLength */, 27u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3380u/* AppAccBytePosition */}, /*RSDS_MidTgt_02_dy*/
  {512u/*BitLength*/, 0u/* BitPosition */, 64u/* ByteLength */, 0u/* BytePosition */, 114u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 6u/* TimeoutIdx */, 15u/* InitValueIdx */, 64u/* AppAccBtyeLength */, 3381u/* AppAccBytePosition */}, /*RSDS_FD2_0x30A*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3445u/* AppAccBytePosition */}, /*RWPC_SwtSts*/
  {3u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3446u/* AppAccBytePosition */}, /*RWPC_FaultSts*/
  {2u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3447u/* AppAccBytePosition */}, /*RWPC_ChrgSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 115u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3448u/* AppAccBytePosition */}, /*RWPC1_0x35D*/
  {1u/*BitLength*/, 15u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3456u/* AppAccBytePosition */}, /*HiPosnBrkLmpFailSts*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3457u/* AppAccBytePosition */}, /*LicPlateLmpFailSts*/
  {1u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3458u/* AppAccBytePosition */}, /*LBrkLmpFailSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3459u/* AppAccBytePosition */}, /*RBrkLmpFailSts*/
  {1u/*BitLength*/, 11u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3460u/* AppAccBytePosition */}, /*PosnLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3461u/* AppAccBytePosition */}, /*RRPosnLmpFailSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3462u/* AppAccBytePosition */}, /*RvsLmpFailSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3463u/* AppAccBytePosition */}, /*LRPosnLmpFailSts*/
  {1u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3464u/* AppAccBytePosition */}, /*RWinHeatgIconRlyCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3465u/* AppAccBytePosition */}, /*RWinHeatgFailSts*/
  {2u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3466u/* AppAccBytePosition */}, /*RTurnLmpFailSts*/
  {2u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3467u/* AppAccBytePosition */}, /*LTurnLmpFailSts*/
  {1u/*BitLength*/, 31u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3468u/* AppAccBytePosition */}, /*LTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3469u/* AppAccBytePosition */}, /*RTurnLmpSts_R_PBox*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3470u/* AppAccBytePosition */}, /*RFogLmpFailSts_R_PBox*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3471u/* AppAccBytePosition */}, /*RFogLmpSts_R_PBox*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3472u/* AppAccBytePosition */}, /*ParkLmpSts_R_PBox*/
  {1u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3473u/* AppAccBytePosition */}, /*RBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 39u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3474u/* AppAccBytePosition */}, /*HiPosnBrkLmpOutpSts_R_PBox*/
  {1u/*BitLength*/, 38u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3475u/* AppAccBytePosition */}, /*LBrkLmpOutpSts_R_PBox*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 116u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3476u/* AppAccBytePosition */}, /*R_PBOX1_0x19C*/
  {1u/*BitLength*/, 19u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3484u/* AppAccBytePosition */}, /*FuncProtnSts*/
  {1u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3485u/* AppAccBytePosition */}, /*ShiftSysStuInLow*/
  {4u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3486u/* AppAccBytePosition */}, /*SystemOperMod*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3487u/* AppAccBytePosition */}, /*CouplingFaultSts*/
  {1u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3488u/* AppAccBytePosition */}, /*CouplingThermWarning*/
  {1u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3489u/* AppAccBytePosition */}, /*DiagLmpReq*/
  {1u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3490u/* AppAccBytePosition */}, /*ModeShiftTimeout*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3491u/* AppAccBytePosition */}, /*AutoShiftSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 117u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 1u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3492u/* AppAccBytePosition */}, /*TOD1_0x251*/
  {3u/*BitLength*/, 13u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3500u/* AppAccBytePosition */}, /*FLTirePressIndSts*/
  {3u/*BitLength*/, 10u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3501u/* AppAccBytePosition */}, /*FRTirePressIndSts*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3502u/* AppAccBytePosition */}, /*TirePressSysFailrIndcn*/
  {3u/*BitLength*/, 21u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3503u/* AppAccBytePosition */}, /*RLTirePressIndSts*/
  {3u/*BitLength*/, 18u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3504u/* AppAccBytePosition */}, /*RRTirePressIndSts*/
  {2u/*BitLength*/, 30u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3505u/* AppAccBytePosition */}, /*FLTireTempSts*/
  {2u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3506u/* AppAccBytePosition */}, /*FRTireTempSts*/
  {2u/*BitLength*/, 26u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3507u/* AppAccBytePosition */}, /*RLTireTempSts*/
  {2u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3508u/* AppAccBytePosition */}, /*RRTireTempSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 118u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3509u/* AppAccBytePosition */}, /*TPMS1_0x341*/
  {8u/*BitLength*/, 0u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3517u/* AppAccBytePosition */}, /*FLTirePress*/
  {8u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3518u/* AppAccBytePosition */}, /*FLTireTemp*/
  {8u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3519u/* AppAccBytePosition */}, /*FRTirePress*/
  {8u/*BitLength*/, 24u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3520u/* AppAccBytePosition */}, /*FRTireTemp*/
  {8u/*BitLength*/, 32u/* BitPosition */, 1u/* ByteLength */, 4u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3521u/* AppAccBytePosition */}, /*RLTirePress*/
  {8u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3522u/* AppAccBytePosition */}, /*RLTireTemp*/
  {8u/*BitLength*/, 48u/* BitPosition */, 1u/* ByteLength */, 6u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3523u/* AppAccBytePosition */}, /*RRTirePress*/
  {8u/*BitLength*/, 56u/* BitPosition */, 1u/* ByteLength */, 7u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_BYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3524u/* AppAccBytePosition */}, /*RRTireTemp*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 119u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3525u/* AppAccBytePosition */}, /*TPMS2_0x395*/
  {3u/*BitLength*/, 5u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3533u/* AppAccBytePosition */}, /*T_BOX_RemtDoorLockCtrl*/
  {2u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3534u/* AppAccBytePosition */}, /*T_BOX_AudioMuteReq*/
  {4u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 7u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3535u/* AppAccBytePosition */}, /*T_BOX_PM25AirQLvl*/
  {10u/*BitLength*/, 56u/* BitPosition */, 2u/* ByteLength */, 7u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT16_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBITNBYTE_SW_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 36u/* InitValueIdx */, 2u/* AppAccBtyeLength */, 3536u/* AppAccBytePosition */}, /*T_BOX_PM25Dens*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 120u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3538u/* AppAccBytePosition */}, /*T_BOX_FD1_0x33*/
  {5u/*BitLength*/, 3u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3546u/* AppAccBytePosition */}, /*T_BOX_SysErrSts*/
  {3u/*BitLength*/, 16u/* BitPosition */, 1u/* ByteLength */, 2u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3547u/* AppAccBytePosition */}, /*T_BOX_SWUpdSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 121u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 0u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3548u/* AppAccBytePosition */}, /*T_BOX_FD3_0x3E9*/
  {2u/*BitLength*/, 40u/* BitPosition */, 1u/* ByteLength */, 5u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3556u/* AppAccBytePosition */}, /*T_BOX_RemtVideoMonrEnaReq_APP*/
  {128u/*BitLength*/, 0u/* BitPosition */, 16u/* ByteLength */, 0u/* BytePosition */, 122u/* pduIdx */, COMEX_UINT8_N_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 65535u/* TimeoutIdx */, 18u/* InitValueIdx */, 16u/* AppAccBtyeLength */, 3557u/* AppAccBytePosition */}, /*T_BOX_FD4_0x1E1*/
  {1u/*BitLength*/, 7u/* BitPosition */, 1u/* ByteLength */, 0u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3573u/* AppAccBytePosition */}, /*TrailerSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 123u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 3u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3574u/* AppAccBytePosition */}, /*Trailer1_0x273*/
  {1u/*BitLength*/, 29u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3582u/* AppAccBytePosition */}, /*VMDR_TmpMonFctnSts*/
  {1u/*BitLength*/, 28u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3583u/* AppAccBytePosition */}, /*VMDR_InitAlarmDlySetSts*/
  {2u/*BitLength*/, 25u/* BitPosition */, 1u/* ByteLength */, 3u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3584u/* AppAccBytePosition */}, /*VMDR_FctnSts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 124u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3585u/* AppAccBytePosition */}, /*VMDR1_0x2FB*/
  {2u/*BitLength*/, 12u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3593u/* AppAccBytePosition */}, /*WPC_ChrgSts*/
  {2u/*BitLength*/, 14u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3594u/* AppAccBytePosition */}, /*WPC_SwtSts*/
  {3u/*BitLength*/, 9u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3595u/* AppAccBytePosition */}, /*WPC_FaultSts*/
  {1u/*BitLength*/, 8u/* BitPosition */, 1u/* ByteLength */, 1u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT8_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBIT_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 0u/* InitValueIdx */, 1u/* AppAccBtyeLength */, 3596u/* AppAccBytePosition */}, /*WPC_PhoneReminder*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* ByteLength */, 0u/* BytePosition */, 125u/* pduIdx */, COMEX_UINT64_APPLTYPEOFRXACCESSINFO/* ApplType */, COMEX_NBYTE_BUSACCOFRXACCESSINFO/* BusAccType */, 2u/* TimeoutIdx */, 2u/* InitValueIdx */, 8u/* AppAccBtyeLength */, 3597u/* AppAccBytePosition */}, /*WPC1_0x2BA*/
};


const ComEx_RxGroupInfoType ComEx_RxGroupInfo[ComEx_RxGroupSize] = 
{
  {0u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*ABM1*/
  {4u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* E2eIdx */}, /*ABS3*/
  {9u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 2u/* E2eIdx */}, /*ACC3_ACC_FD2*/
  {9u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 3u/* E2eIdx */}, /*ACC4_ACC_FD2*/
  {9u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 4u/* E2eIdx */}, /*ACC8_ACC_FD2*/
  {9u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 5u/* E2eIdx */}, /*ACC6_ACC_FD2*/
  {9u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 6u/* E2eIdx */}, /*ACC7_ACC_FD2*/
  {13u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 7u/* E2eIdx */}, /*AEB2_AEB_FD2*/
  {13u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 8u/* E2eIdx */}, /*AEB3_AEB_FD2*/
  {14u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 9u/* E2eIdx */}, /*ALS1*/
  {31u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 10u/* E2eIdx */}, /*BMS4*/
  {48u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 11u/* E2eIdx */}, /*DCT_FD4*/
  {72u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 12u/* E2eIdx */}, /*EPB1*/
  {73u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 13u/* E2eIdx */}, /*EPS1*/
  {74u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 14u/* E2eIdx */}, /*EPS_FD1*/
  {76u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 15u/* E2eIdx */}, /*ESP1*/
  {77u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 16u/* E2eIdx */}, /*ESP2*/
  {80u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 17u/* E2eIdx */}, /*ESP2_ESP_FD2*/
  {80u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 18u/* E2eIdx */}, /*ESP1_ESP_FD2*/
  {80u/* PduIdx */, 8u/* ByteLength */, 40u/* BytePosition */, 19u/* E2eIdx */}, /*ABS3_ESP_FD2*/
  {99u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 20u/* E2eIdx */}, /*HCU_PT7*/
  {103u/* PduIdx */, 8u/* ByteLength */, 8u/* BytePosition */, 21u/* E2eIdx */}, /*IFC3_IFC_FD2*/
  {103u/* PduIdx */, 8u/* ByteLength */, 16u/* BytePosition */, 22u/* E2eIdx */}, /*IFC4_IFC_FD2*/
  {103u/* PduIdx */, 8u/* ByteLength */, 24u/* BytePosition */, 23u/* E2eIdx */}, /*IFC5_IFC_FD2*/
  {103u/* PduIdx */, 8u/* ByteLength */, 32u/* BytePosition */, 24u/* E2eIdx */}, /*IFC6_IFC_FD2*/
};


const ComEx_RxPduInfoType ComEx_RxPduInfo[ComEx_RxPduSize] = 
{
  {0u/* SignalStartIdx */, 15u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABM1*/
  {15u/* SignalStartIdx */, 22u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABM2*/
  {22u/* SignalStartIdx */, 33u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 16u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS1*/
  {33u/* SignalStartIdx */, 44u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 24u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ABS2*/
  {44u/* SignalStartIdx */, 54u/* SignalEndIdx */, 1u/* GroupStartIdx */, 2u/* GroupEndIdx */, 32u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ABS3*/
  {54u/* SignalStartIdx */, 65u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 40u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC1*/
  {65u/* SignalStartIdx */, 78u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 48u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC2*/
  {78u/* SignalStartIdx */, 81u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 56u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC4*/
  {81u/* SignalStartIdx */, 84u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 64u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AC6*/
  {84u/* SignalStartIdx */, 169u/* SignalEndIdx */, 2u/* GroupStartIdx */, 7u/* GroupEndIdx */, 72u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ACC_FD2*/
  {169u/* SignalStartIdx */, 197u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 128u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD3*/
  {197u/* SignalStartIdx */, 266u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ACC_FD4*/
  {266u/* SignalStartIdx */, 278u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AEB_FD1*/
  {278u/* SignalStartIdx */, 295u/* SignalEndIdx */, 7u/* GroupStartIdx */, 9u/* GroupEndIdx */, 320u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AEB_FD2*/
  {295u/* SignalStartIdx */, 299u/* SignalEndIdx */, 9u/* GroupStartIdx */, 10u/* GroupEndIdx */, 376u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ALS1*/
  {299u/* SignalStartIdx */, 315u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP1*/
  {315u/* SignalStartIdx */, 335u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*AMP2*/
  {335u/* SignalStartIdx */, 342u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP3*/
  {342u/* SignalStartIdx */, 348u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*AMP4_ANC1*/
  {348u/* SignalStartIdx */, 361u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM1*/
  {361u/* SignalStartIdx */, 368u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 432u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*BCM3*/
  {368u/* SignalStartIdx */, 371u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 440u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM6*/
  {371u/* SignalStartIdx */, 376u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 448u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM7*/
  {376u/* SignalStartIdx */, 385u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 456u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM8*/
  {385u/* SignalStartIdx */, 388u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 464u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM10*/
  {388u/* SignalStartIdx */, 394u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM11*/
  {394u/* SignalStartIdx */, 402u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 488u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM12*/
  {402u/* SignalStartIdx */, 409u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 496u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM13*/
  {409u/* SignalStartIdx */, 414u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 504u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BCM14*/
  {414u/* SignalStartIdx */, 417u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 512u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE1*/
  {417u/* SignalStartIdx */, 419u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 520u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BLE5*/
  {419u/* SignalStartIdx */, 427u/* SignalEndIdx */, 10u/* GroupStartIdx */, 11u/* GroupEndIdx */, 528u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS4*/
  {427u/* SignalStartIdx */, 430u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 536u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS8*/
  {430u/* SignalStartIdx */, 433u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 544u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS19*/
  {433u/* SignalStartIdx */, 435u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 552u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS22*/
  {435u/* SignalStartIdx */, 437u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 560u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS30*/
  {437u/* SignalStartIdx */, 439u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 568u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS35*/
  {439u/* SignalStartIdx */, 441u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 576u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS65*/
  {441u/* SignalStartIdx */, 459u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 584u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS66*/
  {459u/* SignalStartIdx */, 461u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*BMS_FD14*/
  {461u/* SignalStartIdx */, 465u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CP1*/
  {465u/* SignalStartIdx */, 473u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 608u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CR_FD1*/
  {473u/* SignalStartIdx */, 479u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 672u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA1*/
  {479u/* SignalStartIdx */, 483u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 680u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA2*/
  {483u/* SignalStartIdx */, 501u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 688u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*CSA3*/
  {501u/* SignalStartIdx */, 504u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT3*/
  {504u/* SignalStartIdx */, 509u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT5*/
  {509u/* SignalStartIdx */, 530u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 712u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DCT9*/
  {530u/* SignalStartIdx */, 545u/* SignalEndIdx */, 11u/* GroupStartIdx */, 12u/* GroupEndIdx */, 720u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*DCT_FD4*/
  {545u/* SignalStartIdx */, 553u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 776u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM1*/
  {553u/* SignalStartIdx */, 555u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 784u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DDCM3*/
  {555u/* SignalStartIdx */, 560u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 792u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSC4*/
  {560u/* SignalStartIdx */, 562u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 800u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DSM1*/
  {562u/* SignalStartIdx */, 569u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 808u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*DWD1*/
  {569u/* SignalStartIdx */, 571u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 816u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EBOOSTER_FD1*/
  {571u/* SignalStartIdx */, 577u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 880u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM1*/
  {577u/* SignalStartIdx */, 587u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 888u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM2*/
  {587u/* SignalStartIdx */, 600u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 896u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM3*/
  {600u/* SignalStartIdx */, 603u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 904u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM4*/
  {603u/* SignalStartIdx */, 606u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 912u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM7*/
  {606u/* SignalStartIdx */, 608u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 920u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM9*/
  {608u/* SignalStartIdx */, 610u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 928u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM10*/
  {610u/* SignalStartIdx */, 614u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 936u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM11*/
  {614u/* SignalStartIdx */, 627u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 944u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM16*/
  {627u/* SignalStartIdx */, 629u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 952u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM19*/
  {629u/* SignalStartIdx */, 631u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 960u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM20*/
  {631u/* SignalStartIdx */, 636u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 968u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM24*/
  {636u/* SignalStartIdx */, 639u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 976u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT5*/
  {639u/* SignalStartIdx */, 644u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 984u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT6*/
  {644u/* SignalStartIdx */, 647u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 992u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ECM_PT7*/
  {647u/* SignalStartIdx */, 653u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1000u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EEM1*/
  {653u/* SignalStartIdx */, 656u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1008u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ELD1*/
  {656u/* SignalStartIdx */, 664u/* SignalEndIdx */, 12u/* GroupStartIdx */, 13u/* GroupEndIdx */, 1016u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPB1*/
  {664u/* SignalStartIdx */, 671u/* SignalEndIdx */, 13u/* GroupStartIdx */, 14u/* GroupEndIdx */, 1024u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*EPS1*/
  {671u/* SignalStartIdx */, 678u/* SignalEndIdx */, 14u/* GroupStartIdx */, 15u/* GroupEndIdx */, 1032u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*EPS_FD1*/
  {678u/* SignalStartIdx */, 680u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1088u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESCL2*/
  {680u/* SignalStartIdx */, 687u/* SignalEndIdx */, 15u/* GroupStartIdx */, 16u/* GroupEndIdx */, 1096u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP1*/
  {687u/* SignalStartIdx */, 701u/* SignalEndIdx */, 16u/* GroupStartIdx */, 17u/* GroupEndIdx */, 1104u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP2*/
  {701u/* SignalStartIdx */, 706u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1112u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP8*/
  {706u/* SignalStartIdx */, 709u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1120u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*ESP11*/
  {709u/* SignalStartIdx */, 739u/* SignalEndIdx */, 17u/* GroupStartIdx */, 20u/* GroupEndIdx */, 1128u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*ESP_FD2*/
  {739u/* SignalStartIdx */, 753u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1184u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*F_PBOX1*/
  {753u/* SignalStartIdx */, 761u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1192u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*GW_FD1*/
  {761u/* SignalStartIdx */, 764u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1256u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 2/* CalloutStartIdx */}, /*GW_Sync_Req*/
  {764u/* SignalStartIdx */, 793u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1272u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD1*/
  {793u/* SignalStartIdx */, 818u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1336u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD2*/
  {818u/* SignalStartIdx */, 875u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1400u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD3*/
  {875u/* SignalStartIdx */, 905u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1464u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HAP_FD6*/
  {905u/* SignalStartIdx */, 913u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1528u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_FD1*/
  {913u/* SignalStartIdx */, 918u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1592u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC3*/
  {918u/* SignalStartIdx */, 922u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1600u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC6*/
  {922u/* SignalStartIdx */, 927u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1608u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC7*/
  {927u/* SignalStartIdx */, 929u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1616u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC8*/
  {929u/* SignalStartIdx */, 933u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1624u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HC16*/
  {933u/* SignalStartIdx */, 942u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1632u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP5*/
  {942u/* SignalStartIdx */, 945u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1640u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP6*/
  {945u/* SignalStartIdx */, 947u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1648u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_HP8*/
  {947u/* SignalStartIdx */, 963u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1656u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT4*/
  {963u/* SignalStartIdx */, 970u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1664u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT5*/
  {970u/* SignalStartIdx */, 992u/* SignalEndIdx */, 20u/* GroupStartIdx */, 21u/* GroupEndIdx */, 1672u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT7*/
  {992u/* SignalStartIdx */, 1003u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1680u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HCU_PT8*/
  {1003u/* SignalStartIdx */, 1011u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1688u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*HUD1*/
  {1011u/* SignalStartIdx */, 1014u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1696u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC1*/
  {1014u/* SignalStartIdx */, 1063u/* SignalEndIdx */, 21u/* GroupStartIdx */, 25u/* GroupEndIdx */, 1704u/* BufferPosition */, 56u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*IFC_FD2*/
  {1063u/* SignalStartIdx */, 1084u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1760u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD3*/
  {1084u/* SignalStartIdx */, 1109u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1824u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD5*/
  {1109u/* SignalStartIdx */, 1128u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1888u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*IFC_FD6*/
  {1128u/* SignalStartIdx */, 1131u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 1952u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Ibooster_FD2*/
  {1131u/* SignalStartIdx */, 1133u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2016u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M1*/
  {1133u/* SignalStartIdx */, 1135u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2024u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*P2M3*/
  {1135u/* SignalStartIdx */, 1144u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2032u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PDCM1*/
  {1144u/* SignalStartIdx */, 1148u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2040u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS2*/
  {1148u/* SignalStartIdx */, 1155u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2048u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*PEPS4*/
  {1155u/* SignalStartIdx */, 1174u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2056u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD1*/
  {1174u/* SignalStartIdx */, 1197u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2120u/* BufferPosition */, 64u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RSDS_FD2*/
  {1197u/* SignalStartIdx */, 1201u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2184u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*RWPC1*/
  {1201u/* SignalStartIdx */, 1222u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2192u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*R_PBOX1*/
  {1222u/* SignalStartIdx */, 1231u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2200u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*TOD1*/
  {1231u/* SignalStartIdx */, 1241u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2208u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS1*/
  {1241u/* SignalStartIdx */, 1250u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2216u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*TPMS2*/
  {1250u/* SignalStartIdx */, 1255u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2224u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD1*/
  {1255u/* SignalStartIdx */, 1258u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2232u/* BufferPosition */, 8u/* BufferLength */, 2u/* CalloutNum */, 0/* CalloutStartIdx */}, /*T_BOX_FD3*/
  {1258u/* SignalStartIdx */, 1260u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2240u/* BufferPosition */, 16u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*T_BOX_FD4*/
  {1260u/* SignalStartIdx */, 1262u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2256u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*Trailer1*/
  {1262u/* SignalStartIdx */, 1266u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2264u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*VMDR1*/
  {1266u/* SignalStartIdx */, 1271u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 2272u/* BufferPosition */, 8u/* BufferLength */, 1u/* CalloutNum */, 3/* CalloutStartIdx */}, /*WPC1*/
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
  {E2EPW_ReadInit_ABS3_E2E/* InitFunPtr */, E2EPW_Read_ABS3_E2E/* ReadFunPtr */},
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
  {E2EPW_ReadInit_EPS1_E2E/* InitFunPtr */, E2EPW_Read_EPS1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_EPS_FD1_E2E/* InitFunPtr */, E2EPW_Read_EPS_FD1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP1_E2E/* InitFunPtr */, E2EPW_Read_ESP1_E2E/* ReadFunPtr */},
  {E2EPW_ReadInit_ESP2_E2E/* InitFunPtr */, E2EPW_Read_ESP2_E2E/* ReadFunPtr */},
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
  0x0u
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
  {3u/*BitLength*/, 32u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 12u/* BufferStartIdx */, 13u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExprsnSts*/
  {7u/*BitLength*/, 41u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 13u/* BufferStartIdx */, 14u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*GenderStsQlty*/
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
  {3u/*BitLength*/, 368u/* BitPosition */, 1u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 54u/* BufferStartIdx */, 55u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvBehvSts*/
  {512u/*BitLength*/, 0u/* BitPosition */, 1u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 8u/* BufferStartIdx */, 72u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DMS_FD1_0x24D*/
  {4u/*BitLength*/, 12u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSts*/
  {1u/*BitLength*/, 9u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVR_360VideoCaptureReq*/
  {3u/*BitLength*/, 26u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 75u/* BufferStartIdx */, 76u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRRemtCnSts*/
  {48u/*BitLength*/, 104u/* BitPosition */, 2u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 6u/* BusAccBtyeLength */, 80u/* BufferStartIdx */, 86u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRSN*/
  {2u/*BitLength*/, 10u/* BitPosition */, 2u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 73u/* BufferStartIdx */, 74u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DVRRemtCnSts_ev*/
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
  {3u/*BitLength*/, 5u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatSupportLvlSet*/
  {3u/*BitLength*/, 0u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 160u/* BufferStartIdx */, 161u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatSupportLvlSet*/
  {1u/*BitLength*/, 13u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAutoModReq_TC*/
  {1u/*BitLength*/, 10u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearOffReq_TC*/
  {2u/*BitLength*/, 8u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 161u/* BufferStartIdx */, 162u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet*/
  {2u/*BitLength*/, 22u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet*/
  {1u/*BitLength*/, 21u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ElecSideSteppingSysSet*/
  {2u/*BitLength*/, 19u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatVentnLvlSet*/
  {1u/*BitLength*/, 18u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RoofModSet*/
  {2u/*BitLength*/, 16u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 162u/* BufferStartIdx */, 163u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatVentnLvlSet*/
  {2u/*BitLength*/, 30u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatHeatgLvlSet*/
  {2u/*BitLength*/, 27u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatHeatgLvlSet*/
  {1u/*BitLength*/, 29u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AllTerrainDislSet*/
  {2u/*BitLength*/, 24u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 163u/* BufferStartIdx */, 164u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAutoModReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACCmprReq_VR*/
  {2u/*BitLength*/, 36u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPowerReq_VR*/
  {4u/*BitLength*/, 32u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 164u/* BufferStartIdx */, 165u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACBlwrSpdReq_VR*/
  {6u/*BitLength*/, 42u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempReq_VR*/
  {2u/*BitLength*/, 40u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 165u/* BufferStartIdx */, 166u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntDefrostReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvAirDistribModReq_VR*/
  {2u/*BitLength*/, 51u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAirInletReq_VR*/
  {3u/*BitLength*/, 48u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 166u/* BufferStartIdx */, 167u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAirDistribModReq_TC*/
  {2u/*BitLength*/, 62u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACModReq_HUT*/
  {1u/*BitLength*/, 56u/* BitPosition */, 6u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 167u/* BufferStartIdx */, 168u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RemUpgrdSts*/
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
  {1u/*BitLength*/, 20u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 178u/* BufferStartIdx */, 179u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt_OLE*/
  {1u/*BitLength*/, 19u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 178u/* BufferStartIdx */, 179u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRdmSwt_OLE*/
  {1u/*BitLength*/, 8u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 177u/* BufferStartIdx */, 178u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt_OLE*/
  {2u/*BitLength*/, 6u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRTmpMonFctnSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 8u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 177u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_VMDRInitAlarmDlySet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 8u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 176u/* BufferStartIdx */, 184u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT7_0x44*/
  {2u/*BitLength*/, 10u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDualReq_VR*/
  {2u/*BitLength*/, 8u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 185u/* BufferStartIdx */, 186u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAQSReq_VR*/
  {2u/*BitLength*/, 40u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearDefrstReq_VR*/
  {6u/*BitLength*/, 48u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACPassTempReq_VR*/
  {2u/*BitLength*/, 56u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACAIUReq_VR*/
  {1u/*BitLength*/, 47u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMStatSwt*/
  {1u/*BitLength*/, 46u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynSwt*/
  {2u/*BitLength*/, 42u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 189u/* BufferStartIdx */, 190u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_BeanIDReq*/
  {6u/*BitLength*/, 32u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 188u/* BufferStartIdx */, 189u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMClrSet*/
  {1u/*BitLength*/, 24u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 187u/* BufferStartIdx */, 188u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMRhmSwt*/
  {6u/*BitLength*/, 58u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 191u/* BufferStartIdx */, 192u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*IPVolSet*/
  {2u/*BitLength*/, 54u/* BitPosition */, 9u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 190u/* BufferStartIdx */, 191u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PASSwtReq_VR*/
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
  {1u/*BitLength*/, 60u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 207u/* BufferStartIdx */, 208u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DWD_WorkCmd*/
  {2u/*BitLength*/, 48u/* BitPosition */, 11u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 206u/* BufferStartIdx */, 207u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AVMAutoSet*/
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
  {64u/*BitLength*/, 0u/* BitPosition */, 20u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 272u/* BufferStartIdx */, 280u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT25_0x339*/
  {3u/*BitLength*/, 53u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 286u/* BufferStartIdx */, 287u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SeatFlankAdjmtSwt_HUT*/
  {1u/*BitLength*/, 16u/* BitPosition */, 21u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 282u/* BufferStartIdx */, 283u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AVM_dispsts*/
  {64u/*BitLength*/, 0u/* BitPosition */, 21u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 280u/* BufferStartIdx */, 288u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT26_0x2B6*/
  {2u/*BitLength*/, 61u/* BitPosition */, 22u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 295u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_HCU*/
  {64u/*BitLength*/, 0u/* BitPosition */, 22u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 288u/* BufferStartIdx */, 296u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT27_0x2B2*/
  {5u/*BitLength*/, 8u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_HeightLvlSwt*/
  {4u/*BitLength*/, 28u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 299u/* BufferStartIdx */, 300u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_BrightnessLvlSwt*/
  {2u/*BitLength*/, 24u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 299u/* BufferStartIdx */, 300u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUD_SwtReq*/
  {1u/*BitLength*/, 13u/* BitPosition */, 23u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 297u/* BufferStartIdx */, 298u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_AVM*/
  {64u/*BitLength*/, 0u/* BitPosition */, 23u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 296u/* BufferStartIdx */, 304u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT30_0x1E9*/
  {64u/*BitLength*/, 56u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_PhoneNextRoad*/
  {64u/*BitLength*/, 0u/* BitPosition */, 24u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 304u/* BufferStartIdx */, 312u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT31_0x30C*/
  {8u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 313u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_HUT32*/
  {2u/*BitLength*/, 46u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ScrnOpSts*/
  {11u/*BitLength*/, 29u/* BitPosition */, 25u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 314u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*XLvl*/
  {11u/*BitLength*/, 32u/* BitPosition */, 25u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 317u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*YLvl*/
  {1u/*BitLength*/, 9u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DetVideoLost*/
  {1u/*BitLength*/, 10u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkgCtrlModReqValid*/
  {2u/*BitLength*/, 12u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkgCtrlModReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ContnPrkgReqValid*/
  {2u/*BitLength*/, 14u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ContnPrkgReq*/
  {1u/*BitLength*/, 11u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 313u/* BufferStartIdx */, 314u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSwtReq_HUT*/
  {2u/*BitLength*/, 27u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 315u/* BufferStartIdx */, 316u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSuspendOrFinishReq_HUT*/
  {3u/*BitLength*/, 61u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightModSel_HUT*/
  {1u/*BitLength*/, 60u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightSts_HUT*/
  {1u/*BitLength*/, 45u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightStrtReq_HUT*/
  {1u/*BitLength*/, 44u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 317u/* BufferStartIdx */, 318u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightVehStrtReq_HUT_Valid*/
  {1u/*BitLength*/, 55u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*PrkStraightContinueReq_HUT*/
  {1u/*BitLength*/, 54u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*P2P_PrkgDirSwtReq*/
  {4u/*BitLength*/, 56u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 319u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_HUT32*/
  {1u/*BitLength*/, 51u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RainMode_Swt_Req*/
  {2u/*BitLength*/, 49u/* BitPosition */, 25u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 318u/* BufferStartIdx */, 319u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCMode_Swt_Req*/
  {64u/*BitLength*/, 0u/* BitPosition */, 25u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 312u/* BufferStartIdx */, 320u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT32_0x26F*/
  {2u/*BitLength*/, 4u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 321u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FlaoutUnlockSet*/
  {2u/*BitLength*/, 11u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PrkInDirChoice*/
  {2u/*BitLength*/, 60u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt*/
  {2u/*BitLength*/, 56u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt*/
  {2u/*BitLength*/, 58u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*NaviDispSwt_VR*/
  {2u/*BitLength*/, 62u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 327u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ADASDispSwt_VR*/
  {2u/*BitLength*/, 6u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 321u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ApproachLampSet*/
  {2u/*BitLength*/, 2u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 321u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SuperLockSet*/
  {3u/*BitLength*/, 50u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMDynModSet*/
  {3u/*BitLength*/, 32u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 324u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLWinSwtReq_VR*/
  {3u/*BitLength*/, 53u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 326u/* BufferStartIdx */, 327u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRWinSwtReq_VR*/
  {3u/*BitLength*/, 13u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvWinSwtReq_VR*/
  {3u/*BitLength*/, 35u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 324u/* BufferStartIdx */, 325u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassWinSwtReq_VR*/
  {3u/*BitLength*/, 8u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 321u/* BufferStartIdx */, 322u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSetSwt*/
  {1u/*BitLength*/, 17u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngFinshCmd*/
  {1u/*BitLength*/, 18u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PathLrngStartCmd*/
  {3u/*BitLength*/, 21u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkOutDirReq*/
  {1u/*BitLength*/, 25u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath2Cmd*/
  {1u/*BitLength*/, 26u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath2Cmd*/
  {1u/*BitLength*/, 27u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*StartPrkgPath1Cmd*/
  {1u/*BitLength*/, 28u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DeletePath1Cmd*/
  {3u/*BitLength*/, 29u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 323u/* BufferStartIdx */, 324u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SelPrkgFctnCmd*/
  {1u/*BitLength*/, 19u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ParkMdlCmd*/
  {1u/*BitLength*/, 20u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BackReq_APS*/
  {2u/*BitLength*/, 46u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAEnaReq_TC*/
  {3u/*BitLength*/, 43u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGAChanTyp_TC*/
  {3u/*BitLength*/, 40u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 325u/* BufferStartIdx */, 326u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFGALvlReq_TC*/
  {1u/*BitLength*/, 16u/* BitPosition */, 26u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 322u/* BufferStartIdx */, 323u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*P2P_PrkgDirectSwtCmd*/
  {64u/*BitLength*/, 0u/* BitPosition */, 26u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 320u/* BufferStartIdx */, 328u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT33_0x1ED*/
  {1u/*BitLength*/, 16u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeMod*/
  {1u/*BitLength*/, 17u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TimeIndcn*/
  {5u/*BitLength*/, 11u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 329u/* BufferStartIdx */, 330u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Hour*/
  {6u/*BitLength*/, 18u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 330u/* BufferStartIdx */, 331u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Minutes*/
  {6u/*BitLength*/, 26u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 331u/* BufferStartIdx */, 332u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Second*/
  {4u/*BitLength*/, 36u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Left*/
  {4u/*BitLength*/, 32u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 332u/* BufferStartIdx */, 333u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Year_Right*/
  {4u/*BitLength*/, 44u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 333u/* BufferStartIdx */, 334u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Month*/
  {5u/*BitLength*/, 51u/* BitPosition */, 27u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 335u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*Time_Day*/
  {6u/*BitLength*/, 61u/* BitPosition */, 27u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 334u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_TgtSOCSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 27u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 328u/* BufferStartIdx */, 336u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT34_0x370*/
  {5u/*BitLength*/, 19u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempReq_ETC_VR*/
  {5u/*BitLength*/, 27u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempSteplsReq_ETC_TC*/
  {2u/*BitLength*/, 38u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACDrvTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 34u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempDecReq_ETC_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 340u/* BufferStartIdx */, 341u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearTempIncReq_ETC_TC*/
  {2u/*BitLength*/, 46u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearPowerReq_VR*/
  {2u/*BitLength*/, 25u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 339u/* BufferStartIdx */, 340u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_VR*/
  {2u/*BitLength*/, 17u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACMaxReq_TC*/
  {1u/*BitLength*/, 16u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 338u/* BufferStartIdx */, 339u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SrSpdCtrlSwt*/
  {2u/*BitLength*/, 62u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 343u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FrntWiprCtrl_VR*/
  {2u/*BitLength*/, 42u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 341u/* BufferStartIdx */, 342u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRearAutoModReq_VR*/
  {2u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FreightLmptSwt*/
  {1u/*BitLength*/, 56u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 343u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FreightLmpAutoSet*/
  {1u/*BitLength*/, 49u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 342u/* BufferStartIdx */, 343u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockWinSet*/
  {2u/*BitLength*/, 57u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 343u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DPF_Request*/
  {2u/*BitLength*/, 2u/* BitPosition */, 28u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 337u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ColorCategory*/
  {64u/*BitLength*/, 0u/* BitPosition */, 28u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 336u/* BufferStartIdx */, 344u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT35_0x1E5*/
  {7u/*BitLength*/, 1u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 345u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr1*/
  {7u/*BitLength*/, 9u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 345u/* BufferStartIdx */, 346u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr2*/
  {7u/*BitLength*/, 17u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 346u/* BufferStartIdx */, 347u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr3*/
  {7u/*BitLength*/, 25u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 347u/* BufferStartIdx */, 348u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr4*/
  {7u/*BitLength*/, 33u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 348u/* BufferStartIdx */, 349u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr5*/
  {7u/*BitLength*/, 41u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 349u/* BufferStartIdx */, 350u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr6*/
  {7u/*BitLength*/, 49u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 350u/* BufferStartIdx */, 351u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr7*/
  {7u/*BitLength*/, 57u/* BitPosition */, 29u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 351u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr8*/
  {64u/*BitLength*/, 0u/* BitPosition */, 29u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 344u/* BufferStartIdx */, 352u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT36_0x1E6*/
  {7u/*BitLength*/, 1u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 353u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr9*/
  {7u/*BitLength*/, 9u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 353u/* BufferStartIdx */, 354u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr10*/
  {7u/*BitLength*/, 17u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 354u/* BufferStartIdx */, 355u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr11*/
  {7u/*BitLength*/, 25u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 355u/* BufferStartIdx */, 356u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr12*/
  {7u/*BitLength*/, 33u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 356u/* BufferStartIdx */, 357u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr13*/
  {7u/*BitLength*/, 41u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 357u/* BufferStartIdx */, 358u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr14*/
  {7u/*BitLength*/, 49u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 358u/* BufferStartIdx */, 359u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr15*/
  {7u/*BitLength*/, 57u/* BitPosition */, 30u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 359u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*MultiColorNr16*/
  {64u/*BitLength*/, 0u/* BitPosition */, 30u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 352u/* BufferStartIdx */, 360u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT37_0x1EC*/
  {2u/*BitLength*/, 6u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempDecReq_TC*/
  {2u/*BitLength*/, 4u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempIncReq_TC*/
  {2u/*BitLength*/, 2u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempDecReq_TC*/
  {2u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 361u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempIncReq_TC*/
  {6u/*BitLength*/, 10u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 361u/* BufferStartIdx */, 362u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempReq_VR*/
  {2u/*BitLength*/, 8u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 361u/* BufferStartIdx */, 362u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRLTempSteplsReq_TC*/
  {6u/*BitLength*/, 18u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 362u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempReq_VR*/
  {2u/*BitLength*/, 16u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 362u/* BufferStartIdx */, 363u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACRRTempSteplsReq_TC*/
  {2u/*BitLength*/, 30u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_VR*/
  {2u/*BitLength*/, 28u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACHumidifierReq_TC*/
  {2u/*BitLength*/, 26u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_TC*/
  {2u/*BitLength*/, 24u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 363u/* BufferStartIdx */, 364u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACOzoneReq_VR*/
  {2u/*BitLength*/, 38u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_TC*/
  {2u/*BitLength*/, 36u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACUltravioletReq_VR*/
  {2u/*BitLength*/, 34u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_TC*/
  {2u/*BitLength*/, 32u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 364u/* BufferStartIdx */, 365u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ACFrntWinHeatCmd_VR*/
  {3u/*BitLength*/, 45u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 365u/* BufferStartIdx */, 366u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMFlashFreq*/
  {3u/*BitLength*/, 42u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 365u/* BufferStartIdx */, 366u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMFlashFreq*/
  {3u/*BitLength*/, 55u/* BitPosition */, 31u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 365u/* BufferStartIdx */, 367u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 52u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 366u/* BufferStartIdx */, 367u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMFlashFreq*/
  {3u/*BitLength*/, 61u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 367u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMFlashFreq*/
  {3u/*BitLength*/, 58u/* BitPosition */, 31u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 367u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMFlashFreq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 31u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 360u/* BufferStartIdx */, 368u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT38_0x1E7*/
  {1u/*BitLength*/, 7u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryLockSet*/
  {1u/*BitLength*/, 6u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ActvEntryUnlockSet*/
  {2u/*BitLength*/, 4u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LockPromptFunSet*/
  {1u/*BitLength*/, 3u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPAEntryLockSet*/
  {1u/*BitLength*/, 2u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*BTAPALvngUnlockSet*/
  {2u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 369u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ClsWinSpdSet*/
  {1u/*BitLength*/, 9u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OilBoxSplyReq*/
  {1u/*BitLength*/, 8u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 369u/* BufferStartIdx */, 370u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SeatKeyMemEna*/
  {3u/*BitLength*/, 21u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgLvlSet*/
  {3u/*BitLength*/, 18u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 370u/* BufferStartIdx */, 371u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgLvlSet*/
  {3u/*BitLength*/, 29u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgLvlSet*/
  {3u/*BitLength*/, 26u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 371u/* BufferStartIdx */, 372u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgLvlSet*/
  {7u/*BitLength*/, 40u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 373u/* BufferStartIdx */, 374u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMClrSet*/
  {7u/*BitLength*/, 49u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 374u/* BufferStartIdx */, 375u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMClrSet*/
  {7u/*BitLength*/, 57u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 375u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMClrSet*/
  {1u/*BitLength*/, 48u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 374u/* BufferStartIdx */, 375u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMSwt*/
  {1u/*BitLength*/, 56u/* BitPosition */, 32u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 375u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 32u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 368u/* BufferStartIdx */, 376u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT39_0x1EB*/
  {7u/*BitLength*/, 9u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 377u/* BufferStartIdx */, 378u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq0*/
  {7u/*BitLength*/, 18u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 377u/* BufferStartIdx */, 379u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq1*/
  {7u/*BitLength*/, 27u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 378u/* BufferStartIdx */, 380u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq2*/
  {7u/*BitLength*/, 36u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 379u/* BufferStartIdx */, 381u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq3*/
  {7u/*BitLength*/, 45u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 380u/* BufferStartIdx */, 382u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq4*/
  {7u/*BitLength*/, 54u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 381u/* BufferStartIdx */, 383u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq5*/
  {7u/*BitLength*/, 63u/* BitPosition */, 33u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 382u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MusicFrq6*/
  {1u/*BitLength*/, 62u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 383u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMPartitionSwt*/
  {1u/*BitLength*/, 61u/* BitPosition */, 33u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 383u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMMasterSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 33u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 376u/* BufferStartIdx */, 384u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT40_0x224*/
  {7u/*BitLength*/, 1u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 385u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMClrSet*/
  {1u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 385u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMFloSwt*/
  {7u/*BitLength*/, 9u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 385u/* BufferStartIdx */, 386u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMClrSet*/
  {1u/*BitLength*/, 8u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 385u/* BufferStartIdx */, 386u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ALCMBreSwt*/
  {7u/*BitLength*/, 17u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 386u/* BufferStartIdx */, 387u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMClrSet*/
  {4u/*BitLength*/, 36u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 388u/* BufferStartIdx */, 389u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 32u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 388u/* BufferStartIdx */, 389u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 44u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 389u/* BufferStartIdx */, 390u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 40u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 389u/* BufferStartIdx */, 390u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMLightLvlSet*/
  {4u/*BitLength*/, 52u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 390u/* BufferStartIdx */, 391u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMLightLvlSet*/
  {4u/*BitLength*/, 48u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 390u/* BufferStartIdx */, 391u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMLightLvlSet*/
  {1u/*BitLength*/, 16u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 386u/* BufferStartIdx */, 387u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LeftPanelALCMSwt*/
  {1u/*BitLength*/, 24u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 387u/* BufferStartIdx */, 388u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RightPanelALCMSwt*/
  {1u/*BitLength*/, 59u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*LRDoorALCMSwt*/
  {1u/*BitLength*/, 58u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRDoorALCMSwt*/
  {1u/*BitLength*/, 57u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*FootALCMSwt*/
  {1u/*BitLength*/, 56u/* BitPosition */, 34u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 391u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RoofALCMSwt*/
  {64u/*BitLength*/, 0u/* BitPosition */, 34u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 384u/* BufferStartIdx */, 392u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT41_0x1FB*/
  {4u/*BitLength*/, 20u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RLSeatMassgModSet*/
  {4u/*BitLength*/, 16u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 394u/* BufferStartIdx */, 395u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RRSeatMassgModSet*/
  {4u/*BitLength*/, 4u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatHeatgLvlSet_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 393u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatHeatgLvlSet_Nine*/
  {3u/*BitLength*/, 32u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 396u/* BufferStartIdx */, 397u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RWinSwtReq_TC*/
  {3u/*BitLength*/, 40u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 397u/* BufferStartIdx */, 398u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RWinSwtReq_VR*/
  {1u/*BitLength*/, 50u/* BitPosition */, 35u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 398u/* BufferStartIdx */, 399u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnEna_SecRow*/
  {64u/*BitLength*/, 0u/* BitPosition */, 35u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 392u/* BufferStartIdx */, 400u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT43_0x1FD*/
  {2u/*BitLength*/, 16u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 402u/* BufferStartIdx */, 403u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*RWPC_SwtReq*/
  {4u/*BitLength*/, 8u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 402u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatMassgModSet*/
  {4u/*BitLength*/, 12u/* BitPosition */, 36u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 401u/* BufferStartIdx */, 402u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatMassgModSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 36u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 400u/* BufferStartIdx */, 408u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT45_0x1DC*/
  {4u/*BitLength*/, 4u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 409u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*DrvSeatVentnLvlSet_Nine*/
  {4u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 409u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*PassSeatVentnLvlSet_Nine*/
  {2u/*BitLength*/, 22u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ARFSwtReq*/
  {2u/*BitLength*/, 20u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ASFCSwtReq*/
  {2u/*BitLength*/, 18u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*AGSSwtReq*/
  {2u/*BitLength*/, 16u/* BitPosition */, 37u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 410u/* BufferStartIdx */, 411u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SOCMngmntSwtReq*/
  {64u/*BitLength*/, 0u/* BitPosition */, 37u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 408u/* BufferStartIdx */, 416u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT46_0x1DD*/
  {2u/*BitLength*/, 60u/* BitPosition */, 38u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 423u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*WinShortUpShortDownSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 38u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 416u/* BufferStartIdx */, 424u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT48_0x1F4*/
  {1u/*BitLength*/, 64u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 432u/* BufferStartIdx */, 433u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SSSSet_HUT*/
  {2u/*BitLength*/, 76u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 433u/* BufferStartIdx */, 434u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IFC_SnvtySet*/
  {1u/*BitLength*/, 104u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DOWSwtReq*/
  {1u/*BitLength*/, 105u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_PedSwtReq*/
  {4u/*BitLength*/, 72u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 433u/* BufferStartIdx */, 434u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALCMLightLvlSet*/
  {1u/*BitLength*/, 86u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FlashLmpSwtReq*/
  {1u/*BitLength*/, 85u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCASwtReq*/
  {1u/*BitLength*/, 84u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTASwtReq*/
  {1u/*BitLength*/, 83u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCTABrkSwtReq*/
  {1u/*BitLength*/, 82u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RCWSwtReq*/
  {2u/*BitLength*/, 80u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCW_SnvtySet*/
  {1u/*BitLength*/, 95u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_VehSwtReq*/
  {1u/*BitLength*/, 93u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LKASwtReq*/
  {1u/*BitLength*/, 92u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LCKSwtReq*/
  {1u/*BitLength*/, 91u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ELKSwtReq*/
  {1u/*BitLength*/, 90u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_PedSwtReq*/
  {1u/*BitLength*/, 89u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ESS_VehSwtReq*/
  {1u/*BitLength*/, 88u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 435u/* BufferStartIdx */, 436u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LDWSwtReq*/
  {1u/*BitLength*/, 102u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 436u/* BufferStartIdx */, 437u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRSwtReq*/
  {1u/*BitLength*/, 101u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 436u/* BufferStartIdx */, 437u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSRWarnSwtReq*/
  {1u/*BitLength*/, 127u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 439u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ICA_HandsOffSwtReq*/
  {1u/*BitLength*/, 126u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 439u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ISLSwtReq*/
  {5u/*BitLength*/, 121u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 439u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TSR_SnvtySet*/
  {1u/*BitLength*/, 87u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 434u/* BufferStartIdx */, 435u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HFASwtSts*/
  {2u/*BitLength*/, 113u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 438u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*EPSSteerModSwtReq*/
  {1u/*BitLength*/, 115u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 438u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*OilLvlDispReq*/
  {1u/*BitLength*/, 112u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 438u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DSTSwtReq*/
  {2u/*BitLength*/, 99u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 436u/* BufferStartIdx */, 437u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSWarnFormSwtReq*/
  {1u/*BitLength*/, 98u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 436u/* BufferStartIdx */, 437u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_ESPFuncOffSwtSts*/
  {1u/*BitLength*/, 120u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 439u/* BufferStartIdx */, 440u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*DrvgModeMemReq*/
  {1u/*BitLength*/, 107u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IntelligentEvaSwtReq*/
  {1u/*BitLength*/, 106u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 437u/* BufferStartIdx */, 438u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*LSSSwtReq*/
  {12u/*BitLength*/, 148u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 441u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUTRadioFrq*/
  {4u/*BitLength*/, 156u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 443u/* BufferStartIdx */, 444u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*MediaPlaySrc*/
  {2u/*BitLength*/, 168u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_AudioSts*/
  {2u/*BitLength*/, 176u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*USB_VideoSts*/
  {2u/*BitLength*/, 178u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*BT_AudioSts*/
  {2u/*BitLength*/, 180u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IPod_Sts*/
  {2u/*BitLength*/, 182u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 446u/* BufferStartIdx */, 447u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AM_Sts*/
  {2u/*BitLength*/, 184u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FM_Sts*/
  {2u/*BitLength*/, 186u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*APPLink_Sts*/
  {2u/*BitLength*/, 188u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*QQMusic_Sts*/
  {2u/*BitLength*/, 190u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 447u/* BufferStartIdx */, 448u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*KaolaFM_Sts*/
  {2u/*BitLength*/, 144u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*OnlineNews_Sts*/
  {1u/*BitLength*/, 147u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 442u/* BufferStartIdx */, 443u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OffroadThmSts*/
  {3u/*BitLength*/, 173u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ECM*/
  {3u/*BitLength*/, 170u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 445u/* BufferStartIdx */, 446u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TCU*/
  {2u/*BitLength*/, 162u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 444u/* BufferStartIdx */, 445u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_TOD*/
  {2u/*BitLength*/, 243u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 454u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*ChairMemPosnSet*/
  {4u/*BitLength*/, 252u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 455u/* BufferStartIdx */, 456u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ChairMemPosnSetResult*/
  {1u/*BitLength*/, 224u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 452u/* BufferStartIdx */, 453u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TABSwtReq_HUT*/
  {10u/*BitLength*/, 246u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 453u/* BufferStartIdx */, 455u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavVehToTrafEyeDist*/
  {6u/*BitLength*/, 266u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimValue*/
  {2u/*BitLength*/, 264u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 457u/* BufferStartIdx */, 458u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimUnit_HUT*/
  {10u/*BitLength*/, 286u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 458u/* BufferStartIdx */, 460u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavCtryType*/
  {3u/*BitLength*/, 283u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 459u/* BufferStartIdx */, 460u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimSignSts*/
  {1u/*BitLength*/, 280u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 459u/* BufferStartIdx */, 460u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SwtReq*/
  {8u/*BitLength*/, 288u/* BitPosition */, 39u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 460u/* BufferStartIdx */, 461u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavTSRTrafSign*/
  {2u/*BitLength*/, 302u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_SnvtySet*/
  {1u/*BitLength*/, 301u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTASwtReq*/
  {1u/*BitLength*/, 300u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*FCTABrkSwtReq*/
  {1u/*BitLength*/, 299u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AEB_JASwtReq*/
  {1u/*BitLength*/, 298u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*AESSwtReq*/
  {1u/*BitLength*/, 297u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HWA_WarnFormSwtReq*/
  {1u/*BitLength*/, 296u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 461u/* BufferStartIdx */, 462u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ALC_SwtReq*/
  {4u/*BitLength*/, 308u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 462u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavRoadType*/
  {2u/*BitLength*/, 306u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 462u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*NavSpdLimType*/
  {1u/*BitLength*/, 305u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 462u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TrailerConnected*/
  {1u/*BitLength*/, 304u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 462u/* BufferStartIdx */, 463u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*TrailerConnectedVld*/
  {1u/*BitLength*/, 319u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 463u/* BufferStartIdx */, 464u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModSwtReq_HUT*/
  {2u/*BitLength*/, 317u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 463u/* BufferStartIdx */, 464u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ExpertModReq_HUT_ESP*/
  {1u/*BitLength*/, 316u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 463u/* BufferStartIdx */, 464u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SteerCorrnReq*/
  {3u/*BitLength*/, 325u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 464u/* BufferStartIdx */, 465u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_MsgTye*/
  {13u/*BitLength*/, 328u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 464u/* BufferStartIdx */, 466u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Offset*/
  {2u/*BitLength*/, 342u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 467u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CycCnt*/
  {6u/*BitLength*/, 336u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 466u/* BufferStartIdx */, 467u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Pathldx*/
  {2u/*BitLength*/, 350u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 467u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Idx*/
  {5u/*BitLength*/, 345u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 467u/* BufferStartIdx */, 468u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosProbb*/
  {9u/*BitLength*/, 352u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 467u/* BufferStartIdx */, 469u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Age*/
  {3u/*BitLength*/, 364u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_PosConfdc*/
  {3u/*BitLength*/, 361u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 470u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_CurLane*/
  {9u/*BitLength*/, 368u/* BitPosition */, 39u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 469u/* BufferStartIdx */, 471u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Spd*/
  {8u/*BitLength*/, 376u/* BitPosition */, 39u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 471u/* BufferStartIdx */, 472u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*ADAS_Posn_Rehead*/
  {1u/*BitLength*/, 70u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 432u/* BufferStartIdx */, 433u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*EngStrtDischrgn*/
  {2u/*BitLength*/, 118u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 438u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*HUT_HybModReq*/
  {2u/*BitLength*/, 116u/* BitPosition */, 39u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 438u/* BufferStartIdx */, 439u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_HybFctnReq*/
  {448u/*BitLength*/, 0u/* BitPosition */, 39u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 56u/* BusAccBtyeLength */, 424u/* BufferStartIdx */, 480u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD1_0x2C3*/
  {4u/*BitLength*/, 12u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 483u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 481u/* BufferStartIdx */, 482u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 482u/* BufferStartIdx */, 484u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 484u/* BufferStartIdx */, 486u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 485u/* BufferStartIdx */, 487u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj0_Ground_Pos_Y*/
  {4u/*BitLength*/, 76u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_ID*/
  {3u/*BitLength*/, 85u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 491u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_type*/
  {4u/*BitLength*/, 72u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 489u/* BufferStartIdx */, 490u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Confidence*/
  {7u/*BitLength*/, 94u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 490u/* BufferStartIdx */, 492u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_width*/
  {12u/*BitLength*/, 108u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 492u/* BufferStartIdx */, 494u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_X*/
  {12u/*BitLength*/, 112u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 493u/* BufferStartIdx */, 495u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj1_Ground_Pos_Y*/
  {4u/*BitLength*/, 140u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_ID*/
  {3u/*BitLength*/, 149u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 499u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_type*/
  {4u/*BitLength*/, 136u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 497u/* BufferStartIdx */, 498u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Confidence*/
  {7u/*BitLength*/, 158u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 498u/* BufferStartIdx */, 500u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_width*/
  {12u/*BitLength*/, 172u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 500u/* BufferStartIdx */, 502u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_X*/
  {12u/*BitLength*/, 176u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 501u/* BufferStartIdx */, 503u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj2_Ground_Pos_Y*/
  {4u/*BitLength*/, 204u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_ID*/
  {3u/*BitLength*/, 213u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 507u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_type*/
  {4u/*BitLength*/, 200u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 505u/* BufferStartIdx */, 506u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Confidence*/
  {7u/*BitLength*/, 222u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 506u/* BufferStartIdx */, 508u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_width*/
  {12u/*BitLength*/, 236u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 508u/* BufferStartIdx */, 510u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_X*/
  {12u/*BitLength*/, 240u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 509u/* BufferStartIdx */, 511u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj3_Ground_Pos_Y*/
  {4u/*BitLength*/, 268u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_ID*/
  {3u/*BitLength*/, 277u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 515u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_type*/
  {4u/*BitLength*/, 264u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 513u/* BufferStartIdx */, 514u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Confidence*/
  {7u/*BitLength*/, 286u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 514u/* BufferStartIdx */, 516u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_width*/
  {12u/*BitLength*/, 300u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 516u/* BufferStartIdx */, 518u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_X*/
  {12u/*BitLength*/, 304u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 517u/* BufferStartIdx */, 519u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj4_Ground_Pos_Y*/
  {4u/*BitLength*/, 332u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 522u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_ID*/
  {3u/*BitLength*/, 341u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 522u/* BufferStartIdx */, 523u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_type*/
  {4u/*BitLength*/, 328u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 521u/* BufferStartIdx */, 522u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Confidence*/
  {7u/*BitLength*/, 350u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 522u/* BufferStartIdx */, 524u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_width*/
  {12u/*BitLength*/, 364u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 524u/* BufferStartIdx */, 526u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_X*/
  {12u/*BitLength*/, 368u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 525u/* BufferStartIdx */, 527u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj5_Ground_Pos_Y*/
  {4u/*BitLength*/, 396u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_ID*/
  {3u/*BitLength*/, 405u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 531u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_type*/
  {4u/*BitLength*/, 392u/* BitPosition */, 40u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 529u/* BufferStartIdx */, 530u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Confidence*/
  {7u/*BitLength*/, 414u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 530u/* BufferStartIdx */, 532u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_width*/
  {12u/*BitLength*/, 428u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 532u/* BufferStartIdx */, 534u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_X*/
  {12u/*BitLength*/, 432u/* BitPosition */, 40u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 533u/* BufferStartIdx */, 535u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj6_Ground_Pos_Y*/
  {512u/*BitLength*/, 0u/* BitPosition */, 40u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 480u/* BufferStartIdx */, 544u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD2_0x203*/
  {4u/*BitLength*/, 12u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 545u/* BufferStartIdx */, 546u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_ID*/
  {3u/*BitLength*/, 21u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 546u/* BufferStartIdx */, 547u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_type*/
  {4u/*BitLength*/, 8u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 545u/* BufferStartIdx */, 546u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Confidence*/
  {7u/*BitLength*/, 30u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 546u/* BufferStartIdx */, 548u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_width*/
  {12u/*BitLength*/, 44u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 548u/* BufferStartIdx */, 550u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_X*/
  {12u/*BitLength*/, 48u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 549u/* BufferStartIdx */, 551u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj7_Ground_Pos_Y*/
  {2u/*BitLength*/, 112u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 558u/* BufferStartIdx */, 559u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_WorkSts*/
  {16u/*BitLength*/, 80u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 553u/* BufferStartIdx */, 555u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_OD_Obj_Timestamp*/
  {6u/*BitLength*/, 90u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 555u/* BufferStartIdx */, 556u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD1_distance*/
  {6u/*BitLength*/, 100u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 555u/* BufferStartIdx */, 557u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD2_distance*/
  {6u/*BitLength*/, 110u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 556u/* BufferStartIdx */, 558u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD3_distance*/
  {6u/*BitLength*/, 104u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 557u/* BufferStartIdx */, 558u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD4_distance*/
  {6u/*BitLength*/, 114u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 558u/* BufferStartIdx */, 559u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD5_distance*/
  {6u/*BitLength*/, 138u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 561u/* BufferStartIdx */, 562u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD6_distance*/
  {6u/*BitLength*/, 148u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 561u/* BufferStartIdx */, 563u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD7_distance*/
  {6u/*BitLength*/, 158u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 562u/* BufferStartIdx */, 564u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD8_distance*/
  {6u/*BitLength*/, 152u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 563u/* BufferStartIdx */, 564u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD9_distance*/
  {6u/*BitLength*/, 162u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 564u/* BufferStartIdx */, 565u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD10_distance*/
  {6u/*BitLength*/, 172u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 564u/* BufferStartIdx */, 566u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD11_distance*/
  {6u/*BitLength*/, 182u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 565u/* BufferStartIdx */, 567u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD12_distance*/
  {6u/*BitLength*/, 176u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 566u/* BufferStartIdx */, 567u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD13_distance*/
  {6u/*BitLength*/, 202u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 570u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD14_distance*/
  {6u/*BitLength*/, 212u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 569u/* BufferStartIdx */, 571u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD15_distance*/
  {6u/*BitLength*/, 222u/* BitPosition */, 41u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 570u/* BufferStartIdx */, 572u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD16_distance*/
  {6u/*BitLength*/, 216u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 571u/* BufferStartIdx */, 572u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD17_distance*/
  {6u/*BitLength*/, 226u/* BitPosition */, 41u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 572u/* BufferStartIdx */, 573u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FSD18_distance*/
  {512u/*BitLength*/, 0u/* BitPosition */, 41u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 544u/* BufferStartIdx */, 608u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD3_0x243*/
  {1u/*BitLength*/, 44u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 613u/* BufferStartIdx */, 614u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefinedParkCmd*/
  {3u/*BitLength*/, 16u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 610u/* BufferStartIdx */, 611u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*UserDefPrkMenuSelCmd*/
  {4u/*BitLength*/, 32u/* BitPosition */, 42u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 612u/* BufferStartIdx */, 613u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, CNA_SignalCallBack/* TxAckFuncPtr */}, /*SlotNum_VR*/
  {512u/*BitLength*/, 0u/* BitPosition */, 42u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 64u/* BusAccBtyeLength */, 608u/* BufferStartIdx */, 672u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*HUT_FD4_0x1DA*/
  {8u/*BitLength*/, 0u/* BitPosition */, 43u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 672u/* BufferStartIdx */, 673u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequestMessageId*/
  {56u/*BitLength*/, 56u/* BitPosition */, 43u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 7u/* BusAccBtyeLength */, 673u/* BufferStartIdx */, 680u/* BufferEndIdx */, COMEX_TxSIGNAL_EVENTTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*SyncRequstReseverData*/
  {3u/*BitLength*/, 18u/* BitPosition */, 44u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 690u/* BufferStartIdx */, 691u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_CurrTheme*/
  {9u/*BitLength*/, 23u/* BitPosition */, 44u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 689u/* BufferStartIdx */, 691u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdDisp*/
  {8u/*BitLength*/, 60u/* BitPosition */, 44u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 694u/* BufferStartIdx */, 696u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VelSpdDisp_Mile*/
  {10u/*BitLength*/, 24u/* BitPosition */, 44u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 690u/* BufferStartIdx */, 692u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelMainTankR*/
  {10u/*BitLength*/, 46u/* BitPosition */, 44u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 692u/* BufferStartIdx */, 694u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxTankR*/
  {4u/*BitLength*/, 42u/* BitPosition */, 44u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 693u/* BufferStartIdx */, 694u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_LagueSet*/
  {64u/*BitLength*/, 0u/* BitPosition */, 44u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 688u/* BufferStartIdx */, 696u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP1_0x293*/
  {8u/*BitLength*/, 0u/* BitPosition */, 45u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 696u/* BufferStartIdx */, 697u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*CheckSum_IP2*/
  {2u/*BitLength*/, 50u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 702u/* BufferStartIdx */, 703u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_DrvSeatBeltWarnLmpFailSts*/
  {2u/*BitLength*/, 48u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 702u/* BufferStartIdx */, 703u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_PassSeatBeltWarnLmpFailSts*/
  {24u/*BitLength*/, 24u/* BitPosition */, 45u/* pduIdx */, COMEX_NBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 3u/* BusAccBtyeLength */, 697u/* BufferStartIdx */, 700u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistance*/
  {1u/*BitLength*/, 46u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 701u/* BufferStartIdx */, 702u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehTotDistanceValid*/
  {8u/*BitLength*/, 32u/* BitPosition */, 45u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 700u/* BufferStartIdx */, 701u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlInfo*/
  {2u/*BitLength*/, 44u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 701u/* BufferStartIdx */, 702u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelLvlLowLmpSts*/
  {2u/*BitLength*/, 42u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 701u/* BufferStartIdx */, 702u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_BattChrgLmpSts*/
  {2u/*BitLength*/, 40u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 701u/* BufferStartIdx */, 702u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EngOilPressLowLmpSts*/
  {2u/*BitLength*/, 54u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 702u/* BufferStartIdx */, 703u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ABMWarnLmpFailrSts*/
  {1u/*BitLength*/, 52u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 702u/* BufferStartIdx */, 703u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_Err*/
  {1u/*BitLength*/, 47u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 701u/* BufferStartIdx */, 702u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_ACCErr*/
  {1u/*BitLength*/, 53u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 702u/* BufferStartIdx */, 703u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VehSpdUnit*/
  {1u/*BitLength*/, 63u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 703u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_VINcompr*/
  {4u/*BitLength*/, 56u/* BitPosition */, 45u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 703u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*RollingCounter_IP2*/
  {64u/*BitLength*/, 0u/* BitPosition */, 45u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 696u/* BufferStartIdx */, 704u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP2_0x27F*/
  {12u/*BitLength*/, 20u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 705u/* BufferStartIdx */, 707u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_RemainDistance*/
  {1u/*BitLength*/, 19u/* BitPosition */, 46u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 706u/* BufferStartIdx */, 707u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelConsUnit*/
  {1u/*BitLength*/, 18u/* BitPosition */, 46u/* pduIdx */, COMEX_NBIT_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 706u/* BufferStartIdx */, 707u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_EBDFailSts*/
  {12u/*BitLength*/, 36u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 707u/* BufferStartIdx */, 709u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AvgFuelCons*/
  {14u/*BitLength*/, 54u/* BitPosition */, 46u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 708u/* BufferStartIdx */, 711u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_InstFuelCons*/
  {128u/*BitLength*/, 0u/* BitPosition */, 46u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 16u/* BusAccBtyeLength */, 704u/* BufferStartIdx */, 720u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP3_0x34A*/
  {12u/*BitLength*/, 44u/* BitPosition */, 47u/* pduIdx */, COMEX_NBITNBYTE_SW_BUSACCOFTXSIGINFO/* BusAccType */, 2u/* BusAccBtyeLength */, 724u/* BufferStartIdx */, 726u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_AuxRemainDistance*/
  {64u/*BitLength*/, 0u/* BitPosition */, 47u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 720u/* BufferStartIdx */, 728u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP4_0x34B*/
  {8u/*BitLength*/, 8u/* BitPosition */, 48u/* pduIdx */, COMEX_BYTE_BUSACCOFTXSIGINFO/* BusAccType */, 1u/* BusAccBtyeLength */, 729u/* BufferStartIdx */, 730u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP_FuelAuxLvlInfo*/
  {64u/*BitLength*/, 0u/* BitPosition */, 48u/* pduIdx */, COMEX_NBYTE_BUSACCOFTXSIGINFO/* BusAccType */, 8u/* BusAccBtyeLength */, 728u/* BufferStartIdx */, 736u/* BufferEndIdx */, COMEX_TxSIGNAL_CYCLICTYPE/* SendType */, NULL_PTR/* TxAckFuncPtr */}, /*IP7_0x223*/
};

const ComEx_TxPduInfoType ComEx_TxPduInfo[ComEx_TxPduSize] = 
{
  {65535u/* SignalStartIdx */, 65535u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 0u/* BufferPosition */, 8u/* BufferLength */, 0/* CalloutStartIdx */, 1u/* CalloutNum */}, /*ComIPdu_userData*/
  {0u/* SignalStartIdx */, 31u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 8u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DMS_FD1*/
  {31u/* SignalStartIdx */, 37u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 72u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*DVR_FD1*/
  {37u/* SignalStartIdx */, 66u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 136u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT1*/
  {66u/* SignalStartIdx */, 82u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 144u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT2*/
  {82u/* SignalStartIdx */, 96u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 152u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT3*/
  {96u/* SignalStartIdx */, 121u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 160u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT4*/
  {121u/* SignalStartIdx */, 139u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 168u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT6*/
  {139u/* SignalStartIdx */, 149u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 176u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT7*/
  {149u/* SignalStartIdx */, 163u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 184u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT10*/
  {163u/* SignalStartIdx */, 167u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 192u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT12*/
  {167u/* SignalStartIdx */, 175u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 200u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT13*/
  {175u/* SignalStartIdx */, 195u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 208u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT15*/
  {195u/* SignalStartIdx */, 201u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 216u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT16*/
  {201u/* SignalStartIdx */, 217u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 224u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT17*/
  {217u/* SignalStartIdx */, 231u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 232u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT19*/
  {231u/* SignalStartIdx */, 241u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 240u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT20*/
  {241u/* SignalStartIdx */, 254u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 248u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT21*/
  {254u/* SignalStartIdx */, 274u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 256u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT22*/
  {274u/* SignalStartIdx */, 292u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 264u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT23*/
  {292u/* SignalStartIdx */, 296u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 272u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT25*/
  {296u/* SignalStartIdx */, 299u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 280u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT26*/
  {299u/* SignalStartIdx */, 301u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 288u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT27*/
  {301u/* SignalStartIdx */, 306u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 296u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT30*/
  {306u/* SignalStartIdx */, 308u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 304u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT31*/
  {308u/* SignalStartIdx */, 329u/* SignalEndIdx */, 0u/* GroupStartIdx */, 1u/* GroupEndIdx */, 312u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT32*/
  {329u/* SignalStartIdx */, 358u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 320u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT33*/
  {358u/* SignalStartIdx */, 369u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 328u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT34*/
  {369u/* SignalStartIdx */, 387u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 336u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT35*/
  {387u/* SignalStartIdx */, 396u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 344u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT36*/
  {396u/* SignalStartIdx */, 405u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 352u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT37*/
  {405u/* SignalStartIdx */, 428u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 360u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT38*/
  {428u/* SignalStartIdx */, 446u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 368u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT39*/
  {446u/* SignalStartIdx */, 456u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 376u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT40*/
  {456u/* SignalStartIdx */, 474u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 384u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT41*/
  {474u/* SignalStartIdx */, 482u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 392u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT43*/
  {482u/* SignalStartIdx */, 486u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 400u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT45*/
  {486u/* SignalStartIdx */, 493u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 408u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT46*/
  {493u/* SignalStartIdx */, 495u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 416u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT48*/
  {495u/* SignalStartIdx */, 582u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 424u/* BufferPosition */, 56u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD1*/
  {582u/* SignalStartIdx */, 625u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 480u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD2*/
  {625u/* SignalStartIdx */, 652u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 544u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD3*/
  {652u/* SignalStartIdx */, 656u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 608u/* BufferPosition */, 64u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_FD4*/
  {656u/* SignalStartIdx */, 658u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 672u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*HUT_Sync_Req*/
  {658u/* SignalStartIdx */, 665u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 688u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP1*/
  {665u/* SignalStartIdx */, 681u/* SignalEndIdx */, 1u/* GroupStartIdx */, 2u/* GroupEndIdx */, 696u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP2*/
  {681u/* SignalStartIdx */, 687u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 704u/* BufferPosition */, 16u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP3*/
  {687u/* SignalStartIdx */, 689u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 720u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP4*/
  {689u/* SignalStartIdx */, 691u/* SignalEndIdx */, 65535u/* GroupStartIdx */, 65535u/* GroupEndIdx */, 728u/* BufferPosition */, 8u/* BufferLength */, 1/* CalloutStartIdx */, 1u/* CalloutNum */}, /*IP7*/
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
  0x0u,
  0x0u,
  0x0u,
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
  0x1u,
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
  0x4u,
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
  0x10u,
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
  0x1u,
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
  {25u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 0u/* E2eIdx */}, /*HUT32*/
  {45u/* PduIdx */, 8u/* ByteLength */, 0u/* BytePosition */, 1u/* E2eIdx */}, /*IP2*/
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
