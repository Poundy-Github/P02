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
 * @file:      RTC_Driver.c
 * @author:    Nobo
 * @date:      2020-4-24
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-24
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include <string.h>

#include "RTC_Driver.h"
#include "RTC_RI.h"
#include "RTC_cfg.h"





typedef uint8 Rtc_command_t;


#define eRTC_CMD_INIT                       (0x00U)
#define eRTC_CMD_SET_TIME                   (0x01U)
#define eRTC_CMD_SYNCH_TIME                 (0x02U)
#define eRTC_CMD_NUMBER                     (0x03U)


typedef uint8 Rtc_Retry_t;

#define eRTC_NOT_RETRY                      (0x00)
#define eRTC_RETRY_Low                      (0x01)
#define eRTC_RETRY_MODERATE                 (0x02)
#define eRTC_RETRY_LONG                     (0x03)



typedef uint8 Rtc_InternalStatus_t;

#define RTC_INTERNAL_STAR                   (0x00U)


#define RTC_INTERNAL_INIT_STEP1             (0x1)      //!> Whether it is a return from the state of the backup is confirmed.
#define RTC_INTERNAL_INIT_STEP2             (0x2)       
#define RTC_INTERNAL_INIT_STEP3             (0x3)
#define RTC_INTERNAL_INIT_STEP4             (0x4)
#define RTC_INTERNAL_INIT_STEP5             (0x5)
#define RTC_INTERNAL_INIT_STEP6             (0x6)
#define RTC_INTERNAL_INIT_END               (0x7)
#define RTC_INTERNAL_INIT_E_STEP1           (0x8)
#define RTC_INTERNAL_INIT_E_STEP2_1         (0x9)
#define RTC_INTERNAL_INIT_E_STEP2_2         (0xa)
#define RTC_INTERNAL_INIT_E_STEP3_1         (0xb)
#define RTC_INTERNAL_INIT_E_STEP3_2         (0xc)
#define RTC_INTERNAL_INIT_E_STEP4_1         (0xd)
#define RTC_INTERNAL_INIT_E_STEP4_2         (0xe)
#define RTC_INTERNAL_INIT_E_STEP4_3         (0xf)
#define RTC_INTERNAL_INIT_E_STEP5_1         (0x10)



#define RTC_INTERNAL_SET_STEP1              (0x1)
#define RTC_INTERNAL_SET_STEP2              (0x2)
#define RTC_INTERNAL_SET_STEP3              (0x3)
#define RTC_INTERNAL_SET_E_STEP1            (0x4)
#define RTC_INTERNAL_SET_E_STEP2_1          (0x5)
#define RTC_INTERNAL_SET_E_STEP2_2          (0x6)
#define RTC_INTERNAL_SET_E_STEP3            (0x7)

#define RTC_INTERNAL_GET_STEP1              (0x1)
#define RTC_INTERNAL_GET_STEP2              (0x2)
#define RTC_INTERNAL_GET_E_STEP1            (0x3)
#define RTC_INTERNAL_GET_E_STEP2            (0x4)


// RTC Register Address 
#define RTC_REG_SEC                         (0x00U)
#define RTC_REG_MIN                         (0x01U)
#define RTC_REG_HOUR                        (0x02U)
#define RTC_REG_WEEK                        (0x03U)
#define RTC_REG_DAY                         (0x04U)
#define RTC_REG_MONTH                       (0x05U)
#define RTC_REG_YEAR                        (0x06U)
#define RTC_REG_RAM                         (0x07U)
#define RTC_REG_MIN_ALARM                   (0x08U)
#define RTC_REG_HOUR_ALARM                  (0x09U)
#define RTC_REG_WD_ALARM                    (0x0AU)
#define RTC_REG_TIMER_COUNTER0              (0x0BU)
#define RTC_REG_TIMER_COUNTER1              (0x0CU)
#define RTC_REG_EXTENSION                   (0x0DU)
#define RTC_REG_FLAG                        (0x0EU)
#define RTC_REG_CONTROL                     (0x0FU)


// register FLAG Mast define
#define RTC_REG_FLAG_UF_MASK                (0x20U)
#define RTC_REG_FLAG_TF_MASK                (0x10U)
#define RTC_REG_FLAG_AF_MASK                (0x08U)
#define RTC_REG_FLAG_VLF_MASK               (0x02U)
#define RTC_REG_FLAG_VDET_MASK              (0x01U)

#define RTC_REG_CONTROL_RESET_MASK          (0x01U)



#define TRANSMIT_BUFFER_SZIE                (0x10U)
#define TASK_PERIOD (100u)

typedef struct 
{
    time_t   UTC_Time;
    Rtc_command_t   tCommandEvent;
    Rtc_Status_t    tStatus;
} Rtc_ImplRequest_t;

typedef struct
{
    IIC_ResultStatus_t  tState;
    boolean             bIsUpdata;
}
Rtc_ImplResult_t;



typedef struct 
{              
    Rtc_ImplRequest_t   tRequest;
    Rtc_ImplResult_t    tResult;
    Rtc_InternalStatus_t tInternalStatus;
    uint32 u32FaultCount;
    
} Rtc_DriverHandler_t;




typedef void (*CommandFunction_t)(void);







STATIC void RTC_CommandFromInit(void);
STATIC void RTC_CommandFromSetTime(void);
STATIC void RTC_CommandFromGetTime(void);

STATIC const CommandFunction_t cCommandFunctionTable[eRTC_CMD_NUMBER] = 
{
    RTC_CommandFromInit,
    RTC_CommandFromSetTime,
    RTC_CommandFromGetTime
};

const STATIC uint8 wday2Impl[7] = 
{0x01,0x02,0x04,0x08,0x10,0x20,0x40};


STATIC uint32 u32InitCnt = 0;

#pragma ghs startdata
#pragma ghs section bss=".rram_misc"

STATIC boolean bRTC_IsInit;

#pragma ghs section bss=default
#pragma ghs enddata



STATIC Rtc_DriverHandler_t tRtc_DriverHandler =
{
    0
};

STATIC uint8 u8TransmitBuffer[TRANSMIT_BUFFER_SZIE];


STATIC sint32 RTC_BCD2DEC(const uint8 bcd)
{
    return (bcd>>4)*10 + (bcd & (uint8)0x0F);
}

STATIC uint8 RTC_DEC2BCD(const uint8 dec)
{
    return (uint8)(((dec/10)<<4)+(dec%10));
}






STATIC void RTC_RequestExecute(Rtc_command_t command,time_t time)
{
//    RTC_DEBUG("RTC internal Request Execute : %d\n",command);
    tRtc_DriverHandler.tRequest.tCommandEvent = command;
    tRtc_DriverHandler.tRequest.UTC_Time = time;
    tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_BUSY;

    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_STAR;

}



/***********************************************************************
 * @brief       : check Results, The flag is cleared after reading.
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC boolean RTC_WaitResult(IIC_ResultStatus_t * pState)
{
    boolean bIsUpdata = FALSE;
    RTC_ACCERT(pState!=NULL_PTR);
    if (TRUE == tRtc_DriverHandler.tResult.bIsUpdata)
    {
        bIsUpdata = TRUE;
        tRtc_DriverHandler.tResult.bIsUpdata = FALSE;
        *pState = tRtc_DriverHandler.tResult.tState;
//        RTC_DEBUG(">>>>RTC internal Result : %d\n",*pState);
    }
    return bIsUpdata;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_CommandFromInit(void)
{
    static uint8 flag = 0;
    IIC_Return_t ret;
    IIC_ResultStatus_t state = 0;

//    RTC_DEBUG(">>RTC internal status : %d\n",tRtc_DriverHandler.tInternalStatus);
    switch(tRtc_DriverHandler.tInternalStatus)
    {
        
        case RTC_INTERNAL_STAR:
        case RTC_INTERNAL_INIT_STEP1:
            (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
            u8TransmitBuffer[0] = RTC_REG_FLAG;
            ret = RI_QueueRxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,1,1);
            if (eIIC_Return_Success == ret)
            {
                tRtc_DriverHandler.u32FaultCount = 0;
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP2;
            }
            else
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP1;
            }
            break;
        case RTC_INTERNAL_INIT_STEP2:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    flag = u8TransmitBuffer[0];
                    if (flag & RTC_REG_FLAG_VLF_MASK)
                    {
                        u8TransmitBuffer[0] = RTC_REG_SEC;
                        u8TransmitBuffer[1] = RTC_DEF_SEC  ;
                        u8TransmitBuffer[2] = RTC_DEF_MIN  ;
                        u8TransmitBuffer[3] = RTC_DEF_HOUR ;
                        u8TransmitBuffer[4] = RTC_DEF_WEEK ;
                        u8TransmitBuffer[5] = RTC_DEF_DAY  ;
                        u8TransmitBuffer[6] = RTC_DEF_MONTH;
                        u8TransmitBuffer[7] = RTC_DEF_YEAR ;
                        
                        ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,8);
                        if (eIIC_Return_Success == ret)
                        {
                            tRtc_DriverHandler.u32FaultCount = 0;
                            tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP3;
                        }
                        else
                        {
                            tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP2_2;
                        }
                     }
                    else
                     {
                        // init end;
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_END;
                     }
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP2_1;
                }
            }
            break;
        case RTC_INTERNAL_INIT_STEP3:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
                    u8TransmitBuffer[0] = RTC_REG_FLAG;
                    u8TransmitBuffer[1] = (uint8)(flag & (~RTC_REG_FLAG_VLF_MASK));
                    ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,2);
                    if (eIIC_Return_Success == ret)
                    {
                        tRtc_DriverHandler.u32FaultCount = 0;
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP4;
                    }
                    else
                    {
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP3_2;
                    }
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP3_1;
                }
            }
            break;
        case RTC_INTERNAL_INIT_STEP4:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    tRtc_DriverHandler.u32FaultCount = 0;
                    tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_OK;
                    bRTC_IsInit = TRUE;
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_E_STEP4_1;
                }
            }
            break;
        case RTC_INTERNAL_INIT_END:
                tRtc_DriverHandler.u32FaultCount = 0;
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_OK;
                bRTC_IsInit = TRUE;
                break;
        case RTC_INTERNAL_INIT_E_STEP1:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;
                bRTC_IsInit = FALSE;
            }
            break;
        case RTC_INTERNAL_INIT_E_STEP2_1:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;
                bRTC_IsInit = FALSE;
            }
            break;
       case RTC_INTERNAL_INIT_E_STEP4_1:
       case RTC_INTERNAL_INIT_E_STEP3_2:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
                u8TransmitBuffer[0] = RTC_REG_FLAG;
                u8TransmitBuffer[1] = (uint8)(flag & (~RTC_REG_FLAG_VLF_MASK));
                ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,2);
                if (eIIC_Return_Success == ret)
                {
                    tRtc_DriverHandler.u32FaultCount=0;
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP4;
                }
                else
                {
                    tRtc_DriverHandler.u32FaultCount++;
                }
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;
                bRTC_IsInit = FALSE;
            }
            break;
        case RTC_INTERNAL_INIT_E_STEP3_1:
        case RTC_INTERNAL_INIT_E_STEP2_2:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                u8TransmitBuffer[0] = RTC_REG_SEC;
                u8TransmitBuffer[1] = RTC_DEF_SEC  ;
                u8TransmitBuffer[2] = RTC_DEF_MIN  ;
                u8TransmitBuffer[3] = RTC_DEF_HOUR ;
                u8TransmitBuffer[4] = RTC_DEF_WEEK ;
                u8TransmitBuffer[5] = RTC_DEF_DAY  ;
                u8TransmitBuffer[6] = RTC_DEF_MONTH;
                u8TransmitBuffer[7] = RTC_DEF_YEAR ;
            
                ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,8);
                if (eIIC_Return_Success == ret)
                {
                    tRtc_DriverHandler.u32FaultCount = 0;
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_INIT_STEP3;
                }
                else
                {
                    tRtc_DriverHandler.u32FaultCount++;
                }
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;
                bRTC_IsInit = FALSE;
            }
            break;
        default:
            /*Nothing to do*/
            break;
    }
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_CommandFromSetTime(void)
{
    IIC_Return_t ret = eIIC_Return_Error;
    IIC_ResultStatus_t state = 0;
    struct tm * time;
    RTC_DEBUG(">>RTC internal status : %d\n",tRtc_DriverHandler.tInternalStatus);
    switch(tRtc_DriverHandler.tInternalStatus)
    {
        case RTC_INTERNAL_STAR:
        case RTC_INTERNAL_SET_STEP1:
            (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
            u8TransmitBuffer[0] = RTC_REG_CONTROL;
            u8TransmitBuffer[1] = RTC_REG_CONTROL_RESET_MASK;
            ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,2);
            if (eIIC_Return_Success == ret)
            {
                tRtc_DriverHandler.u32FaultCount = 0;
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_STEP2;
            }
            else
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_E_STEP1;
            }
            break;
        case RTC_INTERNAL_SET_STEP2:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
                    u8TransmitBuffer[0] = RTC_REG_SEC;
                    time = localtime(&tRtc_DriverHandler.tRequest.UTC_Time);
                    u8TransmitBuffer[1] = RTC_DEC2BCD((uint8)time->tm_sec);
                    u8TransmitBuffer[2] = RTC_DEC2BCD((uint8)time->tm_min);
                    u8TransmitBuffer[3] = RTC_DEC2BCD((uint8)time->tm_hour);
                    u8TransmitBuffer[4] = wday2Impl[((uint8)time->tm_wday&(uint8)0x0F)];
                    u8TransmitBuffer[5] = RTC_DEC2BCD((uint8)time->tm_mday);
                    u8TransmitBuffer[6] = RTC_DEC2BCD((uint8)(time->tm_mon+1));
                    u8TransmitBuffer[7] = RTC_DEC2BCD((uint8)(time->tm_year-100));// years since 2000;
                    ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,8);
                    if (eIIC_Return_Success == ret)
                    {
                        tRtc_DriverHandler.u32FaultCount = 0;
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_STEP3;
                    }
                    else
                    {
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_E_STEP2_2;
                    }
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_E_STEP2_1;
                }
            }
            break;
        case RTC_INTERNAL_SET_STEP3:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    tRtc_DriverHandler.u32FaultCount = 0;
                    tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_OK;
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_E_STEP3;
                }
            }
            break;
        case RTC_INTERNAL_SET_E_STEP1:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;

            }
            break;
        case RTC_INTERNAL_SET_E_STEP2_1:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;

            }
            break;
        case RTC_INTERNAL_SET_E_STEP3:
        case RTC_INTERNAL_SET_E_STEP2_2:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                    (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
                    u8TransmitBuffer[0] = RTC_REG_SEC;
                    time = localtime(&tRtc_DriverHandler.tRequest.UTC_Time);
                    u8TransmitBuffer[1] = RTC_DEC2BCD((uint8)time->tm_sec);
                    u8TransmitBuffer[2] = RTC_DEC2BCD((uint8)time->tm_min);
                    u8TransmitBuffer[3] = RTC_DEC2BCD((uint8)time->tm_hour);
                    u8TransmitBuffer[4] = wday2Impl[((uint8)time->tm_wday&(uint8)0x0F)];
                    u8TransmitBuffer[5] = RTC_DEC2BCD((uint8)time->tm_mday);
                    u8TransmitBuffer[6] = RTC_DEC2BCD((uint8)time->tm_mon+1);
                    u8TransmitBuffer[7] = RTC_DEC2BCD((uint8)(time->tm_year-100));// years since 2000;
                    ret = RI_QueueTxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,8);
                    if (eIIC_Return_Success == ret)
                    {
                        tRtc_DriverHandler.u32FaultCount = 0;
                        tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_SET_STEP3;
                    }
                    else
                    {
                        tRtc_DriverHandler.u32FaultCount++;
                    }
                
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;

            }
            break;
        default:
            /*Nothing to do*/
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
STATIC void RTC_CommandFromGetTime(void)
{
    IIC_Return_t ret = eIIC_Return_Error;
    IIC_ResultStatus_t state = 0;
    struct tm time = {0};
//    RTC_DEBUG(">>RTC internal status : %d\n",tRtc_DriverHandler.tInternalStatus);
    switch(tRtc_DriverHandler.tInternalStatus)
    {
        
        case RTC_INTERNAL_STAR:
        case RTC_INTERNAL_GET_STEP1:
            (void)memset(u8TransmitBuffer,0,TRANSMIT_BUFFER_SZIE);
            u8TransmitBuffer[0] = RTC_REG_SEC;
            ret = RI_QueueRxReq(eIIC_DeviceID_RTC,u8TransmitBuffer,1,7);
            if (eIIC_Return_Success == ret)
            {
                tRtc_DriverHandler.u32FaultCount = 0;
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_GET_STEP2;
            }
            else
            {
                
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_GET_E_STEP1;
            }
            break;
        case RTC_INTERNAL_GET_STEP2:
            if (TRUE == RTC_WaitResult(&state))
            {
                if (eIIC_ResultStatus_Success == state)
                {
                    tRtc_DriverHandler.u32FaultCount = 0;
                    time.tm_sec = RTC_BCD2DEC(u8TransmitBuffer[0]);
                    time.tm_min = RTC_BCD2DEC(u8TransmitBuffer[1]);
                    time.tm_hour = RTC_BCD2DEC(u8TransmitBuffer[2]);
                    time.tm_mday = RTC_BCD2DEC(u8TransmitBuffer[4]);
                    time.tm_mon = RTC_BCD2DEC(u8TransmitBuffer[5]);
                    time.tm_year = RTC_BCD2DEC(u8TransmitBuffer[6]);
                    time.tm_mon = time.tm_mon - 1;
                    time.tm_year = time.tm_year + 100;
                    time.tm_isdst = -1;

                    tRtc_DriverHandler.tRequest.UTC_Time = mktime(&time);
                    tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_OK;
                    
                }
                else
                {
                    tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_GET_E_STEP2;
                }
            }
            break;
        case RTC_INTERNAL_GET_E_STEP1:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_GET_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;

            }
            break;
        case RTC_INTERNAL_GET_E_STEP2:
            if (tRtc_DriverHandler.u32FaultCount < RTC_RETRY_CNT)
            {
                tRtc_DriverHandler.tInternalStatus = RTC_INTERNAL_GET_STEP1;
                tRtc_DriverHandler.u32FaultCount++;
            }
            else
            {
                tRtc_DriverHandler.tRequest.tStatus = eRTC_STATUS_ERROR;

            }
            break;
        default:
            /*Nothing to do*/
            break;
    }
}

void RTC_Driver_Impl_Init(void)
{
    bRTC_IsInit = FALSE;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/

void RTC_Driver_Impl_MainFunction(void)
{
    
    if (FALSE == bRTC_IsInit)
    {
        if (eRTC_STATUS_BUSY != tRtc_DriverHandler.tRequest.tStatus)
        {
            if (u32InitCnt == 0)
            {
                u32InitCnt = (60 * 1000) / TASK_PERIOD;
                RTC_RequestExecute(eRTC_CMD_INIT,0);
            }
            else
            {
                u32InitCnt--;
            }
        }
    }

    if (eRTC_STATUS_BUSY == tRtc_DriverHandler.tRequest.tStatus)
    {
        if (tRtc_DriverHandler.tRequest.tCommandEvent < eRTC_CMD_NUMBER)
        {
//            RTC_DEBUG("RTC internal command : %d\n",tRtc_DriverHandler.tInternalStatus);
            if (NULL_PTR!=cCommandFunctionTable[tRtc_DriverHandler.tRequest.tCommandEvent])
            {
                cCommandFunctionTable[tRtc_DriverHandler.tRequest.tCommandEvent]();
            }
        }
        else
        {
            tRtc_DriverHandler.tRequest.tCommandEvent = 0;
            tRtc_DriverHandler.tRequest.tStatus = 0;
        }
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean RTC_Driver_Impl_IsInit(void)
{
    return bRTC_IsInit;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
RTC_Return_t RTC_Impl_SynchronizationTime(void)
{
    RTC_Return_t ret = eRTC_Return_E_Error;

    if (FALSE == bRTC_IsInit)
    {
        ret = eRTC_Return_E_Uninit;
    }
    else if (eRTC_STATUS_BUSY == tRtc_DriverHandler.tRequest.tStatus)
    {
        ret = eRTC_Return_E_BUSY;
    }
    else
    {
        RTC_RequestExecute(eRTC_CMD_SYNCH_TIME,0);
        ret = eRTC_Return_Seccess;
    }
    return ret;
}




/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
RTC_Return_t RTC_Impl_SetTime(const     time_t time)
{
    RTC_Return_t ret = eRTC_Return_E_Error;

    if (FALSE == bRTC_IsInit)
    {
        ret = eRTC_Return_E_Uninit;
    }
    else if (eRTC_STATUS_BUSY == tRtc_DriverHandler.tRequest.tStatus)
    {
        ret = eRTC_Return_E_BUSY;
    }
    else
    {
        RTC_RequestExecute(eRTC_CMD_SET_TIME,time);
        ret = eRTC_Return_Seccess;
    }

    return ret;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Rtc_Status_t RTC_Impl_ReadResult(time_t * time)
{
    *time = tRtc_DriverHandler.tRequest.UTC_Time;
    return tRtc_DriverHandler.tRequest.tStatus;
}



void RTC_Rx_Callback(IIC_ResultStatus_t state, const uint8 * pu8buf, uint16 size)
{
    tRtc_DriverHandler.tResult.tState = state;
    tRtc_DriverHandler.tResult.bIsUpdata = TRUE;
    RTC_TraceMainFunction();
}
void RTC_Tx_Callback(IIC_ResultStatus_t state)
{
    tRtc_DriverHandler.tResult.tState = state;
    tRtc_DriverHandler.tResult.bIsUpdata = TRUE;
    RTC_TraceMainFunction();
}


