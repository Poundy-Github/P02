/**********************************************************************************************************************
 *  Copyright (C) 2020 GWM Automotive Inc.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *  The code contains GWM Confidential Proprietary Information.
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*                 File:  IPC_ClusterApp.h
*            Generator:  IPC Code Generator V1.3.0
*     Description file:  IPC_SOC.h.tem
*          Description:  IPC group ClusterApp  header file
*               Author:  IPC Code Generator V1.3.0
*********************************************************************************************************************/

#ifndef IPC_CLUSTERAPP_H
#define IPC_CLUSTERAPP_H

#include "IPC_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Group id */
#define IPC_GROUP_CLUSTERAPP_ID                                                  (13u)

/* MCU to SOC Message major id */
#define IPC_M2S_CLUSTERAPP_MSGMAJOR_APP_ID                                       (0u)
#define IPC_M2S_CLUSTERAPP_MSGMAJOR_SYSTEM_ID                                    (1u)
#define IPC_M2S_CLUSTERAPP_MSGMAJOR_CANADAPT_ID                                  (2u)
/* MCU to SOC Message sub id */
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_ID                               (0u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_ID                               (2u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_ID                                     (3u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_ID                                     (4u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_ID                                    (6u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_ID                                   (7u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_ID                            (8u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_ID                                    (9u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_ID                                  (10u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_ID                                   (11u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_ID                                 (12u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_ID                             (13u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_ID                           (14u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_ID                              (18u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_ID                                 (19u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_ID                               (20u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_ID                               (21u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_ID                                 (22u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_ID                               (23u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_ID                            (24u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_ID                             (25u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_ID                        (0u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_ID                           (1u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_ID                         (3u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_ID                 (5u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_ID                         (6u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_ID              (7u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_ID                     (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_ID                           (0u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_ID                           (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_ID                           (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_ID                           (3u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_ID                           (4u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_ID                           (5u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_ID                            (6u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_ID                          (7u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_ID                            (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_ID                        (9u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_ID                           (10u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_ID                       (11u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_ID                        (12u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_ID                        (13u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_ID                        (14u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_ID                        (15u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_ID                        (16u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_ID                         (17u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_ID                        (18u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_ID                        (19u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_ID                           (20u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_ID                           (21u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_ID                     (22u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_ID                          (23u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_ID                          (24u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_ID                        (25u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_ID                         (26u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_ID                       (27u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_ID                         (28u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_ID                           (29u)
/* MCU to SOC Message sub length */
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TT_MODULE_LENGTH                           (92u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_MODULE_LENGTH                           (150u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_ODO_LENGTH                                 (6u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_SIA_LENGTH                                 (6u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TPMS_LENGTH                                (16u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_CHIME_LENGTH                               (12u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TRIPCOMPUTER_LENGTH                        (41u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_FUEL_LENGTH                                (26u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_SPEEDO_LENGTH                              (19u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TACHO_LENGTH                               (22u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_COOLANT_LENGTH                             (13u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUSETTING_LENGTH                         (23u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_TCCLEARRESULT_LENGTH                       (1u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_CONFIGDATA_LENGTH                          (93u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_VCONFIG_LENGTH                             (9u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_MENUTHEME_LENGTH                           (8u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_DRIVEMODE_LENGTH                           (6u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_WN_DATA_LENGTH                             (5u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_LENGTH                           (16u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_NEWENERGY_EV_LENGTH                        (24u)
#define IPC_M2S_CLUSTERAPP_APP_MSGSUB_OFFROADINFO_LENGTH                         (10u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_BOOTCONDITION_LENGTH                    (7u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_ADASCONFIG_LENGTH                       (2u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_CLUSTERPOWER_LENGTH                     (3u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_COMMONAPPMSGUPLOADED_LENGTH             (1u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_IPCDEBUGTEST_LENGTH                     (1u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_INTERFACEAPPMSGUPLOADED_LENGTH          (1u)
#define IPC_M2S_CLUSTERAPP_SYSTEM_MSGSUB_GAUGEMSGUPLOADED_LENGTH                 (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA3_244_LENGTH                       (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_EEM1_2A8_LENGTH                       (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_145_LENGTH                       (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP2_137_LENGTH                       (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HUD1_325_LENGTH                       (4u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM3_371_LENGTH                       (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CSA2_A1_LENGTH                        (4u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM16_2D4_LENGTH                      (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AC2_385_LENGTH                        (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM_PT6_290_LENGTH                    (4u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ABM2_245_LENGTH                       (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_RSDS_FD1_16F_LENGTH                   (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD5_19F_LENGTH                    (44u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD6_222_LENGTH                    (8u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD2_2AB_LENGTH                    (44u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD2_23D_LENGTH                    (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_AEB_FD2_227_LENGTH                    (12u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_CR_FD1_15E_LENGTH                     (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_IFC_FD3_2CF_LENGTH                    (10u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ACC_FD3_2B4_LENGTH                    (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM1_319_LENGTH                       (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM3_345_LENGTH                       (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_T_BOX_FD10_2F0_LENGTH                 (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ECM24_350_LENGTH                      (4u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_BCM12_238_LENGTH                      (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_F_PBOX1_19B_LENGTH                    (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_L2_304_LENGTH                     (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_VCU_FD41_2D6_LENGTH                   (2u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_HCM_R2_330_LENGTH                     (1u)
#define IPC_M2S_CLUSTERAPP_CANADAPT_MSGSUB_ESP1_149_LENGTH                       (1u)
/* SOC to MCU Message major id */
#define IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID                                (0u)
#define IPC_S2M_CLUSTERAPP_MSGMAJOR_QNX_ID                                       (1u)
/* SOC to MCU Message sub id */
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_ID                            (0u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_ID                         (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_ID                       (13u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_ID                        (2u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_ID                          (3u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_ID                        (4u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_ID                   (5u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_ID                      (6u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_ID                           (10u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_ID                (11u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_ID                     (12u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_ID                      (14u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_ID                 (15u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_ID                        (16u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_ID                        (17u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_ID                         (18u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_ID                      (19u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_ID                              (0u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_ID                              (1u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_ID                           (2u)
/* SOC to MCU Message sub length */
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_LENGTH                        (10u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_LENGTH                     (6u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_LENGTH                   (4u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_LENGTH                    (2u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_LENGTH                      (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_LENGTH                    (5u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_LENGTH               (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_LENGTH                  (3u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_LENGTH                       (4u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_LENGTH            (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_LENGTH                 (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_LENGTH                  (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_LENGTH             (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_LENGTH                    (8u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_LENGTH                    (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MIAOCALL_LENGTH                     (1u)
#define IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_LENGTH                  (3u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_BOOTSTATUS_LENGTH                          (1u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_ADASCONFIG_LENGTH                          (1u)
#define IPC_S2M_CLUSTERAPP_QNX_MSGSUB_SETADASCONFIG_LENGTH                       (2u)
/* Group: : ClusterApp */
/* Message Major: APP */
/* Message Sub: TT_Module */
typedef struct
{
    union
    {
        uint32_t u32Telltales_status[23];
        struct
        {
            /*1.2 发动机系统故障报警灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EngineSysFault_Data_selfcheck          :1;
            /*1.2 发动机系统故障报警灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EngineSysFault_Data                    :3;
            /*1.4 发动机维修指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EngineFix_Data_selfcheck               :1;
            /*1.4 发动机维修指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EngineFix_Data                         :3;
            /*1.6~1.11 定速巡航指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t CruiseControl_Data_selfcheck           :1;
            /*1.6~1.11 定速巡航指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CruiseControl_Data                     :3;
            /*1.5 发动机水温高指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EngineHighTemp_Data_selfcheck          :1;
            /*1.5 发动机水温高指示灯- 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz  5:0.5hz  6~7 :reserve*/
            uint32_t EngineHighTemp_Data                    :3;
            /*1.6~1.11自适应巡航工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Enable_Data_selfcheck              :1;
            /*1.6~1.11自适应巡航工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Enable_Data                        :3;
            /*1.6~1.11自适应巡航未工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Disable_Data_selfcheck             :1;
            /*1.6~1.11自适应巡航未工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Disable_Data                       :3;
            /*1.6~1.11自适应巡航故障指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Fault_Data_selfcheck               :1;
            /*1.6~1.11自适应巡航故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Fault_Data                         :3;
            /*1.6~1.11智能巡航工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Enable_Data_selfcheck              :1;
            /*1.6~1.11智能巡航工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Enable_Data                        :3;
            /*1.6~1.11智能巡航未工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Disable_Data_selfcheck             :1;
            /*1.6~1.11智能巡航未工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Disable_Data                       :3;
            /*1.6~1.11智能巡航故障指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Fault_Data_selfcheck               :1;
            /*1.6~1.11智能巡航故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Fault_Data                         :3;
            /*1.12智能启停工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t SS_Enable_Data_selfcheck               :1;
            /*1.12智能启停工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SS_Enable_Data                         :3;
            /*1.12智能启停故障指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t SS_Fault_Data_selfcheck                :1;
            /*1.12智能启停故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SS_Fault_Data                          :3;
            /*1.14~1.15蓄电池充放电指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t BatteryCharge_Data_selfcheck           :1;
            /*1.14~1.15蓄电池充放电指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t BatteryCharge_Data                     :3;
            /*1.18机油压力低指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LowFuelPress_Data_selfcheck            :1;
            /*1.18机油压力低指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LowFuelPress_Data                      :3;
            /*1.19自动驻车工作指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t AutoPark_Enable_Data_selfcheck         :1;
            /*1.19自动驻车工作指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AutoPark_Enable_Data                   :3;
            /*1.19自动驻车故障指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t AutoPark_Fault_Data_selfcheck          :1;
            /*1.19自动驻车故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AutoPark_Fault_Data                    :3;
            /*1.23陡降指示灯指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t HSD_Data_selfcheck                     :1;
            /*1.23陡降指示灯指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSD_Data                               :3;
            /*1.24电动驻车报警CHINA指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EPB_Enable_CH_Data_selfcheck           :1;
            /*1.24电动驻车报警CHINA指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPB_Enable_CH_Data                     :3;
            /*1.24电动驻车报警US指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EPB_Enable_US_Data_selfcheck           :1;
            /*1.24电动驻车报警US指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPB_Enable_US_Data                     :3;
            /*1.26动态驻车报警CHINA指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t DPB_Enable_CH_Data_selfcheck           :1;
            /*1.26动态驻车报警CHINA指示灯 - 指示灯状态                                      Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DPB_Enable_CH_Data                     :3;
            /*1.27动态驻车故障US指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t DPB_Enable_US_Data_selfcheck           :1;
            /*1.27动态驻车故障US指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DPB_Enable_US_Data                     :3;
            /*1.28Ibooster指示灯黄色CHINA - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Yellow_CH_Data_selfcheck      :1;
            /*1.28Ibooster指示灯黄色CHINA - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Yellow_CH_Data                :3;
            /*1.28Ibooster指示灯红色CHINA - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Red_CH_Data_selfcheck         :1;
            /*1.28Ibooster指示灯红色CHINA - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Red_CH_Data                   :3;
            /*1.28Ibooster指示灯黄色US - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Yellow_US_Data_selfcheck      :1;
            /*1.28Ibooster指示灯黄色US - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Yellow_US_Data                :3;
            /*1.28Ibooster指示灯红色US - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Red_US_Data_selfcheck         :1;
            /*1.28Ibooster指示灯红色US - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Red_US_Data                   :3;
            /*1.29120KM/H超速报警指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_120KMH_Data_selfcheck              :1;
            /*1.29120KM/H超速报警指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_120KMH_Data                        :3;
            /*1.31~1.32前雾灯指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Front_Fog_Data_selfcheck               :1;
            /*1.31~1.32前雾灯指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Front_Fog_Data                         :3;
            /*1.33~1.34后雾灯指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Rear_Fog_Data_selfcheck                :1;
            /*1.33~1.34后雾灯指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Rear_Fog_Data                          :3;
            /*1.35~1.39远光灯指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t High_Beam_Data_selfcheck               :1;
            /*1.35~1.39远光灯指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t High_Beam_Data                         :3;
            /*1.40~1.41左转向灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Turn_Left_Data_selfcheck               :1;
            /*1.40~1.41左转向灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Turn_Left_Data                         :3;
            /*1.42~1.43右转向灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Turn_Right_Data_selfcheck              :1;
            /*1.42~1.43右转向灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Turn_Right_Data                        :3;
            /*1.44~1.45位置灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Position_Data_selfcheck                :1;
            /*1.44~1.45位置灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Position_Data                          :3;
            /*1.46~1.47灯光总开关指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LightSwitch_Data_selfcheck             :1;
            /*1.46~1.47灯光总开关指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LightSwitch_Data                       :3;
            /*1.48~1.49拖车转向灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Trailer_Data_selfcheck                 :1;
            /*1.48~1.49拖车转向灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Trailer_Data                           :3;
            /*1.50-1.51门开报警指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t DoorOpen_Data_selfcheck                :1;
            /*1.50-1.51门开报警指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DoorOpen_Data                          :3;
            /*1.52胎压报警指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t TPMS_Data_selfcheck                    :1;
            /*1.52胎压报警指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TPMS_Data                              :3;
            /*1.53电动助力转向短暂性性故障指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t EPS_Yellow_Error_Data_selfcheck        :1;
            /*1.53电动助力转向短暂性性故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPS_Yellow_Error_Data                  :3;
            /*1.55安全带未系指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Seat_Belt_Data_selfcheck               :1;
            /*1.55安全带未系指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Seat_Belt_Data                         :3;
            /*1.57~1.59变速器过热指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Trans_OverHeat_Data_selfcheck          :1;
            /*1.57~1.59变速器过热 指示灯- 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Trans_OverHeat_Data                    :3;
            /*1.60~1.62自动远光灯黄色 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Auto_Yellow_Data_selfcheck             :1;
            /*1.60~1.62自动远光灯黄色 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Auto_Yellow_Data                       :3;
            /*1.60~1.62自动远光灯绿色 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Auto_Green_Data_selfcheck              :1;
            /*1.60~1.62自动远光灯绿色 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Auto_Green_Data                        :3;
            /*1.63低燃油报警指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LowFuel_Data_selfcheck                 :1;
            /*1.63低燃油报警 指示灯- 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LowFuel_Data                           :3;
            /*1.65前方碰撞报警指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t FCW_Enable_Data_selfcheck              :1;
            /*1.65前方碰撞报警指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FCW_Enable_Data                        :3;
            /*1.66 LDW 工作指示灯 - 工作 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LDW_Enable_Data_selfcheck              :1;
            /*1.66 LDW 工作指示灯 - 工作 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LDW_Enable_Data                        :3;
            /*1.66 LDW 工作指示灯 - 故障 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LDW_Error_Data_selfcheck               :1;
            /*1.66 LDW 工作指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LDW_Error_Data                         :3;
            /*1.67 LKA 工作指示灯 - 开启 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LKA_Enable_Data_selfcheck              :1;
            /*1.67 LKA 工作指示灯 - 开启 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LKA_Enable_Data                        :3;
            /*1.67 LKA 工作指示灯 - 故障 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LKA_Error_Data_selfcheck               :1;
            /*1.67 LKA 工作指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LKA_Error_Data                         :3;
            /*1.68 LCK 工作指示灯 - 开启 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LCK_Enable_Data_selfcheck              :1;
            /*1.68 LCK 工作指示灯 - 开启 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LCK_Enable_Data                        :3;
            /*1.68 LCK 工作指示灯 - 故障 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t LCK_Error_Data_selfcheck               :1;
            /*1.68 LCK 工作指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LCK_Error_Data                         :3;
            /*1.69~1.70 READY指示灯 - 自检标志位
            self check: 0~no self check ;1~self check*/
            uint32_t Ready_Light_Data_selfcheck             :1;
            /*1.69~1.70 READY指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ready_Light_Data                       :3;
            /*1.71 EV指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t EV_Indicator_Data_selfcheck            :1;
            /*1.71 EV 指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EV_Indicator_Data                      :3;
            /*1.72~1.73 动力电池故障指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t PBF_Warning_Data_selfcheck             :1;
            /*1.72~1.73 动力电池故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t PBF_Warning_Data                       :3;
            /*1.75 充电状态指示灯 - 绿色 - 自检状态
            self check: 0~no self check ;1~self check
            1.105 电池组充电指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_Green_Data_selfcheck          :1;
            /*1.75 充电状态指示灯 - 绿色 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve
            1.105 电池组充电指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_Green_Data                    :3;
            /*1.75 充电状态指示灯(PHEV/HEV) - 红色 - 自检状态
            1.111充放电连接指示灯(EV)- 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_Red_Data_selfcheck            :1;
            /*1.75 充电状态指示灯(PHEV/HEV) -红色-指示灯状态
            1.111充放电连接指示灯(EV)- 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_Red_Data                      :3;
            /*1.75 充电状态指示灯 - 轻微故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_E_Yellow_Data_selfcheck       :1;
            /*1.75 充电状态指示灯 - 轻微故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_E_Yellow_Data                 :3;
            /*1.75 充电状态指示灯 - 严重故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_E_Red_Data_selfcheck          :1;
            /*1.75 充电状态指示灯 - 严重故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_E_Red_Data                    :3;
            /*1.82 次要报警提示符 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Secondary_Warning_Data_selfcheck       :1;
            /*1.82 次要报警提示符 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Secondary_Warning_Data                 :3;
            /*1.83 重要报警提示符 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Major_Warning_Data_selfcheck           :1;
            /*1.83 重要报警提示符 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Major_Warning_Data                     :3;
            /*1.85~1.86 驻车指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Parking_Data_selfcheck                 :1;
            /*1.85~1.86 驻车指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Parking_Data                           :3;
            /*1.87 制动能量回收故障指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t RBS_Data_selfcheck                     :1;
            /*1.87 制动能量回收故障指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RBS_Data                               :3;
            /*1.118 发动机预热指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Engine_Warmup_Data_selfcheck           :1;
            /*1.118 发动机预热指示灯- 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Engine_Warmup_Data                     :3;
            /*1.116 刹车片磨损指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t BrakePad_Worn_Data_selfcheck           :1;
            /*1.116 刹车片磨损指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t BrakePad_Worn_Data                     :3;
            /*1.89 CCO功能指示灯 - 功能激活 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Active_Data_selfcheck              :1;
            /*1.89 CCO功能指示灯 - 功能激活 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Active_Data                        :3;
            /*1.89 CCO功能指示灯 - 功能待机 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Standby_Data_selfcheck             :1;
            /*1.89 CCO功能指示灯 - 功能待机 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Standby_Data                       :3;
            /*1.89 CCO功能指示灯 - 功能故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Inactive_Data_selfcheck            :1;
            /*1.89 CCO功能指示灯 - 功能故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Inactive_Data                      :3;
            /*1.90 前桥电子差速锁状态指示灯 - 工作 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t FEDL_Active_Data_selfcheck             :1;
            /*1.90 前桥电子差速锁状态指示灯 -工作 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FEDL_Active_Data                       :3;
            /*1.90 前桥电子差速锁状态指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t FEDL_Inactive_Data_selfcheck           :1;
            /*1.90 前桥电子差速锁状态指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FEDL_Inactive_Data                     :3;
            /*1.91 后桥电子差速锁状态指示灯 - 工作 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t REDL_Active_Data_selfcheck             :1;
            /*1.91 后桥电子差速锁状态指示灯 - 工作 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t REDL_Active_Data                       :3;
            /*1.91 后桥电子差速锁状态指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t REDL_Inactive_Data_selfcheck           :1;
            /*1.91 后桥电子差速锁状态指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t REDL_Inactive_Data                     :3;
            /*1.93 高速单车道自动驾驶功能指示灯 - 待激活 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Standby_Data_selfcheck            :1;
            /*1.93 高速单车道自动驾驶功能指示灯 - 待激活 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Standby_Data                      :3;
            /*1.93 高速单车道自动驾驶功能指示灯 - 激活 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Active_Data_selfcheck             :1;
            /*1.93 高速单车道自动驾驶功能指示灯 - 激活 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Active_Data                       :3;
            /*1.93 高速单车道自动驾驶功能指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Error_Data_selfcheck              :1;
            /*1.93 高速单车道自动驾驶功能指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Error_Data                        :3;
            /*1.99 高速自动变道辅助指示灯 - 开关 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Switch_Data_selfcheck             :1;
            /*1.99 高速自动变道辅助指示灯 - 开关 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Switch_Data                       :3;
            /*1.99 高速自动变道辅助指示灯 - 激活 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Active_Data_selfcheck             :1;
            /*1.99 高速自动变道辅助指示灯 - 激活 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Active_Data                       :3;
            /*1.99 高速自动变道辅助指示灯 - 待激活 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Standby_Data_selfcheck            :1;
            /*1.99 高速自动变道辅助指示灯 - 待激活 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Standby_Data                      :3;
            /*1.99 高速自动变道辅助指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Error_Data_selfcheck              :1;
            /*1.99 高速自动变道辅助指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Error_Data                        :3;
            /*1.96 并线辅助指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t AUX_Data_selfcheck                     :1;
            /*1.96 并线辅助指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AUX_Data                               :3;
            /*1.97 倒车侧向警告系统指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t RSW_Data_selfcheck                     :1;
            /*1.97 倒车侧向警告系统指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RSW_Data                               :3;
            /*1.98 侧后辅助系统 指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t SAS_Error_Data_selfcheck               :1;
            /*1.98 侧后辅助系统 指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SAS_Error_Data                         :3;
            /*1.98 侧后辅助系统 指示灯 - 受限 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t SAS_Limit_Data_selfcheck               :1;
            /*1.98 侧后辅助系统 指示灯 - 受限 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SAS_Limit_Data                         :3;
            /*1.100 转向辅助功能指示灯 - 开启 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Open_Data_selfcheck        :1;
            /*1.100 转向辅助功能指示灯 - 开启 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Open_Data                  :3;
            /*1.100 转向辅助功能指示灯 - 工作 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Work_Data_selfcheck        :1;
            /*1.100 转向辅助功能指示灯 - 工作 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Work_Data                  :3;
            /*1.100 转向辅助功能指示灯 - 故障 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Error_Data_selfcheck       :1;
            /*1.100 转向辅助功能指示灯 - 故障 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Error_Data                 :3;
            /*1.78/1.103/1.120/1.121 声音提示系统指示灯(PHEV) - 红色 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Sound_Reminder_Red_Data_selfcheck      :1;
            /*1.78/1.103/1.120/1.121  声音提示系统指示灯 - 红色 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Sound_Reminder_Red_Data                :3;
            /*1.78/1.103/1.120/1.121  声音提示系统指示灯 - 黄色 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Sound_Reminder_Yellow_Data_selfcheck   :1;
            /*1.78/1.103/1.120/1.121  声音提示系统指示灯 - 黄色 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Sound_Reminder_Yellow_Data             :3;
            /*1.105 现不使用*/
            uint32_t BatteryPack_Charge_Data_selfcheck      :1;
            /*1.105 现不使用*/
            uint32_t BatteryPack_Charge_Data                :3;
            /*1.109 蓄电池切断指示灯 - 指示灯状态
            self check: 0~no self check ;1~self check*/
            uint32_t Battery_Off_Data_selfcheck             :1;
            /*1.109 蓄电池切断指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Battery_Off_Data                       :3;
            /*1.112 动力电池电量低 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Low_Battery_Data_selfcheck             :1;
            /*1.112 动力电池电量低 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Low_Battery_Data                       :3;
            /*1.101 RSCA OFF 指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t RSCA_Off_Data_selfcheck                :1;
            /*1.101 RSCA OFF 指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RSCA_Off_Data                          :3;
            /*1.113 2H/4H/4L指示灯 - 2H - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TT_2H_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4L指示灯 - 2H - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_2H_Indicator_Data                   :3;
            /*1.113 2H/4H/4L指示灯 - 4H - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TT_4H_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4L指示灯 - 4H - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_4H_Indicator_Data                   :3;
            /*1.113 2H/4H/4L指示灯 - 4L - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TT_4L_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4L指示灯 - 4L - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_4L_Indicator_Data                   :3;
            /*1.79~1.81 单踏板指示灯 - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Single_Pedal_Data_selfcheck            :1;
            /*1.79~1.81 单踏板指示灯 - 指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Single_Pedal_Data                      :3;
            /*1.92 TSR 限速标志指示灯-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_Speed_Limit_Data_selfcheck         :1;
            /*1.92 TSR 限速标志指示灯-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_Speed_Limit_Data                   :3;
            /*1.92 TSR 限速标志指示灯-限速标志信号值
            value: 0x00(不显示)  0x01~0x1E(限速5,10,...,150)  other(不关心，不显示)*/
            uint32_t TSR_Speed_Limit_Data_Value             :8;
            /*1.76 降功率报警指示灯(PHEV/HEV)-自检状态
            1.108 功率降低指示灯(EV) - 自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Power_Reduction_Data_selfcheck         :1;
            /*1.76 降功率报警指示灯(PHEV/HEV)-指示灯状态
            1.108 功率降低指示灯(EV) -指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Power_Reduction_Data                   :3;
            /*1.92 TSR 道路标志指示灯-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_Road_Sign_Data_selfcheck           :1;
            /*1.92 TSR 道路标志指示灯-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_Road_Sign_Data                     :3;
            /*1.92 TSR 道路标志指示灯-道路标志信号值
            value: 0x00(不显示)  0x01~0x45(各种交通标志) other(不关心，不显示)*/
            uint32_t TSR_Road_Sign_Data_Value               :8;
            /*1.77 动力电池电量低指示灯(白色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Low_Battery_White_Data_selfcheck       :1;
            /*1.77 动力电池电量低指示灯(白色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Low_Battery_White_Data                 :3;
            /*1.132 绿波车速引导(I2V)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t GLOSA_Data_selfcheck                   :1;
            /*1.132 绿波车速引导(I2V)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t GLOSA_Data                             :3;
            /*1.132 绿波车速引导(I2V)-引导车速值
            value: 0x00~0x96(引导车速0,1,2, ... , 150) other(不显示)*/
            uint32_t GLOSA_Data_Value                       :8;
            /*1.117 油水分离指示灯(柴油)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t OilWaterSeparation_Data_selfcheck      :1;
            /*1.117 油水分离指示灯(柴油)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t OilWaterSeparation_Data                :3;
            /*1.133 限速预警(I2V)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t SpeedLimitWrn_Data_selfcheck           :1;
            /*1.133 限速预警(I2V)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SpeedLimitWrn_Data                     :3;
            /*1.133 限速预警(I2V)-限速标志信号值
            value: 0x00(不显示) 0x01~0x1E(限速5,10, ... ,150) other(不关心，不显示)*/
            uint32_t SpeedLimitWrn_Data_Value               :8;
            /*1.119 尿素指示灯(柴油)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t Adblue_Data_selfcheck                  :1;
            /*1.119 尿素指示灯(柴油)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Adblue_Data                            :3;
            /*1.134 车内标牌(I2V)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficSign_Data_selfcheck             :1;
            /*1.134 车内标牌(I2V)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficSign_Data                       :3;
            /*1.134 车内标牌(I2V)-交通标志信号值
            value: 0x00(不显示) 0x01~0x24(各种交通标志) other(不关心，不显示)*/
            uint32_t TrafficSign_Data_value                 :8;
            /*1.135 交通信号灯-本车当前所在信号灯(车道)位置
            value: 0x00(不显示) 0x01~0x07(显示本车信号灯位置，对应信号灯存在才显示) other(不关心，不显示)*/
            uint32_t TrafficLight_Position_Value            :4;
            /*1.135 交通信号灯1(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_R_selfcheck          :1;
            /*1.135 交通信号灯1(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_R_Data               :3;
            /*1.135 交通信号灯1(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_Y_selfcheck          :1;
            /*1.135 交通信号灯1(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_Y_Data               :3;
            /*1.135 交通信号灯1(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_G_selfcheck          :1;
            /*1.135 交通信号灯1(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_G_Data               :3;
            /*1.135 交通信号灯2(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_R_selfcheck          :1;
            /*1.135 交通信号灯2(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_R_Data               :3;
            /*1.135 交通信号灯2(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_Y_selfcheck          :1;
            /*1.135 交通信号灯2(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_Y_Data               :3;
            /*1.135 交通信号灯2(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_G_selfcheck          :1;
            /*1.135 交通信号灯2(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_G_Data               :3;
            /*1.135 交通信号灯3(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_R_selfcheck          :1;
            /*1.135 交通信号灯3(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_R_Data               :3;
            /*1.135 交通信号灯3(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_Y_selfcheck          :1;
            /*1.135 交通信号灯3(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_Y_Data               :3;
            /*1.135 交通信号灯3(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_G_selfcheck          :1;
            /*1.135 交通信号灯3(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_G_Data               :3;
            /*1.135 交通信号灯4(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_R_selfcheck          :1;
            /*1.135 交通信号灯4(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_R_Data               :3;
            /*1.135 交通信号灯4(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_Y_selfcheck          :1;
            /*1.135 交通信号灯4(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_Y_Data               :3;
            /*1.135 交通信号灯4(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_G_selfcheck          :1;
            /*1.135 交通信号灯4(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_G_Data               :3;
            /*1.135 交通信号灯5(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_R_selfcheck          :1;
            /*1.135 交通信号灯5(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_R_Data               :3;
            /*1.135 交通信号灯5(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_Y_selfcheck          :1;
            /*1.135 交通信号灯5(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_Y_Data               :3;
            /*1.135 交通信号灯5(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_G_selfcheck          :1;
            /*1.135 交通信号灯5(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_G_Data               :3;
            /*1.135 交通信号灯6(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_R_selfcheck          :1;
            /*1.135 交通信号灯6(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_R_Data               :3;
            /*1.135 交通信号灯6(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_Y_selfcheck          :1;
            /*1.135 交通信号灯6(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_Y_Data               :3;
            /*1.135 交通信号灯6(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_G_selfcheck          :1;
            /*1.135 交通信号灯6(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_G_Data               :3;
            /*1.135 交通信号灯7(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_R_selfcheck          :1;
            /*1.135 交通信号灯7(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_R_Data               :3;
            /*1.135 交通信号灯7(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_Y_selfcheck          :1;
            /*1.135 交通信号灯7(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_Y_Data               :3;
            /*1.135 交通信号灯7(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_G_selfcheck          :1;
            /*1.135 交通信号灯7(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_G_Data               :3;
            /*1.135 交通信号灯8(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_R_selfcheck          :1;
            /*1.135 交通信号灯8(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_R_Data               :3;
            /*1.135 交通信号灯8(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_Y_selfcheck          :1;
            /*1.135 交通信号灯8(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_Y_Data               :3;
            /*1.135 交通信号灯8(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_G_selfcheck          :1;
            /*1.135 交通信号灯8(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_G_Data               :3;
            /*1.135 交通信号灯8(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_R_selfcheck          :1;
            /*1.135 交通信号灯8(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_R_Data               :3;
            /*1.135 交通信号灯8(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_Y_selfcheck          :1;
            /*1.135 交通信号灯8(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_Y_Data               :3;
            /*1.135 交通信号灯8(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_G_selfcheck          :1;
            /*1.135 交通信号灯8(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_G_Data               :3;
            /*1.135 交通信号灯1(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL1_Time                 :16;
            /*1.135 交通信号灯2(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL2_Time                 :16;
            /*1.135 交通信号灯3(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL3_Time                 :16;
            /*1.135 交通信号灯4(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL4_Time                 :16;
            /*1.135 交通信号灯5(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL5_Time                 :16;
            /*1.135 交通信号灯6(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL6_Time                 :16;
            /*1.135 交通信号灯7(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL7_Time                 :16;
            /*1.135 交通信号灯8(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL8_Time                 :16;
            /*1.135 交通信号灯9(绿色)-信号灯倒计时读秒
            value: 0x00(不显示倒计时) 0x001~0x999(倒计时秒数) other(不关心，不显示)*/
            uint32_t TrafficLights_SL9_Time                 :16;
            /*自检播报状态
            value: 0x00(Status OK) 0x01(Status not OK)*/
            uint32_t SelfCheckReportStatus                  :1;
            /*1.137 空气悬架系统故障指示灯(红色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t AirSus_Red_Data_selfcheck              :1;
            /*1.137 空气悬架系统故障指示灯(红色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AirSus_Red_Data                        :3;
            /*1.137 空气悬架系统故障指示灯(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t AirSus_Yellow_Data_selfcheck           :1;
            /*1.137 空气悬架系统故障指示灯(黄色)--指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AirSus_Yellow_Data                     :3;
            /*1.138 喵CALL指示灯(绿色)--自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t MiaoCALLsts_Data_selfcheck             :1;
            /*1.138 喵CALL指示灯(绿色)--指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t MiaoCALLsts_Data                       :3;
            /*1.140 中央差速锁指示灯(绿色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t CentDiffLock_Green_Data_selfcheck      :1;
            /*1.140 中央差速锁指示灯(绿色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CentDiffLock_Green_Data                :3;
            /*1.140 中央差速锁指示灯(黄色)-自检状态
            self check: 0~no self check ;1~self check*/
            uint32_t CentDiffLock_Yellow_Data_selfcheck     :1;
            /*1.140 中央差速锁指示灯(黄色)-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CentDiffLock_Yellow_Data               :3;
            /*对齐补充位，新加时可以使用*/
            uint32_t Reserved                               :11;
        }s_u32Telltales_status_t;
    }u_TT_Moduleu32Telltales_status_t;
}IPC_M2S_ClusterAppAPPTT_Module_t;

/* Pack function of sub message TT_Module */
int32_t IPC_M2S_ClusterAppAPPTT_Module_Pack(IPC_M2S_ClusterAppAPPTT_Module_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TT_Module */
int32_t IPC_M2S_ClusterAppAPPTT_Module_Parse(IPC_M2S_ClusterAppAPPTT_Module_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: WN_Module */
typedef struct
{
    union
    {
        uint8_t u32Warning_status[150];
        struct
        {
            /*Warning Status：0~No Warning,1~Warning  Trigger
            1.147 危险！请立即远离车辆！*/
            uint16_t WN_DrvAwayCar                          :1;
            /*1.147 危险！请安全停车并立即远离车辆！*/
            uint16_t WN_DrvAwayCarStop                      :1;
            /*1.213 ESS紧急转向避让辅助功能激活*/
            uint16_t WN_IFCESSTrig                          :1;
            /*1.212 AES自动紧急转向避让辅助功能激活*/
            uint16_t WN_IFCAESTrig                          :1;
            /*1.187 针对行人的自动紧急制动启动*/
            uint16_t WN_AEBTrigP                            :1;
            /*1.186 针对车辆的自动紧急制动启动*/
            uint16_t WN_AEBTrigV                            :1;
            /*1.188 交叉路口辅助制动启动(针对车辆)*/
            uint16_t WN_IASTrigV                            :1;
            /*1.190 前横穿侧向制动启动*/
            uint16_t WN_FCTABrakeActive                     :1;
            /*1.196 倒车侧向制动启动*/
            uint16_t WN_RSDSRLBStart                        :1;
            /*1.198 触发ACC接管请求---请制动*/
            uint16_t WN_ACCTakeOverBrake                    :1;
            /*1.184 前碰撞预警---请制动*/
            uint16_t WN_AEBFCWWarning                       :1;
            /*1.189 前横穿侧向警告功能-请制动*/
            uint16_t WN_FCTABrakePlease                     :1;
            /*1.210 请手握方向盘1hz*/
            uint16_t WN_IFCHoldWheel_1Hz                    :1;
            /*1.210 请手握方向盘2hz*/
            uint16_t WN_IFCHoldWheel_2Hz                    :1;
            /*1.210 请手握方向盘3hz*/
            uint16_t WN_IFCHoldWheel_3Hz                    :1;
            /*1.210 请手握方向盘4hz*/
            uint16_t WN_IFCHoldWheel_4Hz                    :1;
            /*1.185 请保持安全距离*/
            uint16_t WN_AEBSafeDistance                     :1;
            /*1.205 高速公路辅助系统-请手扶方向盘*/
            uint16_t WN_ACCHWATakeOver                      :1;
            /*1.205 高速公路辅助系统-请手扶方向盘2Hz提示音*/
            uint16_t WN_ACCHWATakeOver_2Hz                  :1;
            /*1.205 高速公路辅助系统-请手扶方向盘4Hz提示音*/
            uint16_t WN_ACCHWATakeOver_4Hz                  :1;
            /*1.210 车道辅助系统退出，请接管车辆*/
            uint16_t WN_IFCTakeOver                         :1;
            /*1.205 高速公路辅助系统-请目视前方*/
            uint16_t WN_ACCHWATakeAtte                      :1;
            /*1.205 高速公路辅助系统-请目视前方2hz*/
            uint16_t WN_ACCHWATakeAtte_2Hz                  :1;
            /*1.205 高速公路辅助系统-请目视前方4hz*/
            uint16_t WN_ACCHWATakeAtte_4Hz                  :1;
            /*1.71  请选择P挡(8AT)   No signal*/
            uint16_t WN_GearPSelect                         :1;
            /*1.17/1.18  左前门开报警*/
            uint16_t WN_LFDoorOpen                          :1;
            /*1.17/1.18  右前门开报警*/
            uint16_t WN_RFDoorOpen                          :1;
            /*1.17/1.18  左后门开报警*/
            uint16_t WN_LRDoorOpen                          :1;
            /*1.17/1.18  右后门开报警*/
            uint16_t WN_RRDoorOpen                          :1;
            /*1.17/1.18  后备箱开报警*/
            uint16_t WN_TrunkOpen                           :1;
            /*1.17/1.18  发动机盖开报警*/
            uint16_t WN_HoodOpen                            :1;
            /*1.44  第一排左安全带报警提示*/
            uint16_t WN_FirRowLSeatBelt                     :1;
            /*1.44  第一排右安全带报警提示*/
            uint16_t WN_FirRowRSeatBelt                     :1;
            /*1.44  第二排左安全带报警提示*/
            uint16_t WN_SecRowLSeatBelt                     :1;
            /*1.44  第二排中安全带报警提示*/
            uint16_t WN_SecRowMSeatBelt                     :1;
            /*1.44  第二排右安全带报警提示*/
            uint16_t WN_SecRowRSeatBelt                     :1;
            /*1.12/1.13/1.14  制动系统故障*/
            uint16_t WN_BrakeSysFault                       :1;
            /*1.160 动力系统严重故障   No signal*/
            uint16_t WN_DynSysFault                         :1;
            /*1.145 CCO目标车速一段*/
            uint16_t WN_CCOTargetSpeed0                     :1;
            /*1.145 CCO目标车速二段*/
            uint16_t WN_CCOTargetSpeed1                     :1;
            /*1.145 CCO目标车速三段*/
            uint16_t WN_CCOTargetSpeed2                     :1;
            /*1.145 CCO目标车速四段*/
            uint16_t WN_CCOTargetSpeed3                     :1;
            /*1.145 CCO目标车速五段*/
            uint16_t WN_CCOTargetSpeed4                     :1;
            /*1.145 CCO目标车速六段*/
            uint16_t WN_CCOTargetSpeed5                     :1;
            /*1.145 CCO目标车速七段*/
            uint16_t WN_CCOTargetSpeed6                     :1;
            /*1.145 CCO目标车速八段*/
            uint16_t WN_CCOTargetSpeed7                     :1;
            /*1.145 CCO目标车速九段*/
            uint16_t WN_CCOTargetSpeed8                     :1;
            /*1.216 蠕行目标车速一段*/
            uint16_t WN_SlowTargetSpeed0                    :1;
            /*1.216 蠕行目标车速二段*/
            uint16_t WN_SlowTargetSpeed1                    :1;
            /*1.216 蠕行目标车速三段*/
            uint16_t WN_SlowTargetSpeed2                    :1;
            /*1.216 蠕行目标车速四段*/
            uint16_t WN_SlowTargetSpeed3                    :1;
            /*1.216 蠕行目标车速五段*/
            uint16_t WN_SlowTargetSpeed4                    :1;
            /*1.216 蠕行目标车速六段*/
            uint16_t WN_SlowTargetSpeed5                    :1;
            /*1.216 蠕行目标车速七段*/
            uint16_t WN_SlowTargetSpeed6                    :1;
            /*1.216 蠕行目标车速八段*/
            uint16_t WN_SlowTargetSpeed7                    :1;
            /*1.216 蠕行目标车速九段*/
            uint16_t WN_SlowTargetSpeed8                    :1;
            /*1.213 紧急转向避让辅助功能故障*/
            uint16_t WN_IFCESSFault                         :1;
            /*1.33  左前胎压过低报警*/
            uint16_t WN_FLTirePressWarning                  :1;
            /*1.33  右前胎压过低报警*/
            uint16_t WN_FRTirePressWarning                  :1;
            /*1.33  左后胎压过低报警*/
            uint16_t WN_RLTirePressWarning                  :1;
            /*1.33  右后胎压过低报警*/
            uint16_t WN_RRTirePressWarning                  :1;
            /*1.34  左前胎温过高报警*/
            uint16_t WN_FLTireTempWarning                   :1;
            /*1.34  右前胎温过高报警*/
            uint16_t WN_FRTireTempWarning                   :1;
            /*1.34  左后胎温过高报警*/
            uint16_t WN_RLTireTempWarning                   :1;
            /*1.34  右后胎温过高报警*/
            uint16_t WN_RRTireTempWarning                   :1;
            /*1.72  四驱系统故障*/
            uint16_t WN_4WDSystemFault                      :1;
            /*1.73  四驱系统过热*/
            uint16_t WN_4WDSystemHeat                       :1;
            /*1.100 混合动力系统故障，请安全停车*/
            uint16_t WN_HybSysFault_Stop                    :1;
            /*1.101 车辆发生碰撞，混合动力系统不可用*/
            uint16_t WN_HybSysUnavailable                   :1;
            /*1.186 正在充电 TBD*/
            uint16_t WN_Charging                            :1;
            /*1.186 预约充电 TBD*/
            uint16_t WN_ChargeWait                          :1;
            /*1.186 充电已完成 TBD*/
            uint16_t WN_ChargeComplete                      :1;
            /*1.186 充电已停止 TBD*/
            uint16_t WN_ChargeStop                          :1;
            /*1.102 动力电池系统故障，请安全停车*/
            uint16_t WN_DynBattSysFault_Stop                :1;
            /*1.102 动力电池系统故障，请及时到4S店维修*/
            uint16_t WN_DynBattSysFault_Repair              :1;
            /*1.212 自动紧急转向避让功能不可用*/
            uint16_t WN_IFCAESFault                         :1;
            /*1.45  变速器过热,请安全停车*/
            uint16_t WN_TransWarnStopCar                    :1;
            /*1.68  动力系统故障  (8AT)   No signal*/
            uint16_t WN_PowerSysFault                       :1;
            /*1.48/1.49/1.50/1.51  变速器故障*/
            uint16_t WN_TransFault                          :1;
            /*1.52/1.53  变速器未能成功挂入P挡*/
            uint16_t WN_TransPutInPFailed                   :1;
            /*1.7   机油压力不足*/
            uint16_t WN_LowOilPressure                      :1;
            /*1.2   发动机水温过高*/
            uint16_t WN_EngWaterTempHigh                    :1;
            /*1.45/1.46/1.47  变速器过热*/
            uint16_t WN_TransWarning                        :1;
            /*1.99  驱动系统故障 请及时到4S店维修*/
            uint16_t WN_DrvSysFault_Repair                  :1;
            /*1.96  混合动力系统故障，请及时到4S店维修*/
            uint16_t WN_HybSysFault_Repair                  :1;
            /*1.93  起动系统故障，请及时到4S店维修*/
            uint16_t WN_StartingSysFault                    :1;
            /*1.97  混合动力系统功率暂时受限，请小心驾驶*/
            uint16_t WN_HybSysLimited                       :1;
            /*1.98  能量回收系统故障，请及时到4S店维修*/
            uint16_t WN_RecoverySysFault                    :1;
            /*1.91  充电机故障，请及时到4S店维修*/
            uint16_t WN_ChargerFault                        :1;
            /*1.92  充电系统故障，充电停止*/
            uint16_t WN_ChargeSysFault                      :1;
            /*1.86  充电机温度过高，充电停止*/
            uint16_t WN_ChargerTempHigh                     :1;
            /*1.87  动力电池温度过高，充电停止*/
            uint16_t WN_DynBattTempHigh                     :1;
            /*1.89  充电机输出功率降低*/
            uint16_t WN_ChargerPWReduced                    :1;
            /*1.194 前向横穿辅助功能不可用*/
            uint16_t WN_FCTAUnavai                          :1;
            /*1.63  变速器在N档，车辆无法锁止*/
            uint16_t WN_LockFailureN                        :1;
            /*1.66  请注意变速器在N挡(8AT)*/
            uint16_t WN_NoticeGearN                         :1;
            /*1.21/1.22  灯光未关提示*/
            uint16_t WN_PositionLampOn                      :1;
            /*1.195 拖车模式 侧后辅助系统停用*/
            uint16_t WN_RSDSTrailer                         :1;
            /*1.192 拖车模式 前向辅助系统停用*/
            uint16_t WN_AEBPSAUnavai                        :1;
            /*1.204 高速公路辅助系统-前方即将穿过隧道，请及时接管车辆*/
            uint16_t WN_ACCHWACrossTunnel                   :1;
            /*1.204 高速公路辅助系统-前方存在分岔路口，请求及时接管车辆*/
            uint16_t WN_ACCHWABranchRoad                    :1;
            /*1.90  充电装置连接不正确，充电停止*/
            uint16_t WN_ChargeDevConnectErr                 :1;
            /*1.88  动力电池温度过低，充电停止*/
            uint16_t WN_DynBattTempLow                      :1;
            /*1.85  充电口输入功率不足，充电停止*/
            uint16_t WN_ChargePortWarning                   :1;
            /*1.209 智能前视系统传感器标定中*/
            uint16_t WN_IFCSCalibrating                     :1;
            /*1.48/1.108 防盗认证失败*/
            uint16_t WN_TransAuthenFailed                   :1;
            /*1.48/1.49/1.50  变速器功能受限*/
            uint16_t WN_TransLimited                        :1;
            /*1.52  变速器无法解除P挡*/
            uint16_t WN_TransReleasePFailed                 :1;
            /*1.43  电子转向锁解锁失败，请转动方向盘*/
            uint16_t WN_ElecSteerUnlockFail                 :1;
            /*1.148 发动机主水泵故障，请尽快维修*/
            uint16_t WN_EngPumpFault                        :1;
            /*1.165 主动格栅故障*/
            uint16_t WN_AGSFault                            :1;
            /*1.81  请断开充/放电装置*/
            uint16_t WN_ChargeDevDisconnect                 :1;
            /*1.90  请连接充电装置*/
            uint16_t WN_ChargeDevConnect                    :1;
            /*1.79  动力电池电量低，请及时充电*/
            uint16_t WN_DynBattLow                          :1;
            /*1.82  请将挡位置于P挡*/
            uint16_t WN_GearChngP                           :1;
            /*1.69  P挡时车辆需静止 (8AT)*/
            uint16_t WN_GearPNeedStop                       :1;
            /*1.131/1.132/1.133 前照灯故障*/
            uint16_t WN_HighBeamSysFault                    :1;
            /*1.70  车速较高不适合挂入P挡(8AT)*/
            uint16_t WN_GearPNotSuitable                    :1;
            /*1.64  变速器D挡跛行模式(8AT) */
            uint16_t WN_LimpModeGearD                       :1;
            /*1.65  变速器P挡跛行模式(8AT) */
            uint16_t WN_LimpModeGearP                       :1;
            /*1.149 车辆已上上电，禁止加油   No signal*/
            uint16_t WN_ReadyNoRefuel                       :1;
            /*1.178 加油准备中*/
            uint16_t WN_FuelPrepare                         :1;
            /*1.111 弹射起步激活*/
            uint16_t WN_RaceLaunchActive                    :1;
            /*1.112 弹射模式激活*/
            uint16_t WN_RaceModeActive                      :1;
            /*1.111 超时保护*/
            uint16_t WN_RaceLaunchTimeout                   :1;
            /*1.149 充电装置已连接，禁止加油   No signal*/
            uint16_t WN_ChargingNoRefuel                    :1;
            /*1.110 油箱系统故障，请维修*/
            uint16_t WN_FuelTankSysFault                    :1;
            /*1.141 油箱盖未关闭*/
            uint16_t WN_FuelTankCapOn                       :1;
            /*1.118 颗粒捕集器正在再生*/
            uint16_t WN_GPFRegenerating                     :1;
            /*1.118 颗粒捕集器需要再生*/
            uint16_t WN_GPFRegenerate                       :1;
            /*1.99  后桥系统故障，请及时到4S店维修*/
            uint16_t WN_RearAxleSysFault                    :1;
            /*1.94  前桥系统故障，请及时到4S店维修*/
            uint16_t WN_FrontAxleSysFault                   :1;
            /*1.107 请勿同时踩下加速与刹车踏板*/
            uint16_t WN_DoNotStepAcAndBr                    :1;
            /*1.67  电子换挡器故障 (8AT)   No signal*/
            uint16_t WN_ElecShifterFault                    :1;
            /*1.8   运输模式*/
            uint16_t WN_StatBattLowTranMode                 :1;
            /*1.8   12V电源系统故障，舒适功能关闭 */
            uint16_t WN_StatBattLowComfortOff               :1;
            /*1.151 12V电源系统故障，请安全停车*/
            uint16_t WN_12VFaultStop                        :1;
            /*1.151 12V电源系统故障，请及时到4S店维修*/
            uint16_t WN_12VFaultRepair                      :1;
            /*1.8   电量消耗过多，进入省电模式*/
            uint16_t WN_StatBattLowSavingMode               :1;
            /*1.8   12V蓄电池电量低，请启动车辆*/
            uint16_t WN_StatBattLowStartUp                  :1;
            /*1.139 模式切换失败，请熄火重试*/
            uint16_t WN_ModeSwitchFailed                    :1;
            /*1.150 正在加油，禁止充电*/
            uint16_t WN_RefuelingNoCharge                   :1;
            /*1.56  换挡请踩刹车并按下解锁键*/
            uint16_t WN_ShiftGearBrakeAndKey                :1;
            /*1.59  换挡请踩刹车*/
            uint16_t WN_ShiftGearStepBrake                  :1;
            /*1.56  换挡请按下解锁键   No signal*/
            uint16_t WN_ShiftGearPressKey                   :1;
            /*1.60/1.61 车速过高无法切换挡位*/
            uint16_t WN_ShiftNotAllowed                     :1;
            /*1.60  请在车辆静止时挂入P档*/
            uint16_t WN_ShiftPStop                          :1;
            /*TBD   请注意休息，取自DMS模块*/
            uint16_t WN_DMSTakeRest_1                       :1;
            /*TBD   请注意休息，取自DMS模块*/
            uint16_t WN_DMSTakeRest_2                       :1;
            /*TBD   请注意休息，取自DMS模块*/
            uint16_t WN_DMSTakeRest_3                       :1;
            /*TBD   请专心驾驶*/
            uint16_t WN_DMSTakeAttention                    :1;
            /*1.166 主动式安全带故障   No signal*/
            uint16_t WN_PPMIFault                           :1;
            /*1.238 副驾主动式安全带故障*/
            uint16_t WN_SidePPMIErr                         :1;
            /*1.95  BSG系统故障，请及时到4S店维修*/
            uint16_t WN_BSGSysFault                         :1;
            /*1.234 请原地开启排气自洁*/
            uint16_t WN_PlsStartSelfClean                   :1;
            /*1.234 请启动车辆并怠速*/
            uint16_t WN_PlsStartCarSlowly                   :1;
            /*1.234 颗粒捕集器正在自洁*/
            uint16_t WN_DPFCleaning                         :1;
            /*1.234 自洁完成感谢等待*/
            uint16_t WN_SelfCleanComplete                   :1;
            /*1.83  请将挡位置于P挡或N挡   No signal*/
            uint16_t WN_GearChngPN                          :1;
            /*1.241 防雨棚未关闭*/
            uint16_t WN_RainDoorOpen                        :1;
            /*1.152 动力电池温度低，请插枪加热*/
            uint16_t WN_HeatingPlugIn                       :1;
            /*1.233 尿素液位低，请加注*/
            uint16_t WN_UreaLow                             :1;
            /*1.233 尿素液位极低，请加注*/
            uint16_t WN_UreaVeryLow                         :1;
            /*1.233 尿素罐空，禁止下次启动*/
            uint16_t WN_UreaTankEmpty                       :1;
            /*1.233 尿素不合格，请检查*/
            uint16_t WN_UreaUnqualifyPlsCheck               :1;
            /*1.233 尿素不合格 行驶超过50km*/
            uint16_t WN_UreaUnqualifyOver50km               :1;
            /*1.233 尿素喷射中断 请检查*/
            uint16_t WN_UreaFillStopPlsReFill               :1;
            /*1.233 尿素喷射中断 行驶超过50km*/
            uint16_t WN_UreaFillStopOver50km                :1;
            /*1.233 尿素系统禁止发动机启动*/
            uint16_t WN_UreaSysDisableEng                   :1;
            /*1.233 尿素系统故障，请入站检查*/
            uint16_t WN_UreaSysErrPlsCheck                  :1;
            /*1.233 尿素系统故障，行驶超过50km*/
            uint16_t WN_UreaSysErrOver50km                  :1;
            /*1.233 尿素系统故障，禁止下次启动*/
            uint16_t WN_UreaSysErrRestartErr                :1;
            /*1.109 发动机需要启动, EV模式不可用*/
            uint16_t WN_DM_ENS_EV                           :1;
            /*1.235 前轮回正完成*/
            uint16_t WN_FrontTireAlignFinish                :1;
            /*1.235 前轮未回正 请右打方向盘*/
            uint16_t WN_FrontTireTurnRight                  :1;
            /*1.235 前轮未回正 请左打方向盘*/
            uint16_t WN_FrontTireTurnLeft                   :1;
            /*1.243 请在车内无人状态下开启紫外线消毒杀菌功能*/
            uint16_t WN_RayAntiVirusWarn                    :1;
            /*1.169 危险 请专心驾驶*/
            uint16_t WN_DrvConcentrate                      :1;
            /*1.170 危险 请勿疲劳驾驶*/
            uint16_t WN_DrvDrowsy                           :1;
            /*1.152 电池温度低，车辆无法行驶*/
            uint16_t WN_CantDriveBatt                       :1;
            /*1.167 连接成功，正在放电中+V2L   No signal*/
            uint16_t WN_DischargingV2L                      :1;
            /*1.167 连接成功，正在放电中+V2V   No signal*/
            uint16_t WN_DischargingV2V                      :1;
            /*1.182 发动机与仪表VIN未匹配*/
            uint16_t WN_EngVinMismatch                      :1;
            /*1.140 越野专家模式*/
            uint16_t WN_ORExperMode                         :1;
            /*1.214 动力电池预热中*/
            uint16_t WN_ChargeHeating                       :1;
            /*1.228 储氢系统受限，请切换为电动模式*/
            uint16_t WN_HSMLimitPlsSwiEV                    :1;
            /*1.228 储氢系统故障，请切换为电动模式并安全停车*/
            uint16_t WN_HSMErrPlsSwiEVAndStop               :1;
            /*1.228 储氢系统故障，请安全停车*/
            uint16_t WN_HSMErrStop                          :1;
            /*1.229 燃料电池系统故障，请到4S店维修*/
            uint16_t WN_BattSysErrPlsFix                    :1;
            /*1.229 燃料电池系统故障，请到4S店维修*/
            uint16_t WN_BattSysErrPlsFix_1                  :1;
            /*1.230 氢气系统故障，请到4S店维修*/
            uint16_t WN_HSErrPlsFix                         :1;
            /*1.230 氢气泄漏，请到4S店维修*/
            uint16_t WN_HSLeakPlsFix                        :1;
            /*1.231 氢气泄漏，请切换为电动模式*/
            uint16_t WN_HSLeakPlsSwiEV                      :1;
            /*1.231 氢气泄漏，请切换为电动模式并安全停车*/
            uint16_t WN_HSLeakPlsSwiEVStop                  :1;
            /*1.231 氢气泄漏，请安全停车，并远离车辆*/
            uint16_t WN_HSLeakStop                          :1;
            /*1.232 冷却液离子浓度过高，请到4S店维修*/
            uint16_t WN_DeionizerErrPlsFix                  :1;
            /*1.144 请带好手机*/
            uint16_t WN_WPCTakePhone                        :1;
            /*1.217 抬头显示故障*/
            uint16_t WN_ARHUDFault                          :1;
            /*1.217 抬头显示过温保护无法显示*/
            uint16_t WN_ARHUDOverheat                       :1;
            /*1.111 超级弹射起步激活*/
            uint16_t WN_SRaceLaunchActive                   :1;
            /*1.111 动力电池可用功率低，超级弹射不可用； 普通弹射激活*/
            uint16_t WN_BattLowSRaceLaunUnAvail             :1;
            /*1.111 变速器温度高，超级弹射不可用；普通弹射激活*/
            uint16_t WN_TransHeatSLaunchUnAvail             :1;
            /*1.111 超级弹射使用次数达到上限，普通弹射激活*/
            uint16_t WN_SRaceLaunchOverLimit                :1;
            /*1.152 动力电池温度过低，车辆无法启动*/
            uint16_t WN_BattTempLowCantStart                :1;
            /*1.221 动力电池温度低，动力降低*/
            uint16_t WN_BattTempLowPowerDown                :1;
            /*1.221 动力电池温度高，动力降低*/
            uint16_t WN_BattTempHighPowerDown               :1;
            /*1.52 请踩下制动踏板或拉起EPB，待P挡自学习完成后松开*/
            uint16_t WN_PlsPrsBrktoWait                     :1;
            /*1.52 P挡自学习未完成，待自学习完成后换挡*/
            uint16_t WN_SelfLearnNotComplete                :1;
            /*1.52 P挡自学习完成，请松开制动踏板*/
            uint16_t WN_LearnSuccessPlsRelBrk               :1;
            /*1.109 动力电池可用功率低，EV模式不可用*/
            uint16_t WN_PowerLowEVUnvil                     :1;
            /*1.210 车辆偏离，请控制方向盘*/
            uint16_t WN_PlsCtrlWheel                        :1;
            /*1.109 后桥系统故障，四驱模式不可用*/
            uint16_t WN_RearAxSysErr4WDUnvil                :1;
            /*1.41  PEPS电源继电器故障*/
            uint16_t WN_PEPSPowerFault                      :1;
            /*1.16  车速一级警报*/
            uint16_t WN_OverSpeedLevel_1                    :1;
            /*1.16  车速二级警报*/
            uint16_t WN_OverSpeedLevel_2                    :1;
            /*1.62  车速警报手动可调*/
            uint16_t WN_OverSpeedSetting                    :1;
            /*1.25/1.26  牌照灯故障*/
            uint16_t WN_LicPlateLampFault                   :1;
            /*1.27/1.28  倒车灯故障*/
            uint16_t WN_RvsLampFault                        :1;
            /*1.29  后位灯故障*/
            uint16_t WN_RearPosnLampFault                   :1;
            /*1.120 激光辅助远光光源故障*/
            uint16_t WN_LasHdLightFault                     :1;
            /*1.208 智能前视系统传感器探测受限*/
            uint16_t WN_IFCSDectectLimited                  :1;
            /*1.191 前向辅助系统传感器探测受限*/
            uint16_t WN_ACCSensorDetectLimited              :1;
            /*1.193 前角雷达传感器探测受限*/
            uint16_t WN_FCTSDectectLimit                    :1;
            /*1.207 紧急车道保持功能受限*/
            uint16_t WN_IFCLKAFunLimited                    :1;
            /*1.104 通信故障，请小心驾驶  已删除*/
            uint16_t WN_CommunicationFault                  :1;
            /*1.206 变道辅助功能故障*/
            uint16_t WN_ACCHWAFuncFault                     :1;
            /*1.197 后方车辆车速过高*/
            uint16_t WN_RSDSRCWWarning                      :1;
            /*1.103 声音提示系统错误*/
            uint16_t WN_BeepSysFault                        :1;
            /*1.23/1.24  制动灯故障*/
            uint16_t WN_BrakeLampFault                      :1;
            /*1.19/1.20  后雾灯故障*/
            uint16_t WN_RearFogLampFault                    :1;
            /*1.31  雨量光线传感器故障*/
            uint16_t WN_RainLightFault                      :1;
            /*1.129 AFS系统故障*/
            uint16_t WN_AFSSystemFault                      :1;
            /*1.201 智慧巡航功能不可用*/
            uint16_t WN_ACCUnavailable                      :1;
            /*1.199 自适应巡航功能不可用*/
            uint16_t WN_ACCCruiseFunFault                   :1;
            /*1.183 ESP关闭 前向辅助系统已停用*/
            uint16_t WN_AEBESPOff                           :1;
            /*1.211 交通标志信息功能故障*/
            uint16_t WN_TrafficSignFault                    :1;
            /*1.8   12V蓄电池电量低，舒适功能降功率*/
            uint16_t WN_StatBattLowPwrReduce                :1;
            /*1.127 ALS系统故障*/
            uint16_t WN_ALSSysFault                         :1;
            /*TBD   越野巡航功能受限*/
            uint16_t WN_ORCruiseLimited                     :1;
            /*TBD   转向辅助功能受限*/
            uint16_t WN_TurnAssistLimited                   :1;
            /*1.9  陡坡缓降功能受限*/
            uint16_t WN_HDCLimited                          :1;
            /*1.10  自动驻车功能受限*/
            uint16_t WN_AutoholdLimited                     :1;
            /*1.143 请确认手机充电区域是否有异物或者偏离*/
            uint16_t WN_WPCChargeZone                       :1;
            /*1.124 像素大灯故障   No signal*/
            uint16_t WN_PHLFault                            :1;
            /*1.125 像素大灯摄像头故障   No signal*/
            uint16_t WN_PHLCameraFault                      :1;
            /*1.136 4L模式请减速慢行  No signal*/
            uint16_t WN_4LModeSlow                          :1;
            /*1.146 四驱系统功能降级  No signal*/
            uint16_t WN_4WDSystemDemotion                   :1;
            /*1.136 4L模式请减速慢行  No signal*/
            uint16_t WN_4HModeSlow                          :1;
            /*1.154 VSG故障  No signal*/
            uint16_t WN_VSGFault                            :1;
            /*1.155 动力蓄电池已切断  No signal*/
            uint16_t WN_DynBattCutOff                       :1;
            /*1.156 电机故障  No signal*/
            uint16_t WN_ElecMachiFault                      :1;
            /*1.157 DC/DC故障  No signal*/
            uint16_t WN_DCDCFault                           :1;
            /*1.159 E-Park故障  No signal*/
            uint16_t WN_EParkFault                          :1;
            /*1.160 请移除充电枪*/
            uint16_t WN_RemoveChargeGun                     :1;
            /*1.160 请移除充放电枪*/
            uint16_t WN_RemoveDischrgGun                    :1;
            /*1.160 换挡器故障*/
            uint16_t WN_ShifterFault                        :1;
            /*1.62  车速过高无法切换挡位（EV）*/
            uint16_t WN_ShiftNotAllowEV                     :1;
            /*1.160 P挡故障*/
            uint16_t WN_ShiftPFault                         :1;
            /*1.160 请在车辆静止时挂入P挡（EV）  No signal*/
            uint16_t WN_ShiftPStopEV                        :1;
            /*1.160 车辆充电中无法换挡  No signal*/
            uint16_t WN_ChargingShift                       :1;
            /*1.160 请踩制动切出P挡  No signal*/
            uint16_t WN_StepBrakeOutP                       :1;
            /*1.160 请踩制动切出N挡  No signal*/
            uint16_t WN_StepBrakeOutN                       :1;
            /*1.160 小蓄电池故障  No signal*/
            uint16_t WN_LVBattFault                         :1;
            /*1.160 动力电池电量低，运动模式不可用  No signal*/
            uint16_t WN_HVBattSport                         :1;
            /*1.160 动力电池电量低，空调功能受限  No signal*/
            uint16_t WN_HVBattAir                           :1;
            /*1.160 已到ECO模式极限值  No signal*/
            uint16_t WN_ECOValue                            :1;
            /*1.160 电量高，单踏板功能受限  No signal*/
            uint16_t WN_PedalLimit                          :1;
            /*1.160 无法识别电池包，请检查  No signal*/
            uint16_t WN_UnidentifyBatt                      :1;
            /*1.161 热管理伺服部件故障，请尽快检修*/
            uint16_t WN_HeatManagerFault                    :1;
            /*1.122 超远辅助远光故障  No signal*/
            uint16_t WN_FarBeamFault                        :1;
            /*1.158 动力电池故障  No signal*/
            uint16_t WN_DynBattFault                        :1;
            /*1.179 请更换紧急呼叫系统备用电池*/
            uint16_t WN_TboxErr                             :1;
            /*1.78  动力电池电量低*/
            uint16_t WN_DynBattLowEV                        :1;
            /*1.237 悬架阻尼功能受限*/
            uint16_t WN_SuspensionLimit                     :1;
            /*1.105/1.106 已上电可挂挡行驶  No signal*/
            uint16_t WN_PowerOnGearDrive                    :1;
            /*1.178 可以开始加油*/
            uint16_t WN_FuelStart                           :1;
            /*1.36  请确认钥匙是否在车内*/
            uint16_t WN_KeyInCarOrNot                       :1;
            /*1.203 向里拨动开关，确认调整车速*/
            uint16_t WN_ACCISLCruiseSpeed                   :1;
            /*1.37 踩下刹车+一键启动 请挂P挡或N挡*/
            uint16_t WN_StepBrakeStartGearPN                :1;
            /*1.38 踩下离合+ 一键启动 请挂空档*/
            uint16_t WN_StepClutchStartGearNull             :1;
            /*1.40 踩下刹车+一键启动 请挂N挡 */
            uint16_t WN_StepBrakeStartGearNull              :1;
            /*1.203 速度过高请主动减速*/
            uint16_t WN_ACCISLSlowDoWN                      :1;
            /*1.3/1.4/1.5   定速巡航*/
            uint16_t WN_TargetCruiseSpeed                   :1;
            /*1.121 激光辅助远光开启*/
            uint16_t WN_LasHdLightOn                        :1;
            /*1.121 激光辅助远光关闭*/
            uint16_t WN_LasHdLightOff                       :1;
            /*1.30  驻车灯已开启*/
            uint16_t WN_ParkLampOn                          :1;
            /*1.32  疲劳驾驶预警*/
            uint16_t WN_DrowsyDrvWarning                    :1;
            /*1.32  疲劳驾驶预警1hz*/
            uint16_t WN_DrowsyDrvWarning_1Hz                :1;
            /*1.35  请带好钥匙提示*/
            uint16_t WN_TakeTheKeyTip                       :1;
            /*1.74  请添加燃油*/
            uint16_t WN_FuelLowWarn                         :1;
            /*1.130 AFS临时行驶模式  No signal*/
            uint16_t WN_AFSDrivingMode                      :1;
            /*1.128 ALS临时行驶模式  No signal*/
            uint16_t WN_ALSDrivingSide                      :1;
            /*TBD   请保养汽车 已删除*/
            uint16_t WN_MaintainPlease                      :1;
            /*TBD   距下次保养XXkm 已删除*/
            uint16_t WN_MaintainNext                        :1;
            /*1.77  请释放电子驻车*/
            uint16_t WN_ReleaseElecParkCCO                  :1;
            /*1.77  请减速*/
            uint16_t WN_PleaseSlowDoWN                      :1;
            /*1.173 为完成4L模式切换，请停车  No signal*/
            uint16_t WN_4LModeStop                          :1;
            /*1.174 请挂N挡  No signal*/
            uint16_t WN_PleaseGearN                         :1;
            /*1.175 请退出4L模式  No signal*/
            uint16_t WN_4LModeEx                            :1;
            /*1.177 请选择4L  No signal*/
            uint16_t WN_4LModeSelect                        :1;
            /*1.177 请选择4H  No signal*/
            uint16_t WN_4HModeSelect                        :1;
            /*1.176 请进入4L模式  No signal*/
            uint16_t WN_4LModeEn                            :1;
            /*1.75 请激活越野巡航功能  No signal*/
            uint16_t WN_ORCruiseActive                      :1;
            /*1.113 标准模式*/
            uint16_t WN_DM_B30_Standard                     :1;
            /*1.113 运动模式*/
            uint16_t WN_DM_B30_Sport                        :1;
            /*1.113 雪地模式*/
            uint16_t WN_DM_B30_Snow                         :1;
            /*1.113 泥地模式*/
            uint16_t WN_DM_B30_Muddy                        :1;
            /*1.113 沙地模式*/
            uint16_t WN_DM_B30_Sand                         :1;
            /*1.113 4L模式*/
            uint16_t WN_DM_B30_4L                           :1;
            /*1.113 经济模式*/
            uint16_t WN_DM_B30_ECO                          :1;
            /*1.113 智能模式*/
            uint16_t WN_DM_B30_IMC                          :1;
            /*1.113 超级运动模式*/
            uint16_t WN_DM_B30_SportPlus                    :1;
            /*1.113 越野模式*/
            uint16_t WN_DM_B30_OffRoad                      :1;
            /*1.113 专家模式*/
            uint16_t WN_DM_B30_Expert                       :1;
            /*1.113 岩石模式*/
            uint16_t WN_DM_B30_Rock                         :1;
            /*1.113 凹凸路模式*/
            uint16_t WN_DM_B30_Pothole                      :1;
            /*1.113 泥砂模式*/
            uint16_t WN_DM_B30_MuddySand                    :1;
            /*1.113 山地模式*/
            uint16_t WN_DM_B30_Mountain                     :1;
            /*1.113 标准模式已选择*/
            uint16_t WN_DM_StandardSelect                   :1;
            /*1.113 运动模式已选择*/
            uint16_t WN_DM_SportSelect                      :1;
            /*1.113 超级运动模式已选择*/
            uint16_t WN_DM_SportPlusSelect                  :1;
            /*1.113 雪地模式已选择*/
            uint16_t WN_DM_SnowSelect                       :1;
            /*1.113 泥地模式已选择*/
            uint16_t WN_DM_MuddySelect                      :1;
            /*1.113 沙地模式已选择*/
            uint16_t WN_DM_SandSelect                       :1;
            /*1.113 经济模式已选择*/
            uint16_t WN_DM_EcoSelect                        :1;
            /*1.113 岩石模式已选择*/
            uint16_t WN_DM_RockSelect                       :1;
            /*1.113 凹凸路模式已选择*/
            uint16_t WN_DM_PotholeSelect                    :1;
            /*1.113 泥沙模式已选择*/
            uint16_t WN_DM_MuddySandSelect                  :1;
            /*1.113 山地模式已选择*/
            uint16_t WN_DM_MountainSelect                   :1;
            /*1.113 专家模式已选择*/
            uint16_t WN_DM_ExpertSelect                     :1;
            /*1.113 越野模式已选择*/
            uint16_t WN_DM_OffRoadSelect                    :1;
            /*1.113 4L模式已选择*/
            uint16_t WN_DM_4LSelect                         :1;
            /*1.113 智能模式已选择*/
            uint16_t WN_DM_IMCSelect                        :1;
            /*1.113 标准模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_StandardDPR                      :1;
            /*1.113 运动模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_SportDPR                         :1;
            /*1.113 经济模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_EcoDPR                           :1;
            /*1.113 雪地模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_SnowDPR                          :1;
            /*1.113 泥地模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_MuddyDPR                         :1;
            /*1.113 沙地模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_SandDPR                          :1;
            /*1.113 凹凸路模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_PotholeDPR                       :1;
            /*1.113 山地模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_MountainDPR                      :1;
            /*1.113 岩石模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_RockDPR                          :1;
            /*1.113 越野模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_OffRoadDPR                       :1;
            /*1.113 超级运动模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_SportPlusDPR                     :1;
            /*1.113 专家模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_ExpertDPR                        :1;
            /*1.113 泥沙模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_MuddySandDPR                     :1;
            /*1.113 智能模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_IMCDPR                           :1;
            /*1.113 4L模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_4LDPR                            :1;
            /*1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车挂N 挡  No signal*/
            uint16_t WN_4LEnGearN                           :1;
            /*1.134/1.135 ESOF 驱动模式 进入4L模式中，无法挂入D/R/P 挡  No signal*/
            uint16_t WN_4LEnGearDRP                         :1;
            /*1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车挂N 挡  No signal*/
            uint16_t WN_4LExGearN                           :1;
            /*1.134/1.135 ESOF 驱动模式 退出4L模式中，无法挂入D/R/P 挡  No signal*/
            uint16_t WN_4LExGearDRP                         :1;
            /*1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车并踩下离合  No signal*/
            uint16_t WN_4LEnClutchStep                      :1;
            /*1.134/1.135 ESOF 驱动模式 进入4L模式中，请勿松开离合踏板  No signal*/
            uint16_t WN_4LEnClutchRele                      :1;
            /*1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车并踩下离合  No signal*/
            uint16_t WN_4LExClutchStep                      :1;
            /*1.134/1.135 ESOF 驱动模式 退出4L模式中，请勿松开离合踏板  No signal*/
            uint16_t WN_4LExClutchRele                      :1;
            /*1.113 标准模式*/
            uint16_t WN_DM_StandardSecond                   :1;
            /*1.113 运动模式*/
            uint16_t WN_DM_SportSecond                      :1;
            /*1.113 超级运动模式*/
            uint16_t WN_DM_SportPlusSecond                  :1;
            /*1.113 雪地模式*/
            uint16_t WN_DM_SnowSecond                       :1;
            /*1.113 泥地模式*/
            uint16_t WN_DM_MuddySecond                      :1;
            /*1.113 沙地模式*/
            uint16_t WN_DM_SandSecond                       :1;
            /*1.113 经济模式*/
            uint16_t WN_DM_ECOSecond                        :1;
            /*1.113 4L模式*/
            uint16_t WN_DM_4LSecond                         :1;
            /*1.113 凹凸路模式*/
            uint16_t WN_DM_PotholeSecond                    :1;
            /*1.113 山地模式*/
            uint16_t WN_DM_MountainSecond                   :1;
            /*1.113 岩石模式*/
            uint16_t WN_DM_RockSecond                       :1;
            /*1.113 越野模式*/
            uint16_t WN_DM_OffRoadSecond                    :1;
            /*1.113 专家模式*/
            uint16_t WN_DM_ExpertSecond                     :1;
            /*1.113 智能模式*/
            uint16_t WN_DM_IMCSecond                        :1;
            /*1.113 泥砂模式*/
            uint16_t WN_DM_MuddySandSecond                  :1;
            /*1.115 标准模式已启动*/
            uint16_t WN_DM_EV_StandardStart                 :1;
            /*1.115 运动模式已启动*/
            uint16_t WN_DM_EV_SportStart                    :1;
            /*1.115 经济模式已启动*/
            uint16_t WN_DM_EV_EcoStart                      :1;
            /*1.115 雪地模式已启动 */
            uint16_t WN_DM_EV_SnowStart                     :1;
            /*1.115 AUTO模式已启动*/
            uint16_t WN_DM_EV_AutoStart                     :1;
            /*1.117 单踏板功能已启动*/
            uint16_t WN_DM_V51EV_SinPedalStart              :1;
            /*1.117 单踏板功能退出*/
            uint16_t WN_DM_V51EV_SinPedalQuit               :1;
            /*1.162 长时间停车，请踩下刹车/挂入P挡*/
            uint16_t WN_StopBrakeGearN                      :1;
            /*1.42  电源未关*/
            uint16_t WN_PowerNotInOff                       :1;
            /*1.6   智能启停*/
            uint16_t WN_AutoStartStop                       :1;
            /*1.80 充电装置已移除  No signal*/
            uint16_t WN_ChargeDevRemoved                    :1;
            /*1.109 动力电池电量低，EV模式不可用*/
            uint16_t WN_DM_DBL_EV_Err                       :1;
            /*1.109 混合动力系统暂时受限，AWD模式不可用*/
            uint16_t WN_DM_HSL_AWD                          :1;
            /*1.109 混合动力系统暂时受限，EV模式不可用*/
            uint16_t WN_DM_HSL_EV                           :1;
            /*1.109 混合动力系统暂时受限，SAVE模式不可用*/
            uint16_t WN_DM_HSL_SAVE                         :1;
            /*1.109 混合动力系统暂时受限，SPORT模式不可用*/
            uint16_t WN_DM_HSL_SPORT                        :1;
            /*1.109 混合动力系统暂时受限，沙地模式不可用*/
            uint16_t WN_DM_HSL_SAND                         :1;
            /*1.109 混合动力系统暂时受限，泥地模式不可用*/
            uint16_t WN_DM_HSL_MUDDY                        :1;
            /*1.109 混合动力系统暂时受限，雪地模式不可用*/
            uint16_t WN_DM_HSL_SNOW                         :1;
            /*1.114 标准模式已启动*/
            uint16_t WN_DM_PHEV_AutoStart                   :1;
            /*1.114 纯电模式已启动*/
            uint16_t WN_DM_PHEV_EvStart                     :1;
            /*1.114 能量储备模式已启动*/
            uint16_t WN_DM_PHEV_SaveStart                   :1;
            /*1.114 运动模式已启动*/
            uint16_t WN_DM_PHEV_SportStart                  :1;
            /*1.114 四驱模式已启动*/
            uint16_t WN_DM_PHEV_AWDStart                    :1;
            /*1.114 雪地模式已启动*/
            uint16_t WN_DM_PHEV_SnowStart                   :1;
            /*1.114 泥地模式已启动*/
            uint16_t WN_DM_PHEV_MuddyStart                  :1;
            /*1.114 沙地模式已启动*/
            uint16_t WN_DM_PHEV_SandStart                   :1;
            /*1.114 经济模式已启动*/
            uint16_t WN_DM_PHEV_EcoStart                    :1;
            /*1.114 超级运动模式已启动*/
            uint16_t WN_DM_PHEV_SportPlusStart              :1;
            /*1.109 已使用手动换挡，车辆切换至SPORT模式*/
            uint16_t WN_DM_MS_SPORT                         :1;
            /*1.109 已使用手动换挡，仅SPORT模式可用*/
            uint16_t WN_DM_MS_SPORT_Only                    :1;
            /*1.109 混合动力系统限制解除，EV模式可用*/
            uint16_t WN_DM_HSR_EV                           :1;
            /*1.111 ESP/AVH功能未关闭，弹射起步不可用*/
            uint16_t WN_RLUnavaiESPAVH                      :1;
            /*1.111 混合动力系统暂时受限，弹射起步不可用*/
            uint16_t WN_RLUnavaiHYB                         :1;
            /*1.109 混合动力系统暂时受限，超级动力模式模式不可用*/
            uint16_t WN_DM_HSL_SPORT_P                      :1;
            /*1.109 混合动力系统暂时受限, ECO模式不可用*/
            uint16_t WN_DM_HSL_ECO                          :1;
            /*TBD   转向辅助功能已开启*/
            uint16_t WN_TurnAssistOn                        :1;
            /*TBD   转向辅助功能工作中*/
            uint16_t WN_TurnAssistWork                      :1;
            /*TBD   转向辅助功能已关闭*/
            uint16_t WN_TurnAssistClose                     :1;
            /*TBD   越野巡航功能已关闭*/
            uint16_t WN_ORCruiseClose                       :1;
            /*TBD   越野巡航功能已进入待机状态*/
            uint16_t WN_ORCruiseWait                        :1;
            /*TBD   越野巡航功能已开启*/
            uint16_t WN_ORCruiseOn                          :1;
            /*1.11  EPB报警1 请系安全带*/
            uint16_t WN_FastenSeatbelt                      :1;
            /*1.11  EPB报警1 坡度过大*/
            uint16_t WN_GradientHighWarning                 :1;
            /*1.11  EPB报警1 驻车制动过热*/
            uint16_t WN_ParkSysWarning                      :1;
            /*1.11  EPB报警1 夹紧力不足*/
            uint16_t WN_ClampForceWarning                   :1;
            /*1.15  请踩制动踏板*/
            uint16_t WN_StepBrakePedal                      :1;
            /*TBD   请停车进行设置 已删除*/
            uint16_t WN_SettingVehilce                      :1;
            /*1.119 室外温度低，请减速慢行*/
            uint16_t WN_OutTempLow                          :1;
            /*1.129 AFS关闭  No signal*/
            uint16_t WN_AFSOff                              :1;
            /*1.129 AFS开启  No signal*/
            uint16_t WN_AFSOn                               :1;
            /*1.142 请先切换至泥地或沙地模式*/
            uint16_t WN_SwitchMudSand                       :1;
            /*1.112 弹射模式退出*/
            uint16_t WN_RaceModeExit                        :1;
            /*1.112 无法进入弹射模式*/
            uint16_t WN_RaceModeFault                       :1;
            /*1.123 像素大灯示宽功能未开启，请在中控中设置开启  No signal*/
            uint16_t WN_PHLWideFunOff                       :1;
            /*1.123 像素大灯示宽功能开启  No signal*/
            uint16_t WN_PHLWideOn                           :1;
            /*1.123 像素大灯示宽功能关闭  No signal*/
            uint16_t WN_PHLWideOff                          :1;
            /*1.136 像素大灯功能关闭  No signal*/
            uint16_t WN_PHLFunOff                           :1;
            /*1.136 像素大灯功能开启  No signal*/
            uint16_t WN_PHLFunOn                            :1;
            /*TBD   请退出简洁模式*/
            uint16_t WN_QuitCompactMode                     :1;
            /*1.163 洗车/拖车模式已激活*/
            uint16_t WN_WashModeActive                      :1;
            /*1.163 车速过高，洗车/拖车模式不可用*/
            uint16_t WN_WashModeSpeed                       :1;
            /*1.163 蓄电池电量低，洗车/拖车模式不可用*/
            uint16_t WN_WashModeBatt                        :1;
            /*1.164 充/放电枪已连接*/
            uint16_t WN_ChargeDisGunConnect                 :1;
            /*1.164 充电枪已连接*/
            uint16_t WN_ChargeGunConnect                    :1;
            /*1.76  请释放电子驻车*/
            uint16_t WN_ReleaseElecPark                     :1;
            /*1.76  请释放后桥差速锁*/
            uint16_t WN_ReleaseRearELD                      :1;
            /*1.111 ESP功能未关闭，弹射起步不可用*/
            uint16_t WN_RLUnavaiESP                         :1;
            /*1.152 动力电池预热完成*/
            uint16_t WN_HeatingComplete                     :1;
            /*1.172 人脸识别已取消*/
            uint16_t WN_FaceCancelled                       :1;
            /*1.172 未找到匹配的人脸*/
            uint16_t WN_FaceNoMatch                         :1;
            /*1.172 人脸识别成功*/
            uint16_t WN_FaceSuccess                         :1;
            /*1.168 混合动力系统暂时受限，单踏板不可用  No signal*/
            uint16_t WN_PedalDynBatt                        :1;
            /*1.168 雪地模式开启，单踏板不可用  No signal*/
            uint16_t WN_PedalDynSnow                        :1;
            /*1.122 超远辅助远光开启  No signal*/
            uint16_t WN_FarBeamOn                           :1;
            /*1.122 超远辅助远光关闭  No signal*/
            uint16_t WN_FarBeamOff                          :1;
            /*1.180 拖车防摆功能已开启*/
            uint16_t WN_TmsTrailer                          :1;
            /*1.180 拖车防摆功能已关闭*/
            uint16_t WN_TsmTrailerOff                       :1;
            /*1.138 四驱换挡直行 请尝试低速直行 TBD*/
            uint16_t WN_4WDGearDelayPlsSlow                 :1;
            /*1.217 抬头显示亮度限制中*/
            uint16_t WN_ARHUDLightLimit                     :1;
            /*1.111 动力电池电量/温度低，弹射起步不可用*/
            uint16_t WN_BattLowLaunchUnavil                 :1;
            /*1.218 横向控制已退出 请控制方向*/
            uint16_t WN_IFCExitPlsControl                   :1;
            /*1.242 ERC系统故障 请立即维修*/
            uint16_t WN_ERCSysErr                           :1;
            /*1.269 紧急车道保持启动*/
            uint16_t WN_IFCLKAFuncOn                        :1;
            /*1.248 转向助力功能受限 请小心驾驶*/
            uint16_t WN_TurnAssistFuncLimit                 :1;
            /*1.242 ERC系统受限*/
            uint16_t WN_ERCSysLimit                         :1;
            /*1.239 主油箱油量低，请添加燃油*/
            uint16_t WN_MainTankLow                         :1;
            /*1.239 主油箱油量低，请及时熄火并切换到副油箱*/
            uint16_t WN_MainTankLowPlsSwitch                :1;
            /*1.239 副油箱油量低，请添加燃油*/
            uint16_t WN_AuxTankLow                          :1;
            /*1.239 副油箱油量低，请及时熄火并切换到主油箱*/
            uint16_t WN_AuxTankLowPlsSwitch                 :1;
            /*1.113 SUPER SPORT*/
            uint16_t WN_DM_B30_Turbo                        :1;
            /*1.113 赛道模式*/
            uint16_t WN_DM_B30_Race                         :1;
            /*1.113 草地/碎石模式*/
            uint16_t WN_DM_B30_GrassGravel                  :1;
            /*1.113 凹凸路模式*/
            uint16_t WN_DM_B30_Uneven                       :1;
            /*1.113 涉水模式*/
            uint16_t WN_DM_B30_Wade4H                       :1;
            /*1.113 低速涉水模式*/
            uint16_t WN_DM_B30_Wade4L                       :1;
            /*1.113 2H模式*/
            uint16_t WN_DM_B30_2H                           :1;
            /*1.113 4H模式*/
            uint16_t WN_DM_B30_4H                           :1;
            /*1.113 SUPER SPORT已选择*/
            uint16_t WN_DM_TurboSelect                      :1;
            /*1.113 赛道模式已选择*/
            uint16_t WN_DM_RaceSelect                       :1;
            /*1.113 草地/碎石模式已选择*/
            uint16_t WN_DM_GrassGravelSelect                :1;
            /*1.113 凹凸路模式已选择*/
            uint16_t WN_DM_UnevenSelect                     :1;
            /*1.113 涉水模式已选择*/
            uint16_t WN_DM_Wade4HSelect                     :1;
            /*1.113 低速涉水模式已选择*/
            uint16_t WN_DM_Wade4LSelect                     :1;
            /*1.113 2H模式已选择*/
            uint16_t WN_DM_2HSelect                         :1;
            /*1.113 4H模式已选择*/
            uint16_t WN_DM_4HSelect                         :1;
            /*1.113 SUPER SPORT切换中，无法进入D/P/R档*/
            uint16_t WN_DM_TurboDPR                         :1;
            /*1.113 赛道模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_RaceDPR                          :1;
            /*1.113 草地/碎石模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_GrassGravelDPR                   :1;
            /*1.113 凹凸路模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_UnevenDPR                        :1;
            /*1.113 涉水模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_Wade4HDPR                        :1;
            /*1.113 低速涉水模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_Wade4LDPR                        :1;
            /*1.113 2H模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_2HDPR                            :1;
            /*1.113 4H模式切换中，无法进入D/P/R档*/
            uint16_t WN_DM_4HDPR                            :1;
            /*1.113 SUPER SPORT*/
            uint16_t WN_DM_TurboSecond                      :1;
            /*1.113 赛道模式*/
            uint16_t WN_DM_RaceSecond                       :1;
            /*1.113 草地/碎石模式*/
            uint16_t WN_DM_GrassGravelSecond                :1;
            /*1.113 凹凸路模式*/
            uint16_t WN_DM_UnevenSecond                     :1;
            /*1.113 涉水模式*/
            uint16_t WN_DM_Wade4HSecond                     :1;
            /*1.113 低速涉水模式*/
            uint16_t WN_DM_Wade4LSecond                     :1;
            /*1.113 2H模式*/
            uint16_t WN_DM_2HSecond                         :1;
            /*1.113 4H模式*/
            uint16_t WN_DM_4HSecond                         :1;
            /*1.114 混动模式已启动*/
            uint16_t WN_DM_PHEV_P2HEVStart                  :1;
            /*1.114 纯电模式已启动*/
            uint16_t WN_DM_PHEV_P2EVStart                   :1;
            /*1.114 能量储备模式已启动*/
            uint16_t WN_DM_PHEV_P2SaveStart                 :1;
            /*1.247 已进入支持NOH路段，欢迎使用*/
            uint16_t WN_AutoNaviStart                       :1;
            /*1.247 前方 XX 米，即将退出自动跟随导航驾驶*/
            uint16_t WN_AutoNaviExitPlsTake                 :1;
            /*1.247 NOH已退出*/
            uint16_t WN_AutoNaviEnd                         :1;
            /*1.242 车速过高 ERC系统自动连接*/
            uint16_t WN_OverSpeedERCSysOn                   :1;
            /*1.242 当前驾驶模式 ERC系统断开禁用*/
            uint16_t WN_ERCSysDisable                       :1;
            /*1.265 越野散热模式已开启*/
            uint16_t WN_OffroadThmSts                       :1;
            /*1.245 低频天线异常*/
            uint16_t WN_AntennaLostErr                      :1;
            /*1.268 自动大灯开启*/
            uint16_t WN_AutoLmpStsOn                        :1;
            /*1.268 自动大灯关闭*/
            uint16_t WN_AutoLmpStsOff                       :1;
            /*1.267 请退出涉水模式*/
            uint16_t WN_PlsExitWadeMode                     :1;
            /*1.267 请减速*/
            uint16_t WN_WadeModePlsSlow                     :1;
            /*1.267 请确认周边工况 如已涉水，谨慎点火*/
            uint16_t WN_WadeModePlsCare                     :1;
            /*1.249 长按紧急下电开关，整车下电！*/
            uint16_t WN_CarPowerShutDown                    :1;
            /*1.296 生命探测功能故障*/
            uint16_t WN_LifeDetectFault                     :1;
            /*1.270 离合器过热*/
            uint16_t WN_ClutchOverheat                      :1;
            /*TBD 弹射起步超时*/
            uint16_t WN_QuickStartOvertime                  :1;
            /*1.295 生命探测功能关闭*/
            uint16_t WN_LifeDetectClose                     :1;
            /*TBD 踩下刹车+请挂N挡+驾驶侧有人或安全带系上*/
            uint16_t WN_StopGearNSeatbelt                   :1;
            /*TBD 踩下刹车+请挂P挡或N挡+驾驶侧有人或安全带系上*/
            uint16_t WN_StopGearPNSeatbelt                  :1;
            /*1.142 请先切换至雪地、泥地、沙地或凹凸路模式*/
            uint16_t WN_SwitchSnowSand                      :1;
            /*1.116 个性化模式已启动*/
            uint16_t WN_Individual                          :1;
            /*TBD 动力系统暂时受限，弹射起步不可用 */
            uint16_t WN_PowerSysLimitLaunchFail             :1;
            /*1.274 当前为预约充电模式*/
            uint16_t WN_ForwardChargeMode                   :1;
            /*1.109 四驱模式，纯电和能量储备模式不可用*/
            uint16_t WN_4WDEVSaveDisable                    :1;
            /*1.250 请注意前车距离+图片*/
            uint16_t WN_V2XCarDistance                      :1;
            /*1.259 注意避让行人+前后图片*/
            uint16_t WN_V2XPeopleRight                      :1;
            /*1.259 注意避让行人+后图片*/
            uint16_t WN_V2XPeopleMid                        :1;
            /*1.259 注意避让行人+前图片*/
            uint16_t WN_V2XPeopleLeft                       :1;
            /*1.255 注意对向来车+图片*/
            uint16_t WN_V2XFaceCar                          :1;
            /*1.254 注意横向来车+两侧图片*/
            uint16_t WN_V2XSideCarTwoSide                   :1;
            /*1.254 注意横向来车+右侧图片*/
            uint16_t WN_V2XSideCarRight                     :1;
            /*1.254 注意横向来车+左侧图片*/
            uint16_t WN_V2XSideCarLeft                      :1;
            /*1.253 前方车辆紧急制动+图片*/
            uint16_t WN_V2XFrontCarAEB                      :1;
            /*1.258 注意前方失控车辆+图片*/
            uint16_t WN_V2XFrontCarUnContron                :1;
            /*1.258 注意后方失控车辆+图片*/
            uint16_t WN_V2XBackCarUnContron                 :1;
            /*1.258 注意周围失控车辆+图片*/
            uint16_t WN_V2XAroundCarUnContron               :1;
            /*1.278 拖车钩故障 请检查*/
            uint16_t WN_HookFaultPlsCheck                   :1;
            /*1.285 空气悬架功能受限！请尽快维修*/
            uint16_t WN_SuspensionFuncLimit                 :1;
            /*1.285 空气悬架故障！请立即维修*/
            uint16_t WN_SuspensionFuncFault                 :1;
            /*1.289 催化器硫含量较高*/
            uint16_t WN_CatalystSuHigh                      :1;
            /*1.289 正在除硫*/
            uint16_t WN_SuClearing                          :1;
            /*1.288 机油液位过低*/
            uint16_t WN_OilLeverLow                         :1;
            /*1.288 机油液位过高*/
            uint16_t WN_OilLeverHigh                        :1;
            /*1.288 机油液位检测故障*/
            uint16_t WN_OilLeverFault                       :1;
            /*1.252 请勿左侧变道+图片*/
            uint16_t WN_V2XLeftLine                         :1;
            /*1.252 请勿右侧变道+图片*/
            uint16_t WN_V2XRightLine                        :1;
            /*1.261 请勿逆向超车+图片*/
            uint16_t WN_V2XReverseLine                      :1;
            /*1.262 请注意前方路况+图片*/
            uint16_t WN_V2XFrontRoad                        :1;
            /*1.256 请注意前方异常车辆+图片*/
            uint16_t WN_V2XFrontCarAttention                :1;
            /*1.257 注意避让紧急车辆*/
            uint16_t WN_V2XLeaveCar                         :1;
            /*1.257 注意避让消防车*/
            uint16_t WN_V2XLeaveFireCar                     :1;
            /*1.257 注意避让救护车*/
            uint16_t WN_V2XLeaveAmbulance                   :1;
            /*1.257 注意避让警车*/
            uint16_t WN_V2XLeavePolice                      :1;
            /*1.257 注意避让工程救援车*/
            uint16_t WN_V2XLeaveEngCar                      :1;
            /*1.251 注意后方盲区车辆+左后盲区图片*/
            uint16_t WN_V2XBackCarLeft                      :1;
            /*1.251 注意后方盲区车辆+右后盲区图片*/
            uint16_t WN_V2XBackCarRight                     :1;
            /*1.251 注意后方盲区车辆+左右后方盲区图片*/
            uint16_t WN_V2XBackCarTwoSide                   :1;
            /*1.160 超级省电模式下动力性和舒适性受限*/
            uint16_t WN_SavePlusPowerLimit                  :1;
            /*1.160 车速过高,无法切换超级省电模式*/
            uint16_t WN_OverSpeedSavePlusFail               :1;
            /*1.160 蠕行功能已激活*/
            uint16_t WN_WormFuncActive                      :1;
            /*1.160 蠕行功能关闭*/
            uint16_t WN_WormFuncOff                         :1;
            /*1.284 蓄电池电量低\n启动发动机更改车辆高度*/
            uint16_t WN_BattLowStartEng                     :1;
            /*1.284 空气悬架系统正在冷却，请等待*/
            uint16_t WN_SuspensionCoolDown                  :1;
            /*1.284 所选高度模式不允许*/
            uint16_t WN_HeightModeDisable                   :1;
            /*1.284 请关闭车门\n以完成高度升降*/
            uint16_t WN_PlsCloseDoorRise                    :1;
            /*1.284 进入举升模式\n空气悬架临时禁用*/
            uint16_t WN_RiseModeSusLimit                    :1;
            /*1.284 空气悬架临时禁用*/
            uint16_t WN_SuspensionTimeLimit                 :1;
            /*1.284 车速高\n无法完成高度切换*/
            uint16_t WN_OverSpeedHeightDisable              :1;
            /*1.287 当前电量高于预设SOC值，无法充电*/
            uint16_t WN_OverDefaultPower                    :1;
            /*1.276 拖车钩已上锁*/
            uint16_t WN_HookLock                            :1;
            /*1.276 拖车钩已解锁*/
            uint16_t WN_HookUnlock                          :1;
            /*1.277 拖车钩电气连接完成*/
            uint16_t WN_HookPowerOn                         :1;
            /*1.279 请先切换为驻车状态*/
            uint16_t WN_SwitchParkSts                       :1;
            /*1.280 请先关闭拖车钩*/
            uint16_t WN_PlsCloseHook                        :1;
            /*1.281 请检查拖车钩连接状态*/
            uint16_t WN_PlsCheckHookSts                     :1;
            /*1.283 已选择标准高度*/
            uint16_t WN_NormalHeightSelect                  :1;
            /*1.283 已选择便捷进出高度*/
            uint16_t WN_SuitHeightSelect                    :1;
            /*1.283 已选择越野高度1*/
            uint16_t WN_ORHeight1Select                     :1;
            /*1.283 已选择越野高度2*/
            uint16_t WN_ORHeight2Select                     :1;
            /*1.283 悬架进入扩展模式*/
            uint16_t WN_SuspensionExtend                    :1;
            /*1.283 悬架锁定在便捷进出高度*/
            uint16_t WN_SuspensionLockHeight                :1;
            /*1.283 已选择后轴装载高度*/
            uint16_t WN_BackShaftHeightSelect               :1;
            /*1.283 已选择自动便捷进出模式*/
            uint16_t WN_SuitHeightModeSelect                :1;
            /*1.283 空气悬架启用拖车模式*/
            uint16_t WN_SuspensionTrailer                   :1;
            /*1.283 空气悬架临时禁用\n以进行换胎、举升*/
            uint16_t WN_SuspensionLimitRise                 :1;
            /*1.283 已选择脚踢开启后轴装载模式*/
            uint16_t WN_KickBackShaft                       :1;
            /*1.283 空气悬架临时禁用\n用于车辆运输*/
            uint16_t WN_SuspensionLimitTrans                :1;
            /*1.283 悬架即将升高\n退出当前低水平高度*/
            uint16_t WN_SuspensionRise                      :1;
            /*1.283 当前车辆处于高位\n请减速慢行*/
            uint16_t WN_CarHighPlsSlow                      :1;
            /*1.289 除硫结束*/
            uint16_t WN_SuClearDown                         :1;
            /*1.282 系统故障，自适应能量回收不可用*/
            uint16_t WN_SysFailACCDisable                   :1;
            /*1.282 传感器故障，自适应能量回收不可用*/
            uint16_t WN_ACCPowerDisable                     :1;
            /*1.282 智能驾驶功能激活，自适应能量回收 不可用*/
            uint16_t WN_HWAACCPowerDisable                  :1;
            /*1.282 ESP功能激活，自适应能量 回收不可用*/
            uint16_t WN_ESPACCPowerDisable                  :1;
            /*1.282 自适应能量回收退出*/
            uint16_t WN_ACCPowerExit                        :1;
            /*TBD 动力电池功率低，纯电模式不可用 已删除*/
            uint16_t WN_BattPowerLowEVDisable               :1;
            /*TBD 动力电池温度低，纯电模式不可用 已删除*/
            uint16_t WN_BattTempLowEVDisable                :1;
            /*TBD 当前为4L模式，纯电和能量储备模式不可用*/
            uint16_t WN_4LModeEVSaveDisable                 :1;
            /*1.76 卡钳过热，转向辅助功能受限*/
            uint16_t WN_CalibreHeatTabLimit                 :1;
            /*TBD 超级省电模式已启动*/
            uint16_t WN_SavePlusModeStart                   :1;
            /*1.264 道路轻度拥堵+图片*/
            uint16_t WN_V2XRoadBlockLever1                  :1;
            /*1.264 道路中度拥堵+图片*/
            uint16_t WN_V2XRoadBlockLever2                  :1;
            /*1.264 道路严重拥堵+图片*/
            uint16_t WN_V2XRoadBlockLever3                  :1;
            /*1.264 道路拥堵+图片*/
            uint16_t WN_V2XRoadBlock                        :1;
            /*TBD 踩下刹车+一键启动 请挂空挡*/
            uint16_t WN_StepBrakeStartGearBlank             :1;
            /*1.38 踩下刹车+请挂空挡+驾驶侧有人或安全带系上*/
            uint16_t WN_StopGearBlankSeatbelt               :1;
            /*1.205 请立即接管*/
            uint16_t WN_PlsTakeOver                         :1;
            /*1.205 请立即接管2Hz提示音*/
            uint16_t WN_PlsTakeOver_2Hz                     :1;
            /*1.205 请立即接管4Hz提示音*/
            uint16_t WN_PlsTakeOver_4Hz                     :1;
            /*1.272 车辆正在自动刹停，请立即接管*/
            uint16_t WN_CarAutoBrakePlsTake                 :1;
            /*1.272 车辆正在靠边停车，请立即接管*/
            uint16_t WN_CarParkingPlsTake                   :1;
            /*1.272 车辆正在紧急刹停，请立即接管*/
            uint16_t WN_CarUrgeBrakePlsTake                 :1;
            /*1.297 驶入匝道失败，请立即接管*/
            uint16_t WN_MoveRampFailPlsTake                 :1;
            /*1.297 汇入主路失败，请立即接管*/
            uint16_t WN_MoveMainFailPlsTake                 :1;
            /*1.297 汇入主路失败，请立即接管2Hz提示音*/
            uint16_t WN_MoveMainFailPlsTake_2Hz             :1;
            /*1.297 汇入主路失败，请立即接管4Hz提示音*/
            uint16_t WN_MoveMainFailPlsTake_4Hz             :1;
            /*1.297 转弯失败，请立即接管*/
            uint16_t WN_TurnFailPlsTake                     :1;
            /*1.297 转弯失败，请立即接管2Hz提示音*/
            uint16_t WN_TurnFailPlsTake_2Hz                 :1;
            /*1.297 转弯失败，请立即接管4Hz提示音*/
            uint16_t WN_TurnFailPlsTake_4Hz                 :1;
            /*1.297 无法成功通过收费站，请立即接管*/
            uint16_t WN_TollGateFailPlsTake                 :1;
            /*1.297 无法成功通过收费站，请立即接管2Hz提示音*/
            uint16_t WN_TollGateFailPlsTake_2Hz             :1;
            /*1.297 无法成功通过收费站，请立即接管4Hz提示音*/
            uint16_t WN_TollGateFailPlsTake_4Hz             :1;
            /*1.297 无法成功通过环岛，请立即接管*/
            uint16_t WN_RoundaboutFailPlsTake               :1;
            /*1.297 无法成功通过环岛，请立即接管2Hz提示音*/
            uint16_t WN_RoundaboutFailPlsTake_2Hz           :1;
            /*1.297 无法成功通过环岛，请立即接管4Hz提示音*/
            uint16_t WN_RoundaboutFailPlsTake_4Hz           :1;
            /*1.256 请注意前方异常车辆+左前方图片*/
            uint16_t WN_V2XFrontCarAttentionLeft            :1;
            /*1.256 请注意前方异常车辆+右前方图片*/
            uint16_t WN_V2XFrontCarAttentionRight           :1;
            /*1.204 前方急转弯，请手扶方向盘*/
            uint16_t WN_UrgeTurnPlsHoldWheel                :1;
            /*1.294 快充桩故障，充电停止*/
            uint16_t WN_FastChrgFault                       :1;
            /*1.273 无法开启NOH，请前往4S店修理*/
            uint16_t WN_NOHFailPlsFix                       :1;
            /*1.273 无法开启NOH，请挂P挡重新尝试*/
            uint16_t WN_NOHFailPlsGearP                     :1;
            /*1.273 请手动进入匝道*/
            uint16_t WN_MoveRampFailPlsHand                 :1;
            /*1.273 这次有点难，需要你的帮助*/
            uint16_t WN_MoveMainFailPlsHand                 :1;
            /*1.273 转弯失败，请手动尝试*/
            uint16_t WN_TurnFailPlsHand                     :1;
            /*1.273 无法成功通过收费站，请手动尝试*/
            uint16_t WN_TollGateFailPlsHand                 :1;
            /*1.273 无法成功通过环岛，请手动尝试*/
            uint16_t WN_RoundaboutFailPlsHand               :1;
            /*1.273 已重新规划路径*/
            uint16_t WN_RePlanLanes                         :1;
            /*1.273 路况复杂，请手动变道汇出*/
            uint16_t WN_PlsHandChangeLanes                  :1;
            /*1.297 驶入匝道失败，请控制方向盘*/
            uint16_t WN_MoveRampFailHandWheel               :1;
            /*1.297 驶入匝道失败，请控制方向盘2Hz提示音*/
            uint16_t WN_MoveRampFailHandWheel_2Hz           :1;
            /*1.297 汇入主路失败，请控制方向盘*/
            uint16_t WN_MoveMainFailHandWheel               :1;
            /*1.297 转弯失败，请控制方向盘*/
            uint16_t WN_TurnFailPlsHandWheel                :1;
            /*1.297 无法成功通过收费站，请控制方向盘*/
            uint16_t WN_TollGateFailPlsHandWheel            :1;
            /*1.297 无法成功通过环岛，请控制方向盘*/
            uint16_t WN_RoundaboutFailPlsHandWheel          :1;
            /*1.201 智慧巡航不可用*/
            uint16_t WN_TJAICADisable                       :1;
            /*1.204 车速低于40km/h，变道辅助不可用*/
            uint16_t WN_LowSpeedLaneAssistDisable           :1;
            /*1.204 车速高于120km/h，变道辅助不可用*/
            uint16_t WN_OverSpeedLaneAssistDisable          :1;
            /*1.297 当前无法开启智慧巡航系统，请擦拭摄像头*/
            uint16_t WN_TJAICAFaultPlsFixCamera             :1;
            /*1.297 当前无法开启智慧巡航系统，请前往4S店修理*/
            uint16_t WN_TJAICAFaultPlsFix                   :1;
            /*1.143 请确认前排手机充电区域是否有异物或者偏离*/
            uint16_t WN_WPCChargeZoneFront                  :1;
            /*1.143 请确认后排手机充电区域是否有异物或者偏离*/
            uint16_t WN_WPCChargeZoneRear                   :1;
            /*1.143 请确认后排右侧手机充电区域是否有异物或者偏离*/
            uint16_t WN_WPCChargeZoneRR                     :1;
            /*1.143 请确认后排左侧手机充电区域是否有异物或者偏离*/
            uint16_t WN_WPCChargeZoneRL                     :1;
            /*1.247 xx公里/xx米后，将退出自动跟随导航驾驶*/
            uint16_t WN_AutoNaviExit                        :1;
            /*1.282 建议松开油门，便于经济驾驶*/
            uint16_t WN_AcceleratorPowen                    :1;
            /*1.203 过弯安全降速*/
            uint16_t WN_TurnSafeSlow                        :1;
            /*1.247 XX公里/米后将退出NOH*/
            uint16_t WN_NOHExit                             :1;
            /*1.247 请准备接管，XX米后NOH将退出*/
            uint16_t WN_NOHExitPlsTake                      :1;
            /*1.247 请立即接管，NOH已退出*/
            uint16_t WN_NOHFinishExit                       :1;
            /*1.247 若车速高于125km/h，NOH将退出*/
            uint16_t WN_OverSpeedNOHExit                    :1;
            /*1.247 即将进入快速车道*/
            uint16_t WN_DriveIntoHighSpeed                  :1;
            /*1.247 进入匝道，请注意安全*/
            uint16_t WN_DriveIntoRamp                       :1;
            /*1.247 巡航车速设为XXkm/h*/
            uint16_t WN_NOHSetAccSpeed                      :1;
            /*1.290 N挡已锁止\n无法换挡*/
            uint16_t WN_LockNGearDisable                    :1;
            /*1.267 请轻踩制动，测试制动性能*/
            uint16_t WN_PlsPressBrakeTest                   :1;
            /*1.177 请选择4A/4H*/
            uint16_t WN_4Aor4HModeSelect                    :1;
            /*1.12/1.13/1.14 制动液位开关故障*/
            uint16_t WN_BrakeSwitchFault                    :1;
            /*TBD 安全备用系统已启动*/
            uint16_t WN_SafeBackStart                       :1;
            /*TBD 安全备用系统即将靠边停车*/
            uint16_t WN_SafeBackStopCar                     :1;
            /*1.11 请切换到非P挡释放驻车*/
            uint16_t WN_SwitchGearReleaseBrake              :1;
            /*1.116 泥地模式已启动*/
            uint16_t WN_DM_EV_MuddyStart                    :1;
            /*1.116 沙地模式已启动*/
            uint16_t WN_DM_EV_SandStart                     :1;
            /*1.116 超级运动模式已启动*/
            uint16_t WN_DM_EV_SportPlusStart                :1;
            /*1.17/1.18  一体式车箱后板开报警*/
            uint16_t WN_OneTrunkBoardOpen                   :1;
            /*1.17/1.18  分体式车箱后板开报警*/
            uint16_t WN_SplitTrunkBoardOpen                 :1;
            /*1.303 慢充电口盖打开的效果示意图片*/
            uint16_t WN_SlowFillingFlapOpenPicture          :1;
            /*1.303 快充电口盖打开的效果示意图片*/
            uint16_t WN_QuickChargeFlapOpenPicture          :1;
            /*1.303 慢充口盖未关*/
            uint16_t WN_SlowFillingFlapNotClosed            :1;
            /*1.303 快充口盖未关*/
            uint16_t WN_QuickChargeFlapNotClosed            :1;
            /*1.262 请注意前方过水路面*/
            uint16_t WN_AttentionWaterRoad                  :1;
            /*1.262 请注意前方低洼路面*/
            uint16_t WN_AttentionLowlyingRoad               :1;
            /*1.262 请注意前方湿滑路面*/
            uint16_t WN_AttentionWetRoad                    :1;
            /*1.262 请注意前方急转弯*/
            uint16_t WN_AttentionSharpTurn                  :1;
            /*1.262 请注意前方道路障碍*/
            uint16_t WN_NoteRoadFailure                     :1;
            /*1.262 请注意前方不平路面*/
            uint16_t WN_NoteUnevenRoad                      :1;
            /*1.262 请注意前方傍山险路*/
            uint16_t WN_AttentionDangerousRoad              :1;
            /*1.262 请注意前方泥石流*/
            uint16_t WN_AwareDebrisFlow                     :1;
            /*1.262 请注意前方桥梁*/
            uint16_t WN_NoteBridge                          :1;
            /*1.262 请注意前方隧道*/
            uint16_t WN_AttentionTunnel                     :1;
            /*1.262 请注意前方火灾*/
            uint16_t WN_AwareFire                           :1;
            /*1.262 请注意前方落石*/
            uint16_t WN_NoteFallingRock                     :1;
            /*1.262 请注意前方结冰路面*/
            uint16_t WN_NoteIcyRoad                         :1;
            /*1.262 请注意前方横风路段*/
            uint16_t WN_NoteCrosswindRoad                   :1;
            /*1.262 请注意前方堤坝路段*/
            uint16_t WN_EmbankmentRoad                      :1;
            /*1.262 请注意前方连续急转弯*/
            uint16_t WN_NoteContinuousSharpTurn             :1;
            /*1.262 请注意前方道路变窄*/
            uint16_t WN_NoteRoadNarrows                     :1;
            /*1.262 请注意前方车辆汇入*/
            uint16_t WN_NoteIncomingTraffic                 :1;
            /*1.262 请注意前方道路设施损坏*/
            uint16_t WN_NotedamgeRoadFacities               :1;
            /*1.262 请注意前方散落物体*/
            uint16_t WN_AwareScatteredObject                :1;
            /*1.273 NOH已恢复*/
            uint16_t WN_NOHIsResumed                        :1;
            /*1.273 前方汇入，小心侧方来车*/
            uint16_t WN_MargeWatchOutFOrCarsComing          :1;
            /*1.273 正在减速，准备汇出*/
            uint16_t WN_SlowingDownForDischarge             :1;
            /*1.273 NOH已退出，请接管方向盘*/
            uint16_t WN_NOExitedTakeSteeringWheel           :1;
            /*1.273 车道线不清晰，请小心驾驶*/
            uint16_t WN_LaneLineNotClearDriveCarefully      :1;
            /*1.301 四驱系统暂时锁定*/
            uint16_t WN_FourWheelDriveSystem                :1;
            /*1.234 颗粒捕集器严重堵塞，请入站检查*/
            uint16_t WN_CatcherSeriouslyBlocked             :1;
            /*充电状态显示（延时充电）*/
            uint16_t WN_ChargingStatusDisplay               :1;
            /*1.301 车速过高四驱系统暂时解除锁定*/
            uint16_t WN_ExcessiveSpeedFourWheelDrive        :1;
            /*1.302 导航降速已激活，请注意车速*/
            uint16_t WN_NavigationSlowDownActive            :1;
            /*1.302 请注意减速*/
            uint16_t WN_PlsPayAttentionToSlowDown           :1;
            /*1.302 前方导航限速60km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward60kmPerHour        :1;
            /*1.302 前方导航限速70km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward70kmPerHour        :1;
            /*1.302 前方导航限速80km/h，请注意减80*/
            uint16_t WN_SPeedLimitForward80kmPerHour        :1;
            /*1.302 前方导航限速90km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward90kmPerHour        :1;
            /*1.302 前方导航限速100km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward100kmPerHour       :1;
            /*1.302 前方导航限速110km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward110kmPerHour       :1;
            /*1.302 前方导航限速120km/h，请注意减速*/
            uint16_t WN_SpeedLimitForward120kmPerHour       :1;
            /*1.302 请注意当前设置车速超过导航限速*/
            uint16_t WN_CurrentlyExceedNavigationLimit      :1;
            /*1.203  向下拨动怀挡，确认调整车速*/
            uint16_t WN_TurnGearDownConfirmSpeedAdjustment  :1;
            /*1.203  按cruise键，确认调整车速*/
            uint16_t WN_PressCruiseConfirmAdjustment        :1;
            /*1.247 即将从主路汇出*/
            uint16_t WN_ComingOutMainRoad                   :1;
            /*1.116 女神模式已启动*/
            uint16_t WN_GoddessModeActivated                :1;
            /*1.306 洗涤液不足 请及时加注*/
            uint16_t WN_WshngLiquidNotEnough                :1;
            /*1.233 尿素不足，XXXkm后无法启动，请加注*/
            uint16_t WN_UreaInsCantStartAfter               :1;
            /*1.233 尿素严重不足，xxxkm后无法启动，请加注*/
            uint16_t WN_UreaInsSeriouslyCantStartAfter      :1;
            /*1.233 尿素罐空，下次无法启动，请加注*/
            uint16_t WN_UreaEmptyCantStartNext              :1;
            /*1.233 尿素罐空，无法启动，请加注*/
            uint16_t WN_UreaEmptyCantStart                  :1;
            /*1.233 尿素不合格，xxxkm后无法启动，请维修*/
            uint16_t WN_UreaUnqualifyCantStartAfter         :1;
            /*1.233 尿素不合格，下次无法启动，请维修*/
            uint16_t WN_UreaUnqualifyCantStartNext          :1;
            /*1.233 尿素不合格，无法启动，请维修*/
            uint16_t WN_UreaUnqualifyCantStart              :1;
            /*1.233 尿素喷射中断，xxxkm后无法启动，请维修*/
            uint16_t WN_UreaFillStopCantStartAfter          :1;
            /*1.233 尿素喷射中断，下次无法启动，请维修*/
            uint16_t WN_UreaFillStopCantStartNext           :1;
            /*1.233 尿素喷射中断，无法启动，请维修*/
            uint16_t WN_UreaFillStopCantStart               :1;
            /*1.233 尿素消耗偏差，xxxkm后无法启动，请维修*/
            uint16_t WN_ConsumDeviatCantStartAfter          :1;
            /*1.233 尿素消耗偏差，下次无法启动，请维修*/
            uint16_t WN_ConsumDeviatCantStartNext           :1;
            /*1.233 尿素消耗偏差，无法启动，请维修*/
            uint16_t WN_ConsumDeviatCantStart               :1;
            /*1.309 请关闭机舱盖后，重新启动车辆*/
            uint16_t WN_HoodClosedRestart                   :1;
            /*1.310 请关闭油箱盖后，重新启动车辆*/
            uint16_t WN_OilTankClosedRestart                :1;
            /*TBD 人脸识别失败*/
            uint16_t WN_FaceFail                            :1;
            /*TBD 人脸信息未录入，请尝试其它方式登录*/
            uint16_t WN_FaceInforNotEntered                 :1;
            /*1.307 舒适制动功能已开启*/
            uint16_t WN_CSTActive                           :1;
            /*1.307 舒适制动功能已关闭*/
            uint16_t WN_CSTClosed                           :1;
            /*1.109 车辆处于强制纯电模式，动力电池可用功率低*/
            uint16_t WN_EVModeBattPowerLow                  :1;
            /*1.308 连接成功，正在放电*/
            uint16_t WN_ConnectedDischarging                :1;
            /*1.308 连接成功，未放电*/
            uint16_t WN_ConnectedNoDischarge                :1;
            /*TBD 前轮自动回正中…*/
            uint16_t WN_FrontTireAutoBack                   :1;
            /*TBD 方向盘自动回正功能退出*/
            uint16_t WN_SteeringAutomaFuncsExits            :1;
            /*1.179 紧急呼叫功能受限 */
            uint16_t WN_EmergencyCallLimited                :1;
            /*1.314 动力电池电量低，请启动发动机用于放电*/
            uint16_t WN_PowerLowStartEngine                 :1;
            /*1.314 放电功能激活失败*/
            uint16_t WN_FailedActivateDischarge             :1;
            /*1.102 动力电池系统受限*/
            uint16_t WN_PowerSystemLimited                  :1;
            /*1.312 后轮转向故障,请小心驾驶*/
            uint16_t WN_RearWheelSteeringFailure            :1;
            /*1.312 后轮转向功能受限*/
            uint16_t WN_RearWheelSteeringLimited            :1;
            /*TBD ETC系统故障*/
            uint16_t WN_ETCSystemFault                      :1;
            /*1.80 放电装置已移除*/
            uint16_t WN_DischargeDeviceRemoved              :1;
            /*TBD ETC通行正常*/
            uint16_t WN_ETCNormal                           :1;
            /*TBD ETC通行异常*/
            uint16_t WN_ETCAbnormal                         :1;
            /*TBD 您本次高速通行正常，预计消费 XX.XX元*/
            uint16_t WN_ExpresswayNormal                    :1;
            /*1.380 当前地形模式下不可解锁*/
            uint16_t WN_CurrentTerrainCannotUnlocked        :1;
            /*1.382 动力电池预热中*/
            uint16_t WN_PowerBattWarmup                     :1;
            /*1.382 充电机故障*/
            uint16_t WN_ChargerFailure                      :1;
            /*1.81 请断开充/放电装置*/
            uint16_t WN_DisconnectChargingDischarging       :1;
            /*TBD 蓄电池电量过低，系统3分钟后关闭电源，请启动车辆*/
            uint16_t WN_PowerOffAfterThreeMinute            :1;
            /*TBD ACC/CC激活：上下左右按键描述*/
            uint16_t WN_ACCCCActive                         :1;
            /*TBD ACC/CC取消：上下左右按键描述*/
            uint16_t WN_ACCCCCancel                         :1;
            /*1.315 车门锁：行车过程中只能通过紧急开关开启，请参见用户手册*/
            uint16_t WN_PleaseReadUserManual                :1;
            /*1.113 新手模式*/
            uint16_t WN_NoviceModel                         :1;
            /*1.113 新手模式已选择*/
            uint16_t WN_NoviceModelSelect                   :1;
            /*1.113 新手模式切换中，无法进入D/R/P挡*/
            uint16_t WN_NoviceModelSwitch                   :1;
            /*TBD 螃蟹模式故障*/
            uint16_t WN_CrabModeFailure                     :1;
            /*1.235 前轮回正完成(应用项目：GEEP4.0)*/
            uint16_t WN_FrontTireAlignFinishGEEP40          :1;
            /*TBD 工厂模式*/
            uint16_t WN_FactoryPatternGEEP40                :1;
            /*TBD 展厅模式*/
            uint16_t WN_GalleryMode                         :1;
            /*1.8 运输模式(应用项目：GEEP4.0)*/
            uint16_t WN_StatBattLowTranModeGEEP40           :1;
            /*1.8 12V电源系统故障，舒适功能关闭，请联系4S店维修(应用项目：GEEP4.0)*/
            uint16_t WN_StatBattLowComfortOffGEEP40         :1;
            /*1.8 电量消耗过多，进入省电模式(应用项目：GEEP4.0)*/
            uint16_t WN_StatBattLowSavingModeGEEP40         :1;
            /*1.8 蓄电池电量过低，系统3分钟后关闭电源，请启动车辆(应用项目：GEEP4.0)  */
            uint16_t WN_PowerOffAfterThreeMinuteGEEP40      :1;
            /*TBD 充电口盖已开启*/
            uint16_t WN_ChargingCoverOpen                   :1;
            /*1.8 12V蓄电池电量低，舒适功能降功率(应用项目：GEEP4.0)*/
            uint16_t WN_StatBattLowPwrReduceGEEP40          :1;
            /*1.273 汇入失败，继续巡航*/
            uint16_t WN_InboundFailedContinueCruise         :1;
            /*TBD xx公里/xx米后即将进入匝道*/
            uint16_t WN_ApproachingRamp                     :1;
            /*TBD 螃蟹模式已退出(应用项目：GEEP4.0)*/
            uint16_t WN_CrabModeExitedGEEP40                :1;
            /*TBD 螃蟹模式已开启(应用项目：GEEP4.0)*/
            uint16_t WN_CrabModeEnabledGEEP40               :1;
            /*TBD 螃蟹模式已待机(应用项目：GEEP4.0)*/
            uint16_t WN_CrabModeStandbyGEEP40               :1;
            /*1.311 动力电池电量较低，请及时启动车辆*/
            uint16_t WN_LowBatteryStartVehicle              :1;
            /*1.311 动力电池电量较低，请及时启动车辆或插枪充电*/
            uint16_t WN_LowBatteryPlugGunCharge             :1;
            /*1.168 驾驶辅助功能开启，单踏板不可用*/
            uint16_t WN_AuxiliaryOpenSingPedalUnable        :1;
            /*1.210 智慧巡航已退出，紧急刹车辅助启动*/
            uint16_t WN_SmartCruiseouteEmergencyBrake       :1;
            /*1.411 转向功能故障，请低速行驶(应用项目：GEEP4.0)*/
            uint16_t WN_SteerFailDrivelowSpeed              :1;
            /*1.411 转向功能受限，请小心驾驶(应用项目：GEEP4.0)*/
            uint16_t WN_SteerFailDriveCarefully             :1;
            /*1.412 方向盘正在自动对齐，请勿触摸方向盘(应用项目：GEEP4.0)*/
            uint16_t WN_SteeringAutoNotTouchWheel           :1;
            /*1.412 方向盘自动对齐完成(应用项目：GEEP4.0)*/
            uint16_t WN_SteeringWheelAutoaLigned            :1;
            /*1.113 新手模式*/
            uint16_t WN_DM_B30_Novice                       :1;
            /*1.178 加油准备中(有声音)*/
            uint16_t WN_FuelPrepare_Sound                   :1;
            /*定速巡航速度值 Value：0-240 km/h  0-150 mph*/
            uint16_t WN_TgtCrsSpdData                       :8;
            /*定速巡航速度有效性  Value: 0~Invalid 1~Valid*/
            uint16_t WN_TgtCrsSpdVld                        :1;
            /*驾驶模式场景值 Value:1-5 ~ Drive Mode case1-case5*/
            uint16_t WN_DrvModeCase                         :8;
            /*自动导航辅助驾驶距离数据 Value:0-0xFFFF*/
            uint16_t WN_NOHDistData                         :16;
            /*道路危险状态提示图片 Value：0-0x14*/
            uint16_t WN_V2XFrontRoadData                    :8;
            /*巡航车速 Value：0-0xFE*/
            uint16_t WN_AccSpdSetValue                      :8;
            /*尿素剩余行驶距离值 Value：0-0xFFFF*/
            uint16_t WN_UreaRemainDistData                  :16;
            /*加油准备中进度值：0-0x63*/
            uint16_t WN_PressReliProgsData                  :8;
        }s_u32Warning_status_t;
    }u_WN_Moduleu32Warning_status_t;
}IPC_M2S_ClusterAppAPPWN_Module_t;

/* Pack function of sub message WN_Module */
int32_t IPC_M2S_ClusterAppAPPWN_Module_Pack(IPC_M2S_ClusterAppAPPWN_Module_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message WN_Module */
int32_t IPC_M2S_ClusterAppAPPWN_Module_Parse(IPC_M2S_ClusterAppAPPWN_Module_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Odo */
typedef struct
{
    /*ODO value unit:1km*/
    uint32_t Value;
    /*0:km,1:kpm*/
    uint8_t Uints;
    /*0:valid 1:Invalid*/
    uint8_t Valid;
}IPC_M2S_ClusterAppAPPOdo_t;

/* Pack function of sub message Odo */
int32_t IPC_M2S_ClusterAppAPPOdo_Pack(IPC_M2S_ClusterAppAPPOdo_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Odo */
int32_t IPC_M2S_ClusterAppAPPOdo_Parse(IPC_M2S_ClusterAppAPPOdo_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: SIA */
typedef struct
{
    /*SIA value unit:1km*/
    int32_t Value;
    /*0:km,1:kpm*/
    uint8_t Uints;
    /*0:valid 1:Invalid*/
    uint8_t Valid;
}IPC_M2S_ClusterAppAPPSIA_t;

/* Pack function of sub message SIA */
int32_t IPC_M2S_ClusterAppAPPSIA_Pack(IPC_M2S_ClusterAppAPPSIA_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SIA */
int32_t IPC_M2S_ClusterAppAPPSIA_Parse(IPC_M2S_ClusterAppAPPSIA_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TPMS */
typedef struct
{
    union
    {
        uint32_t TPMS_Inf[4];
        struct
        {
            /*左前轮胎压状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fl_tire_press_status                   :2;
            /*左前轮胎压颜色 0: White    1:Red*/
            uint32_t fl_tire_press_color                    :1;
            /*左前轮胎压值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t fl_tire_press_value                    :9;
            /*左前轮胎温状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fl_tire_temp_status                    :2;
            /*左前轮胎温颜色 0: White    1:Red*/
            uint32_t fl_tire_temp_color                     :1;
            /*左前轮胎温值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t fl_tire_temp_value                     :9;
            /*左前轮显示状态 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t fl_tire_behavior_color                 :1;
            /*右前轮胎压状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fr_tire_press_status                   :2;
            /*右前轮胎压颜色 0: White    1:Red*/
            uint32_t fr_tire_press_color                    :1;
            /*右前轮胎压值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t fr_tire_press_value                    :9;
            /*右前轮胎温状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fr_tire_temp_status                    :2;
            /*右前轮胎温颜色 0: White    1:Red*/
            uint32_t fr_tire_temp_color                     :1;
            /*右前轮胎温值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t fr_tire_temp_value                     :9;
            /*右前轮显示状态 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t fr_tire_behavior_color                 :1;
            /*左后轮胎压状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rl_tire_press_status                   :2;
            /*左后轮胎压颜色 0: White    1:Red*/
            uint32_t rl_tire_press_color                    :1;
            /*左后轮胎压值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t rl_tire_press_value                    :9;
            /*左后轮胎温状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rl_tire_temp_status                    :2;
            /*左后轮胎温颜色 0: White    1:Red*/
            uint32_t rl_tire_temp_color                     :1;
            /*左后轮胎温值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t rl_tire_temp_value                     :9;
            /*左后轮显示状态 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t rl_tire_behavior_color                 :1;
            /*右后轮胎压状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rr_tire_press_status                   :2;
            /*右后轮胎压颜色 0: White    1:Red*/
            uint32_t rr_tire_press_color                    :1;
            /*右后轮胎压值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t rr_tire_press_value                    :9;
            /*右后轮胎温状态 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rr_tire_temp_status                    :2;
            /*右后轮胎温颜色 0: White    1:Red*/
            uint32_t rr_tire_temp_color                     :1;
            /*右后轮胎温值 0-0xFE：Valid   0xFF:Invalid*/
            uint32_t rr_tire_temp_value                     :9;
            /*右后轮显示状态 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t rr_tire_behavior_color                 :1;
            /*0:kpa   1:psi   2:bar*/
            uint32_t tire_press_unit                        :2;
            /*0:Celsius   1:Fahrenheit*/
            uint32_t tire_temp_unit                         :1;
        }s_TPMS_Inf_t;
    }u_TPMSTPMS_Inf_t;
}IPC_M2S_ClusterAppAPPTPMS_t;

/* Pack function of sub message TPMS */
int32_t IPC_M2S_ClusterAppAPPTPMS_Pack(IPC_M2S_ClusterAppAPPTPMS_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TPMS */
int32_t IPC_M2S_ClusterAppAPPTPMS_Parse(IPC_M2S_ClusterAppAPPTPMS_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Chime */
typedef struct
{
    /*e_SoundType_RadarDWDLongRe_1 
    Chime id = 8    涉水深度DWD Long-重复
    
    e_SoundType_RadarDWD3Hz_1
    Chime id = 15    涉水深度DWD 3Hz-重复
    
    e_SoundType_RadarDWD1_5Hz_1
    Chime id = 21    涉水深度DWD 1.5Hz-重复
    （以上声音ID功能 EV车型暂不实现 与其他项目ID保持一致）*/
    uint8_t SoundId;
    /*start new sound volume  0:High 1:Middle 2:Low*/
    uint8_t Volume;
    /*0:NULL 1:start 2:immediately start 3 :stop 4 :immediately stop 5:read 6:set current sound volume*/
    uint8_t Operation;
    /*For send tick*/
    uint8_t Toggle;
    /*sound repeat time */
    uint32_t RepeatTime;
    /*Sound play time ,0: continue*/
    uint32_t Soundtrack;
}IPC_M2S_ClusterAppAPPChime_t;

/* Pack function of sub message Chime */
int32_t IPC_M2S_ClusterAppAPPChime_Pack(IPC_M2S_ClusterAppAPPChime_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Chime */
int32_t IPC_M2S_ClusterAppAPPChime_Parse(IPC_M2S_ClusterAppAPPChime_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TripComputer */
typedef struct
{
    /*buf0:trip_a ;buf1:trip_b
    0xFFFF display dash 
    factor:10, eg 85=8.5KM*/
    uint32_t Trip[2];
    /*buf0:afe_a ;buf1:afe_b
    0xFFFF display dash 
    factor:10, eg 85=8.5L/100KM
    ;0xFFFE :Disable display */
    uint16_t AFE[2];
    /*0xFFFF display dash 
    factor:10, eg 85=8.5L/100KM
    ;0xFFFE :Disable display */
    uint32_t IFE;
    /*0:L/100KM, 1:L/H, 2:KM/L, 3:GPH, 4:MPG
    */
    uint8_t IFE_Unit;
    /*0xFFFF display dash
    factor:1, eg 123=123KM
    ;0xFFFE :Disable display 
    */
    uint32_t DTE;
    /*buf0:avs_a ;buf1:avs_b；0xFFFF display dash 
    factor:1 eg 100=100km/h
    ;0xFFFE :Disable display */
    uint16_t AVS[2];
    /*buf0:travel_h_a ;buf1:travel_h_b ；0xFF display dash 
    ;0xFE :Disable display 
    
    */
    uint8_t Travel_time_Hour[2];
    /*buf0:travel_m_a ;buf1:travel_m_b；0xFF display dash 
    ;0xFE :Disable display */
    uint8_t Travel_time_MIN[2];
    /*0: DTE-KM AVS:KM/H, 1:DTE-MILES AVS:MPH*/
    uint8_t DTE_AVS_Uint;
    /*0:L/100KM, 1:KM/L, 2:MPG
    */
    uint8_t AFE_Uint;
    /*0xFFFF display dash
    factor:1, eg 123=123KM
    ;0xFFFE :Disable display 
    */
    uint16_t Phev_Dte_Ipc;
    /*Suitable for independent twin tanks : Buf[0] main Dte； Buf[1] aux Dte；0xFFFF display dash
    factor:1, eg 123=123KM
    ;0xFFFE :Disable display 
    */
    uint32_t DTE_Dual[2];
}IPC_M2S_ClusterAppAPPTripComputer_t;

/* Pack function of sub message TripComputer */
int32_t IPC_M2S_ClusterAppAPPTripComputer_Pack(IPC_M2S_ClusterAppAPPTripComputer_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TripComputer */
int32_t IPC_M2S_ClusterAppAPPTripComputer_Parse(IPC_M2S_ClusterAppAPPTripComputer_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: FUEL */
typedef struct
{
    /* factor =10 ,eg 505=50.5% */
    uint16_t TankFuelLevelPercent;
    /*0:Left 1:Right*/
    uint8_t Tankportposition;
    /*0:OFF;1:ON ;2 500ms flash and percent blue; 3 500ms flash and percent red*/
    uint8_t Low_fuel_warning;
    /* factor =10 ,eg 505=50.5% 燃油低报警灯点亮阈值*/
    uint16_t LFW_Trigger_Ipc;
    /* factor =10 ,eg 505=50.5% 燃油低报警灯熄灭阈值*/
    uint16_t LFW_Release_Ipc;
    /*Suitable for independent twin tanks : Buf[0] main tank； Buf[1] aux tank；factor =10 ,eg 505=50.5%*/
    uint16_t TankFuelLevelPercent_Dual[2];
    /* Suitable for independent twin tanks : Buf[0] main tank； Buf[1] aux tank；0:Left 1:Right*/
    uint8_t Tankportposition_Dual[2];
    /* Suitable for independent twin tanks :   Buf[0] main tank； Buf[1] aux tank；0:OFF;1:ON ;2 500ms flash and percent blue; 3 500ms flash and percent red*/
    uint8_t Low_fuel_warning_Dual[2];
    /*  Suitable for independent twin tanks :  Buf[0] main tank； Buf[1] aux tank；factor =10 ,eg 505=50.5% 燃油低报警灯点亮阈值*/
    uint16_t LFW_Trigger_Ipc_Dual[2];
    /*  Suitable for independent twin tanks : Buf[0] main tank； Buf[1] aux tank；factor =10 ,eg 505=50.5% 燃油低报警灯熄灭阈值*/
    uint16_t LFW_Release_Ipc_Dual[2];
    /*Suitable for independent twin tanks : 0x0:Master Oil Box
    0x1:Auxiliary Oil Box
    0x2:Engine State Dissatisfy
    0x3:Reserved*/
    uint8_t OilBoxSplySts_Switch_Dual;
    /*0:Single Tank  1:Dual Tank*/
    uint8_t Fuel_Tank_System;
}IPC_M2S_ClusterAppAPPFUEL_t;

/* Pack function of sub message FUEL */
int32_t IPC_M2S_ClusterAppAPPFUEL_Pack(IPC_M2S_ClusterAppAPPFUEL_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message FUEL */
int32_t IPC_M2S_ClusterAppAPPFUEL_Parse(IPC_M2S_ClusterAppAPPFUEL_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Speedo */
typedef struct
{
    /*Vehicle Speed Calculated Metric:
    value range:0~260(1km/h) Invalid:0xEFFF(display 0);
    Vehicle Speed Calculated Imperial:
    value range:0~180(1mph) Invalid:0xEFFF(display 0)*/
    int32_t VehSpdCalculated;
    /*Real Vehicle Speed 
    Vehicle Speed Calculated Metric:
    value range:0~260(1km/h) Invalid:0xEFFF(display 0);
    Vehicle Speed Calculated Imperial:
    value range:0~180(1mph) Invalid:0xEFFF(display 0)*/
    int32_t VehSpdReal;
    /*Vehicle Speed Max Metric: 260km/h or 240 km/h;
    Vehicle Speed Max Imperial: 180 mph or 160 mph*/
    int32_t VehSpdMax;
    /*0:km/h(metric) ; 1:mph(Imperial)*/
    uint8_t VehSpdUnit;
    /*0: normal 1: red display;*/
    uint8_t RedDispaly;
    /*0: vehicle stop; 1: vehicle running*/
    uint8_t VehRunningSts;
    /*指针车速
    Vehicle Speed Calculated Metric:
    value range:0~260(1km/h) Invalid:0xEFFF(display 0);
    Vehicle Speed Calculated Imperial:
    value range:0~180(1mph) Invalid:0xEFFF(display 0)*/
    int32_t VehSpdAnalog;
}IPC_M2S_ClusterAppAPPSpeedo_t;

/* Pack function of sub message Speedo */
int32_t IPC_M2S_ClusterAppAPPSpeedo_Pack(IPC_M2S_ClusterAppAPPSpeedo_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Speedo */
int32_t IPC_M2S_ClusterAppAPPSpeedo_Parse(IPC_M2S_ClusterAppAPPSpeedo_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Tacho */
typedef struct
{
    /*Invalid:0xEFFF（display 0.0 rpm）*/
    int32_t EngSpdCalculated;
    /*engine speed max: 6000rpm or 8000rpm*/
    int32_t EngSpdMax;
    /*0: normal 1: red display;*/
    uint8_t RedDispaly;
    /*the running status of engine: 1:running; 0:stop;*/
    uint8_t EngRunningSts;
    /*转速红区值 4500rpm or 6000/6300 rpm*/
    int32_t RedZoneThreshold;
    /*指针转速 Invalid:0xEFFF（display 0.0 rpm）*/
    int32_t EngSpdAnalog;
    /*未经滤波的转速 Invalid:0xEFFF（display 0.0 rpm）*/
    int32_t EngSpdReal;
}IPC_M2S_ClusterAppAPPTacho_t;

/* Pack function of sub message Tacho */
int32_t IPC_M2S_ClusterAppAPPTacho_Pack(IPC_M2S_ClusterAppAPPTacho_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Tacho */
int32_t IPC_M2S_ClusterAppAPPTacho_Parse(IPC_M2S_ClusterAppAPPTacho_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Coolant */
typedef struct
{
    /*range value: 0~100%  Invalid:0xEFFF(display 0)*/
    int32_t EngCoolantTemp;
    /*1: Red display; 0:Normal display;*/
    uint8_t RedDispaly;
    /*水温实际值  0-0xFF:Valid*/
    int32_t EngCoolantTempPhysValue;
    /*水温红区阈值 TBD 未使用*/
    int32_t RedZoneThreshold;
}IPC_M2S_ClusterAppAPPCoolant_t;

/* Pack function of sub message Coolant */
int32_t IPC_M2S_ClusterAppAPPCoolant_Pack(IPC_M2S_ClusterAppAPPCoolant_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Coolant */
int32_t IPC_M2S_ClusterAppAPPCoolant_Parse(IPC_M2S_ClusterAppAPPCoolant_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: MenuSetting */
typedef struct
{
    /*set over speed(30~260km/h)/(20~180mph)*/
    uint16_t Sd_NaviLimitSpeed;
    /*0:OFF turn off over speed warning; 1:ON Turn on over speed warning;*/
    uint8_t Sd_OverSpeedEnable;
    /*设置语言类型
    0：汉语
    1：英语
    2：俄语
    3：阿拉伯语
    4：西班牙语
    5：葡萄牙语
    6：德语
    7：法语
    8：意大利语
    9：泰语
    10：乌克兰语
    11：印尼语*/
    uint8_t Sd_Language;
    /*设置显示模式
    0：数字模式
    1：科技模式
    2：极简模式
    3：经典模式
    4：指引模式
    5：越野模式
    6：赛道模式
    7：狂暴模式
    8：SupSport模式*/
    uint8_t Sd_ClusterTheme;
    /*0:Normal Metric; 1:Janpan Metric; 2:Imperial UK; 3:Imperial US;*/
    uint8_t Sd_OdometerUnit;
    /*0:Celsius  ; 1:Fahrenheit*/
    uint8_t Sd_TemperatureUnit;
    /*0: kpa ; 1:psi ; 2:bar*/
    uint8_t Sd_TirePressureUnit;
    /*设置行车电脑ID （仪表HMI定义卡片ID底层无需关注）*/
    uint8_t Sd_TripComputerId;
    /*设置交互卡片ID （仪表HMI定义卡片ID底层无需关注）*/
    uint8_t Sd_InteractiveCarId;
    /*0: switch off  ; 1:switch on ; 2:Invalid*/
    uint8_t Sd_DrivingModeMemorySwitch;
    /*0:24 hours   ; 1:12 hours*/
    uint8_t Sd_TimeUnit;
    /*设置高速辅助界面设置消息（reserved）*/
    uint8_t Sd_HighwayAssistSwitch;
    /*设置变道辅助界面设置消息 （reserved）*/
    uint8_t Sd_LaneChangeAssistSwitch;
    /*0: Sunrise  ;   1:Sunset*/
    uint8_t Sd_SunriseSunset_Mode;
    /*0: Not Auto mode  ; 1: Auto mode*/
    uint8_t Sd_Auto_Mode;
    /*reserved*/
    uint8_t Sd_DrvgModeMemReq;
    /*设置驾驶模式类型
    0XE：赛道模式
    0XC：狂暴模式*/
    uint8_t Sd_DrvingModReqHUT;
    /*主题联动开关状态（0：不联动   1：联动）*/
    uint8_t Sd_Switch_ThemeLinkage_Sts;
    /*数据同步标志*/
    uint8_t Sd_DataSyncFlg;
    /*氛围灯联动开关状态（0：不联动   1：联动）*/
    uint8_t Sd_AtmosphereLampLinkageSwt_Sts;
    /*模拟声浪联动开关状态（0：不联动   1：联动）*/
    uint8_t Sd_SimSoundWaveLinkageSwt_Sts;
    /*猫叫联动开关状态（0：关闭   1：打开）*/
    uint8_t Sd_MaoCallLinkageSwt_Sts;
}IPC_M2S_ClusterAppAPPMenuSetting_t;

/* Pack function of sub message MenuSetting */
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Pack(IPC_M2S_ClusterAppAPPMenuSetting_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MenuSetting */
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Parse(IPC_M2S_ClusterAppAPPMenuSetting_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TCClearResult */
typedef struct
{
    /*0x01:Success 0x0:failure*/
    uint8_t Result;
}IPC_M2S_ClusterAppAPPTCClearResult_t;

/* Pack function of sub message TCClearResult */
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Pack(IPC_M2S_ClusterAppAPPTCClearResult_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TCClearResult */
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Parse(IPC_M2S_ClusterAppAPPTCClearResult_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ConfigData */
typedef struct
{
    /*Cconfig: Byte2 bit2
    0x0: Disable fast response;
    0x1: Enable fast response*/
    uint8_t Fast_Resp;
    /*Cconfig: Byte2 bit0 此参数只对数字转速有效*/
    uint16_t DigitalRPM_Hysteresis;
    /*Cconfig: Byte8 汽油水温表C点温度值*/
    uint8_t GasolineCoolant_C_point;
    /*Cconfig: Byte9 汽油水温表1/4点温度值*/
    uint8_t GasolineCoolant_14_point;
    /*Cconfig: Byte10 汽油水温表1/2点温度值*/
    uint8_t GasolineCoolant_12_point1;
    /*Cconfig: Byte11 汽油水温表1/2点温度值*/
    uint8_t GasolineCoolant_12_point2;
    /*Cconfig: Byte12 汽油水温表3/4点温度值*/
    uint8_t GasolineCoolant_4_point;
    /*Cconfig: Byte13 汽油水温表红线位置温度值*/
    uint8_t GasolineCoolant_Redline_point;
    /*Cconfig: Byte14 汽油水温表H点温度值*/
    uint8_t GasolineCoolant_H_point;
    /*Cconfig: Byte15 柴油水温表C点温度值*/
    uint8_t DieselCoolant_C_point;
    /*Cconfig: Byte16 柴油水温表1/4点温度值*/
    uint8_t DieselCoolant_14_point;
    /*Cconfig: Byte17 柴油水温表1/2点温度值*/
    uint8_t DieselCoolant_12_point1;
    /*Cconfig: Byte18 柴油水温表1/2点温度值*/
    uint8_t DieselCoolant_12_point2;
    /*Cconfig: Byte19 柴油水温表3/4点温度值*/
    uint8_t DieselCoolant_34_point;
    /*Cconfig: Byte20 柴油水温表红线位置温度值*/
    uint8_t DieselCoolant_Redline_point;
    /*Cconfig: Byte21 汽油水温表H点温度值*/
    uint8_t DieselCoolant_H_point;
    /*Cconfig: Byte126 bit7 横向像素位置参数*/
    uint16_t Horizontal_data;
    /*Cconfig: Byte128 横向距离-8米到2.7米所占横向像素百分比*/
    uint8_t X;
    /*Cconfig: Byte129 纵向距离0-100米所占纵向像素百分比*/
    uint8_t Y;
    /*Cconfig: Byte135 bit7 平均车速B显示使能标志*/
    uint8_t AVSBDisplayEnable;
    /*Cconfig: Byte135 bit6 平均车速A显示使能标志*/
    uint8_t AVSADisplayEnable;
    /*Cconfig: Byte135 bit5 行驶时间A显示使能标志*/
    uint8_t TravelTimeADisplayEnable;
    /*Cconfig: Byte135 bit4 行驶时间B显示使能标志*/
    uint8_t TravelTimeBDisplayEnable;
    /*Cconfig: Byte145 bit3 平均油耗A显示使能标志*/
    uint8_t AFCADisplayEnable;
    /*Cconfig: Byte145 bit2 平均油耗B显示使能标志*/
    uint8_t AFCBDisplayEnable;
    /*Cconfig: Byte149 bit7 IFC显示使能标志*/
    uint8_t IFCDisplayEnable;
    /*Cconfig: Byte149 bit6 数字车速显示使能标志*/
    uint8_t DigitalSpeedDisplayEnable;
    /*Cconfig: Byte173 bit7 PHEV续航里程显示使能标志*/
    uint8_t PHEV_HEVDTEDisplayEnable;
    /*Cconfig: Byte174 PHEV纯电续航里程显示最大值*/
    uint8_t MaxDisplayPHEVRange;
    /*Cconfig: Byte181 bit7 PHEVSOC显示使能标志*/
    uint8_t PHEVSOCDisplayEnable;
    /*Cconfig: Byte182 bit7 PHEVSOC更新周期*/
    uint16_t RefreshRatePHEVSOC;
    /*Cconfig: Byte183 bit0 AvailablePower显示使能标志*/
    uint8_t AvailablePowerDisplayEnable;
    /*Cconfig: Byte184 AvailablePower最大值*/
    uint8_t MaxAvailablePower;
    /*Cconfig: Byte185 bit7 平均能耗更新周期*/
    uint16_t RefreshRateAvrgEgyCns;
    /*Cconfig: Byte186 bit0 平均能耗显示使能标志*/
    uint8_t AvrgEgyCnsDisplayEnable;
    /*Cconfig: Byte187 bit7 平均能耗最大值*/
    uint16_t MaxvalueAvrgEgyCns;
    /*Cconfig: Byte188 bit3 power更新周期*/
    uint16_t RefreshRatemotorpower;
    /*Cconfig: Byte190 bit7 电机功率显示使能标志*/
    uint8_t motorpowerDisplayEnable;
    /*Cconfig: Byte190 bit3 SOC更新周期*/
    uint16_t RefreshRateEVSOC;
    /*Cconfig: Byte181 bit7 PHEVSOC显示使能标志*/
    uint8_t EVSOCDisplayEnable;
    /*Cconfig: Byte192 bit3 EV DTE更新周期*/
    uint16_t RefreshRateEVDTE;
    /*Cconfig: Byte194 bit7 EV DTE显示使能标志*/
    uint8_t EVDTEDisplayEnable;
    /*Cconfig: Byte194 bit3 续航里程最大值*/
    uint16_t MaxvalueEVDTE;
    /*Cconfig: Byte196 bit7 EV 电流更新周期*/
    uint16_t RefreshRateCurrent;
    /*Cconfig: Byte197 bit0 EV 电流显示使能标志*/
    uint8_t EVCurrentDisplayEnable;
    /*Cconfig: Byte200 行驶数据A复位时间间隔（4小时）*/
    uint8_t EVDrivDataARestTime;
    /*Cconfig: Byte201 bit7 平均车速更新周期*/
    uint16_t RefreshRateEVAVS;
    /*Cconfig: Byte203 平均车速A/B复位后显示无效值的公里数*/
    uint8_t EVAVSMinDistanceThresh;
    /*Cconfig: Byte204 bit7 平均车速A显示使能标志*/
    uint8_t EVAVSADisplayEnable;
    /*Cconfig: Byte204 bit6 平均车速B显示使能标志*/
    uint8_t EVAVSBDisplayEnable;
    /*Cconfig: Byte205-209 EV行驶时间A/B可显示的最大值，超过此值则翻转到00:00*/
    uint64_t EVTravelTimeDisplayLimited;
    /*Cconfig: Byte210 bit7 EV行驶时间A显示使能标志*/
    uint8_t EVTravelTimeADisplayEnable;
    /*Cconfig: Byte210 bit6 EV行驶时间B显示使能标志*/
    uint8_t EVTravelTimeBDisplayEnable;
    /*Cconfig: Byte228 门开提示文字显示的阈值*/
    uint8_t DoortoRed_speedthreshold;
    /*Cconfig: Byte229 车门打开显示持续时间*/
    uint8_t Doorallclosed_holdtime;
    /*Cconfig: Byte232  7.x或者7.y轮询显示位置指示灯被打断显示时间*/
    uint8_t Telltale_interrupt_display_time;
    /*Cconfig: Byte233  7.x或者7.y轮询显示位置指示灯轮询显示时间*/
    uint8_t Telltale_polling_display_time;
    /*Cconfig: Byte167 bit3 TPMS显示使能标志*/
    uint8_t TPMSDisplayEnable;
    /*Cconfig: Byte216 bit7 ODO显示使能标志*/
    uint8_t FIXEDDISPLAY_1_ODO_ENABLE;
    /*Cconfig: Byte210 bit1 时钟显示使能标志*/
    uint8_t FD_003_CLOCK_ENABLE;
    /*Cconfig: Byte217 bit0 PS驾驶模式显示使能与否*/
    uint8_t FD_009_DRIVE_MODE_2WD_ENABLE;
    /*Cconfig: Byte240 bit7 小计里程A显示使能配置字*/
    uint8_t DrivDataADisplayEnable;
    /*Cconfig: Byte240 bit3 小计里程B显示使能配置字*/
    uint8_t DrivDataBDisplayEnable;
    /*Cconfig: Byte241 车道线滚动速度1*/
    uint16_t Adas_V1;
    /*Cconfig: Byte243 车道线滚动速度2*/
    uint16_t Adas_V2;
    /*Cconfig: Byte245 水温表从C点到H点指示时间*/
    uint8_t GasolineCoolant_Distime;
    /*Cconfig: Byte246 水温表从C点到H点指示时间*/
    uint8_t DieselCoolant_Distime;
    /*Cconfig: Byte41 燃油表从E点指示到F点的指示时间*/
    uint8_t Fuel_Distime;
    /*Cconfig: Byte266 bit3 尿素液位功能的更新频率*/
    uint16_t RefreshRateUrea;
    /*Cconfig: Byte285 怠速g值迟滞*/
    uint8_t GValue_Hysteresis;
    /*Cconfig: Byte286 bit7 g值更新频率*/
    uint16_t GValue_update_frequency;
}IPC_M2S_ClusterAppAPPConfigData_t;

/* Pack function of sub message ConfigData */
int32_t IPC_M2S_ClusterAppAPPConfigData_Pack(IPC_M2S_ClusterAppAPPConfigData_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ConfigData */
int32_t IPC_M2S_ClusterAppAPPConfigData_Parse(IPC_M2S_ClusterAppAPPConfigData_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: VConfig */
typedef struct
{
    union
    {
        uint8_t u8VConfig_data[9];
        struct
        {
            /*Vconfig: Byte2 Bit7-Bit4   FUEL*/
            uint8_t Fuel                                    :8;
            /*Vconfig: Byte4 Bit5-Bit2   REGIONAL*/
            uint8_t Regional                                :8;
            /*Vconfig: Byte26 Bit4-Bit0   SERVICE BRAKE*/
            uint8_t Service_Brake                           :8;
            /*Vconfig: Byte26 Bit7-Bit5   PARKING BRAKE*/
            uint8_t Parking_Brake                           :8;
            /*Vconfig: Byte25 Bit1-Bit0   STEERING SYSTEM*/
            uint8_t Steering_System                         :8;
            /*Vconfig: Byte10 Bit3-Bit0   FORWARD COLLISION WARNING+AUTO EMERGENCY BRAKING*/
            uint8_t Fcw_Aeb                                 :8;
            /*Vconfig: Byte46 Bit7-Bit5   AEB JUNCTION ASSIST*/
            uint8_t Aeb_Assist                              :8;
            /*Vconfig: Byte30 Bit7-Bit4   ELECTROMOTOR POSITION*/
            uint8_t Elec_Position                           :8;
            /*Vconfig: Byte41 Bit3-Bit2   E-PARK*/
            uint8_t E_Park                                  :8;
        }s_u8VConfig_data_t;
    }u_VConfigu8VConfig_data_t;
}IPC_M2S_ClusterAppAPPVConfig_t;

/* Pack function of sub message VConfig */
int32_t IPC_M2S_ClusterAppAPPVConfig_Pack(IPC_M2S_ClusterAppAPPVConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message VConfig */
int32_t IPC_M2S_ClusterAppAPPVConfig_Parse(IPC_M2S_ClusterAppAPPVConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: MenuTheme */
typedef struct
{
    /*主题ID（infra设置主题商城ID）*/
    uint32_t ThemeID;
    /*皮肤ID（infra设置主题商城ID）*/
    uint32_t SkinID;
}IPC_M2S_ClusterAppAPPMenuTheme_t;

/* Pack function of sub message MenuTheme */
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Pack(IPC_M2S_ClusterAppAPPMenuTheme_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MenuTheme */
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Parse(IPC_M2S_ClusterAppAPPMenuTheme_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: DriveMode */
typedef struct
{
    union
    {
        uint8_t u8DriveMode_data[6];
        struct
        {
            /*驾驶模式图标-驾驶模式信号值(对应显示不同图标)
            value: case与code值较多，具体参见固定显示SRS文档*/
            uint8_t DriveMode_Value                         :8;
            /*self check: 0~no self check ;1~self check 其他：reserve*/
            uint8_t DriveMode_Data_selfcheck                :1;
            /*驾驶模式图标-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 其他:reserve*/
            uint8_t DriveMode_Data                          :3;
            /*self check: 0~no self check ;1~self check 其他：reserve*/
            uint8_t HybridMode_Data_selfcheck               :1;
            /*动力模式图标-指示灯状态
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 其他:reserve*/
            uint8_t HybridMode_Data                         :3;
            /*动力模式图标-动力模式信号值(对应显示不同图标)
            value:code值参见固定显示SRS文档*/
            uint8_t HybridMde_Value                         :8;
            /*驾驶模式切换信号值：KL15 ON 3s内发无效值 0x3F；KL15 ON 3s后为实际信号值，参考chime SRS文档章节1.36~1.39  
            补充：驾驶模式切换信号超时，会保持之前的值*/
            uint8_t DrvModSignal_Value                      :6;
            /*燃油车驾驶模式-自动模式切换信号值：KL5 ON 3s内发无效值0x3；KL5 ON 3s后 0x0 not Auto，0x1 Auto
            补充：IMC_Actv信号超时，会保持之前的值；车型配置不适用，该信号不被使用，发无效值0x3*/
            uint8_t IMCActvSignal_Value                     :2;
            /*0x0：None; 
            0x1:  Fuel or PAPA2; 
            0x2:  PHEV/HEV+PS/PS_P4;  
            0x3:  PHEV+P2;
            0x4：EV*/
            uint8_t DrvModVehType                           :4;
            /*0(km/h(metric)), 1(mph(Imperial))*/
            uint8_t DM_individuation_spd_unit               :1;
            /*保留，数据对齐*/
            uint8_t Reserved                                :3;
            /*0x0-0x3B：---km/h或---mph；0x3C-0x96：xxxkm/h或xxxmph；0x97-0xff：---km/h或---mph*/
            uint8_t DM_individuation_spd_value              :8;
        }s_u8DriveMode_data_t;
    }u_DriveModeu8DriveMode_data_t;
}IPC_M2S_ClusterAppAPPDriveMode_t;

/* Pack function of sub message DriveMode */
int32_t IPC_M2S_ClusterAppAPPDriveMode_Pack(IPC_M2S_ClusterAppAPPDriveMode_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message DriveMode */
int32_t IPC_M2S_ClusterAppAPPDriveMode_Parse(IPC_M2S_ClusterAppAPPDriveMode_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: WN_Data */
typedef struct
{
    /*定速巡航速度值 Value：0-240 km/h  0-150 mph*/
    uint8_t WN_TgtCrsSpd;
    /*定速巡航速度有效性  Value: 0~Invalid 1~Valid*/
    uint8_t WN_TgtCrsSpdVldSts;
    /*驾驶模式场景值 Value:1-5 ~ Drive Mode case1-case5*/
    uint8_t WN_DrvModeCaseValue;
    /*自动导航辅助驾驶距离数据 Value:0-0xFFFF*/
    uint16_t WN_NOHDist;
}IPC_M2S_ClusterAppAPPWN_Data_t;

/* Pack function of sub message WN_Data */
int32_t IPC_M2S_ClusterAppAPPWN_Data_Pack(IPC_M2S_ClusterAppAPPWN_Data_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message WN_Data */
int32_t IPC_M2S_ClusterAppAPPWN_Data_Parse(IPC_M2S_ClusterAppAPPWN_Data_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: NewEnergy */
typedef struct
{
    union
    {
        uint32_t u32NewEnergy_data[4];
        struct
        {
            /*0xEFFE:not display ;offset:-100
            1.21~ 1.22 功率指示显示 - 功率指示*/
            uint32_t PowerPointer                           :16;
            /*0xEFFE:not display ;Resolution:0.1
            1.21 功率指示显示( HEV +PHEV ) - 可用功率*/
            uint32_t AvailPower                             :16;
            /*1:red;2:yellow;3:green;4:Gray
            1.20 PHEV 动力电池电量 SOC 显示 (PHEV)- 颜色状态 */
            uint32_t PowerBattery_Status                    :8;
            /*uint:%
            1.20 PHEV 动力电池电量 SOC 显示 (PHEV)- 百分比*/
            uint32_t PowerBattery_Percent                   :8;
            /*0xEFFE:not display ;value = (N)*0.1-10
            1.23 驾驶效率显示 ( HEV+PHEV ) (经济指引)*/
            uint32_t DriveHabit                             :16;
            /*0xFE:not display;0xFF:display --h--min
            1.25 预计充电时间显示(PHEV) - 小时*/
            uint32_t ChrgTime_Hour                          :8;
            /*0xFE:not display;0xFF:display --h--min
            1.25 预计充电时间显示(PHEV) - 分钟*/
            uint32_t ChrgTime_Min                           :8;
            /*0xEFFE:not display;0xFFFF:display ---A; offset: -1000
            1.24 充电状态显示(PHEV) - 充电电流显示*/
            uint32_t ChargeCurrent                          :16;
            /*0xFE:充电状态文字不显示; 0xFF:充电状态卡片不显示
            other value:参考最新TC需求文档，不逐一列举
            1.24 充电状态显示(PHEV) - lcd充电状态显示*/
            uint32_t ChargeStatus                           :8;
            /*0xFE:not display；0xFF：显示“暂时无法获取能量流信息”
            other value:参考最新TC需求文档，不逐一列举
            1.18 能量流显示*/
            uint32_t EnergyFlow_Data                        :8;
            /*电子稳定杆状态：
            0x0: 断开状态;
            0x1: 非预期断开状态;
            0x2: 连接状态;
            other: 无效值*/
            uint32_t ElectronicStabilizerBar_Status         :8;
            /*对齐补充位，新加时可以使用*/
            uint32_t Reserved                               :8;
        }s_u32NewEnergy_data_t;
    }u_NewEnergyu32NewEnergy_data_t;
}IPC_M2S_ClusterAppAPPNewEnergy_t;

/* Pack function of sub message NewEnergy */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Pack(IPC_M2S_ClusterAppAPPNewEnergy_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message NewEnergy */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Parse(IPC_M2S_ClusterAppAPPNewEnergy_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: NewEnergy_EV */
typedef struct
{
    union
    {
        uint32_t u32NewEnergy_EV_data[6];
        struct
        {
            /*1.27 平均能耗指示（EV）
            0xFFFF display dash 
            factor:10, eg 987=98.7kWh/100km
            ;0xFFFE :Disable display */
            uint32_t AEC                                    :16;
            /*平均能耗单位:
            0:kWh/100km, 1:Wh/mi*/
            uint32_t AEC_Unit                               :8;
            /*1.39 经济指引指示 (EV)
            0x0:Nodisplay
            0x1~0x5:Valid value
            Offset:-5
            eg： 0x1 = -4, 0x5 = 0*/
            uint32_t ECODrvHabit                            :8;
            /*1.28 电机功率指示（颜色）
            0x0:Not display
            0x01:Green
            0x02:White
            0x03:Red*/
            uint32_t EV_MotorPower_Status                   :8;
            /*1.28 电机功率指示（kw）分动器配置
            两驱：value = 0~400,offset: -200;  
            四驱：value = 0~2000,offset: -1000;  
            0xFFFE:Not Display；0xFFFF:Display--*/
            uint32_t EV_MotorPower_Percent                  :16;
            /*1.31 电量表指示（电量表百分比）
            0xFF:Display"--" 0xFE:Not DIsplay; Range:0~100; scale:1 offset:0*/
            uint32_t EV_Soc_Value                           :8;
            /*1.31 电量表指示（电量表颜色）
            0:Normal  1:Red  2:Gray*/
            uint32_t EV_SOC_Color                           :8;
            /*1.40 充电状态指示（文字提示）
            0:None  1:充电中     2:预约充电      3:充电完成     4:充电已停止 5:动力电池预热中 6:充电故障*/
            uint32_t EV_Charge_Status                       :8;
            /*1.40 充电状态指示（充电电流）
            0xFFFF:Display"--"  0xFFFE:Not Display  Range:-800~800; scale:1 offset:-800  unit:A*/
            uint32_t EV_Charge_Cur                          :16;
            /*1.30 预计充电时间显示(EV) - 小时"
            "0xFE:not display;0xFF:display --h--min*/
            uint32_t EV_ChargeTimeHour                      :8;
            /*1.30 预计充电时间显示(EV)  - 分钟"
            "0xFE:not display;0xFF:display --h--min*/
            uint32_t EV_ChargeTimeMin                       :8;
            /*1.34 续航里程指示(EV)
            0xFFFF:Display--"  0xFFFE:Not Display; Range:0~9999; scale:1 offset::0  */
            uint32_t EV_Charge_SOCVlaue                     :8;
            /*1.40 充电状态显示   ; 
            0:充电枪充电效果; 1:无线充电状态效果    */
            uint32_t EV_Charge_Interface                    :8;
            /*1.34 续航里程指示(EV)
            0xFFFF:Display--"  0xFFFE:Not Display; Range:0~9999; scale:1 offset::0  unit:KM"*/
            uint32_t EV_DrvRng                              :16;
            /*1.58 能量流显示(EV)
            0x0:不显示
            0x1:车辆静止/无能量流动状态
            0x2:正常行驶能量流   电池包→前驱动电机
            0x3:能量回收能量流   前驱动电机→电池包
            0x4:电池包仅加热状态能量流
            0x5:显示边充电边加热状态能量流
            0x6:仅充电状态能量流 
            0x7:前驱 放电状态能量流 
            0x8:两驱前驱车型不显示此能 量流
            0x9: 正常行驶能量流  电池包→后驱动电机
            0xa: 能量回收能量流 后驱动电机→电池包
            0xb:后驱放电状态能量流 
            0xc: 正常行驶能量流 电池包→ 前/后驱动电机
            0xd: 能量回收能量流  前/后驱动电机→电池包
            0xe:四驱 放电状态能量流 */
            uint32_t EV_EnergyFlow_Value                    :8;
            /*1.59 雨雪天模式
            0x0:No Scenario Mode
            0x1:Rain and Snow Weather Mode*/
            uint32_t EV_RainsSnowMode                       :8;
            /*1.32充电电量指示(off电量表颜色)
            0:Gren  1:Red  2:Yellow*/
            uint32_t EV_Charge_SOCColor                     :8;
            /*1.34 续航里程指示单位(EV)
            0: DTE-KM ,  1:DTE-MILES*/
            uint32_t EV_DrvRng_Unit                         :8;
        }s_u32NewEnergy_EV_data_t;
    }u_NewEnergy_EVu32NewEnergy_EV_data_t;
}IPC_M2S_ClusterAppAPPNewEnergy_EV_t;

/* Pack function of sub message NewEnergy_EV */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Pack(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message NewEnergy_EV */
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Parse(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: OffroadInfo */
typedef struct
{
    /*大气压数据：0~1500hpa valid;
                       other  invalid;*/
    uint16_t Sd_BaroPressure;
    /*海拔高度数据：0x00~0x1FFE （0~8190m）*/
    uint16_t Sd_Heilvl;
    /*海拔显示标记
    0：正数
    1：负数*/
    uint8_t Sd_HeilvlSign;
    /*坡度数据：0~90°*/
    uint8_t Sd_PitchAngle;
    /*坡度显示标记
    0：上坡
    1：下坡*/
    uint8_t Sd_PitchAngleSign;
    /*指南针方向数据：0~7（8个方位）*/
    uint8_t Sd_GeoGraphic;
    /*车轮转向角度：0x00~0x2B  （0~43°）*/
    uint8_t Sd_SteerWheel;
    /*车轮转向显示标记
    0：向左
    1：向右*/
    uint8_t Sd_SteerWheelSign;
}IPC_M2S_ClusterAppAPPOffroadInfo_t;

/* Pack function of sub message OffroadInfo */
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Pack(IPC_M2S_ClusterAppAPPOffroadInfo_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message OffroadInfo */
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Parse(IPC_M2S_ClusterAppAPPOffroadInfo_t *in_data, uint8_t *payload, uint16_t length);

/* Group: : ClusterApp */
/* Message Major: System */
/* Message Sub: BootCondition */
typedef struct
{
    /*tach rpm,units:1 rpm/min, 0xffff: invalid*/
    uint16_t Tach;
    /*Speed value,units:0.1km/h, 0xffff: invalid*/
    uint16_t Speed;
    /*0:P; 1:N; 2~Other*/
    uint8_t Gear;
    /*0:handbrake is off;1:handbrake is On*/
    uint8_t Handbrake;
    /*0:Engine is stop;1：Engine is runing*/
    uint8_t EngineSts;
}IPC_M2S_ClusterAppSystemBootCondition_t;

/* Pack function of sub message BootCondition */
int32_t IPC_M2S_ClusterAppSystemBootCondition_Pack(IPC_M2S_ClusterAppSystemBootCondition_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BootCondition */
int32_t IPC_M2S_ClusterAppSystemBootCondition_Parse(IPC_M2S_ClusterAppSystemBootCondition_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ADASConfig */
typedef struct
{
    /*1 = on , 0 = off*/
    uint8_t HighwayAssistSwitch;
    /*1 = on , 0 = off*/
    uint8_t LaneChangeAssistSwitch;
}IPC_M2S_ClusterAppSystemADASConfig_t;

/* Pack function of sub message ADASConfig */
int32_t IPC_M2S_ClusterAppSystemADASConfig_Pack(IPC_M2S_ClusterAppSystemADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ADASConfig */
int32_t IPC_M2S_ClusterAppSystemADASConfig_Parse(IPC_M2S_ClusterAppSystemADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: CLUSTERPOWER */
typedef struct
{
    /*0x0:cluster off;0x1:cluster standby;0x2:cluster on*/
    uint8_t ClusterState;
    /*0x0:low_sleep;
    0x1:normal;
    0x2:high_alarm;
    0x3:high_sleep;
    0x4:Low_alarm*/
    uint8_t VoltageState;
    /*1:power changed from not on to on
    0:power not changed*/
    uint8_t PowerChangedFlag;
}IPC_M2S_ClusterAppSystemCLUSTERPOWER_t;

/* Pack function of sub message CLUSTERPOWER */
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Pack(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CLUSTERPOWER */
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Parse(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: CommonAppMsgUploaded */
typedef struct
{
    /*0xBB:Data send complete，other：reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t;

/* Pack function of sub message CommonAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Pack(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CommonAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Parse(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: IPCDebugTest */
typedef struct
{
    /*0x0: ON，0x1: OFF，other：reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemIPCDebugTest_t;

/* Pack function of sub message IPCDebugTest */
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Pack(IPC_M2S_ClusterAppSystemIPCDebugTest_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IPCDebugTest */
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Parse(IPC_M2S_ClusterAppSystemIPCDebugTest_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: InterfaceAppMsgUploaded */
typedef struct
{
    /*0xBB: Data send complete, other: reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t;

/* Pack function of sub message InterfaceAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Pack(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message InterfaceAppMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Parse(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: GaugeMsgUploaded */
typedef struct
{
    /*0xBB: Data send complete, other: reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t;

/* Pack function of sub message GaugeMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Pack(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message GaugeMsgUploaded */
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Parse(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *in_data, uint8_t *payload, uint16_t length);

/* Group: : ClusterApp */
/* Message Major: CANAdapt */
/* Message Sub: CSA3_244 */
typedef struct
{
    union
    {
        uint32_t CSA3_244_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t CSA3_244_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t PageUpSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageUpSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t PageDwnSwtSts_Sts_Flag                 :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageDwnSwtSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t PageLSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageLSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t PageRSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageRSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t EnterSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t EnterSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HomeSwtSts_Sts_Flag                    :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t HomeSwtSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t MenuReturnSwtSts_Sts_Flag              :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t MenuReturnSwtSts                       :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t CustomSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t CustomSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IpMenuSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t IpMenuSwtSts                           :2;
        }s_CSA3_244_Inf_t;
    }u_CSA3_244CSA3_244_Inf_t;
    union
    {
        uint32_t CSA3_244_Inf_1;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t AdjVolDwnSwtSts_Sts_Flag               :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t AdjVolDwnSwtSts                        :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t AdjVolUpSwtSts_Sts_Flag                :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t AdjVolUpSwtSts                         :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t SeekDwnSwtSts_Sts_Flag                 :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t SeekDwnSwtSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t SeekUpSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t SeekUpSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t EnterSwtSts_Mmed_Sts_Flag              :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t EnterSwtSts_Mmed                       :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t VRSwtSts_Sts_Flag                      :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t VRSwtSts                               :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t MuteSwtSts_Sts_Flag                    :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t MuteSwtSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t CustomSwtSts_Mmed_Sts_Flag             :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t CustomSwtSts_Mmed                      :2;
        }s_CSA3_244_Inf_1_t;
    }u_CSA3_244CSA3_244_Inf_1_t;
}IPC_M2S_ClusterAppCANAdaptCSA3_244_t;

/* Pack function of sub message CSA3_244 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Pack(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CSA3_244 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Parse(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: EEM1_2A8 */
typedef struct
{
    union
    {
        uint8_t EEM1_2A8_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t EEM1_2A8_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t Stat_PwrSv_Lvl_Sts_Flag                 :1;
            /*0x0:Normal;0x1:Level1;0x2:Level2;0x3-0x7:Reserve*/
            uint8_t Stat_PwrSv_Lvl                          :3;
        }s_EEM1_2A8_Inf_t;
    }u_EEM1_2A8EEM1_2A8_Inf_t;
}IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t;

/* Pack function of sub message EEM1_2A8 */
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Pack(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message EEM1_2A8 */
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Parse(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ESP2_145 */
typedef struct
{
    union
    {
        uint8_t ESP2_145_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t ESP2_145_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t DrivingModDis_145_Sts_Flag              :1;
            /*0x0:Standard
            0x1:Sport
            0x2:Snow
            0x3:Mud
            0x4:Sand
            0x5:4L
            0x6:Economic
            0x7:Mode Unkown
            0x8:AUTO
            0x9:Sport+
            0xA:Off road
            0xB:Stand_2H
            0xC:Expert
            0xD:Stand_4H
            0xE:Failed
            0xF:Invalid Value
            0x10:Snow_4H
            0x11:Normal_4L
            0x12:Rock_4L
            0x13:Pothle_4L
            0x14:Mud/Sand_4L
            0x15:Mountain_4L
            0x16:reserved
            0x17:Race
            0x18-0x19:Reserved
            0x1A:Wade_4H
            0x1B:Wade_4L
            0x1C-0x1F:Reserved*/
            uint8_t DrivingModDis_145                       :5;
        }s_ESP2_145_Inf_t;
    }u_ESP2_145ESP2_145_Inf_t;
}IPC_M2S_ClusterAppCANAdaptESP2_145_t;

/* Pack function of sub message ESP2_145 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Pack(IPC_M2S_ClusterAppCANAdaptESP2_145_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ESP2_145 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Parse(IPC_M2S_ClusterAppCANAdaptESP2_145_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ESP2_137 */
typedef struct
{
    union
    {
        uint16_t ESP2_137_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t ESP2_137_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t DrivingModDis_137_Sts_Flag             :1;
            /*0x0:Standard
            0x1:Sport
            0x2:Snow
            0x3:Mud
            0x4:Sand
            0x5:4L
            0x6:Economic
            0x7:Mode Unkown
            0x8:AUTO
            0x9:Sport+
            0xA:Off road
            0xB:Stand_2H
            0xC:Expert
            0xD:Stand_4H
            0xE:Failed
            0xF:Invalid Value
            0x10:Snow_4H
            0x11:Normal_4L
            0x12:Rock_4L
            0x13:Pothle_4L
            0x14:Mud/Sand_4L
            0x15:Mountain_4L
            0x16:reserved
            0x17:Race
            0x18-0x19:Reserved
            0x1A:Wade_4H
            0x1B:Wade_4L
            0x1C-0x1F:Reserved*/
            uint16_t DrivingModDis_137                      :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t ESPBrkLmpCtrl_137_Sts_Flag             :1;
            /*0x0:Brake light off
            0x1:Brake light on*/
            uint16_t ESPBrkLmpCtrl_137                      :1;
        }s_ESP2_137_Inf_t;
    }u_ESP2_137ESP2_137_Inf_t;
}IPC_M2S_ClusterAppCANAdaptESP2_137_t;

/* Pack function of sub message ESP2_137 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Pack(IPC_M2S_ClusterAppCANAdaptESP2_137_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ESP2_137 */
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Parse(IPC_M2S_ClusterAppCANAdaptESP2_137_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: HUD1_325 */
typedef struct
{
    union
    {
        uint32_t HUD1_325;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t HUD1_325_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_BrightnessLvl_Sts_Flag             :1;
            /*0x0:Level 1
            0x1:Level 2
            0x2:Level 3
            0x3:Level 4
            0x4:Level 5
            0x5:Level 6
            0x6:Level 7
            0x7:Level 8
            0x8:Level 9
            0x9-0xF:Reserved*/
            uint32_t HUD_BrightnessLvl                      :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_HeightLvl_Sts_Flag                 :1;
            /*0x0:No action
            0x1:Level 1_Low
            0x2:Level 2
            0x3:Level 3
            0x4:Level 4
            0x5:Level 5 
            0x6:Level 6
            0x7:Level 7
            0x8:Level 8 
            0x9:Level 9
            0xA:Level 10
            0xB:Level 11_Middle
            0xC:Level 12
            0xD:Level 13
            0xE:Level 14
            0xF:Level 15
            0x10:Level 16
            0x11:Level 17
            0x12:Level 18
            0x13:Level 19
            0x14:Level 20
            0x15:Level 21_High
            0x16-0x1F:Reserved*/
            uint32_t HUD_HeightLvl                          :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_UIMod_Sts_Flag                     :1;
            /*0x0:Normal Mode
            0x1:Dot Matrix Mode*/
            uint32_t HUD_UIMod                              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_UIModVld_Sts_Flag                  :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint32_t HUD_UIModVld                           :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_SwtSts_Sts_Flag                    :1;
            /*0x0:OFF
            0x1:ON*/
            uint32_t HUD_SwtSts                             :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HUD_UIModDefd_Sts_Flag                 :1;
            /*0x0:Normal_Mode
            0x1:Check_Configure_Mode
            0x2:Backgroud_Mode
            0x3:Reserved
            0x7 Reserved*/
            uint32_t HUD_UIModDefd                          :3;
        }s_HUD1_325_t;
    }u_HUD1_325HUD1_325_t;
}IPC_M2S_ClusterAppCANAdaptHUD1_325_t;

/* Pack function of sub message HUD1_325 */
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Pack(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HUD1_325 */
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Parse(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ECM3_371 */
typedef struct
{
    union
    {
        uint16_t ECM3_371_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t ECM3_371_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t BaroPressure_Sts_Flag                  :1;
            /*0x00-0xFE:Valid values
            0xFF:Invalid value*/
            uint16_t BaroPressure                           :8;
        }s_ECM3_371_Inf_t;
    }u_ECM3_371ECM3_371_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM3_371_t;

/* Pack function of sub message ECM3_371 */
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Pack(IPC_M2S_ClusterAppCANAdaptECM3_371_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ECM3_371 */
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Parse(IPC_M2S_ClusterAppCANAdaptECM3_371_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: CSA2_A1 */
typedef struct
{
    union
    {
        uint32_t CSA2_A1_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t CSA2_A1_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t SAS_Sts_Flag                           :1;
            /*0x0:SAS Angle And Speed Correct
            0x1:SAS Not Calibrated
            0x2:Intermittent Error Detected
            0x3:Permanent Error Detected*/
            uint32_t SAS_Sts                                :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t SteerWheelAngSign_Sts_Flag             :1;
            /*0x0:Left (Positive);0x1:Right (Negative)*/
            uint32_t SteerWheelAngSign                      :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t SteerWheelAng_Sts_Flag                 :1;
            /*0x0000-0x1E78:Valid value
            0x1E79-0x7FFE:Reserved
            0x7FFF:Invalid*/
            uint32_t SteerWheelAng                          :15;
        }s_CSA2_A1_Inf_t;
    }u_CSA2_A1CSA2_A1_Inf_t;
}IPC_M2S_ClusterAppCANAdaptCSA2_A1_t;

/* Pack function of sub message CSA2_A1 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Pack(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CSA2_A1 */
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Parse(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ECM16_2D4 */
typedef struct
{
    union
    {
        uint64_t ECM16_2D4_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint64_t ECM16_2D4_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Urea_Level_Sts_Flag                    :1;
            /*0x00: 0%
            0x01:5%
            0x02:10%
            0x03:15%
            0x04:20%
            0x05:25%
            0x06:30%
            0x07:35%
            0x08:40%
            0x09:45%
            0x0A:50%
            0x0B:55%
            0x0C:60%
            0x0D:65%
            0x0E:70%
            0x0F:75%
            0x10:80%
            0x11:85%
            0x12:90%
            0x13:95%
            0x14:100%
            0x15:Reserved*/
            uint64_t Urea_Level                             :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t SCRSysWarnDisplay_Sts_Flag             :1;
            /*0x0:No warn不提示(默认值)
            0x1:Urea level low尿素液位低,请加注
            0x2:Urea level tool low尿素液位极低,请加注
            0x3:Empty tank,next start prohibit尿素罐空,禁止下次启动
            0x4:Incorrect urea尿素不合格,请检查
            0x5:Incorrect urea over limit dist 尿素不合格行驶超过50km
            0x6:Urea fill intercept,please refill尿素加注中止,请重新加注
            0x7:Urea fill intercept over limit dist尿素加注中止行驶超过50km
            0x8:Engine start prohibit尿素系统禁止发动机启动
            0x9:SCR system fault,please check尿素系统故障,请入站检查
            0xA:SCR system fault over limit Dist尿素系统故障行驶超过50km
            0xB:Driving dist over limition with fault, next start prohibit尿素系统故障禁止下次启动
            0xC-0xF:Reserved*/
            uint64_t SCRSysWarnDisplay                      :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t SCRSysWarnDisplay_B2_Flag              :1;
            /*0x0 NoWarn
            0x1 Urea_is_insufficientunable_to_start_after_xxxKmplease_refill
            0x2 Urea_is_seriously_insufficient_unable_to_start_after_xxxKm_please_refill
            0x3 EmptyTankunable_start_next_key_on_please_refill
            0x4 EmptyTank_unable_start_please_refill
            0x5 Urea_unqualifiedunable_to_start_after_xxxKmplease_repair
            0x6 Urea_unqualified_unable_start_next_key_onplease_repair
            0x7 Urea_unqualifiedunable_startplease_repair
            0x8 Urea_Injection_is_interruptedunable_to_start_after_xxxKmPlease_repair
            0x9 Urea_Injection_is_interruptedunable_start_next_key_onPlease_repair
            0xA Urea_Injection_is_interruptedunable_startPlease_repair
            0xB Urea_consumption_deviationunable_to_start_after_xxxkmplease_repair
            0xC Urea_consumption_Deviation_unable_start_next_key_onplease_repair
            0xD Urea_consumption_Deviationunable_startplease_repair
            0xE Reserved
            0xF Reserved*/
            uint64_t SCRSysWarnDisplay_B2                   :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t UreaRemainDist_Sts_Flag                :1;
            /*0x000-0xFFF:Valid value
            */
            uint64_t UreaRemainDist                         :12;
        }s_ECM16_2D4_Inf_t;
    }u_ECM16_2D4ECM16_2D4_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM16_2D4_t;

/* Pack function of sub message ECM16_2D4 */
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Pack(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ECM16_2D4 */
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Parse(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: AC2_385 */
typedef struct
{
    union
    {
        uint16_t AC2_385_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t AC2_385_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t ACAmbTemp_Sts_Flag                     :1;
            /*0x00-0xFD:Valid value
            0xFE:Initial value
            0xFF:Invalid Value*/
            uint16_t ACAmbTemp                              :8;
        }s_AC2_385_Inf_t;
    }u_AC2_385AC2_385_Inf_t;
}IPC_M2S_ClusterAppCANAdaptAC2_385_t;

/* Pack function of sub message AC2_385 */
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Pack(IPC_M2S_ClusterAppCANAdaptAC2_385_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AC2_385 */
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Parse(IPC_M2S_ClusterAppCANAdaptAC2_385_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ECM_PT6_290 */
typedef struct
{
    union
    {
        uint32_t ECM_PT6_290_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t ECM_PT6_290_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t TrqPrct_Sts_Flag                       :1;
            /*0x00-0x64:Valid value
            0x65-0x7F:Reserve*/
            uint32_t TrqPrct                                :7;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t PowerPrct_Sts_Flag                     :1;
            /*0x00-0x64:Valid value
            0x65-0x7F:Reserve*/
            uint32_t PowerPrct                              :7;
        }s_ECM_PT6_290_Inf_t;
    }u_ECM_PT6_290ECM_PT6_290_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t;

/* Pack function of sub message ECM_PT6_290 */
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Pack(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ECM_PT6_290 */
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Parse(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ABM2_245 */
typedef struct
{
    union
    {
        uint64_t ABM2_245_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint64_t ABM2_245_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t VehLgtAccelVld_Sts_Flag                :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint64_t VehLgtAccelVld                         :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t VehLatAccelVld_Sts_Flag                :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint64_t VehLatAccelVld                         :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t VehLgtAccel_Sts_Flag                   :1;
            /*0x0000-0xAC22:Valid Value
            0xAC23-0xFFFF:Reserved*/
            uint64_t VehLgtAccel                            :16;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t VehLatAccel_Sts_Flag                   :1;
            /*0x0000-0xAC22:Valid Value
            0xAC23-0xFFFF:Reserved*/
            uint64_t VehLatAccel                            :16;
        }s_ABM2_245_Inf_t;
    }u_ABM2_245ABM2_245_Inf_t;
}IPC_M2S_ClusterAppCANAdaptABM2_245_t;

/* Pack function of sub message ABM2_245 */
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Pack(IPC_M2S_ClusterAppCANAdaptABM2_245_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ABM2_245 */
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Parse(IPC_M2S_ClusterAppCANAdaptABM2_245_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: RSDS_FD1_16F */
typedef struct
{
    union
    {
        uint16_t RSDS_FD1_16F_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t RSDS_FD1_16F_MSG_TimeoutFlag           :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t BSD_LCA_warningReqRight_Sts_Flag       :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t BSD_LCA_warningReqRight                :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t BSD_LCA_warningReqleft_Sts_Flag        :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t BSD_LCA_warningReqleft                 :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t DOW_warningReqRight_Sts_Flag           :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t DOW_warningReqRight                    :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t DOW_warningReqleft_Sts_Flag            :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t DOW_warningReqleft                     :2;
        }s_RSDS_FD1_16F_Inf_t;
    }u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t;
}IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t;

/* Pack function of sub message RSDS_FD1_16F */
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Pack(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message RSDS_FD1_16F */
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Parse(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: IFC_FD5_19F */
typedef struct
{
    union
    {
        uint32_t IFC_FD5_19F_Inf_1;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t IFC_FD5_19F_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line01_Type_Sts_Flag               :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Line01_Type                        :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line02_Type_Sts_Flag               :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Line02_Type                        :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line03_Type_Sts_Flag               :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Line03_Type                        :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line04_Type_Sts_Flag               :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Line04_Type                        :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge01_Type_Sts_Flag           :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Roadedge01_Type                    :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge02_Type_Sts_Flag           :1;
            /*0x0:undecided
            0x1:solid
            0x2:dashed
            0x3:double solid dashed
            0x4:double dashed solid
            0x5:double solid solid
            0x6:double dashed dashed
            0x7:botts
            0x8:deceleration
            0x9:hov_lane
            0xA:road edge
            0xB:elevated_structure
            0xC:curb
            0xD:cones_poles*/
            uint32_t IFC_Roadedge02_Type                    :4;
        }s_IFC_FD5_19F_Inf_1_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_1_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_2;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line01_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line01_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line01_Curv_Sts_Flag               :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Line01_Curv                        :15;
        }s_IFC_FD5_19F_Inf_2_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_2_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_3;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line02_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line02_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line02_Curv_Sts_Flag               :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Line02_Curv                        :15;
        }s_IFC_FD5_19F_Inf_3_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_3_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_4;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line03_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line03_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line03_Curv_Sts_Flag               :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Line03_Curv                        :15;
        }s_IFC_FD5_19F_Inf_4_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_4_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_5;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line04_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line04_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Line04_Curv_Sts_Flag               :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Line04_Curv                        :15;
        }s_IFC_FD5_19F_Inf_5_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_5_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_6;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge01_Dy_Sts_Flag             :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Roadedge01_Dy                      :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge01_Curv_Sts_Flag           :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Roadedge01_Curv                    :15;
        }s_IFC_FD5_19F_Inf_6_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_6_t;
    union
    {
        uint32_t IFC_FD5_19F_Inf_7;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge02_Dy_Sts_Flag             :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Roadedge02_Dy                      :13;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t IFC_Roadedge02_Curv_Sts_Flag           :1;
            /*0x0-0x7A12:Valid value
            0x7A13-0x7FFF:Reversed*/
            uint32_t IFC_Roadedge02_Curv                    :15;
        }s_IFC_FD5_19F_Inf_7_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_7_t;
    union
    {
        uint64_t IFC_FD5_19F_Inf_8;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line01_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line01_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line02_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line02_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line03_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line03_CurvChange                  :20;
        }s_IFC_FD5_19F_Inf_8_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_8_t;
    union
    {
        uint64_t IFC_FD5_19F_Inf_9;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line04_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line04_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Roadedge01_CurvChange_Sts_Flag     :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Roadedge01_CurvChange              :20;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Roadedge02_CurvChange_Sts_Flag     :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Roadedge02_CurvChange              :20;
        }s_IFC_FD5_19F_Inf_9_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t;

/* Pack function of sub message IFC_FD5_19F */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IFC_FD5_19F */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: IFC_FD6_222 */
typedef struct
{
    union
    {
        uint64_t IFC_FD6_222_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint64_t IFC_FD6_222_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line01_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line01_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line02_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line02_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line03_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line03_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line04_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line04_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Roadedge01_HeadingAngle_Sts_Flag   :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Roadedge01_HeadingAngle            :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Roadedge02_HeadingAngle_Sts_Flag   :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Roadedge02_HeadingAngle            :9;
        }s_IFC_FD6_222_Inf_t;
    }u_IFC_FD6_222IFC_FD6_222_Inf_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t;

/* Pack function of sub message IFC_FD6_222 */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IFC_FD6_222 */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ACC_FD2_2AB */
typedef struct
{
    union
    {
        uint32_t ACC_FD2_2AB_Inf_1;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t ACC_FD2_2AB_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgtTyp_Sts_Flag           :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_PotentialTgtTyp                    :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgtDy_Sts_Flag            :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_PotentialTgtDy                     :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgtHeading_Sts_Flag       :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_PotentialTgtHeading                :6;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgtDetn_Sts_Flag          :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_PotentialTgtDetn                   :2;
        }s_ACC_FD2_2AB_Inf_1_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_1_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_2;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RlvTgtTyp_Sts_Flag                 :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_RlvTgtTyp                          :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RlvTgtDy_Sts_Flag                  :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_RlvTgtDy                           :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RlvTgtHeading_Sts_Flag             :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_RlvTgtHeading                      :6;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RlvTgtDetn_Sts_Flag                :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RlvTgtDetn                         :2;
        }s_ACC_FD2_2AB_Inf_2_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_2_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_3;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgtTyp_Sts_Flag                  :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_LeTgtTyp                           :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgtDy_Sts_Flag                   :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_LeTgtDy                            :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgtHeading_Sts_Flag              :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_LeTgtHeading                       :6;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTargrtDection_Sts_Flag           :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_LeTargrtDection                    :2;
        }s_ACC_FD2_2AB_Inf_3_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_3_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_4;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgtTyp_Sts_Flag                  :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_RiTgtTyp                           :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgtDy_Sts_Flag                   :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_RiTgtDy                            :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgtHeading_Sts_Flag              :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_RiTgtHeading                       :6;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTargrtDetn_Sts_Flag              :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RiTargrtDetn                       :2;
        }s_ACC_FD2_2AB_Inf_4_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_4_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_5;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgt_02_Typ_Sts_Flag              :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_LeTgt_02_Typ                       :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgt_02_Dy_Sts_Flag               :1;
            /*0x0-0x51:Valid value
            0x52-0x7F:Reserved*/
            uint32_t ACC_LeTgt_02_Dy                        :7;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTargrt_02_Detn_Sts_Flag          :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_LeTargrt_02_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgt_02_Typ_Sts_Flag              :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Reserved
            0x7:Invalid*/
            uint32_t ACC_RiTgt_02_Typ                       :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgt_02_Dy_Sts_Flag               :1;
            /*0x0-0x51:Valid value
            0x52-0x7F:Reserved*/
            uint32_t ACC_RiTgt_02_Dy                        :7;
        }s_ACC_FD2_2AB_Inf_5_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_5_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_6;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTargrt_02_Detn_Sts_Flag          :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RiTargrt_02_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_ModDisp_Sts_Flag                   :1;
            /*0x00:OFF Mode
            0x01:Passive Mode
            0x02:StandBy Mode
            0x03:Active-Control Mode
            0x04:Brake-Only Mode
            0x05:Override
            0X06:Reserved
            0X07:ACC and PEBS Failure mode
            0x08:ACC Failure mode 
            0x09-0x1F:Reserved*/
            uint32_t ACC_ModDisp                            :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t TJA_ICA_ModDisp_Sts_Flag               :1;
            /*0x0:OFF mode
            0x1:Passive mode
            0x2:Active mode
            0x3:Ready mode
            0x4:Failure
            0x5-0x7:Reserved  */
            uint32_t TJA_ICA_ModDisp                        :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_TgtObjBarDisp_Sts_Flag             :1;
            /*0x0:No display
            0x1:Distance_1 one bar
            0x2:Distance_2 two bars
            0x3:Distance_3 three bars
            0x4:Distance_4 four bars
            0x5-0x7:Resvered*/
            uint32_t ACC_TgtObjBarDisp                      :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_FctSts_Sts_Flag                    :1;
            /*0x0:Fuction Not  Available
            0x1:Fuction Available 
            0x2:Performance degradation
            0x3:Reserved*/
            uint32_t ACC_FctSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HWA_InterSysInfoDisp_Sts_Flag          :1;
            /*0x0:No display
            0x1:Unable to activate HWA due to other limitation
            0x2:HWA active control is cancelled  
            0x3:Turn off the turn light
            0x4:Active confirm
            0x5:Overtime for lane change
            0x6:lane change is cancelled
            0x7:HWA temporary unavailable
            0x8:Speed is too low to support lane change
            0x9:HWA need to restart the engine
            0xA:Take over request
            0xB: Please Keep Attention
            0xC:To cross the tunnel, please take over??in time
            0xD:Have a branch road ahead. Please take over in time
            0xE-0xF:Reserve*/
            uint32_t HWA_InterSysInfoDisp                   :4;
        }s_ACC_FD2_2AB_Inf_6_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_6_t;
    union
    {
        uint32_t ACC_FD2_2AB_Inf_7;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_InterSysInfoDisp_Sts_Flag          :1;
            /*0x00:No display
            0x01:Unable to activate ACC due to speed not achive
            0x02:ACC active control is cancelled
            0x03:Resvered
            0x04:ACC and PEBS temporary unavailable
            0x05:Unable to activate ACC due to other limitation(except speed not achive)
            0x06:ACC and PEBS error
            0x07:ACC temporary unavailable
            0x08:ACC is active
            0x09:Blindness
            0x0A-0x1F:Resvered*/
            uint32_t ACC_InterSysInfoDisp                   :5;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t TJA_ICA_InterSysInfoDisp_Sts_Flag      :1;
            /*0x0:No display
            0x1:Unable to activate TJA/ICA due to other limitation
            0x2:TJA/ICA active control is cancelled
            0x3:TJA/ICA   temporarily unavailable   
            0x4:Current IGN Cycle Function Inhibit
            0x5:TJA is active
            0x6-0x7:Resvered*/
            uint32_t TJA_ICA_InterSysInfoDisp               :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t Request_driveoff_Sts_Flag              :1;
            /*0x0:no request
            0x1:The front car has started
            0x2:The front car has started,Please pay attention to the road environment ahead
            0x3:The front car has started,please keep your attention
            0x4:The front car has started,please take over the car
            0x5-0x7:Reserved*/
            uint32_t Request_driveoff                       :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HWA_ModDisp_Sts_Flag                   :1;
            /*0x0:OFF
            0x1:Safstop
            0x2:Passive
            0x3:Ready
            0x4:Active
            0x5:Override
            0x6:Slow retreat
            0x7:Standstill
            0x8-0xE:Reserved
            0xF:Fault*/
            uint32_t HWA_ModDisp                            :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HWA_LaneChange_Sts_Flag                :1;
            /*0x0:No display 
            0x1:left 
            0x2:right
            0x3:reserved*/
            uint32_t HWA_LaneChange                         :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t HWA_LaneChangeReq_Sts_Flag             :1;
            /*0x0:No display 
            0x1:left satisfied
            0x2:right satisfied
            0x3:left not satisfied
            0x4:right not satisfied
            0x5~0x7:reserved */
            uint32_t HWA_LaneChangeReq                      :3;
        }s_ACC_FD2_2AB_Inf_7_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_7_t;
    union
    {
        uint64_t ACC_FD2_2AB_Inf_8;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t HWA_Resp_Sts_Flag                      :1;
            /*0x0: OFF
            0X1: ON*/
            uint64_t HWA_Resp                               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ALC_Resp_Sts_Flag                      :1;
            /*0x0:OFF
            0X1:ON*/
            uint64_t ALC_Resp                               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_EgoStatus_Sts_Flag                 :1;
            /*0x0:No Display
            0x1:Override
            0x2:Deceleration
            0x3:Reserved*/
            uint64_t ACC_EgoStatus                          :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_SpdSetValue_Sts_Flag               :1;
            /*0x00-0xFE:Valid value
            0xFF:No display*/
            uint64_t ACC_SpdSetValue                        :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_TimeGapSet_Sts_Flag                :1;
            /*0x0:No display
            0x1:TimeGap_1 1s
            0x2:TimeGap_2 1.4s
            0x3:TimeGap_3 1.8s
            0x4:TimeGap_4 2.1s
            0x5-0x7:Reserved*/
            uint64_t ACC_TimeGapSet                         :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_PotentialTgtDx_Sts_Flag            :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_PotentialTgtDx                     :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_RlvTgtDx_Sts_Flag                  :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RlvTgtDx                           :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_LeTgtDx_Sts_Flag                   :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_LeTgtDx                            :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ISL_InterSysInfoDisp_Sts_Flag          :1;
            /*0x0:No display
            0x1:Speed Limit Confirm Request
            0x2:Speed Limit Take Over Request
            0x3:Resvered*/
            uint64_t ISL_InterSysInfoDisp                   :2;
        }s_ACC_FD2_2AB_Inf_8_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_8_t;
    union
    {
        uint64_t ACC_FD2_2AB_Inf_9;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_RiTgtDx_Sts_Flag                   :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RiTgtDx                            :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_LeTgt_02_Dx_Sts_Flag               :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_LeTgt_02_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t ACC_RiTgt_02_Dx_Sts_Flag               :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RiTgt_02_Dx                        :9;
        }s_ACC_FD2_2AB_Inf_9_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t;
}IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t;

/* Pack function of sub message ACC_FD2_2AB */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Pack(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ACC_FD2_2AB */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Parse(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: IFC_FD2_23D */
typedef struct
{
    union
    {
        uint16_t IFC_FD2_23D_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t IFC_FD2_23D_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t LSSIntervention_Sts_Flag               :1;
            /*0x0:No warning and Intervention 
            0x1: Left warning 
            0x2: Right warning
            0x3: Left Intervention 
            0x4:Right Intervention 
            0x5:Both Intervention 
            0x6: Left warn only reminder
            0x7: Right warn only reminder*/
            uint16_t LSSIntervention                        :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t TJA_FollowSts_Sts_Flag                 :1;
            /*0x0:No Follow
            0x1:Follow Vehicle
            0x2-0x3:Reserved*/
            uint16_t TJA_FollowSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t IntelligentEvaActSts_Sts_Flag          :1;
            /*0x0:Inactive
            0x1:Left Eva
            0x2:Right Eva
            0x3:Reserved*/
            uint16_t IntelligentEvaActSts                   :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t LaneAvailability_Sts_Flag              :1;
            /*0x0:not avaliable
            0x1:left lane marker available
            0x2:right lane marker available
            0x3:both lane marker available*/
            uint16_t LaneAvailability                       :2;
        }s_IFC_FD2_23D_Inf_t;
    }u_IFC_FD2_23DIFC_FD2_23D_Inf_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t;

/* Pack function of sub message IFC_FD2_23D */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IFC_FD2_23D */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: AEB_FD2_227 */
typedef struct
{
    union
    {
        uint32_t AEB_FD2_227_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t AEB_FD2_227_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t FCW_Warn_Sts_Flag                      :1;
            /*0x0:No warning
            0x1:Latent warning 
            0x2:warning Level 1  
            0x3:warning Level 2*/
            uint32_t FCW_Warn                               :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t AEB_VehTrig_Sts_Flag                   :1;
            /*0x0:not tirggered
            0x1:triggered*/
            uint32_t AEB_VehTrig                            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t AEB_PedTrig_Sts_Flag                   :1;
            /*0x0:not tirggered
            0x1:triggered*/
            uint32_t AEB_PedTrig                            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t AEB_JABrkTrig_Sts_Flag                 :1;
            /*0x0:Not tirggered
            0x1:AEB_JA Function Triggered for vehicle
            0x2:AEB_JA Function Triggered for pedestrian
            0x3:reverse*/
            uint32_t AEB_JABrkTrig                          :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgt_03_Typ_Sts_Flag              :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck*/
            uint32_t ACC_RiTgt_03_Typ                       :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTargrt_03_Detn_Sts_Flag          :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RiTargrt_03_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgt_03_Dx_Sts_Flag               :1;
            /*0x0_0x190:Valid_value
            0x191_0x1FF:Reserved*/
            uint32_t ACC_RiTgt_03_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgt_03_Typ_Sts_Flag              :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Traffic_cone
            0x7:Obstacle*/
            uint32_t ACC_LeTgt_03_Typ                       :3;
        }s_AEB_FD2_227_Inf_t;
    }u_AEB_FD2_227AEB_FD2_227_Inf_t;
    union
    {
        uint32_t AEB_FD2_227_Inf_2;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_RiTgt_03_Dy_Sts_Flag               :1;
            /*0x0_0xA0:Valid_value
            0xA1_0xFF:Reserved*/
            uint32_t ACC_RiTgt_03_Dy                        :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTargrt_03_Detn_Sts_Flag          :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_LeTargrt_03_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgt_03_Dx_Sts_Flag               :1;
            /*0x0_0x190:Valid_value
            0x191_0x1FF:Reserved*/
            uint32_t ACC_LeTgt_03_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgt_02_Dx_Sts_Flag        :1;
            /*0x0-0x12C:Valid_value
            0x12D-0x1FF:Reserved*/
            uint32_t ACC_PotentialTgt_02_Dx                 :9;
        }s_AEB_FD2_227_Inf_2_t;
    }u_AEB_FD2_227AEB_FD2_227_Inf_2_t;
    union
    {
        uint32_t AEB_FD2_227_Inf_3;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_LeTgt_03_Dy_Sts_Flag               :1;
            /*0x0_0xA0:Valid_value
            0xA1_0xFF:Reserved*/
            uint32_t ACC_LeTgt_03_Dy                        :8;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgt_02_Heading_Sts_Flag   :1;
            /*0x0_0x3C:Valid_value
            0x3D_0x3F:Reserved*/
            uint32_t ACC_PotentialTgt_02_Heading            :6;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgt_02_Typ_Sts_Flag       :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck
            0x3:Motorcycle
            0x4:Pedestrian
            0x5:Bicycle
            0x6:Traffic_cone
            0x7:Obstacle*/
            uint32_t ACC_PotentialTgt_02_Typ                :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgt_02_Detn_Sts_Flag      :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_PotentialTgt_02_Detn               :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t ACC_PotentialTgt_02_Dy_Sts_Flag        :1;
            /*0x0-0xA0:Valid_value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_PotentialTgt_02_Dy                 :8;
        }s_AEB_FD2_227_Inf_3_t;
    }u_AEB_FD2_227AEB_FD2_227_Inf_3_t;
}IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t;

/* Pack function of sub message AEB_FD2_227 */
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Pack(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AEB_FD2_227 */
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Parse(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: CR_FD1_15E */
typedef struct
{
    union
    {
        uint8_t CR_FD1_15E_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t CR_FD1_15E_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t FCTA_Warn_Sts_Flag                      :1;
            /*0x0:No warning
            0x1:Warning*/
            uint8_t FCTA_Warn                               :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t FCTBTrig_Sts_Flag                       :1;
            /*0x0:Not tirggered
            0x1: tirggered*/
            uint8_t FCTBTrig                                :1;
        }s_CR_FD1_15E_Inf_t;
    }u_CR_FD1_15ECR_FD1_15E_Inf_t;
}IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t;

/* Pack function of sub message CR_FD1_15E */
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Pack(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CR_FD1_15E */
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Parse(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: IFC_FD3_2CF */
typedef struct
{
    union
    {
        uint64_t IFC_FD3_2CF_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint64_t IFC_FD3_2CF_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IDC_L2_TurnLightReq_Sts_Flag           :1;
            /*0x0:Turn OFF
            0x1:Turn Left ON
            0x2:Turn Right ON
            0x3:reserved*/
            uint64_t IDC_L2_TurnLightReq                    :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t HWA_WarnInfoDisp_Sts_Flag              :1;
            /*0x0:No_display
            0x1:Construction_site_ahead
            0x2:large_vehicles_warn
            0x3:Night_warning
            0x4:Adverse_weather_warning
            0x5:Restart_to_activate_HIPilot
            0x6:Camera_blocked
            0x7:Auto_store_to_debug_HIPilot
            0x8:Restart_to_activate_ALC
            0x9:Auto_store_to_debug_ALC
            0xA:Try_ALC_later
            0xB:lane_change_is_cancelled_because_of_risk
            0xC:lane_change_aborted
            0xD:Please_Keep_Attention_distraction
            0xE_0xF:Reserve*/
            uint64_t HWA_WarnInfoDisp                       :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t MRC_InterSysInfoDisp_Sts_Flag          :1;
            /*0x0:default
            0x1:L_CR_fail
            0x2:R_CR_fail
            0x3:L_RSDS_fail
            0x4:R_RSDS_fail
            0x5:Radar_or_Cam_fail
            0x6_0xF:Reserved*/
            uint64_t MRC_InterSysInfoDisp                   :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t HWA_ALC_Trig_Sts_Flag                  :1;
            /*0x0:No_display
            0x1:Slow_vehicle_ahead
            0x2:Reserved
            0x3:Reserved*/
            uint64_t HWA_ALC_Trig                           :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Stop_Mark_Detn_Sts_Flag                :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Stop_Mark_Detn                         :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Stop_Mark_Dx_Sts_Flag                  :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Stop_Mark_Dx                           :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Zebra_Mark_Detn_Sts_Flag               :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Zebra_Mark_Detn                        :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Zebra_Mark_Dx_Sts_Flag                 :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Zebra_Mark_Dx                          :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Grid_Mark_Detn_Sts_Flag                :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Grid_Mark_Detn                         :2;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t Grid_Mark_Dx_Sts_Flag                  :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Grid_Mark_Dx                           :9;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t HWA_InhibitWarn_Sts_Flag               :1;
            /*0x0 Default 0x1Environment_inhibit 0x2 Attention 0x03 Handson 0x04 Seatbelt 0x05 Close_door*/
            uint64_t HWA_InhibitWarn                        :3;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line01_Source_Sts_Flag             :1;
            /*0x0:Detected value
            0x1:Fitted value*/
            uint64_t IFC_Line01_Source                      :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint64_t IFC_Line02_Source_Sts_Flag             :1;
            /*0x0:Detected value
            0x1:Fitted value*/
            uint64_t IFC_Line02_Source                      :1;
        }s_IFC_FD3_2CF_Inf_t;
    }u_IFC_FD3_2CFIFC_FD3_2CF_Inf_t;
    union
    {
        uint16_t IFC_FD3_2CF_Inf_1;
        struct
        {
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t TSRSpdLim_Sts_Flag                     :1;
            /*0x0:No Display
            0x1-0x1E:Valid Value
            0x1F-0x3E:Reserved
            0x3F:Invalid*/
            uint16_t TSRSpdLim                              :6;
            /*0x0:Detected value
            0x1:Fitted value*/
            uint16_t HWA_TakOver_Req_Sts_Flag               :1;
            /*0x0 Default
            0x1 Steer_wheel_req
            0x2 Takeover_req
            0x3 Reserved */
            uint16_t HWA_TakOver_Req                        :2;
            /*0x0:Detected value
            0x1:Fitted value*/
            uint16_t AutoSpdSetSwt_Resp_Sts_Flag            :1;
            /*0x0:OFF
            0x1:ON*/
            uint16_t AutoSpdSetSwt_Resp                     :1;
        }s_IFC_FD3_2CF_Inf_1_t;
    }u_IFC_FD3_2CFIFC_FD3_2CF_Inf_1_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t;

/* Pack function of sub message IFC_FD3_2CF */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Pack(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message IFC_FD3_2CF */
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Parse(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ACC_FD3_2B4 */
typedef struct
{
    union
    {
        uint16_t ACC_FD3_2B4_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t ACC_FD3_2B4_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t NOH_Sts_Sts_Flag                       :1;
            /*0x0:OFF
            0x1:Passive
            0x2:Standby
            0x3:Active
            0x4:Override
            0x5:Slow retreat
            0x6:Standstill
            0x7-0xE:reserved
            0xF:Fail
            */
            uint16_t NOH_Sts                                :4;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t NOH_SysInfoDisplay_Sts_Flag            :1;
            /*0x0:default
            0x1:In NOH GeoFence
            0x2:NOH is activated
            0x3:Please confirm L lane change
            0x4:Please confirm R lane change
            0x5:To overtake from left
            0x6:To overtake from right
            0x7:Lane change waiting
            0x8:To merge in mainroad 
            0x9:NOH to be deactivated
            0xA:NOH deactivated
            0xB-0xF:Reserve*/
            uint16_t NOH_SysInfoDisplay                     :4;
        }s_ACC_FD3_2B4_Inf_t;
    }u_ACC_FD3_2B4ACC_FD3_2B4_Inf_t;
}IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t;

/* Pack function of sub message ACC_FD3_2B4 */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Pack(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ACC_FD3_2B4 */
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Parse(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: BCM1_319 */
typedef struct
{
    union
    {
        uint8_t BCM1_319_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t BCM1_319_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t DrvDoorSts_Sts_Flag                     :1;
            /*0x0:Closed;0x1:Open*/
            uint8_t DrvDoorSts                              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t BrkPedalSts_BCM_Sts_Flag                :1;
            /*0x0:Off
            0x1:On*/
            uint8_t BrkPedalSts_BCM                         :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t LowBeamSts_Sts_Flag                     :1;
            /*0x0:Off
            0x1:On*/
            uint8_t LowBeamSts                              :1;
        }s_BCM1_319_Inf_t;
    }u_BCM1_319BCM1_319_Inf_t;
}IPC_M2S_ClusterAppCANAdaptBCM1_319_t;

/* Pack function of sub message BCM1_319 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Pack(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BCM1_319 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Parse(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: BCM3_345 */
typedef struct
{
    union
    {
        uint8_t BCM3_345_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t BCM3_345_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t DrvDoorLockSts_Sts_Flag                 :1;
            /*0x0:Lock;0x1:Unlock*/
            uint8_t DrvDoorLockSts                          :1;
        }s_BCM3_345_Inf_t;
    }u_BCM3_345BCM3_345_Inf_t;
}IPC_M2S_ClusterAppCANAdaptBCM3_345_t;

/* Pack function of sub message BCM3_345 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Pack(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BCM3_345 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Parse(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: T_Box_FD10_2F0 */
typedef struct
{
    union
    {
        uint8_t T_Box_FD10_2F0_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t T_Box_FD10_2F0_MSG_TimeoutFlag          :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t V2X_RLVW_Sts_Flag                       :1;
            /*0x0:No Warning
            0x1:Warning
            0x2-0x3:Reserved*/
            uint8_t V2X_RLVW                                :2;
        }s_T_Box_FD10_2F0_Inf_t;
    }u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t;
}IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t;

/* Pack function of sub message T_Box_FD10_2F0 */
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Pack(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message T_Box_FD10_2F0 */
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Parse(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ECM24_350 */
typedef struct
{
    union
    {
        uint32_t ECM24_350_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint32_t ECM24_350_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t EngOilPres_Sts_Flag                    :1;
            /*0x0-0x78:Valid values
            0x79-0x7E:Reserve
            0x7F:Invalid value*/
            uint32_t EngOilPres                             :7;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint32_t EngOilTemp_Sts_Flag                    :1;
            /*0x0-0xC8:Valid values
            0xC9-0xFE:Reserve
            0xFF:Invalid value*/
            uint32_t EngOilTemp                             :8;
        }s_ECM24_350_Inf_t;
    }u_ECM24_350ECM24_350_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM24_350_t;

/* Pack function of sub message ECM24_350 */
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Pack(IPC_M2S_ClusterAppCANAdaptECM24_350_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ECM24_350 */
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Parse(IPC_M2S_ClusterAppCANAdaptECM24_350_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: BCM12_238 */
typedef struct
{
    union
    {
        uint16_t BCM12_238_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t BCM12_238_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t SrPosn_VR_APP_Sts_Flag                 :1;
            /*0x0:Tilt up
            0x1~0x9:reserved
            0xA:10%
            0xB~0x13:reserved
            0x14:20%
            0x15~0x1D:reserved
            0x1E:30%*/
            uint16_t SrPosn_VR_APP                          :7;
        }s_BCM12_238_Inf_t;
    }u_BCM12_238BCM12_238_Inf_t;
}IPC_M2S_ClusterAppCANAdaptBCM12_238_t;

/* Pack function of sub message BCM12_238 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Pack(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BCM12_238 */
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Parse(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: F_PBOX1_19B */
typedef struct
{
    union
    {
        uint16_t F_PBOX1_19B_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t F_PBOX1_19B_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t LowBeamSts_F_PBOX_Sts_Flag             :1;
            /*0x0: OFF
            0X1: ON*/
            uint16_t LowBeamSts_F_PBOX                      :1;
        }s_F_PBOX1_19B_Inf_t;
    }u_F_PBOX1_19BF_PBOX1_19B_Inf_t;
}IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t;

/* Pack function of sub message F_PBOX1_19B */
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Pack(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message F_PBOX1_19B */
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Parse(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: HCM_L2_304 */
typedef struct
{
    union
    {
        uint8_t HCM_L2_304_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t HCM_L2_304_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t LeftLightShowSts_Sts_Flag               :1;
            /*0x0:Animation OFF
            0x1:Approach light Animation In Process 
            0x2:Approach light Animation Successful 
            0x3:Approach light Animation Failure
            0x4:Unlock light Animation In Process
            0x5:Unlock light Animation Successful
            0x6:Unlock light Animation Failure
            0x7:Lock light Animation In Process
            0x8: Lock light Animation Successful
            0x9: Lock light Animation Failure
            0xA:Light show Animation In Process
            0xB:Light show Animation Successful
            0xC:Light show Animation Failure
            0xD-0x1F:Reserved
            */
            uint8_t LeftLightShowSts                        :5;
        }s_HCM_L2_304_Inf_t;
    }u_HCM_L2_304HCM_L2_304_Inf_t;
}IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t;

/* Pack function of sub message HCM_L2_304 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Pack(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HCM_L2_304 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Parse(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: VCU_FD41_2D6 */
typedef struct
{
    union
    {
        uint16_t VCU_FD41_2D6_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint16_t VCU_FD41_2D6_MSG_TimeoutFlag           :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint16_t VCU_GModeSts_Sts_Flag                  :1;
            /*0x0:G mode off
            0x1:Received G mode require
            0x2:G mode prepare active
            0x3:G mode active
            0x4~0x7:Reserved*/
            uint16_t VCU_GModeSts                           :3;
        }s_VCU_FD41_2D6_Inf_t;
    }u_VCU_FD41_2D6VCU_FD41_2D6_Inf_t;
}IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t;

/* Pack function of sub message VCU_FD41_2D6 */
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Pack(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message VCU_FD41_2D6 */
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Parse(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: HCM_R2_330 */
typedef struct
{
    union
    {
        uint8_t HCM_R2_330_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t HCM_L2_330_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t RightLightShowSts_Sts_Flag              :1;
            /*0x0:Animation OFF
            0x1:Approach light Animation In Process 
            0x2:Approach light Animation Successful 
            0x3:Approach light Animation Failure
            0x4:Unlock light Animation In Process
            0x5:Unlock light Animation Successful
            0x6:Unlock light Animation Failure
            0x7:Lock light Animation In Process
            0x8: Lock light Animation Successful
            0x9: Lock light Animation Failure
            0xA:Light show Animation In Process
            0xB:Light show Animation Successful
            0xC:Light show Animation Failure
            0xD-0x1F:Reserved
            */
            uint8_t RightLightShowSts                       :5;
        }s_HCM_R2_330_Inf_t;
    }u_HCM_R2_330HCM_R2_330_Inf_t;
}IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t;

/* Pack function of sub message HCM_R2_330 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Pack(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HCM_R2_330 */
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Parse(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ESP1_149 */
typedef struct
{
    union
    {
        uint8_t ESP1_149_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout；*/
            uint8_t ESP1_149_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS：发送0x1表示当前项目没有包含该信号*/
            uint8_t ESPBrkLmpCtrl_149_Sts_Flag              :1;
            /*0x0:Brake light off
            0x1:Brake light on*/
            uint8_t ESPBrkLmpCtrl_149                       :1;
        }s_ESP1_149_Inf_t;
    }u_ESP1_149ESP1_149_Inf_t;
}IPC_M2S_ClusterAppCANAdaptESP1_149_t;

/* Pack function of sub message ESP1_149 */
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Pack(IPC_M2S_ClusterAppCANAdaptESP1_149_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ESP1_149 */
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Parse(IPC_M2S_ClusterAppCANAdaptESP1_149_t *in_data, uint8_t *payload, uint16_t length);

/* Group: : ClusterApp */
/* Group: : ClusterApp */
/* Message Major: ClusterSoc */
/* Message Sub: WrnId */
typedef struct
{
    /*Current display general warning id;65535 is no warning;*/
    uint16_t General;
    /*0xffff:No shied,other:Shied warning ID*/
    uint16_t GeneralShied;
    /*Door and Tpms:
    bit0:FL;bit1:FR;bit2:RL;bit3:RR;bit4:Trunk;bit5:Hatch
    Seltbelt:
    bit0:Driver;bit1:Passenger;bit2:Rear left;bit3:Rear mid;bit4:Rear right;*/
    uint16_t GeneralBit;
    /*Current display adas warning id;65535 is no wanring*/
    uint16_t Adas;
    /*Current display adas fault warning id:0 is no warning*/
    uint8_t AdasFault;
    union
    {
        uint8_t FirstDisplayFlag;
        struct
        {
            /*TRUE:First time display,FALSE:Not*/
            uint8_t GeneralFirstDisplay                     :1;
            /*TRUE:First time display,FALSE:Not*/
            uint8_t AdasFirstDisplay                        :1;
            /*TRUE:First time display,FALSE:Not*/
            uint8_t AdasFaultFirstDisplay                   :1;
            /*reserved bit*/
            uint8_t Reserved                                :5;
        }s_FirstDisplayFlag_t;
    }u_WrnIdFirstDisplayFlag_t;
}IPC_S2M_ClusterAppClusterSocWrnId_t;

/* Pack function of sub message WrnId */
int32_t IPC_S2M_ClusterAppClusterSocWrnId_Pack(IPC_S2M_ClusterAppClusterSocWrnId_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message WrnId */
int32_t IPC_S2M_ClusterAppClusterSocWrnId_Parse(IPC_S2M_ClusterAppClusterSocWrnId_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TTStatus */
typedef struct
{
    union
    {
        uint8_t u32Telltales_status[6];
        struct
        {
            /*胎压指示灯Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t TPMS_Data                               :4;
            /*混合动力系统故障红色指示灯status: 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t HEV_Red_Data                            :4;
            /*安全带未系灯  0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t Seat_Belt_Data                          :4;
            /*reserve*/
            uint8_t Turn_Left_Data                          :4;
            /*reserve*/
            uint8_t Turn_Right_Data                         :4;
            /*超速报警指示灯0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t TSR_120KMH_Data                         :4;
            /*CCO越野巡航故障灯  0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t CCO_Inactive_Data                       :4;
            /*TAB失效指示灯 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t Steer_Assit_Error_Data                  :4;
            /*reserve*/
            uint8_t HEV_Yellow_Data                         :4;
            /*reserve*/
            uint8_t Ready_Light_Data                        :4;
        }s_u32Telltales_status_t;
    }u_TTStatusu32Telltales_status_t;
}IPC_S2M_ClusterAppClusterSocTTStatus_t;

/* Pack function of sub message TTStatus */
int32_t IPC_S2M_ClusterAppClusterSocTTStatus_Pack(IPC_S2M_ClusterAppClusterSocTTStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TTStatus */
int32_t IPC_S2M_ClusterAppClusterSocTTStatus_Parse(IPC_S2M_ClusterAppClusterSocTTStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: AdasStatus */
typedef struct
{
    union
    {
        uint8_t AdasWarn[4];
        struct
        {
            /*无法识别静止目标*/
            uint16_t Id_StillTargetNotRecognized            :1;
            /*变道辅助超时，请关闭转向灯*/
            uint16_t Id_LaneChangeAssistTimeout             :1;
            /*变道辅助已取消*/
            uint16_t Id_LaneChangeAssistCancelled           :1;
            /*变道辅助已完成，请关闭转向灯*/
            uint16_t Id_LaneChangeAssistcompleted           :1;
            /*车速太低不支持变道辅助*/
            uint16_t Id_LaneChangeAssistIsNotSupported      :1;
            /*自适应巡航无法激活*/
            uint16_t Id_ACCCannotBeActivated                :1;
            /*自适应巡航功能取消*/
            uint16_t Id_ACCFunctionCanceled                 :1;
            /*自适应巡航退出*/
            uint16_t Id_ACCExit                             :1;
            /*自适应巡航已激活请保持注意力*/
            uint16_t Id_ACCIsActivated                      :1;
            /*智能巡航辅助无法激活*/
            uint16_t Id_TJAICACannotBeActivated             :1;
            /*智能巡航辅助功能取消*/
            uint16_t Id_TJAICAFunctionCanceled              :1;
            /*智能巡航退出*/
            uint16_t Id_TJAICAExit                          :1;
            /*智能巡航已激活请保持注意力并手握方向盘*/
            uint16_t Id_TJAICAIsActivated                   :1;
            /*智能巡航辅助需车辆重新启动后使用*/
            uint16_t Id_TJAICANeedsToVehicleRestart         :1;
            /*前车已起步*/
            uint16_t Id_FrontVehicleHasStarted              :1;
            /*前车已起步，请注意前方道路环境*/
            uint16_t Id_PlsPayAttentionToTheRoadAhead       :1;
            /*前车已起步，请保持注意力*/
            uint16_t Id_PlsKeepYourAttention                :1;
            /*前车已起步，请接管车辆*/
            uint16_t Id_PlsTakeOverTheVehicle               :1;
            /*车间时距*/
            uint16_t Id_TheTimeGap                          :1;
            uint16_t Reserved                               :13;
        }s_AdasWarn_t;
    }u_AdasStatusAdasWarn_t;
}IPC_S2M_ClusterAppClusterSocAdasStatus_t;

/* Pack function of sub message AdasStatus */
int32_t IPC_S2M_ClusterAppClusterSocAdasStatus_Pack(IPC_S2M_ClusterAppClusterSocAdasStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message AdasStatus */
int32_t IPC_S2M_ClusterAppClusterSocAdasStatus_Parse(IPC_S2M_ClusterAppClusterSocAdasStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: BackChime */
typedef struct
{
    /*Current sound id,0 is no sound*/
    uint8_t CurId;
    /*Last sound play times,0 is continue sound, if last chime id is 0,No care this value*/
    uint8_t LastRepeat;
}IPC_S2M_ClusterAppClusterSocBackChime_t;

/* Pack function of sub message BackChime */
int32_t IPC_S2M_ClusterAppClusterSocBackChime_Pack(IPC_S2M_ClusterAppClusterSocBackChime_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BackChime */
int32_t IPC_S2M_ClusterAppClusterSocBackChime_Parse(IPC_S2M_ClusterAppClusterSocBackChime_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TCClear */
typedef struct
{
    /*0x11:Reset TC_B data,Other:Reserved*/
    uint8_t MenuResrt;
}IPC_S2M_ClusterAppClusterSocTCClear_t;

/* Pack function of sub message TCClear */
int32_t IPC_S2M_ClusterAppClusterSocTCClear_Pack(IPC_S2M_ClusterAppClusterSocTCClear_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TCClear */
int32_t IPC_S2M_ClusterAppClusterSocTCClear_Parse(IPC_S2M_ClusterAppClusterSocTCClear_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: TtToChime */
typedef struct
{
    /*1: have tt flash   0 do not have tt flash */
    uint8_t TtFlash;
    /*the value is Flicker frequency*/
    uint32_t TtFlashTick;
}IPC_S2M_ClusterAppClusterSocTtToChime_t;

/* Pack function of sub message TtToChime */
int32_t IPC_S2M_ClusterAppClusterSocTtToChime_Pack(IPC_S2M_ClusterAppClusterSocTtToChime_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message TtToChime */
int32_t IPC_S2M_ClusterAppClusterSocTtToChime_Parse(IPC_S2M_ClusterAppClusterSocTtToChime_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: CommonAppAlive */
typedef struct
{
    /*0xAA:Service Alive，other：reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocCommonAppAlive_t;

/* Pack function of sub message CommonAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocCommonAppAlive_Pack(IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message CommonAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocCommonAppAlive_Parse(IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: MenuSetting */
typedef struct
{
    /*0:SetNaviLimitSpeedValue  
    1:SetNaviLimitSpeedEnable  
    2:SetLanguage     
    3:SetClusterTheme    
    4:SetOdometerUnits   
    5:SetTemperatureUnits   
    6:SetTirePressureUnits  
    7:SetTripComputerId   
    8:SetInteractiveCard   
    9:SetDrivingModeMemorySwitch 
    10:SetTimeUnits    
    11:SetHighwayAssistSwitch  
    12:SetLaneChangeAssistSwitch 
    13:SetSunriseSunsetMode  
    14:SetAutoMode     
    15:SetClusterDrivingMode
    16:SetClusterThemeCANOutPut
    17:SetThemeLinkageSwitch
    18:SetDataSyncFlg
    19:SetAtmosphereLampLinkageSwitch
    20:SetSimSoundWaveLinkageSwitch
    21:SetMaoCallLinkageSwitch*/
    uint8_t ID;
    /*set change module data*/
    uint16_t Value;
}IPC_S2M_ClusterAppClusterSocMenuSetting_t;

/* Pack function of sub message MenuSetting */
int32_t IPC_S2M_ClusterAppClusterSocMenuSetting_Pack(IPC_S2M_ClusterAppClusterSocMenuSetting_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MenuSetting */
int32_t IPC_S2M_ClusterAppClusterSocMenuSetting_Parse(IPC_S2M_ClusterAppClusterSocMenuSetting_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: Gauges */
typedef struct
{
    /*Factor:0.1 km/h&mph Imperial and Metric value*/
    uint16_t VehicleSpeed;
    /*Factor:0.1rpm*/
    uint16_t EngineSpeed;
}IPC_S2M_ClusterAppClusterSocGauges_t;

/* Pack function of sub message Gauges */
int32_t IPC_S2M_ClusterAppClusterSocGauges_Pack(IPC_S2M_ClusterAppClusterSocGauges_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message Gauges */
int32_t IPC_S2M_ClusterAppClusterSocGauges_Parse(IPC_S2M_ClusterAppClusterSocGauges_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: InterfaceAppAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t;

/* Pack function of sub message InterfaceAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Pack(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message InterfaceAppAlive */
int32_t IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Parse(IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: HMIPowerMode */
typedef struct
{
    /*0x00:Default;0x01:PreSleep Mode;Other reserved*/
    uint8_t PowerStatus;
}IPC_S2M_ClusterAppClusterSocHMIPowerMode_t;

/* Pack function of sub message HMIPowerMode */
int32_t IPC_S2M_ClusterAppClusterSocHMIPowerMode_Pack(IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HMIPowerMode */
int32_t IPC_S2M_ClusterAppClusterSocHMIPowerMode_Parse(IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: GaugesAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocGaugesAlive_t;

/* Pack function of sub message GaugesAlive */
int32_t IPC_S2M_ClusterAppClusterSocGaugesAlive_Pack(IPC_S2M_ClusterAppClusterSocGaugesAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message GaugesAlive */
int32_t IPC_S2M_ClusterAppClusterSocGaugesAlive_Parse(IPC_S2M_ClusterAppClusterSocGaugesAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ChimeClientAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocChimeClientAlive_t;

/* Pack function of sub message ChimeClientAlive */
int32_t IPC_S2M_ClusterAppClusterSocChimeClientAlive_Pack(IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ChimeClientAlive */
int32_t IPC_S2M_ClusterAppClusterSocChimeClientAlive_Parse(IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: MenuTheme */
typedef struct
{
    /*主题ID（infra设置主题商城ID）*/
    uint32_t Rc_ThemeID;
    /*皮肤ID（infra设置主题商城ID）*/
    uint32_t Rc_SkinID;
}IPC_S2M_ClusterAppClusterSocMenuTheme_t;

/* Pack function of sub message MenuTheme */
int32_t IPC_S2M_ClusterAppClusterSocMenuTheme_Pack(IPC_S2M_ClusterAppClusterSocMenuTheme_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MenuTheme */
int32_t IPC_S2M_ClusterAppClusterSocMenuTheme_Parse(IPC_S2M_ClusterAppClusterSocMenuTheme_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: HMISafety */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocHMISafety_t;

/* Pack function of sub message HMISafety */
int32_t IPC_S2M_ClusterAppClusterSocHMISafety_Pack(IPC_S2M_ClusterAppClusterSocHMISafety_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message HMISafety */
int32_t IPC_S2M_ClusterAppClusterSocHMISafety_Parse(IPC_S2M_ClusterAppClusterSocHMISafety_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: MiaoCALL */
typedef struct
{
    /*1.138 喵CALL指示灯--喵call功能开启状态Status : 0:off  1:on  */
    uint8_t MiaoCALLsts;
}IPC_S2M_ClusterAppClusterSocMiaoCALL_t;

/* Pack function of sub message MiaoCALL */
int32_t IPC_S2M_ClusterAppClusterSocMiaoCALL_Pack(IPC_S2M_ClusterAppClusterSocMiaoCALL_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message MiaoCALL */
int32_t IPC_S2M_ClusterAppClusterSocMiaoCALL_Parse(IPC_S2M_ClusterAppClusterSocMiaoCALL_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: OffroadInfo */
typedef struct
{
    /*0:SetBaroPressure
    1:SetHeilvl
    2:SetHeilvlSign
    3:SetPitchAngle
    4:SetPitchAngleSign
    5:SetGeoGraphic
    6:SetSteerWheel
    7:SetSteerWheelSign*/
    uint8_t ID;
    /*offroadinfo value*/
    uint16_t Value;
}IPC_S2M_ClusterAppClusterSocOffroadInfo_t;

/* Pack function of sub message OffroadInfo */
int32_t IPC_S2M_ClusterAppClusterSocOffroadInfo_Pack(IPC_S2M_ClusterAppClusterSocOffroadInfo_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message OffroadInfo */
int32_t IPC_S2M_ClusterAppClusterSocOffroadInfo_Parse(IPC_S2M_ClusterAppClusterSocOffroadInfo_t *in_data, uint8_t *payload, uint16_t length);

/* Group: : ClusterApp */
/* Message Major: QNX */
/* Message Sub: BootStatus */
typedef struct
{
    /*0：Not requirement  1：rerequirement ；0xff:Invaid*/
    uint8_t Request;
}IPC_S2M_ClusterAppQNXBootStatus_t;

/* Pack function of sub message BootStatus */
int32_t IPC_S2M_ClusterAppQNXBootStatus_Pack(IPC_S2M_ClusterAppQNXBootStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message BootStatus */
int32_t IPC_S2M_ClusterAppQNXBootStatus_Parse(IPC_S2M_ClusterAppQNXBootStatus_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: ADASConfig */
typedef struct
{
    /*0：Not requirement  1：rerequirement ；other:Invaid*/
    uint8_t Request;
}IPC_S2M_ClusterAppQNXADASConfig_t;

/* Pack function of sub message ADASConfig */
int32_t IPC_S2M_ClusterAppQNXADASConfig_Pack(IPC_S2M_ClusterAppQNXADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message ADASConfig */
int32_t IPC_S2M_ClusterAppQNXADASConfig_Parse(IPC_S2M_ClusterAppQNXADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Message Sub: SetADASConfig */
typedef struct
{
    /*1 = on , 0 = off*/
    uint8_t HighwayAssistSwitch;
    /*1 = on , 0 = off*/
    uint8_t LaneChangeAssistSwitch;
}IPC_S2M_ClusterAppQNXSetADASConfig_t;

/* Pack function of sub message SetADASConfig */
int32_t IPC_S2M_ClusterAppQNXSetADASConfig_Pack(IPC_S2M_ClusterAppQNXSetADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Parse function of sub message SetADASConfig */
int32_t IPC_S2M_ClusterAppQNXSetADASConfig_Parse(IPC_S2M_ClusterAppQNXSetADASConfig_t *in_data, uint8_t *payload, uint16_t length);

/* Group: : ClusterApp */
#ifdef __cplusplus
}
#endif

#endif
