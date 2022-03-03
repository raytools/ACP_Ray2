#include "DNM_Ext.h"
#include "DNM.h"
#include "../HIE/HIE.h"


///////////////////
//
// DNM Extensions
//
///////////////////


ACP_API XDNM_tdeDynamicsSize XDNM_fn_eGetDynamicsSize( DNM_tdstDynamics *p_stDynamics )
{
	if ( p_stDynamics )
	{
		DWORD ulEndFlags = p_stDynamics->stDynamicsBase.ulEndFlags;

		if ( (ulEndFlags & 4) != 0 )
		{
			return e_DynamicsSize_Complex;
		}
		if ( (ulEndFlags & 2) != 0 )
		{
			return e_DynamicsSize_Advanced;
		}
		return e_DynamicsSize_Base;
	}

	return e_DynamicsSize_Error;
}

ACP_API XDNM_tdeDynamicsSize XDNM_fn_eGetDynamicsSizeSpo( HIE_tdstSuperObject *p_stSpo )
{
	if ( p_stSpo->ulType == HIE_C_ulActor )
	{
		DNM_tdstDynam *p_stDynam = p_stSpo->hLinkedObject.p_stCharacter->p_stDynam;
		if ( p_stDynam )
		{
			return XDNM_fn_eGetDynamicsSize(p_stDynam->p_stDynamics);
		}
	}

	return e_DynamicsSize_Error;
}
