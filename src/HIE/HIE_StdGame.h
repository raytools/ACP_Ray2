/****************************************************************************
 * HIE - StandardGame
 ****************************************************************************/

#pragma once

#include "HIE_Def.h"
#include "LST.h"
#include "MTH.h"
#include "apidef.h"
#include "GEO/GEO.h"


#define Std_C_InvalidObjectType (-1)
#define Std_C_AlwaysObjectType  0x00010000


/*
 * Misc Flags
 */

#define	Std_C_MiscFlag_DesactivateAtAll			0x01
#define Std_C_MiscFlag_Activable				0x02
#define Std_C_MiscFlag_Active					0x04
#define Std_C_MiscFlag_AllSecondPassDone		0x08

#define Std_C_MiscFlag_Always					0x10
#define Std_C_MiscFlag_UselessCulling			0x20
#define Std_C_MiscFlag_AlwaysActive				0x40
#define Std_C_MiscFlag_TooFar					0x80


/*
 * Custom Bits
 */

#define Std_C_CustBit_UnseenFrozenAnimPlayer		0x00000001	/* 1 */
#define Std_C_CustBit_NeedModuleMatrices			0x00000002	/* 2 */
#define Std_C_CustBit_Movable						0x00000004	/* 3 */
#define Std_C_CustBit_Projectile					0x00000008	/* 4 */
#define Std_C_CustBit_RayHit						0x00000010	/* 5 */
#define Std_C_CustBit_Sightable						0x00000020	/* 6 */
#define Std_C_CustBit_CannotCrushPrincipalActor		0x00000040	/* 7 */
#define Std_C_CustBit_Collectable					0x00000080	/* 8 */
#define Std_C_CustBit_ActorHasShadow				0x00000100	/* 9 */
#define Std_C_CustBit_ShadowOnMe					0x00000200	/* 10 */
#define Std_C_CustBit_Prunable						0x00000400	/* 11 */
#define Std_C_CustBit_OutOfVisibility				0x00000800	/* 12 */
#define Std_C_CustBit_UnseenFrozen					0x00001000	/* 13 */
#define Std_C_CustBit_NoAnimPlayer					0x00002000	/* 14 */
#define Std_C_CustBit_Fightable						0x00004000	/* 15 */
#define Std_C_CustBit_NoMechanic					0x00008000	/* 16 */
#define Std_C_CustBit_NoAI							0x00010000	/* 17 */
#define Std_C_CustBit_DestroyWhenAnimEnded			0x00020000	/* 18 */
#define Std_C_CustBit_NoAnimPlayerWhenTooFar		0x00040000	/* 19 */
#define Std_C_CustBit_NoAIWhenTooFar				0x00080000	/* 20 */
#define Std_C_CustBit_Unfreezable					0x00100000	/* 21 */
#define Std_C_CustBit_UsesTransparencyZone			0x00200000	/* 22 */
#define Std_C_CustBit_NoMecaWhenTooFar				0x00400000	/* 23 */
#define Std_C_CustBit_SoundWhenInvisible			0x00800000	/* 24 */
#define Std_C_CustBit_Protection					0x01000000	/* 25 */
#define Std_C_CustBit_CameraHit						0x02000000	/* 26 */
#define Std_C_CustBit_27							0x04000000	/* 27 */
#define Std_C_CustBit_AIUser1						0x08000000	/* 28 */
#define Std_C_CustBit_AIUser2						0x10000000	/* 29 */
#define Std_C_CustBit_AIUser3						0x20000000	/* 30 */
#define Std_C_CustBit_AIUser4						0x40000000	/* 31 */
#define Std_C_CustBit_Rayman						0x80000000	/* 32 */


/*
 * PlatForm Type
 */
#define Std_C_ucPlatFormType_None					0
#define Std_C_ucPlatFormType_StandardPlatForm		1

typedef enum HIE_tdeObjectinitInit
{
	Std_C_OI_WhenPlayerGoOutOfActionZone = 0,
	Std_C_OI_Always,
	Std_C_OI_WhenPlayerIsDead,
	Std_C_OI_WhenMapJustLoaded,
	Std_C_OI_WhenSavedGameJustLoaded,
	Std_C_OI_NeverBackWhenTaken,
	Std_C_OI_NumberOfObjectInit,
	Std_C_OI_WhenGeneratorIsDesactivated
}
HIE_tdeObjectinitInit;

typedef struct HIE_tdstStandardGame
{
	HIE_tdxObjectType lObjectFamilyType;
	HIE_tdxObjectType lObjectModelType;
	HIE_tdxObjectType lObjectPersonalType;
	// -1 (Std_C_InvalidObjectType) is an invalid type
	// (if > Std_C_AlwaysObjectType) is an always object

	HIE_tdstSuperObject *p_stSuperObject;

	HIE_tdeObjectinitInit eInitFlagWhenOutOfZone;
	HIE_tdeObjectinitInit eInitFlagWhenDeadOrTaken;

	unsigned long ulLastTrame;
	unsigned long ubf32Capabilities;
	unsigned char ucTractionFactor;

	unsigned char ucHitPoints;
	unsigned char ucHitPointsMax;
	unsigned char ucHitPointsMaxMax;

	unsigned long ulCustomBits;
	unsigned char ucPlatformType;
	unsigned char ucMiscFlags;

	unsigned char ucTransparencyZoneMin;
	unsigned char ucTransparencyZoneMax;

	unsigned long ulSaveCustomBits;
	unsigned char ucSaveHitPoints;
	unsigned char ucSaveHitPointsMax;
	unsigned char ucSaveMiscFlags;

	unsigned char ucTooFarLimit;
}
HIE_tdstStandardGame;

// TODO: move the following to its own files

#define C_wCollsetNbCollisionVectors 2
#define C_wCollsetNbCollisionReals	2

typedef struct tdstGeometricZdxList_* ZDX_tdxHandleToGeoZdxList;

typedef struct tdstGeometricZdxList_
{
	LST_M_StaticElementDecl(ZDX_tdxHandleToGeoZdxList)
		GEO_tdstGeometricObject hGeoObj;

} tdstGeometricZdxList;

typedef struct tdstZdxIndexList_* ZDX_tdxHandleToZdxIndexList;
typedef struct tdstZoneSetEncapsulation_* ZDX_tdxHandleToZoneSetEncapsulation;

LST_M_StaticListDecl(ZDX_tdxHandleToGeoZdxList);
LST_M_StaticListDecl(ZDX_tdxHandleToZoneSetEncapsulation);

typedef struct tdstZdxList_
{
	LST_M_StaticAnchorTo(ZDX_tdxHandleToGeoZdxList) hGeoZdxList;
	unsigned short uwNumberOfZdx;

} tdstZdxList;

typedef struct tdstCsaList_
{
	LST_M_StaticAnchorTo(ZDX_tdxHandleToZoneSetEncapsulation) hZoneSetEncapsulationList;

} tdstCsaList;

typedef struct tdstCsaList_* ZDX_tdxHandleToCsaList;
typedef struct tdstZdxList_* ZDX_tdxHandleToZdxList;
typedef struct tdstZoneSetList_* ZDX_tdxHandleToZoneSetList;

typedef struct HIE_tdstCollSet // TODO: More like GAM than HIE? -RTS
{
	ZDX_tdxHandleToZdxList  hZddList;
	ZDX_tdxHandleToZdxList  hZdeList;
	ZDX_tdxHandleToZdxList  hZdmList;
	ZDX_tdxHandleToZdxList  hZdrList;
	ZDX_tdxHandleToCsaList  hZddActivationList;
	ZDX_tdxHandleToCsaList  hZdeActivationList;
	ZDX_tdxHandleToCsaList  hZdmActivationList;
	ZDX_tdxHandleToCsaList  hZdrActivationList;

	ZDX_tdxHandleToZoneSetList    hZddCurrentActivation;
	ZDX_tdxHandleToZoneSetList    hZdeCurrentActivation;
	ZDX_tdxHandleToZoneSetList    hZdrCurrentActivation;
	ZDX_tdxHandleToZoneSetList    hZdmCurrentActivation;

	unsigned long ulFBZddPriviligedZones;
	unsigned long ulFBZdePriviligedZones;
	unsigned long ulFBZdmPriviligedZones;
	unsigned long ulFBZdrPriviligedZones;
	unsigned char ucCollComputeFrequency;

	unsigned char ucCharacterPriority;
	unsigned char ucCollisionFlag;

	struct stColliderInfo_
	{
		MTH3D_tdstVector	a_stColliderVectors[C_wCollsetNbCollisionVectors];
		MTH_tdxReal			a_xColliderReals[C_wCollsetNbCollisionReals];
		unsigned char		ucColliderType;
		unsigned char		ucColliderPriority;
		unsigned char		a2_ucUnused[2];	// Alignment
	} stColliderInfo;
}
HIE_tdstCollSet;

// END TODO

/*
 * Object Type
 */

typedef struct HIE_tdstObjectTypeElement
{
	LST_M_DynamicElementDecl(HIE_tdstObjectTypeElement)
	char *szName;
	unsigned char ucElementPriority;
}
HIE_tdstObjectTypeElement;

LST_M_DynamicListDecl(HIE_tdstObjectTypeElement);

typedef struct HIE_tdstObjectType
{
	LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) stFamilyType;
	LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) stModelType;
	LST_M_DynamicAnchorTo(HIE_tdstObjectTypeElement) stPersonalType;
}
HIE_tdstObjectType;

/*
 * Variables
 */

ACP_VAR HIE_tdstObjectType *const HIE_g_stObjectTypes;
