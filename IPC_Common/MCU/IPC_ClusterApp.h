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
*     Description file:  IPC_MCU.h.tem
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
            /*1.2 ������ϵͳ���ϱ����� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EngineSysFault_Data_selfcheck          :1;
            /*1.2 ������ϵͳ���ϱ����� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EngineSysFault_Data                    :3;
            /*1.4 ������ά��ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EngineFix_Data_selfcheck               :1;
            /*1.4 ������ά��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EngineFix_Data                         :3;
            /*1.6~1.11 ����Ѳ��ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t CruiseControl_Data_selfcheck           :1;
            /*1.6~1.11 ����Ѳ��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CruiseControl_Data                     :3;
            /*1.5 ������ˮ�¸�ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EngineHighTemp_Data_selfcheck          :1;
            /*1.5 ������ˮ�¸�ָʾ��- ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz  5:0.5hz  6~7 :reserve*/
            uint32_t EngineHighTemp_Data                    :3;
            /*1.6~1.11����ӦѲ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Enable_Data_selfcheck              :1;
            /*1.6~1.11����ӦѲ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Enable_Data                        :3;
            /*1.6~1.11����ӦѲ��δ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Disable_Data_selfcheck             :1;
            /*1.6~1.11����ӦѲ��δ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Disable_Data                       :3;
            /*1.6~1.11����ӦѲ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t ACC_Fault_Data_selfcheck               :1;
            /*1.6~1.11����ӦѲ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t ACC_Fault_Data                         :3;
            /*1.6~1.11����Ѳ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Enable_Data_selfcheck              :1;
            /*1.6~1.11����Ѳ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Enable_Data                        :3;
            /*1.6~1.11����Ѳ��δ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Disable_Data_selfcheck             :1;
            /*1.6~1.11����Ѳ��δ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Disable_Data                       :3;
            /*1.6~1.11����Ѳ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t TJA_Fault_Data_selfcheck               :1;
            /*1.6~1.11����Ѳ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TJA_Fault_Data                         :3;
            /*1.12������ͣ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t SS_Enable_Data_selfcheck               :1;
            /*1.12������ͣ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SS_Enable_Data                         :3;
            /*1.12������ͣ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t SS_Fault_Data_selfcheck                :1;
            /*1.12������ͣ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SS_Fault_Data                          :3;
            /*1.14~1.15���س�ŵ�ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t BatteryCharge_Data_selfcheck           :1;
            /*1.14~1.15���س�ŵ�ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t BatteryCharge_Data                     :3;
            /*1.18����ѹ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LowFuelPress_Data_selfcheck            :1;
            /*1.18����ѹ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LowFuelPress_Data                      :3;
            /*1.19�Զ�פ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t AutoPark_Enable_Data_selfcheck         :1;
            /*1.19�Զ�פ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AutoPark_Enable_Data                   :3;
            /*1.19�Զ�פ������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t AutoPark_Fault_Data_selfcheck          :1;
            /*1.19�Զ�פ������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AutoPark_Fault_Data                    :3;
            /*1.23����ָʾ��ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t HSD_Data_selfcheck                     :1;
            /*1.23����ָʾ��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSD_Data                               :3;
            /*1.24�綯פ������CHINAָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EPB_Enable_CH_Data_selfcheck           :1;
            /*1.24�綯פ������CHINAָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPB_Enable_CH_Data                     :3;
            /*1.24�綯פ������USָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EPB_Enable_US_Data_selfcheck           :1;
            /*1.24�綯פ������USָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPB_Enable_US_Data                     :3;
            /*1.26��̬פ������CHINAָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t DPB_Enable_CH_Data_selfcheck           :1;
            /*1.26��̬פ������CHINAָʾ�� - ָʾ��״̬                                      Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DPB_Enable_CH_Data                     :3;
            /*1.27��̬פ������USָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t DPB_Enable_US_Data_selfcheck           :1;
            /*1.27��̬פ������USָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DPB_Enable_US_Data                     :3;
            /*1.28Iboosterָʾ�ƻ�ɫCHINA - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Yellow_CH_Data_selfcheck      :1;
            /*1.28Iboosterָʾ�ƻ�ɫCHINA - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Yellow_CH_Data                :3;
            /*1.28Iboosterָʾ�ƺ�ɫCHINA - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Red_CH_Data_selfcheck         :1;
            /*1.28Iboosterָʾ�ƺ�ɫCHINA - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Red_CH_Data                   :3;
            /*1.28Iboosterָʾ�ƻ�ɫUS - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Yellow_US_Data_selfcheck      :1;
            /*1.28Iboosterָʾ�ƻ�ɫUS - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Yellow_US_Data                :3;
            /*1.28Iboosterָʾ�ƺ�ɫUS - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Ibooster_Red_US_Data_selfcheck         :1;
            /*1.28Iboosterָʾ�ƺ�ɫUS - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ibooster_Red_US_Data                   :3;
            /*1.29120KM/H���ٱ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_120KMH_Data_selfcheck              :1;
            /*1.29120KM/H���ٱ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_120KMH_Data                        :3;
            /*1.31~1.32ǰ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Front_Fog_Data_selfcheck               :1;
            /*1.31~1.32ǰ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Front_Fog_Data                         :3;
            /*1.33~1.34�����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Rear_Fog_Data_selfcheck                :1;
            /*1.33~1.34�����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Rear_Fog_Data                          :3;
            /*1.35~1.39Զ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t High_Beam_Data_selfcheck               :1;
            /*1.35~1.39Զ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t High_Beam_Data                         :3;
            /*1.40~1.41��ת��� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Turn_Left_Data_selfcheck               :1;
            /*1.40~1.41��ת��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Turn_Left_Data                         :3;
            /*1.42~1.43��ת��� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Turn_Right_Data_selfcheck              :1;
            /*1.42~1.43��ת��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Turn_Right_Data                        :3;
            /*1.44~1.45λ�õ� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Position_Data_selfcheck                :1;
            /*1.44~1.45λ�õ� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Position_Data                          :3;
            /*1.46~1.47�ƹ��ܿ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LightSwitch_Data_selfcheck             :1;
            /*1.46~1.47�ƹ��ܿ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LightSwitch_Data                       :3;
            /*1.48~1.49�ϳ�ת��� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Trailer_Data_selfcheck                 :1;
            /*1.48~1.49�ϳ�ת��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Trailer_Data                           :3;
            /*1.50-1.51�ſ�����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t DoorOpen_Data_selfcheck                :1;
            /*1.50-1.51�ſ�����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t DoorOpen_Data                          :3;
            /*1.52̥ѹ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t TPMS_Data_selfcheck                    :1;
            /*1.52̥ѹ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TPMS_Data                              :3;
            /*1.53�綯����ת��������Թ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t EPS_Yellow_Error_Data_selfcheck        :1;
            /*1.53�綯����ת��������Թ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EPS_Yellow_Error_Data                  :3;
            /*1.55��ȫ��δϵָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Seat_Belt_Data_selfcheck               :1;
            /*1.55��ȫ��δϵָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Seat_Belt_Data                         :3;
            /*1.57~1.59����������ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Trans_OverHeat_Data_selfcheck          :1;
            /*1.57~1.59���������� ָʾ��- ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Trans_OverHeat_Data                    :3;
            /*1.60~1.62�Զ�Զ��ƻ�ɫ - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Auto_Yellow_Data_selfcheck             :1;
            /*1.60~1.62�Զ�Զ��ƻ�ɫ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Auto_Yellow_Data                       :3;
            /*1.60~1.62�Զ�Զ�����ɫ - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Auto_Green_Data_selfcheck              :1;
            /*1.60~1.62�Զ�Զ�����ɫ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Auto_Green_Data                        :3;
            /*1.63��ȼ�ͱ���ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LowFuel_Data_selfcheck                 :1;
            /*1.63��ȼ�ͱ��� ָʾ��- ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LowFuel_Data                           :3;
            /*1.65ǰ����ײ����ָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t FCW_Enable_Data_selfcheck              :1;
            /*1.65ǰ����ײ����ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FCW_Enable_Data                        :3;
            /*1.66 LDW ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LDW_Enable_Data_selfcheck              :1;
            /*1.66 LDW ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LDW_Enable_Data                        :3;
            /*1.66 LDW ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LDW_Error_Data_selfcheck               :1;
            /*1.66 LDW ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LDW_Error_Data                         :3;
            /*1.67 LKA ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LKA_Enable_Data_selfcheck              :1;
            /*1.67 LKA ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LKA_Enable_Data                        :3;
            /*1.67 LKA ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LKA_Error_Data_selfcheck               :1;
            /*1.67 LKA ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LKA_Error_Data                         :3;
            /*1.68 LCK ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LCK_Enable_Data_selfcheck              :1;
            /*1.68 LCK ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LCK_Enable_Data                        :3;
            /*1.68 LCK ����ָʾ�� - ���� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t LCK_Error_Data_selfcheck               :1;
            /*1.68 LCK ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t LCK_Error_Data                         :3;
            /*1.69~1.70 READYָʾ�� - �Լ��־λ
            self check: 0~no self check ;1~self check*/
            uint32_t Ready_Light_Data_selfcheck             :1;
            /*1.69~1.70 READYָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Ready_Light_Data                       :3;
            /*1.71 EVָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t EV_Indicator_Data_selfcheck            :1;
            /*1.71 EV ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t EV_Indicator_Data                      :3;
            /*1.72~1.73 ������ع���ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t PBF_Warning_Data_selfcheck             :1;
            /*1.72~1.73 ������ع���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t PBF_Warning_Data                       :3;
            /*1.75 ���״ָ̬ʾ�� - ��ɫ - �Լ�״̬
            self check: 0~no self check ;1~self check
            1.105 �������ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_Green_Data_selfcheck          :1;
            /*1.75 ���״ָ̬ʾ�� - ��ɫ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve
            1.105 �������ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_Green_Data                    :3;
            /*1.75 ���״ָ̬ʾ��(PHEV/HEV) - ��ɫ - �Լ�״̬
            1.111��ŵ�����ָʾ��(EV)- �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_Red_Data_selfcheck            :1;
            /*1.75 ���״ָ̬ʾ��(PHEV/HEV) -��ɫ-ָʾ��״̬
            1.111��ŵ�����ָʾ��(EV)- ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_Red_Data                      :3;
            /*1.75 ���״ָ̬ʾ�� - ��΢���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_E_Yellow_Data_selfcheck       :1;
            /*1.75 ���״ָ̬ʾ�� - ��΢���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_E_Yellow_Data                 :3;
            /*1.75 ���״ָ̬ʾ�� - ���ع��� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Charging_E_Red_Data_selfcheck          :1;
            /*1.75 ���״ָ̬ʾ�� - ���ع��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Charging_E_Red_Data                    :3;
            /*1.82 ��Ҫ������ʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Secondary_Warning_Data_selfcheck       :1;
            /*1.82 ��Ҫ������ʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Secondary_Warning_Data                 :3;
            /*1.83 ��Ҫ������ʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Major_Warning_Data_selfcheck           :1;
            /*1.83 ��Ҫ������ʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Major_Warning_Data                     :3;
            /*1.85~1.86 פ��ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Parking_Data_selfcheck                 :1;
            /*1.85~1.86 פ��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Parking_Data                           :3;
            /*1.87 �ƶ��������չ���ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t RBS_Data_selfcheck                     :1;
            /*1.87 �ƶ��������չ���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RBS_Data                               :3;
            /*1.118 ������Ԥ��ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Engine_Warmup_Data_selfcheck           :1;
            /*1.118 ������Ԥ��ָʾ��- ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Engine_Warmup_Data                     :3;
            /*1.116 ɲ��Ƭĥ��ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t BrakePad_Worn_Data_selfcheck           :1;
            /*1.116 ɲ��Ƭĥ��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t BrakePad_Worn_Data                     :3;
            /*1.89 CCO����ָʾ�� - ���ܼ��� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Active_Data_selfcheck              :1;
            /*1.89 CCO����ָʾ�� - ���ܼ��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Active_Data                        :3;
            /*1.89 CCO����ָʾ�� - ���ܴ��� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Standby_Data_selfcheck             :1;
            /*1.89 CCO����ָʾ�� - ���ܴ��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Standby_Data                       :3;
            /*1.89 CCO����ָʾ�� - ���ܹ��� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t CCO_Inactive_Data_selfcheck            :1;
            /*1.89 CCO����ָʾ�� - ���ܹ��� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CCO_Inactive_Data                      :3;
            /*1.90 ǰ�ŵ��Ӳ�����״ָ̬ʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t FEDL_Active_Data_selfcheck             :1;
            /*1.90 ǰ�ŵ��Ӳ�����״ָ̬ʾ�� -���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FEDL_Active_Data                       :3;
            /*1.90 ǰ�ŵ��Ӳ�����״ָ̬ʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t FEDL_Inactive_Data_selfcheck           :1;
            /*1.90 ǰ�ŵ��Ӳ�����״ָ̬ʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t FEDL_Inactive_Data                     :3;
            /*1.91 ���ŵ��Ӳ�����״ָ̬ʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t REDL_Active_Data_selfcheck             :1;
            /*1.91 ���ŵ��Ӳ�����״ָ̬ʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t REDL_Active_Data                       :3;
            /*1.91 ���ŵ��Ӳ�����״ָ̬ʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t REDL_Inactive_Data_selfcheck           :1;
            /*1.91 ���ŵ��Ӳ�����״ָ̬ʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t REDL_Inactive_Data                     :3;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ������ - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Standby_Data_selfcheck            :1;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ������ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Standby_Data                      :3;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Active_Data_selfcheck             :1;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Active_Data                       :3;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAP_Error_Data_selfcheck              :1;
            /*1.93 ���ٵ������Զ���ʻ����ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAP_Error_Data                        :3;
            /*1.99 �����Զ��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Switch_Data_selfcheck             :1;
            /*1.99 �����Զ��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Switch_Data                       :3;
            /*1.99 �����Զ��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Active_Data_selfcheck             :1;
            /*1.99 �����Զ��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Active_Data                       :3;
            /*1.99 �����Զ��������ָʾ�� - ������ - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Standby_Data_selfcheck            :1;
            /*1.99 �����Զ��������ָʾ�� - ������ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Standby_Data                      :3;
            /*1.99 �����Զ��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t HSAS_Error_Data_selfcheck              :1;
            /*1.99 �����Զ��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t HSAS_Error_Data                        :3;
            /*1.96 ���߸���ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t AUX_Data_selfcheck                     :1;
            /*1.96 ���߸���ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AUX_Data                               :3;
            /*1.97 �������򾯸�ϵͳָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t RSW_Data_selfcheck                     :1;
            /*1.97 �������򾯸�ϵͳָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RSW_Data                               :3;
            /*1.98 �����ϵͳ ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t SAS_Error_Data_selfcheck               :1;
            /*1.98 �����ϵͳ ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SAS_Error_Data                         :3;
            /*1.98 �����ϵͳ ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t SAS_Limit_Data_selfcheck               :1;
            /*1.98 �����ϵͳ ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SAS_Limit_Data                         :3;
            /*1.100 ת��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Open_Data_selfcheck        :1;
            /*1.100 ת��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Open_Data                  :3;
            /*1.100 ת��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Work_Data_selfcheck        :1;
            /*1.100 ת��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Work_Data                  :3;
            /*1.100 ת��������ָʾ�� - ���� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Steer_Assit_Error_Data_selfcheck       :1;
            /*1.100 ת��������ָʾ�� - ���� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Steer_Assit_Error_Data                 :3;
            /*1.78/1.103/1.120/1.121 ������ʾϵͳָʾ��(PHEV) - ��ɫ - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Sound_Reminder_Red_Data_selfcheck      :1;
            /*1.78/1.103/1.120/1.121  ������ʾϵͳָʾ�� - ��ɫ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Sound_Reminder_Red_Data                :3;
            /*1.78/1.103/1.120/1.121  ������ʾϵͳָʾ�� - ��ɫ - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Sound_Reminder_Yellow_Data_selfcheck   :1;
            /*1.78/1.103/1.120/1.121  ������ʾϵͳָʾ�� - ��ɫ - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Sound_Reminder_Yellow_Data             :3;
            /*1.105 �ֲ�ʹ��*/
            uint32_t BatteryPack_Charge_Data_selfcheck      :1;
            /*1.105 �ֲ�ʹ��*/
            uint32_t BatteryPack_Charge_Data                :3;
            /*1.109 �����ж�ָʾ�� - ָʾ��״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Battery_Off_Data_selfcheck             :1;
            /*1.109 �����ж�ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Battery_Off_Data                       :3;
            /*1.112 ������ص����� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Low_Battery_Data_selfcheck             :1;
            /*1.112 ������ص����� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Low_Battery_Data                       :3;
            /*1.101 RSCA OFF ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t RSCA_Off_Data_selfcheck                :1;
            /*1.101 RSCA OFF ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t RSCA_Off_Data                          :3;
            /*1.113 2H/4H/4Lָʾ�� - 2H - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TT_2H_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4Lָʾ�� - 2H - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_2H_Indicator_Data                   :3;
            /*1.113 2H/4H/4Lָʾ�� - 4H - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TT_4H_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4Lָʾ�� - 4H - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_4H_Indicator_Data                   :3;
            /*1.113 2H/4H/4Lָʾ�� - 4L - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TT_4L_Indicator_Data_selfcheck         :1;
            /*1.113 2H/4H/4Lָʾ�� - 4L - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TT_4L_Indicator_Data                   :3;
            /*1.79~1.81 ��̤��ָʾ�� - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Single_Pedal_Data_selfcheck            :1;
            /*1.79~1.81 ��̤��ָʾ�� - ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Single_Pedal_Data                      :3;
            /*1.92 TSR ���ٱ�־ָʾ��-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_Speed_Limit_Data_selfcheck         :1;
            /*1.92 TSR ���ٱ�־ָʾ��-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_Speed_Limit_Data                   :3;
            /*1.92 TSR ���ٱ�־ָʾ��-���ٱ�־�ź�ֵ
            value: 0x00(����ʾ)  0x01~0x1E(����5,10,...,150)  other(�����ģ�����ʾ)*/
            uint32_t TSR_Speed_Limit_Data_Value             :8;
            /*1.76 �����ʱ���ָʾ��(PHEV/HEV)-�Լ�״̬
            1.108 ���ʽ���ָʾ��(EV) - �Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Power_Reduction_Data_selfcheck         :1;
            /*1.76 �����ʱ���ָʾ��(PHEV/HEV)-ָʾ��״̬
            1.108 ���ʽ���ָʾ��(EV) -ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Power_Reduction_Data                   :3;
            /*1.92 TSR ��·��־ָʾ��-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TSR_Road_Sign_Data_selfcheck           :1;
            /*1.92 TSR ��·��־ָʾ��-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TSR_Road_Sign_Data                     :3;
            /*1.92 TSR ��·��־ָʾ��-��·��־�ź�ֵ
            value: 0x00(����ʾ)  0x01~0x45(���ֽ�ͨ��־) other(�����ģ�����ʾ)*/
            uint32_t TSR_Road_Sign_Data_Value               :8;
            /*1.77 ������ص�����ָʾ��(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Low_Battery_White_Data_selfcheck       :1;
            /*1.77 ������ص�����ָʾ��(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Low_Battery_White_Data                 :3;
            /*1.132 �̲���������(I2V)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t GLOSA_Data_selfcheck                   :1;
            /*1.132 �̲���������(I2V)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t GLOSA_Data                             :3;
            /*1.132 �̲���������(I2V)-��������ֵ
            value: 0x00~0x96(��������0,1,2, ... , 150) other(����ʾ)*/
            uint32_t GLOSA_Data_Value                       :8;
            /*1.117 ��ˮ����ָʾ��(����)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t OilWaterSeparation_Data_selfcheck      :1;
            /*1.117 ��ˮ����ָʾ��(����)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t OilWaterSeparation_Data                :3;
            /*1.133 ����Ԥ��(I2V)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t SpeedLimitWrn_Data_selfcheck           :1;
            /*1.133 ����Ԥ��(I2V)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t SpeedLimitWrn_Data                     :3;
            /*1.133 ����Ԥ��(I2V)-���ٱ�־�ź�ֵ
            value: 0x00(����ʾ) 0x01~0x1E(����5,10, ... ,150) other(�����ģ�����ʾ)*/
            uint32_t SpeedLimitWrn_Data_Value               :8;
            /*1.119 ����ָʾ��(����)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t Adblue_Data_selfcheck                  :1;
            /*1.119 ����ָʾ��(����)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t Adblue_Data                            :3;
            /*1.134 ���ڱ���(I2V)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficSign_Data_selfcheck             :1;
            /*1.134 ���ڱ���(I2V)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficSign_Data                       :3;
            /*1.134 ���ڱ���(I2V)-��ͨ��־�ź�ֵ
            value: 0x00(����ʾ) 0x01~0x24(���ֽ�ͨ��־) other(�����ģ�����ʾ)*/
            uint32_t TrafficSign_Data_value                 :8;
            /*1.135 ��ͨ�źŵ�-������ǰ�����źŵ�(����)λ��
            value: 0x00(����ʾ) 0x01~0x07(��ʾ�����źŵ�λ�ã���Ӧ�źŵƴ��ڲ���ʾ) other(�����ģ�����ʾ)*/
            uint32_t TrafficLight_Position_Value            :4;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_R_Data               :3;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL1_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL1_G_Data               :3;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_R_Data               :3;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL2_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL2_G_Data               :3;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_R_Data               :3;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL3_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL3_G_Data               :3;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_R_Data               :3;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL4_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL4_G_Data               :3;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_R_Data               :3;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL5_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL5_G_Data               :3;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_R_Data               :3;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL6_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL6_G_Data               :3;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_R_Data               :3;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL7_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL7_G_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_R_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL8_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL8_G_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_R_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_R_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_Y_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_Y_Data               :3;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t TrafficLights_SL9_G_selfcheck          :1;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t TrafficLights_SL9_G_Data               :3;
            /*1.135 ��ͨ�źŵ�1(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL1_Time                 :16;
            /*1.135 ��ͨ�źŵ�2(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL2_Time                 :16;
            /*1.135 ��ͨ�źŵ�3(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL3_Time                 :16;
            /*1.135 ��ͨ�źŵ�4(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL4_Time                 :16;
            /*1.135 ��ͨ�źŵ�5(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL5_Time                 :16;
            /*1.135 ��ͨ�źŵ�6(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL6_Time                 :16;
            /*1.135 ��ͨ�źŵ�7(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL7_Time                 :16;
            /*1.135 ��ͨ�źŵ�8(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL8_Time                 :16;
            /*1.135 ��ͨ�źŵ�9(��ɫ)-�źŵƵ���ʱ����
            value: 0x00(����ʾ����ʱ) 0x001~0x999(����ʱ����) other(�����ģ�����ʾ)*/
            uint32_t TrafficLights_SL9_Time                 :16;
            /*�Լ첥��״̬
            value: 0x00(Status OK) 0x01(Status not OK)*/
            uint32_t SelfCheckReportStatus                  :1;
            /*1.137 ��������ϵͳ����ָʾ��(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t AirSus_Red_Data_selfcheck              :1;
            /*1.137 ��������ϵͳ����ָʾ��(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AirSus_Red_Data                        :3;
            /*1.137 ��������ϵͳ����ָʾ��(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t AirSus_Yellow_Data_selfcheck           :1;
            /*1.137 ��������ϵͳ����ָʾ��(��ɫ)--ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t AirSus_Yellow_Data                     :3;
            /*1.138 ��CALLָʾ��(��ɫ)--�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t MiaoCALLsts_Data_selfcheck             :1;
            /*1.138 ��CALLָʾ��(��ɫ)--ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t MiaoCALLsts_Data                       :3;
            /*1.140 ���������ָʾ��(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t CentDiffLock_Green_Data_selfcheck      :1;
            /*1.140 ���������ָʾ��(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CentDiffLock_Green_Data                :3;
            /*1.140 ���������ָʾ��(��ɫ)-�Լ�״̬
            self check: 0~no self check ;1~self check*/
            uint32_t CentDiffLock_Yellow_Data_selfcheck     :1;
            /*1.140 ���������ָʾ��(��ɫ)-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5:0.5hz  6~7 :reserve*/
            uint32_t CentDiffLock_Yellow_Data               :3;
            /*���벹��λ���¼�ʱ����ʹ��*/
            uint32_t Reserved                               :11;
        }s_u32Telltales_status_t;
    }u_TT_Moduleu32Telltales_status_t;
}IPC_M2S_ClusterAppAPPTT_Module_t;

/* Transmit function of sub message TT_Module */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPTT_Module_Transmit(IPC_M2S_ClusterAppAPPTT_Module_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: WN_Module */
typedef struct
{
    union
    {
        uint8_t u32Warning_status[150];
        struct
        {
            /*Warning Status��0~No Warning,1~Warning  Trigger
            1.147 Σ�գ�������Զ�복����*/
            uint16_t WN_DrvAwayCar                          :1;
            /*1.147 Σ�գ��밲ȫͣ��������Զ�복����*/
            uint16_t WN_DrvAwayCarStop                      :1;
            /*1.213 ESS����ת����ø������ܼ���*/
            uint16_t WN_IFCESSTrig                          :1;
            /*1.212 AES�Զ�����ת����ø������ܼ���*/
            uint16_t WN_IFCAESTrig                          :1;
            /*1.187 ������˵��Զ������ƶ�����*/
            uint16_t WN_AEBTrigP                            :1;
            /*1.186 ��Գ������Զ������ƶ�����*/
            uint16_t WN_AEBTrigV                            :1;
            /*1.188 ����·�ڸ����ƶ�����(��Գ���)*/
            uint16_t WN_IASTrigV                            :1;
            /*1.190 ǰ�ᴩ�����ƶ�����*/
            uint16_t WN_FCTABrakeActive                     :1;
            /*1.196 ���������ƶ�����*/
            uint16_t WN_RSDSRLBStart                        :1;
            /*1.198 ����ACC�ӹ�����---���ƶ�*/
            uint16_t WN_ACCTakeOverBrake                    :1;
            /*1.184 ǰ��ײԤ��---���ƶ�*/
            uint16_t WN_AEBFCWWarning                       :1;
            /*1.189 ǰ�ᴩ���򾯸湦��-���ƶ�*/
            uint16_t WN_FCTABrakePlease                     :1;
            /*1.210 �����շ�����1hz*/
            uint16_t WN_IFCHoldWheel_1Hz                    :1;
            /*1.210 �����շ�����2hz*/
            uint16_t WN_IFCHoldWheel_2Hz                    :1;
            /*1.210 �����շ�����3hz*/
            uint16_t WN_IFCHoldWheel_3Hz                    :1;
            /*1.210 �����շ�����4hz*/
            uint16_t WN_IFCHoldWheel_4Hz                    :1;
            /*1.185 �뱣�ְ�ȫ����*/
            uint16_t WN_AEBSafeDistance                     :1;
            /*1.205 ���ٹ�·����ϵͳ-���ַ�������*/
            uint16_t WN_ACCHWATakeOver                      :1;
            /*1.205 ���ٹ�·����ϵͳ-���ַ�������2Hz��ʾ��*/
            uint16_t WN_ACCHWATakeOver_2Hz                  :1;
            /*1.205 ���ٹ�·����ϵͳ-���ַ�������4Hz��ʾ��*/
            uint16_t WN_ACCHWATakeOver_4Hz                  :1;
            /*1.210 ��������ϵͳ�˳�����ӹܳ���*/
            uint16_t WN_IFCTakeOver                         :1;
            /*1.205 ���ٹ�·����ϵͳ-��Ŀ��ǰ��*/
            uint16_t WN_ACCHWATakeAtte                      :1;
            /*1.205 ���ٹ�·����ϵͳ-��Ŀ��ǰ��2hz*/
            uint16_t WN_ACCHWATakeAtte_2Hz                  :1;
            /*1.205 ���ٹ�·����ϵͳ-��Ŀ��ǰ��4hz*/
            uint16_t WN_ACCHWATakeAtte_4Hz                  :1;
            /*1.71  ��ѡ��P��(8AT)   No signal*/
            uint16_t WN_GearPSelect                         :1;
            /*1.17/1.18  ��ǰ�ſ�����*/
            uint16_t WN_LFDoorOpen                          :1;
            /*1.17/1.18  ��ǰ�ſ�����*/
            uint16_t WN_RFDoorOpen                          :1;
            /*1.17/1.18  ����ſ�����*/
            uint16_t WN_LRDoorOpen                          :1;
            /*1.17/1.18  �Һ��ſ�����*/
            uint16_t WN_RRDoorOpen                          :1;
            /*1.17/1.18  ���俪����*/
            uint16_t WN_TrunkOpen                           :1;
            /*1.17/1.18  �������ǿ�����*/
            uint16_t WN_HoodOpen                            :1;
            /*1.44  ��һ����ȫ��������ʾ*/
            uint16_t WN_FirRowLSeatBelt                     :1;
            /*1.44  ��һ���Ұ�ȫ��������ʾ*/
            uint16_t WN_FirRowRSeatBelt                     :1;
            /*1.44  �ڶ�����ȫ��������ʾ*/
            uint16_t WN_SecRowLSeatBelt                     :1;
            /*1.44  �ڶ����а�ȫ��������ʾ*/
            uint16_t WN_SecRowMSeatBelt                     :1;
            /*1.44  �ڶ����Ұ�ȫ��������ʾ*/
            uint16_t WN_SecRowRSeatBelt                     :1;
            /*1.12/1.13/1.14  �ƶ�ϵͳ����*/
            uint16_t WN_BrakeSysFault                       :1;
            /*1.160 ����ϵͳ���ع���   No signal*/
            uint16_t WN_DynSysFault                         :1;
            /*1.145 CCOĿ�공��һ��*/
            uint16_t WN_CCOTargetSpeed0                     :1;
            /*1.145 CCOĿ�공�ٶ���*/
            uint16_t WN_CCOTargetSpeed1                     :1;
            /*1.145 CCOĿ�공������*/
            uint16_t WN_CCOTargetSpeed2                     :1;
            /*1.145 CCOĿ�공���Ķ�*/
            uint16_t WN_CCOTargetSpeed3                     :1;
            /*1.145 CCOĿ�공�����*/
            uint16_t WN_CCOTargetSpeed4                     :1;
            /*1.145 CCOĿ�공������*/
            uint16_t WN_CCOTargetSpeed5                     :1;
            /*1.145 CCOĿ�공���߶�*/
            uint16_t WN_CCOTargetSpeed6                     :1;
            /*1.145 CCOĿ�공�ٰ˶�*/
            uint16_t WN_CCOTargetSpeed7                     :1;
            /*1.145 CCOĿ�공�پŶ�*/
            uint16_t WN_CCOTargetSpeed8                     :1;
            /*1.216 ����Ŀ�공��һ��*/
            uint16_t WN_SlowTargetSpeed0                    :1;
            /*1.216 ����Ŀ�공�ٶ���*/
            uint16_t WN_SlowTargetSpeed1                    :1;
            /*1.216 ����Ŀ�공������*/
            uint16_t WN_SlowTargetSpeed2                    :1;
            /*1.216 ����Ŀ�공���Ķ�*/
            uint16_t WN_SlowTargetSpeed3                    :1;
            /*1.216 ����Ŀ�공�����*/
            uint16_t WN_SlowTargetSpeed4                    :1;
            /*1.216 ����Ŀ�공������*/
            uint16_t WN_SlowTargetSpeed5                    :1;
            /*1.216 ����Ŀ�공���߶�*/
            uint16_t WN_SlowTargetSpeed6                    :1;
            /*1.216 ����Ŀ�공�ٰ˶�*/
            uint16_t WN_SlowTargetSpeed7                    :1;
            /*1.216 ����Ŀ�공�پŶ�*/
            uint16_t WN_SlowTargetSpeed8                    :1;
            /*1.213 ����ת����ø������ܹ���*/
            uint16_t WN_IFCESSFault                         :1;
            /*1.33  ��ǰ̥ѹ���ͱ���*/
            uint16_t WN_FLTirePressWarning                  :1;
            /*1.33  ��ǰ̥ѹ���ͱ���*/
            uint16_t WN_FRTirePressWarning                  :1;
            /*1.33  ���̥ѹ���ͱ���*/
            uint16_t WN_RLTirePressWarning                  :1;
            /*1.33  �Һ�̥ѹ���ͱ���*/
            uint16_t WN_RRTirePressWarning                  :1;
            /*1.34  ��ǰ̥�¹��߱���*/
            uint16_t WN_FLTireTempWarning                   :1;
            /*1.34  ��ǰ̥�¹��߱���*/
            uint16_t WN_FRTireTempWarning                   :1;
            /*1.34  ���̥�¹��߱���*/
            uint16_t WN_RLTireTempWarning                   :1;
            /*1.34  �Һ�̥�¹��߱���*/
            uint16_t WN_RRTireTempWarning                   :1;
            /*1.72  ����ϵͳ����*/
            uint16_t WN_4WDSystemFault                      :1;
            /*1.73  ����ϵͳ����*/
            uint16_t WN_4WDSystemHeat                       :1;
            /*1.100 ��϶���ϵͳ���ϣ��밲ȫͣ��*/
            uint16_t WN_HybSysFault_Stop                    :1;
            /*1.101 ����������ײ����϶���ϵͳ������*/
            uint16_t WN_HybSysUnavailable                   :1;
            /*1.186 ���ڳ�� TBD*/
            uint16_t WN_Charging                            :1;
            /*1.186 ԤԼ��� TBD*/
            uint16_t WN_ChargeWait                          :1;
            /*1.186 �������� TBD*/
            uint16_t WN_ChargeComplete                      :1;
            /*1.186 �����ֹͣ TBD*/
            uint16_t WN_ChargeStop                          :1;
            /*1.102 �������ϵͳ���ϣ��밲ȫͣ��*/
            uint16_t WN_DynBattSysFault_Stop                :1;
            /*1.102 �������ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_DynBattSysFault_Repair              :1;
            /*1.212 �Զ�����ת����ù��ܲ�����*/
            uint16_t WN_IFCAESFault                         :1;
            /*1.45  ����������,�밲ȫͣ��*/
            uint16_t WN_TransWarnStopCar                    :1;
            /*1.68  ����ϵͳ����  (8AT)   No signal*/
            uint16_t WN_PowerSysFault                       :1;
            /*1.48/1.49/1.50/1.51  ����������*/
            uint16_t WN_TransFault                          :1;
            /*1.52/1.53  ������δ�ܳɹ�����P��*/
            uint16_t WN_TransPutInPFailed                   :1;
            /*1.7   ����ѹ������*/
            uint16_t WN_LowOilPressure                      :1;
            /*1.2   ������ˮ�¹���*/
            uint16_t WN_EngWaterTempHigh                    :1;
            /*1.45/1.46/1.47  ����������*/
            uint16_t WN_TransWarning                        :1;
            /*1.99  ����ϵͳ���� �뼰ʱ��4S��ά��*/
            uint16_t WN_DrvSysFault_Repair                  :1;
            /*1.96  ��϶���ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_HybSysFault_Repair                  :1;
            /*1.93  ��ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_StartingSysFault                    :1;
            /*1.97  ��϶���ϵͳ������ʱ���ޣ���С�ļ�ʻ*/
            uint16_t WN_HybSysLimited                       :1;
            /*1.98  ��������ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_RecoverySysFault                    :1;
            /*1.91  �������ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_ChargerFault                        :1;
            /*1.92  ���ϵͳ���ϣ����ֹͣ*/
            uint16_t WN_ChargeSysFault                      :1;
            /*1.86  �����¶ȹ��ߣ����ֹͣ*/
            uint16_t WN_ChargerTempHigh                     :1;
            /*1.87  ��������¶ȹ��ߣ����ֹͣ*/
            uint16_t WN_DynBattTempHigh                     :1;
            /*1.89  ����������ʽ���*/
            uint16_t WN_ChargerPWReduced                    :1;
            /*1.194 ǰ��ᴩ�������ܲ�����*/
            uint16_t WN_FCTAUnavai                          :1;
            /*1.63  ��������N���������޷���ֹ*/
            uint16_t WN_LockFailureN                        :1;
            /*1.66  ��ע���������N��(8AT)*/
            uint16_t WN_NoticeGearN                         :1;
            /*1.21/1.22  �ƹ�δ����ʾ*/
            uint16_t WN_PositionLampOn                      :1;
            /*1.195 �ϳ�ģʽ �����ϵͳͣ��*/
            uint16_t WN_RSDSTrailer                         :1;
            /*1.192 �ϳ�ģʽ ǰ����ϵͳͣ��*/
            uint16_t WN_AEBPSAUnavai                        :1;
            /*1.204 ���ٹ�·����ϵͳ-ǰ����������������뼰ʱ�ӹܳ���*/
            uint16_t WN_ACCHWACrossTunnel                   :1;
            /*1.204 ���ٹ�·����ϵͳ-ǰ�����ڷֲ�·�ڣ�����ʱ�ӹܳ���*/
            uint16_t WN_ACCHWABranchRoad                    :1;
            /*1.90  ���װ�����Ӳ���ȷ�����ֹͣ*/
            uint16_t WN_ChargeDevConnectErr                 :1;
            /*1.88  ��������¶ȹ��ͣ����ֹͣ*/
            uint16_t WN_DynBattTempLow                      :1;
            /*1.85  �������빦�ʲ��㣬���ֹͣ*/
            uint16_t WN_ChargePortWarning                   :1;
            /*1.209 ����ǰ��ϵͳ�������궨��*/
            uint16_t WN_IFCSCalibrating                     :1;
            /*1.48/1.108 ������֤ʧ��*/
            uint16_t WN_TransAuthenFailed                   :1;
            /*1.48/1.49/1.50  ��������������*/
            uint16_t WN_TransLimited                        :1;
            /*1.52  �������޷����P��*/
            uint16_t WN_TransReleasePFailed                 :1;
            /*1.43  ����ת��������ʧ�ܣ���ת��������*/
            uint16_t WN_ElecSteerUnlockFail                 :1;
            /*1.148 ��������ˮ�ù��ϣ��뾡��ά��*/
            uint16_t WN_EngPumpFault                        :1;
            /*1.165 ������դ����*/
            uint16_t WN_AGSFault                            :1;
            /*1.81  ��Ͽ���/�ŵ�װ��*/
            uint16_t WN_ChargeDevDisconnect                 :1;
            /*1.90  �����ӳ��װ��*/
            uint16_t WN_ChargeDevConnect                    :1;
            /*1.79  ������ص����ͣ��뼰ʱ���*/
            uint16_t WN_DynBattLow                          :1;
            /*1.82  �뽫��λ����P��*/
            uint16_t WN_GearChngP                           :1;
            /*1.69  P��ʱ�����農ֹ (8AT)*/
            uint16_t WN_GearPNeedStop                       :1;
            /*1.131/1.132/1.133 ǰ�յƹ���*/
            uint16_t WN_HighBeamSysFault                    :1;
            /*1.70  ���ٽϸ߲��ʺϹ���P��(8AT)*/
            uint16_t WN_GearPNotSuitable                    :1;
            /*1.64  ������D������ģʽ(8AT) */
            uint16_t WN_LimpModeGearD                       :1;
            /*1.65  ������P������ģʽ(8AT) */
            uint16_t WN_LimpModeGearP                       :1;
            /*1.149 ���������ϵ磬��ֹ����   No signal*/
            uint16_t WN_ReadyNoRefuel                       :1;
            /*1.178 ����׼����*/
            uint16_t WN_FuelPrepare                         :1;
            /*1.111 �����𲽼���*/
            uint16_t WN_RaceLaunchActive                    :1;
            /*1.112 ����ģʽ����*/
            uint16_t WN_RaceModeActive                      :1;
            /*1.111 ��ʱ����*/
            uint16_t WN_RaceLaunchTimeout                   :1;
            /*1.149 ���װ�������ӣ���ֹ����   No signal*/
            uint16_t WN_ChargingNoRefuel                    :1;
            /*1.110 ����ϵͳ���ϣ���ά��*/
            uint16_t WN_FuelTankSysFault                    :1;
            /*1.141 �����δ�ر�*/
            uint16_t WN_FuelTankCapOn                       :1;
            /*1.118 ������������������*/
            uint16_t WN_GPFRegenerating                     :1;
            /*1.118 ������������Ҫ����*/
            uint16_t WN_GPFRegenerate                       :1;
            /*1.99  ����ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_RearAxleSysFault                    :1;
            /*1.94  ǰ��ϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_FrontAxleSysFault                   :1;
            /*1.107 ����ͬʱ���¼�����ɲ��̤��*/
            uint16_t WN_DoNotStepAcAndBr                    :1;
            /*1.67  ���ӻ��������� (8AT)   No signal*/
            uint16_t WN_ElecShifterFault                    :1;
            /*1.8   ����ģʽ*/
            uint16_t WN_StatBattLowTranMode                 :1;
            /*1.8   12V��Դϵͳ���ϣ����ʹ��ܹر� */
            uint16_t WN_StatBattLowComfortOff               :1;
            /*1.151 12V��Դϵͳ���ϣ��밲ȫͣ��*/
            uint16_t WN_12VFaultStop                        :1;
            /*1.151 12V��Դϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_12VFaultRepair                      :1;
            /*1.8   �������Ĺ��࣬����ʡ��ģʽ*/
            uint16_t WN_StatBattLowSavingMode               :1;
            /*1.8   12V���ص����ͣ�����������*/
            uint16_t WN_StatBattLowStartUp                  :1;
            /*1.139 ģʽ�л�ʧ�ܣ���Ϩ������*/
            uint16_t WN_ModeSwitchFailed                    :1;
            /*1.150 ���ڼ��ͣ���ֹ���*/
            uint16_t WN_RefuelingNoCharge                   :1;
            /*1.56  �������ɲ�������½�����*/
            uint16_t WN_ShiftGearBrakeAndKey                :1;
            /*1.59  �������ɲ��*/
            uint16_t WN_ShiftGearStepBrake                  :1;
            /*1.56  �����밴�½�����   No signal*/
            uint16_t WN_ShiftGearPressKey                   :1;
            /*1.60/1.61 ���ٹ����޷��л���λ*/
            uint16_t WN_ShiftNotAllowed                     :1;
            /*1.60  ���ڳ�����ֹʱ����P��*/
            uint16_t WN_ShiftPStop                          :1;
            /*TBD   ��ע����Ϣ��ȡ��DMSģ��*/
            uint16_t WN_DMSTakeRest_1                       :1;
            /*TBD   ��ע����Ϣ��ȡ��DMSģ��*/
            uint16_t WN_DMSTakeRest_2                       :1;
            /*TBD   ��ע����Ϣ��ȡ��DMSģ��*/
            uint16_t WN_DMSTakeRest_3                       :1;
            /*TBD   ��ר�ļ�ʻ*/
            uint16_t WN_DMSTakeAttention                    :1;
            /*1.166 ����ʽ��ȫ������   No signal*/
            uint16_t WN_PPMIFault                           :1;
            /*1.238 ��������ʽ��ȫ������*/
            uint16_t WN_SidePPMIErr                         :1;
            /*1.95  BSGϵͳ���ϣ��뼰ʱ��4S��ά��*/
            uint16_t WN_BSGSysFault                         :1;
            /*1.234 ��ԭ�ؿ��������Խ�*/
            uint16_t WN_PlsStartSelfClean                   :1;
            /*1.234 ����������������*/
            uint16_t WN_PlsStartCarSlowly                   :1;
            /*1.234 ���������������Խ�*/
            uint16_t WN_DPFCleaning                         :1;
            /*1.234 �Խ���ɸ�л�ȴ�*/
            uint16_t WN_SelfCleanComplete                   :1;
            /*1.83  �뽫��λ����P����N��   No signal*/
            uint16_t WN_GearChngPN                          :1;
            /*1.241 ������δ�ر�*/
            uint16_t WN_RainDoorOpen                        :1;
            /*1.152 ��������¶ȵͣ����ǹ����*/
            uint16_t WN_HeatingPlugIn                       :1;
            /*1.233 ����Һλ�ͣ����ע*/
            uint16_t WN_UreaLow                             :1;
            /*1.233 ����Һλ���ͣ����ע*/
            uint16_t WN_UreaVeryLow                         :1;
            /*1.233 ���ع޿գ���ֹ�´�����*/
            uint16_t WN_UreaTankEmpty                       :1;
            /*1.233 ���ز��ϸ�����*/
            uint16_t WN_UreaUnqualifyPlsCheck               :1;
            /*1.233 ���ز��ϸ� ��ʻ����50km*/
            uint16_t WN_UreaUnqualifyOver50km               :1;
            /*1.233 ���������ж� ����*/
            uint16_t WN_UreaFillStopPlsReFill               :1;
            /*1.233 ���������ж� ��ʻ����50km*/
            uint16_t WN_UreaFillStopOver50km                :1;
            /*1.233 ����ϵͳ��ֹ����������*/
            uint16_t WN_UreaSysDisableEng                   :1;
            /*1.233 ����ϵͳ���ϣ�����վ���*/
            uint16_t WN_UreaSysErrPlsCheck                  :1;
            /*1.233 ����ϵͳ���ϣ���ʻ����50km*/
            uint16_t WN_UreaSysErrOver50km                  :1;
            /*1.233 ����ϵͳ���ϣ���ֹ�´�����*/
            uint16_t WN_UreaSysErrRestartErr                :1;
            /*1.109 ��������Ҫ����, EVģʽ������*/
            uint16_t WN_DM_ENS_EV                           :1;
            /*1.235 ǰ�ֻ������*/
            uint16_t WN_FrontTireAlignFinish                :1;
            /*1.235 ǰ��δ���� ���Ҵ�����*/
            uint16_t WN_FrontTireTurnRight                  :1;
            /*1.235 ǰ��δ���� ���������*/
            uint16_t WN_FrontTireTurnLeft                   :1;
            /*1.243 ���ڳ�������״̬�¿�������������ɱ������*/
            uint16_t WN_RayAntiVirusWarn                    :1;
            /*1.169 Σ�� ��ר�ļ�ʻ*/
            uint16_t WN_DrvConcentrate                      :1;
            /*1.170 Σ�� ����ƣ�ͼ�ʻ*/
            uint16_t WN_DrvDrowsy                           :1;
            /*1.152 ����¶ȵͣ������޷���ʻ*/
            uint16_t WN_CantDriveBatt                       :1;
            /*1.167 ���ӳɹ������ڷŵ���+V2L   No signal*/
            uint16_t WN_DischargingV2L                      :1;
            /*1.167 ���ӳɹ������ڷŵ���+V2V   No signal*/
            uint16_t WN_DischargingV2V                      :1;
            /*1.182 ���������Ǳ�VINδƥ��*/
            uint16_t WN_EngVinMismatch                      :1;
            /*1.140 ԽҰר��ģʽ*/
            uint16_t WN_ORExperMode                         :1;
            /*1.214 �������Ԥ����*/
            uint16_t WN_ChargeHeating                       :1;
            /*1.228 ����ϵͳ���ޣ����л�Ϊ�綯ģʽ*/
            uint16_t WN_HSMLimitPlsSwiEV                    :1;
            /*1.228 ����ϵͳ���ϣ����л�Ϊ�綯ģʽ����ȫͣ��*/
            uint16_t WN_HSMErrPlsSwiEVAndStop               :1;
            /*1.228 ����ϵͳ���ϣ��밲ȫͣ��*/
            uint16_t WN_HSMErrStop                          :1;
            /*1.229 ȼ�ϵ��ϵͳ���ϣ��뵽4S��ά��*/
            uint16_t WN_BattSysErrPlsFix                    :1;
            /*1.229 ȼ�ϵ��ϵͳ���ϣ��뵽4S��ά��*/
            uint16_t WN_BattSysErrPlsFix_1                  :1;
            /*1.230 ����ϵͳ���ϣ��뵽4S��ά��*/
            uint16_t WN_HSErrPlsFix                         :1;
            /*1.230 ����й©���뵽4S��ά��*/
            uint16_t WN_HSLeakPlsFix                        :1;
            /*1.231 ����й©�����л�Ϊ�綯ģʽ*/
            uint16_t WN_HSLeakPlsSwiEV                      :1;
            /*1.231 ����й©�����л�Ϊ�綯ģʽ����ȫͣ��*/
            uint16_t WN_HSLeakPlsSwiEVStop                  :1;
            /*1.231 ����й©���밲ȫͣ������Զ�복��*/
            uint16_t WN_HSLeakStop                          :1;
            /*1.232 ��ȴҺ����Ũ�ȹ��ߣ��뵽4S��ά��*/
            uint16_t WN_DeionizerErrPlsFix                  :1;
            /*1.144 ������ֻ�*/
            uint16_t WN_WPCTakePhone                        :1;
            /*1.217 ̧ͷ��ʾ����*/
            uint16_t WN_ARHUDFault                          :1;
            /*1.217 ̧ͷ��ʾ���±����޷���ʾ*/
            uint16_t WN_ARHUDOverheat                       :1;
            /*1.111 ���������𲽼���*/
            uint16_t WN_SRaceLaunchActive                   :1;
            /*1.111 ������ؿ��ù��ʵͣ��������䲻���ã� ��ͨ���伤��*/
            uint16_t WN_BattLowSRaceLaunUnAvail             :1;
            /*1.111 �������¶ȸߣ��������䲻���ã���ͨ���伤��*/
            uint16_t WN_TransHeatSLaunchUnAvail             :1;
            /*1.111 ��������ʹ�ô����ﵽ���ޣ���ͨ���伤��*/
            uint16_t WN_SRaceLaunchOverLimit                :1;
            /*1.152 ��������¶ȹ��ͣ������޷�����*/
            uint16_t WN_BattTempLowCantStart                :1;
            /*1.221 ��������¶ȵͣ���������*/
            uint16_t WN_BattTempLowPowerDown                :1;
            /*1.221 ��������¶ȸߣ���������*/
            uint16_t WN_BattTempHighPowerDown               :1;
            /*1.52 ������ƶ�̤�������EPB����P����ѧϰ��ɺ��ɿ�*/
            uint16_t WN_PlsPrsBrktoWait                     :1;
            /*1.52 P����ѧϰδ��ɣ�����ѧϰ��ɺ󻻵�*/
            uint16_t WN_SelfLearnNotComplete                :1;
            /*1.52 P����ѧϰ��ɣ����ɿ��ƶ�̤��*/
            uint16_t WN_LearnSuccessPlsRelBrk               :1;
            /*1.109 ������ؿ��ù��ʵͣ�EVģʽ������*/
            uint16_t WN_PowerLowEVUnvil                     :1;
            /*1.210 ����ƫ�룬����Ʒ�����*/
            uint16_t WN_PlsCtrlWheel                        :1;
            /*1.109 ����ϵͳ���ϣ�����ģʽ������*/
            uint16_t WN_RearAxSysErr4WDUnvil                :1;
            /*1.41  PEPS��Դ�̵�������*/
            uint16_t WN_PEPSPowerFault                      :1;
            /*1.16  ����һ������*/
            uint16_t WN_OverSpeedLevel_1                    :1;
            /*1.16  ���ٶ�������*/
            uint16_t WN_OverSpeedLevel_2                    :1;
            /*1.62  ���پ����ֶ��ɵ�*/
            uint16_t WN_OverSpeedSetting                    :1;
            /*1.25/1.26  ���յƹ���*/
            uint16_t WN_LicPlateLampFault                   :1;
            /*1.27/1.28  �����ƹ���*/
            uint16_t WN_RvsLampFault                        :1;
            /*1.29  ��λ�ƹ���*/
            uint16_t WN_RearPosnLampFault                   :1;
            /*1.120 ���⸨��Զ���Դ����*/
            uint16_t WN_LasHdLightFault                     :1;
            /*1.208 ����ǰ��ϵͳ������̽������*/
            uint16_t WN_IFCSDectectLimited                  :1;
            /*1.191 ǰ����ϵͳ������̽������*/
            uint16_t WN_ACCSensorDetectLimited              :1;
            /*1.193 ǰ���״ﴫ����̽������*/
            uint16_t WN_FCTSDectectLimit                    :1;
            /*1.207 �����������ֹ�������*/
            uint16_t WN_IFCLKAFunLimited                    :1;
            /*1.104 ͨ�Ź��ϣ���С�ļ�ʻ  ��ɾ��*/
            uint16_t WN_CommunicationFault                  :1;
            /*1.206 ����������ܹ���*/
            uint16_t WN_ACCHWAFuncFault                     :1;
            /*1.197 �󷽳������ٹ���*/
            uint16_t WN_RSDSRCWWarning                      :1;
            /*1.103 ������ʾϵͳ����*/
            uint16_t WN_BeepSysFault                        :1;
            /*1.23/1.24  �ƶ��ƹ���*/
            uint16_t WN_BrakeLampFault                      :1;
            /*1.19/1.20  ����ƹ���*/
            uint16_t WN_RearFogLampFault                    :1;
            /*1.31  �������ߴ���������*/
            uint16_t WN_RainLightFault                      :1;
            /*1.129 AFSϵͳ����*/
            uint16_t WN_AFSSystemFault                      :1;
            /*1.201 �ǻ�Ѳ�����ܲ�����*/
            uint16_t WN_ACCUnavailable                      :1;
            /*1.199 ����ӦѲ�����ܲ�����*/
            uint16_t WN_ACCCruiseFunFault                   :1;
            /*1.183 ESP�ر� ǰ����ϵͳ��ͣ��*/
            uint16_t WN_AEBESPOff                           :1;
            /*1.211 ��ͨ��־��Ϣ���ܹ���*/
            uint16_t WN_TrafficSignFault                    :1;
            /*1.8   12V���ص����ͣ����ʹ��ܽ�����*/
            uint16_t WN_StatBattLowPwrReduce                :1;
            /*1.127 ALSϵͳ����*/
            uint16_t WN_ALSSysFault                         :1;
            /*TBD   ԽҰѲ����������*/
            uint16_t WN_ORCruiseLimited                     :1;
            /*TBD   ת������������*/
            uint16_t WN_TurnAssistLimited                   :1;
            /*1.9  ���»�����������*/
            uint16_t WN_HDCLimited                          :1;
            /*1.10  �Զ�פ����������*/
            uint16_t WN_AutoholdLimited                     :1;
            /*1.143 ��ȷ���ֻ���������Ƿ����������ƫ��*/
            uint16_t WN_WPCChargeZone                       :1;
            /*1.124 ���ش�ƹ���   No signal*/
            uint16_t WN_PHLFault                            :1;
            /*1.125 ���ش������ͷ����   No signal*/
            uint16_t WN_PHLCameraFault                      :1;
            /*1.136 4Lģʽ���������  No signal*/
            uint16_t WN_4LModeSlow                          :1;
            /*1.146 ����ϵͳ���ܽ���  No signal*/
            uint16_t WN_4WDSystemDemotion                   :1;
            /*1.136 4Lģʽ���������  No signal*/
            uint16_t WN_4HModeSlow                          :1;
            /*1.154 VSG����  No signal*/
            uint16_t WN_VSGFault                            :1;
            /*1.155 �����������ж�  No signal*/
            uint16_t WN_DynBattCutOff                       :1;
            /*1.156 �������  No signal*/
            uint16_t WN_ElecMachiFault                      :1;
            /*1.157 DC/DC����  No signal*/
            uint16_t WN_DCDCFault                           :1;
            /*1.159 E-Park����  No signal*/
            uint16_t WN_EParkFault                          :1;
            /*1.160 ���Ƴ����ǹ*/
            uint16_t WN_RemoveChargeGun                     :1;
            /*1.160 ���Ƴ���ŵ�ǹ*/
            uint16_t WN_RemoveDischrgGun                    :1;
            /*1.160 ����������*/
            uint16_t WN_ShifterFault                        :1;
            /*1.62  ���ٹ����޷��л���λ��EV��*/
            uint16_t WN_ShiftNotAllowEV                     :1;
            /*1.160 P������*/
            uint16_t WN_ShiftPFault                         :1;
            /*1.160 ���ڳ�����ֹʱ����P����EV��  No signal*/
            uint16_t WN_ShiftPStopEV                        :1;
            /*1.160 ����������޷�����  No signal*/
            uint16_t WN_ChargingShift                       :1;
            /*1.160 ����ƶ��г�P��  No signal*/
            uint16_t WN_StepBrakeOutP                       :1;
            /*1.160 ����ƶ��г�N��  No signal*/
            uint16_t WN_StepBrakeOutN                       :1;
            /*1.160 С���ع���  No signal*/
            uint16_t WN_LVBattFault                         :1;
            /*1.160 ������ص����ͣ��˶�ģʽ������  No signal*/
            uint16_t WN_HVBattSport                         :1;
            /*1.160 ������ص����ͣ��յ���������  No signal*/
            uint16_t WN_HVBattAir                           :1;
            /*1.160 �ѵ�ECOģʽ����ֵ  No signal*/
            uint16_t WN_ECOValue                            :1;
            /*1.160 �����ߣ���̤�幦������  No signal*/
            uint16_t WN_PedalLimit                          :1;
            /*1.160 �޷�ʶ���ذ�������  No signal*/
            uint16_t WN_UnidentifyBatt                      :1;
            /*1.161 �ȹ����ŷ��������ϣ��뾡�����*/
            uint16_t WN_HeatManagerFault                    :1;
            /*1.122 ��Զ����Զ�����  No signal*/
            uint16_t WN_FarBeamFault                        :1;
            /*1.158 ������ع���  No signal*/
            uint16_t WN_DynBattFault                        :1;
            /*1.179 �������������ϵͳ���õ��*/
            uint16_t WN_TboxErr                             :1;
            /*1.78  ������ص�����*/
            uint16_t WN_DynBattLowEV                        :1;
            /*1.237 �������Ṧ������*/
            uint16_t WN_SuspensionLimit                     :1;
            /*1.105/1.106 ���ϵ�ɹҵ���ʻ  No signal*/
            uint16_t WN_PowerOnGearDrive                    :1;
            /*1.178 ���Կ�ʼ����*/
            uint16_t WN_FuelStart                           :1;
            /*1.36  ��ȷ��Կ���Ƿ��ڳ���*/
            uint16_t WN_KeyInCarOrNot                       :1;
            /*1.203 ���ﲦ�����أ�ȷ�ϵ�������*/
            uint16_t WN_ACCISLCruiseSpeed                   :1;
            /*1.37 ����ɲ��+һ������ ���P����N��*/
            uint16_t WN_StepBrakeStartGearPN                :1;
            /*1.38 �������+ һ������ ��ҿյ�*/
            uint16_t WN_StepClutchStartGearNull             :1;
            /*1.40 ����ɲ��+һ������ ���N�� */
            uint16_t WN_StepBrakeStartGearNull              :1;
            /*1.203 �ٶȹ�������������*/
            uint16_t WN_ACCISLSlowDoWN                      :1;
            /*1.3/1.4/1.5   ����Ѳ��*/
            uint16_t WN_TargetCruiseSpeed                   :1;
            /*1.121 ���⸨��Զ�⿪��*/
            uint16_t WN_LasHdLightOn                        :1;
            /*1.121 ���⸨��Զ��ر�*/
            uint16_t WN_LasHdLightOff                       :1;
            /*1.30  פ�����ѿ���*/
            uint16_t WN_ParkLampOn                          :1;
            /*1.32  ƣ�ͼ�ʻԤ��*/
            uint16_t WN_DrowsyDrvWarning                    :1;
            /*1.32  ƣ�ͼ�ʻԤ��1hz*/
            uint16_t WN_DrowsyDrvWarning_1Hz                :1;
            /*1.35  �����Կ����ʾ*/
            uint16_t WN_TakeTheKeyTip                       :1;
            /*1.74  �����ȼ��*/
            uint16_t WN_FuelLowWarn                         :1;
            /*1.130 AFS��ʱ��ʻģʽ  No signal*/
            uint16_t WN_AFSDrivingMode                      :1;
            /*1.128 ALS��ʱ��ʻģʽ  No signal*/
            uint16_t WN_ALSDrivingSide                      :1;
            /*TBD   �뱣������ ��ɾ��*/
            uint16_t WN_MaintainPlease                      :1;
            /*TBD   ���´α���XXkm ��ɾ��*/
            uint16_t WN_MaintainNext                        :1;
            /*1.77  ���ͷŵ���פ��*/
            uint16_t WN_ReleaseElecParkCCO                  :1;
            /*1.77  �����*/
            uint16_t WN_PleaseSlowDoWN                      :1;
            /*1.173 Ϊ���4Lģʽ�л�����ͣ��  No signal*/
            uint16_t WN_4LModeStop                          :1;
            /*1.174 ���N��  No signal*/
            uint16_t WN_PleaseGearN                         :1;
            /*1.175 ���˳�4Lģʽ  No signal*/
            uint16_t WN_4LModeEx                            :1;
            /*1.177 ��ѡ��4L  No signal*/
            uint16_t WN_4LModeSelect                        :1;
            /*1.177 ��ѡ��4H  No signal*/
            uint16_t WN_4HModeSelect                        :1;
            /*1.176 �����4Lģʽ  No signal*/
            uint16_t WN_4LModeEn                            :1;
            /*1.75 �뼤��ԽҰѲ������  No signal*/
            uint16_t WN_ORCruiseActive                      :1;
            /*1.113 ��׼ģʽ*/
            uint16_t WN_DM_B30_Standard                     :1;
            /*1.113 �˶�ģʽ*/
            uint16_t WN_DM_B30_Sport                        :1;
            /*1.113 ѩ��ģʽ*/
            uint16_t WN_DM_B30_Snow                         :1;
            /*1.113 ���ģʽ*/
            uint16_t WN_DM_B30_Muddy                        :1;
            /*1.113 ɳ��ģʽ*/
            uint16_t WN_DM_B30_Sand                         :1;
            /*1.113 4Lģʽ*/
            uint16_t WN_DM_B30_4L                           :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_B30_ECO                          :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_B30_IMC                          :1;
            /*1.113 �����˶�ģʽ*/
            uint16_t WN_DM_B30_SportPlus                    :1;
            /*1.113 ԽҰģʽ*/
            uint16_t WN_DM_B30_OffRoad                      :1;
            /*1.113 ר��ģʽ*/
            uint16_t WN_DM_B30_Expert                       :1;
            /*1.113 ��ʯģʽ*/
            uint16_t WN_DM_B30_Rock                         :1;
            /*1.113 ��͹·ģʽ*/
            uint16_t WN_DM_B30_Pothole                      :1;
            /*1.113 ��ɰģʽ*/
            uint16_t WN_DM_B30_MuddySand                    :1;
            /*1.113 ɽ��ģʽ*/
            uint16_t WN_DM_B30_Mountain                     :1;
            /*1.113 ��׼ģʽ��ѡ��*/
            uint16_t WN_DM_StandardSelect                   :1;
            /*1.113 �˶�ģʽ��ѡ��*/
            uint16_t WN_DM_SportSelect                      :1;
            /*1.113 �����˶�ģʽ��ѡ��*/
            uint16_t WN_DM_SportPlusSelect                  :1;
            /*1.113 ѩ��ģʽ��ѡ��*/
            uint16_t WN_DM_SnowSelect                       :1;
            /*1.113 ���ģʽ��ѡ��*/
            uint16_t WN_DM_MuddySelect                      :1;
            /*1.113 ɳ��ģʽ��ѡ��*/
            uint16_t WN_DM_SandSelect                       :1;
            /*1.113 ����ģʽ��ѡ��*/
            uint16_t WN_DM_EcoSelect                        :1;
            /*1.113 ��ʯģʽ��ѡ��*/
            uint16_t WN_DM_RockSelect                       :1;
            /*1.113 ��͹·ģʽ��ѡ��*/
            uint16_t WN_DM_PotholeSelect                    :1;
            /*1.113 ��ɳģʽ��ѡ��*/
            uint16_t WN_DM_MuddySandSelect                  :1;
            /*1.113 ɽ��ģʽ��ѡ��*/
            uint16_t WN_DM_MountainSelect                   :1;
            /*1.113 ר��ģʽ��ѡ��*/
            uint16_t WN_DM_ExpertSelect                     :1;
            /*1.113 ԽҰģʽ��ѡ��*/
            uint16_t WN_DM_OffRoadSelect                    :1;
            /*1.113 4Lģʽ��ѡ��*/
            uint16_t WN_DM_4LSelect                         :1;
            /*1.113 ����ģʽ��ѡ��*/
            uint16_t WN_DM_IMCSelect                        :1;
            /*1.113 ��׼ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_StandardDPR                      :1;
            /*1.113 �˶�ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_SportDPR                         :1;
            /*1.113 ����ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_EcoDPR                           :1;
            /*1.113 ѩ��ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_SnowDPR                          :1;
            /*1.113 ���ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_MuddyDPR                         :1;
            /*1.113 ɳ��ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_SandDPR                          :1;
            /*1.113 ��͹·ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_PotholeDPR                       :1;
            /*1.113 ɽ��ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_MountainDPR                      :1;
            /*1.113 ��ʯģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_RockDPR                          :1;
            /*1.113 ԽҰģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_OffRoadDPR                       :1;
            /*1.113 �����˶�ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_SportPlusDPR                     :1;
            /*1.113 ר��ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_ExpertDPR                        :1;
            /*1.113 ��ɳģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_MuddySandDPR                     :1;
            /*1.113 ����ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_IMCDPR                           :1;
            /*1.113 4Lģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_4LDPR                            :1;
            /*1.134/1.135 ESOF ����ģʽ Ҫ����4Lģʽ����ͣ����N ��  No signal*/
            uint16_t WN_4LEnGearN                           :1;
            /*1.134/1.135 ESOF ����ģʽ ����4Lģʽ�У��޷�����D/R/P ��  No signal*/
            uint16_t WN_4LEnGearDRP                         :1;
            /*1.134/1.135 ESOF ����ģʽ Ҫ�˳�4Lģʽ����ͣ����N ��  No signal*/
            uint16_t WN_4LExGearN                           :1;
            /*1.134/1.135 ESOF ����ģʽ �˳�4Lģʽ�У��޷�����D/R/P ��  No signal*/
            uint16_t WN_4LExGearDRP                         :1;
            /*1.134/1.135 ESOF ����ģʽ Ҫ����4Lģʽ����ͣ�����������  No signal*/
            uint16_t WN_4LEnClutchStep                      :1;
            /*1.134/1.135 ESOF ����ģʽ ����4Lģʽ�У������ɿ����̤��  No signal*/
            uint16_t WN_4LEnClutchRele                      :1;
            /*1.134/1.135 ESOF ����ģʽ Ҫ�˳�4Lģʽ����ͣ�����������  No signal*/
            uint16_t WN_4LExClutchStep                      :1;
            /*1.134/1.135 ESOF ����ģʽ �˳�4Lģʽ�У������ɿ����̤��  No signal*/
            uint16_t WN_4LExClutchRele                      :1;
            /*1.113 ��׼ģʽ*/
            uint16_t WN_DM_StandardSecond                   :1;
            /*1.113 �˶�ģʽ*/
            uint16_t WN_DM_SportSecond                      :1;
            /*1.113 �����˶�ģʽ*/
            uint16_t WN_DM_SportPlusSecond                  :1;
            /*1.113 ѩ��ģʽ*/
            uint16_t WN_DM_SnowSecond                       :1;
            /*1.113 ���ģʽ*/
            uint16_t WN_DM_MuddySecond                      :1;
            /*1.113 ɳ��ģʽ*/
            uint16_t WN_DM_SandSecond                       :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_ECOSecond                        :1;
            /*1.113 4Lģʽ*/
            uint16_t WN_DM_4LSecond                         :1;
            /*1.113 ��͹·ģʽ*/
            uint16_t WN_DM_PotholeSecond                    :1;
            /*1.113 ɽ��ģʽ*/
            uint16_t WN_DM_MountainSecond                   :1;
            /*1.113 ��ʯģʽ*/
            uint16_t WN_DM_RockSecond                       :1;
            /*1.113 ԽҰģʽ*/
            uint16_t WN_DM_OffRoadSecond                    :1;
            /*1.113 ר��ģʽ*/
            uint16_t WN_DM_ExpertSecond                     :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_IMCSecond                        :1;
            /*1.113 ��ɰģʽ*/
            uint16_t WN_DM_MuddySandSecond                  :1;
            /*1.115 ��׼ģʽ������*/
            uint16_t WN_DM_EV_StandardStart                 :1;
            /*1.115 �˶�ģʽ������*/
            uint16_t WN_DM_EV_SportStart                    :1;
            /*1.115 ����ģʽ������*/
            uint16_t WN_DM_EV_EcoStart                      :1;
            /*1.115 ѩ��ģʽ������ */
            uint16_t WN_DM_EV_SnowStart                     :1;
            /*1.115 AUTOģʽ������*/
            uint16_t WN_DM_EV_AutoStart                     :1;
            /*1.117 ��̤�幦��������*/
            uint16_t WN_DM_V51EV_SinPedalStart              :1;
            /*1.117 ��̤�幦���˳�*/
            uint16_t WN_DM_V51EV_SinPedalQuit               :1;
            /*1.162 ��ʱ��ͣ���������ɲ��/����P��*/
            uint16_t WN_StopBrakeGearN                      :1;
            /*1.42  ��Դδ��*/
            uint16_t WN_PowerNotInOff                       :1;
            /*1.6   ������ͣ*/
            uint16_t WN_AutoStartStop                       :1;
            /*1.80 ���װ�����Ƴ�  No signal*/
            uint16_t WN_ChargeDevRemoved                    :1;
            /*1.109 ������ص����ͣ�EVģʽ������*/
            uint16_t WN_DM_DBL_EV_Err                       :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�AWDģʽ������*/
            uint16_t WN_DM_HSL_AWD                          :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�EVģʽ������*/
            uint16_t WN_DM_HSL_EV                           :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�SAVEģʽ������*/
            uint16_t WN_DM_HSL_SAVE                         :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�SPORTģʽ������*/
            uint16_t WN_DM_HSL_SPORT                        :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�ɳ��ģʽ������*/
            uint16_t WN_DM_HSL_SAND                         :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ����ģʽ������*/
            uint16_t WN_DM_HSL_MUDDY                        :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ�ѩ��ģʽ������*/
            uint16_t WN_DM_HSL_SNOW                         :1;
            /*1.114 ��׼ģʽ������*/
            uint16_t WN_DM_PHEV_AutoStart                   :1;
            /*1.114 ����ģʽ������*/
            uint16_t WN_DM_PHEV_EvStart                     :1;
            /*1.114 ��������ģʽ������*/
            uint16_t WN_DM_PHEV_SaveStart                   :1;
            /*1.114 �˶�ģʽ������*/
            uint16_t WN_DM_PHEV_SportStart                  :1;
            /*1.114 ����ģʽ������*/
            uint16_t WN_DM_PHEV_AWDStart                    :1;
            /*1.114 ѩ��ģʽ������*/
            uint16_t WN_DM_PHEV_SnowStart                   :1;
            /*1.114 ���ģʽ������*/
            uint16_t WN_DM_PHEV_MuddyStart                  :1;
            /*1.114 ɳ��ģʽ������*/
            uint16_t WN_DM_PHEV_SandStart                   :1;
            /*1.114 ����ģʽ������*/
            uint16_t WN_DM_PHEV_EcoStart                    :1;
            /*1.114 �����˶�ģʽ������*/
            uint16_t WN_DM_PHEV_SportPlusStart              :1;
            /*1.109 ��ʹ���ֶ������������л���SPORTģʽ*/
            uint16_t WN_DM_MS_SPORT                         :1;
            /*1.109 ��ʹ���ֶ���������SPORTģʽ����*/
            uint16_t WN_DM_MS_SPORT_Only                    :1;
            /*1.109 ��϶���ϵͳ���ƽ����EVģʽ����*/
            uint16_t WN_DM_HSR_EV                           :1;
            /*1.111 ESP/AVH����δ�رգ������𲽲�����*/
            uint16_t WN_RLUnavaiESPAVH                      :1;
            /*1.111 ��϶���ϵͳ��ʱ���ޣ������𲽲�����*/
            uint16_t WN_RLUnavaiHYB                         :1;
            /*1.109 ��϶���ϵͳ��ʱ���ޣ���������ģʽģʽ������*/
            uint16_t WN_DM_HSL_SPORT_P                      :1;
            /*1.109 ��϶���ϵͳ��ʱ����, ECOģʽ������*/
            uint16_t WN_DM_HSL_ECO                          :1;
            /*TBD   ת���������ѿ���*/
            uint16_t WN_TurnAssistOn                        :1;
            /*TBD   ת�������ܹ�����*/
            uint16_t WN_TurnAssistWork                      :1;
            /*TBD   ת���������ѹر�*/
            uint16_t WN_TurnAssistClose                     :1;
            /*TBD   ԽҰѲ�������ѹر�*/
            uint16_t WN_ORCruiseClose                       :1;
            /*TBD   ԽҰѲ�������ѽ������״̬*/
            uint16_t WN_ORCruiseWait                        :1;
            /*TBD   ԽҰѲ�������ѿ���*/
            uint16_t WN_ORCruiseOn                          :1;
            /*1.11  EPB����1 ��ϵ��ȫ��*/
            uint16_t WN_FastenSeatbelt                      :1;
            /*1.11  EPB����1 �¶ȹ���*/
            uint16_t WN_GradientHighWarning                 :1;
            /*1.11  EPB����1 פ���ƶ�����*/
            uint16_t WN_ParkSysWarning                      :1;
            /*1.11  EPB����1 �н�������*/
            uint16_t WN_ClampForceWarning                   :1;
            /*1.15  ����ƶ�̤��*/
            uint16_t WN_StepBrakePedal                      :1;
            /*TBD   ��ͣ���������� ��ɾ��*/
            uint16_t WN_SettingVehilce                      :1;
            /*1.119 �����¶ȵͣ����������*/
            uint16_t WN_OutTempLow                          :1;
            /*1.129 AFS�ر�  No signal*/
            uint16_t WN_AFSOff                              :1;
            /*1.129 AFS����  No signal*/
            uint16_t WN_AFSOn                               :1;
            /*1.142 �����л�����ػ�ɳ��ģʽ*/
            uint16_t WN_SwitchMudSand                       :1;
            /*1.112 ����ģʽ�˳�*/
            uint16_t WN_RaceModeExit                        :1;
            /*1.112 �޷����뵯��ģʽ*/
            uint16_t WN_RaceModeFault                       :1;
            /*1.123 ���ش��ʾ����δ�����������п������ÿ���  No signal*/
            uint16_t WN_PHLWideFunOff                       :1;
            /*1.123 ���ش��ʾ���ܿ���  No signal*/
            uint16_t WN_PHLWideOn                           :1;
            /*1.123 ���ش��ʾ���ܹر�  No signal*/
            uint16_t WN_PHLWideOff                          :1;
            /*1.136 ���ش�ƹ��ܹر�  No signal*/
            uint16_t WN_PHLFunOff                           :1;
            /*1.136 ���ش�ƹ��ܿ���  No signal*/
            uint16_t WN_PHLFunOn                            :1;
            /*TBD   ���˳����ģʽ*/
            uint16_t WN_QuitCompactMode                     :1;
            /*1.163 ϴ��/�ϳ�ģʽ�Ѽ���*/
            uint16_t WN_WashModeActive                      :1;
            /*1.163 ���ٹ��ߣ�ϴ��/�ϳ�ģʽ������*/
            uint16_t WN_WashModeSpeed                       :1;
            /*1.163 ���ص����ͣ�ϴ��/�ϳ�ģʽ������*/
            uint16_t WN_WashModeBatt                        :1;
            /*1.164 ��/�ŵ�ǹ������*/
            uint16_t WN_ChargeDisGunConnect                 :1;
            /*1.164 ���ǹ������*/
            uint16_t WN_ChargeGunConnect                    :1;
            /*1.76  ���ͷŵ���פ��*/
            uint16_t WN_ReleaseElecPark                     :1;
            /*1.76  ���ͷź��Ų�����*/
            uint16_t WN_ReleaseRearELD                      :1;
            /*1.111 ESP����δ�رգ������𲽲�����*/
            uint16_t WN_RLUnavaiESP                         :1;
            /*1.152 �������Ԥ�����*/
            uint16_t WN_HeatingComplete                     :1;
            /*1.172 ����ʶ����ȡ��*/
            uint16_t WN_FaceCancelled                       :1;
            /*1.172 δ�ҵ�ƥ�������*/
            uint16_t WN_FaceNoMatch                         :1;
            /*1.172 ����ʶ��ɹ�*/
            uint16_t WN_FaceSuccess                         :1;
            /*1.168 ��϶���ϵͳ��ʱ���ޣ���̤�岻����  No signal*/
            uint16_t WN_PedalDynBatt                        :1;
            /*1.168 ѩ��ģʽ��������̤�岻����  No signal*/
            uint16_t WN_PedalDynSnow                        :1;
            /*1.122 ��Զ����Զ�⿪��  No signal*/
            uint16_t WN_FarBeamOn                           :1;
            /*1.122 ��Զ����Զ��ر�  No signal*/
            uint16_t WN_FarBeamOff                          :1;
            /*1.180 �ϳ����ڹ����ѿ���*/
            uint16_t WN_TmsTrailer                          :1;
            /*1.180 �ϳ����ڹ����ѹر�*/
            uint16_t WN_TsmTrailerOff                       :1;
            /*1.138 ��������ֱ�� �볢�Ե���ֱ�� TBD*/
            uint16_t WN_4WDGearDelayPlsSlow                 :1;
            /*1.217 ̧ͷ��ʾ����������*/
            uint16_t WN_ARHUDLightLimit                     :1;
            /*1.111 ������ص���/�¶ȵͣ������𲽲�����*/
            uint16_t WN_BattLowLaunchUnavil                 :1;
            /*1.218 ����������˳� ����Ʒ���*/
            uint16_t WN_IFCExitPlsControl                   :1;
            /*1.242 ERCϵͳ���� ������ά��*/
            uint16_t WN_ERCSysErr                           :1;
            /*1.269 ����������������*/
            uint16_t WN_IFCLKAFuncOn                        :1;
            /*1.248 ת�������������� ��С�ļ�ʻ*/
            uint16_t WN_TurnAssistFuncLimit                 :1;
            /*1.242 ERCϵͳ����*/
            uint16_t WN_ERCSysLimit                         :1;
            /*1.239 �����������ͣ������ȼ��*/
            uint16_t WN_MainTankLow                         :1;
            /*1.239 �����������ͣ��뼰ʱϨ���л���������*/
            uint16_t WN_MainTankLowPlsSwitch                :1;
            /*1.239 �����������ͣ������ȼ��*/
            uint16_t WN_AuxTankLow                          :1;
            /*1.239 �����������ͣ��뼰ʱϨ���л���������*/
            uint16_t WN_AuxTankLowPlsSwitch                 :1;
            /*1.113 SUPER SPORT*/
            uint16_t WN_DM_B30_Turbo                        :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_B30_Race                         :1;
            /*1.113 �ݵ�/��ʯģʽ*/
            uint16_t WN_DM_B30_GrassGravel                  :1;
            /*1.113 ��͹·ģʽ*/
            uint16_t WN_DM_B30_Uneven                       :1;
            /*1.113 ��ˮģʽ*/
            uint16_t WN_DM_B30_Wade4H                       :1;
            /*1.113 ������ˮģʽ*/
            uint16_t WN_DM_B30_Wade4L                       :1;
            /*1.113 2Hģʽ*/
            uint16_t WN_DM_B30_2H                           :1;
            /*1.113 4Hģʽ*/
            uint16_t WN_DM_B30_4H                           :1;
            /*1.113 SUPER SPORT��ѡ��*/
            uint16_t WN_DM_TurboSelect                      :1;
            /*1.113 ����ģʽ��ѡ��*/
            uint16_t WN_DM_RaceSelect                       :1;
            /*1.113 �ݵ�/��ʯģʽ��ѡ��*/
            uint16_t WN_DM_GrassGravelSelect                :1;
            /*1.113 ��͹·ģʽ��ѡ��*/
            uint16_t WN_DM_UnevenSelect                     :1;
            /*1.113 ��ˮģʽ��ѡ��*/
            uint16_t WN_DM_Wade4HSelect                     :1;
            /*1.113 ������ˮģʽ��ѡ��*/
            uint16_t WN_DM_Wade4LSelect                     :1;
            /*1.113 2Hģʽ��ѡ��*/
            uint16_t WN_DM_2HSelect                         :1;
            /*1.113 4Hģʽ��ѡ��*/
            uint16_t WN_DM_4HSelect                         :1;
            /*1.113 SUPER SPORT�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_TurboDPR                         :1;
            /*1.113 ����ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_RaceDPR                          :1;
            /*1.113 �ݵ�/��ʯģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_GrassGravelDPR                   :1;
            /*1.113 ��͹·ģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_UnevenDPR                        :1;
            /*1.113 ��ˮģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_Wade4HDPR                        :1;
            /*1.113 ������ˮģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_Wade4LDPR                        :1;
            /*1.113 2Hģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_2HDPR                            :1;
            /*1.113 4Hģʽ�л��У��޷�����D/P/R��*/
            uint16_t WN_DM_4HDPR                            :1;
            /*1.113 SUPER SPORT*/
            uint16_t WN_DM_TurboSecond                      :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_RaceSecond                       :1;
            /*1.113 �ݵ�/��ʯģʽ*/
            uint16_t WN_DM_GrassGravelSecond                :1;
            /*1.113 ��͹·ģʽ*/
            uint16_t WN_DM_UnevenSecond                     :1;
            /*1.113 ��ˮģʽ*/
            uint16_t WN_DM_Wade4HSecond                     :1;
            /*1.113 ������ˮģʽ*/
            uint16_t WN_DM_Wade4LSecond                     :1;
            /*1.113 2Hģʽ*/
            uint16_t WN_DM_2HSecond                         :1;
            /*1.113 4Hģʽ*/
            uint16_t WN_DM_4HSecond                         :1;
            /*1.114 �춯ģʽ������*/
            uint16_t WN_DM_PHEV_P2HEVStart                  :1;
            /*1.114 ����ģʽ������*/
            uint16_t WN_DM_PHEV_P2EVStart                   :1;
            /*1.114 ��������ģʽ������*/
            uint16_t WN_DM_PHEV_P2SaveStart                 :1;
            /*1.247 �ѽ���֧��NOH·�Σ���ӭʹ��*/
            uint16_t WN_AutoNaviStart                       :1;
            /*1.247 ǰ�� XX �ף������˳��Զ����浼����ʻ*/
            uint16_t WN_AutoNaviExitPlsTake                 :1;
            /*1.247 NOH���˳�*/
            uint16_t WN_AutoNaviEnd                         :1;
            /*1.242 ���ٹ��� ERCϵͳ�Զ�����*/
            uint16_t WN_OverSpeedERCSysOn                   :1;
            /*1.242 ��ǰ��ʻģʽ ERCϵͳ�Ͽ�����*/
            uint16_t WN_ERCSysDisable                       :1;
            /*1.265 ԽҰɢ��ģʽ�ѿ���*/
            uint16_t WN_OffroadThmSts                       :1;
            /*1.245 ��Ƶ�����쳣*/
            uint16_t WN_AntennaLostErr                      :1;
            /*1.268 �Զ���ƿ���*/
            uint16_t WN_AutoLmpStsOn                        :1;
            /*1.268 �Զ���ƹر�*/
            uint16_t WN_AutoLmpStsOff                       :1;
            /*1.267 ���˳���ˮģʽ*/
            uint16_t WN_PlsExitWadeMode                     :1;
            /*1.267 �����*/
            uint16_t WN_WadeModePlsSlow                     :1;
            /*1.267 ��ȷ���ܱ߹��� ������ˮ���������*/
            uint16_t WN_WadeModePlsCare                     :1;
            /*1.249 ���������µ翪�أ������µ磡*/
            uint16_t WN_CarPowerShutDown                    :1;
            /*1.296 ����̽�⹦�ܹ���*/
            uint16_t WN_LifeDetectFault                     :1;
            /*1.270 ���������*/
            uint16_t WN_ClutchOverheat                      :1;
            /*TBD �����𲽳�ʱ*/
            uint16_t WN_QuickStartOvertime                  :1;
            /*1.295 ����̽�⹦�ܹر�*/
            uint16_t WN_LifeDetectClose                     :1;
            /*TBD ����ɲ��+���N��+��ʻ�����˻�ȫ��ϵ��*/
            uint16_t WN_StopGearNSeatbelt                   :1;
            /*TBD ����ɲ��+���P����N��+��ʻ�����˻�ȫ��ϵ��*/
            uint16_t WN_StopGearPNSeatbelt                  :1;
            /*1.142 �����л���ѩ�ء���ء�ɳ�ػ�͹·ģʽ*/
            uint16_t WN_SwitchSnowSand                      :1;
            /*1.116 ���Ի�ģʽ������*/
            uint16_t WN_Individual                          :1;
            /*TBD ����ϵͳ��ʱ���ޣ������𲽲����� */
            uint16_t WN_PowerSysLimitLaunchFail             :1;
            /*1.274 ��ǰΪԤԼ���ģʽ*/
            uint16_t WN_ForwardChargeMode                   :1;
            /*1.109 ����ģʽ���������������ģʽ������*/
            uint16_t WN_4WDEVSaveDisable                    :1;
            /*1.250 ��ע��ǰ������+ͼƬ*/
            uint16_t WN_V2XCarDistance                      :1;
            /*1.259 ע���������+ǰ��ͼƬ*/
            uint16_t WN_V2XPeopleRight                      :1;
            /*1.259 ע���������+��ͼƬ*/
            uint16_t WN_V2XPeopleMid                        :1;
            /*1.259 ע���������+ǰͼƬ*/
            uint16_t WN_V2XPeopleLeft                       :1;
            /*1.255 ע���������+ͼƬ*/
            uint16_t WN_V2XFaceCar                          :1;
            /*1.254 ע���������+����ͼƬ*/
            uint16_t WN_V2XSideCarTwoSide                   :1;
            /*1.254 ע���������+�Ҳ�ͼƬ*/
            uint16_t WN_V2XSideCarRight                     :1;
            /*1.254 ע���������+���ͼƬ*/
            uint16_t WN_V2XSideCarLeft                      :1;
            /*1.253 ǰ�����������ƶ�+ͼƬ*/
            uint16_t WN_V2XFrontCarAEB                      :1;
            /*1.258 ע��ǰ��ʧ�س���+ͼƬ*/
            uint16_t WN_V2XFrontCarUnContron                :1;
            /*1.258 ע���ʧ�س���+ͼƬ*/
            uint16_t WN_V2XBackCarUnContron                 :1;
            /*1.258 ע����Χʧ�س���+ͼƬ*/
            uint16_t WN_V2XAroundCarUnContron               :1;
            /*1.278 �ϳ������� ����*/
            uint16_t WN_HookFaultPlsCheck                   :1;
            /*1.285 �������ܹ������ޣ��뾡��ά��*/
            uint16_t WN_SuspensionFuncLimit                 :1;
            /*1.285 �������ܹ��ϣ�������ά��*/
            uint16_t WN_SuspensionFuncFault                 :1;
            /*1.289 �߻��������ϸ�*/
            uint16_t WN_CatalystSuHigh                      :1;
            /*1.289 ���ڳ���*/
            uint16_t WN_SuClearing                          :1;
            /*1.288 ����Һλ����*/
            uint16_t WN_OilLeverLow                         :1;
            /*1.288 ����Һλ����*/
            uint16_t WN_OilLeverHigh                        :1;
            /*1.288 ����Һλ������*/
            uint16_t WN_OilLeverFault                       :1;
            /*1.252 ���������+ͼƬ*/
            uint16_t WN_V2XLeftLine                         :1;
            /*1.252 �����Ҳ���+ͼƬ*/
            uint16_t WN_V2XRightLine                        :1;
            /*1.261 �������򳬳�+ͼƬ*/
            uint16_t WN_V2XReverseLine                      :1;
            /*1.262 ��ע��ǰ��·��+ͼƬ*/
            uint16_t WN_V2XFrontRoad                        :1;
            /*1.256 ��ע��ǰ���쳣����+ͼƬ*/
            uint16_t WN_V2XFrontCarAttention                :1;
            /*1.257 ע����ý�������*/
            uint16_t WN_V2XLeaveCar                         :1;
            /*1.257 ע�����������*/
            uint16_t WN_V2XLeaveFireCar                     :1;
            /*1.257 ע����þȻ���*/
            uint16_t WN_V2XLeaveAmbulance                   :1;
            /*1.257 ע����þ���*/
            uint16_t WN_V2XLeavePolice                      :1;
            /*1.257 ע����ù��̾�Ԯ��*/
            uint16_t WN_V2XLeaveEngCar                      :1;
            /*1.251 ע���ä������+���ä��ͼƬ*/
            uint16_t WN_V2XBackCarLeft                      :1;
            /*1.251 ע���ä������+�Һ�ä��ͼƬ*/
            uint16_t WN_V2XBackCarRight                     :1;
            /*1.251 ע���ä������+���Һ�ä��ͼƬ*/
            uint16_t WN_V2XBackCarTwoSide                   :1;
            /*1.160 ����ʡ��ģʽ�¶����Ժ�����������*/
            uint16_t WN_SavePlusPowerLimit                  :1;
            /*1.160 ���ٹ���,�޷��л�����ʡ��ģʽ*/
            uint16_t WN_OverSpeedSavePlusFail               :1;
            /*1.160 ���й����Ѽ���*/
            uint16_t WN_WormFuncActive                      :1;
            /*1.160 ���й��ܹر�*/
            uint16_t WN_WormFuncOff                         :1;
            /*1.284 ���ص�����\n�������������ĳ����߶�*/
            uint16_t WN_BattLowStartEng                     :1;
            /*1.284 ��������ϵͳ������ȴ����ȴ�*/
            uint16_t WN_SuspensionCoolDown                  :1;
            /*1.284 ��ѡ�߶�ģʽ������*/
            uint16_t WN_HeightModeDisable                   :1;
            /*1.284 ��رճ���\n����ɸ߶�����*/
            uint16_t WN_PlsCloseDoorRise                    :1;
            /*1.284 �������ģʽ\n����������ʱ����*/
            uint16_t WN_RiseModeSusLimit                    :1;
            /*1.284 ����������ʱ����*/
            uint16_t WN_SuspensionTimeLimit                 :1;
            /*1.284 ���ٸ�\n�޷���ɸ߶��л�*/
            uint16_t WN_OverSpeedHeightDisable              :1;
            /*1.287 ��ǰ��������Ԥ��SOCֵ���޷����*/
            uint16_t WN_OverDefaultPower                    :1;
            /*1.276 �ϳ���������*/
            uint16_t WN_HookLock                            :1;
            /*1.276 �ϳ����ѽ���*/
            uint16_t WN_HookUnlock                          :1;
            /*1.277 �ϳ��������������*/
            uint16_t WN_HookPowerOn                         :1;
            /*1.279 �����л�Ϊפ��״̬*/
            uint16_t WN_SwitchParkSts                       :1;
            /*1.280 ���ȹر��ϳ���*/
            uint16_t WN_PlsCloseHook                        :1;
            /*1.281 �����ϳ�������״̬*/
            uint16_t WN_PlsCheckHookSts                     :1;
            /*1.283 ��ѡ���׼�߶�*/
            uint16_t WN_NormalHeightSelect                  :1;
            /*1.283 ��ѡ���ݽ����߶�*/
            uint16_t WN_SuitHeightSelect                    :1;
            /*1.283 ��ѡ��ԽҰ�߶�1*/
            uint16_t WN_ORHeight1Select                     :1;
            /*1.283 ��ѡ��ԽҰ�߶�2*/
            uint16_t WN_ORHeight2Select                     :1;
            /*1.283 ���ܽ�����չģʽ*/
            uint16_t WN_SuspensionExtend                    :1;
            /*1.283 ���������ڱ�ݽ����߶�*/
            uint16_t WN_SuspensionLockHeight                :1;
            /*1.283 ��ѡ�����װ�ظ߶�*/
            uint16_t WN_BackShaftHeightSelect               :1;
            /*1.283 ��ѡ���Զ���ݽ���ģʽ*/
            uint16_t WN_SuitHeightModeSelect                :1;
            /*1.283 �������������ϳ�ģʽ*/
            uint16_t WN_SuspensionTrailer                   :1;
            /*1.283 ����������ʱ����\n�Խ��л�̥������*/
            uint16_t WN_SuspensionLimitRise                 :1;
            /*1.283 ��ѡ����߿�������װ��ģʽ*/
            uint16_t WN_KickBackShaft                       :1;
            /*1.283 ����������ʱ����\n���ڳ�������*/
            uint16_t WN_SuspensionLimitTrans                :1;
            /*1.283 ���ܼ�������\n�˳���ǰ��ˮƽ�߶�*/
            uint16_t WN_SuspensionRise                      :1;
            /*1.283 ��ǰ�������ڸ�λ\n���������*/
            uint16_t WN_CarHighPlsSlow                      :1;
            /*1.289 �������*/
            uint16_t WN_SuClearDown                         :1;
            /*1.282 ϵͳ���ϣ�����Ӧ�������ղ�����*/
            uint16_t WN_SysFailACCDisable                   :1;
            /*1.282 ���������ϣ�����Ӧ�������ղ�����*/
            uint16_t WN_ACCPowerDisable                     :1;
            /*1.282 ���ܼ�ʻ���ܼ������Ӧ�������� ������*/
            uint16_t WN_HWAACCPowerDisable                  :1;
            /*1.282 ESP���ܼ������Ӧ���� ���ղ�����*/
            uint16_t WN_ESPACCPowerDisable                  :1;
            /*1.282 ����Ӧ���������˳�*/
            uint16_t WN_ACCPowerExit                        :1;
            /*TBD ������ع��ʵͣ�����ģʽ������ ��ɾ��*/
            uint16_t WN_BattPowerLowEVDisable               :1;
            /*TBD ��������¶ȵͣ�����ģʽ������ ��ɾ��*/
            uint16_t WN_BattTempLowEVDisable                :1;
            /*TBD ��ǰΪ4Lģʽ���������������ģʽ������*/
            uint16_t WN_4LModeEVSaveDisable                 :1;
            /*1.76 ��ǯ���ȣ�ת������������*/
            uint16_t WN_CalibreHeatTabLimit                 :1;
            /*TBD ����ʡ��ģʽ������*/
            uint16_t WN_SavePlusModeStart                   :1;
            /*1.264 ��·���ӵ��+ͼƬ*/
            uint16_t WN_V2XRoadBlockLever1                  :1;
            /*1.264 ��·�ж�ӵ��+ͼƬ*/
            uint16_t WN_V2XRoadBlockLever2                  :1;
            /*1.264 ��·����ӵ��+ͼƬ*/
            uint16_t WN_V2XRoadBlockLever3                  :1;
            /*1.264 ��·ӵ��+ͼƬ*/
            uint16_t WN_V2XRoadBlock                        :1;
            /*TBD ����ɲ��+һ������ ��ҿյ�*/
            uint16_t WN_StepBrakeStartGearBlank             :1;
            /*1.38 ����ɲ��+��ҿյ�+��ʻ�����˻�ȫ��ϵ��*/
            uint16_t WN_StopGearBlankSeatbelt               :1;
            /*1.205 �������ӹ�*/
            uint16_t WN_PlsTakeOver                         :1;
            /*1.205 �������ӹ�2Hz��ʾ��*/
            uint16_t WN_PlsTakeOver_2Hz                     :1;
            /*1.205 �������ӹ�4Hz��ʾ��*/
            uint16_t WN_PlsTakeOver_4Hz                     :1;
            /*1.272 ���������Զ�ɲͣ���������ӹ�*/
            uint16_t WN_CarAutoBrakePlsTake                 :1;
            /*1.272 �������ڿ���ͣ�����������ӹ�*/
            uint16_t WN_CarParkingPlsTake                   :1;
            /*1.272 �������ڽ���ɲͣ���������ӹ�*/
            uint16_t WN_CarUrgeBrakePlsTake                 :1;
            /*1.297 ʻ���ѵ�ʧ�ܣ��������ӹ�*/
            uint16_t WN_MoveRampFailPlsTake                 :1;
            /*1.297 ������·ʧ�ܣ��������ӹ�*/
            uint16_t WN_MoveMainFailPlsTake                 :1;
            /*1.297 ������·ʧ�ܣ��������ӹ�2Hz��ʾ��*/
            uint16_t WN_MoveMainFailPlsTake_2Hz             :1;
            /*1.297 ������·ʧ�ܣ��������ӹ�4Hz��ʾ��*/
            uint16_t WN_MoveMainFailPlsTake_4Hz             :1;
            /*1.297 ת��ʧ�ܣ��������ӹ�*/
            uint16_t WN_TurnFailPlsTake                     :1;
            /*1.297 ת��ʧ�ܣ��������ӹ�2Hz��ʾ��*/
            uint16_t WN_TurnFailPlsTake_2Hz                 :1;
            /*1.297 ת��ʧ�ܣ��������ӹ�4Hz��ʾ��*/
            uint16_t WN_TurnFailPlsTake_4Hz                 :1;
            /*1.297 �޷��ɹ�ͨ���շ�վ���������ӹ�*/
            uint16_t WN_TollGateFailPlsTake                 :1;
            /*1.297 �޷��ɹ�ͨ���շ�վ���������ӹ�2Hz��ʾ��*/
            uint16_t WN_TollGateFailPlsTake_2Hz             :1;
            /*1.297 �޷��ɹ�ͨ���շ�վ���������ӹ�4Hz��ʾ��*/
            uint16_t WN_TollGateFailPlsTake_4Hz             :1;
            /*1.297 �޷��ɹ�ͨ���������������ӹ�*/
            uint16_t WN_RoundaboutFailPlsTake               :1;
            /*1.297 �޷��ɹ�ͨ���������������ӹ�2Hz��ʾ��*/
            uint16_t WN_RoundaboutFailPlsTake_2Hz           :1;
            /*1.297 �޷��ɹ�ͨ���������������ӹ�4Hz��ʾ��*/
            uint16_t WN_RoundaboutFailPlsTake_4Hz           :1;
            /*1.256 ��ע��ǰ���쳣����+��ǰ��ͼƬ*/
            uint16_t WN_V2XFrontCarAttentionLeft            :1;
            /*1.256 ��ע��ǰ���쳣����+��ǰ��ͼƬ*/
            uint16_t WN_V2XFrontCarAttentionRight           :1;
            /*1.204 ǰ����ת�䣬���ַ�������*/
            uint16_t WN_UrgeTurnPlsHoldWheel                :1;
            /*1.294 ���׮���ϣ����ֹͣ*/
            uint16_t WN_FastChrgFault                       :1;
            /*1.273 �޷�����NOH����ǰ��4S������*/
            uint16_t WN_NOHFailPlsFix                       :1;
            /*1.273 �޷�����NOH�����P�����³���*/
            uint16_t WN_NOHFailPlsGearP                     :1;
            /*1.273 ���ֶ������ѵ�*/
            uint16_t WN_MoveRampFailPlsHand                 :1;
            /*1.273 ����е��ѣ���Ҫ��İ���*/
            uint16_t WN_MoveMainFailPlsHand                 :1;
            /*1.273 ת��ʧ�ܣ����ֶ�����*/
            uint16_t WN_TurnFailPlsHand                     :1;
            /*1.273 �޷��ɹ�ͨ���շ�վ�����ֶ�����*/
            uint16_t WN_TollGateFailPlsHand                 :1;
            /*1.273 �޷��ɹ�ͨ�����������ֶ�����*/
            uint16_t WN_RoundaboutFailPlsHand               :1;
            /*1.273 �����¹滮·��*/
            uint16_t WN_RePlanLanes                         :1;
            /*1.273 ·�����ӣ����ֶ�������*/
            uint16_t WN_PlsHandChangeLanes                  :1;
            /*1.297 ʻ���ѵ�ʧ�ܣ�����Ʒ�����*/
            uint16_t WN_MoveRampFailHandWheel               :1;
            /*1.297 ʻ���ѵ�ʧ�ܣ�����Ʒ�����2Hz��ʾ��*/
            uint16_t WN_MoveRampFailHandWheel_2Hz           :1;
            /*1.297 ������·ʧ�ܣ�����Ʒ�����*/
            uint16_t WN_MoveMainFailHandWheel               :1;
            /*1.297 ת��ʧ�ܣ�����Ʒ�����*/
            uint16_t WN_TurnFailPlsHandWheel                :1;
            /*1.297 �޷��ɹ�ͨ���շ�վ������Ʒ�����*/
            uint16_t WN_TollGateFailPlsHandWheel            :1;
            /*1.297 �޷��ɹ�ͨ������������Ʒ�����*/
            uint16_t WN_RoundaboutFailPlsHandWheel          :1;
            /*1.201 �ǻ�Ѳ��������*/
            uint16_t WN_TJAICADisable                       :1;
            /*1.204 ���ٵ���40km/h���������������*/
            uint16_t WN_LowSpeedLaneAssistDisable           :1;
            /*1.204 ���ٸ���120km/h���������������*/
            uint16_t WN_OverSpeedLaneAssistDisable          :1;
            /*1.297 ��ǰ�޷������ǻ�Ѳ��ϵͳ�����������ͷ*/
            uint16_t WN_TJAICAFaultPlsFixCamera             :1;
            /*1.297 ��ǰ�޷������ǻ�Ѳ��ϵͳ����ǰ��4S������*/
            uint16_t WN_TJAICAFaultPlsFix                   :1;
            /*1.143 ��ȷ��ǰ���ֻ���������Ƿ����������ƫ��*/
            uint16_t WN_WPCChargeZoneFront                  :1;
            /*1.143 ��ȷ�Ϻ����ֻ���������Ƿ����������ƫ��*/
            uint16_t WN_WPCChargeZoneRear                   :1;
            /*1.143 ��ȷ�Ϻ����Ҳ��ֻ���������Ƿ����������ƫ��*/
            uint16_t WN_WPCChargeZoneRR                     :1;
            /*1.143 ��ȷ�Ϻ�������ֻ���������Ƿ����������ƫ��*/
            uint16_t WN_WPCChargeZoneRL                     :1;
            /*1.247 xx����/xx�׺󣬽��˳��Զ����浼����ʻ*/
            uint16_t WN_AutoNaviExit                        :1;
            /*1.282 �����ɿ����ţ����ھ��ü�ʻ*/
            uint16_t WN_AcceleratorPowen                    :1;
            /*1.203 ���䰲ȫ����*/
            uint16_t WN_TurnSafeSlow                        :1;
            /*1.247 XX����/�׺��˳�NOH*/
            uint16_t WN_NOHExit                             :1;
            /*1.247 ��׼���ӹܣ�XX�׺�NOH���˳�*/
            uint16_t WN_NOHExitPlsTake                      :1;
            /*1.247 �������ӹܣ�NOH���˳�*/
            uint16_t WN_NOHFinishExit                       :1;
            /*1.247 �����ٸ���125km/h��NOH���˳�*/
            uint16_t WN_OverSpeedNOHExit                    :1;
            /*1.247 ����������ٳ���*/
            uint16_t WN_DriveIntoHighSpeed                  :1;
            /*1.247 �����ѵ�����ע�ⰲȫ*/
            uint16_t WN_DriveIntoRamp                       :1;
            /*1.247 Ѳ��������ΪXXkm/h*/
            uint16_t WN_NOHSetAccSpeed                      :1;
            /*1.290 N������ֹ\n�޷�����*/
            uint16_t WN_LockNGearDisable                    :1;
            /*1.267 ������ƶ��������ƶ�����*/
            uint16_t WN_PlsPressBrakeTest                   :1;
            /*1.177 ��ѡ��4A/4H*/
            uint16_t WN_4Aor4HModeSelect                    :1;
            /*1.12/1.13/1.14 �ƶ�Һλ���ع���*/
            uint16_t WN_BrakeSwitchFault                    :1;
            /*TBD ��ȫ����ϵͳ������*/
            uint16_t WN_SafeBackStart                       :1;
            /*TBD ��ȫ����ϵͳ��������ͣ��*/
            uint16_t WN_SafeBackStopCar                     :1;
            /*1.11 ���л�����P���ͷ�פ��*/
            uint16_t WN_SwitchGearReleaseBrake              :1;
            /*1.116 ���ģʽ������*/
            uint16_t WN_DM_EV_MuddyStart                    :1;
            /*1.116 ɳ��ģʽ������*/
            uint16_t WN_DM_EV_SandStart                     :1;
            /*1.116 �����˶�ģʽ������*/
            uint16_t WN_DM_EV_SportPlusStart                :1;
            /*1.17/1.18  һ��ʽ�����忪����*/
            uint16_t WN_OneTrunkBoardOpen                   :1;
            /*1.17/1.18  ����ʽ�����忪����*/
            uint16_t WN_SplitTrunkBoardOpen                 :1;
            /*1.303 �����ڸǴ򿪵�Ч��ʾ��ͼƬ*/
            uint16_t WN_SlowFillingFlapOpenPicture          :1;
            /*1.303 ����ڸǴ򿪵�Ч��ʾ��ͼƬ*/
            uint16_t WN_QuickChargeFlapOpenPicture          :1;
            /*1.303 ����ڸ�δ��*/
            uint16_t WN_SlowFillingFlapNotClosed            :1;
            /*1.303 ���ڸ�δ��*/
            uint16_t WN_QuickChargeFlapNotClosed            :1;
            /*1.262 ��ע��ǰ����ˮ·��*/
            uint16_t WN_AttentionWaterRoad                  :1;
            /*1.262 ��ע��ǰ������·��*/
            uint16_t WN_AttentionLowlyingRoad               :1;
            /*1.262 ��ע��ǰ��ʪ��·��*/
            uint16_t WN_AttentionWetRoad                    :1;
            /*1.262 ��ע��ǰ����ת��*/
            uint16_t WN_AttentionSharpTurn                  :1;
            /*1.262 ��ע��ǰ����·�ϰ�*/
            uint16_t WN_NoteRoadFailure                     :1;
            /*1.262 ��ע��ǰ����ƽ·��*/
            uint16_t WN_NoteUnevenRoad                      :1;
            /*1.262 ��ע��ǰ����ɽ��·*/
            uint16_t WN_AttentionDangerousRoad              :1;
            /*1.262 ��ע��ǰ����ʯ��*/
            uint16_t WN_AwareDebrisFlow                     :1;
            /*1.262 ��ע��ǰ������*/
            uint16_t WN_NoteBridge                          :1;
            /*1.262 ��ע��ǰ�����*/
            uint16_t WN_AttentionTunnel                     :1;
            /*1.262 ��ע��ǰ������*/
            uint16_t WN_AwareFire                           :1;
            /*1.262 ��ע��ǰ����ʯ*/
            uint16_t WN_NoteFallingRock                     :1;
            /*1.262 ��ע��ǰ�����·��*/
            uint16_t WN_NoteIcyRoad                         :1;
            /*1.262 ��ע��ǰ�����·��*/
            uint16_t WN_NoteCrosswindRoad                   :1;
            /*1.262 ��ע��ǰ���̰�·��*/
            uint16_t WN_EmbankmentRoad                      :1;
            /*1.262 ��ע��ǰ��������ת��*/
            uint16_t WN_NoteContinuousSharpTurn             :1;
            /*1.262 ��ע��ǰ����·��խ*/
            uint16_t WN_NoteRoadNarrows                     :1;
            /*1.262 ��ע��ǰ����������*/
            uint16_t WN_NoteIncomingTraffic                 :1;
            /*1.262 ��ע��ǰ����·��ʩ��*/
            uint16_t WN_NotedamgeRoadFacities               :1;
            /*1.262 ��ע��ǰ��ɢ������*/
            uint16_t WN_AwareScatteredObject                :1;
            /*1.273 NOH�ѻָ�*/
            uint16_t WN_NOHIsResumed                        :1;
            /*1.273 ǰ�����룬С�Ĳ෽����*/
            uint16_t WN_MargeWatchOutFOrCarsComing          :1;
            /*1.273 ���ڼ��٣�׼�����*/
            uint16_t WN_SlowingDownForDischarge             :1;
            /*1.273 NOH���˳�����ӹܷ�����*/
            uint16_t WN_NOExitedTakeSteeringWheel           :1;
            /*1.273 �����߲���������С�ļ�ʻ*/
            uint16_t WN_LaneLineNotClearDriveCarefully      :1;
            /*1.301 ����ϵͳ��ʱ����*/
            uint16_t WN_FourWheelDriveSystem                :1;
            /*1.234 �������������ض���������վ���*/
            uint16_t WN_CatcherSeriouslyBlocked             :1;
            /*���״̬��ʾ����ʱ��磩*/
            uint16_t WN_ChargingStatusDisplay               :1;
            /*1.301 ���ٹ�������ϵͳ��ʱ�������*/
            uint16_t WN_ExcessiveSpeedFourWheelDrive        :1;
            /*1.302 ���������Ѽ����ע�⳵��*/
            uint16_t WN_NavigationSlowDownActive            :1;
            /*1.302 ��ע�����*/
            uint16_t WN_PlsPayAttentionToSlowDown           :1;
            /*1.302 ǰ����������60km/h����ע�����*/
            uint16_t WN_SpeedLimitForward60kmPerHour        :1;
            /*1.302 ǰ����������70km/h����ע�����*/
            uint16_t WN_SpeedLimitForward70kmPerHour        :1;
            /*1.302 ǰ����������80km/h����ע���80*/
            uint16_t WN_SPeedLimitForward80kmPerHour        :1;
            /*1.302 ǰ����������90km/h����ע�����*/
            uint16_t WN_SpeedLimitForward90kmPerHour        :1;
            /*1.302 ǰ����������100km/h����ע�����*/
            uint16_t WN_SpeedLimitForward100kmPerHour       :1;
            /*1.302 ǰ����������110km/h����ע�����*/
            uint16_t WN_SpeedLimitForward110kmPerHour       :1;
            /*1.302 ǰ����������120km/h����ע�����*/
            uint16_t WN_SpeedLimitForward120kmPerHour       :1;
            /*1.302 ��ע�⵱ǰ���ó��ٳ�����������*/
            uint16_t WN_CurrentlyExceedNavigationLimit      :1;
            /*1.203  ���²���������ȷ�ϵ�������*/
            uint16_t WN_TurnGearDownConfirmSpeedAdjustment  :1;
            /*1.203  ��cruise����ȷ�ϵ�������*/
            uint16_t WN_PressCruiseConfirmAdjustment        :1;
            /*1.247 ��������·���*/
            uint16_t WN_ComingOutMainRoad                   :1;
            /*1.116 Ů��ģʽ������*/
            uint16_t WN_GoddessModeActivated                :1;
            /*1.306 ϴ��Һ���� �뼰ʱ��ע*/
            uint16_t WN_WshngLiquidNotEnough                :1;
            /*1.233 ���ز��㣬XXXkm���޷����������ע*/
            uint16_t WN_UreaInsCantStartAfter               :1;
            /*1.233 �������ز��㣬xxxkm���޷����������ע*/
            uint16_t WN_UreaInsSeriouslyCantStartAfter      :1;
            /*1.233 ���ع޿գ��´��޷����������ע*/
            uint16_t WN_UreaEmptyCantStartNext              :1;
            /*1.233 ���ع޿գ��޷����������ע*/
            uint16_t WN_UreaEmptyCantStart                  :1;
            /*1.233 ���ز��ϸ�xxxkm���޷���������ά��*/
            uint16_t WN_UreaUnqualifyCantStartAfter         :1;
            /*1.233 ���ز��ϸ��´��޷���������ά��*/
            uint16_t WN_UreaUnqualifyCantStartNext          :1;
            /*1.233 ���ز��ϸ��޷���������ά��*/
            uint16_t WN_UreaUnqualifyCantStart              :1;
            /*1.233 ���������жϣ�xxxkm���޷���������ά��*/
            uint16_t WN_UreaFillStopCantStartAfter          :1;
            /*1.233 ���������жϣ��´��޷���������ά��*/
            uint16_t WN_UreaFillStopCantStartNext           :1;
            /*1.233 ���������жϣ��޷���������ά��*/
            uint16_t WN_UreaFillStopCantStart               :1;
            /*1.233 ��������ƫ�xxxkm���޷���������ά��*/
            uint16_t WN_ConsumDeviatCantStartAfter          :1;
            /*1.233 ��������ƫ��´��޷���������ά��*/
            uint16_t WN_ConsumDeviatCantStartNext           :1;
            /*1.233 ��������ƫ��޷���������ά��*/
            uint16_t WN_ConsumDeviatCantStart               :1;
            /*1.309 ��رջ��ոǺ�������������*/
            uint16_t WN_HoodClosedRestart                   :1;
            /*1.310 ��ر�����Ǻ�������������*/
            uint16_t WN_OilTankClosedRestart                :1;
            /*TBD ����ʶ��ʧ��*/
            uint16_t WN_FaceFail                            :1;
            /*TBD ������Ϣδ¼�룬�볢��������ʽ��¼*/
            uint16_t WN_FaceInforNotEntered                 :1;
            /*1.307 �����ƶ������ѿ���*/
            uint16_t WN_CSTActive                           :1;
            /*1.307 �����ƶ������ѹر�*/
            uint16_t WN_CSTClosed                           :1;
            /*1.109 ��������ǿ�ƴ���ģʽ��������ؿ��ù��ʵ�*/
            uint16_t WN_EVModeBattPowerLow                  :1;
            /*1.308 ���ӳɹ������ڷŵ�*/
            uint16_t WN_ConnectedDischarging                :1;
            /*1.308 ���ӳɹ���δ�ŵ�*/
            uint16_t WN_ConnectedNoDischarge                :1;
            /*TBD ǰ���Զ������С�*/
            uint16_t WN_FrontTireAutoBack                   :1;
            /*TBD �������Զ����������˳�*/
            uint16_t WN_SteeringAutomaFuncsExits            :1;
            /*1.179 �������й������� */
            uint16_t WN_EmergencyCallLimited                :1;
            /*1.314 ������ص����ͣ����������������ڷŵ�*/
            uint16_t WN_PowerLowStartEngine                 :1;
            /*1.314 �ŵ繦�ܼ���ʧ��*/
            uint16_t WN_FailedActivateDischarge             :1;
            /*1.102 �������ϵͳ����*/
            uint16_t WN_PowerSystemLimited                  :1;
            /*1.312 ����ת�����,��С�ļ�ʻ*/
            uint16_t WN_RearWheelSteeringFailure            :1;
            /*1.312 ����ת��������*/
            uint16_t WN_RearWheelSteeringLimited            :1;
            /*TBD ETCϵͳ����*/
            uint16_t WN_ETCSystemFault                      :1;
            /*1.80 �ŵ�װ�����Ƴ�*/
            uint16_t WN_DischargeDeviceRemoved              :1;
            /*TBD ETCͨ������*/
            uint16_t WN_ETCNormal                           :1;
            /*TBD ETCͨ���쳣*/
            uint16_t WN_ETCAbnormal                         :1;
            /*TBD �����θ���ͨ��������Ԥ������ XX.XXԪ*/
            uint16_t WN_ExpresswayNormal                    :1;
            /*1.380 ��ǰ����ģʽ�²��ɽ���*/
            uint16_t WN_CurrentTerrainCannotUnlocked        :1;
            /*1.382 �������Ԥ����*/
            uint16_t WN_PowerBattWarmup                     :1;
            /*1.382 ��������*/
            uint16_t WN_ChargerFailure                      :1;
            /*1.81 ��Ͽ���/�ŵ�װ��*/
            uint16_t WN_DisconnectChargingDischarging       :1;
            /*TBD ���ص������ͣ�ϵͳ3���Ӻ�رյ�Դ������������*/
            uint16_t WN_PowerOffAfterThreeMinute            :1;
            /*TBD ACC/CC����������Ұ�������*/
            uint16_t WN_ACCCCActive                         :1;
            /*TBD ACC/CCȡ�����������Ұ�������*/
            uint16_t WN_ACCCCCancel                         :1;
            /*1.315 ���������г�������ֻ��ͨ���������ؿ�������μ��û��ֲ�*/
            uint16_t WN_PleaseReadUserManual                :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_NoviceModel                         :1;
            /*1.113 ����ģʽ��ѡ��*/
            uint16_t WN_NoviceModelSelect                   :1;
            /*1.113 ����ģʽ�л��У��޷�����D/R/P��*/
            uint16_t WN_NoviceModelSwitch                   :1;
            /*TBD �зģʽ����*/
            uint16_t WN_CrabModeFailure                     :1;
            /*1.235 ǰ�ֻ������(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_FrontTireAlignFinishGEEP40          :1;
            /*TBD ����ģʽ*/
            uint16_t WN_FactoryPatternGEEP40                :1;
            /*TBD չ��ģʽ*/
            uint16_t WN_GalleryMode                         :1;
            /*1.8 ����ģʽ(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_StatBattLowTranModeGEEP40           :1;
            /*1.8 12V��Դϵͳ���ϣ����ʹ��ܹرգ�����ϵ4S��ά��(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_StatBattLowComfortOffGEEP40         :1;
            /*1.8 �������Ĺ��࣬����ʡ��ģʽ(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_StatBattLowSavingModeGEEP40         :1;
            /*1.8 ���ص������ͣ�ϵͳ3���Ӻ�رյ�Դ������������(Ӧ����Ŀ��GEEP4.0)  */
            uint16_t WN_PowerOffAfterThreeMinuteGEEP40      :1;
            /*TBD ���ڸ��ѿ���*/
            uint16_t WN_ChargingCoverOpen                   :1;
            /*1.8 12V���ص����ͣ����ʹ��ܽ�����(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_StatBattLowPwrReduceGEEP40          :1;
            /*1.273 ����ʧ�ܣ�����Ѳ��*/
            uint16_t WN_InboundFailedContinueCruise         :1;
            /*TBD xx����/xx�׺󼴽������ѵ�*/
            uint16_t WN_ApproachingRamp                     :1;
            /*TBD �зģʽ���˳�(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_CrabModeExitedGEEP40                :1;
            /*TBD �зģʽ�ѿ���(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_CrabModeEnabledGEEP40               :1;
            /*TBD �зģʽ�Ѵ���(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_CrabModeStandbyGEEP40               :1;
            /*1.311 ������ص����ϵͣ��뼰ʱ��������*/
            uint16_t WN_LowBatteryStartVehicle              :1;
            /*1.311 ������ص����ϵͣ��뼰ʱ�����������ǹ���*/
            uint16_t WN_LowBatteryPlugGunCharge             :1;
            /*1.168 ��ʻ�������ܿ�������̤�岻����*/
            uint16_t WN_AuxiliaryOpenSingPedalUnable        :1;
            /*1.210 �ǻ�Ѳ�����˳�������ɲ����������*/
            uint16_t WN_SmartCruiseouteEmergencyBrake       :1;
            /*1.411 ת���ܹ��ϣ��������ʻ(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_SteerFailDrivelowSpeed              :1;
            /*1.411 ת�������ޣ���С�ļ�ʻ(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_SteerFailDriveCarefully             :1;
            /*1.412 �����������Զ����룬������������(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_SteeringAutoNotTouchWheel           :1;
            /*1.412 �������Զ��������(Ӧ����Ŀ��GEEP4.0)*/
            uint16_t WN_SteeringWheelAutoaLigned            :1;
            /*1.113 ����ģʽ*/
            uint16_t WN_DM_B30_Novice                       :1;
            /*1.178 ����׼����(������)*/
            uint16_t WN_FuelPrepare_Sound                   :1;
            /*����Ѳ���ٶ�ֵ Value��0-240 km/h  0-150 mph*/
            uint16_t WN_TgtCrsSpdData                       :8;
            /*����Ѳ���ٶ���Ч��  Value: 0~Invalid 1~Valid*/
            uint16_t WN_TgtCrsSpdVld                        :1;
            /*��ʻģʽ����ֵ Value:1-5 ~ Drive Mode case1-case5*/
            uint16_t WN_DrvModeCase                         :8;
            /*�Զ�����������ʻ�������� Value:0-0xFFFF*/
            uint16_t WN_NOHDistData                         :16;
            /*��·Σ��״̬��ʾͼƬ Value��0-0x14*/
            uint16_t WN_V2XFrontRoadData                    :8;
            /*Ѳ������ Value��0-0xFE*/
            uint16_t WN_AccSpdSetValue                      :8;
            /*����ʣ����ʻ����ֵ Value��0-0xFFFF*/
            uint16_t WN_UreaRemainDistData                  :16;
            /*����׼���н���ֵ��0-0x63*/
            uint16_t WN_PressReliProgsData                  :8;
        }s_u32Warning_status_t;
    }u_WN_Moduleu32Warning_status_t;
}IPC_M2S_ClusterAppAPPWN_Module_t;

/* Transmit function of sub message WN_Module */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPWN_Module_Transmit(IPC_M2S_ClusterAppAPPWN_Module_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message Odo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPOdo_Transmit(IPC_M2S_ClusterAppAPPOdo_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message SIA */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPSIA_Transmit(IPC_M2S_ClusterAppAPPSIA_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TPMS */
typedef struct
{
    union
    {
        uint32_t TPMS_Inf[4];
        struct
        {
            /*��ǰ��̥ѹ״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fl_tire_press_status                   :2;
            /*��ǰ��̥ѹ��ɫ 0: White    1:Red*/
            uint32_t fl_tire_press_color                    :1;
            /*��ǰ��̥ѹֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t fl_tire_press_value                    :9;
            /*��ǰ��̥��״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fl_tire_temp_status                    :2;
            /*��ǰ��̥����ɫ 0: White    1:Red*/
            uint32_t fl_tire_temp_color                     :1;
            /*��ǰ��̥��ֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t fl_tire_temp_value                     :9;
            /*��ǰ����ʾ״̬ 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t fl_tire_behavior_color                 :1;
            /*��ǰ��̥ѹ״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fr_tire_press_status                   :2;
            /*��ǰ��̥ѹ��ɫ 0: White    1:Red*/
            uint32_t fr_tire_press_color                    :1;
            /*��ǰ��̥ѹֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t fr_tire_press_value                    :9;
            /*��ǰ��̥��״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t fr_tire_temp_status                    :2;
            /*��ǰ��̥����ɫ 0: White    1:Red*/
            uint32_t fr_tire_temp_color                     :1;
            /*��ǰ��̥��ֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t fr_tire_temp_value                     :9;
            /*��ǰ����ʾ״̬ 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t fr_tire_behavior_color                 :1;
            /*�����̥ѹ״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rl_tire_press_status                   :2;
            /*�����̥ѹ��ɫ 0: White    1:Red*/
            uint32_t rl_tire_press_color                    :1;
            /*�����̥ѹֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t rl_tire_press_value                    :9;
            /*�����̥��״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rl_tire_temp_status                    :2;
            /*�����̥����ɫ 0: White    1:Red*/
            uint32_t rl_tire_temp_color                     :1;
            /*�����̥��ֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t rl_tire_temp_value                     :9;
            /*�������ʾ״̬ 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t rl_tire_behavior_color                 :1;
            /*�Һ���̥ѹ״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rr_tire_press_status                   :2;
            /*�Һ���̥ѹ��ɫ 0: White    1:Red*/
            uint32_t rr_tire_press_color                    :1;
            /*�Һ���̥ѹֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t rr_tire_press_value                    :9;
            /*�Һ���̥��״̬ 0:Dsiplay OFF      1:Normal display   2:dash + unit*/
            uint32_t rr_tire_temp_status                    :2;
            /*�Һ���̥����ɫ 0: White    1:Red*/
            uint32_t rr_tire_temp_color                     :1;
            /*�Һ���̥��ֵ 0-0xFE��Valid   0xFF:Invalid*/
            uint32_t rr_tire_temp_value                     :9;
            /*�Һ�����ʾ״̬ 0:Normal    1:Tire red and 1HZ flashing*/
            uint32_t rr_tire_behavior_color                 :1;
            /*0:kpa   1:psi   2:bar*/
            uint32_t tire_press_unit                        :2;
            /*0:Celsius   1:Fahrenheit*/
            uint32_t tire_temp_unit                         :1;
        }s_TPMS_Inf_t;
    }u_TPMSTPMS_Inf_t;
}IPC_M2S_ClusterAppAPPTPMS_t;

/* Transmit function of sub message TPMS */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPTPMS_Transmit(IPC_M2S_ClusterAppAPPTPMS_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Chime */
typedef struct
{
    /*e_SoundType_RadarDWDLongRe_1 
    Chime id = 8    ��ˮ���DWD Long-�ظ�
    
    e_SoundType_RadarDWD3Hz_1
    Chime id = 15    ��ˮ���DWD 3Hz-�ظ�
    
    e_SoundType_RadarDWD1_5Hz_1
    Chime id = 21    ��ˮ���DWD 1.5Hz-�ظ�
    ����������ID���� EV�����ݲ�ʵ�� ��������ĿID����һ�£�*/
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

/* Transmit function of sub message Chime */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPChime_Transmit(IPC_M2S_ClusterAppAPPChime_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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
    /*buf0:avs_a ;buf1:avs_b��0xFFFF display dash 
    factor:1 eg 100=100km/h
    ;0xFFFE :Disable display */
    uint16_t AVS[2];
    /*buf0:travel_h_a ;buf1:travel_h_b ��0xFF display dash 
    ;0xFE :Disable display 
    
    */
    uint8_t Travel_time_Hour[2];
    /*buf0:travel_m_a ;buf1:travel_m_b��0xFF display dash 
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
    /*Suitable for independent twin tanks : Buf[0] main Dte�� Buf[1] aux Dte��0xFFFF display dash
    factor:1, eg 123=123KM
    ;0xFFFE :Disable display 
    */
    uint32_t DTE_Dual[2];
}IPC_M2S_ClusterAppAPPTripComputer_t;

/* Transmit function of sub message TripComputer */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPTripComputer_Transmit(IPC_M2S_ClusterAppAPPTripComputer_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: FUEL */
typedef struct
{
    /* factor =10 ,eg 505=50.5% */
    uint16_t TankFuelLevelPercent;
    /*0:Left 1:Right*/
    uint8_t Tankportposition;
    /*0:OFF;1:ON ;2 500ms flash and percent blue; 3 500ms flash and percent red*/
    uint8_t Low_fuel_warning;
    /* factor =10 ,eg 505=50.5% ȼ�͵ͱ����Ƶ�����ֵ*/
    uint16_t LFW_Trigger_Ipc;
    /* factor =10 ,eg 505=50.5% ȼ�͵ͱ�����Ϩ����ֵ*/
    uint16_t LFW_Release_Ipc;
    /*Suitable for independent twin tanks : Buf[0] main tank�� Buf[1] aux tank��factor =10 ,eg 505=50.5%*/
    uint16_t TankFuelLevelPercent_Dual[2];
    /* Suitable for independent twin tanks : Buf[0] main tank�� Buf[1] aux tank��0:Left 1:Right*/
    uint8_t Tankportposition_Dual[2];
    /* Suitable for independent twin tanks :   Buf[0] main tank�� Buf[1] aux tank��0:OFF;1:ON ;2 500ms flash and percent blue; 3 500ms flash and percent red*/
    uint8_t Low_fuel_warning_Dual[2];
    /*  Suitable for independent twin tanks :  Buf[0] main tank�� Buf[1] aux tank��factor =10 ,eg 505=50.5% ȼ�͵ͱ����Ƶ�����ֵ*/
    uint16_t LFW_Trigger_Ipc_Dual[2];
    /*  Suitable for independent twin tanks : Buf[0] main tank�� Buf[1] aux tank��factor =10 ,eg 505=50.5% ȼ�͵ͱ�����Ϩ����ֵ*/
    uint16_t LFW_Release_Ipc_Dual[2];
    /*Suitable for independent twin tanks : 0x0:Master Oil Box
    0x1:Auxiliary Oil Box
    0x2:Engine State Dissatisfy
    0x3:Reserved*/
    uint8_t OilBoxSplySts_Switch_Dual;
    /*0:Single Tank  1:Dual Tank*/
    uint8_t Fuel_Tank_System;
}IPC_M2S_ClusterAppAPPFUEL_t;

/* Transmit function of sub message FUEL */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPFUEL_Transmit(IPC_M2S_ClusterAppAPPFUEL_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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
    /*ָ�복��
    Vehicle Speed Calculated Metric:
    value range:0~260(1km/h) Invalid:0xEFFF(display 0);
    Vehicle Speed Calculated Imperial:
    value range:0~180(1mph) Invalid:0xEFFF(display 0)*/
    int32_t VehSpdAnalog;
}IPC_M2S_ClusterAppAPPSpeedo_t;

/* Transmit function of sub message Speedo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPSpeedo_Transmit(IPC_M2S_ClusterAppAPPSpeedo_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Tacho */
typedef struct
{
    /*Invalid:0xEFFF��display 0.0 rpm��*/
    int32_t EngSpdCalculated;
    /*engine speed max: 6000rpm or 8000rpm*/
    int32_t EngSpdMax;
    /*0: normal 1: red display;*/
    uint8_t RedDispaly;
    /*the running status of engine: 1:running; 0:stop;*/
    uint8_t EngRunningSts;
    /*ת�ٺ���ֵ 4500rpm or 6000/6300 rpm*/
    int32_t RedZoneThreshold;
    /*ָ��ת�� Invalid:0xEFFF��display 0.0 rpm��*/
    int32_t EngSpdAnalog;
    /*δ���˲���ת�� Invalid:0xEFFF��display 0.0 rpm��*/
    int32_t EngSpdReal;
}IPC_M2S_ClusterAppAPPTacho_t;

/* Transmit function of sub message Tacho */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPTacho_Transmit(IPC_M2S_ClusterAppAPPTacho_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Coolant */
typedef struct
{
    /*range value: 0~100%  Invalid:0xEFFF(display 0)*/
    int32_t EngCoolantTemp;
    /*1: Red display; 0:Normal display;*/
    uint8_t RedDispaly;
    /*ˮ��ʵ��ֵ  0-0xFF:Valid*/
    int32_t EngCoolantTempPhysValue;
    /*ˮ�º�����ֵ TBD δʹ��*/
    int32_t RedZoneThreshold;
}IPC_M2S_ClusterAppAPPCoolant_t;

/* Transmit function of sub message Coolant */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPCoolant_Transmit(IPC_M2S_ClusterAppAPPCoolant_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MenuSetting */
typedef struct
{
    /*set over speed(30~260km/h)/(20~180mph)*/
    uint16_t Sd_NaviLimitSpeed;
    /*0:OFF turn off over speed warning; 1:ON Turn on over speed warning;*/
    uint8_t Sd_OverSpeedEnable;
    /*������������
    0������
    1��Ӣ��
    2������
    3����������
    4����������
    5����������
    6������
    7������
    8���������
    9��̩��
    10���ڿ�����
    11��ӡ����*/
    uint8_t Sd_Language;
    /*������ʾģʽ
    0������ģʽ
    1���Ƽ�ģʽ
    2������ģʽ
    3������ģʽ
    4��ָ��ģʽ
    5��ԽҰģʽ
    6������ģʽ
    7����ģʽ
    8��SupSportģʽ*/
    uint8_t Sd_ClusterTheme;
    /*0:Normal Metric; 1:Janpan Metric; 2:Imperial UK; 3:Imperial US;*/
    uint8_t Sd_OdometerUnit;
    /*0:Celsius  ; 1:Fahrenheit*/
    uint8_t Sd_TemperatureUnit;
    /*0: kpa ; 1:psi ; 2:bar*/
    uint8_t Sd_TirePressureUnit;
    /*�����г�����ID ���Ǳ�HMI���忨ƬID�ײ������ע��*/
    uint8_t Sd_TripComputerId;
    /*���ý�����ƬID ���Ǳ�HMI���忨ƬID�ײ������ע��*/
    uint8_t Sd_InteractiveCarId;
    /*0: switch off  ; 1:switch on ; 2:Invalid*/
    uint8_t Sd_DrivingModeMemorySwitch;
    /*0:24 hours   ; 1:12 hours*/
    uint8_t Sd_TimeUnit;
    /*���ø��ٸ�������������Ϣ��reserved��*/
    uint8_t Sd_HighwayAssistSwitch;
    /*���ñ����������������Ϣ ��reserved��*/
    uint8_t Sd_LaneChangeAssistSwitch;
    /*0: Sunrise  ;   1:Sunset*/
    uint8_t Sd_SunriseSunset_Mode;
    /*0: Not Auto mode  ; 1: Auto mode*/
    uint8_t Sd_Auto_Mode;
    /*reserved*/
    uint8_t Sd_DrvgModeMemReq;
    /*���ü�ʻģʽ����
    0XE������ģʽ
    0XC����ģʽ*/
    uint8_t Sd_DrvingModReqHUT;
    /*������������״̬��0��������   1��������*/
    uint8_t Sd_Switch_ThemeLinkage_Sts;
    /*����ͬ����־*/
    uint8_t Sd_DataSyncFlg;
    /*��Χ����������״̬��0��������   1��������*/
    uint8_t Sd_AtmosphereLampLinkageSwt_Sts;
    /*ģ��������������״̬��0��������   1��������*/
    uint8_t Sd_SimSoundWaveLinkageSwt_Sts;
    /*è����������״̬��0���ر�   1���򿪣�*/
    uint8_t Sd_MaoCallLinkageSwt_Sts;
}IPC_M2S_ClusterAppAPPMenuSetting_t;

/* Transmit function of sub message MenuSetting */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPMenuSetting_Transmit(IPC_M2S_ClusterAppAPPMenuSetting_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TCClearResult */
typedef struct
{
    /*0x01:Success 0x0:failure*/
    uint8_t Result;
}IPC_M2S_ClusterAppAPPTCClearResult_t;

/* Transmit function of sub message TCClearResult */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPTCClearResult_Transmit(IPC_M2S_ClusterAppAPPTCClearResult_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ConfigData */
typedef struct
{
    /*Cconfig: Byte2 bit2
    0x0: Disable fast response;
    0x1: Enable fast response*/
    uint8_t Fast_Resp;
    /*Cconfig: Byte2 bit0 �˲���ֻ������ת����Ч*/
    uint16_t DigitalRPM_Hysteresis;
    /*Cconfig: Byte8 ����ˮ�±�C���¶�ֵ*/
    uint8_t GasolineCoolant_C_point;
    /*Cconfig: Byte9 ����ˮ�±�1/4���¶�ֵ*/
    uint8_t GasolineCoolant_14_point;
    /*Cconfig: Byte10 ����ˮ�±�1/2���¶�ֵ*/
    uint8_t GasolineCoolant_12_point1;
    /*Cconfig: Byte11 ����ˮ�±�1/2���¶�ֵ*/
    uint8_t GasolineCoolant_12_point2;
    /*Cconfig: Byte12 ����ˮ�±�3/4���¶�ֵ*/
    uint8_t GasolineCoolant_4_point;
    /*Cconfig: Byte13 ����ˮ�±����λ���¶�ֵ*/
    uint8_t GasolineCoolant_Redline_point;
    /*Cconfig: Byte14 ����ˮ�±�H���¶�ֵ*/
    uint8_t GasolineCoolant_H_point;
    /*Cconfig: Byte15 ����ˮ�±�C���¶�ֵ*/
    uint8_t DieselCoolant_C_point;
    /*Cconfig: Byte16 ����ˮ�±�1/4���¶�ֵ*/
    uint8_t DieselCoolant_14_point;
    /*Cconfig: Byte17 ����ˮ�±�1/2���¶�ֵ*/
    uint8_t DieselCoolant_12_point1;
    /*Cconfig: Byte18 ����ˮ�±�1/2���¶�ֵ*/
    uint8_t DieselCoolant_12_point2;
    /*Cconfig: Byte19 ����ˮ�±�3/4���¶�ֵ*/
    uint8_t DieselCoolant_34_point;
    /*Cconfig: Byte20 ����ˮ�±����λ���¶�ֵ*/
    uint8_t DieselCoolant_Redline_point;
    /*Cconfig: Byte21 ����ˮ�±�H���¶�ֵ*/
    uint8_t DieselCoolant_H_point;
    /*Cconfig: Byte126 bit7 ��������λ�ò���*/
    uint16_t Horizontal_data;
    /*Cconfig: Byte128 �������-8�׵�2.7����ռ�������ذٷֱ�*/
    uint8_t X;
    /*Cconfig: Byte129 �������0-100����ռ�������ذٷֱ�*/
    uint8_t Y;
    /*Cconfig: Byte135 bit7 ƽ������B��ʾʹ�ܱ�־*/
    uint8_t AVSBDisplayEnable;
    /*Cconfig: Byte135 bit6 ƽ������A��ʾʹ�ܱ�־*/
    uint8_t AVSADisplayEnable;
    /*Cconfig: Byte135 bit5 ��ʻʱ��A��ʾʹ�ܱ�־*/
    uint8_t TravelTimeADisplayEnable;
    /*Cconfig: Byte135 bit4 ��ʻʱ��B��ʾʹ�ܱ�־*/
    uint8_t TravelTimeBDisplayEnable;
    /*Cconfig: Byte145 bit3 ƽ���ͺ�A��ʾʹ�ܱ�־*/
    uint8_t AFCADisplayEnable;
    /*Cconfig: Byte145 bit2 ƽ���ͺ�B��ʾʹ�ܱ�־*/
    uint8_t AFCBDisplayEnable;
    /*Cconfig: Byte149 bit7 IFC��ʾʹ�ܱ�־*/
    uint8_t IFCDisplayEnable;
    /*Cconfig: Byte149 bit6 ���ֳ�����ʾʹ�ܱ�־*/
    uint8_t DigitalSpeedDisplayEnable;
    /*Cconfig: Byte173 bit7 PHEV���������ʾʹ�ܱ�־*/
    uint8_t PHEV_HEVDTEDisplayEnable;
    /*Cconfig: Byte174 PHEV�������������ʾ���ֵ*/
    uint8_t MaxDisplayPHEVRange;
    /*Cconfig: Byte181 bit7 PHEVSOC��ʾʹ�ܱ�־*/
    uint8_t PHEVSOCDisplayEnable;
    /*Cconfig: Byte182 bit7 PHEVSOC��������*/
    uint16_t RefreshRatePHEVSOC;
    /*Cconfig: Byte183 bit0 AvailablePower��ʾʹ�ܱ�־*/
    uint8_t AvailablePowerDisplayEnable;
    /*Cconfig: Byte184 AvailablePower���ֵ*/
    uint8_t MaxAvailablePower;
    /*Cconfig: Byte185 bit7 ƽ���ܺĸ�������*/
    uint16_t RefreshRateAvrgEgyCns;
    /*Cconfig: Byte186 bit0 ƽ���ܺ���ʾʹ�ܱ�־*/
    uint8_t AvrgEgyCnsDisplayEnable;
    /*Cconfig: Byte187 bit7 ƽ���ܺ����ֵ*/
    uint16_t MaxvalueAvrgEgyCns;
    /*Cconfig: Byte188 bit3 power��������*/
    uint16_t RefreshRatemotorpower;
    /*Cconfig: Byte190 bit7 ���������ʾʹ�ܱ�־*/
    uint8_t motorpowerDisplayEnable;
    /*Cconfig: Byte190 bit3 SOC��������*/
    uint16_t RefreshRateEVSOC;
    /*Cconfig: Byte181 bit7 PHEVSOC��ʾʹ�ܱ�־*/
    uint8_t EVSOCDisplayEnable;
    /*Cconfig: Byte192 bit3 EV DTE��������*/
    uint16_t RefreshRateEVDTE;
    /*Cconfig: Byte194 bit7 EV DTE��ʾʹ�ܱ�־*/
    uint8_t EVDTEDisplayEnable;
    /*Cconfig: Byte194 bit3 ����������ֵ*/
    uint16_t MaxvalueEVDTE;
    /*Cconfig: Byte196 bit7 EV ������������*/
    uint16_t RefreshRateCurrent;
    /*Cconfig: Byte197 bit0 EV ������ʾʹ�ܱ�־*/
    uint8_t EVCurrentDisplayEnable;
    /*Cconfig: Byte200 ��ʻ����A��λʱ������4Сʱ��*/
    uint8_t EVDrivDataARestTime;
    /*Cconfig: Byte201 bit7 ƽ�����ٸ�������*/
    uint16_t RefreshRateEVAVS;
    /*Cconfig: Byte203 ƽ������A/B��λ����ʾ��Чֵ�Ĺ�����*/
    uint8_t EVAVSMinDistanceThresh;
    /*Cconfig: Byte204 bit7 ƽ������A��ʾʹ�ܱ�־*/
    uint8_t EVAVSADisplayEnable;
    /*Cconfig: Byte204 bit6 ƽ������B��ʾʹ�ܱ�־*/
    uint8_t EVAVSBDisplayEnable;
    /*Cconfig: Byte205-209 EV��ʻʱ��A/B����ʾ�����ֵ��������ֵ��ת��00:00*/
    uint64_t EVTravelTimeDisplayLimited;
    /*Cconfig: Byte210 bit7 EV��ʻʱ��A��ʾʹ�ܱ�־*/
    uint8_t EVTravelTimeADisplayEnable;
    /*Cconfig: Byte210 bit6 EV��ʻʱ��B��ʾʹ�ܱ�־*/
    uint8_t EVTravelTimeBDisplayEnable;
    /*Cconfig: Byte228 �ſ���ʾ������ʾ����ֵ*/
    uint8_t DoortoRed_speedthreshold;
    /*Cconfig: Byte229 ���Ŵ���ʾ����ʱ��*/
    uint8_t Doorallclosed_holdtime;
    /*Cconfig: Byte232  7.x����7.y��ѯ��ʾλ��ָʾ�Ʊ������ʾʱ��*/
    uint8_t Telltale_interrupt_display_time;
    /*Cconfig: Byte233  7.x����7.y��ѯ��ʾλ��ָʾ����ѯ��ʾʱ��*/
    uint8_t Telltale_polling_display_time;
    /*Cconfig: Byte167 bit3 TPMS��ʾʹ�ܱ�־*/
    uint8_t TPMSDisplayEnable;
    /*Cconfig: Byte216 bit7 ODO��ʾʹ�ܱ�־*/
    uint8_t FIXEDDISPLAY_1_ODO_ENABLE;
    /*Cconfig: Byte210 bit1 ʱ����ʾʹ�ܱ�־*/
    uint8_t FD_003_CLOCK_ENABLE;
    /*Cconfig: Byte217 bit0 PS��ʻģʽ��ʾʹ�����*/
    uint8_t FD_009_DRIVE_MODE_2WD_ENABLE;
    /*Cconfig: Byte240 bit7 С�����A��ʾʹ��������*/
    uint8_t DrivDataADisplayEnable;
    /*Cconfig: Byte240 bit3 С�����B��ʾʹ��������*/
    uint8_t DrivDataBDisplayEnable;
    /*Cconfig: Byte241 �����߹����ٶ�1*/
    uint16_t Adas_V1;
    /*Cconfig: Byte243 �����߹����ٶ�2*/
    uint16_t Adas_V2;
    /*Cconfig: Byte245 ˮ�±��C�㵽H��ָʾʱ��*/
    uint8_t GasolineCoolant_Distime;
    /*Cconfig: Byte246 ˮ�±��C�㵽H��ָʾʱ��*/
    uint8_t DieselCoolant_Distime;
    /*Cconfig: Byte41 ȼ�ͱ��E��ָʾ��F���ָʾʱ��*/
    uint8_t Fuel_Distime;
    /*Cconfig: Byte266 bit3 ����Һλ���ܵĸ���Ƶ��*/
    uint16_t RefreshRateUrea;
    /*Cconfig: Byte285 ����gֵ����*/
    uint8_t GValue_Hysteresis;
    /*Cconfig: Byte286 bit7 gֵ����Ƶ��*/
    uint16_t GValue_update_frequency;
}IPC_M2S_ClusterAppAPPConfigData_t;

/* Transmit function of sub message ConfigData */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPConfigData_Transmit(IPC_M2S_ClusterAppAPPConfigData_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message VConfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPVConfig_Transmit(IPC_M2S_ClusterAppAPPVConfig_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MenuTheme */
typedef struct
{
    /*����ID��infra���������̳�ID��*/
    uint32_t ThemeID;
    /*Ƥ��ID��infra���������̳�ID��*/
    uint32_t SkinID;
}IPC_M2S_ClusterAppAPPMenuTheme_t;

/* Transmit function of sub message MenuTheme */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPMenuTheme_Transmit(IPC_M2S_ClusterAppAPPMenuTheme_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: DriveMode */
typedef struct
{
    union
    {
        uint8_t u8DriveMode_data[6];
        struct
        {
            /*��ʻģʽͼ��-��ʻģʽ�ź�ֵ(��Ӧ��ʾ��ͬͼ��)
            value: case��codeֵ�϶࣬����μ��̶���ʾSRS�ĵ�*/
            uint8_t DriveMode_Value                         :8;
            /*self check: 0~no self check ;1~self check ������reserve*/
            uint8_t DriveMode_Data_selfcheck                :1;
            /*��ʻģʽͼ��-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz ����:reserve*/
            uint8_t DriveMode_Data                          :3;
            /*self check: 0~no self check ;1~self check ������reserve*/
            uint8_t HybridMode_Data_selfcheck               :1;
            /*����ģʽͼ��-ָʾ��״̬
            Status : 0:off  1:on  2:1hz  3:2hz  4:4hz ����:reserve*/
            uint8_t HybridMode_Data                         :3;
            /*����ģʽͼ��-����ģʽ�ź�ֵ(��Ӧ��ʾ��ͬͼ��)
            value:codeֵ�μ��̶���ʾSRS�ĵ�*/
            uint8_t HybridMde_Value                         :8;
            /*��ʻģʽ�л��ź�ֵ��KL15 ON 3s�ڷ���Чֵ 0x3F��KL15 ON 3s��Ϊʵ���ź�ֵ���ο�chime SRS�ĵ��½�1.36~1.39  
            ���䣺��ʻģʽ�л��źų�ʱ���ᱣ��֮ǰ��ֵ*/
            uint8_t DrvModSignal_Value                      :6;
            /*ȼ�ͳ���ʻģʽ-�Զ�ģʽ�л��ź�ֵ��KL5 ON 3s�ڷ���Чֵ0x3��KL5 ON 3s�� 0x0 not Auto��0x1 Auto
            ���䣺IMC_Actv�źų�ʱ���ᱣ��֮ǰ��ֵ���������ò����ã����źŲ���ʹ�ã�����Чֵ0x3*/
            uint8_t IMCActvSignal_Value                     :2;
            /*0x0��None; 
            0x1:  Fuel or PAPA2; 
            0x2:  PHEV/HEV+PS/PS_P4;  
            0x3:  PHEV+P2;
            0x4��EV*/
            uint8_t DrvModVehType                           :4;
            /*0(km/h(metric)), 1(mph(Imperial))*/
            uint8_t DM_individuation_spd_unit               :1;
            /*���������ݶ���*/
            uint8_t Reserved                                :3;
            /*0x0-0x3B��---km/h��---mph��0x3C-0x96��xxxkm/h��xxxmph��0x97-0xff��---km/h��---mph*/
            uint8_t DM_individuation_spd_value              :8;
        }s_u8DriveMode_data_t;
    }u_DriveModeu8DriveMode_data_t;
}IPC_M2S_ClusterAppAPPDriveMode_t;

/* Transmit function of sub message DriveMode */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPDriveMode_Transmit(IPC_M2S_ClusterAppAPPDriveMode_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: WN_Data */
typedef struct
{
    /*����Ѳ���ٶ�ֵ Value��0-240 km/h  0-150 mph*/
    uint8_t WN_TgtCrsSpd;
    /*����Ѳ���ٶ���Ч��  Value: 0~Invalid 1~Valid*/
    uint8_t WN_TgtCrsSpdVldSts;
    /*��ʻģʽ����ֵ Value:1-5 ~ Drive Mode case1-case5*/
    uint8_t WN_DrvModeCaseValue;
    /*�Զ�����������ʻ�������� Value:0-0xFFFF*/
    uint16_t WN_NOHDist;
}IPC_M2S_ClusterAppAPPWN_Data_t;

/* Transmit function of sub message WN_Data */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPWN_Data_Transmit(IPC_M2S_ClusterAppAPPWN_Data_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NewEnergy */
typedef struct
{
    union
    {
        uint32_t u32NewEnergy_data[4];
        struct
        {
            /*0xEFFE:not display ;offset:-100
            1.21~ 1.22 ����ָʾ��ʾ - ����ָʾ*/
            uint32_t PowerPointer                           :16;
            /*0xEFFE:not display ;Resolution:0.1
            1.21 ����ָʾ��ʾ( HEV +PHEV ) - ���ù���*/
            uint32_t AvailPower                             :16;
            /*1:red;2:yellow;3:green;4:Gray
            1.20 PHEV ������ص��� SOC ��ʾ (PHEV)- ��ɫ״̬ */
            uint32_t PowerBattery_Status                    :8;
            /*uint:%
            1.20 PHEV ������ص��� SOC ��ʾ (PHEV)- �ٷֱ�*/
            uint32_t PowerBattery_Percent                   :8;
            /*0xEFFE:not display ;value = (N)*0.1-10
            1.23 ��ʻЧ����ʾ ( HEV+PHEV ) (����ָ��)*/
            uint32_t DriveHabit                             :16;
            /*0xFE:not display;0xFF:display --h--min
            1.25 Ԥ�Ƴ��ʱ����ʾ(PHEV) - Сʱ*/
            uint32_t ChrgTime_Hour                          :8;
            /*0xFE:not display;0xFF:display --h--min
            1.25 Ԥ�Ƴ��ʱ����ʾ(PHEV) - ����*/
            uint32_t ChrgTime_Min                           :8;
            /*0xEFFE:not display;0xFFFF:display ---A; offset: -1000
            1.24 ���״̬��ʾ(PHEV) - ��������ʾ*/
            uint32_t ChargeCurrent                          :16;
            /*0xFE:���״̬���ֲ���ʾ; 0xFF:���״̬��Ƭ����ʾ
            other value:�ο�����TC�����ĵ�������һ�о�
            1.24 ���״̬��ʾ(PHEV) - lcd���״̬��ʾ*/
            uint32_t ChargeStatus                           :8;
            /*0xFE:not display��0xFF����ʾ����ʱ�޷���ȡ��������Ϣ��
            other value:�ο�����TC�����ĵ�������һ�о�
            1.18 ��������ʾ*/
            uint32_t EnergyFlow_Data                        :8;
            /*�����ȶ���״̬��
            0x0: �Ͽ�״̬;
            0x1: ��Ԥ�ڶϿ�״̬;
            0x2: ����״̬;
            other: ��Чֵ*/
            uint32_t ElectronicStabilizerBar_Status         :8;
            /*���벹��λ���¼�ʱ����ʹ��*/
            uint32_t Reserved                               :8;
        }s_u32NewEnergy_data_t;
    }u_NewEnergyu32NewEnergy_data_t;
}IPC_M2S_ClusterAppAPPNewEnergy_t;

/* Transmit function of sub message NewEnergy */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPNewEnergy_Transmit(IPC_M2S_ClusterAppAPPNewEnergy_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: NewEnergy_EV */
typedef struct
{
    union
    {
        uint32_t u32NewEnergy_EV_data[6];
        struct
        {
            /*1.27 ƽ���ܺ�ָʾ��EV��
            0xFFFF display dash 
            factor:10, eg 987=98.7kWh/100km
            ;0xFFFE :Disable display */
            uint32_t AEC                                    :16;
            /*ƽ���ܺĵ�λ:
            0:kWh/100km, 1:Wh/mi*/
            uint32_t AEC_Unit                               :8;
            /*1.39 ����ָ��ָʾ (EV)
            0x0:Nodisplay
            0x1~0x5:Valid value
            Offset:-5
            eg�� 0x1 = -4, 0x5 = 0*/
            uint32_t ECODrvHabit                            :8;
            /*1.28 �������ָʾ����ɫ��
            0x0:Not display
            0x01:Green
            0x02:White
            0x03:Red*/
            uint32_t EV_MotorPower_Status                   :8;
            /*1.28 �������ָʾ��kw���ֶ�������
            ������value = 0~400,offset: -200;  
            ������value = 0~2000,offset: -1000;  
            0xFFFE:Not Display��0xFFFF:Display--*/
            uint32_t EV_MotorPower_Percent                  :16;
            /*1.31 ������ָʾ��������ٷֱȣ�
            0xFF:Display"--" 0xFE:Not DIsplay; Range:0~100; scale:1 offset:0*/
            uint32_t EV_Soc_Value                           :8;
            /*1.31 ������ָʾ����������ɫ��
            0:Normal  1:Red  2:Gray*/
            uint32_t EV_SOC_Color                           :8;
            /*1.40 ���״ָ̬ʾ��������ʾ��
            0:None  1:�����     2:ԤԼ���      3:������     4:�����ֹͣ 5:�������Ԥ���� 6:������*/
            uint32_t EV_Charge_Status                       :8;
            /*1.40 ���״ָ̬ʾ����������
            0xFFFF:Display"--"  0xFFFE:Not Display  Range:-800~800; scale:1 offset:-800  unit:A*/
            uint32_t EV_Charge_Cur                          :16;
            /*1.30 Ԥ�Ƴ��ʱ����ʾ(EV) - Сʱ"
            "0xFE:not display;0xFF:display --h--min*/
            uint32_t EV_ChargeTimeHour                      :8;
            /*1.30 Ԥ�Ƴ��ʱ����ʾ(EV)  - ����"
            "0xFE:not display;0xFF:display --h--min*/
            uint32_t EV_ChargeTimeMin                       :8;
            /*1.34 �������ָʾ(EV)
            0xFFFF:Display--"  0xFFFE:Not Display; Range:0~9999; scale:1 offset::0  */
            uint32_t EV_Charge_SOCVlaue                     :8;
            /*1.40 ���״̬��ʾ   ; 
            0:���ǹ���Ч��; 1:���߳��״̬Ч��    */
            uint32_t EV_Charge_Interface                    :8;
            /*1.34 �������ָʾ(EV)
            0xFFFF:Display--"  0xFFFE:Not Display; Range:0~9999; scale:1 offset::0  unit:KM"*/
            uint32_t EV_DrvRng                              :16;
            /*1.58 ��������ʾ(EV)
            0x0:����ʾ
            0x1:������ֹ/����������״̬
            0x2:������ʻ������   ��ذ���ǰ�������
            0x3:��������������   ǰ�����������ذ�
            0x4:��ذ�������״̬������
            0x5:��ʾ�߳��߼���״̬������
            0x6:�����״̬������ 
            0x7:ǰ�� �ŵ�״̬������ 
            0x8:����ǰ�����Ͳ���ʾ���� ����
            0x9: ������ʻ������  ��ذ������������
            0xa: �������������� �������������ذ�
            0xb:�����ŵ�״̬������ 
            0xc: ������ʻ������ ��ذ��� ǰ/���������
            0xd: ��������������  ǰ/�������������ذ�
            0xe:���� �ŵ�״̬������ */
            uint32_t EV_EnergyFlow_Value                    :8;
            /*1.59 ��ѩ��ģʽ
            0x0:No Scenario Mode
            0x1:Rain and Snow Weather Mode*/
            uint32_t EV_RainsSnowMode                       :8;
            /*1.32������ָʾ(off��������ɫ)
            0:Gren  1:Red  2:Yellow*/
            uint32_t EV_Charge_SOCColor                     :8;
            /*1.34 �������ָʾ��λ(EV)
            0: DTE-KM ,  1:DTE-MILES*/
            uint32_t EV_DrvRng_Unit                         :8;
        }s_u32NewEnergy_EV_data_t;
    }u_NewEnergy_EVu32NewEnergy_EV_data_t;
}IPC_M2S_ClusterAppAPPNewEnergy_EV_t;

/* Transmit function of sub message NewEnergy_EV */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPNewEnergy_EV_Transmit(IPC_M2S_ClusterAppAPPNewEnergy_EV_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: OffroadInfo */
typedef struct
{
    /*����ѹ���ݣ�0~1500hpa valid;
                       other  invalid;*/
    uint16_t Sd_BaroPressure;
    /*���θ߶����ݣ�0x00~0x1FFE ��0~8190m��*/
    uint16_t Sd_Heilvl;
    /*������ʾ���
    0������
    1������*/
    uint8_t Sd_HeilvlSign;
    /*�¶����ݣ�0~90��*/
    uint8_t Sd_PitchAngle;
    /*�¶���ʾ���
    0������
    1������*/
    uint8_t Sd_PitchAngleSign;
    /*ָ���뷽�����ݣ�0~7��8����λ��*/
    uint8_t Sd_GeoGraphic;
    /*����ת��Ƕȣ�0x00~0x2B  ��0~43�㣩*/
    uint8_t Sd_SteerWheel;
    /*����ת����ʾ���
    0������
    1������*/
    uint8_t Sd_SteerWheelSign;
}IPC_M2S_ClusterAppAPPOffroadInfo_t;

/* Transmit function of sub message OffroadInfo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppAPPOffroadInfo_Transmit(IPC_M2S_ClusterAppAPPOffroadInfo_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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
    /*0:Engine is stop;1��Engine is runing*/
    uint8_t EngineSts;
}IPC_M2S_ClusterAppSystemBootCondition_t;

/* Transmit function of sub message BootCondition */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemBootCondition_Transmit(IPC_M2S_ClusterAppSystemBootCondition_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ADASConfig */
typedef struct
{
    /*1 = on , 0 = off*/
    uint8_t HighwayAssistSwitch;
    /*1 = on , 0 = off*/
    uint8_t LaneChangeAssistSwitch;
}IPC_M2S_ClusterAppSystemADASConfig_t;

/* Transmit function of sub message ADASConfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemADASConfig_Transmit(IPC_M2S_ClusterAppSystemADASConfig_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Transmit function of sub message CLUSTERPOWER */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemCLUSTERPOWER_Transmit(IPC_M2S_ClusterAppSystemCLUSTERPOWER_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: CommonAppMsgUploaded */
typedef struct
{
    /*0xBB:Data send complete��other��reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t;

/* Transmit function of sub message CommonAppMsgUploaded */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemCommonAppMsgUploaded_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: IPCDebugTest */
typedef struct
{
    /*0x0: ON��0x1: OFF��other��reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemIPCDebugTest_t;

/* Transmit function of sub message IPCDebugTest */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemIPCDebugTest_Transmit(IPC_M2S_ClusterAppSystemIPCDebugTest_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: InterfaceAppMsgUploaded */
typedef struct
{
    /*0xBB: Data send complete, other: reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t;

/* Transmit function of sub message InterfaceAppMsgUploaded */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemInterfaceAppMsgUploaded_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: GaugeMsgUploaded */
typedef struct
{
    /*0xBB: Data send complete, other: reserved*/
    uint8_t Status;
}IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t;

/* Transmit function of sub message GaugeMsgUploaded */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppSystemGaugeMsgUploaded_Transmit(IPC_M2S_ClusterAppSystemGaugeMsgUploaded_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t CSA3_244_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t PageUpSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageUpSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t PageDwnSwtSts_Sts_Flag                 :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageDwnSwtSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t PageLSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageLSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t PageRSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t PageRSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t EnterSwtSts_Sts_Flag                   :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t EnterSwtSts                            :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t HomeSwtSts_Sts_Flag                    :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t HomeSwtSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t MenuReturnSwtSts_Sts_Flag              :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t MenuReturnSwtSts                       :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t CustomSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t CustomSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t AdjVolDwnSwtSts_Sts_Flag               :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t AdjVolDwnSwtSts                        :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t AdjVolUpSwtSts_Sts_Flag                :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t AdjVolUpSwtSts                         :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t SeekDwnSwtSts_Sts_Flag                 :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t SeekDwnSwtSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t SeekUpSwtSts_Sts_Flag                  :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t SeekUpSwtSts                           :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t EnterSwtSts_Mmed_Sts_Flag              :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t EnterSwtSts_Mmed                       :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t VRSwtSts_Sts_Flag                      :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t VRSwtSts                               :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t MuteSwtSts_Sts_Flag                    :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t MuteSwtSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t CustomSwtSts_Mmed_Sts_Flag             :1;
            /*0x0:Released;0x1:Pressed;0x2:Error;0x3:Invalidation;*/
            uint32_t CustomSwtSts_Mmed                      :2;
        }s_CSA3_244_Inf_1_t;
    }u_CSA3_244CSA3_244_Inf_1_t;
}IPC_M2S_ClusterAppCANAdaptCSA3_244_t;

/* Transmit function of sub message CSA3_244 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptCSA3_244_Transmit(IPC_M2S_ClusterAppCANAdaptCSA3_244_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: EEM1_2A8 */
typedef struct
{
    union
    {
        uint8_t EEM1_2A8_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t EEM1_2A8_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t Stat_PwrSv_Lvl_Sts_Flag                 :1;
            /*0x0:Normal;0x1:Level1;0x2:Level2;0x3-0x7:Reserve*/
            uint8_t Stat_PwrSv_Lvl                          :3;
        }s_EEM1_2A8_Inf_t;
    }u_EEM1_2A8EEM1_2A8_Inf_t;
}IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t;

/* Transmit function of sub message EEM1_2A8 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptEEM1_2A8_Transmit(IPC_M2S_ClusterAppCANAdaptEEM1_2A8_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ESP2_145 */
typedef struct
{
    union
    {
        uint8_t ESP2_145_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t ESP2_145_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message ESP2_145 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptESP2_145_Transmit(IPC_M2S_ClusterAppCANAdaptESP2_145_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ESP2_137 */
typedef struct
{
    union
    {
        uint16_t ESP2_137_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t ESP2_137_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t ESPBrkLmpCtrl_137_Sts_Flag             :1;
            /*0x0:Brake light off
            0x1:Brake light on*/
            uint16_t ESPBrkLmpCtrl_137                      :1;
        }s_ESP2_137_Inf_t;
    }u_ESP2_137ESP2_137_Inf_t;
}IPC_M2S_ClusterAppCANAdaptESP2_137_t;

/* Transmit function of sub message ESP2_137 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptESP2_137_Transmit(IPC_M2S_ClusterAppCANAdaptESP2_137_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HUD1_325 */
typedef struct
{
    union
    {
        uint32_t HUD1_325;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t HUD1_325_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t HUD_UIMod_Sts_Flag                     :1;
            /*0x0:Normal Mode
            0x1:Dot Matrix Mode*/
            uint32_t HUD_UIMod                              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t HUD_UIModVld_Sts_Flag                  :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint32_t HUD_UIModVld                           :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t HUD_SwtSts_Sts_Flag                    :1;
            /*0x0:OFF
            0x1:ON*/
            uint32_t HUD_SwtSts                             :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message HUD1_325 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptHUD1_325_Transmit(IPC_M2S_ClusterAppCANAdaptHUD1_325_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ECM3_371 */
typedef struct
{
    union
    {
        uint16_t ECM3_371_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t ECM3_371_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t BaroPressure_Sts_Flag                  :1;
            /*0x00-0xFE:Valid values
            0xFF:Invalid value*/
            uint16_t BaroPressure                           :8;
        }s_ECM3_371_Inf_t;
    }u_ECM3_371ECM3_371_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM3_371_t;

/* Transmit function of sub message ECM3_371 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptECM3_371_Transmit(IPC_M2S_ClusterAppCANAdaptECM3_371_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: CSA2_A1 */
typedef struct
{
    union
    {
        uint32_t CSA2_A1_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t CSA2_A1_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t SAS_Sts_Flag                           :1;
            /*0x0:SAS Angle And Speed Correct
            0x1:SAS Not Calibrated
            0x2:Intermittent Error Detected
            0x3:Permanent Error Detected*/
            uint32_t SAS_Sts                                :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t SteerWheelAngSign_Sts_Flag             :1;
            /*0x0:Left (Positive);0x1:Right (Negative)*/
            uint32_t SteerWheelAngSign                      :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t SteerWheelAng_Sts_Flag                 :1;
            /*0x0000-0x1E78:Valid value
            0x1E79-0x7FFE:Reserved
            0x7FFF:Invalid*/
            uint32_t SteerWheelAng                          :15;
        }s_CSA2_A1_Inf_t;
    }u_CSA2_A1CSA2_A1_Inf_t;
}IPC_M2S_ClusterAppCANAdaptCSA2_A1_t;

/* Transmit function of sub message CSA2_A1 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptCSA2_A1_Transmit(IPC_M2S_ClusterAppCANAdaptCSA2_A1_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ECM16_2D4 */
typedef struct
{
    union
    {
        uint64_t ECM16_2D4_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint64_t ECM16_2D4_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t SCRSysWarnDisplay_Sts_Flag             :1;
            /*0x0:No warn����ʾ(Ĭ��ֵ)
            0x1:Urea level low����Һλ��,���ע
            0x2:Urea level tool low����Һλ����,���ע
            0x3:Empty tank,next start prohibit���ع޿�,��ֹ�´�����
            0x4:Incorrect urea���ز��ϸ�,����
            0x5:Incorrect urea over limit dist ���ز��ϸ���ʻ����50km
            0x6:Urea fill intercept,please refill���ؼ�ע��ֹ,�����¼�ע
            0x7:Urea fill intercept over limit dist���ؼ�ע��ֹ��ʻ����50km
            0x8:Engine start prohibit����ϵͳ��ֹ����������
            0x9:SCR system fault,please check����ϵͳ����,����վ���
            0xA:SCR system fault over limit Dist����ϵͳ������ʻ����50km
            0xB:Driving dist over limition with fault, next start prohibit����ϵͳ���Ͻ�ֹ�´�����
            0xC-0xF:Reserved*/
            uint64_t SCRSysWarnDisplay                      :4;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t UreaRemainDist_Sts_Flag                :1;
            /*0x000-0xFFF:Valid value
            */
            uint64_t UreaRemainDist                         :12;
        }s_ECM16_2D4_Inf_t;
    }u_ECM16_2D4ECM16_2D4_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM16_2D4_t;

/* Transmit function of sub message ECM16_2D4 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptECM16_2D4_Transmit(IPC_M2S_ClusterAppCANAdaptECM16_2D4_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: AC2_385 */
typedef struct
{
    union
    {
        uint16_t AC2_385_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t AC2_385_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t ACAmbTemp_Sts_Flag                     :1;
            /*0x00-0xFD:Valid value
            0xFE:Initial value
            0xFF:Invalid Value*/
            uint16_t ACAmbTemp                              :8;
        }s_AC2_385_Inf_t;
    }u_AC2_385AC2_385_Inf_t;
}IPC_M2S_ClusterAppCANAdaptAC2_385_t;

/* Transmit function of sub message AC2_385 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptAC2_385_Transmit(IPC_M2S_ClusterAppCANAdaptAC2_385_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ECM_PT6_290 */
typedef struct
{
    union
    {
        uint32_t ECM_PT6_290_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t ECM_PT6_290_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t TrqPrct_Sts_Flag                       :1;
            /*0x00-0x64:Valid value
            0x65-0x7F:Reserve*/
            uint32_t TrqPrct                                :7;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t PowerPrct_Sts_Flag                     :1;
            /*0x00-0x64:Valid value
            0x65-0x7F:Reserve*/
            uint32_t PowerPrct                              :7;
        }s_ECM_PT6_290_Inf_t;
    }u_ECM_PT6_290ECM_PT6_290_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t;

/* Transmit function of sub message ECM_PT6_290 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptECM_PT6_290_Transmit(IPC_M2S_ClusterAppCANAdaptECM_PT6_290_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ABM2_245 */
typedef struct
{
    union
    {
        uint64_t ABM2_245_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint64_t ABM2_245_MSG_TimeoutFlag               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t VehLgtAccelVld_Sts_Flag                :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint64_t VehLgtAccelVld                         :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t VehLatAccelVld_Sts_Flag                :1;
            /*0x0:Invalid
            0x1:Valid*/
            uint64_t VehLatAccelVld                         :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t VehLgtAccel_Sts_Flag                   :1;
            /*0x0000-0xAC22:Valid Value
            0xAC23-0xFFFF:Reserved*/
            uint64_t VehLgtAccel                            :16;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t VehLatAccel_Sts_Flag                   :1;
            /*0x0000-0xAC22:Valid Value
            0xAC23-0xFFFF:Reserved*/
            uint64_t VehLatAccel                            :16;
        }s_ABM2_245_Inf_t;
    }u_ABM2_245ABM2_245_Inf_t;
}IPC_M2S_ClusterAppCANAdaptABM2_245_t;

/* Transmit function of sub message ABM2_245 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptABM2_245_Transmit(IPC_M2S_ClusterAppCANAdaptABM2_245_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: RSDS_FD1_16F */
typedef struct
{
    union
    {
        uint16_t RSDS_FD1_16F_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t RSDS_FD1_16F_MSG_TimeoutFlag           :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t BSD_LCA_warningReqRight_Sts_Flag       :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t BSD_LCA_warningReqRight                :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t BSD_LCA_warningReqleft_Sts_Flag        :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t BSD_LCA_warningReqleft                 :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t DOW_warningReqRight_Sts_Flag           :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t DOW_warningReqRight                    :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t DOW_warningReqleft_Sts_Flag            :1;
            /*0x0:No warning
            0x1:Warning level 1
            0x2:Warning level 2
            0x3:Reserved*/
            uint16_t DOW_warningReqleft                     :2;
        }s_RSDS_FD1_16F_Inf_t;
    }u_RSDS_FD1_16FRSDS_FD1_16F_Inf_t;
}IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t;

/* Transmit function of sub message RSDS_FD1_16F */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_Transmit(IPC_M2S_ClusterAppCANAdaptRSDS_FD1_16F_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: IFC_FD5_19F */
typedef struct
{
    union
    {
        uint32_t IFC_FD5_19F_Inf_1;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t IFC_FD5_19F_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Line01_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line01_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Line02_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line02_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Line03_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line03_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Line04_Dy_Sts_Flag                 :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Line04_Dy                          :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Roadedge01_Dy_Sts_Flag             :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Roadedge01_Dy                      :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t IFC_Roadedge02_Dy_Sts_Flag             :1;
            /*0x0-0x1771:Valid value
            0x1772-0x1FFF:Reversed*/
            uint32_t IFC_Roadedge02_Dy                      :13;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line01_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line01_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line02_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line02_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line04_CurvChange_Sts_Flag         :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Line04_CurvChange                  :20;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Roadedge01_CurvChange_Sts_Flag     :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Roadedge01_CurvChange              :20;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Roadedge02_CurvChange_Sts_Flag     :1;
            /*0x0-0XEA600:Valid value
            0xEA601-0xFFFFF:Reversed*/
            uint64_t IFC_Roadedge02_CurvChange              :20;
        }s_IFC_FD5_19F_Inf_9_t;
    }u_IFC_FD5_19FIFC_FD5_19F_Inf_9_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t;

/* Transmit function of sub message IFC_FD5_19F */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD5_19F_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: IFC_FD6_222 */
typedef struct
{
    union
    {
        uint64_t IFC_FD6_222_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint64_t IFC_FD6_222_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line01_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line01_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line02_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line02_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line03_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line03_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line04_HeadingAngle_Sts_Flag       :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Line04_HeadingAngle                :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Roadedge01_HeadingAngle_Sts_Flag   :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Roadedge01_HeadingAngle            :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Roadedge02_HeadingAngle_Sts_Flag   :1;
            /*0x0-0x191:valid value
            0x192-0x1FF:reversed*/
            uint64_t IFC_Roadedge02_HeadingAngle            :9;
        }s_IFC_FD6_222_Inf_t;
    }u_IFC_FD6_222IFC_FD6_222_Inf_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t;

/* Transmit function of sub message IFC_FD6_222 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD6_222_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ACC_FD2_2AB */
typedef struct
{
    union
    {
        uint32_t ACC_FD2_2AB_Inf_1;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t ACC_FD2_2AB_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_PotentialTgtDy_Sts_Flag            :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_PotentialTgtDy                     :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_PotentialTgtHeading_Sts_Flag       :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_PotentialTgtHeading                :6;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RlvTgtDy_Sts_Flag                  :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_RlvTgtDy                           :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RlvTgtHeading_Sts_Flag             :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_RlvTgtHeading                      :6;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTgtDy_Sts_Flag                   :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_LeTgtDy                            :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTgtHeading_Sts_Flag              :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_LeTgtHeading                       :6;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTgtDy_Sts_Flag                   :1;
            /*0x0-0xA0:Valid value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_RiTgtDy                            :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTgtHeading_Sts_Flag              :1;
            /*0x0-0x3C:valid value
            0x3D-0x3F:Reserved*/
            uint32_t ACC_RiTgtHeading                       :6;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTgt_02_Dy_Sts_Flag               :1;
            /*0x0-0x51:Valid value
            0x52-0x7F:Reserved*/
            uint32_t ACC_LeTgt_02_Dy                        :7;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTargrt_02_Detn_Sts_Flag          :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_LeTargrt_02_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTargrt_02_Detn_Sts_Flag          :1;
            /*0x0:Not dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RiTargrt_02_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t TJA_ICA_ModDisp_Sts_Flag               :1;
            /*0x0:OFF mode
            0x1:Passive mode
            0x2:Active mode
            0x3:Ready mode
            0x4:Failure
            0x5-0x7:Reserved  */
            uint32_t TJA_ICA_ModDisp                        :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_TgtObjBarDisp_Sts_Flag             :1;
            /*0x0:No display
            0x1:Distance_1 one bar
            0x2:Distance_2 two bars
            0x3:Distance_3 three bars
            0x4:Distance_4 four bars
            0x5-0x7:Resvered*/
            uint32_t ACC_TgtObjBarDisp                      :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_FctSts_Sts_Flag                    :1;
            /*0x0:Fuction Not  Available
            0x1:Fuction Available 
            0x2:Performance degradation
            0x3:Reserved*/
            uint32_t ACC_FctSts                             :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t Request_driveoff_Sts_Flag              :1;
            /*0x0:no request
            0x1:The front car has started
            0x2:The front car has started,Please pay attention to the road environment ahead
            0x3:The front car has started,please keep your attention
            0x4:The front car has started,please take over the car
            0x5-0x7:Reserved*/
            uint32_t Request_driveoff                       :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t HWA_LaneChange_Sts_Flag                :1;
            /*0x0:No display 
            0x1:left 
            0x2:right
            0x3:reserved*/
            uint32_t HWA_LaneChange                         :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t HWA_Resp_Sts_Flag                      :1;
            /*0x0: OFF
            0X1: ON*/
            uint64_t HWA_Resp                               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ALC_Resp_Sts_Flag                      :1;
            /*0x0:OFF
            0X1:ON*/
            uint64_t ALC_Resp                               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_EgoStatus_Sts_Flag                 :1;
            /*0x0:No Display
            0x1:Override
            0x2:Deceleration
            0x3:Reserved*/
            uint64_t ACC_EgoStatus                          :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_SpdSetValue_Sts_Flag               :1;
            /*0x00-0xFE:Valid value
            0xFF:No display*/
            uint64_t ACC_SpdSetValue                        :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_TimeGapSet_Sts_Flag                :1;
            /*0x0:No display
            0x1:TimeGap_1 1s
            0x2:TimeGap_2 1.4s
            0x3:TimeGap_3 1.8s
            0x4:TimeGap_4 2.1s
            0x5-0x7:Reserved*/
            uint64_t ACC_TimeGapSet                         :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_PotentialTgtDx_Sts_Flag            :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_PotentialTgtDx                     :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_RlvTgtDx_Sts_Flag                  :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RlvTgtDx                           :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_LeTgtDx_Sts_Flag                   :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_LeTgtDx                            :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_RiTgtDx_Sts_Flag                   :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RiTgtDx                            :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_LeTgt_02_Dx_Sts_Flag               :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_LeTgt_02_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t ACC_RiTgt_02_Dx_Sts_Flag               :1;
            /*0x0-0x12C:Valid value
            0x12D-0x1FF:Reserved*/
            uint64_t ACC_RiTgt_02_Dx                        :9;
        }s_ACC_FD2_2AB_Inf_9_t;
    }u_ACC_FD2_2ABACC_FD2_2AB_Inf_9_t;
}IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t;

/* Transmit function of sub message ACC_FD2_2AB */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_Transmit(IPC_M2S_ClusterAppCANAdaptACC_FD2_2AB_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: IFC_FD2_23D */
typedef struct
{
    union
    {
        uint16_t IFC_FD2_23D_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t IFC_FD2_23D_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t TJA_FollowSts_Sts_Flag                 :1;
            /*0x0:No Follow
            0x1:Follow Vehicle
            0x2-0x3:Reserved*/
            uint16_t TJA_FollowSts                          :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t IntelligentEvaActSts_Sts_Flag          :1;
            /*0x0:Inactive
            0x1:Left Eva
            0x2:Right Eva
            0x3:Reserved*/
            uint16_t IntelligentEvaActSts                   :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t LaneAvailability_Sts_Flag              :1;
            /*0x0:not avaliable
            0x1:left lane marker available
            0x2:right lane marker available
            0x3:both lane marker available*/
            uint16_t LaneAvailability                       :2;
        }s_IFC_FD2_23D_Inf_t;
    }u_IFC_FD2_23DIFC_FD2_23D_Inf_t;
}IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t;

/* Transmit function of sub message IFC_FD2_23D */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD2_23D_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: AEB_FD2_227 */
typedef struct
{
    union
    {
        uint32_t AEB_FD2_227_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t AEB_FD2_227_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t FCW_Warn_Sts_Flag                      :1;
            /*0x0:No warning
            0x1:Latent warning 
            0x2:warning Level 1  
            0x3:warning Level 2*/
            uint32_t FCW_Warn                               :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t AEB_VehTrig_Sts_Flag                   :1;
            /*0x0:not tirggered
            0x1:triggered*/
            uint32_t AEB_VehTrig                            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t AEB_PedTrig_Sts_Flag                   :1;
            /*0x0:not tirggered
            0x1:triggered*/
            uint32_t AEB_PedTrig                            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t AEB_JABrkTrig_Sts_Flag                 :1;
            /*0x0:Not tirggered
            0x1:AEB_JA Function Triggered for vehicle
            0x2:AEB_JA Function Triggered for pedestrian
            0x3:reverse*/
            uint32_t AEB_JABrkTrig                          :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTgt_03_Typ_Sts_Flag              :1;
            /*0x0:Unkown
            0x1:Sedan
            0x2:Truck*/
            uint32_t ACC_RiTgt_03_Typ                       :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTargrt_03_Detn_Sts_Flag          :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_RiTargrt_03_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTgt_03_Dx_Sts_Flag               :1;
            /*0x0_0x190:Valid_value
            0x191_0x1FF:Reserved*/
            uint32_t ACC_RiTgt_03_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_RiTgt_03_Dy_Sts_Flag               :1;
            /*0x0_0xA0:Valid_value
            0xA1_0xFF:Reserved*/
            uint32_t ACC_RiTgt_03_Dy                        :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTargrt_03_Detn_Sts_Flag          :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_LeTargrt_03_Detn                   :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTgt_03_Dx_Sts_Flag               :1;
            /*0x0_0x190:Valid_value
            0x191_0x1FF:Reserved*/
            uint32_t ACC_LeTgt_03_Dx                        :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_LeTgt_03_Dy_Sts_Flag               :1;
            /*0x0_0xA0:Valid_value
            0xA1_0xFF:Reserved*/
            uint32_t ACC_LeTgt_03_Dy                        :8;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_PotentialTgt_02_Heading_Sts_Flag   :1;
            /*0x0_0x3C:Valid_value
            0x3D_0x3F:Reserved*/
            uint32_t ACC_PotentialTgt_02_Heading            :6;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_PotentialTgt_02_Detn_Sts_Flag      :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint32_t ACC_PotentialTgt_02_Detn               :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t ACC_PotentialTgt_02_Dy_Sts_Flag        :1;
            /*0x0-0xA0:Valid_value
            0xA1-0xFF:Reserved*/
            uint32_t ACC_PotentialTgt_02_Dy                 :8;
        }s_AEB_FD2_227_Inf_3_t;
    }u_AEB_FD2_227AEB_FD2_227_Inf_3_t;
}IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t;

/* Transmit function of sub message AEB_FD2_227 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_Transmit(IPC_M2S_ClusterAppCANAdaptAEB_FD2_227_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: CR_FD1_15E */
typedef struct
{
    union
    {
        uint8_t CR_FD1_15E_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t CR_FD1_15E_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t FCTA_Warn_Sts_Flag                      :1;
            /*0x0:No warning
            0x1:Warning*/
            uint8_t FCTA_Warn                               :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t FCTBTrig_Sts_Flag                       :1;
            /*0x0:Not tirggered
            0x1: tirggered*/
            uint8_t FCTBTrig                                :1;
        }s_CR_FD1_15E_Inf_t;
    }u_CR_FD1_15ECR_FD1_15E_Inf_t;
}IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t;

/* Transmit function of sub message CR_FD1_15E */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_Transmit(IPC_M2S_ClusterAppCANAdaptCR_FD1_15E_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: IFC_FD3_2CF */
typedef struct
{
    union
    {
        uint64_t IFC_FD3_2CF_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint64_t IFC_FD3_2CF_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IDC_L2_TurnLightReq_Sts_Flag           :1;
            /*0x0:Turn OFF
            0x1:Turn Left ON
            0x2:Turn Right ON
            0x3:reserved*/
            uint64_t IDC_L2_TurnLightReq                    :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t HWA_ALC_Trig_Sts_Flag                  :1;
            /*0x0:No_display
            0x1:Slow_vehicle_ahead
            0x2:Reserved
            0x3:Reserved*/
            uint64_t HWA_ALC_Trig                           :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Stop_Mark_Detn_Sts_Flag                :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Stop_Mark_Detn                         :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Stop_Mark_Dx_Sts_Flag                  :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Stop_Mark_Dx                           :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Zebra_Mark_Detn_Sts_Flag               :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Zebra_Mark_Detn                        :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Zebra_Mark_Dx_Sts_Flag                 :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Zebra_Mark_Dx                          :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Grid_Mark_Detn_Sts_Flag                :1;
            /*0x0:Not_dectected
            0x1:Dectected
            0x2:Reserved
            0x3:Invalid*/
            uint64_t Grid_Mark_Detn                         :2;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t Grid_Mark_Dx_Sts_Flag                  :1;
            /*0x0_0x12C:Validvalue
            0x12D_x1FF:Reserved*/
            uint64_t Grid_Mark_Dx                           :9;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t HWA_InhibitWarn_Sts_Flag               :1;
            /*0x0 Default 0x1Environment_inhibit 0x2 Attention 0x03 Handson 0x04 Seatbelt 0x05 Close_door*/
            uint64_t HWA_InhibitWarn                        :3;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint64_t IFC_Line01_Source_Sts_Flag             :1;
            /*0x0:Detected value
            0x1:Fitted value*/
            uint64_t IFC_Line01_Source                      :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message IFC_FD3_2CF */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_Transmit(IPC_M2S_ClusterAppCANAdaptIFC_FD3_2CF_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ACC_FD3_2B4 */
typedef struct
{
    union
    {
        uint16_t ACC_FD3_2B4_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t ACC_FD3_2B4_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message ACC_FD3_2B4 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_Transmit(IPC_M2S_ClusterAppCANAdaptACC_FD3_2B4_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: BCM1_319 */
typedef struct
{
    union
    {
        uint8_t BCM1_319_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t BCM1_319_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t DrvDoorSts_Sts_Flag                     :1;
            /*0x0:Closed;0x1:Open*/
            uint8_t DrvDoorSts                              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t BrkPedalSts_BCM_Sts_Flag                :1;
            /*0x0:Off
            0x1:On*/
            uint8_t BrkPedalSts_BCM                         :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t LowBeamSts_Sts_Flag                     :1;
            /*0x0:Off
            0x1:On*/
            uint8_t LowBeamSts                              :1;
        }s_BCM1_319_Inf_t;
    }u_BCM1_319BCM1_319_Inf_t;
}IPC_M2S_ClusterAppCANAdaptBCM1_319_t;

/* Transmit function of sub message BCM1_319 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptBCM1_319_Transmit(IPC_M2S_ClusterAppCANAdaptBCM1_319_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: BCM3_345 */
typedef struct
{
    union
    {
        uint8_t BCM3_345_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t BCM3_345_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t DrvDoorLockSts_Sts_Flag                 :1;
            /*0x0:Lock;0x1:Unlock*/
            uint8_t DrvDoorLockSts                          :1;
        }s_BCM3_345_Inf_t;
    }u_BCM3_345BCM3_345_Inf_t;
}IPC_M2S_ClusterAppCANAdaptBCM3_345_t;

/* Transmit function of sub message BCM3_345 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptBCM3_345_Transmit(IPC_M2S_ClusterAppCANAdaptBCM3_345_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: T_Box_FD10_2F0 */
typedef struct
{
    union
    {
        uint8_t T_Box_FD10_2F0_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t T_Box_FD10_2F0_MSG_TimeoutFlag          :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t V2X_RLVW_Sts_Flag                       :1;
            /*0x0:No Warning
            0x1:Warning
            0x2-0x3:Reserved*/
            uint8_t V2X_RLVW                                :2;
        }s_T_Box_FD10_2F0_Inf_t;
    }u_T_Box_FD10_2F0T_Box_FD10_2F0_Inf_t;
}IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t;

/* Transmit function of sub message T_Box_FD10_2F0 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_Transmit(IPC_M2S_ClusterAppCANAdaptT_Box_FD10_2F0_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ECM24_350 */
typedef struct
{
    union
    {
        uint32_t ECM24_350_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint32_t ECM24_350_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t EngOilPres_Sts_Flag                    :1;
            /*0x0-0x78:Valid values
            0x79-0x7E:Reserve
            0x7F:Invalid value*/
            uint32_t EngOilPres                             :7;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint32_t EngOilTemp_Sts_Flag                    :1;
            /*0x0-0xC8:Valid values
            0xC9-0xFE:Reserve
            0xFF:Invalid value*/
            uint32_t EngOilTemp                             :8;
        }s_ECM24_350_Inf_t;
    }u_ECM24_350ECM24_350_Inf_t;
}IPC_M2S_ClusterAppCANAdaptECM24_350_t;

/* Transmit function of sub message ECM24_350 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptECM24_350_Transmit(IPC_M2S_ClusterAppCANAdaptECM24_350_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: BCM12_238 */
typedef struct
{
    union
    {
        uint16_t BCM12_238_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t BCM12_238_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message BCM12_238 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptBCM12_238_Transmit(IPC_M2S_ClusterAppCANAdaptBCM12_238_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: F_PBOX1_19B */
typedef struct
{
    union
    {
        uint16_t F_PBOX1_19B_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t F_PBOX1_19B_MSG_TimeoutFlag            :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint16_t LowBeamSts_F_PBOX_Sts_Flag             :1;
            /*0x0: OFF
            0X1: ON*/
            uint16_t LowBeamSts_F_PBOX                      :1;
        }s_F_PBOX1_19B_Inf_t;
    }u_F_PBOX1_19BF_PBOX1_19B_Inf_t;
}IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t;

/* Transmit function of sub message F_PBOX1_19B */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_Transmit(IPC_M2S_ClusterAppCANAdaptF_PBOX1_19B_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HCM_L2_304 */
typedef struct
{
    union
    {
        uint8_t HCM_L2_304_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t HCM_L2_304_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message HCM_L2_304 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptHCM_L2_304_Transmit(IPC_M2S_ClusterAppCANAdaptHCM_L2_304_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: VCU_FD41_2D6 */
typedef struct
{
    union
    {
        uint16_t VCU_FD41_2D6_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint16_t VCU_FD41_2D6_MSG_TimeoutFlag           :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message VCU_FD41_2D6 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_Transmit(IPC_M2S_ClusterAppCANAdaptVCU_FD41_2D6_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HCM_R2_330 */
typedef struct
{
    union
    {
        uint8_t HCM_R2_330_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t HCM_L2_330_MSG_TimeoutFlag              :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
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

/* Transmit function of sub message HCM_R2_330 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptHCM_R2_330_Transmit(IPC_M2S_ClusterAppCANAdaptHCM_R2_330_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ESP1_149 */
typedef struct
{
    union
    {
        uint8_t ESP1_149_Inf;
        struct
        {
            /*0x0:No Timeout;0x1:Timeout��*/
            uint8_t ESP1_149_MSG_TimeoutFlag                :1;
            /*0x0valid;0x1:Invalid;
            PS������0x1��ʾ��ǰ��Ŀû�а������ź�*/
            uint8_t ESPBrkLmpCtrl_149_Sts_Flag              :1;
            /*0x0:Brake light off
            0x1:Brake light on*/
            uint8_t ESPBrkLmpCtrl_149                       :1;
        }s_ESP1_149_Inf_t;
    }u_ESP1_149ESP1_149_Inf_t;
}IPC_M2S_ClusterAppCANAdaptESP1_149_t;

/* Transmit function of sub message ESP1_149 */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
int32_t IPC_M2S_ClusterAppCANAdaptESP1_149_Transmit(IPC_M2S_ClusterAppCANAdaptESP1_149_t *data);

#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message WrnId */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocWrnId_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocWrnId_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TTStatus */
typedef struct
{
    union
    {
        uint8_t u32Telltales_status[6];
        struct
        {
            /*̥ѹָʾ��Status : 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t TPMS_Data                               :4;
            /*��϶���ϵͳ���Ϻ�ɫָʾ��status: 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t HEV_Red_Data                            :4;
            /*��ȫ��δϵ��  0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t Seat_Belt_Data                          :4;
            /*reserve*/
            uint8_t Turn_Left_Data                          :4;
            /*reserve*/
            uint8_t Turn_Right_Data                         :4;
            /*���ٱ���ָʾ��0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t TSR_120KMH_Data                         :4;
            /*CCOԽҰѲ�����ϵ�  0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t CCO_Inactive_Data                       :4;
            /*TABʧЧָʾ�� 0:off  1:on  2:1hz  3:2hz  4:4hz 5~7 :reserve*/
            uint8_t Steer_Assit_Error_Data                  :4;
            /*reserve*/
            uint8_t HEV_Yellow_Data                         :4;
            /*reserve*/
            uint8_t Ready_Light_Data                        :4;
        }s_u32Telltales_status_t;
    }u_TTStatusu32Telltales_status_t;
}IPC_S2M_ClusterAppClusterSocTTStatus_t;

/* Receive function of sub message TTStatus */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocTTStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTTStatus_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: AdasStatus */
typedef struct
{
    union
    {
        uint8_t AdasWarn[4];
        struct
        {
            /*�޷�ʶ��ֹĿ��*/
            uint16_t Id_StillTargetNotRecognized            :1;
            /*���������ʱ����ر�ת���*/
            uint16_t Id_LaneChangeAssistTimeout             :1;
            /*���������ȡ��*/
            uint16_t Id_LaneChangeAssistCancelled           :1;
            /*�����������ɣ���ر�ת���*/
            uint16_t Id_LaneChangeAssistcompleted           :1;
            /*����̫�Ͳ�֧�ֱ������*/
            uint16_t Id_LaneChangeAssistIsNotSupported      :1;
            /*����ӦѲ���޷�����*/
            uint16_t Id_ACCCannotBeActivated                :1;
            /*����ӦѲ������ȡ��*/
            uint16_t Id_ACCFunctionCanceled                 :1;
            /*����ӦѲ���˳�*/
            uint16_t Id_ACCExit                             :1;
            /*����ӦѲ���Ѽ����뱣��ע����*/
            uint16_t Id_ACCIsActivated                      :1;
            /*����Ѳ�������޷�����*/
            uint16_t Id_TJAICACannotBeActivated             :1;
            /*����Ѳ����������ȡ��*/
            uint16_t Id_TJAICAFunctionCanceled              :1;
            /*����Ѳ���˳�*/
            uint16_t Id_TJAICAExit                          :1;
            /*����Ѳ���Ѽ����뱣��ע���������շ�����*/
            uint16_t Id_TJAICAIsActivated                   :1;
            /*����Ѳ�������賵������������ʹ��*/
            uint16_t Id_TJAICANeedsToVehicleRestart         :1;
            /*ǰ������*/
            uint16_t Id_FrontVehicleHasStarted              :1;
            /*ǰ�����𲽣���ע��ǰ����·����*/
            uint16_t Id_PlsPayAttentionToTheRoadAhead       :1;
            /*ǰ�����𲽣��뱣��ע����*/
            uint16_t Id_PlsKeepYourAttention                :1;
            /*ǰ�����𲽣���ӹܳ���*/
            uint16_t Id_PlsTakeOverTheVehicle               :1;
            /*����ʱ��*/
            uint16_t Id_TheTimeGap                          :1;
            uint16_t Reserved                               :13;
        }s_AdasWarn_t;
    }u_AdasStatusAdasWarn_t;
}IPC_S2M_ClusterAppClusterSocAdasStatus_t;

/* Receive function of sub message AdasStatus */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocAdasStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocAdasStatus_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: BackChime */
typedef struct
{
    /*Current sound id,0 is no sound*/
    uint8_t CurId;
    /*Last sound play times,0 is continue sound, if last chime id is 0,No care this value*/
    uint8_t LastRepeat;
}IPC_S2M_ClusterAppClusterSocBackChime_t;

/* Receive function of sub message BackChime */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocBackChime_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocBackChime_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TCClear */
typedef struct
{
    /*0x11:Reset TC_B data,Other:Reserved*/
    uint8_t MenuResrt;
}IPC_S2M_ClusterAppClusterSocTCClear_t;

/* Receive function of sub message TCClear */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocTCClear_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTCClear_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: TtToChime */
typedef struct
{
    /*1: have tt flash   0 do not have tt flash */
    uint8_t TtFlash;
    /*the value is Flicker frequency*/
    uint32_t TtFlashTick;
}IPC_S2M_ClusterAppClusterSocTtToChime_t;

/* Receive function of sub message TtToChime */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocTtToChime_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocTtToChime_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: CommonAppAlive */
typedef struct
{
    /*0xAA:Service Alive��other��reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocCommonAppAlive_t;

/* Receive function of sub message CommonAppAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocCommonAppAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocCommonAppAlive_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message MenuSetting */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocMenuSetting_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMenuSetting_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: Gauges */
typedef struct
{
    /*Factor:0.1 km/h&mph Imperial and Metric value*/
    uint16_t VehicleSpeed;
    /*Factor:0.1rpm*/
    uint16_t EngineSpeed;
}IPC_S2M_ClusterAppClusterSocGauges_t;

/* Receive function of sub message Gauges */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocGauges_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocGauges_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: InterfaceAppAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t;

/* Receive function of sub message InterfaceAppAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocInterfaceAppAlive_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HMIPowerMode */
typedef struct
{
    /*0x00:Default;0x01:PreSleep Mode;Other reserved*/
    uint8_t PowerStatus;
}IPC_S2M_ClusterAppClusterSocHMIPowerMode_t;

/* Receive function of sub message HMIPowerMode */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocHMIPowerMode_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocHMIPowerMode_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: GaugesAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocGaugesAlive_t;

/* Receive function of sub message GaugesAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocGaugesAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocGaugesAlive_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ChimeClientAlive */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocChimeClientAlive_t;

/* Receive function of sub message ChimeClientAlive */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocChimeClientAlive_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocChimeClientAlive_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MenuTheme */
typedef struct
{
    /*����ID��infra���������̳�ID��*/
    uint32_t Rc_ThemeID;
    /*Ƥ��ID��infra���������̳�ID��*/
    uint32_t Rc_SkinID;
}IPC_S2M_ClusterAppClusterSocMenuTheme_t;

/* Receive function of sub message MenuTheme */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocMenuTheme_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMenuTheme_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: HMISafety */
typedef struct
{
    /*0xAA: Service Alive, other: reserved*/
    uint8_t AliveTick;
}IPC_S2M_ClusterAppClusterSocHMISafety_t;

/* Receive function of sub message HMISafety */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocHMISafety_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocHMISafety_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: MiaoCALL */
typedef struct
{
    /*1.138 ��CALLָʾ��--��call���ܿ���״̬Status : 0:off  1:on  */
    uint8_t MiaoCALLsts;
}IPC_S2M_ClusterAppClusterSocMiaoCALL_t;

/* Receive function of sub message MiaoCALL */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocMiaoCALL_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocMiaoCALL_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
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

/* Receive function of sub message OffroadInfo */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppClusterSocOffroadInfo_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppClusterSocOffroadInfo_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : ClusterApp */
/* Message Major: QNX */
/* Message Sub: BootStatus */
typedef struct
{
    /*0��Not requirement  1��rerequirement ��0xff:Invaid*/
    uint8_t Request;
}IPC_S2M_ClusterAppQNXBootStatus_t;

/* Receive function of sub message BootStatus */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppQNXBootStatus_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXBootStatus_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: ADASConfig */
typedef struct
{
    /*0��Not requirement  1��rerequirement ��other:Invaid*/
    uint8_t Request;
}IPC_S2M_ClusterAppQNXADASConfig_t;

/* Receive function of sub message ADASConfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppQNXADASConfig_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXADASConfig_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Message Sub: SetADASConfig */
typedef struct
{
    /*1 = on , 0 = off*/
    uint8_t HighwayAssistSwitch;
    /*1 = on , 0 = off*/
    uint8_t LaneChangeAssistSwitch;
}IPC_S2M_ClusterAppQNXSetADASConfig_t;

/* Receive function of sub message SetADASConfig */
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define IPC_GATEWAY_START_SEC_CODE
#include "IPC_GateWay_MemMap.h"
void IPC_S2M_ClusterAppQNXSetADASConfig_Receive(uint8_t *receiveData, IPC_S2M_ClusterAppQNXSetADASConfig_t *data, uint32_t payloadLength);
#define IPC_GATEWAY_STOP_SEC_CODE
#include "IPC_GateWay_MemMap.h"
/**********************************************************************************************************
*#endif //Section End                                                                                     *
**********************************************************************************************************/
/* Group: : ClusterApp */
#ifdef __cplusplus
}
#endif

#endif
