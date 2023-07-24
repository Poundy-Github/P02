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
 * @file:      Cdd_HsmLog.c
 * @author:    Nobo
 * @date:      2020-6-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef CDD_HSMLOG_SOURCE
#define CDD_HSMLOG_SOURCE

/**********************************************************************************************************************
* External Function Include                                                                               
*********************************************************************************************************************/
#include "Csm.h"

#include "logger.h"
/**********************************************************************************************************************
* Internel Function Include                                                                               
*********************************************************************************************************************/

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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_Aes128_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state)
{
    return E_OK;
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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_Aes128_Callout_Post(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
    Csm_JobCalloutStateType state,
    P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue)
{
    uint8 verify = *job->jobPrimitiveInputOutput.verifyPtr;
    static uint8 error_cnt = 0x20;

    if (error_cnt)
    {
        if ((verify != 0) && (job->jobPrimitiveInputOutput.verifyPtr != NULL_PTR))
        {
            //crypto_err("AES128 Hsm Error: [%s] ", job == CsmConf_CsmJob_CsmJob_Aes128_Decrypt ? "Decrypt" : "Encrypt");
            //error_cnt--;
        }

        if (*jobReturnValue != E_OK)
        {
            crypto_err("AES128 Job Error: [%s] ", (job->jobId == CsmConf_CsmJob_CsmJob_Aes128_Decrypt) ? "Decrypt" : "Encrypt");
            error_cnt--;
        }
    }
    return E_OK;
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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_SetKey_Callout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state)
{
    return E_OK;
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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_SetKey_Callout_Post(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
    Csm_JobCalloutStateType state,
    P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue)
{
    uint8 verify = *job->jobPrimitiveInputOutput.verifyPtr;
    static uint8 error_cnt = 0x20;

    if (error_cnt)
    {
        if ((verify != 0) && (job->jobPrimitiveInputOutput.verifyPtr != NULL_PTR))
        {
            //crypto_err("Set Key verify Error: [job = %d]\r\n", job->jobId);
            //error_cnt--;
        }

        if (*jobReturnValue != E_OK)
        {
            crypto_err("Set Key Job Error: [job = %d]\r\n", job->jobId);
            error_cnt--;
        }
    }
    return E_OK;
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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_SecOc_CsmCallout_Pre(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state)
{
    return E_OK;
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
FUNC(Std_ReturnType, CSM_APPL_CODE)
CSM_SecOc_CsmCallout_Post(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
    Csm_JobCalloutStateType state,
    P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue)
{
    uint8 verify = *job->jobPrimitiveInputOutput.verifyPtr;
    const uint8 *data = job->jobPrimitiveInputOutput.inputPtr;
    uint8 i = 0;
    uint16 id=((uint16)data[0]|(uint16)data[1]);

    static struct SecOC{
        uint16 id;
        uint8 err;
        uint32 err_cnt;
    }secoc[20]={0};

    for(i=0; i<20; i++)
    {
        if(secoc[i].id == id)
        {
            break;
        }
        if(secoc[i].id == 0)
        {
            secoc[i].id = id;
            break;
        }
    }

    if (i<20)
    {
        if((verify==1)&&(secoc[i].err==0))
        {
            crypto_err("Secoc verify Error , ID[%2x%2x]\r\n", data[0], data[1]);
        }
        else if((verify==0)&&(secoc[i].err==1))
        {
            crypto_info("Secoc verify Recover , ID[%2x%2x]\r\n", data[0], data[1]);
        }

        secoc[i].err = ((verify) | (*jobReturnValue));
    }

    return E_OK;
}
/**********************************************************************************************************************
 *  END OF FILE: Cdd_HsmLog.c
 *********************************************************************************************************************/
#endif //CDD_HSMLOG_SOURCE
