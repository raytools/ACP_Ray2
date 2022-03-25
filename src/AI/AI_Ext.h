#pragma once

#include "AI.h"
#include "../HIE/HIE_Def.h"
#include "../apidef.h"


//////////////////
//
// AI Extensions
//
//////////////////


typedef BOOL (CALLBACK *AI_tdfnEnumDsgVarCallback)( BYTE ucIndex, AI_tdeDsgVarType ulType, void *pCurrentValue, void *pInitValue, void *pModelInitValue );

ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );
