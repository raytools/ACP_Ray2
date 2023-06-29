/****************************************************************************
 *
 * Private header for SPTXT module
 *
 ****************************************************************************/


#pragma once

#include "../SPTXT.h"
#include "LST.h"


typedef struct SPTXT_tdstNodeText SPTXT_tdstNodeText;
LST_M_DynamicListDecl(SPTXT_tdstNodeText);

typedef struct SPTXT_tdstNodeText
{
	LST_M_DynamicElementDecl(SPTXT_tdstNodeText)
	SPTXT_tdfnTextCallback p_fnCallback;
}
SPTXT_tdstNodeText;


/*
 * Variables
 */

extern LST_M_DynamicAnchorTo(SPTXT_tdstNodeText) g_stTextNodeList;

SPTXT_tdstNodeText * SPTXT_fn_p_stCreateNode( void );
void SPTXT_fn_vDeleteNode( SPTXT_tdstNodeText *p_stNode );
