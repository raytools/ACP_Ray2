/****************************************************************************
 *
 * FIL - Files and paths management
 *
 ****************************************************************************/

#pragma once

#include "LST.h"
#include "apidef.h"


typedef struct FIL_tdstFileNameListElement FIL_tdstFileNameListElement;
LST_M_DynamicListDecl(FIL_tdstFileNameListElement);

typedef struct FIL_tdstFileNameListElement
{
	LST_M_DynamicElementDecl(FIL_tdstFileNameListElement)
	char *szFileName;
}
FIL_tdstFileNameListElement;

typedef struct FIL_tdstRealGFFileHeader
{
    unsigned long ulFormat;
    unsigned long ulWidth;
    unsigned long ulHeight;
    unsigned char ucBpp;
    unsigned char ucRLECode;
}
FIL_tdstRealGFFileHeader;


/*
 * Functions
 */

ACP_FUNC void * (*FIL_fn_vOpenConcatFile)( char const *szFilePath );
ACP_FUNC void (*FIL_fn_vCloseConcatFile)( void **p_hCntFile );
