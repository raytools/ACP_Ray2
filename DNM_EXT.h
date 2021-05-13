#pragma once
#include "apidef.h"
#include "MTH.h"
#include "DNM.h"
#include "HIE.h"


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
