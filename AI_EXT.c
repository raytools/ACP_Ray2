#include "ACP_API.h"
#include "AI_EXT.h"
#include "AI.h"
#include "HIE.h"


//////////////////
//
// AI Extensions
//
//////////////////


ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback )
{
	if ( p_stSpo->ulType != SOT_PERSO ) return -1;
	
	AI_tdstBrain *pBrain = p_stSpo->stEngineObject.p_stPerso->p_stBrain;
	if ( !pBrain || !pBrain->p_stMind ) return -1;

	AI_tdstDsgMem *pDsgMem = pBrain->p_stMind->p_stDsgMem;
	if ( !pDsgMem ) return -1;
	
	AI_tdstDsgVar *pDsgVar = *pDsgMem->pp_stDsgVar;
	int nEnumerated = 0;

	for ( BYTE i = 0; i < pDsgVar->nDsgVar; i++ )
	{
		AI_tdstDsgVarInfo *pInfo = &pDsgVar->a_stDsgVarInfo[i];

		void *pCurrentValue = NULL;
		void *pInitValue = NULL;
		void *pModelInitValue = NULL;

		if ( pDsgMem->p_cDsgMemBuffer )
		{
			pCurrentValue = &pDsgMem->p_cDsgMemBuffer[pInfo->ulOffset];
		}
		
		if ( pDsgMem->p_cDsgMemBufferInit )
		{
			pInitValue = &pDsgMem->p_cDsgMemBufferInit[pInfo->ulOffset];
		}

		if ( pDsgVar->p_cDsgMemDefaultInit )
		{
			pModelInitValue = &pDsgVar->p_cDsgMemDefaultInit[pInfo->ulOffset];
		}
		
		BOOL bContinue = p_fnCallback(i, pInfo->ulType, pCurrentValue, pInitValue, pModelInitValue);
		nEnumerated++;

		if ( !bContinue )
			break;
	}

	return nEnumerated;
}
