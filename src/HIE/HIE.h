﻿#pragma once

#include "HIE_Def.h"
#include <AI/AI_Def.h>
#include <DNM/DNM_Def.h>
#include <MTH.h>
#include <apidef.h>


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
	SOF_NO_COLLISION = 1 << 0,
	SOF_INVISIBLE = 1 << 1,
	SOF_NO_TRANSFORM_MATRIX = 1 << 2,
	SOF_ZOOM_INSTEAD_OF_SCALE = 1 << 3,
	SOF_BOUNDING_BOX_INSTEAD_OF_SPHERE = 1 << 4,
	SOF_DISPLAY_ON_TOP = 1 << 5,
	SOF_NO_RAY_TRACING = 1 << 6,
	SOF_NO_SHADOW = 1 << 7,
	SOF_SEMI_LOOKAT = 1 << 8,
	SOF_SPECIAL_BOUNDING_VOLUMES = 1 << 9,
	SOF_FLAG10 = 1 << 10,
	SOF_FLAG11 = 1 << 11,
	SOF_FLAG12 = 1 << 12,
	SOF_FLAG13 = 1 << 13,
	SOF_FLAG14 = 1 << 14,
	SOF_INFLUENCED_BY_MAGNET = 1 << 15,
	SOF_TRANSPARENT = 1 << 16,
	SOF_NO_LIGHTING = 1 << 17,
	SOF_SUPERIMPOSED_CLIPPING = 1 << 18,
	SOF_OUTLINE_MODE = 1 << 19,
	SOF_FLAG20 = 1 << 20,
	SOF_FLAG21 = 1 << 21,
	SOF_FLAG22 = 1 << 22,
	SOF_FLAG23 = 1 << 23,
	SOF_FLAG24 = 1 << 24,
	SOF_FLAG25 = 1 << 25,
	SOF_FLAG26 = 1 << 26,
	SOF_FLAG27 = 1 << 27,
	SOF_FLAG28 = 1 << 28,
	SOF_FLAG29 = 1 << 29,
	SOF_FLAG30 = 1 << 30,
	SOF_FLAG31 = 1 << 31
} HIE_tdeSpoFlags;

typedef enum HIE_tdeObjType
{
	e_OT_Unknown = 0x0,
	e_OT_World = 0x1,
	e_OT_Perso = 0x2,
	e_OT_Sector = 0x4,
	e_OT_PhysicalObject = 0x8,
	e_OT_IPO = 0x20,
	e_OT_IPO2 = 0x40,
	e_OT_GeometricObject = 0x400,
	e_OT_GeometricShadowObj = 0x80000,
} HIE_tdeObjType;

union HIE_tdstEngineObject
{
	HIE_tdstPerso *p_stPerso;
	HIE_tdstSector *p_stSector;
};

struct HIE_tdstSuperObject
{
	HIE_tdeObjType ulType;
	HIE_tdstEngineObject stEngineObject;

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

struct HIE_tdstPerso
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

struct HIE_tdstStandardGame
{
	union
	{
		struct
		{
			int lFamilyID;
			int lModelID;
			int lInstanceID;
		};

		int a_lObjectId[3];
	};
	
	HIE_tdstSuperObject *p_stSuperObject;

	char _field_10[16];

	BYTE _field_20;
	BYTE ucHitPoints;
	BYTE ucHitPointsMax;
	BYTE ucHitPointsMaxMax;

	DWORD ulCustomBits;

	BYTE ucPlatformType;
	BYTE ucMiscFlags;
	BYTE ucTransparencyZoneMin;
	BYTE ucTransparencyZoneMax;

	DWORD ulSaveCustomBits;

	BYTE ucSaveHitPoints;
	BYTE ucSaveHitPointsMax;
	BYTE ucSaveMiscFlags;
	BYTE ucTooFarLimit;

	int _field_34[3];
	char _field_40;
	BYTE ucActivationBits;
};