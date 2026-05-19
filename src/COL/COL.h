#pragma once
#include "COL_Def.h"
#include "HIE/HIE_Def.h"
#include "GAM/GAM_Def.h"
#include "POS/POS_Def.h"

#include "MTH.h"
#include "GMT/GMT.h"
#include "apidef.h"

#define COL_C_xMaxNumberOfCollisions 75

typedef struct COL_tdstCollisionCase
{
  MTH_tdxReal xCollisionTime;
  MTH3D_tdstVector stCollisionNormal;
  MTH3D_tdstVector stCollisionPoint;

  GMT_tdstGameMaterial* hDynamicMaterial;
  GMT_tdstGameMaterial* hStaticMaterial;

  void *p_vParameter1;
  long sParameter2;

  ACP_tdxIndex xDynamicGeomEntity;
  ACP_tdxIndex xStaticGeomEntity;

  MTH3D_tdstVector stTranslation;
  MTH3D_tdstVector stMovement;
  MTH3D_tdstVector stEndPosition;

  MTH_tdxReal xSphereRadius;

  MTH_tdxReal m_xSlide1;
  MTH_tdxReal m_xRebound1;

  MTH_tdxReal m_xSlide2;
  MTH_tdxReal m_xRebound2;
}
COL_tdstCollisionCase;

/*
 * Variables
 */

ACP_VAR COL_tdstCollisionCase *const COL_g_stCollisionCase;
ACP_VAR COL_tdstCollisionCase **const COL_g_stCollisionCaseReal;
ACP_VAR long *const COL_g_lNbElementsInTable;

/*
 * Functions
 */ 

ACP_FUNC ZDX_tdstCollSet *(*COL_fn_vCollSetAlloc) (HIE_tdstEngineObject *engineObject);
ACP_FUNC ZDX_tdstCollSet *(*COL_fn_vCollSetCopyClone) (HIE_tdstEngineObject *p_stObjectDest, HIE_tdstEngineObject *p_stObjectSrc);

ACP_FUNC ACP_tdxBool(*INT_fn_bDetectIntersectSegmentWithTriangle)(MTH3D_tdstVector *p_stVertexA,
  MTH3D_tdstVector *p_stVectAB,
  MTH3D_tdstVector *p_stVertex1,
  MTH3D_tdstVector *p_stVertex2,
  MTH3D_tdstVector *p_stVertex3,
  MTH3D_tdstVector *p_stNormal,
  MTH_tdxReal xDPlan);

ACP_FUNC void (*COL_fn_vNewStaticCollisionForCharacter)(HIE_tdstSuperObject *_hCharacter,
  HIE_tdstSuperObject *_hSector,
  POS_tdstCompletePosition *_p_stStartMatrix,
  POS_tdstCompletePosition *_p_stEndMatrix);