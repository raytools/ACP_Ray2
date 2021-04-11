#pragma once
#include "HIE.h"
#include "AI.h"
#include "ACP_API.h"


//////////////////
//
// AI Extensions
//
//////////////////


typedef BOOL (CALLBACK *AI_tdfnEnumDsgVarCallback)( BYTE ucIndex, AI_tdeDsgVarType ulType, void *pCurrentValue, void *pInitValue, void *pModelInitValue );

ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );
