#pragma once
#include "apidef.h"
#include "AI.h"
#include "HIE.h"


//////////////////
//
// AI Extensions
//
//////////////////


typedef BOOL (CALLBACK *AI_tdfnEnumDsgVarCallback)( BYTE ucIndex, AI_tdeDsgVarType ulType, void *pCurrentValue, void *pInitValue, void *pModelInitValue );

ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );