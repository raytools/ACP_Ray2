#include "ACP_API.h"
#include "XHIE.h"
#include "HIE.h"

HIE_tdstSuperObject **XHIE_pp_stActiveDynamicWorld = (HIE_tdstSuperObject **)0x0500FD0;

XHIE_tdst_llObjectInfo *a_pllObjectNames = (XHIE_tdst_llObjectInfo *)0x005013E0;


ACP_API char * XHIE_fn_szGetObjectName( HIE_tdstSuperObject *p_stSpo, XHIE_OI_TYPE ulInfoType )
{
	XHIE_tdst_llObjectInfo *pllInfo = &a_pllObjectNames[ulInfoType];
	int instId = p_stSpo->p_stEngineObject->p_stStdGame->a_lObjectId[ulInfoType];

	if ( instId < 0 || instId >= pllInfo->nItems )
		return "Unknown";

	XHIE_tdstObjectInfo *item = pllInfo->p_stFirst;

	while ( instId-- )
	{
		item = item->p_stNext;
	}

	return item->szName;
}

ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback )
{
	HIE_tdstSuperObject *p_stChild = p_stSpo->p_stFirstChild;

	for ( int i = 0; i < p_stSpo->nChildren; i++ )
	{
		p_fnCallback(p_stChild);
		p_stChild = p_stChild->p_stNext;
	}

	return p_stSpo->nChildren;
}
