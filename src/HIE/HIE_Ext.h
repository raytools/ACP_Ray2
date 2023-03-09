/****************************************************************************
 *
 * HIE Extensions
 *
 ****************************************************************************/

#pragma once

#include "HIE_Def.h"
#include "HIE_Const.h"
#include "LST.h"
#include "basedef.h"
#include "apidef.h"


/****************************************************************************
 * Convenience macros
 ****************************************************************************/

#define HIE_M_hGetMainActor() (GAM_g_stEngineStructure->g_hMainActor)

#define HIE_M_bSuperObjectIsActor( hSuperObj ) ((hSuperObj)->ulType == HIE_C_Type_Actor)
#define HIE_M_hSuperObjectGetActor( hSuperObj ) ((hSuperObj)->hLinkedObject.p_stActor)
#define HIE_M_hSuperObjectGetStdGame( hSuperObj ) (HIE_M_hSuperObjectGetActor(hSuperObj)->hStandardGame)

#define HIE_M_hStdGameGetSuperObject( hStdGame ) ((hStdGame)->p_stSuperObject)
#define HIE_M_hActorGetSuperObject( hActor ) HIE_M_hStdGameGetSuperObject((hActor)->hStandardGame)

/****************************************************************************/

/* Actor -> Object Type */
#define HIE_M_lActorGetFamilyType( hActor ) ((hActor)->hStandardGame->lObjectFamilyType)
#define HIE_M_lActorGetModelType( hActor ) ((hActor)->hStandardGame->lObjectModelType)
#define HIE_M_lActorGetPersonalType( hActor ) ((hActor)->hStandardGame->lObjectPersonalType)

/* Name -> Object Type */
ACP_API HIE_tdxObjectType HIE_fn_lFindFamilyTypeByName( char const *szName );
ACP_API HIE_tdxObjectType HIE_fn_lFindModelTypeByName( char const *szName );
ACP_API HIE_tdxObjectType HIE_fn_lFindPersonalTypeByName( char const *szName );

/* Object Type -> SuperObject */
ACP_API HIE_tdstSuperObject * HIE_fn_p_stFindObjectChildByPersonalType( HIE_tdxObjectType lType, HIE_tdstSuperObject *p_stParent );
ACP_API HIE_tdstSuperObject * HIE_fn_p_stFindObjectByPersonalType( HIE_tdxObjectType lType );

/* Name -> SuperObject */
ACP_API HIE_tdstSuperObject * HIE_fn_p_stFindObjectChildByName( char const *szName, HIE_tdstSuperObject *p_stParent );
ACP_API HIE_tdstSuperObject * HIE_fn_p_stFindObjectByName( char const *szName );

/* Object Type -> Name */
ACP_API char * HIE_fn_szGetFamilyTypeName( HIE_tdxObjectType lType );
ACP_API char * HIE_fn_szGetModelTypeName( HIE_tdxObjectType lType );
ACP_API char * HIE_fn_szGetPersonalTypeName( HIE_tdxObjectType lType );

/* SuperObject -> Name */
ACP_API char * HIE_fn_szGetObjectFamilyName( HIE_tdstSuperObject *p_stSuperObj );
ACP_API char * HIE_fn_szGetObjectModelName( HIE_tdstSuperObject *p_stSuperObj );
ACP_API char * HIE_fn_szGetObjectPersonalName( HIE_tdstSuperObject *p_stSuperObj );


ACP_API HIE_tdstEngineObject * HIE_fn_p_stFindAlwaysObjectByName( char const *szName );
ACP_API long HIE_fn_lNewObjectType( char const *szName, LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) *hTypeElem );
