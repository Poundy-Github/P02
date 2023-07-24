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
 * @file:      SecOc_Server.h
 * @author:    Nobo
 * @date:      2021-4-8
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-4-8
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/ 

#if !defined (SECOC_SERVER_H)
# define SECOC_SERVER_H

#include "Fvm.h"

extern void CanServer_SecOCBusOffEndStatusSet(boolean busoffEndFlag);
extern boolean CanServer_SecOCBusOffEndStatusGet(void);

extern void CANNM_State_Change_Callback(uint8 nmNetworkHandle,uint8 PreState,uint8 CurState);
 


FUNC(void, COM_APPL_CODE) SECOC_PDU_Message_ReqSet(boolean flag);



/*! Bus Sleep State */
# define NM_STATE_BUS_SLEEP                            (0x01u)
/*! Prepare Bus Sleep State */
# define NM_STATE_PREPARE_BUS_SLEEP                    (0x02u)
/*! Ready Sleep State */
# define NM_STATE_READY_SLEEP                          (0x03u)
/*! Normal Operation State */
# define NM_STATE_NORMAL_OPERATION                     (0x04u)
/*! Repeat Message State */
# define NM_STATE_REPEAT_MESSAGE                       (0x05u)

#endif
