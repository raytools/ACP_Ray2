#pragma once
#include "ACP_API.h"
#include "MTH.h"


////////////////////////////
//
// JFFTXT - 2D Text Module
//
////////////////////////////

typedef struct JFFTXT_tdstText JFFTXT_tdstText;

struct JFFTXT_tdstText
{
	char *szText;
	float X;
	float Y;
	float xSize;
	BYTE ubAlpha;

	BYTE _field_11;
	BYTE ubHighlight;
	BYTE ubOptions;
	DWORD _field_14;
	BYTE ubHighlightColor;
};

ACP_API extern void (*JFFTXT_vAffiche)( void *pContext );
ACP_API extern void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstText *p_stText );
