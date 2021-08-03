#pragma once

#include "../apidef.h"


/////////////////////////////////////
//
// FIL - Files and paths management
//
/////////////////////////////////////


typedef struct FIL_tdstFileNameList FIL_tdstFileNameList;
typedef struct FIL_tdstFileNameListElement FIL_tdstFileNameListElement;


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
