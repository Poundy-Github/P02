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
 * @file:      AMP_LCCalib.c
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

#include "AMP.h"
#include "AMP_LCCalib.h"
#include "String.h"
#include "logger.h"
#include "Logger_Cfg.h"
#include "AMP_Common.h"
#include "Rte_AMP.h"
#include "AMP_ShutDown.h"
#include "AMP_cfg.h"


#define AMPTIMER_FILTERWAIT                                                 (5000)/*500ms*/
#define AMPTIMER_CHANNELMUTE                                                (300)/*30ms*/
#define LCCALIB_VOLTAGE_MIN                                                 (12000)
#define LCCALIB_VOLTAGE_MAX                                                 (16000)
#define LCCALIB_TEMPETURE_MIN                                               (0)
#define LCCALIB_TEMPETURE_MAX                                               (10000)//UM10820 Guide 70,systemsate Guide 100

#define AMPDIAGCALIB_DIDSUPPORT                                             (0u)
#define AMPDIAGCALIB_DIDNOTSUPPORT                                          (1u)
#define AMPTIMER_RESETWAIT                                                  (20000)/*2S*/


typedef struct
{
    uint8 AMPEOLStatus;
    uint8 CH1Status;
    uint8 CH2Status;
    uint8 CH3Status;
    uint8 CH4Status;
}s_EOLReportType;

typedef struct
{
    uint8 AMPDIDStatus;
    uint8 CH1Status;
    uint8 CH2Status;
    uint8 CH3Status;
    uint8 CH4Status;
}s_DIDReportType;

typedef struct
{
    uint8 KSet[4];
    uint8 Calibed;
}s_NVMDataType;

#define AMP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"

static s_LCCalib_Type LCCalib_Data[DEVICE_NUM];
extern I2C_AMPReq_t I2C_Req_AMPData[DEVICE_NUM];


static s_EOLReportType EOLReportValue[DEVICE_NUM] = {{AMODIAGCALIB_NOTCALIB,0,0,0,0},{AMODIAGCALIB_NOTCALIB,0,0,0,0}};
static s_DIDReportType DIDReportValue[DEVICE_NUM];
static uint16 Eol_CalibCmd = 0u;
static uint16 Eol_PreCalibCmd = 0u;
static s_NVMDataType CalibNVMData[DEVICE_NUM];
static s_LCCalib_Info_Type LCCalib_Info[DEVICE_NUM];

#define AMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "AMP_MemMap.h"



#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

static boolean LCCalib_EvenmentCheck(uint8 dev_id);
static Std_ReturnType LCCalib_FilterWaitCallback(uint8 dev_id);
static Std_ReturnType LCCalib_GetTempCallback(uint8 dev_id);
static Std_ReturnType LCCalib_GetVoltageCallback(uint8 dev_id);
static Std_ReturnType LCCalib_GetDeviceStateCallback(uint8 dev_id);
static Std_ReturnType LCCalib_GetFaultStateCallback(uint8 dev_id);
static Std_ReturnType LCCalib_ChannelStateCallback(uint8 dev_id);
static Std_ReturnType LCCalib_NVMWrite(uint8 dev_id);
static Std_ReturnType LCCalib_NVMRead(uint8 dev_id);
static Std_ReturnType LCCalib_CalibDoneCallback(uint8 dev_id);
static Std_ReturnType LCCalib_ChannelMuteCallback(uint8 dev_id);
static void LCCalib_CalculateK(uint8 dev_id);
static void LCCalibEolTrigger(uint8 dev_id);
static void LCCalibWaitHW(uint8 dev_id); 
static void EOLDataUpdate(uint8 dev_id);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"




#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void LCCalib_Init(uint8 dev_id)
{
	u_AMPChannelCfg_t AMPchSuppotSts;

	AMPchSuppotSts = AMP_ChannelCfg(dev_id);
    (void)memset(&LCCalib_Info[dev_id], 0, sizeof(s_LCCalib_Info_Type));
    (void)LCCalib_NVMRead(dev_id);
    LCCalib_Data[dev_id].LCCalibRet = AMPCALIBINIT;
    LCCalib_Data[dev_id].LCCalibStep = AMPLCCalib_ChannelMute;
	LCCalib_Data[dev_id].ChannelAlarm[0].Alarm.Supported = AMPchSuppotSts.Channel.CH1;
	LCCalib_Data[dev_id].ChannelAlarm[1].Alarm.Supported = AMPchSuppotSts.Channel.CH2;
	LCCalib_Data[dev_id].ChannelAlarm[2].Alarm.Supported = AMPchSuppotSts.Channel.CH3;
	LCCalib_Data[dev_id].ChannelAlarm[3].Alarm.Supported = AMPchSuppotSts.Channel.CH4;

    if(VCONFIG_NONE == AMPDevVCfg)
    {
        EOLReportValue[DEVICE_AMP1].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
        EOLReportValue[DEVICE_AMP2].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
    }
	else if(VCONFIG_ONLYAMP1 == AMPDevVCfg)
    {
        EOLReportValue[DEVICE_AMP2].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
    }
	else if(VCONFIG_ONLYAMP2 == AMPDevVCfg)
    {
        EOLReportValue[DEVICE_AMP1].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
    }
	else
	{
		/* do nothing */
	}

    DIDDataReport();
}

/***********************************************************************
 * @brief       : read LCCalib data from nvm
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_NVMRead(uint8 dev_id)
{
    uint8 *ptr;
    A_u8_20 LCCalibResult;
    if(dev_id == DEVICE_AMP1)
    {
        ptr = Rte_Pim_NvBlockNeed_LC_Calibration_MirrorBlock();
    }
    else
    {
        ptr = Rte_Pim_NvBlockNeed_LC_Calibration2_MirrorBlock();        
    }
    (void)memcpy(LCCalibResult,ptr,sizeof(A_u8_20));
    CalibNVMData[dev_id].Calibed = LCCalibResult[4];
    (void)memcpy(&CalibNVMData[dev_id].KSet[0],&LCCalibResult[0],4);
    AMP_ReadNVMKValue(dev_id, LCCalibResult);
    (void)amp_warn("AMP%d NVMRData: %d %d %d %d %d", dev_id+1,CalibNVMData[dev_id].KSet[0],CalibNVMData[dev_id].KSet[1],
					CalibNVMData[dev_id].KSet[2],CalibNVMData[dev_id].KSet[3],CalibNVMData[dev_id].Calibed);
    return E_OK;
}

/***********************************************************************
 * @brief       : get device tempeture state
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static  Std_ReturnType LCCalib_CalibDoneCallback(uint8 dev_id)
{
    LCCalib_Data[dev_id].LCCalibRet = AMPCALIBSUCCESS;
    EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_SUCCESS;
    EOLReportValue[dev_id].CH1Status = CalibNVMData[dev_id].KSet[0];
    EOLReportValue[dev_id].CH2Status = CalibNVMData[dev_id].KSet[1];
    EOLReportValue[dev_id].CH3Status = CalibNVMData[dev_id].KSet[2];
    EOLReportValue[dev_id].CH4Status = CalibNVMData[dev_id].KSet[3];
    DIDReportValue[dev_id].CH1Status = CalibNVMData[dev_id].KSet[0];
    DIDReportValue[dev_id].CH2Status = CalibNVMData[dev_id].KSet[1];
    DIDReportValue[dev_id].CH3Status = CalibNVMData[dev_id].KSet[2];
    DIDReportValue[dev_id].CH4Status = CalibNVMData[dev_id].KSet[3];
    AMP_CALIBLOG("AMP%d Calib Step Finished", dev_id + 1);
    return E_OK;
}

/***********************************************************************
 * @brief       : get device tempeture state
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_GetTempCallback(uint8 dev_id)
{
    LCCalib_Info[dev_id].tempeture = (sint16)(((uint16)I2C_Req_AMPData[dev_id].Data[5] << 8) + (uint16)(I2C_Req_AMPData[dev_id].Data[6]));
    (void)amp_info("AMP%d LCCalib Tempeture is %d /100", dev_id + 1, LCCalib_Info[dev_id].tempeture);

    if(LCCalib_Info[dev_id].tempeture >= LCCALIB_TEMPETURE_MAX)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturehigh = 1u;
        (void)amp_err("AMP%d LC Calib chip tempeture is %ld, More than %ld",dev_id + 1, LCCalib_Info[dev_id].tempeture, LCCALIB_TEMPETURE_MAX);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturehigh = 0u;
    }
    
    if(LCCalib_Info[dev_id].tempeture <= LCCALIB_TEMPETURE_MIN)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturelow = 1u;
        (void)amp_err("AMP%d LC Calib chip tempeture is %ld, Less than %ld",dev_id + 1, LCCalib_Info[dev_id].tempeture, LCCALIB_TEMPETURE_MIN);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturelow = 0u;
    }
    
    return E_OK;
}

/***********************************************************************
 * @brief       : get device voltage state
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_GetVoltageCallback(uint8 dev_id)
{
    LCCalib_Info[dev_id].voltage = ((uint16)I2C_Req_AMPData[dev_id].Data[5] << 8) + (uint16)I2C_Req_AMPData[dev_id].Data[6];
    (void)amp_info("AMP%d LCCalib Voltage is %ld", dev_id + 1, LCCalib_Info[dev_id].voltage);
    if(LCCalib_Info[dev_id].voltage > LCCALIB_VOLTAGE_MAX)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagehigh = 1u;
        (void)amp_err("AMP LC Calibration supply voltage is %ld, more than %ld", LCCalib_Info[dev_id].voltage, LCCALIB_VOLTAGE_MAX);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagehigh = 0u;
    }
    
    if(LCCalib_Info[dev_id].voltage < LCCALIB_VOLTAGE_MIN)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagelow = 1u;
        (void)amp_err("AMP LC Calibration supply voltage is %ld, less than %ld", LCCalib_Info[dev_id].voltage, LCCALIB_VOLTAGE_MIN);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagelow = 0u;
    }
    
    return E_OK;
}

/***********************************************************************
 * @brief       : get AMP device state
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_GetDeviceStateCallback(uint8 dev_id)
{
    uint8 AMP_DeviceState = I2C_Req_AMPData[dev_id].Data[5];

    if(AMP_DeviceState != AMP_PLAYING)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.devicestateerr = 1u;
        (void)amp_err("AMP%d LC Calibration chip state is %d, not %d", dev_id + 1, AMP_DeviceState, AMP_PLAYING);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.devicestateerr = 0u;
        (void)amp_info("AMP%d LC Calibration AMP in Playing State", dev_id + 1);
    }
    
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_GetFaultStateCallback(uint8 dev_id)
{
    uint16 Device_Fault = ((uint16)I2C_Req_AMPData[dev_id].Data[5] << 8) + (uint16)I2C_Req_AMPData[dev_id].Data[6];

    if(Device_Fault != 0u)
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.DeviceFault = 1u;
        (void)amp_err("AMP%d LC Calibration fault state have fault , the fault is %d",dev_id + 1,Device_Fault);
    }
    else
    {
        LCCalib_Data[dev_id].DeviceAlarm.Alarm.DeviceFault = 0u;
        (void)amp_info("AMP%d LC Calibration NO fault",dev_id + 1);
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_ChannelStateCallback(uint8 dev_id)
{
    uint8 ChannelID;
	uint8 ChannelSts;
	
    for(ChannelID = 0u;ChannelID < CHANNEL_NUM;ChannelID ++)
    {
        ChannelSts = I2C_Req_AMPData[dev_id].Data[10 + (6 *ChannelID)];
        if(ChannelSts != 0u)
        {
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.ChannelErr = 1u;
            (void)amp_info("AMP%d Channel%d channel status is %d", dev_id + 1, ChannelID, ChannelSts);
        }
        else
        {
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.ChannelErr = 0u;
        }
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_FilterDiagResultCallback(uint8 dev_id)
{
    uint8 ChannelID;
	uint8 FilterResult;
	
    for(ChannelID = 0u;ChannelID < CHANNEL_NUM;ChannelID ++)
    {
        FilterResult = I2C_Req_AMPData[dev_id].Data[10+ (ChannelID * 5)];
        if(FilterResult == 0u)
        {
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kvalue = I2C_Req_AMPData[dev_id].Data[7 + (ChannelID * 5)];
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmin   = I2C_Req_AMPData[dev_id].Data[8 + (ChannelID * 5)];
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmax   = I2C_Req_AMPData[dev_id].Data[9 + (ChannelID * 5)];
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.FilterErr = 0u;
            
            if(LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kvalue)
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KvalErr   = 0u;
            }
            else
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KvalErr   = 1u;
            }

            if(LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmax)
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KmaxErr   = 0u;
            }
            else
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KmaxErr   = 1u;
            }

            if(LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmin)
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KminErr   = 0u;
            }
            else
            {
                LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KminErr   = 1u;
            }
        }
        else
        {
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kvalue = 0u;
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmin   = 0u;
            LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmax   = 0u;
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.FilterErr = 1u;
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KmaxErr   = 1u;
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KminErr   = 1u;
            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KvalErr   = 1u;
            (void)amp_err("AMP%d LC Calib channel %d have fault , the fault is %d", dev_id + 1, ChannelID, FilterResult);
        }

		if( 0u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.Supported )
		{
			LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kvalue = 0u;
			LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmin	= 0u;
			LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmax	= 0u;
			LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.FilterErr = 0u;
			LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KmaxErr	 = 0u;
			LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KminErr	 = 0u;
			LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KvalErr	 = 0u;
		}
    }
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_ChannelMuteCallback(uint8 dev_id)
{
    Std_ReturnType ret = E_NOT_OK;
    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_CHANNELMUTE))
        {
            AMP_TimerEnd(dev_id);
            ret = E_OK;
            AMP_CALIBLOG("AMP%d Calib ChannelMute wait %dms Success", dev_id + 1, AMPTIMER_CHANNELMUTE / 10);
        }
    }
    else
    {
        AMP_TimerStart(dev_id);
        AMP_CALIBLOG("AMP%d Calib ChannelMute Timer Start Success", dev_id + 1);
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_FilterWaitCallback(uint8 dev_id)
{
    Std_ReturnType ret = E_NOT_OK;
    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_FILTERWAIT))
        {
            AMP_TimerEnd(dev_id);
            AMP_CALIBLOG("AMP%d Calib Filter Diag End", dev_id + 1);
            ret = E_OK;
        }
    }
    else
    {
        AMP_TimerStart(dev_id);
        AMP_CALIBLOG("AMP%d Calib Filter Diag Timer Start", dev_id + 1);
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static boolean LCCalib_EvenmentCheck(uint8 dev_id)
{
    boolean ret = FALSE;

    if( 0u == LCCalib_Data[dev_id].DeviceAlarm.Data )
    {
        ret = TRUE;
        AMP_CALIBLOG("AMP%d Calib Check Environment No Error", dev_id + 1);
    }
    else
    {
        AMP_CALIBLOG("AMP%d Calib Check Environment Have Error", dev_id + 1);
    }
    return ret;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void LCCalib_CalculateK(uint8 dev_id)
{
    uint8 ChannelID;
    uint8 KmaxTemp; 
    uint8 KminTemp;

    for(ChannelID = 0u; ChannelID < CHANNEL_NUM; ChannelID++)
    {
    	if( 0u != LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.Supported )
    	{
	        KmaxTemp = LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmax;
	        KminTemp = LCCalib_Data[dev_id].FilterDiagResult[ChannelID].Kmin;
	        if((KmaxTemp - KminTemp) < 20u)
	        {
	            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KOutofRange = 1u;
				LCCalib_Data[dev_id].KSet[ChannelID] = CalibNVMData[dev_id].KSet[ChannelID];
	            (void)amp_err("AMP%d Channel%d LC Calib Kdelta is %d too small need repair", dev_id + 1, ChannelID, KmaxTemp - KminTemp);
	        }
	        else
	        {
	            LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KOutofRange = 0u;
	            if((KmaxTemp - KminTemp) <= 22u)
	            {
	                LCCalib_Data[dev_id].KSet[ChannelID] = KminTemp + 4u;
	            }
	            else
	            {
	                LCCalib_Data[dev_id].KSet[ChannelID] = KminTemp + ((KmaxTemp - KminTemp - 10u)/3u);
	            }
	            AMP_CALIBLOG("AMP%d Channel%d Calib KValue is 0x%x", dev_id + 1, ChannelID, LCCalib_Data[dev_id].KSet[ChannelID]);  
	        }
    	}
		else
		{
			LCCalib_Data[dev_id].KSet[ChannelID] = CalibNVMData[dev_id].KSet[ChannelID];
		}
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static Std_ReturnType LCCalib_NVMWrite(uint8 dev_id)
{
    if(FALSE == LCCalib_Info[dev_id].LCNVMPending)
    {
        uint8 *prt;
        uint8 NVMReqResult;
        A_u8_20 LCCalibResult;
        Std_ReturnType ret = E_OK; 

        (void)memset(LCCalibResult, 0, sizeof(A_u8_20));
        LCCalibResult[4] = CalibNVMData[dev_id].Calibed;
        (void)memcpy(LCCalibResult, CalibNVMData[dev_id].KSet, 4);
    
        if(AMPCALIBSUCCESS == LCCalib_Data[dev_id].LCCalibRet)
        {
            LCCalibResult[4] = TRUE;
            (void)memcpy(&LCCalibResult[0], &LCCalib_Data[dev_id].KSet[0],4);
        }  

        if(DEVICE_AMP1 == dev_id)    
        {
            prt = Rte_Pim_NvBlockNeed_LC_Calibration_MirrorBlock();
        }
        else
        {
            prt = Rte_Pim_NvBlockNeed_LC_Calibration2_MirrorBlock();        
        }
        AMP_CALIBLOG("AMP%d write NVM Data is:", dev_id + 1);
        AMPArrayPrint(LCCalibResult,20u);

        (void)memcpy(prt,&LCCalibResult,sizeof(A_u8_20));

        if(DEVICE_AMP1 == dev_id)  
        {
            if(E_OK == Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_GetErrorStatus(&NVMReqResult))
            {
                if(NVM_REQ_PENDING != NVMReqResult)
                {
                    (void)Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_WriteBlock(NULL);
                    ret = E_OK;
                }
            }
        }
        else
        {
            if(E_OK == Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_GetErrorStatus(&NVMReqResult))
            {
                if(NVM_REQ_PENDING != NVMReqResult)
                {
                    (void)Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_WriteBlock(NULL);
                    ret = E_OK;
                }
            }
        }

        LCCalib_Info[dev_id].LCNVMPending = TRUE;
        return ret;
    }
    else
    {
        return E_OK;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void LCCalib_Logic(uint8 dev_id)
{
    switch(LCCalib_Data[dev_id].LCCalibStep)
    {
        case AMPLCCalib_ChannelMute:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)SET_CHANNEL_MUTE);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_SetLCFilterCfg,(uint8)AMPLCCalib_Err,LCCalib_ChannelMuteCallback);
            break;

        case AMPLCCalib_SetLCFilterCfg:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)Set_LCFilterCfg);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_SetFilterDiag1,(uint8)AMPLCCalib_Err,NULL);         
            break;

        case AMPLCCalib_SetFilterDiag1:
            AMPSet_LCCalibStep(dev_id,(uint8)LCCalib_Data[dev_id].LCCalibStep);
            AMP_I2C_Req_State_Oper(dev_id,(uint8)Set_FILTERDAIG);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetTemp,(uint8)AMPLCCalib_Err,LCCalib_FilterWaitCallback);
            break;

        case AMPLCCalib_GetTemp:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_TEMPETURE);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetVoltage,(uint8)AMPLCCalib_Err,LCCalib_GetTempCallback);
            break;

        case AMPLCCalib_GetVoltage:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_SUPPLYVOLTAGE);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetDeviceState,(uint8)AMPLCCalib_Err,LCCalib_GetVoltageCallback);
            break;

        case AMPLCCalib_GetDeviceState:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_DEVICESTATE);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetFaultStatus,(uint8)AMPLCCalib_Err,LCCalib_GetDeviceStateCallback);
            break;

        case AMPLCCalib_GetFaultStatus:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_FAULTSTATE);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetChannleStatus,(uint8)AMPLCCalib_Err,LCCalib_GetFaultStateCallback);

            break;
        case AMPLCCalib_GetChannleStatus:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_CHANNELSTATUS);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_GetFilterDiagResult,(uint8)AMPLCCalib_Err,LCCalib_ChannelStateCallback);
            break;

        case AMPLCCalib_GetFilterDiagResult:
            AMP_I2C_Req_State_Oper(dev_id,(uint8)GET_FILTERDIAGRESULT);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_EveironmentCheck,(uint8)AMPLCCalib_Err,LCCalib_FilterDiagResultCallback);
            break;

        case AMPLCCalib_EveironmentCheck:
            if(TRUE == LCCalib_EvenmentCheck(dev_id))
            {
                 LCCalib_Data[dev_id].LCCalibStep = AMPLCCalib_Kvalue;
            }
            else
            {
                LCCalib_Data[dev_id].LCCalibRet = AMPCALIBERR;
                LCCalib_Data[dev_id].LCCalibStep = AMPLCCalib_Done;
            } 
            break;

        case AMPLCCalib_Kvalue:
            LCCalib_CalculateK(dev_id);
            LCCalib_Data[dev_id].LCCalibStep = AMPLCCalib_SetFilterDiag2;
            break;

        case AMPLCCalib_SetFilterDiag2:
            AMPSet_LCCalibStep(dev_id,(uint8)LCCalib_Data[dev_id].LCCalibStep);
            AMP_I2C_Req_State_Oper(dev_id,(uint8)Set_FILTERDAIG);
            AMP_StateIICCallback(&LCCalib_Data[dev_id].LCCalibStep,dev_id,(uint8)AMPLCCalib_Done,(uint8)AMPLCCalib_Err,LCCalib_CalibDoneCallback);
            break;

        case AMPLCCalib_Done:
            (void)LCCalib_NVMWrite(dev_id);
            break;

        case AMPLCCalib_WaitHW:
            LCCalibWaitHW(dev_id);
            break;

        case AMPLCCalib_Err:
			EOLReportValue[dev_id].AMPEOLStatus = AMODIAGCALIB_IICERR;
            break;

        default:
			/* do nothing */
            break;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
Std_ReturnType LCCalib_MainLogic(uint8 dev_id)
{
    LCCalib_Logic(dev_id);
    DIDDataReport();
    return E_OK;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void LCCalibNVMWriteDone(uint8 dev_id) 
{    
    AMP_EmergencyShutdownOneDevice(dev_id);
    LCCalib_Data[dev_id].LCCalibStep = AMPLCCalib_WaitHW;
    (void)LCCalib_NVMRead(dev_id);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void AMPDiag_LCCalibLogic(void)
{
	/* 31 01 service, RoutineControl Start */
    (void)Rte_Read_EOL_AMPCalibration_AMPCalibration(&Eol_CalibCmd);
    if( ( 1u == Eol_CalibCmd ) && ( Eol_PreCalibCmd != Eol_CalibCmd ) )
    {
        (void)amp_info("AMP Calib Trigger");
        if(VCONFIG_NONE != AMPDevVCfg) 
        {
            if(VCONFIG_BOTHAMP == AMPDevVCfg)
            {
                LCCalibEolTrigger(DEVICE_AMP1);
                LCCalibEolTrigger(DEVICE_AMP2);               
            }
            else if(VCONFIG_BOTHAMP > AMPDevVCfg)
            {
                LCCalibEolTrigger(AMPDevVCfg);
            }
			else
			{
				/* do nothing */
			}
        }
    }
	Eol_PreCalibCmd = Eol_CalibCmd;
}

/***********************************************************************
 * @brief       : 31 03 service, RoutineControl Read
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void EOLDataReport(A_U8_10 *ptr) 
{
    if(VCONFIG_ONLYAMP1 == AMPDevVCfg)
    {
        EOLReportValue[DEVICE_AMP2].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
    }
    else if(VCONFIG_ONLYAMP2 == AMPDevVCfg)
    {
        EOLReportValue[DEVICE_AMP1].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
    }
    else if(VCONFIG_NONE == AMPDevVCfg)
    {
        (void)memset(&EOLReportValue,0,sizeof(EOLReportValue));
        EOLReportValue[DEVICE_AMP1].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
        EOLReportValue[DEVICE_AMP2].AMPEOLStatus = AMODIAGCALIB_NOTSUPPORT;
        (void)memcpy(ptr,&EOLReportValue,sizeof(EOLReportValue));
    }
	else
	{
		/* do nothing */
	}

    if(AMPDevVCfg != VCONFIG_NONE)
    {
    	EOLDataUpdate(DEVICE_AMP1);
		EOLDataUpdate(DEVICE_AMP2);
        (void)memcpy(ptr,&EOLReportValue,sizeof(EOLReportValue));
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void EOLDataUpdate(uint8 dev_id)
{
    uint8 ChannelID;

	/*communication with system enginer, voltage have high priority*/
	if( (1u == LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagehigh) ||
	    (1u == LCCalib_Data[dev_id].DeviceAlarm.Alarm.voltagelow) )
	{
		EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_VOLTAGEOUTOFRANGE;
	}
	else if( (1u == LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturehigh) ||
	         (1u == LCCalib_Data[dev_id].DeviceAlarm.Alarm.tempeturelow) )
	{
		EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_TEMPOUTOFRANGE; 
	}
	else
	{
		for( ChannelID = 0u; ChannelID < CHANNEL_NUM; ChannelID++ )
		{
			if( 0u != LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.Supported )
			{
				if( 1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KOutofRange )
				{
					EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_KDELTAOUTOFRANGE;
					(void)amp_info("amp%d channel%d KDELTAOUTOFRANGE", dev_id + 1, ChannelID+1);
				}
				else if( 1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.ChannelErr)
				{
					EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_CHANNELERR;
					(void)amp_info("amp%d channel%d ChannelAlarm_Err", dev_id + 1, ChannelID+1);
				}
				else if( 1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.FilterErr )
				{
					EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_FILTERERR;
					(void)amp_info("amp%d channel%d ChannelFilter_Err", dev_id + 1, ChannelID+1);
				}
				else if(
				  (1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KminErr)	||\
				  (1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KmaxErr)	||\
				  (1u == LCCalib_Data[dev_id].ChannelAlarm[ChannelID].Alarm.KvalErr) )
				{
					EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_KVALERR;
					(void)amp_info("amp%d channel%d ChannelAlarm_Err", dev_id + 1, ChannelID+1);
				}
				else
				{
					/* do nothing */
				}
			}   
		}
	}

	if(AMPDIAGCALIB_SUCCESS != EOLReportValue[dev_id].AMPEOLStatus)
	{
		EOLReportValue[dev_id].CH1Status = 0u;
		EOLReportValue[dev_id].CH2Status = 0u;
		EOLReportValue[dev_id].CH3Status = 0u;
		EOLReportValue[dev_id].CH4Status = 0u;
	}
	else
	{
		EOLReportValue[dev_id].CH1Status = CalibNVMData[dev_id].KSet[0];
		EOLReportValue[dev_id].CH2Status = CalibNVMData[dev_id].KSet[1];
		EOLReportValue[dev_id].CH3Status = CalibNVMData[dev_id].KSet[2];
		EOLReportValue[dev_id].CH4Status = CalibNVMData[dev_id].KSet[3];
	}
}

/***********************************************************************
 * @brief       : 22 service
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void DIDDataReport(void)
{
    uint8 dev_id;
    uint8 DIDArray_9[9];

    DIDReportValue[DEVICE_AMP1].AMPDIDStatus = AMPDIAGCALIB_DIDNOTSUPPORT;
    DIDReportValue[DEVICE_AMP2].AMPDIDStatus = AMPDIAGCALIB_DIDNOTSUPPORT;

    if(VCONFIG_BOTHAMP == AMPDevVCfg)
    {
    	DIDReportValue[DEVICE_AMP1].AMPDIDStatus = AMPDIAGCALIB_DIDSUPPORT;
        DIDReportValue[DEVICE_AMP2].AMPDIDStatus = AMPDIAGCALIB_DIDSUPPORT;
    }
    else if(VCONFIG_ONLYAMP1 == AMPDevVCfg)
    {
        DIDReportValue[DEVICE_AMP1].AMPDIDStatus = AMPDIAGCALIB_DIDSUPPORT;
    }
    else if(VCONFIG_ONLYAMP2 == AMPDevVCfg)
    {
        DIDReportValue[DEVICE_AMP2].AMPDIDStatus = AMPDIAGCALIB_DIDSUPPORT;
    }
	else
	{
		/* do nothing */
	}

    for(dev_id = DEVICE_AMP1;dev_id < DEVICE_NUM;dev_id ++)
    {
        if( (AMPDIAGCALIB_DIDNOTSUPPORT == DIDReportValue[dev_id].AMPDIDStatus)
			|| (TRUE != CalibNVMData[dev_id].Calibed) )
        {
            DIDReportValue[dev_id].CH1Status = 0u;
            DIDReportValue[dev_id].CH2Status = 0u;
            DIDReportValue[dev_id].CH3Status = 0u;
            DIDReportValue[dev_id].CH4Status = 0u;
        }
        else
        {
            DIDReportValue[dev_id].CH1Status = CalibNVMData[dev_id].KSet[0];
            DIDReportValue[dev_id].CH2Status = CalibNVMData[dev_id].KSet[1];
            DIDReportValue[dev_id].CH3Status = CalibNVMData[dev_id].KSet[2];
            DIDReportValue[dev_id].CH4Status = CalibNVMData[dev_id].KSet[3];
        }
    }
	
    DIDArray_9[0] = (DIDReportValue[DEVICE_AMP1].AMPDIDStatus << 4) + DIDReportValue[DEVICE_AMP2].AMPDIDStatus;
    (void)memcpy(&DIDArray_9[1],&DIDReportValue[DEVICE_AMP1].CH1Status,4);
    (void)memcpy(&DIDArray_9[5],&DIDReportValue[DEVICE_AMP2].CH1Status,4);
    (void)Rte_Write_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(DIDArray_9);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void LCCalibEolTrigger(uint8 dev_id)
{
    if(FALSE == LCCalib_Info[dev_id].LCCalibRequest)
    {
        LCCalib_Info[dev_id].LCCalibRequest = TRUE;
        LCCalib_Data[dev_id].LCCalibRet = AMPCALIBPENGDING;
	    EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_CALIBINPROCESS;
        AMPSet_NextDeviceState(dev_id, AMP_LCCALIB);
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void LCCalibWaitHW(uint8 dev_id) 
{
    if(TRUE == AMP_TimerIsStarted(dev_id))
    {
        if(TRUE == AMP_TimerIsElasped(dev_id,AMPTIMER_RESETWAIT))
        {
			EOLDataUpdate(dev_id);
			if( EOLReportValue[dev_id].AMPEOLStatus == AMPDIAGCALIB_CALIBINPROCESS )
			{
				EOLReportValue[dev_id].AMPEOLStatus = AMPDIAGCALIB_SUCCESS;
			}

            AMP_TimerEnd(dev_id);
            AMPChilpInit(dev_id);
            AMPSet_NextDeviceState(dev_id, AMP_STARTUP);
        }
        else
        {
            /* wait time elasped */
        }
    }
    else
    {
        AMP_TimerStart(dev_id);
    }
}

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

