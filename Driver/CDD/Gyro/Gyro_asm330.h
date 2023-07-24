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
 * @file:      Gyro_asm330.h
 * @author:    Nobo
 * @date:      2020-5-7
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-7
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _GYRO_ASM330_H_
#define _GYRO_ASM330_H_

/*INCLUDE FILE*/
#include "IIC_Type.h"
#include "Gyro_asm330reg.h"

//#define ASM330_TEST

/*ASM330 TYPE*/
typedef uint8 Asm330_Addr_t;
typedef uint8 Asm330_Reg_t;    

typedef uint8 Asm330_Return_t; 
#define ASM330_RETURN_SUCCESS               (0x00U)
#define ASM330_RETURN_FAIL                  (0x01U)


/*ASM330 OPTION MODE*/
#define ASM330_INIT_HANDLE                  (0x00U)
#define ASM330_IDLE_HANDLE                  (0x01U)                     
#define ASM330_RESET_HANDLE                 (0x02U)
#define ASM330_READ_HANDLE                  (0x03U)

#define ASM330_NO_INDICATION                (0x00U)
#define ASM330_READ_SUCCESS_IND             (0x01U)
#define ASM330_RESET_SUCCESS_IND            (0x02U)

#define ASM330_INVALID_DEVICE_ID            (0xFFU)
 
/*ASM330  EVENT*/
#define ASM330_NO_EVENT                     (0x00U)
#define ASM330_READ_REQ                     (0x01U)
#define ASM330_RESET_REQ                    (0x02U)
#define ASM330_READ_SUCCESS                 (0x04U)
#define ASM330_WRITE_SUCCESS                (0x08U)
#define ASM330_READ_WRITE_RETRY             (0x10U)
#define ASM330_READ_WRITE_SUCCESS      (ASM330_WRITE_SUCCESS | ASM330_READ_SUCCESS)
#define ASM330_RESET_EVENT             (ASM330_WRITE_SUCCESS | ASM330_READ_SUCCESS | ASM330_RESET_REQ | ASM330_READ_WRITE_RETRY)
#define ASM330_READ_EVENT              (ASM330_READ_SUCCESS | ASM330_READ_REQ | ASM330_READ_WRITE_RETRY) 
#define ASM330_INIT_EVENT                   (0x20U)
/*ASM330 DATA LENGTH*/
#define ASM330_ADDR_SIZE                    (0x01U)

#define ASM330_SENSOR_DATA_TAG_LENGTH       (0x01U)
#define ASM330_SENSOR_DATA_LENGTH           (0x06U)
#define ASM330_READ_DATA_LENGTH             (ASM330_SENSOR_DATA_LENGTH+ASM330_SENSOR_DATA_TAG_LENGTH)

#define ASM330_I2C_CMD_LENGTH               (0x0AU)
    
#define ASM330_ACC_DATA_LENGTH              (0x06U)
#define ASM330_GYRO_DATA_LENGTH             (0x06U)
#define ASM330_TEMP_DATA_LENGTH             (0x02U)
#define ASM330_TIMESTAMP_DATA_LENGTH        (0x04U)

/*ASM330 CMD*/
#define ASM330_READ_CMD_INVALID             (0X00U)
#define ASM330_READ_CMD_VALID               (0X01U)

#define ASM330_RESET_STATE_WRITE_CMD        (0x00U)
#define ASM330_RESET_STATE_READ_CMD         (0x01U)
#define ASM330_DEVICE_CONFIG_ENABLE_CMD     (0x02U)
#define ASM330_RESET_ACC_RATE_CMD           (0x03U)
#define ASM330_RESET_ACC_SCALE_CMD          (0x04U)
#define ASM330_RESET_GYRO_RATE_CMD          (0x05U)
#define ASM330_RESET_GYRO_SCALE_CMD         (0x06U)
#define ASM330_RESET_FINE_CMD               (0X07u)


#define ASM330_WRITE_CMD                    (0x00U)
#define ASM330_READ_CMD                     (0x01U)

/*ASM330 DATA TYPE*/
#define ASM330_INVALID_DATA_TYPE            (0x00U)
#define ASM330_ACC_DATA_TYPE                (0x01U)
#define ASM330_GYRO_DATA_TYPE               (0x02U)
#define ASM330_TEMP_DATA_TYPE               (0x04U)
#define ASM330_TIMESTAMP_DATA_TYPE          (0x08U)

/*ASM330 REG */
#define ASM330_REG_USE_NUM                  (0x05U)
#define ASM330_REG_TABLE    \
 {\
    /*addr              value*/\
    {ASM330_CTRL1_XL,   0x00U},\
    {ASM330_CTRL2_G,    0x00U},\
    {ASM330_CTRL3_C,    0x00U},\
    {ASM330_CTRL9_XL,   0x00U},\
    {ASM330_CTRL10_C,   0x00U},\
 }\


/*ASM330 READ CMD*/
#define ASM330_READ_CMD_NUM                 (0x04U)
#define ASM330_READ_CMD_TABLE   \
 {\
     {ASM330_ACC_DATA_TYPE,        ASM330_OUTX_L_A,     ASM330_ACC_DATA_LENGTH          , 0U},\
     {ASM330_GYRO_DATA_TYPE,       ASM330_OUTX_L_G,     ASM330_GYRO_DATA_LENGTH         , 0U},\
     {ASM330_TEMP_DATA_TYPE,       ASM330_OUT_TEMP_L,   ASM330_TEMP_DATA_LENGTH         , 0U},\
     {ASM330_TIMESTAMP_DATA_TYPE,  ASM330_TIMESTAMP0,   ASM330_TIMESTAMP_DATA_LENGTH    , 0U},\
 }\


/*ASM330 RESET CMD*/
#define ASM330_RESET_CMD_NUM                (0x09U)
#define ASM330_RESET_CMD_TABLE  \
 {\
     /*cmd mask                  cmd addr            cmd value                rw type          cmd size*/\
     {ASM330_RESET_MASK,         ASM330_CTRL3_C,     ASM330_RESET_EN,         ASM330_WRITE_CMD, 1U},\
     {ASM330_RESET_MASK,         ASM330_CTRL3_C,     0,                       ASM330_READ_CMD,  1U},\
     {ASM330_DEVICE_CONFIG_MASK, ASM330_CTRL9_XL,    ASM330_DEVICE_CONFIG_EN, ASM330_WRITE_CMD, 1U},\
     {ASM330_ACC_RATE_MASK,      ASM330_CTRL1_XL,    0,                       ASM330_WRITE_CMD, 1U},\
     {ASM330_ACC_SCALE_MASK,     ASM330_CTRL1_XL,    0,                       ASM330_WRITE_CMD, 1U},\
     {ASM330_GYRO_RATE_MASK,     ASM330_CTRL2_G,     0,                       ASM330_WRITE_CMD, 1U},\
     {ASM330_GYRO_SCALE_MASK,    ASM330_CTRL2_G,     0,                       ASM330_WRITE_CMD, 1U},\
     {ASM330_FREQ_FINE_MASK,     ASM330_INTERNAL_FREQ_FINE,    0,             ASM330_READ_CMD,  1U},\
     {ASM330_TIMESTAMP_MASK,     ASM330_CTRL10_C,    ASM330_TIMESTAMP_EN,     ASM330_WRITE_CMD, 1U},\
 }\

/*ASM330 SENSITIVITY TABLE*/
#define ASM330_SENSITIVITY_NUM                (0x08)
#define ASM330_SENSITIVITY_TABLE  \
{\
    {ASM330_ACC_DATA_TYPE,  ASM330_ACC_SCALE_2G,        ASM330_ACC_SENSITIVITY_2G},\
    {ASM330_ACC_DATA_TYPE,  ASM330_ACC_SCALE_4G,        ASM330_ACC_SENSITIVITY_4G},\
    {ASM330_ACC_DATA_TYPE,  ASM330_ACC_SCALE_8G,        ASM330_ACC_SENSITIVITY_8G},\
    {ASM330_ACC_DATA_TYPE,  ASM330_ACC_SCALE_16G,       ASM330_ACC_SENSITIVITY_16G},\
    {ASM330_GYRO_DATA_TYPE, ASM330_GYRO_SCALE_250DPS,   ASM330_GYRO_SENSITIVITY_250DPS},\
    {ASM330_GYRO_DATA_TYPE, ASM330_GYRO_SCALE_500DPS,   ASM330_GYRO_SENSITIVITY_500DPS},\
    {ASM330_GYRO_DATA_TYPE, ASM330_GYRO_SCALE_1000DPS,  ASM330_GYRO_SENSITIVITY_1000DPS},\
    {ASM330_GYRO_DATA_TYPE, ASM330_GYRO_SCALE_2000DPS,  ASM330_GYRO_SENSITIVITY_2000DPS},\
}\

typedef float Asm330_Tmep_t;
typedef uint64 Asm330_TimeStamp_t;

 /*ASM330 CONFIG STRUCT*/
 typedef struct Asm330_Config_t
 {
    uint8 accrate;
    uint8 accscale;
    uint8 gyrorate;
    uint8 gyroscale;
 }Asm330_Config_t;

/*ASM330 SENSOR SENTIVITY*/
 typedef struct Asm330_Sentivity_t
 {
    uint8 type;
    uint8 scale;
    float sensitivity;
 }Asm330_Sentivity_t;

 /*ASM330 SENSOR DATA STRUCT*/
 typedef struct Asm330_Data_t
 {
     sint16 x;
     sint16 y;
     sint16 z;
 }Asm330_Data_t;

 typedef struct Asm330_ReadData_t
 {
     Asm330_Data_t acc;
     Asm330_Data_t gyro;
     Asm330_Tmep_t temp;
     Asm330_TimeStamp_t timestamp;
 }Asm330_ReadData_t;

 typedef struct Asm330_ReadCmd_t
 {
    uint8 type;
    Asm330_Addr_t addr;
    uint8 size;
    boolean req;
 }Asm330_ReadCmd_t;

typedef struct Asm330_RegData_t
{
    Asm330_Addr_t addr;
    Asm330_Reg_t reg;
}Asm330_RegData_t;

typedef struct Asm330_ResetCmd_t
{
   Asm330_Reg_t mask;
   Asm330_Addr_t addr;
   Asm330_Reg_t value;
   uint8 rw;
   uint8 size;
}Asm330_ResetCmd_t;

 typedef struct Asm330_Attribute_t
{
   uint8 id;
   boolean busy;
   uint8 opt;
   uint8 cmd;
   uint8 event;
   float32 timeres;/* timestamp resolution */
   uint8 cmdbuff[ASM330_I2C_CMD_LENGTH];
   Asm330_ReadData_t* pdata; /*user data buffer ptr*/
   uint8 readbuff[ASM330_READ_DATA_LENGTH];
}Asm330_Attribute_t;

/*EXTERN FUNCTION*/
extern void Asm330_Init(void);
extern void Asm330_ManageTask(void);
extern float Asm330_GetSensitivity(uint8 type, uint8 scale);
extern void Asm330_WriteCallback(IIC_ResultStatus_t state);
extern void Asm330_ReadCallback(IIC_ResultStatus_t state, const uint8 * pu8buf, uint16 size);
extern Asm330_Return_t Asm330_ResetReq(Asm330_Config_t* config);
extern Asm330_Return_t Asm330_ReadReq(uint8 req, Asm330_ReadData_t* pdata);
extern Asm330_Return_t Asm330_GetDeviceId(uint8* id);


#endif /* ifndef _GYRO_ASM330_H_.2020-5-7 10:29:48 GW00191223 */
