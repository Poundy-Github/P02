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
 * @file:      Fcl_api.h
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

#ifndef FCL_API_INCLUDE
#define FCL_API_INCLUDE

/**
 * @brief 
 * 
 */
typedef void (*fcl_init_cbk)(void);
typedef void (*fcl_err_cbk)(uint8 err);
typedef void (*fcl_erase_region_cbk)(uint32 region);
typedef void (*fcl_erase_comp_cbk)(void);
typedef void (*fcl_write_comp_cbk)(uint32 addr, uint32 len);

/**
 * @brief 
 * 
 */
typedef enum{
    FCL_OP_IDLE,
    FCL_OP_READY,
    FCL_OP_BUSY,
    FCL_OP_SUSPENDED,
    FCL_OP_ERROR,
    FCL_OP_COMPLETE
}FclOpState;

/**
 * @brief 
 * 
 */
typedef enum{
    FCL_COMM_IDLE,
    FCL_COMM_INIT,
    FCL_COMM_PREPARE,
    FCL_COMM_DIS_LOCKBITS,
    FCL_COMM_ERASE,
    FCL_COMM_WRITE,
    FCL_COMM_WAIT
}FclCommState;


/**
 * @brief 
 * 
 */
typedef struct 
{
    uint32 Region;
    uint32 Start;
    uint32 End;
    uint8 E_ErrCnt;
    FclOpState E_V;
    uint8 P_ErrCnt;
    FclOpState P_V;
}Fcl_Block;


void Fcl_MainFunction(void);

uint8 Fcl_Init(fcl_err_cbk err_cbk, fcl_init_cbk init_cbk);
uint8 Fcl_Erase(uint32 addr, uint32 length, fcl_erase_region_cbk erase_region_cbk, fcl_erase_comp_cbk erase_comp_cbk);
uint8 Fcl_Write(uint32 addr, uint8 *data, uint32 length, fcl_write_comp_cbk write_comp_cbk);

#endif