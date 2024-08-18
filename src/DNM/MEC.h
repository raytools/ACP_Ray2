/****************************************************************************
 *
 * MEC - Mechanics module
 *
 ****************************************************************************/

#pragma once

#include "DNM_Def.h"

#include "HIE/HIE_Def.h"
#include "MTH.h"
#include "apidef.h"


ACP_FUNC void (*MEC_vInitTranslation)( DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH3D_tdstVector *p_stVector );
