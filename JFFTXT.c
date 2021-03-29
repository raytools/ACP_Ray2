#include "ACP_API.h"
#include "JFFTXT.h"


////////////////////////////
//
// JFFTXT - 2D Text Module
//
////////////////////////////


ACP_API void (*JFFTXT_vAffiche)( void *pContext ) = 0x465C10;
ACP_API void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstText *p_stText ) = 0x4660B0;
