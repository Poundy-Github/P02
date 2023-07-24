/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/
/**
**  Name:               SWC_Odo_Interface_Cfg.h
**
**  Description:        Odo moudle interface file to other.Include init and get Odo data 
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_ODO_INTERFACE_CFG_H
#define SWC_ODO_INTERFACE_CFG_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* Internel Function Invalid                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
* define of parament                                                                                      *
**********************************************************************************************************/
#define ODO_MAIN_TASK_CYCLE 										(20u)

#define ODO_MESSAGE_MAX_VALUE										(9999u)
#define ODO_MESSAGE_ROLLING_MAX_VALUE								(0xFFFFu)

/*(220KM/H)/0.01*/
#define ODO_MAX_SPEED_INPUT											(100u) 

/*If odo value is base on roll couner,need to difine ODO_PPK_Cfg*/
#define ODO_SPEED_PPK_CFG											(1000u)

/*128 0.2m   640  as 72km/h*5/18*50ms = 1m ,
If odo value is base on roll couner,need to difine  to ppk*/
#define ODO_UPDATE_UNIT												(1u) 

/*Diag reset max odo value */
#define ODO_ResetMaxValue 											(600u)

/*Diag reset max odo value */
#define ODO_MAX_DISPLAY_VALUE 										(999999999UL)

/*TRIP ODO NVM error value*/
#define ODO_TRIP_RESET_VALUE 										(999999UL)

#define ODO_VIN_CHEKC_ERR_MAX										(3u)

#define ODO_CLEAR_VALUE_MAX											(255000UL)

// TODO: < REPLACE START >
#define ODO_CAN_SEND_ODO_VALUE(id,dataadr)							//Com_SendSignal(id,dataadr)
// TODO: < REPLACE END >


#define ODO_OSTM_TIMER_REFERENCE									(1u)
#define ODO_OSTM_TIMER_1_COUNTER									(2000/ODO_OSTM_TIMER_REFERENCE)
#define ODO_OSTM_TIMER_2_COUNTER									(5000/ODO_OSTM_TIMER_REFERENCE)
#define ODO_OSTM_TIMER_3_COUNTER									(100/ODO_OSTM_TIMER_REFERENCE)
#define ODO_OSTM_TIMER_4_COUNTER									(5000/ODO_OSTM_TIMER_REFERENCE)
#define ODO_OSTM_TIMER_5_COUNTER									(3000/ODO_OSTM_TIMER_REFERENCE)
#define ODO_OSTM_TIMER_6_COUNTER									((uint32)600)//time unit is s,not ms

#define ODO_RTE_SET_LEN_TBL											{0xff,sizeof(uint32),sizeof(uint8),0xff,sizeof(sint32)}

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/06/02     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

