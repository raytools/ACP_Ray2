#pragma once

#include "DNM_Def.h"
#include "../HIE/HIE_Def.h"
#include "../apidef.h"


///////////////////
//
// DNM Extensions
//
///////////////////


typedef enum XDNM_tdeDynamicsSize
{
	e_DynamicsSize_Base = 0,
	e_DynamicsSize_Advanced = 1,
	e_DynamicsSize_Complex = 2,
	e_DynamicsSize_Error = -1
} XDNM_tdeDynamicsSize;

ACP_API XDNM_tdeDynamicsSize XDNM_fn_eGetDynamicsSize( DNM_tdstDynamics *p_stDynamics );
ACP_API XDNM_tdeDynamicsSize XDNM_fn_eGetDynamicsSizeSpo( HIE_tdstSuperObject *p_stSpo );