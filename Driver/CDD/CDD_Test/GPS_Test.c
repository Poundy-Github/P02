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
 * @file:      GPS_Test.c
 * @author:    Nobo
 * @date:      2020-6-15
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-15
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "RingBuffer.h"
#include "GPS_Test.h"
#include "Logger.h"
#include "CDD_Test.h"

#define MSG_MAX_SIZE                    (256)

#define MSG_STATE_LENGTH_ERROR		(1)

#define GPS_MSG_DEF_GPGGA           (0)
#define GPS_MSG_DEF_PDTIN           (1)
#define GPS_MSG_DEF_NUMBER          (2)

#define GPS_TX_RING_BUFFER_ID          RB_ID_GPS_UART_TX
#define GPS_RX_RING_BUFFER_ID          RB_ID_GPS_UART_RX

typedef void (*GPS_COMMAND_CALLBACK)(const  char *Buffer, uint16 len );


typedef struct
{
    const char * CmdName;
    uint16 ParametersNamble;
    GPS_COMMAND_CALLBACK callback;
    
}GPS_CMD_t;


static volatile boolean bUartStatus = FALSE;
static char GPS_Buffer[MSG_MAX_SIZE+1]={0};
static uint16 GPS_BufferCnt=0; 
static uint16 GPS_BufferState=0;
static uint16 GPGGA_NoSV=0;

extern boolean IsDigitStr(char const  * src, sint32 len);
static void GPS_GPGGACommand(const  char *Buffer, uint16 len );
static void GPS_UnicoreAnalysis(const char * pcCommandString,uint16_t len);
const char *GPS_CLIGetParameter( const char *pcCommandString, uint16 uxWantedParameter, uint16 *pxParameterStringLength );
static int8_t GPS_GetNumberOfParameters( const char *pcCommandString );
static void GPS_PDTINFOCommand(const  char *Buffer, uint16 len );



static const GPS_CMD_t GPS_CMD_Table[GPS_MSG_DEF_NUMBER] = 
{
    {"GGA",14,GPS_GPGGACommand},
    {"TINFO",6,GPS_PDTINFOCommand},
};


static uint8 CMD_PDTINFO[] = "$PDTINFO\r\n";



static void GPS_PDTINFOCommand(const  char *Buffer, uint16 len )
{
    Logger_StringFromCLI(Buffer);
    Logger_StringFromCLI("\r\n");
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static void GPS_DataInit(void)
{
    GPS_BufferCnt = 0;
    GPS_BufferState = 0;
    (void)memset(GPS_Buffer,0,sizeof(GPS_Buffer));
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GPS_Init(void)
{
    (void)RB_Init(GPS_TX_RING_BUFFER_ID);
    (void)RB_Init(GPS_RX_RING_BUFFER_ID);
    (void)Uart_Init(UART_ID_GPS);
    (void)Uart_Open(UART_ID_GPS);
    GPS_DataInit();
//    GPS_TriggerTransmit(CMD_PDTINFO);
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GPS_UartTransmitCallback(Uart_Id_t id, uint8_t *data, uint8_t *length)
{
   RB_Return_t ret;

   CDD_TEST_ENTER_CRITICAL();
   ret = RB_Pop(GPS_TX_RING_BUFFER_ID, data, *length);
   CDD_TEST_EXIT_CRITICAL();
   
   if(ret > RB_SUCCESS)
   {
       *length = (uint8_t)ret;
   }
   else
   {
       *length = 0u; 
   }
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GPS_UartTransmitFinishCallback(Uart_Id_t id, uint8_t *data, uint8_t *length)
{
    RB_Return_t ret = RB_Pop(GPS_TX_RING_BUFFER_ID, data, *length);
    if(ret > RB_SUCCESS)
    {
        *length = (uint8_t)ret;
    }
    else
    {
        *length = 0u;
        bUartStatus = FALSE;
    }
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/

void GPS_UartRxCallback(Uart_Id_t id, uint8 ch)
{
    RB_Return_t ret = 0;
    ret = RB_Push(GPS_RX_RING_BUFFER_ID, &ch, 1);

}

static void GPS_GPGGACommand(const  char *Buffer, uint16 len )
{
    char Parameter[11] = {0};
    const char * pcParameter;
    uint16 lParameterStringLength=0;
    
    pcParameter = GPS_CLIGetParameter
                            (
                                Buffer,
                                7,
                                &lParameterStringLength
                            );
    if ((lParameterStringLength >=10)||(lParameterStringLength == 0))
    {
        return;
    }
    (void)memcpy(Parameter,pcParameter,lParameterStringLength);
    if (IsDigitStr(Parameter,(sint32)lParameterStringLength))
    {
        GPGGA_NoSV = atoi((const char *)Parameter);
    }
}

static void GPS_UnicoreAnalysis(const char * pcCommandString,uint16_t len)
{
    uint16 i;
    if (pcCommandString[0] != '$')
    {
        return;
    }

    for (i=0; i<GPS_MSG_DEF_NUMBER; i++)
    {
        if (strncmp(&pcCommandString[3],GPS_CMD_Table[i].CmdName,strlen(GPS_CMD_Table[i].CmdName))==0)
        {
            
            if (GPS_GetNumberOfParameters(pcCommandString) != GPS_CMD_Table[i].ParametersNamble)
            {
                break;
            }
        
            if (GPS_CMD_Table[i].callback == NULL_PTR)
            {
                break;
            }

            GPS_CMD_Table[i].callback(pcCommandString,len);
        }
    }
}

static int8_t GPS_GetNumberOfParameters( const char *pcCommandString )
{
    int8_t cParameters = 0;
    uint16 xLastCharacterWasSpace = 0;

	/* Count the number of space delimited words in pcCommandString. */
	while( *pcCommandString != 0x00 )
	{
		if( ( *pcCommandString ) == ',' )
		{
			if( xLastCharacterWasSpace != TRUE )
			{
				cParameters++;
				xLastCharacterWasSpace = 0;
			}
		}
		else
		{
			xLastCharacterWasSpace = 0;
		}

		pcCommandString++;
	}

	/* If the command string ended with spaces, then there will have been too
	many parameters counted. */
	if( xLastCharacterWasSpace == TRUE )
	{
		cParameters--;
	}

	/* The value returned is one less than the number of space delimited words,
	as the first word should be the command itself. */
	return cParameters;
}

const char *GPS_CLIGetParameter( const char *pcCommandString, uint16 uxWantedParameter, uint16 *pxParameterStringLength )
{
uint16 uxParametersFound = 0;
const char *pcReturn = NULL_PTR;

	*pxParameterStringLength = 0;

	while( uxParametersFound < uxWantedParameter )
	{
		/* Index the character pointer past the current word.  If this is the start
		of the command string then the first word is the command itself. */
		while( ( ( *pcCommandString ) != 0x00 ) && ( ( *pcCommandString ) != ',' ) )
		{
			pcCommandString++;
		}

		/* Find the start of the next string. */
//		while( ( ( *pcCommandString ) != 0x00 ) && ( ( *pcCommandString ) == ',' ) )
		{
			pcCommandString++;
		}
        

		/* Was a string found? */
		if( *pcCommandString != 0x00 )
		{
			/* Is this the start of the required parameter? */
			uxParametersFound++;

			if( uxParametersFound == uxWantedParameter )
			{
				/* How long is the parameter? */
				pcReturn = pcCommandString;
				while( ( ( *pcCommandString ) != 0x00 ) && ( ( *pcCommandString ) != ',' ) )
				{
					( *pxParameterStringLength )++;
					pcCommandString++;
				}

				if( *pxParameterStringLength == 0 )
				{
					pcReturn = NULL_PTR;
				}

				break;
			}
		}
		else
		{
			break;
		}
	}

	return pcReturn;
}


/***********************************************************************
 * @brief       : MSG
 *                $MSGNAME,data1,data2,data3,…[*CC]\r\n
 * @param       : 
 * @retval      : 
 ***********************************************************************/
// uint8 cfg = 0;
void GPS_MainFunction(void)
{
    char ch;

    

    while(RB_Pop(GPS_RX_RING_BUFFER_ID,&ch,1)>0)
    {
        if (ch == '\r')
        {
            
        }
        else if (ch == '\n')
        {
            if (GPS_BufferState != MSG_STATE_LENGTH_ERROR)
            {
                
                GPS_UnicoreAnalysis(GPS_Buffer,GPS_BufferCnt);

            }
            GPS_DataInit();
        }
        else
        {
            if (GPS_BufferCnt < MSG_MAX_SIZE)
            {
                GPS_Buffer[GPS_BufferCnt++] = ch;
            }
            else
            {
                GPS_BufferState = MSG_STATE_LENGTH_ERROR;
            }
            
        }
    }

}

void GPS_GetGPSSatelliteCount(uint16 *cnt)
{
    *cnt = GPGGA_NoSV;
}


void GPS_TriggerTransmit(uint8 * buffer)
{
    (void)RB_Push(GPS_TX_RING_BUFFER_ID, buffer,strlen(buffer));
    (void)Uart_TriggerTransmit(UART_ID_GPS);
    
}

void GPS_ReadPDTINFO(void)
{
    GPS_TriggerTransmit(CMD_PDTINFO);
}