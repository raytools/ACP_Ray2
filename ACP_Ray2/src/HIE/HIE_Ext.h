#pragma once

#include "HIE_Def.h"
#include "HIE_StdGame.h"
#include "../LST.h"
#include "../MTH.h"
#include "../apidef.h"


///////////////////
//
// HIE Extensions
//
///////////////////


typedef BOOL (CALLBACK *XHIE_tdfnEnumSpoCallback)( HIE_tdstSuperObject *p_stSpo );
typedef BOOL (CALLBACK *XHIE_tdfnEnumPersoCallback)( HIE_tdstEngineObject *p_stPerso );


////////////////
// Object Type
////////////////

ACP_API char * XHIE_fn_szGetSuperObjectPersonalName( HIE_tdstSuperObject *p_stSpo );
ACP_API char * XHIE_fn_szGetSuperObjectModelName( HIE_tdstSuperObject *p_stSpo );
ACP_API char * XHIE_fn_szGetSuperObjectFamilyName( HIE_tdstSuperObject *p_stSpo );
ACP_API int XHIE_fn_lNewObjectType( char const *szName, LST_M_AnchorTo(HIE_tdstObjectTypeElement) *hTypeElem );


/////////////////////////
// SPO & Always Objects
/////////////////////////

ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback );
ACP_API int XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback );

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stGetMainActor( void );
ACP_API HIE_tdstSuperObject * XHIE_fn_p_stFindSuperObjectByName( char const *szName );
