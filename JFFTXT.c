#include "ACP_API.h"
#include "JFFTXT.h"


////////////////////////////
//
// JFFTXT - 2D Text Module
//
////////////////////////////


ACP_API void (*JFFTXT_vAffiche)( void *pContext ) = 0x465C10;
ACP_API void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstText *p_stText ) = 0x4660B0;

ACP_API void (*JFFTXT_vAddText)( DWORD ulTextId, MTH_tdstVector *p_stPos, char *szText, float xAlpha ) = 0x465A50;
ACP_API void (*JFFTXT_vExtendText)( DWORD ulTextId, JFFTXT_tdeExtendParam ulValueToChange, float xNewValue ) = 0x465AA0;
