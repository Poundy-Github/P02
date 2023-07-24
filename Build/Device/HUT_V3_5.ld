/*===========================================================================*/
/* Module       = App_GLOBAL_F1KM_Sample.ld                                  */
/* Version      = V1.10                                                      */
/*                extracted from device file dr7f701610.dvf                  */
/*                by DeFiXRH850 0.8.0.4                                      */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2017 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose:     Template of linker directive file                            */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* Environment:                                                              */
/*          Devices RH850/F1KM: R7F701634, R7F701635, R7F701636, R7F701637   */
/*                              R7F701638, R7F701639, R7F701640, R7F701641   */
/*                              R7F701642, R7F701643, R7F701644, R7F701645   */
/*                              R7F701646, R7F701647, R7F701648, R7F701649   */
/*                              R7F701650, R7F701651, R7F701652, R7F701653   */
/*                              R7F701684, R7F701685, R7F701686, R7F701687   */
/*                              R7F701688, R7F701689, R7F701690, R7F701691   */
/*                              R7F701692, R7F701693, R7F701694, R7F701695   */
/*                                                                           */
/*                         IDE: GHS Multi for V800  V6.xx or later           */
/*===========================================================================*/

CONSTANTS
{
  zero_start = 0xffff8000
  rram_start = 0xFEF00000
}
#ifdef DEF_FIRMWARE_A
DEFAULTS{IROM_0_ADD=0x00020000}
#else
DEFAULTS{IROM_0_ADD=0x00200000}
#endif
DEFAULTS{VERSION_SIZE_DEF=0x10}
DEFAULTS{CMAC_SIZE_DEF=0x20}
MEMORY
 {

  iROM_0          : ORIGIN = IROM_0_ADD,  LENGTH = 1728k - VERSION_SIZE_DEF -CMAC_SIZE_DEF
  iROM_VERSION    : ORIGIN = .,		  LENGTH = VERSION_SIZE_DEF
  iROM_CMAC	  : ORIGIN = .,		  LENGTH = CMAC_SIZE_DEF

  iRAM_0          	: ORIGIN = 0xFEBC0000,  									LENGTH = 256k-65k
  Local_Stack		: ORIGIN = .          ,										LENGTH = 30k
  iRAM_Other		: ORIGIN = .         ,										LENGTH = 35k-0x200
  iRAM_SelfTest		: ORIGIN = .         ,										LENGTH = 0x200
  iRAM_0_TOP      	: ORIGIN = .         ,  									LENGTH = 0

  iRAM_R_SecureBoot : ORIGIN = rram_start+0,  									LENGTH = 0x40    
  iRAM_R_RemoteSts  : ORIGIN = rram_start+0x40,  								LENGTH = 0x40  
  iRAM_R_NVM_Mirror	: ORIGIN = rram_start+0x40+0x40,  							LENGTH = 0x4000/*16k*/
  iRAM_R_Logger		: ORIGIN = rram_start+0x40+0x40+0x4000,  					LENGTH = 0x8800/*34k*/
  iRAM_R_Misc		: ORIGIN = rram_start+0x40+0x40+0x4000+0x8800,  			LENGTH = 0x800/*2k*/
  iRAM_R_Buram		: ORIGIN = rram_start+0x40+0x40+0x4000+0x8800+0x800,  		LENGTH = 0xC00/*3k*/
  iRAM_R_Others		: ORIGIN = rram_start+0x40+0x40+0x4000+0x8800+0x800+0xC00,  LENGTH = 64k-0x40-0x40-16k-34k-2k-3k
  iRAM_R_TOP      	: ORIGIN = .         ,  									LENGTH = 0

  gRAM_A          	: ORIGIN = 0xFEEE8000,  									LENGTH = 96k-0x200 
  gRAM_A_SelfTest	: ORIGIN = .         ,										LENGTH = 0x200

  gRAM_B          	: ORIGIN = 0xFEFE8000,  									LENGTH = 96k-90k-4k  
  gRAM_B_NonTrust   : ORIGIN = .		 ,  									LENGTH = 90k 
  coretest			: ORIGIN = .		 ,  									LENGTH = 4k-0x200
  gRAM_B_SelfTest   : ORIGIN = . 		 ,								    	LENGTH = 0x200
 }

SECTIONS
 {

/* Start of internal ROM area (iROM) */
  .intvect                         :>iROM_0 /* start of interrupt vector */
  __NON_SPESIFIED_CODE_START = .;
  _OS_LINK_EXCVEC_CODE_START = .;
#define OS_LINK_EXCVEC_CODE                                                                                                
#include "Os_Link_Core0.ld"                                                                                    
  _OS_OS_LINK_INTVEC_CODE_START = .;
#define OS_LINK_INTVEC_CODE                                                                                                
#include "Os_Link_Core0.ld"   
    .vHsmRamCode		align(4)               :>.
    .vHsmRamCode_end		align(4)               :>.
 // .romvHsmRamCode  ROM(.vHsmRamCode) :>.
  .rozdata                         :>.      /* constant datas in ZDA area */
  .robase   align(4)               :>.      /* initialize textpointer TP for SDA addressing */
  .rosdata  align(4)               :>.      /* constant datas in SDA area */
  .rodata   align(4)               :>.      /* constant datas in normal area */   

#define OS_LINK_CODE                                                                                                       
#define OS_LINK_CALLOUT_CODE                                                                                               
#include "Os_Link.ld"                                                                                          
                                                                                                                                             
#define OS_LINK_CALLOUT_CODE                                                                                               
#include "Os_Link_Core0.ld" 
  .text     align(4)               :>.      /* program code area */  
  __NON_SPESIFIED_CODE_END = .;

  __RTE_SHARED_CODE_START = .;
  .RTE_SHARED_CODE ALIGN(32) :> .
  __RTE_SHARED_CODE_END = .;
    
  __TRUST_APPLICATION_CODE_START = .;
  .TRUST_APPLICATION_CODE ALIGN(32) :> .
  __TRUST_APPLICATION_CODE_END = .;
  
  __NONTRUST_APPLICATION_CODE_START = .;
  .NONTRUST_APPLICATION_CODE ALIGN(32) :> .
  __NONTRUST_APPLICATION_CODE_END = .;
  
  __CONST_START = .;
  
#define OS_LINK_CONST                                                                                                      
#include "Os_Link.ld"                                                                                          
                                                                                                                           
#define OS_LINK_CONST                                                                                                      
#include "Os_Link_Core0.ld"  
  /* FCL Program code */
  .R_FCL_CODE_ROM       align(4)   :>.      /* FCL code in ROM */
  .R_FCL_CONST          align(4)   :>.      /* FCL constants in ROM */
  .R_FCL_CODE_USRINT    align(4)        :>.      /* Interrupt code located in RAM */
  .R_FCL_CODE_USR       align(4)        :>.      /* User code located in RAM */
  .R_FCL_CODE_RAM       align(4)        :>.      /* FCL code in RAM */
  .R_FCL_CODE_ROMRAM    align(4)        :>.      /* FCL code located in ROM or RAM (depends on the used mode) */
  .R_FCL_CODE_RAM_EX_PROT       align(4):>.

  .fixaddr  align(4)               :>.      /* ghs internal (compiler) */
  .fixtype  align(4)               :>.      /* ghs internal (compiler) */
  .secinfo  align(4)               :>.      /* ghs internal (runtime library) */
  .syscall  align(4)               :>.      /* ghs internal (linker) */

  .romdata  ROM(.data)             :>.      /* constant data to initialize variables (copied to RAM at startup)*/
  .romzdata ROM(.zdata)            :>.      /* constant data to initialize variables in ZDA area (copied to RAM at startup)*/
  .romsdata ROM(.sdata)            :>.      /* constant data to initialize variables in SDA area (copied to RAM at startup)*/
  .romtdata ROM(.tdata)            :>.      /* constant data to initialize variables in TDA area (copied to RAM at startup)*/
  .ROM.RAM_UNSPECIFIED ROM(.RAM_UNSPECIFIED) align(4) :>.

	.romTRUST_INIT_DATA  ROM(.TRUST_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/
	.romNONTRUST_INIT_DATA  ROM(.NONTRUST_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/
	.romRTE_SHARE_INIT_DATA  ROM(.RTE_SHARE_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/
	.romRAMTEST_INIT_DATA  ROM(.RAMTEST_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/
	.romIPC_SHARE_INIT_DATA  ROM(.IPC_SHARE_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/
	.romMISC_SHARE_INIT_DATA  ROM(.MISC_SHARE_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/	
	.romgRAM_NONTRUST_INIT_DATA  ROM(.gRAM_NONTRUST_INIT_DATA)			 :>.	  /* constant data to initialize variables (copied to RAM at startup)*/

	__TRUST_APPLICATION_CONST_START = .;
	.TRUST_APPLICATION_CONST ALIGN(32) :> .
	__TRUST_APPLICATION_CONST_END = .;

	__NONTRUST_APPLICATION_CONST_START = .;
	.NONTRUST_APPLICATION_CONST ALIGN(32) :> .
	__NONTRUST_APPLICATION_CONST_END = .;


  .app_version_code                :>iROM_VERSION
  .app_version_check               :>.
  .irom_cmac   CLEAR FILL(0xAA)	   :>iROM_CMAC
  .camc_value      		   :>.
  

 __CONST_END = .;

 /* Start of internal secondary local RAM area (iRAM_0) */
   _SECTION_VAR. 					:>iRAM_0
   _TRUST_VAR_START = .;

  .FCL_RESERVED  align(4)          
                 pad(addr(.R_FCL_CODE_RAM_EX_PROT)-addr(.R_FCL_CODE_ROM) + sizeof(.R_FCL_CODE_RAM_EX_PROT))
                                   :>iRAM_0    /* FCL copy location */
  .romvHsmRamCode   			   :>.               
  .R_FCL_DATA    align(4)          :>.         /* FCL data */
  .sldata        align(4)          :>.         /* user defined segment for initialized data located in secondary local RAM */
  .slbss         align(4)          :>.         /* user defined segment for initialized data located in secondary local RAM */
  .top_of_RAM_SL align(4)          :>.
  .sdabase  align(4)               :>.      /* initialize globalpointer GP for SDA addressing */
  .sdata    align(4)               :>.      /* initialized data in SDA area*/

  .sbss     align(4)               :>.      /* zero initialized data in SDA area*/
  /****** OS DATA ******/                                                                                                    
#define OS_LINK_VAR_KERNEL                                                                                                 
#define OS_LINK_KERNEL_BARRIERS                                                                                            
#define OS_LINK_KERNEL_CORESTATUS                                                                                          
#define OS_LINK_KERNEL_TRACE  
#define OS_LINK_VAR  
#define OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE_CORE0                                                                     
#include "Os_Link_Core0.ld"                                                                                    
                                                                                                                             
  /****** Application DATA ******/                                                                                           
#define OS_LINK_VAR_APP_APPLICATION_BRS_ASIL_CORE0                                                                         
#define OS_LINK_VAR_APP_APPLICATION_BRS_QM_CORE0                                                                           
#include "Os_Link_Core0.ld"   


  .data     align(4)               		:>.   /* initialized data */
  .bss      align(4)               		:>.   /* zero initialized data*/
  .zdata    align(4)                    :>.      /* initialized data in ZDA area*/
  .zbss     align(4)                    :>.      /* zero initialized data in ZDA area*/
  /****** OS DATA ******/                                                                                                    
#define OS_LINK_VAR_KERNEL                                                                                                 
#define OS_LINK_SPINLOCKS                                                                                                  
#include "Os_Link.ld"  

#define OS_LINK_VAR_GLOBALSHARED                                                                                           
#include "Os_Link.ld" 
  .RAM_UNSPECIFIED CLEAR           :>.                 
  .ramtext  align(128) MAX_SIZE(0x2000) :>.      /* initialized and zero-initialized data in TDA area */
  .tdata    align(4)   MAX_SIZE(0x0100) :>.      /* initialized and zero-initialized data in TDA area */
  .exec     align(128)                  :>.
  .stack    align(4) pad(0x1000)        :>.      /* definition of stack size */

  .TRUST_INIT_DATA 			align(4)               :>.
  .TRUST_NOINIT_DATA 		align(4)               :>.
  
  _TRUST_VAR_END = .;

  _RTE_SHARE_VAR_START = .;

  .RTE_SHARE_NOINIT_DATA 	align(4)               :>.
  .RTE_SHARE_INIT_DATA	align(4)               :>.
	
  _RTE_SHARE_VAR_END = .;
  
  _IPC_SHARE_VAR_START = .;

  .IPC_SHARE_NOINIT_DATA	  align(4)				 :>.
  .IPC_SHARE_INIT_DATA  align(4)				 :>.
  .MISC_SHARE_NOINIT_DATA	  align(4)				 :>.
  .MISC_SHARE_INIT_DATA  align(4)				 :>.
	  
  _IPC_SHARE_VAR_END = .;

	_SECTION_local. 							:>Local_Stack

	_STACK_START = .;
	/* Start of internal primary local RAM area (iRAM_0) */
#define OS_LINK_KERNEL_STACKS                                                                                              
#include "Os_Link_Core0_Stacks.ld"   
	_STACK_END = .;

  _SECTION_NONTRUST.							  :>iRAM_Other

  _NONTRUST_VAR_START = .;

  .NONTRUST_NOINIT_DATA 	align(4)               :>.
  .NONTRUST_INIT_DATA 		align(4)               :>.
  
  _NONTRUST_VAR_END = .;

  .heapbase align(4)                    :>.
  .heap     align(4)
            pad(addr(iRAM_SelfTest)-addr(.heapbase))
            NOCLEAR              :>.     /* definition of heap size */
            
  .LocalRamECCTest				 :>iRAM_SelfTest

  .top_of_RAM_L align(4)         :>iRAM_0_TOP
 /*hsm ram*/
  .vHsmIpcMemory	align(4)			:>gRAM_A
  .svHsmIpcMemory	align(4)			:>.
  .vHsmGlobalRamBuffer	align(4)		:>. 
  .svHsmGlobalRamBuffer align(4)		:>.
  
  .GlobalRamAECCTest					:>gRAM_A_SelfTest

  
  .RAMTEST_INIT_DATA   align(4)   		:>gRAM_B
  .RAMTEST_NOINIT_DATA   align(4)   	:>. 
  
  _GLOBAL_RAMB_NONTRUST_VAR_START = .;
  
  .gRAM_NONTRUST_NOINIT_DATA   align(4)   		:>gRAM_B_NonTrust
  .gRAM_NONTRUST_INIT_DATA 		align(4)               :>. 
  
  _GLOBAL_RAMB_NONTRUST_VAR_END = .;
  
  .GlobalRamBECCTest					:>gRAM_B_SelfTest

 /* Start of internal retention RAM area (iRAM_R) */
  .reset_flag	  			align(4)		 :>iRAM_R_SecureBoot 
  
  .NVMShadowStart      		align(4)         :>iRAM_R_NVM_Mirror/*start var position*/
  .NVMShadow           		align(4)         :>./*nvm mirror ram*/
  .NVMShadowEnd        		align(4)         :>./*end var position*/
  .NVMShadowChecksum   		align(4)         :>./*checksum for nvm mirror*/  
  .NVMShadowChecksumRev   	align(4)     	 :>./*reverse checksum for nvm mirror*/
  
  .LogStart      			align(4)         :>iRAM_R_Logger/*start var position*/
  .LogContext           	align(4)         :>./*log context*/
  .rram_reset_flag			align(4)     	 :>./*remote reset flag*/
  .LogEnd        			align(4)         :>./*end var position*/
  .LogChecksum   			align(4)         :>./*checksum*/  
  .LogChecksumRev   		align(4)     	 :>./*reverse checksum*/

  .rram_misc		    	align(4)		 :>iRAM_R_Misc
  
  .buram	    			align(4)		 :>iRAM_R_Buram
  
  .rdata        			align(4)         :>iRAM_R_Others   /* user defined segment for initialized data located in retention RAM */
  .rbss         			align(4)         :>iRAM_R_Others   /* user defined segment for zero initialized data located in retention RAM */
  
  .top_of_RAM_R align(4)         :>iRAM_R_TOP

  ___ghs_romstart   = MEMADDR(iROM_0);
  ___ghs_romend     = MEMENDADDR(iROM_VERSION);

  ___ghs_ramstart   = MEMADDR(iRAM_0);
  ___ghs_ramend     = MEMENDADDR(iRAM_SelfTest);

  ___ghs_rramstart  = MEMADDR(iRAM_R_SecureBoot);
  ___ghs_rramend    = MEMENDADDR(iRAM_R_Others);
  
  ___ghs_gramastart  = MEMADDR(gRAM_A);
  ___ghs_gramaend    = MEMENDADDR(gRAM_A_SelfTest);
  
  ___ghs_grambstart  = MEMADDR(gRAM_B);
  ___ghs_grambend    = MEMENDADDR(gRAM_B_SelfTest);

  ___ghs_applrramstart  = MEMADDR(iRAM_R_Misc);
  ___ghs_applrramend    = MEMENDADDR(iRAM_R_Buram);
  
  ___ghs_ramcodestart = addr(.romvHsmRamCode);
  ___ghs_romramcodestart = addr(.vHsmRamCode);
  ___ghs_ramcodeend = addr(.vHsmRamCode_end);
  
 }

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/
