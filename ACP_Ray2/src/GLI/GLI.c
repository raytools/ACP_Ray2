#include "GLI.h"


/****************************************************************************
 *
 * GLI - Graphics module
 *
 ****************************************************************************/


ACP_API MTH_tdxReal *const GLI_p_fZValueForSprite = 0x4A07D4;
ACP_API BYTE *const GLI_p_bForceAAAColor = 0x4A72AC;

ACP_API void **const GLI_g_hConcatTexturesFile = 0x4A7280;
ACP_API void **const GLI_gs_p_ConvertBufferMipMapping = 0x503D50;

ACP_API DWORD *const GLI_g_ulNumberOfLoadedTexture = 0x502660;
ACP_API GLI_tdstTexture **const GLI_gs_aDEFTableOfTextureAlreadyRead = 0x502680;
ACP_API DWORD *const GLI_gs_aDEFTableOfTextureMemoryChannels = 0x501660;


ACP_API void (*GLI_vSetGlobalAlpha)( MTH_tdxReal xAlpha ) = 0x42A300;
ACP_API MTH_tdxReal (*GLI_fn_xGetGlobalAlpha)( void ) = 0x42A360;

ACP_API void (*GLI_vDraw2DSpriteWithPercent)( GLD_tdstViewportAttributes *p_stViewport, MTH_tdxReal XMin, MTH_tdxReal YMin, MTH_tdxReal XMax, MTH_tdxReal YMax, void *hMaterial ) = 0x429670;
ACP_API void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, GLD_tdstViewportAttributes *p_stViewport ) = 0x429820;

ACP_API void (*GLI_xLoadTextureInTexelField)( GLI_tdstTexture *p_stTexture, void *pBuffer, BOOL bHideProgress ) = 0x426550;
ACP_API char * (*GLI_fn_szGetPathOfTexture)( void ) = 0x42D1B0;
ACP_API void (*GLI_vComputeTextures)( void ) = 0x426980;
ACP_API void (*GLI_vReloadTextures)( void ) = 0x426A40;
