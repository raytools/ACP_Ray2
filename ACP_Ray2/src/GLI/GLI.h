#pragma once

#include <HIE/HIE_Def.h>
#include <MTH.h>
#include <apidef.h>


//////////////////////////
//
// GLI - Graphics Module
//
//////////////////////////


typedef struct GLI_tdstCamera GLI_tdstCamera;
typedef struct GLI_tdst2DVertex GLI_tdst2DVertex;
typedef struct GLI_tdstSpecificAttributesFor3D GLI_tdstSpecificAttributesFor3D;
typedef struct GLI_tdstViewportManagement GLI_tdstViewportManagement;
typedef struct GLI_tdstNodeCameraList GLI_tdstNodeCameraList;
typedef struct GLI_tdstNodeCamera GLI_tdstNodeCamera;


ACP_API extern MTH_tdxReal *const GLI_p_fZValueForSprite;
ACP_API extern BYTE *const GLI_p_bForceAAAColor;

ACP_API extern void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha,
                                          void *pContext );


struct GLI_tdst2DVertex
{
	MTH_tdxReal xX;
	MTH_tdxReal xY;
	MTH_tdxReal xOoZ;
};

struct GLI_tdstCamera
{
	int lCameraMode;
	DWORD _dword_4;
	DWORD _dword_8;
	MTH_tdstTransformation stMatrix;
	MTH_tdxReal xAlphaX;
	MTH_tdxReal xAlphaY;
	MTH_tdxReal xNear;
	MTH_tdxReal xFar;
	MTH_tdxReal xScreen;
	GLI_tdst2DVertex stScale;
	GLI_tdst2DVertex stTrans;
	MTH_tdxReal xXProjectionRatio;
	MTH_tdxReal xYProjectionRatio;
	MTH3D_tdstVector stNormPlaneLeft;
	MTH_tdxReal xDistPlaneLeft;
	MTH3D_tdstVector stNormPlaneRight;
	MTH_tdxReal xDistPlaneRight;
	MTH3D_tdstVector stNormPlaneUp;
	MTH_tdxReal xDistPlaneUp;
	MTH3D_tdstVector stNormPlaneDown;
	MTH_tdxReal xDistPlaneDown;
	MTH_tdxReal xRatio;
};

struct GLI_tdstSpecificAttributesFor3D
{
	GLI_tdstCamera *p_stCam;
	MTH_tdxReal xNear;
};

struct GLI_tdstViewportManagement
{
	HIE_tdstSuperObject *hCamera;
	HIE_tdstSuperObject *hTempCamera;
	GLI_tdstCamera *p_stCamera;
	BYTE bValid;
};

struct GLI_tdstNodeCameraList
{
	GLI_tdstNodeCamera *hFirstElement;
	GLI_tdstNodeCamera *hLastElement;
	int lNumberOfElements;
};

struct GLI_tdstNodeCamera
{
	HIE_tdstSuperObject *p_stSuperObjectCamera;
	GLI_tdstNodeCamera *hNextBrother;
	GLI_tdstNodeCamera *hPrevBrother;
	GLI_tdstNodeCameraList *hFather;
};
