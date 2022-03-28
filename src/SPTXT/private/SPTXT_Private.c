/****************************************************************************
 *
 * Private functions for SPTXT module
 *
 ****************************************************************************/

#include "SPTXT_Private.h"
#include "MTH.h"
#include "LST.h"
#include "private/framework.h"


#ifdef _DEBUG
DWORD g_ulNbNodes = 0;
DWORD g_ulNbNodesTotal = 0;
DWORD g_ulNbNodesFreed = 0;
#endif

LST_M_DynamicAnchorTo(SPTXT_tdstNodeText) g_stTextNodeList;


SPTXT_tdstNodeText * SPTXT_fn_p_stCreateNode( void )
{
	SPTXT_tdstNodeText *p_stNode = malloc(sizeof(SPTXT_tdstNodeText));
	if ( p_stNode )
	{
		LST_M_DynamicInitElement(p_stNode);
		LST_M_DynamicAddTail(&g_stTextNodeList, p_stNode);

#ifdef _DEBUG
		g_ulNbNodes++;
		g_ulNbNodesTotal++;
#endif
	}
	return p_stNode;
}

void SPTXT_fn_vDeleteNode( SPTXT_tdstNodeText *p_stNode )
{
	LST_M_DynamicIsolate(p_stNode);
	free(p_stNode);

#ifdef _DEBUG
	g_ulNbNodes--;
	g_ulNbNodesFreed++;
#endif
}
