/****************************************************************************
 *
 * GLI - Graphics module
 *
 ****************************************************************************/

#include "GLI.h"


MTH_tdxReal *const GLI_p_fZValueForSprite = OFFSET(0x4A07D4);
unsigned char *const GLI_p_bForceAAAColor = OFFSET(0x4A72AC);

void **const GLI_g_hConcatTexturesFile = OFFSET(0x4A7280);
void **const GLI_gs_p_ConvertBufferMipMapping = OFFSET(0x503D50);

unsigned long *const GLI_g_ulNumberOfLoadedTexture = OFFSET(0x502660);
GLI_tdstTexture **const GLI_gs_aDEFTableOfTextureAlreadyRead = OFFSET(0x502680);
unsigned long *const GLI_gs_aDEFTableOfTextureMemoryChannels = OFFSET(0x501660);


void (*GLI_vSetGlobalAlpha)( MTH_tdxReal xAlpha ) = OFFSET(0x42A300);
MTH_tdxReal (*GLI_fn_xGetGlobalAlpha)( void ) = OFFSET(0x42A360);

void (*GLI_vDraw2DSpriteWithPercent)(
	GLD_tdstViewportAttributes *p_stViewport,
	MTH_tdxReal XMin,
	MTH_tdxReal YMin,
	MTH_tdxReal XMax,
	MTH_tdxReal YMax,
	void *hMaterial
) = OFFSET(0x429670);

void (*GLI_vDisplayFrame)(
	MTH2D_tdstVector *p_stTopLeft,
	MTH2D_tdstVector *p_stBottomRight,
	MTH_tdxReal xAlpha,
	GLD_tdstViewportAttributes *p_stViewport
) = OFFSET(0x429820);

void (*GLI_xLoadTextureInTexelField)( GLI_tdstTexture *p_stTexture, void *pBuffer, BOOL bHideProgress )
	= OFFSET(0x426550);

char * (*GLI_fn_szGetPathOfTexture)( void ) = OFFSET(0x42D1B0);
void (*GLI_vComputeTextures)( void ) = OFFSET(0x426980);
void (*GLI_vReloadTextures)( void ) = OFFSET(0x426A40);
