/****************************************************************************
 *
 * ALW - Always object module
 *
 ****************************************************************************/

#pragma once

#include "HIE/HIE.h"
#include "LST.h"
#include "basedef.h"
#include "apidef.h"


typedef struct ALW_tdstAlways ALW_tdstAlways;
typedef struct ALW_tdstAlwaysModelList ALW_tdstAlwaysModelList;

LST_M_DynamicListDecl(ALW_tdstAlwaysModelList);

typedef struct ALW_tdstAlwaysModelList
{
	LST_M_DynamicElementDecl(ALW_tdstAlwaysModelList)

	long lObjectModelType;
	HIE_tdstEngineObject *p_stAlwaysObject;
}
ALW_tdstAlwaysModelList;

typedef struct ALW_tdstAlways
{
	unsigned long ulMaxNbOfAlways;
	LST_M_DynamicAnchorTo(ALW_tdstAlwaysModelList) hLstAlwaysModel;

	HIE_tdstSuperObject *p_stAlwaysSuperObject; /* Contains all generated always objects */
	HIE_tdstEngineObject *p_stAlwaysEngineObjectInit;
	HIE_tdstSuperObject **a_stAlwaysGenerator; /* List of generators */
}
ALW_tdstAlways;


/*
 * Variables
 */

ACP_VAR ALW_tdstAlways *const ALW_g_stAlways;

/*
 * Functions
 */

ACP_FUNC HIE_tdstSuperObject* (*ALW_fn_p_stAllocateAlways) (long otObjectModelType,
	HIE_tdstSuperObject *p_stFatherSuperObject,
	HIE_tdstSuperObject *_hGenerator,
	unsigned short uwAction,
	POS_tdstCompletePosition *p_stMatrix);