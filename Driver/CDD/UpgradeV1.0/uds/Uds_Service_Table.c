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
 * @file:      Uds_Service_Table.c
 * @author:    Nobo
 * @date:      2020-12-7
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-12-7
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef UDS_SERVICE_TABLE_SOURCE
#define UDS_SERVICE_TABLE_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Uds.h"
#include "Uds_Service.h"
/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Development Error Detection                                                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
static const struct UDS_SERVICE uds_service_table[] = {
    {
        0x10,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,2,uds_DiagnosticSessionControl_10,3,
        {
            {0x01,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,2 ,5 , uds_DiagnosticSessionControl_10_defaultSession_01},
            {0x02,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,2 ,5 , uds_DiagnosticSessionControl_10_ProgrammingSession_02},
            {0x03,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,2 ,5 , uds_DiagnosticSessionControl_10_extendedDiagnosticSession_03},
        }
    },
    {
        0x11,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,3,uds_ECUReset_11,3,
        {
            {0x00,SessionDefault | SessionProgramming | SessionExtendedDiagnostic,3 ,2 , uds_ECUReset_11_SetResetVector_00},
            {0x01,SessionProgramming|SessionExtendedDiagnostic,3 ,2 , uds_ECUReset_11_hardReset_01},
            {0x03,(uint8)SessionExtendedDiagnostic,3 ,2 , uds_ECUReset_11_softReset_03},
        }
    },
    {
        0x22,SessionProgramming|SessionExtendedDiagnostic ,0xff,uds_ReadDataByIdentifier_22,0
    },
    {
        0x2E,SessionProgramming|SessionExtendedDiagnostic ,0xff,uds_WriteDataByIdentifier_2E,0
    },
    {
        0x31,(uint8)SessionProgramming,0xffff,uds_RoutineControl_31,1,
        {0x01,(uint8)SessionProgramming,0xffff ,2 , uds_RoutineControl_31_StartRoutine_01},
    },
    {
        0x34,(uint8)SessionProgramming,12,uds_RequestDownload_34,0
    },
    {
        0x36,(uint8)SessionProgramming,0xffff,uds_TransferData_36,0
    },
    {
        0x37,(uint8)SessionProgramming,1,uds_RequestTransferExit_37,0
    },
};

/*********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  function name()
 **********************************************************************************************************************/
/*! \brief      :
 * \details     :
 * \param[in]   :
 * \param[out]  :
 * \return      :
 * \pre         :
 * \context     :
 * \reentrant   :
 * \synchronous :
 * \trace       :
 * \note        :
 */


/**********************************************************************************************************************
 *  END OF FILE: Uds_Service_Table.c
 *********************************************************************************************************************/
#endif //UDS_SERVICE_TABLE_SOURCE
