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
 * @file:      GNSS_Com.h
 * @author:    Nobo
 * @date:      2021-3-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-3-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _GNSS_COM_H_
#define _GNSS_COM_H_




void GNSS_Com_Init(void);
uint16 GNSS_Com_ReadData(uint8 * buffer,uint16 size);
void GNSS_Com_Monitoring(void);

#endif /* ifndef _GNSS_COM_H_.2021-3-6 11:11:07 GW00188879 */
