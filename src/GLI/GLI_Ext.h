/****************************************************************************
 *
 * GLI Extensions
 *
 ****************************************************************************/

#pragma once

#include "GLI.h"
#include "basedef.h"
#include "apidef.h"


#define GLI_C_CustomMemoryChannel 8


ACP_API void GLI_fn_vSetForcedColor( unsigned char const *a3_Color );

ACP_API GLI_tdstTexture * GLI_fn_pstFindTexture( char const *szName );
ACP_API BOOL GLI_fn_bReadTextureGF( GLI_tdstTexture *p_stTexture, char const *szGFName );
ACP_API void GLI_fn_vLoadTextureInTable( GLI_tdstTexture *p_stTexture );

ACP_API void GLI_fn_vInitMaterialDefaults( GLI_tdstMaterial *p_stMaterial );

ACP_API void GLI_fn_vDraw2DSpriteWithUV(
	MTH_tdxReal xXMin,
	MTH_tdxReal xXMax,
	MTH_tdxReal xYMin,
	MTH_tdxReal xYMax,
	MTH_tdxReal xUMin,
	MTH_tdxReal xUMax,
	MTH_tdxReal xVMin,
	MTH_tdxReal xVMax,
	GLI_tdstMaterial *hMaterial
);

ACP_API void GLI_fn_vDraw2DSpriteWithZValueAndAlpha(
	MTH2D_tdstVector *p_stTopLeft,
	MTH2D_tdstVector *p_stBottomRight,
	MTH_tdxReal xAlpha,
	MTH_tdxReal xZValue,
	GLI_tdstMaterial *hMaterial
);
