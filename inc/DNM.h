#pragma once
#include "apidef.h"
#include "MTH.h"
#include "HIE.h"


//////////////////////////
//
// DNM - Dynamics Module
// 
//////////////////////////


typedef struct DNM_tdstDynam DNM_tdstDynam;
typedef struct DNM_tdstObstacle DNM_tdstObstacle;
typedef struct DNM_tdstReport DNM_tdstReport;

typedef struct DNM_tdstBaseDynamics DNM_tdstBaseDynamics;
typedef struct DNM_tdstAdvancedDynamics DNM_tdstAdvancedDynamics;
typedef struct DNM_tdstComplexDynamics DNM_tdstComplexDynamics;
typedef DNM_tdstComplexDynamics DNM_tdstDynamics;

typedef struct DNM_tdstDynamicsBaseBlock DNM_tdstDynamicsBaseBlock;
typedef struct DNM_tdstDynamicsAdvancedBlock DNM_tdstDynamicsAdvancedBlock;
typedef struct DNM_tdstDynamicsComplexBlock DNM_tdstDynamicsComplexBlock;

typedef struct DNM_tdstMACDPID DNM_tdstMACDPID;


////////////////////
// Dynamics Blocks
////////////////////

struct DNM_tdstDynamicsBaseBlock
{
	int lObjectType;
	void *pCurrentIdCard;
	DWORD ulFlags;
	DWORD ulEndFlags;
	MTH_tdxReal xGravity;
	MTH_tdxReal xSlopeLimit;
	MTH_tdxReal xCosSlope;
	MTH_tdxReal xSlide;
	MTH_tdxReal xRebound;
	MTH3D_tdstVector stImposeSpeed;
	MTH3D_tdstVector stProposeSpeed;
	MTH3D_tdstVector stPreviousSpeed;
	MTH3D_tdstVector stScale;
	MTH3D_tdstVector stSpeedAnim;
	MTH3D_tdstVector stSafeTranslation;
	MTH3D_tdstVector stAddTranslation;
	MTH_tdstTransformation stPreviousMatrix;
	MTH_tdstTransformation stCurrentMatrix;
	MTH3D_tdstMatrix stImposeRotationMatrix;
	BYTE ucNbFrame;
	DNM_tdstReport *p_stReport;
};

struct DNM_tdstDynamicsAdvancedBlock
{
	MTH_tdxReal xInertiaX;
	MTH_tdxReal xInertiaY;
	MTH_tdxReal xInertiaZ;
	MTH_tdxReal xStreamPrority;
	MTH_tdxReal xStreamFactor;
	MTH_tdxReal xSlideFactorX;
	MTH_tdxReal xSlideFactorY;
	MTH_tdxReal xSlideFactorZ;
	MTH_tdxReal xPreviousSlide;
	MTH3D_tdstVector stMaxSpeed;
	MTH3D_tdstVector stStreamSpeed;
	MTH3D_tdstVector stAddSpeed;
	MTH3D_tdstVector stLimit;
	MTH3D_tdstVector stCollisionTranslation;
	MTH3D_tdstVector stInertiaTranslation;
	MTH3D_tdstVector stGroundNormal;
	MTH3D_tdstVector stWallNormal;
	BYTE ucCollideCounter;
};

// WTF?
struct DNM_tdstMACDPID
{
	MTH_tdxReal xData0;
	MTH3D_tdstVector stData1;
	MTH3D_tdstVector stData2;
	MTH3D_tdstVector stData3;
	MTH_tdxReal xData3;
	MTH_tdxReal xData4;
	MTH_tdxReal xData5;

	struct
	{
		MTH_tdxReal xAngle;
		MTH3D_tdstVector stAxis;
	} stData6;

	struct
	{
		MTH_tdxReal xAngle;
		MTH3D_tdstVector stAxis;
	} stData7;

	char cData8;
	WORD uwData9;
	MTH3D_tdstVector stData10;
	MTH_tdxReal xData11;
	MTH3D_tdstVector stData12;
	MTH_tdxReal xData13;
	BYTE ucData14;
};

struct DNM_tdstDynamicsComplexBlock
{
	MTH_tdxReal xTiltIntensity;
	MTH_tdxReal xTiltInertia;
	MTH_tdxReal xTiltOrigin;
	MTH_tdxReal xTiltAngle;
	MTH_tdxReal xHangingLimit;
	MTH3D_tdstVector stContact;
	MTH3D_tdstVector stFallTranslation;
	DNM_tdstMACDPID stExternalDatas;
	HIE_tdstSuperObject *p_stPlatform;
	MTH_tdstTransformation stAbsolutePreviousMatrix;
	MTH_tdstTransformation stPrevPreviousMatrix;
};


/////////////
// Dynamics
/////////////

struct DNM_tdstDynam
{
	DNM_tdstDynamics *p_stDynamics;
	// DNM_tdstParsingDatas *
	void *p_stParsingDatas;
	int eUsedMechanics;
};

struct DNM_tdstBaseDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
};

struct DNM_tdstAdvancedDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
	DNM_tdstDynamicsAdvancedBlock stDynamicsAdvanced;
};

struct DNM_tdstComplexDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
	DNM_tdstDynamicsAdvancedBlock stDynamicsAdvanced;
	DNM_tdstDynamicsComplexBlock stDynamicsComplex;
};

struct DNM_tdstObstacle
{
	MTH_tdxReal xRate;
	MTH3D_tdstVector stNorm;
	MTH3D_tdstVector stContact;
	// GMT_tdstGameMaterial *
	void *hMyMaterial;
	// GMT_tdstGameMaterial *
	void *hCollidedMaterial;
	HIE_tdstSuperObject *p_stSupObj;
};

struct DNM_tdstReport
{
	DWORD ulPrevSurfaceState;
	DWORD ulCurrSurfaceState;
	DNM_tdstObstacle stObstacle;
	DNM_tdstObstacle stGround;
	DNM_tdstObstacle stWall;
	DNM_tdstObstacle stCharacter;
	DNM_tdstObstacle stWater;
	DNM_tdstObstacle stCeil;
	MTH_tdstMove stAbsolutePrevSpeed;
	MTH_tdstMove stAbsoluteCurrSpeed;
	MTH_tdstMove stAbsolutePrevPosition;
	MTH_tdstMove stAbsoluteCurrPosition;
	BYTE ucBitField;
};
