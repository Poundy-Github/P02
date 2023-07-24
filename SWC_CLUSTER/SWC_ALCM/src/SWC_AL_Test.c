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

#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_AL_Interface.h"

#define Common_GateWay_START_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"

static uint16 count = 0;

#define Common_GateWay_STOP_SEC_VAR_INIT_UNSPECIFIED
#include  "Common_Gateway_MemMap.h"


#define Common_GateWay_START_SEC_CODE
#include  "Common_Gateway_MemMap.h"

void ALCM_TestCase1(void)
{
	count++;
	
	switch(count)
	{
		case 5:
			ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_LOW);
			break;
		case 10:
			ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_MID);
			break;
		case 15:
			ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_HIGH);
			break;
		case 20:
			ALCM_EventSet(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
			break;
		case 25:
			ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_UP);
			break;
		case 30:
			ALCM_EventSet(LINKAGE_EVENT_DRVTEMP_DOWN);
			break;	
		case 35:
			ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_UP);
			break;
		case 40:
			ALCM_EventSet(LINKAGE_EVENT_PASSTTEMP_DOWN);
			break;			
		case 45:
			ALCM_EventSet(LINKAGE_EVENT_TBD_TURN_LEFT);
			break;
		case 50:
			ALCM_EventSet(LINKAGE_EVENT_TBD_TURN_RIGHT);
			break;	
		case 60:
			ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_DRIVE);
			break;
		case 70:
			ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_PASSENGER);
			break;
		case 80:
			ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_LR);
			break;
		case 90:
			ALCM_EventSet(LINKAGE_EVENT_DOOR_OPEN_RR);
			break;	
		case 150:
			ALCM_EventSet(LINKAGE_EVENT_DOW_RIGHT);
			break;
		case 160:
			ALCM_EventSet(LINKAGE_EVENT_DOW_LEFT);
			break;		
		case 180:
			ALCM_EventSet(LINKAGE_EVENT_LCA_LEFT);
			break;
		case 190:
			ALCM_EventSet(LINKAGE_EVENT_LCA_RIGHT);
			break;
		case 210:
			ALCM_EventSet(LINKAGE_EVENT_FCT);
			break;	
		case 240:
			ALCM_EventSet(LINKAGE_EVENT_FCW);
			break;	
		case 270:
			ALCM_EventSet(LINKAGE_EVENT_AEB);
			break;
		case 300:
			ALCM_EventClr(LINKAGE_EVENT_AEB);
			break;			
		case 310:
			ALCM_EventClr(LINKAGE_EVENT_FCW);
			break;
		case 320:
			ALCM_EventClr(LINKAGE_EVENT_FCT);
			break;			
		case 330:
			ALCM_EventClr(LINKAGE_EVENT_LCA_LEFT);
			break;
		case 335:
			ALCM_EventClr(LINKAGE_EVENT_LCA_RIGHT);
			break;			
		case 340:
			ALCM_EventClr(LINKAGE_EVENT_DOW_RIGHT);
			break;
		case 345:
			ALCM_EventClr(LINKAGE_EVENT_DOW_LEFT);
			break;
		case 350:
			ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_DRIVE);
			break;
		case 360:
			ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_PASSENGER);
			break;
		case 370:
			ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_LR);
			break;
		case 380:
			ALCM_EventClr(LINKAGE_EVENT_DOOR_OPEN_RR);
			break;
		case 480:
			ALCM_EventClr(LINKAGE_EVENT_TBD_TURN_LEFT);
			break;
		case 510:
			ALCM_EventClr(LINKAGE_EVENT_DRVTEMP_DOWN);
			break;
		case 540:
			ALCM_EventClr(LINKAGE_EVENT_PM25_POLLUTION_SERIOUS);
			break;		
		default:
			break;
	}
}


void ALCM_TestCase2(void)
{

}

void ALCM_TestCase3(void)
{

}

#define Common_GateWay_STOP_SEC_CODE
#include  "Common_Gateway_MemMap.h"

