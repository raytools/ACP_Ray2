#include "ACP_API.h"
#include "HIE.h"
#include "AI.h"
#include "AI_EXT.h"


//////////////////
//
// AI Extensions
//
//////////////////


ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback )
{
	AI_tdstMind *pMind = p_stSpo->stEngineObject.p_stPerso->p_stBrain->p_stMind;
	AI_tdstAIModel *pAiModel = pMind->p_stAIModel;
	AI_tdstDsgVar *pDsgVar = pAiModel->p_stDsgVar;
	AI_tdstDsgMem *pDsgMem = pMind->p_stDsgMem;

	for ( int i = 0; i < pDsgVar->nInfos; i++ )
	{
		AI_tdstDsgVarInfo *pInfo = &pDsgVar->a_stInfos[i];

		void *pCurrentValue = &pDsgMem->p_MemBuffer[pInfo->lOffset];
		void *pInitialValue = &pDsgMem->p_MemBufferInitial[pInfo->lOffset];
		
		BOOL bContinue = p_fnCallback(pInfo->ulType, pCurrentValue, pInitialValue);

		if ( !bContinue )
			break;
	}

	return pDsgVar->nInfos;
}
