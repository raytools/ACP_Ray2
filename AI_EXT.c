#include "ACP_API.h"
#include "HIE_EXT.h"
#include "HIE.h"
#include "AI_EXT.h"

ACP_API int AI_fn_lEnumSpoDsgVars(HIE_tdstSuperObject* p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback) {
	AI_tdstMind* mind = p_stSpo->p_stEngineObject->stPerso.p_stBrain->p_stMind;
	AI_tdstAIModel* aiModel = mind->p_stAIModel;
	AI_tdstDsgVar* dsgVar = aiModel->p_stDsgVar;
	AI_tdstDsgMem* dsgMem = mind->p_stDsgMem;

	for ( int i = 0; i < dsgVar->infoCount; i++ )
	{
		AI_tdstDsgVarInfo info = dsgVar->infos[i];
		p_fnCallback(info.type, (void*)(dsgMem->memoryBufferCurrent+info.offsetInBuffer), (void*)(dsgMem->memoryBufferInitial + info.offsetInBuffer));
	}

	return dsgVar->infoCount;
}