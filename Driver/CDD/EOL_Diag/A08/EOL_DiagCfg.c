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
 * @file:      EOL_DiagCfg.c
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

/*
 *  %header file in this project/library%
 */
#include "EOL_DiagCfg.h"

/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */


/*
 *  %forward declaration%
 */



/*
 *  %global definition%
 */


/*
 *  %function definition%
 */
/******************************************************************************/
/**
* @brief               <EOL_DiagDIDRead_0x22_0xF189>
* 
* <Read DID 0xF189> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
Std_ReturnType EOL_DiagTransferDIDRead_0x22_0xF189(Dcm_OpStatusType OpStatus, uint8 * pu8ValueP)
{
    if(SPI_DIAG_IDEL == EOL_DiagTransferStatusGet())
    {
        EOL_DiagTransferDidRead_Transmit_0x22(0xF189);
    }

    if(SPI_DIAG_DIDREAD_RESPONSE_OK == EOL_DiagTransferStatusGet())
    {
        EOL_DiagTransferDidRead_Receive_0x22(pu8ValueP);
        EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
        OpStatus = E_OK;
    }
    else if(SPI_DIAG_ERR == EOL_DiagTransferStatusGet())
    {
        OpStatus = E_NOT_OK;
    }
    else
    {
        OpStatus = E_PENDING;
    }

    return OpStatus;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagDIDWrite_0x2E_0x02CC>
* 
* <Write DID 0x02CC> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
Std_ReturnType EOL_DiagTransferDIDWrite_0x2E_0x02CC( const uint8 Data[],
    Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode )
{
    /*Predefined in advance by Dcm*/
    uint16 u16DataLenL = cByte46;
    if(SPI_DIAG_IDEL == EOL_DiagTransferStatusGet())
    {
        EOL_DiagTransferDidWrite_Transmit_0x2E(0x02CC, Data, u16DataLenL);
    }

    if(SPI_DIAG_DIDWRITE_RESPONSE_OK == EOL_DiagTransferStatusGet())
    {
        OpStatus = E_OK;
        EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
    }
    else if(SPI_DIAG_ERR == EOL_DiagTransferStatusGet())
    {
        OpStatus = E_NOT_OK;
    }
    else
    {
        OpStatus = E_PENDING;
    }
    return OpStatus;
}

/******************************************************************************/
/**
* @brief               <EOL_DiagDIDWrite_0x2E_0x02CC>
* 
* <Write DID 0x02CC> .
* Service ID   :       <NONE>
* Sync/Async   :       <Synchronous>
* Reentrancy           <Reentrant>
* @param[in]           <NONE>
* @param[out]          <NONE>
* @param[in/out]       <NONE>
* @return              <NONE>    
*/
/******************************************************************************/
Std_ReturnType EOL_DiagTransferSessionControl_0x10_0x03( Dcm_OpStatusType OpStatus,
Dcm_NegativeResponseCodeType* ErrorCode )
{
    if(SPI_DIAG_IDEL == EOL_DiagTransferStatusGet())
    {
        EOL_DiagTransferSessionControl_Transmit_0x10(0x03);
    }

    if(SPI_DIAG_SESSION_RESPONSE_OK == EOL_DiagTransferStatusGet())
    {
        OpStatus = E_OK;
        EOL_DiagTransferStatusSet(SPI_DIAG_IDEL);
    }
    else if(SPI_DIAG_ERR == EOL_DiagTransferStatusGet())
    {
        OpStatus = E_NOT_OK;
    }
    else
    {
        OpStatus = E_PENDING;
    }
    return OpStatus;
}


