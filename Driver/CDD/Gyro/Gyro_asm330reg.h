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
 * @file:      Gyro_asm330reg.h
 * @author:    Nobo
 * @date:      2020-5-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _GYRO_ASM330REG_H_
#define _GYRO_ASM330REG_H_

/*ASM330 REG ADDR*/
#define ASM330_ID                           (0x6BU)
#define ASM330_PIN_CTRL                     (0x02U)
#define ASM330_FIFO_CTRL1                   (0x07U)
#define ASM330_FIFO_CTRL2                   (0x08U)
#define ASM330_FIFO_CTRL3                   (0x09U)
#define ASM330_FIFO_CTRL4                   (0x0AU)
#define ASM330_COUNTER_BDR_REG1             (0x0BU)
#define ASM330_COUNTER_BDR_REG2             (0x0CU)
#define ASM330_INT1_CTRL                    (0x0DU)
#define ASM330_INT2_CTRL                    (0x0EU)
#define ASM330_WHO_AM_I                     (0x0FU)
#define ASM330_CTRL1_XL                     (0x10U)
#define ASM330_CTRL2_G                      (0x11U)
#define ASM330_CTRL3_C                      (0x12U)
#define ASM330_CTRL4_C                      (0x13U)
#define ASM330_CTRL5_C                      (0x14U)
#define ASM330_CTRL6_G                      (0x15U)
#define ASM330_CTRL7_G                      (0x16U)
#define ASM330_CTRL8_XL                     (0x17U)
#define ASM330_CTRL9_XL                     (0x18U)
#define ASM330_CTRL10_C                     (0x19U)
#define ASM330_ALL_INT_SRC                  (0x1AU)
#define ASM330_WAKE_UP_SRC                  (0x1BU)
#define ASM330_TAP_SRC                      (0x1CU)
#define ASM330_D6D_SRC                      (0x1DU)
#define ASM330_STATUS_REG                   (0x1EU)
#define ASM330_OUT_TEMP_L                   (0x20U)
#define ASM330_OUT_TEMP_H                   (0x21U)
#define ASM330_OUTX_L_G                     (0x22U)
#define ASM330_OUTX_H_G                     (0x23U)
#define ASM330_OUTY_L_G                     (0x24U)
#define ASM330_OUTY_H_G                     (0x25U)
#define ASM330_OUTZ_L_G                     (0x26U)
#define ASM330_OUTZ_H_G                     (0x27U)
#define ASM330_OUTX_L_A                     (0x28U)
#define ASM330_OUTX_H_A                     (0x29U)
#define ASM330_OUTY_L_A                     (0x2AU)
#define ASM330_OUTY_H_A                     (0x2BU)
#define ASM330_OUTZ_L_A                     (0x2CU)
#define ASM330_OUTZ_H_A                     (0x2DU)
#define ASM330_FIFO_STATUS2                 (0x3BU)
#define ASM330_FIFO_STATUS1                 (0x3AU)
#define ASM330_TIMESTAMP0                   (0x40U)
#define ASM330_TIMESTAMP1                   (0x41U)
#define ASM330_TIMESTAMP2                   (0x42U)
#define ASM330_TIMESTAMP3                   (0x43U)
#define ASM330_INT_CFG0                     (0x56U)
#define ASM330_INT_CFG1                     (0x58U)
#define ASM330_THS_6D                       (0x59U)
#define ASM330_INT_DUR2                     (0x5AU)
#define ASM330_WAKE_UP_THS                  (0x5BU)
#define ASM330_WAKE_UP_DUR                  (0x5CU)
#define ASM330_FREE_FALL                    (0x5DU)
#define ASM330_MD1_CFG                      (0x5EU)
#define ASM330_MD2_CFG                      (0x5FU)
#define ASM330_INTERNAL_FREQ_FINE           (0x63U)
#define ASM330_X_OFS_USR                    (0x73U)
#define ASM330_Y_OFS_USR                    (0x74U)
#define ASM330_Z_OFS_USR                    (0x75U)
#define ASM330_FIFO_DATA_OUT_TAG            (0x78U)
#define ASM330_FIFO_DATA_OUT_X_L            (0x79U)
#define ASM330_FIFO_DATA_OUT_X_H            (0x7AU)
#define ASM330_FIFO_DATA_OUT_Y_L            (0x7BU)
#define ASM330_FIFO_DATA_OUT_Y_H            (0x7CU)
#define ASM330_FIFO_DATA_OUT_Z_L            (0x7DU)
#define ASM330_FIFO_DATA_OUT_Z_H            (0x7EU)


/* ASM330_ID REG */                         
/* ASM330_PIN_CTRL REG */      
/* ASM330_FIFO_CTRL2 */      
/* ASM330_FIFO_CTRL1 REG */          
/* ASM330_FIFO_CTRL3 REG */ 
#define ASM330_RESET_MASK                   (0x01U)
#define ASM330_RESET_EN                     (0x01U)
/* ASM330_FIFO_CTRL4 REG */      
/* ASM330_COUNTER_BDR_REG1 REG */      
/* ASM330_COUNTER_BDR_REG2 REG */      
/* ASM330_INT1_CTRL REG */      
/* ASM330_WHO_AM_I REG */
#define ASM330_DEVICE_ID_LENGTH             (0X01u)
/* ASM330_INT2_CTRL REG */      
/* ASM330_CTRL1_XL REG */    
#define ASM330_ACC_RATE_MASK                (0xF0U)
#define ASM330_ACC_RATE_SHIFT               (4U)
#define ASM330_ACC_RATE(x)                  ((((uint8)(x))<<ASM330_ACC_RATE_SHIFT) & ASM330_ACC_RATE_MASK)
#define ASM330_ACC_RATE_0HZ                 (0U)
#define ASM330_ACC_RATE_12HZ                (1U)
#define ASM330_ACC_RATE_26HZ                (2U)
#define ASM330_ACC_RATE_53HZ                (3U)
#define ASM330_ACC_RATE_104HZ               (4U)
#define ASM330_ACC_RATE_208HZ               (5U)
#define ASM330_ACC_RATE_417HZ               (6U)
#define ASM330_ACC_RATE_833HZ               (7U)
#define ASM330_ACC_RATE_1667HZ              (8U)
#define ASM330_ACC_RATE_3333HZ              (9U)
#define ASM330_ACC_RATE_6667HZ              (10U)
#define ASM330_ACC_SCALE_MASK               (0x0C)
#define ASM330_ACC_SCALE_SHIFT              (2U)
#define ASM330_ACC_SCALE(x)                 ((((uint8)(x))<<ASM330_ACC_SCALE_SHIFT) & ASM330_ACC_SCALE_MASK)
#define ASM330_ACC_SCALE_2G                 (0U)
#define ASM330_ACC_SCALE_16G                (1U)
#define ASM330_ACC_SCALE_4G                 (2U)
#define ASM330_ACC_SCALE_8G                 (3U)
#define ASM330_ACC_SENSITIVITY_2G           (0.061f)
#define ASM330_ACC_SENSITIVITY_4G           (0.122f)
#define ASM330_ACC_SENSITIVITY_8G           (0.244f)
#define ASM330_ACC_SENSITIVITY_16G          (0.488f)
/* ASM330_CTRL2_G REG */      
#define ASM330_GYRO_RATE_MASK               (0xF0U)
#define ASM330_GYRO_RATE_SHIFT              (4U)
#define ASM330_GYRO_RATE(x)                 ((((uint8)(x))<<ASM330_GYRO_RATE_SHIFT) & ASM330_GYRO_RATE_MASK)
#define ASM330_GYRO_RATE_0HZ                (0U)
#define ASM330_GYRO_RATE_12HZ               (1U)
#define ASM330_GYRO_RATE_26HZ               (2U)
#define ASM330_GYRO_RATE_53HZ               (3U)
#define ASM330_GYRO_RATE_104HZ              (4U)
#define ASM330_GYRO_RATE_208HZ              (5U)
#define ASM330_GYRO_RATE_417HZ              (6U)
#define ASM330_GYRO_RATE_833HZ              (7U)
#define ASM330_GYRO_RATE_1667HZ             (8U)
#define ASM330_GYRO_RATE_3333HZ             (9U)
#define ASM330_GYRO_RATE_6667HZ             (10U)
#define ASM330_GYRO_SCALE_SHIFT             (2U)
#define ASM330_GYRO_SCALE_MASK              (0x0CU)
#define ASM330_GYRO_SCALE(x)                 ((((uint8)(x))<<ASM330_GYRO_SCALE_SHIFT) & ASM330_GYRO_SCALE_MASK)
#define ASM330_GYRO_SCALE_250DPS            (0U)
#define ASM330_GYRO_SCALE_500DPS            (1U)
#define ASM330_GYRO_SCALE_1000DPS           (2U)
#define ASM330_GYRO_SCALE_2000DPS           (3U)
#define ASM330_GYRO_SENSITIVITY_250DPS      (8.75f)
#define ASM330_GYRO_SENSITIVITY_500DPS      (17.5f)
#define ASM330_GYRO_SENSITIVITY_1000DPS     (35.0f)
#define ASM330_GYRO_SENSITIVITY_2000DPS     (70.0f)
/* ASM330_CTRL3_C REG */      
/* ASM330_CTRL4_C REG */      
/* ASM330_CTRL5_C REG */      
/* ASM330_CTRL6_G REG */      
/* ASM330_CTRL7_G REG */      
/* ASM330_CTRL8_XL REG */      
/* ASM330_CTRL9_XL REG */  
#define ASM330_DEVICE_CONFIG_MASK           (0x02)
#define ASM330_DEVICE_CONFIG_EN             (0X02)
/* ASM330_CTRL10_C REG */   
#define ASM330_TIMESTAMP_MASK               (0x20)
#define ASM330_TIMESTAMP_EN                 (0x20)
/* ASM330_ALL_INT_SRC REG */      
/* ASM330_WAKE_UP_SRC REG */      
/* ASM330_TAP_SRC REG */      
/* ASM330_D6D_SRC REG */      
/* ASM330_STATUS_REG REG */      
/* ASM330_OUT_TEMP_L REG */      
/* ASM330_OUT_TEMP_H REG */      
/* ASM330_OUTX_L_G REG */      
/* ASM330_OUTX_H_G REG */      
/* ASM330_OUTY_L_G REG */      
/* ASM330_OUTY_H_G REG */      
/* ASM330_OUTZ_L_G REG */      
/* ASM330_OUTZ_H_G REG */      
/* ASM330_OUTX_L_A REG */      
/* ASM330_OUTX_H_A REG */      
/* ASM330_OUTY_L_A REG */      
/* ASM330_OUTY_H_A REG */      
/* ASM330_OUTZ_L_A REG */      
/* ASM330_OUTZ_H_A REG */      
/* ASM330_FIFO_STATUS1 REG */      
/* ASM330_FIFO_STATUS2 REG */      
/* ASM330_TIMESTAMP0 REG */      
/* ASM330_TIMESTAMP1 REG */      
/* ASM330_TIMESTAMP2 REG */      
/* ASM330_TIMESTAMP3 REG */      
/* ASM330_INT_CFG0 REG */      
/* ASM330_INT_CFG1 REG */      
/* ASM330_THS_6D REG */      
/* ASM330_INT_DUR2 REG */      
/* ASM330_WAKE_UP_THS REG */      
/* ASM330_WAKE_UP_DUR REG */      
/* ASM330_FREE_FALL REG */      
/* ASM330_MD1_CFG REG */     
/* ASM330_MD2_CFG REG */      
/* ASM330_INTERNAL_FREQ_FINE REG */   
#define ASM330_FREQ_FINE_MASK               (0xFFU)
/* ASM330_X_OFS_USR REG */      
/* ASM330_Y_OFS_USR REG */      
/* ASM330_Z_OFS_USR REG */      
/* ASM330_FIFO_DATA_OUT_TAG REG */      
/* ASM330_FIFO_DATA_OUT_X_L REG */      
/* ASM330_FIFO_DATA_OUT_X_H REG */      
/* ASM330_FIFO_DATA_OUT_Y_L REG */      
/* ASM330_FIFO_DATA_OUT_Y_H REG */      
/* ASM330_FIFO_DATA_OUT_Z_L REG */      
/* ASM330_FIFO_DATA_OUT_Z_H REG */       




#endif /* ifndef _GYRO_ASM330REG_H_.2020-5-19 11:53:03 GW00191223 */
