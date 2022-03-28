/****************************************************************************
 *
 * AI Extensions
 *
 ****************************************************************************/

#pragma once

#include "AI.h"
#include "HIE/HIE_Def.h"
#include "basedef.h"
#include "apidef.h"


typedef BOOL (CALLBACK *AI_tdfnEnumDsgVarCallback)( unsigned char ucIndex, AI_tdeDsgVarType ulType, void *pCurrentValue, void *pInitValue, void *pModelInitValue );

ACP_API long XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback );
