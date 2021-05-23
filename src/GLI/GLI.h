#pragma once

#include <MTH.h>
#include <apidef.h>


//////////////////////////
//
// GLI - Graphics Module
// 
//////////////////////////


ACP_API extern void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, void *pContext );
