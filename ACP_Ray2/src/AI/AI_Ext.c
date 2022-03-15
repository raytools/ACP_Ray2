#include "AI_Ext.h"
#include "../HIE/HIE.h"


//////////////////
//
// AI Extensions
//
//////////////////


ACP_API int XAI_fn_lEnumSpoDsgVars( HIE_tdstSuperObject *p_stSpo, AI_tdfnEnumDsgVarCallback p_fnCallback )
{
	if ( p_stSpo->ulType != HIE_C_Type_Actor ) return -1;
	
	AI_tdstBrain *pBrain = p_stSpo->hLinkedObject.p_stCharacter->hBrain;
	if ( !pBrain || !pBrain->p_stMind ) return -1;

	AI_tdstDsgMem *pDsgMem = pBrain->p_stMind->p_stDsgMem;
	if ( !pDsgMem ) return -1;
	
	AI_tdstDsgVar *pDsgVar = *pDsgMem->pp_stDsgVar;
	int nEnumerated = 0;

	for ( BYTE i = 0; i < pDsgVar->ucNbDsgVar; i++ )
	{
		AI_tdstDsgVarInfo *pInfo = &pDsgVar->a_stDsgVarInfo[i];

		void *pCurrentValue = NULL;
		void *pInitValue = NULL;
		void *pModelInitValue = NULL;

		if ( pDsgMem->p_cDsgMemBuffer )
		{
			pCurrentValue = &pDsgMem->p_cDsgMemBuffer[pInfo->ulOffsetInDsgMem];
		}
		
		if ( pDsgMem->p_cDsgMemBufferInit )
		{
			pInitValue = &pDsgMem->p_cDsgMemBufferInit[pInfo->ulOffsetInDsgMem];
		}

		if ( pDsgVar->p_cDsgMemDefaultInit )
		{
			pModelInitValue = &pDsgVar->p_cDsgMemDefaultInit[pInfo->ulOffsetInDsgMem];
		}
		
		BOOL bContinue = p_fnCallback(i, pInfo->eTypeId, pCurrentValue, pInitValue, pModelInitValue);
		nEnumerated++;

		if ( !bContinue )
			break;
	}

	return nEnumerated;
}
