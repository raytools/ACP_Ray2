#include "ACP_API.h"
#include "AI.h"


////////////////
//
// AI Module
// 
////////////////


ACP_API AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)( HIE_tdstSuperObject *p_stSpo, AI_tdstNodeInterpret *p_stNode,
                                                     AI_tdstGetSetParam *p_stParam ) = 0x480B90;
