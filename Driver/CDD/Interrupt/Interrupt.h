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
 * @file:      Interrupt.h
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
 *             %head of header file guard%
 */
#ifndef __INTERRUPT_H
#define __INTERRUPT_H

/*
 *  %header file in this project/library%
 */
#include "Cdd_Common.h"


/*
 *  %third-party header file%
 */

/*
 *  %system/C-run-time header file%
 */


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */
/* Specify 16 interrupt priority levels (P3xxx,P2xxx,P1xxx,P0xxx) */
#define INT_PRIORITY_HIGHEST      (0x00u)  /* Level 0 (highest) */
#define INT_PRIORITY_LEVEL1       (0x01u)  /* Level 1 */
#define INT_PRIORITY_LEVEL2       (0x02u)  /* Level 2 */
#define INT_PRIORITY_LEVEL3       (0x03u)  /* Level 3 */
#define INT_PRIORITY_LEVEL4       (0x04u)  /* Level 4 */
#define INT_PRIORITY_LEVEL5       (0x05u)  /* Level 5 */
#define INT_PRIORITY_LEVEL6       (0x06u)  /* Level 6 */
#define INT_PRIORITY_LEVEL7       (0x07u)  /* Level 7 */
#define INT_PRIORITY_LEVEL8       (0x08u)  /* Level 8 */
#define INT_PRIORITY_LEVEL9       (0x09u)  /* Level 9 */
#define INT_PRIORITY_LEVEL10      (0x0Au)  /* Level 10 */
#define INT_PRIORITY_LEVEL11      (0x0Bu)  /* Level 11 */
#define INT_PRIORITY_LEVEL12      (0x0Cu)  /* Level 12 */
#define INT_PRIORITY_LEVEL13      (0x0Du)  /* Level 13 */
#define INT_PRIORITY_LEVEL14      (0x0Eu)  /* Level 14 */
#define INT_PRIORITY_LOWEST       (0x0Fu)  /* Level 15 (lowest) */

#define INT_PRIORITY(n)           (BIT((n), 0))   /* Priority */

#define INT_TR_DIRECT             (BIT(0u, 6))    /* Table reference */
#define INT_TR_TABLE              (BIT(1u, 6))    /* Table reference */

#define INT_MASK_ENABLE           (BIT(0u, 7))    /* Mask enable */
#define INT_MASK_DISABLE          (BIT(1u, 7))    /* Mask disable */

#define INT_REQUEST_NO_ACK        (BIT(0, 12))   /* Request flag ack */
#define INT_REQUEST_ACK           (BIT(1u, 12))   /* Request flag ack */

#define INT_EDGE_DETECT           (BIT(0u, 15))   /* Edge detection */
#define INT_LEVEL_DETECT          (BIT(1u, 15))   /* Level detection */

struct Int_CtrlReg1
{
    __IO uint16 CCSIH2IC_1;                  /* CCSIH2IC_1      */
    __IO uint16 CCSIH3IC_1;                  /* CCSIH3IC_1      */
    __IO uint16 CCSIH2IR_1;                  /* CCSIH2IR_1      */
    __IO uint16 CCSIH2IRE_1;                 /* CCSIH2IRE_1     */
    __IO uint16 CCSIH2IJC_1;                 /* CCSIH2IJC_1     */
    __IO uint16 CCSIH3IR_1;                  /* CCSIH3IR_1      */
    __IO uint16 CCSIH3IRE_1;                 /* CCSIH3IRE_1     */
    __IO uint16 CCSIH3IJC_1;                 /* CCSIH3IJC_1     */
    __IO uint16 CCSIH1IC_1;                  /* CCSIH1IC_1      */
    __IO uint16 CCSIH1IR_1;                  /* CCSIH1IR_1      */
    __IO uint16 CADCA0I0;                    /* CADCA0I0        */
    __IO uint16 CADCA0I1;                    /* CADCA0I1        */
    __IO uint16 CADCA0I2;                    /* CADCA0I2        */
    __IO uint16 CDCUTDI;                     /* CDCUTDI         */
    __IO uint16 CRCANGERR0;                  /* CRCANGERR0      */
    __IO uint16 CRCANGRECC0;                 /* CRCANGRECC0     */
    __IO uint16 CRCAN0ERR;                   /* CRCAN0ERR       */
    __IO uint16 CRCAN0REC;                   /* CRCAN0REC       */
    __IO uint16 CRCAN0TRX;                   /* CRCAN0TRX       */
    __IO uint16 CCSIG0IC;                    /* CCSIG0IC        */
    __IO uint16 CCSIG0IR;                    /* CCSIG0IR        */
    __IO uint16 CCSIH0IC;                    /* CCSIH0IC        */
    __IO uint16 CCSIH0IR;                    /* CCSIH0IR        */
    __IO uint16 CCSIH0IRE;                   /* CCSIH0IRE       */
    uint8 dummy1[56];                         /* Reserved         */
    __IO uint16 FNC;                          /* FNC              */
    __IO uint16 FIC;                          /* FIC              */
    uint8 dummy2[116];                        /* Reserved         */
    __IO uint16 CIMR0;                        /* IMR0            */
};

struct Int_CtrlReg2
{
    __IO uint16 CADCA0I2_2;                            /* CADCA0I2_2      */
    __IO uint16 CRLIN30;                               /* CRLIN30         */
    __IO uint16 CRLIN30UR0;                            /* CRLIN30UR0      */
    __IO uint16 CRLIN30UR1;                            /* CRLIN30UR1      */
    __IO uint16 CRLIN30UR2;                            /* CRLIN30UR2      */
    __IO uint16 CP0;                                   /* CP0             */
    __IO uint16 CP1;                                   /* CP1             */
    __IO uint16 CP2;                                   /* CP2             */
    __IO uint16 CWDTA0;                                /* CWDTA0          */
    __IO uint16 CWDTA1;                                /* CWDTA1          */
    uint8 dummy1[2];                                    /* Reserved         */
    __IO uint16 CP3;                                   /* CP3             */
    __IO uint16 CP4;                                   /* CP4             */
    __IO uint16 CP5;                                   /* CP5             */
    __IO uint16 CP10;                                  /* CP10            */
    __IO uint16 CP11;                                  /* CP11            */
    __IO uint16 CTAUD0I1;                              /* CTAUD0I1        */
    __IO uint16 CTAUD0I3;                              /* CTAUD0I3        */
    __IO uint16 CTAUD0I5;                              /* CTAUD0I5        */
    __IO uint16 CTAUD0I7;                              /* CTAUD0I7        */
    __IO uint16 CTAUD0I9;                              /* CTAUD0I9        */
    __IO uint16 CTAUD0I11;                             /* CTAUD0I11       */
    __IO uint16 CTAUD0I13;                             /* CTAUD0I13       */
    __IO uint16 CTAUD0I15;                             /* CTAUD0I15       */
    __IO uint16 CADCA0ERR;                             /* CADCA0ERR       */
    __IO uint16 CCSIG0IRE;                             /* CCSIG0IRE       */
    __IO uint16 CRLIN20;                               /* CRLIN20         */
    __IO uint16 CRLIN21;                               /* CRLIN21         */
    __IO uint16 CDMA0;                                 /* CDMA0           */
    __IO uint16 CDMA1;                                 /* CDMA1           */
    __IO uint16 CDMA2;                                 /* CDMA2           */
    __IO uint16 CDMA3;                                 /* CDMA3           */
    __IO uint16 CDMA4;                                 /* CDMA4           */
    __IO uint16 CDMA5;                                 /* CDMA5           */
    __IO uint16 CDMA6;                                 /* CDMA6           */
    __IO uint16 CDMA7;                                 /* CDMA7           */
    __IO uint16 CDMA8;                                 /* CDMA8           */
    __IO uint16 CDMA9;                                 /* CDMA9           */
    __IO uint16 CDMA10;                                /* CDMA10          */
    __IO uint16 CDMA11;                                /* CDMA11          */
    __IO uint16 CDMA12;                                /* CDMA12          */
    __IO uint16 CDMA13;                                /* CDMA13          */
    __IO uint16 CDMA14;                                /* CDMA14          */
    __IO uint16 CDMA15;                                /* CDMA15          */
    __IO uint16 CRIIC0TI;                              /* CRIIC0TI        */
    __IO uint16 CRIIC0EE;                              /* CRIIC0EE        */
    __IO uint16 CRIIC0RI;                              /* CRIIC0RI        */
    __IO uint16 CRIIC0TEI;                             /* CRIIC0TEI       */
    __IO uint16 CTAUJ0I0;                              /* CTAUJ0I0        */
    __IO uint16 CTAUJ0I1;                              /* CTAUJ0I1        */
    __IO uint16 CTAUJ0I2;                              /* CTAUJ0I2        */
    __IO uint16 CTAUJ0I3;                              /* CTAUJ0I3        */
    __IO uint16 COSTM0;                                /* COSTM0          */
    __IO uint16 CENCA0IOV;                             /* CENCA0IOV       */
    __IO uint16 CENCA0IUD;                             /* CENCA0IUD       */
    __IO uint16 CENCA0I0;                              /* CENCA0I0        */
    __IO uint16 CENCA0I1;                              /* CENCA0I1        */
    __IO uint16 CENCA0IEC;                             /* CENCA0IEC       */
    __IO uint16 CKR0;                                  /* CKR0            */
    __IO uint16 CQFULL;                                /* CQFULL          */
    __IO uint16 CPWGA0;                                /* CPWGA0          */
    __IO uint16 CPWGA1;                                /* CPWGA1          */
    __IO uint16 CPWGA2;                                /* CPWGA2          */
    __IO uint16 CPWGA3;                                /* CPWGA3          */
    __IO uint16 CPWGA8;                                /* CPWGA8          */
    __IO uint16 CPWGA9;                                /* CPWGA9          */
    __IO uint16 CPWGA10;                               /* CPWGA10         */
    __IO uint16 CPWGA11;                               /* CPWGA11         */
    __IO uint16 CPWGA12;                               /* CPWGA12         */
    __IO uint16 CPWGA13;                               /* CPWGA13         */
    __IO uint16 CPWGA14;                               /* CPWGA14         */
    __IO uint16 CPWGA15;                               /* CPWGA15         */
    uint8 dummy2[12];                                   /* Reserved         */
    __IO uint16 CFLERR;                                /* CFLERR          */
    __IO uint16 CFLENDNM;                              /* CFLENDNM        */
    __IO uint16 CCWEND;                                /* CCWEND          */
    __IO uint16 CRCAN1ERR;                             /* CRCAN1ERR       */
    __IO uint16 CRCAN1REC;                             /* CRCAN1REC       */
    __IO uint16 CRCAN1TRX;                             /* CRCAN1TRX       */
    __IO uint16 CCSIH1IC;                              /* CCSIH1IC        */
    __IO uint16 CCSIH1IR;                              /* CCSIH1IR        */
    __IO uint16 CCSIH1IRE;                             /* CCSIH1IRE      */
    __IO uint16 CCSIG0IR_2;                            /* CCSIG0IR_2      */
    __IO uint16 CRLIN31;                               /* CRLIN31         */
    __IO uint16 CRLIN31UR0;                            /* CRLIN31UR0      */
    __IO uint16 CRLIN31UR1;                            /* CRLIN31UR1      */
    __IO uint16 CRLIN31UR2;                            /* CRLIN31UR2      */
    __IO uint16 CPWGA20;                               /* CPWGA20         */
    __IO uint16 CPWGA21;                               /* CPWGA21         */
    __IO uint16 CPWGA22;                               /* CPWGA22         */
    __IO uint16 CPWGA23;                               /* CPWGA23         */
    __IO uint16 CP6;                                   /* CP6             */
    __IO uint16 CP7;                                   /* CP7             */
    __IO uint16 CP8;                                   /* CP8             */
    __IO uint16 CP12;                                  /* CP12            */
    __IO uint16 CCSIH2IC;                              /* CCSIH2IC        */
    __IO uint16 CCSIH2IR;                              /* CCSIH2IR        */
    __IO uint16 CCSIH2IRE;                             /* CCSIH2IRE       */
    __IO uint16 CCSIH2IJC;                             /* CCSIH2IJC       */
    uint8 dummy3[12];                                   /* Reserved         */
    __IO uint16 CTAUB0I0;                              /* CTAUB0I0        */
    __IO uint16 CTAUB0I1;                              /* CTAUB0I1        */
    __IO uint16 CTAUB0I2;                              /* CTAUB0I2        */
    __IO uint16 CPWGA16;                               /* CPWGA16         */
    __IO uint16 CTAUB0I4;                              /* CTAUB0I4        */
    __IO uint16 CPWGA17;                               /* CPWGA17         */
    __IO uint16 CTAUB0I6;                              /* CTAUB0I6        */
    __IO uint16 CPWGA18;                               /* CPWGA18         */
    __IO uint16 CTAUB0I8;                              /* CTAUB0I8        */
    __IO uint16 CPWGA19;                               /* CPWGA19         */
    __IO uint16 CTAUB0I10;                             /* CTAUB0I10       */
    __IO uint16 CPWGA26;                               /* CPWGA26         */
    __IO uint16 CTAUB0I12;                             /* CTAUB0I12       */
    __IO uint16 CPWGA30;                               /* CPWGA30         */
    __IO uint16 CTAUB0I14;                             /* CTAUB0I14       */
    __IO uint16 CPWGA31;                               /* CPWGA31         */
    __IO uint16 CCSIH3IC;                              /* CCSIH3IC        */
    __IO uint16 CCSIH3IR;                              /* CCSIH3IR        */
    __IO uint16 CCSIH3IRE;                             /* CCSIH3IRE       */
    __IO uint16 CCSIH3IJC;                             /* CCSIH3IJC       */
    __IO uint16 CRLIN22;                               /* CRLIN22         */
    __IO uint16 CRLIN23;                               /* CRLIN23         */
    __IO uint16 CRLIN32;                               /* CRLIN32         */
    __IO uint16 CRLIN32UR0;                            /* CRLIN32UR0      */
    __IO uint16 CRLIN32UR1;                            /* CRLIN32UR1      */
    __IO uint16 CRLIN32UR2;                            /* CRLIN32UR2      */
    __IO uint16 CTAUJ1I0;                              /* CTAUJ1I0        */
    __IO uint16 CTAUJ1I1;                              /* CTAUJ1I1        */
    __IO uint16 CTAUJ1I2;                              /* CTAUJ1I2        */
    __IO uint16 CTAUJ1I3;                              /* CTAUJ1I3        */
    uint8 dummy4[24];                                   /* Reserved         */
    __IO uint16 CPWGA24;                               /* CPWGA24         */
    __IO uint16 CPWGA25;                               /* CPWGA25         */
    __IO uint16 CPWGA27;                               /* CPWGA27         */
    __IO uint16 CPWGA28;                               /* CPWGA28         */
    __IO uint16 CPWGA29;                               /* CPWGA29         */
    __IO uint16 CPWGA32;                               /* CPWGA32         */
    __IO uint16 CPWGA33;                               /* CPWGA33         */
    __IO uint16 CPWGA34;                               /* CPWGA34         */
    __IO uint16 CPWGA35;                               /* CPWGA35         */
    __IO uint16 CPWGA36;                               /* CPWGA36         */
    __IO uint16 CPWGA37;                               /* CPWGA37         */
    __IO uint16 CPWGA38;                               /* CPWGA38         */
    __IO uint16 CPWGA39;                               /* CPWGA39         */
    __IO uint16 CPWGA40;                               /* CPWGA40         */
    __IO uint16 CPWGA41;                               /* CPWGA41         */
    __IO uint16 CPWGA42;                               /* CPWGA42         */
    __IO uint16 CPWGA43;                               /* CPWGA43         */
    __IO uint16 CPWGA44;                               /* CPWGA44         */
    __IO uint16 CPWGA45;                               /* CPWGA45         */
    __IO uint16 CPWGA46;                               /* CPWGA46         */
    __IO uint16 CPWGA47;                               /* CPWGA47         */
    __IO uint16 CP9;                                   /* CP9             */
    __IO uint16 CP13;                                  /* CP13            */
    __IO uint16 CP14;                                  /* CP14            */
    __IO uint16 CP15;                                  /* CP15            */
    __IO uint16 CRTCA01S;                              /* CRTCA01S        */
    __IO uint16 CRTCA0AL;                              /* CRTCA0AL        */
    __IO uint16 CRTCA0R;                               /* CRTCA0R         */
    __IO uint16 CADCA1ERR;                             /* CADCA1ERR       */
    __IO uint16 CADCA1I0;                              /* CADCA1I0        */
    __IO uint16 CADCA1I1;                              /* CADCA1I1        */
    __IO uint16 CADCA1I2;                              /* CADCA1I2        */
    uint8 dummy5[2];                                    /* Reserved         */
    __IO uint16 CRCAN2ERR;                             /* CRCAN2ERR       */
    __IO uint16 CRCAN2REC;                             /* CRCAN2REC       */
    __IO uint16 CRCAN2TRX;                             /* CRCAN2TRX       */
    __IO uint16 CRCAN3ERR;                             /* CRCAN3ERR       */
    __IO uint16 CRCAN3REC;                             /* CRCAN3REC       */
    __IO uint16 CRCAN3TRX;                             /* CRCAN3TRX       */
    __IO uint16 CCSIG1IC;                              /* CCSIG1IC        */
    __IO uint16 CCSIG1IR;                              /* CCSIG1IR        */
    __IO uint16 CCSIG1IRE;                             /* CCSIG1IRE       */
    __IO uint16 CRLIN24;                               /* CRLIN24         */
    __IO uint16 CRLIN25;                               /* CRLIN25         */
    __IO uint16 CRLIN33;                               /* CRLIN33         */
    __IO uint16 CRLIN33UR0;                            /* CRLIN33UR0      */
    __IO uint16 CRLIN33UR1;                            /* CRLIN33UR1      */
    __IO uint16 CRLIN33UR2;                            /* CRLIN33UR2      */
    __IO uint16 CRLIN34;                               /* CRLIN34         */
    __IO uint16 CRLIN34UR0;                            /* CRLIN34UR0      */
    __IO uint16 CRLIN34UR1;                            /* CRLIN34UR1      */
    __IO uint16 CRLIN34UR2;                            /* CRLIN34UR2      */
    __IO uint16 CRLIN35;                               /* CRLIN35         */
    __IO uint16 CRLIN35UR0;                            /* CRLIN35UR0      */
    __IO uint16 CRLIN35UR1;                            /* CRLIN35UR1      */
    __IO uint16 CRLIN35UR2;                            /* CRLIN35UR2      */
    __IO uint16 CPWGA48;                               /* CPWGA48         */
    __IO uint16 CPWGA49;                               /* CPWGA49         */
    __IO uint16 CPWGA50;                               /* CPWGA50         */
    __IO uint16 CPWGA51;                               /* CPWGA51         */
    __IO uint16 CPWGA52;                               /* CPWGA52         */
    __IO uint16 CPWGA53;                               /* CPWGA53         */
    __IO uint16 CPWGA54;                               /* CPWGA54         */
    __IO uint16 CPWGA55;                               /* CPWGA55         */
    __IO uint16 CPWGA56;                               /* CPWGA56         */
    __IO uint16 CPWGA57;                               /* CPWGA57         */
    __IO uint16 CPWGA58;                               /* CPWGA58         */
    __IO uint16 CPWGA59;                               /* CPWGA59         */
    __IO uint16 CPWGA60;                               /* CPWGA60         */
    __IO uint16 CPWGA61;                               /* CPWGA61         */
    __IO uint16 CPWGA62;                               /* CPWGA62         */
    __IO uint16 CPWGA63;                               /* CPWGA63         */
    __IO uint16 CTAUB1I0;                              /* CTAUB1I0        */
    __IO uint16 CTAUB1I1;                              /* CTAUB1I1        */
    __IO uint16 CTAUB1I2;                              /* CTAUB1I2        */
    __IO uint16 CTAUB1I3;                              /* CTAUB1I3        */
    __IO uint16 CTAUB1I4;                              /* CTAUB1I4        */
    __IO uint16 CTAUB1I5;                              /* CTAUB1I5        */
    __IO uint16 CTAUB1I6;                              /* CTAUB1I6        */
    __IO uint16 CTAUB1I7;                              /* CTAUB1I7        */
    __IO uint16 CTAUB1I8;                              /* CTAUB1I8        */
    __IO uint16 CTAUB1I9;                              /* CTAUB1I9        */
    __IO uint16 CTAUB1I10;                             /* CTAUB1I10       */
    __IO uint16 CTAUB1I11;                             /* CTAUB1I11       */
    __IO uint16 CTAUB1I12;                             /* CTAUB1I12       */
    __IO uint16 CTAUB1I13;                             /* CTAUB1I13       */
    __IO uint16 CTAUB1I14;                             /* CTAUB1I14       */
    __IO uint16 CTAUB1I15;                             /* CTAUB1I15       */
    __IO uint16 CRCAN4ERR;                             /* CRCAN4ERR       */
    __IO uint16 CRCAN4REC;                             /* CRCAN4REC       */
    __IO uint16 CRCAN4TRX;                             /* CRCAN4TRX       */
    __IO uint16 CRLIN26;                               /* CRLIN26         */
    __IO uint16 CRLIN27;                               /* CRLIN27         */
    __IO uint16 CPWGA64;                               /* CPWGA64         */
    __IO uint16 CPWGA65;                               /* CPWGA65         */
    __IO uint16 CPWGA66;                               /* CPWGA66         */
    __IO uint16 CPWGA67;                               /* CPWGA67         */
    __IO uint16 CPWGA68;                               /* CPWGA68         */
    __IO uint16 CPWGA69;                               /* CPWGA69         */
    __IO uint16 CPWGA70;                               /* CPWGA70         */
    __IO uint16 CPWGA71;                               /* CPWGA71         */
    __IO uint16 CRLIN28;                               /* CRLIN28         */
    __IO uint16 CRLIN29;                               /* CRLIN29         */
    __IO uint16 CRCAN5ERR;                             /* CRCAN5ERR       */
    __IO uint16 CRCAN5REC;                             /* CRCAN5REC       */
    __IO uint16 CRCAN5TRX;                             /* CRCAN5TRX       */
    uint8 dummy6[58];                                   /* Reserved         */
    __IO uint16 CRCANGERR1;                            /* CRCANGERR1      */
    __IO uint16 CRCANGRECC1;                           /* CRCANGRECC1     */
    __IO uint16 CRCAN6ERR;                             /* CRCAN6ERR       */
    __IO uint16 CRCAN6REC;                             /* CRCAN6REC       */
    __IO uint16 CRCAN6TRX;                             /* CRCAN6TRX       */
    uint8 dummy7[64];                                   /* Reserved         */
    __IO uint16 CDPE;                                  /* CDPE            */
    __IO uint16 CAPE;                                  /* CAPE            */
    uint8 dummy8[312];                                  /* Reserved         */
    __IO uint16 CIMR1;                                   /* IMR1             */
    __IO uint16 CIMR2;                                   /* IMR2             */
    __IO uint16 CIMR3;                                   /* IMR3             */
    __IO uint16 CIMR4;                                   /* IMR4             */
    __IO uint16 CIMR5;                                   /* IMR5             */
    __IO uint16 CIMR6;                                   /* IMR6             */
    __IO uint16 CIMR7;                                   /* IMR7             */
    __IO uint16 CIMR8;                                   /* IMR8             */
    __IO uint16 CIMR9;                                   /* IMR9             */
    __IO uint16 CIMR10;                                  /* IMR10            */
    __IO uint16 CIMR11;                                  /* IMR11            */
};

#define INT_CTRL1 (*(struct Int_CtrlReg1 *)0xFFFEEA10)   /* INTC1 */
#define INT_CTRL2 (*(struct Int_CtrlReg2 *)0xFFFFB040)   /* INTC2 */


/*
 *  %function declaration%
 */

/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif
