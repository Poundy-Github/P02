############################################################################### 
# File Name  : LinIf_check.mak 
# Description: Configuration check makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2019 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Refer to the LinIf_rules.mak file.
############################################################################### 

###############################################################################
# Support LinTp
#
# Check if LinTp usage setting is configured
###############################################################################
ifeq ($(LINIF_USE_LINTP),)
  $(error Error: LinIf_check.mak: Please set LINIF_USE_LINTP in LinIf_cfg.mak)
endif
