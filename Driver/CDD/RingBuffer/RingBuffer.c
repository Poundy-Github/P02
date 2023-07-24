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
 * @file:      RingBuffer.c
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
#include "RingBuffer.h"
#include "Std_Types.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */
#include <string.h>

/*
 *  %typedef/macro defintion%
 */


/*
 *  %forward declaration%
 */
static uint32 RB_PushInternal(RB_Id_t id, uint8 *data, uint32 elementNumber);
static uint32 RB_PeekInternal(RB_Id_t id, uint8 *data, uint32 elementNumber);
static uint32 RB_PopInternal(RB_Id_t id, uint8 *data, uint32 elementNumber);
static uint16 RB_Crc16(uint8 *data, uint32 length);


/*
 *  %global definition%
 */


/*
 *  %function definition%
 */
/*
* @brief   :   Initial ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @retval  :   SUCCESS: init success
* @retval  :   RB_E_PARAM: id error
* @retval  :   RB_E_CONFIG: buffer length is not equal to (element length * element number)
* @retval  :   RB_E_INIT: ring buffer is not in uninit state
*/
RB_Return_t RB_Init(RB_Id_t id)
{
    RB_Return_t ret = RB_ERROR;
    uint32 bufferLength;
    uint32 bufferLengthCal;

#if(RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE != rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else if((NULL_PTR == rb_cfgs[id].backup) && (TRUE == rb_cfgs[id].supportRestore))
    {
        ret = RB_E_CONFIG;
    }
#endif
    {
#if(RB_DEV_ERROR_DETECT == STD_ON)
        bufferLength = (uint32)(rb_cfgs[id].bufferOverflow) - (uint32)(rb_cfgs[id].buffer);
        bufferLengthCal = (uint32)(rb_cfgs[id].elementLength) * (uint32)(rb_cfgs[id].elementNumber);
        if((bufferLength != bufferLengthCal) || (0u == rb_cfgs[id].elementLength))
        {
            ret = RB_E_CONFIG;
        }
        else
#endif
        {
            rb_datas[id].headIndex = 0u;
            rb_datas[id].tailIndex = 0u;
            rb_datas[id].isInit = TRUE;
            ret = RB_SUCCESS;
        }
    }
    return ret;
}


/*
* @brief   :   push element number elements into ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to data pushed into ring buffer
* @param   :   elementNumber: number of element
* @retval  :   positive: push success
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer, elementNumber is 0
* @retval  :   RB_E_FULL: ring buffer is not enough
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_Push(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    RB_Return_t ret = RB_ERROR;    
    uint32 len;

#if(RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if((data == NULL_PTR) || (0u == elementNumber))
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else 
#endif
    {
        len = RB_PushInternal(id, data, elementNumber);
        if(0u == len)
        {
            ret = RB_E_FULL;
        }
        else
        {
            ret = (RB_Return_t)len;
        }
    }
    return ret;
}


/*
* @brief   :   peek element number elements from ring buffer but not pop
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to restore the peeked data
* @param   :   elementNumber: element number of data
* @retval  :   positive: actual element data in ring buffer
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer, elementNumber is 0
* @retval  :   RB_E_EMPTY: ring buffer is empty
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_Peek(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    int32_t ret = RB_ERROR;
    uint32 len;

#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if((data == NULL_PTR) || (0u == elementNumber))
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else
#endif
    {
        len = RB_PeekInternal(id, data, elementNumber);
        if(0u == len)
        {
            ret = RB_E_EMPTY;
        }
        else
        {
            ret = (RB_Return_t)len;
        }
    }
    return ret;
}


/*
* @brief   :   pop element number elements from ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to restore the popped data
* @param   :   elementNumber: element number of data
* @retval  :   positive: actual element data in ring buffer
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer, elementNumber is 0
* @retval  :   RB_E_EMPTY: ring buffer is empty
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_Pop(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    int32_t ret = RB_ERROR;
    uint32 len;

#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if((data == NULL_PTR) || (0u == elementNumber))
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else
#endif
    {
        len = RB_PopInternal(id, data, elementNumber);
        if(0u == len)
        {
            ret = RB_E_EMPTY;
        }
        else
        {
            ret = (RB_Return_t)len;
        }
    }
    return ret;
}


/*
* @brief   :   get elememt number inside ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @retval  :   positive: element number in ring buffer
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer
* @retval  :   RB_E_EMPTY: ring buffer is empty
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_NumberGet(RB_Id_t id)
{
    RB_Return_t ret = RB_ERROR;
    uint32 elementUsed;

#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else
#endif
    {
        if(rb_datas[id].headIndex >= rb_datas[id].tailIndex)
        {
            elementUsed = rb_datas[id].headIndex - rb_datas[id].tailIndex;
        }
        else
        {
            elementUsed = rb_datas[id].headIndex + (rb_cfgs[id].elementNumber << 1) - rb_datas[id].tailIndex;
        }
	ret = (RB_Return_t)elementUsed;
    }
    return ret;
}


/*
* @brief   :   save current ring buffer status, later it can be restored
* @param   :   id: ring buffer id to represent a ring buffer
* @retval  :   SUCCESS: save ring buffer successfully
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer
* @retval  :   RB_E_CONFIG: config is wrong
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_Save(RB_Id_t id)
{
    RB_Return_t ret = RB_ERROR;

#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else if(FALSE == rb_cfgs[id].supportRestore)
    {
        ret = RB_E_CONFIG;
    }
    else
#endif
    {
        if(rb_cfgs[id].backup != NULL_PTR)
        {
            rb_cfgs[id].backup->headIndex = rb_datas[id].headIndex;
            rb_cfgs[id].backup->tailIndex = rb_datas[id].tailIndex;
            rb_cfgs[id].backup->crc = RB_Crc16(rb_cfgs[id].buffer, rb_cfgs[id].elementLength * rb_cfgs[id].elementNumber);
            ret = RB_SUCCESS;
        }
    }
    return ret;
}


/*
* @brief   :   restore current ring buffer status which is previous saved
* @param   :   id: ring buffer id to represent a ring buffer
* @retval  :   SUCCESS: restore ring buffer successfully
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer
* @retval  :   RB_E_CONFIG: config is wrong
* @retval  :   RB_E_INIT: ring buffer is in init state
* @retval  :   RB_E_INIT: ring buffer is in init state
*/
RB_Return_t RB_Restore(RB_Id_t id)
{
    RB_Return_t ret = RB_ERROR;

#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if(TRUE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else if(FALSE == rb_cfgs[id].supportRestore)
    {
        ret = RB_E_CONFIG;
    }
    else
#endif
    {
        if(rb_cfgs[id].backup != NULL_PTR)
        {
            if(RB_Crc16(rb_cfgs[id].buffer, rb_cfgs[id].elementLength * rb_cfgs[id].elementNumber) != rb_cfgs[id].backup->crc)
            {
                ret = RB_E_RESTORE;
                RB_Init(id);
            }
            else
            {
                /* Restore if comfiguration structure properties is correct ,else not. */
                if((rb_cfgs[id].backup->headIndex < (rb_cfgs[id].elementNumber << 1)) && \
                    (rb_cfgs[id].backup->headIndex >= rb_cfgs[id].backup->tailIndex)  && \
                    ((rb_cfgs[id].backup->headIndex - rb_cfgs[id].backup->tailIndex) <= rb_cfgs[id].elementNumber))
                {
                    rb_datas[id].headIndex = rb_cfgs[id].backup->headIndex;
                    rb_datas[id].tailIndex = rb_cfgs[id].backup->tailIndex;
                    rb_datas[id].isInit = TRUE;
                    ret = RB_SUCCESS;
                }
                else
                {
                    rb_cfgs[id].backup->headIndex = 0;
                    rb_cfgs[id].backup->tailIndex = 0;
                    RB_Init(id);
                }
					
            }
        }

    }
    return ret;
}


/*
* @brief   :   push element number elements into ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to data pushed into ring buffer
* @param   :   elementNumber: element number of data
* @retval  :   void no return value
*/
static uint32 RB_PushInternal(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    uint32 elementUsed;
    uint32 elementUnused;
    uint8 *headPosition;
    uint32 elementOperate;
    uint32 bytesWrite;
    uint32 bytesHeadToBottom;
    uint32 nextHead;
	
    if(rb_datas[id].headIndex >= rb_datas[id].tailIndex)
    {
        elementUsed = rb_datas[id].headIndex - rb_datas[id].tailIndex;
    }
    else
    {
        elementUsed = rb_datas[id].headIndex + (rb_cfgs[id].elementNumber << 1) - rb_datas[id].tailIndex;
    }
	/* element space unused */
    elementUnused = rb_cfgs[id].elementNumber - elementUsed;

	/* get write buffer address depend on head index */
    if(rb_datas[id].headIndex >= rb_cfgs[id].elementNumber)
    {
    	/* element full */
        headPosition = rb_cfgs[id].buffer + (rb_datas[id].headIndex - rb_cfgs[id].elementNumber) * rb_cfgs[id].elementLength;
    }
    else
    {
    	/* element not full */
        headPosition = rb_cfgs[id].buffer + rb_datas[id].headIndex * rb_cfgs[id].elementLength;
    }

	/* guarantee elementOperate < elementUnused */
    if(elementUnused >= elementNumber)
    {
    	/* element not full */
        elementOperate = elementNumber;
    }
    else
    {
    	/* element full */
        if(TRUE == rb_cfgs[id].pushMethod)
        {
        	/* continue operate */
            elementOperate = elementUnused;
        }
        else
        {
        	/* quit */
            elementOperate = 0u;
        }
    }

    if(elementOperate > 0u)
    {
        /* operate accordding to element number */
        bytesWrite = elementOperate * rb_cfgs[id].elementLength;
        /* buffer space unused  */
        bytesHeadToBottom = ((uint32)rb_cfgs[id].bufferOverflow - (uint32)headPosition);

        if(bytesHeadToBottom <= bytesWrite)
        {
            /* operate unused bytes */
            memcpy(headPosition, data, bytesHeadToBottom);

            /* operate remainder bytes */
            memcpy(rb_cfgs[id].buffer, data + bytesHeadToBottom, bytesWrite - bytesHeadToBottom);         
        }
        else
        {
            memcpy(headPosition, data, bytesWrite);
        }

        nextHead = rb_datas[id].headIndex + elementOperate;
        if(nextHead >= (rb_cfgs[id].elementNumber << 1))
        {
            rb_datas[id].headIndex = nextHead - (rb_cfgs[id].elementNumber << 1);
        }
        else
        {
            rb_datas[id].headIndex = nextHead;
        }
    }
    return elementOperate;
}


/*
* @brief   :   peek an element from ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to restore the peeked data
* @param   :   elementNumber: element number of data
* @retval  :   number of element peeked
*/
static uint32 RB_PeekInternal(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    uint32 elementUsed;
    uint8 *tailPosition;
    uint32 bytesTailToBottom;
    uint32 bytesRead;
    uint32 elementOperate;

    if(rb_datas[id].headIndex >= rb_datas[id].tailIndex)
    {
        elementUsed = rb_datas[id].headIndex - rb_datas[id].tailIndex;
    }
    else
    {
        elementUsed = rb_datas[id].headIndex + (rb_cfgs[id].elementNumber << 1) - rb_datas[id].tailIndex;
    }

    if(rb_datas[id].tailIndex >= rb_cfgs[id].elementNumber)
    {
        tailPosition = rb_cfgs[id].buffer + (rb_datas[id].tailIndex - rb_cfgs[id].elementNumber) * rb_cfgs[id].elementLength;
    }
    else
    {
        tailPosition = rb_cfgs[id].buffer + rb_datas[id].tailIndex * rb_cfgs[id].elementLength;
    }
    bytesTailToBottom = ((uint32)rb_cfgs[id].bufferOverflow - (uint32)tailPosition);
    
    if(elementNumber <= elementUsed)
    {
        elementOperate = elementNumber;
    }
    else
    {
        elementOperate = elementUsed;
    }

    if(elementOperate > 0u)
    {
        bytesRead = elementOperate * rb_cfgs[id].elementLength;
        if(bytesTailToBottom <= bytesRead)
        {
            memcpy(data, tailPosition, bytesTailToBottom);
            memcpy(data + bytesTailToBottom, rb_cfgs[id].buffer, bytesRead - bytesTailToBottom);
        }
        else
        {
            memcpy(data, tailPosition, bytesRead);
        }
    }
    return elementOperate;
}


/*
* @brief   :   pop an element from ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @param   :   data: pointer to restore the popped data
* @param   :   elementNumber: element number of data
* @retval  :   void no return value
*/
static uint32 RB_PopInternal(RB_Id_t id, uint8 *data, uint32 elementNumber)
{
    uint32 elementUsed = (uint32)((sint32)rb_datas[id].headIndex - (sint32)rb_datas[id].tailIndex);
    uint8 *tailPosition;
    uint32 bytesTailToBottom;
    uint32 bytesRead;
    uint32 elementOperate;
    uint32 nextTail;

    /* Get element unused */
    if(rb_datas[id].headIndex >= rb_datas[id].tailIndex)
    {
        elementUsed = rb_datas[id].headIndex - rb_datas[id].tailIndex;
    }
    else
    {
        elementUsed = rb_datas[id].headIndex + (rb_cfgs[id].elementNumber << 1) - rb_datas[id].tailIndex;
    }

    /* tailPosition always point to buffer */
    if(rb_datas[id].tailIndex >= rb_cfgs[id].elementNumber)
    {
        tailPosition = rb_cfgs[id].buffer + (rb_datas[id].tailIndex - rb_cfgs[id].elementNumber) * rb_cfgs[id].elementLength;
    }
    else
    {
        tailPosition = rb_cfgs[id].buffer + rb_datas[id].tailIndex * rb_cfgs[id].elementLength;
    }
    bytesTailToBottom = ((uint32)rb_cfgs[id].bufferOverflow - (uint32)tailPosition);

    /* guarantee pop size <= usedElement size,valid data */
    if(elementUsed >= elementNumber)
    {
        elementOperate = elementNumber;
    }
    else
    {
        if(TRUE == rb_cfgs[id].popMethod)
        {
            elementOperate = elementUsed;
        }
        else
        {
            elementOperate = 0u;
        }
    }

    if(elementOperate > 0u)
    {
        bytesRead = elementOperate * rb_cfgs[id].elementLength;
        if(bytesTailToBottom <= bytesRead)
        {
            memcpy(data, tailPosition, bytesTailToBottom);
            memcpy(data + bytesTailToBottom, rb_cfgs[id].buffer, bytesRead - bytesTailToBottom);
        }
        else
        {
            memcpy(data, tailPosition, bytesRead);
        }
        
        nextTail = rb_datas[id].tailIndex + elementOperate;
        if(nextTail >= (rb_cfgs[id].elementNumber << 1))
        {
            rb_datas[id].tailIndex = nextTail - (rb_cfgs[id].elementNumber << 1);
        }
        else
        {
            rb_datas[id].tailIndex = nextTail;
        }
    }
    return elementOperate;
}


/*
* @brief   :   clear elements in ring buffer
* @param   :   id: ring buffer id to represent a ring buffer
* @retval  :   RB_E_PARAM: id error, data with NULL_PTR pointer
* @retval  :   RB_E_INIT: ring buffer is in uninit state
*/
RB_Return_t RB_Clear(RB_Id_t id)
{
    RB_Return_t ret = RB_E_PARAM;
    
#if (RB_DEV_ERROR_DETECT == STD_ON)
    if(id >= RB_ID_NUMBER)
    {
        ret = RB_E_PARAM;
    }
    else if(FALSE == rb_datas[id].isInit)
    {
        ret = RB_E_INIT;
    }
    else
#endif
    {
        rb_datas[id].headIndex = 0u;
        rb_datas[id].tailIndex = 0u;
        ret = RB_SUCCESS;
    }
    return ret;
}

static uint16 crcTable16[256] =
{
    0x0000u, 0x1021u, 0x2042u, 0x3063u, 0x4084u, 0x50a5u, 0x60c6u, 0x70e7u,
    0x8108u, 0x9129u, 0xa14au, 0xb16bu, 0xc18cu, 0xd1adu, 0xe1ceu, 0xf1efu,
    0x1231u, 0x0210u, 0x3273u, 0x2252u, 0x52b5u, 0x4294u, 0x72f7u, 0x62d6u,
    0x9339u, 0x8318u, 0xb37bu, 0xa35au, 0xd3bdu, 0xc39cu, 0xf3ffu, 0xe3deu,
    0x2462u, 0x3443u, 0x0420u, 0x1401u, 0x64e6u, 0x74c7u, 0x44a4u, 0x5485u,
    0xa56au, 0xb54bu, 0x8528u, 0x9509u, 0xe5eeu, 0xf5cfu, 0xc5acu, 0xd58du,
    0x3653u, 0x2672u, 0x1611u, 0x0630u, 0x76d7u, 0x66f6u, 0x5695u, 0x46b4u,
    0xb75bu, 0xa77au, 0x9719u, 0x8738u, 0xf7dfu, 0xe7feu, 0xd79du, 0xc7bcu,
    0x48c4u, 0x58e5u, 0x6886u, 0x78a7u, 0x0840u, 0x1861u, 0x2802u, 0x3823u,
    0xc9ccu, 0xd9edu, 0xe98eu, 0xf9afu, 0x8948u, 0x9969u, 0xa90au, 0xb92bu,
    0x5af5u, 0x4ad4u, 0x7ab7u, 0x6a96u, 0x1a71u, 0x0a50u, 0x3a33u, 0x2a12u,
    0xdbfdu, 0xcbdcu, 0xfbbfu, 0xeb9eu, 0x9b79u, 0x8b58u, 0xbb3bu, 0xab1au,
    0x6ca6u, 0x7c87u, 0x4ce4u, 0x5cc5u, 0x2c22u, 0x3c03u, 0x0c60u, 0x1c41u,
    0xedaeu, 0xfd8fu, 0xcdecu, 0xddcdu, 0xad2au, 0xbd0bu, 0x8d68u, 0x9d49u,
    0x7e97u, 0x6eb6u, 0x5ed5u, 0x4ef4u, 0x3e13u, 0x2e32u, 0x1e51u, 0x0e70u,
    0xff9fu, 0xefbeu, 0xdfddu, 0xcffcu, 0xbf1bu, 0xaf3au, 0x9f59u, 0x8f78u,
    0x9188u, 0x81a9u, 0xb1cau, 0xa1ebu, 0xd10cu, 0xc12du, 0xf14eu, 0xe16fu,
    0x1080u, 0x00a1u, 0x30c2u, 0x20e3u, 0x5004u, 0x4025u, 0x7046u, 0x6067u,
    0x83b9u, 0x9398u, 0xa3fbu, 0xb3dau, 0xc33du, 0xd31cu, 0xe37fu, 0xf35eu,
    0x02b1u, 0x1290u, 0x22f3u, 0x32d2u, 0x4235u, 0x5214u, 0x6277u, 0x7256u,
    0xb5eau, 0xa5cbu, 0x95a8u, 0x8589u, 0xf56eu, 0xe54fu, 0xd52cu, 0xc50du,
    0x34e2u, 0x24c3u, 0x14a0u, 0x0481u, 0x7466u, 0x6447u, 0x5424u, 0x4405u,
    0xa7dbu, 0xb7fau, 0x8799u, 0x97b8u, 0xe75fu, 0xf77eu, 0xc71du, 0xd73cu,
    0x26d3u, 0x36f2u, 0x0691u, 0x16b0u, 0x6657u, 0x7676u, 0x4615u, 0x5634u,
    0xd94cu, 0xc96du, 0xf90eu, 0xe92fu, 0x99c8u, 0x89e9u, 0xb98au, 0xa9abu,
    0x5844u, 0x4865u, 0x7806u, 0x6827u, 0x18c0u, 0x08e1u, 0x3882u, 0x28a3u,
    0xcb7du, 0xdb5cu, 0xeb3fu, 0xfb1eu, 0x8bf9u, 0x9bd8u, 0xabbbu, 0xbb9au,
    0x4a75u, 0x5a54u, 0x6a37u, 0x7a16u, 0x0af1u, 0x1ad0u, 0x2ab3u, 0x3a92u,
    0xfd2eu, 0xed0fu, 0xdd6cu, 0xcd4du, 0xbdaau, 0xad8bu, 0x9de8u, 0x8dc9u,
    0x7c26u, 0x6c07u, 0x5c64u, 0x4c45u, 0x3ca2u, 0x2c83u, 0x1ce0u, 0x0cc1u,
    0xef1fu, 0xff3eu, 0xcf5du, 0xdf7cu, 0xaf9bu, 0xbfbau, 0x8fd9u, 0x9ff8u,
    0x6e17u, 0x7e36u, 0x4e55u, 0x5e74u, 0x2e93u, 0x3eb2u, 0x0ed1u, 0x1ef0u
};


static uint16 RB_Crc16(uint8 *data, uint32 length)
{
    uint8 tableIndex;
    uint16 crcValue = 0xFFFFu;
    uint32 crcDataPtr;

    for (crcDataPtr = 0; crcDataPtr < length; crcDataPtr++)
    {
        tableIndex = ((uint8) (crcValue >> 8u)) ^ data[crcDataPtr];
        crcValue = (crcValue << 8u) ^ crcTable16[tableIndex];
    }
    return crcValue;
}


