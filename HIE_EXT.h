#pragma once
#include "HIE.h"
#include "ACP_API.h"


///////////////////
//
// HIE Extensions
//
///////////////////


typedef struct XHIE_stObjectInfo XHIE_tdstObjectInfo;
typedef struct XHIE_st_llObjectInfo XHIE_tdst_llObjectInfo;

typedef struct XHIE_st_llAlways XHIE_tdst_llAlways;
typedef struct XHIE_stAlways XHIE_tdstAlways;

typedef BOOL (CALLBACK *XHIE_tdfnEnumSpoCallback)( HIE_tdstSuperObject *p_stSpo );
typedef BOOL (CALLBACK *XHIE_tdfnEnumPersoCallback)( HIE_tdstPerso *p_stPerso );

ACP_API extern HIE_tdstSuperObject **const XHIE_pp_stActiveDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const XHIE_pp_stInactiveDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const XHIE_pp_stFatherSector;
ACP_API extern XHIE_tdst_llObjectInfo *const XHIE_a_llObjectNames;


////////////////
// Object Info
////////////////

typedef enum
{
	TOI_FAMILY,
	TOI_MODEL,
	TOI_INSTANCE,
	OI_TYPE_COUNT
} XHIE_tdeObjectInfoType;

struct XHIE_stObjectInfo
{
	XHIE_tdstObjectInfo *p_stNext;
	XHIE_tdstObjectInfo *p_stPrevious;
	XHIE_tdst_llObjectInfo *p_stHeader;

	char *szName;
};

struct XHIE_st_llObjectInfo
{
	XHIE_tdstObjectInfo *p_stFirst;
	XHIE_tdstObjectInfo *p_stLast;
	int nItems;
};


ACP_API char * XHIE_fn_szGetPersoName( HIE_tdstPerso *p_stPerso, XHIE_tdeObjectInfoType ulInfoType );
ACP_API char * XHIE_fn_szGetObjectName( HIE_tdstSuperObject *p_stSpo, XHIE_tdeObjectInfoType ulInfoType );
ACP_API int XHIE_fn_lNewObjectInfo( const char *szName, XHIE_tdeObjectInfoType ulInfoType );


/////////////////////////
// SPO & Always Objects
/////////////////////////

struct XHIE_stAlways
{
	XHIE_tdstAlways *p_stNext;
	XHIE_tdstAlways *p_stPrevious;
	XHIE_tdst_llAlways *p_stHeader;

	int lModelID;
	HIE_tdstPerso *p_stPerso;
};

struct XHIE_st_llAlways
{
	int nMaxAlways;
	XHIE_tdstAlways *p_stFirst;
	XHIE_tdstAlways *p_stLast;
	int nItems;

	// TODO: Always SPO, EngineObjectInit, Generator
};


ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback );
ACP_API int XHIE_fn_lEnumAlwaysObjects( XHIE_tdfnEnumPersoCallback p_fnCallback );
