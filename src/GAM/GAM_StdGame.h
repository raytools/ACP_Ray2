/****************************************************************************
 * GAM - StdGame MiniStructure
 ****************************************************************************/

#pragma once

#include "GAM_Def.h"
#include "GAM_ObjType.h"
#include "HIE/HIE_Def.h"
#include "basedef.h"
#include "apidef.h"

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

#define Std_C_SavedMiscFlags ( Std_C_MiscFlag_DesactivateAtAll | Std_C_MiscFlag_Activable | Std_C_MiscFlag_Active )


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

#define Std_C_ulUnchangableCustomBits ( Std_C_CustBit_OutOfVisibility | Std_C_CustBit_Rayman | Std_C_CustBit_Protection )


 /* PlatForm Type */
#define Std_C_ucPlatFormType_None				0
#define Std_C_ucPlatFormType_StandardPlatForm	1


typedef enum Std_tdeObjectinitInit
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
Std_tdeObjectinitInit;


typedef struct GAM_tdstStandardGame
{
	GAM_tdxObjectType lObjectFamilyType;
	GAM_tdxObjectType lObjectModelType;
	GAM_tdxObjectType lObjectPersonalType;
	// -1 (GAM_C_InvalidObjectType) is an invalid type
	// (if > GAM_C_AlwaysObjectType) is an always object

	HIE_tdstSuperObject *p_stSuperObject;

	Std_tdeObjectinitInit eInitFlagWhenOutOfZone;
	Std_tdeObjectinitInit eInitFlagWhenDeadOrTaken;

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
GAM_tdstStandardGame;

/*
 * Functions
 */

ACP_FUNC void (*GAM_fn_vStdGameAlloc)(HIE_tdstEngineObject *p_stObject);