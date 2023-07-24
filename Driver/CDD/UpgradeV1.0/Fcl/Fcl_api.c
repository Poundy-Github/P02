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
 * @file:      Fcl_api.c
 * @author:    Nobo
 * @date:      2020-12-12
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-12
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "logger.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "r_typedefs.h"
#include "r_fcl_types.h"
#include "fcl_cfg.h"
#include "r_fcl.h"
#include "fcl_descriptor.h"
#include "fcl_user.h"
#include "r_fcl_global.h"
#include "r_fcl_env.h"
#include "Csm.h"
#include "stdio.h"
#include "string.h"
#define HSM_USED
#ifdef HSM_USED
#include "Cdd_Hsm.h"
#endif
#include "Os.h"

#include "Fcl_Api.h"

#include "Fcl_F1MS4_Cfg.c"

typedef r_fcl_status_t (*fpwait_t)(void);

/**
 * @brief 
 * 
 */
typedef struct
{
    FclCommState currentComm;
    FclCommState nextComm;
    boolean hold;
    uint32 time;
} FCL_WAIT_PARAM;

typedef struct
{
    uint8 data[0x200];
    uint32 addr;
    uint32 len;
} FCL_P_DATA;
/**
 * @brief 
 * 
 */
typedef struct Fcl_api
{
    boolean init;
    Fcl_Block *block;
    FclCommState CommState;
    uint32 commRetry;
    fcl_init_cbk init_cbk;
    fcl_err_cbk err_cbk;
    fcl_erase_comp_cbk erase_comp_cbk;
    fcl_erase_region_cbk erase_region_cbk;
    fcl_write_comp_cbk write_comp_cbk;
    r_fcl_request_t request;
    FCL_WAIT_PARAM waitParam;
    FCL_P_DATA P_DATA;
} FCL_PCB;

/**
 * @brief 
 * 
 */
static FCL_PCB FclPcb = {
    FALSE,
    NULL,
    FCL_COMM_IDLE,
    10,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    {0},
    {0},
    {0}};
fpwait_t fpwait;

/*************************************************************************************/
#define FCL_RAM_EXECUTION_AREA_SIZE 0x8000
#if R_FCL_COMPILER == R_FCL_COMP_GHS
#pragma ghs startdata
#pragma ghs section bss = ".FCL_RESERVED"
#define R_FCL_NOINIT
#endif

uint8_t FCL_Copy_area[FCL_RAM_EXECUTION_AREA_SIZE];

#if R_FCL_COMPILER == R_FCL_COMP_GHS
#pragma ghs section bss = default
#pragma ghs enddata
#endif

/*************************************************************************************/
#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
#if R_FCL_COMPILER == R_FCL_COMP_GHS
#pragma ghs section text = ".R_FCL_CODE_USR"
#endif
#endif
/**
 * @brief 
 * 
 * @param wait 
 * @param time 
 * @return r_fcl_status_t 
 */
static r_fcl_status_t _fcl_wait(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;

#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
    if (FclPcb.waitParam.hold == TRUE)
    {
        while ((R_FCL_BUSY == FclPcb.request.status_enu) && (FclPcb.waitParam.time--))
        {
            R_FCL_Handler();
        }
        if (R_FCL_OK == FclPcb.request.status_enu)
        {
            FclPcb.CommState = FclPcb.waitParam.nextComm;
            fclRet = R_FCL_OK;
        }
        else
        {
            if(FclPcb.err_cbk!=NULL)
            {
                FclPcb.err_cbk(FclPcb.request.status_enu);
            }
            fclRet = FclPcb.request.status_enu;
        }
    }
    else
    {
        uint32 time = FclPcb.waitParam.time;
        R_FCL_ResumeRequest();
        do
        {
            R_FCL_Handler();
        } while (FclPcb.request.status_enu == R_FCL_SUSPENDED);

        do
        {
            R_FCL_Handler();

        } while ((FclPcb.request.status_enu == R_FCL_BUSY) && (time--));

        if (FclPcb.request.status_enu == R_FCL_BUSY)
        {
            R_FCL_SuspendRequest();
            do
            {
                R_FCL_Handler();
            } while (FclPcb.request.status_enu == R_FCL_BUSY);
        }
        if(FclPcb.request.status_enu == R_FCL_OK)
        {
            FclPcb.CommState = FclPcb.waitParam.nextComm;
            if(FclPcb.request.command_enu == R_FCL_CMD_ERASE)
            {
                if(FclPcb.erase_region_cbk!=NULL)
                    FclPcb.erase_region_cbk(FclPcb.request.idx_u32);
            }
            else if(FclPcb.request.command_enu == R_FCL_CMD_WRITE)
            {
                if(FclPcb.write_comp_cbk!=NULL)
                    FclPcb.write_comp_cbk(
                        FclPcb.request.idx_u32,
                        FclPcb.request.cnt_u16*256);
            }

            fclRet = R_FCL_OK;
        }
        else if(FclPcb.request.status_enu == R_FCL_SUSPENDED)
        {
            ;
        }
        else
        {
            if(FclPcb.err_cbk!=NULL)
            {
                FclPcb.err_cbk(FclPcb.request.status_enu);
            }
            fclRet = FclPcb.request.status_enu;
        }
        
    }
#endif

    return fclRet;
}

/**
 * @brief 
 * 
 * @return r_fcl_status_t 
 */
static r_fcl_status_t _fcl_Init(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;

    fclRet = R_FCL_Init(&sampleApp_fclConfig_enu);
    if (R_FCL_OK == fclRet)
    {
        fclRet = R_FCL_CopySections();
        if (R_FCL_OK == fclRet)
        {
            fpwait = (fpwait_t)R_FCL_CalcFctAddr((uint32_t)(&_fcl_wait));
            FclPcb.request.command_enu = R_FCL_CMD_PREPARE_ENV;
            R_FCL_Execute(&FclPcb.request);
            FclPcb.waitParam.hold = TRUE;
            FclPcb.waitParam.time = 100;
            _fcl_wait();
            FclPcb.request.command_enu = R_FCL_CMD_DISABLE_LOCKBITS;
            R_FCL_Execute(&FclPcb.request);
            FclPcb.waitParam.hold = TRUE;
            FclPcb.waitParam.time = 100;
            _fcl_wait();

            FclPcb.CommState = FCL_COMM_IDLE;
            FclPcb.block = blocks;
            memcpy(FclPcb.block, const_blocks, sizeof(blocks));
            (void)upgrade_info("%s :Fcl Init ok\r\n", __FUNCTION__);
            if(FclPcb.init_cbk!=NULL)
            {
                FclPcb.init_cbk();
            }
        }
    }
    else
    {
        (void)upgrade_warn("%s :Fcl Init not ok and retry: [%d], Error:[%d]\r\n", __FUNCTION__, FclPcb.commRetry, fclRet);
    }
    return fclRet;
}

/**
 * @brief 
 * 
 * @return r_fcl_status_t 
 */
static r_fcl_status_t _fcl_Prepare(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;

    FclPcb.request.command_enu = R_FCL_CMD_PREPARE_ENV;
    R_FCL_Execute(&FclPcb.request);
    fclRet = FclPcb.request.status_enu;

    if (R_FCL_BUSY == fclRet)
    {
        FclPcb.waitParam.currentComm = FCL_COMM_PREPARE;
        FclPcb.waitParam.nextComm = FCL_COMM_DIS_LOCKBITS;
        FclPcb.waitParam.hold = TRUE;
        FclPcb.waitParam.time = 100;
        FclPcb.CommState = FCL_COMM_WAIT;
    }
    else if (R_FCL_OK == fclRet)
    {
        FclPcb.CommState = FCL_COMM_DIS_LOCKBITS;
    }

    return fclRet;
}

/**
 * @brief 
 * 
 * @return r_fcl_status_t 
 */
static r_fcl_status_t _fcl_DisableLockBits(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;

    FclPcb.request.command_enu = R_FCL_CMD_DISABLE_LOCKBITS;
    R_FCL_Execute(&FclPcb.request);
    fclRet = FclPcb.request.status_enu;
    if (R_FCL_BUSY == fclRet)
    {
        FclPcb.waitParam.currentComm = FCL_COMM_DIS_LOCKBITS;
        FclPcb.waitParam.nextComm = FCL_COMM_IDLE;
        FclPcb.waitParam.hold = TRUE;
        FclPcb.waitParam.time = 100;
        FclPcb.CommState = FCL_COMM_WAIT;
    }
    else if (R_FCL_OK == fclRet)
    {
        FclPcb.CommState = FCL_COMM_IDLE;
    }
}

/*
 * @brief 
 * 
 * @param Region 
 * @param Cnt 
 * @return r_fcl_status_t 
 */
static r_fcl_status_t _fcl_Erase(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;
    uint32 Region = 0;
    uint16 Cnt = 1;
    uint32 blockId = 0;
    Fcl_Block *b;
    for (blockId = 0; blockId < sizeof(blocks) / sizeof(Fcl_Block); blockId++)
    {
        b = &FclPcb.block[blockId];
        if (b->E_V == FCL_OP_READY)
        {
            Region = b->Region;
            Cnt = 1;

            FclPcb.request.command_enu = R_FCL_CMD_ERASE;
            FclPcb.request.idx_u32 = Region;
            FclPcb.request.cnt_u16 = Cnt;
            R_FCL_Execute(&FclPcb.request);
            fclRet = FclPcb.request.status_enu;
            if (R_FCL_BUSY == fclRet)
            {
                FclPcb.waitParam.currentComm = FCL_COMM_ERASE;
                FclPcb.waitParam.nextComm = FCL_COMM_ERASE;
                FclPcb.waitParam.hold = FALSE;
                FclPcb.waitParam.time = 200;
                FclPcb.CommState = FCL_COMM_WAIT;
                b->E_V = FCL_OP_BUSY;
            }
            else if (R_FCL_OK == fclRet)
            {
                FclPcb.CommState = FCL_COMM_ERASE;
            }
            break;
        }
        else if (b->E_V == FCL_OP_BUSY)
        {
            b->E_V = FCL_OP_COMPLETE;
        }
    }

    if(blockId==sizeof(blocks) / sizeof(Fcl_Block))
    {
        FclPcb.CommState = FCL_COMM_IDLE;
        if(FclPcb.erase_comp_cbk !=NULL)
        {
            FclPcb.erase_comp_cbk();
        }
    }

    return fclRet;
}

static r_fcl_status_t _fcl_Write(void)
{
    r_fcl_status_t fclRet = R_FCL_OK;
    uint16 reqCnt = 0;
    uint32 reqIdx = 0;
    uint32 addr=FclPcb.P_DATA.addr;
    uint8* data=FclPcb.P_DATA.data;
    uint32 length=FclPcb.P_DATA.len;

    if ((addr % 256) || (length % 256))
    {
        return R_FCL_ERR_PARAMETER;
    }

    reqIdx = addr;
    reqCnt = (length / 256) + ((length % 256) != 0);
    FclPcb.request.command_enu = R_FCL_CMD_WRITE;
    FclPcb.request.bufferAdd_u32 = (uint32)data;
    FclPcb.request.idx_u32 = reqIdx;
    FclPcb.request.cnt_u16 = reqCnt; /* written bytes = 256 * cnt_u16 */
    R_FCL_Execute(&FclPcb.request);
    fclRet = FclPcb.request.status_enu;
    if (R_FCL_BUSY == fclRet)
    {
        FclPcb.waitParam.currentComm = FCL_COMM_WRITE;
        FclPcb.waitParam.nextComm = FCL_COMM_IDLE;
        FclPcb.waitParam.hold = FALSE;
        FclPcb.waitParam.time = 200;
        FclPcb.CommState = FCL_COMM_WAIT;
    }
    else if (R_FCL_OK == fclRet)
    {
        FclPcb.CommState = FCL_COMM_ERASE;
    }
}

/**
 * @brief 
 * 
 * @param addr 
 * @param length 
 * @return uint8 
 */
uint8 Fcl_Erase(uint32 addr, uint32 length, fcl_erase_region_cbk erase_region_cbk, fcl_erase_comp_cbk erase_comp_cbk)
{
    uint32 i = 0;
    r_fcl_status_t rec = R_FCL_OK;
    Fcl_Block *block = &blocks[0];
    uint32 end_addr = addr + length - 1;
    for (i = 0; i < sizeof(blocks) / sizeof(Fcl_Block); i++, block++)
    {
        if (block->Start <= addr && block->End > addr)
        {
            break;
        }
    }
    for (; i < sizeof(blocks) / sizeof(Fcl_Block); i++, block++)
    {
        if (block->Start > end_addr)
        {
            break;
        }
        block->E_V = FCL_OP_READY;
    }
    FclPcb.CommState = FCL_COMM_ERASE;
    FclPcb.erase_comp_cbk = erase_comp_cbk;
    FclPcb.erase_region_cbk = erase_region_cbk;
    return 0x78;
}

/**
 * @brief 
 * 
 * @param addr 
 * @param data 
 * @param length 
 * @return r_fcl_status_t 
 */
uint8 Fcl_Write(uint32 addr, uint8 *data, uint32 length, fcl_write_comp_cbk write_comp_cbk)
{
    if (length > 0x200)
    {
        return 0x72;
    }
    FclPcb.CommState = FCL_COMM_WRITE;
    FclPcb.P_DATA.addr = addr;
    memcpy(FclPcb.P_DATA.data, data, length);
    FclPcb.P_DATA.len = length;
    FclPcb.write_comp_cbk = write_comp_cbk;
    return 0x78;
}

/**
 * @brief 
 * 
 */
uint8 Fcl_Init(fcl_err_cbk err_cbk, fcl_init_cbk init_cbk)
{
    FclPcb.CommState = FCL_COMM_INIT;
    FclPcb.err_cbk = err_cbk;
    FclPcb.init_cbk = init_cbk;
    return 0x78;
}

/**
 * @brief 
 * 
 */
void Fcl_ErrCallBack(uint32 Err)
{
    if (FclPcb.err_cbk != NULL)
    {
        FclPcb.err_cbk(Err);
    }
}

/**
 * @brief FCL MainFunction 10ms task cycle
 * 
 */
void Fcl_Test(void);
void Fcl_MainFunction(void)
{
    r_fcl_status_t ret = R_FCL_OK;

    if (FCL_COMM_IDLE != FclPcb.CommState)
    {
        Cdd_HsmCodeFlashStart();
        FCLUser_Open();
    }

    if (Cdd_HsmCodeFlashIsAllow() == TRUE)
    {
        SuspendAllInterrupts();
        switch (FclPcb.CommState)
        {
        case FCL_COMM_IDLE:
            break;
        case FCL_COMM_INIT:
            ret = _fcl_Init();
            break;
        case FCL_COMM_PREPARE:
            ret = _fcl_Prepare();
            break;
        case FCL_COMM_DIS_LOCKBITS:
            ret = _fcl_DisableLockBits();
            break;
        case FCL_COMM_ERASE:
            ret = _fcl_Erase();
            break;
        case FCL_COMM_WRITE:
            ret = _fcl_Write();
            break;
        case FCL_COMM_WAIT:
            ret = fpwait();
            break;
        default:
            break;
        }
        
        Cdd_HsmCodeFlashStop();
        ResumeAllInterrupts();
        FclPcb.commRetry = ((R_FCL_OK == ret) ? 10 : (FclPcb.commRetry - 1));
        if (FclPcb.commRetry == 0)
        {
            (void)upgrade_err("command_enu=%d, bufferAdd_u32=%4x, idx_u32=%d, cnt_u16=%d, status_enu=%d\r\n",
                        FclPcb.request.command_enu, FclPcb.request.bufferAdd_u32,
                        FclPcb.request.idx_u32, FclPcb.request.cnt_u16, FclPcb.request.status_enu);
            Fcl_ErrCallBack(ret);
        }
    }

    FCLUser_Close();
    // Fcl_Test();
}

uint8 wdata[0x200] = {0};

boolean WriteComp = FALSE;
boolean EraseComp = FALSE;
void EraseCompTest_Cbk(void)
{
    (void)upgrade_info("%s :erase complete\r\n");
    EraseComp = TRUE;
}
void EraseRegionTest_Cbk(uint32 region)
{
    (void)upgrade_info("%s :erase Region:%d\r\n", __FUNCTION__, region);
}
void WriteCompTest_Cbk(uint32 addr, uint32 len)
{
    if(addr%0x4000 == 0)
    {
        (void)upgrade_info("%s : Write:%4x Length:%d\r\n", __FUNCTION__, addr, len);
    }
    WriteComp = TRUE;
}

void Fcl_Test(void)
{
    static boolean fclIsInit = FALSE;
    static uint32 time=0;
    static uint32 testCnt = 0;
    static uint32 loopCnt = 0;
    static uint32 addr = 0x200000;
    static boolean isErase = FALSE;

    time++;

    if(time%10!=0)
    {
        return;
    }

    if (fclIsInit == FALSE)
    {
        Fcl_Init(NULL,NULL);
        fclIsInit = TRUE;
        isErase = FALSE;
    }
    else
    {
        if(EraseComp == FALSE)
        {
            if (FclPcb.CommState == FCL_COMM_IDLE)
            {
                Fcl_Erase(0x200000, 0x1b0000, EraseRegionTest_Cbk, EraseCompTest_Cbk);
            }
        }
        else
        {
            if(WriteComp ==FALSE)
            {
                if(FclPcb.CommState ==FCL_COMM_IDLE)
                {
                    Fcl_Write(addr, wdata, 0x200, WriteCompTest_Cbk);
                }
            }
            else
            {
                addr+=0x200;
                if (addr == 0x3b0000)
                {
                    addr = 0x200000;
                    FclPcb.CommState == FCL_COMM_IDLE;
                    WriteComp = FALSE;
                    EraseComp = FALSE;
                }
                else
                {
                    Fcl_Write(addr, wdata, 0x200, WriteCompTest_Cbk);
                }
                
            }
            
        }
    }
}
