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
 * @file:      Uds_Service.c
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

#ifndef UDS_SERVICE_SOURCE
#define UDS_SERVICE_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Crc.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/
#include "Uds_Service.h"
#include "Fcl/Fcl_Api.h"
#include "r_fcl_types.h"
#include "Rte_Upgrade.h"
#include "Cdd_Hsm.h"
#include "Version.h"
#include "logger.h"
#include "Ext_Power.h"
#include "Nvm_Cfg.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
static void Uds_FclInit_Cbk(void);
static void uds_EraseComp_Cbk(void);
static void uds_EraseRegionTest_Cbk(uint32 region);
static void uds_FclWriteComp_Cbk(uint32 addr, uint32 len);
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
typedef struct
{
    uint32 targetAddr;
    uint32 targetSize;
    uint32 currentAddr;
    uint32 currentSize;

    uint8 pageCnt;

    uint32 crc;
} UDS_DOWNLOAD;

static UDS_DOWNLOAD uds_download = {
    0, 0, 0, 0, 1};
static uint8 isEraseComp = 0;
static uint8 isInitComp = 0;
static uint8 writeComp = 0;
static uint32 FotaState;

/*********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32 __ghs_romstart;
extern uint32 __ghs_romend;

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(BswM_BswMRteShutdownReqMode data);
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static uint8 uds_GetActiveAppSection(uint32 *outAppStartAddr, uint32 *outAppLength)
{
    uint32 funAddr = (uint32)uds_GetActiveAppSection;
    uint8 section = 0;
    if (funAddr > 0x200000)
    { //! App Section 2
        *outAppStartAddr = 0x200000;
        section = 2;
    }
    else
    { //! App Section 1
        *outAppStartAddr = 0x20000;
        section = 1;
    }
    *outAppLength = 0x1b0000;
    return section;
}
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
EStatus uds_DiagnosticSessionControl_10_defaultSession_01(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uds_pcb.session = SessionDefault;
    (void)upgrade_info("%s \r\n", __FUNCTION__);
    return Success;
}

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
static void Uds_FclInit_Cbk(void)
{
    isInitComp = 2;
}
EStatus uds_DiagnosticSessionControl_10_ProgrammingSession_02(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{

    if (isInitComp == 0)
    {
        // MISRA C-2012 Rule 2.2
        // uint8 isEraseComp = 0;
        // uint8 writeComp = 0;
        isInitComp = 1;
        uds_pcb.err = (Uds_Err)Fcl_Init(Uds_FclErrCbk, Uds_FclInit_Cbk);
        (void)upgrade_info("%s \r\n", __FUNCTION__);
    }
    else if (isInitComp == 1)
    {
        uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    }
    else if (isInitComp == 2)
    {
        isInitComp = 0;
        uds_pcb.session = SessionProgramming;
        uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
    }
    return Success;
}

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
EStatus uds_DiagnosticSessionControl_10_extendedDiagnosticSession_03(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uds_pcb.session = SessionExtendedDiagnostic;
    (void)upgrade_info("%s \r\n", __FUNCTION__);
    return Success;
}

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
EStatus uds_DiagnosticSessionControl_10(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    return Success;
}

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
EStatus uds_ECUReset_11_SetResetVector_00(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    static uint8 loop = 0;
    static uint32 retry = 5000;
    uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
    uds_pcb.txLen = 0;
    if (loop == 1)
    {
        retry--;
        if(retry==0)
        {
            loop = 1;
            retry = 5000;
            uds_pcb.err = UDS_E_72_GENERALPROGRAMMINGFAILURE;
        }
        else
        {
            if (Cdd_HsmSetValidIsBusy() == FALSE)
            {
                loop = 0;
                uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
                (void)upgrade_info("%s Switch App Block to %d  OK\r\n", __FUNCTION__, uds_pdu->data[1]);
            }
            else
            {
                uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
            }
        }
    }
    else
    {
        (void)upgrade_info("%s Switch App Block to %d \r\n", __FUNCTION__, uds_pdu->data[1]);
        Cdd_HsmSecureBoot_SetAppAction(uds_pdu->data[1] - 1);
        uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
        loop = 1;
        retry = 5000;
    }

    return Success;
}

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
EStatus uds_ECUReset_11_hardReset_01(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uds_pcb.txLen = 0;
    (void)upgrade_info("%s \r\n", __FUNCTION__);	
	cold_reset_req = UPGRADE_COLD_RESET;
	init_process_finish = INIT_PROCESS_NOT_FINISHED;		
    (void)Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(3);
    return Success;
}

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
EStatus uds_ECUReset_11_softReset_03(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uds_pcb.txLen = 0;	
	cold_reset_req = UPGRADE_WARM_RESET;
    (void)Rte_Write_Power_Request_PowerModeShutdownReq_requestedMode(3);
    (void)upgrade_info("%s \r\n", __FUNCTION__);
    return Success;
}

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
EStatus uds_ECUReset_11_GetReset_04(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uds_pcb.txLen = 1;
    (void)upgrade_info("%s \r\n", __FUNCTION__);
    uds_pcb.txData[0] = 0x01;
    return Success;
}

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
static void uds_EraseComp_Cbk(void)
{
    (void)upgrade_info("%s :erase complete\r\n");
    isEraseComp = 2;
}

static void uds_EraseRegionTest_Cbk(uint32 region)
{
    (void)upgrade_info("%s :erase Region:%d\r\n", __FUNCTION__, region);
}
EStatus uds_RoutineControl_31_StartRoutine_01(UDS_PDU *uds_pdu, const struct UDS_SUBFUNC *uds_subfunc)
{
    uint16 routineIdentifier = ((((uint16)uds_pdu->data[1]) << 8) | ((uint16)uds_pdu->data[2]));
    uint32 addr = 0;
    uint32 len = 0;
    uint32 crc = 0xffffffff;
    uint32 target_crc = 0xffffffff;
    uint32 SectionAddr = 0;
    uint32 SectionLen = 0;
    uint8 crntAppId = 1;

    switch (routineIdentifier)
    {
    case 0x0302:
        if (isEraseComp == 0)
        {
            addr = ((uint32)uds_pdu->data[3] << 24) |
                   ((uint32)uds_pdu->data[4] << 16) |
                   ((uint32)uds_pdu->data[5] << 8) |
                   ((uint32)uds_pdu->data[6] << 0);

            len = ((uint32)uds_pdu->data[7] << 24) |
                  ((uint32)uds_pdu->data[8] << 16) |
                  ((uint32)uds_pdu->data[9] << 8) |
                  ((uint32)uds_pdu->data[10] << 0);
            (void)upgrade_info("%s %4x addr=%4x len=%4x \r\n", __FUNCTION__, routineIdentifier, addr, len);
            crntAppId = uds_GetActiveAppSection(&SectionAddr, &SectionLen);

            if ((addr >= SectionAddr) && (addr < (SectionAddr + SectionLen)))
            {
                uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
            }
            else
            {
                isEraseComp = 1;
                Fcl_Erase(addr, len, uds_EraseRegionTest_Cbk, uds_EraseComp_Cbk);
                uds_download.crc = 0xffffffff;
                uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
            }
        }
        else if (isEraseComp == 1)
        {
            uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
        }
        else if (isEraseComp == 2)
        {
            isEraseComp = 0;
            uds_pcb.txLen = 4;
            uds_pcb.txData[0] = 0x03;
            uds_pcb.txData[1] = 0x02;
            uds_pcb.txData[2] = 0x02;
            uds_pcb.txData[3] = 0x01;
            uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
        }
        else
        {
            uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        }

        break;
    case 0x0303:
        addr = ((uint32)uds_pdu->data[3] << 24) |
               ((uint32)uds_pdu->data[4] << 16) |
               ((uint32)uds_pdu->data[5] << 8) |
               ((uint32)uds_pdu->data[6] << 0);

        len = ((uint32)uds_pdu->data[7] << 24) |
              ((uint32)uds_pdu->data[8] << 16) |
              ((uint32)uds_pdu->data[9] << 8) |
              ((uint32)uds_pdu->data[10] << 0);
        target_crc = ((uint32)uds_pdu->data[11] << 24) |
                     ((uint32)uds_pdu->data[12] << 16) |
                     ((uint32)uds_pdu->data[13] << 8) |
                     ((uint32)uds_pdu->data[14] << 0);

        crc = (uint32)Crc_CalculateCRC16((uint8 *)addr, len, 0xffff, TRUE);

        if (target_crc == crc)
        {
            uds_pcb.txLen = 4;
            uds_pcb.txData[0] = 0x03;
            uds_pcb.txData[1] = 0x03;
            uds_pcb.txData[2] = 0x02;
            uds_pcb.txData[3] = 0x01;
        }
        else
        {
            uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        }

        break;
    case 0x0304:
        // addr = ((uint32)uds_pdu->data[3] << 24) |
        //        ((uint32)uds_pdu->data[4] << 16) |
        //        ((uint32)uds_pdu->data[5] << 8) |
        //        ((uint32)uds_pdu->data[6] << 0);

        // len = ((uint32)uds_pdu->data[7] << 24) |
        //       ((uint32)uds_pdu->data[8] << 16) |
        //       ((uint32)uds_pdu->data[9] << 8) |
        //       ((uint32)uds_pdu->data[10] << 0);
        target_crc = ((uint32)uds_pdu->data[11] << 24) |
                     ((uint32)uds_pdu->data[12] << 16) |
                     ((uint32)uds_pdu->data[13] << 8) |
                     ((uint32)uds_pdu->data[14] << 0);
        // crc = Crc_CalculateCRC16((uint8*)addr,len,0xffff,TRUE);

        if (target_crc == uds_download.crc)
        {
            uds_pcb.txLen = 4;
            uds_pcb.txData[0] = 0x03;
            uds_pcb.txData[1] = 0x04;
            uds_pcb.txData[2] = 0x02;
            uds_pcb.txData[3] = 0x01;
        }
        else
        {
            uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        }

        break;
    default:
        break;
    }
    return Success;
}

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
EStatus uds_ECUReset_11(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    return Success;
}

extern VAR(EOL_13Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF187_MirrorBlock;
extern VAR(A_20Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock;
extern VAR(EOL_15Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF193_MirrorBlock;
extern VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF195_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock;
extern VAR(Dcm_Data30ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock;
extern const uint8 FOTA_NodeAddress[9];
extern const uint8 FOTA_Name[6];
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
EStatus uds_ReadDataByIdentifier_22(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    uint16 did = ((((uint16)uds_pdu->data[0]) << 8) | ((uint16)uds_pdu->data[1]));
    // uint16 dataId;
    uint32 vipVersion = 0xFFFFFFFF;
    uint8 vipSubVers = 0xFF;
    uint8 crntAppId = 1;
    uint32 addr = 0;
    uint32 len = 0;
    // uint32 keylen = 1;
    uint8_t txLen = 0;

    (void)upgrade_info("%s %4x\r\n", __FUNCTION__, did);
    switch (did)
    {
    case 0x0201:
        uds_pcb.txLen = 8;
        Version_GetSoftwareVersionVIP((uint8 *)&vipVersion, 4);
        // Cdd_HsmSecureBoot_GetAppAction(&crntAppId, &keylen);
        crntAppId = uds_GetActiveAppSection(&addr, &len);
        uds_pcb.txData[0] = 0x02;
        uds_pcb.txData[1] = 0x01;
        uds_pcb.txData[2] = (uint8)(vipVersion);
        uds_pcb.txData[3] = (uint8)(vipVersion >> 8);
        uds_pcb.txData[4] = (uint8)(vipVersion >> 16);
        uds_pcb.txData[5] = (uint8)(vipVersion >> 24);
        uds_pcb.txData[6] = vipSubVers;
        uds_pcb.txData[7] = crntAppId;
        (void)upgrade_info("%s: section:[%d] Addr:[%4x] Len:[%4x]\r\n", __FUNCTION__, crntAppId, addr, len);
        /* code */
        break;
    case 0xF187:
        uds_pcb.txLen = 2 + sizeof(EOL_13Bytes);
        uds_pcb.txData[0] = 0xF1;
        uds_pcb.txData[1] = 0x87;
        (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(Rte_EOL_NvBlockNeed_0xF187_MirrorBlock), sizeof(EOL_13Bytes));
        /* code */
        break;
    case 0xF18C:
        /* code */
        uds_pcb.txLen = 2 + sizeof(A_20Bytes);
        uds_pcb.txData[0] = 0xF1;
        uds_pcb.txData[1] = 0x8C;
        (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock), sizeof(A_20Bytes));
        break;
    case 0xF193:
        /* code */
        uds_pcb.txLen = 2 + sizeof(EOL_15Bytes);
        uds_pcb.txData[0] = 0xF1;
        uds_pcb.txData[1] = 0x93;
        (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(Rte_EOL_NvBlockNeed_0xF193_MirrorBlock), sizeof(EOL_15Bytes));
        break;
    case 0xF195:
        /* code */
        uds_pcb.txLen = 2 + sizeof(A_17Bytes);
        uds_pcb.txData[0] = 0xF1;
        uds_pcb.txData[1] = 0x95;
        Version_GetSystemSupplierECUSoftwareVersionNumber(&uds_pcb.txData[2], (uint16)sizeof(A_17Bytes));
        break;
        //    case 0xF1B3:
        //         /* code */
        //         uds_pcb.txLen = 2+sizeof(FOTA_NodeAddress);
        //         uds_pcb.txData[0] = 0xF1;
        //         uds_pcb.txData[1] = 0xB3;
        //         (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(FOTA_NodeAddress), sizeof(FOTA_NodeAddress));
        //        break;
        //     case 0xF1B5:
        //         /* code */
        //         uds_pcb.txLen = 2+sizeof(FOTA_Name);
        //         uds_pcb.txData[0] = 0xF1;
        //         uds_pcb.txData[1] = 0xB5;
        //         (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(FOTA_Name), sizeof(FOTA_Name));
        //         break;
    case 0xF1C2:
        /* code */
        uds_pcb.txLen = 2 + sizeof(A_1Bytes);
        uds_pcb.txData[0] = 0xF1;
        uds_pcb.txData[1] = 0xC2;
        (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock), sizeof(A_1Bytes));
        break;
    case 0xF1AB:
        /* code */
        txLen = 0;
        while((txLen < 30) && (Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock[txLen]!=0xFF))
        {
            txLen++;
        }
        // for (txLen=0; Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock[txLen]!=0xFF;txLen++)
        // {
        //     ;
        // }
        if (txLen>0)
        {
            uds_pcb.txLen = 2 + txLen;
            uds_pcb.txData[0] = 0xF1;
            uds_pcb.txData[1] = 0xAB;
            (void)memcpy((uint8 *)(&uds_pcb.txData[2]), (uint8 *)(Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock), txLen);
        }
        else
        {
            uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        }
        break;
    default:
        uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        break;
    }
    return Success;
}
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
EStatus uds_WriteDataByIdentifier_2E(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    uint16 did = ((((uint16)uds_pdu->data[0]) << 8) | ((uint16)uds_pdu->data[1]));
    uint32 index = uds_pdu->len;

    (void)upgrade_info("%s %4x\r\n", __FUNCTION__, did);
    switch (did)
    {
    case 0x0201:
        FotaState = uds_pdu->data[2];
        if (FotaState > 1)
        {
            uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        }
        else
        {
	        uds_pcb.txLen = 3;
		    uds_pcb.txData[0] = 0x02;
		    uds_pcb.txData[1] = 0x01;
            uds_pcb.txData[2] = 0x00;
            // Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_WriteBlock(&FotaState);
            Rte_Upgrade_NvBlockNeed_UpgradeResetFlag_MirrorBlock = FotaState;
            Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_UpgradeResetFlag_WriteBlock(NULL);
            Rte_Write_Sd_Upgrade_flag_Element(FotaState);
        }
        break;
    case 0xF1AB:
            //
            if(index < (sizeof(Dcm_Data30ByteType)+1))
            {
                for (index; index<sizeof(Dcm_Data30ByteType); index++)
                {
                    uds_pdu->data[index] = 0xff;
                }
                (void)memcpy((uint8 *)(Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock), (uint8 *)(&uds_pdu->data[2]), sizeof(Dcm_Data30ByteType));
                NvM_WriteBlock(NvMConf_NvMBlockDescriptor_DidDataProcessNvBlockNeed_VehicleSoftwareVersion, NULL);
                uds_pcb.txLen = 3;
                uds_pcb.txData[0] = 0xF1;
                uds_pcb.txData[1] = 0xAB;
                uds_pcb.txData[2] = 0x00;
            }
            else
            {
                uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
            }
            break;
    default:
        uds_pcb.err = UDS_E_33_SECURITYACCESSDENIED;
        break;
    }
    return Success;
}
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
EStatus uds_RoutineControl_31(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    return Success;
}

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
EStatus uds_RequestDownload_34(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    uint32 addr = 0;
    uint32 len = 0;

    addr = ((uint32)uds_pdu->data[2] << 24) |
           ((uint32)uds_pdu->data[3] << 16) |
           ((uint32)uds_pdu->data[4] << 8) |
           ((uint32)uds_pdu->data[5] << 0);

    len = ((uint32)uds_pdu->data[6] << 24) |
          ((uint32)uds_pdu->data[7] << 16) |
          ((uint32)uds_pdu->data[8] << 8) |
          ((uint32)uds_pdu->data[9] << 0);

    uds_download.currentAddr = addr;
    uds_download.targetAddr = addr;
    uds_download.currentSize = len;
    uds_download.targetSize = len;
    uds_download.pageCnt = 1;
    //fcl_writeRequest(addr, len);

    uds_pcb.txLen = 3;
    uds_pcb.txData[0] = 0x01;
    uds_pcb.txData[1] = 0x01;
    uds_pcb.txData[2] = 0x00;
    (void)upgrade_info("%s addr=%4x len=%4x \r\n", __FUNCTION__, addr, len);
    return Success;
}

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
static void uds_FclWriteComp_Cbk(uint32 addr, uint32 len)
{
    if ((addr % 0x1000) == 0)
    {
        (void)upgrade_info("%s : Write:%4x Length:%d\r\n", __FUNCTION__, addr, len);
    }
    writeComp = 2;
}

EStatus uds_TransferData_36(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    if (writeComp == 0)
    {
        writeComp = 1;
        if (uds_download.pageCnt != uds_pdu->data[0])
        {
            uds_pcb.err = UDS_E_24_REQUESTSEQUENCEERROR;
        }
        uds_pcb.err = (Uds_Err)Fcl_Write(uds_download.currentAddr, &uds_pdu->data[1], uds_pdu->len - 2, uds_FclWriteComp_Cbk);
    }
    else if (writeComp == 1)
    {
        uds_pcb.err = UDS_E_78_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    }
    else if (writeComp == 2)
    {
        writeComp = 0;
        uds_download.crc = (uint32)Crc_CalculateCRC16((uint8 *)uds_download.currentAddr, uds_pdu->len - 2, (uint16)uds_download.crc, FALSE);
        uds_download.currentAddr += uds_pdu->len - 2;
        uds_download.currentSize -= uds_pdu->len - 2;
        uds_download.pageCnt++;
        uds_pcb.txLen = 1;
        uds_pcb.txData[0] = uds_pdu->data[0];
        uds_pcb.err = UDS_E_00_POSITIVERESPONSE;
    }

    return Success;
}

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
EStatus uds_RequestTransferExit_37(UDS_PDU *uds_pdu, const struct UDS_SERVICE *uds_service)
{
    uds_download.pageCnt = 1;
    (void)upgrade_info("%s \r\n", __FUNCTION__);
    if (uds_download.currentSize == 0)
    {
    }
    else
    {
        uds_pcb.err = UDS_E_24_REQUESTSEQUENCEERROR;
    }
    return Success;
}

/**********************************************************************************************************************
 *  END OF FILE: Uds_Service.c
 *********************************************************************************************************************/
#endif //UDS_SERVICE_SOURCE
