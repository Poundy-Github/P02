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
 * @file:      DcmEx.c
 * @author:    Nobo
 * @date:      2020-5-24
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-24
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Dcm.h"
#include "DcmEx.h"
#include "DcmEx_Type.h"
#include "IPC_Diagnose.h"
#include "Logger.h"

#define DCM_DID_SUPPORTED       (0U)
#define DCM_DID_NOT_SUPPORTED   (1U)

#define DCMEX_STATE_IDLE                          (0U)
#define DCMEX_STATE_AVAIABLE_CHECKING             (1U)
#define DCMEX_STATE_AVAIABLE_CHECKED              (2U)
#define DCMEX_STATE_LENGTH_CHECKING               (3U)
#define DCMEX_STATE_LENGTH_CHECKED                (4U)
#define DCMEX_STATE_SECURITY_CHECKED              (5U)
#define DCMEX_STATE_CONDITION_CHECKING            (6U)
#define DCMEX_STATE_CONDITION_CHECKED             (7U)
#define DCMEX_STATE_READING_WRITING               (8U)


extern DcmEx_CfgType dcmEx_cfg;
extern DcmEx_Type dcmEx_data;

static Std_ReturnType DcmEx_FindDidRead(uint16 DID, uint16 *index);
static Std_ReturnType DcmEx_FindDidWrite(uint16 DID, uint16 *index);
static boolean DcmEx_SessionSecurityCheckInternal(uint8 ssStart, uint8 ssNumber);
static boolean DcmEx_SessionCheckInternal(uint8 ssStart, uint8 ssNumber);
static boolean DcmEx_SecurityCheckInternal(uint8 ssStart, uint8 ssNumber);
static Std_ReturnType DcmEx_DidSecurityCheck(boolean isRead, uint16 index);
static Std_ReturnType DcmEx_DidLengthCheckRead(uint16 index);
static Std_ReturnType DcmEx_DidLengthCheckWrite(uint16 index, uint16 length);
static Std_ReturnType DcmEx_IsAvaiableDidInternal(boolean isRead, uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported);
static Std_ReturnType DcmEx_ConditionCheck(boolean isRead, uint16 index, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
static Std_ReturnType DcmEx_ReadInternal(uint16 index, uint8 *Data, uint16 DataLength);
static Std_ReturnType DcmEx_WriteInternal(uint16 index, const uint8 *Data, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode);

static Std_ReturnType DcmEx_FindDidRead(uint16 DID, uint16 *index)
{
    uint16 i;
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR == index)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((DID == dcmEx_data.did.didCurrent) && (TRUE == dcmEx_data.did.isRead))
        {
            *index = dcmEx_data.did.indexCurrent;
            ret = E_OK;
        }
        else
        {
            for(i = 0u; i < dcmEx_cfg.didNumber; i++)
            {
                if((DID == dcmEx_cfg.didCfgs[i].did) && 
                    ((dcmEx_cfg.didCfgs[i].supportType & DCMEX_DID_SUPPORT_READ) == DCMEX_DID_SUPPORT_READ))
                {
                    ret = E_OK;
                    *index = i;
                    dcmEx_data.did.didCurrent = DID;
                    dcmEx_data.did.indexCurrent = i;
                    dcmEx_data.did.isRead = TRUE;
                    break;
                }
            }

            if(dcmEx_cfg.didNumber == i)
            {
                can_warn("DID %04X can not find read index", DID);
            }
            else
            {
                can_warn("DID %04X find read index", DID);
            }
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_FindDidWrite(uint16 DID, uint16 *index)
{
    uint16 i;
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR == index)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((DID == dcmEx_data.did.didCurrent) && (FALSE == dcmEx_data.did.isRead))
        {
            *index = dcmEx_data.did.indexCurrent;
	        ret = E_OK;
        }
        else
        {
            for(i = 0u; i < dcmEx_cfg.didNumber; i++)
            {
                if((DID == dcmEx_cfg.didCfgs[i].did) && 
                    ((dcmEx_cfg.didCfgs[i].supportType & DCMEX_DID_SUPPORT_WRITE) == DCMEX_DID_SUPPORT_WRITE))
                {
                    ret = E_OK;
                    *index = i;
                    dcmEx_data.did.didCurrent = DID;
                    dcmEx_data.did.indexCurrent = i;
                    dcmEx_data.did.isRead = FALSE;
                    break;
                }
            }

            if(dcmEx_cfg.didNumber == i)
            {
                can_warn("DID %04X can not find write index", DID);
            }
            else
            {
                can_warn("DID %04X find write index", DID);
            }
        }
    }

    return ret;
}

static boolean DcmEx_SessionCheckInternal(uint8 ssStart, uint8 ssNumber)
{
    boolean ret = FALSE;
    uint8 ssIndex = 0u;
    Dcm_SesCtrlType session = 0u;

    if(((ssStart + ssNumber) > 0u) && ((ssStart + ssNumber - 1u) < dcmEx_cfg.ssNumber))
    {
        (void)Dcm_GetSesCtrlType(&session);
        if(RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION == session)
        {
            session = DCMEX_SESSION_DEFAULT;
        }
        else if(RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == session)
        {
            session = DCMEX_SESSION_EXTEND;
        }
        else if(RTE_MODE_Dcm_DcmDiagnosticSessionControl_EOLDiagnosticSession == session)
        {
            session = DCMEX_SESSION_EOL;
        }
        else
        {
            session = 0u;
        }

        for(ssIndex = ssStart; ssIndex < (ssStart + ssNumber); ssIndex++)
        {
            if((session & dcmEx_cfg.ssCfgs[ssIndex].sessionMap) != 0u)
            {
                ret = TRUE;
                break;
            }
        }
    }

    return ret;
}

static boolean DcmEx_SecurityCheckInternal(uint8 ssStart, uint8 ssNumber)
{
    boolean ret = FALSE;
    uint8 ssIndex = 0u;
    Dcm_SecLevelType securiyLevel = 0u;

    if(((ssStart + ssNumber) > 0u) && ((ssStart + ssNumber - 1u) < dcmEx_cfg.ssNumber))
    {
        (void)Dcm_GetSecurityLevel(&securiyLevel);
        
        if(DCM_SEC_LEV_LOCKED == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_NONE;
        }
        else if(DCM_SEC_LEV_L1 == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_L1;
        }
        else if(DCM_SEC_LEV_L49 == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_EOL;
        }
        else
        {
            securiyLevel = DCMEX_SECURITY_OTHER;
        }

        for(ssIndex = ssStart; ssIndex < (ssStart + ssNumber); ssIndex++)
        {
            if((securiyLevel & dcmEx_cfg.ssCfgs[ssIndex].securityMap) != 0u)
            {
                ret = TRUE;
                break;
            }
        }
    }

    return ret;
}

static boolean DcmEx_SessionSecurityCheckInternal(uint8 ssStart, uint8 ssNumber)
{
    boolean ret = FALSE;
    uint8 ssIndex = 0u;
    Dcm_SecLevelType securiyLevel = 0u;
    Dcm_SesCtrlType session = 0u;

    if(((ssStart + ssNumber) > 0u) && ((ssStart + ssNumber - 1u) < dcmEx_cfg.ssNumber))
    {
        (void)Dcm_GetSesCtrlType(&session);
        (void)Dcm_GetSecurityLevel(&securiyLevel);
        if(RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION == session)
        {
            session = DCMEX_SESSION_DEFAULT;
        }
        else if(RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION == session)
        {
            session = DCMEX_SESSION_EXTEND;
        }
        else if(RTE_MODE_Dcm_DcmDiagnosticSessionControl_EOLDiagnosticSession == session)
        {
            session = DCMEX_SESSION_EOL;
        }
        else
        {
            session = 0u;
        }

        if(DCM_SEC_LEV_LOCKED == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_NONE;
        }
        else if(DCM_SEC_LEV_L1 == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_L1;
        }
        else if(DCM_SEC_LEV_L49 == securiyLevel)
        {
            securiyLevel = DCMEX_SECURITY_EOL;
        }
        else
        {
            securiyLevel = DCMEX_SECURITY_OTHER;
        }

        for(ssIndex = ssStart; ssIndex < (ssStart + ssNumber); ssIndex++)
        {
            if(((session & dcmEx_cfg.ssCfgs[ssIndex].sessionMap) != 0u) && ((securiyLevel & dcmEx_cfg.ssCfgs[ssIndex].securityMap) != 0u))
            {
                ret = TRUE;
                break;
            }
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_DidSecurityCheck(boolean isRead, uint16 index)
{
    uint8 ssStart = 0u;
    uint8 ssNumber = 0u;
    Std_ReturnType ret = RTE_E_INVALID;
    boolean retGet = FALSE;

    if(DCM_E_SECURITYACCESSDENIED == dcmEx_data.did.error)
    {
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        if(TRUE == isRead)
        {
            ssStart = dcmEx_cfg.didCfgs[index].readCfg.ssStart;
            ssNumber = dcmEx_cfg.didCfgs[index].readCfg.ssNumber;
        }
        else
        {
            ssStart = dcmEx_cfg.didCfgs[index].writeCfg.ssStart;
            ssNumber = dcmEx_cfg.didCfgs[index].writeCfg.ssNumber;
        }
        retGet = DcmEx_SecurityCheckInternal(ssStart, ssNumber);
        if(TRUE == retGet)
        {
            dcmEx_data.did.state = DCMEX_STATE_SECURITY_CHECKED;
            ret = RTE_E_OK;
        }
        else
        {
            dcmEx_data.did.error = DCM_E_SECURITYACCESSDENIED;
            dcmEx_data.did.state = DCMEX_STATE_IDLE;
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_DidLengthCheckRead(uint16 index)
{
    Std_ReturnType ret = RTE_E_OK;

    if(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT == dcmEx_data.did.error)
    {
        ret = RTE_E_INVALID;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        if(FALSE == dcmEx_cfg.didCfgs[index].isFlexible)
        {
            ret = RTE_E_OK;
            dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKED;
            dcmEx_data.did.lengthCurrent = dcmEx_cfg.didCfgs[index].length;
        }
        else if(NULL_PTR == dcmEx_cfg.didCfgs[index].readCfg.checkLength)
        {
            ret = RTE_E_INVALID;
            dcmEx_data.did.error = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            dcmEx_data.did.state = DCMEX_STATE_IDLE;
        }
        else
        {
            ret = dcmEx_cfg.didCfgs[index].readCfg.checkLength(dcmEx_data.did.didCurrent, dcmEx_data.did.opStatus, &dcmEx_data.did.lengthCurrent);
            if(RTE_E_INVALID == ret)
            {
                ret = RTE_E_INVALID;
                dcmEx_data.did.error = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
            else if(DCM_E_PENDING == ret)
            {
                ret = DCM_E_PENDING;
                dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKING;
            }
            else
            {
                if(dcmEx_data.did.lengthCurrent > dcmEx_cfg.didCfgs[index].length)
                {
                    dcmEx_data.did.lengthCurrent = dcmEx_cfg.didCfgs[index].length;
                    ret = RTE_E_OK;
                    dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKED;
                }
                else
                {
                    ret = RTE_E_OK;
                    dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKED;
                }
            }
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_DidLengthCheckWrite(uint16 index, uint16 length)
{
    Std_ReturnType ret = RTE_E_OK;

    if(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT == dcmEx_data.did.error)
    {
        ret = (uint8)FALSE;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        if(FALSE == dcmEx_cfg.didCfgs[index].isFlexible)
        {
            if(length != dcmEx_cfg.didCfgs[index].length)
            {
                ret = RTE_E_INVALID;
                dcmEx_data.did.error = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
            else
            {
                ret = RTE_E_OK;
                dcmEx_data.did.lengthCurrent = length;
                dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKED;
            }
        }
        else
        {
            if(length > dcmEx_cfg.didCfgs[index].length)
            {
                ret = RTE_E_INVALID;
                dcmEx_data.did.error = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
            else
            {
                ret = RTE_E_OK;
                dcmEx_data.did.lengthCurrent = length;
                dcmEx_data.did.state = DCMEX_STATE_LENGTH_CHECKED;
            }
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_IsAvaiableDidInternal(boolean isRead, uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported)
{
    uint16 indexFound = 0u;
    Std_ReturnType retFound = E_NOT_OK;
    Std_ReturnType ret = E_OK;
    
    uint8 ssStart = 0u;
    uint8 ssNumber = 0u;
    boolean retGet = FALSE;

    if(TRUE == isRead)
    {
        retFound = DcmEx_FindDidRead(DID, &indexFound); 
    }
    else
    {
        retFound = DcmEx_FindDidWrite(DID, &indexFound);
    }

    if(E_NOT_OK == retFound)
    {
        *supported = DCM_DID_NOT_SUPPORTED;
        ret = RTE_E_INVALID;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        DcmEx_CheckAvailableHandlerType handler;

        dcmEx_data.did.didCurrent = DID;
        dcmEx_data.did.indexCurrent = indexFound;

        if(TRUE == isRead)
        {
            handler = dcmEx_cfg.didCfgs[indexFound].readCfg.checkAvailable;
            
            ssStart = dcmEx_cfg.didCfgs[indexFound].readCfg.ssStart;
            ssNumber = dcmEx_cfg.didCfgs[indexFound].readCfg.ssNumber;
        }
        else
        {
            handler = dcmEx_cfg.didCfgs[indexFound].writeCfg.checkAvailable;
            
            ssStart = dcmEx_cfg.didCfgs[indexFound].writeCfg.ssStart;
            ssNumber = dcmEx_cfg.didCfgs[indexFound].writeCfg.ssNumber;
        }

        retGet = DcmEx_SessionCheckInternal(ssStart, ssNumber);

        if(TRUE == retGet)
        {
            if(NULL_PTR != handler)
            {
                ret = handler(DID, OpStatus, &dcmEx_data.did.error, dcmEx_cfg.didCfgs[indexFound].length);
                if(RTE_E_INVALID == ret)
                {
                    if(DCM_E_REQUESTOUTOFRANGE == dcmEx_data.did.error)
                    {
                        *supported = DCM_DID_NOT_SUPPORTED;
                        ret = RTE_E_INVALID;
                        dcmEx_data.did.state = DCMEX_STATE_IDLE;
                        can_warn("DID %04X available fail with error: %02X", DID, dcmEx_data.did.error);
                    }
                    else
                    {
                        *supported = DCM_DID_SUPPORTED;
                        ret = RTE_E_OK;
                        dcmEx_data.did.state = DCMEX_STATE_AVAIABLE_CHECKED;
                        can_warn("DID %04X available success with error: %02X", DID, dcmEx_data.did.error);
                    }
                }
                else if(DCM_E_PENDING == ret)
                {
                    ret = DCM_E_PENDING;
                    dcmEx_data.did.state = DCMEX_STATE_AVAIABLE_CHECKING;
                }
                else
                {
                    *supported = DCM_DID_SUPPORTED;
                    ret = RTE_E_OK;
                    dcmEx_data.did.state = DCMEX_STATE_AVAIABLE_CHECKED;
                    can_warn("DID %04X available success with error: %02X", DID, dcmEx_data.did.error);
                }
            }
            else
            {
                *supported = DCM_DID_SUPPORTED;
                ret = RTE_E_OK;
                dcmEx_data.did.error = DCM_E_OK;
                dcmEx_data.did.state = DCMEX_STATE_AVAIABLE_CHECKED;
                can_warn("DID %04X available success with error: %02X", DID, dcmEx_data.did.error);
            }
        }
        else
        {
            *supported = DCM_DID_NOT_SUPPORTED;
            ret = RTE_E_INVALID;
            dcmEx_data.did.state = DCMEX_STATE_IDLE;
            can_warn("DID %04X session check fail", DID);
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_ConditionCheck(boolean isRead, uint16 index, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
    Std_ReturnType ret = E_OK;
    DcmEx_CheckConditionHandlerType handler;

    if(DCM_E_CONDITIONSNOTCORRECT == dcmEx_data.did.error)
    {
        ret = RTE_E_INVALID;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        if(TRUE == isRead)
        {
            handler = dcmEx_cfg.didCfgs[index].readCfg.checkCondition;
        }
        else
        {
            handler = dcmEx_cfg.didCfgs[index].writeCfg.checkCondition;
        }

        if(NULL_PTR != handler)
        {
            ret = handler(dcmEx_data.did.didCurrent, OpStatus, &dcmEx_data.did.error);
            if(RTE_E_INVALID == ret)
            {
                if(DCM_E_CONDITIONSNOTCORRECT == dcmEx_data.did.error)
                {
                    ret = RTE_E_INVALID;
                    dcmEx_data.did.state = DCMEX_STATE_IDLE;
                }
                else
                {
                    ret = RTE_E_OK;
                    dcmEx_data.did.state = DCMEX_STATE_CONDITION_CHECKED;
                }
            }
            else if(DCM_E_PENDING == ret)
            {
                ret = DCM_E_PENDING;
                dcmEx_data.did.state = DCMEX_STATE_CONDITION_CHECKING;
            }
            else
            {
                ret = RTE_E_OK;
                dcmEx_data.did.state = DCMEX_STATE_CONDITION_CHECKED;
            }
        }
        else
        {
            ret = RTE_E_OK;
            dcmEx_data.did.state = DCMEX_STATE_CONDITION_CHECKED;
        }
    }
    
    return ret;
}

static Std_ReturnType DcmEx_ReadInternal(uint16 index, uint8 *Data, uint16 DataLength)
{
    Std_ReturnType ret = E_OK;

    if(DCM_E_OK != dcmEx_data.did.error)
    {
        ret = RTE_E_INVALID;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        DcmEx_ReadDataHandlerType handler = dcmEx_cfg.didCfgs[index].readCfg.read;

        if(NULL_PTR != handler)
        {
            ret = handler(dcmEx_data.did.didCurrent, dcmEx_data.did.opStatus, Data, DataLength);
            if(DCM_E_PENDING == ret)
            {
                ret = DCM_E_PENDING;
                dcmEx_data.did.state = DCMEX_STATE_READING_WRITING;
            }
            else if(DCM_E_OK == ret)
            {
                ret = RTE_E_OK;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
            else
            {
                ret = RTE_E_INVALID;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
        }
        else
        {
            ret = RTE_E_OK;
            dcmEx_data.did.state = DCMEX_STATE_IDLE;
            dcmEx_data.did.error = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    return ret;
}

static Std_ReturnType DcmEx_WriteInternal(uint16 index, const uint8 *Data, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
    Std_ReturnType ret = E_OK;

    if(DCM_E_OK != dcmEx_data.did.error)
    {
        ret = RTE_E_INVALID;
        dcmEx_data.did.state = DCMEX_STATE_IDLE;
    }
    else
    {
        DcmEx_WriteDataHandlerType handler = dcmEx_cfg.didCfgs[index].writeCfg.write;

        if(NULL_PTR != handler)
        {
            ret = handler(dcmEx_data.did.didCurrent, Data, dcmEx_data.did.opStatus, &dcmEx_data.did.error, DataLength);
            if(DCM_E_PENDING == ret)
            {
                ret = DCM_E_PENDING;
                dcmEx_data.did.state = DCMEX_STATE_READING_WRITING;
            }
            else if(DCM_E_OK == ret)
            {
                ret = RTE_E_OK;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
            else
            {
                ret = RTE_E_INVALID;
                dcmEx_data.did.state = DCMEX_STATE_IDLE;
            }
        }
        else
        {
            ret = RTE_E_OK;
            dcmEx_data.did.state = DCMEX_STATE_IDLE;
            dcmEx_data.did.error = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    return ret;
}

Std_ReturnType DcmEx_IsAvailableDid(uint16 DID, Dcm_OpStatusType OpStatus, Dcm_DidSupportedType *supported)
{
    Std_ReturnType ret = E_NOT_OK;

    if(0x22 == dcmEx_data.did.sidCurrent)
    {
        ret = DcmEx_IsAvaiableDidInternal(TRUE, DID, OpStatus, supported);
    }
    else if(0x2E == dcmEx_data.did.sidCurrent)
    {
        ret = DcmEx_IsAvaiableDidInternal(FALSE, DID, OpStatus, supported);
    }
    else
    {
        *supported = DCM_DID_NOT_SUPPORTED;
    }

    return ret;
}

Std_ReturnType DcmEx_DidRead(uint16 DID, uint8 *Data, Dcm_OpStatusType OpStatus, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
    uint16 index = 0xFFFFu;
    Std_ReturnType ret = E_NOT_OK;
    Std_ReturnType retFound = E_NOT_OK;

    retFound =  DcmEx_FindDidRead(DID, &index);
    if(E_NOT_OK == retFound)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }

    if(index >= dcmEx_cfg.didNumber)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
        if((DCMEX_STATE_LENGTH_CHECKING == dcmEx_data.did.state) || (DCMEX_STATE_AVAIABLE_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_DidLengthCheckRead(index);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X read length success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X read length fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_LENGTH_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_DidSecurityCheck(TRUE, index);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X read security success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X read security fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_CONDITION_CHECKING == dcmEx_data.did.state) || (DCMEX_STATE_SECURITY_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_ConditionCheck(TRUE, index, dcmEx_data.did.opStatus, &dcmEx_data.did.error);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X read condition success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X read condition fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_READING_WRITING == dcmEx_data.did.state) || (DCMEX_STATE_CONDITION_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_ReadInternal(index, Data, dcmEx_data.did.lengthCurrent);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error; 
                *DataLength = dcmEx_data.did.lengthCurrent;
                can_warn("DID %04X read success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X read fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }
    }

    return ret;
}

Std_ReturnType DcmEx_DidWrite(uint16 DID, const uint8 *Data, Dcm_OpStatusType OpStatus, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
{
    uint16 index = 0xFFFFu;
    Std_ReturnType ret = E_NOT_OK;
    Std_ReturnType retFound = E_NOT_OK;

    retFound =  DcmEx_FindDidWrite(DID, &index);
    if(E_NOT_OK == retFound)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }

    if(index >= dcmEx_cfg.didNumber)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
        if((DCMEX_STATE_LENGTH_CHECKING == dcmEx_data.did.state) || (DCMEX_STATE_AVAIABLE_CHECKED == dcmEx_data.did.state))
        {
            if(TRUE == dcmEx_data.did.isRead)
            {
                ret = DcmEx_DidLengthCheckRead(index);
            }
            else
            {
                ret = DcmEx_DidLengthCheckWrite(index, DataLength);
            }
            
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X write length success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X write length fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_LENGTH_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_DidSecurityCheck(FALSE, index);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X write security success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                *ErrorCode = dcmEx_data.did.error;
                can_warn("DID %04X write security fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_CONDITION_CHECKING == dcmEx_data.did.state) || (DCMEX_STATE_SECURITY_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_ConditionCheck(FALSE, index, dcmEx_data.did.opStatus, &dcmEx_data.did.error);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X write condition success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                 *ErrorCode = dcmEx_data.did.error;
                 can_warn("DID %04X write condition fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }

        if((DCMEX_STATE_READING_WRITING == dcmEx_data.did.state) || (DCMEX_STATE_CONDITION_CHECKED == dcmEx_data.did.state))
        {
            ret = DcmEx_WriteInternal(index, Data, dcmEx_data.did.lengthCurrent, &dcmEx_data.did.error);
            if(RTE_E_OK == ret)
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                can_warn("DID %04X write success with error: %02X", DID, dcmEx_data.did.error);
            }
            else if(DCM_E_PENDING == ret)
            {
                dcmEx_data.did.opStatus = DCM_PENDING;
            }
            else
            {
                dcmEx_data.did.opStatus = DCM_INITIAL;
                 *ErrorCode = dcmEx_data.did.error;
                 can_warn("DID %04X write fail with error: %02X", DID, dcmEx_data.did.error);
            }
        }
    }

    return ret;
}

void DcmEx_SetCurrentSid(uint8 sid)
{
    memset(&dcmEx_data.did,0,sizeof(dcmEx_data.did));
    dcmEx_data.did.sidCurrent = sid;
}

void DcmEx_DtcRetryAvailable(void)
{
    uint16 i;
    Std_ReturnType ret = E_NOT_OK;

    for(i = 0u; i < dcmEx_cfg.dtcNumber; i++)
    {
        if(dcmEx_cfg.dtcs[i].avaiableActual != dcmEx_cfg.dtcs[i].avaiableExpect)
        {
            ret = Dem_SetEventAvailable(dcmEx_cfg.dtcCfgs[i].dtcId, dcmEx_cfg.dtcs[i].avaiableExpect);
            if(E_OK == ret)
            {
                dcmEx_cfg.dtcs[i].avaiableActual = dcmEx_cfg.dtcs[i].avaiableExpect;
            }
        }
    }

}

void DcmEx_AvailableCheck(void)
{
    uint16 i;
    Std_ReturnType ret = E_NOT_OK;

    for(i = 0u; i < dcmEx_cfg.dtcNumber; i++)
    {
        if(NULL_PTR != dcmEx_cfg.dtcCfgs[i].avaiable)
        {
            dcmEx_cfg.dtcs[i].avaiableExpect = dcmEx_cfg.dtcCfgs[i].avaiable(dcmEx_cfg.dtcCfgs[i].dtc);
            ret = Dem_SetEventAvailable(dcmEx_cfg.dtcCfgs[i].dtcId, dcmEx_cfg.dtcs[i].avaiableExpect);
            if(E_OK == ret)
            {
                dcmEx_cfg.dtcs[i].avaiableActual = dcmEx_cfg.dtcs[i].avaiableExpect;
            }
            else
            {
                // When Dem_SetEventAvailable fail, make avaiableActual != avaiableExpect, ensure retry execution
                if (FALSE == dcmEx_cfg.dtcs[i].avaiableExpect)
                {
                    dcmEx_cfg.dtcs[i].avaiableActual = TRUE;
                }
                else
                {
                    dcmEx_cfg.dtcs[i].avaiableActual = FALSE;
                }
            }
        }
        else
        {
            dcmEx_cfg.dtcs[i].avaiableActual = FALSE;
            dcmEx_cfg.dtcs[i].avaiableExpect = FALSE;
        }
    }
}

boolean DcmEx_DtcAvaiableCheckAlwaysTrue(uint32 dtc)
{
    return TRUE;
}

boolean DcmEx_DtcAvaiableCheckAlwaysFalse(uint32 dtc)
{
    return FALSE;
}



