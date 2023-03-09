/****************************************************************************
 *
 * DNM Extensions
 *
 ****************************************************************************/

#pragma once

#include "DNM.h"
#include "basedef.h"
#include "apidef.h"


#define DNM_M_p_stGetBaseBlock( p_stDynamics ) (&((p_stDynamics)->stDynamicsBase))
#define DNM_M_p_stGetAdvancedBlock( p_stDynamics ) (&((p_stDynamics)->stDynamicsAdvanced))
#define DNM_M_p_stGetComplexBlock( p_stDynamics ) (&((p_stDynamics)->stDynamicsComplex))

#define DNM_M_bDynamicsIsBaseSize( p_stDynamics ) (DNM_M_p_stGetBaseBlock(p_stDynamics)->ulEndFlags & DNM_C_EndFlag_BaseSize ? TRUE : FALSE)
#define DNM_M_bDynamicsIsAdvancedSize( p_stDynamics ) (DNM_M_p_stGetBaseBlock(p_stDynamics)->ulEndFlags & DNM_C_EndFlag_AdvancedSize ? TRUE : FALSE)
#define DNM_M_bDynamicsIsComplexSize( p_stDynamics ) (DNM_M_p_stGetBaseBlock(p_stDynamics)->ulEndFlags & DNM_C_EndFlag_ComplexSize ? TRUE : FALSE)
