#include "HIE_Ext.h"
#include "HIE.h"
#include "../GAM/GAM.h"
#include "../ALW/ALW.h"
#include "../LST.h"
#include "../MMG/MMG.h"
#include "../private/framework.h"


///////////////////
//
// HIE Extensions
//
///////////////////

ACP_API XHIE_tdst_llObjectInfo *const XHIE_a_llObjectNames = (XHIE_tdst_llObjectInfo *)0x5013E0;


////////////////
// Object Info
////////////////

ACP_API char * XHIE_fn_szGetPersoName( HIE_tdstEngineObject *p_stPerso, XHIE_tdeObjectInfoType ulInfoType )
{
	XHIE_tdst_llObjectInfo *pllInfo = &XHIE_a_llObjectNames[ulInfoType];
	int nId = p_stPerso->p_stStdGame->a_lObjectType[ulInfoType];

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
	if ( p_stSpo->ulType != HIE_C_Type_Actor )
		return NULL;

	return XHIE_fn_szGetPersoName(p_stSpo->hLinkedObject.p_stCharacter, ulInfoType);
}

ACP_API int XHIE_fn_lNewObjectInfo( char const *szName, XHIE_tdeObjectInfoType ulInfoType )
{
	XHIE_tdst_llObjectInfo *p_llInfo = &XHIE_a_llObjectNames[ulInfoType];
	XHIE_tdstObjectInfo *pPrevious = p_llInfo->p_stLast;

	int length = strlen(szName) + 1;

	char *hName = fn_p_vDynAlloc(length);
	if ( !hName ) return -1;
	memcpy(hName, szName, length);

	XHIE_tdstObjectInfo stNew = { NULL, pPrevious, p_llInfo, hName };
	XHIE_tdstObjectInfo *hNew = fn_p_vDynAlloc(sizeof(XHIE_tdstObjectInfo));
	if ( !hNew ) return -1;
	*hNew = stNew;

	p_llInfo->p_stLast = pPrevious->p_stNext = hNew;
	int newId = p_llInfo->nItems++;

	return newId;
}


/////////////////////////
// SPO & Always Objects
/////////////////////////

ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback )
{
	int nEnumerated = 0;
	HIE_tdstSuperObject *pChild;

	LST_M_DynamicForEach(p_stSpo, pChild)
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
	ALW_tdstAlwaysModelList *pItem;

	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		BOOL bContinue = p_fnCallback(pItem->p_stAlwaysObject);
		nEnumerated++;

		if ( !bContinue ) break;
	}

	return nEnumerated;
}

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stGetMainActor( void )
{
	return GAM_g_stEngineStructure->g_hMainActor;
}

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stFindObject( char const *szName )
{
	HIE_tdstSuperObject *a_p_stSearchIn[] = {
		*GAM_pp_stDynamicWorld,
		*GAM_pp_stInactiveDynamicWorld
	};
	HIE_tdstSuperObject *pItem;

	for ( int i = 0; i < ARRAYSIZE(a_p_stSearchIn); i++ )
	{
		LST_M_DynamicForEach(a_p_stSearchIn[i], pItem)
		{
			char *szObjName = XHIE_fn_szGetObjectName(pItem, e_OI_Instance);
			if ( szObjName && !_stricmp(szName, szObjName) )
			{
				return pItem;
			}
		}
	}

	return NULL;
}

ACP_API HIE_tdstEngineObject * XHIE_fn_p_stFindAlwaysObject( char const *szName )
{
	ALW_tdstAlwaysModelList *pItem;
	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		char *szObjName = XHIE_fn_szGetPersoName(pItem->p_stAlwaysObject, e_OI_Instance);
		if ( szObjName && !_stricmp(szName, szObjName) )
		{
			return pItem->p_stAlwaysObject;
		}
	}

	return NULL;
}
