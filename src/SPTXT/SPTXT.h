#pragma once

#include "SPTXT_Def.h"
#include <MTH.h>
#include <apidef.h>


//////////////////////////////////////////
//
// SPTXT - Spitfire's Text Helper Module
//
//////////////////////////////////////////


ACP_API void SPTXT_vInit( void );
ACP_API void SPTXT_vDeInit( void );

ACP_API void SPTXT_vAddTextCallback( SPTXT_tdfnTextCallback p_fnCallback );
ACP_API void SPTXT_vRemoveTextCallback( SPTXT_tdfnTextCallback p_fnCallback );

ACP_API void SPTXT_vPrint( char *szText );
ACP_API void SPTXT_vNewLine( void );
ACP_API void SPTXT_vPrintLine( char *szText );
ACP_API void SPTXT_vPrintFmtLine( char const *szFmt, ... );
ACP_API void SPTXT_vResetTextInfo( SPTXT_tdstTextInfo *p_stInfo );


struct SPTXT_tdstTextInfo
{
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	BYTE ucAlpha;
	BYTE bFrame;
	BYTE bRightAlign;
	BYTE bSelected;
};
