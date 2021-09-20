#include "FIL.h"


/////////////////////////////////////
//
// FIL - Files and paths management
//
/////////////////////////////////////


ACP_API void * (*FIL_fn_vOpenConcatFile)( char const *szFilePath ) = 0x493300;
ACP_API void (*FIL_fn_vCloseConcatFile)( void **p_hCntFile ) = 0x493590;
