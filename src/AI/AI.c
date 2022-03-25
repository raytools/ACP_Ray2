/****************************************************************************
 *
 * AI - Artificial Intelligence module
 *
 ****************************************************************************/

#include "AI.h"


AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)( HIE_tdstSuperObject *p_stSpo,
											 AI_tdstNodeInterpret *p_stNode,
											 AI_tdstGetSetParam *p_stParam ) = OFFSET(0x480B90);
