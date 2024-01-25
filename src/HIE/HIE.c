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

void (*HIE_fn_vInitMatrixStack)( void ) = OFFSET(0x45B760);
ACP_tdxBool (*HIE_fn_bInitCameraMatrixStack)( GLD_tdstViewportAttributes *hVpt ) = OFFSET(0x45B850);
ACP_tdxBool (*HIE_fn_bStoreMatrix)( POS_tdstCompletePosition *hMatrix ) = OFFSET(0x45B810);
void (*HIE_fn_vPushMatrix)( HIE_tdstSuperObject *hSprObj ) = OFFSET(0x45BF80);
ACP_tdxBool (*HIE_fn_bPopMatrix)( void ) = OFFSET(0x45B7E0);



/****************************************************************************
 * HIE_StdGame.h
 ****************************************************************************/

HIE_tdstObjectType *const HIE_g_stObjectTypes = OFFSET(0x5013E0);
