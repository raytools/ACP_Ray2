#pragma once

#include "GLI_Const.h"
#include "GLD.h"
#include "../GEO/GEO.h"
#include "../HIE/HIE_Def.h"
#include "../POS/POS.h"
#include "../MTH.h"
#include "../LST.h"
#include "../apidef.h"


//////////////////////////
//
// GLI - Graphics Module
//
//////////////////////////


typedef struct GLI_tdstCamera GLI_tdstCamera;
typedef struct GLI_tdst2DVertex GLI_tdst2DVertex;
typedef struct GLI_tdstSpecificAttributesFor3D GLI_tdstSpecificAttributesFor3D;
typedef struct GLI_tdstViewportManagement GLI_tdstViewportManagement;
typedef struct GLI_tdstNodeCamera GLI_tdstNodeCamera;

typedef struct GLI_tdstTexture GLI_tdstTexture;
typedef struct GLI_tdstAnimatedTextureNode GLI_tdstAnimatedTextureNode;
typedef struct GLI_tdstMaterial GLI_tdstMaterial;


ACP_API extern MTH_tdxReal *const GLI_p_fZValueForSprite;
ACP_API extern BYTE *const GLI_p_bForceAAAColor;

ACP_API extern void **const GLI_g_hConcatTexturesFile;
ACP_API extern void **const GLI_gs_p_ConvertBufferMipMapping;

ACP_API extern DWORD *const GLI_g_ulNumberOfLoadedTexture;
ACP_API extern GLI_tdstTexture **const GLI_gs_aDEFTableOfTextureAlreadyRead;
ACP_API extern DWORD *const GLI_gs_aDEFTableOfTextureMemoryChannels;


ACP_API extern void (*GLI_vSetGlobalAlpha)( MTH_tdxReal xAlpha );
ACP_API extern MTH_tdxReal (*GLI_fn_xGetGlobalAlpha)( void );

ACP_API extern void (*GLI_vDraw2DSpriteWithPercent)( GLD_tdstViewportAttributes *p_stViewport, MTH_tdxReal XMin, MTH_tdxReal YMin, MTH_tdxReal XMax, MTH_tdxReal YMax, void *hMaterial );
ACP_API extern void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, GLD_tdstViewportAttributes *p_stViewport );

ACP_API extern void (*GLI_xLoadTextureInTexelField)( GLI_tdstTexture *p_stTexture, void *pBuffer, BOOL bHideProgress );
ACP_API extern char * (*GLI_fn_szGetPathOfTexture)( void );
ACP_API extern void (*GLI_vComputeTextures)( void );
ACP_API extern void (*GLI_vReloadTextures)( void );


struct GLI_tdst2DVertex
{
	MTH_tdxReal xX;
	MTH_tdxReal xY;
	MTH_tdxReal xOoZ;
};

struct GLI_tdstCamera
{
	int lSizeOfThis;
	int lTypeOfThis;
	int lCameraMode;
	POS_tdstCompletePosition stMatrix;
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
	ACP_tdxBool bValid;
};

struct GLI_tdstNodeCamera
{
	HIE_tdstSuperObject *p_stSuperObjectCamera;
	LST_M_DynamicElementDecl(GLI_tdstNodeCamera)
};

LST_M_DynamicListDecl(GLI_tdstNodeCamera);

struct GLI_tdstTexture
{
	BOOL bIsAvailable;
	int lTextureQuality;

	/* texture data */
	void *p_vBitMap;
	void *p_vColorTable;

	/* Parameter specific for graphics card */
	void *p_stSpecParam;

	DWORD ulTextureCaps;

	/* texture size (after compression) */
	WORD uwHeight;
	WORD uwWidth;

	/* texture size (before compression) */
	WORD uwRealHeight;
	WORD uwRealWidth;

	/* data for scrolling texture */
	MTH_tdxReal xAddU;
	MTH_tdxReal xAddV;
	BOOL lIncrementIsEnable;

	DWORD ulChromakeyColorRGBA;

	/* MipMapping */
	int lNumberOfLod;
	DWORD ulCompressionCounter;
	DWORD ulTypeOfCompression;
	DWORD ulTypeOfMipMapping;
	GLI_tdstTexture * p_TextureOfSubstitution;

	BYTE ucBilinearMode;
	BYTE ucCylingMode;

	char szFileName[128];
};

struct GLI_tdstAnimatedTextureNode
{
	GLI_tdstTexture *p_stTexture;
	MTH_tdxReal xDisplayTime;
	GLI_tdstAnimatedTextureNode *p_stNextDisplayNode;
};

struct GLI_tdstMaterial
{
	DWORD ulMaterialType;

	GEO_tdstColor stAmbient;
	GEO_tdstColor stDiffuse;
	GEO_tdstColor stSpecular;
	GEO_tdstColor stColor;
	int lSpecularExponent;

	GLI_tdstTexture *p_stTexture;

	/* scrolling material */
	MTH_tdxReal xAddU;
	MTH_tdxReal xAddV;
	MTH_tdxReal xConstantAddU;
	MTH_tdxReal xConstantAddV;
	int lIncrementIsEnable;

	/* for animated textures */
	DWORD dwActualRefreshNumber;
	GLI_tdstAnimatedTextureNode *p_stFirstAnimatedTextureNode;
	GLI_tdstAnimatedTextureNode *p_stActualAnimatedTextureNode;
	int lNumberOfDisplayNode;
	MTH_tdxReal xActualDisplayTimeSinceStartOfLastTexture;
	ACP_tdxBool xIsLocked;
};
