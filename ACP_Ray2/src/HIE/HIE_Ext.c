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


////////////////
// Object Type
////////////////

char * XHIE_fn_szGetEngineObjectTypeName( HIE_tdstEngineObject *p_stCharacter, LST_M_AnchorTo(HIE_tdstObjectTypeElement) *hTypeElem)
{
	int lId = p_stCharacter->p_stStdGame->lObjectPersonalType;
	
	if ( lId < 0 || lId >= hTypeElem->lNbOfElements )
		return NULL;

	HIE_tdstObjectTypeElement *pItem;
	int i;
	LST_M_DynamicGetNthElement(hTypeElem, lId, pItem, i);

	if ( !pItem )
		return NULL;

	return pItem->szName;
}

char * XHIE_fn_szGetSuperObjectTypeName( HIE_tdstSuperObject *p_stSpo, LST_M_AnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	if ( p_stSpo->ulType != HIE_C_Type_Actor )
		return NULL;

	return XHIE_fn_szGetEngineObjectTypeName(p_stSpo->hLinkedObject.p_stCharacter, hTypeElem);
}

ACP_API char * XHIE_fn_szGetSuperObjectPersonalName( HIE_tdstSuperObject *p_stSpo )
{
	return XHIE_fn_szGetSuperObjectTypeName(p_stSpo, &HIE_g_stObjectTypes->stPersonalType);
}

ACP_API char * XHIE_fn_szGetSuperObjectModelName( HIE_tdstSuperObject *p_stSpo )
{
	return XHIE_fn_szGetSuperObjectTypeName(p_stSpo, &HIE_g_stObjectTypes->stModelType);
}

ACP_API char * XHIE_fn_szGetSuperObjectFamilyName( HIE_tdstSuperObject *p_stSpo )
{
	return XHIE_fn_szGetSuperObjectTypeName(p_stSpo, &HIE_g_stObjectTypes->stFamilyType);
}

int XHIE_fn_lFindTypeIdByName( char const *szName, LST_M_AnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	HIE_tdstObjectTypeElement *pItem;
	int i;

	LST_M_DynamicForEachIndex(hTypeElem, pItem, i)
	{
		if ( !_stricmp(pItem->szName, szName) )
			return i;
	}

	return -1;
}

ACP_API int XHIE_fn_lNewObjectType( char const *szName, LST_M_AnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	int length = strlen(szName) + 1;

	char *hName = fn_p_vDynAlloc(length);
	if ( !hName )
		return -1;

	memcpy(hName, szName, length);
	
	HIE_tdstObjectTypeElement *hNew = fn_p_vDynAlloc(sizeof(HIE_tdstObjectTypeElement));
	if ( !hNew )
		return -1;

	hNew->szName = hName;

	LST_M_DynamicAddTail(hTypeElem, hNew);
	int lNewId = XHIE_fn_lFindTypeIdByName(szName, hTypeElem);

	return lNewId;
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

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stFindSuperObjectByName( char const *szName )
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
			char *szObjName = XHIE_fn_szGetSuperObjectPersonalName(pItem);
			if ( szObjName && !_stricmp(szName, szObjName) )
			{
				return pItem;
			}
		}
	}

	return NULL;
}

ACP_API HIE_tdstEngineObject * XHIE_fn_p_stFindAlwaysObjectByName( char const *szName )
{
	ALW_tdstAlwaysModelList *pItem;
	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		char *szObjName = XHIE_fn_szGetEngineObjectTypeName(pItem->p_stAlwaysObject, &HIE_g_stObjectTypes->stPersonalType);
		if ( szObjName && !_stricmp(szName, szObjName) )
		{
			return pItem->p_stAlwaysObject;
		}
	}

	return NULL;
}
