#pragma once
#include "HIE.h"
#include "ACP_API.h"

typedef struct XHIE_stObjectInfo XHIE_tdstObjectInfo;


typedef struct XHIE_stObjectInfo
{
	XHIE_tdstObjectInfo *p_stNext;
	char _something[8];
	char *szName;
} XHIE_tdstObjectInfo;

typedef enum
{
	TOI_FAMILY,
	TOI_MODEL,
	TOI_INSTANCE,
	OI_TYPE_COUNT
} XHIE_OI_TYPE;

typedef struct XHIE_st_llObjectInfo
{
	XHIE_tdstObjectInfo *p_stFirst;
	XHIE_tdstObjectInfo *p_stLast;
	int nItems;
} XHIE_tdst_llObjectInfo;


////////////////
// API EXPORTS
////////////////

typedef void (CALLBACK *XHIE_tdfnEnumSpoCallback)( HIE_tdstSuperObject *p_stSpo );

ACP_API extern HIE_tdstSuperObject **XHIE_pp_stActiveDynamicWorld;
ACP_API char * XHIE_fn_szGetObjectName( HIE_tdstSuperObject *p_stSpo, XHIE_OI_TYPE ulInfoType );
ACP_API int XHIE_fn_lEnumSpoChildren( HIE_tdstSuperObject *p_stSpo, XHIE_tdfnEnumSpoCallback p_fnCallback );
