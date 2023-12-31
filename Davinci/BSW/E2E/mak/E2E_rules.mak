############################################################################### 
# File Name  : E2E_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2020 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2010-05-31  jk      initial creation
# 1.00.00   2010-06-14  Nh      correct file path
# 1.00.00   2015-07-03  gmi     Profile 5 and Profile 6 were added
# 1.01.00   2015-10-20  gmi     Profile JLR was added
# 1.02.00   2016-11-25  gmi     Profile 7 was added
# 1.03.00   2019-02-06  vircbl  Added support of component-based SIP structure
# 1.03.01   2020-03-16  virsrl  Added support of profile 11. Naming corrections.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################


###############################################################
# REGISTRY
#

LIBRARIES_TO_BUILD      += E2E

E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_SM.c E2E$(BSW_SRC_DIR)\E2E.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_SM.c E2E$(BSW_SRC_DIR)\E2E.c

ifeq ($(E2E_USE_PROFILE_01),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P01.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P01.c
endif
ifeq ($(E2E_USE_PROFILE_02),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P02.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P02.c
endif
ifeq ($(E2E_USE_PROFILE_04),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P04.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P04.c
endif
ifeq ($(E2E_USE_PROFILE_05),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P05.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P05.c
endif
ifeq ($(E2E_USE_PROFILE_06),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P06.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P06.c
endif
ifeq ($(E2E_USE_PROFILE_07),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P07.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P07.c
endif
ifeq ($(E2E_USE_PROFILE_11),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_P11.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_P11.c
endif
ifeq ($(E2E_USE_PROFILE_JLR),1)
E2E_FILES                               += E2E$(BSW_SRC_DIR)\E2E_PJLR.c
CC_FILES_TO_BUILD                       += E2E$(BSW_SRC_DIR)\E2E_PJLR.c
endif


CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

GENERATED_SOURCE_FILES  +=

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
###############################################################


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


