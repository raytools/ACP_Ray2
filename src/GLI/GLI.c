/****************************************************************************
 *
 * GLI - Graphics module
 *
 ****************************************************************************/

#include "GLI.h"


/*
 * Variables
 */

MTH_tdxReal *const GLI_g_fZValueForSprite = OFFSET(0x4A07D4);
unsigned char *const GLI_g_bForceAAAColor = OFFSET(0x4A72AC);
unsigned char *const GLI_a3_ForcedAAAColor = OFFSET(0x503748);

char *const GLI_g_cGlobalFogIsOn = OFFSET(0x4A7248);

MTH_tdxReal *const GLI_g_xBrightness = OFFSET(0x4A0488);

void **const GLI_g_hConcatTexturesFile = OFFSET(0x4A7280);
void **const GLI_gs_p_ConvertBufferMipMapping = OFFSET(0x503D50);

unsigned long *const GLI_g_ulNumberOfLoadedTexture = OFFSET(0x502660);
long *const GLI_gs_lNumberOfTextureToCreate = OFFSET(0x501644);
GLI_tdstTexture **const GLI_gs_aDEFTableOfTextureAlreadyRead = OFFSET(0x502680);
unsigned long *const GLI_gs_aDEFTableOfTextureMemoryChannels = OFFSET(0x501660);

POS_tdstCompletePosition **const GLI_g_p_stCurrentMatrix = OFFSET(0x506B00);

/* Big Globals */
GLI_tdstInternalGlobalValuesFor3dEngine **const GLI_BIG_GLOBALS = OFFSET(0x5036AC);


/*
 * Functions
 */

void (*GLI_vSetGlobalAlpha)( MTH_tdxReal xAlpha ) = OFFSET(0x42A300);
MTH_tdxReal (*GLI_fn_xGetGlobalAlpha)( void ) = OFFSET(0x42A360);

void (*GLI_fn_vSetBrightness)( long lValue ) = OFFSET(0x422570);
long (*GLI_fn_lGetBrightness)( void ) = OFFSET(0x4225B0);


void (**GLI_DRV_vSendSpriteToClip)(
	GLI_tdstAligned2DVector *a4_st2DVertex,
	MTH_tdxReal xZ,
	GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals
) = OFFSET(0x504530);

void (**GLI_DRV_vSendSpriteToClipWithUV)(
	GLI_tdstAligned2DVector *a4_st2DVertex,
	MTH_tdxReal *a8_stUVVertex,
	MTH_tdxReal xZ,
	GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals
) = OFFSET(0x504524);


void (**GLI_DRV_vSendSingleLineToClip)(
	GLD_tdstViewportAttributes *p_stVpt,
	GLI_tdstAligned3DVector *p_stVertex1,
	GLI_tdstAligned2DVector *p_st2DVertex1,
	GLI_tdstAligned3DVector *p_stVertex2,
	GLI_tdstAligned2DVector *p_st2DVertex2,
	GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals,
	long lDrawModeMask,
	GEO_tdstColor *p_stColor
) = OFFSET(0x504834);


void (*GLI_vDoMaterialSelection)( GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals ) = OFFSET(0x42A410);

void (*GLI_vDraw2DSpriteWithPercent)(
	GLD_tdstViewportAttributes *p_stViewport,
	MTH_tdxReal XMin,
	MTH_tdxReal YMin,
	MTH_tdxReal XMax,
	MTH_tdxReal YMax,
	GLI_tdstMaterial *hMaterial
) = OFFSET(0x429670);

void (*GLI_vDisplayFrame)(
	MTH2D_tdstVector *p_stTopLeft,
	MTH2D_tdstVector *p_stBottomRight,
	MTH_tdxReal xAlpha,
	GLD_tdstViewportAttributes *p_stViewport
) = OFFSET(0x429820);

void (*GLI_vDrawWorldSprite)(
	MTH_tdxReal *a3_xPosition,
	GLI_tdstMaterial *hMaterial,
	MTH_tdxReal xScaleX,
	MTH_tdxReal xScaleY,
	GLD_tdstViewportAttributes *p_stViewport,
	unsigned long ulAnimTime
) = OFFSET(0x429890);


void (*GLI_xLoadTextureInTexelField)( GLI_tdstTexture *p_stTexture, void *pBuffer, BOOL bHideProgress )
	= OFFSET(0x426550);

char * (*GLI_fn_szGetPathOfTexture)( void ) = OFFSET(0x42D1B0);
void (*GLI_vComputeTextures)( void ) = OFFSET(0x426980);
void (*GLI_vReloadTextures)( void ) = OFFSET(0x426A40);

void (*GLI_xCreateMaterial)( GLI_tdstMaterial **p_hMaterial ) = OFFSET(0x4245F0);
void (*GLI_xSetMaterialTexture)( GLI_tdstMaterial *hMaterial, GLI_tdstTexture *p_stTexture ) = OFFSET(0x424A00);


void (*GLI_xSendObjectToViewportWithLights)(
	GLD_tdstViewportAttributes *p_stVpt,
	GEO_tdstGeometricObject *p_stObj,
	long lDrawModeMask
) = OFFSET(0x42AAE0);

void (*GLI_xSendObjectElement)( GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals ) = OFFSET(0x42A990);

void (*GLI_xSerialProjection)( GLI_tdstCamera *p_stCam, long lNbOfVertex, GLI_tdstAligned3DVector *p_stSource, GLI_tdstAligned2DVector *p_stDest ) = OFFSET(0x42C8A0);
