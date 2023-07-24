/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup      Os_Hal
 *  \defgroup     Os_Hal_Derivative HAL Derivative
 *  \brief        Defines derivative specific functionality.
 *  \details
 *  This modules decides which HAL specific sub components are needed to implement HAL functionality on a specific
 *  derivative.
 *
 *  \{
 *
 * \file          Os_Hal_Derivative_Types.h
 *  \brief        Selects a derivative specific header and includes it.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_DERIVATIVE_TYPES_H
# define OS_HAL_DERIVATIVE_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# if defined(OS_CFG_DERIVATIVEGROUP_RH850C1H)                                                                           /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850C1H_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850C1M)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850C1M_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850C1MA2)                                                                       /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850C1MA2_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850D1X)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850D1x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850E1XFCC2)                                                                     /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850E1xFCC2_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850E1X)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850E1x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1H)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1H_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1H_HSM)                                                                     /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1H_HSM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1L)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1L_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1X)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1x_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1KM)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1KM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1KM_HSM)                                                                    /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1KM_HSM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1KH)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1KH_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850F1KH_HSM)                                                                    /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850F1KH_HSM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1HC)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1HC_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1HC_HSM)                                                                    /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1HC_HSM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1MC)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1MC_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1M)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1M_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1LC)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1LC_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850R1L)                                                                         /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850R1L_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850P1ME)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850P1ME_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850U2A8)                                                                        /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850U2A8_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850U2A8_HSM)                                                                    /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850U2A8_HSM_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850U2A16)                                                                       /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850U2A16_Types.h"
# elif defined(OS_CFG_DERIVATIVEGROUP_RH850U2A16_HSM)                                                                   /* COV_OS_DERIVATIVEGROUP */
#  include "Os_Hal_Derivative_RH850U2A16_HSM_Types.h"
# else
#  error "The selected derivative is not supported!"
# endif /* OS_CFG_DERIVATIVEGROUP_<> */

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_DERIVATIVE_TYPES_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_Types.h
 **********************************************************************************************************************/
