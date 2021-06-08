#pragma once

#include <MTH.h>
#include <apidef.h>


//////////////////////////////////////////
//
// SPTXT - Spitfire's Text Helper Module
//
//////////////////////////////////////////


typedef struct SPTXT_tdstString SPTXT_tdstString;
typedef struct SPTXT_tdstDynamicString SPTXT_tdstDynamicString;

typedef void (CALLBACK *SPTXT_tdfnDynamicStringCallback)( SPTXT_tdstString *p_stString );


ACP_API void SPTXT_vInit( void );
ACP_API void SPTXT_vDeInit( void );


struct SPTXT_tdstString
{
	char *szText;
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	BYTE ucAlpha;
	BYTE bFrame;
	BYTE bRightAlign;
};

struct SPTXT_tdstDynamicString
{
	SPTXT_tdstString stString;
	SPTXT_tdfnDynamicStringCallback p_fnCallback;
};
