/****************************************************************************
 *
 * GLI - Graphics module
 *
 ****************************************************************************/

#pragma once

#include "GLI_Const.h"
#include "GLI_Def.h"
#include "GLI_Misc.h"
#include "GLI_BigGlobals.h"
#include "GLD.h"

#include "GEO/GEO_Def.h"
#include "HIE/HIE_Def.h"
#include "POS/POS.h"
#include "MTH.h"
#include "LST.h"
#include "apidef.h"


typedef struct GLI_tdst2DVertex
{
	MTH_tdxReal xX;
	MTH_tdxReal xY;
	MTH_tdxReal xOoZ;
}
GLI_tdst2DVertex;

typedef struct GLI_tdstMaterial
{
	unsigned long ulMaterialType;

	GEO_tdstColor stAmbient;
	GEO_tdstColor stDiffuse;
	GEO_tdstColor stSpecular;
	GEO_tdstColor stColor;
	long lSpecularExponent;

	GLI_tdstTexture *p_stTexture;

	/* scrolling material */
	MTH_tdxReal xAddU;
	MTH_tdxReal xAddV;
	MTH_tdxReal xConstantAddU;
	MTH_tdxReal xConstantAddV;
	long lIncrementIsEnable;

	/* for animated textures */
	unsigned long dwActualRefreshNumber;
	GLI_tdstAnimatedTextureNode *p_stFirstAnimatedTextureNode;
	GLI_tdstAnimatedTextureNode *p_stActualAnimatedTextureNode;
	long lNumberOfDisplayNode;
	MTH_tdxReal xActualDisplayTimeSinceStartOfLastTexture;
	ACP_tdxBool xIsLocked;
}
GLI_tdstMaterial;

typedef struct GLI_tdstTexture
{
	BOOL bIsAvailable;
	long lTextureQuality;

	/* texture data */
	void *p_vBitMap;
	void *p_vColorTable;

	/* Parameter specific for graphics card */
	void *p_stSpecParam;

	unsigned long ulTextureCaps;

	/* texture size (after compression) */
	unsigned short uwHeight;
	unsigned short uwWidth;

	/* texture size (before compression) */
	unsigned short uwRealHeight;
	unsigned short uwRealWidth;

	/* data for scrolling texture */
	MTH_tdxReal xAddU;
	MTH_tdxReal xAddV;
	BOOL lIncrementIsEnable;

	unsigned long ulChromakeyColorRGBA;

	/* MipMapping */
	long lNumberOfLod;
	unsigned long ulCompressionCounter;
	unsigned long ulTypeOfCompression;
	unsigned long ulTypeOfMipMapping;
	GLI_tdstTexture *p_TextureOfSubstitution;

	unsigned char ucBilinearMode;
	unsigned char ucCyclingMode;

	char szFileName[128];
}
GLI_tdstTexture;

typedef struct GLI_tdstAnimatedTextureNode
{
	GLI_tdstTexture *p_stTexture;
	MTH_tdxReal xDisplayTime;
	GLI_tdstAnimatedTextureNode *p_stNextDisplayNode;
}
GLI_tdstAnimatedTextureNode;

typedef struct GLI_tdstCamera
{
	long lSizeOfThis;
	long lTypeOfThis;
	long lCameraMode;
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
}
GLI_tdstCamera;

typedef struct GLI_tdstViewportManagement
{
	HIE_tdstSuperObject *hCamera;
	HIE_tdstSuperObject *hTempCamera;
	GLI_tdstCamera *p_stCamera;
	ACP_tdxBool bValid;
}
GLI_tdstViewportManagement;

typedef struct GLI_tdstNodeCamera
{
	HIE_tdstSuperObject *p_stSuperObjectCamera;
	LST_M_DynamicElementDecl(GLI_tdstNodeCamera)
}
GLI_tdstNodeCamera;

LST_M_DynamicListDecl(GLI_tdstNodeCamera);

typedef struct GLI_tdstSpecificAttributesFor3D
{
	GLI_tdstCamera *p_stCam;
	MTH_tdxReal xNear;
}
GLI_tdstSpecificAttributesFor3D;

typedef struct GLI_tdstZBufferForLight
{
	long lSizeX;
	long lSizeY;

	MTH_tdxReal xCoefX;
	MTH_tdxReal xCoefY;
	MTH_tdxReal *p_xZBufferMap;
	MTH_tdxReal *p_xMiddleZBufferMap;
}
GLI_tdstZBufferForLight;

typedef struct GLI_tdstLight
{
	BOOL bOnOff;
	BOOL bThisLightIsZBuffered;
	long lTypeOfLight;

	MTH_tdxReal xFar;
	MTH_tdxReal xNear;

	/* for hotspot */
	MTH_tdxReal xLittleAlpha;
	MTH_tdxReal xBigAlpha;
	MTH_tdxReal xLittleTangent;
	MTH_tdxReal xBigTangent;
	POS_tdstCompletePosition stMatrix;
	GLI_tdstZBufferForLight stZBuffer;
	GEO_tdstColor stColor;

	ACP_tdxBool bValid;
	unsigned char ucObjectPainted;
	ACP_tdxBool bIsPainting;
	unsigned char ucIsAlpha; /* 0: RGBA; 1: A Only; 2: RGB Only */
	MTH3D_tdstVector stInter_Min_Pos;
	MTH3D_tdstVector stExter_Min_Pos;
	MTH3D_tdstVector stInter_Max_Pos;
	MTH3D_tdstVector stExter_Max_Pos;
	MTH3D_tdstVector stCenterBox;
	MTH_tdxReal xRadius;
	MTH_tdxReal xIntensity_Min;
	MTH_tdxReal xIntensity_Max;
	GEO_tdstColor stBackgroundColor;
}
GLI_tdstLight;


/*
 * Variables
 */

ACP_VAR MTH_tdxReal *const GLI_g_fZValueForSprite;
ACP_VAR unsigned char *const GLI_g_bForceAAAColor;
ACP_VAR unsigned char *const GLI_a3_ForcedAAAColor;

ACP_VAR char *const GLI_g_cGlobalFogIsOn;

ACP_VAR MTH_tdxReal *const GLI_g_xBrightness;

ACP_VAR void **const GLI_g_hConcatTexturesFile;
ACP_VAR void **const GLI_gs_p_ConvertBufferMipMapping;

ACP_VAR unsigned long *const GLI_g_ulNumberOfLoadedTexture;
ACP_VAR long *const GLI_gs_lNumberOfTextureToCreate;
ACP_VAR GLI_tdstTexture **const GLI_gs_aDEFTableOfTextureAlreadyRead;
ACP_VAR unsigned long *const GLI_gs_aDEFTableOfTextureMemoryChannels;


/*
 * Functions
 */

ACP_FUNC void (*GLI_vSetGlobalAlpha)( MTH_tdxReal xAlpha );
ACP_FUNC MTH_tdxReal (*GLI_fn_xGetGlobalAlpha)( void );

ACP_FUNC void (*GLI_fn_vSetBrightness)( long lValue );
ACP_FUNC long (*GLI_fn_lGetBrightness)( void );

ACP_FUNC void (**GLI_DRV_vSendSpriteToClip)( GLI_tdstAligned2DVector *a4_st2DVertex ,MTH_tdxReal xZ, GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );
ACP_FUNC void (**GLI_DRV_vSendSpriteToClipWithUV)( GLI_tdstAligned2DVector *a4_st2DVertex, MTH_tdxReal *a8_stUVVertex, MTH_tdxReal xZ, GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );

ACP_FUNC void (*GLI_vDoMaterialSelection)( GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );
ACP_FUNC void (*GLI_vDraw2DSpriteWithPercent)( GLD_tdstViewportAttributes *p_stViewport, MTH_tdxReal XMin, MTH_tdxReal YMin, MTH_tdxReal XMax, MTH_tdxReal YMax, GLI_tdstMaterial *hMaterial );
ACP_FUNC void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, GLD_tdstViewportAttributes *p_stViewport );

ACP_FUNC void (*GLI_vDrawWorldSprite)( MTH_tdxReal *a3_xPosition, GLI_tdstMaterial *hMaterial, MTH_tdxReal xScaleX, MTH_tdxReal xScaleY, GLD_tdstViewportAttributes *p_stViewport, unsigned long ulAnimTime );

ACP_FUNC void (*GLI_xLoadTextureInTexelField)( GLI_tdstTexture *p_stTexture, void *pBuffer, BOOL bHideProgress );
ACP_FUNC char * (*GLI_fn_szGetPathOfTexture)( void );
ACP_FUNC void (*GLI_vComputeTextures)( void );
ACP_FUNC void (*GLI_vReloadTextures)( void );

ACP_FUNC void (*GLI_xCreateMaterial)( GLI_tdstMaterial **p_hMaterial );
ACP_FUNC void (*GLI_xSetMaterialTexture)( GLI_tdstMaterial *hMaterial, GLI_tdstTexture *p_stTexture );

ACP_FUNC void (*GLI_xSendObjectToViewportWithLights)( GLD_tdstViewportAttributes *p_stVpt, GEO_tdstGeometricObject *p_stObj, long lDrawModeMask );
ACP_FUNC void (*GLI_xSendObjectElement)( GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );
