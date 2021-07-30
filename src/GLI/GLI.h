#pragma once

#include <MTH.h>
#include <apidef.h>


//////////////////////////
//
// GLI - Graphics Module
//
//////////////////////////


ACP_API extern MTH_tdxReal *const GLI_p_fZValueForSprite;
ACP_API extern BYTE *const GLI_p_bForceAAAColor;


ACP_API extern void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, void *pContext );
