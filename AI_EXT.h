#pragma once
#include "HIE.h"
#include "AI.h"
#include "ACP_API.h"


//////////////////
//
// AI Extensions
//
//////////////////


typedef BOOL (CALLBACK *AI_tdfnEnumDsgVarCallback)( AI_tdeDsgVarTypeId ulType, void *CurrentValue, void *InitialValue );

ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );
