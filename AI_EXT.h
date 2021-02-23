#pragma once
#include "HIE.h"
#include "AI.h"
#include "ACP_API.h"

////////////////
// API EXPORTS
////////////////

typedef void (CALLBACK* AI_tdfnEnumDsgVarCallback)( AI_tdeDsgVarTypeId ulType, void *p_CurrentValue, void *p_InitialValue );

ACP_API int AI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );
