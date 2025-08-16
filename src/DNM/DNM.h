/****************************************************************************
 *
 * DNM - Dynamics Module
 *
 ****************************************************************************/

#pragma once

#include "DNM_Def.h"
#include "DNM_Const.h"
#include "HIE/HIE_Def.h"
#include "GMT/GMT.h"
#include "POS/POS.h"
#include "MTH.h"

typedef enum {
	DNM_eMIC_Error = -1,
	DNM_eCamera,
	DNM_eBase,
} DNM_tdeMechanicsID;

/*
 * Dynamics Blocks
 */
typedef struct DNM_stMecBaseIdCard
{
	/* Identity */
	DNM_tdeMechanicsID	m_eIdentity;
	unsigned long		ulFlags;		/* Bit field */

	MTH_tdxReal m_xGravity;				/* gravity factor */
	MTH_tdxReal m_xSlide;				/* slide parameter for collision control */
	MTH_tdxReal m_xRebound;				/* rebound parameter for collision control */
	MTH_tdxReal m_xSlopeLimit;			/* slope limit */
	MTH_tdxReal m_xInertiaX;			/* x inertia */
	MTH_tdxReal m_xInertiaY;			/* y inertia */
	MTH_tdxReal m_xInertiaZ;			/* z inertia */
	MTH_tdxReal m_xTiltIntensity;		/* tilt intensity */
	MTH_tdxReal m_xTiltInertia;			/* tilt inertia   ( 0-1 ) */
	MTH_tdxReal m_xTiltOrigin;			/* tilt rotation origin on Z axis */
	MTH3D_tdstVector m_stMaxSpeed;		/* max speed limit */
} DNM_tdstMecBaseIdCard;

typedef struct DNM_tdstDynamicsBaseBlock
{
	long lObjectType;
	DNM_tdstMecBaseIdCard *pCurrentIdCard;

	unsigned long ulFlags;
	unsigned long ulEndFlags;

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

	unsigned char ucNbFrame;
	DNM_tdstReport *p_stReport;
} DNM_tdstDynamicsBaseBlock;

typedef struct DNM_tdstDynamicsAdvancedBlock
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
	unsigned char ucCollideCounter;
}
DNM_tdstDynamicsAdvancedBlock;

/* Module Allowing the Communication of Datas from the Player or the Intelligence to the Dynamics */
typedef struct DNM_tdstMACDPID
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
	unsigned short uwData9;
	MTH3D_tdstVector stData10;
	MTH_tdxReal xData11;
	MTH3D_tdstVector stData12;
	MTH_tdxReal xData13;
	unsigned char ucData14;
}
DNM_tdstMACDPID;

typedef struct DNM_tdstDynamicsComplexBlock
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
}
DNM_tdstDynamicsComplexBlock;


/*
 * Dynamics
 */

typedef struct DNM_tdstDynam
{
	DNM_tdstDynamics *p_stDynamics;
	DNM_tdstParsingDatas *p_stParsingDatas; /* Data used during the frame */
	long eUsedMechanics;
}
DNM_tdstDynam;

typedef struct DNM_tdstBaseDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
}
DNM_tdstBaseDynamics;

typedef struct DNM_tdstAdvancedDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
	DNM_tdstDynamicsAdvancedBlock stDynamicsAdvanced;
}
DNM_tdstAdvancedDynamics;

typedef struct DNM_tdstComplexDynamics
{
	DNM_tdstDynamicsBaseBlock stDynamicsBase;
	DNM_tdstDynamicsAdvancedBlock stDynamicsAdvanced;
	DNM_tdstDynamicsComplexBlock stDynamicsComplex;
}
DNM_tdstComplexDynamics;

typedef struct DNM_tdstObstacle
{
	MTH_tdxReal xRate;
	MTH3D_tdstVector stNorm;
	MTH3D_tdstVector stContact;
	GMT_tdstGameMaterial *hMyMaterial;
	GMT_tdstGameMaterial *hCollidedMaterial;
	HIE_tdstSuperObject *p_stSupObj;
}
DNM_tdstObstacle;

typedef struct DNM_tdstReport
{
	/* Surface report */
	unsigned long ulPrevSurfaceState;
	unsigned long ulCurrSurfaceState;

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

	unsigned char ucBitField;
}
DNM_tdstReport;

typedef struct DNM_tdstParsingDatas
{
	MTH3D_tdstVector stPosition;
	MTH_tdxReal xOutAlpha;
	MTH3D_tdstVector stVector;
}
DNM_tdstParsingDatas;

typedef struct DNM_tdstMecMatCharacteristics
{
	MTH_tdxReal xSlide;
	MTH_tdxReal xRebound;
}
DNM_tdstMecMatCharacteristics;


/*
 * Functions
 */

ACP_FUNC MTH_tdxReal (*DNM_fn_xComputeAngleOfPerso)( HIE_tdstSuperObject *pSuperObjPerso );
