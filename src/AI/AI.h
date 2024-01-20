/****************************************************************************
 *
 * AI - Artificial Intelligence module
 *
 ****************************************************************************/

#pragma once

#include "AI_Def.h"
#include "AI_Const.h"
#include "AI_DsgVar.h"
#include "AI_Scr.h"

#include "HIE/HIE_Def.h"
#include "GMT/GMT.h"
#include "basedef.h"
#include "apidef.h"


typedef struct AI_tdstBrain
{
	AI_tdstMind *p_stMind;
	GMT_tdstGameMaterial *p_stLastCollidedGoThroughMaterial;
	ACP_tdxBool bWarnMechanicsFlag;
	//ACP_tdxBool bActiveDuringTransition;
}
AI_tdstBrain;

typedef struct AI_tdstMind
{
	AI_tdstAIModel *p_stAIModel;

	AI_tdstIntelligence *p_stIntelligence;
	AI_tdstIntelligence *p_stReflex;

	AI_tdstDsgMem *p_stDsgMem;

	ACP_tdxBool bDoingIntel; /* 1 = intelligence, 0 = reflex */
}
AI_tdstMind;

typedef struct AI_tdstIntelligence
{
	AI_tdstScriptAI **pp_stScriptAI;
	AI_tdstNodeInterpret *p_stCurrentSchedule;

	AI_tdstComport *p_stCurrentComport;
	AI_tdstComport *p_stPrevComport;
	void *p_stActionTable;
	unsigned long ulNoComportInit;
}
AI_tdstIntelligence;

typedef struct AI_tdstAIModel
{
	AI_tdstScriptAI *a_stScriptAIIntel;
	AI_tdstScriptAI *a_stScriptAIReflex;

	AI_tdstDsgVar *p_stDsgVar;
	AI_tdstListOfMacro *p_stListOfMacro;

	unsigned char ucSecondPassDone;
}
AI_tdstAIModel;


/*
 * Variables
 */

ACP_VAR ACP_tdxBool *const AI_g_bInGameMenu;


/*
 * Functions
 */

ACP_FUNC AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)( HIE_tdstSuperObject *p_stSpo, AI_tdstNodeInterpret *p_stNode, AI_tdstGetSetParam *p_stParam );

ACP_FUNC void (*AI_fn_vReinitAI)( AI_tdstMind *p_stMind );