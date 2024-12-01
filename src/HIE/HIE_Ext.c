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


/****************************************************************************
 * Name -> Object Type
 ****************************************************************************/

GAM_tdxObjectType HIE_fn_lFindObjectTypeByName( char const *szName, LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) *hTypeElem )
{
	GAM_tdstObjectTypeElement *p_stType;
	long i;
	LST_M_DynamicForEachIndex(hTypeElem, p_stType, i)
	{
		if ( !_stricmp(p_stType->szName, szName) )
			return i;
	}

	return GAM_C_InvalidObjectType;
}

GAM_tdxObjectType HIE_fn_lFindFamilyTypeByName( char const *szName )
{
	return HIE_fn_lFindObjectTypeByName(szName, &GAM_g_stObjectTypes->stFamilyType);
}

GAM_tdxObjectType HIE_fn_lFindModelTypeByName( char const *szName )
{
	return HIE_fn_lFindObjectTypeByName(szName, &GAM_g_stObjectTypes->stModelType);
}

GAM_tdxObjectType HIE_fn_lFindPersonalTypeByName( char const *szName )
{
	return HIE_fn_lFindObjectTypeByName(szName, &GAM_g_stObjectTypes->stPersonalType);
}


/****************************************************************************
 * Object Type -> SuperObject
 ****************************************************************************/

HIE_tdstSuperObject * HIE_fn_p_stFindObjectChildByPersonalType( GAM_tdxObjectType lType, HIE_tdstSuperObject *p_stParent )
{
	HIE_tdstSuperObject *p_stSuperObj;
	LST_M_DynamicForEach(p_stParent, p_stSuperObj)
	{
		if ( p_stSuperObj->ulType != HIE_C_Type_Actor )
			continue;

		HIE_tdstEngineObject *p_stActor = HIE_M_hSuperObjectGetActor(p_stSuperObj);

		if ( p_stActor->hStandardGame->lObjectPersonalType == lType )
			return p_stSuperObj;
	}

	return NULL;
}

HIE_tdstSuperObject * HIE_fn_p_stFindObjectByPersonalType( GAM_tdxObjectType lType )
{
	HIE_tdstSuperObject *p_stSuperObj = NULL;

	p_stSuperObj = HIE_fn_p_stFindObjectChildByPersonalType(lType, *GAM_g_p_stDynamicWorld);

	if ( !p_stSuperObj )
		p_stSuperObj = HIE_fn_p_stFindObjectChildByPersonalType(lType, *GAM_g_p_stInactiveDynamicWorld);

	return p_stSuperObj;
}


/****************************************************************************
 * Name -> SuperObject
 ****************************************************************************/

HIE_tdstSuperObject * HIE_fn_p_stFindObjectChildByName( char const *szName, HIE_tdstSuperObject *p_stParent )
{
	GAM_tdxObjectType lType = HIE_fn_lFindPersonalTypeByName(szName);

	if ( lType == GAM_C_InvalidObjectType )
		return NULL;

	return HIE_fn_p_stFindObjectChildByPersonalType(lType, p_stParent);
}

HIE_tdstSuperObject * HIE_fn_p_stFindObjectByName( char const *szName )
{
	GAM_tdxObjectType lType = HIE_fn_lFindPersonalTypeByName(szName);

	if ( lType == GAM_C_InvalidObjectType )
		return NULL;

	return HIE_fn_p_stFindObjectByPersonalType(lType);
}


/****************************************************************************
 * Object Type -> Name
 ****************************************************************************/

char * HIE_fn_szGetObjectTypeName( GAM_tdxObjectType lType, LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) *hTypeElem )
{
	if ( lType <= GAM_C_InvalidObjectType || lType >= LST_M_DynamicGetNbOfElements(hTypeElem) )
		return NULL;

	GAM_tdstObjectTypeElement *pItem;
	long i;
	LST_M_DynamicGetNthElement(hTypeElem, lType, pItem, i);

	return (pItem) ? pItem->szName : NULL;
}

char * HIE_fn_szGetFamilyTypeName( GAM_tdxObjectType lType )
{
	return HIE_fn_szGetObjectTypeName(lType, &GAM_g_stObjectTypes->stFamilyType);
}

char * HIE_fn_szGetModelTypeName( GAM_tdxObjectType lType )
{
	return HIE_fn_szGetObjectTypeName(lType, &GAM_g_stObjectTypes->stModelType);
}

char * HIE_fn_szGetPersonalTypeName( GAM_tdxObjectType lType )
{
	return HIE_fn_szGetObjectTypeName(lType, &GAM_g_stObjectTypes->stPersonalType);
}


/****************************************************************************
 * SuperObject -> Name
 ****************************************************************************/

char * HIE_fn_szGetObjectFamilyName( HIE_tdstSuperObject *p_stSuperObj )
{
	if ( p_stSuperObj->ulType != HIE_C_Type_Actor )
		return NULL;

	return HIE_fn_szGetFamilyTypeName(HIE_M_lActorGetFamilyType(HIE_M_hSuperObjectGetActor(p_stSuperObj)));
}

char * HIE_fn_szGetObjectModelName( HIE_tdstSuperObject *p_stSuperObj )
{
	if ( p_stSuperObj->ulType != HIE_C_Type_Actor )
		return NULL;
	
	return HIE_fn_szGetModelTypeName(HIE_M_lActorGetModelType(HIE_M_hSuperObjectGetActor(p_stSuperObj)));
}

char * HIE_fn_szGetObjectPersonalName( HIE_tdstSuperObject *p_stSuperObj )
{
	if ( p_stSuperObj->ulType != HIE_C_Type_Actor )
		return NULL;

	GAM_tdxObjectType lPersonalType = HIE_M_lActorGetPersonalType(HIE_M_hSuperObjectGetActor(p_stSuperObj));
	if (lPersonalType == GAM_C_InvalidObjectType || lPersonalType >= GAM_C_AlwaysObjectType) {
		return NULL;
	}

	return HIE_fn_szGetPersonalTypeName(lPersonalType);
}


/****************************************************************************
 * Other
 ****************************************************************************/

HIE_tdstEngineObject * HIE_fn_p_stFindAlwaysObjectByName( char const *szName )
{
	GAM_tdxObjectType lType = HIE_fn_lFindPersonalTypeByName(szName);

	if ( lType == GAM_C_InvalidObjectType )
		return NULL;

	ALW_tdstAlwaysModelList *pItem;
	LST_M_DynamicForEach(&ALW_g_stAlways->hLstAlwaysModel, pItem)
	{
		HIE_tdstEngineObject *p_stAlwaysObj = pItem->p_stAlwaysObject;
		
		if ( p_stAlwaysObj->hStandardGame->lObjectPersonalType == lType )
			return pItem->p_stAlwaysObject;
	}

	return NULL;
}

GAM_tdxObjectType HIE_fn_lNewObjectType( char const *szName, LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) *hTypeElem )
{
	long lStrLen = strlen(szName) + 1;

	char *hName = fn_p_vDynAlloc(lStrLen);
	if ( !hName )
		return GAM_C_InvalidObjectType;

	memcpy(hName, szName, lStrLen);
	
	GAM_tdstObjectTypeElement *hNew = fn_p_vDynAlloc(sizeof(GAM_tdstObjectTypeElement));
	if ( !hNew )
		return GAM_C_InvalidObjectType;

	hNew->szName = hName;

	LST_M_DynamicAddTail(hTypeElem, hNew);
	GAM_tdxObjectType lNewType = HIE_fn_lFindObjectTypeByName(szName, hTypeElem);

	return lNewType;
}
