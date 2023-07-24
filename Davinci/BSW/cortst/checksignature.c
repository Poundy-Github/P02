/*
---------------------------------------------------------------------------------
--                                                                             --
--  Project         : SW G3K                                                   --
--                                                                             --
--  Module Name     : checksignature.c                                         --
--  Language        : Green Hills Software Inc. assembler 3.5.1                --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--  created at      : 22.10.2012  by: Yogitech                                 --
--                                                                             --
--  last modified   : $Date: 2012/10/15 $                                      --
--  by              : $Author: YT $                                            --
--  Version         : $Revision: 1.1 $                                         --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--  Description     : Check of result provided by the test segment             --
--                    versus signature                                         --
--                                                                             --
---------------------------------------------------------------------------------
--                                                                             --
--                                                                             --
--  Revision History:                                                          --
--  -----------------                                                          --
--  1.0 initial version                                                        --
--  1.1 0024057 modified arguments type for MISRA compliance                   --
--      added MISRA violations tags                                            --
---------------------------------------------------------------------------------
*/
#include "Cortst_cfg.h"
#if (CORE_G3K == CORTST_SWCST)
#include "st_glob.h"
#include "config.h"
#else
#include "CST_if.h"
#endif
#include "SW_G3K_Types.h"

#if (CORE_G3K == CORTST_SWCST)
void CheckSignature (sint32  test_id,
                     sint32 *p_Result,
                     sint32 *p_NotResult,
                     sint32 *p_Signature,
                     sint32 *p_NotSignature,
                     volatile sint32 *resl ,
                     sint32  gold_sig)
{
   if ( (0 < test_id) && (test_id < 22) ){
       /* return the computed signature and not(signature) */
       /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
       /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
       p_Signature[test_id - 1] = resl[0] ;
       p_NotSignature[test_id - 1] = ~(p_Signature[test_id - 1]);

       /* check of signature and verification that in r11 not(signature) is stored */
       /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
       /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
        if ((resl[0] == ~resl[1]) && (resl[0] == gold_sig))
       {
          /* return the result = PASSED */
          /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
          p_Result[test_id - 1] = PASSED;
         }

       /* return the not(result) */
       /* MISRA RULE 8.2 VIOLATION TAG 17.4.2 */
       /* MISRA RULE 8.2 VIOLATION TAG 12.7.3 */
       p_NotResult[test_id - 1] = ~(p_Result[test_id - 1]);
   }
}
#else
    void CheckSignature (sint32  test_id,
                     sint32 *p_Result,
                     sint32 *p_Signature,
                     volatile sint32 *resl ,
                     sint32  gold_sig)
{
   if ( (0 <= test_id) && (test_id < CORTST_NUM_TEST_AVAILABLE) ){
       /* return the computed signature */
       p_Signature[test_id] = resl[0] ;
       /* check of signature and verification that in r11 not(signature) is stored */
        if (resl[0] == gold_sig)
       {
          /* return the result = PASSED */
          p_Result[test_id] = PASSED;
       }
   }
}
#endif