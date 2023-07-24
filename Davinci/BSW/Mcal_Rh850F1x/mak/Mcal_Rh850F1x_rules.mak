###############################################################################
# File Name  : Mcal_rules.mak                                                  #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2018 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# Aba          Andreas Barac             Vector Informatik GmbH               #
# virrsu       Roland Suess              Vector Informatik GmbH               #
# vircbl       Claudia Buhl              Vector Informatik GmbH               #
# virnid       Stefan Schmid             Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign    Description                                   #
# ----------   -------  ------  ----------------------------------------------#
# 2017-05-02   1.00.00  virrsu  AUTOSAR_RH850_F1K_MCAL_Ver4.01.00             #
#                               AUTOSAR_RH850_F1K_MCAL_Ver42.00.00            #
# 2018-01-11   1.01.00  virrsu  Consider Spi_Internal.c acc. to MCAL version  #
# 2018-01-29   1.02.00	virrsu	Update with several RH850F1K MCALs            #
# 2018-02-12   1.02.01	virrsu	Spi files are missing                         #
# 2018-04-17   1.03.00	virrsu	Using placeholder feature                     #
# 2018-08-28   1.03.01	vircbl	Added defaults for component switches         #
# 2019-09-13   1.03.02  virnid  Changed MCAL_CORE_PATH in Mcal_Rh850F1x_defs.mak #
# 2020-01-30   1.04.00  virnid  Integration od Wdg DriverB and DriverC		  #
# 2020-02-11   1.05.00  virnid  Integration of F1k, F1KH, F1KM Ver4.05.00	  #
#								and Ver42.05.00								  #
# 2020-06-25   1.05.01  virnid  Added switches for Wdg Driver				  #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#

#Defaults for component switches
#Can be overwritten in Makefile.project.part.defines
ifeq ($(MCAL_EXCLUDE_ADC),)
MCAL_EXCLUDE_ADC = 0
endif
ifeq ($(MCAL_EXCLUDE_DIO),)
MCAL_EXCLUDE_DIO = 0
endif
ifeq ($(MCAL_EXCLUDE_FLS),)
MCAL_EXCLUDE_FLS = 0
endif
ifeq ($(MCAL_EXCLUDE_GPT),)
MCAL_EXCLUDE_GPT = 0
endif
ifeq ($(MCAL_EXCLUDE_ICU),)
MCAL_EXCLUDE_ICU = 0
endif
ifeq ($(MCAL_EXCLUDE_MCU),)
MCAL_EXCLUDE_MCU = 0
endif
ifeq ($(MCAL_EXCLUDE_PORT),)
MCAL_EXCLUDE_PORT = 0
endif
ifeq ($(MCAL_EXCLUDE_PWM),)
MCAL_EXCLUDE_PWM = 0
endif
ifeq ($(MCAL_EXCLUDE_SPI),)
MCAL_EXCLUDE_SPI = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG),)
MCAL_EXCLUDE_WDG = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG_DRIVER_A),)
MCAL_EXCLUDE_WDG_DRIVER_A  = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG_DRIVER_B),)
MCAL_EXCLUDE_WDG_DRIVER_B  = 1
endif
ifeq ($(MCAL_EXCLUDE_WDG_DRIVER_C),)
MCAL_EXCLUDE_WDG_DRIVER_C  = 1
endif

ifeq ($(MCAL_EXCLUDE_CORTST),)
MCAL_EXCLUDE_CORTST = 1
endif
ifeq ($(MCAL_EXCLUDE_FLSTST),)
MCAL_EXCLUDE_FLSTST = 1
endif
ifeq ($(MCAL_EXCLUDE_RAMTST),)
MCAL_EXCLUDE_RAMTST = 1
endif


#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_canlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      +=

# e.g.: CC_FILES_TO_BUILD       += drv\can_drv.c

#AUTOSAR version detected from the MCAL
MCAL_AUTOSAR_VERSION = 4.2.2
#MCAL package version detected from the MCAL
MCAL_PACKAGE_VERSION = 42.05.00
#Path to Mcal source and include files
MCAL_PATH = ..\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00

CC_INCLUDE_PATH    += $(MCAL_PATH)\X1X\common_platform\generic\include $(MCAL_PATH)\X1X\F1x\common_family\include\F1KM

ifneq ($(MCAL_EXCLUDE_ADC),1)
ADC_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\adc
CC_FILES_TO_BUILD  += $(ADC_BASE_PATH)\src\Adc*.c
CC_INCLUDE_PATH    += $(ADC_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_DIO),1)
DIO_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\dio
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio*.c
CC_INCLUDE_PATH    += $(DIO_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
FLS_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\fls
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls*.c
CC_INCLUDE_PATH    += $(FLS_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
GPT_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\gpt
CC_FILES_TO_BUILD  += $(GPT_BASE_PATH)\src\Gpt*.c
CC_INCLUDE_PATH    += $(GPT_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
ICU_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\icu
CC_FILES_TO_BUILD  += $(ICU_BASE_PATH)\src\Icu*.c
CC_INCLUDE_PATH    += $(ICU_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
MCU_BASE_PATH       = $(MCAL_PATH)\X1X\F1x\modules\mcu
CC_FILES_TO_BUILD  += $(MCU_BASE_PATH)\src\Mcu*.c
#ASM_FILES_TO_BUILD += $(MCU_BASE_PATH)\src\Mcu_RRamCopy_asm.850
CC_INCLUDE_PATH    += $(MCU_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_PORT),1)
PORT_BASE_PATH      = $(MCAL_PATH)\X1X\common_platform\modules\port
CC_FILES_TO_BUILD  += $(PORT_BASE_PATH)\src\Port*.c
CC_INCLUDE_PATH    += $(PORT_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_PWM),1)
PWM_BASE_PATH       = $(MCAL_PATH)\X1X
CC_FILES_TO_BUILD  += $(PWM_BASE_PATH)\common_platform\modules\pwm\src\Pwm*.c $(PWM_BASE_PATH)\F1x\common_family\src\pwm_diag\Pwm*.c
CC_INCLUDE_PATH    += $(PWM_BASE_PATH)\common_platform\modules\pwm\include $(PWM_BASE_PATH)\F1x\common_family\include\pwm_diag
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
SPI_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\spi
CC_FILES_TO_BUILD  += $(SPI_BASE_PATH)\src\Spi*.c $(SPI_BASE_PATH)\src\CSIX\Spi*.c $(SPI_BASE_PATH)\src\DMAC\Spi*.c
CC_INCLUDE_PATH    += $(SPI_BASE_PATH)\include $(SPI_BASE_PATH)\include\DMAC $(SPI_BASE_PATH)\include\CSIX
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
WDG_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\wdg

	ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_A),1)
		ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_B),1)
			$(error DriverA and Driver B are selected!)
		else
			ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_C),1)
				$(error Driver A and Driver C are selected!)
			else
				CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg_59_DriverA*.c 
			endif
		endif
	else
		ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_B),1)
			ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_C),1)
				$(error Driver B and Driver C are selected!)
			else
				CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg_59_DriverB*.c
			endif
		else
			ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_C),1)
				CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg_59_DriverC*.c
			else
				$(error No Driver selected!)
			endif
		endif
	endif

CC_INCLUDE_PATH    += $(WDG_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_RAMTST),1)
RAMTST_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\ramtst
CC_FILES_TO_BUILD  += $(RAMTST_BASE_PATH)\src\RamTst*.c
CC_INCLUDE_PATH    += $(RAMTST_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_FLSTST),1)
FLSTST_BASE_PATH       = $(MCAL_PATH)\X1X\common_platform\modules\flstst
CC_FILES_TO_BUILD  += $(FLSTST_BASE_PATH)\src\FlsTst*.c
CC_INCLUDE_PATH    += $(FLSTST_BASE_PATH)\include
endif

ifneq ($(MCAL_EXCLUDE_CORTST),1)
CORTST_BASE_PATH    = $(MCAL_PATH)\X1X\common_platform\modules\cortst
CORTST_ASM_PATH     = $(MCAL_PATH)\X1X\F1x\modules\cortst\src\G3KH
CC_FILES_TO_BUILD  += $(CORTST_BASE_PATH)\src\CorTst*.c \
					  $(MCAL_PATH)\X1X\F1x\modules\cortst\src\sw_cst.c \
					  $(MCAL_PATH)\X1X\F1x\modules\cortst\src\checksignature.c
CC_INCLUDE_PATH    += $(CORTST_BASE_PATH)\include $(MCAL_PATH)\X1X\F1x\modules\cortst\include $(MCAL_PATH)\X1X\F1x\modules\cortst\include\G3KH
ASM_FILES_TO_BUILD += $(CORTST_ASM_PATH)\CPU_arithmetic_ope.850 $(CORTST_ASM_PATH)\CPU_bitinsert_ope.850 $(CORTST_ASM_PATH)\CPU_bitsearch_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_bit_ope.850 $(CORTST_ASM_PATH)\CPU_boolean_ope.850 $(CORTST_ASM_PATH)\CPU_branch_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_condition_ope.850 $(CORTST_ASM_PATH)\CPU_cond_br_ope.850 $(CORTST_ASM_PATH)\CPU_cond_data_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_data_ope.850 $(CORTST_ASM_PATH)\CPU_div_ope.850 $(CORTST_ASM_PATH)\CPU_hsdiv_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_jump_ope.850 $(CORTST_ASM_PATH)\CPU_loadlink_ope.850 $(CORTST_ASM_PATH)\CPU_load_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_loop_ope.850 $(CORTST_ASM_PATH)\CPU_mac_ope.850 $(CORTST_ASM_PATH)\CPU_memory_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_mul_ope.850 $(CORTST_ASM_PATH)\CPU_saturated_ope.850 $(CORTST_ASM_PATH)\CPU_shift_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_special_ope.850 $(CORTST_ASM_PATH)\CPU_store_ope.850 $(CORTST_ASM_PATH)\CPU_syscall_ope.850 \
					  $(CORTST_ASM_PATH)\CPU_trap_ope.850 $(CORTST_ASM_PATH)\FPU_cmov_ope.850 $(CORTST_ASM_PATH)\FPU_calc_ope.850\
					  $(CORTST_ASM_PATH)\FPU_cmp_ope.850 $(CORTST_ASM_PATH)\FPU_cvt_ope.850 $(CORTST_ASM_PATH)\FPU_fmul_ope.850 \
					  $(CORTST_ASM_PATH)\FPU_roundoff_ope.850 $(CORTST_ASM_PATH)\SRU_exc_ope.850 $(CORTST_ASM_PATH)\SRU_fpu_ope.850 \
					  $(CORTST_ASM_PATH)\SRU_loadstore_ope.850 $(CORTST_ASM_PATH)\SRU_mpu_ope.850 $(CORTST_ASM_PATH)\CST_common_func.850 \
					  $(CORTST_ASM_PATH)\CST_common_table.850 $(CORTST_ASM_PATH)\CST_hw_module.850
endif

CPP_FILES_TO_BUILD +=
ASM_FILES_TO_BUILD +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c
ifneq ($(MCAL_EXCLUDE_ADC),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Adc*.c
endif

ifneq ($(MCAL_EXCLUDE_CORTST),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\CorTst*.c
endif

ifneq ($(MCAL_EXCLUDE_DIO),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Dio*.c
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fls_*.c
endif

ifneq ($(MCAL_EXCLUDE_FLSTST),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\FlsTst*.c
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gpt*.c
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Icu*.c
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
GENERATED_SOURCE_FILES  +=  $(GENDATA_DIR)\src\Mcu*.c
endif

ifneq ($(MCAL_EXCLUDE_PORT),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Port*.c
endif

ifneq ($(MCAL_EXCLUDE_PWM),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Pwm*.c
endif

ifneq ($(MCAL_EXCLUDE_RAMTST),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\RamTst*.c
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Spi*.c
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
	ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_A),1)
		GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_59_DriverA*.c
	endif
	ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_B),1)
		GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_59_DriverB*.c
	endif
	ifneq ($(MCAL_EXCLUDE_WDG_DRIVER_C),1)
		GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_59_DriverC*.c
	endif
endif


ADDITIONAL_INCLUDES     += $(GENDATA_DIR)\include

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################
