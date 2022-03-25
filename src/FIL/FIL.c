/****************************************************************************
 *
 * FIL - Files and paths management
 *
 ****************************************************************************/

#include "FIL.h"


void * (*FIL_fn_vOpenConcatFile)( char const *szFilePath ) = OFFSET(0x493300);
void (*FIL_fn_vCloseConcatFile)( void **p_hCntFile ) = OFFSET(0x493590);
