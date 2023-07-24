/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Log.c
 *           Config:  E:/v3_5_svn_demo/CBD2000298_D00/Applications/SipAddon/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Log
 *  Generation Time:  2020-07-14 11:00:07
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Log>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Log.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Logger.h"
#include "Std_Types.h"
#include <stdio.h>
#include <string.h>
#include "logger_IPC.h"
#include "IPC_Common.h"
#include "dma.h"


#if(LOGGER_EN_STORE_PARA_POINTER == 0)

#include "Crc.h"
#include "VersionCfg_B02.h"

#endif

/*
 *  %typedef/macro defintion%
 */
#define FORMAT_FLAG_LEFT_JUSTIFY    (1u << 0)
#define FORMAT_FLAG_PAD_ZERO        (1u << 1)
#define FORMAT_FLAG_PRINT_SIGN      (1u << 2)
#define FORMAT_FLAG_ALTERNATE       (1u << 3)

#define LOGGER_UART_STATE_IDLE      (0)
#define LOGGER_UART_STATE_BUSY      (1)

#define LOGGER_CLI_TEMP_BUFFER_SIZE (1024)

#if(LOGGER_EN_STORE_PARA_POINTER == 1)

#define LOGGER_ASSERT(x) {do{}while((0))}
#define LOGGER_IS_FORMAT_OPT0(x)   ((c == '-') || (c == '0')  || (c == '+') || (c == '#'))
#define LOGGER_IS_FORMAT_OPT1(x)   (c <= '9' && c >= '0')
#define LOGGER_IS_VALID_FORMAT(x)   ((c == 'p') || (c == 'u') || (c == 'x') || (c == 'X') || (c == 'c') || (c == 'd') || (c == 'f') || (c == 's') || (c == 'S') || (c == 'F') || (c == '%'))

#endif

// Module parameters
#define cLOG_ALG_FIFO_DEEPTH                   (512u)          // 115200bps = 11 Byte/ms
#define cRLIN35_LDBR_ADDR                      (0xFFCE2140+0x26)
static uint8 LOG_Alg_FIFO[cLOG_ALG_FIFO_DEEPTH];
static sint32 sLogFIFOReadPrt = 0;

// LOG Com mode state define
typedef enum 
{
    eLOG_Com_Uninit = 0,
    eLOG_Com_Ready,
    eLOG_Com_Err,
}LOG_Com_State_t;

// Private 
// LOG COM state 
static LOG_Com_State_t tLOG_Com_State = eLOG_Com_Uninit;

//==sys timestamp 
extern void TM_Timer1msStartStamp(uint32 * StartStamp);
#define LOG_GET_OSTick(X)		TM_Timer1msStartStamp(X)

void LOG_Com_ReadData(void);
void LOG_DmaErrDeal(void);

typedef struct Logger_Manager
{
    uint8 uartState;

}Logger_Manager_t;

typedef struct Logger_Data
{
    Logger_State_t state;               /* state of debug */
}Logger_Data_t;

/*
 *  %forward declaration%
 */
static Logger_Len_t Logger_StoreChar(uint8 *logBuff, Logger_Len_t logDataLen, char c);
static Logger_Len_t Logger_PrintUnsigned(uint8 *logBuff, Logger_Len_t logDataLen, uint32_t value,uint8_t base, uint8_t num_digits, uint8_t field_width, uint8_t format_flags);
static Logger_Len_t Logger_PrintInt(uint8 *logBuff, Logger_Len_t logDataLen, int32_t value, uint8_t base, uint8_t num_digits, uint8_t field_width, uint8_t format_flags);
static Logger_Len_t Logger_Printf(uint8 *logBuff, Logger_Len_t logDataLen, const char*fmt, ...);
static Logger_Len_t Logger_Vprintf(uint8 *logBuff, Logger_Len_t logDataLen, const char * format, va_list *param);


#if(LOGGER_EN_STORE_PARA_POINTER == 1)

static uint8 Logger_CheckSum8(uint8 *ptr,uint8 len);
static Logger_Return_t Logger_ParametersFormatPadding(uint32* pParaData, uint8 paraLen, uint8_t *pDataForEx,uint8 *exLen,Logger_Module_t module, Logger_Level_t level);
static Logger_Return_t Logger_GetLrAndParaPtr(const char *fmt,va_list *vp,uint32 *pPara,uint8 *pLen);
static Logger_Return_t Logger_CalcVpParameters(const char *fmt,va_list *vp,uint32 *pPara,uint8 *pLen);
static Logger_Return_t Logger_FormatDescriptorDstinguish(char c,va_list *vp,uint32 *pPara,uint8 *pLen);

#endif

/*
 *  %global definition%
 */
static boolean bLogIsInit = FALSE;
static struct Logger_Data logger_data;
static Logger_Manager_t loggerManager;
static char cCliTempBuffer[LOGGER_CLI_TEMP_BUFFER_SIZE];
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define Log_START_SEC_CODE
#include "Log_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Logger_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Logger_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Log_CODE) Logger_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Logger_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Logger_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Log(void)
 *   void Rte_Exit_ExclusiveArea_Log(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Logger_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Log_CODE) Logger_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Logger_MainFunction
 *********************************************************************************************************************/
    RB_Return_t rbDataLen;
    
    if(LOGGER_UART_STATE_IDLE == loggerManager.uartState)
    {
        rbDataLen = RB_NumberGet(logger_cfg.rbUart);
        if(rbDataLen > 0)
        {
            Uart_TriggerTransmit(logger_cfg.chnUart);
            loggerManager.uartState = LOGGER_UART_STATE_BUSY;
        }
     }
    Logger_IPC_Task();

	
	LOG_Com_ReadData();
	LOG_DmaErrDeal();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Log_STOP_SEC_CODE
#include "Log_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

void Log_ColdResetCallout(void)
{
     
}

/*
 * @brief   :   logger uart transmit finish callback to continue transmit
 * @param   :   data: data buffer
 * @param   :   length: ind ata buffer length
 *              out data length actual write to buffer
 * @retval  :   none
 */
 void Logger_UartTransmitCallback(Uart_Id_t id, uint8_t *data, uint8_t *length)
 {
    RB_Return_t ret;
    LOGGER_ENTER_CRITICAL();
    ret = RB_Pop(logger_cfg.rbUart, data, *length);
    LOGGER_EXIT_CRITICAL();

    if(ret > RB_SUCCESS)
    {
        *length = (uint8_t)ret;
    }
    else
    {
        *length = 0u; 
    }
    (void)id;
 }

/*
* @brief   :   logger uart transmit finish callback to continue transmit
* @param   :   data: data buffer
* @param   :   length: in  data buffer length
*                      out data length actual write to buffer
* @retval  :   none
*/
void Logger_UartTransmitFinishCallback(Uart_Id_t id, uint8_t *data, uint8_t *length)
{
    RB_Return_t ret = RB_Pop(logger_cfg.rbUart, data, *length);
    if(ret > RB_SUCCESS)
    {
        *length = (uint8_t)ret;
    }
    else
    {
        *length = 0u;
        loggerManager.uartState = LOGGER_UART_STATE_IDLE;
    }
    (void)id;
}


 /*
 * @brief   :   open logger module
 * @param   :   none
 * @retval  :   LOGGER_SUCCESS: open success
 * @retval  :   LOGGER_E_PARAM: parameter error
 * @retval  :   LOGGER_E_INIT: init error
 * @retval  :   LOGGER_E_STATE: state error
 */
Logger_Return_t Logger_Open(void)
{
    Logger_Return_t ret = LOGGER_ERROR;

#if(LOGGER_DEV_ERROR_DETECT == STD_ON)
    if(LOGGER_STATE_CLOSE != logger_data.state)
    {
        ret = LOGGER_E_STATE;
    }
    else
#endif
    {
        LOGGER_RES_LOCK();
        
        ret = Uart_Open(logger_cfg.chnUart);
        if(UART_SUCCESS == ret)
        {
            logger_data.state = LOGGER_STATE_OPEN;
        }
        ret = LOGGER_SUCCESS;
        LOGGER_RES_UNLOCK();
    }

    return ret;
}

/*
* @brief   :   set module level
* @param   :   module: module id
* @param   :   level: submodule level to set
* @retval  :   LOGGER_SUCCESS: set success
* @retval  :   LOGGER_E_PARAM: parameter error
* @retval  :   LOGGER_E_STATE: state error
*/
Logger_Return_t Logger_LevelSet(Logger_Module_t module, Logger_Level_t level)
{
    Logger_Return_t ret = LOGGER_ERROR;

#if(LOGGER_DEV_ERROR_DETECT == STD_ON)
    if((module >= logger_cfg.subNumber) || (level >= logger_cfg.levelNumber))
    {
        ret = LOGGER_E_PARAM;
    }
    else if(LOGGER_STATE_NOT_INIT == logger_data.state)
    {
        ret = LOGGER_E_STATE;
    }
    else
#endif
    {
        LOGGER_RES_LOCK();
        logger_cfg.subLevelStorage[module] = level;
        LOGGER_RES_UNLOCK();
        ret = LOGGER_SUCCESS;
    }

    return ret;
}


Logger_Return_t  Logger_GetModeId(uint8 * name, uint8 * id)
{
    uint8  len;
    uint8 i;
    Logger_Return_t result = LOGGER_ERROR ;
    if ((name == NULL_PTR)||(id == NULL_PTR))
    {
        result  = LOGGER_E_PARAM;
    }
    else
    {
        len = strnlen(name,LOGGER_MODE_NAME_MAX_LEN);

        for (i=0; i<logger_cfg.subNumber; i++)
        {
            if (strnlen(logger_cfg.subNames[i],LOGGER_MODE_NAME_MAX_LEN) == len)
            {
                if (strncmp(logger_cfg.subNames[i],name,len) == 0)
                {
                    *id = i;
                    result = LOGGER_SUCCESS;
                    break;
                    
                }
            }
        }
    }
    return result;
}


Logger_Return_t Logger_LevelSetAll(Logger_Level_t level)
{
    Logger_Return_t ret = LOGGER_ERROR;

#if(LOGGER_DEV_ERROR_DETECT == STD_ON)
    if(level >= logger_cfg.levelNumber)
    {
        ret = LOGGER_E_PARAM;
    }
    else if(LOGGER_STATE_NOT_INIT == logger_data.state)
    {
        ret = LOGGER_E_STATE;
    }
    else
#endif
    {
        uint8 i;
        LOGGER_RES_LOCK();
        for (i=0;i < logger_cfg.subNumber; i++)
        {
            logger_cfg.subLevelStorage[i] =  level;
        }
        LOGGER_RES_UNLOCK();
        ret = LOGGER_SUCCESS;
    }

    return ret;
}


#if(LOGGER_EN_STORE_PARA_POINTER == 1)
/***********************************************************************************************************************
 *  Os_Hal_GetLP()
 **********************************************************************************************************************/
/*! \fn           uint32 Os_Hal_GetLP(void)
 *  \brief        Returns the current link pointer.
 *  \details      --no details--
 *
 *  \return       The current link pointer.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
asm uint32 Logger_Hal_GetLP(void)
{
  mov  LP, r10

}
/*
* @brief   :   Crc8 algorithm
* @param   :   ptr:Pointer to start address of data block to be calculated.
* @param   :   len:Length of data block to be calculated in bytes
* @retval  :   Crc8
*/
static uint8 Logger_CheckSum8(uint8 *ptr,uint8 len)
{
	return Crc_CalculateCRC8(ptr,len,0xff,TRUE);
}


/*
* @brief   :   pop parameters from stack
* @param   :   c:format
* @param   :   pPara: output Parameters pointer
* @param   :   pLen: size of parameters pointer
* @retval  :   LOGGER_SUCCESS: print success
* @retval  :   LOGGER_E_PARAM: format error
*/
static Logger_Return_t Logger_FormatDescriptorDstinguish(char c,va_list *vp,uint32 *pPara,uint8 *pLen)
{
    Logger_Return_t ret = LOGGER_E_PARAM;
    uint32 *l_pPara = pPara;
    uint8 Len = *pLen; 

    if(LOGGER_IS_VALID_FORMAT(c))
    {
        switch (c)
        {
            case 'p':
            case 'u':
            case 'x':
            case 'X':
            case 'c':
            case 'd':
            {
                int32_t para = va_arg(*vp, int);
            
                memcpy((uint8 *)l_pPara + Len * 4,(uint8 *)&para,sizeof(para));
                Len++;
            }
            break;

            case 'F':
            case 'f':
            {
                float para = va_arg(*vp, double);
                memcpy((uint8 *)l_pPara + Len * 4,(uint8 *)&para,sizeof(para));
                Len++;
            }
            break;
        
            case 'S':
            case 's':
            {
                const char * para = va_arg(*vp, const char *);
                memcpy((uint8 *)l_pPara + Len * 4,(uint8 *)&para,sizeof(para));
                Len++;
            }
            break;

            default:
				/*doing nothing*/
            break;
        }
        *pLen = Len;
        ret = LOGGER_SUCCESS;
    }

    return ret;
}

/*
* @brief   :   Get variable paraters
* @param   :   vp: va_list struct
* @param   :   pPara: output Parameters pointer
* @param   :   pLen: size of parameters pointer
* @retval  :   LOGGER_SUCCESS: print success
* @retval  :   LOGGER_ERROR: 
*/
static Logger_Return_t Logger_GetLrAndParaPtr(const char *fmt,va_list *vp,uint32 *pPara,uint8 *pLen)
{
	Logger_Return_t ret = LOGGER_ERROR;
    
    uint8 Len = *pLen; 
    volatile float temp = 0;
    volatile double tempD = 0;
    volatile char *format = (char*)fmt;  
    volatile int value = 0;
    volatile char c = 0;

    uint8 counter = 0;

/* 
supported format : % <p><n><.><m><q>[o]

    p: optional parameter, refer to LOGGER_IS_FORMAT_ADD0
    n: optional parameter, refer to LOGGER_IS_FORMAT_ADD1 :0 - 9
    .: optional parameter, '.'
    m: optional parameter, 0-9
    o: mandatory parameter, format control discritptor,refer to LOGGER_IS_VALID_FORMAT
*/

    pPara[Len++] = (uint32)format; 

	do
	{
        
        c = *format;
        if (c == 0)
        {
            break;
        }
        if (c == '%') 
        {
            /* next char */
            format++;
            c = *format;
            if(LOGGER_IS_FORMAT_OPT0(c))
            {
                format++;
                c = *format;
                if(LOGGER_IS_FORMAT_OPT1(c))
                {
                    format++;
                    c = *format;
                    if(c == '.')
                    {
                        format++;
                        c = *format;
                        if(LOGGER_IS_FORMAT_OPT1(c))
                        {
                            format++;
                            c = *format;
                        }
                    }
                }
            }
            else
            {
                if(LOGGER_IS_FORMAT_OPT1(c))
                {
                    format++;
                    c = *format;
                    if(c == '.')
                    {
                        format++;
                        c = *format;
                        if(LOGGER_IS_FORMAT_OPT1(c))
                        {
                            format++;
                            c = *format;
                        }
                    }
                    else
                    {
                        if(LOGGER_IS_FORMAT_OPT1(c))
                        {
                            format++;
                            c = *format;
                        }
                    }
                }

            }
            ret = Logger_FormatDescriptorDstinguish(c,vp,pPara,&Len);

            if(ret != LOGGER_SUCCESS)
            {
                break;
            }

        }
        format++;
    }while(1);
		
	*pLen = Len;
    return ret;
}

/*
* @brief   :   Get variable paraters
* @param   :   vp: va_list struct
* @param   :   pPara: output Parameters pointer
* @param   :   pLen: size of parameters pointer
* @retval  :   LOGGER_SUCCESS
* @retval  :   LOGGER_ERROR
*/

static Logger_Return_t Logger_CalcVpParameters(const char *fmt,va_list *vp,uint32 *pPara,uint8 *pLen)
{
	Logger_Return_t ret = LOGGER_ERROR;
    uint64 utc_time = 0;
	uint32 *l_pPara = pPara;

    (void)RTC_GetBinTime(&utc_time);
    l_pPara[0] = (uint32)(utc_time>>32);
    l_pPara[1] =  (uint32)utc_time;

    *pLen = 2;

	return Logger_GetLrAndParaPtr(fmt,vp, pPara, pLen);
}

/*
* @brief   :   padding parameters into ExBuufer
* @param   :   pParaData: parameters will transform
* @param   :   paraLen: parameter length
* @param   :   pDataForEx: output Exbuffer
* @param   :   exLen:output ExBuffer size
* @retval  :   LOGGER_SUCCESS
* @retval  :   LOGGER_ERROR
*/
static Logger_Return_t Logger_ParametersFormatPadding(uint32* pParaData, uint8 paraLen, uint8_t *pDataForEx,uint8 *exLen,Logger_Module_t module, Logger_Level_t level)
{		
	Logger_Return_t ret = LOGGER_ERROR;


	if(pDataForEx != (void*)0)
	{
		uint8 i = 0;

		/* header */
		pDataForEx[0] = 0x5A;
		pDataForEx[1] = 0xA5;
		pDataForEx[2] = module;
		pDataForEx[3] = level;

        /* length of data domain : 4byte version + 4 * n byte parameters */
		pDataForEx[4] = 6 + 4 * paraLen;

        /* lr and Parameter pointers */
		for(i = 0; i < paraLen; i++)
		{
			pDataForEx[6 + i*4] = pParaData[i] & 0xFF;
			pDataForEx[7 + i*4] = (pParaData[i] >> 8) & 0xFF;
			pDataForEx[8 + i*4] = (pParaData[i] >> 16) & 0xFF;
			pDataForEx[9 + i*4] = (pParaData[i] >> 24) & 0xFF;
		}

        /* version */
		pDataForEx[6 + 4 * paraLen] = VIP_VERSION_STATE;
		pDataForEx[7 + 4 * paraLen] = VIP_VERSION_MAJOR;
        pDataForEx[8 + 4 * paraLen] = VIP_VERSION_MID;
        pDataForEx[9 + 4 * paraLen] = VIP_VERSION_MINOR;

        /* crc8, calulate data domain only */ 
		pDataForEx[5] = Logger_CheckSum8(pDataForEx + 6, pDataForEx[2]);

		*exLen = 10 + 4 * (paraLen);

		ret = LOGGER_SUCCESS;

	}
	else
	{
		ret = LOGGER_ERROR;
	}

	
	return ret;
}
#endif

/*
* @brief   :   print formatted message to interface
* @param   :   module: module id
* @param   :   level: level of message
* @param   :   fmt: formatted string
* @param   :   ...: vaialbe parameter
* @retval  :   LOGGER_SUCCESS: print success
* @retval  :   LOGGER_E_PARAM: parameter error
* @retval  :   LOGGER_E_STATE: state error
*/
Logger_Return_t Logger_String(Logger_Module_t module, Logger_Level_t level,const char *fmt,...)
{
    va_list vp;
    Logger_Return_t ret = LOGGER_ERROR;
    Ipc_Data_t ipcData = {0};

#if (LOGGER_EN_STORE_PARA_POINTER == 0)

    uint8 uartHeadBuff[LOGGER_UART_HEAD_SIZE];
    Logger_Len_t uartHeadLen = (Logger_Len_t)sizeof(uartHeadBuff);
    Logger_Len_t logDataLen = LOGGER_DATA_SIZE;
    Logger_Len_t lenUsedHead = 0u;
    Logger_Len_t lenUsedBody = 0u;
    
    uint8 *logBuff = ipcData.buffer;
    uint64 utc_time = 0;

#else

	/* lr fmt para */
    uint32 paraData[LOGGER_MAX_PARA_NUM] = {0};
	uint8 paraLen = 0;
	uint8 ExLen = 0;
	uint8 pDataForEx[LOGGER_MAX_DATA_BYTES] = {0};
#endif


#if(LOGGER_DEV_ERROR_DETECT == STD_ON)
    if((module >= logger_cfg.subNumber) || (level >= logger_cfg.levelNumber))
    {
        ret = LOGGER_E_PARAM;
    }
    else if(LOGGER_STATE_OPEN != logger_data.state)
    {
        ret = LOGGER_E_STATE;
    }
    else
#endif 
    {
        if(logger_cfg.subLevelStorage[module] >= level)
        {     

#if(LOGGER_EN_STORE_PARA_POINTER == 0)

            (void)RTC_GetBinTime(&utc_time);
            lenUsedHead += Logger_Printf(uartHeadBuff, uartHeadLen,"[%04X%08X]", (uint32)(utc_time>>32),(uint32)utc_time);

            lenUsedHead += Logger_Printf(uartHeadBuff + lenUsedHead, uartHeadLen - lenUsedHead,"[%s]", logger_cfg.subNames[module]);

            lenUsedHead += Logger_Printf(uartHeadBuff + lenUsedHead, uartHeadLen - lenUsedHead,"[%s] ", logger_cfg.levelNames[level]);
            ipcData.mdlID = module;
            ipcData.level = level;
            ipcData.timestamp[0] = IPC_GET_BYTE(utc_time,7);
            ipcData.timestamp[1] = IPC_GET_BYTE(utc_time,6);
            ipcData.timestamp[2] = IPC_GET_BYTE(utc_time,5);
            ipcData.timestamp[3] = IPC_GET_BYTE(utc_time,4);
            ipcData.timestamp[4] = IPC_GET_BYTE(utc_time,3);
            ipcData.timestamp[5] = IPC_GET_BYTE(utc_time,2);
            ipcData.timestamp[6] = IPC_GET_BYTE(utc_time,1);
            ipcData.timestamp[7] = IPC_GET_BYTE(utc_time,0);

            va_start(vp, fmt);
            lenUsedBody += Logger_Vprintf(logBuff + lenUsedBody, logDataLen - lenUsedBody,fmt, &vp);
            va_end(vp);

            LOGGER_ENTER_CRITICAL();

            #if (LOGGER_IPC_BUFFER_FIT_DATA == 1)

            /* buffer length */
            ipcData.length = lenUsedBody;
            ipcData.header0 = 0xa5;
            ipcData.header1 = 0xa5;

			if(lenUsedBody + 13 <= sizeof(ipcData))
			{
				(void)RB_Push(logger_cfg.rbIpc,(uint8 *)&ipcData,(lenUsedBody + 13));/* time 8 + ml 2 + header 2 + lenth 1*/
			}

           

            #else

            (void)RB_Push(logger_cfg.rbIpc,(uint8 *)&ipcData,1);

            #endif
            
            LOGGER_EXIT_CRITICAL();

			
            lenUsedBody += Logger_Printf(logBuff + lenUsedBody, logDataLen - lenUsedBody,"\r\n");

            LOGGER_ENTER_CRITICAL();
            (void)RB_Push(logger_cfg.rbUart, uartHeadBuff,lenUsedHead);
            (void)RB_Push(logger_cfg.rbUart, logBuff,lenUsedBody);
            LOGGER_EXIT_CRITICAL();

#else

            va_start(vp, fmt);
			
            ret = Logger_CalcVpParameters(fmt,&vp,paraData,&paraLen);
			
            va_end(vp);

            if(LOGGER_SUCCESS == ret)
            {

                /* Uart */
                Logger_ParametersFormatPadding(paraData,paraLen,pDataForEx,&ExLen,module,level);

                LOGGER_ENTER_CRITICAL();

                (void)RB_Push(logger_cfg.rbUart, pDataForEx,ExLen);

                /* IPC */
                ipcData.mdlID = module;
                ipcData.level = level;

                /* copy paramters only */
                memcpy(ipcData.timestamp,pDataForEx + 6,8);
                memcpy(ipcData.buffer,pDataForEx + 14,ExLen - 14);

                (void)RB_Push(logger_cfg.rbIpc,(uint8 *)&ipcData,1);

                LOGGER_EXIT_CRITICAL();
                
            }
#endif
        }
    }

    return ret;
}
/*
* @brief   :   print formatted message to interface
* @param   :   fmt: formatted string
* @param   :   ...: vaialbe parameter
* @retval  :   LOGGER_SUCCESS: print success
* @retval  :   LOGGER_E_PARAM: parameter error
* @retval  :   LOGGER_E_STATE: state error
*/

Logger_Return_t Logger_StringFromCLI(const char*fmt, ...)
{
    va_list vp;
    Logger_Return_t ret = LOGGER_ERROR;
    Logger_Len_t logDataLen = LOGGER_CLI_TEMP_BUFFER_SIZE;
    Logger_Len_t lenUsedBody = 0u;
    Ipc_Data_t ipcData;
    uint8 *logBuff = cCliTempBuffer;

    va_start(vp, fmt);
    lenUsedBody += Logger_Vprintf(logBuff + lenUsedBody, logDataLen - lenUsedBody,fmt, &vp);
    va_end(vp);
    LOGGER_ENTER_CRITICAL();
    (void)RB_Push(logger_cfg.rbUart, logBuff,lenUsedBody);
    LOGGER_EXIT_CRITICAL();
    ret = LOGGER_SUCCESS;

    return ret;
}





/*
* @brief   :   handle one letter
* @param   :   c: letter to handleLogger_Len_t
* @retval  :   none
*/

static Logger_Len_t Logger_StoreChar(uint8 *const logBuff, Logger_Len_t logDataLen,char c)
{
    Logger_Len_t ret = 0u;
    if(logDataLen > 0u)
    {
        *logBuff = c;
        ret = 1u;
    }
    return ret;
}

/*
* @brief   :   handle unsigned number
* @param   :   value: number to handle
* @param   :   base: base of number
* @param   :   num_digits: digits of number
* @param   :   field_width: width of number
* @param   :   format_flags: format flag
* @retval  :   none
*/
static Logger_Len_t Logger_PrintUnsigned(uint8 *logBuff, Logger_Len_t logDataLen, uint32_t value, uint8_t base, uint8_t num_digits, uint8_t field_width, uint8_t format_flags)
{
    static const char table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    uint32_t div;
    uint32_t digit;
    uint32_t number;
    uint32_t width;
    char c;
    Logger_Len_t lenUsed = 0u;

    number = value;
    digit = 1u;
    width = 1u;
    while (number >= base)
    {
        number = (number / base);
        width++;
    }
    if (num_digits > width)
    {
        width = num_digits;
    }

    if ((format_flags & FORMAT_FLAG_LEFT_JUSTIFY) == 0u)
    {
        if (field_width != 0u)
        {
            if (((format_flags & FORMAT_FLAG_PAD_ZERO) == FORMAT_FLAG_PAD_ZERO) && (num_digits == 0))
            {
                c = '0';
            }
            else
            {
                c = ' ';
            }
            while ((field_width != 0u) && (width < field_width))
            {
                field_width--;
                lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, c);
            }
        }
    }

    while (1) 
    {
        if (num_digits > 1u)
        {
            num_digits--;
        }
        else
        {
            div = value / digit;
            if (div < base)
            {
                break;
            }
        }
        digit *= base;
    }

    do
    {
        div = value / digit;
        value -= div * digit;
        lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, table[div]);
        digit /= base;
    } while (digit);

    if ((format_flags & FORMAT_FLAG_LEFT_JUSTIFY) == FORMAT_FLAG_LEFT_JUSTIFY)
    {
        if (field_width != 0u)
        {
            while ((field_width != 0u) && (width < field_width))
            {
                field_width--;
                lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, ' ');
            }
        }
    }
    return lenUsed;
}

/*
* @brief   :   handle signed number
* @param   :   value: number to handle
* @param   :   base: base of number
* @param   :   num_digits: digits of number
* @param   :   field_width: width of number
* @param   :   format_flags: format flag
* @retval  :   none
*/

static Logger_Len_t Logger_PrintInt(uint8 *logBuff, Logger_Len_t logDataLen, int32_t value, uint8_t base, uint8_t num_digits, uint8_t field_width, uint8_t format_flags)
{
    uint8_t width;
    uint32_t number;
    Logger_Len_t lenUsed = 0u;

    if(value < 0)
    {
        number = -value;
    }
    else
    {
        number = value;
    }

    width = 1u;
    while (number >= (uint32_t)base)
    {
        number = (number / (uint32_t)base);
        width++;
    }

    if (num_digits > width)
    {
        width = num_digits;
    }

    if ((field_width > 0u) && ((value < 0) || ((format_flags & FORMAT_FLAG_PRINT_SIGN) == FORMAT_FLAG_PRINT_SIGN)))
    {
        field_width--;
    }

    if ((((format_flags & FORMAT_FLAG_PAD_ZERO) == 0u) || (num_digits != 0u)) && ((format_flags & FORMAT_FLAG_LEFT_JUSTIFY) == 0u))
    {
        if (field_width != 0u)
        {
            while ((field_width != 0u) && (width < field_width))
            {
                field_width--;
                lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, ' ');
            }
        }
    }

    if(value < 0)
    {
        number = -value;
    }
    else
    {
        number = value;
    }

    if (value < 0)
    {
        lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, '-');
    }
    else if ((format_flags & FORMAT_FLAG_PRINT_SIGN) == FORMAT_FLAG_PRINT_SIGN)
    {
        lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, '+');
    }

    if (((format_flags & FORMAT_FLAG_PAD_ZERO) == FORMAT_FLAG_PAD_ZERO) && ((format_flags & FORMAT_FLAG_LEFT_JUSTIFY) == 0) && (num_digits == 0))
    {
        if (field_width != 0u)
        {
            while ((field_width != 0u) && (width < field_width))
            {
                field_width--;
                lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, '0');
            }
        }
    }
    lenUsed += Logger_PrintUnsigned(logBuff + lenUsed, logDataLen - lenUsed,number, base, num_digits, field_width, format_flags);
    return lenUsed;
}

/*
* @brief   :   internal formatted string handler with unfixed parameter
* @param   :   format: string format
* @param   :   ...: variable parameters
* @retval  :   none
*/

static Logger_Len_t Logger_Printf(uint8 *logBuff, Logger_Len_t logDataLen, const char*fmt, ...)
{
    va_list vp;
    Logger_Len_t lenUsed = 0u;

    va_start(vp, fmt);
    lenUsed += Logger_Vprintf(logBuff,logDataLen,fmt, &vp);
    va_end(vp);
    return lenUsed;
}

/*
* @brief   :   internal formatted string handler with valist
* @param   :   format: string format
* @param   :   param: variable parameters
* @retval  :   none
*/
static Logger_Len_t Logger_Vprintf(uint8 *logBuff, Logger_Len_t logDataLen, const char * format, va_list *param)
{
    char c;
    int32_t value;
    uint8_t num_digits;
    uint8_t format_flags;
    uint8_t field_width;
    Logger_Len_t lenUsed = 0;

    do
    {
        c = *format;
        format++;
        if (c == 0)
        {
            break;
        }
        if (c == '%')
        {
            format_flags = 0u;
            value = 1;
            do
            {
                c = *format;
                switch (c)
                {
                    case '-':
                    {
                        format_flags |= FORMAT_FLAG_LEFT_JUSTIFY;
                        format++;
                    }
                    break;

                    case '0':
                    {
                        format_flags |= FORMAT_FLAG_PAD_ZERO;
                        format++;
                    }
                    break;

                    case '+':
                    {
                        format_flags |= FORMAT_FLAG_PRINT_SIGN;
                        format++;
                    }
                    break;

                    case '#':
                    {
                        format_flags |= FORMAT_FLAG_ALTERNATE;
                        format++;
                    }
                    break;

                    default:
                    {
                        value = 0;
                    }
                    break;
                }
            }while (value);

            field_width = 0u;
            do
            {
                c = *format;
                if ((c < '0') || (c > '9'))
                {
                    break;
                }
                format++;
                field_width = (field_width * 10) + ((unsigned)c - '0');
            } while (1);

            num_digits = 0u;
            c = *format;
            if (c == '.')
            {
                format++;
                do
                {
                    c = *format;
                    if ((c < '0') || (c > '9'))
                    {
                        break;
                    }
                    format++;
                    num_digits = num_digits * 10u + ((unsigned)c - '0');
                } while (1);
            }

            c = *format;
            do
            {
                if ((c == 'l') || (c == 'h'))
                {
                    c = *format;
                    format++;
                }
                else
                {
                    break;
                }
            } while (1);

            switch (c)
            {
                case 'c':
                {
                    char c0;
                    value = va_arg(*param, int);
                    c0 = (char)value;
                    lenUsed += Logger_StoreChar(logBuff + lenUsed, logDataLen - lenUsed, c0);
                }
                break;

                case 'd':
                {
                    value = va_arg(*param, int);
                    lenUsed += Logger_PrintInt(logBuff + lenUsed,logDataLen - lenUsed,value, 10u, num_digits, field_width, format_flags);
                }
                break;

                case 'F':
                case 'f':
                {
                    float f = va_arg(*param, double);
                    uint8_t i;

                    value = f;
                    lenUsed += Logger_PrintInt(logBuff + lenUsed,logDataLen - lenUsed,value, 10u, 0u, field_width, format_flags);
                    lenUsed += Logger_StoreChar(logBuff + lenUsed,logDataLen - lenUsed,'.');
                    if(num_digits == 0u)
                        num_digits = 6u;
                    for(i = 0u; i < num_digits; i++)
                    {
                        f = (f - value) * 10.0f;
                        value = f;
                        if(value < 0.0f)
                        {
                            value = -value;
                        }
                        lenUsed += Logger_PrintInt(logBuff + lenUsed,logDataLen - lenUsed, value, 10u, 0u, field_width, format_flags);
                    }
                }
                break;

                case 'u':
                {
                    value = va_arg(*param, int);
                    lenUsed += Logger_PrintUnsigned(logBuff + lenUsed,logDataLen - lenUsed,(uint32_t)value, 10u, num_digits, field_width, format_flags);
                    break;
                }

                case 'x':
                case 'X':
                {
                    value = va_arg(*param, int);
                    lenUsed += Logger_PrintUnsigned(logBuff + lenUsed,logDataLen - lenUsed,(uint32_t)value, 16u, num_digits, field_width, format_flags);
                }
                break;

                case 's':
                {
                    const char * s = va_arg(*param, const char *);
                    do
                    {
                        c = *s;
                        s++;
                        if (c == '\0')
                        {
                            break;
                        }
                        lenUsed += Logger_StoreChar(logBuff + lenUsed,logDataLen - lenUsed,c);
                    } while(1);
                }
                break;

                case 'S':
                {
                    const struct StrNoEnd *s = va_arg(*param, const struct StrNoEnd *);
                    uint32_t i;
                    for(i = 0u; i < s->len; i++)
                    {
                        lenUsed += Logger_StoreChar(logBuff + lenUsed,logDataLen - lenUsed,s->str[i]);
                    }
                }
                break;

                case 'p':
                {
                    value = va_arg(*param, int);
                    lenUsed += Logger_PrintUnsigned(logBuff + lenUsed,logDataLen - lenUsed,(uint32_t)value, 16u, 8u, 8u, 0u);
                }
                break;

                case '%':
                {
                    lenUsed += Logger_StoreChar(logBuff + lenUsed,logDataLen - lenUsed,'%');
                }
                break;

                default:
                break;
            }
            format++;
        }
        else
        {
            lenUsed += Logger_StoreChar(logBuff + lenUsed,logDataLen - lenUsed,c);
        }
    }while (1);
    return lenUsed;
}

// 注意：1、outstr最大长度200，2、使用局部静态变量，不可重入
char* Hex2Str(uint8 *hex, int hexLen)
{
    static char str[200] = {0};
    char char_arr[17] = "0123456789ABCDEF";
    int index = 0;
    int i = 0;

    if((hex == NULL) || (hexLen == 0))
    {
        strcpy(str, "null");
        return str;
    }
    memset(str, 0, sizeof(str));
	for (i = 0; i < hexLen; i++)
	{
        if (index+4 > sizeof(str))
        {
            str[index-1] = '!';
            break;
        }
        str[index++] = char_arr[hex[i]>>4];
        str[index++] = char_arr[hex[i]&0x0F];
        str[index++] = ' ';
	}
    return str;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint16 LOG_Com_GetWritePrt(void)
{
    sint32 WritePrt = 0;
    
    WritePrt = Dma_ChannelTransferCnt((DMA_DEVICE_ID)DMA_LOG_RX);
    
    if ((WritePrt < 0)||(WritePrt > cLOG_ALG_FIFO_DEEPTH))
    {
        //gnss_warn("Lenth error WritePrt = %d.",WritePrt);
        tLOG_Com_State = eLOG_Com_Err;
        WritePrt = 0;
    }
	else if((0 == WritePrt) || (cLOG_ALG_FIFO_DEEPTH == WritePrt))
	{
		if(TRUE == Dma_ChannelTransferComplete((DMA_DEVICE_ID)DMA_LOG_RX))
		{
			Dma_ChannelTransferCompleteClear((DMA_DEVICE_ID)DMA_LOG_RX);
			WritePrt = (sint32)cLOG_ALG_FIFO_DEEPTH;
			//gnss_verbose("Dma Complete Flag Appear , %d\r\n",WritePrt);
		}
		else
		{
			WritePrt = 0 ;
		}
	}
	else
    {
        WritePrt = (sint32)cLOG_ALG_FIFO_DEEPTH - WritePrt;
    }
    return (uint16) WritePrt;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint16 LOG_Com_GetFifoLength(void)
{
    uint16 lenth = 0;
    uint16 WritePrt = 0;

    WritePrt = LOG_Com_GetWritePrt();
    
    if (tLOG_Com_State == eLOG_Com_Ready)
    {
        if (WritePrt >= sLogFIFOReadPrt)
        {
            lenth = WritePrt - (uint16)sLogFIFOReadPrt;
        }
        else
        {
            lenth = WritePrt + cLOG_ALG_FIFO_DEEPTH - (uint16)sLogFIFOReadPrt;
        }
    }
    else
    {
        lenth = 0;
    }

    return lenth;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void LOG_Com_ReadData(void)
{
    uint16 lenth = 0;
    uint16 i;
	uint8 u8Buffer;
    
    lenth = LOG_Com_GetFifoLength();

    for (i=0; i< lenth; i++)
    {
    	u8Buffer = LOG_Alg_FIFO[sLogFIFOReadPrt];
        sLogFIFOReadPrt++;
        if (sLogFIFOReadPrt >= cLOG_ALG_FIFO_DEEPTH)
        {
            sLogFIFOReadPrt = 0;
        }
	    RB_Push(RB_ID_CMD_INPUT, &u8Buffer, 1);
    }
}
void LOG_Com_DeInit(void)
{
    Uart_Close(UART_ID_LOGGER);
    Uart_Deinit(UART_ID_LOGGER);
	Dma_ChannelStop(DMA_LOG_RX);
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void LOG_Com_Init(void)
{
    sLogFIFOReadPrt = 0;
    tLOG_Com_State = eLOG_Com_Ready;
	
	RB_Init(RB_ID_LOGGER_UART);
    
    Uart_Init(UART_ID_LOGGER);
    Dma_ChannelConfiguration(DMA_LOG_RX,(void *)cRLIN35_LDBR_ADDR
    ,&LOG_Alg_FIFO[0]
    ,cLOG_ALG_FIFO_DEEPTH);
    Uart_Open(UART_ID_LOGGER);
}

void LOG_DmaErrDeal(void)
{
	static uint32 osTick;
	switch(tLOG_Com_State)
	{
		case eLOG_Com_Uninit:
			LOG_GET_OSTick(&osTick);
			//gnss_err("[LOG-E]:at %d ms , Cause Not Init , Start Init \r\n",osTick);
			LOG_Com_Init();
			//
			tLOG_Com_State = eLOG_Com_Ready;
			break;
		case eLOG_Com_Ready:
			break;
		case eLOG_Com_Err:
			LOG_GET_OSTick(&osTick);
			//gnss_err("[LOG-E]:at %d ms , Log Com Err , Start DeInit . \r\n",osTick);
			LOG_Com_DeInit();
			//GNSS_Alg_Init();
			//
			tLOG_Com_State = eLOG_Com_Uninit;
			break;
		default:
			tLOG_Com_State = eLOG_Com_Uninit;
			break;
	}
}


FUNC(void, Log_CODE) Logger_PreInit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Logger_Init
 *********************************************************************************************************************/
    RB_Return_t ret = RB_E_RESTORE;
    
    Logger_IPC_Init();
#if(LOGGER_DEV_ERROR_DETECT == STD_ON)
    if((logger_cfg.chnUart >= UART_CHN_NUM) || (logger_cfg.rbUart >= RB_ID_NUMBER) ||
        (logger_cfg.rbIpc >= RB_ID_NUMBER) || (logger_cfg.subNumber == 0u) ||
        (logger_cfg.subLevelStorage == NULL_PTR) || (logger_cfg.subNames == NULL_PTR) ||
        (logger_cfg.levelNumber == 0u) || (logger_cfg.levelNames == NULL_PTR))
    {
// TODO: < REPLACE START >
//        ret = LOGGER_E_PARAM;
// TODO: < REPLACE END >
    }
    else if(LOGGER_STATE_NOT_INIT != logger_data.state)
    {
// TODO: < REPLACE START >
//        ret = LOGGER_E_STATE;
// TODO: < REPLACE END >
    }
    else
#endif
    if (bLogIsInit == FALSE)
    {
        bLogIsInit = TRUE;
        Logger_IPC_Init();
        LOGGER_ENTER_CRITICAL();
        LOGGER_RES_INIT();
        RB_Init(logger_cfg.rbUart);
        ret = RB_Restore(logger_cfg.rbIpc);
        Uart_Init(logger_cfg.chnUart);
		
		Dma_ChannelConfiguration(DMA_LOG_RX,(void *)cRLIN35_LDBR_ADDR
		,&LOG_Alg_FIFO[0]
		,cLOG_ALG_FIFO_DEEPTH);

		
		tLOG_Com_State = eLOG_Com_Ready;
		
        logger_data.state = LOGGER_STATE_CLOSE; 
        loggerManager.uartState =LOGGER_UART_STATE_IDLE;
// TODO: < REPLACE START >
//        ret = LOGGER_SUCCESS;
// TODO: < REPLACE END >
        if (ret == RB_E_RESTORE)
        {
            Logger_LevelSetAll(LOGGER_LEVEL_DEBUG);
        }
        LOGGER_EXIT_CRITICAL();
    }



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:Log_Init_doc)  ****************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Log_MainFunction)  *******************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Log_MainFunction_doc)  ********************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Log_Init)  ***************************************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
