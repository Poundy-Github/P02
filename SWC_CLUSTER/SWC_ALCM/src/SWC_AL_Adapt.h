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
*File Name   : AL_Adapt.h                                                                                 *
*                                                                                                         *
*Description : Ambient Light module adaptation head file.                                                 *
*                                                                                                         *
*Author      :                                                                                            *
*                                                                                                         *
*Platform    : Free Rtos System                                                    						  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef AL_ADAPT_H
#define AL_ADAPT_H
/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_AL_Config.h"
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_GateWay.h"
#include "VConfig.h"
#include "SWC_IPC_Interface.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
#define SWC_ALCM_ADAPT_B02
#elif defined GWM_V35_PROJECT_TYPE_B03
#define SWC_ALCM_ADAPT_B03
#elif defined GWM_V35_PROJECT_TYPE_P03
#define SWC_ALCM_ADAPT_P03
#elif defined GWM_V35_PROJECT_TYPE_P05
#define SWC_ALCM_ADAPT_P05
#elif defined GWM_V35_PROJECT_TYPE_A07
#define SWC_ALCM_ADAPT_A07
#elif defined GWM_V35_PROJECT_TYPE_D01
#define SWC_ALCM_ADAPT_D01
#elif defined GWM_V35_PROJECT_TYPE_D02
#define SWC_ALCM_ADAPT_D02
#elif defined GWM_V35_PROJECT_TYPE_D03
#define SWC_ALCM_ADAPT_D03
#elif defined GWM_V35_PROJECT_TYPE_P02
#define SWC_ALCM_ADAPT_P02
#else
#define SWC_ALCM_ADAPT_NULL
#endif

#ifdef SWC_ALCM_ADAPT_P03
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_P05
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_A07
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_D01
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_D02
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_D03
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif
#ifdef SWC_ALCM_ADAPT_P02
#include "ComEx_Cfg.h"
#include "SWC_IPC_CANMatrix.h"
#endif

#define Common_GateWay_START_SEC_CODE
#include  "Common_GateWay_MemMap.h"


#ifdef SWC_ALCM_ADAPT_B02
#define GET_CAN_MESSAGE_MISSING(status)     (TRUE)
#elif defined SWC_ALCM_ADAPT_B03
#define GET_CAN_MESSAGE_MISSING(status)     (TRUE)
#if 0
#define GET_CAN_MESSAGE_MISSING(status)		(((RTE_E_NEVER_RECEIVED & (status)) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & (status)) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & (status)) == RTE_E_COM_STOPPED))
#endif
#elif defined SWC_ALCM_ADAPT_P03
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_P05
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_A07
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_D01
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_D02
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_D03
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#elif defined SWC_ALCM_ADAPT_P02
#define GET_CAN_MESSAGE_MISSING(status)		(((COMEX_NEVER_RECEIVED & (status)) == COMEX_NEVER_RECEIVED) || ((COMEX_MAX_AGE_EXCEEDED & (status)) == COMEX_MAX_AGE_EXCEEDED) || ((COMEX_ERROR_PARAM & (status)) == COMEX_ERROR_PARAM))
#else
#define GET_CAN_MESSAGE_MISSING(status)     (TRUE)
#endif



/* Project adaptation */
#define ALCM_NONEFUNC               (0U)
#define ALCM_AUTOSAR                (1U)
#define ALCM_COMEX                  (2U)
#define ALCM_IPCSIG                 (3u)

#define ALCM_TXCANSIG_INVALID       (0xFFFF)

#if (defined SWC_ALCM_ADAPT_P03)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#elif (defined SWC_ALCM_ADAPT_P05)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_NONEFUNC)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_NONEFUNC)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_NONEFUNC)

#elif (defined SWC_ALCM_ADAPT_A07)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_NONEFUNC)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#elif (defined SWC_ALCM_ADAPT_P02)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#elif (defined SWC_ALCM_ADAPT_D01)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#elif (defined SWC_ALCM_ADAPT_D02)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#elif (defined SWC_ALCM_ADAPT_D03)
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_COMEX)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_COMEX)
    #define ALCM_RSIG_FCW_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_COMEX)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_COMEX)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_COMEX)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_COMEX)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_COMEX)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_COMEX)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_COMEX)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_COMEX)
    #define ALCM_RSIG_PM25INDENS					(ALCM_COMEX)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_IPCSIG)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_IPCSIG)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_COMEX)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_COMEX)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_COMEX)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_COMEX)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_COMEX)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_COMEX)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_COMEX)

#else
    #define ALCM_RSIG_AEB_VEHTRIG					(ALCM_NONEFUNC)
    #define ALCM_RSIG_AEB_PEDTRIG					(ALCM_NONEFUNC)
    #define ALCM_RSIG_AEB_JA_WARN					(ALCM_NONEFUNC)
    #define ALCM_RSIG_AEB_JABRKTRIG					(ALCM_NONEFUNC)
    #define ALCM_RSIG_FCW_WARN						(ALCM_NONEFUNC)
    #define ALCM_RSIG_FCTBTRIG						(ALCM_NONEFUNC)
    #define ALCM_RSIG_FCTA_WARN						(ALCM_NONEFUNC)
    #define ALCM_RSIG_LCA_WARNR						(ALCM_NONEFUNC)
    #define ALCM_RSIG_LCA_WARNL						(ALCM_NONEFUNC)
    #define ALCM_RSIG_DOW_WARNR						(ALCM_NONEFUNC)
    #define ALCM_RSIG_DOW_WARNL						(ALCM_NONEFUNC)
    #define ALCM_RSIG_DRVDOORSTS					(ALCM_NONEFUNC)
    #define ALCM_RSIG_PASSENGERDOORSTS				(ALCM_NONEFUNC)
    #define ALCM_RSIG_LRDOORSTS						(ALCM_NONEFUNC)
    #define ALCM_RSIG_RRDOORSTS						(ALCM_NONEFUNC)
    #define ALCM_RSIG_ACDRVTEMP						(ALCM_NONEFUNC)
    #define ALCM_RSIG_ACFRNTPASSTTEMP				(ALCM_NONEFUNC)
    #define ALCM_RSIG_PM25INDENS					(ALCM_NONEFUNC)

    #define ALCM_RTSIG_PARTITIONSWT					(ALCM_NONEFUNC)
    #define ALCM_RTSIG_MASTERSWT					(ALCM_NONEFUNC)

    #define ALCM_SSIG_DRVDOORALCMFLASHFREQ			(ALCM_NONEFUNC)
    #define ALCM_SSIG_PASSDOORALCMFLASHFREQ         (ALCM_NONEFUNC)
    #define ALCM_SSIG_LEFTPANELALCMFLASHFREQ        (ALCM_NONEFUNC)
    #define ALCM_SSIG_RIGHTPANELALCMFLASHFREQ       (ALCM_NONEFUNC)
    #define ALCM_SSIG_LRDOORALCMFLASHFREQ           (ALCM_NONEFUNC)
    #define ALCM_SSIG_RRDOORALCMFLASHFREQ           (ALCM_NONEFUNC)
    #define ALCM_SSIG_FOOTALCMFLASHFREQ             (ALCM_NONEFUNC)
    #define ALCM_SSIG_DRVDOORALCMCLRSET             (ALCM_NONEFUNC)
    #define ALCM_SSIG_PASSDOORALCMCLRSET            (ALCM_NONEFUNC)
    #define ALCM_SSIG_LEFTPANELALCMCLRSET           (ALCM_NONEFUNC)
    #define ALCM_SSIG_RIGHTPANELALCMCLRSET          (ALCM_NONEFUNC)
    #define ALCM_SSIG_LRDOORALCMCLRSET              (ALCM_NONEFUNC)
    #define ALCM_SSIG_RRDOORALCMCLRSET              (ALCM_NONEFUNC)
    #define ALCM_SSIG_FOOTALCMCLRSET                (ALCM_NONEFUNC)
    #define ALCM_SSIG_DRVDOORALCMLIGHTLVLSET        (ALCM_NONEFUNC)
    #define ALCM_SSIG_PASSDOORALCMLIGHTLVLSET       (ALCM_NONEFUNC)
    #define ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET      (ALCM_NONEFUNC)
    #define ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET     (ALCM_NONEFUNC)
    #define ALCM_SSIG_LRDOORALCMLIGHTLVLSET         (ALCM_NONEFUNC)
    #define ALCM_SSIG_RRDOORALCMLIGHTLVLSET         (ALCM_NONEFUNC)
    #define ALCM_SSIG_FOOTALCMLIGHTLVLSET           (ALCM_NONEFUNC)
#endif



#if (ALCM_SSIG_DRVDOORALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_DrvDoorALCMFlashFreq          (uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_DrvDoorALCMFlashFreq          (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_PASSDOORALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_PassDoorALCMFlashFreq         (uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_PassDoorALCMFlashFreq         (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LEFTPANELALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LeftPanelALCMFlashFreq        (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_LeftPanelALCMFlashFreq        (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RIGHTPANELALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RightPanelALCMFlashFreq       (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_RightPanelALCMFlashFreq       (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LRDOORALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LRDoorALCMFlashFreq           (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_LRDoorALCMFlashFreq           (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RRDOORALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RRDoorALCMFlashFreq           (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_RRDoorALCMFlashFreq           (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_FOOTALCMFLASHFREQ == ALCM_COMEX)
    #define ALCM_TXSIGNAL_FootALCMFlashFreq             (uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMFlashFreq
#else
    #define ALCM_TXSIGNAL_FootALCMFlashFreq             (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_DRVDOORALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_DrvDoorALCMClrSet             (uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMClrSet
#else
    #define ALCM_TXSIGNAL_DrvDoorALCMClrSet             (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_PASSDOORALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_PassDoorALCMClrSet            (uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMClrSet
#else
    #define ALCM_TXSIGNAL_PassDoorALCMClrSet            (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LEFTPANELALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LeftPanelALCMClrSet           (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMClrSet
#else
    #define ALCM_TXSIGNAL_LeftPanelALCMClrSet           (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RIGHTPANELALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RightPanelALCMClrSet          (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMClrSet
#else
    #define ALCM_TXSIGNAL_RightPanelALCMClrSet          (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LRDOORALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LRDoorALCMClrSet              (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMClrSet
#else
    #define ALCM_TXSIGNAL_LRDoorALCMClrSet              (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RRDOORALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RRDoorALCMClrSet              (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMClrSet
#else
    #define ALCM_TXSIGNAL_RRDoorALCMClrSet              (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_FOOTALCMCLRSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_FootALCMClrSet                (uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMClrSet
#else
    #define ALCM_TXSIGNAL_FootALCMClrSet                (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_DRVDOORALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_DrvDoorALCMLightLvlSet        (uint16)SWC_IPC_EVENT_CAN_SIGNAL_DrvDoorALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_DrvDoorALCMLightLvlSet        (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_PASSDOORALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_PassDoorALCMLightLvlSet       (uint16)SWC_IPC_EVENT_CAN_SIGNAL_PassDoorALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_PassDoorALCMLightLvlSet       (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LEFTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LeftPanelALCMLightLvlSet      (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LeftPanelALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_LeftPanelALCMLightLvlSet      (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RIGHTPANELALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RightPanelALCMLightLvlSet     (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RightPanelALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_RightPanelALCMLightLvlSet     (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_LRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_LRDoorALCMLightLvlSet         (uint16)SWC_IPC_EVENT_CAN_SIGNAL_LRDoorALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_LRDoorALCMLightLvlSet         (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_RRDOORALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_RRDoorALCMLightLvlSet         (uint16)SWC_IPC_EVENT_CAN_SIGNAL_RRDoorALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_RRDoorALCMLightLvlSet         (uint16)ALCM_TXCANSIG_INVALID
#endif
#if (ALCM_SSIG_FOOTALCMLIGHTLVLSET == ALCM_COMEX)
    #define ALCM_TXSIGNAL_FootALCMLightLvlSet           (uint16)SWC_IPC_EVENT_CAN_SIGNAL_FootALCMLightLvlSet
#else
    #define ALCM_TXSIGNAL_FootALCMLightLvlSet           (uint16)ALCM_TXCANSIG_INVALID
#endif

#define ALCM_TXCANSIG_ADAPT_LIST    \
{\
ALCM_TXSIGNAL_DrvDoorALCMFlashFreq,\
ALCM_TXSIGNAL_PassDoorALCMFlashFreq,\
ALCM_TXSIGNAL_LeftPanelALCMFlashFreq,\
ALCM_TXSIGNAL_RightPanelALCMFlashFreq,\
ALCM_TXSIGNAL_LRDoorALCMFlashFreq,\
ALCM_TXSIGNAL_RRDoorALCMFlashFreq,\
ALCM_TXSIGNAL_FootALCMFlashFreq,\
ALCM_TXSIGNAL_DrvDoorALCMClrSet,\
ALCM_TXSIGNAL_PassDoorALCMClrSet,\
ALCM_TXSIGNAL_LeftPanelALCMClrSet,\
ALCM_TXSIGNAL_RightPanelALCMClrSet,\
ALCM_TXSIGNAL_LRDoorALCMClrSet,\
ALCM_TXSIGNAL_RRDoorALCMClrSet,\
ALCM_TXSIGNAL_FootALCMClrSet,\
ALCM_TXSIGNAL_DrvDoorALCMLightLvlSet,\
ALCM_TXSIGNAL_PassDoorALCMLightLvlSet,\
ALCM_TXSIGNAL_LeftPanelALCMLightLvlSet,\
ALCM_TXSIGNAL_RightPanelALCMLightLvlSet,\
ALCM_TXSIGNAL_LRDoorALCMLightLvlSet,\
ALCM_TXSIGNAL_RRDoorALCMLightLvlSet,\
ALCM_TXSIGNAL_FootALCMLightLvlSet,\
}






uint8 FALCM_Adapt_GetVconfig(uint32 CfgID);
uint8 FALCM_Adapt_GetPowerMode_State(void);
void FALCM_Adapt_Get_Direction(uint8 *data);

uint8 FALCM_Adapt_GetSig_AEB_VehTrig(uint8 *data);
uint8 FALCM_Adapt_GetSig_AEB_PedTrig(uint8 *data);
uint8 FALCM_Adapt_GetSig_AEB_JA_Warn(uint8 *data);
uint8 FALCM_Adapt_GetSig_AEB_JABrkTrig(uint8 *data);
uint8 FALCM_Adapt_GetSig_FCW_Warn(uint8 *data);
uint8 FALCM_Adapt_GetSig_FCTBTrig(uint8 *data);
uint8 FALCM_Adapt_GetSig_FCTA_Warn(uint8 *data);
uint8 FALCM_Adapt_GetSig_BSD_LCA_warningReqRight(uint8 *data);
uint8 FALCM_Adapt_GetSig_BSD_LCA_warningReqleft(uint8 *data);
uint8 FALCM_Adapt_GetSig_DOW_warningReqRight(uint8 *data);
uint8 FALCM_Adapt_GetSig_DOW_warningReqleft(uint8 *data);
uint8 FALCM_Adapt_GetSig_DrvDoorSts(uint8 *data);
uint8 FALCM_Adapt_GetSig_PassengerDoorSts(uint8 *data);
uint8 FALCM_Adapt_GetSig_LRDoorSts(uint8 *data);
uint8 FALCM_Adapt_GetSig_RRDoorSts(uint8 *data);
uint8 FALCM_Adapt_GetSig_ACDrvTemp_ATC(uint8 *data);
uint8 FALCM_Adapt_GetSig_ACFrntPasstTemp_ATC(uint8 *data);
uint8 FALCM_Adapt_GetSig_L_PM25InDens(uint16 *data);

void FALCM_Adapt_GetTxSig_PartitionSwt(uint8 *data);
void FALCM_Adapt_GetTxSig_MasterSwt(uint8 *data);

void FALCM_Adapt_SetSig_DrvDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_PassDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_LeftPanelALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_RightPanelALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_LRDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_RRDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSig_FootALCMFlashFreq(uint8 data);

void FALCM_Adapt_SetSig_DrvDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_PassDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_LeftPanelALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_RightPanelALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_LRDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_RRDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSig_FootALCMClrSet(uint8 data);

void FALCM_Adapt_SetSig_DrvDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_PassDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_LeftPanelALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_RightPanelALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_LRDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_RRDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSig_FootALCMLightLvlSet(uint8 data);

void FALCM_Adapt_SetSigBuffer_DrvDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_PassDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_LeftPanelALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_RightPanelALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_LRDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_RRDoorALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_FootALCMFlashFreq(uint8 data);
void FALCM_Adapt_SetSigBuffer_DrvDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_PassDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_LeftPanelALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_RightPanelALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_LRDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_RRDoorALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_FootALCMClrSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_DrvDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_PassDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_LeftPanelALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_RightPanelALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_LRDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_RRDoorALCMLightLvlSet(uint8 data);
void FALCM_Adapt_SetSigBuffer_FootALCMLightLvlSet(uint8 data);


#define Common_GateWay_STOP_SEC_CODE
#include  "Common_GateWay_MemMap.h"

/*********************************************************************************************************/
#endif //AL_ADAPT_H
/**********************************************************************************************************
*  End Of File																							  *
**********************************************************************************************************/
