#pragma once

#include "../apidef.h"


//////////////////////////////////////
//
// Type definitions for SPTXT module
//
//////////////////////////////////////


#define TXT_Seq_Reset "/o0:"
#define TXT_Seq_Red "/o200:"
#define TXT_Seq_Yellow "/o400:"
#define TXT_Seq_Center "/c:"

#define TXT_Red(str) TXT_Seq_Red str TXT_Seq_Reset
#define TXT_Yellow(str) TXT_Seq_Yellow str TXT_Seq_Reset
#define TXT_Center(str) TXT_Seq_Center str


typedef struct SPTXT_tdstTextInfo SPTXT_tdstTextInfo;
typedef void (CALLBACK *SPTXT_tdfnTextCallback)( SPTXT_tdstTextInfo *p_stString );
