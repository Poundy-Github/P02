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
 * @file:      RingBuffer.h
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
 *  %head of header file guard%
 */
#ifndef _RB_H_
#define _RB_H_


/*
 *  %header file in this project/library%
 */
#include "Cdd_Common.h"
#include "RingBuffer_Cfg.h"


/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
/* ring buffer return type */
typedef sint32 RB_Return_t;
/* operation success */
#define RB_SUCCESS          (0)
/* this flag is initialized error and should not be returned
   if this flag returned, there should be software design error */
#define RB_ERROR            (-1)
/* parameter error */
#define RB_E_PARAM          (-2)
/* config error */
#define RB_E_CONFIG         (-3)
/* init state error */
#define RB_E_INIT           (-4)
/* ring buffer is full */
#define RB_E_FULL           (-5)
/* ring buffer is empty */
#define RB_E_EMPTY          (-6)
/* ring buffer restore fail */
#define RB_E_RESTORE        (-7)


/* data of ring buffer */
typedef struct RB_Data
{
    boolean isInit;                     /* if ring buffer is initialized */
    uint32 headIndex;                   /* head location of buffer */
    uint32 tailIndex;                   /* tail location of buffer */
} RB_Data_t;

/* storage for backup information */
typedef struct RB_BackupStorage
{
    uint32 headIndex;                   /* head location of buffer */
    uint32 tailIndex;                   /* tail location of buffer */
    uint16 crc;                         /* crc for data consistency */
} RB_BackupStorage_t;

/* config of ring buffer */
typedef struct RB_Cfg
{
    uint8 *buffer;                      /* buffer location to store element in queue */
    uint8 *bufferOverflow;              /* buffer location overflow */
    RB_BackupStorage_t *backup;         /* storage for backup information */
    uint32 elementLength;               /* element length in byte */
    uint32 elementNumber;               /* how many element can have in ring buffer */
    boolean popMethod;                  /* when pop operation, as many as possible is popped */
    boolean pushMethod;                 /* when push operation, as many as possible is pushed */
    boolean supportRestore;             /* restore function support flag */
} RB_Cfg_t;

#pragma ghs section bss = ".IPC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".IPC_SHARE_INIT_DATA" 
extern struct RB_Data rb_datas[RB_ID_NUMBER];
#pragma ghs section bss=default
#pragma ghs section data=default

extern const struct RB_Cfg rb_cfgs[RB_ID_NUMBER];

/*
 *  %function declaration%
 */
RB_Return_t RB_Init(RB_Id_t id);
RB_Return_t RB_Push(RB_Id_t id, uint8 *data, uint32 elementNumber);
RB_Return_t RB_Peek(RB_Id_t id, uint8 *data, uint32 elementNumber);
RB_Return_t RB_Pop(RB_Id_t id, uint8 *data, uint32 elementNumber);
RB_Return_t RB_NumberGet(RB_Id_t id);
RB_Return_t RB_Save(RB_Id_t id);
RB_Return_t RB_Restore(RB_Id_t id);
RB_Return_t RB_Clear(RB_Id_t id);


/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif
