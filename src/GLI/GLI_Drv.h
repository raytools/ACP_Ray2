/****************************************************************************
 * GLI - driver DLL functions
 ****************************************************************************/

#pragma once

#include "GLI_Const.h"
#include "GLI_Def.h"
#include "GLI_Misc.h"
#include "GLD.h"

#include "basedef.h"
#include "apidef.h"


ACP_FUNC void (**GLI_DRV_vSendSpriteToClip_)( GLI_tdstAligned2DVector *a4_st2DVertex ,MTH_tdxReal xZ, GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );
ACP_FUNC void (**GLI_DRV_vSendSpriteToClipWithUV_)( GLI_tdstAligned2DVector *a4_st2DVertex, MTH_tdxReal *a8_stUVVertex, MTH_tdxReal xZ, GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals );
ACP_FUNC void (**GLI_DRV_vSendSingleLineToClip_)( GLD_tdstViewportAttributes *p_stVpt,
	GLI_tdstAligned3DVector *p_stVertex1, GLI_tdstAligned2DVector *p_st2DVertex1, GLI_tdstAligned3DVector *p_stVertex2, GLI_tdstAligned2DVector *p_st2DVertex2,
	GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobals, long lDrawModeMask, GEO_tdstColor *p_stColor );

ACP_FUNC void (**GLI_DRV_vSendSingleTrianglesToClip_)( GLI_tdstAligned2DVector *a3_st2DVertex, GLI_tdst2DUVValues *a3_stUV, GLI_tdstInternalGlobalValuesFor3dEngine *p_stGlobaleMT );
ACP_FUNC void (**GLI_DRV_vFlipDeviceWithSyncro)(void);
ACP_FUNC void (**GLI_DRV_vReadaptDisplay)(void);