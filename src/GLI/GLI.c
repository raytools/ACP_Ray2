#include "GLI.h"


//////////////////////////
//
// GLI - Graphics Module
// 
//////////////////////////


ACP_API MTH_tdxReal *const GLI_p_fZValueForSprite = 0x4A07D4;
ACP_API BYTE *const GLI_p_bForceAAAColor = 0x4A72AC;


ACP_API void (*GLI_vDisplayFrame)( MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight, MTH_tdxReal xAlpha, void *pContext ) = 0x429820;
