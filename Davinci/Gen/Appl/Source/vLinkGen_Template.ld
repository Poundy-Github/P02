/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/


MEMORY
{
  BCODE0 : ORIGIN = 0x00000000 , LENGTH = 0x00000080 /* 128 Byte */
  CODE_FLASH_0 : ORIGIN = 0x00000080 , LENGTH = 0x003AFF80 /* 4 MiB */
  SECURE_ICU_CODE_FLASH_0 : ORIGIN = 0x003B0000 , LENGTH = 0x00050000 /* 320 KiB */
  LOCAL_RAM_0 : ORIGIN = 0xFEBC0000 , LENGTH = 0x00040000 /* 256 KiB */
}

SECTIONS
{
  .OS_EXCVEC_CORE0_CODE ALIGN(512) :
  {
    _OS_EXCVEC_CORE0_CODE_START = .;
    __OS_EXCVEC_CORE0_CODE_START = .;
    . = ALIGN(512);
    *(.OS_EXCVEC_CORE0_CODE)
    . = ALIGN(4);
    _OS_EXCVEC_CORE0_CODE_END = . - 1;
    __OS_EXCVEC_CORE0_CODE_END = . - 1;
    _OS_EXCVEC_CORE0_CODE_LIMIT = .;
    __OS_EXCVEC_CORE0_CODE_LIMIT = .;
  } > CODE_FLASH_0

  _OS_EXCVEC_CORE0_CODE_ALL_START = _OS_EXCVEC_CORE0_CODE_START;
  _OS_EXCVEC_CORE0_CODE_ALL_END = _OS_EXCVEC_CORE0_CODE_END;
  _OS_EXCVEC_CORE0_CODE_ALL_LIMIT = _OS_EXCVEC_CORE0_CODE_LIMIT;

  .OS_EXCVEC_CORE0_CONST ALIGN(512) :
  {
    _OS_EXCVEC_CORE0_CONST_START = .;
    __OS_EXCVEC_CORE0_CONST_START = .;
    . = ALIGN(512);
    *(.OS_EXCVEC_CORE0_CONST)
    . = ALIGN(4);
    _OS_EXCVEC_CORE0_CONST_END = . - 1;
    __OS_EXCVEC_CORE0_CONST_END = . - 1;
    _OS_EXCVEC_CORE0_CONST_LIMIT = .;
    __OS_EXCVEC_CORE0_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_EXCVEC_CORE0_CONST_ALL_START = _OS_EXCVEC_CORE0_CONST_START;
  _OS_EXCVEC_CORE0_CONST_ALL_END = _OS_EXCVEC_CORE0_CONST_END;
  _OS_EXCVEC_CORE0_CONST_ALL_LIMIT = _OS_EXCVEC_CORE0_CONST_LIMIT;

  .OS_INTVEC_CODE ALIGN(512) :
  {
    _OS_INTVEC_CODE_START = .;
    __OS_INTVEC_CODE_START = .;
    . = ALIGN(512);
    *(.OS_INTVEC_CODE)
    . = ALIGN(4);
    _OS_INTVEC_CODE_END = . - 1;
    __OS_INTVEC_CODE_END = . - 1;
    _OS_INTVEC_CODE_LIMIT = .;
    __OS_INTVEC_CODE_LIMIT = .;
  } > CODE_FLASH_0

  _OS_INTVEC_CODE_ALL_START = _OS_INTVEC_CODE_START;
  _OS_INTVEC_CODE_ALL_END = _OS_INTVEC_CODE_END;
  _OS_INTVEC_CODE_ALL_LIMIT = _OS_INTVEC_CODE_LIMIT;

  .OS_INTVEC_CONST ALIGN(512) :
  {
    _OS_INTVEC_CONST_START = .;
    __OS_INTVEC_CONST_START = .;
    *(.OS_INTVEC_CONST)
    . = ALIGN(4);
    _OS_INTVEC_CONST_END = . - 1;
    __OS_INTVEC_CONST_END = . - 1;
    _OS_INTVEC_CONST_LIMIT = .;
    __OS_INTVEC_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_INTVEC_CONST_ALL_START = _OS_INTVEC_CONST_START;
  _OS_INTVEC_CONST_ALL_END = _OS_INTVEC_CONST_END;
  _OS_INTVEC_CONST_ALL_LIMIT = _OS_INTVEC_CONST_LIMIT;

  .OS_INTVEC_CORE0_CODE ALIGN(512) :
  {
    _OS_INTVEC_CORE0_CODE_START = .;
    __OS_INTVEC_CORE0_CODE_START = .;
    . = ALIGN(512);
    *(.OS_INTVEC_CORE0_CODE)
    . = ALIGN(4);
    _OS_INTVEC_CORE0_CODE_END = . - 1;
    __OS_INTVEC_CORE0_CODE_END = . - 1;
    _OS_INTVEC_CORE0_CODE_LIMIT = .;
    __OS_INTVEC_CORE0_CODE_LIMIT = .;
  } > CODE_FLASH_0

  _OS_INTVEC_CORE0_CODE_ALL_START = _OS_INTVEC_CORE0_CODE_START;
  _OS_INTVEC_CORE0_CODE_ALL_END = _OS_INTVEC_CORE0_CODE_END;
  _OS_INTVEC_CORE0_CODE_ALL_LIMIT = _OS_INTVEC_CORE0_CODE_LIMIT;

  .OS_INTVEC_CORE0_CONST ALIGN(512) :
  {
    _OS_INTVEC_CORE0_CONST_START = .;
    __OS_INTVEC_CORE0_CONST_START = .;
    . = ALIGN(512);
    *(.OS_INTVEC_CORE0_CONST)
    . = ALIGN(4);
    _OS_INTVEC_CORE0_CONST_END = . - 1;
    __OS_INTVEC_CORE0_CONST_END = . - 1;
    _OS_INTVEC_CORE0_CONST_LIMIT = .;
    __OS_INTVEC_CORE0_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_INTVEC_CORE0_CONST_ALL_START = _OS_INTVEC_CORE0_CONST_START;
  _OS_INTVEC_CORE0_CONST_ALL_END = _OS_INTVEC_CORE0_CONST_END;
  _OS_INTVEC_CORE0_CONST_ALL_LIMIT = _OS_INTVEC_CORE0_CONST_LIMIT;

  .OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM ROM_NOCOPY(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT) :> CODE_FLASH_0
  _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM);
  __OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM);
  _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM);
  __OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM);

  .OS_OsApplication_NonTrust_OsCore0_VAR_INIT :
  {
    _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_START = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_INIT_START = .;
    *(.OS_OsApplication_NonTrust_OsCore0_VAR)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST_NOCACHE)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_NOCACHE)
    _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_END = . - 1;
    __OS_OsApplication_NonTrust_OsCore0_VAR_INIT_END = . - 1;
    _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_LIMIT = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT :
  {
    _OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_START = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_START = .;
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST_NOINIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_NOCACHE_NOINIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT)
    _OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_END = . - 1;
    __OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_END = . - 1;
    _OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_LIMIT = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT :
  {
    _OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_START = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_START = .;
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_FAST_ZERO_INIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_NOCACHE_ZERO_INIT)
    *(.OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT)
    _OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_END = . - 1;
    __OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_END = . - 1;
    _OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_LIMIT = .;
    __OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_OsApplication_NonTrust_OsCore0_VAR_ALL_START = _OS_OsApplication_NonTrust_OsCore0_VAR_INIT_START;
  _OS_OsApplication_NonTrust_OsCore0_VAR_ALL_END = _OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_END;
  _OS_OsApplication_NonTrust_OsCore0_VAR_ALL_LIMIT = _OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_LIMIT;

  .OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM ROM_NOCOPY(.OS_OsApplication_Trust_OsCore0_VAR_INIT) :> LOCAL_RAM_0
  _OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM);
  __OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM);
  _OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM);
  __OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM);

  .OS_OsApplication_Trust_OsCore0_VAR_INIT :
  {
    _OS_OsApplication_Trust_OsCore0_VAR_INIT_START = .;
    __OS_OsApplication_Trust_OsCore0_VAR_INIT_START = .;
    *(.OS_OsApplication_Trust_OsCore0_VAR)
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST)
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST_NOCACHE)
    *(.OS_OsApplication_Trust_OsCore0_VAR_NOCACHE)
    _OS_OsApplication_Trust_OsCore0_VAR_INIT_END = . - 1;
    __OS_OsApplication_Trust_OsCore0_VAR_INIT_END = . - 1;
    _OS_OsApplication_Trust_OsCore0_VAR_INIT_LIMIT = .;
    __OS_OsApplication_Trust_OsCore0_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_Trust_OsCore0_VAR_NOINIT :
  {
    _OS_OsApplication_Trust_OsCore0_VAR_NOINIT_START = .;
    __OS_OsApplication_Trust_OsCore0_VAR_NOINIT_START = .;
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST_NOINIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_NOCACHE_NOINIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_NOINIT)
    _OS_OsApplication_Trust_OsCore0_VAR_NOINIT_END = . - 1;
    __OS_OsApplication_Trust_OsCore0_VAR_NOINIT_END = . - 1;
    _OS_OsApplication_Trust_OsCore0_VAR_NOINIT_LIMIT = .;
    __OS_OsApplication_Trust_OsCore0_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT :
  {
    _OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_START = .;
    __OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_START = .;
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_FAST_ZERO_INIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_NOCACHE_ZERO_INIT)
    *(.OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT)
    _OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_END = . - 1;
    __OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_END = . - 1;
    _OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_LIMIT = .;
    __OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_OsApplication_Trust_OsCore0_VAR_ALL_START = _OS_OsApplication_Trust_OsCore0_VAR_INIT_START;
  _OS_OsApplication_Trust_OsCore0_VAR_ALL_END = _OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_END;
  _OS_OsApplication_Trust_OsCore0_VAR_ALL_LIMIT = _OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_LIMIT;

  .OS_OsApplication_VAR_INIT_ROM ROM_NOCOPY(.OS_OsApplication_VAR_INIT) :> LOCAL_RAM_0
  _OS_OsApplication_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_VAR_INIT_ROM);
  __OS_OsApplication_VAR_INIT_ROM_START = ADDR(.OS_OsApplication_VAR_INIT_ROM);
  _OS_OsApplication_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_VAR_INIT_ROM);
  __OS_OsApplication_VAR_INIT_ROM_LIMIT = ADDR(.OS_OsApplication_VAR_INIT_ROM) + SIZEOF(.OS_OsApplication_VAR_INIT_ROM);

  .OS_OsApplication_VAR_INIT :
  {
    _OS_OsApplication_VAR_INIT_START = .;
    __OS_OsApplication_VAR_INIT_START = .;
    _OS_OsApplication_VAR_INIT_END = . - 1;
    __OS_OsApplication_VAR_INIT_END = . - 1;
    _OS_OsApplication_VAR_INIT_LIMIT = .;
    __OS_OsApplication_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_VAR_NOINIT :
  {
    _OS_OsApplication_VAR_NOINIT_START = .;
    __OS_OsApplication_VAR_NOINIT_START = .;
    _OS_OsApplication_VAR_NOINIT_END = . - 1;
    __OS_OsApplication_VAR_NOINIT_END = . - 1;
    _OS_OsApplication_VAR_NOINIT_LIMIT = .;
    __OS_OsApplication_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_OsApplication_VAR_ZERO_INIT :
  {
    _OS_OsApplication_VAR_ZERO_INIT_START = .;
    __OS_OsApplication_VAR_ZERO_INIT_START = .;
    _OS_OsApplication_VAR_ZERO_INIT_END = . - 1;
    __OS_OsApplication_VAR_ZERO_INIT_END = . - 1;
    _OS_OsApplication_VAR_ZERO_INIT_LIMIT = .;
    __OS_OsApplication_VAR_ZERO_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_OsApplication_VAR_ALL_START = _OS_OsApplication_VAR_INIT_START;
  _OS_OsApplication_VAR_ALL_END = _OS_OsApplication_VAR_ZERO_INIT_END;
  _OS_OsApplication_VAR_ALL_LIMIT = _OS_OsApplication_VAR_ZERO_INIT_LIMIT;

  .STACK_C0 ALIGN(4) :
  {
    _STACK_C0_START = .;
    __STACK_C0_START = .;
    . += 1024;
    . = ALIGN(4);
    _STACK_C0_END = . - 1;
    __STACK_C0_END = . - 1;
    _STACK_C0_LIMIT = .;
    __STACK_C0_LIMIT = .;
  } > LOCAL_RAM_0

  _STACK_C0_ALL_START = _STACK_C0_START;
  _STACK_C0_ALL_END = _STACK_C0_END;
  _STACK_C0_ALL_LIMIT = _STACK_C0_LIMIT;

  .Startup_Code :
  {
    _Startup_Code_START = .;
    __Startup_Code_START = .;
    *(.brsStartup)
    _Startup_Code_END = . - 1;
    __Startup_Code_END = . - 1;
    _Startup_Code_LIMIT = .;
    __Startup_Code_LIMIT = .;
  } > CODE_FLASH_0

  _Startup_Code_ALL_START = _Startup_Code_START;
  _Startup_Code_ALL_END = _Startup_Code_END;
  _Startup_Code_ALL_LIMIT = _Startup_Code_LIMIT;

  .Startup_Code_Core0 :
  {
    _Startup_Code_Core0_START = .;
    __Startup_Code_Core0_START = .;
    *(.bcode0)
    _Startup_Code_Core0_END = . - 1;
    __Startup_Code_Core0_END = . - 1;
    _Startup_Code_Core0_LIMIT = .;
    __Startup_Code_Core0_LIMIT = .;
  } > BCODE0

  _Startup_Code_Core0_ALL_START = _Startup_Code_Core0_START;
  _Startup_Code_Core0_ALL_END = _Startup_Code_Core0_END;
  _Startup_Code_Core0_ALL_LIMIT = _Startup_Code_Core0_LIMIT;

  _RESET = brsStartupEntry;
  _RESET_CORE0 = brsStartupEntry;

  __section_stack_c0_end = _STACK_C0_LIMIT;

  .OS_DATA_CORE0_VAR_INIT_ROM ROM_NOCOPY(.OS_DATA_CORE0_VAR_INIT) :> CODE_FLASH_0
  _OS_DATA_CORE0_VAR_INIT_ROM_START = ADDR(.OS_DATA_CORE0_VAR_INIT_ROM);
  __OS_DATA_CORE0_VAR_INIT_ROM_START = ADDR(.OS_DATA_CORE0_VAR_INIT_ROM);
  _OS_DATA_CORE0_VAR_INIT_ROM_LIMIT = ADDR(.OS_DATA_CORE0_VAR_INIT_ROM) + SIZEOF(.OS_DATA_CORE0_VAR_INIT_ROM);
  __OS_DATA_CORE0_VAR_INIT_ROM_LIMIT = ADDR(.OS_DATA_CORE0_VAR_INIT_ROM) + SIZEOF(.OS_DATA_CORE0_VAR_INIT_ROM);

  .OS_DATA_CORE0_VAR_INIT :
  {
    _OS_DATA_CORE0_VAR_INIT_START = .;
    __OS_DATA_CORE0_VAR_INIT_START = .;
    *(.OS_CORE0_VAR)
    *(.OS_CORE0_VAR_FAST)
    *(.OS_CORE0_VAR_FAST_NOCACHE)
    *(.OS_CORE0_VAR_NOCACHE)
    *(.OS_SystemApplication_OsCore0_VAR)
    *(.OS_SystemApplication_OsCore0_VAR_FAST)
    *(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE)
    *(.OS_SystemApplication_OsCore0_VAR_NOCACHE)
    _OS_DATA_CORE0_VAR_INIT_END = . - 1;
    __OS_DATA_CORE0_VAR_INIT_END = . - 1;
    _OS_DATA_CORE0_VAR_INIT_LIMIT = .;
    __OS_DATA_CORE0_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_DATA_CORE0_VAR_NOINIT :
  {
    _OS_DATA_CORE0_VAR_NOINIT_START = .;
    __OS_DATA_CORE0_VAR_NOINIT_START = .;
    *(.OS_CORE0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_CORE0_VAR_FAST_NOINIT)
    *(.OS_CORE0_VAR_NOCACHE_NOINIT)
    *(.OS_CORE0_VAR_NOINIT)
    *(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT)
    *(.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT)
    *(.OS_SystemApplication_OsCore0_VAR_NOINIT)
    _OS_DATA_CORE0_VAR_NOINIT_END = . - 1;
    __OS_DATA_CORE0_VAR_NOINIT_END = . - 1;
    _OS_DATA_CORE0_VAR_NOINIT_LIMIT = .;
    __OS_DATA_CORE0_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_DATA_CORE0_VAR_ZERO_INIT :
  {
    _OS_DATA_CORE0_VAR_ZERO_INIT_START = .;
    __OS_DATA_CORE0_VAR_ZERO_INIT_START = .;
    *(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT)
    *(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT)
    *(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT)
    *(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT)
    _OS_DATA_CORE0_VAR_ZERO_INIT_END = . - 1;
    __OS_DATA_CORE0_VAR_ZERO_INIT_END = . - 1;
    _OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT = .;
    __OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_DATA_CORE0_VAR_ALL_START = _OS_DATA_CORE0_VAR_INIT_START;
  _OS_DATA_CORE0_VAR_ALL_END = _OS_DATA_CORE0_VAR_ZERO_INIT_END;
  _OS_DATA_CORE0_VAR_ALL_LIMIT = _OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT;

  .OS_DATA_SHARED_VAR_INIT_ROM ROM_NOCOPY(.OS_DATA_SHARED_VAR_INIT) :> CODE_FLASH_0
  _OS_DATA_SHARED_VAR_INIT_ROM_START = ADDR(.OS_DATA_SHARED_VAR_INIT_ROM);
  __OS_DATA_SHARED_VAR_INIT_ROM_START = ADDR(.OS_DATA_SHARED_VAR_INIT_ROM);
  _OS_DATA_SHARED_VAR_INIT_ROM_LIMIT = ADDR(.OS_DATA_SHARED_VAR_INIT_ROM) + SIZEOF(.OS_DATA_SHARED_VAR_INIT_ROM);
  __OS_DATA_SHARED_VAR_INIT_ROM_LIMIT = ADDR(.OS_DATA_SHARED_VAR_INIT_ROM) + SIZEOF(.OS_DATA_SHARED_VAR_INIT_ROM);

  .OS_DATA_SHARED_VAR_INIT :
  {
    _OS_DATA_SHARED_VAR_INIT_START = .;
    __OS_DATA_SHARED_VAR_INIT_START = .;
    *(.OS_VAR_FAST_NOCACHE)
    *(.OS_VAR_NOCACHE)
    _OS_DATA_SHARED_VAR_INIT_END = . - 1;
    __OS_DATA_SHARED_VAR_INIT_END = . - 1;
    _OS_DATA_SHARED_VAR_INIT_LIMIT = .;
    __OS_DATA_SHARED_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_DATA_SHARED_VAR_NOINIT :
  {
    _OS_DATA_SHARED_VAR_NOINIT_START = .;
    __OS_DATA_SHARED_VAR_NOINIT_START = .;
    *(.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT)
    *(.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT)
    *(.OS_PUBLIC_CORE0_VAR_FAST_NOINIT)
    *(.OS_PUBLIC_CORE0_VAR_NOINIT)
    *(.OS_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_VAR_NOCACHE_NOINIT)
    _OS_DATA_SHARED_VAR_NOINIT_END = . - 1;
    __OS_DATA_SHARED_VAR_NOINIT_END = . - 1;
    _OS_DATA_SHARED_VAR_NOINIT_LIMIT = .;
    __OS_DATA_SHARED_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_DATA_SHARED_VAR_ALL_START = _OS_DATA_SHARED_VAR_INIT_START;
  _OS_DATA_SHARED_VAR_ALL_END = _OS_DATA_SHARED_VAR_NOINIT_END;
  _OS_DATA_SHARED_VAR_ALL_LIMIT = _OS_DATA_SHARED_VAR_NOINIT_LIMIT;

  .OS_GLOBALSHARED_CONST :
  {
    _OS_GLOBALSHARED_CONST_START = .;
    __OS_GLOBALSHARED_CONST_START = .;
    *(.OS_GLOBALSHARED_CONST)
    *(.OS_GLOBALSHARED_CONST_FAST)
    _OS_GLOBALSHARED_CONST_END = . - 1;
    __OS_GLOBALSHARED_CONST_END = . - 1;
    _OS_GLOBALSHARED_CONST_LIMIT = .;
    __OS_GLOBALSHARED_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_GLOBALSHARED_CONST_ALL_START = _OS_GLOBALSHARED_CONST_START;
  _OS_GLOBALSHARED_CONST_ALL_END = _OS_GLOBALSHARED_CONST_END;
  _OS_GLOBALSHARED_CONST_ALL_LIMIT = _OS_GLOBALSHARED_CONST_LIMIT;

  .OS_GLOBALSHARED_VAR_INIT_ROM ROM_NOCOPY(.OS_GLOBALSHARED_VAR_INIT) :> CODE_FLASH_0
  _OS_GLOBALSHARED_VAR_INIT_ROM_START = ADDR(.OS_GLOBALSHARED_VAR_INIT_ROM);
  __OS_GLOBALSHARED_VAR_INIT_ROM_START = ADDR(.OS_GLOBALSHARED_VAR_INIT_ROM);
  _OS_GLOBALSHARED_VAR_INIT_ROM_LIMIT = ADDR(.OS_GLOBALSHARED_VAR_INIT_ROM) + SIZEOF(.OS_GLOBALSHARED_VAR_INIT_ROM);
  __OS_GLOBALSHARED_VAR_INIT_ROM_LIMIT = ADDR(.OS_GLOBALSHARED_VAR_INIT_ROM) + SIZEOF(.OS_GLOBALSHARED_VAR_INIT_ROM);

  .OS_GLOBALSHARED_VAR_INIT :
  {
    _OS_GLOBALSHARED_VAR_INIT_START = .;
    __OS_GLOBALSHARED_VAR_INIT_START = .;
    *(.OS_GLOBALSHARED_VAR)
    *(.OS_GLOBALSHARED_VAR_FAST)
    *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE)
    *(.OS_GLOBALSHARED_VAR_NOCACHE)
    _OS_GLOBALSHARED_VAR_INIT_END = . - 1;
    __OS_GLOBALSHARED_VAR_INIT_END = . - 1;
    _OS_GLOBALSHARED_VAR_INIT_LIMIT = .;
    __OS_GLOBALSHARED_VAR_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_GLOBALSHARED_VAR_NOINIT :
  {
    _OS_GLOBALSHARED_VAR_NOINIT_START = .;
    __OS_GLOBALSHARED_VAR_NOINIT_START = .;
    *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE_NOINIT)
    *(.OS_GLOBALSHARED_VAR_FAST_NOINIT)
    *(.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT)
    *(.OS_GLOBALSHARED_VAR_NOINIT)
    _OS_GLOBALSHARED_VAR_NOINIT_END = . - 1;
    __OS_GLOBALSHARED_VAR_NOINIT_END = . - 1;
    _OS_GLOBALSHARED_VAR_NOINIT_LIMIT = .;
    __OS_GLOBALSHARED_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  .OS_GLOBALSHARED_VAR_ZERO_INIT :
  {
    _OS_GLOBALSHARED_VAR_ZERO_INIT_START = .;
    __OS_GLOBALSHARED_VAR_ZERO_INIT_START = .;
    *(.OS_GLOBALSHARED_VAR_FAST_NOCACHE_ZERO_INIT)
    *(.OS_GLOBALSHARED_VAR_FAST_ZERO_INIT)
    *(.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT)
    *(.OS_GLOBALSHARED_VAR_ZERO_INIT)
    _OS_GLOBALSHARED_VAR_ZERO_INIT_END = . - 1;
    __OS_GLOBALSHARED_VAR_ZERO_INIT_END = . - 1;
    _OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT = .;
    __OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_GLOBALSHARED_VAR_ALL_START = _OS_GLOBALSHARED_VAR_INIT_START;
  _OS_GLOBALSHARED_VAR_ALL_END = _OS_GLOBALSHARED_VAR_ZERO_INIT_END;
  _OS_GLOBALSHARED_VAR_ALL_LIMIT = _OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT;

  .OS_STACKS_CORE0_VAR_NOINIT :
  {
    _OS_STACKS_CORE0_VAR_NOINIT_START = .;
    __OS_STACKS_CORE0_VAR_NOINIT_START = .;
    . = ALIGN(4);
    *(.OS_STACK_BSW_COMM_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_BSW_DIAGNOSE_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_DEFAULT_BSW_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_DRIVERS_SAFE_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_FUEL_TC_ODO_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_GATEWAY_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_IPC_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_ERROR_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_INIT_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_PROTECTION_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_TASK_PRIO49_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_SWC_LOW_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_SYS_VAR_NOINIT)
    . = ALIGN(4);
    *(.OS_STACK_TT_GEAR_VAR_NOINIT)
    _OS_STACKS_CORE0_VAR_NOINIT_END = . - 1;
    __OS_STACKS_CORE0_VAR_NOINIT_END = . - 1;
    _OS_STACKS_CORE0_VAR_NOINIT_LIMIT = .;
    __OS_STACKS_CORE0_VAR_NOINIT_LIMIT = .;
  } > LOCAL_RAM_0

  _OS_STACKS_CORE0_VAR_ALL_START = _OS_STACKS_CORE0_VAR_NOINIT_START;
  _OS_STACKS_CORE0_VAR_ALL_END = _OS_STACKS_CORE0_VAR_NOINIT_END;
  _OS_STACKS_CORE0_VAR_ALL_LIMIT = _OS_STACKS_CORE0_VAR_NOINIT_LIMIT;

  .OS_USER_CODE :
  {
    _OS_USER_CODE_START = .;
    __OS_USER_CODE_START = .;
    *(.OS_ADC0_SG1_CAT2_ISR_CODE)
    *(.OS_ADC1_SG1_CAT2_ISR_CODE)
    *(.OS_BSW_COMM_CODE)
    *(.OS_BSW_DIAGNOSE_CODE)
    *(.OS_CanIsrGlobalStatus_CODE)
    *(.OS_CanIsrStatus_0_CODE)
    *(.OS_CanIsrStatus_1_CODE)
    *(.OS_CanIsrStatus_3_CODE)
    *(.OS_CanIsrWakeup_0_CODE)
    *(.OS_CanIsrWakeup_1_CODE)
    *(.OS_CanIsrWakeup_3_CODE)
    *(.OS_Default_BSW_CODE)
    *(.OS_Default_Init_Task_CODE)
    *(.OS_Default_Init_Task_Trusted_CODE)
    *(.OS_DRIVERS_SAFE_CODE)
    *(.OS_ERRORHOOK_CODE)
    *(.OS_EXT_INTP_CH00_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH01_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH03_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH04_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH05_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH09_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH11_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH12_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH13_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH18_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH19_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH20_CAT2_ISR_CODE)
    *(.OS_EXT_INTP_CH21_CAT2_ISR_CODE)
    *(.OS_FUEL_TC_ODO_CODE)
    *(.OS_GateWay_CODE)
    *(.OS_INTFICUIF0DFRQPE_CODE)
    *(.OS_INTRIIC0EE_interrupt_CODE)
    *(.OS_INTRIIC0RI_interrupt_CODE)
    *(.OS_INTRIIC0TEI_interrupt_CODE)
    *(.OS_INTRIIC0TI_interrupt_CODE)
    *(.OS_INTRIIC1EE_interrupt_CODE)
    *(.OS_INTRIIC1RI_interrupt_CODE)
    *(.OS_INTRIIC1TEI_interrupt_CODE)
    *(.OS_INTRIIC1TI_interrupt_CODE)
    *(.OS_IPC_CODE)
    *(.OS_LinIsr_30_Rh850Rlin_31_0_CODE)
    *(.OS_LinIsr_30_Rh850Rlin_32_0_CODE)
    *(.OS_PANICHOOK_CODE)
    *(.OS_POSTTASKHOOK_CODE)
    *(.OS_PRETASKHOOK_CODE)
    *(.OS_PROTECTIONHOOK_CODE)
    *(.OS_SHUTDOWNHOOK_CODE)
    *(.OS_SPI_CSIH3_TIR_CAT2_ISR_CODE)
    *(.OS_SWC_LOW_CODE)
    *(.OS_SYS_CODE)
    *(.OS_TAUD0_CH13_CAT2_ISR_CODE)
    *(.OS_TAUD0_CH15_CAT2_ISR_CODE)
    *(.OS_TT_GEAR_CODE)
    *(.OS_Uart_IntErr4_CODE)
    *(.OS_Uart_IntErr5_CODE)
    *(.OS_Uart_IntRx4_CODE)
    *(.OS_Uart_IntRx5_CODE)
    *(.OS_Uart_IntTx4_CODE)
    *(.OS_Uart_IntTx5_CODE)
    *(.OS_vHsmResponseIsr_CODE)
    _OS_USER_CODE_END = . - 1;
    __OS_USER_CODE_END = . - 1;
    _OS_USER_CODE_LIMIT = .;
    __OS_USER_CODE_LIMIT = .;
  } > CODE_FLASH_0

  _OS_USER_CODE_ALL_START = _OS_USER_CODE_START;
  _OS_USER_CODE_ALL_END = _OS_USER_CODE_END;
  _OS_USER_CODE_ALL_LIMIT = _OS_USER_CODE_LIMIT;

  .OS_USER_CONST :
  {
    _OS_USER_CONST_START = .;
    __OS_USER_CONST_START = .;
    *(.OS_OsApplication_NonTrust_OsCore0_CONST)
    *(.OS_OsApplication_NonTrust_OsCore0_CONST_FAST)
    *(.OS_OsApplication_Trust_OsCore0_CONST)
    *(.OS_OsApplication_Trust_OsCore0_CONST_FAST)
    _OS_USER_CONST_END = . - 1;
    __OS_USER_CONST_END = . - 1;
    _OS_USER_CONST_LIMIT = .;
    __OS_USER_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_USER_CONST_ALL_START = _OS_USER_CONST_START;
  _OS_USER_CONST_ALL_END = _OS_USER_CONST_END;
  _OS_USER_CONST_ALL_LIMIT = _OS_USER_CONST_LIMIT;

  .OS_CODE :
  {
    _OS_CODE_START = .;
    __OS_CODE_START = .;
    *(.OS_CODE)
    *(.OS_OS_COREINITHOOK_CODE)
    _OS_CODE_END = . - 1;
    __OS_CODE_END = . - 1;
    _OS_CODE_LIMIT = .;
    __OS_CODE_LIMIT = .;
  } > CODE_FLASH_0

  _OS_CODE_ALL_START = _OS_CODE_START;
  _OS_CODE_ALL_END = _OS_CODE_END;
  _OS_CODE_ALL_LIMIT = _OS_CODE_LIMIT;

  .OS_CONST :
  {
    _OS_CONST_START = .;
    __OS_CONST_START = .;
    *(.OS_CONST)
    *(.OS_CONST_FAST)
    *(.OS_CORE0_CONST)
    *(.OS_CORE0_CONST_FAST)
    *(.OS_SystemApplication_OsCore0_CONST)
    *(.OS_SystemApplication_OsCore0_CONST_FAST)
    _OS_CONST_END = . - 1;
    __OS_CONST_END = . - 1;
    _OS_CONST_LIMIT = .;
    __OS_CONST_LIMIT = .;
  } > CODE_FLASH_0

  _OS_CONST_ALL_START = _OS_CONST_START;
  _OS_CONST_ALL_END = _OS_CONST_END;
  _OS_CONST_ALL_LIMIT = _OS_CONST_LIMIT;

  .rodata :
  {
    _rodata_START = .;
    __rodata_START = .;
    *(.rodata)
    _rodata_END = . - 1;
    __rodata_END = . - 1;
    _rodata_LIMIT = .;
    __rodata_LIMIT = .;
  } > CODE_FLASH_0

  .rosdata :
  {
    _rosdata_START = .;
    __rosdata_START = .;
    *(.ldata)
    *(.rosdata)
    _rosdata_END = . - 1;
    __rosdata_END = . - 1;
    _rosdata_LIMIT = .;
    __rosdata_LIMIT = .;
  } > CODE_FLASH_0

  .rozdata :
  {
    _rozdata_START = .;
    __rozdata_START = .;
    *(.rozdata)
    *(.zrodata)
    _rozdata_END = . - 1;
    __rozdata_END = . - 1;
    _rozdata_LIMIT = .;
    __rozdata_LIMIT = .;
  } > CODE_FLASH_0

  .sdata2 :
  {
    _sdata2_START = .;
    __sdata2_START = .;
    *(.sdata2)
    _sdata2_END = . - 1;
    __sdata2_END = . - 1;
    _sdata2_LIMIT = .;
    __sdata2_LIMIT = .;
  } > CODE_FLASH_0

  .secinfo :
  {
    _secinfo_START = .;
    __secinfo_START = .;
    *(.secinfo)
    _secinfo_END = . - 1;
    __secinfo_END = . - 1;
    _secinfo_LIMIT = .;
    __secinfo_LIMIT = .;
  } > CODE_FLASH_0

  .tdata :
  {
    _tdata_START = .;
    __tdata_START = .;
    *(.tdata)
    _tdata_END = . - 1;
    __tdata_END = . - 1;
    _tdata_LIMIT = .;
    __tdata_LIMIT = .;
  } > CODE_FLASH_0

  .text :
  {
    _text_START = .;
    __text_START = .;
    *(.fixaddr)
    *(.fixtype)
    *(.picbase)
    *(.pidbase)
    *(.syscall)
    *(.text)
    *(.vletext)
    _text_END = . - 1;
    __text_END = . - 1;
    _text_LIMIT = .;
    __text_LIMIT = .;
  } > CODE_FLASH_0

  _Const_Default_ALL_START = _rodata_START;
  _Const_Default_ALL_END = _text_END;
  _Const_Default_ALL_LIMIT = _text_LIMIT;

  .bss ALIGN(4) CLEAR :
  {
    _bss_START = .;
    __bss_START = .;
    *(.bss)
    *(COMMON)
    . = ALIGN(4);
    _bss_END = . - 1;
    __bss_END = . - 1;
    _bss_LIMIT = .;
    __bss_LIMIT = .;
  } > LOCAL_RAM_0

  .data_ROM ROM_NOCOPY(.data) :> CODE_FLASH_0
  _data_ROM_START = ADDR(.data_ROM);
  __data_ROM_START = ADDR(.data_ROM);
  _data_ROM_LIMIT = ADDR(.data_ROM) + SIZEOF(.data_ROM);
  __data_ROM_LIMIT = ADDR(.data_ROM) + SIZEOF(.data_ROM);

  .data ALIGN(4) :
  {
    _data_START = .;
    __data_START = .;
    *(.data)
    . = ALIGN(4);
    _data_END = . - 1;
    __data_END = . - 1;
    _data_LIMIT = .;
    __data_LIMIT = .;
  } > LOCAL_RAM_0

  .heap ALIGN(16) NOCLEAR :
  {
    _heap_START = .;
    __heap_START = .;
    . += 1024;
    _heap_END = . - 1;
    __heap_END = . - 1;
    _heap_LIMIT = .;
    __heap_LIMIT = .;
  } > LOCAL_RAM_0

  .sbss ALIGN(4) CLEAR :
  {
    _sbss_START = .;
    __sbss_START = .;
    *(.sbss)
    *(SMALLCOMMON)
    . = ALIGN(4);
    _sbss_END = . - 1;
    __sbss_END = . - 1;
    _sbss_LIMIT = .;
    __sbss_LIMIT = .;
  } > LOCAL_RAM_0

  .sdabase :
  {
    _sdabase_START = .;
    __sdabase_START = .;
    *(.sdabase)
    _sdabase_END = . - 1;
    __sdabase_END = . - 1;
    _sdabase_LIMIT = .;
    __sdabase_LIMIT = .;
  } > LOCAL_RAM_0

  .sdata_ROM ROM_NOCOPY(.sdata) :> CODE_FLASH_0
  _sdata_ROM_START = ADDR(.sdata_ROM);
  __sdata_ROM_START = ADDR(.sdata_ROM);
  _sdata_ROM_LIMIT = ADDR(.sdata_ROM) + SIZEOF(.sdata_ROM);
  __sdata_ROM_LIMIT = ADDR(.sdata_ROM) + SIZEOF(.sdata_ROM);

  .sdata ALIGN(4) :
  {
    _sdata_START = .;
    __sdata_START = .;
    *(.sdata)
    . = ALIGN(4);
    _sdata_END = . - 1;
    __sdata_END = . - 1;
    _sdata_LIMIT = .;
    __sdata_LIMIT = .;
  } > LOCAL_RAM_0

  .stack :
  {
    _stack_START = .;
    __stack_START = .;
    *(.stack)
    _stack_END = . - 1;
    __stack_END = . - 1;
    _stack_LIMIT = .;
    __stack_LIMIT = .;
  } > LOCAL_RAM_0

  .zbss ALIGN(4) CLEAR :
  {
    _zbss_START = .;
    __zbss_START = .;
    *(.PPC.EMB.sbss0)
    *(.zbss)
    *(ZEROCOMMON)
    . = ALIGN(4);
    _zbss_END = . - 1;
    __zbss_END = . - 1;
    _zbss_LIMIT = .;
    __zbss_LIMIT = .;
  } > LOCAL_RAM_0

  .zdata_ROM ROM_NOCOPY(.zdata) :> CODE_FLASH_0
  _zdata_ROM_START = ADDR(.zdata_ROM);
  __zdata_ROM_START = ADDR(.zdata_ROM);
  _zdata_ROM_LIMIT = ADDR(.zdata_ROM) + SIZEOF(.zdata_ROM);
  __zdata_ROM_LIMIT = ADDR(.zdata_ROM) + SIZEOF(.zdata_ROM);

  .zdata ALIGN(4) :
  {
    _zdata_START = .;
    __zdata_START = .;
    *(.PPC.EMB.sdata0)
    *(.zdata)
    . = ALIGN(4);
    _zdata_END = . - 1;
    __zdata_END = . - 1;
    _zdata_LIMIT = .;
    __zdata_LIMIT = .;
  } > LOCAL_RAM_0

  _Data_Default_ALL_START = _bss_START;
  _Data_Default_ALL_END = _zdata_END;
  _Data_Default_ALL_LIMIT = _zdata_LIMIT;

}


