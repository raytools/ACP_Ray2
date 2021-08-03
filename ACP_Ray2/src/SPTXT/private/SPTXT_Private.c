#include "SPTXT_Private.h"
#include <MTH.h>
#include <framework.h>


//////////////////////////////
//
// SPTXT - Private functions
//
//////////////////////////////


#ifdef _DEBUG
DWORD g_ulNbNodes = 0;
DWORD g_ulNbNodesTotal = 0;
DWORD g_ulNbNodesFreed = 0;
#endif


SPTXT_tdstNodeText * SPTXT_fn_p_stAllocNode( SPTXT_tdfnTextCallback p_fnCallback )
{
	SPTXT_tdstNodeText *p_stNode = malloc(sizeof(SPTXT_tdstNodeText));
	if ( p_stNode )
	{
		p_stNode->p_stNext = NULL;
		p_stNode->p_stPrevious = NULL;
		p_stNode->p_fnCallback = p_fnCallback;

#ifdef _DEBUG
		g_ulNbNodes++;
		g_ulNbNodesTotal++;
#endif
	}

	return p_stNode;
}

void SPTXT_fn_vFreeNode( SPTXT_tdstNodeText *p_stNode )
{
	free(p_stNode);

#ifdef _DEBUG
	g_ulNbNodes--;
	g_ulNbNodesFreed++;
#endif
}
