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
 * @file:      CLI_Commands.c
 * @author:    Nobo
 * @date:      2020-6-8
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-8
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

//=======================================================================
//============================== Headers ================================
//=======================================================================
#include "VariantCfg.h"
#ifdef PLATFOEM_OF_GNSS_USED
#include "GNSS_Alg.h"
#endif
#include "RTC.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Dio.h"
#include "IoHwAb.h"
#include "IoHwAb_Dio_Cfg.h"
#include "IoHwAb_Adc_Cfg.h"

#include "HwConfig.h"
#include "CLI_Commands.h"

#include "uart.h"
#include "logger.h"
#include "Ringbuffer.h"
#include "FreeRTOS_CLI.h"
#include "Ext_Power.h"
#include "GPS_Test.h"
#include "CDD_Test.h"
#include "VersionCfg.h"
#include "ComNoAction.h"
#include "CConfig_Cfg.h"
#include "VConfig_Cfg.h"
#include "VConfig.h"
#ifndef GWM_V35_PROJECT_TYPE_B03
    #include "ComEx_Cfg.h"
#else
    #include "Com_cfg.h"
#endif
#include "CPULoadMeasure.h"
#include "StackMeasure.h"
#include "Ipc_if.h"
#include "SOCManager.h"
#include "SOCManager_RI.h"
#include "SOCManager_Alg.h"
#include "Gyro.h"
#include "Misc_Diag.h"


//=======================================================================
//============================== Defines ================================
//=======================================================================
#define UART_INPUT_BUFFER_MAX_SIZE  1024U

#define cmdASCII_DEL		( 0x7F )
#define cmdASCII_BS			'\b'
#define cmdASCII_NEWLINE	'\n'
#define cmdASCII_HEADLINE	'\r'
#define cmdASCII_STRINGEND	'\0'
#define cmdASCII_SPACE		' '
#define	cmdASCII_TILDE		'~'

#define CLI_COMM_CHECK_STRING(str)          (strncmp(str, pcParameter, strlen(str)) == 0)

enum passwd_state 
{
	PASSWD_INCORRECT = 0,
	PASSWD_CORRECT = 1,
};

union MultDataType {
    uint8  u8data;
    uint16 u16data;
    uint32 u32data;
    uint8  arydata[64];
};


//=======================================================================
//============================== Variables ==============================
//=======================================================================
static char  UartInputBuffer[UART_INPUT_BUFFER_MAX_SIZE];
static char  UartOutputBuffer[UART_INPUT_BUFFER_MAX_SIZE];

static const char * const passwd = "Noch";
static const char * const input_passwd_msg = "Input password: ";
static const char * const incorrect_passwd_msg = "Password incorrect!\r\n";

// MISRA C-2012 Rule 2.2
// static const char * def_prefix = "Terminal ";
// static const char * const pc_new_line = "\r\n";
// static const char * const backspace = " \b";
// const static char *clean_screen = "\033[H\033[J";

static uint16 u16UartInputCnt = 0;
static uint8  u8ExecuteFlag;
static uint8 permission;
static boolean bEcho_Status = TRUE;

static void vRegisterCLICommands(void);

static uint8 * pAdc_Name[]=
{
    "VIP_NTC_MON1_IAN_AD",
    "MICpwr_VIP_Adsense",
    "VIP_TPS7B7702_IAN2_AD",
    "VIP_TPS7B7702_IAN1_AD",
    "VIP_TPS7B7701_IAN_AD",
    "GPSANTpwer_VIP_ADsense_AD",
    "VIP_ANT2_P_Diag_AD",
    "VIP_ANT1_P_Diag_AD",
    "VIP_BC_IAN_AD",
    "VIP_Version_MON2_IAN_AD",
    "VIP_Version_MON1_IAN_AD",
    "VIP_Fuellevel2_IAN_AD",
    "VIP_Fuellevel1_IAN_AD",
    "VIP_VREF_Fuel_IAN_AD",
    "VIP_A1VREF_IAN_AD",
    "VBATT_VIP_DET_ADC_AD",
    "MIC_VIP_SENS2_AD",
    "MIC_VIP_SENS1_N_AD",
    "VIP_NTC_MON2_IAN_AD",
    "MIC_VIP_SENS2_N_AD",
    "MIC_VIP_SENS1_AD",
    "VIP_NTC_MON3_IAN_AD",
};
	
static const char * soc_state[] = {
    "None",
    "ON",
    "OFF",
    "Reset",
    "DownloadMode",
    "ResetMCU",
    "Reset2MiniSys",
    "Transition",
};
	
extern const struct Logger_Cfg logger_cfg;
extern const CNA_ConfigType cna_config;
extern VConfig_Type vConfig;
extern CConfig_Type cConfig;

//=======================================================================
//============================== Functions ==============================
//=======================================================================
extern Std_ReturnType RTC_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t * date); /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
extern sSOCManager_Alg_Context_t * SOCManager_Alg_Get_Context(void);
extern GYRO_SENSOR_t * GetGyroSensor(void);
extern GYRO_DATA_t * GetGyroSensorData(void);
extern Std_ReturnType CNA_SignalSet(uint16 signalId, uint8 *value);

#ifndef GWM_V35_PROJECT_TYPE_B03
/* Nobo ComEx Frame */
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length);
extern FUNC(Std_ReturnType, ComEx_CODE) ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length);
extern const ComEx_RxSigInfoType ComEx_RxSigInfo[ComEx_RxSignalSize];
extern const ComEx_TxSigInfoType ComEx_TxSigInfo[ComEx_TxSignalSize];
#else 
/* Vector Com Frame */
extern FUNC(uint8, COM_CODE) Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_VAR) SignalDataPtr);
extern FUNC(uint8, COM_CODE) Com_SendSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr);
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId);
#endif

extern void GPS_ReadPDTINFO(void);


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
boolean IsDigitStr(char const  * src, sint32 len)
{
    sint32 i;
    boolean bRet = FALSE;
    if (src[0] == '\0')
    {
        bRet = FALSE;
    }
    else
    {
        for (i=0; i<len; i++)
        {
            if(src[i] == '\0')
            {
                bRet = TRUE;
                break;
            }
            else if ((src[i]<'0' )||(src[i]>'9'))
            {
                bRet = FALSE;
                break;
            }
        }
        if (i == len)
        {
            bRet = TRUE;
        }
    }
    return bRet;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CLI_Init(void)
{
    RB_Init(RB_ID_CMD_INPUT);
    u16UartInputCnt = 0;
    u8ExecuteFlag = 0;
    bEcho_Status = TRUE;
    permission = (uint8)PASSWD_INCORRECT;
    memset(UartInputBuffer,0,sizeof(UartInputBuffer));
    memset(UartOutputBuffer,0,sizeof(UartOutputBuffer));
    vRegisterCLICommands();
    
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CDD_Test_UartRxCallback(Uart_Id_t id, uint8 ch)
{
    CLI_ENTER_CRITICAL();
    RB_Push(RB_ID_CMD_INPUT, &ch, 1);
    CLI_EXIT_CRITICAL();
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvSetEchoCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    pcParameter = FreeRTOS_CLIGetParameter
                                (
                                    pcCommandString,
                                    1,
                                    &lParameterStringLength
                                );

    if ( strncmp( pcParameter, "on", strlen( "on" ) ) == 0 )
    {
        bEcho_Status = TRUE;
    }
    else if ( strncmp( pcParameter, "off", strlen( "off" ) ) == 0 )
    {
        bEcho_Status = FALSE;
    }
    else
    {
        sprintf( pcWriteBuffer, "Valid parameters are 'on' and 'off'.\r\n" );
    }

    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvSetOutputCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    uint16 PortId = 0;
    uint16  lev;
    BaseType_t lParameterStringLength;

    pcParameter = FreeRTOS_CLIGetParameter
                            (
                                pcCommandString,
                                1,
                                &lParameterStringLength
                            );
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        PortId = atoi(pcParameter);
    }
    else
    {
        sprintf( pcWriteBuffer, " Parameter 1 Valid parameters are digit.\r\n" );
        return 0;
    }
    pcParameter = FreeRTOS_CLIGetParameter
                        (
                            pcCommandString,
                            2,
                            &lParameterStringLength
                        );
   if (IsDigitStr(pcParameter, lParameterStringLength))
   {
       lev = atoi(pcParameter);
   }
   else
   {
       sprintf( pcWriteBuffer, " Parameter 2 Valid parameters are digit.\r\n" );
       return 0;
   }
    if (PortId < DIO_CHANNEL_ARRAY_SIZE)
    {
        
        Dio_WriteChannel((uint8)PortId,(uint8)lev);
    }
    else
    {
        sprintf( pcWriteBuffer, " Parameter 1 Valid parameters are 0~%d.\r\n",DIO_CHANNEL_ARRAY_SIZE);
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvReadDevStatusCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    uint16 PortId = 0;
    uint32  lev;
    BaseType_t lParameterStringLength;

    pcParameter = FreeRTOS_CLIGetParameter
                            (
                                pcCommandString,
                                1,
                                &lParameterStringLength
                            );
    if ( strncmp( pcParameter, "adc", strlen( "adc" ) ) == 0 )
    {
        ;
    }
    else
    {
        sprintf( pcWriteBuffer, " Parameter 1 Valid parameters error.\r\n" );
        return 0;
    }
    pcParameter = FreeRTOS_CLIGetParameter
                        (
                            pcCommandString,
                            2,
                            &lParameterStringLength
                        );
   if (IsDigitStr(pcParameter, lParameterStringLength))
   {
       PortId = atoi(pcParameter);
   }
   else
   {
       sprintf( pcWriteBuffer, " Parameter 2 Valid parameters are digit.\r\n" );
       return 0;
   }
    if (PortId < IoHwAb_AIn_Cfg_Count)
    {
        
        IoHwAb_GetVoltage((uint8)PortId,&lev);
        sprintf(pcWriteBuffer,"%s : 0x%08X",pAdc_Name[PortId],lev);
    }
    else
    {
        sprintf( pcWriteBuffer, " Parameter 1 Valid parameters are 0~%d.\r\n",IoHwAb_AIn_Cfg_Count);
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvWachDogCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    pcParameter = FreeRTOS_CLIGetParameter
                                (
                                    pcCommandString,
                                    1,
                                    &lParameterStringLength
                                );

    if ( strncmp( pcParameter, "on", strlen( "on" ) ) == 0 )
    {
        WachDogEnable();
    }
    else if ( strncmp( pcParameter, "off", strlen( "off" ) ) == 0 )
    {
        WachDogDisable();
    }
    else if ( strncmp( pcParameter, "dis", strlen( "dis" ) ) == 0 )
    {
        WachDogFeedDis();
    }
    else
    {
        sprintf( pcWriteBuffer, "Valid parameters are 'on' and 'off'.\r\n" );
    }

    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvRTC_SetTimeCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    time_t time;
    RTC_Return_t ret;
    pcParameter = FreeRTOS_CLIGetParameter
                                (
                                    pcCommandString,
                                    1,
                                    &lParameterStringLength
                                );
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        time = atoi(pcParameter);
        ret = RTC_SetTime(time);
        if (eRTC_Return_Seccess != ret)
        {
            sprintf( pcWriteBuffer, " SET error.\r\n" );
        }
        
    }
    else
    {
        sprintf( pcWriteBuffer, " Parameter 1 Valid parameters are digit.\r\n" );
        
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvRTC_GetTimeCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    RTC_Return_t ret;
    // const char *pcParameter;
    // BaseType_t lParameterStringLength;
    time_t time = 0;
    DateTimeType_t DateTime;
    uint16 len;

    ret = RTC_GetTime(&time);
    if (eRTC_Return_Seccess != ret)
    {
        sprintf( pcWriteBuffer, "Get time Error.\r\n",time);
    }
    else
    {
        len = sprintf( pcWriteBuffer, "UTC:%ld.\r\n",time);
        RTC_UTC2PerpetualCalendar(time,&DateTime);
        len += sprintf(pcWriteBuffer+len,"UTC/GMT 0.00:%d/%d/%d %d:%d:%d\r\n",DateTime.u16Year,DateTime.u8Month+1,DateTime.u8Day,
                                                                           DateTime.u8Hour,DateTime.u8Minutes,DateTime.u8Seconds);
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvLogSetLevelCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    // char *pcMode;
    BaseType_t lParameterStringLength;
    RTC_Return_t ret;
    uint8 level;
    uint8 mode_id;
    char **level_names = logger_cfg.levelNames;
    char cNameBuffer[LOGGER_MODE_NAME_MAX_LEN]={0};

    const char *pcMode = (const char *)FreeRTOS_CLIGetParameter
                            (
                                pcCommandString,
                                1,
                                &lParameterStringLength
                            );
    if (lParameterStringLength >= LOGGER_MODE_NAME_MAX_LEN)
    {
       sprintf( pcWriteBuffer, " Mode name error.\r\n" );
       return 0;
    }
    memcpy(cNameBuffer,pcMode,lParameterStringLength);
    pcParameter = FreeRTOS_CLIGetParameter
                            (
                                pcCommandString,
                                2,
                                &lParameterStringLength
                            );
    
    
   if (IsDigitStr(pcParameter, lParameterStringLength))
   {
       level = atoi(pcParameter);
   }
   else
   {
       sprintf( pcWriteBuffer, " Parameter 2 Valid parameters are digit.\r\n" );
       return 0;
   }


   if (level>=LOGGER_LEVEL_NUMBER)
   {
        sprintf( pcWriteBuffer, " error: \r\n[Level]: 0~%d.\r\n",LOGGER_LEVEL_NUMBER);
        return 0;
   }
    if (strncmp("ALL", cNameBuffer, strlen("ALL")) == 0)
    {
        Logger_LevelSetAll(level);
        sprintf( pcWriteBuffer, " [ALL] -> [%s].\r\n",level_names[level]);
    }
    else 
    {
        mode_id = (uint8) (-1);
        ret = Logger_GetModeId(cNameBuffer, &mode_id);
        if (ret == LOGGER_SUCCESS)
        {
            Logger_LevelSet(mode_id,level);
            sprintf( pcWriteBuffer, " [%s] -> [%s].\r\n",cNameBuffer,level_names[level]);
        }
        else
        {
            sprintf( pcWriteBuffer, " %s Undefined \r\n",cNameBuffer);
        }
    }
    return 0;
}

/***********************************************************************
 * @brief       : syscfg [moudle] [status]
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvSysCfgCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = (const char *)FreeRTOS_CLIGetParameter
                    (
                        pcCommandString,
                        1,
                        &lParameterStringLength
                        );
    if (CLI_COMM_CHECK_STRING("cpuload"))
    {
		pcParameter = (const char *)FreeRTOS_CLIGetParameter
						(
							pcCommandString,
							2,
							&lParameterStringLength
							);
		if (CLI_COMM_CHECK_STRING("open"))
		{
			cpu_load_dbg_setting_cb(TRUE);
		}
		else
		{
			cpu_load_dbg_setting_cb(FALSE);
		}
    }
	else if (CLI_COMM_CHECK_STRING("misclog"))
    {
		pcParameter = (const char *)FreeRTOS_CLIGetParameter
						(
							pcCommandString,
							2,
							&lParameterStringLength
							);
		if (CLI_COMM_CHECK_STRING("open"))
		{
			Misc_AdcPrintfTriger(TRUE);
		}
		else
		{
			Misc_AdcPrintfTriger(FALSE);
		}
    }
#ifdef PLATFOEM_OF_GNSS_USED
	else if (CLI_COMM_CHECK_STRING("gnsslog"))
	{
		pcParameter = (const char *)FreeRTOS_CLIGetParameter
						(
							pcCommandString,
							2,
							&lParameterStringLength
							);
		
		if (CLI_COMM_CHECK_STRING("open"))
		{
			GNSS_TracePrintfSet(TRUE);
		}
		else
		{
			GNSS_TracePrintfSet(FALSE);
		}
	}
#endif
	
	return 0;
}

/***********************************************************************
 * @brief       : stackDisplay [KEY:on|off] [CYCLE:second]
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvStackDisplayCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = (const char *)FreeRTOS_CLIGetParameter
                    (
                        pcCommandString,
                        1,
                        &lParameterStringLength
                        );
    if (CLI_COMM_CHECK_STRING("on"))
    {
        pcParameter = (const char *)FreeRTOS_CLIGetParameter
						(
							pcCommandString,
							2,
							&lParameterStringLength
							);
        OS_Stack_Usage_setting_cb(TRUE, atoi(pcParameter));
    }
    else if (CLI_COMM_CHECK_STRING("off"))
    {
        pcParameter = (const char *)FreeRTOS_CLIGetParameter
						(
							pcCommandString,
							2,
							&lParameterStringLength
							);
        OS_Stack_Usage_setting_cb(FALSE, atoi(pcParameter));
    }
	return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvLogListCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    static uint8 step = 0;
    static uint16 cnt = 0;
    uint8 i = 0;
    char *DataBuffer = pcWriteBuffer;

    switch(step)
    {
        case 0:
            DataBuffer +=sprintf( DataBuffer, " [Log Mode]\r\n" );
            DataBuffer +=sprintf( DataBuffer, " [Name]  [level]\r\n" );
            DataBuffer +=sprintf( DataBuffer, " --------------------------------------------\r\n" );
            step = 1;
            break;
        case 1:
            for(i=0;i<2;i++)
            {
                DataBuffer +=sprintf(DataBuffer," %-8s%s\r\n", logger_cfg.subNames[cnt],logger_cfg.levelNames[logger_cfg.subLevelStorage[cnt]]);
                cnt++;
                if (cnt>=LOGGER_MODULE_NUMBER)
                {
                    step = 2;
                    break;
                }
            }
                break;
        default:
            break;
    }

    if (step == 2)
    {
        step = 0;
        cnt = 0;
        return 0; 
    }
    else
    {
        return 1;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvDumpModeCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    sSOCManager_Alg_Context_t * Context = NULL_PTR;
    uint16 size=0;
    pcParameter = (const char *)FreeRTOS_CLIGetParameter
                        (
                            pcCommandString,
                            1,
                            &lParameterStringLength
                            );
    if (CLI_COMM_CHECK_STRING("socmanager"))
    {
        Context = SOCManager_Alg_Get_Context();
        
        size += sprintf(pcWriteBuffer + size,"SocState = %s\r\n",                   soc_state[Context->SocState]);
        size += sprintf(pcWriteBuffer + size,"ReqSocStateTransfer = %s\r\n",        soc_state[Context->ReqSocStateTransfer]);
        size += sprintf(pcWriteBuffer + size,"u8TransferSequenceStep = %d\r\n",     Context->u8TransferSequenceStep);
        size += sprintf(pcWriteBuffer + size,"HandshakeState = %d\r\n",             Context->HandshakeState);
        size += sprintf(pcWriteBuffer + size,"u8HandshakeTimeoutCnt = %d\r\n",      Context->u8HandshakeTimeoutCnt);
        size += sprintf(pcWriteBuffer + size,"u8HeathTimeoutCnt = %d\r\n",          Context->u8HeathTimeoutCnt);
        size += sprintf(pcWriteBuffer + size,"u8SystemState = %d\r\n",              Context->u8SystemState);
        size += sprintf(pcWriteBuffer + size,"bSocFactoryResetReadyBack = %d\r\n",  Context->bSocFactoryResetReadyBack);

    }
    else if (CLI_COMM_CHECK_STRING("gyro"))
    {
        GYRO_SENSOR_t * sensor = NULL_PTR;
        GYRO_DATA_t * data = NULL_PTR;
        sensor = GetGyroSensor();
        data = GetGyroSensorData();
        
        size += sprintf(pcWriteBuffer + size,"type = %d\r\n",       sensor[0].type    );
        size += sprintf(pcWriteBuffer + size,"  active = %d\r\n",   sensor[0].active  );
        size += sprintf(pcWriteBuffer + size,"  timer = %d\r\n",    sensor[0].timer   );
        size += sprintf(pcWriteBuffer + size,"  period = %d\r\n",   sensor[0].period  );
        size += sprintf(pcWriteBuffer + size,"  ready = %d\r\n",    sensor[0].ready   );
        size += sprintf(pcWriteBuffer + size,"  timestap = %d\r\n", sensor[0].timestap);
        size += sprintf(pcWriteBuffer + size,"  X:%f \r\n",         sensor[0].pclacdata->x);
        size += sprintf(pcWriteBuffer + size,"  Y:%f \r\n",         sensor[0].pclacdata->y);
        size += sprintf(pcWriteBuffer + size,"  Z:%f \r\n",         sensor[0].pclacdata->z);
        size += sprintf(pcWriteBuffer + size,"type = %d\r\n",       sensor[1].type    );
        size += sprintf(pcWriteBuffer + size,"  active = %d\r\n",   sensor[1].active  );
        size += sprintf(pcWriteBuffer + size,"  timer = %d\r\n",    sensor[1].timer   );
        size += sprintf(pcWriteBuffer + size,"  period = %d\r\n",   sensor[1].period  );
        size += sprintf(pcWriteBuffer + size,"  ready = %d\r\n",    sensor[1].ready   );
        size += sprintf(pcWriteBuffer + size,"  timestap = %d\r\n", sensor[1].timestap);
        size += sprintf(pcWriteBuffer + size,"  X:%f \r\n",         sensor[1].pclacdata->x);
        size += sprintf(pcWriteBuffer + size,"  Y:%f \r\n",         sensor[1].pclacdata->y);
        size += sprintf(pcWriteBuffer + size,"  Z:%f \r\n",         sensor[1].pclacdata->z);
        size += sprintf(pcWriteBuffer + size,"temp:%f \r\n",data->read.temp);
        size += sprintf(pcWriteBuffer + size,"timestamp:0x%X%X \r\n",data->read.timestamp>>8,data->read.timestamp);
    }
    else if (CLI_COMM_CHECK_STRING("version"))
    {
#ifdef VIP_VERSION_STATE
        size += sprintf(pcWriteBuffer + size,"version = %x %d.%d.%d\r\n",
            VIP_VERSION_STATE,VIP_VERSION_MAJOR,VIP_VERSION_MID,VIP_VERSION_MINOR);
#else
        size += sprintf(pcWriteBuffer + size,"undefine version.");
#endif
    }
    else
    {
        sprintf(pcWriteBuffer,"CMD %s undefine !\r\n",pcCommandString);
    }



   return 0; 
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvGPSCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = (const char *)FreeRTOS_CLIGetParameter
                    (
                        pcCommandString,
                        1,
                        &lParameterStringLength
                        );
    if (CLI_COMM_CHECK_STRING("PDTINFO"))
    {
        GPS_ReadPDTINFO();
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvCnaCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        sint32 idGet;
        uint16 id;

        idGet = atoi(pcParameter);
        if((idGet < 0) || (idGet >= cna_config.signalNumber))
        {
            sprintf(pcWriteBuffer, " Message id out of range.\r\n" );
        }
        else
        {
            id = (uint16)idGet;
            pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 2u, &lParameterStringLength);
            if (IsDigitStr(pcParameter, lParameterStringLength))
            {
                sint32 dataGet;
                uint32 data;
                Std_ReturnType ret;

                dataGet = atoi(pcParameter);
                data = (uint16)dataGet;
                ret = CNA_SignalSet(id, (uint8 *)&data);
                if(ret != E_OK)
                {
                    sprintf(pcWriteBuffer, " No action trigger fail.\r\n" );
                }
                else
                {
                    sprintf(pcWriteBuffer, " No action trigger success.\r\n" );
                }
            }
            else
            {
                sprintf( pcWriteBuffer, " Data must be digit.\r\n" );
            }
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Message id must be digit.\r\n" );
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvRxCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (TRUE == IsDigitStr(pcParameter, lParameterStringLength))
    {
        sint32 idGet = 0;
        uint16 signalId = 0;
        Std_ReturnType ret = E_OK;
        uint8 data_length = 1;
        union MultDataType dst_data = {0};
        uint16 size = 0;
        uint16 linenum = 0;
        uint8 bytenum = 0;
        boolean isInSignalGrp = FALSE;
        uint8 singalGroupId = 0;

        idGet = atoi(pcParameter);
#ifndef GWM_V35_PROJECT_TYPE_B03      
        if((idGet < 0) || (idGet >= ComEx_RxSignalSize))
#else
        if((idGet < 0) || (idGet >= Com_GetSizeOfRxAccessInfo()))
#endif
        {
            sprintf(pcWriteBuffer, " Signal id out of range.\r\n" );
        }
        else
        {
            signalId = (uint16)idGet;
#ifndef GWM_V35_PROJECT_TYPE_B03                 
            data_length = ComEx_RxSigInfo[signalId].AppAccBtyeLength;  
            if(1 == data_length)
            {
                ret = ComEx_ReceiveSignal(signalId, &dst_data.u8data, data_length);
                size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u8data);
            }
            else if(2 == data_length)
            {
                ret = ComEx_ReceiveSignal(signalId, (uint8 *)&dst_data.u16data, data_length);
                size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u16data);
            }
            else if( (2 < data_length)  && (4 >= data_length) )
            {
                ret = ComEx_ReceiveSignal(signalId, (uint8 *)&dst_data.u32data, data_length);
                size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u32data);
            }
            else if(4 < data_length)
            {
                ret = ComEx_ReceiveSignal(signalId, (uint8 *)&dst_data.arydata, data_length);
                size += sprintf( pcWriteBuffer + size, " Read value is: \r\n" );
                for(linenum = 1, bytenum = 0; (linenum <= (data_length >> 3)) && (bytenum < data_length);)
                {
                    size += sprintf( pcWriteBuffer + size, " Line%d: %d %d %d %d %d %d %d %d.\r\n",linenum,dst_data.arydata[bytenum],
                                          dst_data.arydata[bytenum+1],dst_data.arydata[bytenum+2],dst_data.arydata[bytenum+3],
                                          dst_data.arydata[bytenum+4],dst_data.arydata[bytenum+5],dst_data.arydata[bytenum+6],
                                          dst_data.arydata[bytenum+7]);

                    linenum ++;
                    bytenum = (uint8)((linenum - 1)  << 3);
                    if(bytenum == data_length)
                    {
                        break;
                    }
                }
            }

            if(E_OK == ret)
            {
                size += sprintf( pcWriteBuffer + size, " Signal received normal, status value: %d.\r\n", ret);
            }
            else if(COMEX_NEVER_RECEIVED == (ret & COMEX_NEVER_RECEIVED))
            {
                size += sprintf( pcWriteBuffer + size, " Signal never received, status value: %d.\r\n", ret);
            }
            else if(COMEX_MAX_AGE_EXCEEDED == (ret & COMEX_MAX_AGE_EXCEEDED))
            {
                size += sprintf( pcWriteBuffer + size, " Signal time out, status value: %d.\r\n", ret);
            }
            else if(COMEX_UPDATE_RECEIVED == (ret & COMEX_UPDATE_RECEIVED))
            {
                size += sprintf( pcWriteBuffer + size, " Signal received with update, status value: %d.\r\n", ret);
            }
#else
            isInSignalGrp = (COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO != Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Com_GetRxPduInfoIdxOfRxAccessInfo(signalId)));
            if(isInSignalGrp)
            {
                for(singalGroupId = 0;singalGroupId < (sizeof(Com_RxSigGrpInfo)/sizeof(Com_RxSigGrpInfoType));singalGroupId ++)
                {
                    if (Com_GetRxPduInfoIdxOfRxAccessInfo(signalId) == Com_GetRxPduInfoIdxOfRxSigGrpInfo(singalGroupId))
                    {
                        (void)Com_ReceiveSignalGroup(singalGroupId);
                    }
                }
                
            }

            data_length = Com_GetRxSigBufferArrayBasedBufferLengthOfRxAccessInfo(signalId);

            switch (Com_GetApplTypeOfRxAccessInfo(signalId))
            {
                case COM_UINT8_APPLTYPEOFRXACCESSINFO:
                    ret = Com_ReceiveSignal(signalId, &dst_data.u8data);
                    size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u8data);
                break;
                case COM_UINT16_APPLTYPEOFRXACCESSINFO:
                    ret = Com_ReceiveSignal(signalId, &dst_data.u16data);
                    size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u16data);
                break;
                case COM_UINT32_APPLTYPEOFRXACCESSINFO:
                    ret = Com_ReceiveSignal(signalId, &dst_data.u32data);
                    size += sprintf( pcWriteBuffer + size, " Read value is: %d.\r\n", dst_data.u32data);
                break;
                case COM_UINT8_N_APPLTYPEOFRXACCESSINFO:
                    ret = Com_ReceiveSignal(signalId, &dst_data.arydata);
                    size += sprintf( pcWriteBuffer + size, " Read value is: \r\n" );
                    for(linenum = 1, bytenum = 0; (linenum <= (data_length >> 3)) && (bytenum < data_length);)
                    {
                        size += sprintf( pcWriteBuffer + size, " Line%d: %d %d %d %d %d %d %d %d.\r\n",linenum,dst_data.arydata[bytenum],
                                            dst_data.arydata[bytenum+1],dst_data.arydata[bytenum+2],dst_data.arydata[bytenum+3],
                                            dst_data.arydata[bytenum+4],dst_data.arydata[bytenum+5],dst_data.arydata[bytenum+6],
                                            dst_data.arydata[bytenum+7]);

                        linenum ++;
                        bytenum = (uint8)(((uint16)(linenum - 1)  << 3));
                        if(bytenum == data_length)
                        {
                            break;
                        }
                    }
                break;
                default:
                break;
            }

            if(E_OK == ret)
            {
                size += sprintf( pcWriteBuffer + size, " Service is available, status value: %d.\r\n", ret);
            }
            else
            {
                size += sprintf( pcWriteBuffer + size, " Service is not available, status value: %d.\r\n", ret);
            }
#endif
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Signal id must be digit.\r\n" );
    }
    return 0;
}


/**
 * @brief 
 * 
 * @param pcWriteBuffer 
 * @param xWriteBufferLen 
 * @param pcCommandString 
 * @return BaseType_t 
 */
extern uint8 Seco_CmdIf_SetTxMsgCounter(uint16 msgId,uint32 MsgCnt);
static BaseType_t prvMsgCntCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        sint32 idGet = 0;
        uint16 signalId = 0;
        idGet = (uint16)atoi(pcParameter);
        if((idGet < 0) || (idGet >= 0x7ff))
        {
            sprintf(pcWriteBuffer, " Message id out of range.\r\n" );
        }
        else
        {
            signalId = (uint16)idGet;
            pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 2u, &lParameterStringLength);
            if (IsDigitStr(pcParameter, lParameterStringLength))
            {
                sint64 dataGet = 0;
                uint16 data = 0;
                dataGet = atoi(pcParameter);
                if((dataGet < 0) || (dataGet > 0x3fffffU))
                {
                    sprintf(pcWriteBuffer, " Message counter out of range, currently only spend up to 41941303.\r\n" );
                }
                else
                {
                    Std_ReturnType ret;
                    data = (uint16)dataGet;
                    ret = Seco_CmdIf_SetTxMsgCounter(signalId, dataGet);
                    if(E_OK != ret)
                    {
                        sprintf(pcWriteBuffer, " Message counter set fail.\r\n" );
                    }
                    else
                    {
                        sprintf(pcWriteBuffer, " Message counter set success.\r\n" );
                    }
                }
            }
            else
            {
                sprintf( pcWriteBuffer, "  Message counter must be digit.\r\n" );
            }
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Message id must be digit.\r\n" );
    }
    return 0;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t prvTxCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;

    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        sint32 idGet = 0;
        uint16 signalId = 0;
        idGet = (uint16)atoi(pcParameter);
#ifndef GWM_V35_PROJECT_TYPE_B03       
        if((idGet < 0) || (idGet >= ComEx_TxSignalSize))
#else
        if((idGet < 0) || (idGet >= Com_GetSizeOfTxSigInfo()))
#endif
        {
            sprintf(pcWriteBuffer, " Signal id out of range.\r\n" );
        }
        else
        {
            signalId = (uint16)idGet;
            pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 2u, &lParameterStringLength);
            if (IsDigitStr(pcParameter, lParameterStringLength))
            {
                sint32 dataGet = 0;
                uint16 data = 0;
#ifndef GWM_V35_PROJECT_TYPE_B03  
                uint8 data_length = 1;
                data_length = ComEx_TxSigInfo[signalId].BusAccBtyeLength;
#endif
                dataGet = atoi(pcParameter);
                if((dataGet < 0) || (dataGet > 65535))
                {
                    sprintf(pcWriteBuffer, " Data out of range, currently only spend up to 2 bytes.\r\n" );
                }
                else
                {
                    Std_ReturnType ret;

                    data = (uint16)dataGet;
#ifndef GWM_V35_PROJECT_TYPE_B03  
                    ret = ComEx_SendSignal(signalId, (uint8 *)&data, data_length);
#else
                    ret = Com_SendSignal(signalId, (uint8 *)&data);
                    if(0 == Com_GetTimePeriodOfTxModeTrue(Com_GetTxModeTrueIdxOfTxModeInfo(Com_GetTxPduInfoIdxOfTxSigInfo(signalId))))
                    {/* Check whether the signal is periodic */
                        Com_TriggerIPDUSend(Com_GetTxPduInfoIdxOfTxSigInfo(signalId));
                    }
#endif
                    if(E_OK != ret)
                    {
                        sprintf(pcWriteBuffer, " Signal sends fail.\r\n" );
                    }
                    else
                    {
                        sprintf(pcWriteBuffer, " Signal sends success.\r\n" );
                    }
                }
            }
            else
            {
                sprintf( pcWriteBuffer, " Data must be digit.\r\n" );
            }
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Signal id must be digit.\r\n" );
    }
    
    return 0;
}

/***********************************************************************
                    CONFIG Commands             start
***********************************************************************/
static BaseType_t ReadCconfigKindCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    uint16 cli_kindid;
    uint64 cli_kindcfg;

    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {

        cli_kindid = (uint16)atoi(pcParameter);
        if((cli_kindid < 0) || (cli_kindid >= CCONFIG_KIND_NUMBER))
        {
            sprintf( pcWriteBuffer, " Signal id must be vaild.\r\n" );
        }
        else
        {
                cli_kindcfg = CConfig_GetConfig(cli_kindid,cConfig.config->kindBuffer);
                sprintf(pcWriteBuffer, " value: %d.\r\n",cli_kindcfg);
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Signal id must be digit or all.\r\n" );
    }
    return 0;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static BaseType_t ReadVconfigKindCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
    const char *pcParameter;
    BaseType_t lParameterStringLength;
    uint16 cli_kindid;
    uint8 cli_kindcfg;
    
    pcParameter = FreeRTOS_CLIGetParameter(pcCommandString, 1u, &lParameterStringLength);
    if (IsDigitStr(pcParameter, lParameterStringLength))
    {
        cli_kindid = (uint16)atoi(pcParameter);
        if((cli_kindid < 0) || (cli_kindid >= VCONFIG_KIND_NUMBER))
        {
            sprintf( pcWriteBuffer, " Signal id must be vaild.\r\n" );
        }
        else
        {

                cli_kindcfg = vConfig.config->kindDatas[cli_kindid].configGet;
                sprintf(pcWriteBuffer, " value: %d.\r\n",cli_kindcfg);
        }
    }
    else
    {
        sprintf( pcWriteBuffer, " Signal id must be digit or all.\r\n" );
    }
    return 0;
}


/***********************************************************************
                    CONFIG Commands             end
***********************************************************************/

#define CREAT_REGISTER_CLI_COMMANDS(pcCommand,pcHelpString,pxCommandInterpreter,cExpectedNumberOfParameters)        \
    do{\
        static const CLI_Command_Definition_t   x##pxCommandInterpreter = \
        {\
            pcCommand,\
            pcHelpString,\
            pxCommandInterpreter,\
            cExpectedNumberOfParameters,\
        };\
        static CLI_Definition_List_Item_t pxCommandInterpreter##ListItem = {0};\
        FreeRTOS_CLIRegisterCommandStatic(&x##pxCommandInterpreter,&pxCommandInterpreter##ListItem);\
    }while(0)


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void vRegisterCLICommands(void)
{ 

    CREAT_REGISTER_CLI_COMMANDS(
        "Output",
        "\r\n    Output [dig][dig]\r\n",
        prvSetOutputCommand,
        2
    );

    CREAT_REGISTER_CLI_COMMANDS(
        "Echo",
        "\r\n    Echo [on | off]\r\n",
        prvSetEchoCommand,
        1/* One parameter is expected.  Valid values are "off". */
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "WachDog",
        "\r\n    WachDog [on | off | dis]\r\n",
        prvWachDogCommand,
        1/* One parameter is expected.  Valid values are "off". */
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "Read",
        "\r\n    Read [adc][<id>]\r\n",
        prvReadDevStatusCommand,
        2
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "SetTime",
        "\r\n    SetTime [UTC]\r\n",
        prvRTC_SetTimeCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "GetTime",
        "\r\n    GetTime \r\n",
        prvRTC_GetTimeCommand,
        0
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "log",
        "\r\n    log [Mode][level]\r\n",
        prvLogSetLevelCommand,
        2
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "LogList",
        "\r\n    LogList\r\n",
        prvLogListCommand,
        0
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "dump",
        "dump <mode name>",
        prvDumpModeCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "gps",
        "gps [message]",
        prvGPSCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "cna",
        "\r\ncna [messageId] [data]\r\n",
        prvCnaCommand,
        2
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "Rx",
        "\r\nRx [signalId]\r\n",
        prvRxCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "Tx",
        "\r\nTx [signalId] [data]\r\n",
        prvTxCommand,
        2
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "rccfg",
        "\r\nrccfg [kindId] \r\n",
        ReadCconfigKindCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "rvcfg",
        "\r\nrvcfg [kindId] \r\n",
        ReadVconfigKindCommand,
        1
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "syscfg",
        "\r\n    syscfg [Mode] [level]\r\n",
        prvSysCfgCommand,
        2
    );
    CREAT_REGISTER_CLI_COMMANDS(
        "stackDisplay",
        "\r\n    stackDisplay [KEY:on|off] [CYCLE:second] \n\t Display stack usage \r\n",
        prvStackDisplayCommand,
        2
    );
    #ifndef GWM_V35_PROJECT_TYPE_B03  
    CREAT_REGISTER_CLI_COMMANDS(
        "SecocTx",
        "\r\n    SecocTx [Id] [Message counter]  \r\n",
        prvMsgCntCommand,
        2
    );
    #endif
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void CLI_CmdMainFunction(void)
{
    uint8 ch;
    BaseType_t ret;
    // uint32 cnt = 0;
    while ((u8ExecuteFlag == 0) && (RB_Pop(RB_ID_CMD_INPUT,&ch,1)>=RB_SUCCESS))
    {
        if (ch == cmdASCII_NEWLINE)
        {
            continue;
        }
        // echo input
        if (TRUE == bEcho_Status)
        {

            if (((ch != cmdASCII_DEL)&&(ch != cmdASCII_BS)) || (u16UartInputCnt > 0))
            {
                Logger_StringFromCLI("%c",ch);
            }
            if ((ch == cmdASCII_HEADLINE))
            {
                Logger_StringFromCLI("\n");
            }
        }

        
        if ((ch != cmdASCII_HEADLINE))
        {
            if ((ch>=cmdASCII_SPACE)&&(ch<=cmdASCII_TILDE))
            {
                if (u16UartInputCnt<UART_INPUT_BUFFER_MAX_SIZE)
                {
                    UartInputBuffer[u16UartInputCnt++] = ch;
                }
            }
            else if ((ch == cmdASCII_DEL)||(ch == cmdASCII_BS))
            {
                if (u16UartInputCnt > 0)
                {
                    u16UartInputCnt--;
                    UartInputBuffer[u16UartInputCnt] = cmdASCII_STRINGEND;
                }
            }
        }
        else if (strlen(UartInputBuffer)!=0)
        {
            u8ExecuteFlag = 1;
        }
        else if (permission == PASSWD_INCORRECT)
        {
            Logger_StringFromCLI(input_passwd_msg);
        }
    }
    
    // check line is end;
    if (u8ExecuteFlag == 1)
    {
        if (permission == PASSWD_INCORRECT)
        {
            if(strcmp(passwd, UartInputBuffer))
            {
                Logger_StringFromCLI(incorrect_passwd_msg);
            }
            else
            {
                permission = (uint8)PASSWD_CORRECT;
            }
            u8ExecuteFlag = 0;
            u16UartInputCnt = 0;
            memset(UartInputBuffer,0,sizeof(UartInputBuffer));
            
        }
        else
        {
            if (UartInputBuffer[0] != '$')
            {
                memset(UartOutputBuffer,0,sizeof(UartOutputBuffer));
                ret = FreeRTOS_CLIProcessCommand(UartInputBuffer,UartOutputBuffer,sizeof(UartOutputBuffer)-1);
                if (strlen(UartOutputBuffer) !=0 )
                {
                    Logger_StringFromCLI(UartOutputBuffer);
                }
                if (ret == FALSE)
                {
                    u8ExecuteFlag = 0;
                    u16UartInputCnt = 0;
                    memset(UartInputBuffer,0,sizeof(UartInputBuffer));
                }
            }
            else
            {
#ifdef PLATFOEM_OF_GNSS_USED
           		GNSS_Logger_Triger((uint8 *)UartInputBuffer);
#endif
                //GPS_TriggerTransmit((uint8 *)UartInputBuffer);
                u8ExecuteFlag = 0;
                u16UartInputCnt = 0;
                memset(UartInputBuffer,0,sizeof(UartInputBuffer));
            }
        }
    }
}
