#pragma once
#include "COL_Def.h"

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