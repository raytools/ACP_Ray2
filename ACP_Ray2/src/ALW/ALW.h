#pragma once

#include "../HIE/HIE.h"
#include "../LST.h"
#include "../basedef.h"
#include "../apidef.h"


/****************************************************************************
 *
 * ALW - Always object module
 *
 ****************************************************************************/


typedef struct ALW_tdstAlways ALW_tdstAlways;
typedef struct ALW_tdstAlwaysModelList ALW_tdstAlwaysModelList;


ACP_API extern ALW_tdstAlways *const ALW_g_stAlways;


struct ALW_tdstAlwaysModelList
{
	LST_M_DynamicElementDecl(ALW_tdstAlwaysModelList)

	int lObjectModelType;
	HIE_tdstEngineObject *p_stAlwaysObject;
};

LST_M_DynamicListDecl(ALW_tdstAlwaysModelList);

struct ALW_tdstAlways
{
	DWORD ulMaxNbOfAlways;
	LST_M_AnchorTo(ALW_tdstAlwaysModelList) hLstAlwaysModel;

	HIE_tdstSuperObject *p_stAlwaysSuperObject; /* Contains all generated always objects */
	HIE_tdstEngineObject *p_stAlwaysEngineObjectInit;
	HIE_tdstSuperObject **a_stAlwaysGenerator; /* List of generators */
};