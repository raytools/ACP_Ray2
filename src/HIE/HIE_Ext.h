/****************************************************************************
 *
 * HIE Extensions
 *
 ****************************************************************************/

#pragma once

#include "HIE.h"
#include "LST.h"
#include "MTH.h"
#include "apidef.h"


typedef BOOL (CALLBACK *XHIE_tdfnEnumSpoCallback)( HIE_tdstSuperObject *p_stSpo );
typedef BOOL (CALLBACK *XHIE_tdfnEnumPersoCallback)( HIE_tdstEngineObject *p_stPerso );


/*
 * Object Type
 */

ACP_API char * XHIE_fn_szGetEngineObjectPersonalName( HIE_tdstEngineObject *p_stActor );
ACP_API char * XHIE_fn_szGetEngineObjectModelName( HIE_tdstEngineObject *p_stActor );
ACP_API char * XHIE_fn_szGetEngineObjectFamilyName( HIE_tdstEngineObject *p_stActor );

ACP_API char * XHIE_fn_szGetSuperObjectPersonalName( HIE_tdstSuperObject *p_stSpo );
ACP_API char * XHIE_fn_szGetSuperObjectModelName( HIE_tdstSuperObject *p_stSpo );
ACP_API char * XHIE_fn_szGetSuperObjectFamilyName( HIE_tdstSuperObject *p_stSpo );

ACP_API long XHIE_fn_lNewObjectType( char const *szName, LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) *hTypeElem );


/*
 * SPO & Always Objects
 */

ACP_API long XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback );
ACP_API long XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback );

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stGetMainActor( void );
ACP_API HIE_tdstSuperObject * XHIE_fn_p_stFindSuperObjectByName( char const *szName );
ACP_API HIE_tdstEngineObject * XHIE_fn_p_stFindAlwaysObjectByName( char const *szName );
