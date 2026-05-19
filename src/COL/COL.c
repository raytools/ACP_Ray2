/****************************************************************************
*
* COL - Collision module
*
****************************************************************************/

#include "COL.h"
#include <GAM/GAM_Def.h>
#include <HIE/HIE_Def.h>
#include <POS/POS_Def.h>

/*
 * Variables
 */

COL_tdstCollisionCase* const COL_g_stCollisionCase = OFFSET(0x4F8C40); // Array with the size of COL_C_xMaxNumberOfCollisions
COL_tdstCollisionCase** const COL_g_stCollisionCaseReal = OFFSET(0x4A680C); // Usually points to the start of COL_g_stCollisionCase
long* const COL_g_lNbElementsInTable = OFFSET(0x4a6810);

/*
 * Functions
 */
ZDX_tdstCollSet* (*COL_fn_vCollSetAlloc) (HIE_tdstEngineObject* engineObject) = OFFSET(0x417460);
ZDX_tdstCollSet* (*COL_fn_vCollSetCopyClone) (HIE_tdstEngineObject* p_stObjectDest, HIE_tdstEngineObject* p_stObjectSrc) = OFFSET(0x417710);

ACP_tdxBool (*INT_fn_bDetectIntersectSegmentWithTriangle)(MTH3D_tdstVector* p_stVertexA,
  MTH3D_tdstVector* p_stVectAB,
  MTH3D_tdstVector* p_stVertex1,
  MTH3D_tdstVector* p_stVertex2,
  MTH3D_tdstVector* p_stVertex3,
  MTH3D_tdstVector* p_stNormal,
  MTH_tdxReal xDPlan) = OFFSET(0x4914d0);

void (*COL_fn_vNewStaticCollisionForCharacter)(HIE_tdstSuperObject* _hCharacter,
  HIE_tdstSuperObject* _hSector,
  POS_tdstCompletePosition* _p_stStartMatrix,
  POS_tdstCompletePosition* _p_stEndMatrix) = OFFSET(0x494610);