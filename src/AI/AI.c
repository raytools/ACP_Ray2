/****************************************************************************
 *
 * AI - Artificial Intelligence module
 *
 ****************************************************************************/

#include "AI.h"


ACP_tdxBool *const AI_g_bInGameMenu = OFFSET(0x4B9BC8);
AI_tdstExtendDatas4Ray *const AI_g_stExtendDatas4Ray = OFFSET(0x4E9300);

AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)(
	HIE_tdstSuperObject *p_stSpo,
	AI_tdstNodeInterpret *p_stNode,
	AI_tdstGetSetParam *p_stParam
) = OFFSET(0x480B90);

AI_tdstNodeInterpret* (*AI_fn_p_stEvalCondition)(HIE_tdstSuperObject* p_stSpo,
	AI_tdstNodeInterpret* p_stNode,
	AI_tdstGetSetParam* p_stParam
	) = OFFSET(0x480830);

AI_tdstNodeInterpret* (*AI_fn_p_stEvalKeyWord)(HIE_tdstSuperObject* p_stSpo,
	AI_tdstNodeInterpret* p_stNode,
	AI_tdstGetSetParam* p_stParam
	) = OFFSET(0x480800);

void (*AI_fn_vReinitAI)( AI_tdstMind *p_stMind ) = OFFSET(0x466D00);

void* (*AI_fn_p_vTrueAlloc)(unsigned long ulSize) = OFFSET(0x466860);
void (*AI_fn_vTrueFree)(void* ptr) = OFFSET(0x4668b0);

void (*AI_fn_vBrainAlloc)( HIE_tdstEngineObject *p_stObject ) = OFFSET(0x417E10);
void (*AI_fn_vBrainCopyClone)(HIE_tdstEngineObject* p_stObjectDest, HIE_tdstEngineObject* p_stObjectSrc) = OFFSET(0x4180d0);


/* ultra operator */

void (*AI_fn_vGetUltraOperatorPerso)(
	unsigned char bYouHaveRightToUseThisFunction,
	HIE_tdstSuperObject *hCurrentSuperObjPerso,
	HIE_tdstSuperObject **hNewSuperObjPerso
) = OFFSET(0x4825B0);

unsigned char (*AI_fn_ucGetProcedureUltraOperator)( AI_tdeProcedureId eProcId ) = OFFSET(0x482680);

unsigned char (*AI_fn_ucChangeComportIntell)(AI_tdstIntelligence* p_stIntelligence, AI_tdstComport* p_stComport) = OFFSET(0x481080);

AI_tdstIntelligence* (*AI_fn_p_stSimulateAllocIntelligence) (char** p_ptr, AI_tdstScriptAI** pp_stScriptAI, unsigned char ucActionTableNbEntry) = OFFSET(0x466e80);
AI_tdstDsgMem*			 (*AI_fn_p_stSimulateAllocDsgMem) (char** p_ptr, AI_tdstDsgVar** pp_stDsgVar, unsigned long ulSize) = OFFSET(0x466d90);
char*								 (*AI_fn_p_cSimulateAllocDsgMemBuffer) (char** p_ptr, unsigned long ulSize) = OFFSET(0x466d60);