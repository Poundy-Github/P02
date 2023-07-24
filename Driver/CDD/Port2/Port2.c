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
 * @file:      Port2.c
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file in this project/library%
 */
#include "Port2.h"
#include "Std_Types.h"


/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */
/*reg table of gpio*/
struct Port_DevCfg
{
    uint16 exist;
    __IO uint32 *P;
    __IO uint32 *PNOT;
    __IO uint32 *PM;
    __IO uint32 *PMC;
    __IO uint32 *PFC;
    __IO uint32 *PFCE;
    __IO uint32 *PFCAE;
    __IO uint32 *PIPC;
    __IO uint32 *PIBC;
    __IO const uint32 *PPR;
    __IO uint32 *PD;
    __IO uint32 *PU;
    __IO uint32 *PODC;
    __IO uint32 *PPCMD;
    __IO uint32 *PPROTS;
    __IO uint32 *PBDC;
    __IO uint32 *PDSC;
};

/* gpio reg */
/* this config should be different when MCU chip change */     
struct Port_BaseReg
{                                                     /* Module           */
    __IO uint32 P[23];                                /* 0x0000 - 0x005B  */
    __IO uint8 dummy1[108];                           /* 0x005C - 0x00C7  */
    __IO uint32 AP[2];                                /* 0x00C8 - 0x00CF  */
    __IO uint8 dummy2[48];                            /* 0x00D0 - 0x00FF  */
    __IO uint32 PSR[23];                              /* 0x0100 - 0x015B  */
    __IO uint8 dummy3[108];                           /* 0x015C - 0x01C7  */
    __IO uint32 APSR[2];                              /* 0x01C8 - 0x01CF  */
    __IO uint8 dummy4[48];                            /* 0x01D0 - 0x01FF  */
    __IO uint32 PPR[23];                              /* 0x0200 - 0x025B  */
    __IO uint8 dummy5[108];                           /* 0x025C - 0x02C7  */
    __IO uint32 APPR[2];                              /* 0x02C8 - 0x02CF  */
    __IO uint8 dummy6[48];                            /* 0x02D0 - 0x02FF  */
    __IO uint32 PM[23];                               /* 0x0300 - 0x035B  */
    __IO uint8 dummy7[108];                           /* 0x035C - 0x03C7  */
    __IO uint32 APM[2];                               /* 0x03C8 - 0x03CF  */
    __IO uint8 dummy8[48];                            /* 0x03D0 - 0x03FF  */
    __IO uint32 PMC[23];                              /* 0x0400 - 0x045B  */
    __IO uint8 dummy9[164];                           /* 0x045C - 0x04FF  */
    __IO uint32 PFC[23];                              /* 0x0500 - 0x055B  */
    __IO uint8 dummy10[164];                          /* 0x055C - 0x05FF  */
    __IO uint32 PFCE[23];                             /* 0x0600 - 0x065B  */
    __IO uint8 dummy11[164];                          /* 0x065C - 0x06FF  */
    __IO uint32 PNOT[23];                             /* 0x0700 - 0x075B  */
    __IO uint8 dummy12[108];                          /* 0x075C - 0x07C7  */
    __IO uint32 APNOT[2];                             /* 0x07C8 - 0x07CF  */
    __IO uint8 dummy13[48];                           /* 0x07D0 - 0x07FF  */
    __IO uint32 PMSR[23];                             /* 0x0800 - 0x085B  */
    __IO uint8 dummy14[108];                          /* 0x085C - 0x08C7  */
    __IO uint32 APMSR[2];                             /* 0x08C8 - 0x08CF  */
    __IO uint8 dummy15[48];                           /* 0x08D0 - 0x08FF  */   
    __IO uint32 PMCSR[23];                            /* 0x0900 - 0x095B  */
    __IO uint8 dummy16[164];                          /* 0x095C - 0x09FF  */
    __IO uint32 PFCAE[23];                            /* 0x0A00 - 0x0A5B  */
    __IO uint8 dummy17[13732];                        /* 0x0A5C - 0x3FFF  */
    __IO uint32 PIBC[23];                             /* 0x4000 - 0x405B  */
    __IO uint8 dummy18[108];                          /* 0x405C - 0x40C7  */
    __IO uint32 APIBC[2];                             /* 0x40C8 - 0x40CF  */
    __IO uint8 dummy19[48];                           /* 0x40D0 - 0x40FF  */
    __IO uint32 PBDC[23];                             /* 0x4100 - 0x415B  */
    __IO uint8 dummy20[108];                          /* 0x415C - 0x41C7  */
    __IO uint32 APBDC[2];                             /* 0x41C8 - 0x41CF  */
    __IO uint8 dummy21[48];                           /* 0x41D0 - 0x41FF  */
    __IO uint32 PIPC[23];                             /* 0x4200 - 0x425B  */
    __IO uint8 dummy22[164];                          /* 0x425C - 0x42FF  */
    __IO uint32 PU[23];                               /* 0x4300 - 0x435B  */
    __IO uint8 dummy23[164];                          /* 0x435C - 0x43FF  */
    __IO uint32 PD[23];                               /* 0x4400 - 0x445B  */
    __IO uint8 dummy24[164];                          /* 0x445C - 0x44FF  */
    __IO uint32 PODC[23];                             /* 0x4500 - 0x455B  */
    __IO uint8 dummy25[164];                          /* 0x455C - 0x45FF  */
    __IO uint32 PDSC[23];                             /* 0x4600 - 0x465B  */
    __IO uint8 dummy26[164];                          /* 0x465C - 0x46FF  */
    __IO uint32 PISC[23];                             /* 0x4700 - 0x475B  */
    __IO uint8 dummy27[676];                          /* 0x475C - 0x47FF  */
    __IO uint32 PISCA[23];                            /* 0x4A00 - 0x4A5B  */
    __IO uint8 dummy28[164];                          /* 0x4A5C - 0x4AFF  */
    __IO uint32 PPROTS[23];                           /* 0x4B00 - 0x4B5B  */
    __IO uint8 dummy29[164];                          /* 0x4B5C - 0x4BFF  */
    __IO uint32 PPCMD[23];                            /* 0x4C00 - 0x4C5B  */
    __IO uint8 dummy30[164];                          /* 0x4C5C - 0x4CFF  */
};

/* reg start address */
#define PORT_PORT_REG (*(struct Port_BaseReg *)0xFFC10000)     /* PORT */

/*
 *  %forward declaration%
 */


/*
 *  %global definition%
 */
static const struct Port_DevCfg port_devCfgs[PORT_PORT_NUM] =
{
    {0x7FFFu, &PORT_PORT_REG.P[0], &PORT_PORT_REG.PNOT[0], &PORT_PORT_REG.PM[0], &PORT_PORT_REG.PMC[0], &PORT_PORT_REG.PFC[0], &PORT_PORT_REG.PFCE[0], &PORT_PORT_REG.PFCAE[0], &PORT_PORT_REG.PIPC[0], &PORT_PORT_REG.PIBC[0], &PORT_PORT_REG.PPR[0], &PORT_PORT_REG.PD[0], &PORT_PORT_REG.PU[0], &PORT_PORT_REG.PODC[0], &PORT_PORT_REG.PPCMD[0], &PORT_PORT_REG.PPROTS[0], &PORT_PORT_REG.PBDC[0], &PORT_PORT_REG.PDSC[0]},
    {0xFF3Fu, &PORT_PORT_REG.P[1], &PORT_PORT_REG.PNOT[1], &PORT_PORT_REG.PM[1], &PORT_PORT_REG.PMC[1], &PORT_PORT_REG.PFC[1], &PORT_PORT_REG.PFCE[1], &PORT_PORT_REG.PFCAE[1], &PORT_PORT_REG.PIPC[1], &PORT_PORT_REG.PIBC[1], &PORT_PORT_REG.PPR[1], &PORT_PORT_REG.PD[1], &PORT_PORT_REG.PU[1], &PORT_PORT_REG.PODC[1], &PORT_PORT_REG.PPCMD[1], &PORT_PORT_REG.PPROTS[1], &PORT_PORT_REG.PBDC[1], &PORT_PORT_REG.PDSC[1]},
    {0x007Fu, &PORT_PORT_REG.P[2], &PORT_PORT_REG.PNOT[2], &PORT_PORT_REG.PM[2], &PORT_PORT_REG.PMC[2], &PORT_PORT_REG.PFC[2], &PORT_PORT_REG.PFCE[2], &PORT_PORT_REG.PFCAE[2], &PORT_PORT_REG.PIPC[2], &PORT_PORT_REG.PIBC[2], &PORT_PORT_REG.PPR[2], &PORT_PORT_REG.PD[2], &PORT_PORT_REG.PU[2], &PORT_PORT_REG.PODC[2], &PORT_PORT_REG.PPCMD[2], &PORT_PORT_REG.PPROTS[2], &PORT_PORT_REG.PBDC[2], &PORT_PORT_REG.PDSC[2]},
    {0x1FFFu, &PORT_PORT_REG.P[8], &PORT_PORT_REG.PNOT[8], &PORT_PORT_REG.PM[8], &PORT_PORT_REG.PMC[8], &PORT_PORT_REG.PFC[8], &PORT_PORT_REG.PFCE[8], &PORT_PORT_REG.PFCAE[8], &PORT_PORT_REG.PIPC[8], &PORT_PORT_REG.PIBC[8], &PORT_PORT_REG.PPR[8], &PORT_PORT_REG.PD[8], &PORT_PORT_REG.PU[8], &PORT_PORT_REG.PODC[8], &PORT_PORT_REG.PPCMD[8], &PORT_PORT_REG.PPROTS[8], &PORT_PORT_REG.PBDC[8], NULL_PTR},
    {0x001Fu, &PORT_PORT_REG.P[9], &PORT_PORT_REG.PNOT[9], &PORT_PORT_REG.PM[9], &PORT_PORT_REG.PMC[9], &PORT_PORT_REG.PFC[9], &PORT_PORT_REG.PFCE[9], &PORT_PORT_REG.PFCAE[9], &PORT_PORT_REG.PIPC[9], &PORT_PORT_REG.PIBC[9], &PORT_PORT_REG.PPR[9], &PORT_PORT_REG.PD[9], &PORT_PORT_REG.PU[9], &PORT_PORT_REG.PODC[9], &PORT_PORT_REG.PPCMD[9], &PORT_PORT_REG.PPROTS[9], &PORT_PORT_REG.PBDC[9], NULL_PTR},
    {0xFFFFu, &PORT_PORT_REG.P[10], &PORT_PORT_REG.PNOT[10], &PORT_PORT_REG.PM[10], &PORT_PORT_REG.PMC[10], &PORT_PORT_REG.PFC[10], &PORT_PORT_REG.PFCE[10], &PORT_PORT_REG.PFCAE[10], &PORT_PORT_REG.PIPC[10], &PORT_PORT_REG.PIBC[10], &PORT_PORT_REG.PPR[10], &PORT_PORT_REG.PD[10], &PORT_PORT_REG.PU[10], &PORT_PORT_REG.PODC[10], &PORT_PORT_REG.PPCMD[10], &PORT_PORT_REG.PPROTS[10], &PORT_PORT_REG.PBDC[10], &PORT_PORT_REG.PDSC[10]},
    {0x9FFFu, &PORT_PORT_REG.P[11], &PORT_PORT_REG.PNOT[11], &PORT_PORT_REG.PM[11], &PORT_PORT_REG.PMC[11], &PORT_PORT_REG.PFC[11], &PORT_PORT_REG.PFCE[11], &PORT_PORT_REG.PFCAE[11], &PORT_PORT_REG.PIPC[11], &PORT_PORT_REG.PIBC[11], &PORT_PORT_REG.PPR[11], &PORT_PORT_REG.PD[11], &PORT_PORT_REG.PU[11], &PORT_PORT_REG.PODC[11], &PORT_PORT_REG.PPCMD[11], &PORT_PORT_REG.PPROTS[11], &PORT_PORT_REG.PBDC[11], &PORT_PORT_REG.PDSC[11]},
    {0x003Fu, &PORT_PORT_REG.P[12], &PORT_PORT_REG.PNOT[12], &PORT_PORT_REG.PM[12], &PORT_PORT_REG.PMC[12], &PORT_PORT_REG.PFC[12], &PORT_PORT_REG.PFCE[12], &PORT_PORT_REG.PFCAE[12], &PORT_PORT_REG.PIPC[12], &PORT_PORT_REG.PIBC[12], &PORT_PORT_REG.PPR[12], &PORT_PORT_REG.PD[12], &PORT_PORT_REG.PU[12], &PORT_PORT_REG.PODC[12], &PORT_PORT_REG.PPCMD[12], &PORT_PORT_REG.PPROTS[12], &PORT_PORT_REG.PBDC[12], &PORT_PORT_REG.PDSC[12]},
    {0x00FFu, &PORT_PORT_REG.P[18], &PORT_PORT_REG.PNOT[18], &PORT_PORT_REG.PM[18], &PORT_PORT_REG.PMC[18], &PORT_PORT_REG.PFC[18], &PORT_PORT_REG.PFCE[18], &PORT_PORT_REG.PFCAE[18], &PORT_PORT_REG.PIPC[18], &PORT_PORT_REG.PIBC[18], &PORT_PORT_REG.PPR[18], &PORT_PORT_REG.PD[18], &PORT_PORT_REG.PU[18], &PORT_PORT_REG.PODC[18], &PORT_PORT_REG.PPCMD[18], &PORT_PORT_REG.PPROTS[18], &PORT_PORT_REG.PBDC[18], &PORT_PORT_REG.PDSC[18]},
    {0x003Fu, &PORT_PORT_REG.P[20], &PORT_PORT_REG.PNOT[20], &PORT_PORT_REG.PM[20], &PORT_PORT_REG.PMC[20], &PORT_PORT_REG.PFC[20], &PORT_PORT_REG.PFCE[20], &PORT_PORT_REG.PFCAE[20], &PORT_PORT_REG.PIPC[20], &PORT_PORT_REG.PIBC[20], &PORT_PORT_REG.PPR[20], &PORT_PORT_REG.PD[20], &PORT_PORT_REG.PU[20], &PORT_PORT_REG.PODC[20], &PORT_PORT_REG.PPCMD[20], &PORT_PORT_REG.PPROTS[20], &PORT_PORT_REG.PBDC[20], &PORT_PORT_REG.PDSC[20]},
    {0xFFFFu, &PORT_PORT_REG.AP[0], &PORT_PORT_REG.APNOT[0], &PORT_PORT_REG.APM[0], NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, &PORT_PORT_REG.APIBC[0], &PORT_PORT_REG.APPR[0], NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR},
    {0xFFFFu, &PORT_PORT_REG.AP[1], &PORT_PORT_REG.APNOT[1], &PORT_PORT_REG.APM[1], NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, &PORT_PORT_REG.APIBC[1], &PORT_PORT_REG.APPR[1], NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR}
};


/*
 *  %function definition%
 */

/*
* @brief   :   init gpio according to config
* @param   :   id: id of io
* @retval  :   PORT_SUCCESS: init success
* @retval  :   PORT_E_PARAM: parameter error
*/
Port_Return_t Port2_Init(Port_Id_t id)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *portCfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((portCfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            switch(port_cfgs[id].func)
            {
                case PORT_FUNC_ALT_1:
                {
                    (*portCfg->PFC) &= (~pin);
                    (*portCfg->PFCE) &= (~pin);
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) &= (~pin);
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_2:
                {
                    (*portCfg->PFC) |= pin;
                    (*portCfg->PFCE) &= (~pin);
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) &= (~pin);
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_3:
                {
                    (*portCfg->PFC) &= (~pin);
                    (*portCfg->PFCE) |= pin;
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) &= (~pin);
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_4:
                {
                    (*portCfg->PFC) |= pin;
                    (*portCfg->PFCE) |= pin;
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) &= (~pin);
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_5:
                {
                    (*portCfg->PFC) &= (~pin);
                    (*portCfg->PFCE) &= (~pin);
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) |= pin;
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_6:
                {
                    (*portCfg->PFC) |= pin;
                    (*portCfg->PFCE) &= (~pin);
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) |= pin;
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_ALT_7:
                {
                    (*portCfg->PFC) |= pin;
                    (*portCfg->PFCE) |= pin;
                    if(portCfg->PFCAE)
                    {
                        (*portCfg->PFCAE) |= pin;
                    }
                    (*portCfg->PMC) |= pin;
                }
                break;

                case PORT_FUNC_GPIO:
                default:
                {
                    (*portCfg->PMC) &= (~pin);
                }
                break;
            }

            switch(port_cfgs[id].dir)
            {
                case PORT_DIR_IN:
                {
                    if(portCfg->PIPC)
                    {
                        *portCfg->PIPC &= (~pin);
                    }
                    else
                    {
                        /*nothing to do*/
                    }
                    (*portCfg->PBDC) &= (~pin);
                    (*portCfg->PM) |= pin;
                    (*portCfg->PIBC) |= pin;
                    Port2_OpenDrainSet(id, FALSE);
                }
                break;

                case PORT_DIR_OUT:
                {
                    if(portCfg->PIPC)
                    {
                        *portCfg->PIPC &= (~pin);
                    }

                    (*portCfg->PBDC) &= (~pin);
                    (*portCfg->PM) &= (~pin);
                    (*portCfg->PIBC) &= (~pin);

                    if(port_cfgs[id].initLevel)
                    {
                        (*portCfg->P) |= pin;
                    }
                    else
                    {
                        (*portCfg->P) &= (~pin);
                    }
                    Port2_OpenDrainSet(id, FALSE);
                }
                break;

                case PORT_DIR_BI:
                {
                    if(portCfg->PIPC)
                    {
                        *portCfg->PIPC &= (~pin);
                    }

                    (*portCfg->PBDC) |= (pin);
                    (*portCfg->PM) &= (~pin);
                    (*portCfg->PIBC) &= (~pin);
                    Port2_OpenDrainSet(id, TRUE);
                }
                break;

                case PORT_DIR_PIPC:
                {
                    if(portCfg->PIPC)
                    {
                        *portCfg->PIPC |= pin;
                    }
                    else
                    {
                        ret = PORT_E_PARAM;
                    }

                    (*portCfg->PBDC) &= (~pin);
                    (*portCfg->PM) &= (~pin);
                    (*portCfg->PIBC) &= (~pin);
                    Port2_OpenDrainSet(id, FALSE);
                }

                default:
                break;
            }
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   deinit gpio
* @param   :   id: id of gpio to operate
* @retval  :   PORT_SUCCESS: deinit success
* @retval  :   PORT_E_PARAM: parameter error
*/
Port_Return_t Port2_Deinit(Port_Id_t id)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *portCfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((portCfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            (*portCfg->PMC) &= (~pin);
            (*portCfg->PM) |= pin;
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   get gpio status
* @param   :   id: id of gpio to operate
* @param   :   result: return state of gpio
* @retval  :   PORT_SUCCESS: get success
* @retval  :   PORT_E_PARAM: parameter error
*/
Port_Return_t Port2_Get(Port_Id_t id, boolean *result)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *portCfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;
        uint16 mask = (*portCfg->PPR) & pin;

        if((portCfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else if(mask == 0u)
        {
            *result = FALSE;
        }
        else
        {
            *result = TRUE;
        }
        ret = PORT_SUCCESS;
    }
    return ret;
}

/*
* @brief   :   set gpio level
* @param   :   id: id of gpio to operate
* @param   :   level: state of gpio to set
* @retval  :   PORT_SUCCESS: set success
* @retval  :   PORT_E_PARAM: parameter error
*/
Port_Return_t Port2_Set(Port_Id_t id, boolean level)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *port_cfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((port_cfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            *port_cfg->PM &= ~pin;
            *port_cfg->PMC &= ~pin;
            if(level)
            {
                (*port_cfg->P) |= pin;
            }
            else
            {
                (*port_cfg->P) &= (~pin);
            }
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   toggle gpio level
* @param   :   cfg: pointer to config of gpio to operate
* @retval  :   SUCCESS: set success
* @retval  :   E_PARAM: parameter error
*/
Port_Return_t Port2_Toggle(Port_Id_t id)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *port_cfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((port_cfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            *port_cfg->PNOT |= pin;
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   set gpio open drain status
* @param   :   id: id of gpio to operate
* @param   :   state: open drain state
* @retval  :   SUCCESS: set success
* @retval  :   E_PARAM: parameter error
*/
Port_Return_t Port2_OpenDrainSet(Port_Id_t id, boolean state)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *port_cfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((port_cfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            uint32 value = *port_cfg->PODC;

            if(state)
            {
                value |= pin;
            }
            else
            {
                value &= (~pin);
            }
            protected_write(*port_cfg->PPCMD, *port_cfg->PPROTS, *port_cfg->PODC, value);
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   set gpio push pull status
* @param   :   id: id of gpio to operate
* @param   :   state: push pull state
* @retval  :   SUCCESS: set success
* @retval  :   E_PARAM: parameter error
*/
Port_Return_t Port2_PushPullSet(Port_Id_t id, boolean state)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *port_cfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if((port_cfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            uint32 value = *port_cfg->PU;

            if(state)
            {
                value |= pin;
            }
            else
            {
                value &= (~pin);
            }
            protected_write(*port_cfg->PPCMD, *port_cfg->PPROTS, *port_cfg->PU, value);
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}

/*
* @brief   :   set gpio output drive status
* @param   :   id: id of gpio to operate
* @param   :   state: output drive state
* @retval  :   SUCCESS: set success
* @retval  :   E_PARAM: parameter error
*/
Port_Return_t Port2_StrengthSet(Port_Id_t id, boolean state)
{
    Port_Return_t ret = PORT_ERROR;

#if(PORT2_DEV_ERROR_DETECT == STD_ON)
    if(id >= PORT_ID_NUMBER)
    {
        ret = PORT_E_PARAM;
    }
    else if(port_cfgs[id].port >= PORT_PORT_NUM)
    {
        ret = PORT_E_PARAM;
    }
    else
#endif
    {
        const struct Port_DevCfg *port_cfg = &port_devCfgs[port_cfgs[id].port];
        uint16 pin = port_cfgs[id].pin;

        if(port_cfg->PDSC == NULL_PTR)
        {
            ret = PORT_E_PARAM;
        }
        else if((port_cfg->exist) & (pin == 0u))
        {
            ret = PORT_E_PARAM;
        }
        else
        {
            uint32 value = *port_cfg->PDSC;

            if(state)
            {
                value |= pin;
            }
            else
            {
                value &= (~pin);
            }
            protected_write(*port_cfg->PPCMD, *port_cfg->PPROTS, *port_cfg->PDSC, value);
            ret = PORT_SUCCESS;
        }
    }
    return ret;
}


