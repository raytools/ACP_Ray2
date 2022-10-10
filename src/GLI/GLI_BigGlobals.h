/****************************************************************************
 * GLI - Big Globals Struct
 ****************************************************************************/

#pragma once

#include "GLI_Const.h"
#include "GLI_Def.h"
#include "GLI_Misc.h"

#include "GLD.h"
#include "GEO/GEO.h"
#include "POS/POS.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


/* Big globals struct */
typedef struct GLI_tdstInternalGlobalValuesFor3dEngine
{
	GLD_tdstViewportAttributes *p_stVpt;
	GEO_tdstGeometricObject *p_stObj;
	long lDrawModeMask;
	long lHierachDrawMask;
	long lCurrentDrawMask;
	long GLD_RenderingCounter;
	long lClippingModeMask;

	MTH3D_tdstVector stCenterOfCurrentBoundingSphere;
	MTH_tdxReal stRadiusOfCurrentBoundingSphere;

	/* BIG TABLES */
	GLI_tdstAligned3DVector GLI_TurnedScaledDisplecedPoint[GLI_C_lMaxVertexPerObject];
	GLI_tdstAligned2DVector GLI_ScreenPoint[GLI_C_lMaxVertexPerObject];
	MTH_tdxReal GLI_aDEF_xWaterPlaneDepth[(GLI_C_lMaxVertexPerObject >> 1) - 8];
	GEO_tdstColor GLI_aDEF_stColorsRLID[GLI_C_lMaxVertexPerObject];
	GEO_tdstColor GLI_aDEF_stColorsRLIS[GLI_C_lMaxVertexPerObject];
	GEO_tdstColor GLI_aDEF_stColorsRLIA;
	GLI_tdst2DUVValues GLI_aDEF_stEnvUV[GLI_C_lMaxVertexPerObject];

	GEO_tdstColor GLI_stColorsAdd;
	GEO_tdstColor GLI_stColorsMul;

	POS_tdstCompletePosition *gs_st_CameraMatrix;
	POS_tdstCompletePosition *gs_st_CurrentMatrix;
	POS_tdstCompletePosition gs_st_CurrentMatrixInverted;
	POS_tdstCompletePosition gs_st_CurrentMatrixMultiplyedWithCameraMatrix;

	float fZClipping;
	float fWClipping;
	float fXMinClipping;
	float fXMaxClipping;
	float fYMinClipping;
	float fYMaxClipping;
	GLI_tdstTexture *p_stCurrentTexture;
	GLI_tdstMaterial *hCurrentMaterial;

	struct GLI_tdstCamera_ *p_stCurrentCamera;
	MTH_tdxReal xWaterPlaneDistance;
	GLI_tdstAligned3DVector stWaterPlanNormale;
	unsigned long ulColorInitForSprite;
	unsigned long ulSpecularColorForSprite;
	float fMulU;
	float fMulV;

	/* GLI_tdstZListe* */
	void *p_TheZListe;
	unsigned long ulCurrentZTable;

	/* For fog */
	GLI_tdstFogParams *p_stActiveFog;
	GLI_tdstFogParams *p_stLastComputedFog;
	long xFogIsOn;
	long xTextureDontAcceptFog;

	/* For mirror */
	long lAMirrorIsDetected;
	BOOL bDrawMirrorSymetric;
	long lDisplayMenuIsDetected;

	/* For alpha */
	float xGlobalAlpha;
}
GLI_tdstInternalGlobalValuesFor3dEngine;


/* Big globals pointer */
ACP_VAR GLI_tdstInternalGlobalValuesFor3dEngine **const GLI_BIG_GLOBALS;
