/****************************************************************************
*
* COL - Collision module
*
****************************************************************************/

#include "COL.h"
#include <GAM/GAM_Def.h>
#include <HIE/HIE_Def.h>

/*
 * Variables
 */

COL_tdstCollisionCase* const COL_g_stCollisionCase = OFFSET(0x4F8C40); // Array with the size of COL_C_xMaxNumberOfCollisions
COL_tdstCollisionCase** const COL_g_stCollisionCaseReal = OFFSET(0x4A680C); // Usually points to the start of COL_g_stCollisionCase
long* const COL_g_lNbElementsInTable = OFFSET(0x4a6974);

/*
 * Functions
 */
ZDX_tdstCollSet* (*COL_fn_vCollSetAlloc) (HIE_tdstEngineObject* engineObject) = OFFSET(0x417460);
ZDX_tdstCollSet* (*COL_fn_vCollSetCopyClone) (HIE_tdstEngineObject* p_stObjectDest, HIE_tdstEngineObject* p_stObjectSrc) = OFFSET(0x417710);