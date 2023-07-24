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
 * @file:      ADAU1978_reg.h
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

#ifndef ADAU1978_REG_H
#define ADAU1978_REG_H

#define ADAU1978_REG_POWER                  0x00
#define ADAU1978_REG_PLL                    0x01
#define ADAU1978_REG_BOOST                  0x02
#define ADAU1978_REG_MICBIAS                0x03
#define ADAU1978_REG_BLOCK_POWER_SAI        0x04
#define ADAU1978_REG_SAI_CTRL0              0x05
#define ADAU1978_REG_SAI_CTRL1              0x06
#define ADAU1978_REG_CMAP12                 0x07
#define ADAU1978_REG_CMAP34                 0x08
#define ADAU1978_REG_SAI_OVERTEMP           0x09
#define ADAU1978_REG_POST_ADC_GAIN(x)       (0x0a + (x))
#define ADAU1978_REG_MISC_CONTROL           0x0e
#define ADAU1978_REG_DIAG_CONTROL           0x10
#define ADAU1978_REG_STATUS(x)              (0x11 + (x))
#define ADAU1978_REG_DIAG_IRQ1              0x15
#define ADAU1978_REG_DIAG_IRQ2              0x16
#define ADAU1978_REG_ADJUST1                0x17
#define ADAU1978_REG_ADJUST2                0x18
#define ADAU1978_REG_ADC_CLIP               0x19
#define ADAU1978_REG_DC_HPF_CAL             0x1a

#define ADAU1978_POWER_RESET                BIT(1u, 7)
#define ADAU1978_POWER_PWUP                 BIT(1u, 0)

#define ADAU1978_PLL_CLK_S                  BIT(1u, 4)
#define ADAU1978_PLL_MCS_MASK               0x7
#define ADAU1978_PLL_LOCK_MASK              BIT(1u, 7)

#define ADAU1978_MICBIAS_MB_VOLTS_MASK      0xf0
#define ADAU1978_MICBIAS_MB_VOLTS_OFFSET    4

#define ADAU1978_BLOCK_POWER_SAI_LR_POL     BIT(1u, 7)
#define ADAU1978_BLOCK_POWER_SAI_BCLK_EDGE  BIT(1u, 6)
#define ADAU1978_BLOCK_POWER_SAI_LDO_EN     BIT(1u, 5)
#define ADAU1978_BLOCK_POWER_SAI_VREF_EN    BIT(1u, 4)
#define ADAU1978_BLOCK_POWER_SAI_ADC_EN4    BIT(1u, 3)
#define ADAU1978_BLOCK_POWER_SAI_ADC_EN3    BIT(1u, 2)
#define ADAU1978_BLOCK_POWER_SAI_ADC_EN2    BIT(1u, 1)
#define ADAU1978_BLOCK_POWER_SAI_ADC_EN1    BIT(1u, 0)

#define ADAU1978_SAI_CTRL0_FMT_MASK         (0x3 << 6)
#define ADAU1978_SAI_CTRL0_FMT_I2S          (0x0 << 6)
#define ADAU1978_SAI_CTRL0_FMT_LJ           (0x1 << 6)
#define ADAU1978_SAI_CTRL0_FMT_RJ_24BIT     (0x2 << 6)
#define ADAU1978_SAI_CTRL0_FMT_RJ_16BIT     (0x3 << 6)

#define ADAU1978_SAI_CTRL0_SAI_MASK         (0x7 << 3)
#define ADAU1978_SAI_CTRL0_SAI_I2S          (0x0 << 3)
#define ADAU1978_SAI_CTRL0_SAI_TDM_2        (0x1 << 3)
#define ADAU1978_SAI_CTRL0_SAI_TDM_4        (0x2 << 3)
#define ADAU1978_SAI_CTRL0_SAI_TDM_8        (0x3 << 3)
#define ADAU1978_SAI_CTRL0_SAI_TDM_16       (0x4 << 3)

#define ADAU1978_SAI_CTRL0_FS_MASK          (0x7)
#define ADAU1978_SAI_CTRL0_FS_8000_12000    (0x0)
#define ADAU1978_SAI_CTRL0_FS_16000_24000   (0x1)
#define ADAU1978_SAI_CTRL0_FS_32000_48000   (0x2)
#define ADAU1978_SAI_CTRL0_FS_64000_96000   (0x3)
#define ADAU1978_SAI_CTRL0_FS_128000_192000 (0x4)

#define ADAU1978_SAI_CTRL1_SLOT_WIDTH_MASK  (0x3 << 5)
#define ADAU1978_SAI_CTRL1_SLOT_WIDTH_32    (0x0 << 5)
#define ADAU1978_SAI_CTRL1_SLOT_WIDTH_24    (0x1 << 5)
#define ADAU1978_SAI_CTRL1_SLOT_WIDTH_16    (0x2 << 5)
#define ADAU1978_SAI_CTRL1_DATA_WIDTH_MASK  (0x1 << 4)
#define ADAU1978_SAI_CTRL1_DATA_WIDTH_16BIT (0x1 << 4)
#define ADAU1978_SAI_CTRL1_DATA_WIDTH_24BIT (0x0 << 4)
#define ADAU1978_SAI_CTRL1_LRCLK_PULSE      BIT(1u, 3)
#define ADAU1978_SAI_CTRL1_MSB              BIT(1u, 2)
#define ADAU1978_SAI_CTRL1_BCLKRATE_16      (0x1 << 1)
#define ADAU1978_SAI_CTRL1_BCLKRATE_32      (0x0 << 1)
#define ADAU1978_SAI_CTRL1_BCLKRATE_MASK    (0x1 << 1)
#define ADAU1978_SAI_CTRL1_MASTER           BIT(1u, 0)

#define ADAU1978_SAI_OVERTEMP_DRV_C(x)      BIT(4 + (x))
#define ADAU1978_SAI_OVERTEMP_DRV_HIZ       BIT(1u, 3)

#define ADAU1978_MISC_CONTROL_SUM_MODE_MASK (0x3 << 6)
#define ADAU1978_MISC_CONTROL_SUM_MODE_1CH  (0x2 << 6)
#define ADAU1978_MISC_CONTROL_SUM_MODE_2CH  (0x1 << 6)
#define ADAU1978_MISC_CONTROL_SUM_MODE_4CH  (0x0 << 6)
#define ADAU1978_MISC_CONTROL_MMUTE         BIT(1u, 4)
#define ADAU1978_MISC_CONTROL_DC_CAL        BIT(1u, 0)

#define ADAU1978_CHAN_MAP_SECOND_SLOT_OFFSET    4
#define ADAU1978_CHAN_MAP_FIRST_SLOT_OFFSET     0

#endif