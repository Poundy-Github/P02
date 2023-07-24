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
 * @file:      IoHwAb_Pwm_Cfg.h
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

#ifndef _IOHWAB_PWM_CFG_H_
#define _IOHWAB_PWM_CFG_H_

/*attention ! 
1.the pwm id shared by both pwm period and duty , the same id for period and duty shall located to the same hardware pwm channnel
2.the duty cfg count must equal or bigger than period cfg count */

#define IoHwAb_Pwm_PeriodOutCfg_Count       1
                                                                        
#define IoHwAb_Pwm_DutyOutCfg_Count         1

#endif /*IoHwAb_PWM_Cfg_H*/

