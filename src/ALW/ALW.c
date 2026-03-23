/****************************************************************************
 *
 * ALW - Always object module
 *
 ****************************************************************************/

#include "ALW.h"


ALW_tdstAlways *const ALW_g_stAlways = OFFSET(0x004A6B18);
/*
 * Functions
 */

HIE_tdstSuperObject* (*ALW_fn_p_stAllocateAlways) (long otObjectModelType,
	HIE_tdstSuperObject* p_stFatherSuperObject,
	HIE_tdstSuperObject* _hGenerator,
	unsigned short uwAction,
	POS_tdstCompletePosition* p_stMatrix) = OFFSET(0x40BCC0);