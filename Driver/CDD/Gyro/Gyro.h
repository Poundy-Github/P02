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
 * @file:      Gyro.h
 * @author:    Nobo
 * @date:      2020-5-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _GYRO_H_
#define _GYRO_H_
/*INCLUDE FILE*/
#include "Gyro_asm330.h"
#include "IPC_Sensor.h"

//#define GYRO_TEST
/*GRYO TEST*/
#ifdef GYRO_TEST
#include "logger.h"
#define GYRO_DEBUG(...)              gyro_info(__VA_ARGS__)
#define GYRO_ERROR(...)              gyro_info(__VA_ARGS__);gyro_err("LINE:%d; FUNCTION:%s;\n",__LINE__,(uint8_t*)__FUNCTION__)
#define GYRO_ACCERT(expr)            do{(expr)?(void)0 : (void)gyro_err("LINE:%d; FUNCTION:%s;\n",__LINE__,(uint8_t*)__FUNCTION__);}while(0)
#else
#define GYRO_DEBUG(...)
#define GYRO_ERROR(...)
#define GYRO_ACCERT(expr)
#endif


/*GYRO STATUS TYPES*/
typedef uint8         Gyro_Error_t;

#define GYRO_IIC_ERROR_TYPE                 (0x00U)
#define GYRO_IPC_ERROR_TYPE                 (0x01U)
 
typedef uint8 GYRO_Return_t; 
#define GYRO_Return_Success                 (0x00U)
#define GYRO_Return_Fail                    (0x01U)

/*GYRO STATE*/
#define GYRO_STATE_OFF                      (0x00U)
#define GYRO_STATE_RESET                    (0x01U)
#define GYRO_STATE_NORMAL                   (0x02U)
#define GYRO_STATE_CORRECT                  (0x03U)
#define GYRO_STATE_CALIBRATE                (0x04U)
#define GYRO_STATE_ERROR                    (0x05U)
#define GYRO_STATE_INVALID                  (0x06U)

#define GYRO_STATE_NUM                      (0x06U)

#define GYRO_HANDLE_ERROR                   (0xFF)

/*GYRO RESET HANDLE*/
#define GYRO_RESET_HANDLE_READ_NVM          (0x00U)
#define GYRO_RESET_HANDLE_CONFIG            (0x01U)
#define GYRO_RESET_HANDLE_WAIT              (0x02U)
#define GYRO_RESET_HANDLE_PENGDING          (0x03U)
   
/*GYRO NORMAL HANDLE*/  
#define GYRO_NORMAL_HANDLE_READ_DATA        (0x00U)
#define GYRO_NORMAL_HANDLE_TRANSMIT         (0x01U)
#define GYRO_NORMAL_HANDLE_PENDING          (0x02U)
 
/*GYRO CORRECT HANDLE*/ 
#define GYRO_CORRECT_HANDLE_READ_DATA       (0x00U)
#define GYRO_CORRECT_HANDLE_CALCULATE       (0x01U)
#define GYRO_CORRECT_HANDLE_COMPLETE        (0x02U)
#define GYRO_CORRECT_HANDLE_PENDING         (0x03U)
 
#define GYRO_CORRECT_SAMPLE_NUM             (0x05U)

#define GYRO_IPC_TRANSMIT_LENGTH            (0x0FU)

/*GYRO SENSOR*/
#define GYRO_ACC_SENSOR                     (0x00u)
#define GYRO_GYRO_SENSOR                    (0x01u)
/*GYRO IPC TYPE MASK*/
#define GYRO_IPC_ACTIVATE_MASK              (0x01u)
#define GYRO_IPC_BATCH_MASK                 (0x02u)
/*GYRO IPC Handle*/
#define GYRO_IPC_ACC_HANDLE                 (0x02u)
#define GYRO_IPC_GYRO_HANDLE                (0x00u)
/* Sensor Reply */
#define GYRO_IPC_REPLY_OK                   (0x00u)
#define GYRO_IPC_REPLY_NOK                  (0x01u)


/*EXTERN TYPE*/
typedef Asm330_Config_t                     Gyro_DrvConfig_t;
typedef Asm330_Data_t                       Gyro_SensorData_t;                   
typedef Asm330_ReadData_t                   Gyro_ReadData_t;                     
typedef Asm330_Return_t                     Gyro_DrvReturn_t;                    

#define GYRO_DRV_RETURN_SUCCESS             ASM330_RETURN_SUCCESS               
#define GYRO_DRV_RETURN_FAIL                ASM330_RETURN_FAIL   

#define GYRO_NO_INDICATION                  ASM330_NO_INDICATION
#define GYRO_READ_SUCCESS_IND               ASM330_READ_SUCCESS_IND
#define GYRO_RESET_SUCCESS_IND              ASM330_RESET_SUCCESS_IND

#define GYRO_INVALID_DATA_TYPE              ASM330_INVALID_DATA_TYPE            
#define GYRO_ACC_DATA_TYPE                  ASM330_ACC_DATA_TYPE                
#define GYRO_GYRO_DATA_TYPE                 ASM330_GYRO_DATA_TYPE               
#define GYRO_TEMP_DATA_TYPE                 ASM330_TEMP_DATA_TYPE               
#define GYRO_TIMESTAMP_DATA_TYPE            ASM330_TIMESTAMP_DATA_TYPE         
    
/*EXTERN INTERFACE*/
#define Gyro_DriInit                        Asm330_Init
#define Gyro_DrvResetReq                    Asm330_ResetReq
#define Gyro_DrvReadReq                     Asm330_ReadReq
#define Gyro_DriverTask                     Asm330_ManageTask
#define Gyro_GetSensitivity                 Asm330_GetSensitivity
#define Gyro_GetDrvDeviceId                 Asm330_GetDeviceId

/*OS INTERFACE*/
#define Gyro_ENTER_CRITICAL()           
#define Gyro_EXIT_CRITICAL()            



/*OS INTERFACE*/
#include "Os.h"
#define RI_GYRO_TraceMainFunction()        SetEvent(DRIVERS_SAFE,Rte_Ev_Run_Gyro_Gyro_MainFunction)

/*GYRO SENSOR*/
#define GYRO_SENSOR_NUM                     (0x02U)

#define GYRO_SENSOR_TABLE   \
{\
    /*type                   active  timer  period  ready  timestamp  dataptr               offsetptr               calcdataptr        */\
    {ASM330_ACC_DATA_TYPE,   0U,     0U,    0U,     0U,    0U,        &gyroData.read.acc ,  &gyroData.offset.acc,   &gyroData.calc.acc },\
    {ASM330_GYRO_DATA_TYPE,  0U,     0U,    0U,     0U,    0U,        &gyroData.read.gyro , &gyroData.offset.gyro,  &gyroData.calc.gyro},\
}\
/*IPC Receive*/
#define GYRO_RECEIVE_NUM                     (0x02U)
#define GYRO_RECEIVE_TABLE   \
{\
    /* major id                      sub id                                 callbacak*/\
    {IPC_S2M_SENSOR_MSGMAJOR_IPC_ID, IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_ID, Gyro_IPCCallbackFromActivate,},\
    {IPC_S2M_SENSOR_MSGMAJOR_IPC_ID, IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_ID,    Gyro_IPCCallbackFromBatch,},\
}




/*GYRO ERROR STRUCT*/
typedef struct Gyro_ErrorInfo_t
{
    Gyro_Error_t i2c;
    Gyro_Error_t ipc;
}Gyro_ErrorInfo_t;

 /*GYRO STATE STRUCT*/
 typedef struct Gyro_State_t
 {
    uint8 cnt;
    boolean busy;
    uint8 handle;
 }Gyro_State_t;
 
/*GYRO INFO STRUCT*/
typedef struct Gyro_Info_t
{
    uint8 ind;
    uint8 state;
    uint8 error;
    uint8 statereq;
}Gyro_Info_t;
 
/*GYRO CONFIG STRUCT*/
typedef struct Gyro_SensorCalcData_t
{
    float x;
    float y;
    float z;
}Gyro_SensorCalcData_t;

typedef struct Gyro_CalcData_t
{
    Gyro_SensorCalcData_t acc;
    Gyro_SensorCalcData_t gyro;
}Gyro_CalcData_t;

typedef struct Gyro_OffsetData_t
{
    Gyro_SensorData_t acc;
    Gyro_SensorData_t gyro;
}Gyro_OffsetData_t;

/*GYRO SENSOR STRUCT*/
typedef struct GYRO_SENSOR_t
{
    uint8 type;
    uint8 active;
    uint8 timer;
    uint8 period;
    boolean ready;
    uint8 timestap;
    Gyro_SensorData_t* pdata;
    Gyro_SensorData_t* poffset;
    Gyro_SensorCalcData_t* pclacdata;
}GYRO_SENSOR_t;


/*GYRO DATA STRUCT*/
typedef struct GYRO_DATA_t
{
    Gyro_ReadData_t read;
    Gyro_CalcData_t calc;
    Gyro_OffsetData_t offset;
    uint8 ipc[GYRO_IPC_TRANSMIT_LENGTH];
    Gyro_ReadData_t correct[GYRO_CORRECT_SAMPLE_NUM];
}GYRO_DATA_t;

/*GYRO IPC Receive Config STRUCT*/
typedef struct GYRO_IPC_ReceiveConfig_t
{
    uint8 major_msg_id;
    uint8 sub_msg_id; 
    void (*callback)(uint8* param, uint16 param_len);
}GYRO_IPC_ReceiveConfig_t;


typedef struct GYRO_IPC_RequsetHandle_t
{
    union{
        IPC_S2M_SensorIPCActivate_t Activate;
        IPC_S2M_SensorIPCBatch_t    Batch;
    } data;
    uint8 u8ReqType;
}GYRO_IPC_RequsetHandle_t;



/*GYRO EXTERN FUNCTION*/
extern void Gyro_Init(void);
extern void Gyro_SendMessage(void);
extern void Gyro_MainFunction(void);
extern void Gyro_TriggerError(uint8 type);
extern void Gyro_SetIndication(uint8 ind);
extern void Gyro_IPCCallbackM(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len);


#endif /* ifndef _GYRO_H_.2020-5-6 14:46:17 GW00191223 */
