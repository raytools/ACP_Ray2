#pragma once

#include "../LST.h"
#include "../apidef.h"


/****************************************************************************
 *
 * FIL - Files and paths management
 *
 ****************************************************************************/


ACP_API extern void * (*FIL_fn_vOpenConcatFile)( char const *szFilePath );
ACP_API extern void (*FIL_fn_vCloseConcatFile)( void **p_hCntFile );


typedef struct FIL_tdstFileNameListElement FIL_tdstFileNameListElement;
struct FIL_tdstFileNameListElement
{
	LST_M_DynamicElementDecl(FIL_tdstFileNameListElement)
	char *szFileName;
};

LST_M_DynamicListDecl(FIL_tdstFileNameListElement);

typedef struct FIL_tdstRealGFFileHeader
{
    DWORD ulFormat;
    DWORD ulWidth;
    DWORD ulHeight;
    BYTE ucBpp;
    BYTE ucRLECode;
}
FIL_tdstRealGFFileHeader;
