/****************************************************************************
 *
 * HIE Extensions
 *
 ****************************************************************************/

#include "HIE_Ext.h"
#include "GAM/GAM.h"
#include "ALW/ALW.h"
#include "MMG/MMG.h"
#include "private/framework.h"


/*
 * Object Type
 */

char * XHIE_fn_szGetTypeName( long lID, LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	if ( lID < 0 || lID >= LST_M_DynamicGetNbOfElements(hTypeElem) )
		return NULL;

	HIE_tdstObjectTypeElement *pItem;
	long i;
	LST_M_DynamicGetNthElement(hTypeElem, lID, pItem, i);

	if ( !pItem )
		return NULL;

	return pItem->szName;
}


char * XHIE_fn_szGetEngineObjectPersonalName( HIE_tdstEngineObject *p_stActor )
{
	return XHIE_fn_szGetTypeName(p_stActor->hStandardGame->lObjectPersonalType, &HIE_g_stObjectTypes->stPersonalType);
}

char * XHIE_fn_szGetEngineObjectModelName( HIE_tdstEngineObject *p_stActor )
{
	return XHIE_fn_szGetTypeName(p_stActor->hStandardGame->lObjectModelType, &HIE_g_stObjectTypes->stModelType);
}

char * XHIE_fn_szGetEngineObjectFamilyName( HIE_tdstEngineObject *p_stActor )
{
	return XHIE_fn_szGetTypeName(p_stActor->hStandardGame->lObjectFamilyType, &HIE_g_stObjectTypes->stFamilyType);
}


char * XHIE_fn_szGetSuperObjectPersonalName( HIE_tdstSuperObject *p_stSpo )
{
	if ( p_stSpo->ulType != HIE_C_Type_Actor )
		return NULL;

	return XHIE_fn_szGetEngineObjectPersonalName(p_stSpo->hLinkedObject.p_stCharacter);
}

char * XHIE_fn_szGetSuperObjectModelName( HIE_tdstSuperObject *p_stSpo )
{
	if ( p_stSpo->ulType != HIE_C_Type_Actor )
		return NULL;

	return XHIE_fn_szGetEngineObjectModelName(p_stSpo->hLinkedObject.p_stCharacter);
}

char * XHIE_fn_szGetSuperObjectFamilyName( HIE_tdstSuperObject *p_stSpo )
{
	if ( p_stSpo->ulType != HIE_C_Type_Actor )
		return NULL;

	return XHIE_fn_szGetEngineObjectFamilyName(p_stSpo->hLinkedObject.p_stCharacter);
}


long XHIE_fn_lFindTypeIdByName( char const *szName, LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	HIE_tdstObjectTypeElement *pItem;
	long i;

	LST_M_DynamicForEachIndex(hTypeElem, pItem, i)
	{
		if ( !_stricmp(pItem->szName, szName) )
			return i;
	}

	return -1;
}

long XHIE_fn_lNewObjectType( char const *szName, LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) *hTypeElem )
{
	long length = strlen(szName) + 1;

	char *hName = fn_p_vDynAlloc(length);
	if ( !hName )
		return -1;

	memcpy(hName, szName, length);
	
	HIE_tdstObjectTypeElement *hNew = fn_p_vDynAlloc(sizeof(HIE_tdstObjectTypeElement));
	if ( !hNew )
		return -1;

	hNew->szName = hName;

	LST_M_DynamicAddTail(hTypeElem, hNew);
	long lNewId = XHIE_fn_lFindTypeIdByName(szName, hTypeElem);

	return lNewId;
}


/*
 * SPO & Always Objects
 */

long XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback )
{
	long nEnumerated = 0;
	HIE_tdstSuperObject *pChild;

	LST_M_DynamicForEach(p_stSpo, pChild)
	{
		BOOL bContinue = p_fnCallback(pChild);
		nEnumerated++;

		if ( !bContinue ) break;
	}

	return nEnumerated;
}

long XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback )
{
	long nEnumerated = 0;
	ALW_tdstAlwaysModelList *pItem;

	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		BOOL bContinue = p_fnCallback(pItem->p_stAlwaysObject);
		nEnumerated++;

		if ( !bContinue ) break;
	}

	return nEnumerated;
}

HIE_tdstSuperObject * XHIE_fn_p_stGetMainActor( void )
{
	return GAM_g_stEngineStructure->g_hMainActor;
}

HIE_tdstSuperObject * XHIE_fn_p_stFindSuperObjectByName( char const *szName )
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

HIE_tdstEngineObject * XHIE_fn_p_stFindAlwaysObjectByName( char const *szName )
{
	ALW_tdstAlwaysModelList *pItem;
	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		char *szObjName = XHIE_fn_szGetEngineObjectPersonalName(pItem->p_stAlwaysObject);
		if ( szObjName && !_stricmp(szName, szObjName) )
		{
			return pItem->p_stAlwaysObject;
		}
	}

	return NULL;
}
