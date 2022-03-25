/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/

#include "GAM.h"


/* Engine structure */
GAM_tdstEngineStructure *const GAM_g_stEngineStructure = OFFSET(0x500380);

HIE_tdstSuperObject **const GAM_pp_stDynamicWorld = OFFSET(0x0500FD0);
HIE_tdstSuperObject **const GAM_pp_stInactiveDynamicWorld = OFFSET(0x500FC4);
HIE_tdstSuperObject **const GAM_pp_stFatherSector = OFFSET(0x500FC0);


GAM_tdeEngineMode (*GAM_fn_ucGetEngineMode)( void ) = OFFSET(0x404C60);
void (*GAM_fn_vChangeEngineMode)( GAM_tdeEngineMode ucMode ) = OFFSET(0x404BF0);
char * (*GAM_fn_p_szGetLevelName)( void ) = OFFSET(0x404DA0);
void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, ACP_tdxBool bSaveGame ) = OFFSET(0x4054D0);
void * (*GAM_fn_hGetWindowHandle)( void ) = OFFSET(0x401400);
