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

/***********************************************************************************************************
**
**  Name         : SWC_IPC_DataCheck.c
**
**  Description  :        
**
**  Organization :       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Interface.h"
#include "SWC_IPC_DataCheck.h"
#include "SWC_IPC_Config.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC Crc Table                                                                                           *
**********************************************************************************************************/

const uint8 SWC_IPC__CrcTable[] =  SWC_IPC_DATA_CHECK_CRC_TABLE ;

#define SWC_IPC_NW_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC Data Check Repeater Object                                                                          *
**********************************************************************************************************/

static SWC_IPC_DataCheckObject SWC_IPC__DataCheckObject ;

#define SWC_IPC_NW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h" 

/**********************************************************************************************************
* Static Function Defination                                                                              *
**********************************************************************************************************/

#ifdef SWC_IPC_OBJECT_CHECK

static void IPC_WriteCanNvmObject(void* Data, SWC_IPC_CanRepeaterObject * const Object);

static void IPC_ReadCanNvmObject(void* Data, SWC_IPC_CanRepeaterObject * const Object);

#endif


/**********************************************************************************************************
*Function   : IPC_DataCheckInit                                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_DataCheckInit(void)
{
	
}

/**********************************************************************************************************
*Function   : IPC_DataCheckTask                                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_DataCheckTask(void)
{
	
}

/**********************************************************************************************************
*Function   : IPC_CalculateDataChecksum                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-29                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_OBJECT_CHECK
uint8 IPC_CalculateDataChecksum(void* const Data , const uint32 Length)
{
	uint32 index;
	uint8 Checksum = SWC_IPC_CHECKSUM_INIT_VALUE;
	 
	for(index = 0; index < Length; index++)
	{
		Checksum += *(Data++);
	}
	
	Checksum = ~Checksum;
	return Checksum;
}
#endif
/**********************************************************************************************************
*Function   : IPC_CalculateDataCrc                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-29                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_OBJECT_CHECK
uint8 IPC_CalculateDataCrc(const void* const Data , const uint32 Length)
{
	SWC_IPC_DataCheckObject * Object = &SWC_IPC__DataCheckObject;
	uint8 CrcValue;
    uint8 CrcIndex;
    uint16 index = 0;

    CrcValue = 0;
    for (index = 0; index < Length; index++) 
    {
        CrcIndex = CrcValue ^ Data[index];
        CrcValue = Object->CrcTable[CrcIndex];
    }

    return CrcValue;
}
#endif
/**********************************************************************************************************
*Function   : IPC_API_WriteCanRepeaterNvm                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const void* const Data, const uint32 length ,SWC_IPC_CanRepeaterObject * const Object       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-29                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_OBJECT_CHECK
static void IPC_API_WriteCanRepeaterNvm( const void* const Data, const uint32 length ,SWC_IPC_CanRepeaterObject * const Object )
{
	Rte_Enter_ExclusiveArea();

	

	


	Rte_Exit_ExclusiveArea();
}
#endif
/**********************************************************************************************************
*Function   : IPC_API_ReadCanRepeaterNvm                                                                  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const void* const Data, const uint32 length ,SWC_IPC_CanRepeaterObject * const Object       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-29                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_OBJECT_CHECK
static void IPC_API_ReadCanRepeaterNvm( const void* const Data, const uint32 length ,SWC_IPC_CanRepeaterObject * const Object )
{
	Rte_Enter_ExclusiveArea();

	

	


	Rte_Exit_ExclusiveArea();
}
#endif


#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision : 2.0  
**
**  Author   : HenryChan , Cao Wenping
**
**  Date     : 2020/07/10  1.0    Original Version.    Cao Wenping
**             2020/08/06  2.0    Firmwork Update.     HenryChan
**
**********************************************************************************************************/


/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
