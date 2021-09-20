#pragma once

#include "../apidef.h"


/////////////////////////////////////
//
// FIL - Files and paths management
//
/////////////////////////////////////


typedef struct FIL_tdstFileNameList FIL_tdstFileNameList;
typedef struct FIL_tdstFileNameListElement FIL_tdstFileNameListElement;


ACP_API extern void * (*FIL_fn_vOpenConcatFile)( char const *szFilePath );
ACP_API extern void (*FIL_fn_vCloseConcatFile)( void **p_hCntFile );


struct FIL_tdstFileNameList
{
	FIL_tdstFileNameListElement *hFirstElementDyn;
	FIL_tdstFileNameListElement *hLastElementDyn;
	int lNumberOfElementsDyn;
};

struct FIL_tdstFileNameListElement
{
	FIL_tdstFileNameListElement *hNextBrotherDyn;
	FIL_tdstFileNameListElement *hPrevBrotherDyn;
	FIL_tdstFileNameList *hFatherDyn;
	char *szFileName;
};
