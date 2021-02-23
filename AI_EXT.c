#include "ACP_API.h"
#include "HIE_EXT.h"
#include "HIE.h"
#include "AI_EXT.h"

ACP_API int AI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback )
{
	AI_tdstMind *mind = p_stSpo->p_stEngineObject->stPerso.p_stBrain->p_stMind;
	AI_tdstAIModel *aiModel = mind->p_stAIModel;
	AI_tdstDsgVar *dsgVar = aiModel->p_stDsgVar;
	AI_tdstDsgMem *dsgMem = mind->p_stDsgMem;

	for ( int i = 0; i < dsgVar->nInfos; i++ )
	{
		AI_tdstDsgVarInfo *pInfo = &dsgVar->a_stInfos[i];

		void *pCurrentValue = (void *)(dsgMem->p_MemBuffer + pInfo->lOffset);
		void *pInitialValue = (void *)(dsgMem->p_MemBufferInitial + pInfo->lOffset);
		
		p_fnCallback(pInfo->ulType, pCurrentValue, pInitialValue);
	}

	return dsgVar->nInfos;
}
