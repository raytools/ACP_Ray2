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

	int nEnumerated = 0;

	for ( int i = 0; i < pDsgVar->nDsgVar; i++ )
	{
		AI_tdstDsgVarInfo *pInfo = &pDsgVar->a_stDsgVarInfo[i];

		void *pCurrentValue = &pDsgMem->p_cDsgMemBuffer[pInfo->lOffset];
		void *pInitialValue = &pDsgMem->p_cDsgMemBufferInit[pInfo->lOffset];
		
		BOOL bContinue = p_fnCallback(pInfo->ulType, pCurrentValue, pInitialValue);
		nEnumerated++;

		if ( !bContinue )
			break;
	}

	return nEnumerated;
}
