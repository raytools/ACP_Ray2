#pragma once

#include <apidef.h>


//////////////////////////////////////
//
// Type definitions for SPTXT module
//
//////////////////////////////////////


#define TXT_Color_Reset "/o0:"
#define TXT_Color_Red "/o200:"
#define TXT_Color_Yellow "/o400:"

#define TXT_Red(str) TXT_Color_Red str TXT_Color_Reset
#define TXT_Yellow(str) TXT_Color_Yellow str TXT_Color_Reset


typedef struct SPTXT_tdstTextInfo SPTXT_tdstTextInfo;
typedef void (CALLBACK *SPTXT_tdfnTextCallback)( SPTXT_tdstTextInfo *p_stString );
