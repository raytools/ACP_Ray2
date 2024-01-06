/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/

#include "GAM.h"


/* Engine structure */
GAM_tdstEngineStructure *const GAM_g_stEngineStructure = OFFSET(0x500380);
char const *const GAM_g_szCmdLine = OFFSET(0x4E0DA0);

HIE_tdstSuperObject **const GAM_g_p_stDynamicWorld = OFFSET(0x0500FD0);
HIE_tdstSuperObject **const GAM_g_p_stInactiveDynamicWorld = OFFSET(0x500FC4);
HIE_tdstSuperObject **const GAM_g_p_stFatherSector = OFFSET(0x500FC0);


GAM_tdeEngineMode (*GAM_fn_ucGetEngineMode)( void ) = OFFSET(0x404C60);
void (*GAM_fn_vChangeEngineMode)( GAM_tdeEngineMode ucMode ) = OFFSET(0x404BF0);

void (*GAM_fn_vInitEngineWhenInitApplication)( void ) = OFFSET(0x401000);
void (*GAM_fn_vFirstInitEngine)( void ) = OFFSET(0x403430);
void (*GAM_fn_vInitGameLoop)( void ) = OFFSET(0x4030C0);
void (*GAM_fn_vEngine)( void ) = OFFSET(0x40ADA0);

char * (*GAM_fn_p_szGetLevelName)( void ) = OFFSET(0x404DA0);
void (*GAM_fn_vAskToChangeLevel)( char const *szLevelName, ACP_tdxBool bSaveGame ) = OFFSET(0x4054D0);

HANDLE (*GAM_fn_hGetWindowHandle)( void ) = OFFSET(0x401400);
long (CALLBACK *GAM_fn_WndProc)( HANDLE hWnd, unsigned int uMsg, unsigned int wParam, long lParam ) = OFFSET(0x4022D0);
