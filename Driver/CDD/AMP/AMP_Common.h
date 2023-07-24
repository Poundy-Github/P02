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
 * @file:      AMP_Common.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _AMP_COMMON_H
#define _AMP_COMMON_H



#include "Std_Types.h"
#include "Cdd_Common.h"
#include "IIC_cfg.h"
#include "IIC.h"
#include "AMP_Cfg.h"
#include "Dio.h"



#define AMP_TMMAX                                   (0xFFFFFFFF)
#define AMP_TXLENGTH_MAX                            (50u)


#define AMP_IICIDLE                                 (0u)
#define AMP_IICWORK                                 (1u)


#define AMP_NO_REQUEST                              (0xFF)
#define AMP_RX_TX_LENGTH                            (5u)
#define I2C_Req_Fail_Counter                        (4u)

#define LOGTIMERINIT                                (0u)
#define LOGTIMERRUN                                 (1u)
#define LOGTIMERTIMEOUT                             (2u)

#define TIMER_AMP1                                  (0u)
#define TIMER_AMP2                                  (1u)
#define TIMER_AMP1DIAG1                             (2u)
#define TIMER_AMP1DIAG2                             (3u)
#define TIMER_AMP1DIAG3                             (4u)
#define TIMER_AMP2DIAG1                             (5u)
#define TIMER_AMP2DIAG2                             (6u)
#define TIMER_AMP2DIAG3                             (7u)
#define TIMER_NUM                                   (8u)

#define   HEX_TO_STR(a)   (((a) > 9) ? ((a) - 0xA + 'A') : ((a) - 0 + '0'))


typedef struct
{
    uint32 TMStart;
    uint32 TMEnd;
    uint8  TX_Sts;
    uint8  TX_RetryCunt;
    uint8  Cmd_Data[AMP_TXLENGTH_MAX];
}s_AMP_TX_Data_Type;


typedef struct
{
    uint8 DeviceState;
    uint8 NextState;
    uint8 Major_State;
    uint8 Sub_State;
}s_AMP_State_Type;

typedef Std_ReturnType (*IICCallback)(uint8 dev_id);

#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];

extern void AMP_TimerStart(const uint8 timer_id);
extern void AMP_TimerEnd(const uint8 timer_id);
extern boolean AMP_TimerIsStarted(const uint8 timer_id);
extern boolean AMP_TimerIsElasped(const uint8 timer_id,const uint32 TimerMax);

extern void AMPSet_I2C_Req_Data(uint8 dev_id,uint8 *ptr, uint8 Length);
extern void AMPSet_I2C_Req_DataSts(uint8 dev_id,I2C_Req_Sts_t Sts);
extern I2C_Req_Sts_t AMPGet_I2C_Req_DataSts(uint8 dev_id);
extern void AMPSetRead_I2C_Req_Data(uint8 dev_id,uint8 *ptr, uint8 Length);
extern void AMP1_I2CTx_Callback(IIC_ResultStatus_t state);
extern void AMP1_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 *p_data, uint16 size);
extern void AMP2_I2CTx_Callback(IIC_ResultStatus_t state);
extern void AMP2_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 *p_data, uint16 size);
extern void AMP8532_Set_Pin(uint8 dev_id,AMP_8532_PIN_ID_t pin_id,Dio_LevelType pin_sts);
extern Dio_LevelType AMP8532_Get_Pin(uint8 dev_id, AMP_8532_PIN_ID_t pin_id);
extern void AMP_HWMuteOperate(uint8 dev_id,uint8 MuteType);
extern void AMP_StateIICCallback(void *State,uint8 dev_id,uint8 nextstate,uint8 errstate,IICCallback ptr);
extern void AMP_CommonInit(uint8 dev_id);
extern void AMPSet_NextDeviceState(uint8 dev_id,uint8 State);
extern void AMPArrayPrint(uint8* Array, uint8 Length);
extern void AMP_I2C_Req_State_Oper(uint8 dev_id, uint8 IICFlg);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"


#endif

