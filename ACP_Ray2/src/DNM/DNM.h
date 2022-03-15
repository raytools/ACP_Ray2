#pragma once

#include "DNM_Def.h"
#include "../HIE/HIE_Def.h"
#include "../MTH.h"
#include "../POS/POS.h"


//////////////////////////
//
// DNM - Dynamics Module
// 
//////////////////////////


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
	MTH_tdxReal xSlopeLimit; /* tan of slope limit */
	MTH_tdxReal xCosSlope; /* cos of slope limit */
	MTH_tdxReal xSlide;
	MTH_tdxReal xRebound;

	MTH3D_tdstVector stImposeSpeed;
	MTH3D_tdstVector stProposeSpeed;
	MTH3D_tdstVector stPreviousSpeed;
	MTH3D_tdstVector stScale;
	MTH3D_tdstVector stSpeedAnim;
	MTH3D_tdstVector stSafeTranslation;
	MTH3D_tdstVector stAddTranslation;

	POS_tdstCompletePosition stPreviousMatrix;
	POS_tdstCompletePosition stCurrentMatrix;
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

/* Module Allowing the Communication of Datas from the Player or the Intelligence to the Dynamics */
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
	POS_tdstCompletePosition stAbsolutePreviousMatrix;
	POS_tdstCompletePosition stPrevPreviousMatrix;
};


/////////////
// Dynamics
/////////////

struct DNM_tdstDynam
{
	DNM_tdstDynamics *p_stDynamics;
	DNM_tdstParsingDatas *p_stParsingDatas; /* Data used during the frame */
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
	/* Surface report */
	DWORD ulPrevSurfaceState;
	DWORD ulCurrSurfaceState;

	/* Obstacle report */
	DNM_tdstObstacle stObstacle;
	DNM_tdstObstacle stGround;
	DNM_tdstObstacle stWall;
	DNM_tdstObstacle stCharacter;
	DNM_tdstObstacle stWater;
	DNM_tdstObstacle stCeil;

	/* Kinetic report */
	MTH_tdstMove stAbsolutePrevSpeed;
	MTH_tdstMove stAbsoluteCurrSpeed;
	MTH_tdstMove stAbsolutePrevPosition;
	MTH_tdstMove stAbsoluteCurrPosition;

	BYTE ucBitField;
};

struct DNM_tdstParsingDatas
{
	MTH3D_tdstVector stPosition;
	MTH_tdxReal xOutAlpha;
	MTH3D_tdstVector stVector;
};

struct DNM_tdstMecMatCharacteristics
{
	MTH_tdxReal xSlide;
	MTH_tdxReal xRebound;
};
