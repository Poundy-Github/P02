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
 * @file:      Uds_Service.h
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

#ifndef UDS_SERVICE_INCLUDE
#define UDS_SERVICE_INCLUDE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/

/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Uds.h"
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
extern void Uds_Init(void);
extern EStatus uds_DiagnosticSessionControl_10_defaultSession_01(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_DiagnosticSessionControl_10_ProgrammingSession_02(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_DiagnosticSessionControl_10_extendedDiagnosticSession_03(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_ECUReset_11_SetResetVector_00(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_ECUReset_11_hardReset_01(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_ECUReset_11_softReset_03(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);
extern EStatus uds_ECUReset_11_GetReset_04(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc);
extern EStatus uds_RoutineControl_31_StartRoutine_01(UDS_PDU* uds_pdu, const struct UDS_SUBFUNC* uds_subfunc);



extern EStatus uds_DiagnosticSessionControl_10(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_ECUReset_11(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_ReadDataByIdentifier_22(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_WriteDataByIdentifier_2E(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service);
extern EStatus uds_RoutineControl_31(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_RequestDownload_34(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_TransferData_36(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
extern EStatus uds_RequestTransferExit_37(UDS_PDU* uds_pdu, const struct UDS_SERVICE* uds_service);
/**********************************************************************************************************************
 *  END OF FILE: Uds_Service.h
 *********************************************************************************************************************/
#endif //UDS_SERVICE_INCLUDE
