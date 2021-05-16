#include "JFFTXT.h"
#include <apidef.h>


////////////////////////////
//
// JFFTXT - 2D Text Module
//
////////////////////////////


ACP_API void (*JFFTXT_vAffiche)( void *pContext ) = 0x465C10;
ACP_API void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstString *p_stString ) = 0x4660B0;

ACP_API void (*JFFTXT_vAddText)( DWORD ulTextId, MTH3D_tdstVector *p_stPos, char *szText, float xAlpha ) = 0x465A50;
ACP_API void (*JFFTXT_vExtendText)( DWORD ulTextId, JFFTXT_tdeExtendParam ulParamToChange, float xNewValue ) = 0x465AA0;
