/****************************************************************************
 *
 * MEC - Mechanics module
 *
 ****************************************************************************/

#include "MEC.h"


void (*MEC_vInitTranslation)(
	DNM_tdstDynamics *p_stDynamic,
	HIE_tdstSuperObject *hSupObj,
	MTH3D_tdstVector *p_stVector
) = OFFSET(0x432DA0);

DNM_tdstMecReport* const MEC_g_stReport = OFFSET(0x050a9a0);