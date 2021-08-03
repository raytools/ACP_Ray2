#pragma once

#include "../SPTXT_Def.h"


////////////////////////////////////
//
// Private header for SPTXT module
//
////////////////////////////////////


typedef struct SPTXT_tdstNodeText SPTXT_tdstNodeText;

SPTXT_tdstNodeText * SPTXT_fn_p_stAllocNode( SPTXT_tdfnTextCallback p_fnCallback );
void SPTXT_fn_vFreeNode( SPTXT_tdstNodeText *p_stNode );


struct SPTXT_tdstNodeText
{
	SPTXT_tdstNodeText *p_stNext;
	SPTXT_tdstNodeText *p_stPrevious;
	SPTXT_tdfnTextCallback p_fnCallback;
};
