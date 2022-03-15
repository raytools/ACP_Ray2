#include "GAM.h"


///////////////////////
//
// GAM - Game Library
// 
///////////////////////


// Engine structure
ACP_API GAM_tdstEngineStructure *const GAM_g_stEngineStructure = (GAM_tdstEngineStructure *)0x500380;

ACP_API HIE_tdstSuperObject **const GAM_pp_stDynamicWorld = (HIE_tdstSuperObject **)0x0500FD0;
ACP_API HIE_tdstSuperObject **const GAM_pp_stInactiveDynamicWorld = (HIE_tdstSuperObject **)0x500FC4;
ACP_API HIE_tdstSuperObject **const GAM_pp_stFatherSector = (HIE_tdstSuperObject **)0x500FC0;


ACP_API BYTE (*GAM_fn_ucGetEngineMode)( void ) = 0x404C60;
ACP_API void (*GAM_fn_vChangeEngineMode)( BYTE ucMode ) = 0x404BF0;
ACP_API char * (*GAM_fn_p_szGetLevelName)( void ) = 0x404DA0;
ACP_API void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, BYTE bSaveGame ) = 0x4054D0;
ACP_API HANDLE (*GAM_fn_hGetWindowHandle)( void ) = 0x401400;
