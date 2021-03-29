#include "ACP_API.h"
#include "HIE_EXT.h"
#include "HIE.h"
#include "MMG.h"
#include "framework.h"


///////////////////
//
// HIE Extensions
//
///////////////////


ACP_API HIE_tdstSuperObject **const XHIE_pp_stActiveDynamicWorld = (HIE_tdstSuperObject **)0x0500FD0;
ACP_API HIE_tdstSuperObject **const XHIE_pp_stInactiveDynamicWorld = (HIE_tdstSuperObject **)0x500FC4;
ACP_API HIE_tdstSuperObject **const XHIE_pp_stFatherSector = (HIE_tdstSuperObject **)0x500FC0;
ACP_API XHIE_tdst_llObjectInfo *const XHIE_a_llObjectNames = (XHIE_tdst_llObjectInfo *)0x5013E0;

XHIE_tdst_llAlways *const p_llAlways = (XHIE_tdst_llAlways *)0x004A6B18;


////////////////
// Object Info
////////////////

ACP_API char * XHIE_fn_szGetPersoName( HIE_tdstPerso *p_stPerso, XHIE_tdeObjectInfoType ulInfoType )
{
	XHIE_tdst_llObjectInfo *pllInfo = &XHIE_a_llObjectNames[ulInfoType];
	int nId = p_stPerso->p_stStdGame->a_lObjectId[ulInfoType];

	if ( nId < 0 || nId >= pllInfo->nItems )
		return NULL;

	for ( XHIE_tdstObjectInfo *pItem = pllInfo->p_stFirst; pItem; pItem = pItem->p_stNext )
	{
		if ( nId == 0 ) return pItem->szName;
		nId--;
	}

	return NULL;
}

ACP_API char * XHIE_fn_szGetObjectName( HIE_tdstSuperObject *p_stSpo, XHIE_tdeObjectInfoType ulInfoType )
{
	if ( p_stSpo->ulType != SOT_PERSO )
		return NULL;

	return XHIE_fn_szGetPersoName(p_stSpo->stEngineObject.p_stPerso, ulInfoType);
}

ACP_API int XHIE_fn_lNewObjectInfo( const char *szName, XHIE_tdeObjectInfoType ulInfoType )
{
	XHIE_tdst_llObjectInfo *pllInfo = &XHIE_a_llObjectNames[ulInfoType];
	XHIE_tdstObjectInfo *pPrevious = pllInfo->p_stLast;

	int length = strlen(szName) + 1;

	char *hName = fn_p_vDynAlloc(length);
	if ( !hName ) return -1;
	memcpy(hName, szName, length);

	XHIE_tdstObjectInfo stNew = { NULL, pPrevious, pllInfo, hName };
	XHIE_tdstObjectInfo *hNew = fn_p_vDynAlloc(sizeof(XHIE_tdstObjectInfo));
	if ( !hNew ) return -1;
	*hNew = stNew;

	pllInfo->p_stLast = pPrevious->p_stNext = hNew;
	int newId = pllInfo->nItems++;

	return newId;
}


/////////////////////////
// SPO & Always Objects
/////////////////////////

ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback )
{
	int nEnumerated = 0;

	for ( HIE_tdstSuperObject *pChild = p_stSpo->p_stFirstChild; pChild; pChild = pChild->p_stNext )
	{
		BOOL bContinue = p_fnCallback(pChild);
		nEnumerated++;

		if ( !bContinue ) break;
	}

	return nEnumerated;
}

ACP_API int XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback )
{
	int nEnumerated = 0;

	for ( XHIE_tdstAlways *pItem = p_llAlways->p_stFirst; pItem; pItem = pItem->p_stNext )
	{
		BOOL bContinue = p_fnCallback(pItem->p_stPerso);
		nEnumerated++;

		if ( !bContinue ) break;
	}

	return nEnumerated;
}
