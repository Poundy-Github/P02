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
 *             File:  Gyro.c
 *           Config:  E:/V3P5_VIP/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Gyro
 *  Generation Time:  2020-08-11 14:20:33
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Gyro>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Gyro.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "string.h"

#include "Gyro_asm330.h"
#include "Gyro.h"
#include "logger.h"
#include "Ipc_if.h"
#include "RingBuffer.h"
#include "Misc_Board.h"



/*MACRO DEFINE*/
#define GYRO_RAD_P_DEG             (3.14159f / 180.0f)
#define GYRO_G_P_ACC               (9.81f)

#define GYRO_CYCLE_PERIOD  (20U)
#define GYRO_TIMER_COUNT_100MS     (100U/GYRO_CYCLE_PERIOD)
#define GYRO_TIMER_COUNT_200MS     (200U/GYRO_CYCLE_PERIOD)
#define GYRO_TIMER_COUNT_nMs(ms)    ((ms)/GYRO_CYCLE_PERIOD)

#define GYRO_TIMER_COUNT_20MS       (20U/GYRO_CYCLE_PERIOD)


/*STATIC VARIABLES*/
static Gyro_Info_t gyroInfo;

static GYRO_DATA_t gyroData;

static Gyro_ErrorInfo_t gyroError;

static Gyro_DrvConfig_t gryoDrvConfig;

static Gyro_State_t gyroState[GYRO_STATE_NUM];

static GYRO_SENSOR_t gyroSensor[GYRO_SENSOR_NUM] = GYRO_SENSOR_TABLE;
static boolean bIsInit = 0;


extern Std_ReturnType Misc_Board_GetHwVersion(uint8 * ver);


/*STATIC FUNCTION*/
static void Gyro_IpcTask(void);
static void Gyro_ResetState(void);
static void Gyro_NormalState(void);
static void Gyro_CorrectState(void);
static void Gyro_HandleUpdata(void);
static void Gyro_StateReqCheck(void);
static void Gyro_DataCalculate(void);
static void Gyro_CalibrateState(void);
static void Gyro_StateManageTask(void);
static GYRO_Return_t Gyro_IpcTransmit(void);
static void Gyro_SensorCheck(uint8* readreq);
static GYRO_Return_t Gyro_SetState(uint8 state);
static void Gyro_IpcLoadData(uint8 type, uint8*ipcdata);
static void Gyro_DataTransfer(Gyro_SensorCalcData_t* pcalcdata);
static void Gyro_DataOffset(Gyro_SensorData_t* pdata, Gyro_SensorData_t*poffset);
static void Gyro_CalculateOffset(Gyro_OffsetData_t* poffset, Gyro_ReadData_t* pdata);
static void Gyro_DataSensitivity(uint8 type, Gyro_SensorData_t* pdata, Gyro_SensorCalcData_t* pcalcdata);

/*STATIC FUNCTION FROM IPC*/
static void Gyro_IPCExecuteReqBatch(IPC_S2M_SensorIPCBatch_t * data);
static void Gyro_IPCCallbackFromBatch(uint8 * param, uint16 param_len);
static void Gyro_IPCExecuteReqActivate(IPC_S2M_SensorIPCActivate_t *data);
static void Gyro_IPCCallbackFromActivate(uint8 * param, uint16 param_len);

/*STATIC VARIABLES FROM IPC*/
static const GYRO_IPC_ReceiveConfig_t cGYRO_IPC_ReceiveConfigTable[GYRO_RECEIVE_NUM] = GYRO_RECEIVE_TABLE;


#ifdef GYRO_TEST
static void Gyro_TestTask(void);
static void Gyro_PrintfData(uint8 type);
#endif

//#define Gyro_ReadNvmData         NVM_ReadBlock
//#define Gyro_WriteNvmData        NVM_WriteBlock
//#define Gyro_IpcDataTransmit     IPC_M2S_Gyro_Transmit
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * A_U8_10: Array with 10 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Gyro_START_SEC_CODE
#include "Gyro_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Gyro_IPCCallbackM
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Sv_IPC_Gyro_Req>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Sd_IPC_Gyro_Message_Element(const uint8 *data)
 *     Argument data: uint8* is of type A_U8_10
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Gyro_IPCCallbackM(uint8 major_msg_id, uint8 sub_msg_id, uint8 *param, uint16 param_len)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_IPCCallbackM_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Gyro_CODE) Gyro_IPCCallbackM(uint8 major_msg_id, uint8 sub_msg_id, P2VAR(uint8, AUTOMATIC, RTE_GYRO_APPL_VAR) param, uint16 param_len) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_IPCCallbackM
 *********************************************************************************************************************/
    uint8 i;
    boolean bResult = FALSE;

    for (i = 0; (i < GYRO_RECEIVE_NUM) && (FALSE == bResult); i++)
    {
        if ((major_msg_id == cGYRO_IPC_ReceiveConfigTable[i].major_msg_id) &&
             (sub_msg_id == cGYRO_IPC_ReceiveConfigTable[i].sub_msg_id))
        {
            bResult = TRUE;

            if (NULL_PTR != cGYRO_IPC_ReceiveConfigTable[i].callback)
            {
                cGYRO_IPC_ReceiveConfigTable[i].callback(param, param_len);
            }
        }
    }

    if (TRUE == bResult)
    {
        RI_GYRO_TraceMainFunction();
    }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Gyro_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <Gyro_Init_server>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Gyro_Init(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Gyro_CODE) Gyro_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_Init
 *********************************************************************************************************************/
	memset((uint8*)&gyroInfo, 0x00U, sizeof(gyroInfo));
	memset((uint8*)&gyroData, 0x00U, sizeof(gyroData));
	memset((uint8*)&gyroError, 0x00U, sizeof(gyroError));
	memset((uint8*)&gyroState[0], 0x00U, sizeof(gyroState));
	memset((uint8*)&gryoDrvConfig, 0x00U, sizeof(gryoDrvConfig));	 
	Gyro_DriInit();
	RB_Init(RB_ID_GYRO_IPC);
	bIsInit = FALSE;
	gryoDrvConfig.accrate = ASM330_ACC_RATE(ASM330_ACC_RATE_53HZ);
	gryoDrvConfig.accscale = ASM330_ACC_SCALE(ASM330_ACC_SCALE_2G);
	gryoDrvConfig.gyrorate = ASM330_GYRO_RATE(ASM330_GYRO_RATE_53HZ);
	gryoDrvConfig.gyroscale = ASM330_GYRO_SCALE(ASM330_GYRO_SCALE_250DPS);

	gyroSensor[GYRO_ACC_SENSOR].period = GYRO_TIMER_COUNT_200MS;
	gyroSensor[GYRO_ACC_SENSOR].timer = GYRO_TIMER_COUNT_200MS;

	gyroSensor[GYRO_GYRO_SENSOR].period = GYRO_TIMER_COUNT_200MS;
	gyroSensor[GYRO_GYRO_SENSOR].timer = GYRO_TIMER_COUNT_200MS;

	gyroSensor[GYRO_ACC_SENSOR].timestap = TRUE;
	gyroSensor[GYRO_GYRO_SENSOR].timestap = TRUE;
#ifdef GYRO_TEST
	GYRO_DEBUG("GYRO TEST \n");
	Gyro_TestTask();
#endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Gyro_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_Rc_IPC_Gyro_Message_Element(uint8 *data)
 *     Argument data: uint8* is of type A_U8_10
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Sd_IIC1_Notify_Message_Message(uint16 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Gyro(void)
 *   void Rte_Exit_ExclusiveArea_Gyro(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Gyro_CODE) Gyro_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Gyro_MainFunction
 *********************************************************************************************************************/
    
    Gyro_IpcTask();
    
    Gyro_StateReqCheck();
    
    Gyro_StateManageTask();
    
    Gyro_DriverTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Gyro_STOP_SEC_CODE
#include "Gyro_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define Gyro_START_SEC_CODE
#include "Gyro_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_StateManageTask(void)
{
    switch(gyroInfo.state)
    {
        case GYRO_STATE_OFF:
            /*do nothing, Wait for users to configure*/
            break;
        case GYRO_STATE_RESET:
            Gyro_ResetState();
            break;
        case GYRO_STATE_NORMAL:
            Gyro_NormalState();
            break;
        case GYRO_STATE_CORRECT:
            Gyro_CorrectState();
            break;
        case GYRO_STATE_CALIBRATE:
            Gyro_CalibrateState();
            break;
        default:
			/* nothing to do */
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/ 
static void Gyro_ResetState(void)
{
    Gyro_DrvReturn_t driver = GYRO_DRV_RETURN_FAIL;    
    Gyro_State_t* state = &gyroState[GYRO_STATE_RESET];
    
    switch(state->handle)
    {
        case GYRO_RESET_HANDLE_READ_NVM:
            /*Gyro_ReadNvmData((uint8*)(&gyroData.offset);*/ /*Todo: RTE interface*/
            state->handle = GYRO_RESET_HANDLE_CONFIG;
            break;
        case GYRO_RESET_HANDLE_CONFIG:          
            driver = Gyro_DrvResetReq(&gryoDrvConfig);
            if(driver == GYRO_DRV_RETURN_SUCCESS)
            {
                state->handle = GYRO_RESET_HANDLE_PENGDING;
            }
            break;
        case GYRO_RESET_HANDLE_WAIT:
            state->cnt++;
            if(state->cnt >= GYRO_TIMER_COUNT_200MS)
            {
                state->cnt = 0U;
                state->handle = GYRO_RESET_HANDLE_READ_NVM;
                
                Gyro_SetState(GYRO_STATE_NORMAL);
            }
            break;
        case GYRO_RESET_HANDLE_PENGDING:           
            if(GYRO_RESET_SUCCESS_IND == gyroInfo.ind)
            {
                gyroInfo.ind = GYRO_NO_INDICATION;
                state->handle = GYRO_RESET_HANDLE_WAIT;
            }
            break;
        case GYRO_HANDLE_ERROR:
            /*Todo:need initialization state */
            break;
        default:
			/* nothing to do */
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_NormalState(void)
{
    uint8 readreq = 0U;
    GYRO_Return_t ret = GYRO_Return_Fail;
    Gyro_DrvReturn_t driver = GYRO_DRV_RETURN_FAIL;    
    Gyro_State_t* state = &gyroState[GYRO_STATE_NORMAL];
    
    switch(state->handle)
    {
        case GYRO_NORMAL_HANDLE_READ_DATA:
            Gyro_SensorCheck(&readreq);
            if(readreq != 0)
            {
                state->busy = TRUE;
                
                driver = Gyro_DrvReadReq(readreq, &gyroData.read);
                if(driver == GYRO_DRV_RETURN_SUCCESS)
                {
                    state->handle = GYRO_NORMAL_HANDLE_PENDING;
                }
            }
            break;
        case GYRO_NORMAL_HANDLE_TRANSMIT:
            Gyro_DataCalculate();
            
            ret = Gyro_IpcTransmit();
            if(ret == GYRO_Return_Success)
            {
                state->busy = FALSE;
                state->handle = GYRO_NORMAL_HANDLE_READ_DATA;
            }
            else
            {
                /*repeat ipc transmit*/
                state->handle = GYRO_NORMAL_HANDLE_TRANSMIT;
            }
            break;
        case GYRO_NORMAL_HANDLE_PENDING:
            if(GYRO_READ_SUCCESS_IND == gyroInfo.ind)
            {
                gyroInfo.ind = GYRO_NO_INDICATION;
                state->handle = GYRO_NORMAL_HANDLE_TRANSMIT;
                Gyro_HandleUpdata();
            }
            break;
        case GYRO_HANDLE_ERROR:
            /*Todo:need initialization state */
            /*Todo:notify SOC sensor failure*/
            break;
        default:
			/* nothing to do */
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_CorrectState(void)
{
    Gyro_DrvReturn_t driver = GYRO_DRV_RETURN_FAIL;    

    Gyro_State_t* state = &gyroState[GYRO_STATE_RESET];

    switch(state->handle)
    {
        case GYRO_CORRECT_HANDLE_READ_DATA:
            if(state->cnt < GYRO_CORRECT_SAMPLE_NUM)
            {
                driver = Gyro_DrvReadReq(GYRO_ACC_DATA_TYPE|GYRO_GYRO_DATA_TYPE, &gyroData.correct[state->cnt]);
                if(driver == GYRO_DRV_RETURN_SUCCESS)
                {
                    state->handle = GYRO_CORRECT_HANDLE_PENDING;
                }
            }
            else
            {
                state->handle = GYRO_CORRECT_HANDLE_CALCULATE;
            }
            break;
        case GYRO_CORRECT_HANDLE_CALCULATE:
            Gyro_CalculateOffset(&gyroData.offset, &gyroData.correct[0]);
            /*Gyro_WriteNvmData(&gyroData.offset);*/ /*Todo: RTE interface*/
            state->handle = GYRO_CORRECT_HANDLE_COMPLETE;
            break;
        case GYRO_CORRECT_HANDLE_COMPLETE:
            /*Todo: Notify RTE correct success*/
            Gyro_SetState(GYRO_STATE_NORMAL);
            
            state->cnt = 0U;
            state->handle = GYRO_CORRECT_HANDLE_READ_DATA;
            break;
        case GYRO_CORRECT_HANDLE_PENDING:
            if(GYRO_READ_SUCCESS_IND == gyroInfo.ind)
            {
                state->cnt++;
                state->handle = GYRO_CORRECT_HANDLE_READ_DATA;
            }
            break;
        case GYRO_HANDLE_ERROR:
            /*Todo:need initialization state */
            /*Todo:Notify RTE correct fail*/
            Gyro_SetState(GYRO_STATE_NORMAL);
            break;
        default:
			/* nothing to do */
            break;
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_CalibrateState(void)
{
    /*Calibrate state*/
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IpcTask(void)
{
    /*Handle IPC events*/
    boolean bResult = FALSE;
    GYRO_IPC_RequsetHandle_t tRequsetHandle;
    uint8 ver = MiscBoard_Version_Def;
    Std_ReturnType ret = E_NOT_OK;

    ret = Misc_Board_GetHwVersion(&ver);

    
    while(RB_Pop(RB_ID_GYRO_IPC,(uint8 *)&tRequsetHandle,sizeof(GYRO_IPC_RequsetHandle_t)) > 0 )
    {
        if ((ret == E_NOT_OK)||(ver >= eMiscBoard_Version_B1))
        {
            IPC_M2S_SensorIPCSensorReply_t reply;
            bResult = FALSE;
            
            reply.state = GYRO_IPC_REPLY_NOK;
            if (tRequsetHandle.u8ReqType == GYRO_IPC_ACTIVATE_MASK)
            {
                reply.handle = tRequsetHandle.data.Activate.handle;
                reply.id = IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_ID;
            }
            else if (tRequsetHandle.u8ReqType == GYRO_IPC_BATCH_MASK)
            {
                reply.handle = tRequsetHandle.data.Batch.handle;
                reply.id = IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_ID;
            }
            IPC_M2S_SensorIPCSensorReply_Transmit(&reply);
        }
        else if (tRequsetHandle.u8ReqType == GYRO_IPC_ACTIVATE_MASK)
        {
            bResult = TRUE;
            Gyro_IPCExecuteReqActivate(&tRequsetHandle.data.Activate);
        }
        else if (tRequsetHandle.u8ReqType == GYRO_IPC_BATCH_MASK)
        {
            bResult = TRUE;
            Gyro_IPCExecuteReqBatch(&tRequsetHandle.data.Batch);
        }
        else
        {
            /* Do nothing */
        }
    }
    if (TRUE == bResult)
    {
        if (bIsInit == FALSE)
        {
            bIsInit = TRUE;
            gyroInfo.statereq = GYRO_STATE_RESET;
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_StateReqCheck()
{
    if(gyroInfo.statereq != GYRO_STATE_INVALID)
    {
        /*only when normal is not busy, it is allowed to switch correct or calibrate */
        if((gyroInfo.statereq == GYRO_STATE_CORRECT) || (gyroInfo.statereq == GYRO_STATE_CALIBRATE))
        {
            if(gyroState[GYRO_STATE_NORMAL].busy == FALSE)
            {
                gyroInfo.state = gyroInfo.statereq;
                gyroInfo.statereq = GYRO_STATE_INVALID;
            }
        }
        else
        {
            gyroInfo.state = gyroInfo.statereq;
            gyroInfo.statereq = GYRO_STATE_INVALID;
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static GYRO_Return_t Gyro_IpcTransmit(void)
{
    uint8 idx = 0U;
    uint8 length = 0U;
    GYRO_Return_t ret = GYRO_Return_Fail;
    e_IPC_ErrorType_t ipcstate = IPC_ERR_NONE;
    
    GYRO_SENSOR_t* psensor;
    
    for(idx = 0; idx < GYRO_SENSOR_NUM; idx++)
    {
        psensor = &gyroSensor[idx];
        if(psensor->ready != FALSE)
        {
            psensor->ready = FALSE;
            /*Todo:load IPC data*/
            Gyro_IpcLoadData(psensor->type, &gyroData.ipc[length]);
            /*length += psensor->size;*/ 

            #ifdef GYRO_TEST
            Gyro_PrintfData(psensor->type);
            #endif
        }
    }

    /*ipcstate = Gyro_IpcDataTransmit(gyroData.ipc);*/ /*Todo: IPC interface*/

    if(IPC_ERR_NONE == ipcstate)
    {
        ret = GYRO_Return_Success;
    }
    else
    {
        Gyro_TriggerError(GYRO_IIC_ERROR_TYPE);
        ret = GYRO_Return_Success;
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IpcLoadData(uint8 type, uint8*ipcdata)
{
    /*Todo: load data sent to SOC*/
    IPC_M2S_SensorIPCSensorData_t tData;
    if (type == ASM330_ACC_DATA_TYPE)
    {
        tData.handle = GYRO_IPC_ACC_HANDLE;
        tData.x = gyroSensor[GYRO_ACC_SENSOR].pclacdata->x;
        tData.y = gyroSensor[GYRO_ACC_SENSOR].pclacdata->y;
        tData.z = gyroSensor[GYRO_ACC_SENSOR].pclacdata->z;
    }
    else
    {
        tData.handle = GYRO_IPC_GYRO_HANDLE;
        tData.x = gyroSensor[GYRO_GYRO_SENSOR].pclacdata->x;
        tData.y = gyroSensor[GYRO_GYRO_SENSOR].pclacdata->y;
        tData.z = gyroSensor[GYRO_GYRO_SENSOR].pclacdata->z;
    }
    tData.timestamp =  (int64_t) gyroData.read.timestamp;
    tData.temp = gyroData.read.temp;
    
    IPC_M2S_SensorIPCSensorData_Transmit(&tData);
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_CalculateOffset(Gyro_OffsetData_t* poffset, Gyro_ReadData_t* pdata)
{
    /*Todo: offset calculate*/
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_DataOffset(Gyro_SensorData_t* pdata, Gyro_SensorData_t*poffset)
{   
    /*x y z three-axis zero offset calculate*/
    pdata->x = pdata->x + poffset->x;
    pdata->y = pdata->y + poffset->y;
    pdata->z = pdata->z + poffset->z;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_DataSensitivity(uint8 type, Gyro_SensorData_t* pdata, Gyro_SensorCalcData_t* pcalcdata)
{
    float sensitivity = Asm330_GetSensitivity(type, gryoDrvConfig.accscale);

    switch(type)
    {
        case GYRO_ACC_DATA_TYPE:
            /*  acceleration scale          mg/LSB
            *           ±2 g                0.061
            *           ±4 g                0.122
            *           ±8 g                0.244
            *           ±16 g               0.488
            *
            *acceleration sensor data uint mg, m/s2 = g * 9.81
            *Acc = data(mg) / 1000 * sensitivity * 9.81
            */
            sensitivity = Asm330_GetSensitivity(GYRO_ACC_DATA_TYPE, gryoDrvConfig.accscale);
            pcalcdata->x = pdata->x * sensitivity * GYRO_G_P_ACC / 1000;
            pcalcdata->y = pdata->y * sensitivity * GYRO_G_P_ACC / 1000;
            pcalcdata->z = pdata->z * sensitivity * GYRO_G_P_ACC / 1000;
            break;
        case GYRO_GYRO_DATA_TYPE:
            /*     gryoscope scale               mdps/LSB
            *           ±125  dps                4.37
            *           ±250  dps                8.75
            *           ±500  dps                17.5
            *           ±1000 dps                35.0
            *           ±2000 dps                70.0
            *           ±4000 dps                140.0
            *               
            *gyroscope sensor data uint mdps, deg = dps * pi / 180
            *GYRO = data(mdps) / 1000 * sensitivity * pi / 180
            */
            sensitivity = Asm330_GetSensitivity(GYRO_GYRO_DATA_TYPE, gryoDrvConfig.gyroscale);
            pcalcdata->x = pdata->x * sensitivity * GYRO_RAD_P_DEG / 1000;
            pcalcdata->y = pdata->y * sensitivity * GYRO_RAD_P_DEG / 1000;
            pcalcdata->z = pdata->z * sensitivity * GYRO_RAD_P_DEG / 1000;
            break;
        default:
			/* nothing to do */
            break;        
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_DataTransfer(Gyro_SensorCalcData_t* pcalcdata)
{
    /*Todo: sensor coordinate to vehicle coordinate*/
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_DataCalculate(void)
{
    uint8 idx;
    GYRO_SENSOR_t* sensor = NULL_PTR;
    
    for(idx = 0; idx < GYRO_SENSOR_NUM; idx++)
    {
        sensor = &gyroSensor[idx];
        if(sensor->ready != FALSE)
        {
            Gyro_DataOffset(sensor->pdata, sensor->poffset);
            Gyro_DataSensitivity(sensor->type, sensor->pdata, sensor->pclacdata);
            Gyro_DataTransfer(sensor->pclacdata);
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_SensorCheck(uint8* readreq)
{
    uint8 idx;
    GYRO_SENSOR_t* psensor;

    for(idx = 0U; idx < GYRO_SENSOR_NUM; idx++)
    {
        psensor = &gyroSensor[idx];

        if(psensor->active != FALSE)
        {
            psensor->timer--;
            if(psensor->timer == 0U)
            {
                psensor->ready = TRUE;
                psensor->timer = psensor->period;
                *readreq |= psensor->type;
                
                if(psensor->timestap == TRUE)
                {
                    *readreq |= GYRO_TIMESTAMP_DATA_TYPE;
                }

                
                *readreq |= GYRO_TEMP_DATA_TYPE;
                
            }
        }
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static GYRO_Return_t Gyro_SetState(uint8 req)
{
    GYRO_Return_t ret = GYRO_Return_Fail;

    /*only in normal state, it is allowed to switch correct or calibrate */
    if((req == GYRO_STATE_CORRECT) || (req == GYRO_STATE_CALIBRATE))
    {
        if((gyroInfo.state == GYRO_STATE_NORMAL) && (gyroInfo.statereq == GYRO_STATE_INVALID))
        {
            gyroInfo.statereq = req;
            ret = GYRO_Return_Success;
        }
        else
        {
            /*sensor is not initialized */
            ret = GYRO_Return_Fail;
        }
    }
    else
    {
        gyroInfo.statereq = req;
        ret = GYRO_Return_Success;
    }
    
    return ret;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_HandleUpdata(void)
{
    Gyro_SendMessage();
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_SetStateHandle(uint8 handle)
{
    //gyroState[gyroInfo.state].handle = handle;
    IPC_M2S_SensorIPCSensorState_t tDate;
    tDate.handle = handle;
    tDate.state = GYRO_IIC_ERROR_TYPE;
    IPC_M2S_SensorIPCSensorState_Transmit(&tDate);
    
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Gyro_SetIndication(uint8 ind)
{
    gyroInfo.ind = ind;
    
    Gyro_SendMessage();
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Gyro_TriggerError(uint8 type)
{
    if(type == GYRO_IIC_ERROR_TYPE)
    {
        gyroError.i2c++;
        if(gyroError.i2c >= 2)
        {
            Gyro_SetStateHandle(GYRO_HANDLE_ERROR);
        }
    }

    if(type == GYRO_IPC_ERROR_TYPE)
    {
        /*Notify DEM ipc error*/
    }
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void Gyro_SendMessage(void)
{
    RI_GYRO_TraceMainFunction();
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
GYRO_Return_t Gyro_GetDeviceId(uint8* pdata)
{
    GYRO_Return_t ret = GYRO_Return_Fail;
    Gyro_DrvReturn_t drvres = GYRO_DRV_RETURN_FAIL; 
    
    if(pdata != NULL_PTR)
    {
        drvres = Gyro_GetDrvDeviceId(pdata);

        if(drvres == GYRO_DRV_RETURN_SUCCESS)
        {
            ret = GYRO_Return_Success;
        }
    }
    else
    {
        ret = GYRO_Return_Fail;
    }

    return ret;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IPCCallbackFromActivate(uint8 * param, uint16 param_len)
{
    if (NULL_PTR != param)
    {
        GYRO_IPC_RequsetHandle_t tRequsetHandle;
        IPC_S2M_SensorIPCActivate_Receive(param, &tRequsetHandle.data.Activate, param_len);
        tRequsetHandle.u8ReqType = GYRO_IPC_ACTIVATE_MASK;

        RB_Push(RB_ID_GYRO_IPC,(uint8 *)&tRequsetHandle,sizeof(GYRO_IPC_RequsetHandle_t));
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IPCCallbackFromBatch(uint8 * param, uint16 param_len)
{
    if (NULL_PTR != param)
    {
        GYRO_IPC_RequsetHandle_t tRequsetHandle;
        IPC_S2M_SensorIPCBatch_Receive(param, &tRequsetHandle.data.Batch, param_len);
        tRequsetHandle.u8ReqType = GYRO_IPC_BATCH_MASK;
        RB_Push(RB_ID_GYRO_IPC,(uint8 *)&tRequsetHandle,sizeof(GYRO_IPC_RequsetHandle_t));
    }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IPCExecuteReqActivate(IPC_S2M_SensorIPCActivate_t *data)
{
    IPC_M2S_SensorIPCSensorReply_t reply;
    if (data->handle == GYRO_IPC_GYRO_HANDLE)
    {
        gyroSensor[1].active = data->enable;
        reply.state = GYRO_IPC_REPLY_OK;
    }
    else if (data->handle ==  GYRO_IPC_ACC_HANDLE)
    {
        gyroSensor[0].active = data->enable;
        reply.state = GYRO_IPC_REPLY_OK;
    }
    else
    {
        reply.state = GYRO_IPC_REPLY_NOK;
    }
    reply.handle = data->handle;
    reply.id = IPC_S2M_SENSOR_IPC_MSGSUB_ACTIVATE_ID;
    
    IPC_M2S_SensorIPCSensorReply_Transmit(&reply);
}





/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void Gyro_IPCExecuteReqBatch(IPC_S2M_SensorIPCBatch_t * data)
{
    IPC_M2S_SensorIPCSensorReply_t reply;
    uint8 time_cnt;
    uint8 type=0;

    time_cnt = (data->period_ns / 1000000) / GYRO_CYCLE_PERIOD;

    if ( (time_cnt >= GYRO_TIMER_COUNT_20MS) &&(time_cnt <= GYRO_TIMER_COUNT_200MS))
    {
        if (data->handle == GYRO_IPC_GYRO_HANDLE)
        {
            type = GYRO_GYRO_SENSOR;
        }
        else if (data->handle == GYRO_IPC_ACC_HANDLE)
        {
            type = GYRO_ACC_SENSOR;
        }
        gyroSensor[type].period = time_cnt;
//        gyroSensor[type].timer = time_cnt;
        reply.state = GYRO_IPC_REPLY_OK;
    }
    else 
    {
        reply.state = GYRO_IPC_REPLY_NOK;
    }

    reply.handle = data->handle;
    reply.id = IPC_S2M_SENSOR_IPC_MSGSUB_BATCH_ID;

    IPC_M2S_SensorIPCSensorReply_Transmit(&reply);
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
GYRO_SENSOR_t * GetGyroSensor(void)
{
    return gyroSensor;
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
GYRO_DATA_t * GetGyroSensorData(void)
{
    return &gyroData;
}
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
 #ifdef GYRO_TEST
static void Gyro_TestTask(void)
{
    gyroInfo.statereq = GYRO_STATE_RESET;

    gryoDrvConfig.accrate = ASM330_ACC_RATE(ASM330_ACC_RATE_53HZ);
    gryoDrvConfig.accscale = ASM330_ACC_SCALE(ASM330_ACC_SCALE_2G);
    gryoDrvConfig.gyrorate = ASM330_GYRO_RATE(ASM330_GYRO_RATE_53HZ);
    gryoDrvConfig.gyroscale = ASM330_GYRO_SCALE(ASM330_GYRO_SCALE_250DPS);

    gyroSensor[GYRO_ACC_SENSOR].active = TRUE;
    gyroSensor[GYRO_ACC_SENSOR].period = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_ACC_SENSOR].timer = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_ACC_SENSOR].timestap = FALSE;

    gyroSensor[GYRO_GYRO_SENSOR].active = TRUE;
    gyroSensor[GYRO_GYRO_SENSOR].period = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_GYRO_SENSOR].timer = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_GYRO_SENSOR].timestap = FALSE;
}

static void Gyro_PrintfData(uint8 type)
{
    switch(type)
    {
        case GYRO_ACC_DATA_TYPE:
//            GYRO_DEBUG("ACC Sensor Raw Data x:%d y:%d z:%d timestap:%ld  temp %f°C", \
//                 gyroData.read.acc.x, gyroData.read.acc.y, gyroData.read.acc.z, gyroData.read.timestamp, gyroData.read.temp); 
//            GYRO_DEBUG("\r\n");     
            GYRO_DEBUG("ACC Sensor Calc Data x:%f g y:%f g z:%f g timestap:%ldus  temp %f°C", \
                 gyroData.calc.acc.x, gyroData.calc.acc.y, gyroData.calc.acc.z, gyroData.read.timestamp, gyroData.read.temp);
             GYRO_DEBUG("\r\n");
            break;
        case GYRO_GYRO_DATA_TYPE:
//            GYRO_DEBUG("GYRO Sensor Raw Data x:%d y:%d z:%d timestap:%ld  temp %f°C", \
//                 gyroData.read.gyro.x, gyroData.read.gyro.y, gyroData.read.gyro.z, gyroData.read.timestamp, gyroData.read.temp); 
//            GYRO_DEBUG("\r\n");     
            GYRO_DEBUG("GYRO Sensor Calc Data x:%f deg y:%f deg z:%f deg timestap:%ldus  temp %f°C", \
                 gyroData.calc.gyro.x, gyroData.calc.gyro.y, gyroData.calc.gyro.z, gyroData.read.timestamp, gyroData.read.temp); 
            GYRO_DEBUG("\r\n");
    }
}
#define Gyro_STOP_SEC_CODE
#include "Gyro_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: documentation area:Gyro_Init_doc)  ***************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:Gyro_Init)  **************************************/
    memset((uint8*)&gyroInfo, 0x00U, sizeof(gyroInfo));
    memset((uint8*)&gyroData, 0x00U, sizeof(gyroData));
    memset((uint8*)&gyroError, 0x00U, sizeof(gyroError));
    memset((uint8*)&gyroState[0], 0x00U, sizeof(gyroState));
    memset((uint8*)&gryoDrvConfig, 0x00U, sizeof(gryoDrvConfig));    
    Gyro_DriInit();
    RB_Init(RB_ID_GYRO_IPC);
    bIsInit = FALSE;
    gryoDrvConfig.accrate = ASM330_ACC_RATE(ASM330_ACC_RATE_53HZ);
    gryoDrvConfig.accscale = ASM330_ACC_SCALE(ASM330_ACC_SCALE_2G);
    gryoDrvConfig.gyrorate = ASM330_GYRO_RATE(ASM330_GYRO_RATE_53HZ);
    gryoDrvConfig.gyroscale = ASM330_GYRO_SCALE(ASM330_GYRO_SCALE_250DPS);

    gyroSensor[GYRO_ACC_SENSOR].period = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_ACC_SENSOR].timer = GYRO_TIMER_COUNT_200MS;

    gyroSensor[GYRO_GYRO_SENSOR].period = GYRO_TIMER_COUNT_200MS;
    gyroSensor[GYRO_GYRO_SENSOR].timer = GYRO_TIMER_COUNT_200MS;
    
    gyroSensor[GYRO_ACC_SENSOR].timestap = TRUE;
    gyroSensor[GYRO_GYRO_SENSOR].timestap = TRUE;
    #ifdef GYRO_TEST
    GYRO_DEBUG("GYRO TEST \n");
    Gyro_TestTask();
    #endif

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
