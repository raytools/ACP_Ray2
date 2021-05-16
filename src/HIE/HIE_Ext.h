#pragma once

#include "HIE.h"
#include <MTH.h>
#include <apidef.h>


///////////////////
//
// HIE Extensions
//
///////////////////


typedef struct XHIE_tdstObjectInfo XHIE_tdstObjectInfo;
typedef struct XHIE_tdst_llObjectInfo XHIE_tdst_llObjectInfo;

typedef struct XHIE_tdst_llAlways XHIE_tdst_llAlways;
typedef struct XHIE_tdstAlways XHIE_tdstAlways;

typedef BOOL (CALLBACK *XHIE_tdfnEnumSpoCallback)( HIE_tdstSuperObject *p_stSpo );
typedef BOOL (CALLBACK *XHIE_tdfnEnumPersoCallback)( HIE_tdstPerso *p_stPerso );

ACP_API extern HIE_tdstSuperObject **const XHIE_p_p_stActiveDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const XHIE_p_p_stInactiveDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const XHIE_p_p_stFatherSector;
ACP_API extern XHIE_tdst_llObjectInfo *const XHIE_a_llObjectNames;


////////////////
// Object Info
////////////////

typedef enum XHIE_tdeObjectInfoType
{
	e_OI_Family,
	e_OI_Model,
	e_OI_Instance,
	e_Nb_OI
} XHIE_tdeObjectInfoType;

struct XHIE_tdstObjectInfo
{
	XHIE_tdstObjectInfo *p_stNext;
	XHIE_tdstObjectInfo *p_stPrevious;
	XHIE_tdst_llObjectInfo *p_stHeader;
	char *szName;
};

struct XHIE_tdst_llObjectInfo
{
	XHIE_tdstObjectInfo *p_stFirst;
	XHIE_tdstObjectInfo *p_stLast;
	int nItems;
};


ACP_API char * XHIE_fn_szGetPersoName( HIE_tdstPerso *p_stPerso, XHIE_tdeObjectInfoType ulInfoType );
ACP_API char * XHIE_fn_szGetObjectName( HIE_tdstSuperObject *p_stSpo, XHIE_tdeObjectInfoType ulInfoType );
ACP_API int XHIE_fn_lNewObjectInfo( char const *szName, XHIE_tdeObjectInfoType ulInfoType );


/////////////////////////
// SPO & Always Objects
/////////////////////////

struct XHIE_tdstAlways
{
	XHIE_tdstAlways *p_stNext;
	XHIE_tdstAlways *p_stPrevious;
	XHIE_tdst_llAlways *p_stHeader;

	int lModelID;
	HIE_tdstPerso *p_stPerso;
};

struct XHIE_tdst_llAlways
{
	int nMaxAlways;
	XHIE_tdstAlways *p_stFirst;
	XHIE_tdstAlways *p_stLast;
	int nItems;

	// TODO: Always SPO, EngineObjectInit, Generator
};


ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback );
ACP_API int XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback );

ACP_API HIE_tdstSuperObject * XHIE_fn_p_stGetMainActor( void );
ACP_API HIE_tdstSuperObject * XHIE_fn_p_stFindObject( char const *szName );
ACP_API HIE_tdstPerso * XHIE_fn_p_stFindAlwaysObject( char const *szName );