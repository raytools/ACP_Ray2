/****************************************************************************
 *
 * HIE - Object Hierarchy
 *
 ****************************************************************************/

#include "HIE.h"
#include "HIE_StdGame.h"
#include "HIE_Family.h"


/****************************************************************************
 * HIE.h
 ****************************************************************************/

int *const HIE_gs_lCurrentFrame = OFFSET(0x514EA0);

void (*HIE_fn_vChangeFather)(HIE_tdstSuperObject *p_stSpo, HIE_tdstSuperObject *p_stNewFather, unsigned char bFirstChild) = OFFSET(0x45C080);


/****************************************************************************
 * HIE_StdGame.h
 ****************************************************************************/

HIE_tdstObjectType *const HIE_g_stObjectTypes = OFFSET(0x5013E0);
