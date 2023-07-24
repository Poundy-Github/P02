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
/**********************************************************************************************************
*File Name   : SWC_TC_Rte_Adapt.c                                                                             *
*                                                                                                         *
*Description : TripComputer module adaptation interface source file.                                        *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/
/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef TC_ADAPT_H
#define TC_ADAPT_C

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "string.h"
#include "Rte_Common_Normal.h"
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_TC_Rte_Adapt.h"
#include "SWC_TC_Process.h"
#include "SWC_Odo_Interface.h"
#include "CConfig_Cfg.h"

#if  (defined(SWC_TC_ADAPT_B03))
//#include "ComEx_Cfg.h.h"
#elif (defined(SWC_TC_ADAPT_B02))
#include "ComEx_Cfg.h"
#elif (defined(SWC_TC_ADAPT_B06))
// #include "ComEx_Cfg.h"
#elif (defined(SWC_TC_ADAPT_P03))
#include "ComEx_Cfg.h"
#elif (defined(SWC_TC_ADAPT_P05))
#include "ComEx_Cfg.h"
#elif (defined(SWC_TC_ADAPT_A07))
 #include "ComEx_Cfg.h"
 #elif (defined(SWC_TC_ADAPT_D01))
 #include "ComEx_Cfg.h"
 #elif (defined(SWC_TC_ADAPT_D02))
 #include "ComEx_Cfg.h"
 #elif (defined(SWC_TC_ADAPT_D03))
 #include "ComEx_Cfg.h"
 #elif (defined(SWC_TC_ADAPT_P02))
 #include "ComEx_Cfg.h"
 #elif (defined(SWC_TC_ADAPT_P01))
#include "ComEx_Cfg.h"
#else
#endif


/**********************************************************************************************************
*																										  *
*																										  *
*				  Type Definition																		  *
*																										  *
*																										  *
**********************************************************************************************************/
#define SWC_TC_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

static TC_OSTIMER_DATA_STRUCT TC_Os_Timer_Tbl[TC_OS_TimerMax] = {0};
static Std_ReturnType TC_FUEL_Muti_Err_Status = FALSE;
static st_TcConfiguration st_TcRteConfiguration = {0xFF};


#define SWC_TC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************
*																										  *
*																										  *
*				              Macro																		  *
*																										  *
*																										  *
**********************************************************************************************************/

#define SWC_TC_START_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
uint8 TC_RTE_API_Get_Fuel_Consumption_Counter(void);
void TC_Api_RTE_CanOutputViaGateway_IP_AvgFuelCons(uint16 data);
void TC_Api_RTE_CanOutputViaGateway_IP_InstFuelConsUnit(uint8 data);
void TC_Api_RTE_CanOutputViaGateway_IP_RemainDistance(uint16 data);
void TC_Api_RTE_CanOutputViaGateway_IP_AuxRemainDistance(uint16 data);
void TC_Api_RTE_CanOutputViaGateway_IP_InstFuelCons(uint16 data);

/**********************************************************************************************************
*Function   : TC_Rte_Api_Get_Vehicle_Type_Cfg                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-19                                                                                  *
**********************************************************************************************************/
TC_VEHICLE_TYPE_ENUM TC_Rte_Api_Get_Vehicle_Type_Cfg(void)
{

    uint8 VconfigKind_600Bytes_temp[sizeof(VconfigKind_Allbuffers)];
	uint8 tc_vehicle_cfg_temp = 0;
//	uint8 *configAdr;
	TC_VEHICLE_TYPE_ENUM tc_vehicle_cfg=TC_VEHICLE_NONE;
#ifdef Rte_Read_Vconfig_GetKindBuffers_AllKinds 
    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds (VconfigKind_600Bytes_temp);
	if(0 != VconfigKind_600Bytes_temp[VCONFIG_KIND_INIT_FLAG])
	{
		tc_vehicle_cfg_temp = VconfigKind_600Bytes_temp[VCONFIG_KIND_FUEL];
	}
	if((1 == tc_vehicle_cfg_temp) || (2 == tc_vehicle_cfg_temp) || (7 == tc_vehicle_cfg_temp))
	{
	/*
    F1B1 : Byte2
    001     gasoline
    0010    gasoline+ natural gas
    0111    natural gas
    */
		tc_vehicle_cfg = TC_VEHICLE_FUEL;
	}
	else if((0 == tc_vehicle_cfg_temp))
	{
	/*
	F1B1 : Byte2
	0000	diesel
	*/
		tc_vehicle_cfg = TC_VEHICLE_FUEL_DIESEL;
	}
	else if(3 == tc_vehicle_cfg_temp)

	{
	/*
    F1B1 : Byte2
    0011    hev
    */
		tc_vehicle_cfg =TC_VEHICLE_HEV;
	}
    else if(4 == tc_vehicle_cfg_temp)
    {
    /*
    F1B1 : Byte2
    0100    phev
    */
        tc_vehicle_cfg = TC_VEHICLE_PHEV;

    }
	else if(5 == tc_vehicle_cfg_temp)
	{
	/*
    F1B1 : Byte2
    0101   ev
    */
		tc_vehicle_cfg = TC_VEHICLE_EV;
	}
	else
	{
		/* other vehicle type force to fuel type*/
		tc_vehicle_cfg = TC_VEHICLE_NONE;
	}
#endif
	return tc_vehicle_cfg;
}



boolean TC_Rte_Api_Get_Cconfig_Cfg(CconfigKind_400Bytes Lcal_config)
{
    boolean result=FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
    if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
	{
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
    if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
     if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
     {
         result = TRUE;
     }
     else
     {
         result = FALSE;
     }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
	  if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
	  {
		  result = TRUE;
	  }
	  else
	  {
		  result = FALSE;
	  }
#endif
#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
       if(E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(Lcal_config))
       {
           result = TRUE;
       }
       else
       {
           result = FALSE;
       }
#endif


#else

#endif
 return result;

}

/**********************************************************************************************************
*Function   : TC_Rte_Api_Get_Uint_Cfg                                                                     *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-19                                                                                  *
**********************************************************************************************************/
TC_UINT_TYPE_ENUM TC_Rte_Api_Get_Uint_Cfg(void)
{

	TC_UINT_TYPE_ENUM tc_uint_cfg = TC_UINT_KM;
#if  (defined(SWC_TC_ADAPT_B03))

#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
    MenuSetData_t configAdr;
    if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
    {
        tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
        MenuSetData_t configAdr;
        if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
        {
            tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
        }
#endif


#elif (defined(SWC_TC_ADAPT_B06))

#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
        MenuSetData_t configAdr;
        if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
        {
            tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))

#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
        MenuSetData_t configAdr;
        if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
        {
            tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
        }
#endif


#elif (defined(SWC_TC_ADAPT_P05))

#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
        MenuSetData_t configAdr;
        if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
        {
            tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
    MenuSetData_t configAdr;

    if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
    {
        tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
    MenuSetData_t configAdr;

    if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
    {
        tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
    MenuSetData_t configAdr;

    if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
    {
        tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
    MenuSetData_t configAdr;

    if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
    {
        tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
	MenuSetData_t configAdr;

	if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
	{
		tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
	}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_MenuSetData_Element
        MenuSetData_t configAdr;
    
        if(E_OK == Rte_Read_rpSR_SWCNormal_MenuSetData_Element(&configAdr))
        {
            tc_uint_cfg = (TC_UINT_TYPE_ENUM)configAdr.OdometerUnit;
        }
#endif


#else

#endif
	return (tc_uint_cfg);
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Power_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_Power_Mode_State (void)
{
    boolean result = FALSE;
    
 #if  (defined(SWC_TC_ADAPT_B03))
    SystemState_RecordType *power_u8;
    power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
    if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
    {
      if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
      {
          result = TRUE;
      }
      else
      {
          result = FALSE;
      }
    }
    else
    {
      result = FALSE;
    }

#elif (defined(SWC_TC_ADAPT_B02))

#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
    SystemState_RecordType *power_u8;
    power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
    if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
    {
         if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
             if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
             {
                 result = TRUE;
             }
             else
             {
                 result = FALSE;
             }
        }
        else
        {
            result = (uint8)FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result = TRUE;
            }
            else
            {
                result = FALSE;
            }
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
            SystemState_RecordType *power_u8;
            power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
            if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
            {
                if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
                {
                    result = TRUE;
                }
                else
                {
                    result = FALSE;
                }
            }
            else
            {
                result = FALSE;
            }
#endif


#else

#endif

    return result;
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Power_Mode_State_Is_Sleep                                                 	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-28                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_Power_Mode_State_Is_Sleep(void)
{
    boolean result=(boolean)0;
 #if  (defined(SWC_TC_ADAPT_B03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
    SystemState_RecordType *power_u8;
    power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
    if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
         SystemState_RecordType *power_u8;
         power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
         if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
         {
             result = TRUE;
         }
         else
         {
             result = FALSE;
         }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
		  SystemState_RecordType *power_u8;
		  power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
		  if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
		  {
			  result = TRUE;
		  }
		  else
		  {
			  result = FALSE;
		  }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
               SystemState_RecordType *power_u8;
               power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
               if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
               {
                   result = TRUE;
               }
               else
               {
                   result = FALSE;
               }
#endif


#else

#endif

	 return result;
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Voltage_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_Voltage_Mode_State (void)
{
    boolean result = FALSE;
 #if  (defined(SWC_TC_ADAPT_B03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
    SystemState_RecordType *voltage_u8;
    voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
    if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
       (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
       (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
		SystemState_RecordType *voltage_u8;
		voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
		if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
		   (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
		   (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
		{
			result = TRUE;
		}
		else
		{
			result = FALSE;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
 #ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *voltage_u8;
        voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state)|| \
           (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
           (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif


#else

#endif

	return ((result==TRUE)?1u:0u);
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_Error_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_Fuel_Error_State (void)
{
    boolean result = FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
    (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
    if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
    {
        result= TRUE;
    }
    else
    {
        result= FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= (uint8)FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= (uint8)FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
		FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
		(void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
		if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
		{
			result= TRUE;
		}
		else
		{
			result= FALSE;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Sensor_Error_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif


#else

#endif

	return result;
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_Finished_Init_State                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_Fuel_Finished_Init_State (void)
{
    boolean result = FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
    (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
    if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
    {
       result= TRUE;
    }
    else
    {
       result= FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
       (void) Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
        {
           result= TRUE;
        }
        else
        {
           result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
		FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
		(void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
		if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
		{
		   result= TRUE;
		}
		else
		{
		   result= FALSE;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
	    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
	    (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
	    if(FALSE != fuel_module_data_temp.Fuel_Init_Complete_Status)
	    {
	       result= TRUE;
	    }
	    else
	    {
	       result= FALSE;
	    }
#endif

#else

#endif

	return result;
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_volume                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2020-09-15                                                                                  *
**********************************************************************************************************/
uint32 TC_RTE_API_Get_Fuel_volume (void)
{
    uint32 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
    (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
    result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        result = fuel_module_data_temp.Fuel_Level_Display_Value;
#endif
#else
#endif
    return result;

}
boolean TC_RTE_API_Get_AFE_Fuel_Condition (void)
{
    boolean result=FALSE;
    boolean odoErr = FALSE;
    boolean ecmErr = FALSE;
    boolean VehStartingSts = FALSE;
    odoErr = TC_RTE_API_Get_ODO_err();
    ecmErr = TC_RTE_API_Get_ECM2_err();
    VehStartingSts=TC_RTE_API_Get_Hev_Phev_VehStartingSts();
#if  (defined(SWC_TC_ADAPT_B03))
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
       result=TRUE;
    }
    else
    {
       result=FALSE;
    }
#elif (defined(SWC_TC_ADAPT_B02))
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
       result=TRUE;
    }
    else
    {
       result=FALSE;
    }
#elif (defined(SWC_TC_ADAPT_B06))
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
       result=TRUE;
    }
    else
    {
       result=FALSE;
    }
#elif (defined(SWC_TC_ADAPT_P03))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
#elif (defined(SWC_TC_ADAPT_P05))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
#elif (defined(SWC_TC_ADAPT_A07))
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
       result=TRUE;
    }
    else
    {
       result=FALSE;
    }
#elif (defined(SWC_TC_ADAPT_D01))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
#elif (defined(SWC_TC_ADAPT_D02))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
#elif (defined(SWC_TC_ADAPT_D03))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
#elif (defined(SWC_TC_ADAPT_P02))
    if (TC_Module_Motor_Type_Data == TC_VEHICLE_MOTOR_P0)
    {
        if ((FALSE !=VehStartingSts)&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    else
    {
        if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
    }
    
#elif (defined(SWC_TC_ADAPT_P01))
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
        result=TRUE;
    }
    else
    {
        result=FALSE;
    }
#else
    if((FALSE != TC_API_Get_EngSpd_State())&&(FALSE == odoErr)&&(FALSE== ecmErr))
    {
       result=TRUE;
    }
    else
    {
       result=FALSE;
    }
#endif
    return result;

}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_VehRunning_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_VehRunning_State (void)
{
    uint8 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t vehicle_run_status;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
    result = vehicle_run_status.VehRunSts;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
		s_SpeedoInfo_t vehicle_run_status;
		(void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
		result = vehicle_run_status.VehRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.VehRunSts;
#endif

#else

#endif

	return (result);
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_VehRunning_State_Ifc                                                      	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	:Shu junhua                                                                                   *
*                                                                                                         *
*Date		: 2021-01-15                                                                                  *
**********************************************************************************************************/
uint16 TC_RTE_API_Get_VehRunning_State_Ifc (void)
{
    uint16 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t vehicle_run_status;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
    result = vehicle_run_status.RealSpeedBak;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t vehicle_run_status;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&vehicle_run_status);
        result = vehicle_run_status.RealSpeedBak;
#endif


#else

#endif
	return (result);
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_EngSpd_State                                                           	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_EngSpd_State (void)
{
    uint8 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	s_TachoInfo_t engine_run_status;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	result=engine_run_status.EngRunSts;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.EngRunSts;
#endif

#else

#endif
	return (result);
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_EngSpd_OUT_State                                                             *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Ren Feng Po                                                                                 *
*                                                                                                         *
*Date		: 2021-11-23                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_EngSpd_OUT_State (void)
{
   uint8 result=0;	
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	    s_TachoInfo_t engine_run_status;
	    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	    result=engine_run_status.TimeOutFlag;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	    s_TachoInfo_t engine_run_status;
	    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	    s_TachoInfo_t engine_run_status;
	    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	    s_TachoInfo_t engine_run_status;
	    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	    s_TachoInfo_t engine_run_status;
	    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
	s_TachoInfo_t engine_run_status;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
	result=engine_run_status.TimeOutFlag;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t engine_run_status;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&engine_run_status);
    result=engine_run_status.TimeOutFlag;
#endif

#else

#endif
	return (result);
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Fuel_FastFill_State                                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_Fuel_FastFill_State (void)
{
    boolean result = FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
    FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
    (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= (uint8)FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
            if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
            {
                result= TRUE;
            }
            else
            {
                result= FALSE;
            }
#endif
#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element
        FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE fuel_module_data_temp;
        (void)Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_module_data_temp);
        if(FALSE != fuel_module_data_temp.Fuel_Fast_Fill_Status)
        {
            result= TRUE;
        }
        else
        {
            result= FALSE;
        }
#endif

#else

#endif


	return result;
}

uint8 TC_RTE_API_Get_ODO_Count (void)
{
	uint8 count= Odo_Api_RunCounter_Get();
	return (count);
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_trip_value                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                *
*                                                                                                         *
*Date		: 2020-09-17                                                                                  *
**********************************************************************************************************/

uint32 TC_RTE_API_Get_trip_value (uint8 index)
{
    uint32 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
    {
        result =Odo_Parament.TripKmValue_u32[index];
    }
    else
    {
        result =Odo_Parament.TripMileValue_u32[index];
    }
#endif


#else

#endif
    return result ;
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_ODO_Condition                                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_API_Get_ODO_err (void)
{
    uint8 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.OdoInputlValid;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        result=Odo_Parament.OdoInputlValid;
#endif

#else

#endif

    return (result==1u)?TRUE:FALSE;

}

boolean TC_RTE_API_Get_ECM2_err (void)
{
	uint8 can_node_status = 0;
    boolean result = FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_FuelConsumption_FuelConsumption
    uint16 fuelConsumption_value=0;
    can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
    if(((can_node_status&RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&&\
    ((can_node_status&RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED)&&\
    ((can_node_status&RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
    {
        result= FALSE;
    }
    else
    {
        result= TRUE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        FuelConsumption  FuelConsumption_temp=0;
        can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
        (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,sizeof (FuelConsumption));

        //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
       if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result= FALSE;
        }
        else
        {
            result= TRUE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))

#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
                FuelConsumption  FuelConsumption_temp=0;
                can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
                (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,sizeof (FuelConsumption));

                //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
               if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
                {
                    result= FALSE;
                }
                else
                {
                    result= TRUE;
                }
#endif

#elif (defined(SWC_TC_ADAPT_P03))

#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
                FuelConsumption  FuelConsumption_temp=0;
                can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
                (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,sizeof (FuelConsumption));

                //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
               if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
                {
                    result= FALSE;
                }
                else
                {
                    result= TRUE;
                }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
                FuelConsumption  FuelConsumption_temp=0;
                can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
                (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,(uint8)sizeof(FuelConsumption));

                //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
               if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
                {
                    result= FALSE;
                }
                else
                {
                    result= TRUE;
                }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            FuelConsumption  FuelConsumption_temp=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
            (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,(uint8)sizeof (FuelConsumption));

            //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
           if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                result= FALSE;
            }
            else
            {
                result= TRUE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            FuelConsumption  FuelConsumption_temp=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
            (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,(uint8)sizeof (FuelConsumption));

            //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
           if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                result= FALSE;
            }
            else
            {
                result= TRUE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            FuelConsumption  FuelConsumption_temp=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
            (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,(uint8)sizeof (FuelConsumption));

            //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
           if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                result= FALSE;
            }
            else
            {
                result= TRUE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            FuelConsumption  FuelConsumption_temp=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
            (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,(uint8)sizeof (FuelConsumption));

            //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
           if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                result= FALSE;
            }
            else
            {
                result= TRUE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
		FuelConsumption  FuelConsumption_temp=0;
		can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
		(COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,sizeof (FuelConsumption));

		//can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
	   if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
	((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
	((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
		{
			result= FALSE;
		}
		else
		{
			result= TRUE;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        FuelConsumption  FuelConsumption_temp=0;
        can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal \
        (COMEX_SIGNAL_RX_FUELCONSUMPTION,&FuelConsumption_temp,sizeof (FuelConsumption));

        //can_node_status = Rte_Read_FuelConsumption_FuelConsumption(&fuelConsumption_value);
       if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result= FALSE;
        }
        else
        {
            result= TRUE;
        }
#endif

#else

#endif




	return result;
}

boolean TC_RTE_API_Get_ODO_Condition (void)
{
    boolean odo_err_temp=FALSE;
    if (TC_RTE_API_Get_ODO_err())
    {
        odo_err_temp= FALSE;
    }
    else
    {
        odo_err_temp= TRUE;
    }
    return (odo_err_temp);
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_ODO_Count                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_API_Get_Fuel_Consumption_Counter(void)
{
	uint8 result=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    result=Odo_Parament.RunCounter_u8;
#endif

#else

#endif


	return result;
}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_TC_Module_Output_Data                                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void TC_RTE_API_Get_TC_Module_Output_Data (TC_MODULE_OUTPUT_DATA_STRUCT tc_module_output_data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef  Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element
        (void)Rte_Write_ppSR_SWCNormal_TC_Module_Output_Data_Element(&tc_module_output_data);
#endif

#else

#endif

}
/**********************************************************************************************************
*Function   : TC_RTE_API_Set_TC_Module_Reset_Data                                                         *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void TC_RTE_API_Set_TC_Module_Reset_Data (uint8 tc_reset_index)
{
    uint8 u8temp = tc_reset_index;
    TC_MODULE_RESET_DATA_INDEX  enTc_reset_index = (TC_MODULE_RESET_DATA_INDEX)u8temp;
    (void)TC_API_Set_TC_Module_Reset_Data(enTc_reset_index);
}
/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerStart                                                                       *
*                                                                                                         *
*Description: system timer start                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;   Over_u16: Over time                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_OstmTimerStart(uint8 Index_u8)
{
    boolean status = FALSE;
    Std_ReturnType ret = RTE_E_Os_Service_E_OK;  
    ret = Rte_Call_Os_Service_GetCounterValue(&TC_Os_Timer_Tbl[Index_u8].u32TC_StartTime);
    if(RTE_E_Os_Service_E_OK == ret)
    {
        TC_Os_Timer_Tbl[Index_u8].u8TC_TimeStatus = TC_OSTM_TIMER_RUNING;
        status = TRUE;
    }
    else
    {
        TC_Os_Timer_Tbl[Index_u8].u8TC_TimeStatus = TC_OSTM_TIMER_CLEAR;
        status = FALSE;
    }
    return status;
}
/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerCheck                                                                       *
*                                                                                                         *
*Description: system timer check                                                                          *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : uint8:Timer check status                                                                    *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
uint8 TC_RTE_OstmTimerCheck(uint8 Index_u8,uint32 over_time_base)
{
	uint8 status;
	uint8 os_sts;
	uint32 passtime;
	uint32 starttime;
	if(TC_OSTM_TIMER_CLEAR == TC_Os_Timer_Tbl[Index_u8].u8TC_TimeStatus)
	{
		status = TC_OSTM_TIMER_CLEAR;
	}
	else
	{
		starttime = TC_Os_Timer_Tbl[Index_u8].u32TC_StartTime;
		os_sts = Rte_Call_Os_Service_GetElapsedValue(&starttime,&passtime);
		if(RTE_E_Os_Service_E_OK == os_sts)
		{
			if(passtime >= over_time_base)
			{
				status = TC_OSTM_TIMER_OVER;
			}
			else
			{
				status = TC_OSTM_TIMER_RUNING;
			}
		}
		else
		{
			status = TC_OSTM_TIMER_RUNING;
		}
	}
	return status;
}
/**********************************************************************************************************
*Function   : TC_RTE_OstmTimerStop                                                                        *
*                                                                                                         *
*Description: system timer stop                                                                           *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
void TC_RTE_OstmTimerStop(uint8 Index_u8)
{
	TC_Os_Timer_Tbl[Index_u8].u8TC_TimeStatus = TC_OSTM_TIMER_CLEAR;
}
/**********************************************************************************************************
*Function   : TC_RTE_Get_OstmTimerValue                                                                   *
*                                                                                                         *
*Description: system timer stop                                                                           *
*                                                                                                         *
*Parameter  : Index_u8:timer index;                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-06-12                                                                                  *
**********************************************************************************************************/
boolean TC_RTE_Get_OstmTimerValue(uint8 Index_u8 , uint32 *TC_ElapseTime)
{
	boolean status = FALSE;
	uint8 os_sts;
	uint32 passtime;
	uint32 starttime;

	if(TC_OSTM_TIMER_CLEAR == TC_Os_Timer_Tbl[Index_u8].u8TC_TimeStatus)
	{
		status = FALSE;
	}
	else
	{
		starttime = TC_Os_Timer_Tbl[Index_u8].u32TC_StartTime;
		os_sts = Rte_Call_Os_Service_GetElapsedValue(&starttime,&passtime);
		if(RTE_E_Os_Service_E_OK == os_sts)
		{
			TC_Os_Timer_Tbl[Index_u8].u32TC_StartTime = starttime;
			*TC_ElapseTime = passtime;
			status = TRUE;
		}
		else
		{
			status = FALSE;
		}
	}
	return status;
}



TC_FUEL_COMSUME_DATA_STRUCT TC_RTE_Get_FuelConsMsgValue(void)
{
	TC_FUEL_COMSUME_DATA_STRUCT fuelConsumption_value_raw = {0};
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
    CanFrameCounterType  fuelConsumption_value;
    if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
    {
        /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
        fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
        fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
    }
    else
    {
        /* means ECM2 missing or never received */
        fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
		CanFrameCounterType  fuelConsumption_value;
		if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
		{
			/* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
			fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
			fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
		}
		else
		{
			/* means ECM2 missing or never received */
			fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_CanFrameCounter_Can_ECM2_Counter
        CanFrameCounterType  fuelConsumption_value;
        if(E_OK == Rte_Call_CanFrameCounter_Can_ECM2_Counter(&fuelConsumption_value))
        {
            /* uint: ul  max: 0xFFFF*2 = 0x1FFFE*/
            fuelConsumption_value_raw.u32_fuel_consume_value = (uint32)fuelConsumption_value.Data * 2;
            fuelConsumption_value_raw.u16_fuel_consume_rc =fuelConsumption_value.Counter;
        }
        else
        {
            /* means ECM2 missing or never received */
            fuelConsumption_value_raw.u32_fuel_consume_value = 0xFFFFFFFF;
        }
#endif


#else

#endif
	return fuelConsumption_value_raw;

}

void TC_Api_RTE_CanOutputViaGateway_IP_AvgFuelCons(uint16 data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_AvgFuelCons((uint16)data);
#endif

#else

#endif


}

void TC_Api_RTE_CanOutputViaGateway_IP_InstFuelConsUnit(uint8 data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
     (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
         (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit
             (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
#endif

#else

#endif


}

void TC_Api_RTE_CanOutputViaGateway_IP_InstFuelCons(uint16 data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
#endif

#else

#endif

}


void TC_Api_RTE_CanOutputViaGateway_IP_RemainDistance(uint16 data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_RemainDistance((uint16)data);
#endif

#else

#endif


}

void TC_Api_RTE_CanOutputViaGateway_IP_AuxRemainDistance(uint16 data)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_AuxRemainDistance
#endif

#else

#endif


}


void TC_Api_Update_can_publish(TC_IP_PUBLISH_ENUM type,uint32 data)
{
    switch (type)
    	{
		case TC_IP_AvgFuelCons_A:
			 TC_Api_RTE_CanOutputViaGateway_IP_AvgFuelCons((uint16)data); /*Adjust the call interface to decouple*/
			 break;
		case TC_IP_AvgFuelCons_B:
			 break;
		case TC_IP_InstFuelConsUnit:
             TC_Api_RTE_CanOutputViaGateway_IP_InstFuelConsUnit((uint8)data);
			 break;
		case TC_IP_InstFuelCons:
			 TC_Api_RTE_CanOutputViaGateway_IP_InstFuelCons((uint16)data);
             break;
		case TC_IP_RemainDistance:
	         TC_Api_RTE_CanOutputViaGateway_IP_RemainDistance((uint16)data);
             break;
        case TC_IP_AuxRemainDistance:
             TC_Api_RTE_CanOutputViaGateway_IP_AuxRemainDistance((uint16) data);
             break;
		default :
            //do nothing
            break;
    	}
}

/**********************************************************************************************************
*Function   : TC_API_RTE_Diag_Read_TC_Data                                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-04                                                                                  *
**********************************************************************************************************/
void TC_API_RTE_Diag_Read_TC_Data(uint8 * data)
{
	TC_API_Set_Diag_Read_TC_Data(data);
}

/**********************************************************************************************************
*Function   : TC_Module_Rte_Coldinit_Warminit_Flag                                                  	  *
*                                                                                                         *
*Description:                                                                                             *
Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-17                                                                                  *
**********************************************************************************************************/
boolean TC_Module_Rte_Coldinit_Warminit_Flag (void)
{
	boolean warn_flag = FALSE;
    boolean result = FALSE;

#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
    if(FALSE != warn_flag)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag);
        if(FALSE != warn_flag)
        {
            result = TRUE;
        }
        else
        {
            result = FALSE;
        }
#endif

#else

#endif
    return result;

}



TC_Phev_Egy_DATA_t TC_Api_Rte_Get_Hcu_EgyUsed_MsgValue(void)
{
	TC_Phev_Egy_DATA_t  Egy_MsgValue = {0};
	TC_Phev_Egy_DATA_t  Egy_MsgValue_result = {0};
    uint8 can_node_status=0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_HCU_EgyUsed_HCU_EgyUsed
    can_node_status=Rte_Read_HCU_EgyUsed_HCU_EgyUsed(&Egy_MsgValue.tc_Egyued);
    if(((can_node_status&RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&&\
    ((can_node_status&RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED)&&\
    ((can_node_status&RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
    {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

    }
    else
    {
    /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
    }
#endif
#ifdef Rte_Read_HCU_RecupPwr_HCU_RecupPwr
    can_node_status=Rte_Read_HCU_RecupPwr_HCU_RecupPwr(&Egy_MsgValue.tc_RecupPwr);
    if(((can_node_status&RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&&\
    ((can_node_status&RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED)&&\
    ((can_node_status&RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
    {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

    }
    else
    {
    /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
    }
#endif

#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
    sizeof(HCU_EgyUsed));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
    Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

    }
    else
    {
    /* means ECM2 missing or never received */
    Egy_MsgValue_result.tc_Egyued =   0xFFFF;
    }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,\
    sizeof(HCU_RecupPwr));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
    Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

    }
    else
    {
    /* means ECM2 missing or never received */
    Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
      can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
uint16 HCU_RecupPwr_u16 = 0;

#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        #ifdef COMEX_SIGNAL_RX_HCU_EGYUSED
        uint16 HCU_EgyUsed = 0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        (uint8)sizeof(HCU_EgyUsed));
        #endif
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
//        uint16 HCU_RecupPwr = 0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        (uint8)sizeof(HCU_RecupPwr_u16));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        //(uint8)sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        //(uint8)sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        (uint8)sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        (uint8)sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        (uint8)sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        (uint8)sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        (uint8)sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        (uint8)sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
		can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
		(uint8)sizeof(HCU_EgyUsed));
		if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
		((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
		((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
		{
		Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

		}
		else
		{
		/* means ECM2 missing or never received */
		Egy_MsgValue_result.tc_Egyued =   0xFFFF;
		}
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
				can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
				sizeof(HCU_RecupPwr));
				if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
				((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
				((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
				{
				Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;
		
				}
				else
				{
				/* means ECM2 missing or never received */
				Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
				}
#endif


#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EGYUSED,&Egy_MsgValue.tc_Egyued,
        (uint8)sizeof(HCU_EgyUsed));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_Egyued = Egy_MsgValue.tc_Egyued;

        }
        else
        {
        /* means ECM2 missing or never received */
        Egy_MsgValue_result.tc_Egyued =   0xFFFF;
        }
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RECUPPWR,&Egy_MsgValue.tc_RecupPwr,
        (uint8)sizeof(HCU_RecupPwr));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
        Egy_MsgValue_result.tc_RecupPwr = Egy_MsgValue.tc_RecupPwr;
        }
        else
        {
        Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
        }
#endif

#else
    Egy_MsgValue_result.tc_Egyued =   0xFFFF;
    Egy_MsgValue_result.tc_RecupPwr = 0xFFFF;
#endif

    return Egy_MsgValue_result;

}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Hev_Phev_VehStartingSts                                                      *
*                                                                                                         *
*Description:                                                                                             *
HEV/PHEV vehicle running status                                                                           *
0:The HEV /PHEV vehicle did not start                                                                     *
1:HEV /PHEV vehicle starts	                                                                              *                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                *
*                                                                                                         *
*Date		: 2020-12-1                                                                                  *
**********************************************************************************************************/

boolean TC_RTE_API_Get_Hev_Phev_VehStartingSts (void)
{
    boolean  VehStartingSts = FALSE;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_SG_HCU_PT7_SG_HCU_PT7
    boolean  HCU_RdyLmpSts_b = (boolean)0;
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    HCU_RdyLmpSts_b = SG_HCU_PT7_Tmp.HCU_RdyLmpSts;
    if (Rte_ReturnSts ==RTE_E_OK)
    {
        if(1==HCU_RdyLmpSts_b)
        {
            VehStartingSts = TRUE;
        }
        else
        {
            VehStartingSts = FALSE;
        }
    }
    else
    {
        VehStartingSts = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        if(1==HCU_RdyLmpSts_temp)
        {
            VehStartingSts = TRUE;
        }
        else
        {
            VehStartingSts = FALSE;
        }
    }
    else
    {
        VehStartingSts = FALSE;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
        uint8 can_node_status=0;
        can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
        (HCU_RdyLmpSts)) ;
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            if(1==HCU_RdyLmpSts_temp)
            {
                VehStartingSts = TRUE;
            }
            else
            {
                VehStartingSts = FALSE;
            }
        }
        else
        {
            VehStartingSts = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        Std_ReturnType  HCU_RdyLmpSts_temp = 0;
        uint8 can_node_status=0;
         can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof(HCU_RdyLmpSts))  ;
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            if(1==HCU_RdyLmpSts_temp)
            {
                VehStartingSts = TRUE;
            }
            else
            {
                VehStartingSts = FALSE;
            }
        }
        else
        {
            VehStartingSts = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        Std_ReturnType  HCU_RdyLmpSts_temp = 0;
        uint8 can_node_status=0;
        can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,(uint8)sizeof(uint8));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            if(1==HCU_RdyLmpSts_temp)
            {
                VehStartingSts = TRUE;
            }
            else
            {
                VehStartingSts = FALSE;
            }
        }
        else
        {
            VehStartingSts = FALSE;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            HCU_RdyLmpSts  HCU_RdyLmpSts_temp = (boolean)0;
            uint8 can_node_status=0;
            can_node_status = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,(uint8)sizeof
            //(HCU_RdyLmpSts)) ;
            if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                if(1==HCU_RdyLmpSts_temp)
                {
                    VehStartingSts = TRUE;
                }
                else
                {
                    VehStartingSts = FALSE;
                }
            }
            else
            {
                VehStartingSts = FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
            uint8 can_node_status=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
            (HCU_RdyLmpSts)) ;
            if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                if(1==HCU_RdyLmpSts_temp)
                {
                    VehStartingSts = TRUE;
                }
                else
                {
                    VehStartingSts = FALSE;
                }
            }
            else
            {
                VehStartingSts = FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
            uint8 can_node_status=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
            (HCU_RdyLmpSts)) ;
            if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                if(1==HCU_RdyLmpSts_temp)
                {
                    VehStartingSts = TRUE;
                }
                else
                {
                    VehStartingSts = FALSE;
                }
            }
            else
            {
                VehStartingSts = FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
            HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
            uint8 can_node_status=0;
            can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
            (HCU_RdyLmpSts)) ;
            if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
            {
                if(1==HCU_RdyLmpSts_temp)
                {
                    VehStartingSts = TRUE;
                }
                else
                {
                    VehStartingSts = FALSE;
                }
            }
            else
            {
                VehStartingSts = FALSE;
            }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
		HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
		uint8 can_node_status=0;
		can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
		(HCU_RdyLmpSts)) ;
		if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
		((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
		((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
		{
			if(1==HCU_RdyLmpSts_temp)
			{
				VehStartingSts = TRUE;
			}
			else
			{
				VehStartingSts = FALSE;
			}
		}
		else
		{
			VehStartingSts = FALSE;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
        uint8 can_node_status=0;
        can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
        (HCU_RdyLmpSts)) ;
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            if(1==HCU_RdyLmpSts_temp)
            {
                VehStartingSts = TRUE;
            }
            else
            {
                VehStartingSts = FALSE;
            }
        }
        else
        {
            VehStartingSts = FALSE;
        }
#endif

#else

#endif


    return VehStartingSts;
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out                                                      *
*                                                                                                         *
*Description:                                                                                             *
HEV/PHEV vehicle running status                                                                           *
0:The HEV /PHEV vehicle did not start                                                                     *
1:HEV /PHEV vehicle starts	                                                                              *                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Ren Feng Po                                                                                *
*                                                                                                         *
*Date		: 2022-1-13                                                                                  *
**********************************************************************************************************/

uint8 TC_RTE_API_Get_Hev_Phev_VehStartingSts_Out (void)
{
    uint8  VehStartingSts_out = 0;
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Read_SG_HCU_PT7_SG_HCU_PT7
    boolean  HCU_RdyLmpSts_b = (boolean)0;
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    HCU_RdyLmpSts_b = SG_HCU_PT7_Tmp.HCU_RdyLmpSts;
    if (Rte_ReturnSts ==RTE_E_OK)
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
       VehStartingSts_out = 1;
    }
    else
    {
       VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    Std_ReturnType  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
     can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof(HCU_RdyLmpSts))  ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    Std_ReturnType  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,(uint8)sizeof(uint8));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = (boolean)0;
    uint8 can_node_status=0;
    can_node_status = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,(uint8)sizeof
    //(HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
	HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
	uint8 can_node_status=0;
	can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
	(HCU_RdyLmpSts)) ;
	if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
	((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
	((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
	{
	    VehStartingSts_out = 1;
	}
	else
	{
		VehStartingSts_out = 0;
	}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_RdyLmpSts  HCU_RdyLmpSts_temp = 0;
    uint8 can_node_status=0;
    can_node_status =Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal (COMEX_SIGNAL_RX_HCU_RDYLMPSTS,&HCU_RdyLmpSts_temp,sizeof
    (HCU_RdyLmpSts)) ;
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        VehStartingSts_out = 1;
    }
    else
    {
        VehStartingSts_out = 0;
    }
#endif

#else

#endif
    return VehStartingSts_out;
}

TC_VEHICLE_MOTOR_TYPE_ENUM TC_Rte_Api_Get_Motor_Cfg(void)
{
    TC_VEHICLE_MOTOR_TYPE_ENUM tc_moto_cfg_temp = TC_VEHICLE_MOTOR_NONE;

#ifdef Rte_Read_Vconfig_GetKindBuffers_AllKinds
    VconfigKind_Allbuffers configAdr;

    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdr);
    if(0 != configAdr[VCONFIG_KIND_INIT_FLAG])
    {
        tc_moto_cfg_temp =(TC_VEHICLE_MOTOR_TYPE_ENUM)configAdr[VCONFIG_KIND_ELECTROMOTOR_POSITION];
    }
#endif

	return tc_moto_cfg_temp;
}


/**********************************************************************************************************
*Function   : TC_RTE_API_Get_HCU_Node_Status                                                  	          *
*                                                                                                         *
*Description:  PHEV DTE Single handle                                                                     *
*                                                                                                         *
Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: PHEV DTE value and valid                                                                    *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-03-06  adapt SRS V2.0 For B02/B02/B06/P03                                              *
**********************************************************************************************************/

TC_DTE_PHEV_DATA_STRUCT TC_RTE_API_Get_HCU_Node_Status (void)
{
	Std_ReturnType  can_node_status = 0;
    TC_DTE_PHEV_DATA_STRUCT HCU_EVContnsDistance_Temp={FALSE,0,0};
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
#endif
#ifdef Rte_Read_HCU_EVContnsDistance_HCU_EVContnsDistance
    can_node_status = Rte_Read_HCU_EVContnsDistance_HCU_EVContnsDistance(&phev_dte_temp);
#endif

#ifdef Rte_Read_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld
    can_node_status = Rte_Read_HCU_EVContnsDistanceVld_HCU_EVContnsDistanceVld(&HCU_EVContnsDistance_Temp.tc_phev_dte_node_valid);
#endif
    if(((can_node_status&RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&&\
        ((can_node_status&RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED)&&\
	    ((can_node_status&RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
    {
        if(HCU_EVContnsDistance_Temp.tc_phev_dte_node_valid==1)
        {
            HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
            HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
        }
        else
        {
            HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
        }
    }
    else
    {
        HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
    }
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
HCU_EVContnsDistance phev_dte_temp=0;
HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
sizeof(HCU_EVContnsDistance));
can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
           ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
           ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
       {
         if(HCU_EVContnsDistanceVld_temp == 1)
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
               HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =FALSE;// return FALSE;
           }

       }
       else
       {
           HCU_EVContnsDistance_Temp.tc_phev_dte_node_status=FALSE;//return TRUE;
       }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    sizeof(HCU_EVContnsDistance));
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status=FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    sizeof(HCU_EVContnsDistance));
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status=FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
//    HCU_EVContnsDistance phev_dte_temp=0;
//    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
    uint8 phev_dte_temp  = 0;
    uint8 HCU_EVContnsDistanceVld_temp=0;
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    #ifdef COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    sizeof(phev_dte_temp));
    #endif 
    #ifdef COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld_temp));
    #endif
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =  TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    //(uint8)sizeof(HCU_EVContnsDistance));
    can_node_status = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    //HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =  TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    (uint8)sizeof(HCU_EVContnsDistance));
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =  TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    (uint8)sizeof(HCU_EVContnsDistance));
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status =  TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
    HCU_EVContnsDistance phev_dte_temp=0;
    HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
    (uint8)sizeof(HCU_EVContnsDistance));
    can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
    HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
                   HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
               }
               else
               {
                   HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
               }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
		HCU_EVContnsDistance phev_dte_temp=0;
		HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
        (uint8)sizeof(HCU_EVContnsDistance));
        can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
        HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
             {
                 HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
                 HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
             }
             else
             {
                 HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
             }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_TypeDef_HCU_EVContnsDistance
        HCU_EVContnsDistance phev_dte_temp=0;
        HCU_EVContnsDistanceVld HCU_EVContnsDistanceVld_temp=0;
#endif
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE,&phev_dte_temp,
        (uint8)sizeof(HCU_EVContnsDistance));
        can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCEVLD,&
        HCU_EVContnsDistanceVld_temp,sizeof(HCU_EVContnsDistanceVld));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
           {
             if(HCU_EVContnsDistanceVld_temp == 1)
             {
                 HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = TRUE;// return FALSE;
                 HCU_EVContnsDistance_Temp.tc_phev_dte_value = phev_dte_temp;
             }
             else
             {
                 HCU_EVContnsDistance_Temp.tc_phev_dte_node_status = FALSE;// return FALSE;
             }

           }
           else
           {
               HCU_EVContnsDistance_Temp.tc_phev_dte_node_status= FALSE;//return TRUE;
           }
#endif

#else

#endif



    return HCU_EVContnsDistance_Temp;
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_HCU_Charge_Status                                                  	      *
*                                                                                                         *
*Description: Charging state of vehicle                                                                   *
Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: TC_VEHICLE_CHARGE_TYPE_ENUM                                                                 *
*                                                                                                         *
*Author 	: Shu junhua                                                                                  *
*                                                                                                         *
*Date		: 2021-03-6    update for SRS V2.0                                                            *
**********************************************************************************************************/
TC_VEHICLE_CHARGE_TYPE_ENUM TC_RTE_API_Get_HCU_Charge_Status (void)
{
	Std_ReturnType can_node_status=0;
    TC_VEHICLE_CHARGE_TYPE_ENUM result=TC_VEHICLE_CHARGE_DEFAULT;
#if  (defined(SWC_TC_ADAPT_B03))

#ifdef Rte_Read_HCU_ChargSts_HCU_ChargSts
    HCU_ChargSts   HCU_ChargSts_u8=0;
    can_node_status = Rte_Read_HCU_ChargSts_HCU_ChargSts(&HCU_ChargSts_u8);
    if(((can_node_status&RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&&\
        ((can_node_status&RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED)&&\
	    ((can_node_status&RTE_E_COM_STOPPED) != RTE_E_COM_STOPPED))
    {
        result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
    }
    else
    {
        result=TC_VEHICLE_CHARGE_DEFAULT;
    }
#endif

#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
    HCU_ChargSts   HCU_ChargSts_u8=0;
    can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
    HCU_ChargSts));
    if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
    ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
    ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
    {
        result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
    }
    else
    {
        result=TC_VEHICLE_CHARGE_DEFAULT;
    }
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        uint8 HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
//        HCU_ChargSts   HCU_ChargSts_u8=0;
        uint8 HCU_ChargSts_u8=0;
        #ifdef COMEX_SIGNAL_RX_HCU_CHARGSTS
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts_u8));
        #endif
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        //HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
		HCU_ChargSts   HCU_ChargSts_u8=0;
		can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
		HCU_ChargSts));
		if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
		((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
		((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
		{
			result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
		}
		else
		{
			result=TC_VEHICLE_CHARGE_DEFAULT;
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal
        HCU_ChargSts   HCU_ChargSts_u8=0;
        can_node_status= Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS,&HCU_ChargSts_u8,sizeof(
        HCU_ChargSts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
        ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
        ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = (TC_VEHICLE_CHARGE_TYPE_ENUM) HCU_ChargSts_u8;
        }
        else
        {
            result=TC_VEHICLE_CHARGE_DEFAULT;
        }
#endif
#else
    result=TC_VEHICLE_CHARGE_DEFAULT;
#endif


    return result;
}

/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Odo_value                                                                    *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: shujunhua                                                                                *
*                                                                                                         *
*Date		: 2020-12-1                                                                                  *
**********************************************************************************************************/

uint32 TC_Api_Rte_Get_Odo_value (void)
{
uint32 result=0;

#if  (defined(SWC_TC_ADAPT_B03))
    s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
	(void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
	if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
	{
			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
	}
	else
	{
		    result = (0xffffffff);
	}
#endif
#elif (defined(SWC_TC_ADAPT_B02))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_B06))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_P03))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_P05))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_A07))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_D01))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_D02))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_D03))
        s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif

#elif (defined(SWC_TC_ADAPT_P02))
			s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
		(void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
		if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
		{

			//result = (Odo_Parament.OdoKmValue_u32/1000);
			result = (Odo_Parament.OdoKmValue_u32);
		}
		else
		{
				result = (0xffffffff);
		}
#endif

#elif (defined(SWC_TC_ADAPT_P01))
                s_OdoRteGetParament_t Odo_Parament;
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        (void)Rte_Read_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        if((TC_UINT_KM == TC_Rte_Api_Get_Uint_Cfg()) || (TC_UINT_KM_JP == TC_Rte_Api_Get_Uint_Cfg()))
        {

            //result = (Odo_Parament.OdoKmValue_u32/1000);
            result = (Odo_Parament.OdoKmValue_u32);
        }
        else
        {
                result = (0xffffffff);
        }
#endif


#else

#endif

    return result;

}
/**********************************************************************************************************
*Function   : TC_RTE_API_Get_Odo_Info                                                                     *
*                                                                                                         *
*Description: Add api for energy dte To IVI                                                               *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: TC_ENERGY_ODO_INFO_STRUCT                                                                   *
*                                                                                                         *
*Author 	: shujunhua                                                                                   *
*                                                                                                         *
*Date		: 2021-1-19                                                                                   *
**********************************************************************************************************/

TC_ENERGY_ODO_INFO_STRUCT TC_Api_Rte_Get_Odo_Info (void)
{
    TC_ENERGY_ODO_INFO_STRUCT Odo_Info_temp={0,0,0,0};
#if  (defined(SWC_TC_ADAPT_B03))
    #ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
    Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
    Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
    Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
    #endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
    s_OdoRteGetParament_t Odo_Parament;
    (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
    Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
    Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
    Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
    Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
        s_OdoRteGetParament_t Odo_Parament;
        (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
        Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
        Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
        Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Read_rpSR_SWCNormal_OdoParament_Element
            s_OdoRteGetParament_t Odo_Parament;
            (void)Rte_Read_Common_Normal_rpSR_SWCNormal_OdoParament_Element(&Odo_Parament);
            Odo_Info_temp.Tc_Energy_Info_Odo=Odo_Parament.OdoKmValue_u32/1000; /*unit 1KM */
            Odo_Info_temp.Tc_Energy_Info_TripA=Odo_Parament.TripKmValue_u32[0];/*unit 0.1KM */
            Odo_Info_temp.Tc_Energy_Info_TripB=Odo_Parament.TripKmValue_u32[1];/*unit 0.1KM */
            Odo_Info_temp.Tc_Energy_Info_FsrvKmValue=Odo_Parament.FsrvKmValue_s32;/*unit 1KM */
#endif

#else

#endif

    return Odo_Info_temp;
}

TC_EMERGY_SYS_LOG_t TC_Api_Rte_Get_SYS_Data(void)
{
	TC_EMERGY_SYS_LOG_t time_s = {0};
	Std_ReturnType readSts;
	sint64 timetick=0;
#if  (defined(SWC_TC_ADAPT_B03))
    //#ifdef Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime
     #ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
         //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
         readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
         if(readSts ==RTE_E_OK)
         {
             time_s.time =timetick ;
         }

     #endif
     time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;
#elif (defined(SWC_TC_ADAPT_B02))
//#ifdef Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime
      #ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis

            //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
              readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
              if(readSts ==RTE_E_OK)
              {
                  time_s.time =timetick ;
              }


      #endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_B06))
        //#ifdef Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime
     #ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
     //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
     readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
     if(readSts ==RTE_E_OK)
     {
         time_s.time =timetick ;
     }

     #endif
     time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;


#elif (defined(SWC_TC_ADAPT_P03))
     #ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
     //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
     readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
     if(readSts ==RTE_E_OK)
     {
         time_s.time =timetick ;
     }

     #endif
     time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
        //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
        readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
        if(readSts ==RTE_E_OK)
        {
            time_s.time =timetick ;
        }

#endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;


#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
        //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
        readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
        if(readSts ==RTE_E_OK)
        {
            time_s.time =timetick ;
        }

#endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
        //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
        readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
        if(readSts ==RTE_E_OK)
        {
            time_s.time =timetick ;
        }

#endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
        //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
        readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
        if(readSts ==RTE_E_OK)
        {
            time_s.time =timetick ;
        }

#endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
        //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
        readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
        if(readSts ==RTE_E_OK)
        {
            time_s.time =timetick ;
        }

#endif
        time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
	 //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
	 readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
	 if(readSts ==RTE_E_OK)
	 {
		 time_s.time =timetick ;
	 }

 #endif
	 time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_IRTC_Service_GetUTCTimeInMillis
	 //  readSts = Rte_Read_tiSR_Rte_Read_Sd_RTC_Data_UtcTime(&timetick);
	 readSts = Rte_Call_IRTC_Service_GetUTCTimeInMillis(&timetick);
	 if(readSts ==RTE_E_OK)
	 {
		 time_s.time =timetick ;
	 }

 #endif
	 time_s.Curodo =TC_Api_Rte_Get_Odo_value()/1000;// Odo_Api_Odometer_Get(e_OdoUints_10m)/10;

#else

#endif

	return time_s;
}



Std_ReturnType TC_Rte_Api_Get_Fuel_ONE_Error_State (void)
{
#if  (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
    TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
		TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation
        TC_FUEL_Muti_Err_Status=Rte_Call_rpCS_SWCNormal_SensorAorB_Status_Operation();
#endif

#else
    TC_FUEL_Muti_Err_Status = FALSE;
#endif
    return TC_FUEL_Muti_Err_Status;

}


/* new energy signal adaptation */
uint8 TC_RTE_API_Get_HCU_TotDrvReqPower(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Read_HCU_TotDrvReqPower_HCU_TotDrvReqPower(&u8TotDrvReqPower);
	*data = (uint16)u8TotDrvReqPower;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	uint8 u8TotDrvReqPower = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8TotDrvReqPower = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}


#elif (defined(SWC_TC_ADAPT_P01))
        uint8 u8TotDrvReqPower = 0;
    
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X14A, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
        *data = (uint16)u8TotDrvReqPower;
        if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
        {
            result = RTE_E_OK;
        }
    
#endif

	return result;
}

uint8 TC_RTE_API_Get_HCU_TotDrvReqPower_P0(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8TotDrvReqPower = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
	*data = (uint16)u8TotDrvReqPower;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
    uint8 u8TotDrvReqPower = 0;

    result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_TOTDRVREQPOWER_0X9E, &u8TotDrvReqPower, (uint8)sizeof(u8TotDrvReqPower));
    *data = (uint16)u8TotDrvReqPower;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
        result = RTE_E_OK;
    }

#endif

	return result;
}

uint8 TC_RTE_API_Get_HCU_AvailPower_TM(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Read_HCU_AvailPower_TM_HCU_AvailPower_TM(&u8AvailPower_TM);
	*data = (uint16)u8AvailPower_TM;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8AvailPower_TM = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8AvailPower_TM = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
	*data = (uint16)u8AvailPower_TM;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
uint8 u8AvailPower_TM = 0;
result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_AVAILPOWER_TM, &u8AvailPower_TM, (uint8)sizeof(u8AvailPower_TM));
*data = (uint16)u8AvailPower_TM;
if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
{
	result = RTE_E_OK;
}

#endif

	return result;
}

uint8 TC_RTE_API_Get_BMS_DisSOC(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8BMS_DisSoc = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8BMS_DisSoc = 0;

	//result = Rte_Read_BMS_DisSOC1_BMS_DisSOC1(&u8BMS_DisSoc);
	*data = u8BMS_DisSoc;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8BMS_DisSoc = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8BMS_DisSoc = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8BMS_DisSoc = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8BMS_DisSoc = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8BMS_DisSoc = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8BMS_DisSoc = 0;
	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
	*data = u8BMS_DisSoc;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
	uint8 u8BMS_DisSoc = 0;

result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_DISSOC1, (uint8 *)&u8BMS_DisSoc, (uint8)sizeof(u8BMS_DisSoc));
*data = u8BMS_DisSoc;
if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
{
	result = RTE_E_OK;
}
#endif

	return result;
}

uint8 TC_RTE_API_Get_HCU_ECODrvHabit(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Read_HCU_ECODrvHabit_Indcn_HCU_ECODrvHabit_Indcn(&u8HCU_ECODrvHabit);
	*data = (uint16)u8HCU_ECODrvHabit;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8HCU_ECODrvHabit = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
    *data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
	uint8 u8HCU_ECODrvHabit = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ECODRVHABIT_INDCN, &u8HCU_ECODrvHabit, (uint8)sizeof(u8HCU_ECODrvHabit));
	*data = (uint16)u8HCU_ECODrvHabit;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

uint8 TC_RTE_API_Get_BMS_ChrgDurationTime(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Read_BMS_ChrgDurationTime_BMS_ChrgDurationTime(&u16BMS_ChrgDurationTime);
	*data = u16BMS_ChrgDurationTime;
#elif (defined(SWC_TC_ADAPT_P03))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_A07))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
    *data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
	uint16 u16BMS_ChrgDurationTime = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)&u16BMS_ChrgDurationTime, (uint8)sizeof(u16BMS_ChrgDurationTime));
	*data = u16BMS_ChrgDurationTime;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

    return result;
}


uint8 TC_RTE_API_Get_OBC_ConnectSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8OBC_ConnectSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8OBC_ConnectSts = 0;

	result = Rte_Read_OBC_ConnectSts_OBC_ConnectSts(&u8OBC_ConnectSts);
	*data = u8OBC_ConnectSts;
#elif (defined(SWC_TC_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8OBC_ConnectSts = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8OBC_ConnectSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8OBC_ConnectSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8OBC_ConnectSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8OBC_ConnectSts = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
	*data = u8OBC_ConnectSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
    uint8 u8OBC_ConnectSts = 0;

   // result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, &u8OBC_ConnectSts, (uint8)sizeof(u8OBC_ConnectSts));
    *data = u8OBC_ConnectSts;
    if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
    {
    	result = RTE_E_OK;
    }
#endif

	return result;
}

uint8 TC_RTE_API_Get_BMS_StsCC2Line(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8BMS_StsCC2Line = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMSSTSCC2LINE, &u8BMS_StsCC2Line, (uint8)sizeof(u8BMS_StsCC2Line));
	*data = u8BMS_StsCC2Line;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	uint8 u8BMS_StsCC2Line = 0;

	//result = Rte_Read_BMS_StsCC2Line_BMS_StsCC2Line(&u8BMS_StsCC2Line);
	*data = u8BMS_StsCC2Line;
#elif (defined(SWC_TC_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	uint8 u8BMS_StsCC2Line = 0;

	//result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMSSTSCC2LINE, &u8BMS_StsCC2Line, (uint8)sizeof(u8BMS_StsCC2Line));
	*data = u8BMS_StsCC2Line;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P01))
    *data = 0;

#endif

	return result;
}

uint8 TC_RTE_API_Get_BMS_PackCurr(uint16 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	SG_BMS4 SG_BMS4_PBF;
	result = Rte_Read_SG_BMS4_SG_BMS4(&SG_BMS4_PBF);
	*data = SG_BMS4_PBF.BMS_PackCurr;
#elif (defined(SWC_TC_ADAPT_P03))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	uint16 u16BMS_PackCurr = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#elif (defined(SWC_TC_ADAPT_D01))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P01))
	uint16 u16BMS_PackCurr = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_PACKCURR, (uint8 *)&u16BMS_PackCurr, (uint8)sizeof(u16BMS_PackCurr));
	*data = u16BMS_PackCurr;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}

#endif

	return result;
}

/**********************************************************************************************************
*Function   : TC_NE_RTE_API_Get_Power_Mode_State                                                          *
*                                                                                                         *
*Description: New energy module use, get power mode                                                       *
*                                                                                                         *
*Parameter	: NONE                                                                                        *
*                                                                                                         *
*Return     : uint8                                                                                       *
*                                                                                                         *
*Author     : DengJiangbo                                                                                 *
*                                                                                                         *
*Date       : 2021-4-02                                                                                   *
**********************************************************************************************************/
uint8 TC_NE_RTE_API_Get_Power_Mode_State(void)
{
	uint8 result = CLUSTER_UNKONWN;

#if (defined(SWC_TC_ADAPT_B03))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_B02))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_B06))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_P03))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_P05))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_A07))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_D01))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_D02))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_D03))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_P02))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
	SystemState_RecordType *power_u8;
	power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

	if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
	{
		if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
		{
			result = CLUSTER_KL15ON;
		}
		else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
		{
			result = CLUSTER_KL15OFF;
		}
		else
		{
			// don't care
			result = CLUSTER_OTHER;
		}
	}
	else
	{
		// don't care
		result = CLUSTER_OTHER;
	}
#endif
#elif (defined(SWC_TC_ADAPT_P01))
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
    SystemState_RecordType *power_u8;
    power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();

    if(FALSE != TC_RTE_API_Get_Voltage_Mode_State())
    {
        if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
        {
            result = CLUSTER_KL15ON;
        }
        else if(SYSTEMSTATE_Cluster_STANDBY == power_u8->ClusterState)
        {
            result = CLUSTER_KL15OFF;
        }
        else
        {
            // don't care
            result = CLUSTER_OTHER;
        }
    }
    else
    {
        // don't care
        result = CLUSTER_OTHER;
    }
#endif
#else
#endif

	return result;
}


uint8 TC_RTE_API_Get_HCU_EnrgFlowInd_DHT(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_B02))
	uint8 u8EnrgFlowInd_DHT = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_DHT, &u8EnrgFlowInd_DHT, (uint8)sizeof(u8EnrgFlowInd_DHT));
	*data = u8EnrgFlowInd_DHT;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_B03))
	SG_HCU_HP5 SG_HCU_HP5_Tmp = {0};
	result = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&SG_HCU_HP5_Tmp);
	*data = SG_HCU_HP5_Tmp.HCU_EnrgFlowInd_DHT;
#elif (defined(SWC_TC_ADAPT_A07))
	// HCU_HC3 ?
	uint8 u8EnrgFlowInd_DHT = 0;

	result = COMEX_NEVER_RECEIVED;//Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_DHT, &u8EnrgFlowInd_DHT, (uint8)sizeof(u8EnrgFlowInd_DHT));
	*data = u8EnrgFlowInd_DHT;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P01))
    *data = 0;

#endif
	return result;
}

uint8 TC_RTE_API_Get_HCU_EnrgFlowInd_P2(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P03))
	uint8 u8EnrgFlowInd_P2 = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
	*data = u8EnrgFlowInd_P2;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8EnrgFlowInd_P2 = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
	*data = u8EnrgFlowInd_P2;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
    }
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8EnrgFlowInd_P2 = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
	*data = u8EnrgFlowInd_P2;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
    }
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8EnrgFlowInd_P2 = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
	*data = u8EnrgFlowInd_P2;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
    }
#elif (defined(SWC_TC_ADAPT_P02))
	uint8 u8EnrgFlowInd_P2 = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
	*data = u8EnrgFlowInd_P2;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
    }
#elif (defined(SWC_TC_ADAPT_P01))
uint8 u8EnrgFlowInd_P2 = 0;

result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ENRGFLOWIND_P2, &u8EnrgFlowInd_P2, (uint8)sizeof(u8EnrgFlowInd_P2));
*data = u8EnrgFlowInd_P2;
if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
{
	result = RTE_E_OK;
}
#endif
	return result;
}

uint8 TC_RTE_API_Get_BarConnSts(uint8 *data)
{
	uint8 result = RTE_E_INVALID;

#if (defined(SWC_TC_ADAPT_P05))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_A07))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_B03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_B02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P03))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_D01))
	uint8 u8BarConnSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, &u8BarConnSts, (uint8)sizeof(u8BarConnSts));
	*data = u8BarConnSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D02))
	uint8 u8BarConnSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, &u8BarConnSts, (uint8)sizeof(u8BarConnSts));
	*data = u8BarConnSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_D03))
	uint8 u8BarConnSts = 0;

	result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, &u8BarConnSts, (uint8)sizeof(u8BarConnSts));
	*data = u8BarConnSts;
	if (result == RTE_E_ComEx_COMEX_UPDATE_RECEIVED)
	{
		result = RTE_E_OK;
	}
#elif (defined(SWC_TC_ADAPT_P02))
	*data = 0;
#elif (defined(SWC_TC_ADAPT_P01))
	*data = 0;
#endif

	return result;
}

void  TC_API_Get_Fuel_ONE_Error_State_Clear (void)
{
	TC_FUEL_Muti_Err_Status=0;
}

/*************************************************************************  
 * [TC_API_Get_HCU_CDCSFlag : description]
 * @Author   GW00227774
 * @DateTime 2021/11/1-15:41:42
 * @param    void                     [description]
 * @return   uint8                    [description]
 *************************************************************************/
uint8 TC_Rte_Get_HCU_CDCSFlag(void)
{
    uint8 result = 0xFF;
#if (defined(SWC_TC_ADAPT_B02))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
         uint8 u8HcuCdcsFlag = 0u;
         result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
         if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
             ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
             ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
         {
             result = u8HcuCdcsFlag;
         }
         else
         {
             result = 0u;
         }
     #endif

#elif (defined(SWC_TC_ADAPT_B03))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
         uint8 u8HcuCdcsFlag = 0u;
         result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
         if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
             ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
             ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
         {
             result = u8HcuCdcsFlag;
         }
         else
         {
             result = 0u;
         }
    #endif

#elif (defined(SWC_TC_ADAPT_A07))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
    	uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif
#elif (defined(SWC_TC_ADAPT_P05))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif


#elif (defined(SWC_TC_ADAPT_P03))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif


#elif (defined(SWC_TC_ADAPT_D01))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif


#elif (defined(SWC_TC_ADAPT_D02))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif


#elif (defined(SWC_TC_ADAPT_D03))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif


#elif (defined(SWC_TC_ADAPT_P02))
    #ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif
#elif (defined(SWC_TC_ADAPT_P01))
#ifdef COMEX_SIGNAL_RX_HCU_CDCSFLAG
        uint8 u8HcuCdcsFlag = 0u;
        result = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CDCSFLAG, &u8HcuCdcsFlag, (uint8)sizeof(u8HcuCdcsFlag));
        if(((result&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
            ((result&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
            ((result&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
            result = u8HcuCdcsFlag;
        }
        else
        {
            result = 0u;
        }
    #endif

#else

#endif
	return result;
}
/*************************************************************************  
 * [TC_Adapt_Api_Get_AVS_MAX_VALUE : description]
 * @Author   GW00254713
 * @DateTime 2022/1/10
 * @param uint32
 * unit_type=0 KM/H unit_type=1 MPH
 *************************************************************************/
uint32 TC_AVS_Get_MAXValue(uint8 unit_type)
{
    uint32 result=0;
    if((TC_VEHICLE_HEV == TC_Module_Vehicle_Type_Data) || (TC_VEHICLE_PHEV == TC_Module_Vehicle_Type_Data))
    {
        if(0u == unit_type)
        {
            result = 260u;
        }
        else if(1u == unit_type)
        {
            result = 180u;
        }
        else 
        {
            result = 0u;
        }
    }
    else if((TC_VEHICLE_FUEL == TC_Module_Vehicle_Type_Data)||(TC_VEHICLE_FUEL_DIESEL == TC_Module_Vehicle_Type_Data))
    {
        if(0u == unit_type)
        {
            result = 240u;
        }
        else if(1u == unit_type)
        {
            result = 160u;
        }
        else 
        {
            result = 0u;
        }
    }
    else
    {
        if(0u == unit_type)
        {
            result = 240u;
        }
        else if(1u == unit_type)
        {
            result = 160u;
        }
        else 
        {
            result = 0u;
        }
    }
    result*=1000uL;
	return result;
}
/*************************************************************************  
 * [TC_Adapt_PowerTrainType_Vconfig : description]
 * @Author   GW00227774
 * @DateTime 2022/4/6-15:47:59
 * @param    void                     [description]
 *************************************************************************/
static TC_RTE_POWER_TRAIN_TYPE_ENUM TC_Adapt_PowerTrainType_Vconfig(void)
{
    TC_RTE_POWER_TRAIN_TYPE_ENUM PowerTrainType = TC_PowerTrainType_NONE;
#if (defined(SWC_TC_ADAPT_P03))
    uint8 VCfgByte27 = 0;
    VconfigKind_Allbuffers VCfg_kindBuffers={0};
    #ifdef Rte_Read_Vconfig_GetKindBuffers_AllKinds
    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VCfg_kindBuffers);
    if(TRUE==VCfg_kindBuffers[VCONFIG_KIND_INIT_FLAG])
    {
        VCfgByte27 = VCfg_kindBuffers[VCONFIG_KIND_POWER_TRAIN_TYPE];
    }
    if( 109 == VCfgByte27 )
    {
        PowerTrainType = TC_PowerTrainType_AAEA7;
    }
    else if( 112 == VCfgByte27 )
    {
        PowerTrainType = TC_PowerTrainType_AAED2;
    }
    else if( 139 == VCfgByte27 )
    {
        PowerTrainType = TC_PowerTrainType_AAEB5;
    }
    else
    {
        PowerTrainType = TC_PowerTrainType_NONE;
        (void)TC_MODULE_err("TC_PowerTrainType :%d",VCfgByte27);
    }
    #endif
#else
    PowerTrainType = TC_PowerTrainType_NONE;
#endif
    return PowerTrainType;
}

/*************************************************************************  
 * [TC_Adapt_Api_Get_DteSfcInit : description]
 * @Author   GW00227774
 * @DateTime 2021/11/10-17:25:29
 * @param    void                     [description]
 *************************************************************************/
stTC_RTE_DteSfcInit TC_Adapt_Api_Get_DteSfcInit(void)
{
    stTC_RTE_DteSfcInit DteSfcInit = {0};
    CconfigKind_400Bytes Lcal_config_data;
	boolean Lcal_config_status = FALSE;
    uint16 u16STripAgeTolTripBileage = 100;
    #if(defined(SWC_TC_ADAPT_P03))
    TC_RTE_POWER_TRAIN_TYPE_ENUM PowerTrainType = TC_Adapt_PowerTrainType_Vconfig();
    #endif
	Lcal_config_status = TC_Rte_Api_Get_Cconfig_Cfg(Lcal_config_data);

	if(FALSE != Lcal_config_status)
	{
    #if (defined(SWC_TC_ADAPT_B02))
        if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_B03))
        if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_A07))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error");
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error");
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P05))
        if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P03))
        if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL)&&(PowerTrainType == TC_PowerTrainType_AAEA7))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL)&&(PowerTrainType == TC_PowerTrainType_AAED2))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
        else if ((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL)&&(PowerTrainType == TC_PowerTrainType_AAEB5))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon4,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon5,Lcal_config_data);
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = u16STripAgeTolTripBileage;
        }
    #elif (defined(SWC_TC_ADAPT_D01))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_D02))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_D03))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon3,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P02))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P01))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon1,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
            DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
            if(DteSfcInit.STripAgeInitTripBileage==0u){
                (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
            }
            else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
            }
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #else
        DteSfcInit.STripAgeInitTripBileage =(uint16)CConfig_GetConfig(CCONFIG_KIND_STripAgeInitTripBileage1,Lcal_config_data);   /* init trip =75km  */
        DteSfcInit.StripAgeFuelInitFuelCon = (uint16)CConfig_GetConfig(CCONFIG_KIND_StripAgeFuelInitFuelCon2,Lcal_config_data);/*SFCDefault_NvmInit*STripAgeInitTripBileage*/
        if(DteSfcInit.STripAgeInitTripBileage==0u){
            (void)TC_MODULE_err("TripBileage is error:%d",DteSfcInit.STripAgeInitTripBileage);
        }
        else{
                DteSfcInit.SFCDefault_NvmInit = DteSfcInit.StripAgeFuelInitFuelCon/DteSfcInit.STripAgeInitTripBileage;
        }
        DteSfcInit.STripAgeTolTripBileage = 100;
    #endif
    }
    else
    {
    #if (defined(SWC_TC_ADAPT_B02))
        if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_B03))
        if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_A07))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P05))
        if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit      = 115;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8250;
            DteSfcInit.SFCDefault_NvmInit      = 110;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8250;
            DteSfcInit.SFCDefault_NvmInit      = 110;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P03))
        if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 9750;
            DteSfcInit.SFCDefault_NvmInit      = 130;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 9750;
            DteSfcInit.SFCDefault_NvmInit      = 130;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 9750;
            DteSfcInit.SFCDefault_NvmInit      = 130;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_D01))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_D02))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_D03))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_PHEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 4500;
            DteSfcInit.SFCDefault_NvmInit      = 60;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
        else
        {   /*error :default fuel */
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 5625;
            DteSfcInit.SFCDefault_NvmInit      = 75;
            DteSfcInit.STripAgeTolTripBileage  = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P02))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #elif (defined(SWC_TC_ADAPT_P01))
         if (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_HEV)
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else if((TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL) || (TC_Module_Vehicle_Type_Data ==TC_VEHICLE_FUEL_DIESEL))
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
        else
        {
            DteSfcInit.STripAgeInitTripBileage = 75;
            DteSfcInit.StripAgeFuelInitFuelCon = 8625;
            DteSfcInit.SFCDefault_NvmInit = 115;
            DteSfcInit.STripAgeTolTripBileage = 100;
        }
    #else
        DteSfcInit.STripAgeInitTripBileage = 75;
        DteSfcInit.StripAgeFuelInitFuelCon = 8625;
        DteSfcInit.SFCDefault_NvmInit = 115;
        DteSfcInit.STripAgeTolTripBileage = 100;
    #endif
    }
	return DteSfcInit;
}


/*************************************************************************
 * [TC_RTE_GetAllConfiguration : description]
 * @Author   GW00227774
 * @DateTime 2022/1/18-9:44:42
 * @param    void                     [description]
 *************************************************************************/
void TC_RTE_GetAllConfiguration(void)
{
    VconfigKind_Allbuffers configAdress;
    (void)memset(&st_TcRteConfiguration,0xff,sizeof(st_TcConfiguration));

    (void) Rte_Read_Vconfig_GetKindBuffers_AllKinds(configAdress);

    if(E_OK != configAdress[VCONFIG_KIND_INIT_FLAG])
    {
        st_TcRteConfiguration.Vconfig_KIND_PT_CAN_BUS_TYPE = configAdress[VCONFIG_KIND_PT_CAN_BUS_TYPE];
    }
}

st_TcConfiguration TC_RTE_ApiGetConfiguration(void)
{
	return st_TcRteConfiguration;
}


/*************************************************************************
 * [TC_RTE_API_GetSpeedMsgValue : description]
 * @Author   GW00227774
 * @DateTime 2022/1/17-10:24:19
 * @param    void                     [description]
 *************************************************************************/
CanFrameCounterType TC_RTE_API_GetSpeedMsgValue(void)
{
#if (defined(SWC_TC_ADAPT_B02))
	CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
 	{
 		outValue.Data = 0xffff;
 		outValue.Counter = 0xffff;
 	}
 	else
 	{
 		if(outValue.Data < 0x3E8)
 		{
 			outValue.Data *= 10;
 		}
 		else
 		{
 			outValue.Data = 0xffff;
 			outValue.Counter = 0xffff;
 		}
 	}
 #else
 	outValue.Data = 0xffff;
 	outValue.Counter = 0xffff;
 #endif
#elif(defined(SWC_TC_ADAPT_P05))
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	st_TcConfiguration condfig_s = TC_RTE_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}	
#elif(defined(SWC_TC_ADAPT_A07))
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	st_TcConfiguration condfig_s = TC_RTE_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}
#elif(defined(SWC_TC_ADAPT_P03))
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config = 0u;
	st_TcConfiguration condfig_s = TC_RTE_ApiGetConfiguration();
	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
	/*Get signals from CAN*/
	if(0x00u == config)
	{
	/* #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	 */
	}
	/*Get signals from CANFD*/
	else if(0x01u == config)
	{
	 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
	 	if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
	 	{
	 		outValue.Data = 0xffff;
	 		outValue.Counter = 0xffff;
	 	}
	 	else
	 	{
	 		if(outValue.Data < 0x3E8)
	 		{
	 			outValue.Data *= 10;
	 		}
	 		else
	 		{
	 			outValue.Data = 0xffff;
	 			outValue.Counter = 0xffff;
	 		}
	 	}
	 #else
	 	outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	 #endif
	}
	else
	{
		outValue.Data = 0xffff;
	 	outValue.Counter = 0xffff;
	}
#elif (defined(SWC_TC_ADAPT_D01))
		CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
		if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
		{
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
		}
		else
		{
			if(outValue.Data < 0x3E8)
			{
				outValue.Data *= 10;
			}
			else
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
		}
 #else
		outValue.Data = 0xffff;
		outValue.Counter = 0xffff;
 #endif
#elif (defined(SWC_TC_ADAPT_D02))
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#elif (defined(SWC_TC_ADAPT_D03))
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#elif (defined(SWC_TC_ADAPT_P02))
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
 #elif (defined(SWC_TC_ADAPT_P01))
			CanFrameCounterType outValue = {0xffff,0xffff};
 #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
			if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
			{
				outValue.Data = 0xffff;
				outValue.Counter = 0xffff;
			}
			else
			{
				if(outValue.Data < 0x3E8)
				{
					outValue.Data *= 10;
				}
				else
				{
					outValue.Data = 0xffff;
					outValue.Counter = 0xffff;
				}
			}
 #else
			outValue.Data = 0xffff;
			outValue.Counter = 0xffff;
 #endif
#else
	CanFrameCounterType outValue = {0xffff,0xffff};
	uint8 config;
	st_TcConfiguration condfig_s = TC_RTE_ApiGetConfiguration();
 	
 	config =  condfig_s.Vconfig_KIND_PT_CAN_BUS_TYPE;
 
 	if(0x00 == config)
 	{
  #ifdef Rte_Call_CanFrameCounter_Can_ABS3_Counter
  		if(E_OK != Rte_Call_CanFrameCounter_Can_ABS3_Counter(&outValue))
  		{
  			outValue.Data = 0xffff;
  			outValue.Counter = 0xffff;
  		}
  		else
  		{	if(outValue.Data < 0x3E8)
  			{
  				outValue.Data *= 10;
  			}
  			else
  			{
  				outValue.Data = 0xffff;
  				outValue.Counter = 0xffff;
  			}
  		}
  #else 
  		outValue.Data = 0xffff;
  		outValue.Counter = 0xffff;	
  #endif
 	}
 	else if(0x01 == config)
 	{
  #ifdef Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter
  		if(E_OK != Rte_Call_CanFrameCounter_Can_ESP_FD2_Counter(&outValue))
  		{
  			outValue.Data = 0xffff;
  			outValue.Counter = 0xffff;
  		}
  		else
  		{
  			if(outValue.Data < 0x3E8)
  			{
  				outValue.Data *= 10;
  			}
  			else
  			{
  				outValue.Data = 0xffff;
  				outValue.Counter = 0xffff;
  			}
  		}
  #else
  		outValue.Data = 0xffff;
  		outValue.Counter = 0xffff;
  #endif
 	}
#endif
	return outValue;

}


#define SWC_TC_STOP_SEC_CODE
#include "SWC_TC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************
**
**  Revision:      1.0
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/



