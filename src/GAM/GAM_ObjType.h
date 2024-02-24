/****************************************************************************
 * GAM / Std - object type
 ****************************************************************************/

#pragma once

#include "GAM_Def.h"
#include "LST.h"
#include "basedef.h"
#include "apidef.h"


#define GAM_C_InvalidObjectType		(-1)
#define GAM_C_AlwaysObjectType		0x00010000

typedef long GAM_tdxObjectType;


typedef struct GAM_tdstObjectTypeElement
{
	LST_M_DynamicElementDecl(GAM_tdstObjectTypeElement)
	char *szName;
	unsigned char ucElementPriority;
}
GAM_tdstObjectTypeElement;

LST_M_DynamicListDecl(GAM_tdstObjectTypeElement);

typedef struct GAM_tdstObjectType
{
	LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) stFamilyType;
	LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) stModelType;
	LST_M_DynamicAnchorTo(GAM_tdstObjectTypeElement) stPersonalType;
}
GAM_tdstObjectType;


ACP_VAR GAM_tdstObjectType *const GAM_g_stObjectTypes;
