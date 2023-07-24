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
**  Name:               SWC_Fuel_Pkg_Math.c
**
**  Description:        Implentation module for linear interpolation software.
**                     See comments below for more details.
**
** Organization:       
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
#include "Rte_Common_Normal.h"
#include "IoHwAb_Cfg_RI.h"
#include "VConfig.h"
#include <string.h>
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Fuel_Api_Rte_Adapt.h"
#include "SWC_Fuel_Api_Process.h"

#if  (defined(SWC_FUEL_ADAPT_B03))

#elif (defined(SWC_FUEL_ADAPT_B02)) 

#elif (defined(SWC_FUEL_ADAPT_P03))

#elif (defined(SWC_FUEL_ADAPT_P05)) 
    #include "ComEx_Cfg.h"
#elif (defined(SWC_FUEL_ADAPT_A07))

#elif (defined(SWC_FUEL_ADAPT_P02))

#elif (defined(SWC_FUEL_ADAPT_D01))

#elif (defined(SWC_FUEL_ADAPT_D02))

#elif (defined(SWC_FUEL_ADAPT_D03))

#elif (defined(SWC_FUEL_ADAPT_P01))

#else

#endif

/**********************************************************************************************************
*																								          *
*																								          *
*	              Type Definition																		  *
*																								          *
*																								          *
**********************************************************************************************************/


/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_FUEL_START_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Fuel_Tank_Cfg                                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: 2 - FLASH, 1 - ON, 0 - OFF                                                                  *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
Fuel_config_t Fuel_Rte_Api_Get_Fuel_Tank_Cfg(void)
{
    FUEL_VR_TYPE_ENUM fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO1;
    uint8 fuel_project_cfg = 0u;
    uint8 fuel_tank_type_cfg = 0u;
    uint8 VconfigKind_600Bytes_temp[sizeof(VconfigKind_Allbuffers)];
    uint8 fuel_tank_Tankportposition = 0u;
    uint8 Fuel_Engine_Control_Unit_Type=0u;
    Fuel_config_t  fuel_tank_cfg_temp;
    uint8 fuel_tank_aux_temp = 0u;
    uint8 fuel_vehicle_cfg_temp = 0u;
    #ifdef Rte_Read_Vconfig_GetKindBuffers_AllKinds
    (void)Rte_Read_Vconfig_GetKindBuffers_AllKinds(VconfigKind_600Bytes_temp);

    if(0u != VconfigKind_600Bytes_temp[VCONFIG_KIND_INIT_FLAG])
    {
        fuel_project_cfg = VconfigKind_600Bytes_temp[VCONFIG_KIND_PROJECT_CODE];// 项目代码
        fuel_tank_type_cfg = VconfigKind_600Bytes_temp[VCONFIG_KIND_FUEL_TANK_SYSTEM];// 油箱系统
        Fuel_Engine_Control_Unit_Type=VconfigKind_600Bytes_temp[VCONFIG_KIND_ENGINE_CONTROL_UNIT];// 发动机控制单元
        fuel_tank_Tankportposition =VconfigKind_600Bytes_temp[VCONFIG_KIND_INST_REFUELING_PORT_ORIENTATION_DISPLAY];// 仪表加油口方位显示
        //fuel_tank_aux_temp=VconfigKind_600Bytes_temp[VCONFIG_KIND_AUXILIARY_FUEL_TANK];// 有无副油箱
        fuel_tank_aux_temp=(uint8)((fuel_tank_type_cfg==5u)?1u:0u);// 有无副油箱
        fuel_vehicle_cfg_temp = VconfigKind_600Bytes_temp[VCONFIG_KIND_FUEL];// 燃油类型
    }
    if(1u == fuel_tank_type_cfg)// 0b001 常规单浮子油箱
    {
        if(FUEL_PROJECTCODE_V51_0 == fuel_project_cfg)
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO2;
        }
        else if(((FUEL_PROJECTCODE_P03 ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1 ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1G ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1R ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1IND ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_CY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_DP ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_CY_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05G_CY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_DP_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_YY_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05G_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_XDL ==fuel_project_cfg ))&&\
                ((FUEL_ENG_DIESEL_Dr ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_DIESEL_Dr_CB18 ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_DIESEL_DELPHI ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_DIESEL_NEW_TREND ==Fuel_Engine_Control_Unit_Type )))
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO3;
        }
        else if(((FUEL_PROJECTCODE_P03 ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1 ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1G ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1R ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_1IND ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_CY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_DP ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_CY_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05G_CY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_DP_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05_YY_THA ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P05G_YY ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P03_XDL ==fuel_project_cfg )||\
                (FUEL_PROJECTCODE_P02 ==fuel_project_cfg ))&&\
                ((FUEL_ENG_NONE ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_GASOLINE_UAES ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_GASOLINE_SIEMENS ==Fuel_Engine_Control_Unit_Type )||\
                (FUEL_ENG_GASOLINE_DELPHI ==Fuel_Engine_Control_Unit_Type )))
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO4;
        }
        else if((FUEL_PROJECTCODE_A07 ==fuel_project_cfg ))
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO5;
        }
        else if( ((FUEL_PROJECTCODE_D01 ==fuel_project_cfg )||(FUEL_PROJECTCODE_D03 ==fuel_project_cfg ))&&((FUEL_TYPE_HEV==fuel_vehicle_cfg_temp)||(FUEL_TYPE_GASOLINE==fuel_vehicle_cfg_temp)) )
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO7;
        }
        else if( ((FUEL_PROJECTCODE_D01 ==fuel_project_cfg )||(FUEL_PROJECTCODE_D02 ==fuel_project_cfg )||(FUEL_PROJECTCODE_D02G ==fuel_project_cfg )||(FUEL_PROJECTCODE_D03 ==fuel_project_cfg ))&&(FUEL_TYPE_PHEV==fuel_vehicle_cfg_temp) )
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO8;
        }
        else if( ((FUEL_PROJECTCODE_D02 ==fuel_project_cfg )||(FUEL_PROJECTCODE_D02G ==fuel_project_cfg ))&&((FUEL_TYPE_HEV == fuel_vehicle_cfg_temp )||(FUEL_TYPE_GASOLINE==fuel_vehicle_cfg_temp)) )
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO9;
        }
        else
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_SINGLE_NO1;
        }
    }
    else if(2u == fuel_tank_type_cfg)// 0b010 常规双浮子油箱
    {
        if((FUEL_PROJECTCODE_V71 == fuel_project_cfg) || (FUEL_PROJECTCODE_V71GT == fuel_project_cfg))
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_DUAL_NO2;
        }
        else if(FUEL_PROJECTCODE_A08 == fuel_project_cfg)
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_DUAL_NO3;
        }
        else if((FUEL_PROJECTCODE_D03_1G == fuel_project_cfg)||(FUEL_PROJECTCODE_D01G == fuel_project_cfg))
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_DUAL_NO4;
        }
        else
        {
            fuel_tank_cfg = FUEL_VR_COMMMON_DUAL_NO1;
        }
    }
    else if(3u == fuel_tank_type_cfg)// 0b011 高压单浮子油箱
    {
        fuel_tank_cfg = FUEL_VR_HIGH_VOLT_SINGLE_NO1;
    }
    else if(4u == fuel_tank_type_cfg)// 0b100 高压双浮子油箱
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;
    }
    else/* error cfg */
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;
    }
#if   (defined(SWC_FUEL_ADAPT_B03))
#elif (defined(SWC_FUEL_ADAPT_B02))
#elif (defined(SWC_FUEL_ADAPT_P03))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO3) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO4))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_P05))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO3) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO4))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_A07))
    if(fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO5)
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_P02))
    if(fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO4)
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_D01))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO7) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO8))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_D02))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO8) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO9))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_D03))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO7) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO8) && (fuel_tank_cfg != FUEL_VR_COMMMON_DUAL_NO4))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#elif (defined(SWC_FUEL_ADAPT_P01))
    if((fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO7) && (fuel_tank_cfg != FUEL_VR_COMMMON_SINGLE_NO8))
    {
        fuel_tank_cfg = FUEL_VR_COMMMON_NONE;/* error cfg */
    }
#else
#endif
    fuel_tank_cfg_temp.Fuel_config_tanktype= fuel_tank_cfg;
    fuel_tank_cfg_temp.Fuel_Vehicle_Config_ViceTank= fuel_tank_aux_temp ; /*add it for P03/P05*/
    /*The diagnostic requirements have not been updated; the left side is used by default*/
    /*Add the position for Vconfig_v1.2 */
    if((fuel_tank_Tankportposition==0x1) ||(fuel_tank_Tankportposition==0x0))
    {
        fuel_tank_cfg_temp.Fuel_config_Tankportposition=0u;
    }
    else if (fuel_tank_Tankportposition==0x2)
    {
        fuel_tank_cfg_temp.Fuel_config_Tankportposition=1u;
    }
    else
    {
        fuel_tank_cfg_temp.Fuel_config_Tankportposition=0u;
    }
#endif
    return fuel_tank_cfg_temp;
}
/** 
 * [Fuel_Dual_Api_Get_Tank_Config : description]
 * @Author   shujunhua
 * @DateTime 2021/9/23-16:27:56
 * @param                             [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Dual_Api_Get_Tank_Config( void )
{
    uint8 index = (uint8)Fuel_Api_Tank_Vr_cfg_get();

    if((index>=(uint8)FUEL_VR_COMMMON_DUAL_SINGEL_N01 ) &&(index<= (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_MAX))
    {
        index =  (uint8)FUEL_VR_COMMMON_DUAL_SINGEL_MAX - index -1u;
    }
    else
    {
        index = 0u;
    }
    return (index);
}

/**********************************************************************************************************
*Function   : Fuel_RTE_Api_Get_Power_Mode_State                                                       	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-23                                                                                  *
**********************************************************************************************************/
boolean Fuel_Rte_Api_Get_Cconfig_Cfg(CconfigKind_400Bytes Lcal_config)
{
    boolean result=FALSE;
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
    return result;
	
}
/**********************************************************************************************************
*Function   : Fuel_RTE_Api_Get_Power_Mode_State                                                       	  *
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
uint8 Fuel_Rte_Api_Get_Power_Mode_State(void)
{
    boolean result=FALSE;
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut(); 
        if(FALSE != Fuel_Rte_Api_Get_Voltage_Mode_State())
        {
            if(SYSTEMSTATE_Cluster_ON == power_u8->ClusterState)
            {
                result= TRUE;
            }
            else
            {
                result=FALSE;
            }
        }
        else
        {
            result= FALSE;
        }
#endif
/*****************************************************************************/

#else

#endif    
 	
	return ( (result==TRUE)?1u:0u);
}
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Power_Mode_State_Is_Sleep                                              	  *
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
boolean Fuel_Rte_Api_Get_Power_Mode_State_Is_Sleep(void)
{
    boolean result=FALSE;
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }    
#endif 

#elif (defined(SWC_FUEL_ADAPT_P02))  
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01))  
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02))  
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03))  
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01))  
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
        SystemState_RecordType *power_u8;
        power_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
        if(SYSTEMSTATE_Cluster_OFF == power_u8->ClusterState)
        {
            result=TRUE;
        }
        else
        {
            result=FALSE;
        }
#endif
/*****************************************************************************/

#else

#endif    

    return result;
}
/**
 * [Fuel_Rte_Api_Get_Voltage_Mode_State : Check - 6.5 V <=V batt <=19V]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:41:20+0800
 * @param    void                     [description]
 * @return   uint8                    [1：6.5 V <=V batt <=19V]
 */
uint8 Fuel_Rte_Api_Get_Voltage_Mode_State (void)
{
    boolean result=FALSE;
#ifdef Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut
    SystemState_RecordType *voltage_u8;
	voltage_u8 = Rte_IRead_Common_Normal_10msMainFunction_tiSR_Power_Out_SystemStateOut();
	if((VOLTAGE_OUT_NORMAL == voltage_u8->s_PowerVoltage.state) ||\
       (VOLTAGE_OUT_LOWALARM == voltage_u8->s_PowerVoltage.state)||\
       (VOLTAGE_OUT_HIGHALARM == voltage_u8->s_PowerVoltage.state))
	{
		result= TRUE;
	}
	else
	{
		result=FALSE;
	}    
#endif 
    return ( (result==TRUE)?1u:0u);	
}

/**********************************************************************************************************
*Function   : Fuel_RTE_Api_Get_VehRunning_State                                                       	  *
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
uint8 Fuel_Rte_Api_Get_VehRunning_State (void)
{	
	uint8 vehrunning_status_temp = 0;	
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10UL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif	    
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif	    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif	   
#elif (defined(SWC_FUEL_ADAPT_P03)) 
 #ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif	   
#elif (defined(SWC_FUEL_ADAPT_P05)) 
 #ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)) )
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif	   
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif 

#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }  
#endif  

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }  
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /* > 0.5km/h exit fastfill mode*/
    /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
    if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
        s_SpeedoInfo_t speed_value_temp;
        (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
        /* > 0.5km/h exit fastfill mode*/
        /*@20210128:speed >= 0.2km/h exit fastfill mode,Speed module accuracy changed to 0.01*/
        if(speed_value_temp.RealSpeed >= (10uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(6)))
        {
            vehrunning_status_temp = 0;
        }
        else
        {
            vehrunning_status_temp = 1;
        }
#endif

/*****************************************************************************/

#else
    
#endif
    return vehrunning_status_temp;

}
/** 
 * [Fuel_Rte_Api_Get_VehHalt_State : Check SPD<=1KM/H ]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:30:33+0800
 * @param    void                     [description]
 * @return   uint8                    [0:SPD<=1KM/H]
 */
uint8 Fuel_Rte_Api_Get_VehHalt_State (void)
{	
	uint8 vehrunning_status_temp = 0;	
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <=(100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif     
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif     
#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif     
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif     
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif     
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif  
   
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif   

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element
    s_SpeedoInfo_t speed_value_temp;
    (void)Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(&speed_value_temp);
    /*RealSpeed:100==>1KM/H*/
    if(speed_value_temp.RealSpeed <= (100uL*Fuel_Api_Config_Data_NVM_Pkg_Get_Data(7)))
    {
        vehrunning_status_temp = 0;
    }
    else
    {
        vehrunning_status_temp = 1;
    }
#endif 
/*****************************************************************************/

#else
    
#endif

	return vehrunning_status_temp;
}

/** 
 * [Fuel_Rte_Api_Get_EngSpd_State : EngSpd ≥ 400rpm]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T14:32:25+0800
 * @param    void                     [description]
 * @return   uint8                    [1:EngSpd ≥ 400rpm]
 */
uint8 Fuel_Rte_Api_Get_EngSpd_State (void)
{
    uint8 result=0;
 
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif    
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif    
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
	(void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif   

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif  
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif  
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
    s_TachoInfo_t EngineRunningInfo;
    (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
    result= EngineRunningInfo.EngRunSts;
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Read_rpSR_SWCNormal_TachoInfo_Element
        s_TachoInfo_t EngineRunningInfo;
        (void)Rte_Read_rpSR_SWCNormal_TachoInfo_Element(&EngineRunningInfo); 
        result= EngineRunningInfo.EngRunSts;
#endif
/*****************************************************************************/


#else
    
#endif

	return result;
}
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_IFC_10S_Rate                                                           	  *
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
uint16 Fuel_Rte_Api_Get_IFC_10S_Rate (void)
{
    uint16	result=0;
   
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif    
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif    
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
   (void) Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif  
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif  

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element
    TC_MODULE_OUTPUT_DATA_STRUCT_RTE tc_Parament;
    (void)Rte_Read_rpSR_SWCNormal_TC_Module_Output_Data_Element(&tc_Parament);
    result =tc_Parament.u16IFC_Poc_For_Fuel_Calculate_Rate;
#endif 
/*****************************************************************************/

#else

#endif

	return result ;	
	
}

/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Get_Fuel_AD_Value                                                          	  *
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
uint16 Fuel_Rte_Api_Get_Fuel_AD_Value (uint8 fuel_ad_channel)
{
	uint32 fuel_ad_temp=0;	
	uint32 temp_ref_ad=0;	
	uint32 temp_ad_value=0;
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif

#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif

#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif

#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif

#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif

#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif   

#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif    

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }   
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
            {
                temp_ref_ad = temp_ad_value;
        
                if(0 == fuel_ad_channel)
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else if(1 == fuel_ad_channel) 
                {
                    if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                    {
                        fuel_ad_temp = temp_ad_value;
                    }
                    else
                    {
                        /* error value, keep last value */
                        fuel_ad_temp = 0xFFFF;
                    }
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                temp_ref_ad = 0xFFFF;
            }   
        
            if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
            else
            {
                fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
            }
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01))
#ifdef Rte_Call_IoHwAb_Interface_GetVoltage
        if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN, &temp_ad_value))
        {
            temp_ref_ad = temp_ad_value;
    
            if(0 == fuel_ad_channel)
            {
                if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN, &temp_ad_value))
                {
                    fuel_ad_temp = temp_ad_value;
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else if(1 == fuel_ad_channel) 
            {
                if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN, &temp_ad_value))
                {
                    fuel_ad_temp = temp_ad_value;
                }
                else
                {
                    /* error value, keep last value */
                    fuel_ad_temp = 0xFFFF;
                }
            }
            else
            {
                /* error value, keep last value */
                fuel_ad_temp = 0xFFFF;
            }
        }
        else
        {
            /* error value, keep last value */
            temp_ref_ad = 0xFFFF;
        }   
    
        if((temp_ref_ad == 0xFFFF) || (fuel_ad_temp == 0xFFFF))
        {
            /* error value, keep last value */
            fuel_ad_temp = 0xFFFF;
        }
        else
        {
            fuel_ad_temp = (fuel_ad_temp * 4095) / (temp_ref_ad);
        }
#endif 
/*****************************************************************************/

#else

#endif
 
	return ((uint16)fuel_ad_temp);
}

/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Set_Warning_Fuel                                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: 2 - FLASH, 1 - ON, 0 - OFF                                                                  *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Rte_Api_Set_Warning_Fuel(uint8 fuel_warning_set_status)
{
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif 
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif 

#elif (defined(SWC_FUEL_ADAPT_B06)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif     
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif     
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
   (void) Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif     
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif    
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif  

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Write_Sd_Fuel_Status_Fuel_Status 
    (void)Rte_Write_Sd_Fuel_Status_Fuel_Status(fuel_warning_set_status);       
#endif
/*****************************************************************************/


#else
    
#endif


	
}
/**********************************************************************************************************
*Function   : Fuel_Rte_Api_Set_Module_Data                                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void Fuel_Rte_Api_Set_Module_Data(FUEL_MODULE_OUTPUT_DATA_STRUCT fuel_set_module_data)
{

#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif 
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_B06)) 
 #ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif  

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
    (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
   (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef  Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element
   (void)Rte_Write_ppSR_SWCNormal_Fuel_Set_Module_Data_Element(&fuel_set_module_data);
#endif
/*****************************************************************************/
#else

#endif

	
}
/**********************************************************************************************************
*Function   : SWC_API_RTE_EOL_HardInput_For_Cluster                                                       *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-06-12                                                                                  *
**********************************************************************************************************/
void SWC_API_RTE_EOL_HardInput_For_Cluster(uint8 * data)
{
	uint8 eol_data[6] = {0};
	uint8 eol_data_temp_u8_h = 0;
	uint8 eol_data_temp_u8_l = 0;
	uint32 eol_data_temp_u32 = 0;
    uint16 u16fuel_ad_value = 0;
    
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

#elif (defined(SWC_FUEL_ADAPT_B06)) 

#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
         /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1	;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
          /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

#elif (defined(SWC_FUEL_ADAPT_A07)) 
	 if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
	 {
		 /* do nothing */
	 }
	 else
	 {
		 eol_data_temp_u8_h = 0;
	 }
	 
	 if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
	 {
		 if(300 >= eol_data_temp_u32)
		 {
			 eol_data_temp_u8_l = 0;
		 }
		 else
		 {
			 eol_data_temp_u8_l = 1;
		 }
	 }
	 else
	 {
		 eol_data_temp_u8_l = 0;
	 }	 
	 
	 eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
	 
	 if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
	 {
		 /* do nothing */
	 }
	 else
	 {
		 eol_data_temp_u8_h = 0;
	 }
	 
	 if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
	 {
		 /* do nothing */
	 }
	 else
	 {
		 eol_data_temp_u8_l = 0;
	 }
	 
	 eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
	 
	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
	 /*
	 if(0xFFFF != eol_data_temp_u32)
	 {
		 eol_data_temp_u32/=10;
	 }*/
	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
     if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
	 {
		 eol_data_temp_u32/=10;
	 }else{
         eol_data_temp_u32 = 0xFFFF;
     }
	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
	 
	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
	 /*
	 if(0xFFFF != eol_data_temp_u32)
	 {
		 eol_data_temp_u32/=10;
	 }*/
	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
     if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
	 {
		 eol_data_temp_u32/=10;
	 }else{
         eol_data_temp_u32 = 0xFFFF;
     }
	 eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
	 eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);

#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1	;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
          /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif


/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1	;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
          /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1	;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
          /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
         {
             if(300 >= eol_data_temp_u32)
             {
                 eol_data_temp_u8_l = 0;
             }
             else
             {
                 eol_data_temp_u8_l = 1	;
             }
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }   
     
         eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_h = 0;
         }
     
         if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
         {
             /* do nothing */
         }
         else
         {
             eol_data_temp_u8_l = 0;
         }
     
         eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
     
         eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
          /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
    	 eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
    	 eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
    	 
    	 eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
    	 /*
    	 if(0xFFFF != eol_data_temp_u32)
    	 {
    		 eol_data_temp_u32/=10;
    	 }*/
    	 u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
    	 if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
    	 {
    		 eol_data_temp_u32/=10;
    	 }else{
             eol_data_temp_u32 = 0xFFFF;
         }
         eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
         eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Call_IoHwAb_Interface_GetPin
          if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, &eol_data_temp_u8_h))
          {
              /* do nothing */
          }
          else
          {
              eol_data_temp_u8_h = 0;
          }
      
          if(E_OK == Rte_Call_IoHwAb_Interface_GetVoltage(RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN, &eol_data_temp_u32))
          {
              if(300 >= eol_data_temp_u32)
              {
                  eol_data_temp_u8_l = 0;
              }
              else
              {
                  eol_data_temp_u8_l = 1 ;
              }
          }
          else
          {
              eol_data_temp_u8_l = 0;
          }   
      
          eol_data[0] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
      
          if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, &eol_data_temp_u8_h))
          {
              /* do nothing */
          }
          else
          {
              eol_data_temp_u8_h = 0;
          }
      
          if(E_OK == Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, &eol_data_temp_u8_l))
          {
              /* do nothing */
          }
          else
          {
              eol_data_temp_u8_l = 0;
          }
      
          eol_data[1] = (eol_data_temp_u8_h << 4) + eol_data_temp_u8_l;
      
          eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(0);
           /*
          if(0xFFFF != eol_data_temp_u32)
          {
              eol_data_temp_u32/=10;
          }*/
          u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(0);
          if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
          {
              eol_data_temp_u32/=10;
          }else{
              eol_data_temp_u32 = 0xFFFF;
          }
          eol_data[2] = (uint8)((uint16)eol_data_temp_u32 >> 8);
          eol_data[3] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
          
          eol_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Value(1);
          /*
          if(0xFFFF != eol_data_temp_u32)
          {
              eol_data_temp_u32/=10;
          }*/
          u16fuel_ad_value = Fuel_Api_Get_Fuel_AD_Value(1);
          if( (u16fuel_ad_value>=FUEL_AD_MIN)&&(u16fuel_ad_value<=FUEL_AD_MAX)  )
          {
              eol_data_temp_u32/=10;
          }else{
              eol_data_temp_u32 = 0xFFFF;
          }
          eol_data[4] = (uint8)((uint16)eol_data_temp_u32 >> 8);
          eol_data[5] = (uint8)((uint16)eol_data_temp_u32 & (uint16)0xFF);
#endif
/*****************************************************************************/

#else

#endif  

 
	 (void)memcpy(data,eol_data,6);
}
/**********************************************************************************************************
*Function   : Fuel_Api_Update_can_publish                                                                 *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
static void Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlLowLmpSts(uint8 data)
{

#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif 
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif     
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif  

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
#endif

/*****************************************************************************/


#else
    
#endif


}

static void Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlInfo(uint8 data)
{

#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif     
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
 #ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif   
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif       
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif  


/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif
/*****************************************************************************/


#else
    
#endif


}
/** 
 * [Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlInfo : description]
 * @Author   shujunhua
 * @DateTime 2021/10/19-13:20:35
 * @param    data                     [description]
 */
static void Fuel_Api_Rte_CanOutputViaGateway_IP_FuelAuxLvlInfo(uint8 data)
{

#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
  //  (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif     
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
  //  (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
   // (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
 #ifdef Rte_Write_ppSR_SWCNormal_IP_FuelAuxLvlInfo_IP_FuelAuxLvlInfo
    (void)Rte_Write_ppSR_SWCNormal_IP_FuelAuxLvlInfo_IP_FuelAuxLvlInfo((uint8)data);    
#endif   
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
   // (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif       
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
   // (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo
       // (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);    
#endif

#else
    
#endif

}

static void Fuel_Api_Rte_CanOutputViaGateway_IP_FuelMainTankR(uint16 data)
{
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif      
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
 #ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
       (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif 

#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
       (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif 
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif 

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
        (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
       (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
       (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);    
#endif

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01))
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR
       (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);
#endif
/*****************************************************************************/



#else
    
#endif


}

static void Fuel_Api_Rte_CanOutputViaGateway_IP_FuelAuxTankR(uint16 data)
{
#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif 
#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif    
#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif 
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif 
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR
    (void)Rte_Write_Sd_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);   
#endif
/*****************************************************************************/

#else

#endif


}

void Fuel_Api_Update_can_publish(Fuel_IP_PUBLISH_ENUM type,uint32 data)
{  
	switch (type) 
		  {
		  case Fuel_IP_FuelLvlLowLmpSts:
			   Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data); /*Adjust the call interface to decouple*/
			   break;
		  case Fuel_IP_FuelLvlInfo:
		  	   Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlInfo((uint8)data);
			  break;
            case Fuel_IP_FuelLvlInfoAux:
		  	   Fuel_Api_Rte_CanOutputViaGateway_IP_FuelAuxLvlInfo((uint8)data); //tbd
			  break;
		  case Fuel_IP_FuelMainTankR:			  
			   Fuel_Api_Rte_CanOutputViaGateway_IP_FuelMainTankR((uint16)data);
			   break;
		  case Fuel_IP_FuelAuxTankR:
			   Fuel_Api_Rte_CanOutputViaGateway_IP_FuelAuxTankR((uint16)data);
			   break;
		  default :
               Fuel_Api_Rte_CanOutputViaGateway_IP_FuelLvlLowLmpSts((uint8)data);
			   break; 
		  }

}
/**********************************************************************************************************
*Function   : Fuel_Api_Open_Or_Short_Dtc_Status                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE																				          *
*                                                                                                         *
*Return 	: NONE                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-03                                                                                  *
**********************************************************************************************************/
void Fuel_Api_Open_Or_Short_Dtc_Status(FUEL_SENSOR_ERROR_ENUM index,uint32 status)
{ 

#if  (defined(SWC_FUEL_ADAPT_B03)) 
    if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }        
#elif (defined(SWC_FUEL_ADAPT_B02)) 
    if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
    if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
    if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }    
#elif (defined(SWC_FUEL_ADAPT_A07)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }       
#elif (defined(SWC_FUEL_ADAPT_P02)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D02)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
	if(FUEL_SENSOR1_OPEN == index)
    {  
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR1_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_OPEN == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus((uint8)status);
        #endif 
    }
    else if(FUEL_SENSOR2_SHORT == index)
    {   
        #ifdef Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus
    	(void)Rte_Call_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus((uint8)status);
        #endif 
    }
    else
    {
    	/* do nothing */
    }

/*****************************************************************************/

#else
    
#endif

	
}
/** 
 * [Fuel_SWC_API_RTE_Diag_Read_Fuel_Data : $22 -DID-FDC5 fuel data]
 * @Author   shujunhua
 * @DateTime 2021/5/5-T16:09:59+0800
 * @param    data                     [description]
 */
void Fuel_SWC_API_RTE_Diag_Read_Fuel_Data(uint8 * data)
{
	uint8 diag_read_data[9] = {0};
	uint8 diag_read_data_temp_u8_h = 0;
	uint8 diag_read_data_temp_u8_l = 0;
	uint32 diag_read_data_temp_u32 = 0;	
#if  (defined(SWC_FUEL_ADAPT_B03)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }    
#elif (defined(SWC_FUEL_ADAPT_B02)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }    
#elif (defined(SWC_FUEL_ADAPT_B06)) 
    
#elif (defined(SWC_FUEL_ADAPT_P03)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }    
#elif (defined(SWC_FUEL_ADAPT_P05)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }    
#elif (defined(SWC_FUEL_ADAPT_A07)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }        
#elif (defined(SWC_FUEL_ADAPT_P02)) 
    if((Fuel_Api_tank_cfg_get()==Fuel_MULTI_TYPE) || (Fuel_Api_tank_cfg_get()==Fuel_DUAL_SINGLE_TYPE))
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    } 

/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
    if(Fuel_MULTI_TYPE==Fuel_Api_tank_cfg_get())
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    } 
#elif (defined(SWC_FUEL_ADAPT_D02)) 
    if(Fuel_MULTI_TYPE==Fuel_Api_tank_cfg_get())
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    } 
#elif (defined(SWC_FUEL_ADAPT_D03)) 
    if(Fuel_MULTI_TYPE==Fuel_Api_tank_cfg_get())
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    } 


/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01))
    if(Fuel_MULTI_TYPE==Fuel_Api_tank_cfg_get())
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);

        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(1);//Fuel_Api_Get_Fuel_Resisitor_Value(1);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[2] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[3] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = Fuel_Api_Module_Flps_Aux_Fuel_Level();
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();        
        
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    }
    else
    {
        diag_read_data_temp_u32 = Fuel_Api_Get_Fuel_Resisitor_Diag(0);//Fuel_Api_Get_Fuel_Resisitor_Value(0);
        if(0xFFFF != diag_read_data_temp_u32)
        {
            diag_read_data_temp_u32/=10;
        }
        diag_read_data[0] = (uint8)((uint16)diag_read_data_temp_u32 >> 8);
        diag_read_data[1] = (uint8)((uint16)diag_read_data_temp_u32 & (uint16)0xFF);
        diag_read_data[2] = 0;
        diag_read_data[3] = 0;
        diag_read_data[4] = Fuel_Api_Module_Flps_Fuel_Level();
        diag_read_data[5] = 0;
        diag_read_data[6] = Fuel_Api_Module_Fuel_Level_Volum_Read();           
        diag_read_data_temp_u8_h = Fuel_Api_Module_Fast_Fill_Loss_Status();
        diag_read_data_temp_u8_l = Fuel_Api_Current_Module_Status();
        diag_read_data[7] = (diag_read_data_temp_u8_h << 2) + diag_read_data_temp_u8_l;
        diag_read_data[8] = Fuel_Api_Current_Module_Ref_Fuel_Level();
    } 
/*****************************************************************************/

#else
    
#endif
	(void)memcpy(data,diag_read_data,9);
}

/**********************************************************************************************************
*Function   : Fuel_Module_Rte_Coldinit_Warminit_Flag                                                  	  *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: NONE													          							  *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-11-17                                                                                  *
**********************************************************************************************************/
boolean Fuel_Module_Rte_Coldinit_Warminit_Flag (void)
{
    boolean warn_flag = FALSE;

#if  (defined(SWC_FUEL_ADAPT_B03)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
    {
        warn_flag = FALSE;
    }
#endif 

#elif (defined(SWC_FUEL_ADAPT_B02)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
        {
            warn_flag = FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_B06)) 

#elif (defined(SWC_FUEL_ADAPT_P03)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
        {
            warn_flag = FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_P05)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
        {
            warn_flag = FALSE;
        }
#endif

#elif (defined(SWC_FUEL_ADAPT_A07)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
        {
            warn_flag = FALSE;
        }
#endif
#elif (defined(SWC_FUEL_ADAPT_P02)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
        if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
        {
            warn_flag = FALSE;
        }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D01)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
    {
        warn_flag = FALSE;
    }
#endif

/*****************************************************************************/

#elif (defined(SWC_FUEL_ADAPT_D02)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
    {
        warn_flag = FALSE;
    }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_D03)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
    {
        warn_flag = FALSE;
    }
#endif
/*****************************************************************************/
#elif (defined(SWC_FUEL_ADAPT_P01)) 
#ifdef Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element
    if(E_OK != Rte_Read_rcSR_SWCNormal_BswM_Warm_Reset_Element(&warn_flag))
    {
        warn_flag = FALSE;
    }
#endif
/*****************************************************************************/
#else

#endif
	return warn_flag;
}

uint32 Fuel_Module_Rte_Diag_Dtc_Counter(void)
{

    uint32 result = 0;
    uint32 dtc_clear_flag_count=0;
#if  (defined(SWC_FUEL_ADAPT_B03))
#ifdef Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter
    Rte_Read_rpSR_SWCNormal_DiagMonitorReInitFlag_ChangeCounter(&dtc_clear_flag_count);
#endif 
       
#elif (defined(SWC_FUEL_ADAPT_B02))

#elif (defined(SWC_FUEL_ADAPT_P03))

#elif (defined(SWC_FUEL_ADAPT_P05))

#elif (defined(SWC_FUEL_ADAPT_A07))

#elif (defined(SWC_FUEL_ADAPT_P02))

#elif (defined(SWC_FUEL_ADAPT_D01))

#elif (defined(SWC_FUEL_ADAPT_D02))

#elif (defined(SWC_FUEL_ADAPT_D03))

#elif (defined(SWC_FUEL_ADAPT_P01))

#else

#endif
    result =dtc_clear_flag_count;
return result;

}

/*************************************************************************  
 * [Fuel_Api_Rte_Get_Damp_run_fuelup : description]
 * @Author   GW0018945
 * @DateTime 2021/9/24
 * @param    void    
 * @return   uint16
 *[description] :TBD 
 *************************************************************************/
uint16 Fuel_Api_Rte_Get_Damp_run_fuelup(void)
{
    uint16 damp_run_fuelup_temp = 400;/* 0.04L/S */
#if  (defined(SWC_FUEL_ADAPT_B03)) 
    damp_run_fuelup_temp = 400;   
#elif (defined(SWC_FUEL_ADAPT_B02)) 
    damp_run_fuelup_temp = 400;   
#elif (defined(SWC_FUEL_ADAPT_P03)) 
    damp_run_fuelup_temp = 400/2;           
#elif (defined(SWC_FUEL_ADAPT_P05)) 
    damp_run_fuelup_temp = 400/2;   
#elif (defined(SWC_FUEL_ADAPT_A07)) 
    damp_run_fuelup_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D01))
    damp_run_fuelup_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D02))
    damp_run_fuelup_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D03))
    damp_run_fuelup_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P02))
    damp_run_fuelup_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P01))
    damp_run_fuelup_temp = 400;
#else
        
#endif  
return damp_run_fuelup_temp;
}

/*************************************************************************  
 * [Fuel_Api_Rte_Get_Damp_run_fueldown : description]
 * @Author   GW0018945
 * @DateTime 2021/9/24
 * @param    void    
 * @return   uint16
 *[description] :TBD 
 *************************************************************************/
uint16 Fuel_Api_Rte_Get_Damp_run_fueldown(void)
{
    uint16 damp_run_fueldown_temp = 400;/* 0.04L/S */
#if  (defined(SWC_FUEL_ADAPT_B03))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_B02))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P03))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P05))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_A07))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P02))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D01))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D02))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_D03))
    damp_run_fueldown_temp = 400;
#elif (defined(SWC_FUEL_ADAPT_P01))
    damp_run_fueldown_temp = 400;

#else

#endif
return damp_run_fueldown_temp;
}

/*************************************************************************  
 * [Fuel_Api_Rte_Get_ZSS_Delta_A : description]
 * @Author   GW0018945
 * @DateTime 2021/9/24
 * @param    void    
 * @return   uint16
 *[description] : for Keyoff_ref and ZSS_ref 5S minimum and maximum value difference for reference 
 *************************************************************************/
uint16 Fuel_Api_Rte_Get_Ref_Delta_A(void)
{
    uint16 ref_delta_temp = 3730;/* 0.04L/S */
#if  (defined(SWC_FUEL_ADAPT_B03))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_B02))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_P03))
    ref_delta_temp = 3730; 
#elif (defined(SWC_FUEL_ADAPT_P05))
    ref_delta_temp = 8128;
#elif (defined(SWC_FUEL_ADAPT_A07))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_P02))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_D01))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_D02))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_D03))
    ref_delta_temp = 3730;
#elif (defined(SWC_FUEL_ADAPT_P01))
    ref_delta_temp = 3730;
#else

#endif
return ref_delta_temp;
}
/** 
 * [Fuel_Api_Rte_Get_Oil_Switch : description]
 * @Author   shujunhua
 * @DateTime 2021/10/28-13:10:22
 * @param    void                     [description]
 * @return   uint8                    [description]
 */
uint8 Fuel_Api_Rte_Get_Oil_Switch(void)
{
    uint8 OilBoxSplySts = 0;/* 0.04L/S */
#if (defined(SWC_FUEL_ADAPT_P05))
    uint8 can_node_status = COMEX_ERROR_PARAM;
#endif
    uint8 result =0;
#if  (defined(SWC_FUEL_ADAPT_B03))
    
#elif (defined(SWC_FUEL_ADAPT_B02))
     
#elif (defined(SWC_FUEL_ADAPT_P03))
             
#elif (defined(SWC_FUEL_ADAPT_P05))
   #ifdef COMEX_SIGNAL_RX_OILBOXSPLYSTS
        can_node_status = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OILBOXSPLYSTS, (uint8 *)&OilBoxSplySts, (uint8)sizeof(OilBoxSplySts));
        if(((can_node_status&COMEX_ERROR_PARAM) != COMEX_ERROR_PARAM)&&\
               ((can_node_status&COMEX_NEVER_RECEIVED) != COMEX_NEVER_RECEIVED)&&\
               ((can_node_status&COMEX_MAX_AGE_EXCEEDED) != COMEX_MAX_AGE_EXCEEDED))
        {
           result = OilBoxSplySts;
        }
        else
        {
           result= 0;
        }
   #endif
#elif (defined(SWC_FUEL_ADAPT_A07))
#elif (defined(SWC_FUEL_ADAPT_P02))
#elif (defined(SWC_FUEL_ADAPT_D01))
#elif (defined(SWC_FUEL_ADAPT_D02))
#elif (defined(SWC_FUEL_ADAPT_D03))
#elif (defined(SWC_FUEL_ADAPT_P01))

#else
#endif
    return result;
}


#define SWC_FUEL_STOP_SEC_CODE
#include "SWC_Fuel_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

/**********************************************************************************************************
**
**  Revision:   1.0  
**
**  2020/06/02     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

