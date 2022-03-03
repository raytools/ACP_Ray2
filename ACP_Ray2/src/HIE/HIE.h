#pragma once

#include "HIE_Def.h"
#include "HIE_StdGame.h"
#include "../AI/AI_Def.h"
#include "../DNM/DNM_Def.h"
#include "../MTH.h"
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
	HIE_C_Flag_ulNotPickable = 1 << 0,
	HIE_C_Flag_ulHidden = 1 << 1,
	HIE_C_Flag_ulNoTransformationMatrix = 1 << 2,
	HIE_C_Flag_ulZoomInsteadOfScale = 1 << 3,
	HIE_C_Flag_ulTypeOfBoundingVolume = 1 << 4,
	HIE_C_Flag_ulSuperimposed = 1 << 5,
	HIE_C_Flag_ulNotHitByRayTrace = 1 << 6,
	HIE_C_Flag_ulNoShadowOnMe = 1 << 7,
	HIE_C_Flag_ulSemiLookAt = 1 << 8,
	HIE_C_Flag_ulCheckChildren = 1 << 9,
	HIE_C_Flag_MagnetModification = 1 << 15,
	HIE_C_Flag_ModuleTransparency = 1 << 16,
	HIE_C_Flag_ExcluLight = 1 << 17,
	HIE_C_Flag_SuperimposedClipping = 1 << 18,
	HIE_C_Flag_OutlineMode = 1 << 19
} HIE_tdeSpoFlags;

typedef enum HIE_tdeTypeOfObject
{
	HIE_C_ulUnknown = 0x0,
	HIE_C_ulSuperObject = 0x1,
	HIE_C_ulActor = 0x2,
	HIE_C_ulSector = 0x4,
	HIE_C_ulPO = 0x8,
	HIE_C_ulPO_Mirror = 0x10,
	HIE_C_ulIPO = 0x20,
	HIE_C_ulIPO_Mirror = 0x40,
	HIE_C_ulSpecialEffect = 0x80,
	HIE_C_ulNoAction = 0x100,
	HIE_C_ulMirror = 0x200,
	HIE_C_ulEDT_Geometric = 0x400,
	HIE_C_ulEDT_Light = 0x800,
	HIE_C_ulEDT_Waypoint = 0x1000,
	HIE_C_ulEDT_ZdD = 0x2000,
	HIE_C_ulEDT_ZdE = 0x4000,
	HIE_C_ulEDT_ZdM = 0x8000,
	HIE_C_ulEDT_ZdR = 0x10000,
	HIE_C_ulEDT_BdV = 0x20000,
	HIE_C_ulEDT_TestPoint = 0x40000
} HIE_tdeTypeOfObject;

union HIE_tduLinkedObject
{
	HIE_tdstSuperObject *p_stSuperObject;
	HIE_tdstEngineObject *p_stCharacter;
	HIE_tdstSector *p_stSector;
	void *p_stPhysicalObject;
	void *p_stInstanciatedPhysicalObject;
	void *p_stGeometricObject;
	void *p_stLight;
	void* p_Void;
};

struct HIE_tdstSuperObject
{
	HIE_tdeTypeOfObject ulType;
	HIE_tduLinkedObject hLinkedObject;

	HIE_tdstSuperObject *p_stFirstChild;
	HIE_tdstSuperObject *p_stLastChild;
	int nChildren;

	HIE_tdstSuperObject *p_stNext;
	HIE_tdstSuperObject *p_stPrevious;
	HIE_tdstSuperObject *p_stParent;

	MTH_tdstTransformation *p_stLocalMatrix;
	MTH_tdstTransformation *p_stGlobalMatrix;

	int lLastComputeFrame;
	int lDrawModeMask;
	HIE_tdeSpoFlags ulFlags;

	union
	{
		void *pBoundingVolume;
		//BOUNDING_VOL_BOX *lp_bvBoundingBox;
		//BOUNDING_VOL_SPHERE *lp_bvBoundingSphere;
	};
};


//////////////
// SPO Types
//////////////


struct HIE_tdstEngineObject /* aka: Perso, Actor, Character */
{
	// TODO: replace void pointers
	void *p_stP3DData;
	HIE_tdstStandardGame *p_stStdGame;
	DNM_tdstDynam *p_stDynam;
	AI_tdstBrain *p_stBrain;
	void *p_stCamera;
	void *p_stCollSet;
	void *p_stMsWay;
	void *p_stMsLight;
	void *p_stSectInfo;
};

struct HIE_tdstSector
{
	// TODO: fill out this struct correctly
	void *persoSPOList;
	void *staticLightsList;
	void *dynamicLightsList;
};


struct HIE_tdstFamilyList
{
	// TODO: tdstFamily
	////////////////////////////////////////////////////////////////////////////////
	// Dear future me:
	// The original struct was called `LST2_tdstAnchorTotdxHandleToFamilyListDyn`.
	// The item struct was called `tdstFamilyList_`.
	// This was somewhat confusing (the item is not a list), so I changed it.
	// Now it's slightly less confusing but can still cause trouble in the future,
	// especially while implementing `tdstFamily`.
	// For that reason I'm leaving this note here.

	//tdstFamily(ListItem) *
	void *hFirstElement;
	//tdstFamily(ListItem) *
	void *hLastElement;
	int lNumberOfElements;
};

struct HIE_tdstAlwaysActiveCharacterList
{
	HIE_tdstAlwaysActiveCharacter *hFirstElement;
	HIE_tdstAlwaysActiveCharacter *hLastElement;
	int lNumberOfElements;
};

struct HIE_tdstAlwaysActiveCharacter
{
	HIE_tdstAlwaysActiveCharacter *hNextBrother;
	HIE_tdstAlwaysActiveCharacter *hPrevBrother;
	HIE_tdstAlwaysActiveCharacterList *hFather;
	HIE_tdstSuperObject *hAlwActSuperObject;
	BYTE bDynamicAlwaysActive;
};
