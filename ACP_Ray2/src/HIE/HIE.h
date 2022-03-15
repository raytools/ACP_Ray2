#pragma once

#include "HIE_Def.h"
#include "HIE_StdGame.h"
#include "HIE_Family.h"
#include "../AI/AI_Def.h"
#include "../DNM/DNM_Def.h"
#include "../POS/POS.h"
#include "../GEO/GEO.h"
#include "../PO/PO.h"
#include "../SCT/SCT.h"
#include "../GLI/GLI_Def.h"
#include "../MTH.h"
#include "../LST.h"
#include "../apidef.h"


///////////////////////////
//
// HIE - Object Hierarchy
// 
///////////////////////////


ACP_API extern void (*HIE_fn_vChangeFather)( HIE_tdstSuperObject *p_stSpo, HIE_tdstSuperObject *p_stNewFather, BYTE bFirstChild );


////////////////
// SuperObject
////////////////

typedef enum HIE_tdeSpoFlags
{
	HIE_C_Flag_NotPickable				= 1 << 0,
	HIE_C_Flag_Hidden					= 1 << 1,
	HIE_C_Flag_NoTransformationMatrix	= 1 << 2,
	HIE_C_Flag_ZoomInsteadOfScale		= 1 << 3,
	HIE_C_Flag_TypeOfBoundingVolume		= 1 << 4,
	HIE_C_Flag_Superimposed				= 1 << 5,
	HIE_C_Flag_NotHitByRayTrace			= 1 << 6,
	HIE_C_Flag_NoShadowOnMe				= 1 << 7,
	HIE_C_Flag_SemiLookAt				= 1 << 8,
	HIE_C_Flag_CheckChildren			= 1 << 9,
	HIE_C_Flag_MagnetModification		= 1 << 15,
	HIE_C_Flag_ModuleTransparency		= 1 << 16,
	HIE_C_Flag_ExcluLight				= 1 << 17,
	HIE_C_Flag_SuperimposedClipping		= 1 << 18,
	HIE_C_Flag_OutlineMode				= 1 << 19
} HIE_tdeSpoFlags;

typedef enum HIE_tdeTypeOfObject
{
	HIE_C_Type_Unknown					= 0x0,
	HIE_C_Type_SuperObject				= 0x1,
	HIE_C_Type_Actor					= 0x2,
	HIE_C_Type_Sector					= 0x4,
	HIE_C_Type_PO						= 0x8,
	HIE_C_Type_PO_Mirror				= 0x10,
	HIE_C_Type_IPO						= 0x20,
	HIE_C_Type_IPO_Mirror				= 0x40,
	HIE_C_Type_SpecialEffect			= 0x80,
	HIE_C_Type_NoAction					= 0x100,
	HIE_C_Type_Mirror					= 0x200,
	HIE_C_Type_EDT_Geometric			= 0x400,
	HIE_C_Type_EDT_Light				= 0x800,
	HIE_C_Type_EDT_Waypoint				= 0x1000,
	HIE_C_Type_EDT_ZdD					= 0x2000,
	HIE_C_Type_EDT_ZdE					= 0x4000,
	HIE_C_Type_EDT_ZdM					= 0x8000,
	HIE_C_Type_EDT_ZdR					= 0x10000,
	HIE_C_Type_EDT_BdV					= 0x20000,
	HIE_C_Type_EDT_TestPoint			= 0x40000
} HIE_tdeTypeOfObject;

union HIE_tduLinkedObject
{
	HIE_tdstSuperObject *p_stSuperObject;
	HIE_tdstEngineObject *p_stCharacter;
	SCT_tdstSector *p_stSector;
	GEO_tdstGeometricObject *p_stGeometricObject;
	PO_tdstPhysicalObject *p_stPhysicalObject;
	PO_tdstInstantiatedPhysicalObject *p_stInstantiatedPhysicalObject;
	GLI_tdstLight *p_stLight;
	void* p_Void;
};

struct HIE_tdstSuperObject
{
	HIE_tdeTypeOfObject ulType;
	HIE_tduLinkedObject hLinkedObject;

	LST_M_DynamicParentDecl(HIE_tdstSuperObject)
	LST_M_DynamicChildDecl(HIE_tdstSuperObject, HIE_tdstSuperObject)

	POS_tdstCompletePosition *p_stLocalMatrix;
	POS_tdstCompletePosition *p_stGlobalMatrix;

	int lLastComputeFrame;
	int lDrawModeMask;
	HIE_tdeSpoFlags ulFlags;

	void *pBoundingVolume;
	MTH_tdxReal fTransparenceLevel;
};

struct HIE_tdstEngineObject /* aka: Perso, Actor, Character */
{
	// TODO: replace void pointers
	void *h3dData;
	HIE_tdstStandardGame *hStandardGame;
	DNM_tdstDynam *hDynam;
	AI_tdstBrain *hBrain;
	void *hCineInfo;
	void *hCollSet;
	void *hMSWay;
	void *hMSLight;
	SCT_tdstSectInfo *hSectInfo;
	void *hMicro;
	void *hMSPrtSrc;
	void *hMSSound;
	void *hAnimEffect;
	void *hMSMagnet;
};

struct HIE_tdstAlwaysActiveCharacter
{
	HIE_tdstSuperObject *hAlwActSuperObject;
	LST_M_DynamicElementDecl(HIE_tdstAlwaysActiveCharacter)
	//BYTE bDynamicAlwaysActive;
};

LST_M_DynamicListDecl(HIE_tdstAlwaysActiveCharacter);
