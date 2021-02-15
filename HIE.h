#pragma once
#include "MTH.h"
#include "AI.h"

/////////////////////
//
// Object Hierarchy
// 
/////////////////////

typedef struct HIE_stSuperObject HIE_tdstSuperObject;
typedef union HIE_stEngineObject HIE_tdstEngineObject;

////////////////
// SuperObject
////////////////

typedef enum
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
} HIE_SPO_FLAGS;

typedef enum
{
	SOT_UNKNOWN = 0x0,
	SOT_WORLD = 0x1,
	SOT_PERSO = 0x2,
	SOT_SECTOR = 0x4,
	SOT_PHYSICAL_OBJECT = 0x8,
	SOT_IPO = 0x20,
	SOT_IPO_2 = 0x40,
	SOT_GEOMETRIC_OBJECT = 0x400,
	SOT_GEOMETRIC_SHADOW_OBJECT = 0x80000,
} HIE_SPO_TYPE;

typedef struct HIE_stSuperObject
{
	HIE_SPO_TYPE ulType;

	HIE_tdstEngineObject *p_stEngineObject;

	HIE_tdstSuperObject *p_stFirstChild;
	HIE_tdstSuperObject *p_stLastChild;
	int nChildren;

	HIE_tdstSuperObject *p_stNext;
	HIE_tdstSuperObject *p_stPrevious;
	HIE_tdstSuperObject *p_stParent;

	MTH_tdstMatrix *p_stMatrix1;
	MTH_tdstMatrix *p_stMatrix2;

	void *pGlobalMatrix;
	DWORD ulDrawFlags;

	HIE_SPO_FLAGS ulFlags;

	union
	{
		void *pBoundingVolume;
		//BOUNDING_VOL_BOX *lp_bvBoundingBox;
		//BOUNDING_VOL_SPHERE *lp_bvBoundingSphere;
	};
} HIE_tdstSuperObject;


/////////////////////////////
// EngineObject and StdGame
/////////////////////////////

typedef struct HIE_stStandardGame
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

	// TODO
} HIE_tdstStandardGame;

typedef struct HIE_stPerso
{
	// TODO: fix names, replace void pointers
	void *p3dData;
	HIE_tdstStandardGame *p_stStdGame;
	void *dynam;
	AI_tdstBrain *p_stBrain;
	void *off_camera;
	void *off_collSet;
	void *off_msWay;
	void *off_msLight;
	void *sectInfo;
} HIE_tdstPerso;

typedef struct HIE_stSector
{
	// TODO: fill out this struct correctly
	void *persoSPOList;
	void *staticLightsList;
	void *dynamicLightsList;
} HIE_tdstSector;

typedef union HIE_stEngineObject
{
	HIE_tdstPerso stPerso;
	HIE_tdstSector stSector;
} HIE_tdstEngineObject;
