---------------------------------------------------------------------------------
-- Project      = G3M/G3KH SW CST                                              --
-- Module       = CST_common.inc                                               --
-- Version      = 1.2.4                                                        --
-- Date         = 10-11-2017                                                   --
---------------------------------------------------------------------------------
--                                  COPYRIGHT                                  --
---------------------------------------------------------------------------------
-- Copyright (c) 2014-2017 by Renesas Electronics Corporation                  --
---------------------------------------------------------------------------------
-- Purpose:                                                                    --
--   RH850G3M/RH850G3KH CORE SELF TEST                                         --
--   Condition Flags definitions                                               --
---------------------------------------------------------------------------------
--                                                                             --
-- Unless otherwise agreed upon in writing between your company and            --
-- Renesas Electronics Corporation the following shall apply!                  --
--                                                                             --
-- Warranty Disclaimer                                                         --
--                                                                             --
-- There is no warranty of any kind whatsoever granted by Renesas. Any         --
-- warranty is expressly disclaimed and excluded by Renesas, either expressed  --
-- or implied, including but not limited to those for non-infringement of      --
-- intellectual property, merchantability and/or fitness for the particular    --
-- purpose.                                                                    --
--                                                                             --
-- Renesas shall not have any obligation to maintain, service or provide bug   --
-- fixes for the supplied Product(s) and/or the Application.                   --
--                                                                             --
-- Each User is solely responsible for determining the appropriateness of      --
-- using the Product(s) and assumes all risks associated with its exercise     --
-- of rights under this Agreement, including, but not limited to the risks     --
-- and costs of program errors, compliance with applicable laws, damage to     --
-- or loss of data, programs or equipment, and unavailability or               --
-- interruption of operations.                                                 --
--                                                                             --
-- Limitation of Liability                                                     --
--                                                                             --
-- In no event shall Renesas be liable to the User for any incidental,         --
-- consequential, indirect, or punitive damage (including but not limited      --
-- to lost profits) regardless of whether such liability is based on breach    --
-- of contract, tort, strict liability, breach of warranties, failure of       --
-- essential purpose or otherwise and even if advised of the possibility of    --
-- such damages. Renesas shall not be liable for any services or products      --
-- provided by third party vendors, developers or consultants identified or    --
-- referred to the User by Renesas in connection with the Product(s) and/or    --
-- the Application.                                                            --
--                                                                             --
---------------------------------------------------------------------------------
-- Environment:                                                                --
--              Devices:  G3M/G3KH                                             --
--              Language: Green Hills Software, Compiler v2015.1.7             --
---------------------------------------------------------------------------------

#ifndef CST_COMMON_INC
#define CST_COMMON_INC

------------------------------------------------------------------------------
--	Condition flag definitions
------------------------------------------------------------------------------
	.SET		CC_V			0x0
	.SET		CC_NV			0x8
	.SET		CC_CL			0x1
	.SET		CC_NCNL 		0x9
	.SET		CC_Z			0x2
	.SET		CC_NZ			0xa
	.SET		CC_NH			0x3
	.SET		CC_H			0xb
	.SET		CC_SN			0x4
	.SET		CC_NSP			0xc
	.SET		CC_T			0x5
	.SET		CC_SA			0xd
	.SET		CC_LT			0x6
	.SET		CC_GE			0xe
	.SET		CC_LE			0x7
	.SET		CC_GT			0xf

------------------------------------------------------------------------------
--	FPU Condition flag definitions
------------------------------------------------------------------------------
	.SET		FC_F			0
	.SET		FC_UN			1
	.SET		FC_EQ			2
	.SET		FC_UEQ			3
	.SET		FC_OLT			4
	.SET		FC_ULT			5
	.SET		FC_OLE			6
	.SET		FC_ULE			7
	.SET		FC_SF			8
	.SET		FC_NGLE			9
	.SET		FC_SEQ			10
	.SET		FC_NGL			11
	.SET		FC_LT			12
	.SET		FC_NGE			13
	.SET		FC_LE			14
	.SET		FC_NGT			15

------------------------------------------------------------------------------
--	System Register definitions
------------------------------------------------------------------------------
	.SET		PSW_MASK_SATCYOVSZ	0xFFFFFFE0
	.SET		PSW_EXCEPTION_BIT	0x000000A0
	.SET		MCTL_MA_BIT		0x00000002
	.SET		PID_MASK_REV_ID		0xFFFFFFE0


#endif /* CST_COMMON_INC */

-- ============================================================================
-- =====        E n d   o f   F i l e   :   CST_common.inc                =====
-- ============================================================================
