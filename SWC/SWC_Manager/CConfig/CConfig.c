/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  CConfig.c
 *           Config:  D:/code/VIP_P03/VIP/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  CConfig
 *  Generation Time:  2021-04-09 14:30:39
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <CConfig>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *********************************************************************************************************************/

#include "Rte_CConfig.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
 *  %header file in this project/library%
 */
#include "CConfig.h"
#include "IPC_Misc.h"

/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */
#if ( (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_B03))
    #define VCONFIG_FIXED_FLAG TRUE
#else
    #define VCONFIG_FIXED_FLAG FALSE
#endif


/*
 *  %forward declaration%
 */
static void CConfig_Parse(void);


/*
 *  %global definition%
 */
extern CConfig_ConfigType cConfig_config;
#define CCONFIG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CConfig_MemMap.h"
 CConfig_Type cConfig = {(boolean)FALSE, 0, &cConfig_config};
#define CCONFIG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CConfig_MemMap.h"

#define CCONFIG_START_SEC_CODE
#include "CConfig_MemMap.h"

uint8 Get_Cconfig_Flag = (uint8)FALSE;
uint8 Cconfig_Response_Flag = (uint8)FALSE;

uint8 CconfigRequestUpdateLatestCount = 0u;
uint8 CconfigRequestUpdatePreCount = 0u;

#if (defined GWM_V35_PROJECT_TYPE_P03)
const uint8 Cconfig_InitValue[300] = {12U, 132U, 26U, 13U, 0U, 0U, 10U, 90U, 110U, 125U, 162U, 166U, 168U, 180U, 90U, 110U, 125U, 155U, 158U, 161U, 170U, 0U, 160U, 3U, 232U, 6U, 64U, 100U, 1U, 64U, 50U, 0U, 32U, 2U, 1U, 144U, 1U, 144U, 1U, 144U, 20U, 0U, 30U, 50U, 0U, 25U, 12U, 128U, 200U, 6U, 64U, 50U, 25U, 0U, 90U, 7U, 128U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 25U, 0U, 100U, 8U, 32U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 25U, 0U, 100U, 8U, 32U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 25U, 0U, 100U, 8U, 32U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 25U, 0U, 100U, 8U, 32U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 240U, 30U, 68U, 40U, 24U, 6U, 64U, 3U, 240U, 0U, 0U, 54U, 238U, 118U, 6U, 64U, 7U, 158U, 60U, 0U, 165U, 0U, 192U, 6U, 64U, 10U, 0U, 0U, 50U, 18U, 176U, 20U, 10U, 1U, 3U, 10U, 40U, 0U, 0U, 1U, 232U, 0U, 0U, 0U, 0U, 0U, 128U, 254U, 0U, 128U, 0U, 0U, 0U, 0U, 128U, 0U, 161U, 80U, 0U, 1U, 61U, 224U, 2U, 128U, 10U, 128U, 10U, 131U, 231U, 0U, 161U, 0U, 0U, 24U, 6U, 64U, 3U, 192U, 0U, 0U, 54U, 238U, 118U, 254U, 0U, 0U, 0U, 0U, 0U, 131U, 121U, 30U, 1U, 56U, 128U, 120U, 120U, 15U, 60U, 15U, 160U, 6U, 5U, 40U, 20U, 2U, 4U, 1U, 24U, 105U, 241U, 134U, 159U, 17U, 2U, 136U, 15U, 156U, 20U, 20U, 0U, 0U, 160U, 2U, 0U, 32U, 2U, 0U, 160U, 10U, 30U, 0U, 160U, 10U, 0U, 0U, 0U, 20U, 3U, 32U, 100U, 3U, 33U, 144U, 6U, 224U, 160U, 3U, 33U, 144U, 8U, 192U, 170U, 12U, 4U, 20U, 20U, 20U, 2U, 0U, 160U, 20U, 20U, 1U, 244U, 2U, 1U, 5U, 0U, 0U, 0U, 0U, 0U, 0U};
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * CconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * Dcm_Data300ByteType: Array with 300 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define CConfig_START_SEC_CODE
#include "CConfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OperationCConfig_GetUpdateTick> of PortPrototype <CConfig_GetUpdateTick>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CConfig_GetUpdateTick_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CConfig_CODE) CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_CCONFIG_APPL_VAR) updateTick) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick (returns application error)
 *********************************************************************************************************************/
	Std_ReturnType ret = E_OK;

    if(NULL_PTR == updateTick)
    {
        ret = E_NOT_OK;
    }
    else if(FALSE == cConfig.isInit)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *updateTick = cConfig.updateCount;
    }

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CConfig_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_Init_doc
 *********************************************************************************************************************/

/*
* @brief   :   Internal parse function to convert raw config data to kind config data
* @param   :   none
* @retval  :   none
*/
static void CConfig_Parse(void)
{
    uint16 index;
    uint16 kind;
    uint8 *rawBuffer;
    uint8 *configBuffer;

    for(kind = 0u; kind < cConfig.config->kindNumber; kind++)
    {
        const CConfig_KindConfigType *kindConfig = &cConfig.config->kindConfigs[kind];

        rawBuffer = &cConfig.config->rawData[kindConfig->byteStart];
        configBuffer = &cConfig.config->kindBuffer[kindConfig->bufferStart];
        if(1u == kindConfig->byteNumberRaw)
        {
            *configBuffer = (*rawBuffer & kindConfig->mask1) >>  kindConfig->offset;
        }
        else if(2u == kindConfig->byteNumberRaw)
        {
            uint16 result = 0u;

            result = ((uint16)(*rawBuffer) & (uint16)(kindConfig->mask1)) >> (kindConfig->offset);
            rawBuffer--;
            result |= (((uint16)(*rawBuffer) & (uint16)(kindConfig->mask2)) << (8u - kindConfig->offset));
            for(index = kindConfig->bufferStart; index < kindConfig->bufferEnd; index++)
            {
                *configBuffer = (uint8)result;
                configBuffer++;
                result = (result >> 8);
            }
        }
        else
        {
            uint16 result16 = 0u;
            uint8 rawByteLeft = kindConfig->byteNumberRaw;
            uint16 configByteLeft = kindConfig->bufferEnd - kindConfig->bufferStart;

            while(rawByteLeft > 2u)
            {
                uint8 result = 0u;
                result = ((*rawBuffer) & (kindConfig->mask1)) >> (kindConfig->offset);
                rawBuffer--;
                result |= ((*rawBuffer) & (255u - kindConfig->mask1)) << (8u - kindConfig->offset);

                *configBuffer = result;
                configBuffer++;
                rawByteLeft--;
                configByteLeft--;
            }

            result16 = (((uint16)(*rawBuffer) & (uint16)(kindConfig->mask1)) >> (kindConfig->offset));
            rawBuffer--;
            result16 |= (((uint16)(*rawBuffer) & (uint16)(kindConfig->mask2)) << (8u - kindConfig->offset));
            for(index = 0; index < configByteLeft; index++)
            {
                *configBuffer = (uint8)result16;
                configBuffer++;
                result16 = (result16 >> 8);
            }
        }
    }
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CConfig_CODE) CConfig_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_Init
 *********************************************************************************************************************/
    Std_ReturnType ret = E_OK;
	CConfig_ConfigType *config = cConfig.config;
	
#if(CCONFIG_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == config)
    {
        ret = E_NOT_OK;
    }
    else if((0u == config->kindNumber) ||
			(NULL_PTR == config->kindConfigs))
    {
        ret = E_NOT_OK;
    }
    else
#endif
    {
#if VCONFIG_FIXED_FLAG
        (void)memcpy(cConfig.config->rawDataBackup,Cconfig_InitValue,sizeof(Dcm_Data300ByteType));
        (void)memcpy(cConfig.config->rawData,Cconfig_InitValue,sizeof(Dcm_Data300ByteType));
#else
        Rte_Read_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(cConfig.config->rawDataBackup);
		Rte_Read_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(cConfig.config->rawData);
#endif 
		CConfig_Parse();
		
			/* TODO: Set data of port */
		(void)Rte_Write_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(cConfig.config->kindBuffer);
			/* Send ipc data to SOC */
		(void)IPC_M2S_MiscServiceCconfig_Transmit(cConfig.config->rawData);

		
        /* Clear update flag */
        cConfig.updateCount = 0u;
        /* set config to module config */
        
        cConfig.isInit = TRUE;
    }

    if(E_OK != ret)
    {
        /* Report */
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CConfig_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(uint8 *data)
 *   Std_ReturnType Rte_Read_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(uint8 *data)
 *     Argument data: uint8* is of type Dcm_Data300ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(const uint8 *data)
 *     Argument data: uint8* is of type CconfigKind_400Bytes
 *   Std_ReturnType Rte_Write_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CConfig_CODE) CConfig_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CConfig_MainFunction
 *********************************************************************************************************************/



	
	Rte_Read_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(&CconfigRequestUpdateLatestCount);
	if(((CconfigRequestUpdateLatestCount -1) == CconfigRequestUpdatePreCount) || (Get_Cconfig_Flag == TRUE))
	{
		/* TODO: Get data from DCM Server */
#if !(VCONFIG_FIXED_FLAG)
        Rte_Read_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(cConfig.config->rawData);
#endif
		/* check config change */
		/*
		for(pos = 0u; pos < cConfig.config->rawDataSize; pos++)
		{
			if(cConfig.config->rawData[pos] != cConfig.config->rawDataBackup[pos])
			{
				parseNeed = TRUE;
				cConfig.config->rawData[pos] = cConfig.config->rawDataBackup[pos];
			}
		}
		*/

		CConfig_Parse();
		cConfig.updateCount++;

        /* TODO: Set data of port */
        (void)Rte_Write_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(cConfig.config->kindBuffer);
		/* Send ipc data to SOC */
		(void)IPC_M2S_MiscServiceCconfig_Transmit(cConfig.config->rawData);
		Get_Cconfig_Flag = (uint8)FALSE;
		
		CconfigRequestUpdatePreCount = CconfigRequestUpdateLatestCount;
		if(CconfigRequestUpdatePreCount == 255)
		{
			CconfigRequestUpdatePreCount = 0;
		}
	}
	if(Cconfig_Response_Flag == TRUE)
    {
		Rte_Write_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(TRUE);
		Cconfig_Response_Flag = (uint8)FALSE;
    }
	
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CConfig_STOP_SEC_CODE
#include "CConfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
