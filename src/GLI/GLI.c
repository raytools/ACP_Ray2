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

long* const g_lNbMatrixInStack = OFFSET(0x4b98d4);
POS_tdstCompletePosition** const g_aDEF_stMatrixStack = OFFSET(0x51607c);


/* Big Globals */
GLI_tdstInternalGlobalValuesFor3dEngine **const GLI_BIG_GLOBALS = OFFSET(0x5036AC);

POS_tdstCompletePosition** const g_p_stCurrentMatrix = OFFSET(0x506B00);

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


void (**GLI_DRV_vSendSingleLineToClip)(GLD_tdstViewportAttributes*,
	GLI_tdstAligned3DVector*,
	GLI_tdstAligned2DVector*,
	GLI_tdstAligned3DVector*,
	GLI_tdstAligned2DVector*,
	GLI_tdstInternalGlobalValuesFor3dEngine*,
	long,
	GEO_tdstColor*)
= OFFSET(0x504834);

void (**GLI_DRV_vSendSingleTrianglesToClip)(GLI_tdstAligned2DVector*,
	GLI_tdst2DUVValues* a3_stUV,
	GLI_tdstInternalGlobalValuesFor3dEngine* p_stGlobaleMT)
	= OFFSET(0x504828);

void (*GLI_xGetCameraMatrix)(GLI_tdstCamera *p_stCam, POS_tdstCompletePosition *p_stMatrix) = OFFSET(0x422620);

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

void (*GLI_xSerialProjection)(struct GLI_tdstCamera_* p_stCam, long lNbOfVertex, struct GLI_tdstAligned3DVector_* p_stSource, struct GLI_tdstAligned2DVector_* p_stDest
) = OFFSET(0x42C8A0);