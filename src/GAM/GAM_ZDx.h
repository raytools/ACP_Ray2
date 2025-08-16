/****************************************************************************
 * GAM - ZDx MiniStructure
 ****************************************************************************/

#pragma once

#include "GAM_Def.h"
#include "GEO/GEO_Def.h"
#include "LST.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


#define ZDX_C_wCollsetNbCollisionVectors	2
#define ZDX_C_wCollsetNbCollisionReals		2


/* forward type definitions */
typedef struct ZDX_tdstGeometricZdxList ZDX_tdstGeometricZdxList;
typedef struct ZDX_tdstZdxIndexList ZDX_tdstZdxIndexList;
typedef struct ZDX_tdstZoneSetEncapsulation ZDX_tdstZoneSetEncapsulation;

LST_M_StaticListDecl(ZDX_tdstGeometricZdxList);
LST_M_StaticListDecl(ZDX_tdstZdxIndexList);
LST_M_StaticListDecl(ZDX_tdstZoneSetEncapsulation);


typedef struct ZDX_tdstZdxList
{
	LST_M_StaticAnchorTo(ZDX_tdstGeometricZdxList) hGeoZdxList;
	unsigned short uwNumberOfZdx;
}
ZDX_tdstZdxList;

typedef struct ZDX_tdstCsaList
{
	LST_M_StaticAnchorTo(ZDX_tdstZoneSetEncapsulation) hZoneSetEncapsulationList;
}
ZDX_tdstCsaList;

typedef struct ZDX_tdstGeometricZdxList
{
	LST_M_StaticElementDecl(ZDX_tdstGeometricZdxList)
	GEO_tdstGeometricObject *hGeoObj;
}
ZDX_tdstGeometricZdxList;

typedef struct ZDX_tdstZdxIndexList
{
	LST_M_StaticElementDecl(ZDX_tdstZdxIndexList)
	unsigned short uwZdxIndex;
}
ZDX_tdstZdxIndexList;

typedef struct ZDX_tdstZoneSetList
{
	LST_M_StaticAnchorTo(ZDX_tdstZdxIndexList) hZdxIndexList;
}
ZDX_tdstZoneSetList;

typedef struct ZDX_tdstZoneSetEncapsulation
{
	LST_M_StaticElementDecl(ZDX_tdstZoneSetEncapsulation)
	ZDX_tdstZoneSetList *p_stZoneSetList;
	unsigned short uwIndex;
}
ZDX_tdstZoneSetEncapsulation;

typedef enum {
	edmPriviligedDefault = 0x00,
	edmPriviligedActivated = 0x01,
	edmPriviligedDisactivated = 0x02,
	edmNumberOfPrivilegedActivation
} ZDX_tdeCollSetPrivilegedActivation;

typedef struct ZDX_tdstCollSet
{
	ZDX_tdstZdxList *hZddList;
	ZDX_tdstZdxList *hZdeList;
	ZDX_tdstZdxList *hZdmList;
	ZDX_tdstZdxList *hZdrList;
	ZDX_tdstCsaList *hZddActivationList;
	ZDX_tdstCsaList *hZdeActivationList;
	ZDX_tdstCsaList *hZdmActivationList;
	ZDX_tdstCsaList *hZdrActivationList;

	ZDX_tdstZoneSetList *hZddCurrentActivation;
	ZDX_tdstZoneSetList *hZdeCurrentActivation;
	ZDX_tdstZoneSetList *hZdrCurrentActivation;
	ZDX_tdstZoneSetList *hZdmCurrentActivation;

	unsigned long ulFBZddPriviligedZones;
	unsigned long ulFBZdePriviligedZones;
	unsigned long ulFBZdmPriviligedZones;
	unsigned long ulFBZdrPriviligedZones;
	unsigned char ucCollComputeFrequency;

	unsigned char ucCharacterPriority;
	unsigned char ucCollisionFlag;

	struct stColliderInfo_
	{
		MTH3D_tdstVector a_stColliderVectors[ZDX_C_wCollsetNbCollisionVectors];
		MTH_tdxReal a_xColliderReals[ZDX_C_wCollsetNbCollisionReals];
		unsigned char ucColliderType;
		unsigned char ucColliderPriority;
		unsigned char a2_ucUnused[2];
	} stColliderInfo;
}
ZDX_tdstCollSet;
