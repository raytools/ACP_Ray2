#pragma once

#include "../SPTXT_Def.h"
#include "../../LST.h"


////////////////////////////////////
//
// Private header for SPTXT module
//
////////////////////////////////////


typedef struct SPTXT_tdstNodeText SPTXT_tdstNodeText;

extern LST_M_AnchorTo(SPTXT_tdstNodeText) g_stTextNodeList;

SPTXT_tdstNodeText * SPTXT_fn_p_stCreateNode( void );
void SPTXT_fn_vDeleteNode( SPTXT_tdstNodeText *p_stNode );


struct SPTXT_tdstNodeText
{
	LST_M_DynamicElementDecl(SPTXT_tdstNodeText)
	SPTXT_tdfnTextCallback p_fnCallback;
};

LST_M_DynamicListDecl(SPTXT_tdstNodeText);
